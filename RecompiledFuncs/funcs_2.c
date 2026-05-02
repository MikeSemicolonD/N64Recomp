#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void fake_func_8000595C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80005960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005960: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80005964: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80005968: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8000596C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80005970: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_80005974:
    // 0x80005974: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_80005978:
    // 0x80005978: lw          $v0, 0x26E4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X26E4);
    // 0x8000597C: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80005980: srav        $v0, $v0, $s1
    ctx->r2 = S32(SIGNED(ctx->r2) >> (ctx->r17 & 31));
    // 0x80005984: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80005988: beq         $v0, $zero, L_80005B64
    if (ctx->r2 == 0) {
        // 0x8000598C: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_80005B64;
    }
    // 0x8000598C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80005990: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005994: lw          $v1, 0x26E8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X26E8);
    // 0x80005998: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x8000599C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800059A0: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800059A4: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x800059A8: andi        $v0, $v0, 0x5
    ctx->r2 = ctx->r2 & 0X5;
    // 0x800059AC: bne         $v0, $v1, L_80005B48
    if (ctx->r2 != ctx->r3) {
        // 0x800059B0: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80005B48;
    }
    // 0x800059B0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800059B4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800059B8: lw          $a0, 0x26E0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X26E0);
    // 0x800059BC: sll         $a1, $s1, 1
    ctx->r5 = S32(ctx->r17 << 1);
    // 0x800059C0: addu        $a1, $a1, $s1
    ctx->r5 = ADD32(ctx->r5, ctx->r17);
    // 0x800059C4: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x800059C8: addu        $a1, $a1, $s1
    ctx->r5 = ADD32(ctx->r5, ctx->r17);
    // 0x800059CC: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x800059D0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800059D4: addiu       $v0, $v0, 0x2730
    ctx->r2 = ADD32(ctx->r2, 0X2730);
    // 0x800059D8: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800059DC: jal         0x80030AA0
    // 0x800059E0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    osPfsInitPak_recomp(rdram, ctx);
        goto after_0;
    // 0x800059E0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_0:
    // 0x800059E4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800059E8: sltiu       $v0, $v1, 0xC
    ctx->r2 = ctx->r3 < 0XC ? 1 : 0;
    // 0x800059EC: beq         $v0, $zero, L_80005B0C
    if (ctx->r2 == 0) {
        // 0x800059F0: lui         $v0, 0x8000
        ctx->r2 = S32(0X8000 << 16);
            goto L_80005B0C;
    }
    // 0x800059F0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800059F4: addiu       $v0, $v0, 0x480
    ctx->r2 = ADD32(ctx->r2, 0X480);
    // 0x800059F8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800059FC: addu        $v1, $v1, $v0
    gpr jr_addend_80005A04 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80005A00: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x80005A04: jr          $v0
    // 0x80005A08: nop

    switch (jr_addend_80005A04 >> 2) {
        case 0: goto L_80005AE4; break;
        case 1: goto L_80005A0C; break;
        case 2: goto L_80005A60; break;
        case 3: goto L_80005B0C; break;
        case 4: goto L_80005A68; break;
        case 5: goto L_80005B0C; break;
        case 6: goto L_80005B0C; break;
        case 7: goto L_80005B0C; break;
        case 8: goto L_80005B0C; break;
        case 9: goto L_80005B0C; break;
        case 10: goto L_80005A70; break;
        case 11: goto L_80005AEC; break;
        default: switch_error(__func__, 0x80005A04, 0x80000480);
    }
    // 0x80005A08: nop

L_80005A0C:
    // 0x80005A0C: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80005A10: lw          $a0, 0x26E0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X26E0);
    // 0x80005A14: jal         0x8002AB80
    // 0x80005A18: nop

    osContStartQuery_recomp(rdram, ctx);
        goto after_1;
    // 0x80005A18: nop

    after_1:
    // 0x80005A1C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80005A20: lw          $a0, 0x26E0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X26E0);
    // 0x80005A24: jal         0x800331D0
    // 0x80005A28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80005A28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80005A2C: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80005A30: lw          $a0, 0x26E8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X26E8);
    // 0x80005A34: jal         0x8002AC04
    // 0x80005A38: nop

    osContGetQuery_recomp(rdram, ctx);
        goto after_3;
    // 0x80005A38: nop

    after_3:
    // 0x80005A3C: lw          $v1, 0x26E8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X26E8);
    // 0x80005A40: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x80005A44: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80005A48: lbu         $v1, 0x3($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X3);
    // 0x80005A4C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80005A50: beq         $v1, $v0, L_80005B64
    if (ctx->r3 == ctx->r2) {
        // 0x80005A54: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_80005B64;
    }
    // 0x80005A54: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80005A58: j           L_80005B10
    // 0x80005A5C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
        goto L_80005B10;
    // 0x80005A5C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_80005A60:
    // 0x80005A60: j           L_80005B0C
    // 0x80005A64: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
        goto L_80005B0C;
    // 0x80005A64: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
L_80005A68:
    // 0x80005A68: j           L_80005B0C
    // 0x80005A6C: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
        goto L_80005B0C;
    // 0x80005A6C: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
L_80005A70:
    // 0x80005A70: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005A74: lw          $v0, 0x26F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X26F0);
    // 0x80005A78: beq         $v0, $zero, L_80005A8C
    if (ctx->r2 == 0) {
        // 0x80005A7C: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80005A8C;
    }
    // 0x80005A7C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80005A80: jalr        $v0
    // 0x80005A84: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x80005A84: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_4:
    // 0x80005A88: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_80005A8C:
    // 0x80005A8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80005A90: beq         $v1, $v0, L_80005974
    if (ctx->r3 == ctx->r2) {
        // 0x80005A94: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80005974;
    }
    // 0x80005A94: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80005A98: beq         $v0, $zero, L_80005AB0
    if (ctx->r2 == 0) {
        // 0x80005A9C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80005AB0;
    }
    // 0x80005A9C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80005AA0: beq         $v1, $zero, L_80005AE4
    if (ctx->r3 == 0) {
        // 0x80005AA4: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80005AE4;
    }
    // 0x80005AA4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005AA8: j           L_80005B10
    // 0x80005AAC: nop

        goto L_80005B10;
    // 0x80005AAC: nop

L_80005AB0:
    // 0x80005AB0: bnel        $v1, $v0, L_80005B10
    if (ctx->r3 != ctx->r2) {
        // 0x80005AB4: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80005B10;
    }
    goto skip_0;
    // 0x80005AB4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    skip_0:
    // 0x80005AB8: sll         $a0, $s1, 1
    ctx->r4 = S32(ctx->r17 << 1);
    // 0x80005ABC: addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    // 0x80005AC0: sllv        $a0, $a0, $v0
    ctx->r4 = S32(ctx->r4 << (ctx->r2 & 31));
    // 0x80005AC4: addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    // 0x80005AC8: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80005ACC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005AD0: addiu       $v0, $v0, 0x2730
    ctx->r2 = ADD32(ctx->r2, 0X2730);
    // 0x80005AD4: jal         0x80032000
    // 0x80005AD8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    osPfsRepairId_recomp(rdram, ctx);
        goto after_5;
    // 0x80005AD8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_5:
    // 0x80005ADC: j           L_80005978
    // 0x80005AE0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
        goto L_80005978;
    // 0x80005AE0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_80005AE4:
    // 0x80005AE4: j           L_80005B88
    // 0x80005AE8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80005B88;
    // 0x80005AE8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80005AEC:
    // 0x80005AEC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005AF0: lw          $v0, 0x26F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X26F0);
    // 0x80005AF4: beql        $v0, $zero, L_80005B88
    if (ctx->r2 == 0) {
        // 0x80005AF8: addiu       $v0, $zero, 0xD
        ctx->r2 = ADD32(0, 0XD);
            goto L_80005B88;
    }
    goto skip_1;
    // 0x80005AF8: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    skip_1:
    // 0x80005AFC: jalr        $v0
    // 0x80005B00: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x80005B00: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_6:
    // 0x80005B04: j           L_80005B88
    // 0x80005B08: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
        goto L_80005B88;
    // 0x80005B08: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_80005B0C:
    // 0x80005B0C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_80005B10:
    // 0x80005B10: lw          $v0, 0x26F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X26F0);
    // 0x80005B14: beq         $v0, $zero, L_80005B28
    if (ctx->r2 == 0) {
        // 0x80005B18: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80005B28;
    }
    // 0x80005B18: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80005B1C: jalr        $v0
    // 0x80005B20: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_7;
    // 0x80005B20: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
    // 0x80005B24: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_80005B28:
    // 0x80005B28: beq         $v1, $zero, L_80005B88
    if (ctx->r3 == 0) {
        // 0x80005B2C: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_80005B88;
    }
    // 0x80005B2C: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x80005B30: bltz        $v1, L_80005B84
    if (SIGNED(ctx->r3) < 0) {
        // 0x80005B34: slti        $v0, $v1, 0x3
        ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_80005B84;
    }
    // 0x80005B34: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x80005B38: beq         $v0, $zero, L_80005B84
    if (ctx->r2 == 0) {
        // 0x80005B3C: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80005B84;
    }
    // 0x80005B3C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005B40: j           L_80005978
    // 0x80005B44: nop

        goto L_80005978;
    // 0x80005B44: nop

L_80005B48:
    // 0x80005B48: lw          $v0, 0x26F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X26F0);
    // 0x80005B4C: beql        $v0, $zero, L_80005B88
    if (ctx->r2 == 0) {
        // 0x80005B50: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_80005B88;
    }
    goto skip_2;
    // 0x80005B50: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    skip_2:
    // 0x80005B54: jalr        $v0
    // 0x80005B58: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_8;
    // 0x80005B58: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_8:
    // 0x80005B5C: j           L_80005B88
    // 0x80005B60: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_80005B88;
    // 0x80005B60: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_80005B64:
    // 0x80005B64: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005B68: lw          $v0, 0x26F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X26F0);
    // 0x80005B6C: beql        $v0, $zero, L_80005B88
    if (ctx->r2 == 0) {
        // 0x80005B70: addiu       $v0, $zero, 0xB
        ctx->r2 = ADD32(0, 0XB);
            goto L_80005B88;
    }
    goto skip_3;
    // 0x80005B70: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    skip_3:
    // 0x80005B74: jalr        $v0
    // 0x80005B78: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_9;
    // 0x80005B78: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_9:
    // 0x80005B7C: j           L_80005B88
    // 0x80005B80: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_80005B88;
    // 0x80005B80: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_80005B84:
    // 0x80005B84: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80005B88:
    // 0x80005B88: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80005B8C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80005B90: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80005B94: jr          $ra
    // 0x80005B98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80005B98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80005B9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005B9C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80005BA0: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80005BA4: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80005BA8: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80005BAC: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x80005BB0: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80005BB4: addu        $s7, $a1, $zero
    ctx->r23 = ADD32(ctx->r5, 0);
    // 0x80005BB8: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80005BBC: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80005BC0: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80005BC4: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80005BC8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80005BCC: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80005BD0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80005BD4: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80005BD8: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
L_80005BDC:
    // 0x80005BDC: jal         0x80005960
    // 0x80005BE0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    func_80005960(rdram, ctx);
        goto after_0;
    // 0x80005BE0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_0:
    // 0x80005BE4: addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    // 0x80005BE8: bne         $s6, $zero, L_80005EE8
    if (ctx->r22 != 0) {
        // 0x80005BEC: addu        $v0, $s6, $zero
        ctx->r2 = ADD32(ctx->r22, 0);
            goto L_80005EE8;
    }
    // 0x80005BEC: addu        $v0, $s6, $zero
    ctx->r2 = ADD32(ctx->r22, 0);
    // 0x80005BF0: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80005BF4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80005BF8: jal         0x800078E0
    // 0x80005BFC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x80005BFC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80005C00: beq         $s7, $zero, L_80005C10
    if (ctx->r23 == 0) {
        // 0x80005C04: addiu       $v0, $s7, 0x11
        ctx->r2 = ADD32(ctx->r23, 0X11);
            goto L_80005C10;
    }
    // 0x80005C04: addiu       $v0, $s7, 0x11
    ctx->r2 = ADD32(ctx->r23, 0X11);
    // 0x80005C08: j           L_80005C14
    // 0x80005C0C: sb          $v0, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r2;
        goto L_80005C14;
    // 0x80005C0C: sb          $v0, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r2;
L_80005C10:
    // 0x80005C10: sb          $zero, 0x20($sp)
    MEM_B(0X20, ctx->r29) = 0;
L_80005C14:
    // 0x80005C14: addiu       $v1, $fp, 0x117
    ctx->r3 = ADD32(ctx->r30, 0X117);
    // 0x80005C18: addiu       $v0, $zero, -0x100
    ctx->r2 = ADD32(0, -0X100);
    // 0x80005C1C: and         $s5, $v1, $v0
    ctx->r21 = ctx->r3 & ctx->r2;
L_80005C20:
    // 0x80005C20: sll         $a0, $s4, 1
    ctx->r4 = S32(ctx->r20 << 1);
L_80005C24:
    // 0x80005C24: addu        $a0, $a0, $s4
    ctx->r4 = ADD32(ctx->r4, ctx->r20);
    // 0x80005C28: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80005C2C: addu        $a0, $a0, $s4
    ctx->r4 = ADD32(ctx->r4, ctx->r20);
    // 0x80005C30: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80005C34: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005C38: addiu       $v0, $v0, 0x2730
    ctx->r2 = ADD32(ctx->r2, 0X2730);
    // 0x80005C3C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80005C40: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005C44: addiu       $v1, $v0, 0x26C0
    ctx->r3 = ADD32(ctx->r2, 0X26C0);
    // 0x80005C48: addiu       $a3, $v1, 0x10
    ctx->r7 = ADD32(ctx->r3, 0X10);
    // 0x80005C4C: lw          $a2, 0x26C0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X26C0);
    // 0x80005C50: addiu       $v0, $sp, 0x20
    ctx->r2 = ADD32(ctx->r29, 0X20);
    // 0x80005C54: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80005C58: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // 0x80005C5C: lhu         $a1, 0xC($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0XC);
    // 0x80005C60: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x80005C64: jal         0x8002EBE0
    // 0x80005C68: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    osPfsAllocateFile_recomp(rdram, ctx);
        goto after_2;
    // 0x80005C68: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x80005C6C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80005C70: sltiu       $v0, $v1, 0xA
    ctx->r2 = ctx->r3 < 0XA ? 1 : 0;
    // 0x80005C74: beq         $v0, $zero, L_80005D24
    if (ctx->r2 == 0) {
        // 0x80005C78: lui         $v0, 0x8000
        ctx->r2 = S32(0X8000 << 16);
            goto L_80005D24;
    }
    // 0x80005C78: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80005C7C: addiu       $v0, $v0, 0x4B0
    ctx->r2 = ADD32(ctx->r2, 0X4B0);
    // 0x80005C80: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80005C84: addu        $v1, $v1, $v0
    gpr jr_addend_80005C8C = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80005C88: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x80005C8C: jr          $v0
    // 0x80005C90: nop

    switch (jr_addend_80005C8C >> 2) {
        case 0: goto L_80005C94; break;
        case 1: goto L_80005C9C; break;
        case 2: goto L_80005D08; break;
        case 3: goto L_80005D10; break;
        case 4: goto L_80005D10; break;
        case 5: goto L_80005D10; break;
        case 6: goto L_80005D24; break;
        case 7: goto L_80005D18; break;
        case 8: goto L_80005D18; break;
        case 9: goto L_80005D20; break;
        default: switch_error(__func__, 0x80005C8C, 0x800004B0);
    }
    // 0x80005C90: nop

L_80005C94:
    // 0x80005C94: j           L_80005D24
    // 0x80005C98: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
        goto L_80005D24;
    // 0x80005C98: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_80005C9C:
    // 0x80005C9C: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80005CA0: lw          $a0, 0x26E0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X26E0);
    // 0x80005CA4: jal         0x8002AB80
    // 0x80005CA8: nop

    osContStartQuery_recomp(rdram, ctx);
        goto after_3;
    // 0x80005CA8: nop

    after_3:
    // 0x80005CAC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80005CB0: lw          $a0, 0x26E0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X26E0);
    // 0x80005CB4: jal         0x800331D0
    // 0x80005CB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x80005CB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80005CBC: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80005CC0: lw          $a0, 0x26E8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X26E8);
    // 0x80005CC4: jal         0x8002AC04
    // 0x80005CC8: nop

    osContGetQuery_recomp(rdram, ctx);
        goto after_5;
    // 0x80005CC8: nop

    after_5:
    // 0x80005CCC: lw          $v1, 0x26E8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X26E8);
    // 0x80005CD0: sll         $v0, $s4, 2
    ctx->r2 = S32(ctx->r20 << 2);
    // 0x80005CD4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80005CD8: lbu         $v1, 0x3($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X3);
    // 0x80005CDC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80005CE0: bne         $v1, $v0, L_80005D24
    if (ctx->r3 != ctx->r2) {
        // 0x80005CE4: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_80005D24;
    }
    // 0x80005CE4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80005CE8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005CEC: lw          $v0, 0x26F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X26F0);
    // 0x80005CF0: beql        $v0, $zero, L_80005EE8
    if (ctx->r2 == 0) {
        // 0x80005CF4: addiu       $v0, $zero, 0xB
        ctx->r2 = ADD32(0, 0XB);
            goto L_80005EE8;
    }
    goto skip_0;
    // 0x80005CF4: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    skip_0:
    // 0x80005CF8: jalr        $v0
    // 0x80005CFC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x80005CFC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_6:
    // 0x80005D00: j           L_80005EE8
    // 0x80005D04: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_80005EE8;
    // 0x80005D04: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_80005D08:
    // 0x80005D08: j           L_80005D24
    // 0x80005D0C: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
        goto L_80005D24;
    // 0x80005D0C: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
L_80005D10:
    // 0x80005D10: j           L_80005D24
    // 0x80005D14: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
        goto L_80005D24;
    // 0x80005D14: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
L_80005D18:
    // 0x80005D18: j           L_80005D24
    // 0x80005D1C: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
        goto L_80005D24;
    // 0x80005D1C: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
L_80005D20:
    // 0x80005D20: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
L_80005D24:
    // 0x80005D24: beq         $s0, $zero, L_80005DE4
    if (ctx->r16 == 0) {
        // 0x80005D28: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80005DE4;
    }
    // 0x80005D28: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005D2C: lw          $v0, 0x26F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X26F0);
    // 0x80005D30: beq         $v0, $zero, L_80005D44
    if (ctx->r2 == 0) {
        // 0x80005D34: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80005D44;
    }
    // 0x80005D34: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80005D38: jalr        $v0
    // 0x80005D3C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_7;
    // 0x80005D3C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
    // 0x80005D40: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_80005D44:
    // 0x80005D44: addiu       $v1, $s0, -0x1
    ctx->r3 = ADD32(ctx->r16, -0X1);
    // 0x80005D48: sltiu       $v0, $v1, 0x9
    ctx->r2 = ctx->r3 < 0X9 ? 1 : 0;
    // 0x80005D4C: beq         $v0, $zero, L_80005EDC
    if (ctx->r2 == 0) {
        // 0x80005D50: lui         $v0, 0x8000
        ctx->r2 = S32(0X8000 << 16);
            goto L_80005EDC;
    }
    // 0x80005D50: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80005D54: addiu       $v0, $v0, 0x4D8
    ctx->r2 = ADD32(ctx->r2, 0X4D8);
    // 0x80005D58: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80005D5C: addu        $v1, $v1, $v0
    gpr jr_addend_80005D64 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80005D60: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x80005D64: jr          $v0
    // 0x80005D68: nop

    switch (jr_addend_80005D64 >> 2) {
        case 0: goto L_80005D6C; break;
        case 1: goto L_80005EDC; break;
        case 2: goto L_80005EDC; break;
        case 3: goto L_80005EDC; break;
        case 4: goto L_80005EDC; break;
        case 5: goto L_80005D7C; break;
        case 6: goto L_80005ED4; break;
        case 7: goto L_80005EDC; break;
        case 8: goto L_80005D6C; break;
        default: switch_error(__func__, 0x80005D64, 0x800004D8);
    }
    // 0x80005D68: nop

L_80005D6C:
    // 0x80005D6C: bne         $a0, $zero, L_80005C24
    if (ctx->r4 != 0) {
        // 0x80005D70: sll         $a0, $s4, 1
        ctx->r4 = S32(ctx->r20 << 1);
            goto L_80005C24;
    }
    // 0x80005D70: sll         $a0, $s4, 1
    ctx->r4 = S32(ctx->r20 << 1);
    // 0x80005D74: j           L_80005EE8
    // 0x80005D78: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
        goto L_80005EE8;
    // 0x80005D78: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80005D7C:
    // 0x80005D7C: beq         $a0, $zero, L_80005EDC
    if (ctx->r4 == 0) {
        // 0x80005D80: sll         $a0, $s4, 1
        ctx->r4 = S32(ctx->r20 << 1);
            goto L_80005EDC;
    }
    // 0x80005D80: sll         $a0, $s4, 1
    ctx->r4 = S32(ctx->r20 << 1);
    // 0x80005D84: addu        $a0, $a0, $s4
    ctx->r4 = ADD32(ctx->r4, ctx->r20);
    // 0x80005D88: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80005D8C: addu        $a0, $a0, $s4
    ctx->r4 = ADD32(ctx->r4, ctx->r20);
    // 0x80005D90: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80005D94: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005D98: addiu       $v0, $v0, 0x2730
    ctx->r2 = ADD32(ctx->r2, 0X2730);
    // 0x80005D9C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80005DA0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005DA4: addiu       $v1, $v0, 0x26C0
    ctx->r3 = ADD32(ctx->r2, 0X26C0);
    // 0x80005DA8: addiu       $a3, $v1, 0x10
    ctx->r7 = ADD32(ctx->r3, 0X10);
    // 0x80005DAC: lw          $a2, 0x26C0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X26C0);
    // 0x80005DB0: lhu         $a1, 0xC($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0XC);
    // 0x80005DB4: addiu       $v0, $sp, 0x20
    ctx->r2 = ADD32(ctx->r29, 0X20);
    // 0x80005DB8: jal         0x800300F0
    // 0x80005DBC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    osPfsDeleteFile_recomp(rdram, ctx);
        goto after_8;
    // 0x80005DBC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_8:
    // 0x80005DC0: beq         $v0, $zero, L_80005C20
    if (ctx->r2 == 0) {
        // 0x80005DC4: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80005C20;
    }
    // 0x80005DC4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005DC8: lw          $v0, 0x26F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X26F0);
    // 0x80005DCC: beq         $v0, $zero, L_80005EDC
    if (ctx->r2 == 0) {
        // 0x80005DD0: addiu       $s0, $zero, 0x5
        ctx->r16 = ADD32(0, 0X5);
            goto L_80005EDC;
    }
    // 0x80005DD0: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
    // 0x80005DD4: jalr        $v0
    // 0x80005DD8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_9;
    // 0x80005DD8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_9:
    // 0x80005DDC: j           L_80005EE8
    // 0x80005DE0: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
        goto L_80005EE8;
    // 0x80005DE0: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80005DE4:
    // 0x80005DE4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80005DE8: lui         $s3, 0x8011
    ctx->r19 = S32(0X8011 << 16);
    // 0x80005DEC: lw          $s1, 0x2724($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X2724);
    // 0x80005DF0: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x80005DF4: jal         0x800078E0
    // 0x80005DF8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    rs_memset(rdram, ctx);
        goto after_10;
    // 0x80005DF8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_10:
    // 0x80005DFC: addiu       $s2, $s1, 0x18
    ctx->r18 = ADD32(ctx->r17, 0X18);
    // 0x80005E00: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80005E04: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80005E08: jal         0x800346F0
    // 0x80005E0C: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    memcpy_recomp(rdram, ctx);
        goto after_11;
    // 0x80005E0C: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    after_11:
    // 0x80005E10: addiu       $s0, $s1, 0x8
    ctx->r16 = ADD32(ctx->r17, 0X8);
    // 0x80005E14: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80005E18: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80005E1C: jal         0x800346F0
    // 0x80005E20: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    memcpy_recomp(rdram, ctx);
        goto after_12;
    // 0x80005E20: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_12:
    // 0x80005E24: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80005E28: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80005E2C: jal         0x800269B0
    // 0x80005E30: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    adler32(rdram, ctx);
        goto after_13;
    // 0x80005E30: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_13:
    // 0x80005E34: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80005E38: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80005E3C: jal         0x800269B0
    // 0x80005E40: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    adler32(rdram, ctx);
        goto after_14;
    // 0x80005E40: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_14:
    // 0x80005E44: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80005E48: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80005E4C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80005E50: jal         0x800269B0
    // 0x80005E54: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    adler32(rdram, ctx);
        goto after_15;
    // 0x80005E54: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    after_15:
    // 0x80005E58: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80005E5C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005E60: lw          $a2, 0x26C8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X26C8);
    // 0x80005E64: jal         0x800269B0
    // 0x80005E68: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    adler32(rdram, ctx);
        goto after_16;
    // 0x80005E68: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_16:
    // 0x80005E6C: sll         $a0, $s4, 1
    ctx->r4 = S32(ctx->r20 << 1);
    // 0x80005E70: addu        $a0, $a0, $s4
    ctx->r4 = ADD32(ctx->r4, ctx->r20);
    // 0x80005E74: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80005E78: addu        $a0, $a0, $s4
    ctx->r4 = ADD32(ctx->r4, ctx->r20);
    // 0x80005E7C: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80005E80: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80005E84: addiu       $v1, $v1, 0x2730
    ctx->r3 = ADD32(ctx->r3, 0X2730);
    // 0x80005E88: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80005E8C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80005E90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80005E94: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80005E98: lw          $v0, 0x2724($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X2724);
    // 0x80005E9C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80005EA0: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80005EA4: jal         0x80031BDC
    // 0x80005EA8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    osPfsReadWriteFile_recomp(rdram, ctx);
        goto after_17;
    // 0x80005EA8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_17:
    // 0x80005EAC: beq         $v0, $zero, L_80005EE4
    if (ctx->r2 == 0) {
        // 0x80005EB0: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80005EE4;
    }
    // 0x80005EB0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005EB4: lw          $v0, 0x26F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X26F0);
    // 0x80005EB8: beq         $v0, $zero, L_80005ED0
    if (ctx->r2 == 0) {
        // 0x80005EBC: addiu       $s0, $zero, 0x5
        ctx->r16 = ADD32(0, 0X5);
            goto L_80005ED0;
    }
    // 0x80005EBC: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
    // 0x80005EC0: jalr        $v0
    // 0x80005EC4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_18;
    // 0x80005EC4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_18:
    // 0x80005EC8: j           L_80005ED4
    // 0x80005ECC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
        goto L_80005ED4;
    // 0x80005ECC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_80005ED0:
    // 0x80005ED0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80005ED4:
    // 0x80005ED4: bne         $a0, $zero, L_80005BDC
    if (ctx->r4 != 0) {
        // 0x80005ED8: nop
    
            goto L_80005BDC;
    }
    // 0x80005ED8: nop

L_80005EDC:
    // 0x80005EDC: j           L_80005EE8
    // 0x80005EE0: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
        goto L_80005EE8;
    // 0x80005EE0: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80005EE4:
    // 0x80005EE4: addu        $v0, $s6, $zero
    ctx->r2 = ADD32(ctx->r22, 0);
L_80005EE8:
    // 0x80005EE8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80005EEC: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80005EF0: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80005EF4: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80005EF8: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80005EFC: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80005F00: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80005F04: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80005F08: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80005F0C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80005F10: jr          $ra
    // 0x80005F14: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80005F14: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80005F18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005F18: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80005F1C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80005F20: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80005F24: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80005F28: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x80005F2C: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80005F30: addu        $s7, $a2, $zero
    ctx->r23 = ADD32(ctx->r6, 0);
    // 0x80005F34: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80005F38: addu        $s6, $a3, $zero
    ctx->r22 = ADD32(ctx->r7, 0);
    // 0x80005F3C: sw          $ra, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r31;
    // 0x80005F40: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80005F44: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80005F48: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80005F4C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
L_80005F50:
    // 0x80005F50: jal         0x80005960
    // 0x80005F54: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_80005960(rdram, ctx);
        goto after_0;
    // 0x80005F54: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_0:
    // 0x80005F58: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // 0x80005F5C: bne         $s4, $zero, L_8000616C
    if (ctx->r20 != 0) {
        // 0x80005F60: addu        $v0, $s4, $zero
        ctx->r2 = ADD32(ctx->r20, 0);
            goto L_8000616C;
    }
    // 0x80005F60: addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
    // 0x80005F64: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80005F68: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80005F6C: jal         0x800078E0
    // 0x80005F70: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x80005F70: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80005F74: beq         $s5, $zero, L_80005F84
    if (ctx->r21 == 0) {
        // 0x80005F78: addiu       $v0, $s5, 0x11
        ctx->r2 = ADD32(ctx->r21, 0X11);
            goto L_80005F84;
    }
    // 0x80005F78: addiu       $v0, $s5, 0x11
    ctx->r2 = ADD32(ctx->r21, 0X11);
    // 0x80005F7C: j           L_80005F88
    // 0x80005F80: sb          $v0, 0x18($sp)
    MEM_B(0X18, ctx->r29) = ctx->r2;
        goto L_80005F88;
    // 0x80005F80: sb          $v0, 0x18($sp)
    MEM_B(0X18, ctx->r29) = ctx->r2;
L_80005F84:
    // 0x80005F84: sb          $zero, 0x18($sp)
    MEM_B(0X18, ctx->r29) = 0;
L_80005F88:
    // 0x80005F88: sll         $a0, $s2, 1
    ctx->r4 = S32(ctx->r18 << 1);
    // 0x80005F8C: addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    // 0x80005F90: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80005F94: addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    // 0x80005F98: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80005F9C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005FA0: addiu       $v0, $v0, 0x2730
    ctx->r2 = ADD32(ctx->r2, 0X2730);
    // 0x80005FA4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80005FA8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005FAC: addiu       $v1, $v0, 0x26C0
    ctx->r3 = ADD32(ctx->r2, 0X26C0);
    // 0x80005FB0: addiu       $a3, $v1, 0x10
    ctx->r7 = ADD32(ctx->r3, 0X10);
    // 0x80005FB4: lw          $a2, 0x26C0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X26C0);
    // 0x80005FB8: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x80005FBC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80005FC0: addiu       $v0, $sp, 0x20
    ctx->r2 = ADD32(ctx->r29, 0X20);
    // 0x80005FC4: lhu         $a1, 0xC($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0XC);
    // 0x80005FC8: addiu       $v1, $s6, 0x117
    ctx->r3 = ADD32(ctx->r22, 0X117);
    // 0x80005FCC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80005FD0: addiu       $v0, $zero, -0x100
    ctx->r2 = ADD32(0, -0X100);
    // 0x80005FD4: jal         0x80032260
    // 0x80005FD8: and         $s3, $v1, $v0
    ctx->r19 = ctx->r3 & ctx->r2;
    osPfsFindFile_recomp(rdram, ctx);
        goto after_2;
    // 0x80005FD8: and         $s3, $v1, $v0
    ctx->r19 = ctx->r3 & ctx->r2;
    after_2:
    // 0x80005FDC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80005FE0: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x80005FE4: beq         $v0, $zero, L_80006074
    if (ctx->r2 == 0) {
        // 0x80005FE8: lui         $v0, 0x8000
        ctx->r2 = S32(0X8000 << 16);
            goto L_80006074;
    }
    // 0x80005FE8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80005FEC: addiu       $v0, $v0, 0x500
    ctx->r2 = ADD32(ctx->r2, 0X500);
    // 0x80005FF0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80005FF4: addu        $v1, $v1, $v0
    gpr jr_addend_80005FFC = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80005FF8: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x80005FFC: jr          $v0
    // 0x80006000: nop

    switch (jr_addend_80005FFC >> 2) {
        case 0: goto L_80006004; break;
        case 1: goto L_8000600C; break;
        case 2: goto L_80006060; break;
        case 3: goto L_80006068; break;
        case 4: goto L_80006068; break;
        case 5: goto L_80006070; break;
        default: switch_error(__func__, 0x80005FFC, 0x80000500);
    }
    // 0x80006000: nop

L_80006004:
    // 0x80006004: j           L_80006074
    // 0x80006008: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
        goto L_80006074;
    // 0x80006008: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_8000600C:
    // 0x8000600C: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80006010: lw          $a0, 0x26E0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X26E0);
    // 0x80006014: jal         0x8002AB80
    // 0x80006018: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    osContStartQuery_recomp(rdram, ctx);
        goto after_3;
    // 0x80006018: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    after_3:
    // 0x8000601C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80006020: lw          $a0, 0x26E0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X26E0);
    // 0x80006024: jal         0x800331D0
    // 0x80006028: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x80006028: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x8000602C: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80006030: lw          $a0, 0x26E8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X26E8);
    // 0x80006034: jal         0x8002AC04
    // 0x80006038: nop

    osContGetQuery_recomp(rdram, ctx);
        goto after_5;
    // 0x80006038: nop

    after_5:
    // 0x8000603C: lw          $v1, 0x26E8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X26E8);
    // 0x80006040: sll         $v0, $s2, 2
    ctx->r2 = S32(ctx->r18 << 2);
    // 0x80006044: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80006048: lbu         $v1, 0x3($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X3);
    // 0x8000604C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80006050: beql        $v1, $v0, L_80006074
    if (ctx->r3 == ctx->r2) {
        // 0x80006054: addiu       $s1, $zero, 0xB
        ctx->r17 = ADD32(0, 0XB);
            goto L_80006074;
    }
    goto skip_0;
    // 0x80006054: addiu       $s1, $zero, 0xB
    ctx->r17 = ADD32(0, 0XB);
    skip_0:
    // 0x80006058: j           L_80006074
    // 0x8000605C: nop

        goto L_80006074;
    // 0x8000605C: nop

L_80006060:
    // 0x80006060: j           L_80006074
    // 0x80006064: addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
        goto L_80006074;
    // 0x80006064: addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
L_80006068:
    // 0x80006068: j           L_80006074
    // 0x8000606C: addiu       $s1, $zero, 0x9
    ctx->r17 = ADD32(0, 0X9);
        goto L_80006074;
    // 0x8000606C: addiu       $s1, $zero, 0x9
    ctx->r17 = ADD32(0, 0X9);
L_80006070:
    // 0x80006070: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
L_80006074:
    // 0x80006074: bne         $s1, $zero, L_8000616C
    if (ctx->r17 != 0) {
        // 0x80006078: addu        $v0, $s1, $zero
        ctx->r2 = ADD32(ctx->r17, 0);
            goto L_8000616C;
    }
    // 0x80006078: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x8000607C: sll         $a0, $s2, 1
    ctx->r4 = S32(ctx->r18 << 1);
    // 0x80006080: addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    // 0x80006084: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80006088: addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    // 0x8000608C: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80006090: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80006094: addiu       $v0, $v0, 0x2730
    ctx->r2 = ADD32(ctx->r2, 0X2730);
    // 0x80006098: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8000609C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800060A0: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800060A4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800060A8: lw          $v0, 0x2724($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2724);
    // 0x800060AC: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x800060B0: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x800060B4: jal         0x80031BDC
    // 0x800060B8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    osPfsReadWriteFile_recomp(rdram, ctx);
        goto after_6;
    // 0x800060B8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_6:
    // 0x800060BC: beq         $v0, $zero, L_800060F4
    if (ctx->r2 == 0) {
        // 0x800060C0: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800060F4;
    }
    // 0x800060C0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800060C4: lw          $v0, 0x26F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X26F0);
    // 0x800060C8: beq         $v0, $zero, L_800060E0
    if (ctx->r2 == 0) {
        // 0x800060CC: addiu       $s1, $zero, 0x4
        ctx->r17 = ADD32(0, 0X4);
            goto L_800060E0;
    }
    // 0x800060CC: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x800060D0: jalr        $v0
    // 0x800060D4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_7;
    // 0x800060D4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_7:
    // 0x800060D8: j           L_800060E4
    // 0x800060DC: nop

        goto L_800060E4;
    // 0x800060DC: nop

L_800060E0:
    // 0x800060E0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800060E4:
    // 0x800060E4: bne         $v0, $zero, L_80005F50
    if (ctx->r2 != 0) {
        // 0x800060E8: addu        $v0, $s1, $zero
        ctx->r2 = ADD32(ctx->r17, 0);
            goto L_80005F50;
    }
    // 0x800060E8: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x800060EC: j           L_8000616C
    // 0x800060F0: nop

        goto L_8000616C;
    // 0x800060F0: nop

L_800060F4:
    // 0x800060F4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800060F8: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800060FC: lw          $s0, 0x2724($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X2724);
    // 0x80006100: jal         0x800269B0
    // 0x80006104: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    adler32(rdram, ctx);
        goto after_8;
    // 0x80006104: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_8:
    // 0x80006108: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000610C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80006110: jal         0x800269B0
    // 0x80006114: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    adler32(rdram, ctx);
        goto after_9;
    // 0x80006114: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    after_9:
    // 0x80006118: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x8000611C: bne         $v1, $v0, L_8000616C
    if (ctx->r3 != ctx->r2) {
        // 0x80006120: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8000616C;
    }
    // 0x80006120: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80006124: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80006128: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8000612C: jal         0x800269B0
    // 0x80006130: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    adler32(rdram, ctx);
        goto after_10;
    // 0x80006130: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_10:
    // 0x80006134: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80006138: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000613C: addiu       $s1, $s0, 0x18
    ctx->r17 = ADD32(ctx->r16, 0X18);
    // 0x80006140: lw          $a2, 0x26C8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X26C8);
    // 0x80006144: jal         0x800269B0
    // 0x80006148: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    adler32(rdram, ctx);
        goto after_11;
    // 0x80006148: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_11:
    // 0x8000614C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80006150: bne         $v1, $v0, L_8000616C
    if (ctx->r3 != ctx->r2) {
        // 0x80006154: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8000616C;
    }
    // 0x80006154: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80006158: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x8000615C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80006160: jal         0x800346F0
    // 0x80006164: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    memcpy_recomp(rdram, ctx);
        goto after_12;
    // 0x80006164: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    after_12:
    // 0x80006168: addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
L_8000616C:
    // 0x8000616C: lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X48);
    // 0x80006170: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80006174: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80006178: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8000617C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80006180: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80006184: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80006188: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8000618C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80006190: jr          $ra
    // 0x80006194: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80006194: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80006198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006198: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8000619C: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800061A0: addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // 0x800061A4: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x800061A8: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x800061AC: addiu       $a3, $a2, 0x26C0
    ctx->r7 = ADD32(ctx->r6, 0X26C0);
    // 0x800061B0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800061B4: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800061B8: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800061BC: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800061C0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800061C4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800061C8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800061CC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800061D0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800061D4: lhu         $v0, 0xE($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0XE);
    // 0x800061D8: beq         $v0, $zero, L_80006308
    if (ctx->r2 == 0) {
        // 0x800061DC: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_80006308;
    }
    // 0x800061DC: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x800061E0: sll         $v0, $s7, 1
    ctx->r2 = S32(ctx->r23 << 1);
    // 0x800061E4: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x800061E8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800061EC: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x800061F0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800061F4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800061F8: addiu       $v1, $v1, 0x2730
    ctx->r3 = ADD32(ctx->r3, 0X2730);
    // 0x800061FC: addu        $s4, $v0, $v1
    ctx->r20 = ADD32(ctx->r2, ctx->r3);
    // 0x80006200: addu        $fp, $a2, $zero
    ctx->r30 = ADD32(ctx->r6, 0);
    // 0x80006204: addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
    // 0x80006208: lui         $s6, 0x8011
    ctx->r22 = S32(0X8011 << 16);
    // 0x8000620C: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
L_80006210:
    // 0x80006210: jal         0x80005960
    // 0x80006214: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    func_80005960(rdram, ctx);
        goto after_0;
    // 0x80006214: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    after_0:
    // 0x80006218: bnel        $v0, $zero, L_800062F4
    if (ctx->r2 != 0) {
        // 0x8000621C: addiu       $s2, $s2, 0x10
        ctx->r18 = ADD32(ctx->r18, 0X10);
            goto L_800062F4;
    }
    goto skip_0;
    // 0x8000621C: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    skip_0:
    // 0x80006220: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80006224: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80006228: jal         0x800078E0
    // 0x8000622C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x8000622C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80006230: beq         $s3, $zero, L_80006240
    if (ctx->r19 == 0) {
        // 0x80006234: addiu       $v0, $s3, 0x11
        ctx->r2 = ADD32(ctx->r19, 0X11);
            goto L_80006240;
    }
    // 0x80006234: addiu       $v0, $s3, 0x11
    ctx->r2 = ADD32(ctx->r19, 0X11);
    // 0x80006238: j           L_80006244
    // 0x8000623C: sb          $v0, 0x18($sp)
    MEM_B(0X18, ctx->r29) = ctx->r2;
        goto L_80006244;
    // 0x8000623C: sb          $v0, 0x18($sp)
    MEM_B(0X18, ctx->r29) = ctx->r2;
L_80006240:
    // 0x80006240: sb          $zero, 0x18($sp)
    MEM_B(0X18, ctx->r29) = 0;
L_80006244:
    // 0x80006244: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80006248: addiu       $a3, $s5, 0x10
    ctx->r7 = ADD32(ctx->r21, 0X10);
    // 0x8000624C: lw          $a2, 0x26C0($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X26C0);
    // 0x80006250: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x80006254: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80006258: lhu         $a1, 0xC($s5)
    ctx->r5 = MEM_HU(ctx->r21, 0XC);
    // 0x8000625C: addiu       $v0, $sp, 0x20
    ctx->r2 = ADD32(ctx->r29, 0X20);
    // 0x80006260: jal         0x80032260
    // 0x80006264: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    osPfsFindFile_recomp(rdram, ctx);
        goto after_2;
    // 0x80006264: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_2:
    // 0x80006268: bne         $v0, $zero, L_800062E4
    if (ctx->r2 != 0) {
        // 0x8000626C: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_800062E4;
    }
    // 0x8000626C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80006270: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80006274: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80006278: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8000627C: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x80006280: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80006284: lw          $v0, 0x2724($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X2724);
    // 0x80006288: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x8000628C: jal         0x80031BDC
    // 0x80006290: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    osPfsReadWriteFile_recomp(rdram, ctx);
        goto after_3;
    // 0x80006290: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_3:
    // 0x80006294: bne         $v0, $zero, L_800062E4
    if (ctx->r2 != 0) {
        // 0x80006298: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_800062E4;
    }
    // 0x80006298: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8000629C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800062A0: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800062A4: lw          $s0, 0x2724($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X2724);
    // 0x800062A8: jal         0x800269B0
    // 0x800062AC: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    adler32(rdram, ctx);
        goto after_4;
    // 0x800062AC: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_4:
    // 0x800062B0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800062B4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800062B8: addiu       $s1, $s0, 0x8
    ctx->r17 = ADD32(ctx->r16, 0X8);
    // 0x800062BC: jal         0x800269B0
    // 0x800062C0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    adler32(rdram, ctx);
        goto after_5;
    // 0x800062C0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_5:
    // 0x800062C4: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x800062C8: bne         $v1, $v0, L_800062E4
    if (ctx->r3 != ctx->r2) {
        // 0x800062CC: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_800062E4;
    }
    // 0x800062CC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800062D0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800062D4: jal         0x800346F0
    // 0x800062D8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    memcpy_recomp(rdram, ctx);
        goto after_6;
    // 0x800062D8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_6:
    // 0x800062DC: j           L_800062F4
    // 0x800062E0: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
        goto L_800062F4;
    // 0x800062E0: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
L_800062E4:
    // 0x800062E4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800062E8: jal         0x800078E0
    // 0x800062EC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    rs_memset(rdram, ctx);
        goto after_7;
    // 0x800062EC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_7:
    // 0x800062F0: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
L_800062F4:
    // 0x800062F4: lhu         $v0, 0xE($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0XE);
    // 0x800062F8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800062FC: slt         $v0, $s3, $v0
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80006300: bne         $v0, $zero, L_80006210
    if (ctx->r2 != 0) {
        // 0x80006304: nop
    
            goto L_80006210;
    }
    // 0x80006304: nop

L_80006308:
    // 0x80006308: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8000630C: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80006310: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80006314: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80006318: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8000631C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80006320: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80006324: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80006328: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8000632C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80006330: jr          $ra
    // 0x80006334: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80006334: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80006338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006338: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8000633C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80006340: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80006344: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80006348: addiu       $s1, $v0, 0x26C0
    ctx->r17 = ADD32(ctx->r2, 0X26C0);
    // 0x8000634C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80006350: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80006354: lui         $s2, 0x8011
    ctx->r18 = S32(0X8011 << 16);
    // 0x80006358: sw          $a1, 0x26F0($s2)
    MEM_W(0X26F0, ctx->r18) = ctx->r5;
    // 0x8000635C: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x80006360: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80006364: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x80006368: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8000636C: jal         0x800346F0
    // 0x80006370: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x80006370: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    after_0:
    // 0x80006374: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    // 0x80006378: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000637C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80006380: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80006384: sb          $v0, 0x272C($v1)
    MEM_B(0X272C, ctx->r3) = ctx->r2;
    // 0x80006388: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000638C: addiu       $v0, $v0, 0x770
    ctx->r2 = ADD32(ctx->r2, 0X770);
    // 0x80006390: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80006394: sw          $v0, 0x26E0($s0)
    MEM_W(0X26E0, ctx->r16) = ctx->r2;
    // 0x80006398: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000639C: addiu       $v0, $v0, 0x798
    ctx->r2 = ADD32(ctx->r2, 0X798);
    // 0x800063A0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800063A4: sw          $v0, 0x26E4($v1)
    MEM_W(0X26E4, ctx->r3) = ctx->r2;
    // 0x800063A8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800063AC: lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X8);
    // 0x800063B0: addiu       $v0, $v0, 0x788
    ctx->r2 = ADD32(ctx->r2, 0X788);
    // 0x800063B4: sw          $v0, 0x26E8($a0)
    MEM_W(0X26E8, ctx->r4) = ctx->r2;
    // 0x800063B8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800063BC: addiu       $a0, $v1, 0x118
    ctx->r4 = ADD32(ctx->r3, 0X118);
    // 0x800063C0: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x800063C4: jal         0x80001ACC
    // 0x800063C8: sw          $v1, 0x2728($v0)
    MEM_W(0X2728, ctx->r2) = ctx->r3;
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x800063C8: sw          $v1, 0x2728($v0)
    MEM_W(0X2728, ctx->r2) = ctx->r3;
    after_1:
    // 0x800063CC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800063D0: sw          $v0, 0x2724($v1)
    MEM_W(0X2724, ctx->r3) = ctx->r2;
    // 0x800063D4: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x800063D8: beq         $v0, $zero, L_800063E4
    if (ctx->r2 == 0) {
        // 0x800063DC: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_800063E4;
    }
    // 0x800063DC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800063E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800063E4:
    // 0x800063E4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800063E8: jal         0x80003284
    // 0x800063EC: sw          $a0, 0x2720($v0)
    MEM_W(0X2720, ctx->r2) = ctx->r4;
    func_80003284(rdram, ctx);
        goto after_2;
    // 0x800063EC: sw          $a0, 0x2720($v0)
    MEM_W(0X2720, ctx->r2) = ctx->r4;
    after_2:
    // 0x800063F0: lw          $a0, 0x26E0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X26E0);
    // 0x800063F4: jal         0x8002A2A0
    // 0x800063F8: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    osEepromProbe_recomp(rdram, ctx);
        goto after_3;
    // 0x800063F8: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    after_3:
    // 0x800063FC: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80006400: jal         0x800032E0
    // 0x80006404: sb          $v0, 0x26EC($s0)
    MEM_B(0X26EC, ctx->r16) = ctx->r2;
    func_800032E0(rdram, ctx);
        goto after_4;
    // 0x80006404: sb          $v0, 0x26EC($s0)
    MEM_B(0X26EC, ctx->r16) = ctx->r2;
    after_4:
    // 0x80006408: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x8000640C: beq         $v0, $zero, L_80006740
    if (ctx->r2 == 0) {
        // 0x80006410: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80006740;
    }
    // 0x80006410: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80006414: lbu         $v1, 0x26EC($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X26EC);
    // 0x80006418: bne         $v1, $zero, L_8000643C
    if (ctx->r3 != 0) {
        // 0x8000641C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000643C;
    }
    // 0x8000641C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80006420: lw          $v0, 0x26F0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X26F0);
    // 0x80006424: beql        $v0, $zero, L_80006748
    if (ctx->r2 == 0) {
        // 0x80006428: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80006748;
    }
    goto skip_0;
    // 0x80006428: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_0:
    // 0x8000642C: jalr        $v0
    // 0x80006430: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_5;
    // 0x80006430: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_5:
    // 0x80006434: j           L_80006748
    // 0x80006438: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80006748;
    // 0x80006438: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8000643C:
    // 0x8000643C: bne         $v1, $v0, L_80006740
    if (ctx->r3 != ctx->r2) {
        // 0x80006440: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80006740;
    }
    // 0x80006440: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80006444: lui         $t1, 0xF5F5
    ctx->r9 = S32(0XF5F5 << 16);
    // 0x80006448: ori         $t1, $t1, 0xF5F5
    ctx->r9 = ctx->r9 | 0XF5F5;
    // 0x8000644C: lui         $t0, 0x4741
    ctx->r8 = S32(0X4741 << 16);
    // 0x80006450: ori         $t0, $t0, 0x4D45
    ctx->r8 = ctx->r8 | 0X4D45;
    // 0x80006454: lui         $a3, 0x4753
    ctx->r7 = S32(0X4753 << 16);
    // 0x80006458: ori         $a3, $a3, 0x5953
    ctx->r7 = ctx->r7 | 0X5953;
    // 0x8000645C: lui         $v1, 0xAAAA
    ctx->r3 = S32(0XAAAA << 16);
    // 0x80006460: ori         $v1, $v1, 0xAAAA
    ctx->r3 = ctx->r3 | 0XAAAA;
    // 0x80006464: lui         $v0, 0x5555
    ctx->r2 = S32(0X5555 << 16);
    // 0x80006468: ori         $v0, $v0, 0x5555
    ctx->r2 = ctx->r2 | 0X5555;
    // 0x8000646C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80006470: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80006474: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80006478: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8000647C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80006480: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80006484: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80006488: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8000648C: lhu         $v0, 0xA($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XA);
    // 0x80006490: lhu         $v1, 0xE($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XE);
    // 0x80006494: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80006498: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8000649C: jal         0x800269B0
    // 0x800064A0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    adler32(rdram, ctx);
        goto after_6;
    // 0x800064A0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_6:
    // 0x800064A4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800064A8: addiu       $a1, $sp, 0x14
    ctx->r5 = ADD32(ctx->r29, 0X14);
    // 0x800064AC: jal         0x800269B0
    // 0x800064B0: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    adler32(rdram, ctx);
        goto after_7;
    // 0x800064B0: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_7:
    // 0x800064B4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800064B8: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800064BC: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x800064C0: jal         0x800269B0
    // 0x800064C4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    adler32(rdram, ctx);
        goto after_8;
    // 0x800064C4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_8:
    // 0x800064C8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800064CC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800064D0: jal         0x800269B0
    // 0x800064D4: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    adler32(rdram, ctx);
        goto after_9;
    // 0x800064D4: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_9:
    // 0x800064D8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
L_800064DC:
    // 0x800064DC: jal         0x80003284
    // 0x800064E0: nop

    func_80003284(rdram, ctx);
        goto after_10;
    // 0x800064E0: nop

    after_10:
    // 0x800064E4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800064E8: lw          $a0, 0x26E0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X26E0);
    // 0x800064EC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800064F0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800064F4: addiu       $s1, $v0, 0x2700
    ctx->r17 = ADD32(ctx->r2, 0X2700);
    // 0x800064F8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x800064FC: jal         0x8002A120
    // 0x80006500: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    osEepromLongRead_recomp(rdram, ctx);
        goto after_11;
    // 0x80006500: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_11:
    // 0x80006504: jal         0x800032E0
    // 0x80006508: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    func_800032E0(rdram, ctx);
        goto after_12;
    // 0x80006508: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_12:
    // 0x8000650C: beq         $s0, $zero, L_80006550
    if (ctx->r16 == 0) {
        // 0x80006510: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80006550;
    }
    // 0x80006510: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80006514: lw          $v0, 0x26F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X26F0);
    // 0x80006518: beq         $v0, $zero, L_8000652C
    if (ctx->r2 == 0) {
        // 0x8000651C: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8000652C;
    }
    // 0x8000651C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80006520: jalr        $v0
    // 0x80006524: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_13;
    // 0x80006524: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_13:
    // 0x80006528: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_8000652C:
    // 0x8000652C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80006530: beq         $v1, $v0, L_800064DC
    if (ctx->r3 == ctx->r2) {
        // 0x80006534: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800064DC;
    }
    // 0x80006534: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80006538: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000653C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80006540: sb          $zero, 0x26EC($v1)
    MEM_B(0X26EC, ctx->r3) = 0;
    // 0x80006544: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80006548: j           L_80006748
    // 0x8000654C: sw          $v1, 0x2720($a0)
    MEM_W(0X2720, ctx->r4) = ctx->r3;
        goto L_80006748;
    // 0x8000654C: sw          $v1, 0x2720($a0)
    MEM_W(0X2720, ctx->r4) = ctx->r3;
L_80006550:
    // 0x80006550: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80006554: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80006558: jal         0x80029F60
    // 0x8000655C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    bcmp_recomp(rdram, ctx);
        goto after_14;
    // 0x8000655C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_14:
    // 0x80006560: beq         $v0, $zero, L_8000673C
    if (ctx->r2 == 0) {
        // 0x80006564: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_8000673C;
    }
    // 0x80006564: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80006568: lw          $v0, 0x26F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X26F0);
    // 0x8000656C: beq         $v0, $zero, L_80006580
    if (ctx->r2 == 0) {
        // 0x80006570: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80006580;
    }
    // 0x80006570: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80006574: jalr        $v0
    // 0x80006578: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_15;
    // 0x80006578: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_15:
    // 0x8000657C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_80006580:
    // 0x80006580: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80006584: beq         $v1, $v0, L_800064DC
    if (ctx->r3 == ctx->r2) {
        // 0x80006588: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800064DC;
    }
    // 0x80006588: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8000658C: bne         $v1, $v0, L_80006748
    if (ctx->r3 != ctx->r2) {
        // 0x80006590: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80006748;
    }
    // 0x80006590: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80006594: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80006598: addiu       $s0, $v0, 0x26C0
    ctx->r16 = ADD32(ctx->r2, 0X26C0);
    // 0x8000659C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800065A0: lhu         $v1, 0xE($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XE);
    // 0x800065A4: lw          $v0, 0x2728($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2728);
    // 0x800065A8: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800065AC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800065B0: mflo        $t2
    ctx->r10 = lo;
    // 0x800065B4: addiu       $v0, $t2, 0x20
    ctx->r2 = ADD32(ctx->r10, 0X20);
    // 0x800065B8: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x800065BC: beq         $v0, $zero, L_800065E0
    if (ctx->r2 == 0) {
        // 0x800065C0: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800065E0;
    }
    // 0x800065C0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800065C4: lw          $v0, 0x26F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X26F0);
    // 0x800065C8: beql        $v0, $zero, L_80006748
    if (ctx->r2 == 0) {
        // 0x800065CC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80006748;
    }
    goto skip_1;
    // 0x800065CC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_1:
    // 0x800065D0: jalr        $v0
    // 0x800065D4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_16;
    // 0x800065D4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_16:
    // 0x800065D8: j           L_80006748
    // 0x800065DC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80006748;
    // 0x800065DC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800065E0:
    // 0x800065E0: jal         0x80001ACC
    // 0x800065E4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    rs_malloc(rdram, ctx);
        goto after_17;
    // 0x800065E4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_17:
    // 0x800065E8: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x800065EC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800065F0: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x800065F4: jal         0x800078E0
    // 0x800065F8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_memset(rdram, ctx);
        goto after_18;
    // 0x800065F8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_18:
    // 0x800065FC: lhu         $v0, 0xE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XE);
    // 0x80006600: beq         $v0, $zero, L_80006680
    if (ctx->r2 == 0) {
        // 0x80006604: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80006680;
    }
    // 0x80006604: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80006608: addu        $s3, $s0, $zero
    ctx->r19 = ADD32(ctx->r16, 0);
L_8000660C:
    // 0x8000660C: lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X8);
    // 0x80006610: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x80006614: mult        $s1, $v0
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80006618: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8000661C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80006620: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80006624: mflo        $t2
    ctx->r10 = lo;
    // 0x80006628: addiu       $s0, $t2, 0x20
    ctx->r16 = ADD32(ctx->r10, 0X20);
    // 0x8000662C: jal         0x800269B0
    // 0x80006630: addu        $s0, $s2, $s0
    ctx->r16 = ADD32(ctx->r18, ctx->r16);
    adler32(rdram, ctx);
        goto after_19;
    // 0x80006630: addu        $s0, $s2, $s0
    ctx->r16 = ADD32(ctx->r18, ctx->r16);
    after_19:
    // 0x80006634: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80006638: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    // 0x8000663C: jal         0x800269B0
    // 0x80006640: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    adler32(rdram, ctx);
        goto after_20;
    // 0x80006640: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_20:
    // 0x80006644: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80006648: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8000664C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80006650: jal         0x800269B0
    // 0x80006654: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    adler32(rdram, ctx);
        goto after_21;
    // 0x80006654: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    after_21:
    // 0x80006658: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000665C: lw          $a2, 0x8($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X8);
    // 0x80006660: jal         0x800269B0
    // 0x80006664: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    adler32(rdram, ctx);
        goto after_22;
    // 0x80006664: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_22:
    // 0x80006668: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000666C: lhu         $v0, 0xE($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0XE);
    // 0x80006670: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80006674: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80006678: bne         $v0, $zero, L_8000660C
    if (ctx->r2 != 0) {
        // 0x8000667C: nop
    
            goto L_8000660C;
    }
    // 0x8000667C: nop

L_80006680:
    // 0x80006680: jal         0x80003284
    // 0x80006684: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    func_80003284(rdram, ctx);
        goto after_23;
    // 0x80006684: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    after_23:
    // 0x80006688: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8000668C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80006690: lw          $a0, 0x26E0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X26E0);
    // 0x80006694: lw          $a3, 0x26C4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X26C4);
    // 0x80006698: jal         0x8002A1B0
    // 0x8000669C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    osEepromLongWrite_recomp(rdram, ctx);
        goto after_24;
    // 0x8000669C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_24:
    // 0x800066A0: beq         $v0, $zero, L_800066C8
    if (ctx->r2 == 0) {
        // 0x800066A4: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800066C8;
    }
    // 0x800066A4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800066A8: jal         0x800032E0
    // 0x800066AC: nop

    func_800032E0(rdram, ctx);
        goto after_25;
    // 0x800066AC: nop

    after_25:
    // 0x800066B0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800066B4: lw          $v0, 0x26F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X26F0);
    // 0x800066B8: bne         $v0, $zero, L_800066F4
    if (ctx->r2 != 0) {
        // 0x800066BC: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800066F4;
    }
    // 0x800066BC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800066C0: j           L_80006704
    // 0x800066C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80006704;
    // 0x800066C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800066C8:
    // 0x800066C8: lw          $a0, 0x26E0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X26E0);
    // 0x800066CC: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // 0x800066D0: jal         0x8002A1B0
    // 0x800066D4: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    osEepromLongWrite_recomp(rdram, ctx);
        goto after_26;
    // 0x800066D4: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_26:
    // 0x800066D8: jal         0x800032E0
    // 0x800066DC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    func_800032E0(rdram, ctx);
        goto after_27;
    // 0x800066DC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_27:
    // 0x800066E0: beq         $s0, $zero, L_8000672C
    if (ctx->r16 == 0) {
        // 0x800066E4: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_8000672C;
    }
    // 0x800066E4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800066E8: lw          $v0, 0x26F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X26F0);
    // 0x800066EC: beq         $v0, $zero, L_80006700
    if (ctx->r2 == 0) {
        // 0x800066F0: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80006700;
    }
    // 0x800066F0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800066F4:
    // 0x800066F4: jalr        $v0
    // 0x800066F8: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_28;
    // 0x800066F8: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_28:
    // 0x800066FC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_80006700:
    // 0x80006700: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80006704:
    // 0x80006704: beq         $v1, $v0, L_80006680
    if (ctx->r3 == ctx->r2) {
        // 0x80006708: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_80006680;
    }
    // 0x80006708: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8000670C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80006710: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80006714: sb          $zero, 0x26EC($v0)
    MEM_B(0X26EC, ctx->r2) = 0;
    // 0x80006718: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8000671C: jal         0x80001C98
    // 0x80006720: sw          $v0, 0x2720($v1)
    MEM_W(0X2720, ctx->r3) = ctx->r2;
    rs_free(rdram, ctx);
        goto after_29;
    // 0x80006720: sw          $v0, 0x2720($v1)
    MEM_W(0X2720, ctx->r3) = ctx->r2;
    after_29:
    // 0x80006724: j           L_80006748
    // 0x80006728: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80006748;
    // 0x80006728: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8000672C:
    // 0x8000672C: jal         0x80001C98
    // 0x80006730: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    rs_free(rdram, ctx);
        goto after_30;
    // 0x80006730: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_30:
    // 0x80006734: j           L_800064DC
    // 0x80006738: nop

        goto L_800064DC;
    // 0x80006738: nop

L_8000673C:
    // 0x8000673C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_80006740:
    // 0x80006740: sb          $zero, 0x26ED($v0)
    MEM_B(0X26ED, ctx->r2) = 0;
    // 0x80006744: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80006748:
    // 0x80006748: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x8000674C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80006750: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80006754: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80006758: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8000675C: jr          $ra
    // 0x80006760: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80006760: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80006764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006764: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80006768: lw          $a0, 0x2724($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2724);
    // 0x8000676C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80006770: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80006774: jal         0x80001C98
    // 0x80006778: nop

    rs_free(rdram, ctx);
        goto after_0;
    // 0x80006778: nop

    after_0:
    // 0x8000677C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80006780: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80006784: jr          $ra
    // 0x80006788: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80006788: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8000678C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000678C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80006790: jr          $ra
    // 0x80006794: sw          $a0, 0x26F0($v0)
    MEM_W(0X26F0, ctx->r2) = ctx->r4;
    return;
    // 0x80006794: sw          $a0, 0x26F0($v0)
    MEM_W(0X26F0, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void func_80006798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006798: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8000679C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800067A0: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800067A4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800067A8: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800067AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800067B0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800067B4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800067B8: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x800067BC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800067C0: addu        $fp, $a2, $zero
    ctx->r30 = ADD32(ctx->r6, 0);
    // 0x800067C4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800067C8: addu        $s7, $a3, $zero
    ctx->r23 = ADD32(ctx->r7, 0);
    // 0x800067CC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800067D0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800067D4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800067D8: bne         $s0, $zero, L_800067E8
    if (ctx->r16 != 0) {
        // 0x800067DC: sw          $s1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r17;
            goto L_800067E8;
    }
    // 0x800067DC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800067E0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800067E4: lw          $s0, 0x2720($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X2720);
L_800067E8:
    // 0x800067E8: jal         0x80003284
    // 0x800067EC: nop

    func_80003284(rdram, ctx);
        goto after_0;
    // 0x800067EC: nop

    after_0:
    // 0x800067F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800067F4: beq         $s0, $v0, L_8000680C
    if (ctx->r16 == ctx->r2) {
        // 0x800067F8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8000680C;
    }
    // 0x800067F8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800067FC: beq         $s0, $v0, L_800068D0
    if (ctx->r16 == ctx->r2) {
        // 0x80006800: sltiu       $v0, $s2, 0x4
        ctx->r2 = ctx->r18 < 0X4 ? 1 : 0;
            goto L_800068D0;
    }
    // 0x80006800: sltiu       $v0, $s2, 0x4
    ctx->r2 = ctx->r18 < 0X4 ? 1 : 0;
    // 0x80006804: j           L_800068F8
    // 0x80006808: nop

        goto L_800068F8;
    // 0x80006808: nop

L_8000680C:
    // 0x8000680C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80006810: lui         $s4, 0x8011
    ctx->r20 = S32(0X8011 << 16);
    // 0x80006814: lui         $s3, 0x8011
    ctx->r19 = S32(0X8011 << 16);
    // 0x80006818: lw          $s0, 0x2724($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X2724);
    // 0x8000681C: lw          $a2, 0x2728($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X2728);
    // 0x80006820: jal         0x800078E0
    // 0x80006824: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x80006824: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80006828: addiu       $s2, $s0, 0x18
    ctx->r18 = ADD32(ctx->r16, 0X18);
    // 0x8000682C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80006830: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // 0x80006834: jal         0x800346F0
    // 0x80006838: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    memcpy_recomp(rdram, ctx);
        goto after_2;
    // 0x80006838: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    after_2:
    // 0x8000683C: addiu       $s1, $s0, 0x8
    ctx->r17 = ADD32(ctx->r16, 0X8);
    // 0x80006840: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80006844: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    // 0x80006848: jal         0x800346F0
    // 0x8000684C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x8000684C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_3:
    // 0x80006850: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80006854: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80006858: jal         0x800269B0
    // 0x8000685C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    adler32(rdram, ctx);
        goto after_4;
    // 0x8000685C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_4:
    // 0x80006860: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80006864: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80006868: jal         0x800269B0
    // 0x8000686C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    adler32(rdram, ctx);
        goto after_5;
    // 0x8000686C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_5:
    // 0x80006870: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80006874: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80006878: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8000687C: jal         0x800269B0
    // 0x80006880: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    adler32(rdram, ctx);
        goto after_6;
    // 0x80006880: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    after_6:
    // 0x80006884: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80006888: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000688C: lw          $a2, 0x26C8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X26C8);
    // 0x80006890: jal         0x800269B0
    // 0x80006894: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    adler32(rdram, ctx);
        goto after_7;
    // 0x80006894: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_7:
    // 0x80006898: lw          $a3, 0x2728($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X2728);
    // 0x8000689C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800068A0: mult        $fp, $a3
    result = S64(S32(ctx->r30)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800068A4: lw          $a0, 0x26E0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X26E0);
    // 0x800068A8: lw          $a2, 0x2724($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X2724);
    // 0x800068AC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800068B0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800068B4: mflo        $t0
    ctx->r8 = lo;
    // 0x800068B8: addiu       $a1, $t0, 0x20
    ctx->r5 = ADD32(ctx->r8, 0X20);
    // 0x800068BC: srl         $a1, $a1, 3
    ctx->r5 = S32(U32(ctx->r5) >> 3);
    // 0x800068C0: jal         0x8002A1B0
    // 0x800068C4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    osEepromLongWrite_recomp(rdram, ctx);
        goto after_8;
    // 0x800068C4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_8:
    // 0x800068C8: j           L_800068F8
    // 0x800068CC: nop

        goto L_800068F8;
    // 0x800068CC: nop

L_800068D0:
    // 0x800068D0: bnel        $v0, $zero, L_800068E0
    if (ctx->r2 != 0) {
        // 0x800068D4: sw          $s5, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r21;
            goto L_800068E0;
    }
    goto skip_0;
    // 0x800068D4: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    skip_0:
    // 0x800068D8: j           L_80006904
    // 0x800068DC: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_80006904;
    // 0x800068DC: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_800068E0:
    // 0x800068E0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800068E4: addu        $a1, $fp, $zero
    ctx->r5 = ADD32(ctx->r30, 0);
    // 0x800068E8: addu        $a2, $s7, $zero
    ctx->r6 = ADD32(ctx->r23, 0);
    // 0x800068EC: jal         0x80005B9C
    // 0x800068F0: addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    func_80005B9C(rdram, ctx);
        goto after_9;
    // 0x800068F0: addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    after_9:
    // 0x800068F4: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_800068F8:
    // 0x800068F8: jal         0x800032E0
    // 0x800068FC: nop

    func_800032E0(rdram, ctx);
        goto after_10;
    // 0x800068FC: nop

    after_10:
    // 0x80006900: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_80006904:
    // 0x80006904: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80006908: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8000690C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80006910: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80006914: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80006918: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000691C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80006920: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80006924: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80006928: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000692C: jr          $ra
    // 0x80006930: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80006930: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80006934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006934: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80006938: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8000693C: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80006940: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80006944: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80006948: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8000694C: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x80006950: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80006954: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x80006958: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8000695C: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x80006960: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x80006964: bne         $s0, $zero, L_80006974
    if (ctx->r16 != 0) {
        // 0x80006968: sw          $s1, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r17;
            goto L_80006974;
    }
    // 0x80006968: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8000696C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80006970: lw          $s0, 0x2720($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X2720);
L_80006974:
    // 0x80006974: jal         0x80003284
    // 0x80006978: nop

    func_80003284(rdram, ctx);
        goto after_0;
    // 0x80006978: nop

    after_0:
    // 0x8000697C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80006980: beq         $s0, $v0, L_80006998
    if (ctx->r16 == ctx->r2) {
        // 0x80006984: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80006998;
    }
    // 0x80006984: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80006988: beq         $s0, $v0, L_80006A48
    if (ctx->r16 == ctx->r2) {
        // 0x8000698C: sltiu       $v0, $s2, 0x4
        ctx->r2 = ctx->r18 < 0X4 ? 1 : 0;
            goto L_80006A48;
    }
    // 0x8000698C: sltiu       $v0, $s2, 0x4
    ctx->r2 = ctx->r18 < 0X4 ? 1 : 0;
    // 0x80006990: j           L_80006A6C
    // 0x80006994: nop

        goto L_80006A6C;
    // 0x80006994: nop

L_80006998:
    // 0x80006998: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000699C: lw          $a3, 0x2728($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X2728);
    // 0x800069A0: mult        $s3, $a3
    result = S64(S32(ctx->r19)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800069A4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800069A8: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800069AC: lw          $a0, 0x26E0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X26E0);
    // 0x800069B0: lw          $a2, 0x2724($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X2724);
    // 0x800069B4: mflo        $t0
    ctx->r8 = lo;
    // 0x800069B8: addiu       $a1, $t0, 0x20
    ctx->r5 = ADD32(ctx->r8, 0X20);
    // 0x800069BC: srl         $a1, $a1, 3
    ctx->r5 = S32(U32(ctx->r5) >> 3);
    // 0x800069C0: jal         0x8002A120
    // 0x800069C4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    osEepromLongRead_recomp(rdram, ctx);
        goto after_1;
    // 0x800069C4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_1:
    // 0x800069C8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800069CC: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800069D0: lw          $s0, 0x2724($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X2724);
    // 0x800069D4: jal         0x800269B0
    // 0x800069D8: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    adler32(rdram, ctx);
        goto after_2;
    // 0x800069D8: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_2:
    // 0x800069DC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800069E0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800069E4: jal         0x800269B0
    // 0x800069E8: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    adler32(rdram, ctx);
        goto after_3;
    // 0x800069E8: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    after_3:
    // 0x800069EC: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x800069F0: bne         $v1, $v0, L_80006A6C
    if (ctx->r3 != ctx->r2) {
        // 0x800069F4: addiu       $s1, $zero, 0x4
        ctx->r17 = ADD32(0, 0X4);
            goto L_80006A6C;
    }
    // 0x800069F4: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x800069F8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800069FC: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80006A00: jal         0x800269B0
    // 0x80006A04: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    adler32(rdram, ctx);
        goto after_4;
    // 0x80006A04: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_4:
    // 0x80006A08: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80006A0C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80006A10: addiu       $s1, $s0, 0x18
    ctx->r17 = ADD32(ctx->r16, 0X18);
    // 0x80006A14: lw          $a2, 0x26C8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X26C8);
    // 0x80006A18: jal         0x800269B0
    // 0x80006A1C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    adler32(rdram, ctx);
        goto after_5;
    // 0x80006A1C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_5:
    // 0x80006A20: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80006A24: beq         $v1, $v0, L_80006A34
    if (ctx->r3 == ctx->r2) {
        // 0x80006A28: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_80006A34;
    }
    // 0x80006A28: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80006A2C: j           L_80006A6C
    // 0x80006A30: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
        goto L_80006A6C;
    // 0x80006A30: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_80006A34:
    // 0x80006A34: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80006A38: jal         0x800346F0
    // 0x80006A3C: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    memcpy_recomp(rdram, ctx);
        goto after_6;
    // 0x80006A3C: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    after_6:
    // 0x80006A40: j           L_80006A6C
    // 0x80006A44: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
        goto L_80006A6C;
    // 0x80006A44: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_80006A48:
    // 0x80006A48: bne         $v0, $zero, L_80006A58
    if (ctx->r2 != 0) {
        // 0x80006A4C: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_80006A58;
    }
    // 0x80006A4C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80006A50: j           L_80006A78
    // 0x80006A54: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_80006A78;
    // 0x80006A54: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_80006A58:
    // 0x80006A58: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80006A5C: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    // 0x80006A60: jal         0x80005F18
    // 0x80006A64: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    func_80005F18(rdram, ctx);
        goto after_7;
    // 0x80006A64: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    after_7:
    // 0x80006A68: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_80006A6C:
    // 0x80006A6C: jal         0x800032E0
    // 0x80006A70: nop

    func_800032E0(rdram, ctx);
        goto after_8;
    // 0x80006A70: nop

    after_8:
    // 0x80006A74: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_80006A78:
    // 0x80006A78: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x80006A7C: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80006A80: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80006A84: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80006A88: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80006A8C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80006A90: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80006A94: jr          $ra
    // 0x80006A98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80006A98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80006A9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006A9C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80006AA0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80006AA4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80006AA8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80006AAC: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80006AB0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80006AB4: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x80006AB8: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80006ABC: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x80006AC0: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80006AC4: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80006AC8: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80006ACC: bne         $s0, $zero, L_80006ADC
    if (ctx->r16 != 0) {
        // 0x80006AD0: sw          $s3, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r19;
            goto L_80006ADC;
    }
    // 0x80006AD0: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80006AD4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80006AD8: lw          $s0, 0x2720($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X2720);
L_80006ADC:
    // 0x80006ADC: jal         0x80003284
    // 0x80006AE0: nop

    func_80003284(rdram, ctx);
        goto after_0;
    // 0x80006AE0: nop

    after_0:
    // 0x80006AE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80006AE8: beq         $s0, $v0, L_80006B00
    if (ctx->r16 == ctx->r2) {
        // 0x80006AEC: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80006B00;
    }
    // 0x80006AEC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80006AF0: beq         $s0, $v0, L_80006BC0
    if (ctx->r16 == ctx->r2) {
        // 0x80006AF4: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80006BC0;
    }
    // 0x80006AF4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80006AF8: j           L_80006BC8
    // 0x80006AFC: nop

        goto L_80006BC8;
    // 0x80006AFC: nop

L_80006B00:
    // 0x80006B00: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80006B04: addiu       $v1, $v0, 0x26C0
    ctx->r3 = ADD32(ctx->r2, 0X26C0);
    // 0x80006B08: lhu         $v0, 0xE($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XE);
    // 0x80006B0C: beq         $v0, $zero, L_80006BC8
    if (ctx->r2 == 0) {
        // 0x80006B10: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_80006BC8;
    }
    // 0x80006B10: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80006B14: lui         $s7, 0x8011
    ctx->r23 = S32(0X8011 << 16);
    // 0x80006B18: lui         $s6, 0x8011
    ctx->r22 = S32(0X8011 << 16);
    // 0x80006B1C: lui         $s4, 0x8011
    ctx->r20 = S32(0X8011 << 16);
    // 0x80006B20: addu        $s5, $v1, $zero
    ctx->r21 = ADD32(ctx->r3, 0);
L_80006B24:
    // 0x80006B24: lw          $v0, 0x2728($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X2728);
    // 0x80006B28: mult        $s3, $v0
    result = S64(S32(ctx->r19)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80006B2C: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    // 0x80006B30: lw          $a0, 0x26E0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X26E0);
    // 0x80006B34: lw          $a2, 0x2724($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X2724);
    // 0x80006B38: mflo        $t0
    ctx->r8 = lo;
    // 0x80006B3C: addiu       $a1, $t0, 0x20
    ctx->r5 = ADD32(ctx->r8, 0X20);
    // 0x80006B40: srl         $a1, $a1, 3
    ctx->r5 = S32(U32(ctx->r5) >> 3);
    // 0x80006B44: jal         0x8002A120
    // 0x80006B48: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    osEepromLongRead_recomp(rdram, ctx);
        goto after_1;
    // 0x80006B48: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_1:
    // 0x80006B4C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80006B50: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80006B54: lw          $s0, 0x2724($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X2724);
    // 0x80006B58: jal         0x800269B0
    // 0x80006B5C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    adler32(rdram, ctx);
        goto after_2;
    // 0x80006B5C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_2:
    // 0x80006B60: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80006B64: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80006B68: addiu       $s1, $s0, 0x8
    ctx->r17 = ADD32(ctx->r16, 0X8);
    // 0x80006B6C: jal         0x800269B0
    // 0x80006B70: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    adler32(rdram, ctx);
        goto after_3;
    // 0x80006B70: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_3:
    // 0x80006B74: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x80006B78: beq         $v1, $v0, L_80006B94
    if (ctx->r3 == ctx->r2) {
        // 0x80006B7C: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_80006B94;
    }
    // 0x80006B7C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80006B80: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80006B84: jal         0x800078E0
    // 0x80006B88: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    rs_memset(rdram, ctx);
        goto after_4;
    // 0x80006B88: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_4:
    // 0x80006B8C: j           L_80006BA4
    // 0x80006B90: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
        goto L_80006BA4;
    // 0x80006B90: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
L_80006B94:
    // 0x80006B94: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80006B98: jal         0x800346F0
    // 0x80006B9C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    memcpy_recomp(rdram, ctx);
        goto after_5;
    // 0x80006B9C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_5:
    // 0x80006BA0: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
L_80006BA4:
    // 0x80006BA4: lhu         $v0, 0xE($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0XE);
    // 0x80006BA8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80006BAC: slt         $v0, $s3, $v0
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80006BB0: beq         $v0, $zero, L_80006BC8
    if (ctx->r2 == 0) {
        // 0x80006BB4: nop
    
            goto L_80006BC8;
    }
    // 0x80006BB4: nop

    // 0x80006BB8: j           L_80006B24
    // 0x80006BBC: nop

        goto L_80006B24;
    // 0x80006BBC: nop

L_80006BC0:
    // 0x80006BC0: jal         0x80006198
    // 0x80006BC4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_80006198(rdram, ctx);
        goto after_6;
    // 0x80006BC4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_6:
L_80006BC8:
    // 0x80006BC8: jal         0x800032E0
    // 0x80006BCC: nop

    func_800032E0(rdram, ctx);
        goto after_7;
    // 0x80006BCC: nop

    after_7:
    // 0x80006BD0: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80006BD4: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x80006BD8: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x80006BDC: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80006BE0: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80006BE4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80006BE8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80006BEC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80006BF0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80006BF4: jr          $ra
    // 0x80006BF8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80006BF8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void fake_func_80006BFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80006C00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006C00: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80006C04: sw          $zero, 0x28D0($v0)
    MEM_W(0X28D0, ctx->r2) = 0;
    // 0x80006C08: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80006C0C: sw          $zero, 0x28D4($v0)
    MEM_W(0X28D4, ctx->r2) = 0;
    // 0x80006C10: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80006C14: sh          $zero, 0x28D8($v0)
    MEM_H(0X28D8, ctx->r2) = 0;
    // 0x80006C18: jr          $ra
    // 0x80006C1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80006C1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80006C20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006C20: jr          $ra
    // 0x80006C24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80006C24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80006C28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    { fprintf(stderr, "[trace] worker_spawn a0=%u a1=%u entry=0x%08X arg=0x%08X\n", (uint32_t)ctx->r4, (uint32_t)ctx->r5, (uint32_t)ctx->r6, (uint32_t)ctx->r7); fflush(stderr); }
    // 0x80006C28: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80006C2C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80006C30: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80006C34: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80006C38: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80006C3C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80006C40: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x80006C44: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80006C48: addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // 0x80006C4C: addiu       $v0, $s1, 0x20
    ctx->r2 = ADD32(ctx->r17, 0X20);
    // 0x80006C50: srl         $v0, $v0, 3
    ctx->r2 = S32(U32(ctx->r2) >> 3);
    // 0x80006C54: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80006C58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80006C5C: andi        $s0, $s2, 0xFFFF
    ctx->r16 = ctx->r18 & 0XFFFF;
    // 0x80006C60: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x80006C64: addiu       $v0, $v0, 0x1F0
    ctx->r2 = ADD32(ctx->r2, 0X1F0);
    // 0x80006C68: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80006C6C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80006C70: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    // 0x80006C74: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80006C78: jal         0x80001ACC
    // 0x80006C7C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x80006C7C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    after_0:
    // 0x80006C80: lui         $a2, 0xCDCD
    ctx->r6 = S32(0XCDCD << 16);
    // 0x80006C84: ori         $a2, $a2, 0xCDCD
    ctx->r6 = ctx->r6 | 0XCDCD;
    // 0x80006C88: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // 0x80006C8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80006C90: addiu       $s1, $s1, 0x7
    ctx->r17 = ADD32(ctx->r17, 0X7);
    // 0x80006C94: srl         $s1, $s1, 3
    ctx->r17 = S32(U32(ctx->r17) >> 3);
    // 0x80006C98: sll         $s1, $s1, 3
    ctx->r17 = S32(ctx->r17 << 3);
    // 0x80006C9C: addu        $s0, $s5, $s0
    ctx->r16 = ADD32(ctx->r21, ctx->r16);
    // 0x80006CA0: addiu       $s0, $s0, -0x8
    ctx->r16 = ADD32(ctx->r16, -0X8);
    // 0x80006CA4: srl         $s0, $s0, 3
    ctx->r16 = S32(U32(ctx->r16) >> 3);
    // 0x80006CA8: sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16 << 3);
    // 0x80006CAC: sb          $v0, 0x5($s5)
    MEM_B(0X5, ctx->r21) = ctx->r2;
    // 0x80006CB0: addiu       $v0, $s5, 0x1F0
    ctx->r2 = ADD32(ctx->r21, 0X1F0);
    // 0x80006CB4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80006CB8: sw          $s0, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->r16;
    // 0x80006CBC: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x80006CC0: sw          $s1, 0x10($s5)
    MEM_W(0X10, ctx->r21) = ctx->r17;
    // 0x80006CC4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80006CC8: sw          $v0, 0x1C($s5)
    MEM_W(0X1C, ctx->r21) = ctx->r2;
    // 0x80006CCC: lw          $v0, 0x28D4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28D4);
    // 0x80006CD0: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x80006CD4: sw          $zero, 0x18($s5)
    MEM_W(0X18, ctx->r21) = 0;
    // 0x80006CD8: sw          $s3, 0x14($s5)
    MEM_W(0X14, ctx->r21) = ctx->r19;
    // 0x80006CDC: sh          $s2, 0x6($s5)
    MEM_H(0X6, ctx->r21) = ctx->r18;
    // 0x80006CE0: sw          $v1, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r3;
    // 0x80006CE4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80006CE8: sw          $v0, 0x28D4($a0)
    MEM_W(0X28D4, ctx->r4) = ctx->r2;
    // 0x80006CEC: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
    // 0x80006CF0: sb          $s4, 0x4($s5)
    MEM_B(0X4, ctx->r21) = ctx->r20;
    // 0x80006CF4: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x80006CF8: lw          $v0, 0xC($s5)
    ctx->r2 = MEM_W(ctx->r21, 0XC);
    // 0x80006CFC: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x80006D00: lhu         $v0, 0x6($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X6);
    // 0x80006D04: beq         $v0, $zero, L_80006D18
    if (ctx->r2 == 0) {
        // 0x80006D08: addu        $a2, $v0, $zero
        ctx->r6 = ADD32(ctx->r2, 0);
            goto L_80006D18;
    }
    // 0x80006D08: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80006D0C: lw          $a1, 0x1C($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X1C);
    // 0x80006D10: jal         0x8002B300
    // 0x80006D14: addiu       $a0, $s5, 0x1D0
    ctx->r4 = ADD32(ctx->r21, 0X1D0);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80006D14: addiu       $a0, $s5, 0x1D0
    ctx->r4 = ADD32(ctx->r21, 0X1D0);
    after_1:
L_80006D18:
    // 0x80006D18: lw          $v0, 0x8($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X8);
    // 0x80006D1C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80006D20: lbu         $v0, 0x4($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X4);
    // 0x80006D24: addiu       $a0, $s5, 0x20
    ctx->r4 = ADD32(ctx->r21, 0X20);
    // 0x80006D28: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80006D2C: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    // 0x80006D30: lw          $a2, 0x14($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X14);
    // 0x80006D34: jal         0x8002B330
    // 0x80006D38: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    osCreateThread_recomp(rdram, ctx);
        goto after_2;
    // 0x80006D38: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    after_2:
    { fprintf(stderr, "[trace] worker_spawn: osCreateThread done, struct@$s5 id=*(0)=will-be-logged-on-next-iteration\n"); fflush(stderr); }
    // 0x80006D3C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80006D40: lw          $v0, 0x28D0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28D0);
    // 0x80006D44: bnel        $v0, $zero, L_80006D54
    if (ctx->r2 != 0) {
        // 0x80006D48: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_80006D54;
    }
    goto skip_0;
    // 0x80006D48: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    skip_0:
    // 0x80006D4C: j           L_80006D74
    // 0x80006D50: sw          $s5, 0x28D0($v1)
    MEM_W(0X28D0, ctx->r3) = ctx->r21;
        goto L_80006D74;
    // 0x80006D50: sw          $s5, 0x28D0($v1)
    MEM_W(0X28D0, ctx->r3) = ctx->r21;
L_80006D54:
    // 0x80006D54: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x80006D58: beql        $v0, $zero, L_80006D74
    if (ctx->r2 == 0) {
        // 0x80006D5C: sw          $s5, 0x18($v1)
        MEM_W(0X18, ctx->r3) = ctx->r21;
            goto L_80006D74;
    }
    goto skip_1;
    // 0x80006D5C: sw          $s5, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r21;
    skip_1:
L_80006D60:
    // 0x80006D60: lw          $v1, 0x18($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X18);
    // 0x80006D64: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x80006D68: bne         $v0, $zero, L_80006D60
    if (ctx->r2 != 0) {
        // 0x80006D6C: nop
    
            goto L_80006D60;
    }
    // 0x80006D6C: nop

    // 0x80006D70: sw          $s5, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r21;
L_80006D74:
    // 0x80006D74: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x80006D78: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80006D7C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80006D80: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80006D84: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80006D88: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80006D8C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80006D90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80006D94: jr          $ra
    // 0x80006D98: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80006D98: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80006D9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006D9C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80006DA0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80006DA4: lw          $a0, 0x28D0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X28D0);
    // 0x80006DA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80006DAC: beq         $a0, $zero, L_80006DCC
    if (ctx->r4 == 0) {
        // 0x80006DB0: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80006DCC;
    }
    // 0x80006DB0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
L_80006DB4:
    // 0x80006DB4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80006DB8: beq         $v0, $v1, L_80006DD0
    if (ctx->r2 == ctx->r3) {
        // 0x80006DBC: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80006DD0;
    }
    // 0x80006DBC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80006DC0: lw          $a0, 0x18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X18);
    // 0x80006DC4: bne         $a0, $zero, L_80006DB4
    if (ctx->r4 != 0) {
        // 0x80006DC8: nop
    
            goto L_80006DB4;
    }
    // 0x80006DC8: nop

L_80006DCC:
    // 0x80006DCC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80006DD0:
    // 0x80006DD0: sb          $v0, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r2;
    // 0x80006DD4: jal         0x800344E0
    // 0x80006DD8: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    osStartThread_recomp(rdram, ctx);
        goto after_0;
    // 0x80006DD8: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_0:
    // 0x80006DDC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80006DE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80006DE4: jr          $ra
    // 0x80006DE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80006DE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80006DEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006DEC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80006DF0: lw          $v1, 0x28D0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X28D0);
    // 0x80006DF4: beq         $v1, $zero, L_80006E14
    if (ctx->r3 == 0) {
        // 0x80006DF8: nop
    
            goto L_80006E14;
    }
    // 0x80006DF8: nop

L_80006DFC:
    // 0x80006DFC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80006E00: beq         $v0, $a0, L_80006E14
    if (ctx->r2 == ctx->r4) {
        // 0x80006E04: nop
    
            goto L_80006E14;
    }
    // 0x80006E04: nop

    // 0x80006E08: lw          $v1, 0x18($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X18);
    // 0x80006E0C: bne         $v1, $zero, L_80006DFC
    if (ctx->r3 != 0) {
        // 0x80006E10: nop
    
            goto L_80006DFC;
    }
    // 0x80006E10: nop

L_80006E14:
    // 0x80006E14: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    // 0x80006E18: lui         $v0, 0xCDCD
    ctx->r2 = S32(0XCDCD << 16);
    // 0x80006E1C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80006E20: ori         $v0, $v0, 0xCDCD
    ctx->r2 = ctx->r2 | 0XCDCD;
    // 0x80006E24: bne         $v1, $v0, L_80006E38
    if (ctx->r3 != ctx->r2) {
        // 0x80006E28: nop
    
            goto L_80006E38;
    }
    // 0x80006E28: nop

    // 0x80006E2C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80006E30: beq         $v0, $v1, L_80006E40
    if (ctx->r2 == ctx->r3) {
        // 0x80006E34: nop
    
            goto L_80006E40;
    }
    // 0x80006E34: nop

L_80006E38:
    // 0x80006E38: jr          $ra
    // 0x80006E3C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80006E3C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80006E40:
    // 0x80006E40: jr          $ra
    // 0x80006E44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80006E44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80006E48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006E48: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80006E4C: lw          $a1, 0x28D0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X28D0);
    // 0x80006E50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80006E54: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80006E58: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80006E5C: beq         $a1, $zero, L_80006E7C
    if (ctx->r5 == 0) {
        // 0x80006E60: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_80006E7C;
    }
    // 0x80006E60: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_80006E64:
    // 0x80006E64: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80006E68: beq         $v0, $a0, L_80006E80
    if (ctx->r2 == ctx->r4) {
        // 0x80006E6C: addiu       $s1, $a1, 0x1D0
        ctx->r17 = ADD32(ctx->r5, 0X1D0);
            goto L_80006E80;
    }
    // 0x80006E6C: addiu       $s1, $a1, 0x1D0
    ctx->r17 = ADD32(ctx->r5, 0X1D0);
    // 0x80006E70: lw          $a1, 0x18($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X18);
    // 0x80006E74: bne         $a1, $zero, L_80006E64
    if (ctx->r5 != 0) {
        // 0x80006E78: nop
    
            goto L_80006E64;
    }
    // 0x80006E78: nop

L_80006E7C:
    // 0x80006E7C: addiu       $s1, $a1, 0x1D0
    ctx->r17 = ADD32(ctx->r5, 0X1D0);
L_80006E80:
    // 0x80006E80: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80006E84: addiu       $s0, $a1, 0x1E8
    ctx->r16 = ADD32(ctx->r5, 0X1E8);
    // 0x80006E88: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80006E8C: jal         0x800331D0
    // 0x80006E90: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80006E90: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x80006E94: bne         $v0, $zero, L_80006EB0
    if (ctx->r2 != 0) {
        // 0x80006E98: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80006EB0;
    }
    // 0x80006E98: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80006E9C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80006EA0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80006EA4: jal         0x8002C3B0
    // 0x80006EA8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osJamMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80006EA8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // 0x80006EAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80006EB0:
    // 0x80006EB0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80006EB4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80006EB8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80006EBC: jr          $ra
    // 0x80006EC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80006EC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80006EC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006EC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80006EC8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80006ECC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80006ED0: lw          $s0, 0x28D0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X28D0);
    // 0x80006ED4: beq         $s0, $zero, L_80006EF4
    if (ctx->r16 == 0) {
        // 0x80006ED8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80006EF4;
    }
    // 0x80006ED8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
L_80006EDC:
    // 0x80006EDC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80006EE0: beql        $v0, $a0, L_80006EF8
    if (ctx->r2 == ctx->r4) {
        // 0x80006EE4: addiu       $a0, $s0, 0x1D0
        ctx->r4 = ADD32(ctx->r16, 0X1D0);
            goto L_80006EF8;
    }
    goto skip_0;
    // 0x80006EE4: addiu       $a0, $s0, 0x1D0
    ctx->r4 = ADD32(ctx->r16, 0X1D0);
    skip_0:
    // 0x80006EE8: lw          $s0, 0x18($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X18);
    // 0x80006EEC: bne         $s0, $zero, L_80006EDC
    if (ctx->r16 != 0) {
        // 0x80006EF0: nop
    
            goto L_80006EDC;
    }
    // 0x80006EF0: nop

L_80006EF4:
    // 0x80006EF4: addiu       $a0, $s0, 0x1D0
    ctx->r4 = ADD32(ctx->r16, 0X1D0);
L_80006EF8:
    // 0x80006EF8: addiu       $a1, $s0, 0x1E8
    ctx->r5 = ADD32(ctx->r16, 0X1E8);
    // 0x80006EFC: jal         0x800331D0
    // 0x80006F00: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80006F00: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x80006F04: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80006F08: beq         $v0, $v1, L_80006F14
    if (ctx->r2 == ctx->r3) {
        // 0x80006F0C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80006F14;
    }
    // 0x80006F0C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80006F10: lw          $v0, 0x1E8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E8);
L_80006F14:
    // 0x80006F14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006F18: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80006F1C: jr          $ra
    // 0x80006F20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80006F20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80006F24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006F24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80006F28: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80006F2C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80006F30: lw          $s0, 0x28D0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X28D0);
    // 0x80006F34: beq         $s0, $zero, L_80006F54
    if (ctx->r16 == 0) {
        // 0x80006F38: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80006F54;
    }
    // 0x80006F38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
L_80006F3C:
    // 0x80006F3C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80006F40: beql        $v0, $a0, L_80006F58
    if (ctx->r2 == ctx->r4) {
        // 0x80006F44: addiu       $a0, $s0, 0x1D0
        ctx->r4 = ADD32(ctx->r16, 0X1D0);
            goto L_80006F58;
    }
    goto skip_0;
    // 0x80006F44: addiu       $a0, $s0, 0x1D0
    ctx->r4 = ADD32(ctx->r16, 0X1D0);
    skip_0:
    // 0x80006F48: lw          $s0, 0x18($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X18);
    // 0x80006F4C: bne         $s0, $zero, L_80006F3C
    if (ctx->r16 != 0) {
        // 0x80006F50: nop
    
            goto L_80006F3C;
    }
    // 0x80006F50: nop

L_80006F54:
    // 0x80006F54: addiu       $a0, $s0, 0x1D0
    ctx->r4 = ADD32(ctx->r16, 0X1D0);
L_80006F58:
    // 0x80006F58: addiu       $a1, $s0, 0x1E8
    ctx->r5 = ADD32(ctx->r16, 0X1E8);
    // 0x80006F5C: jal         0x800331D0
    // 0x80006F60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80006F60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80006F64: lw          $v0, 0x1E8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E8);
    // 0x80006F68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006F6C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80006F70: jr          $ra
    // 0x80006F74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80006F74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80006F78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    { static int n=0; if (++n<=20 || (n%500)==0) { fprintf(stderr, "[trace] func_80006F78(reg) #%d id_a=0x%08X id_b=0x%08X msg=0x%08X flags=%u\n", n, (uint32_t)ctx->r4, (uint32_t)ctx->r5, (uint32_t)ctx->r6, (uint32_t)ctx->r7); fflush(stderr); } }
    // 0x80006F78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80006F7C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80006F80: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80006F84: lw          $s0, 0x28D0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X28D0);
    // 0x80006F88: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80006F8C: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x80006F90: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80006F94: addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    // 0x80006F98: beq         $s0, $zero, L_80006FB8
    if (ctx->r16 == 0) {
        // 0x80006F9C: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80006FB8;
    }
    // 0x80006F9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
L_80006FA0:
    // 0x80006FA0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80006FA4: beq         $v0, $a1, L_80006FB8
    if (ctx->r2 == ctx->r5) {
        // 0x80006FA8: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80006FB8;
    }
    // 0x80006FA8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80006FAC: lw          $s0, 0x18($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X18);
    // 0x80006FB0: bne         $s0, $zero, L_80006FA0
    if (ctx->r16 != 0) {
        // 0x80006FB4: nop
    
            goto L_80006FA0;
    }
    // 0x80006FB4: nop

L_80006FB8:
    // 0x80006FB8: lw          $a1, 0x28D0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X28D0);
    // 0x80006FBC: beq         $a1, $zero, L_80006FDC
    if (ctx->r5 == 0) {
        // 0x80006FC0: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80006FDC;
    }
    // 0x80006FC0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
L_80006FC4:
    // 0x80006FC4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80006FC8: beq         $v0, $a0, L_80006FDC
    if (ctx->r2 == ctx->r4) {
        // 0x80006FCC: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80006FDC;
    }
    // 0x80006FCC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80006FD0: lw          $a1, 0x18($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X18);
    // 0x80006FD4: bne         $a1, $zero, L_80006FC4
    if (ctx->r5 != 0) {
        // 0x80006FD8: nop
    
            goto L_80006FC4;
    }
    // 0x80006FD8: nop

L_80006FDC:
    // 0x80006FDC: sb          $zero, 0x4($s1)
    MEM_B(0X4, ctx->r17) = 0;
    // 0x80006FE0: lhu         $a0, 0x28D8($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X28D8);
    // 0x80006FE4: addiu       $v0, $a1, 0x1D0
    ctx->r2 = ADD32(ctx->r5, 0X1D0);
    // 0x80006FE8: sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    // 0x80006FEC: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80006FF0: sh          $v0, 0x28D8($v1)
    MEM_H(0X28D8, ctx->r3) = ctx->r2;
    // 0x80006FF4: sh          $a0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r4;
    // 0x80006FF8: addiu       $a0, $s0, 0x1D0
    ctx->r4 = ADD32(ctx->r16, 0X1D0);
L_80006FFC:
    // 0x80006FFC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80007000: jal         0x80033410
    // 0x80007004: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80007004: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x80007008: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8000700C: bne         $v0, $v1, L_80007024
    if (ctx->r2 != ctx->r3) {
        // 0x80007010: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80007024;
    }
    // 0x80007010: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80007014: andi        $v0, $s2, 0x1
    ctx->r2 = ctx->r18 & 0X1;
    // 0x80007018: bne         $v0, $zero, L_80006FFC
    if (ctx->r2 != 0) {
        // 0x8000701C: addiu       $a0, $s0, 0x1D0
        ctx->r4 = ADD32(ctx->r16, 0X1D0);
            goto L_80006FFC;
    }
    // 0x8000701C: addiu       $a0, $s0, 0x1D0
    ctx->r4 = ADD32(ctx->r16, 0X1D0);
    // 0x80007020: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80007024:
    // 0x80007024: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80007028: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8000702C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80007030: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80007034: jr          $ra
    // 0x80007038: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80007038: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8000703C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000703C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007040: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80007044: lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4);
    // 0x80007048: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8000704C: ori         $v0, $v0, 0x40
    ctx->r2 = ctx->r2 | 0X40;
    // 0x80007050: sb          $v0, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r2;
    // 0x80007054: lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X8);
    // 0x80007058: jal         0x8002C3B0
    // 0x8000705C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osJamMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8000705C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80007060: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80007064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007064: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80007068: jr          $ra
    // 0x8000706C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000706C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80007070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    { static int n=0; if (++n<=20 || (n%500)==0) { fprintf(stderr, "[trace] func_80007070(send) #%d id=0x%08X\n", n, (uint32_t)ctx->r4); fflush(stderr); } }
    // 0x80007070: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80007074: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80007078: lw          $a0, 0x28D0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X28D0);
    // 0x8000707C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007080: beq         $a0, $zero, L_800070A0
    if (ctx->r4 == 0) {
        // 0x80007084: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_800070A0;
    }
    // 0x80007084: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
L_80007088:
    // 0x80007088: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000708C: beql        $v0, $v1, L_800070A4
    if (ctx->r2 == ctx->r3) {
        // 0x80007090: addiu       $a0, $a0, 0x1D0
        ctx->r4 = ADD32(ctx->r4, 0X1D0);
            goto L_800070A4;
    }
    goto skip_0;
    // 0x80007090: addiu       $a0, $a0, 0x1D0
    ctx->r4 = ADD32(ctx->r4, 0X1D0);
    skip_0:
    // 0x80007094: lw          $a0, 0x18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X18);
    // 0x80007098: bne         $a0, $zero, L_80007088
    if (ctx->r4 != 0) {
        // 0x8000709C: nop
    
            goto L_80007088;
    }
    // 0x8000709C: nop

L_800070A0:
    // 0x800070A0: addiu       $a0, $a0, 0x1D0
    ctx->r4 = ADD32(ctx->r4, 0X1D0);
L_800070A4:
    // 0x800070A4: jal         0x80033410
    // 0x800070A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800070A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800070AC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800070B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800070B4: jr          $ra
    // 0x800070B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800070B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800070BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800070BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800070C0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800070C4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800070C8: lw          $s0, 0x28D0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X28D0);
    // 0x800070CC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800070D0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800070D4: beq         $s0, $zero, L_800070F8
    if (ctx->r16 == 0) {
        // 0x800070D8: addu        $s1, $s0, $zero
        ctx->r17 = ADD32(ctx->r16, 0);
            goto L_800070F8;
    }
    // 0x800070D8: addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
L_800070DC:
    // 0x800070DC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800070E0: beql        $v0, $a0, L_800070FC
    if (ctx->r2 == ctx->r4) {
        // 0x800070E4: addiu       $a0, $s0, 0x20
        ctx->r4 = ADD32(ctx->r16, 0X20);
            goto L_800070FC;
    }
    goto skip_0;
    // 0x800070E4: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    skip_0:
    // 0x800070E8: addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
    // 0x800070EC: lw          $s0, 0x18($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X18);
    // 0x800070F0: bne         $s0, $zero, L_800070DC
    if (ctx->r16 != 0) {
        // 0x800070F4: nop
    
            goto L_800070DC;
    }
    // 0x800070F4: nop

L_800070F8:
    // 0x800070F8: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
L_800070FC:
    // 0x800070FC: jal         0x8002B480
    // 0x80007100: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    osDestroyThread_recomp(rdram, ctx);
        goto after_0;
    // 0x80007100: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    after_0:
    // 0x80007104: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80007108: lw          $v0, 0x28D0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28D0);
    // 0x8000710C: bne         $s0, $v0, L_80007120
    if (ctx->r16 != ctx->r2) {
        // 0x80007110: nop
    
            goto L_80007120;
    }
    // 0x80007110: nop

    // 0x80007114: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x80007118: j           L_80007128
    // 0x8000711C: sw          $v0, 0x28D0($v1)
    MEM_W(0X28D0, ctx->r3) = ctx->r2;
        goto L_80007128;
    // 0x8000711C: sw          $v0, 0x28D0($v1)
    MEM_W(0X28D0, ctx->r3) = ctx->r2;
L_80007120:
    // 0x80007120: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x80007124: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
L_80007128:
    // 0x80007128: jal         0x80001C98
    // 0x8000712C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    rs_free(rdram, ctx);
        goto after_1;
    // 0x8000712C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80007130: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80007134: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80007138: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000713C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80007140: jr          $ra
    // 0x80007144: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80007144: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80007148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007148: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000714C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80007150: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80007154: lw          $s1, 0x28D0($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X28D0);
    // 0x80007158: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8000715C: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x80007160: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80007164: addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    // 0x80007168: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8000716C: beq         $s1, $zero, L_8000718C
    if (ctx->r17 == 0) {
        // 0x80007170: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_8000718C;
    }
    // 0x80007170: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_80007174:
    // 0x80007174: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80007178: beq         $v0, $a1, L_8000718C
    if (ctx->r2 == ctx->r5) {
        // 0x8000717C: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_8000718C;
    }
    // 0x8000717C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80007180: lw          $s1, 0x18($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X18);
    // 0x80007184: bne         $s1, $zero, L_80007174
    if (ctx->r17 != 0) {
        // 0x80007188: nop
    
            goto L_80007174;
    }
    // 0x80007188: nop

L_8000718C:
    // 0x8000718C: lw          $s0, 0x28D0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X28D0);
    // 0x80007190: beq         $s0, $zero, L_800071B0
    if (ctx->r16 == 0) {
        // 0x80007194: addiu       $v0, $zero, 0x80
        ctx->r2 = ADD32(0, 0X80);
            goto L_800071B0;
    }
    // 0x80007194: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
L_80007198:
    // 0x80007198: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000719C: beq         $v0, $a0, L_800071B0
    if (ctx->r2 == ctx->r4) {
        // 0x800071A0: addiu       $v0, $zero, 0x80
        ctx->r2 = ADD32(0, 0X80);
            goto L_800071B0;
    }
    // 0x800071A0: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x800071A4: lw          $s0, 0x18($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X18);
    // 0x800071A8: bne         $s0, $zero, L_80007198
    if (ctx->r16 != 0) {
        // 0x800071AC: nop
    
            goto L_80007198;
    }
    // 0x800071AC: nop

L_800071B0:
    // 0x800071B0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800071B4: sb          $v0, 0x4($s3)
    MEM_B(0X4, ctx->r19) = ctx->r2;
    // 0x800071B8: lhu         $a0, 0x28D8($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X28D8);
    // 0x800071BC: addiu       $v0, $s0, 0x1D0
    ctx->r2 = ADD32(ctx->r16, 0X1D0);
    // 0x800071C0: sw          $v0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r2;
    // 0x800071C4: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x800071C8: sh          $v0, 0x28D8($v1)
    MEM_H(0X28D8, ctx->r3) = ctx->r2;
    // 0x800071CC: sh          $a0, 0x2($s3)
    MEM_H(0X2, ctx->r19) = ctx->r4;
    // 0x800071D0: addiu       $a0, $s1, 0x1D0
    ctx->r4 = ADD32(ctx->r17, 0X1D0);
L_800071D4:
    // 0x800071D4: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800071D8: jal         0x80033410
    // 0x800071DC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800071DC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x800071E0: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800071E4: bnel        $v0, $v1, L_80007200
    if (ctx->r2 != ctx->r3) {
        // 0x800071E8: addiu       $s2, $s0, 0x1D0
        ctx->r18 = ADD32(ctx->r16, 0X1D0);
            goto L_80007200;
    }
    goto skip_0;
    // 0x800071E8: addiu       $s2, $s0, 0x1D0
    ctx->r18 = ADD32(ctx->r16, 0X1D0);
    skip_0:
    // 0x800071EC: andi        $v0, $s2, 0x1
    ctx->r2 = ctx->r18 & 0X1;
    // 0x800071F0: bne         $v0, $zero, L_800071D4
    if (ctx->r2 != 0) {
        // 0x800071F4: addiu       $a0, $s1, 0x1D0
        ctx->r4 = ADD32(ctx->r17, 0X1D0);
            goto L_800071D4;
    }
    // 0x800071F4: addiu       $a0, $s1, 0x1D0
    ctx->r4 = ADD32(ctx->r17, 0X1D0);
    // 0x800071F8: j           L_80007240
    // 0x800071FC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80007240;
    // 0x800071FC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80007200:
    // 0x80007200: addiu       $s1, $s0, 0x1E8
    ctx->r17 = ADD32(ctx->r16, 0X1E8);
    // 0x80007204: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_80007208:
    // 0x80007208: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8000720C: jal         0x800331D0
    // 0x80007210: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80007210: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80007214: lw          $v0, 0x1E8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E8);
    // 0x80007218: lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X2);
    // 0x8000721C: lhu         $v0, 0x2($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X2);
    // 0x80007220: beq         $v1, $v0, L_8000723C
    if (ctx->r3 == ctx->r2) {
        // 0x80007224: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_8000723C;
    }
    // 0x80007224: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80007228: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8000722C: jal         0x80033410
    // 0x80007230: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80007230: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80007234: j           L_80007208
    // 0x80007238: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
        goto L_80007208;
    // 0x80007238: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_8000723C:
    // 0x8000723C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80007240:
    // 0x80007240: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80007244: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80007248: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8000724C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80007250: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80007254: jr          $ra
    // 0x80007258: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80007258: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8000725C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000725C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80007260: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80007264: lw          $a0, 0x28D0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X28D0);
    // 0x80007268: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000726C: beq         $a0, $zero, L_8000728C
    if (ctx->r4 == 0) {
        // 0x80007270: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8000728C;
    }
    // 0x80007270: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
L_80007274:
    // 0x80007274: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80007278: beql        $v0, $v1, L_80007290
    if (ctx->r2 == ctx->r3) {
        // 0x8000727C: sb          $a1, 0x4($a0)
        MEM_B(0X4, ctx->r4) = ctx->r5;
            goto L_80007290;
    }
    goto skip_0;
    // 0x8000727C: sb          $a1, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r5;
    skip_0:
    // 0x80007280: lw          $a0, 0x18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X18);
    // 0x80007284: bne         $a0, $zero, L_80007274
    if (ctx->r4 != 0) {
        // 0x80007288: nop
    
            goto L_80007274;
    }
    // 0x80007288: nop

L_8000728C:
    // 0x8000728C: sb          $a1, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r5;
L_80007290:
    // 0x80007290: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x80007294: jal         0x800336E0
    // 0x80007298: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    osSetThreadPri_recomp(rdram, ctx);
        goto after_0;
    // 0x80007298: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_0:
    // 0x8000729C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800072A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800072A4: jr          $ra
    // 0x800072A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800072A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800072AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800072AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800072B0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800072B4: jal         0x80037510
    // 0x800072B8: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_0;
    // 0x800072B8: nop

    after_0:
    // 0x800072BC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800072C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800072C4: jr          $ra
    // 0x800072C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800072C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800072CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800072CC: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x800072D0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800072D4: lw          $a0, 0x28D0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X28D0);
    // 0x800072D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800072DC: beq         $a0, $zero, L_800072FC
    if (ctx->r4 == 0) {
        // 0x800072E0: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_800072FC;
    }
    // 0x800072E0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
L_800072E4:
    // 0x800072E4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800072E8: beq         $v0, $v1, L_80007300
    if (ctx->r2 == ctx->r3) {
        // 0x800072EC: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80007300;
    }
    // 0x800072EC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800072F0: lw          $a0, 0x18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X18);
    // 0x800072F4: bne         $a0, $zero, L_800072E4
    if (ctx->r4 != 0) {
        // 0x800072F8: nop
    
            goto L_800072E4;
    }
    // 0x800072F8: nop

L_800072FC:
    // 0x800072FC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80007300:
    // 0x80007300: sb          $v0, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r2;
    // 0x80007304: jal         0x80034630
    // 0x80007308: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    osStopThread_recomp(rdram, ctx);
        goto after_0;
    // 0x80007308: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_0:
    // 0x8000730C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80007310: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80007314: jr          $ra
    // 0x80007318: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80007318: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8000731C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000731C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80007320: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80007324: lw          $a0, 0x28D0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X28D0);
    // 0x80007328: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000732C: beq         $a0, $zero, L_8000734C
    if (ctx->r4 == 0) {
        // 0x80007330: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8000734C;
    }
    // 0x80007330: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
L_80007334:
    // 0x80007334: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80007338: beq         $v0, $v1, L_80007350
    if (ctx->r2 == ctx->r3) {
        // 0x8000733C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80007350;
    }
    // 0x8000733C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80007340: lw          $a0, 0x18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X18);
    // 0x80007344: bne         $a0, $zero, L_80007334
    if (ctx->r4 != 0) {
        // 0x80007348: nop
    
            goto L_80007334;
    }
    // 0x80007348: nop

L_8000734C:
    // 0x8000734C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80007350:
    // 0x80007350: sb          $v0, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r2;
    // 0x80007354: jal         0x800344E0
    // 0x80007358: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    osStartThread_recomp(rdram, ctx);
        goto after_0;
    // 0x80007358: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_0:
    // 0x8000735C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80007360: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80007364: jr          $ra
    // 0x80007368: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80007368: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8000736C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000736C: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x80007370: jr          $ra
    // 0x80007374: nop

    return;
    // 0x80007374: nop

;}
RECOMP_FUNC void fake_func_8000737C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80007380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007380: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80007384: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80007388: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x8000738C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80007390: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80007394: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80007398: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x8000739C: addiu       $s1, $s1, 0x2910
    ctx->r17 = ADD32(ctx->r17, 0X2910);
    // 0x800073A0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800073A4: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    // 0x800073A8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800073AC: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x800073B0: jal         0x8002B300
    // 0x800073B4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800073B4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    after_0:
    // 0x800073B8: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    // 0x800073BC: jal         0x80001ACC
    // 0x800073C0: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x800073C0: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_1:
    // 0x800073C4: addiu       $s2, $s1, 0x20
    ctx->r18 = ADD32(ctx->r17, 0X20);
    // 0x800073C8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800073CC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800073D0: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x800073D4: addiu       $a2, $a2, 0x7480
    ctx->r6 = ADD32(ctx->r6, 0X7480);
    // 0x800073D8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800073DC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800073E0: sw          $v0, 0x28E4($at)
    MEM_W(0X28E4, ctx->r1) = ctx->r2;
    // 0x800073E4: addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
    // 0x800073E8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800073EC: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x800073F0: jal         0x8002B330
    // 0x800073F4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    osCreateThread_recomp(rdram, ctx);
        goto after_2;
    // 0x800073F4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_2:
    // 0x800073F8: jal         0x800344E0
    // 0x800073FC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    osStartThread_recomp(rdram, ctx);
        goto after_3;
    // 0x800073FC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_3:
    // 0x80007400: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x80007404: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80007408: sll         $v1, $v0, 6
    ctx->r3 = S32(ctx->r2 << 6);
    // 0x8000740C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80007410: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80007414: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80007418: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000741C: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80007420: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80007424: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80007428: addu        $t1, $v1, $zero
    ctx->r9 = ADD32(ctx->r3, 0);
    // 0x8000742C: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80007430: addiu       $a0, $s1, -0x20
    ctx->r4 = ADD32(ctx->r17, -0X20);
    // 0x80007434: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80007438: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8000743C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80007440: sw          $s3, 0x28E0($at)
    MEM_W(0X28E0, ctx->r1) = ctx->r19;
    // 0x80007444: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80007448: sw          $v1, 0x28E8($at)
    MEM_W(0X28E8, ctx->r1) = ctx->r3;
    // 0x8000744C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80007450: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80007454: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80007458: jal         0x800337C0
    // 0x8000745C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    osSetTimer_recomp(rdram, ctx);
        goto after_4;
    // 0x8000745C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_4:
    // 0x80007460: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80007464: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80007468: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8000746C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80007470: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80007474: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80007478: jr          $ra
    // 0x8000747C: nop

    return;
    // 0x8000747C: nop

;}
RECOMP_FUNC void func_80007480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007480: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007484: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80007488: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x8000748C: addiu       $s0, $s0, 0x2910
    ctx->r16 = ADD32(ctx->r16, 0X2910);
    // 0x80007490: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007494: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80007498:
    // 0x80007498: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8000749C: jal         0x800331D0
    // 0x800074A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800074A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800074A4: jal         0x80037510
    // 0x800074A8: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800074A8: nop

    after_1:
    // 0x800074AC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800074B0: lw          $v0, 0x28E0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X28E0);
    // 0x800074B4: jalr        $v0
    // 0x800074B8: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x800074B8: nop

    after_2:
    // 0x800074BC: j           L_80007498
    // 0x800074C0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80007498;
    // 0x800074C0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800074C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800074C8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800074CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800074D0: jr          $ra
    // 0x800074D4: nop

    return;
    // 0x800074D4: nop

;}
RECOMP_FUNC void fake_func_800074D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800074E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800074E0: dsll32      $v0, $a0, 0
    ctx->r2 = ctx->r4 << (0 + 32);
    // 0x800074E4: dsll32      $v1, $a1, 0
    ctx->r3 = ctx->r5 << (0 + 32);
    // 0x800074E8: dsrl32      $v1, $v1, 0
    ctx->r3 = ctx->r3 >> (0 + 32);
    // 0x800074EC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800074F0: dsll32      $v1, $a2, 0
    ctx->r3 = ctx->r6 << (0 + 32);
    // 0x800074F4: dsll32      $t0, $a3, 0
    ctx->r8 = ctx->r7 << (0 + 32);
    // 0x800074F8: dsrl32      $t0, $t0, 0
    ctx->r8 = ctx->r8 >> (0 + 32);
    // 0x800074FC: or          $v1, $v1, $t0
    ctx->r3 = ctx->r3 | ctx->r8;
    // 0x80007500: ddivu       $zero, $v0, $v1
    DDIVU(U64(ctx->r2), U64(ctx->r3), &lo, &hi);
    // 0x80007504: mflo        $v1
    ctx->r3 = lo;
    // 0x80007508: jr          $ra
    // 0x8000750C: dsrl32      $v0, $v1, 0
    ctx->r2 = ctx->r3 >> (0 + 32);
    return;
    // 0x8000750C: dsrl32      $v0, $v1, 0
    ctx->r2 = ctx->r3 >> (0 + 32);
;}
RECOMP_FUNC void func_80007510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007510: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x80007514: jr          $ra
    // 0x80007518: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    return;
    // 0x80007518: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
;}
RECOMP_FUNC void fake_func_8000751C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void rs_strcasecmp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007520: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80007524: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80007528: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8000752C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80007530: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x80007534: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80007538: jal         0x8003471C
    // 0x8000753C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    strlen_recomp(rdram, ctx);
        goto after_0;
    // 0x8000753C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80007540: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80007544: jal         0x8003471C
    // 0x80007548: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    strlen_recomp(rdram, ctx);
        goto after_1;
    // 0x80007548: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_1:
    // 0x8000754C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80007550: slt         $v0, $v1, $s0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80007554: bnel        $v0, $zero, L_8000755C
    if (ctx->r2 != 0) {
        // 0x80007558: addu        $v1, $s0, $zero
        ctx->r3 = ADD32(ctx->r16, 0);
            goto L_8000755C;
    }
    goto skip_0;
    // 0x80007558: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    skip_0:
L_8000755C:
    // 0x8000755C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80007560: addu        $t3, $v1, $zero
    ctx->r11 = ADD32(ctx->r3, 0);
    // 0x80007564: blez        $t3, L_80007600
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80007568: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_80007600;
    }
    // 0x80007568: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_8000756C:
    // 0x8000756C: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80007570: bne         $v0, $zero, L_80007584
    if (ctx->r2 != 0) {
        // 0x80007574: nop
    
            goto L_80007584;
    }
    // 0x80007574: nop

    // 0x80007578: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8000757C: beq         $v0, $zero, L_80007604
    if (ctx->r2 == 0) {
        // 0x80007580: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80007604;
    }
    // 0x80007580: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80007584:
    // 0x80007584: lbu         $a2, 0x0($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X0);
    // 0x80007588: addiu       $v0, $a2, -0x41
    ctx->r2 = ADD32(ctx->r6, -0X41);
    // 0x8000758C: sltiu       $t2, $v0, 0x1A
    ctx->r10 = ctx->r2 < 0X1A ? 1 : 0;
    // 0x80007590: beq         $t2, $zero, L_8000759C
    if (ctx->r10 == 0) {
        // 0x80007594: addu        $t0, $a2, $zero
        ctx->r8 = ADD32(ctx->r6, 0);
            goto L_8000759C;
    }
    // 0x80007594: addu        $t0, $a2, $zero
    ctx->r8 = ADD32(ctx->r6, 0);
    // 0x80007598: addiu       $t0, $a2, 0x20
    ctx->r8 = ADD32(ctx->r6, 0X20);
L_8000759C:
    // 0x8000759C: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800075A0: andi        $t0, $t0, 0xFF
    ctx->r8 = ctx->r8 & 0XFF;
    // 0x800075A4: addiu       $v0, $v1, -0x41
    ctx->r2 = ADD32(ctx->r3, -0X41);
    // 0x800075A8: sltiu       $t1, $v0, 0x1A
    ctx->r9 = ctx->r2 < 0X1A ? 1 : 0;
    // 0x800075AC: beq         $t1, $zero, L_800075B8
    if (ctx->r9 == 0) {
        // 0x800075B0: addu        $a3, $v1, $zero
        ctx->r7 = ADD32(ctx->r3, 0);
            goto L_800075B8;
    }
    // 0x800075B0: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    // 0x800075B4: addiu       $a3, $v1, 0x20
    ctx->r7 = ADD32(ctx->r3, 0X20);
L_800075B8:
    // 0x800075B8: andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // 0x800075BC: sltu        $v0, $v0, $t0
    ctx->r2 = ctx->r2 < ctx->r8 ? 1 : 0;
    // 0x800075C0: bne         $v0, $zero, L_80007604
    if (ctx->r2 != 0) {
        // 0x800075C4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80007604;
    }
    // 0x800075C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800075C8: beq         $t2, $zero, L_800075D4
    if (ctx->r10 == 0) {
        // 0x800075CC: addu        $v0, $a2, $zero
        ctx->r2 = ADD32(ctx->r6, 0);
            goto L_800075D4;
    }
    // 0x800075CC: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // 0x800075D0: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
L_800075D4:
    // 0x800075D4: beq         $t1, $zero, L_800075E0
    if (ctx->r9 == 0) {
        // 0x800075D8: andi        $a2, $v0, 0xFF
        ctx->r6 = ctx->r2 & 0XFF;
            goto L_800075E0;
    }
    // 0x800075D8: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // 0x800075DC: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
L_800075E0:
    // 0x800075E0: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800075E4: sltu        $v0, $a2, $v0
    ctx->r2 = ctx->r6 < ctx->r2 ? 1 : 0;
    // 0x800075E8: bne         $v0, $zero, L_80007604
    if (ctx->r2 != 0) {
        // 0x800075EC: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80007604;
    }
    // 0x800075EC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800075F0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800075F4: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // 0x800075F8: bgtz        $t3, L_8000756C
    if (SIGNED(ctx->r11) > 0) {
        // 0x800075FC: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8000756C;
    }
    // 0x800075FC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80007600:
    // 0x80007600: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80007604:
    // 0x80007604: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80007608: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8000760C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80007610: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80007614: jr          $ra
    // 0x80007618: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80007618: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void rs_strcpy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000761C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_80007620:
    // 0x80007620: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80007624: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80007628: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8000762C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80007630: bne         $v0, $zero, L_80007620
    if (ctx->r2 != 0) {
        // 0x80007634: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80007620;
    }
    // 0x80007634: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80007638: jr          $ra
    // 0x8000763C: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    return;
    // 0x8000763C: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
;}
RECOMP_FUNC void rs_strncpy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007640: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x80007644: blez        $a2, L_80007674
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80007648: addu        $t0, $v0, $zero
        ctx->r8 = ADD32(ctx->r2, 0);
            goto L_80007674;
    }
    // 0x80007648: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_8000764C:
    // 0x8000764C: addu        $a3, $t0, $zero
    ctx->r7 = ADD32(ctx->r8, 0);
    // 0x80007650: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x80007654: beq         $v1, $zero, L_80007664
    if (ctx->r3 == 0) {
        // 0x80007658: addiu       $t0, $a3, 0x1
        ctx->r8 = ADD32(ctx->r7, 0X1);
            goto L_80007664;
    }
    // 0x80007658: addiu       $t0, $a3, 0x1
    ctx->r8 = ADD32(ctx->r7, 0X1);
    // 0x8000765C: j           L_80007668
    // 0x80007660: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_80007668;
    // 0x80007660: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80007664:
    // 0x80007664: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80007668:
    // 0x80007668: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8000766C: bgtz        $a2, L_8000764C
    if (SIGNED(ctx->r6) > 0) {
        // 0x80007670: sb          $v1, 0x0($a3)
        MEM_B(0X0, ctx->r7) = ctx->r3;
            goto L_8000764C;
    }
    // 0x80007670: sb          $v1, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r3;
L_80007674:
    // 0x80007674: jr          $ra
    // 0x80007678: nop

    return;
    // 0x80007678: nop

;}
RECOMP_FUNC void rs_strcat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000767C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80007680: beq         $v0, $zero, L_80007698
    if (ctx->r2 == 0) {
        // 0x80007684: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80007698;
    }
    // 0x80007684: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80007688: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8000768C:
    // 0x8000768C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80007690: bnel        $v0, $zero, L_8000768C
    if (ctx->r2 != 0) {
        // 0x80007694: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8000768C;
    }
    goto skip_0;
    // 0x80007694: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
L_80007698:
    // 0x80007698: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8000769C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800076A0: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x800076A4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800076A8: bne         $v0, $zero, L_80007698
    if (ctx->r2 != 0) {
        // 0x800076AC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80007698;
    }
    // 0x800076AC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800076B0: jr          $ra
    // 0x800076B4: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    return;
    // 0x800076B4: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
;}
RECOMP_FUNC void rs_strncat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800076B8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800076BC: beq         $v0, $zero, L_800076D4
    if (ctx->r2 == 0) {
        // 0x800076C0: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_800076D4;
    }
    // 0x800076C0: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x800076C4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800076C8:
    // 0x800076C8: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800076CC: bnel        $v0, $zero, L_800076C8
    if (ctx->r2 != 0) {
        // 0x800076D0: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800076C8;
    }
    goto skip_0;
    // 0x800076D0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
L_800076D4:
    // 0x800076D4: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800076D8: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x800076DC: blez        $a2, L_800076F0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800076E0: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800076F0;
    }
    // 0x800076E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800076E4: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800076E8: bne         $v0, $zero, L_800076D4
    if (ctx->r2 != 0) {
        // 0x800076EC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800076D4;
    }
    // 0x800076EC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800076F0:
    // 0x800076F0: jr          $ra
    // 0x800076F4: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    return;
    // 0x800076F4: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
;}
RECOMP_FUNC void rs_strcmp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800076F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800076FC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80007700: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80007704: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80007708: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8000770C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80007710: jal         0x8003471C
    // 0x80007714: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    strlen_recomp(rdram, ctx);
        goto after_0;
    // 0x80007714: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80007718: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8000771C: jal         0x8003471C
    // 0x80007720: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    strlen_recomp(rdram, ctx);
        goto after_1;
    // 0x80007720: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_1:
    // 0x80007724: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80007728: slt         $v0, $v1, $s0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8000772C: bnel        $v0, $zero, L_80007734
    if (ctx->r2 != 0) {
        // 0x80007730: addu        $v1, $s0, $zero
        ctx->r3 = ADD32(ctx->r16, 0);
            goto L_80007734;
    }
    goto skip_0;
    // 0x80007730: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    skip_0:
L_80007734:
    // 0x80007734: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80007738: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    // 0x8000773C: blez        $a3, L_8000778C
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80007740: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_8000778C;
    }
    // 0x80007740: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_80007744:
    // 0x80007744: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80007748: bne         $v0, $zero, L_8000775C
    if (ctx->r2 != 0) {
        // 0x8000774C: nop
    
            goto L_8000775C;
    }
    // 0x8000774C: nop

    // 0x80007750: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80007754: beq         $v0, $zero, L_80007790
    if (ctx->r2 == 0) {
        // 0x80007758: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80007790;
    }
    // 0x80007758: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8000775C:
    // 0x8000775C: lbu         $a2, 0x0($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X0);
    // 0x80007760: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80007764: sltu        $v0, $v1, $a2
    ctx->r2 = ctx->r3 < ctx->r6 ? 1 : 0;
    // 0x80007768: bne         $v0, $zero, L_80007790
    if (ctx->r2 != 0) {
        // 0x8000776C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80007790;
    }
    // 0x8000776C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80007770: sltu        $v0, $a2, $v1
    ctx->r2 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x80007774: bne         $v0, $zero, L_80007790
    if (ctx->r2 != 0) {
        // 0x80007778: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80007790;
    }
    // 0x80007778: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000777C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80007780: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x80007784: bgtz        $a3, L_80007744
    if (SIGNED(ctx->r7) > 0) {
        // 0x80007788: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80007744;
    }
    // 0x80007788: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8000778C:
    // 0x8000778C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80007790:
    // 0x80007790: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80007794: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80007798: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8000779C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800077A0: jr          $ra
    // 0x800077A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800077A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void rs_strncmp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800077A8: blez        $a2, L_80007800
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800077AC: nop
    
            goto L_80007800;
    }
    // 0x800077AC: nop

L_800077B0:
    // 0x800077B0: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800077B4: bne         $v0, $zero, L_800077C8
    if (ctx->r2 != 0) {
        // 0x800077B8: nop
    
            goto L_800077C8;
    }
    // 0x800077B8: nop

    // 0x800077BC: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800077C0: beq         $v0, $zero, L_80007808
    if (ctx->r2 == 0) {
        // 0x800077C4: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80007808;
    }
    // 0x800077C4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800077C8:
    // 0x800077C8: lbu         $a3, 0x0($a0)
    ctx->r7 = MEM_BU(ctx->r4, 0X0);
    // 0x800077CC: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800077D0: sltu        $v0, $v1, $a3
    ctx->r2 = ctx->r3 < ctx->r7 ? 1 : 0;
    // 0x800077D4: beq         $v0, $zero, L_800077E4
    if (ctx->r2 == 0) {
        // 0x800077D8: sltu        $v0, $a3, $v1
        ctx->r2 = ctx->r7 < ctx->r3 ? 1 : 0;
            goto L_800077E4;
    }
    // 0x800077D8: sltu        $v0, $a3, $v1
    ctx->r2 = ctx->r7 < ctx->r3 ? 1 : 0;
    // 0x800077DC: jr          $ra
    // 0x800077E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800077E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800077E4:
    // 0x800077E4: beq         $v0, $zero, L_800077F4
    if (ctx->r2 == 0) {
        // 0x800077E8: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800077F4;
    }
    // 0x800077E8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800077EC: jr          $ra
    // 0x800077F0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800077F0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800077F4:
    // 0x800077F4: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800077F8: bgtz        $a2, L_800077B0
    if (SIGNED(ctx->r6) > 0) {
        // 0x800077FC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800077B0;
    }
    // 0x800077FC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80007800:
    // 0x80007800: jr          $ra
    // 0x80007804: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80007804: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80007808:
    // 0x80007808: jr          $ra
    // 0x8000780C: nop

    return;
    // 0x8000780C: nop

;}
RECOMP_FUNC void rs_strncasecmp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007810: blez        $a2, L_800078B0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80007814: nop
    
            goto L_800078B0;
    }
    // 0x80007814: nop

L_80007818:
    // 0x80007818: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8000781C: bne         $v0, $zero, L_80007830
    if (ctx->r2 != 0) {
        // 0x80007820: nop
    
            goto L_80007830;
    }
    // 0x80007820: nop

    // 0x80007824: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80007828: beq         $v0, $zero, L_800078B8
    if (ctx->r2 == 0) {
        // 0x8000782C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800078B8;
    }
    // 0x8000782C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80007830:
    // 0x80007830: lbu         $a3, 0x0($a0)
    ctx->r7 = MEM_BU(ctx->r4, 0X0);
    // 0x80007834: addiu       $v0, $a3, -0x41
    ctx->r2 = ADD32(ctx->r7, -0X41);
    // 0x80007838: sltiu       $t3, $v0, 0x1A
    ctx->r11 = ctx->r2 < 0X1A ? 1 : 0;
    // 0x8000783C: beq         $t3, $zero, L_80007848
    if (ctx->r11 == 0) {
        // 0x80007840: addu        $t1, $a3, $zero
        ctx->r9 = ADD32(ctx->r7, 0);
            goto L_80007848;
    }
    // 0x80007840: addu        $t1, $a3, $zero
    ctx->r9 = ADD32(ctx->r7, 0);
    // 0x80007844: addiu       $t1, $a3, 0x20
    ctx->r9 = ADD32(ctx->r7, 0X20);
L_80007848:
    // 0x80007848: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x8000784C: andi        $t1, $t1, 0xFF
    ctx->r9 = ctx->r9 & 0XFF;
    // 0x80007850: addiu       $v0, $v1, -0x41
    ctx->r2 = ADD32(ctx->r3, -0X41);
    // 0x80007854: sltiu       $t2, $v0, 0x1A
    ctx->r10 = ctx->r2 < 0X1A ? 1 : 0;
    // 0x80007858: beq         $t2, $zero, L_80007864
    if (ctx->r10 == 0) {
        // 0x8000785C: addu        $t0, $v1, $zero
        ctx->r8 = ADD32(ctx->r3, 0);
            goto L_80007864;
    }
    // 0x8000785C: addu        $t0, $v1, $zero
    ctx->r8 = ADD32(ctx->r3, 0);
    // 0x80007860: addiu       $t0, $v1, 0x20
    ctx->r8 = ADD32(ctx->r3, 0X20);
L_80007864:
    // 0x80007864: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // 0x80007868: sltu        $v0, $v0, $t1
    ctx->r2 = ctx->r2 < ctx->r9 ? 1 : 0;
    // 0x8000786C: bne         $v0, $zero, L_800078B8
    if (ctx->r2 != 0) {
        // 0x80007870: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800078B8;
    }
    // 0x80007870: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80007874: beq         $t3, $zero, L_80007880
    if (ctx->r11 == 0) {
        // 0x80007878: addu        $v0, $a3, $zero
        ctx->r2 = ADD32(ctx->r7, 0);
            goto L_80007880;
    }
    // 0x80007878: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    // 0x8000787C: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
L_80007880:
    // 0x80007880: beq         $t2, $zero, L_8000788C
    if (ctx->r10 == 0) {
        // 0x80007884: andi        $a3, $v0, 0xFF
        ctx->r7 = ctx->r2 & 0XFF;
            goto L_8000788C;
    }
    // 0x80007884: andi        $a3, $v0, 0xFF
    ctx->r7 = ctx->r2 & 0XFF;
    // 0x80007888: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
L_8000788C:
    // 0x8000788C: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x80007890: sltu        $v0, $a3, $v0
    ctx->r2 = ctx->r7 < ctx->r2 ? 1 : 0;
    // 0x80007894: beq         $v0, $zero, L_800078A4
    if (ctx->r2 == 0) {
        // 0x80007898: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800078A4;
    }
    // 0x80007898: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000789C: jr          $ra
    // 0x800078A0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800078A0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800078A4:
    // 0x800078A4: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800078A8: bgtz        $a2, L_80007818
    if (SIGNED(ctx->r6) > 0) {
        // 0x800078AC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80007818;
    }
    // 0x800078AC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800078B0:
    // 0x800078B0: jr          $ra
    // 0x800078B4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800078B4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800078B8:
    // 0x800078B8: jr          $ra
    // 0x800078BC: nop

    return;
    // 0x800078BC: nop

;}
RECOMP_FUNC void rs_tolower(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800078C0: addiu       $v0, $a0, -0x41
    ctx->r2 = ADD32(ctx->r4, -0X41);
    // 0x800078C4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800078C8: sltiu       $v0, $v0, 0x1A
    ctx->r2 = ctx->r2 < 0X1A ? 1 : 0;
    // 0x800078CC: beq         $v0, $zero, L_800078D8
    if (ctx->r2 == 0) {
        // 0x800078D0: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_800078D8;
    }
    // 0x800078D0: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x800078D4: addiu       $v1, $a0, 0x20
    ctx->r3 = ADD32(ctx->r4, 0X20);
L_800078D8:
    // 0x800078D8: jr          $ra
    // 0x800078DC: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    return;
    // 0x800078DC: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
;}
RECOMP_FUNC void rs_memset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800078E0: beq         $a2, $zero, L_80007900
    if (ctx->r6 == 0) {
        // 0x800078E4: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80007900;
    }
    // 0x800078E4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800078E8: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
L_800078EC:
    // 0x800078EC: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x800078F0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800078F4: sltu        $v0, $v1, $a2
    ctx->r2 = ctx->r3 < ctx->r6 ? 1 : 0;
    // 0x800078F8: bne         $v0, $zero, L_800078EC
    if (ctx->r2 != 0) {
        // 0x800078FC: addu        $v0, $a0, $v1
        ctx->r2 = ADD32(ctx->r4, ctx->r3);
            goto L_800078EC;
    }
    // 0x800078FC: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
L_80007900:
    // 0x80007900: jr          $ra
    // 0x80007904: nop

    return;
    // 0x80007904: nop

;}
RECOMP_FUNC void fake_func_80007908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80007910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007910: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80007914: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80007918: addiu       $v1, $v1, -0x575C
    ctx->r3 = ADD32(ctx->r3, -0X575C);
L_8000791C:
    // 0x8000791C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80007920: bnel        $v0, $zero, L_80007934
    if (ctx->r2 != 0) {
        // 0x80007924: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80007934;
    }
    goto skip_0;
    // 0x80007924: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_0:
    // 0x80007928: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000792C: j           L_80007944
    // 0x80007930: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80007944;
    // 0x80007930: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80007934:
    // 0x80007934: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80007938: bne         $v0, $zero, L_8000791C
    if (ctx->r2 != 0) {
        // 0x8000793C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8000791C;
    }
    // 0x8000793C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80007940: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80007944:
    // 0x80007944: jr          $ra
    // 0x80007948: nop

    return;
    // 0x80007948: nop

;}
