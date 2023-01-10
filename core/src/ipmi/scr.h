/*
 *  Copyright (C) 2021-2022 Intel Corporation
 *
 *  Intel Simplified Software License (Version August 2021)
 *
 *  Use and Redistribution.  You may use and redistribute the software (the “Software”), without modification, provided the following conditions are met:
 *
 *  * Redistributions must reproduce the above copyright notice and the
 *    following terms of use in the Software and in the documentation and/or other materials provided with the distribution.
 *  * Neither the name of Intel nor the names of its suppliers may be used to
 *    endorse or promote products derived from this Software without specific
 *    prior written permission.
 *  * No reverse engineering, decompilation, or disassembly of this Software
 *    is permitted.
 *
 *  No other licenses.  Except as provided in the preceding section, Intel grants no licenses or other rights by implication, estoppel or otherwise to, patent, copyright, trademark, trade name, service mark or other intellectual property licenses or rights of Intel.
 *
 *  Third party software.  The Software may contain Third Party Software. “Third Party Software” is open source software, third party software, or other Intel software that may be identified in the Software itself or in the files (if any) listed in the “third-party-software.txt” or similarly named text file included with the Software. Third Party Software, even if included with the distribution of the Software, may be governed by separate license terms, including without limitation, open source software license terms, third party software license terms, and other Intel software license terms. Those separate license terms solely govern your use of the Third Party Software, and nothing in this license limits any rights under, or grants rights that supersede, the terms of the applicable license terms.
 *
 *  DISCLAIMER.  THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT ARE DISCLAIMED. THIS SOFTWARE IS NOT INTENDED FOR USE IN SYSTEMS OR APPLICATIONS WHERE FAILURE OF THE SOFTWARE MAY CAUSE PERSONAL INJURY OR DEATH AND YOU AGREE THAT YOU ARE FULLY RESPONSIBLE FOR ANY CLAIMS, COSTS, DAMAGES, EXPENSES, AND ATTORNEYS’ FEES ARISING OUT OF ANY SUCH USE, EVEN IF ANY CLAIM ALLEGES THAT INTEL WAS NEGLIGENT REGARDING THE DESIGN OR MANUFACTURE OF THE SOFTWARE.
 *
 *  LIMITATION OF LIABILITY. IN NO EVENT WILL INTEL BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  No support.  Intel may make changes to the Software, at any time without notice, and is not obligated to support, update or provide training for the Software.
 *
 *  Termination. Your right to use the Software is terminated in the event of your breach of this license.
 *
 *  Feedback.  Should you provide Intel with comments, modifications, corrections, enhancements or other input (“Feedback”) related to the Software, Intel will be free to use, disclose, reproduce, license or otherwise distribute or exploit the Feedback in its sole discretion without any obligations or restrictions of any kind, including without limitation, intellectual property rights or licensing obligations.
 *
 *  Compliance with laws.  You agree to comply with all relevant laws and regulations governing your use, transfer, import or export (or prohibition thereof) of the Software.
 *
 *  Governing law.  All disputes will be governed by the laws of the United States of America and the State of Delaware without reference to conflict of law principles and subject to the exclusive jurisdiction of the state or federal courts sitting in the State of Delaware, and each party agrees that it submits to the personal jurisdiction and venue of those courts and waives any objections. The United Nations Convention on Contracts for the International Sale of Goods (1980) is specifically excluded and will not apply to the Software.
 *
 *  @file scr.h
 */

#pragma once
#include "tool.h"

namespace xpum {

#define SCR_NUM_ICG_ICLS 8
#define SCR_NUM_NORTH_ICG_ICLS SCR_NUM_ICG_ICLS
#define SCR_NUM_SOUTH_ICG_ICLS SCR_NUM_ICG_ICLS
#define SCR_ICG_NORTH_NUMBER 0
#define SCR_ICG_SOUTH_NUMBER 1
#define SCR_TOTAL_NUM_ICLS (SCR_NUM_NORTH_ICG_ICLS + SCR_NUM_SOUTH_ICG_ICLS)
#define SCR_TOTAL_NUM_PGS 2
#define SCR_NHT_TABLE_ENTRIES 1024
#define SCR_ICC_ROUTE_SIZE (3 * sizeof(uint32_t) + 2 * sizeof(uint8_t))
#define SCR_ICLS_PER_PEER 4
#define SCR_NORTH_DISCOVERY_NODE_ID_OFFSET 64
#define SCR_SOUTH_DISCOVERY_NODE_ID_OFFSET 128

extern struct nrv_portgroup scr_pgs[SCR_TOTAL_NUM_PGS];

int scr_net_set_routes(ipmi_address_t *ipmi_address, int self, unsigned portgroup, int num_nodes,
                       uint64_t *port_masks, uint16_t *valid, enum nervana_routing_patterns mc,
                       enum nervana_virtual_channels vc);
int scr_net_get_neighbourhood(ipmi_address_t *ipmi_address, int *nodes);
int scr_get_board_portgroups(void **pgs, int *num_pgs);
unsigned long long scr_get_default_port_enable(uint8_t board_sku);
int scr_csmc_send_recv(ipmi_address_t *ipmi_address,
                       void *send_buf, uint16_t send_len,
                       void *recv_buf, uint16_t *recv_len);
int scr_csmc_send_msg(ipmi_address_t *ipmi_address, char *data_buf, uint16_t send_len);
void scr_clear_nht_table(void);
int net_get_nht_entries(uint32_t num_nodes, uint32_t idx, uint64_t port_masks, uint16_t valid,
                        enum nervana_routing_patterns mc, unsigned portgroup,
                        enum nervana_virtual_channels vc);
} // namespace xpum