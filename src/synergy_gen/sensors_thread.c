/* generated thread source file - do not edit */
#include "sensors_thread.h"

TX_THREAD sensors_thread;
void sensors_thread_create(void);
static void sensors_thread_func(ULONG thread_input);
static uint8_t sensors_thread_stack[1024] BSP_PLACE_IN_SECTION_V2(".stack.sensors_thread") BSP_ALIGN_VARIABLE_V2(BSP_STACK_ALIGNMENT);
void tx_startup_err_callback(void *p_instance, void *p_data);
void tx_startup_common_init(void);
#if (5) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_external_irq5) && !defined(SSP_SUPPRESS_ISR_ICU5)
SSP_VECTOR_DEFINE( icu_irq_isr, ICU, IRQ5);
#endif
#endif
static icu_instance_ctrl_t g_external_irq5_ctrl;
static const external_irq_cfg_t g_external_irq5_cfg =
{ .channel = 5,
  .trigger = EXTERNAL_IRQ_TRIG_RISING,
  .filter_enable = true,
  .pclk_div = EXTERNAL_IRQ_PCLK_DIV_BY_64,
  .autostart = true,
  .p_callback = irq_410_callback,
  .p_context = &g_external_irq5,
  .p_extend = NULL,
  .irq_ipl = (5), };
/* Instance structure to use this module. */
const external_irq_instance_t g_external_irq5 =
{ .p_ctrl = &g_external_irq5_ctrl, .p_cfg = &g_external_irq5_cfg, .p_api = &g_external_irq_on_icu };
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_timer9) && !defined(SSP_SUPPRESS_ISR_GPT9)
SSP_VECTOR_DEFINE_CHAN(gpt_counter_overflow_isr, GPT, COUNTER_OVERFLOW, 9);
#endif
#endif
static gpt_instance_ctrl_t g_timer9_ctrl;
static const timer_on_gpt_cfg_t g_timer9_extend =
{ .gtioca =
{ .output_enabled = true, .stop_level = GPT_PIN_LEVEL_LOW },
  .gtiocb =
  { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW } };
static const timer_cfg_t g_timer9_cfg =
{ .mode = TIMER_MODE_PWM, .period = 1, .unit = TIMER_UNIT_FREQUENCY_KHZ, .duty_cycle = 50000, .duty_cycle_unit =
          TIMER_PWM_UNIT_PERCENT_X_1000,
  .channel = 9, .autostart = true, .p_callback = NULL, .p_context = &g_timer9, .p_extend = &g_timer9_extend, .irq_ipl =
          (BSP_IRQ_DISABLED), };
/* Instance structure to use this module. */
const timer_instance_t g_timer9 =
{ .p_ctrl = &g_timer9_ctrl, .p_cfg = &g_timer9_cfg, .p_api = &g_timer_on_gpt };
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_adc0) && !defined(SSP_SUPPRESS_ISR_ADC0)
SSP_VECTOR_DEFINE_CHAN(adc_scan_end_isr, ADC, SCAN_END, 0);
#endif
#endif
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_adc0) && !defined(SSP_SUPPRESS_ISR_ADC0)
SSP_VECTOR_DEFINE_CHAN(adc_scan_end_b_isr, ADC, SCAN_END_B, 0);
#endif
#endif
adc_instance_ctrl_t g_adc0_ctrl;
const adc_cfg_t g_adc0_cfg =
{ .unit = 0,
  .mode = ADC_MODE_CONTINUOUS_SCAN,
  .resolution = ADC_RESOLUTION_12_BIT,
  .alignment = ADC_ALIGNMENT_RIGHT,
  .add_average_count = ADC_ADD_OFF,
  .clearing = ADC_CLEAR_AFTER_READ_ON,
  .trigger = ADC_TRIGGER_SOFTWARE,
  .trigger_group_b = ADC_TRIGGER_SYNC_ELC,
  .p_callback = NULL,
  .p_context = &g_adc0,
  .scan_end_ipl = (BSP_IRQ_DISABLED),
  .scan_end_b_ipl = (BSP_IRQ_DISABLED),
  .calib_adc_skip = false, };
const adc_channel_cfg_t g_adc0_channel_cfg =
{ .scan_mask = (uint32_t) (
        ((uint64_t) ADC_MASK_CHANNEL_0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                | (0)),
  /** Group B channel mask is right shifted by 32 at the end to form the proper mask */
  .scan_mask_group_b = (uint32_t) (
          (((uint64_t) ADC_MASK_CHANNEL_0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                  | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                  | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                  | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                  | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                  | (0)) >> 32),
  .priority_group_a = ADC_GROUP_A_PRIORITY_OFF, .add_mask = (uint32_t) (
          (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0)
                  | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0)),
  .sample_hold_mask = (uint32_t) ((0) | (0) | (0)), .sample_hold_states = 24, };
/* Instance structure to use this module. */
const adc_instance_t g_adc0 =
{ .p_ctrl = &g_adc0_ctrl, .p_cfg = &g_adc0_cfg, .p_channel_cfg = &g_adc0_channel_cfg, .p_api = &g_adc_on_adc };
TX_QUEUE g_values_queue;
static uint8_t queue_memory_g_values_queue[16];
extern bool g_ssp_common_initialized;
extern uint32_t g_ssp_common_thread_count;
extern TX_SEMAPHORE g_ssp_common_initialized_semaphore;

void sensors_thread_create(void)
{
    /* Increment count so we will know the number of ISDE created threads. */
    g_ssp_common_thread_count++;

    /* Initialize each kernel object. */
    UINT err_g_values_queue;
    err_g_values_queue = tx_queue_create (&g_values_queue, (CHAR *) "Values Queue", 4, &queue_memory_g_values_queue,
                                          sizeof(queue_memory_g_values_queue));
    if (TX_SUCCESS != err_g_values_queue)
    {
        tx_startup_err_callback (&g_values_queue, 0);
    }

    UINT err;
    err = tx_thread_create (&sensors_thread, (CHAR *) "Sensors Thread", sensors_thread_func, (ULONG) NULL,
                            &sensors_thread_stack, 1024, 5, 5, 10, TX_AUTO_START);
    if (TX_SUCCESS != err)
    {
        tx_startup_err_callback (&sensors_thread, 0);
    }
}

static void sensors_thread_func(ULONG thread_input)
{
    /* Not currently using thread_input. */
    SSP_PARAMETER_NOT_USED (thread_input);

    /* Initialize common components */
    tx_startup_common_init ();

    /* Initialize each module instance. */

    /* Enter user code for this thread. */
    sensors_thread_entry ();
}
