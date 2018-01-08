#ifndef USB_DESC_H_
#define USB_DESC_H_

#include <stdint.h>

#ifndef SWAPBYTE
#define SWAPBYTE(addr) (((uint16_t)(*((uint8_t *)(addr)))) + \
                       (((uint16_t)(*(((uint8_t *)(addr)) + 1))) << 8))
#endif

#ifndef LOBYTE
#define LOBYTE(x)  ((uint8_t)(x & 0x00FF))
#endif

#ifndef HIBYTE
#define HIBYTE(x)  ((uint8_t)((x & 0xFF00) >>8))
#endif

#ifndef MIN
#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
#endif

#ifndef MAX
#define MAX(a, b)  (((a) > (b)) ? (a) : (b))
#endif

/*------------------------------------------------------------------------------*/
/*  General descriptors                                                         */
/*------------------------------------------------------------------------------*/

#define USBD_NUM_CONFIGS                1
#define USBD_NUM_INTERFACES             4
#define USBD_CFG_SIZE                   171

#define USB_DEVICE_DESC_TYPE            1
#define USB_CONFIG_DESC_TYPE            2
#define USB_STRING_DESC_TYPE            3
#define USB_INTERFACE_DESC_TYPE         4
#define USB_ENDPOINT_DESC_TYPE          5
#define USB_DEVICE_QUALIFIER_DESC_TYPE  6
#define USB_LANGID_DESC_TYPE            USB_STRING_DESC_TYPE
#define USB_IAD_DESC_TYPE               11
#define USB_BOS_DESC_TYPE               15
#define USB_CS_INTERFACE_TYPE           0x24
#define USB_CS_ENDPOINT_TYPE            0x25

#define USB_DEVICE_DESC_SIZE            18
#define USB_CONFIG_DESC_SIZE            9
#define USB_INTERFACE_DESC_SIZE         9
#define USB_ENDPOINT_DESC_SIZE          7
#define USB_LANGID_DESC_SIZE            4
#define USB_IAD_DESC_SIZE               8

#define USBD_IDX_LANGID_STR             0
#define USBD_IDX_MFC_STR                1
#define USBD_IDX_PRODUCT_STR            2
#define USBD_IDX_SERIAL_STR             3
#define USBD_IDX_CONFIG_STR             4
#define USBD_IDX_MIDI_IF_STR            5
#define USBD_IDX_CDC_IF_STR             6

#define USB_LANGID_ENG_US               0x0409

#define USB_CONFIG_REMOTE_WAKEUP        0x02
#define USB_CONFIG_SELF_POWERED         0x01

#define USB_FEATURE_EP_HALT             0
#define USB_FEATURE_REMOTE_WAKEUP       1
#define USB_FEATURE_TEST_MODE           2

/*------------------------------------------------------------------------------*/
/*  MIDI Interface                                                              */
/*------------------------------------------------------------------------------*/

#define USBD_MIDI_CS_IF_DESC_TYPE       USB_CS_INTERFACE_TYPE
#define USBD_MIDI_CS_EP_DESC_TYPE       USB_CS_ENDPOINT_TYPE

#define USBD_MIDI_CONTROL_SIZE          9
#define USBD_MIDI_STREAM_SIZE           7
#define USBD_MIDI_JACK_IN_SIZE          6
#define USBD_MIDI_JACK_OUT_SIZE         9
#define USBD_MIDI_ENDPOINT_SIZE         5

#define USBD_MIDI_IN_JACK               0x02
#define USBD_MIDI_OUT_JACK              0x03

#define USBD_MIDI_JACK_EMBEDDED         0x01
#define USBD_MIDI_JACK_EXTERNAL         0x02

/*------------------------------------------------------------------------------*/
/*  CDC Interface                                                               */
/*------------------------------------------------------------------------------*/

#define USBD_CDC_CS_IF_DESC_TYPE        USB_CS_INTERFACE_TYPE

#define USBD_CDC_HEADER_SIZE            5
#define USBD_CDC_ACM_SIZE               4
#define USBD_CDC_UNION_SIZE             5
#define USBD_CDC_CALL_MAN_SIZE          5

#define USBD_CDC_HEADER_SUBTYPE         0x00
#define USBD_CDC_ACM_SUBTYPE            0x02
#define USBD_CDC_UNION_SUBTYPE          0x06
#define USBD_CDC_CALL_MAN_SUBTYPE       0x01

#define CDC_SET_LINE_CODING             0x20
#define CDC_GET_LINE_CODING             0x21

/*------------------------------------------------------------------------------*/
/*  Functions                                                                   */
/*------------------------------------------------------------------------------*/

uint8_t *usbd_get_dev_desc(uint16_t *length);
uint8_t *usbd_hjalmar_dev_qualifier_desc(uint16_t *length);
uint8_t *usbd_get_cfg_desc(uint8_t cfg_no, uint16_t *length);
uint8_t *usbd_get_langid_str(uint16_t *length);
uint8_t *usbd_get_mfc_str(uint16_t *length);
uint8_t *usbd_get_prod_str(uint16_t *length);
uint8_t *usbd_get_serial_str(uint16_t *length);
uint8_t *usbd_get_cfg_str(uint16_t *length);
uint8_t *usbd_get_midi_if_str(uint16_t *length);
uint8_t *usbd_get_cdc_if_str(uint16_t *length);

#endif /* USB_DESC_H_ */