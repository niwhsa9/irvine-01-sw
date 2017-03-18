#ifndef __GPIO_CPP_HH__
#define __GPIO_CPP_HH__
#include <stdint.h>

namespace IrvCS
{
  class Gpio
  {
  public:
    /**
     * Create an uninitialized GPIO
     **/
    Gpio();

    /**
     * Create and initialize GPIO
     **/
    Gpio(int16_t gpio);
    
    ~Gpio();

    /**
     * Initialize with given gpio
     * @param gpio the gpio value
     * @return true if successful
     * @return false if not
     **/
    bool initialize(int16_t gpio);

    /**
     * Indicate whether or not the GPIO was initialized successfully.
     * @return true if initialized successfully
     * @return false if there were problems initializing
     **/
    bool initialized();
    
    /**
     * Set the GPIO
     * @param val The value to set the GPIO.  Should be 0 or 1.
     * @return 0 if successful
     * @return <0 if not successful
     **/
    int8_t set(uint8_t val);

    /**
     * Get the GPIO value
     * @return 1 or 0 if successful
     * @return <0 if failed
     **/
    int8_t get();

  private:
    /**
     * If < 0 this is not initialized
     **/
    int16_t gpio_;
  };
}
#endif
