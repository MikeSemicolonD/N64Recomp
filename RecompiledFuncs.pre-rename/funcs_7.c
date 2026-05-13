#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80023950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023950: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80023954: lw          $v1, -0x5830($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5830);
    // 0x80023958: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002395C: lw          $v0, -0x5828($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5828);
    // 0x80023960: jr          $ra
    // 0x80023964: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    return;
    // 0x80023964: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
;}
RECOMP_FUNC void fake_func_80023968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80023970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023970: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80023974: lbu         $v0, 0x43A8($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X43A8);
    // 0x80023978: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002397C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80023980: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80023984: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80023988: addiu       $v1, $zero, -0x2001
    ctx->r3 = ADD32(0, -0X2001);
    // 0x8002398C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80023990: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80023994: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80023998: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8002399C: or          $s2, $v0, $v1
    ctx->r18 = ctx->r2 | ctx->r3;
    // 0x800239A0: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x800239A4: and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // 0x800239A8: bne         $v0, $zero, L_800239C0
    if (ctx->r2 != 0) {
        // 0x800239AC: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_800239C0;
    }
    // 0x800239AC: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800239B0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800239B4: lbu         $v0, -0x5768($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5768);
    // 0x800239B8: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x800239BC: sll         $s0, $v0, 3
    ctx->r16 = S32(ctx->r2 << 3);
L_800239C0:
    // 0x800239C0: andi        $v1, $a2, 0x14
    ctx->r3 = ctx->r6 & 0X14;
    // 0x800239C4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800239C8: beql        $v1, $v0, L_800239D0
    if (ctx->r3 == ctx->r2) {
        // 0x800239CC: ori         $s0, $s0, 0x4
        ctx->r16 = ctx->r16 | 0X4;
            goto L_800239D0;
    }
    goto skip_0;
    // 0x800239CC: ori         $s0, $s0, 0x4
    ctx->r16 = ctx->r16 | 0X4;
    skip_0:
L_800239D0:
    // 0x800239D0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800239D4: lbu         $v1, -0x579F($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X579F);
    // 0x800239D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800239DC: beq         $v1, $v0, L_800239F4
    if (ctx->r3 == ctx->r2) {
        // 0x800239E0: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800239F4;
    }
    // 0x800239E0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800239E4: beql        $v1, $v0, L_800239FC
    if (ctx->r3 == ctx->r2) {
        // 0x800239E8: ori         $s0, $s0, 0x20
        ctx->r16 = ctx->r16 | 0X20;
            goto L_800239FC;
    }
    goto skip_1;
    // 0x800239E8: ori         $s0, $s0, 0x20
    ctx->r16 = ctx->r16 | 0X20;
    skip_1:
    // 0x800239EC: j           L_80023A08
    // 0x800239F0: lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
        goto L_80023A08;
    // 0x800239F0: lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
L_800239F4:
    // 0x800239F4: j           L_80023A04
    // 0x800239F8: ori         $s0, $s0, 0x20
    ctx->r16 = ctx->r16 | 0X20;
        goto L_80023A04;
    // 0x800239F8: ori         $s0, $s0, 0x20
    ctx->r16 = ctx->r16 | 0X20;
L_800239FC:
    // 0x800239FC: addiu       $v0, $zero, -0x41
    ctx->r2 = ADD32(0, -0X41);
    // 0x80023A00: and         $s2, $s2, $v0
    ctx->r18 = ctx->r18 & ctx->r2;
L_80023A04:
    // 0x80023A04: lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
L_80023A08:
    // 0x80023A08: and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // 0x80023A0C: bnel        $v0, $zero, L_80023A14
    if (ctx->r2 != 0) {
        // 0x80023A10: ori         $s0, $s0, 0x1
        ctx->r16 = ctx->r16 | 0X1;
            goto L_80023A14;
    }
    goto skip_2;
    // 0x80023A10: ori         $s0, $s0, 0x1
    ctx->r16 = ctx->r16 | 0X1;
    skip_2:
L_80023A14:
    // 0x80023A14: lui         $v0, 0x4
    ctx->r2 = S32(0X4 << 16);
    // 0x80023A18: and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // 0x80023A1C: bnel        $v0, $zero, L_80023A24
    if (ctx->r2 != 0) {
        // 0x80023A20: ori         $s0, $s0, 0x2
        ctx->r16 = ctx->r16 | 0X2;
            goto L_80023A24;
    }
    goto skip_3;
    // 0x80023A20: ori         $s0, $s0, 0x2
    ctx->r16 = ctx->r16 | 0X2;
    skip_3:
L_80023A24:
    // 0x80023A24: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80023A28: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x80023A2C: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80023A30: bne         $v0, $zero, L_80023A48
    if (ctx->r2 != 0) {
        // 0x80023A34: lui         $v0, 0xB500
        ctx->r2 = S32(0XB500 << 16);
            goto L_80023A48;
    }
    // 0x80023A34: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80023A38: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80023A3C: jal         0x80007D74
    // 0x80023A40: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    func_80007D74(rdram, ctx);
        goto after_0;
    // 0x80023A40: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    after_0:
    // 0x80023A44: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_80023A48:
    // 0x80023A48: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80023A4C: lbu         $v0, -0x56F8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X56F8);
    // 0x80023A50: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80023A54: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80023A58: bne         $v0, $v1, L_80023AA0
    if (ctx->r2 != ctx->r3) {
        // 0x80023A5C: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80023AA0;
    }
    // 0x80023A5C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80023A60: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80023A64: lui         $v0, 0xBA00
    ctx->r2 = S32(0XBA00 << 16);
    // 0x80023A68: ori         $v0, $v0, 0x1402
    ctx->r2 = ctx->r2 | 0X1402;
    // 0x80023A6C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80023A70: lui         $v0, 0x10
    ctx->r2 = S32(0X10 << 16);
    // 0x80023A74: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80023A78: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80023A7C: and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // 0x80023A80: bne         $v0, $zero, L_80023A98
    if (ctx->r2 != 0) {
        // 0x80023A84: andi        $v1, $s0, 0xFF
        ctx->r3 = ctx->r16 & 0XFF;
            goto L_80023A98;
    }
    // 0x80023A84: andi        $v1, $s0, 0xFF
    ctx->r3 = ctx->r16 & 0XFF;
    // 0x80023A88: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80023A8C: lbu         $v0, -0x5768($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5768);
    // 0x80023A90: bne         $v0, $zero, L_80023AB4
    if (ctx->r2 != 0) {
        // 0x80023A94: ori         $s0, $v1, 0x18
        ctx->r16 = ctx->r3 | 0X18;
            goto L_80023AB4;
    }
    // 0x80023A94: ori         $s0, $v1, 0x18
    ctx->r16 = ctx->r3 | 0X18;
L_80023A98:
    // 0x80023A98: j           L_80023AB4
    // 0x80023A9C: ori         $s0, $v1, 0x10
    ctx->r16 = ctx->r3 | 0X10;
        goto L_80023AB4;
    // 0x80023A9C: ori         $s0, $v1, 0x10
    ctx->r16 = ctx->r3 | 0X10;
L_80023AA0:
    // 0x80023AA0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80023AA4: lui         $v0, 0xBA00
    ctx->r2 = S32(0XBA00 << 16);
    // 0x80023AA8: ori         $v0, $v0, 0x1402
    ctx->r2 = ctx->r2 | 0X1402;
    // 0x80023AAC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80023AB0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_80023AB4:
    // 0x80023AB4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80023AB8: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x80023ABC: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80023AC0: bne         $v0, $zero, L_80023AE0
    if (ctx->r2 != 0) {
        // 0x80023AC4: lui         $v0, 0xB900
        ctx->r2 = S32(0XB900 << 16);
            goto L_80023AE0;
    }
    // 0x80023AC4: lui         $v0, 0xB900
    ctx->r2 = S32(0XB900 << 16);
    // 0x80023AC8: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80023ACC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80023AD0: jal         0x80007D74
    // 0x80023AD4: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    func_80007D74(rdram, ctx);
        goto after_1;
    // 0x80023AD4: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    after_1:
    // 0x80023AD8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80023ADC: lui         $v0, 0xB900
    ctx->r2 = S32(0XB900 << 16);
L_80023AE0:
    // 0x80023AE0: ori         $v0, $v0, 0x31D
    ctx->r2 = ctx->r2 | 0X31D;
    // 0x80023AE4: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80023AE8: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80023AEC: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x80023AF0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80023AF4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80023AF8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80023AFC: lw          $v1, -0x7720($at)
    ctx->r3 = MEM_W(ctx->r1, -0X7720);
    // 0x80023B00: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80023B04: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80023B08: lw          $a0, -0x771C($at)
    ctx->r4 = MEM_W(ctx->r1, -0X771C);
    // 0x80023B0C: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x80023B10: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x80023B14: and         $v1, $s2, $v1
    ctx->r3 = ctx->r18 & ctx->r3;
    // 0x80023B18: sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    // 0x80023B1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80023B20: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80023B24: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80023B28: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80023B2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80023B30: jr          $ra
    // 0x80023B34: nop

    return;
    // 0x80023B34: nop

;}
RECOMP_FUNC void func_80023B38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023B38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80023B3C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80023B40: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80023B44: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80023B48: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80023B4C: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80023B50: and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // 0x80023B54: bne         $v0, $zero, L_80023B6C
    if (ctx->r2 != 0) {
        // 0x80023B58: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_80023B6C;
    }
    // 0x80023B58: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80023B5C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80023B60: lbu         $v0, -0x5768($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5768);
    // 0x80023B64: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80023B68: sll         $s0, $v0, 3
    ctx->r16 = S32(ctx->r2 << 3);
L_80023B6C:
    // 0x80023B6C: andi        $v1, $a2, 0x14
    ctx->r3 = ctx->r6 & 0X14;
    // 0x80023B70: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80023B74: beql        $v1, $v0, L_80023B7C
    if (ctx->r3 == ctx->r2) {
        // 0x80023B78: ori         $s0, $s0, 0x4
        ctx->r16 = ctx->r16 | 0X4;
            goto L_80023B7C;
    }
    goto skip_0;
    // 0x80023B78: ori         $s0, $s0, 0x4
    ctx->r16 = ctx->r16 | 0X4;
    skip_0:
L_80023B7C:
    // 0x80023B7C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80023B80: lbu         $v1, -0x579F($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X579F);
    // 0x80023B84: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x80023B88: beql        $v0, $zero, L_80023B9C
    if (ctx->r2 == 0) {
        // 0x80023B8C: lui         $v0, 0x2
        ctx->r2 = S32(0X2 << 16);
            goto L_80023B9C;
    }
    goto skip_1;
    // 0x80023B8C: lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
    skip_1:
    // 0x80023B90: bnel        $v1, $zero, L_80023B98
    if (ctx->r3 != 0) {
        // 0x80023B94: ori         $s0, $s0, 0x20
        ctx->r16 = ctx->r16 | 0X20;
            goto L_80023B98;
    }
    goto skip_2;
    // 0x80023B94: ori         $s0, $s0, 0x20
    ctx->r16 = ctx->r16 | 0X20;
    skip_2:
L_80023B98:
    // 0x80023B98: lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
L_80023B9C:
    // 0x80023B9C: and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // 0x80023BA0: bnel        $v0, $zero, L_80023BA8
    if (ctx->r2 != 0) {
        // 0x80023BA4: ori         $s0, $s0, 0x1
        ctx->r16 = ctx->r16 | 0X1;
            goto L_80023BA8;
    }
    goto skip_3;
    // 0x80023BA4: ori         $s0, $s0, 0x1
    ctx->r16 = ctx->r16 | 0X1;
    skip_3:
L_80023BA8:
    // 0x80023BA8: lui         $v0, 0x4
    ctx->r2 = S32(0X4 << 16);
    // 0x80023BAC: and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // 0x80023BB0: bnel        $v0, $zero, L_80023BB8
    if (ctx->r2 != 0) {
        // 0x80023BB4: ori         $s0, $s0, 0x2
        ctx->r16 = ctx->r16 | 0X2;
            goto L_80023BB8;
    }
    goto skip_4;
    // 0x80023BB4: ori         $s0, $s0, 0x2
    ctx->r16 = ctx->r16 | 0X2;
    skip_4:
L_80023BB8:
    // 0x80023BB8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80023BBC: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x80023BC0: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80023BC4: bne         $v0, $zero, L_80023BDC
    if (ctx->r2 != 0) {
        // 0x80023BC8: lui         $v0, 0xB500
        ctx->r2 = S32(0XB500 << 16);
            goto L_80023BDC;
    }
    // 0x80023BC8: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80023BCC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80023BD0: jal         0x80007D74
    // 0x80023BD4: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    func_80007D74(rdram, ctx);
        goto after_0;
    // 0x80023BD4: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    after_0:
    // 0x80023BD8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_80023BDC:
    // 0x80023BDC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80023BE0: lbu         $v0, -0x56F8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X56F8);
    // 0x80023BE4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80023BE8: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80023BEC: bne         $v0, $v1, L_80023C34
    if (ctx->r2 != ctx->r3) {
        // 0x80023BF0: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80023C34;
    }
    // 0x80023BF0: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80023BF4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80023BF8: lui         $v0, 0xBA00
    ctx->r2 = S32(0XBA00 << 16);
    // 0x80023BFC: ori         $v0, $v0, 0x1402
    ctx->r2 = ctx->r2 | 0X1402;
    // 0x80023C00: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80023C04: lui         $v0, 0x10
    ctx->r2 = S32(0X10 << 16);
    // 0x80023C08: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80023C0C: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80023C10: and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // 0x80023C14: bne         $v0, $zero, L_80023C2C
    if (ctx->r2 != 0) {
        // 0x80023C18: andi        $v1, $s0, 0xFF
        ctx->r3 = ctx->r16 & 0XFF;
            goto L_80023C2C;
    }
    // 0x80023C18: andi        $v1, $s0, 0xFF
    ctx->r3 = ctx->r16 & 0XFF;
    // 0x80023C1C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80023C20: lbu         $v0, -0x5768($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5768);
    // 0x80023C24: bne         $v0, $zero, L_80023C48
    if (ctx->r2 != 0) {
        // 0x80023C28: ori         $s0, $v1, 0x18
        ctx->r16 = ctx->r3 | 0X18;
            goto L_80023C48;
    }
    // 0x80023C28: ori         $s0, $v1, 0x18
    ctx->r16 = ctx->r3 | 0X18;
L_80023C2C:
    // 0x80023C2C: j           L_80023C48
    // 0x80023C30: ori         $s0, $v1, 0x10
    ctx->r16 = ctx->r3 | 0X10;
        goto L_80023C48;
    // 0x80023C30: ori         $s0, $v1, 0x10
    ctx->r16 = ctx->r3 | 0X10;
L_80023C34:
    // 0x80023C34: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80023C38: lui         $v0, 0xBA00
    ctx->r2 = S32(0XBA00 << 16);
    // 0x80023C3C: ori         $v0, $v0, 0x1402
    ctx->r2 = ctx->r2 | 0X1402;
    // 0x80023C40: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80023C44: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_80023C48:
    // 0x80023C48: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80023C4C: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x80023C50: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80023C54: bne         $v0, $zero, L_80023C74
    if (ctx->r2 != 0) {
        // 0x80023C58: lui         $v0, 0xB900
        ctx->r2 = S32(0XB900 << 16);
            goto L_80023C74;
    }
    // 0x80023C58: lui         $v0, 0xB900
    ctx->r2 = S32(0XB900 << 16);
    // 0x80023C5C: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80023C60: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80023C64: jal         0x80007D74
    // 0x80023C68: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    func_80007D74(rdram, ctx);
        goto after_1;
    // 0x80023C68: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    after_1:
    // 0x80023C6C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80023C70: lui         $v0, 0xB900
    ctx->r2 = S32(0XB900 << 16);
L_80023C74:
    // 0x80023C74: ori         $v0, $v0, 0x31D
    ctx->r2 = ctx->r2 | 0X31D;
    // 0x80023C78: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80023C7C: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x80023C80: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80023C84: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80023C88: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80023C8C: lw          $v1, -0x7520($at)
    ctx->r3 = MEM_W(ctx->r1, -0X7520);
    // 0x80023C90: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80023C94: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80023C98: lw          $a1, -0x751C($at)
    ctx->r5 = MEM_W(ctx->r1, -0X751C);
    // 0x80023C9C: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80023CA0: or          $v1, $v1, $a1
    ctx->r3 = ctx->r3 | ctx->r5;
    // 0x80023CA4: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x80023CA8: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80023CAC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80023CB0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80023CB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80023CB8: jr          $ra
    // 0x80023CBC: nop

    return;
    // 0x80023CBC: nop

;}
RECOMP_FUNC void recordFrameTimestamp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023CC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80023CC4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80023CC8: jal         0x8002BF00
    // 0x80023CCC: nop

    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x80023CCC: nop

    after_0:
    // 0x80023CD0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80023CD4: sw          $v1, -0x70F0($at)
    MEM_W(-0X70F0, ctx->r1) = ctx->r3;
    // 0x80023CD8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80023CDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80023CE0: jr          $ra
    // 0x80023CE4: nop

    return;
    // 0x80023CE4: nop

;}
RECOMP_FUNC void getTimeLow32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023CE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80023CEC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80023CF0: jal         0x8002BF00
    // 0x80023CF4: nop

    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x80023CF4: nop

    after_0:
    // 0x80023CF8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80023CFC: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x80023D00: jr          $ra
    // 0x80023D04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80023D04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void getTimeSinceLastFrame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023D08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80023D0C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80023D10: jal         0x8002BF00
    // 0x80023D14: nop

    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x80023D14: nop

    after_0:
    // 0x80023D18: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80023D1C: lw          $a0, -0x70F0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X70F0);
    // 0x80023D20: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80023D24: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    // 0x80023D28: jr          $ra
    // 0x80023D2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80023D2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80023D30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023D30: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80023D34: sb          $a0, -0x7320($at)
    MEM_B(-0X7320, ctx->r1) = ctx->r4;
    // 0x80023D38: jr          $ra
    // 0x80023D3C: nop

    return;
    // 0x80023D3C: nop

;}
RECOMP_FUNC void func_80023D40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023D40: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80023D44: lbu         $v0, -0x7320($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7320);
    // 0x80023D48: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80023D4C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80023D50: lbu         $s7, 0x53($sp)
    ctx->r23 = MEM_BU(ctx->r29, 0X53);
    // 0x80023D54: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80023D58: lbu         $fp, 0x57($sp)
    ctx->r30 = MEM_BU(ctx->r29, 0X57);
    // 0x80023D5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80023D60: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80023D64: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80023D68: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x80023D6C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80023D70: addu        $s6, $a3, $zero
    ctx->r22 = ADD32(ctx->r7, 0);
    // 0x80023D74: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80023D78: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80023D7C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80023D80: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80023D84: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80023D88: beq         $v0, $zero, L_800240F0
    if (ctx->r2 == 0) {
        // 0x80023D8C: sh          $s2, 0x16($sp)
        MEM_H(0X16, ctx->r29) = ctx->r18;
            goto L_800240F0;
    }
    // 0x80023D8C: sh          $s2, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r18;
    // 0x80023D90: lui         $v0, 0x3B9A
    ctx->r2 = S32(0X3B9A << 16);
    // 0x80023D94: ori         $v0, $v0, 0xCA00
    ctx->r2 = ctx->r2 | 0XCA00;
    // 0x80023D98: multu       $a1, $v0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80023D9C: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80023DA0: lw          $a2, -0x6F00($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X6F00);
    // 0x80023DA4: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80023DA8: lw          $a3, -0x6EFC($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X6EFC);
    // 0x80023DAC: mfhi        $a0
    ctx->r4 = hi;
    // 0x80023DB0: mflo        $a1
    ctx->r5 = lo;
    // 0x80023DB4: jal         0x800074E0
    // 0x80023DB8: nop

    func_800074E0(rdram, ctx);
        goto after_0;
    // 0x80023DB8: nop

    after_0:
    // 0x80023DBC: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80023DC0: srl         $a0, $v1, 27
    ctx->r4 = S32(U32(ctx->r3) >> 27);
    // 0x80023DC4: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x80023DC8: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80023DCC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80023DD0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80023DD4: lui         $a3, 0x32
    ctx->r7 = S32(0X32 << 16);
    // 0x80023DD8: ori         $a3, $a3, 0xDCD5
    ctx->r7 = ctx->r7 | 0XDCD5;
    // 0x80023DDC: jal         0x800074E0
    // 0x80023DE0: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    func_800074E0(rdram, ctx);
        goto after_1;
    // 0x80023DE0: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    after_1:
    // 0x80023DE4: addu        $s3, $v1, $zero
    ctx->r19 = ADD32(ctx->r3, 0);
    // 0x80023DE8: sltiu       $v0, $s3, 0x141
    ctx->r2 = ctx->r19 < 0X141 ? 1 : 0;
    // 0x80023DEC: beql        $v0, $zero, L_80023DF4
    if (ctx->r2 == 0) {
        // 0x80023DF0: addiu       $s3, $zero, 0x140
        ctx->r19 = ADD32(0, 0X140);
            goto L_80023DF4;
    }
    goto skip_0;
    // 0x80023DF0: addiu       $s3, $zero, 0x140
    ctx->r19 = ADD32(0, 0X140);
    skip_0:
L_80023DF4:
    // 0x80023DF4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80023DF8: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x80023DFC: sltu        $v0, $s0, $v0
    ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x80023E00: bne         $v0, $zero, L_80023E20
    if (ctx->r2 != 0) {
        // 0x80023E04: addu        $v1, $s0, $zero
        ctx->r3 = ADD32(ctx->r16, 0);
            goto L_80023E20;
    }
    // 0x80023E04: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x80023E08: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80023E0C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80023E10: jal         0x80007D74
    // 0x80023E14: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    func_80007D74(rdram, ctx);
        goto after_2;
    // 0x80023E14: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    after_2:
    // 0x80023E18: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80023E1C: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
L_80023E20:
    // 0x80023E20: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80023E24: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x80023E28: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80023E2C: lui         $s5, 0xE700
    ctx->r21 = S32(0XE700 << 16);
    // 0x80023E30: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x80023E34: sltu        $v0, $s0, $v0
    ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x80023E38: bne         $v0, $zero, L_80023E54
    if (ctx->r2 != 0) {
        // 0x80023E3C: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_80023E54;
    }
    // 0x80023E3C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80023E40: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80023E44: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80023E48: jal         0x80007D74
    // 0x80023E4C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    func_80007D74(rdram, ctx);
        goto after_3;
    // 0x80023E4C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    after_3:
    // 0x80023E50: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_80023E54:
    // 0x80023E54: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80023E58: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80023E5C: lui         $a0, 0xB900
    ctx->r4 = S32(0XB900 << 16);
    // 0x80023E60: ori         $a0, $a0, 0x31D
    ctx->r4 = ctx->r4 | 0X31D;
    // 0x80023E64: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80023E68: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x80023E6C: lui         $v1, 0xF0A
    ctx->r3 = S32(0XF0A << 16);
    // 0x80023E70: ori         $v1, $v1, 0x4000
    ctx->r3 = ctx->r3 | 0X4000;
    // 0x80023E74: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x80023E78: sltu        $v0, $s0, $v0
    ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x80023E7C: bne         $v0, $zero, L_80023E98
    if (ctx->r2 != 0) {
        // 0x80023E80: sw          $v1, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->r3;
            goto L_80023E98;
    }
    // 0x80023E80: sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    // 0x80023E84: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80023E88: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80023E8C: jal         0x80007D74
    // 0x80023E90: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    func_80007D74(rdram, ctx);
        goto after_4;
    // 0x80023E90: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    after_4:
    // 0x80023E94: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_80023E98:
    // 0x80023E98: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80023E9C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80023EA0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80023EA4: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80023EA8: lui         $v0, 0xBA00
    ctx->r2 = S32(0XBA00 << 16);
    // 0x80023EAC: ori         $v0, $v0, 0x1402
    ctx->r2 = ctx->r2 | 0X1402;
    // 0x80023EB0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80023EB4: lui         $v0, 0x30
    ctx->r2 = S32(0X30 << 16);
    // 0x80023EB8: sltu        $v1, $s0, $v1
    ctx->r3 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80023EBC: bne         $v1, $zero, L_80023ED8
    if (ctx->r3 != 0) {
        // 0x80023EC0: sw          $v0, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r2;
            goto L_80023ED8;
    }
    // 0x80023EC0: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x80023EC4: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80023EC8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80023ECC: jal         0x80007D74
    // 0x80023ED0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    func_80007D74(rdram, ctx);
        goto after_5;
    // 0x80023ED0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    after_5:
    // 0x80023ED4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_80023ED8:
    // 0x80023ED8: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x80023EDC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80023EE0: lui         $a0, 0x4211
    ctx->r4 = S32(0X4211 << 16);
    // 0x80023EE4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80023EE8: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80023EEC: ori         $a0, $a0, 0x4211
    ctx->r4 = ctx->r4 | 0X4211;
    // 0x80023EF0: lui         $s4, 0xF700
    ctx->r20 = S32(0XF700 << 16);
    // 0x80023EF4: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80023EF8: sltu        $v1, $s0, $v1
    ctx->r3 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80023EFC: bne         $v1, $zero, L_80023F18
    if (ctx->r3 != 0) {
        // 0x80023F00: sw          $a0, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r4;
            goto L_80023F18;
    }
    // 0x80023F00: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x80023F04: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80023F08: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80023F0C: jal         0x80007D74
    // 0x80023F10: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    func_80007D74(rdram, ctx);
        goto after_6;
    // 0x80023F10: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    after_6:
    // 0x80023F14: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_80023F18:
    // 0x80023F18: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80023F1C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80023F20: sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18 << 16);
    // 0x80023F24: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80023F28: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x80023F2C: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x80023F30: sll         $s1, $v0, 2
    ctx->r17 = S32(ctx->r2 << 2);
    // 0x80023F34: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80023F38: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80023F3C: lui         $v0, 0xF628
    ctx->r2 = S32(0XF628 << 16);
    // 0x80023F40: or          $v0, $s1, $v0
    ctx->r2 = ctx->r17 | ctx->r2;
    // 0x80023F44: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80023F48: andi        $v0, $s2, 0x3FF
    ctx->r2 = ctx->r18 & 0X3FF;
    // 0x80023F4C: sll         $s2, $v0, 2
    ctx->r18 = S32(ctx->r2 << 2);
    // 0x80023F50: sltu        $v1, $s0, $v1
    ctx->r3 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80023F54: bne         $v1, $zero, L_80023F70
    if (ctx->r3 != 0) {
        // 0x80023F58: sw          $s2, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r18;
            goto L_80023F70;
    }
    // 0x80023F58: sw          $s2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r18;
    // 0x80023F5C: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80023F60: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80023F64: jal         0x80007D74
    // 0x80023F68: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    func_80007D74(rdram, ctx);
        goto after_7;
    // 0x80023F68: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    after_7:
    // 0x80023F6C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_80023F70:
    // 0x80023F70: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80023F74: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x80023F78: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x80023F7C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80023F80: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x80023F84: sltu        $v0, $s0, $v0
    ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x80023F88: bne         $v0, $zero, L_80023FA4
    if (ctx->r2 != 0) {
        // 0x80023F8C: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_80023FA4;
    }
    // 0x80023F8C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80023F90: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80023F94: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80023F98: jal         0x80007D74
    // 0x80023F9C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    func_80007D74(rdram, ctx);
        goto after_8;
    // 0x80023F9C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    after_8:
    // 0x80023FA0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_80023FA4:
    // 0x80023FA4: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x80023FA8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80023FAC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80023FB0: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80023FB4: lui         $a0, 0x2109
    ctx->r4 = S32(0X2109 << 16);
    // 0x80023FB8: ori         $a0, $a0, 0x2109
    ctx->r4 = ctx->r4 | 0X2109;
    // 0x80023FBC: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80023FC0: sltu        $v1, $s0, $v1
    ctx->r3 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80023FC4: bne         $v1, $zero, L_80023FE0
    if (ctx->r3 != 0) {
        // 0x80023FC8: sw          $a0, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r4;
            goto L_80023FE0;
    }
    // 0x80023FC8: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x80023FCC: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80023FD0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80023FD4: jal         0x80007D74
    // 0x80023FD8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    func_80007D74(rdram, ctx);
        goto after_9;
    // 0x80023FD8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    after_9:
    // 0x80023FDC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_80023FE0:
    // 0x80023FE0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80023FE4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80023FE8: lui         $v1, 0x28
    ctx->r3 = S32(0X28 << 16);
    // 0x80023FEC: ori         $v1, $v1, 0x4000
    ctx->r3 = ctx->r3 | 0X4000;
    // 0x80023FF0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80023FF4: lw          $a0, 0x63D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63D4);
    // 0x80023FF8: lui         $v0, 0xF650
    ctx->r2 = S32(0XF650 << 16);
    // 0x80023FFC: or          $v0, $s1, $v0
    ctx->r2 = ctx->r17 | ctx->r2;
    // 0x80024000: or          $v1, $s2, $v1
    ctx->r3 = ctx->r18 | ctx->r3;
    // 0x80024004: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80024008: sltu        $a0, $s0, $a0
    ctx->r4 = ctx->r16 < ctx->r4 ? 1 : 0;
    // 0x8002400C: bne         $a0, $zero, L_80024028
    if (ctx->r4 != 0) {
        // 0x80024010: sw          $v1, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->r3;
            goto L_80024028;
    }
    // 0x80024010: sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    // 0x80024014: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80024018: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8002401C: jal         0x80007D74
    // 0x80024020: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    func_80007D74(rdram, ctx);
        goto after_10;
    // 0x80024020: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    after_10:
    // 0x80024024: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_80024028:
    // 0x80024028: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8002402C: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x80024030: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x80024034: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80024038: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x8002403C: sltu        $v0, $s0, $v0
    ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x80024040: bne         $v0, $zero, L_8002405C
    if (ctx->r2 != 0) {
        // 0x80024044: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8002405C;
    }
    // 0x80024044: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80024048: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x8002404C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80024050: jal         0x80007D74
    // 0x80024054: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    func_80007D74(rdram, ctx);
        goto after_11;
    // 0x80024054: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    after_11:
    // 0x80024058: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_8002405C:
    // 0x8002405C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80024060: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80024064: sll         $v1, $s6, 8
    ctx->r3 = S32(ctx->r22 << 8);
    // 0x80024068: andi        $v1, $v1, 0xF800
    ctx->r3 = ctx->r3 & 0XF800;
    // 0x8002406C: sll         $v0, $s7, 3
    ctx->r2 = S32(ctx->r23 << 3);
    // 0x80024070: andi        $v0, $v0, 0x7C0
    ctx->r2 = ctx->r2 & 0X7C0;
    // 0x80024074: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80024078: srl         $v0, $fp, 2
    ctx->r2 = S32(U32(ctx->r30) >> 2);
    // 0x8002407C: andi        $v0, $v0, 0x3E
    ctx->r2 = ctx->r2 & 0X3E;
    // 0x80024080: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80024084: ori         $v0, $v1, 0x1
    ctx->r2 = ctx->r3 | 0X1;
    // 0x80024088: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002408C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80024090: lw          $a0, 0x63D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63D4);
    // 0x80024094: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80024098: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8002409C: sw          $s4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r20;
    // 0x800240A0: sltu        $a0, $s0, $a0
    ctx->r4 = ctx->r16 < ctx->r4 ? 1 : 0;
    // 0x800240A4: bne         $a0, $zero, L_800240C0
    if (ctx->r4 != 0) {
        // 0x800240A8: sw          $v0, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->r2;
            goto L_800240C0;
    }
    // 0x800240A8: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x800240AC: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x800240B0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800240B4: jal         0x80007D74
    // 0x800240B8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    func_80007D74(rdram, ctx);
        goto after_12;
    // 0x800240B8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    after_12:
    // 0x800240BC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_800240C0:
    // 0x800240C0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800240C4: andi        $v1, $s3, 0x3FF
    ctx->r3 = ctx->r19 & 0X3FF;
    // 0x800240C8: sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3 << 14);
    // 0x800240CC: lui         $v0, 0xF600
    ctx->r2 = S32(0XF600 << 16);
    // 0x800240D0: or          $v0, $s1, $v0
    ctx->r2 = ctx->r17 | ctx->r2;
    // 0x800240D4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800240D8: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800240DC: lhu         $t0, 0x16($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X16);
    // 0x800240E0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800240E4: andi        $v0, $t0, 0x3FF
    ctx->r2 = ctx->r8 & 0X3FF;
    // 0x800240E8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800240EC: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_800240F0:
    // 0x800240F0: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x800240F4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800240F8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800240FC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80024100: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80024104: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80024108: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002410C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80024110: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80024114: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80024118: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002411C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80024120: jr          $ra
    // 0x80024124: nop

    return;
    // 0x80024124: nop

;}
RECOMP_FUNC void fake_func_80024128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80024130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024130: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80024134: lh          $v0, -0x40D8($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X40D8);
    // 0x80024138: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002413C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80024140: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80024144: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80024148: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8002414C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80024150: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80024154: beq         $v0, $zero, L_800244CC
    if (ctx->r2 == 0) {
        // 0x80024158: sw          $s1, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r17;
            goto L_800244CC;
    }
    // 0x80024158: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8002415C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80024160: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x80024164: sltu        $v0, $s0, $v0
    ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x80024168: bne         $v0, $zero, L_80024180
    if (ctx->r2 != 0) {
        // 0x8002416C: lui         $v0, 0xB500
        ctx->r2 = S32(0XB500 << 16);
            goto L_80024180;
    }
    // 0x8002416C: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80024170: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80024174: jal         0x80007D74
    // 0x80024178: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    func_80007D74(rdram, ctx);
        goto after_0;
    // 0x80024178: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    after_0:
    // 0x8002417C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_80024180:
    // 0x80024180: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80024184: lhu         $v1, -0x70DE($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X70DE);
    // 0x80024188: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8002418C: lw          $a1, -0x5BBC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5BBC);
    // 0x80024190: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80024194: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x80024198: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8002419C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800241A0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800241A4: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800241A8: lhu         $a1, 0x2($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X2);
    // 0x800241AC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800241B0: jal         0x800225F8
    // 0x800241B4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800225F8(rdram, ctx);
        goto after_1;
    // 0x800241B4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x800241B8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800241BC: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x800241C0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800241C4: sltu        $v1, $s0, $v1
    ctx->r3 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x800241C8: bne         $v1, $zero, L_800241E8
    if (ctx->r3 != 0) {
        // 0x800241CC: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_800241E8;
    }
    // 0x800241CC: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x800241D0: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x800241D4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800241D8: jal         0x80007D74
    // 0x800241DC: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    func_80007D74(rdram, ctx);
        goto after_2;
    // 0x800241DC: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    after_2:
    // 0x800241E0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800241E4: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_800241E8:
    // 0x800241E8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800241EC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800241F0: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x800241F4: lui         $a0, 0xB900
    ctx->r4 = S32(0XB900 << 16);
    // 0x800241F8: ori         $a0, $a0, 0x31D
    ctx->r4 = ctx->r4 | 0X31D;
    // 0x800241FC: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80024200: sltu        $v1, $s0, $v1
    ctx->r3 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80024204: bne         $v1, $zero, L_80024220
    if (ctx->r3 != 0) {
        // 0x80024208: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_80024220;
    }
    // 0x80024208: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002420C: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80024210: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80024214: jal         0x80007D74
    // 0x80024218: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    func_80007D74(rdram, ctx);
        goto after_3;
    // 0x80024218: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    after_3:
    // 0x8002421C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_80024220:
    // 0x80024220: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80024224: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80024228: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8002422C: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80024230: lui         $v0, 0xBA00
    ctx->r2 = S32(0XBA00 << 16);
    // 0x80024234: ori         $v0, $v0, 0x1402
    ctx->r2 = ctx->r2 | 0X1402;
    // 0x80024238: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8002423C: lui         $v0, 0x20
    ctx->r2 = S32(0X20 << 16);
    // 0x80024240: sltu        $v1, $s0, $v1
    ctx->r3 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80024244: bne         $v1, $zero, L_80024260
    if (ctx->r3 != 0) {
        // 0x80024248: sw          $v0, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r2;
            goto L_80024260;
    }
    // 0x80024248: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8002424C: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80024250: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80024254: jal         0x80007D74
    // 0x80024258: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    func_80007D74(rdram, ctx);
        goto after_4;
    // 0x80024258: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    after_4:
    // 0x8002425C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_80024260:
    // 0x80024260: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x80024264: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80024268: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8002426C: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80024270: lui         $a0, 0xBA00
    ctx->r4 = S32(0XBA00 << 16);
    // 0x80024274: ori         $a0, $a0, 0xC02
    ctx->r4 = ctx->r4 | 0XC02;
    // 0x80024278: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8002427C: sltu        $v1, $s0, $v1
    ctx->r3 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80024280: bne         $v1, $zero, L_8002429C
    if (ctx->r3 != 0) {
        // 0x80024284: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8002429C;
    }
    // 0x80024284: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80024288: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x8002428C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80024290: jal         0x80007D74
    // 0x80024294: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    func_80007D74(rdram, ctx);
        goto after_5;
    // 0x80024294: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    after_5:
    // 0x80024298: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_8002429C:
    // 0x8002429C: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x800242A0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800242A4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800242A8: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x800242AC: lui         $a0, 0xBA00
    ctx->r4 = S32(0XBA00 << 16);
    // 0x800242B0: ori         $a0, $a0, 0x1301
    ctx->r4 = ctx->r4 | 0X1301;
    // 0x800242B4: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800242B8: sltu        $v1, $s0, $v1
    ctx->r3 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x800242BC: bne         $v1, $zero, L_800242D8
    if (ctx->r3 != 0) {
        // 0x800242C0: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_800242D8;
    }
    // 0x800242C0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800242C4: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x800242C8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800242CC: jal         0x80007D74
    // 0x800242D0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    func_80007D74(rdram, ctx);
        goto after_6;
    // 0x800242D0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    after_6:
    // 0x800242D4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_800242D8:
    // 0x800242D8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800242DC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800242E0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800242E4: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x800242E8: lui         $v0, 0xB900
    ctx->r2 = S32(0XB900 << 16);
    // 0x800242EC: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // 0x800242F0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800242F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800242F8: sltu        $v1, $s0, $v1
    ctx->r3 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x800242FC: bne         $v1, $zero, L_80024318
    if (ctx->r3 != 0) {
        // 0x80024300: sw          $v0, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r2;
            goto L_80024318;
    }
    // 0x80024300: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x80024304: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80024308: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8002430C: jal         0x80007D74
    // 0x80024310: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    func_80007D74(rdram, ctx);
        goto after_7;
    // 0x80024310: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    after_7:
    // 0x80024314: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_80024318:
    // 0x80024318: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8002431C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80024320: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80024324: lh          $a0, -0x40D8($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X40D8);
    // 0x80024328: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x8002432C: lui         $v1, 0xF900
    ctx->r3 = S32(0XF900 << 16);
    // 0x80024330: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80024334: blez        $a0, L_800244C4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80024338: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_800244C4;
    }
    // 0x80024338: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002433C: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
L_80024340:
    // 0x80024340: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80024344: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80024348: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8002434C: sll         $s1, $v1, 1
    ctx->r17 = S32(ctx->r3 << 1);
    // 0x80024350: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80024354: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x80024358: lbu         $a1, -0x70D4($at)
    ctx->r5 = MEM_BU(ctx->r1, -0X70D4);
    // 0x8002435C: addiu       $v0, $a1, -0x61
    ctx->r2 = ADD32(ctx->r5, -0X61);
    // 0x80024360: sltiu       $v0, $v0, 0x1A
    ctx->r2 = ctx->r2 < 0X1A ? 1 : 0;
    // 0x80024364: bnel        $v0, $zero, L_8002436C
    if (ctx->r2 != 0) {
        // 0x80024368: addiu       $a1, $a1, -0x20
        ctx->r5 = ADD32(ctx->r5, -0X20);
            goto L_8002436C;
    }
    goto skip_0;
    // 0x80024368: addiu       $a1, $a1, -0x20
    ctx->r5 = ADD32(ctx->r5, -0X20);
    skip_0:
L_8002436C:
    // 0x8002436C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80024370: lw          $a0, -0x7310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7310);
    // 0x80024374: jal         0x80034744
    // 0x80024378: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    strchr_recomp(rdram, ctx);
        goto after_8;
    // 0x80024378: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_8:
    // 0x8002437C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80024380: beq         $v1, $zero, L_800244A4
    if (ctx->r3 == 0) {
        // 0x80024384: addiu       $v0, $s4, 0x1
        ctx->r2 = ADD32(ctx->r20, 0X1);
            goto L_800244A4;
    }
    // 0x80024384: addiu       $v0, $s4, 0x1
    ctx->r2 = ADD32(ctx->r20, 0X1);
    // 0x80024388: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8002438C: lw          $v0, -0x7310($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7310);
    // 0x80024390: subu        $a1, $v1, $v0
    ctx->r5 = SUB32(ctx->r3, ctx->r2);
    // 0x80024394: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x80024398: lui         $v1, 0x8618
    ctx->r3 = S32(0X8618 << 16);
    // 0x8002439C: ori         $v1, $v1, 0x6187
    ctx->r3 = ctx->r3 | 0X6187;
    // 0x800243A0: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800243A4: mfhi        $v1
    ctx->r3 = hi;
    // 0x800243A8: subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
    // 0x800243AC: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x800243B0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800243B4: srl         $v1, $v1, 4
    ctx->r3 = S32(U32(ctx->r3) >> 4);
    // 0x800243B8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800243BC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800243C0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800243C4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800243C8: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x800243CC: andi        $s3, $a0, 0xFF
    ctx->r19 = ctx->r4 & 0XFF;
    // 0x800243D0: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x800243D4: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x800243D8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800243DC: lw          $a0, 0x63D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63D4);
    // 0x800243E0: subu        $s2, $v0, $v1
    ctx->r18 = SUB32(ctx->r2, ctx->r3);
    // 0x800243E4: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // 0x800243E8: sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x800243EC: bne         $v0, $zero, L_80024404
    if (ctx->r2 != 0) {
        // 0x800243F0: lui         $v0, 0xB500
        ctx->r2 = S32(0XB500 << 16);
            goto L_80024404;
    }
    // 0x800243F0: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x800243F4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800243F8: jal         0x80007D74
    // 0x800243FC: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    func_80007D74(rdram, ctx);
        goto after_9;
    // 0x800243FC: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    after_9:
    // 0x80024400: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_80024404:
    // 0x80024404: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80024408: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8002440C: lh          $a0, -0x70D8($at)
    ctx->r4 = MEM_H(ctx->r1, -0X70D8);
    // 0x80024410: lui         $a2, 0x1000
    ctx->r6 = S32(0X1000 << 16);
    // 0x80024414: ori         $a2, $a2, 0x400
    ctx->r6 = ctx->r6 | 0X400;
    // 0x80024418: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8002441C: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x80024420: lh          $v0, -0x70D6($at)
    ctx->r2 = MEM_H(ctx->r1, -0X70D6);
    // 0x80024424: lui         $v1, 0xE400
    ctx->r3 = S32(0XE400 << 16);
    // 0x80024428: addiu       $a0, $a0, 0x7
    ctx->r4 = ADD32(ctx->r4, 0X7);
    // 0x8002442C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80024430: andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    // 0x80024434: sll         $a0, $a0, 12
    ctx->r4 = S32(ctx->r4 << 12);
    // 0x80024438: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x8002443C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80024440: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80024444: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80024448: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x8002444C: sw          $a0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r4;
    // 0x80024450: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80024454: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x80024458: lh          $a0, -0x70D8($at)
    ctx->r4 = MEM_H(ctx->r1, -0X70D8);
    // 0x8002445C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80024460: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x80024464: lh          $a1, -0x70D6($at)
    ctx->r5 = MEM_H(ctx->r1, -0X70D6);
    // 0x80024468: sll         $v1, $s3, 24
    ctx->r3 = S32(ctx->r19 << 24);
    // 0x8002446C: sll         $v0, $s2, 5
    ctx->r2 = S32(ctx->r18 << 5);
    // 0x80024470: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80024474: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80024478: sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    // 0x8002447C: sw          $a2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r6;
    // 0x80024480: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80024484: andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    // 0x80024488: sll         $a0, $a0, 12
    ctx->r4 = S32(ctx->r4 << 12);
    // 0x8002448C: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x80024490: andi        $a1, $a1, 0xFFF
    ctx->r5 = ctx->r5 & 0XFFF;
    // 0x80024494: or          $a0, $a0, $a1
    ctx->r4 = ctx->r4 | ctx->r5;
    // 0x80024498: sw          $a0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r4;
    // 0x8002449C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800244A0: addiu       $v0, $s4, 0x1
    ctx->r2 = ADD32(ctx->r20, 0X1);
L_800244A4:
    // 0x800244A4: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // 0x800244A8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800244AC: lh          $v1, -0x40D8($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X40D8);
    // 0x800244B0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800244B4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800244B8: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800244BC: bne         $v0, $zero, L_80024340
    if (ctx->r2 != 0) {
        // 0x800244C0: sll         $v0, $s4, 16
        ctx->r2 = S32(ctx->r20 << 16);
            goto L_80024340;
    }
    // 0x800244C0: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
L_800244C4:
    // 0x800244C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800244C8: sh          $zero, -0x40D8($at)
    MEM_H(-0X40D8, ctx->r1) = 0;
L_800244CC:
    // 0x800244CC: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x800244D0: addiu       $v1, $zero, 0x28
    ctx->r3 = ADD32(0, 0X28);
    // 0x800244D4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800244D8: sh          $v1, -0x40D6($at)
    MEM_H(-0X40D6, ctx->r1) = ctx->r3;
    // 0x800244DC: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x800244E0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800244E4: sh          $v1, -0x40D4($at)
    MEM_H(-0X40D4, ctx->r1) = ctx->r3;
    // 0x800244E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800244EC: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800244F0: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800244F4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800244F8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800244FC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80024500: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80024504: jr          $ra
    // 0x80024508: nop

    return;
    // 0x80024508: nop

;}
RECOMP_FUNC void func_8002450C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002450C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80024510: lh          $v1, -0x40D8($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X40D8);
    // 0x80024514: slti        $v0, $v1, 0x800
    ctx->r2 = SIGNED(ctx->r3) < 0X800 ? 1 : 0;
    // 0x80024518: beq         $v0, $zero, L_80024570
    if (ctx->r2 == 0) {
        // 0x8002451C: nop
    
            goto L_80024570;
    }
    // 0x8002451C: nop

    // 0x80024520: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80024524: lbu         $v0, -0x70E0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X70E0);
    // 0x80024528: beq         $v0, $zero, L_80024570
    if (ctx->r2 == 0) {
        // 0x8002452C: sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3 << 1);
            goto L_80024570;
    }
    // 0x8002452C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80024530: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80024534: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80024538: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8002453C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80024540: sb          $a2, -0x70D4($at)
    MEM_B(-0X70D4, ctx->r1) = ctx->r6;
    // 0x80024544: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80024548: lhu         $v1, -0x40D8($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X40D8);
    // 0x8002454C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80024550: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80024554: sh          $a0, -0x70D8($at)
    MEM_H(-0X70D8, ctx->r1) = ctx->r4;
    // 0x80024558: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8002455C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80024560: sh          $a1, -0x70D6($at)
    MEM_H(-0X70D6, ctx->r1) = ctx->r5;
    // 0x80024564: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80024568: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8002456C: sh          $v1, -0x40D8($at)
    MEM_H(-0X40D8, ctx->r1) = ctx->r3;
L_80024570:
    // 0x80024570: jr          $ra
    // 0x80024574: nop

    return;
    // 0x80024574: nop

;}
RECOMP_FUNC void func_80024578(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024578: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8002457C: sra         $a0, $a0, 13
    ctx->r4 = S32(SIGNED(ctx->r4) >> 13);
    // 0x80024580: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x80024584: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80024588: sra         $a1, $a1, 13
    ctx->r5 = S32(SIGNED(ctx->r5) >> 13);
    // 0x8002458C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80024590: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80024594: sh          $a0, -0x40D6($at)
    MEM_H(-0X40D6, ctx->r1) = ctx->r4;
    // 0x80024598: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8002459C: sh          $a1, -0x40D4($at)
    MEM_H(-0X40D4, ctx->r1) = ctx->r5;
    // 0x800245A0: jr          $ra
    // 0x800245A4: nop

    return;
    // 0x800245A4: nop

;}
RECOMP_FUNC void func_800245A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800245A8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800245AC: beq         $v0, $zero, L_800246C0
    if (ctx->r2 == 0) {
        // 0x800245B0: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_800246C0;
    }
    // 0x800245B0: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x800245B4: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x800245B8: addiu       $t2, $zero, 0x9
    ctx->r10 = ADD32(0, 0X9);
    // 0x800245BC: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x800245C0: addiu       $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
L_800245C4:
    // 0x800245C4: beq         $v1, $t3, L_8002469C
    if (ctx->r3 == ctx->r11) {
        // 0x800245C8: slti        $v0, $v1, 0x21
        ctx->r2 = SIGNED(ctx->r3) < 0X21 ? 1 : 0;
            goto L_8002469C;
    }
    // 0x800245C8: slti        $v0, $v1, 0x21
    ctx->r2 = SIGNED(ctx->r3) < 0X21 ? 1 : 0;
    // 0x800245CC: beq         $v0, $zero, L_80024624
    if (ctx->r2 == 0) {
        // 0x800245D0: nop
    
            goto L_80024624;
    }
    // 0x800245D0: nop

    // 0x800245D4: beq         $v1, $t2, L_80024608
    if (ctx->r3 == ctx->r10) {
        // 0x800245D8: nop
    
            goto L_80024608;
    }
    // 0x800245D8: nop

    // 0x800245DC: bne         $v1, $t1, L_80024624
    if (ctx->r3 != ctx->r9) {
        // 0x800245E0: nop
    
            goto L_80024624;
    }
    // 0x800245E0: nop

    // 0x800245E4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800245E8: lhu         $v0, -0x40D4($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X40D4);
    // 0x800245EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800245F0: sh          $t0, -0x40D6($at)
    MEM_H(-0X40D6, ctx->r1) = ctx->r8;
    // 0x800245F4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800245F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800245FC: sh          $v0, -0x40D4($at)
    MEM_H(-0X40D4, ctx->r1) = ctx->r2;
    // 0x80024600: j           L_800246B4
    // 0x80024604: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_800246B4;
    // 0x80024604: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80024608:
    // 0x80024608: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8002460C: lhu         $v0, -0x40D6($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X40D6);
    // 0x80024610: srl         $v0, $v0, 3
    ctx->r2 = S32(U32(ctx->r2) >> 3);
    // 0x80024614: andi        $v0, $v0, 0x1FF8
    ctx->r2 = ctx->r2 & 0X1FF8;
    // 0x80024618: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8002461C: j           L_800246A8
    // 0x80024620: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
        goto L_800246A8;
    // 0x80024620: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
L_80024624:
    // 0x80024624: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80024628: lhu         $a3, -0x40D6($a3)
    ctx->r7 = MEM_HU(ctx->r7, -0X40D6);
    // 0x8002462C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80024630: lh          $v1, -0x40D8($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X40D8);
    // 0x80024634: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80024638: lhu         $a2, -0x40D4($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X40D4);
    // 0x8002463C: lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X0);
    // 0x80024640: slti        $v0, $v1, 0x800
    ctx->r2 = SIGNED(ctx->r3) < 0X800 ? 1 : 0;
    // 0x80024644: beq         $v0, $zero, L_8002469C
    if (ctx->r2 == 0) {
        // 0x80024648: nop
    
            goto L_8002469C;
    }
    // 0x80024648: nop

    // 0x8002464C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80024650: lbu         $v0, -0x70E0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X70E0);
    // 0x80024654: beq         $v0, $zero, L_8002469C
    if (ctx->r2 == 0) {
        // 0x80024658: sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3 << 1);
            goto L_8002469C;
    }
    // 0x80024658: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8002465C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80024660: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80024664: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80024668: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8002466C: sb          $a1, -0x70D4($at)
    MEM_B(-0X70D4, ctx->r1) = ctx->r5;
    // 0x80024670: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80024674: lhu         $v1, -0x40D8($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X40D8);
    // 0x80024678: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8002467C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80024680: sh          $a3, -0x70D8($at)
    MEM_H(-0X70D8, ctx->r1) = ctx->r7;
    // 0x80024684: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80024688: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8002468C: sh          $a2, -0x70D6($at)
    MEM_H(-0X70D6, ctx->r1) = ctx->r6;
    // 0x80024690: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80024694: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80024698: sh          $v1, -0x40D8($at)
    MEM_H(-0X40D8, ctx->r1) = ctx->r3;
L_8002469C:
    // 0x8002469C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800246A0: lhu         $v0, -0x40D6($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X40D6);
    // 0x800246A4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800246A8:
    // 0x800246A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800246AC: sh          $v0, -0x40D6($at)
    MEM_H(-0X40D6, ctx->r1) = ctx->r2;
    // 0x800246B0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800246B4:
    // 0x800246B4: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800246B8: bne         $v0, $zero, L_800245C4
    if (ctx->r2 != 0) {
        // 0x800246BC: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_800245C4;
    }
    // 0x800246BC: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_800246C0:
    // 0x800246C0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800246C4: lhu         $v0, -0x40D4($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X40D4);
    // 0x800246C8: addiu       $v1, $zero, 0x28
    ctx->r3 = ADD32(0, 0X28);
    // 0x800246CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800246D0: sh          $v1, -0x40D6($at)
    MEM_H(-0X40D6, ctx->r1) = ctx->r3;
    // 0x800246D4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800246D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800246DC: sh          $v0, -0x40D4($at)
    MEM_H(-0X40D4, ctx->r1) = ctx->r2;
    // 0x800246E0: jr          $ra
    // 0x800246E4: nop

    return;
    // 0x800246E4: nop

;}
RECOMP_FUNC void loadDebugAssets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800246E8: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800246EC: sw          $s3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r19;
    // 0x800246F0: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800246F4: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800246F8: addiu       $a0, $a0, 0xA3C
    ctx->r4 = ADD32(ctx->r4, 0XA3C);
    // 0x800246FC: sw          $ra, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r31;
    // 0x80024700: sw          $s4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r20;
    // 0x80024704: sw          $s2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r18;
    // 0x80024708: sw          $s1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r17;
    // 0x8002470C: sw          $s0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r16;
    // 0x80024710: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80024714: sb          $zero, -0x70E0($at)
    MEM_B(-0X70E0, ctx->r1) = 0;
    // 0x80024718: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8002471C: sh          $zero, -0x40D8($at)
    MEM_H(-0X40D8, ctx->r1) = 0;
    // 0x80024720: jal         0x800047F4
    // 0x80024724: nop

    findManifestEntryByName(rdram, ctx);
        goto after_0;
    // 0x80024724: nop

    after_0:
    // 0x80024728: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // 0x8002472C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80024730: beq         $s4, $v0, L_80024854
    if (ctx->r20 == ctx->r2) {
        // 0x80024734: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_80024854;
    }
    // 0x80024734: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80024738: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x8002473C: addiu       $s0, $s0, 0xA48
    ctx->r16 = ADD32(ctx->r16, 0XA48);
    // 0x80024740: jal         0x80004D5C
    // 0x80024744: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    get_asset_size_extra(rdram, ctx);
        goto after_1;
    // 0x80024744: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80024748: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8002474C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80024750: jal         0x80001ACC
    // 0x80024754: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    rs_malloc(rdram, ctx);
        goto after_2;
    // 0x80024754: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
    // 0x80024758: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8002475C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80024760: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    // 0x80024764: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x80024768: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8002476C: jal         0x80004AAC
    // 0x80024770: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80004AAC(rdram, ctx);
        goto after_3;
    // 0x80024770: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x80024774: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80024778: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8002477C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80024780: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x80024784: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80024788: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8002478C: jal         0x80004E70
    // 0x80024790: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    setupAssetDma(rdram, ctx);
        goto after_4;
    // 0x80024790: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_4:
    // 0x80024794: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80024798: jal         0x80004C70
    // 0x8002479C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    teardownAssetDma(rdram, ctx);
        goto after_5;
    // 0x8002479C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_5:
    // 0x800247A0: addiu       $v0, $s0, 0x3C
    ctx->r2 = ADD32(ctx->r16, 0X3C);
    // 0x800247A4: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x800247A8: addiu       $v0, $s0, 0xC
    ctx->r2 = ADD32(ctx->r16, 0XC);
    // 0x800247AC: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x800247B0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800247B4: addiu       $v0, $v0, 0xA54
    ctx->r2 = ADD32(ctx->r2, 0XA54);
    // 0x800247B8: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x800247BC: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x800247C0: sh          $v0, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r2;
    // 0x800247C4: lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6);
    // 0x800247C8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800247CC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800247D0: sb          $s1, 0x6C($sp)
    MEM_B(0X6C, ctx->r29) = ctx->r17;
    // 0x800247D4: sh          $v0, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r2;
    // 0x800247D8: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800247DC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800247E0: sb          $zero, 0x70($sp)
    MEM_B(0X70, ctx->r29) = 0;
    // 0x800247E4: sb          $zero, 0x71($sp)
    MEM_B(0X71, ctx->r29) = 0;
    // 0x800247E8: sb          $zero, 0x72($sp)
    MEM_B(0X72, ctx->r29) = 0;
    // 0x800247EC: ori         $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 | 0X4000;
    // 0x800247F0: sh          $v0, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r2;
    // 0x800247F4: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x800247F8: addiu       $t0, $t0, 0xA60
    ctx->r8 = ADD32(ctx->r8, 0XA60);
    // 0x800247FC: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80024800: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x80024804: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    // 0x80024808: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8002480C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x80024810: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80024814: jal         0x80022B90
    // 0x80024818: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    registerHmtTextureInTable(rdram, ctx);
        goto after_6;
    // 0x80024818: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x8002481C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80024820: sh          $v0, -0x70DE($at)
    MEM_H(-0X70DE, ctx->r1) = ctx->r2;
    // 0x80024824: jal         0x80001C98
    // 0x80024828: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    rs_free(rdram, ctx);
        goto after_7;
    // 0x80024828: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
    // 0x8002482C: jal         0x80004994
    // 0x80024830: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    func_80004994(rdram, ctx);
        goto after_8;
    // 0x80024830: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_8:
    // 0x80024834: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x80024838: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8002483C: sh          $v0, -0x40D6($at)
    MEM_H(-0X40D6, ctx->r1) = ctx->r2;
    // 0x80024840: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80024844: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80024848: sh          $v0, -0x40D4($at)
    MEM_H(-0X40D4, ctx->r1) = ctx->r2;
    // 0x8002484C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80024850: sb          $s1, -0x70E0($at)
    MEM_B(-0X70E0, ctx->r1) = ctx->r17;
L_80024854:
    // 0x80024854: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
    // 0x80024858: lw          $s4, 0x88($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X88);
    // 0x8002485C: lw          $s3, 0x84($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X84);
    // 0x80024860: lw          $s2, 0x80($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X80);
    // 0x80024864: lw          $s1, 0x7C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X7C);
    // 0x80024868: lw          $s0, 0x78($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X78);
    // 0x8002486C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x80024870: jr          $ra
    // 0x80024874: nop

    return;
    // 0x80024874: nop

;}
RECOMP_FUNC void fake_func_80024878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80024880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024880: addu        $t2, $a1, $zero
    ctx->r10 = ADD32(ctx->r5, 0);
    // 0x80024884: addu        $t3, $a0, $zero
    ctx->r11 = ADD32(ctx->r4, 0);
    // 0x80024888: srl         $t7, $a3, 1
    ctx->r15 = S32(U32(ctx->r7) >> 1);
    // 0x8002488C: addiu       $t0, $a2, 0x1
    ctx->r8 = ADD32(ctx->r6, 0X1);
    // 0x80024890: srl         $t0, $t0, 1
    ctx->r8 = S32(U32(ctx->r8) >> 1);
    // 0x80024894: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x80024898: beq         $t7, $zero, L_800249A0
    if (ctx->r15 == 0) {
        // 0x8002489C: lw          $t6, 0x10($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X10);
            goto L_800249A0;
    }
    // 0x8002489C: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
L_800248A0:
    // 0x800248A0: srl         $t4, $a3, 4
    ctx->r12 = S32(U32(ctx->r7) >> 4);
L_800248A4:
    // 0x800248A4: lbu         $t0, 0x0($t2)
    ctx->r8 = MEM_BU(ctx->r10, 0X0);
    // 0x800248A8: lbu         $t1, 0x1($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X1);
    // 0x800248AC: dsll        $t0, $t0, 8
    ctx->r8 = ctx->r8 << 8;
    // 0x800248B0: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x800248B4: lbu         $t1, 0x2($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X2);
    // 0x800248B8: dsll        $t0, $t0, 8
    ctx->r8 = ctx->r8 << 8;
    // 0x800248BC: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x800248C0: lbu         $t1, 0x3($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X3);
    // 0x800248C4: dsll        $t0, $t0, 8
    ctx->r8 = ctx->r8 << 8;
    // 0x800248C8: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x800248CC: lbu         $t1, 0x4($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X4);
    // 0x800248D0: dsll        $t0, $t0, 8
    ctx->r8 = ctx->r8 << 8;
    // 0x800248D4: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x800248D8: lbu         $t1, 0x5($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X5);
    // 0x800248DC: dsll        $t0, $t0, 8
    ctx->r8 = ctx->r8 << 8;
    // 0x800248E0: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x800248E4: lbu         $t1, 0x6($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X6);
    // 0x800248E8: dsll        $t0, $t0, 8
    ctx->r8 = ctx->r8 << 8;
    // 0x800248EC: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x800248F0: lbu         $t1, 0x7($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X7);
    // 0x800248F4: dsll        $t0, $t0, 8
    ctx->r8 = ctx->r8 << 8;
    // 0x800248F8: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x800248FC: sd          $t0, 0x0($t3)
    SD(ctx->r8, 0X0, ctx->r11);
    // 0x80024900: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x80024904: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x80024908: bne         $t4, $zero, L_800248A4
    if (ctx->r12 != 0) {
        // 0x8002490C: addiu       $t3, $t3, 0x8
        ctx->r11 = ADD32(ctx->r11, 0X8);
            goto L_800248A4;
    }
    // 0x8002490C: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x80024910: addiu       $t6, $t6, -0x1
    ctx->r14 = ADD32(ctx->r14, -0X1);
    // 0x80024914: beq         $t6, $zero, L_80024998
    if (ctx->r14 == 0) {
        // 0x80024918: subu        $t2, $t2, $t7
        ctx->r10 = SUB32(ctx->r10, ctx->r15);
            goto L_80024998;
    }
    // 0x80024918: subu        $t2, $t2, $t7
    ctx->r10 = SUB32(ctx->r10, ctx->r15);
    // 0x8002491C: srl         $t4, $a3, 4
    ctx->r12 = S32(U32(ctx->r7) >> 4);
L_80024920:
    // 0x80024920: lbu         $t0, 0x4($t2)
    ctx->r8 = MEM_BU(ctx->r10, 0X4);
    // 0x80024924: lbu         $t1, 0x5($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X5);
    // 0x80024928: dsll        $t0, $t0, 8
    ctx->r8 = ctx->r8 << 8;
    // 0x8002492C: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x80024930: lbu         $t1, 0x6($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X6);
    // 0x80024934: dsll        $t0, $t0, 8
    ctx->r8 = ctx->r8 << 8;
    // 0x80024938: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x8002493C: lbu         $t1, 0x7($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X7);
    // 0x80024940: dsll        $t0, $t0, 8
    ctx->r8 = ctx->r8 << 8;
    // 0x80024944: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x80024948: lbu         $t1, 0x0($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X0);
    // 0x8002494C: dsll        $t0, $t0, 8
    ctx->r8 = ctx->r8 << 8;
    // 0x80024950: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x80024954: lbu         $t1, 0x1($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X1);
    // 0x80024958: dsll        $t0, $t0, 8
    ctx->r8 = ctx->r8 << 8;
    // 0x8002495C: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x80024960: lbu         $t1, 0x2($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X2);
    // 0x80024964: dsll        $t0, $t0, 8
    ctx->r8 = ctx->r8 << 8;
    // 0x80024968: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x8002496C: lbu         $t1, 0x3($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X3);
    // 0x80024970: dsll        $t0, $t0, 8
    ctx->r8 = ctx->r8 << 8;
    // 0x80024974: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x80024978: sd          $t0, 0x0($t3)
    SD(ctx->r8, 0X0, ctx->r11);
    // 0x8002497C: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x80024980: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x80024984: bne         $t4, $zero, L_80024920
    if (ctx->r12 != 0) {
        // 0x80024988: addiu       $t3, $t3, 0x8
        ctx->r11 = ADD32(ctx->r11, 0X8);
            goto L_80024920;
    }
    // 0x80024988: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x8002498C: addiu       $t6, $t6, -0x1
    ctx->r14 = ADD32(ctx->r14, -0X1);
    // 0x80024990: bne         $t6, $zero, L_800248A0
    if (ctx->r14 != 0) {
        // 0x80024994: subu        $t2, $t2, $t7
        ctx->r10 = SUB32(ctx->r10, ctx->r15);
            goto L_800248A0;
    }
    // 0x80024994: subu        $t2, $t2, $t7
    ctx->r10 = SUB32(ctx->r10, ctx->r15);
L_80024998:
    // 0x80024998: jr          $ra
    // 0x8002499C: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
    return;
    // 0x8002499C: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
L_800249A0:
    // 0x800249A0: srl         $t4, $a3, 4
    ctx->r12 = S32(U32(ctx->r7) >> 4);
L_800249A4:
    // 0x800249A4: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x800249A8: lwu         $t1, 0x4($t2)
    ctx->r9 = MEM_WU(ctx->r10, 0X4);
    // 0x800249AC: dsll32      $t0, $t0, 0
    ctx->r8 = ctx->r8 << (0 + 32);
    // 0x800249B0: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x800249B4: sd          $t0, 0x0($t3)
    SD(ctx->r8, 0X0, ctx->r11);
    // 0x800249B8: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x800249BC: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x800249C0: bne         $t4, $zero, L_800249A4
    if (ctx->r12 != 0) {
        // 0x800249C4: addiu       $t3, $t3, 0x8
        ctx->r11 = ADD32(ctx->r11, 0X8);
            goto L_800249A4;
    }
    // 0x800249C4: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x800249C8: addiu       $t6, $t6, -0x1
    ctx->r14 = ADD32(ctx->r14, -0X1);
    // 0x800249CC: beq         $t6, $zero, L_80024A04
    if (ctx->r14 == 0) {
        // 0x800249D0: srl         $t4, $a3, 4
        ctx->r12 = S32(U32(ctx->r7) >> 4);
            goto L_80024A04;
    }
    // 0x800249D0: srl         $t4, $a3, 4
    ctx->r12 = S32(U32(ctx->r7) >> 4);
L_800249D4:
    // 0x800249D4: lw          $t0, 0x4($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X4);
    // 0x800249D8: lwu         $t1, 0x0($t2)
    ctx->r9 = MEM_WU(ctx->r10, 0X0);
    // 0x800249DC: dsll32      $t0, $t0, 0
    ctx->r8 = ctx->r8 << (0 + 32);
    // 0x800249E0: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x800249E4: sd          $t0, 0x0($t3)
    SD(ctx->r8, 0X0, ctx->r11);
    // 0x800249E8: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x800249EC: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x800249F0: bne         $t4, $zero, L_800249D4
    if (ctx->r12 != 0) {
        // 0x800249F4: addiu       $t3, $t3, 0x8
        ctx->r11 = ADD32(ctx->r11, 0X8);
            goto L_800249D4;
    }
    // 0x800249F4: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x800249F8: addiu       $t6, $t6, -0x1
    ctx->r14 = ADD32(ctx->r14, -0X1);
    // 0x800249FC: bne         $t6, $zero, L_800249A4
    if (ctx->r14 != 0) {
        // 0x80024A00: srl         $t4, $a3, 4
        ctx->r12 = S32(U32(ctx->r7) >> 4);
            goto L_800249A4;
    }
    // 0x80024A00: srl         $t4, $a3, 4
    ctx->r12 = S32(U32(ctx->r7) >> 4);
L_80024A04:
    // 0x80024A04: jr          $ra
    // 0x80024A08: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
    return;
    // 0x80024A08: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
;}
RECOMP_FUNC void fake_func_80024A0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void adler32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800269B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800269B4: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800269B8: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x800269BC: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // 0x800269C0: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x800269C4: andi        $t8, $a0, 0xFFFF
    ctx->r24 = ctx->r4 & 0XFFFF;
    // 0x800269C8: srl         $t9, $a0, 16
    ctx->r25 = S32(U32(ctx->r4) >> 16);
    // 0x800269CC: sw          $s7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r23;
    // 0x800269D0: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    // 0x800269D4: sw          $s3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r19;
    // 0x800269D8: sw          $s2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r18;
    // 0x800269DC: sw          $s1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r17;
    // 0x800269E0: bne         $s4, $zero, L_800269F0
    if (ctx->r20 != 0) {
        // 0x800269E4: sw          $s0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r16;
            goto L_800269F0;
    }
    // 0x800269E4: sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // 0x800269E8: j           L_80026B6C
    // 0x800269EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80026B6C;
    // 0x800269EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800269F0:
    // 0x800269F0: beq         $s5, $zero, L_80026B68
    if (ctx->r21 == 0) {
        // 0x800269F4: sll         $v0, $t9, 16
        ctx->r2 = S32(ctx->r25 << 16);
            goto L_80026B68;
    }
    // 0x800269F4: sll         $v0, $t9, 16
    ctx->r2 = S32(ctx->r25 << 16);
    // 0x800269F8: lui         $s6, 0x8007
    ctx->r22 = S32(0X8007 << 16);
    // 0x800269FC: ori         $s6, $s6, 0x8071
    ctx->r22 = ctx->r22 | 0X8071;
L_80026A00:
    // 0x80026A00: sltiu       $v0, $s5, 0x15B1
    ctx->r2 = ctx->r21 < 0X15B1 ? 1 : 0;
    // 0x80026A04: bne         $v0, $zero, L_80026A10
    if (ctx->r2 != 0) {
        // 0x80026A08: addu        $s3, $s5, $zero
        ctx->r19 = ADD32(ctx->r21, 0);
            goto L_80026A10;
    }
    // 0x80026A08: addu        $s3, $s5, $zero
    ctx->r19 = ADD32(ctx->r21, 0);
    // 0x80026A0C: addiu       $s3, $zero, 0x15B0
    ctx->r19 = ADD32(0, 0X15B0);
L_80026A10:
    // 0x80026A10: slti        $v0, $s3, 0x10
    ctx->r2 = SIGNED(ctx->r19) < 0X10 ? 1 : 0;
    // 0x80026A14: bne         $v0, $zero, L_80026AF4
    if (ctx->r2 != 0) {
        // 0x80026A18: subu        $s5, $s5, $s3
        ctx->r21 = SUB32(ctx->r21, ctx->r19);
            goto L_80026AF4;
    }
    // 0x80026A18: subu        $s5, $s5, $s3
    ctx->r21 = SUB32(ctx->r21, ctx->r19);
    // 0x80026A1C: addiu       $s2, $s4, 0xF
    ctx->r18 = ADD32(ctx->r20, 0XF);
L_80026A20:
    // 0x80026A20: lbu         $v1, -0xE($s2)
    ctx->r3 = MEM_BU(ctx->r18, -0XE);
    // 0x80026A24: lbu         $a0, -0xD($s2)
    ctx->r4 = MEM_BU(ctx->r18, -0XD);
    // 0x80026A28: lbu         $a1, -0xC($s2)
    ctx->r5 = MEM_BU(ctx->r18, -0XC);
    // 0x80026A2C: lbu         $a2, -0xB($s2)
    ctx->r6 = MEM_BU(ctx->r18, -0XB);
    // 0x80026A30: lbu         $a3, -0xA($s2)
    ctx->r7 = MEM_BU(ctx->r18, -0XA);
    // 0x80026A34: lbu         $t0, -0x9($s2)
    ctx->r8 = MEM_BU(ctx->r18, -0X9);
    // 0x80026A38: lbu         $t1, -0x8($s2)
    ctx->r9 = MEM_BU(ctx->r18, -0X8);
    // 0x80026A3C: lbu         $t2, -0x7($s2)
    ctx->r10 = MEM_BU(ctx->r18, -0X7);
    // 0x80026A40: lbu         $t3, -0x6($s2)
    ctx->r11 = MEM_BU(ctx->r18, -0X6);
    // 0x80026A44: lbu         $t4, -0x5($s2)
    ctx->r12 = MEM_BU(ctx->r18, -0X5);
    // 0x80026A48: lbu         $t5, -0x4($s2)
    ctx->r13 = MEM_BU(ctx->r18, -0X4);
    // 0x80026A4C: lbu         $t6, -0x3($s2)
    ctx->r14 = MEM_BU(ctx->r18, -0X3);
    // 0x80026A50: lbu         $t7, -0x2($s2)
    ctx->r15 = MEM_BU(ctx->r18, -0X2);
    // 0x80026A54: lbu         $s0, -0x1($s2)
    ctx->r16 = MEM_BU(ctx->r18, -0X1);
    // 0x80026A58: lbu         $s1, 0x0($s2)
    ctx->r17 = MEM_BU(ctx->r18, 0X0);
    // 0x80026A5C: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x80026A60: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x80026A64: addiu       $s4, $s4, 0x10
    ctx->r20 = ADD32(ctx->r20, 0X10);
    // 0x80026A68: addiu       $s3, $s3, -0x10
    ctx->r19 = ADD32(ctx->r19, -0X10);
    // 0x80026A6C: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x80026A70: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80026A74: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x80026A78: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80026A7C: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x80026A80: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80026A84: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x80026A88: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80026A8C: addu        $t8, $t8, $a2
    ctx->r24 = ADD32(ctx->r24, ctx->r6);
    // 0x80026A90: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80026A94: addu        $t8, $t8, $a3
    ctx->r24 = ADD32(ctx->r24, ctx->r7);
    // 0x80026A98: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80026A9C: addu        $t8, $t8, $t0
    ctx->r24 = ADD32(ctx->r24, ctx->r8);
    // 0x80026AA0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80026AA4: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x80026AA8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80026AAC: addu        $t8, $t8, $t2
    ctx->r24 = ADD32(ctx->r24, ctx->r10);
    // 0x80026AB0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80026AB4: addu        $t8, $t8, $t3
    ctx->r24 = ADD32(ctx->r24, ctx->r11);
    // 0x80026AB8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80026ABC: addu        $t8, $t8, $t4
    ctx->r24 = ADD32(ctx->r24, ctx->r12);
    // 0x80026AC0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80026AC4: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x80026AC8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80026ACC: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x80026AD0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80026AD4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80026AD8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80026ADC: addu        $t8, $t8, $s0
    ctx->r24 = ADD32(ctx->r24, ctx->r16);
    // 0x80026AE0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80026AE4: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x80026AE8: slti        $v0, $s3, 0x10
    ctx->r2 = SIGNED(ctx->r19) < 0X10 ? 1 : 0;
    // 0x80026AEC: beq         $v0, $zero, L_80026A20
    if (ctx->r2 == 0) {
        // 0x80026AF0: addu        $t9, $t9, $t8
        ctx->r25 = ADD32(ctx->r25, ctx->r24);
            goto L_80026A20;
    }
    // 0x80026AF0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
L_80026AF4:
    // 0x80026AF4: multu       $t8, $s6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80026AF8: beq         $s3, $zero, L_80026B1C
    if (ctx->r19 == 0) {
        // 0x80026AFC: nop
    
            goto L_80026B1C;
    }
    // 0x80026AFC: nop

L_80026B00:
    // 0x80026B00: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x80026B04: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80026B08: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x80026B0C: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x80026B10: bne         $s3, $zero, L_80026B00
    if (ctx->r19 != 0) {
        // 0x80026B14: addu        $t9, $t9, $t8
        ctx->r25 = ADD32(ctx->r25, ctx->r24);
            goto L_80026B00;
    }
    // 0x80026B14: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80026B18: multu       $t8, $s6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
L_80026B1C:
    // 0x80026B1C: mfhi        $v1
    ctx->r3 = hi;
    // 0x80026B20: nop

    // 0x80026B24: nop

    // 0x80026B28: multu       $t9, $s6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80026B2C: srl         $v1, $v1, 15
    ctx->r3 = S32(U32(ctx->r3) >> 15);
    // 0x80026B30: sll         $v0, $v1, 12
    ctx->r2 = S32(ctx->r3 << 12);
    // 0x80026B34: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80026B38: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80026B3C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80026B40: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x80026B44: mfhi        $a0
    ctx->r4 = hi;
    // 0x80026B48: srl         $v1, $a0, 15
    ctx->r3 = S32(U32(ctx->r4) >> 15);
    // 0x80026B4C: sll         $v0, $v1, 12
    ctx->r2 = S32(ctx->r3 << 12);
    // 0x80026B50: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80026B54: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80026B58: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80026B5C: bne         $s5, $zero, L_80026A00
    if (ctx->r21 != 0) {
        // 0x80026B60: subu        $t9, $t9, $v0
        ctx->r25 = SUB32(ctx->r25, ctx->r2);
            goto L_80026A00;
    }
    // 0x80026B60: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x80026B64: sll         $v0, $t9, 16
    ctx->r2 = S32(ctx->r25 << 16);
L_80026B68:
    // 0x80026B68: or          $v0, $v0, $t8
    ctx->r2 = ctx->r2 | ctx->r24;
L_80026B6C:
    // 0x80026B6C: lw          $s7, 0x1C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X1C);
    // 0x80026B70: lw          $s6, 0x18($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X18);
    // 0x80026B74: lw          $s5, 0x14($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X14);
    // 0x80026B78: lw          $s4, 0x10($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X10);
    // 0x80026B7C: lw          $s3, 0xC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XC);
    // 0x80026B80: lw          $s2, 0x8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X8);
    // 0x80026B84: lw          $s1, 0x4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4);
    // 0x80026B88: lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X0);
    // 0x80026B8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80026B90: jr          $ra
    // 0x80026B94: nop

    return;
    // 0x80026B94: nop

;}
RECOMP_FUNC void fake_func_80026B98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026B98: sw          $a0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r4;
    // 0x80026B9C: lhu         $v0, 0x34($fp)
    ctx->r2 = MEM_HU(ctx->r30, 0X34);
;}
RECOMP_FUNC void inflateReset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026BA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80026BA4: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80026BA8: beq         $a1, $zero, L_80026BBC
    if (ctx->r5 == 0) {
        // 0x80026BAC: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_80026BBC;
    }
    // 0x80026BAC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80026BB0: lw          $v0, 0x1C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1C);
    // 0x80026BB4: bnel        $v0, $zero, L_80026BC4
    if (ctx->r2 != 0) {
        // 0x80026BB8: sw          $zero, 0x14($a1)
        MEM_W(0X14, ctx->r5) = 0;
            goto L_80026BC4;
    }
    goto skip_0;
    // 0x80026BB8: sw          $zero, 0x14($a1)
    MEM_W(0X14, ctx->r5) = 0;
    skip_0:
L_80026BBC:
    // 0x80026BBC: j           L_80026BF4
    // 0x80026BC0: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
        goto L_80026BF4;
    // 0x80026BC0: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_80026BC4:
    // 0x80026BC4: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x80026BC8: sw          $zero, 0x18($a1)
    MEM_W(0X18, ctx->r5) = 0;
    // 0x80026BCC: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80026BD0: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x80026BD4: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x80026BD8: andi        $v1, $v1, 0x7
    ctx->r3 = ctx->r3 & 0X7;
    // 0x80026BDC: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80026BE0: lw          $v0, 0x1C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1C);
    // 0x80026BE4: lw          $a0, 0x14($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X14);
    // 0x80026BE8: jal         0x800275F0
    // 0x80026BEC: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    inflate_blocks_reset(rdram, ctx);
        goto after_0;
    // 0x80026BEC: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x80026BF0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80026BF4:
    // 0x80026BF4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80026BF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80026BFC: jr          $ra
    // 0x80026C00: nop

    return;
    // 0x80026C00: nop

;}
RECOMP_FUNC void inflateEnd(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026C04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80026C08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80026C0C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80026C10: beq         $s0, $zero, L_80026C30
    if (ctx->r16 == 0) {
        // 0x80026C14: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80026C30;
    }
    // 0x80026C14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80026C18: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80026C1C: beq         $a0, $zero, L_80026C68
    if (ctx->r4 == 0) {
        // 0x80026C20: addiu       $v0, $zero, -0x2
        ctx->r2 = ADD32(0, -0X2);
            goto L_80026C68;
    }
    // 0x80026C20: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // 0x80026C24: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80026C28: bne         $v0, $zero, L_80026C38
    if (ctx->r2 != 0) {
        // 0x80026C2C: nop
    
            goto L_80026C38;
    }
    // 0x80026C2C: nop

L_80026C30:
    // 0x80026C30: j           L_80026C68
    // 0x80026C34: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
        goto L_80026C68;
    // 0x80026C34: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_80026C38:
    // 0x80026C38: lw          $a0, 0x14($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14);
    // 0x80026C3C: beq         $a0, $zero, L_80026C4C
    if (ctx->r4 == 0) {
        // 0x80026C40: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_80026C4C;
    }
    // 0x80026C40: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80026C44: jal         0x800283D8
    // 0x80026C48: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    inflate_blocks_free(rdram, ctx);
        goto after_0;
    // 0x80026C48: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_0:
L_80026C4C:
    // 0x80026C4C: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x80026C50: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x80026C54: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80026C58: jalr        $v0
    // 0x80026C5C: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x80026C5C: nop

    after_1:
    // 0x80026C60: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80026C64: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
L_80026C68:
    // 0x80026C68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80026C6C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80026C70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80026C74: jr          $ra
    // 0x80026C78: nop

    return;
    // 0x80026C78: nop

;}
RECOMP_FUNC void inflateInit2_(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026C7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80026C80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80026C84: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80026C88: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80026C8C: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80026C90: beq         $a2, $zero, L_80026CB8
    if (ctx->r6 == 0) {
        // 0x80026C94: sw          $ra, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r31;
            goto L_80026CB8;
    }
    // 0x80026C94: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80026C98: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x80026C9C: xori        $v1, $a3, 0x38
    ctx->r3 = ctx->r7 ^ 0X38;
    // 0x80026CA0: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x80026CA4: xori        $v0, $v0, 0x66
    ctx->r2 = ctx->r2 ^ 0X66;
    // 0x80026CA8: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80026CAC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80026CB0: beq         $v0, $zero, L_80026CC0
    if (ctx->r2 == 0) {
        // 0x80026CB4: nop
    
            goto L_80026CC0;
    }
    // 0x80026CB4: nop

L_80026CB8:
    // 0x80026CB8: j           L_80026E64
    // 0x80026CBC: addiu       $v0, $zero, -0x6
    ctx->r2 = ADD32(0, -0X6);
        goto L_80026E64;
    // 0x80026CBC: addiu       $v0, $zero, -0x6
    ctx->r2 = ADD32(0, -0X6);
L_80026CC0:
    // 0x80026CC0: bne         $s0, $zero, L_80026CD0
    if (ctx->r16 != 0) {
        // 0x80026CC4: nop
    
            goto L_80026CD0;
    }
    // 0x80026CC4: nop

L_80026CC8:
    // 0x80026CC8: j           L_80026E64
    // 0x80026CCC: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
        goto L_80026E64;
    // 0x80026CCC: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_80026CD0:
    // 0x80026CD0: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x80026CD4: bne         $v0, $zero, L_80026CEC
    if (ctx->r2 != 0) {
        // 0x80026CD8: sw          $zero, 0x18($s0)
        MEM_W(0X18, ctx->r16) = 0;
            goto L_80026CEC;
    }
    // 0x80026CD8: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x80026CDC: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x80026CE0: addiu       $v0, $v0, -0x6330
    ctx->r2 = ADD32(ctx->r2, -0X6330);
    // 0x80026CE4: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x80026CE8: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
L_80026CEC:
    // 0x80026CEC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80026CF0: bne         $v0, $zero, L_80026D04
    if (ctx->r2 != 0) {
        // 0x80026CF4: nop
    
            goto L_80026D04;
    }
    // 0x80026CF4: nop

    // 0x80026CF8: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x80026CFC: addiu       $v0, $v0, -0x630C
    ctx->r2 = ADD32(ctx->r2, -0X630C);
    // 0x80026D00: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
L_80026D04:
    // 0x80026D04: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x80026D08: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x80026D0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80026D10: jalr        $v0
    // 0x80026D14: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80026D14: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_0:
    // 0x80026D18: bne         $v0, $zero, L_80026D28
    if (ctx->r2 != 0) {
        // 0x80026D1C: sw          $v0, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = ctx->r2;
            goto L_80026D28;
    }
    // 0x80026D1C: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
L_80026D20:
    // 0x80026D20: j           L_80026E64
    // 0x80026D24: addiu       $v0, $zero, -0x4
    ctx->r2 = ADD32(0, -0X4);
        goto L_80026E64;
    // 0x80026D24: addiu       $v0, $zero, -0x4
    ctx->r2 = ADD32(0, -0X4);
L_80026D28:
    // 0x80026D28: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x80026D2C: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x80026D30: bgez        $s1, L_80026D48
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80026D34: sw          $zero, 0xC($v0)
        MEM_W(0XC, ctx->r2) = 0;
            goto L_80026D48;
    }
    // 0x80026D34: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80026D38: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    // 0x80026D3C: negu        $s1, $s1
    ctx->r17 = SUB32(0, ctx->r17);
    // 0x80026D40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80026D44: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
L_80026D48:
    // 0x80026D48: addiu       $v0, $s1, -0x8
    ctx->r2 = ADD32(ctx->r17, -0X8);
    // 0x80026D4C: sltiu       $v0, $v0, 0x8
    ctx->r2 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x80026D50: bne         $v0, $zero, L_80026DA0
    if (ctx->r2 != 0) {
        // 0x80026D54: nop
    
            goto L_80026DA0;
    }
    // 0x80026D54: nop

    // 0x80026D58: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80026D5C: beq         $a0, $zero, L_80026E64
    if (ctx->r4 == 0) {
        // 0x80026D60: addiu       $v0, $zero, -0x2
        ctx->r2 = ADD32(0, -0X2);
            goto L_80026E64;
    }
    // 0x80026D60: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // 0x80026D64: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80026D68: beql        $v0, $zero, L_80026E64
    if (ctx->r2 == 0) {
        // 0x80026D6C: addiu       $v0, $zero, -0x2
        ctx->r2 = ADD32(0, -0X2);
            goto L_80026E64;
    }
    goto skip_0;
    // 0x80026D6C: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    skip_0:
    // 0x80026D70: lw          $a0, 0x14($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14);
    // 0x80026D74: beq         $a0, $zero, L_80026D84
    if (ctx->r4 == 0) {
        // 0x80026D78: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_80026D84;
    }
    // 0x80026D78: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80026D7C: jal         0x800283D8
    // 0x80026D80: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    inflate_blocks_free(rdram, ctx);
        goto after_1;
    // 0x80026D80: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_1:
L_80026D84:
    // 0x80026D84: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x80026D88: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x80026D8C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80026D90: jalr        $v0
    // 0x80026D94: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x80026D94: nop

    after_2:
    // 0x80026D98: j           L_80026CC8
    // 0x80026D9C: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
        goto L_80026CC8;
    // 0x80026D9C: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
L_80026DA0:
    // 0x80026DA0: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x80026DA4: sw          $s1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r17;
    // 0x80026DA8: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x80026DAC: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x80026DB0: bne         $v0, $zero, L_80026DC0
    if (ctx->r2 != 0) {
        // 0x80026DB4: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80026DC0;
    }
    // 0x80026DB4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80026DB8: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    // 0x80026DBC: addiu       $a1, $a1, 0x69B0
    ctx->r5 = ADD32(ctx->r5, 0X69B0);
L_80026DC0:
    // 0x80026DC0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80026DC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80026DC8: jal         0x800276C4
    // 0x80026DCC: sllv        $a2, $a2, $s1
    ctx->r6 = S32(ctx->r6 << (ctx->r17 & 31));
    inflate_blocks_new(rdram, ctx);
        goto after_3;
    // 0x80026DCC: sllv        $a2, $a2, $s1
    ctx->r6 = S32(ctx->r6 << (ctx->r17 & 31));
    after_3:
    // 0x80026DD0: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    // 0x80026DD4: bne         $v0, $zero, L_80026E24
    if (ctx->r2 != 0) {
        // 0x80026DD8: sw          $v0, 0x14($v1)
        MEM_W(0X14, ctx->r3) = ctx->r2;
            goto L_80026E24;
    }
    // 0x80026DD8: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x80026DDC: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80026DE0: beq         $a0, $zero, L_80026E64
    if (ctx->r4 == 0) {
        // 0x80026DE4: addiu       $v0, $zero, -0x4
        ctx->r2 = ADD32(0, -0X4);
            goto L_80026E64;
    }
    // 0x80026DE4: addiu       $v0, $zero, -0x4
    ctx->r2 = ADD32(0, -0X4);
    // 0x80026DE8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80026DEC: beql        $v0, $zero, L_80026E64
    if (ctx->r2 == 0) {
        // 0x80026DF0: addiu       $v0, $zero, -0x4
        ctx->r2 = ADD32(0, -0X4);
            goto L_80026E64;
    }
    goto skip_1;
    // 0x80026DF0: addiu       $v0, $zero, -0x4
    ctx->r2 = ADD32(0, -0X4);
    skip_1:
    // 0x80026DF4: lw          $a0, 0x14($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14);
    // 0x80026DF8: beq         $a0, $zero, L_80026E08
    if (ctx->r4 == 0) {
        // 0x80026DFC: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_80026E08;
    }
    // 0x80026DFC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80026E00: jal         0x800283D8
    // 0x80026E04: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    inflate_blocks_free(rdram, ctx);
        goto after_4;
    // 0x80026E04: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_4:
L_80026E08:
    // 0x80026E08: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x80026E0C: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x80026E10: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80026E14: jalr        $v0
    // 0x80026E18: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_5;
    // 0x80026E18: nop

    after_5:
    // 0x80026E1C: j           L_80026D20
    // 0x80026E20: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
        goto L_80026D20;
    // 0x80026E20: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
L_80026E24:
    // 0x80026E24: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x80026E28: beq         $v0, $zero, L_80026E60
    if (ctx->r2 == 0) {
        // 0x80026E2C: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_80026E60;
    }
    // 0x80026E2C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80026E30: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x80026E34: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x80026E38: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x80026E3C: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80026E40: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x80026E44: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x80026E48: andi        $v1, $v1, 0x7
    ctx->r3 = ctx->r3 & 0X7;
    // 0x80026E4C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80026E50: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x80026E54: lw          $a0, 0x14($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X14);
    // 0x80026E58: jal         0x800275F0
    // 0x80026E5C: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    inflate_blocks_reset(rdram, ctx);
        goto after_6;
    // 0x80026E5C: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_6:
L_80026E60:
    // 0x80026E60: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80026E64:
    // 0x80026E64: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80026E68: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80026E6C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80026E70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80026E74: jr          $ra
    // 0x80026E78: nop

    return;
    // 0x80026E78: nop

;}
RECOMP_FUNC void inflateInit_(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026E7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80026E80: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80026E84: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x80026E88: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x80026E8C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80026E90: jal         0x80026C7C
    // 0x80026E94: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    inflateInit2_(rdram, ctx);
        goto after_0;
    // 0x80026E94: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    after_0:
    // 0x80026E98: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80026E9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80026EA0: jr          $ra
    // 0x80026EA4: nop

    return;
    // 0x80026EA4: nop

;}
RECOMP_FUNC void inflate_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026EA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80026EAC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80026EB0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80026EB4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80026EB8: beq         $s0, $zero, L_80027380
    if (ctx->r16 == 0) {
        // 0x80026EBC: sw          $s1, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r17;
            goto L_80027380;
    }
    // 0x80026EBC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80026EC0: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x80026EC4: beq         $v0, $zero, L_80027380
    if (ctx->r2 == 0) {
        // 0x80026EC8: srl         $v1, $a1, 31
        ctx->r3 = S32(U32(ctx->r5) >> 31);
            goto L_80027380;
    }
    // 0x80026EC8: srl         $v1, $a1, 31
    ctx->r3 = S32(U32(ctx->r5) >> 31);
    // 0x80026ECC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80026ED0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80026ED4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80026ED8: bne         $v0, $zero, L_80027384
    if (ctx->r2 != 0) {
        // 0x80026EDC: addiu       $v0, $zero, -0x2
        ctx->r2 = ADD32(0, -0X2);
            goto L_80027384;
    }
    // 0x80026EDC: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // 0x80026EE0: addiu       $s1, $zero, -0x5
    ctx->r17 = ADD32(0, -0X5);
L_80026EE4:
    // 0x80026EE4: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x80026EE8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80026EEC: sltiu       $v0, $v1, 0xE
    ctx->r2 = ctx->r3 < 0XE ? 1 : 0;
    // 0x80026EF0: beq         $v0, $zero, L_80027380
    if (ctx->r2 == 0) {
        // 0x80026EF4: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80027380;
    }
    // 0x80026EF4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80026EF8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80026EFC: addu        $at, $at, $v0
    gpr jr_addend_80026F04 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80026F00: lw          $v0, 0xA70($at)
    ctx->r2 = ADD32(ctx->r1, 0XA70);
    // 0x80026F04: jr          $v0
    // 0x80026F08: nop

    switch (jr_addend_80026F04 >> 2) {
        case 0: goto L_80026F0C; break;
        case 1: goto L_80026F88; break;
        case 2: goto L_8002701C; break;
        case 3: goto L_80027064; break;
        case 4: goto L_800270B8; break;
        case 5: goto L_8002710C; break;
        case 6: goto L_8002716C; break;
        case 7: goto L_80027188; break;
        case 8: goto L_80027204; break;
        case 9: goto L_8002724C; break;
        case 10: goto L_800272A0; break;
        case 11: goto L_800272F4; break;
        case 12: goto L_80027370; break;
        case 13: goto L_80027378; break;
        default: switch_error(__func__, 0x80026F04, 0x80000A70);
    }
    // 0x80026F08: nop

L_80026F0C:
    // 0x80026F0C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80026F10: beq         $v0, $zero, L_80027300
    if (ctx->r2 == 0) {
        // 0x80026F14: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80027300;
    }
    // 0x80026F14: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80026F18: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x80026F1C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80026F20: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x80026F24: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80026F28: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80026F2C: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x80026F30: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80026F34: sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    // 0x80026F38: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80026F3C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x80026F40: andi        $v1, $v1, 0xF
    ctx->r3 = ctx->r3 & 0XF;
    // 0x80026F44: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80026F48: beq         $v1, $v0, L_80026F60
    if (ctx->r3 == ctx->r2) {
        // 0x80026F4C: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80026F60;
    }
    // 0x80026F4C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80026F50: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    // 0x80026F54: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x80026F58: j           L_80027358
    // 0x80026F5C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_80027358;
    // 0x80026F5C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80026F60:
    // 0x80026F60: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80026F64: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80026F68: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x80026F6C: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x80026F70: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80026F74: sltu        $v1, $v1, $v0
    ctx->r3 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80026F78: bne         $v1, $zero, L_80027354
    if (ctx->r3 != 0) {
        // 0x80026F7C: addiu       $v0, $zero, 0xD
        ctx->r2 = ADD32(0, 0XD);
            goto L_80027354;
    }
    // 0x80026F7C: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x80026F80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80026F84: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_80026F88:
    // 0x80026F88: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80026F8C: beq         $v0, $zero, L_80027300
    if (ctx->r2 == 0) {
        // 0x80026F90: lui         $a0, 0x842
        ctx->r4 = S32(0X842 << 16);
            goto L_80027300;
    }
    // 0x80026F90: lui         $a0, 0x842
    ctx->r4 = S32(0X842 << 16);
    // 0x80026F94: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x80026F98: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80026F9C: lw          $a2, 0x1C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C);
    // 0x80026FA0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80026FA4: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x80026FA8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80026FAC: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x80026FB0: sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    // 0x80026FB4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80026FB8: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x80026FBC: lbu         $a1, 0x0($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X0);
    // 0x80026FC0: ori         $a0, $a0, 0x1085
    ctx->r4 = ctx->r4 | 0X1085;
    // 0x80026FC4: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    // 0x80026FC8: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80026FCC: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80026FD0: mfhi        $a0
    ctx->r4 = hi;
    // 0x80026FD4: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    // 0x80026FD8: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x80026FDC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80026FE0: srl         $a0, $a0, 4
    ctx->r4 = S32(U32(ctx->r4) >> 4);
    // 0x80026FE4: sll         $v0, $a0, 5
    ctx->r2 = S32(ctx->r4 << 5);
    // 0x80026FE8: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80026FEC: beq         $v1, $v0, L_80027000
    if (ctx->r3 == ctx->r2) {
        // 0x80026FF0: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80027000;
    }
    // 0x80026FF0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80026FF4: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x80026FF8: j           L_80027358
    // 0x80026FFC: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
        goto L_80027358;
    // 0x80026FFC: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_80027000:
    // 0x80027000: andi        $v0, $a1, 0x20
    ctx->r2 = ctx->r5 & 0X20;
    // 0x80027004: bne         $v0, $zero, L_80027018
    if (ctx->r2 != 0) {
        // 0x80027008: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80027018;
    }
    // 0x80027008: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8002700C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80027010: j           L_80026EE4
    // 0x80027014: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
        goto L_80026EE4;
    // 0x80027014: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_80027018:
    // 0x80027018: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_8002701C:
    // 0x8002701C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80027020: beq         $v0, $zero, L_80027300
    if (ctx->r2 == 0) {
        // 0x80027024: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80027300;
    }
    // 0x80027024: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80027028: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x8002702C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80027030: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x80027034: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80027038: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8002703C: sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    // 0x80027040: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80027044: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80027048: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    // 0x8002704C: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80027050: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x80027054: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    // 0x80027058: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8002705C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80027060: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80027064:
    // 0x80027064: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80027068: beq         $v0, $zero, L_80027300
    if (ctx->r2 == 0) {
        // 0x8002706C: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80027300;
    }
    // 0x8002706C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80027070: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x80027074: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x80027078: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8002707C: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x80027080: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80027084: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80027088: sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    // 0x8002708C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80027090: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80027094: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x80027098: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x8002709C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800270A0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800270A4: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
    // 0x800270A8: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    // 0x800270AC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800270B0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800270B4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800270B8:
    // 0x800270B8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800270BC: beq         $v0, $zero, L_80027300
    if (ctx->r2 == 0) {
        // 0x800270C0: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80027300;
    }
    // 0x800270C0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800270C4: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x800270C8: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x800270CC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800270D0: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x800270D4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800270D8: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x800270DC: sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    // 0x800270E0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800270E4: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800270E8: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x800270EC: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x800270F0: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x800270F4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800270F8: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
    // 0x800270FC: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    // 0x80027100: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80027104: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80027108: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8002710C:
    // 0x8002710C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80027110: beq         $v0, $zero, L_80027300
    if (ctx->r2 == 0) {
        // 0x80027114: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80027300;
    }
    // 0x80027114: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80027118: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x8002711C: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x80027120: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80027124: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x80027128: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002712C: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80027130: sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    // 0x80027134: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80027138: lbu         $a0, 0x0($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X0);
    // 0x8002713C: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x80027140: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    // 0x80027144: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80027148: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8002714C: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x80027150: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80027154: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80027158: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8002715C: sw          $v1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r3;
    // 0x80027160: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x80027164: j           L_80027384
    // 0x80027168: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
        goto L_80027384;
    // 0x80027168: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
L_8002716C:
    // 0x8002716C: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x80027170: addiu       $v1, $zero, 0xD
    ctx->r3 = ADD32(0, 0XD);
    // 0x80027174: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80027178: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    // 0x8002717C: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // 0x80027180: j           L_80027384
    // 0x80027184: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
        goto L_80027384;
    // 0x80027184: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_80027188:
    // 0x80027188: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x8002718C: lw          $a0, 0x14($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X14);
    // 0x80027190: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80027194: jal         0x80027818
    // 0x80027198: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    inflate_blocks(rdram, ctx);
        goto after_0;
    // 0x80027198: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_0:
    // 0x8002719C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800271A0: addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
    // 0x800271A4: bne         $s1, $v0, L_800271C4
    if (ctx->r17 != ctx->r2) {
        // 0x800271A8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800271C4;
    }
    // 0x800271A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800271AC: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x800271B0: addiu       $v1, $zero, 0xD
    ctx->r3 = ADD32(0, 0XD);
    // 0x800271B4: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800271B8: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x800271BC: j           L_80026EE4
    // 0x800271C0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
        goto L_80026EE4;
    // 0x800271C0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
L_800271C4:
    // 0x800271C4: bne         $s1, $v0, L_80027384
    if (ctx->r17 != ctx->r2) {
        // 0x800271C8: addu        $v0, $s1, $zero
        ctx->r2 = ADD32(ctx->r17, 0);
            goto L_80027384;
    }
    // 0x800271C8: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x800271CC: lw          $a2, 0x1C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C);
    // 0x800271D0: lw          $a0, 0x14($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X14);
    // 0x800271D4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800271D8: jal         0x800275F0
    // 0x800271DC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    inflate_blocks_reset(rdram, ctx);
        goto after_1;
    // 0x800271DC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_1:
    // 0x800271E0: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    // 0x800271E4: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800271E8: beq         $v0, $zero, L_800271FC
    if (ctx->r2 == 0) {
        // 0x800271EC: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_800271FC;
    }
    // 0x800271EC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800271F0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x800271F4: j           L_80026EE4
    // 0x800271F8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_80026EE4;
    // 0x800271F8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800271FC:
    // 0x800271FC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80027200: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80027204:
    // 0x80027204: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80027208: beq         $v0, $zero, L_80027300
    if (ctx->r2 == 0) {
        // 0x8002720C: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80027300;
    }
    // 0x8002720C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80027210: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x80027214: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80027218: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8002721C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80027220: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80027224: sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    // 0x80027228: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8002722C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80027230: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    // 0x80027234: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80027238: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8002723C: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    // 0x80027240: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80027244: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80027248: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8002724C:
    // 0x8002724C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80027250: beq         $v0, $zero, L_80027300
    if (ctx->r2 == 0) {
        // 0x80027254: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80027300;
    }
    // 0x80027254: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80027258: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x8002725C: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x80027260: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80027264: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x80027268: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002726C: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80027270: sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    // 0x80027274: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80027278: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8002727C: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x80027280: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80027284: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80027288: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8002728C: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
    // 0x80027290: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    // 0x80027294: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80027298: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8002729C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800272A0:
    // 0x800272A0: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800272A4: beq         $v0, $zero, L_80027300
    if (ctx->r2 == 0) {
        // 0x800272A8: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80027300;
    }
    // 0x800272A8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800272AC: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x800272B0: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x800272B4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800272B8: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x800272BC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800272C0: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x800272C4: sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    // 0x800272C8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800272CC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800272D0: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x800272D4: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x800272D8: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x800272DC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800272E0: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
    // 0x800272E4: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    // 0x800272E8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800272EC: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x800272F0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800272F4:
    // 0x800272F4: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800272F8: bne         $v0, $zero, L_80027308
    if (ctx->r2 != 0) {
        // 0x800272FC: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80027308;
    }
    // 0x800272FC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80027300:
    // 0x80027300: j           L_80027384
    // 0x80027304: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
        goto L_80027384;
    // 0x80027304: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_80027308:
    // 0x80027308: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x8002730C: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x80027310: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80027314: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x80027318: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002731C: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80027320: sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    // 0x80027324: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80027328: lbu         $a0, 0x0($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X0);
    // 0x8002732C: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x80027330: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    // 0x80027334: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80027338: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8002733C: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80027340: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x80027344: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80027348: beq         $v1, $v0, L_80027368
    if (ctx->r3 == ctx->r2) {
        // 0x8002734C: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80027368;
    }
    // 0x8002734C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80027350: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_80027354:
    // 0x80027354: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_80027358:
    // 0x80027358: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    // 0x8002735C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80027360: j           L_80026EE4
    // 0x80027364: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
        goto L_80026EE4;
    // 0x80027364: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80027368:
    // 0x80027368: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x8002736C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_80027370:
    // 0x80027370: j           L_80027384
    // 0x80027374: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80027384;
    // 0x80027374: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80027378:
    // 0x80027378: j           L_80027384
    // 0x8002737C: addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
        goto L_80027384;
    // 0x8002737C: addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
L_80027380:
    // 0x80027380: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_80027384:
    // 0x80027384: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80027388: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8002738C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80027390: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80027394: jr          $ra
    // 0x80027398: nop

    return;
    // 0x80027398: nop

;}
RECOMP_FUNC void inflateSetDictionary(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002739C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800273A0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800273A4: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800273A8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800273AC: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x800273B0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800273B4: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x800273B8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800273BC: addu        $s3, $s0, $zero
    ctx->r19 = ADD32(ctx->r16, 0);
    // 0x800273C0: beq         $s1, $zero, L_800273E0
    if (ctx->r17 == 0) {
        // 0x800273C4: sw          $ra, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r31;
            goto L_800273E0;
    }
    // 0x800273C4: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800273C8: lw          $v1, 0x1C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1C);
    // 0x800273CC: beq         $v1, $zero, L_800273E0
    if (ctx->r3 == 0) {
        // 0x800273D0: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_800273E0;
    }
    // 0x800273D0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800273D4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800273D8: beq         $v1, $v0, L_800273E8
    if (ctx->r3 == ctx->r2) {
        // 0x800273DC: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800273E8;
    }
    // 0x800273DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800273E0:
    // 0x800273E0: j           L_80027448
    // 0x800273E4: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
        goto L_80027448;
    // 0x800273E4: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_800273E8:
    // 0x800273E8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800273EC: jal         0x800269B0
    // 0x800273F0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    adler32(rdram, ctx);
        goto after_0;
    // 0x800273F0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_0:
    // 0x800273F4: lw          $v1, 0x30($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X30);
    // 0x800273F8: bne         $v0, $v1, L_80027448
    if (ctx->r2 != ctx->r3) {
        // 0x800273FC: addiu       $v0, $zero, -0x3
        ctx->r2 = ADD32(0, -0X3);
            goto L_80027448;
    }
    // 0x800273FC: addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
    // 0x80027400: lw          $a0, 0x1C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X1C);
    // 0x80027404: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80027408: sw          $a1, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r5;
    // 0x8002740C: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x80027410: srlv        $v0, $s0, $v1
    ctx->r2 = S32(U32(ctx->r16) >> (ctx->r3 & 31));
    // 0x80027414: beq         $v0, $zero, L_80027428
    if (ctx->r2 == 0) {
        // 0x80027418: sllv        $v0, $a1, $v1
        ctx->r2 = S32(ctx->r5 << (ctx->r3 & 31));
            goto L_80027428;
    }
    // 0x80027418: sllv        $v0, $a1, $v1
    ctx->r2 = S32(ctx->r5 << (ctx->r3 & 31));
    // 0x8002741C: addiu       $s0, $v0, -0x1
    ctx->r16 = ADD32(ctx->r2, -0X1);
    // 0x80027420: subu        $v0, $s3, $s0
    ctx->r2 = SUB32(ctx->r19, ctx->r16);
    // 0x80027424: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
L_80027428:
    // 0x80027428: lw          $a0, 0x14($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14);
    // 0x8002742C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80027430: jal         0x800284D4
    // 0x80027434: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    inflate_set_dictionary(rdram, ctx);
        goto after_1;
    // 0x80027434: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80027438: lw          $a0, 0x1C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X1C);
    // 0x8002743C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80027440: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // 0x80027444: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
L_80027448:
    // 0x80027448: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8002744C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80027450: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80027454: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80027458: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002745C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80027460: jr          $ra
    // 0x80027464: nop

    return;
    // 0x80027464: nop

;}
RECOMP_FUNC void inflateSync(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027468: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002746C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80027470: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80027474: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80027478: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002747C: beq         $s0, $zero, L_80027490
    if (ctx->r16 == 0) {
        // 0x80027480: sw          $s1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r17;
            goto L_80027490;
    }
    // 0x80027480: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80027484: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    // 0x80027488: bne         $v1, $zero, L_80027498
    if (ctx->r3 != 0) {
        // 0x8002748C: addiu       $a0, $zero, 0xD
        ctx->r4 = ADD32(0, 0XD);
            goto L_80027498;
    }
    // 0x8002748C: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
L_80027490:
    // 0x80027490: j           L_800275D4
    // 0x80027494: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
        goto L_800275D4;
    // 0x80027494: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_80027498:
    // 0x80027498: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002749C: beq         $v0, $a0, L_800274B0
    if (ctx->r2 == ctx->r4) {
        // 0x800274A0: nop
    
            goto L_800274B0;
    }
    // 0x800274A0: nop

    // 0x800274A4: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x800274A8: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x800274AC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
L_800274B0:
    // 0x800274B0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800274B4: beq         $a0, $zero, L_800275D4
    if (ctx->r4 == 0) {
        // 0x800274B8: addiu       $v0, $zero, -0x5
        ctx->r2 = ADD32(0, -0X5);
            goto L_800275D4;
    }
    // 0x800274B8: addiu       $v0, $zero, -0x5
    ctx->r2 = ADD32(0, -0X5);
    // 0x800274BC: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x800274C0: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x800274C4: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x800274C8: sltu        $v0, $zero, $a0
    ctx->r2 = 0 < ctx->r4 ? 1 : 0;
    // 0x800274CC: sltiu       $v1, $a1, 0x4
    ctx->r3 = ctx->r5 < 0X4 ? 1 : 0;
    // 0x800274D0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800274D4: beq         $v0, $zero, L_8002753C
    if (ctx->r2 == 0) {
        // 0x800274D8: nop
    
            goto L_8002753C;
    }
    // 0x800274D8: nop

    // 0x800274DC: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800274E0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
L_800274E4:
    // 0x800274E4: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
    // 0x800274E8: sltiu       $v0, $a1, 0x2
    ctx->r2 = ctx->r5 < 0X2 ? 1 : 0;
    // 0x800274EC: bne         $v0, $zero, L_80027504
    if (ctx->r2 != 0) {
        // 0x800274F0: nop
    
            goto L_80027504;
    }
    // 0x800274F0: nop

    // 0x800274F4: beql        $v1, $t0, L_80027524
    if (ctx->r3 == ctx->r8) {
        // 0x800274F8: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80027524;
    }
    goto skip_0;
    // 0x800274F8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_0:
    // 0x800274FC: j           L_80027514
    // 0x80027500: nop

        goto L_80027514;
    // 0x80027500: nop

L_80027504:
    // 0x80027504: bne         $v1, $zero, L_80027514
    if (ctx->r3 != 0) {
        // 0x80027508: nop
    
            goto L_80027514;
    }
    // 0x80027508: nop

    // 0x8002750C: j           L_80027524
    // 0x80027510: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_80027524;
    // 0x80027510: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80027514:
    // 0x80027514: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x80027518: beq         $v0, $zero, L_80027524
    if (ctx->r2 == 0) {
        // 0x8002751C: subu        $a1, $a3, $a1
        ctx->r5 = SUB32(ctx->r7, ctx->r5);
            goto L_80027524;
    }
    // 0x8002751C: subu        $a1, $a3, $a1
    ctx->r5 = SUB32(ctx->r7, ctx->r5);
    // 0x80027520: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80027524:
    // 0x80027524: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80027528: sltu        $v0, $zero, $a0
    ctx->r2 = 0 < ctx->r4 ? 1 : 0;
    // 0x8002752C: sltiu       $v1, $a1, 0x4
    ctx->r3 = ctx->r5 < 0X4 ? 1 : 0;
    // 0x80027530: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80027534: bne         $v0, $zero, L_800274E4
    if (ctx->r2 != 0) {
        // 0x80027538: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800274E4;
    }
    // 0x80027538: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8002753C:
    // 0x8002753C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80027540: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80027544: sw          $a0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r4;
    // 0x80027548: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x8002754C: sw          $a2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r6;
    // 0x80027550: subu        $v1, $a2, $v1
    ctx->r3 = SUB32(ctx->r6, ctx->r3);
    // 0x80027554: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80027558: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x8002755C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80027560: beq         $a1, $v0, L_80027570
    if (ctx->r5 == ctx->r2) {
        // 0x80027564: sw          $a1, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r5;
            goto L_80027570;
    }
    // 0x80027564: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80027568: j           L_800275D4
    // 0x8002756C: addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
        goto L_800275D4;
    // 0x8002756C: addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
L_80027570:
    // 0x80027570: lw          $s1, 0x8($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X8);
    // 0x80027574: lw          $s2, 0x14($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X14);
    // 0x80027578: beq         $s0, $zero, L_800275BC
    if (ctx->r16 == 0) {
        // 0x8002757C: nop
    
            goto L_800275BC;
    }
    // 0x8002757C: nop

    // 0x80027580: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x80027584: beq         $v0, $zero, L_800275BC
    if (ctx->r2 == 0) {
        // 0x80027588: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_800275BC;
    }
    // 0x80027588: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8002758C: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x80027590: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x80027594: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x80027598: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x8002759C: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x800275A0: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x800275A4: andi        $v1, $v1, 0x7
    ctx->r3 = ctx->r3 & 0X7;
    // 0x800275A8: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800275AC: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x800275B0: lw          $a0, 0x14($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X14);
    // 0x800275B4: jal         0x800275F0
    // 0x800275B8: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    inflate_blocks_reset(rdram, ctx);
        goto after_0;
    // 0x800275B8: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_0:
L_800275BC:
    // 0x800275BC: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x800275C0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800275C4: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // 0x800275C8: sw          $s1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r17;
    // 0x800275CC: sw          $s2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r18;
    // 0x800275D0: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
L_800275D4:
    // 0x800275D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800275D8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800275DC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800275E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800275E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800275E8: jr          $ra
    // 0x800275EC: nop

    return;
    // 0x800275EC: nop

;}
RECOMP_FUNC void inflate_blocks_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800275F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800275F4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800275F8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800275FC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80027600: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80027604: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80027608: beq         $v0, $zero, L_80027618
    if (ctx->r2 == 0) {
        // 0x8002760C: addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
            goto L_80027618;
    }
    // 0x8002760C: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80027610: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x80027614: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_80027618:
    // 0x80027618: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8002761C: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80027620: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80027624: beq         $v0, $zero, L_80027640
    if (ctx->r2 == 0) {
        // 0x80027628: nop
    
            goto L_80027640;
    }
    // 0x80027628: nop

    // 0x8002762C: lw          $a0, 0x28($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X28);
    // 0x80027630: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80027634: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x80027638: jalr        $v0
    // 0x8002763C: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8002763C: nop

    after_0:
L_80027640:
    // 0x80027640: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80027644: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80027648: bne         $v1, $v0, L_80027674
    if (ctx->r3 != ctx->r2) {
        // 0x8002764C: nop
    
            goto L_80027674;
    }
    // 0x8002764C: nop

    // 0x80027650: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80027654: jal         0x80028D2C
    // 0x80027658: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    inflate_codes_free(rdram, ctx);
        goto after_1;
    // 0x80027658: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_1:
    // 0x8002765C: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80027660: jal         0x80029A68
    // 0x80027664: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    inflate_trees_free(rdram, ctx);
        goto after_2;
    // 0x80027664: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_2:
    // 0x80027668: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8002766C: jal         0x80029A68
    // 0x80027670: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    inflate_trees_free(rdram, ctx);
        goto after_3;
    // 0x80027670: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_3:
L_80027674:
    // 0x80027674: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80027678: lw          $v1, 0x34($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X34);
    // 0x8002767C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80027680: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x80027684: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x80027688: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x8002768C: beq         $v1, $zero, L_800276AC
    if (ctx->r3 == 0) {
        // 0x80027690: sw          $v0, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->r2;
            goto L_800276AC;
    }
    // 0x80027690: sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    // 0x80027694: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80027698: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8002769C: jalr        $v1
    // 0x800276A0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_4;
    // 0x800276A0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_4:
    // 0x800276A4: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
    // 0x800276A8: sw          $v0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r2;
L_800276AC:
    // 0x800276AC: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800276B0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800276B4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800276B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800276BC: jr          $ra
    // 0x800276C0: nop

    return;
    // 0x800276C0: nop

;}
RECOMP_FUNC void inflate_blocks_new(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800276C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800276C8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800276CC: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800276D0: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800276D4: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x800276D8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800276DC: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x800276E0: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800276E4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800276E8: lw          $a0, 0x28($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X28);
    // 0x800276EC: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    // 0x800276F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800276F4: jalr        $v0
    // 0x800276F8: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800276F8: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_0:
    // 0x800276FC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80027700: bne         $s0, $zero, L_80027710
    if (ctx->r16 != 0) {
        // 0x80027704: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80027710;
    }
    // 0x80027704: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80027708: j           L_800277F8
    // 0x8002770C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800277F8;
    // 0x8002770C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80027710:
    // 0x80027710: lw          $a0, 0x28($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X28);
    // 0x80027714: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    // 0x80027718: jalr        $v0
    // 0x8002771C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8002771C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_1:
    // 0x80027720: bne         $v0, $zero, L_80027740
    if (ctx->r2 != 0) {
        // 0x80027724: sw          $v0, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r2;
            goto L_80027740;
    }
    // 0x80027724: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x80027728: lw          $a0, 0x28($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X28);
    // 0x8002772C: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x80027730: jalr        $v0
    // 0x80027734: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x80027734: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80027738: j           L_800277F8
    // 0x8002773C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800277F8;
    // 0x8002773C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80027740:
    // 0x80027740: sw          $s3, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r19;
    // 0x80027744: lw          $v1, 0x34($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X34);
    // 0x80027748: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8002774C: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x80027750: beq         $v1, $zero, L_80027760
    if (ctx->r3 == 0) {
        // 0x80027754: sw          $zero, 0x0($s0)
        MEM_W(0X0, ctx->r16) = 0;
            goto L_80027760;
    }
    // 0x80027754: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80027758: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x8002775C: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
L_80027760:
    // 0x80027760: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80027764: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80027768: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8002776C: beq         $v0, $zero, L_80027788
    if (ctx->r2 == 0) {
        // 0x80027770: nop
    
            goto L_80027788;
    }
    // 0x80027770: nop

    // 0x80027774: lw          $a0, 0x28($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X28);
    // 0x80027778: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8002777C: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x80027780: jalr        $v0
    // 0x80027784: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_3;
    // 0x80027784: nop

    after_3:
L_80027788:
    // 0x80027788: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8002778C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80027790: bne         $v1, $v0, L_800277BC
    if (ctx->r3 != ctx->r2) {
        // 0x80027794: nop
    
            goto L_800277BC;
    }
    // 0x80027794: nop

    // 0x80027798: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x8002779C: jal         0x80028D2C
    // 0x800277A0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    inflate_codes_free(rdram, ctx);
        goto after_4;
    // 0x800277A0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_4:
    // 0x800277A4: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x800277A8: jal         0x80029A68
    // 0x800277AC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    inflate_trees_free(rdram, ctx);
        goto after_5;
    // 0x800277AC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_5:
    // 0x800277B0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800277B4: jal         0x80029A68
    // 0x800277B8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    inflate_trees_free(rdram, ctx);
        goto after_6;
    // 0x800277B8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_6:
L_800277BC:
    // 0x800277BC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800277C0: lw          $v1, 0x34($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X34);
    // 0x800277C4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800277C8: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x800277CC: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x800277D0: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x800277D4: beq         $v1, $zero, L_800277F4
    if (ctx->r3 == 0) {
        // 0x800277D8: sw          $v0, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->r2;
            goto L_800277F4;
    }
    // 0x800277D8: sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    // 0x800277DC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800277E0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800277E4: jalr        $v1
    // 0x800277E8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_7;
    // 0x800277E8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_7:
    // 0x800277EC: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
    // 0x800277F0: sw          $v0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r2;
L_800277F4:
    // 0x800277F4: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_800277F8:
    // 0x800277F8: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800277FC: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80027800: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80027804: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80027808: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002780C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80027810: jr          $ra
    // 0x80027814: nop

    return;
    // 0x80027814: nop

;}
RECOMP_FUNC void inflate_blocks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027818: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8002781C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80027820: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80027824: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80027828: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x8002782C: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80027830: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80027834: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80027838: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x8002783C: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80027840: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80027844: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80027848: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8002784C: lw          $s5, 0x0($s4)
    ctx->r21 = MEM_W(ctx->r20, 0X0);
    // 0x80027850: lw          $s6, 0x4($s4)
    ctx->r22 = MEM_W(ctx->r20, 0X4);
    // 0x80027854: lw          $fp, 0x30($s1)
    ctx->r30 = MEM_W(ctx->r17, 0X30);
    // 0x80027858: lw          $v1, 0x2C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X2C);
    // 0x8002785C: lw          $s3, 0x20($s1)
    ctx->r19 = MEM_W(ctx->r17, 0X20);
    // 0x80027860: lw          $s2, 0x1C($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X1C);
    // 0x80027864: sltu        $v0, $fp, $v1
    ctx->r2 = ctx->r30 < ctx->r3 ? 1 : 0;
    // 0x80027868: beq         $v0, $zero, L_8002787C
    if (ctx->r2 == 0) {
        // 0x8002786C: addu        $t0, $a2, $zero
        ctx->r8 = ADD32(ctx->r6, 0);
            goto L_8002787C;
    }
    // 0x8002786C: addu        $t0, $a2, $zero
    ctx->r8 = ADD32(ctx->r6, 0);
    // 0x80027870: subu        $v0, $v1, $fp
    ctx->r2 = SUB32(ctx->r3, ctx->r30);
    // 0x80027874: j           L_80027884
    // 0x80027878: addiu       $s7, $v0, -0x1
    ctx->r23 = ADD32(ctx->r2, -0X1);
        goto L_80027884;
    // 0x80027878: addiu       $s7, $v0, -0x1
    ctx->r23 = ADD32(ctx->r2, -0X1);
L_8002787C:
    // 0x8002787C: lw          $v0, 0x28($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X28);
    // 0x80027880: subu        $s7, $v0, $fp
    ctx->r23 = SUB32(ctx->r2, ctx->r30);
L_80027884:
    // 0x80027884: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80027888: sltiu       $v0, $v1, 0xA
    ctx->r2 = ctx->r3 < 0XA ? 1 : 0;
    // 0x8002788C: beq         $v0, $zero, L_80028368
    if (ctx->r2 == 0) {
        // 0x80027890: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80028368;
    }
    // 0x80027890: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80027894: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80027898: addu        $at, $at, $v0
    gpr jr_addend_800278A0 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8002789C: lw          $v0, 0xAB0($at)
    ctx->r2 = ADD32(ctx->r1, 0XAB0);
    // 0x800278A0: jr          $v0
    // 0x800278A4: nop

    switch (jr_addend_800278A0 >> 2) {
        case 0: goto L_800278C8; break;
        case 1: goto L_80027A00; break;
        case 2: goto L_80027A6C; break;
        case 3: goto L_80027BFC; break;
        case 4: goto L_80027CBC; break;
        case 5: goto L_80027FC0; break;
        case 6: goto L_8002811C; break;
        case 7: goto L_80028200; break;
        case 8: goto L_80028250; break;
        case 9: goto L_80028270; break;
        default: switch_error(__func__, 0x800278A0, 0x80000AB0);
    }
    // 0x800278A4: nop

L_800278A8:
    // 0x800278A8: beq         $s6, $zero, L_80028290
    if (ctx->r22 == 0) {
        // 0x800278AC: addiu       $s6, $s6, -0x1
        ctx->r22 = ADD32(ctx->r22, -0X1);
            goto L_80028290;
    }
    // 0x800278AC: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x800278B0: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x800278B4: lbu         $v0, 0x0($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X0);
    // 0x800278B8: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800278BC: sllv        $v0, $v0, $s2
    ctx->r2 = S32(ctx->r2 << (ctx->r18 & 31));
    // 0x800278C0: or          $s3, $s3, $v0
    ctx->r19 = ctx->r19 | ctx->r2;
    // 0x800278C4: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
L_800278C8:
    // 0x800278C8: sltiu       $v0, $s2, 0x3
    ctx->r2 = ctx->r18 < 0X3 ? 1 : 0;
    // 0x800278CC: bne         $v0, $zero, L_800278A8
    if (ctx->r2 != 0) {
        // 0x800278D0: andi        $s0, $s3, 0x7
        ctx->r16 = ctx->r19 & 0X7;
            goto L_800278A8;
    }
    // 0x800278D0: andi        $s0, $s3, 0x7
    ctx->r16 = ctx->r19 & 0X7;
    // 0x800278D4: andi        $v0, $s3, 0x1
    ctx->r2 = ctx->r19 & 0X1;
    // 0x800278D8: srl         $v1, $s0, 1
    ctx->r3 = S32(U32(ctx->r16) >> 1);
    // 0x800278DC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800278E0: beq         $v1, $t1, L_80027928
    if (ctx->r3 == ctx->r9) {
        // 0x800278E4: sw          $v0, 0x18($s1)
        MEM_W(0X18, ctx->r17) = ctx->r2;
            goto L_80027928;
    }
    // 0x800278E4: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    // 0x800278E8: beq         $v1, $zero, L_80027908
    if (ctx->r3 == 0) {
        // 0x800278EC: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80027908;
    }
    // 0x800278EC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800278F0: beq         $v1, $v0, L_800279A4
    if (ctx->r3 == ctx->r2) {
        // 0x800278F4: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800279A4;
    }
    // 0x800278F4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800278F8: beql        $v1, $v0, L_800279B4
    if (ctx->r3 == ctx->r2) {
        // 0x800278FC: srl         $s3, $s3, 3
        ctx->r19 = S32(U32(ctx->r19) >> 3);
            goto L_800279B4;
    }
    goto skip_0;
    // 0x800278FC: srl         $s3, $s3, 3
    ctx->r19 = S32(U32(ctx->r19) >> 3);
    skip_0:
    // 0x80027900: j           L_80027884
    // 0x80027904: nop

        goto L_80027884;
    // 0x80027904: nop

L_80027908:
    // 0x80027908: srl         $s3, $s3, 3
    ctx->r19 = S32(U32(ctx->r19) >> 3);
    // 0x8002790C: addiu       $s2, $s2, -0x3
    ctx->r18 = ADD32(ctx->r18, -0X3);
    // 0x80027910: andi        $s0, $s2, 0x7
    ctx->r16 = ctx->r18 & 0X7;
    // 0x80027914: srlv        $s3, $s3, $s0
    ctx->r19 = S32(U32(ctx->r19) >> (ctx->r16 & 31));
    // 0x80027918: subu        $s2, $s2, $s0
    ctx->r18 = SUB32(ctx->r18, ctx->r16);
    // 0x8002791C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80027920: j           L_80027884
    // 0x80027924: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
        goto L_80027884;
    // 0x80027924: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
L_80027928:
    // 0x80027928: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8002792C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80027930: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x80027934: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    // 0x80027938: jal         0x80029864
    // 0x8002793C: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    inflate_trees_fixed(rdram, ctx);
        goto after_0;
    // 0x8002793C: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    after_0:
    // 0x80027940: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80027944: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80027948: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8002794C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80027950: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80027954: jal         0x80028520
    // 0x80027958: nop

    inflate_codes_new(rdram, ctx);
        goto after_1;
    // 0x80027958: nop

    after_1:
    // 0x8002795C: sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // 0x80027960: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80027964: bnel        $v0, $zero, L_8002798C
    if (ctx->r2 != 0) {
        // 0x80027968: srl         $s3, $s3, 3
        ctx->r19 = S32(U32(ctx->r19) >> 3);
            goto L_8002798C;
    }
    goto skip_1;
    // 0x80027968: srl         $s3, $s3, 3
    ctx->r19 = S32(U32(ctx->r19) >> 3);
    skip_1:
    // 0x8002796C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80027970: sw          $s3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r19;
    // 0x80027974: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x80027978: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8002797C: lw          $v1, 0x8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X8);
    // 0x80027980: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80027984: j           L_80028384
    // 0x80027988: addiu       $a2, $zero, -0x4
    ctx->r6 = ADD32(0, -0X4);
        goto L_80028384;
    // 0x80027988: addiu       $a2, $zero, -0x4
    ctx->r6 = ADD32(0, -0X4);
L_8002798C:
    // 0x8002798C: addiu       $s2, $s2, -0x3
    ctx->r18 = ADD32(ctx->r18, -0X3);
    // 0x80027990: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80027994: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
    // 0x80027998: sw          $zero, 0x8($s1)
    MEM_W(0X8, ctx->r17) = 0;
    // 0x8002799C: j           L_80027884
    // 0x800279A0: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
        goto L_80027884;
    // 0x800279A0: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
L_800279A4:
    // 0x800279A4: srl         $s3, $s3, 3
    ctx->r19 = S32(U32(ctx->r19) >> 3);
    // 0x800279A8: addiu       $s2, $s2, -0x3
    ctx->r18 = ADD32(ctx->r18, -0X3);
L_800279AC:
    // 0x800279AC: j           L_80027884
    // 0x800279B0: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
        goto L_80027884;
    // 0x800279B0: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_800279B4:
    // 0x800279B4: addiu       $s2, $s2, -0x3
    ctx->r18 = ADD32(ctx->r18, -0X3);
    // 0x800279B8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800279BC: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x800279C0: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x800279C4: sw          $s3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r19;
    // 0x800279C8: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x800279CC: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800279D0: lw          $v1, 0x8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X8);
    // 0x800279D4: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x800279D8: j           L_80028384
    // 0x800279DC: addiu       $a2, $zero, -0x3
    ctx->r6 = ADD32(0, -0X3);
        goto L_80028384;
    // 0x800279DC: addiu       $a2, $zero, -0x3
    ctx->r6 = ADD32(0, -0X3);
L_800279E0:
    // 0x800279E0: beq         $s6, $zero, L_800282B4
    if (ctx->r22 == 0) {
        // 0x800279E4: addiu       $s6, $s6, -0x1
        ctx->r22 = ADD32(ctx->r22, -0X1);
            goto L_800282B4;
    }
    // 0x800279E4: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x800279E8: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x800279EC: lbu         $v0, 0x0($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X0);
    // 0x800279F0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800279F4: sllv        $v0, $v0, $s2
    ctx->r2 = S32(ctx->r2 << (ctx->r18 & 31));
    // 0x800279F8: or          $s3, $s3, $v0
    ctx->r19 = ctx->r19 | ctx->r2;
    // 0x800279FC: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
L_80027A00:
    // 0x80027A00: sltiu       $v0, $s2, 0x20
    ctx->r2 = ctx->r18 < 0X20 ? 1 : 0;
    // 0x80027A04: bne         $v0, $zero, L_800279E0
    if (ctx->r2 != 0) {
        // 0x80027A08: nor         $v0, $zero, $s3
        ctx->r2 = ~(0 | ctx->r19);
            goto L_800279E0;
    }
    // 0x80027A08: nor         $v0, $zero, $s3
    ctx->r2 = ~(0 | ctx->r19);
    // 0x80027A0C: srl         $v1, $v0, 16
    ctx->r3 = S32(U32(ctx->r2) >> 16);
    // 0x80027A10: andi        $v0, $s3, 0xFFFF
    ctx->r2 = ctx->r19 & 0XFFFF;
    // 0x80027A14: beq         $v1, $v0, L_80027A40
    if (ctx->r3 == ctx->r2) {
        // 0x80027A18: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80027A40;
    }
    // 0x80027A18: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80027A1C: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x80027A20: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80027A24: sw          $s3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r19;
    // 0x80027A28: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x80027A2C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80027A30: lw          $v1, 0x8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X8);
    // 0x80027A34: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80027A38: j           L_80028384
    // 0x80027A3C: addiu       $a2, $zero, -0x3
    ctx->r6 = ADD32(0, -0X3);
        goto L_80028384;
    // 0x80027A3C: addiu       $a2, $zero, -0x3
    ctx->r6 = ADD32(0, -0X3);
L_80027A40:
    // 0x80027A40: sw          $v1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r3;
    // 0x80027A44: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80027A48: bne         $v1, $zero, L_80027A64
    if (ctx->r3 != 0) {
        // 0x80027A4C: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_80027A64;
    }
    // 0x80027A4C: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80027A50: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x80027A54: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80027A58: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80027A5C: j           L_800279AC
    // 0x80027A60: andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
        goto L_800279AC;
    // 0x80027A60: andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
L_80027A64:
    // 0x80027A64: j           L_800279AC
    // 0x80027A68: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800279AC;
    // 0x80027A68: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80027A6C:
    // 0x80027A6C: bne         $s6, $zero, L_80027A94
    if (ctx->r22 != 0) {
        // 0x80027A70: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80027A94;
    }
    // 0x80027A70: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80027A74: sw          $s3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r19;
    // 0x80027A78: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x80027A7C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80027A80: lw          $v1, 0x8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X8);
    // 0x80027A84: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80027A88: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    // 0x80027A8C: j           L_80028388
    // 0x80027A90: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
        goto L_80028388;
    // 0x80027A90: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_80027A94:
    // 0x80027A94: bne         $s7, $zero, L_80027B70
    if (ctx->r23 != 0) {
        // 0x80027A98: nop
    
            goto L_80027B70;
    }
    // 0x80027A98: nop

    // 0x80027A9C: lw          $a0, 0x28($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X28);
    // 0x80027AA0: bne         $fp, $a0, L_80027AD4
    if (ctx->r30 != ctx->r4) {
        // 0x80027AA4: nop
    
            goto L_80027AD4;
    }
    // 0x80027AA4: nop

    // 0x80027AA8: lw          $v1, 0x2C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X2C);
    // 0x80027AAC: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x80027AB0: beq         $v1, $v0, L_80027AD4
    if (ctx->r3 == ctx->r2) {
        // 0x80027AB4: nop
    
            goto L_80027AD4;
    }
    // 0x80027AB4: nop

    // 0x80027AB8: addu        $fp, $v0, $zero
    ctx->r30 = ADD32(ctx->r2, 0);
    // 0x80027ABC: sltu        $v0, $fp, $v1
    ctx->r2 = ctx->r30 < ctx->r3 ? 1 : 0;
    // 0x80027AC0: beq         $v0, $zero, L_80027AD0
    if (ctx->r2 == 0) {
        // 0x80027AC4: subu        $v0, $v1, $fp
        ctx->r2 = SUB32(ctx->r3, ctx->r30);
            goto L_80027AD0;
    }
    // 0x80027AC4: subu        $v0, $v1, $fp
    ctx->r2 = SUB32(ctx->r3, ctx->r30);
    // 0x80027AC8: j           L_80027AD4
    // 0x80027ACC: addiu       $s7, $v0, -0x1
    ctx->r23 = ADD32(ctx->r2, -0X1);
        goto L_80027AD4;
    // 0x80027ACC: addiu       $s7, $v0, -0x1
    ctx->r23 = ADD32(ctx->r2, -0X1);
L_80027AD0:
    // 0x80027AD0: subu        $s7, $a0, $fp
    ctx->r23 = SUB32(ctx->r4, ctx->r30);
L_80027AD4:
    // 0x80027AD4: bne         $s7, $zero, L_80027B70
    if (ctx->r23 != 0) {
        // 0x80027AD8: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80027B70;
    }
    // 0x80027AD8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80027ADC: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80027AE0: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    // 0x80027AE4: jal         0x80029B20
    // 0x80027AE8: sw          $fp, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r30;
    inflate_flush(rdram, ctx);
        goto after_2;
    // 0x80027AE8: sw          $fp, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r30;
    after_2:
    // 0x80027AEC: lw          $fp, 0x30($s1)
    ctx->r30 = MEM_W(ctx->r17, 0X30);
    // 0x80027AF0: lw          $v1, 0x2C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X2C);
    // 0x80027AF4: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80027AF8: sltu        $v0, $fp, $v1
    ctx->r2 = ctx->r30 < ctx->r3 ? 1 : 0;
    // 0x80027AFC: beq         $v0, $zero, L_80027B0C
    if (ctx->r2 == 0) {
        // 0x80027B00: subu        $v0, $v1, $fp
        ctx->r2 = SUB32(ctx->r3, ctx->r30);
            goto L_80027B0C;
    }
    // 0x80027B00: subu        $v0, $v1, $fp
    ctx->r2 = SUB32(ctx->r3, ctx->r30);
    // 0x80027B04: j           L_80027B14
    // 0x80027B08: addiu       $s7, $v0, -0x1
    ctx->r23 = ADD32(ctx->r2, -0X1);
        goto L_80027B14;
    // 0x80027B08: addiu       $s7, $v0, -0x1
    ctx->r23 = ADD32(ctx->r2, -0X1);
L_80027B0C:
    // 0x80027B0C: lw          $v0, 0x28($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X28);
    // 0x80027B10: subu        $s7, $v0, $fp
    ctx->r23 = SUB32(ctx->r2, ctx->r30);
L_80027B14:
    // 0x80027B14: lw          $a0, 0x28($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X28);
    // 0x80027B18: bne         $fp, $a0, L_80027B4C
    if (ctx->r30 != ctx->r4) {
        // 0x80027B1C: nop
    
            goto L_80027B4C;
    }
    // 0x80027B1C: nop

    // 0x80027B20: lw          $v1, 0x2C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X2C);
    // 0x80027B24: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x80027B28: beq         $v1, $v0, L_80027B4C
    if (ctx->r3 == ctx->r2) {
        // 0x80027B2C: nop
    
            goto L_80027B4C;
    }
    // 0x80027B2C: nop

    // 0x80027B30: addu        $fp, $v0, $zero
    ctx->r30 = ADD32(ctx->r2, 0);
    // 0x80027B34: sltu        $v0, $fp, $v1
    ctx->r2 = ctx->r30 < ctx->r3 ? 1 : 0;
    // 0x80027B38: beq         $v0, $zero, L_80027B48
    if (ctx->r2 == 0) {
        // 0x80027B3C: subu        $v0, $v1, $fp
        ctx->r2 = SUB32(ctx->r3, ctx->r30);
            goto L_80027B48;
    }
    // 0x80027B3C: subu        $v0, $v1, $fp
    ctx->r2 = SUB32(ctx->r3, ctx->r30);
    // 0x80027B40: j           L_80027B4C
    // 0x80027B44: addiu       $s7, $v0, -0x1
    ctx->r23 = ADD32(ctx->r2, -0X1);
        goto L_80027B4C;
    // 0x80027B44: addiu       $s7, $v0, -0x1
    ctx->r23 = ADD32(ctx->r2, -0X1);
L_80027B48:
    // 0x80027B48: subu        $s7, $a0, $fp
    ctx->r23 = SUB32(ctx->r4, ctx->r30);
L_80027B4C:
    // 0x80027B4C: bne         $s7, $zero, L_80027B70
    if (ctx->r23 != 0) {
        // 0x80027B50: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80027B70;
    }
    // 0x80027B50: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80027B54: sw          $s3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r19;
    // 0x80027B58: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x80027B5C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80027B60: lw          $v1, 0x8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X8);
    // 0x80027B64: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80027B68: j           L_80028384
    // 0x80027B6C: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
        goto L_80028384;
    // 0x80027B6C: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
L_80027B70:
    // 0x80027B70: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x80027B74: sltu        $v0, $s6, $s0
    ctx->r2 = ctx->r22 < ctx->r16 ? 1 : 0;
    // 0x80027B78: beq         $v0, $zero, L_80027B84
    if (ctx->r2 == 0) {
        // 0x80027B7C: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_80027B84;
    }
    // 0x80027B7C: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80027B80: addu        $s0, $s6, $zero
    ctx->r16 = ADD32(ctx->r22, 0);
L_80027B84:
    // 0x80027B84: sltu        $v0, $s7, $s0
    ctx->r2 = ctx->r23 < ctx->r16 ? 1 : 0;
    // 0x80027B88: bnel        $v0, $zero, L_80027B90
    if (ctx->r2 != 0) {
        // 0x80027B8C: addu        $s0, $s7, $zero
        ctx->r16 = ADD32(ctx->r23, 0);
            goto L_80027B90;
    }
    goto skip_2;
    // 0x80027B8C: addu        $s0, $s7, $zero
    ctx->r16 = ADD32(ctx->r23, 0);
    skip_2:
L_80027B90:
    // 0x80027B90: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // 0x80027B94: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x80027B98: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80027B9C: jal         0x80018EF4
    // 0x80027BA0: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    zmemcpy(rdram, ctx);
        goto after_3;
    // 0x80027BA0: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    after_3:
    // 0x80027BA4: addu        $s5, $s5, $s0
    ctx->r21 = ADD32(ctx->r21, ctx->r16);
    // 0x80027BA8: subu        $s6, $s6, $s0
    ctx->r22 = SUB32(ctx->r22, ctx->r16);
    // 0x80027BAC: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x80027BB0: addu        $fp, $fp, $s0
    ctx->r30 = ADD32(ctx->r30, ctx->r16);
    // 0x80027BB4: subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x80027BB8: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x80027BBC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80027BC0: bne         $v0, $zero, L_80027884
    if (ctx->r2 != 0) {
        // 0x80027BC4: subu        $s7, $s7, $s0
        ctx->r23 = SUB32(ctx->r23, ctx->r16);
            goto L_80027884;
    }
    // 0x80027BC4: subu        $s7, $s7, $s0
    ctx->r23 = SUB32(ctx->r23, ctx->r16);
    // 0x80027BC8: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x80027BCC: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80027BD0: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80027BD4: j           L_800279AC
    // 0x80027BD8: andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
        goto L_800279AC;
    // 0x80027BD8: andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
L_80027BDC:
    // 0x80027BDC: beq         $s6, $zero, L_800282D8
    if (ctx->r22 == 0) {
        // 0x80027BE0: addiu       $s6, $s6, -0x1
        ctx->r22 = ADD32(ctx->r22, -0X1);
            goto L_800282D8;
    }
    // 0x80027BE0: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x80027BE4: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80027BE8: lbu         $v0, 0x0($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X0);
    // 0x80027BEC: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80027BF0: sllv        $v0, $v0, $s2
    ctx->r2 = S32(ctx->r2 << (ctx->r18 & 31));
    // 0x80027BF4: or          $s3, $s3, $v0
    ctx->r19 = ctx->r19 | ctx->r2;
    // 0x80027BF8: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
L_80027BFC:
    // 0x80027BFC: sltiu       $v0, $s2, 0xE
    ctx->r2 = ctx->r18 < 0XE ? 1 : 0;
    // 0x80027C00: bne         $v0, $zero, L_80027BDC
    if (ctx->r2 != 0) {
        // 0x80027C04: andi        $s0, $s3, 0x3FFF
        ctx->r16 = ctx->r19 & 0X3FFF;
            goto L_80027BDC;
    }
    // 0x80027C04: andi        $s0, $s3, 0x3FFF
    ctx->r16 = ctx->r19 & 0X3FFF;
    // 0x80027C08: andi        $a0, $s3, 0x1F
    ctx->r4 = ctx->r19 & 0X1F;
    // 0x80027C0C: sltiu       $v0, $a0, 0x1E
    ctx->r2 = ctx->r4 < 0X1E ? 1 : 0;
    // 0x80027C10: beq         $v0, $zero, L_80027C2C
    if (ctx->r2 == 0) {
        // 0x80027C14: sw          $s0, 0x4($s1)
        MEM_W(0X4, ctx->r17) = ctx->r16;
            goto L_80027C2C;
    }
    // 0x80027C14: sw          $s0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r16;
    // 0x80027C18: srl         $v0, $s0, 5
    ctx->r2 = S32(U32(ctx->r16) >> 5);
    // 0x80027C1C: andi        $v1, $v0, 0x1F
    ctx->r3 = ctx->r2 & 0X1F;
    // 0x80027C20: sltiu       $v0, $v1, 0x1E
    ctx->r2 = ctx->r3 < 0X1E ? 1 : 0;
    // 0x80027C24: bne         $v0, $zero, L_80027C54
    if (ctx->r2 != 0) {
        // 0x80027C28: addiu       $v0, $v1, 0x102
        ctx->r2 = ADD32(ctx->r3, 0X102);
            goto L_80027C54;
    }
    // 0x80027C28: addiu       $v0, $v1, 0x102
    ctx->r2 = ADD32(ctx->r3, 0X102);
L_80027C2C:
    // 0x80027C2C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80027C30: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x80027C34: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80027C38: sw          $s3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r19;
    // 0x80027C3C: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x80027C40: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80027C44: lw          $v1, 0x8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X8);
    // 0x80027C48: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80027C4C: j           L_80028384
    // 0x80027C50: addiu       $a2, $zero, -0x3
    ctx->r6 = ADD32(0, -0X3);
        goto L_80028384;
    // 0x80027C50: addiu       $a2, $zero, -0x3
    ctx->r6 = ADD32(0, -0X3);
L_80027C54:
    // 0x80027C54: addu        $s0, $a0, $v0
    ctx->r16 = ADD32(ctx->r4, ctx->r2);
    // 0x80027C58: sltiu       $v0, $s0, 0x13
    ctx->r2 = ctx->r16 < 0X13 ? 1 : 0;
    // 0x80027C5C: bnel        $v0, $zero, L_80027C64
    if (ctx->r2 != 0) {
        // 0x80027C60: addiu       $s0, $zero, 0x13
        ctx->r16 = ADD32(0, 0X13);
            goto L_80027C64;
    }
    goto skip_3;
    // 0x80027C60: addiu       $s0, $zero, 0x13
    ctx->r16 = ADD32(0, 0X13);
    skip_3:
L_80027C64:
    // 0x80027C64: lw          $a0, 0x28($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X28);
    // 0x80027C68: lw          $v0, 0x20($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X20);
    // 0x80027C6C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80027C70: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80027C74: jalr        $v0
    // 0x80027C78: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x80027C78: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    after_4:
    // 0x80027C7C: sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // 0x80027C80: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80027C84: bnel        $v0, $zero, L_80027CAC
    if (ctx->r2 != 0) {
        // 0x80027C88: srl         $s3, $s3, 14
        ctx->r19 = S32(U32(ctx->r19) >> 14);
            goto L_80027CAC;
    }
    goto skip_4;
    // 0x80027C88: srl         $s3, $s3, 14
    ctx->r19 = S32(U32(ctx->r19) >> 14);
    skip_4:
    // 0x80027C8C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80027C90: sw          $s3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r19;
    // 0x80027C94: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x80027C98: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80027C9C: lw          $v1, 0x8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X8);
    // 0x80027CA0: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80027CA4: j           L_80028384
    // 0x80027CA8: addiu       $a2, $zero, -0x4
    ctx->r6 = ADD32(0, -0X4);
        goto L_80028384;
    // 0x80027CA8: addiu       $a2, $zero, -0x4
    ctx->r6 = ADD32(0, -0X4);
L_80027CAC:
    // 0x80027CAC: addiu       $s2, $s2, -0xE
    ctx->r18 = ADD32(ctx->r18, -0XE);
    // 0x80027CB0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80027CB4: sw          $zero, 0x8($s1)
    MEM_W(0X8, ctx->r17) = 0;
    // 0x80027CB8: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_80027CBC:
    // 0x80027CBC: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x80027CC0: j           L_80027D30
    // 0x80027CC4: nop

        goto L_80027D30;
    // 0x80027CC4: nop

L_80027CC8:
    // 0x80027CC8: beq         $s6, $zero, L_800282FC
    if (ctx->r22 == 0) {
        // 0x80027CCC: addiu       $s6, $s6, -0x1
        ctx->r22 = ADD32(ctx->r22, -0X1);
            goto L_800282FC;
    }
    // 0x80027CCC: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x80027CD0: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80027CD4: lbu         $v0, 0x0($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X0);
    // 0x80027CD8: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80027CDC: sllv        $v0, $v0, $s2
    ctx->r2 = S32(ctx->r2 << (ctx->r18 & 31));
    // 0x80027CE0: or          $s3, $s3, $v0
    ctx->r19 = ctx->r19 | ctx->r2;
    // 0x80027CE4: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80027CE8: sltiu       $v0, $s2, 0x3
    ctx->r2 = ctx->r18 < 0X3 ? 1 : 0;
L_80027CEC:
    // 0x80027CEC: bne         $v0, $zero, L_80027CC8
    if (ctx->r2 != 0) {
        // 0x80027CF0: andi        $a0, $s3, 0x7
        ctx->r4 = ctx->r19 & 0X7;
            goto L_80027CC8;
    }
    // 0x80027CF0: andi        $a0, $s3, 0x7
    ctx->r4 = ctx->r19 & 0X7;
    // 0x80027CF4: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x80027CF8: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80027CFC: addiu       $t1, $t1, -0x7200
    ctx->r9 = ADD32(ctx->r9, -0X7200);
    // 0x80027D00: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80027D04: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80027D08: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80027D0C: sw          $v1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r3;
    // 0x80027D10: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80027D14: lw          $v1, 0xC($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XC);
    // 0x80027D18: srl         $s3, $s3, 3
    ctx->r19 = S32(U32(ctx->r19) >> 3);
    // 0x80027D1C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80027D20: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80027D24: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80027D28: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x80027D2C: addiu       $s2, $s2, -0x3
    ctx->r18 = ADD32(ctx->r18, -0X3);
L_80027D30:
    // 0x80027D30: lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X8);
    // 0x80027D34: srl         $v0, $v0, 10
    ctx->r2 = S32(U32(ctx->r2) >> 10);
    // 0x80027D38: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80027D3C: sltu        $v1, $v1, $v0
    ctx->r3 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80027D40: bne         $v1, $zero, L_80027CEC
    if (ctx->r3 != 0) {
        // 0x80027D44: sltiu       $v0, $s2, 0x3
        ctx->r2 = ctx->r18 < 0X3 ? 1 : 0;
            goto L_80027CEC;
    }
    // 0x80027D44: sltiu       $v0, $s2, 0x3
    ctx->r2 = ctx->r18 < 0X3 ? 1 : 0;
    // 0x80027D48: j           L_80027D78
    // 0x80027D4C: nop

        goto L_80027D78;
    // 0x80027D4C: nop

L_80027D50:
    // 0x80027D50: sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    // 0x80027D54: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80027D58: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80027D5C: addiu       $t1, $t1, -0x7200
    ctx->r9 = ADD32(ctx->r9, -0X7200);
    // 0x80027D60: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80027D64: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80027D68: lw          $v1, 0xC($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XC);
    // 0x80027D6C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80027D70: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80027D74: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80027D78:
    // 0x80027D78: lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X8);
    // 0x80027D7C: sltiu       $v0, $v1, 0x13
    ctx->r2 = ctx->r3 < 0X13 ? 1 : 0;
    // 0x80027D80: bne         $v0, $zero, L_80027D50
    if (ctx->r2 != 0) {
        // 0x80027D84: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_80027D50;
    }
    // 0x80027D84: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80027D88: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x80027D8C: addiu       $a1, $s1, 0x10
    ctx->r5 = ADD32(ctx->r17, 0X10);
    // 0x80027D90: addiu       $a2, $s1, 0x14
    ctx->r6 = ADD32(ctx->r17, 0X14);
    // 0x80027D94: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // 0x80027D98: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80027D9C: sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
    // 0x80027DA0: jal         0x800296A0
    // 0x80027DA4: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    inflate_trees_bits(rdram, ctx);
        goto after_5;
    // 0x80027DA4: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    after_5:
    // 0x80027DA8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80027DAC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80027DB0: beq         $s0, $zero, L_80027DE8
    if (ctx->r16 == 0) {
        // 0x80027DB4: addiu       $v0, $zero, -0x3
        ctx->r2 = ADD32(0, -0X3);
            goto L_80027DE8;
    }
    // 0x80027DB4: addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
    // 0x80027DB8: addu        $t0, $s0, $zero
    ctx->r8 = ADD32(ctx->r16, 0);
    // 0x80027DBC: bne         $t0, $v0, L_80027DCC
    if (ctx->r8 != ctx->r2) {
        // 0x80027DC0: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80027DCC;
    }
    // 0x80027DC0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80027DC4: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x80027DC8: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
L_80027DCC:
    // 0x80027DCC: sw          $s3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r19;
    // 0x80027DD0: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x80027DD4: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80027DD8: lw          $v1, 0x8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X8);
    // 0x80027DDC: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80027DE0: j           L_80028384
    // 0x80027DE4: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
        goto L_80028384;
    // 0x80027DE4: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
L_80027DE8:
    // 0x80027DE8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80027DEC: sw          $zero, 0x8($s1)
    MEM_W(0X8, ctx->r17) = 0;
    // 0x80027DF0: j           L_80027FC0
    // 0x80027DF4: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
        goto L_80027FC0;
    // 0x80027DF4: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_80027DF8:
    // 0x80027DF8: lw          $s0, 0x10($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X10);
    // 0x80027DFC: sltu        $v0, $s2, $s0
    ctx->r2 = ctx->r18 < ctx->r16 ? 1 : 0;
    // 0x80027E00: beq         $v0, $zero, L_80027E34
    if (ctx->r2 == 0) {
        // 0x80027E04: sll         $v0, $s0, 2
        ctx->r2 = S32(ctx->r16 << 2);
            goto L_80027E34;
    }
    // 0x80027E04: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
L_80027E08:
    // 0x80027E08: beq         $s6, $zero, L_80028320
    if (ctx->r22 == 0) {
        // 0x80027E0C: addiu       $s6, $s6, -0x1
        ctx->r22 = ADD32(ctx->r22, -0X1);
            goto L_80028320;
    }
    // 0x80027E0C: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x80027E10: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80027E14: lbu         $v0, 0x0($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X0);
    // 0x80027E18: sllv        $v0, $v0, $s2
    ctx->r2 = S32(ctx->r2 << (ctx->r18 & 31));
    // 0x80027E1C: or          $s3, $s3, $v0
    ctx->r19 = ctx->r19 | ctx->r2;
    // 0x80027E20: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80027E24: sltu        $v0, $s2, $s0
    ctx->r2 = ctx->r18 < ctx->r16 ? 1 : 0;
    // 0x80027E28: bne         $v0, $zero, L_80027E08
    if (ctx->r2 != 0) {
        // 0x80027E2C: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_80027E08;
    }
    // 0x80027E2C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80027E30: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
L_80027E34:
    // 0x80027E34: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80027E38: addiu       $t1, $t1, -0x6FC0
    ctx->r9 = ADD32(ctx->r9, -0X6FC0);
    // 0x80027E3C: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80027E40: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80027E44: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x80027E48: and         $v0, $s3, $v0
    ctx->r2 = ctx->r19 & ctx->r2;
    // 0x80027E4C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80027E50: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80027E54: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x80027E58: lbu         $s0, 0x1($v1)
    ctx->r16 = MEM_BU(ctx->r3, 0X1);
    // 0x80027E5C: sltiu       $v0, $a2, 0x10
    ctx->r2 = ctx->r6 < 0X10 ? 1 : 0;
    // 0x80027E60: beq         $v0, $zero, L_80027E90
    if (ctx->r2 == 0) {
        // 0x80027E64: addiu       $v0, $zero, 0x12
        ctx->r2 = ADD32(0, 0X12);
            goto L_80027E90;
    }
    // 0x80027E64: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x80027E68: srlv        $s3, $s3, $s0
    ctx->r19 = S32(U32(ctx->r19) >> (ctx->r16 & 31));
    // 0x80027E6C: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x80027E70: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x80027E74: subu        $s2, $s2, $s0
    ctx->r18 = SUB32(ctx->r18, ctx->r16);
    // 0x80027E78: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80027E7C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80027E80: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80027E84: sw          $v1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r3;
    // 0x80027E88: j           L_80027FC0
    // 0x80027E8C: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
        goto L_80027FC0;
    // 0x80027E8C: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
L_80027E90:
    // 0x80027E90: beq         $a2, $v0, L_80027E9C
    if (ctx->r6 == ctx->r2) {
        // 0x80027E94: addiu       $a1, $zero, 0x7
        ctx->r5 = ADD32(0, 0X7);
            goto L_80027E9C;
    }
    // 0x80027E94: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80027E98: addiu       $a1, $a2, -0xE
    ctx->r5 = ADD32(ctx->r6, -0XE);
L_80027E9C:
    // 0x80027E9C: xori        $v0, $a2, 0x12
    ctx->r2 = ctx->r6 ^ 0X12;
    // 0x80027EA0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80027EA4: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80027EA8: andi        $v0, $v0, 0xB
    ctx->r2 = ctx->r2 & 0XB;
    // 0x80027EAC: ori         $a3, $v0, 0x3
    ctx->r7 = ctx->r2 | 0X3;
    // 0x80027EB0: addu        $v1, $s0, $a1
    ctx->r3 = ADD32(ctx->r16, ctx->r5);
    // 0x80027EB4: sltu        $v0, $s2, $v1
    ctx->r2 = ctx->r18 < ctx->r3 ? 1 : 0;
    // 0x80027EB8: beql        $v0, $zero, L_80027EEC
    if (ctx->r2 == 0) {
        // 0x80027EBC: srlv        $s3, $s3, $s0
        ctx->r19 = S32(U32(ctx->r19) >> (ctx->r16 & 31));
            goto L_80027EEC;
    }
    goto skip_5;
    // 0x80027EBC: srlv        $s3, $s3, $s0
    ctx->r19 = S32(U32(ctx->r19) >> (ctx->r16 & 31));
    skip_5:
L_80027EC0:
    // 0x80027EC0: beq         $s6, $zero, L_80028344
    if (ctx->r22 == 0) {
        // 0x80027EC4: addiu       $s6, $s6, -0x1
        ctx->r22 = ADD32(ctx->r22, -0X1);
            goto L_80028344;
    }
    // 0x80027EC4: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x80027EC8: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80027ECC: lbu         $v0, 0x0($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X0);
    // 0x80027ED0: sllv        $v0, $v0, $s2
    ctx->r2 = S32(ctx->r2 << (ctx->r18 & 31));
    // 0x80027ED4: or          $s3, $s3, $v0
    ctx->r19 = ctx->r19 | ctx->r2;
    // 0x80027ED8: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80027EDC: sltu        $v0, $s2, $v1
    ctx->r2 = ctx->r18 < ctx->r3 ? 1 : 0;
    // 0x80027EE0: bne         $v0, $zero, L_80027EC0
    if (ctx->r2 != 0) {
        // 0x80027EE4: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_80027EC0;
    }
    // 0x80027EE4: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80027EE8: srlv        $s3, $s3, $s0
    ctx->r19 = S32(U32(ctx->r19) >> (ctx->r16 & 31));
L_80027EEC:
    // 0x80027EEC: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80027EF0: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80027EF4: addiu       $t1, $t1, -0x6FC0
    ctx->r9 = ADD32(ctx->r9, -0X6FC0);
    // 0x80027EF8: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80027EFC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80027F00: subu        $s2, $s2, $s0
    ctx->r18 = SUB32(ctx->r18, ctx->r16);
    // 0x80027F04: subu        $s2, $s2, $a1
    ctx->r18 = SUB32(ctx->r18, ctx->r5);
    // 0x80027F08: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x80027F0C: and         $v0, $s3, $v0
    ctx->r2 = ctx->r19 & ctx->r2;
    // 0x80027F10: srlv        $s3, $s3, $a1
    ctx->r19 = S32(U32(ctx->r19) >> (ctx->r5 & 31));
    // 0x80027F14: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x80027F18: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x80027F1C: andi        $v1, $s0, 0x1F
    ctx->r3 = ctx->r16 & 0X1F;
    // 0x80027F20: srl         $v0, $s0, 5
    ctx->r2 = S32(U32(ctx->r16) >> 5);
    // 0x80027F24: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x80027F28: addiu       $v0, $v0, 0x102
    ctx->r2 = ADD32(ctx->r2, 0X102);
    // 0x80027F2C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80027F30: addu        $a0, $a1, $a3
    ctx->r4 = ADD32(ctx->r5, ctx->r7);
    // 0x80027F34: sltu        $v1, $v1, $a0
    ctx->r3 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x80027F38: bne         $v1, $zero, L_80027F58
    if (ctx->r3 != 0) {
        // 0x80027F3C: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80027F58;
    }
    // 0x80027F3C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80027F40: xori        $v0, $a2, 0x10
    ctx->r2 = ctx->r6 ^ 0X10;
    // 0x80027F44: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80027F48: sltiu       $v1, $a1, 0x1
    ctx->r3 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x80027F4C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80027F50: beq         $v0, $zero, L_80027F7C
    if (ctx->r2 == 0) {
        // 0x80027F54: addiu       $v0, $zero, 0x10
        ctx->r2 = ADD32(0, 0X10);
            goto L_80027F7C;
    }
    // 0x80027F54: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_80027F58:
    // 0x80027F58: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x80027F5C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80027F60: sw          $s3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r19;
    // 0x80027F64: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x80027F68: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80027F6C: lw          $v1, 0x8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X8);
    // 0x80027F70: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80027F74: j           L_80028384
    // 0x80027F78: addiu       $a2, $zero, -0x3
    ctx->r6 = ADD32(0, -0X3);
        goto L_80028384;
    // 0x80027F78: addiu       $a2, $zero, -0x3
    ctx->r6 = ADD32(0, -0X3);
L_80027F7C:
    // 0x80027F7C: bne         $a2, $v0, L_80027F9C
    if (ctx->r6 != ctx->r2) {
        // 0x80027F80: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80027F9C;
    }
    // 0x80027F80: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80027F84: lw          $v1, 0xC($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XC);
    // 0x80027F88: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80027F8C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80027F90: lw          $v0, -0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4);
    // 0x80027F94: j           L_80027FA4
    // 0x80027F98: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
        goto L_80027FA4;
    // 0x80027F98: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
L_80027F9C:
    // 0x80027F9C: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
L_80027FA0:
    // 0x80027FA0: lw          $v1, 0xC($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XC);
L_80027FA4:
    // 0x80027FA4: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80027FA8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80027FAC: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x80027FB0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80027FB4: bne         $a3, $zero, L_80027FA0
    if (ctx->r7 != 0) {
        // 0x80027FB8: sw          $a2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r6;
            goto L_80027FA0;
    }
    // 0x80027FB8: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x80027FBC: sw          $a1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r5;
L_80027FC0:
    // 0x80027FC0: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x80027FC4: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x80027FC8: andi        $v0, $s0, 0x1F
    ctx->r2 = ctx->r16 & 0X1F;
    // 0x80027FCC: srl         $v1, $s0, 5
    ctx->r3 = S32(U32(ctx->r16) >> 5);
    // 0x80027FD0: andi        $v1, $v1, 0x1F
    ctx->r3 = ctx->r3 & 0X1F;
    // 0x80027FD4: addiu       $v1, $v1, 0x102
    ctx->r3 = ADD32(ctx->r3, 0X102);
    // 0x80027FD8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80027FDC: sltu        $a0, $a0, $v0
    ctx->r4 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80027FE0: bne         $a0, $zero, L_80027DF8
    if (ctx->r4 != 0) {
        // 0x80027FE4: addu        $a1, $s4, $zero
        ctx->r5 = ADD32(ctx->r20, 0);
            goto L_80027DF8;
    }
    // 0x80027FE4: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80027FE8: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x80027FEC: jal         0x80029A68
    // 0x80027FF0: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    inflate_trees_free(rdram, ctx);
        goto after_6;
    // 0x80027FF0: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    after_6:
    // 0x80027FF4: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x80027FF8: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x80027FFC: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    // 0x80028000: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80028004: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80028008: addiu       $v0, $sp, 0x34
    ctx->r2 = ADD32(ctx->r29, 0X34);
    // 0x8002800C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80028010: addiu       $v0, $sp, 0x38
    ctx->r2 = ADD32(ctx->r29, 0X38);
    // 0x80028014: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80028018: addiu       $v0, $sp, 0x3C
    ctx->r2 = ADD32(ctx->r29, 0X3C);
    // 0x8002801C: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80028020: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80028024: sw          $s4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r20;
    // 0x80028028: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x8002802C: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // 0x80028030: andi        $a0, $s0, 0x1F
    ctx->r4 = ctx->r16 & 0X1F;
    // 0x80028034: addiu       $a0, $a0, 0x101
    ctx->r4 = ADD32(ctx->r4, 0X101);
    // 0x80028038: srl         $a1, $s0, 5
    ctx->r5 = S32(U32(ctx->r16) >> 5);
    // 0x8002803C: andi        $a1, $a1, 0x1F
    ctx->r5 = ctx->r5 & 0X1F;
    // 0x80028040: jal         0x8002971C
    // 0x80028044: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    inflate_trees_dynamic(rdram, ctx);
        goto after_7;
    // 0x80028044: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_7:
    // 0x80028048: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8002804C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80028050: beq         $s0, $zero, L_80028084
    if (ctx->r16 == 0) {
        // 0x80028054: addiu       $v0, $zero, -0x3
        ctx->r2 = ADD32(0, -0X3);
            goto L_80028084;
    }
    // 0x80028054: addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
    // 0x80028058: bne         $s0, $v0, L_80028068
    if (ctx->r16 != ctx->r2) {
        // 0x8002805C: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80028068;
    }
    // 0x8002805C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80028060: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x80028064: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
L_80028068:
    // 0x80028068: sw          $s3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r19;
    // 0x8002806C: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x80028070: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80028074: lw          $v1, 0x8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X8);
    // 0x80028078: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x8002807C: j           L_80028384
    // 0x80028080: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
        goto L_80028384;
    // 0x80028080: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
L_80028084:
    // 0x80028084: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80028088: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8002808C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80028090: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80028094: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80028098: jal         0x80028520
    // 0x8002809C: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    inflate_codes_new(rdram, ctx);
        goto after_8;
    // 0x8002809C: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    after_8:
    // 0x800280A0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800280A4: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800280A8: bne         $s0, $zero, L_800280E8
    if (ctx->r16 != 0) {
        // 0x800280AC: nop
    
            goto L_800280E8;
    }
    // 0x800280AC: nop

    // 0x800280B0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800280B4: jal         0x80029A68
    // 0x800280B8: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    inflate_trees_free(rdram, ctx);
        goto after_9;
    // 0x800280B8: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_9:
    // 0x800280BC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800280C0: jal         0x80029A68
    // 0x800280C4: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    inflate_trees_free(rdram, ctx);
        goto after_10;
    // 0x800280C4: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_10:
    // 0x800280C8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800280CC: sw          $s3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r19;
    // 0x800280D0: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x800280D4: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800280D8: lw          $v1, 0x8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X8);
    // 0x800280DC: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x800280E0: j           L_80028384
    // 0x800280E4: addiu       $a2, $zero, -0x4
    ctx->r6 = ADD32(0, -0X4);
        goto L_80028384;
    // 0x800280E4: addiu       $a2, $zero, -0x4
    ctx->r6 = ADD32(0, -0X4);
L_800280E8:
    // 0x800280E8: lw          $a0, 0x28($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X28);
    // 0x800280EC: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x800280F0: lw          $v0, 0x24($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X24);
    // 0x800280F4: jalr        $v0
    // 0x800280F8: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_11;
    // 0x800280F8: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    after_11:
    // 0x800280FC: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80028100: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80028104: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80028108: sw          $s0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r16;
    // 0x8002810C: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x80028110: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x80028114: sw          $v1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r3;
    // 0x80028118: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
L_8002811C:
    // 0x8002811C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80028120: sw          $s3, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r19;
    // 0x80028124: sw          $s2, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r18;
    // 0x80028128: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8002812C: lw          $v1, 0x8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X8);
    // 0x80028130: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80028134: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    // 0x80028138: sw          $s6, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r22;
    // 0x8002813C: sw          $s5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r21;
    // 0x80028140: subu        $v0, $s5, $v0
    ctx->r2 = SUB32(ctx->r21, ctx->r2);
    // 0x80028144: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80028148: sw          $v1, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r3;
    // 0x8002814C: jal         0x8002859C
    // 0x80028150: sw          $fp, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r30;
    inflate_codes_recomp(rdram, ctx);
        goto after_12;
    // 0x80028150: sw          $fp, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r30;
    after_12:
    // 0x80028154: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80028158: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8002815C: beq         $t0, $t1, L_80028170
    if (ctx->r8 == ctx->r9) {
        // 0x80028160: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80028170;
    }
    // 0x80028160: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80028164: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80028168: j           L_8002839C
    // 0x8002816C: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
        goto L_8002839C;
    // 0x8002816C: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
L_80028170:
    // 0x80028170: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x80028174: jal         0x80028D2C
    // 0x80028178: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    inflate_codes_free(rdram, ctx);
        goto after_13;
    // 0x80028178: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_13:
    // 0x8002817C: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x80028180: jal         0x80029A68
    // 0x80028184: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    inflate_trees_free(rdram, ctx);
        goto after_14;
    // 0x80028184: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_14:
    // 0x80028188: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x8002818C: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80028190: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80028194: jal         0x80029A68
    // 0x80028198: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    inflate_trees_free(rdram, ctx);
        goto after_15;
    // 0x80028198: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    after_15:
    // 0x8002819C: lw          $s5, 0x0($s4)
    ctx->r21 = MEM_W(ctx->r20, 0X0);
    // 0x800281A0: lw          $s6, 0x4($s4)
    ctx->r22 = MEM_W(ctx->r20, 0X4);
    // 0x800281A4: lw          $fp, 0x30($s1)
    ctx->r30 = MEM_W(ctx->r17, 0X30);
    // 0x800281A8: lw          $v1, 0x2C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X2C);
    // 0x800281AC: lw          $s3, 0x20($s1)
    ctx->r19 = MEM_W(ctx->r17, 0X20);
    // 0x800281B0: lw          $s2, 0x1C($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X1C);
    // 0x800281B4: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800281B8: sltu        $v0, $fp, $v1
    ctx->r2 = ctx->r30 < ctx->r3 ? 1 : 0;
    // 0x800281BC: beq         $v0, $zero, L_800281CC
    if (ctx->r2 == 0) {
        // 0x800281C0: subu        $v0, $v1, $fp
        ctx->r2 = SUB32(ctx->r3, ctx->r30);
            goto L_800281CC;
    }
    // 0x800281C0: subu        $v0, $v1, $fp
    ctx->r2 = SUB32(ctx->r3, ctx->r30);
    // 0x800281C4: j           L_800281D4
    // 0x800281C8: addiu       $s7, $v0, -0x1
    ctx->r23 = ADD32(ctx->r2, -0X1);
        goto L_800281D4;
    // 0x800281C8: addiu       $s7, $v0, -0x1
    ctx->r23 = ADD32(ctx->r2, -0X1);
L_800281CC:
    // 0x800281CC: lw          $v0, 0x28($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X28);
    // 0x800281D0: subu        $s7, $v0, $fp
    ctx->r23 = SUB32(ctx->r2, ctx->r30);
L_800281D4:
    // 0x800281D4: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x800281D8: bne         $v0, $zero, L_800281E8
    if (ctx->r2 != 0) {
        // 0x800281DC: sltiu       $v0, $s2, 0x8
        ctx->r2 = ctx->r18 < 0X8 ? 1 : 0;
            goto L_800281E8;
    }
    // 0x800281DC: sltiu       $v0, $s2, 0x8
    ctx->r2 = ctx->r18 < 0X8 ? 1 : 0;
    // 0x800281E0: j           L_80027884
    // 0x800281E4: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
        goto L_80027884;
    // 0x800281E4: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_800281E8:
    // 0x800281E8: bne         $v0, $zero, L_800281FC
    if (ctx->r2 != 0) {
        // 0x800281EC: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_800281FC;
    }
    // 0x800281EC: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800281F0: addiu       $s2, $s2, -0x8
    ctx->r18 = ADD32(ctx->r18, -0X8);
    // 0x800281F4: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800281F8: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
L_800281FC:
    // 0x800281FC: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_80028200:
    // 0x80028200: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80028204: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80028208: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    // 0x8002820C: jal         0x80029B20
    // 0x80028210: sw          $fp, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r30;
    inflate_flush(rdram, ctx);
        goto after_16;
    // 0x80028210: sw          $fp, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r30;
    after_16:
    // 0x80028214: lw          $fp, 0x30($s1)
    ctx->r30 = MEM_W(ctx->r17, 0X30);
    // 0x80028218: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x8002821C: lw          $v1, 0x2C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X2C);
    // 0x80028220: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x80028224: beq         $v1, $v0, L_80028248
    if (ctx->r3 == ctx->r2) {
        // 0x80028228: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80028248;
    }
    // 0x80028228: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8002822C: sw          $s3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r19;
    // 0x80028230: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x80028234: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80028238: lw          $v1, 0x8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X8);
    // 0x8002823C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80028240: j           L_80028384
    // 0x80028244: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
        goto L_80028384;
    // 0x80028244: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
L_80028248:
    // 0x80028248: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8002824C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_80028250:
    // 0x80028250: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80028254: sw          $s3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r19;
    // 0x80028258: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x8002825C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80028260: lw          $v1, 0x8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X8);
    // 0x80028264: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80028268: j           L_80028384
    // 0x8002826C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80028384;
    // 0x8002826C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80028270:
    // 0x80028270: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80028274: sw          $s3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r19;
    // 0x80028278: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x8002827C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80028280: lw          $v1, 0x8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X8);
    // 0x80028284: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80028288: j           L_80028384
    // 0x8002828C: addiu       $a2, $zero, -0x3
    ctx->r6 = ADD32(0, -0X3);
        goto L_80028384;
    // 0x8002828C: addiu       $a2, $zero, -0x3
    ctx->r6 = ADD32(0, -0X3);
L_80028290:
    // 0x80028290: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80028294: sw          $s3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r19;
    // 0x80028298: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x8002829C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800282A0: lw          $v1, 0x8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X8);
    // 0x800282A4: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x800282A8: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    // 0x800282AC: j           L_80028388
    // 0x800282B0: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
        goto L_80028388;
    // 0x800282B0: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_800282B4:
    // 0x800282B4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800282B8: sw          $s3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r19;
    // 0x800282BC: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x800282C0: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800282C4: lw          $v1, 0x8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X8);
    // 0x800282C8: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x800282CC: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    // 0x800282D0: j           L_80028388
    // 0x800282D4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
        goto L_80028388;
    // 0x800282D4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_800282D8:
    // 0x800282D8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800282DC: sw          $s3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r19;
    // 0x800282E0: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x800282E4: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800282E8: lw          $v1, 0x8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X8);
    // 0x800282EC: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x800282F0: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    // 0x800282F4: j           L_80028388
    // 0x800282F8: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
        goto L_80028388;
    // 0x800282F8: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_800282FC:
    // 0x800282FC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80028300: sw          $s3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r19;
    // 0x80028304: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x80028308: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8002830C: lw          $v1, 0x8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X8);
    // 0x80028310: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80028314: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    // 0x80028318: j           L_80028388
    // 0x8002831C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
        goto L_80028388;
    // 0x8002831C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_80028320:
    // 0x80028320: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80028324: sw          $s3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r19;
    // 0x80028328: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x8002832C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80028330: lw          $v1, 0x8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X8);
    // 0x80028334: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80028338: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    // 0x8002833C: j           L_80028388
    // 0x80028340: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
        goto L_80028388;
    // 0x80028340: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_80028344:
    // 0x80028344: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80028348: sw          $s3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r19;
    // 0x8002834C: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x80028350: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80028354: lw          $v1, 0x8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X8);
    // 0x80028358: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x8002835C: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    // 0x80028360: j           L_80028388
    // 0x80028364: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
        goto L_80028388;
    // 0x80028364: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_80028368:
    // 0x80028368: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8002836C: sw          $s3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r19;
    // 0x80028370: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x80028374: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80028378: lw          $v1, 0x8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X8);
    // 0x8002837C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80028380: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
L_80028384:
    // 0x80028384: sw          $s6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r22;
L_80028388:
    // 0x80028388: sw          $s5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r21;
    // 0x8002838C: subu        $v0, $s5, $v0
    ctx->r2 = SUB32(ctx->r21, ctx->r2);
    // 0x80028390: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80028394: sw          $v1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r3;
    // 0x80028398: sw          $fp, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r30;
L_8002839C:
    // 0x8002839C: jal         0x80029B20
    // 0x800283A0: nop

    inflate_flush(rdram, ctx);
        goto after_17;
    // 0x800283A0: nop

    after_17:
    // 0x800283A4: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x800283A8: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x800283AC: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x800283B0: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x800283B4: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x800283B8: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800283BC: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800283C0: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800283C4: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800283C8: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800283CC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x800283D0: jr          $ra
    // 0x800283D4: nop

    return;
    // 0x800283D4: nop

;}
RECOMP_FUNC void inflate_blocks_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800283D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800283DC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800283E0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800283E4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800283E8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800283EC: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x800283F0: beq         $v0, $zero, L_80028400
    if (ctx->r2 == 0) {
        // 0x800283F4: addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
            goto L_80028400;
    }
    // 0x800283F4: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800283F8: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x800283FC: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_80028400:
    // 0x80028400: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80028404: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80028408: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8002840C: beq         $v0, $zero, L_80028428
    if (ctx->r2 == 0) {
        // 0x80028410: nop
    
            goto L_80028428;
    }
    // 0x80028410: nop

    // 0x80028414: lw          $a0, 0x28($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X28);
    // 0x80028418: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8002841C: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x80028420: jalr        $v0
    // 0x80028424: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80028424: nop

    after_0:
L_80028428:
    // 0x80028428: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8002842C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80028430: bne         $v1, $v0, L_8002845C
    if (ctx->r3 != ctx->r2) {
        // 0x80028434: nop
    
            goto L_8002845C;
    }
    // 0x80028434: nop

    // 0x80028438: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x8002843C: jal         0x80028D2C
    // 0x80028440: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    inflate_codes_free(rdram, ctx);
        goto after_1;
    // 0x80028440: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_1:
    // 0x80028444: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80028448: jal         0x80029A68
    // 0x8002844C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    inflate_trees_free(rdram, ctx);
        goto after_2;
    // 0x8002844C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_2:
    // 0x80028450: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80028454: jal         0x80029A68
    // 0x80028458: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    inflate_trees_free(rdram, ctx);
        goto after_3;
    // 0x80028458: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_3:
L_8002845C:
    // 0x8002845C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80028460: lw          $v1, 0x34($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X34);
    // 0x80028464: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80028468: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x8002846C: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x80028470: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x80028474: beq         $v1, $zero, L_80028494
    if (ctx->r3 == 0) {
        // 0x80028478: sw          $v0, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->r2;
            goto L_80028494;
    }
    // 0x80028478: sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    // 0x8002847C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80028480: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80028484: jalr        $v1
    // 0x80028488: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_4;
    // 0x80028488: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_4:
    // 0x8002848C: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
    // 0x80028490: sw          $v0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r2;
L_80028494:
    // 0x80028494: lw          $a0, 0x28($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X28);
    // 0x80028498: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    // 0x8002849C: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x800284A0: jalr        $v0
    // 0x800284A4: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_5;
    // 0x800284A4: nop

    after_5:
    // 0x800284A8: lw          $a0, 0x28($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X28);
    // 0x800284AC: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x800284B0: jalr        $v0
    // 0x800284B4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x800284B4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_6:
    // 0x800284B8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800284BC: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800284C0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800284C4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800284C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800284CC: jr          $ra
    // 0x800284D0: nop

    return;
    // 0x800284D0: nop

;}
RECOMP_FUNC void inflate_set_dictionary(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800284D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800284D8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800284DC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800284E0: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800284E4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800284E8: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x800284EC: jal         0x80018EF4
    // 0x800284F0: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    zmemcpy(rdram, ctx);
        goto after_0;
    // 0x800284F0: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    after_0:
    // 0x800284F4: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800284F8: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x800284FC: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x80028500: sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    // 0x80028504: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80028508: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8002850C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80028510: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80028514: jr          $ra
    // 0x80028518: nop

    return;
    // 0x80028518: nop

;}
RECOMP_FUNC void fake_func_8002851C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002851C: lwc1        $f4, 0x18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X18);
;}
RECOMP_FUNC void inflate_codes_new(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028520: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80028524: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80028528: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002852C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80028530: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80028534: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80028538: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8002853C: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x80028540: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80028544: addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // 0x80028548: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8002854C: lw          $v1, 0x20($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X20);
    // 0x80028550: lw          $a0, 0x28($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X28);
    // 0x80028554: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80028558: jalr        $v1
    // 0x8002855C: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8002855C: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    after_0:
    // 0x80028560: beq         $v0, $zero, L_8002857C
    if (ctx->r2 == 0) {
        // 0x80028564: nop
    
            goto L_8002857C;
    }
    // 0x80028564: nop

    // 0x80028568: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8002856C: sb          $s0, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r16;
    // 0x80028570: sb          $s1, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r17;
    // 0x80028574: sw          $s2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r18;
    // 0x80028578: sw          $s3, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r19;
L_8002857C:
    // 0x8002857C: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80028580: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80028584: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80028588: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8002858C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80028590: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80028594: jr          $ra
    // 0x80028598: nop

    return;
    // 0x80028598: nop

;}
RECOMP_FUNC void inflate_codes_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002859C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800285A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800285A4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800285A8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800285AC: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x800285B0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800285B4: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800285B8: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800285BC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800285C0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800285C4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800285C8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800285CC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800285D0: lw          $s6, 0x0($s3)
    ctx->r22 = MEM_W(ctx->r19, 0X0);
    // 0x800285D4: lw          $s7, 0x4($s3)
    ctx->r23 = MEM_W(ctx->r19, 0X4);
    // 0x800285D8: lw          $s4, 0x20($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X20);
    // 0x800285DC: lw          $t0, 0x30($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X30);
    // 0x800285E0: lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C);
    // 0x800285E4: lw          $s2, 0x1C($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X1C);
    // 0x800285E8: lw          $s1, 0xC($s0)
    ctx->r17 = MEM_W(ctx->r16, 0XC);
    // 0x800285EC: sltu        $v0, $t0, $v1
    ctx->r2 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800285F0: beq         $v0, $zero, L_80028600
    if (ctx->r2 == 0) {
        // 0x800285F4: subu        $v0, $v1, $t0
        ctx->r2 = SUB32(ctx->r3, ctx->r8);
            goto L_80028600;
    }
    // 0x800285F4: subu        $v0, $v1, $t0
    ctx->r2 = SUB32(ctx->r3, ctx->r8);
    // 0x800285F8: j           L_80028608
    // 0x800285FC: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
        goto L_80028608;
    // 0x800285FC: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
L_80028600:
    // 0x80028600: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x80028604: subu        $t1, $v0, $t0
    ctx->r9 = SUB32(ctx->r2, ctx->r8);
L_80028608:
    // 0x80028608: lui         $fp, 0x8004
    ctx->r30 = S32(0X8004 << 16);
    // 0x8002860C: addiu       $fp, $fp, -0x6FC0
    ctx->r30 = ADD32(ctx->r30, -0X6FC0);
L_80028610:
    // 0x80028610: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80028614: sltiu       $v0, $v1, 0xA
    ctx->r2 = ctx->r3 < 0XA ? 1 : 0;
    // 0x80028618: beq         $v0, $zero, L_80028CC0
    if (ctx->r2 == 0) {
        // 0x8002861C: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80028CC0;
    }
    // 0x8002861C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80028620: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80028624: addu        $at, $at, $v0
    gpr jr_addend_8002862C = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80028628: lw          $v0, 0xAE0($at)
    ctx->r2 = ADD32(ctx->r1, 0XAE0);
    // 0x8002862C: jr          $v0
    // 0x80028630: nop

    switch (jr_addend_8002862C >> 2) {
        case 0: goto L_80028634; break;
        case 1: goto L_80028700; break;
        case 2: goto L_800287E4; break;
        case 3: goto L_80028858; break;
        case 4: goto L_80028920; break;
        case 5: goto L_80028984; break;
        case 6: goto L_80028AB0; break;
        case 7: goto L_80028BA0; break;
        case 8: goto L_80028BE8; break;
        case 9: goto L_80028C08; break;
        default: switch_error(__func__, 0x8002862C, 0x80000AE0);
    }
    // 0x80028630: nop

L_80028634:
    // 0x80028634: sltiu       $v1, $t1, 0x102
    ctx->r3 = ctx->r9 < 0X102 ? 1 : 0;
    // 0x80028638: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x8002863C: sltiu       $v0, $s7, 0xA
    ctx->r2 = ctx->r23 < 0XA ? 1 : 0;
    // 0x80028640: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80028644: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80028648: beq         $v1, $zero, L_800286E8
    if (ctx->r3 == 0) {
        // 0x8002864C: nop
    
            goto L_800286E8;
    }
    // 0x8002864C: nop

    // 0x80028650: sw          $s4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r20;
    // 0x80028654: sw          $s2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r18;
    // 0x80028658: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8002865C: lw          $v1, 0x8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X8);
    // 0x80028660: sw          $s7, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r23;
    // 0x80028664: sw          $s6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r22;
    // 0x80028668: subu        $v0, $s6, $v0
    ctx->r2 = SUB32(ctx->r22, ctx->r2);
    // 0x8002866C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80028670: sw          $v1, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r3;
    // 0x80028674: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    // 0x80028678: lbu         $a0, 0x10($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X10);
    // 0x8002867C: lbu         $a1, 0x11($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X11);
    // 0x80028680: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80028684: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80028688: lw          $a2, 0x14($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X14);
    // 0x8002868C: lw          $a3, 0x18($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X18);
    // 0x80028690: jal         0x80028D60
    // 0x80028694: nop

    inflate_fast(rdram, ctx);
        goto after_0;
    // 0x80028694: nop

    after_0:
    // 0x80028698: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8002869C: lw          $s6, 0x0($s3)
    ctx->r22 = MEM_W(ctx->r19, 0X0);
    // 0x800286A0: lw          $s7, 0x4($s3)
    ctx->r23 = MEM_W(ctx->r19, 0X4);
    // 0x800286A4: lw          $t0, 0x30($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X30);
    // 0x800286A8: lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C);
    // 0x800286AC: lw          $s4, 0x20($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X20);
    // 0x800286B0: lw          $s2, 0x1C($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X1C);
    // 0x800286B4: sltu        $v0, $t0, $v1
    ctx->r2 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800286B8: beq         $v0, $zero, L_800286C8
    if (ctx->r2 == 0) {
        // 0x800286BC: subu        $v0, $v1, $t0
        ctx->r2 = SUB32(ctx->r3, ctx->r8);
            goto L_800286C8;
    }
    // 0x800286BC: subu        $v0, $v1, $t0
    ctx->r2 = SUB32(ctx->r3, ctx->r8);
    // 0x800286C0: j           L_800286D0
    // 0x800286C4: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
        goto L_800286D0;
    // 0x800286C4: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
L_800286C8:
    // 0x800286C8: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x800286CC: subu        $t1, $v0, $t0
    ctx->r9 = SUB32(ctx->r2, ctx->r8);
L_800286D0:
    // 0x800286D0: beq         $a2, $zero, L_800286E8
    if (ctx->r6 == 0) {
        // 0x800286D4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800286E8;
    }
    // 0x800286D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800286D8: beq         $a2, $v0, L_800287B4
    if (ctx->r6 == ctx->r2) {
        // 0x800286DC: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_800287B4;
    }
    // 0x800286DC: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x800286E0: j           L_80028610
    // 0x800286E4: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
        goto L_80028610;
    // 0x800286E4: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_800286E8:
    // 0x800286E8: lbu         $v0, 0x10($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X10);
    // 0x800286EC: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x800286F0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800286F4: sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    // 0x800286F8: sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // 0x800286FC: sw          $a0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r4;
L_80028700:
    // 0x80028700: lw          $a3, 0xC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XC);
    // 0x80028704: sltu        $v0, $s2, $a3
    ctx->r2 = ctx->r18 < ctx->r7 ? 1 : 0;
    // 0x80028708: beq         $v0, $zero, L_8002873C
    if (ctx->r2 == 0) {
        // 0x8002870C: sll         $v0, $a3, 2
        ctx->r2 = S32(ctx->r7 << 2);
            goto L_8002873C;
    }
    // 0x8002870C: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
L_80028710:
    // 0x80028710: beq         $s7, $zero, L_80028C28
    if (ctx->r23 == 0) {
        // 0x80028714: addiu       $s7, $s7, -0x1
        ctx->r23 = ADD32(ctx->r23, -0X1);
            goto L_80028C28;
    }
    // 0x80028714: addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
    // 0x80028718: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8002871C: lbu         $v0, 0x0($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X0);
    // 0x80028720: sllv        $v0, $v0, $s2
    ctx->r2 = S32(ctx->r2 << (ctx->r18 & 31));
    // 0x80028724: or          $s4, $s4, $v0
    ctx->r20 = ctx->r20 | ctx->r2;
    // 0x80028728: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x8002872C: sltu        $v0, $s2, $a3
    ctx->r2 = ctx->r18 < ctx->r7 ? 1 : 0;
    // 0x80028730: bne         $v0, $zero, L_80028710
    if (ctx->r2 != 0) {
        // 0x80028734: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_80028710;
    }
    // 0x80028734: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80028738: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
L_8002873C:
    // 0x8002873C: addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // 0x80028740: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80028744: lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X8);
    // 0x80028748: and         $v0, $s4, $v0
    ctx->r2 = ctx->r20 & ctx->r2;
    // 0x8002874C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80028750: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80028754: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x80028758: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x8002875C: srlv        $s4, $s4, $v0
    ctx->r20 = S32(U32(ctx->r20) >> (ctx->r2 & 31));
    // 0x80028760: bne         $a0, $zero, L_8002877C
    if (ctx->r4 != 0) {
        // 0x80028764: subu        $s2, $s2, $v0
        ctx->r18 = SUB32(ctx->r18, ctx->r2);
            goto L_8002877C;
    }
    // 0x80028764: subu        $s2, $s2, $v0
    ctx->r18 = SUB32(ctx->r18, ctx->r2);
    // 0x80028768: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x8002876C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80028770: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80028774: j           L_80028610
    // 0x80028778: sw          $v1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r3;
        goto L_80028610;
    // 0x80028778: sw          $v1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r3;
L_8002877C:
    // 0x8002877C: andi        $v0, $a0, 0x10
    ctx->r2 = ctx->r4 & 0X10;
    // 0x80028780: beq         $v0, $zero, L_800287A0
    if (ctx->r2 == 0) {
        // 0x80028784: andi        $v0, $a0, 0xF
        ctx->r2 = ctx->r4 & 0XF;
            goto L_800287A0;
    }
    // 0x80028784: andi        $v0, $a0, 0xF
    ctx->r2 = ctx->r4 & 0XF;
    // 0x80028788: sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    // 0x8002878C: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x80028790: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80028794: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80028798: j           L_80028610
    // 0x8002879C: sw          $v1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r3;
        goto L_80028610;
    // 0x8002879C: sw          $v1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r3;
L_800287A0:
    // 0x800287A0: andi        $v0, $a0, 0x40
    ctx->r2 = ctx->r4 & 0X40;
    // 0x800287A4: beq         $v0, $zero, L_800288EC
    if (ctx->r2 == 0) {
        // 0x800287A8: andi        $v0, $a0, 0x20
        ctx->r2 = ctx->r4 & 0X20;
            goto L_800288EC;
    }
    // 0x800287A8: andi        $v0, $a0, 0x20
    ctx->r2 = ctx->r4 & 0X20;
    // 0x800287AC: beq         $v0, $zero, L_800287C0
    if (ctx->r2 == 0) {
        // 0x800287B0: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800287C0;
    }
    // 0x800287B0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_800287B4:
    // 0x800287B4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800287B8: j           L_80028610
    // 0x800287BC: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
        goto L_80028610;
    // 0x800287BC: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_800287C0:
    // 0x800287C0: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x800287C4: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800287C8: sw          $s4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r20;
    // 0x800287CC: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x800287D0: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800287D4: lw          $v1, 0x8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X8);
    // 0x800287D8: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800287DC: j           L_80028CDC
    // 0x800287E0: addiu       $a2, $zero, -0x3
    ctx->r6 = ADD32(0, -0X3);
        goto L_80028CDC;
    // 0x800287E0: addiu       $a2, $zero, -0x3
    ctx->r6 = ADD32(0, -0X3);
L_800287E4:
    // 0x800287E4: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x800287E8: sltu        $v0, $s2, $a3
    ctx->r2 = ctx->r18 < ctx->r7 ? 1 : 0;
    // 0x800287EC: beq         $v0, $zero, L_80028820
    if (ctx->r2 == 0) {
        // 0x800287F0: sll         $v0, $a3, 2
        ctx->r2 = S32(ctx->r7 << 2);
            goto L_80028820;
    }
    // 0x800287F0: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
L_800287F4:
    // 0x800287F4: beq         $s7, $zero, L_80028C48
    if (ctx->r23 == 0) {
        // 0x800287F8: addiu       $s7, $s7, -0x1
        ctx->r23 = ADD32(ctx->r23, -0X1);
            goto L_80028C48;
    }
    // 0x800287F8: addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
    // 0x800287FC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80028800: lbu         $v0, 0x0($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X0);
    // 0x80028804: sllv        $v0, $v0, $s2
    ctx->r2 = S32(ctx->r2 << (ctx->r18 & 31));
    // 0x80028808: or          $s4, $s4, $v0
    ctx->r20 = ctx->r20 | ctx->r2;
    // 0x8002880C: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80028810: sltu        $v0, $s2, $a3
    ctx->r2 = ctx->r18 < ctx->r7 ? 1 : 0;
    // 0x80028814: bne         $v0, $zero, L_800287F4
    if (ctx->r2 != 0) {
        // 0x80028818: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_800287F4;
    }
    // 0x80028818: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x8002881C: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
L_80028820:
    // 0x80028820: addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // 0x80028824: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80028828: subu        $s2, $s2, $a3
    ctx->r18 = SUB32(ctx->r18, ctx->r7);
    // 0x8002882C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80028830: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80028834: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x80028838: lbu         $a0, 0x11($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X11);
    // 0x8002883C: lw          $a1, 0x18($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X18);
    // 0x80028840: and         $v1, $s4, $v1
    ctx->r3 = ctx->r20 & ctx->r3;
    // 0x80028844: srlv        $s4, $s4, $a3
    ctx->r20 = S32(U32(ctx->r20) >> (ctx->r7 & 31));
    // 0x80028848: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8002884C: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x80028850: sw          $a0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r4;
    // 0x80028854: sw          $a1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r5;
L_80028858:
    // 0x80028858: lw          $a3, 0xC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XC);
    // 0x8002885C: sltu        $v0, $s2, $a3
    ctx->r2 = ctx->r18 < ctx->r7 ? 1 : 0;
    // 0x80028860: beq         $v0, $zero, L_80028894
    if (ctx->r2 == 0) {
        // 0x80028864: sll         $v0, $a3, 2
        ctx->r2 = S32(ctx->r7 << 2);
            goto L_80028894;
    }
    // 0x80028864: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
L_80028868:
    // 0x80028868: beq         $s7, $zero, L_80028C68
    if (ctx->r23 == 0) {
        // 0x8002886C: addiu       $s7, $s7, -0x1
        ctx->r23 = ADD32(ctx->r23, -0X1);
            goto L_80028C68;
    }
    // 0x8002886C: addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
    // 0x80028870: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80028874: lbu         $v0, 0x0($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X0);
    // 0x80028878: sllv        $v0, $v0, $s2
    ctx->r2 = S32(ctx->r2 << (ctx->r18 & 31));
    // 0x8002887C: or          $s4, $s4, $v0
    ctx->r20 = ctx->r20 | ctx->r2;
    // 0x80028880: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80028884: sltu        $v0, $s2, $a3
    ctx->r2 = ctx->r18 < ctx->r7 ? 1 : 0;
    // 0x80028888: bne         $v0, $zero, L_80028868
    if (ctx->r2 != 0) {
        // 0x8002888C: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_80028868;
    }
    // 0x8002888C: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80028890: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
L_80028894:
    // 0x80028894: addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // 0x80028898: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8002889C: lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X8);
    // 0x800288A0: and         $v0, $s4, $v0
    ctx->r2 = ctx->r20 & ctx->r2;
    // 0x800288A4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800288A8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800288AC: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x800288B0: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800288B4: srlv        $s4, $s4, $v0
    ctx->r20 = S32(U32(ctx->r20) >> (ctx->r2 & 31));
    // 0x800288B8: subu        $s2, $s2, $v0
    ctx->r18 = SUB32(ctx->r18, ctx->r2);
    // 0x800288BC: andi        $v0, $a0, 0x10
    ctx->r2 = ctx->r4 & 0X10;
    // 0x800288C0: beq         $v0, $zero, L_800288E0
    if (ctx->r2 == 0) {
        // 0x800288C4: andi        $v0, $a0, 0xF
        ctx->r2 = ctx->r4 & 0XF;
            goto L_800288E0;
    }
    // 0x800288C4: andi        $v0, $a0, 0xF
    ctx->r2 = ctx->r4 & 0XF;
    // 0x800288C8: sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    // 0x800288CC: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x800288D0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800288D4: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800288D8: j           L_80028610
    // 0x800288DC: sw          $v1, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r3;
        goto L_80028610;
    // 0x800288DC: sw          $v1, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r3;
L_800288E0:
    // 0x800288E0: andi        $v0, $a0, 0x40
    ctx->r2 = ctx->r4 & 0X40;
    // 0x800288E4: bnel        $v0, $zero, L_800288FC
    if (ctx->r2 != 0) {
        // 0x800288E8: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800288FC;
    }
    goto skip_0;
    // 0x800288E8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    skip_0:
L_800288EC:
    // 0x800288EC: sw          $a0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r4;
    // 0x800288F0: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x800288F4: j           L_80028610
    // 0x800288F8: sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
        goto L_80028610;
    // 0x800288F8: sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
L_800288FC:
    // 0x800288FC: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80028900: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80028904: sw          $s4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r20;
    // 0x80028908: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x8002890C: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80028910: lw          $v1, 0x8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X8);
    // 0x80028914: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80028918: j           L_80028CDC
    // 0x8002891C: addiu       $a2, $zero, -0x3
    ctx->r6 = ADD32(0, -0X3);
        goto L_80028CDC;
    // 0x8002891C: addiu       $a2, $zero, -0x3
    ctx->r6 = ADD32(0, -0X3);
L_80028920:
    // 0x80028920: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x80028924: sltu        $v0, $s2, $a3
    ctx->r2 = ctx->r18 < ctx->r7 ? 1 : 0;
    // 0x80028928: beq         $v0, $zero, L_8002895C
    if (ctx->r2 == 0) {
        // 0x8002892C: sll         $v0, $a3, 2
        ctx->r2 = S32(ctx->r7 << 2);
            goto L_8002895C;
    }
    // 0x8002892C: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
L_80028930:
    // 0x80028930: beq         $s7, $zero, L_80028C88
    if (ctx->r23 == 0) {
        // 0x80028934: addiu       $s7, $s7, -0x1
        ctx->r23 = ADD32(ctx->r23, -0X1);
            goto L_80028C88;
    }
    // 0x80028934: addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
    // 0x80028938: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8002893C: lbu         $v0, 0x0($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X0);
    // 0x80028940: sllv        $v0, $v0, $s2
    ctx->r2 = S32(ctx->r2 << (ctx->r18 & 31));
    // 0x80028944: or          $s4, $s4, $v0
    ctx->r20 = ctx->r20 | ctx->r2;
    // 0x80028948: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x8002894C: sltu        $v0, $s2, $a3
    ctx->r2 = ctx->r18 < ctx->r7 ? 1 : 0;
    // 0x80028950: bne         $v0, $zero, L_80028930
    if (ctx->r2 != 0) {
        // 0x80028954: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_80028930;
    }
    // 0x80028954: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80028958: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
L_8002895C:
    // 0x8002895C: addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // 0x80028960: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80028964: subu        $s2, $s2, $a3
    ctx->r18 = SUB32(ctx->r18, ctx->r7);
    // 0x80028968: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8002896C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80028970: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x80028974: and         $v1, $s4, $v1
    ctx->r3 = ctx->r20 & ctx->r3;
    // 0x80028978: srlv        $s4, $s4, $a3
    ctx->r20 = S32(U32(ctx->r20) >> (ctx->r7 & 31));
    // 0x8002897C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80028980: sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
L_80028984:
    // 0x80028984: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80028988: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x8002898C: subu        $a1, $t0, $v0
    ctx->r5 = SUB32(ctx->r8, ctx->r2);
    // 0x80028990: sltu        $v0, $a1, $a0
    ctx->r2 = ctx->r5 < ctx->r4 ? 1 : 0;
    // 0x80028994: beq         $v0, $zero, L_800289A8
    if (ctx->r2 == 0) {
        // 0x80028998: subu        $v0, $a0, $a1
        ctx->r2 = SUB32(ctx->r4, ctx->r5);
            goto L_800289A8;
    }
    // 0x80028998: subu        $v0, $a0, $a1
    ctx->r2 = SUB32(ctx->r4, ctx->r5);
    // 0x8002899C: lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X28);
    // 0x800289A0: j           L_800289AC
    // 0x800289A4: subu        $s5, $v1, $v0
    ctx->r21 = SUB32(ctx->r3, ctx->r2);
        goto L_800289AC;
    // 0x800289A4: subu        $s5, $v1, $v0
    ctx->r21 = SUB32(ctx->r3, ctx->r2);
L_800289A8:
    // 0x800289A8: subu        $s5, $t0, $a0
    ctx->r21 = SUB32(ctx->r8, ctx->r4);
L_800289AC:
    // 0x800289AC: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x800289B0: beql        $v0, $zero, L_80028610
    if (ctx->r2 == 0) {
        // 0x800289B4: sw          $zero, 0x0($s1)
        MEM_W(0X0, ctx->r17) = 0;
            goto L_80028610;
    }
    goto skip_1;
    // 0x800289B4: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    skip_1:
L_800289B8:
    // 0x800289B8: bne         $t1, $zero, L_80028A74
    if (ctx->r9 != 0) {
        // 0x800289BC: nop
    
            goto L_80028A74;
    }
    // 0x800289BC: nop

    // 0x800289C0: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x800289C4: bne         $t0, $a0, L_800289F8
    if (ctx->r8 != ctx->r4) {
        // 0x800289C8: nop
    
            goto L_800289F8;
    }
    // 0x800289C8: nop

    // 0x800289CC: lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C);
    // 0x800289D0: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800289D4: beq         $v1, $v0, L_800289F8
    if (ctx->r3 == ctx->r2) {
        // 0x800289D8: nop
    
            goto L_800289F8;
    }
    // 0x800289D8: nop

    // 0x800289DC: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x800289E0: sltu        $v0, $t0, $v1
    ctx->r2 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800289E4: beq         $v0, $zero, L_800289F4
    if (ctx->r2 == 0) {
        // 0x800289E8: subu        $v0, $v1, $t0
        ctx->r2 = SUB32(ctx->r3, ctx->r8);
            goto L_800289F4;
    }
    // 0x800289E8: subu        $v0, $v1, $t0
    ctx->r2 = SUB32(ctx->r3, ctx->r8);
    // 0x800289EC: j           L_800289F8
    // 0x800289F0: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
        goto L_800289F8;
    // 0x800289F0: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
L_800289F4:
    // 0x800289F4: subu        $t1, $a0, $t0
    ctx->r9 = SUB32(ctx->r4, ctx->r8);
L_800289F8:
    // 0x800289F8: bne         $t1, $zero, L_80028A74
    if (ctx->r9 != 0) {
        // 0x800289FC: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80028A74;
    }
    // 0x800289FC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80028A00: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80028A04: jal         0x80029B20
    // 0x80028A08: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    inflate_flush(rdram, ctx);
        goto after_1;
    // 0x80028A08: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    after_1:
    // 0x80028A0C: lw          $t0, 0x30($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X30);
    // 0x80028A10: lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C);
    // 0x80028A14: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80028A18: sltu        $v0, $t0, $v1
    ctx->r2 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80028A1C: beq         $v0, $zero, L_80028A2C
    if (ctx->r2 == 0) {
        // 0x80028A20: subu        $v0, $v1, $t0
        ctx->r2 = SUB32(ctx->r3, ctx->r8);
            goto L_80028A2C;
    }
    // 0x80028A20: subu        $v0, $v1, $t0
    ctx->r2 = SUB32(ctx->r3, ctx->r8);
    // 0x80028A24: j           L_80028A34
    // 0x80028A28: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
        goto L_80028A34;
    // 0x80028A28: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
L_80028A2C:
    // 0x80028A2C: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x80028A30: subu        $t1, $v0, $t0
    ctx->r9 = SUB32(ctx->r2, ctx->r8);
L_80028A34:
    // 0x80028A34: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x80028A38: bne         $t0, $a0, L_80028A6C
    if (ctx->r8 != ctx->r4) {
        // 0x80028A3C: nop
    
            goto L_80028A6C;
    }
    // 0x80028A3C: nop

    // 0x80028A40: lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C);
    // 0x80028A44: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80028A48: beq         $v1, $v0, L_80028A6C
    if (ctx->r3 == ctx->r2) {
        // 0x80028A4C: nop
    
            goto L_80028A6C;
    }
    // 0x80028A4C: nop

    // 0x80028A50: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80028A54: sltu        $v0, $t0, $v1
    ctx->r2 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80028A58: beq         $v0, $zero, L_80028A68
    if (ctx->r2 == 0) {
        // 0x80028A5C: subu        $v0, $v1, $t0
        ctx->r2 = SUB32(ctx->r3, ctx->r8);
            goto L_80028A68;
    }
    // 0x80028A5C: subu        $v0, $v1, $t0
    ctx->r2 = SUB32(ctx->r3, ctx->r8);
    // 0x80028A60: j           L_80028A6C
    // 0x80028A64: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
        goto L_80028A6C;
    // 0x80028A64: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
L_80028A68:
    // 0x80028A68: subu        $t1, $a0, $t0
    ctx->r9 = SUB32(ctx->r4, ctx->r8);
L_80028A6C:
    // 0x80028A6C: beq         $t1, $zero, L_80028CA8
    if (ctx->r9 == 0) {
        // 0x80028A70: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80028CA8;
    }
    // 0x80028A70: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80028A74:
    // 0x80028A74: lbu         $v0, 0x0($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X0);
    // 0x80028A78: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80028A7C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80028A80: sb          $v0, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r2;
    // 0x80028A84: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x80028A88: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x80028A8C: bne         $s5, $v0, L_80028A98
    if (ctx->r21 != ctx->r2) {
        // 0x80028A90: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_80028A98;
    }
    // 0x80028A90: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80028A94: lw          $s5, 0x24($s0)
    ctx->r21 = MEM_W(ctx->r16, 0X24);
L_80028A98:
    // 0x80028A98: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x80028A9C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80028AA0: bne         $v0, $zero, L_800289B8
    if (ctx->r2 != 0) {
        // 0x80028AA4: sw          $v0, 0x4($s1)
        MEM_W(0X4, ctx->r17) = ctx->r2;
            goto L_800289B8;
    }
    // 0x80028AA4: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x80028AA8: j           L_80028610
    // 0x80028AAC: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
        goto L_80028610;
    // 0x80028AAC: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_80028AB0:
    // 0x80028AB0: bne         $t1, $zero, L_80028B84
    if (ctx->r9 != 0) {
        // 0x80028AB4: nop
    
            goto L_80028B84;
    }
    // 0x80028AB4: nop

    // 0x80028AB8: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x80028ABC: bne         $t0, $a0, L_80028AF0
    if (ctx->r8 != ctx->r4) {
        // 0x80028AC0: nop
    
            goto L_80028AF0;
    }
    // 0x80028AC0: nop

    // 0x80028AC4: lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C);
    // 0x80028AC8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80028ACC: beq         $v1, $v0, L_80028AF0
    if (ctx->r3 == ctx->r2) {
        // 0x80028AD0: nop
    
            goto L_80028AF0;
    }
    // 0x80028AD0: nop

    // 0x80028AD4: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80028AD8: sltu        $v0, $t0, $v1
    ctx->r2 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80028ADC: beq         $v0, $zero, L_80028AEC
    if (ctx->r2 == 0) {
        // 0x80028AE0: subu        $v0, $v1, $t0
        ctx->r2 = SUB32(ctx->r3, ctx->r8);
            goto L_80028AEC;
    }
    // 0x80028AE0: subu        $v0, $v1, $t0
    ctx->r2 = SUB32(ctx->r3, ctx->r8);
    // 0x80028AE4: j           L_80028AF0
    // 0x80028AE8: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
        goto L_80028AF0;
    // 0x80028AE8: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
L_80028AEC:
    // 0x80028AEC: subu        $t1, $a0, $t0
    ctx->r9 = SUB32(ctx->r4, ctx->r8);
L_80028AF0:
    // 0x80028AF0: bne         $t1, $zero, L_80028B84
    if (ctx->r9 != 0) {
        // 0x80028AF4: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80028B84;
    }
    // 0x80028AF4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80028AF8: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80028AFC: jal         0x80029B20
    // 0x80028B00: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    inflate_flush(rdram, ctx);
        goto after_2;
    // 0x80028B00: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    after_2:
    // 0x80028B04: lw          $t0, 0x30($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X30);
    // 0x80028B08: lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C);
    // 0x80028B0C: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80028B10: sltu        $v0, $t0, $v1
    ctx->r2 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80028B14: beq         $v0, $zero, L_80028B24
    if (ctx->r2 == 0) {
        // 0x80028B18: subu        $v0, $v1, $t0
        ctx->r2 = SUB32(ctx->r3, ctx->r8);
            goto L_80028B24;
    }
    // 0x80028B18: subu        $v0, $v1, $t0
    ctx->r2 = SUB32(ctx->r3, ctx->r8);
    // 0x80028B1C: j           L_80028B2C
    // 0x80028B20: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
        goto L_80028B2C;
    // 0x80028B20: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
L_80028B24:
    // 0x80028B24: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x80028B28: subu        $t1, $v0, $t0
    ctx->r9 = SUB32(ctx->r2, ctx->r8);
L_80028B2C:
    // 0x80028B2C: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x80028B30: bne         $t0, $a0, L_80028B64
    if (ctx->r8 != ctx->r4) {
        // 0x80028B34: nop
    
            goto L_80028B64;
    }
    // 0x80028B34: nop

    // 0x80028B38: lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C);
    // 0x80028B3C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80028B40: beq         $v1, $v0, L_80028B64
    if (ctx->r3 == ctx->r2) {
        // 0x80028B44: nop
    
            goto L_80028B64;
    }
    // 0x80028B44: nop

    // 0x80028B48: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80028B4C: sltu        $v0, $t0, $v1
    ctx->r2 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80028B50: beq         $v0, $zero, L_80028B60
    if (ctx->r2 == 0) {
        // 0x80028B54: subu        $v0, $v1, $t0
        ctx->r2 = SUB32(ctx->r3, ctx->r8);
            goto L_80028B60;
    }
    // 0x80028B54: subu        $v0, $v1, $t0
    ctx->r2 = SUB32(ctx->r3, ctx->r8);
    // 0x80028B58: j           L_80028B64
    // 0x80028B5C: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
        goto L_80028B64;
    // 0x80028B5C: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
L_80028B60:
    // 0x80028B60: subu        $t1, $a0, $t0
    ctx->r9 = SUB32(ctx->r4, ctx->r8);
L_80028B64:
    // 0x80028B64: bne         $t1, $zero, L_80028B84
    if (ctx->r9 != 0) {
        // 0x80028B68: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80028B84;
    }
    // 0x80028B68: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80028B6C: sw          $s4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r20;
    // 0x80028B70: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x80028B74: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80028B78: lw          $v1, 0x8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X8);
    // 0x80028B7C: j           L_80028CDC
    // 0x80028B80: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
        goto L_80028CDC;
    // 0x80028B80: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
L_80028B84:
    // 0x80028B84: lbu         $v0, 0xB($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XB);
    // 0x80028B88: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80028B8C: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x80028B90: sb          $v0, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r2;
    // 0x80028B94: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80028B98: j           L_80028610
    // 0x80028B9C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
        goto L_80028610;
    // 0x80028B9C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_80028BA0:
    // 0x80028BA0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80028BA4: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80028BA8: jal         0x80029B20
    // 0x80028BAC: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    inflate_flush(rdram, ctx);
        goto after_3;
    // 0x80028BAC: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    after_3:
    // 0x80028BB0: lw          $t0, 0x30($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X30);
    // 0x80028BB4: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80028BB8: lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C);
    // 0x80028BBC: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x80028BC0: beq         $v1, $v0, L_80028BE0
    if (ctx->r3 == ctx->r2) {
        // 0x80028BC4: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80028BE0;
    }
    // 0x80028BC4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80028BC8: sw          $s4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r20;
    // 0x80028BCC: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x80028BD0: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80028BD4: lw          $v1, 0x8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X8);
    // 0x80028BD8: j           L_80028CDC
    // 0x80028BDC: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
        goto L_80028CDC;
    // 0x80028BDC: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
L_80028BE0:
    // 0x80028BE0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80028BE4: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_80028BE8:
    // 0x80028BE8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80028BEC: sw          $s4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r20;
    // 0x80028BF0: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x80028BF4: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80028BF8: lw          $v1, 0x8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X8);
    // 0x80028BFC: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80028C00: j           L_80028CDC
    // 0x80028C04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80028CDC;
    // 0x80028C04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80028C08:
    // 0x80028C08: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80028C0C: sw          $s4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r20;
    // 0x80028C10: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x80028C14: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80028C18: lw          $v1, 0x8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X8);
    // 0x80028C1C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80028C20: j           L_80028CDC
    // 0x80028C24: addiu       $a2, $zero, -0x3
    ctx->r6 = ADD32(0, -0X3);
        goto L_80028CDC;
    // 0x80028C24: addiu       $a2, $zero, -0x3
    ctx->r6 = ADD32(0, -0X3);
L_80028C28:
    // 0x80028C28: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80028C2C: sw          $s4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r20;
    // 0x80028C30: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x80028C34: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80028C38: lw          $v1, 0x8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X8);
    // 0x80028C3C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80028C40: j           L_80028CE0
    // 0x80028C44: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
        goto L_80028CE0;
    // 0x80028C44: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_80028C48:
    // 0x80028C48: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80028C4C: sw          $s4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r20;
    // 0x80028C50: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x80028C54: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80028C58: lw          $v1, 0x8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X8);
    // 0x80028C5C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80028C60: j           L_80028CE0
    // 0x80028C64: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
        goto L_80028CE0;
    // 0x80028C64: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_80028C68:
    // 0x80028C68: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80028C6C: sw          $s4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r20;
    // 0x80028C70: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x80028C74: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80028C78: lw          $v1, 0x8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X8);
    // 0x80028C7C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80028C80: j           L_80028CE0
    // 0x80028C84: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
        goto L_80028CE0;
    // 0x80028C84: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_80028C88:
    // 0x80028C88: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80028C8C: sw          $s4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r20;
    // 0x80028C90: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x80028C94: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80028C98: lw          $v1, 0x8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X8);
    // 0x80028C9C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80028CA0: j           L_80028CE0
    // 0x80028CA4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
        goto L_80028CE0;
    // 0x80028CA4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_80028CA8:
    // 0x80028CA8: sw          $s4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r20;
    // 0x80028CAC: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x80028CB0: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80028CB4: lw          $v1, 0x8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X8);
    // 0x80028CB8: j           L_80028CDC
    // 0x80028CBC: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
        goto L_80028CDC;
    // 0x80028CBC: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
L_80028CC0:
    // 0x80028CC0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80028CC4: sw          $s4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r20;
    // 0x80028CC8: sw          $s2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r18;
    // 0x80028CCC: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80028CD0: lw          $v1, 0x8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X8);
    // 0x80028CD4: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80028CD8: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
L_80028CDC:
    // 0x80028CDC: sw          $s7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r23;
L_80028CE0:
    // 0x80028CE0: sw          $s6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r22;
    // 0x80028CE4: subu        $v0, $s6, $v0
    ctx->r2 = SUB32(ctx->r22, ctx->r2);
    // 0x80028CE8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80028CEC: sw          $v1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r3;
    // 0x80028CF0: jal         0x80029B20
    // 0x80028CF4: sw          $t0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r8;
    inflate_flush(rdram, ctx);
        goto after_4;
    // 0x80028CF4: sw          $t0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r8;
    after_4:
    // 0x80028CF8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80028CFC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80028D00: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80028D04: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80028D08: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80028D0C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80028D10: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80028D14: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80028D18: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80028D1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80028D20: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80028D24: jr          $ra
    // 0x80028D28: nop

    return;
    // 0x80028D28: nop

;}
RECOMP_FUNC void inflate_codes_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028D2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80028D30: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x80028D34: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80028D38: lw          $v1, 0x24($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X24);
    // 0x80028D3C: lw          $a0, 0x28($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X28);
    // 0x80028D40: jalr        $v1
    // 0x80028D44: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80028D44: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_0:
    // 0x80028D48: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80028D4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80028D50: jr          $ra
    // 0x80028D54: nop

    return;
    // 0x80028D54: nop

;}
RECOMP_FUNC void fake_func_80028D58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028D58: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x80028D5C: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
;}
RECOMP_FUNC void inflate_fast(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028D60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80028D64: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80028D68: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80028D6C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80028D70: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80028D74: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x80028D78: lw          $t5, 0x4($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X4);
    // 0x80028D7C: lw          $t3, 0x30($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X30);
    // 0x80028D80: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x80028D84: lw          $t2, 0x20($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X20);
    // 0x80028D88: lw          $t0, 0x1C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X1C);
    // 0x80028D8C: sltu        $v0, $t3, $v1
    ctx->r2 = ctx->r11 < ctx->r3 ? 1 : 0;
    // 0x80028D90: beq         $v0, $zero, L_80028DC8
    if (ctx->r2 == 0) {
        // 0x80028D94: addu        $s1, $a2, $zero
        ctx->r17 = ADD32(ctx->r6, 0);
            goto L_80028DC8;
    }
    // 0x80028D94: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x80028D98: subu        $v0, $v1, $t3
    ctx->r2 = SUB32(ctx->r3, ctx->r11);
    // 0x80028D9C: j           L_80028DD0
    // 0x80028DA0: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
        goto L_80028DD0;
    // 0x80028DA0: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
L_80028DA4:
    // 0x80028DA4: addu        $t5, $t5, $t1
    ctx->r13 = ADD32(ctx->r13, ctx->r9);
    // 0x80028DA8: andi        $t0, $t0, 0x7
    ctx->r8 = ctx->r8 & 0X7;
    // 0x80028DAC: sw          $t2, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->r10;
    // 0x80028DB0: sw          $t0, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->r8;
    // 0x80028DB4: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x80028DB8: lw          $a0, 0x8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8);
    // 0x80028DBC: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x80028DC0: j           L_800290AC
    // 0x80028DC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800290AC;
    // 0x80028DC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80028DC8:
    // 0x80028DC8: lw          $v0, 0x28($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X28);
    // 0x80028DCC: subu        $t6, $v0, $t3
    ctx->r14 = SUB32(ctx->r2, ctx->r11);
L_80028DD0:
    // 0x80028DD0: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80028DD4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80028DD8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80028DDC: lw          $s0, -0x6FC0($at)
    ctx->r16 = MEM_W(ctx->r1, -0X6FC0);
    // 0x80028DE0: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80028DE4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80028DE8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80028DEC: lw          $a2, -0x6FC0($at)
    ctx->r6 = MEM_W(ctx->r1, -0X6FC0);
    // 0x80028DF0: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80028DF4: addiu       $t9, $t9, -0x6FC0
    ctx->r25 = ADD32(ctx->r25, -0X6FC0);
    // 0x80028DF8: j           L_80028E18
    // 0x80028DFC: sltiu       $v0, $t0, 0x14
    ctx->r2 = ctx->r8 < 0X14 ? 1 : 0;
        goto L_80028E18;
    // 0x80028DFC: sltiu       $v0, $t0, 0x14
    ctx->r2 = ctx->r8 < 0X14 ? 1 : 0;
L_80028E00:
    // 0x80028E00: lbu         $v0, 0x0($t4)
    ctx->r2 = MEM_BU(ctx->r12, 0X0);
    // 0x80028E04: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x80028E08: sllv        $v0, $v0, $t0
    ctx->r2 = S32(ctx->r2 << (ctx->r8 & 31));
    // 0x80028E0C: or          $t2, $t2, $v0
    ctx->r10 = ctx->r10 | ctx->r2;
    // 0x80028E10: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80028E14: sltiu       $v0, $t0, 0x14
    ctx->r2 = ctx->r8 < 0X14 ? 1 : 0;
L_80028E18:
    // 0x80028E18: bnel        $v0, $zero, L_80028E00
    if (ctx->r2 != 0) {
        // 0x80028E1C: addiu       $t5, $t5, -0x1
        ctx->r13 = ADD32(ctx->r13, -0X1);
            goto L_80028E00;
    }
    goto skip_0;
    // 0x80028E1C: addiu       $t5, $t5, -0x1
    ctx->r13 = ADD32(ctx->r13, -0X1);
    skip_0:
    // 0x80028E20: and         $v0, $t2, $s0
    ctx->r2 = ctx->r10 & ctx->r16;
    // 0x80028E24: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80028E28: j           L_80029014
    // 0x80028E2C: addu        $v1, $s1, $v0
    ctx->r3 = ADD32(ctx->r17, ctx->r2);
        goto L_80029014;
    // 0x80028E2C: addu        $v1, $s1, $v0
    ctx->r3 = ADD32(ctx->r17, ctx->r2);
L_80028E30:
    // 0x80028E30: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x80028E34: srlv        $t2, $t2, $v0
    ctx->r10 = S32(U32(ctx->r10) >> (ctx->r2 & 31));
    // 0x80028E38: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x80028E3C: andi        $v0, $a1, 0x10
    ctx->r2 = ctx->r5 & 0X10;
    // 0x80028E40: beq         $v0, $zero, L_80028FF0
    if (ctx->r2 == 0) {
        // 0x80028E44: andi        $v0, $a1, 0x40
        ctx->r2 = ctx->r5 & 0X40;
            goto L_80028FF0;
    }
    // 0x80028E44: andi        $v0, $a1, 0x40
    ctx->r2 = ctx->r5 & 0X40;
    // 0x80028E48: andi        $a1, $a1, 0xF
    ctx->r5 = ctx->r5 & 0XF;
    // 0x80028E4C: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80028E50: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x80028E54: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80028E58: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x80028E5C: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x80028E60: and         $v0, $t2, $v0
    ctx->r2 = ctx->r10 & ctx->r2;
    // 0x80028E64: addu        $t1, $v1, $v0
    ctx->r9 = ADD32(ctx->r3, ctx->r2);
    // 0x80028E68: sltiu       $v0, $t0, 0xF
    ctx->r2 = ctx->r8 < 0XF ? 1 : 0;
    // 0x80028E6C: beq         $v0, $zero, L_80028E94
    if (ctx->r2 == 0) {
        // 0x80028E70: srlv        $t2, $t2, $a1
        ctx->r10 = S32(U32(ctx->r10) >> (ctx->r5 & 31));
            goto L_80028E94;
    }
    // 0x80028E70: srlv        $t2, $t2, $a1
    ctx->r10 = S32(U32(ctx->r10) >> (ctx->r5 & 31));
L_80028E74:
    // 0x80028E74: lbu         $v0, 0x0($t4)
    ctx->r2 = MEM_BU(ctx->r12, 0X0);
    // 0x80028E78: addiu       $t5, $t5, -0x1
    ctx->r13 = ADD32(ctx->r13, -0X1);
    // 0x80028E7C: sllv        $v0, $v0, $t0
    ctx->r2 = S32(ctx->r2 << (ctx->r8 & 31));
    // 0x80028E80: or          $t2, $t2, $v0
    ctx->r10 = ctx->r10 | ctx->r2;
    // 0x80028E84: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80028E88: sltiu       $v0, $t0, 0xF
    ctx->r2 = ctx->r8 < 0XF ? 1 : 0;
    // 0x80028E8C: bne         $v0, $zero, L_80028E74
    if (ctx->r2 != 0) {
        // 0x80028E90: addiu       $t4, $t4, 0x1
        ctx->r12 = ADD32(ctx->r12, 0X1);
            goto L_80028E74;
    }
    // 0x80028E90: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
L_80028E94:
    // 0x80028E94: and         $v0, $t2, $a2
    ctx->r2 = ctx->r10 & ctx->r6;
    // 0x80028E98: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80028E9C: addu        $v1, $a3, $v0
    ctx->r3 = ADD32(ctx->r7, ctx->r2);
L_80028EA0:
    // 0x80028EA0: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x80028EA4: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x80028EA8: srlv        $t2, $t2, $v0
    ctx->r10 = S32(U32(ctx->r10) >> (ctx->r2 & 31));
    // 0x80028EAC: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x80028EB0: andi        $v0, $a1, 0x10
    ctx->r2 = ctx->r5 & 0X10;
    // 0x80028EB4: beq         $v0, $zero, L_80028FA4
    if (ctx->r2 == 0) {
        // 0x80028EB8: andi        $v0, $a1, 0x40
        ctx->r2 = ctx->r5 & 0X40;
            goto L_80028FA4;
    }
    // 0x80028EB8: andi        $v0, $a1, 0x40
    ctx->r2 = ctx->r5 & 0X40;
    // 0x80028EBC: andi        $a1, $a1, 0xF
    ctx->r5 = ctx->r5 & 0XF;
    // 0x80028EC0: sltu        $v0, $t0, $a1
    ctx->r2 = ctx->r8 < ctx->r5 ? 1 : 0;
    // 0x80028EC4: beq         $v0, $zero, L_80028EF0
    if (ctx->r2 == 0) {
        // 0x80028EC8: sll         $v0, $a1, 2
        ctx->r2 = S32(ctx->r5 << 2);
            goto L_80028EF0;
    }
    // 0x80028EC8: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
L_80028ECC:
    // 0x80028ECC: lbu         $v0, 0x0($t4)
    ctx->r2 = MEM_BU(ctx->r12, 0X0);
    // 0x80028ED0: addiu       $t5, $t5, -0x1
    ctx->r13 = ADD32(ctx->r13, -0X1);
    // 0x80028ED4: sllv        $v0, $v0, $t0
    ctx->r2 = S32(ctx->r2 << (ctx->r8 & 31));
    // 0x80028ED8: or          $t2, $t2, $v0
    ctx->r10 = ctx->r10 | ctx->r2;
    // 0x80028EDC: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80028EE0: sltu        $v0, $t0, $a1
    ctx->r2 = ctx->r8 < ctx->r5 ? 1 : 0;
    // 0x80028EE4: bne         $v0, $zero, L_80028ECC
    if (ctx->r2 != 0) {
        // 0x80028EE8: addiu       $t4, $t4, 0x1
        ctx->r12 = ADD32(ctx->r12, 0X1);
            goto L_80028ECC;
    }
    // 0x80028EE8: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x80028EEC: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
L_80028EF0:
    // 0x80028EF0: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x80028EF4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80028EF8: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x80028EFC: subu        $t6, $t6, $t1
    ctx->r14 = SUB32(ctx->r14, ctx->r9);
    // 0x80028F00: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x80028F04: lw          $a0, 0x24($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X24);
    // 0x80028F08: and         $v0, $t2, $v0
    ctx->r2 = ctx->r10 & ctx->r2;
    // 0x80028F0C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80028F10: subu        $a0, $t3, $a0
    ctx->r4 = SUB32(ctx->r11, ctx->r4);
    // 0x80028F14: sltu        $v0, $a0, $v1
    ctx->r2 = ctx->r4 < ctx->r3 ? 1 : 0;
    // 0x80028F18: bne         $v0, $zero, L_80028F4C
    if (ctx->r2 != 0) {
        // 0x80028F1C: srlv        $t2, $t2, $a1
        ctx->r10 = S32(U32(ctx->r10) >> (ctx->r5 & 31));
            goto L_80028F4C;
    }
    // 0x80028F1C: srlv        $t2, $t2, $a1
    ctx->r10 = S32(U32(ctx->r10) >> (ctx->r5 & 31));
    // 0x80028F20: subu        $v1, $t3, $v1
    ctx->r3 = SUB32(ctx->r11, ctx->r3);
    // 0x80028F24: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80028F28: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80028F2C: addiu       $t1, $t1, -0x2
    ctx->r9 = ADD32(ctx->r9, -0X2);
    // 0x80028F30: sb          $v0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r2;
    // 0x80028F34: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80028F38: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80028F3C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80028F40: sb          $v0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r2;
    // 0x80028F44: j           L_80028F84
    // 0x80028F48: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
        goto L_80028F84;
    // 0x80028F48: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
L_80028F4C:
    // 0x80028F4C: lw          $v0, 0x28($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X28);
    // 0x80028F50: subu        $a1, $v1, $a0
    ctx->r5 = SUB32(ctx->r3, ctx->r4);
    // 0x80028F54: subu        $v1, $v0, $a1
    ctx->r3 = SUB32(ctx->r2, ctx->r5);
    // 0x80028F58: sltu        $v0, $a1, $t1
    ctx->r2 = ctx->r5 < ctx->r9 ? 1 : 0;
    // 0x80028F5C: beq         $v0, $zero, L_80028F84
    if (ctx->r2 == 0) {
        // 0x80028F60: nop
    
            goto L_80028F84;
    }
    // 0x80028F60: nop

    // 0x80028F64: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
L_80028F68:
    // 0x80028F68: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80028F6C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80028F70: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80028F74: sb          $v0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r2;
    // 0x80028F78: bne         $a1, $zero, L_80028F68
    if (ctx->r5 != 0) {
        // 0x80028F7C: addiu       $t3, $t3, 0x1
        ctx->r11 = ADD32(ctx->r11, 0X1);
            goto L_80028F68;
    }
    // 0x80028F7C: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80028F80: lw          $v1, 0x24($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X24);
L_80028F84:
    // 0x80028F84: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80028F88: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80028F8C: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x80028F90: sb          $v0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r2;
    // 0x80028F94: bne         $t1, $zero, L_80028F84
    if (ctx->r9 != 0) {
        // 0x80028F98: addiu       $t3, $t3, 0x1
        ctx->r11 = ADD32(ctx->r11, 0X1);
            goto L_80028F84;
    }
    // 0x80028F98: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80028F9C: j           L_80029070
    // 0x80028FA0: sltiu       $v1, $t6, 0x102
    ctx->r3 = ctx->r14 < 0X102 ? 1 : 0;
        goto L_80029070;
    // 0x80028FA0: sltiu       $v1, $t6, 0x102
    ctx->r3 = ctx->r14 < 0X102 ? 1 : 0;
L_80028FA4:
    // 0x80028FA4: bnel        $v0, $zero, L_80028FCC
    if (ctx->r2 != 0) {
        // 0x80028FA8: srl         $t1, $t0, 3
        ctx->r9 = S32(U32(ctx->r8) >> 3);
            goto L_80028FCC;
    }
    goto skip_1;
    // 0x80028FA8: srl         $t1, $t0, 3
    ctx->r9 = S32(U32(ctx->r8) >> 3);
    skip_1:
    // 0x80028FAC: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80028FB0: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x80028FB4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80028FB8: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x80028FBC: and         $v0, $t2, $v0
    ctx->r2 = ctx->r10 & ctx->r2;
    // 0x80028FC0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80028FC4: j           L_80028EA0
    // 0x80028FC8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
        goto L_80028EA0;
    // 0x80028FC8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
L_80028FCC:
    // 0x80028FCC: addu        $t5, $t5, $t1
    ctx->r13 = ADD32(ctx->r13, ctx->r9);
    // 0x80028FD0: andi        $t0, $t0, 0x7
    ctx->r8 = ctx->r8 & 0X7;
    // 0x80028FD4: sw          $t2, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->r10;
    // 0x80028FD8: sw          $t0, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->r8;
    // 0x80028FDC: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x80028FE0: lw          $a0, 0x8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8);
    // 0x80028FE4: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x80028FE8: j           L_800290AC
    // 0x80028FEC: addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
        goto L_800290AC;
    // 0x80028FEC: addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
L_80028FF0:
    // 0x80028FF0: bne         $v0, $zero, L_80029040
    if (ctx->r2 != 0) {
        // 0x80028FF4: andi        $v0, $a1, 0x20
        ctx->r2 = ctx->r5 & 0X20;
            goto L_80029040;
    }
    // 0x80028FF4: andi        $v0, $a1, 0x20
    ctx->r2 = ctx->r5 & 0X20;
    // 0x80028FF8: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80028FFC: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x80029000: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80029004: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x80029008: and         $v0, $t2, $v0
    ctx->r2 = ctx->r10 & ctx->r2;
    // 0x8002900C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80029010: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
L_80029014:
    // 0x80029014: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x80029018: bne         $a1, $zero, L_80028E30
    if (ctx->r5 != 0) {
        // 0x8002901C: nop
    
            goto L_80028E30;
    }
    // 0x8002901C: nop

    // 0x80029020: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x80029024: addiu       $t6, $t6, -0x1
    ctx->r14 = ADD32(ctx->r14, -0X1);
    // 0x80029028: lbu         $v1, 0x7($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7);
    // 0x8002902C: srlv        $t2, $t2, $v0
    ctx->r10 = S32(U32(ctx->r10) >> (ctx->r2 & 31));
    // 0x80029030: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x80029034: sb          $v1, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r3;
    // 0x80029038: j           L_8002906C
    // 0x8002903C: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
        goto L_8002906C;
    // 0x8002903C: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
L_80029040:
    // 0x80029040: bne         $v0, $zero, L_80028DA4
    if (ctx->r2 != 0) {
        // 0x80029044: srl         $t1, $t0, 3
        ctx->r9 = S32(U32(ctx->r8) >> 3);
            goto L_80028DA4;
    }
    // 0x80029044: srl         $t1, $t0, 3
    ctx->r9 = S32(U32(ctx->r8) >> 3);
    // 0x80029048: addu        $t5, $t5, $t1
    ctx->r13 = ADD32(ctx->r13, ctx->r9);
    // 0x8002904C: andi        $t0, $t0, 0x7
    ctx->r8 = ctx->r8 & 0X7;
    // 0x80029050: sw          $t2, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->r10;
    // 0x80029054: sw          $t0, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->r8;
    // 0x80029058: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x8002905C: lw          $a0, 0x8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8);
    // 0x80029060: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x80029064: j           L_800290AC
    // 0x80029068: addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
        goto L_800290AC;
    // 0x80029068: addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
L_8002906C:
    // 0x8002906C: sltiu       $v1, $t6, 0x102
    ctx->r3 = ctx->r14 < 0X102 ? 1 : 0;
L_80029070:
    // 0x80029070: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x80029074: sltiu       $v0, $t5, 0xA
    ctx->r2 = ctx->r13 < 0XA ? 1 : 0;
    // 0x80029078: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8002907C: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80029080: bne         $v1, $zero, L_80028E18
    if (ctx->r3 != 0) {
        // 0x80029084: sltiu       $v0, $t0, 0x14
        ctx->r2 = ctx->r8 < 0X14 ? 1 : 0;
            goto L_80028E18;
    }
    // 0x80029084: sltiu       $v0, $t0, 0x14
    ctx->r2 = ctx->r8 < 0X14 ? 1 : 0;
    // 0x80029088: srl         $t1, $t0, 3
    ctx->r9 = S32(U32(ctx->r8) >> 3);
    // 0x8002908C: addu        $t5, $t5, $t1
    ctx->r13 = ADD32(ctx->r13, ctx->r9);
    // 0x80029090: andi        $t0, $t0, 0x7
    ctx->r8 = ctx->r8 & 0X7;
    // 0x80029094: sw          $t2, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->r10;
    // 0x80029098: sw          $t0, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->r8;
    // 0x8002909C: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x800290A0: lw          $a0, 0x8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8);
    // 0x800290A4: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x800290A8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800290AC:
    // 0x800290AC: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x800290B0: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x800290B4: subu        $v1, $t4, $v1
    ctx->r3 = SUB32(ctx->r12, ctx->r3);
    // 0x800290B8: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x800290BC: sw          $a0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r4;
    // 0x800290C0: sw          $t3, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r11;
    // 0x800290C4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800290C8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800290CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800290D0: jr          $ra
    // 0x800290D4: nop

    return;
    // 0x800290D4: nop

;}
RECOMP_FUNC void fake_func_800290D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800290D8: lw          $v1, 0x28($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X28);
    // 0x800290DC: lw          $a0, 0x28($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X28);
;}
RECOMP_FUNC void huft_build_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800290E0: addiu       $sp, $sp, -0x5D0
    ctx->r29 = ADD32(ctx->r29, -0X5D0);
    // 0x800290E4: addu        $t8, $a2, $zero
    ctx->r24 = ADD32(ctx->r6, 0);
    // 0x800290E8: lw          $t9, 0x5E4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5E4);
    // 0x800290EC: lw          $a2, 0x5E8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5E8);
    // 0x800290F0: sw          $s1, 0x5AC($sp)
    MEM_W(0X5AC, ctx->r29) = ctx->r17;
    // 0x800290F4: sw          $a1, 0x55C($sp)
    MEM_W(0X55C, ctx->r29) = ctx->r5;
    // 0x800290F8: lw          $s1, 0x55C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X55C);
    // 0x800290FC: sw          $s5, 0x5BC($sp)
    MEM_W(0X5BC, ctx->r29) = ctx->r21;
    // 0x80029100: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x80029104: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80029108: sw          $ra, 0x5CC($sp)
    MEM_W(0X5CC, ctx->r29) = ctx->r31;
    // 0x8002910C: sw          $fp, 0x5C8($sp)
    MEM_W(0X5C8, ctx->r29) = ctx->r30;
    // 0x80029110: sw          $s7, 0x5C4($sp)
    MEM_W(0X5C4, ctx->r29) = ctx->r23;
    // 0x80029114: sw          $s6, 0x5C0($sp)
    MEM_W(0X5C0, ctx->r29) = ctx->r22;
    // 0x80029118: sw          $s4, 0x5B8($sp)
    MEM_W(0X5B8, ctx->r29) = ctx->r20;
    // 0x8002911C: sw          $s3, 0x5B4($sp)
    MEM_W(0X5B4, ctx->r29) = ctx->r19;
    // 0x80029120: sw          $s2, 0x5B0($sp)
    MEM_W(0X5B0, ctx->r29) = ctx->r18;
    // 0x80029124: sw          $s0, 0x5A8($sp)
    MEM_W(0X5A8, ctx->r29) = ctx->r16;
    // 0x80029128: sw          $a3, 0x564($sp)
    MEM_W(0X564, ctx->r29) = ctx->r7;
    // 0x8002912C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80029130: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80029134: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80029138: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8002913C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80029140: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80029144: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80029148: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8002914C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80029150: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80029154: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80029158: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8002915C: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80029160: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80029164: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80029168: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
L_8002916C:
    // 0x8002916C: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x80029170: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80029174: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80029178: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8002917C: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80029180: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80029184: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80029188: bne         $s1, $zero, L_8002916C
    if (ctx->r17 != 0) {
        // 0x8002918C: sw          $v1, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r3;
            goto L_8002916C;
    }
    // 0x8002918C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80029190: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80029194: lw          $t7, 0x55C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X55C);
    // 0x80029198: bne         $v0, $t7, L_800291B0
    if (ctx->r2 != ctx->r15) {
        // 0x8002919C: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_800291B0;
    }
    // 0x8002919C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800291A0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800291A4: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x800291A8: j           L_8002966C
    // 0x800291AC: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_8002966C;
    // 0x800291AC: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_800291B0:
    // 0x800291B0: lw          $fp, 0x0($a2)
    ctx->r30 = MEM_W(ctx->r6, 0X0);
    // 0x800291B4: addiu       $v1, $sp, 0x14
    ctx->r3 = ADD32(ctx->r29, 0X14);
L_800291B8:
    // 0x800291B8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800291BC: bne         $v0, $zero, L_800291D8
    if (ctx->r2 != 0) {
        // 0x800291C0: addu        $t2, $s0, $zero
        ctx->r10 = ADD32(ctx->r16, 0);
            goto L_800291D8;
    }
    // 0x800291C0: addu        $t2, $s0, $zero
    ctx->r10 = ADD32(ctx->r16, 0);
    // 0x800291C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800291C8: sltiu       $v0, $s0, 0x10
    ctx->r2 = ctx->r16 < 0X10 ? 1 : 0;
    // 0x800291CC: bne         $v0, $zero, L_800291B8
    if (ctx->r2 != 0) {
        // 0x800291D0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800291B8;
    }
    // 0x800291D0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800291D4: addu        $t2, $s0, $zero
    ctx->r10 = ADD32(ctx->r16, 0);
L_800291D8:
    // 0x800291D8: sltu        $v0, $fp, $t2
    ctx->r2 = ctx->r30 < ctx->r10 ? 1 : 0;
    // 0x800291DC: bnel        $v0, $zero, L_800291E4
    if (ctx->r2 != 0) {
        // 0x800291E0: addu        $fp, $t2, $zero
        ctx->r30 = ADD32(ctx->r10, 0);
            goto L_800291E4;
    }
    goto skip_0;
    // 0x800291E0: addu        $fp, $t2, $zero
    ctx->r30 = ADD32(ctx->r10, 0);
    skip_0:
L_800291E4:
    // 0x800291E4: addiu       $s1, $zero, 0xF
    ctx->r17 = ADD32(0, 0XF);
    // 0x800291E8: addiu       $v1, $sp, 0x4C
    ctx->r3 = ADD32(ctx->r29, 0X4C);
L_800291EC:
    // 0x800291EC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800291F0: bne         $v0, $zero, L_80029208
    if (ctx->r2 != 0) {
        // 0x800291F4: addu        $t6, $s1, $zero
        ctx->r14 = ADD32(ctx->r17, 0);
            goto L_80029208;
    }
    // 0x800291F4: addu        $t6, $s1, $zero
    ctx->r14 = ADD32(ctx->r17, 0);
    // 0x800291F8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800291FC: bne         $s1, $zero, L_800291EC
    if (ctx->r17 != 0) {
        // 0x80029200: addiu       $v1, $v1, -0x4
        ctx->r3 = ADD32(ctx->r3, -0X4);
            goto L_800291EC;
    }
    // 0x80029200: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x80029204: addu        $t6, $s1, $zero
    ctx->r14 = ADD32(ctx->r17, 0);
L_80029208:
    // 0x80029208: sltu        $v0, $t6, $fp
    ctx->r2 = ctx->r14 < ctx->r30 ? 1 : 0;
    // 0x8002920C: bnel        $v0, $zero, L_80029214
    if (ctx->r2 != 0) {
        // 0x80029210: addu        $fp, $t6, $zero
        ctx->r30 = ADD32(ctx->r14, 0);
            goto L_80029214;
    }
    goto skip_1;
    // 0x80029210: addu        $fp, $t6, $zero
    ctx->r30 = ADD32(ctx->r14, 0);
    skip_1:
L_80029214:
    // 0x80029214: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80029218: sllv        $t4, $v0, $s0
    ctx->r12 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8002921C: sltu        $v0, $s0, $t6
    ctx->r2 = ctx->r16 < ctx->r14 ? 1 : 0;
    // 0x80029220: beq         $v0, $zero, L_80029254
    if (ctx->r2 == 0) {
        // 0x80029224: sw          $fp, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r30;
            goto L_80029254;
    }
    // 0x80029224: sw          $fp, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r30;
    // 0x80029228: addiu       $v1, $sp, 0x10
    ctx->r3 = ADD32(ctx->r29, 0X10);
    // 0x8002922C: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x80029230: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
L_80029234:
    // 0x80029234: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029238: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x8002923C: bltz        $t4, L_80029270
    if (SIGNED(ctx->r12) < 0) {
        // 0x80029240: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80029270;
    }
    // 0x80029240: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80029244: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80029248: sltu        $v0, $s0, $s1
    ctx->r2 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x8002924C: bne         $v0, $zero, L_80029234
    if (ctx->r2 != 0) {
        // 0x80029250: sll         $t4, $t4, 1
        ctx->r12 = S32(ctx->r12 << 1);
            goto L_80029234;
    }
    // 0x80029250: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
L_80029254:
    // 0x80029254: sll         $v1, $s1, 2
    ctx->r3 = S32(ctx->r17 << 2);
    // 0x80029258: addiu       $v0, $sp, 0x10
    ctx->r2 = ADD32(ctx->r29, 0X10);
    // 0x8002925C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80029260: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029264: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x80029268: bgez        $t4, L_80029278
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8002926C: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_80029278;
    }
    // 0x8002926C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_80029270:
    // 0x80029270: j           L_8002966C
    // 0x80029274: addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
        goto L_8002966C;
    // 0x80029274: addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
L_80029278:
    // 0x80029278: addiu       $s5, $sp, 0x14
    ctx->r21 = ADD32(ctx->r29, 0X14);
    // 0x8002927C: addiu       $a1, $sp, 0x520
    ctx->r5 = ADD32(ctx->r29, 0X520);
    // 0x80029280: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80029284: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x80029288: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8002928C: beq         $s1, $zero, L_800292B0
    if (ctx->r17 == 0) {
        // 0x80029290: sw          $zero, 0x51C($sp)
        MEM_W(0X51C, ctx->r29) = 0;
            goto L_800292B0;
    }
    // 0x80029290: sw          $zero, 0x51C($sp)
    MEM_W(0X51C, ctx->r29) = 0;
L_80029294:
    // 0x80029294: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x80029298: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x8002929C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800292A0: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x800292A4: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x800292A8: bne         $s1, $zero, L_80029294
    if (ctx->r17 != 0) {
        // 0x800292AC: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80029294;
    }
    // 0x800292AC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_800292B0:
    // 0x800292B0: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x800292B4: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800292B8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
L_800292BC:
    // 0x800292BC: lw          $s0, 0x0($s5)
    ctx->r16 = MEM_W(ctx->r21, 0X0);
    // 0x800292C0: beq         $s0, $zero, L_800292E8
    if (ctx->r16 == 0) {
        // 0x800292C4: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_800292E8;
    }
    // 0x800292C4: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x800292C8: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x800292CC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800292D0: lw          $v1, 0x508($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X508);
    // 0x800292D4: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x800292D8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800292DC: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800292E0: sw          $a0, 0x508($v0)
    MEM_W(0X508, ctx->r2) = ctx->r4;
    // 0x800292E4: sw          $s1, 0x88($v1)
    MEM_W(0X88, ctx->r3) = ctx->r17;
L_800292E8:
    // 0x800292E8: lw          $t7, 0x55C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X55C);
    // 0x800292EC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800292F0: sltu        $v0, $s1, $t7
    ctx->r2 = ctx->r17 < ctx->r15 ? 1 : 0;
    // 0x800292F4: bne         $v0, $zero, L_800292BC
    if (ctx->r2 != 0) {
        // 0x800292F8: addiu       $s6, $zero, -0x1
        ctx->r22 = ADD32(0, -0X1);
            goto L_800292BC;
    }
    // 0x800292F8: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x800292FC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80029300: addiu       $s5, $sp, 0x98
    ctx->r21 = ADD32(ctx->r29, 0X98);
    // 0x80029304: negu        $s2, $fp
    ctx->r18 = SUB32(0, ctx->r30);
    // 0x80029308: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8002930C: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80029310: slt         $v0, $t6, $t2
    ctx->r2 = SIGNED(ctx->r14) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80029314: sw          $zero, 0x518($sp)
    MEM_W(0X518, ctx->r29) = 0;
    // 0x80029318: bne         $v0, $zero, L_80029650
    if (ctx->r2 != 0) {
        // 0x8002931C: sw          $zero, 0x58($sp)
        MEM_W(0X58, ctx->r29) = 0;
            goto L_80029650;
    }
    // 0x8002931C: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x80029320: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80029324: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x80029328: sw          $t7, 0x5A4($sp)
    MEM_W(0X5A4, ctx->r29) = ctx->r15;
    // 0x8002932C: addiu       $t3, $sp, 0x10
    ctx->r11 = ADD32(ctx->r29, 0X10);
    // 0x80029330: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x80029334: sw          $t7, 0x574($sp)
    MEM_W(0X574, ctx->r29) = ctx->r15;
L_80029338:
    // 0x80029338: lw          $t7, 0x574($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X574);
    // 0x8002933C: lw          $t1, 0x0($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X0);
    // 0x80029340: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80029344: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x80029348: beq         $t1, $t7, L_8002962C
    if (ctx->r9 == ctx->r15) {
        // 0x8002934C: addu        $v1, $s2, $fp
        ctx->r3 = ADD32(ctx->r18, ctx->r30);
            goto L_8002962C;
    }
    // 0x8002934C: addu        $v1, $s2, $fp
    ctx->r3 = ADD32(ctx->r18, ctx->r30);
    // 0x80029350: lw          $t7, 0x5A4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5A4);
    // 0x80029354: sll         $s7, $s6, 2
    ctx->r23 = S32(ctx->r22 << 2);
    // 0x80029358: sw          $t7, 0x56C($sp)
    MEM_W(0X56C, ctx->r29) = ctx->r15;
L_8002935C:
    // 0x8002935C: slt         $v0, $v1, $t2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80029360: beq         $v0, $zero, L_800294D4
    if (ctx->r2 == 0) {
        // 0x80029364: sll         $v0, $s6, 2
        ctx->r2 = S32(ctx->r22 << 2);
            goto L_800294D4;
    }
    // 0x80029364: sll         $v0, $s6, 2
    ctx->r2 = S32(ctx->r22 << 2);
    // 0x80029368: addu        $s4, $v0, $t3
    ctx->r20 = ADD32(ctx->r2, ctx->r11);
    // 0x8002936C: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
L_80029370:
    // 0x80029370: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x80029374: addu        $s2, $v1, $zero
    ctx->r18 = ADD32(ctx->r3, 0);
    // 0x80029378: subu        $s3, $t6, $s2
    ctx->r19 = SUB32(ctx->r14, ctx->r18);
    // 0x8002937C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80029380: sltu        $v0, $fp, $a1
    ctx->r2 = ctx->r30 < ctx->r5 ? 1 : 0;
    // 0x80029384: beq         $v0, $zero, L_80029390
    if (ctx->r2 == 0) {
        // 0x80029388: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_80029390;
    }
    // 0x80029388: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x8002938C: addu        $a1, $fp, $zero
    ctx->r5 = ADD32(ctx->r30, 0);
L_80029390:
    // 0x80029390: subu        $s0, $t2, $s2
    ctx->r16 = SUB32(ctx->r10, ctx->r18);
    // 0x80029394: sllv        $a2, $t5, $s0
    ctx->r6 = S32(ctx->r13 << (ctx->r16 & 31));
    // 0x80029398: addiu       $v0, $t1, 0x1
    ctx->r2 = ADD32(ctx->r9, 0X1);
    // 0x8002939C: sltu        $v0, $v0, $a2
    ctx->r2 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x800293A0: beq         $v0, $zero, L_800293EC
    if (ctx->r2 == 0) {
        // 0x800293A4: addu        $s3, $a1, $zero
        ctx->r19 = ADD32(ctx->r5, 0);
            goto L_800293EC;
    }
    // 0x800293A4: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x800293A8: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // 0x800293AC: lw          $t7, 0x56C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X56C);
    // 0x800293B0: subu        $a2, $v0, $t1
    ctx->r6 = SUB32(ctx->r2, ctx->r9);
    // 0x800293B4: sltu        $v0, $s0, $s3
    ctx->r2 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x800293B8: beq         $v0, $zero, L_800293EC
    if (ctx->r2 == 0) {
        // 0x800293BC: addu        $a1, $t3, $t7
        ctx->r5 = ADD32(ctx->r11, ctx->r15);
            goto L_800293EC;
    }
    // 0x800293BC: addu        $a1, $t3, $t7
    ctx->r5 = ADD32(ctx->r11, ctx->r15);
    // 0x800293C0: j           L_800293E0
    // 0x800293C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800293E0;
    // 0x800293C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800293C8:
    // 0x800293C8: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800293CC: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x800293D0: sltu        $v0, $v1, $a2
    ctx->r2 = ctx->r3 < ctx->r6 ? 1 : 0;
    // 0x800293D4: beq         $v0, $zero, L_800293EC
    if (ctx->r2 == 0) {
        // 0x800293D8: subu        $a2, $a2, $v1
        ctx->r6 = SUB32(ctx->r6, ctx->r3);
            goto L_800293EC;
    }
    // 0x800293D8: subu        $a2, $a2, $v1
    ctx->r6 = SUB32(ctx->r6, ctx->r3);
    // 0x800293DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800293E0:
    // 0x800293E0: sltu        $v0, $s0, $s3
    ctx->r2 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x800293E4: bne         $v0, $zero, L_800293C8
    if (ctx->r2 != 0) {
        // 0x800293E8: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_800293C8;
    }
    // 0x800293E8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_800293EC:
    // 0x800293EC: lw          $t7, 0x5EC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5EC);
    // 0x800293F0: sllv        $s3, $t5, $s0
    ctx->r19 = S32(ctx->r13 << (ctx->r16 & 31));
    // 0x800293F4: lw          $a0, 0x28($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X28);
    // 0x800293F8: lw          $v0, 0x20($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X20);
    // 0x800293FC: addiu       $a1, $s3, 0x1
    ctx->r5 = ADD32(ctx->r19, 0X1);
    // 0x80029400: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80029404: sw          $t1, 0x578($sp)
    MEM_W(0X578, ctx->r29) = ctx->r9;
    // 0x80029408: sw          $t2, 0x57C($sp)
    MEM_W(0X57C, ctx->r29) = ctx->r10;
    // 0x8002940C: sw          $t3, 0x580($sp)
    MEM_W(0X580, ctx->r29) = ctx->r11;
    // 0x80029410: sw          $t4, 0x584($sp)
    MEM_W(0X584, ctx->r29) = ctx->r12;
    // 0x80029414: sw          $t5, 0x588($sp)
    MEM_W(0X588, ctx->r29) = ctx->r13;
    // 0x80029418: sw          $t6, 0x58C($sp)
    MEM_W(0X58C, ctx->r29) = ctx->r14;
    // 0x8002941C: sw          $t8, 0x594($sp)
    MEM_W(0X594, ctx->r29) = ctx->r24;
    // 0x80029420: jalr        $v0
    // 0x80029424: sw          $t9, 0x598($sp)
    MEM_W(0X598, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80029424: sw          $t9, 0x598($sp)
    MEM_W(0X598, ctx->r29) = ctx->r25;
    after_0:
    // 0x80029428: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x8002942C: lw          $t1, 0x578($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X578);
    // 0x80029430: lw          $t2, 0x57C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X57C);
    // 0x80029434: lw          $t3, 0x580($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X580);
    // 0x80029438: lw          $t4, 0x584($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X584);
    // 0x8002943C: lw          $t5, 0x588($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X588);
    // 0x80029440: lw          $t6, 0x58C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58C);
    // 0x80029444: lw          $t8, 0x594($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X594);
    // 0x80029448: lw          $t9, 0x598($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X598);
    // 0x8002944C: bnel        $t0, $zero, L_80029474
    if (ctx->r8 != 0) {
        // 0x80029450: addiu       $v0, $t0, 0x8
        ctx->r2 = ADD32(ctx->r8, 0X8);
            goto L_80029474;
    }
    goto skip_2;
    // 0x80029450: addiu       $v0, $t0, 0x8
    ctx->r2 = ADD32(ctx->r8, 0X8);
    skip_2:
    // 0x80029454: beq         $s6, $zero, L_8002966C
    if (ctx->r22 == 0) {
        // 0x80029458: addiu       $v0, $zero, -0x4
        ctx->r2 = ADD32(0, -0X4);
            goto L_8002966C;
    }
    // 0x80029458: addiu       $v0, $zero, -0x4
    ctx->r2 = ADD32(0, -0X4);
    // 0x8002945C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80029460: lw          $a1, 0x5EC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5EC);
    // 0x80029464: jal         0x80029A68
    // 0x80029468: nop

    inflate_trees_free(rdram, ctx);
        goto after_1;
    // 0x80029468: nop

    after_1:
    // 0x8002946C: j           L_8002966C
    // 0x80029470: addiu       $v0, $zero, -0x4
    ctx->r2 = ADD32(0, -0X4);
        goto L_8002966C;
    // 0x80029470: addiu       $v0, $zero, -0x4
    ctx->r2 = ADD32(0, -0X4);
L_80029474:
    // 0x80029474: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x80029478: addiu       $t9, $t0, 0x4
    ctx->r25 = ADD32(ctx->r8, 0X4);
    // 0x8002947C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80029480: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80029484: beq         $s6, $zero, L_800294C4
    if (ctx->r22 == 0) {
        // 0x80029488: sw          $t0, 0x48($s4)
        MEM_W(0X48, ctx->r20) = ctx->r8;
            goto L_800294C4;
    }
    // 0x80029488: sw          $t0, 0x48($s4)
    MEM_W(0X48, ctx->r20) = ctx->r8;
    // 0x8002948C: subu        $v1, $s2, $fp
    ctx->r3 = SUB32(ctx->r18, ctx->r30);
    // 0x80029490: addu        $v0, $sp, $s7
    ctx->r2 = ADD32(ctx->r29, ctx->r23);
    // 0x80029494: sw          $s1, 0x508($s4)
    MEM_W(0X508, ctx->r20) = ctx->r17;
    // 0x80029498: sb          $fp, 0x51($sp)
    MEM_B(0X51, ctx->r29) = ctx->r30;
    // 0x8002949C: sb          $s0, 0x50($sp)
    MEM_B(0X50, ctx->r29) = ctx->r16;
    // 0x800294A0: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x800294A4: lw          $a0, 0x54($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X54);
    // 0x800294A8: srlv        $s0, $s1, $v1
    ctx->r16 = S32(U32(ctx->r17) >> (ctx->r3 & 31));
    // 0x800294AC: sll         $v0, $s0, 3
    ctx->r2 = S32(ctx->r16 << 3);
    // 0x800294B0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800294B4: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x800294B8: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x800294BC: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800294C0: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
L_800294C4:
    // 0x800294C4: addu        $v1, $s2, $fp
    ctx->r3 = ADD32(ctx->r18, ctx->r30);
    // 0x800294C8: slt         $v0, $v1, $t2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800294CC: bnel        $v0, $zero, L_80029370
    if (ctx->r2 != 0) {
        // 0x800294D0: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_80029370;
    }
    goto skip_3;
    // 0x800294D0: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    skip_3:
L_800294D4:
    // 0x800294D4: lw          $t7, 0x55C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X55C);
    // 0x800294D8: subu        $v0, $t2, $s2
    ctx->r2 = SUB32(ctx->r10, ctx->r18);
    // 0x800294DC: sb          $v0, 0x51($sp)
    MEM_B(0X51, ctx->r29) = ctx->r2;
    // 0x800294E0: addiu       $v0, $sp, 0x98
    ctx->r2 = ADD32(ctx->r29, 0X98);
    // 0x800294E4: sll         $v1, $t7, 2
    ctx->r3 = S32(ctx->r15 << 2);
    // 0x800294E8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800294EC: sltu        $v0, $s5, $v0
    ctx->r2 = ctx->r21 < ctx->r2 ? 1 : 0;
    // 0x800294F0: bne         $v0, $zero, L_80029500
    if (ctx->r2 != 0) {
        // 0x800294F4: addiu       $v0, $zero, 0xC0
        ctx->r2 = ADD32(0, 0XC0);
            goto L_80029500;
    }
    // 0x800294F4: addiu       $v0, $zero, 0xC0
    ctx->r2 = ADD32(0, 0XC0);
    // 0x800294F8: j           L_80029568
    // 0x800294FC: sb          $v0, 0x50($sp)
    MEM_B(0X50, ctx->r29) = ctx->r2;
        goto L_80029568;
    // 0x800294FC: sb          $v0, 0x50($sp)
    MEM_B(0X50, ctx->r29) = ctx->r2;
L_80029500:
    // 0x80029500: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80029504: sltu        $v0, $v1, $t8
    ctx->r2 = ctx->r3 < ctx->r24 ? 1 : 0;
    // 0x80029508: beq         $v0, $zero, L_8002952C
    if (ctx->r2 == 0) {
        // 0x8002950C: sltiu       $v0, $v1, 0x100
        ctx->r2 = ctx->r3 < 0X100 ? 1 : 0;
            goto L_8002952C;
    }
    // 0x8002950C: sltiu       $v0, $v1, 0x100
    ctx->r2 = ctx->r3 < 0X100 ? 1 : 0;
    // 0x80029510: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80029514: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80029518: andi        $v0, $v0, 0x60
    ctx->r2 = ctx->r2 & 0X60;
    // 0x8002951C: sb          $v0, 0x50($sp)
    MEM_B(0X50, ctx->r29) = ctx->r2;
    // 0x80029520: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x80029524: j           L_80029564
    // 0x80029528: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
        goto L_80029564;
    // 0x80029528: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_8002952C:
    // 0x8002952C: lw          $t7, 0x5E0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5E0);
    // 0x80029530: subu        $v0, $v1, $t8
    ctx->r2 = SUB32(ctx->r3, ctx->r24);
    // 0x80029534: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80029538: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8002953C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80029540: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x80029544: sb          $v0, 0x50($sp)
    MEM_B(0X50, ctx->r29) = ctx->r2;
    // 0x80029548: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x8002954C: lw          $t7, 0x564($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X564);
    // 0x80029550: subu        $v0, $v0, $t8
    ctx->r2 = SUB32(ctx->r2, ctx->r24);
    // 0x80029554: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80029558: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8002955C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80029560: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_80029564:
    // 0x80029564: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
L_80029568:
    // 0x80029568: subu        $v0, $t2, $s2
    ctx->r2 = SUB32(ctx->r10, ctx->r18);
    // 0x8002956C: sllv        $a2, $t5, $v0
    ctx->r6 = S32(ctx->r13 << (ctx->r2 & 31));
    // 0x80029570: srlv        $s0, $s1, $s2
    ctx->r16 = S32(U32(ctx->r17) >> (ctx->r18 & 31));
    // 0x80029574: sltu        $v0, $s0, $s3
    ctx->r2 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x80029578: beq         $v0, $zero, L_800295AC
    if (ctx->r2 == 0) {
        // 0x8002957C: sll         $v0, $s0, 3
        ctx->r2 = S32(ctx->r16 << 3);
            goto L_800295AC;
    }
    // 0x8002957C: sll         $v0, $s0, 3
    ctx->r2 = S32(ctx->r16 << 3);
    // 0x80029580: addu        $a3, $v0, $t0
    ctx->r7 = ADD32(ctx->r2, ctx->r8);
L_80029584:
    // 0x80029584: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x80029588: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x8002958C: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80029590: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x80029594: sll         $v0, $a2, 3
    ctx->r2 = S32(ctx->r6 << 3);
    // 0x80029598: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x8002959C: addu        $s0, $s0, $a2
    ctx->r16 = ADD32(ctx->r16, ctx->r6);
    // 0x800295A0: sltu        $v0, $s0, $s3
    ctx->r2 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x800295A4: bne         $v0, $zero, L_80029584
    if (ctx->r2 != 0) {
        // 0x800295A8: nop
    
            goto L_80029584;
    }
    // 0x800295A8: nop

L_800295AC:
    // 0x800295AC: addiu       $v0, $t2, -0x1
    ctx->r2 = ADD32(ctx->r10, -0X1);
    // 0x800295B0: sllv        $s0, $t5, $v0
    ctx->r16 = S32(ctx->r13 << (ctx->r2 & 31));
    // 0x800295B4: and         $v0, $s1, $s0
    ctx->r2 = ctx->r17 & ctx->r16;
    // 0x800295B8: beq         $v0, $zero, L_800295D0
    if (ctx->r2 == 0) {
        // 0x800295BC: xor         $s1, $s1, $s0
        ctx->r17 = ctx->r17 ^ ctx->r16;
            goto L_800295D0;
    }
    // 0x800295BC: xor         $s1, $s1, $s0
    ctx->r17 = ctx->r17 ^ ctx->r16;
L_800295C0:
    // 0x800295C0: srl         $s0, $s0, 1
    ctx->r16 = S32(U32(ctx->r16) >> 1);
    // 0x800295C4: and         $v0, $s1, $s0
    ctx->r2 = ctx->r17 & ctx->r16;
    // 0x800295C8: bne         $v0, $zero, L_800295C0
    if (ctx->r2 != 0) {
        // 0x800295CC: xor         $s1, $s1, $s0
        ctx->r17 = ctx->r17 ^ ctx->r16;
            goto L_800295C0;
    }
    // 0x800295CC: xor         $s1, $s1, $s0
    ctx->r17 = ctx->r17 ^ ctx->r16;
L_800295D0:
    // 0x800295D0: sllv        $v0, $t5, $s2
    ctx->r2 = S32(ctx->r13 << (ctx->r18 & 31));
    // 0x800295D4: addu        $v1, $s7, $t3
    ctx->r3 = ADD32(ctx->r23, ctx->r11);
    // 0x800295D8: lw          $v1, 0x508($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X508);
    // 0x800295DC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800295E0: and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // 0x800295E4: beql        $v0, $v1, L_80029620
    if (ctx->r2 == ctx->r3) {
        // 0x800295E8: addiu       $t1, $t1, -0x1
        ctx->r9 = ADD32(ctx->r9, -0X1);
            goto L_80029620;
    }
    goto skip_4;
    // 0x800295E8: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    skip_4:
    // 0x800295EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800295F0: sll         $v0, $s6, 2
    ctx->r2 = S32(ctx->r22 << 2);
    // 0x800295F4: addu        $a0, $v0, $t3
    ctx->r4 = ADD32(ctx->r2, ctx->r11);
L_800295F8:
    // 0x800295F8: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x800295FC: addiu       $s7, $s7, -0x4
    ctx->r23 = ADD32(ctx->r23, -0X4);
    // 0x80029600: subu        $s2, $s2, $fp
    ctx->r18 = SUB32(ctx->r18, ctx->r30);
    // 0x80029604: sllv        $v0, $a1, $s2
    ctx->r2 = S32(ctx->r5 << (ctx->r18 & 31));
    // 0x80029608: lw          $v1, 0x508($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X508);
    // 0x8002960C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80029610: and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // 0x80029614: bne         $v0, $v1, L_800295F8
    if (ctx->r2 != ctx->r3) {
        // 0x80029618: addiu       $s6, $s6, -0x1
        ctx->r22 = ADD32(ctx->r22, -0X1);
            goto L_800295F8;
    }
    // 0x80029618: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x8002961C: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
L_80029620:
    // 0x80029620: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80029624: bne         $t1, $t7, L_8002935C
    if (ctx->r9 != ctx->r15) {
        // 0x80029628: addu        $v1, $s2, $fp
        ctx->r3 = ADD32(ctx->r18, ctx->r30);
            goto L_8002935C;
    }
    // 0x80029628: addu        $v1, $s2, $fp
    ctx->r3 = ADD32(ctx->r18, ctx->r30);
L_8002962C:
    // 0x8002962C: lw          $t7, 0x5A4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5A4);
    // 0x80029630: addiu       $t7, $t7, 0x4
    ctx->r15 = ADD32(ctx->r15, 0X4);
    // 0x80029634: sw          $t7, 0x5A4($sp)
    MEM_W(0X5A4, ctx->r29) = ctx->r15;
    // 0x80029638: lw          $t7, 0x574($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X574);
    // 0x8002963C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80029640: slt         $v0, $t6, $t2
    ctx->r2 = SIGNED(ctx->r14) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80029644: addiu       $t7, $t7, 0x4
    ctx->r15 = ADD32(ctx->r15, 0X4);
    // 0x80029648: beq         $v0, $zero, L_80029338
    if (ctx->r2 == 0) {
        // 0x8002964C: sw          $t7, 0x574($sp)
        MEM_W(0X574, ctx->r29) = ctx->r15;
            goto L_80029338;
    }
    // 0x8002964C: sw          $t7, 0x574($sp)
    MEM_W(0X574, ctx->r29) = ctx->r15;
L_80029650:
    // 0x80029650: sltu        $v0, $zero, $t4
    ctx->r2 = 0 < ctx->r12 ? 1 : 0;
    // 0x80029654: xori        $v1, $t6, 0x1
    ctx->r3 = ctx->r14 ^ 0X1;
    // 0x80029658: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x8002965C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80029660: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80029664: addiu       $v1, $zero, -0x5
    ctx->r3 = ADD32(0, -0X5);
    // 0x80029668: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
L_8002966C:
    // 0x8002966C: lw          $ra, 0x5CC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5CC);
    // 0x80029670: lw          $fp, 0x5C8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X5C8);
    // 0x80029674: lw          $s7, 0x5C4($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C4);
    // 0x80029678: lw          $s6, 0x5C0($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X5C0);
    // 0x8002967C: lw          $s5, 0x5BC($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5BC);
    // 0x80029680: lw          $s4, 0x5B8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X5B8);
    // 0x80029684: lw          $s3, 0x5B4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5B4);
    // 0x80029688: lw          $s2, 0x5B0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X5B0);
    // 0x8002968C: lw          $s1, 0x5AC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5AC);
    // 0x80029690: lw          $s0, 0x5A8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X5A8);
    // 0x80029694: addiu       $sp, $sp, 0x5D0
    ctx->r29 = ADD32(ctx->r29, 0X5D0);
    // 0x80029698: jr          $ra
    // 0x8002969C: nop

    return;
    // 0x8002969C: nop

;}
RECOMP_FUNC void inflate_trees_bits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800296A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800296A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800296A8: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x800296AC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800296B0: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // 0x800296B4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x800296B8: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x800296BC: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x800296C0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800296C4: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800296C8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800296CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800296D0: jal         0x800290E0
    // 0x800296D4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    huft_build_recomp(rdram, ctx);
        goto after_0;
    // 0x800296D4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_0:
    // 0x800296D8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800296DC: addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
    // 0x800296E0: beq         $v1, $v0, L_80029700
    if (ctx->r3 == ctx->r2) {
        // 0x800296E4: addiu       $v0, $zero, -0x5
        ctx->r2 = ADD32(0, -0X5);
            goto L_80029700;
    }
    // 0x800296E4: addiu       $v0, $zero, -0x5
    ctx->r2 = ADD32(0, -0X5);
    // 0x800296E8: bne         $v1, $v0, L_80029704
    if (ctx->r3 != ctx->r2) {
        // 0x800296EC: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_80029704;
    }
    // 0x800296EC: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x800296F0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800296F4: jal         0x80029A68
    // 0x800296F8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    inflate_trees_free(rdram, ctx);
        goto after_1;
    // 0x800296F8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_1:
    // 0x800296FC: addiu       $v1, $zero, -0x3
    ctx->r3 = ADD32(0, -0X3);
L_80029700:
    // 0x80029700: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80029704:
    // 0x80029704: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x80029708: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8002970C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80029710: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80029714: jr          $ra
    // 0x80029718: nop

    return;
    // 0x80029718: nop

;}
RECOMP_FUNC void inflate_trees_dynamic(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002971C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80029720: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80029724: lw          $s7, 0x58($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X58);
    // 0x80029728: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8002972C: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80029730: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80029734: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80029738: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8002973C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80029740: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80029744: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x80029748: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8002974C: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x80029750: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80029754: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80029758: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x8002975C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80029760: addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
    // 0x80029764: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80029768: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x8002976C: addiu       $a3, $a3, -0x71AC
    ctx->r7 = ADD32(ctx->r7, -0X71AC);
    // 0x80029770: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80029774: addiu       $v0, $v0, -0x7130
    ctx->r2 = ADD32(ctx->r2, -0X7130);
    // 0x80029778: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x8002977C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80029780: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80029784: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // 0x80029788: jal         0x800290E0
    // 0x8002978C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    huft_build_recomp(rdram, ctx);
        goto after_0;
    // 0x8002978C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    after_0:
    // 0x80029790: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80029794: beq         $s0, $zero, L_800297BC
    if (ctx->r16 == 0) {
        // 0x80029798: addiu       $v0, $zero, -0x3
        ctx->r2 = ADD32(0, -0X3);
            goto L_800297BC;
    }
    // 0x80029798: addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
    // 0x8002979C: beq         $s0, $v0, L_80029828
    if (ctx->r16 == ctx->r2) {
        // 0x800297A0: addiu       $v0, $zero, -0x5
        ctx->r2 = ADD32(0, -0X5);
            goto L_80029828;
    }
    // 0x800297A0: addiu       $v0, $zero, -0x5
    ctx->r2 = ADD32(0, -0X5);
    // 0x800297A4: bne         $s0, $v0, L_80029834
    if (ctx->r16 != ctx->r2) {
        // 0x800297A8: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_80029834;
    }
    // 0x800297A8: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x800297AC: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x800297B0: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800297B4: j           L_80029820
    // 0x800297B8: addiu       $s0, $zero, -0x3
    ctx->r16 = ADD32(0, -0X3);
        goto L_80029820;
    // 0x800297B8: addiu       $s0, $zero, -0x3
    ctx->r16 = ADD32(0, -0X3);
L_800297BC:
    // 0x800297BC: sll         $a0, $s1, 2
    ctx->r4 = S32(ctx->r17 << 2);
    // 0x800297C0: addu        $a0, $s2, $a0
    ctx->r4 = ADD32(ctx->r18, ctx->r4);
    // 0x800297C4: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x800297C8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800297CC: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800297D0: addiu       $a3, $a3, -0x70B4
    ctx->r7 = ADD32(ctx->r7, -0X70B4);
    // 0x800297D4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800297D8: addiu       $v0, $v0, -0x703C
    ctx->r2 = ADD32(ctx->r2, -0X703C);
    // 0x800297DC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800297E0: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x800297E4: sw          $s7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r23;
    // 0x800297E8: jal         0x800290E0
    // 0x800297EC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    huft_build_recomp(rdram, ctx);
        goto after_1;
    // 0x800297EC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    after_1:
    // 0x800297F0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800297F4: beq         $s0, $zero, L_80029830
    if (ctx->r16 == 0) {
        // 0x800297F8: addiu       $v0, $zero, -0x3
        ctx->r2 = ADD32(0, -0X3);
            goto L_80029830;
    }
    // 0x800297F8: addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
    // 0x800297FC: beq         $s0, $v0, L_80029818
    if (ctx->r16 == ctx->r2) {
        // 0x80029800: addiu       $v0, $zero, -0x5
        ctx->r2 = ADD32(0, -0X5);
            goto L_80029818;
    }
    // 0x80029800: addiu       $v0, $zero, -0x5
    ctx->r2 = ADD32(0, -0X5);
    // 0x80029804: bne         $s0, $v0, L_80029818
    if (ctx->r16 != ctx->r2) {
        // 0x80029808: addu        $a1, $s3, $zero
        ctx->r5 = ADD32(ctx->r19, 0);
            goto L_80029818;
    }
    // 0x80029808: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8002980C: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    // 0x80029810: jal         0x80029A68
    // 0x80029814: addiu       $s0, $zero, -0x3
    ctx->r16 = ADD32(0, -0X3);
    inflate_trees_free(rdram, ctx);
        goto after_2;
    // 0x80029814: addiu       $s0, $zero, -0x3
    ctx->r16 = ADD32(0, -0X3);
    after_2:
L_80029818:
    // 0x80029818: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x8002981C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
L_80029820:
    // 0x80029820: jal         0x80029A68
    // 0x80029824: nop

    inflate_trees_free(rdram, ctx);
        goto after_3;
    // 0x80029824: nop

    after_3:
L_80029828:
    // 0x80029828: j           L_80029834
    // 0x8002982C: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
        goto L_80029834;
    // 0x8002982C: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80029830:
    // 0x80029830: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80029834:
    // 0x80029834: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x80029838: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8002983C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80029840: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80029844: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80029848: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8002984C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80029850: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80029854: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80029858: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8002985C: jr          $ra
    // 0x80029860: nop

    return;
    // 0x80029860: nop

;}
RECOMP_FUNC void inflate_trees_fixed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029864: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80029868: lw          $v0, -0x6FC4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6FC4);
    // 0x8002986C: addiu       $sp, $sp, -0x4F8
    ctx->r29 = ADD32(ctx->r29, -0X4F8);
    // 0x80029870: sw          $s0, 0x4E0($sp)
    MEM_W(0X4E0, ctx->r29) = ctx->r16;
    // 0x80029874: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80029878: sw          $s1, 0x4E4($sp)
    MEM_W(0X4E4, ctx->r29) = ctx->r17;
    // 0x8002987C: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80029880: sw          $s2, 0x4E8($sp)
    MEM_W(0X4E8, ctx->r29) = ctx->r18;
    // 0x80029884: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x80029888: sw          $s3, 0x4EC($sp)
    MEM_W(0X4EC, ctx->r29) = ctx->r19;
    // 0x8002988C: addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // 0x80029890: bne         $v0, $zero, L_80029A14
    if (ctx->r2 != 0) {
        // 0x80029894: sw          $ra, 0x4F0($sp)
        MEM_W(0X4F0, ctx->r29) = ctx->r31;
            goto L_80029A14;
    }
    // 0x80029894: sw          $ra, 0x4F0($sp)
    MEM_W(0X4F0, ctx->r29) = ctx->r31;
    // 0x80029898: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8002989C: addiu       $a0, $zero, 0x8F
    ctx->r4 = ADD32(0, 0X8F);
    // 0x800298A0: addiu       $v1, $sp, 0x25C
    ctx->r3 = ADD32(ctx->r29, 0X25C);
    // 0x800298A4: addiu       $v0, $zero, 0x212
    ctx->r2 = ADD32(0, 0X212);
    // 0x800298A8: sw          $v0, 0x4D8($sp)
    MEM_W(0X4D8, ctx->r29) = ctx->r2;
    // 0x800298AC: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x800298B0: addiu       $v0, $v0, -0x6518
    ctx->r2 = ADD32(ctx->r2, -0X6518);
    // 0x800298B4: sw          $v0, 0x4C0($sp)
    MEM_W(0X4C0, ctx->r29) = ctx->r2;
    // 0x800298B8: addiu       $v0, $sp, 0x4D8
    ctx->r2 = ADD32(ctx->r29, 0X4D8);
    // 0x800298BC: sw          $zero, 0x4C4($sp)
    MEM_W(0X4C4, ctx->r29) = 0;
    // 0x800298C0: sw          $v0, 0x4C8($sp)
    MEM_W(0X4C8, ctx->r29) = ctx->r2;
L_800298C4:
    // 0x800298C4: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800298C8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800298CC: bgez        $a0, L_800298C4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800298D0: addiu       $v1, $v1, -0x4
        ctx->r3 = ADD32(ctx->r3, -0X4);
            goto L_800298C4;
    }
    // 0x800298D0: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800298D4: addiu       $a0, $zero, 0x90
    ctx->r4 = ADD32(0, 0X90);
    // 0x800298D8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800298DC: addiu       $v1, $sp, 0x260
    ctx->r3 = ADD32(ctx->r29, 0X260);
L_800298E0:
    // 0x800298E0: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800298E4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800298E8: slti        $v0, $a0, 0x100
    ctx->r2 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x800298EC: bne         $v0, $zero, L_800298E0
    if (ctx->r2 != 0) {
        // 0x800298F0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800298E0;
    }
    // 0x800298F0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800298F4: slti        $v0, $a0, 0x118
    ctx->r2 = SIGNED(ctx->r4) < 0X118 ? 1 : 0;
    // 0x800298F8: beq         $v0, $zero, L_80029920
    if (ctx->r2 == 0) {
        // 0x800298FC: sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4 << 2);
            goto L_80029920;
    }
    // 0x800298FC: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80029900: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80029904: addiu       $v1, $sp, 0x20
    ctx->r3 = ADD32(ctx->r29, 0X20);
    // 0x80029908: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
L_8002990C:
    // 0x8002990C: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x80029910: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80029914: slti        $v0, $a0, 0x118
    ctx->r2 = SIGNED(ctx->r4) < 0X118 ? 1 : 0;
    // 0x80029918: bne         $v0, $zero, L_8002990C
    if (ctx->r2 != 0) {
        // 0x8002991C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8002990C;
    }
    // 0x8002991C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80029920:
    // 0x80029920: slti        $v0, $a0, 0x120
    ctx->r2 = SIGNED(ctx->r4) < 0X120 ? 1 : 0;
    // 0x80029924: beq         $v0, $zero, L_8002994C
    if (ctx->r2 == 0) {
        // 0x80029928: addiu       $a1, $zero, 0x8
        ctx->r5 = ADD32(0, 0X8);
            goto L_8002994C;
    }
    // 0x80029928: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8002992C: addiu       $v1, $sp, 0x20
    ctx->r3 = ADD32(ctx->r29, 0X20);
    // 0x80029930: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80029934: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
L_80029938:
    // 0x80029938: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x8002993C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80029940: slti        $v0, $a0, 0x120
    ctx->r2 = SIGNED(ctx->r4) < 0X120 ? 1 : 0;
    // 0x80029944: bne         $v0, $zero, L_80029938
    if (ctx->r2 != 0) {
        // 0x80029948: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80029938;
    }
    // 0x80029948: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8002994C:
    // 0x8002994C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80029950: addiu       $a1, $zero, 0x120
    ctx->r5 = ADD32(0, 0X120);
    // 0x80029954: addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
    // 0x80029958: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x8002995C: addiu       $a3, $a3, -0x71AC
    ctx->r7 = ADD32(ctx->r7, -0X71AC);
    // 0x80029960: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80029964: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80029968: sw          $v0, -0x3040($at)
    MEM_W(-0X3040, ctx->r1) = ctx->r2;
    // 0x8002996C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80029970: addiu       $v0, $v0, -0x7130
    ctx->r2 = ADD32(ctx->r2, -0X7130);
    // 0x80029974: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80029978: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8002997C: addiu       $v0, $v0, -0x3038
    ctx->r2 = ADD32(ctx->r2, -0X3038);
    // 0x80029980: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80029984: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80029988: addiu       $v0, $v0, -0x3040
    ctx->r2 = ADD32(ctx->r2, -0X3040);
    // 0x8002998C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80029990: addiu       $v0, $sp, 0x4A0
    ctx->r2 = ADD32(ctx->r29, 0X4A0);
    // 0x80029994: jal         0x800290E0
    // 0x80029998: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    huft_build_recomp(rdram, ctx);
        goto after_0;
    // 0x80029998: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8002999C: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x800299A0: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x800299A4: addiu       $v0, $sp, 0x94
    ctx->r2 = ADD32(ctx->r29, 0X94);
L_800299A8:
    // 0x800299A8: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800299AC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800299B0: bgez        $a0, L_800299A8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800299B4: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_800299A8;
    }
    // 0x800299B4: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x800299B8: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800299BC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x800299C0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800299C4: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800299C8: addiu       $a3, $a3, -0x70B4
    ctx->r7 = ADD32(ctx->r7, -0X70B4);
    // 0x800299CC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800299D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800299D4: sw          $v0, -0x303C($at)
    MEM_W(-0X303C, ctx->r1) = ctx->r2;
    // 0x800299D8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800299DC: addiu       $v0, $v0, -0x703C
    ctx->r2 = ADD32(ctx->r2, -0X703C);
    // 0x800299E0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800299E4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800299E8: addiu       $v0, $v0, -0x3034
    ctx->r2 = ADD32(ctx->r2, -0X3034);
    // 0x800299EC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x800299F0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800299F4: addiu       $v0, $v0, -0x303C
    ctx->r2 = ADD32(ctx->r2, -0X303C);
    // 0x800299F8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800299FC: addiu       $v0, $sp, 0x4A0
    ctx->r2 = ADD32(ctx->r29, 0X4A0);
    // 0x80029A00: jal         0x800290E0
    // 0x80029A04: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    huft_build_recomp(rdram, ctx);
        goto after_1;
    // 0x80029A04: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80029A08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80029A0C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80029A10: sw          $v0, -0x6FC4($at)
    MEM_W(-0X6FC4, ctx->r1) = ctx->r2;
L_80029A14:
    // 0x80029A14: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80029A18: lw          $v0, -0x3040($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3040);
    // 0x80029A1C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80029A20: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80029A24: lw          $v0, -0x303C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X303C);
    // 0x80029A28: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80029A2C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80029A30: lw          $v0, -0x3038($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3038);
    // 0x80029A34: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x80029A38: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80029A3C: lw          $v1, -0x3034($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3034);
    // 0x80029A40: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80029A44: sw          $v1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r3;
    // 0x80029A48: lw          $ra, 0x4F0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4F0);
    // 0x80029A4C: lw          $s3, 0x4EC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4EC);
    // 0x80029A50: lw          $s2, 0x4E8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4E8);
    // 0x80029A54: lw          $s1, 0x4E4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4E4);
    // 0x80029A58: lw          $s0, 0x4E0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4E0);
    // 0x80029A5C: addiu       $sp, $sp, 0x4F8
    ctx->r29 = ADD32(ctx->r29, 0X4F8);
    // 0x80029A60: jr          $ra
    // 0x80029A64: nop

    return;
    // 0x80029A64: nop

;}
RECOMP_FUNC void inflate_trees_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029A68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80029A6C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80029A70: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80029A74: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80029A78: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80029A7C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80029A80: beq         $s0, $zero, L_80029AA0
    if (ctx->r16 == 0) {
        // 0x80029A84: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_80029AA0;
    }
    // 0x80029A84: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
L_80029A88:
    // 0x80029A88: lw          $v0, -0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X4);
    // 0x80029A8C: sw          $a1, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r5;
    // 0x80029A90: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80029A94: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80029A98: bne         $s0, $zero, L_80029A88
    if (ctx->r16 != 0) {
        // 0x80029A9C: nop
    
            goto L_80029A88;
    }
    // 0x80029A9C: nop

L_80029AA0:
    // 0x80029AA0: beq         $a1, $zero, L_80029AD0
    if (ctx->r5 == 0) {
        // 0x80029AA4: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80029AD0;
    }
    // 0x80029AA4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80029AA8: addiu       $a1, $a1, -0x8
    ctx->r5 = ADD32(ctx->r5, -0X8);
L_80029AAC:
    // 0x80029AAC: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x80029AB0: lw          $a0, 0x28($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X28);
    // 0x80029AB4: lw          $s0, 0x4($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X4);
    // 0x80029AB8: jalr        $v0
    // 0x80029ABC: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80029ABC: nop

    after_0:
    // 0x80029AC0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80029AC4: bnel        $a1, $zero, L_80029AAC
    if (ctx->r5 != 0) {
        // 0x80029AC8: addiu       $a1, $a1, -0x8
        ctx->r5 = ADD32(ctx->r5, -0X8);
            goto L_80029AAC;
    }
    goto skip_0;
    // 0x80029AC8: addiu       $a1, $a1, -0x8
    ctx->r5 = ADD32(ctx->r5, -0X8);
    skip_0:
    // 0x80029ACC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80029AD0:
    // 0x80029AD0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80029AD4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80029AD8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80029ADC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80029AE0: jr          $ra
    // 0x80029AE4: nop

    return;
    // 0x80029AE4: nop

;}
RECOMP_FUNC void falloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029AE8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80029AEC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80029AF0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80029AF4: addiu       $v1, $v1, -0x40D0
    ctx->r3 = ADD32(ctx->r3, -0X40D0);
    // 0x80029AF8: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x80029AFC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80029B00: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80029B04: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80029B08: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80029B0C: jr          $ra
    // 0x80029B10: nop

    return;
    // 0x80029B10: nop

;}
RECOMP_FUNC void fake_func_80029B14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029B14: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80029B18: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80029B1C: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
;}
RECOMP_FUNC void inflate_flush(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029B20: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80029B24: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80029B28: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80029B2C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80029B30: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x80029B34: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80029B38: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80029B3C: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80029B40: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80029B44: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80029B48: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80029B4C: lw          $s1, 0x2C($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X2C);
    // 0x80029B50: lw          $v1, 0x30($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X30);
    // 0x80029B54: lw          $s4, 0xC($s3)
    ctx->r20 = MEM_W(ctx->r19, 0XC);
    // 0x80029B58: sltu        $v0, $v1, $s1
    ctx->r2 = ctx->r3 < ctx->r17 ? 1 : 0;
    // 0x80029B5C: bne         $v0, $zero, L_80029B6C
    if (ctx->r2 != 0) {
        // 0x80029B60: addu        $s5, $a2, $zero
        ctx->r21 = ADD32(ctx->r6, 0);
            goto L_80029B6C;
    }
    // 0x80029B60: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x80029B64: j           L_80029B74
    // 0x80029B68: subu        $s0, $v1, $s1
    ctx->r16 = SUB32(ctx->r3, ctx->r17);
        goto L_80029B74;
    // 0x80029B68: subu        $s0, $v1, $s1
    ctx->r16 = SUB32(ctx->r3, ctx->r17);
L_80029B6C:
    // 0x80029B6C: lw          $v0, 0x28($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X28);
    // 0x80029B70: subu        $s0, $v0, $s1
    ctx->r16 = SUB32(ctx->r2, ctx->r17);
L_80029B74:
    // 0x80029B74: lw          $v1, 0x10($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X10);
    // 0x80029B78: sltu        $v0, $v1, $s0
    ctx->r2 = ctx->r3 < ctx->r16 ? 1 : 0;
    // 0x80029B7C: bnel        $v0, $zero, L_80029B84
    if (ctx->r2 != 0) {
        // 0x80029B80: addu        $s0, $v1, $zero
        ctx->r16 = ADD32(ctx->r3, 0);
            goto L_80029B84;
    }
    goto skip_0;
    // 0x80029B80: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    skip_0:
L_80029B84:
    // 0x80029B84: lw          $v0, 0x14($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X14);
    // 0x80029B88: subu        $v1, $v1, $s0
    ctx->r3 = SUB32(ctx->r3, ctx->r16);
    // 0x80029B8C: sw          $v1, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r3;
    // 0x80029B90: sltu        $v1, $zero, $s0
    ctx->r3 = 0 < ctx->r16 ? 1 : 0;
    // 0x80029B94: addiu       $s6, $zero, -0x5
    ctx->r22 = ADD32(0, -0X5);
    // 0x80029B98: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80029B9C: sw          $v0, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r2;
    // 0x80029BA0: xor         $v0, $s5, $s6
    ctx->r2 = ctx->r21 ^ ctx->r22;
    // 0x80029BA4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80029BA8: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80029BAC: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80029BB0: lw          $v0, 0x34($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X34);
    // 0x80029BB4: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x80029BB8: beq         $v0, $zero, L_80029BD8
    if (ctx->r2 == 0) {
        // 0x80029BBC: and         $s5, $s5, $v1
        ctx->r21 = ctx->r21 & ctx->r3;
            goto L_80029BD8;
    }
    // 0x80029BBC: and         $s5, $s5, $v1
    ctx->r21 = ctx->r21 & ctx->r3;
    // 0x80029BC0: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x80029BC4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80029BC8: jalr        $v0
    // 0x80029BCC: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80029BCC: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80029BD0: sw          $v0, 0x38($s2)
    MEM_W(0X38, ctx->r18) = ctx->r2;
    // 0x80029BD4: sw          $v0, 0x30($s3)
    MEM_W(0X30, ctx->r19) = ctx->r2;
L_80029BD8:
    // 0x80029BD8: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80029BDC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80029BE0: jal         0x80018EF4
    // 0x80029BE4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    zmemcpy(rdram, ctx);
        goto after_1;
    // 0x80029BE4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80029BE8: lw          $v1, 0x28($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X28);
    // 0x80029BEC: addu        $s1, $s1, $s0
    ctx->r17 = ADD32(ctx->r17, ctx->r16);
    // 0x80029BF0: bne         $s1, $v1, L_80029C88
    if (ctx->r17 != ctx->r3) {
        // 0x80029BF4: addu        $s4, $s4, $s0
        ctx->r20 = ADD32(ctx->r20, ctx->r16);
            goto L_80029C88;
    }
    // 0x80029BF4: addu        $s4, $s4, $s0
    ctx->r20 = ADD32(ctx->r20, ctx->r16);
    // 0x80029BF8: lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X30);
    // 0x80029BFC: lw          $s1, 0x24($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X24);
    // 0x80029C00: beql        $v0, $v1, L_80029C08
    if (ctx->r2 == ctx->r3) {
        // 0x80029C04: sw          $s1, 0x30($s2)
        MEM_W(0X30, ctx->r18) = ctx->r17;
            goto L_80029C08;
    }
    goto skip_1;
    // 0x80029C04: sw          $s1, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->r17;
    skip_1:
L_80029C08:
    // 0x80029C08: lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X30);
    // 0x80029C0C: lw          $v1, 0x10($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X10);
    // 0x80029C10: subu        $s0, $v0, $s1
    ctx->r16 = SUB32(ctx->r2, ctx->r17);
    // 0x80029C14: sltu        $v0, $v1, $s0
    ctx->r2 = ctx->r3 < ctx->r16 ? 1 : 0;
    // 0x80029C18: bnel        $v0, $zero, L_80029C20
    if (ctx->r2 != 0) {
        // 0x80029C1C: addu        $s0, $v1, $zero
        ctx->r16 = ADD32(ctx->r3, 0);
            goto L_80029C20;
    }
    goto skip_2;
    // 0x80029C1C: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    skip_2:
L_80029C20:
    // 0x80029C20: lw          $v0, 0x14($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X14);
    // 0x80029C24: subu        $v1, $v1, $s0
    ctx->r3 = SUB32(ctx->r3, ctx->r16);
    // 0x80029C28: sw          $v1, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r3;
    // 0x80029C2C: sltu        $v1, $zero, $s0
    ctx->r3 = 0 < ctx->r16 ? 1 : 0;
    // 0x80029C30: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80029C34: sw          $v0, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r2;
    // 0x80029C38: xor         $v0, $s5, $s6
    ctx->r2 = ctx->r21 ^ ctx->r22;
    // 0x80029C3C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80029C40: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80029C44: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80029C48: lw          $v0, 0x34($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X34);
    // 0x80029C4C: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x80029C50: beq         $v0, $zero, L_80029C70
    if (ctx->r2 == 0) {
        // 0x80029C54: and         $s5, $s5, $v1
        ctx->r21 = ctx->r21 & ctx->r3;
            goto L_80029C70;
    }
    // 0x80029C54: and         $s5, $s5, $v1
    ctx->r21 = ctx->r21 & ctx->r3;
    // 0x80029C58: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x80029C5C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80029C60: jalr        $v0
    // 0x80029C64: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x80029C64: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80029C68: sw          $v0, 0x38($s2)
    MEM_W(0X38, ctx->r18) = ctx->r2;
    // 0x80029C6C: sw          $v0, 0x30($s3)
    MEM_W(0X30, ctx->r19) = ctx->r2;
L_80029C70:
    // 0x80029C70: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80029C74: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80029C78: jal         0x80018EF4
    // 0x80029C7C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    zmemcpy(rdram, ctx);
        goto after_3;
    // 0x80029C7C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80029C80: addu        $s4, $s4, $s0
    ctx->r20 = ADD32(ctx->r20, ctx->r16);
    // 0x80029C84: addu        $s1, $s1, $s0
    ctx->r17 = ADD32(ctx->r17, ctx->r16);
L_80029C88:
    // 0x80029C88: addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
    // 0x80029C8C: sw          $s4, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r20;
    // 0x80029C90: sw          $s1, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r17;
    // 0x80029C94: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80029C98: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x80029C9C: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80029CA0: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80029CA4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80029CA8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80029CAC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80029CB0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80029CB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80029CB8: jr          $ra
    // 0x80029CBC: nop

    return;
    // 0x80029CBC: nop

    // 0x80029CC0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80029CC4: addiu       $v0, $v0, 0xB18
    ctx->r2 = ADD32(ctx->r2, 0XB18);
    // 0x80029CC8: jr          $ra
    // 0x80029CCC: nop

    return;
    // 0x80029CCC: nop

;}
RECOMP_FUNC void zcalloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029CD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80029CD4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80029CD8: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x80029CDC: jal         0x8000527C
    // 0x80029CE0: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    rs_zcalloc(rdram, ctx);
        goto after_0;
    // 0x80029CE0: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    after_0:
    // 0x80029CE4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80029CE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80029CEC: jr          $ra
    // 0x80029CF0: nop

    return;
    // 0x80029CF0: nop

;}
RECOMP_FUNC void zcfree(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029CF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80029CF8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80029CFC: jal         0x8000525C
    // 0x80029D00: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    rs_zcfree(rdram, ctx);
        goto after_0;
    // 0x80029D00: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    after_0:
    // 0x80029D04: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80029D08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80029D0C: jr          $ra
    // 0x80029D10: nop

    return;
    // 0x80029D10: nop

;}
RECOMP_FUNC void fake_func_80029D14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029D14: lwc1        $f2, 0x1D2C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X1D2C);
    // 0x80029D18: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80029D1C: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
;}
