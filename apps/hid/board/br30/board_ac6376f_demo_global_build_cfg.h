#ifndef CONFIG_BOARD_AC6376F_DEMO_POST_BUILD_CFG_H
#define CONFIG_BOARD_AC6376F_DEMO_POST_BUILD_CFG_H

/* 改文件只添加和isd_config.ini相关的配置，用以生成isd_config.ini */
/* 其他不相关的配置请勿添加在改文件 */

#ifdef CONFIG_BOARD_AC6376F_DEMO

/* Following Macros Affect Periods Of Both Code Compiling And Post-build */

#define CONFIG_DOUBLE_BANK_ENABLE               0       //单双备份选择
#define CONFIG_APP_OTA_ENABLE                   0       //是否支持APP升级

#undef RCSP_BTMATE_EN
#undef RCSP_UPDATE_EN
#undef UPDATE_MD5_ENABLE

#if CONFIG_APP_OTA_ENABLE
#define RCSP_BTMATE_EN                    1
#define RCSP_UPDATE_EN                    1
#define UPDATE_MD5_ENABLE                 0
#else
#define RCSP_BTMATE_EN                    0
#define RCSP_UPDATE_EN                    0
#define UPDATE_MD5_ENABLE                 0
#endif

#define CONFIG_UPDATE_JUMP_TO_MASK              0   	//配置升级到loader的方式0为直接reset,1为跳转

#define CONFIG_LP_TOUCH_KEY_EN					0		//配置是否使用内置触摸
#define CONFIG_UPDATE_WITH_MD5_CHECK_EN			0 		//配置升级是否支持MD5校验

#define CONFIG_ANC_ENABLE           			0		//配置是否支持ANC

//flash size vaule definition
#define FLASH_SIZE_256K							0x40000
#define FLASH_SIZE_512K							0x80000
#define FLASH_SIZE_1M							0x100000
#define FLASH_SIZE_2M							0x200000
#define FLASH_SIZE_4M							0x400000

#define CONFIG_FLASH_SIZE                       FLASH_SIZE_1M    //配置FLASH大小


/* Above Macros Affect Periods Of Both Code Compiling And Post-build */

/* Following Macros Only For Post Bulid Configuaration */

#define CONFIG_DB_UPDATE_DATA_GENERATE_EN       0       //是否生成db_data.bin(用于GMA升级)
#define CONFIG_ONLY_GRENERATE_ALIGN_4K_CODE     0    	//ufw只生成1份4K对齐的代码

//config for supported chip version
#ifdef CONFIG_BR30_C_VERSION
#define CONFIG_SUPPORTED_CHIP_VERSION			C
#else
#define CONFIG_SUPPORTED_CHIP_VERSION			B,D,E,M,N,O,P
#endif

//DON'T MODIFY THIS CONFIG EXCEPT SDK PUBLISHER
#define CONFIG_CHIP_NAME                        AD697N	 			//除了SDK发布者,请不要修改
//it can be modified before first programming,but keep the same as the original version
#define CONFIG_PID                              AD697N				//烧写或强制升级之前可以修改,之后升级要保持一致
//it can be modified before first programming,but keep the same as the original version
#define CONFIG_VID                              0.01				//烧写或强制升级之前可以修改,之后升级要保持一致

//Project with bluetooth,it must use OSC as PLL_SOURCE;
#define CONFIG_PLL_SOURCE_USING_LRC             0       			//PLL时钟源选择 1:LRC 2:OSC

//config alignment size unit
#ifdef CONFIG_256K_FLASH
#define ALIGN_UNIT_256B             1                 				//FLASH对齐方式选择，如果是256K的FLASH，选择256BYTE对齐方式
#else
#define ALIGN_UNIT_256B             0
#endif

//partial platform check this config to select the uart IO for wired update
#define CONFIG_UART_UPDATE_PIN                  PB05

//isd_download loader/uboot/update_loader debug io config
//#define CONFIG_UBOOT_DEBUG_PIN                  PA05
//#define CONFIG_UBOOT_DEBUG_BAUD_RATE            1000000

//config long-press reset io pin,time,trigger level
#if CONFIG_LP_TOUCH_KEY_EN
#define CONFIG_RESET_PIN                        LDO  //io pin
#define CONFIG_RESET_TIME                       04   //unit:second
#define CONFIG_RESET_LEVEL                      1	 //tigger level(0/1)
#else
#define CONFIG_RESET_PIN                        PB01 //io pin
#define CONFIG_RESET_TIME                       08   //unit:second
#define CONFIG_RESET_LEVEL                      0	 //tigger level(0/1)
#endif

//reserved three custom cfg item for the future definition
//#define CONFIG_CUSTOM_CFG1_TYPE			POWER_PIN
//#define CONFIG_CUSTOM_CFG1_VALUE		 	PC01_1

//#define CONFIG_CUSTOM_CFG2_TYPE
//#define CONFIG_CUSTOM_CFG2_VALUE

//#define CONFIG_CUSTOM_CFG3_TYPE
//#define CONFIG_CUSTOM_CFG3_VALUE


//#define CONFIG_VDDIO_LVD_LEVEL                  4 ////VDDIO_LVD挡位，0: 1.9V   1: 2.0V   2: 2.1V   3: 2.2V   4: 2.3V   5: 2.4V   6: 2.5V   7: 2.6V

//with single-bank mode,actual vm size should larger this VM_LEAST_SIZE,and dual bank mode,actual vm size equals this;
#define CONFIG_VM_LEAST_SIZE                    8K
//config whether erased this area when do a update,1-No Operation,0-Erase
#define CONFIG_VM_OPT							1

//config whether erased this area when do a update,1-No Operation,0-Erase
#define CONFIG_BTIF_OPT							1

//reserved two custom cfg area for the future definition
//#define CONFIG_RESERVED_AREA1					EXIF1
#ifdef CONFIG_RESERVED_AREA1
#define CONFIG_RESERVED_AREA1_ADDR				AUTO
#define CONFIG_RESERVED_AREA1_LEN				0x1000
#define CONFIG_RESERVED_AREA1_OPT				1
//#define CONFIG_RESERVED_AREA1_FILE				anc_gains.bin
#endif

//#define CONFIG_RESERVED_AREA2					EXIF2
#ifdef CONFIG_RESERVED_AREA2
#define CONFIG_RESERVED_AREA2_ADDR				AUTO
#define CONFIG_RESERVED_AREA2_LEN				0x1000
#define CONFIG_RESERVED_AREA2_OPT				1
//#define CONFIG_RESERVED_AREA2_FILE				anc_gains.bin
#endif

/* Above Macros Only For Post Bulid Configuaration */
#endif

#endif
