/**
 * @file codop.h
 *
 * Departamento de Informática de Sistemas y Computadores (DISCA)
 * Universidad Politécnica de Valencia.
 *
 * @author Sergio Sáez <ssaez@disca.upv.es>
 * @author Pedro López <plopez@disca.upv.es>
 *
 * @brief
 *    Contiene los códigos de las instrucciones implementadas
 *
 * DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN
 *
 * @copyright [CC BY-NC-ND 4.0]
 *   Esta obra está bajo una licencia de Creative Commons Atribución-NoComercial-SinDerivadas
 *   Para evitar dudas, no se tiene permiso bajo esta Licencia para compartir Material Adaptado.
 *   Más detalles en https://creativecommons.org/licenses/by-nc-nd/4.0/legalcode.es
 */

#ifndef codop_H
#define codop_H

/*** Includes **************************************************************/

#include "tipos.h"

/*** Defines ***************************************************************/

// Subformatos de instrucción
#define FMT_INT_RRI       0
#define FMT_INT_RRSH      1
#define FMT_INT_RI        2
#define FMT_INT_RA        3
#define FMT_INT_RRR       4
#define FMT_J_RA          5
#define FMT_J_RRA         6
#define FMT_INT_B_RRA     7
#define FMT_INT_L_RSB     8
#define FMT_INT_S_RSB     9
#define FMT_INT_RB        10
#define FMT_INT_RRB       11
#define FMT_CSR_RxR       12
#define FMT_CSR_RxI       13
#define FMT_INT_ECALL     14
#define FMT_INT_EBREAK    15
#define FMT_FP_L_FSB      16
#define FMT_FP_S_FSB      17
#define FMT_FP_FFFFr      18
#define FMT_FP_FFFr       19
#define FMT_FP_FFr        20
#define FMT_FP_FFF        21
#define FMT_FP_FF         22
#define FMT_FP_RFr        23
#define FMT_FP_RF         24
#define FMT_FP_RFF        25
#define FMT_FP_FRr        26
#define FMT_FP_FR         27

// Tipos de instrucción
#define INST_TYPE_nnnn         0
#define INST_TYPE_nLSn         1
#define INST_TYPE_nLLn         2
#define INST_TYPE_nLDn         3
#define INST_TYPE_SSnn         4
#define INST_TYPE_SSSn         5
#define INST_TYPE_SSSS         6
#define INST_TYPE_SLnn         7
#define INST_TYPE_Lnnn         8
#define INST_TYPE_LnLn         9
#define INST_TYPE_LSnn         10
#define INST_TYPE_LSSn         11
#define INST_TYPE_LLnn         12
#define INST_TYPE_LLLn         13
#define INST_TYPE_LDnn         14
#define INST_TYPE_LDDn         15
#define INST_TYPE_DLnn         16
#define INST_TYPE_DDnn         17
#define INST_TYPE_DDDn         18
#define INST_TYPE_DDDD         19

// Códigos de operación internos
#define RV32I_ADDI             0
#define RV32I_SLTI             1
#define RV32I_SLTIU            2
#define RV32I_ANDI             3
#define RV32I_ORI              4
#define RV32I_XORI             5
#define RV32I_LUI              6
#define RV32I_AUIPC            7
#define RV32I_ADD              8
#define RV32I_SUB              9
#define RV32I_AND              10
#define RV32I_SLT              11
#define RV32I_SLTU             12
#define RV32I_OR               13
#define RV32I_XOR              14
#define RV32I_SLL              15
#define RV32I_SRL              16
#define RV32I_SRA              17
#define RV32I_JAL              18
#define RV32I_JALR             19
#define RV32I_BEQ              20
#define RV32I_BNE              21
#define RV32I_BLT              22
#define RV32I_BLTU             23
#define RV32I_BGE              24
#define RV32I_BGEU             25
#define RV32I_LB               26
#define RV32I_LBU              27
#define RV32I_LH               28
#define RV32I_LHU              29
#define RV32I_LW               30
#define RV32I_SB               31
#define RV32I_SH               32
#define RV32I_SW               33
#define RV32I_CSRRW            34
#define RV32I_CSRRS            35
#define RV32I_CSRRC            36
#define RV32I_CSRRWI           37
#define RV32I_CSRRSI           38
#define RV32I_CSRRCI           39
#define RV32I_ECALL            40
#define RV32I_EBREAK           41
#define RV32M_MUL              42
#define RV32M_MULH             43
#define RV32M_MULHSU           44
#define RV32M_MULHU            45
#define RV32M_DIV              46
#define RV32M_DIVU             47
#define RV32M_REM              48
#define RV32M_REMU             49
#define RV32F_FLW              50
#define RV32F_FSW              51
#define RV32F_FMADD_S          52
#define RV32F_FMSUB_S          53
#define RV32F_FNMSUB_S         54
#define RV32F_FNMADD_S         55
#define RV32F_FADD_S           56
#define RV32F_FSUB_S           57
#define RV32F_FMUL_S           58
#define RV32F_FDIV_S           59
#define RV32F_FSQRT_S          60
#define RV32F_FSGNJ_S          61
#define RV32F_FSGNJN_S         62
#define RV32F_FSGNJX_S         63
#define RV32F_FMIN_S           64
#define RV32F_FMAX_S           65
#define RV32F_FCVT_W_S         66
#define RV32F_FCVT_WU_S        67
#define RV32F_FMV_X_W          68
#define RV32F_FEQ_S            69
#define RV32F_FLT_S            70
#define RV32F_FLE_S            71
#define RV32F_FCLASS_S         72
#define RV32F_FCVT_S_W         73
#define RV32F_FCVT_S_WU        74
#define RV32F_FMV_W_X          75
#define RV32D_FLD              76
#define RV32D_FSD              77
#define RV32D_FMADD_D          78
#define RV32D_FMSUB_D          79
#define RV32D_FNMSUB_D         80
#define RV32D_FNMADD_D         81
#define RV32D_FADD_D           82
#define RV32D_FSUB_D           83
#define RV32D_FMUL_D           84
#define RV32D_FDIV_D           85
#define RV32D_FSQRT_D          86
#define RV32D_FSGNJ_D          87
#define RV32D_FSGNJN_D         88
#define RV32D_FSGNJX_D         89
#define RV32D_FMIN_D           90
#define RV32D_FMAX_D           91
#define RV32D_FCVT_S_D         92
#define RV32D_FCVT_D_S         93
#define RV32D_FEQ_D            94
#define RV32D_FLT_D            95
#define RV32D_FLE_D            96
#define RV32D_FCLASS_D         97
#define RV32D_FCVT_W_D         98
#define RV32D_FCVT_WU_D        99
#define RV32D_FCVT_D_W         100
#define RV32D_FCVT_D_WU        101
#define RV32A_LR_W             102
#define RV32A_SC_W             103
#define RV32A_AMOSWAP_W        104
#define RV32A_AMOADD_W         105
#define RV32A_AMOXOR_W         106
#define RV32A_AMOAND_W         107
#define RV32A_AMOOR_W          108
#define RV32A_AMOMIN_W         109
#define RV32A_AMOMAX_W         110
#define RV32A_AMOMINU_W        111
#define RV32A_AMOMAXU_W        112
#define RV32A_LR_W_AQ          113
#define RV32A_SC_W_AQ          114
#define RV32A_AMOSWAP_W_AQ     115
#define RV32A_AMOADD_W_AQ      116
#define RV32A_AMOXOR_W_AQ      117
#define RV32A_AMOAND_W_AQ      118
#define RV32A_AMOOR_W_AQ       119
#define RV32A_AMOMIN_W_AQ      120
#define RV32A_AMOMAX_W_AQ      121
#define RV32A_AMOMINU_W_AQ     122
#define RV32A_AMOMAXU_W_AQ     123
#define RV32A_LR_W_RL          124
#define RV32A_SC_W_RL          125
#define RV32A_AMOSWAP_W_RL     126
#define RV32A_AMOADD_W_RL      127
#define RV32A_AMOXOR_W_RL      128
#define RV32A_AMOAND_W_RL      129
#define RV32A_AMOOR_W_RL       130
#define RV32A_AMOMIN_W_RL      131
#define RV32A_AMOMAX_W_RL      132
#define RV32A_AMOMINU_W_RL     133
#define RV32A_AMOMAXU_W_RL     134
#define RV32A_LR_W_AQRL        135
#define RV32A_SC_W_AQRL        136
#define RV32A_AMOSWAP_W_AQRL   137
#define RV32A_AMOADD_W_AQRL    138
#define RV32A_AMOXOR_W_AQRL    139
#define RV32A_AMOAND_W_AQRL    140
#define RV32A_AMOOR_W_AQRL     141
#define RV32A_AMOMIN_W_AQRL    142
#define RV32A_AMOMAX_W_AQRL    143
#define RV32A_AMOMINU_W_AQRL   144
#define RV32A_AMOMAXU_W_AQRL   145
#define RV64I_LWU              146
#define RV64I_LD               147
#define RV64I_SD               148
#define RV64I_ADDIW            149
#define RV64I_SLLI             150
#define RV64I_SRLI             151
#define RV64I_SRAI             152
#define RV64I_SLLIW            153
#define RV64I_SRLIW            154
#define RV64I_SRAIW            155
#define RV64I_ADDW             156
#define RV64I_SUBW             157
#define RV64I_SLLW             158
#define RV64I_SRLW             159
#define RV64I_SRAW             160
#define RV64M_MULW             161
#define RV64M_DIVW             162
#define RV64M_DIVUW            163
#define RV64M_REMW             164
#define RV64M_REMUW            165
#define RV64A_LR_D             166
#define RV64A_SC_D             167
#define RV64A_AMOSWAP_D        168
#define RV64A_AMOADD_D         169
#define RV64A_AMOXOR_D         170
#define RV64A_AMOAND_D         171
#define RV64A_AMOOR_D          172
#define RV64A_AMOMIN_D         173
#define RV64A_AMOMAX_D         174
#define RV64A_AMOMINU_D        175
#define RV64A_AMOMAXU_D        176
#define RV64A_LR_D_AQ          177
#define RV64A_SC_D_AQ          178
#define RV64A_AMOSWAP_D_AQ     179
#define RV64A_AMOADD_D_AQ      180
#define RV64A_AMOXOR_D_AQ      181
#define RV64A_AMOAND_D_AQ      182
#define RV64A_AMOOR_D_AQ       183
#define RV64A_AMOMIN_D_AQ      184
#define RV64A_AMOMAX_D_AQ      185
#define RV64A_AMOMINU_D_AQ     186
#define RV64A_AMOMAXU_D_AQ     187
#define RV64A_LR_D_RL          188
#define RV64A_SC_D_RL          189
#define RV64A_AMOSWAP_D_RL     190
#define RV64A_AMOADD_D_RL      191
#define RV64A_AMOXOR_D_RL      192
#define RV64A_AMOAND_D_RL      193
#define RV64A_AMOOR_D_RL       194
#define RV64A_AMOMIN_D_RL      195
#define RV64A_AMOMAX_D_RL      196
#define RV64A_AMOMINU_D_RL     197
#define RV64A_AMOMAXU_D_RL     198
#define RV64A_LR_D_AQRL        199
#define RV64A_SC_D_AQRL        200
#define RV64A_AMOSWAP_D_AQRL   201
#define RV64A_AMOADD_D_AQRL    202
#define RV64A_AMOXOR_D_AQRL    203
#define RV64A_AMOAND_D_AQRL    204
#define RV64A_AMOOR_D_AQRL     205
#define RV64A_AMOMIN_D_AQRL    206
#define RV64A_AMOMAX_D_AQRL    207
#define RV64A_AMOMINU_D_AQRL   208
#define RV64A_AMOMAXU_D_AQRL   209
#define RV64F_FCVT_L_S         210
#define RV64F_FCVT_LU_S        211
#define RV64F_FCVT_S_L         212
#define RV64F_FCVT_S_LU        213
#define RV64D_FCVT_L_D         214
#define RV64D_FCVT_LU_D        215
#define RV64D_FMV_X_D          216
#define RV64D_FCVT_D_L         217
#define RV64D_FCVT_D_LU        218
#define RV64D_FMV_D_X          219
#define PSEUDO_NOP             220
#define PSEUDO_NEG             221
#define PSEUDO_NEGW            222
#define PSEUDO_SNEZ            223
#define PSEUDO_SLTZ            224
#define PSEUDO_SGTZ            225
#define PSEUDO_BEQZ            226
#define PSEUDO_BNEZ            227
#define PSEUDO_BLEZ            228
#define PSEUDO_BGEZ            229
#define PSEUDO_BLTZ            230
#define PSEUDO_BGTZ            231
#define PSEUDO_J               232
#define PSEUDO_JR              233
#define PSEUDO_RET             234
#define PSEUDO_TAIL            235
#define PSEUDO_RDINSRET        236
#define PSEUDO_RDINSRETH       237
#define PSEUDO_RDCYCLE         238
#define PSEUDO_RDCYCLEH        239
#define PSEUDO_RDTIME          240
#define PSEUDO_RDTIMEH         241
#define PSEUDO_LLA             242
#define PSEUDO_LA              243
#define PSEUDO_LI              244
#define PSEUDO_MV              245
#define PSEUDO_NOT             246
#define PSEUDO_SEXT_W          247
#define PSEUDO_SEQZ            248
#define PSEUDO_FMV_S           249
#define PSEUDO_FABS_S          250
#define PSEUDO_FNEG_S          251
#define PSEUDO_FMV_D           252
#define PSEUDO_FABS_D          253
#define PSEUDO_FNEG_D          254
#define PSEUDO_BGT             255
#define PSEUDO_BLE             256
#define PSEUDO_BGTU            257
#define PSEUDO_BLEU            258
#define PSEUDO_CALL            259
#define PSEUDO_TRAP            260

/*** Macros ****************************************************************/

#define SET(i) (instruction_list[i].set)
#define PRINTED(i) (instruction_list[i].print)
#define FORMAT(i) (instruction_list[i].format)
#define DECODE(i) (instruction_list[i].decode)
#define OPCODE(i) (instruction_list[i].decode.opcode)
#define FUNC3(i) (instruction_list[i].decode.funct3)
#define FUNC7(i) (instruction_list[i].decode.funct7)
#define FUNC5(i) (instruction_list[i].decode.funct5)

#define TIPOS(i) (inst_types_list[instruction_list[i].type])

/*** Tipos *****************************************************************/

typedef struct {
    unsigned int opcode: 7;
    unsigned int _pad1 : 5;
    unsigned int funct3: 3;
    unsigned int _pad2 : 5;
    unsigned int funct5: 5;
    unsigned int funct7: 7;
} format_decode_type;

typedef struct {
    tipo_t result;
    tipo_t Rfte1;
    tipo_t Rfte2;
    tipo_t Rfte3;
} inst_types_t;

typedef struct {
    int set;
    char nemo[15];
    char print[15];
    formato_t format;
    unsigned int type;
    format_decode_type decode;
} inst_fmt_t;

/*** Definiciones externas *************************************************/

#ifndef codop_C

extern inst_fmt_t instruction_list[];
extern inst_types_t inst_types_list[];

codop_t obtener_decodificacion(
    dword PC, format_decode_type decode,
    char **p_nemo, int *p_subfmt, formato_t *p_format
);

#endif

#endif /* Include codop.h */
