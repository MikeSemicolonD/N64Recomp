#include "recomp.h"
#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>  // getenv for ROGUESQ_LOG_DPC gate

RECOMP_FUNC void func_800971E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800971E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800971EC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800971F0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800971F4: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800971F8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800971FC: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80097200: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80097204: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x80097208: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8009720C: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x80097210: beq         $v1, $v0, L_80097280
    if (ctx->r3 == ctx->r2) {
        // 0x80097214: addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
            goto L_80097280;
    }
    // 0x80097214: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80097218: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x8009721C: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
L_80097220:
    // 0x80097220: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x80097224: addu        $a1, $s1, $v0
    ctx->r5 = ADD32(ctx->r17, ctx->r2);
    // 0x80097228: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8009722C: beq         $v0, $s3, L_8009725C
    if (ctx->r2 == ctx->r19) {
        // 0x80097230: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8009725C;
    }
    // 0x80097230: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80097234: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x80097238: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_8009723C:
    // 0x8009723C: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    // 0x80097240: beq         $v0, $v1, L_8009725C
    if (ctx->r2 == ctx->r3) {
        // 0x80097244: addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
            goto L_8009725C;
    }
    // 0x80097244: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x80097248: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8009724C: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80097250: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80097254: bne         $v0, $a0, L_8009723C
    if (ctx->r2 != ctx->r4) {
        // 0x80097258: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8009723C;
    }
    // 0x80097258: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8009725C:
    // 0x8009725C: beql        $v0, $zero, L_80097274
    if (ctx->r2 == 0) {
        // 0x80097260: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_80097274;
    }
    goto skip_0;
    // 0x80097260: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    skip_0:
    // 0x80097264: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x80097268: jal         0x80084C08
    // 0x8009726C: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    func_80084C08(rdram, ctx);
        goto after_0;
    // 0x8009726C: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    after_0:
    // 0x80097270: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_80097274:
    // 0x80097274: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x80097278: bne         $a0, $s2, L_80097220
    if (ctx->r4 != ctx->r18) {
        // 0x8009727C: nop
    
            goto L_80097220;
    }
    // 0x8009727C: nop

L_80097280:
    // 0x80097280: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80097284: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80097288: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8009728C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80097290: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80097294: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80097298: jr          $ra
    // 0x8009729C: nop

    return;
    // 0x8009729C: nop

;}
RECOMP_FUNC void func_800972A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800972A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800972A4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800972A8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800972AC: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800972B0: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800972B4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800972B8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800972BC: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x800972C0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800972C4: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x800972C8: beq         $v1, $v0, L_8009733C
    if (ctx->r3 == ctx->r2) {
        // 0x800972CC: addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
            goto L_8009733C;
    }
    // 0x800972CC: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800972D0: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x800972D4: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
L_800972D8:
    // 0x800972D8: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x800972DC: addu        $a1, $s1, $v0
    ctx->r5 = ADD32(ctx->r17, ctx->r2);
    // 0x800972E0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800972E4: beq         $v0, $s3, L_80097314
    if (ctx->r2 == ctx->r19) {
        // 0x800972E8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80097314;
    }
    // 0x800972E8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800972EC: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x800972F0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_800972F4:
    // 0x800972F4: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    // 0x800972F8: beq         $v0, $v1, L_80097314
    if (ctx->r2 == ctx->r3) {
        // 0x800972FC: addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
            goto L_80097314;
    }
    // 0x800972FC: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x80097300: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80097304: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80097308: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8009730C: bne         $v0, $a0, L_800972F4
    if (ctx->r2 != ctx->r4) {
        // 0x80097310: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800972F4;
    }
    // 0x80097310: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80097314:
    // 0x80097314: beql        $v0, $zero, L_80097330
    if (ctx->r2 == 0) {
        // 0x80097318: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_80097330;
    }
    goto skip_0;
    // 0x80097318: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    skip_0:
    // 0x8009731C: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x80097320: lhu         $a2, 0xA($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0XA);
    // 0x80097324: jal         0x80084E44
    // 0x80097328: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
    func_80084E44(rdram, ctx);
        goto after_0;
    // 0x80097328: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
    after_0:
    // 0x8009732C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_80097330:
    // 0x80097330: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x80097334: bne         $a0, $s2, L_800972D8
    if (ctx->r4 != ctx->r18) {
        // 0x80097338: nop
    
            goto L_800972D8;
    }
    // 0x80097338: nop

L_8009733C:
    // 0x8009733C: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80097340: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80097344: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80097348: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8009734C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80097350: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80097354: jr          $ra
    // 0x80097358: nop

    return;
    // 0x80097358: nop

;}
RECOMP_FUNC void func_8009735C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009735C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80097360: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80097364: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80097368: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x8009736C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80097370: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x80097374: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80097378: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8009737C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80097380: jal         0x800925F4
    // 0x80097384: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    func_800925F4(rdram, ctx);
        goto after_0;
    // 0x80097384: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_0:
    // 0x80097388: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x8009738C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80097390: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80097394: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x80097398: beq         $v1, $v0, L_8009740C
    if (ctx->r3 == ctx->r2) {
        // 0x8009739C: addiu       $s2, $sp, 0x10
        ctx->r18 = ADD32(ctx->r29, 0X10);
            goto L_8009740C;
    }
    // 0x8009739C: addiu       $s2, $sp, 0x10
    ctx->r18 = ADD32(ctx->r29, 0X10);
    // 0x800973A0: ori         $s3, $zero, 0xFFFF
    ctx->r19 = 0 | 0XFFFF;
    // 0x800973A4: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
L_800973A8:
    // 0x800973A8: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x800973AC: beql        $v0, $s3, L_800973E8
    if (ctx->r2 == ctx->r19) {
        // 0x800973B0: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800973E8;
    }
    goto skip_0;
    // 0x800973B0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    skip_0:
    // 0x800973B4: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x800973B8: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
L_800973BC:
    // 0x800973BC: bnel        $v0, $v1, L_800973D8
    if (ctx->r2 != ctx->r3) {
        // 0x800973C0: addiu       $a1, $a1, 0x18
        ctx->r5 = ADD32(ctx->r5, 0X18);
            goto L_800973D8;
    }
    goto skip_1;
    // 0x800973C0: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    skip_1:
    // 0x800973C4: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x800973C8: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x800973CC: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800973D0: j           L_800973E8
    // 0x800973D4: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
        goto L_800973E8;
    // 0x800973D4: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
L_800973D8:
    // 0x800973D8: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x800973DC: bne         $v0, $a0, L_800973BC
    if (ctx->r2 != ctx->r4) {
        // 0x800973E0: nop
    
            goto L_800973BC;
    }
    // 0x800973E0: nop

    // 0x800973E4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_800973E8:
    // 0x800973E8: beql        $a1, $zero, L_80097400
    if (ctx->r5 == 0) {
        // 0x800973EC: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_80097400;
    }
    goto skip_2;
    // 0x800973EC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    skip_2:
    // 0x800973F0: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x800973F4: lw          $a2, 0x10($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X10);
    // 0x800973F8: jal         0x800852D4
    // 0x800973FC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    func_800852D4(rdram, ctx);
        goto after_1;
    // 0x800973FC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    after_1:
L_80097400:
    // 0x80097400: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x80097404: bne         $a0, $s3, L_800973A8
    if (ctx->r4 != ctx->r19) {
        // 0x80097408: addu        $a1, $s4, $zero
        ctx->r5 = ADD32(ctx->r20, 0);
            goto L_800973A8;
    }
    // 0x80097408: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
L_8009740C:
    // 0x8009740C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80097410: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80097414: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80097418: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8009741C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80097420: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80097424: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80097428: jr          $ra
    // 0x8009742C: nop

    return;
    // 0x8009742C: nop

;}
RECOMP_FUNC void func_80097430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097430: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80097434: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80097438: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8009743C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80097440: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80097444: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80097448: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x8009744C: blez        $v0, L_80097498
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80097450: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80097498;
    }
    // 0x80097450: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80097454: addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
L_80097458:
    // 0x80097458: lbu         $v0, 0x9($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X9);
    // 0x8009745C: lhu         $a0, 0x4($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X4);
    // 0x80097460: lhu         $a1, 0x6($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X6);
    // 0x80097464: lbu         $a2, 0xB($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0XB);
    // 0x80097468: lbu         $a3, 0xA($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0XA);
    // 0x8009746C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80097470: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
    // 0x80097474: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80097478: lbu         $v0, 0xC($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XC);
    // 0x8009747C: jal         0x80085560
    // 0x80097480: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_80085560(rdram, ctx);
        goto after_0;
    // 0x80097480: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x80097484: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x80097488: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8009748C: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80097490: bne         $v0, $zero, L_80097458
    if (ctx->r2 != 0) {
        // 0x80097494: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80097458;
    }
    // 0x80097494: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_80097498:
    // 0x80097498: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8009749C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800974A0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800974A4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800974A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800974AC: jr          $ra
    // 0x800974B0: nop

    return;
    // 0x800974B0: nop

;}
RECOMP_FUNC void func_800974B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800974B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800974B8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800974BC: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800974C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800974C4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800974C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800974CC: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x800974D0: blez        $v0, L_800974FC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800974D4: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_800974FC;
    }
    // 0x800974D4: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800974D8: addu        $s1, $s2, $zero
    ctx->r17 = ADD32(ctx->r18, 0);
L_800974DC:
    // 0x800974DC: lhu         $a0, 0x4($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4);
    // 0x800974E0: jal         0x80085770
    // 0x800974E4: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    func_80085770(rdram, ctx);
        goto after_0;
    // 0x800974E4: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    after_0:
    // 0x800974E8: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x800974EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800974F0: slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800974F4: bne         $v0, $zero, L_800974DC
    if (ctx->r2 != 0) {
        // 0x800974F8: nop
    
            goto L_800974DC;
    }
    // 0x800974F8: nop

L_800974FC:
    // 0x800974FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80097500: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80097504: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80097508: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009750C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80097510: jr          $ra
    // 0x80097514: nop

    return;
    // 0x80097514: nop

;}
RECOMP_FUNC void func_80097518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097518: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8009751C: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80097520: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80097524: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80097528: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x8009752C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80097530: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x80097534: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80097538: addu        $s7, $a3, $zero
    ctx->r23 = ADD32(ctx->r7, 0);
    // 0x8009753C: sw          $ra, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r31;
    // 0x80097540: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80097544: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80097548: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8009754C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80097550: beq         $v0, $zero, L_800978B8
    if (ctx->r2 == 0) {
        // 0x80097554: sw          $s0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r16;
            goto L_800978B8;
    }
    // 0x80097554: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80097558: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8009755C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80097560: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80097564: beq         $v1, $v0, L_800978BC
    if (ctx->r3 == ctx->r2) {
        // 0x80097568: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800978BC;
    }
    // 0x80097568: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8009756C: ori         $s5, $zero, 0xFFFF
    ctx->r21 = 0 | 0XFFFF;
    // 0x80097570: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
L_80097574:
    // 0x80097574: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
    // 0x80097578: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x8009757C: bne         $v1, $v0, L_800978A4
    if (ctx->r3 != ctx->r2) {
        // 0x80097580: nop
    
            goto L_800978A4;
    }
    // 0x80097580: nop

    // 0x80097584: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80097588: lh          $v0, 0x2A10($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2A10);
    // 0x8009758C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80097590: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80097594: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80097598: sw          $s1, 0x29D0($at)
    MEM_W(0X29D0, ctx->r1) = ctx->r17;
    // 0x8009759C: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x800975A0: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x800975A4: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x800975A8: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x800975AC: beq         $v1, $s5, L_80097618
    if (ctx->r3 == ctx->r21) {
        // 0x800975B0: nop
    
            goto L_80097618;
    }
    // 0x800975B0: nop

    // 0x800975B4: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
L_800975B8:
    // 0x800975B8: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800975BC: addu        $a1, $s4, $v0
    ctx->r5 = ADD32(ctx->r20, ctx->r2);
    // 0x800975C0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800975C4: beq         $v0, $s6, L_800975F4
    if (ctx->r2 == ctx->r22) {
        // 0x800975C8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800975F4;
    }
    // 0x800975C8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800975CC: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x800975D0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_800975D4:
    // 0x800975D4: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    // 0x800975D8: beq         $v0, $v1, L_800975F4
    if (ctx->r2 == ctx->r3) {
        // 0x800975DC: addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
            goto L_800975F4;
    }
    // 0x800975DC: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x800975E0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800975E4: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800975E8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800975EC: bne         $v0, $a0, L_800975D4
    if (ctx->r2 != ctx->r4) {
        // 0x800975F0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800975D4;
    }
    // 0x800975F0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800975F4:
    // 0x800975F4: beql        $v0, $zero, L_8009760C
    if (ctx->r2 == 0) {
        // 0x800975F8: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_8009760C;
    }
    goto skip_0;
    // 0x800975F8: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    skip_0:
    // 0x800975FC: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x80097600: jal         0x8008588C
    // 0x80097604: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    func_8008588C(rdram, ctx);
        goto after_0;
    // 0x80097604: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    after_0:
    // 0x80097608: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_8009760C:
    // 0x8009760C: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x80097610: bne         $v1, $s2, L_800975B8
    if (ctx->r3 != ctx->r18) {
        // 0x80097614: nop
    
            goto L_800975B8;
    }
    // 0x80097614: nop

L_80097618:
    // 0x80097618: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x8009761C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80097620: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80097624: jal         0x800925F4
    // 0x80097628: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    func_800925F4(rdram, ctx);
        goto after_1;
    // 0x80097628: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    after_1:
    // 0x8009762C: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x80097630: beq         $v1, $s5, L_800976A4
    if (ctx->r3 == ctx->r21) {
        // 0x80097634: addu        $s2, $v0, $zero
        ctx->r18 = ADD32(ctx->r2, 0);
            goto L_800976A4;
    }
    // 0x80097634: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x80097638: addiu       $s3, $sp, 0x20
    ctx->r19 = ADD32(ctx->r29, 0X20);
    // 0x8009763C: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
L_80097640:
    // 0x80097640: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x80097644: beql        $v0, $s5, L_80097680
    if (ctx->r2 == ctx->r21) {
        // 0x80097648: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80097680;
    }
    goto skip_1;
    // 0x80097648: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    skip_1:
    // 0x8009764C: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80097650: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
L_80097654:
    // 0x80097654: bnel        $v0, $v1, L_80097670
    if (ctx->r2 != ctx->r3) {
        // 0x80097658: addiu       $a1, $a1, 0x18
        ctx->r5 = ADD32(ctx->r5, 0X18);
            goto L_80097670;
    }
    goto skip_2;
    // 0x80097658: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    skip_2:
    // 0x8009765C: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x80097660: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80097664: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x80097668: j           L_80097680
    // 0x8009766C: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
        goto L_80097680;
    // 0x8009766C: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
L_80097670:
    // 0x80097670: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x80097674: bne         $v0, $a0, L_80097654
    if (ctx->r2 != ctx->r4) {
        // 0x80097678: nop
    
            goto L_80097654;
    }
    // 0x80097678: nop

    // 0x8009767C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80097680:
    // 0x80097680: beql        $a1, $zero, L_80097698
    if (ctx->r5 == 0) {
        // 0x80097684: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_80097698;
    }
    goto skip_3;
    // 0x80097684: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    skip_3:
    // 0x80097688: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x8009768C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80097690: jal         0x800852D4
    // 0x80097694: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    func_800852D4(rdram, ctx);
        goto after_2;
    // 0x80097694: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    after_2:
L_80097698:
    // 0x80097698: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x8009769C: bne         $v1, $s5, L_80097640
    if (ctx->r3 != ctx->r21) {
        // 0x800976A0: addu        $a1, $s7, $zero
        ctx->r5 = ADD32(ctx->r23, 0);
            goto L_80097640;
    }
    // 0x800976A0: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
L_800976A4:
    // 0x800976A4: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x800976A8: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x800976AC: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x800976B0: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x800976B4: beq         $v1, $s5, L_80097720
    if (ctx->r3 == ctx->r21) {
        // 0x800976B8: nop
    
            goto L_80097720;
    }
    // 0x800976B8: nop

    // 0x800976BC: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
L_800976C0:
    // 0x800976C0: lw          $v0, 0x4($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X4);
    // 0x800976C4: addu        $a1, $s4, $v0
    ctx->r5 = ADD32(ctx->r20, ctx->r2);
    // 0x800976C8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800976CC: beq         $v0, $s6, L_800976FC
    if (ctx->r2 == ctx->r22) {
        // 0x800976D0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800976FC;
    }
    // 0x800976D0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800976D4: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x800976D8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_800976DC:
    // 0x800976DC: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    // 0x800976E0: beq         $v0, $v1, L_800976FC
    if (ctx->r2 == ctx->r3) {
        // 0x800976E4: addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
            goto L_800976FC;
    }
    // 0x800976E4: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x800976E8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800976EC: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800976F0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800976F4: bne         $v0, $a0, L_800976DC
    if (ctx->r2 != ctx->r4) {
        // 0x800976F8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800976DC;
    }
    // 0x800976F8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800976FC:
    // 0x800976FC: beql        $v0, $zero, L_80097714
    if (ctx->r2 == 0) {
        // 0x80097700: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_80097714;
    }
    goto skip_4;
    // 0x80097700: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    skip_4:
    // 0x80097704: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x80097708: jal         0x80085098
    // 0x8009770C: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    func_80085098(rdram, ctx);
        goto after_3;
    // 0x8009770C: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    after_3:
    // 0x80097710: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_80097714:
    // 0x80097714: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x80097718: bne         $v1, $s2, L_800976C0
    if (ctx->r3 != ctx->r18) {
        // 0x8009771C: nop
    
            goto L_800976C0;
    }
    // 0x8009771C: nop

L_80097720:
    // 0x80097720: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x80097724: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80097728: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x8009772C: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x80097730: beq         $v1, $s5, L_8009779C
    if (ctx->r3 == ctx->r21) {
        // 0x80097734: nop
    
            goto L_8009779C;
    }
    // 0x80097734: nop

    // 0x80097738: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
L_8009773C:
    // 0x8009773C: lw          $v0, 0x8($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X8);
    // 0x80097740: addu        $a1, $s4, $v0
    ctx->r5 = ADD32(ctx->r20, ctx->r2);
    // 0x80097744: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80097748: beq         $v0, $s6, L_80097778
    if (ctx->r2 == ctx->r22) {
        // 0x8009774C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80097778;
    }
    // 0x8009774C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80097750: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80097754: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_80097758:
    // 0x80097758: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    // 0x8009775C: beq         $v0, $v1, L_80097778
    if (ctx->r2 == ctx->r3) {
        // 0x80097760: addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
            goto L_80097778;
    }
    // 0x80097760: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x80097764: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80097768: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8009776C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80097770: bne         $v0, $a0, L_80097758
    if (ctx->r2 != ctx->r4) {
        // 0x80097774: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80097758;
    }
    // 0x80097774: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80097778:
    // 0x80097778: beql        $v0, $zero, L_80097790
    if (ctx->r2 == 0) {
        // 0x8009777C: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_80097790;
    }
    goto skip_5;
    // 0x8009777C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    skip_5:
    // 0x80097780: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x80097784: jal         0x80084C08
    // 0x80097788: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    func_80084C08(rdram, ctx);
        goto after_4;
    // 0x80097788: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    after_4:
    // 0x8009778C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_80097790:
    // 0x80097790: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x80097794: bne         $v1, $s2, L_8009773C
    if (ctx->r3 != ctx->r18) {
        // 0x80097798: nop
    
            goto L_8009773C;
    }
    // 0x80097798: nop

L_8009779C:
    // 0x8009779C: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x800977A0: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x800977A4: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x800977A8: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x800977AC: beq         $v1, $s5, L_8009781C
    if (ctx->r3 == ctx->r21) {
        // 0x800977B0: nop
    
            goto L_8009781C;
    }
    // 0x800977B0: nop

    // 0x800977B4: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
L_800977B8:
    // 0x800977B8: lw          $v0, 0xC($s4)
    ctx->r2 = MEM_W(ctx->r20, 0XC);
    // 0x800977BC: addu        $a1, $s4, $v0
    ctx->r5 = ADD32(ctx->r20, ctx->r2);
    // 0x800977C0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800977C4: beq         $v0, $s6, L_800977F4
    if (ctx->r2 == ctx->r22) {
        // 0x800977C8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800977F4;
    }
    // 0x800977C8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800977CC: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x800977D0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_800977D4:
    // 0x800977D4: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    // 0x800977D8: beq         $v0, $v1, L_800977F4
    if (ctx->r2 == ctx->r3) {
        // 0x800977DC: addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
            goto L_800977F4;
    }
    // 0x800977DC: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x800977E0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800977E4: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800977E8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800977EC: bne         $v0, $a0, L_800977D4
    if (ctx->r2 != ctx->r4) {
        // 0x800977F0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800977D4;
    }
    // 0x800977F0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800977F4:
    // 0x800977F4: beql        $v0, $zero, L_80097810
    if (ctx->r2 == 0) {
        // 0x800977F8: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_80097810;
    }
    goto skip_6;
    // 0x800977F8: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    skip_6:
    // 0x800977FC: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x80097800: lhu         $a2, 0xA($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0XA);
    // 0x80097804: jal         0x80084E44
    // 0x80097808: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
    func_80084E44(rdram, ctx);
        goto after_5;
    // 0x80097808: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
    after_5:
    // 0x8009780C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_80097810:
    // 0x80097810: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x80097814: bne         $v1, $s2, L_800977B8
    if (ctx->r3 != ctx->r18) {
        // 0x80097818: nop
    
            goto L_800977B8;
    }
    // 0x80097818: nop

L_8009781C:
    // 0x8009781C: lhu         $v1, 0x6($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X6);
    // 0x80097820: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80097824: bne         $v1, $v0, L_80097888
    if (ctx->r3 != ctx->r2) {
        // 0x80097828: nop
    
            goto L_80097888;
    }
    // 0x80097828: nop

    // 0x8009782C: lw          $v0, 0x1C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1C);
    // 0x80097830: addu        $s2, $v0, $s1
    ctx->r18 = ADD32(ctx->r2, ctx->r17);
    // 0x80097834: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80097838: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x8009783C: blez        $v0, L_80097888
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80097840: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80097888;
    }
    // 0x80097840: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80097844: addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
L_80097848:
    // 0x80097848: lbu         $v0, 0x9($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X9);
    // 0x8009784C: lhu         $a0, 0x4($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X4);
    // 0x80097850: lhu         $a1, 0x6($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X6);
    // 0x80097854: lbu         $a2, 0xB($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0XB);
    // 0x80097858: lbu         $a3, 0xA($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0XA);
    // 0x8009785C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80097860: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
    // 0x80097864: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80097868: lbu         $v0, 0xC($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XC);
    // 0x8009786C: jal         0x80085560
    // 0x80097870: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_80085560(rdram, ctx);
        goto after_6;
    // 0x80097870: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_6:
    // 0x80097874: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x80097878: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8009787C: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80097880: bne         $v0, $zero, L_80097848
    if (ctx->r2 != 0) {
        // 0x80097884: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80097848;
    }
    // 0x80097884: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_80097888:
    // 0x80097888: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8009788C: lhu         $v1, 0x2A10($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X2A10);
    // 0x80097890: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80097894: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80097898: sh          $v1, 0x2A10($at)
    MEM_H(0X2A10, ctx->r1) = ctx->r3;
    // 0x8009789C: j           L_800978BC
    // 0x800978A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800978BC;
    // 0x800978A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800978A4:
    // 0x800978A4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800978A8: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x800978AC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800978B0: bne         $v0, $s6, L_80097574
    if (ctx->r2 != ctx->r22) {
        // 0x800978B4: nop
    
            goto L_80097574;
    }
    // 0x800978B4: nop

L_800978B8:
    // 0x800978B8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800978BC:
    // 0x800978BC: lw          $ra, 0x50($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X50);
    // 0x800978C0: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x800978C4: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x800978C8: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x800978CC: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800978D0: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800978D4: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800978D8: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800978DC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800978E0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800978E4: jr          $ra
    // 0x800978E8: nop

    return;
    // 0x800978E8: nop

;}
RECOMP_FUNC void func_800978EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800978EC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800978F0: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x800978F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800978F8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800978FC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80097900: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80097904: beq         $v0, $zero, L_80097AA8
    if (ctx->r2 == 0) {
        // 0x80097908: sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
            goto L_80097AA8;
    }
    // 0x80097908: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8009790C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80097910: lh          $v0, 0x2A10($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2A10);
    // 0x80097914: beq         $v0, $zero, L_80097AA8
    if (ctx->r2 == 0) {
        // 0x80097918: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_80097AA8;
    }
    // 0x80097918: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8009791C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80097920: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80097924: sra         $v0, $v0, 14
    ctx->r2 = S32(SIGNED(ctx->r2) >> 14);
    // 0x80097928: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009792C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80097930: lw          $s1, 0x29D0($at)
    ctx->r17 = MEM_W(ctx->r1, 0X29D0);
    // 0x80097934: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x80097938: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009793C: sh          $v1, 0x2A10($at)
    MEM_H(0X2A10, ctx->r1) = ctx->r3;
    // 0x80097940: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80097944: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x80097948: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x8009794C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80097950: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x80097954: beq         $v1, $v0, L_80097974
    if (ctx->r3 == ctx->r2) {
        // 0x80097958: nop
    
            goto L_80097974;
    }
    // 0x80097958: nop

    // 0x8009795C: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
L_80097960:
    // 0x80097960: jal         0x80085A94
    // 0x80097964: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    func_80085A94(rdram, ctx);
        goto after_0;
    // 0x80097964: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    after_0:
    // 0x80097968: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x8009796C: bne         $a0, $s2, L_80097960
    if (ctx->r4 != ctx->r18) {
        // 0x80097970: nop
    
            goto L_80097960;
    }
    // 0x80097970: nop

L_80097974:
    // 0x80097974: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x80097978: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x8009797C: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x80097980: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x80097984: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80097988: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x8009798C: beq         $v1, $v0, L_800979AC
    if (ctx->r3 == ctx->r2) {
        // 0x80097990: nop
    
            goto L_800979AC;
    }
    // 0x80097990: nop

    // 0x80097994: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
L_80097998:
    // 0x80097998: jal         0x8008545C
    // 0x8009799C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    func_8008545C(rdram, ctx);
        goto after_1;
    // 0x8009799C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    after_1:
    // 0x800979A0: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x800979A4: bne         $a0, $s2, L_80097998
    if (ctx->r4 != ctx->r18) {
        // 0x800979A8: nop
    
            goto L_80097998;
    }
    // 0x800979A8: nop

L_800979AC:
    // 0x800979AC: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x800979B0: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x800979B4: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x800979B8: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x800979BC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800979C0: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x800979C4: beq         $v1, $v0, L_800979E4
    if (ctx->r3 == ctx->r2) {
        // 0x800979C8: nop
    
            goto L_800979E4;
    }
    // 0x800979C8: nop

    // 0x800979CC: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
L_800979D0:
    // 0x800979D0: jal         0x800851E4
    // 0x800979D4: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    func_800851E4(rdram, ctx);
        goto after_2;
    // 0x800979D4: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    after_2:
    // 0x800979D8: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x800979DC: bne         $a0, $s2, L_800979D0
    if (ctx->r4 != ctx->r18) {
        // 0x800979E0: nop
    
            goto L_800979D0;
    }
    // 0x800979E0: nop

L_800979E4:
    // 0x800979E4: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x800979E8: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x800979EC: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x800979F0: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x800979F4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800979F8: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x800979FC: beq         $v1, $v0, L_80097A1C
    if (ctx->r3 == ctx->r2) {
        // 0x80097A00: nop
    
            goto L_80097A1C;
    }
    // 0x80097A00: nop

    // 0x80097A04: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
L_80097A08:
    // 0x80097A08: jal         0x80084D54
    // 0x80097A0C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    func_80084D54(rdram, ctx);
        goto after_3;
    // 0x80097A0C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    after_3:
    // 0x80097A10: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x80097A14: bne         $a0, $s2, L_80097A08
    if (ctx->r4 != ctx->r18) {
        // 0x80097A18: nop
    
            goto L_80097A08;
    }
    // 0x80097A18: nop

L_80097A1C:
    // 0x80097A1C: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x80097A20: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80097A24: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x80097A28: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x80097A2C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80097A30: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x80097A34: beq         $v1, $v0, L_80097A54
    if (ctx->r3 == ctx->r2) {
        // 0x80097A38: nop
    
            goto L_80097A54;
    }
    // 0x80097A38: nop

    // 0x80097A3C: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
L_80097A40:
    // 0x80097A40: jal         0x80084FA8
    // 0x80097A44: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    func_80084FA8(rdram, ctx);
        goto after_4;
    // 0x80097A44: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    after_4:
    // 0x80097A48: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x80097A4C: bne         $a0, $s2, L_80097A40
    if (ctx->r4 != ctx->r18) {
        // 0x80097A50: nop
    
            goto L_80097A40;
    }
    // 0x80097A50: nop

L_80097A54:
    // 0x80097A54: lhu         $v1, 0x6($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X6);
    // 0x80097A58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80097A5C: bne         $v1, $v0, L_80097AAC
    if (ctx->r3 != ctx->r2) {
        // 0x80097A60: nop
    
            goto L_80097AAC;
    }
    // 0x80097A60: nop

    // 0x80097A64: lw          $v0, 0x1C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1C);
    // 0x80097A68: addu        $s2, $v0, $s1
    ctx->r18 = ADD32(ctx->r2, ctx->r17);
    // 0x80097A6C: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80097A70: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x80097A74: blez        $v0, L_80097AA0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80097A78: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_80097AA0;
    }
    // 0x80097A78: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80097A7C: addu        $s1, $s2, $zero
    ctx->r17 = ADD32(ctx->r18, 0);
L_80097A80:
    // 0x80097A80: lhu         $a0, 0x4($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4);
    // 0x80097A84: jal         0x80085770
    // 0x80097A88: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    func_80085770(rdram, ctx);
        goto after_5;
    // 0x80097A88: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    after_5:
    // 0x80097A8C: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x80097A90: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80097A94: slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80097A98: bne         $v0, $zero, L_80097A80
    if (ctx->r2 != 0) {
        // 0x80097A9C: nop
    
            goto L_80097A80;
    }
    // 0x80097A9C: nop

L_80097AA0:
    // 0x80097AA0: j           L_80097AAC
    // 0x80097AA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80097AAC;
    // 0x80097AA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80097AA8:
    // 0x80097AA8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80097AAC:
    // 0x80097AAC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80097AB0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80097AB4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80097AB8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80097ABC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80097AC0: jr          $ra
    // 0x80097AC4: nop

    return;
    // 0x80097AC4: nop

;}
RECOMP_FUNC void func_80097AC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097AC8: jr          $ra
    // 0x80097ACC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80097ACC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_80097AD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097AD0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80097AD4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80097AD8: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x80097ADC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80097AE0: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80097AE4: lbu         $a2, 0x4B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X4B);
    // 0x80097AE8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80097AEC: addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // 0x80097AF0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80097AF4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80097AF8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80097AFC: beq         $v0, $zero, L_80097C04
    if (ctx->r2 == 0) {
        // 0x80097B00: sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
            goto L_80097C04;
    }
    // 0x80097B00: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80097B04: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80097B08: lh          $v0, 0x2A10($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2A10);
    // 0x80097B0C: blez        $v0, L_80097C04
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80097B10: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80097C04;
    }
    // 0x80097B10: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80097B14: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80097B18: andi        $a3, $a1, 0xFFFF
    ctx->r7 = ctx->r5 & 0XFFFF;
    // 0x80097B1C: andi        $t0, $a2, 0xFF
    ctx->r8 = ctx->r6 & 0XFF;
    // 0x80097B20: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80097B24:
    // 0x80097B24: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80097B28: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x80097B2C: lw          $a1, 0x29D0($at)
    ctx->r5 = MEM_W(ctx->r1, 0X29D0);
    // 0x80097B30: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    // 0x80097B34: bnel        $v0, $a0, L_80097BF0
    if (ctx->r2 != ctx->r4) {
        // 0x80097B38: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80097BF0;
    }
    goto skip_0;
    // 0x80097B38: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x80097B3C: lhu         $v0, 0x6($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X6);
    // 0x80097B40: bne         $v0, $zero, L_80097C08
    if (ctx->r2 != 0) {
        // 0x80097B44: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80097C08;
    }
    // 0x80097B44: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80097B48: lw          $v0, 0x24($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X24);
    // 0x80097B4C: lw          $v1, 0x20($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X20);
    // 0x80097B50: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80097B54: addu        $s0, $a1, $v0
    ctx->r16 = ADD32(ctx->r5, ctx->r2);
    // 0x80097B58: lw          $v0, 0x1C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1C);
    // 0x80097B5C: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x80097B60: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80097B64: addu        $s2, $a1, $v1
    ctx->r18 = ADD32(ctx->r5, ctx->r3);
    // 0x80097B68: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80097B6C: addu        $s1, $a1, $v0
    ctx->r17 = ADD32(ctx->r5, ctx->r2);
    // 0x80097B70: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x80097B74: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80097B78: beql        $v1, $v0, L_80097C08
    if (ctx->r3 == ctx->r2) {
        // 0x80097B7C: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80097C08;
    }
    goto skip_1;
    // 0x80097B7C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_1:
L_80097B80:
    // 0x80097B80: bnel        $a0, $a3, L_80097BDC
    if (ctx->r4 != ctx->r7) {
        // 0x80097B84: addiu       $s0, $s0, 0x84
        ctx->r16 = ADD32(ctx->r16, 0X84);
            goto L_80097BDC;
    }
    goto skip_2;
    // 0x80097B84: addiu       $s0, $s0, 0x84
    ctx->r16 = ADD32(ctx->r16, 0X84);
    skip_2:
    // 0x80097B88: beq         $t0, $zero, L_80097BAC
    if (ctx->r8 == 0) {
        // 0x80097B8C: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80097BAC;
    }
    // 0x80097B8C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80097B90: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80097B94: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80097B98: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80097B9C: jal         0x80094350
    // 0x80097BA0: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    func_80094350(rdram, ctx);
        goto after_0;
    // 0x80097BA0: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    after_0:
    // 0x80097BA4: j           L_80097BD4
    // 0x80097BA8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
        goto L_80097BD4;
    // 0x80097BA8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_80097BAC:
    // 0x80097BAC: jal         0x80092010
    // 0x80097BB0: nop

    func_80092010(rdram, ctx);
        goto after_1;
    // 0x80097BB0: nop

    after_1:
    // 0x80097BB4: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80097BB8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80097BBC: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80097BC0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80097BC4: jal         0x80094350
    // 0x80097BC8: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    func_80094350(rdram, ctx);
        goto after_2;
    // 0x80097BC8: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    after_2:
    // 0x80097BCC: jal         0x8009205C
    // 0x80097BD0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    func_8009205C(rdram, ctx);
        goto after_3;
    // 0x80097BD0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_3:
L_80097BD4:
    // 0x80097BD4: j           L_80097C08
    // 0x80097BD8: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
        goto L_80097C08;
    // 0x80097BD8: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80097BDC:
    // 0x80097BDC: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x80097BE0: bne         $a0, $v0, L_80097B80
    if (ctx->r4 != ctx->r2) {
        // 0x80097BE4: nop
    
            goto L_80097B80;
    }
    // 0x80097BE4: nop

    // 0x80097BE8: j           L_80097C08
    // 0x80097BEC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80097C08;
    // 0x80097BEC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80097BF0:
    // 0x80097BF0: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80097BF4: lh          $v0, 0x2A10($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2A10);
    // 0x80097BF8: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80097BFC: bne         $v0, $zero, L_80097B24
    if (ctx->r2 != 0) {
        // 0x80097C00: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80097B24;
    }
    // 0x80097C00: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_80097C04:
    // 0x80097C04: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80097C08:
    // 0x80097C08: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80097C0C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80097C10: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80097C14: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80097C18: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80097C1C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80097C20: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80097C24: jr          $ra
    // 0x80097C28: nop

    return;
    // 0x80097C28: nop

;}
RECOMP_FUNC void func_80097C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097C2C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80097C30: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80097C34: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80097C38: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80097C3C: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x80097C40: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80097C44: addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // 0x80097C48: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80097C4C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80097C50: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80097C54: beq         $v0, $zero, L_80097D30
    if (ctx->r2 == 0) {
        // 0x80097C58: sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
            goto L_80097D30;
    }
    // 0x80097C58: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80097C5C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80097C60: lh          $v0, 0x2A10($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2A10);
    // 0x80097C64: blez        $v0, L_80097D30
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80097C68: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80097D30;
    }
    // 0x80097C68: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80097C6C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80097C70: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x80097C74: andi        $a3, $a1, 0xFFFF
    ctx->r7 = ctx->r5 & 0XFFFF;
    // 0x80097C78: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80097C7C:
    // 0x80097C7C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80097C80: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x80097C84: lw          $a1, 0x29D0($at)
    ctx->r5 = MEM_W(ctx->r1, 0X29D0);
    // 0x80097C88: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    // 0x80097C8C: bnel        $v0, $a0, L_80097D1C
    if (ctx->r2 != ctx->r4) {
        // 0x80097C90: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80097D1C;
    }
    goto skip_0;
    // 0x80097C90: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x80097C94: lhu         $v0, 0x6($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X6);
    // 0x80097C98: bne         $v0, $zero, L_80097D34
    if (ctx->r2 != 0) {
        // 0x80097C9C: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80097D34;
    }
    // 0x80097C9C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80097CA0: lw          $v0, 0x24($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X24);
    // 0x80097CA4: lw          $v1, 0x20($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X20);
    // 0x80097CA8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80097CAC: addu        $s0, $a1, $v0
    ctx->r16 = ADD32(ctx->r5, ctx->r2);
    // 0x80097CB0: lw          $v0, 0x1C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1C);
    // 0x80097CB4: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x80097CB8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80097CBC: addu        $s1, $a1, $v1
    ctx->r17 = ADD32(ctx->r5, ctx->r3);
    // 0x80097CC0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80097CC4: beq         $a0, $t0, L_80097D30
    if (ctx->r4 == ctx->r8) {
        // 0x80097CC8: addu        $s2, $a1, $v0
        ctx->r18 = ADD32(ctx->r5, ctx->r2);
            goto L_80097D30;
    }
    // 0x80097CC8: addu        $s2, $a1, $v0
    ctx->r18 = ADD32(ctx->r5, ctx->r2);
    // 0x80097CCC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80097CD0:
    // 0x80097CD0: bnel        $a0, $a3, L_80097D08
    if (ctx->r4 != ctx->r7) {
        // 0x80097CD4: addiu       $s0, $s0, 0x84
        ctx->r16 = ADD32(ctx->r16, 0X84);
            goto L_80097D08;
    }
    goto skip_1;
    // 0x80097CD4: addiu       $s0, $s0, 0x84
    ctx->r16 = ADD32(ctx->r16, 0X84);
    skip_1:
    // 0x80097CD8: jal         0x80092010
    // 0x80097CDC: nop

    func_80092010(rdram, ctx);
        goto after_0;
    // 0x80097CDC: nop

    after_0:
    // 0x80097CE0: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80097CE4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80097CE8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80097CEC: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80097CF0: jal         0x80094350
    // 0x80097CF4: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    func_80094350(rdram, ctx);
        goto after_1;
    // 0x80097CF4: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    after_1:
    // 0x80097CF8: jal         0x8009205C
    // 0x80097CFC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    func_8009205C(rdram, ctx);
        goto after_2;
    // 0x80097CFC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_2:
    // 0x80097D00: j           L_80097D34
    // 0x80097D04: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
        goto L_80097D34;
    // 0x80097D04: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80097D08:
    // 0x80097D08: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x80097D0C: bne         $a0, $v0, L_80097CD0
    if (ctx->r4 != ctx->r2) {
        // 0x80097D10: nop
    
            goto L_80097CD0;
    }
    // 0x80097D10: nop

    // 0x80097D14: j           L_80097D34
    // 0x80097D18: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80097D34;
    // 0x80097D18: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80097D1C:
    // 0x80097D1C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80097D20: lh          $v0, 0x2A10($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2A10);
    // 0x80097D24: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80097D28: bne         $v0, $zero, L_80097C7C
    if (ctx->r2 != 0) {
        // 0x80097D2C: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80097C7C;
    }
    // 0x80097D2C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_80097D30:
    // 0x80097D30: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80097D34:
    // 0x80097D34: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80097D38: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80097D3C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80097D40: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80097D44: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80097D48: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80097D4C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80097D50: jr          $ra
    // 0x80097D54: nop

    return;
    // 0x80097D54: nop

;}
RECOMP_FUNC void fake_func_80097D58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80097D60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097D60: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80097D64: lbu         $v0, 0x1AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1AD0);
    // 0x80097D68: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80097D6C: blez        $v0, L_80097D9C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80097D70: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80097D9C;
    }
    // 0x80097D70: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80097D74: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80097D78:
    // 0x80097D78: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80097D7C: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80097D80: sb          $zero, 0x2A20($at)
    MEM_B(0X2A20, ctx->r1) = 0;
    // 0x80097D84: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80097D88: lbu         $v0, 0x1AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1AD0);
    // 0x80097D8C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80097D90: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80097D94: bne         $v0, $zero, L_80097D78
    if (ctx->r2 != 0) {
        // 0x80097D98: addiu       $a0, $a0, 0x18
        ctx->r4 = ADD32(ctx->r4, 0X18);
            goto L_80097D78;
    }
    // 0x80097D98: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
L_80097D9C:
    // 0x80097D9C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80097DA0: jr          $ra
    // 0x80097DA4: nop

    return;
    // 0x80097DA4: nop

;}
RECOMP_FUNC void func_80097DA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097DA8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80097DAC: lbu         $v0, 0x1AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1AD0);
    // 0x80097DB0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80097DB4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80097DB8: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80097DBC: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80097DC0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80097DC4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80097DC8: blez        $v0, L_80097F34
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80097DCC: sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
            goto L_80097F34;
    }
    // 0x80097DCC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80097DD0: lui         $s2, 0x8015
    ctx->r18 = S32(0X8015 << 16);
    // 0x80097DD4: addiu       $s2, $s2, 0x2A30
    ctx->r18 = ADD32(ctx->r18, 0X2A30);
    // 0x80097DD8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_80097DDC:
    // 0x80097DDC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80097DE0: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80097DE4: lbu         $v1, 0x2A20($at)
    ctx->r3 = MEM_BU(ctx->r1, 0X2A20);
    // 0x80097DE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80097DEC: bnel        $v1, $v0, L_80097F1C
    if (ctx->r3 != ctx->r2) {
        // 0x80097DF0: addiu       $s2, $s2, 0x18
        ctx->r18 = ADD32(ctx->r18, 0X18);
            goto L_80097F1C;
    }
    goto skip_0;
    // 0x80097DF0: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    skip_0:
    // 0x80097DF4: jal         0x80092564
    // 0x80097DF8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_80092564(rdram, ctx);
        goto after_0;
    // 0x80097DF8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_0:
    // 0x80097DFC: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80097E00: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80097E04: beq         $t0, $s1, L_80097F14
    if (ctx->r8 == ctx->r17) {
        // 0x80097E08: sltu        $v0, $t0, $s1
        ctx->r2 = ctx->r8 < ctx->r17 ? 1 : 0;
            goto L_80097F14;
    }
    // 0x80097E08: sltu        $v0, $t0, $s1
    ctx->r2 = ctx->r8 < ctx->r17 ? 1 : 0;
    // 0x80097E0C: beq         $v0, $zero, L_80097E7C
    if (ctx->r2 == 0) {
        // 0x80097E10: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_80097E7C;
    }
    // 0x80097E10: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80097E14: subu        $a1, $s1, $t0
    ctx->r5 = SUB32(ctx->r17, ctx->r8);
    // 0x80097E18: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80097E1C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80097E20: lw          $v1, 0x2A28($at)
    ctx->r3 = MEM_W(ctx->r1, 0X2A28);
    // 0x80097E24: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80097E28: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80097E2C: lw          $v0, 0x2A34($at)
    ctx->r2 = MEM_W(ctx->r1, 0X2A34);
    // 0x80097E30: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80097E34: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80097E38: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80097E3C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80097E40: lw          $v0, 0x2A24($at)
    ctx->r2 = MEM_W(ctx->r1, 0X2A24);
    // 0x80097E44: sll         $a0, $t0, 1
    ctx->r4 = S32(ctx->r8 << 1);
    // 0x80097E48: jalr        $v0
    // 0x80097E4C: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x80097E4C: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    after_1:
    // 0x80097E50: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80097E54: beql        $v0, $zero, L_80097F18
    if (ctx->r2 == 0) {
        // 0x80097E58: sw          $s1, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->r17;
            goto L_80097F18;
    }
    goto skip_1;
    // 0x80097E58: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
    skip_1:
    // 0x80097E5C: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x80097E60: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80097E64: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80097E68: lw          $v0, 0x2A28($at)
    ctx->r2 = MEM_W(ctx->r1, 0X2A28);
    // 0x80097E6C: sll         $a0, $a1, 1
    ctx->r4 = S32(ctx->r5 << 1);
    // 0x80097E70: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // 0x80097E74: j           L_80097F0C
    // 0x80097E78: subu        $a1, $s1, $a1
    ctx->r5 = SUB32(ctx->r17, ctx->r5);
        goto L_80097F0C;
    // 0x80097E78: subu        $a1, $s1, $a1
    ctx->r5 = SUB32(ctx->r17, ctx->r5);
L_80097E7C:
    // 0x80097E7C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80097E80: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80097E84: lw          $a2, 0x2A28($at)
    ctx->r6 = MEM_W(ctx->r1, 0X2A28);
    // 0x80097E88: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80097E8C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80097E90: lw          $a1, 0x2A2C($at)
    ctx->r5 = MEM_W(ctx->r1, 0X2A2C);
    // 0x80097E94: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80097E98: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80097E9C: lw          $v0, 0x2A34($at)
    ctx->r2 = MEM_W(ctx->r1, 0X2A34);
    // 0x80097EA0: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x80097EA4: sll         $a0, $t0, 1
    ctx->r4 = S32(ctx->r8 << 1);
    // 0x80097EA8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80097EAC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80097EB0: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80097EB4: lw          $v0, 0x2A24($at)
    ctx->r2 = MEM_W(ctx->r1, 0X2A24);
    // 0x80097EB8: addu        $a0, $a2, $a0
    ctx->r4 = ADD32(ctx->r6, ctx->r4);
    // 0x80097EBC: jalr        $v0
    // 0x80097EC0: subu        $a1, $a1, $t0
    ctx->r5 = SUB32(ctx->r5, ctx->r8);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x80097EC0: subu        $a1, $a1, $t0
    ctx->r5 = SUB32(ctx->r5, ctx->r8);
    after_2:
    // 0x80097EC4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80097EC8: beql        $v0, $zero, L_80097F18
    if (ctx->r2 == 0) {
        // 0x80097ECC: sw          $s1, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->r17;
            goto L_80097F18;
    }
    goto skip_2;
    // 0x80097ECC: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
    skip_2:
    // 0x80097ED0: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80097ED4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80097ED8: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80097EDC: lw          $v0, 0x2A28($at)
    ctx->r2 = MEM_W(ctx->r1, 0X2A28);
    // 0x80097EE0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80097EE4: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80097EE8: lw          $a1, 0x2A2C($at)
    ctx->r5 = MEM_W(ctx->r1, 0X2A2C);
    // 0x80097EEC: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
    // 0x80097EF0: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // 0x80097EF4: jal         0x80092588
    // 0x80097EF8: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    func_80092588(rdram, ctx);
        goto after_3;
    // 0x80097EF8: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    after_3:
    // 0x80097EFC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80097F00: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80097F04: lw          $a0, 0x2A28($at)
    ctx->r4 = MEM_W(ctx->r1, 0X2A28);
    // 0x80097F08: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
L_80097F0C:
    // 0x80097F0C: jal         0x80092588
    // 0x80097F10: nop

    func_80092588(rdram, ctx);
        goto after_4;
    // 0x80097F10: nop

    after_4:
L_80097F14:
    // 0x80097F14: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
L_80097F18:
    // 0x80097F18: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
L_80097F1C:
    // 0x80097F1C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80097F20: lbu         $v0, 0x1AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1AD0);
    // 0x80097F24: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80097F28: slt         $v0, $s3, $v0
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80097F2C: bne         $v0, $zero, L_80097DDC
    if (ctx->r2 != 0) {
        // 0x80097F30: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_80097DDC;
    }
    // 0x80097F30: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
L_80097F34:
    // 0x80097F34: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80097F38: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80097F3C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80097F40: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80097F44: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80097F48: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80097F4C: jr          $ra
    // 0x80097F50: nop

    return;
    // 0x80097F50: nop

;}
RECOMP_FUNC void func_80097F54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097F54: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80097F58: lbu         $v0, 0x1AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1AD0);
    // 0x80097F5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80097F60: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80097F64: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80097F68: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80097F6C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80097F70: blez        $v0, L_80097FCC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80097F74: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80097FCC;
    }
    // 0x80097F74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80097F78: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80097F7C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_80097F80:
    // 0x80097F80: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80097F84: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80097F88: lbu         $v0, 0x2A20($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X2A20);
    // 0x80097F8C: bne         $v0, $s2, L_80097FB4
    if (ctx->r2 != ctx->r18) {
        // 0x80097F90: nop
    
            goto L_80097FB4;
    }
    // 0x80097F90: nop

    // 0x80097F94: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80097F98: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80097F9C: lw          $a0, 0x2A28($at)
    ctx->r4 = MEM_W(ctx->r1, 0X2A28);
    // 0x80097FA0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80097FA4: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80097FA8: lw          $a1, 0x2A2C($at)
    ctx->r5 = MEM_W(ctx->r1, 0X2A2C);
    // 0x80097FAC: jal         0x800925A8
    // 0x80097FB0: nop

    func_800925A8(rdram, ctx);
        goto after_0;
    // 0x80097FB0: nop

    after_0:
L_80097FB4:
    // 0x80097FB4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80097FB8: lbu         $v0, 0x1AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1AD0);
    // 0x80097FBC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80097FC0: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80097FC4: bne         $v0, $zero, L_80097F80
    if (ctx->r2 != 0) {
        // 0x80097FC8: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_80097F80;
    }
    // 0x80097FC8: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
L_80097FCC:
    // 0x80097FCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80097FD0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80097FD4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80097FD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80097FDC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80097FE0: jr          $ra
    // 0x80097FE4: nop

    return;
    // 0x80097FE4: nop

;}
RECOMP_FUNC void func_80097FE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097FE8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80097FEC: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80097FF0: lw          $s4, 0x88($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X88);
    // 0x80097FF4: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80097FF8: lw          $s6, 0x8C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X8C);
    // 0x80097FFC: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80098000: lbu         $fp, 0x7B($sp)
    ctx->r30 = MEM_BU(ctx->r29, 0X7B);
    // 0x80098004: lbu         $t0, 0x7F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X7F);
    // 0x80098008: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8009800C: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80098010: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80098014: lbu         $s7, 0x83($sp)
    ctx->r23 = MEM_BU(ctx->r29, 0X83);
    // 0x80098018: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8009801C: lbu         $s5, 0x87($sp)
    ctx->r21 = MEM_BU(ctx->r29, 0X87);
    // 0x80098020: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80098024: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x80098028: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8009802C: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x80098030: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80098034: addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    // 0x80098038: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8009803C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80098040: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80098044: beq         $v0, $zero, L_800981AC
    if (ctx->r2 == 0) {
        // 0x80098048: sb          $t0, 0x3F($sp)
        MEM_B(0X3F, ctx->r29) = ctx->r8;
            goto L_800981AC;
    }
    // 0x80098048: sb          $t0, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r8;
    // 0x8009804C: jal         0x80092010
    // 0x80098050: nop

    func_80092010(rdram, ctx);
        goto after_0;
    // 0x80098050: nop

    after_0:
    // 0x80098054: jal         0x80086914
    // 0x80098058: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    func_80086914(rdram, ctx);
        goto after_1;
    // 0x80098058: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_1:
    // 0x8009805C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80098060: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80098064: beq         $s0, $v0, L_8009819C
    if (ctx->r16 == ctx->r2) {
        // 0x80098068: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8009819C;
    }
    // 0x80098068: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8009806C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80098070: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80098074: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x80098078: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8009807C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80098080: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80098084: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80098088: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8009808C: sw          $s3, 0x2A28($at)
    MEM_W(0X2A28, ctx->r1) = ctx->r19;
    // 0x80098090: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80098094: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80098098: sw          $s1, 0x2A2C($at)
    MEM_W(0X2A2C, ctx->r1) = ctx->r17;
    // 0x8009809C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800980A0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800980A4: sw          $s4, 0x2A24($at)
    MEM_W(0X2A24, ctx->r1) = ctx->r20;
    // 0x800980A8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800980AC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800980B0: sb          $v1, 0x2A20($at)
    MEM_B(0X2A20, ctx->r1) = ctx->r3;
    // 0x800980B4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800980B8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800980BC: sw          $zero, 0x2A30($at)
    MEM_W(0X2A30, ctx->r1) = 0;
    // 0x800980C0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800980C4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800980C8: sw          $s6, 0x2A34($at)
    MEM_W(0X2A34, ctx->r1) = ctx->r22;
    // 0x800980CC: lui         $v0, 0x40
    ctx->r2 = S32(0X40 << 16);
    // 0x800980D0: or          $v0, $s2, $v0
    ctx->r2 = ctx->r18 | ctx->r2;
    // 0x800980D4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800980D8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800980DC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800980E0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800980E4: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800980E8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800980EC: jal         0x80092128
    // 0x800980F0: sb          $zero, 0x30($sp)
    MEM_B(0X30, ctx->r29) = 0;
    func_80092128(rdram, ctx);
        goto after_2;
    // 0x800980F0: sb          $zero, 0x30($sp)
    MEM_B(0X30, ctx->r29) = 0;
    after_2:
    // 0x800980F4: mtc1        $s2, $f2
    ctx->f2.u32l = ctx->r18;
    // 0x800980F8: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x800980FC: bgezl       $s2, L_80098114
    if (SIGNED(ctx->r18) >= 0) {
        // 0x80098100: cvt.s.d     $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
            goto L_80098114;
    }
    goto skip_0;
    // 0x80098100: cvt.s.d     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
    skip_0:
    // 0x80098104: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80098108: ldc1        $f0, -0x2190($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2190);
    // 0x8009810C: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
    // 0x80098110: cvt.s.d     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
L_80098114:
    // 0x80098114: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80098118: lwc1        $f2, 0x40C0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X40C0);
    // 0x8009811C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80098120: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80098124: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80098128: lwc1        $f2, -0x2188($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2188);
    // 0x8009812C: mul.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80098130: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80098134: lwc1        $f0, -0x2184($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2184);
    // 0x80098138: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8009813C: nop

    // 0x80098140: bc1tl       L_80098158
    if (c1cs) {
        // 0x80098144: sub.s       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_80098158;
    }
    goto skip_1;
    // 0x80098144: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    skip_1:
    // 0x80098148: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8009814C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80098150: j           L_8009816C
    // 0x80098154: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
        goto L_8009816C;
    // 0x80098154: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80098158:
    // 0x80098158: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8009815C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80098160: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80098164: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x80098168: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_8009816C:
    // 0x8009816C: jal         0x80092390
    // 0x80098170: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    func_80092390(rdram, ctx);
        goto after_3;
    // 0x80098170: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_3:
    // 0x80098174: sll         $v0, $s5, 16
    ctx->r2 = S32(ctx->r21 << 16);
    // 0x80098178: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8009817C: lbu         $t0, 0x3F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3F);
    // 0x80098180: sll         $a1, $fp, 16
    ctx->r5 = S32(ctx->r30 << 16);
    // 0x80098184: sll         $a3, $s7, 16
    ctx->r7 = S32(ctx->r23 << 16);
    // 0x80098188: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8009818C: jal         0x800923E4
    // 0x80098190: sll         $a2, $t0, 16
    ctx->r6 = S32(ctx->r8 << 16);
    func_800923E4(rdram, ctx);
        goto after_4;
    // 0x80098190: sll         $a2, $t0, 16
    ctx->r6 = S32(ctx->r8 << 16);
    after_4:
    // 0x80098194: jal         0x8009231C
    // 0x80098198: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8009231C(rdram, ctx);
        goto after_5;
    // 0x80098198: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
L_8009819C:
    // 0x8009819C: jal         0x8009205C
    // 0x800981A0: nop

    func_8009205C(rdram, ctx);
        goto after_6;
    // 0x800981A0: nop

    after_6:
    // 0x800981A4: j           L_800981B0
    // 0x800981A8: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
        goto L_800981B0;
    // 0x800981A8: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_800981AC:
    // 0x800981AC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800981B0:
    // 0x800981B0: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800981B4: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x800981B8: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x800981BC: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800981C0: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800981C4: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800981C8: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800981CC: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800981D0: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800981D4: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800981D8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800981DC: jr          $ra
    // 0x800981E0: nop

    return;
    // 0x800981E0: nop

;}
RECOMP_FUNC void func_800981E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800981E4: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x800981E8: jr          $ra
    // 0x800981EC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    return;
    // 0x800981EC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
;}
RECOMP_FUNC void func_800981F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800981F0: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800981F4: lbu         $v1, 0xF50($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XF50);
    // 0x800981F8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800981FC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80098200: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80098204: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80098208: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x8009820C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80098210: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x80098214: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80098218: addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    // 0x8009821C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80098220: lbu         $s0, 0x43($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X43);
    // 0x80098224: nor         $v0, $zero, $s1
    ctx->r2 = ~(0 | ctx->r17);
    // 0x80098228: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8009822C: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x80098230: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80098234: beq         $v1, $zero, L_80098274
    if (ctx->r3 == 0) {
        // 0x80098238: sw          $ra, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r31;
            goto L_80098274;
    }
    // 0x80098238: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8009823C: jal         0x80092010
    // 0x80098240: nop

    func_80092010(rdram, ctx);
        goto after_0;
    // 0x80098240: nop

    after_0:
    // 0x80098244: sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16 << 16);
    // 0x80098248: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8009824C: andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    // 0x80098250: andi        $a2, $s4, 0xFF
    ctx->r6 = ctx->r20 & 0XFF;
    // 0x80098254: andi        $a3, $s2, 0xFF
    ctx->r7 = ctx->r18 & 0XFF;
    // 0x80098258: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8009825C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80098260: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80098264: jal         0x800923E4
    // 0x80098268: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    func_800923E4(rdram, ctx);
        goto after_1;
    // 0x80098268: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    after_1:
    // 0x8009826C: jal         0x8009205C
    // 0x80098270: nop

    func_8009205C(rdram, ctx);
        goto after_2;
    // 0x80098270: nop

    after_2:
L_80098274:
    // 0x80098274: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80098278: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8009827C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80098280: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80098284: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80098288: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009828C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80098290: jr          $ra
    // 0x80098294: nop

    return;
    // 0x80098294: nop

;}
RECOMP_FUNC void func_80098298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    { static int n=0; ++n; if (n<=10 || (n%50)==0) {
        fprintf(stderr, "[trace] func_80098298 (stage-render) ENTRY #%d a0=0x%08X\n",
            n, (uint32_t)ctx->r4);
        fflush(stderr);
    } }
    // 0x80098298: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8009829C: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x800982A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800982A4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800982A8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800982AC: beq         $v0, $zero, L_800982FC
    if (ctx->r2 == 0) {
        // 0x800982B0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800982FC;
    }
    // 0x800982B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800982B4: jal         0x80092010
    // 0x800982B8: nop

    func_80092010(rdram, ctx);
        goto after_0;
    // 0x800982B8: nop

    after_0:
    // 0x800982BC: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x800982C0: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800982C4: sll         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2 << 3);
    // 0x800982C8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800982CC: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800982D0: lbu         $v1, 0x2A20($at)
    ctx->r3 = MEM_BU(ctx->r1, 0X2A20);
    // 0x800982D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800982D8: bne         $v1, $v0, L_800982F4
    if (ctx->r3 != ctx->r2) {
        // 0x800982DC: nop
    
            goto L_800982F4;
    }
    // 0x800982DC: nop

    // 0x800982E0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800982E4: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800982E8: sb          $zero, 0x2A20($at)
    MEM_B(0X2A20, ctx->r1) = 0;
    // 0x800982EC: jal         0x800869DC
    // 0x800982F0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800869DC(rdram, ctx);
        goto after_1;
    // 0x800982F0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
L_800982F4:
    // 0x800982F4: jal         0x8009205C
    // 0x800982F8: nop

    func_8009205C(rdram, ctx);
        goto after_2;
    // 0x800982F8: nop

    after_2:
L_800982FC:
    // 0x800982FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80098300: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80098304: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80098308: jr          $ra
    // 0x8009830C: nop

    return;
    // 0x8009830C: nop

;}
RECOMP_FUNC void func_80098310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098310: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80098314: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80098318: lw          $s6, 0xA0($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XA0);
    // 0x8009831C: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80098320: lw          $s4, 0xA4($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XA4);
    // 0x80098324: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80098328: lwc1        $f0, -0x2180($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2180);
    // 0x8009832C: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80098330: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80098334: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80098338: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8009833C: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80098340: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x80098344: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80098348: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8009834C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80098350: sdc1        $f30, 0x88($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X88, ctx->r29);
    // 0x80098354: sdc1        $f28, 0x80($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X80, ctx->r29);
    // 0x80098358: sdc1        $f26, 0x78($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X78, ctx->r29);
    // 0x8009835C: sdc1        $f24, 0x70($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X70, ctx->r29);
    // 0x80098360: sdc1        $f22, 0x68($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X68, ctx->r29);
    // 0x80098364: sdc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X60, ctx->r29);
    // 0x80098368: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x8009836C: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
    // 0x80098370: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x80098374: lw          $s0, 0x3418($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X3418);
    // 0x80098378: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8009837C: lwc1        $f24, -0x217C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X217C);
    // 0x80098380: beq         $s0, $zero, L_80098648
    if (ctx->r16 == 0) {
        // 0x80098384: addu        $s5, $a3, $zero
        ctx->r21 = ADD32(ctx->r7, 0);
            goto L_80098648;
    }
    // 0x80098384: addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
    // 0x80098388: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x8009838C: mtc1        $zero, $f27
    ctx->f_odd[(27 - 1) * 2] = 0;
    // 0x80098390: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    // 0x80098394: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
L_80098398:
    // 0x80098398: lwc1        $f12, 0xC($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8009839C: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800983A0: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800983A4: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x800983A8: lwc1        $f2, 0x10($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800983AC: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800983B0: mul.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800983B4: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800983B8: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800983BC: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800983C0: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800983C4: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800983C8: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800983CC: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800983D0: add.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x800983D4: add.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x800983D8: jal         0x80093E6C
    // 0x800983DC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_80093E6C(rdram, ctx);
        goto after_0;
    // 0x800983DC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800983E0: lwc1        $f2, 0x24($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800983E4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x800983E8: c.le.s      $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f22.fl <= ctx->f2.fl;
    // 0x800983EC: nop

    // 0x800983F0: bc1f        L_8009863C
    if (!c1cs) {
        // 0x800983F4: lui         $v0, 0x8
        ctx->r2 = S32(0X8 << 16);
            goto L_8009863C;
    }
    // 0x800983F4: lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
    // 0x800983F8: div.s       $f2, $f22, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f22.fl, ctx->f2.fl);
    // 0x800983FC: lwc1        $f0, 0x30($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X30);
    // 0x80098400: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80098404: sub.s       $f0, $f30, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f30.fl - ctx->f0.fl;
    // 0x80098408: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8009840C: nop

    // 0x80098410: mul.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80098414: lwc1        $f2, 0x28($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80098418: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8009841C: lwc1        $f4, 0x2C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80098420: sub.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80098424: sub.s       $f0, $f30, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f30.fl - ctx->f0.fl;
    // 0x80098428: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8009842C: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80098430: lwc1        $f2, 0x84($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80098434: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80098438: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8009843C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80098440: swc1        $f0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f0.u32l;
    // 0x80098444: lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X8);
    // 0x80098448: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8009844C: bne         $v0, $zero, L_8009863C
    if (ctx->r2 != 0) {
        // 0x80098450: andi        $v0, $v1, 0x8
        ctx->r2 = ctx->r3 & 0X8;
            goto L_8009863C;
    }
    // 0x80098450: andi        $v0, $v1, 0x8
    ctx->r2 = ctx->r3 & 0X8;
    // 0x80098454: bne         $v0, $zero, L_8009846C
    if (ctx->r2 != 0) {
        // 0x80098458: nop
    
            goto L_8009846C;
    }
    // 0x80098458: nop

    // 0x8009845C: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80098460: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80098464: beq         $v0, $zero, L_80098588
    if (ctx->r2 == 0) {
        // 0x80098468: addiu       $a0, $s0, 0x48
        ctx->r4 = ADD32(ctx->r16, 0X48);
            goto L_80098588;
    }
    // 0x80098468: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
L_8009846C:
    // 0x8009846C: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80098470: lwc1        $f0, 0x18($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80098474: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80098478: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x8009847C: lwc1        $f2, 0x1C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80098480: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80098484: mul.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80098488: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8009848C: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x80098490: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80098494: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80098498: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8009849C: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800984A0: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800984A4: add.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x800984A8: add.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x800984AC: jal         0x80093E6C
    // 0x800984B0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_80093E6C(rdram, ctx);
        goto after_1;
    // 0x800984B0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800984B4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800984B8: c.lt.s      $f28, $f20
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f28.fl < ctx->f20.fl;
    // 0x800984BC: nop

    // 0x800984C0: bc1f        L_80098588
    if (!c1cs) {
        // 0x800984C4: addiu       $a0, $s0, 0x48
        ctx->r4 = ADD32(ctx->r16, 0X48);
            goto L_80098588;
    }
    // 0x800984C4: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x800984C8: lwc1        $f0, 0x18($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X18);
    // 0x800984CC: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800984D0: lwc1        $f2, 0x18($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800984D4: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800984D8: mul.s       $f2, $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x800984DC: add.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800984E0: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800984E4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800984E8: sub.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800984EC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800984F0: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x800984F4: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800984F8: lwc1        $f2, 0x1C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800984FC: lwc1        $f4, 0x10($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80098500: mul.s       $f2, $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x80098504: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80098508: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8009850C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80098510: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80098514: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80098518: lwc1        $f0, 0x20($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8009851C: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x80098520: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80098524: mul.s       $f6, $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x80098528: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8009852C: mul.s       $f8, $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80098530: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80098534: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80098538: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8009853C: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80098540: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80098544: mul.s       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80098548: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8009854C: add.s       $f12, $f8, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x80098550: jal         0x80093E6C
    // 0x80098554: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    func_80093E6C(rdram, ctx);
        goto after_2;
    // 0x80098554: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x80098558: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8009855C: nop

    // 0x80098560: bc1f        L_80098574
    if (!c1cs) {
        // 0x80098564: nop
    
            goto L_80098574;
    }
    // 0x80098564: nop

    // 0x80098568: lwc1        $f0, 0x80($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X80);
    // 0x8009856C: j           L_8009857C
    // 0x80098570: sub.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f20.fl;
        goto L_8009857C;
    // 0x80098570: sub.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f20.fl;
L_80098574:
    // 0x80098574: lwc1        $f0, 0x80($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80098578: add.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f20.fl;
L_8009857C:
    // 0x8009857C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80098580: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
    // 0x80098584: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
L_80098588:
    // 0x80098588: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    // 0x8009858C: jal         0x80099C50
    // 0x80098590: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_80099C50(rdram, ctx);
        goto after_3;
    // 0x80098590: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x80098594: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80098598: c.le.s      $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f28.fl <= ctx->f2.fl;
    // 0x8009859C: nop

    // 0x800985A0: bc1f        L_800985C0
    if (!c1cs) {
        // 0x800985A4: nop
    
            goto L_800985C0;
    }
    // 0x800985A4: nop

    // 0x800985A8: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800985AC: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x800985B0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800985B4: lwc1        $f0, -0x2178($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2178);
    // 0x800985B8: j           L_800985D4
    // 0x800985BC: nop

        goto L_800985D4;
    // 0x800985BC: nop

L_800985C0:
    // 0x800985C0: lwc1        $f4, 0x7C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x800985C4: neg.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = -ctx->f4.fl;
    // 0x800985C8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800985CC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800985D0: lwc1        $f0, -0x2174($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2174);
L_800985D4:
    // 0x800985D4: bc1tl       L_800985DC
    if (c1cs) {
        // 0x800985D8: div.s       $f0, $f2, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
            goto L_800985DC;
    }
    goto skip_0;
    // 0x800985D8: div.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    skip_0:
L_800985DC:
    // 0x800985DC: swc1        $f0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f0.u32l;
    // 0x800985E0: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800985E4: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x800985E8: c.eq.d      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.d == ctx->f26.d;
    // 0x800985EC: nop

    // 0x800985F0: bc1f        L_80098624
    if (!c1cs) {
        // 0x800985F4: nop
    
            goto L_80098624;
    }
    // 0x800985F4: nop

    // 0x800985F8: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800985FC: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80098600: c.eq.d      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.d == ctx->f26.d;
    // 0x80098604: nop

    // 0x80098608: bc1f        L_80098624
    if (!c1cs) {
        // 0x8009860C: nop
    
            goto L_80098624;
    }
    // 0x8009860C: nop

    // 0x80098610: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80098614: c.eq.s      $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f0.fl == ctx->f28.fl;
    // 0x80098618: nop

    // 0x8009861C: bc1t        L_8009862C
    if (c1cs) {
        // 0x80098620: nop
    
            goto L_8009862C;
    }
    // 0x80098620: nop

L_80098624:
    // 0x80098624: jal         0x80099CFC
    // 0x80098628: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_80099CFC(rdram, ctx);
        goto after_4;
    // 0x80098628: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_4:
L_8009862C:
    // 0x8009862C: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80098630: swc1        $f0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f0.u32l;
    // 0x80098634: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80098638: swc1        $f0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f0.u32l;
L_8009863C:
    // 0x8009863C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80098640: bne         $s0, $zero, L_80098398
    if (ctx->r16 != 0) {
        // 0x80098644: nop
    
            goto L_80098398;
    }
    // 0x80098644: nop

L_80098648:
    // 0x80098648: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8009864C: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80098650: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x80098654: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80098658: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8009865C: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80098660: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80098664: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80098668: ldc1        $f30, 0x88($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X88);
    // 0x8009866C: ldc1        $f28, 0x80($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X80);
    // 0x80098670: ldc1        $f26, 0x78($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X78);
    // 0x80098674: ldc1        $f24, 0x70($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X70);
    // 0x80098678: ldc1        $f22, 0x68($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X68);
    // 0x8009867C: ldc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X60);
    // 0x80098680: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x80098684: jr          $ra
    // 0x80098688: nop

    return;
    // 0x80098688: nop

;}
RECOMP_FUNC void func_8009868C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009868C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80098690: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80098694: lwc1        $f22, 0x40($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80098698: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8009869C: lwc1        $f24, 0x44($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800986A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800986A4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800986A8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800986AC: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x800986B0: lw          $s0, 0x34($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X34);
    // 0x800986B4: lui         $v1, 0x10
    ctx->r3 = S32(0X10 << 16);
    // 0x800986B8: mtc1        $a1, $f2
    ctx->f2.u32l = ctx->r5;
    // 0x800986BC: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800986C0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800986C4: beq         $v0, $zero, L_80098730
    if (ctx->r2 == 0) {
        // 0x800986C8: nop
    
            goto L_80098730;
    }
    // 0x800986C8: nop

    // 0x800986CC: lwc1        $f0, 0x40($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X40);
    // 0x800986D0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800986D4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800986D8: lwc1        $f2, -0x2170($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2170);
    // 0x800986DC: mul.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800986E0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800986E4: lwc1        $f0, -0x216C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X216C);
    // 0x800986E8: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800986EC: nop

    // 0x800986F0: bc1tl       L_80098708
    if (c1cs) {
        // 0x800986F4: sub.s       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_80098708;
    }
    goto skip_0;
    // 0x800986F4: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    skip_0:
    // 0x800986F8: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800986FC: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x80098700: j           L_8009871C
    // 0x80098704: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_8009871C;
    // 0x80098704: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_80098708:
    // 0x80098708: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8009870C: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x80098710: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80098714: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80098718: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_8009871C:
    // 0x8009871C: sltiu       $v0, $v1, 0x80
    ctx->r2 = ctx->r3 < 0X80 ? 1 : 0;
    // 0x80098720: beq         $v0, $zero, L_80098784
    if (ctx->r2 == 0) {
        // 0x80098724: addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
            goto L_80098784;
    }
    // 0x80098724: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x80098728: j           L_80098788
    // 0x8009872C: nop

        goto L_80098788;
    // 0x8009872C: nop

L_80098730:
    // 0x80098730: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80098734: lwc1        $f0, -0x2168($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2168);
    // 0x80098738: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8009873C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80098740: lwc1        $f0, -0x2164($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2164);
    // 0x80098744: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80098748: nop

    // 0x8009874C: bc1tl       L_80098764
    if (c1cs) {
        // 0x80098750: sub.s       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_80098764;
    }
    goto skip_1;
    // 0x80098750: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    skip_1:
    // 0x80098754: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80098758: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8009875C: j           L_80098778
    // 0x80098760: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
        goto L_80098778;
    // 0x80098760: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
L_80098764:
    // 0x80098764: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80098768: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8009876C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80098770: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x80098774: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
L_80098778:
    // 0x80098778: sltiu       $v0, $a1, 0x80
    ctx->r2 = ctx->r5 < 0X80 ? 1 : 0;
    // 0x8009877C: bne         $v0, $zero, L_80098788
    if (ctx->r2 != 0) {
        // 0x80098780: nop
    
            goto L_80098788;
    }
    // 0x80098780: nop

L_80098784:
    // 0x80098784: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
L_80098788:
    // 0x80098788: jal         0x8008905C
    // 0x8009878C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8008905C(rdram, ctx);
        goto after_0;
    // 0x8009878C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80098790: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80098794: lwc1        $f0, -0x2160($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2160);
    // 0x80098798: add.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x8009879C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800987A0: lwc1        $f2, -0x215C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X215C);
    // 0x800987A4: mul.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800987A8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800987AC: lwc1        $f0, -0x2158($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2158);
    // 0x800987B0: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800987B4: nop

    // 0x800987B8: bc1tl       L_800987D0
    if (c1cs) {
        // 0x800987BC: sub.s       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_800987D0;
    }
    goto skip_2;
    // 0x800987BC: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    skip_2:
    // 0x800987C0: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800987C4: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x800987C8: j           L_800987E4
    // 0x800987CC: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_800987E4;
    // 0x800987CC: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_800987D0:
    // 0x800987D0: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800987D4: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x800987D8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800987DC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800987E0: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_800987E4:
    // 0x800987E4: sltiu       $v0, $v1, 0x80
    ctx->r2 = ctx->r3 < 0X80 ? 1 : 0;
    // 0x800987E8: bne         $v0, $zero, L_800987F4
    if (ctx->r2 != 0) {
        // 0x800987EC: addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
            goto L_800987F4;
    }
    // 0x800987EC: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x800987F0: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
L_800987F4:
    // 0x800987F4: jal         0x800883C4
    // 0x800987F8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800883C4(rdram, ctx);
        goto after_1;
    // 0x800987F8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800987FC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80098800: lwc1        $f0, -0x2154($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2154);
    // 0x80098804: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80098808: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8009880C: lwc1        $f2, -0x2150($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2150);
    // 0x80098810: mul.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80098814: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80098818: lwc1        $f0, -0x214C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X214C);
    // 0x8009881C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80098820: nop

    // 0x80098824: bc1tl       L_8009883C
    if (c1cs) {
        // 0x80098828: sub.s       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_8009883C;
    }
    goto skip_3;
    // 0x80098828: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    skip_3:
    // 0x8009882C: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80098830: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x80098834: j           L_80098850
    // 0x80098838: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_80098850;
    // 0x80098838: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_8009883C:
    // 0x8009883C: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80098840: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x80098844: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80098848: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8009884C: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_80098850:
    // 0x80098850: sltiu       $v0, $v1, 0x80
    ctx->r2 = ctx->r3 < 0X80 ? 1 : 0;
    // 0x80098854: bne         $v0, $zero, L_80098860
    if (ctx->r2 != 0) {
        // 0x80098858: addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
            goto L_80098860;
    }
    // 0x80098858: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x8009885C: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
L_80098860:
    // 0x80098860: jal         0x800885AC
    // 0x80098864: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800885AC(rdram, ctx);
        goto after_2;
    // 0x80098864: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80098868: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8009886C: lwc1        $f0, -0x2148($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2148);
    // 0x80098870: mul.s       $f2, $f24, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x80098874: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80098878: lwc1        $f0, -0x2144($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2144);
    // 0x8009887C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80098880: nop

    // 0x80098884: bc1tl       L_8009889C
    if (c1cs) {
        // 0x80098888: sub.s       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_8009889C;
    }
    goto skip_4;
    // 0x80098888: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    skip_4:
    // 0x8009888C: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80098890: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80098894: j           L_800988B0
    // 0x80098898: sltiu       $v0, $a1, 0x4000
    ctx->r2 = ctx->r5 < 0X4000 ? 1 : 0;
        goto L_800988B0;
    // 0x80098898: sltiu       $v0, $a1, 0x4000
    ctx->r2 = ctx->r5 < 0X4000 ? 1 : 0;
L_8009889C:
    // 0x8009889C: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800988A0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800988A4: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800988A8: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x800988AC: sltiu       $v0, $a1, 0x4000
    ctx->r2 = ctx->r5 < 0X4000 ? 1 : 0;
L_800988B0:
    // 0x800988B0: bne         $v0, $zero, L_800988BC
    if (ctx->r2 != 0) {
        // 0x800988B4: addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
            goto L_800988BC;
    }
    // 0x800988B4: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x800988B8: addiu       $v0, $zero, 0x3FFF
    ctx->r2 = ADD32(0, 0X3FFF);
L_800988BC:
    // 0x800988BC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800988C0: jal         0x80088794
    // 0x800988C4: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    func_80088794(rdram, ctx);
        goto after_3;
    // 0x800988C4: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    after_3:
    // 0x800988C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800988CC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800988D0: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800988D4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800988D8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800988DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800988E0: jr          $ra
    // 0x800988E4: nop

    return;
    // 0x800988E4: nop

;}
RECOMP_FUNC void func_800988E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800988E8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800988EC: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x800988F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800988F4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800988F8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800988FC: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80098900: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x80098904: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80098908: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x8009890C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80098910: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // 0x80098914: beq         $v0, $zero, L_80098994
    if (ctx->r2 == 0) {
        // 0x80098918: sw          $ra, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r31;
            goto L_80098994;
    }
    // 0x80098918: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8009891C: jal         0x80092010
    // 0x80098920: nop

    func_80092010(rdram, ctx);
        goto after_0;
    // 0x80098920: nop

    after_0:
    // 0x80098924: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80098928: lwc1        $f2, -0x2140($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2140);
    // 0x8009892C: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x80098930: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80098934: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80098938: div.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8009893C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80098940: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x80098944: lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X8);
    // 0x80098948: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x8009894C: sw          $v1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r3;
    // 0x80098950: sw          $a0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r4;
    // 0x80098954: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80098958: lw          $v1, 0x4($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X4);
    // 0x8009895C: lw          $a0, 0x8($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X8);
    // 0x80098960: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x80098964: sw          $v1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r3;
    // 0x80098968: sw          $a0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r4;
    // 0x8009896C: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80098970: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80098974: nop

    // 0x80098978: bc1f        L_80098984
    if (!c1cs) {
        // 0x8009897C: swc1        $f2, 0x28($s0)
        MEM_W(0X28, ctx->r16) = ctx->f2.u32l;
            goto L_80098984;
    }
    // 0x8009897C: swc1        $f2, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f2.u32l;
    // 0x80098980: swc1        $f2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f2.u32l;
L_80098984:
    // 0x80098984: jal         0x8009205C
    // 0x80098988: nop

    func_8009205C(rdram, ctx);
        goto after_1;
    // 0x80098988: nop

    after_1:
    // 0x8009898C: j           L_80098998
    // 0x80098990: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80098998;
    // 0x80098990: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80098994:
    // 0x80098994: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80098998:
    // 0x80098998: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8009899C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800989A0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800989A4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800989A8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800989AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800989B0: jr          $ra
    // 0x800989B4: nop

    return;
    // 0x800989B4: nop

;}
RECOMP_FUNC void func_800989B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800989B8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800989BC: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x800989C0: beq         $v0, $zero, L_800989D0
    if (ctx->r2 == 0) {
        // 0x800989C4: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800989D0;
    }
    // 0x800989C4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800989C8: lhu         $v0, 0x8($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X8);
    // 0x800989CC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
L_800989D0:
    // 0x800989D0: jr          $ra
    // 0x800989D4: nop

    return;
    // 0x800989D4: nop

;}
RECOMP_FUNC void func_800989D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800989D8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800989DC: sdc1        $f22, 0x60($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X60, ctx->r29);
    // 0x800989E0: lwc1        $f22, 0x78($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800989E4: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x800989E8: lw          $fp, 0x7C($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X7C);
    // 0x800989EC: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800989F0: lhu         $s3, 0x82($sp)
    ctx->r19 = MEM_HU(ctx->r29, 0X82);
    // 0x800989F4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800989F8: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x800989FC: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80098A00: lbu         $s1, 0x87($sp)
    ctx->r17 = MEM_BU(ctx->r29, 0X87);
    // 0x80098A04: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80098A08: lbu         $s2, 0x8B($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X8B);
    // 0x80098A0C: sdc1        $f20, 0x58($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X58, ctx->r29);
    // 0x80098A10: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x80098A14: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80098A18: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x80098A1C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80098A20: addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // 0x80098A24: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80098A28: addu        $s7, $a2, $zero
    ctx->r23 = ADD32(ctx->r6, 0);
    // 0x80098A2C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80098A30: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80098A34: beq         $v0, $zero, L_80098B9C
    if (ctx->r2 == 0) {
        // 0x80098A38: sw          $s0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r16;
            goto L_80098B9C;
    }
    // 0x80098A38: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80098A3C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80098A40: jal         0x80092010
    // 0x80098A44: or          $s4, $s3, $v0
    ctx->r20 = ctx->r19 | ctx->r2;
    func_80092010(rdram, ctx);
        goto after_0;
    // 0x80098A44: or          $s4, $s3, $v0
    ctx->r20 = ctx->r19 | ctx->r2;
    after_0:
    // 0x80098A48: addu        $s0, $s5, $zero
    ctx->r16 = ADD32(ctx->r21, 0);
    // 0x80098A4C: bne         $s0, $zero, L_80098A5C
    if (ctx->r16 != 0) {
        // 0x80098A50: nop
    
            goto L_80098A5C;
    }
    // 0x80098A50: nop

    // 0x80098A54: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x80098A58: addiu       $s0, $s0, 0x2D20
    ctx->r16 = ADD32(ctx->r16, 0X2D20);
L_80098A5C:
    // 0x80098A5C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80098A60: lwc1        $f2, -0x213C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X213C);
    // 0x80098A64: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x80098A68: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80098A6C: div.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80098A70: mtc1        $s2, $f0
    ctx->f0.u32l = ctx->r18;
    // 0x80098A74: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80098A78: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80098A7C: sw          $fp, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r30;
    // 0x80098A80: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x80098A84: lw          $v1, 0x4($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X4);
    // 0x80098A88: lw          $a0, 0x8($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X8);
    // 0x80098A8C: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x80098A90: sw          $v1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r3;
    // 0x80098A94: sw          $a0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r4;
    // 0x80098A98: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x80098A9C: lw          $v1, 0x4($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X4);
    // 0x80098AA0: lw          $a0, 0x8($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X8);
    // 0x80098AA4: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x80098AA8: sw          $v1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r3;
    // 0x80098AAC: sw          $a0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r4;
    // 0x80098AB0: swc1        $f20, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f20.u32l;
    // 0x80098AB4: sh          $s3, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r19;
    // 0x80098AB8: swc1        $f22, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f22.u32l;
    // 0x80098ABC: sw          $s4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r20;
    // 0x80098AC0: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    // 0x80098AC4: bne         $s5, $zero, L_80098B58
    if (ctx->r21 != 0) {
        // 0x80098AC8: swc1        $f0, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
            goto L_80098B58;
    }
    // 0x80098AC8: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x80098ACC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80098AD0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80098AD4: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80098AD8: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // 0x80098ADC: addiu       $v0, $sp, 0x24
    ctx->r2 = ADD32(ctx->r29, 0X24);
    // 0x80098AE0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80098AE4: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x80098AE8: jal         0x80098310
    // 0x80098AEC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_80098310(rdram, ctx);
        goto after_1;
    // 0x80098AEC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_1:
    // 0x80098AF0: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80098AF4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80098AF8: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x80098AFC: nop

    // 0x80098B00: bc1t        L_80098B94
    if (c1cs) {
        // 0x80098B04: addiu       $a1, $zero, 0x7F
        ctx->r5 = ADD32(0, 0X7F);
            goto L_80098B94;
    }
    // 0x80098B04: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x80098B08: lhu         $a0, 0x3C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X3C);
    // 0x80098B0C: jal         0x80087EE8
    // 0x80098B10: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80087EE8(rdram, ctx);
        goto after_2;
    // 0x80098B10: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_2:
    // 0x80098B14: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80098B18: beq         $v0, $v1, L_80098B94
    if (ctx->r2 == ctx->r3) {
        // 0x80098B1C: sw          $v0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->r2;
            goto L_80098B94;
    }
    // 0x80098B1C: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x80098B20: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80098B24: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80098B28: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80098B2C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80098B30: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80098B34: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80098B38: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80098B3C: jal         0x8009868C
    // 0x80098B40: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8009868C(rdram, ctx);
        goto after_3;
    // 0x80098B40: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80098B44: jal         0x8009205C
    // 0x80098B48: nop

    func_8009205C(rdram, ctx);
        goto after_4;
    // 0x80098B48: nop

    after_4:
    // 0x80098B4C: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80098B50: j           L_80098BA0
    // 0x80098B54: nop

        goto L_80098BA0;
    // 0x80098B54: nop

L_80098B58:
    // 0x80098B58: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80098B5C: lw          $v0, 0x3414($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3414);
    // 0x80098B60: beq         $v0, $zero, L_80098B6C
    if (ctx->r2 == 0) {
        // 0x80098B64: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_80098B6C;
    }
    // 0x80098B64: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80098B68: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
L_80098B6C:
    // 0x80098B6C: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80098B70: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80098B74: sw          $v1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r3;
    // 0x80098B78: lui         $v1, 0x3
    ctx->r3 = S32(0X3 << 16);
    // 0x80098B7C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80098B80: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80098B84: sw          $s0, 0x3414($at)
    MEM_W(0X3414, ctx->r1) = ctx->r16;
    // 0x80098B88: sh          $zero, 0x3E($s0)
    MEM_H(0X3E, ctx->r16) = 0;
    // 0x80098B8C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80098B90: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
L_80098B94:
    // 0x80098B94: jal         0x8009205C
    // 0x80098B98: nop

    func_8009205C(rdram, ctx);
        goto after_5;
    // 0x80098B98: nop

    after_5:
L_80098B9C:
    // 0x80098B9C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80098BA0:
    // 0x80098BA0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80098BA4: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80098BA8: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80098BAC: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80098BB0: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80098BB4: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80098BB8: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80098BBC: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80098BC0: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80098BC4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80098BC8: ldc1        $f22, 0x60($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X60);
    // 0x80098BCC: ldc1        $f20, 0x58($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X58);
    // 0x80098BD0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80098BD4: jr          $ra
    // 0x80098BD8: nop

    return;
    // 0x80098BD8: nop

;}
RECOMP_FUNC void func_80098BDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098BDC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80098BE0: sdc1        $f22, 0x60($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X60, ctx->r29);
    // 0x80098BE4: lwc1        $f22, 0x78($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80098BE8: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80098BEC: lw          $fp, 0x7C($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X7C);
    // 0x80098BF0: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80098BF4: lhu         $s7, 0x82($sp)
    ctx->r23 = MEM_HU(ctx->r29, 0X82);
    // 0x80098BF8: lhu         $v1, 0x86($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X86);
    // 0x80098BFC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80098C00: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80098C04: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80098C08: lbu         $s1, 0x8B($sp)
    ctx->r17 = MEM_BU(ctx->r29, 0X8B);
    // 0x80098C0C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80098C10: lbu         $s2, 0x8F($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X8F);
    // 0x80098C14: sdc1        $f20, 0x58($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X58, ctx->r29);
    // 0x80098C18: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x80098C1C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80098C20: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x80098C24: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80098C28: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x80098C2C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80098C30: addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // 0x80098C34: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80098C38: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80098C3C: beq         $v0, $zero, L_80098DA0
    if (ctx->r2 == 0) {
        // 0x80098C40: sw          $s0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r16;
            goto L_80098DA0;
    }
    // 0x80098C40: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80098C44: jal         0x80092010
    // 0x80098C48: addu        $s3, $v1, $zero
    ctx->r19 = ADD32(ctx->r3, 0);
    func_80092010(rdram, ctx);
        goto after_0;
    // 0x80098C48: addu        $s3, $v1, $zero
    ctx->r19 = ADD32(ctx->r3, 0);
    after_0:
    // 0x80098C4C: addu        $s0, $s4, $zero
    ctx->r16 = ADD32(ctx->r20, 0);
    // 0x80098C50: bne         $s0, $zero, L_80098C60
    if (ctx->r16 != 0) {
        // 0x80098C54: nop
    
            goto L_80098C60;
    }
    // 0x80098C54: nop

    // 0x80098C58: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x80098C5C: addiu       $s0, $s0, 0x2D20
    ctx->r16 = ADD32(ctx->r16, 0X2D20);
L_80098C60:
    // 0x80098C60: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80098C64: lwc1        $f2, -0x2138($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2138);
    // 0x80098C68: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x80098C6C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80098C70: div.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80098C74: mtc1        $s2, $f0
    ctx->f0.u32l = ctx->r18;
    // 0x80098C78: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80098C7C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80098C80: sw          $fp, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r30;
    // 0x80098C84: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x80098C88: lw          $v1, 0x4($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X4);
    // 0x80098C8C: lw          $a0, 0x8($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X8);
    // 0x80098C90: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x80098C94: sw          $v1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r3;
    // 0x80098C98: sw          $a0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r4;
    // 0x80098C9C: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x80098CA0: lw          $v1, 0x4($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X4);
    // 0x80098CA4: lw          $a0, 0x8($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X8);
    // 0x80098CA8: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x80098CAC: sw          $v1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r3;
    // 0x80098CB0: sw          $a0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r4;
    // 0x80098CB4: swc1        $f20, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f20.u32l;
    // 0x80098CB8: sh          $s7, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r23;
    // 0x80098CBC: swc1        $f22, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f22.u32l;
    // 0x80098CC0: sw          $s3, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r19;
    // 0x80098CC4: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    // 0x80098CC8: bne         $s4, $zero, L_80098D5C
    if (ctx->r20 != 0) {
        // 0x80098CCC: swc1        $f0, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
            goto L_80098D5C;
    }
    // 0x80098CCC: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x80098CD0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80098CD4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80098CD8: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80098CDC: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // 0x80098CE0: addiu       $v0, $sp, 0x24
    ctx->r2 = ADD32(ctx->r29, 0X24);
    // 0x80098CE4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80098CE8: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x80098CEC: jal         0x80098310
    // 0x80098CF0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_80098310(rdram, ctx);
        goto after_1;
    // 0x80098CF0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_1:
    // 0x80098CF4: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80098CF8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80098CFC: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x80098D00: nop

    // 0x80098D04: bc1t        L_80098D98
    if (c1cs) {
        // 0x80098D08: addiu       $a1, $zero, 0x7F
        ctx->r5 = ADD32(0, 0X7F);
            goto L_80098D98;
    }
    // 0x80098D08: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x80098D0C: lhu         $a0, 0x3C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X3C);
    // 0x80098D10: jal         0x80087EE8
    // 0x80098D14: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80087EE8(rdram, ctx);
        goto after_2;
    // 0x80098D14: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_2:
    // 0x80098D18: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80098D1C: beq         $v0, $v1, L_80098D98
    if (ctx->r2 == ctx->r3) {
        // 0x80098D20: sw          $v0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->r2;
            goto L_80098D98;
    }
    // 0x80098D20: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x80098D24: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80098D28: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80098D2C: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80098D30: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80098D34: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80098D38: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80098D3C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80098D40: jal         0x8009868C
    // 0x80098D44: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8009868C(rdram, ctx);
        goto after_3;
    // 0x80098D44: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80098D48: jal         0x8009205C
    // 0x80098D4C: nop

    func_8009205C(rdram, ctx);
        goto after_4;
    // 0x80098D4C: nop

    after_4:
    // 0x80098D50: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80098D54: j           L_80098DA4
    // 0x80098D58: nop

        goto L_80098DA4;
    // 0x80098D58: nop

L_80098D5C:
    // 0x80098D5C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80098D60: lw          $v0, 0x3414($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3414);
    // 0x80098D64: beq         $v0, $zero, L_80098D70
    if (ctx->r2 == 0) {
        // 0x80098D68: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_80098D70;
    }
    // 0x80098D68: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80098D6C: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
L_80098D70:
    // 0x80098D70: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80098D74: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80098D78: sw          $v1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r3;
    // 0x80098D7C: lui         $v1, 0x3
    ctx->r3 = S32(0X3 << 16);
    // 0x80098D80: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80098D84: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80098D88: sw          $s0, 0x3414($at)
    MEM_W(0X3414, ctx->r1) = ctx->r16;
    // 0x80098D8C: sh          $zero, 0x3E($s0)
    MEM_H(0X3E, ctx->r16) = 0;
    // 0x80098D90: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80098D94: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
L_80098D98:
    // 0x80098D98: jal         0x8009205C
    // 0x80098D9C: nop

    func_8009205C(rdram, ctx);
        goto after_5;
    // 0x80098D9C: nop

    after_5:
L_80098DA0:
    // 0x80098DA0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80098DA4:
    // 0x80098DA4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80098DA8: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80098DAC: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80098DB0: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80098DB4: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80098DB8: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80098DBC: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80098DC0: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80098DC4: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80098DC8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80098DCC: ldc1        $f22, 0x60($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X60);
    // 0x80098DD0: ldc1        $f20, 0x58($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X58);
    // 0x80098DD4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80098DD8: jr          $ra
    // 0x80098DDC: nop

    return;
    // 0x80098DDC: nop

;}
RECOMP_FUNC void func_80098DE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098DE0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80098DE4: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80098DE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80098DEC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80098DF0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80098DF4: beq         $v0, $zero, L_80098E6C
    if (ctx->r2 == 0) {
        // 0x80098DF8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80098E6C;
    }
    // 0x80098DF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80098DFC: jal         0x80092010
    // 0x80098E00: nop

    func_80092010(rdram, ctx);
        goto after_0;
    // 0x80098E00: nop

    after_0:
    // 0x80098E04: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80098E08: beq         $v1, $zero, L_80098E18
    if (ctx->r3 == 0) {
        // 0x80098E0C: nop
    
            goto L_80098E18;
    }
    // 0x80098E0C: nop

    // 0x80098E10: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80098E14: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80098E18:
    // 0x80098E18: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x80098E1C: beq         $v1, $zero, L_80098E30
    if (ctx->r3 == 0) {
        // 0x80098E20: nop
    
            goto L_80098E30;
    }
    // 0x80098E20: nop

    // 0x80098E24: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80098E28: j           L_80098E3C
    // 0x80098E2C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_80098E3C;
    // 0x80098E2C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80098E30:
    // 0x80098E30: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80098E34: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80098E38: sw          $v0, 0x3414($at)
    MEM_W(0X3414, ctx->r1) = ctx->r2;
L_80098E3C:
    // 0x80098E3C: lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XA);
    // 0x80098E40: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80098E44: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x80098E48: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80098E4C: beq         $a0, $v0, L_80098E5C
    if (ctx->r4 == ctx->r2) {
        // 0x80098E50: nop
    
            goto L_80098E5C;
    }
    // 0x80098E50: nop

    // 0x80098E54: jal         0x80089414
    // 0x80098E58: nop

    func_80089414(rdram, ctx);
        goto after_1;
    // 0x80098E58: nop

    after_1:
L_80098E5C:
    // 0x80098E5C: jal         0x8009205C
    // 0x80098E60: nop

    func_8009205C(rdram, ctx);
        goto after_2;
    // 0x80098E60: nop

    after_2:
    // 0x80098E64: j           L_80098E70
    // 0x80098E68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80098E70;
    // 0x80098E68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80098E6C:
    // 0x80098E6C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80098E70:
    // 0x80098E70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80098E74: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80098E78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80098E7C: jr          $ra
    // 0x80098E80: nop

    return;
    // 0x80098E80: nop

;}
RECOMP_FUNC void func_80098E84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098E84: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80098E88: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80098E8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80098E90: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80098E94: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80098E98: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80098E9C: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80098EA0: beq         $v0, $zero, L_80098ED0
    if (ctx->r2 == 0) {
        // 0x80098EA4: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_80098ED0;
    }
    // 0x80098EA4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80098EA8: jal         0x80092010
    // 0x80098EAC: nop

    func_80092010(rdram, ctx);
        goto after_0;
    // 0x80098EAC: nop

    after_0:
    // 0x80098EB0: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80098EB4: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80098EB8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80098EBC: beq         $v0, $zero, L_80098EC8
    if (ctx->r2 == 0) {
        // 0x80098EC0: nop
    
            goto L_80098EC8;
    }
    // 0x80098EC0: nop

    // 0x80098EC4: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
L_80098EC8:
    // 0x80098EC8: jal         0x8009205C
    // 0x80098ECC: nop

    func_8009205C(rdram, ctx);
        goto after_1;
    // 0x80098ECC: nop

    after_1:
L_80098ED0:
    // 0x80098ED0: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x80098ED4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80098ED8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80098EDC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80098EE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80098EE4: jr          $ra
    // 0x80098EE8: nop

    return;
    // 0x80098EE8: nop

;}
RECOMP_FUNC void func_80098EEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098EEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80098EF0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80098EF4: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x80098EF8: lw          $s0, 0x3414($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X3414);
    // 0x80098EFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80098F00: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80098F04: beq         $s0, $zero, L_80098F8C
    if (ctx->r16 == 0) {
        // 0x80098F08: sw          $s1, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r17;
            goto L_80098F8C;
    }
    // 0x80098F08: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80098F0C: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_80098F10:
    // 0x80098F10: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80098F14: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80098F18: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80098F1C: beql        $v0, $zero, L_80098F84
    if (ctx->r2 == 0) {
        // 0x80098F20: addu        $s0, $s1, $zero
        ctx->r16 = ADD32(ctx->r17, 0);
            goto L_80098F84;
    }
    goto skip_0;
    // 0x80098F20: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
    skip_0:
    // 0x80098F24: jal         0x80092010
    // 0x80098F28: nop

    func_80092010(rdram, ctx);
        goto after_0;
    // 0x80098F28: nop

    after_0:
    // 0x80098F2C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80098F30: beq         $v1, $zero, L_80098F40
    if (ctx->r3 == 0) {
        // 0x80098F34: nop
    
            goto L_80098F40;
    }
    // 0x80098F34: nop

    // 0x80098F38: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80098F3C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80098F40:
    // 0x80098F40: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x80098F44: beq         $v1, $zero, L_80098F58
    if (ctx->r3 == 0) {
        // 0x80098F48: nop
    
            goto L_80098F58;
    }
    // 0x80098F48: nop

    // 0x80098F4C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80098F50: j           L_80098F64
    // 0x80098F54: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_80098F64;
    // 0x80098F54: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80098F58:
    // 0x80098F58: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80098F5C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80098F60: sw          $v0, 0x3414($at)
    MEM_W(0X3414, ctx->r1) = ctx->r2;
L_80098F64:
    // 0x80098F64: lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XA);
    // 0x80098F68: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80098F6C: beq         $a0, $s2, L_80098F7C
    if (ctx->r4 == ctx->r18) {
        // 0x80098F70: sw          $v0, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->r2;
            goto L_80098F7C;
    }
    // 0x80098F70: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x80098F74: jal         0x80089414
    // 0x80098F78: nop

    func_80089414(rdram, ctx);
        goto after_1;
    // 0x80098F78: nop

    after_1:
L_80098F7C:
    // 0x80098F7C: jal         0x8009205C
    // 0x80098F80: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
    func_8009205C(rdram, ctx);
        goto after_2;
    // 0x80098F80: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
    after_2:
L_80098F84:
    // 0x80098F84: bne         $s0, $zero, L_80098F10
    if (ctx->r16 != 0) {
        // 0x80098F88: nop
    
            goto L_80098F10;
    }
    // 0x80098F88: nop

L_80098F8C:
    // 0x80098F8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80098F90: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80098F94: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80098F98: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80098F9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80098FA0: jr          $ra
    // 0x80098FA4: nop

    return;
    // 0x80098FA4: nop

;}
RECOMP_FUNC void func_80098FA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098FA8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80098FAC: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80098FB0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80098FB4: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80098FB8: lw          $s3, 0x70($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X70);
    // 0x80098FBC: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80098FC0: lbu         $s5, 0x77($sp)
    ctx->r21 = MEM_BU(ctx->r29, 0X77);
    // 0x80098FC4: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80098FC8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80098FCC: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80098FD0: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80098FD4: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80098FD8: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x80098FDC: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80098FE0: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x80098FE4: bne         $v0, $zero, L_80098FF4
    if (ctx->r2 != 0) {
        // 0x80098FE8: sw          $ra, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r31;
            goto L_80098FF4;
    }
    // 0x80098FE8: sw          $ra, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r31;
    // 0x80098FEC: j           L_80099104
    // 0x80098FF0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80099104;
    // 0x80098FF0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80098FF4:
    // 0x80098FF4: jal         0x80092010
    // 0x80098FF8: nop

    func_80092010(rdram, ctx);
        goto after_0;
    // 0x80098FF8: nop

    after_0:
    // 0x80098FFC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80099000: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x80099004: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x80099008: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x8009900C: sw          $v1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r3;
    // 0x80099010: sw          $a0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r4;
    // 0x80099014: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80099018: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x8009901C: lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X8);
    // 0x80099020: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x80099024: sw          $v1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r3;
    // 0x80099028: sw          $a0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r4;
    // 0x8009902C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80099030: lw          $v1, 0x4($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X4);
    // 0x80099034: lw          $a0, 0x8($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X8);
    // 0x80099038: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x8009903C: sw          $v1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r3;
    // 0x80099040: sw          $a0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r4;
    // 0x80099044: lwc1        $f0, 0x0($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80099048: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8009904C: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x80099050: lwc1        $f0, 0x4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80099054: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80099058: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x8009905C: lwc1        $f0, 0x8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80099060: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    // 0x80099064: addiu       $a1, $s0, 0x3C
    ctx->r5 = ADD32(ctx->r16, 0X3C);
    // 0x80099068: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8009906C: addiu       $a2, $s0, 0x24
    ctx->r6 = ADD32(ctx->r16, 0X24);
    // 0x80099070: jal         0x80099D68
    // 0x80099074: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    func_80099D68(rdram, ctx);
        goto after_1;
    // 0x80099074: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x80099078: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8009907C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80099080: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80099084: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80099088: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8009908C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80099090: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80099094: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80099098: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8009909C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800990A0: lwc1        $f0, 0x44($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800990A4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x800990A8: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800990AC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800990B0: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800990B4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x800990B8: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800990BC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800990C0: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800990C4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800990C8: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800990CC: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800990D0: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800990D4: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x800990D8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800990DC: jal         0x80099DCC
    // 0x800990E0: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    func_80099DCC(rdram, ctx);
        goto after_2;
    // 0x800990E0: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x800990E4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800990E8: lwc1        $f2, -0x2134($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2134);
    // 0x800990EC: mtc1        $s5, $f0
    ctx->f0.u32l = ctx->r21;
    // 0x800990F0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800990F4: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800990F8: jal         0x8009205C
    // 0x800990FC: swc1        $f0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f0.u32l;
    func_8009205C(rdram, ctx);
        goto after_3;
    // 0x800990FC: swc1        $f0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f0.u32l;
    after_3:
    // 0x80099100: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80099104:
    // 0x80099104: lw          $ra, 0x58($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X58);
    // 0x80099108: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x8009910C: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80099110: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80099114: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80099118: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8009911C: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80099120: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80099124: jr          $ra
    // 0x80099128: nop

    return;
    // 0x80099128: nop

;}
RECOMP_FUNC void func_8009912C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009912C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80099130: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80099134: lw          $s1, 0x88($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X88);
    // 0x80099138: sdc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X60, ctx->r29);
    // 0x8009913C: lwc1        $f20, 0x8C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80099140: sdc1        $f22, 0x68($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X68, ctx->r29);
    // 0x80099144: lwc1        $f22, 0x90($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80099148: sdc1        $f24, 0x70($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X70, ctx->r29);
    // 0x8009914C: lwc1        $f24, 0x94($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80099150: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80099154: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80099158: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x8009915C: lw          $s6, 0x98($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X98);
    // 0x80099160: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80099164: lbu         $s5, 0x9F($sp)
    ctx->r21 = MEM_BU(ctx->r29, 0X9F);
    // 0x80099168: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8009916C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80099170: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80099174: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x80099178: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8009917C: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x80099180: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80099184: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x80099188: beq         $v0, $zero, L_800992D4
    if (ctx->r2 == 0) {
        // 0x8009918C: sw          $ra, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r31;
            goto L_800992D4;
    }
    // 0x8009918C: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80099190: jal         0x80092010
    // 0x80099194: nop

    func_80092010(rdram, ctx);
        goto after_0;
    // 0x80099194: nop

    after_0:
    // 0x80099198: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8009919C: lw          $v0, 0x3418($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3418);
    // 0x800991A0: beq         $v0, $zero, L_800991AC
    if (ctx->r2 == 0) {
        // 0x800991A4: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_800991AC;
    }
    // 0x800991A4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800991A8: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
L_800991AC:
    // 0x800991AC: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800991B0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800991B4: sw          $s0, 0x3418($at)
    MEM_W(0X3418, ctx->r1) = ctx->r16;
    // 0x800991B8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800991BC: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x800991C0: lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X8);
    // 0x800991C4: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x800991C8: sw          $v1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r3;
    // 0x800991CC: sw          $a0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r4;
    // 0x800991D0: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800991D4: lw          $v1, 0x4($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X4);
    // 0x800991D8: lw          $a0, 0x8($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X8);
    // 0x800991DC: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x800991E0: sw          $v1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r3;
    // 0x800991E4: sw          $a0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r4;
    // 0x800991E8: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800991EC: lw          $v1, 0x4($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X4);
    // 0x800991F0: lw          $a0, 0x8($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X8);
    // 0x800991F4: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x800991F8: sw          $v1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r3;
    // 0x800991FC: sw          $a0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r4;
    // 0x80099200: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80099204: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80099208: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x8009920C: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80099210: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80099214: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    // 0x80099218: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x8009921C: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80099220: addiu       $a1, $s0, 0x3C
    ctx->r5 = ADD32(ctx->r16, 0X3C);
    // 0x80099224: addiu       $a2, $s0, 0x24
    ctx->r6 = ADD32(ctx->r16, 0X24);
    // 0x80099228: swc1        $f20, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f20.u32l;
    // 0x8009922C: swc1        $f22, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f22.u32l;
    // 0x80099230: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80099234: swc1        $f24, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f24.u32l;
    // 0x80099238: jal         0x80099D68
    // 0x8009923C: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    func_80099D68(rdram, ctx);
        goto after_1;
    // 0x8009923C: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x80099240: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80099244: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80099248: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8009924C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80099250: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80099254: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80099258: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8009925C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80099260: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80099264: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80099268: lwc1        $f0, 0x44($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8009926C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80099270: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80099274: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80099278: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8009927C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80099280: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80099284: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80099288: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8009928C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80099290: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80099294: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80099298: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8009929C: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x800992A0: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800992A4: jal         0x80099DCC
    // 0x800992A8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    func_80099DCC(rdram, ctx);
        goto after_2;
    // 0x800992A8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x800992AC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800992B0: lwc1        $f2, -0x2130($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2130);
    // 0x800992B4: mtc1        $s5, $f0
    ctx->f0.u32l = ctx->r21;
    // 0x800992B8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800992BC: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800992C0: sw          $s6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r22;
    // 0x800992C4: jal         0x8009205C
    // 0x800992C8: swc1        $f0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f0.u32l;
    func_8009205C(rdram, ctx);
        goto after_3;
    // 0x800992C8: swc1        $f0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f0.u32l;
    after_3:
    // 0x800992CC: j           L_800992D8
    // 0x800992D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800992D8;
    // 0x800992D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800992D4:
    // 0x800992D4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800992D8:
    // 0x800992D8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800992DC: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800992E0: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800992E4: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800992E8: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800992EC: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800992F0: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800992F4: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800992F8: ldc1        $f24, 0x70($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X70);
    // 0x800992FC: ldc1        $f22, 0x68($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X68);
    // 0x80099300: ldc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X60);
    // 0x80099304: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x80099308: jr          $ra
    // 0x8009930C: nop

    return;
    // 0x8009930C: nop

;}
RECOMP_FUNC void func_80099310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099310: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80099314: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80099318: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009931C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80099320: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80099324: beq         $v0, $zero, L_8009937C
    if (ctx->r2 == 0) {
        // 0x80099328: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8009937C;
    }
    // 0x80099328: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009932C: jal         0x80092010
    // 0x80099330: nop

    func_80092010(rdram, ctx);
        goto after_0;
    // 0x80099330: nop

    after_0:
    // 0x80099334: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80099338: beq         $v1, $zero, L_80099348
    if (ctx->r3 == 0) {
        // 0x8009933C: nop
    
            goto L_80099348;
    }
    // 0x8009933C: nop

    // 0x80099340: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80099344: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80099348:
    // 0x80099348: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x8009934C: beq         $v1, $zero, L_80099360
    if (ctx->r3 == 0) {
        // 0x80099350: nop
    
            goto L_80099360;
    }
    // 0x80099350: nop

    // 0x80099354: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80099358: j           L_8009936C
    // 0x8009935C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_8009936C;
    // 0x8009935C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80099360:
    // 0x80099360: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80099364: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80099368: sw          $v0, 0x3418($at)
    MEM_W(0X3418, ctx->r1) = ctx->r2;
L_8009936C:
    // 0x8009936C: jal         0x8009205C
    // 0x80099370: nop

    func_8009205C(rdram, ctx);
        goto after_1;
    // 0x80099370: nop

    after_1:
    // 0x80099374: j           L_80099380
    // 0x80099378: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80099380;
    // 0x80099378: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8009937C:
    // 0x8009937C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80099380:
    // 0x80099380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80099384: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80099388: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009938C: jr          $ra
    // 0x80099390: nop

    return;
    // 0x80099390: nop

;}
RECOMP_FUNC void func_80099394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099394: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80099398: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8009939C: lbu         $v0, 0x2EF0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2EF0);
    // 0x800993A0: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x800993A4: mtc1        $a1, $f2
    ctx->f2.u32l = ctx->r5;
    // 0x800993A8: blez        $v0, L_800993E0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800993AC: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800993E0;
    }
    // 0x800993AC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800993B0: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    // 0x800993B4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800993B8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800993BC:
    // 0x800993BC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800993C0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800993C4: lw          $v0, 0x2D70($at)
    ctx->r2 = MEM_W(ctx->r1, 0X2D70);
    // 0x800993C8: beq         $a2, $v0, L_800993E0
    if (ctx->r6 == ctx->r2) {
        // 0x800993CC: nop
    
            goto L_800993E0;
    }
    // 0x800993CC: nop

    // 0x800993D0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800993D4: slt         $v0, $a1, $a0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800993D8: bne         $v0, $zero, L_800993BC
    if (ctx->r2 != 0) {
        // 0x800993DC: addiu       $v1, $v1, 0xC
        ctx->r3 = ADD32(ctx->r3, 0XC);
            goto L_800993BC;
    }
    // 0x800993DC: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
L_800993E0:
    // 0x800993E0: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x800993E4: lbu         $v1, 0x2EF0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2EF0);
    // 0x800993E8: bne         $a1, $v1, L_80099430
    if (ctx->r5 != ctx->r3) {
        // 0x800993EC: sll         $v0, $a1, 1
        ctx->r2 = S32(ctx->r5 << 1);
            goto L_80099430;
    }
    // 0x800993EC: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x800993F0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800993F4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800993F8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800993FC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80099400: sw          $zero, 0x2D74($at)
    MEM_W(0X2D74, ctx->r1) = 0;
    // 0x80099404: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80099408: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8009940C: sw          $zero, 0x2D78($at)
    MEM_W(0X2D78, ctx->r1) = 0;
    // 0x80099410: lw          $a0, 0x38($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X38);
    // 0x80099414: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80099418: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009941C: sb          $v1, 0x2EF0($at)
    MEM_B(0X2EF0, ctx->r1) = ctx->r3;
    // 0x80099420: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80099424: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80099428: sw          $a0, 0x2D70($at)
    MEM_W(0X2D70, ctx->r1) = ctx->r4;
    // 0x8009942C: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
L_80099430:
    // 0x80099430: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80099434: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80099438: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009943C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80099440: lw          $a2, 0x2D78($at)
    ctx->r6 = MEM_W(ctx->r1, 0X2D78);
    // 0x80099444: beq         $a2, $zero, L_80099470
    if (ctx->r6 == 0) {
        // 0x80099448: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80099470;
    }
    // 0x80099448: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8009944C:
    // 0x8009944C: lwc1        $f0, 0x4($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80099450: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80099454: nop

    // 0x80099458: bc1t        L_80099470
    if (c1cs) {
        // 0x8009945C: nop
    
            goto L_80099470;
    }
    // 0x8009945C: nop

    // 0x80099460: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    // 0x80099464: lw          $a2, 0x0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X0);
    // 0x80099468: bne         $a2, $zero, L_8009944C
    if (ctx->r6 != 0) {
        // 0x8009946C: nop
    
            goto L_8009944C;
    }
    // 0x8009946C: nop

L_80099470:
    // 0x80099470: bne         $a0, $zero, L_800994B8
    if (ctx->r4 != 0) {
        // 0x80099474: nop
    
            goto L_800994B8;
    }
    // 0x80099474: nop

    // 0x80099478: sll         $a0, $a1, 1
    ctx->r4 = S32(ctx->r5 << 1);
    // 0x8009947C: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80099480: lbu         $v1, 0x3410($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X3410);
    // 0x80099484: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x80099488: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8009948C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80099490: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80099494: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80099498: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8009949C: addiu       $v1, $v1, 0x3290
    ctx->r3 = ADD32(ctx->r3, 0X3290);
    // 0x800994A0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800994A4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800994A8: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800994AC: sw          $v0, 0x2D78($at)
    MEM_W(0X2D78, ctx->r1) = ctx->r2;
    // 0x800994B0: j           L_800994DC
    // 0x800994B4: nop

        goto L_800994DC;
    // 0x800994B4: nop

L_800994B8:
    // 0x800994B8: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800994BC: lbu         $v0, 0x3410($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X3410);
    // 0x800994C0: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x800994C4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800994C8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800994CC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800994D0: addiu       $v0, $v0, 0x3290
    ctx->r2 = ADD32(ctx->r2, 0X3290);
    // 0x800994D4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800994D8: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
L_800994DC:
    // 0x800994DC: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x800994E0: lbu         $v1, 0x3410($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X3410);
    // 0x800994E4: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800994E8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800994EC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800994F0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800994F4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800994F8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800994FC: sw          $a2, 0x3290($at)
    MEM_W(0X3290, ctx->r1) = ctx->r6;
    // 0x80099500: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80099504: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80099508: sw          $a3, 0x3298($at)
    MEM_W(0X3298, ctx->r1) = ctx->r7;
    // 0x8009950C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80099510: sb          $v1, 0x3410($at)
    MEM_B(0X3410, ctx->r1) = ctx->r3;
    // 0x80099514: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80099518: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8009951C: swc1        $f2, 0x3294($at)
    MEM_W(0X3294, ctx->r1) = ctx->f2.u32l;
    // 0x80099520: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80099524: jr          $ra
    // 0x80099528: nop

    return;
    // 0x80099528: nop

;}
RECOMP_FUNC void func_8009952C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009952C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80099530: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80099534: lbu         $v0, 0x2EF0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2EF0);
    // 0x80099538: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8009953C: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80099540: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x80099544: mtc1        $a1, $f2
    ctx->f2.u32l = ctx->r5;
    // 0x80099548: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x8009954C: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x80099550: blez        $v0, L_80099588
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80099554: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80099588;
    }
    // 0x80099554: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80099558: lw          $a2, 0x38($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X38);
    // 0x8009955C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80099560: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80099564:
    // 0x80099564: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80099568: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8009956C: lw          $v0, 0x2D70($at)
    ctx->r2 = MEM_W(ctx->r1, 0X2D70);
    // 0x80099570: beq         $a2, $v0, L_80099588
    if (ctx->r6 == ctx->r2) {
        // 0x80099574: nop
    
            goto L_80099588;
    }
    // 0x80099574: nop

    // 0x80099578: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8009957C: slt         $v0, $a1, $a0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80099580: bne         $v0, $zero, L_80099564
    if (ctx->r2 != 0) {
        // 0x80099584: addiu       $v1, $v1, 0xC
        ctx->r3 = ADD32(ctx->r3, 0XC);
            goto L_80099564;
    }
    // 0x80099584: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
L_80099588:
    // 0x80099588: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8009958C: lbu         $v1, 0x2EF0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2EF0);
    // 0x80099590: bne         $a1, $v1, L_800995DC
    if (ctx->r5 != ctx->r3) {
        // 0x80099594: addiu       $v0, $zero, 0x20
        ctx->r2 = ADD32(0, 0X20);
            goto L_800995DC;
    }
    // 0x80099594: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x80099598: beq         $a1, $v0, L_800995F0
    if (ctx->r5 == ctx->r2) {
        // 0x8009959C: sll         $v0, $a1, 1
        ctx->r2 = S32(ctx->r5 << 1);
            goto L_800995F0;
    }
    // 0x8009959C: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x800995A0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800995A4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800995A8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800995AC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800995B0: sw          $zero, 0x2D74($at)
    MEM_W(0X2D74, ctx->r1) = 0;
    // 0x800995B4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800995B8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800995BC: sw          $zero, 0x2D78($at)
    MEM_W(0X2D78, ctx->r1) = 0;
    // 0x800995C0: lw          $a0, 0x38($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X38);
    // 0x800995C4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800995C8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800995CC: sb          $v1, 0x2EF0($at)
    MEM_B(0X2EF0, ctx->r1) = ctx->r3;
    // 0x800995D0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800995D4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800995D8: sw          $a0, 0x2D70($at)
    MEM_W(0X2D70, ctx->r1) = ctx->r4;
L_800995DC:
    // 0x800995DC: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x800995E0: lbu         $v1, 0x3280($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X3280);
    // 0x800995E4: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x800995E8: bne         $v1, $v0, L_800995F8
    if (ctx->r3 != ctx->r2) {
        // 0x800995EC: sll         $v0, $a1, 1
        ctx->r2 = S32(ctx->r5 << 1);
            goto L_800995F8;
    }
    // 0x800995EC: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
L_800995F0:
    // 0x800995F0: j           L_80099714
    // 0x800995F4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80099714;
    // 0x800995F4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800995F8:
    // 0x800995F8: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800995FC: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x80099600: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80099604: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80099608: lw          $a1, 0x2D74($at)
    ctx->r5 = MEM_W(ctx->r1, 0X2D74);
    // 0x8009960C: beq         $a1, $zero, L_8009967C
    if (ctx->r5 == 0) {
        // 0x80099610: sll         $v0, $v1, 3
        ctx->r2 = S32(ctx->r3 << 3);
            goto L_8009967C;
    }
    // 0x80099610: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80099614: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80099618: beq         $v0, $zero, L_80099644
    if (ctx->r2 == 0) {
        // 0x8009961C: nop
    
            goto L_80099644;
    }
    // 0x8009961C: nop

L_80099620:
    // 0x80099620: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80099624: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80099628: nop

    // 0x8009962C: bc1t        L_80099644
    if (c1cs) {
        // 0x80099630: nop
    
            goto L_80099644;
    }
    // 0x80099630: nop

    // 0x80099634: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    // 0x80099638: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8009963C: bne         $v0, $zero, L_80099620
    if (ctx->r2 != 0) {
        // 0x80099640: nop
    
            goto L_80099620;
    }
    // 0x80099640: nop

L_80099644:
    // 0x80099644: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80099648: lbu         $v1, 0x3280($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X3280);
    // 0x8009964C: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80099650: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80099654: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80099658: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009965C: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80099660: addiu       $v1, $v1, 0x2F00
    ctx->r3 = ADD32(ctx->r3, 0X2F00);
    // 0x80099664: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80099668: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8009966C: sw          $a0, 0x2F00($at)
    MEM_W(0X2F00, ctx->r1) = ctx->r4;
    // 0x80099670: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80099674: j           L_800996A8
    // 0x80099678: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_800996A8;
    // 0x80099678: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_8009967C:
    // 0x8009967C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80099680: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80099684: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80099688: addiu       $v1, $v1, 0x2F00
    ctx->r3 = ADD32(ctx->r3, 0X2F00);
    // 0x8009968C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80099690: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80099694: sw          $zero, 0x2F00($at)
    MEM_W(0X2F00, ctx->r1) = 0;
    // 0x80099698: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8009969C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800996A0: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800996A4: sw          $v0, 0x2D74($at)
    MEM_W(0X2D74, ctx->r1) = ctx->r2;
L_800996A8:
    // 0x800996A8: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800996AC: lbu         $a0, 0x3280($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X3280);
    // 0x800996B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800996B4: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x800996B8: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800996BC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800996C0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800996C4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800996C8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800996CC: sw          $t0, 0x2F18($at)
    MEM_W(0X2F18, ctx->r1) = ctx->r8;
    // 0x800996D0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800996D4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800996D8: swc1        $f8, 0x2F14($at)
    MEM_W(0X2F14, ctx->r1) = ctx->f8.u32l;
    // 0x800996DC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800996E0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800996E4: swc1        $f4, 0x2F08($at)
    MEM_W(0X2F08, ctx->r1) = ctx->f4.u32l;
    // 0x800996E8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800996EC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800996F0: swc1        $f6, 0x2F0C($at)
    MEM_W(0X2F0C, ctx->r1) = ctx->f6.u32l;
    // 0x800996F4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800996F8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800996FC: swc1        $f10, 0x2F10($at)
    MEM_W(0X2F10, ctx->r1) = ctx->f10.u32l;
    // 0x80099700: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80099704: sb          $a0, 0x3280($at)
    MEM_B(0X3280, ctx->r1) = ctx->r4;
    // 0x80099708: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009970C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80099710: swc1        $f2, 0x2F04($at)
    MEM_W(0X2F04, ctx->r1) = ctx->f2.u32l;
L_80099714:
    // 0x80099714: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80099718: jr          $ra
    // 0x8009971C: nop

    return;
    // 0x8009971C: nop

;}
RECOMP_FUNC void func_80099720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099720: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80099724: lbu         $v0, 0x2EF0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2EF0);
    // 0x80099728: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8009972C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80099730: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x80099734: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x80099738: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8009973C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80099740: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80099744: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80099748: blez        $v0, L_800998C0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8009974C: sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
            goto L_800998C0;
    }
    // 0x8009974C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80099750: lui         $s5, 0xFFFD
    ctx->r21 = S32(0XFFFD << 16);
    // 0x80099754: ori         $s5, $s5, 0xFFFF
    ctx->r21 = ctx->r21 | 0XFFFF;
    // 0x80099758: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
L_8009975C:
    // 0x8009975C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80099760: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x80099764: lw          $s1, 0x2D74($at)
    ctx->r17 = MEM_W(ctx->r1, 0X2D74);
    // 0x80099768: beq         $s1, $zero, L_800998A8
    if (ctx->r17 == 0) {
        // 0x8009976C: nop
    
            goto L_800998A8;
    }
    // 0x8009976C: nop

    // 0x80099770: addu        $s2, $s3, $zero
    ctx->r18 = ADD32(ctx->r19, 0);
L_80099774:
    // 0x80099774: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80099778: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x8009977C: lw          $v0, 0x2D78($at)
    ctx->r2 = MEM_W(ctx->r1, 0X2D78);
    // 0x80099780: beq         $v0, $zero, L_800997F4
    if (ctx->r2 == 0) {
        // 0x80099784: nop
    
            goto L_800997F4;
    }
    // 0x80099784: nop

    // 0x80099788: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8009978C: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80099790: sub.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80099794: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80099798: lwc1        $f0, -0x212C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X212C);
    // 0x8009979C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800997A0: nop

    // 0x800997A4: bc1t        L_8009989C
    if (c1cs) {
        // 0x800997A8: nop
    
            goto L_8009989C;
    }
    // 0x800997A8: nop

    // 0x800997AC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800997B0: lwc1        $f0, -0x2128($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2128);
    // 0x800997B4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800997B8: nop

    // 0x800997BC: bc1f        L_800997EC
    if (!c1cs) {
        // 0x800997C0: nop
    
            goto L_800997EC;
    }
    // 0x800997C0: nop

    // 0x800997C4: lw          $v1, 0x18($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X18);
    // 0x800997C8: lhu         $v0, 0x3E($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X3E);
    // 0x800997CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800997D0: sh          $v0, 0x3E($v1)
    MEM_H(0X3E, ctx->r3) = ctx->r2;
    // 0x800997D4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800997D8: sltiu       $v0, $v0, 0x14
    ctx->r2 = ctx->r2 < 0X14 ? 1 : 0;
    // 0x800997DC: beq         $v0, $zero, L_800997F4
    if (ctx->r2 == 0) {
        // 0x800997E0: nop
    
            goto L_800997F4;
    }
    // 0x800997E0: nop

    // 0x800997E4: j           L_8009989C
    // 0x800997E8: nop

        goto L_8009989C;
    // 0x800997E8: nop

L_800997EC:
    // 0x800997EC: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x800997F0: sh          $zero, 0x3E($v0)
    MEM_H(0X3E, ctx->r2) = 0;
L_800997F4:
    // 0x800997F4: lw          $s0, 0x18($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X18);
    // 0x800997F8: lhu         $a0, 0x3C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X3C);
    // 0x800997FC: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x80099800: jal         0x80087D90
    // 0x80099804: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80087D90(rdram, ctx);
        goto after_0;
    // 0x80099804: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_0:
    // 0x80099808: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8009980C: bne         $v0, $v1, L_80099834
    if (ctx->r2 != ctx->r3) {
        // 0x80099810: sw          $v0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->r2;
            goto L_80099834;
    }
    // 0x80099810: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x80099814: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x80099818: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x8009981C: bne         $v0, $zero, L_8009989C
    if (ctx->r2 != 0) {
        // 0x80099820: lui         $v0, 0x4
        ctx->r2 = S32(0X4 << 16);
            goto L_8009989C;
    }
    // 0x80099820: lui         $v0, 0x4
    ctx->r2 = S32(0X4 << 16);
    // 0x80099824: or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    // 0x80099828: and         $v0, $v0, $s5
    ctx->r2 = ctx->r2 & ctx->r21;
    // 0x8009982C: j           L_8009989C
    // 0x80099830: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
        goto L_8009989C;
    // 0x80099830: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
L_80099834:
    // 0x80099834: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x80099838: lui         $v0, 0x10
    ctx->r2 = S32(0X10 << 16);
    // 0x8009983C: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    // 0x80099840: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80099844: sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    // 0x80099848: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8009984C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80099850: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80099854: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80099858: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x8009985C: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    // 0x80099860: lw          $a3, 0xC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XC);
    // 0x80099864: jal         0x8009868C
    // 0x80099868: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8009868C(rdram, ctx);
        goto after_1;
    // 0x80099868: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8009986C: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80099870: and         $v0, $v0, $s5
    ctx->r2 = ctx->r2 & ctx->r21;
    // 0x80099874: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x80099878: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009987C: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x80099880: lw          $v0, 0x2D78($at)
    ctx->r2 = MEM_W(ctx->r1, 0X2D78);
    // 0x80099884: beq         $v0, $zero, L_8009989C
    if (ctx->r2 == 0) {
        // 0x80099888: nop
    
            goto L_8009989C;
    }
    // 0x80099888: nop

    // 0x8009988C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80099890: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80099894: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x80099898: sw          $v0, 0x2D78($at)
    MEM_W(0X2D78, ctx->r1) = ctx->r2;
L_8009989C:
    // 0x8009989C: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x800998A0: bne         $s1, $zero, L_80099774
    if (ctx->r17 != 0) {
        // 0x800998A4: nop
    
            goto L_80099774;
    }
    // 0x800998A4: nop

L_800998A8:
    // 0x800998A8: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800998AC: lbu         $v0, 0x2EF0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2EF0);
    // 0x800998B0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800998B4: slt         $v0, $s4, $v0
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800998B8: bne         $v0, $zero, L_8009975C
    if (ctx->r2 != 0) {
        // 0x800998BC: addiu       $s3, $s3, 0xC
        ctx->r19 = ADD32(ctx->r19, 0XC);
            goto L_8009975C;
    }
    // 0x800998BC: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
L_800998C0:
    // 0x800998C0: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x800998C4: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800998C8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800998CC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800998D0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800998D4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800998D8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800998DC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800998E0: jr          $ra
    // 0x800998E4: nop

    return;
    // 0x800998E4: nop

;}
RECOMP_FUNC void func_800998E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    {
        static int n = 0;
        if (++n <= 10 || (n % 60) == 0) {
            if(0) fprintf(stderr, "[trace] func_800998E8 #%d\n", n);
            fflush(stderr);
        }
    }
    // 0x800998E8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800998EC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800998F0: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x800998F4: lw          $s0, 0x3414($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X3414);
    // 0x800998F8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800998FC: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80099900: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80099904: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80099908: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8009990C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80099910: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80099914: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x80099918: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009991C: sw          $zero, 0x341C($at)
    MEM_W(0X341C, ctx->r1) = 0;
    // 0x80099920: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80099924: sb          $zero, 0x2EF0($at)
    MEM_B(0X2EF0, ctx->r1) = 0;
    // 0x80099928: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009992C: sb          $zero, 0x3280($at)
    MEM_B(0X3280, ctx->r1) = 0;
    // 0x80099930: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80099934: sb          $zero, 0x3410($at)
    MEM_B(0X3410, ctx->r1) = 0;
    // 0x80099938: beq         $s0, $zero, L_80099BF4
    if (ctx->r16 == 0) {
        // 0x8009993C: nop
    
            goto L_80099BF4;
    }
    // 0x8009993C: nop

    // 0x80099940: lui         $s6, 0x4
    ctx->r22 = S32(0X4 << 16);
    // 0x80099944: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80099948: lui         $s5, 0x8
    ctx->r21 = S32(0X8 << 16);
    // 0x8009994C: lui         $s4, 0x2
    ctx->r20 = S32(0X2 << 16);
    // 0x80099950: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80099954: lui         $s2, 0xFFFD
    ctx->r18 = S32(0XFFFD << 16);
    // 0x80099958: ori         $s2, $s2, 0xFFFF
    ctx->r18 = ctx->r18 | 0XFFFF;
L_8009995C:
    // 0x8009995C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80099960: lw          $v0, 0x341C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X341C);
    // 0x80099964: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x80099968: lw          $s3, 0x0($s0)
    ctx->r19 = MEM_W(ctx->r16, 0X0);
    // 0x8009996C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80099970: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80099974: sw          $v0, 0x341C($at)
    MEM_W(0X341C, ctx->r1) = ctx->r2;
    // 0x80099978: and         $v0, $v1, $s6
    ctx->r2 = ctx->r3 & ctx->r22;
    // 0x8009997C: beql        $v0, $zero, L_800999DC
    if (ctx->r2 == 0) {
        // 0x80099980: lui         $v0, 0x2
        ctx->r2 = S32(0X2 << 16);
            goto L_800999DC;
    }
    goto skip_0;
    // 0x80099980: lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
    skip_0:
    // 0x80099984: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80099988: beq         $v1, $zero, L_80099998
    if (ctx->r3 == 0) {
        // 0x8009998C: nop
    
            goto L_80099998;
    }
    // 0x8009998C: nop

    // 0x80099990: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80099994: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80099998:
    // 0x80099998: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x8009999C: beq         $v1, $zero, L_800999B0
    if (ctx->r3 == 0) {
        // 0x800999A0: nop
    
            goto L_800999B0;
    }
    // 0x800999A0: nop

    // 0x800999A4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800999A8: j           L_800999BC
    // 0x800999AC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_800999BC;
    // 0x800999AC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800999B0:
    // 0x800999B0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800999B4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800999B8: sw          $v0, 0x3414($at)
    MEM_W(0X3414, ctx->r1) = ctx->r2;
L_800999BC:
    // 0x800999BC: lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XA);
    // 0x800999C0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x800999C4: beq         $a0, $s1, L_80099BE8
    if (ctx->r4 == ctx->r17) {
        // 0x800999C8: sw          $v0, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->r2;
            goto L_80099BE8;
    }
    // 0x800999C8: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x800999CC: jal         0x80089414
    // 0x800999D0: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
    func_80089414(rdram, ctx);
        goto after_0;
    // 0x800999D0: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
    after_0:
    // 0x800999D4: j           L_80099BEC
    // 0x800999D8: nop

        goto L_80099BEC;
    // 0x800999D8: nop

L_800999DC:
    // 0x800999DC: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x800999E0: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x800999E4: beq         $v0, $zero, L_80099A0C
    if (ctx->r2 == 0) {
        // 0x800999E8: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80099A0C;
    }
    // 0x800999E8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800999EC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800999F0: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x800999F4: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // 0x800999F8: addiu       $v0, $sp, 0x24
    ctx->r2 = ADD32(ctx->r29, 0X24);
    // 0x800999FC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80099A00: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x80099A04: jal         0x80098310
    // 0x80099A08: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_80098310(rdram, ctx);
        goto after_1;
    // 0x80099A08: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_1:
L_80099A0C:
    // 0x80099A0C: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x80099A10: and         $v0, $v1, $s5
    ctx->r2 = ctx->r3 & ctx->r21;
    // 0x80099A14: bne         $v0, $zero, L_80099BC0
    if (ctx->r2 != 0) {
        // 0x80099A18: and         $v0, $v1, $s4
        ctx->r2 = ctx->r3 & ctx->r20;
            goto L_80099BC0;
    }
    // 0x80099A18: and         $v0, $v1, $s4
    ctx->r2 = ctx->r3 & ctx->r20;
    // 0x80099A1C: beq         $v0, $zero, L_80099AC0
    if (ctx->r2 == 0) {
        // 0x80099A20: nop
    
            goto L_80099AC0;
    }
    // 0x80099A20: nop

    // 0x80099A24: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80099A28: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x80099A2C: nop

    // 0x80099A30: bc1f        L_80099A48
    if (!c1cs) {
        // 0x80099A34: andi        $v0, $v1, 0x4
        ctx->r2 = ctx->r3 & 0X4;
            goto L_80099A48;
    }
    // 0x80099A34: andi        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 & 0X4;
    // 0x80099A38: beq         $v0, $zero, L_80099A48
    if (ctx->r2 == 0) {
        // 0x80099A3C: or          $v0, $v1, $s5
        ctx->r2 = ctx->r3 | ctx->r21;
            goto L_80099A48;
    }
    // 0x80099A3C: or          $v0, $v1, $s5
    ctx->r2 = ctx->r3 | ctx->r21;
    // 0x80099A40: j           L_80099AE8
    // 0x80099A44: and         $v0, $v0, $s2
    ctx->r2 = ctx->r2 & ctx->r18;
        goto L_80099AE8;
    // 0x80099A44: and         $v0, $v0, $s2
    ctx->r2 = ctx->r2 & ctx->r18;
L_80099A48:
    // 0x80099A48: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80099A4C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80099A50: beq         $v0, $zero, L_80099A90
    if (ctx->r2 == 0) {
        // 0x80099A54: addiu       $a1, $zero, 0x7F
        ctx->r5 = ADD32(0, 0X7F);
            goto L_80099A90;
    }
    // 0x80099A54: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x80099A58: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80099A5C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80099A60: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80099A64: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80099A68: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80099A6C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80099A70: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80099A74: jal         0x8009952C
    // 0x80099A78: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8009952C(rdram, ctx);
        goto after_2;
    // 0x80099A78: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80099A7C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80099A80: bnel        $v0, $zero, L_80099BEC
    if (ctx->r2 != 0) {
        // 0x80099A84: addu        $s0, $s3, $zero
        ctx->r16 = ADD32(ctx->r19, 0);
            goto L_80099BEC;
    }
    goto skip_1;
    // 0x80099A84: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
    skip_1:
    // 0x80099A88: j           L_80099AEC
    // 0x80099A8C: nop

        goto L_80099AEC;
    // 0x80099A8C: nop

L_80099A90:
    // 0x80099A90: lhu         $a0, 0x3C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X3C);
    // 0x80099A94: jal         0x80087D90
    // 0x80099A98: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80087D90(rdram, ctx);
        goto after_3;
    // 0x80099A98: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_3:
    // 0x80099A9C: bne         $v0, $s1, L_80099AEC
    if (ctx->r2 != ctx->r17) {
        // 0x80099AA0: sw          $v0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->r2;
            goto L_80099AEC;
    }
    // 0x80099AA0: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x80099AA4: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x80099AA8: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x80099AAC: bnel        $v0, $zero, L_80099BEC
    if (ctx->r2 != 0) {
        // 0x80099AB0: addu        $s0, $s3, $zero
        ctx->r16 = ADD32(ctx->r19, 0);
            goto L_80099BEC;
    }
    goto skip_2;
    // 0x80099AB0: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
    skip_2:
    // 0x80099AB4: or          $v0, $v1, $s6
    ctx->r2 = ctx->r3 | ctx->r22;
    // 0x80099AB8: j           L_80099AE8
    // 0x80099ABC: and         $v0, $v0, $s2
    ctx->r2 = ctx->r2 & ctx->r18;
        goto L_80099AE8;
    // 0x80099ABC: and         $v0, $v0, $s2
    ctx->r2 = ctx->r2 & ctx->r18;
L_80099AC0:
    // 0x80099AC0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80099AC4: jal         0x80088068
    // 0x80099AC8: nop

    func_80088068(rdram, ctx);
        goto after_4;
    // 0x80099AC8: nop

    after_4:
    // 0x80099ACC: bne         $v0, $s1, L_80099AEC
    if (ctx->r2 != ctx->r17) {
        // 0x80099AD0: sw          $v0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->r2;
            goto L_80099AEC;
    }
    // 0x80099AD0: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x80099AD4: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x80099AD8: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x80099ADC: bne         $v0, $zero, L_80099AE8
    if (ctx->r2 != 0) {
        // 0x80099AE0: or          $v0, $v1, $s4
        ctx->r2 = ctx->r3 | ctx->r20;
            goto L_80099AE8;
    }
    // 0x80099AE0: or          $v0, $v1, $s4
    ctx->r2 = ctx->r3 | ctx->r20;
    // 0x80099AE4: or          $v0, $v1, $s6
    ctx->r2 = ctx->r3 | ctx->r22;
L_80099AE8:
    // 0x80099AE8: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
L_80099AEC:
    // 0x80099AEC: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80099AF0: beq         $v0, $s1, L_80099B70
    if (ctx->r2 == ctx->r17) {
        // 0x80099AF4: nop
    
            goto L_80099B70;
    }
    // 0x80099AF4: nop

    // 0x80099AF8: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80099AFC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80099B00: beq         $v0, $zero, L_80099B14
    if (ctx->r2 == 0) {
        // 0x80099B04: nop
    
            goto L_80099B14;
    }
    // 0x80099B04: nop

    // 0x80099B08: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80099B0C: jal         0x80099394
    // 0x80099B10: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80099394(rdram, ctx);
        goto after_5;
    // 0x80099B10: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
L_80099B14:
    // 0x80099B14: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80099B18: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x80099B1C: nop

    // 0x80099B20: bc1f        L_80099B4C
    if (!c1cs) {
        // 0x80099B24: nop
    
            goto L_80099B4C;
    }
    // 0x80099B24: nop

    // 0x80099B28: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x80099B2C: andi        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 & 0X4;
    // 0x80099B30: beq         $v0, $zero, L_80099B4C
    if (ctx->r2 == 0) {
        // 0x80099B34: or          $v0, $v1, $s5
        ctx->r2 = ctx->r3 | ctx->r21;
            goto L_80099B4C;
    }
    // 0x80099B34: or          $v0, $v1, $s5
    ctx->r2 = ctx->r3 | ctx->r21;
    // 0x80099B38: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80099B3C: jal         0x80089414
    // 0x80099B40: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    func_80089414(rdram, ctx);
        goto after_6;
    // 0x80099B40: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    after_6:
    // 0x80099B44: j           L_80099B70
    // 0x80099B48: sw          $s1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r17;
        goto L_80099B70;
    // 0x80099B48: sw          $s1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r17;
L_80099B4C:
    // 0x80099B4C: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80099B50: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80099B54: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80099B58: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80099B5C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80099B60: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80099B64: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80099B68: jal         0x8009868C
    // 0x80099B6C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8009868C(rdram, ctx);
        goto after_7;
    // 0x80099B6C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
L_80099B70:
    // 0x80099B70: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80099B74: lui         $v1, 0x10
    ctx->r3 = S32(0X10 << 16);
    // 0x80099B78: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80099B7C: beql        $v0, $zero, L_80099BEC
    if (ctx->r2 == 0) {
        // 0x80099B80: addu        $s0, $s3, $zero
        ctx->r16 = ADD32(ctx->r19, 0);
            goto L_80099BEC;
    }
    goto skip_3;
    // 0x80099B80: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
    skip_3:
    // 0x80099B84: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80099B88: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80099B8C: lwc1        $f2, -0x2124($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2124);
    // 0x80099B90: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80099B94: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80099B98: lwc1        $f2, -0x2120($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2120);
    // 0x80099B9C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80099BA0: nop

    // 0x80099BA4: bc1f        L_80099BE8
    if (!c1cs) {
        // 0x80099BA8: swc1        $f0, 0x40($s0)
        MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
            goto L_80099BE8;
    }
    // 0x80099BA8: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x80099BAC: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80099BB0: lui         $v1, 0xFFEF
    ctx->r3 = S32(0XFFEF << 16);
    // 0x80099BB4: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x80099BB8: j           L_80099BE4
    // 0x80099BBC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
        goto L_80099BE4;
    // 0x80099BBC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
L_80099BC0:
    // 0x80099BC0: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80099BC4: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x80099BC8: nop

    // 0x80099BCC: bc1tl       L_80099BEC
    if (c1cs) {
        // 0x80099BD0: addu        $s0, $s3, $zero
        ctx->r16 = ADD32(ctx->r19, 0);
            goto L_80099BEC;
    }
    goto skip_4;
    // 0x80099BD0: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
    skip_4:
    // 0x80099BD4: lui         $v0, 0xFFF7
    ctx->r2 = S32(0XFFF7 << 16);
    // 0x80099BD8: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80099BDC: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x80099BE0: or          $v0, $v0, $s4
    ctx->r2 = ctx->r2 | ctx->r20;
L_80099BE4:
    // 0x80099BE4: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
L_80099BE8:
    // 0x80099BE8: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
L_80099BEC:
    // 0x80099BEC: bne         $s0, $zero, L_8009995C
    if (ctx->r16 != 0) {
        // 0x80099BF0: nop
    
            goto L_8009995C;
    }
    // 0x80099BF0: nop

L_80099BF4:
    // 0x80099BF4: jal         0x80099720
    // 0x80099BF8: nop

    func_80099720(rdram, ctx);
        goto after_8;
    // 0x80099BF8: nop

    after_8:
    // 0x80099BFC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80099C00: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80099C04: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80099C08: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80099C0C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80099C10: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80099C14: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80099C18: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80099C1C: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x80099C20: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80099C24: jr          $ra
    // 0x80099C28: nop

    return;
    // 0x80099C28: nop

;}
RECOMP_FUNC void func_80099C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099C2C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80099C30: sw          $zero, 0x3414($at)
    MEM_W(0X3414, ctx->r1) = 0;
    // 0x80099C34: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80099C38: sw          $zero, 0x3418($at)
    MEM_W(0X3418, ctx->r1) = 0;
    // 0x80099C3C: jr          $ra
    // 0x80099C40: nop

    return;
    // 0x80099C40: nop

;}
RECOMP_FUNC void func_80099C44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099C44: jr          $ra
    // 0x80099C48: nop

    return;
    // 0x80099C48: nop

;}
RECOMP_FUNC void fake_func_80099C4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80099C50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099C50: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80099C54: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80099C58: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80099C5C: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80099C60: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80099C64: mul.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80099C68: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80099C6C: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80099C70: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80099C74: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80099C78: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80099C7C: lwc1        $f2, 0x24($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80099C80: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80099C84: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x80099C88: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80099C8C: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80099C90: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80099C94: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80099C98: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80099C9C: mul.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80099CA0: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80099CA4: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80099CA8: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80099CAC: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80099CB0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80099CB4: lwc1        $f2, 0x28($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80099CB8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80099CBC: swc1        $f0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f0.u32l;
    // 0x80099CC0: lwc1        $f0, 0x18($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80099CC4: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80099CC8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80099CCC: lwc1        $f6, 0x1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80099CD0: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80099CD4: mul.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80099CD8: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80099CDC: lwc1        $f2, 0x20($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80099CE0: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80099CE4: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80099CE8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80099CEC: lwc1        $f2, 0x2C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80099CF0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80099CF4: jr          $ra
    // 0x80099CF8: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
    return;
    // 0x80099CF8: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_80099CFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099CFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80099D00: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80099D04: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80099D08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80099D0C: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80099D10: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80099D14: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80099D18: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80099D1C: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80099D20: mul.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80099D24: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80099D28: jal         0x80093E6C
    // 0x80099D2C: add.s       $f12, $f2, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f12.fl;
    func_80093E6C(rdram, ctx);
        goto after_0;
    // 0x80099D2C: add.s       $f12, $f2, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f12.fl;
    after_0:
    // 0x80099D30: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80099D34: div.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80099D38: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80099D3C: div.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80099D40: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80099D44: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80099D48: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x80099D4C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80099D50: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    // 0x80099D54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80099D58: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80099D5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80099D60: jr          $ra
    // 0x80099D64: nop

    return;
    // 0x80099D64: nop

;}
RECOMP_FUNC void func_80099D68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099D68: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80099D6C: lwc1        $f0, 0x8($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80099D70: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80099D74: lwc1        $f2, 0x4($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80099D78: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80099D7C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80099D80: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80099D84: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80099D88: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80099D8C: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80099D90: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80099D94: lwc1        $f2, 0x8($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80099D98: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80099D9C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80099DA0: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80099DA4: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x80099DA8: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80099DAC: lwc1        $f0, 0x4($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80099DB0: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80099DB4: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80099DB8: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80099DBC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80099DC0: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80099DC4: jr          $ra
    // 0x80099DC8: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80099DC8: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80099DCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099DCC: lwc1        $f14, 0x10($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80099DD0: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80099DD4: mul.s       $f12, $f14, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x80099DD8: lwc1        $f2, 0x1C($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80099DDC: lwc1        $f0, 0x14($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80099DE0: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80099DE4: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80099DE8: mul.s       $f6, $f8, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80099DEC: lwc1        $f10, 0x18($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80099DF0: mul.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80099DF4: nop

    // 0x80099DF8: mul.s       $f8, $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80099DFC: nop

    // 0x80099E00: mul.s       $f10, $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80099E04: sub.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x80099E08: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80099E0C: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80099E10: sub.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80099E14: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80099E18: neg.s       $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = -ctx->f6.fl;
    // 0x80099E1C: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80099E20: sub.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80099E24: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80099E28: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80099E2C: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80099E30: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80099E34: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80099E38: lwc1        $f10, -0x2110($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2110);
    // 0x80099E3C: div.s       $f10, $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80099E40: mul.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80099E44: nop

    // 0x80099E48: mul.s       $f6, $f10, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80099E4C: nop

    // 0x80099E50: mul.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80099E54: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x80099E58: swc1        $f6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f6.u32l;
    // 0x80099E5C: swc1        $f8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f8.u32l;
    // 0x80099E60: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80099E64: lwc1        $f2, 0x20($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80099E68: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80099E6C: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80099E70: lwc1        $f2, 0x1C($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80099E74: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80099E78: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80099E7C: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x80099E80: mul.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80099E84: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x80099E88: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80099E8C: lwc1        $f2, 0x20($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80099E90: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80099E94: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80099E98: lwc1        $f2, 0x18($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80099E9C: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80099EA0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80099EA4: mul.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80099EA8: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x80099EAC: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80099EB0: lwc1        $f2, 0x1C($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80099EB4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80099EB8: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80099EBC: lwc1        $f2, 0x18($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80099EC0: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80099EC4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80099EC8: mul.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80099ECC: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x80099ED0: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80099ED4: lwc1        $f2, 0x14($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80099ED8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80099EDC: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80099EE0: lwc1        $f2, 0x10($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80099EE4: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80099EE8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80099EEC: mul.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80099EF0: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x80099EF4: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80099EF8: lwc1        $f0, 0x14($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80099EFC: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80099F00: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80099F04: lwc1        $f0, 0xC($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80099F08: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80099F0C: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80099F10: mul.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80099F14: swc1        $f6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f6.u32l;
    // 0x80099F18: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80099F1C: lwc1        $f0, 0x10($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80099F20: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80099F24: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80099F28: lwc1        $f0, 0xC($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80099F2C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80099F30: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80099F34: mul.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80099F38: swc1        $f10, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f10.u32l;
    // 0x80099F3C: lwc1        $f0, 0x24($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X24);
    // 0x80099F40: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80099F44: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80099F48: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80099F4C: lwc1        $f6, 0x28($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X28);
    // 0x80099F50: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80099F54: mul.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80099F58: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80099F5C: lwc1        $f2, 0x2C($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80099F60: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80099F64: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80099F68: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80099F6C: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x80099F70: lwc1        $f0, 0x24($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X24);
    // 0x80099F74: lwc1        $f2, 0xC($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80099F78: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80099F7C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80099F80: lwc1        $f6, 0x28($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X28);
    // 0x80099F84: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80099F88: mul.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80099F8C: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80099F90: lwc1        $f2, 0x2C($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80099F94: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80099F98: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80099F9C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80099FA0: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
    // 0x80099FA4: lwc1        $f0, 0x24($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X24);
    // 0x80099FA8: lwc1        $f2, 0x18($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80099FAC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80099FB0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80099FB4: lwc1        $f6, 0x28($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X28);
    // 0x80099FB8: lwc1        $f2, 0x1C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80099FBC: mul.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80099FC0: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80099FC4: lwc1        $f2, 0x2C($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80099FC8: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80099FCC: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80099FD0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80099FD4: jr          $ra
    // 0x80099FD8: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x80099FD8: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void fake_func_80099FDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8009AF60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009AF60: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8009AF64: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8009AF68:
    // 0x8009AF68: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8009AF6C:
    // 0x8009AF6C: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x8009AF70: lw          $a2, 0x4648($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X4648);
    // 0x8009AF74: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8009AF78:
    // 0x8009AF78: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009AF7C: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x8009AF80: lbu         $v0, 0x4620($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X4620);
    // 0x8009AF84: beql        $v0, $zero, L_8009AFAC
    if (ctx->r2 == 0) {
        // 0x8009AF88: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8009AFAC;
    }
    goto skip_0;
    // 0x8009AF88: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8009AF8C: beql        $v1, $a0, L_8009AFAC
    if (ctx->r3 == ctx->r4) {
        // 0x8009AF90: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8009AFAC;
    }
    goto skip_1;
    // 0x8009AF90: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x8009AF94: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009AF98: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x8009AF9C: lw          $v0, 0x4644($at)
    ctx->r2 = MEM_W(ctx->r1, 0X4644);
    // 0x8009AFA0: beq         $v0, $a2, L_8009AFB4
    if (ctx->r2 == ctx->r6) {
        // 0x8009AFA4: nop
    
            goto L_8009AFB4;
    }
    // 0x8009AFA4: nop

    // 0x8009AFA8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8009AFAC:
    // 0x8009AFAC: beq         $v1, $zero, L_8009AF78
    if (ctx->r3 == 0) {
        // 0x8009AFB0: addiu       $a1, $a1, 0x1228
        ctx->r5 = ADD32(ctx->r5, 0X1228);
            goto L_8009AF78;
    }
    // 0x8009AFB0: addiu       $a1, $a1, 0x1228
    ctx->r5 = ADD32(ctx->r5, 0X1228);
L_8009AFB4:
    // 0x8009AFB4: beq         $v1, $t0, L_8009AFE8
    if (ctx->r3 == ctx->r8) {
        // 0x8009AFB8: sll         $v0, $a0, 3
        ctx->r2 = S32(ctx->r4 << 3);
            goto L_8009AFE8;
    }
    // 0x8009AFB8: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x8009AFBC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8009AFC0: lw          $v0, 0x4648($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4648);
    // 0x8009AFC4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8009AFC8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009AFCC: sw          $v0, 0x4648($at)
    MEM_W(0X4648, ctx->r1) = ctx->r2;
    // 0x8009AFD0: bne         $v0, $a3, L_8009AF6C
    if (ctx->r2 != ctx->r7) {
        // 0x8009AFD4: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8009AF6C;
    }
    // 0x8009AFD4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8009AFD8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009AFDC: sw          $zero, 0x4648($at)
    MEM_W(0X4648, ctx->r1) = 0;
    // 0x8009AFE0: j           L_8009AF68
    // 0x8009AFE4: nop

        goto L_8009AF68;
    // 0x8009AFE4: nop

L_8009AFE8:
    // 0x8009AFE8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8009AFEC: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8009AFF0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8009AFF4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009AFF8: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8009AFFC: lw          $v1, 0x4648($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4648);
    // 0x8009B000: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8009B004: sll         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2 << 3);
    // 0x8009B008: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8009B00C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B010: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8009B014: sw          $v1, 0x4644($at)
    MEM_W(0X4644, ctx->r1) = ctx->r3;
    // 0x8009B018: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8009B01C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B020: sw          $v1, 0x4648($at)
    MEM_W(0X4648, ctx->r1) = ctx->r3;
    // 0x8009B024: bne         $v1, $v0, L_8009B034
    if (ctx->r3 != ctx->r2) {
        // 0x8009B028: nop
    
            goto L_8009B034;
    }
    // 0x8009B028: nop

    // 0x8009B02C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B030: sw          $zero, 0x4648($at)
    MEM_W(0X4648, ctx->r1) = 0;
L_8009B034:
    // 0x8009B034: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B038: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8009B03C: lw          $v0, 0x4644($at)
    ctx->r2 = MEM_W(ctx->r1, 0X4644);
    // 0x8009B040: jr          $ra
    // 0x8009B044: nop

    return;
    // 0x8009B044: nop

;}
RECOMP_FUNC void func_8009B048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B048: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8009B04C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8009B050: lbu         $fp, 0x53($sp)
    ctx->r30 = MEM_BU(ctx->r29, 0X53);
    // 0x8009B054: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8009B058: lbu         $v0, 0x5121($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5121);
    // 0x8009B05C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8009B060: lbu         $s5, 0x57($sp)
    ctx->r21 = MEM_BU(ctx->r29, 0X57);
    // 0x8009B064: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8009B068: lbu         $s6, 0x5B($sp)
    ctx->r22 = MEM_BU(ctx->r29, 0X5B);
    // 0x8009B06C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8009B070: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x8009B074: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009B078: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8009B07C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8009B080: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x8009B084: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8009B088: addu        $s7, $a3, $zero
    ctx->r23 = ADD32(ctx->r7, 0);
    // 0x8009B08C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8009B090: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8009B094: beq         $v0, $zero, L_8009B230
    if (ctx->r2 == 0) {
        // 0x8009B098: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8009B230;
    }
    // 0x8009B098: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009B09C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8009B0A0: lw          $v0, 0x4670($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4670);
    // 0x8009B0A4: sltu        $v0, $s3, $v0
    ctx->r2 = ctx->r19 < ctx->r2 ? 1 : 0;
    // 0x8009B0A8: beq         $v0, $zero, L_8009B230
    if (ctx->r2 == 0) {
        // 0x8009B0AC: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_8009B230;
    }
    // 0x8009B0AC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8009B0B0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8009B0B4:
    // 0x8009B0B4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B0B8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8009B0BC: lbu         $v0, 0x4620($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X4620);
    // 0x8009B0C0: beql        $v0, $zero, L_8009B0D8
    if (ctx->r2 == 0) {
        // 0x8009B0C4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8009B0D8;
    }
    goto skip_0;
    // 0x8009B0C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8009B0C8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8009B0CC: blez        $s1, L_8009B0B4
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8009B0D0: addiu       $v1, $v1, 0x1228
        ctx->r3 = ADD32(ctx->r3, 0X1228);
            goto L_8009B0B4;
    }
    // 0x8009B0D0: addiu       $v1, $v1, 0x1228
    ctx->r3 = ADD32(ctx->r3, 0X1228);
    // 0x8009B0D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8009B0D8:
    // 0x8009B0D8: beq         $s1, $v0, L_8009B230
    if (ctx->r17 == ctx->r2) {
        // 0x8009B0DC: sll         $v0, $s1, 3
        ctx->r2 = S32(ctx->r17 << 3);
            goto L_8009B230;
    }
    // 0x8009B0DC: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
    // 0x8009B0E0: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x8009B0E4: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8009B0E8: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x8009B0EC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009B0F0: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x8009B0F4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8009B0F8: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8009B0FC: addiu       $v1, $v1, 0x3420
    ctx->r3 = ADD32(ctx->r3, 0X3420);
    // 0x8009B100: addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // 0x8009B104: addiu       $a0, $s0, 0x11E0
    ctx->r4 = ADD32(ctx->r16, 0X11E0);
    // 0x8009B108: addiu       $a1, $s0, 0x11F8
    ctx->r5 = ADD32(ctx->r16, 0X11F8);
    // 0x8009B10C: jal         0x8002B300
    // 0x8009B110: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8009B110: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x8009B114: bne         $s2, $zero, L_8009B140
    if (ctx->r18 != 0) {
        // 0x8009B118: sll         $v1, $s2, 3
        ctx->r3 = S32(ctx->r18 << 3);
            goto L_8009B140;
    }
    // 0x8009B118: sll         $v1, $s2, 3
    ctx->r3 = S32(ctx->r18 << 3);
    // 0x8009B11C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8009B120: lw          $v0, 0x467C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X467C);
    // 0x8009B124: sll         $v1, $s3, 2
    ctx->r3 = S32(ctx->r19 << 2);
    // 0x8009B128: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8009B12C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8009B130: bne         $v0, $zero, L_8009B13C
    if (ctx->r2 != 0) {
        // 0x8009B134: addiu       $s2, $zero, 0x3E80
        ctx->r18 = ADD32(0, 0X3E80);
            goto L_8009B13C;
    }
    // 0x8009B134: addiu       $s2, $zero, 0x3E80
    ctx->r18 = ADD32(0, 0X3E80);
    // 0x8009B138: addiu       $s2, $zero, 0x1F40
    ctx->r18 = ADD32(0, 0X1F40);
L_8009B13C:
    // 0x8009B13C: sll         $v1, $s2, 3
    ctx->r3 = S32(ctx->r18 << 3);
L_8009B140:
    // 0x8009B140: lui         $v0, 0x8888
    ctx->r2 = S32(0X8888 << 16);
    // 0x8009B144: ori         $v0, $v0, 0x8889
    ctx->r2 = ctx->r2 | 0X8889;
    // 0x8009B148: multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009B14C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8009B150: addiu       $a0, $a0, 0x4650
    ctx->r4 = ADD32(ctx->r4, 0X4650);
    // 0x8009B154: lui         $v1, 0xCCCC
    ctx->r3 = S32(0XCCCC << 16);
    // 0x8009B158: ori         $v1, $v1, 0xCCCD
    ctx->r3 = ctx->r3 | 0XCCCD;
    // 0x8009B15C: sb          $s4, 0x1204($s0)
    MEM_B(0X1204, ctx->r16) = ctx->r20;
    // 0x8009B160: mfhi        $t1
    ctx->r9 = hi;
    // 0x8009B164: srl         $v0, $t1, 4
    ctx->r2 = S32(U32(ctx->r9) >> 4);
    // 0x8009B168: addiu       $v0, $v0, 0x9F
    ctx->r2 = ADD32(ctx->r2, 0X9F);
    // 0x8009B16C: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009B170: sb          $s7, 0x1201($s0)
    MEM_B(0X1201, ctx->r16) = ctx->r23;
    // 0x8009B174: sb          $fp, 0x1202($s0)
    MEM_B(0X1202, ctx->r16) = ctx->r30;
    // 0x8009B178: sb          $s5, 0x1203($s0)
    MEM_B(0X1203, ctx->r16) = ctx->r21;
    // 0x8009B17C: sb          $s6, 0x1219($s0)
    MEM_B(0X1219, ctx->r16) = ctx->r22;
    // 0x8009B180: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8009B184: lw          $v0, 0x4674($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4674);
    // 0x8009B188: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8009B18C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8009B190: sw          $s2, 0x1208($s0)
    MEM_W(0X1208, ctx->r16) = ctx->r18;
    // 0x8009B194: sw          $v0, 0x1210($s0)
    MEM_W(0X1210, ctx->r16) = ctx->r2;
    // 0x8009B198: mfhi        $t1
    ctx->r9 = hi;
    // 0x8009B19C: srl         $v1, $t1, 7
    ctx->r3 = S32(U32(ctx->r9) >> 7);
    // 0x8009B1A0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8009B1A4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8009B1A8: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8009B1AC: jal         0x800331D0
    // 0x8009B1B0: sw          $v0, 0x1214($s0)
    MEM_W(0X1214, ctx->r16) = ctx->r2;
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8009B1B0: sw          $v0, 0x1214($s0)
    MEM_W(0X1214, ctx->r16) = ctx->r2;
    after_1:
    // 0x8009B1B4: lui         $t0, 0xFF
    ctx->r8 = S32(0XFF << 16);
    // 0x8009B1B8: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8009B1BC: lw          $v1, 0x467C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X467C);
    // 0x8009B1C0: ori         $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 | 0XFFFF;
    // 0x8009B1C4: sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19 << 2);
    // 0x8009B1C8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8009B1CC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8009B1D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8009B1D4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8009B1D8: addiu       $v0, $v0, -0x41F8
    ctx->r2 = ADD32(ctx->r2, -0X41F8);
    // 0x8009B1DC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8009B1E0: lw          $a2, 0x1210($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1210);
    // 0x8009B1E4: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8009B1E8: lw          $v0, 0x4684($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4684);
    // 0x8009B1EC: lw          $a3, 0x1214($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X1214);
    // 0x8009B1F0: and         $a1, $a1, $t0
    ctx->r5 = ctx->r5 & ctx->r8;
    // 0x8009B1F4: jal         0x8009BE40
    // 0x8009B1F8: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    func_8009BE40(rdram, ctx);
        goto after_2;
    // 0x8009B1F8: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    after_2:
    // 0x8009B1FC: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8009B200: addiu       $a0, $a0, 0x4650
    ctx->r4 = ADD32(ctx->r4, 0X4650);
    // 0x8009B204: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8009B208: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8009B20C: sw          $v0, 0x120C($s0)
    MEM_W(0X120C, ctx->r16) = ctx->r2;
    // 0x8009B210: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8009B214: sb          $v0, 0x1200($s0)
    MEM_B(0X1200, ctx->r16) = ctx->r2;
    // 0x8009B218: jal         0x80033410
    // 0x8009B21C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x8009B21C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_3:
    // 0x8009B220: jal         0x8009AF60
    // 0x8009B224: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8009AF60(rdram, ctx);
        goto after_4;
    // 0x8009B224: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_4:
    // 0x8009B228: j           L_8009B234
    // 0x8009B22C: nop

        goto L_8009B234;
    // 0x8009B22C: nop

L_8009B230:
    // 0x8009B230: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8009B234:
    // 0x8009B234: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8009B238: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8009B23C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8009B240: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8009B244: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8009B248: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8009B24C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8009B250: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8009B254: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8009B258: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009B25C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8009B260: jr          $ra
    // 0x8009B264: nop

    return;
    // 0x8009B264: nop

;}
RECOMP_FUNC void func_8009B268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B268: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009B26C: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x8009B270: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8009B274: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8009B278: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8009B27C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009B280: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8009B284: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8009B288: sll         $s0, $v0, 3
    ctx->r16 = S32(ctx->r2 << 3);
    // 0x8009B28C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009B290: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B294: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009B298: lbu         $v0, 0x4620($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X4620);
    // 0x8009B29C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8009B2A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8009B2A4: beq         $v1, $v0, L_8009B2BC
    if (ctx->r3 == ctx->r2) {
        // 0x8009B2A8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8009B2BC;
    }
    // 0x8009B2A8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8009B2AC: beq         $v1, $v0, L_8009B2D0
    if (ctx->r3 == ctx->r2) {
        // 0x8009B2B0: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8009B2D0;
    }
    // 0x8009B2B0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8009B2B4: j           L_8009B328
    // 0x8009B2B8: nop

        goto L_8009B328;
    // 0x8009B2B8: nop

L_8009B2BC:
    // 0x8009B2BC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B2C0: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009B2C4: sb          $zero, 0x4620($at)
    MEM_B(0X4620, ctx->r1) = 0;
    // 0x8009B2C8: j           L_8009B328
    // 0x8009B2CC: nop

        goto L_8009B328;
    // 0x8009B2CC: nop

L_8009B2D0:
    // 0x8009B2D0: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8009B2D4: addiu       $a0, $a0, 0x4650
    ctx->r4 = ADD32(ctx->r4, 0X4650);
    // 0x8009B2D8: jal         0x800331D0
    // 0x8009B2DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8009B2DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8009B2E0: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8009B2E4: addiu       $a0, $a0, 0x3420
    ctx->r4 = ADD32(ctx->r4, 0X3420);
    // 0x8009B2E8: jal         0x8009C2BC
    // 0x8009B2EC: addu        $a0, $s0, $a0
    ctx->r4 = ADD32(ctx->r16, ctx->r4);
    func_8009C2BC(rdram, ctx);
        goto after_1;
    // 0x8009B2EC: addu        $a0, $s0, $a0
    ctx->r4 = ADD32(ctx->r16, ctx->r4);
    after_1:
    // 0x8009B2F0: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8009B2F4: addiu       $a0, $a0, 0x4650
    ctx->r4 = ADD32(ctx->r4, 0X4650);
    // 0x8009B2F8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8009B2FC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8009B300: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8009B304: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B308: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009B30C: sb          $v0, 0x4620($at)
    MEM_B(0X4620, ctx->r1) = ctx->r2;
    // 0x8009B310: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8009B314: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B318: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009B31C: sb          $v0, 0x4638($at)
    MEM_B(0X4638, ctx->r1) = ctx->r2;
    // 0x8009B320: jal         0x80033410
    // 0x8009B324: nop

    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8009B324: nop

    after_2:
L_8009B328:
    // 0x8009B328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009B32C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8009B330: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009B334: jr          $ra
    // 0x8009B338: nop

    return;
    // 0x8009B338: nop

;}
RECOMP_FUNC void func_8009B33C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B33C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009B340: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8009B344: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8009B348: beq         $a1, $v0, L_8009B3B8
    if (ctx->r5 == ctx->r2) {
        // 0x8009B34C: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8009B3B8;
    }
    // 0x8009B34C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8009B350: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8009B354: lbu         $v0, 0x5121($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5121);
    // 0x8009B358: beq         $v0, $zero, L_8009B3B8
    if (ctx->r2 == 0) {
        // 0x8009B35C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8009B3B8;
    }
    // 0x8009B35C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8009B360: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8009B364:
    // 0x8009B364: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B368: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8009B36C: lbu         $v0, 0x4620($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X4620);
    // 0x8009B370: beql        $v0, $zero, L_8009B390
    if (ctx->r2 == 0) {
        // 0x8009B374: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8009B390;
    }
    goto skip_0;
    // 0x8009B374: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x8009B378: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B37C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8009B380: lw          $v0, 0x4644($at)
    ctx->r2 = MEM_W(ctx->r1, 0X4644);
    // 0x8009B384: beq         $v0, $a1, L_8009B3A0
    if (ctx->r2 == ctx->r5) {
        // 0x8009B388: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8009B3A0;
    }
    // 0x8009B388: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8009B38C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8009B390:
    // 0x8009B390: beq         $a0, $zero, L_8009B364
    if (ctx->r4 == 0) {
        // 0x8009B394: addiu       $v1, $v1, 0x1228
        ctx->r3 = ADD32(ctx->r3, 0X1228);
            goto L_8009B364;
    }
    // 0x8009B394: addiu       $v1, $v1, 0x1228
    ctx->r3 = ADD32(ctx->r3, 0X1228);
    // 0x8009B398: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8009B39C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8009B3A0:
    // 0x8009B3A0: beq         $a0, $v0, L_8009B3BC
    if (ctx->r4 == ctx->r2) {
        // 0x8009B3A4: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8009B3BC;
    }
    // 0x8009B3A4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8009B3A8: jal         0x8009B268
    // 0x8009B3AC: nop

    func_8009B268(rdram, ctx);
        goto after_0;
    // 0x8009B3AC: nop

    after_0:
    // 0x8009B3B0: j           L_8009B3BC
    // 0x8009B3B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8009B3BC;
    // 0x8009B3B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8009B3B8:
    // 0x8009B3B8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8009B3BC:
    // 0x8009B3BC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8009B3C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009B3C4: jr          $ra
    // 0x8009B3C8: nop

    return;
    // 0x8009B3C8: nop

;}
RECOMP_FUNC void func_8009B3CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B3CC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8009B3D0: lbu         $v0, 0x5121($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5121);
    // 0x8009B3D4: beq         $v0, $zero, L_8009B458
    if (ctx->r2 == 0) {
        // 0x8009B3D8: addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
            goto L_8009B458;
    }
    // 0x8009B3D8: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8009B3DC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8009B3E0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8009B3E4:
    // 0x8009B3E4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B3E8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8009B3EC: lbu         $v0, 0x4620($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X4620);
    // 0x8009B3F0: beql        $v0, $zero, L_8009B410
    if (ctx->r2 == 0) {
        // 0x8009B3F4: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8009B410;
    }
    goto skip_0;
    // 0x8009B3F4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x8009B3F8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B3FC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8009B400: lw          $v0, 0x4644($at)
    ctx->r2 = MEM_W(ctx->r1, 0X4644);
    // 0x8009B404: beql        $v0, $a1, L_8009B420
    if (ctx->r2 == ctx->r5) {
        // 0x8009B408: addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
            goto L_8009B420;
    }
    goto skip_1;
    // 0x8009B408: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    skip_1:
    // 0x8009B40C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8009B410:
    // 0x8009B410: beq         $a0, $zero, L_8009B3E4
    if (ctx->r4 == 0) {
        // 0x8009B414: addiu       $v1, $v1, 0x1228
        ctx->r3 = ADD32(ctx->r3, 0X1228);
            goto L_8009B3E4;
    }
    // 0x8009B414: addiu       $v1, $v1, 0x1228
    ctx->r3 = ADD32(ctx->r3, 0X1228);
    // 0x8009B418: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8009B41C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
L_8009B420:
    // 0x8009B420: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8009B424: beq         $a1, $v0, L_8009B458
    if (ctx->r5 == ctx->r2) {
        // 0x8009B428: sll         $v0, $a1, 3
        ctx->r2 = S32(ctx->r5 << 3);
            goto L_8009B458;
    }
    // 0x8009B428: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x8009B42C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8009B430: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8009B434: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8009B438: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009B43C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8009B440: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8009B444: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B448: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8009B44C: lbu         $v0, 0x4620($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X4620);
    // 0x8009B450: j           L_8009B45C
    // 0x8009B454: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
        goto L_8009B45C;
    // 0x8009B454: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
L_8009B458:
    // 0x8009B458: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8009B45C:
    // 0x8009B45C: jr          $ra
    // 0x8009B460: nop

    return;
    // 0x8009B460: nop

;}
RECOMP_FUNC void func_8009B464(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B464: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8009B468: lbu         $v0, 0x5121($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5121);
    // 0x8009B46C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8009B470: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8009B474: lbu         $s5, 0x4B($sp)
    ctx->r21 = MEM_BU(ctx->r29, 0X4B);
    // 0x8009B478: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8009B47C: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x8009B480: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8009B484: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x8009B488: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009B48C: addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    // 0x8009B490: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x8009B494: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8009B498: beq         $v0, $zero, L_8009B57C
    if (ctx->r2 == 0) {
        // 0x8009B49C: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8009B57C;
    }
    // 0x8009B49C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009B4A0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8009B4A4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8009B4A8:
    // 0x8009B4A8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B4AC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8009B4B0: lbu         $v0, 0x4620($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X4620);
    // 0x8009B4B4: beql        $v0, $zero, L_8009B4D4
    if (ctx->r2 == 0) {
        // 0x8009B4B8: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8009B4D4;
    }
    goto skip_0;
    // 0x8009B4B8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_0:
    // 0x8009B4BC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B4C0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8009B4C4: lw          $v0, 0x4644($at)
    ctx->r2 = MEM_W(ctx->r1, 0X4644);
    // 0x8009B4C8: beq         $v0, $a0, L_8009B4E0
    if (ctx->r2 == ctx->r4) {
        // 0x8009B4CC: addu        $s0, $a1, $zero
        ctx->r16 = ADD32(ctx->r5, 0);
            goto L_8009B4E0;
    }
    // 0x8009B4CC: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x8009B4D0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8009B4D4:
    // 0x8009B4D4: beq         $a1, $zero, L_8009B4A8
    if (ctx->r5 == 0) {
        // 0x8009B4D8: addiu       $v1, $v1, 0x1228
        ctx->r3 = ADD32(ctx->r3, 0X1228);
            goto L_8009B4A8;
    }
    // 0x8009B4D8: addiu       $v1, $v1, 0x1228
    ctx->r3 = ADD32(ctx->r3, 0X1228);
    // 0x8009B4DC: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
L_8009B4E0:
    // 0x8009B4E0: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x8009B4E4: beq         $s0, $s1, L_8009B57C
    if (ctx->r16 == ctx->r17) {
        // 0x8009B4E8: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8009B57C;
    }
    // 0x8009B4E8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8009B4EC: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8009B4F0: addiu       $a0, $a0, 0x4650
    ctx->r4 = ADD32(ctx->r4, 0X4650);
    // 0x8009B4F4: jal         0x800331D0
    // 0x8009B4F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8009B4F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8009B4FC: sll         $v0, $s0, 3
    ctx->r2 = S32(ctx->r16 << 3);
    // 0x8009B500: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8009B504: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8009B508: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8009B50C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009B510: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8009B514: sll         $s0, $v0, 3
    ctx->r16 = S32(ctx->r2 << 3);
    // 0x8009B518: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B51C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009B520: lw          $a0, 0x462C($at)
    ctx->r4 = MEM_W(ctx->r1, 0X462C);
    // 0x8009B524: beq         $a0, $s1, L_8009B53C
    if (ctx->r4 == ctx->r17) {
        // 0x8009B528: andi        $a1, $s4, 0xFF
        ctx->r5 = ctx->r20 & 0XFF;
            goto L_8009B53C;
    }
    // 0x8009B528: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    // 0x8009B52C: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x8009B530: andi        $a2, $s3, 0xFF
    ctx->r6 = ctx->r19 & 0XFF;
    // 0x8009B534: jal         0x800981F0
    // 0x8009B538: andi        $a3, $s2, 0xFF
    ctx->r7 = ctx->r18 & 0XFF;
    func_800981F0(rdram, ctx);
        goto after_1;
    // 0x8009B538: andi        $a3, $s2, 0xFF
    ctx->r7 = ctx->r18 & 0XFF;
    after_1:
L_8009B53C:
    // 0x8009B53C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8009B540: addiu       $a0, $a0, 0x4650
    ctx->r4 = ADD32(ctx->r4, 0X4650);
    // 0x8009B544: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8009B548: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B54C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009B550: sb          $s3, 0x4622($at)
    MEM_B(0X4622, ctx->r1) = ctx->r19;
    // 0x8009B554: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B558: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009B55C: sb          $s2, 0x4623($at)
    MEM_B(0X4623, ctx->r1) = ctx->r18;
    // 0x8009B560: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B564: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009B568: sb          $s4, 0x4621($at)
    MEM_B(0X4621, ctx->r1) = ctx->r20;
    // 0x8009B56C: jal         0x80033410
    // 0x8009B570: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8009B570: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_2:
    // 0x8009B574: j           L_8009B580
    // 0x8009B578: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8009B580;
    // 0x8009B578: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8009B57C:
    // 0x8009B57C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8009B580:
    // 0x8009B580: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x8009B584: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8009B588: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8009B58C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8009B590: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8009B594: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8009B598: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009B59C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8009B5A0: jr          $ra
    // 0x8009B5A4: nop

    return;
    // 0x8009B5A4: nop

;}
RECOMP_FUNC void func_8009B5A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    {
        static int n=0;
        ++n;
        // Bumped throttle: print first 8 + every 64th to see actual tick rate
        // (was n<=3 — masked the steady-state cadence).
        // Cinematic-driver tick trace. Fires every cinematic frame during
        // playback. Useful when investigating the cinematic_drv message
        // queue / state-machine. Default off — gate on ROGUESQ_LOG_DPC.
        // (funcs_26.c is C, not C++, so the gate is a manual init.)
        static int log_cd_init = 0;
        static int log_cd = 0;
        if (!log_cd_init) {
            const char *a = getenv("ROGUESQ_LOG_ALL");
            const char *e = getenv("ROGUESQ_LOG_DPC");
            log_cd = ((a && *a && *a != '0') || (e && *e && *e != '0')) ? 1 : 0;
            log_cd_init = 1;
        }
        if (log_cd && (n<=8 || (n & 63) == 0)) {
            // Read per-stage state bytes at MIPS 0x80154620 + i*0x1228 for stages 0-4.
            uint8_t s0 = *(uint8_t*)(rdram + (size_t)((0x80154620u ^ 3) & 0x7FFFFFFFu));
            uint8_t s1 = *(uint8_t*)(rdram + (size_t)(((0x80154620u + 0x1228u) ^ 3) & 0x7FFFFFFFu));
            uint8_t s2 = *(uint8_t*)(rdram + (size_t)(((0x80154620u + 0x2450u) ^ 3) & 0x7FFFFFFFu));
            uint8_t s3 = *(uint8_t*)(rdram + (size_t)(((0x80154620u + 0x3678u) ^ 3) & 0x7FFFFFFFu));
            uint8_t s4 = *(uint8_t*)(rdram + (size_t)(((0x80154620u + 0x48A0u) ^ 3) & 0x7FFFFFFFu));
            fprintf(stderr, "[trace] cinematic_drv ENTRY #%d stage_states=[%02X %02X %02X %02X %02X]\n",
                n, (unsigned)s0, (unsigned)s1, (unsigned)s2, (unsigned)s3, (unsigned)s4);
            fflush(stderr);
        }
        // ROGUESQ_FORCE_STAGE_ACTIVATE=1 — diagnostic: at first cinematic_drv tick
        // after entry, force all 5 stages from state 0 to state 1 once. If the
        // cinematic_drv state machine then advances 1->2 and func_80098298
        // starts firing, we've proved the activation handshake is the only
        // missing link. If it crashes / produces nonsense, stages need more
        // setup than just the state byte (possibly the struct[0] field at
        // -0x23 from state byte and others).
        {
            static int once = 0;
            if (!once) {
                const char *e = getenv("ROGUESQ_FORCE_STAGE_ACTIVATE");
                if (e && *e && *e != '0' && n >= 5) {
                    once = 1;
                    for (int i = 0; i < 5; ++i) {
                        uint32_t addr = 0x80154620u + (uint32_t)i * 0x1228u;
                        uint8_t *p = (uint8_t*)(rdram + (size_t)((addr ^ 3) & 0x7FFFFFFFu));
                        *p = 1;
                    }
                    fprintf(stderr, "[force] wrote stage state = 1 to all 5 stages\n");
                    fflush(stderr);
                }
            }
        }
        // Watch rdram[0x3CBC4] (first corrupted word). Log when it changes.
        static uint32_t last_word = 0;
        static int initialized = 0;
        uint32_t cur = *(uint32_t*)(rdram + 0x3CBC4);
        if (!initialized) {
            initialized = 1;
            last_word = cur;
            fprintf(stderr, "[wp] cinematic_drv #%d: initial rdram@0x3CBC4 = 0x%08X\n", n, cur);
            fflush(stderr);
        } else if (cur != last_word) {
            fprintf(stderr, "[wp] cinematic_drv #%d: rdram@0x3CBC4 CHANGED 0x%08X -> 0x%08X\n", n, last_word, cur);
            fflush(stderr);
            last_word = cur;
        }
    }
    // 0x8009B5A8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8009B5AC: lbu         $v0, 0x5121($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5121);
    // 0x8009B5B0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8009B5B4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8009B5B8: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8009B5BC: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8009B5C0: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8009B5C4: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8009B5C8: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8009B5CC: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8009B5D0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8009B5D4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8009B5D8: beq         $v0, $zero, L_8009B874
    if (ctx->r2 == 0) {
        // 0x8009B5DC: sw          $s0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r16;
            goto L_8009B874;
    }
    // 0x8009B5DC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8009B5E0: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8009B5E4: addiu       $a0, $a0, 0x4650
    ctx->r4 = ADD32(ctx->r4, 0X4650);
    // 0x8009B5E8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    {
        // Pre-recv trace. Same gate as ENTRY trace above (ROGUESQ_LOG_DPC).
        static int n=0; ++n;
        static int log_cd_init = 0;
        static int log_cd = 0;
        if (!log_cd_init) {
            const char *a = getenv("ROGUESQ_LOG_ALL");
            const char *e = getenv("ROGUESQ_LOG_DPC");
            log_cd = ((a && *a && *a != '0') || (e && *e && *e != '0')) ? 1 : 0;
            log_cd_init = 1;
        }
        if (log_cd && (n<=8 || (n & 63) == 0)) { fprintf(stderr, "[trace] cinematic_drv #%d BEFORE recv\n", n); fflush(stderr); }
    }
    // 0x8009B5EC: jal         0x800331D0
    // 0x8009B5F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8009B5F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    {
        // Post-recv trace. Same gate as ENTRY trace above (ROGUESQ_LOG_DPC).
        static int n=0; ++n;
        static int log_cd_init = 0;
        static int log_cd = 0;
        if (!log_cd_init) {
            const char *a = getenv("ROGUESQ_LOG_ALL");
            const char *e = getenv("ROGUESQ_LOG_DPC");
            log_cd = ((a && *a && *a != '0') || (e && *e && *e != '0')) ? 1 : 0;
            log_cd_init = 1;
        }
        if (log_cd && (n<=8 || (n & 63) == 0)) { fprintf(stderr, "[trace] cinematic_drv #%d AFTER recv (got mutex)\n", n); fflush(stderr); }
    }
    // 0x8009B5F4: jal         0x8002BF00
    // 0x8009B5F8: addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    osGetTime_recomp(rdram, ctx);
        goto after_1;
    // 0x8009B5F8: addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    after_1:
    // 0x8009B5FC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B600: sw          $v1, 0x466C($at)
    MEM_W(0X466C, ctx->r1) = ctx->r3;
    // 0x8009B604: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x8009B608: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x8009B60C: lui         $s2, 0x8015
    ctx->r18 = S32(0X8015 << 16);
    // 0x8009B610: addiu       $s2, $s2, 0x4638
    ctx->r18 = ADD32(ctx->r18, 0X4638);
    // 0x8009B614: addiu       $s5, $s2, -0xC
    ctx->r21 = ADD32(ctx->r18, -0XC);
    // 0x8009B618: addiu       $s4, $s2, -0x3B
    ctx->r20 = ADD32(ctx->r18, -0X3B);
    // 0x8009B61C: addiu       $s3, $s2, -0x10
    ctx->r19 = ADD32(ctx->r18, -0X10);
    // 0x8009B620: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8009B624:
    // 0x8009B624: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B628: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009B62C: lbu         $v0, 0x4620($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X4620);
    // 0x8009B630: beql        $v0, $zero, L_8009B824
    if (ctx->r2 == 0) {
        // 0x8009B634: addiu       $s2, $s2, 0x1228
        ctx->r18 = ADD32(ctx->r18, 0X1228);
            goto L_8009B824;
    }
    goto skip_0;
    // 0x8009B634: addiu       $s2, $s2, 0x1228
    ctx->r18 = ADD32(ctx->r18, 0X1228);
    skip_0:
    // 0x8009B638: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8009B63C: addiu       $v0, $v0, 0x3420
    ctx->r2 = ADD32(ctx->r2, 0X3420);
    // 0x8009B640: addu        $s1, $s0, $v0
    ctx->r17 = ADD32(ctx->r16, ctx->r2);
    // 0x8009B644: jal         0x8009BF14
    // 0x8009B648: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8009BF14(rdram, ctx);
        goto after_2;
    // 0x8009B648: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
    // 0x8009B64C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B650: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009B654: lbu         $v0, 0x4620($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X4620);
    // 0x8009B658: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8009B65C: beq         $v1, $s7, L_8009B7B4
    if (ctx->r3 == ctx->r23) {
        // 0x8009B660: slti        $v0, $v1, 0x3
        ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_8009B7B4;
    }
    // 0x8009B660: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8009B664: beq         $v0, $zero, L_8009B67C
    if (ctx->r2 == 0) {
        // 0x8009B668: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8009B67C;
    }
    // 0x8009B668: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8009B66C: beq         $v1, $v0, L_8009B690
    if (ctx->r3 == ctx->r2) {
        // 0x8009B670: nop
    
            goto L_8009B690;
    }
    // 0x8009B670: nop

    // 0x8009B674: j           L_8009B824
    // 0x8009B678: addiu       $s2, $s2, 0x1228
    ctx->r18 = ADD32(ctx->r18, 0X1228);
        goto L_8009B824;
    // 0x8009B678: addiu       $s2, $s2, 0x1228
    ctx->r18 = ADD32(ctx->r18, 0X1228);
L_8009B67C:
    // 0x8009B67C: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8009B680: beq         $v1, $t0, L_8009B7D8
    if (ctx->r3 == ctx->r8) {
        // 0x8009B684: nop
    
            goto L_8009B7D8;
    }
    // 0x8009B684: nop

    // 0x8009B688: j           L_8009B824
    // 0x8009B68C: addiu       $s2, $s2, 0x1228
    ctx->r18 = ADD32(ctx->r18, 0X1228);
        goto L_8009B824;
    // 0x8009B68C: addiu       $s2, $s2, 0x1228
    ctx->r18 = ADD32(ctx->r18, 0X1228);
L_8009B690:
    // 0x8009B690: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x8009B694: bnel        $v0, $s7, L_8009B824
    if (ctx->r2 != ctx->r23) {
        // 0x8009B698: addiu       $s2, $s2, 0x1228
        ctx->r18 = ADD32(ctx->r18, 0X1228);
            goto L_8009B824;
    }
    goto skip_1;
    // 0x8009B698: addiu       $s2, $s2, 0x1228
    ctx->r18 = ADD32(ctx->r18, 0X1228);
    skip_1:
    // 0x8009B69C: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8009B6A0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B6A4: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009B6A8: lhu         $v0, 0x45C0($at)
    ctx->r2 = MEM_HU(ctx->r1, 0X45C0);
    // 0x8009B6AC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8009B6B0: lwc1        $f2, -0x2100($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2100);
    // 0x8009B6B4: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8009B6B8: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x8009B6BC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8009B6C0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8009B6C4: mul.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8009B6C8: bgez        $v1, L_8009B6DC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8009B6CC: nop
    
            goto L_8009B6DC;
    }
    // 0x8009B6CC: nop

    // 0x8009B6D0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8009B6D4: ldc1        $f0, -0x20F8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X20F8);
    // 0x8009B6D8: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
L_8009B6DC:
    // 0x8009B6DC: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x8009B6E0: div.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8009B6E4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B6E8: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009B6EC: sw          $zero, 0x463C($at)
    MEM_W(0X463C, ctx->r1) = 0;
    // 0x8009B6F0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B6F4: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009B6F8: sb          $s7, 0x4620($at)
    MEM_B(0X4620, ctx->r1) = ctx->r23;
    // 0x8009B6FC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B700: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009B704: swc1        $f0, 0x4640($at)
    MEM_W(0X4640, ctx->r1) = ctx->f0.u32l;
    // 0x8009B708: jal         0x8009C2A0
    // 0x8009B70C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8009C2A0(rdram, ctx);
        goto after_3;
    // 0x8009B70C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_3:
    // 0x8009B710: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B714: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009B718: lbu         $v0, 0x4621($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X4621);
    // 0x8009B71C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B720: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009B724: lbu         $a0, 0x4624($at)
    ctx->r4 = MEM_BU(ctx->r1, 0X4624);
    // 0x8009B728: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B72C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009B730: lw          $a1, 0x4630($at)
    ctx->r5 = MEM_W(ctx->r1, 0X4630);
    // 0x8009B734: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B738: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009B73C: lw          $a2, 0x4634($at)
    ctx->r6 = MEM_W(ctx->r1, 0X4634);
    // 0x8009B740: lw          $a3, 0x0($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X0);
    // 0x8009B744: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8009B748: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B74C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009B750: lbu         $v0, 0x4622($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X4622);
    // 0x8009B754: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8009B758: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B75C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009B760: lbu         $v0, 0x4623($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X4623);
    // 0x8009B764: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8009B768: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B76C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009B770: lbu         $v1, 0x4639($at)
    ctx->r3 = MEM_BU(ctx->r1, 0X4639);
    // 0x8009B774: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8009B778: addiu       $v0, $v0, -0x4284
    ctx->r2 = ADD32(ctx->r2, -0X4284);
    // 0x8009B77C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8009B780: sw          $s6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r22;
    // 0x8009B784: jal         0x80097FE8
    // 0x8009B788: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80097FE8(rdram, ctx);
        goto after_4;
    // 0x8009B788: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_4:
    // 0x8009B78C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8009B790: bne         $v0, $t0, L_8009B820
    if (ctx->r2 != ctx->r8) {
        // 0x8009B794: sw          $v0, 0x120C($s1)
        MEM_W(0X120C, ctx->r17) = ctx->r2;
            goto L_8009B820;
    }
    // 0x8009B794: sw          $v0, 0x120C($s1)
    MEM_W(0X120C, ctx->r17) = ctx->r2;
    // 0x8009B798: jal         0x8009C2BC
    // 0x8009B79C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8009C2BC(rdram, ctx);
        goto after_5;
    // 0x8009B79C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_5:
    // 0x8009B7A0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B7A4: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009B7A8: sb          $zero, 0x4620($at)
    MEM_B(0X4620, ctx->r1) = 0;
    // 0x8009B7AC: j           L_8009B824
    // 0x8009B7B0: addiu       $s2, $s2, 0x1228
    ctx->r18 = ADD32(ctx->r18, 0X1228);
        goto L_8009B824;
    // 0x8009B7B0: addiu       $s2, $s2, 0x1228
    ctx->r18 = ADD32(ctx->r18, 0X1228);
L_8009B7B4:
    // 0x8009B7B4: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x8009B7B8: bnel        $v0, $fp, L_8009B824
    if (ctx->r2 != ctx->r30) {
        // 0x8009B7BC: addiu       $s2, $s2, 0x1228
        ctx->r18 = ADD32(ctx->r18, 0X1228);
            goto L_8009B824;
    }
    goto skip_2;
    // 0x8009B7BC: addiu       $s2, $s2, 0x1228
    ctx->r18 = ADD32(ctx->r18, 0X1228);
    skip_2:
    // 0x8009B7C0: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8009B7C4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B7C8: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009B7CC: sb          $t0, 0x4620($at)
    MEM_B(0X4620, ctx->r1) = ctx->r8;
    // 0x8009B7D0: j           L_8009B820
    // 0x8009B7D4: sb          $fp, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r30;
        goto L_8009B820;
    // 0x8009B7D4: sb          $fp, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r30;
L_8009B7D8:
    // 0x8009B7D8: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x8009B7DC: bne         $v0, $zero, L_8009B7F8
    if (ctx->r2 != 0) {
        // 0x8009B7E0: nop
    
            goto L_8009B7F8;
    }
    // 0x8009B7E0: nop

    // 0x8009B7E4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B7E8: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009B7EC: sb          $zero, 0x4620($at)
    MEM_B(0X4620, ctx->r1) = 0;
    // 0x8009B7F0: j           L_8009B824
    // 0x8009B7F4: addiu       $s2, $s2, 0x1228
    ctx->r18 = ADD32(ctx->r18, 0X1228);
        goto L_8009B824;
    // 0x8009B7F4: addiu       $s2, $s2, 0x1228
    ctx->r18 = ADD32(ctx->r18, 0X1228);
L_8009B7F8:
    // 0x8009B7F8: bne         $v0, $s7, L_8009B814
    if (ctx->r2 != ctx->r23) {
        // 0x8009B7FC: nop
    
            goto L_8009B814;
    }
    // 0x8009B7FC: nop

    // 0x8009B800: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x8009B804: jal         0x80098298
    // 0x8009B808: nop

    func_80098298(rdram, ctx);
        goto after_6;
    // 0x8009B808: nop

    after_6:
    // 0x8009B80C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8009B810: sw          $t0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r8;
L_8009B814:
    // 0x8009B814: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x8009B818: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009B81C: sb          $v0, 0x1218($s1)
    MEM_B(0X1218, ctx->r17) = ctx->r2;
L_8009B820:
    // 0x8009B820: addiu       $s2, $s2, 0x1228
    ctx->r18 = ADD32(ctx->r18, 0X1228);
L_8009B824:
    // 0x8009B824: addiu       $s5, $s5, 0x1228
    ctx->r21 = ADD32(ctx->r21, 0X1228);
    // 0x8009B828: addiu       $s4, $s4, 0x1228
    ctx->r20 = ADD32(ctx->r20, 0X1228);
    // 0x8009B82C: addiu       $s3, $s3, 0x1228
    ctx->r19 = ADD32(ctx->r19, 0X1228);
    // 0x8009B830: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x8009B834: blez        $s6, L_8009B624
    if (SIGNED(ctx->r22) <= 0) {
        // 0x8009B838: addiu       $s0, $s0, 0x1228
        ctx->r16 = ADD32(ctx->r16, 0X1228);
            goto L_8009B624;
    }
    // 0x8009B838: addiu       $s0, $s0, 0x1228
    ctx->r16 = ADD32(ctx->r16, 0X1228);
    // 0x8009B83C: jal         0x8002BF00
    // 0x8009B840: nop

    osGetTime_recomp(rdram, ctx);
        goto after_7;
    // 0x8009B840: nop

    after_7:
    // 0x8009B844: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8009B848: addiu       $a0, $a0, 0x4650
    ctx->r4 = ADD32(ctx->r4, 0X4650);
    // 0x8009B84C: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x8009B850: lw          $a3, 0x466C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X466C);
    // 0x8009B854: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8009B858: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B85C: sw          $v1, 0x4680($at)
    MEM_W(0X4680, ctx->r1) = ctx->r3;
    // 0x8009B860: subu        $a3, $v1, $a3
    ctx->r7 = SUB32(ctx->r3, ctx->r7);
    // 0x8009B864: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B868: sw          $a3, 0x4678($at)
    MEM_W(0X4678, ctx->r1) = ctx->r7;
    // 0x8009B86C: jal         0x80033410
    // 0x8009B870: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_8;
    // 0x8009B870: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_8:
L_8009B874:
    // 0x8009B874: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8009B878: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8009B87C: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8009B880: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8009B884: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8009B888: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8009B88C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8009B890: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8009B894: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8009B898: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8009B89C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8009B8A0: jr          $ra
    // 0x8009B8A4: nop

    return;
    // 0x8009B8A4: nop

;}
RECOMP_FUNC void func_8009B8A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B8A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009B8AC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8009B8B0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8009B8B4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8009B8B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8009B8BC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8009B8C0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8009B8C4: beq         $s0, $v0, L_8009BA18
    if (ctx->r16 == ctx->r2) {
        // 0x8009B8C8: addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
            goto L_8009BA18;
    }
    // 0x8009B8C8: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x8009B8CC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8009B8D0: lbu         $v0, 0x5121($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5121);
    // 0x8009B8D4: beq         $v0, $zero, L_8009BA18
    if (ctx->r2 == 0) {
        // 0x8009B8D8: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8009BA18;
    }
    // 0x8009B8D8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8009B8DC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8009B8E0:
    // 0x8009B8E0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B8E4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8009B8E8: lbu         $v0, 0x4620($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X4620);
    // 0x8009B8EC: beql        $v0, $zero, L_8009B90C
    if (ctx->r2 == 0) {
        // 0x8009B8F0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8009B90C;
    }
    goto skip_0;
    // 0x8009B8F0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x8009B8F4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B8F8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8009B8FC: lw          $v0, 0x4644($at)
    ctx->r2 = MEM_W(ctx->r1, 0X4644);
    // 0x8009B900: beql        $v0, $s0, L_8009B91C
    if (ctx->r2 == ctx->r16) {
        // 0x8009B904: addu        $s0, $a0, $zero
        ctx->r16 = ADD32(ctx->r4, 0);
            goto L_8009B91C;
    }
    goto skip_1;
    // 0x8009B904: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    skip_1:
    // 0x8009B908: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8009B90C:
    // 0x8009B90C: beq         $a0, $zero, L_8009B8E0
    if (ctx->r4 == 0) {
        // 0x8009B910: addiu       $v1, $v1, 0x1228
        ctx->r3 = ADD32(ctx->r3, 0X1228);
            goto L_8009B8E0;
    }
    // 0x8009B910: addiu       $v1, $v1, 0x1228
    ctx->r3 = ADD32(ctx->r3, 0X1228);
    // 0x8009B914: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8009B918: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
L_8009B91C:
    // 0x8009B91C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8009B920: beq         $s0, $v0, L_8009BA18
    if (ctx->r16 == ctx->r2) {
        // 0x8009B924: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8009BA18;
    }
    // 0x8009B924: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8009B928: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8009B92C: addiu       $a0, $a0, 0x4650
    ctx->r4 = ADD32(ctx->r4, 0X4650);
    // 0x8009B930: jal         0x800331D0
    // 0x8009B934: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8009B934: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8009B938: sll         $v0, $s0, 3
    ctx->r2 = S32(ctx->r16 << 3);
    // 0x8009B93C: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8009B940: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8009B944: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8009B948: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009B94C: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8009B950: sll         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2 << 3);
    // 0x8009B954: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B958: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8009B95C: lbu         $v0, 0x4620($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X4620);
    // 0x8009B960: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8009B964: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8009B968: bne         $v0, $v1, L_8009B9CC
    if (ctx->r2 != ctx->r3) {
        // 0x8009B96C: nop
    
            goto L_8009B9CC;
    }
    // 0x8009B96C: nop

    // 0x8009B970: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B974: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8009B978: lw          $v0, 0x463C($at)
    ctx->r2 = MEM_W(ctx->r1, 0X463C);
    // 0x8009B97C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8009B980: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x8009B984: bgez        $v0, L_8009B998
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8009B988: nop
    
            goto L_8009B998;
    }
    // 0x8009B988: nop

    // 0x8009B98C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8009B990: ldc1        $f0, -0x20F0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X20F0);
    // 0x8009B994: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
L_8009B998:
    // 0x8009B998: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B99C: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8009B9A0: lw          $v0, 0x4628($at)
    ctx->r2 = MEM_W(ctx->r1, 0X4628);
    // 0x8009B9A4: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8009B9A8: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x8009B9AC: bgez        $v0, L_8009B9C0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8009B9B0: cvt.s.d     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f4.fl = CVT_S_D(ctx->f4.d);
            goto L_8009B9C0;
    }
    // 0x8009B9B0: cvt.s.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f4.fl = CVT_S_D(ctx->f4.d);
    // 0x8009B9B4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8009B9B8: ldc1        $f0, -0x20E8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X20E8);
    // 0x8009B9BC: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
L_8009B9C0:
    // 0x8009B9C0: cvt.s.d     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
    // 0x8009B9C4: j           L_8009B9D0
    // 0x8009B9C8: div.s       $f20, $f4, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
        goto L_8009B9D0;
    // 0x8009B9C8: div.s       $f20, $f4, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
L_8009B9CC:
    // 0x8009B9CC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
L_8009B9D0:
    // 0x8009B9D0: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8009B9D4: addiu       $a0, $a0, 0x4650
    ctx->r4 = ADD32(ctx->r4, 0X4650);
    // 0x8009B9D8: sll         $v0, $s0, 3
    ctx->r2 = S32(ctx->r16 << 3);
    // 0x8009B9DC: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8009B9E0: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8009B9E4: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8009B9E8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8009B9EC: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8009B9F0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8009B9F4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009B9F8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8009B9FC: lwc1        $f0, 0x4640($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X4640);
    // 0x8009BA00: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8009BA04: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8009BA08: jal         0x80033410
    // 0x8009BA0C: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8009BA0C: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    after_1:
    // 0x8009BA10: j           L_8009BA1C
    // 0x8009BA14: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
        goto L_8009BA1C;
    // 0x8009BA14: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_8009BA18:
    // 0x8009BA18: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8009BA1C:
    // 0x8009BA1C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8009BA20: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8009BA24: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8009BA28: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8009BA2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8009BA30: jr          $ra
    // 0x8009BA34: nop

    return;
    // 0x8009BA34: nop

;}
