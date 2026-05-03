#include "recomp.h"
#include "funcs.h"
#include <stdio.h>

RECOMP_FUNC void loadSpeechFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BA38: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8009BA3C: lbu         $v0, 0x5121($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5121);
    // 0x8009BA40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009BA44: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8009BA48: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8009BA4C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009BA50: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8009BA54: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009BA58: beq         $v0, $zero, L_8009BB80
    if (ctx->r2 == 0) {
        // 0x8009BA5C: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8009BB80;
    }
    // 0x8009BA5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009BA60: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8009BA64: lw          $a0, 0x467C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X467C);
    // 0x8009BA68: beq         $a0, $zero, L_8009BA8C
    if (ctx->r4 == 0) {
        // 0x8009BA6C: lui         $v0, 0xF000
        ctx->r2 = S32(0XF000 << 16);
            goto L_8009BA8C;
    }
    // 0x8009BA6C: lui         $v0, 0xF000
    ctx->r2 = S32(0XF000 << 16);
    // 0x8009BA70: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8009BA74: lbu         $v0, 0x5120($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5120);
    // 0x8009BA78: beq         $v0, $zero, L_8009BA8C
    if (ctx->r2 == 0) {
        // 0x8009BA7C: lui         $v0, 0xF000
        ctx->r2 = S32(0XF000 << 16);
            goto L_8009BA8C;
    }
    // 0x8009BA7C: lui         $v0, 0xF000
    ctx->r2 = S32(0XF000 << 16);
    // 0x8009BA80: jal         0x80001C98
    // 0x8009BA84: nop

    rs_free(rdram, ctx);
        goto after_0;
    // 0x8009BA84: nop

    after_0:
    // 0x8009BA88: lui         $v0, 0xF000
    ctx->r2 = S32(0XF000 << 16);
L_8009BA8C:
    // 0x8009BA8C: and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // 0x8009BA90: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x8009BA94: beq         $v0, $v1, L_8009BB54
    if (ctx->r2 == ctx->r3) {
        // 0x8009BA98: addiu       $v0, $s1, 0x4
        ctx->r2 = ADD32(ctx->r17, 0X4);
            goto L_8009BB54;
    }
    // 0x8009BA98: addiu       $v0, $s1, 0x4
    ctx->r2 = ADD32(ctx->r17, 0X4);
    // 0x8009BA9C: jal         0x8000591C
    // 0x8009BAA0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8000591C(rdram, ctx);
        goto after_1;
    // 0x8009BAA0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x8009BAA4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009BAA8: sw          $v0, 0x4684($at)
    MEM_W(0X4684, ctx->r1) = ctx->r2;
    // 0x8009BAAC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8009BAB0: jal         0x80001ACC
    // 0x8009BAB4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    rs_malloc(rdram, ctx);
        goto after_2;
    // 0x8009BAB4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
    // 0x8009BAB8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8009BABC: beq         $s0, $zero, L_8009BB80
    if (ctx->r16 == 0) {
        // 0x8009BAC0: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_8009BB80;
    }
    // 0x8009BAC0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8009BAC4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8009BAC8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8009BACC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8009BAD0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8009BAD4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8009BAD8: jal         0x80004E70
    // 0x8009BADC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_80004E70(rdram, ctx);
        goto after_3;
    // 0x8009BADC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_3:
    // 0x8009BAE0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009BAE4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009BAE8: sw          $v0, 0x4670($at)
    MEM_W(0X4670, ctx->r1) = ctx->r2;
    // 0x8009BAEC: jal         0x80001C98
    // 0x8009BAF0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    rs_free(rdram, ctx);
        goto after_4;
    // 0x8009BAF0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x8009BAF4: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8009BAF8: lw          $a0, 0x4670($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4670);
    // 0x8009BAFC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8009BB00: jal         0x80001ACC
    // 0x8009BB04: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    rs_malloc(rdram, ctx);
        goto after_5;
    // 0x8009BB04: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_5:
    // 0x8009BB08: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8009BB0C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009BB10: sw          $v1, 0x467C($at)
    MEM_W(0X467C, ctx->r1) = ctx->r3;
    // 0x8009BB14: beq         $v1, $zero, L_8009BB80
    if (ctx->r3 == 0) {
        // 0x8009BB18: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_8009BB80;
    }
    // 0x8009BB18: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8009BB1C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8009BB20: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8009BB24: lw          $v0, 0x4670($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4670);
    // 0x8009BB28: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8009BB2C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8009BB30: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x8009BB34: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009BB38: jal         0x80004E70
    // 0x8009BB3C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80004E70(rdram, ctx);
        goto after_6;
    // 0x8009BB3C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_6:
    // 0x8009BB40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8009BB44: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8009BB48: sb          $v0, 0x5120($at)
    MEM_B(0X5120, ctx->r1) = ctx->r2;
    // 0x8009BB4C: j           L_8009BB84
    // 0x8009BB50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8009BB84;
    // 0x8009BB50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8009BB54:
    // 0x8009BB54: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009BB58: sw          $s1, 0x4684($at)
    MEM_W(0X4684, ctx->r1) = ctx->r17;
    // 0x8009BB5C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009BB60: sw          $v0, 0x467C($at)
    MEM_W(0X467C, ctx->r1) = ctx->r2;
    // 0x8009BB64: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8009BB68: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8009BB6C: sb          $zero, 0x5120($at)
    MEM_B(0X5120, ctx->r1) = 0;
    // 0x8009BB70: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009BB74: sw          $v0, 0x4670($at)
    MEM_W(0X4670, ctx->r1) = ctx->r2;
    // 0x8009BB78: j           L_8009BB84
    // 0x8009BB7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8009BB84;
    // 0x8009BB7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8009BB80:
    // 0x8009BB80: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8009BB84:
    // 0x8009BB84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009BB88: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8009BB8C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8009BB90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009BB94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8009BB98: jr          $ra
    // 0x8009BB9C: nop

    return;
    // 0x8009BB9C: nop

;}
RECOMP_FUNC void func_8009BBA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BBA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009BBA4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009BBA8: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8009BBAC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8009BBB0: lui         $s1, 0x8015
    ctx->r17 = S32(0X8015 << 16);
    // 0x8009BBB4: addiu       $s1, $s1, 0x3420
    ctx->r17 = ADD32(ctx->r17, 0X3420);
    // 0x8009BBB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009BBBC: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8009BBC0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009BBC4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009BBC8: sw          $zero, 0x467C($at)
    MEM_W(0X467C, ctx->r1) = 0;
L_8009BBCC:
    // 0x8009BBCC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8009BBD0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8009BBD4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8009BBD8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8009BBDC: jal         0x8009BE40
    // 0x8009BBE0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8009BE40(rdram, ctx);
        goto after_0;
    // 0x8009BBE0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x8009BBE4: addiu       $s1, $s1, 0x1228
    ctx->r17 = ADD32(ctx->r17, 0X1228);
    // 0x8009BBE8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009BBEC: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009BBF0: sb          $zero, 0x4620($at)
    MEM_B(0X4620, ctx->r1) = 0;
    // 0x8009BBF4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8009BBF8: blez        $s2, L_8009BBCC
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8009BBFC: addiu       $s0, $s0, 0x1228
        ctx->r16 = ADD32(ctx->r16, 0X1228);
            goto L_8009BBCC;
    }
    // 0x8009BBFC: addiu       $s0, $s0, 0x1228
    ctx->r16 = ADD32(ctx->r16, 0X1228);
    // 0x8009BC00: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8009BC04: addiu       $a0, $a0, 0x4650
    ctx->r4 = ADD32(ctx->r4, 0X4650);
    // 0x8009BC08: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8009BC0C: addiu       $a1, $a1, 0x4668
    ctx->r5 = ADD32(ctx->r5, 0X4668);
    // 0x8009BC10: jal         0x8002B300
    // 0x8009BC14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x8009BC14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8009BC18: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8009BC1C: addiu       $a0, $a0, 0x4650
    ctx->r4 = ADD32(ctx->r4, 0X4650);
    // 0x8009BC20: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8009BC24: jal         0x80033410
    // 0x8009BC28: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8009BC28: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_2:
    // 0x8009BC2C: jal         0x800981E4
    // 0x8009BC30: addiu       $a0, $zero, 0x10E0
    ctx->r4 = ADD32(0, 0X10E0);
    func_800981E4(rdram, ctx);
        goto after_3;
    // 0x8009BC30: addiu       $a0, $zero, 0x10E0
    ctx->r4 = ADD32(0, 0X10E0);
    after_3:
    // 0x8009BC34: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8009BC38: jal         0x80001ACC
    // 0x8009BC3C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_4;
    // 0x8009BC3C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_4:
    // 0x8009BC40: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8009BC44: addiu       $a0, $a0, -0x4A58
    ctx->r4 = ADD32(ctx->r4, -0X4A58);
    // 0x8009BC48: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009BC4C: sw          $v0, 0x4674($at)
    MEM_W(0X4674, ctx->r1) = ctx->r2;
    // 0x8009BC50: jal         0x80007910
    // 0x8009BC54: nop

    func_80007910(rdram, ctx);
        goto after_5;
    // 0x8009BC54: nop

    after_5:
    // 0x8009BC58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8009BC5C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8009BC60: sb          $v0, 0x5121($at)
    MEM_B(0X5121, ctx->r1) = ctx->r2;
    // 0x8009BC64: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009BC68: sw          $zero, 0x4648($at)
    MEM_W(0X4648, ctx->r1) = 0;
    // 0x8009BC6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009BC70: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8009BC74: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8009BC78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009BC7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8009BC80: jr          $ra
    // 0x8009BC84: nop

    return;
    // 0x8009BC84: nop

;}
RECOMP_FUNC void func_8009BC88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BC88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8009BC8C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8009BC90:
    // 0x8009BC90: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8009BC94:
    // 0x8009BC94: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009BC98: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8009BC9C: lbu         $v0, 0x4620($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X4620);
    // 0x8009BCA0: bne         $v0, $zero, L_8009BCB4
    if (ctx->r2 != 0) {
        // 0x8009BCA4: nop
    
            goto L_8009BCB4;
    }
    // 0x8009BCA4: nop

    // 0x8009BCA8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8009BCAC: blez        $a0, L_8009BC94
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8009BCB0: addiu       $v1, $v1, 0x1228
        ctx->r3 = ADD32(ctx->r3, 0X1228);
            goto L_8009BC94;
    }
    // 0x8009BCB0: addiu       $v1, $v1, 0x1228
    ctx->r3 = ADD32(ctx->r3, 0X1228);
L_8009BCB4:
    // 0x8009BCB4: bnel        $a0, $a1, L_8009BC90
    if (ctx->r4 != ctx->r5) {
        // 0x8009BCB8: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8009BC90;
    }
    goto skip_0;
    // 0x8009BCB8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_0:
    // 0x8009BCBC: jr          $ra
    // 0x8009BCC0: nop

    return;
    // 0x8009BCC0: nop

;}
RECOMP_FUNC void func_8009BCC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BCC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009BCC8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8009BCCC: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8009BCD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
L_8009BCD4:
    // 0x8009BCD4: jal         0x8009B268
    // 0x8009BCD8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8009B268(rdram, ctx);
        goto after_0;
    // 0x8009BCD8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8009BCDC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009BCE0: blez        $s0, L_8009BCD4
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8009BCE4: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8009BCD4;
    }
    // 0x8009BCE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8009BCE8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8009BCEC:
    // 0x8009BCEC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8009BCF0:
    // 0x8009BCF0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009BCF4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8009BCF8: lbu         $v0, 0x4620($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X4620);
    // 0x8009BCFC: bne         $v0, $zero, L_8009BD10
    if (ctx->r2 != 0) {
        // 0x8009BD00: nop
    
            goto L_8009BD10;
    }
    // 0x8009BD00: nop

    // 0x8009BD04: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8009BD08: blez        $a0, L_8009BCF0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8009BD0C: addiu       $v1, $v1, 0x1228
        ctx->r3 = ADD32(ctx->r3, 0X1228);
            goto L_8009BCF0;
    }
    // 0x8009BD0C: addiu       $v1, $v1, 0x1228
    ctx->r3 = ADD32(ctx->r3, 0X1228);
L_8009BD10:
    // 0x8009BD10: bne         $a0, $a1, L_8009BCEC
    if (ctx->r4 != ctx->r5) {
        // 0x8009BD14: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8009BCEC;
    }
    // 0x8009BD14: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8009BD18: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8009BD1C: addiu       $a0, $a0, -0x4A58
    ctx->r4 = ADD32(ctx->r4, -0X4A58);
    // 0x8009BD20: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8009BD24: sb          $zero, 0x5121($at)
    MEM_B(0X5121, ctx->r1) = 0;
    // 0x8009BD28: jal         0x8000794C
    // 0x8009BD2C: nop

    func_8000794C(rdram, ctx);
        goto after_1;
    // 0x8009BD2C: nop

    after_1:
    // 0x8009BD30: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8009BD34: lw          $a0, 0x467C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X467C);
    // 0x8009BD38: beq         $a0, $zero, L_8009BD58
    if (ctx->r4 == 0) {
        // 0x8009BD3C: nop
    
            goto L_8009BD58;
    }
    // 0x8009BD3C: nop

    // 0x8009BD40: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8009BD44: lbu         $v0, 0x5120($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5120);
    // 0x8009BD48: beq         $v0, $zero, L_8009BD58
    if (ctx->r2 == 0) {
        // 0x8009BD4C: nop
    
            goto L_8009BD58;
    }
    // 0x8009BD4C: nop

    // 0x8009BD50: jal         0x80001C98
    // 0x8009BD54: nop

    rs_free(rdram, ctx);
        goto after_2;
    // 0x8009BD54: nop

    after_2:
L_8009BD58:
    // 0x8009BD58: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8009BD5C: lw          $a0, 0x4674($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4674);
    // 0x8009BD60: jal         0x80001C98
    // 0x8009BD64: nop

    rs_free(rdram, ctx);
        goto after_3;
    // 0x8009BD64: nop

    after_3:
    // 0x8009BD68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009BD6C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8009BD70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009BD74: jr          $ra
    // 0x8009BD78: nop

    return;
    // 0x8009BD78: nop

;}
RECOMP_FUNC void func_8009BD7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BD7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009BD80: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8009BD84: lbu         $v0, 0x5121($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5121);
    // 0x8009BD88: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8009BD8C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8009BD90: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8009BD94: beq         $v0, $zero, L_8009BDEC
    if (ctx->r2 == 0) {
        // 0x8009BD98: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_8009BDEC;
    }
    // 0x8009BD98: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8009BD9C: sll         $s0, $v1, 3
    ctx->r16 = S32(ctx->r3 << 3);
    // 0x8009BDA0: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // 0x8009BDA4: sll         $s0, $s0, 4
    ctx->r16 = S32(ctx->r16 << 4);
    // 0x8009BDA8: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // 0x8009BDAC: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x8009BDB0: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // 0x8009BDB4: sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16 << 3);
    // 0x8009BDB8: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8009BDBC: addiu       $a0, $a0, 0x3420
    ctx->r4 = ADD32(ctx->r4, 0X3420);
    // 0x8009BDC0: addu        $s1, $a1, $a3
    ctx->r17 = ADD32(ctx->r5, ctx->r7);
    // 0x8009BDC4: addu        $a0, $s0, $a0
    ctx->r4 = ADD32(ctx->r16, ctx->r4);
    // 0x8009BDC8: jal         0x8009C240
    // 0x8009BDCC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8009C240(rdram, ctx);
        goto after_0;
    // 0x8009BDCC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_0:
    // 0x8009BDD0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009BDD4: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009BDD8: lw          $v0, 0x463C($at)
    ctx->r2 = MEM_W(ctx->r1, 0X463C);
    // 0x8009BDDC: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x8009BDE0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009BDE4: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009BDE8: sw          $v0, 0x463C($at)
    MEM_W(0X463C, ctx->r1) = ctx->r2;
L_8009BDEC:
    // 0x8009BDEC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8009BDF0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8009BDF4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8009BDF8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8009BDFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009BE00: jr          $ra
    // 0x8009BE04: nop

    return;
    // 0x8009BE04: nop

;}
RECOMP_FUNC void func_8009BE08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BE08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009BE0C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8009BE10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009BE14: jal         0x80005200
    // 0x8009BE18: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    func_80005200(rdram, ctx);
        goto after_0;
    // 0x8009BE18: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    after_0:
    // 0x8009BE1C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8009BE20: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8009BE24: jal         0x80033410
    // 0x8009BE28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8009BE28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8009BE2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009BE30: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8009BE34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009BE38: jr          $ra
    // 0x8009BE3C: nop

    return;
    // 0x8009BE3C: nop

;}
RECOMP_FUNC void func_8009BE40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BE40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009BE44: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8009BE48: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x8009BE4C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8009BE50: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x8009BE54: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8009BE58: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x8009BE5C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8009BE60: addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // 0x8009BE64: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8009BE68: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8009BE6C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009BE70: jal         0x8002A080
    // 0x8009BE74: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    bzero_recomp(rdram, ctx);
        goto after_0;
    // 0x8009BE74: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    after_0:
    // 0x8009BE78: addiu       $a0, $s4, 0x11AC
    ctx->r4 = ADD32(ctx->r20, 0X11AC);
    // 0x8009BE7C: addiu       $a1, $s4, 0x11C4
    ctx->r5 = ADD32(ctx->r20, 0X11C4);
    // 0x8009BE80: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x8009BE84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8009BE88: sh          $v0, 0x166($s4)
    MEM_H(0X166, ctx->r20) = ctx->r2;
    // 0x8009BE8C: sw          $s0, 0x194($s4)
    MEM_W(0X194, ctx->r20) = ctx->r16;
    // 0x8009BE90: sw          $s2, 0x198($s4)
    MEM_W(0X198, ctx->r20) = ctx->r18;
    // 0x8009BE94: sw          $s3, 0x19C($s4)
    MEM_W(0X19C, ctx->r20) = ctx->r19;
    // 0x8009BE98: sw          $zero, 0x11A8($s4)
    MEM_W(0X11A8, ctx->r20) = 0;
    // 0x8009BE9C: jal         0x8002B300
    // 0x8009BEA0: sw          $s1, 0x190($s4)
    MEM_W(0X190, ctx->r20) = ctx->r17;
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x8009BEA0: sw          $s1, 0x190($s4)
    MEM_W(0X190, ctx->r20) = ctx->r17;
    after_1:
    // 0x8009BEA4: sltiu       $s0, $s0, 0x1
    ctx->r16 = ctx->r16 < 0X1 ? 1 : 0;
    // 0x8009BEA8: sltiu       $s1, $s1, 0x1
    ctx->r17 = ctx->r17 < 0X1 ? 1 : 0;
    // 0x8009BEAC: or          $s0, $s0, $s1
    ctx->r16 = ctx->r16 | ctx->r17;
    // 0x8009BEB0: beq         $s0, $zero, L_8009BEC0
    if (ctx->r16 == 0) {
        // 0x8009BEB4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8009BEC0;
    }
    // 0x8009BEB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8009BEB8: j           L_8009BEC4
    // 0x8009BEBC: sb          $zero, 0x11DD($s4)
    MEM_B(0X11DD, ctx->r20) = 0;
        goto L_8009BEC4;
    // 0x8009BEBC: sb          $zero, 0x11DD($s4)
    MEM_B(0X11DD, ctx->r20) = 0;
L_8009BEC0:
    // 0x8009BEC0: sb          $v0, 0x11DD($s4)
    MEM_B(0X11DD, ctx->r20) = ctx->r2;
L_8009BEC4:
    // 0x8009BEC4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8009BEC8: sb          $zero, 0x11DC($s4)
    MEM_B(0X11DC, ctx->r20) = 0;
    // 0x8009BECC: sh          $zero, 0x11A2($s4)
    MEM_H(0X11A2, ctx->r20) = 0;
    // 0x8009BED0: sw          $zero, 0x11A4($s4)
    MEM_W(0X11A4, ctx->r20) = 0;
    // 0x8009BED4: sh          $zero, 0x11A0($s4)
    MEM_H(0X11A0, ctx->r20) = 0;
    // 0x8009BED8: sw          $zero, 0x11C8($s4)
    MEM_W(0X11C8, ctx->r20) = 0;
    // 0x8009BEDC: sw          $zero, 0x11D0($s4)
    MEM_W(0X11D0, ctx->r20) = 0;
    // 0x8009BEE0: sw          $zero, 0x11CC($s4)
    MEM_W(0X11CC, ctx->r20) = 0;
    // 0x8009BEE4: sw          $zero, 0x11D8($s4)
    MEM_W(0X11D8, ctx->r20) = 0;
    // 0x8009BEE8: sw          $zero, 0x11D4($s4)
    MEM_W(0X11D4, ctx->r20) = 0;
    // 0x8009BEEC: sb          $v0, 0x11DE($s4)
    MEM_B(0X11DE, ctx->r20) = ctx->r2;
    // 0x8009BEF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009BEF4: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8009BEF8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8009BEFC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8009BF00: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8009BF04: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8009BF08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8009BF0C: jr          $ra
    // 0x8009BF10: nop

    return;
    // 0x8009BF10: nop

;}
RECOMP_FUNC void func_8009BF14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BF14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009BF18: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8009BF1C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8009BF20: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8009BF24: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8009BF28: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8009BF2C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8009BF30: lbu         $v0, 0x11DC($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X11DC);
    // 0x8009BF34: lbu         $s1, 0x11DE($s0)
    ctx->r17 = MEM_BU(ctx->r16, 0X11DE);
    // 0x8009BF38: beq         $v0, $zero, L_8009BFBC
    if (ctx->r2 == 0) {
        // 0x8009BF3C: addiu       $a0, $s0, 0x11AC
        ctx->r4 = ADD32(ctx->r16, 0X11AC);
            goto L_8009BFBC;
    }
    // 0x8009BF3C: addiu       $a0, $s0, 0x11AC
    ctx->r4 = ADD32(ctx->r16, 0X11AC);
    // 0x8009BF40: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8009BF44: jal         0x800331D0
    // 0x8009BF48: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8009BF48: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x8009BF4C: bltz        $v0, L_8009BFB0
    if (SIGNED(ctx->r2) < 0) {
        // 0x8009BF50: nop
    
            goto L_8009BFB0;
    }
    // 0x8009BF50: nop

    // 0x8009BF54: lw          $v0, 0x11D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X11D0);
    // 0x8009BF58: bne         $v0, $zero, L_8009BF8C
    if (ctx->r2 != 0) {
        // 0x8009BF5C: lui         $a2, 0xFF
        ctx->r6 = S32(0XFF << 16);
            goto L_8009BF8C;
    }
    // 0x8009BF5C: lui         $a2, 0xFF
    ctx->r6 = S32(0XFF << 16);
    // 0x8009BF60: lhu         $a0, 0x1A4($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1A4);
    // 0x8009BF64: lw          $a1, 0x1A4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1A4);
    // 0x8009BF68: lw          $v1, 0x1A8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1A8);
    // 0x8009BF6C: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x8009BF70: addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // 0x8009BF74: sw          $v0, 0x11C8($s0)
    MEM_W(0X11C8, ctx->r16) = ctx->r2;
    // 0x8009BF78: and         $v1, $v1, $a2
    ctx->r3 = ctx->r3 & ctx->r6;
    // 0x8009BF7C: sh          $a0, 0x11A0($s0)
    MEM_H(0X11A0, ctx->r16) = ctx->r4;
    // 0x8009BF80: sh          $a1, 0x11A2($s0)
    MEM_H(0X11A2, ctx->r16) = ctx->r5;
    // 0x8009BF84: sw          $v1, 0x11A4($s0)
    MEM_W(0X11A4, ctx->r16) = ctx->r3;
    // 0x8009BF88: lw          $v0, 0x11D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X11D0);
L_8009BF8C:
    // 0x8009BF8C: lw          $v1, 0x11A4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X11A4);
    // 0x8009BF90: addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
    // 0x8009BF94: sw          $v0, 0x11D0($s0)
    MEM_W(0X11D0, ctx->r16) = ctx->r2;
    // 0x8009BF98: sltiu       $v0, $v1, 0x101
    ctx->r2 = ctx->r3 < 0X101 ? 1 : 0;
    // 0x8009BF9C: bnel        $v0, $zero, L_8009BFAC
    if (ctx->r2 != 0) {
        // 0x8009BFA0: sw          $zero, 0x11A4($s0)
        MEM_W(0X11A4, ctx->r16) = 0;
            goto L_8009BFAC;
    }
    goto skip_0;
    // 0x8009BFA0: sw          $zero, 0x11A4($s0)
    MEM_W(0X11A4, ctx->r16) = 0;
    skip_0:
    // 0x8009BFA4: addiu       $v0, $v1, -0x100
    ctx->r2 = ADD32(ctx->r3, -0X100);
    // 0x8009BFA8: sw          $v0, 0x11A4($s0)
    MEM_W(0X11A4, ctx->r16) = ctx->r2;
L_8009BFAC:
    // 0x8009BFAC: sb          $zero, 0x11DC($s0)
    MEM_B(0X11DC, ctx->r16) = 0;
L_8009BFB0:
    // 0x8009BFB0: lbu         $v0, 0x11DC($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X11DC);
    // 0x8009BFB4: bne         $v0, $zero, L_8009C048
    if (ctx->r2 != 0) {
        // 0x8009BFB8: nop
    
            goto L_8009C048;
    }
    // 0x8009BFB8: nop

L_8009BFBC:
    // 0x8009BFBC: lbu         $v1, 0x11DD($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X11DD);
    // 0x8009BFC0: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x8009BFC4: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8009BFC8: bne         $v0, $zero, L_8009BFDC
    if (ctx->r2 != 0) {
        // 0x8009BFCC: andi        $v1, $v1, 0xFF
        ctx->r3 = ctx->r3 & 0XFF;
            goto L_8009BFDC;
    }
    // 0x8009BFCC: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8009BFD0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8009BFD4: bne         $v1, $v0, L_8009C048
    if (ctx->r3 != ctx->r2) {
        // 0x8009BFD8: nop
    
            goto L_8009C048;
    }
    // 0x8009BFD8: nop

L_8009BFDC:
    // 0x8009BFDC: lw          $v1, 0x11D0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X11D0);
    // 0x8009BFE0: lw          $v0, 0x11CC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X11CC);
    // 0x8009BFE4: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x8009BFE8: sltiu       $v0, $v0, 0xC01
    ctx->r2 = ctx->r2 < 0XC01 ? 1 : 0;
    // 0x8009BFEC: beq         $v0, $zero, L_8009C048
    if (ctx->r2 == 0) {
        // 0x8009BFF0: nop
    
            goto L_8009C048;
    }
    // 0x8009BFF0: nop

    // 0x8009BFF4: bne         $v1, $zero, L_8009C004
    if (ctx->r3 != 0) {
        // 0x8009BFF8: nop
    
            goto L_8009C004;
    }
    // 0x8009BFF8: nop

    // 0x8009BFFC: j           L_8009C018
    // 0x8009C000: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
        goto L_8009C018;
    // 0x8009C000: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
L_8009C004:
    // 0x8009C004: lw          $v1, 0x11A4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X11A4);
    // 0x8009C008: sltiu       $v0, $v1, 0x101
    ctx->r2 = ctx->r3 < 0X101 ? 1 : 0;
    // 0x8009C00C: beq         $v0, $zero, L_8009C018
    if (ctx->r2 == 0) {
        // 0x8009C010: addiu       $a2, $zero, 0x400
        ctx->r6 = ADD32(0, 0X400);
            goto L_8009C018;
    }
    // 0x8009C010: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    // 0x8009C014: sll         $a2, $v1, 2
    ctx->r6 = S32(ctx->r3 << 2);
L_8009C018:
    // 0x8009C018: blez        $a2, L_8009C048
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8009C01C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8009C048;
    }
    // 0x8009C01C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8009C020: lw          $a0, 0x194($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X194);
    // 0x8009C024: lw          $a1, 0x11D0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X11D0);
    // 0x8009C028: sb          $v0, 0x11DC($s0)
    MEM_B(0X11DC, ctx->r16) = ctx->r2;
    // 0x8009C02C: lw          $v0, 0x190($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X190);
    // 0x8009C030: addiu       $a3, $s0, 0x11AC
    ctx->r7 = ADD32(ctx->r16, 0X11AC);
    // 0x8009C034: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x8009C038: andi        $a1, $a1, 0xFF8
    ctx->r5 = ctx->r5 & 0XFF8;
    // 0x8009C03C: addiu       $a1, $a1, 0x1A0
    ctx->r5 = ADD32(ctx->r5, 0X1A0);
    // 0x8009C040: jalr        $v0
    // 0x8009C044: addu        $a1, $s0, $a1
    ctx->r5 = ADD32(ctx->r16, ctx->r5);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8009C044: addu        $a1, $s0, $a1
    ctx->r5 = ADD32(ctx->r16, ctx->r5);
    after_1:
L_8009C048:
    // 0x8009C048: lw          $v0, 0x11D8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X11D8);
    // 0x8009C04C: lw          $a0, 0x11D4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X11D4);
    // 0x8009C050: lw          $v1, 0x19C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X19C);
    // 0x8009C054: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8009C058: addiu       $v1, $v1, -0xA0
    ctx->r3 = ADD32(ctx->r3, -0XA0);
    // 0x8009C05C: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8009C060: beq         $v0, $zero, L_8009C144
    if (ctx->r2 == 0) {
        // 0x8009C064: nop
    
            goto L_8009C144;
    }
    // 0x8009C064: nop

    // 0x8009C068: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8009C06C: addiu       $s2, $zero, -0x4
    ctx->r18 = ADD32(0, -0X4);
L_8009C070:
    // 0x8009C070: lbu         $v0, 0x11DD($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X11DD);
    // 0x8009C074: beq         $v0, $s3, L_8009C088
    if (ctx->r2 == ctx->r19) {
        // 0x8009C078: nop
    
            goto L_8009C088;
    }
    // 0x8009C078: nop

    // 0x8009C07C: lhu         $v0, 0x11A0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X11A0);
    // 0x8009C080: beq         $v0, $zero, L_8009C144
    if (ctx->r2 == 0) {
        // 0x8009C084: nop
    
            goto L_8009C144;
    }
    // 0x8009C084: nop

L_8009C088:
    // 0x8009C088: lw          $v1, 0x11D0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X11D0);
    // 0x8009C08C: beq         $v1, $zero, L_8009C0A0
    if (ctx->r3 == 0) {
        // 0x8009C090: nop
    
            goto L_8009C0A0;
    }
    // 0x8009C090: nop

    // 0x8009C094: lw          $v0, 0x11A4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X11A4);
    // 0x8009C098: beq         $v0, $zero, L_8009C0B4
    if (ctx->r2 == 0) {
        // 0x8009C09C: nop
    
            goto L_8009C0B4;
    }
    // 0x8009C09C: nop

L_8009C0A0:
    // 0x8009C0A0: lw          $v0, 0x11CC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X11CC);
    // 0x8009C0A4: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x8009C0A8: sltiu       $v0, $v0, 0x25
    ctx->r2 = ctx->r2 < 0X25 ? 1 : 0;
    // 0x8009C0AC: bne         $v0, $zero, L_8009C144
    if (ctx->r2 != 0) {
        // 0x8009C0B0: nop
    
            goto L_8009C144;
    }
    // 0x8009C0B0: nop

L_8009C0B4:
    // 0x8009C0B4: blez        $s1, L_8009C144
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8009C0B8: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8009C144;
    }
    // 0x8009C0B8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8009C0BC: lw          $v1, 0x11D8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X11D8);
    // 0x8009C0C0: lw          $v0, 0x19C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X19C);
    // 0x8009C0C4: divu        $zero, $v1, $v0
    lo = S32(U32(ctx->r3) / U32(ctx->r2)); hi = S32(U32(ctx->r3) % U32(ctx->r2));
    // 0x8009C0C8: bne         $v0, $zero, L_8009C0D4
    if (ctx->r2 != 0) {
        // 0x8009C0CC: nop
    
            goto L_8009C0D4;
    }
    // 0x8009C0CC: nop

    // 0x8009C0D0: break       7
    do_break(2148122832);
L_8009C0D4:
    // 0x8009C0D4: mfhi        $a1
    ctx->r5 = hi;
    // 0x8009C0D8: lw          $v0, 0x198($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X198);
    // 0x8009C0DC: srl         $a1, $a1, 2
    ctx->r5 = S32(U32(ctx->r5) >> 2);
    // 0x8009C0E0: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x8009C0E4: jal         0x8009C904
    // 0x8009C0E8: addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    func_8009C904(rdram, ctx);
        goto after_2;
    // 0x8009C0E8: addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    after_2:
    // 0x8009C0EC: lhu         $a0, 0x11A0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X11A0);
    // 0x8009C0F0: lw          $v0, 0x11C8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X11C8);
    // 0x8009C0F4: lw          $v1, 0x11D8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X11D8);
    // 0x8009C0F8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8009C0FC: srl         $v0, $v0, 3
    ctx->r2 = S32(U32(ctx->r2) >> 3);
    // 0x8009C100: and         $v0, $v0, $s2
    ctx->r2 = ctx->r2 & ctx->r18;
    // 0x8009C104: addiu       $v1, $v1, 0xA0
    ctx->r3 = ADD32(ctx->r3, 0XA0);
    // 0x8009C108: sh          $a0, 0x11A0($s0)
    MEM_H(0X11A0, ctx->r16) = ctx->r4;
    // 0x8009C10C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8009C110: sw          $v0, 0x11CC($s0)
    MEM_W(0X11CC, ctx->r16) = ctx->r2;
    // 0x8009C114: bne         $a0, $zero, L_8009C124
    if (ctx->r4 != 0) {
        // 0x8009C118: sw          $v1, 0x11D8($s0)
        MEM_W(0X11D8, ctx->r16) = ctx->r3;
            goto L_8009C124;
    }
    // 0x8009C118: sw          $v1, 0x11D8($s0)
    MEM_W(0X11D8, ctx->r16) = ctx->r3;
    // 0x8009C11C: lw          $v0, 0x19C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X19C);
    // 0x8009C120: sw          $v0, 0x11A8($s0)
    MEM_W(0X11A8, ctx->r16) = ctx->r2;
L_8009C124:
    // 0x8009C124: lw          $v0, 0x11D8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X11D8);
    // 0x8009C128: lw          $a0, 0x11D4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X11D4);
    // 0x8009C12C: lw          $v1, 0x19C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X19C);
    // 0x8009C130: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8009C134: addiu       $v1, $v1, -0xA0
    ctx->r3 = ADD32(ctx->r3, -0XA0);
    // 0x8009C138: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8009C13C: bne         $v0, $zero, L_8009C070
    if (ctx->r2 != 0) {
        // 0x8009C140: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_8009C070;
    }
    // 0x8009C140: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8009C144:
    // 0x8009C144: lbu         $v0, 0x11DD($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X11DD);
    // 0x8009C148: addiu       $v0, $v0, -0x3
    ctx->r2 = ADD32(ctx->r2, -0X3);
    // 0x8009C14C: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8009C150: beq         $v0, $zero, L_8009C1EC
    if (ctx->r2 == 0) {
        // 0x8009C154: nop
    
            goto L_8009C1EC;
    }
    // 0x8009C154: nop

    // 0x8009C158: lhu         $v0, 0x11A0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X11A0);
    // 0x8009C15C: bne         $v0, $zero, L_8009C1EC
    if (ctx->r2 != 0) {
        // 0x8009C160: nop
    
            goto L_8009C1EC;
    }
    // 0x8009C160: nop

    // 0x8009C164: lw          $a0, 0x11D8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X11D8);
    // 0x8009C168: lw          $v0, 0x11D4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X11D4);
    // 0x8009C16C: lw          $a1, 0x19C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X19C);
    // 0x8009C170: subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // 0x8009C174: addiu       $v1, $a1, -0xA0
    ctx->r3 = ADD32(ctx->r5, -0XA0);
    // 0x8009C178: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8009C17C: slt         $v1, $zero, $s1
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8009C180: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8009C184: beq         $v0, $zero, L_8009C1EC
    if (ctx->r2 == 0) {
        // 0x8009C188: nop
    
            goto L_8009C1EC;
    }
    // 0x8009C188: nop

L_8009C18C:
    // 0x8009C18C: divu        $zero, $a0, $a1
    lo = S32(U32(ctx->r4) / U32(ctx->r5)); hi = S32(U32(ctx->r4) % U32(ctx->r5));
    // 0x8009C190: bne         $a1, $zero, L_8009C19C
    if (ctx->r5 != 0) {
        // 0x8009C194: nop
    
            goto L_8009C19C;
    }
    // 0x8009C194: nop

    // 0x8009C198: break       7
    do_break(2148123032);
L_8009C19C:
    // 0x8009C19C: mfhi        $a0
    ctx->r4 = hi;
    // 0x8009C1A0: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    // 0x8009C1A4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8009C1A8: lw          $v0, 0x198($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X198);
    // 0x8009C1AC: srl         $a0, $a0, 2
    ctx->r4 = S32(U32(ctx->r4) >> 2);
    // 0x8009C1B0: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x8009C1B4: jal         0x8002A080
    // 0x8009C1B8: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    bzero_recomp(rdram, ctx);
        goto after_3;
    // 0x8009C1B8: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_3:
    // 0x8009C1BC: lw          $v0, 0x11D8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X11D8);
    // 0x8009C1C0: lw          $a1, 0x19C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X19C);
    // 0x8009C1C4: lw          $v1, 0x11D4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X11D4);
    // 0x8009C1C8: addiu       $v0, $v0, 0xA0
    ctx->r2 = ADD32(ctx->r2, 0XA0);
    // 0x8009C1CC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8009C1D0: subu        $v1, $a0, $v1
    ctx->r3 = SUB32(ctx->r4, ctx->r3);
    // 0x8009C1D4: addiu       $v0, $a1, -0xA0
    ctx->r2 = ADD32(ctx->r5, -0XA0);
    // 0x8009C1D8: sltu        $v1, $v1, $v0
    ctx->r3 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8009C1DC: slt         $v0, $zero, $s1
    ctx->r2 = SIGNED(0) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8009C1E0: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8009C1E4: bne         $v1, $zero, L_8009C18C
    if (ctx->r3 != 0) {
        // 0x8009C1E8: sw          $a0, 0x11D8($s0)
        MEM_W(0X11D8, ctx->r16) = ctx->r4;
            goto L_8009C18C;
    }
    // 0x8009C1E8: sw          $a0, 0x11D8($s0)
    MEM_W(0X11D8, ctx->r16) = ctx->r4;
L_8009C1EC:
    // 0x8009C1EC: lbu         $v1, 0x11DD($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X11DD);
    // 0x8009C1F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8009C1F4: bne         $v1, $v0, L_8009C220
    if (ctx->r3 != ctx->r2) {
        // 0x8009C1F8: nop
    
            goto L_8009C220;
    }
    // 0x8009C1F8: nop

    // 0x8009C1FC: lw          $v0, 0x11D8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X11D8);
    // 0x8009C200: lw          $a0, 0x11D4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X11D4);
    // 0x8009C204: lw          $v1, 0x19C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X19C);
    // 0x8009C208: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8009C20C: addiu       $v1, $v1, -0x140
    ctx->r3 = ADD32(ctx->r3, -0X140);
    // 0x8009C210: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8009C214: bne         $v0, $zero, L_8009C220
    if (ctx->r2 != 0) {
        // 0x8009C218: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8009C220;
    }
    // 0x8009C218: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8009C21C: sb          $v0, 0x11DD($s0)
    MEM_B(0X11DD, ctx->r16) = ctx->r2;
L_8009C220:
    // 0x8009C220: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8009C224: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8009C228: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8009C22C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8009C230: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8009C234: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8009C238: jr          $ra
    // 0x8009C23C: nop

    return;
    // 0x8009C23C: nop

;}
RECOMP_FUNC void func_8009C240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C240: lbu         $v1, 0x11DD($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X11DD);
    // 0x8009C244: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8009C248: bne         $v1, $v0, L_8009C298
    if (ctx->r3 != ctx->r2) {
        // 0x8009C24C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8009C298;
    }
    // 0x8009C24C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8009C250: lw          $v0, 0x11A8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X11A8);
    // 0x8009C254: blez        $v0, L_8009C270
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8009C258: subu        $v0, $v0, $a1
        ctx->r2 = SUB32(ctx->r2, ctx->r5);
            goto L_8009C270;
    }
    // 0x8009C258: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x8009C25C: bgtz        $v0, L_8009C270
    if (SIGNED(ctx->r2) > 0) {
        // 0x8009C260: sw          $v0, 0x11A8($a0)
        MEM_W(0X11A8, ctx->r4) = ctx->r2;
            goto L_8009C270;
    }
    // 0x8009C260: sw          $v0, 0x11A8($a0)
    MEM_W(0X11A8, ctx->r4) = ctx->r2;
    // 0x8009C264: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8009C268: sb          $v0, 0x11DD($a0)
    MEM_B(0X11DD, ctx->r4) = ctx->r2;
    // 0x8009C26C: sw          $zero, 0x11A8($a0)
    MEM_W(0X11A8, ctx->r4) = 0;
L_8009C270:
    // 0x8009C270: lw          $v0, 0x11D8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X11D8);
    // 0x8009C274: lw          $a2, 0x11D4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X11D4);
    // 0x8009C278: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x8009C27C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8009C280: sltu        $v0, $a1, $v1
    ctx->r2 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x8009C284: bnel        $v0, $zero, L_8009C28C
    if (ctx->r2 != 0) {
        // 0x8009C288: addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
            goto L_8009C28C;
    }
    goto skip_0;
    // 0x8009C288: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    skip_0:
L_8009C28C:
    // 0x8009C28C: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
    // 0x8009C290: sw          $v0, 0x11D4($a0)
    MEM_W(0X11D4, ctx->r4) = ctx->r2;
    // 0x8009C294: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8009C298:
    // 0x8009C298: jr          $ra
    // 0x8009C29C: nop

    return;
    // 0x8009C29C: nop

;}
RECOMP_FUNC void func_8009C2A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C2A0: lbu         $v1, 0x11DD($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X11DD);
    // 0x8009C2A4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8009C2A8: bne         $v1, $v0, L_8009C2B4
    if (ctx->r3 != ctx->r2) {
        // 0x8009C2AC: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8009C2B4;
    }
    // 0x8009C2AC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8009C2B0: sb          $v0, 0x11DD($a0)
    MEM_B(0X11DD, ctx->r4) = ctx->r2;
L_8009C2B4:
    // 0x8009C2B4: jr          $ra
    // 0x8009C2B8: nop

    return;
    // 0x8009C2B8: nop

;}
RECOMP_FUNC void func_8009C2BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C2BC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8009C2C0: jr          $ra
    // 0x8009C2C4: sb          $v0, 0x11DD($a0)
    MEM_B(0X11DD, ctx->r4) = ctx->r2;
    return;
    // 0x8009C2C4: sb          $v0, 0x11DD($a0)
    MEM_B(0X11DD, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void fake_func_8009C2C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8009C2D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C2D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C2D4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8009C2D8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8009C2DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C2E0: lh          $t0, 0x188($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X188);
    // 0x8009C2E4: lh          $v0, 0x0($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X0);
    // 0x8009C2E8: lh          $a0, 0x4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X4);
    // 0x8009C2EC: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x8009C2F0: addiu       $t0, $t0, 0x168
    ctx->r8 = ADD32(ctx->r8, 0X168);
    // 0x8009C2F4: addu        $t0, $s0, $t0
    ctx->r8 = ADD32(ctx->r16, ctx->r8);
    // 0x8009C2F8: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
    // 0x8009C2FC: sll         $v1, $v0, 10
    ctx->r3 = S32(ctx->r2 << 10);
    // 0x8009C300: sll         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2 << 11);
    // 0x8009C304: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8009C308: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x8009C30C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8009C310: sll         $v1, $v0, 8
    ctx->r3 = S32(ctx->r2 << 8);
    // 0x8009C314: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8009C318: addiu       $v0, $v0, 0x4000
    ctx->r2 = ADD32(ctx->r2, 0X4000);
    // 0x8009C31C: lh          $v1, 0x2($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X2);
    // 0x8009C320: sra         $v0, $v0, 15
    ctx->r2 = S32(SIGNED(ctx->r2) >> 15);
    // 0x8009C324: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8009C328: sll         $a0, $a0, 10
    ctx->r4 = S32(ctx->r4 << 10);
    // 0x8009C32C: addiu       $a0, $a0, -0x5000
    ctx->r4 = ADD32(ctx->r4, -0X5000);
    // 0x8009C330: sh          $v0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r2;
    // 0x8009C334: addiu       $v1, $v1, -0x20
    ctx->r3 = ADD32(ctx->r3, -0X20);
    // 0x8009C338: sll         $v0, $v1, 10
    ctx->r2 = S32(ctx->r3 << 10);
    // 0x8009C33C: sll         $v1, $v1, 11
    ctx->r3 = S32(ctx->r3 << 11);
    // 0x8009C340: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8009C344: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8009C348: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8009C34C: sll         $v0, $v1, 8
    ctx->r2 = S32(ctx->r3 << 8);
    // 0x8009C350: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8009C354: addiu       $v1, $v1, 0x4000
    ctx->r3 = ADD32(ctx->r3, 0X4000);
    // 0x8009C358: sra         $v1, $v1, 15
    ctx->r3 = S32(SIGNED(ctx->r3) >> 15);
    // 0x8009C35C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8009C360: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8009C364: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8009C368: sh          $v1, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r3;
    // 0x8009C36C: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x8009C370: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8009C374: sll         $v1, $v0, 8
    ctx->r3 = S32(ctx->r2 << 8);
    // 0x8009C378: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8009C37C: addiu       $v0, $v0, 0x4000
    ctx->r2 = ADD32(ctx->r2, 0X4000);
    // 0x8009C380: lh          $v1, 0x6($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X6);
    // 0x8009C384: lh          $a0, 0x8($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X8);
    // 0x8009C388: sra         $v0, $v0, 15
    ctx->r2 = S32(SIGNED(ctx->r2) >> 15);
    // 0x8009C38C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8009C390: sh          $v0, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r2;
    // 0x8009C394: sll         $v1, $v1, 10
    ctx->r3 = S32(ctx->r3 << 10);
    // 0x8009C398: addiu       $v1, $v1, -0x2C00
    ctx->r3 = ADD32(ctx->r3, -0X2C00);
    // 0x8009C39C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8009C3A0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8009C3A4: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x8009C3A8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8009C3AC: sll         $v1, $v0, 8
    ctx->r3 = S32(ctx->r2 << 8);
    // 0x8009C3B0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8009C3B4: addiu       $v0, $v0, 0x4000
    ctx->r2 = ADD32(ctx->r2, 0X4000);
    // 0x8009C3B8: sra         $v0, $v0, 15
    ctx->r2 = S32(SIGNED(ctx->r2) >> 15);
    // 0x8009C3BC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8009C3C0: sll         $a0, $a0, 10
    ctx->r4 = S32(ctx->r4 << 10);
    // 0x8009C3C4: addiu       $a0, $a0, -0x20BC
    ctx->r4 = ADD32(ctx->r4, -0X20BC);
    // 0x8009C3C8: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8009C3CC: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8009C3D0: sh          $v0, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r2;
    // 0x8009C3D4: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8009C3D8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8009C3DC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8009C3E0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8009C3E4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009C3E8: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8009C3EC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8009C3F0: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8009C3F4: addiu       $v0, $v0, 0x4000
    ctx->r2 = ADD32(ctx->r2, 0X4000);
    // 0x8009C3F8: lh          $v1, 0xA($a1)
    ctx->r3 = MEM_H(ctx->r5, 0XA);
    // 0x8009C3FC: sra         $v0, $v0, 15
    ctx->r2 = S32(SIGNED(ctx->r2) >> 15);
    // 0x8009C400: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8009C404: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8009C408: sh          $v0, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r2;
    // 0x8009C40C: sll         $v1, $v1, 10
    ctx->r3 = S32(ctx->r3 << 10);
    // 0x8009C410: addiu       $v1, $v1, -0x1200
    ctx->r3 = ADD32(ctx->r3, -0X1200);
    // 0x8009C414: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8009C418: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8009C41C: sll         $v1, $v0, 8
    ctx->r3 = S32(ctx->r2 << 8);
    // 0x8009C420: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8009C424: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009C428: addiu       $v0, $v0, 0x4000
    ctx->r2 = ADD32(ctx->r2, 0X4000);
    // 0x8009C42C: lh          $v1, 0xC($a1)
    ctx->r3 = MEM_H(ctx->r5, 0XC);
    // 0x8009C430: sra         $v0, $v0, 15
    ctx->r2 = S32(SIGNED(ctx->r2) >> 15);
    // 0x8009C434: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8009C438: sh          $v0, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r2;
    // 0x8009C43C: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8009C440: sll         $v1, $v1, 10
    ctx->r3 = S32(ctx->r3 << 10);
    // 0x8009C444: addiu       $v1, $v1, 0x2AA
    ctx->r3 = ADD32(ctx->r3, 0X2AA);
    // 0x8009C448: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
    // 0x8009C44C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8009C450: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009C454: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8009C458: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8009C45C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8009C460: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8009C464: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8009C468: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8009C46C: addiu       $v0, $v0, 0x4000
    ctx->r2 = ADD32(ctx->r2, 0X4000);
    // 0x8009C470: lh          $v1, 0xE($a1)
    ctx->r3 = MEM_H(ctx->r5, 0XE);
    // 0x8009C474: sra         $v0, $v0, 15
    ctx->r2 = S32(SIGNED(ctx->r2) >> 15);
    // 0x8009C478: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8009C47C: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // 0x8009C480: addu        $a2, $a3, $zero
    ctx->r6 = ADD32(ctx->r7, 0);
    // 0x8009C484: sh          $v0, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r2;
    // 0x8009C488: sll         $v1, $v1, 10
    ctx->r3 = S32(ctx->r3 << 10);
    // 0x8009C48C: addiu       $v1, $v1, -0x710
    ctx->r3 = ADD32(ctx->r3, -0X710);
    // 0x8009C490: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x8009C494: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8009C498: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009C49C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8009C4A0: sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2 << 6);
    // 0x8009C4A4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8009C4A8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009C4AC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8009C4B0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009C4B4: addiu       $v0, $v0, 0x4000
    ctx->r2 = ADD32(ctx->r2, 0X4000);
    // 0x8009C4B8: sra         $v0, $v0, 15
    ctx->r2 = S32(SIGNED(ctx->r2) >> 15);
    // 0x8009C4BC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8009C4C0: jal         0x8009DB44
    // 0x8009C4C4: sh          $v0, 0xE($t0)
    MEM_H(0XE, ctx->r8) = ctx->r2;
    func_8009DB44(rdram, ctx);
        goto after_0;
    // 0x8009C4C4: sh          $v0, 0xE($t0)
    MEM_H(0XE, ctx->r8) = ctx->r2;
    after_0:
    // 0x8009C4C8: lhu         $v0, 0x188($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X188);
    // 0x8009C4CC: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8009C4D0: sh          $v0, 0x188($s0)
    MEM_H(0X188, ctx->r16) = ctx->r2;
    // 0x8009C4D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C4D8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8009C4DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C4E0: jr          $ra
    // 0x8009C4E4: nop

    return;
    // 0x8009C4E4: nop

;}
RECOMP_FUNC void func_8009C4E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C4E8: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8009C4EC: sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // 0x8009C4F0: lw          $s5, 0x98($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X98);
    // 0x8009C4F4: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x8009C4F8: lw          $s2, 0x9C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X9C);
    // 0x8009C4FC: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x8009C500: lw          $s1, 0xA0($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XA0);
    // 0x8009C504: sw          $s6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r22;
    // 0x8009C508: addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // 0x8009C50C: sw          $s7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r23;
    // 0x8009C510: addu        $s7, $a1, $zero
    ctx->r23 = ADD32(ctx->r5, 0);
    // 0x8009C514: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x8009C518: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x8009C51C: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // 0x8009C520: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x8009C524: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x8009C528: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8009C52C: sw          $ra, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r31;
L_8009C530:
    // 0x8009C530: lh          $a0, 0x0($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X0);
    // 0x8009C534: lh          $a1, 0x0($s5)
    ctx->r5 = MEM_H(ctx->r21, 0X0);
    // 0x8009C538: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8009C53C: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    // 0x8009C540: jal         0x8009D7D0
    // 0x8009C544: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_8009D7D0(rdram, ctx);
        goto after_0;
    // 0x8009C544: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_0:
    // 0x8009C548: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x8009C54C: lh          $a1, 0x0($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X0);
    // 0x8009C550: lh          $a2, 0x0($s4)
    ctx->r6 = MEM_H(ctx->r20, 0X0);
    // 0x8009C554: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    // 0x8009C558: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x8009C55C: jal         0x8009D8C4
    // 0x8009C560: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    func_8009D8C4(rdram, ctx);
        goto after_1;
    // 0x8009C560: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    after_1:
    // 0x8009C564: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8009C568: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    // 0x8009C56C: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8009C570: bne         $v0, $zero, L_8009C530
    if (ctx->r2 != 0) {
        // 0x8009C574: addiu       $s1, $s1, 0x1A
        ctx->r17 = ADD32(ctx->r17, 0X1A);
            goto L_8009C530;
    }
    // 0x8009C574: addiu       $s1, $s1, 0x1A
    ctx->r17 = ADD32(ctx->r17, 0X1A);
    // 0x8009C578: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x8009C57C: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x8009C580: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    // 0x8009C584: jal         0x8009C2D0
    // 0x8009C588: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    func_8009C2D0(rdram, ctx);
        goto after_2;
    // 0x8009C588: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_2:
    // 0x8009C58C: lw          $ra, 0x80($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X80);
    // 0x8009C590: lw          $s7, 0x7C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X7C);
    // 0x8009C594: lw          $s6, 0x78($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X78);
    // 0x8009C598: lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X74);
    // 0x8009C59C: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x8009C5A0: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x8009C5A4: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x8009C5A8: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x8009C5AC: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x8009C5B0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x8009C5B4: jr          $ra
    // 0x8009C5B8: nop

    return;
    // 0x8009C5B8: nop

;}
RECOMP_FUNC void func_8009C5BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C5BC: addiu       $sp, $sp, -0x120
    ctx->r29 = ADD32(ctx->r29, -0X120);
    // 0x8009C5C0: sw          $ra, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r31;
    // 0x8009C5C4: sw          $fp, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r30;
    // 0x8009C5C8: sw          $s7, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r23;
    // 0x8009C5CC: sw          $s6, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r22;
    // 0x8009C5D0: sw          $s5, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r21;
    // 0x8009C5D4: sw          $s4, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r20;
    // 0x8009C5D8: sw          $s3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r19;
    // 0x8009C5DC: sw          $s2, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r18;
    // 0x8009C5E0: sw          $s1, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r17;
    // 0x8009C5E4: sw          $s0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r16;
    // 0x8009C5E8: lbu         $v1, 0x1($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X1);
    // 0x8009C5EC: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8009C5F0: srl         $v1, $v1, 6
    ctx->r3 = S32(U32(ctx->r3) >> 6);
    // 0x8009C5F4: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x8009C5F8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009C5FC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8009C600: sh          $v1, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r3;
    // 0x8009C604: lbu         $v0, 0x1($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1);
    // 0x8009C608: andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // 0x8009C60C: sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    // 0x8009C610: lbu         $v0, 0x2($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X2);
    // 0x8009C614: srl         $v0, $v0, 3
    ctx->r2 = S32(U32(ctx->r2) >> 3);
    // 0x8009C618: sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    // 0x8009C61C: lbu         $v1, 0x3($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X3);
    // 0x8009C620: lbu         $v0, 0x2($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X2);
    // 0x8009C624: srl         $v1, $v1, 6
    ctx->r3 = S32(U32(ctx->r3) >> 6);
    // 0x8009C628: andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // 0x8009C62C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009C630: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8009C634: sh          $v1, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r3;
    // 0x8009C638: lbu         $v0, 0x3($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X3);
    // 0x8009C63C: addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // 0x8009C640: addu        $fp, $a2, $zero
    ctx->r30 = ADD32(ctx->r6, 0);
    // 0x8009C644: srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // 0x8009C648: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x8009C64C: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // 0x8009C650: lbu         $v1, 0x4($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X4);
    // 0x8009C654: lbu         $v0, 0x3($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X3);
    // 0x8009C658: addu        $t3, $zero, $zero
    ctx->r11 = ADD32(0, 0);
    // 0x8009C65C: srl         $v1, $v1, 6
    ctx->r3 = S32(U32(ctx->r3) >> 6);
    // 0x8009C660: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x8009C664: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009C668: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8009C66C: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    // 0x8009C670: lbu         $v0, 0x4($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X4);
    // 0x8009C674: addiu       $t2, $sp, 0x10
    ctx->r10 = ADD32(ctx->r29, 0X10);
    // 0x8009C678: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8009C67C: srl         $v0, $v0, 3
    ctx->r2 = S32(U32(ctx->r2) >> 3);
    // 0x8009C680: andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // 0x8009C684: sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    // 0x8009C688: lbu         $v0, 0x4($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X4);
    // 0x8009C68C: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8009C690: addu        $t1, $t2, $zero
    ctx->r9 = ADD32(ctx->r10, 0);
    // 0x8009C694: andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // 0x8009C698: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
L_8009C69C:
    // 0x8009C69C: lbu         $v0, 0x5($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X5);
    // 0x8009C6A0: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x8009C6A4: sh          $v0, 0x10($t1)
    MEM_H(0X10, ctx->r9) = ctx->r2;
    // 0x8009C6A8: lbu         $v0, 0x5($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X5);
    // 0x8009C6AC: lbu         $v1, 0x6($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X6);
    // 0x8009C6B0: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8009C6B4: srl         $v1, $v1, 7
    ctx->r3 = S32(U32(ctx->r3) >> 7);
    // 0x8009C6B8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8009C6BC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8009C6C0: sh          $v1, 0x20($t1)
    MEM_H(0X20, ctx->r9) = ctx->r3;
    // 0x8009C6C4: lbu         $v0, 0x6($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X6);
    // 0x8009C6C8: addiu       $a1, $sp, 0x56
    ctx->r5 = ADD32(ctx->r29, 0X56);
    // 0x8009C6CC: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x8009C6D0: srl         $v0, $v0, 5
    ctx->r2 = S32(U32(ctx->r2) >> 5);
    // 0x8009C6D4: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x8009C6D8: sh          $v0, 0x18($t1)
    MEM_H(0X18, ctx->r9) = ctx->r2;
    // 0x8009C6DC: lbu         $v1, 0x7($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X7);
    // 0x8009C6E0: lbu         $v0, 0x6($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X6);
    // 0x8009C6E4: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x8009C6E8: srl         $v1, $v1, 7
    ctx->r3 = S32(U32(ctx->r3) >> 7);
    // 0x8009C6EC: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x8009C6F0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8009C6F4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8009C6F8: sh          $v1, 0x28($t1)
    MEM_H(0X28, ctx->r9) = ctx->r3;
    // 0x8009C6FC: lbu         $v0, 0x7($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X7);
    // 0x8009C700: addu        $a2, $a2, $t0
    ctx->r6 = ADD32(ctx->r6, ctx->r8);
    // 0x8009C704: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8009C708: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x8009C70C: andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // 0x8009C710: sh          $v0, 0x30($t2)
    MEM_H(0X30, ctx->r10) = ctx->r2;
    // 0x8009C714: lbu         $v1, 0x7($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X7);
    // 0x8009C718: addiu       $v0, $sp, 0x42
    ctx->r2 = ADD32(ctx->r29, 0X42);
    // 0x8009C71C: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8009C720: srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // 0x8009C724: andi        $v1, $v1, 0x7
    ctx->r3 = ctx->r3 & 0X7;
    // 0x8009C728: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x8009C72C: lbu         $v1, 0x7($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X7);
    // 0x8009C730: lbu         $a0, 0x8($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X8);
    // 0x8009C734: addiu       $v0, $sp, 0x44
    ctx->r2 = ADD32(ctx->r29, 0X44);
    // 0x8009C738: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8009C73C: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x8009C740: srl         $a0, $a0, 6
    ctx->r4 = S32(U32(ctx->r4) >> 6);
    // 0x8009C744: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8009C748: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x8009C74C: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x8009C750: lbu         $v1, 0x8($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X8);
    // 0x8009C754: addiu       $v0, $sp, 0x46
    ctx->r2 = ADD32(ctx->r29, 0X46);
    // 0x8009C758: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8009C75C: srl         $v1, $v1, 3
    ctx->r3 = S32(U32(ctx->r3) >> 3);
    // 0x8009C760: andi        $v1, $v1, 0x7
    ctx->r3 = ctx->r3 & 0X7;
    // 0x8009C764: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x8009C768: lbu         $v1, 0x8($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X8);
    // 0x8009C76C: addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // 0x8009C770: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8009C774: andi        $v1, $v1, 0x7
    ctx->r3 = ctx->r3 & 0X7;
    // 0x8009C778: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x8009C77C: lbu         $v1, 0x9($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X9);
    // 0x8009C780: addiu       $v0, $sp, 0x4A
    ctx->r2 = ADD32(ctx->r29, 0X4A);
    // 0x8009C784: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8009C788: srl         $v1, $v1, 5
    ctx->r3 = S32(U32(ctx->r3) >> 5);
    // 0x8009C78C: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x8009C790: lbu         $v1, 0x9($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X9);
    // 0x8009C794: addiu       $v0, $sp, 0x4C
    ctx->r2 = ADD32(ctx->r29, 0X4C);
    // 0x8009C798: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8009C79C: srl         $v1, $v1, 2
    ctx->r3 = S32(U32(ctx->r3) >> 2);
    // 0x8009C7A0: andi        $v1, $v1, 0x7
    ctx->r3 = ctx->r3 & 0X7;
    // 0x8009C7A4: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x8009C7A8: lbu         $a0, 0xA($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0XA);
    // 0x8009C7AC: lbu         $v0, 0x9($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X9);
    // 0x8009C7B0: addiu       $v1, $sp, 0x4E
    ctx->r3 = ADD32(ctx->r29, 0X4E);
    // 0x8009C7B4: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x8009C7B8: srl         $a0, $a0, 7
    ctx->r4 = S32(U32(ctx->r4) >> 7);
    // 0x8009C7BC: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x8009C7C0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8009C7C4: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x8009C7C8: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x8009C7CC: lbu         $v1, 0xA($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0XA);
    // 0x8009C7D0: addiu       $v0, $sp, 0x50
    ctx->r2 = ADD32(ctx->r29, 0X50);
    // 0x8009C7D4: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8009C7D8: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8009C7DC: srl         $v1, $v1, 4
    ctx->r3 = S32(U32(ctx->r3) >> 4);
    // 0x8009C7E0: andi        $v1, $v1, 0x7
    ctx->r3 = ctx->r3 & 0X7;
    // 0x8009C7E4: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x8009C7E8: lbu         $v1, 0xA($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0XA);
    // 0x8009C7EC: addiu       $v0, $sp, 0x52
    ctx->r2 = ADD32(ctx->r29, 0X52);
    // 0x8009C7F0: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8009C7F4: srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // 0x8009C7F8: andi        $v1, $v1, 0x7
    ctx->r3 = ctx->r3 & 0X7;
    // 0x8009C7FC: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x8009C800: lbu         $v0, 0xA($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0XA);
    // 0x8009C804: lbu         $v1, 0xB($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0XB);
    // 0x8009C808: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x8009C80C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8009C810: srl         $v1, $v1, 6
    ctx->r3 = S32(U32(ctx->r3) >> 6);
    // 0x8009C814: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009C818: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8009C81C: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
    // 0x8009C820: lbu         $v0, 0xB($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0XB);
    // 0x8009C824: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x8009C828: addiu       $t2, $t2, 0x1A
    ctx->r10 = ADD32(ctx->r10, 0X1A);
    // 0x8009C82C: srl         $v0, $v0, 3
    ctx->r2 = S32(U32(ctx->r2) >> 3);
    // 0x8009C830: andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // 0x8009C834: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8009C838: lbu         $v0, 0xB($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0XB);
    // 0x8009C83C: addiu       $t0, $t0, 0x1A
    ctx->r8 = ADD32(ctx->r8, 0X1A);
    // 0x8009C840: andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // 0x8009C844: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x8009C848: slti        $v0, $t3, 0x4
    ctx->r2 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x8009C84C: bne         $v0, $zero, L_8009C69C
    if (ctx->r2 != 0) {
        // 0x8009C850: addiu       $a3, $a3, 0x7
        ctx->r7 = ADD32(ctx->r7, 0X7);
            goto L_8009C69C;
    }
    // 0x8009C850: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    // 0x8009C854: addiu       $s6, $sp, 0x10
    ctx->r22 = ADD32(ctx->r29, 0X10);
    // 0x8009C858: addiu       $s5, $sp, 0x20
    ctx->r21 = ADD32(ctx->r29, 0X20);
    // 0x8009C85C: addiu       $s4, $sp, 0x30
    ctx->r20 = ADD32(ctx->r29, 0X30);
    // 0x8009C860: addiu       $s3, $sp, 0x28
    ctx->r19 = ADD32(ctx->r29, 0X28);
    // 0x8009C864: addiu       $s2, $sp, 0x38
    ctx->r18 = ADD32(ctx->r29, 0X38);
    // 0x8009C868: addiu       $s1, $sp, 0x40
    ctx->r17 = ADD32(ctx->r29, 0X40);
    // 0x8009C86C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8009C870:
    // 0x8009C870: lh          $a0, 0x0($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X0);
    // 0x8009C874: lh          $a1, 0x0($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X0);
    // 0x8009C878: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8009C87C: addiu       $a3, $sp, 0xA8
    ctx->r7 = ADD32(ctx->r29, 0XA8);
    // 0x8009C880: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009C884: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8009C888: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x8009C88C: jal         0x8009D7D0
    // 0x8009C890: addiu       $s1, $s1, 0x1A
    ctx->r17 = ADD32(ctx->r17, 0X1A);
    func_8009D7D0(rdram, ctx);
        goto after_0;
    // 0x8009C890: addiu       $s1, $s1, 0x1A
    ctx->r17 = ADD32(ctx->r17, 0X1A);
    after_0:
    // 0x8009C894: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x8009C898: lh          $a1, 0x0($s5)
    ctx->r5 = MEM_H(ctx->r21, 0X0);
    // 0x8009C89C: lh          $a2, 0x0($s4)
    ctx->r6 = MEM_H(ctx->r20, 0X0);
    // 0x8009C8A0: addiu       $a3, $sp, 0xA8
    ctx->r7 = ADD32(ctx->r29, 0XA8);
    // 0x8009C8A4: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x8009C8A8: jal         0x8009D8C4
    // 0x8009C8AC: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    func_8009D8C4(rdram, ctx);
        goto after_1;
    // 0x8009C8AC: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    after_1:
    // 0x8009C8B0: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8009C8B4: bne         $v0, $zero, L_8009C870
    if (ctx->r2 != 0) {
        // 0x8009C8B8: addu        $a0, $s7, $zero
        ctx->r4 = ADD32(ctx->r23, 0);
            goto L_8009C870;
    }
    // 0x8009C8B8: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x8009C8BC: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // 0x8009C8C0: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8009C8C4: jal         0x8009C2D0
    // 0x8009C8C8: addu        $a3, $fp, $zero
    ctx->r7 = ADD32(ctx->r30, 0);
    func_8009C2D0(rdram, ctx);
        goto after_2;
    // 0x8009C8C8: addu        $a3, $fp, $zero
    ctx->r7 = ADD32(ctx->r30, 0);
    after_2:
    // 0x8009C8CC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8009C8D0: lw          $ra, 0x11C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X11C);
    // 0x8009C8D4: lw          $fp, 0x118($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X118);
    // 0x8009C8D8: lw          $s7, 0x114($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X114);
    // 0x8009C8DC: lw          $s6, 0x110($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X110);
    // 0x8009C8E0: lw          $s5, 0x10C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X10C);
    // 0x8009C8E4: lw          $s4, 0x108($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X108);
    // 0x8009C8E8: lw          $s3, 0x104($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X104);
    // 0x8009C8EC: lw          $s2, 0x100($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X100);
    // 0x8009C8F0: lw          $s1, 0xFC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XFC);
    // 0x8009C8F4: lw          $s0, 0xF8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XF8);
    // 0x8009C8F8: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
    // 0x8009C8FC: jr          $ra
    // 0x8009C900: nop

    return;
    // 0x8009C900: nop

;}
RECOMP_FUNC void func_8009C904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C904: addiu       $sp, $sp, -0x140
    ctx->r29 = ADD32(ctx->r29, -0X140);
    // 0x8009C908: sw          $fp, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r30;
    // 0x8009C90C: addu        $fp, $a0, $zero
    ctx->r30 = ADD32(ctx->r4, 0);
    // 0x8009C910: sw          $ra, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r31;
    // 0x8009C914: sw          $s7, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r23;
    // 0x8009C918: sw          $s6, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r22;
    // 0x8009C91C: sw          $s5, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r21;
    // 0x8009C920: sw          $s4, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r20;
    // 0x8009C924: sw          $s3, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r19;
    // 0x8009C928: sw          $s2, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r18;
    // 0x8009C92C: sw          $s1, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r17;
    // 0x8009C930: sw          $s0, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r16;
    // 0x8009C934: sw          $a1, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r5;
    // 0x8009C938: lw          $s1, 0x11C8($fp)
    ctx->r17 = MEM_W(ctx->r30, 0X11C8);
    // 0x8009C93C: addiu       $a3, $fp, 0x1A0
    ctx->r7 = ADD32(ctx->r30, 0X1A0);
    // 0x8009C940: sra         $v0, $s1, 3
    ctx->r2 = S32(SIGNED(ctx->r17) >> 3);
    // 0x8009C944: andi        $v0, $v0, 0xFFC
    ctx->r2 = ctx->r2 & 0XFFC;
    // 0x8009C948: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009C94C: andi        $v1, $s1, 0x1F
    ctx->r3 = ctx->r17 & 0X1F;
    // 0x8009C950: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009C954: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x8009C958: subu        $s0, $v0, $v1
    ctx->r16 = SUB32(ctx->r2, ctx->r3);
    // 0x8009C95C: lh          $v0, 0x18A($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X18A);
    // 0x8009C960: addiu       $t1, $zero, 0x3FF
    ctx->r9 = ADD32(0, 0X3FF);
    // 0x8009C964: bne         $v0, $zero, L_8009CAE8
    if (ctx->r2 != 0) {
        // 0x8009C968: srlv        $a0, $a0, $v1
        ctx->r4 = S32(U32(ctx->r4) >> (ctx->r3 & 31));
            goto L_8009CAE8;
    }
    // 0x8009C968: srlv        $a0, $a0, $v1
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r3 & 31));
    // 0x8009C96C: lh          $v0, 0x18C($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X18C);
    // 0x8009C970: bne         $v0, $zero, L_8009CAF4
    if (ctx->r2 != 0) {
        // 0x8009C974: slti        $v0, $s0, 0x2
        ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
            goto L_8009CAF4;
    }
    // 0x8009C974: slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x8009C978: bne         $v0, $zero, L_8009C990
    if (ctx->r2 != 0) {
        // 0x8009C97C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8009C990;
    }
    // 0x8009C97C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8009C980: andi        $v1, $a0, 0x1
    ctx->r3 = ctx->r4 & 0X1;
    // 0x8009C984: srl         $a0, $a0, 1
    ctx->r4 = S32(U32(ctx->r4) >> 1);
    // 0x8009C988: j           L_8009C9D8
    // 0x8009C98C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
        goto L_8009C9D8;
    // 0x8009C98C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_8009C990:
    // 0x8009C990: sllv        $v0, $a1, $s0
    ctx->r2 = S32(ctx->r5 << (ctx->r16 & 31));
    // 0x8009C994: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009C998: and         $v1, $a0, $v0
    ctx->r3 = ctx->r4 & ctx->r2;
    // 0x8009C99C: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x8009C9A0: sra         $v0, $s1, 3
    ctx->r2 = S32(SIGNED(ctx->r17) >> 3);
    // 0x8009C9A4: andi        $v0, $v0, 0xFFC
    ctx->r2 = ctx->r2 & 0XFFC;
    // 0x8009C9A8: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009C9AC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009C9B0: beq         $s0, $a1, L_8009C9CC
    if (ctx->r16 == ctx->r5) {
        // 0x8009C9B4: subu        $v0, $a1, $s0
        ctx->r2 = SUB32(ctx->r5, ctx->r16);
            goto L_8009C9CC;
    }
    // 0x8009C9B4: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009C9B8: sllv        $v0, $a1, $v0
    ctx->r2 = S32(ctx->r5 << (ctx->r2 & 31));
    // 0x8009C9BC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009C9C0: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009C9C4: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009C9C8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_8009C9CC:
    // 0x8009C9CC: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009C9D0: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009C9D4: addiu       $s0, $s0, 0x1F
    ctx->r16 = ADD32(ctx->r16, 0X1F);
L_8009C9D8:
    // 0x8009C9D8: beq         $v1, $zero, L_8009CA64
    if (ctx->r3 == 0) {
        // 0x8009C9DC: slti        $v0, $s0, 0x5
        ctx->r2 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
            goto L_8009CA64;
    }
    // 0x8009C9DC: slti        $v0, $s0, 0x5
    ctx->r2 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x8009C9E0: bnel        $v0, $zero, L_8009C9FC
    if (ctx->r2 != 0) {
        // 0x8009C9E4: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8009C9FC;
    }
    goto skip_0;
    // 0x8009C9E4: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_0:
    // 0x8009C9E8: andi        $v0, $a0, 0xF
    ctx->r2 = ctx->r4 & 0XF;
    // 0x8009C9EC: sh          $v0, 0x18C($fp)
    MEM_H(0X18C, ctx->r30) = ctx->r2;
    // 0x8009C9F0: srl         $a0, $a0, 4
    ctx->r4 = S32(U32(ctx->r4) >> 4);
    // 0x8009C9F4: j           L_8009CA54
    // 0x8009C9F8: addiu       $s0, $s0, -0x4
    ctx->r16 = ADD32(ctx->r16, -0X4);
        goto L_8009CA54;
    // 0x8009C9F8: addiu       $s0, $s0, -0x4
    ctx->r16 = ADD32(ctx->r16, -0X4);
L_8009C9FC:
    // 0x8009C9FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8009CA00: sllv        $v0, $a2, $s0
    ctx->r2 = S32(ctx->r6 << (ctx->r16 & 31));
    // 0x8009CA04: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009CA08: and         $a1, $a0, $v0
    ctx->r5 = ctx->r4 & ctx->r2;
    // 0x8009CA0C: sra         $v0, $s1, 5
    ctx->r2 = S32(SIGNED(ctx->r17) >> 5);
    // 0x8009CA10: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x8009CA14: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009CA18: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009CA1C: sh          $a1, 0x18C($fp)
    MEM_H(0X18C, ctx->r30) = ctx->r5;
    // 0x8009CA20: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009CA24: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x8009CA28: beq         $s0, $v1, L_8009CA48
    if (ctx->r16 == ctx->r3) {
        // 0x8009CA2C: subu        $v0, $v1, $s0
        ctx->r2 = SUB32(ctx->r3, ctx->r16);
            goto L_8009CA48;
    }
    // 0x8009CA2C: subu        $v0, $v1, $s0
    ctx->r2 = SUB32(ctx->r3, ctx->r16);
    // 0x8009CA30: sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6 << (ctx->r2 & 31));
    // 0x8009CA34: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009CA38: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009CA3C: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009CA40: or          $v0, $a1, $v0
    ctx->r2 = ctx->r5 | ctx->r2;
    // 0x8009CA44: sh          $v0, 0x18C($fp)
    MEM_H(0X18C, ctx->r30) = ctx->r2;
L_8009CA48:
    // 0x8009CA48: subu        $v0, $v1, $s0
    ctx->r2 = SUB32(ctx->r3, ctx->r16);
    // 0x8009CA4C: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009CA50: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
L_8009CA54:
    // 0x8009CA54: lhu         $v0, 0x18C($fp)
    ctx->r2 = MEM_HU(ctx->r30, 0X18C);
    // 0x8009CA58: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8009CA5C: j           L_8009CAE8
    // 0x8009CA60: sh          $v0, 0x18C($fp)
    MEM_H(0X18C, ctx->r30) = ctx->r2;
        goto L_8009CAE8;
    // 0x8009CA60: sh          $v0, 0x18C($fp)
    MEM_H(0X18C, ctx->r30) = ctx->r2;
L_8009CA64:
    // 0x8009CA64: slti        $v0, $s0, 0x8
    ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x8009CA68: bnel        $v0, $zero, L_8009CA84
    if (ctx->r2 != 0) {
        // 0x8009CA6C: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8009CA84;
    }
    goto skip_1;
    // 0x8009CA6C: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_1:
    // 0x8009CA70: andi        $v0, $a0, 0x7F
    ctx->r2 = ctx->r4 & 0X7F;
    // 0x8009CA74: sh          $v0, 0x18A($fp)
    MEM_H(0X18A, ctx->r30) = ctx->r2;
    // 0x8009CA78: srl         $a0, $a0, 7
    ctx->r4 = S32(U32(ctx->r4) >> 7);
    // 0x8009CA7C: j           L_8009CADC
    // 0x8009CA80: addiu       $s0, $s0, -0x7
    ctx->r16 = ADD32(ctx->r16, -0X7);
        goto L_8009CADC;
    // 0x8009CA80: addiu       $s0, $s0, -0x7
    ctx->r16 = ADD32(ctx->r16, -0X7);
L_8009CA84:
    // 0x8009CA84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8009CA88: sllv        $v0, $a2, $s0
    ctx->r2 = S32(ctx->r6 << (ctx->r16 & 31));
    // 0x8009CA8C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009CA90: and         $a1, $a0, $v0
    ctx->r5 = ctx->r4 & ctx->r2;
    // 0x8009CA94: sra         $v0, $s1, 5
    ctx->r2 = S32(SIGNED(ctx->r17) >> 5);
    // 0x8009CA98: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x8009CA9C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009CAA0: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009CAA4: sh          $a1, 0x18A($fp)
    MEM_H(0X18A, ctx->r30) = ctx->r5;
    // 0x8009CAA8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009CAAC: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // 0x8009CAB0: beq         $s0, $v1, L_8009CAD0
    if (ctx->r16 == ctx->r3) {
        // 0x8009CAB4: subu        $v0, $v1, $s0
        ctx->r2 = SUB32(ctx->r3, ctx->r16);
            goto L_8009CAD0;
    }
    // 0x8009CAB4: subu        $v0, $v1, $s0
    ctx->r2 = SUB32(ctx->r3, ctx->r16);
    // 0x8009CAB8: sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6 << (ctx->r2 & 31));
    // 0x8009CABC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009CAC0: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009CAC4: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009CAC8: or          $v0, $a1, $v0
    ctx->r2 = ctx->r5 | ctx->r2;
    // 0x8009CACC: sh          $v0, 0x18A($fp)
    MEM_H(0X18A, ctx->r30) = ctx->r2;
L_8009CAD0:
    // 0x8009CAD0: subu        $v0, $v1, $s0
    ctx->r2 = SUB32(ctx->r3, ctx->r16);
    // 0x8009CAD4: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009CAD8: addiu       $s0, $s0, 0x19
    ctx->r16 = ADD32(ctx->r16, 0X19);
L_8009CADC:
    // 0x8009CADC: lhu         $v0, 0x18A($fp)
    ctx->r2 = MEM_HU(ctx->r30, 0X18A);
    // 0x8009CAE0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8009CAE4: sh          $v0, 0x18A($fp)
    MEM_H(0X18A, ctx->r30) = ctx->r2;
L_8009CAE8:
    // 0x8009CAE8: lh          $v0, 0x18C($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X18C);
    // 0x8009CAEC: beq         $v0, $zero, L_8009CB10
    if (ctx->r2 == 0) {
        // 0x8009CAF0: slti        $v0, $s0, 0x7
        ctx->r2 = SIGNED(ctx->r16) < 0X7 ? 1 : 0;
            goto L_8009CB10;
    }
    // 0x8009CAF0: slti        $v0, $s0, 0x7
    ctx->r2 = SIGNED(ctx->r16) < 0X7 ? 1 : 0;
L_8009CAF4:
    // 0x8009CAF4: lw          $a0, 0xFC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XFC);
    // 0x8009CAF8: jal         0x8002A080
    // 0x8009CAFC: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    bzero_recomp(rdram, ctx);
        goto after_0;
    // 0x8009CAFC: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    after_0:
    // 0x8009CB00: lhu         $v0, 0x18C($fp)
    ctx->r2 = MEM_HU(ctx->r30, 0X18C);
    // 0x8009CB04: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009CB08: j           L_8009D780
    // 0x8009CB0C: sh          $v0, 0x18C($fp)
    MEM_H(0X18C, ctx->r30) = ctx->r2;
        goto L_8009D780;
    // 0x8009CB0C: sh          $v0, 0x18C($fp)
    MEM_H(0X18C, ctx->r30) = ctx->r2;
L_8009CB10:
    // 0x8009CB10: bnel        $v0, $zero, L_8009CB2C
    if (ctx->r2 != 0) {
        // 0x8009CB14: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8009CB2C;
    }
    goto skip_2;
    // 0x8009CB14: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_2:
    // 0x8009CB18: andi        $v0, $a0, 0x3F
    ctx->r2 = ctx->r4 & 0X3F;
    // 0x8009CB1C: sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // 0x8009CB20: srl         $a0, $a0, 6
    ctx->r4 = S32(U32(ctx->r4) >> 6);
    // 0x8009CB24: j           L_8009CB84
    // 0x8009CB28: addiu       $s0, $s0, -0x6
    ctx->r16 = ADD32(ctx->r16, -0X6);
        goto L_8009CB84;
    // 0x8009CB28: addiu       $s0, $s0, -0x6
    ctx->r16 = ADD32(ctx->r16, -0X6);
L_8009CB2C:
    // 0x8009CB2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8009CB30: sllv        $v0, $a2, $s0
    ctx->r2 = S32(ctx->r6 << (ctx->r16 & 31));
    // 0x8009CB34: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009CB38: and         $a1, $a0, $v0
    ctx->r5 = ctx->r4 & ctx->r2;
    // 0x8009CB3C: sra         $v0, $s1, 5
    ctx->r2 = S32(SIGNED(ctx->r17) >> 5);
    // 0x8009CB40: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x8009CB44: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009CB48: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009CB4C: sh          $a1, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r5;
    // 0x8009CB50: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009CB54: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x8009CB58: beq         $s0, $v1, L_8009CB78
    if (ctx->r16 == ctx->r3) {
        // 0x8009CB5C: subu        $v0, $v1, $s0
        ctx->r2 = SUB32(ctx->r3, ctx->r16);
            goto L_8009CB78;
    }
    // 0x8009CB5C: subu        $v0, $v1, $s0
    ctx->r2 = SUB32(ctx->r3, ctx->r16);
    // 0x8009CB60: sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6 << (ctx->r2 & 31));
    // 0x8009CB64: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009CB68: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009CB6C: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009CB70: or          $v0, $a1, $v0
    ctx->r2 = ctx->r5 | ctx->r2;
    // 0x8009CB74: sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
L_8009CB78:
    // 0x8009CB78: subu        $v0, $v1, $s0
    ctx->r2 = SUB32(ctx->r3, ctx->r16);
    // 0x8009CB7C: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009CB80: addiu       $s0, $s0, 0x1A
    ctx->r16 = ADD32(ctx->r16, 0X1A);
L_8009CB84:
    // 0x8009CB84: slti        $v0, $s0, 0x7
    ctx->r2 = SIGNED(ctx->r16) < 0X7 ? 1 : 0;
    // 0x8009CB88: bnel        $v0, $zero, L_8009CBA4
    if (ctx->r2 != 0) {
        // 0x8009CB8C: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8009CBA4;
    }
    goto skip_3;
    // 0x8009CB8C: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_3:
    // 0x8009CB90: andi        $v0, $a0, 0x3F
    ctx->r2 = ctx->r4 & 0X3F;
    // 0x8009CB94: sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    // 0x8009CB98: srl         $a0, $a0, 6
    ctx->r4 = S32(U32(ctx->r4) >> 6);
    // 0x8009CB9C: j           L_8009CBFC
    // 0x8009CBA0: addiu       $s0, $s0, -0x6
    ctx->r16 = ADD32(ctx->r16, -0X6);
        goto L_8009CBFC;
    // 0x8009CBA0: addiu       $s0, $s0, -0x6
    ctx->r16 = ADD32(ctx->r16, -0X6);
L_8009CBA4:
    // 0x8009CBA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8009CBA8: sllv        $v0, $a2, $s0
    ctx->r2 = S32(ctx->r6 << (ctx->r16 & 31));
    // 0x8009CBAC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009CBB0: and         $a1, $a0, $v0
    ctx->r5 = ctx->r4 & ctx->r2;
    // 0x8009CBB4: sra         $v0, $s1, 5
    ctx->r2 = S32(SIGNED(ctx->r17) >> 5);
    // 0x8009CBB8: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x8009CBBC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009CBC0: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009CBC4: sh          $a1, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r5;
    // 0x8009CBC8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009CBCC: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x8009CBD0: beq         $s0, $v1, L_8009CBF0
    if (ctx->r16 == ctx->r3) {
        // 0x8009CBD4: subu        $v0, $v1, $s0
        ctx->r2 = SUB32(ctx->r3, ctx->r16);
            goto L_8009CBF0;
    }
    // 0x8009CBD4: subu        $v0, $v1, $s0
    ctx->r2 = SUB32(ctx->r3, ctx->r16);
    // 0x8009CBD8: sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6 << (ctx->r2 & 31));
    // 0x8009CBDC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009CBE0: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009CBE4: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009CBE8: or          $v0, $a1, $v0
    ctx->r2 = ctx->r5 | ctx->r2;
    // 0x8009CBEC: sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
L_8009CBF0:
    // 0x8009CBF0: subu        $v0, $v1, $s0
    ctx->r2 = SUB32(ctx->r3, ctx->r16);
    // 0x8009CBF4: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009CBF8: addiu       $s0, $s0, 0x1A
    ctx->r16 = ADD32(ctx->r16, 0X1A);
L_8009CBFC:
    // 0x8009CBFC: slti        $v0, $s0, 0x6
    ctx->r2 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x8009CC00: bnel        $v0, $zero, L_8009CC1C
    if (ctx->r2 != 0) {
        // 0x8009CC04: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8009CC1C;
    }
    goto skip_4;
    // 0x8009CC04: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_4:
    // 0x8009CC08: andi        $v0, $a0, 0x1F
    ctx->r2 = ctx->r4 & 0X1F;
    // 0x8009CC0C: sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    // 0x8009CC10: srl         $a0, $a0, 5
    ctx->r4 = S32(U32(ctx->r4) >> 5);
    // 0x8009CC14: j           L_8009CC74
    // 0x8009CC18: addiu       $s0, $s0, -0x5
    ctx->r16 = ADD32(ctx->r16, -0X5);
        goto L_8009CC74;
    // 0x8009CC18: addiu       $s0, $s0, -0x5
    ctx->r16 = ADD32(ctx->r16, -0X5);
L_8009CC1C:
    // 0x8009CC1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8009CC20: sllv        $v0, $a2, $s0
    ctx->r2 = S32(ctx->r6 << (ctx->r16 & 31));
    // 0x8009CC24: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009CC28: and         $a1, $a0, $v0
    ctx->r5 = ctx->r4 & ctx->r2;
    // 0x8009CC2C: sra         $v0, $s1, 5
    ctx->r2 = S32(SIGNED(ctx->r17) >> 5);
    // 0x8009CC30: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x8009CC34: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009CC38: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009CC3C: sh          $a1, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r5;
    // 0x8009CC40: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009CC44: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x8009CC48: beq         $s0, $v1, L_8009CC68
    if (ctx->r16 == ctx->r3) {
        // 0x8009CC4C: subu        $v0, $v1, $s0
        ctx->r2 = SUB32(ctx->r3, ctx->r16);
            goto L_8009CC68;
    }
    // 0x8009CC4C: subu        $v0, $v1, $s0
    ctx->r2 = SUB32(ctx->r3, ctx->r16);
    // 0x8009CC50: sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6 << (ctx->r2 & 31));
    // 0x8009CC54: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009CC58: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009CC5C: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009CC60: or          $v0, $a1, $v0
    ctx->r2 = ctx->r5 | ctx->r2;
    // 0x8009CC64: sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
L_8009CC68:
    // 0x8009CC68: subu        $v0, $v1, $s0
    ctx->r2 = SUB32(ctx->r3, ctx->r16);
    // 0x8009CC6C: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009CC70: addiu       $s0, $s0, 0x1B
    ctx->r16 = ADD32(ctx->r16, 0X1B);
L_8009CC74:
    // 0x8009CC74: slti        $v0, $s0, 0x6
    ctx->r2 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x8009CC78: bnel        $v0, $zero, L_8009CC94
    if (ctx->r2 != 0) {
        // 0x8009CC7C: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8009CC94;
    }
    goto skip_5;
    // 0x8009CC7C: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_5:
    // 0x8009CC80: andi        $v0, $a0, 0x1F
    ctx->r2 = ctx->r4 & 0X1F;
    // 0x8009CC84: sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    // 0x8009CC88: srl         $a0, $a0, 5
    ctx->r4 = S32(U32(ctx->r4) >> 5);
    // 0x8009CC8C: j           L_8009CCEC
    // 0x8009CC90: addiu       $s0, $s0, -0x5
    ctx->r16 = ADD32(ctx->r16, -0X5);
        goto L_8009CCEC;
    // 0x8009CC90: addiu       $s0, $s0, -0x5
    ctx->r16 = ADD32(ctx->r16, -0X5);
L_8009CC94:
    // 0x8009CC94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8009CC98: sllv        $v0, $a2, $s0
    ctx->r2 = S32(ctx->r6 << (ctx->r16 & 31));
    // 0x8009CC9C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009CCA0: and         $a1, $a0, $v0
    ctx->r5 = ctx->r4 & ctx->r2;
    // 0x8009CCA4: sra         $v0, $s1, 5
    ctx->r2 = S32(SIGNED(ctx->r17) >> 5);
    // 0x8009CCA8: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x8009CCAC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009CCB0: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009CCB4: sh          $a1, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r5;
    // 0x8009CCB8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009CCBC: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x8009CCC0: beq         $s0, $v1, L_8009CCE0
    if (ctx->r16 == ctx->r3) {
        // 0x8009CCC4: subu        $v0, $v1, $s0
        ctx->r2 = SUB32(ctx->r3, ctx->r16);
            goto L_8009CCE0;
    }
    // 0x8009CCC4: subu        $v0, $v1, $s0
    ctx->r2 = SUB32(ctx->r3, ctx->r16);
    // 0x8009CCC8: sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6 << (ctx->r2 & 31));
    // 0x8009CCCC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009CCD0: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009CCD4: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009CCD8: or          $v0, $a1, $v0
    ctx->r2 = ctx->r5 | ctx->r2;
    // 0x8009CCDC: sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
L_8009CCE0:
    // 0x8009CCE0: subu        $v0, $v1, $s0
    ctx->r2 = SUB32(ctx->r3, ctx->r16);
    // 0x8009CCE4: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009CCE8: addiu       $s0, $s0, 0x1B
    ctx->r16 = ADD32(ctx->r16, 0X1B);
L_8009CCEC:
    // 0x8009CCEC: slti        $v0, $s0, 0x5
    ctx->r2 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x8009CCF0: bnel        $v0, $zero, L_8009CD0C
    if (ctx->r2 != 0) {
        // 0x8009CCF4: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8009CD0C;
    }
    goto skip_6;
    // 0x8009CCF4: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_6:
    // 0x8009CCF8: andi        $v0, $a0, 0xF
    ctx->r2 = ctx->r4 & 0XF;
    // 0x8009CCFC: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // 0x8009CD00: srl         $a0, $a0, 4
    ctx->r4 = S32(U32(ctx->r4) >> 4);
    // 0x8009CD04: j           L_8009CD64
    // 0x8009CD08: addiu       $s0, $s0, -0x4
    ctx->r16 = ADD32(ctx->r16, -0X4);
        goto L_8009CD64;
    // 0x8009CD08: addiu       $s0, $s0, -0x4
    ctx->r16 = ADD32(ctx->r16, -0X4);
L_8009CD0C:
    // 0x8009CD0C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8009CD10: sllv        $v0, $a2, $s0
    ctx->r2 = S32(ctx->r6 << (ctx->r16 & 31));
    // 0x8009CD14: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009CD18: and         $a1, $a0, $v0
    ctx->r5 = ctx->r4 & ctx->r2;
    // 0x8009CD1C: sra         $v0, $s1, 5
    ctx->r2 = S32(SIGNED(ctx->r17) >> 5);
    // 0x8009CD20: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x8009CD24: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009CD28: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009CD2C: sh          $a1, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r5;
    // 0x8009CD30: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009CD34: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x8009CD38: beq         $s0, $v1, L_8009CD58
    if (ctx->r16 == ctx->r3) {
        // 0x8009CD3C: subu        $v0, $v1, $s0
        ctx->r2 = SUB32(ctx->r3, ctx->r16);
            goto L_8009CD58;
    }
    // 0x8009CD3C: subu        $v0, $v1, $s0
    ctx->r2 = SUB32(ctx->r3, ctx->r16);
    // 0x8009CD40: sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6 << (ctx->r2 & 31));
    // 0x8009CD44: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009CD48: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009CD4C: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009CD50: or          $v0, $a1, $v0
    ctx->r2 = ctx->r5 | ctx->r2;
    // 0x8009CD54: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
L_8009CD58:
    // 0x8009CD58: subu        $v0, $v1, $s0
    ctx->r2 = SUB32(ctx->r3, ctx->r16);
    // 0x8009CD5C: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009CD60: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
L_8009CD64:
    // 0x8009CD64: slti        $v0, $s0, 0x5
    ctx->r2 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x8009CD68: bnel        $v0, $zero, L_8009CD84
    if (ctx->r2 != 0) {
        // 0x8009CD6C: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8009CD84;
    }
    goto skip_7;
    // 0x8009CD6C: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_7:
    // 0x8009CD70: andi        $v0, $a0, 0xF
    ctx->r2 = ctx->r4 & 0XF;
    // 0x8009CD74: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x8009CD78: srl         $a0, $a0, 4
    ctx->r4 = S32(U32(ctx->r4) >> 4);
    // 0x8009CD7C: j           L_8009CDDC
    // 0x8009CD80: addiu       $s0, $s0, -0x4
    ctx->r16 = ADD32(ctx->r16, -0X4);
        goto L_8009CDDC;
    // 0x8009CD80: addiu       $s0, $s0, -0x4
    ctx->r16 = ADD32(ctx->r16, -0X4);
L_8009CD84:
    // 0x8009CD84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8009CD88: sllv        $v0, $a2, $s0
    ctx->r2 = S32(ctx->r6 << (ctx->r16 & 31));
    // 0x8009CD8C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009CD90: and         $a1, $a0, $v0
    ctx->r5 = ctx->r4 & ctx->r2;
    // 0x8009CD94: sra         $v0, $s1, 5
    ctx->r2 = S32(SIGNED(ctx->r17) >> 5);
    // 0x8009CD98: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x8009CD9C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009CDA0: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009CDA4: sh          $a1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r5;
    // 0x8009CDA8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009CDAC: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x8009CDB0: beq         $s0, $v1, L_8009CDD0
    if (ctx->r16 == ctx->r3) {
        // 0x8009CDB4: subu        $v0, $v1, $s0
        ctx->r2 = SUB32(ctx->r3, ctx->r16);
            goto L_8009CDD0;
    }
    // 0x8009CDB4: subu        $v0, $v1, $s0
    ctx->r2 = SUB32(ctx->r3, ctx->r16);
    // 0x8009CDB8: sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6 << (ctx->r2 & 31));
    // 0x8009CDBC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009CDC0: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009CDC4: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009CDC8: or          $v0, $a1, $v0
    ctx->r2 = ctx->r5 | ctx->r2;
    // 0x8009CDCC: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
L_8009CDD0:
    // 0x8009CDD0: subu        $v0, $v1, $s0
    ctx->r2 = SUB32(ctx->r3, ctx->r16);
    // 0x8009CDD4: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009CDD8: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
L_8009CDDC:
    // 0x8009CDDC: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8009CDE0: bnel        $v0, $zero, L_8009CDFC
    if (ctx->r2 != 0) {
        // 0x8009CDE4: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8009CDFC;
    }
    goto skip_8;
    // 0x8009CDE4: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_8:
    // 0x8009CDE8: andi        $v0, $a0, 0x7
    ctx->r2 = ctx->r4 & 0X7;
    // 0x8009CDEC: sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    // 0x8009CDF0: srl         $a0, $a0, 3
    ctx->r4 = S32(U32(ctx->r4) >> 3);
    // 0x8009CDF4: j           L_8009CE54
    // 0x8009CDF8: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
        goto L_8009CE54;
    // 0x8009CDF8: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
L_8009CDFC:
    // 0x8009CDFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8009CE00: sllv        $v0, $a2, $s0
    ctx->r2 = S32(ctx->r6 << (ctx->r16 & 31));
    // 0x8009CE04: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009CE08: and         $a1, $a0, $v0
    ctx->r5 = ctx->r4 & ctx->r2;
    // 0x8009CE0C: sra         $v0, $s1, 5
    ctx->r2 = S32(SIGNED(ctx->r17) >> 5);
    // 0x8009CE10: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x8009CE14: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009CE18: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009CE1C: sh          $a1, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r5;
    // 0x8009CE20: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009CE24: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8009CE28: beq         $s0, $v1, L_8009CE48
    if (ctx->r16 == ctx->r3) {
        // 0x8009CE2C: subu        $v0, $v1, $s0
        ctx->r2 = SUB32(ctx->r3, ctx->r16);
            goto L_8009CE48;
    }
    // 0x8009CE2C: subu        $v0, $v1, $s0
    ctx->r2 = SUB32(ctx->r3, ctx->r16);
    // 0x8009CE30: sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6 << (ctx->r2 & 31));
    // 0x8009CE34: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009CE38: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009CE3C: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009CE40: or          $v0, $a1, $v0
    ctx->r2 = ctx->r5 | ctx->r2;
    // 0x8009CE44: sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
L_8009CE48:
    // 0x8009CE48: subu        $v0, $v1, $s0
    ctx->r2 = SUB32(ctx->r3, ctx->r16);
    // 0x8009CE4C: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009CE50: addiu       $s0, $s0, 0x1D
    ctx->r16 = ADD32(ctx->r16, 0X1D);
L_8009CE54:
    // 0x8009CE54: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8009CE58: bnel        $v0, $zero, L_8009CE74
    if (ctx->r2 != 0) {
        // 0x8009CE5C: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8009CE74;
    }
    goto skip_9;
    // 0x8009CE5C: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_9:
    // 0x8009CE60: andi        $v0, $a0, 0x7
    ctx->r2 = ctx->r4 & 0X7;
    // 0x8009CE64: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x8009CE68: srl         $a0, $a0, 3
    ctx->r4 = S32(U32(ctx->r4) >> 3);
    // 0x8009CE6C: j           L_8009CECC
    // 0x8009CE70: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
        goto L_8009CECC;
    // 0x8009CE70: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
L_8009CE74:
    // 0x8009CE74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8009CE78: sllv        $v0, $a2, $s0
    ctx->r2 = S32(ctx->r6 << (ctx->r16 & 31));
    // 0x8009CE7C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009CE80: and         $a1, $a0, $v0
    ctx->r5 = ctx->r4 & ctx->r2;
    // 0x8009CE84: sra         $v0, $s1, 5
    ctx->r2 = S32(SIGNED(ctx->r17) >> 5);
    // 0x8009CE88: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x8009CE8C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009CE90: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009CE94: sh          $a1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r5;
    // 0x8009CE98: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009CE9C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8009CEA0: beq         $s0, $v1, L_8009CEC0
    if (ctx->r16 == ctx->r3) {
        // 0x8009CEA4: subu        $v0, $v1, $s0
        ctx->r2 = SUB32(ctx->r3, ctx->r16);
            goto L_8009CEC0;
    }
    // 0x8009CEA4: subu        $v0, $v1, $s0
    ctx->r2 = SUB32(ctx->r3, ctx->r16);
    // 0x8009CEA8: sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6 << (ctx->r2 & 31));
    // 0x8009CEAC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009CEB0: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009CEB4: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009CEB8: or          $v0, $a1, $v0
    ctx->r2 = ctx->r5 | ctx->r2;
    // 0x8009CEBC: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
L_8009CEC0:
    // 0x8009CEC0: subu        $v0, $v1, $s0
    ctx->r2 = SUB32(ctx->r3, ctx->r16);
    // 0x8009CEC4: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009CEC8: addiu       $s0, $s0, 0x1D
    ctx->r16 = ADD32(ctx->r16, 0X1D);
L_8009CECC:
    // 0x8009CECC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8009CED0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8009CED4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8009CED8: addiu       $t4, $sp, 0x58
    ctx->r12 = ADD32(ctx->r29, 0X58);
    // 0x8009CEDC: sw          $t4, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r12;
    // 0x8009CEE0: lw          $t2, 0x104($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X104);
    // 0x8009CEE4: addiu       $t8, $sp, 0x56
    ctx->r24 = ADD32(ctx->r29, 0X56);
    // 0x8009CEE8: addiu       $s7, $sp, 0x54
    ctx->r23 = ADD32(ctx->r29, 0X54);
    // 0x8009CEEC: addiu       $s6, $sp, 0x52
    ctx->r22 = ADD32(ctx->r29, 0X52);
    // 0x8009CEF0: addiu       $s5, $sp, 0x50
    ctx->r21 = ADD32(ctx->r29, 0X50);
    // 0x8009CEF4: addiu       $s4, $sp, 0x4E
    ctx->r20 = ADD32(ctx->r29, 0X4E);
    // 0x8009CEF8: addiu       $s3, $sp, 0x4C
    ctx->r19 = ADD32(ctx->r29, 0X4C);
    // 0x8009CEFC: addiu       $s2, $sp, 0x4A
    ctx->r18 = ADD32(ctx->r29, 0X4A);
    // 0x8009CF00: addiu       $t7, $sp, 0x48
    ctx->r15 = ADD32(ctx->r29, 0X48);
    // 0x8009CF04: addiu       $t6, $sp, 0x46
    ctx->r14 = ADD32(ctx->r29, 0X46);
    // 0x8009CF08: addiu       $t5, $sp, 0x44
    ctx->r13 = ADD32(ctx->r29, 0X44);
    // 0x8009CF0C: addiu       $t4, $sp, 0x42
    ctx->r12 = ADD32(ctx->r29, 0X42);
    // 0x8009CF10: addiu       $v0, $sp, 0x10
    ctx->r2 = ADD32(ctx->r29, 0X10);
    // 0x8009CF14: addu        $t3, $v0, $zero
    ctx->r11 = ADD32(ctx->r2, 0);
    // 0x8009CF18: addu        $t0, $t3, $zero
    ctx->r8 = ADD32(ctx->r11, 0);
    // 0x8009CF1C: sw          $t4, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r12;
L_8009CF20:
    // 0x8009CF20: slti        $v0, $s0, 0x8
    ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x8009CF24: bnel        $v0, $zero, L_8009CF40
    if (ctx->r2 != 0) {
        // 0x8009CF28: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8009CF40;
    }
    goto skip_10;
    // 0x8009CF28: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_10:
    // 0x8009CF2C: andi        $v0, $a0, 0x7F
    ctx->r2 = ctx->r4 & 0X7F;
    // 0x8009CF30: sh          $v0, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r2;
    // 0x8009CF34: srl         $a0, $a0, 7
    ctx->r4 = S32(U32(ctx->r4) >> 7);
    // 0x8009CF38: j           L_8009CF98
    // 0x8009CF3C: addiu       $s0, $s0, -0x7
    ctx->r16 = ADD32(ctx->r16, -0X7);
        goto L_8009CF98;
    // 0x8009CF3C: addiu       $s0, $s0, -0x7
    ctx->r16 = ADD32(ctx->r16, -0X7);
L_8009CF40:
    // 0x8009CF40: sllv        $v0, $a2, $s0
    ctx->r2 = S32(ctx->r6 << (ctx->r16 & 31));
    // 0x8009CF44: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009CF48: and         $v1, $a0, $v0
    ctx->r3 = ctx->r4 & ctx->r2;
    // 0x8009CF4C: sra         $v0, $s1, 5
    ctx->r2 = S32(SIGNED(ctx->r17) >> 5);
    // 0x8009CF50: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x8009CF54: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009CF58: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009CF5C: sh          $v1, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r3;
    // 0x8009CF60: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009CF64: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x8009CF68: beq         $s0, $t4, L_8009CF8C
    if (ctx->r16 == ctx->r12) {
        // 0x8009CF6C: subu        $v0, $t4, $s0
        ctx->r2 = SUB32(ctx->r12, ctx->r16);
            goto L_8009CF8C;
    }
    // 0x8009CF6C: subu        $v0, $t4, $s0
    ctx->r2 = SUB32(ctx->r12, ctx->r16);
    // 0x8009CF70: sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6 << (ctx->r2 & 31));
    // 0x8009CF74: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009CF78: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009CF7C: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009CF80: or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    // 0x8009CF84: sh          $v0, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r2;
    // 0x8009CF88: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
L_8009CF8C:
    // 0x8009CF8C: subu        $v0, $t4, $s0
    ctx->r2 = SUB32(ctx->r12, ctx->r16);
    // 0x8009CF90: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009CF94: addiu       $s0, $s0, 0x19
    ctx->r16 = ADD32(ctx->r16, 0X19);
L_8009CF98:
    // 0x8009CF98: slti        $v0, $s0, 0x3
    ctx->r2 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x8009CF9C: bnel        $v0, $zero, L_8009CFB8
    if (ctx->r2 != 0) {
        // 0x8009CFA0: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8009CFB8;
    }
    goto skip_11;
    // 0x8009CFA0: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_11:
    // 0x8009CFA4: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x8009CFA8: sh          $v0, 0x20($t0)
    MEM_H(0X20, ctx->r8) = ctx->r2;
    // 0x8009CFAC: srl         $a0, $a0, 2
    ctx->r4 = S32(U32(ctx->r4) >> 2);
    // 0x8009CFB0: j           L_8009D008
    // 0x8009CFB4: addiu       $s0, $s0, -0x2
    ctx->r16 = ADD32(ctx->r16, -0X2);
        goto L_8009D008;
    // 0x8009CFB4: addiu       $s0, $s0, -0x2
    ctx->r16 = ADD32(ctx->r16, -0X2);
L_8009CFB8:
    // 0x8009CFB8: sllv        $v0, $a2, $s0
    ctx->r2 = S32(ctx->r6 << (ctx->r16 & 31));
    // 0x8009CFBC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009CFC0: and         $v1, $a0, $v0
    ctx->r3 = ctx->r4 & ctx->r2;
    // 0x8009CFC4: sra         $v0, $s1, 5
    ctx->r2 = S32(SIGNED(ctx->r17) >> 5);
    // 0x8009CFC8: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x8009CFCC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009CFD0: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009CFD4: sh          $v1, 0x20($t0)
    MEM_H(0X20, ctx->r8) = ctx->r3;
    // 0x8009CFD8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009CFDC: beq         $s0, $t9, L_8009CFFC
    if (ctx->r16 == ctx->r25) {
        // 0x8009CFE0: subu        $v0, $t9, $s0
        ctx->r2 = SUB32(ctx->r25, ctx->r16);
            goto L_8009CFFC;
    }
    // 0x8009CFE0: subu        $v0, $t9, $s0
    ctx->r2 = SUB32(ctx->r25, ctx->r16);
    // 0x8009CFE4: sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6 << (ctx->r2 & 31));
    // 0x8009CFE8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009CFEC: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009CFF0: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009CFF4: or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    // 0x8009CFF8: sh          $v0, 0x20($t0)
    MEM_H(0X20, ctx->r8) = ctx->r2;
L_8009CFFC:
    // 0x8009CFFC: subu        $v0, $t9, $s0
    ctx->r2 = SUB32(ctx->r25, ctx->r16);
    // 0x8009D000: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009D004: addiu       $s0, $s0, 0x1E
    ctx->r16 = ADD32(ctx->r16, 0X1E);
L_8009D008:
    // 0x8009D008: slti        $v0, $s0, 0x3
    ctx->r2 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x8009D00C: bnel        $v0, $zero, L_8009D028
    if (ctx->r2 != 0) {
        // 0x8009D010: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8009D028;
    }
    goto skip_12;
    // 0x8009D010: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_12:
    // 0x8009D014: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x8009D018: sh          $v0, 0x18($t0)
    MEM_H(0X18, ctx->r8) = ctx->r2;
    // 0x8009D01C: srl         $a0, $a0, 2
    ctx->r4 = S32(U32(ctx->r4) >> 2);
    // 0x8009D020: j           L_8009D078
    // 0x8009D024: addiu       $s0, $s0, -0x2
    ctx->r16 = ADD32(ctx->r16, -0X2);
        goto L_8009D078;
    // 0x8009D024: addiu       $s0, $s0, -0x2
    ctx->r16 = ADD32(ctx->r16, -0X2);
L_8009D028:
    // 0x8009D028: sllv        $v0, $a2, $s0
    ctx->r2 = S32(ctx->r6 << (ctx->r16 & 31));
    // 0x8009D02C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D030: and         $v1, $a0, $v0
    ctx->r3 = ctx->r4 & ctx->r2;
    // 0x8009D034: sra         $v0, $s1, 5
    ctx->r2 = S32(SIGNED(ctx->r17) >> 5);
    // 0x8009D038: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x8009D03C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009D040: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009D044: sh          $v1, 0x18($t0)
    MEM_H(0X18, ctx->r8) = ctx->r3;
    // 0x8009D048: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009D04C: beq         $s0, $t9, L_8009D06C
    if (ctx->r16 == ctx->r25) {
        // 0x8009D050: subu        $v0, $t9, $s0
        ctx->r2 = SUB32(ctx->r25, ctx->r16);
            goto L_8009D06C;
    }
    // 0x8009D050: subu        $v0, $t9, $s0
    ctx->r2 = SUB32(ctx->r25, ctx->r16);
    // 0x8009D054: sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6 << (ctx->r2 & 31));
    // 0x8009D058: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D05C: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009D060: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009D064: or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    // 0x8009D068: sh          $v0, 0x18($t0)
    MEM_H(0X18, ctx->r8) = ctx->r2;
L_8009D06C:
    // 0x8009D06C: subu        $v0, $t9, $s0
    ctx->r2 = SUB32(ctx->r25, ctx->r16);
    // 0x8009D070: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009D074: addiu       $s0, $s0, 0x1E
    ctx->r16 = ADD32(ctx->r16, 0X1E);
L_8009D078:
    // 0x8009D078: slti        $v0, $s0, 0x7
    ctx->r2 = SIGNED(ctx->r16) < 0X7 ? 1 : 0;
    // 0x8009D07C: bnel        $v0, $zero, L_8009D098
    if (ctx->r2 != 0) {
        // 0x8009D080: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8009D098;
    }
    goto skip_13;
    // 0x8009D080: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_13:
    // 0x8009D084: andi        $v0, $a0, 0x3F
    ctx->r2 = ctx->r4 & 0X3F;
    // 0x8009D088: sh          $v0, 0x28($t0)
    MEM_H(0X28, ctx->r8) = ctx->r2;
    // 0x8009D08C: srl         $a0, $a0, 6
    ctx->r4 = S32(U32(ctx->r4) >> 6);
    // 0x8009D090: j           L_8009D0F0
    // 0x8009D094: addiu       $s0, $s0, -0x6
    ctx->r16 = ADD32(ctx->r16, -0X6);
        goto L_8009D0F0;
    // 0x8009D094: addiu       $s0, $s0, -0x6
    ctx->r16 = ADD32(ctx->r16, -0X6);
L_8009D098:
    // 0x8009D098: sllv        $v0, $a2, $s0
    ctx->r2 = S32(ctx->r6 << (ctx->r16 & 31));
    // 0x8009D09C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D0A0: and         $v1, $a0, $v0
    ctx->r3 = ctx->r4 & ctx->r2;
    // 0x8009D0A4: sra         $v0, $s1, 5
    ctx->r2 = S32(SIGNED(ctx->r17) >> 5);
    // 0x8009D0A8: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x8009D0AC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009D0B0: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009D0B4: sh          $v1, 0x28($t0)
    MEM_H(0X28, ctx->r8) = ctx->r3;
    // 0x8009D0B8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009D0BC: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x8009D0C0: beq         $s0, $t4, L_8009D0E4
    if (ctx->r16 == ctx->r12) {
        // 0x8009D0C4: subu        $v0, $t4, $s0
        ctx->r2 = SUB32(ctx->r12, ctx->r16);
            goto L_8009D0E4;
    }
    // 0x8009D0C4: subu        $v0, $t4, $s0
    ctx->r2 = SUB32(ctx->r12, ctx->r16);
    // 0x8009D0C8: sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6 << (ctx->r2 & 31));
    // 0x8009D0CC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D0D0: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009D0D4: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009D0D8: or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    // 0x8009D0DC: sh          $v0, 0x28($t0)
    MEM_H(0X28, ctx->r8) = ctx->r2;
    // 0x8009D0E0: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
L_8009D0E4:
    // 0x8009D0E4: subu        $v0, $t4, $s0
    ctx->r2 = SUB32(ctx->r12, ctx->r16);
    // 0x8009D0E8: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009D0EC: addiu       $s0, $s0, 0x1A
    ctx->r16 = ADD32(ctx->r16, 0X1A);
L_8009D0F0:
    // 0x8009D0F0: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8009D0F4: bnel        $v0, $zero, L_8009D110
    if (ctx->r2 != 0) {
        // 0x8009D0F8: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8009D110;
    }
    goto skip_14;
    // 0x8009D0F8: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_14:
    // 0x8009D0FC: andi        $v0, $a0, 0x7
    ctx->r2 = ctx->r4 & 0X7;
    // 0x8009D100: sh          $v0, 0x30($t3)
    MEM_H(0X30, ctx->r11) = ctx->r2;
    // 0x8009D104: srl         $a0, $a0, 3
    ctx->r4 = S32(U32(ctx->r4) >> 3);
    // 0x8009D108: j           L_8009D160
    // 0x8009D10C: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
        goto L_8009D160;
    // 0x8009D10C: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
L_8009D110:
    // 0x8009D110: sllv        $v0, $a2, $s0
    ctx->r2 = S32(ctx->r6 << (ctx->r16 & 31));
    // 0x8009D114: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D118: and         $v1, $a0, $v0
    ctx->r3 = ctx->r4 & ctx->r2;
    // 0x8009D11C: sra         $v0, $s1, 5
    ctx->r2 = S32(SIGNED(ctx->r17) >> 5);
    // 0x8009D120: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x8009D124: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009D128: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009D12C: sh          $v1, 0x30($t3)
    MEM_H(0X30, ctx->r11) = ctx->r3;
    // 0x8009D130: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009D134: beq         $s0, $a1, L_8009D154
    if (ctx->r16 == ctx->r5) {
        // 0x8009D138: subu        $v0, $a1, $s0
        ctx->r2 = SUB32(ctx->r5, ctx->r16);
            goto L_8009D154;
    }
    // 0x8009D138: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009D13C: sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6 << (ctx->r2 & 31));
    // 0x8009D140: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D144: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009D148: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009D14C: or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    // 0x8009D150: sh          $v0, 0x30($t3)
    MEM_H(0X30, ctx->r11) = ctx->r2;
L_8009D154:
    // 0x8009D154: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009D158: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009D15C: addiu       $s0, $s0, 0x1D
    ctx->r16 = ADD32(ctx->r16, 0X1D);
L_8009D160:
    // 0x8009D160: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8009D164: bnel        $v0, $zero, L_8009D184
    if (ctx->r2 != 0) {
        // 0x8009D168: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8009D184;
    }
    goto skip_15;
    // 0x8009D168: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_15:
    // 0x8009D16C: andi        $v0, $a0, 0x7
    ctx->r2 = ctx->r4 & 0X7;
    // 0x8009D170: lw          $t4, 0x114($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X114);
    // 0x8009D174: srl         $a0, $a0, 3
    ctx->r4 = S32(U32(ctx->r4) >> 3);
    // 0x8009D178: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
    // 0x8009D17C: j           L_8009D1D8
    // 0x8009D180: sh          $v0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r2;
        goto L_8009D1D8;
    // 0x8009D180: sh          $v0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r2;
L_8009D184:
    // 0x8009D184: sllv        $v0, $a2, $s0
    ctx->r2 = S32(ctx->r6 << (ctx->r16 & 31));
    // 0x8009D188: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D18C: and         $v1, $a0, $v0
    ctx->r3 = ctx->r4 & ctx->r2;
    // 0x8009D190: lw          $t4, 0x114($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X114);
    // 0x8009D194: sra         $v0, $s1, 5
    ctx->r2 = S32(SIGNED(ctx->r17) >> 5);
    // 0x8009D198: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x8009D19C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009D1A0: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009D1A4: sh          $v1, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r3;
    // 0x8009D1A8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009D1AC: beq         $s0, $a1, L_8009D1CC
    if (ctx->r16 == ctx->r5) {
        // 0x8009D1B0: subu        $v0, $a1, $s0
        ctx->r2 = SUB32(ctx->r5, ctx->r16);
            goto L_8009D1CC;
    }
    // 0x8009D1B0: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009D1B4: sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6 << (ctx->r2 & 31));
    // 0x8009D1B8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D1BC: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009D1C0: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009D1C4: or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    // 0x8009D1C8: sh          $v0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r2;
L_8009D1CC:
    // 0x8009D1CC: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009D1D0: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009D1D4: addiu       $s0, $s0, 0x1D
    ctx->r16 = ADD32(ctx->r16, 0X1D);
L_8009D1D8:
    // 0x8009D1D8: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8009D1DC: bnel        $v0, $zero, L_8009D1F8
    if (ctx->r2 != 0) {
        // 0x8009D1E0: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8009D1F8;
    }
    goto skip_16;
    // 0x8009D1E0: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_16:
    // 0x8009D1E4: andi        $v0, $a0, 0x7
    ctx->r2 = ctx->r4 & 0X7;
    // 0x8009D1E8: sh          $v0, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r2;
    // 0x8009D1EC: srl         $a0, $a0, 3
    ctx->r4 = S32(U32(ctx->r4) >> 3);
    // 0x8009D1F0: j           L_8009D248
    // 0x8009D1F4: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
        goto L_8009D248;
    // 0x8009D1F4: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
L_8009D1F8:
    // 0x8009D1F8: sllv        $v0, $a2, $s0
    ctx->r2 = S32(ctx->r6 << (ctx->r16 & 31));
    // 0x8009D1FC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D200: and         $v1, $a0, $v0
    ctx->r3 = ctx->r4 & ctx->r2;
    // 0x8009D204: sra         $v0, $s1, 5
    ctx->r2 = S32(SIGNED(ctx->r17) >> 5);
    // 0x8009D208: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x8009D20C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009D210: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009D214: sh          $v1, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r3;
    // 0x8009D218: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009D21C: beq         $s0, $a1, L_8009D23C
    if (ctx->r16 == ctx->r5) {
        // 0x8009D220: subu        $v0, $a1, $s0
        ctx->r2 = SUB32(ctx->r5, ctx->r16);
            goto L_8009D23C;
    }
    // 0x8009D220: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009D224: sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6 << (ctx->r2 & 31));
    // 0x8009D228: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D22C: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009D230: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009D234: or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    // 0x8009D238: sh          $v0, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r2;
L_8009D23C:
    // 0x8009D23C: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009D240: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009D244: addiu       $s0, $s0, 0x1D
    ctx->r16 = ADD32(ctx->r16, 0X1D);
L_8009D248:
    // 0x8009D248: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8009D24C: bnel        $v0, $zero, L_8009D268
    if (ctx->r2 != 0) {
        // 0x8009D250: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8009D268;
    }
    goto skip_17;
    // 0x8009D250: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_17:
    // 0x8009D254: andi        $v0, $a0, 0x7
    ctx->r2 = ctx->r4 & 0X7;
    // 0x8009D258: sh          $v0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r2;
    // 0x8009D25C: srl         $a0, $a0, 3
    ctx->r4 = S32(U32(ctx->r4) >> 3);
    // 0x8009D260: j           L_8009D2B8
    // 0x8009D264: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
        goto L_8009D2B8;
    // 0x8009D264: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
L_8009D268:
    // 0x8009D268: sllv        $v0, $a2, $s0
    ctx->r2 = S32(ctx->r6 << (ctx->r16 & 31));
    // 0x8009D26C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D270: and         $v1, $a0, $v0
    ctx->r3 = ctx->r4 & ctx->r2;
    // 0x8009D274: sra         $v0, $s1, 5
    ctx->r2 = S32(SIGNED(ctx->r17) >> 5);
    // 0x8009D278: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x8009D27C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009D280: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009D284: sh          $v1, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r3;
    // 0x8009D288: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009D28C: beq         $s0, $a1, L_8009D2AC
    if (ctx->r16 == ctx->r5) {
        // 0x8009D290: subu        $v0, $a1, $s0
        ctx->r2 = SUB32(ctx->r5, ctx->r16);
            goto L_8009D2AC;
    }
    // 0x8009D290: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009D294: sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6 << (ctx->r2 & 31));
    // 0x8009D298: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D29C: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009D2A0: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009D2A4: or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    // 0x8009D2A8: sh          $v0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r2;
L_8009D2AC:
    // 0x8009D2AC: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009D2B0: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009D2B4: addiu       $s0, $s0, 0x1D
    ctx->r16 = ADD32(ctx->r16, 0X1D);
L_8009D2B8:
    // 0x8009D2B8: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8009D2BC: bnel        $v0, $zero, L_8009D2D8
    if (ctx->r2 != 0) {
        // 0x8009D2C0: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8009D2D8;
    }
    goto skip_18;
    // 0x8009D2C0: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_18:
    // 0x8009D2C4: andi        $v0, $a0, 0x7
    ctx->r2 = ctx->r4 & 0X7;
    // 0x8009D2C8: sh          $v0, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r2;
    // 0x8009D2CC: srl         $a0, $a0, 3
    ctx->r4 = S32(U32(ctx->r4) >> 3);
    // 0x8009D2D0: j           L_8009D328
    // 0x8009D2D4: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
        goto L_8009D328;
    // 0x8009D2D4: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
L_8009D2D8:
    // 0x8009D2D8: sllv        $v0, $a2, $s0
    ctx->r2 = S32(ctx->r6 << (ctx->r16 & 31));
    // 0x8009D2DC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D2E0: and         $v1, $a0, $v0
    ctx->r3 = ctx->r4 & ctx->r2;
    // 0x8009D2E4: sra         $v0, $s1, 5
    ctx->r2 = S32(SIGNED(ctx->r17) >> 5);
    // 0x8009D2E8: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x8009D2EC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009D2F0: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009D2F4: sh          $v1, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r3;
    // 0x8009D2F8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009D2FC: beq         $s0, $a1, L_8009D31C
    if (ctx->r16 == ctx->r5) {
        // 0x8009D300: subu        $v0, $a1, $s0
        ctx->r2 = SUB32(ctx->r5, ctx->r16);
            goto L_8009D31C;
    }
    // 0x8009D300: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009D304: sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6 << (ctx->r2 & 31));
    // 0x8009D308: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D30C: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009D310: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009D314: or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    // 0x8009D318: sh          $v0, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r2;
L_8009D31C:
    // 0x8009D31C: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009D320: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009D324: addiu       $s0, $s0, 0x1D
    ctx->r16 = ADD32(ctx->r16, 0X1D);
L_8009D328:
    // 0x8009D328: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8009D32C: bnel        $v0, $zero, L_8009D348
    if (ctx->r2 != 0) {
        // 0x8009D330: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8009D348;
    }
    goto skip_19;
    // 0x8009D330: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_19:
    // 0x8009D334: andi        $v0, $a0, 0x7
    ctx->r2 = ctx->r4 & 0X7;
    // 0x8009D338: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    // 0x8009D33C: srl         $a0, $a0, 3
    ctx->r4 = S32(U32(ctx->r4) >> 3);
    // 0x8009D340: j           L_8009D398
    // 0x8009D344: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
        goto L_8009D398;
    // 0x8009D344: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
L_8009D348:
    // 0x8009D348: sllv        $v0, $a2, $s0
    ctx->r2 = S32(ctx->r6 << (ctx->r16 & 31));
    // 0x8009D34C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D350: and         $v1, $a0, $v0
    ctx->r3 = ctx->r4 & ctx->r2;
    // 0x8009D354: sra         $v0, $s1, 5
    ctx->r2 = S32(SIGNED(ctx->r17) >> 5);
    // 0x8009D358: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x8009D35C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009D360: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009D364: sh          $v1, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r3;
    // 0x8009D368: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009D36C: beq         $s0, $a1, L_8009D38C
    if (ctx->r16 == ctx->r5) {
        // 0x8009D370: subu        $v0, $a1, $s0
        ctx->r2 = SUB32(ctx->r5, ctx->r16);
            goto L_8009D38C;
    }
    // 0x8009D370: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009D374: sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6 << (ctx->r2 & 31));
    // 0x8009D378: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D37C: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009D380: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009D384: or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    // 0x8009D388: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
L_8009D38C:
    // 0x8009D38C: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009D390: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009D394: addiu       $s0, $s0, 0x1D
    ctx->r16 = ADD32(ctx->r16, 0X1D);
L_8009D398:
    // 0x8009D398: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8009D39C: bnel        $v0, $zero, L_8009D3B8
    if (ctx->r2 != 0) {
        // 0x8009D3A0: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8009D3B8;
    }
    goto skip_20;
    // 0x8009D3A0: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_20:
    // 0x8009D3A4: andi        $v0, $a0, 0x7
    ctx->r2 = ctx->r4 & 0X7;
    // 0x8009D3A8: sh          $v0, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r2;
    // 0x8009D3AC: srl         $a0, $a0, 3
    ctx->r4 = S32(U32(ctx->r4) >> 3);
    // 0x8009D3B0: j           L_8009D408
    // 0x8009D3B4: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
        goto L_8009D408;
    // 0x8009D3B4: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
L_8009D3B8:
    // 0x8009D3B8: sllv        $v0, $a2, $s0
    ctx->r2 = S32(ctx->r6 << (ctx->r16 & 31));
    // 0x8009D3BC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D3C0: and         $v1, $a0, $v0
    ctx->r3 = ctx->r4 & ctx->r2;
    // 0x8009D3C4: sra         $v0, $s1, 5
    ctx->r2 = S32(SIGNED(ctx->r17) >> 5);
    // 0x8009D3C8: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x8009D3CC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009D3D0: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009D3D4: sh          $v1, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r3;
    // 0x8009D3D8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009D3DC: beq         $s0, $a1, L_8009D3FC
    if (ctx->r16 == ctx->r5) {
        // 0x8009D3E0: subu        $v0, $a1, $s0
        ctx->r2 = SUB32(ctx->r5, ctx->r16);
            goto L_8009D3FC;
    }
    // 0x8009D3E0: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009D3E4: sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6 << (ctx->r2 & 31));
    // 0x8009D3E8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D3EC: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009D3F0: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009D3F4: or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    // 0x8009D3F8: sh          $v0, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r2;
L_8009D3FC:
    // 0x8009D3FC: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009D400: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009D404: addiu       $s0, $s0, 0x1D
    ctx->r16 = ADD32(ctx->r16, 0X1D);
L_8009D408:
    // 0x8009D408: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8009D40C: bnel        $v0, $zero, L_8009D428
    if (ctx->r2 != 0) {
        // 0x8009D410: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8009D428;
    }
    goto skip_21;
    // 0x8009D410: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_21:
    // 0x8009D414: andi        $v0, $a0, 0x7
    ctx->r2 = ctx->r4 & 0X7;
    // 0x8009D418: sh          $v0, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r2;
    // 0x8009D41C: srl         $a0, $a0, 3
    ctx->r4 = S32(U32(ctx->r4) >> 3);
    // 0x8009D420: j           L_8009D478
    // 0x8009D424: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
        goto L_8009D478;
    // 0x8009D424: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
L_8009D428:
    // 0x8009D428: sllv        $v0, $a2, $s0
    ctx->r2 = S32(ctx->r6 << (ctx->r16 & 31));
    // 0x8009D42C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D430: and         $v1, $a0, $v0
    ctx->r3 = ctx->r4 & ctx->r2;
    // 0x8009D434: sra         $v0, $s1, 5
    ctx->r2 = S32(SIGNED(ctx->r17) >> 5);
    // 0x8009D438: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x8009D43C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009D440: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009D444: sh          $v1, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r3;
    // 0x8009D448: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009D44C: beq         $s0, $a1, L_8009D46C
    if (ctx->r16 == ctx->r5) {
        // 0x8009D450: subu        $v0, $a1, $s0
        ctx->r2 = SUB32(ctx->r5, ctx->r16);
            goto L_8009D46C;
    }
    // 0x8009D450: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009D454: sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6 << (ctx->r2 & 31));
    // 0x8009D458: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D45C: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009D460: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009D464: or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    // 0x8009D468: sh          $v0, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r2;
L_8009D46C:
    // 0x8009D46C: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009D470: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009D474: addiu       $s0, $s0, 0x1D
    ctx->r16 = ADD32(ctx->r16, 0X1D);
L_8009D478:
    // 0x8009D478: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8009D47C: bnel        $v0, $zero, L_8009D498
    if (ctx->r2 != 0) {
        // 0x8009D480: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8009D498;
    }
    goto skip_22;
    // 0x8009D480: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_22:
    // 0x8009D484: andi        $v0, $a0, 0x7
    ctx->r2 = ctx->r4 & 0X7;
    // 0x8009D488: sh          $v0, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r2;
    // 0x8009D48C: srl         $a0, $a0, 3
    ctx->r4 = S32(U32(ctx->r4) >> 3);
    // 0x8009D490: j           L_8009D4E8
    // 0x8009D494: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
        goto L_8009D4E8;
    // 0x8009D494: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
L_8009D498:
    // 0x8009D498: sllv        $v0, $a2, $s0
    ctx->r2 = S32(ctx->r6 << (ctx->r16 & 31));
    // 0x8009D49C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D4A0: and         $v1, $a0, $v0
    ctx->r3 = ctx->r4 & ctx->r2;
    // 0x8009D4A4: sra         $v0, $s1, 5
    ctx->r2 = S32(SIGNED(ctx->r17) >> 5);
    // 0x8009D4A8: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x8009D4AC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009D4B0: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009D4B4: sh          $v1, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r3;
    // 0x8009D4B8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009D4BC: beq         $s0, $a1, L_8009D4DC
    if (ctx->r16 == ctx->r5) {
        // 0x8009D4C0: subu        $v0, $a1, $s0
        ctx->r2 = SUB32(ctx->r5, ctx->r16);
            goto L_8009D4DC;
    }
    // 0x8009D4C0: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009D4C4: sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6 << (ctx->r2 & 31));
    // 0x8009D4C8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D4CC: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009D4D0: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009D4D4: or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    // 0x8009D4D8: sh          $v0, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r2;
L_8009D4DC:
    // 0x8009D4DC: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009D4E0: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009D4E4: addiu       $s0, $s0, 0x1D
    ctx->r16 = ADD32(ctx->r16, 0X1D);
L_8009D4E8:
    // 0x8009D4E8: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8009D4EC: bnel        $v0, $zero, L_8009D508
    if (ctx->r2 != 0) {
        // 0x8009D4F0: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8009D508;
    }
    goto skip_23;
    // 0x8009D4F0: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_23:
    // 0x8009D4F4: andi        $v0, $a0, 0x7
    ctx->r2 = ctx->r4 & 0X7;
    // 0x8009D4F8: sh          $v0, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r2;
    // 0x8009D4FC: srl         $a0, $a0, 3
    ctx->r4 = S32(U32(ctx->r4) >> 3);
    // 0x8009D500: j           L_8009D558
    // 0x8009D504: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
        goto L_8009D558;
    // 0x8009D504: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
L_8009D508:
    // 0x8009D508: sllv        $v0, $a2, $s0
    ctx->r2 = S32(ctx->r6 << (ctx->r16 & 31));
    // 0x8009D50C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D510: and         $v1, $a0, $v0
    ctx->r3 = ctx->r4 & ctx->r2;
    // 0x8009D514: sra         $v0, $s1, 5
    ctx->r2 = S32(SIGNED(ctx->r17) >> 5);
    // 0x8009D518: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x8009D51C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009D520: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009D524: sh          $v1, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r3;
    // 0x8009D528: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009D52C: beq         $s0, $a1, L_8009D54C
    if (ctx->r16 == ctx->r5) {
        // 0x8009D530: subu        $v0, $a1, $s0
        ctx->r2 = SUB32(ctx->r5, ctx->r16);
            goto L_8009D54C;
    }
    // 0x8009D530: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009D534: sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6 << (ctx->r2 & 31));
    // 0x8009D538: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D53C: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009D540: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009D544: or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    // 0x8009D548: sh          $v0, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r2;
L_8009D54C:
    // 0x8009D54C: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009D550: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009D554: addiu       $s0, $s0, 0x1D
    ctx->r16 = ADD32(ctx->r16, 0X1D);
L_8009D558:
    // 0x8009D558: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8009D55C: bnel        $v0, $zero, L_8009D578
    if (ctx->r2 != 0) {
        // 0x8009D560: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8009D578;
    }
    goto skip_24;
    // 0x8009D560: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_24:
    // 0x8009D564: andi        $v0, $a0, 0x7
    ctx->r2 = ctx->r4 & 0X7;
    // 0x8009D568: sh          $v0, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r2;
    // 0x8009D56C: srl         $a0, $a0, 3
    ctx->r4 = S32(U32(ctx->r4) >> 3);
    // 0x8009D570: j           L_8009D5C8
    // 0x8009D574: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
        goto L_8009D5C8;
    // 0x8009D574: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
L_8009D578:
    // 0x8009D578: sllv        $v0, $a2, $s0
    ctx->r2 = S32(ctx->r6 << (ctx->r16 & 31));
    // 0x8009D57C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D580: and         $v1, $a0, $v0
    ctx->r3 = ctx->r4 & ctx->r2;
    // 0x8009D584: sra         $v0, $s1, 5
    ctx->r2 = S32(SIGNED(ctx->r17) >> 5);
    // 0x8009D588: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x8009D58C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009D590: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009D594: sh          $v1, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r3;
    // 0x8009D598: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009D59C: beq         $s0, $a1, L_8009D5BC
    if (ctx->r16 == ctx->r5) {
        // 0x8009D5A0: subu        $v0, $a1, $s0
        ctx->r2 = SUB32(ctx->r5, ctx->r16);
            goto L_8009D5BC;
    }
    // 0x8009D5A0: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009D5A4: sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6 << (ctx->r2 & 31));
    // 0x8009D5A8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D5AC: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009D5B0: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009D5B4: or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    // 0x8009D5B8: sh          $v0, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r2;
L_8009D5BC:
    // 0x8009D5BC: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009D5C0: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009D5C4: addiu       $s0, $s0, 0x1D
    ctx->r16 = ADD32(ctx->r16, 0X1D);
L_8009D5C8:
    // 0x8009D5C8: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8009D5CC: bnel        $v0, $zero, L_8009D5E8
    if (ctx->r2 != 0) {
        // 0x8009D5D0: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8009D5E8;
    }
    goto skip_25;
    // 0x8009D5D0: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_25:
    // 0x8009D5D4: andi        $v0, $a0, 0x7
    ctx->r2 = ctx->r4 & 0X7;
    // 0x8009D5D8: sh          $v0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r2;
    // 0x8009D5DC: srl         $a0, $a0, 3
    ctx->r4 = S32(U32(ctx->r4) >> 3);
    // 0x8009D5E0: j           L_8009D638
    // 0x8009D5E4: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
        goto L_8009D638;
    // 0x8009D5E4: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
L_8009D5E8:
    // 0x8009D5E8: sllv        $v0, $a2, $s0
    ctx->r2 = S32(ctx->r6 << (ctx->r16 & 31));
    // 0x8009D5EC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D5F0: and         $v1, $a0, $v0
    ctx->r3 = ctx->r4 & ctx->r2;
    // 0x8009D5F4: sra         $v0, $s1, 5
    ctx->r2 = S32(SIGNED(ctx->r17) >> 5);
    // 0x8009D5F8: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x8009D5FC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009D600: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009D604: sh          $v1, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r3;
    // 0x8009D608: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009D60C: beq         $s0, $a1, L_8009D62C
    if (ctx->r16 == ctx->r5) {
        // 0x8009D610: subu        $v0, $a1, $s0
        ctx->r2 = SUB32(ctx->r5, ctx->r16);
            goto L_8009D62C;
    }
    // 0x8009D610: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009D614: sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6 << (ctx->r2 & 31));
    // 0x8009D618: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D61C: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009D620: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009D624: or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    // 0x8009D628: sh          $v0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r2;
L_8009D62C:
    // 0x8009D62C: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009D630: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009D634: addiu       $s0, $s0, 0x1D
    ctx->r16 = ADD32(ctx->r16, 0X1D);
L_8009D638:
    // 0x8009D638: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8009D63C: bnel        $v0, $zero, L_8009D658
    if (ctx->r2 != 0) {
        // 0x8009D640: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8009D658;
    }
    goto skip_26;
    // 0x8009D640: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_26:
    // 0x8009D644: andi        $v0, $a0, 0x7
    ctx->r2 = ctx->r4 & 0X7;
    // 0x8009D648: sh          $v0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r2;
    // 0x8009D64C: srl         $a0, $a0, 3
    ctx->r4 = S32(U32(ctx->r4) >> 3);
    // 0x8009D650: j           L_8009D6A8
    // 0x8009D654: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
        goto L_8009D6A8;
    // 0x8009D654: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
L_8009D658:
    // 0x8009D658: sllv        $v0, $a2, $s0
    ctx->r2 = S32(ctx->r6 << (ctx->r16 & 31));
    // 0x8009D65C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D660: and         $v1, $a0, $v0
    ctx->r3 = ctx->r4 & ctx->r2;
    // 0x8009D664: sra         $v0, $s1, 5
    ctx->r2 = S32(SIGNED(ctx->r17) >> 5);
    // 0x8009D668: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x8009D66C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009D670: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8009D674: sh          $v1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r3;
    // 0x8009D678: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009D67C: beq         $s0, $a1, L_8009D69C
    if (ctx->r16 == ctx->r5) {
        // 0x8009D680: subu        $v0, $a1, $s0
        ctx->r2 = SUB32(ctx->r5, ctx->r16);
            goto L_8009D69C;
    }
    // 0x8009D680: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009D684: sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6 << (ctx->r2 & 31));
    // 0x8009D688: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D68C: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8009D690: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8009D694: or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    // 0x8009D698: sh          $v0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r2;
L_8009D69C:
    // 0x8009D69C: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x8009D6A0: srlv        $a0, $a0, $v0
    ctx->r4 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // 0x8009D6A4: addiu       $s0, $s0, 0x1D
    ctx->r16 = ADD32(ctx->r16, 0X1D);
L_8009D6A8:
    // 0x8009D6A8: addiu       $t2, $t2, 0x1A
    ctx->r10 = ADD32(ctx->r10, 0X1A);
    // 0x8009D6AC: addiu       $t8, $t8, 0x1A
    ctx->r24 = ADD32(ctx->r24, 0X1A);
    // 0x8009D6B0: addiu       $s7, $s7, 0x1A
    ctx->r23 = ADD32(ctx->r23, 0X1A);
    // 0x8009D6B4: addiu       $s6, $s6, 0x1A
    ctx->r22 = ADD32(ctx->r22, 0X1A);
    // 0x8009D6B8: addiu       $s5, $s5, 0x1A
    ctx->r21 = ADD32(ctx->r21, 0X1A);
    // 0x8009D6BC: addiu       $s4, $s4, 0x1A
    ctx->r20 = ADD32(ctx->r20, 0X1A);
    // 0x8009D6C0: addiu       $s3, $s3, 0x1A
    ctx->r19 = ADD32(ctx->r19, 0X1A);
    // 0x8009D6C4: addiu       $s2, $s2, 0x1A
    ctx->r18 = ADD32(ctx->r18, 0X1A);
    // 0x8009D6C8: addiu       $t7, $t7, 0x1A
    ctx->r15 = ADD32(ctx->r15, 0X1A);
    // 0x8009D6CC: lw          $t4, 0x114($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X114);
    // 0x8009D6D0: addiu       $t6, $t6, 0x1A
    ctx->r14 = ADD32(ctx->r14, 0X1A);
    // 0x8009D6D4: addiu       $t5, $t5, 0x1A
    ctx->r13 = ADD32(ctx->r13, 0X1A);
    // 0x8009D6D8: addiu       $t4, $t4, 0x1A
    ctx->r12 = ADD32(ctx->r12, 0X1A);
    // 0x8009D6DC: sw          $t4, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r12;
    // 0x8009D6E0: lw          $t4, 0x104($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X104);
    // 0x8009D6E4: addiu       $t3, $t3, 0x1A
    ctx->r11 = ADD32(ctx->r11, 0X1A);
    // 0x8009D6E8: addiu       $v0, $t4, 0x68
    ctx->r2 = ADD32(ctx->r12, 0X68);
    // 0x8009D6EC: slt         $v0, $t2, $v0
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8009D6F0: bne         $v0, $zero, L_8009CF20
    if (ctx->r2 != 0) {
        // 0x8009D6F4: addiu       $t0, $t0, 0x2
        ctx->r8 = ADD32(ctx->r8, 0X2);
            goto L_8009CF20;
    }
    // 0x8009D6F4: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x8009D6F8: addiu       $t4, $sp, 0x10
    ctx->r12 = ADD32(ctx->r29, 0X10);
    // 0x8009D6FC: addiu       $s7, $sp, 0x20
    ctx->r23 = ADD32(ctx->r29, 0X20);
    // 0x8009D700: addiu       $s6, $sp, 0x30
    ctx->r22 = ADD32(ctx->r29, 0X30);
    // 0x8009D704: addiu       $s5, $sp, 0x28
    ctx->r21 = ADD32(ctx->r29, 0X28);
    // 0x8009D708: addiu       $s4, $sp, 0x38
    ctx->r20 = ADD32(ctx->r29, 0X38);
    // 0x8009D70C: sw          $t4, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r12;
    // 0x8009D710: lhu         $v0, 0x18A($fp)
    ctx->r2 = MEM_HU(ctx->r30, 0X18A);
    // 0x8009D714: addiu       $s3, $sp, 0x40
    ctx->r19 = ADD32(ctx->r29, 0X40);
    // 0x8009D718: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8009D71C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D720: sh          $v0, 0x18A($fp)
    MEM_H(0X18A, ctx->r30) = ctx->r2;
L_8009D724:
    // 0x8009D724: lh          $a0, 0x0($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X0);
    // 0x8009D728: lh          $a1, 0x0($s5)
    ctx->r5 = MEM_H(ctx->r21, 0X0);
    // 0x8009D72C: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8009D730: addiu       $a3, $sp, 0xA8
    ctx->r7 = ADD32(ctx->r29, 0XA8);
    // 0x8009D734: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8009D738: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x8009D73C: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    // 0x8009D740: jal         0x8009D7D0
    // 0x8009D744: addiu       $s3, $s3, 0x1A
    ctx->r19 = ADD32(ctx->r19, 0X1A);
    func_8009D7D0(rdram, ctx);
        goto after_1;
    // 0x8009D744: addiu       $s3, $s3, 0x1A
    ctx->r19 = ADD32(ctx->r19, 0X1A);
    after_1:
    // 0x8009D748: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // 0x8009D74C: lh          $a1, 0x0($s7)
    ctx->r5 = MEM_H(ctx->r23, 0X0);
    // 0x8009D750: lh          $a2, 0x0($s6)
    ctx->r6 = MEM_H(ctx->r22, 0X0);
    // 0x8009D754: addiu       $a3, $sp, 0xA8
    ctx->r7 = ADD32(ctx->r29, 0XA8);
    // 0x8009D758: addiu       $s6, $s6, 0x2
    ctx->r22 = ADD32(ctx->r22, 0X2);
    // 0x8009D75C: jal         0x8009D8C4
    // 0x8009D760: addiu       $s7, $s7, 0x2
    ctx->r23 = ADD32(ctx->r23, 0X2);
    func_8009D8C4(rdram, ctx);
        goto after_2;
    // 0x8009D760: addiu       $s7, $s7, 0x2
    ctx->r23 = ADD32(ctx->r23, 0X2);
    after_2:
    // 0x8009D764: slti        $v0, $s2, 0x4
    ctx->r2 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x8009D768: bne         $v0, $zero, L_8009D724
    if (ctx->r2 != 0) {
        // 0x8009D76C: addu        $a0, $fp, $zero
        ctx->r4 = ADD32(ctx->r30, 0);
            goto L_8009D724;
    }
    // 0x8009D76C: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // 0x8009D770: lw          $a1, 0x10C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X10C);
    // 0x8009D774: lw          $a3, 0xFC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XFC);
    // 0x8009D778: jal         0x8009C2D0
    // 0x8009D77C: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    func_8009C2D0(rdram, ctx);
        goto after_3;
    // 0x8009D77C: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    after_3:
L_8009D780:
    // 0x8009D780: addiu       $v0, $zero, -0x20
    ctx->r2 = ADD32(0, -0X20);
    // 0x8009D784: and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // 0x8009D788: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x8009D78C: subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x8009D790: sw          $v0, 0x11C8($fp)
    MEM_W(0X11C8, ctx->r30) = ctx->r2;
    // 0x8009D794: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8009D798: lw          $ra, 0x13C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X13C);
    // 0x8009D79C: lw          $fp, 0x138($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X138);
    // 0x8009D7A0: lw          $s7, 0x134($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X134);
    // 0x8009D7A4: lw          $s6, 0x130($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X130);
    // 0x8009D7A8: lw          $s5, 0x12C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X12C);
    // 0x8009D7AC: lw          $s4, 0x128($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X128);
    // 0x8009D7B0: lw          $s3, 0x124($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X124);
    // 0x8009D7B4: lw          $s2, 0x120($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X120);
    // 0x8009D7B8: lw          $s1, 0x11C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X11C);
    // 0x8009D7BC: lw          $s0, 0x118($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X118);
    // 0x8009D7C0: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
    // 0x8009D7C4: jr          $ra
    // 0x8009D7C8: nop

    return;
    // 0x8009D7C8: nop

;}
RECOMP_FUNC void fake_func_8009D7CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8009D7D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D7D0: addiu       $at, $a0, -0x7
    ctx->r1 = ADD32(ctx->r4, -0X7);
    // 0x8009D7D4: bgtz        $at, L_8009D80C
    if (SIGNED(ctx->r1) > 0) {
        // 0x8009D7D8: nop
    
            goto L_8009D80C;
    }
    // 0x8009D7D8: nop

    // 0x8009D7DC: addu        $at, $ra, $zero
    ctx->r1 = ADD32(ctx->r31, 0);
    // 0x8009D7E0: bltzal      $zero, L_8009D8BC
    if (SIGNED(0) < 0) {
        // 0x8009D7E4: nop

    func_8009D8BC(rdram, ctx);
        goto after_0;
    }
    // 0x8009D7E4: nop

    after_0:
    // 0x8009D7E8: addiu       $t7, $ra, 0xD4
    ctx->r15 = ADD32(ctx->r31, 0XD4);
    // 0x8009D7EC: addu        $ra, $at, $zero
    ctx->r31 = ADD32(ctx->r1, 0);
    // 0x8009D7F0: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8009D7F4: lb          $at, 0x0($t7)
    ctx->r1 = MEM_B(ctx->r15, 0X0);
    // 0x8009D7F8: nop

    // 0x8009D7FC: sra         $t0, $at, 4
    ctx->r8 = S32(SIGNED(ctx->r1) >> 4);
    // 0x8009D800: andi        $t1, $at, 0x7
    ctx->r9 = ctx->r1 & 0X7;
    // 0x8009D804: b           L_8009D818
    // 0x8009D808: nop

        goto L_8009D818;
    // 0x8009D808: nop

L_8009D80C:
    // 0x8009D80C: addiu       $t0, $a0, -0x8
    ctx->r8 = ADD32(ctx->r4, -0X8);
    // 0x8009D810: sra         $t0, $t0, 3
    ctx->r8 = S32(SIGNED(ctx->r8) >> 3);
    // 0x8009D814: andi        $t1, $a0, 0x7
    ctx->r9 = ctx->r4 & 0X7;
L_8009D818:
    // 0x8009D818: sll         $t4, $t1, 11
    ctx->r12 = S32(ctx->r9 << 11);
    // 0x8009D81C: addiu       $t4, $t4, 0x47FF
    ctx->r12 = ADD32(ctx->r12, 0X47FF);
    // 0x8009D820: ori         $t2, $zero, 0x6
    ctx->r10 = 0 | 0X6;
    // 0x8009D824: subu        $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    // 0x8009D828: ori         $t3, $zero, 0x1
    ctx->r11 = 0 | 0X1;
    // 0x8009D82C: addiu       $at, $t2, -0x1
    ctx->r1 = ADD32(ctx->r10, -0X1);
    // 0x8009D830: sllv        $t3, $t3, $at
    ctx->r11 = S32(ctx->r11 << (ctx->r1 & 31));
    // 0x8009D834: ori         $t6, $zero, 0xD
    ctx->r14 = 0 | 0XD;
    // 0x8009D838: addu        $t8, $a2, $zero
    ctx->r24 = ADD32(ctx->r6, 0);
L_8009D83C:
    // 0x8009D83C: lh          $t5, 0x0($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X0);
    // 0x8009D840: nop

    // 0x8009D844: sll         $t5, $t5, 13
    ctx->r13 = S32(ctx->r13 << 13);
    // 0x8009D848: addiu       $t5, $t5, -0x7000
    ctx->r13 = ADD32(ctx->r13, -0X7000);
    // 0x8009D84C: mult        $t5, $t4
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009D850: mflo        $t5
    ctx->r13 = lo;
    // 0x8009D854: addiu       $t5, $t5, 0x4000
    ctx->r13 = ADD32(ctx->r13, 0X4000);
    // 0x8009D858: sra         $t5, $t5, 15
    ctx->r13 = S32(SIGNED(ctx->r13) >> 15);
    // 0x8009D85C: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8009D860: srav        $t5, $t5, $t2
    ctx->r13 = S32(SIGNED(ctx->r13) >> (ctx->r10 & 31));
    // 0x8009D864: sh          $t5, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r13;
    // 0x8009D868: addiu       $t6, $t6, -0x1
    ctx->r14 = ADD32(ctx->r14, -0X1);
    // 0x8009D86C: bgtz        $t6, L_8009D83C
    if (SIGNED(ctx->r14) > 0) {
        // 0x8009D870: addiu       $t8, $t8, 0x2
        ctx->r24 = ADD32(ctx->r24, 0X2);
            goto L_8009D83C;
    }
    // 0x8009D870: addiu       $t8, $t8, 0x2
    ctx->r24 = ADD32(ctx->r24, 0X2);
    // 0x8009D874: addu        $t9, $a3, $zero
    ctx->r25 = ADD32(ctx->r7, 0);
    // 0x8009D878: ori         $t6, $zero, 0x28
    ctx->r14 = 0 | 0X28;
L_8009D87C:
    // 0x8009D87C: sh          $zero, 0x0($t9)
    MEM_H(0X0, ctx->r25) = 0;
    // 0x8009D880: addiu       $t6, $t6, -0x1
    ctx->r14 = ADD32(ctx->r14, -0X1);
    // 0x8009D884: bgtz        $t6, L_8009D87C
    if (SIGNED(ctx->r14) > 0) {
        // 0x8009D888: addiu       $t9, $t9, 0x2
        ctx->r25 = ADD32(ctx->r25, 0X2);
            goto L_8009D87C;
    }
    // 0x8009D888: addiu       $t9, $t9, 0x2
    ctx->r25 = ADD32(ctx->r25, 0X2);
    // 0x8009D88C: addu        $t9, $a3, $a1
    ctx->r25 = ADD32(ctx->r7, ctx->r5);
    // 0x8009D890: addu        $t9, $t9, $a1
    ctx->r25 = ADD32(ctx->r25, ctx->r5);
    // 0x8009D894: addu        $t8, $a2, $zero
    ctx->r24 = ADD32(ctx->r6, 0);
    // 0x8009D898: ori         $t6, $zero, 0xD
    ctx->r14 = 0 | 0XD;
L_8009D89C:
    // 0x8009D89C: lh          $at, 0x0($t8)
    ctx->r1 = MEM_H(ctx->r24, 0X0);
    // 0x8009D8A0: addiu       $t8, $t8, 0x2
    ctx->r24 = ADD32(ctx->r24, 0X2);
    // 0x8009D8A4: sh          $at, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r1;
    // 0x8009D8A8: addiu       $t6, $t6, -0x1
    ctx->r14 = ADD32(ctx->r14, -0X1);
    // 0x8009D8AC: bgtz        $t6, L_8009D89C
    if (SIGNED(ctx->r14) > 0) {
        // 0x8009D8B0: addiu       $t9, $t9, 0x6
        ctx->r25 = ADD32(ctx->r25, 0X6);
            goto L_8009D89C;
    }
    // 0x8009D8B0: addiu       $t9, $t9, 0x6
    ctx->r25 = ADD32(ctx->r25, 0X6);
    // 0x8009D8B4: jr          $ra
    // 0x8009D8B8: nop

    return;
    // 0x8009D8B8: nop

;}
RECOMP_FUNC void func_8009D8BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8009D8C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D8C4: lh          $t3, 0x166($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X166);
    // 0x8009D8C8: addiu       $at, $a1, -0x28
    ctx->r1 = ADD32(ctx->r5, -0X28);
    // 0x8009D8CC: bltz        $at, L_8009D8E4
    if (SIGNED(ctx->r1) < 0) {
        // 0x8009D8D0: nop
    
            goto L_8009D8E4;
    }
    // 0x8009D8D0: nop

    // 0x8009D8D4: addiu       $at, $at, -0x50
    ctx->r1 = ADD32(ctx->r1, -0X50);
    // 0x8009D8D8: bgtz        $at, L_8009D8E4
    if (SIGNED(ctx->r1) > 0) {
        // 0x8009D8DC: nop
    
            goto L_8009D8E4;
    }
    // 0x8009D8DC: nop

    // 0x8009D8E0: addu        $t3, $a1, $zero
    ctx->r11 = ADD32(ctx->r5, 0);
L_8009D8E4:
    // 0x8009D8E4: sh          $t3, 0x166($a0)
    MEM_H(0X166, ctx->r4) = ctx->r11;
    // 0x8009D8E8: addu        $at, $ra, $zero
    ctx->r1 = ADD32(ctx->r31, 0);
    // 0x8009D8EC: bltzal      $zero, L_8009D978
    if (SIGNED(0) < 0) {
        // 0x8009D8F0: nop

    func_8009D978(rdram, ctx);
        goto after_0;
    }
    // 0x8009D8F0: nop

    after_0:
    // 0x8009D8F4: addiu       $t0, $ra, 0x84
    ctx->r8 = ADD32(ctx->r31, 0X84);
    // 0x8009D8F8: addu        $ra, $at, $zero
    ctx->r31 = ADD32(ctx->r1, 0);
    // 0x8009D8FC: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x8009D900: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x8009D904: lhu         $t0, 0x0($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X0);
    // 0x8009D908: ori         $t2, $zero, 0x77
    ctx->r10 = 0 | 0X77;
    // 0x8009D90C: addiu       $t5, $a0, 0x0
    ctx->r13 = ADD32(ctx->r4, 0X0);
L_8009D910:
    // 0x8009D910: lhu         $t4, 0x50($t5)
    ctx->r12 = MEM_HU(ctx->r13, 0X50);
    // 0x8009D914: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x8009D918: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
    // 0x8009D91C: bgez        $t2, L_8009D910
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8009D920: addiu       $t5, $t5, 0x2
        ctx->r13 = ADD32(ctx->r13, 0X2);
            goto L_8009D910;
    }
    // 0x8009D920: addiu       $t5, $t5, 0x2
    ctx->r13 = ADD32(ctx->r13, 0X2);
    // 0x8009D924: ori         $t2, $zero, 0x27
    ctx->r10 = 0 | 0X27;
    // 0x8009D928: addiu       $t6, $a0, 0x0
    ctx->r14 = ADD32(ctx->r4, 0X0);
    // 0x8009D92C: addiu       $t5, $a0, 0x0
    ctx->r13 = ADD32(ctx->r4, 0X0);
    // 0x8009D930: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x8009D934: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x8009D938: addu        $t7, $a3, $zero
    ctx->r15 = ADD32(ctx->r7, 0);
L_8009D93C:
    // 0x8009D93C: lh          $t1, 0xF0($t5)
    ctx->r9 = MEM_H(ctx->r13, 0XF0);
    // 0x8009D940: addiu       $t5, $t5, 0x2
    ctx->r13 = ADD32(ctx->r13, 0X2);
    // 0x8009D944: mult        $t1, $t0
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009D948: mflo        $t1
    ctx->r9 = lo;
    // 0x8009D94C: addiu       $t1, $t1, 0x4000
    ctx->r9 = ADD32(ctx->r9, 0X4000);
    // 0x8009D950: sra         $t1, $t1, 15
    ctx->r9 = S32(SIGNED(ctx->r9) >> 15);
    // 0x8009D954: lh          $at, 0x0($t7)
    ctx->r1 = MEM_H(ctx->r15, 0X0);
    // 0x8009D958: addiu       $t7, $t7, 0x2
    ctx->r15 = ADD32(ctx->r15, 0X2);
    // 0x8009D95C: addu        $t1, $t1, $at
    ctx->r9 = ADD32(ctx->r9, ctx->r1);
    // 0x8009D960: sh          $t1, 0xF0($t6)
    MEM_H(0XF0, ctx->r14) = ctx->r9;
    // 0x8009D964: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x8009D968: bgtz        $t2, L_8009D93C
    if (SIGNED(ctx->r10) > 0) {
        // 0x8009D96C: addiu       $t2, $t2, -0x1
        ctx->r10 = ADD32(ctx->r10, -0X1);
            goto L_8009D93C;
    }
    // 0x8009D96C: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x8009D970: jr          $ra
    // 0x8009D974: nop

    return;
    // 0x8009D974: nop

;}
RECOMP_FUNC void func_8009D978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8009D980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
L_8009D980:
    // 0x8009D980: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x8009D984: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x8009D988: sll         $t5, $t9, 16
    ctx->r13 = S32(ctx->r25 << 16);
    // 0x8009D98C: sra         $t5, $t5, 16
    ctx->r13 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8009D990: mult        $s7, $t5
    result = S64(S32(ctx->r23)) * S64(S32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009D994: mflo        $at
    ctx->r1 = lo;
    // 0x8009D998: addiu       $at, $at, 0x4000
    ctx->r1 = ADD32(ctx->r1, 0X4000);
    // 0x8009D99C: sra         $at, $at, 15
    ctx->r1 = S32(SIGNED(ctx->r1) >> 15);
    // 0x8009D9A0: subu        $t2, $t2, $at
    ctx->r10 = SUB32(ctx->r10, ctx->r1);
    // 0x8009D9A4: sra         $t5, $t9, 16
    ctx->r13 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8009D9A8: mult        $s6, $t5
    result = S64(S32(ctx->r22)) * S64(S32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009D9AC: mflo        $at
    ctx->r1 = lo;
    // 0x8009D9B0: addiu       $at, $at, 0x4000
    ctx->r1 = ADD32(ctx->r1, 0X4000);
    // 0x8009D9B4: sra         $at, $at, 15
    ctx->r1 = S32(SIGNED(ctx->r1) >> 15);
    // 0x8009D9B8: subu        $t2, $t2, $at
    ctx->r10 = SUB32(ctx->r10, ctx->r1);
    // 0x8009D9BC: mult        $t5, $t2
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009D9C0: mflo        $at
    ctx->r1 = lo;
    // 0x8009D9C4: addiu       $at, $at, 0x4000
    ctx->r1 = ADD32(ctx->r1, 0X4000);
    // 0x8009D9C8: sra         $at, $at, 15
    ctx->r1 = S32(SIGNED(ctx->r1) >> 15);
    // 0x8009D9CC: addu        $s7, $at, $s6
    ctx->r23 = ADD32(ctx->r1, ctx->r22);
    // 0x8009D9D0: sll         $t5, $t8, 16
    ctx->r13 = S32(ctx->r24 << 16);
    // 0x8009D9D4: sra         $t5, $t5, 16
    ctx->r13 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8009D9D8: mult        $s5, $t5
    result = S64(S32(ctx->r21)) * S64(S32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009D9DC: mflo        $at
    ctx->r1 = lo;
    // 0x8009D9E0: addiu       $at, $at, 0x4000
    ctx->r1 = ADD32(ctx->r1, 0X4000);
    // 0x8009D9E4: sra         $at, $at, 15
    ctx->r1 = S32(SIGNED(ctx->r1) >> 15);
    // 0x8009D9E8: subu        $t2, $t2, $at
    ctx->r10 = SUB32(ctx->r10, ctx->r1);
    // 0x8009D9EC: mult        $t5, $t2
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009D9F0: mflo        $at
    ctx->r1 = lo;
    // 0x8009D9F4: addiu       $at, $at, 0x4000
    ctx->r1 = ADD32(ctx->r1, 0X4000);
    // 0x8009D9F8: sra         $at, $at, 15
    ctx->r1 = S32(SIGNED(ctx->r1) >> 15);
    // 0x8009D9FC: addu        $s6, $at, $s5
    ctx->r22 = ADD32(ctx->r1, ctx->r21);
    // 0x8009DA00: sra         $t5, $t8, 16
    ctx->r13 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8009DA04: mult        $s4, $t5
    result = S64(S32(ctx->r20)) * S64(S32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009DA08: mflo        $at
    ctx->r1 = lo;
    // 0x8009DA0C: addiu       $at, $at, 0x4000
    ctx->r1 = ADD32(ctx->r1, 0X4000);
    // 0x8009DA10: sra         $at, $at, 15
    ctx->r1 = S32(SIGNED(ctx->r1) >> 15);
    // 0x8009DA14: subu        $t2, $t2, $at
    ctx->r10 = SUB32(ctx->r10, ctx->r1);
    // 0x8009DA18: mult        $t5, $t2
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009DA1C: mflo        $at
    ctx->r1 = lo;
    // 0x8009DA20: addiu       $at, $at, 0x4000
    ctx->r1 = ADD32(ctx->r1, 0X4000);
    // 0x8009DA24: sra         $at, $at, 15
    ctx->r1 = S32(SIGNED(ctx->r1) >> 15);
    // 0x8009DA28: addu        $s5, $at, $s4
    ctx->r21 = ADD32(ctx->r1, ctx->r20);
    // 0x8009DA2C: sll         $t5, $t7, 16
    ctx->r13 = S32(ctx->r15 << 16);
    // 0x8009DA30: sra         $t5, $t5, 16
    ctx->r13 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8009DA34: mult        $s3, $t5
    result = S64(S32(ctx->r19)) * S64(S32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009DA38: mflo        $at
    ctx->r1 = lo;
    // 0x8009DA3C: addiu       $at, $at, 0x4000
    ctx->r1 = ADD32(ctx->r1, 0X4000);
    // 0x8009DA40: sra         $at, $at, 15
    ctx->r1 = S32(SIGNED(ctx->r1) >> 15);
    // 0x8009DA44: subu        $t2, $t2, $at
    ctx->r10 = SUB32(ctx->r10, ctx->r1);
    // 0x8009DA48: mult        $t5, $t2
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009DA4C: mflo        $at
    ctx->r1 = lo;
    // 0x8009DA50: addiu       $at, $at, 0x4000
    ctx->r1 = ADD32(ctx->r1, 0X4000);
    // 0x8009DA54: sra         $at, $at, 15
    ctx->r1 = S32(SIGNED(ctx->r1) >> 15);
    // 0x8009DA58: addu        $s4, $at, $s3
    ctx->r20 = ADD32(ctx->r1, ctx->r19);
    // 0x8009DA5C: sra         $t5, $t7, 16
    ctx->r13 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8009DA60: mult        $s2, $t5
    result = S64(S32(ctx->r18)) * S64(S32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009DA64: mflo        $at
    ctx->r1 = lo;
    // 0x8009DA68: addiu       $at, $at, 0x4000
    ctx->r1 = ADD32(ctx->r1, 0X4000);
    // 0x8009DA6C: sra         $at, $at, 15
    ctx->r1 = S32(SIGNED(ctx->r1) >> 15);
    // 0x8009DA70: subu        $t2, $t2, $at
    ctx->r10 = SUB32(ctx->r10, ctx->r1);
    // 0x8009DA74: mult        $t5, $t2
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009DA78: mflo        $at
    ctx->r1 = lo;
    // 0x8009DA7C: addiu       $at, $at, 0x4000
    ctx->r1 = ADD32(ctx->r1, 0X4000);
    // 0x8009DA80: sra         $at, $at, 15
    ctx->r1 = S32(SIGNED(ctx->r1) >> 15);
    // 0x8009DA84: addu        $s3, $at, $s2
    ctx->r19 = ADD32(ctx->r1, ctx->r18);
    // 0x8009DA88: sll         $t5, $t6, 16
    ctx->r13 = S32(ctx->r14 << 16);
    // 0x8009DA8C: sra         $t5, $t5, 16
    ctx->r13 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8009DA90: mult        $s1, $t5
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009DA94: mflo        $at
    ctx->r1 = lo;
    // 0x8009DA98: addiu       $at, $at, 0x4000
    ctx->r1 = ADD32(ctx->r1, 0X4000);
    // 0x8009DA9C: sra         $at, $at, 15
    ctx->r1 = S32(SIGNED(ctx->r1) >> 15);
    // 0x8009DAA0: subu        $t2, $t2, $at
    ctx->r10 = SUB32(ctx->r10, ctx->r1);
    // 0x8009DAA4: mult        $t5, $t2
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009DAA8: mflo        $at
    ctx->r1 = lo;
    // 0x8009DAAC: addiu       $at, $at, 0x4000
    ctx->r1 = ADD32(ctx->r1, 0X4000);
    // 0x8009DAB0: sra         $at, $at, 15
    ctx->r1 = S32(SIGNED(ctx->r1) >> 15);
    // 0x8009DAB4: addu        $s2, $at, $s1
    ctx->r18 = ADD32(ctx->r1, ctx->r17);
    // 0x8009DAB8: sra         $t5, $t6, 16
    ctx->r13 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8009DABC: mult        $s0, $t5
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009DAC0: mflo        $at
    ctx->r1 = lo;
    // 0x8009DAC4: addiu       $at, $at, 0x4000
    ctx->r1 = ADD32(ctx->r1, 0X4000);
    // 0x8009DAC8: sra         $at, $at, 15
    ctx->r1 = S32(SIGNED(ctx->r1) >> 15);
    // 0x8009DACC: subu        $t2, $t2, $at
    ctx->r10 = SUB32(ctx->r10, ctx->r1);
    // 0x8009DAD0: mult        $t5, $t2
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009DAD4: mflo        $at
    ctx->r1 = lo;
    // 0x8009DAD8: addiu       $at, $at, 0x4000
    ctx->r1 = ADD32(ctx->r1, 0X4000);
    // 0x8009DADC: sra         $at, $at, 15
    ctx->r1 = S32(SIGNED(ctx->r1) >> 15);
    // 0x8009DAE0: addu        $s1, $at, $s0
    ctx->r17 = ADD32(ctx->r1, ctx->r16);
    // 0x8009DAE4: addu        $s0, $t2, $zero
    ctx->r16 = ADD32(ctx->r10, 0);
    // 0x8009DAE8: ori         $at, $zero, 0x6E14
    ctx->r1 = 0 | 0X6E14;
    // 0x8009DAEC: mult        $at, $a3
    result = S64(S32(ctx->r1)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009DAF0: mflo        $at
    ctx->r1 = lo;
    // 0x8009DAF4: addiu       $at, $at, 0x4000
    ctx->r1 = ADD32(ctx->r1, 0X4000);
    // 0x8009DAF8: sra         $at, $at, 15
    ctx->r1 = S32(SIGNED(ctx->r1) >> 15);
    // 0x8009DAFC: addu        $t2, $t2, $at
    ctx->r10 = ADD32(ctx->r10, ctx->r1);
    // 0x8009DB00: addu        $a3, $t2, $zero
    ctx->r7 = ADD32(ctx->r10, 0);
    // 0x8009DB04: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8009DB08: sra         $at, $t2, 15
    ctx->r1 = S32(SIGNED(ctx->r10) >> 15);
    // 0x8009DB0C: addiu       $at, $at, 0x1
    ctx->r1 = ADD32(ctx->r1, 0X1);
    // 0x8009DB10: sra         $at, $at, 1
    ctx->r1 = S32(SIGNED(ctx->r1) >> 1);
    // 0x8009DB14: beq         $at, $zero, L_8009DB28
    if (ctx->r1 == 0) {
        // 0x8009DB18: nop
    
            goto L_8009DB28;
    }
    // 0x8009DB18: nop

    // 0x8009DB1C: bltz        $at, L_8009DB28
    if (SIGNED(ctx->r1) < 0) {
        // 0x8009DB20: addiu       $t2, $zero, -0x8000
        ctx->r10 = ADD32(0, -0X8000);
            goto L_8009DB28;
    }
    // 0x8009DB20: addiu       $t2, $zero, -0x8000
    ctx->r10 = ADD32(0, -0X8000);
    // 0x8009DB24: addiu       $t2, $zero, 0x7FFF
    ctx->r10 = ADD32(0, 0X7FFF);
L_8009DB28:
    // 0x8009DB28: andi        $t2, $t2, 0xFFF8
    ctx->r10 = ctx->r10 & 0XFFF8;
    // 0x8009DB2C: sh          $t2, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r10;
    // 0x8009DB30: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x8009DB34: bgtz        $t3, L_8009D980
    if (SIGNED(ctx->r11) > 0) {
        // 0x8009DB38: addiu       $t3, $t3, -0x1
        ctx->r11 = ADD32(ctx->r11, -0X1);
            goto L_8009D980;
    }
    // 0x8009DB38: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // 0x8009DB3C: jr          $ra
    // 0x8009DB40: nop

    return;
    // 0x8009DB40: nop

;}
RECOMP_FUNC void func_8009DB44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
L_8009D980:
    // 0x8009DB44: addiu       $sp, $sp, -0x44
    ctx->r29 = ADD32(ctx->r29, -0X44);
    // 0x8009DB48: sw          $ra, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r31;
    // 0x8009DB4C: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x8009DB50: sw          $a1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r5;
    // 0x8009DB54: sw          $a2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r6;
    // 0x8009DB58: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8009DB5C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8009DB60: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8009DB64: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8009DB68: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8009DB6C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8009DB70: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8009DB74: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8009DB78: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8009DB7C: addiu       $at, $a0, 0x140
    ctx->r1 = ADD32(ctx->r4, 0X140);
    // 0x8009DB80: lw          $s0, 0x0($at)
    ctx->r16 = MEM_W(ctx->r1, 0X0);
    // 0x8009DB84: lw          $s1, 0x4($at)
    ctx->r17 = MEM_W(ctx->r1, 0X4);
    // 0x8009DB88: lw          $s2, 0x8($at)
    ctx->r18 = MEM_W(ctx->r1, 0X8);
    // 0x8009DB8C: lw          $s3, 0xC($at)
    ctx->r19 = MEM_W(ctx->r1, 0XC);
    // 0x8009DB90: lw          $s4, 0x10($at)
    ctx->r20 = MEM_W(ctx->r1, 0X10);
    // 0x8009DB94: lw          $s5, 0x14($at)
    ctx->r21 = MEM_W(ctx->r1, 0X14);
    // 0x8009DB98: lw          $s6, 0x18($at)
    ctx->r22 = MEM_W(ctx->r1, 0X18);
    // 0x8009DB9C: lw          $s7, 0x1C($at)
    ctx->r23 = MEM_W(ctx->r1, 0X1C);
    // 0x8009DBA0: lh          $a3, 0x164($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X164);
    // 0x8009DBA4: bltzal      $zero, L_8009DD3C
    if (SIGNED(0) < 0) {
        // 0x8009DBA8: nop

    func_8009DD3C(rdram, ctx);
        goto after_0;
    }
    // 0x8009DBA8: nop

    after_0:
    // 0x8009DBAC: addiu       $t3, $ra, 0x190
    ctx->r11 = ADD32(ctx->r31, 0X190);
    // 0x8009DBB0: bgezal      $zero, L_8009DC98
    if (SIGNED(0) >= 0) {
        // 0x8009DBB4: nop

    func_8009DC98(rdram, ctx);
        goto after_1;
    }
    // 0x8009DBB4: nop

    after_1:
    // 0x8009DBB8: addiu       $t1, $a1, 0x0
    ctx->r9 = ADD32(ctx->r5, 0X0);
    // 0x8009DBBC: addiu       $t0, $a2, 0x0
    ctx->r8 = ADD32(ctx->r6, 0X0);
    // 0x8009DBC0: bgezal      $zero, L_8009D980
    if (SIGNED(0) >= 0) {
        // 0x8009DBC4: ori         $t3, $zero, 0xC
    ctx->r11 = 0 | 0XC;
    func_8009D980(rdram, ctx);
        goto after_2;
    }
    // 0x8009DBC4: ori         $t3, $zero, 0xC
    ctx->r11 = 0 | 0XC;
    after_2:
    // 0x8009DBC8: bltzal      $zero, L_8009DD54
    if (SIGNED(0) < 0) {
        // 0x8009DBCC: nop

    func_8009DD54(rdram, ctx);
        goto after_3;
    }
    // 0x8009DBCC: nop

    after_3:
    // 0x8009DBD0: addiu       $t3, $ra, 0x184
    ctx->r11 = ADD32(ctx->r31, 0X184);
    // 0x8009DBD4: bgezal      $zero, L_8009DC98
    if (SIGNED(0) >= 0) {
        // 0x8009DBD8: nop

    func_8009DC98(rdram, ctx);
        goto after_4;
    }
    // 0x8009DBD8: nop

    after_4:
    // 0x8009DBDC: addiu       $t1, $a1, 0x1A
    ctx->r9 = ADD32(ctx->r5, 0X1A);
    // 0x8009DBE0: addiu       $t0, $a2, 0x1A
    ctx->r8 = ADD32(ctx->r6, 0X1A);
    // 0x8009DBE4: bgezal      $zero, L_8009D980
    if (SIGNED(0) >= 0) {
        // 0x8009DBE8: ori         $t3, $zero, 0xD
    ctx->r11 = 0 | 0XD;
    func_8009D980(rdram, ctx);
        goto after_5;
    }
    // 0x8009DBE8: ori         $t3, $zero, 0xD
    ctx->r11 = 0 | 0XD;
    after_5:
    // 0x8009DBEC: bltzal      $zero, L_8009DD64
    if (SIGNED(0) < 0) {
        // 0x8009DBF0: nop

    func_8009DD64(rdram, ctx);
        goto after_6;
    }
    // 0x8009DBF0: nop

    after_6:
    // 0x8009DBF4: addiu       $t3, $ra, 0x170
    ctx->r11 = ADD32(ctx->r31, 0X170);
    // 0x8009DBF8: bgezal      $zero, L_8009DC98
    if (SIGNED(0) >= 0) {
        // 0x8009DBFC: nop

    func_8009DC98(rdram, ctx);
        goto after_7;
    }
    // 0x8009DBFC: nop

    after_7:
    // 0x8009DC00: addiu       $t1, $a1, 0x36
    ctx->r9 = ADD32(ctx->r5, 0X36);
    // 0x8009DC04: addiu       $t0, $a2, 0x36
    ctx->r8 = ADD32(ctx->r6, 0X36);
    // 0x8009DC08: bgezal      $zero, L_8009D980
    if (SIGNED(0) >= 0) {
        // 0x8009DC0C: ori         $t3, $zero, 0xC
    ctx->r11 = 0 | 0XC;
    func_8009D980(rdram, ctx);
        goto after_8;
    }
    // 0x8009DC0C: ori         $t3, $zero, 0xC
    ctx->r11 = 0 | 0XC;
    after_8:
    // 0x8009DC10: bltzal      $zero, L_8009DD7C
    if (SIGNED(0) < 0) {
        // 0x8009DC14: nop

    func_8009DD7C(rdram, ctx);
        goto after_9;
    }
    // 0x8009DC14: nop

    after_9:
    // 0x8009DC18: addiu       $t3, $ra, 0x164
    ctx->r11 = ADD32(ctx->r31, 0X164);
    // 0x8009DC1C: bgezal      $zero, L_8009DC98
    if (SIGNED(0) >= 0) {
        // 0x8009DC20: nop

    func_8009DC98(rdram, ctx);
        goto after_10;
    }
    // 0x8009DC20: nop

    after_10:
    // 0x8009DC24: addiu       $t1, $a1, 0x50
    ctx->r9 = ADD32(ctx->r5, 0X50);
    // 0x8009DC28: addiu       $t0, $a2, 0x50
    ctx->r8 = ADD32(ctx->r6, 0X50);
    // 0x8009DC2C: bgezal      $zero, L_8009D980
    if (SIGNED(0) >= 0) {
        // 0x8009DC30: ori         $t3, $zero, 0x77
    ctx->r11 = 0 | 0X77;
    func_8009D980(rdram, ctx);
        goto after_11;
    }
    // 0x8009DC30: ori         $t3, $zero, 0x77
    ctx->r11 = 0 | 0X77;
    after_11:
    // 0x8009DC34: addiu       $at, $a0, 0x140
    ctx->r1 = ADD32(ctx->r4, 0X140);
    // 0x8009DC38: sw          $s0, 0x0($at)
    MEM_W(0X0, ctx->r1) = ctx->r16;
    // 0x8009DC3C: sw          $s1, 0x4($at)
    MEM_W(0X4, ctx->r1) = ctx->r17;
    // 0x8009DC40: sw          $s2, 0x8($at)
    MEM_W(0X8, ctx->r1) = ctx->r18;
    // 0x8009DC44: sw          $s3, 0xC($at)
    MEM_W(0XC, ctx->r1) = ctx->r19;
    // 0x8009DC48: sw          $s4, 0x10($at)
    MEM_W(0X10, ctx->r1) = ctx->r20;
    // 0x8009DC4C: sw          $s5, 0x14($at)
    MEM_W(0X14, ctx->r1) = ctx->r21;
    // 0x8009DC50: sw          $s6, 0x18($at)
    MEM_W(0X18, ctx->r1) = ctx->r22;
    // 0x8009DC54: sw          $s7, 0x1C($at)
    MEM_W(0X1C, ctx->r1) = ctx->r23;
    // 0x8009DC58: sh          $a3, 0x164($a0)
    MEM_H(0X164, ctx->r4) = ctx->r7;
    // 0x8009DC5C: lw          $ra, 0x0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X0);
    // 0x8009DC60: lw          $a0, 0x4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4);
    // 0x8009DC64: lw          $a1, 0x8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8);
    // 0x8009DC68: lw          $a2, 0xC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC);
    // 0x8009DC6C: lw          $a3, 0x10($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X10);
    // 0x8009DC70: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8009DC74: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8009DC78: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8009DC7C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8009DC80: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8009DC84: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8009DC88: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8009DC8C: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8009DC90: jr          $ra
    // 0x8009DC94: addiu       $sp, $sp, 0x44
    ctx->r29 = ADD32(ctx->r29, 0X44);
    return;
    // 0x8009DC94: addiu       $sp, $sp, 0x44
    ctx->r29 = ADD32(ctx->r29, 0X44);
;}
RECOMP_FUNC void func_8009DC98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009DC98: lh          $at, 0x188($a0)
    ctx->r1 = MEM_H(ctx->r4, 0X188);
    // 0x8009DC9C: addiu       $t0, $a0, 0x168
    ctx->r8 = ADD32(ctx->r4, 0X168);
    // 0x8009DCA0: beq         $at, $zero, L_8009DCB0
    if (ctx->r1 == 0) {
        // 0x8009DCA4: addiu       $t1, $t0, 0x10
        ctx->r9 = ADD32(ctx->r8, 0X10);
            goto L_8009DCB0;
    }
    // 0x8009DCA4: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x8009DCA8: addu        $t0, $t1, $zero
    ctx->r8 = ADD32(ctx->r9, 0);
    // 0x8009DCAC: addiu       $t1, $a0, 0x168
    ctx->r9 = ADD32(ctx->r4, 0X168);
L_8009DCB0:
    // 0x8009DCB0: addu        $t5, $ra, $zero
    ctx->r13 = ADD32(ctx->r31, 0);
    // 0x8009DCB4: lh          $t2, 0x0($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X0);
    // 0x8009DCB8: jalr        $t3
    // 0x8009DCBC: lh          $t4, 0x0($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X0);
    LOOKUP_FUNC(ctx->r11)(rdram, ctx);
        goto after_0;
    // 0x8009DCBC: lh          $t4, 0x0($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X0);
    after_0:
    // 0x8009DCC0: sll         $t6, $t2, 16
    ctx->r14 = S32(ctx->r10 << 16);
    // 0x8009DCC4: lh          $t2, 0x2($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X2);
    // 0x8009DCC8: jalr        $t3
    // 0x8009DCCC: lh          $t4, 0x2($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X2);
    LOOKUP_FUNC(ctx->r11)(rdram, ctx);
        goto after_1;
    // 0x8009DCCC: lh          $t4, 0x2($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X2);
    after_1:
    // 0x8009DCD0: or          $t6, $t6, $t2
    ctx->r14 = ctx->r14 | ctx->r10;
    // 0x8009DCD4: lh          $t2, 0x4($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X4);
    // 0x8009DCD8: jalr        $t3
    // 0x8009DCDC: lh          $t4, 0x4($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X4);
    LOOKUP_FUNC(ctx->r11)(rdram, ctx);
        goto after_2;
    // 0x8009DCDC: lh          $t4, 0x4($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X4);
    after_2:
    // 0x8009DCE0: sll         $t7, $t2, 16
    ctx->r15 = S32(ctx->r10 << 16);
    // 0x8009DCE4: lh          $t2, 0x6($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X6);
    // 0x8009DCE8: jalr        $t3
    // 0x8009DCEC: lh          $t4, 0x6($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X6);
    LOOKUP_FUNC(ctx->r11)(rdram, ctx);
        goto after_3;
    // 0x8009DCEC: lh          $t4, 0x6($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X6);
    after_3:
    // 0x8009DCF0: or          $t7, $t7, $t2
    ctx->r15 = ctx->r15 | ctx->r10;
    // 0x8009DCF4: lh          $t2, 0x8($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X8);
    // 0x8009DCF8: jalr        $t3
    // 0x8009DCFC: lh          $t4, 0x8($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X8);
    LOOKUP_FUNC(ctx->r11)(rdram, ctx);
        goto after_4;
    // 0x8009DCFC: lh          $t4, 0x8($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X8);
    after_4:
    // 0x8009DD00: sll         $t8, $t2, 16
    ctx->r24 = S32(ctx->r10 << 16);
    // 0x8009DD04: lh          $t2, 0xA($t0)
    ctx->r10 = MEM_H(ctx->r8, 0XA);
    // 0x8009DD08: jalr        $t3
    // 0x8009DD0C: lh          $t4, 0xA($t1)
    ctx->r12 = MEM_H(ctx->r9, 0XA);
    LOOKUP_FUNC(ctx->r11)(rdram, ctx);
        goto after_5;
    // 0x8009DD0C: lh          $t4, 0xA($t1)
    ctx->r12 = MEM_H(ctx->r9, 0XA);
    after_5:
    // 0x8009DD10: or          $t8, $t8, $t2
    ctx->r24 = ctx->r24 | ctx->r10;
    // 0x8009DD14: lh          $t2, 0xC($t0)
    ctx->r10 = MEM_H(ctx->r8, 0XC);
    // 0x8009DD18: jalr        $t3
    // 0x8009DD1C: lh          $t4, 0xC($t1)
    ctx->r12 = MEM_H(ctx->r9, 0XC);
    LOOKUP_FUNC(ctx->r11)(rdram, ctx);
        goto after_6;
    // 0x8009DD1C: lh          $t4, 0xC($t1)
    ctx->r12 = MEM_H(ctx->r9, 0XC);
    after_6:
    // 0x8009DD20: sll         $t9, $t2, 16
    ctx->r25 = S32(ctx->r10 << 16);
    // 0x8009DD24: lh          $t2, 0xE($t0)
    ctx->r10 = MEM_H(ctx->r8, 0XE);
    // 0x8009DD28: jalr        $t3
    // 0x8009DD2C: lh          $t4, 0xE($t1)
    ctx->r12 = MEM_H(ctx->r9, 0XE);
    LOOKUP_FUNC(ctx->r11)(rdram, ctx);
        goto after_7;
    // 0x8009DD2C: lh          $t4, 0xE($t1)
    ctx->r12 = MEM_H(ctx->r9, 0XE);
    after_7:
    // 0x8009DD30: addu        $ra, $t5, $zero
    ctx->r31 = ADD32(ctx->r13, 0);
    // 0x8009DD34: jr          $ra
    // 0x8009DD38: or          $t9, $t9, $t2
    ctx->r25 = ctx->r25 | ctx->r10;
    return;
    // 0x8009DD38: or          $t9, $t9, $t2
    ctx->r25 = ctx->r25 | ctx->r10;
;}
RECOMP_FUNC void func_8009DD3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009DD3C: sra         $t2, $t2, 2
    ctx->r10 = S32(SIGNED(ctx->r10) >> 2);
    // 0x8009DD40: sra         $t4, $t4, 1
    ctx->r12 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8009DD44: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x8009DD48: sra         $t4, $t4, 1
    ctx->r12 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8009DD4C: b           L_8009DD7C
    // 0x8009DD50: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    func_8009DD7C(rdram, ctx);
    return;
    // 0x8009DD50: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
;}
RECOMP_FUNC void func_8009DD54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009DD54: sra         $t2, $t2, 1
    ctx->r10 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8009DD58: sra         $t4, $t4, 1
    ctx->r12 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8009DD5C: b           L_8009DD7C
    // 0x8009DD60: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    func_8009DD7C(rdram, ctx);
    return;
    // 0x8009DD60: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
;}
RECOMP_FUNC void func_8009DD64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009DD64: sra         $t2, $t2, 1
    ctx->r10 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8009DD68: sra         $t4, $t4, 2
    ctx->r12 = S32(SIGNED(ctx->r12) >> 2);
    // 0x8009DD6C: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x8009DD70: sra         $t2, $t2, 1
    ctx->r10 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8009DD74: b           L_8009DD7C
    // 0x8009DD78: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    func_8009DD7C(rdram, ctx);
    return;
    // 0x8009DD78: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
;}
RECOMP_FUNC void func_8009DD7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009DD7C: bgez        $t2, L_8009DD8C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8009DD80: addu        $t4, $zero, $zero
        ctx->r12 = ADD32(0, 0);
            goto L_8009DD8C;
    }
    // 0x8009DD80: addu        $t4, $zero, $zero
    ctx->r12 = ADD32(0, 0);
    // 0x8009DD84: negu        $t2, $t2
    ctx->r10 = SUB32(0, ctx->r10);
    // 0x8009DD88: ori         $t4, $zero, 0x1
    ctx->r12 = 0 | 0X1;
L_8009DD8C:
    // 0x8009DD8C: addiu       $at, $t2, -0x2B33
    ctx->r1 = ADD32(ctx->r10, -0X2B33);
    // 0x8009DD90: bltz        $at, L_8009DDAC
    if (SIGNED(ctx->r1) < 0) {
        // 0x8009DD94: sll         $at, $t2, 1
        ctx->r1 = S32(ctx->r10 << 1);
            goto L_8009DDAC;
    }
    // 0x8009DD94: sll         $at, $t2, 1
    ctx->r1 = S32(ctx->r10 << 1);
    // 0x8009DD98: addiu       $at, $t2, -0x4E66
    ctx->r1 = ADD32(ctx->r10, -0X4E66);
    // 0x8009DD9C: bltz        $at, L_8009DDAC
    if (SIGNED(ctx->r1) < 0) {
        // 0x8009DDA0: addiu       $at, $t2, 0x2B33
        ctx->r1 = ADD32(ctx->r10, 0X2B33);
            goto L_8009DDAC;
    }
    // 0x8009DDA0: addiu       $at, $t2, 0x2B33
    ctx->r1 = ADD32(ctx->r10, 0X2B33);
    // 0x8009DDA4: sra         $at, $t2, 2
    ctx->r1 = S32(SIGNED(ctx->r10) >> 2);
    // 0x8009DDA8: addiu       $at, $at, 0x6600
    ctx->r1 = ADD32(ctx->r1, 0X6600);
L_8009DDAC:
    // 0x8009DDAC: addiu       $t2, $at, -0x7FFF
    ctx->r10 = ADD32(ctx->r1, -0X7FFF);
    // 0x8009DDB0: blez        $t2, L_8009DDBC
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8009DDB4: addu        $t2, $at, $zero
        ctx->r10 = ADD32(ctx->r1, 0);
            goto L_8009DDBC;
    }
    // 0x8009DDB4: addu        $t2, $at, $zero
    ctx->r10 = ADD32(ctx->r1, 0);
    // 0x8009DDB8: ori         $t2, $zero, 0x7FFF
    ctx->r10 = 0 | 0X7FFF;
L_8009DDBC:
    // 0x8009DDBC: bne         $t4, $zero, L_8009DDC8
    if (ctx->r12 != 0) {
        // 0x8009DDC0: negu        $t2, $t2
        ctx->r10 = SUB32(0, ctx->r10);
            goto L_8009DDC8;
    }
    // 0x8009DDC0: negu        $t2, $t2
    ctx->r10 = SUB32(0, ctx->r10);
    // 0x8009DDC4: negu        $t2, $t2
    ctx->r10 = SUB32(0, ctx->r10);
L_8009DDC8:
    // 0x8009DDC8: jr          $ra
    // 0x8009DDCC: andi        $t2, $t2, 0xFFFF
    ctx->r10 = ctx->r10 & 0XFFFF;
    return;
    // 0x8009DDCC: andi        $t2, $t2, 0xFFFF
    ctx->r10 = ctx->r10 & 0XFFFF;
;}
RECOMP_FUNC void func_800A5D80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5D80: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x800A5D84: sw          $s7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r23;
    // 0x800A5D88: addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // 0x800A5D8C: andi        $a0, $s7, 0xFF
    ctx->r4 = ctx->r23 & 0XFF;
    // 0x800A5D90: sw          $s0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r16;
    // 0x800A5D94: sb          $a1, 0x7C($sp)
    MEM_B(0X7C, ctx->r29) = ctx->r5;
    // 0x800A5D98: andi        $s0, $a1, 0xFF
    ctx->r16 = ctx->r5 & 0XFF;
    // 0x800A5D9C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800A5DA0: sw          $ra, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r31;
    // 0x800A5DA4: sw          $fp, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r30;
    // 0x800A5DA8: sw          $s6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r22;
    // 0x800A5DAC: sw          $s5, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r21;
    // 0x800A5DB0: sw          $s4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r20;
    // 0x800A5DB4: sw          $s3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r19;
    // 0x800A5DB8: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x800A5DBC: sw          $s1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r17;
    // 0x800A5DC0: sdc1        $f24, 0xD0($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0XD0, ctx->r29);
    // 0x800A5DC4: sdc1        $f22, 0xC8($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XC8, ctx->r29);
    // 0x800A5DC8: sdc1        $f20, 0xC0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XC0, ctx->r29);
    // 0x800A5DCC: jal         0x800AE928
    // 0x800A5DD0: sb          $a2, 0x7D($sp)
    MEM_B(0X7D, ctx->r29) = ctx->r6;
    func_800AE928(rdram, ctx);
        goto after_0;
    // 0x800A5DD0: sb          $a2, 0x7D($sp)
    MEM_B(0X7D, ctx->r29) = ctx->r6;
    after_0:
    // 0x800A5DD4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800A5DD8: beq         $v0, $zero, L_800A65E4
    if (ctx->r2 == 0) {
        // 0x800A5DDC: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800A65E4;
    }
    // 0x800A5DDC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A5DE0: addiu       $a0, $v0, 0xB40
    ctx->r4 = ADD32(ctx->r2, 0XB40);
    // 0x800A5DE4: lbu         $v0, 0x13($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X13);
    // 0x800A5DE8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800A5DEC: sb          $v0, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r2;
    // 0x800A5DF0: lbu         $t0, 0x20($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X20);
    // 0x800A5DF4: sb          $t0, 0x88($sp)
    MEM_B(0X88, ctx->r29) = ctx->r8;
    // 0x800A5DF8: lbu         $t1, 0x21($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X21);
    // 0x800A5DFC: sb          $t1, 0x89($sp)
    MEM_B(0X89, ctx->r29) = ctx->r9;
    // 0x800A5E00: lbu         $t0, 0x22($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X22);
    // 0x800A5E04: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800A5E08: beq         $s0, $v0, L_800A5E20
    if (ctx->r16 == ctx->r2) {
        // 0x800A5E0C: sb          $t0, 0x8A($sp)
        MEM_B(0X8A, ctx->r29) = ctx->r8;
            goto L_800A5E20;
    }
    // 0x800A5E0C: sb          $t0, 0x8A($sp)
    MEM_B(0X8A, ctx->r29) = ctx->r8;
    // 0x800A5E10: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x800A5E14: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x800A5E18: beq         $v0, $zero, L_800A5E50
    if (ctx->r2 == 0) {
        // 0x800A5E1C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800A5E50;
    }
    // 0x800A5E1C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800A5E20:
    // 0x800A5E20: lbu         $v1, 0x23($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X23);
    // 0x800A5E24: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x800A5E28: sb          $v0, 0x20($a0)
    MEM_B(0X20, ctx->r4) = ctx->r2;
    // 0x800A5E2C: sb          $v0, 0x21($a0)
    MEM_B(0X21, ctx->r4) = ctx->r2;
    // 0x800A5E30: beq         $v1, $zero, L_800A5E44
    if (ctx->r3 == 0) {
        // 0x800A5E34: sb          $v0, 0x22($a0)
        MEM_B(0X22, ctx->r4) = ctx->r2;
            goto L_800A5E44;
    }
    // 0x800A5E34: sb          $v0, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r2;
    // 0x800A5E38: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x800A5E3C: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x800A5E40: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
L_800A5E44:
    // 0x800A5E44: jal         0x8006E468
    // 0x800A5E48: nop

    func_8006E468(rdram, ctx);
        goto after_1;
    // 0x800A5E48: nop

    after_1:
    // 0x800A5E4C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800A5E50:
    // 0x800A5E50: andi        $s2, $s7, 0xFFFF
    ctx->r18 = ctx->r23 & 0XFFFF;
    // 0x800A5E54: sw          $s2, 0xB70($v0)
    MEM_W(0XB70, ctx->r2) = ctx->r18;
    // 0x800A5E58: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A5E5C: sb          $s2, 0xB40($v0)
    MEM_B(0XB40, ctx->r2) = ctx->r18;
    // 0x800A5E60: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A5E64: sw          $zero, 0x7CE4($v0)
    MEM_W(0X7CE4, ctx->r2) = 0;
    // 0x800A5E68: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A5E6C: sh          $zero, 0xB22($v0)
    MEM_H(0XB22, ctx->r2) = 0;
    // 0x800A5E70: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A5E74: sw          $zero, 0xB2C($v0)
    MEM_W(0XB2C, ctx->r2) = 0;
    // 0x800A5E78: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A5E7C: sb          $zero, 0xB1F($v0)
    MEM_B(0XB1F, ctx->r2) = 0;
    // 0x800A5E80: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800A5E84: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x800A5E88: sw          $zero, -0x7764($v0)
    MEM_W(-0X7764, ctx->r2) = 0;
    // 0x800A5E8C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800A5E90: sb          $v0, 0x9B0($v1)
    MEM_B(0X9B0, ctx->r3) = ctx->r2;
    // 0x800A5E94: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800A5E98: lbu         $s1, 0x7C($sp)
    ctx->r17 = MEM_BU(ctx->r29, 0X7C);
    // 0x800A5E9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800A5EA0: sb          $v0, 0xB39($v1)
    MEM_B(0XB39, ctx->r3) = ctx->r2;
    // 0x800A5EA4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800A5EA8: xori        $v0, $s1, 0x1
    ctx->r2 = ctx->r17 ^ 0X1;
    // 0x800A5EAC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800A5EB0: sb          $v0, 0xBA0($v1)
    MEM_B(0XBA0, ctx->r3) = ctx->r2;
    // 0x800A5EB4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800A5EB8: bne         $s1, $v0, L_800A5ECC
    if (ctx->r17 != ctx->r2) {
        // 0x800A5EBC: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_800A5ECC;
    }
    // 0x800A5EBC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800A5EC0: xori        $v0, $s2, 0x3
    ctx->r2 = ctx->r18 ^ 0X3;
    // 0x800A5EC4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800A5EC8: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
L_800A5ECC:
    // 0x800A5ECC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800A5ED0: andi        $s0, $s7, 0xFF
    ctx->r16 = ctx->r23 & 0XFF;
    // 0x800A5ED4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800A5ED8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x800A5EDC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A5EE0: sb          $a3, 0xB38($v0)
    MEM_B(0XB38, ctx->r2) = ctx->r7;
    // 0x800A5EE4: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A5EE8: sb          $zero, 0xB1C($v0)
    MEM_B(0XB1C, ctx->r2) = 0;
    // 0x800A5EEC: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A5EF0: sh          $zero, 0xB24($v0)
    MEM_H(0XB24, ctx->r2) = 0;
    // 0x800A5EF4: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A5EF8: sb          $zero, 0xB14($v0)
    MEM_B(0XB14, ctx->r2) = 0;
    // 0x800A5EFC: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A5F00: sb          $zero, 0xB1D($v0)
    MEM_B(0XB1D, ctx->r2) = 0;
    // 0x800A5F04: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A5F08: jal         0x800A9ABC
    // 0x800A5F0C: sw          $zero, 0xBA4($v0)
    MEM_W(0XBA4, ctx->r2) = 0;
    func_800A9ABC(rdram, ctx);
        goto after_2;
    // 0x800A5F0C: sw          $zero, 0xBA4($v0)
    MEM_W(0XBA4, ctx->r2) = 0;
    after_2:
    // 0x800A5F10: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800A5F14: jal         0x800A6CE4
    // 0x800A5F18: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_800A6CE4(rdram, ctx);
        goto after_3;
    // 0x800A5F18: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_3:
    // 0x800A5F1C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800A5F20: jal         0x800AF0EC
    // 0x800A5F24: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_800AF0EC(rdram, ctx);
        goto after_4;
    // 0x800A5F24: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_4:
    // 0x800A5F28: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800A5F2C: jal         0x800A6620
    // 0x800A5F30: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    load_cutscene(rdram, ctx);
        goto after_5;
    // 0x800A5F30: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_5:
    // 0x800A5F34: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x800A5F38: jal         0x800AEB7C
    // 0x800A5F3C: sw          $v0, 0x1904($s0)
    MEM_W(0X1904, ctx->r16) = ctx->r2;
    func_800AEB7C(rdram, ctx);
        goto after_6;
    // 0x800A5F3C: sw          $v0, 0x1904($s0)
    MEM_W(0X1904, ctx->r16) = ctx->r2;
    after_6:
    // 0x800A5F40: jal         0x800AEFC8
    // 0x800A5F44: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    func_800AEFC8(rdram, ctx);
        goto after_7;
    // 0x800A5F44: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    after_7:
    // 0x800A5F48: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A5F4C: lwc1        $f24, 0x5158($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X5158);
    // 0x800A5F50: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800A5F54: lw          $v1, 0x1904($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1904);
    // 0x800A5F58: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A5F5C: sw          $zero, 0xB28($v0)
    MEM_W(0XB28, ctx->r2) = 0;
    // 0x800A5F60: sll         $v0, $s2, 24
    ctx->r2 = S32(ctx->r18 << 24);
L_800A5F64:
    // 0x800A5F64: sra         $v0, $v0, 19
    ctx->r2 = S32(SIGNED(ctx->r2) >> 19);
    // 0x800A5F68: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800A5F6C: lw          $v0, 0x1318($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1318);
    // 0x800A5F70: bnel        $v0, $zero, L_800A5F98
    if (ctx->r2 != 0) {
        // 0x800A5F74: sw          $zero, 0x18($sp)
        MEM_W(0X18, ctx->r29) = 0;
            goto L_800A5F98;
    }
    goto skip_0;
    // 0x800A5F74: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    skip_0:
    // 0x800A5F78: addiu       $v0, $s2, 0x1
    ctx->r2 = ADD32(ctx->r18, 0X1);
    // 0x800A5F7C: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x800A5F80: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x800A5F84: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x800A5F88: slti        $v0, $v0, 0x6
    ctx->r2 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x800A5F8C: bnel        $v0, $zero, L_800A5F64
    if (ctx->r2 != 0) {
        // 0x800A5F90: sll         $v0, $s2, 24
        ctx->r2 = S32(ctx->r18 << 24);
            goto L_800A5F64;
    }
    goto skip_1;
    // 0x800A5F90: sll         $v0, $s2, 24
    ctx->r2 = S32(ctx->r18 << 24);
    skip_1:
    // 0x800A5F94: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_800A5F98:
    // 0x800A5F98: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x800A5F9C: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A5FA0: addiu       $v0, $v0, 0x9C0
    ctx->r2 = ADD32(ctx->r2, 0X9C0);
    // 0x800A5FA4: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_800A5FA8:
    // 0x800A5FA8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800A5FAC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800A5FB0: bgez        $v1, L_800A5FA8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800A5FB4: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_800A5FA8;
    }
    // 0x800A5FB4: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x800A5FB8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800A5FBC: andi        $a2, $s2, 0xFF
    ctx->r6 = ctx->r18 & 0XFF;
    // 0x800A5FC0: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x800A5FC4: addiu       $a1, $v1, 0x1938
    ctx->r5 = ADD32(ctx->r3, 0X1938);
    // 0x800A5FC8: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x800A5FCC: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A5FD0: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // 0x800A5FD4: lui         $s3, 0x800B
    ctx->r19 = S32(0X800B << 16);
    // 0x800A5FD8: andi        $s5, $s7, 0xFFFF
    ctx->r21 = ctx->r23 & 0XFFFF;
    // 0x800A5FDC: addiu       $t0, $s5, 0x16
    ctx->r8 = ADD32(ctx->r21, 0X16);
    // 0x800A5FE0: lbu         $t1, 0x7C($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X7C);
    // 0x800A5FE4: lw          $a1, 0x1904($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X1904);
    // 0x800A5FE8: addiu       $s1, $sp, 0x78
    ctx->r17 = ADD32(ctx->r29, 0X78);
    // 0x800A5FEC: sw          $t0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r8;
    // 0x800A5FF0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800A5FF4: jal         0x800A73E4
    // 0x800A5FF8: sw          $t1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r9;
    func_800A73E4(rdram, ctx);
        goto after_8;
    // 0x800A5FF8: sw          $t1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r9;
    after_8:
    // 0x800A5FFC: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800A6000: addiu       $a1, $a1, 0x1938
    ctx->r5 = ADD32(ctx->r5, 0X1938);
    // 0x800A6004: lw          $a0, 0x1904($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X1904);
    // 0x800A6008: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x800A600C: jal         0x800A9D70
    // 0x800A6010: sw          $v0, 0x1A08($v1)
    MEM_W(0X1A08, ctx->r3) = ctx->r2;
    func_800A9D70(rdram, ctx);
        goto after_9;
    // 0x800A6010: sw          $v0, 0x1A08($v1)
    MEM_W(0X1A08, ctx->r3) = ctx->r2;
    after_9:
    // 0x800A6014: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A6018: addiu       $fp, $v0, 0xB40
    ctx->r30 = ADD32(ctx->r2, 0XB40);
    // 0x800A601C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800A6020: addiu       $s6, $v0, -0x6AA0
    ctx->r22 = ADD32(ctx->r2, -0X6AA0);
L_800A6024:
    // 0x800A6024: jal         0x800AF360
    // 0x800A6028: nop

    func_800AF360(rdram, ctx);
        goto after_10;
    // 0x800A6028: nop

    after_10:
    // 0x800A602C: jal         0x80002FF4
    // 0x800A6030: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_80002FF4(rdram, ctx);
        goto after_11;
    // 0x800A6030: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_11:
    // 0x800A6034: jal         0x80079CE0
    // 0x800A6038: nop

    setNewAndPreviousButtonsPressed(rdram, ctx);
        goto after_12;
    // 0x800A6038: nop

    after_12:
    // 0x800A603C: lui         $t1, 0x800B
    ctx->r9 = S32(0X800B << 16);
    // 0x800A6040: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x800A6044: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A6048: lwc1        $f2, 0xB2C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XB2C);
    // 0x800A604C: lw          $a0, 0xAFC($t1)
    ctx->r4 = MEM_W(ctx->r9, 0XAFC);
    // 0x800A6050: add.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f20.fl;
    // 0x800A6054: lwc1        $f0, 0xBA4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XBA4);
    // 0x800A6058: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800A605C: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x800A6060: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800A6064: swc1        $f2, 0xB2C($v1)
    MEM_W(0XB2C, ctx->r3) = ctx->f2.u32l;
    // 0x800A6068: jal         0x800AF550
    // 0x800A606C: swc1        $f0, 0xBA4($v0)
    MEM_W(0XBA4, ctx->r2) = ctx->f0.u32l;
    func_800AF550(rdram, ctx);
        goto after_13;
    // 0x800A606C: swc1        $f0, 0xBA4($v0)
    MEM_W(0XBA4, ctx->r2) = ctx->f0.u32l;
    after_13:
    // 0x800A6070: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800A6074: bne         $v0, $zero, L_800A64BC
    if (ctx->r2 != 0) {
        // 0x800A6078: nop
    
            goto L_800A64BC;
    }
    // 0x800A6078: nop

    // 0x800A607C: jal         0x800AF668
    // 0x800A6080: nop

    func_800AF668(rdram, ctx);
        goto after_14;
    // 0x800A6080: nop

    after_14:
    // 0x800A6084: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A6088: lwc1        $f2, 0x515C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X515C);
    // 0x800A608C: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800A6090: nop

    // 0x800A6094: bc1t        L_800A60A4
    if (c1cs) {
        // 0x800A6098: nop
    
            goto L_800A60A4;
    }
    // 0x800A6098: nop

    // 0x800A609C: jal         0x80066D8C
    // 0x800A60A0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80066D8C(rdram, ctx);
        goto after_15;
    // 0x800A60A0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_15:
L_800A60A4:
    // 0x800A60A4: mul.s       $f0, $f20, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x800A60A8: lw          $v0, 0x1904($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X1904);
    // 0x800A60AC: lwc1        $f4, 0x50($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X50);
    // 0x800A60B0: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800A60B4: add.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f0.fl;
    // 0x800A60B8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A60BC: lwc1        $f0, 0x5160($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5160);
    // 0x800A60C0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800A60C4: c.lt.s      $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f22.fl < ctx->f2.fl;
    // 0x800A60C8: nop

    // 0x800A60CC: bc1tl       L_800A60D4
    if (c1cs) {
        // 0x800A60D0: mov.s       $f2, $f22
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.fl = ctx->f22.fl;
            goto L_800A60D4;
    }
    goto skip_2;
    // 0x800A60D0: mov.s       $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.fl = ctx->f22.fl;
    skip_2:
L_800A60D4:
    // 0x800A60D4: lwc1        $f0, 0x54($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X54);
    // 0x800A60D8: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
    // 0x800A60DC: mul.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800A60E0: nop

    // 0x800A60E4: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800A60E8: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x800A60EC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800A60F0: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800A60F4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800A60F8: beq         $t1, $t0, L_800A6130
    if (ctx->r9 == ctx->r8) {
        // 0x800A60FC: sw          $v1, 0xB28($s3)
        MEM_W(0XB28, ctx->r19) = ctx->r3;
            goto L_800A6130;
    }
    // 0x800A60FC: sw          $v1, 0xB28($s3)
    MEM_W(0XB28, ctx->r19) = ctx->r3;
    // 0x800A6100: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x800A6104: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x800A6108: bne         $v0, $zero, L_800A6158
    if (ctx->r2 != 0) {
        // 0x800A610C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800A6158;
    }
    // 0x800A610C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A6110: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x800A6114: bne         $t1, $zero, L_800A6124
    if (ctx->r9 != 0) {
        // 0x800A6118: addiu       $v0, $s5, 0x6
        ctx->r2 = ADD32(ctx->r21, 0X6);
            goto L_800A6124;
    }
    // 0x800A6118: addiu       $v0, $s5, 0x6
    ctx->r2 = ADD32(ctx->r21, 0X6);
    // 0x800A611C: j           L_800A614C
    // 0x800A6120: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
        goto L_800A614C;
    // 0x800A6120: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
L_800A6124:
    // 0x800A6124: lbu         $a0, 0x93($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X93);
    // 0x800A6128: j           L_800A614C
    // 0x800A612C: nop

        goto L_800A614C;
    // 0x800A612C: nop

L_800A6130:
    // 0x800A6130: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // 0x800A6134: bne         $s5, $v0, L_800A6158
    if (ctx->r21 != ctx->r2) {
        // 0x800A6138: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800A6158;
    }
    // 0x800A6138: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800A613C: slti        $v0, $v1, 0x5F
    ctx->r2 = SIGNED(ctx->r3) < 0X5F ? 1 : 0;
    // 0x800A6140: bne         $v0, $zero, L_800A615C
    if (ctx->r2 != 0) {
        // 0x800A6144: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_800A615C;
    }
    // 0x800A6144: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800A6148: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800A614C:
    // 0x800A614C: jal         0x8006ED90
    // 0x800A6150: nop

    func_8006ED90(rdram, ctx);
        goto after_16;
    // 0x800A6150: nop

    after_16:
    // 0x800A6154: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_800A6158:
    // 0x800A6158: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
L_800A615C:
    // 0x800A615C: lbu         $v0, 0xB38($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0XB38);
    // 0x800A6160: beq         $v0, $zero, L_800A61D4
    if (ctx->r2 == 0) {
        // 0x800A6164: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_800A61D4;
    }
    // 0x800A6164: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A6168: lbu         $v1, 0xB1E($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB1E);
    // 0x800A616C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800A6170: beq         $v1, $t1, L_800A61B0
    if (ctx->r3 == ctx->r9) {
        // 0x800A6174: nop
    
            goto L_800A61B0;
    }
    // 0x800A6174: nop

    // 0x800A6178: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800A617C: beq         $v0, $zero, L_800A6194
    if (ctx->r2 == 0) {
        // 0x800A6180: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_800A6194;
    }
    // 0x800A6180: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800A6184: beq         $v1, $zero, L_800A61A4
    if (ctx->r3 == 0) {
        // 0x800A6188: nop
    
            goto L_800A61A4;
    }
    // 0x800A6188: nop

    // 0x800A618C: j           L_800A61D4
    // 0x800A6190: nop

        goto L_800A61D4;
    // 0x800A6190: nop

L_800A6194:
    // 0x800A6194: beq         $v1, $t0, L_800A61BC
    if (ctx->r3 == ctx->r8) {
        // 0x800A6198: nop
    
            goto L_800A61BC;
    }
    // 0x800A6198: nop

    // 0x800A619C: j           L_800A61D4
    // 0x800A61A0: nop

        goto L_800A61D4;
    // 0x800A61A0: nop

L_800A61A4:
    // 0x800A61A4: lw          $v0, 0xB28($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XB28);
    // 0x800A61A8: j           L_800A61C4
    // 0x800A61AC: slti        $v0, $v0, 0x222
    ctx->r2 = SIGNED(ctx->r2) < 0X222 ? 1 : 0;
        goto L_800A61C4;
    // 0x800A61AC: slti        $v0, $v0, 0x222
    ctx->r2 = SIGNED(ctx->r2) < 0X222 ? 1 : 0;
L_800A61B0:
    // 0x800A61B0: lw          $v0, 0xB28($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XB28);
    // 0x800A61B4: j           L_800A61C4
    // 0x800A61B8: slti        $v0, $v0, 0x222
    ctx->r2 = SIGNED(ctx->r2) < 0X222 ? 1 : 0;
        goto L_800A61C4;
    // 0x800A61B8: slti        $v0, $v0, 0x222
    ctx->r2 = SIGNED(ctx->r2) < 0X222 ? 1 : 0;
L_800A61BC:
    // 0x800A61BC: lw          $v0, 0xB28($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XB28);
    // 0x800A61C0: slti        $v0, $v0, 0x47F
    ctx->r2 = SIGNED(ctx->r2) < 0X47F ? 1 : 0;
L_800A61C4:
    // 0x800A61C4: bne         $v0, $zero, L_800A61D4
    if (ctx->r2 != 0) {
        // 0x800A61C8: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_800A61D4;
    }
    // 0x800A61C8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800A61CC: lui         $t1, 0x800B
    ctx->r9 = S32(0X800B << 16);
    // 0x800A61D0: sb          $t0, 0xB1C($t1)
    MEM_B(0XB1C, ctx->r9) = ctx->r8;
L_800A61D4:
    // 0x800A61D4: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x800A61D8: andi        $v0, $v1, 0x400
    ctx->r2 = ctx->r3 & 0X400;
    // 0x800A61DC: bnel        $v0, $zero, L_800A61E4
    if (ctx->r2 != 0) {
        // 0x800A61E0: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800A61E4;
    }
    goto skip_3;
    // 0x800A61E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_3:
L_800A61E4:
    // 0x800A61E4: andi        $v0, $v1, 0x20
    ctx->r2 = ctx->r3 & 0X20;
    // 0x800A61E8: bnel        $v0, $zero, L_800A61F0
    if (ctx->r2 != 0) {
        // 0x800A61EC: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800A61F0;
    }
    goto skip_4;
    // 0x800A61EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_4:
L_800A61F0:
    // 0x800A61F0: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x800A61F4: beq         $v0, $zero, L_800A6214
    if (ctx->r2 == 0) {
        // 0x800A61F8: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800A6214;
    }
    // 0x800A61F8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800A61FC: lbu         $a0, 0x7D($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X7D);
    // 0x800A6200: jal         0x80079F50
    // 0x800A6204: nop

    getControllerNewButtonsPressed(rdram, ctx);
        goto after_17;
    // 0x800A6204: nop

    after_17:
    // 0x800A6208: andi        $v0, $v0, 0x9000
    ctx->r2 = ctx->r2 & 0X9000;
    // 0x800A620C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x800A6210: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_800A6214:
    // 0x800A6214: lw          $a1, 0x10($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X10);
    // 0x800A6218: andi        $v0, $a1, 0x420
    ctx->r2 = ctx->r5 & 0X420;
    // 0x800A621C: beq         $v0, $zero, L_800A6234
    if (ctx->r2 == 0) {
        // 0x800A6220: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_800A6234;
    }
    // 0x800A6220: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x800A6224: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x800A6228: beq         $v0, $zero, L_800A6234
    if (ctx->r2 == 0) {
        // 0x800A622C: ori         $v0, $a1, 0x800
        ctx->r2 = ctx->r5 | 0X800;
            goto L_800A6234;
    }
    // 0x800A622C: ori         $v0, $a1, 0x800
    ctx->r2 = ctx->r5 | 0X800;
    // 0x800A6230: sw          $v0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r2;
L_800A6234:
    // 0x800A6234: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x800A6238: bne         $v0, $zero, L_800A6250
    if (ctx->r2 != 0) {
        // 0x800A623C: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800A6250;
    }
    // 0x800A623C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800A6240: lui         $t1, 0x800B
    ctx->r9 = S32(0X800B << 16);
    // 0x800A6244: lbu         $v0, 0xB1C($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0XB1C);
    // 0x800A6248: beq         $v0, $zero, L_800A6254
    if (ctx->r2 == 0) {
        // 0x800A624C: nop
    
            goto L_800A6254;
    }
    // 0x800A624C: nop

L_800A6250:
    // 0x800A6250: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800A6254:
    // 0x800A6254: lw          $v0, 0x1904($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X1904);
    // 0x800A6258: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x800A625C: lw          $v0, 0x44($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X44);
    // 0x800A6260: lw          $v1, 0xB28($s3)
    ctx->r3 = MEM_W(ctx->r19, 0XB28);
    // 0x800A6264: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
    // 0x800A6268: sltu        $v1, $v1, $v0
    ctx->r3 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x800A626C: beq         $v1, $zero, L_800A627C
    if (ctx->r3 == 0) {
        // 0x800A6270: andi        $v0, $a0, 0xFF
        ctx->r2 = ctx->r4 & 0XFF;
            goto L_800A627C;
    }
    // 0x800A6270: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x800A6274: beq         $v0, $zero, L_800A62EC
    if (ctx->r2 == 0) {
        // 0x800A6278: nop
    
            goto L_800A62EC;
    }
    // 0x800A6278: nop

L_800A627C:
    // 0x800A627C: jal         0x800AF540
    // 0x800A6280: nop

    func_800AF540(rdram, ctx);
        goto after_18;
    // 0x800A6280: nop

    after_18:
    // 0x800A6284: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800A6288: bne         $v0, $zero, L_800A62EC
    if (ctx->r2 != 0) {
        // 0x800A628C: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_800A62EC;
    }
    // 0x800A628C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800A6290: lbu         $v0, 0xB38($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0XB38);
    // 0x800A6294: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A6298: lwc1        $f0, 0x5164($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5164);
    // 0x800A629C: beq         $v0, $zero, L_800A62AC
    if (ctx->r2 == 0) {
        // 0x800A62A0: lui         $t1, 0x800B
        ctx->r9 = S32(0X800B << 16);
            goto L_800A62AC;
    }
    // 0x800A62A0: lui         $t1, 0x800B
    ctx->r9 = S32(0X800B << 16);
    // 0x800A62A4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A62A8: lwc1        $f0, 0x5168($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5168);
L_800A62AC:
    // 0x800A62AC: lw          $a0, 0xAFC($t1)
    ctx->r4 = MEM_W(ctx->r9, 0XAFC);
    // 0x800A62B0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800A62B4: jal         0x800AF408
    // 0x800A62B8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_800AF408(rdram, ctx);
        goto after_19;
    // 0x800A62B8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_19:
    // 0x800A62BC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800A62C0: lbu         $v0, 0xB38($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0XB38);
    // 0x800A62C4: beq         $v0, $zero, L_800A62D0
    if (ctx->r2 == 0) {
        // 0x800A62C8: addiu       $a1, $zero, 0x12C
        ctx->r5 = ADD32(0, 0X12C);
            goto L_800A62D0;
    }
    // 0x800A62C8: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    // 0x800A62CC: addiu       $a1, $zero, 0x546
    ctx->r5 = ADD32(0, 0X546);
L_800A62D0:
    // 0x800A62D0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800A62D4: jal         0x8008E0B0
    // 0x800A62D8: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    func_8008E0B0(rdram, ctx);
        goto after_20;
    // 0x800A62D8: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    after_20:
    // 0x800A62DC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800A62E0: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    // 0x800A62E4: jal         0x8008E0B0
    // 0x800A62E8: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    func_8008E0B0(rdram, ctx);
        goto after_21;
    // 0x800A62E8: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    after_21:
L_800A62EC:
    // 0x800A62EC: jal         0x8000A86C
    // 0x800A62F0: nop

    func_8000A86C(rdram, ctx);
        goto after_22;
    // 0x800A62F0: nop

    after_22:
    // 0x800A62F4: lw          $a0, 0x1904($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X1904);
    // 0x800A62F8: lw          $a1, 0xB28($s3)
    ctx->r5 = MEM_W(ctx->r19, 0XB28);
    // 0x800A62FC: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x800A6300: andi        $a2, $s2, 0xFF
    ctx->r6 = ctx->r18 & 0XFF;
    // 0x800A6304: jal         0x800A89B0
    // 0x800A6308: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800A89B0(rdram, ctx);
        goto after_23;
    // 0x800A6308: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_23:
    // 0x800A630C: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x800A6310: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800A6314: andi        $a2, $s2, 0xFF
    ctx->r6 = ctx->r18 & 0XFF;
    // 0x800A6318: lw          $a1, 0x1904($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X1904);
    // 0x800A631C: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x800A6320: addiu       $a3, $a3, 0x1938
    ctx->r7 = ADD32(ctx->r7, 0X1938);
    // 0x800A6324: jal         0x800A73E4
    // 0x800A6328: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    func_800A73E4(rdram, ctx);
        goto after_24;
    // 0x800A6328: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_24:
    // 0x800A632C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800A6330: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800A6334: addiu       $a1, $a1, 0x1938
    ctx->r5 = ADD32(ctx->r5, 0X1938);
    // 0x800A6338: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x800A633C: jal         0x800A6FC0
    // 0x800A6340: sw          $v0, 0x1A08($v1)
    MEM_W(0X1A08, ctx->r3) = ctx->r2;
    func_800A6FC0(rdram, ctx);
        goto after_25;
    // 0x800A6340: sw          $v0, 0x1A08($v1)
    MEM_W(0X1A08, ctx->r3) = ctx->r2;
    after_25:
    // 0x800A6344: lw          $a1, 0x1904($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X1904);
    // 0x800A6348: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800A634C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800A6350: jal         0x800A8420
    // 0x800A6354: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_800A8420(rdram, ctx);
        goto after_26;
    // 0x800A6354: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_26:
    // 0x800A6358: jal         0x800AA658
    // 0x800A635C: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_800AA658(rdram, ctx);
        goto after_27;
    // 0x800A635C: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_27:
    // 0x800A6360: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800A6364: jal         0x800ABD0C
    // 0x800A6368: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_800ABD0C(rdram, ctx);
        goto after_28;
    // 0x800A6368: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_28:
    // 0x800A636C: lw          $a0, 0x1904($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X1904);
    // 0x800A6370: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800A6374: jal         0x800AEE14
    // 0x800A6378: nop

    func_800AEE14(rdram, ctx);
        goto after_29;
    // 0x800A6378: nop

    after_29:
    // 0x800A637C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800A6380: lhu         $a0, 0xC($s6)
    ctx->r4 = MEM_HU(ctx->r22, 0XC);
    // 0x800A6384: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x800A6388: jal         0x8003E8DC
    // 0x800A638C: swc1        $f20, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f20.u32l;
    func_8003E8DC(rdram, ctx);
        goto after_30;
    // 0x800A638C: swc1        $f20, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f20.u32l;
    after_30:
    // 0x800A6390: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800A6394: lhu         $a0, 0x10($s6)
    ctx->r4 = MEM_HU(ctx->r22, 0X10);
    // 0x800A6398: jal         0x8003E8DC
    // 0x800A639C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8003E8DC(rdram, ctx);
        goto after_31;
    // 0x800A639C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_31:
    // 0x800A63A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800A63A4: lhu         $a0, 0x14($s6)
    ctx->r4 = MEM_HU(ctx->r22, 0X14);
    // 0x800A63A8: jal         0x8003E8DC
    // 0x800A63AC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8003E8DC(rdram, ctx);
        goto after_32;
    // 0x800A63AC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_32:
    // 0x800A63B0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800A63B4: lhu         $a0, 0x6($s6)
    ctx->r4 = MEM_HU(ctx->r22, 0X6);
    // 0x800A63B8: jal         0x8003E8DC
    // 0x800A63BC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8003E8DC(rdram, ctx);
        goto after_33;
    // 0x800A63BC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_33:
    // 0x800A63C0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800A63C4: lhu         $a0, 0x8($s6)
    ctx->r4 = MEM_HU(ctx->r22, 0X8);
    // 0x800A63C8: jal         0x8003E8DC
    // 0x800A63CC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8003E8DC(rdram, ctx);
        goto after_34;
    // 0x800A63CC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_34:
    // 0x800A63D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800A63D4: lhu         $a0, 0xE($s6)
    ctx->r4 = MEM_HU(ctx->r22, 0XE);
    // 0x800A63D8: jal         0x8003E8DC
    // 0x800A63DC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8003E8DC(rdram, ctx);
        goto after_35;
    // 0x800A63DC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_35:
    // 0x800A63E0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800A63E4: lhu         $a0, 0x36($s6)
    ctx->r4 = MEM_HU(ctx->r22, 0X36);
    // 0x800A63E8: jal         0x8003E8DC
    // 0x800A63EC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8003E8DC(rdram, ctx);
        goto after_36;
    // 0x800A63EC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_36:
    // 0x800A63F0: jal         0x80045B60
    // 0x800A63F4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80045B60(rdram, ctx);
        goto after_37;
    // 0x800A63F4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_37:
    // 0x800A63F8: jal         0x80054650
    // 0x800A63FC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80054650(rdram, ctx);
        goto after_38;
    // 0x800A63FC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_38:
    // 0x800A6400: jal         0x80046484
    // 0x800A6404: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80046484(rdram, ctx);
        goto after_39;
    // 0x800A6404: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_39:
    // 0x800A6408: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x800A640C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800A6410: bne         $t1, $t0, L_800A6454
    if (ctx->r9 != ctx->r8) {
        // 0x800A6414: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_800A6454;
    }
    // 0x800A6414: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A6418: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800A641C: beq         $s5, $v0, L_800A6440
    if (ctx->r21 == ctx->r2) {
        // 0x800A6420: addiu       $v0, $zero, 0x13
        ctx->r2 = ADD32(0, 0X13);
            goto L_800A6440;
    }
    // 0x800A6420: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // 0x800A6424: bne         $s5, $v0, L_800A6454
    if (ctx->r21 != ctx->r2) {
        // 0x800A6428: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_800A6454;
    }
    // 0x800A6428: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A642C: lw          $a0, 0xB28($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XB28);
    // 0x800A6430: jal         0x800AD224
    // 0x800A6434: nop

    func_800AD224(rdram, ctx);
        goto after_40;
    // 0x800A6434: nop

    after_40:
    // 0x800A6438: j           L_800A6450
    // 0x800A643C: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
        goto L_800A6450;
    // 0x800A643C: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
L_800A6440:
    // 0x800A6440: lw          $a0, 0xB28($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XB28);
    // 0x800A6444: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800A6448: jal         0x800AD690
    // 0x800A644C: nop

    func_800AD690(rdram, ctx);
        goto after_41;
    // 0x800A644C: nop

    after_41:
L_800A6450:
    // 0x800A6450: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
L_800A6454:
    // 0x800A6454: lw          $a0, 0x1A08($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X1A08);
    // 0x800A6458: jal         0x80047368
    // 0x800A645C: andi        $s0, $s7, 0xFF
    ctx->r16 = ctx->r23 & 0XFF;
    func_80047368(rdram, ctx);
        goto after_42;
    // 0x800A645C: andi        $s0, $s7, 0xFF
    ctx->r16 = ctx->r23 & 0XFF;
    after_42:
    // 0x800A6460: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800A6464: jal         0x800A70E4
    // 0x800A6468: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800A70E4(rdram, ctx);
        goto after_43;
    // 0x800A6468: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_43:
    // 0x800A646C: jal         0x80067300
    // 0x800A6470: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80067300(rdram, ctx);
        goto after_44;
    // 0x800A6470: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_44:
    // 0x800A6474: jal         0x80055CB0
    // 0x800A6478: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80055CB0(rdram, ctx);
        goto after_45;
    // 0x800A6478: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_45:
    // 0x800A647C: lui         $t1, 0x800B
    ctx->r9 = S32(0X800B << 16);
    // 0x800A6480: lw          $a0, 0x1904($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X1904);
    // 0x800A6484: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800A6488: jal         0x800AA1BC
    // 0x800A648C: addiu       $a1, $t1, 0x1938
    ctx->r5 = ADD32(ctx->r9, 0X1938);
    func_800AA1BC(rdram, ctx);
        goto after_46;
    // 0x800A648C: addiu       $a1, $t1, 0x1938
    ctx->r5 = ADD32(ctx->r9, 0X1938);
    after_46:
    // 0x800A6490: jal         0x8000A6CC
    // 0x800A6494: nop

    func_8000A6CC(rdram, ctx);
        goto after_47;
    // 0x800A6494: nop

    after_47:
    // 0x800A6498: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800A649C: jal         0x800A71B8
    // 0x800A64A0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800A71B8(rdram, ctx);
        goto after_48;
    // 0x800A64A0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_48:
    // 0x800A64A4: jal         0x8000B6F4
    // 0x800A64A8: nop

    func_8000B6F4(rdram, ctx);
        goto after_49;
    // 0x800A64A8: nop

    after_49:
    // 0x800A64AC: jal         0x8000C07C
    // 0x800A64B0: nop

    func_8000C07C(rdram, ctx);
        goto after_50;
    // 0x800A64B0: nop

    after_50:
    // 0x800A64B4: j           L_800A6024
    // 0x800A64B8: nop

        goto L_800A6024;
    // 0x800A64B8: nop

L_800A64BC:
    // 0x800A64BC: jal         0x8000BF60
    // 0x800A64C0: nop

    func_8000BF60(rdram, ctx);
        goto after_51;
    // 0x800A64C0: nop

    after_51:
    // 0x800A64C4: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A64C8: lw          $a0, 0xAFC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XAFC);
    // 0x800A64CC: jal         0x800AF60C
    // 0x800A64D0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_800AF60C(rdram, ctx);
        goto after_52;
    // 0x800A64D0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_52:
    // 0x800A64D4: jal         0x800668B0
    // 0x800A64D8: nop

    func_800668B0(rdram, ctx);
        goto after_53;
    // 0x800A64D8: nop

    after_53:
    // 0x800A64DC: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A64E0: lw          $a0, 0x1904($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X1904);
    // 0x800A64E4: jal         0x800AEB30
    // 0x800A64E8: nop

    func_800AEB30(rdram, ctx);
        goto after_54;
    // 0x800A64E8: nop

    after_54:
    // 0x800A64EC: jal         0x800AF260
    // 0x800A64F0: nop

    func_800AF260(rdram, ctx);
        goto after_55;
    // 0x800A64F0: nop

    after_55:
    // 0x800A64F4: jal         0x800AEB38
    // 0x800A64F8: nop

    func_800AEB38(rdram, ctx);
        goto after_56;
    // 0x800A64F8: nop

    after_56:
    // 0x800A64FC: lbu         $v1, 0x7C($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X7C);
    // 0x800A6500: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800A6504: beq         $v1, $v0, L_800A651C
    if (ctx->r3 == ctx->r2) {
        // 0x800A6508: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800A651C;
    }
    // 0x800A6508: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A650C: lw          $v0, 0xB50($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB50);
    // 0x800A6510: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x800A6514: beq         $v0, $zero, L_800A6568
    if (ctx->r2 == 0) {
        // 0x800A6518: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800A6568;
    }
    // 0x800A6518: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800A651C:
    // 0x800A651C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A6520: lbu         $t0, 0x88($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X88);
    // 0x800A6524: addiu       $s0, $v0, 0xB40
    ctx->r16 = ADD32(ctx->r2, 0XB40);
    // 0x800A6528: sb          $t0, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r8;
    // 0x800A652C: lbu         $t1, 0x89($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X89);
    // 0x800A6530: sb          $t1, 0x21($s0)
    MEM_B(0X21, ctx->r16) = ctx->r9;
    // 0x800A6534: lbu         $t0, 0x8A($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X8A);
    // 0x800A6538: jal         0x8006E468
    // 0x800A653C: sb          $t0, 0x22($s0)
    MEM_B(0X22, ctx->r16) = ctx->r8;
    func_8006E468(rdram, ctx);
        goto after_57;
    // 0x800A653C: sb          $t0, 0x22($s0)
    MEM_B(0X22, ctx->r16) = ctx->r8;
    after_57:
    // 0x800A6540: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x800A6544: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // 0x800A6548: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x800A654C: sw          $v1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r3;
    // 0x800A6550: lbu         $v0, 0x87($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X87);
    // 0x800A6554: beq         $v0, $zero, L_800A6560
    if (ctx->r2 == 0) {
        // 0x800A6558: ori         $v0, $v1, 0x1
        ctx->r2 = ctx->r3 | 0X1;
            goto L_800A6560;
    }
    // 0x800A6558: ori         $v0, $v1, 0x1
    ctx->r2 = ctx->r3 | 0X1;
    // 0x800A655C: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
L_800A6560:
    // 0x800A6560: lbu         $v1, 0x7C($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X7C);
    // 0x800A6564: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800A6568:
    // 0x800A6568: sb          $zero, 0xB39($v0)
    MEM_B(0XB39, ctx->r2) = 0;
    // 0x800A656C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A6570: sb          $zero, 0xBA0($v0)
    MEM_B(0XBA0, ctx->r2) = 0;
    // 0x800A6574: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A6578: sb          $zero, 0xB38($v0)
    MEM_B(0XB38, ctx->r2) = 0;
    // 0x800A657C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800A6580: bne         $v1, $v0, L_800A65A4
    if (ctx->r3 != ctx->r2) {
        // 0x800A6584: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800A65A4;
    }
    // 0x800A6584: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A6588: andi        $v1, $s7, 0xFFFF
    ctx->r3 = ctx->r23 & 0XFFFF;
    // 0x800A658C: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // 0x800A6590: bne         $v1, $v0, L_800A65A4
    if (ctx->r3 != ctx->r2) {
        // 0x800A6594: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800A65A4;
    }
    // 0x800A6594: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A6598: jal         0x8006E360
    // 0x800A659C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8006E360(rdram, ctx);
        goto after_58;
    // 0x800A659C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_58:
    // 0x800A65A0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800A65A4:
    // 0x800A65A4: lw          $v0, 0xB50($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB50);
    // 0x800A65A8: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x800A65AC: bne         $v0, $zero, L_800A65DC
    if (ctx->r2 != 0) {
        // 0x800A65B0: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800A65DC;
    }
    // 0x800A65B0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800A65B4: lbu         $v1, 0x7C($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X7C);
    // 0x800A65B8: beq         $v1, $v0, L_800A65DC
    if (ctx->r3 == ctx->r2) {
        // 0x800A65BC: nop
    
            goto L_800A65DC;
    }
    // 0x800A65BC: nop

    // 0x800A65C0: bne         $v1, $zero, L_800A65D0
    if (ctx->r3 != 0) {
        // 0x800A65C4: andi        $v0, $s7, 0xFFFF
        ctx->r2 = ctx->r23 & 0XFFFF;
            goto L_800A65D0;
    }
    // 0x800A65C4: andi        $v0, $s7, 0xFFFF
    ctx->r2 = ctx->r23 & 0XFFFF;
    // 0x800A65C8: j           L_800A65D4
    // 0x800A65CC: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
        goto L_800A65D4;
    // 0x800A65CC: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
L_800A65D0:
    // 0x800A65D0: addiu       $v0, $v0, 0x16
    ctx->r2 = ADD32(ctx->r2, 0X16);
L_800A65D4:
    // 0x800A65D4: jal         0x8006E360
    // 0x800A65D8: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    func_8006E360(rdram, ctx);
        goto after_59;
    // 0x800A65D8: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    after_59:
L_800A65DC:
    // 0x800A65DC: jal         0x8003DF78
    // 0x800A65E0: nop

    func_8003DF78(rdram, ctx);
        goto after_60;
    // 0x800A65E0: nop

    after_60:
L_800A65E4:
    // 0x800A65E4: lw          $ra, 0xBC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XBC);
    // 0x800A65E8: lw          $fp, 0xB8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XB8);
    // 0x800A65EC: lw          $s7, 0xB4($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XB4);
    // 0x800A65F0: lw          $s6, 0xB0($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XB0);
    // 0x800A65F4: lw          $s5, 0xAC($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XAC);
    // 0x800A65F8: lw          $s4, 0xA8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XA8);
    // 0x800A65FC: lw          $s3, 0xA4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XA4);
    // 0x800A6600: lw          $s2, 0xA0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA0);
    // 0x800A6604: lw          $s1, 0x9C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X9C);
    // 0x800A6608: lw          $s0, 0x98($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X98);
    // 0x800A660C: ldc1        $f24, 0xD0($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0XD0);
    // 0x800A6610: ldc1        $f22, 0xC8($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XC8);
    // 0x800A6614: ldc1        $f20, 0xC0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XC0);
    // 0x800A6618: jr          $ra
    // 0x800A661C: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x800A661C: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void load_cutscene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6620: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800A6624: sb          $a0, 0x30($sp)
    MEM_B(0X30, ctx->r29) = ctx->r4;
    // 0x800A6628: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800A662C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A6630: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x800A6634: addiu       $a1, $v0, 0x516C
    ctx->r5 = ADD32(ctx->r2, 0X516C);
    // 0x800A6638: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A663C: addiu       $v0, $v0, -0x950
    ctx->r2 = ADD32(ctx->r2, -0X950);
    // 0x800A6640: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800A6644: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800A6648: lbu         $s0, 0x30($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X30);
    // 0x800A664C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A6650: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800A6654: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x800A6658: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x800A665C: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x800A6660: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x800A6664: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800A6668: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800A666C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800A6670: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800A6674: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x800A6678: jal         0x80033CC4
    // 0x800A667C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800A667C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_0:
    // 0x800A6680: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800A6684: jal         0x800647E0
    // 0x800A6688: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    load_asset_with_malloc_flags(rdram, ctx);
        goto after_1;
    // 0x800A6688: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x800A668C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800A6690: addiu       $s1, $v1, 0xB40
    ctx->r17 = ADD32(ctx->r3, 0XB40);
    // 0x800A6694: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x800A6698: lbu         $a1, 0x1($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1);
    // 0x800A669C: jal         0x800ACE8C
    // 0x800A66A0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_800ACE8C(rdram, ctx);
        goto after_2;
    // 0x800A66A0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_2:
    // 0x800A66A4: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A66A8: sh          $zero, 0xB20($v0)
    MEM_H(0XB20, ctx->r2) = 0;
    // 0x800A66AC: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // 0x800A66B0: bne         $s0, $v0, L_800A6710
    if (ctx->r16 != ctx->r2) {
        // 0x800A66B4: nop
    
            goto L_800A6710;
    }
    // 0x800A66B4: nop

    // 0x800A66B8: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x800A66BC: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800A66C0: beq         $v0, $zero, L_800A6710
    if (ctx->r2 == 0) {
        // 0x800A66C4: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_800A6710;
    }
    // 0x800A66C4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A66C8: addiu       $t3, $v0, 0x517C
    ctx->r11 = ADD32(ctx->r2, 0X517C);
    // 0x800A66CC: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800A66D0: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x800A66D4: lw          $t2, 0x8($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X8);
    // 0x800A66D8: sw          $t0, 0x1D58($s3)
    MEM_W(0X1D58, ctx->r19) = ctx->r8;
    // 0x800A66DC: sw          $t1, 0x1D5C($s3)
    MEM_W(0X1D5C, ctx->r19) = ctx->r9;
    // 0x800A66E0: sw          $t2, 0x1D60($s3)
    MEM_W(0X1D60, ctx->r19) = ctx->r10;
    // 0x800A66E4: lw          $t0, 0xC($t3)
    ctx->r8 = MEM_W(ctx->r11, 0XC);
    // 0x800A66E8: sw          $t0, 0x1D64($s3)
    MEM_W(0X1D64, ctx->r19) = ctx->r8;
    // 0x800A66EC: addiu       $t3, $v0, 0x517C
    ctx->r11 = ADD32(ctx->r2, 0X517C);
    // 0x800A66F0: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800A66F4: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x800A66F8: lw          $t2, 0x8($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X8);
    // 0x800A66FC: sw          $t0, 0x1E3C($s3)
    MEM_W(0X1E3C, ctx->r19) = ctx->r8;
    // 0x800A6700: sw          $t1, 0x1E40($s3)
    MEM_W(0X1E40, ctx->r19) = ctx->r9;
    // 0x800A6704: sw          $t2, 0x1E44($s3)
    MEM_W(0X1E44, ctx->r19) = ctx->r10;
    // 0x800A6708: lw          $t0, 0xC($t3)
    ctx->r8 = MEM_W(ctx->r11, 0XC);
    // 0x800A670C: sw          $t0, 0x1E48($s3)
    MEM_W(0X1E48, ctx->r19) = ctx->r8;
L_800A6710:
    // 0x800A6710: lhu         $v0, 0x4A($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X4A);
    // 0x800A6714: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x800A6718: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x800A671C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800A6720: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x800A6724: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x800A6728: jal         0x80001ACC
    // 0x800A672C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    rs_malloc(rdram, ctx);
        goto after_3;
    // 0x800A672C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_3:
    // 0x800A6730: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800A6734: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800A6738: lhu         $v0, 0x4A($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X4A);
    // 0x800A673C: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x800A6740: sw          $a0, 0x1900($s0)
    MEM_W(0X1900, ctx->r16) = ctx->r4;
    // 0x800A6744: sll         $a2, $v0, 2
    ctx->r6 = S32(ctx->r2 << 2);
    // 0x800A6748: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x800A674C: sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6 << 4);
    // 0x800A6750: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // 0x800A6754: jal         0x800078E0
    // 0x800A6758: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    rs_memset(rdram, ctx);
        goto after_4;
    // 0x800A6758: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    after_4:
    // 0x800A675C: lhu         $v0, 0x4A($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X4A);
    // 0x800A6760: beq         $v0, $zero, L_800A684C
    if (ctx->r2 == 0) {
        // 0x800A6764: addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
            goto L_800A684C;
    }
    // 0x800A6764: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x800A6768: addu        $s7, $s0, $zero
    ctx->r23 = ADD32(ctx->r16, 0);
    // 0x800A676C: addiu       $fp, $zero, 0x5F
    ctx->r30 = ADD32(0, 0X5F);
    // 0x800A6770: addu        $s2, $s4, $zero
    ctx->r18 = ADD32(ctx->r20, 0);
    // 0x800A6774: addu        $s5, $s4, $zero
    ctx->r21 = ADD32(ctx->r20, 0);
    // 0x800A6778: addiu       $s6, $zero, 0x13D8
    ctx->r22 = ADD32(0, 0X13D8);
L_800A677C:
    // 0x800A677C: lw          $v0, 0x1900($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X1900);
    // 0x800A6780: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A6784: lwc1        $f0, 0x519C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X519C);
    // 0x800A6788: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x800A678C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x800A6790: lw          $v1, 0x1900($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X1900);
    // 0x800A6794: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800A6798: addu        $v1, $s2, $v1
    ctx->r3 = ADD32(ctx->r18, ctx->r3);
    // 0x800A679C: addiu       $a0, $v1, 0x88
    ctx->r4 = ADD32(ctx->r3, 0X88);
    // 0x800A67A0: swc1        $f0, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->f0.u32l;
    // 0x800A67A4: jal         0x8001CA50
    // 0x800A67A8: sh          $v0, 0xB8($v1)
    MEM_H(0XB8, ctx->r3) = ctx->r2;
    func_8001CA50(rdram, ctx);
        goto after_5;
    // 0x800A67A8: sh          $v0, 0xB8($v1)
    MEM_H(0XB8, ctx->r3) = ctx->r2;
    after_5:
    // 0x800A67AC: addu        $s0, $s3, $s6
    ctx->r16 = ADD32(ctx->r19, ctx->r22);
    // 0x800A67B0: jal         0x8003471C
    // 0x800A67B4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    strlen_recomp(rdram, ctx);
        goto after_6;
    // 0x800A67B4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // 0x800A67B8: addiu       $s1, $v0, -0x1
    ctx->r17 = ADD32(ctx->r2, -0X1);
    // 0x800A67BC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800A67C0: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A67C4: lw          $v0, 0x1900($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X1900);
    // 0x800A67C8: addiu       $a1, $a1, 0x518C
    ctx->r5 = ADD32(ctx->r5, 0X518C);
    // 0x800A67CC: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x800A67D0: jal         0x800076F8
    // 0x800A67D4: sb          $s1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r17;
    rs_strcmp(rdram, ctx);
        goto after_7;
    // 0x800A67D4: sb          $s1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r17;
    after_7:
    // 0x800A67D8: beq         $v0, $zero, L_800A6830
    if (ctx->r2 == 0) {
        // 0x800A67DC: addu        $v0, $s1, $s5
        ctx->r2 = ADD32(ctx->r17, ctx->r21);
            goto L_800A6830;
    }
    // 0x800A67DC: addu        $v0, $s1, $s5
    ctx->r2 = ADD32(ctx->r17, ctx->r21);
    // 0x800A67E0: addu        $v0, $s3, $v0
    ctx->r2 = ADD32(ctx->r19, ctx->r2);
    // 0x800A67E4: lbu         $v0, 0x13D8($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X13D8);
    // 0x800A67E8: addiu       $v0, $v0, -0x30
    ctx->r2 = ADD32(ctx->r2, -0X30);
    // 0x800A67EC: sltiu       $v0, $v0, 0xA
    ctx->r2 = ctx->r2 < 0XA ? 1 : 0;
    // 0x800A67F0: beql        $v0, $zero, L_800A6834
    if (ctx->r2 == 0) {
        // 0x800A67F4: addiu       $s2, $s2, 0x13C
        ctx->r18 = ADD32(ctx->r18, 0X13C);
            goto L_800A6834;
    }
    goto skip_0;
    // 0x800A67F4: addiu       $s2, $s2, 0x13C
    ctx->r18 = ADD32(ctx->r18, 0X13C);
    skip_0:
    // 0x800A67F8: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800A67FC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_800A6800:
    // 0x800A6800: addu        $v0, $s1, $a0
    ctx->r2 = ADD32(ctx->r17, ctx->r4);
    // 0x800A6804: addu        $v0, $s3, $v0
    ctx->r2 = ADD32(ctx->r19, ctx->r2);
    // 0x800A6808: lbu         $v1, 0x13D8($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X13D8);
    // 0x800A680C: addiu       $v0, $v1, -0x30
    ctx->r2 = ADD32(ctx->r3, -0X30);
    // 0x800A6810: sltiu       $v0, $v0, 0xA
    ctx->r2 = ctx->r2 < 0XA ? 1 : 0;
    // 0x800A6814: bnel        $v0, $zero, L_800A6800
    if (ctx->r2 != 0) {
        // 0x800A6818: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_800A6800;
    }
    goto skip_1;
    // 0x800A6818: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_1:
    // 0x800A681C: beql        $v1, $fp, L_800A6800
    if (ctx->r3 == ctx->r30) {
        // 0x800A6820: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_800A6800;
    }
    goto skip_2;
    // 0x800A6820: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_2:
    // 0x800A6824: lw          $v0, 0x1900($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X1900);
    // 0x800A6828: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x800A682C: sb          $s1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r17;
L_800A6830:
    // 0x800A6830: addiu       $s2, $s2, 0x13C
    ctx->r18 = ADD32(ctx->r18, 0X13C);
L_800A6834:
    // 0x800A6834: addiu       $s5, $s5, 0x4C
    ctx->r21 = ADD32(ctx->r21, 0X4C);
    // 0x800A6838: lhu         $v0, 0x4A($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X4A);
    // 0x800A683C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800A6840: sltu        $v0, $s4, $v0
    ctx->r2 = ctx->r20 < ctx->r2 ? 1 : 0;
    // 0x800A6844: bne         $v0, $zero, L_800A677C
    if (ctx->r2 != 0) {
        // 0x800A6848: addiu       $s6, $s6, 0x4C
        ctx->r22 = ADD32(ctx->r22, 0X4C);
            goto L_800A677C;
    }
    // 0x800A6848: addiu       $s6, $s6, 0x4C
    ctx->r22 = ADD32(ctx->r22, 0X4C);
L_800A684C:
    // 0x800A684C: jal         0x800AEA28
    // 0x800A6850: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    cuts_0058_bubble_sort(rdram, ctx);
        goto after_8;
    // 0x800A6850: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_8:
    // 0x800A6854: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800A6858: lbu         $s0, 0x30($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X30);
    // 0x800A685C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800A6860: jal         0x800A7C4C
    // 0x800A6864: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800A7C4C(rdram, ctx);
        goto after_9;
    // 0x800A6864: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_9:
    // 0x800A6868: jal         0x80079A70
    // 0x800A686C: nop

    func_80079A70(rdram, ctx);
        goto after_10;
    // 0x800A686C: nop

    after_10:
    // 0x800A6870: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800A6874: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800A6878: jal         0x800A7C4C
    // 0x800A687C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800A7C4C(rdram, ctx);
        goto after_11;
    // 0x800A687C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x800A6880: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x800A6884: beq         $s0, $v0, L_800A6894
    if (ctx->r16 == ctx->r2) {
        // 0x800A6888: nop
    
            goto L_800A6894;
    }
    // 0x800A6888: nop

    // 0x800A688C: jal         0x80048104
    // 0x800A6890: addiu       $a0, $zero, 0x5DC0
    ctx->r4 = ADD32(0, 0X5DC0);
    func_80048104(rdram, ctx);
        goto after_12;
    // 0x800A6890: addiu       $a0, $zero, 0x5DC0
    ctx->r4 = ADD32(0, 0X5DC0);
    after_12:
L_800A6894:
    // 0x800A6894: jal         0x800A959C
    // 0x800A6898: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_800A959C(rdram, ctx);
        goto after_13;
    // 0x800A6898: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_13:
    // 0x800A689C: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x800A68A0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800A68A4: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A68A8: addiu       $a0, $v0, 0x1A20
    ctx->r4 = ADD32(ctx->r2, 0X1A20);
    // 0x800A68AC: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A68B0: addiu       $v1, $v0, 0x1A10
    ctx->r3 = ADD32(ctx->r2, 0X1A10);
L_800A68B4:
    // 0x800A68B4: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A68B8: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x800A68BC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800A68C0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800A68C4: sltiu       $v0, $s4, 0x4
    ctx->r2 = ctx->r20 < 0X4 ? 1 : 0;
    // 0x800A68C8: bne         $v0, $zero, L_800A68B4
    if (ctx->r2 != 0) {
        // 0x800A68CC: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800A68B4;
    }
    // 0x800A68CC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800A68D0: addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
    // 0x800A68D4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800A68D8: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x800A68DC: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x800A68E0: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800A68E4: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800A68E8: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800A68EC: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800A68F0: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800A68F4: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800A68F8: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800A68FC: jr          $ra
    // 0x800A6900: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800A6900: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_800A6904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6904: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A6908: mtc1        $a2, $f10
    ctx->f10.u32l = ctx->r6;
    // 0x800A690C: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x800A6910: lw          $a3, 0x1904($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X1904);
    // 0x800A6914: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800A6918: sdc1        $f24, 0x58($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X58, ctx->r29);
    // 0x800A691C: sdc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X50, ctx->r29);
    // 0x800A6920: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x800A6924: lw          $v1, 0x44($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X44);
    // 0x800A6928: lbu         $t0, 0x73($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X73);
    // 0x800A692C: mtc1        $v1, $f2
    ctx->f2.u32l = ctx->r3;
    // 0x800A6930: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x800A6934: bgezl       $v1, L_800A694C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800A6938: cvt.s.d     $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
            goto L_800A694C;
    }
    goto skip_0;
    // 0x800A6938: cvt.s.d     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
    skip_0:
    // 0x800A693C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A6940: ldc1        $f0, 0x51A0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X51A0);
    // 0x800A6944: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
    // 0x800A6948: cvt.s.d     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
L_800A694C:
    // 0x800A694C: div.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800A6950: mul.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800A6954: mtc1        $v1, $f2
    ctx->f2.u32l = ctx->r3;
    // 0x800A6958: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x800A695C: trunc.w.s   $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800A6960: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800A6964: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // 0x800A6968: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800A696C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A6970: bgezl       $v1, L_800A6988
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800A6974: cvt.s.d     $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
            goto L_800A6988;
    }
    goto skip_1;
    // 0x800A6974: cvt.s.d     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
    skip_1:
    // 0x800A6978: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A697C: ldc1        $f0, 0x51A8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X51A8);
    // 0x800A6980: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
    // 0x800A6984: cvt.s.d     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
L_800A6988:
    // 0x800A6988: div.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800A698C: div.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800A6990: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x800A6994: lw          $v0, 0x44($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X44);
    // 0x800A6998: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x800A699C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A69A0: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800A69A4: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x800A69A8: bgezl       $v0, L_800A69C0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A69AC: cvt.s.d     $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
            goto L_800A69C0;
    }
    goto skip_2;
    // 0x800A69AC: cvt.s.d     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
    skip_2:
    // 0x800A69B0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A69B4: ldc1        $f0, 0x51B0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X51B0);
    // 0x800A69B8: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
    // 0x800A69BC: cvt.s.d     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
L_800A69C0:
    // 0x800A69C0: div.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800A69C4: div.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800A69C8: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // 0x800A69CC: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800A69D0: lw          $v1, 0x44($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X44);
    // 0x800A69D4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800A69D8: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A69DC: mtc1        $v1, $f2
    ctx->f2.u32l = ctx->r3;
    // 0x800A69E0: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x800A69E4: bgezl       $v1, L_800A69FC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800A69E8: cvt.s.d     $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
            goto L_800A69FC;
    }
    goto skip_3;
    // 0x800A69E8: cvt.s.d     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
    skip_3:
    // 0x800A69EC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A69F0: ldc1        $f0, 0x51B8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X51B8);
    // 0x800A69F4: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
    // 0x800A69F8: cvt.s.d     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
L_800A69FC:
    // 0x800A69FC: div.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800A6A00: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800A6A04: addiu       $v0, $a2, 0x2
    ctx->r2 = ADD32(ctx->r6, 0X2);
    // 0x800A6A08: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x800A6A0C: lw          $v1, 0x44($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X44);
    // 0x800A6A10: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800A6A14: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A6A18: mtc1        $v1, $f2
    ctx->f2.u32l = ctx->r3;
    // 0x800A6A1C: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x800A6A20: bgezl       $v1, L_800A6A38
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800A6A24: cvt.s.d     $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
            goto L_800A6A38;
    }
    goto skip_4;
    // 0x800A6A24: cvt.s.d     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
    skip_4:
    // 0x800A6A28: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A6A2C: ldc1        $f0, 0x51C0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X51C0);
    // 0x800A6A30: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
    // 0x800A6A34: cvt.s.d     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
L_800A6A38:
    // 0x800A6A38: div.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800A6A3C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800A6A40: div.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800A6A44: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800A6A48: nop

    // 0x800A6A4C: bc1t        L_800A6A90
    if (c1cs) {
        // 0x800A6A50: swc1        $f0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
            goto L_800A6A90;
    }
    // 0x800A6A50: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800A6A54: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A6A58: lwc1        $f2, 0x51C8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X51C8);
    // 0x800A6A5C: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800A6A60: nop

    // 0x800A6A64: bc1t        L_800A6A90
    if (c1cs) {
        // 0x800A6A68: nop
    
            goto L_800A6A90;
    }
    // 0x800A6A68: nop

    // 0x800A6A6C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800A6A70: nop

    // 0x800A6A74: bc1t        L_800A6A90
    if (c1cs) {
        // 0x800A6A78: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_800A6A90;
    }
    // 0x800A6A78: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A6A7C: lhu         $v0, 0xB22($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0XB22);
    // 0x800A6A80: beq         $v0, $zero, L_800A6B10
    if (ctx->r2 == 0) {
        // 0x800A6A84: andi        $v0, $t0, 0xFF
        ctx->r2 = ctx->r8 & 0XFF;
            goto L_800A6B10;
    }
    // 0x800A6A84: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // 0x800A6A88: bne         $v0, $zero, L_800A6B14
    if (ctx->r2 != 0) {
        // 0x800A6A8C: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_800A6B14;
    }
    // 0x800A6A8C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_800A6A90:
    // 0x800A6A90: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800A6A94: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x800A6A98: nop

    // 0x800A6A9C: bc1f        L_800A6AD0
    if (!c1cs) {
        // 0x800A6AA0: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_800A6AD0;
    }
    // 0x800A6AA0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800A6AA4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800A6AA8:
    // 0x800A6AA8: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x800A6AAC: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x800A6AB0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A6AB4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800A6AB8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A6ABC: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800A6AC0: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x800A6AC4: nop

    // 0x800A6AC8: bc1tl       L_800A6AA8
    if (c1cs) {
        // 0x800A6ACC: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800A6AA8;
    }
    goto skip_5;
    // 0x800A6ACC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_5:
L_800A6AD0:
    // 0x800A6AD0: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x800A6AD4: bnel        $v0, $zero, L_800A6ADC
    if (ctx->r2 != 0) {
        // 0x800A6AD8: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_800A6ADC;
    }
    goto skip_6;
    // 0x800A6AD8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    skip_6:
L_800A6ADC:
    // 0x800A6ADC: andi        $v1, $a2, 0xFFFF
    ctx->r3 = ctx->r6 & 0XFFFF;
    // 0x800A6AE0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800A6AE4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A6AE8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A6AEC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800A6AF0: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800A6AF4: sub.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800A6AF8: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800A6AFC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800A6B00: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800A6B04: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800A6B08: j           L_800A6CD0
    // 0x800A6B0C: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
        goto L_800A6CD0;
    // 0x800A6B0C: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_800A6B10:
    // 0x800A6B10: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_800A6B14:
    // 0x800A6B14: addiu       $t1, $sp, 0x38
    ctx->r9 = ADD32(ctx->r29, 0X38);
    // 0x800A6B18: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
L_800A6B1C:
    // 0x800A6B1C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A6B20: addu        $t0, $v0, $sp
    ctx->r8 = ADD32(ctx->r2, ctx->r29);
    // 0x800A6B24: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800A6B28: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x800A6B2C: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800A6B30: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800A6B34: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800A6B38: nop

    // 0x800A6B3C: bc1f        L_800A6B70
    if (!c1cs) {
        // 0x800A6B40: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_800A6B70;
    }
    // 0x800A6B40: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800A6B44: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800A6B48:
    // 0x800A6B48: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x800A6B4C: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x800A6B50: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A6B54: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800A6B58: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A6B5C: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800A6B60: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800A6B64: nop

    // 0x800A6B68: bc1tl       L_800A6B48
    if (c1cs) {
        // 0x800A6B6C: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800A6B48;
    }
    goto skip_7;
    // 0x800A6B6C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_7:
L_800A6B70:
    // 0x800A6B70: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x800A6B74: bnel        $v0, $zero, L_800A6B7C
    if (ctx->r2 != 0) {
        // 0x800A6B78: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_800A6B7C;
    }
    goto skip_8;
    // 0x800A6B78: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    skip_8:
L_800A6B7C:
    // 0x800A6B7C: andi        $v1, $a2, 0xFFFF
    ctx->r3 = ctx->r6 & 0XFFFF;
    // 0x800A6B80: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800A6B84: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A6B88: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A6B8C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800A6B90: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800A6B94: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800A6B98: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800A6B9C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800A6BA0: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800A6BA4: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x800A6BA8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800A6BAC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800A6BB0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800A6BB4: addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // 0x800A6BB8: swc1        $f0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f0.u32l;
    // 0x800A6BBC: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x800A6BC0: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x800A6BC4: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x800A6BC8: bnel        $v0, $zero, L_800A6B1C
    if (ctx->r2 != 0) {
        // 0x800A6BCC: andi        $v0, $a3, 0xFFFF
        ctx->r2 = ctx->r7 & 0XFFFF;
            goto L_800A6B1C;
    }
    goto skip_9;
    // 0x800A6BCC: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    skip_9:
    // 0x800A6BD0: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800A6BD4: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800A6BD8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800A6BDC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A6BE0: lwc1        $f4, 0x51CC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X51CC);
    // 0x800A6BE4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800A6BE8: nop

    // 0x800A6BEC: bc1tl       L_800A6BF4
    if (c1cs) {
        // 0x800A6BF0: mov.s       $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = ctx->f4.fl;
            goto L_800A6BF4;
    }
    goto skip_10;
    // 0x800A6BF0: mov.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = ctx->f4.fl;
    skip_10:
L_800A6BF4:
    // 0x800A6BF4: sub.s       $f10, $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x800A6BF8: div.s       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800A6BFC: mul.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800A6C00: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A6C04: lwc1        $f6, 0x51D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X51D0);
    // 0x800A6C08: mul.s       $f2, $f10, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800A6C0C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A6C10: lwc1        $f4, 0x51D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X51D4);
    // 0x800A6C14: mul.s       $f22, $f10, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800A6C18: nop

    // 0x800A6C1C: mul.s       $f20, $f16, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800A6C20: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A6C24: lwc1        $f0, 0x51D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X51D8);
    // 0x800A6C28: mul.s       $f0, $f16, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800A6C2C: nop

    // 0x800A6C30: mul.s       $f18, $f20, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800A6C34: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A6C38: lwc1        $f12, 0x51DC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X51DC);
    // 0x800A6C3C: mul.s       $f12, $f20, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f12.fl);
    // 0x800A6C40: nop

    // 0x800A6C44: mul.s       $f4, $f20, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x800A6C48: nop

    // 0x800A6C4C: mul.s       $f6, $f16, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800A6C50: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A6C54: lwc1        $f8, 0x51E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X51E0);
    // 0x800A6C58: mul.s       $f8, $f20, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x800A6C5C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A6C60: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800A6C64: mul.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A6C68: add.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800A6C6C: add.s       $f18, $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x800A6C70: lwc1        $f2, 0x8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800A6C74: mul.s       $f2, $f18, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800A6C78: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x800A6C7C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A6C80: lwc1        $f0, 0x51E4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X51E4);
    // 0x800A6C84: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x800A6C88: lwc1        $f14, 0xC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800A6C8C: mul.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800A6C90: add.s       $f0, $f16, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f16.fl;
    // 0x800A6C94: add.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800A6C98: add.s       $f8, $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x800A6C9C: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800A6CA0: mul.s       $f0, $f8, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800A6CA4: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x800A6CA8: add.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x800A6CAC: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x800A6CB0: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x800A6CB4: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800A6CB8: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x800A6CBC: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x800A6CC0: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x800A6CC4: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    // 0x800A6CC8: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x800A6CCC: swc1        $f2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f2.u32l;
L_800A6CD0:
    // 0x800A6CD0: ldc1        $f24, 0x58($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X58);
    // 0x800A6CD4: ldc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X50);
    // 0x800A6CD8: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x800A6CDC: jr          $ra
    // 0x800A6CE0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800A6CE0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_800A6CE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6CE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A6CE8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800A6CEC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800A6CF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A6CF4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800A6CF8: jal         0x80056350
    // 0x800A6CFC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    func_80056350(rdram, ctx);
        goto after_0;
    // 0x800A6CFC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_0:
    // 0x800A6D00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A6D04: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A6D08: lwc1        $f0, 0x5234($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5234);
    // 0x800A6D0C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A6D10: swc1        $f0, 0x6FBC($v0)
    MEM_W(0X6FBC, ctx->r2) = ctx->f0.u32l;
    // 0x800A6D14: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A6D18: lwc1        $f0, 0x5238($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5238);
    // 0x800A6D1C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A6D20: jal         0x80017B48
    // 0x800A6D24: swc1        $f0, 0x6FAC($v0)
    MEM_W(0X6FAC, ctx->r2) = ctx->f0.u32l;
    func_80017B48(rdram, ctx);
        goto after_1;
    // 0x800A6D24: swc1        $f0, 0x6FAC($v0)
    MEM_W(0X6FAC, ctx->r2) = ctx->f0.u32l;
    after_1:
    // 0x800A6D28: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x800A6D2C: addiu       $v1, $v1, 0x90C
    ctx->r3 = ADD32(ctx->r3, 0X90C);
    // 0x800A6D30: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x800A6D34: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A6D38: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x800A6D3C: jal         0x800453C8
    // 0x800A6D40: nop

    func_800453C8(rdram, ctx);
        goto after_2;
    // 0x800A6D40: nop

    after_2:
    // 0x800A6D44: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A6D48: lwc1        $f12, 0x523C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X523C);
    // 0x800A6D4C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A6D50: lwc1        $f14, 0x5240($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X5240);
    // 0x800A6D54: jal         0x800457B8
    // 0x800A6D58: nop

    func_800457B8(rdram, ctx);
        goto after_3;
    // 0x800A6D58: nop

    after_3:
    // 0x800A6D5C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A6D60: lwc1        $f12, 0x5244($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5244);
    // 0x800A6D64: jal         0x800457AC
    // 0x800A6D68: nop

    func_800457AC(rdram, ctx);
        goto after_4;
    // 0x800A6D68: nop

    after_4:
    // 0x800A6D6C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800A6D70: addiu       $a0, $a0, 0x4724
    ctx->r4 = ADD32(ctx->r4, 0X4724);
    // 0x800A6D74: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800A6D78: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800A6D7C: jal         0x8003FFEC
    // 0x800A6D80: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    func_8003FFEC(rdram, ctx);
        goto after_5;
    // 0x800A6D80: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    after_5:
    // 0x800A6D84: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800A6D88: sh          $v0, 0xBA2($v1)
    MEM_H(0XBA2, ctx->r3) = ctx->r2;
    // 0x800A6D8C: addiu       $v1, $s0, -0x2
    ctx->r3 = ADD32(ctx->r16, -0X2);
    // 0x800A6D90: sltiu       $v0, $v1, 0x12
    ctx->r2 = ctx->r3 < 0X12 ? 1 : 0;
    // 0x800A6D94: beq         $v0, $zero, L_800A6F78
    if (ctx->r2 == 0) {
        // 0x800A6D98: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_800A6F78;
    }
    // 0x800A6D98: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A6D9C: addiu       $v0, $v0, 0x5248
    ctx->r2 = ADD32(ctx->r2, 0X5248);
    // 0x800A6DA0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800A6DA4: addu        $v1, $v1, $v0
    gpr jr_addend_800A6DAC = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A6DA8: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800A6DAC: jr          $v0
    // 0x800A6DB0: nop

    switch (jr_addend_800A6DAC >> 2) {
        case 0: goto L_800A6DB4; break;
        case 1: goto L_800A6DC8; break;
        case 2: goto L_800A6F78; break;
        case 3: goto L_800A6F78; break;
        case 4: goto L_800A6E34; break;
        case 5: goto L_800A6F78; break;
        case 6: goto L_800A6F78; break;
        case 7: goto L_800A6F78; break;
        case 8: goto L_800A6F78; break;
        case 9: goto L_800A6F78; break;
        case 10: goto L_800A6F78; break;
        case 11: goto L_800A6F78; break;
        case 12: goto L_800A6F78; break;
        case 13: goto L_800A6E60; break;
        case 14: goto L_800A6F78; break;
        case 15: goto L_800A6F78; break;
        case 16: goto L_800A6F78; break;
        case 17: goto L_800A6E80; break;
        default: switch_error(__func__, 0x800A6DAC, 0x800A5248);
    }
    // 0x800A6DB0: nop

L_800A6DB4:
    // 0x800A6DB4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A6DB8: lwc1        $f0, 0x5290($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5290);
    // 0x800A6DBC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A6DC0: j           L_800A6F78
    // 0x800A6DC4: swc1        $f0, 0x6FBC($v0)
    MEM_W(0X6FBC, ctx->r2) = ctx->f0.u32l;
        goto L_800A6F78;
    // 0x800A6DC4: swc1        $f0, 0x6FBC($v0)
    MEM_W(0X6FBC, ctx->r2) = ctx->f0.u32l;
L_800A6DC8:
    // 0x800A6DC8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A6DCC: lbu         $v0, 0xB38($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB38);
    // 0x800A6DD0: beq         $v0, $zero, L_800A6F78
    if (ctx->r2 == 0) {
        // 0x800A6DD4: lui         $a0, 0x800A
        ctx->r4 = S32(0X800A << 16);
            goto L_800A6F78;
    }
    // 0x800A6DD4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A6DD8: addiu       $a0, $a0, 0x51E8
    ctx->r4 = ADD32(ctx->r4, 0X51E8);
    // 0x800A6DDC: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x800A6DE0: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800A6DE4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800A6DE8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A6DEC: sb          $zero, 0x6E18($v0)
    MEM_B(0X6E18, ctx->r2) = 0;
    // 0x800A6DF0: addiu       $v0, $v0, 0x6E18
    ctx->r2 = ADD32(ctx->r2, 0X6E18);
    // 0x800A6DF4: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x800A6DF8: jal         0x800ADF74
    // 0x800A6DFC: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    func_800ADF74(rdram, ctx);
        goto after_6;
    // 0x800A6DFC: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    after_6:
    // 0x800A6E00: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800A6E04: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A6E08: jal         0x800AF65C
    // 0x800A6E0C: sw          $a0, 0xB10($v0)
    MEM_W(0XB10, ctx->r2) = ctx->r4;
    func_800AF65C(rdram, ctx);
        goto after_7;
    // 0x800A6E0C: sw          $a0, 0xB10($v0)
    MEM_W(0XB10, ctx->r2) = ctx->r4;
    after_7:
    // 0x800A6E10: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800A6E14: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A6E18: lw          $a0, 0xB00($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XB00);
    // 0x800A6E1C: jal         0x800642A0
    // 0x800A6E20: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_800642A0(rdram, ctx);
        goto after_8;
    // 0x800A6E20: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_8:
    // 0x800A6E24: jal         0x800AC574
    // 0x800A6E28: nop

    func_800AC574(rdram, ctx);
        goto after_9;
    // 0x800A6E28: nop

    after_9:
    // 0x800A6E2C: j           L_800A6F78
    // 0x800A6E30: nop

        goto L_800A6F78;
    // 0x800A6E30: nop

L_800A6E34:
    // 0x800A6E34: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A6E38: addiu       $a0, $a0, 0x51F0
    ctx->r4 = ADD32(ctx->r4, 0X51F0);
    // 0x800A6E3C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800A6E40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A6E44: jal         0x8005645C
    // 0x800A6E48: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    load_hmt_and_hob(rdram, ctx);
        goto after_10;
    // 0x800A6E48: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_10:
    // 0x800A6E4C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A6E50: addiu       $a0, $a0, 0x5200
    ctx->r4 = ADD32(ctx->r4, 0X5200);
    // 0x800A6E54: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800A6E58: j           L_800A6E70
    // 0x800A6E5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_800A6E70;
    // 0x800A6E5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800A6E60:
    // 0x800A6E60: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A6E64: addiu       $a0, $a0, 0x5210
    ctx->r4 = ADD32(ctx->r4, 0X5210);
    // 0x800A6E68: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800A6E6C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
L_800A6E70:
    // 0x800A6E70: jal         0x8005645C
    // 0x800A6E74: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    load_hmt_and_hob(rdram, ctx);
        goto after_11;
    // 0x800A6E74: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_11:
    // 0x800A6E78: j           L_800A6F78
    // 0x800A6E7C: nop

        goto L_800A6F78;
    // 0x800A6E7C: nop

L_800A6E80:
    // 0x800A6E80: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A6E84: lwc1        $f12, 0x5294($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5294);
    // 0x800A6E88: jal         0x800457AC
    // 0x800A6E8C: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    func_800457AC(rdram, ctx);
        goto after_12;
    // 0x800A6E8C: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    after_12:
    // 0x800A6E90: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A6E94: addiu       $a0, $a0, 0x5224
    ctx->r4 = ADD32(ctx->r4, 0X5224);
    // 0x800A6E98: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x800A6E9C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800A6EA0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800A6EA4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A6EA8: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x800A6EAC: sb          $v1, 0x6E18($v0)
    MEM_B(0X6E18, ctx->r2) = ctx->r3;
    // 0x800A6EB0: addiu       $v0, $v0, 0x6E18
    ctx->r2 = ADD32(ctx->r2, 0X6E18);
    // 0x800A6EB4: sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
    // 0x800A6EB8: jal         0x800ADF74
    // 0x800A6EBC: sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    func_800ADF74(rdram, ctx);
        goto after_13;
    // 0x800A6EBC: sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    after_13:
    // 0x800A6EC0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A6EC4: addiu       $a0, $a0, 0x5228
    ctx->r4 = ADD32(ctx->r4, 0X5228);
    // 0x800A6EC8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x800A6ECC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800A6ED0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800A6ED4: jal         0x800ADF74
    // 0x800A6ED8: sw          $v0, 0xB04($s0)
    MEM_W(0XB04, ctx->r16) = ctx->r2;
    func_800ADF74(rdram, ctx);
        goto after_14;
    // 0x800A6ED8: sw          $v0, 0xB04($s0)
    MEM_W(0XB04, ctx->r16) = ctx->r2;
    after_14:
    // 0x800A6EDC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A6EE0: addiu       $a0, $a0, 0x522C
    ctx->r4 = ADD32(ctx->r4, 0X522C);
    // 0x800A6EE4: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800A6EE8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800A6EEC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800A6EF0: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x800A6EF4: jal         0x800ADF74
    // 0x800A6EF8: sw          $v0, 0xB08($s1)
    MEM_W(0XB08, ctx->r17) = ctx->r2;
    func_800ADF74(rdram, ctx);
        goto after_15;
    // 0x800A6EF8: sw          $v0, 0xB08($s1)
    MEM_W(0XB08, ctx->r17) = ctx->r2;
    after_15:
    // 0x800A6EFC: lw          $a0, 0xB04($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB04);
    // 0x800A6F00: lui         $s2, 0x800B
    ctx->r18 = S32(0X800B << 16);
    // 0x800A6F04: jal         0x800AF65C
    // 0x800A6F08: sw          $v0, 0xB0C($s2)
    MEM_W(0XB0C, ctx->r18) = ctx->r2;
    func_800AF65C(rdram, ctx);
        goto after_16;
    // 0x800A6F08: sw          $v0, 0xB0C($s2)
    MEM_W(0XB0C, ctx->r18) = ctx->r2;
    after_16:
    // 0x800A6F0C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800A6F10: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x800A6F14: lw          $a0, 0xB00($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB00);
    // 0x800A6F18: jal         0x800642A0
    // 0x800A6F1C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_800642A0(rdram, ctx);
        goto after_17;
    // 0x800A6F1C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_17:
    // 0x800A6F20: lw          $a0, 0xB08($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XB08);
    // 0x800A6F24: jal         0x800AF65C
    // 0x800A6F28: nop

    func_800AF65C(rdram, ctx);
        goto after_18;
    // 0x800A6F28: nop

    after_18:
    // 0x800A6F2C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800A6F30: lw          $a0, 0xB00($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB00);
    // 0x800A6F34: jal         0x800642A0
    // 0x800A6F38: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    func_800642A0(rdram, ctx);
        goto after_19;
    // 0x800A6F38: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    after_19:
    // 0x800A6F3C: lw          $a0, 0xB0C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XB0C);
    // 0x800A6F40: jal         0x800AF65C
    // 0x800A6F44: nop

    func_800AF65C(rdram, ctx);
        goto after_20;
    // 0x800A6F44: nop

    after_20:
    // 0x800A6F48: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800A6F4C: lw          $a0, 0xB00($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB00);
    // 0x800A6F50: jal         0x800642A0
    // 0x800A6F54: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_800642A0(rdram, ctx);
        goto after_21;
    // 0x800A6F54: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_21:
    // 0x800A6F58: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A6F5C: lwc1        $f0, 0x5298($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5298);
    // 0x800A6F60: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A6F64: swc1        $f0, 0x6FBC($v0)
    MEM_W(0X6FBC, ctx->r2) = ctx->f0.u32l;
    // 0x800A6F68: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A6F6C: lwc1        $f0, 0x529C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X529C);
    // 0x800A6F70: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A6F74: swc1        $f0, 0x6FAC($v0)
    MEM_W(0X6FAC, ctx->r2) = ctx->f0.u32l;
L_800A6F78:
    // 0x800A6F78: jal         0x8005E7EC
    // 0x800A6F7C: nop

    func_8005E7EC(rdram, ctx);
        goto after_22;
    // 0x800A6F7C: nop

    after_22:
    // 0x800A6F80: jal         0x80054A18
    // 0x800A6F84: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80054A18(rdram, ctx);
        goto after_23;
    // 0x800A6F84: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_23:
    // 0x800A6F88: jal         0x8006C6D0
    // 0x800A6F8C: nop

    func_8006C6D0(rdram, ctx);
        goto after_24;
    // 0x800A6F8C: nop

    after_24:
    // 0x800A6F90: jal         0x80040310
    // 0x800A6F94: nop

    func_80040310(rdram, ctx);
        goto after_25;
    // 0x800A6F94: nop

    after_25:
    // 0x800A6F98: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A6F9C: lbu         $a1, 0xB62($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0XB62);
    // 0x800A6FA0: jal         0x80066A90
    // 0x800A6FA4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80066A90(rdram, ctx);
        goto after_26;
    // 0x800A6FA4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_26:
    // 0x800A6FA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A6FAC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800A6FB0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800A6FB4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800A6FB8: jr          $ra
    // 0x800A6FBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A6FBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800A6FC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6FC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A6FC4: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x800A6FC8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800A6FCC: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A6FD0: addiu       $a0, $v0, 0x9C0
    ctx->r4 = ADD32(ctx->r2, 0X9C0);
    // 0x800A6FD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A6FD8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800A6FDC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800A6FE0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800A6FE4: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800A6FE8: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
L_800A6FEC:
    // 0x800A6FEC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A6FF0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800A6FF4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800A6FF8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800A6FFC: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800A7000: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x800A7004: bne         $v0, $zero, L_800A6FEC
    if (ctx->r2 != 0) {
        // 0x800A7008: andi        $v0, $v1, 0xFF
        ctx->r2 = ctx->r3 & 0XFF;
            goto L_800A6FEC;
    }
    // 0x800A7008: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800A700C: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A7010: addiu       $s0, $v0, 0xA00
    ctx->r16 = ADD32(ctx->r2, 0XA00);
    // 0x800A7014: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x800A7018: sw          $a2, 0xA00($v0)
    MEM_W(0XA00, ctx->r2) = ctx->r6;
    // 0x800A701C: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A7020: addiu       $v0, $v0, 0x9C0
    ctx->r2 = ADD32(ctx->r2, 0X9C0);
    // 0x800A7024: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // 0x800A7028: sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    // 0x800A702C: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x800A7030: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x800A7034: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800A7038: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x800A703C: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A7040: sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // 0x800A7044: addiu       $v1, $v0, 0x9D0
    ctx->r3 = ADD32(ctx->r2, 0X9D0);
    // 0x800A7048: lui         $s2, 0x800B
    ctx->r18 = S32(0X800B << 16);
    // 0x800A704C: addiu       $s1, $s2, 0xA50
    ctx->r17 = ADD32(ctx->r18, 0XA50);
    // 0x800A7050: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
    // 0x800A7054: sw          $s1, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r17;
    // 0x800A7058: sw          $zero, 0x9D0($v0)
    MEM_W(0X9D0, ctx->r2) = 0;
    // 0x800A705C: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A7060: addiu       $v0, $v0, 0x9E0
    ctx->r2 = ADD32(ctx->r2, 0X9E0);
    // 0x800A7064: jal         0x80059D18
    // 0x800A7068: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    func_80059D18(rdram, ctx);
        goto after_0;
    // 0x800A7068: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    after_0:
    // 0x800A706C: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x800A7070: addiu       $v0, $v1, 0xAB0
    ctx->r2 = ADD32(ctx->r3, 0XAB0);
    // 0x800A7074: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x800A7078: lw          $a2, 0x1C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C);
    // 0x800A707C: lw          $a3, 0x20($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X20);
    // 0x800A7080: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    // 0x800A7084: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x800A7088: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x800A708C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800A7090: sw          $zero, 0xAB0($v1)
    MEM_W(0XAB0, ctx->r3) = 0;
    // 0x800A7094: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x800A7098: jal         0x8001CAC4
    // 0x800A709C: sw          $s1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r17;
    func_8001CAC4(rdram, ctx);
        goto after_1;
    // 0x800A709C: sw          $s1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r17;
    after_1:
    // 0x800A70A0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800A70A4: lui         $v0, 0x4900
    ctx->r2 = S32(0X4900 << 16);
    // 0x800A70A8: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x800A70AC: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800A70B0: sw          $zero, 0xA50($s2)
    MEM_W(0XA50, ctx->r18) = 0;
    // 0x800A70B4: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // 0x800A70B8: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x800A70BC: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x800A70C0: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800A70C4: jal         0x8000A85C
    // 0x800A70C8: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    func_8000A85C(rdram, ctx);
        goto after_2;
    // 0x800A70C8: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    after_2:
    // 0x800A70CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A70D0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800A70D4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800A70D8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800A70DC: jr          $ra
    // 0x800A70E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A70E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800A70E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A70E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A70E8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800A70EC: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800A70F0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800A70F4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800A70F8: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800A70FC: addiu       $s0, $s0, -0x6AA0
    ctx->r16 = ADD32(ctx->r16, -0X6AA0);
    // 0x800A7100: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800A7104: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x800A7108: addiu       $s1, $s1, 0xA00
    ctx->r17 = ADD32(ctx->r17, 0XA00);
    // 0x800A710C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A7110: lhu         $a0, 0x6($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X6);
    // 0x800A7114: jal         0x8003E8DC
    // 0x800A7118: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8003E8DC(rdram, ctx);
        goto after_0;
    // 0x800A7118: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_0:
    // 0x800A711C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800A7120: lhu         $a0, 0x8($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X8);
    // 0x800A7124: jal         0x8003E8DC
    // 0x800A7128: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8003E8DC(rdram, ctx);
        goto after_1;
    // 0x800A7128: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_1:
    // 0x800A712C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800A7130: lhu         $a0, 0xC($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XC);
    // 0x800A7134: jal         0x8003E8DC
    // 0x800A7138: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8003E8DC(rdram, ctx);
        goto after_2;
    // 0x800A7138: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_2:
    // 0x800A713C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800A7140: lhu         $a0, 0x10($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X10);
    // 0x800A7144: jal         0x8003E8DC
    // 0x800A7148: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8003E8DC(rdram, ctx);
        goto after_3;
    // 0x800A7148: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_3:
    // 0x800A714C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800A7150: lhu         $a0, 0x14($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X14);
    // 0x800A7154: jal         0x8003E8DC
    // 0x800A7158: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8003E8DC(rdram, ctx);
        goto after_4;
    // 0x800A7158: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_4:
    // 0x800A715C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800A7160: lhu         $a0, 0xE($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XE);
    // 0x800A7164: jal         0x8003E8DC
    // 0x800A7168: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8003E8DC(rdram, ctx);
        goto after_5;
    // 0x800A7168: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_5:
    // 0x800A716C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800A7170: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A7174: lhu         $a0, 0xBA2($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0XBA2);
    // 0x800A7178: jal         0x8003E8DC
    // 0x800A717C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8003E8DC(rdram, ctx);
        goto after_6;
    // 0x800A717C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_6:
    // 0x800A7180: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A7184: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800A7188: sw          $v1, 0xAB0($v0)
    MEM_W(0XAB0, ctx->r2) = ctx->r3;
    // 0x800A718C: beq         $v1, $zero, L_800A7198
    if (ctx->r3 == 0) {
        // 0x800A7190: addiu       $v0, $v0, 0xAB0
        ctx->r2 = ADD32(ctx->r2, 0XAB0);
            goto L_800A7198;
    }
    // 0x800A7190: addiu       $v0, $v0, 0xAB0
    ctx->r2 = ADD32(ctx->r2, 0XAB0);
    // 0x800A7194: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800A7198:
    // 0x800A7198: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800A719C: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x800A71A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A71A4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800A71A8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800A71AC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800A71B0: jr          $ra
    // 0x800A71B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A71B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800A71B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    {
        static int n = 0;
        ++n;
        if (n <= 10 || (n % 60) == 0) {
            uint8_t gate = rdram[((0x800B09B0u) ^ 3) & 0x7FFFFFFFu];
            fprintf(stderr, "[trace] func_800A71B8 #%d gate@800B09B0=0x%02X\n", n, gate);
            fflush(stderr);
        }
    }
    // 0x800A71B8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A71BC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800A71C0: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x800A71C4: lbu         $v0, 0x9B0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X9B0);
    // 0x800A71C8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800A71CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A71D0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800A71D4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800A71D8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800A71DC: beq         $v0, $zero, L_800A7230
    if (ctx->r2 == 0) {
        // 0x800A71E0: addu        $s1, $a0, $zero
        ctx->r17 = ADD32(ctx->r4, 0);
            goto L_800A7230;
    }
    // 0x800A71E0: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800A71E4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800A71E8: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800A71EC: jal         0x80017A90
    // 0x800A71F0: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    func_80017A90(rdram, ctx);
        goto after_0;
    // 0x800A71F0: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_0:
    // 0x800A71F4: jal         0x80009B48
    // 0x800A71F8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80009B48(rdram, ctx);
        goto after_1;
    // 0x800A71F8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // 0x800A71FC: jal         0x80017AB0
    // 0x800A7200: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80017AB0(rdram, ctx);
        goto after_2;
    // 0x800A7200: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x800A7204: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800A7208: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x800A720C: sw          $zero, 0x8($s1)
    MEM_W(0X8, ctx->r17) = 0;
    // 0x800A7210: jal         0x80055B8C
    // 0x800A7214: sw          $zero, 0xC($s1)
    MEM_W(0XC, ctx->r17) = 0;
    func_80055B8C(rdram, ctx);
        goto after_3;
    // 0x800A7214: sw          $zero, 0xC($s1)
    MEM_W(0XC, ctx->r17) = 0;
    after_3:
    // 0x800A7218: jal         0x80016C44
    // 0x800A721C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80016C44(rdram, ctx);
        goto after_4;
    // 0x800A721C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_4:
    // 0x800A7220: lbu         $v0, 0x9B0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X9B0);
    // 0x800A7224: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800A7228: j           L_800A73C4
    // 0x800A722C: sb          $v0, 0x9B0($s0)
    MEM_B(0X9B0, ctx->r16) = ctx->r2;
        goto L_800A73C4;
    // 0x800A722C: sb          $v0, 0x9B0($s0)
    MEM_B(0X9B0, ctx->r16) = ctx->r2;
L_800A7230:
    // 0x800A7230: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800A7234: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // 0x800A7238: beq         $a1, $v0, L_800A726C
    if (ctx->r5 == ctx->r2) {
        // 0x800A723C: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_800A726C;
    }
    // 0x800A723C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x800A7240: bne         $a1, $v0, L_800A7250
    if (ctx->r5 != ctx->r2) {
        // 0x800A7244: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_800A7250;
    }
    // 0x800A7244: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A7248: j           L_800A7270
    // 0x800A724C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
        goto L_800A7270;
    // 0x800A724C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800A7250:
    // 0x800A7250: lw          $v1, 0x9D0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X9D0);
    // 0x800A7254: bne         $v1, $zero, L_800A7264
    if (ctx->r3 != 0) {
        // 0x800A7258: addiu       $a0, $v0, 0x9D0
        ctx->r4 = ADD32(ctx->r2, 0X9D0);
            goto L_800A7264;
    }
    // 0x800A7258: addiu       $a0, $v0, 0x9D0
    ctx->r4 = ADD32(ctx->r2, 0X9D0);
    // 0x800A725C: j           L_800A7270
    // 0x800A7260: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
        goto L_800A7270;
    // 0x800A7260: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800A7264:
    // 0x800A7264: jal         0x80009B48
    // 0x800A7268: nop

    func_80009B48(rdram, ctx);
        goto after_5;
    // 0x800A7268: nop

    after_5:
L_800A726C:
    // 0x800A726C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800A7270:
    // 0x800A7270: jal         0x80017AB0
    // 0x800A7274: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    func_80017AB0(rdram, ctx);
        goto after_6;
    // 0x800A7274: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    after_6:
    // 0x800A7278: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A727C: lw          $a0, 0xB00($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XB00);
    // 0x800A7280: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x800A7284: lw          $v0, 0x9C0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X9C0);
    // 0x800A7288: addiu       $s0, $s0, 0x9C0
    ctx->r16 = ADD32(ctx->r16, 0X9C0);
    // 0x800A728C: sw          $zero, 0x8($s1)
    MEM_W(0X8, ctx->r17) = 0;
    // 0x800A7290: jal         0x80064488
    // 0x800A7294: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    func_80064488(rdram, ctx);
        goto after_7;
    // 0x800A7294: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    after_7:
    // 0x800A7298: sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // 0x800A729C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A72A0: lbu         $a0, 0x6E18($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X6E18);
    // 0x800A72A4: addiu       $v0, $v0, 0x6E18
    ctx->r2 = ADD32(ctx->r2, 0X6E18);
    // 0x800A72A8: lbu         $a1, 0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X1);
    // 0x800A72AC: lbu         $a2, 0x2($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X2);
    // 0x800A72B0: jal         0x80017A90
    // 0x800A72B4: nop

    func_80017A90(rdram, ctx);
        goto after_8;
    // 0x800A72B4: nop

    after_8:
    // 0x800A72B8: jal         0x80016C44
    // 0x800A72BC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80016C44(rdram, ctx);
        goto after_9;
    // 0x800A72BC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_9:
    // 0x800A72C0: jal         0x8000B654
    // 0x800A72C4: nop

    func_8000B654(rdram, ctx);
        goto after_10;
    // 0x800A72C4: nop

    after_10:
    // 0x800A72C8: jal         0x80017AB0
    // 0x800A72CC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80017AB0(rdram, ctx);
        goto after_11;
    // 0x800A72CC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_11:
    // 0x800A72D0: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A72D4: sw          $zero, 0xC($s1)
    MEM_W(0XC, ctx->r17) = 0;
    // 0x800A72D8: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x800A72DC: lbu         $v0, 0xB1D($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB1D);
    // 0x800A72E0: beq         $v0, $zero, L_800A72F0
    if (ctx->r2 == 0) {
        // 0x800A72E4: sw          $v1, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r3;
            goto L_800A72F0;
    }
    // 0x800A72E4: sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    // 0x800A72E8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800A72EC: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_800A72F0:
    // 0x800A72F0: jal         0x80016C44
    // 0x800A72F4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80016C44(rdram, ctx);
        goto after_12;
    // 0x800A72F4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_12:
    // 0x800A72F8: jal         0x8000B654
    // 0x800A72FC: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    func_8000B654(rdram, ctx);
        goto after_13;
    // 0x800A72FC: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    after_13:
    // 0x800A7300: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A7304: lw          $a0, 0xAFC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XAFC);
    // 0x800A7308: jal         0x80064488
    // 0x800A730C: sw          $s2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r18;
    func_80064488(rdram, ctx);
        goto after_14;
    // 0x800A730C: sw          $s2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r18;
    after_14:
    // 0x800A7310: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800A7314: jal         0x80055B8C
    // 0x800A7318: sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    func_80055B8C(rdram, ctx);
        goto after_15;
    // 0x800A7318: sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    after_15:
    // 0x800A731C: jal         0x80016C44
    // 0x800A7320: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80016C44(rdram, ctx);
        goto after_16;
    // 0x800A7320: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_16:
    // 0x800A7324: lw          $v0, 0xB18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB18);
    // 0x800A7328: beq         $v0, $zero, L_800A73C4
    if (ctx->r2 == 0) {
        // 0x800A732C: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_800A73C4;
    }
    // 0x800A732C: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A7330: lbu         $v0, 0xB14($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB14);
    // 0x800A7334: beq         $v0, $zero, L_800A73C4
    if (ctx->r2 == 0) {
        // 0x800A7338: nop
    
            goto L_800A73C4;
    }
    // 0x800A7338: nop

    // 0x800A733C: jal         0x8000B654
    // 0x800A7340: nop

    func_8000B654(rdram, ctx);
        goto after_17;
    // 0x800A7340: nop

    after_17:
    // 0x800A7344: jal         0x80016C44
    // 0x800A7348: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80016C44(rdram, ctx);
        goto after_18;
    // 0x800A7348: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_18:
    // 0x800A734C: lwc1        $f20, 0x24($s1)
    ctx->f20.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800A7350: lwc1        $f22, 0x28($s1)
    ctx->f22.u32l = MEM_W(ctx->r17, 0X28);
    // 0x800A7354: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A7358: lwc1        $f0, 0x52A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X52A0);
    // 0x800A735C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A7360: lwc1        $f2, 0x52A4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X52A4);
    // 0x800A7364: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A7368: swc1        $f0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f0.u32l;
    // 0x800A736C: jal         0x80017AB0
    // 0x800A7370: swc1        $f2, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f2.u32l;
    func_80017AB0(rdram, ctx);
        goto after_19;
    // 0x800A7370: swc1        $f2, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f2.u32l;
    after_19:
    // 0x800A7374: jal         0x80017AD0
    // 0x800A7378: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80017AD0(rdram, ctx);
        goto after_20;
    // 0x800A7378: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_20:
    // 0x800A737C: jal         0x80017AC0
    // 0x800A7380: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80017AC0(rdram, ctx);
        goto after_21;
    // 0x800A7380: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_21:
    // 0x800A7384: jal         0x80009B48
    // 0x800A7388: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80009B48(rdram, ctx);
        goto after_22;
    // 0x800A7388: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_22:
    // 0x800A738C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x800A7390: lw          $v0, 0xB18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB18);
    // 0x800A7394: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x800A7398: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800A739C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800A73A0: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800A73A4: jal         0x80016C44
    // 0x800A73A8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80016C44(rdram, ctx);
        goto after_23;
    // 0x800A73A8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_23:
    // 0x800A73AC: jal         0x80017AD0
    // 0x800A73B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80017AD0(rdram, ctx);
        goto after_24;
    // 0x800A73B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_24:
    // 0x800A73B4: jal         0x80017AB0
    // 0x800A73B8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80017AB0(rdram, ctx);
        goto after_25;
    // 0x800A73B8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_25:
    // 0x800A73BC: swc1        $f20, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f20.u32l;
    // 0x800A73C0: swc1        $f22, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f22.u32l;
L_800A73C4:
    // 0x800A73C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A73C8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800A73CC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800A73D0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800A73D4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800A73D8: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800A73DC: jr          $ra
    // 0x800A73E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800A73E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800A73E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A73E4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800A73E8: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800A73EC: addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // 0x800A73F0: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800A73F4: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800A73F8: addiu       $a1, $s6, 0x20
    ctx->r5 = ADD32(ctx->r22, 0X20);
    // 0x800A73FC: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800A7400: andi        $s0, $a2, 0xFF
    ctx->r16 = ctx->r6 & 0XFF;
    // 0x800A7404: sll         $s0, $s0, 5
    ctx->r16 = S32(ctx->r16 << 5);
    // 0x800A7408: sdc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X60, ctx->r29);
    // 0x800A740C: lwc1        $f20, 0x80($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800A7410: addu        $s0, $s1, $s0
    ctx->r16 = ADD32(ctx->r17, ctx->r16);
    // 0x800A7414: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800A7418: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800A741C: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800A7420: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800A7424: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800A7428: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800A742C: sdc1        $f22, 0x68($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X68, ctx->r29);
    // 0x800A7430: lw          $v0, 0x1334($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1334);
    // 0x800A7434: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A7438: lwc1        $f22, 0x52A8($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X52A8);
    // 0x800A743C: addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
    // 0x800A7440: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x800A7444: sllv        $a0, $v0, $s3
    ctx->r4 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800A7448: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800A744C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800A7450: addiu       $a0, $a0, 0x25AC
    ctx->r4 = ADD32(ctx->r4, 0X25AC);
    // 0x800A7454: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800A7458: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x800A745C: jal         0x800A6904
    // 0x800A7460: addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    func_800A6904(rdram, ctx);
        goto after_0;
    // 0x800A7460: addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    after_0:
    // 0x800A7464: lui         $s4, 0x800B
    ctx->r20 = S32(0X800B << 16);
    // 0x800A7468: addiu       $s2, $s4, 0x940
    ctx->r18 = ADD32(ctx->r20, 0X940);
    // 0x800A746C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800A7470: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x800A7474: lw          $v0, 0x1318($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1318);
    // 0x800A7478: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800A747C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800A7480: sllv        $a0, $v0, $s3
    ctx->r4 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800A7484: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800A7488: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800A748C: addiu       $a0, $a0, 0x25AC
    ctx->r4 = ADD32(ctx->r4, 0X25AC);
    // 0x800A7490: jal         0x800A6904
    // 0x800A7494: addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    func_800A6904(rdram, ctx);
        goto after_1;
    // 0x800A7494: addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    after_1:
    // 0x800A7498: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800A749C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x800A74A0: lw          $v0, 0x131C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X131C);
    // 0x800A74A4: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    // 0x800A74A8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800A74AC: sllv        $a0, $v0, $s3
    ctx->r4 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800A74B0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800A74B4: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800A74B8: addiu       $a0, $a0, 0x25AC
    ctx->r4 = ADD32(ctx->r4, 0X25AC);
    // 0x800A74BC: jal         0x800A6904
    // 0x800A74C0: addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    func_800A6904(rdram, ctx);
        goto after_2;
    // 0x800A74C0: addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    after_2:
    // 0x800A74C4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800A74C8: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x800A74CC: lw          $v0, 0x1320($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1320);
    // 0x800A74D0: addiu       $a1, $s2, 0x8
    ctx->r5 = ADD32(ctx->r18, 0X8);
    // 0x800A74D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800A74D8: sllv        $a0, $v0, $s3
    ctx->r4 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800A74DC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800A74E0: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800A74E4: addiu       $a0, $a0, 0x25AC
    ctx->r4 = ADD32(ctx->r4, 0X25AC);
    // 0x800A74E8: jal         0x800A6904
    // 0x800A74EC: addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    func_800A6904(rdram, ctx);
        goto after_3;
    // 0x800A74EC: addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    after_3:
    // 0x800A74F0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A74F4: lwc1        $f22, 0x52AC($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X52AC);
    // 0x800A74F8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800A74FC: lw          $v0, 0x1330($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1330);
    // 0x800A7500: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800A7504: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x800A7508: sllv        $a0, $v0, $s3
    ctx->r4 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800A750C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800A7510: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800A7514: addiu       $a0, $a0, 0x25AC
    ctx->r4 = ADD32(ctx->r4, 0X25AC);
    // 0x800A7518: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x800A751C: jal         0x800A6904
    // 0x800A7520: addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    func_800A6904(rdram, ctx);
        goto after_4;
    // 0x800A7520: addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    after_4:
    // 0x800A7524: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800A7528: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x800A752C: lw          $v0, 0x1324($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1324);
    // 0x800A7530: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800A7534: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x800A7538: sllv        $a0, $v0, $s3
    ctx->r4 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800A753C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800A7540: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800A7544: addiu       $a0, $a0, 0x25AC
    ctx->r4 = ADD32(ctx->r4, 0X25AC);
    // 0x800A7548: jal         0x800A6904
    // 0x800A754C: addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    func_800A6904(rdram, ctx);
        goto after_5;
    // 0x800A754C: addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    after_5:
    // 0x800A7550: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800A7554: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x800A7558: lw          $v0, 0x1328($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1328);
    // 0x800A755C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800A7560: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x800A7564: sllv        $a0, $v0, $s3
    ctx->r4 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800A7568: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800A756C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800A7570: addiu       $a0, $a0, 0x25AC
    ctx->r4 = ADD32(ctx->r4, 0X25AC);
    // 0x800A7574: jal         0x800A6904
    // 0x800A7578: addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    func_800A6904(rdram, ctx);
        goto after_6;
    // 0x800A7578: addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    after_6:
    // 0x800A757C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800A7580: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x800A7584: lw          $v0, 0x132C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X132C);
    // 0x800A7588: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800A758C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x800A7590: sllv        $a0, $v0, $s3
    ctx->r4 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800A7594: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800A7598: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800A759C: addiu       $a0, $a0, 0x25AC
    ctx->r4 = ADD32(ctx->r4, 0X25AC);
    // 0x800A75A0: jal         0x800A6904
    // 0x800A75A4: addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    func_800A6904(rdram, ctx);
        goto after_7;
    // 0x800A75A4: addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    after_7:
    // 0x800A75A8: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A75AC: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800A75B0: lwc1        $f8, 0x940($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X940);
    // 0x800A75B4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A75B8: lwc1        $f6, 0x52B0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X52B0);
    // 0x800A75BC: lhu         $v0, 0x9B4($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X9B4);
    // 0x800A75C0: mul.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800A75C4: lwc1        $f4, 0x4($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X4);
    // 0x800A75C8: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800A75CC: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800A75D0: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A75D4: lhu         $v0, 0x9B6($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X9B6);
    // 0x800A75D8: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A75DC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800A75E0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800A75E4: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800A75E8: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800A75EC: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800A75F0: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800A75F4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800A75F8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800A75FC: swc1        $f8, 0x940($s4)
    MEM_W(0X940, ctx->r20) = ctx->f8.u32l;
    // 0x800A7600: swc1        $f4, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f4.u32l;
    // 0x800A7604: jal         0x8001CB64
    // 0x800A7608: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
    func_8001CB64(rdram, ctx);
        goto after_8;
    // 0x800A7608: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
    after_8:
    // 0x800A760C: addiu       $s0, $sp, 0x28
    ctx->r16 = ADD32(ctx->r29, 0X28);
    // 0x800A7610: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800A7614: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800A7618: jal         0x8001D144
    // 0x800A761C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_8001D144(rdram, ctx);
        goto after_9;
    // 0x800A761C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_9:
    // 0x800A7620: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800A7624: jal         0x8001DAEC
    // 0x800A7628: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8001DAEC(rdram, ctx);
        goto after_10;
    // 0x800A7628: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_10:
    // 0x800A762C: lw          $a1, 0x940($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X940);
    // 0x800A7630: lw          $a2, 0x4($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X4);
    // 0x800A7634: lw          $a3, 0x8($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X8);
    // 0x800A7638: jal         0x8001CA90
    // 0x800A763C: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    func_8001CA90(rdram, ctx);
        goto after_11;
    // 0x800A763C: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_11:
    // 0x800A7640: addiu       $a0, $s6, 0x2C
    ctx->r4 = ADD32(ctx->r22, 0X2C);
    // 0x800A7644: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800A7648: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A764C: addiu       $v0, $v0, 0x1910
    ctx->r2 = ADD32(ctx->r2, 0X1910);
    // 0x800A7650: sw          $v0, -0x72E4($v1)
    MEM_W(-0X72E4, ctx->r3) = ctx->r2;
    // 0x800A7654: addiu       $t3, $s4, 0x940
    ctx->r11 = ADD32(ctx->r20, 0X940);
    // 0x800A7658: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800A765C: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x800A7660: lw          $t2, 0x8($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X8);
    // 0x800A7664: sw          $t0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r8;
    // 0x800A7668: sw          $t1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r9;
    // 0x800A766C: sw          $t2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r10;
    // 0x800A7670: jal         0x8001C774
    // 0x800A7674: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    func_8001C774(rdram, ctx);
        goto after_12;
    // 0x800A7674: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_12:
    // 0x800A7678: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800A767C: jal         0x800AF164
    // 0x800A7680: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800AF164(rdram, ctx);
        goto after_13;
    // 0x800A7680: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_13:
    // 0x800A7684: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x800A7688: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800A768C: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800A7690: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800A7694: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800A7698: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800A769C: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800A76A0: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800A76A4: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800A76A8: ldc1        $f22, 0x68($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X68);
    // 0x800A76AC: ldc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X60);
    // 0x800A76B0: jr          $ra
    // 0x800A76B4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800A76B4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_800A76B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A76B8: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800A76BC: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x800A76C0: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800A76C4: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x800A76C8: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x800A76CC: andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // 0x800A76D0: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800A76D4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A76D8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800A76DC: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800A76E0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800A76E4: addiu       $v1, $v1, 0x13D8
    ctx->r3 = ADD32(ctx->r3, 0X13D8);
    // 0x800A76E8: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x800A76EC: addu        $s1, $s2, $v1
    ctx->r17 = ADD32(ctx->r18, ctx->r3);
    // 0x800A76F0: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x800A76F4: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800A76F8: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x800A76FC: sdc1        $f22, 0x70($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X70, ctx->r29);
    // 0x800A7700: sdc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X68, ctx->r29);
    // 0x800A7704: lbu         $v0, 0x1F($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1F);
    // 0x800A7708: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x800A770C: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // 0x800A7710: beq         $v0, $zero, L_800A7920
    if (ctx->r2 == 0) {
        // 0x800A7714: addu        $s4, $a2, $zero
        ctx->r20 = ADD32(ctx->r6, 0);
            goto L_800A7920;
    }
    // 0x800A7714: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x800A7718: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x800A771C: addiu       $s0, $s0, 0x950
    ctx->r16 = ADD32(ctx->r16, 0X950);
    // 0x800A7720: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800A7724: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    // 0x800A7728: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A772C: lwc1        $f20, 0x52B8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X52B8);
    // 0x800A7730: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800A7734: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800A7738: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x800A773C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800A7740: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800A7744: addiu       $a0, $a0, 0x25AC
    ctx->r4 = ADD32(ctx->r4, 0X25AC);
    // 0x800A7748: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800A774C: jal         0x800A6904
    // 0x800A7750: addu        $a0, $s2, $a0
    ctx->r4 = ADD32(ctx->r18, ctx->r4);
    func_800A6904(rdram, ctx);
        goto after_0;
    // 0x800A7750: addu        $a0, $s2, $a0
    ctx->r4 = ADD32(ctx->r18, ctx->r4);
    after_0:
    // 0x800A7754: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800A7758: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800A775C: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x800A7760: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800A7764: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800A7768: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x800A776C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800A7770: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800A7774: addiu       $a0, $a0, 0x25AC
    ctx->r4 = ADD32(ctx->r4, 0X25AC);
    // 0x800A7778: jal         0x800A6904
    // 0x800A777C: addu        $a0, $s2, $a0
    ctx->r4 = ADD32(ctx->r18, ctx->r4);
    func_800A6904(rdram, ctx);
        goto after_1;
    // 0x800A777C: addu        $a0, $s2, $a0
    ctx->r4 = ADD32(ctx->r18, ctx->r4);
    after_1:
    // 0x800A7780: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800A7784: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800A7788: lw          $v0, 0x28($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X28);
    // 0x800A778C: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    // 0x800A7790: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800A7794: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x800A7798: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800A779C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800A77A0: addiu       $a0, $a0, 0x25AC
    ctx->r4 = ADD32(ctx->r4, 0X25AC);
    // 0x800A77A4: jal         0x800A6904
    // 0x800A77A8: addu        $a0, $s2, $a0
    ctx->r4 = ADD32(ctx->r18, ctx->r4);
    func_800A6904(rdram, ctx);
        goto after_2;
    // 0x800A77A8: addu        $a0, $s2, $a0
    ctx->r4 = ADD32(ctx->r18, ctx->r4);
    after_2:
    // 0x800A77AC: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800A77B0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800A77B4: lw          $v0, 0x2C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X2C);
    // 0x800A77B8: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800A77BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800A77C0: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x800A77C4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800A77C8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800A77CC: addiu       $a0, $a0, 0x25AC
    ctx->r4 = ADD32(ctx->r4, 0X25AC);
    // 0x800A77D0: jal         0x800A6904
    // 0x800A77D4: addu        $a0, $s2, $a0
    ctx->r4 = ADD32(ctx->r18, ctx->r4);
    func_800A6904(rdram, ctx);
        goto after_3;
    // 0x800A77D4: addu        $a0, $s2, $a0
    ctx->r4 = ADD32(ctx->r18, ctx->r4);
    after_3:
    // 0x800A77D8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A77DC: lwc1        $f20, 0x52BC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X52BC);
    // 0x800A77E0: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800A77E4: lw          $v0, 0x40($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X40);
    // 0x800A77E8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800A77EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800A77F0: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x800A77F4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800A77F8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800A77FC: addiu       $a0, $a0, 0x25AC
    ctx->r4 = ADD32(ctx->r4, 0X25AC);
    // 0x800A7800: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800A7804: jal         0x800A6904
    // 0x800A7808: addu        $a0, $s2, $a0
    ctx->r4 = ADD32(ctx->r18, ctx->r4);
    func_800A6904(rdram, ctx);
        goto after_4;
    // 0x800A7808: addu        $a0, $s2, $a0
    ctx->r4 = ADD32(ctx->r18, ctx->r4);
    after_4:
    // 0x800A780C: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800A7810: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800A7814: lw          $v0, 0x44($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X44);
    // 0x800A7818: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800A781C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800A7820: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x800A7824: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800A7828: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800A782C: addiu       $a0, $a0, 0x25AC
    ctx->r4 = ADD32(ctx->r4, 0X25AC);
    // 0x800A7830: jal         0x800A6904
    // 0x800A7834: addu        $a0, $s2, $a0
    ctx->r4 = ADD32(ctx->r18, ctx->r4);
    func_800A6904(rdram, ctx);
        goto after_5;
    // 0x800A7834: addu        $a0, $s2, $a0
    ctx->r4 = ADD32(ctx->r18, ctx->r4);
    after_5:
    // 0x800A7838: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800A783C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800A7840: lw          $v0, 0x48($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X48);
    // 0x800A7844: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x800A7848: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800A784C: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x800A7850: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800A7854: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800A7858: addiu       $a0, $a0, 0x25AC
    ctx->r4 = ADD32(ctx->r4, 0X25AC);
    // 0x800A785C: jal         0x800A6904
    // 0x800A7860: addu        $a0, $s2, $a0
    ctx->r4 = ADD32(ctx->r18, ctx->r4);
    func_800A6904(rdram, ctx);
        goto after_6;
    // 0x800A7860: addu        $a0, $s2, $a0
    ctx->r4 = ADD32(ctx->r18, ctx->r4);
    after_6:
    // 0x800A7864: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800A7868: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800A786C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800A7870: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x800A7874: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800A7878: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800A787C: sllv        $a0, $v0, $s0
    ctx->r4 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x800A7880: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800A7884: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800A7888: addiu       $a0, $a0, 0x25AC
    ctx->r4 = ADD32(ctx->r4, 0X25AC);
    // 0x800A788C: jal         0x800A6904
    // 0x800A7890: addu        $a0, $s2, $a0
    ctx->r4 = ADD32(ctx->r18, ctx->r4);
    func_800A6904(rdram, ctx);
        goto after_7;
    // 0x800A7890: addu        $a0, $s2, $a0
    ctx->r4 = ADD32(ctx->r18, ctx->r4);
    after_7:
    // 0x800A7894: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800A7898: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800A789C: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x800A78A0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800A78A4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800A78A8: sllv        $a0, $v0, $s0
    ctx->r4 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x800A78AC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800A78B0: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800A78B4: addiu       $a0, $a0, 0x25AC
    ctx->r4 = ADD32(ctx->r4, 0X25AC);
    // 0x800A78B8: jal         0x800A6904
    // 0x800A78BC: addu        $a0, $s2, $a0
    ctx->r4 = ADD32(ctx->r18, ctx->r4);
    func_800A6904(rdram, ctx);
        goto after_8;
    // 0x800A78BC: addu        $a0, $s2, $a0
    ctx->r4 = ADD32(ctx->r18, ctx->r4);
    after_8:
    // 0x800A78C0: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800A78C4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800A78C8: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x800A78CC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800A78D0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800A78D4: sllv        $a0, $v0, $s0
    ctx->r4 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x800A78D8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800A78DC: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800A78E0: addiu       $a0, $a0, 0x25AC
    ctx->r4 = ADD32(ctx->r4, 0X25AC);
    // 0x800A78E4: jal         0x800A6904
    // 0x800A78E8: addu        $a0, $s2, $a0
    ctx->r4 = ADD32(ctx->r18, ctx->r4);
    func_800A6904(rdram, ctx);
        goto after_9;
    // 0x800A78E8: addu        $a0, $s2, $a0
    ctx->r4 = ADD32(ctx->r18, ctx->r4);
    after_9:
    // 0x800A78EC: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800A78F0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800A78F4: lw          $v0, 0x3C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X3C);
    // 0x800A78F8: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x800A78FC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800A7900: sllv        $a0, $v0, $s0
    ctx->r4 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x800A7904: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800A7908: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800A790C: addiu       $a0, $a0, 0x25AC
    ctx->r4 = ADD32(ctx->r4, 0X25AC);
    // 0x800A7910: jal         0x800A6904
    // 0x800A7914: addu        $a0, $s2, $a0
    ctx->r4 = ADD32(ctx->r18, ctx->r4);
    func_800A6904(rdram, ctx);
        goto after_10;
    // 0x800A7914: addu        $a0, $s2, $a0
    ctx->r4 = ADD32(ctx->r18, ctx->r4);
    after_10:
    // 0x800A7918: j           L_800A7984
    // 0x800A791C: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
        goto L_800A7984;
    // 0x800A791C: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
L_800A7920:
    // 0x800A7920: lwc1        $f0, 0x20($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800A7924: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A7928: swc1        $f0, 0x950($v0)
    MEM_W(0X950, ctx->r2) = ctx->f0.u32l;
    // 0x800A792C: lwc1        $f0, 0x24($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800A7930: addiu       $v0, $v0, 0x950
    ctx->r2 = ADD32(ctx->r2, 0X950);
    // 0x800A7934: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x800A7938: lwc1        $f0, 0x28($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X28);
    // 0x800A793C: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x800A7940: lwc1        $f0, 0x2C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x800A7944: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x800A7948: lwc1        $f0, 0x40($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X40);
    // 0x800A794C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800A7950: lwc1        $f0, 0x44($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X44);
    // 0x800A7954: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x800A7958: lwc1        $f0, 0x48($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X48);
    // 0x800A795C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800A7960: lwc1        $f0, 0x30($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X30);
    // 0x800A7964: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800A7968: lwc1        $f0, 0x34($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X34);
    // 0x800A796C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800A7970: lwc1        $f0, 0x38($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X38);
    // 0x800A7974: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800A7978: lwc1        $f0, 0x3C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x800A797C: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800A7980: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
L_800A7984:
    // 0x800A7984: lwc1        $f12, 0x950($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X950);
    // 0x800A7988: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A798C: lwc1        $f2, 0x52C0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X52C0);
    // 0x800A7990: mul.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x800A7994: addiu       $v0, $v1, 0x950
    ctx->r2 = ADD32(ctx->r3, 0X950);
    // 0x800A7998: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800A799C: mul.s       $f10, $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800A79A0: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800A79A4: mul.s       $f8, $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800A79A8: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800A79AC: mul.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800A79B0: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800A79B4: mul.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800A79B8: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800A79BC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800A79C0: swc1        $f12, 0x950($v1)
    MEM_W(0X950, ctx->r3) = ctx->f12.u32l;
    // 0x800A79C4: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x800A79C8: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x800A79CC: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x800A79D0: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x800A79D4: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800A79D8: lbu         $v0, 0x1F($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1F);
    // 0x800A79DC: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x800A79E0: beq         $v0, $zero, L_800A7ACC
    if (ctx->r2 == 0) {
        // 0x800A79E4: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_800A7ACC;
    }
    // 0x800A79E4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800A79E8: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A79EC: addiu       $a1, $a1, 0x52B4
    ctx->r5 = ADD32(ctx->r5, 0X52B4);
    // 0x800A79F0: jal         0x800AF284
    // 0x800A79F4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800AF284(rdram, ctx);
        goto after_11;
    // 0x800A79F4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_11:
    // 0x800A79F8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800A79FC: bne         $v0, $zero, L_800A7A54
    if (ctx->r2 != 0) {
        // 0x800A7A00: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_800A7A54;
    }
    // 0x800A7A00: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800A7A04: andi        $v1, $s3, 0xFF
    ctx->r3 = ctx->r19 & 0XFF;
    // 0x800A7A08: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800A7A0C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A7A10: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A7A14: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800A7A18: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A7A1C: lw          $v1, 0x1900($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1900);
    // 0x800A7A20: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A7A24: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A7A28: lbu         $v1, 0x2($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X2);
    // 0x800A7A2C: addiu       $a0, $a0, -0x6D4
    ctx->r4 = ADD32(ctx->r4, -0X6D4);
    // 0x800A7A30: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800A7A34: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A7A38: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800A7A3C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A7A40: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A7A44: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800A7A48: lwc1        $f0, 0x54($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X54);
    // 0x800A7A4C: j           L_800A7AD8
    // 0x800A7A50: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
        goto L_800A7AD8;
    // 0x800A7A50: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
L_800A7A54:
    // 0x800A7A54: andi        $v1, $s3, 0xFF
    ctx->r3 = ctx->r19 & 0XFF;
    // 0x800A7A58: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800A7A5C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A7A60: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A7A64: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800A7A68: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A7A6C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A7A70: addiu       $a0, $a0, -0x6D4
    ctx->r4 = ADD32(ctx->r4, -0X6D4);
    // 0x800A7A74: lw          $v1, 0x1900($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1900);
    // 0x800A7A78: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800A7A7C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A7A80: lwc1        $f0, 0x52C4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X52C4);
    // 0x800A7A84: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A7A88: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800A7A8C: lbu         $v1, 0x2($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X2);
    // 0x800A7A90: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800A7A94: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800A7A98: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A7A9C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800A7AA0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A7AA4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A7AA8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800A7AAC: lwc1        $f4, 0x54($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X54);
    // 0x800A7AB0: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x800A7AB4: nop

    // 0x800A7AB8: bc1t        L_800A7AD8
    if (c1cs) {
        // 0x800A7ABC: swc1        $f2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
            goto L_800A7AD8;
    }
    // 0x800A7ABC: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x800A7AC0: mul.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800A7AC4: j           L_800A7AD8
    // 0x800A7AC8: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
        goto L_800A7AD8;
    // 0x800A7AC8: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
L_800A7ACC:
    // 0x800A7ACC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A7AD0: lwc1        $f0, 0x52C8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X52C8);
    // 0x800A7AD4: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
L_800A7AD8:
    // 0x800A7AD8: andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // 0x800A7ADC: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x800A7AE0: sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2 << 2);
    // 0x800A7AE4: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x800A7AE8: sll         $s0, $s0, 4
    ctx->r16 = S32(ctx->r16 << 4);
    // 0x800A7AEC: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x800A7AF0: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x800A7AF4: lw          $v0, 0x1900($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1900);
    // 0x800A7AF8: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800A7AFC: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800A7B00: swc1        $f0, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f0.u32l;
    // 0x800A7B04: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800A7B08: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800A7B0C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800A7B10: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x800A7B14: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800A7B18: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800A7B1C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800A7B20: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800A7B24: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800A7B28: jal         0x8001CAC4
    // 0x800A7B2C: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    func_8001CAC4(rdram, ctx);
        goto after_12;
    // 0x800A7B2C: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_12:
    // 0x800A7B30: lw          $v0, 0x1900($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1900);
    // 0x800A7B34: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x800A7B38: lbu         $v1, 0x2($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2);
    // 0x800A7B3C: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
    // 0x800A7B40: beq         $v1, $v0, L_800A7B50
    if (ctx->r3 == ctx->r2) {
        // 0x800A7B44: addiu       $v0, $zero, 0x1B
        ctx->r2 = ADD32(0, 0X1B);
            goto L_800A7B50;
    }
    // 0x800A7B44: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    // 0x800A7B48: bne         $v1, $v0, L_800A7B60
    if (ctx->r3 != ctx->r2) {
        // 0x800A7B4C: addiu       $s0, $sp, 0x38
        ctx->r16 = ADD32(ctx->r29, 0X38);
            goto L_800A7B60;
    }
    // 0x800A7B4C: addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
L_800A7B50:
    // 0x800A7B50: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    // 0x800A7B54: jal         0x8001CCCC
    // 0x800A7B58: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    func_8001CCCC(rdram, ctx);
        goto after_13;
    // 0x800A7B58: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_13:
    // 0x800A7B5C: addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
L_800A7B60:
    // 0x800A7B60: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800A7B64: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x800A7B68: jal         0x8001D144
    // 0x800A7B6C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_8001D144(rdram, ctx);
        goto after_14;
    // 0x800A7B6C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_14:
    // 0x800A7B70: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800A7B74: jal         0x8001DAEC
    // 0x800A7B78: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8001DAEC(rdram, ctx);
        goto after_15;
    // 0x800A7B78: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_15:
    // 0x800A7B7C: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800A7B80: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800A7B84: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800A7B88: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800A7B8C: jal         0x8001CB04
    // 0x800A7B90: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8001CB04(rdram, ctx);
        goto after_16;
    // 0x800A7B90: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_16:
    // 0x800A7B94: andi        $v1, $s3, 0xFF
    ctx->r3 = ctx->r19 & 0XFF;
    // 0x800A7B98: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800A7B9C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A7BA0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A7BA4: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800A7BA8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A7BAC: lw          $v1, 0x1900($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1900);
    // 0x800A7BB0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A7BB4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A7BB8: lbu         $v1, 0x2($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X2);
    // 0x800A7BBC: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    // 0x800A7BC0: bne         $v1, $v0, L_800A7BE4
    if (ctx->r3 != ctx->r2) {
        // 0x800A7BC4: lui         $s0, 0x800B
        ctx->r16 = S32(0X800B << 16);
            goto L_800A7BE4;
    }
    // 0x800A7BC4: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x800A7BC8: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A7BCC: lw          $a1, 0xB30($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XB30);
    // 0x800A7BD0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800A7BD4: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800A7BD8: jal         0x8001CB04
    // 0x800A7BDC: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8001CB04(rdram, ctx);
        goto after_17;
    // 0x800A7BDC: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_17:
    // 0x800A7BE0: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
L_800A7BE4:
    // 0x800A7BE4: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800A7BE8: lwc1        $f0, 0x950($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X950);
    // 0x800A7BEC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800A7BF0: addiu       $s0, $s0, 0x950
    ctx->r16 = ADD32(ctx->r16, 0X950);
    // 0x800A7BF4: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800A7BF8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800A7BFC: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800A7C00: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800A7C04: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800A7C08: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800A7C0C: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800A7C10: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800A7C14: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800A7C18: jal         0x8001CA90
    // 0x800A7C1C: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    func_8001CA90(rdram, ctx);
        goto after_18;
    // 0x800A7C1C: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_18:
    // 0x800A7C20: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x800A7C24: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800A7C28: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x800A7C2C: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x800A7C30: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x800A7C34: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x800A7C38: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x800A7C3C: ldc1        $f22, 0x70($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X70);
    // 0x800A7C40: ldc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X68);
    // 0x800A7C44: jr          $ra
    // 0x800A7C48: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800A7C48: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_800A7C4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7C4C: addiu       $sp, $sp, -0x850
    ctx->r29 = ADD32(ctx->r29, -0X850);
    // 0x800A7C50: sw          $s7, 0x844($sp)
    MEM_W(0X844, ctx->r29) = ctx->r23;
    // 0x800A7C54: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // 0x800A7C58: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A7C5C: addiu       $v1, $v0, 0xB40
    ctx->r3 = ADD32(ctx->r2, 0XB40);
    // 0x800A7C60: sw          $ra, 0x84C($sp)
    MEM_W(0X84C, ctx->r29) = ctx->r31;
    // 0x800A7C64: sw          $fp, 0x848($sp)
    MEM_W(0X848, ctx->r29) = ctx->r30;
    // 0x800A7C68: sw          $s6, 0x840($sp)
    MEM_W(0X840, ctx->r29) = ctx->r22;
    // 0x800A7C6C: sw          $s5, 0x83C($sp)
    MEM_W(0X83C, ctx->r29) = ctx->r21;
    // 0x800A7C70: sw          $s4, 0x838($sp)
    MEM_W(0X838, ctx->r29) = ctx->r20;
    // 0x800A7C74: sw          $s3, 0x834($sp)
    MEM_W(0X834, ctx->r29) = ctx->r19;
    // 0x800A7C78: sw          $s2, 0x830($sp)
    MEM_W(0X830, ctx->r29) = ctx->r18;
    // 0x800A7C7C: sw          $s1, 0x82C($sp)
    MEM_W(0X82C, ctx->r29) = ctx->r17;
    // 0x800A7C80: sw          $s0, 0x828($sp)
    MEM_W(0X828, ctx->r29) = ctx->r16;
    // 0x800A7C84: sw          $a0, 0x850($sp)
    MEM_W(0X850, ctx->r29) = ctx->r4;
    // 0x800A7C88: sb          $a1, 0x810($sp)
    MEM_B(0X810, ctx->r29) = ctx->r5;
    // 0x800A7C8C: sb          $a2, 0x811($sp)
    MEM_B(0X811, ctx->r29) = ctx->r6;
    // 0x800A7C90: sb          $zero, 0x81F($sp)
    MEM_B(0X81F, ctx->r29) = 0;
    // 0x800A7C94: sll         $v0, $s7, 16
    ctx->r2 = S32(ctx->r23 << 16);
L_800A7C98:
    // 0x800A7C98: sra         $v0, $v0, 14
    ctx->r2 = S32(SIGNED(ctx->r2) >> 14);
    // 0x800A7C9C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A7CA0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800A7CA4: addiu       $v0, $s7, 0x1
    ctx->r2 = ADD32(ctx->r23, 0X1);
    // 0x800A7CA8: addu        $s7, $v0, $zero
    ctx->r23 = ADD32(ctx->r2, 0);
    // 0x800A7CAC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800A7CB0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800A7CB4: slti        $v0, $v0, 0x20
    ctx->r2 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x800A7CB8: bne         $v0, $zero, L_800A7C98
    if (ctx->r2 != 0) {
        // 0x800A7CBC: sll         $v0, $s7, 16
        ctx->r2 = S32(ctx->r23 << 16);
            goto L_800A7C98;
    }
    // 0x800A7CBC: sll         $v0, $s7, 16
    ctx->r2 = S32(ctx->r23 << 16);
    // 0x800A7CC0: lw          $t0, 0x850($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X850);
    // 0x800A7CC4: lhu         $v0, 0x4A($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X4A);
    // 0x800A7CC8: beq         $v0, $zero, L_800A83F0
    if (ctx->r2 == 0) {
        // 0x800A7CCC: addu        $s7, $zero, $zero
        ctx->r23 = ADD32(0, 0);
            goto L_800A83F0;
    }
    // 0x800A7CCC: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // 0x800A7CD0: lui         $fp, 0x800B
    ctx->r30 = S32(0X800B << 16);
    // 0x800A7CD4: addiu       $t0, $sp, 0x10
    ctx->r8 = ADD32(ctx->r29, 0X10);
    // 0x800A7CD8: sw          $t0, 0x824($sp)
    MEM_W(0X824, ctx->r29) = ctx->r8;
    // 0x800A7CDC: addiu       $t0, $sp, 0x50
    ctx->r8 = ADD32(ctx->r29, 0X50);
    // 0x800A7CE0: sw          $t0, 0x820($sp)
    MEM_W(0X820, ctx->r29) = ctx->r8;
    // 0x800A7CE4: sll         $v0, $s7, 16
    ctx->r2 = S32(ctx->r23 << 16);
L_800A7CE8:
    // 0x800A7CE8: sra         $s0, $v0, 16
    ctx->r16 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800A7CEC: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x800A7CF0: addu        $s1, $v0, $s0
    ctx->r17 = ADD32(ctx->r2, ctx->r16);
    // 0x800A7CF4: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x800A7CF8: subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x800A7CFC: lw          $t0, 0x850($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X850);
    // 0x800A7D00: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x800A7D04: addu        $v0, $t0, $a1
    ctx->r2 = ADD32(ctx->r8, ctx->r5);
    // 0x800A7D08: lbu         $v0, 0x13F7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X13F7);
    // 0x800A7D0C: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x800A7D10: beq         $v0, $zero, L_800A83D0
    if (ctx->r2 == 0) {
        // 0x800A7D14: addiu       $v0, $s7, 0x1
        ctx->r2 = ADD32(ctx->r23, 0X1);
            goto L_800A83D0;
    }
    // 0x800A7D14: addiu       $v0, $s7, 0x1
    ctx->r2 = ADD32(ctx->r23, 0X1);
    // 0x800A7D18: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800A7D1C: addiu       $a1, $a1, 0x13D8
    ctx->r5 = ADD32(ctx->r5, 0X13D8);
    // 0x800A7D20: jal         0x8000761C
    // 0x800A7D24: addu        $a1, $t0, $a1
    ctx->r5 = ADD32(ctx->r8, ctx->r5);
    rs_strcpy(rdram, ctx);
        goto after_0;
    // 0x800A7D24: addu        $a1, $t0, $a1
    ctx->r5 = ADD32(ctx->r8, ctx->r5);
    after_0:
    // 0x800A7D28: sll         $v0, $s1, 4
    ctx->r2 = S32(ctx->r17 << 4);
    // 0x800A7D2C: subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x800A7D30: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A7D34: lw          $v1, 0x1900($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X1900);
    // 0x800A7D38: lw          $a0, 0x824($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X824);
    // 0x800A7D3C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A7D40: lbu         $v0, 0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1);
    // 0x800A7D44: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800A7D48: jal         0x8003471C
    // 0x800A7D4C: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    strlen_recomp(rdram, ctx);
        goto after_1;
    // 0x800A7D4C: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    after_1:
    // 0x800A7D50: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800A7D54: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x800A7D58: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800A7D5C: bltz        $v0, L_800A7D9C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A7D60: addiu       $v1, $zero, 0x2F
        ctx->r3 = ADD32(0, 0X2F);
            goto L_800A7D9C;
    }
    // 0x800A7D60: addiu       $v1, $zero, 0x2F
    ctx->r3 = ADD32(0, 0X2F);
    // 0x800A7D64: sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18 << 16);
    // 0x800A7D68: lw          $t0, 0x824($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X824);
L_800A7D6C:
    // 0x800A7D6C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800A7D70: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x800A7D74: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800A7D78: beq         $v0, $v1, L_800A8120
    if (ctx->r2 == ctx->r3) {
        // 0x800A7D7C: addiu       $v0, $s2, -0x1
        ctx->r2 = ADD32(ctx->r18, -0X1);
            goto L_800A8120;
    }
    // 0x800A7D7C: addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    // 0x800A7D80: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x800A7D84: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800A7D88: bgez        $v0, L_800A7D6C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A7D8C: sll         $v0, $s2, 16
        ctx->r2 = S32(ctx->r18 << 16);
            goto L_800A7D6C;
    }
    // 0x800A7D8C: sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18 << 16);
L_800A7D90:
    // 0x800A7D90: sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18 << 16);
    // 0x800A7D94: bgez        $v0, L_800A7DA8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A7D98: sra         $v0, $v0, 16
        ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800A7DA8;
    }
    // 0x800A7D98: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_800A7D9C:
    // 0x800A7D9C: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800A7DA0: sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18 << 16);
    // 0x800A7DA4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_800A7DA8:
    // 0x800A7DA8: lw          $t0, 0x824($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X824);
    // 0x800A7DAC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800A7DB0: addu        $a1, $t0, $v0
    ctx->r5 = ADD32(ctx->r8, ctx->r2);
    // 0x800A7DB4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A7DB8: addiu       $a2, $v0, 0x52B4
    ctx->r6 = ADD32(ctx->r2, 0X52B4);
    // 0x800A7DBC: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
L_800A7DC0:
    // 0x800A7DC0: addu        $v1, $a1, $v0
    ctx->r3 = ADD32(ctx->r5, ctx->r2);
    // 0x800A7DC4: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x800A7DC8: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x800A7DCC: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800A7DD0: bne         $v1, $v0, L_800A8118
    if (ctx->r3 != ctx->r2) {
        // 0x800A7DD4: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800A8118;
    }
    // 0x800A7DD4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A7DD8: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800A7DDC: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800A7DE0: bne         $v0, $zero, L_800A7DC0
    if (ctx->r2 != 0) {
        // 0x800A7DE4: andi        $v0, $a0, 0xFFFF
        ctx->r2 = ctx->r4 & 0XFFFF;
            goto L_800A7DC0;
    }
    // 0x800A7DE4: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800A7DE8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800A7DEC:
    // 0x800A7DEC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800A7DF0: beql        $v0, $zero, L_800A7DF8
    if (ctx->r2 == 0) {
        // 0x800A7DF4: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_800A7DF8;
    }
    goto skip_0;
    // 0x800A7DF4: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    skip_0:
L_800A7DF8:
    // 0x800A7DF8: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800A7DFC: jal         0x8000761C
    // 0x800A7E00: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    rs_strcpy(rdram, ctx);
        goto after_2;
    // 0x800A7E00: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_2:
    // 0x800A7E04: addu        $s1, $s2, $zero
    ctx->r17 = ADD32(ctx->r18, 0);
    // 0x800A7E08: sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18 << 16);
    // 0x800A7E0C: sra         $s3, $v0, 16
    ctx->r19 = S32(SIGNED(ctx->r2) >> 16);
L_800A7E10:
    // 0x800A7E10: lw          $t0, 0x820($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X820);
    // 0x800A7E14: sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17 << 16);
    // 0x800A7E18: sra         $s0, $v0, 16
    ctx->r16 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800A7E1C: jal         0x8003471C
    // 0x800A7E20: addu        $a0, $t0, $s3
    ctx->r4 = ADD32(ctx->r8, ctx->r19);
    strlen_recomp(rdram, ctx);
        goto after_3;
    // 0x800A7E20: addu        $a0, $t0, $s3
    ctx->r4 = ADD32(ctx->r8, ctx->r19);
    after_3:
    // 0x800A7E24: sltu        $v0, $s0, $v0
    ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800A7E28: beq         $v0, $zero, L_800A7E58
    if (ctx->r2 == 0) {
        // 0x800A7E2C: addu        $s5, $zero, $zero
        ctx->r21 = ADD32(0, 0);
            goto L_800A7E58;
    }
    // 0x800A7E2C: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x800A7E30: lw          $t0, 0x820($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X820);
    // 0x800A7E34: addu        $a0, $t0, $s0
    ctx->r4 = ADD32(ctx->r8, ctx->r16);
    // 0x800A7E38: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800A7E3C: addiu       $v0, $v1, -0x41
    ctx->r2 = ADD32(ctx->r3, -0X41);
    // 0x800A7E40: sltiu       $v0, $v0, 0x1A
    ctx->r2 = ctx->r2 < 0X1A ? 1 : 0;
    // 0x800A7E44: beq         $v0, $zero, L_800A7E50
    if (ctx->r2 == 0) {
        // 0x800A7E48: ori         $v0, $v1, 0x20
        ctx->r2 = ctx->r3 | 0X20;
            goto L_800A7E50;
    }
    // 0x800A7E48: ori         $v0, $v1, 0x20
    ctx->r2 = ctx->r3 | 0X20;
    // 0x800A7E4C: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_800A7E50:
    // 0x800A7E50: j           L_800A7E10
    // 0x800A7E54: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
        goto L_800A7E10;
    // 0x800A7E54: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
L_800A7E58:
    // 0x800A7E58: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A7E5C: addiu       $s4, $v0, -0x6B4
    ctx->r20 = ADD32(ctx->r2, -0X6B4);
    // 0x800A7E60: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x800A7E64: sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18 << 16);
    // 0x800A7E68: sra         $s1, $v0, 16
    ctx->r17 = S32(SIGNED(ctx->r2) >> 16);
L_800A7E6C:
    // 0x800A7E6C: andi        $v1, $s5, 0xFF
    ctx->r3 = ctx->r21 & 0XFF;
    // 0x800A7E70: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800A7E74: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A7E78: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800A7E7C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A7E80: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A7E84: addu        $s0, $v0, $s4
    ctx->r16 = ADD32(ctx->r2, ctx->r20);
    // 0x800A7E88: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800A7E8C: jal         0x800076F8
    // 0x800A7E90: addiu       $a1, $s3, 0x52CC
    ctx->r5 = ADD32(ctx->r19, 0X52CC);
    rs_strcmp(rdram, ctx);
        goto after_4;
    // 0x800A7E90: addiu       $a1, $s3, 0x52CC
    ctx->r5 = ADD32(ctx->r19, 0X52CC);
    after_4:
    // 0x800A7E94: beq         $v0, $zero, L_800A7EB8
    if (ctx->r2 == 0) {
        // 0x800A7E98: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_800A7EB8;
    }
    // 0x800A7E98: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800A7E9C: lw          $t0, 0x820($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X820);
    // 0x800A7EA0: jal         0x800076F8
    // 0x800A7EA4: addu        $a0, $t0, $s1
    ctx->r4 = ADD32(ctx->r8, ctx->r17);
    rs_strcmp(rdram, ctx);
        goto after_5;
    // 0x800A7EA4: addu        $a0, $t0, $s1
    ctx->r4 = ADD32(ctx->r8, ctx->r17);
    after_5:
    // 0x800A7EA8: beq         $v0, $zero, L_800A7EBC
    if (ctx->r2 == 0) {
        // 0x800A7EAC: addiu       $a1, $sp, 0x10
        ctx->r5 = ADD32(ctx->r29, 0X10);
            goto L_800A7EBC;
    }
    // 0x800A7EAC: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800A7EB0: j           L_800A7E6C
    // 0x800A7EB4: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
        goto L_800A7E6C;
    // 0x800A7EB4: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_800A7EB8:
    // 0x800A7EB8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
L_800A7EBC:
    // 0x800A7EBC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A7EC0: addiu       $a2, $v0, 0x52B4
    ctx->r6 = ADD32(ctx->r2, 0X52B4);
    // 0x800A7EC4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800A7EC8: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
L_800A7ECC:
    // 0x800A7ECC: addu        $v1, $a1, $v0
    ctx->r3 = ADD32(ctx->r5, ctx->r2);
    // 0x800A7ED0: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x800A7ED4: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x800A7ED8: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800A7EDC: bne         $v1, $v0, L_800A8110
    if (ctx->r3 != ctx->r2) {
        // 0x800A7EE0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800A8110;
    }
    // 0x800A7EE0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A7EE4: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800A7EE8: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800A7EEC: bne         $v0, $zero, L_800A7ECC
    if (ctx->r2 != 0) {
        // 0x800A7EF0: andi        $v0, $a0, 0xFFFF
        ctx->r2 = ctx->r4 & 0XFFFF;
            goto L_800A7ECC;
    }
    // 0x800A7EF0: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800A7EF4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800A7EF8:
    // 0x800A7EF8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800A7EFC: beq         $v0, $zero, L_800A8038
    if (ctx->r2 == 0) {
        // 0x800A7F00: addu        $s6, $zero, $zero
        ctx->r22 = ADD32(0, 0);
            goto L_800A8038;
    }
    // 0x800A7F00: addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    // 0x800A7F04: andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
    // 0x800A7F08: sll         $s0, $v0, 1
    ctx->r16 = S32(ctx->r2 << 1);
    // 0x800A7F0C: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x800A7F10: sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16 << 3);
    // 0x800A7F14: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x800A7F18: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x800A7F1C: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A7F20: addiu       $v0, $v0, -0x6D4
    ctx->r2 = ADD32(ctx->r2, -0X6D4);
    // 0x800A7F24: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x800A7F28: jal         0x8003471C
    // 0x800A7F2C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    strlen_recomp(rdram, ctx);
        goto after_6;
    // 0x800A7F2C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // 0x800A7F30: bne         $v0, $zero, L_800A7F3C
    if (ctx->r2 != 0) {
        // 0x800A7F34: addu        $s4, $s0, $zero
        ctx->r20 = ADD32(ctx->r16, 0);
            goto L_800A7F3C;
    }
    // 0x800A7F34: addu        $s4, $s0, $zero
    ctx->r20 = ADD32(ctx->r16, 0);
    // 0x800A7F38: addiu       $s4, $sp, 0x10
    ctx->r20 = ADD32(ctx->r29, 0X10);
L_800A7F3C:
    // 0x800A7F3C: lbu         $v1, 0x810($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X810);
    // 0x800A7F40: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // 0x800A7F44: bne         $v1, $v0, L_800A7F74
    if (ctx->r3 != ctx->r2) {
        // 0x800A7F48: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800A7F74;
    }
    // 0x800A7F48: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A7F4C: lw          $v0, 0xB58($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB58);
    // 0x800A7F50: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800A7F54: beq         $v0, $zero, L_800A7F74
    if (ctx->r2 == 0) {
        // 0x800A7F58: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_800A7F74;
    }
    // 0x800A7F58: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800A7F5C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A7F60: jal         0x800076F8
    // 0x800A7F64: addiu       $a1, $a1, 0x517C
    ctx->r5 = ADD32(ctx->r5, 0X517C);
    rs_strcmp(rdram, ctx);
        goto after_7;
    // 0x800A7F64: addiu       $a1, $a1, 0x517C
    ctx->r5 = ADD32(ctx->r5, 0X517C);
    after_7:
    // 0x800A7F68: bne         $v0, $zero, L_800A7F74
    if (ctx->r2 != 0) {
        // 0x800A7F6C: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_800A7F74;
    }
    // 0x800A7F6C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A7F70: addiu       $s4, $v0, 0x52D0
    ctx->r20 = ADD32(ctx->r2, 0X52D0);
L_800A7F74:
    // 0x800A7F74: lbu         $v0, 0x81F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X81F);
    // 0x800A7F78: beq         $v0, $zero, L_800A7FB4
    if (ctx->r2 == 0) {
        // 0x800A7F7C: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_800A7FB4;
    }
    // 0x800A7F7C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800A7F80: addiu       $s3, $sp, 0x90
    ctx->r19 = ADD32(ctx->r29, 0X90);
    // 0x800A7F84: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800A7F88: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
L_800A7F8C:
    // 0x800A7F8C: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x800A7F90: addu        $a0, $s3, $a0
    ctx->r4 = ADD32(ctx->r19, ctx->r4);
    // 0x800A7F94: jal         0x800076F8
    // 0x800A7F98: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    rs_strcmp(rdram, ctx);
        goto after_8;
    // 0x800A7F98: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_8:
    // 0x800A7F9C: beq         $v0, $zero, L_800A8108
    if (ctx->r2 == 0) {
        // 0x800A7FA0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800A8108;
    }
    // 0x800A7FA0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A7FA4: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800A7FA8: sltu        $v0, $v0, $s1
    ctx->r2 = ctx->r2 < ctx->r17 ? 1 : 0;
    // 0x800A7FAC: bne         $v0, $zero, L_800A7F8C
    if (ctx->r2 != 0) {
        // 0x800A7FB0: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_800A7F8C;
    }
    // 0x800A7FB0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
L_800A7FB4:
    // 0x800A7FB4: andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // 0x800A7FB8: bne         $v0, $zero, L_800A8038
    if (ctx->r2 != 0) {
        // 0x800A7FBC: nop
    
            goto L_800A8038;
    }
    // 0x800A7FBC: nop

    // 0x800A7FC0: lbu         $v0, 0x811($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X811);
    // 0x800A7FC4: bne         $v0, $zero, L_800A8048
    if (ctx->r2 != 0) {
        // 0x800A7FC8: sll         $v1, $s7, 16
        ctx->r3 = S32(ctx->r23 << 16);
            goto L_800A8048;
    }
    // 0x800A7FC8: sll         $v1, $s7, 16
    ctx->r3 = S32(ctx->r23 << 16);
    // 0x800A7FCC: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800A7FD0: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800A7FD4: addiu       $a1, $a1, -0x6D4
    ctx->r5 = ADD32(ctx->r5, -0X6D4);
    // 0x800A7FD8: andi        $v1, $s5, 0xFF
    ctx->r3 = ctx->r21 & 0XFF;
    // 0x800A7FDC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800A7FE0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A7FE4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800A7FE8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A7FEC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A7FF0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800A7FF4: lw          $a3, 0x58($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X58);
    // 0x800A7FF8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800A7FFC: srl         $a2, $a3, 6
    ctx->r6 = S32(U32(ctx->r7) >> 6);
    // 0x800A8000: andi        $a2, $a2, 0x1
    ctx->r6 = ctx->r6 & 0X1;
    // 0x800A8004: andi        $a3, $a3, 0x20
    ctx->r7 = ctx->r7 & 0X20;
    // 0x800A8008: sltu        $a3, $a1, $a3
    ctx->r7 = ctx->r5 < ctx->r7 ? 1 : 0;
    // 0x800A800C: jal         0x8005645C
    // 0x800A8010: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    load_hmt_and_hob(rdram, ctx);
        goto after_9;
    // 0x800A8010: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    after_9:
    // 0x800A8014: addiu       $v0, $sp, 0x90
    ctx->r2 = ADD32(ctx->r29, 0X90);
    // 0x800A8018: lbu         $a0, 0x81F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X81F);
    // 0x800A801C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x800A8020: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x800A8024: jal         0x8000761C
    // 0x800A8028: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    rs_strcpy(rdram, ctx);
        goto after_10;
    // 0x800A8028: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_10:
    // 0x800A802C: lbu         $t0, 0x81F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X81F);
    // 0x800A8030: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800A8034: sb          $t0, 0x81F($sp)
    MEM_B(0X81F, ctx->r29) = ctx->r8;
L_800A8038:
    // 0x800A8038: lbu         $v0, 0x811($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X811);
    // 0x800A803C: beq         $v0, $zero, L_800A83D0
    if (ctx->r2 == 0) {
        // 0x800A8040: addiu       $v0, $s7, 0x1
        ctx->r2 = ADD32(ctx->r23, 0X1);
            goto L_800A83D0;
    }
    // 0x800A8040: addiu       $v0, $s7, 0x1
    ctx->r2 = ADD32(ctx->r23, 0X1);
    // 0x800A8044: sll         $v1, $s7, 16
    ctx->r3 = S32(ctx->r23 << 16);
L_800A8048:
    // 0x800A8048: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800A804C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A8050: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A8054: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800A8058: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A805C: sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2 << 2);
    // 0x800A8060: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800A8064: lw          $v1, 0x1900($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X1900);
    // 0x800A8068: addiu       $a0, $a0, -0x6D4
    ctx->r4 = ADD32(ctx->r4, -0X6D4);
    // 0x800A806C: addu        $v1, $s0, $v1
    ctx->r3 = ADD32(ctx->r16, ctx->r3);
    // 0x800A8070: sb          $s5, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r21;
    // 0x800A8074: andi        $v1, $s5, 0xFF
    ctx->r3 = ctx->r21 & 0XFF;
    // 0x800A8078: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800A807C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A8080: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800A8084: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A8088: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A808C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800A8090: lw          $v1, 0x1900($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X1900);
    // 0x800A8094: lbu         $v0, 0x5B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5B);
    // 0x800A8098: addu        $v1, $s0, $v1
    ctx->r3 = ADD32(ctx->r16, ctx->r3);
    // 0x800A809C: sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
    // 0x800A80A0: lw          $v0, 0x1900($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1900);
    // 0x800A80A4: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800A80A8: lbu         $v0, 0x3($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X3);
    // 0x800A80AC: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800A80B0: beq         $v0, $zero, L_800A8128
    if (ctx->r2 == 0) {
        // 0x800A80B4: sll         $a0, $s2, 16
        ctx->r4 = S32(ctx->r18 << 16);
            goto L_800A8128;
    }
    // 0x800A80B4: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x800A80B8: lw          $t0, 0x820($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X820);
    // 0x800A80BC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800A80C0: jal         0x80057338
    // 0x800A80C4: addu        $a0, $t0, $a0
    ctx->r4 = ADD32(ctx->r8, ctx->r4);
    func_80057338(rdram, ctx);
        goto after_11;
    // 0x800A80C4: addu        $a0, $t0, $a0
    ctx->r4 = ADD32(ctx->r8, ctx->r4);
    after_11:
    // 0x800A80C8: lw          $v1, 0x1900($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X1900);
    // 0x800A80CC: addu        $v1, $s0, $v1
    ctx->r3 = ADD32(ctx->r16, ctx->r3);
    // 0x800A80D0: sw          $v0, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r2;
    // 0x800A80D4: sw          $v0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r2;
    // 0x800A80D8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800A80DC: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x800A80E0: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x800A80E4: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x800A80E8: addiu       $a1, $zero, -0x9
    ctx->r5 = ADD32(0, -0X9);
    // 0x800A80EC: and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // 0x800A80F0: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // 0x800A80F4: lw          $v1, 0x54($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X54);
    // 0x800A80F8: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x800A80FC: and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // 0x800A8100: j           L_800A81A4
    // 0x800A8104: sw          $v0, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r2;
        goto L_800A81A4;
    // 0x800A8104: sw          $v0, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r2;
L_800A8108:
    // 0x800A8108: j           L_800A7FB4
    // 0x800A810C: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
        goto L_800A7FB4;
    // 0x800A810C: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_800A8110:
    // 0x800A8110: j           L_800A7EF8
    // 0x800A8114: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A7EF8;
    // 0x800A8114: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A8118:
    // 0x800A8118: j           L_800A7DEC
    // 0x800A811C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A7DEC;
    // 0x800A811C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A8120:
    // 0x800A8120: j           L_800A7D90
    // 0x800A8124: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_800A7D90;
    // 0x800A8124: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800A8128:
    // 0x800A8128: lw          $t0, 0x820($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X820);
    // 0x800A812C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800A8130: jal         0x80056EB0
    // 0x800A8134: addu        $a0, $t0, $a0
    ctx->r4 = ADD32(ctx->r8, ctx->r4);
    func_80056EB0(rdram, ctx);
        goto after_12;
    // 0x800A8134: addu        $a0, $t0, $a0
    ctx->r4 = ADD32(ctx->r8, ctx->r4);
    after_12:
    // 0x800A8138: lw          $v1, 0x1900($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X1900);
    // 0x800A813C: addu        $v1, $s0, $v1
    ctx->r3 = ADD32(ctx->r16, ctx->r3);
    // 0x800A8140: lbu         $a0, 0x3($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X3);
    // 0x800A8144: sw          $v0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r2;
    // 0x800A8148: andi        $v0, $a0, 0x20
    ctx->r2 = ctx->r4 & 0X20;
    // 0x800A814C: beq         $v0, $zero, L_800A8174
    if (ctx->r2 == 0) {
        // 0x800A8150: sw          $zero, 0x54($v1)
        MEM_W(0X54, ctx->r3) = 0;
            goto L_800A8174;
    }
    // 0x800A8150: sw          $zero, 0x54($v1)
    MEM_W(0X54, ctx->r3) = 0;
    // 0x800A8154: andi        $v0, $a0, 0x40
    ctx->r2 = ctx->r4 & 0X40;
    // 0x800A8158: bne         $v0, $zero, L_800A8178
    if (ctx->r2 != 0) {
        // 0x800A815C: sll         $v0, $s7, 16
        ctx->r2 = S32(ctx->r23 << 16);
            goto L_800A8178;
    }
    // 0x800A815C: sll         $v0, $s7, 16
    ctx->r2 = S32(ctx->r23 << 16);
    // 0x800A8160: lw          $a0, 0x50($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X50);
    // 0x800A8164: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800A8168: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x800A816C: jal         0x8005955C
    // 0x800A8170: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8005955C(rdram, ctx);
        goto after_13;
    // 0x800A8170: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_13:
L_800A8174:
    // 0x800A8174: sll         $v0, $s7, 16
    ctx->r2 = S32(ctx->r23 << 16);
L_800A8178:
    // 0x800A8178: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800A817C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800A8180: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A8184: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A8188: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800A818C: lw          $a0, 0x1900($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X1900);
    // 0x800A8190: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800A8194: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x800A8198: lw          $a1, 0x50($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X50);
    // 0x800A819C: jal         0x80071308
    // 0x800A81A0: addiu       $a0, $a0, 0x104
    ctx->r4 = ADD32(ctx->r4, 0X104);
    func_80071308(rdram, ctx);
        goto after_14;
    // 0x800A81A0: addiu       $a0, $a0, 0x104
    ctx->r4 = ADD32(ctx->r4, 0X104);
    after_14:
L_800A81A4:
    // 0x800A81A4: sll         $v1, $s7, 16
    ctx->r3 = S32(ctx->r23 << 16);
    // 0x800A81A8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800A81AC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A81B0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A81B4: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800A81B8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A81BC: sll         $s1, $v0, 2
    ctx->r17 = S32(ctx->r2 << 2);
    // 0x800A81C0: andi        $s0, $s5, 0xFF
    ctx->r16 = ctx->r21 & 0XFF;
    // 0x800A81C4: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x800A81C8: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800A81CC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800A81D0: subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x800A81D4: sll         $s2, $v0, 2
    ctx->r18 = S32(ctx->r2 << 2);
    // 0x800A81D8: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A81DC: lw          $v1, 0x1900($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X1900);
    // 0x800A81E0: addiu       $s3, $v0, -0x6A4
    ctx->r19 = ADD32(ctx->r2, -0X6A4);
    // 0x800A81E4: addu        $a0, $s1, $v1
    ctx->r4 = ADD32(ctx->r17, ctx->r3);
    // 0x800A81E8: lw          $v1, 0x50($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X50);
    // 0x800A81EC: addu        $v0, $s2, $s3
    ctx->r2 = ADD32(ctx->r18, ctx->r19);
    // 0x800A81F0: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x800A81F4: lbu         $v0, 0x3($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X3);
    // 0x800A81F8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800A81FC: beq         $v0, $zero, L_800A821C
    if (ctx->r2 == 0) {
        // 0x800A8200: sw          $zero, 0x60($a0)
        MEM_W(0X60, ctx->r4) = 0;
            goto L_800A821C;
    }
    // 0x800A8200: sw          $zero, 0x60($a0)
    MEM_W(0X60, ctx->r4) = 0;
    // 0x800A8204: lw          $a0, 0x50($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X50);
    // 0x800A8208: jal         0x80054500
    // 0x800A820C: nop

    func_80054500(rdram, ctx);
        goto after_15;
    // 0x800A820C: nop

    after_15:
    // 0x800A8210: lw          $v1, 0x1900($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X1900);
    // 0x800A8214: addu        $v1, $s1, $v1
    ctx->r3 = ADD32(ctx->r17, ctx->r3);
    // 0x800A8218: sw          $v0, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->r2;
L_800A821C:
    // 0x800A821C: lw          $v0, 0x1900($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1900);
    // 0x800A8220: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800A8224: lbu         $v0, 0x3($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X3);
    // 0x800A8228: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800A822C: beq         $v0, $zero, L_800A8284
    if (ctx->r2 == 0) {
        // 0x800A8230: lui         $v1, 0x800B
        ctx->r3 = S32(0X800B << 16);
            goto L_800A8284;
    }
    // 0x800A8230: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x800A8234: addiu       $v1, $v1, 0x4AC
    ctx->r3 = ADD32(ctx->r3, 0X4AC);
    // 0x800A8238: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x800A823C: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800A8240: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A8244: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A8248: lhu         $a2, 0x2($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X2);
    // 0x800A824C: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800A8250: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800A8254: jal         0x8006BD18
    // 0x800A8258: nop

    func_8006BD18(rdram, ctx);
        goto after_16;
    // 0x800A8258: nop

    after_16:
    // 0x800A825C: lw          $v1, 0x1900($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X1900);
    // 0x800A8260: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A8264: lwc1        $f0, 0x52E4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X52E4);
    // 0x800A8268: addu        $v1, $s1, $v1
    ctx->r3 = ADD32(ctx->r17, ctx->r3);
    // 0x800A826C: sw          $v0, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->r2;
    // 0x800A8270: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    // 0x800A8274: lw          $v0, 0x6C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X6C);
    // 0x800A8278: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A827C: lwc1        $f0, 0x52E8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X52E8);
    // 0x800A8280: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
L_800A8284:
    // 0x800A8284: lw          $v0, 0x1900($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1900);
    // 0x800A8288: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x800A828C: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800A8290: sw          $v1, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r3;
    // 0x800A8294: addu        $v0, $s3, $s2
    ctx->r2 = ADD32(ctx->r19, ctx->r18);
    // 0x800A8298: lbu         $v0, 0xC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XC);
    // 0x800A829C: beq         $v0, $zero, L_800A8320
    if (ctx->r2 == 0) {
        // 0x800A82A0: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_800A8320;
    }
    // 0x800A82A0: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A82A4: addiu       $v0, $v0, 0xB40
    ctx->r2 = ADD32(ctx->r2, 0XB40);
    // 0x800A82A8: sll         $v1, $s0, 2
    ctx->r3 = S32(ctx->r16 << 2);
    // 0x800A82AC: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x800A82B0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A82B4: bne         $v0, $zero, L_800A82D4
    if (ctx->r2 != 0) {
        // 0x800A82B8: addiu       $a0, $s3, 0xC
        ctx->r4 = ADD32(ctx->r19, 0XC);
            goto L_800A82D4;
    }
    // 0x800A82B8: addiu       $a0, $s3, 0xC
    ctx->r4 = ADD32(ctx->r19, 0XC);
    // 0x800A82BC: addu        $a0, $s2, $a0
    ctx->r4 = ADD32(ctx->r18, ctx->r4);
    // 0x800A82C0: jal         0x800647E0
    // 0x800A82C4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    load_asset_with_malloc_flags(rdram, ctx);
        goto after_17;
    // 0x800A82C4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_17:
    // 0x800A82C8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800A82CC: jal         0x80082BD0
    // 0x800A82D0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    model_animation_offset_convert(rdram, ctx);
        goto after_18;
    // 0x800A82D0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_18:
L_800A82D4:
    // 0x800A82D4: lw          $v0, 0x1900($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1900);
    // 0x800A82D8: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800A82DC: lw          $v0, 0x50($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X50);
    // 0x800A82E0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800A82E4: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x800A82E8: jal         0x80082B00
    // 0x800A82EC: nop

    func_80082B00(rdram, ctx);
        goto after_19;
    // 0x800A82EC: nop

    after_19:
    // 0x800A82F0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800A82F4: lw          $v0, 0x1900($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1900);
    // 0x800A82F8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800A82FC: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800A8300: jal         0x80082E18
    // 0x800A8304: sw          $a0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r4;
    func_80082E18(rdram, ctx);
        goto after_20;
    // 0x800A8304: sw          $a0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r4;
    after_20:
    // 0x800A8308: lw          $v1, 0x1900($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X1900);
    // 0x800A830C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x800A8310: addu        $v1, $s1, $v1
    ctx->r3 = ADD32(ctx->r17, ctx->r3);
    // 0x800A8314: lw          $a0, 0x58($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X58);
    // 0x800A8318: jal         0x80083258
    // 0x800A831C: sw          $v0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r2;
    func_80083258(rdram, ctx);
        goto after_21;
    // 0x800A831C: sw          $v0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r2;
    after_21:
L_800A8320:
    // 0x800A8320: sll         $v1, $s7, 16
    ctx->r3 = S32(ctx->r23 << 16);
    // 0x800A8324: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800A8328: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A832C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A8330: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800A8334: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A8338: lw          $v1, 0x1900($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X1900);
    // 0x800A833C: sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2 << 2);
    // 0x800A8340: addu        $v1, $s0, $v1
    ctx->r3 = ADD32(ctx->r16, ctx->r3);
    // 0x800A8344: lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X3);
    // 0x800A8348: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x800A834C: beq         $v0, $zero, L_800A838C
    if (ctx->r2 == 0) {
        // 0x800A8350: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800A838C;
    }
    // 0x800A8350: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A8354: lw          $v0, 0xB50($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB50);
    // 0x800A8358: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800A835C: bnel        $v0, $zero, L_800A8390
    if (ctx->r2 != 0) {
        // 0x800A8360: sll         $v1, $s7, 16
        ctx->r3 = S32(ctx->r23 << 16);
            goto L_800A8390;
    }
    goto skip_1;
    // 0x800A8360: sll         $v1, $s7, 16
    ctx->r3 = S32(ctx->r23 << 16);
    skip_1:
    // 0x800A8364: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800A8368: lui         $a2, 0x2000
    ctx->r6 = S32(0X2000 << 16);
    // 0x800A836C: lw          $a0, 0x50($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X50);
    // 0x800A8370: jal         0x8005955C
    // 0x800A8374: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8005955C(rdram, ctx);
        goto after_22;
    // 0x800A8374: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_22:
    // 0x800A8378: lw          $v0, 0x1900($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1900);
    // 0x800A837C: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800A8380: lw          $a0, 0x50($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X50);
    // 0x800A8384: jal         0x80059614
    // 0x800A8388: nop

    func_80059614(rdram, ctx);
        goto after_23;
    // 0x800A8388: nop

    after_23:
L_800A838C:
    // 0x800A838C: sll         $v1, $s7, 16
    ctx->r3 = S32(ctx->r23 << 16);
L_800A8390:
    // 0x800A8390: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800A8394: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A8398: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A839C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800A83A0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A83A4: lw          $v1, 0x1900($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X1900);
    // 0x800A83A8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A83AC: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x800A83B0: lbu         $v1, 0x2($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X2);
    // 0x800A83B4: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x800A83B8: bne         $v1, $v0, L_800A83D0
    if (ctx->r3 != ctx->r2) {
        // 0x800A83BC: addiu       $v0, $s7, 0x1
        ctx->r2 = ADD32(ctx->r23, 0X1);
            goto L_800A83D0;
    }
    // 0x800A83BC: addiu       $v0, $s7, 0x1
    ctx->r2 = ADD32(ctx->r23, 0X1);
    // 0x800A83C0: lw          $a1, 0x50($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X50);
    // 0x800A83C4: jal         0x8007D470
    // 0x800A83C8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8007D470(rdram, ctx);
        goto after_24;
    // 0x800A83C8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_24:
    // 0x800A83CC: addiu       $v0, $s7, 0x1
    ctx->r2 = ADD32(ctx->r23, 0X1);
L_800A83D0:
    // 0x800A83D0: addu        $s7, $v0, $zero
    ctx->r23 = ADD32(ctx->r2, 0);
    // 0x800A83D4: lw          $t0, 0x850($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X850);
    // 0x800A83D8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800A83DC: lhu         $v1, 0x4A($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X4A);
    // 0x800A83E0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800A83E4: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800A83E8: bne         $v0, $zero, L_800A7CE8
    if (ctx->r2 != 0) {
        // 0x800A83EC: sll         $v0, $s7, 16
        ctx->r2 = S32(ctx->r23 << 16);
            goto L_800A7CE8;
    }
    // 0x800A83EC: sll         $v0, $s7, 16
    ctx->r2 = S32(ctx->r23 << 16);
L_800A83F0:
    // 0x800A83F0: lw          $ra, 0x84C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84C);
    // 0x800A83F4: lw          $fp, 0x848($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X848);
    // 0x800A83F8: lw          $s7, 0x844($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X844);
    // 0x800A83FC: lw          $s6, 0x840($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X840);
    // 0x800A8400: lw          $s5, 0x83C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X83C);
    // 0x800A8404: lw          $s4, 0x838($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X838);
    // 0x800A8408: lw          $s3, 0x834($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X834);
    // 0x800A840C: lw          $s2, 0x830($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X830);
    // 0x800A8410: lw          $s1, 0x82C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X82C);
    // 0x800A8414: lw          $s0, 0x828($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X828);
    // 0x800A8418: jr          $ra
    // 0x800A841C: addiu       $sp, $sp, 0x850
    ctx->r29 = ADD32(ctx->r29, 0X850);
    return;
    // 0x800A841C: addiu       $sp, $sp, 0x850
    ctx->r29 = ADD32(ctx->r29, 0X850);
;}
RECOMP_FUNC void func_800A8420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8420: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800A8424: sdc1        $f20, 0x78($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X78, ctx->r29);
    // 0x800A8428: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800A842C: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x800A8430: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x800A8434: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x800A8438: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x800A843C: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x800A8440: sw          $ra, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r31;
    // 0x800A8444: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x800A8448: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x800A844C: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x800A8450: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x800A8454: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x800A8458: sdc1        $f22, 0x80($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X80, ctx->r29);
    // 0x800A845C: lhu         $v0, 0x4A($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X4A);
    // 0x800A8460: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x800A8464: beq         $v0, $zero, L_800A84D8
    if (ctx->r2 == 0) {
        // 0x800A8468: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_800A84D8;
    }
    // 0x800A8468: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800A846C: addiu       $s6, $zero, 0x80
    ctx->r22 = ADD32(0, 0X80);
    // 0x800A8470: lui         $s3, 0x800B
    ctx->r19 = S32(0X800B << 16);
    // 0x800A8474: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
    // 0x800A8478: addu        $s2, $s5, $zero
    ctx->r18 = ADD32(ctx->r21, 0);
L_800A847C:
    // 0x800A847C: lbu         $v0, 0x13F7($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X13F7);
    // 0x800A8480: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x800A8484: bne         $v0, $s6, L_800A84A8
    if (ctx->r2 != ctx->r22) {
        // 0x800A8488: addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
            goto L_800A84A8;
    }
    // 0x800A8488: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800A848C: lw          $v0, 0x1900($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X1900);
    // 0x800A8490: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    // 0x800A8494: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800A8498: lw          $a2, 0x50($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X50);
    // 0x800A849C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800A84A0: j           L_800A84BC
    // 0x800A84A4: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
        goto L_800A84BC;
    // 0x800A84A4: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
L_800A84A8:
    // 0x800A84A8: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    // 0x800A84AC: lw          $a2, 0x1900($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X1900);
    // 0x800A84B0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800A84B4: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    // 0x800A84B8: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
L_800A84BC:
    // 0x800A84BC: jal         0x800A76B8
    // 0x800A84C0: addiu       $s0, $s0, 0x13C
    ctx->r16 = ADD32(ctx->r16, 0X13C);
    func_800A76B8(rdram, ctx);
        goto after_0;
    // 0x800A84C0: addiu       $s0, $s0, 0x13C
    ctx->r16 = ADD32(ctx->r16, 0X13C);
    after_0:
    // 0x800A84C4: lhu         $v0, 0x4A($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X4A);
    // 0x800A84C8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800A84CC: sltu        $v0, $s1, $v0
    ctx->r2 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x800A84D0: bne         $v0, $zero, L_800A847C
    if (ctx->r2 != 0) {
        // 0x800A84D4: addiu       $s2, $s2, 0x4C
        ctx->r18 = ADD32(ctx->r18, 0X4C);
            goto L_800A847C;
    }
    // 0x800A84D4: addiu       $s2, $s2, 0x4C
    ctx->r18 = ADD32(ctx->r18, 0X4C);
L_800A84D8:
    // 0x800A84D8: jal         0x800A98AC
    // 0x800A84DC: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    func_800A98AC(rdram, ctx);
        goto after_1;
    // 0x800A84DC: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_1:
    // 0x800A84E0: lhu         $v0, 0x4A($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X4A);
    // 0x800A84E4: beq         $v0, $zero, L_800A8534
    if (ctx->r2 == 0) {
        // 0x800A84E8: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_800A8534;
    }
    // 0x800A84E8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800A84EC: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A84F0: lw          $v1, 0x1900($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1900);
L_800A84F4:
    // 0x800A84F4: lw          $v0, 0x50($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X50);
    // 0x800A84F8: beql        $v0, $zero, L_800A8510
    if (ctx->r2 == 0) {
        // 0x800A84FC: sw          $zero, 0x10($v1)
        MEM_W(0X10, ctx->r3) = 0;
            goto L_800A8510;
    }
    goto skip_0;
    // 0x800A84FC: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    skip_0:
    // 0x800A8500: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800A8504: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x800A8508: j           L_800A851C
    // 0x800A850C: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
        goto L_800A851C;
    // 0x800A850C: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
L_800A8510:
    // 0x800A8510: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x800A8514: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800A8518: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
L_800A851C:
    // 0x800A851C: lhu         $v0, 0x4A($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X4A);
    // 0x800A8520: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800A8524: sltu        $v0, $s1, $v0
    ctx->r2 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x800A8528: bne         $v0, $zero, L_800A84F4
    if (ctx->r2 != 0) {
        // 0x800A852C: addiu       $v1, $v1, 0x13C
        ctx->r3 = ADD32(ctx->r3, 0X13C);
            goto L_800A84F4;
    }
    // 0x800A852C: addiu       $v1, $v1, 0x13C
    ctx->r3 = ADD32(ctx->r3, 0X13C);
    // 0x800A8530: lhu         $v0, 0x4A($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X4A);
L_800A8534:
    // 0x800A8534: beq         $v0, $zero, L_800A8768
    if (ctx->r2 == 0) {
        // 0x800A8538: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_800A8768;
    }
    // 0x800A8538: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800A853C: addiu       $s7, $zero, 0x3F
    ctx->r23 = ADD32(0, 0X3F);
    // 0x800A8540: lui         $s2, 0x800B
    ctx->r18 = S32(0X800B << 16);
    // 0x800A8544: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A8548: addiu       $s6, $v0, 0x4AC
    ctx->r22 = ADD32(ctx->r2, 0X4AC);
    // 0x800A854C: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
    // 0x800A8550: addu        $s3, $s5, $zero
    ctx->r19 = ADD32(ctx->r21, 0);
L_800A8554:
    // 0x800A8554: lbu         $v1, 0x13F7($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X13F7);
    // 0x800A8558: andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // 0x800A855C: beq         $v0, $zero, L_800A86B8
    if (ctx->r2 == 0) {
        // 0x800A8560: andi        $a0, $v1, 0x3F
        ctx->r4 = ctx->r3 & 0X3F;
            goto L_800A86B8;
    }
    // 0x800A8560: andi        $a0, $v1, 0x3F
    ctx->r4 = ctx->r3 & 0X3F;
    // 0x800A8564: andi        $v1, $v1, 0x3F
    ctx->r3 = ctx->r3 & 0X3F;
    // 0x800A8568: bne         $v1, $s7, L_800A85B8
    if (ctx->r3 != ctx->r23) {
        // 0x800A856C: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800A85B8;
    }
    // 0x800A856C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A8570: lw          $v0, 0x1900($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1900);
    // 0x800A8574: addu        $a0, $s0, $v0
    ctx->r4 = ADD32(ctx->r16, ctx->r2);
    // 0x800A8578: lw          $v1, 0x50($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X50);
    // 0x800A857C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800A8580: beq         $v0, $zero, L_800A8598
    if (ctx->r2 == 0) {
        // 0x800A8584: sw          $v0, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->r2;
            goto L_800A8598;
    }
    // 0x800A8584: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x800A8588: lw          $v0, 0x50($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X50);
    // 0x800A858C: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800A8590: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800A8594: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800A8598:
    // 0x800A8598: lw          $v1, 0x1900($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1900);
    // 0x800A859C: addu        $v1, $s0, $v1
    ctx->r3 = ADD32(ctx->r16, ctx->r3);
    // 0x800A85A0: lw          $v0, 0x50($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X50);
    // 0x800A85A4: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800A85A8: lw          $v0, 0x50($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X50);
    // 0x800A85AC: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800A85B0: j           L_800A8618
    // 0x800A85B4: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
        goto L_800A8618;
    // 0x800A85B4: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
L_800A85B8:
    // 0x800A85B8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A85BC: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800A85C0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A85C4: lw          $v1, 0x1900($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1900);
    // 0x800A85C8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A85CC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A85D0: addu        $v1, $s0, $v1
    ctx->r3 = ADD32(ctx->r16, ctx->r3);
    // 0x800A85D4: lw          $a1, 0x50($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X50);
    // 0x800A85D8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A85DC: addiu       $a0, $a1, 0xC
    ctx->r4 = ADD32(ctx->r5, 0XC);
    // 0x800A85E0: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x800A85E4: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800A85E8: bne         $v1, $zero, L_800A8604
    if (ctx->r3 != 0) {
        // 0x800A85EC: nop
    
            goto L_800A8604;
    }
    // 0x800A85EC: nop

    // 0x800A85F0: sw          $a0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r4;
    // 0x800A85F4: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800A85F8: j           L_800A8618
    // 0x800A85FC: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
        goto L_800A8618;
    // 0x800A85FC: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
L_800A8600:
    // 0x800A8600: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
L_800A8604:
    // 0x800A8604: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800A8608: bne         $v0, $zero, L_800A8600
    if (ctx->r2 != 0) {
        // 0x800A860C: nop
    
            goto L_800A8600;
    }
    // 0x800A860C: nop

    // 0x800A8610: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x800A8614: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
L_800A8618:
    // 0x800A8618: lui         $a0, 0xFF00
    ctx->r4 = S32(0XFF00 << 16);
    // 0x800A861C: lw          $v0, 0x1900($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1900);
    // 0x800A8620: ori         $a0, $a0, 0x4
    ctx->r4 = ctx->r4 | 0X4;
    // 0x800A8624: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    // 0x800A8628: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800A862C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800A8630: and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // 0x800A8634: bnel        $v1, $v0, L_800A8754
    if (ctx->r3 != ctx->r2) {
        // 0x800A8638: addiu       $s0, $s0, 0x13C
        ctx->r16 = ADD32(ctx->r16, 0X13C);
            goto L_800A8754;
    }
    goto skip_1;
    // 0x800A8638: addiu       $s0, $s0, 0x13C
    ctx->r16 = ADD32(ctx->r16, 0X13C);
    skip_1:
    // 0x800A863C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800A8640: jal         0x80059D18
    // 0x800A8644: addiu       $a1, $a1, 0x88
    ctx->r5 = ADD32(ctx->r5, 0X88);
    func_80059D18(rdram, ctx);
        goto after_2;
    // 0x800A8644: addiu       $a1, $a1, 0x88
    ctx->r5 = ADD32(ctx->r5, 0X88);
    after_2:
    // 0x800A8648: lw          $a2, 0x1900($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X1900);
    // 0x800A864C: addu        $a2, $s0, $a2
    ctx->r6 = ADD32(ctx->r16, ctx->r6);
    // 0x800A8650: lbu         $v1, 0x2($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X2);
    // 0x800A8654: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800A8658: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A865C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A8660: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A8664: addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // 0x800A8668: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800A866C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800A8670: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800A8674: lbu         $v1, 0x2($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X2);
    // 0x800A8678: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800A867C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A8680: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A8684: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A8688: addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // 0x800A868C: lwc1        $f2, 0x10($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800A8690: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800A8694: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800A8698: addiu       $a0, $a0, 0x9C4
    ctx->r4 = ADD32(ctx->r4, 0X9C4);
    // 0x800A869C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x800A86A0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800A86A4: lw          $a3, 0x6C($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X6C);
    // 0x800A86A8: jal         0x8006BEC8
    // 0x800A86AC: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    func_8006BEC8(rdram, ctx);
        goto after_3;
    // 0x800A86AC: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_3:
    // 0x800A86B0: j           L_800A8754
    // 0x800A86B4: addiu       $s0, $s0, 0x13C
    ctx->r16 = ADD32(ctx->r16, 0X13C);
        goto L_800A8754;
    // 0x800A86B4: addiu       $s0, $s0, 0x13C
    ctx->r16 = ADD32(ctx->r16, 0X13C);
L_800A86B8:
    // 0x800A86B8: bnel        $a0, $s7, L_800A86F4
    if (ctx->r4 != ctx->r23) {
        // 0x800A86BC: sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4 << 2);
            goto L_800A86F4;
    }
    goto skip_2;
    // 0x800A86BC: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    skip_2:
    // 0x800A86C0: lw          $v0, 0x1900($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1900);
    // 0x800A86C4: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x800A86C8: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800A86CC: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x800A86D0: beq         $v1, $zero, L_800A86DC
    if (ctx->r3 == 0) {
        // 0x800A86D4: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800A86DC;
    }
    // 0x800A86D4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A86D8: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800A86DC:
    // 0x800A86DC: lw          $v0, 0x1900($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1900);
    // 0x800A86E0: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800A86E4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A86E8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800A86EC: j           L_800A8750
    // 0x800A86F0: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
        goto L_800A8750;
    // 0x800A86F0: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
L_800A86F4:
    // 0x800A86F4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800A86F8: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800A86FC: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800A8700: lw          $v1, 0x1900($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1900);
    // 0x800A8704: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A8708: addu        $a1, $s0, $v1
    ctx->r5 = ADD32(ctx->r16, ctx->r3);
    // 0x800A870C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800A8710: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A8714: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A8718: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x800A871C: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800A8720: bne         $v1, $zero, L_800A873C
    if (ctx->r3 != 0) {
        // 0x800A8724: nop
    
            goto L_800A873C;
    }
    // 0x800A8724: nop

    // 0x800A8728: sw          $a1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r5;
    // 0x800A872C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800A8730: j           L_800A8750
    // 0x800A8734: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
        goto L_800A8750;
    // 0x800A8734: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_800A8738:
    // 0x800A8738: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
L_800A873C:
    // 0x800A873C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800A8740: bne         $v0, $zero, L_800A8738
    if (ctx->r2 != 0) {
        // 0x800A8744: nop
    
            goto L_800A8738;
    }
    // 0x800A8744: nop

    // 0x800A8748: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A874C: sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
L_800A8750:
    // 0x800A8750: addiu       $s0, $s0, 0x13C
    ctx->r16 = ADD32(ctx->r16, 0X13C);
L_800A8754:
    // 0x800A8754: lhu         $v0, 0x4A($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X4A);
    // 0x800A8758: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800A875C: sltu        $v0, $s1, $v0
    ctx->r2 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x800A8760: bne         $v0, $zero, L_800A8554
    if (ctx->r2 != 0) {
        // 0x800A8764: addiu       $s3, $s3, 0x4C
        ctx->r19 = ADD32(ctx->r19, 0X4C);
            goto L_800A8554;
    }
    // 0x800A8764: addiu       $s3, $s3, 0x4C
    ctx->r19 = ADD32(ctx->r19, 0X4C);
L_800A8768:
    // 0x800A8768: lhu         $v0, 0x4A($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X4A);
    // 0x800A876C: beq         $v0, $zero, L_800A897C
    if (ctx->r2 == 0) {
        // 0x800A8770: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_800A897C;
    }
    // 0x800A8770: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800A8774: lui         $s2, 0x800B
    ctx->r18 = S32(0X800B << 16);
    // 0x800A8778: lui         $s6, 0x800B
    ctx->r22 = S32(0X800B << 16);
    // 0x800A877C: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
    // 0x800A8780: addu        $s3, $s5, $zero
    ctx->r19 = ADD32(ctx->r21, 0);
L_800A8784:
    // 0x800A8784: lbu         $v0, 0x13F7($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X13F7);
    // 0x800A8788: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x800A878C: beq         $v0, $zero, L_800A8964
    if (ctx->r2 == 0) {
        // 0x800A8790: addiu       $a1, $s4, 0x2C
        ctx->r5 = ADD32(ctx->r20, 0X2C);
            goto L_800A8964;
    }
    // 0x800A8790: addiu       $a1, $s4, 0x2C
    ctx->r5 = ADD32(ctx->r20, 0X2C);
    // 0x800A8794: lw          $a2, 0x1900($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X1900);
    // 0x800A8798: addu        $a2, $s0, $a2
    ctx->r6 = ADD32(ctx->r16, ctx->r6);
    // 0x800A879C: lw          $v0, 0x50($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X50);
    // 0x800A87A0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800A87A4: lwc1        $f0, 0x64($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X64);
    // 0x800A87A8: lwc1        $f2, 0x44($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X44);
    // 0x800A87AC: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800A87B0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800A87B4: addiu       $a2, $a2, 0x70
    ctx->r6 = ADD32(ctx->r6, 0X70);
    // 0x800A87B8: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800A87BC: addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // 0x800A87C0: jal         0x8001DC34
    // 0x800A87C4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_8001DC34(rdram, ctx);
        goto after_4;
    // 0x800A87C4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_4:
    // 0x800A87C8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800A87CC: beq         $v0, $zero, L_800A87E8
    if (ctx->r2 == 0) {
        // 0x800A87D0: nop
    
            goto L_800A87E8;
    }
    // 0x800A87D0: nop

    // 0x800A87D4: lw          $v0, 0x1900($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1900);
    // 0x800A87D8: addu        $a0, $s0, $v0
    ctx->r4 = ADD32(ctx->r16, ctx->r2);
    // 0x800A87DC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800A87E0: beq         $v0, $zero, L_800A8898
    if (ctx->r2 == 0) {
        // 0x800A87E4: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_800A8898;
    }
    // 0x800A87E4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_800A87E8:
    // 0x800A87E8: lw          $v0, 0x1900($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1900);
    // 0x800A87EC: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800A87F0: lw          $a0, 0x50($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X50);
    // 0x800A87F4: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x800A87F8: addiu       $v0, $a0, 0xC
    ctx->r2 = ADD32(ctx->r4, 0XC);
    // 0x800A87FC: bne         $v1, $v0, L_800A8810
    if (ctx->r3 != ctx->r2) {
        // 0x800A8800: nop
    
            goto L_800A8810;
    }
    // 0x800A8800: nop

    // 0x800A8804: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x800A8808: j           L_800A8964
    // 0x800A880C: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
        goto L_800A8964;
    // 0x800A880C: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
L_800A8810:
    // 0x800A8810: beq         $v1, $zero, L_800A882C
    if (ctx->r3 == 0) {
        // 0x800A8814: nop
    
            goto L_800A882C;
    }
    // 0x800A8814: nop

L_800A8818:
    // 0x800A8818: beq         $v1, $v0, L_800A8858
    if (ctx->r3 == ctx->r2) {
        // 0x800A881C: nop
    
            goto L_800A8858;
    }
    // 0x800A881C: nop

    // 0x800A8820: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800A8824: bne         $v1, $zero, L_800A8818
    if (ctx->r3 != 0) {
        // 0x800A8828: nop
    
            goto L_800A8818;
    }
    // 0x800A8828: nop

L_800A882C:
    // 0x800A882C: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x800A8830: lw          $v1, 0xC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XC);
    // 0x800A8834: bne         $v1, $v0, L_800A8848
    if (ctx->r3 != ctx->r2) {
        // 0x800A8838: nop
    
            goto L_800A8848;
    }
    // 0x800A8838: nop

    // 0x800A883C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800A8840: j           L_800A8964
    // 0x800A8844: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
        goto L_800A8964;
    // 0x800A8844: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
L_800A8848:
    // 0x800A8848: beql        $v1, $zero, L_800A8968
    if (ctx->r3 == 0) {
        // 0x800A884C: addiu       $s0, $s0, 0x13C
        ctx->r16 = ADD32(ctx->r16, 0X13C);
            goto L_800A8968;
    }
    goto skip_3;
    // 0x800A884C: addiu       $s0, $s0, 0x13C
    ctx->r16 = ADD32(ctx->r16, 0X13C);
    skip_3:
L_800A8850:
    // 0x800A8850: bne         $v1, $v0, L_800A8884
    if (ctx->r3 != ctx->r2) {
        // 0x800A8854: nop
    
            goto L_800A8884;
    }
    // 0x800A8854: nop

L_800A8858:
    // 0x800A8858: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x800A885C: beq         $a0, $zero, L_800A886C
    if (ctx->r4 == 0) {
        // 0x800A8860: nop
    
            goto L_800A886C;
    }
    // 0x800A8860: nop

    // 0x800A8864: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800A8868: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_800A886C:
    // 0x800A886C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800A8870: beql        $a0, $zero, L_800A8968
    if (ctx->r4 == 0) {
        // 0x800A8874: addiu       $s0, $s0, 0x13C
        ctx->r16 = ADD32(ctx->r16, 0X13C);
            goto L_800A8968;
    }
    goto skip_4;
    // 0x800A8874: addiu       $s0, $s0, 0x13C
    ctx->r16 = ADD32(ctx->r16, 0X13C);
    skip_4:
    // 0x800A8878: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x800A887C: j           L_800A8964
    // 0x800A8880: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
        goto L_800A8964;
    // 0x800A8880: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_800A8884:
    // 0x800A8884: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800A8888: bne         $v1, $zero, L_800A8850
    if (ctx->r3 != 0) {
        // 0x800A888C: nop
    
            goto L_800A8850;
    }
    // 0x800A888C: nop

    // 0x800A8890: j           L_800A8968
    // 0x800A8894: addiu       $s0, $s0, 0x13C
    ctx->r16 = ADD32(ctx->r16, 0X13C);
        goto L_800A8968;
    // 0x800A8894: addiu       $s0, $s0, 0x13C
    ctx->r16 = ADD32(ctx->r16, 0X13C);
L_800A8898:
    // 0x800A8898: lw          $v1, 0x58($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X58);
    // 0x800A889C: beq         $v1, $v0, L_800A88E8
    if (ctx->r3 == ctx->r2) {
        // 0x800A88A0: nop
    
            goto L_800A88E8;
    }
    // 0x800A88A0: nop

    // 0x800A88A4: lwc1        $f12, 0x68($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X68);
    // 0x800A88A8: mul.s       $f12, $f20, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f12.fl);
    // 0x800A88AC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A88B0: lwc1        $f14, 0x52EC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X52EC);
    // 0x800A88B4: jal         0x8001E20C
    // 0x800A88B8: nop

    func_8001E20C(rdram, ctx);
        goto after_5;
    // 0x800A88B8: nop

    after_5:
    // 0x800A88BC: lw          $v0, 0x1900($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1900);
    // 0x800A88C0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800A88C4: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800A88C8: lw          $a0, 0x58($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X58);
    // 0x800A88CC: jal         0x80083008
    // 0x800A88D0: nop

    func_80083008(rdram, ctx);
        goto after_6;
    // 0x800A88D0: nop

    after_6:
    // 0x800A88D4: lw          $v0, 0x1900($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1900);
    // 0x800A88D8: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800A88DC: lw          $a0, 0x58($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X58);
    // 0x800A88E0: jal         0x80083468
    // 0x800A88E4: nop

    func_80083468(rdram, ctx);
        goto after_7;
    // 0x800A88E4: nop

    after_7:
L_800A88E8:
    // 0x800A88E8: lw          $v0, 0x1900($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1900);
    // 0x800A88EC: addu        $v1, $s0, $v0
    ctx->r3 = ADD32(ctx->r16, ctx->r2);
    // 0x800A88F0: lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X3);
    // 0x800A88F4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800A88F8: beq         $v0, $zero, L_800A8914
    if (ctx->r2 == 0) {
        // 0x800A88FC: nop
    
            goto L_800A8914;
    }
    // 0x800A88FC: nop

    // 0x800A8900: lw          $a0, 0x60($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X60);
    // 0x800A8904: lw          $a1, 0x1A08($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X1A08);
    // 0x800A8908: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    // 0x800A890C: jal         0x80053F7C
    // 0x800A8910: nop

    func_80053F7C(rdram, ctx);
        goto after_8;
    // 0x800A8910: nop

    after_8:
L_800A8914:
    // 0x800A8914: lw          $v0, 0x1900($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1900);
    // 0x800A8918: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    // 0x800A891C: lw          $v0, 0x54($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X54);
    // 0x800A8920: bnel        $v0, $zero, L_800A8968
    if (ctx->r2 != 0) {
        // 0x800A8924: addiu       $s0, $s0, 0x13C
        ctx->r16 = ADD32(ctx->r16, 0X13C);
            goto L_800A8968;
    }
    goto skip_5;
    // 0x800A8924: addiu       $s0, $s0, 0x13C
    ctx->r16 = ADD32(ctx->r16, 0X13C);
    skip_5:
    // 0x800A8928: lbu         $v1, 0x104($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X104);
    // 0x800A892C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800A8930: beq         $v1, $v0, L_800A8964
    if (ctx->r3 == ctx->r2) {
        // 0x800A8934: addiu       $a0, $a1, 0x104
        ctx->r4 = ADD32(ctx->r5, 0X104);
            goto L_800A8964;
    }
    // 0x800A8934: addiu       $a0, $a1, 0x104
    ctx->r4 = ADD32(ctx->r5, 0X104);
    // 0x800A8938: lw          $a1, 0x50($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X50);
    // 0x800A893C: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800A8940: jal         0x80072BE0
    // 0x800A8944: nop

    func_80072BE0(rdram, ctx);
        goto after_9;
    // 0x800A8944: nop

    after_9:
    // 0x800A8948: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x800A894C: lw          $a0, 0x1900($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1900);
    // 0x800A8950: addiu       $a2, $a2, 0xA00
    ctx->r6 = ADD32(ctx->r6, 0XA00);
    // 0x800A8954: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // 0x800A8958: lw          $a1, 0x50($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X50);
    // 0x800A895C: jal         0x80071928
    // 0x800A8960: addiu       $a0, $a0, 0x104
    ctx->r4 = ADD32(ctx->r4, 0X104);
    func_80071928(rdram, ctx);
        goto after_10;
    // 0x800A8960: addiu       $a0, $a0, 0x104
    ctx->r4 = ADD32(ctx->r4, 0X104);
    after_10:
L_800A8964:
    // 0x800A8964: addiu       $s0, $s0, 0x13C
    ctx->r16 = ADD32(ctx->r16, 0X13C);
L_800A8968:
    // 0x800A8968: lhu         $v0, 0x4A($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X4A);
    // 0x800A896C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800A8970: sltu        $v0, $s1, $v0
    ctx->r2 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x800A8974: bne         $v0, $zero, L_800A8784
    if (ctx->r2 != 0) {
        // 0x800A8978: addiu       $s3, $s3, 0x4C
        ctx->r19 = ADD32(ctx->r19, 0X4C);
            goto L_800A8784;
    }
    // 0x800A8978: addiu       $s3, $s3, 0x4C
    ctx->r19 = ADD32(ctx->r19, 0X4C);
L_800A897C:
    // 0x800A897C: lw          $ra, 0x70($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X70);
    // 0x800A8980: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x800A8984: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x800A8988: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x800A898C: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x800A8990: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x800A8994: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x800A8998: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x800A899C: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x800A89A0: ldc1        $f22, 0x80($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X80);
    // 0x800A89A4: ldc1        $f20, 0x78($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X78);
    // 0x800A89A8: jr          $ra
    // 0x800A89AC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x800A89AC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_800A89B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A89B0: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x800A89B4: sw          $s7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r23;
    // 0x800A89B8: addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // 0x800A89BC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800A89C0: lhu         $v1, 0xB20($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XB20);
    // 0x800A89C4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A89C8: sw          $ra, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r31;
    // 0x800A89CC: sw          $fp, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r30;
    // 0x800A89D0: sw          $s6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r22;
    // 0x800A89D4: sw          $s5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r21;
    // 0x800A89D8: sw          $s4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r20;
    // 0x800A89DC: sw          $s3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r19;
    // 0x800A89E0: sw          $s2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r18;
    // 0x800A89E4: sw          $s1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r17;
    // 0x800A89E8: sw          $s0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r16;
    // 0x800A89EC: sdc1        $f30, 0x100($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X100, ctx->r29);
    // 0x800A89F0: sdc1        $f28, 0xF8($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0XF8, ctx->r29);
    // 0x800A89F4: sdc1        $f26, 0xF0($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0XF0, ctx->r29);
    // 0x800A89F8: sdc1        $f24, 0xE8($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0XE8, ctx->r29);
    // 0x800A89FC: sdc1        $f22, 0xE0($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XE0, ctx->r29);
    // 0x800A8A00: sdc1        $f20, 0xD8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XD8, ctx->r29);
    // 0x800A8A04: sw          $a1, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r5;
    // 0x800A8A08: sb          $a2, 0xA9($sp)
    MEM_B(0XA9, ctx->r29) = ctx->r6;
    // 0x800A8A0C: addiu       $t3, $v0, 0x52F0
    ctx->r11 = ADD32(ctx->r2, 0X52F0);
    // 0x800A8A10: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800A8A14: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x800A8A18: lw          $t2, 0x8($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X8);
    // 0x800A8A1C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800A8A20: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800A8A24: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800A8A28: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A8A2C: addiu       $t3, $v0, 0x52FC
    ctx->r11 = ADD32(ctx->r2, 0X52FC);
    // 0x800A8A30: lwl         $t0, 0x0($t3)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r11, 0X0);
    // 0x800A8A34: lwr         $t0, 0x3($t3)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r11, 0X3);
    // 0x800A8A38: swl         $t0, 0x30($sp)
    do_swl(rdram, 0X30, ctx->r29, ctx->r8);
    // 0x800A8A3C: swr         $t0, 0x33($sp)
    do_swr(rdram, 0X33, ctx->r29, ctx->r8);
    // 0x800A8A40: lbu         $t0, 0x11B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X11B);
    // 0x800A8A44: sw          $a3, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r7;
    // 0x800A8A48: sltiu       $v1, $v1, 0xC8
    ctx->r3 = ctx->r3 < 0XC8 ? 1 : 0;
    // 0x800A8A4C: beq         $v1, $zero, L_800A9550
    if (ctx->r3 == 0) {
        // 0x800A8A50: sb          $t0, 0xA8($sp)
        MEM_B(0XA8, ctx->r29) = ctx->r8;
            goto L_800A9550;
    }
    // 0x800A8A50: sb          $t0, 0xA8($sp)
    MEM_B(0XA8, ctx->r29) = ctx->r8;
    // 0x800A8A54: lui         $s4, 0x800B
    ctx->r20 = S32(0X800B << 16);
    // 0x800A8A58: addiu       $t1, $sp, 0x30
    ctx->r9 = ADD32(ctx->r29, 0X30);
    // 0x800A8A5C: addiu       $s6, $sp, 0x48
    ctx->r22 = ADD32(ctx->r29, 0X48);
    // 0x800A8A60: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A8A64: addiu       $fp, $v0, 0x1A10
    ctx->r30 = ADD32(ctx->r2, 0X1A10);
    // 0x800A8A68: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A8A6C: ldc1        $f26, 0x5330($at)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r1, 0X5330);
    // 0x800A8A70: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A8A74: lwc1        $f28, 0x5338($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X5338);
    // 0x800A8A78: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A8A7C: lwc1        $f30, 0x533C($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X533C);
    // 0x800A8A80: addiu       $s5, $sp, 0x78
    ctx->r21 = ADD32(ctx->r29, 0X78);
    // 0x800A8A84: sw          $t1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r9;
L_800A8A88:
    // 0x800A8A88: lhu         $v1, 0xB20($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XB20);
    // 0x800A8A8C: lw          $t2, 0x10C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X10C);
    // 0x800A8A90: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800A8A94: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A8A98: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x800A8A9C: addu        $v0, $s7, $v1
    ctx->r2 = ADD32(ctx->r23, ctx->r3);
    // 0x800A8AA0: lw          $v0, 0x5C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5C);
    // 0x800A8AA4: sltu        $v0, $t2, $v0
    ctx->r2 = ctx->r10 < ctx->r2 ? 1 : 0;
    // 0x800A8AA8: bne         $v0, $zero, L_800A9550
    if (ctx->r2 != 0) {
        // 0x800A8AAC: addiu       $v0, $v1, 0x58
        ctx->r2 = ADD32(ctx->r3, 0X58);
            goto L_800A9550;
    }
    // 0x800A8AAC: addiu       $v0, $v1, 0x58
    ctx->r2 = ADD32(ctx->r3, 0X58);
    // 0x800A8AB0: addu        $s2, $s7, $v0
    ctx->r18 = ADD32(ctx->r23, ctx->r2);
    // 0x800A8AB4: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800A8AB8: sltiu       $v0, $v1, 0x17
    ctx->r2 = ctx->r3 < 0X17 ? 1 : 0;
    // 0x800A8ABC: beq         $v0, $zero, L_800A9528
    if (ctx->r2 == 0) {
        // 0x800A8AC0: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_800A9528;
    }
    // 0x800A8AC0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A8AC4: addiu       $v0, $v0, 0x5340
    ctx->r2 = ADD32(ctx->r2, 0X5340);
    // 0x800A8AC8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800A8ACC: addu        $v1, $v1, $v0
    gpr jr_addend_800A8AD4 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A8AD0: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800A8AD4: jr          $v0
    // 0x800A8AD8: nop

    switch (jr_addend_800A8AD4 >> 2) {
        case 0: goto L_800A8ADC; break;
        case 1: goto L_800A8F60; break;
        case 2: goto L_800A902C; break;
        case 3: goto L_800A8B28; break;
        case 4: goto L_800A8B10; break;
        case 5: goto L_800A8B9C; break;
        case 6: goto L_800A8F38; break;
        case 7: goto L_800A8EE8; break;
        case 8: goto L_800A9074; break;
        case 9: goto L_800A9344; break;
        case 10: goto L_800A9354; break;
        case 11: goto L_800A9364; break;
        case 12: goto L_800A93D4; break;
        case 13: goto L_800A941C; break;
        case 14: goto L_800A9468; break;
        case 15: goto L_800A9480; break;
        case 16: goto L_800A9490; break;
        case 17: goto L_800A94AC; break;
        case 18: goto L_800A9528; break;
        case 19: goto L_800A94E8; break;
        case 20: goto L_800A94F8; break;
        case 21: goto L_800A9508; break;
        case 22: goto L_800A9518; break;
        default: switch_error(__func__, 0x800A8AD4, 0x800A5340);
    }
    // 0x800A8AD8: nop

L_800A8ADC:
    // 0x800A8ADC: lbu         $v0, 0xA8($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0XA8);
    // 0x800A8AE0: bne         $v0, $zero, L_800A952C
    if (ctx->r2 != 0) {
        // 0x800A8AE4: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_800A952C;
    }
    // 0x800A8AE4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800A8AE8: lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC);
    // 0x800A8AEC: beq         $v0, $zero, L_800A8AF8
    if (ctx->r2 == 0) {
        // 0x800A8AF0: addiu       $a1, $zero, 0x7F
        ctx->r5 = ADD32(0, 0X7F);
            goto L_800A8AF8;
    }
    // 0x800A8AF0: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x800A8AF4: lbu         $a1, 0xF($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0XF);
L_800A8AF8:
    // 0x800A8AF8: lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X8);
    // 0x800A8AFC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800A8B00: jal         0x80066EE4
    // 0x800A8B04: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_80066EE4(rdram, ctx);
        goto after_0;
    // 0x800A8B04: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x800A8B08: j           L_800A952C
    // 0x800A8B0C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
        goto L_800A952C;
    // 0x800A8B0C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_800A8B10:
    // 0x800A8B10: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x800A8B14: lbu         $s2, 0xB($s2)
    ctx->r18 = MEM_BU(ctx->r18, 0XB);
    // 0x800A8B18: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800A8B1C: sb          $v0, 0x9B0($v1)
    MEM_B(0X9B0, ctx->r3) = ctx->r2;
    // 0x800A8B20: j           L_800A9528
    // 0x800A8B24: sb          $s2, 0xA9($sp)
    MEM_B(0XA9, ctx->r29) = ctx->r18;
        goto L_800A9528;
    // 0x800A8B24: sb          $s2, 0xA9($sp)
    MEM_B(0XA9, ctx->r29) = ctx->r18;
L_800A8B28:
    // 0x800A8B28: lbu         $v0, 0xA8($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0XA8);
    // 0x800A8B2C: bne         $v0, $zero, L_800A952C
    if (ctx->r2 != 0) {
        // 0x800A8B30: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_800A952C;
    }
    // 0x800A8B30: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800A8B34: lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X14);
    // 0x800A8B38: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x800A8B3C: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x800A8B40: sw          $v0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r2;
    // 0x800A8B44: lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X8);
    // 0x800A8B48: addiu       $v1, $v1, -0x918
    ctx->r3 = ADD32(ctx->r3, -0X918);
    // 0x800A8B4C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800A8B50: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A8B54: lw          $v1, 0xC($s2)
    ctx->r3 = MEM_W(ctx->r18, 0XC);
    // 0x800A8B58: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x800A8B5C: beq         $v1, $zero, L_800A8B68
    if (ctx->r3 == 0) {
        // 0x800A8B60: addiu       $a1, $zero, 0x7F
        ctx->r5 = ADD32(0, 0X7F);
            goto L_800A8B68;
    }
    // 0x800A8B60: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x800A8B64: lbu         $a1, 0xF($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0XF);
L_800A8B68:
    // 0x800A8B68: lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X10);
    // 0x800A8B6C: beq         $v0, $zero, L_800A8B78
    if (ctx->r2 == 0) {
        // 0x800A8B70: addiu       $a2, $zero, 0x40
        ctx->r6 = ADD32(0, 0X40);
            goto L_800A8B78;
    }
    // 0x800A8B70: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x800A8B74: lbu         $a2, 0x13($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X13);
L_800A8B78:
    // 0x800A8B78: jal         0x80087EE8
    // 0x800A8B7C: nop

    func_80087EE8(rdram, ctx);
        goto after_1;
    // 0x800A8B7C: nop

    after_1:
    // 0x800A8B80: lui         $t3, 0x800B
    ctx->r11 = S32(0X800B << 16);
    // 0x800A8B84: lw          $v1, 0x14($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X14);
    // 0x800A8B88: addiu       $t3, $t3, 0x1A20
    ctx->r11 = ADD32(ctx->r11, 0X1A20);
    // 0x800A8B8C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800A8B90: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x800A8B94: j           L_800A9528
    // 0x800A8B98: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_800A9528;
    // 0x800A8B98: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800A8B9C:
    // 0x800A8B9C: lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC);
    // 0x800A8BA0: beq         $v0, $zero, L_800A8BCC
    if (ctx->r2 == 0) {
        // 0x800A8BA4: nop
    
            goto L_800A8BCC;
    }
    // 0x800A8BA4: nop

    // 0x800A8BA8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800A8BAC: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x800A8BB0: bltzl       $v0, L_800A8BB8
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A8BB4: add.d       $f0, $f0, $f26
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f26.d); 
    ctx->f0.d = ctx->f0.d + ctx->f26.d;
            goto L_800A8BB8;
    }
    goto skip_0;
    // 0x800A8BB4: add.d       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f26.d); 
    ctx->f0.d = ctx->f0.d + ctx->f26.d;
    skip_0:
L_800A8BB8:
    // 0x800A8BB8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A8BBC: lwc1        $f2, 0x539C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X539C);
    // 0x800A8BC0: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x800A8BC4: j           L_800A8BD4
    // 0x800A8BC8: div.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
        goto L_800A8BD4;
    // 0x800A8BC8: div.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
L_800A8BCC:
    // 0x800A8BCC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A8BD0: lwc1        $f20, 0x53A0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X53A0);
L_800A8BD4:
    // 0x800A8BD4: lw          $v1, 0x10($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X10);
    // 0x800A8BD8: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x800A8BDC: beq         $v0, $zero, L_800A9528
    if (ctx->r2 == 0) {
        // 0x800A8BE0: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_800A9528;
    }
    // 0x800A8BE0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A8BE4: addiu       $v0, $v0, 0x53A8
    ctx->r2 = ADD32(ctx->r2, 0X53A8);
    // 0x800A8BE8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800A8BEC: addu        $v1, $v1, $v0
    gpr jr_addend_800A8BF4 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A8BF0: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800A8BF4: jr          $v0
    // 0x800A8BF8: nop

    switch (jr_addend_800A8BF4 >> 2) {
        case 0: goto L_800A8BFC; break;
        case 1: goto L_800A8C58; break;
        case 2: goto L_800A8C94; break;
        case 3: goto L_800A8D98; break;
        case 4: goto L_800A8E90; break;
        default: switch_error(__func__, 0x800A8BF4, 0x800A53A8);
    }
    // 0x800A8BF8: nop

L_800A8BFC:
    // 0x800A8BFC: lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X8);
    // 0x800A8C00: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800A8C04: lw          $a0, 0x1900($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X1900);
    // 0x800A8C08: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A8C0C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A8C10: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800A8C14: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A8C18: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A8C1C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800A8C20: jal         0x800612A4
    // 0x800A8C24: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    func_800612A4(rdram, ctx);
        goto after_2;
    // 0x800A8C24: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    after_2:
    // 0x800A8C28: lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X8);
    // 0x800A8C2C: lw          $a0, 0x1900($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X1900);
    // 0x800A8C30: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A8C34: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A8C38: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800A8C3C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A8C40: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A8C44: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800A8C48: jal         0x8005EBD8
    // 0x800A8C4C: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    func_8005EBD8(rdram, ctx);
        goto after_3;
    // 0x800A8C4C: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    after_3:
    // 0x800A8C50: j           L_800A952C
    // 0x800A8C54: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
        goto L_800A952C;
    // 0x800A8C54: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_800A8C58:
    // 0x800A8C58: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x800A8C5C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800A8C60: lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X8);
    // 0x800A8C64: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800A8C68: lw          $a0, 0x1900($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X1900);
    // 0x800A8C6C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800A8C70: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A8C74: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A8C78: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800A8C7C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800A8C80: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x800A8C84: jal         0x80077570
    // 0x800A8C88: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    func_80077570(rdram, ctx);
        goto after_4;
    // 0x800A8C88: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    after_4:
    // 0x800A8C8C: j           L_800A952C
    // 0x800A8C90: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
        goto L_800A952C;
    // 0x800A8C90: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_800A8C94:
    // 0x800A8C94: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800A8C98: lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X8);
    // 0x800A8C9C: lw          $a3, 0xAC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XAC);
    // 0x800A8CA0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A8CA4: lwc1        $f10, 0x53BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X53BC);
    // 0x800A8CA8: lw          $a1, 0x1900($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X1900);
    // 0x800A8CAC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A8CB0: lwc1        $f0, 0x53C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X53C0);
    // 0x800A8CB4: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x800A8CB8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800A8CBC: swc1        $f28, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f28.u32l;
    // 0x800A8CC0: swc1        $f30, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f30.u32l;
    // 0x800A8CC4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A8CC8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A8CCC: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800A8CD0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A8CD4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A8CD8: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800A8CDC: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    // 0x800A8CE0: mul.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x800A8CE4: jal         0x80072684
    // 0x800A8CE8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_80072684(rdram, ctx);
        goto after_5;
    // 0x800A8CE8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x800A8CEC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800A8CF0: lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X8);
    // 0x800A8CF4: lw          $a3, 0xAC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XAC);
    // 0x800A8CF8: lw          $a1, 0x1900($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X1900);
    // 0x800A8CFC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A8D00: lwc1        $f0, 0x53C4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X53C4);
    // 0x800A8D04: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x800A8D08: swc1        $f28, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f28.u32l;
    // 0x800A8D0C: swc1        $f30, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f30.u32l;
    // 0x800A8D10: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A8D14: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A8D18: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800A8D1C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A8D20: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A8D24: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800A8D28: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    // 0x800A8D2C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800A8D30: jal         0x80072684
    // 0x800A8D34: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    func_80072684(rdram, ctx);
        goto after_6;
    // 0x800A8D34: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    after_6:
    // 0x800A8D38: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800A8D3C: lw          $a3, 0xAC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XAC);
    // 0x800A8D40: lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X8);
    // 0x800A8D44: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A8D48: lwc1        $f10, 0x53C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X53C8);
    // 0x800A8D4C: lw          $a1, 0x1900($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X1900);
    // 0x800A8D50: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A8D54: lwc1        $f0, 0x53CC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X53CC);
    // 0x800A8D58: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x800A8D5C: swc1        $f28, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f28.u32l;
    // 0x800A8D60: swc1        $f30, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f30.u32l;
    // 0x800A8D64: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A8D68: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A8D6C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800A8D70: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A8D74: mul.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x800A8D78: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A8D7C: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800A8D80: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    // 0x800A8D84: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800A8D88: jal         0x80072684
    // 0x800A8D8C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    func_80072684(rdram, ctx);
        goto after_7;
    // 0x800A8D8C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    after_7:
    // 0x800A8D90: j           L_800A952C
    // 0x800A8D94: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
        goto L_800A952C;
    // 0x800A8D94: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_800A8D98:
    // 0x800A8D98: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x800A8D9C: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
    // 0x800A8DA0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A8DA4: lwc1        $f24, 0x53D0($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X53D0);
    // 0x800A8DA8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A8DAC: lwc1        $f22, 0x53D4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X53D4);
    // 0x800A8DB0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
L_800A8DB4:
    // 0x800A8DB4: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // 0x800A8DB8: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x800A8DBC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A8DC0: addiu       $s0, $s0, 0x2D
    ctx->r16 = ADD32(ctx->r16, 0X2D);
    // 0x800A8DC4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800A8DC8: addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
    // 0x800A8DCC: jal         0x8007202C
    // 0x800A8DD0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_8007202C(rdram, ctx);
        goto after_8;
    // 0x800A8DD0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_8:
    // 0x800A8DD4: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x800A8DD8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x800A8DDC: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800A8DE0: jal         0x80072300
    // 0x800A8DE4: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    func_80072300(rdram, ctx);
        goto after_9;
    // 0x800A8DE4: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    after_9:
    // 0x800A8DE8: jal         0x80003430
    // 0x800A8DEC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    rand_recomp(rdram, ctx);
        goto after_10;
    // 0x800A8DEC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    after_10:
    // 0x800A8DF0: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800A8DF4: mtc1        $v0, $f20
    ctx->f20.u32l = ctx->r2;
    // 0x800A8DF8: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x800A8DFC: sub.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x800A8E00: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A8E04: lwc1        $f0, 0x53D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X53D8);
    // 0x800A8E08: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A8E0C: lwc1        $f2, 0x53DC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X53DC);
    // 0x800A8E10: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800A8E14: jal         0x80003430
    // 0x800A8E18: add.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f2.fl;
    rand_recomp(rdram, ctx);
        goto after_11;
    // 0x800A8E18: add.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f2.fl;
    after_11:
    // 0x800A8E1C: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800A8E20: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800A8E24: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800A8E28: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // 0x800A8E2C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A8E30: lwc1        $f2, 0x53E0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X53E0);
    // 0x800A8E34: lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X8);
    // 0x800A8E38: lw          $a0, 0x1900($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X1900);
    // 0x800A8E3C: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x800A8E40: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x800A8E44: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A8E48: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A8E4C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800A8E50: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800A8E54: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A8E58: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A8E5C: lwc1        $f2, 0x53E4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X53E4);
    // 0x800A8E60: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A8E64: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800A8E68: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800A8E6C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800A8E70: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800A8E74: jal         0x80072384
    // 0x800A8E78: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    func_80072384(rdram, ctx);
        goto after_12;
    // 0x800A8E78: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    after_12:
    // 0x800A8E7C: sltiu       $v0, $s3, 0x8
    ctx->r2 = ctx->r19 < 0X8 ? 1 : 0;
    // 0x800A8E80: bne         $v0, $zero, L_800A8DB4
    if (ctx->r2 != 0) {
        // 0x800A8E84: addiu       $a0, $sp, 0x38
        ctx->r4 = ADD32(ctx->r29, 0X38);
            goto L_800A8DB4;
    }
    // 0x800A8E84: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800A8E88: j           L_800A952C
    // 0x800A8E8C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
        goto L_800A952C;
    // 0x800A8E8C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_800A8E90:
    // 0x800A8E90: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800A8E94: lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X8);
    // 0x800A8E98: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A8E9C: lwc1        $f0, 0x53E8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X53E8);
    // 0x800A8EA0: lw          $a0, 0x1900($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X1900);
    // 0x800A8EA4: div.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800A8EA8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A8EAC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A8EB0: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800A8EB4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A8EB8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A8EBC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800A8EC0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800A8EC4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A8EC8: lwc1        $f0, 0x53EC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X53EC);
    // 0x800A8ECC: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    // 0x800A8ED0: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x800A8ED4: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x800A8ED8: jal         0x80077858
    // 0x800A8EDC: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_80077858(rdram, ctx);
        goto after_13;
    // 0x800A8EDC: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x800A8EE0: j           L_800A952C
    // 0x800A8EE4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
        goto L_800A952C;
    // 0x800A8EE4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_800A8EE8:
    // 0x800A8EE8: lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X8);
    // 0x800A8EEC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A8EF0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A8EF4: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800A8EF8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A8EFC: lw          $v1, 0x1900($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X1900);
    // 0x800A8F00: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A8F04: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A8F08: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800A8F0C: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x800A8F10: lhu         $v1, 0x4A($s7)
    ctx->r3 = MEM_HU(ctx->r23, 0X4A);
    // 0x800A8F14: lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X8);
    // 0x800A8F18: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800A8F1C: beq         $v0, $zero, L_800A952C
    if (ctx->r2 == 0) {
        // 0x800A8F20: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_800A952C;
    }
    // 0x800A8F20: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800A8F24: lbu         $a0, 0xB($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0XB);
    // 0x800A8F28: jal         0x800AEF30
    // 0x800A8F2C: nop

    func_800AEF30(rdram, ctx);
        goto after_14;
    // 0x800A8F2C: nop

    after_14:
    // 0x800A8F30: j           L_800A952C
    // 0x800A8F34: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
        goto L_800A952C;
    // 0x800A8F34: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_800A8F38:
    // 0x800A8F38: lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X8);
    // 0x800A8F3C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800A8F40: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A8F44: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A8F48: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800A8F4C: lw          $v0, 0x1900($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X1900);
    // 0x800A8F50: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800A8F54: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A8F58: j           L_800A9528
    // 0x800A8F5C: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
        goto L_800A9528;
    // 0x800A8F5C: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_800A8F60:
    // 0x800A8F60: lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X10);
    // 0x800A8F64: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x800A8F68: sw          $v0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r2;
    // 0x800A8F6C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A8F70: addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // 0x800A8F74: lw          $s3, 0x0($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X0);
    // 0x800A8F78: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800A8F7C: bne         $s3, $v0, L_800A952C
    if (ctx->r19 != ctx->r2) {
        // 0x800A8F80: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_800A952C;
    }
    // 0x800A8F80: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800A8F84: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x800A8F88: lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X8);
    // 0x800A8F8C: addiu       $v1, $v1, -0x84C
    ctx->r3 = ADD32(ctx->r3, -0X84C);
    // 0x800A8F90: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A8F94: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A8F98: lhu         $s1, 0x0($v0)
    ctx->r17 = MEM_HU(ctx->r2, 0X0);
    // 0x800A8F9C: jal         0x800AF03C
    // 0x800A8FA0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800AF03C(rdram, ctx);
        goto after_15;
    // 0x800A8FA0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_15:
    // 0x800A8FA4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800A8FA8: jal         0x80066A18
    // 0x800A8FAC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    func_80066A18(rdram, ctx);
        goto after_16;
    // 0x800A8FAC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_16:
    // 0x800A8FB0: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x800A8FB4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800A8FB8: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x800A8FBC: jal         0x80097C2C
    // 0x800A8FC0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80097C2C(rdram, ctx);
        goto after_17;
    // 0x800A8FC0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_17:
    // 0x800A8FC4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800A8FC8: beql        $v1, $s3, L_800A952C
    if (ctx->r3 == ctx->r19) {
        // 0x800A8FCC: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_800A952C;
    }
    goto skip_1;
    // 0x800A8FCC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    skip_1:
    // 0x800A8FD0: lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X10);
    // 0x800A8FD4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A8FD8: addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // 0x800A8FDC: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800A8FE0: lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC);
    // 0x800A8FE4: beq         $v0, $zero, L_800A8FF0
    if (ctx->r2 == 0) {
        // 0x800A8FE8: addiu       $a0, $zero, 0x7F
        ctx->r4 = ADD32(0, 0X7F);
            goto L_800A8FF0;
    }
    // 0x800A8FE8: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    // 0x800A8FEC: lbu         $a0, 0xF($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0XF);
L_800A8FF0:
    // 0x800A8FF0: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A8FF4: lw          $v1, 0x10($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X10);
    // 0x800A8FF8: lhu         $a1, -0x942($v0)
    ctx->r5 = MEM_HU(ctx->r2, -0X942);
    // 0x800A8FFC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800A9000: addu        $v1, $v1, $fp
    ctx->r3 = ADD32(ctx->r3, ctx->r30);
    // 0x800A9004: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x800A9008: jal         0x800964C8
    // 0x800A900C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_800964C8(rdram, ctx);
        goto after_18;
    // 0x800A900C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_18:
    // 0x800A9010: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
    // 0x800A9014: lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC);
    // 0x800A9018: beq         $v0, $zero, L_800A9024
    if (ctx->r2 == 0) {
        // 0x800A901C: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_800A9024;
    }
    // 0x800A901C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800A9020: lbu         $v1, 0xF($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0XF);
L_800A9024:
    // 0x800A9024: j           L_800A9528
    // 0x800A9028: sb          $v1, 0x1A30($a0)
    MEM_B(0X1A30, ctx->r4) = ctx->r3;
        goto L_800A9528;
    // 0x800A9028: sb          $v1, 0x1A30($a0)
    MEM_B(0X1A30, ctx->r4) = ctx->r3;
L_800A902C:
    // 0x800A902C: lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X8);
    // 0x800A9030: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x800A9034: sw          $v0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r2;
    // 0x800A9038: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A903C: addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // 0x800A9040: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x800A9044: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x800A9048: beq         $a2, $s0, L_800A9528
    if (ctx->r6 == ctx->r16) {
        // 0x800A904C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800A9528;
    }
    // 0x800A904C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800A9050: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A9054: lhu         $a1, -0x942($v0)
    ctx->r5 = MEM_HU(ctx->r2, -0X942);
    // 0x800A9058: jal         0x800964C8
    // 0x800A905C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800964C8(rdram, ctx);
        goto after_19;
    // 0x800A905C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_19:
    // 0x800A9060: lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X8);
    // 0x800A9064: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A9068: addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // 0x800A906C: j           L_800A9528
    // 0x800A9070: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
        goto L_800A9528;
    // 0x800A9070: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
L_800A9074:
    // 0x800A9074: lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC);
    // 0x800A9078: sltiu       $v0, $v0, 0xF
    ctx->r2 = ctx->r2 < 0XF ? 1 : 0;
    // 0x800A907C: beq         $v0, $zero, L_800A9528
    if (ctx->r2 == 0) {
        // 0x800A9080: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_800A9528;
    }
    // 0x800A9080: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A9084: addiu       $t3, $v0, 0x5310
    ctx->r11 = ADD32(ctx->r2, 0X5310);
    // 0x800A9088: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800A908C: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x800A9090: lw          $t2, 0x8($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X8);
    // 0x800A9094: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x800A9098: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800A909C: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x800A90A0: lw          $t0, 0xC($t3)
    ctx->r8 = MEM_W(ctx->r11, 0XC);
    // 0x800A90A4: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    // 0x800A90A8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A90AC: addiu       $t3, $v0, 0x5320
    ctx->r11 = ADD32(ctx->r2, 0X5320);
    // 0x800A90B0: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800A90B4: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x800A90B8: lw          $t2, 0x8($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X8);
    // 0x800A90BC: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x800A90C0: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x800A90C4: sw          $t2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r10;
    // 0x800A90C8: lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X8);
    // 0x800A90CC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A90D0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A90D4: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800A90D8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A90DC: lw          $v1, 0x1900($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X1900);
    // 0x800A90E0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A90E4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A90E8: lw          $v0, 0x50($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X50);
    // 0x800A90EC: beq         $v0, $zero, L_800A952C
    if (ctx->r2 == 0) {
        // 0x800A90F0: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_800A952C;
    }
    // 0x800A90F0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800A90F4: lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X10);
    // 0x800A90F8: beq         $v0, $zero, L_800A9124
    if (ctx->r2 == 0) {
        // 0x800A90FC: nop
    
            goto L_800A9124;
    }
    // 0x800A90FC: nop

    // 0x800A9100: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800A9104: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x800A9108: bltzl       $v0, L_800A9110
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A910C: add.d       $f0, $f0, $f26
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f26.d); 
    ctx->f0.d = ctx->f0.d + ctx->f26.d;
            goto L_800A9110;
    }
    goto skip_2;
    // 0x800A910C: add.d       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f26.d); 
    ctx->f0.d = ctx->f0.d + ctx->f26.d;
    skip_2:
L_800A9110:
    // 0x800A9110: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9114: lwc1        $f2, 0x53F0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X53F0);
    // 0x800A9118: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x800A911C: j           L_800A912C
    // 0x800A9120: div.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
        goto L_800A912C;
    // 0x800A9120: div.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
L_800A9124:
    // 0x800A9124: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9128: lwc1        $f20, 0x53F4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X53F4);
L_800A912C:
    // 0x800A912C: lw          $v1, 0xC($s2)
    ctx->r3 = MEM_W(ctx->r18, 0XC);
    // 0x800A9130: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x800A9134: bne         $v1, $v0, L_800A91D8
    if (ctx->r3 != ctx->r2) {
        // 0x800A9138: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800A91D8;
    }
    // 0x800A9138: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A913C: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800A9140: lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X8);
    // 0x800A9144: lw          $a1, 0x1900($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X1900);
    // 0x800A9148: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A914C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A9150: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800A9154: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A9158: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A915C: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800A9160: jal         0x80059D18
    // 0x800A9164: addiu       $a1, $a1, 0x88
    ctx->r5 = ADD32(ctx->r5, 0X88);
    func_80059D18(rdram, ctx);
        goto after_20;
    // 0x800A9164: addiu       $a1, $a1, 0x88
    ctx->r5 = ADD32(ctx->r5, 0X88);
    after_20:
    // 0x800A9168: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x800A916C: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800A9170: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x800A9174: sw          $zero, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = 0;
    // 0x800A9178: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A917C: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800A9180: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9184: lwc1        $f0, 0x53F8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X53F8);
    // 0x800A9188: lwc1        $f2, 0x80($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800A918C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800A9190: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800A9194: sw          $zero, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = 0;
    // 0x800A9198: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A919C: sw          $zero, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = 0;
    // 0x800A91A0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A91A4: lwc1        $f0, 0x53FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X53FC);
    // 0x800A91A8: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x800A91AC: swc1        $f6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f6.u32l;
    // 0x800A91B0: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    // 0x800A91B4: swc1        $f2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f2.u32l;
    // 0x800A91B8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800A91BC: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800A91C0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800A91C4: lw          $a0, 0xC($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XC);
    // 0x800A91C8: jal         0x8005E3B0
    // 0x800A91CC: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    func_8005E3B0(rdram, ctx);
        goto after_21;
    // 0x800A91CC: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    after_21:
    // 0x800A91D0: j           L_800A9324
    // 0x800A91D4: nop

        goto L_800A9324;
    // 0x800A91D4: nop

L_800A91D8:
    // 0x800A91D8: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x800A91DC: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // 0x800A91E0: bne         $v1, $v0, L_800A920C
    if (ctx->r3 != ctx->r2) {
        // 0x800A91E4: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_800A920C;
    }
    // 0x800A91E4: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x800A91E8: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800A91EC: add.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f4.fl;
    // 0x800A91F0: lwc1        $f2, 0x6C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A91F4: add.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800A91F8: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800A91FC: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800A9200: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
    // 0x800A9204: swc1        $f2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f2.u32l;
    // 0x800A9208: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
L_800A920C:
    // 0x800A920C: srl         $v0, $s3, 1
    ctx->r2 = S32(U32(ctx->r19) >> 1);
L_800A9210:
    // 0x800A9210: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A9214: addiu       $v1, $sp, 0x58
    ctx->r3 = ADD32(ctx->r29, 0X58);
    // 0x800A9218: addu        $s1, $v1, $v0
    ctx->r17 = ADD32(ctx->r3, ctx->r2);
    // 0x800A921C: andi        $s0, $s3, 0x1
    ctx->r16 = ctx->r19 & 0X1;
    // 0x800A9220: lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X8);
    // 0x800A9224: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800A9228: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A922C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A9230: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800A9234: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A9238: lw          $v1, 0x1900($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X1900);
    // 0x800A923C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A9240: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A9244: lw          $a0, 0x50($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X50);
    // 0x800A9248: jal         0x800AF2C8
    // 0x800A924C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_800AF2C8(rdram, ctx);
        goto after_22;
    // 0x800A924C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_22:
    // 0x800A9250: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800A9254: beql        $v0, $zero, L_800A9318
    if (ctx->r2 == 0) {
        // 0x800A9258: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_800A9318;
    }
    goto skip_3;
    // 0x800A9258: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_3:
    // 0x800A925C: lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X8);
    // 0x800A9260: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800A9264: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800A9268: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800A926C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800A9270: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800A9274: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9278: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A927C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800A9280: lw          $v0, 0x1900($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X1900);
    // 0x800A9284: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800A9288: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A928C: lw          $a0, 0x50($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X50);
    // 0x800A9290: jal         0x80058360
    // 0x800A9294: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    func_80058360(rdram, ctx);
        goto after_23;
    // 0x800A9294: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    after_23:
    // 0x800A9298: beql        $v0, $zero, L_800A9318
    if (ctx->r2 == 0) {
        // 0x800A929C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_800A9318;
    }
    goto skip_4;
    // 0x800A929C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_4:
    // 0x800A92A0: sw          $zero, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = 0;
    // 0x800A92A4: sw          $zero, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = 0;
    // 0x800A92A8: sw          $zero, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = 0;
    // 0x800A92AC: lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X8);
    // 0x800A92B0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A92B4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A92B8: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800A92BC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A92C0: lw          $v1, 0x1900($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X1900);
    // 0x800A92C4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A92C8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A92CC: lbu         $v1, 0x2($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X2);
    // 0x800A92D0: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x800A92D4: bne         $v1, $v0, L_800A92EC
    if (ctx->r3 != ctx->r2) {
        // 0x800A92D8: ori         $a1, $zero, 0xFFFF
        ctx->r5 = 0 | 0XFFFF;
            goto L_800A92EC;
    }
    // 0x800A92D8: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x800A92DC: swc1        $f28, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f28.u32l;
    // 0x800A92E0: jal         0x8001CF58
    // 0x800A92E4: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    normalize_vector(rdram, ctx);
        goto after_24;
    // 0x800A92E4: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    after_24:
    // 0x800A92E8: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
L_800A92EC:
    // 0x800A92EC: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x800A92F0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A92F4: lwc1        $f0, 0x5400($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5400);
    // 0x800A92F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800A92FC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800A9300: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800A9304: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800A9308: lw          $a0, 0xC($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XC);
    // 0x800A930C: jal         0x8005E3B0
    // 0x800A9310: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    func_8005E3B0(rdram, ctx);
        goto after_25;
    // 0x800A9310: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    after_25:
    // 0x800A9314: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800A9318:
    // 0x800A9318: sltiu       $v0, $s3, 0x8
    ctx->r2 = ctx->r19 < 0X8 ? 1 : 0;
    // 0x800A931C: bne         $v0, $zero, L_800A9210
    if (ctx->r2 != 0) {
        // 0x800A9320: srl         $v0, $s3, 1
        ctx->r2 = S32(U32(ctx->r19) >> 1);
            goto L_800A9210;
    }
    // 0x800A9320: srl         $v0, $s3, 1
    ctx->r2 = S32(U32(ctx->r19) >> 1);
L_800A9324:
    // 0x800A9324: lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X14);
    // 0x800A9328: beq         $v0, $zero, L_800A9528
    if (ctx->r2 == 0) {
        // 0x800A932C: addiu       $a1, $zero, 0x7F
        ctx->r5 = ADD32(0, 0X7F);
            goto L_800A9528;
    }
    // 0x800A932C: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x800A9330: lhu         $a0, 0x16($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X16);
    // 0x800A9334: jal         0x80087EE8
    // 0x800A9338: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80087EE8(rdram, ctx);
        goto after_26;
    // 0x800A9338: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_26:
    // 0x800A933C: j           L_800A952C
    // 0x800A9340: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
        goto L_800A952C;
    // 0x800A9340: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_800A9344:
    // 0x800A9344: lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X8);
    // 0x800A9348: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A934C: j           L_800A9528
    // 0x800A9350: sw          $v1, -0x944($v0)
    MEM_W(-0X944, ctx->r2) = ctx->r3;
        goto L_800A9528;
    // 0x800A9350: sw          $v1, -0x944($v0)
    MEM_W(-0X944, ctx->r2) = ctx->r3;
L_800A9354:
    // 0x800A9354: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x800A9358: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800A935C: j           L_800A9528
    // 0x800A9360: sb          $v0, 0xB1C($v1)
    MEM_B(0XB1C, ctx->r3) = ctx->r2;
        goto L_800A9528;
    // 0x800A9360: sb          $v0, 0xB1C($v1)
    MEM_B(0XB1C, ctx->r3) = ctx->r2;
L_800A9364:
    // 0x800A9364: lw          $v1, 0x10($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X10);
    // 0x800A9368: beq         $v1, $zero, L_800A952C
    if (ctx->r3 == 0) {
        // 0x800A936C: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_800A952C;
    }
    // 0x800A936C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800A9370: lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC);
    // 0x800A9374: lhu         $a0, 0xA($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0XA);
    // 0x800A9378: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800A937C: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x800A9380: bltzl       $v0, L_800A9388
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A9384: add.d       $f0, $f0, $f26
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f26.d); 
    ctx->f0.d = ctx->f0.d + ctx->f26.d;
            goto L_800A9388;
    }
    goto skip_5;
    // 0x800A9384: add.d       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f26.d); 
    ctx->f0.d = ctx->f0.d + ctx->f26.d;
    skip_5:
L_800A9388:
    // 0x800A9388: lw          $t0, 0x10C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10C);
    // 0x800A938C: addu        $v0, $t0, $v1
    ctx->r2 = ADD32(ctx->r8, ctx->r3);
    // 0x800A9390: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800A9394: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x800A9398: bgez        $v0, L_800A93A4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A939C: cvt.s.d     $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f6.fl = CVT_S_D(ctx->f0.d);
            goto L_800A93A4;
    }
    // 0x800A939C: cvt.s.d     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f6.fl = CVT_S_D(ctx->f0.d);
    // 0x800A93A0: add.d       $f4, $f4, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f26.d); 
    ctx->f4.d = ctx->f4.d + ctx->f26.d;
L_800A93A4:
    // 0x800A93A4: lwc1        $f0, 0x54($s7)
    ctx->f0.u32l = MEM_W(ctx->r23, 0X54);
    // 0x800A93A8: lwc1        $f2, 0x50($s7)
    ctx->f2.u32l = MEM_W(ctx->r23, 0X50);
    // 0x800A93AC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800A93B0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800A93B4: lw          $a2, 0x114($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X114);
    // 0x800A93B8: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x800A93BC: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800A93C0: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800A93C4: jal         0x800AEBD0
    // 0x800A93C8: nop

    func_800AEBD0(rdram, ctx);
        goto after_27;
    // 0x800A93C8: nop

    after_27:
    // 0x800A93CC: j           L_800A952C
    // 0x800A93D0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
        goto L_800A952C;
    // 0x800A93D0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_800A93D4:
    // 0x800A93D4: lui         $t1, 0x800B
    ctx->r9 = S32(0X800B << 16);
    // 0x800A93D8: lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X8);
    // 0x800A93DC: addiu       $t1, $t1, 0x1A20
    ctx->r9 = ADD32(ctx->r9, 0X1A20);
    // 0x800A93E0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A93E4: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800A93E8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800A93EC: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x800A93F0: beql        $a0, $s0, L_800A952C
    if (ctx->r4 == ctx->r16) {
        // 0x800A93F4: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_800A952C;
    }
    goto skip_6;
    // 0x800A93F4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    skip_6:
    // 0x800A93F8: jal         0x800894F0
    // 0x800A93FC: nop

    func_800894F0(rdram, ctx);
        goto after_28;
    // 0x800A93FC: nop

    after_28:
    // 0x800A9400: lui         $t2, 0x800B
    ctx->r10 = S32(0X800B << 16);
    // 0x800A9404: lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X8);
    // 0x800A9408: addiu       $t2, $t2, 0x1A20
    ctx->r10 = ADD32(ctx->r10, 0X1A20);
    // 0x800A940C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A9410: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x800A9414: j           L_800A9528
    // 0x800A9418: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
        goto L_800A9528;
    // 0x800A9418: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
L_800A941C:
    // 0x800A941C: lw          $a0, 0xC($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XC);
    // 0x800A9420: lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X8);
    // 0x800A9424: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x800A9428: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x800A942C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A9430: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A9434: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800A9438: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A943C: lw          $v1, 0x1900($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X1900);
    // 0x800A9440: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A9444: bgez        $a0, L_800A9450
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800A9448: addu        $v0, $v0, $v1
        ctx->r2 = ADD32(ctx->r2, ctx->r3);
            goto L_800A9450;
    }
    // 0x800A9448: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A944C: add.d       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f26.d); 
    ctx->f0.d = ctx->f0.d + ctx->f26.d;
L_800A9450:
    // 0x800A9450: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9454: lwc1        $f2, 0x5404($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5404);
    // 0x800A9458: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x800A945C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800A9460: j           L_800A9528
    // 0x800A9464: swc1        $f0, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f0.u32l;
        goto L_800A9528;
    // 0x800A9464: swc1        $f0, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f0.u32l;
L_800A9468:
    // 0x800A9468: lbu         $a0, 0xB($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0XB);
    // 0x800A946C: lhu         $a1, 0xE($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0XE);
    // 0x800A9470: jal         0x8008E0B0
    // 0x800A9474: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    func_8008E0B0(rdram, ctx);
        goto after_29;
    // 0x800A9474: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    after_29:
    // 0x800A9478: j           L_800A952C
    // 0x800A947C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
        goto L_800A952C;
    // 0x800A947C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_800A9480:
    // 0x800A9480: jal         0x800AAC88
    // 0x800A9484: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_800AAC88(rdram, ctx);
        goto after_30;
    // 0x800A9484: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_30:
    // 0x800A9488: j           L_800A952C
    // 0x800A948C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
        goto L_800A952C;
    // 0x800A948C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_800A9490:
    // 0x800A9490: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800A9494: lbu         $a0, 0xB($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0XB);
    // 0x800A9498: lbu         $a1, 0xF($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0XF);
    // 0x800A949C: jal         0x800AC75C
    // 0x800A94A0: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    func_800AC75C(rdram, ctx);
        goto after_31;
    // 0x800A94A0: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    after_31:
    // 0x800A94A4: j           L_800A952C
    // 0x800A94A8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
        goto L_800A952C;
    // 0x800A94A8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_800A94AC:
    // 0x800A94AC: lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X8);
    // 0x800A94B0: mtc1        $v0, $f12
    ctx->f12.u32l = ctx->r2;
    // 0x800A94B4: cvt.d.w     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.d = CVT_D_W(ctx->f12.u32l);
    // 0x800A94B8: bltzl       $v0, L_800A94C0
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A94BC: add.d       $f12, $f12, $f26
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f26.d); 
    ctx->f12.d = ctx->f12.d + ctx->f26.d;
            goto L_800A94C0;
    }
    goto skip_7;
    // 0x800A94BC: add.d       $f12, $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f26.d); 
    ctx->f12.d = ctx->f12.d + ctx->f26.d;
    skip_7:
L_800A94C0:
    // 0x800A94C0: lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC);
    // 0x800A94C4: mtc1        $v0, $f14
    ctx->f14.u32l = ctx->r2;
    // 0x800A94C8: cvt.d.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.d = CVT_D_W(ctx->f14.u32l);
    // 0x800A94CC: bgez        $v0, L_800A94D8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A94D0: cvt.s.d     $f12, $f12
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f12.fl = CVT_S_D(ctx->f12.d);
            goto L_800A94D8;
    }
    // 0x800A94D0: cvt.s.d     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f12.fl = CVT_S_D(ctx->f12.d);
    // 0x800A94D4: add.d       $f14, $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f26.d); 
    ctx->f14.d = ctx->f14.d + ctx->f26.d;
L_800A94D8:
    // 0x800A94D8: jal         0x800457B8
    // 0x800A94DC: cvt.s.d     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.d); 
    ctx->f14.fl = CVT_S_D(ctx->f14.d);
    func_800457B8(rdram, ctx);
        goto after_32;
    // 0x800A94DC: cvt.s.d     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.d); 
    ctx->f14.fl = CVT_S_D(ctx->f14.d);
    after_32:
    // 0x800A94E0: j           L_800A952C
    // 0x800A94E4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
        goto L_800A952C;
    // 0x800A94E4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_800A94E8:
    // 0x800A94E8: lhu         $v1, 0xA($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0XA);
    // 0x800A94EC: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A94F0: j           L_800A9528
    // 0x800A94F4: sh          $v1, 0xB22($v0)
    MEM_H(0XB22, ctx->r2) = ctx->r3;
        goto L_800A9528;
    // 0x800A94F4: sh          $v1, 0xB22($v0)
    MEM_H(0XB22, ctx->r2) = ctx->r3;
L_800A94F8:
    // 0x800A94F8: jal         0x800AF08C
    // 0x800A94FC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800AF08C(rdram, ctx);
        goto after_33;
    // 0x800A94FC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_33:
    // 0x800A9500: j           L_800A952C
    // 0x800A9504: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
        goto L_800A952C;
    // 0x800A9504: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_800A9508:
    // 0x800A9508: lhu         $v1, 0xA($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0XA);
    // 0x800A950C: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A9510: j           L_800A9528
    // 0x800A9514: sh          $v1, 0xB24($v0)
    MEM_H(0XB24, ctx->r2) = ctx->r3;
        goto L_800A9528;
    // 0x800A9514: sh          $v1, 0xB24($v0)
    MEM_H(0XB24, ctx->r2) = ctx->r3;
L_800A9518:
    // 0x800A9518: lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X8);
    // 0x800A951C: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x800A9520: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x800A9524: sb          $v0, 0xB14($v1)
    MEM_B(0XB14, ctx->r3) = ctx->r2;
L_800A9528:
    // 0x800A9528: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_800A952C:
    // 0x800A952C: lhu         $v0, 0xB20($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XB20);
    // 0x800A9530: lhu         $v1, 0x4E($s7)
    ctx->r3 = MEM_HU(ctx->r23, 0X4E);
    // 0x800A9534: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800A9538: sh          $v0, 0xB20($a0)
    MEM_H(0XB20, ctx->r4) = ctx->r2;
    // 0x800A953C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800A9540: beq         $v0, $v1, L_800A9550
    if (ctx->r2 == ctx->r3) {
        // 0x800A9544: sltiu       $v0, $v0, 0xC8
        ctx->r2 = ctx->r2 < 0XC8 ? 1 : 0;
            goto L_800A9550;
    }
    // 0x800A9544: sltiu       $v0, $v0, 0xC8
    ctx->r2 = ctx->r2 < 0XC8 ? 1 : 0;
    // 0x800A9548: bne         $v0, $zero, L_800A8A88
    if (ctx->r2 != 0) {
        // 0x800A954C: nop
    
            goto L_800A8A88;
    }
    // 0x800A954C: nop

L_800A9550:
    // 0x800A9550: lbu         $v0, 0xA9($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0XA9);
    // 0x800A9554: lw          $ra, 0xD4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XD4);
    // 0x800A9558: lw          $fp, 0xD0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XD0);
    // 0x800A955C: lw          $s7, 0xCC($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XCC);
    // 0x800A9560: lw          $s6, 0xC8($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XC8);
    // 0x800A9564: lw          $s5, 0xC4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XC4);
    // 0x800A9568: lw          $s4, 0xC0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XC0);
    // 0x800A956C: lw          $s3, 0xBC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XBC);
    // 0x800A9570: lw          $s2, 0xB8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XB8);
    // 0x800A9574: lw          $s1, 0xB4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XB4);
    // 0x800A9578: lw          $s0, 0xB0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XB0);
    // 0x800A957C: ldc1        $f30, 0x100($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X100);
    // 0x800A9580: ldc1        $f28, 0xF8($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0XF8);
    // 0x800A9584: ldc1        $f26, 0xF0($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0XF0);
    // 0x800A9588: ldc1        $f24, 0xE8($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0XE8);
    // 0x800A958C: ldc1        $f22, 0xE0($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XE0);
    // 0x800A9590: ldc1        $f20, 0xD8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XD8);
    // 0x800A9594: jr          $ra
    // 0x800A9598: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    return;
    // 0x800A9598: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void func_800A9270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9270: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A9274: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9278: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800A927C: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800A9280: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800A9284: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800A9288: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800A928C: lw          $v1, -0x25A4($s1)
    ctx->r3 = MEM_W(ctx->r17, -0X25A4);
    // 0x800A9290: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800A9294: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A9298: sll         $s0, $v0, 3
    ctx->r16 = S32(ctx->r2 << 3);
    // 0x800A929C: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800A92A0: addu        $v1, $s0, $v1
    ctx->r3 = ADD32(ctx->r16, ctx->r3);
    // 0x800A92A4: lhu         $a0, 0x40($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X40);
    // 0x800A92A8: andi        $v0, $a0, 0x8
    ctx->r2 = ctx->r4 & 0X8;
    // 0x800A92AC: bne         $v0, $zero, L_800A92F0
    if (ctx->r2 != 0) {
        // 0x800A92B0: srl         $v0, $a0, 4
        ctx->r2 = S32(U32(ctx->r4) >> 4);
            goto L_800A92F0;
    }
    // 0x800A92B0: srl         $v0, $a0, 4
    ctx->r2 = S32(U32(ctx->r4) >> 4);
    // 0x800A92B4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800A92B8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800A92BC: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    // 0x800A92C0: addiu       $a0, $a0, -0x2990
    ctx->r4 = ADD32(ctx->r4, -0X2990);
    // 0x800A92C4: lw          $a3, 0x0($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X0);
    // 0x800A92C8: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x800A92CC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800A92D0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800A92D4: addiu       $a2, $a3, 0x5C
    ctx->r6 = ADD32(ctx->r7, 0X5C);
    // 0x800A92D8: addiu       $a3, $a3, 0x68
    ctx->r7 = ADD32(ctx->r7, 0X68);
    // 0x800A92DC: jal         0x80065E98
    // 0x800A92E0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_80065E98(rdram, ctx);
        goto after_0;
    // 0x800A92E0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_0:
    // 0x800A92E4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800A92E8: beq         $v0, $zero, L_800A9344
    if (ctx->r2 == 0) {
        // 0x800A92EC: nop
    
            goto L_800A9344;
    }
    // 0x800A92EC: nop

L_800A92F0:
    // 0x800A92F0: lw          $v0, -0x25A4($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X25A4);
    // 0x800A92F4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800A92F8: addu        $a0, $s0, $v0
    ctx->r4 = ADD32(ctx->r16, ctx->r2);
    // 0x800A92FC: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x800A9300: lw          $v0, -0x2990($a1)
    ctx->r2 = MEM_W(ctx->r5, -0X2990);
    // 0x800A9304: beq         $v0, $zero, L_800A931C
    if (ctx->r2 == 0) {
        // 0x800A9308: sw          $v0, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->r2;
            goto L_800A931C;
    }
    // 0x800A9308: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x800A930C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x800A9310: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800A9314: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800A9318: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800A931C:
    // 0x800A931C: lw          $v1, -0x25A4($s1)
    ctx->r3 = MEM_W(ctx->r17, -0X25A4);
    // 0x800A9320: addu        $v1, $s0, $v1
    ctx->r3 = ADD32(ctx->r16, ctx->r3);
    // 0x800A9324: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x800A9328: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800A932C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x800A9330: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800A9334: sw          $v0, -0x2990($a1)
    MEM_W(-0X2990, ctx->r5) = ctx->r2;
    // 0x800A9338: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800A933C: j           L_800A9350
    // 0x800A9340: sb          $v0, 0x271($v1)
    MEM_B(0X271, ctx->r3) = ctx->r2;
        goto L_800A9350;
    // 0x800A9340: sb          $v0, 0x271($v1)
    MEM_B(0X271, ctx->r3) = ctx->r2;
L_800A9344:
    // 0x800A9344: lw          $v0, -0x25A4($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X25A4);
    // 0x800A9348: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800A934C: sb          $zero, 0x271($v0)
    MEM_B(0X271, ctx->r2) = 0;
L_800A9350:
    // 0x800A9350: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800A9354: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800A9358: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A935C: jr          $ra
    // 0x800A9360: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800A9360: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void hangarInitialize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9364: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A9368: lw          $v0, 0xB58($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB58);
    // 0x800A936C: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x800A9370: sw          $s3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r19;
    // 0x800A9374: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x800A9378: sw          $s0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r16;
    // 0x800A937C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800A9380: sw          $s1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r17;
    // 0x800A9384: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800A9388: sw          $fp, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r30;
    // 0x800A938C: sw          $ra, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r31;
    // 0x800A9390: sw          $s7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r23;
    // 0x800A9394: sw          $s6, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r22;
    // 0x800A9398: sw          $s5, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r21;
    // 0x800A939C: sw          $s4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r20;
    // 0x800A93A0: sw          $s2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r18;
    // 0x800A93A4: sdc1        $f20, 0xD0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XD0, ctx->r29);
    // 0x800A93A8: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800A93AC: beq         $v0, $zero, L_800A93DC
    if (ctx->r2 == 0) {
        // 0x800A93B0: addu        $fp, $a3, $zero
        ctx->r30 = ADD32(ctx->r7, 0);
            goto L_800A93DC;
    }
    // 0x800A93B0: addu        $fp, $a3, $zero
    ctx->r30 = ADD32(ctx->r7, 0);
    // 0x800A93B4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800A93B8: addiu       $v1, $v1, -0x3AD4
    ctx->r3 = ADD32(ctx->r3, -0X3AD4);
    // 0x800A93BC: lwc1        $f2, 0xC($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800A93C0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A93C4: lwc1        $f0, 0x5598($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5598);
    // 0x800A93C8: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800A93CC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800A93D0: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x800A93D4: sb          $v0, -0x3ADB($a0)
    MEM_B(-0X3ADB, ctx->r4) = ctx->r2;
    // 0x800A93D8: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
L_800A93DC:
    // 0x800A93DC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800A93E0: sb          $zero, -0x25F0($v0)
    MEM_B(-0X25F0, ctx->r2) = 0;
    // 0x800A93E4: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800A93E8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800A93EC: addiu       $v1, $v0, -0x25F8
    ctx->r3 = ADD32(ctx->r2, -0X25F8);
    // 0x800A93F0: addu        $v0, $s2, $v1
    ctx->r2 = ADD32(ctx->r18, ctx->r3);
L_800A93F4:
    // 0x800A93F4: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x800A93F8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800A93FC: sltiu       $v0, $s2, 0x8
    ctx->r2 = ctx->r18 < 0X8 ? 1 : 0;
    // 0x800A9400: bne         $v0, $zero, L_800A93F4
    if (ctx->r2 != 0) {
        // 0x800A9404: addu        $v0, $s2, $v1
        ctx->r2 = ADD32(ctx->r18, ctx->r3);
            goto L_800A93F4;
    }
    // 0x800A9404: addu        $v0, $s2, $v1
    ctx->r2 = ADD32(ctx->r18, ctx->r3);
    // 0x800A9408: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A940C: lbu         $a1, 0xB62($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0XB62);
    // 0x800A9410: jal         0x80066A90
    // 0x800A9414: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80066A90(rdram, ctx);
        goto after_0;
    // 0x800A9414: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // 0x800A9418: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800A941C: sw          $zero, -0x25E8($v0)
    MEM_W(-0X25E8, ctx->r2) = 0;
    // 0x800A9420: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800A9424: sb          $s0, -0x2930($v0)
    MEM_B(-0X2930, ctx->r2) = ctx->r16;
    // 0x800A9428: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800A942C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800A9430: sw          $s3, -0x2928($v0)
    MEM_W(-0X2928, ctx->r2) = ctx->r19;
    // 0x800A9434: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800A9438: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    // 0x800A943C: sb          $zero, -0x2A00($v0)
    MEM_B(-0X2A00, ctx->r2) = 0;
    // 0x800A9440: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800A9444: bne         $a1, $v0, L_800A9450
    if (ctx->r5 != ctx->r2) {
        // 0x800A9448: sb          $zero, -0x291C($v1)
        MEM_B(-0X291C, ctx->r3) = 0;
            goto L_800A9450;
    }
    // 0x800A9448: sb          $zero, -0x291C($v1)
    MEM_B(-0X291C, ctx->r3) = 0;
    // 0x800A944C: sb          $zero, -0x291C($v1)
    MEM_B(-0X291C, ctx->r3) = 0;
L_800A9450:
    // 0x800A9450: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800A9454: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800A9458: addiu       $v1, $v0, -0x3C08
    ctx->r3 = ADD32(ctx->r2, -0X3C08);
    // 0x800A945C: addiu       $a2, $s2, 0x1
    ctx->r6 = ADD32(ctx->r18, 0X1);
L_800A9460:
    // 0x800A9460: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
    // 0x800A9464: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800A9468: beq         $v0, $a1, L_800AA228
    if (ctx->r2 == ctx->r5) {
        // 0x800A946C: addu        $s2, $a2, $zero
        ctx->r18 = ADD32(ctx->r6, 0);
            goto L_800AA228;
    }
    // 0x800A946C: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x800A9470: sltiu       $v0, $s2, 0x8
    ctx->r2 = ctx->r18 < 0X8 ? 1 : 0;
    // 0x800A9474: bnel        $v0, $zero, L_800A9460
    if (ctx->r2 != 0) {
        // 0x800A9478: addiu       $a2, $s2, 0x1
        ctx->r6 = ADD32(ctx->r18, 0X1);
            goto L_800A9460;
    }
    goto skip_0;
    // 0x800A9478: addiu       $a2, $s2, 0x1
    ctx->r6 = ADD32(ctx->r18, 0X1);
    skip_0:
L_800A947C:
    // 0x800A947C: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800A9480: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800A9484: addiu       $a0, $v0, -0x3BFC
    ctx->r4 = ADD32(ctx->r2, -0X3BFC);
    // 0x800A9488: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800A948C: lbu         $v1, -0x291C($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X291C);
    // 0x800A9490: addu        $v0, $s2, $a0
    ctx->r2 = ADD32(ctx->r18, ctx->r4);
L_800A9494:
    // 0x800A9494: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800A9498: beq         $v0, $v1, L_800AA218
    if (ctx->r2 == ctx->r3) {
        // 0x800A949C: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800AA218;
    }
    // 0x800A949C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800A94A0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800A94A4: sltiu       $v0, $s2, 0x8
    ctx->r2 = ctx->r18 < 0X8 ? 1 : 0;
    // 0x800A94A8: bne         $v0, $zero, L_800A9494
    if (ctx->r2 != 0) {
        // 0x800A94AC: addu        $v0, $s2, $a0
        ctx->r2 = ADD32(ctx->r18, ctx->r4);
            goto L_800A9494;
    }
    // 0x800A94AC: addu        $v0, $s2, $a0
    ctx->r2 = ADD32(ctx->r18, ctx->r4);
L_800A94B0:
    // 0x800A94B0: andi        $s0, $fp, 0xFF
    ctx->r16 = ctx->r30 & 0XFF;
    // 0x800A94B4: jal         0x800C6234
    // 0x800A94B8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    getAvailablePlayerCraftFlagsConsiderUnlocks(rdram, ctx);
        goto after_1;
    // 0x800A94B8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800A94BC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800A94C0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800A94C4: srl         $v0, $v0, 5
    ctx->r2 = S32(U32(ctx->r2) >> 5);
    // 0x800A94C8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800A94CC: jal         0x800C6234
    // 0x800A94D0: sb          $v0, -0x2933($v1)
    MEM_B(-0X2933, ctx->r3) = ctx->r2;
    getAvailablePlayerCraftFlagsConsiderUnlocks(rdram, ctx);
        goto after_2;
    // 0x800A94D0: sb          $v0, -0x2933($v1)
    MEM_B(-0X2933, ctx->r3) = ctx->r2;
    after_2:
    // 0x800A94D4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800A94D8: srl         $v0, $v0, 6
    ctx->r2 = S32(U32(ctx->r2) >> 6);
    // 0x800A94DC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800A94E0: sb          $v0, -0x2932($v1)
    MEM_B(-0X2932, ctx->r3) = ctx->r2;
    // 0x800A94E4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A94E8: lw          $v0, 0xB68($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB68);
    // 0x800A94EC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800A94F0: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x800A94F4: beq         $v0, $zero, L_800A9528
    if (ctx->r2 == 0) {
        // 0x800A94F8: sb          $v0, -0x2931($v1)
        MEM_B(-0X2931, ctx->r3) = ctx->r2;
            goto L_800A9528;
    }
    // 0x800A94F8: sb          $v0, -0x2931($v1)
    MEM_B(-0X2931, ctx->r3) = ctx->r2;
    // 0x800A94FC: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800A9500: addiu       $v1, $v1, -0x13B0
    ctx->r3 = ADD32(ctx->r3, -0X13B0);
    // 0x800A9504: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x800A9508: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A950C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800A9510: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800A9514: beq         $v1, $v0, L_800A9528
    if (ctx->r3 == ctx->r2) {
        // 0x800A9518: lui         $v1, 0x800D
        ctx->r3 = S32(0X800D << 16);
            goto L_800A9528;
    }
    // 0x800A9518: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800A951C: lw          $v0, -0x2928($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2928);
    // 0x800A9520: ori         $v0, $v0, 0x100
    ctx->r2 = ctx->r2 | 0X100;
    // 0x800A9524: sw          $v0, -0x2928($v1)
    MEM_W(-0X2928, ctx->r3) = ctx->r2;
L_800A9528:
    // 0x800A9528: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800A952C: addiu       $v1, $v1, -0x2990
    ctx->r3 = ADD32(ctx->r3, -0X2990);
    // 0x800A9530: addiu       $a0, $v1, 0x2C
    ctx->r4 = ADD32(ctx->r3, 0X2C);
    // 0x800A9534: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800A9538: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A953C: lwc1        $f0, 0x559C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X559C);
    // 0x800A9540: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9544: lwc1        $f2, 0x55A0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X55A0);
    // 0x800A9548: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A954C: lwc1        $f4, 0x55A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X55A4);
    // 0x800A9550: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9554: lwc1        $f6, 0x55A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X55A8);
    // 0x800A9558: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800A955C: sw          $zero, -0x7764($v0)
    MEM_W(-0X7764, ctx->r2) = 0;
    // 0x800A9560: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800A9564: sw          $zero, -0x29F8($v0)
    MEM_W(-0X29F8, ctx->r2) = 0;
    // 0x800A9568: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // 0x800A956C: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x800A9570: addiu       $v0, $zero, 0x154
    ctx->r2 = ADD32(0, 0X154);
    // 0x800A9574: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x800A9578: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // 0x800A957C: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x800A9580: addiu       $v0, $zero, 0xAA
    ctx->r2 = ADD32(0, 0XAA);
    // 0x800A9584: sw          $v0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r2;
    // 0x800A9588: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800A958C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800A9590: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x800A9594: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x800A9598: swc1        $f0, -0x2920($v0)
    MEM_W(-0X2920, ctx->r2) = ctx->f0.u32l;
    // 0x800A959C: swc1        $f2, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f2.u32l;
    // 0x800A95A0: swc1        $f4, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f4.u32l;
    // 0x800A95A4: jal         0x8001CA50
    // 0x800A95A8: swc1        $f6, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f6.u32l;
    func_8001CA50(rdram, ctx);
        goto after_3;
    // 0x800A95A8: swc1        $f6, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f6.u32l;
    after_3:
    // 0x800A95AC: jal         0x80017AB0
    // 0x800A95B0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_80017AB0(rdram, ctx);
        goto after_4;
    // 0x800A95B0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_4:
    // 0x800A95B4: jal         0x8000E0BC
    // 0x800A95B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8000E0BC(rdram, ctx);
        goto after_5;
    // 0x800A95B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x800A95BC: jal         0x8000E0E0
    // 0x800A95C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8000E0E0(rdram, ctx);
        goto after_6;
    // 0x800A95C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x800A95C4: jal         0x800645CC
    // 0x800A95C8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800645CC(rdram, ctx);
        goto after_7;
    // 0x800A95C8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_7:
    // 0x800A95CC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800A95D0: addiu       $v1, $v1, -0x29F0
    ctx->r3 = ADD32(ctx->r3, -0X29F0);
    // 0x800A95D4: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x800A95D8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800A95DC: sw          $v0, -0x2998($v1)
    MEM_W(-0X2998, ctx->r3) = ctx->r2;
    // 0x800A95E0: beq         $s2, $zero, L_800A95F0
    if (ctx->r18 == 0) {
        // 0x800A95E4: addiu       $v0, $a0, -0x58
        ctx->r2 = ADD32(ctx->r4, -0X58);
            goto L_800A95F0;
    }
    // 0x800A95E4: addiu       $v0, $a0, -0x58
    ctx->r2 = ADD32(ctx->r4, -0X58);
    // 0x800A95E8: j           L_800A95F4
    // 0x800A95EC: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
        goto L_800A95F4;
    // 0x800A95EC: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_800A95F0:
    // 0x800A95F0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_800A95F4:
    // 0x800A95F4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800A95F8: sb          $zero, 0x8($a0)
    MEM_B(0X8, ctx->r4) = 0;
    // 0x800A95FC: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800A9600: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x800A9604: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800A9608: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x800A960C: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x800A9610: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x800A9614: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x800A9618: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x800A961C: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x800A9620: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // 0x800A9624: sw          $zero, 0x34($a0)
    MEM_W(0X34, ctx->r4) = 0;
    // 0x800A9628: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800A962C: beq         $s2, $zero, L_800A95F0
    if (ctx->r18 == 0) {
        // 0x800A9630: addiu       $a0, $a0, 0x58
        ctx->r4 = ADD32(ctx->r4, 0X58);
            goto L_800A95F0;
    }
    // 0x800A9630: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    // 0x800A9634: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A9638: addiu       $a0, $a0, 0x51FC
    ctx->r4 = ADD32(ctx->r4, 0X51FC);
    // 0x800A963C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800A9640: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9644: lwc1        $f0, 0x55AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X55AC);
    // 0x800A9648: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A964C: lwc1        $f2, 0x55B0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X55B0);
    // 0x800A9650: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9654: lwc1        $f4, 0x55B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X55B4);
    // 0x800A9658: addiu       $v0, $v0, -0x29F0
    ctx->r2 = ADD32(ctx->r2, -0X29F0);
    // 0x800A965C: sb          $zero, 0x8($v0)
    MEM_B(0X8, ctx->r2) = 0;
    // 0x800A9660: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x800A9664: swc1        $f2, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f2.u32l;
    // 0x800A9668: jal         0x80046784
    // 0x800A966C: swc1        $f4, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f4.u32l;
    loadDatFile(rdram, ctx);
        goto after_8;
    // 0x800A966C: swc1        $f4, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f4.u32l;
    after_8:
    // 0x800A9670: ori         $a0, $zero, 0x8A40
    ctx->r4 = 0 | 0X8A40;
    // 0x800A9674: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800A9678: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800A967C: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800A9680: sw          $v0, -0x3A74($v1)
    MEM_W(-0X3A74, ctx->r3) = ctx->r2;
    // 0x800A9684: jal         0x80001ACC
    // 0x800A9688: sh          $zero, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = 0;
    rs_malloc(rdram, ctx);
        goto after_9;
    // 0x800A9688: sh          $zero, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = 0;
    after_9:
    // 0x800A968C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800A9690: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800A9694: sw          $v0, -0x25A4($v1)
    MEM_W(-0X25A4, ctx->r3) = ctx->r2;
    // 0x800A9698: addiu       $v1, $zero, 0x30
    ctx->r3 = ADD32(0, 0X30);
    // 0x800A969C: sh          $v1, -0x25BE($a0)
    MEM_H(-0X25BE, ctx->r4) = ctx->r3;
    // 0x800A96A0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800A96A4: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800A96A8: lhu         $a0, -0x25C0($s0)
    ctx->r4 = MEM_HU(ctx->r16, -0X25C0);
    // 0x800A96AC: lhu         $a1, -0x25C0($s0)
    ctx->r5 = MEM_HU(ctx->r16, -0X25C0);
    // 0x800A96B0: addiu       $a3, $zero, 0x621
    ctx->r7 = ADD32(0, 0X621);
    // 0x800A96B4: sh          $a0, -0x25B0($v1)
    MEM_H(-0X25B0, ctx->r3) = ctx->r4;
    // 0x800A96B8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A96BC: addiu       $a0, $a0, 0x520C
    ctx->r4 = ADD32(ctx->r4, 0X520C);
    // 0x800A96C0: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x800A96C4: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800A96C8: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A96CC: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x800A96D0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A96D4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A96D8: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x800A96DC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x800A96E0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A96E4: sh          $a1, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r5;
    // 0x800A96E8: sh          $a1, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r5;
    // 0x800A96EC: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A96F0: sh          $a0, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r4;
    // 0x800A96F4: lhu         $a0, -0x25C0($s0)
    ctx->r4 = MEM_HU(ctx->r16, -0X25C0);
    // 0x800A96F8: addiu       $a1, $a1, 0x5214
    ctx->r5 = ADD32(ctx->r5, 0X5214);
    // 0x800A96FC: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9700: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9704: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9708: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A970C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9710: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9714: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9718: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A971C: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9720: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800A9724: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9728: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A972C: sh          $a0, -0x25A8($v1)
    MEM_H(-0X25A8, ctx->r3) = ctx->r4;
    // 0x800A9730: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9734: addiu       $a1, $a1, 0x5224
    ctx->r5 = ADD32(ctx->r5, 0X5224);
    // 0x800A9738: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A973C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9740: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9744: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9748: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A974C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9750: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9754: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9758: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A975C: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9760: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9764: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9768: addiu       $a1, $a1, 0x522C
    ctx->r5 = ADD32(ctx->r5, 0X522C);
    // 0x800A976C: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9770: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9774: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9778: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A977C: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9780: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9784: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9788: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A978C: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9790: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9794: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9798: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A979C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A97A0: addiu       $a1, $a1, 0x5234
    ctx->r5 = ADD32(ctx->r5, 0X5234);
    // 0x800A97A4: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A97A8: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A97AC: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A97B0: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A97B4: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A97B8: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A97BC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A97C0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A97C4: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A97C8: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A97CC: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A97D0: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A97D4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A97D8: addiu       $a1, $a1, 0x523C
    ctx->r5 = ADD32(ctx->r5, 0X523C);
    // 0x800A97DC: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A97E0: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A97E4: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A97E8: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A97EC: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A97F0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A97F4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A97F8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A97FC: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9800: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9804: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9808: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A980C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A9810: lhu         $a1, -0x25C0($s0)
    ctx->r5 = MEM_HU(ctx->r16, -0X25C0);
    // 0x800A9814: addiu       $a0, $a0, 0x5244
    ctx->r4 = ADD32(ctx->r4, 0X5244);
    // 0x800A9818: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x800A981C: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800A9820: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9824: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x800A9828: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A982C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9830: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x800A9834: addiu       $a0, $zero, 0x221
    ctx->r4 = ADD32(0, 0X221);
    // 0x800A9838: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A983C: sh          $a0, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r4;
    // 0x800A9840: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800A9844: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A9848: sh          $a1, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r5;
    // 0x800A984C: sh          $a1, -0x25AE($v1)
    MEM_H(-0X25AE, ctx->r3) = ctx->r5;
    // 0x800A9850: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800A9854: addiu       $a0, $a0, 0x524C
    ctx->r4 = ADD32(ctx->r4, 0X524C);
    // 0x800A9858: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x800A985C: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800A9860: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9864: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x800A9868: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A986C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9870: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x800A9874: addiu       $a0, $zero, 0x421
    ctx->r4 = ADD32(0, 0X421);
    // 0x800A9878: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A987C: sh          $a0, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r4;
    // 0x800A9880: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800A9884: sh          $a1, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r5;
    // 0x800A9888: sh          $a1, -0x25AA($v1)
    MEM_H(-0X25AA, ctx->r3) = ctx->r5;
    // 0x800A988C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9890: lhu         $a0, -0x25C0($s0)
    ctx->r4 = MEM_HU(ctx->r16, -0X25C0);
    // 0x800A9894: addiu       $a1, $a1, 0x5258
    ctx->r5 = ADD32(ctx->r5, 0X5258);
    // 0x800A9898: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A989C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A98A0: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A98A4: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A98A8: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A98AC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A98B0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A98B4: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A98B8: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A98BC: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A98C0: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A98C4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A98C8: addiu       $a1, $a1, 0x5264
    ctx->r5 = ADD32(ctx->r5, 0X5264);
    // 0x800A98CC: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A98D0: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A98D4: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A98D8: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A98DC: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A98E0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A98E4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A98E8: addiu       $a3, $zero, 0x180
    ctx->r7 = ADD32(0, 0X180);
    // 0x800A98EC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A98F0: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A98F4: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A98F8: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A98FC: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9900: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9904: addiu       $a1, $a1, 0x526C
    ctx->r5 = ADD32(ctx->r5, 0X526C);
    // 0x800A9908: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A990C: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9910: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9914: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9918: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A991C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9920: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9924: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9928: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A992C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9930: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9934: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9938: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A993C: addiu       $a1, $a1, 0x5274
    ctx->r5 = ADD32(ctx->r5, 0X5274);
    // 0x800A9940: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9944: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9948: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A994C: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9950: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9954: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9958: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A995C: addiu       $a3, $zero, 0x1080
    ctx->r7 = ADD32(0, 0X1080);
    // 0x800A9960: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9964: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9968: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A996C: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9970: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9974: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9978: addiu       $a1, $a1, 0x5280
    ctx->r5 = ADD32(ctx->r5, 0X5280);
    // 0x800A997C: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9980: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9984: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9988: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A998C: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9990: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9994: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9998: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A999C: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A99A0: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A99A4: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A99A8: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A99AC: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A99B0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A99B4: addiu       $a1, $a1, 0x528C
    ctx->r5 = ADD32(ctx->r5, 0X528C);
    // 0x800A99B8: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A99BC: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A99C0: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A99C4: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A99C8: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A99CC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A99D0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A99D4: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A99D8: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A99DC: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A99E0: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A99E4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A99E8: addiu       $a1, $a1, 0x5298
    ctx->r5 = ADD32(ctx->r5, 0X5298);
    // 0x800A99EC: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A99F0: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A99F4: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A99F8: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A99FC: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9A00: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9A04: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9A08: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9A0C: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9A10: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9A14: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9A18: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9A1C: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9A20: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9A24: addiu       $a1, $a1, 0x52A4
    ctx->r5 = ADD32(ctx->r5, 0X52A4);
    // 0x800A9A28: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9A2C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9A30: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9A34: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9A38: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9A3C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9A40: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9A44: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9A48: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9A4C: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9A50: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9A54: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9A58: addiu       $a1, $a1, 0x52B0
    ctx->r5 = ADD32(ctx->r5, 0X52B0);
    // 0x800A9A5C: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9A60: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9A64: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9A68: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9A6C: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9A70: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9A74: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9A78: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9A7C: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9A80: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9A84: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9A88: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9A8C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9A90: addiu       $a1, $a1, 0x52BC
    ctx->r5 = ADD32(ctx->r5, 0X52BC);
    // 0x800A9A94: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9A98: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9A9C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9AA0: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9AA4: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9AA8: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9AAC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9AB0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9AB4: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9AB8: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9ABC: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9AC0: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9AC4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9AC8: addiu       $a1, $a1, 0x52C8
    ctx->r5 = ADD32(ctx->r5, 0X52C8);
    // 0x800A9ACC: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9AD0: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9AD4: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9AD8: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9ADC: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9AE0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9AE4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9AE8: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    // 0x800A9AEC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9AF0: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9AF4: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9AF8: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9AFC: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9B00: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9B04: addiu       $a1, $a1, 0x52D4
    ctx->r5 = ADD32(ctx->r5, 0X52D4);
    // 0x800A9B08: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9B0C: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9B10: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9B14: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9B18: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9B1C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9B20: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9B24: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9B28: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9B2C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9B30: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9B34: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9B38: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9B3C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9B40: addiu       $a1, $a1, 0x52E0
    ctx->r5 = ADD32(ctx->r5, 0X52E0);
    // 0x800A9B44: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9B48: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9B4C: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9B50: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9B54: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9B58: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9B5C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9B60: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9B64: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9B68: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9B6C: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9B70: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9B74: addiu       $a1, $a1, 0x52EC
    ctx->r5 = ADD32(ctx->r5, 0X52EC);
    // 0x800A9B78: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9B7C: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9B80: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9B84: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9B88: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9B8C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9B90: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9B94: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9B98: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9B9C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9BA0: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9BA4: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9BA8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9BAC: addiu       $a1, $a1, 0x52F8
    ctx->r5 = ADD32(ctx->r5, 0X52F8);
    // 0x800A9BB0: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9BB4: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9BB8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9BBC: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9BC0: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9BC4: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9BC8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9BCC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9BD0: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9BD4: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9BD8: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9BDC: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9BE0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9BE4: addiu       $a1, $a1, 0x5304
    ctx->r5 = ADD32(ctx->r5, 0X5304);
    // 0x800A9BE8: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9BEC: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9BF0: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9BF4: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9BF8: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9BFC: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9C00: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9C04: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800A9C08: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9C0C: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9C10: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9C14: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9C18: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9C1C: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9C20: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9C24: addiu       $a1, $a1, 0x5310
    ctx->r5 = ADD32(ctx->r5, 0X5310);
    // 0x800A9C28: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9C2C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9C30: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9C34: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9C38: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9C3C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9C40: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9C44: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9C48: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9C4C: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9C50: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9C54: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9C58: addiu       $a1, $a1, 0x531C
    ctx->r5 = ADD32(ctx->r5, 0X531C);
    // 0x800A9C5C: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9C60: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9C64: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9C68: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9C6C: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9C70: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9C74: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9C78: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9C7C: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9C80: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9C84: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9C88: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9C8C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9C90: addiu       $a1, $a1, 0x5328
    ctx->r5 = ADD32(ctx->r5, 0X5328);
    // 0x800A9C94: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9C98: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9C9C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9CA0: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9CA4: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9CA8: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9CAC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9CB0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9CB4: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9CB8: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9CBC: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9CC0: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9CC4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9CC8: addiu       $a1, $a1, 0x5334
    ctx->r5 = ADD32(ctx->r5, 0X5334);
    // 0x800A9CCC: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9CD0: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9CD4: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9CD8: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9CDC: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9CE0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9CE4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9CE8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9CEC: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9CF0: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9CF4: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9CF8: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9CFC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9D00: addiu       $a1, $a1, 0x5340
    ctx->r5 = ADD32(ctx->r5, 0X5340);
    // 0x800A9D04: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9D08: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9D0C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9D10: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9D14: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9D18: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9D1C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9D20: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9D24: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9D28: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9D2C: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9D30: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9D34: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9D38: addiu       $a1, $a1, 0x534C
    ctx->r5 = ADD32(ctx->r5, 0X534C);
    // 0x800A9D3C: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9D40: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9D44: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9D48: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9D4C: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9D50: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9D54: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9D58: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9D5C: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9D60: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9D64: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9D68: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9D6C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9D70: addiu       $a1, $a1, 0x535C
    ctx->r5 = ADD32(ctx->r5, 0X535C);
    // 0x800A9D74: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9D78: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9D7C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9D80: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9D84: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9D88: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9D8C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9D90: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9D94: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9D98: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9D9C: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9DA0: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9DA4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9DA8: addiu       $a1, $a1, 0x536C
    ctx->r5 = ADD32(ctx->r5, 0X536C);
    // 0x800A9DAC: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9DB0: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9DB4: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9DB8: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9DBC: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9DC0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9DC4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9DC8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9DCC: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9DD0: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9DD4: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9DD8: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9DDC: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9DE0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9DE4: addiu       $a1, $a1, 0x537C
    ctx->r5 = ADD32(ctx->r5, 0X537C);
    // 0x800A9DE8: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9DEC: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9DF0: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9DF4: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9DF8: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9DFC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9E00: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9E04: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9E08: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9E0C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800A9E10: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9E14: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9E18: sh          $a0, -0x25B8($v1)
    MEM_H(-0X25B8, ctx->r3) = ctx->r4;
    // 0x800A9E1C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9E20: addiu       $a1, $a1, 0x538C
    ctx->r5 = ADD32(ctx->r5, 0X538C);
    // 0x800A9E24: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9E28: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9E2C: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9E30: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9E34: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9E38: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9E3C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9E40: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9E44: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9E48: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9E4C: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9E50: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9E54: addiu       $a1, $a1, 0x5394
    ctx->r5 = ADD32(ctx->r5, 0X5394);
    // 0x800A9E58: sh          $zero, 0x40($v1)
    MEM_H(0X40, ctx->r3) = 0;
    // 0x800A9E5C: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9E60: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9E64: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9E68: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9E6C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9E70: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9E74: addiu       $a3, $zero, 0x16
    ctx->r7 = ADD32(0, 0X16);
    // 0x800A9E78: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9E7C: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9E80: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9E84: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9E88: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9E8C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9E90: addiu       $a1, $a1, 0x53A0
    ctx->r5 = ADD32(ctx->r5, 0X53A0);
    // 0x800A9E94: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9E98: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9E9C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9EA0: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9EA4: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9EA8: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9EAC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9EB0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9EB4: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9EB8: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9EBC: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9EC0: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9EC4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9EC8: addiu       $a1, $a1, 0x53AC
    ctx->r5 = ADD32(ctx->r5, 0X53AC);
    // 0x800A9ECC: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9ED0: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9ED4: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9ED8: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9EDC: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9EE0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9EE4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9EE8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9EEC: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9EF0: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9EF4: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9EF8: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9EFC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9F00: addiu       $a1, $a1, 0x53B8
    ctx->r5 = ADD32(ctx->r5, 0X53B8);
    // 0x800A9F04: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9F08: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9F0C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9F10: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9F14: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9F18: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9F1C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9F20: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9F24: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9F28: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9F2C: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9F30: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9F34: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9F38: addiu       $a1, $a1, 0x53C4
    ctx->r5 = ADD32(ctx->r5, 0X53C4);
    // 0x800A9F3C: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9F40: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9F44: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9F48: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9F4C: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9F50: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9F54: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9F58: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9F5C: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9F60: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9F64: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9F68: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9F6C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9F70: addiu       $a1, $a1, 0x53D0
    ctx->r5 = ADD32(ctx->r5, 0X53D0);
    // 0x800A9F74: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9F78: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9F7C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9F80: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9F84: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9F88: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9F8C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9F90: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    // 0x800A9F94: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9F98: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9F9C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9FA0: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9FA4: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9FA8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9FAC: addiu       $a1, $a1, 0x53E0
    ctx->r5 = ADD32(ctx->r5, 0X53E0);
    // 0x800A9FB0: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9FB4: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9FB8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9FBC: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9FC0: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9FC4: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800A9FC8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9FCC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A9FD0: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800A9FD4: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A9FD8: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800A9FDC: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800A9FE0: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800A9FE4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800A9FE8: addiu       $a1, $a1, 0x53EC
    ctx->r5 = ADD32(ctx->r5, 0X53EC);
    // 0x800A9FEC: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800A9FF0: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800A9FF4: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800A9FF8: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800A9FFC: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800AA000: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800AA004: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800AA008: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800AA00C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800AA010: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800AA014: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800AA018: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800AA01C: addiu       $a1, $a1, 0x53F8
    ctx->r5 = ADD32(ctx->r5, 0X53F8);
    // 0x800AA020: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800AA024: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800AA028: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800AA02C: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800AA030: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800AA034: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800AA038: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800AA03C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800AA040: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800AA044: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800AA048: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800AA04C: sh          $a0, -0x25BA($a2)
    MEM_H(-0X25BA, ctx->r6) = ctx->r4;
    // 0x800AA050: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800AA054: addiu       $a1, $a1, 0x5404
    ctx->r5 = ADD32(ctx->r5, 0X5404);
    // 0x800AA058: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800AA05C: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800AA060: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800AA064: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800AA068: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800AA06C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800AA070: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800AA074: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800AA078: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800AA07C: sh          $a3, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r7;
    // 0x800AA080: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AA084: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800AA088: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800AA08C: sh          $a0, -0x25B6($v1)
    MEM_H(-0X25B6, ctx->r3) = ctx->r4;
    // 0x800AA090: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800AA094: addiu       $a1, $a1, 0x5410
    ctx->r5 = ADD32(ctx->r5, 0X5410);
    // 0x800AA098: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800AA09C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800AA0A0: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800AA0A4: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800AA0A8: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800AA0AC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800AA0B0: addiu       $a2, $zero, 0x820
    ctx->r6 = ADD32(0, 0X820);
    // 0x800AA0B4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800AA0B8: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800AA0BC: sh          $a2, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r6;
    // 0x800AA0C0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AA0C4: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800AA0C8: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800AA0CC: sh          $a0, -0x25B4($v1)
    MEM_H(-0X25B4, ctx->r3) = ctx->r4;
    // 0x800AA0D0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800AA0D4: addiu       $a1, $a1, 0x5420
    ctx->r5 = ADD32(ctx->r5, 0X5420);
    // 0x800AA0D8: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800AA0DC: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800AA0E0: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800AA0E4: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800AA0E8: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800AA0EC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800AA0F0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800AA0F4: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800AA0F8: sh          $a2, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r6;
    // 0x800AA0FC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AA100: sh          $a0, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r4;
    // 0x800AA104: sh          $a0, -0x25B2($v1)
    MEM_H(-0X25B2, ctx->r3) = ctx->r4;
    // 0x800AA108: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800AA10C: lhu         $a1, -0x25C0($s0)
    ctx->r5 = MEM_HU(ctx->r16, -0X25C0);
    // 0x800AA110: addiu       $a0, $a0, 0x5430
    ctx->r4 = ADD32(ctx->r4, 0X5430);
    // 0x800AA114: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x800AA118: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800AA11C: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800AA120: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x800AA124: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800AA128: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800AA12C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x800AA130: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    // 0x800AA134: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800AA138: sh          $a0, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r4;
    // 0x800AA13C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800AA140: addiu       $a0, $a0, -0x3A64
    ctx->r4 = ADD32(ctx->r4, -0X3A64);
    // 0x800AA144: andi        $v1, $fp, 0xFF
    ctx->r3 = ctx->r30 & 0XFF;
    // 0x800AA148: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800AA14C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800AA150: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x800AA154: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AA158: sh          $a1, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r5;
    // 0x800AA15C: sh          $a1, -0x25AC($v1)
    MEM_H(-0X25AC, ctx->r3) = ctx->r5;
    // 0x800AA160: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800AA164: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800AA168: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x800AA16C: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800AA170: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800AA174: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x800AA178: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800AA17C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800AA180: addiu       $v0, $zero, 0x822
    ctx->r2 = ADD32(0, 0X822);
    // 0x800AA184: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800AA188: sh          $v0, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r2;
    // 0x800AA18C: sh          $a1, -0x25C0($s0)
    MEM_H(-0X25C0, ctx->r16) = ctx->r5;
    // 0x800AA190: jal         0x80054A18
    // 0x800AA194: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    func_80054A18(rdram, ctx);
        goto after_10;
    // 0x800AA194: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    after_10:
    // 0x800AA198: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800AA19C: jal         0x800543F4
    // 0x800AA1A0: addiu       $a0, $a0, 0x5438
    ctx->r4 = ADD32(ctx->r4, 0X5438);
    load_full_header_image(rdram, ctx);
        goto after_11;
    // 0x800AA1A0: addiu       $a0, $a0, 0x5438
    ctx->r4 = ADD32(ctx->r4, 0X5438);
    after_11:
    // 0x800AA1A4: jal         0x800AE9E0
    // 0x800AA1A8: nop

    hangarLoadShadows(rdram, ctx);
        goto after_12;
    // 0x800AA1A8: nop

    after_12:
    // 0x800AA1AC: jal         0x80056350
    // 0x800AA1B0: nop

    func_80056350(rdram, ctx);
        goto after_13;
    // 0x800AA1B0: nop

    after_13:
    // 0x800AA1B4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800AA1B8: addiu       $a0, $a0, 0x5448
    ctx->r4 = ADD32(ctx->r4, 0X5448);
    // 0x800AA1BC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AA1C0: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800AA1C4: jal         0x8005645C
    // 0x800AA1C8: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    load_hmt_and_hob(rdram, ctx);
        goto after_14;
    // 0x800AA1C8: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_14:
    // 0x800AA1CC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800AA1D0: addiu       $a0, $a0, 0x5460
    ctx->r4 = ADD32(ctx->r4, 0X5460);
    // 0x800AA1D4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AA1D8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800AA1DC: jal         0x8005645C
    // 0x800AA1E0: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    load_hmt_and_hob(rdram, ctx);
        goto after_15;
    // 0x800AA1E0: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_15:
    // 0x800AA1E4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800AA1E8: addiu       $a0, $a0, 0x5478
    ctx->r4 = ADD32(ctx->r4, 0X5478);
    // 0x800AA1EC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AA1F0: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800AA1F4: jal         0x8005645C
    // 0x800AA1F8: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    load_hmt_and_hob(rdram, ctx);
        goto after_16;
    // 0x800AA1F8: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_16:
    // 0x800AA1FC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AA200: lw          $v0, 0xB58($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB58);
    // 0x800AA204: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800AA208: beq         $v0, $zero, L_800AA234
    if (ctx->r2 == 0) {
        // 0x800AA20C: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_800AA234;
    }
    // 0x800AA20C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800AA210: j           L_800AA23C
    // 0x800AA214: addiu       $a0, $v0, 0x548C
    ctx->r4 = ADD32(ctx->r2, 0X548C);
        goto L_800AA23C;
    // 0x800AA214: addiu       $a0, $v0, 0x548C
    ctx->r4 = ADD32(ctx->r2, 0X548C);
L_800AA218:
    // 0x800AA218: sb          $s2, -0x2919($v0)
    MEM_B(-0X2919, ctx->r2) = ctx->r18;
    // 0x800AA21C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AA220: j           L_800A94B0
    // 0x800AA224: sb          $s2, -0x2918($v0)
    MEM_B(-0X2918, ctx->r2) = ctx->r18;
        goto L_800A94B0;
    // 0x800AA224: sb          $s2, -0x2918($v0)
    MEM_B(-0X2918, ctx->r2) = ctx->r18;
L_800AA228:
    // 0x800AA228: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AA22C: j           L_800A947C
    // 0x800AA230: sb          $a2, -0x291C($v0)
    MEM_B(-0X291C, ctx->r2) = ctx->r6;
        goto L_800A947C;
    // 0x800AA230: sb          $a2, -0x291C($v0)
    MEM_B(-0X291C, ctx->r2) = ctx->r6;
L_800AA234:
    // 0x800AA234: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800AA238: addiu       $a0, $v0, 0x54A0
    ctx->r4 = ADD32(ctx->r2, 0X54A0);
L_800AA23C:
    // 0x800AA23C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AA240: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800AA244: jal         0x8005645C
    // 0x800AA248: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    load_hmt_and_hob(rdram, ctx);
        goto after_17;
    // 0x800AA248: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_17:
    // 0x800AA24C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800AA250: addiu       $a0, $a0, 0x54B0
    ctx->r4 = ADD32(ctx->r4, 0X54B0);
    // 0x800AA254: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AA258: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800AA25C: jal         0x8005645C
    // 0x800AA260: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    load_hmt_and_hob(rdram, ctx);
        goto after_18;
    // 0x800AA260: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_18:
    // 0x800AA264: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800AA268: addiu       $a0, $a0, 0x54C0
    ctx->r4 = ADD32(ctx->r4, 0X54C0);
    // 0x800AA26C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AA270: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800AA274: jal         0x8005645C
    // 0x800AA278: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    load_hmt_and_hob(rdram, ctx);
        goto after_19;
    // 0x800AA278: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_19:
    // 0x800AA27C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800AA280: addiu       $a0, $a0, 0x54D0
    ctx->r4 = ADD32(ctx->r4, 0X54D0);
    // 0x800AA284: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AA288: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800AA28C: jal         0x8005645C
    // 0x800AA290: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    load_hmt_and_hob(rdram, ctx);
        goto after_20;
    // 0x800AA290: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_20:
    // 0x800AA294: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AA298: lbu         $v0, -0x2931($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2931);
    // 0x800AA29C: beq         $v0, $zero, L_800AA2BC
    if (ctx->r2 == 0) {
        // 0x800AA2A0: lui         $a0, 0x800A
        ctx->r4 = S32(0X800A << 16);
            goto L_800AA2BC;
    }
    // 0x800AA2A0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800AA2A4: addiu       $a0, $a0, 0x54E4
    ctx->r4 = ADD32(ctx->r4, 0X54E4);
    // 0x800AA2A8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AA2AC: lw          $a1, 0xB68($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XB68);
    // 0x800AA2B0: ori         $a2, $zero, 0x8000
    ctx->r6 = 0 | 0X8000;
    // 0x800AA2B4: jal         0x8005645C
    // 0x800AA2B8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    load_hmt_and_hob(rdram, ctx);
        goto after_21;
    // 0x800AA2B8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_21:
L_800AA2BC:
    // 0x800AA2BC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800AA2C0: addiu       $a0, $a0, 0x54F8
    ctx->r4 = ADD32(ctx->r4, 0X54F8);
    // 0x800AA2C4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AA2C8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800AA2CC: jal         0x8005645C
    // 0x800AA2D0: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    load_hmt_and_hob(rdram, ctx);
        goto after_22;
    // 0x800AA2D0: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_22:
    // 0x800AA2D4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AA2D8: addiu       $v1, $v1, -0x3A64
    ctx->r3 = ADD32(ctx->r3, -0X3A64);
    // 0x800AA2DC: andi        $v0, $fp, 0xFF
    ctx->r2 = ctx->r30 & 0XFF;
    // 0x800AA2E0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800AA2E4: addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // 0x800AA2E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800AA2EC: jal         0x8003471C
    // 0x800AA2F0: nop

    strlen_recomp(rdram, ctx);
        goto after_23;
    // 0x800AA2F0: nop

    after_23:
    // 0x800AA2F4: beq         $v0, $zero, L_800AA330
    if (ctx->r2 == 0) {
        // 0x800AA2F8: addiu       $a0, $sp, 0x28
        ctx->r4 = ADD32(ctx->r29, 0X28);
            goto L_800AA330;
    }
    // 0x800AA2F8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800AA2FC: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800AA300: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x800AA304: addiu       $a1, $a1, 0x5508
    ctx->r5 = ADD32(ctx->r5, 0X5508);
    // 0x800AA308: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800AA30C: jal         0x80033CC4
    // 0x800AA310: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    sprintf_recomp(rdram, ctx);
        goto after_24;
    // 0x800AA310: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    after_24:
    // 0x800AA314: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800AA318: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AA31C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800AA320: jal         0x8005645C
    // 0x800AA324: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    load_hmt_and_hob(rdram, ctx);
        goto after_25;
    // 0x800AA324: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_25:
    // 0x800AA328: j           L_800AA344
    // 0x800AA32C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
        goto L_800AA344;
    // 0x800AA32C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
L_800AA330:
    // 0x800AA330: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AA334: lhu         $v0, -0x25BE($v1)
    ctx->r2 = MEM_HU(ctx->r3, -0X25BE);
    // 0x800AA338: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800AA33C: sh          $v0, -0x25BE($v1)
    MEM_H(-0X25BE, ctx->r3) = ctx->r2;
    // 0x800AA340: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
L_800AA344:
    // 0x800AA344: addiu       $a0, $a0, 0x5518
    ctx->r4 = ADD32(ctx->r4, 0X5518);
    // 0x800AA348: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AA34C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800AA350: jal         0x8005645C
    // 0x800AA354: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    load_hmt_and_hob(rdram, ctx);
        goto after_26;
    // 0x800AA354: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_26:
    // 0x800AA358: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800AA35C: addiu       $a0, $a0, 0x552C
    ctx->r4 = ADD32(ctx->r4, 0X552C);
    // 0x800AA360: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800AA364: jal         0x800547C0
    // 0x800AA368: addiu       $a1, $a1, 0x5534
    ctx->r5 = ADD32(ctx->r5, 0X5534);
    func_800547C0(rdram, ctx);
        goto after_27;
    // 0x800AA368: addiu       $a1, $a1, 0x5534
    ctx->r5 = ADD32(ctx->r5, 0X5534);
    after_27:
    // 0x800AA36C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800AA370: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AA374: sh          $v0, -0x25BC($v1)
    MEM_H(-0X25BC, ctx->r3) = ctx->r2;
    // 0x800AA378: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x800AA37C: lui         $a1, 0x4140
    ctx->r5 = S32(0X4140 << 16);
    // 0x800AA380: jal         0x80054B0C
    // 0x800AA384: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    func_80054B0C(rdram, ctx);
        goto after_28;
    // 0x800AA384: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    after_28:
    // 0x800AA388: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AA38C: lhu         $v0, -0x25BE($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X25BE);
    // 0x800AA390: beq         $v0, $zero, L_800AA7C4
    if (ctx->r2 == 0) {
        // 0x800AA394: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_800AA7C4;
    }
    // 0x800AA394: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800AA398: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x800AA39C: addiu       $s7, $zero, 0x2A
    ctx->r23 = ADD32(0, 0X2A);
    // 0x800AA3A0: lui         $s6, 0x800D
    ctx->r22 = S32(0X800D << 16);
    // 0x800AA3A4: addu        $s1, $s2, $zero
    ctx->r17 = ADD32(ctx->r18, 0);
L_800AA3A8:
    // 0x800AA3A8: lw          $s0, -0x25A4($s4)
    ctx->r16 = MEM_W(ctx->r20, -0X25A4);
    // 0x800AA3AC: addu        $s0, $s1, $s0
    ctx->r16 = ADD32(ctx->r17, ctx->r16);
    // 0x800AA3B0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800AA3B4: jal         0x8003471C
    // 0x800AA3B8: nop

    strlen_recomp(rdram, ctx);
        goto after_29;
    // 0x800AA3B8: nop

    after_29:
    // 0x800AA3BC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800AA3C0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800AA3C4: lbu         $v1, -0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X1);
    // 0x800AA3C8: addiu       $v0, $v1, -0x32
    ctx->r2 = ADD32(ctx->r3, -0X32);
    // 0x800AA3CC: sltiu       $v0, $v0, 0x8
    ctx->r2 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x800AA3D0: beq         $v0, $zero, L_800AA3F8
    if (ctx->r2 == 0) {
        // 0x800AA3D4: andi        $v1, $v1, 0xFF
        ctx->r3 = ctx->r3 & 0XFF;
            goto L_800AA3F8;
    }
    // 0x800AA3D4: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x800AA3D8: lw          $v0, -0x25A4($s4)
    ctx->r2 = MEM_W(ctx->r20, -0X25A4);
    // 0x800AA3DC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800AA3E0: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800AA3E4: sb          $v1, 0x270($v0)
    MEM_B(0X270, ctx->r2) = ctx->r3;
    // 0x800AA3E8: lw          $v0, -0x25A4($s4)
    ctx->r2 = MEM_W(ctx->r20, -0X25A4);
    // 0x800AA3EC: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800AA3F0: j           L_800AA404
    // 0x800AA3F4: sb          $s5, 0x274($v0)
    MEM_B(0X274, ctx->r2) = ctx->r21;
        goto L_800AA404;
    // 0x800AA3F4: sb          $s5, 0x274($v0)
    MEM_B(0X274, ctx->r2) = ctx->r21;
L_800AA3F8:
    // 0x800AA3F8: addiu       $v0, $zero, 0x31
    ctx->r2 = ADD32(0, 0X31);
    // 0x800AA3FC: beql        $v1, $v0, L_800AA404
    if (ctx->r3 == ctx->r2) {
        // 0x800AA400: addu        $s5, $s2, $zero
        ctx->r21 = ADD32(ctx->r18, 0);
            goto L_800AA404;
    }
    goto skip_1;
    // 0x800AA400: addu        $s5, $s2, $zero
    ctx->r21 = ADD32(ctx->r18, 0);
    skip_1:
L_800AA404:
    // 0x800AA404: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AA408: lhu         $v0, -0x25AA($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X25AA);
    // 0x800AA40C: bne         $s2, $v0, L_800AA420
    if (ctx->r18 != ctx->r2) {
        // 0x800AA410: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800AA420;
    }
    // 0x800AA410: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AA414: lbu         $v0, -0x2931($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2931);
    // 0x800AA418: beq         $v0, $zero, L_800AA48C
    if (ctx->r2 == 0) {
        // 0x800AA41C: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_800AA48C;
    }
    // 0x800AA41C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
L_800AA420:
    // 0x800AA420: lw          $v0, -0x25A4($s4)
    ctx->r2 = MEM_W(ctx->r20, -0X25A4);
    // 0x800AA424: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800AA428: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800AA42C: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
    // 0x800AA430: beq         $v1, $zero, L_800AA478
    if (ctx->r3 == 0) {
        // 0x800AA434: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800AA478;
    }
    // 0x800AA434: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AA438: addiu       $v0, $zero, 0x23
    ctx->r2 = ADD32(0, 0X23);
    // 0x800AA43C: beq         $v1, $v0, L_800AA478
    if (ctx->r3 == ctx->r2) {
        // 0x800AA440: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800AA478;
    }
    // 0x800AA440: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AA444: addiu       $a3, $v0, -0x2AE0
    ctx->r7 = ADD32(ctx->r2, -0X2AE0);
    // 0x800AA448: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    // 0x800AA44C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800AA450:
    // 0x800AA450: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800AA454: beq         $v1, $s7, L_800AA478
    if (ctx->r3 == ctx->r23) {
        // 0x800AA458: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800AA478;
    }
    // 0x800AA458: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800AA45C: addu        $v0, $a1, $a3
    ctx->r2 = ADD32(ctx->r5, ctx->r7);
    // 0x800AA460: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x800AA464: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800AA468: beq         $v0, $zero, L_800AA478
    if (ctx->r2 == 0) {
        // 0x800AA46C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800AA478;
    }
    // 0x800AA46C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800AA470: bne         $v0, $a2, L_800AA450
    if (ctx->r2 != ctx->r6) {
        // 0x800AA474: nop
    
            goto L_800AA450;
    }
    // 0x800AA474: nop

L_800AA478:
    // 0x800AA478: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800AA47C: addiu       $v1, $t0, -0x2AE0
    ctx->r3 = ADD32(ctx->r8, -0X2AE0);
    // 0x800AA480: addu        $v0, $a1, $v1
    ctx->r2 = ADD32(ctx->r5, ctx->r3);
    // 0x800AA484: j           L_800AA490
    // 0x800AA488: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
        goto L_800AA490;
    // 0x800AA488: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_800AA48C:
    // 0x800AA48C: addiu       $v1, $v0, 0x554C
    ctx->r3 = ADD32(ctx->r2, 0X554C);
L_800AA490:
    // 0x800AA490: jal         0x80056EB0
    // 0x800AA494: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    func_80056EB0(rdram, ctx);
        goto after_30;
    // 0x800AA494: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_30:
    // 0x800AA498: lw          $v1, -0x25A4($s4)
    ctx->r3 = MEM_W(ctx->r20, -0X25A4);
    // 0x800AA49C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800AA4A0: addu        $a1, $s1, $v1
    ctx->r5 = ADD32(ctx->r17, ctx->r3);
    // 0x800AA4A4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AA4A8: lhu         $v1, -0x25AC($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X25AC);
    // 0x800AA4AC: addiu       $a0, $a0, -0x3C20
    ctx->r4 = ADD32(ctx->r4, -0X3C20);
    // 0x800AA4B0: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x800AA4B4: beq         $s2, $v1, L_800AA4C8
    if (ctx->r18 == ctx->r3) {
        // 0x800AA4B8: sw          $a0, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r4;
            goto L_800AA4C8;
    }
    // 0x800AA4B8: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x800AA4BC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800AA4C0: j           L_800AA4D0
    // 0x800AA4C4: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
        goto L_800AA4D0;
    // 0x800AA4C4: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
L_800AA4C8:
    // 0x800AA4C8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800AA4CC: addiu       $a1, $v0, 0x5554
    ctx->r5 = ADD32(ctx->r2, 0X5554);
L_800AA4D0:
    // 0x800AA4D0: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800AA4D4: addiu       $t1, $t1, -0x3A74
    ctx->r9 = ADD32(ctx->r9, -0X3A74);
    // 0x800AA4D8: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x800AA4DC: jal         0x80047B70
    // 0x800AA4E0: nop

    getDatItemByName(rdram, ctx);
        goto after_31;
    // 0x800AA4E0: nop

    after_31:
    // 0x800AA4E4: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x800AA4E8: lw          $a0, -0x25A4($s4)
    ctx->r4 = MEM_W(ctx->r20, -0X25A4);
    // 0x800AA4EC: lw          $v1, -0x25A4($s4)
    ctx->r3 = MEM_W(ctx->r20, -0X25A4);
    // 0x800AA4F0: addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    // 0x800AA4F4: addu        $v1, $s1, $v1
    ctx->r3 = ADD32(ctx->r17, ctx->r3);
    // 0x800AA4F8: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x800AA4FC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AA500: lw          $t2, 0x10($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X10);
    // 0x800AA504: lw          $t3, 0x14($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X14);
    // 0x800AA508: lw          $t0, 0x18($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X18);
    // 0x800AA50C: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
    // 0x800AA510: sw          $t3, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r11;
    // 0x800AA514: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
    // 0x800AA518: lw          $t2, 0x1C($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X1C);
    // 0x800AA51C: lw          $t3, 0x20($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X20);
    // 0x800AA520: lw          $t0, 0x24($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X24);
    // 0x800AA524: sw          $t2, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r10;
    // 0x800AA528: sw          $t3, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r11;
    // 0x800AA52C: sw          $t0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r8;
    // 0x800AA530: lw          $v1, -0x25A4($s4)
    ctx->r3 = MEM_W(ctx->r20, -0X25A4);
    // 0x800AA534: lwc1        $f0, 0x28($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X28);
    // 0x800AA538: lhu         $v0, -0x25AC($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X25AC);
    // 0x800AA53C: addu        $a0, $s1, $v1
    ctx->r4 = ADD32(ctx->r17, ctx->r3);
    // 0x800AA540: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x800AA544: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x800AA548: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x800AA54C: bne         $s2, $v0, L_800AA5B0
    if (ctx->r18 != ctx->r2) {
        // 0x800AA550: swc1        $f0, 0x3C($a0)
        MEM_W(0X3C, ctx->r4) = ctx->f0.u32l;
            goto L_800AA5B0;
    }
    // 0x800AA550: swc1        $f0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f0.u32l;
    // 0x800AA554: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AA558: addiu       $v0, $v0, -0x3A18
    ctx->r2 = ADD32(ctx->r2, -0X3A18);
    // 0x800AA55C: andi        $a1, $fp, 0xFF
    ctx->r5 = ctx->r30 & 0XFF;
    // 0x800AA560: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800AA564: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800AA568: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA56C: lwc1        $f4, 0x55B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X55B8);
    // 0x800AA570: bne         $v0, $zero, L_800AA580
    if (ctx->r2 != 0) {
        // 0x800AA574: lui         $v1, 0x800D
        ctx->r3 = S32(0X800D << 16);
            goto L_800AA580;
    }
    // 0x800AA574: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AA578: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA57C: lwc1        $f4, 0x55BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X55BC);
L_800AA580:
    // 0x800AA580: addiu       $v1, $v1, -0x3A04
    ctx->r3 = ADD32(ctx->r3, -0X3A04);
    // 0x800AA584: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800AA588: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA58C: lwc1        $f0, 0x55C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X55C0);
    // 0x800AA590: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA594: lwc1        $f2, 0x55C4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X55C4);
    // 0x800AA598: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800AA59C: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x800AA5A0: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x800AA5A4: swc1        $f2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f2.u32l;
    // 0x800AA5A8: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800AA5AC: swc1        $f0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f0.u32l;
L_800AA5B0:
    // 0x800AA5B0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800AA5B4: lw          $v0, -0x25A4($s4)
    ctx->r2 = MEM_W(ctx->r20, -0X25A4);
    // 0x800AA5B8: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800AA5BC: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800AA5C0: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x800AA5C4: addiu       $a1, $a1, 0x555C
    ctx->r5 = ADD32(ctx->r5, 0X555C);
    // 0x800AA5C8: sh          $zero, 0x26E($v0)
    MEM_H(0X26E, ctx->r2) = 0;
    // 0x800AA5CC: jal         0x80033CC4
    // 0x800AA5D0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    sprintf_recomp(rdram, ctx);
        goto after_32;
    // 0x800AA5D0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_32:
    // 0x800AA5D4: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x800AA5D8: lw          $a1, -0x25A4($s4)
    ctx->r5 = MEM_W(ctx->r20, -0X25A4);
    // 0x800AA5DC: lw          $a0, -0x3A74($s6)
    ctx->r4 = MEM_W(ctx->r22, -0X3A74);
    // 0x800AA5E0: addu        $a1, $a1, $s1
    ctx->r5 = ADD32(ctx->r5, ctx->r17);
    // 0x800AA5E4: jal         0x80047C38
    // 0x800AA5E8: addiu       $a1, $a1, 0x210
    ctx->r5 = ADD32(ctx->r5, 0X210);
    func_80047C38(rdram, ctx);
        goto after_33;
    // 0x800AA5E8: addiu       $a1, $a1, 0x210
    ctx->r5 = ADD32(ctx->r5, 0X210);
    after_33:
    // 0x800AA5EC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800AA5F0: beq         $s0, $zero, L_800AA664
    if (ctx->r16 == 0) {
        // 0x800AA5F4: nop
    
            goto L_800AA664;
    }
    // 0x800AA5F4: nop

    // 0x800AA5F8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AA5FC: lw          $v0, 0xB58($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB58);
    // 0x800AA600: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800AA604: beq         $v0, $zero, L_800AA62C
    if (ctx->r2 == 0) {
        // 0x800AA608: nop
    
            goto L_800AA62C;
    }
    // 0x800AA608: nop

    // 0x800AA60C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800AA610: bne         $s2, $v0, L_800AA62C
    if (ctx->r18 != ctx->r2) {
        // 0x800AA614: nop
    
            goto L_800AA62C;
    }
    // 0x800AA614: nop

    // 0x800AA618: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800AA61C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA620: lwc1        $f2, 0x55C8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X55C8);
    // 0x800AA624: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800AA628: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
L_800AA62C:
    // 0x800AA62C: lw          $a3, -0x25A4($s4)
    ctx->r7 = MEM_W(ctx->r20, -0X25A4);
    // 0x800AA630: addiu       $a1, $s3, 0x10
    ctx->r5 = ADD32(ctx->r19, 0X10);
    // 0x800AA634: lw          $t2, 0x10($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X10);
    // 0x800AA638: lw          $t3, 0x14($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X14);
    // 0x800AA63C: lw          $t0, 0x18($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X18);
    // 0x800AA640: sw          $t2, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r10;
    // 0x800AA644: sw          $t3, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r11;
    // 0x800AA648: sw          $t0, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r8;
    // 0x800AA64C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800AA650: addu        $a3, $a3, $s1
    ctx->r7 = ADD32(ctx->r7, ctx->r17);
    // 0x800AA654: addiu       $a0, $a3, 0x210
    ctx->r4 = ADD32(ctx->r7, 0X210);
    // 0x800AA658: addiu       $a2, $a3, 0xC
    ctx->r6 = ADD32(ctx->r7, 0XC);
    // 0x800AA65C: jal         0x800662A0
    // 0x800AA660: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    func_800662A0(rdram, ctx);
        goto after_34;
    // 0x800AA660: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    after_34:
L_800AA664:
    // 0x800AA664: lw          $v0, -0x25A4($s4)
    ctx->r2 = MEM_W(ctx->r20, -0X25A4);
    // 0x800AA668: beq         $s0, $zero, L_800AA67C
    if (ctx->r16 == 0) {
        // 0x800AA66C: addu        $v0, $s1, $v0
        ctx->r2 = ADD32(ctx->r17, ctx->r2);
            goto L_800AA67C;
    }
    // 0x800AA66C: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800AA670: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x800AA674: j           L_800AA680
    // 0x800AA678: swc1        $f0, 0x220($v0)
    MEM_W(0X220, ctx->r2) = ctx->f0.u32l;
        goto L_800AA680;
    // 0x800AA678: swc1        $f0, 0x220($v0)
    MEM_W(0X220, ctx->r2) = ctx->f0.u32l;
L_800AA67C:
    // 0x800AA67C: sw          $zero, 0x220($v0)
    MEM_W(0X220, ctx->r2) = 0;
L_800AA680:
    // 0x800AA680: lw          $v0, -0x25A4($s4)
    ctx->r2 = MEM_W(ctx->r20, -0X25A4);
    // 0x800AA684: beq         $s0, $zero, L_800AA698
    if (ctx->r16 == 0) {
        // 0x800AA688: addu        $v0, $s1, $v0
        ctx->r2 = ADD32(ctx->r17, ctx->r2);
            goto L_800AA698;
    }
    // 0x800AA688: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800AA68C: lwc1        $f0, 0x44($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800AA690: j           L_800AA6A4
    // 0x800AA694: swc1        $f0, 0x224($v0)
    MEM_W(0X224, ctx->r2) = ctx->f0.u32l;
        goto L_800AA6A4;
    // 0x800AA694: swc1        $f0, 0x224($v0)
    MEM_W(0X224, ctx->r2) = ctx->f0.u32l;
L_800AA698:
    // 0x800AA698: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA69C: lwc1        $f0, 0x55CC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X55CC);
    // 0x800AA6A0: swc1        $f0, 0x224($v0)
    MEM_W(0X224, ctx->r2) = ctx->f0.u32l;
L_800AA6A4:
    // 0x800AA6A4: lw          $v0, -0x25A4($s4)
    ctx->r2 = MEM_W(ctx->r20, -0X25A4);
    // 0x800AA6A8: addu        $v1, $s1, $v0
    ctx->r3 = ADD32(ctx->r17, ctx->r2);
    // 0x800AA6AC: lhu         $v0, 0x40($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X40);
    // 0x800AA6B0: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800AA6B4: beq         $v0, $zero, L_800AA6D0
    if (ctx->r2 == 0) {
        // 0x800AA6B8: sw          $zero, 0x21C($v1)
        MEM_W(0X21C, ctx->r3) = 0;
            goto L_800AA6D0;
    }
    // 0x800AA6B8: sw          $zero, 0x21C($v1)
    MEM_W(0X21C, ctx->r3) = 0;
    // 0x800AA6BC: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x800AA6C0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AA6C4: lui         $a2, 0x4
    ctx->r6 = S32(0X4 << 16);
    // 0x800AA6C8: jal         0x8005955C
    // 0x800AA6CC: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8005955C(rdram, ctx);
        goto after_35;
    // 0x800AA6CC: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_35:
L_800AA6D0:
    // 0x800AA6D0: lw          $v0, -0x25A4($s4)
    ctx->r2 = MEM_W(ctx->r20, -0X25A4);
    // 0x800AA6D4: addu        $v1, $s1, $v0
    ctx->r3 = ADD32(ctx->r17, ctx->r2);
    // 0x800AA6D8: lhu         $v0, 0x40($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X40);
    // 0x800AA6DC: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800AA6E0: beq         $v0, $zero, L_800AA768
    if (ctx->r2 == 0) {
        // 0x800AA6E4: nop
    
            goto L_800AA768;
    }
    // 0x800AA6E4: nop

    // 0x800AA6E8: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x800AA6EC: lw          $a1, 0x3C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X3C);
    // 0x800AA6F0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x800AA6F4: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800AA6F8: jal         0x8001CB64
    // 0x800AA6FC: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8001CB64(rdram, ctx);
        goto after_36;
    // 0x800AA6FC: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_36:
    // 0x800AA700: lw          $v0, -0x25A4($s4)
    ctx->r2 = MEM_W(ctx->r20, -0X25A4);
    // 0x800AA704: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800AA708: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x800AA70C: lw          $a1, 0x18($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X18);
    // 0x800AA710: jal         0x8001CB9C
    // 0x800AA714: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8001CB9C(rdram, ctx);
        goto after_37;
    // 0x800AA714: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_37:
    // 0x800AA718: lw          $v0, -0x25A4($s4)
    ctx->r2 = MEM_W(ctx->r20, -0X25A4);
    // 0x800AA71C: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800AA720: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x800AA724: lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1C);
    // 0x800AA728: jal         0x8001CCCC
    // 0x800AA72C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8001CCCC(rdram, ctx);
        goto after_38;
    // 0x800AA72C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_38:
    // 0x800AA730: lw          $v0, -0x25A4($s4)
    ctx->r2 = MEM_W(ctx->r20, -0X25A4);
    // 0x800AA734: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800AA738: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x800AA73C: lw          $a1, 0x20($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X20);
    // 0x800AA740: jal         0x8001CDFC
    // 0x800AA744: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8001CDFC(rdram, ctx);
        goto after_39;
    // 0x800AA744: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_39:
    // 0x800AA748: lw          $v0, -0x25A4($s4)
    ctx->r2 = MEM_W(ctx->r20, -0X25A4);
    // 0x800AA74C: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800AA750: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x800AA754: lw          $a2, 0x10($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X10);
    // 0x800AA758: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x800AA75C: lw          $a3, 0x14($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X14);
    // 0x800AA760: jal         0x8001CA90
    // 0x800AA764: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8001CA90(rdram, ctx);
        goto after_40;
    // 0x800AA764: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_40:
L_800AA768:
    // 0x800AA768: lw          $v0, -0x25A4($s4)
    ctx->r2 = MEM_W(ctx->r20, -0X25A4);
    // 0x800AA76C: addu        $a0, $s1, $v0
    ctx->r4 = ADD32(ctx->r17, ctx->r2);
    // 0x800AA770: lhu         $v1, 0x40($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X40);
    // 0x800AA774: andi        $v0, $v1, 0xC0
    ctx->r2 = ctx->r3 & 0XC0;
    // 0x800AA778: beq         $v0, $zero, L_800AA7AC
    if (ctx->r2 == 0) {
        // 0x800AA77C: addiu       $a1, $zero, 0x16
        ctx->r5 = ADD32(0, 0X16);
            goto L_800AA7AC;
    }
    // 0x800AA77C: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x800AA780: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800AA784: addiu       $a2, $v0, -0x5AD8
    ctx->r6 = ADD32(ctx->r2, -0X5AD8);
    // 0x800AA788: andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // 0x800AA78C: beq         $v0, $zero, L_800AA798
    if (ctx->r2 == 0) {
        // 0x800AA790: addiu       $a0, $a0, 0x48
        ctx->r4 = ADD32(ctx->r4, 0X48);
            goto L_800AA798;
    }
    // 0x800AA790: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800AA794: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
L_800AA798:
    // 0x800AA798: addu        $v0, $a1, $a2
    ctx->r2 = ADD32(ctx->r5, ctx->r6);
    // 0x800AA79C: lhu         $a1, 0x0($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X0);
    // 0x800AA7A0: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800AA7A4: jal         0x800AE088
    // 0x800AA7A8: addiu       $a2, $a2, -0x3A68
    ctx->r6 = ADD32(ctx->r6, -0X3A68);
    hangarInitializeShipShadowHob(rdram, ctx);
        goto after_41;
    // 0x800AA7A8: addiu       $a2, $a2, -0x3A68
    ctx->r6 = ADD32(ctx->r6, -0X3A68);
    after_41:
L_800AA7AC:
    // 0x800AA7AC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AA7B0: lhu         $v0, -0x25BE($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X25BE);
    // 0x800AA7B4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800AA7B8: sltu        $v0, $s2, $v0
    ctx->r2 = ctx->r18 < ctx->r2 ? 1 : 0;
    // 0x800AA7BC: bne         $v0, $zero, L_800AA3A8
    if (ctx->r2 != 0) {
        // 0x800AA7C0: addiu       $s1, $s1, 0x278
        ctx->r17 = ADD32(ctx->r17, 0X278);
            goto L_800AA3A8;
    }
    // 0x800AA7C0: addiu       $s1, $s1, 0x278
    ctx->r17 = ADD32(ctx->r17, 0X278);
L_800AA7C4:
    // 0x800AA7C4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AA7C8: lui         $a2, 0x6
    ctx->r6 = S32(0X6 << 16);
    // 0x800AA7CC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AA7D0: lhu         $v1, -0x25B6($v0)
    ctx->r3 = MEM_HU(ctx->r2, -0X25B6);
    // 0x800AA7D4: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800AA7D8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800AA7DC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800AA7E0: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800AA7E4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800AA7E8: lw          $v1, -0x25A4($s0)
    ctx->r3 = MEM_W(ctx->r16, -0X25A4);
    // 0x800AA7EC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800AA7F0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800AA7F4: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x800AA7F8: jal         0x8005955C
    // 0x800AA7FC: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8005955C(rdram, ctx);
        goto after_42;
    // 0x800AA7FC: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_42:
    // 0x800AA800: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AA804: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AA808: lhu         $v1, -0x25B4($v0)
    ctx->r3 = MEM_HU(ctx->r2, -0X25B4);
    // 0x800AA80C: lui         $a2, 0x6
    ctx->r6 = S32(0X6 << 16);
    // 0x800AA810: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800AA814: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800AA818: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800AA81C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800AA820: lw          $v1, -0x25A4($s0)
    ctx->r3 = MEM_W(ctx->r16, -0X25A4);
    // 0x800AA824: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800AA828: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800AA82C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x800AA830: jal         0x8005955C
    // 0x800AA834: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8005955C(rdram, ctx);
        goto after_43;
    // 0x800AA834: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_43:
    // 0x800AA838: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AA83C: lhu         $v1, -0x25BE($v0)
    ctx->r3 = MEM_HU(ctx->r2, -0X25BE);
    // 0x800AA840: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x800AA844: bne         $v1, $v0, L_800AA888
    if (ctx->r3 != ctx->r2) {
        // 0x800AA848: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_800AA888;
    }
    // 0x800AA848: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800AA84C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AA850: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AA854: lhu         $v1, -0x25AC($v0)
    ctx->r3 = MEM_HU(ctx->r2, -0X25AC);
    // 0x800AA858: lui         $a2, 0x6
    ctx->r6 = S32(0X6 << 16);
    // 0x800AA85C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800AA860: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800AA864: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800AA868: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800AA86C: lw          $v1, -0x25A4($s0)
    ctx->r3 = MEM_W(ctx->r16, -0X25A4);
    // 0x800AA870: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800AA874: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800AA878: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x800AA87C: jal         0x8005955C
    // 0x800AA880: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8005955C(rdram, ctx);
        goto after_44;
    // 0x800AA880: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_44:
    // 0x800AA884: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
L_800AA888:
    // 0x800AA888: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    // 0x800AA88C: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x800AA890: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AA894: addiu       $v0, $v0, -0x2770
    ctx->r2 = ADD32(ctx->r2, -0X2770);
    // 0x800AA898: addiu       $s3, $v0, 0x10
    ctx->r19 = ADD32(ctx->r2, 0X10);
    // 0x800AA89C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_800AA8A0:
    // 0x800AA8A0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800AA8A4: addiu       $a1, $s5, 0x5568
    ctx->r5 = ADD32(ctx->r21, 0X5568);
    // 0x800AA8A8: jal         0x80033CC4
    // 0x800AA8AC: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    sprintf_recomp(rdram, ctx);
        goto after_45;
    // 0x800AA8AC: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_45:
    // 0x800AA8B0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800AA8B4: lw          $a0, -0x3A74($s4)
    ctx->r4 = MEM_W(ctx->r20, -0X3A74);
    // 0x800AA8B8: jal         0x80047C38
    // 0x800AA8BC: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_80047C38(rdram, ctx);
        goto after_46;
    // 0x800AA8BC: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_46:
    // 0x800AA8C0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800AA8C4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800AA8C8: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    // 0x800AA8CC: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x800AA8D0: jal         0x8006623C
    // 0x800AA8D4: sw          $a1, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r5;
    func_8006623C(rdram, ctx);
        goto after_47;
    // 0x800AA8D4: sw          $a1, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r5;
    after_47:
    // 0x800AA8D8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800AA8DC: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x800AA8E0: addiu       $s3, $s3, 0x24
    ctx->r19 = ADD32(ctx->r19, 0X24);
    // 0x800AA8E4: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x800AA8E8: lwc1        $f0, 0x44($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800AA8EC: sltiu       $v0, $s2, 0x6
    ctx->r2 = ctx->r18 < 0X6 ? 1 : 0;
    // 0x800AA8F0: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
    // 0x800AA8F4: bne         $v0, $zero, L_800AA8A0
    if (ctx->r2 != 0) {
        // 0x800AA8F8: addiu       $s1, $s1, 0x24
        ctx->r17 = ADD32(ctx->r17, 0X24);
            goto L_800AA8A0;
    }
    // 0x800AA8F8: addiu       $s1, $s1, 0x24
    ctx->r17 = ADD32(ctx->r17, 0X24);
    // 0x800AA8FC: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800AA900: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    // 0x800AA904: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x800AA908: lui         $s4, 0x800A
    ctx->r20 = S32(0X800A << 16);
    // 0x800AA90C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AA910: addiu       $s1, $v0, -0x2880
    ctx->r17 = ADD32(ctx->r2, -0X2880);
    // 0x800AA914: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AA918: addiu       $s0, $v0, -0x28E0
    ctx->r16 = ADD32(ctx->r2, -0X28E0);
L_800AA91C:
    // 0x800AA91C: sltiu       $v0, $s2, 0x8
    ctx->r2 = ctx->r18 < 0X8 ? 1 : 0;
    // 0x800AA920: beq         $v0, $zero, L_800AA958
    if (ctx->r2 == 0) {
        // 0x800AA924: addiu       $a0, $sp, 0x28
        ctx->r4 = ADD32(ctx->r29, 0X28);
            goto L_800AA958;
    }
    // 0x800AA924: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800AA928: addiu       $a1, $s5, 0x5578
    ctx->r5 = ADD32(ctx->r21, 0X5578);
    // 0x800AA92C: jal         0x80033CC4
    // 0x800AA930: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    sprintf_recomp(rdram, ctx);
        goto after_48;
    // 0x800AA930: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_48:
    // 0x800AA934: lw          $a0, -0x3A74($s3)
    ctx->r4 = MEM_W(ctx->r19, -0X3A74);
    // 0x800AA938: jal         0x80047B70
    // 0x800AA93C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    getDatItemByName(rdram, ctx);
        goto after_49;
    // 0x800AA93C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_49:
    // 0x800AA940: lw          $t2, 0x10($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X10);
    // 0x800AA944: lw          $t3, 0x14($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X14);
    // 0x800AA948: lw          $t0, 0x18($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X18);
    // 0x800AA94C: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x800AA950: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x800AA954: sw          $t0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r8;
L_800AA958:
    // 0x800AA958: sltiu       $v0, $s2, 0x9
    ctx->r2 = ctx->r18 < 0X9 ? 1 : 0;
    // 0x800AA95C: beq         $v0, $zero, L_800AA994
    if (ctx->r2 == 0) {
        // 0x800AA960: addiu       $a0, $sp, 0x28
        ctx->r4 = ADD32(ctx->r29, 0X28);
            goto L_800AA994;
    }
    // 0x800AA960: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800AA964: addiu       $a1, $s4, 0x5588
    ctx->r5 = ADD32(ctx->r20, 0X5588);
    // 0x800AA968: jal         0x80033CC4
    // 0x800AA96C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    sprintf_recomp(rdram, ctx);
        goto after_50;
    // 0x800AA96C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_50:
    // 0x800AA970: lw          $a0, -0x3A74($s3)
    ctx->r4 = MEM_W(ctx->r19, -0X3A74);
    // 0x800AA974: jal         0x80047B70
    // 0x800AA978: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    getDatItemByName(rdram, ctx);
        goto after_51;
    // 0x800AA978: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_51:
    // 0x800AA97C: lw          $t2, 0x10($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X10);
    // 0x800AA980: lw          $t3, 0x14($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X14);
    // 0x800AA984: lw          $t0, 0x18($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X18);
    // 0x800AA988: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x800AA98C: sw          $t3, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r11;
    // 0x800AA990: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
L_800AA994:
    // 0x800AA994: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x800AA998: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800AA99C: sltiu       $v0, $s2, 0x9
    ctx->r2 = ctx->r18 < 0X9 ? 1 : 0;
    // 0x800AA9A0: bne         $v0, $zero, L_800AA91C
    if (ctx->r2 != 0) {
        // 0x800AA9A4: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800AA91C;
    }
    // 0x800AA9A4: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800AA9A8: jal         0x80066918
    // 0x800AA9AC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80066918(rdram, ctx);
        goto after_52;
    // 0x800AA9AC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_52:
    // 0x800AA9B0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800AA9B4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800AA9B8: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x800AA9BC: addiu       $s5, $zero, 0xF
    ctx->r21 = ADD32(0, 0XF);
    // 0x800AA9C0: addiu       $s4, $zero, 0x5A
    ctx->r20 = ADD32(0, 0X5A);
    // 0x800AA9C4: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800AA9C8: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x800AA9CC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA9D0: lwc1        $f20, 0x55D0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X55D0);
    // 0x800AA9D4: jal         0x8006657C
    // 0x800AA9D8: addiu       $s1, $zero, 0x278
    ctx->r17 = ADD32(0, 0X278);
    func_8006657C(rdram, ctx);
        goto after_53;
    // 0x800AA9D8: addiu       $s1, $zero, 0x278
    ctx->r17 = ADD32(0, 0X278);
    after_53:
    // 0x800AA9DC: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x800AA9E0: jal         0x8006657C
    // 0x800AA9E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8006657C(rdram, ctx);
        goto after_54;
    // 0x800AA9E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_54:
    // 0x800AA9E8: jal         0x80066A18
    // 0x800AA9EC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80066A18(rdram, ctx);
        goto after_55;
    // 0x800AA9EC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_55:
    // 0x800AA9F0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800AA9F4: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800AA9F8: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x800AA9FC: jal         0x80097C2C
    // 0x800AAA00: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80097C2C(rdram, ctx);
        goto after_56;
    // 0x800AAA00: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_56:
    // 0x800AAA04: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    // 0x800AAA08: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x800AAA0C: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    // 0x800AAA10: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AAA14: jal         0x8008E0B0
    // 0x800AAA18: sw          $v0, -0x2694($v1)
    MEM_W(-0X2694, ctx->r3) = ctx->r2;
    func_8008E0B0(rdram, ctx);
        goto after_57;
    // 0x800AAA18: sw          $v0, -0x2694($v1)
    MEM_W(-0X2694, ctx->r3) = ctx->r2;
    after_57:
    // 0x800AAA1C: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    // 0x800AAA20: addiu       $a1, $zero, 0x1964
    ctx->r5 = ADD32(0, 0X1964);
    // 0x800AAA24: jal         0x8008E0B0
    // 0x800AAA28: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    func_8008E0B0(rdram, ctx);
        goto after_58;
    // 0x800AAA28: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    after_58:
    // 0x800AAA2C: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x800AAA30: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x800AAA34: jal         0x80087EE8
    // 0x800AAA38: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80087EE8(rdram, ctx);
        goto after_59;
    // 0x800AAA38: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_59:
    // 0x800AAA3C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800AAA40: addiu       $s0, $v1, 0x55D8
    ctx->r16 = ADD32(ctx->r3, 0X55D8);
    // 0x800AAA44: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AAA48: sw          $v0, -0x268C($v1)
    MEM_W(-0X268C, ctx->r3) = ctx->r2;
L_800AAA4C:
    // 0x800AAA4C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AAA50: addiu       $v0, $v0, -0x3C08
    ctx->r2 = ADD32(ctx->r2, -0X3C08);
    // 0x800AAA54: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x800AAA58: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800AAA5C: sltiu       $v0, $v1, 0x9
    ctx->r2 = ctx->r3 < 0X9 ? 1 : 0;
    // 0x800AAA60: beq         $v0, $zero, L_800AAB34
    if (ctx->r2 == 0) {
        // 0x800AAA64: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800AAB34;
    }
    // 0x800AAA64: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800AAA68: addu        $v0, $v0, $s0
    gpr jr_addend_800AAA70 = ctx->r2;
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800AAA6C: lw          $v0, 0x0($v0)
    ctx->r2 = ADD32(ctx->r2, 0X0);
    // 0x800AAA70: jr          $v0
    // 0x800AAA74: nop

    switch (jr_addend_800AAA70 >> 2) {
        case 0: goto L_800AAAB0; break;
        case 1: goto L_800AAAC0; break;
        case 2: goto L_800AAA78; break;
        case 3: goto L_800AAAA0; break;
        case 4: goto L_800AAA90; break;
        case 5: goto L_800AAAD0; break;
        case 6: goto L_800AAAF0; break;
        case 7: goto L_800AAB34; break;
        case 8: goto L_800AAAE0; break;
        default: switch_error(__func__, 0x800AAA70, 0x800A55D8);
    }
    // 0x800AAA74: nop

L_800AAA78:
    // 0x800AAA78: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800AAA7C: lw          $a2, -0x25A4($s3)
    ctx->r6 = MEM_W(ctx->r19, -0X25A4);
    // 0x800AAA80: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800AAA84: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // 0x800AAA88: j           L_800AAB08
    // 0x800AAA8C: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
        goto L_800AAB08;
    // 0x800AAA8C: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
L_800AAA90:
    // 0x800AAA90: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800AAA94: lw          $a2, -0x25A4($s3)
    ctx->r6 = MEM_W(ctx->r19, -0X25A4);
    // 0x800AAA98: j           L_800AAAFC
    // 0x800AAA9C: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
        goto L_800AAAFC;
    // 0x800AAA9C: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_800AAAA0:
    // 0x800AAAA0: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800AAAA4: lw          $a2, -0x25A4($s3)
    ctx->r6 = MEM_W(ctx->r19, -0X25A4);
    // 0x800AAAA8: j           L_800AAAFC
    // 0x800AAAAC: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
        goto L_800AAAFC;
    // 0x800AAAAC: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_800AAAB0:
    // 0x800AAAB0: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800AAAB4: lw          $a2, -0x25A4($s3)
    ctx->r6 = MEM_W(ctx->r19, -0X25A4);
    // 0x800AAAB8: j           L_800AAAFC
    // 0x800AAABC: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_800AAAFC;
    // 0x800AAABC: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_800AAAC0:
    // 0x800AAAC0: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800AAAC4: lw          $a2, -0x25A4($s3)
    ctx->r6 = MEM_W(ctx->r19, -0X25A4);
    // 0x800AAAC8: j           L_800AAAFC
    // 0x800AAACC: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
        goto L_800AAAFC;
    // 0x800AAACC: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_800AAAD0:
    // 0x800AAAD0: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800AAAD4: lw          $a2, -0x25A4($s3)
    ctx->r6 = MEM_W(ctx->r19, -0X25A4);
    // 0x800AAAD8: j           L_800AAAFC
    // 0x800AAADC: addiu       $v0, $zero, 0x2E
    ctx->r2 = ADD32(0, 0X2E);
        goto L_800AAAFC;
    // 0x800AAADC: addiu       $v0, $zero, 0x2E
    ctx->r2 = ADD32(0, 0X2E);
L_800AAAE0:
    // 0x800AAAE0: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800AAAE4: lw          $a2, -0x25A4($s3)
    ctx->r6 = MEM_W(ctx->r19, -0X25A4);
    // 0x800AAAE8: j           L_800AAAFC
    // 0x800AAAEC: addiu       $v0, $zero, 0x6F
    ctx->r2 = ADD32(0, 0X6F);
        goto L_800AAAFC;
    // 0x800AAAEC: addiu       $v0, $zero, 0x6F
    ctx->r2 = ADD32(0, 0X6F);
L_800AAAF0:
    // 0x800AAAF0: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800AAAF4: lw          $a2, -0x25A4($s3)
    ctx->r6 = MEM_W(ctx->r19, -0X25A4);
    // 0x800AAAF8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_800AAAFC:
    // 0x800AAAFC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800AAB00: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // 0x800AAB04: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
L_800AAB08:
    // 0x800AAB08: sw          $s4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r20;
    // 0x800AAB0C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800AAB10: addu        $a2, $a2, $s1
    ctx->r6 = ADD32(ctx->r6, ctx->r17);
    // 0x800AAB14: addiu       $a0, $a2, 0x228
    ctx->r4 = ADD32(ctx->r6, 0X228);
    // 0x800AAB18: addiu       $a1, $a2, 0xC
    ctx->r5 = ADD32(ctx->r6, 0XC);
    // 0x800AAB1C: jal         0x800989D8
    // 0x800AAB20: addiu       $a2, $a2, 0x24
    ctx->r6 = ADD32(ctx->r6, 0X24);
    func_800989D8(rdram, ctx);
        goto after_60;
    // 0x800AAB20: addiu       $a2, $a2, 0x24
    ctx->r6 = ADD32(ctx->r6, 0X24);
    after_60:
    // 0x800AAB24: lw          $v0, -0x25A4($s3)
    ctx->r2 = MEM_W(ctx->r19, -0X25A4);
    // 0x800AAB28: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800AAB2C: j           L_800AAB40
    // 0x800AAB30: sb          $s4, 0x273($v0)
    MEM_B(0X273, ctx->r2) = ctx->r20;
        goto L_800AAB40;
    // 0x800AAB30: sb          $s4, 0x273($v0)
    MEM_B(0X273, ctx->r2) = ctx->r20;
L_800AAB34:
    // 0x800AAB34: lw          $v0, -0x25A4($s3)
    ctx->r2 = MEM_W(ctx->r19, -0X25A4);
    // 0x800AAB38: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800AAB3C: sw          $zero, 0x230($v0)
    MEM_W(0X230, ctx->r2) = 0;
L_800AAB40:
    // 0x800AAB40: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800AAB44: lw          $v0, -0x25A4($s3)
    ctx->r2 = MEM_W(ctx->r19, -0X25A4);
    // 0x800AAB48: addiu       $v1, $zero, 0x100
    ctx->r3 = ADD32(0, 0X100);
    // 0x800AAB4C: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800AAB50: sh          $v1, 0x26C($v0)
    MEM_H(0X26C, ctx->r2) = ctx->r3;
    // 0x800AAB54: sltiu       $v0, $s2, 0x9
    ctx->r2 = ctx->r18 < 0X9 ? 1 : 0;
    // 0x800AAB58: bne         $v0, $zero, L_800AAA4C
    if (ctx->r2 != 0) {
        // 0x800AAB5C: addiu       $s1, $s1, 0x278
        ctx->r17 = ADD32(ctx->r17, 0X278);
            goto L_800AAA4C;
    }
    // 0x800AAB5C: addiu       $s1, $s1, 0x278
    ctx->r17 = ADD32(ctx->r17, 0X278);
    // 0x800AAB60: andi        $a0, $fp, 0xFF
    ctx->r4 = ctx->r30 & 0XFF;
    // 0x800AAB64: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AAB68: sb          $zero, -0x2698($v0)
    MEM_B(-0X2698, ctx->r2) = 0;
    // 0x800AAB6C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AAB70: jal         0x800AB658
    // 0x800AAB74: sb          $zero, -0x3C1C($v0)
    MEM_B(-0X3C1C, ctx->r2) = 0;
    func_800AB658(rdram, ctx);
        goto after_61;
    // 0x800AAB74: sb          $zero, -0x3C1C($v0)
    MEM_B(-0X3C1C, ctx->r2) = 0;
    after_61:
    // 0x800AAB78: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800AAB7C: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x800AAB80: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800AAB84: addiu       $s7, $v0, -0x5AD8
    ctx->r23 = ADD32(ctx->r2, -0X5AD8);
    // 0x800AAB88: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AAB8C: addiu       $s6, $v0, -0x3AE0
    ctx->r22 = ADD32(ctx->r2, -0X3AE0);
    // 0x800AAB90: lui         $s5, 0x800D
    ctx->r21 = S32(0X800D << 16);
    // 0x800AAB94: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AAB98: addiu       $s4, $v0, -0x25E0
    ctx->r20 = ADD32(ctx->r2, -0X25E0);
    // 0x800AAB9C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800AABA0: addiu       $s0, $zero, 0x278
    ctx->r16 = ADD32(0, 0X278);
L_800AABA4:
    // 0x800AABA4: lw          $v0, -0x25A4($s3)
    ctx->r2 = MEM_W(ctx->r19, -0X25A4);
    // 0x800AABA8: addu        $v1, $s0, $v0
    ctx->r3 = ADD32(ctx->r16, ctx->r2);
    // 0x800AABAC: lhu         $v0, 0x40($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X40);
    // 0x800AABB0: andi        $v0, $v0, 0x200
    ctx->r2 = ctx->r2 & 0X200;
    // 0x800AABB4: beq         $v0, $zero, L_800AABD8
    if (ctx->r2 == 0) {
        // 0x800AABB8: addiu       $a2, $s5, -0x3A68
        ctx->r6 = ADD32(ctx->r21, -0X3A68);
            goto L_800AABD8;
    }
    // 0x800AABB8: addiu       $a2, $s5, -0x3A68
    ctx->r6 = ADD32(ctx->r21, -0X3A68);
    // 0x800AABBC: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x800AABC0: jal         0x80054500
    // 0x800AABC4: nop

    func_80054500(rdram, ctx);
        goto after_62;
    // 0x800AABC4: nop

    after_62:
    // 0x800AABC8: lw          $v1, -0x25A4($s3)
    ctx->r3 = MEM_W(ctx->r19, -0X25A4);
    // 0x800AABCC: addu        $v1, $s0, $v1
    ctx->r3 = ADD32(ctx->r16, ctx->r3);
    // 0x800AABD0: sw          $v0, 0x20C($v1)
    MEM_W(0X20C, ctx->r3) = ctx->r2;
    // 0x800AABD4: addiu       $a2, $s5, -0x3A68
    ctx->r6 = ADD32(ctx->r21, -0X3A68);
L_800AABD8:
    // 0x800AABD8: addu        $v0, $s2, $s6
    ctx->r2 = ADD32(ctx->r18, ctx->r22);
    // 0x800AABDC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800AABE0: lw          $a0, -0x25A4($s3)
    ctx->r4 = MEM_W(ctx->r19, -0X25A4);
    // 0x800AABE4: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800AABE8: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // 0x800AABEC: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800AABF0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800AABF4: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x800AABF8: lhu         $a1, 0x0($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X0);
    // 0x800AABFC: jal         0x800AE088
    // 0x800AAC00: addiu       $s0, $s0, 0x278
    ctx->r16 = ADD32(ctx->r16, 0X278);
    hangarInitializeShipShadowHob(rdram, ctx);
        goto after_63;
    // 0x800AAC00: addiu       $s0, $s0, 0x278
    ctx->r16 = ADD32(ctx->r16, 0X278);
    after_63:
    // 0x800AAC04: addu        $v0, $s1, $s4
    ctx->r2 = ADD32(ctx->r17, ctx->r20);
    // 0x800AAC08: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800AAC0C: sltiu       $v0, $s2, 0x9
    ctx->r2 = ctx->r18 < 0X9 ? 1 : 0;
    // 0x800AAC10: bne         $v0, $zero, L_800AABA4
    if (ctx->r2 != 0) {
        // 0x800AAC14: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800AABA4;
    }
    // 0x800AAC14: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800AAC18: jal         0x80061A88
    // 0x800AAC1C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80061A88(rdram, ctx);
        goto after_64;
    // 0x800AAC1C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_64:
    // 0x800AAC20: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AAC24: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x800AAC28: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800AAC2C: lw          $a0, -0x2998($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X2998);
    // 0x800AAC30: jal         0x800613C0
    // 0x800AAC34: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    func_800613C0(rdram, ctx);
        goto after_65;
    // 0x800AAC34: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_65:
    // 0x800AAC38: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800AAC3C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x800AAC40: lw          $a0, -0x2998($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X2998);
    // 0x800AAC44: jal         0x800613C0
    // 0x800AAC48: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    func_800613C0(rdram, ctx);
        goto after_66;
    // 0x800AAC48: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_66:
    // 0x800AAC4C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800AAC50: jal         0x80063C6C
    // 0x800AAC54: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80063C6C(rdram, ctx);
        goto after_67;
    // 0x800AAC54: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_67:
    // 0x800AAC58: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800AAC5C: jal         0x80063C6C
    // 0x800AAC60: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80063C6C(rdram, ctx);
        goto after_68;
    // 0x800AAC60: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_68:
    // 0x800AAC64: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800AAC68: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    // 0x800AAC6C: jal         0x80063E2C
    // 0x800AAC70: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80063E2C(rdram, ctx);
        goto after_69;
    // 0x800AAC70: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_69:
    // 0x800AAC74: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800AAC78: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800AAC7C: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800AAC80: jal         0x80063E54
    // 0x800AAC84: addiu       $a2, $a2, -0x3A70
    ctx->r6 = ADD32(ctx->r6, -0X3A70);
    func_80063E54(rdram, ctx);
        goto after_70;
    // 0x800AAC84: addiu       $a2, $a2, -0x3A70
    ctx->r6 = ADD32(ctx->r6, -0X3A70);
    after_70:
    // 0x800AAC88: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800AAC8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800AAC90: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800AAC94: addiu       $s0, $s0, -0x3A6C
    ctx->r16 = ADD32(ctx->r16, -0X3A6C);
    // 0x800AAC98: jal         0x80063E54
    // 0x800AAC9C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80063E54(rdram, ctx);
        goto after_71;
    // 0x800AAC9C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_71:
    // 0x800AACA0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800AACA4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800AACA8: jal         0x80063E54
    // 0x800AACAC: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80063E54(rdram, ctx);
        goto after_72;
    // 0x800AACAC: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_72:
    // 0x800AACB0: jal         0x8005589C
    // 0x800AACB4: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    getGameOrFrontText(rdram, ctx);
        goto after_73;
    // 0x800AACB4: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    after_73:
    // 0x800AACB8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800AACBC: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800AACC0: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x800AACC4: addiu       $a3, $zero, -0x100
    ctx->r7 = ADD32(0, -0X100);
    // 0x800AACC8: addiu       $v0, $zero, -0xA3
    ctx->r2 = ADD32(0, -0XA3);
    // 0x800AACCC: jal         0x80063CFC
    // 0x800AACD0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80063CFC(rdram, ctx);
        goto after_74;
    // 0x800AACD0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_74:
    // 0x800AACD4: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800AACD8: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x800AACDC: lbu         $v0, -0x291C($s2)
    ctx->r2 = MEM_BU(ctx->r18, -0X291C);
    // 0x800AACE0: addiu       $s1, $s1, -0x3C08
    ctx->r17 = ADD32(ctx->r17, -0X3C08);
    // 0x800AACE4: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x800AACE8: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x800AACEC: jal         0x8005589C
    // 0x800AACF0: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    getGameOrFrontText(rdram, ctx);
        goto after_75;
    // 0x800AACF0: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_75:
    // 0x800AACF4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800AACF8: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800AACFC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800AAD00: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800AAD04: addiu       $v0, $zero, -0x100
    ctx->r2 = ADD32(0, -0X100);
    // 0x800AAD08: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800AAD0C: addiu       $v0, $zero, 0x75
    ctx->r2 = ADD32(0, 0X75);
    // 0x800AAD10: jal         0x800625C4
    // 0x800AAD14: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_800625C4(rdram, ctx);
        goto after_76;
    // 0x800AAD14: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_76:
    // 0x800AAD18: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800AAD1C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AAD20: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800AAD24: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AAD28: jal         0x80063E54
    // 0x800AAD2C: sw          $v0, -0x2994($v1)
    MEM_W(-0X2994, ctx->r3) = ctx->r2;
    func_80063E54(rdram, ctx);
        goto after_77;
    // 0x800AAD2C: sw          $v0, -0x2994($v1)
    MEM_W(-0X2994, ctx->r3) = ctx->r2;
    after_77:
    // 0x800AAD30: jal         0x8005589C
    // 0x800AAD34: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    getGameOrFrontText(rdram, ctx);
        goto after_78;
    // 0x800AAD34: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    after_78:
    // 0x800AAD38: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800AAD3C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800AAD40: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800AAD44: addiu       $a3, $zero, -0x100
    ctx->r7 = ADD32(0, -0X100);
    // 0x800AAD48: addiu       $v0, $zero, -0x82
    ctx->r2 = ADD32(0, -0X82);
    // 0x800AAD4C: jal         0x80063CFC
    // 0x800AAD50: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80063CFC(rdram, ctx);
        goto after_79;
    // 0x800AAD50: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_79:
    // 0x800AAD54: lbu         $v0, -0x291C($s2)
    ctx->r2 = MEM_BU(ctx->r18, -0X291C);
    // 0x800AAD58: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x800AAD5C: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x800AAD60: jal         0x800AEB48
    // 0x800AAD64: andi        $a0, $fp, 0xFF
    ctx->r4 = ctx->r30 & 0XFF;
    func_800AEB48(rdram, ctx);
        goto after_80;
    // 0x800AAD64: andi        $a0, $fp, 0xFF
    ctx->r4 = ctx->r30 & 0XFF;
    after_80:
    // 0x800AAD68: lw          $ra, 0xCC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XCC);
    // 0x800AAD6C: lw          $fp, 0xC8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XC8);
    // 0x800AAD70: lw          $s7, 0xC4($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XC4);
    // 0x800AAD74: lw          $s6, 0xC0($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XC0);
    // 0x800AAD78: lw          $s5, 0xBC($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XBC);
    // 0x800AAD7C: lw          $s4, 0xB8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XB8);
    // 0x800AAD80: lw          $s3, 0xB4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XB4);
    // 0x800AAD84: lw          $s2, 0xB0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XB0);
    // 0x800AAD88: lw          $s1, 0xAC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XAC);
    // 0x800AAD8C: lw          $s0, 0xA8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA8);
    // 0x800AAD90: ldc1        $f20, 0xD0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XD0);
    // 0x800AAD94: jr          $ra
    // 0x800AAD98: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x800AAD98: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void func_800A959C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A959C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800A95A0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800A95A4: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800A95A8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800A95AC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800A95B0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800A95B4: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x800A95B8: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x800A95BC: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x800A95C0: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800A95C4: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800A95C8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800A95CC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800A95D0: lhu         $v1, 0x4E($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4E);
    // 0x800A95D4: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A95D8: sw          $zero, 0x1EE4($v0)
    MEM_W(0X1EE4, ctx->r2) = 0;
    // 0x800A95DC: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A95E0: beq         $v1, $zero, L_800A9618
    if (ctx->r3 == 0) {
        // 0x800A95E4: sw          $zero, 0x1EE0($v0)
        MEM_W(0X1EE0, ctx->r2) = 0;
            goto L_800A9618;
    }
    // 0x800A95E4: sw          $zero, 0x1EE0($v0)
    MEM_W(0X1EE0, ctx->r2) = 0;
    // 0x800A95E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A95EC: addu        $v1, $s2, $zero
    ctx->r3 = ADD32(ctx->r18, 0);
L_800A95F0:
    // 0x800A95F0: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x800A95F4: bne         $v0, $a0, L_800A9604
    if (ctx->r2 != ctx->r4) {
        // 0x800A95F8: nop
    
            goto L_800A9604;
    }
    // 0x800A95F8: nop

    // 0x800A95FC: lhu         $v0, 0x62($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X62);
    // 0x800A9600: sw          $v0, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->r2;
L_800A9604:
    // 0x800A9604: lhu         $v0, 0x4E($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X4E);
    // 0x800A9608: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800A960C: sltu        $v0, $s1, $v0
    ctx->r2 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x800A9610: bne         $v0, $zero, L_800A95F0
    if (ctx->r2 != 0) {
        // 0x800A9614: addiu       $v1, $v1, 0x18
        ctx->r3 = ADD32(ctx->r3, 0X18);
            goto L_800A95F0;
    }
    // 0x800A9614: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
L_800A9618:
    // 0x800A9618: lhu         $v0, 0x4E($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X4E);
    // 0x800A961C: beq         $v0, $zero, L_800A9820
    if (ctx->r2 == 0) {
        // 0x800A9620: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_800A9820;
    }
    // 0x800A9620: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800A9624: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800A9628: lui         $fp, 0x1
    ctx->r30 = S32(0X1 << 16);
    // 0x800A962C: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A9630: addiu       $s4, $v0, -0x84C
    ctx->r20 = ADD32(ctx->r2, -0X84C);
    // 0x800A9634: lui         $s7, 0x2
    ctx->r23 = S32(0X2 << 16);
    // 0x800A9638: addiu       $s5, $zero, 0x58
    ctx->r21 = ADD32(0, 0X58);
L_800A963C:
    // 0x800A963C: addu        $s3, $s2, $s5
    ctx->r19 = ADD32(ctx->r18, ctx->r21);
    // 0x800A9640: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800A9644: bne         $v0, $s6, L_800A980C
    if (ctx->r2 != ctx->r22) {
        // 0x800A9648: nop
    
            goto L_800A980C;
    }
    // 0x800A9648: nop

    // 0x800A964C: lw          $v1, 0x8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X8);
    // 0x800A9650: and         $v0, $v1, $fp
    ctx->r2 = ctx->r3 & ctx->r30;
    // 0x800A9654: bne         $v0, $zero, L_800A9768
    if (ctx->r2 != 0) {
        // 0x800A9658: and         $v0, $v1, $s7
        ctx->r2 = ctx->r3 & ctx->r23;
            goto L_800A9768;
    }
    // 0x800A9658: and         $v0, $v1, $s7
    ctx->r2 = ctx->r3 & ctx->r23;
    // 0x800A965C: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x800A9660: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A9664: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x800A9668: lhu         $s0, 0x0($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0X0);
    // 0x800A966C: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // 0x800A9670: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800A9674: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
L_800A9678:
    // 0x800A9678: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A967C: addu        $v1, $v0, $s4
    ctx->r3 = ADD32(ctx->r2, ctx->r20);
    // 0x800A9680: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800A9684: bne         $v0, $s0, L_800A9698
    if (ctx->r2 != ctx->r16) {
        // 0x800A9688: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800A9698;
    }
    // 0x800A9688: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A968C: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
    // 0x800A9690: j           L_800A96AC
    // 0x800A9694: andi        $s0, $a0, 0xFFFF
    ctx->r16 = ctx->r4 & 0XFFFF;
        goto L_800A96AC;
    // 0x800A9694: andi        $s0, $a0, 0xFFFF
    ctx->r16 = ctx->r4 & 0XFFFF;
L_800A9698:
    // 0x800A9698: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x800A969C: sltiu       $v0, $v0, 0x5E
    ctx->r2 = ctx->r2 < 0X5E ? 1 : 0;
    // 0x800A96A0: bne         $v0, $zero, L_800A9678
    if (ctx->r2 != 0) {
        // 0x800A96A4: andi        $v0, $a1, 0xFFFF
        ctx->r2 = ctx->r5 & 0XFFFF;
            goto L_800A9678;
    }
    // 0x800A96A4: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x800A96A8: andi        $s0, $a0, 0xFFFF
    ctx->r16 = ctx->r4 & 0XFFFF;
L_800A96AC:
    // 0x800A96AC: jal         0x80066918
    // 0x800A96B0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80066918(rdram, ctx);
        goto after_0;
    // 0x800A96B0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x800A96B4: addiu       $a2, $s1, 0x1
    ctx->r6 = ADD32(ctx->r17, 0X1);
    // 0x800A96B8: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A96BC: lw          $v1, 0x1EE0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1EE0);
    // 0x800A96C0: lhu         $a0, 0x4E($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X4E);
    // 0x800A96C4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800A96C8: sltu        $a0, $a2, $a0
    ctx->r4 = ctx->r6 < ctx->r4 ? 1 : 0;
    // 0x800A96CC: beq         $a0, $zero, L_800A9760
    if (ctx->r4 == 0) {
        // 0x800A96D0: sw          $v1, 0x1EE0($v0)
        MEM_W(0X1EE0, ctx->r2) = ctx->r3;
            goto L_800A9760;
    }
    // 0x800A96D0: sw          $v1, 0x1EE0($v0)
    MEM_W(0X1EE0, ctx->r2) = ctx->r3;
    // 0x800A96D4: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800A96D8: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800A96DC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800A96E0: addu        $a1, $v0, $s2
    ctx->r5 = ADD32(ctx->r2, ctx->r18);
L_800A96E4:
    // 0x800A96E4: lw          $v0, 0x58($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X58);
    // 0x800A96E8: bne         $v0, $s6, L_800A974C
    if (ctx->r2 != ctx->r22) {
        // 0x800A96EC: ori         $a3, $zero, 0xFFFF
        ctx->r7 = 0 | 0XFFFF;
            goto L_800A974C;
    }
    // 0x800A96EC: ori         $a3, $zero, 0xFFFF
    ctx->r7 = 0 | 0XFFFF;
    // 0x800A96F0: lhu         $v0, 0x62($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X62);
    // 0x800A96F4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800A96F8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A96FC: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x800A9700: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
    // 0x800A9704: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
L_800A9708:
    // 0x800A9708: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A970C: addu        $v1, $v0, $s4
    ctx->r3 = ADD32(ctx->r2, ctx->r20);
    // 0x800A9710: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800A9714: bnel        $v0, $t0, L_800A9728
    if (ctx->r2 != ctx->r8) {
        // 0x800A9718: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800A9728;
    }
    goto skip_0;
    // 0x800A9718: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x800A971C: lhu         $a3, 0x2($v1)
    ctx->r7 = MEM_HU(ctx->r3, 0X2);
    // 0x800A9720: j           L_800A9738
    // 0x800A9724: nop

        goto L_800A9738;
    // 0x800A9724: nop

L_800A9728:
    // 0x800A9728: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800A972C: sltiu       $v0, $v0, 0x5E
    ctx->r2 = ctx->r2 < 0X5E ? 1 : 0;
    // 0x800A9730: bne         $v0, $zero, L_800A9708
    if (ctx->r2 != 0) {
        // 0x800A9734: andi        $v0, $a0, 0xFFFF
        ctx->r2 = ctx->r4 & 0XFFFF;
            goto L_800A9708;
    }
    // 0x800A9734: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
L_800A9738:
    // 0x800A9738: bne         $a3, $s0, L_800A974C
    if (ctx->r7 != ctx->r16) {
        // 0x800A973C: nop
    
            goto L_800A974C;
    }
    // 0x800A973C: nop

    // 0x800A9740: lw          $v0, 0x60($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X60);
    // 0x800A9744: or          $v0, $v0, $fp
    ctx->r2 = ctx->r2 | ctx->r30;
    // 0x800A9748: sw          $v0, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->r2;
L_800A974C:
    // 0x800A974C: lhu         $v0, 0x4E($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X4E);
    // 0x800A9750: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800A9754: sltu        $v0, $a2, $v0
    ctx->r2 = ctx->r6 < ctx->r2 ? 1 : 0;
    // 0x800A9758: bne         $v0, $zero, L_800A96E4
    if (ctx->r2 != 0) {
        // 0x800A975C: addiu       $a1, $a1, 0x18
        ctx->r5 = ADD32(ctx->r5, 0X18);
            goto L_800A96E4;
    }
    // 0x800A975C: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
L_800A9760:
    // 0x800A9760: lw          $v1, 0x8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X8);
    // 0x800A9764: and         $v0, $v1, $s7
    ctx->r2 = ctx->r3 & ctx->r23;
L_800A9768:
    // 0x800A9768: bne         $v0, $zero, L_800A980C
    if (ctx->r2 != 0) {
        // 0x800A976C: andi        $v0, $v1, 0xFFFF
        ctx->r2 = ctx->r3 & 0XFFFF;
            goto L_800A980C;
    }
    // 0x800A976C: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x800A9770: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A9774: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x800A9778: lhu         $s0, 0x0($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0X0);
    // 0x800A977C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800A9780: lw          $a0, -0x76E0($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X76E0);
    // 0x800A9784: jal         0x8006657C
    // 0x800A9788: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8006657C(rdram, ctx);
        goto after_1;
    // 0x800A9788: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800A978C: lui         $t1, 0x800B
    ctx->r9 = S32(0X800B << 16);
    // 0x800A9790: addiu       $a2, $s1, 0x1
    ctx->r6 = ADD32(ctx->r17, 0X1);
    // 0x800A9794: lw          $v1, 0x1EE4($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X1EE4);
    // 0x800A9798: lui         $t1, 0x800B
    ctx->r9 = S32(0X800B << 16);
    // 0x800A979C: addiu       $t1, $t1, 0x1EA0
    ctx->r9 = ADD32(ctx->r9, 0X1EA0);
    // 0x800A97A0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A97A4: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800A97A8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800A97AC: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x800A97B0: lhu         $v0, 0x4E($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X4E);
    // 0x800A97B4: lui         $t1, 0x800B
    ctx->r9 = S32(0X800B << 16);
    // 0x800A97B8: sltu        $v0, $a2, $v0
    ctx->r2 = ctx->r6 < ctx->r2 ? 1 : 0;
    // 0x800A97BC: beq         $v0, $zero, L_800A980C
    if (ctx->r2 == 0) {
        // 0x800A97C0: sw          $v1, 0x1EE4($t1)
        MEM_W(0X1EE4, ctx->r9) = ctx->r3;
            goto L_800A980C;
    }
    // 0x800A97C0: sw          $v1, 0x1EE4($t1)
    MEM_W(0X1EE4, ctx->r9) = ctx->r3;
    // 0x800A97C4: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800A97C8: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800A97CC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800A97D0: addu        $a1, $v0, $s2
    ctx->r5 = ADD32(ctx->r2, ctx->r18);
L_800A97D4:
    // 0x800A97D4: lw          $v0, 0x58($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X58);
    // 0x800A97D8: bne         $v0, $s6, L_800A97F8
    if (ctx->r2 != ctx->r22) {
        // 0x800A97DC: nop
    
            goto L_800A97F8;
    }
    // 0x800A97DC: nop

    // 0x800A97E0: lw          $a0, 0x60($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X60);
    // 0x800A97E4: lhu         $v1, 0xA($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0XA);
    // 0x800A97E8: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800A97EC: bne         $v0, $v1, L_800A97F8
    if (ctx->r2 != ctx->r3) {
        // 0x800A97F0: or          $v0, $a0, $s7
        ctx->r2 = ctx->r4 | ctx->r23;
            goto L_800A97F8;
    }
    // 0x800A97F0: or          $v0, $a0, $s7
    ctx->r2 = ctx->r4 | ctx->r23;
    // 0x800A97F4: sw          $v0, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->r2;
L_800A97F8:
    // 0x800A97F8: lhu         $v0, 0x4E($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X4E);
    // 0x800A97FC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800A9800: sltu        $v0, $a2, $v0
    ctx->r2 = ctx->r6 < ctx->r2 ? 1 : 0;
    // 0x800A9804: bne         $v0, $zero, L_800A97D4
    if (ctx->r2 != 0) {
        // 0x800A9808: addiu       $a1, $a1, 0x18
        ctx->r5 = ADD32(ctx->r5, 0X18);
            goto L_800A97D4;
    }
    // 0x800A9808: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
L_800A980C:
    // 0x800A980C: lhu         $v0, 0x4E($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X4E);
    // 0x800A9810: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800A9814: sltu        $v0, $s1, $v0
    ctx->r2 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x800A9818: bne         $v0, $zero, L_800A963C
    if (ctx->r2 != 0) {
        // 0x800A981C: addiu       $s5, $s5, 0x18
        ctx->r21 = ADD32(ctx->r21, 0X18);
            goto L_800A963C;
    }
    // 0x800A981C: addiu       $s5, $s5, 0x18
    ctx->r21 = ADD32(ctx->r21, 0X18);
L_800A9820:
    // 0x800A9820: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    // 0x800A9824: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x800A9828: jal         0x8008E0B0
    // 0x800A982C: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    func_8008E0B0(rdram, ctx);
        goto after_2;
    // 0x800A982C: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    after_2:
    // 0x800A9830: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    // 0x800A9834: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x800A9838: jal         0x8008E0B0
    // 0x800A983C: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    func_8008E0B0(rdram, ctx);
        goto after_3;
    // 0x800A983C: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    after_3:
    // 0x800A9840: lhu         $v0, 0x4E($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X4E);
    // 0x800A9844: beq         $v0, $zero, L_800A987C
    if (ctx->r2 == 0) {
        // 0x800A9848: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_800A987C;
    }
    // 0x800A9848: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800A984C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A9850: addu        $v1, $s2, $zero
    ctx->r3 = ADD32(ctx->r18, 0);
L_800A9854:
    // 0x800A9854: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x800A9858: bne         $v0, $a0, L_800A9868
    if (ctx->r2 != ctx->r4) {
        // 0x800A985C: nop
    
            goto L_800A9868;
    }
    // 0x800A985C: nop

    // 0x800A9860: lhu         $v0, 0x62($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X62);
    // 0x800A9864: sw          $v0, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->r2;
L_800A9868:
    // 0x800A9868: lhu         $v0, 0x4E($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X4E);
    // 0x800A986C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800A9870: sltu        $v0, $s1, $v0
    ctx->r2 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x800A9874: bne         $v0, $zero, L_800A9854
    if (ctx->r2 != 0) {
        // 0x800A9878: addiu       $v1, $v1, 0x18
        ctx->r3 = ADD32(ctx->r3, 0X18);
            goto L_800A9854;
    }
    // 0x800A9878: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
L_800A987C:
    // 0x800A987C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800A9880: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x800A9884: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x800A9888: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x800A988C: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800A9890: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800A9894: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800A9898: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800A989C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800A98A0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800A98A4: jr          $ra
    // 0x800A98A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800A98A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800A98AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A98AC: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800A98B0: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // 0x800A98B4: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x800A98B8: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x800A98BC: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x800A98C0: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x800A98C4: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x800A98C8: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x800A98CC: lhu         $v0, 0x4A($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X4A);
    // 0x800A98D0: beq         $v0, $zero, L_800A9A9C
    if (ctx->r2 == 0) {
        // 0x800A98D4: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_800A9A9C;
    }
    // 0x800A98D4: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800A98D8: lui         $s3, 0x800B
    ctx->r19 = S32(0X800B << 16);
    // 0x800A98DC: sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18 << 16);
L_800A98E0:
    // 0x800A98E0: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800A98E4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A98E8: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x800A98EC: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800A98F0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A98F4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A98F8: addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // 0x800A98FC: lbu         $v0, 0x13F7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X13F7);
    // 0x800A9900: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x800A9904: bne         $v0, $zero, L_800A9938
    if (ctx->r2 != 0) {
        // 0x800A9908: sll         $v0, $a0, 4
        ctx->r2 = S32(ctx->r4 << 4);
            goto L_800A9938;
    }
    // 0x800A9908: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x800A990C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A9910: lw          $v1, 0x1900($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X1900);
    // 0x800A9914: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A9918: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A991C: addiu       $a0, $v0, 0x88
    ctx->r4 = ADD32(ctx->r2, 0X88);
    // 0x800A9920: sw          $zero, 0x70($v0)
    MEM_W(0X70, ctx->r2) = 0;
    // 0x800A9924: sw          $zero, 0x74($v0)
    MEM_W(0X74, ctx->r2) = 0;
    // 0x800A9928: jal         0x8001CA50
    // 0x800A992C: sw          $zero, 0x78($v0)
    MEM_W(0X78, ctx->r2) = 0;
    func_8001CA50(rdram, ctx);
        goto after_0;
    // 0x800A992C: sw          $zero, 0x78($v0)
    MEM_W(0X78, ctx->r2) = 0;
    after_0:
    // 0x800A9930: j           L_800A9A80
    // 0x800A9934: addiu       $v0, $s2, 0x1
    ctx->r2 = ADD32(ctx->r18, 0X1);
        goto L_800A9A80;
    // 0x800A9934: addiu       $v0, $s2, 0x1
    ctx->r2 = ADD32(ctx->r18, 0X1);
L_800A9938:
    // 0x800A9938: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A993C: lw          $v1, 0x1900($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X1900);
    // 0x800A9940: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A9944: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A9948: lw          $v0, 0x50($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X50);
    // 0x800A994C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800A9950: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
    // 0x800A9954: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x800A9958: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800A995C: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x800A9960: beq         $v0, $zero, L_800A9990
    if (ctx->r2 == 0) {
        // 0x800A9964: addiu       $a2, $sp, 0x10
        ctx->r6 = ADD32(ctx->r29, 0X10);
            goto L_800A9990;
    }
    // 0x800A9964: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
L_800A9968:
    // 0x800A9968: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    // 0x800A996C: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x800A9970: sra         $v0, $v0, 14
    ctx->r2 = S32(SIGNED(ctx->r2) >> 14);
    // 0x800A9974: lw          $a1, 0x8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X8);
    // 0x800A9978: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x800A997C: addiu       $v1, $a1, 0x1C
    ctx->r3 = ADD32(ctx->r5, 0X1C);
    // 0x800A9980: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800A9984: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x800A9988: bne         $v0, $zero, L_800A9968
    if (ctx->r2 != 0) {
        // 0x800A998C: addu        $s0, $a0, $zero
        ctx->r16 = ADD32(ctx->r4, 0);
            goto L_800A9968;
    }
    // 0x800A998C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
L_800A9990:
    // 0x800A9990: addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
    // 0x800A9994: sll         $v1, $s2, 16
    ctx->r3 = S32(ctx->r18 << 16);
    // 0x800A9998: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800A999C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A99A0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A99A4: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800A99A8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A99AC: lw          $a0, 0x1900($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X1900);
    // 0x800A99B0: sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2 << 2);
    // 0x800A99B4: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // 0x800A99B8: jal         0x8001CA50
    // 0x800A99BC: addiu       $a0, $a0, 0x88
    ctx->r4 = ADD32(ctx->r4, 0X88);
    func_8001CA50(rdram, ctx);
        goto after_1;
    // 0x800A99BC: addiu       $a0, $a0, 0x88
    ctx->r4 = ADD32(ctx->r4, 0X88);
    after_1:
    // 0x800A99C0: sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17 << 16);
    // 0x800A99C4: bltz        $v0, L_800A9A44
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A99C8: sll         $v1, $s2, 16
        ctx->r3 = S32(ctx->r18 << 16);
            goto L_800A9A44;
    }
    // 0x800A99C8: sll         $v1, $s2, 16
    ctx->r3 = S32(ctx->r18 << 16);
L_800A99CC:
    // 0x800A99CC: lw          $v0, 0x1900($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X1900);
    // 0x800A99D0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800A99D4: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800A99D8: addiu       $v1, $v0, 0x88
    ctx->r3 = ADD32(ctx->r2, 0X88);
    // 0x800A99DC: addiu       $v0, $v0, 0xB8
    ctx->r2 = ADD32(ctx->r2, 0XB8);
L_800A99E0:
    // 0x800A99E0: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x800A99E4: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x800A99E8: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x800A99EC: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
    // 0x800A99F0: sw          $a3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r7;
    // 0x800A99F4: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x800A99F8: sw          $t1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r9;
    // 0x800A99FC: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
    // 0x800A9A00: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800A9A04: bne         $v1, $v0, L_800A99E0
    if (ctx->r3 != ctx->r2) {
        // 0x800A9A08: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_800A99E0;
    }
    // 0x800A9A08: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800A9A0C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800A9A10: sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17 << 16);
    // 0x800A9A14: sra         $v0, $v0, 14
    ctx->r2 = S32(SIGNED(ctx->r2) >> 14);
    // 0x800A9A18: addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // 0x800A9A1C: lw          $a2, 0x1900($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X1900);
    // 0x800A9A20: lw          $a1, 0x10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X10);
    // 0x800A9A24: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    // 0x800A9A28: jal         0x800191C4
    // 0x800A9A2C: addiu       $a2, $a2, 0x88
    ctx->r6 = ADD32(ctx->r6, 0X88);
    func_800191C4(rdram, ctx);
        goto after_2;
    // 0x800A9A2C: addiu       $a2, $a2, 0x88
    ctx->r6 = ADD32(ctx->r6, 0X88);
    after_2:
    // 0x800A9A30: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
    // 0x800A9A34: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800A9A38: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800A9A3C: bgez        $v0, L_800A99CC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A9A40: sll         $v1, $s2, 16
        ctx->r3 = S32(ctx->r18 << 16);
            goto L_800A99CC;
    }
    // 0x800A9A40: sll         $v1, $s2, 16
    ctx->r3 = S32(ctx->r18 << 16);
L_800A9A44:
    // 0x800A9A44: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800A9A48: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A9A4C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A9A50: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800A9A54: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800A9A58: lw          $v1, 0x1900($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X1900);
    // 0x800A9A5C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800A9A60: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800A9A64: lwc1        $f0, 0xAC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XAC);
    // 0x800A9A68: lwc1        $f2, 0xB0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XB0);
    // 0x800A9A6C: lwc1        $f4, 0xB4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XB4);
    // 0x800A9A70: swc1        $f0, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f0.u32l;
    // 0x800A9A74: swc1        $f2, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f2.u32l;
    // 0x800A9A78: swc1        $f4, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f4.u32l;
    // 0x800A9A7C: addiu       $v0, $s2, 0x1
    ctx->r2 = ADD32(ctx->r18, 0X1);
L_800A9A80:
    // 0x800A9A80: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x800A9A84: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800A9A88: lhu         $v1, 0x4A($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X4A);
    // 0x800A9A8C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800A9A90: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800A9A94: bne         $v0, $zero, L_800A98E0
    if (ctx->r2 != 0) {
        // 0x800A9A98: sll         $v0, $s2, 16
        ctx->r2 = S32(ctx->r18 << 16);
            goto L_800A98E0;
    }
    // 0x800A9A98: sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18 << 16);
L_800A9A9C:
    // 0x800A9A9C: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x800A9AA0: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x800A9AA4: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x800A9AA8: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x800A9AAC: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x800A9AB0: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x800A9AB4: jr          $ra
    // 0x800A9AB8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800A9AB8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_800A9ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9ABC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A9AC0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800A9AC4: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800A9AC8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800A9ACC: addiu       $a0, $a0, 0x960
    ctx->r4 = ADD32(ctx->r4, 0X960);
    // 0x800A9AD0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800A9AD4: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x800A9AD8: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x800A9ADC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800A9AE0: addiu       $s1, $v0, 0x7560
    ctx->r17 = ADD32(ctx->r2, 0X7560);
    // 0x800A9AE4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800A9AE8: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800A9AEC: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x800A9AF0: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x800A9AF4: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800A9AF8: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800A9AFC: jal         0x80018EF4
    // 0x800A9B00: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    zmemcpy(rdram, ctx);
        goto after_0;
    // 0x800A9B00: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    after_0:
    // 0x800A9B04: lui         $s5, 0x800B
    ctx->r21 = S32(0X800B << 16);
    // 0x800A9B08: addiu       $a1, $zero, 0x280
    ctx->r5 = ADD32(0, 0X280);
    // 0x800A9B0C: lui         $s3, 0x800B
    ctx->r19 = S32(0X800B << 16);
    // 0x800A9B10: addiu       $v0, $zero, 0xAA
    ctx->r2 = ADD32(0, 0XAA);
    // 0x800A9B14: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800A9B18: sh          $v0, 0x9B4($s3)
    MEM_H(0X9B4, ctx->r19) = ctx->r2;
    // 0x800A9B1C: addiu       $v0, $zero, 0x23
    ctx->r2 = ADD32(0, 0X23);
    // 0x800A9B20: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x800A9B24: sh          $v0, 0x9B8($a0)
    MEM_H(0X9B8, ctx->r4) = ctx->r2;
    // 0x800A9B28: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // 0x800A9B2C: bne         $s0, $v0, L_800A9B44
    if (ctx->r16 != ctx->r2) {
        // 0x800A9B30: sh          $a1, 0x9B2($s5)
        MEM_H(0X9B2, ctx->r21) = ctx->r5;
            goto L_800A9B44;
    }
    // 0x800A9B30: sh          $a1, 0x9B2($s5)
    MEM_H(0X9B2, ctx->r21) = ctx->r5;
    // 0x800A9B34: addiu       $v0, $zero, 0xE0
    ctx->r2 = ADD32(0, 0XE0);
    // 0x800A9B38: sh          $v0, 0x9B4($s3)
    MEM_H(0X9B4, ctx->r19) = ctx->r2;
    // 0x800A9B3C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800A9B40: sh          $v0, 0x9B8($a0)
    MEM_H(0X9B8, ctx->r4) = ctx->r2;
L_800A9B44:
    // 0x800A9B44: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A9B48: addiu       $t1, $v0, 0xB40
    ctx->r9 = ADD32(ctx->r2, 0XB40);
    // 0x800A9B4C: lw          $v0, 0x10($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X10);
    // 0x800A9B50: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800A9B54: beq         $v0, $zero, L_800A9B6C
    if (ctx->r2 == 0) {
        // 0x800A9B58: addiu       $v1, $zero, 0x154
        ctx->r3 = ADD32(0, 0X154);
            goto L_800A9B6C;
    }
    // 0x800A9B58: addiu       $v1, $zero, 0x154
    ctx->r3 = ADD32(0, 0X154);
    // 0x800A9B5C: lhu         $v0, 0x9B8($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X9B8);
    // 0x800A9B60: sh          $v1, 0x9B4($s3)
    MEM_H(0X9B4, ctx->r19) = ctx->r3;
    // 0x800A9B64: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800A9B68: sh          $v0, 0x9B8($a0)
    MEM_H(0X9B8, ctx->r4) = ctx->r2;
L_800A9B6C:
    // 0x800A9B6C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x800A9B70: sh          $v0, 0x16($s1)
    MEM_H(0X16, ctx->r17) = ctx->r2;
    // 0x800A9B74: sb          $v0, 0x20($s1)
    MEM_B(0X20, ctx->r17) = ctx->r2;
    // 0x800A9B78: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x800A9B7C: sb          $v0, 0x21($s1)
    MEM_B(0X21, ctx->r17) = ctx->r2;
    // 0x800A9B80: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800A9B84: sb          $v0, 0x22($s1)
    MEM_B(0X22, ctx->r17) = ctx->r2;
    // 0x800A9B88: addiu       $v0, $zero, 0x5622
    ctx->r2 = ADD32(0, 0X5622);
    // 0x800A9B8C: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    // 0x800A9B90: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800A9B94: sh          $a1, 0x12($s1)
    MEM_H(0X12, ctx->r17) = ctx->r5;
    // 0x800A9B98: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800A9B9C: addiu       $a1, $a1, 0x72C
    ctx->r5 = ADD32(ctx->r5, 0X72C);
    // 0x800A9BA0: lhu         $v1, 0x9B8($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X9B8);
    // 0x800A9BA4: lhu         $a2, 0x9B4($s3)
    ctx->r6 = MEM_HU(ctx->r19, 0X9B4);
    // 0x800A9BA8: andi        $a0, $s4, 0xFF
    ctx->r4 = ctx->r20 & 0XFF;
    // 0x800A9BAC: sb          $v0, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r2;
    // 0x800A9BB0: sh          $v1, 0x40($s1)
    MEM_H(0X40, ctx->r17) = ctx->r3;
    // 0x800A9BB4: sh          $v1, 0x42($s1)
    MEM_H(0X42, ctx->r17) = ctx->r3;
    // 0x800A9BB8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800A9BBC: sh          $a2, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r6;
    // 0x800A9BC0: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x800A9BC4: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x800A9BC8: sltiu       $v0, $v0, 0xF1
    ctx->r2 = ctx->r2 < 0XF1 ? 1 : 0;
    // 0x800A9BCC: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x800A9BD0: sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2 << 6);
    // 0x800A9BD4: sll         $v1, $s0, 3
    ctx->r3 = S32(ctx->r16 << 3);
    // 0x800A9BD8: sw          $v0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->r2;
    // 0x800A9BDC: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800A9BE0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800A9BE4: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800A9BE8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A9BEC: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800A9BF0: lhu         $v0, 0x6($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X6);
    // 0x800A9BF4: sll         $a3, $v0, 10
    ctx->r7 = S32(ctx->r2 << 10);
    // 0x800A9BF8: sw          $a3, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r7;
    // 0x800A9BFC: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x800A9C00: sll         $t0, $v0, 10
    ctx->r8 = S32(ctx->r2 << 10);
    // 0x800A9C04: sw          $t0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->r8;
    // 0x800A9C08: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x800A9C0C: sll         $a1, $v0, 10
    ctx->r5 = S32(ctx->r2 << 10);
    // 0x800A9C10: sw          $a1, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r5;
    // 0x800A9C14: lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X0);
    // 0x800A9C18: lbu         $a0, 0x23($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X23);
    // 0x800A9C1C: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800A9C20: sh          $a2, 0x9B6($v0)
    MEM_H(0X9B6, ctx->r2) = ctx->r6;
    // 0x800A9C24: beq         $a0, $zero, L_800A9C68
    if (ctx->r4 == 0) {
        // 0x800A9C28: sh          $v1, 0x3E($s1)
        MEM_H(0X3E, ctx->r17) = ctx->r3;
            goto L_800A9C68;
    }
    // 0x800A9C28: sh          $v1, 0x3E($s1)
    MEM_H(0X3E, ctx->r17) = ctx->r3;
    // 0x800A9C2C: lui         $v1, 0x2
    ctx->r3 = S32(0X2 << 16);
    // 0x800A9C30: addu        $v0, $a3, $v1
    ctx->r2 = ADD32(ctx->r7, ctx->r3);
    // 0x800A9C34: sw          $v0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r2;
    // 0x800A9C38: lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
    // 0x800A9C3C: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x800A9C40: sw          $v0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->r2;
    // 0x800A9C44: addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    // 0x800A9C48: sh          $v0, 0x3E($s1)
    MEM_H(0X3E, ctx->r17) = ctx->r2;
    // 0x800A9C4C: sh          $v0, 0x3C($s1)
    MEM_H(0X3C, ctx->r17) = ctx->r2;
    // 0x800A9C50: lw          $v0, 0x28($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X28);
    // 0x800A9C54: addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // 0x800A9C58: sw          $v1, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r3;
    // 0x800A9C5C: lui         $v1, 0x4
    ctx->r3 = S32(0X4 << 16);
    // 0x800A9C60: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800A9C64: sw          $v0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r2;
L_800A9C68:
    // 0x800A9C68: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
    // 0x800A9C6C: addiu       $a1, $s1, 0x2C
    ctx->r5 = ADD32(ctx->r17, 0X2C);
    // 0x800A9C70: jal         0x80001354
    // 0x800A9C74: addiu       $a2, $s1, 0x1C
    ctx->r6 = ADD32(ctx->r17, 0X1C);
    func_80001354(rdram, ctx);
        goto after_1;
    // 0x800A9C74: addiu       $a2, $s1, 0x1C
    ctx->r6 = ADD32(ctx->r17, 0X1C);
    after_1:
    // 0x800A9C78: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A9C7C: jal         0x800047F4
    // 0x800A9C80: addiu       $a0, $a0, 0x5408
    ctx->r4 = ADD32(ctx->r4, 0X5408);
    func_800047F4(rdram, ctx);
        goto after_2;
    // 0x800A9C80: addiu       $a0, $a0, 0x5408
    ctx->r4 = ADD32(ctx->r4, 0X5408);
    after_2:
    // 0x800A9C84: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800A9C88: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800A9C8C: jal         0x8003DF20
    // 0x800A9C90: sw          $v0, 0x7CFC($v1)
    MEM_W(0X7CFC, ctx->r3) = ctx->r2;
    func_8003DF20(rdram, ctx);
        goto after_3;
    // 0x800A9C90: sw          $v0, 0x7CFC($v1)
    MEM_W(0X7CFC, ctx->r3) = ctx->r2;
    after_3:
    // 0x800A9C94: jal         0x8003E560
    // 0x800A9C98: nop

    func_8003E560(rdram, ctx);
        goto after_4;
    // 0x800A9C98: nop

    after_4:
    // 0x800A9C9C: jal         0x8003FD54
    // 0x800A9CA0: nop

    func_8003FD54(rdram, ctx);
        goto after_5;
    // 0x800A9CA0: nop

    after_5:
    // 0x800A9CA4: jal         0x8005C5D0
    // 0x800A9CA8: nop

    func_8005C5D0(rdram, ctx);
        goto after_6;
    // 0x800A9CA8: nop

    after_6:
    // 0x800A9CAC: jal         0x800663B0
    // 0x800A9CB0: nop

    func_800663B0(rdram, ctx);
        goto after_7;
    // 0x800A9CB0: nop

    after_7:
    // 0x800A9CB4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A9CB8: jal         0x80055880
    // 0x800A9CBC: addiu       $a0, $a0, 0x5410
    ctx->r4 = ADD32(ctx->r4, 0X5410);
    loadGameOrFrontTxtFile(rdram, ctx);
        goto after_8;
    // 0x800A9CBC: addiu       $a0, $a0, 0x5410
    ctx->r4 = ADD32(ctx->r4, 0X5410);
    after_8:
    // 0x800A9CC0: jal         0x80055A30
    // 0x800A9CC4: nop

    func_80055A30(rdram, ctx);
        goto after_9;
    // 0x800A9CC4: nop

    after_9:
    // 0x800A9CC8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800A9CCC: jal         0x800561AC
    // 0x800A9CD0: addiu       $a1, $zero, -0x4
    ctx->r5 = ADD32(0, -0X4);
    func_800561AC(rdram, ctx);
        goto after_10;
    // 0x800A9CD0: addiu       $a1, $zero, -0x4
    ctx->r5 = ADD32(0, -0X4);
    after_10:
    // 0x800A9CD4: lhu         $v0, 0x9B2($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X9B2);
    // 0x800A9CD8: lhu         $v1, 0x9B4($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0X9B4);
    // 0x800A9CDC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9CE0: lwc1        $f0, 0x541C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X541C);
    // 0x800A9CE4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9CE8: lwc1        $f2, 0x5420($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5420);
    // 0x800A9CEC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9CF0: lwc1        $f4, 0x5424($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5424);
    // 0x800A9CF4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A9CF8: sw          $zero, 0x4($s2)
    MEM_W(0X4, ctx->r18) = 0;
    // 0x800A9CFC: sw          $zero, 0x8($s2)
    MEM_W(0X8, ctx->r18) = 0;
    // 0x800A9D00: sw          $zero, 0xC($s2)
    MEM_W(0XC, ctx->r18) = 0;
    // 0x800A9D04: sw          $v0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r2;
    // 0x800A9D08: srlv        $v0, $v0, $a0
    ctx->r2 = S32(U32(ctx->r2) >> (ctx->r4 & 31));
    // 0x800A9D0C: sw          $v1, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r3;
    // 0x800A9D10: srlv        $v1, $v1, $a0
    ctx->r3 = S32(U32(ctx->r3) >> (ctx->r4 & 31));
    // 0x800A9D14: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    // 0x800A9D18: sw          $v1, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r3;
    // 0x800A9D1C: swc1        $f0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f0.u32l;
    // 0x800A9D20: swc1        $f2, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f2.u32l;
    // 0x800A9D24: jal         0x8000E0BC
    // 0x800A9D28: swc1        $f4, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f4.u32l;
    func_8000E0BC(rdram, ctx);
        goto after_11;
    // 0x800A9D28: swc1        $f4, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f4.u32l;
    after_11:
    // 0x800A9D2C: jal         0x800645CC
    // 0x800A9D30: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800645CC(rdram, ctx);
        goto after_12;
    // 0x800A9D30: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_12:
    // 0x800A9D34: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800A9D38: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x800A9D3C: jal         0x800645CC
    // 0x800A9D40: sw          $v0, 0xAFC($v1)
    MEM_W(0XAFC, ctx->r3) = ctx->r2;
    func_800645CC(rdram, ctx);
        goto after_13;
    // 0x800A9D40: sw          $v0, 0xAFC($v1)
    MEM_W(0XAFC, ctx->r3) = ctx->r2;
    after_13:
    // 0x800A9D44: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x800A9D48: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800A9D4C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800A9D50: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800A9D54: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800A9D58: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800A9D5C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800A9D60: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x800A9D64: sw          $v0, 0xB00($v1)
    MEM_W(0XB00, ctx->r3) = ctx->r2;
    // 0x800A9D68: jr          $ra
    // 0x800A9D6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800A9D6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800A9B80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9B80: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800A9B84: sw          $ra, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r31;
    // 0x800A9B88: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x800A9B8C: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x800A9B90: sdc1        $f22, 0x78($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X78, ctx->r29);
    // 0x800A9B94: sdc1        $f20, 0x70($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X70, ctx->r29);
    // 0x800A9B98: lwc1        $f0, 0x24($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800A9B9C: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x800A9BA0: lwc1        $f0, 0x28($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800A9BA4: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x800A9BA8: lwc1        $f0, 0x2C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800A9BAC: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x800A9BB0: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800A9BB4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800A9BB8: lwc1        $f0, 0x14($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800A9BBC: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800A9BC0: lwc1        $f2, 0x20($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800A9BC4: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x800A9BC8: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800A9BCC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800A9BD0: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800A9BD4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x800A9BD8: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800A9BDC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800A9BE0: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A9BE4: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800A9BE8: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800A9BEC: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x800A9BF0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800A9BF4: lwc1        $f0, 0x18($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800A9BF8: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x800A9BFC: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x800A9C00: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x800A9C04: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x800A9C08: jal         0x8001CF2C
    // 0x800A9C0C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    func_8001CF2C(rdram, ctx);
        goto after_0;
    // 0x800A9C0C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800A9C10: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9C14: lwc1        $f2, 0x5140($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5140);
    // 0x800A9C18: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800A9C1C: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x800A9C20: nop

    // 0x800A9C24: bc1f        L_800A9C9C
    if (!c1cs) {
        // 0x800A9C28: nop
    
            goto L_800A9C9C;
    }
    // 0x800A9C28: nop

    // 0x800A9C2C: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800A9C30: jal         0x8001C400
    // 0x800A9C34: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_8001C400(rdram, ctx);
        goto after_1;
    // 0x800A9C34: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_1:
    // 0x800A9C38: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9C3C: lwc1        $f2, 0x5144($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5144);
    // 0x800A9C40: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800A9C44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800A9C48: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800A9C4C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800A9C50: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9C54: lwc1        $f2, 0x5148($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5148);
    // 0x800A9C58: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x800A9C5C: nop

    // 0x800A9C60: bc1t        L_800A9C6C
    if (c1cs) {
        // 0x800A9C64: sub.s       $f12, $f2, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_800A9C6C;
    }
    // 0x800A9C64: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800A9C68: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800A9C6C:
    // 0x800A9C6C: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800A9C70: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800A9C74: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800A9C78: nop

    // 0x800A9C7C: bc1t        L_800A9C88
    if (c1cs) {
        // 0x800A9C80: xor         $v0, $v0, $v1
        ctx->r2 = ctx->r2 ^ ctx->r3;
            goto L_800A9C88;
    }
    // 0x800A9C80: xor         $v0, $v0, $v1
    ctx->r2 = ctx->r2 ^ ctx->r3;
    // 0x800A9C84: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800A9C88:
    // 0x800A9C88: bnel        $v0, $v1, L_800A9C90
    if (ctx->r2 != ctx->r3) {
        // 0x800A9C8C: neg.s       $f12, $f12
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
            goto L_800A9C90;
    }
    goto skip_0;
    // 0x800A9C8C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    skip_0:
L_800A9C90:
    // 0x800A9C90: swc1        $f12, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f12.u32l;
    // 0x800A9C94: j           L_800A9CDC
    // 0x800A9C98: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
        goto L_800A9CDC;
    // 0x800A9C98: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
L_800A9C9C:
    // 0x800A9C9C: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800A9CA0: jal         0x8001C400
    // 0x800A9CA4: div.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f20.fl);
    func_8001C400(rdram, ctx);
        goto after_2;
    // 0x800A9CA4: div.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f20.fl);
    after_2:
    // 0x800A9CA8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9CAC: lwc1        $f2, 0x514C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X514C);
    // 0x800A9CB0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800A9CB4: lwc1        $f6, 0x10($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800A9CB8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800A9CBC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9CC0: lwc1        $f4, 0x5150($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5150);
    // 0x800A9CC4: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800A9CC8: nop

    // 0x800A9CCC: bc1f        L_800A9CD8
    if (!c1cs) {
        // 0x800A9CD0: sub.s       $f12, $f4, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f0.fl;
            goto L_800A9CD8;
    }
    // 0x800A9CD0: sub.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800A9CD4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
L_800A9CD8:
    // 0x800A9CD8: swc1        $f12, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f12.u32l;
L_800A9CDC:
    // 0x800A9CDC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9CE0: lwc1        $f0, 0x5154($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5154);
    // 0x800A9CE4: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800A9CE8: nop

    // 0x800A9CEC: bc1f        L_800A9D04
    if (!c1cs) {
        // 0x800A9CF0: addiu       $a0, $sp, 0x40
        ctx->r4 = ADD32(ctx->r29, 0X40);
            goto L_800A9D04;
    }
    // 0x800A9CF0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x800A9CF4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9CF8: lwc1        $f0, 0x5158($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5158);
    // 0x800A9CFC: j           L_800A9D54
    // 0x800A9D00: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
        goto L_800A9D54;
    // 0x800A9D00: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
L_800A9D04:
    // 0x800A9D04: jal         0x8001CFE8
    // 0x800A9D08: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8001CFE8(rdram, ctx);
        goto after_3;
    // 0x800A9D08: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_3:
    // 0x800A9D0C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9D10: lwc1        $f2, 0x515C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X515C);
    // 0x800A9D14: div.s       $f12, $f0, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800A9D18: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    // 0x800A9D1C: nop

    // 0x800A9D20: bc1f        L_800A9D30
    if (!c1cs) {
        // 0x800A9D24: nop
    
            goto L_800A9D30;
    }
    // 0x800A9D24: nop

    // 0x800A9D28: j           L_800A9D54
    // 0x800A9D2C: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
        goto L_800A9D54;
    // 0x800A9D2C: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
L_800A9D30:
    // 0x800A9D30: jal         0x8001C400
    // 0x800A9D34: nop

    func_8001C400(rdram, ctx);
        goto after_4;
    // 0x800A9D34: nop

    after_4:
    // 0x800A9D38: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9D3C: lwc1        $f2, 0x5160($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5160);
    // 0x800A9D40: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800A9D44: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9D48: lwc1        $f2, 0x5164($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5164);
    // 0x800A9D4C: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800A9D50: swc1        $f12, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f12.u32l;
L_800A9D54:
    // 0x800A9D54: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800A9D58: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800A9D5C: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x800A9D60: nop

    // 0x800A9D64: bc1f        L_800A9D78
    if (!c1cs) {
        // 0x800A9D68: addiu       $s0, $sp, 0x50
        ctx->r16 = ADD32(ctx->r29, 0X50);
            goto L_800A9D78;
    }
    // 0x800A9D68: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
    // 0x800A9D6C: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800A9D70: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800A9D74: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
L_800A9D78:
    // 0x800A9D78: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800A9D7C: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800A9D80: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800A9D84: swc1        $f22, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f22.u32l;
    // 0x800A9D88: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800A9D8C: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    // 0x800A9D90: jal         0x8001CF2C
    // 0x800A9D94: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    func_8001CF2C(rdram, ctx);
        goto after_5;
    // 0x800A9D94: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x800A9D98: cvt.d.s     $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f2.d = CVT_D_S(ctx->f20.fl);
    // 0x800A9D9C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9DA0: ldc1        $f4, 0x5168($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X5168);
    // 0x800A9DA4: c.le.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d <= ctx->f2.d;
    // 0x800A9DA8: nop

    // 0x800A9DAC: bc1f        L_800A9E54
    if (!c1cs) {
        // 0x800A9DB0: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_800A9E54;
    }
    // 0x800A9DB0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800A9DB4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800A9DB8: jal         0x8001CFE8
    // 0x800A9DBC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_8001CFE8(rdram, ctx);
        goto after_6;
    // 0x800A9DBC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_6:
    // 0x800A9DC0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9DC4: lwc1        $f2, 0x5170($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5170);
    // 0x800A9DC8: div.s       $f12, $f0, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800A9DCC: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    // 0x800A9DD0: nop

    // 0x800A9DD4: bc1f        L_800A9DE4
    if (!c1cs) {
        // 0x800A9DD8: nop
    
            goto L_800A9DE4;
    }
    // 0x800A9DD8: nop

    // 0x800A9DDC: j           L_800A9E30
    // 0x800A9DE0: swc1        $f22, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f22.u32l;
        goto L_800A9E30;
    // 0x800A9DE0: swc1        $f22, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f22.u32l;
L_800A9DE4:
    // 0x800A9DE4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9DE8: lwc1        $f0, 0x5174($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5174);
    // 0x800A9DEC: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x800A9DF0: nop

    // 0x800A9DF4: bc1f        L_800A9E0C
    if (!c1cs) {
        // 0x800A9DF8: nop
    
            goto L_800A9E0C;
    }
    // 0x800A9DF8: nop

    // 0x800A9DFC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9E00: lwc1        $f0, 0x5178($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5178);
    // 0x800A9E04: j           L_800A9E30
    // 0x800A9E08: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
        goto L_800A9E30;
    // 0x800A9E08: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
L_800A9E0C:
    // 0x800A9E0C: jal         0x8001C400
    // 0x800A9E10: nop

    func_8001C400(rdram, ctx);
        goto after_7;
    // 0x800A9E10: nop

    after_7:
    // 0x800A9E14: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9E18: lwc1        $f2, 0x517C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X517C);
    // 0x800A9E1C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800A9E20: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9E24: lwc1        $f2, 0x5180($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5180);
    // 0x800A9E28: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800A9E2C: swc1        $f2, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f2.u32l;
L_800A9E30:
    // 0x800A9E30: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800A9E34: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800A9E38: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800A9E3C: nop

    // 0x800A9E40: bc1f        L_800A9E54
    if (!c1cs) {
        // 0x800A9E44: nop
    
            goto L_800A9E54;
    }
    // 0x800A9E44: nop

    // 0x800A9E48: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800A9E4C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800A9E50: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
L_800A9E54:
    // 0x800A9E54: lw          $ra, 0x68($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X68);
    // 0x800A9E58: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x800A9E5C: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x800A9E60: ldc1        $f22, 0x78($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X78);
    // 0x800A9E64: ldc1        $f20, 0x70($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X70);
    // 0x800A9E68: jr          $ra
    // 0x800A9E6C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800A9E6C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_800A9D70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9D70: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x800A9D74: sw          $s6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r22;
    // 0x800A9D78: addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // 0x800A9D7C: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x800A9D80: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800A9D84: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800A9D88: sw          $ra, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r31;
    // 0x800A9D8C: sw          $fp, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r30;
    // 0x800A9D90: sw          $s7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r23;
    // 0x800A9D94: sw          $s5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r21;
    // 0x800A9D98: sw          $s4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r20;
    // 0x800A9D9C: sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // 0x800A9DA0: sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // 0x800A9DA4: sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // 0x800A9DA8: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x800A9DAC: sdc1        $f20, 0x90($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X90, ctx->r29);
    // 0x800A9DB0: jal         0x800078E0
    // 0x800A9DB4: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    rs_memset(rdram, ctx);
        goto after_0;
    // 0x800A9DB4: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_0:
    // 0x800A9DB8: lw          $t0, 0x98($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X98);
    // 0x800A9DBC: lhu         $v0, 0x4A($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X4A);
    // 0x800A9DC0: beq         $v0, $zero, L_800AA0C8
    if (ctx->r2 == 0) {
        // 0x800A9DC4: addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
            goto L_800AA0C8;
    }
    // 0x800A9DC4: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x800A9DC8: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x800A9DCC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9DD0: lwc1        $f20, 0x5428($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5428);
    // 0x800A9DD4: addiu       $s2, $zero, 0xF
    ctx->r18 = ADD32(0, 0XF);
    // 0x800A9DD8: addiu       $s3, $zero, 0x78
    ctx->r19 = ADD32(0, 0X78);
    // 0x800A9DDC: addiu       $fp, $zero, 0x64
    ctx->r30 = ADD32(0, 0X64);
    // 0x800A9DE0: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x800A9DE4: addiu       $s5, $zero, 0x7F
    ctx->r21 = ADD32(0, 0X7F);
    // 0x800A9DE8: addu        $s0, $s4, $zero
    ctx->r16 = ADD32(ctx->r20, 0);
L_800A9DEC:
    // 0x800A9DEC: lw          $v0, 0x1900($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1900);
    // 0x800A9DF0: addu        $v1, $s0, $v0
    ctx->r3 = ADD32(ctx->r16, ctx->r2);
    // 0x800A9DF4: lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X3);
    // 0x800A9DF8: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800A9DFC: beq         $v0, $zero, L_800AA0B0
    if (ctx->r2 == 0) {
        // 0x800A9E00: nop
    
            goto L_800AA0B0;
    }
    // 0x800A9E00: nop

    // 0x800A9E04: sb          $zero, 0x100($v1)
    MEM_B(0X100, ctx->r3) = 0;
    // 0x800A9E08: lw          $v0, 0x1900($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1900);
    // 0x800A9E0C: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800A9E10: lbu         $v1, 0x2($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X2);
    // 0x800A9E14: sltiu       $v0, $v1, 0x12
    ctx->r2 = ctx->r3 < 0X12 ? 1 : 0;
    // 0x800A9E18: beq         $v0, $zero, L_800AA0B0
    if (ctx->r2 == 0) {
        // 0x800A9E1C: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800AA0B0;
    }
    // 0x800A9E1C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800A9E20: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x800A9E24: addiu       $t1, $t1, 0x5430
    ctx->r9 = ADD32(ctx->r9, 0X5430);
    // 0x800A9E28: addu        $v0, $v0, $t1
    gpr jr_addend_800A9E30 = ctx->r2;
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800A9E2C: lw          $v0, 0x0($v0)
    ctx->r2 = ADD32(ctx->r2, 0X0);
    // 0x800A9E30: jr          $v0
    // 0x800A9E34: nop

    switch (jr_addend_800A9E30 >> 2) {
        case 0: goto L_800A9E38; break;
        case 1: goto L_800A9EB4; break;
        case 2: goto L_800A9EC8; break;
        case 3: goto L_800A9F04; break;
        case 4: goto L_800A9E74; break;
        case 5: goto L_800A9F4C; break;
        case 6: goto L_800A9F90; break;
        case 7: goto L_800A9FE4; break;
        case 8: goto L_800A9FE4; break;
        case 9: goto L_800A9FE4; break;
        case 10: goto L_800A9FE4; break;
        case 11: goto L_800AA0B0; break;
        case 12: goto L_800AA0B0; break;
        case 13: goto L_800AA0B0; break;
        case 14: goto L_800AA060; break;
        case 15: goto L_800AA008; break;
        case 16: goto L_800AA008; break;
        case 17: goto L_800AA008; break;
        default: switch_error(__func__, 0x800A9E30, 0x800A5430);
    }
    // 0x800A9E34: nop

L_800A9E38:
    // 0x800A9E38: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800A9E3C: lw          $a1, 0x1900($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1900);
    // 0x800A9E40: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x800A9E44: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800A9E48: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x800A9E4C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800A9E50: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800A9E54: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800A9E58: addu        $a1, $a1, $s0
    ctx->r5 = ADD32(ctx->r5, ctx->r16);
    // 0x800A9E5C: addiu       $a0, $a1, 0xBC
    ctx->r4 = ADD32(ctx->r5, 0XBC);
    // 0x800A9E60: jal         0x800989D8
    // 0x800A9E64: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    func_800989D8(rdram, ctx);
        goto after_1;
    // 0x800A9E64: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    after_1:
    // 0x800A9E68: lw          $v0, 0x1900($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1900);
    // 0x800A9E6C: j           L_800A9FD8
    // 0x800A9E70: addiu       $v1, $zero, 0x5A
    ctx->r3 = ADD32(0, 0X5A);
        goto L_800A9FD8;
    // 0x800A9E70: addiu       $v1, $zero, 0x5A
    ctx->r3 = ADD32(0, 0X5A);
L_800A9E74:
    // 0x800A9E74: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x800A9E78: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800A9E7C: lw          $a1, 0x1900($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1900);
    // 0x800A9E80: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // 0x800A9E84: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800A9E88: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x800A9E8C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800A9E90: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800A9E94: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800A9E98: addu        $a1, $a1, $s0
    ctx->r5 = ADD32(ctx->r5, ctx->r16);
    // 0x800A9E9C: addiu       $a0, $a1, 0xBC
    ctx->r4 = ADD32(ctx->r5, 0XBC);
    // 0x800A9EA0: jal         0x800989D8
    // 0x800A9EA4: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    func_800989D8(rdram, ctx);
        goto after_2;
    // 0x800A9EA4: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    after_2:
    // 0x800A9EA8: lw          $v0, 0x1900($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1900);
    // 0x800A9EAC: j           L_800A9FD8
    // 0x800A9EB0: addiu       $v1, $zero, 0x5A
    ctx->r3 = ADD32(0, 0X5A);
        goto L_800A9FD8;
    // 0x800A9EB0: addiu       $v1, $zero, 0x5A
    ctx->r3 = ADD32(0, 0X5A);
L_800A9EB4:
    // 0x800A9EB4: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x800A9EB8: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800A9EBC: lw          $a1, 0x1900($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1900);
    // 0x800A9EC0: j           L_800A9F14
    // 0x800A9EC4: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
        goto L_800A9F14;
    // 0x800A9EC4: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_800A9EC8:
    // 0x800A9EC8: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x800A9ECC: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800A9ED0: lw          $a1, 0x1900($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1900);
    // 0x800A9ED4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9ED8: lwc1        $f0, 0x5478($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5478);
    // 0x800A9EDC: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x800A9EE0: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x800A9EE4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800A9EE8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800A9EEC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800A9EF0: addu        $a1, $a1, $s0
    ctx->r5 = ADD32(ctx->r5, ctx->r16);
    // 0x800A9EF4: addiu       $a0, $a1, 0xBC
    ctx->r4 = ADD32(ctx->r5, 0XBC);
    // 0x800A9EF8: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    // 0x800A9EFC: j           L_800A9F34
    // 0x800A9F00: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
        goto L_800A9F34;
    // 0x800A9F00: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
L_800A9F04:
    // 0x800A9F04: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x800A9F08: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800A9F0C: lw          $a1, 0x1900($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1900);
    // 0x800A9F10: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_800A9F14:
    // 0x800A9F14: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800A9F18: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x800A9F1C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800A9F20: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800A9F24: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800A9F28: addu        $a1, $a1, $s0
    ctx->r5 = ADD32(ctx->r5, ctx->r16);
    // 0x800A9F2C: addiu       $a0, $a1, 0xBC
    ctx->r4 = ADD32(ctx->r5, 0XBC);
    // 0x800A9F30: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
L_800A9F34:
    // 0x800A9F34: jal         0x800989D8
    // 0x800A9F38: nop

    func_800989D8(rdram, ctx);
        goto after_3;
    // 0x800A9F38: nop

    after_3:
    // 0x800A9F3C: lw          $v0, 0x1900($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1900);
    // 0x800A9F40: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800A9F44: j           L_800AA0B0
    // 0x800A9F48: sb          $fp, 0x100($v0)
    MEM_B(0X100, ctx->r2) = ctx->r30;
        goto L_800AA0B0;
    // 0x800A9F48: sb          $fp, 0x100($v0)
    MEM_B(0X100, ctx->r2) = ctx->r30;
L_800A9F4C:
    // 0x800A9F4C: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x800A9F50: lui         $a3, 0x4140
    ctx->r7 = S32(0X4140 << 16);
    // 0x800A9F54: lw          $a1, 0x1900($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1900);
    // 0x800A9F58: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9F5C: lwc1        $f0, 0x547C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X547C);
    // 0x800A9F60: addiu       $v0, $zero, 0x2E
    ctx->r2 = ADD32(0, 0X2E);
    // 0x800A9F64: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x800A9F68: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800A9F6C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800A9F70: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800A9F74: addu        $a1, $a1, $s0
    ctx->r5 = ADD32(ctx->r5, ctx->r16);
    // 0x800A9F78: addiu       $a0, $a1, 0xBC
    ctx->r4 = ADD32(ctx->r5, 0XBC);
    // 0x800A9F7C: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    // 0x800A9F80: jal         0x800989D8
    // 0x800A9F84: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_4;
    // 0x800A9F84: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x800A9F88: j           L_800AA050
    // 0x800A9F8C: nop

        goto L_800AA050;
    // 0x800A9F8C: nop

L_800A9F90:
    // 0x800A9F90: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x800A9F94: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800A9F98: lw          $a1, 0x1900($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1900);
    // 0x800A9F9C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9FA0: lwc1        $f0, 0x5480($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5480);
    // 0x800A9FA4: addiu       $v0, $zero, 0x6F
    ctx->r2 = ADD32(0, 0X6F);
    // 0x800A9FA8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800A9FAC: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
    // 0x800A9FB0: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x800A9FB4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800A9FB8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800A9FBC: addu        $a1, $a1, $s0
    ctx->r5 = ADD32(ctx->r5, ctx->r16);
    // 0x800A9FC0: addiu       $a0, $a1, 0xBC
    ctx->r4 = ADD32(ctx->r5, 0XBC);
    // 0x800A9FC4: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    // 0x800A9FC8: jal         0x800989D8
    // 0x800A9FCC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_5;
    // 0x800A9FCC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x800A9FD0: lw          $v0, 0x1900($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1900);
    // 0x800A9FD4: addiu       $v1, $zero, 0x6E
    ctx->r3 = ADD32(0, 0X6E);
L_800A9FD8:
    // 0x800A9FD8: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800A9FDC: j           L_800AA0B0
    // 0x800A9FE0: sb          $v1, 0x100($v0)
    MEM_B(0X100, ctx->r2) = ctx->r3;
        goto L_800AA0B0;
    // 0x800A9FE0: sb          $v1, 0x100($v0)
    MEM_B(0X100, ctx->r2) = ctx->r3;
L_800A9FE4:
    // 0x800A9FE4: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x800A9FE8: lui         $a3, 0x41A8
    ctx->r7 = S32(0X41A8 << 16);
    // 0x800A9FEC: lw          $a1, 0x1900($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1900);
    // 0x800A9FF0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9FF4: lwc1        $f0, 0x5484($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5484);
    // 0x800A9FF8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800A9FFC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800AA000: j           L_800AA080
    // 0x800AA004: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
        goto L_800AA080;
    // 0x800AA004: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
L_800AA008:
    // 0x800AA008: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x800AA00C: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800AA010: lw          $a1, 0x1900($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1900);
    // 0x800AA014: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA018: lwc1        $f0, 0x5488($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5488);
    // 0x800AA01C: addiu       $v0, $zero, 0x39
    ctx->r2 = ADD32(0, 0X39);
    // 0x800AA020: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800AA024: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
    // 0x800AA028: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800AA02C: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x800AA030: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x800AA034: sw          $s7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r23;
    // 0x800AA038: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800AA03C: addu        $a1, $a1, $s0
    ctx->r5 = ADD32(ctx->r5, ctx->r16);
    // 0x800AA040: addiu       $a0, $a1, 0xBC
    ctx->r4 = ADD32(ctx->r5, 0XBC);
    // 0x800AA044: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    // 0x800AA048: jal         0x80098BDC
    // 0x800AA04C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80098BDC(rdram, ctx);
        goto after_6;
    // 0x800AA04C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_6:
L_800AA050:
    // 0x800AA050: lw          $v0, 0x1900($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1900);
    // 0x800AA054: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800AA058: j           L_800AA0B0
    // 0x800AA05C: sb          $s3, 0x100($v0)
    MEM_B(0X100, ctx->r2) = ctx->r19;
        goto L_800AA0B0;
    // 0x800AA05C: sb          $s3, 0x100($v0)
    MEM_B(0X100, ctx->r2) = ctx->r19;
L_800AA060:
    // 0x800AA060: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x800AA064: lui         $a3, 0x4208
    ctx->r7 = S32(0X4208 << 16);
    // 0x800AA068: lw          $a1, 0x1900($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1900);
    // 0x800AA06C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA070: lwc1        $f0, 0x548C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X548C);
    // 0x800AA074: addiu       $v0, $zero, 0x38
    ctx->r2 = ADD32(0, 0X38);
    // 0x800AA078: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800AA07C: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
L_800AA080:
    // 0x800AA080: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x800AA084: sw          $s7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r23;
    // 0x800AA088: sw          $s5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r21;
    // 0x800AA08C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800AA090: addu        $a1, $a1, $s0
    ctx->r5 = ADD32(ctx->r5, ctx->r16);
    // 0x800AA094: addiu       $a0, $a1, 0xBC
    ctx->r4 = ADD32(ctx->r5, 0XBC);
    // 0x800AA098: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    // 0x800AA09C: jal         0x80098BDC
    // 0x800AA0A0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80098BDC(rdram, ctx);
        goto after_7;
    // 0x800AA0A0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x800AA0A4: lw          $v0, 0x1900($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1900);
    // 0x800AA0A8: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800AA0AC: sb          $s5, 0x100($v0)
    MEM_B(0X100, ctx->r2) = ctx->r21;
L_800AA0B0:
    // 0x800AA0B0: lw          $t2, 0x98($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X98);
    // 0x800AA0B4: lhu         $v0, 0x4A($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X4A);
    // 0x800AA0B8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800AA0BC: sltu        $v0, $s4, $v0
    ctx->r2 = ctx->r20 < ctx->r2 ? 1 : 0;
    // 0x800AA0C0: bne         $v0, $zero, L_800A9DEC
    if (ctx->r2 != 0) {
        // 0x800AA0C4: addiu       $s0, $s0, 0x13C
        ctx->r16 = ADD32(ctx->r16, 0X13C);
            goto L_800A9DEC;
    }
    // 0x800AA0C4: addiu       $s0, $s0, 0x13C
    ctx->r16 = ADD32(ctx->r16, 0X13C);
L_800AA0C8:
    // 0x800AA0C8: lwc1        $f0, 0x24($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X24);
    // 0x800AA0CC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800AA0D0: lwc1        $f0, 0x28($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X28);
    // 0x800AA0D4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x800AA0D8: lwc1        $f0, 0x2C($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X2C);
    // 0x800AA0DC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800AA0E0: lwc1        $f0, 0x8($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X8);
    // 0x800AA0E4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800AA0E8: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800AA0EC: lwc1        $f0, 0x14($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X14);
    // 0x800AA0F0: addiu       $a0, $a0, 0x1A50
    ctx->r4 = ADD32(ctx->r4, 0X1A50);
    // 0x800AA0F4: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800AA0F8: lwc1        $f0, 0x20($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X20);
    // 0x800AA0FC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800AA100: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x800AA104: lwc1        $f0, 0x4($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800AA108: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x800AA10C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800AA110: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x800AA114: lwc1        $f0, 0x10($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X10);
    // 0x800AA118: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x800AA11C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800AA120: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800AA124: lwc1        $f0, 0x1C($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X1C);
    // 0x800AA128: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA12C: lwc1        $f2, 0x5490($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5490);
    // 0x800AA130: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800AA134: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x800AA138: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA13C: lwc1        $f0, 0x5494($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5494);
    // 0x800AA140: addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // 0x800AA144: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800AA148: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AA14C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800AA150: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x800AA154: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x800AA158: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800AA15C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800AA160: jal         0x8009912C
    // 0x800AA164: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8009912C(rdram, ctx);
        goto after_8;
    // 0x800AA164: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x800AA168: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
    // 0x800AA16C: lw          $fp, 0x88($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X88);
    // 0x800AA170: lw          $s7, 0x84($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X84);
    // 0x800AA174: lw          $s6, 0x80($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X80);
    // 0x800AA178: lw          $s5, 0x7C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X7C);
    // 0x800AA17C: lw          $s4, 0x78($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X78);
    // 0x800AA180: lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X74);
    // 0x800AA184: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x800AA188: lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6C);
    // 0x800AA18C: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x800AA190: ldc1        $f20, 0x90($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X90);
    // 0x800AA194: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800AA198: addiu       $t2, $v0, 0x1A40
    ctx->r10 = ADD32(ctx->r2, 0X1A40);
    // 0x800AA19C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800AA1A0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800AA1A4: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800AA1A8: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x800AA1AC: sw          $t0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r8;
    // 0x800AA1B0: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x800AA1B4: jr          $ra
    // 0x800AA1B8: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800AA1B8: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_800A9E70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9E70: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800A9E74: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800A9E78: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800A9E7C: sdc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X48, ctx->r29);
    // 0x800A9E80: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x800A9E84: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x800A9E88: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800A9E8C: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800A9E90: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A9E94: lwc1        $f24, 0x5184($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X5184);
    // 0x800A9E98: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800A9E9C: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x800A9EA0: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800A9EA4: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x800A9EA8: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800A9EAC: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x800A9EB0: lwc1        $f20, 0x0($a2)
    ctx->f20.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800A9EB4: mul.s       $f20, $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x800A9EB8: lwc1        $f22, 0x4($a2)
    ctx->f22.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800A9EBC: lwc1        $f26, 0x8($a2)
    ctx->f26.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800A9EC0: mul.s       $f22, $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f24.fl);
    // 0x800A9EC4: jal         0x8002B190
    // 0x800A9EC8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x800A9EC8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x800A9ECC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800A9ED0: jal         0x80033960
    // 0x800A9ED4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x800A9ED4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800A9ED8: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x800A9EDC: jal         0x8002B190
    // 0x800A9EE0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x800A9EE0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x800A9EE4: mul.s       $f26, $f26, $f24
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f24.fl);
    // 0x800A9EE8: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x800A9EEC: jal         0x80033960
    // 0x800A9EF0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x800A9EF0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x800A9EF4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800A9EF8: jal         0x8002B190
    // 0x800A9EFC: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    cosf_recomp(rdram, ctx);
        goto after_4;
    // 0x800A9EFC: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    after_4:
    // 0x800A9F00: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x800A9F04: jal         0x80033960
    // 0x800A9F08: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    sinf_recomp(rdram, ctx);
        goto after_5;
    // 0x800A9F08: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x800A9F0C: lwc1        $f10, 0x14($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800A9F10: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800A9F14: mul.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800A9F18: nop

    // 0x800A9F1C: mul.s       $f20, $f10, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800A9F20: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800A9F24: mul.s       $f14, $f4, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800A9F28: nop

    // 0x800A9F2C: mul.s       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800A9F30: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800A9F34: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x800A9F38: mul.s       $f8, $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800A9F3C: neg.s       $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = -ctx->f4.fl;
    // 0x800A9F40: mul.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800A9F44: nop

    // 0x800A9F48: mul.s       $f10, $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800A9F4C: nop

    // 0x800A9F50: mul.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x800A9F54: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800A9F58: mul.s       $f26, $f16, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f26.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800A9F5C: nop

    // 0x800A9F60: mul.s       $f24, $f20, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800A9F64: nop

    // 0x800A9F68: mul.s       $f22, $f14, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x800A9F6C: nop

    // 0x800A9F70: mul.s       $f2, $f18, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800A9F74: sub.s       $f18, $f18, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f26.fl;
    // 0x800A9F78: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800A9F7C: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x800A9F80: add.s       $f14, $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f24.fl;
    // 0x800A9F84: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x800A9F88: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x800A9F8C: add.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x800A9F90: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x800A9F94: swc1        $f12, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f12.u32l;
    // 0x800A9F98: sub.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x800A9F9C: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x800A9FA0: swc1        $f14, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f14.u32l;
    // 0x800A9FA4: swc1        $f20, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f20.u32l;
    // 0x800A9FA8: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    // 0x800A9FAC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800A9FB0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800A9FB4: ldc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X48);
    // 0x800A9FB8: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x800A9FBC: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x800A9FC0: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800A9FC4: jr          $ra
    // 0x800A9FC8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800A9FC8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800A9FCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9FCC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A9FD0: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800A9FD4: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x800A9FD8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800A9FDC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800A9FE0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800A9FE4: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800A9FE8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800A9FEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A9FF0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800A9FF4: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800A9FF8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800A9FFC: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800AA000: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x800AA004: nop

    // 0x800AA008: bc1f        L_800AA020
    if (!c1cs) {
        // 0x800AA00C: addu        $s2, $a3, $zero
        ctx->r18 = ADD32(ctx->r7, 0);
            goto L_800AA020;
    }
    // 0x800AA00C: addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    // 0x800AA010: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x800AA014: nop

    // 0x800AA018: bc1t        L_800AA040
    if (c1cs) {
        // 0x800AA01C: nop
    
            goto L_800AA040;
    }
    // 0x800AA01C: nop

L_800AA020:
    // 0x800AA020: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x800AA024: nop

    // 0x800AA028: bc1f        L_800AA064
    if (!c1cs) {
        // 0x800AA02C: nop
    
            goto L_800AA064;
    }
    // 0x800AA02C: nop

    // 0x800AA030: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x800AA034: nop

    // 0x800AA038: bc1f        L_800AA064
    if (!c1cs) {
        // 0x800AA03C: nop
    
            goto L_800AA064;
    }
    // 0x800AA03C: nop

L_800AA040:
    // 0x800AA040: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA044: lwc1        $f2, 0x5188($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5188);
    // 0x800AA048: add.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x800AA04C: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800AA050: sub.s       $f0, $f4, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x800AA054: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800AA058: add.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x800AA05C: j           L_800AA0F4
    // 0x800AA060: sub.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_800AA0F4;
    // 0x800AA060: sub.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f2.fl;
L_800AA064:
    // 0x800AA064: abs.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = fabsf(ctx->f12.fl);
    // 0x800AA068: abs.s       $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = fabsf(ctx->f4.fl);
    // 0x800AA06C: add.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800AA070: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA074: lwc1        $f0, 0x518C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X518C);
    // 0x800AA078: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800AA07C: nop

    // 0x800AA080: bc1f        L_800AA094
    if (!c1cs) {
        // 0x800AA084: nop
    
            goto L_800AA094;
    }
    // 0x800AA084: nop

    // 0x800AA088: mul.s       $f4, $f2, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x800AA08C: j           L_800AA0A4
    // 0x800AA090: nop

        goto L_800AA0A4;
    // 0x800AA090: nop

L_800AA094:
    // 0x800AA094: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA098: lwc1        $f0, 0x5190($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5190);
    // 0x800AA09C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800AA0A0: mul.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
L_800AA0A4:
    // 0x800AA0A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AA0A8: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800AA0AC: nop

    // 0x800AA0B0: bc1f        L_800AA0D8
    if (!c1cs) {
        // 0x800AA0B4: nop
    
            goto L_800AA0D8;
    }
    // 0x800AA0B4: nop

    // 0x800AA0B8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA0BC: lwc1        $f0, 0x5194($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5194);
    // 0x800AA0C0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800AA0C4: nop

    // 0x800AA0C8: bc1tl       L_800AA0F4
    if (c1cs) {
        // 0x800AA0CC: sub.s       $f20, $f12, $f4
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f12.fl - ctx->f4.fl;
            goto L_800AA0F4;
    }
    goto skip_0;
    // 0x800AA0CC: sub.s       $f20, $f12, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f12.fl - ctx->f4.fl;
    skip_0:
    // 0x800AA0D0: j           L_800AA0F4
    // 0x800AA0D4: add.s       $f20, $f12, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f12.fl + ctx->f4.fl;
        goto L_800AA0F4;
    // 0x800AA0D4: add.s       $f20, $f12, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f12.fl + ctx->f4.fl;
L_800AA0D8:
    // 0x800AA0D8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA0DC: lwc1        $f0, 0x5198($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5198);
    // 0x800AA0E0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800AA0E4: nop

    // 0x800AA0E8: bc1fl       L_800AA0F4
    if (!c1cs) {
        // 0x800AA0EC: sub.s       $f20, $f12, $f4
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f12.fl - ctx->f4.fl;
            goto L_800AA0F4;
    }
    goto skip_1;
    // 0x800AA0EC: sub.s       $f20, $f12, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f12.fl - ctx->f4.fl;
    skip_1:
    // 0x800AA0F0: add.s       $f20, $f12, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f12.fl + ctx->f4.fl;
L_800AA0F4:
    // 0x800AA0F4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA0F8: lwc1        $f14, 0x519C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X519C);
    // 0x800AA0FC: jal         0x8001E20C
    // 0x800AA100: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_8001E20C(rdram, ctx);
        goto after_0;
    // 0x800AA100: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x800AA104: swc1        $f20, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f20.u32l;
    // 0x800AA108: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800AA10C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AA110: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800AA114: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x800AA118: nop

    // 0x800AA11C: bc1f        L_800AA134
    if (!c1cs) {
        // 0x800AA120: nop
    
            goto L_800AA134;
    }
    // 0x800AA120: nop

    // 0x800AA124: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x800AA128: nop

    // 0x800AA12C: bc1t        L_800AA154
    if (c1cs) {
        // 0x800AA130: nop
    
            goto L_800AA154;
    }
    // 0x800AA130: nop

L_800AA134:
    // 0x800AA134: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x800AA138: nop

    // 0x800AA13C: bc1f        L_800AA178
    if (!c1cs) {
        // 0x800AA140: nop
    
            goto L_800AA178;
    }
    // 0x800AA140: nop

    // 0x800AA144: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x800AA148: nop

    // 0x800AA14C: bc1f        L_800AA178
    if (!c1cs) {
        // 0x800AA150: nop
    
            goto L_800AA178;
    }
    // 0x800AA150: nop

L_800AA154:
    // 0x800AA154: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA158: lwc1        $f2, 0x51A0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X51A0);
    // 0x800AA15C: add.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x800AA160: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800AA164: sub.s       $f0, $f4, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x800AA168: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800AA16C: add.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x800AA170: j           L_800AA208
    // 0x800AA174: sub.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_800AA208;
    // 0x800AA174: sub.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f2.fl;
L_800AA178:
    // 0x800AA178: abs.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = fabsf(ctx->f12.fl);
    // 0x800AA17C: abs.s       $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = fabsf(ctx->f4.fl);
    // 0x800AA180: add.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800AA184: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA188: lwc1        $f0, 0x51A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X51A4);
    // 0x800AA18C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800AA190: nop

    // 0x800AA194: bc1f        L_800AA1A8
    if (!c1cs) {
        // 0x800AA198: nop
    
            goto L_800AA1A8;
    }
    // 0x800AA198: nop

    // 0x800AA19C: mul.s       $f4, $f2, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x800AA1A0: j           L_800AA1B8
    // 0x800AA1A4: nop

        goto L_800AA1B8;
    // 0x800AA1A4: nop

L_800AA1A8:
    // 0x800AA1A8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA1AC: lwc1        $f0, 0x51A8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X51A8);
    // 0x800AA1B0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800AA1B4: mul.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
L_800AA1B8:
    // 0x800AA1B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AA1BC: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800AA1C0: nop

    // 0x800AA1C4: bc1f        L_800AA1EC
    if (!c1cs) {
        // 0x800AA1C8: nop
    
            goto L_800AA1EC;
    }
    // 0x800AA1C8: nop

    // 0x800AA1CC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA1D0: lwc1        $f0, 0x51AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X51AC);
    // 0x800AA1D4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800AA1D8: nop

    // 0x800AA1DC: bc1tl       L_800AA208
    if (c1cs) {
        // 0x800AA1E0: sub.s       $f20, $f12, $f4
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f12.fl - ctx->f4.fl;
            goto L_800AA208;
    }
    goto skip_2;
    // 0x800AA1E0: sub.s       $f20, $f12, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f12.fl - ctx->f4.fl;
    skip_2:
    // 0x800AA1E4: j           L_800AA208
    // 0x800AA1E8: add.s       $f20, $f12, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f12.fl + ctx->f4.fl;
        goto L_800AA208;
    // 0x800AA1E8: add.s       $f20, $f12, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f12.fl + ctx->f4.fl;
L_800AA1EC:
    // 0x800AA1EC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA1F0: lwc1        $f0, 0x51B0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X51B0);
    // 0x800AA1F4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800AA1F8: nop

    // 0x800AA1FC: bc1fl       L_800AA208
    if (!c1cs) {
        // 0x800AA200: sub.s       $f20, $f12, $f4
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f12.fl - ctx->f4.fl;
            goto L_800AA208;
    }
    goto skip_3;
    // 0x800AA200: sub.s       $f20, $f12, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f12.fl - ctx->f4.fl;
    skip_3:
    // 0x800AA204: add.s       $f20, $f12, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f12.fl + ctx->f4.fl;
L_800AA208:
    // 0x800AA208: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA20C: lwc1        $f14, 0x51B4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X51B4);
    // 0x800AA210: jal         0x8001E20C
    // 0x800AA214: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_8001E20C(rdram, ctx);
        goto after_1;
    // 0x800AA214: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x800AA218: swc1        $f20, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f20.u32l;
    // 0x800AA21C: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800AA220: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AA224: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800AA228: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x800AA22C: nop

    // 0x800AA230: bc1f        L_800AA248
    if (!c1cs) {
        // 0x800AA234: nop
    
            goto L_800AA248;
    }
    // 0x800AA234: nop

    // 0x800AA238: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x800AA23C: nop

    // 0x800AA240: bc1t        L_800AA268
    if (c1cs) {
        // 0x800AA244: nop
    
            goto L_800AA268;
    }
    // 0x800AA244: nop

L_800AA248:
    // 0x800AA248: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x800AA24C: nop

    // 0x800AA250: bc1f        L_800AA28C
    if (!c1cs) {
        // 0x800AA254: nop
    
            goto L_800AA28C;
    }
    // 0x800AA254: nop

    // 0x800AA258: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x800AA25C: nop

    // 0x800AA260: bc1f        L_800AA28C
    if (!c1cs) {
        // 0x800AA264: nop
    
            goto L_800AA28C;
    }
    // 0x800AA264: nop

L_800AA268:
    // 0x800AA268: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA26C: lwc1        $f2, 0x51B8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X51B8);
    // 0x800AA270: add.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x800AA274: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800AA278: sub.s       $f0, $f4, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x800AA27C: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800AA280: add.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x800AA284: j           L_800AA31C
    // 0x800AA288: sub.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_800AA31C;
    // 0x800AA288: sub.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f2.fl;
L_800AA28C:
    // 0x800AA28C: abs.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = fabsf(ctx->f12.fl);
    // 0x800AA290: abs.s       $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = fabsf(ctx->f4.fl);
    // 0x800AA294: add.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800AA298: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA29C: lwc1        $f0, 0x51BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X51BC);
    // 0x800AA2A0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800AA2A4: nop

    // 0x800AA2A8: bc1f        L_800AA2BC
    if (!c1cs) {
        // 0x800AA2AC: nop
    
            goto L_800AA2BC;
    }
    // 0x800AA2AC: nop

    // 0x800AA2B0: mul.s       $f4, $f2, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x800AA2B4: j           L_800AA2CC
    // 0x800AA2B8: nop

        goto L_800AA2CC;
    // 0x800AA2B8: nop

L_800AA2BC:
    // 0x800AA2BC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA2C0: lwc1        $f0, 0x51C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X51C0);
    // 0x800AA2C4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800AA2C8: mul.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
L_800AA2CC:
    // 0x800AA2CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AA2D0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800AA2D4: nop

    // 0x800AA2D8: bc1f        L_800AA300
    if (!c1cs) {
        // 0x800AA2DC: nop
    
            goto L_800AA300;
    }
    // 0x800AA2DC: nop

    // 0x800AA2E0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA2E4: lwc1        $f0, 0x51C4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X51C4);
    // 0x800AA2E8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800AA2EC: nop

    // 0x800AA2F0: bc1tl       L_800AA31C
    if (c1cs) {
        // 0x800AA2F4: sub.s       $f20, $f12, $f4
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f12.fl - ctx->f4.fl;
            goto L_800AA31C;
    }
    goto skip_4;
    // 0x800AA2F4: sub.s       $f20, $f12, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f12.fl - ctx->f4.fl;
    skip_4:
    // 0x800AA2F8: j           L_800AA31C
    // 0x800AA2FC: add.s       $f20, $f12, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f12.fl + ctx->f4.fl;
        goto L_800AA31C;
    // 0x800AA2FC: add.s       $f20, $f12, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f12.fl + ctx->f4.fl;
L_800AA300:
    // 0x800AA300: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA304: lwc1        $f0, 0x51C8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X51C8);
    // 0x800AA308: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800AA30C: nop

    // 0x800AA310: bc1fl       L_800AA31C
    if (!c1cs) {
        // 0x800AA314: sub.s       $f20, $f12, $f4
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f12.fl - ctx->f4.fl;
            goto L_800AA31C;
    }
    goto skip_5;
    // 0x800AA314: sub.s       $f20, $f12, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f12.fl - ctx->f4.fl;
    skip_5:
    // 0x800AA318: add.s       $f20, $f12, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f12.fl + ctx->f4.fl;
L_800AA31C:
    // 0x800AA31C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA320: lwc1        $f14, 0x51CC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X51CC);
    // 0x800AA324: jal         0x8001E20C
    // 0x800AA328: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_8001E20C(rdram, ctx);
        goto after_2;
    // 0x800AA328: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_2:
    // 0x800AA32C: swc1        $f20, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f20.u32l;
    // 0x800AA330: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AA334: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800AA338: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800AA33C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800AA340: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800AA344: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800AA348: jr          $ra
    // 0x800AA34C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800AA34C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800AA1BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA1BC: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800AA1C0: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x800AA1C4: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x800AA1C8: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x800AA1CC: sw          $s4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r20;
    // 0x800AA1D0: sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // 0x800AA1D4: sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // 0x800AA1D8: sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // 0x800AA1DC: sdc1        $f22, 0x88($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X88, ctx->r29);
    // 0x800AA1E0: sdc1        $f20, 0x80($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X80, ctx->r29);
    // 0x800AA1E4: lwc1        $f2, 0x24($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800AA1E8: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800AA1EC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AA1F0: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x800AA1F4: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800AA1F8: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800AA1FC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x800AA200: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800AA204: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800AA208: nop

    // 0x800AA20C: bc1f        L_800AA250
    if (!c1cs) {
        // 0x800AA210: swc1        $f6, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
            goto L_800AA250;
    }
    // 0x800AA210: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x800AA214: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800AA218: lwc1        $f0, 0x1A40($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1A40);
    // 0x800AA21C: addiu       $v0, $v0, 0x1A40
    ctx->r2 = ADD32(ctx->r2, 0X1A40);
    // 0x800AA220: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800AA224: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800AA228: sub.s       $f2, $f4, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800AA22C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800AA230: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800AA234: sub.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800AA238: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x800AA23C: div.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800AA240: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x800AA244: div.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800AA248: j           L_800AA25C
    // 0x800AA24C: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
        goto L_800AA25C;
    // 0x800AA24C: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
L_800AA250:
    // 0x800AA250: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x800AA254: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800AA258: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
L_800AA25C:
    // 0x800AA25C: addiu       $s2, $sp, 0x48
    ctx->r18 = ADD32(ctx->r29, 0X48);
    // 0x800AA260: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800AA264: addiu       $t3, $v0, 0x1A40
    ctx->r11 = ADD32(ctx->r2, 0X1A40);
    // 0x800AA268: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800AA26C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800AA270: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800AA274: sw          $t0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r8;
    // 0x800AA278: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x800AA27C: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    // 0x800AA280: jal         0x8001CF2C
    // 0x800AA284: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001CF2C(rdram, ctx);
        goto after_0;
    // 0x800AA284: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_0:
    // 0x800AA288: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800AA28C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA290: lwc1        $f4, 0x5498($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5498);
    // 0x800AA294: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x800AA298: nop

    // 0x800AA29C: bc1f        L_800AA2D8
    if (!c1cs) {
        // 0x800AA2A0: addiu       $s1, $sp, 0x18
        ctx->r17 = ADD32(ctx->r29, 0X18);
            goto L_800AA2D8;
    }
    // 0x800AA2A0: addiu       $s1, $sp, 0x18
    ctx->r17 = ADD32(ctx->r29, 0X18);
    // 0x800AA2A4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA2A8: lwc1        $f0, 0x549C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X549C);
    // 0x800AA2AC: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800AA2B0: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800AA2B4: div.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800AA2B8: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800AA2BC: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800AA2C0: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800AA2C4: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800AA2C8: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800AA2CC: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x800AA2D0: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    // 0x800AA2D4: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
L_800AA2D8:
    // 0x800AA2D8: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800AA2DC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800AA2E0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800AA2E4: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800AA2E8: addiu       $a0, $a0, 0x1A50
    ctx->r4 = ADD32(ctx->r4, 0X1A50);
    // 0x800AA2EC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x800AA2F0: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800AA2F4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800AA2F8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800AA2FC: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800AA300: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x800AA304: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800AA308: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800AA30C: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AA310: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x800AA314: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800AA318: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800AA31C: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800AA320: addiu       $v0, $sp, 0x38
    ctx->r2 = ADD32(ctx->r29, 0X38);
    // 0x800AA324: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800AA328: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x800AA32C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800AA330: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x800AA334: jal         0x80098FA8
    // 0x800AA338: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_80098FA8(rdram, ctx);
        goto after_1;
    // 0x800AA338: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_1:
    // 0x800AA33C: lhu         $v0, 0x4A($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X4A);
    // 0x800AA340: beq         $v0, $zero, L_800AA4CC
    if (ctx->r2 == 0) {
        // 0x800AA344: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_800AA4CC;
    }
    // 0x800AA344: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800AA348: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x800AA34C: addiu       $s2, $sp, 0x58
    ctx->r18 = ADD32(ctx->r29, 0X58);
    // 0x800AA350: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA354: lwc1        $f22, 0x54A0($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X54A0);
    // 0x800AA358: lui         $s4, 0x8000
    ctx->r20 = S32(0X8000 << 16);
    // 0x800AA35C: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
L_800AA360:
    // 0x800AA360: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800AA364: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800AA368: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800AA36C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800AA370: lw          $v1, 0x1900($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1900);
    // 0x800AA374: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800AA378: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x800AA37C: lbu         $v0, 0x3($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X3);
    // 0x800AA380: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800AA384: beq         $v0, $zero, L_800AA4B4
    if (ctx->r2 == 0) {
        // 0x800AA388: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800AA4B4;
    }
    // 0x800AA388: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AA38C: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800AA390: beq         $v1, $v0, L_800AA3AC
    if (ctx->r3 == ctx->r2) {
        // 0x800AA394: andi        $v1, $s0, 0xFFFF
        ctx->r3 = ctx->r16 & 0XFFFF;
            goto L_800AA3AC;
    }
    // 0x800AA394: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
    // 0x800AA398: lbu         $v0, 0x100($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X100);
    // 0x800AA39C: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x800AA3A0: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AA3A4: j           L_800AA3B4
    // 0x800AA3A8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
        goto L_800AA3B4;
    // 0x800AA3A8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_800AA3AC:
    // 0x800AA3AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AA3B0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_800AA3B4:
    // 0x800AA3B4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800AA3B8: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800AA3BC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800AA3C0: lw          $v1, 0x1900($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1900);
    // 0x800AA3C4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800AA3C8: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x800AA3CC: lwc1        $f2, 0x70($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X70);
    // 0x800AA3D0: lwc1        $f0, 0x7C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x800AA3D4: sub.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800AA3D8: addiu       $a1, $a0, 0x70
    ctx->r5 = ADD32(ctx->r4, 0X70);
    // 0x800AA3DC: addiu       $v0, $a0, 0x7C
    ctx->r2 = ADD32(ctx->r4, 0X7C);
    // 0x800AA3E0: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x800AA3E4: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AA3E8: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800AA3EC: sub.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800AA3F0: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x800AA3F4: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AA3F8: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800AA3FC: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800AA400: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AA404: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800AA408: nop

    // 0x800AA40C: bc1f        L_800AA440
    if (!c1cs) {
        // 0x800AA410: swc1        $f6, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
            goto L_800AA440;
    }
    // 0x800AA410: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x800AA414: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AA418: lwc1        $f0, 0x54A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X54A4);
    // 0x800AA41C: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800AA420: mul.s       $f2, $f10, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800AA424: nop

    // 0x800AA428: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800AA42C: nop

    // 0x800AA430: mul.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800AA434: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    // 0x800AA438: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x800AA43C: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
L_800AA440:
    // 0x800AA440: c.le.s      $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f22.fl <= ctx->f8.fl;
    // 0x800AA444: nop

    // 0x800AA448: bc1t        L_800AA460
    if (c1cs) {
        // 0x800AA44C: addiu       $a0, $a0, 0xBC
        ctx->r4 = ADD32(ctx->r4, 0XBC);
            goto L_800AA460;
    }
    // 0x800AA44C: addiu       $a0, $a0, 0xBC
    ctx->r4 = ADD32(ctx->r4, 0XBC);
    // 0x800AA450: trunc.w.s   $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800AA454: mfc1        $v0, $f12
    ctx->r2 = (int32_t)ctx->f12.u32l;
    // 0x800AA458: j           L_800AA474
    // 0x800AA45C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
        goto L_800AA474;
    // 0x800AA45C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
L_800AA460:
    // 0x800AA460: sub.s       $f0, $f8, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f22.fl;
    // 0x800AA464: trunc.w.s   $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800AA468: mfc1        $v0, $f12
    ctx->r2 = (int32_t)ctx->f12.u32l;
    // 0x800AA46C: or          $v0, $v0, $s4
    ctx->r2 = ctx->r2 | ctx->r20;
    // 0x800AA470: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
L_800AA474:
    // 0x800AA474: jal         0x800988E8
    // 0x800AA478: andi        $a3, $v0, 0xFF
    ctx->r7 = ctx->r2 & 0XFF;
    func_800988E8(rdram, ctx);
        goto after_2;
    // 0x800AA478: andi        $a3, $v0, 0xFF
    ctx->r7 = ctx->r2 & 0XFF;
    after_2:
    // 0x800AA47C: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
    // 0x800AA480: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800AA484: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800AA488: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800AA48C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800AA490: lw          $v1, 0x1900($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1900);
    // 0x800AA494: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800AA498: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800AA49C: lw          $t1, 0x70($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X70);
    // 0x800AA4A0: lw          $t2, 0x74($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X74);
    // 0x800AA4A4: lw          $t3, 0x78($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X78);
    // 0x800AA4A8: sw          $t1, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r9;
    // 0x800AA4AC: sw          $t2, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r10;
    // 0x800AA4B0: sw          $t3, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r11;
L_800AA4B4:
    // 0x800AA4B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800AA4B8: lhu         $v1, 0x4A($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0X4A);
    // 0x800AA4BC: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x800AA4C0: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800AA4C4: bne         $v0, $zero, L_800AA360
    if (ctx->r2 != 0) {
        // 0x800AA4C8: andi        $v1, $s0, 0xFFFF
        ctx->r3 = ctx->r16 & 0XFFFF;
            goto L_800AA360;
    }
    // 0x800AA4C8: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
L_800AA4CC:
    // 0x800AA4CC: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x800AA4D0: lw          $s4, 0x78($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X78);
    // 0x800AA4D4: lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X74);
    // 0x800AA4D8: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x800AA4DC: lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6C);
    // 0x800AA4E0: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x800AA4E4: ldc1        $f22, 0x88($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X88);
    // 0x800AA4E8: ldc1        $f20, 0x80($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X80);
    // 0x800AA4EC: jr          $ra
    // 0x800AA4F0: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800AA4F0: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
