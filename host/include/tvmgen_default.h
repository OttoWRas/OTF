#ifndef TVMGEN_DEFAULT_H_
#define TVMGEN_DEFAULT_H_
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Input tensor Input3 size (in bytes) for TVM module "default" 
 */
#define TVMGEN_DEFAULT_INPUT3_SIZE 3136
/*!
 * \brief Output tensor output size (in bytes) for TVM module "default" 
 */
#define TVMGEN_DEFAULT_OUTPUT_SIZE 40
/*!
 * \brief Input tensor pointers for TVM module "default" 
 */
#define TVMGEN_DEFAULT_WORKSPACE_SIZE 31360

#ifdef __cplusplus
}
#endif

#endif // TVMGEN_DEFAULT_H_
