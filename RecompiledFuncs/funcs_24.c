#include "recomp.h"
#include "funcs.h"
#include <stdio.h>

RECOMP_FUNC void func_8008F758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F758: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8008F75C: lw          $a1, -0x6650($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6650);
    // 0x8008F760: beq         $a1, $zero, L_8008F780
    if (ctx->r5 == 0) {
        // 0x8008F764: addu        $a2, $a0, $zero
        ctx->r6 = ADD32(ctx->r4, 0);
            goto L_8008F780;
    }
    // 0x8008F764: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
L_8008F768:
    // 0x8008F768: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x8008F76C: beq         $v0, $a2, L_8008F7CC
    if (ctx->r2 == ctx->r6) {
        // 0x8008F770: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_8008F7CC;
    }
    // 0x8008F770: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8008F774: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    // 0x8008F778: bne         $a1, $zero, L_8008F768
    if (ctx->r5 != 0) {
        // 0x8008F77C: nop
    
            goto L_8008F768;
    }
    // 0x8008F77C: nop

L_8008F780:
    // 0x8008F780: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008F784: lw          $v0, -0x6654($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6654);
    // 0x8008F788: beq         $v0, $zero, L_8008F7D8
    if (ctx->r2 == 0) {
        // 0x8008F78C: addu        $a1, $v0, $zero
        ctx->r5 = ADD32(ctx->r2, 0);
            goto L_8008F7D8;
    }
    // 0x8008F78C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8008F790: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8008F794: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F798: sw          $v0, -0x6654($at)
    MEM_W(-0X6654, ctx->r1) = ctx->r2;
    // 0x8008F79C: bnel        $v0, $zero, L_8008F7A4
    if (ctx->r2 != 0) {
        // 0x8008F7A0: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8008F7A4;
    }
    goto skip_0;
    // 0x8008F7A0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_0:
L_8008F7A4:
    // 0x8008F7A4: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008F7A8: lw          $v0, -0x6650($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6650);
    // 0x8008F7AC: bnel        $v0, $zero, L_8008F7B4
    if (ctx->r2 != 0) {
        // 0x8008F7B0: sw          $a1, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r5;
            goto L_8008F7B4;
    }
    goto skip_1;
    // 0x8008F7B0: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    skip_1:
L_8008F7B4:
    // 0x8008F7B4: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008F7B8: lw          $v0, -0x6650($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6650);
    // 0x8008F7BC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F7C0: sw          $a1, -0x6650($at)
    MEM_W(-0X6650, ctx->r1) = ctx->r5;
    // 0x8008F7C4: j           L_8008F800
    // 0x8008F7C8: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_8008F800;
    // 0x8008F7C8: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_8008F7CC:
    // 0x8008F7CC: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x8008F7D0: j           L_8008F850
    // 0x8008F7D4: sh          $v1, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r3;
        goto L_8008F850;
    // 0x8008F7D4: sh          $v1, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r3;
L_8008F7D8:
    // 0x8008F7D8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8008F7DC: lw          $a1, -0x6650($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6650);
    // 0x8008F7E0: beq         $a1, $zero, L_8008F800
    if (ctx->r5 == 0) {
        // 0x8008F7E4: nop
    
            goto L_8008F800;
    }
    // 0x8008F7E4: nop

L_8008F7E8:
    // 0x8008F7E8: lhu         $v0, 0x10($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X10);
    // 0x8008F7EC: beq         $v0, $zero, L_8008F800
    if (ctx->r2 == 0) {
        // 0x8008F7F0: nop
    
            goto L_8008F800;
    }
    // 0x8008F7F0: nop

    // 0x8008F7F4: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    // 0x8008F7F8: bne         $a1, $zero, L_8008F7E8
    if (ctx->r5 != 0) {
        // 0x8008F7FC: nop
    
            goto L_8008F7E8;
    }
    // 0x8008F7FC: nop

L_8008F800:
    // 0x8008F800: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8008F804: lhu         $a0, -0x68DC($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X68DC);
    // 0x8008F808: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8008F80C: lw          $v1, -0x68D8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X68D8);
    // 0x8008F810: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8008F814: sh          $v0, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r2;
    // 0x8008F818: sw          $a2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r6;
    // 0x8008F81C: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8008F820: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8008F824: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008F828: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008F82C: addiu       $v1, $zero, 0x100
    ctx->r3 = ADD32(0, 0X100);
    // 0x8008F830: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x8008F834: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8008F838: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x8008F83C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008F840: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F844: sh          $a0, -0x68DC($at)
    MEM_H(-0X68DC, ctx->r1) = ctx->r4;
    // 0x8008F848: sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
    // 0x8008F84C: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
L_8008F850:
    // 0x8008F850: jr          $ra
    // 0x8008F854: nop

    return;
    // 0x8008F854: nop

;}
RECOMP_FUNC void func_8008F858(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F858: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008F85C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8008F860: andi        $s2, $a0, 0xFFFF
    ctx->r18 = ctx->r4 & 0XFFFF;
    // 0x8008F864: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8008F868: sll         $s0, $s2, 1
    ctx->r16 = S32(ctx->r18 << 1);
    // 0x8008F86C: addu        $s0, $s0, $s2
    ctx->r16 = ADD32(ctx->r16, ctx->r18);
    // 0x8008F870: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8008F874: sll         $s1, $s0, 9
    ctx->r17 = S32(ctx->r16 << 9);
    // 0x8008F878: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8008F87C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008F880: jal         0x80001ACC
    // 0x8008F884: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x8008F884: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x8008F888: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8008F88C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F890: sw          $a0, -0x663C($at)
    MEM_W(-0X663C, ctx->r1) = ctx->r4;
    // 0x8008F894: jal         0x8002C280
    // 0x8008F898: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    osInvalDCache_recomp(rdram, ctx);
        goto after_1;
    // 0x8008F898: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_1:
    // 0x8008F89C: sll         $a0, $s0, 3
    ctx->r4 = S32(ctx->r16 << 3);
    // 0x8008F8A0: jal         0x80001ACC
    // 0x8008F8A4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_2;
    // 0x8008F8A4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
    // 0x8008F8A8: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8008F8AC: lw          $a0, -0x663C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X663C);
    // 0x8008F8B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8008F8B4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8008F8B8: slt         $v0, $a2, $s2
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8008F8BC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F8C0: sw          $v1, -0x6638($at)
    MEM_W(-0X6638, ctx->r1) = ctx->r3;
    // 0x8008F8C4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F8C8: sw          $zero, -0x661C($at)
    MEM_W(-0X661C, ctx->r1) = 0;
    // 0x8008F8CC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F8D0: sw          $zero, -0x664C($at)
    MEM_W(-0X664C, ctx->r1) = 0;
    // 0x8008F8D4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F8D8: sw          $v1, -0x6634($at)
    MEM_W(-0X6634, ctx->r1) = ctx->r3;
    // 0x8008F8DC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8008F8E0: beq         $v0, $zero, L_8008F924
    if (ctx->r2 == 0) {
        // 0x8008F8E4: sw          $a0, 0x14($v1)
        MEM_W(0X14, ctx->r3) = ctx->r4;
            goto L_8008F924;
    }
    // 0x8008F8E4: sw          $a0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r4;
    // 0x8008F8E8: addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
    // 0x8008F8EC: addiu       $a3, $a0, 0x600
    ctx->r7 = ADD32(ctx->r4, 0X600);
    // 0x8008F8F0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8008F8F4: addu        $t0, $v1, $zero
    ctx->r8 = ADD32(ctx->r3, 0);
    // 0x8008F8F8: addiu       $v1, $t0, 0x18
    ctx->r3 = ADD32(ctx->r8, 0X18);
L_8008F8FC:
    // 0x8008F8FC: sw          $a3, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r7;
    // 0x8008F900: addiu       $a3, $a3, 0x600
    ctx->r7 = ADD32(ctx->r7, 0X600);
    // 0x8008F904: addu        $v0, $t0, $a1
    ctx->r2 = ADD32(ctx->r8, ctx->r5);
    // 0x8008F908: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x8008F90C: sw          $v1, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->r3;
    // 0x8008F910: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8008F914: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8008F918: slt         $v0, $a2, $s0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8008F91C: bne         $v0, $zero, L_8008F8FC
    if (ctx->r2 != 0) {
        // 0x8008F920: addiu       $v1, $v1, 0x18
        ctx->r3 = ADD32(ctx->r3, 0X18);
            goto L_8008F8FC;
    }
    // 0x8008F920: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
L_8008F924:
    // 0x8008F924: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8008F928: lw          $v1, -0x6638($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6638);
    // 0x8008F92C: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x8008F930: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8008F934: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8008F938: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008F93C: sw          $zero, -0x18($v0)
    MEM_W(-0X18, ctx->r2) = 0;
    // 0x8008F940: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008F944: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8008F948: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8008F94C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8008F950: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008F954: jr          $ra
    // 0x8008F958: nop

    return;
    // 0x8008F958: nop

;}
RECOMP_FUNC void func_8008F95C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F95C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008F960: lw          $v0, -0x664C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X664C);
    // 0x8008F964: beq         $a0, $v0, L_8008F9C0
    if (ctx->r4 == ctx->r2) {
        // 0x8008F968: nop
    
            goto L_8008F9C0;
    }
    // 0x8008F968: nop

    // 0x8008F96C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8008F970: beq         $v1, $zero, L_8008F980
    if (ctx->r3 == 0) {
        // 0x8008F974: nop
    
            goto L_8008F980;
    }
    // 0x8008F974: nop

    // 0x8008F978: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8008F97C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_8008F980:
    // 0x8008F980: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x8008F984: beq         $v1, $zero, L_8008F998
    if (ctx->r3 == 0) {
        // 0x8008F988: nop
    
            goto L_8008F998;
    }
    // 0x8008F988: nop

    // 0x8008F98C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8008F990: j           L_8008F9A4
    // 0x8008F994: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_8008F9A4;
    // 0x8008F994: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8008F998:
    // 0x8008F998: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8008F99C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F9A0: sw          $v0, -0x661C($at)
    MEM_W(-0X661C, ctx->r1) = ctx->r2;
L_8008F9A4:
    // 0x8008F9A4: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008F9A8: lw          $v0, -0x664C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X664C);
    // 0x8008F9AC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F9B0: sw          $a0, -0x664C($at)
    MEM_W(-0X664C, ctx->r1) = ctx->r4;
    // 0x8008F9B4: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8008F9B8: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8008F9BC: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_8008F9C0:
    // 0x8008F9C0: jr          $ra
    // 0x8008F9C4: nop

    return;
    // 0x8008F9C4: nop

;}
RECOMP_FUNC void func_8008F9C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F9C8: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008F9CC: lw          $v0, -0x6634($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6634);
    // 0x8008F9D0: beq         $v0, $zero, L_8008FA38
    if (ctx->r2 == 0) {
        // 0x8008F9D4: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8008FA38;
    }
    // 0x8008F9D4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8008F9D8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008F9DC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F9E0: sw          $v0, -0x6634($at)
    MEM_W(-0X6634, ctx->r1) = ctx->r2;
    // 0x8008F9E4: bnel        $v0, $zero, L_8008F9EC
    if (ctx->r2 != 0) {
        // 0x8008F9E8: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8008F9EC;
    }
    goto skip_0;
    // 0x8008F9E8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_0:
L_8008F9EC:
    // 0x8008F9EC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008F9F0: lw          $v0, -0x664C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X664C);
    // 0x8008F9F4: bnel        $v0, $zero, L_8008FA20
    if (ctx->r2 != 0) {
        // 0x8008F9F8: sw          $zero, 0x0($v1)
        MEM_W(0X0, ctx->r3) = 0;
            goto L_8008FA20;
    }
    goto skip_1;
    // 0x8008F9F8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    skip_1:
    // 0x8008F9FC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008FA00: lw          $v0, -0x661C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X661C);
    // 0x8008FA04: beq         $v0, $zero, L_8008FA10
    if (ctx->r2 == 0) {
        // 0x8008FA08: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8008FA10;
    }
    // 0x8008FA08: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8008FA0C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8008FA10:
    // 0x8008FA10: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008FA14: sw          $v1, -0x661C($at)
    MEM_W(-0X661C, ctx->r1) = ctx->r3;
    // 0x8008FA18: j           L_8008FA28
    // 0x8008FA1C: nop

        goto L_8008FA28;
    // 0x8008FA1C: nop

L_8008FA20:
    // 0x8008FA20: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8008FA24: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
L_8008FA28:
    // 0x8008FA28: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008FA2C: sw          $v1, -0x664C($at)
    MEM_W(-0X664C, ctx->r1) = ctx->r3;
    // 0x8008FA30: j           L_8008FAA4
    // 0x8008FA34: nop

        goto L_8008FAA4;
    // 0x8008FA34: nop

L_8008FA38:
    // 0x8008FA38: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8008FA3C: lw          $v1, -0x661C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X661C);
    // 0x8008FA40: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008FA44: lw          $v0, -0x664C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X664C);
    // 0x8008FA48: beq         $v1, $v0, L_8008FAA4
    if (ctx->r3 == ctx->r2) {
        // 0x8008FA4C: nop
    
            goto L_8008FAA4;
    }
    // 0x8008FA4C: nop

    // 0x8008FA50: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8008FA54: beq         $a0, $zero, L_8008FA64
    if (ctx->r4 == 0) {
        // 0x8008FA58: nop
    
            goto L_8008FA64;
    }
    // 0x8008FA58: nop

    // 0x8008FA5C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8008FA60: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8008FA64:
    // 0x8008FA64: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x8008FA68: beq         $a0, $zero, L_8008FA7C
    if (ctx->r4 == 0) {
        // 0x8008FA6C: nop
    
            goto L_8008FA7C;
    }
    // 0x8008FA6C: nop

    // 0x8008FA70: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008FA74: j           L_8008FA88
    // 0x8008FA78: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
        goto L_8008FA88;
    // 0x8008FA78: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_8008FA7C:
    // 0x8008FA7C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008FA80: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008FA84: sw          $v0, -0x661C($at)
    MEM_W(-0X661C, ctx->r1) = ctx->r2;
L_8008FA88:
    // 0x8008FA88: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008FA8C: lw          $v0, -0x664C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X664C);
    // 0x8008FA90: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008FA94: sw          $v1, -0x664C($at)
    MEM_W(-0X664C, ctx->r1) = ctx->r3;
    // 0x8008FA98: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8008FA9C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8008FAA0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8008FAA4:
    // 0x8008FAA4: jr          $ra
    // 0x8008FAA8: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    return;
    // 0x8008FAA8: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
;}
RECOMP_FUNC void func_8008FAAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FAAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FAB0: addu        $t5, $a0, $zero
    ctx->r13 = ADD32(ctx->r4, 0);
    // 0x8008FAB4: addu        $t4, $a1, $zero
    ctx->r12 = ADD32(ctx->r5, 0);
    // 0x8008FAB8: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8008FABC: lw          $t0, -0x664C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X664C);
    // 0x8008FAC0: addu        $t2, $a2, $zero
    ctx->r10 = ADD32(ctx->r6, 0);
    // 0x8008FAC4: beq         $t0, $zero, L_8008FCA4
    if (ctx->r8 == 0) {
        // 0x8008FAC8: addu        $t3, $zero, $zero
        ctx->r11 = ADD32(0, 0);
            goto L_8008FCA4;
    }
    // 0x8008FAC8: addu        $t3, $zero, $zero
    ctx->r11 = ADD32(0, 0);
    // 0x8008FACC: addiu       $t6, $zero, 0x600
    ctx->r14 = ADD32(0, 0X600);
    // 0x8008FAD0: addiu       $t8, $zero, -0x100
    ctx->r24 = ADD32(0, -0X100);
    // 0x8008FAD4: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8008FAD8: lw          $t7, -0x68D8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X68D8);
L_8008FADC:
    // 0x8008FADC: lw          $v0, 0xC($t0)
    ctx->r2 = MEM_W(ctx->r8, 0XC);
    // 0x8008FAE0: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8008FAE4: bnel        $v0, $a3, L_8008FC9C
    if (ctx->r2 != ctx->r7) {
        // 0x8008FAE8: addu        $t0, $t1, $zero
        ctx->r8 = ADD32(ctx->r9, 0);
            goto L_8008FC9C;
    }
    goto skip_0;
    // 0x8008FAE8: addu        $t0, $t1, $zero
    ctx->r8 = ADD32(ctx->r9, 0);
    skip_0:
    // 0x8008FAEC: lw          $a0, 0x8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X8);
    // 0x8008FAF0: addu        $a1, $t4, $t2
    ctx->r5 = ADD32(ctx->r12, ctx->r10);
    // 0x8008FAF4: sltu        $v0, $a0, $a1
    ctx->r2 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x8008FAF8: beql        $v0, $zero, L_8008FC9C
    if (ctx->r2 == 0) {
        // 0x8008FAFC: addu        $t0, $t1, $zero
        ctx->r8 = ADD32(ctx->r9, 0);
            goto L_8008FC9C;
    }
    goto skip_1;
    // 0x8008FAFC: addu        $t0, $t1, $zero
    ctx->r8 = ADD32(ctx->r9, 0);
    skip_1:
    // 0x8008FB00: addiu       $a2, $a0, 0x600
    ctx->r6 = ADD32(ctx->r4, 0X600);
    // 0x8008FB04: sltu        $v0, $t4, $a2
    ctx->r2 = ctx->r12 < ctx->r6 ? 1 : 0;
    // 0x8008FB08: beql        $v0, $zero, L_8008FC9C
    if (ctx->r2 == 0) {
        // 0x8008FB0C: addu        $t0, $t1, $zero
        ctx->r8 = ADD32(ctx->r9, 0);
            goto L_8008FC9C;
    }
    goto skip_2;
    // 0x8008FB0C: addu        $t0, $t1, $zero
    ctx->r8 = ADD32(ctx->r9, 0);
    skip_2:
    // 0x8008FB10: lw          $v1, 0x10($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X10);
    // 0x8008FB14: beq         $v1, $t6, L_8008FB94
    if (ctx->r3 == ctx->r14) {
        // 0x8008FB18: addu        $a0, $a0, $v1
        ctx->r4 = ADD32(ctx->r4, ctx->r3);
            goto L_8008FB94;
    }
    // 0x8008FB18: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8008FB1C: sltu        $v0, $a0, $a1
    ctx->r2 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x8008FB20: beq         $v0, $zero, L_8008FB94
    if (ctx->r2 == 0) {
        // 0x8008FB24: sltu        $v0, $a1, $a2
        ctx->r2 = ctx->r5 < ctx->r6 ? 1 : 0;
            goto L_8008FB94;
    }
    // 0x8008FB24: sltu        $v0, $a1, $a2
    ctx->r2 = ctx->r5 < ctx->r6 ? 1 : 0;
    // 0x8008FB28: bne         $v0, $zero, L_8008FB38
    if (ctx->r2 != 0) {
        // 0x8008FB2C: subu        $v0, $a1, $a0
        ctx->r2 = SUB32(ctx->r5, ctx->r4);
            goto L_8008FB38;
    }
    // 0x8008FB2C: subu        $v0, $a1, $a0
    ctx->r2 = SUB32(ctx->r5, ctx->r4);
    // 0x8008FB30: j           L_8008FB40
    // 0x8008FB34: subu        $a2, $t6, $v1
    ctx->r6 = SUB32(ctx->r14, ctx->r3);
        goto L_8008FB40;
    // 0x8008FB34: subu        $a2, $t6, $v1
    ctx->r6 = SUB32(ctx->r14, ctx->r3);
L_8008FB38:
    // 0x8008FB38: addiu       $v0, $v0, 0xFF
    ctx->r2 = ADD32(ctx->r2, 0XFF);
    // 0x8008FB3C: and         $a2, $v0, $t8
    ctx->r6 = ctx->r2 & ctx->r24;
L_8008FB40:
    // 0x8008FB40: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8008FB44: lhu         $a1, -0x68DC($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X68DC);
    // 0x8008FB48: lw          $v0, 0x8($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X8);
    // 0x8008FB4C: lw          $v1, 0x10($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X10);
    // 0x8008FB50: sll         $a0, $a1, 1
    ctx->r4 = S32(ctx->r5 << 1);
    // 0x8008FB54: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x8008FB58: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8008FB5C: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8008FB60: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008FB64: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8008FB68: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x8008FB6C: lw          $v0, 0x14($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X14);
    // 0x8008FB70: lw          $v1, 0x10($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X10);
    // 0x8008FB74: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008FB78: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x8008FB7C: lw          $v0, 0x10($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X10);
    // 0x8008FB80: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008FB84: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008FB88: sh          $a1, -0x68DC($at)
    MEM_H(-0X68DC, ctx->r1) = ctx->r5;
    // 0x8008FB8C: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8008FB90: sw          $v0, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r2;
L_8008FB94:
    // 0x8008FB94: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008FB98: lw          $v0, -0x664C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X664C);
    // 0x8008FB9C: beq         $t0, $v0, L_8008FBF8
    if (ctx->r8 == ctx->r2) {
        // 0x8008FBA0: nop
    
            goto L_8008FBF8;
    }
    // 0x8008FBA0: nop

    // 0x8008FBA4: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8008FBA8: beq         $v1, $zero, L_8008FBB8
    if (ctx->r3 == 0) {
        // 0x8008FBAC: nop
    
            goto L_8008FBB8;
    }
    // 0x8008FBAC: nop

    // 0x8008FBB0: lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X4);
    // 0x8008FBB4: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_8008FBB8:
    // 0x8008FBB8: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x8008FBBC: beq         $v1, $zero, L_8008FBD0
    if (ctx->r3 == 0) {
        // 0x8008FBC0: nop
    
            goto L_8008FBD0;
    }
    // 0x8008FBC0: nop

    // 0x8008FBC4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8008FBC8: j           L_8008FBDC
    // 0x8008FBCC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_8008FBDC;
    // 0x8008FBCC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8008FBD0:
    // 0x8008FBD0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8008FBD4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008FBD8: sw          $v0, -0x661C($at)
    MEM_W(-0X661C, ctx->r1) = ctx->r2;
L_8008FBDC:
    // 0x8008FBDC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008FBE0: lw          $v0, -0x664C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X664C);
    // 0x8008FBE4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008FBE8: sw          $t0, -0x664C($at)
    MEM_W(-0X664C, ctx->r1) = ctx->r8;
    // 0x8008FBEC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8008FBF0: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x8008FBF4: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_8008FBF8:
    // 0x8008FBF8: lw          $a1, 0x8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8);
    // 0x8008FBFC: sltu        $v0, $t4, $a1
    ctx->r2 = ctx->r12 < ctx->r5 ? 1 : 0;
    // 0x8008FC00: beq         $v0, $zero, L_8008FC3C
    if (ctx->r2 == 0) {
        // 0x8008FC04: andi        $v1, $t3, 0xFFFF
        ctx->r3 = ctx->r11 & 0XFFFF;
            goto L_8008FC3C;
    }
    // 0x8008FC04: andi        $v1, $t3, 0xFFFF
    ctx->r3 = ctx->r11 & 0XFFFF;
    // 0x8008FC08: lw          $v0, 0x14($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X14);
    // 0x8008FC0C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8008FC10: addu        $v1, $v1, $sp
    ctx->r3 = ADD32(ctx->r3, ctx->r29);
    // 0x8008FC14: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8008FC18: lw          $v0, 0x8($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X8);
    // 0x8008FC1C: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x8008FC20: lw          $v0, 0x8($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X8);
    // 0x8008FC24: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8008FC28: subu        $v0, $v0, $t4
    ctx->r2 = SUB32(ctx->r2, ctx->r12);
    // 0x8008FC2C: subu        $v0, $t2, $v0
    ctx->r2 = SUB32(ctx->r10, ctx->r2);
    // 0x8008FC30: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x8008FC34: j           L_8008FC98
    // 0x8008FC38: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
        goto L_8008FC98;
    // 0x8008FC38: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
L_8008FC3C:
    // 0x8008FC3C: lw          $v0, 0x10($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X10);
    // 0x8008FC40: addu        $v1, $t4, $t2
    ctx->r3 = ADD32(ctx->r12, ctx->r10);
    // 0x8008FC44: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x8008FC48: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8008FC4C: beq         $v0, $zero, L_8008FF18
    if (ctx->r2 == 0) {
        // 0x8008FC50: andi        $v1, $t3, 0xFFFF
        ctx->r3 = ctx->r11 & 0XFFFF;
            goto L_8008FF18;
    }
    // 0x8008FC50: andi        $v1, $t3, 0xFFFF
    ctx->r3 = ctx->r11 & 0XFFFF;
    // 0x8008FC54: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    // 0x8008FC58: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8008FC5C: addu        $v1, $v1, $sp
    ctx->r3 = ADD32(ctx->r3, ctx->r29);
    // 0x8008FC60: subu        $v0, $t4, $a1
    ctx->r2 = SUB32(ctx->r12, ctx->r5);
    // 0x8008FC64: sw          $t4, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r12;
    // 0x8008FC68: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8008FC6C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8008FC70: lw          $a0, 0x8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X8);
    // 0x8008FC74: lw          $v0, 0x10($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X10);
    // 0x8008FC78: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8008FC7C: subu        $a0, $a0, $t4
    ctx->r4 = SUB32(ctx->r4, ctx->r12);
    // 0x8008FC80: sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // 0x8008FC84: lw          $v1, 0x8($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X8);
    // 0x8008FC88: lw          $v0, 0x10($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X10);
    // 0x8008FC8C: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8008FC90: subu        $t2, $t2, $a0
    ctx->r10 = SUB32(ctx->r10, ctx->r4);
    // 0x8008FC94: addu        $t4, $v1, $v0
    ctx->r12 = ADD32(ctx->r3, ctx->r2);
L_8008FC98:
    // 0x8008FC98: addu        $t0, $t1, $zero
    ctx->r8 = ADD32(ctx->r9, 0);
L_8008FC9C:
    // 0x8008FC9C: bne         $t0, $zero, L_8008FADC
    if (ctx->r8 != 0) {
        // 0x8008FCA0: nop
    
            goto L_8008FADC;
    }
    // 0x8008FCA0: nop

L_8008FCA4:
    // 0x8008FCA4: beq         $t2, $zero, L_8008FEF0
    if (ctx->r10 == 0) {
        // 0x8008FCA8: subu        $v1, $t4, $a3
        ctx->r3 = SUB32(ctx->r12, ctx->r7);
            goto L_8008FEF0;
    }
    // 0x8008FCA8: subu        $v1, $t4, $a3
    ctx->r3 = SUB32(ctx->r12, ctx->r7);
    // 0x8008FCAC: lui         $v0, 0xAAAA
    ctx->r2 = S32(0XAAAA << 16);
    // 0x8008FCB0: ori         $v0, $v0, 0xAAAB
    ctx->r2 = ctx->r2 | 0XAAAB;
    // 0x8008FCB4: multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008FCB8: addiu       $t6, $zero, 0x600
    ctx->r14 = ADD32(0, 0X600);
    // 0x8008FCBC: addiu       $t7, $zero, -0x100
    ctx->r15 = ADD32(0, -0X100);
    // 0x8008FCC0: mfhi        $t9
    ctx->r25 = hi;
    // 0x8008FCC4: srl         $t1, $t9, 10
    ctx->r9 = S32(U32(ctx->r25) >> 10);
    // 0x8008FCC8: sll         $v0, $t1, 1
    ctx->r2 = S32(ctx->r9 << 1);
    // 0x8008FCCC: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8008FCD0: sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2 << 9);
    // 0x8008FCD4: subu        $t1, $v1, $v0
    ctx->r9 = SUB32(ctx->r3, ctx->r2);
L_8008FCD8:
    // 0x8008FCD8: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008FCDC: lw          $v0, -0x6634($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6634);
    // 0x8008FCE0: beq         $v0, $zero, L_8008FD48
    if (ctx->r2 == 0) {
        // 0x8008FCE4: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8008FD48;
    }
    // 0x8008FCE4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8008FCE8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008FCEC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008FCF0: sw          $v0, -0x6634($at)
    MEM_W(-0X6634, ctx->r1) = ctx->r2;
    // 0x8008FCF4: bnel        $v0, $zero, L_8008FCFC
    if (ctx->r2 != 0) {
        // 0x8008FCF8: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8008FCFC;
    }
    goto skip_3;
    // 0x8008FCF8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_3:
L_8008FCFC:
    // 0x8008FCFC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008FD00: lw          $v0, -0x664C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X664C);
    // 0x8008FD04: bnel        $v0, $zero, L_8008FD30
    if (ctx->r2 != 0) {
        // 0x8008FD08: sw          $zero, 0x0($v1)
        MEM_W(0X0, ctx->r3) = 0;
            goto L_8008FD30;
    }
    goto skip_4;
    // 0x8008FD08: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    skip_4:
    // 0x8008FD0C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008FD10: lw          $v0, -0x661C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X661C);
    // 0x8008FD14: beq         $v0, $zero, L_8008FD20
    if (ctx->r2 == 0) {
        // 0x8008FD18: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8008FD20;
    }
    // 0x8008FD18: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8008FD1C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8008FD20:
    // 0x8008FD20: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008FD24: sw          $v1, -0x661C($at)
    MEM_W(-0X661C, ctx->r1) = ctx->r3;
    // 0x8008FD28: j           L_8008FD38
    // 0x8008FD2C: nop

        goto L_8008FD38;
    // 0x8008FD2C: nop

L_8008FD30:
    // 0x8008FD30: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8008FD34: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
L_8008FD38:
    // 0x8008FD38: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008FD3C: sw          $v1, -0x664C($at)
    MEM_W(-0X664C, ctx->r1) = ctx->r3;
    // 0x8008FD40: j           L_8008FDB8
    // 0x8008FD44: addu        $t0, $v1, $zero
    ctx->r8 = ADD32(ctx->r3, 0);
        goto L_8008FDB8;
    // 0x8008FD44: addu        $t0, $v1, $zero
    ctx->r8 = ADD32(ctx->r3, 0);
L_8008FD48:
    // 0x8008FD48: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8008FD4C: lw          $v1, -0x661C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X661C);
    // 0x8008FD50: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008FD54: lw          $v0, -0x664C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X664C);
    // 0x8008FD58: beq         $v1, $v0, L_8008FDB8
    if (ctx->r3 == ctx->r2) {
        // 0x8008FD5C: addu        $t0, $v1, $zero
        ctx->r8 = ADD32(ctx->r3, 0);
            goto L_8008FDB8;
    }
    // 0x8008FD5C: addu        $t0, $v1, $zero
    ctx->r8 = ADD32(ctx->r3, 0);
    // 0x8008FD60: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8008FD64: beq         $a0, $zero, L_8008FD74
    if (ctx->r4 == 0) {
        // 0x8008FD68: nop
    
            goto L_8008FD74;
    }
    // 0x8008FD68: nop

    // 0x8008FD6C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8008FD70: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8008FD74:
    // 0x8008FD74: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x8008FD78: beq         $a0, $zero, L_8008FD8C
    if (ctx->r4 == 0) {
        // 0x8008FD7C: nop
    
            goto L_8008FD8C;
    }
    // 0x8008FD7C: nop

    // 0x8008FD80: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008FD84: j           L_8008FD98
    // 0x8008FD88: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
        goto L_8008FD98;
    // 0x8008FD88: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_8008FD8C:
    // 0x8008FD8C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008FD90: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008FD94: sw          $v0, -0x661C($at)
    MEM_W(-0X661C, ctx->r1) = ctx->r2;
L_8008FD98:
    // 0x8008FD98: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008FD9C: lw          $v0, -0x664C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X664C);
    // 0x8008FDA0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008FDA4: sw          $v1, -0x664C($at)
    MEM_W(-0X664C, ctx->r1) = ctx->r3;
    // 0x8008FDA8: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8008FDAC: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8008FDB0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8008FDB4: addu        $t0, $v1, $zero
    ctx->r8 = ADD32(ctx->r3, 0);
L_8008FDB8:
    // 0x8008FDB8: subu        $v0, $t4, $t1
    ctx->r2 = SUB32(ctx->r12, ctx->r9);
    // 0x8008FDBC: addu        $v1, $t2, $t1
    ctx->r3 = ADD32(ctx->r10, ctx->r9);
    // 0x8008FDC0: sw          $v0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r2;
    // 0x8008FDC4: sltiu       $v0, $v1, 0x601
    ctx->r2 = ctx->r3 < 0X601 ? 1 : 0;
    // 0x8008FDC8: bne         $v0, $zero, L_8008FE58
    if (ctx->r2 != 0) {
        // 0x8008FDCC: sw          $a3, 0xC($t0)
        MEM_W(0XC, ctx->r8) = ctx->r7;
            goto L_8008FE58;
    }
    // 0x8008FDCC: sw          $a3, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r7;
    // 0x8008FDD0: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x8008FDD4: lhu         $a2, -0x68DC($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X68DC);
    // 0x8008FDD8: andi        $a1, $t3, 0xFFFF
    ctx->r5 = ctx->r11 & 0XFFFF;
    // 0x8008FDDC: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8008FDE0: lw          $a0, -0x68D8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X68D8);
    // 0x8008FDE4: lw          $v1, 0x8($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X8);
    // 0x8008FDE8: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8008FDEC: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x8008FDF0: sw          $t6, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r14;
    // 0x8008FDF4: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x8008FDF8: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8008FDFC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008FE00: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8008FE04: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x8008FE08: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8008FE0C: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    // 0x8008FE10: addu        $a1, $a1, $sp
    ctx->r5 = ADD32(ctx->r5, ctx->r29);
    // 0x8008FE14: addiu       $v1, $t2, -0x600
    ctx->r3 = ADD32(ctx->r10, -0X600);
    // 0x8008FE18: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x8008FE1C: lw          $v0, 0x14($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X14);
    // 0x8008FE20: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x8008FE24: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8008FE28: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008FE2C: sh          $a2, -0x68DC($at)
    MEM_H(-0X68DC, ctx->r1) = ctx->r6;
    // 0x8008FE30: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8008FE34: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8008FE38: lw          $v1, 0x8($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X8);
    // 0x8008FE3C: addiu       $v0, $t1, -0x600
    ctx->r2 = ADD32(ctx->r9, -0X600);
    // 0x8008FE40: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x8008FE44: subu        $v0, $t6, $t1
    ctx->r2 = SUB32(ctx->r14, ctx->r9);
    // 0x8008FE48: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x8008FE4C: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // 0x8008FE50: j           L_8008FEE8
    // 0x8008FE54: sw          $v1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r3;
        goto L_8008FEE8;
    // 0x8008FE54: sw          $v1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r3;
L_8008FE58:
    // 0x8008FE58: addiu       $v0, $v1, 0xFF
    ctx->r2 = ADD32(ctx->r3, 0XFF);
    // 0x8008FE5C: and         $v0, $v0, $t7
    ctx->r2 = ctx->r2 & ctx->r15;
    // 0x8008FE60: sw          $v0, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r2;
    // 0x8008FE64: sltiu       $v0, $v0, 0x601
    ctx->r2 = ctx->r2 < 0X601 ? 1 : 0;
    // 0x8008FE68: bne         $v0, $zero, L_8008FE74
    if (ctx->r2 != 0) {
        // 0x8008FE6C: nop
    
            goto L_8008FE74;
    }
    // 0x8008FE6C: nop

    // 0x8008FE70: break       1, 7
    do_break(2148073072);
L_8008FE74:
    // 0x8008FE74: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8008FE78: lhu         $a1, -0x68DC($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X68DC);
    // 0x8008FE7C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8008FE80: lw          $a0, -0x68D8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X68D8);
    // 0x8008FE84: lw          $v1, 0x8($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X8);
    // 0x8008FE88: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8008FE8C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8008FE90: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008FE94: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8008FE98: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x8008FE9C: lw          $v1, 0x10($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X10);
    // 0x8008FEA0: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8008FEA4: lw          $v1, 0x14($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X14);
    // 0x8008FEA8: sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
    // 0x8008FEAC: andi        $v1, $t3, 0xFFFF
    ctx->r3 = ctx->r11 & 0XFFFF;
    // 0x8008FEB0: lw          $v0, 0x14($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X14);
    // 0x8008FEB4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8008FEB8: addu        $v1, $v1, $sp
    ctx->r3 = ADD32(ctx->r3, ctx->r29);
    // 0x8008FEBC: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8008FEC0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8008FEC4: lw          $v0, 0x8($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X8);
    // 0x8008FEC8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008FECC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008FED0: sh          $a1, -0x68DC($at)
    MEM_H(-0X68DC, ctx->r1) = ctx->r5;
    // 0x8008FED4: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8008FED8: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x8008FEDC: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8008FEE0: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8008FEE4: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
L_8008FEE8:
    // 0x8008FEE8: bne         $t2, $zero, L_8008FCD8
    if (ctx->r10 != 0) {
        // 0x8008FEEC: addu        $t1, $zero, $zero
        ctx->r9 = ADD32(0, 0);
            goto L_8008FCD8;
    }
    // 0x8008FEEC: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
L_8008FEF0:
    // 0x8008FEF0: andi        $v1, $t3, 0xFFFF
    ctx->r3 = ctx->r11 & 0XFFFF;
    // 0x8008FEF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008FEF8: bne         $v1, $v0, L_8008FF48
    if (ctx->r3 != ctx->r2) {
        // 0x8008FEFC: nop
    
            goto L_8008FF48;
    }
    // 0x8008FEFC: nop

    // 0x8008FF00: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x8008FF04: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x8008FF08: lw          $v0, 0x8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X8);
    // 0x8008FF0C: sh          $zero, 0xA($t5)
    MEM_H(0XA, ctx->r13) = 0;
    // 0x8008FF10: j           L_8008FFA0
    // 0x8008FF14: sh          $v0, 0x8($t5)
    MEM_H(0X8, ctx->r13) = ctx->r2;
        goto L_8008FFA0;
    // 0x8008FF14: sh          $v0, 0x8($t5)
    MEM_H(0X8, ctx->r13) = ctx->r2;
L_8008FF18:
    // 0x8008FF18: andi        $v0, $t3, 0xFFFF
    ctx->r2 = ctx->r11 & 0XFFFF;
    // 0x8008FF1C: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    // 0x8008FF20: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008FF24: addu        $v0, $v0, $sp
    ctx->r2 = ADD32(ctx->r2, ctx->r29);
    // 0x8008FF28: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x8008FF2C: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8008FF30: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8008FF34: subu        $v1, $t4, $a1
    ctx->r3 = SUB32(ctx->r12, ctx->r5);
    // 0x8008FF38: sw          $t4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r12;
    // 0x8008FF3C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8008FF40: j           L_8008FCA4
    // 0x8008FF44: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
        goto L_8008FCA4;
    // 0x8008FF44: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
L_8008FF48:
    // 0x8008FF48: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x8008FF4C: lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X14);
    // 0x8008FF50: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8008FF54: beq         $v0, $zero, L_8008FF80
    if (ctx->r2 == 0) {
        // 0x8008FF58: nop
    
            goto L_8008FF80;
    }
    // 0x8008FF58: nop

    // 0x8008FF5C: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x8008FF60: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x8008FF64: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x8008FF68: sw          $v0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r2;
    // 0x8008FF6C: lw          $v0, 0x8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X8);
    // 0x8008FF70: sh          $v0, 0x8($t5)
    MEM_H(0X8, ctx->r13) = ctx->r2;
    // 0x8008FF74: lw          $v0, 0xC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC);
    // 0x8008FF78: j           L_8008FFA0
    // 0x8008FF7C: sh          $v0, 0xA($t5)
    MEM_H(0XA, ctx->r13) = ctx->r2;
        goto L_8008FFA0;
    // 0x8008FF7C: sh          $v0, 0xA($t5)
    MEM_H(0XA, ctx->r13) = ctx->r2;
L_8008FF80:
    // 0x8008FF80: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x8008FF84: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x8008FF88: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x8008FF8C: sw          $v0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r2;
    // 0x8008FF90: lw          $v0, 0xC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC);
    // 0x8008FF94: sh          $v0, 0x8($t5)
    MEM_H(0X8, ctx->r13) = ctx->r2;
    // 0x8008FF98: lw          $v0, 0x8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X8);
    // 0x8008FF9C: sh          $v0, 0xA($t5)
    MEM_H(0XA, ctx->r13) = ctx->r2;
L_8008FFA0:
    // 0x8008FFA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FFA4: jr          $ra
    // 0x8008FFA8: nop

    return;
    // 0x8008FFA8: nop

;}
RECOMP_FUNC void func_8008FFAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FFAC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8008FFB0: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8008FFB4: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8008FFB8: sw          $ra, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r31;
    // 0x8008FFBC: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8008FFC0: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8008FFC4: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8008FFC8: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8008FFCC: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8008FFD0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8008FFD4: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8008FFD8: sdc1        $f20, 0x58($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X58, ctx->r29);
    // 0x8008FFDC: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x8008FFE0: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x8008FFE4: andi        $v1, $s5, 0xFFFF
    ctx->r3 = ctx->r21 & 0XFFFF;
    // 0x8008FFE8: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008FFEC: mflo        $v0
    ctx->r2 = lo;
    // 0x8008FFF0: ldc1        $f12, 0x8($s1)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r17, 0X8);
    // 0x8008FFF4: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // 0x8008FFF8: addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // 0x8008FFFC: lbu         $s7, 0x73($sp)
    ctx->r23 = MEM_BU(ctx->r29, 0X73);
    // 0x80090000: addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
    // 0x80090004: jal         0x80093E54
    // 0x80090008: srl         $s4, $v0, 12
    ctx->r20 = S32(U32(ctx->r2) >> 12);
    func_80093E54(rdram, ctx);
        goto after_0;
    // 0x80090008: srl         $s4, $v0, 12
    ctx->r20 = S32(U32(ctx->r2) >> 12);
    after_0:
    // 0x8009000C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80090010: ldc1        $f4, -0x2258($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2258);
    // 0x80090014: mov.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.d = ctx->f0.d;
    // 0x80090018: c.le.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d <= ctx->f2.d;
    // 0x8009001C: nop

    // 0x80090020: bc1t        L_80090038
    if (c1cs) {
        // 0x80090024: addiu       $s4, $s4, 0x6
        ctx->r20 = ADD32(ctx->r20, 0X6);
            goto L_80090038;
    }
    // 0x80090024: addiu       $s4, $s4, 0x6
    ctx->r20 = ADD32(ctx->r20, 0X6);
    // 0x80090028: trunc.w.d   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x8009002C: mfc1        $a0, $f0
    ctx->r4 = (int32_t)ctx->f0.u32l;
    // 0x80090030: j           L_8009004C
    // 0x80090034: nop

        goto L_8009004C;
    // 0x80090034: nop

L_80090038:
    // 0x80090038: sub.d       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f2.d - ctx->f4.d;
    // 0x8009003C: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80090040: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x80090044: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80090048: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
L_8009004C:
    // 0x8009004C: lw          $v1, 0x3C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X3C);
    // 0x80090050: lw          $v0, 0x40($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X40);
    // 0x80090054: beq         $v0, $zero, L_80090078
    if (ctx->r2 == 0) {
        // 0x80090058: addu        $a2, $v1, $v0
        ctx->r6 = ADD32(ctx->r3, ctx->r2);
            goto L_80090078;
    }
    // 0x80090058: addu        $a2, $v1, $v0
    ctx->r6 = ADD32(ctx->r3, ctx->r2);
    // 0x8009005C: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x80090060: subu        $v1, $v0, $a2
    ctx->r3 = SUB32(ctx->r2, ctx->r6);
    // 0x80090064: sltiu       $v0, $v1, 0xA
    ctx->r2 = ctx->r3 < 0XA ? 1 : 0;
    // 0x80090068: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8009006C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80090070: j           L_8009007C
    // 0x80090074: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
        goto L_8009007C;
    // 0x80090074: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
L_80090078:
    // 0x80090078: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8009007C:
    // 0x8009007C: lw          $a3, 0x40($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X40);
    // 0x80090080: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80090084: beq         $a3, $zero, L_80090150
    if (ctx->r7 == 0) {
        // 0x80090088: sb          $v0, 0x28($sp)
        MEM_B(0X28, ctx->r29) = ctx->r2;
            goto L_80090150;
    }
    // 0x80090088: sb          $v0, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r2;
    // 0x8009008C: lbu         $v0, 0x1($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1);
    // 0x80090090: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80090094: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80090098: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8009009C: beq         $v0, $zero, L_80090150
    if (ctx->r2 == 0) {
        // 0x800900A0: sltu        $v0, $a2, $a0
        ctx->r2 = ctx->r6 < ctx->r4 ? 1 : 0;
            goto L_80090150;
    }
    // 0x800900A0: sltu        $v0, $a2, $a0
    ctx->r2 = ctx->r6 < ctx->r4 ? 1 : 0;
    // 0x800900A4: bne         $v0, $zero, L_80090150
    if (ctx->r2 != 0) {
        // 0x800900A8: addu        $v0, $a0, $s4
        ctx->r2 = ADD32(ctx->r4, ctx->r20);
            goto L_80090150;
    }
    // 0x800900A8: addu        $v0, $a0, $s4
    ctx->r2 = ADD32(ctx->r4, ctx->r20);
    // 0x800900AC: sltu        $v0, $a2, $v0
    ctx->r2 = ctx->r6 < ctx->r2 ? 1 : 0;
    // 0x800900B0: beq         $v0, $zero, L_80090188
    if (ctx->r2 == 0) {
        // 0x800900B4: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_80090188;
    }
    // 0x800900B4: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x800900B8: lw          $a1, 0x3C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X3C);
    // 0x800900BC: sltu        $v0, $a1, $a0
    ctx->r2 = ctx->r5 < ctx->r4 ? 1 : 0;
    // 0x800900C0: bne         $v0, $zero, L_800900F4
    if (ctx->r2 != 0) {
        // 0x800900C4: subu        $v1, $a2, $a0
        ctx->r3 = SUB32(ctx->r6, ctx->r4);
            goto L_800900F4;
    }
    // 0x800900C4: subu        $v1, $a2, $a0
    ctx->r3 = SUB32(ctx->r6, ctx->r4);
    // 0x800900C8: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x800900CC: lw          $v0, 0x3C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X3C);
    // 0x800900D0: lw          $v1, 0x40($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X40);
    // 0x800900D4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800900D8: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800900DC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800900E0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800900E4: lw          $v0, 0x3C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X3C);
    // 0x800900E8: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x800900EC: j           L_8009019C
    // 0x800900F0: subu        $s2, $v0, $a0
    ctx->r18 = SUB32(ctx->r2, ctx->r4);
        goto L_8009019C;
    // 0x800900F0: subu        $s2, $v0, $a0
    ctx->r18 = SUB32(ctx->r2, ctx->r4);
L_800900F4:
    // 0x800900F4: subu        $a2, $s4, $v1
    ctx->r6 = SUB32(ctx->r20, ctx->r3);
    // 0x800900F8: sltu        $v0, $a3, $a2
    ctx->r2 = ctx->r7 < ctx->r6 ? 1 : 0;
    // 0x800900FC: bnel        $v0, $zero, L_80090118
    if (ctx->r2 != 0) {
        // 0x80090100: sw          $a1, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r5;
            goto L_80090118;
    }
    goto skip_0;
    // 0x80090100: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    skip_0:
    // 0x80090104: subu        $v0, $a0, $a1
    ctx->r2 = SUB32(ctx->r4, ctx->r5);
    // 0x80090108: sltu        $v0, $a2, $v0
    ctx->r2 = ctx->r6 < ctx->r2 ? 1 : 0;
    // 0x8009010C: bne         $v0, $zero, L_80090130
    if (ctx->r2 != 0) {
        // 0x80090110: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_80090130;
    }
    // 0x80090110: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80090114: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
L_80090118:
    // 0x80090118: lw          $v0, 0x40($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X40);
    // 0x8009011C: subu        $s3, $a0, $a1
    ctx->r19 = SUB32(ctx->r4, ctx->r5);
    // 0x80090120: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80090124: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80090128: j           L_8009019C
    // 0x8009012C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
        goto L_8009019C;
    // 0x8009012C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
L_80090130:
    // 0x80090130: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x80090134: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80090138: lw          $v1, 0x3C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X3C);
    // 0x8009013C: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80090140: addiu       $v0, $a2, -0x6
    ctx->r2 = ADD32(ctx->r6, -0X6);
    // 0x80090144: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80090148: j           L_8009019C
    // 0x8009014C: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
        goto L_8009019C;
    // 0x8009014C: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
L_80090150:
    // 0x80090150: lw          $v1, 0x38($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X38);
    // 0x80090154: addu        $v0, $a0, $s4
    ctx->r2 = ADD32(ctx->r4, ctx->r20);
    // 0x80090158: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8009015C: bne         $v0, $zero, L_80090188
    if (ctx->r2 != 0) {
        // 0x80090160: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_80090188;
    }
    // 0x80090160: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80090164: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x80090168: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x8009016C: addiu       $s2, $zero, -0x2
    ctx->r18 = ADD32(0, -0X2);
    // 0x80090170: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80090174: sb          $zero, 0x28($sp)
    MEM_B(0X28, ctx->r29) = 0;
    // 0x80090178: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8009017C: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80090180: j           L_8009019C
    // 0x80090184: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
        goto L_8009019C;
    // 0x80090184: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
L_80090188:
    // 0x80090188: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x8009018C: addiu       $v0, $s4, -0x6
    ctx->r2 = ADD32(ctx->r20, -0X6);
    // 0x80090190: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x80090194: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80090198: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8009019C:
    // 0x8009019C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800901A0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800901A4: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x800901A8: beq         $a0, $zero, L_800901B8
    if (ctx->r4 == 0) {
        // 0x800901AC: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_800901B8;
    }
    // 0x800901AC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800901B0: addiu       $v0, $a0, 0x6
    ctx->r2 = ADD32(ctx->r4, 0X6);
    // 0x800901B4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_800901B8:
    // 0x800901B8: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
    // 0x800901BC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800901C0: beq         $v0, $zero, L_8009046C
    if (ctx->r2 == 0) {
        // 0x800901C4: nop
    
            goto L_8009046C;
    }
    // 0x800901C4: nop

    // 0x800901C8: lbu         $v1, 0x6D($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6D);
    // 0x800901CC: beq         $v1, $zero, L_80090358
    if (ctx->r3 == 0) {
        // 0x800901D0: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80090358;
    }
    // 0x800901D0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800901D4: bne         $v1, $v0, L_8009071C
    if (ctx->r3 != ctx->r2) {
        // 0x800901D8: nop
    
            goto L_8009071C;
    }
    // 0x800901D8: nop

    // 0x800901DC: beq         $a0, $zero, L_8009025C
    if (ctx->r4 == 0) {
        // 0x800901E0: addiu       $a0, $s0, 0x34
        ctx->r4 = ADD32(ctx->r16, 0X34);
            goto L_8009025C;
    }
    // 0x800901E0: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x800901E4: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x800901E8: andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // 0x800901EC: sh          $v0, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r2;
    // 0x800901F0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800901F4: lhu         $a1, 0x4A($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X4A);
    // 0x800901F8: sh          $v0, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r2;
    // 0x800901FC: lw          $a3, 0x14($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X14);
    // 0x80090200: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80090204: andi        $v1, $a1, 0x1F
    ctx->r3 = ctx->r5 & 0X1F;
    // 0x80090208: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8009020C: addiu       $v0, $v0, 0x1F
    ctx->r2 = ADD32(ctx->r2, 0X1F);
    // 0x80090210: sra         $v0, $v0, 5
    ctx->r2 = S32(SIGNED(ctx->r2) >> 5);
    // 0x80090214: srl         $a1, $a1, 5
    ctx->r5 = S32(U32(ctx->r5) >> 5);
    // 0x80090218: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8009021C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80090220: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80090224: sll         $a2, $v0, 2
    ctx->r6 = S32(ctx->r2 << 2);
    // 0x80090228: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8009022C: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    // 0x80090230: srl         $a3, $a3, 6
    ctx->r7 = S32(U32(ctx->r7) >> 6);
    // 0x80090234: sll         $a1, $a3, 2
    ctx->r5 = S32(ctx->r7 << 2);
    // 0x80090238: addu        $a1, $a1, $a3
    ctx->r5 = ADD32(ctx->r5, ctx->r7);
    // 0x8009023C: lw          $a3, 0x34($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X34);
    // 0x80090240: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x80090244: addiu       $a1, $a1, 0x100
    ctx->r5 = ADD32(ctx->r5, 0X100);
    // 0x80090248: addu        $a1, $a3, $a1
    ctx->r5 = ADD32(ctx->r7, ctx->r5);
    // 0x8009024C: jal         0x8008FAAC
    // 0x80090250: addiu       $a3, $a3, 0x100
    ctx->r7 = ADD32(ctx->r7, 0X100);
    func_8008FAAC(rdram, ctx);
        goto after_1;
    // 0x80090250: addiu       $a3, $a3, 0x100
    ctx->r7 = ADD32(ctx->r7, 0X100);
    after_1:
    // 0x80090254: j           L_80090260
    // 0x80090258: nop

        goto L_80090260;
    // 0x80090258: nop

L_8009025C:
    // 0x8009025C: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
L_80090260:
    // 0x80090260: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80090264: andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // 0x80090268: sh          $v0, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r2;
    // 0x8009026C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80090270: lhu         $a1, 0x48($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X48);
    // 0x80090274: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80090278: sh          $v0, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r2;
    // 0x8009027C: lw          $a3, 0x10($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X10);
    // 0x80090280: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80090284: andi        $v1, $a1, 0x1F
    ctx->r3 = ctx->r5 & 0X1F;
    // 0x80090288: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8009028C: addiu       $v0, $v0, 0x1F
    ctx->r2 = ADD32(ctx->r2, 0X1F);
    // 0x80090290: sra         $v0, $v0, 5
    ctx->r2 = S32(SIGNED(ctx->r2) >> 5);
    // 0x80090294: srl         $a1, $a1, 5
    ctx->r5 = S32(U32(ctx->r5) >> 5);
    // 0x80090298: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8009029C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800902A0: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800902A4: sll         $a2, $v0, 2
    ctx->r6 = S32(ctx->r2 << 2);
    // 0x800902A8: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x800902AC: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    // 0x800902B0: srl         $a3, $a3, 6
    ctx->r7 = S32(U32(ctx->r7) >> 6);
    // 0x800902B4: sll         $a1, $a3, 2
    ctx->r5 = S32(ctx->r7 << 2);
    // 0x800902B8: addu        $a1, $a1, $a3
    ctx->r5 = ADD32(ctx->r5, ctx->r7);
    // 0x800902BC: lw          $a3, 0x34($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X34);
    // 0x800902C0: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x800902C4: addiu       $a1, $a1, 0x100
    ctx->r5 = ADD32(ctx->r5, 0X100);
    // 0x800902C8: addu        $a1, $a3, $a1
    ctx->r5 = ADD32(ctx->r7, ctx->r5);
    // 0x800902CC: jal         0x8008FAAC
    // 0x800902D0: addiu       $a3, $a3, 0x100
    ctx->r7 = ADD32(ctx->r7, 0X100);
    func_8008FAAC(rdram, ctx);
        goto after_2;
    // 0x800902D0: addiu       $a3, $a3, 0x100
    ctx->r7 = ADD32(ctx->r7, 0X100);
    after_2:
    // 0x800902D4: sh          $s3, 0x64($s0)
    MEM_H(0X64, ctx->r16) = ctx->r19;
    // 0x800902D8: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x800902DC: jal         0x8008F758
    // 0x800902E0: nop

    func_8008F758(rdram, ctx);
        goto after_3;
    // 0x800902E0: nop

    after_3:
    // 0x800902E4: sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
    // 0x800902E8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800902EC: beq         $s2, $v0, L_80090698
    if (ctx->r18 == ctx->r2) {
        // 0x800902F0: addiu       $v0, $zero, -0x2
        ctx->r2 = ADD32(0, -0X2);
            goto L_80090698;
    }
    // 0x800902F0: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // 0x800902F4: bne         $s2, $v0, L_80090328
    if (ctx->r18 != ctx->r2) {
        // 0x800902F8: nop
    
            goto L_80090328;
    }
    // 0x800902F8: nop

    // 0x800902FC: lhu         $v0, 0x48($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X48);
    // 0x80090300: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80090304: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x80090308: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8009030C: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x80090310: lhu         $v0, 0x48($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X48);
    // 0x80090314: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80090318: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x8009031C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80090320: j           L_80090718
    // 0x80090324: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
        goto L_80090718;
    // 0x80090324: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
L_80090328:
    // 0x80090328: lhu         $v0, 0x48($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X48);
    // 0x8009032C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80090330: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80090334: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x80090338: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8009033C: beq         $a0, $zero, L_8009070C
    if (ctx->r4 == 0) {
        // 0x80090340: sw          $v0, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->r2;
            goto L_8009070C;
    }
    // 0x80090340: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x80090344: lhu         $v0, 0x4A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4A);
    // 0x80090348: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x8009034C: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80090350: j           L_80090718
    // 0x80090354: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
        goto L_80090718;
    // 0x80090354: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
L_80090358:
    // 0x80090358: beq         $a0, $zero, L_800903AC
    if (ctx->r4 == 0) {
        // 0x8009035C: addiu       $a0, $s0, 0x34
        ctx->r4 = ADD32(ctx->r16, 0X34);
            goto L_800903AC;
    }
    // 0x8009035C: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x80090360: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x80090364: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x80090368: sh          $v0, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r2;
    // 0x8009036C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80090370: lhu         $a2, 0x4A($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X4A);
    // 0x80090374: sh          $v0, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r2;
    // 0x80090378: lw          $a1, 0x14($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14);
    // 0x8009037C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80090380: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x80090384: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x80090388: andi        $a2, $a2, 0xFFFC
    ctx->r6 = ctx->r6 & 0XFFFC;
    // 0x8009038C: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x80090390: lw          $a3, 0x34($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X34);
    // 0x80090394: andi        $a1, $a1, 0xFFFC
    ctx->r5 = ctx->r5 & 0XFFFC;
    // 0x80090398: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x8009039C: jal         0x8008FAAC
    // 0x800903A0: addu        $a1, $a3, $a1
    ctx->r5 = ADD32(ctx->r7, ctx->r5);
    func_8008FAAC(rdram, ctx);
        goto after_4;
    // 0x800903A0: addu        $a1, $a3, $a1
    ctx->r5 = ADD32(ctx->r7, ctx->r5);
    after_4:
    // 0x800903A4: j           L_800903B0
    // 0x800903A8: nop

        goto L_800903B0;
    // 0x800903A8: nop

L_800903AC:
    // 0x800903AC: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
L_800903B0:
    // 0x800903B0: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x800903B4: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x800903B8: sh          $v0, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r2;
    // 0x800903BC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800903C0: lhu         $a2, 0x48($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X48);
    // 0x800903C4: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x800903C8: sh          $v0, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r2;
    // 0x800903CC: lw          $a1, 0x10($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X10);
    // 0x800903D0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800903D4: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x800903D8: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x800903DC: andi        $a2, $a2, 0xFFFC
    ctx->r6 = ctx->r6 & 0XFFFC;
    // 0x800903E0: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x800903E4: lw          $a3, 0x34($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X34);
    // 0x800903E8: andi        $a1, $a1, 0xFFFC
    ctx->r5 = ctx->r5 & 0XFFFC;
    // 0x800903EC: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x800903F0: jal         0x8008FAAC
    // 0x800903F4: addu        $a1, $a3, $a1
    ctx->r5 = ADD32(ctx->r7, ctx->r5);
    func_8008FAAC(rdram, ctx);
        goto after_5;
    // 0x800903F4: addu        $a1, $a3, $a1
    ctx->r5 = ADD32(ctx->r7, ctx->r5);
    after_5:
    // 0x800903F8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800903FC: beq         $s2, $v0, L_80090698
    if (ctx->r18 == ctx->r2) {
        // 0x80090400: sh          $s3, 0x64($s0)
        MEM_H(0X64, ctx->r16) = ctx->r19;
            goto L_80090698;
    }
    // 0x80090400: sh          $s3, 0x64($s0)
    MEM_H(0X64, ctx->r16) = ctx->r19;
    // 0x80090404: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // 0x80090408: bne         $s2, $v0, L_8009043C
    if (ctx->r18 != ctx->r2) {
        // 0x8009040C: nop
    
            goto L_8009043C;
    }
    // 0x8009040C: nop

    // 0x80090410: lhu         $v0, 0x48($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X48);
    // 0x80090414: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80090418: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x8009041C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80090420: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x80090424: lhu         $v0, 0x48($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X48);
    // 0x80090428: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8009042C: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x80090430: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80090434: j           L_80090718
    // 0x80090438: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
        goto L_80090718;
    // 0x80090438: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
L_8009043C:
    // 0x8009043C: lhu         $v0, 0x48($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X48);
    // 0x80090440: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80090444: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80090448: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x8009044C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80090450: beq         $a0, $zero, L_8009070C
    if (ctx->r4 == 0) {
        // 0x80090454: sw          $v0, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->r2;
            goto L_8009070C;
    }
    // 0x80090454: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x80090458: lhu         $v0, 0x4A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4A);
    // 0x8009045C: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x80090460: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80090464: j           L_80090718
    // 0x80090468: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
        goto L_80090718;
    // 0x80090468: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
L_8009046C:
    // 0x8009046C: lbu         $v1, 0x6D($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6D);
    // 0x80090470: beq         $v1, $zero, L_800905EC
    if (ctx->r3 == 0) {
        // 0x80090474: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800905EC;
    }
    // 0x80090474: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80090478: bne         $v1, $v0, L_8009071C
    if (ctx->r3 != ctx->r2) {
        // 0x8009047C: nop
    
            goto L_8009071C;
    }
    // 0x8009047C: nop

    // 0x80090480: beql        $a0, $zero, L_800904FC
    if (ctx->r4 == 0) {
        // 0x80090484: sw          $zero, 0x34($s0)
        MEM_W(0X34, ctx->r16) = 0;
            goto L_800904FC;
    }
    goto skip_1;
    // 0x80090484: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    skip_1:
    // 0x80090488: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x8009048C: andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // 0x80090490: sh          $v0, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r2;
    // 0x80090494: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80090498: lhu         $a0, 0x4A($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X4A);
    // 0x8009049C: sh          $v0, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r2;
    // 0x800904A0: lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X14);
    // 0x800904A4: lw          $a1, 0x34($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X34);
    // 0x800904A8: sh          $zero, 0x3E($s0)
    MEM_H(0X3E, ctx->r16) = 0;
    // 0x800904AC: srl         $v1, $v1, 6
    ctx->r3 = S32(U32(ctx->r3) >> 6);
    // 0x800904B0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800904B4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800904B8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800904BC: lhu         $v1, 0x46($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X46);
    // 0x800904C0: addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // 0x800904C4: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800904C8: andi        $v0, $a0, 0x1F
    ctx->r2 = ctx->r4 & 0X1F;
    // 0x800904CC: srl         $a0, $a0, 5
    ctx->r4 = S32(U32(ctx->r4) >> 5);
    // 0x800904D0: sw          $a1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r5;
    // 0x800904D4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800904D8: addiu       $v1, $v1, 0x1F
    ctx->r3 = ADD32(ctx->r3, 0X1F);
    // 0x800904DC: sra         $v1, $v1, 5
    ctx->r3 = S32(SIGNED(ctx->r3) >> 5);
    // 0x800904E0: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800904E4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800904E8: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800904EC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800904F0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800904F4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800904F8: sh          $v0, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r2;
L_800904FC:
    // 0x800904FC: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80090500: andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // 0x80090504: sh          $v0, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r2;
    // 0x80090508: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8009050C: lhu         $a0, 0x48($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X48);
    // 0x80090510: sh          $v0, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r2;
    // 0x80090514: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x80090518: lw          $a1, 0x34($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X34);
    // 0x8009051C: sh          $zero, 0x32($s0)
    MEM_H(0X32, ctx->r16) = 0;
    // 0x80090520: sh          $s3, 0x64($s0)
    MEM_H(0X64, ctx->r16) = ctx->r19;
    // 0x80090524: srl         $v1, $v1, 6
    ctx->r3 = S32(U32(ctx->r3) >> 6);
    // 0x80090528: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8009052C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80090530: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80090534: lhu         $v1, 0x44($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X44);
    // 0x80090538: addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // 0x8009053C: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80090540: andi        $v0, $a0, 0x1F
    ctx->r2 = ctx->r4 & 0X1F;
    // 0x80090544: srl         $a0, $a0, 5
    ctx->r4 = S32(U32(ctx->r4) >> 5);
    // 0x80090548: sw          $a1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r5;
    // 0x8009054C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80090550: addiu       $v1, $v1, 0x1F
    ctx->r3 = ADD32(ctx->r3, 0X1F);
    // 0x80090554: sra         $v1, $v1, 5
    ctx->r3 = S32(SIGNED(ctx->r3) >> 5);
    // 0x80090558: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8009055C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80090560: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80090564: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80090568: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8009056C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80090570: sh          $v0, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r2;
    // 0x80090574: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x80090578: sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
    // 0x8009057C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80090580: beq         $s2, $v0, L_80090698
    if (ctx->r18 == ctx->r2) {
        // 0x80090584: addiu       $v0, $zero, -0x2
        ctx->r2 = ADD32(0, -0X2);
            goto L_80090698;
    }
    // 0x80090584: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // 0x80090588: bne         $s2, $v0, L_800905BC
    if (ctx->r18 != ctx->r2) {
        // 0x8009058C: nop
    
            goto L_800905BC;
    }
    // 0x8009058C: nop

    // 0x80090590: lhu         $v0, 0x48($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X48);
    // 0x80090594: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80090598: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x8009059C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800905A0: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x800905A4: lhu         $v0, 0x48($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X48);
    // 0x800905A8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800905AC: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x800905B0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800905B4: j           L_80090718
    // 0x800905B8: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
        goto L_80090718;
    // 0x800905B8: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
L_800905BC:
    // 0x800905BC: lhu         $v0, 0x48($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X48);
    // 0x800905C0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800905C4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x800905C8: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x800905CC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800905D0: beq         $a0, $zero, L_8009070C
    if (ctx->r4 == 0) {
        // 0x800905D4: sw          $v0, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->r2;
            goto L_8009070C;
    }
    // 0x800905D4: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x800905D8: lhu         $v0, 0x4A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4A);
    // 0x800905DC: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x800905E0: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x800905E4: j           L_80090718
    // 0x800905E8: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
        goto L_80090718;
    // 0x800905E8: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
L_800905EC:
    // 0x800905EC: beql        $a0, $zero, L_80090640
    if (ctx->r4 == 0) {
        // 0x800905F0: sw          $zero, 0x34($s0)
        MEM_W(0X34, ctx->r16) = 0;
            goto L_80090640;
    }
    goto skip_2;
    // 0x800905F0: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    skip_2:
    // 0x800905F4: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x800905F8: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x800905FC: sh          $v0, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r2;
    // 0x80090600: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80090604: sh          $v0, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r2;
    // 0x80090608: lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X14);
    // 0x8009060C: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x80090610: lhu         $v0, 0x4A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4A);
    // 0x80090614: lhu         $a1, 0x46($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X46);
    // 0x80090618: sh          $zero, 0x3E($s0)
    MEM_H(0X3E, ctx->r16) = 0;
    // 0x8009061C: andi        $v1, $v1, 0xFFFC
    ctx->r3 = ctx->r3 & 0XFFFC;
    // 0x80090620: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80090624: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80090628: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8009062C: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x80090630: andi        $v0, $v0, 0xFFFC
    ctx->r2 = ctx->r2 & 0XFFFC;
    // 0x80090634: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80090638: sw          $a0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r4;
    // 0x8009063C: sh          $v0, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r2;
L_80090640:
    // 0x80090640: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80090644: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x80090648: sh          $v0, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r2;
    // 0x8009064C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80090650: sh          $v0, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r2;
    // 0x80090654: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x80090658: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x8009065C: lhu         $v0, 0x48($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X48);
    // 0x80090660: lhu         $a1, 0x44($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X44);
    // 0x80090664: sh          $zero, 0x32($s0)
    MEM_H(0X32, ctx->r16) = 0;
    // 0x80090668: sh          $s3, 0x64($s0)
    MEM_H(0X64, ctx->r16) = ctx->r19;
    // 0x8009066C: andi        $v1, $v1, 0xFFFC
    ctx->r3 = ctx->r3 & 0XFFFC;
    // 0x80090670: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80090674: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80090678: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8009067C: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x80090680: andi        $v0, $v0, 0xFFFC
    ctx->r2 = ctx->r2 & 0XFFFC;
    // 0x80090684: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80090688: sh          $v0, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r2;
    // 0x8009068C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80090690: bne         $s2, $v0, L_800906A4
    if (ctx->r18 != ctx->r2) {
        // 0x80090694: sw          $a0, 0x28($s0)
        MEM_W(0X28, ctx->r16) = ctx->r4;
            goto L_800906A4;
    }
    // 0x80090694: sw          $a0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r4;
L_80090698:
    // 0x80090698: addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
    // 0x8009069C: j           L_8009071C
    // 0x800906A0: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
        goto L_8009071C;
    // 0x800906A0: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
L_800906A4:
    // 0x800906A4: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // 0x800906A8: bne         $s2, $v0, L_800906DC
    if (ctx->r18 != ctx->r2) {
        // 0x800906AC: nop
    
            goto L_800906DC;
    }
    // 0x800906AC: nop

    // 0x800906B0: lhu         $v0, 0x48($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X48);
    // 0x800906B4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800906B8: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x800906BC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800906C0: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x800906C4: lhu         $v0, 0x48($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X48);
    // 0x800906C8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800906CC: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x800906D0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800906D4: j           L_80090718
    // 0x800906D8: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
        goto L_80090718;
    // 0x800906D8: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
L_800906DC:
    // 0x800906DC: lhu         $v0, 0x48($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X48);
    // 0x800906E0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800906E4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x800906E8: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x800906EC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800906F0: beq         $a0, $zero, L_8009070C
    if (ctx->r4 == 0) {
        // 0x800906F4: sw          $v0, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->r2;
            goto L_8009070C;
    }
    // 0x800906F4: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x800906F8: lhu         $v0, 0x4A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4A);
    // 0x800906FC: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x80090700: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80090704: j           L_80090718
    // 0x80090708: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
        goto L_80090718;
    // 0x80090708: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
L_8009070C:
    // 0x8009070C: lhu         $v0, 0x48($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X48);
    // 0x80090710: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x80090714: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
L_80090718:
    // 0x80090718: sw          $v0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r2;
L_8009071C:
    // 0x8009071C: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x80090720: sb          $v0, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r2;
    // 0x80090724: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x80090728: sh          $v0, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r2;
    // 0x8009072C: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x80090730: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80090734: bne         $v1, $v0, L_80090748
    if (ctx->r3 != ctx->r2) {
        // 0x80090738: nop
    
            goto L_80090748;
    }
    // 0x80090738: nop

    // 0x8009073C: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x80090740: j           L_80090750
    // 0x80090744: sh          $v0, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r2;
        goto L_80090750;
    // 0x80090744: sh          $v0, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r2;
L_80090748:
    // 0x80090748: lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X6);
    // 0x8009074C: sh          $v0, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r2;
L_80090750:
    // 0x80090750: lw          $v1, 0x4C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4C);
    // 0x80090754: andi        $v0, $s6, 0xFFFF
    ctx->r2 = ctx->r22 & 0XFFFF;
    // 0x80090758: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8009075C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80090760: sw          $v1, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r3;
    // 0x80090764: ldc1        $f0, 0x8($s1)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r17, 0X8);
    // 0x80090768: sh          $s5, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r21;
    // 0x8009076C: sh          $s4, 0x62($s0)
    MEM_H(0X62, ctx->r16) = ctx->r20;
    // 0x80090770: sdc1        $f0, 0x50($s0)
    CHECK_FR(ctx, 0);
    SD(ctx->f0.u64, 0X50, ctx->r16);
    // 0x80090774: lbu         $v1, 0x6D($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6D);
    // 0x80090778: addiu       $v0, $s1, 0x78
    ctx->r2 = ADD32(ctx->r17, 0X78);
    // 0x8009077C: sw          $v0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r2;
    // 0x80090780: sb          $v1, 0x21($s0)
    MEM_B(0X21, ctx->r16) = ctx->r3;
    // 0x80090784: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
    // 0x80090788: andi        $v0, $s5, 0xFFFF
    ctx->r2 = ctx->r21 & 0XFFFF;
    // 0x8009078C: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80090790: mflo        $v1
    ctx->r3 = lo;
    // 0x80090794: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80090798: ldc1        $f2, -0x2250($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2250);
    // 0x8009079C: lw          $a0, 0x40($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X40);
    // 0x800907A0: sb          $s7, 0x84($s1)
    MEM_B(0X84, ctx->r17) = ctx->r23;
    // 0x800907A4: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x800907A8: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x800907AC: beq         $a0, $zero, L_800907C0
    if (ctx->r4 == 0) {
        // 0x800907B0: div.d       $f20, $f0, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f20.d = DIV_D(ctx->f0.d, ctx->f2.d);
            goto L_800907C0;
    }
    // 0x800907B0: div.d       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f20.d = DIV_D(ctx->f0.d, ctx->f2.d);
    // 0x800907B4: lbu         $v0, 0x1($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1);
    // 0x800907B8: bne         $v0, $zero, L_80090828
    if (ctx->r2 != 0) {
        // 0x800907BC: nop
    
            goto L_80090828;
    }
    // 0x800907BC: nop

L_800907C0:
    // 0x800907C0: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x800907C4: ldc1        $f0, 0x8($s1)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r17, 0X8);
    // 0x800907C8: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800907CC: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x800907D0: bgez        $v0, L_800907E4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800907D4: add.d       $f12, $f0, $f20
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f20.d); 
    ctx->f12.d = ctx->f0.d + ctx->f20.d;
            goto L_800907E4;
    }
    // 0x800907D4: add.d       $f12, $f0, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f20.d); 
    ctx->f12.d = ctx->f0.d + ctx->f20.d;
    // 0x800907D8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800907DC: ldc1        $f0, -0x2248($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2248);
    // 0x800907E0: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
L_800907E4:
    // 0x800907E4: c.le.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d <= ctx->f12.d;
    // 0x800907E8: nop

    // 0x800907EC: bc1f        L_8009081C
    if (!c1cs) {
        // 0x800907F0: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8009081C;
    }
    // 0x800907F0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800907F4: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800907F8: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x800907FC: bgez        $v0, L_80090810
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80090800: nop
    
            goto L_80090810;
    }
    // 0x80090800: nop

    // 0x80090804: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80090808: ldc1        $f0, -0x2240($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2240);
    // 0x8009080C: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
L_80090810:
    // 0x80090810: sdc1        $f2, 0x8($s1)
    CHECK_FR(ctx, 2);
    SD(ctx->f2.u64, 0X8, ctx->r17);
    // 0x80090814: j           L_800908DC
    // 0x80090818: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
        goto L_800908DC;
    // 0x80090818: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_8009081C:
    // 0x8009081C: sdc1        $f12, 0x8($s1)
    CHECK_FR(ctx, 12);
    SD(ctx->f12.u64, 0X8, ctx->r17);
    // 0x80090820: j           L_800908DC
    // 0x80090824: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
        goto L_800908DC;
    // 0x80090824: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_80090828:
    // 0x80090828: lw          $v0, 0x3C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X3C);
    // 0x8009082C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80090830: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x80090834: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x80090838: bgez        $v0, L_8009084C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8009083C: nop
    
            goto L_8009084C;
    }
    // 0x8009083C: nop

    // 0x80090840: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80090844: ldc1        $f0, -0x2238($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2238);
    // 0x80090848: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
L_8009084C:
    // 0x8009084C: ldc1        $f4, 0x8($s1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r17, 0X8);
    // 0x80090850: add.d       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f0.d = ctx->f4.d + ctx->f20.d;
    // 0x80090854: c.lt.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d < ctx->f2.d;
    // 0x80090858: nop

    // 0x8009085C: bc1t        L_800908D4
    if (c1cs) {
        // 0x80090860: nop
    
            goto L_800908D4;
    }
    // 0x80090860: nop

    // 0x80090864: sub.d       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f2.d - ctx->f4.d;
    // 0x80090868: mtc1        $a0, $f2
    ctx->f2.u32l = ctx->r4;
    // 0x8009086C: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x80090870: bgez        $a0, L_80090884
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80090874: sub.d       $f20, $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f20.d = ctx->f20.d - ctx->f0.d;
            goto L_80090884;
    }
    // 0x80090874: sub.d       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f20.d = ctx->f20.d - ctx->f0.d;
    // 0x80090878: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8009087C: ldc1        $f0, -0x2230($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2230);
    // 0x80090880: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
L_80090884:
    // 0x80090884: jal         0x80093E54
    // 0x80090888: div.d       $f12, $f20, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = DIV_D(ctx->f20.d, ctx->f2.d);
    func_80093E54(rdram, ctx);
        goto after_6;
    // 0x80090888: div.d       $f12, $f20, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = DIV_D(ctx->f20.d, ctx->f2.d);
    after_6:
    // 0x8009088C: lw          $v0, 0x40($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X40);
    // 0x80090890: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x80090894: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x80090898: bgez        $v0, L_800908AC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8009089C: mov.d       $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.d = ctx->f0.d;
            goto L_800908AC;
    }
    // 0x8009089C: mov.d       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.d = ctx->f0.d;
    // 0x800908A0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800908A4: ldc1        $f0, -0x2228($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2228);
    // 0x800908A8: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
L_800908AC:
    // 0x800908AC: mul.d       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x800908B0: lw          $v0, 0x3C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X3C);
    // 0x800908B4: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800908B8: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x800908BC: bgez        $v0, L_800908D0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800908C0: sub.d       $f20, $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f20.d = ctx->f20.d - ctx->f0.d;
            goto L_800908D0;
    }
    // 0x800908C0: sub.d       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f20.d = ctx->f20.d - ctx->f0.d;
    // 0x800908C4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800908C8: ldc1        $f0, -0x2220($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2220);
    // 0x800908CC: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
L_800908D0:
    // 0x800908D0: add.d       $f0, $f2, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f20.d); 
    ctx->f0.d = ctx->f2.d + ctx->f20.d;
L_800908D4:
    // 0x800908D4: sdc1        $f0, 0x8($s1)
    CHECK_FR(ctx, 0);
    SD(ctx->f0.u64, 0X8, ctx->r17);
    // 0x800908D8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_800908DC:
    // 0x800908DC: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x800908E0: andi        $a1, $s5, 0xFFFF
    ctx->r5 = ctx->r21 & 0XFFFF;
    // 0x800908E4: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x800908E8: jal         0x8008F4D8
    // 0x800908EC: sh          $v0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r2;
    func_8008F4D8(rdram, ctx);
        goto after_7;
    // 0x800908EC: sh          $v0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r2;
    after_7:
    // 0x800908F0: lh          $v0, 0x44($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X44);
    // 0x800908F4: lwc1        $f0, 0x5C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X5C);
    // 0x800908F8: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x800908FC: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80090900: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80090904: lh          $v0, 0x46($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X46);
    // 0x80090908: lwc1        $f0, 0x5C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X5C);
    // 0x8009090C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80090910: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80090914: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80090918: lh          $v0, 0x48($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X48);
    // 0x8009091C: lwc1        $f0, 0x5C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X5C);
    // 0x80090920: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80090924: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80090928: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8009092C: lh          $v0, 0x4A($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X4A);
    // 0x80090930: lwc1        $f2, 0x5C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X5C);
    // 0x80090934: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80090938: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8009093C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80090940: trunc.w.s   $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80090944: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80090948: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // 0x8009094C: lhu         $a1, 0x18($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X18);
    // 0x80090950: trunc.w.s   $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80090954: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x80090958: sh          $a0, 0x1A($s1)
    MEM_H(0X1A, ctx->r17) = ctx->r4;
    // 0x8009095C: trunc.w.s   $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80090960: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80090964: sh          $v0, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r2;
    // 0x80090968: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8009096C: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x80090970: sh          $v1, 0x1E($s1)
    MEM_H(0X1E, ctx->r17) = ctx->r3;
    // 0x80090974: sh          $a1, 0x66($s0)
    MEM_H(0X66, ctx->r16) = ctx->r5;
    // 0x80090978: lhu         $v0, 0x1A($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X1A);
    // 0x8009097C: sh          $v0, 0x68($s0)
    MEM_H(0X68, ctx->r16) = ctx->r2;
    // 0x80090980: lhu         $v0, 0x1C($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X1C);
    // 0x80090984: sh          $v0, 0x6A($s0)
    MEM_H(0X6A, ctx->r16) = ctx->r2;
    // 0x80090988: lhu         $v0, 0x1E($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X1E);
    // 0x8009098C: sh          $v0, 0x6C($s0)
    MEM_H(0X6C, ctx->r16) = ctx->r2;
    // 0x80090990: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x80090994: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80090998: bne         $v1, $v0, L_800909C0
    if (ctx->r3 != ctx->r2) {
        // 0x8009099C: nop
    
            goto L_800909C0;
    }
    // 0x8009099C: nop

    // 0x800909A0: lhu         $v0, 0x18($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X18);
    // 0x800909A4: lhu         $v1, 0x1A($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X1A);
    // 0x800909A8: lhu         $a0, 0x1C($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X1C);
    // 0x800909AC: lhu         $a1, 0x1E($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X1E);
    // 0x800909B0: sh          $v0, 0x20($s1)
    MEM_H(0X20, ctx->r17) = ctx->r2;
    // 0x800909B4: sh          $v1, 0x22($s1)
    MEM_H(0X22, ctx->r17) = ctx->r3;
    // 0x800909B8: sh          $a0, 0x24($s1)
    MEM_H(0X24, ctx->r17) = ctx->r4;
    // 0x800909BC: sh          $a1, 0x26($s1)
    MEM_H(0X26, ctx->r17) = ctx->r5;
L_800909C0:
    // 0x800909C0: lhu         $v0, 0x20($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X20);
    // 0x800909C4: sh          $v0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r2;
    // 0x800909C8: lhu         $v0, 0x22($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X22);
    // 0x800909CC: sh          $v0, 0x70($s0)
    MEM_H(0X70, ctx->r16) = ctx->r2;
    // 0x800909D0: lhu         $v0, 0x24($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X24);
    // 0x800909D4: sh          $v0, 0x72($s0)
    MEM_H(0X72, ctx->r16) = ctx->r2;
    // 0x800909D8: lhu         $v0, 0x26($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X26);
    // 0x800909DC: sh          $v0, 0x74($s0)
    MEM_H(0X74, ctx->r16) = ctx->r2;
    // 0x800909E0: lbu         $v0, 0x28($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X28);
    // 0x800909E4: lhu         $v1, 0x18($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X18);
    // 0x800909E8: lhu         $a0, 0x1A($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X1A);
    // 0x800909EC: lhu         $a1, 0x1C($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X1C);
    // 0x800909F0: lhu         $a2, 0x1E($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X1E);
    // 0x800909F4: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // 0x800909F8: sh          $v1, 0x20($s1)
    MEM_H(0X20, ctx->r17) = ctx->r3;
    // 0x800909FC: sh          $a0, 0x22($s1)
    MEM_H(0X22, ctx->r17) = ctx->r4;
    // 0x80090A00: sh          $a1, 0x24($s1)
    MEM_H(0X24, ctx->r17) = ctx->r5;
    // 0x80090A04: sh          $a2, 0x26($s1)
    MEM_H(0X26, ctx->r17) = ctx->r6;
    // 0x80090A08: lw          $ra, 0x50($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X50);
    // 0x80090A0C: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80090A10: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80090A14: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80090A18: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80090A1C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80090A20: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80090A24: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80090A28: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80090A2C: ldc1        $f20, 0x58($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X58);
    // 0x80090A30: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80090A34: jr          $ra
    // 0x80090A38: nop

    return;
    // 0x80090A38: nop

;}
RECOMP_FUNC void func_80090A3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090A3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80090A40: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80090A44: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80090A48: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80090A4C: lhu         $v1, -0x68A0($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X68A0);
    // 0x80090A50: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80090A54: lw          $a0, -0x68B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X68B0);
    // 0x80090A58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80090A5C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80090A60: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80090A64: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80090A68: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80090A6C: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80090A70: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80090A74: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80090A78: addu        $s2, $a0, $v0
    ctx->r18 = ADD32(ctx->r4, ctx->r2);
    // 0x80090A7C: lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X0);
    // 0x80090A80: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80090A84: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80090A88: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80090A8C: lbu         $v1, 0x21($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X21);
    // 0x80090A90: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80090A94: beq         $v1, $zero, L_80090BA0
    if (ctx->r3 == 0) {
        // 0x80090A98: addu        $s1, $s2, $v0
        ctx->r17 = ADD32(ctx->r18, ctx->r2);
            goto L_80090BA0;
    }
    // 0x80090A98: addu        $s1, $s2, $v0
    ctx->r17 = ADD32(ctx->r18, ctx->r2);
    // 0x80090A9C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80090AA0: bne         $v1, $v0, L_80090DE8
    if (ctx->r3 != ctx->r2) {
        // 0x80090AA4: nop
    
            goto L_80090DE8;
    }
    // 0x80090AA4: nop

    // 0x80090AA8: lhu         $v0, 0x24($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X24);
    // 0x80090AAC: sh          $v0, 0x22($s1)
    MEM_H(0X22, ctx->r17) = ctx->r2;
    // 0x80090AB0: ldc1        $f12, 0x50($s0)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r16, 0X50);
    // 0x80090AB4: jal         0x80093E54
    // 0x80090AB8: nop

    func_80093E54(rdram, ctx);
        goto after_0;
    // 0x80090AB8: nop

    after_0:
    // 0x80090ABC: ldc1        $f2, 0x50($s0)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r16, 0X50);
    // 0x80090AC0: sub.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d - ctx->f0.d;
    // 0x80090AC4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80090AC8: ldc1        $f0, -0x2218($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2218);
    // 0x80090ACC: mul.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f0.d);
    // 0x80090AD0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80090AD4: ldc1        $f0, -0x2210($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2210);
    // 0x80090AD8: c.le.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d <= ctx->f2.d;
    // 0x80090ADC: nop

    // 0x80090AE0: bc1tl       L_80090AF8
    if (c1cs) {
        // 0x80090AE4: sub.d       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
            goto L_80090AF8;
    }
    goto skip_0;
    // 0x80090AE4: sub.d       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
    skip_0:
    // 0x80090AE8: trunc.w.d   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x80090AEC: mfc1        $a0, $f0
    ctx->r4 = (int32_t)ctx->f0.u32l;
    // 0x80090AF0: j           L_80090B0C
    // 0x80090AF4: sh          $a0, 0x20($s1)
    MEM_H(0X20, ctx->r17) = ctx->r4;
        goto L_80090B0C;
    // 0x80090AF4: sh          $a0, 0x20($s1)
    MEM_H(0X20, ctx->r17) = ctx->r4;
L_80090AF8:
    // 0x80090AF8: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80090AFC: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x80090B00: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80090B04: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x80090B08: sh          $a0, 0x20($s1)
    MEM_H(0X20, ctx->r17) = ctx->r4;
L_80090B0C:
    // 0x80090B0C: lhu         $v0, 0x24($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X24);
    // 0x80090B10: lhu         $v1, 0x44($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X44);
    // 0x80090B14: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80090B18: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80090B1C: mflo        $v0
    ctx->r2 = lo;
    // 0x80090B20: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80090B24: sh          $v0, 0x4C($s1)
    MEM_H(0X4C, ctx->r17) = ctx->r2;
    // 0x80090B28: lhu         $v1, 0x48($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X48);
    // 0x80090B2C: lhu         $v0, 0x44($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X44);
    // 0x80090B30: andi        $v1, $v1, 0x1F
    ctx->r3 = ctx->r3 & 0X1F;
    // 0x80090B34: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80090B38: addiu       $v0, $v0, 0x1F
    ctx->r2 = ADD32(ctx->r2, 0X1F);
    // 0x80090B3C: sra         $v0, $v0, 5
    ctx->r2 = S32(SIGNED(ctx->r2) >> 5);
    // 0x80090B40: sb          $v0, 0x3C($s1)
    MEM_B(0X3C, ctx->r17) = ctx->r2;
    // 0x80090B44: lhu         $v0, 0x48($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X48);
    // 0x80090B48: sb          $v0, 0x3E($s1)
    MEM_B(0X3E, ctx->r17) = ctx->r2;
    // 0x80090B4C: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x80090B50: lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C);
    // 0x80090B54: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80090B58: sw          $v0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r2;
    // 0x80090B5C: sw          $v1, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r3;
    // 0x80090B60: sw          $a0, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r4;
    // 0x80090B64: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    // 0x80090B68: sw          $v0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->r2;
    // 0x80090B6C: lhu         $v0, 0x64($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X64);
    // 0x80090B70: sh          $v0, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r2;
    // 0x80090B74: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80090B78: beql        $v0, $zero, L_80090C88
    if (ctx->r2 == 0) {
        // 0x80090B7C: sb          $zero, 0x3D($s1)
        MEM_B(0X3D, ctx->r17) = 0;
            goto L_80090C88;
    }
    goto skip_1;
    // 0x80090B7C: sb          $zero, 0x3D($s1)
    MEM_B(0X3D, ctx->r17) = 0;
    skip_1:
    // 0x80090B80: lhu         $v1, 0x4A($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X4A);
    // 0x80090B84: lhu         $v0, 0x46($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X46);
    // 0x80090B88: andi        $v1, $v1, 0x1F
    ctx->r3 = ctx->r3 & 0X1F;
    // 0x80090B8C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80090B90: addiu       $v0, $v0, 0x1F
    ctx->r2 = ADD32(ctx->r2, 0X1F);
    // 0x80090B94: sra         $v0, $v0, 5
    ctx->r2 = S32(SIGNED(ctx->r2) >> 5);
    // 0x80090B98: j           L_80090C68
    // 0x80090B9C: sb          $v0, 0x3D($s1)
    MEM_B(0X3D, ctx->r17) = ctx->r2;
        goto L_80090C68;
    // 0x80090B9C: sb          $v0, 0x3D($s1)
    MEM_B(0X3D, ctx->r17) = ctx->r2;
L_80090BA0:
    // 0x80090BA0: lhu         $v0, 0x24($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X24);
    // 0x80090BA4: sh          $v0, 0x22($s1)
    MEM_H(0X22, ctx->r17) = ctx->r2;
    // 0x80090BA8: ldc1        $f12, 0x50($s0)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r16, 0X50);
    // 0x80090BAC: jal         0x80093E54
    // 0x80090BB0: nop

    func_80093E54(rdram, ctx);
        goto after_1;
    // 0x80090BB0: nop

    after_1:
    // 0x80090BB4: ldc1        $f2, 0x50($s0)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r16, 0X50);
    // 0x80090BB8: sub.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d - ctx->f0.d;
    // 0x80090BBC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80090BC0: ldc1        $f0, -0x2208($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2208);
    // 0x80090BC4: mul.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f0.d);
    // 0x80090BC8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80090BCC: ldc1        $f0, -0x2200($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2200);
    // 0x80090BD0: c.le.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d <= ctx->f2.d;
    // 0x80090BD4: nop

    // 0x80090BD8: bc1tl       L_80090BF0
    if (c1cs) {
        // 0x80090BDC: sub.d       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
            goto L_80090BF0;
    }
    goto skip_2;
    // 0x80090BDC: sub.d       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
    skip_2:
    // 0x80090BE0: trunc.w.d   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x80090BE4: mfc1        $a0, $f0
    ctx->r4 = (int32_t)ctx->f0.u32l;
    // 0x80090BE8: j           L_80090C04
    // 0x80090BEC: sh          $a0, 0x20($s1)
    MEM_H(0X20, ctx->r17) = ctx->r4;
        goto L_80090C04;
    // 0x80090BEC: sh          $a0, 0x20($s1)
    MEM_H(0X20, ctx->r17) = ctx->r4;
L_80090BF0:
    // 0x80090BF0: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80090BF4: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x80090BF8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80090BFC: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x80090C00: sh          $a0, 0x20($s1)
    MEM_H(0X20, ctx->r17) = ctx->r4;
L_80090C04:
    // 0x80090C04: lhu         $v0, 0x24($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X24);
    // 0x80090C08: lhu         $v1, 0x44($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X44);
    // 0x80090C0C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80090C10: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80090C14: mflo        $v0
    ctx->r2 = lo;
    // 0x80090C18: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80090C1C: sh          $v0, 0x4C($s1)
    MEM_H(0X4C, ctx->r17) = ctx->r2;
    // 0x80090C20: lhu         $v0, 0x44($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X44);
    // 0x80090C24: sb          $zero, 0x3C($s1)
    MEM_B(0X3C, ctx->r17) = 0;
    // 0x80090C28: sh          $v0, 0x40($s1)
    MEM_H(0X40, ctx->r17) = ctx->r2;
    // 0x80090C2C: lhu         $v0, 0x48($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X48);
    // 0x80090C30: sb          $v0, 0x3E($s1)
    MEM_B(0X3E, ctx->r17) = ctx->r2;
    // 0x80090C34: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x80090C38: lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C);
    // 0x80090C3C: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80090C40: sw          $v0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r2;
    // 0x80090C44: sw          $v1, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r3;
    // 0x80090C48: sw          $a0, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r4;
    // 0x80090C4C: lhu         $v0, 0x64($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X64);
    // 0x80090C50: sh          $v0, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r2;
    // 0x80090C54: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80090C58: beql        $v0, $zero, L_80090C88
    if (ctx->r2 == 0) {
        // 0x80090C5C: sh          $zero, 0x42($s1)
        MEM_H(0X42, ctx->r17) = 0;
            goto L_80090C88;
    }
    goto skip_3;
    // 0x80090C5C: sh          $zero, 0x42($s1)
    MEM_H(0X42, ctx->r17) = 0;
    skip_3:
    // 0x80090C60: lhu         $v0, 0x46($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X46);
    // 0x80090C64: sh          $v0, 0x42($s1)
    MEM_H(0X42, ctx->r17) = ctx->r2;
L_80090C68:
    // 0x80090C68: lhu         $v0, 0x4A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4A);
    // 0x80090C6C: sb          $v0, 0x3F($s1)
    MEM_B(0X3F, ctx->r17) = ctx->r2;
    // 0x80090C70: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80090C74: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x80090C78: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80090C7C: sw          $v0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r2;
    // 0x80090C80: sw          $v1, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r3;
    // 0x80090C84: sw          $a0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->r4;
L_80090C88:
    // 0x80090C88: lw          $v0, 0x58($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X58);
    // 0x80090C8C: sh          $v0, 0x48($s1)
    MEM_H(0X48, ctx->r17) = ctx->r2;
    // 0x80090C90: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x80090C94: sw          $zero, 0x44($s1)
    MEM_W(0X44, ctx->r17) = 0;
    // 0x80090C98: sh          $v0, 0x4A($s1)
    MEM_H(0X4A, ctx->r17) = ctx->r2;
    // 0x80090C9C: lh          $v0, 0x6E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6E);
    // 0x80090CA0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80090CA4: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80090CA8: lh          $v0, 0x70($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X70);
    // 0x80090CAC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80090CB0: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x80090CB4: lh          $v0, 0x72($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X72);
    // 0x80090CB8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80090CBC: sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    // 0x80090CC0: lh          $v0, 0x74($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X74);
    // 0x80090CC4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80090CC8: sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // 0x80090CCC: lh          $v0, 0x66($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X66);
    // 0x80090CD0: lh          $v1, 0x6E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X6E);
    // 0x80090CD4: lhu         $a0, 0x60($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X60);
    // 0x80090CD8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80090CDC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80090CE0: div         $zero, $v0, $a0
    if (S32(ctx->r4) != 0) { lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4))); } else { lo = 0; hi = S32(ctx->r2); }
    // 0x80090CE4: bne         $a0, $zero, L_80090CF0
    if (ctx->r4 != 0) {
        // 0x80090CE8: nop
    
            goto L_80090CF0;
    }
    // 0x80090CE8: nop

    // 0x80090CEC: break       7
    do_break(2148076780);
L_80090CF0:
    // 0x80090CF0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80090CF4: bne         $a0, $at, L_80090D08
    if (ctx->r4 != ctx->r1) {
        // 0x80090CF8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80090D08;
    }
    // 0x80090CF8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80090CFC: bne         $v0, $at, L_80090D08
    if (ctx->r2 != ctx->r1) {
        // 0x80090D00: nop
    
            goto L_80090D08;
    }
    // 0x80090D00: nop

    // 0x80090D04: break       6
    do_break(2148076804);
L_80090D08:
    // 0x80090D08: mflo        $v0
    ctx->r2 = lo;
    // 0x80090D0C: sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
    // 0x80090D10: lh          $v0, 0x68($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X68);
    // 0x80090D14: lh          $v1, 0x70($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X70);
    // 0x80090D18: lhu         $a0, 0x60($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X60);
    // 0x80090D1C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80090D20: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80090D24: div         $zero, $v0, $a0
    if (S32(ctx->r4) != 0) { lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4))); } else { lo = 0; hi = S32(ctx->r2); }
    // 0x80090D28: bne         $a0, $zero, L_80090D34
    if (ctx->r4 != 0) {
        // 0x80090D2C: nop
    
            goto L_80090D34;
    }
    // 0x80090D2C: nop

    // 0x80090D30: break       7
    do_break(2148076848);
L_80090D34:
    // 0x80090D34: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80090D38: bne         $a0, $at, L_80090D4C
    if (ctx->r4 != ctx->r1) {
        // 0x80090D3C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80090D4C;
    }
    // 0x80090D3C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80090D40: bne         $v0, $at, L_80090D4C
    if (ctx->r2 != ctx->r1) {
        // 0x80090D44: nop
    
            goto L_80090D4C;
    }
    // 0x80090D44: nop

    // 0x80090D48: break       6
    do_break(2148076872);
L_80090D4C:
    // 0x80090D4C: mflo        $v0
    ctx->r2 = lo;
    // 0x80090D50: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // 0x80090D54: lh          $v0, 0x6A($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6A);
    // 0x80090D58: lh          $v1, 0x72($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X72);
    // 0x80090D5C: lhu         $a0, 0x60($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X60);
    // 0x80090D60: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80090D64: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80090D68: div         $zero, $v0, $a0
    if (S32(ctx->r4) != 0) { lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4))); } else { lo = 0; hi = S32(ctx->r2); }
    // 0x80090D6C: bne         $a0, $zero, L_80090D78
    if (ctx->r4 != 0) {
        // 0x80090D70: nop
    
            goto L_80090D78;
    }
    // 0x80090D70: nop

    // 0x80090D74: break       7
    do_break(2148076916);
L_80090D78:
    // 0x80090D78: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80090D7C: bne         $a0, $at, L_80090D90
    if (ctx->r4 != ctx->r1) {
        // 0x80090D80: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80090D90;
    }
    // 0x80090D80: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80090D84: bne         $v0, $at, L_80090D90
    if (ctx->r2 != ctx->r1) {
        // 0x80090D88: nop
    
            goto L_80090D90;
    }
    // 0x80090D88: nop

    // 0x80090D8C: break       6
    do_break(2148076940);
L_80090D90:
    // 0x80090D90: mflo        $v0
    ctx->r2 = lo;
    // 0x80090D94: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    // 0x80090D98: lh          $v0, 0x6C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6C);
    // 0x80090D9C: lh          $v1, 0x74($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X74);
    // 0x80090DA0: lhu         $a0, 0x60($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X60);
    // 0x80090DA4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80090DA8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80090DAC: div         $zero, $v0, $a0
    if (S32(ctx->r4) != 0) { lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4))); } else { lo = 0; hi = S32(ctx->r2); }
    // 0x80090DB0: bne         $a0, $zero, L_80090DBC
    if (ctx->r4 != 0) {
        // 0x80090DB4: nop
    
            goto L_80090DBC;
    }
    // 0x80090DB4: nop

    // 0x80090DB8: break       7
    do_break(2148076984);
L_80090DBC:
    // 0x80090DBC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80090DC0: bne         $a0, $at, L_80090DD4
    if (ctx->r4 != ctx->r1) {
        // 0x80090DC4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80090DD4;
    }
    // 0x80090DC4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80090DC8: bne         $v0, $at, L_80090DD4
    if (ctx->r2 != ctx->r1) {
        // 0x80090DCC: nop
    
            goto L_80090DD4;
    }
    // 0x80090DCC: nop

    // 0x80090DD0: break       6
    do_break(2148077008);
L_80090DD4:
    // 0x80090DD4: mflo        $v0
    ctx->r2 = lo;
    // 0x80090DD8: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    // 0x80090DDC: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x80090DE0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80090DE4: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
L_80090DE8:
    // 0x80090DE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80090DEC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80090DF0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80090DF4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80090DF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80090DFC: jr          $ra
    // 0x80090E00: nop

    return;
    // 0x80090E00: nop

;}
RECOMP_FUNC void func_80090E04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090E04: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80090E08: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80090E0C: addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // 0x80090E10: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80090E14: lbu         $v0, -0x68FE($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X68FE);
    // 0x80090E18: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80090E1C: lhu         $a0, -0x6900($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X6900);
    // 0x80090E20: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80090E24: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80090E28: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80090E2C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80090E30: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80090E34: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80090E38: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80090E3C: addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // 0x80090E40: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80090E44: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x80090E48: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80090E4C: addiu       $v1, $v1, -0x68F0
    ctx->r3 = ADD32(ctx->r3, -0X68F0);
    // 0x80090E50: sw          $ra, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r31;
    // 0x80090E54: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80090E58: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80090E5C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80090E60: beq         $a0, $zero, L_80090F5C
    if (ctx->r4 == 0) {
        // 0x80090E64: addu        $s1, $v0, $v1
        ctx->r17 = ADD32(ctx->r2, ctx->r3);
            goto L_80090F5C;
    }
    // 0x80090E64: addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // 0x80090E68: lui         $s4, 0x8015
    ctx->r20 = S32(0X8015 << 16);
    // 0x80090E6C: addiu       $s4, $s4, -0x68F8
    ctx->r20 = ADD32(ctx->r20, -0X68F8);
    // 0x80090E70: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
L_80090E74:
    // 0x80090E74: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80090E78: lw          $a0, -0x6908($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6908);
    // 0x80090E7C: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80090E80: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80090E84: sll         $a1, $v0, 3
    ctx->r5 = S32(ctx->r2 << 3);
    // 0x80090E88: addu        $v1, $a1, $a0
    ctx->r3 = ADD32(ctx->r5, ctx->r4);
    // 0x80090E8C: lbu         $v0, 0x85($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X85);
    // 0x80090E90: beq         $v0, $zero, L_80090EB8
    if (ctx->r2 == 0) {
        // 0x80090E94: nop
    
            goto L_80090EB8;
    }
    // 0x80090E94: nop

    // 0x80090E98: sb          $zero, 0x85($v1)
    MEM_B(0X85, ctx->r3) = 0;
    // 0x80090E9C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80090EA0: lw          $v0, -0x6908($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6908);
    // 0x80090EA4: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x80090EA8: lbu         $v1, 0x84($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X84);
    // 0x80090EAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80090EB0: sllv        $v0, $v0, $v1
    ctx->r2 = S32(ctx->r2 << (ctx->r3 & 31));
    // 0x80090EB4: or          $s3, $s3, $v0
    ctx->r19 = ctx->r19 | ctx->r2;
L_80090EB8:
    // 0x80090EB8: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80090EBC: lw          $v0, -0x6908($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6908);
    // 0x80090EC0: addu        $a0, $a1, $v0
    ctx->r4 = ADD32(ctx->r5, ctx->r2);
    // 0x80090EC4: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80090EC8: beq         $v0, $zero, L_80090F40
    if (ctx->r2 == 0) {
        // 0x80090ECC: andi        $a1, $s6, 0xFFFF
        ctx->r5 = ctx->r22 & 0XFFFF;
            goto L_80090F40;
    }
    // 0x80090ECC: andi        $a1, $s6, 0xFFFF
    ctx->r5 = ctx->r22 & 0XFFFF;
    // 0x80090ED0: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80090ED4: lbu         $v0, -0x68FE($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X68FE);
    // 0x80090ED8: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x80090EDC: andi        $a2, $s5, 0xFFFF
    ctx->r6 = ctx->r21 & 0XFFFF;
    // 0x80090EE0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80090EE4: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x80090EE8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80090EEC: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x80090EF0: sll         $a3, $v1, 4
    ctx->r7 = S32(ctx->r3 << 4);
    // 0x80090EF4: addu        $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
    // 0x80090EF8: sll         $a3, $a3, 3
    ctx->r7 = S32(ctx->r7 << 3);
    // 0x80090EFC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80090F00: jal         0x8008FFAC
    // 0x80090F04: addu        $a3, $t0, $a3
    ctx->r7 = ADD32(ctx->r8, ctx->r7);
    func_8008FFAC(rdram, ctx);
        goto after_0;
    // 0x80090F04: addu        $a3, $t0, $a3
    ctx->r7 = ADD32(ctx->r8, ctx->r7);
    after_0:
    // 0x80090F08: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    // 0x80090F0C: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80090F10: lbu         $v1, -0x68FE($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X68FE);
    // 0x80090F14: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80090F18: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80090F1C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80090F20: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x80090F24: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x80090F28: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80090F2C: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x80090F30: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80090F34: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80090F38: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80090F3C: sb          $zero, 0x22($v0)
    MEM_B(0X22, ctx->r2) = 0;
L_80090F40:
    // 0x80090F40: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80090F44: lhu         $v1, -0x6900($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X6900);
    // 0x80090F48: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80090F4C: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x80090F50: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80090F54: bne         $v0, $zero, L_80090E74
    if (ctx->r2 != 0) {
        // 0x80090F58: andi        $v1, $s0, 0xFFFF
        ctx->r3 = ctx->r16 & 0XFFFF;
            goto L_80090E74;
    }
    // 0x80090F58: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
L_80090F5C:
    // 0x80090F5C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80090F60: lbu         $v0, -0x68FE($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X68FE);
    // 0x80090F64: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x80090F68: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80090F6C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090F70: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80090F74: lw          $a0, -0x68F8($at)
    ctx->r4 = MEM_W(ctx->r1, -0X68F8);
    // 0x80090F78: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80090F7C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80090F80: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80090F84: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80090F88: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80090F8C: sb          $v1, 0x22($v0)
    MEM_B(0X22, ctx->r2) = ctx->r3;
    // 0x80090F90: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80090F94: lbu         $v1, -0x68FE($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X68FE);
    // 0x80090F98: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80090F9C: addiu       $v0, $v0, -0x68F8
    ctx->r2 = ADD32(ctx->r2, -0X68F8);
    // 0x80090FA0: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    // 0x80090FA4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80090FA8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80090FAC: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80090FB0: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x80090FB4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80090FB8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80090FBC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80090FC0: sw          $s7, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r23;
    // 0x80090FC4: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    // 0x80090FC8: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80090FCC: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x80090FD0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80090FD4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80090FD8: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80090FDC: sh          $s5, 0x80($v0)
    MEM_H(0X80, ctx->r2) = ctx->r21;
    // 0x80090FE0: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    // 0x80090FE4: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80090FE8: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x80090FEC: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80090FF0: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x80090FF4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80090FF8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80090FFC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80091000: sw          $s3, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r19;
    // 0x80091004: lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X48);
    // 0x80091008: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8009100C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80091010: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80091014: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80091018: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8009101C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80091020: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80091024: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80091028: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8009102C: jr          $ra
    // 0x80091030: nop

    return;
    // 0x80091030: nop

;}
RECOMP_FUNC void func_80091034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091034: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80091038: lbu         $v0, -0x68FE($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X68FE);
    // 0x8009103C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80091040: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80091044: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80091048: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009104C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80091050: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80091054: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80091058: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009105C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80091060: lw          $v0, -0x68A8($at)
    ctx->r2 = MEM_W(ctx->r1, -0X68A8);
    // 0x80091064: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x80091068: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009106C: sh          $zero, -0x68A0($at)
    MEM_H(-0X68A0, ctx->r1) = 0;
    // 0x80091070: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091074: sw          $v0, -0x68B0($at)
    MEM_W(-0X68B0, ctx->r1) = ctx->r2;
    // 0x80091078: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x8009107C: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
    // 0x80091080: beq         $v0, $zero, L_80091220
    if (ctx->r2 == 0) {
        // 0x80091084: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_80091220;
    }
    // 0x80091084: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80091088: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
L_8009108C:
    // 0x8009108C: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80091090: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80091094: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80091098: addu        $a1, $v1, $s1
    ctx->r5 = ADD32(ctx->r3, ctx->r17);
    // 0x8009109C: lbu         $v0, 0x22($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X22);
    // 0x800910A0: bne         $v0, $zero, L_800910B8
    if (ctx->r2 != 0) {
        // 0x800910A4: nop
    
            goto L_800910B8;
    }
    // 0x800910A4: nop

    // 0x800910A8: jal         0x80090A3C
    // 0x800910AC: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    func_80090A3C(rdram, ctx);
        goto after_0;
    // 0x800910AC: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    after_0:
    // 0x800910B0: j           L_8009120C
    // 0x800910B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_8009120C;
    // 0x800910B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800910B8:
    // 0x800910B8: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800910BC: lhu         $v0, -0x68A0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X68A0);
    // 0x800910C0: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800910C4: lw          $a0, -0x68B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X68B0);
    // 0x800910C8: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800910CC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800910D0: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800910D4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800910D8: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800910DC: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    // 0x800910E0: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800910E4: bne         $v0, $zero, L_800910FC
    if (ctx->r2 != 0) {
        // 0x800910E8: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800910FC;
    }
    // 0x800910E8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800910EC: sh          $zero, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = 0;
    // 0x800910F0: lw          $v0, 0x7C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X7C);
    // 0x800910F4: j           L_80091114
    // 0x800910F8: sw          $v0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r2;
        goto L_80091114;
    // 0x800910F8: sw          $v0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r2;
L_800910FC:
    // 0x800910FC: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80091100: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80091104: lw          $v0, 0x7C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X7C);
    // 0x80091108: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x8009110C: addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // 0x80091110: sw          $v0, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r2;
L_80091114:
    // 0x80091114: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80091118: lhu         $v1, -0x68A0($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X68A0);
    // 0x8009111C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80091120: lw          $a0, -0x68B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X68B0);
    // 0x80091124: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80091128: lw          $a1, -0x6898($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6898);
    // 0x8009112C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80091130: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80091134: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80091138: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8009113C: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80091140: lw          $v1, -0x689C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X689C);
    // 0x80091144: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80091148: addu        $a2, $v0, $a0
    ctx->r6 = ADD32(ctx->r2, ctx->r4);
    // 0x8009114C: sw          $v1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r3;
    // 0x80091150: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
    // 0x80091154: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80091158: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8009115C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80091160: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80091164: lw          $v0, 0x84($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X84);
    // 0x80091168: sw          $a1, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r5;
    // 0x8009116C: beq         $a1, $zero, L_800911BC
    if (ctx->r5 == 0) {
        // 0x80091170: sw          $v0, 0x4($a2)
        MEM_W(0X4, ctx->r6) = ctx->r2;
            goto L_800911BC;
    }
    // 0x80091170: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x80091174: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80091178: lw          $a0, -0x6894($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6894);
    // 0x8009117C: lui         $v0, 0x2AAA
    ctx->r2 = S32(0X2AAA << 16);
    // 0x80091180: ori         $v0, $v0, 0xAAAB
    ctx->r2 = ctx->r2 | 0XAAAB;
    // 0x80091184: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091188: sra         $v1, $a0, 31
    ctx->r3 = S32(SIGNED(ctx->r4) >> 31);
    // 0x8009118C: mfhi        $a3
    ctx->r7 = hi;
    // 0x80091190: sra         $v0, $a3, 5
    ctx->r2 = S32(SIGNED(ctx->r7) >> 5);
    // 0x80091194: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80091198: sh          $v0, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r2;
    // 0x8009119C: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x800911A0: addiu       $a0, $a0, 0xC0
    ctx->r4 = ADD32(ctx->r4, 0XC0);
    // 0x800911A4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800911A8: sw          $a0, -0x6894($at)
    MEM_W(-0X6894, ctx->r1) = ctx->r4;
    // 0x800911AC: bne         $a0, $v0, L_800911BC
    if (ctx->r4 != ctx->r2) {
        // 0x800911B0: nop
    
            goto L_800911BC;
    }
    // 0x800911B0: nop

    // 0x800911B4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800911B8: sw          $zero, -0x6894($at)
    MEM_W(-0X6894, ctx->r1) = 0;
L_800911BC:
    // 0x800911BC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800911C0: lhu         $v0, -0x68A0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X68A0);
    // 0x800911C4: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x800911C8: lhu         $v1, -0x68B2($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X68B2);
    // 0x800911CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800911D0: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x800911D4: sltu        $v1, $a0, $v1
    ctx->r3 = ctx->r4 < ctx->r3 ? 1 : 0;
    // 0x800911D8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800911DC: sh          $v0, -0x68A0($at)
    MEM_H(-0X68A0, ctx->r1) = ctx->r2;
    // 0x800911E0: beq         $v1, $zero, L_80091208
    if (ctx->r3 == 0) {
        // 0x800911E4: sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4 << 2);
            goto L_80091208;
    }
    // 0x800911E4: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800911E8: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x800911EC: lw          $v1, -0x68B0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X68B0);
    // 0x800911F0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800911F4: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800911F8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800911FC: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80091200: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80091204: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
L_80091208:
    // 0x80091208: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8009120C:
    // 0x8009120C: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x80091210: andi        $v1, $s2, 0xFFFF
    ctx->r3 = ctx->r18 & 0XFFFF;
    // 0x80091214: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80091218: bne         $v0, $zero, L_8009108C
    if (ctx->r2 != 0) {
        // 0x8009121C: andi        $v0, $s0, 0xFFFF
        ctx->r2 = ctx->r16 & 0XFFFF;
            goto L_8009108C;
    }
    // 0x8009121C: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
L_80091220:
    // 0x80091220: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80091224: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80091228: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8009122C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80091230: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80091234: jr          $ra
    // 0x80091238: nop

    return;
    // 0x80091238: nop

;}
RECOMP_FUNC void func_8009123C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009123C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80091240: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80091244: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80091248: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8009124C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80091250: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80091254: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80091258: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8009125C: jal         0x800920A4
    // 0x80091260: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    func_800920A4(rdram, ctx);
        goto after_0;
    // 0x80091260: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    after_0:
    // 0x80091264: jal         0x80023CC0
    // 0x80091268: nop

    func_80023CC0(rdram, ctx);
        goto after_1;
    // 0x80091268: nop

    after_1:
    // 0x8009126C: jal         0x8002BF00
    // 0x80091270: nop

    osGetTime_recomp(rdram, ctx);
        goto after_2;
    // 0x80091270: nop

    after_2:
    // 0x80091274: jal         0x8002C240
    // 0x80091278: addu        $s6, $v1, $zero
    ctx->r22 = ADD32(ctx->r3, 0);
    __osDisableInt_recomp(rdram, ctx);
        goto after_3;
    // 0x80091278: addu        $s6, $v1, $zero
    ctx->r22 = ADD32(ctx->r3, 0);
    after_3:
    // 0x8009127C: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80091280: lbu         $v1, -0x6910($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X6910);
    // 0x80091284: beq         $v1, $zero, L_8009129C
    if (ctx->r3 == 0) {
        // 0x80091288: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_8009129C;
    }
    // 0x80091288: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8009128C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80091290: lbu         $v0, -0x6910($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6910);
    // 0x80091294: j           L_800912A0
    // 0x80091298: addiu       $s4, $v0, -0x1
    ctx->r20 = ADD32(ctx->r2, -0X1);
        goto L_800912A0;
    // 0x80091298: addiu       $s4, $v0, -0x1
    ctx->r20 = ADD32(ctx->r2, -0X1);
L_8009129C:
    // 0x8009129C: addiu       $s4, $zero, 0xF
    ctx->r20 = ADD32(0, 0XF);
L_800912A0:
    // 0x800912A0: jal         0x8002C260
    // 0x800912A4: nop

    __osRestoreInt_recomp(rdram, ctx);
        goto after_4;
    // 0x800912A4: nop

    after_4:
    // 0x800912A8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800912AC: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x800912B0: beq         $v0, $zero, L_800912C0
    if (ctx->r2 == 0) {
        // 0x800912B4: nop
    
            goto L_800912C0;
    }
    // 0x800912B4: nop

    // 0x800912B8: jal         0x800998E8
    // 0x800912BC: nop

    func_800998E8(rdram, ctx);
        goto after_5;
    // 0x800912BC: nop

    after_5:
L_800912C0:
    // 0x800912C0: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x800912C4: lhu         $v1, -0x6678($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X6678);
    // 0x800912C8: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800912CC: beq         $v1, $v0, L_800917E0
    if (ctx->r3 == ctx->r2) {
        // 0x800912D0: nop

            goto L_800917E0;
    }
    // 0x800912D0: nop

    // 0x800912D4: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800912D8: lbu         $v0, -0x68B4($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X68B4);
    // 0x800912DC: beq         $v0, $zero, L_80091304
    if (ctx->r2 == 0) {
        // 0x800912E0: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80091304;
    }
    // 0x800912E0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800912E4: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800912E8: addiu       $a0, $a0, -0x68D0
    ctx->r4 = ADD32(ctx->r4, -0X68D0);
    // 0x800912EC: jal         0x800331D0
    // 0x800912F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x800912F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x800912F4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800912F8: sb          $zero, -0x68B4($at)
    MEM_B(-0X68B4, ctx->r1) = 0;
    // 0x800912FC: jal         0x80037510
    // 0x80091300: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_7;
    // 0x80091300: nop

    after_7:
L_80091304:
    // 0x80091304: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80091308: lbu         $v0, -0x68FE($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X68FE);
    // 0x8009130C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80091310: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80091314: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091318: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8009131C: lw          $a0, -0x68F8($at)
    ctx->r4 = MEM_W(ctx->r1, -0X68F8);
    // 0x80091320: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80091324: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091328: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8009132C: lhu         $a1, -0x68F0($at)
    ctx->r5 = MEM_HU(ctx->r1, -0X68F0);
    // 0x80091330: jal         0x80091034
    // 0x80091334: nop

    func_80091034(rdram, ctx);
        goto after_8;
    // 0x80091334: nop

    after_8:
    // 0x80091338: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8009133C: lw          $v1, -0x6650($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6650);
    // 0x80091340: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80091344: lbu         $v0, -0x68FE($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X68FE);
    // 0x80091348: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009134C: sh          $zero, -0x68DC($at)
    MEM_H(-0X68DC, ctx->r1) = 0;
    // 0x80091350: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80091354: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091358: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8009135C: sh          $zero, -0x68F0($at)
    MEM_H(-0X68F0, ctx->r1) = 0;
    // 0x80091360: beq         $v1, $zero, L_80091384
    if (ctx->r3 == 0) {
        // 0x80091364: nop
    
            goto L_80091384;
    }
    // 0x80091364: nop

L_80091368:
    // 0x80091368: lhu         $v0, 0x10($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X10);
    // 0x8009136C: beq         $v0, $zero, L_80091378
    if (ctx->r2 == 0) {
        // 0x80091370: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80091378;
    }
    // 0x80091370: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80091374: sh          $v0, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r2;
L_80091378:
    // 0x80091378: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8009137C: bne         $v1, $zero, L_80091368
    if (ctx->r3 != 0) {
        // 0x80091380: nop
    
            goto L_80091368;
    }
    // 0x80091380: nop

L_80091384:
    // 0x80091384: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80091388: lhu         $v1, -0x6678($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X6678);
    // 0x8009138C: andi        $v0, $s4, 0xFFFF
    ctx->r2 = ctx->r20 & 0XFFFF;
    // 0x80091390: beq         $v1, $v0, L_800916A8
    if (ctx->r3 == ctx->r2) {
        // 0x80091394: nop

            goto L_800916A8;
    }
    // 0x80091394: nop

    // 0x80091398: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8009139C: lhu         $v0, -0x6900($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6900);
    // 0x800913A0: blez        $v0, L_80091418
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800913A4: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80091418;
    }
    // 0x800913A4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800913A8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800913AC: ldc1        $f4, -0x21F8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X21F8);
    // 0x800913B0: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x800913B4: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x800913B8: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800913BC: lw          $a0, -0x6908($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6908);
L_800913C0:
    // 0x800913C0: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800913C4: beq         $v0, $zero, L_80091408
    if (ctx->r2 == 0) {
        // 0x800913C8: addu        $a2, $a0, $zero
        ctx->r6 = ADD32(ctx->r4, 0);
            goto L_80091408;
    }
    // 0x800913C8: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x800913CC: ldc1        $f2, 0x8($a0)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r4, 0X8);
    // 0x800913D0: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x800913D4: c.le.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d <= ctx->f2.d;
    // 0x800913D8: nop

    // 0x800913DC: bc1t        L_800913F4
    if (c1cs) {
        // 0x800913E0: sw          $v0, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->r2;
            goto L_800913F4;
    }
    // 0x800913E0: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    // 0x800913E4: trunc.w.d   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x800913E8: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x800913EC: j           L_80091408
    // 0x800913F0: sw          $v1, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r3;
        goto L_80091408;
    // 0x800913F0: sw          $v1, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r3;
L_800913F4:
    // 0x800913F4: sub.d       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f2.d - ctx->f4.d;
    // 0x800913F8: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x800913FC: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x80091400: or          $v1, $v1, $t0
    ctx->r3 = ctx->r3 | ctx->r8;
    // 0x80091404: sw          $v1, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r3;
L_80091408:
    // 0x80091408: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8009140C: slt         $v0, $a1, $a3
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80091410: bne         $v0, $zero, L_800913C0
    if (ctx->r2 != 0) {
        // 0x80091414: addiu       $a0, $a0, 0x88
        ctx->r4 = ADD32(ctx->r4, 0X88);
            goto L_800913C0;
    }
    // 0x80091414: addiu       $a0, $a0, 0x88
    ctx->r4 = ADD32(ctx->r4, 0X88);
L_80091418:
    // 0x80091418: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8009141C: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80091420: lhu         $v1, -0x6678($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X6678);
    // 0x80091424: andi        $a0, $s4, 0xFFFF
    ctx->r4 = ctx->r20 & 0XFFFF;
    // 0x80091428: sltu        $v0, $v1, $a0
    ctx->r2 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x8009142C: beq         $v0, $zero, L_800914E8
    if (ctx->r2 == 0) {
        // 0x80091430: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_800914E8;
    }
    // 0x80091430: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80091434: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    // 0x80091438: lui         $s5, 0x8015
    ctx->r21 = S32(0X8015 << 16);
    // 0x8009143C: addiu       $s5, $s5, -0x6950
    ctx->r21 = ADD32(ctx->r21, -0X6950);
    // 0x80091440: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
L_80091444:
    // 0x80091444: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80091448: lhu         $v1, -0x68B2($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X68B2);
    // 0x8009144C: andi        $v0, $s3, 0xFFFF
    ctx->r2 = ctx->r19 & 0XFFFF;
    // 0x80091450: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80091454: beq         $v0, $zero, L_80091654
    if (ctx->r2 == 0) {
        // 0x80091458: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_80091654;
    }
    // 0x80091458: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8009145C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80091460: lbu         $v1, 0xF50($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XF50);
    // 0x80091464: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80091468: beq         $v1, $zero, L_800914AC
    if (ctx->r3 == 0) {
        // 0x8009146C: addu        $s1, $v0, $zero
        ctx->r17 = ADD32(ctx->r2, 0);
            goto L_800914AC;
    }
    // 0x8009146C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80091470: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80091474: lw          $v0, -0x68EC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68EC);
    // 0x80091478: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009147C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091480: sw          $v0, -0x68EC($at)
    MEM_W(-0X68EC, ctx->r1) = ctx->r2;
    // 0x80091484: bne         $v0, $zero, L_800914B0
    if (ctx->r2 != 0) {
        // 0x80091488: andi        $v0, $s1, 0xFFFF
        ctx->r2 = ctx->r17 & 0XFFFF;
            goto L_800914B0;
    }
    // 0x80091488: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
    // 0x8009148C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80091490: lw          $v0, -0x68E8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68E8);
    // 0x80091494: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091498: sw          $v0, -0x68EC($at)
    MEM_W(-0X68EC, ctx->r1) = ctx->r2;
    // 0x8009149C: jal         0x80096D08
    // 0x800914A0: nop

    func_80096D08(rdram, ctx);
        goto after_9;
    // 0x800914A0: nop

    after_9:
    // 0x800914A4: jal         0x8008D960
    // 0x800914A8: nop

    func_8008D960(rdram, ctx);
        goto after_10;
    // 0x800914A8: nop

    after_10:
L_800914AC:
    // 0x800914AC: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
L_800914B0:
    // 0x800914B0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800914B4: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x800914B8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800914BC: andi        $a1, $s2, 0xFFFF
    ctx->r5 = ctx->r18 & 0XFFFF;
    // 0x800914C0: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    // 0x800914C4: addiu       $s2, $s2, 0xC0
    ctx->r18 = ADD32(ctx->r18, 0XC0);
    // 0x800914C8: jal         0x80090E04
    // 0x800914CC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    func_80090E04(rdram, ctx);
        goto after_11;
    // 0x800914CC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    after_11:
    // 0x800914D0: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x800914D4: sltu        $v0, $v0, $s4
    ctx->r2 = ctx->r2 < ctx->r20 ? 1 : 0;
    // 0x800914D8: beq         $v0, $zero, L_80091654
    if (ctx->r2 == 0) {
        // 0x800914DC: nop
    
            goto L_80091654;
    }
    // 0x800914DC: nop

    // 0x800914E0: j           L_80091444
    // 0x800914E4: nop

        goto L_80091444;
    // 0x800914E4: nop

L_800914E8:
    // 0x800914E8: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x800914EC: lhu         $s0, -0x6678($s0)
    ctx->r16 = MEM_HU(ctx->r16, -0X6678);
    // 0x800914F0: sltiu       $v0, $s0, 0x10
    ctx->r2 = ctx->r16 < 0X10 ? 1 : 0;
    // 0x800914F4: beq         $v0, $zero, L_800915A4
    if (ctx->r2 == 0) {
        // 0x800914F8: andi        $v0, $s4, 0xFFFF
        ctx->r2 = ctx->r20 & 0XFFFF;
            goto L_800915A4;
    }
    // 0x800914F8: andi        $v0, $s4, 0xFFFF
    ctx->r2 = ctx->r20 & 0XFFFF;
    // 0x800914FC: lui         $s5, 0x8015
    ctx->r21 = S32(0X8015 << 16);
    // 0x80091500: addiu       $s5, $s5, -0x6950
    ctx->r21 = ADD32(ctx->r21, -0X6950);
L_80091504:
    // 0x80091504: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80091508: lhu         $v1, -0x68B2($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X68B2);
    // 0x8009150C: andi        $v0, $s3, 0xFFFF
    ctx->r2 = ctx->r19 & 0XFFFF;
    // 0x80091510: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80091514: beq         $v0, $zero, L_800915A0
    if (ctx->r2 == 0) {
        // 0x80091518: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_800915A0;
    }
    // 0x80091518: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8009151C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80091520: lbu         $v1, 0xF50($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XF50);
    // 0x80091524: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80091528: beq         $v1, $zero, L_8009156C
    if (ctx->r3 == 0) {
        // 0x8009152C: addu        $s1, $v0, $zero
        ctx->r17 = ADD32(ctx->r2, 0);
            goto L_8009156C;
    }
    // 0x8009152C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80091530: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80091534: lw          $v0, -0x68EC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68EC);
    // 0x80091538: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009153C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091540: sw          $v0, -0x68EC($at)
    MEM_W(-0X68EC, ctx->r1) = ctx->r2;
    // 0x80091544: bne         $v0, $zero, L_80091570
    if (ctx->r2 != 0) {
        // 0x80091548: andi        $v0, $s1, 0xFFFF
        ctx->r2 = ctx->r17 & 0XFFFF;
            goto L_80091570;
    }
    // 0x80091548: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
    // 0x8009154C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80091550: lw          $v0, -0x68E8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68E8);
    // 0x80091554: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091558: sw          $v0, -0x68EC($at)
    MEM_W(-0X68EC, ctx->r1) = ctx->r2;
    // 0x8009155C: jal         0x80096D08
    // 0x80091560: nop

    func_80096D08(rdram, ctx);
        goto after_12;
    // 0x80091560: nop

    after_12:
    // 0x80091564: jal         0x8008D960
    // 0x80091568: nop

    func_8008D960(rdram, ctx);
        goto after_13;
    // 0x80091568: nop

    after_13:
L_8009156C:
    // 0x8009156C: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
L_80091570:
    // 0x80091570: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80091574: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x80091578: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009157C: andi        $a1, $s2, 0xFFFF
    ctx->r5 = ctx->r18 & 0XFFFF;
    // 0x80091580: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    // 0x80091584: addiu       $s2, $s2, 0xC0
    ctx->r18 = ADD32(ctx->r18, 0XC0);
    // 0x80091588: jal         0x80090E04
    // 0x8009158C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    func_80090E04(rdram, ctx);
        goto after_14;
    // 0x8009158C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    after_14:
    // 0x80091590: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x80091594: sltiu       $v0, $v0, 0x10
    ctx->r2 = ctx->r2 < 0X10 ? 1 : 0;
    // 0x80091598: bne         $v0, $zero, L_80091504
    if (ctx->r2 != 0) {
        // 0x8009159C: nop
    
            goto L_80091504;
    }
    // 0x8009159C: nop

L_800915A0:
    // 0x800915A0: andi        $v0, $s4, 0xFFFF
    ctx->r2 = ctx->r20 & 0XFFFF;
L_800915A4:
    // 0x800915A4: beq         $v0, $zero, L_80091654
    if (ctx->r2 == 0) {
        // 0x800915A8: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_80091654;
    }
    // 0x800915A8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800915AC: lui         $s5, 0x8015
    ctx->r21 = S32(0X8015 << 16);
    // 0x800915B0: addiu       $s5, $s5, -0x6950
    ctx->r21 = ADD32(ctx->r21, -0X6950);
    // 0x800915B4: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
L_800915B8:
    // 0x800915B8: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x800915BC: lhu         $v1, -0x68B2($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X68B2);
    // 0x800915C0: andi        $v0, $s3, 0xFFFF
    ctx->r2 = ctx->r19 & 0XFFFF;
    // 0x800915C4: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800915C8: beq         $v0, $zero, L_80091654
    if (ctx->r2 == 0) {
        // 0x800915CC: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_80091654;
    }
    // 0x800915CC: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x800915D0: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800915D4: lbu         $v1, 0xF50($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XF50);
    // 0x800915D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800915DC: beq         $v1, $zero, L_80091620
    if (ctx->r3 == 0) {
        // 0x800915E0: addu        $s1, $v0, $zero
        ctx->r17 = ADD32(ctx->r2, 0);
            goto L_80091620;
    }
    // 0x800915E0: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800915E4: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800915E8: lw          $v0, -0x68EC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68EC);
    // 0x800915EC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800915F0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800915F4: sw          $v0, -0x68EC($at)
    MEM_W(-0X68EC, ctx->r1) = ctx->r2;
    // 0x800915F8: bne         $v0, $zero, L_80091624
    if (ctx->r2 != 0) {
        // 0x800915FC: andi        $v0, $s1, 0xFFFF
        ctx->r2 = ctx->r17 & 0XFFFF;
            goto L_80091624;
    }
    // 0x800915FC: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
    // 0x80091600: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80091604: lw          $v0, -0x68E8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68E8);
    // 0x80091608: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009160C: sw          $v0, -0x68EC($at)
    MEM_W(-0X68EC, ctx->r1) = ctx->r2;
    // 0x80091610: jal         0x80096D08
    // 0x80091614: nop

    func_80096D08(rdram, ctx);
        goto after_15;
    // 0x80091614: nop

    after_15:
    // 0x80091618: jal         0x8008D960
    // 0x8009161C: nop

    func_8008D960(rdram, ctx);
        goto after_16;
    // 0x8009161C: nop

    after_16:
L_80091620:
    // 0x80091620: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
L_80091624:
    // 0x80091624: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80091628: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x8009162C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80091630: andi        $a1, $s2, 0xFFFF
    ctx->r5 = ctx->r18 & 0XFFFF;
    // 0x80091634: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    // 0x80091638: addiu       $s2, $s2, 0xC0
    ctx->r18 = ADD32(ctx->r18, 0XC0);
    // 0x8009163C: jal         0x80090E04
    // 0x80091640: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    func_80090E04(rdram, ctx);
        goto after_17;
    // 0x80091640: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    after_17:
    // 0x80091644: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x80091648: sltu        $v0, $v0, $s4
    ctx->r2 = ctx->r2 < ctx->r20 ? 1 : 0;
    // 0x8009164C: bne         $v0, $zero, L_800915B8
    if (ctx->r2 != 0) {
        // 0x80091650: nop
    
            goto L_800915B8;
    }
    // 0x80091650: nop

L_80091654:
    // 0x80091654: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80091658: lhu         $a1, -0x68DC($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X68DC);
    // 0x8009165C: beq         $a1, $zero, L_8009168C
    if (ctx->r5 == 0) {
        // 0x80091660: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8009168C;
    }
    // 0x80091660: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80091664: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80091668: lw          $a0, -0x68D8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X68D8);
    // 0x8009166C: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80091670: lw          $v1, -0x6624($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6624);
    // 0x80091674: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x80091678: addiu       $a2, $a2, -0x68D0
    ctx->r6 = ADD32(ctx->r6, -0X68D0);
    // 0x8009167C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091680: sb          $v0, -0x68B4($at)
    MEM_B(-0X68B4, ctx->r1) = ctx->r2;
    // 0x80091684: jalr        $v1
    // 0x80091688: nop

    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_18;
    // 0x80091688: nop

    after_18:
L_8009168C:
    // 0x8009168C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80091690: lhu         $v0, -0x6676($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6676);
    // 0x80091694: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091698: sh          $s0, -0x6678($at)
    MEM_H(-0X6678, ctx->r1) = ctx->r16;
    // 0x8009169C: subu        $v0, $v0, $s3
    ctx->r2 = SUB32(ctx->r2, ctx->r19);
    // 0x800916A0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800916A4: sh          $v0, -0x6676($at)
    MEM_H(-0X6676, ctx->r1) = ctx->r2;
L_800916A8:
    // 0x800916A8: jal         0x80097F54
    // 0x800916AC: nop

    func_80097F54(rdram, ctx);
        goto after_19;
    // 0x800916AC: nop

    after_19:
    // 0x800916B0: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800916B4: lbu         $v0, -0x68B3($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X68B3);
    // 0x800916B8: beq         $v0, $zero, L_800916E0
    if (ctx->r2 == 0) {
        // 0x800916BC: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800916E0;
    }
    // 0x800916BC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800916C0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800916C4: addiu       $a0, $a0, -0x5800
    ctx->r4 = ADD32(ctx->r4, -0X5800);
    // 0x800916C8: jal         0x800331D0
    // 0x800916CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_20;
    // 0x800916CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_20:
    // 0x800916D0: jal         0x8001A018
    // 0x800916D4: nop

    func_8001A018(rdram, ctx);
        goto after_21;
    // 0x800916D4: nop

    after_21:
    // 0x800916D8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800916DC: sb          $zero, -0x68B3($at)
    MEM_B(-0X68B3, ctx->r1) = 0;
L_800916E0:
    // 0x800916E0: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x800916E4: lhu         $a2, -0x68A0($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X68A0);
    // 0x800916E8: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800916EC: lw          $a0, -0x68B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X68B0);
    // 0x800916F0: beq         $a2, $zero, L_800917AC
    if (ctx->r6 == 0) {
        // 0x800916F4: sll         $a1, $a2, 2
        ctx->r5 = S32(ctx->r6 << 2);
            goto L_800917AC;
    }
    // 0x800916F4: sll         $a1, $a2, 2
    ctx->r5 = S32(ctx->r6 << 2);
    // 0x800916F8: addu        $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x800916FC: sll         $a1, $a1, 5
    ctx->r5 = S32(ctx->r5 << 5);
    // 0x80091700: addu        $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x80091704: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x80091708: addiu       $s0, $s0, -0x6B90
    ctx->r16 = ADD32(ctx->r16, -0X6B90);
    // 0x8009170C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80091710: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80091714: addiu       $v1, $v1, 0x25D0
    ctx->r3 = ADD32(ctx->r3, 0X25D0);
    // 0x80091718: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8009171C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80091720: addiu       $v0, $v0, 0x26A0
    ctx->r2 = ADD32(ctx->r2, 0X26A0);
    // 0x80091724: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80091728: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009172C: sw          $v0, -0x6B84($at)
    MEM_W(-0X6B84, ctx->r1) = ctx->r2;
    // 0x80091730: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80091734: addiu       $v0, $v0, -0x6020
    ctx->r2 = ADD32(ctx->r2, -0X6020);
    // 0x80091738: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009173C: sw          $v0, -0x6B80($at)
    MEM_W(-0X6B80, ctx->r1) = ctx->r2;
    // 0x80091740: addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // 0x80091744: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091748: sw          $v0, -0x6B7C($at)
    MEM_W(-0X6B7C, ctx->r1) = ctx->r2;
    // 0x8009174C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80091750: addiu       $v0, $v0, 0x4E00
    ctx->r2 = ADD32(ctx->r2, 0X4E00);
    // 0x80091754: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091758: sw          $v0, -0x6B78($at)
    MEM_W(-0X6B78, ctx->r1) = ctx->r2;
    // 0x8009175C: addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    // 0x80091760: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091764: sw          $zero, -0x6B8C($at)
    MEM_W(-0X6B8C, ctx->r1) = 0;
    // 0x80091768: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009176C: sw          $v1, -0x6B88($at)
    MEM_W(-0X6B88, ctx->r1) = ctx->r3;
    // 0x80091770: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091774: sw          $v0, -0x6B74($at)
    MEM_W(-0X6B74, ctx->r1) = ctx->r2;
    // 0x80091778: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009177C: sw          $a0, -0x6B60($at)
    MEM_W(-0X6B60, ctx->r1) = ctx->r4;
    // 0x80091780: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091784: sw          $a2, -0x6B5C($at)
    MEM_W(-0X6B5C, ctx->r1) = ctx->r6;
    // 0x80091788: jal         0x800358B0
    // 0x8009178C: sll         $a1, $a1, 4
    ctx->r5 = S32(ctx->r5 << 4);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_22;
    // 0x8009178C: sll         $a1, $a1, 4
    ctx->r5 = S32(ctx->r5 << 4);
    after_22:
    // 0x80091790: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80091794: lw          $v0, -0x6630($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6630);
    // 0x80091798: jalr        $v0
    // 0x8009179C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_23;
    // 0x8009179C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_23:
    // 0x800917A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800917A4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800917A8: sb          $v0, -0x68B3($at)
    MEM_B(-0X68B3, ctx->r1) = ctx->r2;
L_800917AC:
    // 0x800917AC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800917B0: lbu         $v0, -0x68FE($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X68FE);
    // 0x800917B4: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800917B8: lbu         $v1, 0xF50($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XF50);
    // 0x800917BC: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x800917C0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800917C4: sb          $v0, -0x68FE($at)
    MEM_B(-0X68FE, ctx->r1) = ctx->r2;
    // 0x800917C8: beq         $v1, $zero, L_800917E8
    if (ctx->r3 == 0) {
        // 0x800917CC: nop
    
            goto L_800917E8;
    }
    // 0x800917CC: nop

    // 0x800917D0: jal         0x80097DA8
    // 0x800917D4: nop

    func_80097DA8(rdram, ctx);
        goto after_24;
    // 0x800917D4: nop

    after_24:
    // 0x800917D8: j           L_800917E8
    // 0x800917DC: nop

        goto L_800917E8;
    // 0x800917DC: nop

L_800917E0:
    // 0x800917E0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800917E4: sh          $s4, -0x6678($at)
    MEM_H(-0X6678, ctx->r1) = ctx->r20;
L_800917E8:
    // 0x800917E8: jal         0x80023D08
    // 0x800917EC: nop

    func_80023D08(rdram, ctx);
        goto after_25;
    // 0x800917EC: nop

    after_25:
    // 0x800917F0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800917F4: sw          $v0, 0x1778($at)
    MEM_W(0X1778, ctx->r1) = ctx->r2;
    // 0x800917F8: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800917FC: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x80091800: bgez        $v0, L_80091814
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80091804: nop
    
            goto L_80091814;
    }
    // 0x80091804: nop

    // 0x80091808: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8009180C: ldc1        $f0, -0x21F0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X21F0);
    // 0x80091810: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
L_80091814:
    // 0x80091814: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80091818: lwc1        $f4, 0x176C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X176C);
    // 0x8009181C: cvt.s.d     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
    // 0x80091820: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80091824: lwc1        $f2, 0x1770($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X1770);
    // 0x80091828: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8009182C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80091830: lwc1        $f0, -0x21E8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X21E8);
    // 0x80091834: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80091838: div.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8009183C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80091840: swc1        $f4, 0x176C($at)
    MEM_W(0X176C, ctx->r1) = ctx->f4.u32l;
    // 0x80091844: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80091848: swc1        $f2, 0x1770($at)
    MEM_W(0X1770, ctx->r1) = ctx->f2.u32l;
    // 0x8009184C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80091850: swc1        $f0, 0x1774($at)
    MEM_W(0X1774, ctx->r1) = ctx->f0.u32l;
    // 0x80091854: jal         0x8002BF00
    // 0x80091858: nop

    osGetTime_recomp(rdram, ctx);
        goto after_26;
    // 0x80091858: nop

    after_26:
    // 0x8009185C: subu        $v1, $v1, $s6
    ctx->r3 = SUB32(ctx->r3, ctx->r22);
    // 0x80091860: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091864: sw          $v1, -0x6618($at)
    MEM_W(-0X6618, ctx->r1) = ctx->r3;
    // 0x80091868: jal         0x800920D0
    // 0x8009186C: nop

    func_800920D0(rdram, ctx);
        goto after_27;
    // 0x8009186C: nop

    after_27:
    // 0x80091870: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80091874: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80091878: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8009187C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80091880: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80091884: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80091888: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8009188C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80091890: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80091894: jr          $ra
    // 0x80091898: nop

    return;
    // 0x80091898: nop

;}
RECOMP_FUNC void func_8009189C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    { if(0) fprintf(stderr, "[trace] func_8009189C ENTRY (vtable register) a0=0x%08X\n", (uint32_t)ctx->r4); fflush(stderr); }
    // 0x8009189C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800918A0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800918A4: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800918A8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800918AC: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x800918B0: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800918B4: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x800918B8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800918BC: addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    // 0x800918C0: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x800918C4: sltiu       $v0, $v0, 0x21
    ctx->r2 = ctx->r2 < 0X21 ? 1 : 0;
    // 0x800918C8: bne         $v0, $zero, L_800918D4
    if (ctx->r2 != 0) {
        // 0x800918CC: sw          $ra, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r31;
            goto L_800918D4;
    }
    // 0x800918CC: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800918D0: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_800918D4:
    // 0x800918D4: lui         $v0, 0x8002
    ctx->r2 = S32(0X8002 << 16);
    // 0x800918D8: addiu       $v0, $v0, -0x5FA8
    ctx->r2 = ADD32(ctx->r2, -0X5FA8);
    // 0x800918DC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800918E0: sw          $v0, -0x6630($at)
    MEM_W(-0X6630, ctx->r1) = ctx->r2;
    // 0x800918E4: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800918E8: addiu       $v0, $v0, 0x569C
    ctx->r2 = ADD32(ctx->r2, 0X569C);
    // 0x800918EC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800918F0: sw          $v0, -0x6624($at)
    MEM_W(-0X6624, ctx->r1) = ctx->r2;
    // 0x800918F4: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800918F8: addiu       $v0, $v0, 0x7910
    ctx->r2 = ADD32(ctx->r2, 0X7910);
    // 0x800918FC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091900: sw          $v0, -0x662C($at)
    MEM_W(-0X662C, ctx->r1) = ctx->r2;
    // 0x80091904: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80091908: addiu       $v0, $v0, 0x794C
    ctx->r2 = ADD32(ctx->r2, 0X794C);
    // 0x8009190C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091910: sw          $v0, -0x6628($at)
    MEM_W(-0X6628, ctx->r1) = ctx->r2;
    // 0x80091914: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80091918: addiu       $v0, $v0, 0x591C
    ctx->r2 = ADD32(ctx->r2, 0X591C);
    // 0x8009191C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091920: sw          $v0, -0x6620($at)
    MEM_W(-0X6620, ctx->r1) = ctx->r2;
    // 0x80091924: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091928: sb          $zero, -0x68B3($at)
    MEM_B(-0X68B3, ctx->r1) = 0;
    // 0x8009192C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80091930: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x80091934: jal         0x8008F0A0
    // 0x80091938: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8008F0A0(rdram, ctx);
        goto after_0;
    // 0x80091938: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8009193C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80091940: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80091944: jal         0x8008F2FC
    // 0x80091948: andi        $a2, $s2, 0xFF
    ctx->r6 = ctx->r18 & 0XFF;
    func_8008F2FC(rdram, ctx);
        goto after_1;
    // 0x80091948: andi        $a2, $s2, 0xFF
    ctx->r6 = ctx->r18 & 0XFF;
    after_1:
    // 0x8009194C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80091950: andi        $a2, $s3, 0xFFFF
    ctx->r6 = ctx->r19 & 0XFFFF;
    // 0x80091954: beq         $a2, $zero, L_800919C8
    if (ctx->r6 == 0) {
        // 0x80091958: lui         $v0, 0x1062
        ctx->r2 = S32(0X1062 << 16);
            goto L_800919C8;
    }
    // 0x80091958: lui         $v0, 0x1062
    ctx->r2 = S32(0X1062 << 16);
    // 0x8009195C: mult        $v1, $a2
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091960: mflo        $v1
    ctx->r3 = lo;
    // 0x80091964: ori         $v0, $v0, 0x4DD3
    ctx->r2 = ctx->r2 | 0X4DD3;
    // 0x80091968: nop

    // 0x8009196C: multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091970: mfhi        $t0
    ctx->r8 = hi;
    // 0x80091974: lui         $v0, 0xAAAA
    ctx->r2 = S32(0XAAAA << 16);
    // 0x80091978: ori         $v0, $v0, 0xAAAB
    ctx->r2 = ctx->r2 | 0XAAAB;
    // 0x8009197C: srl         $v1, $t0, 6
    ctx->r3 = S32(U32(ctx->r8) >> 6);
    // 0x80091980: multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091984: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80091988: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009198C: sw          $zero, -0x6898($at)
    MEM_W(-0X6898, ctx->r1) = 0;
    // 0x80091990: mfhi        $t0
    ctx->r8 = hi;
    // 0x80091994: srl         $v1, $t0, 7
    ctx->r3 = S32(U32(ctx->r8) >> 7);
    // 0x80091998: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8009199C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800919A0: sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2 << 6);
    // 0x800919A4: addiu       $v1, $v0, 0xC0
    ctx->r3 = ADD32(ctx->r2, 0XC0);
    // 0x800919A8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800919AC: sw          $v1, -0x688C($at)
    MEM_W(-0X688C, ctx->r1) = ctx->r3;
    // 0x800919B0: jal         0x80001ACC
    // 0x800919B4: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
    rs_malloc(rdram, ctx);
        goto after_2;
    // 0x800919B4: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
    after_2:
    // 0x800919B8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800919BC: sw          $v0, -0x6890($at)
    MEM_W(-0X6890, ctx->r1) = ctx->r2;
    // 0x800919C0: j           L_800919D0
    // 0x800919C4: nop

        goto L_800919D0;
    // 0x800919C4: nop

L_800919C8:
    // 0x800919C8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800919CC: sw          $zero, -0x6890($at)
    MEM_W(-0X6890, ctx->r1) = 0;
L_800919D0:
    // 0x800919D0: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800919D4: lw          $v0, -0x662C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X662C);
    // 0x800919D8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800919DC: addiu       $a0, $a0, 0x123C
    ctx->r4 = ADD32(ctx->r4, 0X123C);
    // 0x800919E0: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x800919E4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800919E8: sh          $v1, -0x6678($at)
    MEM_H(-0X6678, ctx->r1) = ctx->r3;
    // 0x800919EC: jalr        $v0
    // 0x800919F0: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_3;
    // 0x800919F0: nop

    after_3:
    // 0x800919F4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800919F8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800919FC: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x80091A00: bgez        $v0, L_80091A14
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80091A04: nop
    
            goto L_80091A14;
    }
    // 0x80091A04: nop

    // 0x80091A08: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80091A0C: ldc1        $f0, -0x21D0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X21D0);
    // 0x80091A10: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
L_80091A14:
    // 0x80091A14: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80091A18: lwc1        $f2, -0x21C8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X21C8);
    // 0x80091A1C: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x80091A20: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80091A24: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80091A28: lwc1        $f2, -0x21C4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X21C4);
    // 0x80091A2C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80091A30: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80091A34: lwc1        $f2, -0x21C0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X21C0);
    // 0x80091A38: add.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80091A3C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80091A40: lwc1        $f0, -0x21BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X21BC);
    // 0x80091A44: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80091A48: nop

    // 0x80091A4C: bc1tl       L_80091A64
    if (c1cs) {
        // 0x80091A50: sub.s       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_80091A64;
    }
    goto skip_0;
    // 0x80091A50: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    skip_0:
    // 0x80091A54: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80091A58: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x80091A5C: j           L_80091A78
    // 0x80091A60: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
        goto L_80091A78;
    // 0x80091A60: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
L_80091A64:
    // 0x80091A64: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80091A68: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x80091A6C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80091A70: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80091A74: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
L_80091A78:
    // 0x80091A78: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80091A7C: sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2 << 6);
    // 0x80091A80: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091A84: sw          $v1, -0x68E8($at)
    MEM_W(-0X68E8, ctx->r1) = ctx->r3;
    // 0x80091A88: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091A8C: sw          $v1, -0x68EC($at)
    MEM_W(-0X68EC, ctx->r1) = ctx->r3;
    // 0x80091A90: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80091A94: sw          $v0, 0x2038($at)
    MEM_W(0X2038, ctx->r1) = ctx->r2;
    // 0x80091A98: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80091A9C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80091AA0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80091AA4: sb          $v0, 0x80D($at)
    MEM_B(0X80D, ctx->r1) = ctx->r2;
    // 0x80091AA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80091AAC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80091AB0: sb          $v0, 0x80C($at)
    MEM_B(0X80C, ctx->r1) = ctx->r2;
    // 0x80091AB4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80091AB8: sw          $v1, 0x808($at)
    MEM_W(0X808, ctx->r1) = ctx->r3;
    // 0x80091ABC: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80091AC0: addiu       $a1, $a1, -0x21E4
    ctx->r5 = ADD32(ctx->r5, -0X21E4);
    // 0x80091AC4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80091AC8: addiu       $a0, $a0, 0x90E
    ctx->r4 = ADD32(ctx->r4, 0X90E);
    // 0x80091ACC: lwl         $v0, 0x0($a1)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r5, 0X0);
    // 0x80091AD0: lwr         $v0, 0x3($a1)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r5, 0X3);
    // 0x80091AD4: lwl         $v1, 0x4($a1)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r5, 0X4);
    // 0x80091AD8: lwr         $v1, 0x7($a1)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r5, 0X7);
    // 0x80091ADC: swl         $v0, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, ctx->r2);
    // 0x80091AE0: swr         $v0, 0x3($a0)
    do_swr(rdram, 0X3, ctx->r4, ctx->r2);
    // 0x80091AE4: swl         $v1, 0x4($a0)
    do_swl(rdram, 0X4, ctx->r4, ctx->r3);
    // 0x80091AE8: swr         $v1, 0x7($a0)
    do_swr(rdram, 0X7, ctx->r4, ctx->r3);
    // 0x80091AEC: lwl         $v0, 0x8($a1)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r5, 0X8);
    // 0x80091AF0: lwr         $v0, 0xB($a1)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r5, 0XB);
    // 0x80091AF4: lwl         $v1, 0xC($a1)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r5, 0XC);
    // 0x80091AF8: lwr         $v1, 0xF($a1)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r5, 0XF);
    // 0x80091AFC: swl         $v0, 0x8($a0)
    do_swl(rdram, 0X8, ctx->r4, ctx->r2);
    // 0x80091B00: swr         $v0, 0xB($a0)
    do_swr(rdram, 0XB, ctx->r4, ctx->r2);
    // 0x80091B04: swl         $v1, 0xC($a0)
    do_swl(rdram, 0XC, ctx->r4, ctx->r3);
    // 0x80091B08: swr         $v1, 0xF($a0)
    do_swr(rdram, 0XF, ctx->r4, ctx->r3);
    // 0x80091B0C: lh          $v0, 0x10($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X10);
    // 0x80091B10: lb          $v1, 0x12($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X12);
    // 0x80091B14: sh          $v0, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r2;
    // 0x80091B18: sb          $v1, 0x12($a0)
    MEM_B(0X12, ctx->r4) = ctx->r3;
    // 0x80091B1C: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80091B20: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80091B24: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80091B28: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80091B2C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80091B30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80091B34: jr          $ra
    // 0x80091B38: nop

    return;
    // 0x80091B38: nop

;}
RECOMP_FUNC void func_80091B3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    { if(0) fprintf(stderr, "[trace] func_80091B3C ENTRY\n"); fflush(stderr); }
    // 0x80091B3C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80091B40: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80091B44: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80091B48: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80091B4C: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // 0x80091B50: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80091B54: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x80091B58: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80091B5C: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x80091B60: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80091B64: jal         0x80091FC4
    // 0x80091B68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_80091FC4(rdram, ctx);
        goto after_0;
    // 0x80091B68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80091B6C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80091B70: addiu       $a0, $a0, -0x6990
    ctx->r4 = ADD32(ctx->r4, -0X6990);
    // 0x80091B74: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80091B78: addiu       $a1, $a1, -0x6970
    ctx->r5 = ADD32(ctx->r5, -0X6970);
    // 0x80091B7C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80091B80: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x80091B84: addiu       $s0, $s0, -0x6960
    ctx->r16 = ADD32(ctx->r16, -0X6960);
    // 0x80091B88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80091B8C: jal         0x8002B300
    // 0x80091B90: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80091B90: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    after_1:
    // 0x80091B94: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80091B98: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80091B9C: addiu       $a1, $a1, -0x6990
    ctx->r5 = ADD32(ctx->r5, -0X6990);
    // 0x80091BA0: jal         0x80033560
    // 0x80091BA4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80091BA4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80091BA8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80091BAC: jal         0x80029D20
    // 0x80091BB0: nop

    osAiSetFrequency_recomp(rdram, ctx);
        goto after_3;
    // 0x80091BB0: nop

    after_3:
    // 0x80091BB4: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x80091BB8: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x80091BBC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091BC0: sw          $v0, -0x690C($at)
    MEM_W(-0X690C, ctx->r1) = ctx->r2;
    // 0x80091BC4: jal         0x80001ACC
    // 0x80091BC8: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    rs_malloc(rdram, ctx);
        goto after_4;
    // 0x80091BC8: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    after_4:
    // 0x80091BCC: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80091BD0: addiu       $a0, $a0, -0x6B50
    ctx->r4 = ADD32(ctx->r4, -0X6B50);
    // 0x80091BD4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80091BD8: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80091BDC: addiu       $a2, $a2, -0x1290
    ctx->r6 = ADD32(ctx->r6, -0X1290);
    // 0x80091BE0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80091BE4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091BE8: sw          $v0, -0x69A0($at)
    MEM_W(-0X69A0, ctx->r1) = ctx->r2;
    // 0x80091BEC: addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
    // 0x80091BF0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80091BF4: addiu       $v0, $zero, 0x7A
    ctx->r2 = ADD32(0, 0X7A);
    // 0x80091BF8: jal         0x8002B330
    // 0x80091BFC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    osCreateThread_recomp(rdram, ctx);
        goto after_5;
    // 0x80091BFC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_5:
    // 0x80091C00: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80091C04: addiu       $a0, $a0, -0x6B50
    ctx->r4 = ADD32(ctx->r4, -0X6B50);
    // 0x80091C08: jal         0x800344E0
    // 0x80091C0C: nop

    osStartThread_recomp(rdram, ctx);
        goto after_6;
    // 0x80091C0C: nop

    after_6:
    // 0x80091C10: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80091C14: and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // 0x80091C18: bne         $v0, $zero, L_80091C4C
    if (ctx->r2 != 0) {
        // 0x80091C1C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80091C4C;
    }
    // 0x80091C1C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80091C20: lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
    // 0x80091C24: and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // 0x80091C28: bne         $v0, $zero, L_80091C4C
    if (ctx->r2 != 0) {
        // 0x80091C2C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80091C4C;
    }
    // 0x80091C2C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80091C30: lui         $v0, 0x4
    ctx->r2 = S32(0X4 << 16);
    // 0x80091C34: and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // 0x80091C38: bne         $v0, $zero, L_80091C4C
    if (ctx->r2 != 0) {
        // 0x80091C3C: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80091C4C;
    }
    // 0x80091C3C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80091C40: lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
    // 0x80091C44: and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // 0x80091C48: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80091C4C:
    // 0x80091C4C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80091C50: andi        $a1, $s3, 0xFFFF
    ctx->r5 = ctx->r19 & 0XFFFF;
    // 0x80091C54: andi        $a2, $s4, 0xFFFF
    ctx->r6 = ctx->r20 & 0XFFFF;
    // 0x80091C58: jal         0x8009189C
    // 0x80091C5C: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    func_8009189C(rdram, ctx);
        goto after_7;
    // 0x80091C5C: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    after_7:
    // 0x80091C60: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80091C64: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80091C68: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80091C6C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80091C70: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80091C74: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80091C78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80091C7C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80091C80: jr          $ra
    // 0x80091C84: nop

    return;
    // 0x80091C84: nop

;}
RECOMP_FUNC void func_80091C88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    { if(0) fprintf(stderr, "[trace] func_80091C88 ENTRY (audio+gfx init)\n"); fflush(stderr); }
    // 0x80091C88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80091C8C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80091C90: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80091C94: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80091C98: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // 0x80091C9C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80091CA0: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x80091CA4: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80091CA8: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80091CAC: jal         0x80091FC4
    // 0x80091CB0: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    func_80091FC4(rdram, ctx);
        goto after_0;
    // 0x80091CB0: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    after_0:
    // 0x80091CB4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80091CB8: jal         0x80029D20
    // 0x80091CBC: nop

    osAiSetFrequency_recomp(rdram, ctx);
        goto after_1;
    // 0x80091CBC: nop

    after_1:
    // 0x80091CC0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091CC4: sw          $v0, -0x690C($at)
    MEM_W(-0X690C, ctx->r1) = ctx->r2;
    // 0x80091CC8: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80091CCC: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80091CD0: and         $v0, $s0, $v0
    ctx->r2 = ctx->r16 & ctx->r2;
    // 0x80091CD4: bne         $v0, $zero, L_80091D08
    if (ctx->r2 != 0) {
        // 0x80091CD8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80091D08;
    }
    // 0x80091CD8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80091CDC: lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
    // 0x80091CE0: and         $v0, $s0, $v0
    ctx->r2 = ctx->r16 & ctx->r2;
    // 0x80091CE4: bne         $v0, $zero, L_80091D08
    if (ctx->r2 != 0) {
        // 0x80091CE8: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80091D08;
    }
    // 0x80091CE8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80091CEC: lui         $v0, 0x4
    ctx->r2 = S32(0X4 << 16);
    // 0x80091CF0: and         $v0, $s0, $v0
    ctx->r2 = ctx->r16 & ctx->r2;
    // 0x80091CF4: bne         $v0, $zero, L_80091D08
    if (ctx->r2 != 0) {
        // 0x80091CF8: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80091D08;
    }
    // 0x80091CF8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80091CFC: lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
    // 0x80091D00: and         $v0, $s0, $v0
    ctx->r2 = ctx->r16 & ctx->r2;
    // 0x80091D04: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80091D08:
    // 0x80091D08: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80091D0C: andi        $a1, $s2, 0xFFFF
    ctx->r5 = ctx->r18 & 0XFFFF;
    // 0x80091D10: andi        $a2, $s3, 0xFFFF
    ctx->r6 = ctx->r19 & 0XFFFF;
    // 0x80091D14: jal         0x8009189C
    // 0x80091D18: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    func_8009189C(rdram, ctx);
        goto after_2;
    // 0x80091D18: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    after_2:
    // 0x80091D1C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80091D20: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80091D24: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80091D28: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80091D2C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80091D30: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80091D34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80091D38: jr          $ra
    // 0x80091D3C: nop

    return;
    // 0x80091D3C: nop

;}
RECOMP_FUNC void func_80091D40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091D40: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80091D44: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80091D48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80091D4C: beq         $v0, $zero, L_80091EA0
    if (ctx->r2 == 0) {
        // 0x80091D50: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_80091EA0;
    }
    // 0x80091D50: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80091D54: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80091D58: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091D5C: sh          $v0, -0x6676($at)
    MEM_H(-0X6676, ctx->r1) = ctx->r2;
L_80091D60:
    // 0x80091D60: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80091D64: lhu         $v0, -0x6676($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6676);
    // 0x80091D68: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80091D6C: bgtz        $v0, L_80091D60
    if (SIGNED(ctx->r2) > 0) {
        // 0x80091D70: nop
    
            goto L_80091D60;
    }
    // 0x80091D70: nop

    // 0x80091D74: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80091D78: lw          $v0, -0x6628($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6628);
    // 0x80091D7C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80091D80: addiu       $a0, $a0, 0x123C
    ctx->r4 = ADD32(ctx->r4, 0X123C);
    // 0x80091D84: jalr        $v0
    // 0x80091D88: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80091D88: nop

    after_0:
    // 0x80091D8C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80091D90: lw          $v0, -0x6898($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6898);
    // 0x80091D94: beq         $v0, $zero, L_80091DAC
    if (ctx->r2 == 0) {
        // 0x80091D98: nop
    
            goto L_80091DAC;
    }
    // 0x80091D98: nop

    // 0x80091D9C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091DA0: sw          $zero, -0x6898($at)
    MEM_W(-0X6898, ctx->r1) = 0;
    // 0x80091DA4: jal         0x80001C98
    // 0x80091DA8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    rs_free(rdram, ctx);
        goto after_1;
    // 0x80091DA8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
L_80091DAC:
    // 0x80091DAC: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80091DB0: lw          $a0, -0x6890($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6890);
    // 0x80091DB4: beq         $a0, $zero, L_80091DC4
    if (ctx->r4 == 0) {
        // 0x80091DB8: nop
    
            goto L_80091DC4;
    }
    // 0x80091DB8: nop

    // 0x80091DBC: jal         0x80001C98
    // 0x80091DC0: nop

    rs_free(rdram, ctx);
        goto after_2;
    // 0x80091DC0: nop

    after_2:
L_80091DC4:
    // 0x80091DC4: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80091DC8: lbu         $v0, -0x68B4($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X68B4);
    // 0x80091DCC: bne         $v0, $zero, L_80091DC4
    if (ctx->r2 != 0) {
        // 0x80091DD0: nop
    
            goto L_80091DC4;
    }
    // 0x80091DD0: nop

    // 0x80091DD4: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80091DD8: lw          $a0, -0x68D8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X68D8);
    // 0x80091DDC: jal         0x80001C98
    // 0x80091DE0: nop

    rs_free(rdram, ctx);
        goto after_3;
    // 0x80091DE0: nop

    after_3:
    // 0x80091DE4: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80091DE8: lw          $a0, -0x6644($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6644);
    // 0x80091DEC: jal         0x80001C98
    // 0x80091DF0: nop

    rs_free(rdram, ctx);
        goto after_4;
    // 0x80091DF0: nop

    after_4:
    // 0x80091DF4: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80091DF8: lw          $a0, -0x6640($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6640);
    // 0x80091DFC: jal         0x80001C98
    // 0x80091E00: nop

    rs_free(rdram, ctx);
        goto after_5;
    // 0x80091E00: nop

    after_5:
    // 0x80091E04: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80091E08: lw          $a0, -0x6638($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6638);
    // 0x80091E0C: jal         0x80001C98
    // 0x80091E10: nop

    rs_free(rdram, ctx);
        goto after_6;
    // 0x80091E10: nop

    after_6:
    // 0x80091E14: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80091E18: lw          $a0, -0x663C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X663C);
    // 0x80091E1C: jal         0x80001C98
    // 0x80091E20: nop

    rs_free(rdram, ctx);
        goto after_7;
    // 0x80091E20: nop

    after_7:
    // 0x80091E24: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80091E28: lw          $a0, -0x68A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X68A8);
    // 0x80091E2C: jal         0x80001C98
    // 0x80091E30: nop

    rs_free(rdram, ctx);
        goto after_8;
    // 0x80091E30: nop

    after_8:
    // 0x80091E34: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80091E38: lw          $a0, -0x68A4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X68A4);
    // 0x80091E3C: jal         0x80001C98
    // 0x80091E40: nop

    rs_free(rdram, ctx);
        goto after_9;
    // 0x80091E40: nop

    after_9:
    // 0x80091E44: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80091E48: lw          $a0, -0x6904($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6904);
    // 0x80091E4C: jal         0x80001C98
    // 0x80091E50: nop

    rs_free(rdram, ctx);
        goto after_10;
    // 0x80091E50: nop

    after_10:
    // 0x80091E54: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80091E58: lw          $a0, -0x689C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X689C);
    // 0x80091E5C: jal         0x80001C98
    // 0x80091E60: nop

    rs_free(rdram, ctx);
        goto after_11;
    // 0x80091E60: nop

    after_11:
    // 0x80091E64: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80091E68: addiu       $a0, $a0, -0x6990
    ctx->r4 = ADD32(ctx->r4, -0X6990);
    // 0x80091E6C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80091E70: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80091E74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80091E78: jal         0x80033410
    // 0x80091E7C: sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
    osSendMesg_recomp(rdram, ctx);
        goto after_12;
    // 0x80091E7C: sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
    after_12:
    // 0x80091E80: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80091E84: lw          $a0, -0x6950($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6950);
    // 0x80091E88: jal         0x80001C98
    // 0x80091E8C: nop

    rs_free(rdram, ctx);
        goto after_13;
    // 0x80091E8C: nop

    after_13:
    // 0x80091E90: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80091E94: lw          $a0, -0x69A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X69A0);
    // 0x80091E98: jal         0x80001C98
    // 0x80091E9C: nop

    rs_free(rdram, ctx);
        goto after_14;
    // 0x80091E9C: nop

    after_14:
L_80091EA0:
    // 0x80091EA0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80091EA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80091EA8: jr          $ra
    // 0x80091EAC: nop

    return;
    // 0x80091EAC: nop

;}
RECOMP_FUNC void func_80091EB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091EB0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80091EB4: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80091EB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091EBC: beq         $v0, $zero, L_80091FB4
    if (ctx->r2 == 0) {
        // 0x80091EC0: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80091FB4;
    }
    // 0x80091EC0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80091EC4: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80091EC8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091ECC: sh          $v0, -0x6676($at)
    MEM_H(-0X6676, ctx->r1) = ctx->r2;
L_80091ED0:
    // 0x80091ED0: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80091ED4: lhu         $v0, -0x6676($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6676);
    // 0x80091ED8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80091EDC: bgtz        $v0, L_80091ED0
    if (SIGNED(ctx->r2) > 0) {
        // 0x80091EE0: nop
    
            goto L_80091ED0;
    }
    // 0x80091EE0: nop

    // 0x80091EE4: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80091EE8: lw          $v0, -0x6628($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6628);
    // 0x80091EEC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80091EF0: addiu       $a0, $a0, 0x123C
    ctx->r4 = ADD32(ctx->r4, 0X123C);
    // 0x80091EF4: jalr        $v0
    // 0x80091EF8: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80091EF8: nop

    after_0:
    // 0x80091EFC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80091F00: lw          $v0, -0x6898($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6898);
    // 0x80091F04: beq         $v0, $zero, L_80091F1C
    if (ctx->r2 == 0) {
        // 0x80091F08: nop
    
            goto L_80091F1C;
    }
    // 0x80091F08: nop

    // 0x80091F0C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091F10: sw          $zero, -0x6898($at)
    MEM_W(-0X6898, ctx->r1) = 0;
    // 0x80091F14: jal         0x80001C98
    // 0x80091F18: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    rs_free(rdram, ctx);
        goto after_1;
    // 0x80091F18: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
L_80091F1C:
    // 0x80091F1C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80091F20: lw          $a0, -0x6890($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6890);
    // 0x80091F24: beq         $a0, $zero, L_80091F34
    if (ctx->r4 == 0) {
        // 0x80091F28: nop
    
            goto L_80091F34;
    }
    // 0x80091F28: nop

    // 0x80091F2C: jal         0x80001C98
    // 0x80091F30: nop

    rs_free(rdram, ctx);
        goto after_2;
    // 0x80091F30: nop

    after_2:
L_80091F34:
    // 0x80091F34: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80091F38: lbu         $v0, -0x68B4($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X68B4);
    // 0x80091F3C: bne         $v0, $zero, L_80091F34
    if (ctx->r2 != 0) {
        // 0x80091F40: nop
    
            goto L_80091F34;
    }
    // 0x80091F40: nop

    // 0x80091F44: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80091F48: lw          $a0, -0x68D8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X68D8);
    // 0x80091F4C: jal         0x80001C98
    // 0x80091F50: nop

    rs_free(rdram, ctx);
        goto after_3;
    // 0x80091F50: nop

    after_3:
    // 0x80091F54: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80091F58: lw          $a0, -0x6644($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6644);
    // 0x80091F5C: jal         0x80001C98
    // 0x80091F60: nop

    rs_free(rdram, ctx);
        goto after_4;
    // 0x80091F60: nop

    after_4:
    // 0x80091F64: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80091F68: lw          $a0, -0x6640($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6640);
    // 0x80091F6C: jal         0x80001C98
    // 0x80091F70: nop

    rs_free(rdram, ctx);
        goto after_5;
    // 0x80091F70: nop

    after_5:
    // 0x80091F74: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80091F78: lw          $a0, -0x68A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X68A8);
    // 0x80091F7C: jal         0x80001C98
    // 0x80091F80: nop

    rs_free(rdram, ctx);
        goto after_6;
    // 0x80091F80: nop

    after_6:
    // 0x80091F84: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80091F88: lw          $a0, -0x68A4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X68A4);
    // 0x80091F8C: jal         0x80001C98
    // 0x80091F90: nop

    rs_free(rdram, ctx);
        goto after_7;
    // 0x80091F90: nop

    after_7:
    // 0x80091F94: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80091F98: lw          $a0, -0x6904($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6904);
    // 0x80091F9C: jal         0x80001C98
    // 0x80091FA0: nop

    rs_free(rdram, ctx);
        goto after_8;
    // 0x80091FA0: nop

    after_8:
    // 0x80091FA4: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80091FA8: lw          $a0, -0x689C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X689C);
    // 0x80091FAC: jal         0x80001C98
    // 0x80091FB0: nop

    rs_free(rdram, ctx);
        goto after_9;
    // 0x80091FB0: nop

    after_9:
L_80091FB4:
    // 0x80091FB4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80091FB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091FBC: jr          $ra
    // 0x80091FC0: nop

    return;
    // 0x80091FC0: nop

;}
RECOMP_FUNC void func_80091FC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091FC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091FC8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80091FCC: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x80091FD0: addiu       $s0, $s0, -0x6670
    ctx->r16 = ADD32(ctx->r16, -0X6670);
    // 0x80091FD4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80091FD8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80091FDC: addiu       $a1, $a1, -0x6658
    ctx->r5 = ADD32(ctx->r5, -0X6658);
    // 0x80091FE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091FE4: jal         0x8002B300
    // 0x80091FE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80091FE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80091FEC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80091FF0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80091FF4: jal         0x80033410
    // 0x80091FF8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80091FF8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // 0x80091FFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80092000: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80092004: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80092008: jr          $ra
    // 0x8009200C: nop

    return;
    // 0x8009200C: nop

;}
RECOMP_FUNC void func_80092010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8009205C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800920A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800920D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800920FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800920FC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80092100: lw          $v0, -0x6908($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6908);
    // 0x80092104: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x80092108: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8009210C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80092110: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80092114: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80092118: jr          $ra
    // 0x8009211C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x8009211C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
;}
RECOMP_FUNC void func_80092120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092120: jr          $ra
    // 0x80092124: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80092124: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_80092128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092128: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x8009212C: andi        $a0, $a3, 0xFFFF
    ctx->r4 = ctx->r7 & 0XFFFF;
    // 0x80092130: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x80092134: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80092138: lw          $v0, -0x6908($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6908);
    // 0x8009213C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80092140: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80092144: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80092148: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8009214C: addiu       $v1, $zero, 0x1000
    ctx->r3 = ADD32(0, 0X1000);
    // 0x80092150: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
    // 0x80092154: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80092158: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8009215C: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x80092160: sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
    // 0x80092164: sh          $zero, 0x18($v0)
    MEM_H(0X18, ctx->r2) = 0;
    // 0x80092168: sh          $zero, 0x20($v0)
    MEM_H(0X20, ctx->r2) = 0;
    // 0x8009216C: sh          $zero, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = 0;
    // 0x80092170: sh          $zero, 0x22($v0)
    MEM_H(0X22, ctx->r2) = 0;
    // 0x80092174: sh          $zero, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = 0;
    // 0x80092178: sh          $zero, 0x24($v0)
    MEM_H(0X24, ctx->r2) = 0;
    // 0x8009217C: sh          $zero, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = 0;
    // 0x80092180: sh          $zero, 0x26($v0)
    MEM_H(0X26, ctx->r2) = 0;
    // 0x80092184: sh          $zero, 0x44($v0)
    MEM_H(0X44, ctx->r2) = 0;
    // 0x80092188: sh          $zero, 0x46($v0)
    MEM_H(0X46, ctx->r2) = 0;
    // 0x8009218C: sh          $zero, 0x48($v0)
    MEM_H(0X48, ctx->r2) = 0;
    // 0x80092190: beq         $a2, $zero, L_800921CC
    if (ctx->r6 == 0) {
        // 0x80092194: sh          $zero, 0x4A($v0)
        MEM_H(0X4A, ctx->r2) = 0;
            goto L_800921CC;
    }
    // 0x80092194: sh          $zero, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = 0;
    // 0x80092198: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8009219C: lw          $v1, -0x6908($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6908);
    // 0x800921A0: sll         $v0, $a3, 4
    ctx->r2 = S32(ctx->r7 << 4);
    // 0x800921A4: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x800921A8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800921AC: lwc1        $f0, -0x21B8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X21B8);
    // 0x800921B0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800921B4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800921B8: addiu       $v1, $zero, 0x14
    ctx->r3 = ADD32(0, 0X14);
    // 0x800921BC: sh          $zero, 0x28($v0)
    MEM_H(0X28, ctx->r2) = 0;
    // 0x800921C0: sh          $zero, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = 0;
    // 0x800921C4: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x800921C8: sh          $v1, 0x30($v0)
    MEM_H(0X30, ctx->r2) = ctx->r3;
L_800921CC:
    // 0x800921CC: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800921D0: lw          $a0, -0x6908($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6908);
    // 0x800921D4: sll         $v0, $a3, 4
    ctx->r2 = S32(ctx->r7 << 4);
    // 0x800921D8: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x800921DC: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x800921E0: sll         $a2, $v0, 3
    ctx->r6 = S32(ctx->r2 << 3);
    // 0x800921E4: addu        $a0, $a2, $a0
    ctx->r4 = ADD32(ctx->r6, ctx->r4);
    // 0x800921E8: sw          $v1, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r3;
    // 0x800921EC: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x800921F0: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800921F4: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x800921F8: bgez        $v0, L_8009220C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800921FC: nop
    
            goto L_8009220C;
    }
    // 0x800921FC: nop

    // 0x80092200: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80092204: ldc1        $f0, -0x21B0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X21B0);
    // 0x80092208: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
L_8009220C:
    // 0x8009220C: sdc1        $f2, 0x8($a0)
    CHECK_FR(ctx, 2);
    SD(ctx->f2.u64, 0X8, ctx->r4);
    // 0x80092210: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x80092214: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    // 0x80092218: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // 0x8009221C: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x80092220: sw          $v0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r2;
    // 0x80092224: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    // 0x80092228: sw          $v0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r2;
    // 0x8009222C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80092230: sw          $v0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r2;
    // 0x80092234: lbu         $v0, 0x18($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X18);
    // 0x80092238: sb          $v0, 0x6D($a0)
    MEM_B(0X6D, ctx->r4) = ctx->r2;
    // 0x8009223C: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x80092240: lui         $v1, 0xF000
    ctx->r3 = S32(0XF000 << 16);
    // 0x80092244: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80092248: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x8009224C: beq         $v0, $v1, L_8009226C
    if (ctx->r2 == ctx->r3) {
        // 0x80092250: nop
    
            goto L_8009226C;
    }
    // 0x80092250: nop

    // 0x80092254: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80092258: lw          $v1, -0x6908($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6908);
    // 0x8009225C: addu        $v1, $a2, $v1
    ctx->r3 = ADD32(ctx->r6, ctx->r3);
    // 0x80092260: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x80092264: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80092268: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
L_8009226C:
    // 0x8009226C: jr          $ra
    // 0x80092270: nop

    return;
    // 0x80092270: nop

;}
RECOMP_FUNC void func_80092274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092274: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80092278: lw          $v1, -0x6908($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6908);
    // 0x8009227C: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x80092280: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80092284: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80092288: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8009228C: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x80092290: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x80092294: beq         $a1, $zero, L_800922BC
    if (ctx->r5 == 0) {
        // 0x80092298: sh          $v0, 0x30($a0)
        MEM_H(0X30, ctx->r4) = ctx->r2;
            goto L_800922BC;
    }
    // 0x80092298: sh          $v0, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r2;
    // 0x8009229C: lwc1        $f0, 0x5C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X5C);
    // 0x800922A0: lhu         $v1, 0x30($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X30);
    // 0x800922A4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800922A8: sb          $v0, 0x6C($a0)
    MEM_B(0X6C, ctx->r4) = ctx->r2;
    // 0x800922AC: sw          $zero, 0x64($a0)
    MEM_W(0X64, ctx->r4) = 0;
    // 0x800922B0: sw          $zero, 0x60($a0)
    MEM_W(0X60, ctx->r4) = 0;
    // 0x800922B4: swc1        $f0, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->f0.u32l;
    // 0x800922B8: sh          $v1, 0x58($a0)
    MEM_H(0X58, ctx->r4) = ctx->r3;
L_800922BC:
    // 0x800922BC: jr          $ra
    // 0x800922C0: nop

    return;
    // 0x800922C0: nop

;}
RECOMP_FUNC void func_800922C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800922C4: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x800922C8: lw          $a2, -0x6908($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X6908);
    // 0x800922CC: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x800922D0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800922D4: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x800922D8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800922DC: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800922E0: sh          $v1, 0x28($v0)
    MEM_H(0X28, ctx->r2) = ctx->r3;
    // 0x800922E4: lhu         $v1, 0x2($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X2);
    // 0x800922E8: sh          $v1, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r3;
    // 0x800922EC: lhu         $v1, 0x4($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X4);
    // 0x800922F0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800922F4: ldc1        $f2, -0x21A8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X21A8);
    // 0x800922F8: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x800922FC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80092300: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80092304: div.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f2.d);
    // 0x80092308: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8009230C: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x80092310: lhu         $v1, 0x6($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X6);
    // 0x80092314: jr          $ra
    // 0x80092318: sh          $v1, 0x30($v0)
    MEM_H(0X30, ctx->r2) = ctx->r3;
    return;
    // 0x80092318: sh          $v1, 0x30($v0)
    MEM_H(0X30, ctx->r2) = ctx->r3;
;}
RECOMP_FUNC void func_8009231C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009231C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80092320: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x80092324: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80092328: lw          $v1, -0x6908($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6908);
    // 0x8009232C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80092330: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80092334: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80092338: lwc1        $f0, -0x21A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X21A0);
    // 0x8009233C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80092340: lhu         $a0, 0x28($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X28);
    // 0x80092344: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80092348: sb          $zero, 0x6C($v1)
    MEM_B(0X6C, ctx->r3) = 0;
    // 0x8009234C: sw          $zero, 0x60($v1)
    MEM_W(0X60, ctx->r3) = 0;
    // 0x80092350: sw          $zero, 0x68($v1)
    MEM_W(0X68, ctx->r3) = 0;
    // 0x80092354: sw          $zero, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = 0;
    // 0x80092358: swc1        $f0, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->f0.u32l;
    // 0x8009235C: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80092360: jr          $ra
    // 0x80092364: sh          $a0, 0x58($v1)
    MEM_H(0X58, ctx->r3) = ctx->r4;
    return;
    // 0x80092364: sh          $a0, 0x58($v1)
    MEM_H(0X58, ctx->r3) = ctx->r4;
;}
RECOMP_FUNC void func_80092368(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092368: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8009236C: lw          $v1, -0x6908($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6908);
    // 0x80092370: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x80092374: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80092378: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8009237C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80092380: jr          $ra
    // 0x80092384: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    return;
    // 0x80092384: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
;}
RECOMP_FUNC void func_80092388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092388: jr          $ra
    // 0x8009238C: nop

    return;
    // 0x8009238C: nop

;}
RECOMP_FUNC void func_80092390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092390: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x80092394: sltiu       $v0, $v0, 0x2001
    ctx->r2 = ctx->r2 < 0X2001 ? 1 : 0;
    // 0x80092398: beq         $v0, $zero, L_800923BC
    if (ctx->r2 == 0) {
        // 0x8009239C: sll         $v0, $a0, 4
        ctx->r2 = S32(ctx->r4 << 4);
            goto L_800923BC;
    }
    // 0x8009239C: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x800923A0: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x800923A4: lw          $v1, -0x6908($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6908);
    // 0x800923A8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800923AC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800923B0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800923B4: j           L_800923DC
    // 0x800923B8: sh          $a1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r5;
        goto L_800923DC;
    // 0x800923B8: sh          $a1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r5;
L_800923BC:
    // 0x800923BC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800923C0: lw          $v0, -0x6908($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6908);
    // 0x800923C4: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x800923C8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800923CC: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800923D0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800923D4: addiu       $v0, $zero, 0x2000
    ctx->r2 = ADD32(0, 0X2000);
    // 0x800923D8: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
L_800923DC:
    // 0x800923DC: jr          $ra
    // 0x800923E0: nop

    return;
    // 0x800923E0: nop

;}
RECOMP_FUNC void func_800923E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800923E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800923E8: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x800923EC: addu        $t1, $a2, $zero
    ctx->r9 = ADD32(ctx->r6, 0);
    // 0x800923F0: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800923F4: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x800923F8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800923FC: lw          $a1, -0x6908($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6908);
    // 0x80092400: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80092404: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80092408: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    // 0x8009240C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80092410: addu        $a3, $t1, $zero
    ctx->r7 = ADD32(ctx->r9, 0);
    // 0x80092414: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80092418: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8009241C: addiu       $v0, $a1, 0x48
    ctx->r2 = ADD32(ctx->r5, 0X48);
    // 0x80092420: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80092424: addiu       $v0, $a1, 0x4A
    ctx->r2 = ADD32(ctx->r5, 0X4A);
    // 0x80092428: addiu       $a0, $a1, 0x46
    ctx->r4 = ADD32(ctx->r5, 0X46);
    // 0x8009242C: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    // 0x80092430: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80092434: jal         0x800940D4
    // 0x80092438: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800940D4(rdram, ctx);
        goto after_0;
    // 0x80092438: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8009243C: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80092440: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80092444: jr          $ra
    // 0x80092448: nop

    return;
    // 0x80092448: nop

;}
RECOMP_FUNC void func_8009244C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009244C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80092450: lw          $v0, -0x6908($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6908);
    // 0x80092454: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x80092458: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8009245C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80092460: addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
    // 0x80092464: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80092468: beq         $v0, $zero, L_80092488
    if (ctx->r2 == 0) {
        // 0x8009246C: nop
    
            goto L_80092488;
    }
    // 0x8009246C: nop

    // 0x80092470: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80092474: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80092478: lw          $v0, -0x6908($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6908);
    // 0x8009247C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80092480: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80092484: sb          $v1, 0x85($v0)
    MEM_B(0X85, ctx->r2) = ctx->r3;
L_80092488:
    // 0x80092488: jr          $ra
    // 0x8009248C: nop

    return;
    // 0x8009248C: nop

;}
RECOMP_FUNC void func_80092490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092490: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80092494: lw          $v0, -0x6908($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6908);
    // 0x80092498: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x8009249C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800924A0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800924A4: addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
    // 0x800924A8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800924AC: beq         $v0, $zero, L_800924E8
    if (ctx->r2 == 0) {
        // 0x800924B0: addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
            goto L_800924E8;
    }
    // 0x800924B0: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x800924B4: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
    // 0x800924B8: beq         $v1, $zero, L_800924C8
    if (ctx->r3 == 0) {
        // 0x800924BC: sh          $v0, 0x30($a0)
        MEM_H(0X30, ctx->r4) = ctx->r2;
            goto L_800924C8;
    }
    // 0x800924BC: sh          $v0, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r2;
    // 0x800924C0: j           L_800924E8
    // 0x800924C4: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
        goto L_800924E8;
    // 0x800924C4: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
L_800924C8:
    // 0x800924C8: lwc1        $f0, 0x5C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X5C);
    // 0x800924CC: lhu         $v1, 0x30($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X30);
    // 0x800924D0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800924D4: sb          $v0, 0x6C($a0)
    MEM_B(0X6C, ctx->r4) = ctx->r2;
    // 0x800924D8: sw          $zero, 0x64($a0)
    MEM_W(0X64, ctx->r4) = 0;
    // 0x800924DC: sw          $zero, 0x60($a0)
    MEM_W(0X60, ctx->r4) = 0;
    // 0x800924E0: swc1        $f0, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->f0.u32l;
    // 0x800924E4: sh          $v1, 0x58($a0)
    MEM_H(0X58, ctx->r4) = ctx->r3;
L_800924E8:
    // 0x800924E8: jr          $ra
    // 0x800924EC: nop

    return;
    // 0x800924EC: nop

;}
RECOMP_FUNC void func_800924F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800924F0: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x800924F4: lw          $v1, -0x6908($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6908);
    // 0x800924F8: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x800924FC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80092500: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80092504: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80092508: jr          $ra
    // 0x8009250C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    return;
    // 0x8009250C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
;}
RECOMP_FUNC void func_80092510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092510: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80092514: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80092518: jal         0x8008EEC0
    // 0x8009251C: nop

    func_8008EEC0(rdram, ctx);
        goto after_0;
    // 0x8009251C: nop

    after_0:
    // 0x80092520: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80092524: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80092528: jr          $ra
    // 0x8009252C: nop

    return;
    // 0x8009252C: nop

;}
RECOMP_FUNC void func_80092530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092530: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80092534: lw          $v0, -0x6898($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6898);
    // 0x80092538: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009253C: beq         $v0, $zero, L_80092554
    if (ctx->r2 == 0) {
        // 0x80092540: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80092554;
    }
    // 0x80092540: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80092544: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80092548: sw          $zero, -0x6898($at)
    MEM_W(-0X6898, ctx->r1) = 0;
    // 0x8009254C: jal         0x80001C98
    // 0x80092550: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    rs_free(rdram, ctx);
        goto after_0;
    // 0x80092550: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
L_80092554:
    // 0x80092554: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80092558: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009255C: jr          $ra
    // 0x80092560: nop

    return;
    // 0x80092560: nop

;}
RECOMP_FUNC void func_80092564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092564: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80092568: lw          $v1, -0x6908($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6908);
    // 0x8009256C: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x80092570: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80092574: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80092578: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8009257C: lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X14);
    // 0x80092580: jr          $ra
    // 0x80092584: nop

    return;
    // 0x80092584: nop

;}
RECOMP_FUNC void func_80092588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092588: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009258C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80092590: jal         0x800358B0
    // 0x80092594: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x80092594: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    after_0:
    // 0x80092598: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8009259C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800925A0: jr          $ra
    // 0x800925A4: nop

    return;
    // 0x800925A4: nop

;}
RECOMP_FUNC void func_800925A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800925A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800925AC: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x800925B0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800925B4: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800925B8: sll         $a0, $a1, 1
    ctx->r4 = S32(ctx->r5 << 1);
    // 0x800925BC: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x800925C0: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x800925C4: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x800925C8: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    // 0x800925CC: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x800925D0: sh          $v0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r2;
    // 0x800925D4: lhu         $v0, 0x6($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X6);
    // 0x800925D8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800925DC: jal         0x800358B0
    // 0x800925E0: sh          $v0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r2;
    osWritebackDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x800925E0: sh          $v0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r2;
    after_0:
    // 0x800925E4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800925E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800925EC: jr          $ra
    // 0x800925F0: nop

    return;
    // 0x800925F0: nop

;}
RECOMP_FUNC void func_800925F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800925F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800925F8: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800925FC: lui         $v0, 0xFF00
    ctx->r2 = S32(0XFF00 << 16);
    // 0x80092600: and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // 0x80092604: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x80092608: xor         $v1, $v0, $v1
    ctx->r3 = ctx->r2 ^ ctx->r3;
    // 0x8009260C: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x80092610: lui         $a0, 0xB000
    ctx->r4 = S32(0XB000 << 16);
    // 0x80092614: xor         $v0, $v0, $a0
    ctx->r2 = ctx->r2 ^ ctx->r4;
    // 0x80092618: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8009261C: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80092620: beq         $v1, $zero, L_8009263C
    if (ctx->r3 == 0) {
        // 0x80092624: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8009263C;
    }
    // 0x80092624: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80092628: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8009262C: lw          $v0, -0x6620($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6620);
    // 0x80092630: jalr        $v0
    // 0x80092634: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80092634: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    after_0:
    // 0x80092638: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
L_8009263C:
    // 0x8009263C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80092640: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x80092644: jr          $ra
    // 0x80092648: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80092648: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8009264C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009264C: lbu         $a2, 0xE($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0XE);
    // 0x80092650: addiu       $sp, $sp, -0x1C
    ctx->r29 = ADD32(ctx->r29, -0X1C);
    // 0x80092654: sw          $ra, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r31;
    // 0x80092658: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8009265C: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x80092660: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x80092664: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80092668: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x8009266C: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    // 0x80092670: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80092674: lw          $t2, 0x4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4);
    // 0x80092678: lw          $s2, 0x18($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X18);
    // 0x8009267C: lw          $s3, 0x1C($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X1C);
    // 0x80092680: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x80092684: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x80092688: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x8009268C: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x80092690: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80092694: srl         $t8, $t8, 3
    ctx->r24 = S32(U32(ctx->r24) >> 3);
    // 0x80092698: srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // 0x8009269C: ori         $t9, $zero, 0xFFFF
    ctx->r25 = 0 | 0XFFFF;
    // 0x800926A0: dsll        $t9, $t9, 15
    ctx->r25 = ctx->r25 << 15;
    // 0x800926A4: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x800926A8: ori         $t0, $zero, 0x1
    ctx->r8 = 0 | 0X1;
    // 0x800926AC: beq         $a2, $t0, L_800926CC
    if (ctx->r6 == ctx->r8) {
        // 0x800926B0: addu        $t7, $zero, $zero
        ctx->r15 = ADD32(0, 0);
            goto L_800926CC;
    }
    // 0x800926B0: addu        $t7, $zero, $zero
    ctx->r15 = ADD32(0, 0);
    // 0x800926B4: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x800926B8: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x800926BC: lh          $t5, 0x8($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X8);
    // 0x800926C0: lhu         $t7, 0xA($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0XA);
    // 0x800926C4: j           L_800926F8
    // 0x800926C8: sll         $t7, $t7, 15
    ctx->r15 = S32(ctx->r15 << 15);
        goto L_800926F8;
    // 0x800926C8: sll         $t7, $t7, 15
    ctx->r15 = S32(ctx->r15 << 15);
L_800926CC:
    // 0x800926CC: lh          $t4, 0x0($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X0);
    // 0x800926D0: bne         $t1, $s2, L_800926E0
    if (ctx->r9 != ctx->r18) {
        // 0x800926D4: addiu       $t1, $t1, 0x2
        ctx->r9 = ADD32(ctx->r9, 0X2);
            goto L_800926E0;
    }
    // 0x800926D4: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x800926D8: beq         $s3, $zero, L_8009278C
    if (ctx->r19 == 0) {
        // 0x800926DC: addu        $t1, $s3, $zero
        ctx->r9 = ADD32(ctx->r19, 0);
            goto L_8009278C;
    }
    // 0x800926DC: addu        $t1, $s3, $zero
    ctx->r9 = ADD32(ctx->r19, 0);
L_800926E0:
    // 0x800926E0: lh          $t5, 0x0($t1)
    ctx->r13 = MEM_H(ctx->r9, 0X0);
    // 0x800926E4: nop

    // 0x800926E8: subu        $t6, $t5, $t4
    ctx->r14 = SUB32(ctx->r13, ctx->r12);
    // 0x800926EC: mult        $t6, $v0
    result = S64(S32(ctx->r14)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800926F0: sll         $t4, $t4, 15
    ctx->r12 = S32(ctx->r12 << 15);
    // 0x800926F4: mflo        $t6
    ctx->r14 = lo;
L_800926F8:
    // 0x800926F8: jal         0x800927B0
    // 0x800926FC: cache       0x0D, 0x0($t2)

    func_800927B0(rdram, ctx);
        goto after_0;
    // 0x800926FC: cache       0x0D, 0x0($t2)

    after_0:
    // 0x80092700: sd          $t3, 0x0($t2)
    SD(ctx->r11, 0X0, ctx->r10);
    // 0x80092704: jal         0x800927B0
    // 0x80092708: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    func_800927B0(rdram, ctx);
        goto after_1;
    // 0x80092708: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    after_1:
    // 0x8009270C: sd          $t3, 0x0($t2)
    SD(ctx->r11, 0X0, ctx->r10);
    // 0x80092710: cache       0x19, -0x8($t2)

    // 0x80092714: addiu       $t8, $t8, -0x1
    ctx->r24 = ADD32(ctx->r24, -0X1);
    // 0x80092718: bne         $t8, $zero, L_800926F8
    if (ctx->r24 != 0) {
        // 0x8009271C: addiu       $t2, $t2, 0x8
        ctx->r10 = ADD32(ctx->r10, 0X8);
            goto L_800926F8;
    }
    // 0x8009271C: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
L_80092720:
    // 0x80092720: srl         $t7, $t7, 15
    ctx->r15 = S32(U32(ctx->r15) >> 15);
    // 0x80092724: sh          $t7, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r15;
    // 0x80092728: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x8009272C: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x80092730: sh          $t5, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r13;
    // 0x80092734: lw          $ra, 0x0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X0);
    // 0x80092738: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8009273C: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x80092740: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x80092744: lw          $s3, 0x10($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X10);
    // 0x80092748: lw          $s4, 0x14($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X14);
    // 0x8009274C: lw          $s5, 0x18($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X18);
    // 0x80092750: jr          $ra
    // 0x80092754: addiu       $sp, $sp, 0x1C
    ctx->r29 = ADD32(ctx->r29, 0X1C);
    return;
    // 0x80092754: addiu       $sp, $sp, 0x1C
    ctx->r29 = ADD32(ctx->r29, 0X1C);
    // 0x80092758: j           L_8009276C
    // 0x8009275C: dsll32      $t3, $t3, 1
    ctx->r11 = ctx->r11 << (1 + 32);
        goto L_8009276C;
    // 0x8009275C: dsll32      $t3, $t3, 1
    ctx->r11 = ctx->r11 << (1 + 32);
    // 0x80092760: j           L_8009276C
    // 0x80092764: dsll        $t3, $t3, 17
    ctx->r11 = ctx->r11 << 17;
        goto L_8009276C;
    // 0x80092764: dsll        $t3, $t3, 17
    ctx->r11 = ctx->r11 << 17;
    // 0x80092768: dsll        $t3, $t3, 1
    ctx->r11 = ctx->r11 << 1;
L_8009276C:
    // 0x8009276C: sd          $t3, 0x0($t2)
    SD(ctx->r11, 0X0, ctx->r10);
    // 0x80092770: andi        $t0, $t2, 0xF
    ctx->r8 = ctx->r10 & 0XF;
    // 0x80092774: bne         $t0, $zero, L_8009279C
    if (ctx->r8 != 0) {
        // 0x80092778: addiu       $t2, $t2, 0x8
        ctx->r10 = ADD32(ctx->r10, 0X8);
            goto L_8009279C;
    }
    // 0x80092778: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x8009277C: sd          $zero, 0x0($t2)
    SD(0, 0X0, ctx->r10);
    // 0x80092780: cache       0x19, -0x8($t2)

    // 0x80092784: j           L_8009279C
    // 0x80092788: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
        goto L_8009279C;
    // 0x80092788: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
L_8009278C:
    // 0x8009278C: cache       0x0D, 0x0($t2)

    // 0x80092790: sd          $zero, 0x0($t2)
    SD(0, 0X0, ctx->r10);
    // 0x80092794: sd          $zero, 0x8($t2)
    SD(0, 0X8, ctx->r10);
    // 0x80092798: cache       0x19, 0x0($t2)

L_8009279C:
    // 0x8009279C: addiu       $t8, $t8, -0x1
    ctx->r24 = ADD32(ctx->r24, -0X1);
    // 0x800927A0: bne         $t8, $zero, L_8009278C
    if (ctx->r24 != 0) {
        // 0x800927A4: addiu       $t2, $t2, 0x10
        ctx->r10 = ADD32(ctx->r10, 0X10);
            goto L_8009278C;
    }
    // 0x800927A4: addiu       $t2, $t2, 0x10
    ctx->r10 = ADD32(ctx->r10, 0X10);
    // 0x800927A8: j           L_80092720
    // 0x800927AC: nop

        goto L_80092720;
    // 0x800927AC: nop

;}
RECOMP_FUNC void func_800927B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800928D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800928D4: addiu       $sp, $sp, -0x1C
    ctx->r29 = ADD32(ctx->r29, -0X1C);
    // 0x800928D8: sw          $ra, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r31;
    // 0x800928DC: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800928E0: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x800928E4: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x800928E8: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x800928EC: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x800928F0: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    // 0x800928F4: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800928F8: lw          $t2, 0x4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4);
    // 0x800928FC: lw          $s2, 0x18($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X18);
    // 0x80092900: lw          $s3, 0x1C($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X1C);
    // 0x80092904: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x80092908: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x8009290C: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x80092910: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    // 0x80092914: ori         $s5, $s5, 0x1790
    ctx->r21 = ctx->r21 | 0X1790;
    // 0x80092918: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x8009291C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80092920: srl         $t8, $t8, 3
    ctx->r24 = S32(U32(ctx->r24) >> 3);
    // 0x80092924: srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // 0x80092928: ori         $t9, $zero, 0xFFFF
    ctx->r25 = 0 | 0XFFFF;
    // 0x8009292C: dsll        $t9, $t9, 15
    ctx->r25 = ctx->r25 << 15;
    // 0x80092930: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80092934: ori         $t0, $zero, 0x1
    ctx->r8 = 0 | 0X1;
    // 0x80092938: beq         $a2, $t0, L_80092958
    if (ctx->r6 == ctx->r8) {
        // 0x8009293C: addu        $t7, $zero, $zero
        ctx->r15 = ADD32(0, 0);
            goto L_80092958;
    }
    // 0x8009293C: addu        $t7, $zero, $zero
    ctx->r15 = ADD32(0, 0);
    // 0x80092940: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x80092944: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x80092948: lh          $t5, 0x8($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X8);
    // 0x8009294C: lhu         $t7, 0xA($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0XA);
    // 0x80092950: j           L_8009299C
    // 0x80092954: sll         $t7, $t7, 15
    ctx->r15 = S32(ctx->r15 << 15);
        goto L_8009299C;
    // 0x80092954: sll         $t7, $t7, 15
    ctx->r15 = S32(ctx->r15 << 15);
L_80092958:
    // 0x80092958: lbu         $t4, 0x0($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X0);
    // 0x8009295C: bne         $t1, $s2, L_8009296C
    if (ctx->r9 != ctx->r18) {
        // 0x80092960: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_8009296C;
    }
    // 0x80092960: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80092964: beq         $s3, $zero, L_80092A30
    if (ctx->r19 == 0) {
        // 0x80092968: addu        $t1, $s3, $zero
        ctx->r9 = ADD32(ctx->r19, 0);
            goto L_80092A30;
    }
    // 0x80092968: addu        $t1, $s3, $zero
    ctx->r9 = ADD32(ctx->r19, 0);
L_8009296C:
    // 0x8009296C: lbu         $t5, 0x0($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X0);
    // 0x80092970: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80092974: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80092978: addu        $t4, $t4, $s5
    ctx->r12 = ADD32(ctx->r12, ctx->r21);
    // 0x8009297C: addu        $t5, $t5, $s5
    ctx->r13 = ADD32(ctx->r13, ctx->r21);
    // 0x80092980: lh          $t4, 0x0($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X0);
    // 0x80092984: lh          $t5, 0x0($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X0);
    // 0x80092988: nop

    // 0x8009298C: subu        $t6, $t5, $t4
    ctx->r14 = SUB32(ctx->r13, ctx->r12);
    // 0x80092990: mult        $t6, $v0
    result = S64(S32(ctx->r14)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80092994: sll         $t4, $t4, 15
    ctx->r12 = S32(ctx->r12 << 15);
    // 0x80092998: mflo        $t6
    ctx->r14 = lo;
L_8009299C:
    // 0x8009299C: jal         0x80092A54
    // 0x800929A0: cache       0x0D, 0x0($t2)

    func_80092A54(rdram, ctx);
        goto after_0;
    // 0x800929A0: cache       0x0D, 0x0($t2)

    after_0:
    // 0x800929A4: sd          $t3, 0x0($t2)
    SD(ctx->r11, 0X0, ctx->r10);
    // 0x800929A8: jal         0x80092A54
    // 0x800929AC: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    func_80092A54(rdram, ctx);
        goto after_1;
    // 0x800929AC: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    after_1:
    // 0x800929B0: sd          $t3, 0x0($t2)
    SD(ctx->r11, 0X0, ctx->r10);
    // 0x800929B4: cache       0x19, -0x8($t2)

    // 0x800929B8: addiu       $t8, $t8, -0x1
    ctx->r24 = ADD32(ctx->r24, -0X1);
    // 0x800929BC: bne         $t8, $zero, L_8009299C
    if (ctx->r24 != 0) {
        // 0x800929C0: addiu       $t2, $t2, 0x8
        ctx->r10 = ADD32(ctx->r10, 0X8);
            goto L_8009299C;
    }
    // 0x800929C0: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
L_800929C4:
    // 0x800929C4: srl         $t7, $t7, 15
    ctx->r15 = S32(U32(ctx->r15) >> 15);
    // 0x800929C8: sh          $t7, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r15;
    // 0x800929CC: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x800929D0: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x800929D4: sh          $t5, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r13;
    // 0x800929D8: lw          $ra, 0x0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X0);
    // 0x800929DC: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x800929E0: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x800929E4: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x800929E8: lw          $s3, 0x10($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X10);
    // 0x800929EC: lw          $s4, 0x14($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X14);
    // 0x800929F0: lw          $s5, 0x18($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X18);
    // 0x800929F4: jr          $ra
    // 0x800929F8: addiu       $sp, $sp, 0x1C
    ctx->r29 = ADD32(ctx->r29, 0X1C);
    return;
    // 0x800929F8: addiu       $sp, $sp, 0x1C
    ctx->r29 = ADD32(ctx->r29, 0X1C);
    // 0x800929FC: j           L_80092A10
    // 0x80092A00: dsll32      $t3, $t3, 1
    ctx->r11 = ctx->r11 << (1 + 32);
        goto L_80092A10;
    // 0x80092A00: dsll32      $t3, $t3, 1
    ctx->r11 = ctx->r11 << (1 + 32);
    // 0x80092A04: j           L_80092A10
    // 0x80092A08: dsll        $t3, $t3, 17
    ctx->r11 = ctx->r11 << 17;
        goto L_80092A10;
    // 0x80092A08: dsll        $t3, $t3, 17
    ctx->r11 = ctx->r11 << 17;
    // 0x80092A0C: dsll        $t3, $t3, 1
    ctx->r11 = ctx->r11 << 1;
L_80092A10:
    // 0x80092A10: sd          $t3, 0x0($t2)
    SD(ctx->r11, 0X0, ctx->r10);
    // 0x80092A14: andi        $t0, $t2, 0xF
    ctx->r8 = ctx->r10 & 0XF;
    // 0x80092A18: bne         $t0, $zero, L_80092A40
    if (ctx->r8 != 0) {
        // 0x80092A1C: addiu       $t2, $t2, 0x8
        ctx->r10 = ADD32(ctx->r10, 0X8);
            goto L_80092A40;
    }
    // 0x80092A1C: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x80092A20: sd          $zero, 0x0($t2)
    SD(0, 0X0, ctx->r10);
    // 0x80092A24: cache       0x19, -0x8($t2)

    // 0x80092A28: j           L_80092A40
    // 0x80092A2C: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
        goto L_80092A40;
    // 0x80092A2C: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
L_80092A30:
    // 0x80092A30: cache       0x0D, 0x0($t2)

    // 0x80092A34: sd          $zero, 0x0($t2)
    SD(0, 0X0, ctx->r10);
    // 0x80092A38: sd          $zero, 0x8($t2)
    SD(0, 0X8, ctx->r10);
    // 0x80092A3C: cache       0x19, 0x0($t2)

L_80092A40:
    // 0x80092A40: addiu       $t8, $t8, -0x1
    ctx->r24 = ADD32(ctx->r24, -0X1);
    // 0x80092A44: bne         $t8, $zero, L_80092A30
    if (ctx->r24 != 0) {
        // 0x80092A48: addiu       $t2, $t2, 0x10
        ctx->r10 = ADD32(ctx->r10, 0X10);
            goto L_80092A30;
    }
    // 0x80092A48: addiu       $t2, $t2, 0x10
    ctx->r10 = ADD32(ctx->r10, 0X10);
    // 0x80092A4C: j           L_800929C4
    // 0x80092A50: nop

        goto L_800929C4;
    // 0x80092A50: nop

;}
RECOMP_FUNC void func_80092A54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80092BA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092BA8: addiu       $sp, $sp, -0x1C
    ctx->r29 = ADD32(ctx->r29, -0X1C);
    // 0x80092BAC: sw          $ra, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r31;
    // 0x80092BB0: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80092BB4: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x80092BB8: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x80092BBC: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80092BC0: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x80092BC4: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    // 0x80092BC8: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80092BCC: lw          $t2, 0x4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4);
    // 0x80092BD0: lw          $s2, 0x18($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X18);
    // 0x80092BD4: lw          $s3, 0x1C($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X1C);
    // 0x80092BD8: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x80092BDC: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x80092BE0: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x80092BE4: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x80092BE8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80092BEC: srl         $t8, $t8, 3
    ctx->r24 = S32(U32(ctx->r24) >> 3);
    // 0x80092BF0: srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // 0x80092BF4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80092BF8: ori         $t0, $zero, 0x1
    ctx->r8 = 0 | 0X1;
    // 0x80092BFC: beq         $a2, $t0, L_80092C10
    if (ctx->r6 == ctx->r8) {
        // 0x80092C00: addu        $t7, $zero, $zero
        ctx->r15 = ADD32(0, 0);
            goto L_80092C10;
    }
    // 0x80092C00: addu        $t7, $zero, $zero
    ctx->r15 = ADD32(0, 0);
    // 0x80092C04: lhu         $t7, 0xA($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0XA);
    // 0x80092C08: nop

    // 0x80092C0C: sll         $t7, $t7, 15
    ctx->r15 = S32(ctx->r15 << 15);
L_80092C10:
    // 0x80092C10: ori         $t9, $zero, 0xFFFF
    ctx->r25 = 0 | 0XFFFF;
    // 0x80092C14: dsll        $t9, $t9, 15
    ctx->r25 = ctx->r25 << 15;
L_80092C18:
    // 0x80092C18: jal         0x80092CF0
    // 0x80092C1C: cache       0x0D, 0x0($t2)

    func_80092CF0(rdram, ctx);
        goto after_0;
    // 0x80092C1C: cache       0x0D, 0x0($t2)

    after_0:
    // 0x80092C20: sd          $t3, 0x0($t2)
    SD(ctx->r11, 0X0, ctx->r10);
    // 0x80092C24: jal         0x80092CF0
    // 0x80092C28: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    func_80092CF0(rdram, ctx);
        goto after_1;
    // 0x80092C28: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    after_1:
    // 0x80092C2C: sd          $t3, 0x0($t2)
    SD(ctx->r11, 0X0, ctx->r10);
    // 0x80092C30: cache       0x19, -0x8($t2)

    // 0x80092C34: addiu       $t8, $t8, -0x1
    ctx->r24 = ADD32(ctx->r24, -0X1);
    // 0x80092C38: bne         $t8, $zero, L_80092C18
    if (ctx->r24 != 0) {
        // 0x80092C3C: addiu       $t2, $t2, 0x8
        ctx->r10 = ADD32(ctx->r10, 0X8);
            goto L_80092C18;
    }
    // 0x80092C3C: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x80092C40: srl         $t7, $t7, 15
    ctx->r15 = S32(U32(ctx->r15) >> 15);
    // 0x80092C44: sh          $t7, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r15;
    // 0x80092C48: lw          $ra, 0x0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X0);
    // 0x80092C4C: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80092C50: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x80092C54: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x80092C58: lw          $s3, 0x10($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X10);
    // 0x80092C5C: lw          $s4, 0x14($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X14);
    // 0x80092C60: lw          $s5, 0x18($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X18);
    // 0x80092C64: jr          $ra
    // 0x80092C68: addiu       $sp, $sp, 0x1C
    ctx->r29 = ADD32(ctx->r29, 0X1C);
    return;
    // 0x80092C68: addiu       $sp, $sp, 0x1C
    ctx->r29 = ADD32(ctx->r29, 0X1C);
;}
RECOMP_FUNC void func_80092CF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80092E48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092E48: addiu       $sp, $sp, -0x1C
    ctx->r29 = ADD32(ctx->r29, -0X1C);
    // 0x80092E4C: sw          $ra, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r31;
    // 0x80092E50: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80092E54: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x80092E58: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x80092E5C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80092E60: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x80092E64: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    // 0x80092E68: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80092E6C: lw          $t2, 0x4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4);
    // 0x80092E70: lw          $s2, 0x18($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X18);
    // 0x80092E74: lw          $s3, 0x1C($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X1C);
    // 0x80092E78: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x80092E7C: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x80092E80: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x80092E84: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x80092E88: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80092E8C: ori         $t0, $zero, 0x1
    ctx->r8 = 0 | 0X1;
    // 0x80092E90: beq         $a2, $t0, L_80092EA4
    if (ctx->r6 == ctx->r8) {
        // 0x80092E94: addu        $t7, $zero, $zero
        ctx->r15 = ADD32(0, 0);
            goto L_80092EA4;
    }
    // 0x80092E94: addu        $t7, $zero, $zero
    ctx->r15 = ADD32(0, 0);
    // 0x80092E98: lhu         $t7, 0xA($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0XA);
    // 0x80092E9C: nop

    // 0x80092EA0: sll         $t7, $t7, 15
    ctx->r15 = S32(ctx->r15 << 15);
L_80092EA4:
    // 0x80092EA4: ori         $t9, $zero, 0xFFFF
    ctx->r25 = 0 | 0XFFFF;
    // 0x80092EA8: dsll        $t9, $t9, 15
    ctx->r25 = ctx->r25 << 15;
    // 0x80092EAC: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    // 0x80092EB0: ori         $s5, $s5, 0x1790
    ctx->r21 = ctx->r21 | 0X1790;
    // 0x80092EB4: srl         $t8, $t8, 3
    ctx->r24 = S32(U32(ctx->r24) >> 3);
    // 0x80092EB8: srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
L_80092EBC:
    // 0x80092EBC: jal         0x80092F94
    // 0x80092EC0: cache       0x0D, 0x0($t2)

    func_80092F94(rdram, ctx);
        goto after_0;
    // 0x80092EC0: cache       0x0D, 0x0($t2)

    after_0:
    // 0x80092EC4: sd          $t3, 0x0($t2)
    SD(ctx->r11, 0X0, ctx->r10);
    // 0x80092EC8: jal         0x80092F94
    // 0x80092ECC: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    func_80092F94(rdram, ctx);
        goto after_1;
    // 0x80092ECC: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    after_1:
    // 0x80092ED0: sd          $t3, 0x0($t2)
    SD(ctx->r11, 0X0, ctx->r10);
    // 0x80092ED4: cache       0x19, -0x8($t2)

    // 0x80092ED8: addiu       $t8, $t8, -0x1
    ctx->r24 = ADD32(ctx->r24, -0X1);
    // 0x80092EDC: bne         $t8, $zero, L_80092EBC
    if (ctx->r24 != 0) {
        // 0x80092EE0: addiu       $t2, $t2, 0x8
        ctx->r10 = ADD32(ctx->r10, 0X8);
            goto L_80092EBC;
    }
    // 0x80092EE0: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x80092EE4: srl         $t7, $t7, 15
    ctx->r15 = S32(U32(ctx->r15) >> 15);
    // 0x80092EE8: sh          $t7, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r15;
    // 0x80092EEC: lw          $ra, 0x0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X0);
    // 0x80092EF0: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80092EF4: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x80092EF8: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x80092EFC: lw          $s3, 0x10($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X10);
    // 0x80092F00: lw          $s4, 0x14($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X14);
    // 0x80092F04: lw          $s5, 0x18($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X18);
    // 0x80092F08: jr          $ra
    // 0x80092F0C: addiu       $sp, $sp, 0x1C
    ctx->r29 = ADD32(ctx->r29, 0X1C);
    return;
    // 0x80092F0C: addiu       $sp, $sp, 0x1C
    ctx->r29 = ADD32(ctx->r29, 0X1C);
;}
RECOMP_FUNC void func_80092F10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80092F94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
L_80092F10:
    // 0x80092F94: srl         $t0, $t7, 16
    ctx->r8 = S32(U32(ctx->r15) >> 16);
L_80092F20:
    // 0x80092F98: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
L_80092F30:
    // 0x80092F9C: lbu         $t4, 0x0($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X0);
L_80092F40:
    // 0x80092FA0: lbu         $t5, 0x1($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X1);
    // 0x80092FA4: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80092FA8: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80092FAC: addu        $t4, $t4, $s5
    ctx->r12 = ADD32(ctx->r12, ctx->r21);
    // 0x80092FB0: addu        $t5, $t5, $s5
    ctx->r13 = ADD32(ctx->r13, ctx->r21);
    // 0x80092FB4: lh          $t4, 0x0($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X0);
    // 0x80092FB8: bgtz        $t7, L_80092FC8
    if (SIGNED(ctx->r15) > 0) {
        // 0x80092FBC: lh          $t5, 0x0($t5)
        ctx->r13 = MEM_H(ctx->r13, 0X0);
            goto L_80092FC8;
    }
    // 0x80092FBC: lh          $t5, 0x0($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X0);
    // 0x80092FC0: and         $t7, $t7, $at
    ctx->r15 = ctx->r15 & ctx->r1;
    // 0x80092FC4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_80092FC8:
    // 0x80092FC8: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x80092FCC: subu        $t6, $t5, $t4
    ctx->r14 = SUB32(ctx->r13, ctx->r12);
    // 0x80092FD0: mult        $t6, $t0
    result = S64(S32(ctx->r14)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80092FD4: addu        $t3, $zero, $zero
    ctx->r11 = ADD32(0, 0);
    // 0x80092FD8: sll         $t4, $t4, 15
    ctx->r12 = S32(ctx->r12 << 15);
    // 0x80092FDC: sltu        $t0, $t1, $s2
    ctx->r8 = ctx->r9 < ctx->r18 ? 1 : 0;
    // 0x80092FE0: mflo        $t6
    ctx->r14 = lo;
    // 0x80092FE4: bne         $t0, $zero, L_80092FF8
    if (ctx->r8 != 0) {
        // 0x80092FE8: addu        $t6, $t6, $t4
        ctx->r14 = ADD32(ctx->r14, ctx->r12);
            goto L_80092FF8;
    }
    // 0x80092FE8: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x80092FEC: beq         $s3, $zero, L_80092F10
    if (ctx->r19 == 0) {
            // 0x80092FF0: subu        $t1, $t1, $s2
    ctx->r9 = SUB32(ctx->r9, ctx->r18);
    func_80092F10(rdram, ctx);
    return;
    }
    // 0x80092FF0: subu        $t1, $t1, $s2
    ctx->r9 = SUB32(ctx->r9, ctx->r18);
    // 0x80092FF4: addu        $t1, $t1, $s3
    ctx->r9 = ADD32(ctx->r9, ctx->r19);
L_80092FF8:
    // 0x80092FF8: and         $t6, $t6, $t9
    ctx->r14 = ctx->r14 & ctx->r25;
    // 0x80092FFC: or          $t3, $t3, $t6
    ctx->r11 = ctx->r11 | ctx->r14;
    // 0x80093000: srl         $t0, $t7, 16
    ctx->r8 = S32(U32(ctx->r15) >> 16);
    // 0x80093004: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x80093008: lbu         $t4, 0x0($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X0);
    // 0x8009300C: lbu         $t5, 0x1($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X1);
    // 0x80093010: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80093014: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80093018: addu        $t4, $t4, $s5
    ctx->r12 = ADD32(ctx->r12, ctx->r21);
    // 0x8009301C: addu        $t5, $t5, $s5
    ctx->r13 = ADD32(ctx->r13, ctx->r21);
    // 0x80093020: lh          $t4, 0x0($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X0);
    // 0x80093024: bgtz        $t7, L_80093034
    if (SIGNED(ctx->r15) > 0) {
        // 0x80093028: lh          $t5, 0x0($t5)
        ctx->r13 = MEM_H(ctx->r13, 0X0);
            goto L_80093034;
    }
    // 0x80093028: lh          $t5, 0x0($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X0);
    // 0x8009302C: and         $t7, $t7, $at
    ctx->r15 = ctx->r15 & ctx->r1;
    // 0x80093030: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_80093034:
    // 0x80093034: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x80093038: subu        $t6, $t5, $t4
    ctx->r14 = SUB32(ctx->r13, ctx->r12);
    // 0x8009303C: mult        $t6, $t0
    result = S64(S32(ctx->r14)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80093040: dsll        $t3, $t3, 16
    ctx->r11 = ctx->r11 << 16;
    // 0x80093044: sll         $t4, $t4, 15
    ctx->r12 = S32(ctx->r12 << 15);
    // 0x80093048: sltu        $t0, $t1, $s2
    ctx->r8 = ctx->r9 < ctx->r18 ? 1 : 0;
    // 0x8009304C: mflo        $t6
    ctx->r14 = lo;
    // 0x80093050: bne         $t0, $zero, L_80093064
    if (ctx->r8 != 0) {
        // 0x80093054: addu        $t6, $t6, $t4
        ctx->r14 = ADD32(ctx->r14, ctx->r12);
            goto L_80093064;
    }
    // 0x80093054: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x80093058: beq         $s3, $zero, L_80092F20
    if (ctx->r19 == 0) {
        // 0x8009305C: subu        $t1, $t1, $s2
        ctx->r9 = SUB32(ctx->r9, ctx->r18);
            goto L_80092F20;
    }
    // 0x8009305C: subu        $t1, $t1, $s2
    ctx->r9 = SUB32(ctx->r9, ctx->r18);
    // 0x80093060: addu        $t1, $t1, $s3
    ctx->r9 = ADD32(ctx->r9, ctx->r19);
L_80093064:
    // 0x80093064: and         $t6, $t6, $t9
    ctx->r14 = ctx->r14 & ctx->r25;
    // 0x80093068: or          $t3, $t3, $t6
    ctx->r11 = ctx->r11 | ctx->r14;
    // 0x8009306C: srl         $t0, $t7, 16
    ctx->r8 = S32(U32(ctx->r15) >> 16);
    // 0x80093070: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x80093074: lbu         $t4, 0x0($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X0);
    // 0x80093078: lbu         $t5, 0x1($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X1);
    // 0x8009307C: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80093080: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80093084: addu        $t4, $t4, $s5
    ctx->r12 = ADD32(ctx->r12, ctx->r21);
    // 0x80093088: addu        $t5, $t5, $s5
    ctx->r13 = ADD32(ctx->r13, ctx->r21);
    // 0x8009308C: lh          $t4, 0x0($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X0);
    // 0x80093090: bgtz        $t7, L_800930A0
    if (SIGNED(ctx->r15) > 0) {
        // 0x80093094: lh          $t5, 0x0($t5)
        ctx->r13 = MEM_H(ctx->r13, 0X0);
            goto L_800930A0;
    }
    // 0x80093094: lh          $t5, 0x0($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X0);
    // 0x80093098: and         $t7, $t7, $at
    ctx->r15 = ctx->r15 & ctx->r1;
    // 0x8009309C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_800930A0:
    // 0x800930A0: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x800930A4: subu        $t6, $t5, $t4
    ctx->r14 = SUB32(ctx->r13, ctx->r12);
    // 0x800930A8: mult        $t6, $t0
    result = S64(S32(ctx->r14)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800930AC: dsll        $t3, $t3, 16
    ctx->r11 = ctx->r11 << 16;
    // 0x800930B0: sll         $t4, $t4, 15
    ctx->r12 = S32(ctx->r12 << 15);
    // 0x800930B4: sltu        $t0, $t1, $s2
    ctx->r8 = ctx->r9 < ctx->r18 ? 1 : 0;
    // 0x800930B8: mflo        $t6
    ctx->r14 = lo;
    // 0x800930BC: bne         $t0, $zero, L_800930D0
    if (ctx->r8 != 0) {
        // 0x800930C0: addu        $t6, $t6, $t4
        ctx->r14 = ADD32(ctx->r14, ctx->r12);
            goto L_800930D0;
    }
    // 0x800930C0: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x800930C4: beq         $s3, $zero, L_80092F30
    if (ctx->r19 == 0) {
        // 0x800930C8: subu        $t1, $t1, $s2
        ctx->r9 = SUB32(ctx->r9, ctx->r18);
            goto L_80092F30;
    }
    // 0x800930C8: subu        $t1, $t1, $s2
    ctx->r9 = SUB32(ctx->r9, ctx->r18);
    // 0x800930CC: addu        $t1, $t1, $s3
    ctx->r9 = ADD32(ctx->r9, ctx->r19);
L_800930D0:
    // 0x800930D0: and         $t6, $t6, $t9
    ctx->r14 = ctx->r14 & ctx->r25;
    // 0x800930D4: or          $t3, $t3, $t6
    ctx->r11 = ctx->r11 | ctx->r14;
    // 0x800930D8: srl         $t0, $t7, 16
    ctx->r8 = S32(U32(ctx->r15) >> 16);
    // 0x800930DC: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x800930E0: lbu         $t4, 0x0($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X0);
    // 0x800930E4: lbu         $t5, 0x1($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X1);
    // 0x800930E8: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x800930EC: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x800930F0: addu        $t4, $t4, $s5
    ctx->r12 = ADD32(ctx->r12, ctx->r21);
    // 0x800930F4: addu        $t5, $t5, $s5
    ctx->r13 = ADD32(ctx->r13, ctx->r21);
    // 0x800930F8: lh          $t4, 0x0($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X0);
    // 0x800930FC: bgtz        $t7, L_8009310C
    if (SIGNED(ctx->r15) > 0) {
        // 0x80093100: lh          $t5, 0x0($t5)
        ctx->r13 = MEM_H(ctx->r13, 0X0);
            goto L_8009310C;
    }
    // 0x80093100: lh          $t5, 0x0($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X0);
    // 0x80093104: and         $t7, $t7, $at
    ctx->r15 = ctx->r15 & ctx->r1;
    // 0x80093108: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_8009310C:
    // 0x8009310C: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x80093110: subu        $t6, $t5, $t4
    ctx->r14 = SUB32(ctx->r13, ctx->r12);
    // 0x80093114: mult        $t6, $t0
    result = S64(S32(ctx->r14)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80093118: dsll        $t3, $t3, 1
    ctx->r11 = ctx->r11 << 1;
    // 0x8009311C: sll         $t4, $t4, 15
    ctx->r12 = S32(ctx->r12 << 15);
    // 0x80093120: sltu        $t0, $t1, $s2
    ctx->r8 = ctx->r9 < ctx->r18 ? 1 : 0;
    // 0x80093124: mflo        $t6
    ctx->r14 = lo;
    // 0x80093128: bne         $t0, $zero, L_8009313C
    if (ctx->r8 != 0) {
        // 0x8009312C: addu        $t6, $t6, $t4
        ctx->r14 = ADD32(ctx->r14, ctx->r12);
            goto L_8009313C;
    }
    // 0x8009312C: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x80093130: beq         $s3, $zero, L_80092F40
    if (ctx->r19 == 0) {
        // 0x80093134: subu        $t1, $t1, $s2
        ctx->r9 = SUB32(ctx->r9, ctx->r18);
            goto L_80092F40;
    }
    // 0x80093134: subu        $t1, $t1, $s2
    ctx->r9 = SUB32(ctx->r9, ctx->r18);
    // 0x80093138: addu        $t1, $t1, $s3
    ctx->r9 = ADD32(ctx->r9, ctx->r19);
L_8009313C:
    // 0x8009313C: sra         $t6, $t6, 15
    ctx->r14 = S32(SIGNED(ctx->r14) >> 15);
    // 0x80093140: andi        $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 & 0XFFFF;
    // 0x80093144: jr          $ra
    // 0x80093148: or          $t3, $t3, $t6
    ctx->r11 = ctx->r11 | ctx->r14;
    return;
    // 0x80093148: or          $t3, $t3, $t6
    ctx->r11 = ctx->r11 | ctx->r14;
;}
RECOMP_FUNC void func_8009314C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009314C: addiu       $sp, $sp, -0x1C
    ctx->r29 = ADD32(ctx->r29, -0X1C);
    // 0x80093150: sw          $ra, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r31;
    // 0x80093154: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80093158: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x8009315C: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x80093160: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80093164: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x80093168: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    // 0x8009316C: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80093170: lw          $t2, 0x4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4);
    // 0x80093174: lw          $s2, 0x18($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X18);
    // 0x80093178: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x8009317C: lw          $s3, 0x1C($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X1C);
    // 0x80093180: srl         $t8, $t8, 3
    ctx->r24 = S32(U32(ctx->r24) >> 3);
L_80093184:
    // 0x80093184: cache       0x0D, 0x0($t2)

    // 0x80093188: lhu         $t4, 0x0($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X0);
    // 0x8009318C: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x80093190: bne         $t1, $s2, L_800931A4
    if (ctx->r9 != ctx->r18) {
        // 0x80093194: addu        $t3, $zero, $zero
        ctx->r11 = ADD32(0, 0);
            goto L_800931A4;
    }
    // 0x80093194: addu        $t3, $zero, $zero
    ctx->r11 = ADD32(0, 0);
    // 0x80093198: beq         $s3, $zero, L_800931A4
    if (ctx->r19 == 0) {
        // 0x8009319C: addiu       $t1, $t1, -0x2
        ctx->r9 = ADD32(ctx->r9, -0X2);
            goto L_800931A4;
    }
    // 0x8009319C: addiu       $t1, $t1, -0x2
    ctx->r9 = ADD32(ctx->r9, -0X2);
    // 0x800931A0: addu        $t1, $s3, $zero
    ctx->r9 = ADD32(ctx->r19, 0);
L_800931A4:
    // 0x800931A4: or          $t3, $t3, $t4
    ctx->r11 = ctx->r11 | ctx->r12;
    // 0x800931A8: lhu         $t4, 0x0($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X0);
    // 0x800931AC: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x800931B0: bne         $t1, $s2, L_800931C4
    if (ctx->r9 != ctx->r18) {
        // 0x800931B4: dsll        $t3, $t3, 16
        ctx->r11 = ctx->r11 << 16;
            goto L_800931C4;
    }
    // 0x800931B4: dsll        $t3, $t3, 16
    ctx->r11 = ctx->r11 << 16;
    // 0x800931B8: beq         $s3, $zero, L_800931C4
    if (ctx->r19 == 0) {
        // 0x800931BC: addiu       $t1, $t1, -0x2
        ctx->r9 = ADD32(ctx->r9, -0X2);
            goto L_800931C4;
    }
    // 0x800931BC: addiu       $t1, $t1, -0x2
    ctx->r9 = ADD32(ctx->r9, -0X2);
    // 0x800931C0: addu        $t1, $s3, $zero
    ctx->r9 = ADD32(ctx->r19, 0);
L_800931C4:
    // 0x800931C4: or          $t3, $t3, $t4
    ctx->r11 = ctx->r11 | ctx->r12;
    // 0x800931C8: lhu         $t4, 0x0($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X0);
    // 0x800931CC: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x800931D0: bne         $t1, $s2, L_800931E4
    if (ctx->r9 != ctx->r18) {
        // 0x800931D4: dsll        $t3, $t3, 16
        ctx->r11 = ctx->r11 << 16;
            goto L_800931E4;
    }
    // 0x800931D4: dsll        $t3, $t3, 16
    ctx->r11 = ctx->r11 << 16;
    // 0x800931D8: beq         $s3, $zero, L_800931E4
    if (ctx->r19 == 0) {
        // 0x800931DC: addiu       $t1, $t1, -0x2
        ctx->r9 = ADD32(ctx->r9, -0X2);
            goto L_800931E4;
    }
    // 0x800931DC: addiu       $t1, $t1, -0x2
    ctx->r9 = ADD32(ctx->r9, -0X2);
    // 0x800931E0: addu        $t1, $s3, $zero
    ctx->r9 = ADD32(ctx->r19, 0);
L_800931E4:
    // 0x800931E4: or          $t3, $t3, $t4
    ctx->r11 = ctx->r11 | ctx->r12;
    // 0x800931E8: lhu         $t4, 0x0($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X0);
    // 0x800931EC: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x800931F0: bne         $t1, $s2, L_80093204
    if (ctx->r9 != ctx->r18) {
        // 0x800931F4: dsll        $t3, $t3, 16
        ctx->r11 = ctx->r11 << 16;
            goto L_80093204;
    }
    // 0x800931F4: dsll        $t3, $t3, 16
    ctx->r11 = ctx->r11 << 16;
    // 0x800931F8: beq         $s3, $zero, L_80093204
    if (ctx->r19 == 0) {
        // 0x800931FC: addiu       $t1, $t1, -0x2
        ctx->r9 = ADD32(ctx->r9, -0X2);
            goto L_80093204;
    }
    // 0x800931FC: addiu       $t1, $t1, -0x2
    ctx->r9 = ADD32(ctx->r9, -0X2);
    // 0x80093200: addu        $t1, $s3, $zero
    ctx->r9 = ADD32(ctx->r19, 0);
L_80093204:
    // 0x80093204: or          $t3, $t3, $t4
    ctx->r11 = ctx->r11 | ctx->r12;
    // 0x80093208: sd          $t3, 0x0($t2)
    SD(ctx->r11, 0X0, ctx->r10);
    // 0x8009320C: lhu         $t4, 0x0($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X0);
    // 0x80093210: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x80093214: bne         $t1, $s2, L_80093228
    if (ctx->r9 != ctx->r18) {
        // 0x80093218: addu        $t3, $zero, $zero
        ctx->r11 = ADD32(0, 0);
            goto L_80093228;
    }
    // 0x80093218: addu        $t3, $zero, $zero
    ctx->r11 = ADD32(0, 0);
    // 0x8009321C: beq         $s3, $zero, L_80093228
    if (ctx->r19 == 0) {
        // 0x80093220: addiu       $t1, $t1, -0x2
        ctx->r9 = ADD32(ctx->r9, -0X2);
            goto L_80093228;
    }
    // 0x80093220: addiu       $t1, $t1, -0x2
    ctx->r9 = ADD32(ctx->r9, -0X2);
    // 0x80093224: addu        $t1, $s3, $zero
    ctx->r9 = ADD32(ctx->r19, 0);
L_80093228:
    // 0x80093228: or          $t3, $t3, $t4
    ctx->r11 = ctx->r11 | ctx->r12;
    // 0x8009322C: lhu         $t4, 0x0($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X0);
    // 0x80093230: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x80093234: bne         $t1, $s2, L_80093248
    if (ctx->r9 != ctx->r18) {
        // 0x80093238: dsll        $t3, $t3, 16
        ctx->r11 = ctx->r11 << 16;
            goto L_80093248;
    }
    // 0x80093238: dsll        $t3, $t3, 16
    ctx->r11 = ctx->r11 << 16;
    // 0x8009323C: beq         $s3, $zero, L_80093248
    if (ctx->r19 == 0) {
        // 0x80093240: addiu       $t1, $t1, -0x2
        ctx->r9 = ADD32(ctx->r9, -0X2);
            goto L_80093248;
    }
    // 0x80093240: addiu       $t1, $t1, -0x2
    ctx->r9 = ADD32(ctx->r9, -0X2);
    // 0x80093244: addu        $t1, $s3, $zero
    ctx->r9 = ADD32(ctx->r19, 0);
L_80093248:
    // 0x80093248: or          $t3, $t3, $t4
    ctx->r11 = ctx->r11 | ctx->r12;
    // 0x8009324C: lhu         $t4, 0x0($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X0);
    // 0x80093250: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x80093254: bne         $t1, $s2, L_80093268
    if (ctx->r9 != ctx->r18) {
        // 0x80093258: dsll        $t3, $t3, 16
        ctx->r11 = ctx->r11 << 16;
            goto L_80093268;
    }
    // 0x80093258: dsll        $t3, $t3, 16
    ctx->r11 = ctx->r11 << 16;
    // 0x8009325C: beq         $s3, $zero, L_80093268
    if (ctx->r19 == 0) {
        // 0x80093260: addiu       $t1, $t1, -0x2
        ctx->r9 = ADD32(ctx->r9, -0X2);
            goto L_80093268;
    }
    // 0x80093260: addiu       $t1, $t1, -0x2
    ctx->r9 = ADD32(ctx->r9, -0X2);
    // 0x80093264: addu        $t1, $s3, $zero
    ctx->r9 = ADD32(ctx->r19, 0);
L_80093268:
    // 0x80093268: or          $t3, $t3, $t4
    ctx->r11 = ctx->r11 | ctx->r12;
    // 0x8009326C: lhu         $t4, 0x0($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X0);
    // 0x80093270: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x80093274: bne         $t1, $s2, L_80093288
    if (ctx->r9 != ctx->r18) {
        // 0x80093278: dsll        $t3, $t3, 16
        ctx->r11 = ctx->r11 << 16;
            goto L_80093288;
    }
    // 0x80093278: dsll        $t3, $t3, 16
    ctx->r11 = ctx->r11 << 16;
    // 0x8009327C: beq         $s3, $zero, L_80093288
    if (ctx->r19 == 0) {
        // 0x80093280: addiu       $t1, $t1, -0x2
        ctx->r9 = ADD32(ctx->r9, -0X2);
            goto L_80093288;
    }
    // 0x80093280: addiu       $t1, $t1, -0x2
    ctx->r9 = ADD32(ctx->r9, -0X2);
    // 0x80093284: addu        $t1, $s3, $zero
    ctx->r9 = ADD32(ctx->r19, 0);
L_80093288:
    // 0x80093288: or          $t3, $t3, $t4
    ctx->r11 = ctx->r11 | ctx->r12;
    // 0x8009328C: sd          $t3, 0x8($t2)
    SD(ctx->r11, 0X8, ctx->r10);
    // 0x80093290: cache       0x19, 0x0($t2)

    // 0x80093294: addiu       $t8, $t8, -0x1
    ctx->r24 = ADD32(ctx->r24, -0X1);
    // 0x80093298: bne         $t8, $zero, L_80093184
    if (ctx->r24 != 0) {
        // 0x8009329C: addiu       $t2, $t2, 0x10
        ctx->r10 = ADD32(ctx->r10, 0X10);
            goto L_80093184;
    }
    // 0x8009329C: addiu       $t2, $t2, 0x10
    ctx->r10 = ADD32(ctx->r10, 0X10);
    // 0x800932A0: lw          $ra, 0x0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X0);
    // 0x800932A4: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x800932A8: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x800932AC: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x800932B0: lw          $s3, 0x10($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X10);
    // 0x800932B4: lw          $s4, 0x14($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X14);
    // 0x800932B8: lw          $s5, 0x18($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X18);
    // 0x800932BC: jr          $ra
    // 0x800932C0: addiu       $sp, $sp, 0x1C
    ctx->r29 = ADD32(ctx->r29, 0X1C);
    return;
    // 0x800932C0: addiu       $sp, $sp, 0x1C
    ctx->r29 = ADD32(ctx->r29, 0X1C);
;}
RECOMP_FUNC void func_800932C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800932C4: addiu       $sp, $sp, -0x1C
    ctx->r29 = ADD32(ctx->r29, -0X1C);
    // 0x800932C8: sw          $ra, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r31;
    // 0x800932CC: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800932D0: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x800932D4: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x800932D8: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x800932DC: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x800932E0: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    // 0x800932E4: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800932E8: lw          $t2, 0x4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4);
    // 0x800932EC: lw          $s2, 0x18($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X18);
    // 0x800932F0: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x800932F4: lw          $s3, 0x1C($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X1C);
    // 0x800932F8: srl         $t8, $t8, 3
    ctx->r24 = S32(U32(ctx->r24) >> 3);
    // 0x800932FC: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    // 0x80093300: ori         $s5, $s5, 0x1790
    ctx->r21 = ctx->r21 | 0X1790;
L_80093304:
    // 0x80093304: cache       0x0D, 0x0($t2)

    // 0x80093308: lbu         $t4, 0x0($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X0);
    // 0x8009330C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80093310: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80093314: addu        $t4, $t4, $s5
    ctx->r12 = ADD32(ctx->r12, ctx->r21);
    // 0x80093318: lhu         $t4, 0x0($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X0);
    // 0x8009331C: bne         $t1, $s2, L_80093330
    if (ctx->r9 != ctx->r18) {
        // 0x80093320: addu        $t3, $zero, $zero
        ctx->r11 = ADD32(0, 0);
            goto L_80093330;
    }
    // 0x80093320: addu        $t3, $zero, $zero
    ctx->r11 = ADD32(0, 0);
    // 0x80093324: beq         $s3, $zero, L_80093330
    if (ctx->r19 == 0) {
        // 0x80093328: addiu       $t1, $t1, -0x1
        ctx->r9 = ADD32(ctx->r9, -0X1);
            goto L_80093330;
    }
    // 0x80093328: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x8009332C: addu        $t1, $s3, $zero
    ctx->r9 = ADD32(ctx->r19, 0);
L_80093330:
    // 0x80093330: or          $t3, $t3, $t4
    ctx->r11 = ctx->r11 | ctx->r12;
    // 0x80093334: lbu         $t4, 0x0($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X0);
    // 0x80093338: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8009333C: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80093340: addu        $t4, $t4, $s5
    ctx->r12 = ADD32(ctx->r12, ctx->r21);
    // 0x80093344: lhu         $t4, 0x0($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X0);
    // 0x80093348: bne         $t1, $s2, L_8009335C
    if (ctx->r9 != ctx->r18) {
        // 0x8009334C: dsll        $t3, $t3, 16
        ctx->r11 = ctx->r11 << 16;
            goto L_8009335C;
    }
    // 0x8009334C: dsll        $t3, $t3, 16
    ctx->r11 = ctx->r11 << 16;
    // 0x80093350: beq         $s3, $zero, L_8009335C
    if (ctx->r19 == 0) {
        // 0x80093354: addiu       $t1, $t1, -0x1
        ctx->r9 = ADD32(ctx->r9, -0X1);
            goto L_8009335C;
    }
    // 0x80093354: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x80093358: addu        $t1, $s3, $zero
    ctx->r9 = ADD32(ctx->r19, 0);
L_8009335C:
    // 0x8009335C: or          $t3, $t3, $t4
    ctx->r11 = ctx->r11 | ctx->r12;
    // 0x80093360: lbu         $t4, 0x0($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X0);
    // 0x80093364: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80093368: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8009336C: addu        $t4, $t4, $s5
    ctx->r12 = ADD32(ctx->r12, ctx->r21);
    // 0x80093370: lhu         $t4, 0x0($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X0);
    // 0x80093374: bne         $t1, $s2, L_80093388
    if (ctx->r9 != ctx->r18) {
        // 0x80093378: dsll        $t3, $t3, 16
        ctx->r11 = ctx->r11 << 16;
            goto L_80093388;
    }
    // 0x80093378: dsll        $t3, $t3, 16
    ctx->r11 = ctx->r11 << 16;
    // 0x8009337C: beq         $s3, $zero, L_80093388
    if (ctx->r19 == 0) {
        // 0x80093380: addiu       $t1, $t1, -0x1
        ctx->r9 = ADD32(ctx->r9, -0X1);
            goto L_80093388;
    }
    // 0x80093380: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x80093384: addu        $t1, $s3, $zero
    ctx->r9 = ADD32(ctx->r19, 0);
L_80093388:
    // 0x80093388: or          $t3, $t3, $t4
    ctx->r11 = ctx->r11 | ctx->r12;
    // 0x8009338C: lbu         $t4, 0x0($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X0);
    // 0x80093390: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80093394: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80093398: addu        $t4, $t4, $s5
    ctx->r12 = ADD32(ctx->r12, ctx->r21);
    // 0x8009339C: lhu         $t4, 0x0($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X0);
    // 0x800933A0: bne         $t1, $s2, L_800933B4
    if (ctx->r9 != ctx->r18) {
        // 0x800933A4: dsll        $t3, $t3, 16
        ctx->r11 = ctx->r11 << 16;
            goto L_800933B4;
    }
    // 0x800933A4: dsll        $t3, $t3, 16
    ctx->r11 = ctx->r11 << 16;
    // 0x800933A8: beq         $s3, $zero, L_800933B4
    if (ctx->r19 == 0) {
        // 0x800933AC: addiu       $t1, $t1, -0x1
        ctx->r9 = ADD32(ctx->r9, -0X1);
            goto L_800933B4;
    }
    // 0x800933AC: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800933B0: addu        $t1, $s3, $zero
    ctx->r9 = ADD32(ctx->r19, 0);
L_800933B4:
    // 0x800933B4: or          $t3, $t3, $t4
    ctx->r11 = ctx->r11 | ctx->r12;
    // 0x800933B8: sd          $t3, 0x0($t2)
    SD(ctx->r11, 0X0, ctx->r10);
    // 0x800933BC: lbu         $t4, 0x0($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X0);
    // 0x800933C0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800933C4: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x800933C8: addu        $t4, $t4, $s5
    ctx->r12 = ADD32(ctx->r12, ctx->r21);
    // 0x800933CC: lhu         $t4, 0x0($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X0);
    // 0x800933D0: bne         $t1, $s2, L_800933E4
    if (ctx->r9 != ctx->r18) {
        // 0x800933D4: addu        $t3, $zero, $zero
        ctx->r11 = ADD32(0, 0);
            goto L_800933E4;
    }
    // 0x800933D4: addu        $t3, $zero, $zero
    ctx->r11 = ADD32(0, 0);
    // 0x800933D8: beq         $s3, $zero, L_800933E4
    if (ctx->r19 == 0) {
        // 0x800933DC: addiu       $t1, $t1, -0x1
        ctx->r9 = ADD32(ctx->r9, -0X1);
            goto L_800933E4;
    }
    // 0x800933DC: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800933E0: addu        $t1, $s3, $zero
    ctx->r9 = ADD32(ctx->r19, 0);
L_800933E4:
    // 0x800933E4: or          $t3, $t3, $t4
    ctx->r11 = ctx->r11 | ctx->r12;
    // 0x800933E8: lbu         $t4, 0x0($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X0);
    // 0x800933EC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800933F0: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x800933F4: addu        $t4, $t4, $s5
    ctx->r12 = ADD32(ctx->r12, ctx->r21);
    // 0x800933F8: lhu         $t4, 0x0($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X0);
    // 0x800933FC: bne         $t1, $s2, L_80093410
    if (ctx->r9 != ctx->r18) {
        // 0x80093400: dsll        $t3, $t3, 16
        ctx->r11 = ctx->r11 << 16;
            goto L_80093410;
    }
    // 0x80093400: dsll        $t3, $t3, 16
    ctx->r11 = ctx->r11 << 16;
    // 0x80093404: beq         $s3, $zero, L_80093410
    if (ctx->r19 == 0) {
        // 0x80093408: addiu       $t1, $t1, -0x1
        ctx->r9 = ADD32(ctx->r9, -0X1);
            goto L_80093410;
    }
    // 0x80093408: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x8009340C: addu        $t1, $s3, $zero
    ctx->r9 = ADD32(ctx->r19, 0);
L_80093410:
    // 0x80093410: or          $t3, $t3, $t4
    ctx->r11 = ctx->r11 | ctx->r12;
    // 0x80093414: lbu         $t4, 0x0($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X0);
    // 0x80093418: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8009341C: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80093420: addu        $t4, $t4, $s5
    ctx->r12 = ADD32(ctx->r12, ctx->r21);
    // 0x80093424: lhu         $t4, 0x0($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X0);
    // 0x80093428: bne         $t1, $s2, L_8009343C
    if (ctx->r9 != ctx->r18) {
        // 0x8009342C: dsll        $t3, $t3, 16
        ctx->r11 = ctx->r11 << 16;
            goto L_8009343C;
    }
    // 0x8009342C: dsll        $t3, $t3, 16
    ctx->r11 = ctx->r11 << 16;
    // 0x80093430: beq         $s3, $zero, L_8009343C
    if (ctx->r19 == 0) {
        // 0x80093434: addiu       $t1, $t1, -0x1
        ctx->r9 = ADD32(ctx->r9, -0X1);
            goto L_8009343C;
    }
    // 0x80093434: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x80093438: addu        $t1, $s3, $zero
    ctx->r9 = ADD32(ctx->r19, 0);
L_8009343C:
    // 0x8009343C: or          $t3, $t3, $t4
    ctx->r11 = ctx->r11 | ctx->r12;
    // 0x80093440: lbu         $t4, 0x0($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X0);
    // 0x80093444: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80093448: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8009344C: addu        $t4, $t4, $s5
    ctx->r12 = ADD32(ctx->r12, ctx->r21);
    // 0x80093450: lhu         $t4, 0x0($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X0);
    // 0x80093454: bne         $t1, $s2, L_80093468
    if (ctx->r9 != ctx->r18) {
        // 0x80093458: dsll        $t3, $t3, 16
        ctx->r11 = ctx->r11 << 16;
            goto L_80093468;
    }
    // 0x80093458: dsll        $t3, $t3, 16
    ctx->r11 = ctx->r11 << 16;
    // 0x8009345C: beq         $s3, $zero, L_80093468
    if (ctx->r19 == 0) {
        // 0x80093460: addiu       $t1, $t1, -0x1
        ctx->r9 = ADD32(ctx->r9, -0X1);
            goto L_80093468;
    }
    // 0x80093460: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x80093464: addu        $t1, $s3, $zero
    ctx->r9 = ADD32(ctx->r19, 0);
L_80093468:
    // 0x80093468: or          $t3, $t3, $t4
    ctx->r11 = ctx->r11 | ctx->r12;
    // 0x8009346C: sd          $t3, 0x8($t2)
    SD(ctx->r11, 0X8, ctx->r10);
    // 0x80093470: cache       0x19, 0x0($t2)

    // 0x80093474: addiu       $t8, $t8, -0x1
    ctx->r24 = ADD32(ctx->r24, -0X1);
    // 0x80093478: bne         $t8, $zero, L_80093304
    if (ctx->r24 != 0) {
        // 0x8009347C: addiu       $t2, $t2, 0x10
        ctx->r10 = ADD32(ctx->r10, 0X10);
            goto L_80093304;
    }
    // 0x8009347C: addiu       $t2, $t2, 0x10
    ctx->r10 = ADD32(ctx->r10, 0X10);
    // 0x80093480: lw          $ra, 0x0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X0);
    // 0x80093484: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80093488: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x8009348C: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x80093490: lw          $s3, 0x10($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X10);
    // 0x80093494: lw          $s4, 0x14($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X14);
    // 0x80093498: lw          $s5, 0x18($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X18);
    // 0x8009349C: jr          $ra
    // 0x800934A0: addiu       $sp, $sp, 0x1C
    ctx->r29 = ADD32(ctx->r29, 0X1C);
    return;
    // 0x800934A0: addiu       $sp, $sp, 0x1C
    ctx->r29 = ADD32(ctx->r29, 0X1C);
;}
