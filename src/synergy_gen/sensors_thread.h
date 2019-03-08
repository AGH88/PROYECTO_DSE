/* generated thread header file - do not edit */
#ifndef SENSORS_THREAD_H_
#define SENSORS_THREAD_H_
#include "bsp_api.h"
#include "tx_api.h"
#include "hal_data.h"
#ifdef __cplusplus 
extern "C" void sensors_thread_entry(void);
#else 
extern void sensors_thread_entry(void);
#endif
#include "r_icu.h"
#include "r_external_irq_api.h"
#include "r_gpt.h"
#include "r_timer_api.h"
#include "r_adc.h"
#include "r_adc_api.h"
#ifdef __cplusplus
extern "C"
{
#endif
/* External IRQ on ICU Instance. */
extern const external_irq_instance_t g_external_irq5;
#ifndef irq_410_callback
void irq_410_callback(external_irq_callback_args_t *p_args);
#endif
/** Timer on GPT Instance. */
extern const timer_instance_t g_timer9;
#ifndef NULL
void NULL(timer_callback_args_t *p_args);
#endif
/** ADC on ADC Instance. */
extern const adc_instance_t g_adc0;
#ifndef NULL
void NULL(adc_callback_args_t *p_args);
#endif
extern TX_QUEUE g_values_queue;
#ifdef __cplusplus
} /* extern "C" */
#endif
#endif /* SENSORS_THREAD_H_ */
