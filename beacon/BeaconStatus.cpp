#include <arpa/inet.h>
#include "BeaconStatus.h"

namespace IrvCS
{
  BeaconStatus::BeaconStatus(const BeaconData *data)
  {
    id_=data->id;
    ldc_=ntohs(data->ldc);
    for (int i =0; i < 3; i++)
    {
      gyro_[i]=((int32_t)ntohl(data->gyro[i])/(1024.0*1024.0));
    }
    for (int i =0; i < 3; i++)
    {
      mag_[i]=(int32_t)ntohl(data->mag[i]);
    }
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
    // updated the gyro and the mag to put in a cycler? to fill each of the
    // bytes from 0 - 2 in sequence

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
             <<"GYRO = [";
    for (int i=0; i < 3; i++)
    {
      if (i != 0)
      {
        os<<",";
      }
      os<<beaconStatus.gyro_[i];
    }
    os<<"]"<<std::endl
      <<"MAG = "<<beaconStatus.mag_[3]<<std::endl
      /*
       * @TODO add the same style of cycler as did for gyro for mag
       * check that the program is outputting the correct variable,
       * to see if correct check beacon.h
       */
      <<"TEMP_DAUGHTERA = "<<beaconStatus.tempDaughterA_<<std::endl
      <<"TEMP_3V_PAYLOAD = "<<beaconStatus.tempThreeVpl_<<std::endl
             <<"OUTSIDE_TEMP = "<<beaconStatus.tempNz_<<std::endl
             <<"3V_SENSOR_VOLTAGE = "<<beaconStatus.volt3V_<<std::endl
             <<"3V_SENSOR_CURRENT = "<<beaconStatus.volt3V_<<std::endl
             <<"5V_PAYLOAD_VOLTAGE = "<<beaconStatus.volt5Vpl_<<std::endl
             <<"5V_PAYLOAD_CURRENT = "<<beaconStatus.curr5Vpl<<std::endl;
  }
}
