struct log_event
{
    //system event
    bool system_running_status;					//true:running; false:killed

    //sensor event
    bool velodyne_power_status;					//true:on; false:off
    bool ibeo_power_status;
    bool esr_power_status;
    bool me3_power_status;
    bool gps_ins_power_status;
    bool hd_map_power_status;

    int8_t gps_mode;							//0:SPSS;1:DIFF;3:RTK-float;4:RTK-interger

    //module event
    bool velodyne_data_status;
    bool velodyne_process_status;
    bool ibeo_data_status;
    bool ibeo_process_status;
    bool esr_data_status;
    bool esr_process_status;
    bool me3_data_status;
    bool me3_process_status;
    bool adp_status;

    //human behavior event
    int8_t human_behavior;						//start_autonomous_driving:0; monitored by vehicle CAN
    //interfere:1
    //turning light;
    //brake

    //automous driving behavior event
    int8_t autonoumos_mode;						//0:manual;1:semi-auto;2:auto
    int8_t autonomous_behavior;					//0:lane keeping;1:following;2:lane changing;3:overtaking;4:emergency braking
                                                //5:avoiding obstacles;6:intersection stop;7:parking;8:turning left;9:turning right;10:turning around

    //function failure event
    bool failed;

    //environment event
    bool sunny;

}
