#ifndef REQ_AGENT_HPP
#define REQ_AGENT_HPP
#include<string>
#include<ostream>
#include<odb/core.hxx>



struct ns2__reg_agent_obj
{
    uint64_t tx_id ;//
    uint16_t tx_type;//
    uint64_t hypertag_id;//
    uint32_t bank_code;//
    std::string agent_code;//
    uint64_t cif_id;
    std::string acc_id;
    uint8_t acc_type;
    std::string net_operator;
    uint64_t phone;
    uint16_t home_currency;
    std::string home_country;
    std::string home_province;
    std::string home_region;
    std::string home_city;
    std::string home_township;
    std::string date_birth;
    uint8_t id_type;
    std::string id_no;
    std::string gender;
    uint8_t occupation;
    std::string home_branch;
    std::string service_plan;
    std::string signup_loc;
    std::string signup_date;
    std::string magent_code;
    std::string funder_acct_id;
};
#pragma db object(ns2__reg_agent_obj) no_id




struct ns2__reg_customer_obj
{
    uint64_t tx_id ;//
    uint16_t tx_type;//
    uint64_t hypertag_id;//
    uint32_t bank_code;//
    uint64_t cif_id;
    std::string acc_id;
    uint8_t acc_type;
    std::string net_operator;
    uint64_t phone;
    uint16_t home_currency;
    std::string home_country;
    std::string home_province;
    std::string home_region;
    std::string home_city;
    std::string home_township;
    std::string date_birth;
    uint8_t id_type;
    std::string id_no;
    std::string gender;
    uint8_t occupation;
    std::string home_branch;
    std::string service_plan;
    std::string signup_loc;
    std::string signup_date;
    std::string agent_code;
    uint64_t initial_deposit;
};
#pragma db object(ns2__reg_customer_obj) no_id
#endif
