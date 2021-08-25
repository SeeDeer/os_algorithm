/************************************************************************
 * @file: Do not edit
 * @author: xxx
 * @brief: xxx
 * @version: 1.0.0
 * @LastEditTime: 2021-08-25 22:23:21
 * @attention: Do not edit
 *************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "os_alg_data_check.h"

static void __invert_uint8(uint8_t *dstBuf, uint8_t *srcBuf);
static void __invert_uint16(uint16_t *dstBuf, uint16_t *srcBuf);

/*****************************************************************
 * @Function: os_alg_data_check_crc16
 * @Description: 计算CRC16值的算法实现，适配所有CRC16的协议
 * @Param: ref_flag,数据位序翻转，true-低位在前，高位在后
 * @Return: void
 *****************************************************************/
uint16_t os_alg_data_check_crc16(uint8_t *data,uint32_t size,const uint16_t crc_poly,uint16_t init_value,uint8_t ref_flag)
{    
    unsigned short crc_reg = init_value,tmp = 0;
    unsigned char j,byte = 0;
    
    while (size--){
        byte = *(data++);
        if (ref_flag)
            __invert_uint8(&byte,&byte);
        crc_reg ^= byte << 8;
        for ( j = 0; j < 8; j++){
            tmp = crc_reg & 0x8000;
            crc_reg <<= 1;
            if (tmp)
                crc_reg ^= crc_poly;
        }
    }
    
    if (ref_flag)
        __invert_uint16(&crc_reg,&crc_reg);
    
    // 这里XOROUT数值固定为0x0000
    return crc_reg;  // 等价于 return (crc_reg ^ 0X0000);
}

static void __invert_uint8(uint8_t *dstBuf, uint8_t *srcBuf)
{
    uint8_t i,tmp = 0;
    for ( i = 0; i < 8; i++){
        if (srcBuf[0] & (1 << i)){
            tmp |= 1 << (7-i);
        }
    }
    *dstBuf = tmp;
}

static void __invert_uint16(uint16_t *dstBuf, uint16_t *srcBuf)
{
    uint16_t i,tmp = 0;
    for ( i = 0; i < 16; i++){
        if (srcBuf[0] & (1 << i)){
            tmp |= 1 << (15-i);
        }
    }
    *dstBuf = tmp;
}
