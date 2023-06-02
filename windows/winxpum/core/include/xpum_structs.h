#ifndef _XPUM_STRUCTS_H
#define _XPUM_STRUCTS_H

#pragma once

#include <stdbool.h>
#include <stdint.h>

namespace xpum {
extern "C" {

/**
 * Max string length
 */
#define XPUM_MAX_STR_LENGTH 256

/**
 * Max version string length
 */
#define XPUM_MAX_VERSION_STR_LENGTH 32

/**
 * Max number of devices supported by XPUM
 */
#define XPUM_MAX_NUM_DEVICES 32

/**
 * Max limit on the number of properties of a device supported by XPUM
 */
#define XPUM_MAX_NUM_PROPERTIES 100

/**
 * The device id stand for all devices
 */
#define XPUM_DEVICE_ID_ALL_DEVICES 1024

/**
 * Device id
 */
typedef int32_t xpum_device_id_t;

/**
 * Tile id
 */
typedef int32_t xpum_device_tile_id_t;

/**
 * API call results
 */
typedef enum xpum_result_enum {
    XPUM_OK = 0,                  ///< Ok
    XPUM_GENERIC_ERROR,           ///< Function return with unknown errors
    XPUM_BUFFER_TOO_SMALL,        ///< The buffer pass to function is too small
    XPUM_RESULT_DEVICE_NOT_FOUND, ///< Device not found
    XPUM_RESULT_TILE_NOT_FOUND,   ///< Tile not found
    XPUM_RESULT_GROUP_NOT_FOUND,
    XPUM_RESULT_POLICY_TYPE_INVALID,               // Policy type is invalid
    XPUM_RESULT_POLICY_ACTION_TYPE_INVALID,        // Policy action type is invalid
    XPUM_RESULT_POLICY_CONDITION_TYPE_INVALID,     // Policy condtion type is invalid
    XPUM_RESULT_POLICY_TYPE_ACTION_NOT_SUPPORT,    // Policy type and policy action not match
    XPUM_RESULT_POLICY_TYPE_CONDITION_NOT_SUPPORT, // Policy type and condition type not match
    XPUM_RESULT_POLICY_INVALID_THRESHOLD,          //Policy threshold invalid
    XPUM_RESULT_POLICY_INVALID_FREQUENCY,          //Policy frequency invalid
    XPUM_RESULT_POLICY_NOT_EXIST,                  //Policy not exist
    XPUM_RESULT_DIAGNOSTIC_TASK_NOT_COMPLETE,
    XPUM_RESULT_DIAGNOSTIC_TASK_NOT_FOUND,
    XPUM_GROUP_DEVICE_DUPLICATED,
    XPUM_GROUP_CHANGE_NOT_ALLOWED,
    XPUM_NOT_INITIALIZED,                      ///< XPUM is not initialized.
    XPUM_DUMP_RAW_DATA_TASK_NOT_EXIST,         ///< Dump raw data task not exists
    XPUM_DUMP_RAW_DATA_ILLEGAL_DUMP_FILE_PATH, ///< Dump file path provide is illegal
    XPUM_RESULT_UNKNOWN_AGENT_CONFIG_KEY,      ///< The the key for agent setting is unknown
    XPUM_UPDATE_FIRMWARE_IMAGE_FILE_NOT_FOUND,
    XPUM_UPDATE_FIRMWARE_UNSUPPORTED_AMC,
    XPUM_UPDATE_FIRMWARE_UNSUPPORTED_AMC_SINGLE,
    XPUM_UPDATE_FIRMWARE_UNSUPPORTED_GFX_ALL,   ///< Don't support updating GFX firmwares on all device
    XPUM_UPDATE_FIRMWARE_MODEL_INCONSISTENCE,
    XPUM_UPDATE_FIRMWARE_IGSC_NOT_FOUND, /// "/usr/bin/igsc" not found
    XPUM_UPDATE_FIRMWARE_TASK_RUNNING,       /// Firmware update task is already running
    XPUM_UPDATE_FIRMWARE_INVALID_FW_IMAGE,       /// The image file is not a valid FW image file
    XPUM_UPDATE_FIRMWARE_FW_IMAGE_NOT_COMPATIBLE_WITH_DEVICE,       /// The image file is not compatible with device
    XPUM_RESULT_DUMP_METRICS_TYPE_NOT_SUPPORT,
    XPUM_METRIC_NOT_SUPPORTED, ///< Unsupported metric
    XPUM_METRIC_NOT_ENABLED,   ///< Unenabled metric
    XPUM_RESULT_HEALTH_INVALID_TYPE,
    XPUM_RESULT_HEALTH_INVALID_CONIG_TYPE,
    XPUM_RESULT_HEALTH_INVALID_THRESHOLD,
    XPUM_RESULT_DIAGNOSTIC_INVALID_LEVEL,
    XPUM_RESULT_DIAGNOSTIC_INVALID_TASK_TYPE,
    XPUM_RESULT_AGENT_SET_INVALID_VALUE,  /// Agent set value is invalid
    XPUM_LEVEL_ZERO_INITIALIZATION_ERROR, ///< Level Zero initialization error.
    XPUM_UNSUPPORTED_SESSIONID,           ///< Unsupported session id
    XPUM_RESULT_MEMORY_ECC_LIB_NOT_SUPPORT,
    XPUM_UPDATE_FIRMWARE_UNSUPPORTED_GFX_DATA, ///< The device doesn't support GFX_DATA firmware update
    XPUM_UPDATE_FIRMWARE_UNSUPPORTED_PSC, ///< The device doesn't support PSCBIN firmware update
    XPUM_UPDATE_FIRMWARE_UNSUPPORTED_PSC_IGSC, ///< Installed igsc doesn't support PSCBIN firmware update
    XPUM_INTERVAL_INVALID,
    XPUM_RESULT_FILE_DUP,
    XPUM_RESULT_INVALID_DIR,
    XPUM_RESULT_FW_MGMT_NOT_INIT, ///< The firmware management feature is not initialized
    XPUM_API_UNSUPPORTED
} xpum_result_t;

typedef enum xpum_device_type_enum {
    GPU = 0, ///< GPU
} xpum_device_type_t;

typedef enum xpum_device_function_type_enum {
    DEVICE_FUNCTION_TYPE_VIRTUAL = 0,
    DEVICE_FUNCTION_TYPE_PHYSICAL = 1,
    DEVICE_FUNCTION_TYPE_UNKNOWN = 0x7fffffff,
} xpum_device_function_type_t;

/**
 * XPUM version types
 */
typedef enum xpum_version_enum {
    XPUM_VERSION = 0,       ///< XPUM version
    XPUM_VERSION_GIT,       ///< The git commit hash of this build
    XPUM_VERSION_LEVEL_ZERO ///< Underlying level-zero lib version
} xpum_version_t;

/**
 * XPUM version info
 */
typedef struct xpum_version_info {
    xpum_version_t version;                          ///< XPUM version types
    char versionString[XPUM_MAX_VERSION_STR_LENGTH]; ///< Version strings
} xpum_version_info;

/**
 * Device basic info
 */
typedef struct xpum_device_basic_info {
    xpum_device_id_t deviceId;               ///< Device id
    xpum_device_type_t type;                 ///< Device type
    xpum_device_function_type_t functionType;   ///< Device function type, PF or VF
    char uuid[XPUM_MAX_STR_LENGTH];          ///< Device uuid
    char deviceName[XPUM_MAX_STR_LENGTH];    ///< Device name
    char PCIDeviceId[XPUM_MAX_STR_LENGTH];   ///< Device PCI device id
    char PCIBDFAddress[XPUM_MAX_STR_LENGTH]; ///< Device PCI bdf address
    char VendorName[XPUM_MAX_STR_LENGTH];    ///< Device vendor name
    char drmDevice[XPUM_MAX_STR_LENGTH];     ///< DRM Device
} xpum_device_basic_info;

/**
 * Device property types
 */
typedef enum xpum_device_property_name_enum {
    XPUM_DEVICE_PROPERTY_DEVICE_TYPE,                    ///< Device type
    XPUM_DEVICE_PROPERTY_DEVICE_NAME,                    ///< Device name
    XPUM_DEVICE_PROPERTY_VENDOR_NAME,                    ///< Vendor name
    XPUM_DEVICE_PROPERTY_UUID,                           ///< Device uuid
    XPUM_DEVICE_PROPERTY_PCI_DEVICE_ID,                  ///< The PCI device id of device
    XPUM_DEVICE_PROPERTY_PCI_VENDOR_ID,                  ///< The PCI vendor id of device
    XPUM_DEVICE_PROPERTY_PCI_BDF_ADDRESS,                ///< The PCI bdf address of device
    XPUM_DEVICE_PROPERTY_DRM_DEVICE,                     ///< DRM Device 
    XPUM_DEVICE_PROPERTY_PCI_SLOT,                       ///< PCI slot of device
    XPUM_DEVICE_PROPERTY_PCIE_GENERATION,                ///< PCIe generation
    XPUM_DEVICE_PROPERTY_PCIE_MAX_LINK_WIDTH,            ///< PCIe max link width
    XPUM_DEVICE_PROPERTY_OAM_SOCKET_ID,                  ///< Socket Id of OAM GPU
    XPUM_DEVICE_PROPERTY_DEVICE_STEPPING,                ///< The stepping of device
    XPUM_DEVICE_PROPERTY_DRIVER_VERSION,                 ///< The driver version
    XPUM_DEVICE_PROPERTY_GFX_FIRMWARE_NAME,              ///< The GFX firmware name of device
    XPUM_DEVICE_PROPERTY_GFX_FIRMWARE_VERSION,           ///< The GFX firmware version of device
    XPUM_DEVICE_PROPERTY_GFX_DATA_FIRMWARE_NAME,         ///< The GFX Data firmware name of device
    XPUM_DEVICE_PROPERTY_GFX_DATA_FIRMWARE_VERSION,      ///< The GFX Data firmware version of device
    XPUM_DEVICE_PROPERTY_AMC_FIRMWARE_NAME,              ///< The AMC firmware name of device
    XPUM_DEVICE_PROPERTY_AMC_FIRMWARE_VERSION,           ///< The AMC firmware version of device
    XPUM_DEVICE_PROPERTY_SERIAL_NUMBER,                  ///< Serial number
    XPUM_DEVICE_PROPERTY_CORE_CLOCK_RATE_MHZ,            ///< Clock rate for device core, in MHz
    XPUM_DEVICE_PROPERTY_MEMORY_PHYSICAL_SIZE_BYTE,      ///< Device free memory size, in bytes
    XPUM_DEVICE_PROPERTY_MEMORY_FREE_SIZE_BYTE,          ///< The free memory, in bytes
    XPUM_DEVICE_PROPERTY_MAX_MEM_ALLOC_SIZE_BYTE,        ///< The total allocatable memory, in bytes
    XPUM_DEVICE_PROPERTY_NUMBER_OF_MEMORY_CHANNELS,      ///< Number of memory channels
    XPUM_DEVICE_PROPERTY_MEMORY_BUS_WIDTH,               ///< Memory bus width
    XPUM_DEVICE_PROPERTY_MAX_HARDWARE_CONTEXTS,          ///< Maximum number of logical hardware contexts
    XPUM_DEVICE_PROPERTY_MAX_COMMAND_QUEUE_PRIORITY,     ///< Maximum priority for command queues. Higher value is higher priority
    XPUM_DEVICE_PROPERTY_NUMBER_OF_EUS,                  ///< The number of EUs
    XPUM_DEVICE_PROPERTY_NUMBER_OF_TILES,                ///< The number of tiles
    XPUM_DEVICE_PROPERTY_NUMBER_OF_SLICES,               ///< Maximum number of slices
    XPUM_DEVICE_PROPERTY_NUMBER_OF_SUB_SLICES_PER_SLICE, ///< Maximum number of sub-slices per slice
    XPUM_DEVICE_PROPERTY_NUMBER_OF_EUS_PER_SUB_SLICE,    ///< Maximum number of EUs per sub-slice
    XPUM_DEVICE_PROPERTY_NUMBER_OF_THREADS_PER_EU,       ///< Maximum number of threads per EU
    XPUM_DEVICE_PROPERTY_PHYSICAL_EU_SIMD_WIDTH,         ///< The physical EU simd width
    XPUM_DEVICE_PROPERTY_NUMBER_OF_MEDIA_ENGINES,        ///< The number of media engines
    XPUM_DEVICE_PROPERTY_NUMBER_OF_MEDIA_ENH_ENGINES,    ///< The number of media enhancement engines
    XPUM_DEVICE_PROPERTY_LINUX_KERNEL_VERSION,           ///< Linux kernel version
    XPUM_DEVICE_PROPERTY_FABRIC_PORT_NUMBER,             ///< Number of fabric ports
    XPUM_DEVICE_PROPERTY_FABRIC_PORT_MAX_SPEED,          ///< Maximum speed supported by the port (sum of all lanes)
    XPUM_DEVICE_PROPERTY_FABRIC_PORT_LANES_NUMBER,       ///< The number of lanes of the port
    XPUM_DEVICE_PROPERTY_GFX_PSCBIN_FIRMWARE_NAME,       ///< The GFX_PSCBIN firmware name of device
    XPUM_DEVICE_PROPERTY_GFX_PSCBIN_FIRMWARE_VERSION,    ///< The GFX_PSCBIN firmware version of device
    XPUM_DEVICE_PROPERTY_MEMORY_ECC_STATE,               ///< The memory ECC state of device
    XPUM_DEVICE_PROPERTY_GFX_FIRMWARE_STATUS,            ///< The GFX firmware status
    XPUM_DEVICE_PROPERTY_SKU_TYPE,                       ///< The type of SKU
    XPUM_DEVICE_PROPERTY_MAX
} xpum_device_property_name_t;

/**
 * @brief Struct for one device property
 */
typedef struct xpum_device_property_t {
    xpum_device_property_name_t name; ///< Device property name
    char value[XPUM_MAX_STR_LENGTH];  ///< Device property value strings
} xpum_device_property_t;

/**
 * @brief Struct stores all properties of a device
 *
 */
typedef struct xpum_device_properties_t {
    xpum_device_id_t deviceId; ///< Device id
    xpum_device_property_t properties[XPUM_MAX_NUM_PROPERTIES];
    int propertyLen; ///< The property numbers stored in properties
} xpum_device_properties_t;

/**
 * @brief Struct AMC firmware version
 *
 */
typedef struct xpum_amc_fw_version_t {
    char version[XPUM_MAX_STR_LENGTH];
} xpum_amc_fw_version_t;

/**************************************************************************/
/**
 * Definitions for configuration
 */
 /**************************************************************************/

typedef enum xpum_device_mode_enum {
    XPUM_GPU_SCHEDULE_MODE = 0,
    XPUM_GPU_STANDBY_MODE
} xpum_device_mode_t;

typedef enum xpum_device_config_type_enum {
    XPUM_DEVICE_CONFIG_DEVICE_MODE = 0,
    XPUM_DEVICE_CONFIG_POWER_LIMIT_ENABLED,
    XPUM_DEVICE_CONFIG_POWER_LIMIT_VALUE,
    XPUM_DEVICE_CONFIG_POWER_LIMIT_AVG_WINDOW,
    XPUM_DEVICE_CONFIG_CORE_FREQ_MIN,
    XPUM_DEVICE_CONFIG_CORE_FREQ_MAX,
    XPUM_DEVICE_CONFIG_RESET,
} xpum_device_config_type_t;

/**************************************************************************/
/**
 * Definitions for firmware update
 */
 /**************************************************************************/

 /**
  * @brief Firmware types
  *
  */
typedef enum xpum_firmware_type_enum {
    XPUM_DEVICE_FIRMWARE_GFX = 0, ///< GFX firmware
    XPUM_DEVICE_FIRMWARE_AMC = 1, ///< AMC firmware
    XPUM_DEVICE_FIRMWARE_GFX_DATA = 2, ///< GFX_DATA firmware
    XPUM_DEVICE_FIRMWARE_GFX_PSCBIN = 3, ///< GFX_PSCBIN firmware
} xpum_firmware_type_t;

/**
 * @brief Firmware flash states
 *
 */
typedef enum xpum_firmware_flash_result_enum {
    XPUM_DEVICE_FIRMWARE_FLASH_OK = 0,      ///< Firmware flash successfully
    XPUM_DEVICE_FIRMWARE_FLASH_ERROR,       ///< Firmware flash in error
    XPUM_DEVICE_FIRMWARE_FLASH_ONGOING,     ///< Firmware flash is on going
    XPUM_DEVICE_FIRMWARE_FLASH_UNSUPPORTED, ///< Firmware flash is unsupported
} xpum_firmware_flash_result_t;

/**
 * @brief Firmware flash job
 *
 */
typedef struct xpum_firmware_flash_job {
    xpum_firmware_type_t type; ///< The firmware type to flash
    const char* filePath;      ///< The path of firmware binary file to flash
} xpum_firmware_flash_job;

/**
 * @brief The struct stores the firmware flash states
 *
 */
typedef struct xpum_firmware_flash_task_result_t {
    xpum_device_id_t deviceId;             ///< The id of the device to flash firmware
    xpum_firmware_type_t type;             ///< The firmware type to flash
    xpum_firmware_flash_result_t result;   ///< Which state the firmware flash job is in
    char description[XPUM_MAX_STR_LENGTH]; ///< The description of this result
    char version[XPUM_MAX_STR_LENGTH];     ///< Current firmware version
    int percentage;
} xpum_firmware_flash_task_result_t;

typedef struct xpum_fabric_port_config_t {
    bool onSubdevice;
    uint32_t subdeviceId;
    uint32_t fabricId;
    uint32_t attachId;
    uint8_t portNumber;
    bool enabled;
    bool beaconing;
    bool setting_enabled;
    bool setting_beaconing;
} xpum_fabric_port_config_t;

typedef enum xpum_engine_type_flags_t {
    XPUM_UNDEFINED = 1 << 0,
    XPUM_COMPUTE = 1 << 1,
    XPUM_THREE_D = 1 << 2,
    XPUM_MEDIA = 1 << 3,
    XPUM_COPY = 1 << 4,
    XPUM_RENDER = 1 << 5,
    XPUM_TYPE_FLAGS_FORCE_UINT32 = 0x7fffffff
} xpum_engine_type_flags_t;

typedef enum xpum_standby_type_t {
    XPUM_GLOBAL = 0,
    XPUM_STANDBY_TYPE_FORCE_UINT32 = 0x7fffffff
} xpum_standby_type_t;

typedef enum xpum_standby_mode_t {
    XPUM_DEFAULT = 0,
    XPUM_NEVER = 1,
    XPUM_STANDBY_MODE_FORCE_UINT32 = 0x7fffffff
} xpum_standby_mode_t;

typedef struct xpum_power_sustained_limit_t {
    bool enabled;

    int32_t power;

    int32_t interval;
} xpum_power_sustained_limit_t;
typedef struct xpum_power_burst_limit_t {
    bool enabled;

    int32_t power;
} xpum_power_burst_limit_t;

typedef struct xpum_power_peak_limit_t {
    int32_t power_AC;

    int32_t power_DC;
} xpum_power_peak_limit_t;

typedef struct xpum_standby_data_t {
    xpum_standby_type_t type;
    bool on_subdevice;
    uint32_t subdevice_Id;
    xpum_standby_mode_t mode;
} xpum_standby_data_t;

typedef struct xpum_power_limits_t {
    xpum_power_sustained_limit_t sustained_limit;
} xpum_power_limits_t;

typedef enum xpum_frequency_type_t {
    XPUM_GPU_FREQUENCY = 0,
    XPUM_MEMORY_FREQUENCY = 1,
    XPUM_FORCE_UINT32 = 0x7fffffff
} xpum_frequency_type_t;

typedef enum xpum_scheduler_mode_t {
    XPUM_TIMEOUT = 0,
    XPUM_TIMESLICE = 1,
    XPUM_EXCLUSIVE = 2,
    XPUM_COMPUTE_UNIT_DEBUG = 3,
    XPUM_MODE_FORCE_UINT32 = 0x7fffffff
} xpum_scheduler_mode_t;

typedef enum xpum_ecc_state_t {
    XPUM_ECC_STATE_UNAVAILABLE = 0, ///< None
    XPUM_ECC_STATE_ENABLED = 1,     ///< ECC enabled.
    XPUM_ECC_STATE_DISABLED = 2,    ///< ECC disabled.
    XPUM_ECC_STATE_FORCE_UINT32 = 0x7fffffff

} xpum_ecc_state_t;

typedef enum xpum_ecc_action_t {
    XPUM_ECC_ACTION_NONE = 0,               ///< No action.
    XPUM_ECC_ACTION_WARM_CARD_RESET = 1,    ///< Warm reset of the card.
    XPUM_ECC_ACTION_COLD_CARD_RESET = 2,    ///< Cold reset of the card.
    XPUM_ECC_ACTION_COLD_SYSTEM_REBOOT = 3, ///< Cold reboot of the system.
    XPUM_ECC_ACTION_FORCE_UINT32 = 0x7fffffff

} xpum_ecc_action_t;

typedef struct xpum_device_performancefactor_t {
    bool on_subdevice;
    uint32_t subdevice_id;
    double factor;
    xpum_engine_type_flags_t engine;
} xpum_device_performancefactor_t;

typedef struct xpum_frequency_range_t {
    xpum_frequency_type_t type;
    uint32_t subdevice_Id;
    double min;
    double max;
    char freqOption[XPUM_MAX_STR_LENGTH];
} xpum_frequency_range_t;

typedef struct xpum_scheduler_data_t {
    bool on_subdevice;
    uint32_t subdevice_Id;
    bool can_control;
    xpum_scheduler_mode_t mode;
    xpum_engine_type_flags_t engine_types;
    xpum_scheduler_mode_t supported_modes;
    uint64_t val1;
    uint64_t val2;
} xpum_scheduler_data_t;

typedef struct xpum_power_prop_data_t {
    bool on_subdevice;
    uint32_t subdevice_Id;
    bool can_control;
    bool is_energy_threshold_supported;
    int32_t default_limit;
    int32_t min_limit;
    int32_t max_limit;
} xpum_power_prop_data_t;

typedef struct xpum_scheduler_timeout_t {
    uint32_t subdevice_Id;
    uint64_t watchdog_timeout;
} xpum_scheduler_timeout_t;

typedef struct xpum_scheduler_timeslice_t {
    uint32_t subdevice_Id;
    uint64_t interval;
    uint64_t yield_timeout;
} xpum_scheduler_timeslice_t;

typedef struct xpum_scheduler_exclusive_t {
    uint32_t subdevice_Id;
} xpum_scheduler_exclusive_t;

/**
 * @brief Statistics and metrics types
 *
 */
typedef enum xpum_stats_type_enum {
    XPUM_STATS_GPU_UTILIZATION = 0,                  ///< GPU Utilization
    XPUM_STATS_EU_ACTIVE,                            ///< GPU EU Array Active
    XPUM_STATS_EU_STALL,                             ///< GPU EU Array Stall
    XPUM_STATS_EU_IDLE,                              ///< GPU EU Array Idle
    XPUM_STATS_POWER,                                ///< Power
    XPUM_STATS_ENERGY,                               ///< Energy
    XPUM_STATS_GPU_FREQUENCY,                        ///< Gpu Actual Frequency
    XPUM_STATS_GPU_CORE_TEMPERATURE,                 ///< Gpu Temeperature
    XPUM_STATS_MEMORY_USED,                          ///< Memory Used
    XPUM_STATS_MEMORY_UTILIZATION,                   ///< Memory Utilization. Percent utilization is calculated by the equation: physical size - free size / physical size.
    XPUM_STATS_MEMORY_BANDWIDTH,                     ///< Memory Bandwidth
    XPUM_STATS_MEMORY_READ,                          ///< Memory Read
    XPUM_STATS_MEMORY_WRITE,                         ///< Memory Write
    XPUM_STATS_MEMORY_READ_THROUGHPUT,               ///< Memory read throughput
    XPUM_STATS_MEMORY_WRITE_THROUGHPUT,              ///< Memory write throughput
    XPUM_STATS_ENGINE_GROUP_COMPUTE_ALL_UTILIZATION, ///< Engine Group Compute All Utilization
    XPUM_STATS_ENGINE_GROUP_MEDIA_ALL_UTILIZATION,   ///< Engine Group Media All Utilization
    XPUM_STATS_ENGINE_GROUP_COPY_ALL_UTILIZATION,    ///< Engine Group Copy All Utilization
    XPUM_STATS_ENGINE_GROUP_RENDER_ALL_UTILIZATION,  ///< Engine Group Render All Utilization
    XPUM_STATS_ENGINE_GROUP_3D_ALL_UTILIZATION,      ///< Engine Group 3d All Utilization
    XPUM_STATS_RAS_ERROR_CAT_RESET,
    XPUM_STATS_RAS_ERROR_CAT_PROGRAMMING_ERRORS,
    XPUM_STATS_RAS_ERROR_CAT_DRIVER_ERRORS,
    XPUM_STATS_RAS_ERROR_CAT_CACHE_ERRORS_CORRECTABLE,
    XPUM_STATS_RAS_ERROR_CAT_CACHE_ERRORS_UNCORRECTABLE,
    XPUM_STATS_RAS_ERROR_CAT_DISPLAY_ERRORS_CORRECTABLE,
    XPUM_STATS_RAS_ERROR_CAT_DISPLAY_ERRORS_UNCORRECTABLE,
    XPUM_STATS_RAS_ERROR_CAT_NON_COMPUTE_ERRORS_CORRECTABLE,
    XPUM_STATS_RAS_ERROR_CAT_NON_COMPUTE_ERRORS_UNCORRECTABLE,
    XPUM_STATS_GPU_REQUEST_FREQUENCY, ///< Gpu Request Frequency
    XPUM_STATS_MEMORY_TEMPERATURE,    ///< Memory Temeperature
    XPUM_STATS_FREQUENCY_THROTTLE,    ///< Frequency Throttle time
    XPUM_STATS_PCIE_READ_THROUGHPUT,  ///< PCIe read throughput
    XPUM_STATS_PCIE_WRITE_THROUGHPUT, ///< PCIe write throughput
    XPUM_STATS_PCIE_READ,             ///< PCIe read
    XPUM_STATS_PCIE_WRITE,            ///< PCIe write
    XPUM_STATS_ENGINE_UTILIZATION,    ///< Engine Utilization
    XPUM_STATS_FABRIC_THROUGHPUT,     ///< Fabric throughput
    XPUM_STATS_FREQUENCY_THROTTLE_REASON_GPU,    ///< Frequency Throttle reason
    XPUM_STATS_MAX
} xpum_stats_type_t;

typedef xpum_stats_type_t xpum_realtime_metric_type_t;

/**
 * @brief Struct to store realtime data for different metric types
 *
 */
typedef struct xpum_device_realtime_metric_t {
    xpum_realtime_metric_type_t metricsType;  ///< Metric type
    bool isCounter;                           ///< If this metric is a counter
    uint64_t value;                           ///< The value of this metric type
    uint32_t scale;                           ///< The magnification of the value
} xpum_device_realtime_metric_t;

/**
 * @brief Struct to store device realtime datas
 *
 */
typedef struct xpum_device_realtime_metrics_t {
    xpum_device_id_t deviceId; ///< Device id
    bool isTileData;           ///< If this statistics data is tile level
    int32_t tileId;            ///< The tile id, only valid if isTileData is true
    int32_t count;             ///< The count of data stored in dataList array
    xpum_device_realtime_metric_t dataList[XPUM_STATS_MAX];
} xpum_device_realtime_metrics_t;

/**
 * @brief Engine types
 *
 */
typedef enum xpum_engine_type_enum {
    XPUM_ENGINE_TYPE_COMPUTE,
    XPUM_ENGINE_TYPE_RENDER,
    XPUM_ENGINE_TYPE_DECODE,
    XPUM_ENGINE_TYPE_ENCODE,
    XPUM_ENGINE_TYPE_COPY,
    XPUM_ENGINE_TYPE_MEDIA_ENHANCEMENT,
    XPUM_ENGINE_TYPE_3D,
    XPUM_ENGINE_TYPE_UNKNOWN,
} xpum_engine_type_t;

/**
 * @brief Struct to store device engine realtime data
 * 
 */
typedef struct xpum_device_realtime_engine_data_t {
    bool isTileData;           ///< If this statistics data is tile level
    int32_t tileId;            ///< The tile id, only valid if isTileData is true
    uint64_t index;            ///< The index of the engine in the same type on the device or sub-device
    xpum_engine_type_t type;   ///< The type of the engine
    uint64_t value;            ///< The value of engine utilization
    uint64_t min;              ///< The min value since last call
    uint64_t avg;              ///< The average value since last call
    uint64_t max;              ///< The max value since last call
    uint32_t scale;            ///< The magnification of the value, accumulated, min, avg, and max fields
    xpum_device_id_t deviceId; ///< Device id
} xpum_device_realtime_engine_data_t;

/**
 * @brief Struct to store device engine metric data
 *
 */
typedef struct xpum_device_engine_metric_t {
    bool isTileData;         ///< If this statistics data is tile level
    int32_t tileId;          ///< The tile id, only valid if isTileData is true
    uint64_t index;          ///< The index of the engine in the same type on the device or sub-device
    xpum_engine_type_t type; ///< The type of the engine
    uint64_t value;          ///< The value of engine utilization
    uint32_t scale;          ///< The magnification of the value field
} xpum_device_engine_metric_t;

typedef struct {
    int amcIndex;                         ///< Device index
    double value;                         ///< Sensor reading value
    double sensorLow;                     ///< Sensor low bound
    double sensorHigh;                    ///< Sensor high bound
    char sensorName[XPUM_MAX_STR_LENGTH]; ///< Sensor name
    char sensorUnit[XPUM_MAX_STR_LENGTH]; ///< Sensor reading unit
} xpum_sensor_reading_t;

typedef enum xpum_dump_type_enum {
    XPUM_DUMP_GPU_UTILIZATION,
    XPUM_DUMP_POWER,
    XPUM_DUMP_GPU_FREQUENCY,
    XPUM_DUMP_GPU_CORE_TEMPERATURE,
    XPUM_DUMP_MEMORY_TEMPERATURE,
    XPUM_DUMP_MEMORY_UTILIZATION,
    XPUM_DUMP_MEMORY_READ_THROUGHPUT,
    XPUM_DUMP_MEMORY_WRITE_THROUGHPUT,
    XPUM_DUMP_ENERGY,
    XPUM_DUMP_EU_ACTIVE,
    XPUM_DUMP_EU_STALL,
    XPUM_DUMP_EU_IDLE,
    XPUM_DUMP_RAS_ERROR_CAT_RESET,
    XPUM_DUMP_RAS_ERROR_CAT_PROGRAMMING_ERRORS,
    XPUM_DUMP_RAS_ERROR_CAT_DRIVER_ERRORS,
    XPUM_DUMP_RAS_ERROR_CAT_CACHE_ERRORS_CORRECTABLE,
    XPUM_DUMP_RAS_ERROR_CAT_CACHE_ERRORS_UNCORRECTABLE,
    XPUM_DUMP_MEMORY_BANDWIDTH,
    XPUM_DUMP_MEMORY_USED,
    XPUM_DUMP_PCIE_READ_THROUGHPUT,
    XPUM_DUMP_PCIE_WRITE_THROUGHPUT,
    XPUM_DUMP_COMPUTE_XE_LINK_THROUGHPUT,
    XPUM_DUMP_COMPUTE_ENGINE_UTILIZATION,
    XPUM_DUMP_RENDER_ENGINE_UTILIZATION,
    XPUM_DUMP_DECODE_ENGINE_UTILIZATION,
    XPUM_DUMP_ENCODE_ENGINE_UTILIZATION,
    XPUM_DUMP_COPY_ENGINE_UTILIZATION,
    XPUM_DUMP_MEDIA_ENHANCEMENT_ENGINE_UTILIZATION,
    XPUM_DUMP_3D_ENGINE_UTILIZATION,
    XPUM_DUMP_RAS_ERROR_CAT_NON_COMPUTE_ERRORS_CORRECTABLE,
    XPUM_DUMP_RAS_ERROR_CAT_NON_COMPUTE_ERRORS_UNCORRECTABLE,
    XPUM_DUMP_COMPUTE_ENGINE_GROUP_UTILIZATION,
    XPUM_DUMP_RENDER_ENGINE_GROUP_UTILIZATION,
    XPUM_DUMP_MEDIA_ENGINE_GROUP_UTILIZATION,
    XPUM_DUMP_COPY_ENGINE_GROUP_UTILIZATION,
    XPUM_DUMP_FREQUENCY_THROTTLE_REASON_GPU,
    XPUM_DUMP_MAX
} xpum_dump_type_t;
} // extern "C"
} // end namespace xpum

#endif // _XPUM_STRUCTS_H