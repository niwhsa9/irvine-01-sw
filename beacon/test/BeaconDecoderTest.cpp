#include <arpa/inet.h>
#include <BeaconStatus.h>
#include <gtest/gtest.h>

using namespace IrvCS;

/*
 * Unit tests for Beacon Decoder
 */

/**
 * Test decoding the ID and LDC
 **/
TEST(BeaconDecode, DecodeIDandLDC)
{
  /*
   * Create beacon data in network byte order
   */
  BeaconData beaconData;
  strcpy(beaconData.id, BEACON_ID);
  beaconData.ldc=htons(100);

  BeaconStatus bStatus(&beaconData);

  ASSERT_EQ(bStatus.id_, "IRV-01");
  ASSERT_EQ(bStatus.ldc_, 100);
}

/**
 * test decoding gyro.  Retrieve telemetry data from adcs-sensor-telemetry
 * for this test and compare with adcs-sensor-status output
 **/
TEST(BeaconDecode, DecodeGyro)
{
  BeaconData beaconData;

  beaconData.gyro[0]=1284505;
  beaconData.gyro[1]=-238550;
  beaconData.gyro[2]=578027;

  BeaconStatus bStatus(&beaconData);

  ASSERT_EQ(bStatus.gyro_[0], 0.857499);
  ASSERT_EQ(bStatus.gyro_[1], -0.096249);
  ASSERT_EQ(bStatus.gyro_[2], 0.096250);
}

/**
 * Test decoding magnetometer data.
 *
 * @TODO create the data for this test
 *
 * Retrieve telemetry data from adcs-sensor-telemetry
 * for this test and compare with adcs-sensor-status output *
 **/
TEST(BeaconDecode, DecodeMag)
{
  // @TODO check if valid, if it is, then substite actual values
  // where does the telemetry come from? can't find the adcs-sensor-status
  // are the values above arbitrary? 

  BeaconData beaconData;
  beaconData.mag[0]=htonl(-10212);
  beaconData.mag[1]=htonl(-14628);
  beaconData.mag[2]=htonl(-12972);

  BeaconStatus bStatus(&beaconData);

  ASSERT_EQ(bStatus.mag_[0], -10212);
  ASSERT_EQ(bStatus.mag_[1], -14628);
  ASSERT_EQ(bStatus.mag_[2], -12972);
}

  */
}
/**
 * Test decoding temperature variables
 * @TODO create the data for this test
 **/
TEST(BeaconDecode, DecodeTemp)
{
  // @TODO 
  FAIL()<<"Implement me";                       
}

/**
 * test decoding power - voltage and current variables
 * @TODO create the data for this test
 **/
TEST(BeaconDecode, DecodePower)
{
  // @TODO
  FAIL()<<"Implement me";                       
}

/**
 * Test the ostream output.  You can output the stream to a string, then compare
 * the file against expected string output (or use a file).
 **/
TEST(BeaconDecode, HumanReadableOutput)
{
  // @TODO
  FAIL()<<"Implement me";
}
