/** @file adimat-client-opts.hh
 *  @brief The header file for the command line option parser
 *  generated by GNU Gengetopt version 2.22.4
 *  http://www.gnu.org/software/gengetopt.
 *  DO NOT modify this file, since it can be overwritten
 *  @author GNU Gengetopt by Lorenzo Bettini */

#ifndef ADIMAT_CLIENT_OPTS_H
#define ADIMAT_CLIENT_OPTS_H

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h> /* for FILE */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef CMDLINE_PARSER_PACKAGE
/** @brief the program name (used for printing errors) */
#define CMDLINE_PARSER_PACKAGE "adimat-client"
#endif

#ifndef CMDLINE_PARSER_PACKAGE_NAME
/** @brief the complete program name (used for help and version) */
#define CMDLINE_PARSER_PACKAGE_NAME "adimat-client"
#endif

#ifndef CMDLINE_PARSER_VERSION
/** @brief the program version */
#define CMDLINE_PARSER_VERSION VERSION
#endif

/** @brief Where the command line options are stored */
struct gengetopt_args_info
{
  const char *help_help; /**< @brief Print help and exit help description.  */
  const char *full_help_help; /**< @brief Print help, including hidden options, and exit help description.  */
  const char *version_help; /**< @brief Print version and exit help description.  */
  int long_version_flag;	/**< @brief Print long version (default=off).  */
  const char *long_version_help; /**< @brief Print long version help description.  */
  int* verbose_arg;	/**< @brief Set the level of status messages. 0 (no output at all) upto 20 (most chatty) (default='5').  */
  char ** verbose_orig;	/**< @brief Set the level of status messages. 0 (no output at all) upto 20 (most chatty) original value given at command line.  */
  unsigned int verbose_min; /**< @brief Set the level of status messages. 0 (no output at all) upto 20 (most chatty)'s minimum occurreces */
  unsigned int verbose_max; /**< @brief Set the level of status messages. 0 (no output at all) upto 20 (most chatty)'s maximum occurreces */
  const char *verbose_help; /**< @brief Set the level of status messages. 0 (no output at all) upto 20 (most chatty) help description.  */
  int debug_flag;	/**< @brief Enable debugging: save messages and log to directory ./adimat (default=off).  */
  const char *debug_help; /**< @brief Enable debugging: save messages and log to directory ./adimat help description.  */
  char * user_dir_arg;	/**< @brief Directory for client user configuration and state (default='${HOME}/.adimat').  */
  char * user_dir_orig;	/**< @brief Directory for client user configuration and state original value given at command line.  */
  const char *user_dir_help; /**< @brief Directory for client user configuration and state help description.  */
  int classic_forward_flag;	/**< @brief Differentiate in Forward Mode (default=off).  */
  const char *classic_forward_help; /**< @brief Differentiate in Forward Mode help description.  */
  int forward_flag;	/**< @brief Differentiate in Forward Mode (default=off).  */
  const char *forward_help; /**< @brief Differentiate in Forward Mode help description.  */
  int taylor_flag;	/**< @brief Differentiate in Taylor Forward Mode (default=off).  */
  const char *taylor_help; /**< @brief Differentiate in Taylor Forward Mode help description.  */
  int reverse_flag;	/**< @brief Differentiate in Reverse Mode (default=off).  */
  const char *reverse_help; /**< @brief Differentiate in Reverse Mode help description.  */
  char * tool_chain_arg;	/**< @brief Run named toolchain.  */
  char * tool_chain_orig;	/**< @brief Run named toolchain original value given at command line.  */
  const char *tool_chain_help; /**< @brief Run named toolchain help description.  */
  int list_tool_chains_flag;	/**< @brief List available toolchains (default=off).  */
  const char *list_tool_chains_help; /**< @brief List available toolchains help description.  */
  int server_version_flag;	/**< @brief Get server version (default=off).  */
  const char *server_version_help; /**< @brief Get server version help description.  */
  int stdout_flag;	/**< @brief Output received files to console (default=off).  */
  const char *stdout_help; /**< @brief Output received files to console help description.  */
  char * output_arg;	/**< @brief Output received files to file.  */
  char * output_orig;	/**< @brief Output received files to file original value given at command line.  */
  const char *output_help; /**< @brief Output received files to file help description.  */
  int* interactive_arg;	/**< @brief Do not ask before sending files over the net (default='0').  */
  char ** interactive_orig;	/**< @brief Do not ask before sending files over the net original value given at command line.  */
  unsigned int interactive_min; /**< @brief Do not ask before sending files over the net's minimum occurreces */
  unsigned int interactive_max; /**< @brief Do not ask before sending files over the net's maximum occurreces */
  const char *interactive_help; /**< @brief Do not ask before sending files over the net help description.  */
  char ** output_dir_arg;	/**< @brief Write received files to directory (default='.').  */
  char ** output_dir_orig;	/**< @brief Write received files to directory original value given at command line.  */
  unsigned int output_dir_min; /**< @brief Write received files to directory's minimum occurreces */
  unsigned int output_dir_max; /**< @brief Write received files to directory's maximum occurreces */
  const char *output_dir_help; /**< @brief Write received files to directory help description.  */
  char ** include_dir_arg;	/**< @brief Add directory to search path.  */
  char ** include_dir_orig;	/**< @brief Add directory to search path original value given at command line.  */
  unsigned int include_dir_min; /**< @brief Add directory to search path's minimum occurreces */
  unsigned int include_dir_max; /**< @brief Add directory to search path's maximum occurreces */
  const char *include_dir_help; /**< @brief Add directory to search path help description.  */
  char * encoding_arg;	/**< @brief Specify encoding of input files (default='utf-8').  */
  char * encoding_orig;	/**< @brief Specify encoding of input files original value given at command line.  */
  const char *encoding_help; /**< @brief Specify encoding of input files help description.  */
  char * dependency_list_arg;	/**< @brief Write list of dependencies to file.  */
  char * dependency_list_orig;	/**< @brief Write list of dependencies to file original value given at command line.  */
  const char *dependency_list_help; /**< @brief Write list of dependencies to file help description.  */
  int unbound_flag;	/**< @brief Don't ask for more files if unbound identifieres (default=off).  */
  const char *unbound_help; /**< @brief Don't ask for more files if unbound identifieres help description.  */
  char * independent_arg;	/**< @brief Set independent variables.  */
  char * independent_orig;	/**< @brief Set independent variables original value given at command line.  */
  const char *independent_help; /**< @brief Set independent variables help description.  */
  char * dependent_arg;	/**< @brief Set independent variables.  */
  char * dependent_orig;	/**< @brief Set independent variables original value given at command line.  */
  const char *dependent_help; /**< @brief Set independent variables help description.  */
  char ** transformation_param_arg;	/**< @brief Set a transformation parameter.  */
  char ** transformation_param_orig;	/**< @brief Set a transformation parameter original value given at command line.  */
  unsigned int transformation_param_min; /**< @brief Set a transformation parameter's minimum occurreces */
  unsigned int transformation_param_max; /**< @brief Set a transformation parameter's maximum occurreces */
  const char *transformation_param_help; /**< @brief Set a transformation parameter help description.  */
  int all_active_flag;	/**< @brief Ignore activity analysis and consider all variables active (rm/fm only) (default=off).  */
  const char *all_active_help; /**< @brief Ignore activity analysis and consider all variables active (rm/fm only) help description.  */
  char * xslt_processor_arg;	/**< @brief Set XSLT processor (xsltproc or saxon-xslt).  */
  char * xslt_processor_orig;	/**< @brief Set XSLT processor (xsltproc or saxon-xslt) original value given at command line.  */
  const char *xslt_processor_help; /**< @brief Set XSLT processor (xsltproc or saxon-xslt) help description.  */
  int vector_flag;	/**< @brief Create code for classless vector mode (default=off).  */
  const char *vector_help; /**< @brief Create code for classless vector mode help description.  */
  int* comments_arg;	/**< @brief Add comments inserted into the code. Repeat for more comments (default='0').  */
  char ** comments_orig;	/**< @brief Add comments inserted into the code. Repeat for more comments original value given at command line.  */
  unsigned int comments_min; /**< @brief Add comments inserted into the code. Repeat for more comments's minimum occurreces */
  unsigned int comments_max; /**< @brief Add comments inserted into the code. Repeat for more comments's maximum occurreces */
  const char *comments_help; /**< @brief Add comments inserted into the code. Repeat for more comments help description.  */
  char * server_arg;	/**< @brief The URL to connect to (default='https://adimat.sc.informatik.tu-darmstadt.de/').  */
  char * server_orig;	/**< @brief The URL to connect to original value given at command line.  */
  const char *server_help; /**< @brief The URL to connect to help description.  */
  char * hostname_arg;	/**< @brief The host to connect to (default='adimat.sc.informatik.tu-darmstadt.de').  */
  char * hostname_orig;	/**< @brief The host to connect to original value given at command line.  */
  const char *hostname_help; /**< @brief The host to connect to help description.  */
  char * cgi_path_arg;	/**< @brief The relative path of the CGI on server (without base path) (default='cgi-bin/adimat-server.fcgi').  */
  char * cgi_path_orig;	/**< @brief The relative path of the CGI on server (without base path) original value given at command line.  */
  const char *cgi_path_help; /**< @brief The relative path of the CGI on server (without base path) help description.  */
  char * request_path_arg;	/**< @brief The relative path of the CGI on server (default='/cgi-bin/adimat-server.fcgi').  */
  char * request_path_orig;	/**< @brief The relative path of the CGI on server original value given at command line.  */
  const char *request_path_help; /**< @brief The relative path of the CGI on server help description.  */
  char * port_arg;	/**< @brief Port to connect to (default='443').  */
  char * port_orig;	/**< @brief Port to connect to original value given at command line.  */
  const char *port_help; /**< @brief Port to connect to help description.  */
  int numeric_host_flag;	/**< @brief No DNS resolution (default=off).  */
  const char *numeric_host_help; /**< @brief No DNS resolution help description.  */
  int numeric_port_flag;	/**< @brief No resolution of service names (default=off).  */
  const char *numeric_port_help; /**< @brief No resolution of service names help description.  */
  int no_canonical_host_name_flag;	/**< @brief Don't retrieve canonical host name (default=off).  */
  const char *no_canonical_host_name_help; /**< @brief Don't retrieve canonical host name help description.  */
  int ipv4_flag;	/**< @brief Use IPv4 only (default=off).  */
  const char *ipv4_help; /**< @brief Use IPv4 only help description.  */
  int ipv6_flag;	/**< @brief Use IPv6 only (default=off).  */
  const char *ipv6_help; /**< @brief Use IPv6 only help description.  */
  char ** cgi_param_arg;	/**< @brief Set a CGI parameter.  */
  char ** cgi_param_orig;	/**< @brief Set a CGI parameter original value given at command line.  */
  unsigned int cgi_param_min; /**< @brief Set a CGI parameter's minimum occurreces */
  unsigned int cgi_param_max; /**< @brief Set a CGI parameter's maximum occurreces */
  const char *cgi_param_help; /**< @brief Set a CGI parameter help description.  */
  int no_ssl_flag;	/**< @brief Do not use SSL (default=off).  */
  const char *no_ssl_help; /**< @brief Do not use SSL help description.  */
  char * seed_file_arg;	/**< @brief Where to read SSL random seed from.  */
  char * seed_file_orig;	/**< @brief Where to read SSL random seed from original value given at command line.  */
  const char *seed_file_help; /**< @brief Where to read SSL random seed from help description.  */
  char * trust_store_arg;	/**< @brief Where to read certificates from (default='${HOME}/.adimat/adimat.pem').  */
  char * trust_store_orig;	/**< @brief Where to read certificates from original value given at command line.  */
  const char *trust_store_help; /**< @brief Where to read certificates from help description.  */
  char * ciphers_arg;	/**< @brief Which ciphers to use, see ciphers(1) for details (default='HIGH').  */
  char * ciphers_orig;	/**< @brief Which ciphers to use, see ciphers(1) for details original value given at command line.  */
  const char *ciphers_help; /**< @brief Which ciphers to use, see ciphers(1) for details help description.  */
  int check_certificate_flag;	/**< @brief Whether to check the server's certificate (default=on).  */
  const char *check_certificate_help; /**< @brief Whether to check the server's certificate help description.  */
  int check_certificate_name_flag;	/**< @brief Whether to check the server's certificate common name (CN) (default=on).  */
  const char *check_certificate_name_help; /**< @brief Whether to check the server's certificate common name (CN) help description.  */
  int max_reconnect_arg;	/**< @brief How often to try to reconnect (default='10').  */
  char * max_reconnect_orig;	/**< @brief How often to try to reconnect original value given at command line.  */
  const char *max_reconnect_help; /**< @brief How often to try to reconnect help description.  */
  char * http_version_arg;	/**< @brief Set HTTP protocol version (default='1.1').  */
  char * http_version_orig;	/**< @brief Set HTTP protocol version original value given at command line.  */
  const char *http_version_help; /**< @brief Set HTTP protocol version help description.  */
  char * request_method_arg;	/**< @brief Set HTTP request method (default='POST').  */
  char * request_method_orig;	/**< @brief Set HTTP request method original value given at command line.  */
  const char *request_method_help; /**< @brief Set HTTP request method help description.  */
  char ** header_arg;	/**< @brief Send additional HTTP header.  */
  char ** header_orig;	/**< @brief Send additional HTTP header original value given at command line.  */
  unsigned int header_min; /**< @brief Send additional HTTP header's minimum occurreces */
  unsigned int header_max; /**< @brief Send additional HTTP header's maximum occurreces */
  const char *header_help; /**< @brief Send additional HTTP header help description.  */
  int winsock_major_arg;	/**< @brief Winsock DLL major version number (default='2').  */
  char * winsock_major_orig;	/**< @brief Winsock DLL major version number original value given at command line.  */
  const char *winsock_major_help; /**< @brief Winsock DLL major version number help description.  */
  int winsock_minor_arg;	/**< @brief Winsock DLL minor version number (default='2').  */
  char * winsock_minor_orig;	/**< @brief Winsock DLL minor version number original value given at command line.  */
  const char *winsock_minor_help; /**< @brief Winsock DLL minor version number help description.  */
  
  unsigned int help_given ;	/**< @brief Whether help was given.  */
  unsigned int full_help_given ;	/**< @brief Whether full-help was given.  */
  unsigned int version_given ;	/**< @brief Whether version was given.  */
  unsigned int long_version_given ;	/**< @brief Whether long-version was given.  */
  unsigned int verbose_given ;	/**< @brief Whether verbose was given.  */
  unsigned int debug_given ;	/**< @brief Whether debug was given.  */
  unsigned int user_dir_given ;	/**< @brief Whether user-dir was given.  */
  unsigned int classic_forward_given ;	/**< @brief Whether classic-forward was given.  */
  unsigned int forward_given ;	/**< @brief Whether forward was given.  */
  unsigned int taylor_given ;	/**< @brief Whether taylor was given.  */
  unsigned int reverse_given ;	/**< @brief Whether reverse was given.  */
  unsigned int tool_chain_given ;	/**< @brief Whether tool-chain was given.  */
  unsigned int list_tool_chains_given ;	/**< @brief Whether list-tool-chains was given.  */
  unsigned int server_version_given ;	/**< @brief Whether server-version was given.  */
  unsigned int stdout_given ;	/**< @brief Whether stdout was given.  */
  unsigned int output_given ;	/**< @brief Whether output was given.  */
  unsigned int interactive_given ;	/**< @brief Whether interactive was given.  */
  unsigned int output_dir_given ;	/**< @brief Whether output-dir was given.  */
  unsigned int include_dir_given ;	/**< @brief Whether include-dir was given.  */
  unsigned int encoding_given ;	/**< @brief Whether encoding was given.  */
  unsigned int dependency_list_given ;	/**< @brief Whether dependency-list was given.  */
  unsigned int unbound_given ;	/**< @brief Whether unbound was given.  */
  unsigned int independent_given ;	/**< @brief Whether independent was given.  */
  unsigned int dependent_given ;	/**< @brief Whether dependent was given.  */
  unsigned int transformation_param_given ;	/**< @brief Whether transformation-param was given.  */
  unsigned int all_active_given ;	/**< @brief Whether all-active was given.  */
  unsigned int xslt_processor_given ;	/**< @brief Whether xslt-processor was given.  */
  unsigned int vector_given ;	/**< @brief Whether vector was given.  */
  unsigned int comments_given ;	/**< @brief Whether comments was given.  */
  unsigned int server_given ;	/**< @brief Whether server was given.  */
  unsigned int hostname_given ;	/**< @brief Whether hostname was given.  */
  unsigned int cgi_path_given ;	/**< @brief Whether cgi-path was given.  */
  unsigned int request_path_given ;	/**< @brief Whether request-path was given.  */
  unsigned int port_given ;	/**< @brief Whether port was given.  */
  unsigned int numeric_host_given ;	/**< @brief Whether numeric-host was given.  */
  unsigned int numeric_port_given ;	/**< @brief Whether numeric-port was given.  */
  unsigned int no_canonical_host_name_given ;	/**< @brief Whether no-canonical-host-name was given.  */
  unsigned int ipv4_given ;	/**< @brief Whether ipv4 was given.  */
  unsigned int ipv6_given ;	/**< @brief Whether ipv6 was given.  */
  unsigned int cgi_param_given ;	/**< @brief Whether cgi-param was given.  */
  unsigned int no_ssl_given ;	/**< @brief Whether no-ssl was given.  */
  unsigned int seed_file_given ;	/**< @brief Whether seed-file was given.  */
  unsigned int trust_store_given ;	/**< @brief Whether trust-store was given.  */
  unsigned int ciphers_given ;	/**< @brief Whether ciphers was given.  */
  unsigned int check_certificate_given ;	/**< @brief Whether check-certificate was given.  */
  unsigned int check_certificate_name_given ;	/**< @brief Whether check-certificate-name was given.  */
  unsigned int max_reconnect_given ;	/**< @brief Whether max-reconnect was given.  */
  unsigned int http_version_given ;	/**< @brief Whether http-version was given.  */
  unsigned int request_method_given ;	/**< @brief Whether request-method was given.  */
  unsigned int header_given ;	/**< @brief Whether header was given.  */
  unsigned int winsock_major_given ;	/**< @brief Whether winsock-major was given.  */
  unsigned int winsock_minor_given ;	/**< @brief Whether winsock-minor was given.  */

  char **inputs ; /**< @brief unamed options (options without names) */
  unsigned inputs_num ; /**< @brief unamed options number */
  int Toolchain_mode_counter; /**< @brief Counter for mode Toolchain */
  int classic_fm_mode_counter; /**< @brief Counter for mode classic_fm */
  int fm_mode_counter; /**< @brief Counter for mode fm */
  int rm_mode_counter; /**< @brief Counter for mode rm */
  int taylor_mode_counter; /**< @brief Counter for mode taylor */
  int version_mode_counter; /**< @brief Counter for mode version */
} ;

/** @brief The additional parameters to pass to parser functions */
struct cmdline_parser_params
{
  int override; /**< @brief whether to override possibly already present options (default 0) */
  int initialize; /**< @brief whether to initialize the option structure gengetopt_args_info (default 1) */
  int check_required; /**< @brief whether to check that all required options were provided (default 1) */
  int check_ambiguity; /**< @brief whether to check for options already specified in the option structure gengetopt_args_info (default 0) */
  int print_errors; /**< @brief whether getopt_long should print an error message for a bad option (default 1) */
} ;

/** @brief the purpose string of the program */
extern const char *gengetopt_args_info_purpose;
/** @brief the usage string of the program */
extern const char *gengetopt_args_info_usage;
/** @brief all the lines making the help output */
extern const char *gengetopt_args_info_help[];
/** @brief all the lines making the full help output (including hidden options) */
extern const char *gengetopt_args_info_full_help[];

/**
 * The command line parser
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser (int argc, char **argv,
  struct gengetopt_args_info *args_info);

/**
 * The command line parser (version with additional parameters - deprecated)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param override whether to override possibly already present options
 * @param initialize whether to initialize the option structure my_args_info
 * @param check_required whether to check that all required options were provided
 * @return 0 if everything went fine, NON 0 if an error took place
 * @deprecated use cmdline_parser_ext() instead
 */
int cmdline_parser2 (int argc, char **argv,
  struct gengetopt_args_info *args_info,
  int override, int initialize, int check_required);

/**
 * The command line parser (version with additional parameters)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param params additional parameters for the parser
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_ext (int argc, char **argv,
  struct gengetopt_args_info *args_info,
  struct cmdline_parser_params *params);

/**
 * Save the contents of the option struct into an already open FILE stream.
 * @param outfile the stream where to dump options
 * @param args_info the option struct to dump
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_dump(FILE *outfile,
  struct gengetopt_args_info *args_info);

/**
 * Save the contents of the option struct into a (text) file.
 * This file can be read by the config file parser (if generated by gengetopt)
 * @param filename the file where to save
 * @param args_info the option struct to save
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_file_save(const char *filename,
  struct gengetopt_args_info *args_info);

/**
 * Print the help
 */
void cmdline_parser_print_help(void);
/**
 * Print the full help (including hidden options)
 */
void cmdline_parser_print_full_help(void);
/**
 * Print the version
 */
void cmdline_parser_print_version(void);

/**
 * Initializes all the fields a cmdline_parser_params structure 
 * to their default values
 * @param params the structure to initialize
 */
void cmdline_parser_params_init(struct cmdline_parser_params *params);

/**
 * Allocates dynamically a cmdline_parser_params structure and initializes
 * all its fields to their default values
 * @return the created and initialized cmdline_parser_params structure
 */
struct cmdline_parser_params *cmdline_parser_params_create(void);

/**
 * Initializes the passed gengetopt_args_info structure's fields
 * (also set default values for options that have a default)
 * @param args_info the structure to initialize
 */
void cmdline_parser_init (struct gengetopt_args_info *args_info);
/**
 * Deallocates the string fields of the gengetopt_args_info structure
 * (but does not deallocate the structure itself)
 * @param args_info the structure to deallocate
 */
void cmdline_parser_free (struct gengetopt_args_info *args_info);

/**
 * The config file parser (deprecated version)
 * @param filename the name of the config file
 * @param args_info the structure where option information will be stored
 * @param override whether to override possibly already present options
 * @param initialize whether to initialize the option structure my_args_info
 * @param check_required whether to check that all required options were provided
 * @return 0 if everything went fine, NON 0 if an error took place
 * @deprecated use cmdline_parser_config_file() instead
 */
int cmdline_parser_configfile (const char *filename,
  struct gengetopt_args_info *args_info,
  int override, int initialize, int check_required);

/**
 * The config file parser
 * @param filename the name of the config file
 * @param args_info the structure where option information will be stored
 * @param params additional parameters for the parser
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_config_file (const char *filename,
  struct gengetopt_args_info *args_info,
  struct cmdline_parser_params *params);

/**
 * Checks that all the required options were specified
 * @param args_info the structure to check
 * @param prog_name the name of the program that will be used to print
 *   possible errors
 * @return
 */
int cmdline_parser_required (struct gengetopt_args_info *args_info,
  const char *prog_name);


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ADIMAT_CLIENT_OPTS_H */
