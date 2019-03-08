#include "gui/guiapp_resources.h"
#include "gui/guiapp_specifications.h"
#include "main_thread.h"
#include "sensors_thread.h"

#define APP_TIMER_ID        (101)
#define APP_TIMER_PERIOD    (30)

ULONG my_rcv_message[4] = {0x00, 0x00, 0x00};

static void update_counter(GX_WIDGET * p_widget, GX_RESOURCE_ID id, GX_RESOURCE_ID dutc);

UINT window1_handler(GX_WINDOW *widget, GX_EVENT *event_ptr)
{
    UINT result = gx_window_event_process(widget, event_ptr);

    tx_queue_receive(&g_values_queue, my_rcv_message, 20);

    switch (event_ptr->gx_event_type)
    {
    case GX_EVENT_SHOW:
        gx_system_timer_start(widget, APP_TIMER_ID, APP_TIMER_PERIOD,
                              APP_TIMER_PERIOD);
    break;
    case GX_EVENT_TIMER:
        if (APP_TIMER_ID == event_ptr->gx_event_payload.gx_event_timer_id)
        {
            update_counter(widget->gx_widget_parent, ID_RESP3, ID_RESP1);
        }
    break;
    }

    return result;
}

static void update_counter(GX_WIDGET * p_widget, GX_RESOURCE_ID setp, GX_RESOURCE_ID dutc)
{

    GX_PROMPT * p_prompt = NULL;

    static GX_CHAR txt_buffer[5];
    static GX_CHAR dut_buffer[4];
    static GX_CHAR speed_buffer[5];

    ssp_err_t err = gx_widget_find(p_widget, ID_RESP3, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET**)&p_prompt);
    if (TX_SUCCESS == err)
    {
        gx_utility_ltoa((LONG) my_rcv_message[1], txt_buffer, 5);

        err = gx_prompt_text_set(p_prompt, txt_buffer);
        if (err)
            while (1);
    }

    err = gx_widget_find(p_widget, ID_RESP1, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET**)&p_prompt);
    if (TX_SUCCESS == err)
    {
        gx_utility_ltoa((LONG) my_rcv_message[2], dut_buffer, 4);

        err = gx_prompt_text_set(p_prompt, dut_buffer);
        if (err)
            while (1);
    }

    err = gx_widget_find(p_widget, ID_RESP2, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET**)&p_prompt);
    if (TX_SUCCESS == err)
    {
        gx_utility_ltoa((LONG) my_rcv_message[0], speed_buffer, 5);

        err = gx_prompt_text_set(p_prompt, speed_buffer);
        if (err)
            while (1);
    }
}
