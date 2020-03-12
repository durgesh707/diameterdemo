/*
* Copyright (c) 2019 Sprint
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*    http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

/****************
 Generated By: fdtool enhancements to diafuzzer
 License: same as freeDiameter
****************/


/* 
 * Dictionary definitions of objects specified in SWm (e10).
 */
#include <freeDiameter/extension.h>

#define PROTO_VER "e10"
#define GEN_DATE  1570740577.56

const char *swm_proto_ver = PROTO_VER;
const double swm_gen_date = GEN_DATE;

/* The content of this file follows the same structure as dict_base_proto.c */

#define CHECK_dict_new( _type, _data, _parent, _ref )                                     \
{                                                                                         \
    int _ret = fd_dict_new( fd_g_config->cnf_dict, (_type), (_data), (_parent), (_ref) ); \
    if ( _ret != 0 && _ret != EEXIST )                                                    \
       return _ret;                                                                       \
}

#define CHECK_dict_search( _type, _criteria, _what, _result )		\
    CHECK_FCT(  fd_dict_search( fd_g_config->cnf_dict, (_type), (_criteria), (_what), (_result), ENOENT) );

struct local_rules_definition {
    struct dict_avp_request avp_vendor_plus_name;
    enum rule_position	position;
    int 			min;
    int			max;
};

#define RULE_ORDER( _position ) ((((_position) == RULE_FIXED_HEAD) || ((_position) == RULE_FIXED_TAIL)) ? 1 : 0 )

/* Attention! This version of the macro uses AVP_BY_NAME_AND_VENDOR, in contrast to most other copies! */
#define PARSE_loc_rules( _rulearray, _parent) {                                                         \
        int __ar;                                                                                       \
        for (__ar=0; __ar < sizeof(_rulearray) / sizeof((_rulearray)[0]); __ar++) {                     \
                struct dict_rule_data __data = { NULL,                                                  \
                        (_rulearray)[__ar].position,                                                    \
                        0,                                                                              \
                        (_rulearray)[__ar].min,                                                         \
                        (_rulearray)[__ar].max};                                                        \
                __data.rule_order = RULE_ORDER(__data.rule_position);                                   \
                CHECK_FCT(  fd_dict_search(                                                             \
                        fd_g_config->cnf_dict,                                                          \
                        DICT_AVP,                                                                       \
                        AVP_BY_NAME_AND_VENDOR,                                                         \
                        &(_rulearray)[__ar].avp_vendor_plus_name,                                       \
                        &__data.rule_avp, 0 ) );                                                        \
                if ( !__data.rule_avp ) {                                                               \
                        TRACE_DEBUG(INFO, "AVP Not found: '%s'", (_rulearray)[__ar].avp_vendor_plus_name.avp_name);             \
                        return ENOENT;                                                                  \
                }                                                                                       \
                {                                                                                       \
                         int _ret = fd_dict_new( fd_g_config->cnf_dict, DICT_RULE, &(__data), (_parent), NULL ); \
                         if ( _ret != 0 && _ret != EEXIST )      {                                      \
                                TRACE_DEBUG(INFO, "Error on rule with AVP '%s'",                        \
                                            (_rulearray)[__ar].avp_vendor_plus_name.avp_name);          \
                                return EINVAL;                                                          \
                         }                                                                              \
                }                                                                                       \
        }                                                                                               \
}

#define CHECK_vendor_new( _data ) { \
        struct dict_object * vendor_found; \
        if (fd_dict_search(fd_g_config->cnf_dict,DICT_VENDOR,VENDOR_BY_ID,&_data.vendor_id,&vendor_found,ENOENT) == ENOENT) { \
                CHECK_FCT(fd_dict_new(fd_g_config->cnf_dict, DICT_VENDOR, &_data, NULL, NULL)); \
        } \
}

#define enumval_def_u32( _val_, _str_ )		\
    { _str_, 		{ .u32 = _val_ }}

#define enumval_def_os( _len_, _val_, _str_ )				\
    { _str_, 		{ .os = { .data = (unsigned char *)_val_, .len = _len_ }}}


static int dict_swm_load_defs(char * conffile)
{
   TRACE_ENTRY("%p", conffile);
	struct dict_object * app_id16777264;

	/* Application Section */
	{
	  {
			struct dict_object * vendor;
			CHECK_dict_search(DICT_VENDOR, VENDOR_BY_NAME, "3GPP", &vendor)
			struct dict_application_data data = { 16777264, "SWm" };
			CHECK_dict_new( DICT_APPLICATION, &data, vendor, &app_id16777264)
	  }
	  /* Result codes */
	  {
			struct dict_object *type;
			CHECK_dict_search(DICT_TYPE, TYPE_BY_NAME, "Enumerated(Result-Code)",&type);
			struct dict_enumval_data        t_1 = { "Result_Code_and_Experimental_Result_Values", { .u32=10 }};
			struct dict_enumval_data        t_2 = { "for_STa_by_replacing", { .u32=2 }};
			struct dict_enumval_data        t_3 = { "ePDG_behaviour", { .u32=3 }};
			struct dict_enumval_data        t_4 = { "S6b_interface", { .u32=4 }};
			struct dict_enumval_data        t_5 = { "QoS_Resources", { .u32=5 }};
			struct dict_enumval_data        t_6 = { "SWm_Interface", { .u32=6 }};
			struct dict_enumval_data        t_7 = { "DER_S6b_Flags", { .u32=7 }};

			CHECK_dict_new( DICT_ENUMVAL, &t_1, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_2, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_3, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_4, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_5, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_6, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_7, type, NULL);

	  }
	}


   /* AVP section */
   {
		struct dict_object * Address_type;
		struct dict_object * UTF8String_type;
		struct dict_object * DiameterIdentity_type;
		struct dict_object * DiameterURI_type;
		struct dict_object * Time_type;
		struct dict_object * IPFilterRule_type;

		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "Address", &Address_type);
		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "UTF8String", &UTF8String_type);
		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "DiameterIdentity", &DiameterIdentity_type);
		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "DiameterURI", &DiameterURI_type);
		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "Time", &Time_type);
		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "IPFilterRule", &IPFilterRule_type);

	
   }

   /* Commands section */
   {
		/* Diameter-EAP-Request */
		{
			struct dict_object* cmd;
			struct dict_cmd_data data = {
				268,	/* Code */
				"Diameter-EAP-Request",	/* Name */
				CMD_FLAG_REQUEST | CMD_FLAG_ERROR,	/* Fixed flags */
				CMD_FLAG_REQUEST | CMD_FLAG_PROXIABLE,	/* Fixed flag values */
			};

			CHECK_dict_new( DICT_COMMAND, &data , app_id16777264, &cmd)
		}
		/* Diameter-EAP-Answer */
		{
			struct dict_object* cmd;
			struct dict_cmd_data data = {
				268,	/* Code */
				"Diameter-EAP-Answer",	/* Name */
				CMD_FLAG_REQUEST,	/* Fixed flags */
				CMD_FLAG_PROXIABLE,	/* Fixed flag values */
			};

			CHECK_dict_new( DICT_COMMAND, &data , app_id16777264, &cmd)
		}
		/* AA-Request */
		{
			struct dict_object* cmd;
			struct dict_cmd_data data = {
				265,	/* Code */
				"AA-Request",	/* Name */
				CMD_FLAG_REQUEST | CMD_FLAG_ERROR,	/* Fixed flags */
				CMD_FLAG_REQUEST | CMD_FLAG_PROXIABLE,	/* Fixed flag values */
			};

			CHECK_dict_new( DICT_COMMAND, &data , app_id16777264, &cmd)
		}
		/* AA-Answer */
		{
			struct dict_object* cmd;
			struct dict_cmd_data data = {
				265,	/* Code */
				"AA-Answer",	/* Name */
				CMD_FLAG_REQUEST,	/* Fixed flags */
				CMD_FLAG_PROXIABLE,	/* Fixed flag values */
			};

			CHECK_dict_new( DICT_COMMAND, &data , app_id16777264, &cmd)
		}
		/* Session-Termination-Request */
		{
			struct dict_object* cmd;
			struct dict_cmd_data data = {
				275,	/* Code */
				"Session-Termination-Request",	/* Name */
				CMD_FLAG_REQUEST | CMD_FLAG_ERROR,	/* Fixed flags */
				CMD_FLAG_REQUEST | CMD_FLAG_PROXIABLE,	/* Fixed flag values */
			};

			CHECK_dict_new( DICT_COMMAND, &data , app_id16777264, &cmd)
		}
		/* Session-Termination-Answer */
		{
			struct dict_object* cmd;
			struct dict_cmd_data data = {
				275,	/* Code */
				"Session-Termination-Answer",	/* Name */
				CMD_FLAG_REQUEST,	/* Fixed flags */
				CMD_FLAG_PROXIABLE,	/* Fixed flag values */
			};

			CHECK_dict_new( DICT_COMMAND, &data , app_id16777264, &cmd)
		}
		/* Abort-Session-Request */
		{
			struct dict_object* cmd;
			struct dict_cmd_data data = {
				274,	/* Code */
				"Abort-Session-Request",	/* Name */
				CMD_FLAG_REQUEST | CMD_FLAG_ERROR,	/* Fixed flags */
				CMD_FLAG_REQUEST | CMD_FLAG_PROXIABLE,	/* Fixed flag values */
			};

			CHECK_dict_new( DICT_COMMAND, &data , app_id16777264, &cmd)
		}
		/* Abort-Session-Answer */
		{
			struct dict_object* cmd;
			struct dict_cmd_data data = {
				274,	/* Code */
				"Abort-Session-Answer",	/* Name */
				CMD_FLAG_REQUEST,	/* Fixed flags */
				CMD_FLAG_PROXIABLE,	/* Fixed flag values */
			};

			CHECK_dict_new( DICT_COMMAND, &data , app_id16777264, &cmd)
		}
		/* Re-Auth-Request */
		{
			struct dict_object* cmd;
			struct dict_cmd_data data = {
				258,	/* Code */
				"Re-Auth-Request",	/* Name */
				CMD_FLAG_REQUEST | CMD_FLAG_ERROR,	/* Fixed flags */
				CMD_FLAG_REQUEST | CMD_FLAG_PROXIABLE,	/* Fixed flag values */
			};

			CHECK_dict_new( DICT_COMMAND, &data , app_id16777264, &cmd)
		}
		/* Re-Auth-Answer */
		{
			struct dict_object* cmd;
			struct dict_cmd_data data = {
				258,	/* Code */
				"Re-Auth-Answer",	/* Name */
				CMD_FLAG_REQUEST,	/* Fixed flags */
				CMD_FLAG_PROXIABLE,	/* Fixed flag values */
			};

			CHECK_dict_new( DICT_COMMAND, &data , app_id16777264, &cmd)
		}

   }

   return 0;
}

static int dict_swm_load_rules(char * conffile)
{
   /* Grouped AVP section */
   {

   }	

   /* Commands section */
   {
	  /* Diameter-EAP-Request */
	  {
		struct dict_object* cmd;
		CHECK_dict_search( DICT_COMMAND, CMD_BY_NAME, "Diameter-EAP-Request", &cmd)
		struct local_rules_definition rules[] =
		{
			{ { .avp_vendor = 0, .avp_name = "Session-Id"}, RULE_FIXED_HEAD, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "DRMP"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Auth-Application-Id"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Host"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Destination-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Destination-Host"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Auth-Request-Type"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "EAP-Payload"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "User-Name"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "RAT-Type"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Service-Selection"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "MIP6-Feature-Vector"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "QoS-Capability"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Visited-Network-Identifier"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "AAA-Failure-Indication"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Supported-Features"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "UE-Local-IP-Address"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "OC-Supported-Features"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Terminal-Information"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Emergency-Services"}, RULE_OPTIONAL, -1, -1 }
		};
		PARSE_loc_rules(rules, cmd);
	  }
	  /* Diameter-EAP-Answer */
	  {
		struct dict_object* cmd;
		CHECK_dict_search( DICT_COMMAND, CMD_BY_NAME, "Diameter-EAP-Answer", &cmd)
		struct local_rules_definition rules[] =
		{
			{ { .avp_vendor = 0, .avp_name = "Session-Id"}, RULE_FIXED_HEAD, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "DRMP"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Auth-Application-Id"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Auth-Request-Type"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Result-Code"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Host"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "EAP-Payload"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "User-Name"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "EAP-Master-Session-Key"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "APN-OI-Replacement"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "APN-Configuration"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "MIP6-Feature-Vector"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Mobile-Node-Identifier"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Trace-Info"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Subscription-Id"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Session-Timeout"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "MIP6-Agent-Info"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "3GPP-Charging-Characteristics"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Redirect-Host"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Supported-Features"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "OC-Supported-Features"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "OC-OLR"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Load"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Access-Network-Info"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "User-Location-Info-Time"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "UE-Usage-Type"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Emergency-Info"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Core-Network-Restrictions"}, RULE_OPTIONAL, -1, -1 }
		};
		PARSE_loc_rules(rules, cmd);
	  }
	  /* AA-Request */
	  {
		struct dict_object* cmd;
		CHECK_dict_search( DICT_COMMAND, CMD_BY_NAME, "AA-Request", &cmd)
		struct local_rules_definition rules[] =
		{
			{ { .avp_vendor = 0, .avp_name = "Session-Id"}, RULE_FIXED_HEAD, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "DRMP"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Auth-Application-Id"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Host"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Destination-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Destination-Host"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Auth-Request-Type"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "User-Name"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "OC-Supported-Features"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "AAR-Flags"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "UE-Local-IP-Address"}, RULE_OPTIONAL, -1, -1 }
		};
		PARSE_loc_rules(rules, cmd);
	  }
	  /* AA-Answer */
	  {
		struct dict_object* cmd;
		CHECK_dict_search( DICT_COMMAND, CMD_BY_NAME, "AA-Answer", &cmd)
		struct local_rules_definition rules[] =
		{
			{ { .avp_vendor = 0, .avp_name = "Session-Id"}, RULE_FIXED_HEAD, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "DRMP"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Auth-Application-Id"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Auth-Request-Type"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Result-Code"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Host"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "User-Name"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "APN-OI-Replacement"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "APN-Configuration"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Trace-Info"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Subscription-Id"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "3GPP-Charging-Characteristics"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Session-Timeout"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "OC-Supported-Features"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "OC-OLR"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Load"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Access-Network-Info"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "User-Location-Info-Time"}, RULE_OPTIONAL, -1, -1 }
		};
		PARSE_loc_rules(rules, cmd);
	  }
	  /* Session-Termination-Request */
	  {
		struct dict_object* cmd;
		CHECK_dict_search( DICT_COMMAND, CMD_BY_NAME, "Session-Termination-Request", &cmd)
		struct local_rules_definition rules[] =
		{
			{ { .avp_vendor = 0, .avp_name = "Session-Id"}, RULE_FIXED_HEAD, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "DRMP"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Host"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Destination-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Destination-Host"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Auth-Application-Id"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Termination-Cause"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "User-Name"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "OC-Supported-Features"}, RULE_OPTIONAL, -1, -1 }
		};
		PARSE_loc_rules(rules, cmd);
	  }
	  /* Session-Termination-Answer */
	  {
		struct dict_object* cmd;
		CHECK_dict_search( DICT_COMMAND, CMD_BY_NAME, "Session-Termination-Answer", &cmd)
		struct local_rules_definition rules[] =
		{
			{ { .avp_vendor = 0, .avp_name = "Session-Id"}, RULE_FIXED_HEAD, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "DRMP"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Result-Code"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Host"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "OC-Supported-Features"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "OC-OLR"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Load"}, RULE_OPTIONAL, -1, -1 }
		};
		PARSE_loc_rules(rules, cmd);
	  }
	  /* Abort-Session-Request */
	  {
		struct dict_object* cmd;
		CHECK_dict_search( DICT_COMMAND, CMD_BY_NAME, "Abort-Session-Request", &cmd)
		struct local_rules_definition rules[] =
		{
			{ { .avp_vendor = 0, .avp_name = "Session-Id"}, RULE_FIXED_HEAD, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "DRMP"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Host"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Destination-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Destination-Host"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Auth-Application-Id"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "User-Name"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Auth-Session-State"}, RULE_OPTIONAL, -1, -1 }
		};
		PARSE_loc_rules(rules, cmd);
	  }
	  /* Abort-Session-Answer */
	  {
		struct dict_object* cmd;
		CHECK_dict_search( DICT_COMMAND, CMD_BY_NAME, "Abort-Session-Answer", &cmd)
		struct local_rules_definition rules[] =
		{
			{ { .avp_vendor = 0, .avp_name = "Session-Id"}, RULE_FIXED_HEAD, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "DRMP"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Result-Code"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Host"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Realm"}, RULE_REQUIRED, -1, -1 }
		};
		PARSE_loc_rules(rules, cmd);
	  }
	  /* Re-Auth-Request */
	  {
		struct dict_object* cmd;
		CHECK_dict_search( DICT_COMMAND, CMD_BY_NAME, "Re-Auth-Request", &cmd)
		struct local_rules_definition rules[] =
		{
			{ { .avp_vendor = 0, .avp_name = "Session-Id"}, RULE_FIXED_HEAD, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "DRMP"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Host"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Destination-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Destination-Host"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Auth-Application-Id"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Re-Auth-Request-Type"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "User-Name"}, RULE_OPTIONAL, -1, -1 }
		};
		PARSE_loc_rules(rules, cmd);
	  }
	  /* Re-Auth-Answer */
	  {
		struct dict_object* cmd;
		CHECK_dict_search( DICT_COMMAND, CMD_BY_NAME, "Re-Auth-Answer", &cmd)
		struct local_rules_definition rules[] =
		{
			{ { .avp_vendor = 0, .avp_name = "Session-Id"}, RULE_FIXED_HEAD, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "DRMP"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Result-Code"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Host"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "User-Name"}, RULE_OPTIONAL, -1, -1 }
		};
		PARSE_loc_rules(rules, cmd);
	  }

   }

   LOG_D( "Extension 'Dictionary definitions for SWm (e10)' initialized");
   return 0;
}

int dict_entry(char * conffile)
{
	dict_swm_load_defs(conffile);
	return dict_swm_load_rules(conffile);
}

const char* dict_proto_ver(char * conffile) {
	return swm_proto_ver;
}

const double dict_gen_ts(char * conffile) {
	return swm_gen_date;
}

EXTENSION_ENTRY2("dict_swm", dict_swm_load_defs, dict_swm_load_rules, "dict_ts29273_avps", "dict_ts32299_avps", "dict_ts29272_avps", "dict_ts29212_avps", "dict_ts29214_avps", "dict_ts29336_avps", "dict_ts29229_avps", "dict_rfc5778_avps", "dict_ts29061_avps", "dict_rfc4006bis_avps", "dict_rfc6942_avps", "dict_rfc4072_avps", "dict_rfc7155_avps", "dict_rfc5447_avps", "dict_rfc7683_avps", "dict_rfc6734_avps", "dict_draftload_avps", "dict_rfc4004_avps", "dict_rfc5580_avps", "dict_rfc5777_avps", "dict_etsi283034_avps", "dict_rfc7944_avps");


