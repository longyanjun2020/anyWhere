//==============================================================================
//
//  File        : mmp_register_audio.h
//  Description : INCLUDE File for the Retina register map.
//  Author      : Rogers Chen
//  Revision    : 1.0
//
//==============================================================================

#ifndef _MMP_REG_AUDIO_H_
#define _MMP_REG_AUDIO_H_

#include "mmp_register.h"

/** @addtogroup MMPH_reg
@{
*/

#if (CHIP == MCR_V2)
//-------------------------------------------------------------------------
// Audio I2S structure ch0 (0x80007800) ch1 (0x80005A00) ch2(0x80003A00)
//-------------------------------------------------------------------------
typedef struct _AITS_I2S {
	/* I2S FIFO */
    AIT_REG_B   I2S_FIFO_CPU_INT_EN;                                    // 0x00
    AIT_REG_B   I2S_FIFO_HOST_INT_EN;                                   // 0x01
        /*-DEFINE-----------------------------------------------------*/
        #define AUD_INT_FIFO_EMPTY          0x01
        #define AUD_INT_FIFO_FULL           0x02
        #define AUD_INT_FIFO_REACH_UNRD_TH  0x04
        #define AUD_INT_FIFO_REACH_UNWR_TH  0x08
        #define RX_INT_EN(_a)            	(_a)
        #define TX_INT_EN(_a)          		(_a << 4)
		/*------------------------------------------------------------*/    
	AIT_REG_B   I2S_FIFO_INT_SR;                                        // 0x02
        /*-DEFINE-----------------------------------------------------*/
        #define I2S_FIFO_SRC_CH0            0x01
        #define I2S_FIFO_SRC_CH1            0x02
        #define I2S_FIFO_SRC_CH2            0x04
        /*------------------------------------------------------------*/
    AIT_REG_B                          	_x03;
    AIT_REG_B   I2S_FIFO_RX_SR;                             			// 0x04
    AIT_REG_B   I2S_FIFO_TX_SR;                                			// 0x05
    AIT_REG_B   						_x06[2];
    AIT_REG_B   I2S_FIFO_RST;                                           // 0x08
        /*-DEFINE-----------------------------------------------------*/
		#define I2S_FIFO_RST_EN             0x01
		/*------------------------------------------------------------*/    
    AIT_REG_B   						_x09[3];
    AIT_REG_D   I2S_FIFO_DATA_RX;                                		// 0x0C
    
    AIT_REG_W	I2S_FIFO_RD_TH_RX;										// 0x10
    AIT_REG_B                           _x12[2];
	AIT_REG_W	I2S_FIFO_WR_TH_RX;										// 0x14
    AIT_REG_B                           _x16[2];
	AIT_REG_W	I2S_FIFO_UNRD_CNT_RX;       							// 0x18 [RO]
	AIT_REG_B							_x1A[2];       							
	AIT_REG_W	I2S_FIFO_UNWR_CNT_RX;       							// 0x1C [RO]
    AIT_REG_B                           _x1E[2];
    
    AIT_REG_D   I2S_FIFO_DATA_TX;                            			// 0x20
    AIT_REG_W   I2S_FIFO_UNRD_CNT_TX;                                	// 0x24 [RO]
    AIT_REG_W   I2S_FIFO_UNWR_CNT_TX;                                	// 0x26 [RO]                            
    /* I2S Control */
    AIT_REG_B   I2S_CTL;                                                // 0x28
        /*-DEFINE-----------------------------------------------------*/
		#define I2S_SDO_OUT_EN				0x08
		#define I2S_LRCK_OUT_EN             0x04
		#define I2S_BCK_OUT_EN              0x02
		#define I2S_HCK_CLK_EN              0x01
		/*------------------------------------------------------------*/    
    AIT_REG_B   						_x29;
    AIT_REG_W   I2S_FIFO_RD_TH_TX;                                   	// 0x2A	    
    AIT_REG_B   I2S_MCLK_DIV;                                         	// 0x2C
    AIT_REG_B   I2S_MCLK_FIX_MODE;                                     	// 0x2D
        /*-DEFINE-----------------------------------------------------*/
		#define I2S_MCLK_FIX                0x01
		/*------------------------------------------------------------*/
    AIT_REG_W   I2S_FIFO_WR_TH_TX;										// 0x2E
    
    AIT_REG_W   I2S_MCLK_RATIO_NM;                                   	// 0x30
    AIT_REG_B   						_x32[2];
    AIT_REG_B   I2S_OUT_BIT_SIZE;                                  		// 0x34
        /*-DEFINE-----------------------------------------------------*/
		#define I2S_OUT_32BITS              0x04
		#define I2S_OUT_24BITS              0x02
		#define I2S_OUT_16BITS              0x01
		/*------------------------------------------------------------*/
    AIT_REG_B   						_x35[3];
    AIT_REG_B   I2S_LRCK_POL;                                           // 0x38
        /*-DEFINE-----------------------------------------------------*/
		#define I2S_LRCK_L_CH_HIGH          0x01
		#define I2S_LRCK_L_CH_LOW           0x00
		/*------------------------------------------------------------*/
    AIT_REG_B	I2S_MULTI_CH_ENABLE;									// 0x39
		/*-DEFINE-----------------------------------------------------*/
		#define IS_MULTI_CH_RX_EN      		0x01
    	/*------------------------------------------------------------*/
    AIT_REG_B	I2S_MULTI_CH_BIT_PER_CH;								// 0x3A
	    /*-DEFINE-----------------------------------------------------*/
		#define I2S_MULTICH_20BITS_PER_CH	0x04
		#define I2S_MULTICH_24BITS_PER_CH	0x02
		#define I2S_MULTICH_32BITS_PER_CH 	0x01
		#define I2S_MULTICH_16BITS_PER_CH 	0x00
	    /*------------------------------------------------------------*/
    AIT_REG_B	I2S_MULTI_CH_CNT;										// 0x3B
	    /*-DEFINE-----------------------------------------------------*/
		#define I2S_MULTICH_4CH_EN      	0x10
		#define I2S_MULTICH_5CH_EN      	0x08
		#define I2S_MULTICH_6CH_EN      	0x04
		#define I2S_MULTICH_7CH_EN      	0x02
		#define I2S_MULTICH_8CH_EN      	0x01
		#define I2S_MULTICH_3CH_EN      	0x00
	    /*------------------------------------------------------------*/   
    AIT_REG_D   I2S_L_CH_DATA_PORT;                                		// 0x3C
    
    AIT_REG_D   I2S_R_CH_DATA_PORT;                                 	// 0x40
    AIT_REG_B   I2S_BIT_ALIGN_OUT;                                      // 0x44
    AIT_REG_B   I2S_BIT_ALIGN_IN;                                       // 0x45
	    /*-DEFINE-----------------------------------------------------*/
		#define I2S_BIT_ALIGN_MASK 			0x1F
	    /*------------------------------------------------------------*/    
    AIT_REG_B   						_x46[2];
    AIT_REG_B   I2S_MODE_CTL;                                           // 0x48
        /*-DEFINE-----------------------------------------------------*/
		#define I2S_MCLK_OUT_EN             0x04
		#define I2S_SLAVE_MODE          	0x00
		#define I2S_MASTER_MODE           	0x01   
		/*------------------------------------------------------------*/    
    AIT_REG_B   						_x49[3];
    AIT_REG_B   I2S_MCLK_CTL;                                           // 0x4C
        /*-DEFINE-----------------------------------------------------*/
        #define I2S_1536_FS                 0x80
        #define I2S_1024_FS                 0x40
        #define I2S_768_FS                  0x20
        #define I2S_512_FS                  0x10
    	#define I2S_384_FS				    0x08
    	#define I2S_256_FS				    0x04
    	#define I2S_192_FS				    0x02
    	#define I2S_128_FS				    0x01
		/*------------------------------------------------------------*/    
    AIT_REG_B   						_x4D[3];
    
    AIT_REG_B   I2S_MSPORT_CTL;                                         // 0x50
        /*-DEFINE-----------------------------------------------------*/
        #define I2S_MSPORT_MODE_EN    		0x04
        #define I2S_ASPORT_MODE_EN			0x01
		/*------------------------------------------------------------*/
    AIT_REG_B   I2S_MSPORT_START_BIT;                                   // 0x51
    AIT_REG_B   						_x52[2];
    AIT_REG_B   I2S_DATA_OUT_EN;                                        // 0x54
        /*-DEFINE-----------------------------------------------------*/
        #define I2S_SDI_OUT_MODE    		0x02
        #define I2S_ENABLE_DATA_OUT			0x01
		/*------------------------------------------------------------*/
    AIT_REG_B   						_x55[3];
    AIT_REG_B   I2S_DATA_IN_SEL;                                        // 0x58
        /*-DEFINE-----------------------------------------------------*/
        #define I2S_DATA_IN_FROM_SDO    	0x01
        #define I2S_DATA_IN_FROM_SDI    	0x00
		/*------------------------------------------------------------*/    
    AIT_REG_B   						_x59[3];
    AIT_REG_B   I2S_CPU_INT_EN;                                         // 0x5C
    AIT_REG_B   I2S_HOST_INT_EN;                                        // 0x5D
        /*-DEFINE-----------------------------------------------------*/
        #define I2S_INT_EN     		        0x01
        #define I2S_INT_DIS    			    0x00
		/*------------------------------------------------------------*/
    AIT_REG_B   I2S_INT_SR;                                             // 0x5E
        /*-DEFINE-----------------------------------------------------*/
        #define I2S_INT_SRC_CH0             0x01
        #define I2S_INT_SRC_CH1             0x02
        #define I2S_INT_SRC_CH2             0x04
        /*------------------------------------------------------------*/
    AIT_REG_B   						_x5F;
    
    AIT_REG_B   I2S_OUT_DELAY_MODE;                                 	// 0x60
        /*-DEFINE-----------------------------------------------------*/
        #define	I2S_STD_MODE			    0x01
        #define	I2S_I2S_MODE			    0x00
        /*------------------------------------------------------------*/
    AIT_REG_B   						_x61[3];
    AIT_REG_W   I2S_MSPORT_FRM_CYCLE_CNT;                          		// 0x64                             
    AIT_REG_B   I2S_MSPORT_FRM_SYNC_CNT;                            	// 0x66
    AIT_REG_B                           _x67;
    AIT_REG_B   I2S_SDO_SHIFT_REG_RST;                               	// 0x68
    AIT_REG_B                           _x69[7];
    
    /* I2S Mux */
    AIT_REG_B   I2S_MUX_MODE_CTL;                                       // 0x70
        /*-DEFINE-----------------------------------------------------*/
        #define AUD_MUX_AUTO_MODE        	0x01
        #define AUD_MUX_CPU_MODE            0x00
		/*------------------------------------------------------------*/    
    AIT_REG_B   						_x71[3];
	AIT_REG_B   I2S_DUPLEX_PATH_SEL;                             		// 0x74
	    /*-DEFINE-----------------------------------------------------*/
        #define I2S2_FULL_DUPLEX_EN     	0x10 		// SDO -> I2S2 Tx FIFO, SDI -> I2S2 Rx FIFO
        #define I2S1_FULL_DUPLEX_EN      	0x02 		// SDO -> I2S1 Tx FIFO, SDI -> I2S1 Rx FIFO
		#define I2S0_FULL_DUPLEX_EN      	0x01 		// SDO -> I2S0 Tx FIFO, SDI -> I2S0 Rx FIFO
		/*------------------------------------------------------------*/
	AIT_REG_B   						_x75[3];
    AIT_REG_B   I2S_PATH_CTL;                                           // 0x78
        /*-DEFINE-----------------------------------------------------*/
        #define THREE_T_SYNC_MODE_EN		0x40  
        #define I2S1_SDI_LOOPBACK_DAC       0x20 		// I2S1 SDI -> DAC without pass FIFO
        #define I2S0_SDI_LOOPBACK_DAC       0x10 		// I2S0 SDI -> DAC without pass FIFO
		#define ADC_LOOPBACK_I2S2_SDO    	0x04 		// ADC -> I2S2 SDO without pass FIFO
        #define ADC_LOOPBACK_I2S1_SDO       0x02 		// ADC -> I2S1 SDO without pass FIFO
        #define ADC_LOOPBACK_I2S0_SDO       0x01 		// ADC -> I2S0 SDO without pass FIFO
        /*------------------------------------------------------------*/
    AIT_REG_B   I2S_MISC_CTL;                                           // 0x79
        /*-DEFINE-----------------------------------------------------*/
		#define I2S2_MCLK_AS_AFE_SYSCLK			0x10    // AFE use I2S2 MCLK as SYSCLK
		#define I2S1_MCLK_AS_AFE_SYSCLK        	0x08    // AFE use I2S1 MCLK as SYSCLK
		#define I2S0_MCLK_AS_AFE_SYSCLK    	 	0x00	// AFE use I2S0 MCLK as SYSCLK
		#define I2S_INV_MCLK_AS_AFE_SYSCLK_EN	0x04	// AFE use inverter I2S MCLK as SYSCLK
		#define I2S_MCLK_AS_AFE_SYSCLK_EN      	0x02	// AFE use I2S MCLK as SYSCLK
        /*------------------------------------------------------------*/
    AIT_REG_B                           _x7A[6];
    
    /* I2S Timer (Internal:clk_audio_i2s, External:BCK, LRCK, MCLK, SOF */
    AIT_REG_B   I2S_TIMER_EN;                                           // 0x80
       	/*-DEFINE-----------------------------------------------------*/
        #define I2S_TIMER_INFO_SEND_TO_GBL	0x02
        #define I2S_TIMER_COUNTER_EN    	0x01
		/*------------------------------------------------------------*/ 
    AIT_REG_B   						_x81[3];
    AIT_REG_W   I2S_TIMER_CTL;                                          // 0x84
       /*-DEFINE-----------------------------------------------------*/
        #define I2S_TIMER_COUNTER_SRC_MCLK		0x0008
        #define I2S_TIMER_COUNTER_SRC_BCK		0x0004        
        #define I2S_TIMER_COUNTER_SRC_LRCK		0x0002
        #define I2S_TIMER_COUNTER_SRC_USB_SOF	0x0001
        #define I2S_TIMER_COUNTER_ROUNDING_EN	0x0100
		/*------------------------------------------------------------*/ 
    AIT_REG_B   						_x86[2];
    AIT_REG_D   I2S_TIMER_EXT_TAGET_VALUE;                            	// 0x88
    AIT_REG_D   I2S_TIMER_EXT_CUR_VALUE;                             	// 0x8C [RO]
    
    AIT_REG_B   I2S_TIMER_CPU_INT_EN;                                   // 0x90
    AIT_REG_B   I2S_TIMER_HOST_INT_EN;                                  // 0x91	
       	/*-DEFINE-----------------------------------------------------*/
        #define I2S_TIMER_INT_INTL_EQUAL_EXT_EN	0x08
        #define I2S_TIMER_INT_INTL_SLOW_EXT_EN	0x04
        #define I2S_TIMER_INT_INTL_FAST_EXT_EN	0x02
        #define I2S_TIMER_INT_HIT_TARGET_EN		0x01
		/*------------------------------------------------------------*/
    AIT_REG_B   						_x92[2];
    AIT_REG_B   I2S0_TIMER_INT_SR;	                                    // 0x94
    AIT_REG_B   I2S1_TIMER_INT_SR;	                                    // 0x95
    AIT_REG_B   I2S2_TIMER_INT_SR;	                                    // 0x96
    AIT_REG_B   						_x97;
    AIT_REG_B   I2S_TIMER_RST;                                          // 0x98
    AIT_REG_B                           _x99[7];
    
    AIT_REG_D  	I2S_TIMER_INT_TARGET_VALUE_LOW;                      	// 0xA0
    AIT_REG_D  	I2S_TIMER_INT_TARGET_VALUE_HIG;                       	// 0xA4
    AIT_REG_D  	I2S_TIMER_INT_CUR_VALUE_LOW;                            // 0xA8 [RO]
    AIT_REG_D  	I2S_TIMER_INT_CUR_VALUE_HIG;                            // 0xAC [RO]
    
    AIT_REG_B                           _xB0[16];
   	
   	/* SPDIF */
    AIT_REG_D   SPDIF_CHANNEL_SR[6];                                    // 0xC0
    
    AIT_REG_W   SPDIF_CTL;                                              // 0xD8
        /*-DEFINE-----------------------------------------------------*/
        #define SPDIF_SW_CRC       			0x0400
        #define HDMI_TRANS_EN       		0x0200
        #define SPDIF_TRANS_EN              0x0100
        /*------------------------------------------------------------*/
    AIT_REG_B   SPDIF_DATA_ALIGN_FMT;                                   // 0xDA
    AIT_REG_B                           _xDB;
    AIT_REG_B   SPDIF_RST;                                              // 0xDC
    AIT_REG_B                           _xDD[3];
    
    AIT_REG_B   HDMI_ECC_DATA;                                      	// 0xE0
    AIT_REG_B                           _xE1[3];
    AIT_REG_B   AFE_SAMPLE_RATE_SEL;                                    // 0xE4
        /*-DEFINE-----------------------------------------------------*/
        #define AFE_SRATE_192KHZ_128KHZ   	0x02
        #define AFE_SRATE_96KHZ_64KHZ    	0x01
        #define AFE_SRATE_48KHZ_UNDER   	0x00
        /*------------------------------------------------------------*/
    AIT_REG_B                           _xE5[3];
    AIT_REG_B   AFE_DOWN_SAMPLE_SEL;                                    // 0xE8
        /*-DEFINE-----------------------------------------------------*/
        #define AFE_DOWNSAMPLE_4TIMES       0x02
        #define AFE_DOWNSAMPLE_2TIMES       0x01
        #define AFE_DOWNSAMPLE_NONE      	0x00
        /*------------------------------------------------------------*/
    AIT_REG_B                             _xE9[7];
    
    AIT_REG_B  	SRAM_LIGHT_SLEEP_MOD_CTL;     	                        // 0xF0
        /*-DEFINE-----------------------------------------------------*/
        #define DAC_LEFT_CHAN_LIGHT_MODE    0x20
        #define AFE_RCHAN_LIGHT_MODE        0x10
        #define AFE_LCHAN_LIGHT_MODE        0x08
        #define AFE_FIFO_LIGHT_MODE         0x04
        #define IS21_FIFO_LIGHT_MODE        0x02
        #define IS20_FIFO_LIGHT_MODE        0x01
        /*------------------------------------------------------------*/
    AIT_REG_B  	SRAM_DEEP_SLEEP_MOD_CTL;     	                        // 0xF1
        /*-DEFINE-----------------------------------------------------*/
        #define DAC_LEFT_CHAN_DEEP_MODE     0x20
        #define AFE_RCHAN_DEEP_MODE         0x10
        #define AFE_LCHAN_DEEP_MODE         0x08
        #define AFE_FIFO_DEEP_MODE          0x04
        #define IS21_FIFO_DEEP_MODE         0x02
        #define IS20_FIFO_DEEP_MODE         0x01
        /*------------------------------------------------------------*/
    AIT_REG_B  	SRAM_SHUT_DOWN_MOD_CTL;     	                   		// 0xF2
       /*-DEFINE-----------------------------------------------------*/
       #define DAC_LEFT_CHAN_STDOWN_MODE    0x20
       #define AFE_RCHAN_STDOWN_MODE        0x10
       #define AFE_LCHAN_STDOWN_MODE        0x08
       #define AFE_FIFO_STDOWN_MODE         0x04
       #define IS21_FIFO_STDOWN_MODE        0x02
       #define IS20_FIFO_STDOWN_MODE        0x01
       /*------------------------------------------------------------*/
	AIT_REG_B                             _xF3[13];
} AITS_I2S, *AITPS_I2S;

//--------------------------------------------
// Audio AFE FIFO structure (0x80007F40/0x80007F80)
//--------------------------------------------
typedef __packed struct _AUD_FIFO {
    AIT_REG_B   CPU_INT_EN;                                				//  0x40
    AIT_REG_B   HOST_INT_EN;                               				//  0x41	
	AIT_REG_B   						_x42[2];
    AIT_REG_B   FIFO_SR;                                        		//  0x44 [RO]
	AIT_REG_B   						_x45[3];
    AIT_REG_B   RST;                                       				//  0x48
        /*-DEFINE-----------------------------------------------------*/
        #define AUD_FIFO_RST_EN             0x01
        /*------------------------------------------------------------*/
	AIT_REG_B   						_x49[3];
	AIT_REG_D   DATA;                                      				//  0x4C
	
	AIT_REG_W   RD_TH;                                     				//  0x50
	AIT_REG_B   						_x52[2];
	AIT_REG_W   WR_TH;                                     				//  0x54
	AIT_REG_B   						_x56[2];
	AIT_REG_W   UNRD_CNT;                                  				//  0x58 [RO]
	AIT_REG_B   						_x5A[2];
	AIT_REG_W   UNWR_CNT;                                  				//  0x5C [RO]
	AIT_REG_B   						_x5E[2];
} AUD_FIFO;	

//--------------------------------------------
// Audio AFE structure (0x80007F00)
//--------------------------------------------
typedef struct _AITS_AUD {
    AIT_REG_B   AFE_POWER_CTL;                                          // 0x00
        /*-DEFINE-----------------------------------------------------*/
        #define ANALOG_POWER_EN             0x20
        #define VREF_POWER_EN               0x10
        #define ADC_DF_POWER_EN             0x02
        #define DAC_DF_POWER_EN             0x01
        #define AFE_POWER_OFF               0x00
        /*------------------------------------------------------------*/
    AIT_REG_B                           _x7F01;
    AIT_REG_B   AFE_CLK_CTL;                                            // 0x02
        /*-DEFINE-----------------------------------------------------*/
        #define DMIC_EN                     0x40
        #define CODEC_ADC_64FS_EN           0x20
        #define CODEC_ADC_128FS_EN          0x10
        #define DAC_CLK_256FS_MODE          0x00
        #define DAC_CLK_USB_MODE            0x08
        /* ADC only 256fs mode */
        #define DAC_CLK_INV_EN              0x02
        #define ADC_CLK_INV_EN              0x01
        /*------------------------------------------------------------*/
    AIT_REG_B   AFE_SAMPLE_RATE_CTL;                                    // 0x03
        /*-DEFINE-----------------------------------------------------*/
        #define DAC_SRATE_MASK              0xF0
        #define DAC_SRATE(_a)               (_a << 4)
        
        #define SRATE_48000HZ               0x0A
        #define SRATE_44100HZ               0x09
        #define SRATE_32000HZ               0x08
        #define SRATE_24000HZ               0x06
        #define SRATE_22050HZ               0x05
        #define SRATE_16000HZ               0x04
        #define SRATE_12000HZ               0x02
        #define SRATE_11025HZ               0x01
        #define SRATE_8000HZ                0x00
        /*------------------------------------------------------------*/        
    AIT_REG_B                           _x7F04;     
    AIT_REG_B   AFE_DAC_FILTER_CTL;                                     // 0x05
        /*-DEFINE-----------------------------------------------------*/
        #define DAC_DITHER_EN               0x80
        #define DAC_DITHER_SCALE_2_1        0x60
        #define DAC_DITHER_SCALE_1_1        0x40
        #define DAC_DITHER_SCALE_1_2        0x20
        #define DAC_DITHER_SCALE_1_4        0x00
        #define DAC_FILTER_64_FS          	0x04
        #define DAC_FILTER_128_FS        	0x02
        #define DAC_FILTER_256_FS         	0x01
        /*------------------------------------------------------------*/
    AIT_REG_W   AFE_DAC_DIG_GAIN_CTL;                                   // 0x06
        /*-DEFINE-----------------------------------------------------*/
        #define DAC_R_SOFT_MUTE             0x8000
        #define DAC_R_GAIN_DIRECT_SET       0x4000
        #define DAC_L_SOFT_MUTE             0x0080
        #define DAC_L_GAIN_DIRECT_SET       0x0040
        /*------------------------------------------------------------*/  
    AIT_REG_B	AFE_MICBIAS_DUAL_CHAN;                               	// 0x08
        /*-DEFINE-----------------------------------------------------*/
        #define ADC_MIC_BIAS_VOLT_MASK   	0xFF
        #define ADC_MIC_BIAS_R_POWER_UP     0x40
		#define ADC_MIC_BIAS_R_VOLT_0D95    0x30
		#define ADC_MIC_BIAS_R_VOLT_0D85    0x20
		#define ADC_MIC_BIAS_R_VOLT_0D75    0x10
		#define ADC_MIC_BIAS_R_VOLT_0D65    0x00

        #define ADC_MIC_BIAS_L_POWER_UP     0x04
        #define ADC_MIC_BIAS_L_VOLT_0D95   	0x03		
		#define ADC_MIC_BIAS_L_VOLT_0D85   	0x02
		#define ADC_MIC_BIAS_L_VOLT_0D75   	0x01
		#define ADC_MIC_BIAS_L_VOLT_0D65   	0x00
        /*------------------------------------------------------------*/
    AIT_REG_B  	AFE_ADC_PGA_POWER_CTL;                              	// 0x09    
        /*-DEFINE-----------------------------------------------------*/
        #define ADC_R_POWER_UP              0x08
        #define ADC_L_POWER_UP              0x04
        #define ADC_PGA_R_POWER_EN          0x02
        #define ADC_PGA_L_POWER_EN          0x01
        /*------------------------------------------------------------*/
    AIT_REG_B  	AFE_ADC_ANA_LPGA_CTL;                               	// 0x0A    
        /*-DEFINE-----------------------------------------------------*/      
		#define OUT_LPGA_ZC_DETECT_EN       0x08
        #define LPGA_SRC_IN_MASK           	0x06
        #define LPGA_SRC_IN_AUXL           	0x04
        #define LPGA_SRC_IN_MICLP         	0x02
        #define LPGA_SRC_IN_MICLP_LN     	0x00
        #define LPGA_MUTE_CTL              	0x01
		/*------------------------------------------------------------*/
    AIT_REG_B  	AFE_ADC_ANA_LPGA_GAIN;                           		// 0x0B
		/*-DEFINE-----------------------------------------------------*/
        #define AFE_ADC_ANA_PGA_GAIN_MASK	0x1F
        /*------------------------------------------------------------*/
    AIT_REG_B  	AFE_ADC_ANA_RPGA_CTL;                               	// 0x0C   
        /*-DEFINE-----------------------------------------------------*/
        #define OUT_RPGA_ZC_DETECT_EN    	0x08
        #define RPGA_SRC_IN_MASK           	0x06
        #define RPGA_SRC_IN_AUXR           	0x04
        #define RPGA_SRC_IN_MICRP         	0x02
        #define RPGA_SRC_IN_MICRP_RN     	0x00
        #define RPGA_MUTE_CTL              	0x01
		/*------------------------------------------------------------*/
    AIT_REG_B  	AFE_ADC_ANA_RPGA_GAIN;                                  // 0x0D
    AIT_REG_B  	AFE_LADC_DITHER_AND_TEST;                            	// 0x0E
    AIT_REG_B  	AFE_RADC_DITHER_AND_TEST;                              	// 0x0F
    
    AIT_REG_D  	AFE_L_CHENNEL_DATA;                                		// 0x10
    AIT_REG_D  	AFE_R_CHENNEL_DATA;                               		// 0x14
    AIT_REG_B	AFE_CPU_INT_EN;                                         // 0x18
		/*-DEFINE-----------------------------------------------------*/
        #define AUD_ADC_INT_EN           	0x02
        #define AUD_DAC_INT_EN            	0x01
        /*------------------------------------------------------------*/
    AIT_REG_B   AFE_HOST_INT_EN;                                        // 0x19
    AIT_REG_W   AFE_ADC_DIG_GAIN;                                       // 0x1A
    	/*-DEFINE-----------------------------------------------------*/
   		#define ADC_DIG_GAIN_MUTE          	0x0000
 		#define ADC_DIG_GAIN_0DB           	0x5151
    	/*------------------------------------------------------------*/
    AIT_REG_B   AFE_ANA_DAC_POWER_CTL;                                  // 0x1C
        /*-DEFINE-----------------------------------------------------*/
        #define LINEOUT_POWER_UP            0x02
        #define DAC_POWER_UP                0x01
        /*------------------------------------------------------------*/
    AIT_REG_B   AFE_DAC_LOUT_VOL;                                       // 0x1D
        /*-DEFINE-----------------------------------------------------*/
        #define LOUT_ANA_GAIN_MUTE        	0x3E
        #define LOUT_ANA_GAIN_MASK        	0x3E
        #define LOUT_ZC_GAIN_UPD_EN      	0x01
        /*------------------------------------------------------------*/
    AIT_REG_B                        	_x7F1E[2]; 
     
    AIT_REG_B   AFE_DIG_GAIN_MUTE_STEP;                                 // 0x20
        /*-DEFINE-----------------------------------------------------*/
        #define ADC_PGA_GAIN_SMOOTH_SET_AT_ZC	0x80
        #define ADC_PGA_GAIN_DIRECT_SET_AT_ZC 	0x40
        #define DAC_PGA_GAIN_SMOOTH_SET_AT_ZC   0x20
        #define DAC_PGA_GAIN_DIRECT_SET_AT_ZC	0x10
        #define ADC_PGA_GAIN_UPDATE_DIS     	0x08
        #define DAC_PGA_GAIN_UPDATE_DIS  		0x04
        /* DAC gain update period (ramp up/down step size) when mute enable or DAC digital gain not using zero crossing detect */
        #define DAC_DIG_PGA_MUTE_1FS_UPDATE 	0x00
        #define DAC_DIG_PGA_MUTE_2FS_UPDATE 	0x01
        #define DAC_DIG_PGA_MUTE_4FS_UPDATE 	0x02
        #define DAC_DIG_PGA_MUTE_8FS_UPDATE 	0x03
        /*------------------------------------------------------------*/
    AIT_REG_B   AFE_DAC_DF_BUGFIX;                                      // 0x21
    AIT_REG_B   AFE_DAC_DF_BUGFIX_VAL;                               	// 0x22
    AIT_REG_B   AFE_ADC_MUTE_TO_TARGET_SR;                       		// 0x23
    AIT_REG_W   AFE_DAC_DIG_GAIN;                                       // 0x24
        /*-DEFINE-----------------------------------------------------*/
        #define DAC_DIG_MUTE              	0x00
        #define DAC_DIG_GAIN_MASK           0x7F
        /*------------------------------------------------------------*/
    AIT_REG_B   AFE_OVF_BUGFIX;                                         // 0x26
        /*-DEFINE-----------------------------------------------------*/
        #define DAC_DIG_VOL_OVF_FIX         0x08
        #define DAC_SDM_OVF_FIX             0x04
        /*------------------------------------------------------------*/
    AIT_REG_B                           _x7F27[9];
    
    AIT_REG_B                           _x7F30[2];
    AIT_REG_B   AFE_LADC_DIG_TIME_OUT[3];                               // 0x32     
    AIT_REG_B   AFE_LADC_DIG_STEP_TIME[3];                              // 0x35 
    AIT_REG_B   AFE_RADC_DIG_TIME_OUT[3];                               // 0x38
    AIT_REG_B   AFE_RADC_DIG_STEP_TIME[3];                              // 0x3B
    AIT_REG_B   AFE_ADC_DIG_GAIN_SETTING_CTL;                       	// 0x3E
        /*-DEFINE-----------------------------------------------------*/
        #define AFE_ADC_NORMAL_STATE_DIG_GAIN_DIRECT_METHOD	0x30     	/* Apply for the stage that if gain has any change after mute to initial gain stage */        
        #define AFE_ADC_DIG_GAIN_SMOOTH_METHOD 	0x08        			/* Apply for the stage from mute(-60dB) to initial gain setting */
        #define AFE_ADC_DIG_GAIN_DIRECT_METHOD 	0x04        			/* Apply for the stage from mute(-60dB) to initial gain setting */
        #define AFE_ADC_LR_MUTE_ENABLE   		0x03
        /*------------------------------------------------------------*/ 
    AIT_REG_B                           _x7F3F;
	
	AUD_FIFO 	AFE_DAC_FIFO;											// 0x40
	
	AIT_REG_B   AFE_LADC_ANA_TIME_OUT[3];                           	// 0x60	
	AIT_REG_B   AFE_LADC_ANA_STEP_TIME[3];                        		// 0x63	
	AIT_REG_B   AFE_RADC_ANA_TIME_OUT[3];                            	// 0x66		
	AIT_REG_B   AFE_RADC_ANA_STEP_TIME[3];                        		// 0x69
	AIT_REG_B   AFE_ADC_ANA_GAIN_SETTING_CTL;                     		// 0x6C
	    /*-DEFINE-----------------------------------------------------*/
	    #define AFE_ADC_ANA_GAIN_DIRECT_METHOD 	0x20
	    #define AFE_ADC_ANA_GAIN_SMOOTH_METHOD	0x10
	    #define TIME_OUT_PULSE_ENABLE    		0x01
	    /*------------------------------------------------------------*/ 
	AIT_REG_B   						_x7F6D[3];

	AIT_REG_B   AFE_MUX_MODE_CTL;                                       // 0x70
        /*-DEFINE-----------------------------------------------------*/
        #define I2S_CH2_DATA_24BIT          0x80
        #define I2S_CH2_DATA_20BIT          0x40
        #define I2S_CH1_DATA_24BIT          0x20
        #define I2S_CH1_DATA_20BIT          0x10
        #define I2S_CH0_DATA_24BIT          0x08
        #define I2S_CH0_DATA_20BIT          0x04
        #define AFE_MUX_AUTO_MODE           0x01
        #define AFE_MUX_CPU_MODE           	0x00
		/*------------------------------------------------------------*/ 
    AIT_REG_B   AFE_DATA_BIT_TRANS;                                     // 0x71
        /*-DEFINE-----------------------------------------------------*/
        #define AFE_ADC_DATA_BIT_MASK       0xF0
        #define AFE_ADC_DATA_BIT_SEL(_a)    (_a << 4)
        #define AFE_DAC_DATA_BIT_MASK       0x07
        #define AFE_DAC_DATA_BIT_SEL(_a)    (_a)
        /*------------------------------------------------------------*/ 
    AIT_REG_B   AFE_DMIC_CLK_DATA_CTL;                                  // 0x72
        /*-DEFINE-----------------------------------------------------*/
        #define AFE_DMIC_CLK_EN             0x08
        #define AFE_DMIC_LR_DATA_SWAP		0x04
        #define AFE_DMIC_DATA_INV_EN		0x02
        #define AFE_DMIC_CLK_INV_EN			0x01
        /*------------------------------------------------------------*/ 
    AIT_REG_B   AFE_ADDA_BIT_MODE;                               		// 0x73
    AIT_REG_B                           _x7F74[12];
    					
	AUD_FIFO  	AFE_ADC_FIFO;											// 0x80

    AIT_REG_B                           _x7FA0[48];
    
    AIT_REG_B                           _x7FE0[8];
    AIT_REG_B   AFE_ADC_LOOP_CTL;                                       // 0xE8
        /*-DEFINE-----------------------------------------------------*/
        #define AFE_ADC_LOOP_DAC_FILTER_EN	0x01
        /*------------------------------------------------------------*/ 
    AIT_REG_B                           _x7FE9[7];
    
    AIT_REG_B                           _x7FF0[16];
} AITS_AUD, *AITPS_AUD;

//--------------------------------------------
// New Audio Digital Filter structure (0x80006500)
//--------------------------------------------
typedef struct _AITS_DADC_EXT {
    AIT_REG_W   DADC_HPF_MODE_SEL;                                      // 0x00
        /*-DEFINE-----------------------------------------------------*/
        #define ADC_HPF_BYPASS              0x0000
        #define ADC_HPF_AUD                 0x0101
        #define ADC_HPF_VOC                 0x0202
        /*------------------------------------------------------------*/
    AIT_REG_W   DADC_HPF_AUD_MODE_COEF;                                 // 0x02
        /*-DEFINE-----------------------------------------------------*/
        #define HPF_AUD_FC_2HZ              0x0000
        #define HPF_AUD_FC_4HZ              0x0101
        #define HPF_AUD_FC_8HZ              0x0202
        #define HPF_AUD_FC_16HZ             0x0303
        /*------------------------------------------------------------*/
    AIT_REG_W   DADC_HPF_VOC_MODE_COEF;                                 // 0x04
        /*-DEFINE-----------------------------------------------------*/
        #define HPF_VOC_FC_2D5HZ            0x0000
        #define HPF_VOC_FC_25HZ             0x0101
        #define HPF_VOC_FC_50HZ             0x0202
        #define HPF_VOC_FC_100HZ            0x0303
        #define HPF_VOC_FC_150HZ            0x0404
        #define HPF_VOC_FC_200HZ            0x0505
        #define HPF_VOC_FC_300HZ            0x0606
        #define HPF_VOC_FC_400HZ            0x0707
        /*------------------------------------------------------------*/
    AIT_REG_B   DADC_L_EQ_LSF_COEF;                                     // 0x06
    AIT_REG_B   DADC_L_EQ_PK1_COEF;                                     // 0x07
    AIT_REG_B   DADC_L_EQ_PK2_COEF;                                     // 0x08
    AIT_REG_B   DADC_L_EQ_PK3_COEF;                                     // 0x09
    AIT_REG_B   DADC_L_EQ_HSF_COEF;                                     // 0x0A
    AIT_REG_B   DADC_R_EQ_LSF_COEF;                                     // 0x0B
    AIT_REG_B   DADC_R_EQ_PK1_COEF;                                     // 0x0C
    AIT_REG_B   DADC_R_EQ_PK2_COEF;                                     // 0x0D
    AIT_REG_B   DADC_R_EQ_PK3_COEF;                                     // 0x0E
    AIT_REG_B   DADC_R_EQ_HSF_COEF;                                     // 0x0F

    AIT_REG_B   DADC_L_NF0_B0_COEF_LOW[2];                              // 0x10
    AIT_REG_B   DADC_L_NF0_B0_COEF_HIG;                                 // 0x12
    AIT_REG_B   DADC_L_NF0_B1_COEF_LOW[2];                              // 0x13
    AIT_REG_B   DADC_L_NF0_B1_COEF_HIG;                                 // 0x15
    AIT_REG_B   DADC_L_NF0_B2_COEF_LOW[2];                              // 0x16
    AIT_REG_B   DADC_L_NF0_B2_COEF_HIG;                                 // 0x18
    AIT_REG_B   DADC_L_NF0_A1_COEF_LOW[2];                              // 0x19
    AIT_REG_B   DADC_L_NF0_A1_COEF_HIG;                                 // 0x1B
    AIT_REG_B   DADC_L_NF0_A2_COEF_LOW[2];                              // 0x1C
    AIT_REG_B   DADC_L_NF0_A2_COEF_HIG;                                 // 0x1E
    AIT_REG_B    						_x651F;
    
    AIT_REG_B   DADC_L_NF1_B0_COEF_LOW[2];                              // 0x20
    AIT_REG_B   DADC_L_NF1_B0_COEF_HIG;                                 // 0x22
    AIT_REG_B   DADC_L_NF1_B1_COEF_LOW[2];                              // 0x23
    AIT_REG_B   DADC_L_NF1_B1_COEF_HIG;                                 // 0x25
    AIT_REG_B   DADC_L_NF1_B2_COEF_LOW[2];                              // 0x26
    AIT_REG_B   DADC_L_NF1_B2_COEF_HIG;                                 // 0x28
    AIT_REG_B   DADC_L_NF1_A1_COEF_LOW[2];                              // 0x29
    AIT_REG_B   DADC_L_NF1_A1_COEF_HIG;                                 // 0x2B
    AIT_REG_B   DADC_L_NF1_A2_COEF_LOW[2];                              // 0x2C
    AIT_REG_B   DADC_L_NF1_A2_COEF_HIG;                                 // 0x2E
    AIT_REG_B    						_x652F;
    
    AIT_REG_B   DADC_L_NF2_B0_COEF_LOW[2];                              // 0x30
    AIT_REG_B   DADC_L_NF2_B0_COEF_HIG;                                 // 0x32
    AIT_REG_B   DADC_L_NF2_B1_COEF_LOW[2];                              // 0x33
    AIT_REG_B   DADC_L_NF2_B1_COEF_HIG;                                 // 0x35
    AIT_REG_B   DADC_L_NF2_B2_COEF_LOW[2];                              // 0x36
    AIT_REG_B   DADC_L_NF2_B2_COEF_HIG;                                 // 0x38
    AIT_REG_B   DADC_L_NF2_A1_COEF_LOW[2];                              // 0x39
    AIT_REG_B   DADC_L_NF2_A1_COEF_HIG;                                 // 0x3B
    AIT_REG_B   DADC_L_NF2_A2_COEF_LOW[2];                              // 0x3C
    AIT_REG_B   DADC_L_NF2_A2_COEF_HIG;                                 // 0x3E
    AIT_REG_B    						_x653F;

    AIT_REG_B   DADC_L_NF3_B0_COEF_LOW[2];                              // 0x40
    AIT_REG_B   DADC_L_NF3_B0_COEF_HIG;                                 // 0x42
    AIT_REG_B   DADC_L_NF3_B1_COEF_LOW[2];                              // 0x43
    AIT_REG_B   DADC_L_NF3_B1_COEF_HIG;                                 // 0x45
    AIT_REG_B   DADC_L_NF3_B2_COEF_LOW[2];                              // 0x46
    AIT_REG_B   DADC_L_NF3_B2_COEF_HIG;                                 // 0x48
    AIT_REG_B   DADC_L_NF3_A1_COEF_LOW[2];                              // 0x49
    AIT_REG_B   DADC_L_NF3_A1_COEF_HIG;                                 // 0x4B
    AIT_REG_B   DADC_L_NF3_A2_COEF_LOW[2];                              // 0x4C
    AIT_REG_B   DADC_L_NF3_A2_COEF_HIG;                                 // 0x4E
    AIT_REG_B    						_x654F;

    AIT_REG_B   DADC_L_NF4_B0_COEF_LOW[2];                              // 0x50
    AIT_REG_B   DADC_L_NF4_B0_COEF_HIG;                                 // 0x52
    AIT_REG_B   DADC_L_NF4_B1_COEF_LOW[2];                              // 0x53
    AIT_REG_B   DADC_L_NF4_B1_COEF_HIG;                                 // 0x55
    AIT_REG_B   DADC_L_NF4_B2_COEF_LOW[2];                              // 0x56
    AIT_REG_B   DADC_L_NF4_B2_COEF_HIG;                                 // 0x58
    AIT_REG_B   DADC_L_NF4_A1_COEF_LOW[2];                              // 0x59
    AIT_REG_B   DADC_L_NF4_A1_COEF_HIG;                                 // 0x5B
    AIT_REG_B   DADC_L_NF4_A2_COEF_LOW[2];                              // 0x5C
    AIT_REG_B   DADC_L_NF4_A2_COEF_HIG;                                 // 0x5E
    AIT_REG_B    						_x655F;

    AIT_REG_B   DADC_R_NF0_B0_COEF_LOW[2];                              // 0x60
    AIT_REG_B   DADC_R_NF0_B0_COEF_HIG;                                 // 0x62
    AIT_REG_B   DADC_R_NF0_B1_COEF_LOW[2];                              // 0x63
    AIT_REG_B   DADC_R_NF0_B1_COEF_HIG;                                 // 0x65
    AIT_REG_B   DADC_R_NF0_B2_COEF_LOW[2];                              // 0x66
    AIT_REG_B   DADC_R_NF0_B2_COEF_HIG;                                 // 0x68
    AIT_REG_B   DADC_R_NF0_A1_COEF_LOW[2];                              // 0x69
    AIT_REG_B   DADC_R_NF0_A1_COEF_HIG;                                 // 0x6B
    AIT_REG_B   DADC_R_NF0_A2_COEF_LOW[2];                              // 0x6C
    AIT_REG_B   DADC_R_NF0_A2_COEF_HIG;                                 // 0x6E
    AIT_REG_B    						_x656F;

    AIT_REG_B   DADC_R_NF1_B0_COEF_LOW[2];                              // 0x70
    AIT_REG_B   DADC_R_NF1_B0_COEF_HIG;                                 // 0x72
    AIT_REG_B   DADC_R_NF1_B1_COEF_LOW[2];                              // 0x73
    AIT_REG_B   DADC_R_NF1_B1_COEF_HIG;                                 // 0x75
    AIT_REG_B   DADC_R_NF1_B2_COEF_LOW[2];                              // 0x76
    AIT_REG_B   DADC_R_NF1_B2_COEF_HIG;                                 // 0x78
    AIT_REG_B   DADC_R_NF1_A1_COEF_LOW[2];                              // 0x79
    AIT_REG_B   DADC_R_NF1_A1_COEF_HIG;                                 // 0x7B
    AIT_REG_B   DADC_R_NF1_A2_COEF_LOW[2];                              // 0x7C
    AIT_REG_B   DADC_R_NF1_A2_COEF_HIG;                                 // 0x7E
    AIT_REG_B    						_x657F;

    AIT_REG_B   DADC_R_NF2_B0_COEF_LOW[2];                              // 0x80
    AIT_REG_B   DADC_R_NF2_B0_COEF_HIG;                                 // 0x82
    AIT_REG_B   DADC_R_NF2_B1_COEF_LOW[2];                              // 0x83
    AIT_REG_B   DADC_R_NF2_B1_COEF_HIG;                                 // 0x85
    AIT_REG_B   DADC_R_NF2_B2_COEF_LOW[2];                              // 0x86
    AIT_REG_B   DADC_R_NF2_B2_COEF_HIG;                                 // 0x88
    AIT_REG_B   DADC_R_NF2_A1_COEF_LOW[2];                              // 0x89
    AIT_REG_B   DADC_R_NF2_A1_COEF_HIG;                                 // 0x8B
    AIT_REG_B   DADC_R_NF2_A2_COEF_LOW[2];                              // 0x8C
    AIT_REG_B   DADC_R_NF2_A2_COEF_HIG;                                 // 0x8E
    AIT_REG_B    						_x658F;

    AIT_REG_B   DADC_R_NF3_B0_COEF_LOW[2];                              // 0x90
    AIT_REG_B   DADC_R_NF3_B0_COEF_HIG;                                 // 0x92
    AIT_REG_B   DADC_R_NF3_B1_COEF_LOW[2];                              // 0x93
    AIT_REG_B   DADC_R_NF3_B1_COEF_HIG;                                 // 0x95
    AIT_REG_B   DADC_R_NF3_B2_COEF_LOW[2];                              // 0x96
    AIT_REG_B   DADC_R_NF3_B2_COEF_HIG;                                 // 0x98
    AIT_REG_B   DADC_R_NF3_A1_COEF_LOW[2];                              // 0x99
    AIT_REG_B   DADC_R_NF3_A1_COEF_HIG;                                 // 0x9B
    AIT_REG_B   DADC_R_NF3_A2_COEF_LOW[2];                              // 0x9C
    AIT_REG_B   DADC_R_NF3_A2_COEF_HIG;                                 // 0x9E
    AIT_REG_B    						_x659F;

    AIT_REG_B   DADC_R_NF4_B0_COEF_LOW[2];                              // 0xA0
    AIT_REG_B   DADC_R_NF4_B0_COEF_HIG;                                 // 0xA2
    AIT_REG_B   DADC_R_NF4_B1_COEF_LOW[2];                              // 0xA3
    AIT_REG_B   DADC_R_NF4_B1_COEF_HIG;                                 // 0xA5
    AIT_REG_B   DADC_R_NF4_B2_COEF_LOW[2];                              // 0xA6
    AIT_REG_B   DADC_R_NF4_B2_COEF_HIG;                                 // 0xA8
    AIT_REG_B   DADC_R_NF4_A1_COEF_LOW[2];                              // 0xA9
    AIT_REG_B   DADC_R_NF4_A1_COEF_HIG;                                 // 0xAB
    AIT_REG_B   DADC_R_NF4_A2_COEF_LOW[2];                              // 0xAC
    AIT_REG_B   DADC_R_NF4_A2_COEF_HIG;                                 // 0xAE
    AIT_REG_B    						_x65AF;
     
} AITS_DADC_EXT, *AITPS_DADC_EXT;

#endif //(CHIP == MCR_V2)

/// @}

#endif // _MMP_REG_AUDIO_H_
