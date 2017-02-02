#ifndef QTMSG_H
#define QTMSG_H
#include <PERCEPTION_OBSTACLE.hpp>
#include <UNIFIED_OBJECT.hpp>
#include <VELODYNE64_RING.hpp>

enum DATA_FIELD_INDEX
{
    DFI_LATITUDE=0,             //field name:0,plot element:1
    DFI_LONGITUDE,              //1
    DFI_ALTITUDE,               //2
    DFI_ACCELERATION_X,         //3
    DFI_ACCELERATION_Y,         //4
    DFI_ACCELERATION_Z,         //5
    DFI_ANGULAR_RATEX,          //6
    DFI_ANGULAR_RATEY,          //7
    DFI_ANGULAR_RATEZ,          //8
    DFI_VELOCITY_NORTH,         //9
    DFI_VELOCITY_WEST,          //10
    DFI_VELOCITY_UP,            //11
    DFI_HEADING,                //12
    DFI_PITCH,                  //13
    DFI_ROLL,                   //14
    DFI_FRONT_LEFT_WHEEL_SPEED, //15
    DFI_FRONT_RIGHT_WHEEL_SPEED,//16
    DFI_REAR_LEFT_WHEEL_SPEED,  //17
    DFI_REAR_RIGHT_WHEEL_SPEED, //18
    DFI_STEER_ANGLE,            //19
    DFI_SPEED,                  //20
    DFI_DESIRED_SPEED,          //21
    DFI_LEFT_LINE_DIST,         //22
    DFI_RIGHT_LINE_DIST,        //23
    DFI_FRONT_OBSTACLE_DIST,    //24
    DFI_IPC2VCU_VELOCITY,       //25
    DFI_IBEO_OBJECTS,           //26
    DFI_ADP_STATUS,             //27
    DFI_TSR,                    //28
    DFI_PERCEPTIONED_OBJ,       //29

    DFI_END
};

struct Q_VEHICLE_POSE
{
    double fLatitude;//in deg;
    double fLongitude;//in deg;
    float fAltitude;//in deg;
    float fAccX;//in m/s/s;
    float fAccY;//in m/s/s;
    float fAccZ;//in m/s/s;
    float fAngRateX;//in deg/s;
    float fAngRateY;//in deg/s;
    float fAngRateZ;//in deg/s;
    float fVelNorth;//in m/s;
    float fVelWest;//in m/s;
    float fVelUp;//in m/s;
    float fHeading;//in deg;
    float fPitch;//in deg;
    float fRoll;//in deg;
    float fSpeed;//in km/h
};
Q_DECLARE_METATYPE ( Q_VEHICLE_POSE );

struct Q_VCU_VEHICLE_INFO
{
  float fSteeringAngle;//in deg;
  float fFrontLeftWheelSpeed;//in m/s;
  float fFrontRightWheelSpeed;//in m/s;
  float fRearLeftWheelSpeed;//in m/s;
  float fRearRightWheelSpeed;//in m/s;
};
Q_DECLARE_METATYPE(Q_VCU_VEHICLE_INFO);

struct Q_EXECUTE_TRAJECTORY
{
  float fDesiredSpeed;//in km/h;
};
Q_DECLARE_METATYPE ( Q_EXECUTE_TRAJECTORY );

struct Q_MOBILEYE_LINES
{
    float fLeftLineDist;//in m;
    float fRightLineDist;//in m;
};
Q_DECLARE_METATYPE( Q_MOBILEYE_LINES );

struct Q_PERCEPTION_OCT_OBSTACLES
{
    PERCEPTION_OBSTACLE gstOctObstacles[8];
};
Q_DECLARE_METATYPE( Q_PERCEPTION_OCT_OBSTACLES );

struct Q_IPC2DEV_VELOCITY
{
    HEADER     stHeader;

    uint8_t    bLen;

    int16_t    gnMsgId[8];

    uint8_t    gbMsgLen[8];

    uint8_t    gbData[8][8];
};
Q_DECLARE_METATYPE( Q_IPC2DEV_VELOCITY );

struct Q_PERCEPTIONED_OBJECTS
{
    HEADER     header;

    PERCEPTION_OBSTACLE gstLeftLaneObstacles[10];

    PERCEPTION_OBSTACLE gstMiddleLaneObstacles[10];

    PERCEPTION_OBSTACLE gstRightLaneObstacles[10];
};
Q_DECLARE_METATYPE( Q_PERCEPTIONED_OBJECTS );

//adp behavior
struct Q_EXECUTE_BEHAVIOR_PLAN
{
  HEADER header;
  int8_t n_operate_status;
  int8_t n_last_behavior;
  int8_t n_current_behavior;
  int8_t n_next_behavior;
  int8_t n_lane_property[3];
  int8_t n_compare_lane_property_result;
  int8_t n_overtaking_intent;
  int8_t n_leftlane_safe;
  int8_t n_rightlane_safe;
  int8_t n_leftlane_better;
  int8_t n_rightlane_better;
  int8_t n_left_change;
  int8_t n_right_change;
  int8_t n_left_light_on;
  int8_t n_right_light_on;
  int8_t n_wiper_on;
  int8_t n_wiper_speed;
};Q_DECLARE_METATYPE( Q_EXECUTE_BEHAVIOR_PLAN );

//tsr
struct Q_PERCEPTION_TSR
{
    HEADER header;

//    boolean bLight;
    float  fDist2Light;
//    byte nLightState;

    int64_t nSpeedLimitTimeStamp;
//    boolean bSpeedLimit;
    float fDist2SpeedLimit;
    int16_t nSpeedLimit;

    int64_t nStopLineTimeStamp;
//    boolean bStopLine;
    float fDist2StopLine;

};Q_DECLARE_METATYPE( Q_PERCEPTION_TSR );

//tsr
struct Q_TRACKED_OBSTACLES
{
    HEADER header;
    UNIFIED_OBJECT gstTrackedObjectes[8];

};Q_DECLARE_METATYPE( Q_TRACKED_OBSTACLES );

//velodyne
struct Q_VELODYNE_POINTS
{
    HEADER     stHeader;

};Q_DECLARE_METATYPE( Q_VELODYNE_POINTS );
#endif // QTMSG_H
