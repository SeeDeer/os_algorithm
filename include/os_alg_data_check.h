/************************************************************************
 * @file: Do not edit
 * @author: xxx
 * @brief: xxx
 * @version: 1.0.0
 * @LastEditTime: 2021-07-05 23:42:59
 * @attention: Do not edit
 *************************************************************************/

#ifndef __OS_ALG_DATA_CHECK_H__
#define __OS_ALG_DATA_CHECK_H__

#include <stdint.h>

/***************************************************************
 * CRC校验：https://zhuanlan.zhihu.com/p/150609159
****************************************************************/
uint16_t os_alg_data_check_crc16(uint8_t *data,uint32_t size,const uint16_t crc_poly,uint16_t init_value,uint8_t ref_flag);

// 按CRC所用协议直接调用如下宏函数即可，这里只列出部分常用的
#define IOT_CRC16_CCITT_FALSE(data,size)    os_alg_data_check_crc16(data,size,0x1021,0xFFFF,0)
#define IOT_CRC16_CCITT(data,size)          os_alg_data_check_crc16(data,size,0x1021,0x0000,1)
#define IOT_CRC16_MODBUS(data,size)         os_alg_data_check_crc16(data,size,0x8005,0xFFFF,1)
#define IOT_CRC16_XMODEM(data,size)         os_alg_data_check_crc16(data,size,0x1021,0x0000,0)
#define IOT_CRC16_YMODEM(data,size)         os_alg_data_check_crc16(data,size,0x1021,0x0000,0)

/***************************************************************
 * MD5校验：
****************************************************************/



#endif /* __OS_ALG_DATA_CHECK_H__ */
