#include "app.hpp"
#include "Hub.hpp"
#include "spike/hub/imu.h"
#include <stdio.h>

/* メインタスク(起動時にのみ関数コールされる) */
void main_task(intptr_t unused) {

  spikeapi::Hub hub;
  hub.init();
  spikeapi::AccelerometerData accel = {0.0f};
  spikeapi::GyroscopeData gyro = {0.0f};

  while (true) {
    accel = hub.get_acceleration();
    gyro = hub.get_angular_velocity();

    printf("acceleration: %f, %f, %f\n", accel.x, accel.y, accel.z);
    printf("angular velocity: %f, %f, %f\n", gyro.x, gyro.y, gyro.z);

    tslp_tsk(1000 * 1000);
  }
}
