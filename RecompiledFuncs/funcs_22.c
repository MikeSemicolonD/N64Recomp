#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8008872C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008872C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80088730: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80088734: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80088738: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8008873C: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80088740: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80088744: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80088748: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8008874C: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80088750: beq         $v0, $zero, L_80088774
    if (ctx->r2 == 0) {
        // 0x80088754: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80088774;
    }
    // 0x80088754: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80088758: jal         0x80092010
    // 0x8008875C: nop

    func_80092010(rdram, ctx);
        goto after_0;
    // 0x8008875C: nop

    after_0:
    // 0x80088760: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80088764: jal         0x800885AC
    // 0x80088768: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    func_800885AC(rdram, ctx);
        goto after_1;
    // 0x80088768: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    after_1:
    // 0x8008876C: jal         0x8009205C
    // 0x80088770: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    func_8009205C(rdram, ctx);
        goto after_2;
    // 0x80088770: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_2:
L_80088774:
    // 0x80088774: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x80088778: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008877C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80088780: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80088784: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80088788: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008878C: jr          $ra
    // 0x80088790: nop

    return;
    // 0x80088790: nop

;}
RECOMP_FUNC void func_80088794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088794: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80088798: beql        $a0, $a3, L_800887EC
    if (ctx->r4 == ctx->r7) {
        // 0x8008879C: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_800887EC;
    }
    goto skip_0;
    // 0x8008879C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    skip_0:
    // 0x800887A0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800887A4: lw          $v1, -0x5100($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5100);
    // 0x800887A8: beq         $v1, $zero, L_800887D0
    if (ctx->r3 == 0) {
        // 0x800887AC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800887D0;
    }
    // 0x800887AC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800887B0:
    // 0x800887B0: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800887B4: beq         $v0, $a0, L_800887E4
    if (ctx->r2 == ctx->r4) {
        // 0x800887B8: sltu        $v0, $a0, $v0
        ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
            goto L_800887E4;
    }
    // 0x800887B8: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x800887BC: bne         $v0, $zero, L_800887D0
    if (ctx->r2 != 0) {
        // 0x800887C0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800887D0;
    }
    // 0x800887C0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800887C4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800887C8: bne         $v1, $zero, L_800887B0
    if (ctx->r3 != 0) {
        // 0x800887CC: nop
    
            goto L_800887B0;
    }
    // 0x800887CC: nop

L_800887D0:
    // 0x800887D0: beq         $v0, $zero, L_800887EC
    if (ctx->r2 == 0) {
        // 0x800887D4: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_800887EC;
    }
    // 0x800887D4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800887D8: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x800887DC: j           L_800887F0
    // 0x800887E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800887F0;
    // 0x800887E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800887E4:
    // 0x800887E4: j           L_800887D0
    // 0x800887E8: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_800887D0;
    // 0x800887E8: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_800887EC:
    // 0x800887EC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800887F0:
    // 0x800887F0: beq         $a0, $v0, L_80088A1C
    if (ctx->r4 == ctx->r2) {
        // 0x800887F4: nop
    
            goto L_80088A1C;
    }
    // 0x800887F4: nop

    // 0x800887F8: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800887FC: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x80088800: addiu       $t3, $t3, 0x40C8
    ctx->r11 = ADD32(ctx->r11, 0X40C8);
    // 0x80088804: srl         $v0, $a1, 7
    ctx->r2 = S32(U32(ctx->r5) >> 7);
    // 0x80088808: andi        $t1, $v0, 0x7F
    ctx->r9 = ctx->r2 & 0X7F;
    // 0x8008880C: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80088810: addiu       $t2, $t2, 0xA10
    ctx->r10 = ADD32(ctx->r10, 0XA10);
    // 0x80088814: andi        $t0, $a1, 0x7F
    ctx->r8 = ctx->r5 & 0X7F;
L_80088818:
    // 0x80088818: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x8008881C: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x80088820: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80088824: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80088828: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x8008882C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80088830: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088834: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80088838: lw          $v0, -0x271C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X271C);
    // 0x8008883C: bne         $v0, $a0, L_80088A1C
    if (ctx->r2 != ctx->r4) {
        // 0x80088840: nop
    
            goto L_80088A1C;
    }
    // 0x80088840: nop

    // 0x80088844: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088848: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008884C: lw          $v0, -0x275C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X275C);
    // 0x80088850: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80088854: beq         $v0, $zero, L_800888FC
    if (ctx->r2 == 0) {
        // 0x80088858: nop
    
            goto L_800888FC;
    }
    // 0x80088858: nop

    // 0x8008885C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088860: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80088864: lbu         $a1, -0x2727($at)
    ctx->r5 = MEM_BU(ctx->r1, -0X2727);
    // 0x80088868: beq         $a1, $t4, L_800888AC
    if (ctx->r5 == ctx->r12) {
        // 0x8008886C: addu        $v1, $a2, $zero
        ctx->r3 = ADD32(ctx->r6, 0);
            goto L_800888AC;
    }
    // 0x8008886C: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
    // 0x80088870: sll         $v0, $a1, 4
    ctx->r2 = S32(ctx->r5 << 4);
    // 0x80088874: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80088878: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008887C: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x80088880: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80088884: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x80088888: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x8008888C: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x80088890: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80088894: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80088898: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8008889C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800888A0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800888A4: j           L_800888CC
    // 0x800888A8: sb          $t1, 0x84($v1)
    MEM_B(0X84, ctx->r3) = ctx->r9;
        goto L_800888CC;
    // 0x800888A8: sb          $t1, 0x84($v1)
    MEM_B(0X84, ctx->r3) = ctx->r9;
L_800888AC:
    // 0x800888AC: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x800888B0: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x800888B4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800888B8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800888BC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800888C0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800888C4: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x800888C8: sb          $t1, 0x84($v0)
    MEM_B(0X84, ctx->r2) = ctx->r9;
L_800888CC:
    // 0x800888CC: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800888D0: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800888D4: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800888D8: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x800888DC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800888E0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800888E4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800888E8: lbu         $a1, -0x2727($at)
    ctx->r5 = MEM_BU(ctx->r1, -0X2727);
    // 0x800888EC: bne         $a1, $t4, L_80088994
    if (ctx->r5 != ctx->r12) {
        // 0x800888F0: addu        $v1, $a2, $zero
        ctx->r3 = ADD32(ctx->r6, 0);
            goto L_80088994;
    }
    // 0x800888F0: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
    // 0x800888F4: j           L_800889D4
    // 0x800888F8: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_800889D4;
    // 0x800888F8: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_800888FC:
    // 0x800888FC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088900: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80088904: lbu         $a1, -0x2731($at)
    ctx->r5 = MEM_BU(ctx->r1, -0X2731);
    // 0x80088908: beq         $a1, $t4, L_8008894C
    if (ctx->r5 == ctx->r12) {
        // 0x8008890C: addu        $v1, $a2, $zero
        ctx->r3 = ADD32(ctx->r6, 0);
            goto L_8008894C;
    }
    // 0x8008890C: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
    // 0x80088910: sll         $v0, $a1, 4
    ctx->r2 = S32(ctx->r5 << 4);
    // 0x80088914: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80088918: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008891C: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x80088920: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80088924: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x80088928: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x8008892C: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x80088930: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80088934: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80088938: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8008893C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80088940: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80088944: j           L_8008896C
    // 0x80088948: sb          $t1, 0x84($v1)
    MEM_B(0X84, ctx->r3) = ctx->r9;
        goto L_8008896C;
    // 0x80088948: sb          $t1, 0x84($v1)
    MEM_B(0X84, ctx->r3) = ctx->r9;
L_8008894C:
    // 0x8008894C: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80088950: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80088954: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80088958: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008895C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80088960: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80088964: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80088968: sb          $t1, 0x84($v0)
    MEM_B(0X84, ctx->r2) = ctx->r9;
L_8008896C:
    // 0x8008896C: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x80088970: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80088974: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80088978: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x8008897C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80088980: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088984: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80088988: lbu         $a1, -0x2731($at)
    ctx->r5 = MEM_BU(ctx->r1, -0X2731);
    // 0x8008898C: beq         $a1, $t4, L_800889D0
    if (ctx->r5 == ctx->r12) {
        // 0x80088990: addu        $v1, $a2, $zero
        ctx->r3 = ADD32(ctx->r6, 0);
            goto L_800889D0;
    }
    // 0x80088990: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
L_80088994:
    // 0x80088994: sll         $v0, $a1, 4
    ctx->r2 = S32(ctx->r5 << 4);
    // 0x80088998: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8008899C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800889A0: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x800889A4: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800889A8: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800889AC: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x800889B0: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x800889B4: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800889B8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800889BC: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800889C0: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800889C4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800889C8: j           L_800889F0
    // 0x800889CC: sb          $t0, 0x85($v1)
    MEM_B(0X85, ctx->r3) = ctx->r8;
        goto L_800889F0;
    // 0x800889CC: sb          $t0, 0x85($v1)
    MEM_B(0X85, ctx->r3) = ctx->r8;
L_800889D0:
    // 0x800889D0: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_800889D4:
    // 0x800889D4: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x800889D8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800889DC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800889E0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800889E4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800889E8: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x800889EC: sb          $t0, 0x85($v0)
    MEM_B(0X85, ctx->r2) = ctx->r8;
L_800889F0:
    // 0x800889F0: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800889F4: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800889F8: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800889FC: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80088A00: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80088A04: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088A08: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80088A0C: lw          $a0, -0x2770($at)
    ctx->r4 = MEM_W(ctx->r1, -0X2770);
    // 0x80088A10: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80088A14: bne         $a0, $v0, L_80088818
    if (ctx->r4 != ctx->r2) {
        // 0x80088A18: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_80088818;
    }
    // 0x80088A18: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_80088A1C:
    // 0x80088A1C: jr          $ra
    // 0x80088A20: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    return;
    // 0x80088A20: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
;}
RECOMP_FUNC void func_80088A24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088A24: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80088A28: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80088A2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80088A30: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80088A34: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80088A38: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80088A3C: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80088A40: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80088A44: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80088A48: beq         $v0, $zero, L_80088A6C
    if (ctx->r2 == 0) {
        // 0x80088A4C: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80088A6C;
    }
    // 0x80088A4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80088A50: jal         0x80092010
    // 0x80088A54: nop

    func_80092010(rdram, ctx);
        goto after_0;
    // 0x80088A54: nop

    after_0:
    // 0x80088A58: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80088A5C: jal         0x80088794
    // 0x80088A60: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    func_80088794(rdram, ctx);
        goto after_1;
    // 0x80088A60: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    after_1:
    // 0x80088A64: jal         0x8009205C
    // 0x80088A68: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    func_8009205C(rdram, ctx);
        goto after_2;
    // 0x80088A68: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_2:
L_80088A6C:
    // 0x80088A6C: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x80088A70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80088A74: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80088A78: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80088A7C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80088A80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80088A84: jr          $ra
    // 0x80088A88: nop

    return;
    // 0x80088A88: nop

;}
RECOMP_FUNC void func_80088A8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088A8C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80088A90: beql        $a0, $a3, L_80088AE4
    if (ctx->r4 == ctx->r7) {
        // 0x80088A94: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_80088AE4;
    }
    goto skip_0;
    // 0x80088A94: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    skip_0:
    // 0x80088A98: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80088A9C: lw          $v1, -0x5100($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5100);
    // 0x80088AA0: beq         $v1, $zero, L_80088AC8
    if (ctx->r3 == 0) {
        // 0x80088AA4: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80088AC8;
    }
    // 0x80088AA4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80088AA8:
    // 0x80088AA8: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80088AAC: beq         $v0, $a0, L_80088ADC
    if (ctx->r2 == ctx->r4) {
        // 0x80088AB0: sltu        $v0, $a0, $v0
        ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
            goto L_80088ADC;
    }
    // 0x80088AB0: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80088AB4: bne         $v0, $zero, L_80088AC8
    if (ctx->r2 != 0) {
        // 0x80088AB8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80088AC8;
    }
    // 0x80088AB8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80088ABC: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80088AC0: bne         $v1, $zero, L_80088AA8
    if (ctx->r3 != 0) {
        // 0x80088AC4: nop
    
            goto L_80088AA8;
    }
    // 0x80088AC4: nop

L_80088AC8:
    // 0x80088AC8: beq         $v0, $zero, L_80088AE4
    if (ctx->r2 == 0) {
        // 0x80088ACC: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_80088AE4;
    }
    // 0x80088ACC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80088AD0: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x80088AD4: j           L_80088AE8
    // 0x80088AD8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80088AE8;
    // 0x80088AD8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80088ADC:
    // 0x80088ADC: j           L_80088AC8
    // 0x80088AE0: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80088AC8;
    // 0x80088AE0: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80088AE4:
    // 0x80088AE4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80088AE8:
    // 0x80088AE8: beq         $a0, $v0, L_80088D14
    if (ctx->r4 == ctx->r2) {
        // 0x80088AEC: nop
    
            goto L_80088D14;
    }
    // 0x80088AEC: nop

    // 0x80088AF0: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80088AF4: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x80088AF8: addiu       $t3, $t3, 0x40C8
    ctx->r11 = ADD32(ctx->r11, 0X40C8);
    // 0x80088AFC: srl         $v0, $a1, 7
    ctx->r2 = S32(U32(ctx->r5) >> 7);
    // 0x80088B00: andi        $t1, $v0, 0x7F
    ctx->r9 = ctx->r2 & 0X7F;
    // 0x80088B04: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80088B08: addiu       $t2, $t2, 0xA10
    ctx->r10 = ADD32(ctx->r10, 0XA10);
    // 0x80088B0C: andi        $t0, $a1, 0x7F
    ctx->r8 = ctx->r5 & 0X7F;
L_80088B10:
    // 0x80088B10: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x80088B14: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x80088B18: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80088B1C: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80088B20: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80088B24: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80088B28: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088B2C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80088B30: lw          $v0, -0x271C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X271C);
    // 0x80088B34: bne         $v0, $a0, L_80088D14
    if (ctx->r2 != ctx->r4) {
        // 0x80088B38: nop
    
            goto L_80088D14;
    }
    // 0x80088B38: nop

    // 0x80088B3C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088B40: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80088B44: lw          $v0, -0x275C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X275C);
    // 0x80088B48: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80088B4C: beq         $v0, $zero, L_80088BF4
    if (ctx->r2 == 0) {
        // 0x80088B50: nop
    
            goto L_80088BF4;
    }
    // 0x80088B50: nop

    // 0x80088B54: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088B58: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80088B5C: lbu         $a1, -0x2727($at)
    ctx->r5 = MEM_BU(ctx->r1, -0X2727);
    // 0x80088B60: beq         $a1, $t4, L_80088BA4
    if (ctx->r5 == ctx->r12) {
        // 0x80088B64: addu        $v1, $a2, $zero
        ctx->r3 = ADD32(ctx->r6, 0);
            goto L_80088BA4;
    }
    // 0x80088B64: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
    // 0x80088B68: sll         $v0, $a1, 4
    ctx->r2 = S32(ctx->r5 << 4);
    // 0x80088B6C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80088B70: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80088B74: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x80088B78: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80088B7C: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x80088B80: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x80088B84: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x80088B88: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80088B8C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80088B90: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80088B94: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80088B98: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80088B9C: j           L_80088BC4
    // 0x80088BA0: sb          $t1, 0x80($v1)
    MEM_B(0X80, ctx->r3) = ctx->r9;
        goto L_80088BC4;
    // 0x80088BA0: sb          $t1, 0x80($v1)
    MEM_B(0X80, ctx->r3) = ctx->r9;
L_80088BA4:
    // 0x80088BA4: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80088BA8: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80088BAC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80088BB0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80088BB4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80088BB8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80088BBC: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80088BC0: sb          $t1, 0x80($v0)
    MEM_B(0X80, ctx->r2) = ctx->r9;
L_80088BC4:
    // 0x80088BC4: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x80088BC8: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80088BCC: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80088BD0: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80088BD4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80088BD8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088BDC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80088BE0: lbu         $a1, -0x2727($at)
    ctx->r5 = MEM_BU(ctx->r1, -0X2727);
    // 0x80088BE4: bne         $a1, $t4, L_80088C8C
    if (ctx->r5 != ctx->r12) {
        // 0x80088BE8: addu        $v1, $a2, $zero
        ctx->r3 = ADD32(ctx->r6, 0);
            goto L_80088C8C;
    }
    // 0x80088BE8: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
    // 0x80088BEC: j           L_80088CCC
    // 0x80088BF0: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_80088CCC;
    // 0x80088BF0: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_80088BF4:
    // 0x80088BF4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088BF8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80088BFC: lbu         $a1, -0x2731($at)
    ctx->r5 = MEM_BU(ctx->r1, -0X2731);
    // 0x80088C00: beq         $a1, $t4, L_80088C44
    if (ctx->r5 == ctx->r12) {
        // 0x80088C04: addu        $v1, $a2, $zero
        ctx->r3 = ADD32(ctx->r6, 0);
            goto L_80088C44;
    }
    // 0x80088C04: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
    // 0x80088C08: sll         $v0, $a1, 4
    ctx->r2 = S32(ctx->r5 << 4);
    // 0x80088C0C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80088C10: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80088C14: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x80088C18: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80088C1C: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x80088C20: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x80088C24: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x80088C28: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80088C2C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80088C30: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80088C34: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80088C38: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80088C3C: j           L_80088C64
    // 0x80088C40: sb          $t1, 0x80($v1)
    MEM_B(0X80, ctx->r3) = ctx->r9;
        goto L_80088C64;
    // 0x80088C40: sb          $t1, 0x80($v1)
    MEM_B(0X80, ctx->r3) = ctx->r9;
L_80088C44:
    // 0x80088C44: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80088C48: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80088C4C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80088C50: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80088C54: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80088C58: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80088C5C: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80088C60: sb          $t1, 0x80($v0)
    MEM_B(0X80, ctx->r2) = ctx->r9;
L_80088C64:
    // 0x80088C64: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x80088C68: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80088C6C: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80088C70: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80088C74: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80088C78: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088C7C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80088C80: lbu         $a1, -0x2731($at)
    ctx->r5 = MEM_BU(ctx->r1, -0X2731);
    // 0x80088C84: beq         $a1, $t4, L_80088CC8
    if (ctx->r5 == ctx->r12) {
        // 0x80088C88: addu        $v1, $a2, $zero
        ctx->r3 = ADD32(ctx->r6, 0);
            goto L_80088CC8;
    }
    // 0x80088C88: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
L_80088C8C:
    // 0x80088C8C: sll         $v0, $a1, 4
    ctx->r2 = S32(ctx->r5 << 4);
    // 0x80088C90: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80088C94: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80088C98: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x80088C9C: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80088CA0: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x80088CA4: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x80088CA8: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x80088CAC: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80088CB0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80088CB4: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80088CB8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80088CBC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80088CC0: j           L_80088CE8
    // 0x80088CC4: sb          $t0, 0x81($v1)
    MEM_B(0X81, ctx->r3) = ctx->r8;
        goto L_80088CE8;
    // 0x80088CC4: sb          $t0, 0x81($v1)
    MEM_B(0X81, ctx->r3) = ctx->r8;
L_80088CC8:
    // 0x80088CC8: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_80088CCC:
    // 0x80088CCC: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80088CD0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80088CD4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80088CD8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80088CDC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80088CE0: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80088CE4: sb          $t0, 0x81($v0)
    MEM_B(0X81, ctx->r2) = ctx->r8;
L_80088CE8:
    // 0x80088CE8: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x80088CEC: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80088CF0: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80088CF4: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80088CF8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80088CFC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088D00: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80088D04: lw          $a0, -0x2770($at)
    ctx->r4 = MEM_W(ctx->r1, -0X2770);
    // 0x80088D08: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80088D0C: bne         $a0, $v0, L_80088B10
    if (ctx->r4 != ctx->r2) {
        // 0x80088D10: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_80088B10;
    }
    // 0x80088D10: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_80088D14:
    // 0x80088D14: jr          $ra
    // 0x80088D18: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    return;
    // 0x80088D18: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
;}
RECOMP_FUNC void func_80088D1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088D1C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80088D20: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80088D24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80088D28: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80088D2C: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80088D30: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80088D34: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80088D38: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80088D3C: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80088D40: beq         $v0, $zero, L_80088D64
    if (ctx->r2 == 0) {
        // 0x80088D44: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80088D64;
    }
    // 0x80088D44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80088D48: jal         0x80092010
    // 0x80088D4C: nop

    func_80092010(rdram, ctx);
        goto after_0;
    // 0x80088D4C: nop

    after_0:
    // 0x80088D50: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80088D54: jal         0x80088A8C
    // 0x80088D58: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    func_80088A8C(rdram, ctx);
        goto after_1;
    // 0x80088D58: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    after_1:
    // 0x80088D5C: jal         0x8009205C
    // 0x80088D60: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    func_8009205C(rdram, ctx);
        goto after_2;
    // 0x80088D60: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_2:
L_80088D64:
    // 0x80088D64: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x80088D68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80088D6C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80088D70: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80088D74: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80088D78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80088D7C: jr          $ra
    // 0x80088D80: nop

    return;
    // 0x80088D80: nop

;}
RECOMP_FUNC void func_80088D84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088D84: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80088D88: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80088D8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80088D90: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80088D94: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80088D98: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80088D9C: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80088DA0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80088DA4: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x80088DA8: beq         $v0, $zero, L_8008903C
    if (ctx->r2 == 0) {
        // 0x80088DAC: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8008903C;
    }
    // 0x80088DAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80088DB0: jal         0x80092010
    // 0x80088DB4: nop

    func_80092010(rdram, ctx);
        goto after_0;
    // 0x80088DB4: nop

    after_0:
    // 0x80088DB8: beq         $s0, $s1, L_80088E0C
    if (ctx->r16 == ctx->r17) {
        // 0x80088DBC: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_80088E0C;
    }
    // 0x80088DBC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80088DC0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80088DC4: lw          $v1, -0x5100($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5100);
    // 0x80088DC8: beq         $v1, $zero, L_80088DF0
    if (ctx->r3 == 0) {
        // 0x80088DCC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80088DF0;
    }
    // 0x80088DCC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80088DD0:
    // 0x80088DD0: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80088DD4: beq         $v0, $s0, L_80088E04
    if (ctx->r2 == ctx->r16) {
        // 0x80088DD8: sltu        $v0, $s0, $v0
        ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
            goto L_80088E04;
    }
    // 0x80088DD8: sltu        $v0, $s0, $v0
    ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x80088DDC: bne         $v0, $zero, L_80088DF0
    if (ctx->r2 != 0) {
        // 0x80088DE0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80088DF0;
    }
    // 0x80088DE0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80088DE4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80088DE8: bne         $v1, $zero, L_80088DD0
    if (ctx->r3 != 0) {
        // 0x80088DEC: nop
    
            goto L_80088DD0;
    }
    // 0x80088DEC: nop

L_80088DF0:
    // 0x80088DF0: beq         $v0, $zero, L_80088E0C
    if (ctx->r2 == 0) {
        // 0x80088DF4: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_80088E0C;
    }
    // 0x80088DF4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80088DF8: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x80088DFC: j           L_80088E10
    // 0x80088E00: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
        goto L_80088E10;
    // 0x80088E00: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
L_80088E04:
    // 0x80088E04: j           L_80088DF0
    // 0x80088E08: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80088DF0;
    // 0x80088E08: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80088E0C:
    // 0x80088E0C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
L_80088E10:
    // 0x80088E10: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80088E14: beq         $s0, $v0, L_80089034
    if (ctx->r16 == ctx->r2) {
        // 0x80088E18: addiu       $t2, $zero, 0xFF
        ctx->r10 = ADD32(0, 0XFF);
            goto L_80089034;
    }
    // 0x80088E18: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80088E1C: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80088E20: addiu       $t1, $t1, 0x40C8
    ctx->r9 = ADD32(ctx->r9, 0X40C8);
    // 0x80088E24: andi        $a1, $s2, 0x7F
    ctx->r5 = ctx->r18 & 0X7F;
    // 0x80088E28: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80088E2C: addiu       $t0, $t0, 0xA10
    ctx->r8 = ADD32(ctx->r8, 0XA10);
L_80088E30:
    // 0x80088E30: andi        $a3, $s0, 0xFF
    ctx->r7 = ctx->r16 & 0XFF;
    // 0x80088E34: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x80088E38: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80088E3C: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80088E40: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x80088E44: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80088E48: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088E4C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80088E50: lw          $v0, -0x271C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X271C);
    // 0x80088E54: bne         $v0, $s0, L_80089034
    if (ctx->r2 != ctx->r16) {
        // 0x80088E58: nop
    
            goto L_80089034;
    }
    // 0x80088E58: nop

    // 0x80088E5C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088E60: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80088E64: lw          $v0, -0x275C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X275C);
    // 0x80088E68: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80088E6C: beq         $v0, $zero, L_80088F14
    if (ctx->r2 == 0) {
        // 0x80088E70: nop
    
            goto L_80088F14;
    }
    // 0x80088E70: nop

    // 0x80088E74: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088E78: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80088E7C: lbu         $a2, -0x2727($at)
    ctx->r6 = MEM_BU(ctx->r1, -0X2727);
    // 0x80088E80: beq         $a2, $t2, L_80088EC4
    if (ctx->r6 == ctx->r10) {
        // 0x80088E84: addu        $v1, $a3, $zero
        ctx->r3 = ADD32(ctx->r7, 0);
            goto L_80088EC4;
    }
    // 0x80088E84: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
    // 0x80088E88: sll         $v0, $a2, 4
    ctx->r2 = S32(ctx->r6 << 4);
    // 0x80088E8C: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80088E90: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80088E94: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80088E98: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80088E9C: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80088EA0: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x80088EA4: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x80088EA8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80088EAC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80088EB0: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80088EB4: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80088EB8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80088EBC: j           L_80088EE4
    // 0x80088EC0: sb          $a1, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r5;
        goto L_80088EE4;
    // 0x80088EC0: sb          $a1, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r5;
L_80088EC4:
    // 0x80088EC4: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80088EC8: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80088ECC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80088ED0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80088ED4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80088ED8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80088EDC: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80088EE0: sb          $a1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r5;
L_80088EE4:
    // 0x80088EE4: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x80088EE8: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80088EEC: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80088EF0: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x80088EF4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80088EF8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088EFC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80088F00: lbu         $a2, -0x2727($at)
    ctx->r6 = MEM_BU(ctx->r1, -0X2727);
    // 0x80088F04: bne         $a2, $t2, L_80088FAC
    if (ctx->r6 != ctx->r10) {
        // 0x80088F08: addu        $v1, $a3, $zero
        ctx->r3 = ADD32(ctx->r7, 0);
            goto L_80088FAC;
    }
    // 0x80088F08: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
    // 0x80088F0C: j           L_80088FEC
    // 0x80088F10: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_80088FEC;
    // 0x80088F10: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_80088F14:
    // 0x80088F14: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088F18: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80088F1C: lbu         $a2, -0x2731($at)
    ctx->r6 = MEM_BU(ctx->r1, -0X2731);
    // 0x80088F20: beq         $a2, $t2, L_80088F64
    if (ctx->r6 == ctx->r10) {
        // 0x80088F24: addu        $v1, $a3, $zero
        ctx->r3 = ADD32(ctx->r7, 0);
            goto L_80088F64;
    }
    // 0x80088F24: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
    // 0x80088F28: sll         $v0, $a2, 4
    ctx->r2 = S32(ctx->r6 << 4);
    // 0x80088F2C: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80088F30: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80088F34: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80088F38: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80088F3C: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80088F40: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x80088F44: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x80088F48: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80088F4C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80088F50: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80088F54: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80088F58: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80088F5C: j           L_80088F84
    // 0x80088F60: sb          $a1, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r5;
        goto L_80088F84;
    // 0x80088F60: sb          $a1, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r5;
L_80088F64:
    // 0x80088F64: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80088F68: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80088F6C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80088F70: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80088F74: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80088F78: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80088F7C: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80088F80: sb          $a1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r5;
L_80088F84:
    // 0x80088F84: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x80088F88: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80088F8C: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80088F90: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x80088F94: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80088F98: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088F9C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80088FA0: lbu         $a2, -0x2731($at)
    ctx->r6 = MEM_BU(ctx->r1, -0X2731);
    // 0x80088FA4: beq         $a2, $t2, L_80088FE8
    if (ctx->r6 == ctx->r10) {
        // 0x80088FA8: addu        $v1, $a3, $zero
        ctx->r3 = ADD32(ctx->r7, 0);
            goto L_80088FE8;
    }
    // 0x80088FA8: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
L_80088FAC:
    // 0x80088FAC: sll         $v0, $a2, 4
    ctx->r2 = S32(ctx->r6 << 4);
    // 0x80088FB0: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80088FB4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80088FB8: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80088FBC: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80088FC0: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80088FC4: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x80088FC8: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x80088FCC: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80088FD0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80088FD4: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80088FD8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80088FDC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80088FE0: j           L_80089008
    // 0x80088FE4: sb          $zero, 0x21($v1)
    MEM_B(0X21, ctx->r3) = 0;
        goto L_80089008;
    // 0x80088FE4: sb          $zero, 0x21($v1)
    MEM_B(0X21, ctx->r3) = 0;
L_80088FE8:
    // 0x80088FE8: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_80088FEC:
    // 0x80088FEC: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80088FF0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80088FF4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80088FF8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80088FFC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80089000: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80089004: sb          $zero, 0x21($v0)
    MEM_B(0X21, ctx->r2) = 0;
L_80089008:
    // 0x80089008: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x8008900C: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80089010: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80089014: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x80089018: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008901C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80089020: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80089024: lw          $s0, -0x2770($at)
    ctx->r16 = MEM_W(ctx->r1, -0X2770);
    // 0x80089028: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8008902C: bne         $s0, $v0, L_80088E30
    if (ctx->r16 != ctx->r2) {
        // 0x80089030: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80088E30;
    }
    // 0x80089030: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_80089034:
    // 0x80089034: jal         0x8009205C
    // 0x80089038: nop

    func_8009205C(rdram, ctx);
        goto after_1;
    // 0x80089038: nop

    after_1:
L_8008903C:
    // 0x8008903C: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x80089040: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80089044: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80089048: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8008904C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80089050: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80089054: jr          $ra
    // 0x80089058: nop

    return;
    // 0x80089058: nop

;}
RECOMP_FUNC void func_8008905C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008905C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80089060: beql        $a0, $a2, L_800890B4
    if (ctx->r4 == ctx->r6) {
        // 0x80089064: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_800890B4;
    }
    goto skip_0;
    // 0x80089064: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    skip_0:
    // 0x80089068: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8008906C: lw          $v1, -0x5100($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5100);
    // 0x80089070: beq         $v1, $zero, L_80089098
    if (ctx->r3 == 0) {
        // 0x80089074: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80089098;
    }
    // 0x80089074: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80089078:
    // 0x80089078: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x8008907C: beq         $v0, $a0, L_800890AC
    if (ctx->r2 == ctx->r4) {
        // 0x80089080: sltu        $v0, $a0, $v0
        ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
            goto L_800890AC;
    }
    // 0x80089080: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80089084: bne         $v0, $zero, L_80089098
    if (ctx->r2 != 0) {
        // 0x80089088: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80089098;
    }
    // 0x80089088: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8008908C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80089090: bne         $v1, $zero, L_80089078
    if (ctx->r3 != 0) {
        // 0x80089094: nop
    
            goto L_80089078;
    }
    // 0x80089094: nop

L_80089098:
    // 0x80089098: beq         $v0, $zero, L_800890B4
    if (ctx->r2 == 0) {
        // 0x8008909C: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_800890B4;
    }
    // 0x8008909C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800890A0: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x800890A4: j           L_800890B8
    // 0x800890A8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800890B8;
    // 0x800890A8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800890AC:
    // 0x800890AC: j           L_80089098
    // 0x800890B0: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80089098;
    // 0x800890B0: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_800890B4:
    // 0x800890B4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800890B8:
    // 0x800890B8: beq         $a0, $v0, L_800891D4
    if (ctx->r4 == ctx->r2) {
        // 0x800890BC: nop
    
            goto L_800891D4;
    }
    // 0x800890BC: nop

    // 0x800890C0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800890C4: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x800890C8: addiu       $t1, $t1, 0x40C8
    ctx->r9 = ADD32(ctx->r9, 0X40C8);
    // 0x800890CC: andi        $a1, $a1, 0x7F
    ctx->r5 = ctx->r5 & 0X7F;
    // 0x800890D0: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x800890D4: addiu       $t0, $t0, 0xA10
    ctx->r8 = ADD32(ctx->r8, 0XA10);
    // 0x800890D8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_800890DC:
    // 0x800890DC: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x800890E0: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x800890E4: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x800890E8: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800890EC: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x800890F0: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800890F4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800890F8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800890FC: lw          $v0, -0x271C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X271C);
    // 0x80089100: bne         $v0, $a0, L_800891D4
    if (ctx->r2 != ctx->r4) {
        // 0x80089104: nop
    
            goto L_800891D4;
    }
    // 0x80089104: nop

    // 0x80089108: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008910C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80089110: lw          $v0, -0x275C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X275C);
    // 0x80089114: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80089118: beq         $v0, $zero, L_8008913C
    if (ctx->r2 == 0) {
        // 0x8008911C: nop
    
            goto L_8008913C;
    }
    // 0x8008911C: nop

    // 0x80089120: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80089124: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80089128: lbu         $a2, -0x2727($at)
    ctx->r6 = MEM_BU(ctx->r1, -0X2727);
    // 0x8008912C: bne         $a2, $t2, L_80089150
    if (ctx->r6 != ctx->r10) {
        // 0x80089130: addu        $v1, $a3, $zero
        ctx->r3 = ADD32(ctx->r7, 0);
            goto L_80089150;
    }
    // 0x80089130: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
    // 0x80089134: j           L_80089190
    // 0x80089138: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_80089190;
    // 0x80089138: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_8008913C:
    // 0x8008913C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80089140: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80089144: lbu         $a2, -0x2731($at)
    ctx->r6 = MEM_BU(ctx->r1, -0X2731);
    // 0x80089148: beq         $a2, $t2, L_8008918C
    if (ctx->r6 == ctx->r10) {
        // 0x8008914C: addu        $v1, $a3, $zero
        ctx->r3 = ADD32(ctx->r7, 0);
            goto L_8008918C;
    }
    // 0x8008914C: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
L_80089150:
    // 0x80089150: sll         $v0, $a2, 4
    ctx->r2 = S32(ctx->r6 << 4);
    // 0x80089154: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80089158: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008915C: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80089160: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80089164: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80089168: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x8008916C: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x80089170: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80089174: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80089178: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8008917C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80089180: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80089184: j           L_800891AC
    // 0x80089188: sb          $a1, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r5;
        goto L_800891AC;
    // 0x80089188: sb          $a1, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r5;
L_8008918C:
    // 0x8008918C: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_80089190:
    // 0x80089190: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80089194: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80089198: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008919C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800891A0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800891A4: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x800891A8: sb          $a1, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r5;
L_800891AC:
    // 0x800891AC: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x800891B0: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x800891B4: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800891B8: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x800891BC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800891C0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800891C4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800891C8: lw          $a0, -0x2770($at)
    ctx->r4 = MEM_W(ctx->r1, -0X2770);
    // 0x800891CC: bne         $a0, $t3, L_800890DC
    if (ctx->r4 != ctx->r11) {
        // 0x800891D0: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_800890DC;
    }
    // 0x800891D0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_800891D4:
    // 0x800891D4: jr          $ra
    // 0x800891D8: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    return;
    // 0x800891D8: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
;}
RECOMP_FUNC void func_800891DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800891DC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800891E0: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x800891E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800891E8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800891EC: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800891F0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800891F4: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x800891F8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800891FC: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80089200: beq         $v0, $zero, L_80089224
    if (ctx->r2 == 0) {
        // 0x80089204: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80089224;
    }
    // 0x80089204: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80089208: jal         0x80092010
    // 0x8008920C: nop

    func_80092010(rdram, ctx);
        goto after_0;
    // 0x8008920C: nop

    after_0:
    // 0x80089210: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80089214: jal         0x8008905C
    // 0x80089218: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    func_8008905C(rdram, ctx);
        goto after_1;
    // 0x80089218: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    after_1:
    // 0x8008921C: jal         0x8009205C
    // 0x80089220: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    func_8009205C(rdram, ctx);
        goto after_2;
    // 0x80089220: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_2:
L_80089224:
    // 0x80089224: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x80089228: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008922C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80089230: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80089234: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80089238: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008923C: jr          $ra
    // 0x80089240: nop

    return;
    // 0x80089240: nop

;}
RECOMP_FUNC void func_80089244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089244: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80089248: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x8008924C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80089250: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80089254: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80089258: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8008925C: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80089260: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80089264: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x80089268: beq         $v0, $zero, L_800893F4
    if (ctx->r2 == 0) {
        // 0x8008926C: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800893F4;
    }
    // 0x8008926C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80089270: jal         0x80092010
    // 0x80089274: nop

    func_80092010(rdram, ctx);
        goto after_0;
    // 0x80089274: nop

    after_0:
    // 0x80089278: beq         $s0, $s1, L_800892CC
    if (ctx->r16 == ctx->r17) {
        // 0x8008927C: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_800892CC;
    }
    // 0x8008927C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80089280: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80089284: lw          $v1, -0x5100($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5100);
    // 0x80089288: beq         $v1, $zero, L_800892B0
    if (ctx->r3 == 0) {
        // 0x8008928C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800892B0;
    }
    // 0x8008928C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80089290:
    // 0x80089290: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80089294: beq         $v0, $s0, L_800892C4
    if (ctx->r2 == ctx->r16) {
        // 0x80089298: sltu        $v0, $s0, $v0
        ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
            goto L_800892C4;
    }
    // 0x80089298: sltu        $v0, $s0, $v0
    ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x8008929C: bne         $v0, $zero, L_800892B0
    if (ctx->r2 != 0) {
        // 0x800892A0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800892B0;
    }
    // 0x800892A0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800892A4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800892A8: bne         $v1, $zero, L_80089290
    if (ctx->r3 != 0) {
        // 0x800892AC: nop
    
            goto L_80089290;
    }
    // 0x800892AC: nop

L_800892B0:
    // 0x800892B0: beq         $v0, $zero, L_800892CC
    if (ctx->r2 == 0) {
        // 0x800892B4: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_800892CC;
    }
    // 0x800892B4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800892B8: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x800892BC: j           L_800892D0
    // 0x800892C0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
        goto L_800892D0;
    // 0x800892C0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
L_800892C4:
    // 0x800892C4: j           L_800892B0
    // 0x800892C8: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_800892B0;
    // 0x800892C8: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_800892CC:
    // 0x800892CC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
L_800892D0:
    // 0x800892D0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800892D4: beq         $s0, $v0, L_800893EC
    if (ctx->r16 == ctx->r2) {
        // 0x800892D8: addiu       $t2, $zero, 0xFF
        ctx->r10 = ADD32(0, 0XFF);
            goto L_800893EC;
    }
    // 0x800892D8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800892DC: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x800892E0: addiu       $t1, $t1, 0x40C8
    ctx->r9 = ADD32(ctx->r9, 0X40C8);
    // 0x800892E4: andi        $a1, $s2, 0x7F
    ctx->r5 = ctx->r18 & 0X7F;
    // 0x800892E8: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x800892EC: addiu       $t0, $t0, 0xA10
    ctx->r8 = ADD32(ctx->r8, 0XA10);
L_800892F0:
    // 0x800892F0: andi        $a3, $s0, 0xFF
    ctx->r7 = ctx->r16 & 0XFF;
    // 0x800892F4: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x800892F8: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x800892FC: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80089300: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x80089304: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80089308: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008930C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80089310: lw          $v0, -0x271C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X271C);
    // 0x80089314: bne         $v0, $s0, L_800893EC
    if (ctx->r2 != ctx->r16) {
        // 0x80089318: nop
    
            goto L_800893EC;
    }
    // 0x80089318: nop

    // 0x8008931C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80089320: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80089324: lw          $v0, -0x275C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X275C);
    // 0x80089328: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x8008932C: beq         $v0, $zero, L_80089350
    if (ctx->r2 == 0) {
        // 0x80089330: nop
    
            goto L_80089350;
    }
    // 0x80089330: nop

    // 0x80089334: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80089338: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008933C: lbu         $a2, -0x2727($at)
    ctx->r6 = MEM_BU(ctx->r1, -0X2727);
    // 0x80089340: bne         $a2, $t2, L_80089364
    if (ctx->r6 != ctx->r10) {
        // 0x80089344: addu        $v1, $a3, $zero
        ctx->r3 = ADD32(ctx->r7, 0);
            goto L_80089364;
    }
    // 0x80089344: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
    // 0x80089348: j           L_800893A4
    // 0x8008934C: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_800893A4;
    // 0x8008934C: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_80089350:
    // 0x80089350: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80089354: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80089358: lbu         $a2, -0x2731($at)
    ctx->r6 = MEM_BU(ctx->r1, -0X2731);
    // 0x8008935C: beq         $a2, $t2, L_800893A0
    if (ctx->r6 == ctx->r10) {
        // 0x80089360: addu        $v1, $a3, $zero
        ctx->r3 = ADD32(ctx->r7, 0);
            goto L_800893A0;
    }
    // 0x80089360: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
L_80089364:
    // 0x80089364: sll         $v0, $a2, 4
    ctx->r2 = S32(ctx->r6 << 4);
    // 0x80089368: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8008936C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80089370: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80089374: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80089378: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8008937C: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x80089380: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x80089384: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80089388: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8008938C: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80089390: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80089394: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80089398: j           L_800893C0
    // 0x8008939C: sb          $a1, 0x5B($v1)
    MEM_B(0X5B, ctx->r3) = ctx->r5;
        goto L_800893C0;
    // 0x8008939C: sb          $a1, 0x5B($v1)
    MEM_B(0X5B, ctx->r3) = ctx->r5;
L_800893A0:
    // 0x800893A0: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_800893A4:
    // 0x800893A4: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x800893A8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800893AC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800893B0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800893B4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800893B8: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x800893BC: sb          $a1, 0x5B($v0)
    MEM_B(0X5B, ctx->r2) = ctx->r5;
L_800893C0:
    // 0x800893C0: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x800893C4: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x800893C8: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800893CC: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x800893D0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800893D4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800893D8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800893DC: lw          $s0, -0x2770($at)
    ctx->r16 = MEM_W(ctx->r1, -0X2770);
    // 0x800893E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800893E4: bne         $s0, $v0, L_800892F0
    if (ctx->r16 != ctx->r2) {
        // 0x800893E8: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_800892F0;
    }
    // 0x800893E8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_800893EC:
    // 0x800893EC: jal         0x8009205C
    // 0x800893F0: nop

    func_8009205C(rdram, ctx);
        goto after_1;
    // 0x800893F0: nop

    after_1:
L_800893F4:
    // 0x800893F4: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x800893F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800893FC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80089400: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80089404: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80089408: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008940C: jr          $ra
    // 0x80089410: nop

    return;
    // 0x80089410: nop

;}
RECOMP_FUNC void func_80089414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089414: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80089418: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x8008941C: beq         $v0, $zero, L_800894E8
    if (ctx->r2 == 0) {
        // 0x80089420: addiu       $a1, $zero, -0x1
        ctx->r5 = ADD32(0, -0X1);
            goto L_800894E8;
    }
    // 0x80089420: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80089424: beql        $a0, $a1, L_80089478
    if (ctx->r4 == ctx->r5) {
        // 0x80089428: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_80089478;
    }
    goto skip_0;
    // 0x80089428: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    skip_0:
    // 0x8008942C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80089430: lw          $v1, -0x5100($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5100);
    // 0x80089434: beq         $v1, $zero, L_8008945C
    if (ctx->r3 == 0) {
        // 0x80089438: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8008945C;
    }
    // 0x80089438: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8008943C:
    // 0x8008943C: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80089440: beq         $v0, $a0, L_80089470
    if (ctx->r2 == ctx->r4) {
        // 0x80089444: sltu        $v0, $a0, $v0
        ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
            goto L_80089470;
    }
    // 0x80089444: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80089448: bne         $v0, $zero, L_8008945C
    if (ctx->r2 != 0) {
        // 0x8008944C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8008945C;
    }
    // 0x8008944C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80089450: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80089454: bne         $v1, $zero, L_8008943C
    if (ctx->r3 != 0) {
        // 0x80089458: nop
    
            goto L_8008943C;
    }
    // 0x80089458: nop

L_8008945C:
    // 0x8008945C: beq         $v0, $zero, L_80089478
    if (ctx->r2 == 0) {
        // 0x80089460: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_80089478;
    }
    // 0x80089460: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80089464: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x80089468: j           L_8008947C
    // 0x8008946C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8008947C;
    // 0x8008946C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80089470:
    // 0x80089470: j           L_8008945C
    // 0x80089474: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8008945C;
    // 0x80089474: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80089478:
    // 0x80089478: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8008947C:
    // 0x8008947C: beq         $a0, $v0, L_800894E8
    if (ctx->r4 == ctx->r2) {
        // 0x80089480: nop
    
            goto L_800894E8;
    }
    // 0x80089480: nop

    // 0x80089484: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80089488: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
L_8008948C:
    // 0x8008948C: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80089490: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80089494: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80089498: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8008949C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800894A0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800894A4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800894A8: lw          $v0, -0x271C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X271C);
    // 0x800894AC: bne         $v0, $a0, L_800894D4
    if (ctx->r2 != ctx->r4) {
        // 0x800894B0: nop
    
            goto L_800894D4;
    }
    // 0x800894B0: nop

    // 0x800894B4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800894B8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800894BC: lw          $v0, -0x275C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X275C);
    // 0x800894C0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800894C4: ori         $v0, $v0, 0x8
    ctx->r2 = ctx->r2 | 0X8;
    // 0x800894C8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800894CC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800894D0: sw          $v0, -0x275C($at)
    MEM_W(-0X275C, ctx->r1) = ctx->r2;
L_800894D4:
    // 0x800894D4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800894D8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800894DC: lw          $a0, -0x2770($at)
    ctx->r4 = MEM_W(ctx->r1, -0X2770);
    // 0x800894E0: bnel        $a0, $a2, L_8008948C
    if (ctx->r4 != ctx->r6) {
        // 0x800894E4: andi        $v0, $a0, 0xFF
        ctx->r2 = ctx->r4 & 0XFF;
            goto L_8008948C;
    }
    goto skip_1;
    // 0x800894E4: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    skip_1:
L_800894E8:
    // 0x800894E8: jr          $ra
    // 0x800894EC: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    return;
    // 0x800894EC: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
;}
RECOMP_FUNC void func_800894F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800894F0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800894F4: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x800894F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800894FC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80089500: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80089504: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80089508: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x8008950C: beq         $v0, $zero, L_8008952C
    if (ctx->r2 == 0) {
        // 0x80089510: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_8008952C;
    }
    // 0x80089510: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80089514: jal         0x80092010
    // 0x80089518: nop

    func_80092010(rdram, ctx);
        goto after_0;
    // 0x80089518: nop

    after_0:
    // 0x8008951C: jal         0x80089414
    // 0x80089520: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80089414(rdram, ctx);
        goto after_1;
    // 0x80089520: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x80089524: jal         0x8009205C
    // 0x80089528: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    func_8009205C(rdram, ctx);
        goto after_2;
    // 0x80089528: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_2:
L_8008952C:
    // 0x8008952C: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x80089530: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80089534: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80089538: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8008953C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80089540: jr          $ra
    // 0x80089544: nop

    return;
    // 0x80089544: nop

;}
RECOMP_FUNC void func_80089548(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089548: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8008954C: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x80089550: jr          $ra
    // 0x80089554: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    return;
    // 0x80089554: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_80089558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089558: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8008955C: lbu         $v1, 0x4F($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X4F);
    // 0x80089560: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80089564: addiu       $a0, $a0, -0x5330
    ctx->r4 = ADD32(ctx->r4, -0X5330);
    // 0x80089568: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8008956C: beq         $v1, $v0, L_8008957C
    if (ctx->r3 == ctx->r2) {
        // 0x80089570: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8008957C;
    }
    // 0x80089570: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80089574: j           L_80089580
    // 0x80089578: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
        goto L_80089580;
    // 0x80089578: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
L_8008957C:
    // 0x8008957C: addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
L_80089580:
    // 0x80089580: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80089584: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80089588: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
    // 0x8008958C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80089590: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80089594: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80089598: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8008959C: divu        $zero, $v0, $a0
    lo = S32(U32(ctx->r2) / U32(ctx->r4)); hi = S32(U32(ctx->r2) % U32(ctx->r4));
    // 0x800895A0: bne         $a0, $zero, L_800895AC
    if (ctx->r4 != 0) {
        // 0x800895A4: nop
    
            goto L_800895AC;
    }
    // 0x800895A4: nop

    // 0x800895A8: break       7
    do_break(2148046248);
L_800895AC:
    // 0x800895AC: mflo        $v0
    ctx->r2 = lo;
    // 0x800895B0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800895B4: jr          $ra
    // 0x800895B8: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    return;
    // 0x800895B8: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
;}
RECOMP_FUNC void func_800895BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800895BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800895C0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800895C4: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800895C8: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800895CC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800895D0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800895D4: srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // 0x800895D8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800895DC: beq         $v0, $zero, L_800895FC
    if (ctx->r2 == 0) {
        // 0x800895E0: addu        $s0, $a0, $zero
        ctx->r16 = ADD32(ctx->r4, 0);
            goto L_800895FC;
    }
    // 0x800895E0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800895E4: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x800895E8: andi        $v0, $v1, 0x30
    ctx->r2 = ctx->r3 & 0X30;
    // 0x800895EC: beq         $v0, $zero, L_80089644
    if (ctx->r2 == 0) {
        // 0x800895F0: ori         $v0, $v1, 0x4
        ctx->r2 = ctx->r3 | 0X4;
            goto L_80089644;
    }
    // 0x800895F0: ori         $v0, $v1, 0x4
    ctx->r2 = ctx->r3 | 0X4;
    // 0x800895F4: j           L_8008960C
    // 0x800895F8: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
        goto L_8008960C;
    // 0x800895F8: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
L_800895FC:
    // 0x800895FC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80089600: addiu       $v1, $zero, -0x5
    ctx->r3 = ADD32(0, -0X5);
    // 0x80089604: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80089608: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
L_8008960C:
    // 0x8008960C: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x80089610: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80089614: beq         $v0, $zero, L_8008965C
    if (ctx->r2 == 0) {
        // 0x80089618: lui         $v1, 0xFFF7
        ctx->r3 = S32(0XFFF7 << 16);
            goto L_8008965C;
    }
    // 0x80089618: lui         $v1, 0xFFF7
    ctx->r3 = S32(0XFFF7 << 16);
    // 0x8008961C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80089620: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x80089624: bne         $v0, $zero, L_8008964C
    if (ctx->r2 != 0) {
        // 0x80089628: nop
    
            goto L_8008964C;
    }
    // 0x80089628: nop

    // 0x8008962C: lbu         $a0, 0x67($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X67);
    // 0x80089630: jal         0x800920FC
    // 0x80089634: nop

    func_800920FC(rdram, ctx);
        goto after_0;
    // 0x80089634: nop

    after_0:
    // 0x80089638: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8008963C: bne         $v0, $zero, L_8008964C
    if (ctx->r2 != 0) {
        // 0x80089640: nop
    
            goto L_8008964C;
    }
    // 0x80089640: nop

L_80089644:
    // 0x80089644: j           L_8008975C
    // 0x80089648: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8008975C;
    // 0x80089648: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8008964C:
    // 0x8008964C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80089650: lui         $v1, 0x8
    ctx->r3 = S32(0X8 << 16);
    // 0x80089654: j           L_80089668
    // 0x80089658: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
        goto L_80089668;
    // 0x80089658: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
L_8008965C:
    // 0x8008965C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80089660: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x80089664: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
L_80089668:
    // 0x80089668: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x8008966C: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x80089670: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80089674: beq         $v0, $zero, L_800896C0
    if (ctx->r2 == 0) {
        // 0x80089678: lui         $v0, 0xA835
        ctx->r2 = S32(0XA835 << 16);
            goto L_800896C0;
    }
    // 0x80089678: lui         $v0, 0xA835
    ctx->r2 = S32(0XA835 << 16);
    // 0x8008967C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80089680: lw          $v1, 0xF54($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XF54);
    // 0x80089684: ori         $v0, $v0, 0x1D63
    ctx->r2 = ctx->r2 | 0X1D63;
    // 0x80089688: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008968C: mflo        $v1
    ctx->r3 = lo;
    // 0x80089690: lhu         $a0, 0x4($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4);
    // 0x80089694: srl         $v0, $v1, 6
    ctx->r2 = S32(U32(ctx->r3) >> 6);
    // 0x80089698: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8008969C: divu        $zero, $v0, $a0
    lo = S32(U32(ctx->r2) / U32(ctx->r4)); hi = S32(U32(ctx->r2) % U32(ctx->r4));
    // 0x800896A0: bne         $a0, $zero, L_800896AC
    if (ctx->r4 != 0) {
        // 0x800896A4: nop
    
            goto L_800896AC;
    }
    // 0x800896A4: nop

    // 0x800896A8: break       7
    do_break(2148046504);
L_800896AC:
    // 0x800896AC: mfhi        $a0
    ctx->r4 = hi;
    // 0x800896B0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800896B4: sw          $v1, 0xF54($at)
    MEM_W(0XF54, ctx->r1) = ctx->r3;
    // 0x800896B8: j           L_800896C8
    // 0x800896BC: sw          $a0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r4;
        goto L_800896C8;
    // 0x800896BC: sw          $a0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r4;
L_800896C0:
    // 0x800896C0: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x800896C4: sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
L_800896C8:
    // 0x800896C8: lw          $v1, 0x40($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X40);
    // 0x800896CC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800896D0: beq         $v1, $v0, L_80089754
    if (ctx->r3 == ctx->r2) {
        // 0x800896D4: nop
    
            goto L_80089754;
    }
    // 0x800896D4: nop

    // 0x800896D8: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x800896DC: srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // 0x800896E0: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800896E4: beq         $v0, $zero, L_800896F4
    if (ctx->r2 == 0) {
        // 0x800896E8: sll         $v0, $v1, 8
        ctx->r2 = S32(ctx->r3 << 8);
            goto L_800896F4;
    }
    // 0x800896E8: sll         $v0, $v1, 8
    ctx->r2 = S32(ctx->r3 << 8);
    // 0x800896EC: j           L_80089754
    // 0x800896F0: sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
        goto L_80089754;
    // 0x800896F0: sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
L_800896F4:
    // 0x800896F4: lbu         $v1, 0x4F($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4F);
    // 0x800896F8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800896FC: addiu       $a0, $a0, -0x5330
    ctx->r4 = ADD32(ctx->r4, -0X5330);
    // 0x80089700: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80089704: beq         $v1, $v0, L_80089718
    if (ctx->r3 == ctx->r2) {
        // 0x80089708: addiu       $a1, $s0, 0x40
        ctx->r5 = ADD32(ctx->r16, 0X40);
            goto L_80089718;
    }
    // 0x80089708: addiu       $a1, $s0, 0x40
    ctx->r5 = ADD32(ctx->r16, 0X40);
    // 0x8008970C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80089710: j           L_8008971C
    // 0x80089714: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
        goto L_8008971C;
    // 0x80089714: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
L_80089718:
    // 0x80089718: addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
L_8008971C:
    // 0x8008971C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80089720: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80089724: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
    // 0x80089728: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008972C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80089730: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80089734: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x80089738: divu        $zero, $v0, $a0
    lo = S32(U32(ctx->r2) / U32(ctx->r4)); hi = S32(U32(ctx->r2) % U32(ctx->r4));
    // 0x8008973C: bne         $a0, $zero, L_80089748
    if (ctx->r4 != 0) {
        // 0x80089740: nop
    
            goto L_80089748;
    }
    // 0x80089740: nop

    // 0x80089744: break       7
    do_break(2148046660);
L_80089748:
    // 0x80089748: mflo        $v0
    ctx->r2 = lo;
    // 0x8008974C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80089750: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_80089754:
    // 0x80089754: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    // 0x80089758: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
L_8008975C:
    // 0x8008975C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80089760: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80089764: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80089768: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008976C: jr          $ra
    // 0x80089770: nop

    return;
    // 0x80089770: nop

;}
RECOMP_FUNC void func_80089774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089774: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80089778: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008977C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80089780: jal         0x800895BC
    // 0x80089784: sb          $v0, 0x5($a1)
    MEM_B(0X5, ctx->r5) = ctx->r2;
    func_800895BC(rdram, ctx);
        goto after_0;
    // 0x80089784: sb          $v0, 0x5($a1)
    MEM_B(0X5, ctx->r5) = ctx->r2;
    after_0:
    // 0x80089788: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8008978C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80089790: jr          $ra
    // 0x80089794: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80089794: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80089798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089798: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008979C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800897A0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800897A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800897A8: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800897AC: jal         0x800862F4
    // 0x800897B0: sb          $zero, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = 0;
    func_800862F4(rdram, ctx);
        goto after_0;
    // 0x800897B0: sb          $zero, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = 0;
    after_0:
    // 0x800897B4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800897B8: sw          $v0, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r2;
    // 0x800897BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800897C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800897C4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800897C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800897CC: jr          $ra
    // 0x800897D0: nop

    return;
    // 0x800897D0: nop

;}
RECOMP_FUNC void func_800897D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800897D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800897D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800897DC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800897E0: lbu         $v0, 0x2($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X2);
    // 0x800897E4: beq         $v0, $zero, L_800897F8
    if (ctx->r2 == 0) {
        // 0x800897E8: addu        $s0, $a0, $zero
        ctx->r16 = ADD32(ctx->r4, 0);
            goto L_800897F8;
    }
    // 0x800897E8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800897EC: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x800897F0: bne         $a0, $zero, L_80089818
    if (ctx->r4 != 0) {
        // 0x800897F4: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80089818;
    }
    // 0x800897F4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800897F8:
    // 0x800897F8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800897FC: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80089800: jal         0x800862F4
    // 0x80089804: sb          $zero, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = 0;
    func_800862F4(rdram, ctx);
        goto after_0;
    // 0x80089804: sb          $zero, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = 0;
    after_0:
    // 0x80089808: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008980C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80089810: j           L_80089824
    // 0x80089814: sw          $v1, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r3;
        goto L_80089824;
    // 0x80089814: sw          $v1, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r3;
L_80089818:
    // 0x80089818: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
    // 0x8008981C: sw          $a0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r4;
    // 0x80089820: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
L_80089824:
    // 0x80089824: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80089828: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8008982C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80089830: jr          $ra
    // 0x80089834: nop

    return;
    // 0x80089834: nop

;}
RECOMP_FUNC void func_80089838(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089838: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008983C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80089840: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80089844: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80089848: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x8008984C: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80089850: lhu         $v0, 0x54($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X54);
    // 0x80089854: lbu         $v1, 0x2($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X2);
    // 0x80089858: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8008985C: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80089860: bne         $v0, $zero, L_80089894
    if (ctx->r2 != 0) {
        // 0x80089864: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80089894;
    }
    // 0x80089864: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80089868: jal         0x80085CE8
    // 0x8008986C: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    func_80085CE8(rdram, ctx);
        goto after_0;
    // 0x8008986C: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    after_0:
    // 0x80089870: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80089874: beq         $v1, $zero, L_80089894
    if (ctx->r3 == 0) {
        // 0x80089878: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80089894;
    }
    // 0x80089878: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8008987C: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // 0x80089880: lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X6);
    // 0x80089884: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80089888: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8008988C: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x80089890: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80089894:
    // 0x80089894: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80089898: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008989C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800898A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800898A4: jr          $ra
    // 0x800898A8: nop

    return;
    // 0x800898A8: nop

;}
RECOMP_FUNC void func_800898AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800898AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800898B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800898B4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800898B8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800898BC: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800898C0: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800898C4: lhu         $v0, 0x30($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X30);
    // 0x800898C8: lbu         $v1, 0x2($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X2);
    // 0x800898CC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800898D0: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800898D4: bne         $v0, $zero, L_80089908
    if (ctx->r2 != 0) {
        // 0x800898D8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80089908;
    }
    // 0x800898D8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800898DC: jal         0x80085CE8
    // 0x800898E0: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    func_80085CE8(rdram, ctx);
        goto after_0;
    // 0x800898E0: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    after_0:
    // 0x800898E4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800898E8: beq         $v1, $zero, L_80089908
    if (ctx->r3 == 0) {
        // 0x800898EC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80089908;
    }
    // 0x800898EC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800898F0: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // 0x800898F4: lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X6);
    // 0x800898F8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800898FC: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80089900: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x80089904: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80089908:
    // 0x80089908: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8008990C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80089910: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80089914: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80089918: jr          $ra
    // 0x8008991C: nop

    return;
    // 0x8008991C: nop

;}
RECOMP_FUNC void func_80089920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089920: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80089924: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80089928: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8008992C: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80089930: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80089934: lbu         $v1, 0x4E($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4E);
    // 0x80089938: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8008993C: beq         $v1, $v0, L_80089990
    if (ctx->r3 == ctx->r2) {
        // 0x80089940: addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
            goto L_80089990;
    }
    // 0x80089940: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80089944: jal         0x80084860
    // 0x80089948: addiu       $a1, $s0, 0x11A
    ctx->r5 = ADD32(ctx->r16, 0X11A);
    func_80084860(rdram, ctx);
        goto after_0;
    // 0x80089948: addiu       $a1, $s0, 0x11A
    ctx->r5 = ADD32(ctx->r16, 0X11A);
    after_0:
    // 0x8008994C: srl         $v0, $v0, 7
    ctx->r2 = S32(U32(ctx->r2) >> 7);
    // 0x80089950: lbu         $v1, 0x2($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X2);
    // 0x80089954: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80089958: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8008995C: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80089960: bne         $v0, $zero, L_80089994
    if (ctx->r2 != 0) {
        // 0x80089964: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80089994;
    }
    // 0x80089964: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80089968: jal         0x80085CE8
    // 0x8008996C: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    func_80085CE8(rdram, ctx);
        goto after_1;
    // 0x8008996C: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    after_1:
    // 0x80089970: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80089974: beq         $v1, $zero, L_80089994
    if (ctx->r3 == 0) {
        // 0x80089978: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80089994;
    }
    // 0x80089978: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8008997C: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // 0x80089980: lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X6);
    // 0x80089984: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80089988: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8008998C: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_80089990:
    // 0x80089990: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80089994:
    // 0x80089994: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80089998: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008999C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800899A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800899A4: jr          $ra
    // 0x800899A8: nop

    return;
    // 0x800899A8: nop

;}
RECOMP_FUNC void func_800899AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800899AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800899B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800899B4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800899B8: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800899BC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800899C0: lbu         $v1, 0x4E($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4E);
    // 0x800899C4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800899C8: beq         $v1, $v0, L_80089A34
    if (ctx->r3 == ctx->r2) {
        // 0x800899CC: addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
            goto L_80089A34;
    }
    // 0x800899CC: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800899D0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800899D4: lw          $v0, 0xF54($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XF54);
    // 0x800899D8: lui         $v1, 0xA835
    ctx->r3 = S32(0XA835 << 16);
    // 0x800899DC: ori         $v1, $v1, 0x1D63
    ctx->r3 = ctx->r3 | 0X1D63;
    // 0x800899E0: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800899E4: mflo        $v0
    ctx->r2 = lo;
    // 0x800899E8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800899EC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800899F0: sw          $v0, 0xF54($at)
    MEM_W(0XF54, ctx->r1) = ctx->r2;
    // 0x800899F4: lbu         $v1, 0x2($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X2);
    // 0x800899F8: srl         $v0, $v0, 6
    ctx->r2 = S32(U32(ctx->r2) >> 6);
    // 0x800899FC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80089A00: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80089A04: bne         $v0, $zero, L_80089A38
    if (ctx->r2 != 0) {
        // 0x80089A08: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80089A38;
    }
    // 0x80089A08: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80089A0C: jal         0x80085CE8
    // 0x80089A10: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    func_80085CE8(rdram, ctx);
        goto after_0;
    // 0x80089A10: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    after_0:
    // 0x80089A14: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80089A18: beq         $v1, $zero, L_80089A38
    if (ctx->r3 == 0) {
        // 0x80089A1C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80089A38;
    }
    // 0x80089A1C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80089A20: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // 0x80089A24: lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X6);
    // 0x80089A28: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80089A2C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80089A30: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_80089A34:
    // 0x80089A34: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80089A38:
    // 0x80089A38: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80089A3C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80089A40: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80089A44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80089A48: jr          $ra
    // 0x80089A4C: nop

    return;
    // 0x80089A4C: nop

;}
RECOMP_FUNC void func_80089A50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089A50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80089A54: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80089A58: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80089A5C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80089A60: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80089A64: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80089A68: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    // 0x80089A6C: jal         0x80085CE8
    // 0x80089A70: nop

    func_80085CE8(rdram, ctx);
        goto after_0;
    // 0x80089A70: nop

    after_0:
    // 0x80089A74: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80089A78: bne         $a0, $zero, L_80089AA0
    if (ctx->r4 != 0) {
        // 0x80089A7C: nop
    
            goto L_80089AA0;
    }
    // 0x80089A7C: nop

    // 0x80089A80: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80089A84: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80089A88: jal         0x800862F4
    // 0x80089A8C: sb          $zero, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = 0;
    func_800862F4(rdram, ctx);
        goto after_1;
    // 0x80089A8C: sb          $zero, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = 0;
    after_1:
    // 0x80089A90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80089A94: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80089A98: j           L_80089AC8
    // 0x80089A9C: sw          $v1, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r3;
        goto L_80089AC8;
    // 0x80089A9C: sw          $v1, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r3;
L_80089AA0:
    // 0x80089AA0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80089AA4: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x80089AA8: sw          $a0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r4;
    // 0x80089AAC: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x80089AB0: sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // 0x80089AB4: lhu         $v1, 0x6($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X6);
    // 0x80089AB8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80089ABC: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80089AC0: addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // 0x80089AC4: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
L_80089AC8:
    // 0x80089AC8: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80089ACC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80089AD0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80089AD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80089AD8: jr          $ra
    // 0x80089ADC: nop

    return;
    // 0x80089ADC: nop

;}
RECOMP_FUNC void func_80089AE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089AE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80089AE4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80089AE8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80089AEC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80089AF0: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80089AF4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80089AF8: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x80089AFC: jal         0x80085CE8
    // 0x80089B00: nop

    func_80085CE8(rdram, ctx);
        goto after_0;
    // 0x80089B00: nop

    after_0:
    // 0x80089B04: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80089B08: beq         $v1, $zero, L_80089B28
    if (ctx->r3 == 0) {
        // 0x80089B0C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80089B28;
    }
    // 0x80089B0C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80089B10: sw          $v1, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r3;
    // 0x80089B14: lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6);
    // 0x80089B18: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80089B1C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80089B20: sw          $v0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r2;
    // 0x80089B24: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80089B28:
    // 0x80089B28: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80089B2C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80089B30: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80089B34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80089B38: jr          $ra
    // 0x80089B3C: nop

    return;
    // 0x80089B3C: nop

;}
RECOMP_FUNC void func_80089B40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089B40: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80089B44: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x80089B48: jr          $ra
    // 0x80089B4C: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    return;
    // 0x80089B4C: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
;}
RECOMP_FUNC void func_80089B50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089B50: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80089B54: lhu         $v0, 0x6C($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X6C);
    // 0x80089B58: bne         $v0, $zero, L_80089BD4
    if (ctx->r2 != 0) {
        // 0x80089B5C: nop
    
            goto L_80089BD4;
    }
    // 0x80089B5C: nop

    // 0x80089B60: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x80089B64: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80089B68: beq         $v0, $zero, L_80089BB4
    if (ctx->r2 == 0) {
        // 0x80089B6C: lui         $v0, 0xA835
        ctx->r2 = S32(0XA835 << 16);
            goto L_80089BB4;
    }
    // 0x80089B6C: lui         $v0, 0xA835
    ctx->r2 = S32(0XA835 << 16);
    // 0x80089B70: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80089B74: lw          $v1, 0xF54($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XF54);
    // 0x80089B78: ori         $v0, $v0, 0x1D63
    ctx->r2 = ctx->r2 | 0X1D63;
    // 0x80089B7C: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80089B80: mflo        $v1
    ctx->r3 = lo;
    // 0x80089B84: lhu         $a0, 0x4($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X4);
    // 0x80089B88: srl         $v0, $v1, 6
    ctx->r2 = S32(U32(ctx->r3) >> 6);
    // 0x80089B8C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80089B90: divu        $zero, $v0, $a0
    lo = S32(U32(ctx->r2) / U32(ctx->r4)); hi = S32(U32(ctx->r2) % U32(ctx->r4));
    // 0x80089B94: bne         $a0, $zero, L_80089BA0
    if (ctx->r4 != 0) {
        // 0x80089B98: nop
    
            goto L_80089BA0;
    }
    // 0x80089B98: nop

    // 0x80089B9C: break       7
    do_break(2148047772);
L_80089BA0:
    // 0x80089BA0: mfhi        $a0
    ctx->r4 = hi;
    // 0x80089BA4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80089BA8: sw          $v1, 0xF54($at)
    MEM_W(0XF54, ctx->r1) = ctx->r3;
    // 0x80089BAC: j           L_80089BBC
    // 0x80089BB0: sh          $a0, 0x6C($a2)
    MEM_H(0X6C, ctx->r6) = ctx->r4;
        goto L_80089BBC;
    // 0x80089BB0: sh          $a0, 0x6C($a2)
    MEM_H(0X6C, ctx->r6) = ctx->r4;
L_80089BB4:
    // 0x80089BB4: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    // 0x80089BB8: sh          $v0, 0x6C($a2)
    MEM_H(0X6C, ctx->r6) = ctx->r2;
L_80089BBC:
    // 0x80089BBC: lhu         $a0, 0x6C($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X6C);
    // 0x80089BC0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80089BC4: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x80089BC8: beq         $v1, $v0, L_80089BEC
    if (ctx->r3 == ctx->r2) {
        // 0x80089BCC: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_80089BEC;
    }
    // 0x80089BCC: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80089BD0: sh          $v0, 0x6C($a2)
    MEM_H(0X6C, ctx->r6) = ctx->r2;
L_80089BD4:
    // 0x80089BD4: lhu         $v0, 0x6C($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X6C);
    // 0x80089BD8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80089BDC: sh          $v0, 0x6C($a2)
    MEM_H(0X6C, ctx->r6) = ctx->r2;
    // 0x80089BE0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80089BE4: beq         $v0, $zero, L_80089C3C
    if (ctx->r2 == 0) {
        // 0x80089BE8: nop
    
            goto L_80089C3C;
    }
    // 0x80089BE8: nop

L_80089BEC:
    // 0x80089BEC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80089BF0: srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // 0x80089BF4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80089BF8: beq         $v0, $zero, L_80089C28
    if (ctx->r2 == 0) {
        // 0x80089BFC: nop
    
            goto L_80089C28;
    }
    // 0x80089BFC: nop

    // 0x80089C00: lw          $v1, 0x24($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X24);
    // 0x80089C04: lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // 0x80089C08: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x80089C0C: bne         $v0, $zero, L_80089C28
    if (ctx->r2 != 0) {
        // 0x80089C10: nop
    
            goto L_80089C28;
    }
    // 0x80089C10: nop

    // 0x80089C14: andi        $v0, $v1, 0x8
    ctx->r2 = ctx->r3 & 0X8;
    // 0x80089C18: beq         $v0, $zero, L_80089C28
    if (ctx->r2 == 0) {
        // 0x80089C1C: nop
    
            goto L_80089C28;
    }
    // 0x80089C1C: nop

    // 0x80089C20: j           L_80089C3C
    // 0x80089C24: sh          $zero, 0x6C($a2)
    MEM_H(0X6C, ctx->r6) = 0;
        goto L_80089C3C;
    // 0x80089C24: sh          $zero, 0x6C($a2)
    MEM_H(0X6C, ctx->r6) = 0;
L_80089C28:
    // 0x80089C28: lhu         $v0, 0x6($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X6);
    // 0x80089C2C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80089C30: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80089C34: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80089C38: sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
L_80089C3C:
    // 0x80089C3C: jr          $ra
    // 0x80089C40: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80089C40: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_80089C44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089C44: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80089C48: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x80089C4C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80089C50: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80089C54: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80089C58: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80089C5C: lhu         $a0, 0x52($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X52);
    // 0x80089C60: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80089C64: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80089C68: addu        $a2, $a0, $v0
    ctx->r6 = ADD32(ctx->r4, ctx->r2);
    // 0x80089C6C: srl         $v1, $v1, 16
    ctx->r3 = S32(U32(ctx->r3) >> 16);
    // 0x80089C70: lbu         $v0, 0x5($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X5);
    // 0x80089C74: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80089C78: lbu         $a0, 0x6($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X6);
    // 0x80089C7C: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x80089C80: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80089C84: bltz        $a2, L_80089CA0
    if (SIGNED(ctx->r6) < 0) {
        // 0x80089C88: or          $a0, $v1, $a0
        ctx->r4 = ctx->r3 | ctx->r4;
            goto L_80089CA0;
    }
    // 0x80089C88: or          $a0, $v1, $a0
    ctx->r4 = ctx->r3 | ctx->r4;
    // 0x80089C8C: slti        $v0, $a2, 0x80
    ctx->r2 = SIGNED(ctx->r6) < 0X80 ? 1 : 0;
    // 0x80089C90: beq         $v0, $zero, L_80089CA4
    if (ctx->r2 == 0) {
        // 0x80089C94: addiu       $a1, $zero, 0x7F
        ctx->r5 = ADD32(0, 0X7F);
            goto L_80089CA4;
    }
    // 0x80089C94: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x80089C98: j           L_80089CA4
    // 0x80089C9C: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
        goto L_80089CA4;
    // 0x80089C9C: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
L_80089CA0:
    // 0x80089CA0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80089CA4:
    // 0x80089CA4: lbu         $v0, 0x50($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X50);
    // 0x80089CA8: beq         $v0, $zero, L_80089CB4
    if (ctx->r2 == 0) {
        // 0x80089CAC: addu        $a2, $a1, $zero
        ctx->r6 = ADD32(ctx->r5, 0);
            goto L_80089CB4;
    }
    // 0x80089CAC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80089CB0: ori         $a2, $a2, 0x80
    ctx->r6 = ctx->r6 | 0X80;
L_80089CB4:
    // 0x80089CB4: lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X39);
    // 0x80089CB8: lhu         $a1, 0xB6($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0XB6);
    // 0x80089CBC: lbu         $a3, 0x31($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X31);
    // 0x80089CC0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80089CC4: lbu         $v0, 0x4E($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4E);
    // 0x80089CC8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80089CCC: lbu         $v0, 0x4F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4F);
    // 0x80089CD0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80089CD4: lhu         $v0, 0x6($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X6);
    // 0x80089CD8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80089CDC: lbu         $v0, 0x2F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2F);
    // 0x80089CE0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80089CE4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80089CE8: lbu         $v0, 0xBA($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XBA);
    // 0x80089CEC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80089CF0: jal         0x80086FC4
    // 0x80089CF4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_80086FC4(rdram, ctx);
        goto after_0;
    // 0x80089CF4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_0:
    // 0x80089CF8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80089CFC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80089D00: sw          $a0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r4;
    // 0x80089D04: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80089D08: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x80089D0C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80089D10: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80089D14: lw          $a1, 0x64($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X64);
    // 0x80089D18: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80089D1C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80089D20: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80089D24: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80089D28: sw          $a1, -0x276C($at)
    MEM_W(-0X276C, ctx->r1) = ctx->r5;
    // 0x80089D2C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80089D30: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80089D34: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80089D38: jr          $ra
    // 0x80089D3C: nop

    return;
    // 0x80089D3C: nop

;}
RECOMP_FUNC void func_80089D40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089D40: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80089D44: lbu         $v0, 0x2($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X2);
    // 0x80089D48: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80089D4C: lhu         $a0, 0x52($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X52);
    // 0x80089D50: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x80089D54: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x80089D58: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80089D5C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80089D60: lbu         $v0, 0x1AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1AD0);
    // 0x80089D64: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80089D68: beq         $v0, $zero, L_80089E00
    if (ctx->r2 == 0) {
        // 0x80089D6C: or          $a0, $a0, $v1
        ctx->r4 = ctx->r4 | ctx->r3;
            goto L_80089E00;
    }
    // 0x80089D6C: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x80089D70: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x80089D74: lbu         $t1, 0xF50($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0XF50);
    // 0x80089D78: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80089D7C: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80089D80: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_80089D84:
    // 0x80089D84: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80089D88: addu        $at, $at, $a3
    ctx->r1 = ADD32(ctx->r1, ctx->r7);
    // 0x80089D8C: lw          $a1, -0x271C($at)
    ctx->r5 = MEM_W(ctx->r1, -0X271C);
    // 0x80089D90: or          $v0, $a0, $a2
    ctx->r2 = ctx->r4 | ctx->r6;
    // 0x80089D94: bnel        $a1, $v0, L_80089DF4
    if (ctx->r5 != ctx->r2) {
        // 0x80089D98: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80089DF4;
    }
    goto skip_0;
    // 0x80089D98: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_0:
    // 0x80089D9C: beql        $t1, $zero, L_80089DF4
    if (ctx->r9 == 0) {
        // 0x80089DA0: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80089DF4;
    }
    goto skip_1;
    // 0x80089DA0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_1:
    // 0x80089DA4: beq         $a1, $t2, L_80089DF0
    if (ctx->r5 == ctx->r10) {
        // 0x80089DA8: andi        $v0, $a1, 0xFF
        ctx->r2 = ctx->r5 & 0XFF;
            goto L_80089DF0;
    }
    // 0x80089DA8: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x80089DAC: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80089DB0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80089DB4: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80089DB8: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80089DBC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80089DC0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80089DC4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80089DC8: lw          $v0, -0x271C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X271C);
    // 0x80089DCC: bnel        $v0, $a1, L_80089DF4
    if (ctx->r2 != ctx->r5) {
        // 0x80089DD0: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80089DF4;
    }
    goto skip_2;
    // 0x80089DD0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_2:
    // 0x80089DD4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80089DD8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80089DDC: lw          $v0, -0x275C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X275C);
    // 0x80089DE0: ori         $v0, $v0, 0x8
    ctx->r2 = ctx->r2 | 0X8;
    // 0x80089DE4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80089DE8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80089DEC: sw          $v0, -0x275C($at)
    MEM_W(-0X275C, ctx->r1) = ctx->r2;
L_80089DF0:
    // 0x80089DF0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80089DF4:
    // 0x80089DF4: sltu        $v0, $a2, $t0
    ctx->r2 = ctx->r6 < ctx->r8 ? 1 : 0;
    // 0x80089DF8: bne         $v0, $zero, L_80089D84
    if (ctx->r2 != 0) {
        // 0x80089DFC: addiu       $a3, $a3, 0x17C
        ctx->r7 = ADD32(ctx->r7, 0X17C);
            goto L_80089D84;
    }
    // 0x80089DFC: addiu       $a3, $a3, 0x17C
    ctx->r7 = ADD32(ctx->r7, 0X17C);
L_80089E00:
    // 0x80089E00: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80089E04: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x80089E08: jr          $ra
    // 0x80089E0C: nop

    return;
    // 0x80089E0C: nop

;}
RECOMP_FUNC void func_80089E10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089E10: lhu         $v1, 0x28($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X28);
    // 0x80089E14: lh          $v0, 0x0($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X0);
    // 0x80089E18: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80089E1C: bgezl       $v1, L_80089E2C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80089E20: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_80089E2C;
    }
    goto skip_0;
    // 0x80089E20: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    skip_0:
    // 0x80089E24: j           L_80089E40
    // 0x80089E28: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
        goto L_80089E40;
    // 0x80089E28: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
L_80089E2C:
    // 0x80089E2C: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80089E30: beql        $v0, $zero, L_80089E3C
    if (ctx->r2 == 0) {
        // 0x80089E34: sll         $v0, $v1, 16
        ctx->r2 = S32(ctx->r3 << 16);
            goto L_80089E3C;
    }
    goto skip_1;
    // 0x80089E34: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    skip_1:
    // 0x80089E38: lui         $v0, 0xFFFF
    ctx->r2 = S32(0XFFFF << 16);
L_80089E3C:
    // 0x80089E3C: sw          $v0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r2;
L_80089E40:
    // 0x80089E40: jr          $ra
    // 0x80089E44: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80089E44: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_80089E48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089E48: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x80089E4C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80089E50: sw          $v0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r2;
    // 0x80089E54: jr          $ra
    // 0x80089E58: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80089E58: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_80089E5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089E5C: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x80089E60: beql        $v1, $zero, L_80089E88
    if (ctx->r3 == 0) {
        // 0x80089E64: sh          $zero, 0x2C($a0)
        MEM_H(0X2C, ctx->r4) = 0;
            goto L_80089E88;
    }
    goto skip_0;
    // 0x80089E64: sh          $zero, 0x2C($a0)
    MEM_H(0X2C, ctx->r4) = 0;
    skip_0:
    // 0x80089E68: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    // 0x80089E6C: srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // 0x80089E70: divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // 0x80089E74: bne         $v1, $zero, L_80089E80
    if (ctx->r3 != 0) {
        // 0x80089E78: nop
    
            goto L_80089E80;
    }
    // 0x80089E78: nop

    // 0x80089E7C: break       7
    do_break(2148048508);
L_80089E80:
    // 0x80089E80: mflo        $v0
    ctx->r2 = lo;
    // 0x80089E84: sh          $v0, 0x2C($a0)
    MEM_H(0X2C, ctx->r4) = ctx->r2;
L_80089E88:
    // 0x80089E88: jr          $ra
    // 0x80089E8C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80089E8C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_80089E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089E90: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x80089E94: lbu         $v0, 0x2E($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2E);
    // 0x80089E98: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80089E9C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80089EA0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80089EA4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80089EA8: bgezl       $v0, L_80089EB8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80089EAC: slti        $v0, $v0, 0x100
        ctx->r2 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
            goto L_80089EB8;
    }
    goto skip_0;
    // 0x80089EAC: slti        $v0, $v0, 0x100
    ctx->r2 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    skip_0:
    // 0x80089EB0: j           L_80089EC8
    // 0x80089EB4: sb          $zero, 0x2E($a0)
    MEM_B(0X2E, ctx->r4) = 0;
        goto L_80089EC8;
    // 0x80089EB4: sb          $zero, 0x2E($a0)
    MEM_B(0X2E, ctx->r4) = 0;
L_80089EB8:
    // 0x80089EB8: bnel        $v0, $zero, L_80089EC8
    if (ctx->r2 != 0) {
        // 0x80089EBC: sb          $v1, 0x2E($a0)
        MEM_B(0X2E, ctx->r4) = ctx->r3;
            goto L_80089EC8;
    }
    goto skip_1;
    // 0x80089EBC: sb          $v1, 0x2E($a0)
    MEM_B(0X2E, ctx->r4) = ctx->r3;
    skip_1:
    // 0x80089EC0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80089EC4: sb          $v0, 0x2E($a0)
    MEM_B(0X2E, ctx->r4) = ctx->r2;
L_80089EC8:
    // 0x80089EC8: jr          $ra
    // 0x80089ECC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80089ECC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_80089ED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089ED0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80089ED4: srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // 0x80089ED8: sb          $v0, 0x2E($a0)
    MEM_B(0X2E, ctx->r4) = ctx->r2;
    // 0x80089EDC: jr          $ra
    // 0x80089EE0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80089EE0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_80089EE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089EE4: lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X2);
    // 0x80089EE8: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x80089EEC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80089EF0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80089EF4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80089EF8: sb          $v0, -0x73A8($at)
    MEM_B(-0X73A8, ctx->r1) = ctx->r2;
    // 0x80089EFC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80089F00: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80089F04: jr          $ra
    // 0x80089F08: nop

    return;
    // 0x80089F08: nop

;}
RECOMP_FUNC void func_80089F0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089F0C: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x80089F10: sb          $v0, 0x6E($a0)
    MEM_B(0X6E, ctx->r4) = ctx->r2;
    // 0x80089F14: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80089F18: srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // 0x80089F1C: sb          $v0, 0x6F($a0)
    MEM_B(0X6F, ctx->r4) = ctx->r2;
    // 0x80089F20: jr          $ra
    // 0x80089F24: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80089F24: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_80089F28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089F28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80089F2C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80089F30: lw          $v0, 0x70($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X70);
    // 0x80089F34: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80089F38: sw          $v0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r2;
    // 0x80089F3C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80089F40: jal         0x800895BC
    // 0x80089F44: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    func_800895BC(rdram, ctx);
        goto after_0;
    // 0x80089F44: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    after_0:
    // 0x80089F48: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80089F4C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80089F50: jr          $ra
    // 0x80089F54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80089F54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80089F58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089F58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80089F5C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80089F60: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80089F64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80089F68: lb          $v0, 0xBC($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XBC);
    // 0x80089F6C: beql        $v0, $zero, L_8008A000
    if (ctx->r2 == 0) {
        // 0x80089F70: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8008A000;
    }
    goto skip_0;
    // 0x80089F70: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_0:
    // 0x80089F74: blez        $v0, L_80089FC0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80089F78: nop
    
            goto L_80089FC0;
    }
    // 0x80089F78: nop

    // 0x80089F7C: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
    // 0x80089F80: jal         0x80093F3C
    // 0x80089F84: nop

    func_80093F3C(rdram, ctx);
        goto after_0;
    // 0x80089F84: nop

    after_0:
    // 0x80089F88: lw          $v1, 0x70($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X70);
    // 0x80089F8C: lb          $a0, 0xBC($s0)
    ctx->r4 = MEM_B(ctx->r16, 0XBC);
    // 0x80089F90: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80089F94: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80089F98: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80089F9C: mflo        $v0
    ctx->r2 = lo;
    // 0x80089FA0: lui         $v1, 0x51EB
    ctx->r3 = S32(0X51EB << 16);
    // 0x80089FA4: ori         $v1, $v1, 0x851F
    ctx->r3 = ctx->r3 | 0X851F;
    // 0x80089FA8: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80089FAC: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80089FB0: mfhi        $a1
    ctx->r5 = hi;
    // 0x80089FB4: sra         $v1, $a1, 5
    ctx->r3 = S32(SIGNED(ctx->r5) >> 5);
    // 0x80089FB8: j           L_8008A000
    // 0x80089FBC: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
        goto L_8008A000;
    // 0x80089FBC: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
L_80089FC0:
    // 0x80089FC0: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
    // 0x80089FC4: jal         0x80093F60
    // 0x80089FC8: nop

    func_80093F60(rdram, ctx);
        goto after_1;
    // 0x80089FC8: nop

    after_1:
    // 0x80089FCC: lw          $v1, 0x70($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X70);
    // 0x80089FD0: lb          $a0, 0xBC($s0)
    ctx->r4 = MEM_B(ctx->r16, 0XBC);
    // 0x80089FD4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80089FD8: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80089FDC: mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80089FE0: mflo        $v1
    ctx->r3 = lo;
    // 0x80089FE4: lui         $v0, 0x51EB
    ctx->r2 = S32(0X51EB << 16);
    // 0x80089FE8: ori         $v0, $v0, 0x851F
    ctx->r2 = ctx->r2 | 0X851F;
    // 0x80089FEC: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80089FF0: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x80089FF4: mfhi        $a1
    ctx->r5 = hi;
    // 0x80089FF8: sra         $v0, $a1, 5
    ctx->r2 = S32(SIGNED(ctx->r5) >> 5);
    // 0x80089FFC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_8008A000:
    // 0x8008A000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008A004: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8008A008: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008A00C: jr          $ra
    // 0x8008A010: nop

    return;
    // 0x8008A010: nop

;}
RECOMP_FUNC void func_8008A014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A014: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008A018: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8008A01C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8008A020: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8008A024: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x8008A028: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8008A02C: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
    // 0x8008A030: lw          $a1, 0x60($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X60);
    // 0x8008A034: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8008A038: jal         0x80093E80
    // 0x8008A03C: sh          $v0, 0x54($s0)
    MEM_H(0X54, ctx->r16) = ctx->r2;
    func_80093E80(rdram, ctx);
        goto after_0;
    // 0x8008A03C: sh          $v0, 0x54($s0)
    MEM_H(0X54, ctx->r16) = ctx->r2;
    after_0:
    // 0x8008A040: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8008A044: sw          $v0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r2;
    // 0x8008A048: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x8008A04C: sb          $v0, 0xBC($s0)
    MEM_B(0XBC, ctx->r16) = ctx->r2;
    // 0x8008A050: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8008A054: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8008A058: beq         $v0, $zero, L_8008A0EC
    if (ctx->r2 == 0) {
        // 0x8008A05C: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8008A0EC;
    }
    // 0x8008A05C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8008A060: blez        $v0, L_8008A0AC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008A064: nop
    
            goto L_8008A0AC;
    }
    // 0x8008A064: nop

    // 0x8008A068: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
    // 0x8008A06C: jal         0x80093F3C
    // 0x8008A070: nop

    func_80093F3C(rdram, ctx);
        goto after_1;
    // 0x8008A070: nop

    after_1:
    // 0x8008A074: lw          $v1, 0x70($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X70);
    // 0x8008A078: lb          $a0, 0xBC($s0)
    ctx->r4 = MEM_B(ctx->r16, 0XBC);
    // 0x8008A07C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8008A080: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008A084: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A088: mflo        $v0
    ctx->r2 = lo;
    // 0x8008A08C: lui         $v1, 0x51EB
    ctx->r3 = S32(0X51EB << 16);
    // 0x8008A090: ori         $v1, $v1, 0x851F
    ctx->r3 = ctx->r3 | 0X851F;
    // 0x8008A094: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A098: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8008A09C: mfhi        $a2
    ctx->r6 = hi;
    // 0x8008A0A0: sra         $v1, $a2, 5
    ctx->r3 = S32(SIGNED(ctx->r6) >> 5);
    // 0x8008A0A4: j           L_8008A0EC
    // 0x8008A0A8: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
        goto L_8008A0EC;
    // 0x8008A0A8: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
L_8008A0AC:
    // 0x8008A0AC: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
    // 0x8008A0B0: jal         0x80093F60
    // 0x8008A0B4: nop

    func_80093F60(rdram, ctx);
        goto after_2;
    // 0x8008A0B4: nop

    after_2:
    // 0x8008A0B8: lw          $v1, 0x70($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X70);
    // 0x8008A0BC: lb          $a0, 0xBC($s0)
    ctx->r4 = MEM_B(ctx->r16, 0XBC);
    // 0x8008A0C0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8008A0C4: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8008A0C8: mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A0CC: mflo        $v1
    ctx->r3 = lo;
    // 0x8008A0D0: lui         $v0, 0x51EB
    ctx->r2 = S32(0X51EB << 16);
    // 0x8008A0D4: ori         $v0, $v0, 0x851F
    ctx->r2 = ctx->r2 | 0X851F;
    // 0x8008A0D8: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A0DC: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x8008A0E0: mfhi        $a2
    ctx->r6 = hi;
    // 0x8008A0E4: sra         $v0, $a2, 5
    ctx->r2 = S32(SIGNED(ctx->r6) >> 5);
    // 0x8008A0E8: subu        $v1, $v0, $v1
    ctx->r3 = SUB32(ctx->r2, ctx->r3);
L_8008A0EC:
    // 0x8008A0EC: lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X70);
    // 0x8008A0F0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8008A0F4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8008A0F8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008A0FC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008A100: sw          $v0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r2;
    // 0x8008A104: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8008A108: jal         0x800895BC
    // 0x8008A10C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    func_800895BC(rdram, ctx);
        goto after_3;
    // 0x8008A10C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    after_3:
    // 0x8008A110: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8008A114: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8008A118: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8008A11C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8008A120: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008A124: jr          $ra
    // 0x8008A128: nop

    return;
    // 0x8008A128: nop

;}
RECOMP_FUNC void func_8008A12C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A12C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008A130: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8008A134: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8008A138: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8008A13C: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x8008A140: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8008A144: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8008A148: srl         $v0, $a0, 24
    ctx->r2 = S32(U32(ctx->r4) >> 24);
    // 0x8008A14C: bne         $v0, $zero, L_8008A160
    if (ctx->r2 != 0) {
        // 0x8008A150: srl         $v0, $a0, 8
        ctx->r2 = S32(U32(ctx->r4) >> 8);
            goto L_8008A160;
    }
    // 0x8008A150: srl         $v0, $a0, 8
    ctx->r2 = S32(U32(ctx->r4) >> 8);
    // 0x8008A154: lhu         $v1, 0x54($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X54);
    // 0x8008A158: j           L_8008A164
    // 0x8008A15C: nop

        goto L_8008A164;
    // 0x8008A15C: nop

L_8008A160:
    // 0x8008A160: lhu         $v1, 0x52($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X52);
L_8008A164:
    // 0x8008A164: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8008A168: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8008A16C: sh          $v1, 0x54($s0)
    MEM_H(0X54, ctx->r16) = ctx->r3;
    // 0x8008A170: lbu         $a0, 0x55($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X55);
    // 0x8008A174: lw          $a1, 0x60($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X60);
    // 0x8008A178: jal         0x80093E80
    // 0x8008A17C: nop

    func_80093E80(rdram, ctx);
        goto after_0;
    // 0x8008A17C: nop

    after_0:
    // 0x8008A180: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8008A184: sw          $v0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r2;
    // 0x8008A188: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x8008A18C: sb          $v0, 0xBC($s0)
    MEM_B(0XBC, ctx->r16) = ctx->r2;
    // 0x8008A190: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8008A194: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8008A198: beq         $v0, $zero, L_8008A22C
    if (ctx->r2 == 0) {
        // 0x8008A19C: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8008A22C;
    }
    // 0x8008A19C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8008A1A0: blez        $v0, L_8008A1EC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008A1A4: nop
    
            goto L_8008A1EC;
    }
    // 0x8008A1A4: nop

    // 0x8008A1A8: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
    // 0x8008A1AC: jal         0x80093F3C
    // 0x8008A1B0: nop

    func_80093F3C(rdram, ctx);
        goto after_1;
    // 0x8008A1B0: nop

    after_1:
    // 0x8008A1B4: lw          $v1, 0x70($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X70);
    // 0x8008A1B8: lb          $a0, 0xBC($s0)
    ctx->r4 = MEM_B(ctx->r16, 0XBC);
    // 0x8008A1BC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8008A1C0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008A1C4: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A1C8: mflo        $v0
    ctx->r2 = lo;
    // 0x8008A1CC: lui         $v1, 0x51EB
    ctx->r3 = S32(0X51EB << 16);
    // 0x8008A1D0: ori         $v1, $v1, 0x851F
    ctx->r3 = ctx->r3 | 0X851F;
    // 0x8008A1D4: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A1D8: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8008A1DC: mfhi        $a2
    ctx->r6 = hi;
    // 0x8008A1E0: sra         $v1, $a2, 5
    ctx->r3 = S32(SIGNED(ctx->r6) >> 5);
    // 0x8008A1E4: j           L_8008A22C
    // 0x8008A1E8: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
        goto L_8008A22C;
    // 0x8008A1E8: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
L_8008A1EC:
    // 0x8008A1EC: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
    // 0x8008A1F0: jal         0x80093F60
    // 0x8008A1F4: nop

    func_80093F60(rdram, ctx);
        goto after_2;
    // 0x8008A1F4: nop

    after_2:
    // 0x8008A1F8: lw          $v1, 0x70($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X70);
    // 0x8008A1FC: lb          $a0, 0xBC($s0)
    ctx->r4 = MEM_B(ctx->r16, 0XBC);
    // 0x8008A200: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8008A204: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8008A208: mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A20C: mflo        $v1
    ctx->r3 = lo;
    // 0x8008A210: lui         $v0, 0x51EB
    ctx->r2 = S32(0X51EB << 16);
    // 0x8008A214: ori         $v0, $v0, 0x851F
    ctx->r2 = ctx->r2 | 0X851F;
    // 0x8008A218: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A21C: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x8008A220: mfhi        $a2
    ctx->r6 = hi;
    // 0x8008A224: sra         $v0, $a2, 5
    ctx->r2 = S32(SIGNED(ctx->r6) >> 5);
    // 0x8008A228: subu        $v1, $v0, $v1
    ctx->r3 = SUB32(ctx->r2, ctx->r3);
L_8008A22C:
    // 0x8008A22C: lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X70);
    // 0x8008A230: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8008A234: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8008A238: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008A23C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008A240: sw          $v0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r2;
    // 0x8008A244: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8008A248: jal         0x800895BC
    // 0x8008A24C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    func_800895BC(rdram, ctx);
        goto after_3;
    // 0x8008A24C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    after_3:
    // 0x8008A250: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8008A254: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8008A258: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8008A25C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8008A260: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008A264: jr          $ra
    // 0x8008A268: nop

    return;
    // 0x8008A268: nop

;}
RECOMP_FUNC void func_8008A26C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A26C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008A270: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8008A274: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8008A278: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8008A27C: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x8008A280: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8008A284: lbu         $v0, 0xBD($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XBD);
    // 0x8008A288: lbu         $v1, 0x2($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X2);
    // 0x8008A28C: lw          $a1, 0x60($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X60);
    // 0x8008A290: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008A294: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8008A298: jal         0x80093E80
    // 0x8008A29C: sh          $v0, 0x54($s0)
    MEM_H(0X54, ctx->r16) = ctx->r2;
    func_80093E80(rdram, ctx);
        goto after_0;
    // 0x8008A29C: sh          $v0, 0x54($s0)
    MEM_H(0X54, ctx->r16) = ctx->r2;
    after_0:
    // 0x8008A2A0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8008A2A4: sw          $v0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r2;
    // 0x8008A2A8: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x8008A2AC: sb          $v0, 0xBC($s0)
    MEM_B(0XBC, ctx->r16) = ctx->r2;
    // 0x8008A2B0: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8008A2B4: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8008A2B8: beq         $v0, $zero, L_8008A34C
    if (ctx->r2 == 0) {
        // 0x8008A2BC: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8008A34C;
    }
    // 0x8008A2BC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8008A2C0: blez        $v0, L_8008A30C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008A2C4: nop
    
            goto L_8008A30C;
    }
    // 0x8008A2C4: nop

    // 0x8008A2C8: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
    // 0x8008A2CC: jal         0x80093F3C
    // 0x8008A2D0: nop

    func_80093F3C(rdram, ctx);
        goto after_1;
    // 0x8008A2D0: nop

    after_1:
    // 0x8008A2D4: lw          $v1, 0x70($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X70);
    // 0x8008A2D8: lb          $a0, 0xBC($s0)
    ctx->r4 = MEM_B(ctx->r16, 0XBC);
    // 0x8008A2DC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8008A2E0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008A2E4: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A2E8: mflo        $v0
    ctx->r2 = lo;
    // 0x8008A2EC: lui         $v1, 0x51EB
    ctx->r3 = S32(0X51EB << 16);
    // 0x8008A2F0: ori         $v1, $v1, 0x851F
    ctx->r3 = ctx->r3 | 0X851F;
    // 0x8008A2F4: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A2F8: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8008A2FC: mfhi        $a2
    ctx->r6 = hi;
    // 0x8008A300: sra         $v1, $a2, 5
    ctx->r3 = S32(SIGNED(ctx->r6) >> 5);
    // 0x8008A304: j           L_8008A34C
    // 0x8008A308: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
        goto L_8008A34C;
    // 0x8008A308: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
L_8008A30C:
    // 0x8008A30C: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
    // 0x8008A310: jal         0x80093F60
    // 0x8008A314: nop

    func_80093F60(rdram, ctx);
        goto after_2;
    // 0x8008A314: nop

    after_2:
    // 0x8008A318: lw          $v1, 0x70($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X70);
    // 0x8008A31C: lb          $a0, 0xBC($s0)
    ctx->r4 = MEM_B(ctx->r16, 0XBC);
    // 0x8008A320: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8008A324: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8008A328: mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A32C: mflo        $v1
    ctx->r3 = lo;
    // 0x8008A330: lui         $v0, 0x51EB
    ctx->r2 = S32(0X51EB << 16);
    // 0x8008A334: ori         $v0, $v0, 0x851F
    ctx->r2 = ctx->r2 | 0X851F;
    // 0x8008A338: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A33C: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x8008A340: mfhi        $a2
    ctx->r6 = hi;
    // 0x8008A344: sra         $v0, $a2, 5
    ctx->r2 = S32(SIGNED(ctx->r6) >> 5);
    // 0x8008A348: subu        $v1, $v0, $v1
    ctx->r3 = SUB32(ctx->r2, ctx->r3);
L_8008A34C:
    // 0x8008A34C: lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X70);
    // 0x8008A350: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8008A354: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8008A358: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008A35C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008A360: sw          $v0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r2;
    // 0x8008A364: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8008A368: jal         0x800895BC
    // 0x8008A36C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    func_800895BC(rdram, ctx);
        goto after_3;
    // 0x8008A36C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    after_3:
    // 0x8008A370: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8008A374: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8008A378: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8008A37C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8008A380: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008A384: jr          $ra
    // 0x8008A388: nop

    return;
    // 0x8008A388: nop

;}
RECOMP_FUNC void func_8008A38C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A38C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008A390: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x8008A394: addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // 0x8008A398: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8008A39C: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x8008A3A0: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x8008A3A4: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8008A3A8: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8008A3AC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8008A3B0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8008A3B4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8008A3B8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8008A3BC: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8008A3C0: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x8008A3C4: srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // 0x8008A3C8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008A3CC: sh          $v0, -0x53B8($at)
    MEM_H(-0X53B8, ctx->r1) = ctx->r2;
    // 0x8008A3D0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008A3D4: lw          $v0, -0x3BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3BB4);
    // 0x8008A3D8: lui         $fp, 0x8014
    ctx->r30 = S32(0X8014 << 16);
    // 0x8008A3DC: addiu       $fp, $fp, -0x4FB8
    ctx->r30 = ADD32(ctx->r30, -0X4FB8);
    // 0x8008A3E0: beq         $v0, $zero, L_8008A438
    if (ctx->r2 == 0) {
        // 0x8008A3E4: addiu       $s7, $zero, 0xC
        ctx->r23 = ADD32(0, 0XC);
            goto L_8008A438;
    }
    // 0x8008A3E4: addiu       $s7, $zero, 0xC
    ctx->r23 = ADD32(0, 0XC);
    // 0x8008A3E8: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8008A3EC: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8008A3F0: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_8008A3F4:
    // 0x8008A3F4: sra         $s2, $v0, 1
    ctx->r18 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8008A3F8: addiu       $s1, $s2, -0x1
    ctx->r17 = ADD32(ctx->r18, -0X1);
    // 0x8008A3FC: mult        $s7, $s1
    result = S64(S32(ctx->r23)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A400: mflo        $v0
    ctx->r2 = lo;
    // 0x8008A404: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008A408: addiu       $a0, $a0, -0x53C0
    ctx->r4 = ADD32(ctx->r4, -0X53C0);
    // 0x8008A40C: addu        $s0, $fp, $v0
    ctx->r16 = ADD32(ctx->r30, ctx->r2);
    // 0x8008A410: jal         0x80085E10
    // 0x8008A414: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80085E10(rdram, ctx);
        goto after_0;
    // 0x8008A414: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8008A418: beql        $v0, $zero, L_8008A43C
    if (ctx->r2 == 0) {
        // 0x8008A41C: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_8008A43C;
    }
    goto skip_0;
    // 0x8008A41C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    skip_0:
    // 0x8008A420: bgezl       $v0, L_8008A42C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008A424: addiu       $s4, $s2, 0x1
        ctx->r20 = ADD32(ctx->r18, 0X1);
            goto L_8008A42C;
    }
    goto skip_1;
    // 0x8008A424: addiu       $s4, $s2, 0x1
    ctx->r20 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x8008A428: addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
L_8008A42C:
    // 0x8008A42C: slt         $v0, $s3, $s4
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8008A430: beq         $v0, $zero, L_8008A3F4
    if (ctx->r2 == 0) {
        // 0x8008A434: addu        $v0, $s4, $s3
        ctx->r2 = ADD32(ctx->r20, ctx->r19);
            goto L_8008A3F4;
    }
    // 0x8008A434: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_8008A438:
    // 0x8008A438: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8008A43C:
    // 0x8008A43C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008A440: sw          $a1, -0x53B4($at)
    MEM_W(-0X53B4, ctx->r1) = ctx->r5;
    // 0x8008A444: beq         $a1, $zero, L_8008A4B8
    if (ctx->r5 == 0) {
        // 0x8008A448: lui         $v1, 0xFF
        ctx->r3 = S32(0XFF << 16);
            goto L_8008A4B8;
    }
    // 0x8008A448: lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // 0x8008A44C: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8008A450: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8008A454: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008A458: sw          $v0, -0x5360($at)
    MEM_W(-0X5360, ctx->r1) = ctx->r2;
    // 0x8008A45C: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x8008A460: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008A464: sw          $zero, -0x5358($at)
    MEM_W(-0X5358, ctx->r1) = 0;
    // 0x8008A468: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008A46C: sw          $v0, -0x535C($at)
    MEM_W(-0X535C, ctx->r1) = ctx->r2;
    // 0x8008A470: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x8008A474: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008A478: sw          $v0, -0x5350($at)
    MEM_W(-0X5350, ctx->r1) = ctx->r2;
    // 0x8008A47C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8008A480: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x8008A484: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8008A488: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008A48C: sw          $v0, -0x5354($at)
    MEM_W(-0X5354, ctx->r1) = ctx->r2;
    // 0x8008A490: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x8008A494: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008A498: sw          $a0, -0x53B0($at)
    MEM_W(-0X53B0, ctx->r1) = ctx->r4;
    // 0x8008A49C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008A4A0: sw          $v0, -0x534C($at)
    MEM_W(-0X534C, ctx->r1) = ctx->r2;
    // 0x8008A4A4: lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4);
    // 0x8008A4A8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008A4AC: sb          $v0, -0x5348($at)
    MEM_B(-0X5348, ctx->r1) = ctx->r2;
    // 0x8008A4B0: j           L_8008A4BC
    // 0x8008A4B4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_8008A4BC;
    // 0x8008A4B4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8008A4B8:
    // 0x8008A4B8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_8008A4BC:
    // 0x8008A4BC: bne         $v1, $zero, L_8008A690
    if (ctx->r3 != 0) {
        // 0x8008A4C0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8008A690;
    }
    // 0x8008A4C0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8008A4C4: lbu         $v0, 0x0($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X0);
    // 0x8008A4C8: bne         $v0, $zero, L_8008A4E4
    if (ctx->r2 != 0) {
        // 0x8008A4CC: addiu       $v0, $zero, 0x7F
        ctx->r2 = ADD32(0, 0X7F);
            goto L_8008A4E4;
    }
    // 0x8008A4CC: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x8008A4D0: lw          $v0, 0x4($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X4);
    // 0x8008A4D4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008A4D8: sw          $v0, -0x5358($at)
    MEM_W(-0X5358, ctx->r1) = ctx->r2;
    // 0x8008A4DC: j           L_8008A520
    // 0x8008A4E0: nop

        goto L_8008A520;
    // 0x8008A4E0: nop

L_8008A4E4:
    // 0x8008A4E4: lhu         $v1, 0x30($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0X30);
    // 0x8008A4E8: lw          $a0, 0x4($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X4);
    // 0x8008A4EC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008A4F0: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A4F4: mflo        $v0
    ctx->r2 = lo;
    // 0x8008A4F8: lui         $v1, 0x204
    ctx->r3 = S32(0X204 << 16);
    // 0x8008A4FC: ori         $v1, $v1, 0x811
    ctx->r3 = ctx->r3 | 0X811;
    // 0x8008A500: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A504: mfhi        $v1
    ctx->r3 = hi;
    // 0x8008A508: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008A50C: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x8008A510: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8008A514: srl         $v1, $v1, 6
    ctx->r3 = S32(U32(ctx->r3) >> 6);
    // 0x8008A518: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008A51C: sw          $v1, -0x5358($at)
    MEM_W(-0X5358, ctx->r1) = ctx->r3;
L_8008A520:
    // 0x8008A520: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008A524: addiu       $a1, $a1, -0x5358
    ctx->r5 = ADD32(ctx->r5, -0X5358);
    // 0x8008A528: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8008A52C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8008A530: lw          $v1, -0x5354($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5354);
    // 0x8008A534: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8008A538: bne         $v0, $zero, L_8008A544
    if (ctx->r2 != 0) {
        // 0x8008A53C: addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
            goto L_8008A544;
    }
    // 0x8008A53C: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x8008A540: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_8008A544:
    // 0x8008A544: lw          $v0, 0x24($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X24);
    // 0x8008A548: lbu         $a0, 0x67($s5)
    ctx->r4 = MEM_BU(ctx->r21, 0X67);
    // 0x8008A54C: andi        $v0, $v0, 0x200
    ctx->r2 = ctx->r2 & 0X200;
    // 0x8008A550: bne         $v0, $zero, L_8008A560
    if (ctx->r2 != 0) {
        // 0x8008A554: addiu       $a1, $a1, -0x8
        ctx->r5 = ADD32(ctx->r5, -0X8);
            goto L_8008A560;
    }
    // 0x8008A554: addiu       $a1, $a1, -0x8
    ctx->r5 = ADD32(ctx->r5, -0X8);
    // 0x8008A558: j           L_8008A564
    // 0x8008A55C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_8008A564;
    // 0x8008A55C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8008A560:
    // 0x8008A560: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_8008A564:
    // 0x8008A564: jal         0x80092128
    // 0x8008A568: nop

    func_80092128(rdram, ctx);
        goto after_1;
    // 0x8008A568: nop

    after_1:
    // 0x8008A56C: lbu         $a0, 0xBD($s5)
    ctx->r4 = MEM_BU(ctx->r21, 0XBD);
    // 0x8008A570: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008A574: lw          $a1, -0x5360($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5360);
    // 0x8008A578: jal         0x80093E80
    // 0x8008A57C: nop

    func_80093E80(rdram, ctx);
        goto after_2;
    // 0x8008A57C: nop

    after_2:
    // 0x8008A580: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008A584: sw          $v0, 0x9C($s5)
    MEM_W(0X9C, ctx->r21) = ctx->r2;
    // 0x8008A588: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008A58C: lw          $v0, -0x5360($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5360);
    // 0x8008A590: sw          $v0, 0x60($s5)
    MEM_W(0X60, ctx->r21) = ctx->r2;
    // 0x8008A594: lw          $v0, 0x24($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X24);
    // 0x8008A598: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8008A59C: lw          $v1, -0x535C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X535C);
    // 0x8008A5A0: ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    // 0x8008A5A4: sw          $v0, 0x24($s5)
    MEM_W(0X24, ctx->r21) = ctx->r2;
    // 0x8008A5A8: andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // 0x8008A5AC: bne         $v0, $zero, L_8008A68C
    if (ctx->r2 != 0) {
        // 0x8008A5B0: sw          $v1, 0x5C($s5)
        MEM_W(0X5C, ctx->r21) = ctx->r3;
            goto L_8008A68C;
    }
    // 0x8008A5B0: sw          $v1, 0x5C($s5)
    MEM_W(0X5C, ctx->r21) = ctx->r3;
    // 0x8008A5B4: lbu         $a0, 0x55($s5)
    ctx->r4 = MEM_BU(ctx->r21, 0X55);
    // 0x8008A5B8: lw          $a1, 0x60($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X60);
    // 0x8008A5BC: jal         0x80093E80
    // 0x8008A5C0: nop

    func_80093E80(rdram, ctx);
        goto after_3;
    // 0x8008A5C0: nop

    after_3:
    // 0x8008A5C4: lb          $v1, 0xBC($s5)
    ctx->r3 = MEM_B(ctx->r21, 0XBC);
    // 0x8008A5C8: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x8008A5CC: beq         $v1, $zero, L_8008A65C
    if (ctx->r3 == 0) {
        // 0x8008A5D0: sw          $a0, 0x70($s5)
        MEM_W(0X70, ctx->r21) = ctx->r4;
            goto L_8008A65C;
    }
    // 0x8008A5D0: sw          $a0, 0x70($s5)
    MEM_W(0X70, ctx->r21) = ctx->r4;
    // 0x8008A5D4: blez        $v1, L_8008A61C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8008A5D8: nop
    
            goto L_8008A61C;
    }
    // 0x8008A5D8: nop

    // 0x8008A5DC: jal         0x80093F3C
    // 0x8008A5E0: nop

    func_80093F3C(rdram, ctx);
        goto after_4;
    // 0x8008A5E0: nop

    after_4:
    // 0x8008A5E4: lw          $v1, 0x70($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X70);
    // 0x8008A5E8: lb          $a0, 0xBC($s5)
    ctx->r4 = MEM_B(ctx->r21, 0XBC);
    // 0x8008A5EC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8008A5F0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008A5F4: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A5F8: mflo        $v0
    ctx->r2 = lo;
    // 0x8008A5FC: lui         $v1, 0x51EB
    ctx->r3 = S32(0X51EB << 16);
    // 0x8008A600: ori         $v1, $v1, 0x851F
    ctx->r3 = ctx->r3 | 0X851F;
    // 0x8008A604: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A608: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8008A60C: mfhi        $a3
    ctx->r7 = hi;
    // 0x8008A610: sra         $v1, $a3, 5
    ctx->r3 = S32(SIGNED(ctx->r7) >> 5);
    // 0x8008A614: j           L_8008A660
    // 0x8008A618: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
        goto L_8008A660;
    // 0x8008A618: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
L_8008A61C:
    // 0x8008A61C: jal         0x80093F60
    // 0x8008A620: nop

    func_80093F60(rdram, ctx);
        goto after_5;
    // 0x8008A620: nop

    after_5:
    // 0x8008A624: lw          $v1, 0x70($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X70);
    // 0x8008A628: lb          $a0, 0xBC($s5)
    ctx->r4 = MEM_B(ctx->r21, 0XBC);
    // 0x8008A62C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8008A630: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8008A634: mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A638: mflo        $v1
    ctx->r3 = lo;
    // 0x8008A63C: lui         $v0, 0x51EB
    ctx->r2 = S32(0X51EB << 16);
    // 0x8008A640: ori         $v0, $v0, 0x851F
    ctx->r2 = ctx->r2 | 0X851F;
    // 0x8008A644: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A648: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x8008A64C: mfhi        $a3
    ctx->r7 = hi;
    // 0x8008A650: sra         $v0, $a3, 5
    ctx->r2 = S32(SIGNED(ctx->r7) >> 5);
    // 0x8008A654: j           L_8008A660
    // 0x8008A658: subu        $v1, $v0, $v1
    ctx->r3 = SUB32(ctx->r2, ctx->r3);
        goto L_8008A660;
    // 0x8008A658: subu        $v1, $v0, $v1
    ctx->r3 = SUB32(ctx->r2, ctx->r3);
L_8008A65C:
    // 0x8008A65C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8008A660:
    // 0x8008A660: lw          $v0, 0x70($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X70);
    // 0x8008A664: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x8008A668: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // 0x8008A66C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008A670: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008A674: sw          $v0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r2;
    // 0x8008A678: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8008A67C: jal         0x800895BC
    // 0x8008A680: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    func_800895BC(rdram, ctx);
        goto after_6;
    // 0x8008A680: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    after_6:
    // 0x8008A684: j           L_8008A690
    // 0x8008A688: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
        goto L_8008A690;
    // 0x8008A688: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_8008A68C:
    // 0x8008A68C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8008A690:
    // 0x8008A690: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8008A694: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x8008A698: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x8008A69C: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x8008A6A0: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8008A6A4: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8008A6A8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8008A6AC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8008A6B0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8008A6B4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8008A6B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8008A6BC: jr          $ra
    // 0x8008A6C0: nop

    return;
    // 0x8008A6C0: nop

;}
RECOMP_FUNC void func_8008A6C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A6C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008A6C8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8008A6CC: lbu         $a0, 0x67($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X67);
    // 0x8008A6D0: jal         0x80092274
    // 0x8008A6D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80092274(rdram, ctx);
        goto after_0;
    // 0x8008A6D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8008A6D8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8008A6DC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8008A6E0: jr          $ra
    // 0x8008A6E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8008A6E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8008A6E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A6E8: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x8008A6EC: ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // 0x8008A6F0: sw          $v0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r2;
    // 0x8008A6F4: jr          $ra
    // 0x8008A6F8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8008A6F8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_8008A6FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A6FC: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8008A700: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008A704: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x8008A708: beq         $v0, $zero, L_8008A71C
    if (ctx->r2 == 0) {
        // 0x8008A70C: addu        $a2, $a0, $zero
        ctx->r6 = ADD32(ctx->r4, 0);
            goto L_8008A71C;
    }
    // 0x8008A70C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8008A710: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
    // 0x8008A714: j           L_8008A728
    // 0x8008A718: ori         $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 | 0X4000;
        goto L_8008A728;
    // 0x8008A718: ori         $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 | 0X4000;
L_8008A71C:
    // 0x8008A71C: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
    // 0x8008A720: addiu       $v1, $zero, -0x4001
    ctx->r3 = ADD32(0, -0X4001);
    // 0x8008A724: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
L_8008A728:
    // 0x8008A728: sw          $v0, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r2;
    // 0x8008A72C: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x8008A730: lhu         $v1, 0x4($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X4);
    // 0x8008A734: srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // 0x8008A738: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8008A73C: beq         $v0, $zero, L_8008A750
    if (ctx->r2 == 0) {
        // 0x8008A740: sw          $v1, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r3;
            goto L_8008A750;
    }
    // 0x8008A740: sw          $v1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r3;
    // 0x8008A744: sll         $v0, $v1, 8
    ctx->r2 = S32(ctx->r3 << 8);
    // 0x8008A748: j           L_8008A7B0
    // 0x8008A74C: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
        goto L_8008A7B0;
    // 0x8008A74C: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_8008A750:
    // 0x8008A750: lbu         $v1, 0x4F($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X4F);
    // 0x8008A754: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008A758: addiu       $a0, $a0, -0x5330
    ctx->r4 = ADD32(ctx->r4, -0X5330);
    // 0x8008A75C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8008A760: beq         $v1, $v0, L_8008A774
    if (ctx->r3 == ctx->r2) {
        // 0x8008A764: addu        $a3, $sp, $zero
        ctx->r7 = ADD32(ctx->r29, 0);
            goto L_8008A774;
    }
    // 0x8008A764: addu        $a3, $sp, $zero
    ctx->r7 = ADD32(ctx->r29, 0);
    // 0x8008A768: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8008A76C: j           L_8008A778
    // 0x8008A770: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
        goto L_8008A778;
    // 0x8008A770: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
L_8008A774:
    // 0x8008A774: addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
L_8008A778:
    // 0x8008A778: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8008A77C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8008A780: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
    // 0x8008A784: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008A788: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008A78C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008A790: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8008A794: divu        $zero, $v0, $a0
    lo = S32(U32(ctx->r2) / U32(ctx->r4)); hi = S32(U32(ctx->r2) % U32(ctx->r4));
    // 0x8008A798: bne         $a0, $zero, L_8008A7A4
    if (ctx->r4 != 0) {
        // 0x8008A79C: nop
    
            goto L_8008A7A4;
    }
    // 0x8008A79C: nop

    // 0x8008A7A0: break       7
    do_break(2148050848);
L_8008A7A4:
    // 0x8008A7A4: mflo        $v0
    ctx->r2 = lo;
    // 0x8008A7A8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8008A7AC: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
L_8008A7B0:
    // 0x8008A7B0: lw          $v1, 0x0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X0);
    // 0x8008A7B4: beql        $v1, $zero, L_8008A80C
    if (ctx->r3 == 0) {
        // 0x8008A7B8: addiu       $v1, $zero, -0x2001
        ctx->r3 = ADD32(0, -0X2001);
            goto L_8008A80C;
    }
    goto skip_0;
    // 0x8008A7B8: addiu       $v1, $zero, -0x2001
    ctx->r3 = ADD32(0, -0X2001);
    skip_0:
    // 0x8008A7BC: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
    // 0x8008A7C0: sw          $v1, 0x78($a2)
    MEM_W(0X78, ctx->r6) = ctx->r3;
    // 0x8008A7C4: ori         $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 | 0X2000;
    // 0x8008A7C8: sw          $v0, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r2;
    // 0x8008A7CC: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8008A7D0: srl         $v0, $v1, 16
    ctx->r2 = S32(U32(ctx->r3) >> 16);
    // 0x8008A7D4: srl         $v1, $v1, 8
    ctx->r3 = S32(U32(ctx->r3) >> 8);
    // 0x8008A7D8: sb          $v0, 0x81($a2)
    MEM_B(0X81, ctx->r6) = ctx->r2;
    // 0x8008A7DC: sll         $v0, $v1, 24
    ctx->r2 = S32(ctx->r3 << 24);
    // 0x8008A7E0: bgez        $v0, L_8008A800
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008A7E4: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_8008A800;
    }
    // 0x8008A7E4: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8008A7E8: lw          $v0, 0x78($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X78);
    // 0x8008A7EC: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x8008A7F0: sb          $v1, 0x80($a2)
    MEM_B(0X80, ctx->r6) = ctx->r3;
    // 0x8008A7F4: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x8008A7F8: j           L_8008A818
    // 0x8008A7FC: sw          $v0, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->r2;
        goto L_8008A818;
    // 0x8008A7FC: sw          $v0, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->r2;
L_8008A800:
    // 0x8008A800: sb          $a0, 0x80($a2)
    MEM_B(0X80, ctx->r6) = ctx->r4;
    // 0x8008A804: j           L_8008A818
    // 0x8008A808: sw          $zero, 0x74($a2)
    MEM_W(0X74, ctx->r6) = 0;
        goto L_8008A818;
    // 0x8008A808: sw          $zero, 0x74($a2)
    MEM_W(0X74, ctx->r6) = 0;
L_8008A80C:
    // 0x8008A80C: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
    // 0x8008A810: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8008A814: sw          $v0, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r2;
L_8008A818:
    // 0x8008A818: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8008A81C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8008A820: jr          $ra
    // 0x8008A824: nop

    return;
    // 0x8008A824: nop

;}
RECOMP_FUNC void func_8008A828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A828: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    // 0x8008A82C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008A830: srl         $v1, $a1, 8
    ctx->r3 = S32(U32(ctx->r5) >> 8);
    // 0x8008A834: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8008A838: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8008A83C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008A840: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008A844: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8008A848: lw          $v0, 0x168($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X168);
    // 0x8008A84C: srl         $a1, $a1, 16
    ctx->r5 = S32(U32(ctx->r5) >> 16);
    // 0x8008A850: sll         $a1, $a1, 8
    ctx->r5 = S32(ctx->r5 << 8);
    // 0x8008A854: beq         $v0, $zero, L_8008A860
    if (ctx->r2 == 0) {
        // 0x8008A858: sw          $a1, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r5;
            goto L_8008A860;
    }
    // 0x8008A858: sw          $a1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r5;
    // 0x8008A85C: sw          $zero, 0x164($a0)
    MEM_W(0X164, ctx->r4) = 0;
L_8008A860:
    // 0x8008A860: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x8008A864: sw          $v0, 0x168($a0)
    MEM_W(0X168, ctx->r4) = ctx->r2;
    // 0x8008A868: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8008A86C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8008A870: jr          $ra
    // 0x8008A874: nop

    return;
    // 0x8008A874: nop

;}
RECOMP_FUNC void func_8008A878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A878: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008A87C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8008A880: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8008A884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008A888: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8008A88C: ori         $v0, $v0, 0x100
    ctx->r2 = ctx->r2 | 0X100;
    // 0x8008A890: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x8008A894: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8008A898: srl         $a0, $a0, 8
    ctx->r4 = S32(U32(ctx->r4) >> 8);
    // 0x8008A89C: jal         0x80093F18
    // 0x8008A8A0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    func_80093F18(rdram, ctx);
        goto after_0;
    // 0x8008A8A0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x8008A8A4: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x8008A8A8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8008A8AC: sw          $v1, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r3;
    // 0x8008A8B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008A8B4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8008A8B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008A8BC: jr          $ra
    // 0x8008A8C0: nop

    return;
    // 0x8008A8C0: nop

;}
RECOMP_FUNC void func_8008A8C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A8C4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8008A8C8: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x8008A8CC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8008A8D0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8008A8D4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8008A8D8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008A8DC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008A8E0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008A8E4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008A8E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008A8EC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8008A8F0: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x8008A8F4: srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // 0x8008A8F8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008A8FC: sh          $v0, -0x53A4($at)
    MEM_H(-0X53A4, ctx->r1) = ctx->r2;
    // 0x8008A900: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008A904: lw          $v0, -0x50F4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X50F4);
    // 0x8008A908: lui         $s7, 0x8015
    ctx->r23 = S32(0X8015 << 16);
    // 0x8008A90C: addiu       $s7, $s7, -0x7398
    ctx->r23 = ADD32(ctx->r23, -0X7398);
    // 0x8008A910: beq         $v0, $zero, L_8008A968
    if (ctx->r2 == 0) {
        // 0x8008A914: addiu       $s6, $zero, 0x8
        ctx->r22 = ADD32(0, 0X8);
            goto L_8008A968;
    }
    // 0x8008A914: addiu       $s6, $zero, 0x8
    ctx->r22 = ADD32(0, 0X8);
    // 0x8008A918: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8008A91C: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8008A920: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_8008A924:
    // 0x8008A924: sra         $s2, $v0, 1
    ctx->r18 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8008A928: addiu       $s1, $s2, -0x1
    ctx->r17 = ADD32(ctx->r18, -0X1);
    // 0x8008A92C: mult        $s6, $s1
    result = S64(S32(ctx->r22)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A930: mflo        $v0
    ctx->r2 = lo;
    // 0x8008A934: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008A938: addiu       $a0, $a0, -0x53A8
    ctx->r4 = ADD32(ctx->r4, -0X53A8);
    // 0x8008A93C: addu        $s0, $s7, $v0
    ctx->r16 = ADD32(ctx->r23, ctx->r2);
    // 0x8008A940: jal         0x80085F54
    // 0x8008A944: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80085F54(rdram, ctx);
        goto after_0;
    // 0x8008A944: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8008A948: beq         $v0, $zero, L_8008A96C
    if (ctx->r2 == 0) {
        // 0x8008A94C: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_8008A96C;
    }
    // 0x8008A94C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8008A950: bgezl       $v0, L_8008A95C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008A954: addiu       $s4, $s2, 0x1
        ctx->r20 = ADD32(ctx->r18, 0X1);
            goto L_8008A95C;
    }
    goto skip_0;
    // 0x8008A954: addiu       $s4, $s2, 0x1
    ctx->r20 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x8008A958: addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
L_8008A95C:
    // 0x8008A95C: slt         $v0, $s3, $s4
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8008A960: beq         $v0, $zero, L_8008A924
    if (ctx->r2 == 0) {
        // 0x8008A964: addu        $v0, $s4, $s3
        ctx->r2 = ADD32(ctx->r20, ctx->r19);
            goto L_8008A924;
    }
    // 0x8008A964: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_8008A968:
    // 0x8008A968: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8008A96C:
    // 0x8008A96C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008A970: sw          $a1, -0x53A0($at)
    MEM_W(-0X53A0, ctx->r1) = ctx->r5;
    // 0x8008A974: beq         $a1, $zero, L_8008A980
    if (ctx->r5 == 0) {
        // 0x8008A978: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8008A980;
    }
    // 0x8008A978: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8008A97C: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
L_8008A980:
    // 0x8008A980: beq         $a0, $zero, L_8008A9F4
    if (ctx->r4 == 0) {
        // 0x8008A984: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8008A9F4;
    }
    // 0x8008A984: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8008A988: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8008A98C: srl         $v1, $v0, 8
    ctx->r3 = S32(U32(ctx->r2) >> 8);
    // 0x8008A990: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8008A994: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8008A998: sh          $v1, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r3;
    // 0x8008A99C: lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2);
    // 0x8008A9A0: srl         $v1, $v0, 8
    ctx->r3 = S32(U32(ctx->r2) >> 8);
    // 0x8008A9A4: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8008A9A8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8008A9AC: sh          $v1, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r3;
    // 0x8008A9B0: lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X4);
    // 0x8008A9B4: srl         $v1, $v0, 8
    ctx->r3 = S32(U32(ctx->r2) >> 8);
    // 0x8008A9B8: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8008A9BC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8008A9C0: sh          $v1, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r3;
    // 0x8008A9C4: lhu         $v0, 0x6($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X6);
    // 0x8008A9C8: srl         $v1, $v0, 8
    ctx->r3 = S32(U32(ctx->r2) >> 8);
    // 0x8008A9CC: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8008A9D0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8008A9D4: sh          $v1, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r3;
    // 0x8008A9D8: lbu         $a0, 0x67($s5)
    ctx->r4 = MEM_BU(ctx->r21, 0X67);
    // 0x8008A9DC: jal         0x800922C4
    // 0x8008A9E0: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_800922C4(rdram, ctx);
        goto after_1;
    // 0x8008A9E0: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x8008A9E4: lw          $v0, 0x24($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X24);
    // 0x8008A9E8: ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
    // 0x8008A9EC: sw          $v0, 0x24($s5)
    MEM_W(0X24, ctx->r21) = ctx->r2;
    // 0x8008A9F0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8008A9F4:
    // 0x8008A9F4: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x8008A9F8: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8008A9FC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8008AA00: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8008AA04: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008AA08: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008AA0C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008AA10: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008AA14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008AA18: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8008AA1C: jr          $ra
    // 0x8008AA20: nop

    return;
    // 0x8008AA20: nop

;}
RECOMP_FUNC void func_8008AA24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AA24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008AA28: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8008AA2C: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8008AA30: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8008AA34: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x8008AA38: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8008AA3C: sll         $s0, $a2, 2
    ctx->r16 = S32(ctx->r6 << 2);
    // 0x8008AA40: addu        $s0, $s0, $s2
    ctx->r16 = ADD32(ctx->r16, ctx->r18);
    // 0x8008AA44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008AA48: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x8008AA4C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8008AA50: addu        $a2, $s2, $a2
    ctx->r6 = ADD32(ctx->r18, ctx->r6);
    // 0x8008AA54: srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // 0x8008AA58: sb          $v0, 0x4C($a2)
    MEM_B(0X4C, ctx->r6) = ctx->r2;
    // 0x8008AA5C: sb          $v0, 0xAC($a2)
    MEM_B(0XAC, ctx->r6) = ctx->r2;
    // 0x8008AA60: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    // 0x8008AA64: jal         0x80093F18
    // 0x8008AA68: nop

    func_80093F18(rdram, ctx);
        goto after_0;
    // 0x8008AA68: nop

    after_0:
    // 0x8008AA6C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8008AA70: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008AA74: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8008AA78: sw          $v0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r2;
    // 0x8008AA7C: jal         0x800895BC
    // 0x8008AA80: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    func_800895BC(rdram, ctx);
        goto after_1;
    // 0x8008AA80: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    after_1:
    // 0x8008AA84: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8008AA88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008AA8C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8008AA90: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8008AA94: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8008AA98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008AA9C: jr          $ra
    // 0x8008AAA0: nop

    return;
    // 0x8008AAA0: nop

;}
RECOMP_FUNC void func_8008AAA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AAA4: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8008AAA8: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
    // 0x8008AAAC: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // 0x8008AAB0: sw          $v0, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r2;
    // 0x8008AAB4: lhu         $a3, 0x0($a1)
    ctx->r7 = MEM_HU(ctx->r5, 0X0);
    // 0x8008AAB8: sll         $v0, $a3, 8
    ctx->r2 = S32(ctx->r7 << 8);
    // 0x8008AABC: sw          $v0, 0xA4($a2)
    MEM_W(0XA4, ctx->r6) = ctx->r2;
    // 0x8008AAC0: lbu         $v0, 0x2($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X2);
    // 0x8008AAC4: lb          $v1, 0x7($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X7);
    // 0x8008AAC8: lw          $a0, 0xA4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XA4);
    // 0x8008AACC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008AAD0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8008AAD4: sw          $v0, 0x38($a2)
    MEM_W(0X38, ctx->r6) = ctx->r2;
    // 0x8008AAD8: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8008AADC: beq         $a0, $zero, L_8008AB00
    if (ctx->r4 == 0) {
        // 0x8008AAE0: sw          $v0, 0xA8($a2)
        MEM_W(0XA8, ctx->r6) = ctx->r2;
            goto L_8008AB00;
    }
    // 0x8008AAE0: sw          $v0, 0xA8($a2)
    MEM_W(0XA8, ctx->r6) = ctx->r2;
    // 0x8008AAE4: divu        $zero, $v1, $a3
    lo = S32(U32(ctx->r3) / U32(ctx->r7)); hi = S32(U32(ctx->r3) % U32(ctx->r7));
    // 0x8008AAE8: bne         $a3, $zero, L_8008AAF4
    if (ctx->r7 != 0) {
        // 0x8008AAEC: nop
    
            goto L_8008AAF4;
    }
    // 0x8008AAEC: nop

    // 0x8008AAF0: break       7
    do_break(2148051696);
L_8008AAF4:
    // 0x8008AAF4: mflo        $v0
    ctx->r2 = lo;
    // 0x8008AAF8: j           L_8008AB04
    // 0x8008AAFC: sw          $v0, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->r2;
        goto L_8008AB04;
    // 0x8008AAFC: sw          $v0, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->r2;
L_8008AB00:
    // 0x8008AB00: sw          $v1, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->r3;
L_8008AB04:
    // 0x8008AB04: jr          $ra
    // 0x8008AB08: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8008AB08: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_8008AB0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AB0C: lhu         $v0, 0x54($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X54);
    // 0x8008AB10: lbu         $v1, 0x1($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X1);
    // 0x8008AB14: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    // 0x8008AB18: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008AB1C: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x8008AB20: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x8008AB24: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8008AB28: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008AB2C: mflo        $v0
    ctx->r2 = lo;
    // 0x8008AB30: bgez        $v0, L_8008AB3C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008AB34: addiu       $sp, $sp, -0x8
        ctx->r29 = ADD32(ctx->r29, -0X8);
            goto L_8008AB3C;
    }
    // 0x8008AB34: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008AB38: addiu       $v0, $v0, 0x7F
    ctx->r2 = ADD32(ctx->r2, 0X7F);
L_8008AB3C:
    // 0x8008AB3C: sra         $v1, $v0, 7
    ctx->r3 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8008AB40: srl         $v0, $a1, 24
    ctx->r2 = S32(U32(ctx->r5) >> 24);
    // 0x8008AB44: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008AB48: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8008AB4C: bgez        $v1, L_8008AB5C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8008AB50: lui         $v0, 0x7F
        ctx->r2 = S32(0X7F << 16);
            goto L_8008AB5C;
    }
    // 0x8008AB50: lui         $v0, 0x7F
    ctx->r2 = S32(0X7F << 16);
    // 0x8008AB54: j           L_8008AB68
    // 0x8008AB58: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_8008AB68;
    // 0x8008AB58: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8008AB5C:
    // 0x8008AB5C: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8008AB60: bnel        $v0, $zero, L_8008AB68
    if (ctx->r2 != 0) {
        // 0x8008AB64: lui         $v1, 0x7F
        ctx->r3 = S32(0X7F << 16);
            goto L_8008AB68;
    }
    goto skip_0;
    // 0x8008AB64: lui         $v1, 0x7F
    ctx->r3 = S32(0X7F << 16);
    skip_0:
L_8008AB68:
    // 0x8008AB68: sw          $v1, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r3;
    // 0x8008AB6C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8008AB70: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8008AB74: jr          $ra
    // 0x8008AB78: nop

    return;
    // 0x8008AB78: nop

;}
RECOMP_FUNC void func_8008AB7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AB7C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008AB80: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8008AB84: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x8008AB88: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8008AB8C: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x8008AB90: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x8008AB94: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x8008AB98: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8008AB9C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8008ABA0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8008ABA4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8008ABA8: beq         $v0, $zero, L_8008AC80
    if (ctx->r2 == 0) {
        // 0x8008ABAC: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_8008AC80;
    }
    // 0x8008ABAC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8008ABB0: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8008ABB4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008ABB8: sh          $v0, -0x53A4($at)
    MEM_H(-0X53A4, ctx->r1) = ctx->r2;
    // 0x8008ABBC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008ABC0: lw          $v0, -0x50F4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X50F4);
    // 0x8008ABC4: lui         $s7, 0x8015
    ctx->r23 = S32(0X8015 << 16);
    // 0x8008ABC8: addiu       $s7, $s7, -0x7398
    ctx->r23 = ADD32(ctx->r23, -0X7398);
    // 0x8008ABCC: beq         $v0, $zero, L_8008AC24
    if (ctx->r2 == 0) {
        // 0x8008ABD0: addiu       $s6, $zero, 0x8
        ctx->r22 = ADD32(0, 0X8);
            goto L_8008AC24;
    }
    // 0x8008ABD0: addiu       $s6, $zero, 0x8
    ctx->r22 = ADD32(0, 0X8);
    // 0x8008ABD4: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8008ABD8: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8008ABDC: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_8008ABE0:
    // 0x8008ABE0: sra         $s2, $v0, 1
    ctx->r18 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8008ABE4: addiu       $s1, $s2, -0x1
    ctx->r17 = ADD32(ctx->r18, -0X1);
    // 0x8008ABE8: mult        $s6, $s1
    result = S64(S32(ctx->r22)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008ABEC: mflo        $v0
    ctx->r2 = lo;
    // 0x8008ABF0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008ABF4: addiu       $a0, $a0, -0x53A8
    ctx->r4 = ADD32(ctx->r4, -0X53A8);
    // 0x8008ABF8: addu        $s0, $s7, $v0
    ctx->r16 = ADD32(ctx->r23, ctx->r2);
    // 0x8008ABFC: jal         0x80085F54
    // 0x8008AC00: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80085F54(rdram, ctx);
        goto after_0;
    // 0x8008AC00: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8008AC04: beql        $v0, $zero, L_8008AC28
    if (ctx->r2 == 0) {
        // 0x8008AC08: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_8008AC28;
    }
    goto skip_0;
    // 0x8008AC08: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    skip_0:
    // 0x8008AC0C: bgezl       $v0, L_8008AC18
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008AC10: addiu       $s4, $s2, 0x1
        ctx->r20 = ADD32(ctx->r18, 0X1);
            goto L_8008AC18;
    }
    goto skip_1;
    // 0x8008AC10: addiu       $s4, $s2, 0x1
    ctx->r20 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x8008AC14: addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
L_8008AC18:
    // 0x8008AC18: slt         $v0, $s3, $s4
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8008AC1C: beq         $v0, $zero, L_8008ABE0
    if (ctx->r2 == 0) {
        // 0x8008AC20: addu        $v0, $s4, $s3
        ctx->r2 = ADD32(ctx->r20, ctx->r19);
            goto L_8008ABE0;
    }
    // 0x8008AC20: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_8008AC24:
    // 0x8008AC24: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8008AC28:
    // 0x8008AC28: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008AC2C: sw          $a1, -0x53A0($at)
    MEM_W(-0X53A0, ctx->r1) = ctx->r5;
    // 0x8008AC30: beq         $a1, $zero, L_8008AC3C
    if (ctx->r5 == 0) {
        // 0x8008AC34: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_8008AC3C;
    }
    // 0x8008AC34: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8008AC38: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
L_8008AC3C:
    // 0x8008AC3C: beq         $a2, $zero, L_8008AC80
    if (ctx->r6 == 0) {
        // 0x8008AC40: srl         $v1, $s5, 16
        ctx->r3 = S32(U32(ctx->r21) >> 16);
            goto L_8008AC80;
    }
    // 0x8008AC40: srl         $v1, $s5, 16
    ctx->r3 = S32(U32(ctx->r21) >> 16);
    // 0x8008AC44: sltiu       $v0, $v1, 0x7F
    ctx->r2 = ctx->r3 < 0X7F ? 1 : 0;
    // 0x8008AC48: beq         $v0, $zero, L_8008AC74
    if (ctx->r2 == 0) {
        // 0x8008AC4C: andi        $a0, $s5, 0xFFFF
        ctx->r4 = ctx->r21 & 0XFFFF;
            goto L_8008AC74;
    }
    // 0x8008AC4C: andi        $a0, $s5, 0xFFFF
    ctx->r4 = ctx->r21 & 0XFFFF;
    // 0x8008AC50: addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
    // 0x8008AC54: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x8008AC58: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8008AC5C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8008AC60: mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008AC64: mflo        $v1
    ctx->r3 = lo;
    // 0x8008AC68: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008AC6C: j           L_8008AC80
    // 0x8008AC70: addu        $s5, $v0, $v1
    ctx->r21 = ADD32(ctx->r2, ctx->r3);
        goto L_8008AC80;
    // 0x8008AC70: addu        $s5, $v0, $v1
    ctx->r21 = ADD32(ctx->r2, ctx->r3);
L_8008AC74:
    // 0x8008AC74: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
    // 0x8008AC78: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8008AC7C: sll         $s5, $v0, 16
    ctx->r21 = S32(ctx->r2 << 16);
L_8008AC80:
    // 0x8008AC80: addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
    // 0x8008AC84: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x8008AC88: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x8008AC8C: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x8008AC90: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8008AC94: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8008AC98: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8008AC9C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8008ACA0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8008ACA4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8008ACA8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8008ACAC: jr          $ra
    // 0x8008ACB0: nop

    return;
    // 0x8008ACB0: nop

;}
