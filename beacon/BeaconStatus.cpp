#include <arpa/inet.h>
#include "BeaconStatus.h"

namespace IrvCS
{
  BeaconStatus::BeaconStatus(const BeaconData *data)
  {
    id_=data->id;
    ldc_=ntohs(data->ldc);
    gyro_[3]=data->gyro;
    mag_[3]=data->mag;
    tempDaughterA_=data->tempDaughterA;
    tempThreeVpl_=data->tempThreeVpl;
    tempNz_=data->tempNz;
    volt3V_=data->volt3V;
    curr3V_=data->curr3V;
    volt5Vpl_=data->volt5Vpl;
    curr5Vpl=data->curr5Vpl;
    //
    // @TODO convert the rest of the members to host byte order and appropriate
    //       units.  See adc-sensors-util for example of int/uint->float
    //       conversion.
    //
    // every member starting from gyro through curr5Vpl was already a value, so
    // i wrote the values in. however, what are the phrases that come after the
    // the arrows?
    //
    // @TODO find the BeaconData structure and replace the phrase after the
    // arrows above to reflect the members of the structure

  }

  BeaconStatus::~BeaconStatus()
  {
  }

/**
 * Output Beacon Status in human friendly attr = value form
 **/
  std::ostream& operator<<(std::ostream &os, const BeaconStatus &beaconStatus)
  {

    
    //
    // @TODO Add all members of Beacon Status to the output
    //
    // done??
    //
    return os<<"ID = "<<beaconStatus.id_<<std::endl
             <<"LDC = "<<beaconStatus.ldc_<<std::endl
             <<"GYRO = "<<beaconStatus.gyro_[3]<<std::endl
             <<"MAG = "<<beaconStatus.mag_[3]<<std::endl
             <<"TEMP_DAUGHTERA = "<<beaconStatus.tempDaughterA_<<std::endl
             <<"TEMP_3V_PAYLOAD = "<<beaconStatus.tempThreeVpl_<<std::endl
             <<"OUTSIDE_TEMP = "<<beaconStatus.tempNz_<<std::endl
             <<"3V_SENSOR_VOLTAGE = "<<beaconStatus.volt3V_<<std::endl
             <<"3V_SENSOR_CURRENT = "<<beaconStatus.volt3V_<<std::endl
             <<"5V_PAYLOAD_VOLTAGE = "<<beaconStatus.volt5Vpl_<<std::endl
             <<"5V_PAYLOAD_CURRENT = "<<beaconStatus.curr5Vpl<<std::endl;
  }
}
