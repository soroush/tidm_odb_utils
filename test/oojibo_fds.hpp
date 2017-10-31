// Interface Header Oojibo v1.5 
// Creation Date: 9 June 2015
// OMS Data Schema v1.5(2nd June, 2015)
//
// STL vector containers (use option -s to disable)
#import "stlvector.h"

struct ns2__msg_response
{
    uint64_t tx_id;
    uint16_t tx_type;
    double risk;
    int action;
    int return_code;
};


/* ---------------
 * Registeration
 * ---------------
 */
struct ns2__reg_agent_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;//
    /*transaction type*/
    uint16_t tx_type;//
    /*hypertag unique id*/
    uint64_t hypertag_id;//
    /*issuing bank code*/
    uint32_t bank_code;//
    /*agent that signup this customer*/
    std::string agent_code;//
    /*customer information file id*/
    uint64_t cif_id;
    /*hashed account id*/
    std::string acc_id;
    /**account type*/
    uint8_t acc_type;
    /*mobile network operator*/
    std::string net_operator;
    /*phone number*/
    uint64_t phone;
    /*home currency ISO code*/
    uint16_t home_currency;
    /*home country ISO code*/
    std::string home_country;
    /*home province name*/
    std::string home_province;
    /*home region name*/
    std::string home_region;
    /*home city name*/
    std::string home_city;
    /*home city name*/
    std::string home_township;
    /*date of birth*/
    std::string date_birth;
    /*identification document type*/
    uint8_t id_type;
    /*identification document number*/
    std::string id_no;
    /*gender*/
    std::string gender;
    /*occupation group*/
    uint8_t occupation;
    /*home bank branch*/
    std::string home_branch;
    /*service plan code*/
    std::string service_plan;
    /*signup location*/
    std::string signup_loc;
    /*signup Date/Time*/
    std::string signup_date;
    /*master agent code*/
    std::string magent_code;
    /*hashed funder account id*/
    std::string funder_acct_id;
};

int ns2__register_agent(struct ns2__reg_agent_obj msg, struct ns2__msg_response& m);

struct ns2__reg_customer_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;//
    /*transaction type*/
    uint16_t tx_type;//
    /*hypertag unique id*/
    uint64_t hypertag_id;//
    /*issuing bank code*/
    uint32_t bank_code;//
    /*customer information file id*/
    uint64_t cif_id;
    /*hashed account id*/
    std::string acc_id;
    /**account type*/
    uint8_t acc_type;
    /*mobile network operator*/
    std::string net_operator;
    /*phone number*/
    uint64_t phone;
    /*home currency ISO code*/
    uint16_t home_currency;
    /*home country ISO code*/
    std::string home_country;
    /*home province name*/
    std::string home_province;
    /*home region name*/
    std::string home_region;
    /*home city name*/
    std::string home_city;
    /*home city name*/
    std::string home_township;
    /*date of birth*/
    std::string date_birth;
    /*identification document type*/
    uint8_t id_type;
    /*identification document number*/
    std::string id_no;
    /*gender*/
    std::string gender;
    /*occupation group*/
    uint8_t occupation;
    /*home bank branch*/
    std::string home_branch;
    /*service plan code*/
    std::string service_plan;
    /*signup location*/
    std::string signup_loc;
    /*signup Date/Time*/
    std::string signup_date;
    /*agent code*/
    std::string agent_code;
    /*Initial Deposit*/
    uint64_t initial_deposit;
};
int ns2__register_customer(struct ns2__reg_customer_obj msg, struct ns2__msg_response& m);


struct ns2__reg_merchant_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;//
    /*transaction type*/
    uint16_t tx_type;//
    /*hypertag unique id*/
    uint64_t hypertag_id;//
    /*issuing bank code*/
    uint32_t bank_code;//
    /*merchant code*/
    std::string mrch_code;
    /*merchant category code*/
    std::string mrch_category;
    /*merchant type*/
    uint8_t mrch_type;
    /*business start date*/
    std::string business_start_date;
    /*mobile network operator*/
    std::string net_operator;
    /*phone number*/
    uint64_t phone;
    /*home currency ISO code*/
    uint16_t home_currency;
    /*home country ISO code*/
    std::string home_country;
    /*home province name*/
    std::string home_province;
    /*home region name*/
    std::string home_region;
    /*home city name*/
    std::string home_city;
    /*home city name*/
    std::string home_township;
    /*service plan code*/
    std::string service_plan;
    /*signup location*/
    std::string signup_loc;
    /*signup Date/Time*/
    std::string signup_date;
    /*agent code that signup this merchant*/
    std::string agent_code;
};

int ns2__register_merchant(struct ns2__reg_merchant_obj msg, struct ns2__msg_response& m);

/* ---------------
 * Account Service 
 * ---------------
 */
struct ns2__acnt_change_pin_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*issuing bank code*/
    uint32_t bank_code;
    /*hashed account id*/
    std::string acc_id;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction location*/
    std::string tx_location;
};
int ns2__account_service_change_pin(struct ns2__acnt_change_pin_obj msg, struct ns2__msg_response& m);

struct ns2__acnt_change_mobile_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*issuing bank code*/
    uint32_t bank_code;
    /*hashed account id*/
    std::string acc_id;
    /*old mobile number- for change mobile num*/
    uint64_t old_mobile;
    /*new mobile number- for change mobile num*/
    uint64_t new_mobile;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction location*/
    std::string tx_location;
};
int ns2__account_service_change_mobile(struct ns2__acnt_change_mobile_obj msg, struct ns2__msg_response& m);


struct ns2__acnt_update_dtl_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*issuing bank code*/
    uint32_t bank_code;
    /*agent code */
    std::string agent_code;
    /*merchant code*/
    std::string mrch_code;
    /*customer information file id*/
    uint64_t cif_id;
    /*hashed account id*/
    std::string acc_id;
    /*home country ISO code*/
    std::string home_country;
    /*home province name*/
    std::string home_province;
    /*home region name*/
    std::string home_region;
    /*home city name*/
    std::string home_city;
    /*home city name*/
    std::string home_township;
    /*identification document type-- for update details*/
    uint8_t id_type;
    /*identification document number-- for update details*/
    std::string id_no;
    /*gender-- for update details*/
    std::string gender;
    /*occupation group-- for update details*/
    uint8_t occupation;
    /*home bank branch-- for update details */
    std::string home_branch;
    /*transaction date/time*/
    std::string tx_date;
};
int ns2__account_service_update_dtl(struct ns2__acnt_update_dtl_obj msg, struct ns2__msg_response& m);

struct ns2__acnt_link_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*issuing bank code*/
    uint32_t bank_code;
    /*customer information file id*/
    uint64_t cif_id;
    /*hashed account id*/
    std::string acc_id;
    /*CASA acc type-- for link/unlink CASA*/
    uint8_t casa_acc_type;
    /*CASA acc id--for link/unlink CASA */
    std::string casa_acc_id;
    /*CASA acc currency -- for link/unlink CASA*/
    uint16_t casa_acc_currency;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction branch*/
    std::string tx_branch;
};
int ns2__account_service_link(struct ns2__acnt_link_obj msg, struct ns2__msg_response& m);

struct ns2__acnt_change_plan_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*issuing bank code*/
    uint32_t bank_code;
    /*hashed account id*/
    std::string acc_id;
    /*old service plan code-- for change plan*/
    std::string old_plan;
    /*new service plan code-- for change plan*/
    std::string new_plan;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction branch*/
    std::string tx_branch;
    /*transaction location*/
    std::string tx_location;
};
int ns2__account_service_change_plan(struct ns2__acnt_change_plan_obj msg, struct ns2__msg_response& m);


struct ns2__acnt_change_level_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*issuing bank code*/
    uint32_t bank_code;
    /*hashed account id*/
    std::string acc_id;
    /*old service level -- for change level*/
    uint8_t old_level;
    /*new service level -- for change level*/
    uint8_t new_level;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction branch*/
    std::string tx_branch;
    /*transaction location*/
    std::string tx_location;
};
int ns2__account_service_change_level(struct ns2__acnt_change_level_obj msg, struct ns2__msg_response& m);

struct ns2__acnt_reset_pin_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*issuing bank code*/
    uint32_t bank_code;
    /*hashed account id*/
    std::string acc_id;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction branch*/
    std::string tx_branch;
    /*transaction location*/
    std::string tx_location;
};
int ns2__account_service_reset_pin(struct ns2__acnt_reset_pin_obj msg, struct ns2__msg_response& m);


struct ns2__acnt_replace_ht_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*issuing bank code*/
    uint32_t bank_code;
    /*hashed account id*/
    std::string acc_id;
    /*new hypetag unique id*/
    std::string new_hypertag;
    /*reason*/
    std::string reason;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction branch*/
    std::string tx_branch;
};
int ns2__account_service_replace_ht(struct ns2__acnt_replace_ht_obj msg, struct ns2__msg_response& m);


struct ns2__acnt_block_obj
{
    /*Unique transaction id*/
    uint64_t tx_id;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*issuing bank code*/
    uint32_t bank_code;
    /*hashed account id*/
    std::string acc_id;
    /*reason*/
    std::string reason;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction branch*/
    std::string tx_branch;
};
int ns2__account_service_block(struct ns2__acnt_block_obj msg, struct ns2__msg_response& m);


struct ns2__acnt_status_obj
{
    /*Unique transaction id*/
    uint64_t tx_id;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*issuing bank code*/
    uint32_t bank_code;
    /*hashed account id*/
    std::string acc_id;
    /*reason*/
    std::string reason;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction branch*/
    std::string tx_branch;
};
int ns2__account_service_status(struct ns2__acnt_status_obj msg, struct ns2__msg_response& m);


struct ns2__acnt_funding_obj
{
    /*Unique transaction id*/
    uint64_t tx_id;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*issuing bank code*/
    uint32_t bank_code;
    /*hashed account id*/
    std::string acc_id;
    /*hashed funder account id*/
    std::string funder_acct_id;
    /*funding limit*/
    uint64_t funding_limit;
    /*warning level limit*/
    uint64_t warning_limit;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction branch*/
    std::string tx_branch;
};
int ns2__account_service_funding(struct ns2__acnt_funding_obj msg, struct ns2__msg_response& m);

struct ns2__acnt_info_obj
{
    /*Unique transaction id*/
    uint64_t tx_id;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*issuing bank code*/
    uint32_t bank_code;
    /*hashed account id*/
    std::string acc_id;
    /*recipient hashed account ID*/
    std::string recipient_acc_id;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction location*/
    std::string tx_location;
};
int ns2__account_service_info(struct ns2__acnt_info_obj msg, struct ns2__msg_response& m);


/* ---------------
 * Balance Inquery
 * ---------------
 */

struct ns2__inquery_balance_obj
{
    /*Unique transaction id*/
    uint64_t tx_id;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*issuing bank code*/
    uint32_t sender_bank_code;
    /*sender account id*/
    std::string sender_acc_id;
    /*sender account type*/
    uint8_t sender_acc_type;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction location*/
    std::string tx_location;
};
int ns2__inquery_balance(struct ns2__inquery_balance_obj msg, struct ns2__msg_response& m);


struct ns2__fund_transfer_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*sender bank code*/
    uint32_t bank_code;
    /*sender hashed account id*/
    std::string sender_acc_id;
    /*sender account type*/
    uint8_t sender_acc_type;
    /*recipien bank (SWIFT code)*/
    std::string recipient_bank;
    /*OMS recip ient bank code*/
    uint32_t oms_recipient_bank;
    /*recipient hashed account id*/
    std::string recipient_acc_id;
    /*recipient account type*/
    uint8_t recipient_acc_type;
    /*recipient phone num*/
    uint64_t recipient_phone;
    /*recipient name*/
    std::string recipient_name;
    /*transaction currency ISO code*/
    uint16_t tx_curr;
    /*transaction amount (local)*/
    uint64_t tx_amnt_local;
    /*transaction amount (foreign)*/
    uint64_t tx_amnt_foreign;
    /**source of income*/
    std::string income_src;
    /*relationship to the recipient*/
    std::string relationship;
    /*reason*/
    std::string reason;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction location*/
    std::string tx_location;
};

int ns2__fund_transfer(struct ns2__fund_transfer_obj msg, struct ns2__msg_response& m);


struct ns2__remittance_mobile_money_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*sender bank code*/
    uint32_t bank_code;
    /*sender hashed account id*/
    std::string sender_acc_id;
    /*sender account type*/
    uint8_t sender_acc_type;
    /*recipient phone num*/
    uint64_t recipient_phone;
    /*recipient ID number*/
    std::string recipient_id_number;
    /*transaction currency ISO code*/
    uint16_t tx_curr;
    /*transaction amount (local)*/
    uint64_t tx_amnt_local;
    /*transaction amount (foreign)*/
    uint64_t tx_amnt_foreign;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction location*/
    std::string tx_location;
    /*source of income*/
    std::string income_src;
    /*relationship to the recipient*/
    std::string relationship;
    /*reason*/
    std::string reason;
};
int ns2__remittance_mobile_money(struct ns2__remittance_mobile_money_obj msg, struct ns2__msg_response& m);



struct ns2__remittance_atm_cash_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*sender bank code*/
    uint32_t bank_code;
    /*sender hashed account id*/
    std::string sender_acc_id;
    /*sender account type*/
    uint8_t sender_acc_type;
    /*recipient phone num*/
    uint64_t recipient_phone;
    /*recipient ID number*/
    std::string recipient_id_number;
    /*transaction currency ISO code*/
    uint16_t tx_curr;
    /*transaction amount (local)*/
    uint64_t tx_amnt_local;
    /*transaction amount (foreign)*/
    uint64_t tx_amnt_foreign;
    /*transaction date/time*/
    std::string tx_date;
    /*source of income*/
    std::string income_src;
    /*relationship to the recipient*/
    std::string relationship;
    /*reason*/
    std::string reason;
};
int ns2__remittance_atm_cash(struct ns2__remittance_atm_cash_obj msg, struct ns2__msg_response& m);


struct ns2__remittance_reg_money_transfer_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*sender bank code*/
    uint32_t bank_code;
    /*sender hashed account id*/
    std::string sender_acc_id;
    /*sender account type*/
    uint8_t sender_acc_type;
    /*recipient bank*/
    std::string recipient_bank;
    /*recipient hashed account id*/
    std::string recipient_acc_id;
    /*recipient account type*/
    uint8_t recipient_acc_type;
    /*recipient phone num*/
    uint64_t recipient_phone;
    /*recipient name*/
    std::string recipient_name;
    /*recipient ID number*/
    std::string recipient_id_number;
    /*recipient branch*/
    std::string recipient_branch;
    /*reference number*/
    std::string ref_no;
    /*transaction currency ISO code*/
    uint16_t tx_curr;
    /*transaction amount (local)*/
    uint64_t tx_amnt_local;
    /*transaction amount (foreign)*/
    uint64_t tx_amnt_foreign;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction location*/
    std::string tx_location;
    /*source of income*/
    std::string income_src;
    /*relationship to the recipient*/
    std::string relationship;
    /*reason*/
    std::string reason;
};
int ns2__remittance_reg_money_transfer(struct ns2__remittance_reg_money_transfer_obj msg, struct ns2__msg_response& m);


struct ns2__cash_in_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*sender bank code*/
    uint32_t sender_bank_code;
    /*sender hashed account id*/
    std::string sender_acc_id;
    /*sender account type*/
    uint8_t sender_acc_type;
    /*agent code*/
    std::string agent_code;
    /*transaction currency ISO code*/
    uint16_t tx_curr;
    /*transaction amount (local)*/
    uint64_t tx_amnt_local;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction location*/
    std::string tx_location;
};
int ns2__cash_in(struct ns2__cash_in_obj msg, struct ns2__msg_response& m);

struct ns2__cash_in_3rd_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*agent bank code*/
    uint32_t agent_bank_code;
    /*agent hashed account ID*/
    std::string agent_acc_id;
    /*agent account type*/
    uint8_t agent_acc_type;
    /*recipient bank*/
    uint32_t recipient_bank;
    /*recipient account id*/
    std::string recipient_acc_id;
    /*recipient account type*/
    uint8_t recipient_acc_type;
    /*recipient ID number*/
    std::string recipient_id_number;
    /*transaction currency ISO code*/
    uint16_t tx_curr;
    /*transaction amount (local)*/
    uint64_t tx_amnt_local;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction location*/
    std::string tx_location;
};
int ns2__cash_in_3rd(struct ns2__cash_in_3rd_obj msg, struct ns2__msg_response& m);

struct ns2__cash_out_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*sender bank code*/
    uint32_t bank_code;
    /*sender hashed account id*/
    std::string sender_acc_id;
    /*sender account type*/
    uint8_t sender_acc_type;
    /*agent code*/
    std::string agent_code;
    /*transaction currency ISO code*/
    uint16_t tx_curr;
    /*transaction amount (local)*/
    uint64_t tx_amnt_local;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction location*/
    std::string tx_location;
};
int ns2__cash_out(struct ns2__cash_out_obj msg, struct ns2__msg_response& m);


struct ns2__cash_out_MAB_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*agent bank code*/
    uint32_t agent_bank_code;
    /*agent hashed account id*/
    std::string agent_acc_id;
    /*agent account type*/
    uint8_t agent_acc_type;
    /*mobile money request transaction id*/
    uint64_t orig_tx_id;
    /*agent code*/
    std::string agent_code;
    /*transaction currency ISO code*/
    uint16_t tx_curr;
    /*transaction amount (local)*/
    uint64_t tx_amnt_local;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction location*/
    std::string tx_location;
};
int ns2__cash_out_MBA(struct ns2__cash_out_MAB_obj msg, struct ns2__msg_response& m);

struct ns2__cash_remittance_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*recipient phone num*/
    uint64_t recipient_phone ;
    /*recipient id number*/
    std::string recipient_id;
    /*sender phone number*/
    uint64_t sender_phone ;
    /*sender id number*/
    std::string sender_id_number;
    /*transaction currency ISO code*/
    uint16_t tx_curr;
    /*transaction amount (local)*/
    uint64_t tx_amnt_local;
    /*transaction amount (foreign)*/
    uint64_t tx_amnt_foreign;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction location*/
    std::string tx_location;
    /*source of income*/
    std::string income_src;
    /*relationship to the recipient*/
    std::string relationship;
    /*reason*/
    std::string reason;
};
int ns2__cash_remittance(struct ns2__cash_remittance_obj msg, struct ns2__msg_response& m);

struct ns2__payment_retail_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*sender bank code*/
    uint32_t bank_code;
    /*sender hashed account id*/
    std::string sender_acc_id;
    /*sender account type*/
    uint8_t sender_acc_type;
    /*merchant code*/
    std::string mrch_code;
     /*terminal id*/
    std::string term_id;
    /*transaction currency ISO code*/
    uint16_t tx_curr;
    /*transaction amount (local)*/
    uint64_t tx_amnt_local;
     /*transaction date/time*/
    std::string tx_date;
    /*transaction location*/
    std::string tx_location;
};
int ns2__payment_retail(struct ns2__payment_retail_obj msg, struct ns2__msg_response& m);

struct ns2__payment_personal_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*sender bank code*/
    uint32_t bank_code;
    /*sender hashed account id*/
    std::string sender_acc_id;
    /*sender account type*/
    uint8_t sender_acc_type;
    /*recipient bank code*/
    std::string recipient_bank_code;
    /*OMS recipient bank code*/
    uint32_t OMS_recipient_bank_code;
    /*recipient hashed account id*/
    std::string recipient_acc_id;
    /*recipient account type*/
    uint8_t recipient_acc_type;
    /*recipient phone num*/
    uint64_t recipient_phone ;
    /*recipient name*/
    std::string recipient_name;
    /*transaction currency ISO code*/
    uint16_t tx_curr;
    /*transaction amount (local)*/
    uint64_t tx_amnt_local;
    /*transaction amount (foreign)*/
    uint64_t tx_amnt_foreign;
    /*reason*/
    std::string reason;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction location*/
    std::string tx_location;
};
int ns2__payment_personal_(struct ns2__payment_personal_obj msg, struct ns2__msg_response& m);

struct ns2__prepaid_top_up_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*sender bank code*/
    uint32_t bank_code;
    /*sender hashed account id*/
    std::string sender_acc_id;
    /*sender account type*/
    uint8_t sender_acc_type;
    /*provider code*/
    std::string provider;
    /*Account Number(Phone no, Card no, etc)*/
    std::string acc_no;
    /*reference number*/
    std::string ref_no;
    /*transaction currency ISO code*/
    uint16_t tx_curr;
    /*transaction amount (local)*/
    uint64_t tx_amnt_local;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction location*/
    std::string tx_location;

};
int ns2__prepaid_top_up(struct ns2__prepaid_top_up_obj msg, struct ns2__msg_response& m);

struct ns2__payment_bill_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*sender bank code*/
    uint32_t bank_code;
    /*sender hashed account id*/
    std::string sender_acc_id;
    /*sender account type*/
    uint8_t sender_acc_type;
    /*biller code*/
    std::string biller;
    /*bill account number*/
    std::string bill_acc_no;
    /*bill Reference No.*/
    std::string bill_ref;
    /*bill account name*/
    std::string bill_acc_name;
    /*transaction currency ISO code*/
    uint16_t tx_curr;
    /*transaction amount (local)*/
    uint64_t tx_amnt_local;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction location*/
    std::string tx_location;
};
int ns2__payment_bill(struct ns2__payment_bill_obj msg, struct ns2__msg_response& m);

struct ns2__payment_invoice_1click_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*sender bank code*/
    uint32_t bank_code;
    /*sender hashed account id*/
    std::string sender_acc_id;
    /*sender account type*/
    uint8_t sender_acc_type;
    /*merchant code*/
    std::string mrch_code;
    /*invoice reference number*/
    std::string invoice_ref_no;
    /*transaction currency ISO code*/
    uint16_t tx_curr;
    /*transaction amount (local)*/
    uint64_t tx_amnt_local;
   /*transaction date/time*/
    std::string tx_date;
    /*transaction location*/
    std::string tx_location;
};
int ns2__payment_invoice_1click(struct ns2__payment_invoice_1click_obj msg, struct ns2__msg_response& m);

struct ns2__payment_invoice_salesman_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*sender bank code*/
    uint32_t bank_code;
    /*sender hashed account id*/
    std::string sender_acc_id;
    /*sender account type*/
    uint8_t sender_acc_type;
    /*merchant code*/
    std::string mrch_code;
    /*invoice reference number*/
    std::string invoice_ref_no;
    /*transaction currency ISO code*/
    uint16_t tx_curr;
    /*transaction amount (local)*/
    uint64_t tx_amnt_local;
    /* salesman code*/
    std::string salesman;
   /*transaction date/time*/
    std::string tx_date;
    /*transaction location*/
    std::string tx_location;
};
int ns2__payment_invoice_salesman(struct ns2__payment_invoice_salesman_obj msg, struct ns2__msg_response& m);

struct ns2__payment_bulk_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*sender bank code*/
    uint32_t bank_code;
    /*sender hashed account id*/
    std::string sender_acc_id;
    /*sender account type*/
    uint8_t sender_acc_type;
    /*recipient bank*/
    uint32_t recipient_bank;
    /*recipient hashed account id*/
    std::string recipient_acc_id;
    /*recipient account type*/
    uint8_t recipient_acc_type;
   /*transaction currency ISO code*/
    uint16_t tx_curr;
    /*transaction amount (local)*/
    uint64_t tx_amnt_local;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction location*/
    std::string tx_location;
};
int ns2__payment_bulk(struct ns2__payment_bulk_obj msg, struct ns2__msg_response& m);

struct ns2__payment_online_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*sender bank code*/
    uint32_t bank_code;
    /*sender hashed account id*/
    std::string sender_acc_id;
    /*sender account type*/
    uint8_t sender_acc_type;
    /*merchant code*/
    std::string mrch_code;
    /*Tx cuerrency ISO code*/
    uint16_t tx_curr;
    /*transaction amount (local)*/
    uint64_t tx_amnt_local;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction location*/
    std::string tx_location;
};
int ns2__payment_online(struct ns2__payment_online_obj msg, struct ns2__msg_response& m);

struct ns2__payment_ticket_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*hypertag unique id*/
    uint64_t hypertag_id;
    /*sender bank code*/
    uint32_t bank_code;
    /*sender hashed account id*/
    std::string sender_acc_id;
    /*sender account type*/
    uint8_t sender_acc_type;
    /*merchant code*/
    std::string mrch_code;
    /*Tx currency ISO code*/
    uint16_t tx_curr;
    /*transaction amount (local)*/
    uint64_t tx_amnt_local;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction location*/
    std::string tx_location;
};
int ns2__payment_ticket(struct ns2__payment_ticket_obj msg, struct ns2__msg_response& m);

struct ns2__cash_in_out_branch_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*branch code*/
    std::string branch_code;
    /*customer bank code*/
    uint32_t bank_code;
    /*customer hashed account id*/
    std::string customer_acc_id;
    /*customer account type*/
    uint8_t customer_acc_type;
    /*transaction currency ISO code*/
    uint16_t tx_curr;
    /*transaction amount (local)*/
    uint64_t tx_amnt_local;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction location*/
    std::string tx_location;
};
int ns2__cash_in_out_branch(struct ns2__cash_in_out_branch_obj msg, struct ns2__msg_response& m);

struct ns2__cash_out_ATM_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*branch code*/
    std::string branch_code;
    /*ATM id*/
    std::string ATM_id;
    /*bank code*/
    uint32_t bank_code;
    /*customer hashed account id*/
    std::string customer_acc_id;
    /*customer account type*/
    uint8_t customer_acc_type;
    /*transaction currency ISO code*/
    uint16_t tx_curr;
    /*transaction amount (local)*/
    uint64_t tx_amnt_local;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction location*/
    std::string tx_location;
};
int ns2__cash_out_ATM(struct ns2__cash_out_ATM_obj msg, struct ns2__msg_response& m);

struct ns2__cash_remittance_branch_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*branch code*/
    std::string branch_code;
   /*recipient phone num*/
    uint64_t recipient_phone ;
    /*recipient id number*/
    std::string recipient_id;
    /*sender phone number*/
    uint64_t sender_phone ;
    /*sender id number*/
    std::string sender_id_number;
    /*transaction currency ISO code*/
    uint16_t tx_curr;
    /*transaction amount (local)*/
    uint64_t tx_amnt_local;
    /*transaction amount (foreign)*/
    uint64_t tx_amnt_foreign;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction location*/
    std::string tx_location;
    /*source of income*/
    std::string income_src;
    /*relationship to the recipient*/
    std::string relationship;
    /*reason*/
    std::string reason;
};
int ns2__cash_remittance_branch(struct ns2__cash_remittance_branch_obj msg, struct ns2__msg_response& m);

struct ns2__cash_out_ATM_cash_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*branch code*/
    std::string branch_code;
    /*ATM id*/
    std::string ATM_id;
    /*OOjiBO money request transaction id*/
    uint64_t orig_tx_id;
    /*transaction currency ISO code*/
    uint16_t tx_curr;
    /*transaction amount (local)*/
    uint64_t tx_amnt_local;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction location*/
    std::string tx_location;
};
int ns2__cash_out_ATM_cash(struct ns2__cash_out_ATM_cash_obj msg, struct ns2__msg_response& m);

struct ns2__cash_out_mobile_money_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*branch code*/
    std::string branch_code;
    /*OOjiBO money request transaction id*/
    uint64_t orig_tx_id;
    /*transaction currency ISO code*/
    uint16_t tx_curr;
    /*transaction amount (local)*/
    uint64_t tx_amnt_local;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction location*/
    std::string tx_location;
};
int ns2__cash_out_mobile_money(struct ns2__cash_out_mobile_money_obj msg, struct ns2__msg_response& m);

struct ns2__adjustment_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*OOjiBO money request transaction id*/
    uint64_t orig_tx_id;
    /*OOjiBO money request transaction type*/
    uint16_t orig_tx_type;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction remarks*/
    std::string tx_remarks;
};
int ns2__adjustment(struct ns2__adjustment_obj msg, struct ns2__msg_response& m);

struct ns2__adjustment_fee_obj
{
    /*Unique transaction id*/
    uint64_t tx_id ;
    /*transaction type*/
    uint16_t tx_type;
    /*customer bank code*/
    uint32_t bank_code;
    /*customer hashed account id*/
    std::string customer_acc_id;
    /*customer account type*/
    uint8_t customer_acc_type;
    /*transaction amount (local)*/
    uint16_t tx_curr;
    /*transaction amount (local)*/
    uint64_t tx_amnt_local;
    /*transaction date/time*/
    std::string tx_date;
    /*transaction remarks*/
    std::string tx_remarks;
};
int ns2__adjustment_fee(struct ns2__adjustment_fee_obj msg, struct ns2__msg_response& m);




