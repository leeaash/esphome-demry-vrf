#pragma once

#include "esphome/core/component.h"
#include "esphome/components/climate/climate.h"
#include "esphome/components/uart/uart.h"

namespace esphome {
  namespace demry_vrf {

    #define CMD_IDX_ON_OFF 2
    #define CMD_IDX_CLIMATE_MODE 5
    #define CMD_IDX_FAN_MODE 7
    #define CMD_IDX_TARGET_TEMP 4

    #define CMD_ON 0x01
    #define CMD_OFF 0x00

    #define CMD_CLIMATE_MODE_COOL 0x00
    #define CMD_CLIMATE_MODE_HEAT 0x01
    #define CMD_CLIMATE_MODE_FAN_ONLY 0x02
    #define CMD_CLIMATE_MODE_DRY 0x03

    #define CMD_FAN_MODE_HIGH 0x03
    #define CMD_FAN_MODE_MEDIUM 0x02
    #define CMD_FAN_MODE_LOW 0x01
    #define CMD_FAN_MODE_AUTO 0x00

    class DemryVrfClimate : public climate::Climate, public Component {
     public:
      void setup() override;
      void control(const climate::ClimateCall &call) override;
      climate::ClimateTraits traits() override;
      
      void set_idx(uint8_t idx) { this->idx_ = idx; }
      // 💡 关键修改：暴露物理 ID 接口
      uint8_t get_idx() const { return this->idx_; } 
      
      void set_uart(uart::UARTDevice *uart) { this->uart_ = uart; }

     protected:
      uint8_t idx_;
      uart::UARTDevice *uart_;
    };

  }
}
