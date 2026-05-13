#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8000794C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000794C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80007950: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80007954: addiu       $v1, $v1, -0x575C
    ctx->r3 = ADD32(ctx->r3, -0X575C);
L_80007958:
    // 0x80007958: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000795C: bnel        $v0, $a0, L_8000796C
    if (ctx->r2 != ctx->r4) {
        // 0x80007960: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8000796C;
    }
    goto skip_0;
    // 0x80007960: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_0:
    // 0x80007964: j           L_80007978
    // 0x80007968: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_80007978;
    // 0x80007968: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8000796C:
    // 0x8000796C: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80007970: bne         $v0, $zero, L_80007958
    if (ctx->r2 != 0) {
        // 0x80007974: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80007958;
    }
    // 0x80007974: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80007978:
    // 0x80007978: jr          $ra
    // 0x8000797C: nop

    return;
    // 0x8000797C: nop

;}
RECOMP_FUNC void func_80007980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007980: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80007984: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80007988: addiu       $v0, $v0, -0x5750
    ctx->r2 = ADD32(ctx->r2, -0X5750);
L_8000798C:
    // 0x8000798C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80007990: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80007994: bgez        $v1, L_8000798C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80007998: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_8000798C;
    }
    // 0x80007998: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x8000799C: jr          $ra
    // 0x800079A0: nop

    return;
    // 0x800079A0: nop

;}
RECOMP_FUNC void func_800079A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800079A4: beq         $a0, $zero, L_800079E8
    if (ctx->r4 == 0) {
        // 0x800079A8: nop
    
            goto L_800079E8;
    }
    // 0x800079A8: nop

    // 0x800079AC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800079B0: beq         $v0, $zero, L_800079C8
    if (ctx->r2 == 0) {
        // 0x800079B4: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_800079C8;
    }
    // 0x800079B4: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_800079B8:
    // 0x800079B8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800079BC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800079C0: bne         $v0, $zero, L_800079B8
    if (ctx->r2 != 0) {
        // 0x800079C4: nop
    
            goto L_800079B8;
    }
    // 0x800079C4: nop

L_800079C8:
    // 0x800079C8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800079CC: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x800079D0: beq         $v0, $zero, L_800079DC
    if (ctx->r2 == 0) {
        // 0x800079D4: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800079DC;
    }
    // 0x800079D4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800079D8: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_800079DC:
    // 0x800079DC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800079E0: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x800079E4: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_800079E8:
    // 0x800079E8: jr          $ra
    // 0x800079EC: nop

    return;
    // 0x800079EC: nop

;}
RECOMP_FUNC void heapWalker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    {
    // Reset cycle-detection state at function entry. Needs to be a global so
    // the loop-top hook below can read it across iterations.
    extern unsigned g_heapwalker_initial;
    extern unsigned g_heapwalker_iter;
    g_heapwalker_initial = 0;
    g_heapwalker_iter = 0;
}
    // 0x800079F0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800079F4: lbu         $v0, -0x5767($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5767);
    // 0x800079F8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800079FC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80007A00: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80007A04: lw          $a0, 0x63C8($at)
    ctx->r4 = MEM_W(ctx->r1, 0X63C8);
    // 0x80007A08: beq         $a0, $zero, L_80007A4C
    if (ctx->r4 == 0) {
        // 0x80007A0C: addiu       $sp, $sp, -0x28
        ctx->r29 = ADD32(ctx->r29, -0X28);
            goto L_80007A4C;
    }
    // 0x80007A0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80007A10: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80007A14: beq         $v0, $zero, L_80007A2C
    if (ctx->r2 == 0) {
        // 0x80007A18: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80007A2C;
    }
    // 0x80007A18: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_80007A1C:
    // 0x80007A1C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    { if (((uint64_t)ctx->r3 & 0xFFFFFFFFE0000000ULL) != 0xFFFFFFFF80000000ULL) { ctx->r2 = 0; goto L_80007A2C; } }
    // 0x80007A20: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80007A24: bne         $v0, $zero, L_80007A1C
    if (ctx->r2 != 0) {
        // 0x80007A28: nop
    
            goto L_80007A1C;
    }
    // 0x80007A28: nop

L_80007A2C:
    // 0x80007A2C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80007A30: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80007A34: beq         $v0, $zero, L_80007A40
    if (ctx->r2 == 0) {
        // 0x80007A38: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80007A40;
    }
    // 0x80007A38: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80007A3C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_80007A40:
    { if (((uint64_t)ctx->r3 & 0xFFFFFFFFE0000000ULL) != 0xFFFFFFFF80000000ULL) { ctx->r2 = 0; goto L_80007A4C; } }
    // 0x80007A40: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80007A44: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x80007A48: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_80007A4C:
    // 0x80007A4C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80007A50: lbu         $v0, -0x5767($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5767);
    // 0x80007A54: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80007A58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80007A5C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80007A60: lw          $a0, -0x5B50($at)
    ctx->r4 = MEM_W(ctx->r1, -0X5B50);
    // 0x80007A64: beq         $a0, $zero, L_80007AA8
    if (ctx->r4 == 0) {
        // 0x80007A68: nop
    
            goto L_80007AA8;
    }
    // 0x80007A68: nop

    // 0x80007A6C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80007A70: beq         $v0, $zero, L_80007A88
    if (ctx->r2 == 0) {
        // 0x80007A74: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80007A88;
    }
    // 0x80007A74: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_80007A78:
    {
    extern unsigned g_heapwalker_initial;
    extern unsigned g_heapwalker_iter;
    if (g_heapwalker_iter == 0) {
        g_heapwalker_initial = (unsigned)(uint64_t)ctx->r3;
        g_heapwalker_iter = 1;
    } else {
        g_heapwalker_iter++;
    }
    // Perform the lw (replaces the NOPed instruction).
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // Cycle check: after the second iter, if r3 returns to start, the list
    // is cyclic — bail to function exit.
    if (g_heapwalker_iter > 2 && (unsigned)(uint64_t)ctx->r3 == g_heapwalker_initial) {
        goto L_80007A88;
    }
    // Safety upper bound (cycles not caught by start-revisit): bail at 1M
    // iters. Normal free-lists are much smaller than this.
    if (g_heapwalker_iter > 1000000u) {
        goto L_80007A88;
    }
}
    // 0x80007A78: nop

    // 0x80007A7C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80007A80: bne         $v0, $zero, L_80007A78
    if (ctx->r2 != 0) {
        // 0x80007A84: nop
    
            goto L_80007A78;
    }
    // 0x80007A84: nop

L_80007A88:
    // 0x80007A88: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80007A8C: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80007A90: beq         $v0, $zero, L_80007A9C
    if (ctx->r2 == 0) {
        // 0x80007A94: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80007A9C;
    }
    // 0x80007A94: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80007A98: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_80007A9C:
    // 0x80007A9C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80007AA0: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x80007AA4: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_80007AA8:
    // 0x80007AA8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80007AAC: lbu         $v0, -0x5767($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5767);
    // 0x80007AB0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80007AB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80007AB8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80007ABC: lw          $a0, -0x5BA8($at)
    ctx->r4 = MEM_W(ctx->r1, -0X5BA8);
    // 0x80007AC0: beq         $a0, $zero, L_80007B04
    if (ctx->r4 == 0) {
        // 0x80007AC4: nop
    
            goto L_80007B04;
    }
    // 0x80007AC4: nop

    // 0x80007AC8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80007ACC: beq         $v0, $zero, L_80007AE4
    if (ctx->r2 == 0) {
        // 0x80007AD0: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80007AE4;
    }
    // 0x80007AD0: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_80007AD4:
    // 0x80007AD4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80007AD8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80007ADC: bne         $v0, $zero, L_80007AD4
    if (ctx->r2 != 0) {
        // 0x80007AE0: nop
    
            goto L_80007AD4;
    }
    // 0x80007AE0: nop

L_80007AE4:
    // 0x80007AE4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80007AE8: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80007AEC: beq         $v0, $zero, L_80007AF8
    if (ctx->r2 == 0) {
        // 0x80007AF0: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80007AF8;
    }
    // 0x80007AF0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80007AF4: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_80007AF8:
    // 0x80007AF8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80007AFC: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x80007B00: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_80007B04:
    // 0x80007B04: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80007B08: lbu         $v0, -0x5767($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5767);
    // 0x80007B0C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80007B10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80007B14: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80007B18: lw          $a0, -0x5B60($at)
    ctx->r4 = MEM_W(ctx->r1, -0X5B60);
    // 0x80007B1C: beq         $a0, $zero, L_80007B60
    if (ctx->r4 == 0) {
        // 0x80007B20: nop
    
            goto L_80007B60;
    }
    // 0x80007B20: nop

    // 0x80007B24: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80007B28: beq         $v0, $zero, L_80007B40
    if (ctx->r2 == 0) {
        // 0x80007B2C: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80007B40;
    }
    // 0x80007B2C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_80007B30:
    // 0x80007B30: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80007B34: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80007B38: bne         $v0, $zero, L_80007B30
    if (ctx->r2 != 0) {
        // 0x80007B3C: nop
    
            goto L_80007B30;
    }
    // 0x80007B3C: nop

L_80007B40:
    // 0x80007B40: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80007B44: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80007B48: beq         $v0, $zero, L_80007B54
    if (ctx->r2 == 0) {
        // 0x80007B4C: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80007B54;
    }
    // 0x80007B4C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80007B50: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_80007B54:
    // 0x80007B54: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80007B58: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x80007B5C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_80007B60:
    // 0x80007B60: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80007B64: lbu         $v0, -0x5767($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5767);
    // 0x80007B68: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80007B6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80007B70: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80007B74: lw          $a0, -0x5B98($at)
    ctx->r4 = MEM_W(ctx->r1, -0X5B98);
    // 0x80007B78: beq         $a0, $zero, L_80007BBC
    if (ctx->r4 == 0) {
        // 0x80007B7C: nop
    
            goto L_80007BBC;
    }
    // 0x80007B7C: nop

    // 0x80007B80: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80007B84: beq         $v0, $zero, L_80007B9C
    if (ctx->r2 == 0) {
        // 0x80007B88: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80007B9C;
    }
    // 0x80007B88: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_80007B8C:
    // 0x80007B8C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80007B90: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80007B94: bne         $v0, $zero, L_80007B8C
    if (ctx->r2 != 0) {
        // 0x80007B98: nop
    
            goto L_80007B8C;
    }
    // 0x80007B98: nop

L_80007B9C:
    // 0x80007B9C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80007BA0: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80007BA4: beq         $v0, $zero, L_80007BB0
    if (ctx->r2 == 0) {
        // 0x80007BA8: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80007BB0;
    }
    // 0x80007BA8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80007BAC: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_80007BB0:
    // 0x80007BB0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80007BB4: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x80007BB8: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_80007BBC:
    // 0x80007BBC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80007BC0: addiu       $v1, $v1, -0x5767
    ctx->r3 = ADD32(ctx->r3, -0X5767);
    // 0x80007BC4: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80007BC8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80007BCC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80007BD0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80007BD4: sw          $zero, 0x63C8($at)
    MEM_W(0X63C8, ctx->r1) = 0;
    // 0x80007BD8: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80007BDC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80007BE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80007BE4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80007BE8: sw          $zero, -0x5B50($at)
    MEM_W(-0X5B50, ctx->r1) = 0;
    // 0x80007BEC: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80007BF0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80007BF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80007BF8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80007BFC: sw          $zero, -0x5BA8($at)
    MEM_W(-0X5BA8, ctx->r1) = 0;
    // 0x80007C00: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80007C04: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80007C08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80007C0C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80007C10: sw          $zero, -0x5B60($at)
    MEM_W(-0X5B60, ctx->r1) = 0;
    // 0x80007C14: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80007C18: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80007C1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80007C20: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80007C24: sw          $zero, -0x5B98($at)
    MEM_W(-0X5B98, ctx->r1) = 0;
    // 0x80007C28: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80007C2C: lbu         $v1, -0x5767($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X5767);
    // 0x80007C30: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80007C34: addiu       $v0, $v0, 0x63C8
    ctx->r2 = ADD32(ctx->r2, 0X63C8);
    // 0x80007C38: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80007C3C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80007C40: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80007C44: sw          $v0, 0x63FC($at)
    MEM_W(0X63FC, ctx->r1) = ctx->r2;
    // 0x80007C48: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80007C4C: addiu       $v0, $v0, -0x5820
    ctx->r2 = ADD32(ctx->r2, -0X5820);
    // 0x80007C50: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80007C54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80007C58: sw          $v0, -0x5824($at)
    MEM_W(-0X5824, ctx->r1) = ctx->r2;
    // 0x80007C5C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80007C60: addiu       $v0, $v0, -0x5B50
    ctx->r2 = ADD32(ctx->r2, -0X5B50);
    // 0x80007C64: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80007C68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80007C6C: sw          $v0, -0x5B3C($at)
    MEM_W(-0X5B3C, ctx->r1) = ctx->r2;
    // 0x80007C70: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80007C74: addiu       $v0, $v0, -0x5BA8
    ctx->r2 = ADD32(ctx->r2, -0X5BA8);
    // 0x80007C78: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80007C7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80007C80: sw          $v0, -0x5B54($at)
    MEM_W(-0X5B54, ctx->r1) = ctx->r2;
    // 0x80007C84: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80007C88: addiu       $v0, $v0, -0x5B60
    ctx->r2 = ADD32(ctx->r2, -0X5B60);
    // 0x80007C8C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80007C90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80007C94: sw          $v0, -0x5B44($at)
    MEM_W(-0X5B44, ctx->r1) = ctx->r2;
    // 0x80007C98: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80007C9C: addiu       $v0, $v0, -0x5B98
    ctx->r2 = ADD32(ctx->r2, -0X5B98);
    // 0x80007CA0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80007CA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80007CA8: sw          $v1, -0x5B48($at)
    MEM_W(-0X5B48, ctx->r1) = ctx->r3;
    // 0x80007CAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80007CB0: jr          $ra
    // 0x80007CB4: nop

    return;
    // 0x80007CB4: nop

;}
RECOMP_FUNC void func_80007CB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007CB8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80007CBC: lw          $v1, 0x63B0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63B0);
    // 0x80007CC0: beq         $v1, $zero, L_80007CD4
    if (ctx->r3 == 0) {
        // 0x80007CC4: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80007CD4;
    }
    // 0x80007CC4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80007CC8:
    // 0x80007CC8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80007CCC: bne         $v1, $zero, L_80007CC8
    if (ctx->r3 != 0) {
        // 0x80007CD0: addiu       $v0, $v0, 0x108
        ctx->r2 = ADD32(ctx->r2, 0X108);
            goto L_80007CC8;
    }
    // 0x80007CD0: addiu       $v0, $v0, 0x108
    ctx->r2 = ADD32(ctx->r2, 0X108);
L_80007CD4:
    // 0x80007CD4: jr          $ra
    // 0x80007CD8: nop

    return;
    // 0x80007CD8: nop

;}
RECOMP_FUNC void func_80007CDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007CDC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80007CE0: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x80007CE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007CE8: bne         $a0, $zero, L_80007D48
    if (ctx->r4 != 0) {
        // 0x80007CEC: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80007D48;
    }
    // 0x80007CEC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80007CF0: jal         0x8002221C
    // 0x80007CF4: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_0;
    // 0x80007CF4: nop

    after_0:
    // 0x80007CF8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80007CFC: beq         $a0, $zero, L_80007D40
    if (ctx->r4 == 0) {
        // 0x80007D00: nop
    
            goto L_80007D40;
    }
    // 0x80007D00: nop

    // 0x80007D04: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80007D08: beq         $v0, $zero, L_80007D20
    if (ctx->r2 == 0) {
        // 0x80007D0C: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80007D20;
    }
    // 0x80007D0C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_80007D10:
    // 0x80007D10: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80007D14: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80007D18: bne         $v0, $zero, L_80007D10
    if (ctx->r2 != 0) {
        // 0x80007D1C: nop
    
            goto L_80007D10;
    }
    // 0x80007D1C: nop

L_80007D20:
    // 0x80007D20: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80007D24: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80007D28: beq         $v0, $zero, L_80007D34
    if (ctx->r2 == 0) {
        // 0x80007D2C: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80007D34;
    }
    // 0x80007D2C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80007D30: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_80007D34:
    // 0x80007D34: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80007D38: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x80007D3C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_80007D40:
    // 0x80007D40: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80007D44: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_80007D48:
    // 0x80007D48: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80007D4C: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80007D50: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80007D54: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80007D58: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x80007D5C: bnel        $v0, $zero, L_80007D64
    if (ctx->r2 != 0) {
        // 0x80007D60: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_80007D64;
    }
    goto skip_0;
    // 0x80007D60: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_0:
L_80007D64:
    // 0x80007D64: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80007D68: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x80007D6C: jr          $ra
    // 0x80007D70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80007D70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void allocateDisplayListBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007D74: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80007D78: lw          $v1, 0x63B0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63B0);
    // 0x80007D7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007D80: bne         $v1, $zero, L_80007DE0
    if (ctx->r3 != 0) {
        // 0x80007D84: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80007DE0;
    }
    // 0x80007D84: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80007D88: jal         0x8002221C
    // 0x80007D8C: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_0;
    // 0x80007D8C: nop

    after_0:
    // 0x80007D90: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80007D94: beq         $v1, $zero, L_80007DD8
    if (ctx->r3 == 0) {
        // 0x80007D98: nop
    
            goto L_80007DD8;
    }
    // 0x80007D98: nop

    // 0x80007D9C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80007DA0: beq         $v0, $zero, L_80007DB8
    if (ctx->r2 == 0) {
        // 0x80007DA4: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_80007DB8;
    }
    // 0x80007DA4: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
L_80007DA8:
    // 0x80007DA8: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80007DAC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80007DB0: bne         $v0, $zero, L_80007DA8
    if (ctx->r2 != 0) {
        // 0x80007DB4: nop
    
            goto L_80007DA8;
    }
    // 0x80007DB4: nop

L_80007DB8:
    // 0x80007DB8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80007DBC: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80007DC0: beq         $v0, $zero, L_80007DCC
    if (ctx->r2 == 0) {
        // 0x80007DC4: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_80007DCC;
    }
    // 0x80007DC4: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80007DC8: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
L_80007DCC:
    // 0x80007DCC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80007DD0: sw          $v1, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r3;
    // 0x80007DD4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_80007DD8:
    // 0x80007DD8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80007DDC: lw          $v1, 0x63B0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63B0);
L_80007DE0:
    // 0x80007DE0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80007DE4: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80007DE8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80007DEC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80007DF0: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x80007DF4: bnel        $v0, $zero, L_80007DFC
    if (ctx->r2 != 0) {
        // 0x80007DF8: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_80007DFC;
    }
    goto skip_0;
    // 0x80007DF8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_0:
L_80007DFC:
    // 0x80007DFC: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80007E00: lw          $a1, 0x63FC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X63FC);
    // 0x80007E04: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80007E08: bne         $v0, $zero, L_80007E18
    if (ctx->r2 != 0) {
        // 0x80007E0C: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_80007E18;
    }
    // 0x80007E0C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80007E10: j           L_80007E30
    // 0x80007E14: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
        goto L_80007E30;
    // 0x80007E14: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
L_80007E18:
    // 0x80007E18: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80007E1C: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x80007E20: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80007E24: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80007E28: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80007E2C: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_80007E30:
    // 0x80007E30: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80007E34: lw          $v1, -0x5824($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5824);
    // 0x80007E38: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80007E3C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80007E40: addiu       $v1, $a0, 0x100
    ctx->r3 = ADD32(ctx->r4, 0X100);
    // 0x80007E44: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80007E48: sw          $v1, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r3;
    // 0x80007E4C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80007E50: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80007E54: jr          $ra
    // 0x80007E58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80007E58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80007E5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007E5C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80007E60: lw          $a1, 0x63B0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X63B0);
    // 0x80007E64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007E68: bne         $a1, $zero, L_80007EC8
    if (ctx->r5 != 0) {
        // 0x80007E6C: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80007EC8;
    }
    // 0x80007E6C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80007E70: jal         0x8002221C
    // 0x80007E74: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_0;
    // 0x80007E74: nop

    after_0:
    // 0x80007E78: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80007E7C: beq         $a1, $zero, L_80007EC0
    if (ctx->r5 == 0) {
        // 0x80007E80: nop
    
            goto L_80007EC0;
    }
    // 0x80007E80: nop

    // 0x80007E84: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80007E88: beq         $v0, $zero, L_80007EA0
    if (ctx->r2 == 0) {
        // 0x80007E8C: addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
            goto L_80007EA0;
    }
    // 0x80007E8C: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
L_80007E90:
    // 0x80007E90: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80007E94: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80007E98: bne         $v0, $zero, L_80007E90
    if (ctx->r2 != 0) {
        // 0x80007E9C: nop
    
            goto L_80007E90;
    }
    // 0x80007E9C: nop

L_80007EA0:
    // 0x80007EA0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80007EA4: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80007EA8: beq         $v0, $zero, L_80007EB4
    if (ctx->r2 == 0) {
        // 0x80007EAC: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80007EB4;
    }
    // 0x80007EAC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80007EB0: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_80007EB4:
    // 0x80007EB4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80007EB8: sw          $a1, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r5;
    // 0x80007EBC: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_80007EC0:
    // 0x80007EC0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80007EC4: lw          $a1, 0x63B0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X63B0);
L_80007EC8:
    // 0x80007EC8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80007ECC: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80007ED0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80007ED4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80007ED8: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x80007EDC: bnel        $v0, $zero, L_80007EE4
    if (ctx->r2 != 0) {
        // 0x80007EE0: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_80007EE4;
    }
    goto skip_0;
    // 0x80007EE0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_0:
L_80007EE4:
    // 0x80007EE4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80007EE8: lw          $v0, -0x5B3C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5B3C);
    // 0x80007EEC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80007EF0: bnel        $v0, $zero, L_80007EF8
    if (ctx->r2 != 0) {
        // 0x80007EF4: sw          $a1, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r5;
            goto L_80007EF8;
    }
    goto skip_1;
    // 0x80007EF4: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    skip_1:
L_80007EF8:
    // 0x80007EF8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80007EFC: lw          $a0, -0x5B3C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5B3C);
    // 0x80007F00: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80007F04: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x80007F08: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80007F0C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80007F10: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80007F14: jr          $ra
    // 0x80007F18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80007F18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80007F1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007F1C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80007F20: lw          $a1, 0x63B0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X63B0);
    // 0x80007F24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007F28: bne         $a1, $zero, L_80007F88
    if (ctx->r5 != 0) {
        // 0x80007F2C: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80007F88;
    }
    // 0x80007F2C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80007F30: jal         0x8002221C
    // 0x80007F34: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_0;
    // 0x80007F34: nop

    after_0:
    // 0x80007F38: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80007F3C: beq         $a1, $zero, L_80007F80
    if (ctx->r5 == 0) {
        // 0x80007F40: nop
    
            goto L_80007F80;
    }
    // 0x80007F40: nop

    // 0x80007F44: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80007F48: beq         $v0, $zero, L_80007F60
    if (ctx->r2 == 0) {
        // 0x80007F4C: addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
            goto L_80007F60;
    }
    // 0x80007F4C: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
L_80007F50:
    // 0x80007F50: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80007F54: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80007F58: bne         $v0, $zero, L_80007F50
    if (ctx->r2 != 0) {
        // 0x80007F5C: nop
    
            goto L_80007F50;
    }
    // 0x80007F5C: nop

L_80007F60:
    // 0x80007F60: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80007F64: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80007F68: beq         $v0, $zero, L_80007F74
    if (ctx->r2 == 0) {
        // 0x80007F6C: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80007F74;
    }
    // 0x80007F6C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80007F70: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_80007F74:
    // 0x80007F74: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80007F78: sw          $a1, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r5;
    // 0x80007F7C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_80007F80:
    // 0x80007F80: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80007F84: lw          $a1, 0x63B0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X63B0);
L_80007F88:
    // 0x80007F88: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80007F8C: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80007F90: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80007F94: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80007F98: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x80007F9C: bnel        $v0, $zero, L_80007FA4
    if (ctx->r2 != 0) {
        // 0x80007FA0: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_80007FA4;
    }
    goto skip_0;
    // 0x80007FA0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_0:
L_80007FA4:
    // 0x80007FA4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80007FA8: lw          $v0, -0x5B54($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5B54);
    // 0x80007FAC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80007FB0: bnel        $v0, $zero, L_80007FB8
    if (ctx->r2 != 0) {
        // 0x80007FB4: sw          $a1, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r5;
            goto L_80007FB8;
    }
    goto skip_1;
    // 0x80007FB4: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    skip_1:
L_80007FB8:
    // 0x80007FB8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80007FBC: lw          $a0, -0x5B54($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5B54);
    // 0x80007FC0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80007FC4: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x80007FC8: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80007FCC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80007FD0: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80007FD4: jr          $ra
    // 0x80007FD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80007FD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80007FDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007FDC: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80007FE0: lw          $a1, 0x63B0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X63B0);
    // 0x80007FE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007FE8: bne         $a1, $zero, L_80008048
    if (ctx->r5 != 0) {
        // 0x80007FEC: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80008048;
    }
    // 0x80007FEC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80007FF0: jal         0x8002221C
    // 0x80007FF4: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_0;
    // 0x80007FF4: nop

    after_0:
    // 0x80007FF8: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80007FFC: beq         $a1, $zero, L_80008040
    if (ctx->r5 == 0) {
        // 0x80008000: nop
    
            goto L_80008040;
    }
    // 0x80008000: nop

    // 0x80008004: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80008008: beq         $v0, $zero, L_80008020
    if (ctx->r2 == 0) {
        // 0x8000800C: addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
            goto L_80008020;
    }
    // 0x8000800C: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
L_80008010:
    // 0x80008010: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80008014: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80008018: bne         $v0, $zero, L_80008010
    if (ctx->r2 != 0) {
        // 0x8000801C: nop
    
            goto L_80008010;
    }
    // 0x8000801C: nop

L_80008020:
    // 0x80008020: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80008024: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80008028: beq         $v0, $zero, L_80008034
    if (ctx->r2 == 0) {
        // 0x8000802C: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80008034;
    }
    // 0x8000802C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80008030: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_80008034:
    // 0x80008034: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80008038: sw          $a1, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r5;
    // 0x8000803C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_80008040:
    // 0x80008040: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80008044: lw          $a1, 0x63B0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X63B0);
L_80008048:
    // 0x80008048: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000804C: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80008050: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80008054: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80008058: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000805C: bnel        $v0, $zero, L_80008064
    if (ctx->r2 != 0) {
        // 0x80008060: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_80008064;
    }
    goto skip_0;
    // 0x80008060: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_0:
L_80008064:
    // 0x80008064: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80008068: lw          $v0, -0x5B48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5B48);
    // 0x8000806C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80008070: bnel        $v0, $zero, L_80008078
    if (ctx->r2 != 0) {
        // 0x80008074: sw          $a1, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r5;
            goto L_80008078;
    }
    goto skip_1;
    // 0x80008074: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    skip_1:
L_80008078:
    // 0x80008078: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000807C: lw          $a0, -0x5B48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5B48);
    // 0x80008080: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80008084: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x80008088: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x8000808C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80008090: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80008094: jr          $ra
    // 0x80008098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80008098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8000809C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000809C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800080A0: lw          $a1, 0x63B0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X63B0);
    // 0x800080A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800080A8: bne         $a1, $zero, L_80008108
    if (ctx->r5 != 0) {
        // 0x800080AC: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80008108;
    }
    // 0x800080AC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800080B0: jal         0x8002221C
    // 0x800080B4: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_0;
    // 0x800080B4: nop

    after_0:
    // 0x800080B8: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800080BC: beq         $a1, $zero, L_80008100
    if (ctx->r5 == 0) {
        // 0x800080C0: nop
    
            goto L_80008100;
    }
    // 0x800080C0: nop

    // 0x800080C4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800080C8: beq         $v0, $zero, L_800080E0
    if (ctx->r2 == 0) {
        // 0x800080CC: addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
            goto L_800080E0;
    }
    // 0x800080CC: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
L_800080D0:
    // 0x800080D0: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800080D4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800080D8: bne         $v0, $zero, L_800080D0
    if (ctx->r2 != 0) {
        // 0x800080DC: nop
    
            goto L_800080D0;
    }
    // 0x800080DC: nop

L_800080E0:
    // 0x800080E0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800080E4: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x800080E8: beq         $v0, $zero, L_800080F4
    if (ctx->r2 == 0) {
        // 0x800080EC: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800080F4;
    }
    // 0x800080EC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800080F0: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_800080F4:
    // 0x800080F4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800080F8: sw          $a1, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r5;
    // 0x800080FC: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_80008100:
    // 0x80008100: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80008104: lw          $a1, 0x63B0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X63B0);
L_80008108:
    // 0x80008108: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000810C: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80008110: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80008114: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80008118: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000811C: bnel        $v0, $zero, L_80008124
    if (ctx->r2 != 0) {
        // 0x80008120: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_80008124;
    }
    goto skip_0;
    // 0x80008120: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_0:
L_80008124:
    // 0x80008124: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80008128: lw          $v0, -0x5B44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5B44);
    // 0x8000812C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80008130: bnel        $v0, $zero, L_80008138
    if (ctx->r2 != 0) {
        // 0x80008134: sw          $a1, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r5;
            goto L_80008138;
    }
    goto skip_1;
    // 0x80008134: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    skip_1:
L_80008138:
    // 0x80008138: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000813C: lw          $a0, -0x5B44($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5B44);
    // 0x80008140: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80008144: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x80008148: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x8000814C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80008150: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80008154: jr          $ra
    // 0x80008158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80008158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void drainMeshReleaseQueue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000815C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80008160: lhu         $v0, 0x3230($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3230);
    // 0x80008164: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80008168: blez        $v0, L_8000833C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000816C: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_8000833C;
    }
    // 0x8000816C: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x80008170: addu        $t4, $v0, $zero
    ctx->r12 = ADD32(ctx->r2, 0);
    // 0x80008174: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80008178: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000817C: addiu       $v0, $v0, 0x2B34
    ctx->r2 = ADD32(ctx->r2, 0X2B34);
    // 0x80008180: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x80008184: addu        $t3, $v0, $zero
    ctx->r11 = ADD32(ctx->r2, 0);
L_80008188:
    // 0x80008188: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000818C: addu        $at, $at, $a3
    ctx->r1 = ADD32(ctx->r1, ctx->r7);
    // 0x80008190: lw          $a0, 0x2B30($at)
    ctx->r4 = MEM_W(ctx->r1, 0X2B30);
    // 0x80008194: beq         $a0, $zero, L_800081DC
    if (ctx->r4 == 0) {
        // 0x80008198: addu        $a1, $t0, $zero
        ctx->r5 = ADD32(ctx->r8, 0);
            goto L_800081DC;
    }
    // 0x80008198: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x8000819C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800081A0: beq         $v0, $zero, L_800081B8
    if (ctx->r2 == 0) {
        // 0x800081A4: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_800081B8;
    }
    // 0x800081A4: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_800081A8:
    // 0x800081A8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800081AC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800081B0: bne         $v0, $zero, L_800081A8
    if (ctx->r2 != 0) {
        // 0x800081B4: nop
    
            goto L_800081A8;
    }
    // 0x800081B4: nop

L_800081B8:
    // 0x800081B8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800081BC: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x800081C0: beq         $v0, $zero, L_800081CC
    if (ctx->r2 == 0) {
        // 0x800081C4: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800081CC;
    }
    // 0x800081C4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800081C8: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_800081CC:
    // 0x800081CC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800081D0: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x800081D4: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800081D8: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
L_800081DC:
    // 0x800081DC: addu        $a2, $t3, $zero
    ctx->r6 = ADD32(ctx->r11, 0);
    // 0x800081E0: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
L_800081E4:
    // 0x800081E4: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x800081E8: beq         $a0, $zero, L_8000822C
    if (ctx->r4 == 0) {
        // 0x800081EC: nop
    
            goto L_8000822C;
    }
    // 0x800081EC: nop

    // 0x800081F0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800081F4: beq         $v0, $zero, L_8000820C
    if (ctx->r2 == 0) {
        // 0x800081F8: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000820C;
    }
    // 0x800081F8: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_800081FC:
    // 0x800081FC: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80008200: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80008204: bne         $v0, $zero, L_800081FC
    if (ctx->r2 != 0) {
        // 0x80008208: nop
    
            goto L_800081FC;
    }
    // 0x80008208: nop

L_8000820C:
    // 0x8000820C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80008210: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80008214: beq         $v0, $zero, L_80008220
    if (ctx->r2 == 0) {
        // 0x80008218: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80008220;
    }
    // 0x80008218: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000821C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_80008220:
    // 0x80008220: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80008224: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x80008228: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000822C:
    // 0x8000822C: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80008230: beql        $a0, $zero, L_80008278
    if (ctx->r4 == 0) {
        // 0x80008234: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80008278;
    }
    goto skip_0;
    // 0x80008234: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    skip_0:
    // 0x80008238: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000823C: beq         $v0, $zero, L_80008254
    if (ctx->r2 == 0) {
        // 0x80008240: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80008254;
    }
    // 0x80008240: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_80008244:
    // 0x80008244: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80008248: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000824C: bne         $v0, $zero, L_80008244
    if (ctx->r2 != 0) {
        // 0x80008250: nop
    
            goto L_80008244;
    }
    // 0x80008250: nop

L_80008254:
    // 0x80008254: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80008258: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000825C: beq         $v0, $zero, L_80008268
    if (ctx->r2 == 0) {
        // 0x80008260: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80008268;
    }
    // 0x80008260: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80008264: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_80008268:
    // 0x80008268: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000826C: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x80008270: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80008274: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_80008278:
    // 0x80008278: slt         $v0, $a1, $t1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8000827C: bne         $v0, $zero, L_800081E4
    if (ctx->r2 != 0) {
        // 0x80008280: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800081E4;
    }
    // 0x80008280: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80008284: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80008288: addu        $at, $at, $a3
    ctx->r1 = ADD32(ctx->r1, ctx->r7);
    // 0x8000828C: lw          $a0, 0x2B48($at)
    ctx->r4 = MEM_W(ctx->r1, 0X2B48);
    // 0x80008290: beq         $a0, $zero, L_800082D4
    if (ctx->r4 == 0) {
        // 0x80008294: nop
    
            goto L_800082D4;
    }
    // 0x80008294: nop

    // 0x80008298: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000829C: beq         $v0, $zero, L_800082B4
    if (ctx->r2 == 0) {
        // 0x800082A0: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_800082B4;
    }
    // 0x800082A0: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_800082A4:
    // 0x800082A4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800082A8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800082AC: bne         $v0, $zero, L_800082A4
    if (ctx->r2 != 0) {
        // 0x800082B0: nop
    
            goto L_800082A4;
    }
    // 0x800082B0: nop

L_800082B4:
    // 0x800082B4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800082B8: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x800082BC: beq         $v0, $zero, L_800082C8
    if (ctx->r2 == 0) {
        // 0x800082C0: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800082C8;
    }
    // 0x800082C0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800082C4: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_800082C8:
    // 0x800082C8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800082CC: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x800082D0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_800082D4:
    // 0x800082D4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800082D8: addu        $at, $at, $a3
    ctx->r1 = ADD32(ctx->r1, ctx->r7);
    // 0x800082DC: lw          $a0, 0x2B44($at)
    ctx->r4 = MEM_W(ctx->r1, 0X2B44);
    // 0x800082E0: beql        $a0, $zero, L_80008328
    if (ctx->r4 == 0) {
        // 0x800082E4: addiu       $a3, $a3, 0x1C
        ctx->r7 = ADD32(ctx->r7, 0X1C);
            goto L_80008328;
    }
    goto skip_1;
    // 0x800082E4: addiu       $a3, $a3, 0x1C
    ctx->r7 = ADD32(ctx->r7, 0X1C);
    skip_1:
    // 0x800082E8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800082EC: beq         $v0, $zero, L_80008304
    if (ctx->r2 == 0) {
        // 0x800082F0: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80008304;
    }
    // 0x800082F0: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_800082F4:
    // 0x800082F4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800082F8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800082FC: bne         $v0, $zero, L_800082F4
    if (ctx->r2 != 0) {
        // 0x80008300: nop
    
            goto L_800082F4;
    }
    // 0x80008300: nop

L_80008304:
    // 0x80008304: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80008308: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000830C: beq         $v0, $zero, L_80008318
    if (ctx->r2 == 0) {
        // 0x80008310: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80008318;
    }
    // 0x80008310: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80008314: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_80008318:
    // 0x80008318: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000831C: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x80008320: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80008324: addiu       $a3, $a3, 0x1C
    ctx->r7 = ADD32(ctx->r7, 0X1C);
L_80008328:
    // 0x80008328: addiu       $t0, $t0, 0x1C
    ctx->r8 = ADD32(ctx->r8, 0X1C);
    // 0x8000832C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80008330: slt         $v0, $t2, $t4
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80008334: bne         $v0, $zero, L_80008188
    if (ctx->r2 != 0) {
        // 0x80008338: addiu       $t3, $t3, 0x1C
        ctx->r11 = ADD32(ctx->r11, 0X1C);
            goto L_80008188;
    }
    // 0x80008338: addiu       $t3, $t3, 0x1C
    ctx->r11 = ADD32(ctx->r11, 0X1C);
L_8000833C:
    // 0x8000833C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80008340: sh          $zero, 0x3230($at)
    MEM_H(0X3230, ctx->r1) = 0;
    // 0x80008344: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80008348: jr          $ra
    // 0x8000834C: nop

    return;
    // 0x8000834C: nop

;}
RECOMP_FUNC void enqueueMeshForDeferredRelease(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008350: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80008354: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x80008358: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8000835C: beq         $v0, $zero, L_800083FC
    if (ctx->r2 == 0) {
        // 0x80008360: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800083FC;
    }
    // 0x80008360: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80008364: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80008368: lhu         $a0, 0x3230($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X3230);
    // 0x8000836C: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x80008370: sltiu       $v0, $v1, 0x40
    ctx->r2 = ctx->r3 < 0X40 ? 1 : 0;
    // 0x80008374: beq         $v0, $zero, L_800083A0
    if (ctx->r2 == 0) {
        // 0x80008378: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_800083A0;
    }
    // 0x80008378: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8000837C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80008380: sh          $v0, 0x3230($at)
    MEM_H(0X3230, ctx->r1) = ctx->r2;
    // 0x80008384: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80008388: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8000838C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80008390: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80008394: addiu       $v1, $v1, 0x2B30
    ctx->r3 = ADD32(ctx->r3, 0X2B30);
    // 0x80008398: j           L_800083A4
    // 0x8000839C: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
        goto L_800083A4;
    // 0x8000839C: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
L_800083A0:
    // 0x800083A0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800083A4:
    // 0x800083A4: beq         $v1, $zero, L_800083F8
    if (ctx->r3 == 0) {
        // 0x800083A8: addiu       $a0, $zero, -0x19
        ctx->r4 = ADD32(0, -0X19);
            goto L_800083F8;
    }
    // 0x800083A8: addiu       $a0, $zero, -0x19
    ctx->r4 = ADD32(0, -0X19);
    // 0x800083AC: lw          $v0, 0x3C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X3C);
    // 0x800083B0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800083B4: lw          $v0, 0x44($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X44);
    // 0x800083B8: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x800083BC: lw          $v0, 0x48($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X48);
    // 0x800083C0: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x800083C4: lw          $v0, 0x4C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4C);
    // 0x800083C8: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x800083CC: lw          $v0, 0x50($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X50);
    // 0x800083D0: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x800083D4: lw          $v0, 0x54($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X54);
    // 0x800083D8: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x800083DC: lw          $v0, 0x58($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X58);
    // 0x800083E0: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x800083E4: lw          $v1, 0xC($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XC);
    // 0x800083E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800083EC: and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // 0x800083F0: j           L_800083FC
    // 0x800083F4: sw          $v1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r3;
        goto L_800083FC;
    // 0x800083F4: sw          $v1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r3;
L_800083F8:
    // 0x800083F8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800083FC:
    // 0x800083FC: jr          $ra
    // 0x80008400: nop

    return;
    // 0x80008400: nop

;}
RECOMP_FUNC void func_80008404(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008404: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80008408: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000840C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80008410: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80008414: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x80008418: lui         $v0, 0x4000
    ctx->r2 = S32(0X4000 << 16);
    // 0x8000841C: and         $a1, $a1, $v0
    ctx->r5 = ctx->r5 & ctx->r2;
    // 0x80008420: beq         $a1, $zero, L_80008538
    if (ctx->r5 == 0) {
        // 0x80008424: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_80008538;
    }
    // 0x80008424: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80008428: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000842C: lbu         $v0, -0x2F6C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2F6C);
    // 0x80008430: sltiu       $v0, $v0, 0x40
    ctx->r2 = ctx->r2 < 0X40 ? 1 : 0;
    // 0x80008434: bne         $v0, $zero, L_80008500
    if (ctx->r2 != 0) {
        // 0x80008438: lui         $a0, 0xFF
        ctx->r4 = S32(0XFF << 16);
            goto L_80008500;
    }
    // 0x80008438: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x8000843C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80008440: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x80008444: bne         $a0, $zero, L_800084A4
    if (ctx->r4 != 0) {
        // 0x80008448: nop
    
            goto L_800084A4;
    }
    // 0x80008448: nop

    // 0x8000844C: jal         0x8002221C
    // 0x80008450: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_0;
    // 0x80008450: nop

    after_0:
    // 0x80008454: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80008458: beq         $a0, $zero, L_8000849C
    if (ctx->r4 == 0) {
        // 0x8000845C: nop
    
            goto L_8000849C;
    }
    // 0x8000845C: nop

    // 0x80008460: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80008464: beq         $v0, $zero, L_8000847C
    if (ctx->r2 == 0) {
        // 0x80008468: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000847C;
    }
    // 0x80008468: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000846C:
    // 0x8000846C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80008470: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80008474: bne         $v0, $zero, L_8000846C
    if (ctx->r2 != 0) {
        // 0x80008478: nop
    
            goto L_8000846C;
    }
    // 0x80008478: nop

L_8000847C:
    // 0x8000847C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80008480: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80008484: beq         $v0, $zero, L_80008490
    if (ctx->r2 == 0) {
        // 0x80008488: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80008490;
    }
    // 0x80008488: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000848C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_80008490:
    // 0x80008490: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80008494: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x80008498: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000849C:
    // 0x8000849C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800084A0: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_800084A4:
    // 0x800084A4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800084A8: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x800084AC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800084B0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800084B4: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x800084B8: bnel        $v0, $zero, L_800084C0
    if (ctx->r2 != 0) {
        // 0x800084BC: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_800084C0;
    }
    goto skip_0;
    // 0x800084BC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_0:
L_800084C0:
    // 0x800084C0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800084C4: lw          $v0, -0x5B44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5B44);
    // 0x800084C8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800084CC: bnel        $v0, $zero, L_800084D4
    if (ctx->r2 != 0) {
        // 0x800084D0: sw          $a0, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r4;
            goto L_800084D4;
    }
    goto skip_1;
    // 0x800084D0: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    skip_1:
L_800084D4:
    // 0x800084D4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800084D8: lw          $v0, -0x5B44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5B44);
    // 0x800084DC: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800084E0: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800084E4: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800084E8: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x800084EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800084F0: sw          $v0, -0x2F70($at)
    MEM_W(-0X2F70, ctx->r1) = ctx->r2;
    // 0x800084F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800084F8: sb          $zero, -0x2F6C($at)
    MEM_B(-0X2F6C, ctx->r1) = 0;
    // 0x800084FC: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
L_80008500:
    // 0x80008500: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80008504: addiu       $a1, $a1, -0x2F6C
    ctx->r5 = ADD32(ctx->r5, -0X2F6C);
    // 0x80008508: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x8000850C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80008510: lw          $a2, -0x2F70($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2F70);
    // 0x80008514: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x80008518: and         $a0, $s0, $a0
    ctx->r4 = ctx->r16 & ctx->r4;
    // 0x8000851C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80008520: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80008524: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x80008528: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x8000852C: sll         $v0, $s1, 24
    ctx->r2 = S32(ctx->r17 << 24);
    // 0x80008530: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x80008534: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_80008538:
    // 0x80008538: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8000853C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80008540: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80008544: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80008548: jr          $ra
    // 0x8000854C: nop

    return;
    // 0x8000854C: nop

;}
RECOMP_FUNC void commitMeshDrawBatchRefs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008550: lw          $a1, 0xC($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XC);
    // 0x80008554: andi        $v0, $a1, 0x10
    ctx->r2 = ctx->r5 & 0X10;
    // 0x80008558: beq         $v0, $zero, L_80008680
    if (ctx->r2 == 0) {
        // 0x8000855C: andi        $v0, $a1, 0x60
        ctx->r2 = ctx->r5 & 0X60;
            goto L_80008680;
    }
    // 0x8000855C: andi        $v0, $a1, 0x60
    ctx->r2 = ctx->r5 & 0X60;
    // 0x80008560: beq         $v0, $zero, L_80008680
    if (ctx->r2 == 0) {
        // 0x80008564: addiu       $v1, $zero, -0x61
        ctx->r3 = ADD32(0, -0X61);
            goto L_80008680;
    }
    // 0x80008564: addiu       $v1, $zero, -0x61
    ctx->r3 = ADD32(0, -0X61);
    // 0x80008568: lw          $t0, 0x58($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X58);
    // 0x8000856C: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x80008570: and         $v1, $a1, $v1
    ctx->r3 = ctx->r5 & ctx->r3;
    // 0x80008574: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
    // 0x80008578: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x8000857C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80008580: bne         $v0, $zero, L_8000858C
    if (ctx->r2 != 0) {
        // 0x80008584: addiu       $a2, $a0, 0x44
        ctx->r6 = ADD32(ctx->r4, 0X44);
            goto L_8000858C;
    }
    // 0x80008584: addiu       $a2, $a0, 0x44
    ctx->r6 = ADD32(ctx->r4, 0X44);
    // 0x80008588: addiu       $a2, $a0, 0x48
    ctx->r6 = ADD32(ctx->r4, 0X48);
L_8000858C:
    // 0x8000858C: lw          $a2, 0x0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X0);
    // 0x80008590: bne         $v0, $zero, L_8000859C
    if (ctx->r2 != 0) {
        // 0x80008594: addiu       $v1, $a0, 0x4C
        ctx->r3 = ADD32(ctx->r4, 0X4C);
            goto L_8000859C;
    }
    // 0x80008594: addiu       $v1, $a0, 0x4C
    ctx->r3 = ADD32(ctx->r4, 0X4C);
    // 0x80008598: addiu       $v1, $a0, 0x50
    ctx->r3 = ADD32(ctx->r4, 0X50);
L_8000859C:
    // 0x8000859C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800085A0: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800085A4: beq         $v0, $zero, L_800085C8
    if (ctx->r2 == 0) {
        // 0x800085A8: nop
    
            goto L_800085C8;
    }
    // 0x800085A8: nop

L_800085AC:
    // 0x800085AC: lw          $a2, 0x0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X0);
    // 0x800085B0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800085B4: beq         $v0, $zero, L_800085C8
    if (ctx->r2 == 0) {
        // 0x800085B8: nop
    
            goto L_800085C8;
    }
    // 0x800085B8: nop

    // 0x800085BC: j           L_800085AC
    // 0x800085C0: nop

        goto L_800085AC;
    // 0x800085C0: nop

L_800085C4:
    // 0x800085C4: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
L_800085C8:
    // 0x800085C8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800085CC: bne         $v0, $zero, L_800085C4
    if (ctx->r2 != 0) {
        // 0x800085D0: nop
    
            goto L_800085C4;
    }
    // 0x800085D0: nop

    // 0x800085D4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800085D8: beq         $v0, $zero, L_800085F0
    if (ctx->r2 == 0) {
        // 0x800085DC: sltu        $v0, $zero, $a2
        ctx->r2 = 0 < ctx->r6 ? 1 : 0;
            goto L_800085F0;
    }
    // 0x800085DC: sltu        $v0, $zero, $a2
    ctx->r2 = 0 < ctx->r6 ? 1 : 0;
L_800085E0:
    // 0x800085E0: lw          $t0, 0x0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X0);
    // 0x800085E4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800085E8: bne         $v0, $zero, L_800085E0
    if (ctx->r2 != 0) {
        // 0x800085EC: sltu        $v0, $zero, $a2
        ctx->r2 = 0 < ctx->r6 ? 1 : 0;
            goto L_800085E0;
    }
    // 0x800085EC: sltu        $v0, $zero, $a2
    ctx->r2 = 0 < ctx->r6 ? 1 : 0;
L_800085F0:
    // 0x800085F0: sltu        $v1, $zero, $a1
    ctx->r3 = 0 < ctx->r5 ? 1 : 0;
    // 0x800085F4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800085F8: beq         $v0, $zero, L_80008680
    if (ctx->r2 == 0) {
        // 0x800085FC: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_80008680;
    }
    // 0x800085FC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80008600: lui         $t1, 0xFF
    ctx->r9 = S32(0XFF << 16);
    // 0x80008604: ori         $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 | 0XFFFF;
    // 0x80008608: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8000860C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80008610: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x80008614: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
L_80008618:
    // 0x80008618: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8000861C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80008620: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80008624: and         $v0, $v1, $t1
    ctx->r2 = ctx->r3 & ctx->r9;
    // 0x80008628: srl         $v1, $v1, 24
    ctx->r3 = S32(U32(ctx->r3) >> 24);
    // 0x8000862C: beq         $v1, $zero, L_80008644
    if (ctx->r3 == 0) {
        // 0x80008630: or          $a0, $v0, $t4
        ctx->r4 = ctx->r2 | ctx->r12;
            goto L_80008644;
    }
    // 0x80008630: or          $a0, $v0, $t4
    ctx->r4 = ctx->r2 | ctx->r12;
    // 0x80008634: beq         $v1, $t3, L_80008658
    if (ctx->r3 == ctx->r11) {
        // 0x80008638: addiu       $v0, $a1, 0x8
        ctx->r2 = ADD32(ctx->r5, 0X8);
            goto L_80008658;
    }
    // 0x80008638: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x8000863C: j           L_80008660
    // 0x80008640: nop

        goto L_80008660;
    // 0x80008640: nop

L_80008644:
    // 0x80008644: addiu       $v0, $a2, 0x8
    ctx->r2 = ADD32(ctx->r6, 0X8);
    // 0x80008648: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8000864C: lw          $a2, 0x4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X4);
    // 0x80008650: j           L_80008660
    // 0x80008654: nop

        goto L_80008660;
    // 0x80008654: nop

L_80008658:
    // 0x80008658: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8000865C: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
L_80008660:
    // 0x80008660: bne         $a3, $t2, L_80008670
    if (ctx->r7 != ctx->r10) {
        // 0x80008664: sltu        $v0, $zero, $a2
        ctx->r2 = 0 < ctx->r6 ? 1 : 0;
            goto L_80008670;
    }
    // 0x80008664: sltu        $v0, $zero, $a2
    ctx->r2 = 0 < ctx->r6 ? 1 : 0;
    // 0x80008668: lw          $t0, 0x4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4);
    // 0x8000866C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_80008670:
    // 0x80008670: sltu        $v1, $zero, $a1
    ctx->r3 = 0 < ctx->r5 ? 1 : 0;
    // 0x80008674: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80008678: bne         $v0, $zero, L_80008618
    if (ctx->r2 != 0) {
        // 0x8000867C: sll         $v0, $a3, 2
        ctx->r2 = S32(ctx->r7 << 2);
            goto L_80008618;
    }
    // 0x8000867C: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
L_80008680:
    // 0x80008680: jr          $ra
    // 0x80008684: nop

    return;
    // 0x80008684: nop

;}
RECOMP_FUNC void func_80008688(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008688: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000868C: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x80008690: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80008694: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80008698: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8000869C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800086A0: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800086A4: sltu        $v0, $s0, $v0
    ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800086A8: bne         $v0, $zero, L_80008790
    if (ctx->r2 != 0) {
        // 0x800086AC: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_80008790;
    }
    // 0x800086AC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800086B0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800086B4: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x800086B8: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x800086BC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800086C0: bne         $a0, $zero, L_80008720
    if (ctx->r4 != 0) {
        // 0x800086C4: sw          $zero, 0x4($s0)
        MEM_W(0X4, ctx->r16) = 0;
            goto L_80008720;
    }
    // 0x800086C4: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800086C8: jal         0x8002221C
    // 0x800086CC: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_0;
    // 0x800086CC: nop

    after_0:
    // 0x800086D0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800086D4: beq         $a0, $zero, L_80008718
    if (ctx->r4 == 0) {
        // 0x800086D8: nop
    
            goto L_80008718;
    }
    // 0x800086D8: nop

    // 0x800086DC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800086E0: beq         $v0, $zero, L_800086F8
    if (ctx->r2 == 0) {
        // 0x800086E4: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_800086F8;
    }
    // 0x800086E4: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_800086E8:
    // 0x800086E8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800086EC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800086F0: bne         $v0, $zero, L_800086E8
    if (ctx->r2 != 0) {
        // 0x800086F4: nop
    
            goto L_800086E8;
    }
    // 0x800086F4: nop

L_800086F8:
    // 0x800086F8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800086FC: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80008700: beq         $v0, $zero, L_8000870C
    if (ctx->r2 == 0) {
        // 0x80008704: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000870C;
    }
    // 0x80008704: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80008708: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000870C:
    // 0x8000870C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80008710: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x80008714: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_80008718:
    // 0x80008718: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000871C: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_80008720:
    // 0x80008720: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80008724: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80008728: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000872C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80008730: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x80008734: bnel        $v0, $zero, L_8000873C
    if (ctx->r2 != 0) {
        // 0x80008738: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000873C;
    }
    goto skip_0;
    // 0x80008738: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_0:
L_8000873C:
    // 0x8000873C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80008740: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x80008744: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80008748: bne         $v0, $zero, L_80008758
    if (ctx->r2 != 0) {
        // 0x8000874C: nop
    
            goto L_80008758;
    }
    // 0x8000874C: nop

    // 0x80008750: j           L_80008770
    // 0x80008754: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_80008770;
    // 0x80008754: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_80008758:
    // 0x80008758: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000875C: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x80008760: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80008764: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80008768: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000876C: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_80008770:
    // 0x80008770: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80008774: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x80008778: addiu       $s0, $a0, 0x8
    ctx->r16 = ADD32(ctx->r4, 0X8);
    // 0x8000877C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80008780: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80008784: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x80008788: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000878C: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
L_80008790:
    // 0x80008790: lui         $v0, 0x4000
    ctx->r2 = S32(0X4000 << 16);
    // 0x80008794: and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // 0x80008798: beq         $v0, $zero, L_800088A8
    if (ctx->r2 == 0) {
        // 0x8000879C: nop
    
            goto L_800088A8;
    }
    // 0x8000879C: nop

    // 0x800087A0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800087A4: lbu         $v0, -0x2F6C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2F6C);
    // 0x800087A8: sltiu       $v0, $v0, 0x40
    ctx->r2 = ctx->r2 < 0X40 ? 1 : 0;
    // 0x800087AC: bne         $v0, $zero, L_80008878
    if (ctx->r2 != 0) {
        // 0x800087B0: lui         $a0, 0xFF
        ctx->r4 = S32(0XFF << 16);
            goto L_80008878;
    }
    // 0x800087B0: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x800087B4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800087B8: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x800087BC: bne         $a0, $zero, L_8000881C
    if (ctx->r4 != 0) {
        // 0x800087C0: nop
    
            goto L_8000881C;
    }
    // 0x800087C0: nop

    // 0x800087C4: jal         0x8002221C
    // 0x800087C8: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_1;
    // 0x800087C8: nop

    after_1:
    // 0x800087CC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800087D0: beq         $a0, $zero, L_80008814
    if (ctx->r4 == 0) {
        // 0x800087D4: nop
    
            goto L_80008814;
    }
    // 0x800087D4: nop

    // 0x800087D8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800087DC: beq         $v0, $zero, L_800087F4
    if (ctx->r2 == 0) {
        // 0x800087E0: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_800087F4;
    }
    // 0x800087E0: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_800087E4:
    // 0x800087E4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800087E8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800087EC: bne         $v0, $zero, L_800087E4
    if (ctx->r2 != 0) {
        // 0x800087F0: nop
    
            goto L_800087E4;
    }
    // 0x800087F0: nop

L_800087F4:
    // 0x800087F4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800087F8: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x800087FC: beq         $v0, $zero, L_80008808
    if (ctx->r2 == 0) {
        // 0x80008800: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80008808;
    }
    // 0x80008800: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80008804: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_80008808:
    // 0x80008808: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000880C: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x80008810: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_80008814:
    // 0x80008814: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80008818: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000881C:
    // 0x8000881C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80008820: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80008824: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80008828: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000882C: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x80008830: bnel        $v0, $zero, L_80008838
    if (ctx->r2 != 0) {
        // 0x80008834: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_80008838;
    }
    goto skip_1;
    // 0x80008834: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_1:
L_80008838:
    // 0x80008838: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000883C: lw          $v0, -0x5B44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5B44);
    // 0x80008840: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80008844: bnel        $v0, $zero, L_8000884C
    if (ctx->r2 != 0) {
        // 0x80008848: sw          $a0, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r4;
            goto L_8000884C;
    }
    goto skip_2;
    // 0x80008848: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    skip_2:
L_8000884C:
    // 0x8000884C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80008850: lw          $v0, -0x5B44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5B44);
    // 0x80008854: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80008858: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x8000885C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80008860: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80008864: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80008868: sw          $v0, -0x2F70($at)
    MEM_W(-0X2F70, ctx->r1) = ctx->r2;
    // 0x8000886C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80008870: sb          $zero, -0x2F6C($at)
    MEM_B(-0X2F6C, ctx->r1) = 0;
    // 0x80008874: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
L_80008878:
    // 0x80008878: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000887C: lbu         $v1, -0x2F6C($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X2F6C);
    // 0x80008880: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80008884: lw          $a1, -0x2F70($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2F70);
    // 0x80008888: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x8000888C: and         $a0, $s0, $a0
    ctx->r4 = ctx->r16 & ctx->r4;
    // 0x80008890: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80008894: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80008898: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8000889C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800088A0: sb          $v0, -0x2F6C($at)
    MEM_B(-0X2F6C, ctx->r1) = ctx->r2;
    // 0x800088A4: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_800088A8:
    // 0x800088A8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800088AC: lw          $a1, 0x63B0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X63B0);
    // 0x800088B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800088B4: sw          $s0, -0x5BB8($at)
    MEM_W(-0X5BB8, ctx->r1) = ctx->r16;
    // 0x800088B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800088BC: sb          $zero, -0x5BB0($at)
    MEM_B(-0X5BB0, ctx->r1) = 0;
    // 0x800088C0: bne         $a1, $zero, L_80008920
    if (ctx->r5 != 0) {
        // 0x800088C4: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_80008920;
    }
    // 0x800088C4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800088C8: jal         0x8002221C
    // 0x800088CC: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_2;
    // 0x800088CC: nop

    after_2:
    // 0x800088D0: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800088D4: beq         $a1, $zero, L_80008918
    if (ctx->r5 == 0) {
        // 0x800088D8: nop
    
            goto L_80008918;
    }
    // 0x800088D8: nop

    // 0x800088DC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800088E0: beq         $v0, $zero, L_800088F8
    if (ctx->r2 == 0) {
        // 0x800088E4: addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
            goto L_800088F8;
    }
    // 0x800088E4: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
L_800088E8:
    // 0x800088E8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800088EC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800088F0: bne         $v0, $zero, L_800088E8
    if (ctx->r2 != 0) {
        // 0x800088F4: nop
    
            goto L_800088E8;
    }
    // 0x800088F4: nop

L_800088F8:
    // 0x800088F8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800088FC: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80008900: beq         $v0, $zero, L_8000890C
    if (ctx->r2 == 0) {
        // 0x80008904: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000890C;
    }
    // 0x80008904: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80008908: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000890C:
    // 0x8000890C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80008910: sw          $a1, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r5;
    // 0x80008914: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_80008918:
    // 0x80008918: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8000891C: lw          $a1, 0x63B0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X63B0);
L_80008920:
    // 0x80008920: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80008924: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80008928: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000892C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80008930: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x80008934: bnel        $v0, $zero, L_8000893C
    if (ctx->r2 != 0) {
        // 0x80008938: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000893C;
    }
    goto skip_3;
    // 0x80008938: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_3:
L_8000893C:
    // 0x8000893C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80008940: lw          $v0, -0x5B3C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5B3C);
    // 0x80008944: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80008948: bnel        $v0, $zero, L_80008950
    if (ctx->r2 != 0) {
        // 0x8000894C: sw          $a1, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r5;
            goto L_80008950;
    }
    goto skip_4;
    // 0x8000894C: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    skip_4:
L_80008950:
    // 0x80008950: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80008954: lw          $a0, -0x5B3C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5B3C);
    // 0x80008958: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8000895C: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x80008960: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80008964: addiu       $v1, $a1, 0x8
    ctx->r3 = ADD32(ctx->r5, 0X8);
    // 0x80008968: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x8000896C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80008970: sw          $v1, -0x5BB4($at)
    MEM_W(-0X5BB4, ctx->r1) = ctx->r3;
    // 0x80008974: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80008978: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8000897C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80008980: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80008984: jr          $ra
    // 0x80008988: nop

    return;
    // 0x80008988: nop

;}
RECOMP_FUNC void func_8000898C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000898C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80008990: addu        $t4, $a0, $zero
    ctx->r12 = ADD32(ctx->r4, 0);
    // 0x80008994: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80008998: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x8000899C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800089A0: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x800089A4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800089A8: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800089AC: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x800089B0: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x800089B4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800089B8: addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    // 0x800089BC: addiu       $t1, $sp, 0x10
    ctx->r9 = ADD32(ctx->r29, 0X10);
    // 0x800089C0: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800089C4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800089C8: beq         $v0, $zero, L_80008A54
    if (ctx->r2 == 0) {
        // 0x800089CC: sw          $s3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r19;
            goto L_80008A54;
    }
    // 0x800089CC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800089D0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800089D4: addu        $t3, $v0, $zero
    ctx->r11 = ADD32(ctx->r2, 0);
    // 0x800089D8: andi        $a3, $t0, 0xFF
    ctx->r7 = ctx->r8 & 0XFF;
L_800089DC:
    // 0x800089DC: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x800089E0: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x800089E4: lhu         $a1, 0x0($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X0);
    // 0x800089E8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800089EC: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x800089F0: lbu         $a2, 0x32C0($at)
    ctx->r6 = MEM_BU(ctx->r1, 0X32C0);
    // 0x800089F4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800089F8: lhu         $v0, 0x42C0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X42C0);
    // 0x800089FC: sll         $a0, $a2, 2
    ctx->r4 = S32(ctx->r6 << 2);
    // 0x80008A00: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80008A04: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80008A08: lhu         $v1, 0x3242($at)
    ctx->r3 = MEM_HU(ctx->r1, 0X3242);
    // 0x80008A0C: bne         $v1, $v0, L_80008A34
    if (ctx->r3 != ctx->r2) {
        // 0x80008A10: andi        $v0, $t0, 0xFF
        ctx->r2 = ctx->r8 & 0XFF;
            goto L_80008A34;
    }
    // 0x80008A10: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // 0x80008A14: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80008A18: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80008A1C: lhu         $v0, 0x3240($at)
    ctx->r2 = MEM_HU(ctx->r1, 0X3240);
    // 0x80008A20: bne         $v0, $a1, L_80008A34
    if (ctx->r2 != ctx->r5) {
        // 0x80008A24: andi        $v0, $t0, 0xFF
        ctx->r2 = ctx->r8 & 0XFF;
            goto L_80008A34;
    }
    // 0x80008A24: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // 0x80008A28: addu        $v0, $t1, $a3
    ctx->r2 = ADD32(ctx->r9, ctx->r7);
    // 0x80008A2C: j           L_80008A40
    // 0x80008A30: sb          $a2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r6;
        goto L_80008A40;
    // 0x80008A30: sb          $a2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r6;
L_80008A34:
    // 0x80008A34: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x80008A38: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    // 0x80008A3C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_80008A40:
    // 0x80008A40: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80008A44: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // 0x80008A48: sltu        $v0, $v0, $t3
    ctx->r2 = ctx->r2 < ctx->r11 ? 1 : 0;
    // 0x80008A4C: bne         $v0, $zero, L_800089DC
    if (ctx->r2 != 0) {
        // 0x80008A50: andi        $a3, $t0, 0xFF
        ctx->r7 = ctx->r8 & 0XFF;
            goto L_800089DC;
    }
    // 0x80008A50: andi        $a3, $t0, 0xFF
    ctx->r7 = ctx->r8 & 0XFF;
L_80008A54:
    // 0x80008A54: andi        $a0, $t2, 0xFF
    ctx->r4 = ctx->r10 & 0XFF;
    // 0x80008A58: beq         $a0, $zero, L_80008C9C
    if (ctx->r4 == 0) {
        // 0x80008A5C: addiu       $v0, $zero, 0x20
        ctx->r2 = ADD32(0, 0X20);
            goto L_80008C9C;
    }
    // 0x80008A5C: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x80008A60: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80008A64: addiu       $s3, $s3, -0x5BB0
    ctx->r19 = ADD32(ctx->r19, -0X5BB0);
    // 0x80008A68: lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X0);
    // 0x80008A6C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80008A70: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80008A74: beq         $v0, $zero, L_80008BAC
    if (ctx->r2 == 0) {
        // 0x80008A78: andi        $a3, $s2, 0xFF
        ctx->r7 = ctx->r18 & 0XFF;
            goto L_80008BAC;
    }
    // 0x80008A78: andi        $a3, $s2, 0xFF
    ctx->r7 = ctx->r18 & 0XFF;
    // 0x80008A7C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80008A80: lbu         $v0, -0x5BB0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5BB0);
    // 0x80008A84: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80008A88: lw          $a0, -0x5BB8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5BB8);
    // 0x80008A8C: sll         $v1, $v0, 10
    ctx->r3 = S32(ctx->r2 << 10);
    // 0x80008A90: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80008A94: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x80008A98: andi        $v0, $v0, 0xFFF0
    ctx->r2 = ctx->r2 & 0XFFF0;
    // 0x80008A9C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80008AA0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80008AA4: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80008AA8: lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // 0x80008AAC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80008AB0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80008AB4: lhu         $v0, 0x42C0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X42C0);
    // 0x80008AB8: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80008ABC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80008AC0: lw          $v1, -0x5BB4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5BB4);
    // 0x80008AC4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80008AC8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80008ACC: sh          $v0, 0x42C0($at)
    MEM_H(0X42C0, ctx->r1) = ctx->r2;
    // 0x80008AD0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80008AD4: bne         $v0, $zero, L_80008AE8
    if (ctx->r2 != 0) {
        // 0x80008AD8: sw          $v1, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r3;
            goto L_80008AE8;
    }
    // 0x80008AD8: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x80008ADC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80008AE0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80008AE4: sh          $v0, 0x42C0($at)
    MEM_H(0X42C0, ctx->r1) = ctx->r2;
L_80008AE8:
    // 0x80008AE8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80008AEC: jal         0x80008688
    // 0x80008AF0: addu        $a0, $t4, $zero
    ctx->r4 = ADD32(ctx->r12, 0);
    func_80008688(rdram, ctx);
        goto after_0;
    // 0x80008AF0: addu        $a0, $t4, $zero
    ctx->r4 = ADD32(ctx->r12, 0);
    after_0:
    // 0x80008AF4: addu        $t4, $v0, $zero
    ctx->r12 = ADD32(ctx->r2, 0);
    // 0x80008AF8: andi        $a3, $s2, 0xFF
    ctx->r7 = ctx->r18 & 0XFF;
    // 0x80008AFC: beq         $a3, $zero, L_80008CF8
    if (ctx->r7 == 0) {
        // 0x80008B00: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_80008CF8;
    }
    // 0x80008B00: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80008B04: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x80008B08: andi        $a1, $t0, 0xFF
    ctx->r5 = ctx->r8 & 0XFF;
L_80008B0C:
    // 0x80008B0C: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x80008B10: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x80008B14: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x80008B18: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x80008B1C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80008B20: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80008B24: sb          $v0, 0x32C0($at)
    MEM_B(0X32C0, ctx->r1) = ctx->r2;
    // 0x80008B28: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x80008B2C: lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X0);
    // 0x80008B30: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80008B34: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80008B38: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80008B3C: sh          $v1, 0x3240($at)
    MEM_H(0X3240, ctx->r1) = ctx->r3;
    // 0x80008B40: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x80008B44: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80008B48: lhu         $v1, 0x42C0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X42C0);
    // 0x80008B4C: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x80008B50: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80008B54: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80008B58: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80008B5C: sh          $v1, 0x3242($at)
    MEM_H(0X3242, ctx->r1) = ctx->r3;
    // 0x80008B60: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x80008B64: lw          $v1, -0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, -0X4);
    // 0x80008B68: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // 0x80008B6C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80008B70: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80008B74: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80008B78: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x80008B7C: addu        $a1, $s1, $a1
    ctx->r5 = ADD32(ctx->r17, ctx->r5);
    // 0x80008B80: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x80008B84: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x80008B88: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80008B8C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80008B90: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x80008B94: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // 0x80008B98: sltu        $v0, $v0, $a3
    ctx->r2 = ctx->r2 < ctx->r7 ? 1 : 0;
    // 0x80008B9C: bne         $v0, $zero, L_80008B0C
    if (ctx->r2 != 0) {
        // 0x80008BA0: andi        $a1, $t0, 0xFF
        ctx->r5 = ctx->r8 & 0XFF;
            goto L_80008B0C;
    }
    // 0x80008BA0: andi        $a1, $t0, 0xFF
    ctx->r5 = ctx->r8 & 0XFF;
    // 0x80008BA4: j           L_80008CFC
    // 0x80008BA8: addu        $v0, $t4, $zero
    ctx->r2 = ADD32(ctx->r12, 0);
        goto L_80008CFC;
    // 0x80008BA8: addu        $v0, $t4, $zero
    ctx->r2 = ADD32(ctx->r12, 0);
L_80008BAC:
    // 0x80008BAC: beq         $a3, $zero, L_80008CF8
    if (ctx->r7 == 0) {
        // 0x80008BB0: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_80008CF8;
    }
    // 0x80008BB0: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80008BB4: addiu       $t2, $sp, 0x10
    ctx->r10 = ADD32(ctx->r29, 0X10);
    // 0x80008BB8: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80008BBC: addu        $t1, $s3, $zero
    ctx->r9 = ADD32(ctx->r19, 0);
    // 0x80008BC0: addiu       $t3, $t1, -0x4
    ctx->r11 = ADD32(ctx->r9, -0X4);
    // 0x80008BC4: andi        $a2, $t0, 0xFF
    ctx->r6 = ctx->r8 & 0XFF;
L_80008BC8:
    // 0x80008BC8: addu        $a1, $t2, $a2
    ctx->r5 = ADD32(ctx->r10, ctx->r6);
    // 0x80008BCC: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x80008BD0: bne         $v1, $t5, L_80008C60
    if (ctx->r3 != ctx->r13) {
        // 0x80008BD4: addu        $v0, $s1, $a2
        ctx->r2 = ADD32(ctx->r17, ctx->r6);
            goto L_80008C60;
    }
    // 0x80008BD4: addu        $v0, $s1, $a2
    ctx->r2 = ADD32(ctx->r17, ctx->r6);
    // 0x80008BD8: sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6 << 1);
    // 0x80008BDC: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x80008BE0: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x80008BE4: lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X0);
    // 0x80008BE8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80008BEC: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80008BF0: sb          $v0, 0x32C0($at)
    MEM_B(0X32C0, ctx->r1) = ctx->r2;
    // 0x80008BF4: lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X0);
    // 0x80008BF8: lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X0);
    // 0x80008BFC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80008C00: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80008C04: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80008C08: sh          $v1, 0x3240($at)
    MEM_H(0X3240, ctx->r1) = ctx->r3;
    // 0x80008C0C: lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X0);
    // 0x80008C10: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80008C14: lhu         $v1, 0x42C0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X42C0);
    // 0x80008C18: sll         $a0, $a2, 2
    ctx->r4 = S32(ctx->r6 << 2);
    // 0x80008C1C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80008C20: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80008C24: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80008C28: sh          $v1, 0x3242($at)
    MEM_H(0X3242, ctx->r1) = ctx->r3;
    // 0x80008C2C: lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X0);
    // 0x80008C30: lw          $v1, -0x4($t1)
    ctx->r3 = MEM_W(ctx->r9, -0X4);
    // 0x80008C34: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // 0x80008C38: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80008C3C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80008C40: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80008C44: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x80008C48: addu        $v0, $s1, $a2
    ctx->r2 = ADD32(ctx->r17, ctx->r6);
    // 0x80008C4C: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x80008C50: lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X0);
    // 0x80008C54: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80008C58: j           L_80008C80
    // 0x80008C5C: sb          $v0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r2;
        goto L_80008C80;
    // 0x80008C5C: sb          $v0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r2;
L_80008C60:
    // 0x80008C60: sll         $a0, $a2, 2
    ctx->r4 = S32(ctx->r6 << 2);
    // 0x80008C64: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x80008C68: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80008C6C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80008C70: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // 0x80008C74: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80008C78: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80008C7C: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
L_80008C80:
    // 0x80008C80: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80008C84: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // 0x80008C88: sltu        $v0, $v0, $a3
    ctx->r2 = ctx->r2 < ctx->r7 ? 1 : 0;
    // 0x80008C8C: bne         $v0, $zero, L_80008BC8
    if (ctx->r2 != 0) {
        // 0x80008C90: andi        $a2, $t0, 0xFF
        ctx->r6 = ctx->r8 & 0XFF;
            goto L_80008BC8;
    }
    // 0x80008C90: andi        $a2, $t0, 0xFF
    ctx->r6 = ctx->r8 & 0XFF;
    // 0x80008C94: j           L_80008CFC
    // 0x80008C98: addu        $v0, $t4, $zero
    ctx->r2 = ADD32(ctx->r12, 0);
        goto L_80008CFC;
    // 0x80008C98: addu        $v0, $t4, $zero
    ctx->r2 = ADD32(ctx->r12, 0);
L_80008C9C:
    // 0x80008C9C: andi        $a3, $s2, 0xFF
    ctx->r7 = ctx->r18 & 0XFF;
    // 0x80008CA0: sltu        $v0, $a0, $a3
    ctx->r2 = ctx->r4 < ctx->r7 ? 1 : 0;
    // 0x80008CA4: beq         $v0, $zero, L_80008CF8
    if (ctx->r2 == 0) {
        // 0x80008CA8: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_80008CF8;
    }
    // 0x80008CA8: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80008CAC: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // 0x80008CB0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80008CB4: addiu       $t1, $t1, -0x5BB4
    ctx->r9 = ADD32(ctx->r9, -0X5BB4);
L_80008CB8:
    // 0x80008CB8: andi        $a0, $t0, 0xFF
    ctx->r4 = ctx->r8 & 0XFF;
    // 0x80008CBC: addu        $a1, $a2, $a0
    ctx->r5 = ADD32(ctx->r6, ctx->r4);
    // 0x80008CC0: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x80008CC4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80008CC8: addu        $v0, $s1, $a0
    ctx->r2 = ADD32(ctx->r17, ctx->r4);
    // 0x80008CCC: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80008CD0: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x80008CD4: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80008CD8: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80008CDC: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // 0x80008CE0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80008CE4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80008CE8: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // 0x80008CEC: sltu        $v0, $v0, $a3
    ctx->r2 = ctx->r2 < ctx->r7 ? 1 : 0;
    // 0x80008CF0: bne         $v0, $zero, L_80008CB8
    if (ctx->r2 != 0) {
        // 0x80008CF4: sw          $v1, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r3;
            goto L_80008CB8;
    }
    // 0x80008CF4: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
L_80008CF8:
    // 0x80008CF8: addu        $v0, $t4, $zero
    ctx->r2 = ADD32(ctx->r12, 0);
L_80008CFC:
    // 0x80008CFC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80008D00: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80008D04: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80008D08: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80008D0C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80008D10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80008D14: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80008D18: jr          $ra
    // 0x80008D1C: nop

    return;
    // 0x80008D1C: nop

;}
RECOMP_FUNC void emitFrameRdpInitDl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008D20: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80008D24: sb          $a0, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r4;
    // 0x80008D28: lui         $a0, 0xB900
    ctx->r4 = S32(0XB900 << 16);
    // 0x80008D2C: ori         $a0, $a0, 0x31D
    ctx->r4 = ctx->r4 | 0X31D;
    // 0x80008D30: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80008D34: lbu         $t0, -0x5794($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X5794);
    // 0x80008D38: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80008D3C: lbu         $t1, -0x5793($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X5793);
    // 0x80008D40: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80008D44: lbu         $t2, -0x5792($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X5792);
    // 0x80008D48: lui         $v1, 0xF0A
    ctx->r3 = S32(0XF0A << 16);
    // 0x80008D4C: ori         $v1, $v1, 0x4000
    ctx->r3 = ctx->r3 | 0X4000;
    // 0x80008D50: sb          $a1, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r5;
    // 0x80008D54: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80008D58: lw          $a1, -0x23A8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X23A8);
    // 0x80008D5C: lui         $v0, 0xBA00
    ctx->r2 = S32(0XBA00 << 16);
    // 0x80008D60: ori         $v0, $v0, 0x1402
    ctx->r2 = ctx->r2 | 0X1402;
    // 0x80008D64: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80008D68: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80008D6C: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80008D70: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80008D74: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80008D78: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80008D7C: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80008D80: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80008D84: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80008D88: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80008D8C: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x80008D90: lui         $v0, 0x30
    ctx->r2 = S32(0X30 << 16);
    // 0x80008D94: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x80008D98: sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    // 0x80008D9C: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // 0x80008DA0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80008DA4: lw          $v1, -0x57B4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X57B4);
    // 0x80008DA8: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x80008DAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80008DB0: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x80008DB4: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x80008DB8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80008DBC: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x80008DC0: beq         $v1, $zero, L_80008DEC
    if (ctx->r3 == 0) {
        // 0x80008DC4: lui         $v0, 0xFE00
        ctx->r2 = S32(0XFE00 << 16);
            goto L_80008DEC;
    }
    // 0x80008DC4: lui         $v0, 0xFE00
    ctx->r2 = S32(0XFE00 << 16);
    // 0x80008DC8: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x80008DCC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80008DD0: lw          $v1, -0x57B4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X57B4);
    // 0x80008DD4: addiu       $v0, $a1, 0x18
    ctx->r2 = ADD32(ctx->r5, 0X18);
    // 0x80008DD8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80008DDC: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x80008DE0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80008DE4: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80008DE8: sw          $v1, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r3;
L_80008DEC:
    // 0x80008DEC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80008DF0: lw          $v0, 0x42C4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X42C4);
    // 0x80008DF4: bne         $v0, $zero, L_80008E40
    if (ctx->r2 != 0) {
        // 0x80008DF8: addu        $s7, $v0, $zero
        ctx->r23 = ADD32(ctx->r2, 0);
            goto L_80008E40;
    }
    // 0x80008DF8: addu        $s7, $v0, $zero
    ctx->r23 = ADD32(ctx->r2, 0);
    // 0x80008DFC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80008E00: lhu         $v1, -0x56F6($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X56F6);
    // 0x80008E04: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80008E08: lhu         $a0, -0x56F4($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X56F4);
    // 0x80008E0C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80008E10: lhu         $a1, -0x56F2($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X56F2);
    // 0x80008E14: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80008E18: lhu         $a2, -0x56F0($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X56F0);
    // 0x80008E1C: addiu       $s7, $sp, 0x18
    ctx->r23 = ADD32(ctx->r29, 0X18);
    // 0x80008E20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80008E24: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80008E28: addiu       $v0, $sp, 0x10
    ctx->r2 = ADD32(ctx->r29, 0X10);
    // 0x80008E2C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80008E30: sh          $v1, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r3;
    // 0x80008E34: sh          $a0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r4;
    // 0x80008E38: sh          $a1, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r5;
    // 0x80008E3C: sh          $a2, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r6;
L_80008E40:
    // 0x80008E40: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x80008E44: lw          $a3, 0x4($s7)
    ctx->r7 = MEM_W(ctx->r23, 0X4);
    // 0x80008E48: beq         $v0, $zero, L_80009B14
    if (ctx->r2 == 0) {
        // 0x80008E4C: addu        $s6, $zero, $zero
        ctx->r22 = ADD32(0, 0);
            goto L_80009B14;
    }
    // 0x80008E4C: addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    // 0x80008E50: lui         $s0, 0xB500
    ctx->r16 = S32(0XB500 << 16);
    // 0x80008E54: andi        $a0, $t0, 0xFF
    ctx->r4 = ctx->r8 & 0XFF;
    // 0x80008E58: sll         $v1, $a0, 24
    ctx->r3 = S32(ctx->r4 << 24);
    // 0x80008E5C: andi        $a1, $t1, 0xFF
    ctx->r5 = ctx->r9 & 0XFF;
    // 0x80008E60: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80008E64: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80008E68: andi        $a2, $t2, 0xFF
    ctx->r6 = ctx->r10 & 0XFF;
    // 0x80008E6C: sll         $v0, $a2, 8
    ctx->r2 = S32(ctx->r6 << 8);
    // 0x80008E70: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80008E74: ori         $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 | 0XFF;
    // 0x80008E78: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x80008E7C: sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4 << 8);
    // 0x80008E80: andi        $a0, $a0, 0xF800
    ctx->r4 = ctx->r4 & 0XF800;
    // 0x80008E84: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x80008E88: andi        $a1, $a1, 0x7C0
    ctx->r5 = ctx->r5 & 0X7C0;
    // 0x80008E8C: or          $a0, $a0, $a1
    ctx->r4 = ctx->r4 | ctx->r5;
    // 0x80008E90: srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    // 0x80008E94: andi        $a2, $a2, 0x3E
    ctx->r6 = ctx->r6 & 0X3E;
    // 0x80008E98: or          $fp, $a0, $a2
    ctx->r30 = ctx->r4 | ctx->r6;
    // 0x80008E9C: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
L_80008EA0:
    // 0x80008EA0: lhu         $s5, 0x0($s1)
    ctx->r21 = MEM_HU(ctx->r17, 0X0);
    // 0x80008EA4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80008EA8: lhu         $v1, -0x56F6($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X56F6);
    // 0x80008EAC: sltu        $v0, $s5, $v1
    ctx->r2 = ctx->r21 < ctx->r3 ? 1 : 0;
    // 0x80008EB0: bnel        $v0, $zero, L_80008EB8
    if (ctx->r2 != 0) {
        // 0x80008EB4: addu        $s5, $v1, $zero
        ctx->r21 = ADD32(ctx->r3, 0);
            goto L_80008EB8;
    }
    goto skip_0;
    // 0x80008EB4: addu        $s5, $v1, $zero
    ctx->r21 = ADD32(ctx->r3, 0);
    skip_0:
L_80008EB8:
    // 0x80008EB8: lhu         $s4, 0x2($s1)
    ctx->r20 = MEM_HU(ctx->r17, 0X2);
    // 0x80008EBC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80008EC0: lhu         $v1, -0x56F4($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X56F4);
    // 0x80008EC4: sltu        $v0, $s4, $v1
    ctx->r2 = ctx->r20 < ctx->r3 ? 1 : 0;
    // 0x80008EC8: bnel        $v0, $zero, L_80008ED0
    if (ctx->r2 != 0) {
        // 0x80008ECC: addu        $s4, $v1, $zero
        ctx->r20 = ADD32(ctx->r3, 0);
            goto L_80008ED0;
    }
    goto skip_1;
    // 0x80008ECC: addu        $s4, $v1, $zero
    ctx->r20 = ADD32(ctx->r3, 0);
    skip_1:
L_80008ED0:
    // 0x80008ED0: lhu         $s3, 0x4($s1)
    ctx->r19 = MEM_HU(ctx->r17, 0X4);
    // 0x80008ED4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80008ED8: lhu         $v1, -0x56F2($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X56F2);
    // 0x80008EDC: sltu        $v0, $v1, $s3
    ctx->r2 = ctx->r3 < ctx->r19 ? 1 : 0;
    // 0x80008EE0: bnel        $v0, $zero, L_80008EE8
    if (ctx->r2 != 0) {
        // 0x80008EE4: addu        $s3, $v1, $zero
        ctx->r19 = ADD32(ctx->r3, 0);
            goto L_80008EE8;
    }
    goto skip_2;
    // 0x80008EE4: addu        $s3, $v1, $zero
    ctx->r19 = ADD32(ctx->r3, 0);
    skip_2:
L_80008EE8:
    // 0x80008EE8: lhu         $s2, 0x6($s1)
    ctx->r18 = MEM_HU(ctx->r17, 0X6);
    // 0x80008EEC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80008EF0: lhu         $v1, -0x56F0($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X56F0);
    // 0x80008EF4: sltu        $v0, $v1, $s2
    ctx->r2 = ctx->r3 < ctx->r18 ? 1 : 0;
    // 0x80008EF8: bnel        $v0, $zero, L_80008F00
    if (ctx->r2 != 0) {
        // 0x80008EFC: addu        $s2, $v1, $zero
        ctx->r18 = ADD32(ctx->r3, 0);
            goto L_80008F00;
    }
    goto skip_3;
    // 0x80008EFC: addu        $s2, $v1, $zero
    ctx->r18 = ADD32(ctx->r3, 0);
    skip_3:
L_80008F00:
    // 0x80008F00: lbu         $v0, 0x2F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X2F);
    // 0x80008F04: beq         $v0, $zero, L_800093B8
    if (ctx->r2 == 0) {
        // 0x80008F08: nop
    
            goto L_800093B8;
    }
    // 0x80008F08: nop

    // 0x80008F0C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80008F10: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x80008F14: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80008F18: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x80008F1C: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80008F20: bne         $v0, $zero, L_8000900C
    if (ctx->r2 != 0) {
        // 0x80008F24: nop
    
            goto L_8000900C;
    }
    // 0x80008F24: nop

    // 0x80008F28: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80008F2C: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x80008F30: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
    // 0x80008F34: bne         $a0, $zero, L_80008F94
    if (ctx->r4 != 0) {
        // 0x80008F38: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_80008F94;
    }
    // 0x80008F38: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80008F3C: jal         0x8002221C
    // 0x80008F40: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_0;
    // 0x80008F40: nop

    after_0:
    // 0x80008F44: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80008F48: beq         $a0, $zero, L_80008F8C
    if (ctx->r4 == 0) {
        // 0x80008F4C: nop
    
            goto L_80008F8C;
    }
    // 0x80008F4C: nop

    // 0x80008F50: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80008F54: beq         $v0, $zero, L_80008F6C
    if (ctx->r2 == 0) {
        // 0x80008F58: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80008F6C;
    }
    // 0x80008F58: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_80008F5C:
    // 0x80008F5C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80008F60: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80008F64: bne         $v0, $zero, L_80008F5C
    if (ctx->r2 != 0) {
        // 0x80008F68: nop
    
            goto L_80008F5C;
    }
    // 0x80008F68: nop

L_80008F6C:
    // 0x80008F6C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80008F70: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80008F74: beq         $v0, $zero, L_80008F80
    if (ctx->r2 == 0) {
        // 0x80008F78: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80008F80;
    }
    // 0x80008F78: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80008F7C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_80008F80:
    // 0x80008F80: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80008F84: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x80008F88: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_80008F8C:
    // 0x80008F8C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80008F90: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_80008F94:
    // 0x80008F94: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80008F98: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80008F9C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80008FA0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80008FA4: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x80008FA8: bnel        $v0, $zero, L_80008FB0
    if (ctx->r2 != 0) {
        // 0x80008FAC: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_80008FB0;
    }
    goto skip_4;
    // 0x80008FAC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_4:
L_80008FB0:
    // 0x80008FB0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80008FB4: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x80008FB8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80008FBC: bne         $v0, $zero, L_80008FCC
    if (ctx->r2 != 0) {
        // 0x80008FC0: nop
    
            goto L_80008FCC;
    }
    // 0x80008FC0: nop

    // 0x80008FC4: j           L_80008FE4
    // 0x80008FC8: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_80008FE4;
    // 0x80008FC8: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_80008FCC:
    // 0x80008FCC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80008FD0: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x80008FD4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80008FD8: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80008FDC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80008FE0: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_80008FE4:
    // 0x80008FE4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80008FE8: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x80008FEC: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80008FF0: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80008FF4: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x80008FF8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80008FFC: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x80009000: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80009004: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80009008: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_8000900C:
    // 0x8000900C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80009010: lw          $a1, -0x23A8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X23A8);
    // 0x80009014: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80009018: lw          $a0, 0x63D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63D4);
    // 0x8000901C: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x80009020: addiu       $v1, $a1, 0x8
    ctx->r3 = ADD32(ctx->r5, 0X8);
    // 0x80009024: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80009028: sw          $v1, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r3;
    // 0x8000902C: sltu        $v1, $v1, $a0
    ctx->r3 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x80009030: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80009034: bne         $v1, $zero, L_80009120
    if (ctx->r3 != 0) {
        // 0x80009038: sw          $zero, 0x4($a1)
        MEM_W(0X4, ctx->r5) = 0;
            goto L_80009120;
    }
    // 0x80009038: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8000903C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80009040: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x80009044: sw          $s0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r16;
    // 0x80009048: bne         $a0, $zero, L_800090A8
    if (ctx->r4 != 0) {
        // 0x8000904C: sw          $zero, 0xC($a1)
        MEM_W(0XC, ctx->r5) = 0;
            goto L_800090A8;
    }
    // 0x8000904C: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x80009050: jal         0x8002221C
    // 0x80009054: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_1;
    // 0x80009054: nop

    after_1:
    // 0x80009058: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000905C: beq         $a0, $zero, L_800090A0
    if (ctx->r4 == 0) {
        // 0x80009060: nop
    
            goto L_800090A0;
    }
    // 0x80009060: nop

    // 0x80009064: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80009068: beq         $v0, $zero, L_80009080
    if (ctx->r2 == 0) {
        // 0x8000906C: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80009080;
    }
    // 0x8000906C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_80009070:
    // 0x80009070: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80009074: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80009078: bne         $v0, $zero, L_80009070
    if (ctx->r2 != 0) {
        // 0x8000907C: nop
    
            goto L_80009070;
    }
    // 0x8000907C: nop

L_80009080:
    // 0x80009080: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80009084: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80009088: beq         $v0, $zero, L_80009094
    if (ctx->r2 == 0) {
        // 0x8000908C: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80009094;
    }
    // 0x8000908C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80009090: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_80009094:
    // 0x80009094: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009098: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000909C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_800090A0:
    // 0x800090A0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800090A4: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_800090A8:
    // 0x800090A8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800090AC: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x800090B0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800090B4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800090B8: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x800090BC: bnel        $v0, $zero, L_800090C4
    if (ctx->r2 != 0) {
        // 0x800090C0: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_800090C4;
    }
    goto skip_5;
    // 0x800090C0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_5:
L_800090C4:
    // 0x800090C4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800090C8: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x800090CC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800090D0: bne         $v0, $zero, L_800090E0
    if (ctx->r2 != 0) {
        // 0x800090D4: nop
    
            goto L_800090E0;
    }
    // 0x800090D4: nop

    // 0x800090D8: j           L_800090F8
    // 0x800090DC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_800090F8;
    // 0x800090DC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_800090E0:
    // 0x800090E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800090E4: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x800090E8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800090EC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x800090F0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800090F4: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_800090F8:
    // 0x800090F8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800090FC: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x80009100: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80009104: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80009108: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000910C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009110: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x80009114: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80009118: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000911C: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_80009120:
    // 0x80009120: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80009124: lw          $v0, -0x57C8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X57C8);
    // 0x80009128: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000912C: lw          $a1, -0x23A8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X23A8);
    // 0x80009130: lui         $v1, 0xFF10
    ctx->r3 = S32(0XFF10 << 16);
    // 0x80009134: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80009138: lw          $a0, 0x63D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63D4);
    // 0x8000913C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80009140: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80009144: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80009148: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8000914C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80009150: lw          $v1, -0x57B4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X57B4);
    // 0x80009154: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x80009158: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000915C: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x80009160: sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80009164: bne         $v0, $zero, L_80009250
    if (ctx->r2 != 0) {
        // 0x80009168: sw          $v1, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->r3;
            goto L_80009250;
    }
    // 0x80009168: sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    // 0x8000916C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80009170: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x80009174: sw          $s0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r16;
    // 0x80009178: bne         $a0, $zero, L_800091D8
    if (ctx->r4 != 0) {
        // 0x8000917C: sw          $zero, 0xC($a1)
        MEM_W(0XC, ctx->r5) = 0;
            goto L_800091D8;
    }
    // 0x8000917C: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x80009180: jal         0x8002221C
    // 0x80009184: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_2;
    // 0x80009184: nop

    after_2:
    // 0x80009188: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000918C: beq         $a0, $zero, L_800091D0
    if (ctx->r4 == 0) {
        // 0x80009190: nop
    
            goto L_800091D0;
    }
    // 0x80009190: nop

    // 0x80009194: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80009198: beq         $v0, $zero, L_800091B0
    if (ctx->r2 == 0) {
        // 0x8000919C: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_800091B0;
    }
    // 0x8000919C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_800091A0:
    // 0x800091A0: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800091A4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800091A8: bne         $v0, $zero, L_800091A0
    if (ctx->r2 != 0) {
        // 0x800091AC: nop
    
            goto L_800091A0;
    }
    // 0x800091AC: nop

L_800091B0:
    // 0x800091B0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800091B4: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x800091B8: beq         $v0, $zero, L_800091C4
    if (ctx->r2 == 0) {
        // 0x800091BC: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800091C4;
    }
    // 0x800091BC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800091C0: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_800091C4:
    // 0x800091C4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800091C8: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x800091CC: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_800091D0:
    // 0x800091D0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800091D4: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_800091D8:
    // 0x800091D8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800091DC: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x800091E0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800091E4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800091E8: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x800091EC: bnel        $v0, $zero, L_800091F4
    if (ctx->r2 != 0) {
        // 0x800091F0: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_800091F4;
    }
    goto skip_6;
    // 0x800091F0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_6:
L_800091F4:
    // 0x800091F4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800091F8: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x800091FC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80009200: bne         $v0, $zero, L_80009210
    if (ctx->r2 != 0) {
        // 0x80009204: nop
    
            goto L_80009210;
    }
    // 0x80009204: nop

    // 0x80009208: j           L_80009228
    // 0x8000920C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_80009228;
    // 0x8000920C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_80009210:
    // 0x80009210: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80009214: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x80009218: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000921C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80009220: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80009224: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_80009228:
    // 0x80009228: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000922C: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x80009230: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80009234: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80009238: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000923C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009240: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x80009244: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80009248: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000924C: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_80009250:
    // 0x80009250: lui         $a1, 0xFFFC
    ctx->r5 = S32(0XFFFC << 16);
    // 0x80009254: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80009258: lw          $a2, -0x23A8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X23A8);
    // 0x8000925C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80009260: lw          $a0, 0x63D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63D4);
    // 0x80009264: ori         $a1, $a1, 0xFFFC
    ctx->r5 = ctx->r5 | 0XFFFC;
    // 0x80009268: lui         $v0, 0xF700
    ctx->r2 = S32(0XF700 << 16);
    // 0x8000926C: addiu       $v1, $a2, 0x8
    ctx->r3 = ADD32(ctx->r6, 0X8);
    // 0x80009270: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80009274: sw          $v1, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r3;
    // 0x80009278: sltu        $v1, $v1, $a0
    ctx->r3 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x8000927C: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80009280: bne         $v1, $zero, L_8000936C
    if (ctx->r3 != 0) {
        // 0x80009284: sw          $a1, 0x4($a2)
        MEM_W(0X4, ctx->r6) = ctx->r5;
            goto L_8000936C;
    }
    // 0x80009284: sw          $a1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r5;
    // 0x80009288: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000928C: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x80009290: sw          $s0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r16;
    // 0x80009294: bne         $a0, $zero, L_800092F4
    if (ctx->r4 != 0) {
        // 0x80009298: sw          $zero, 0xC($a2)
        MEM_W(0XC, ctx->r6) = 0;
            goto L_800092F4;
    }
    // 0x80009298: sw          $zero, 0xC($a2)
    MEM_W(0XC, ctx->r6) = 0;
    // 0x8000929C: jal         0x8002221C
    // 0x800092A0: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_3;
    // 0x800092A0: nop

    after_3:
    // 0x800092A4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800092A8: beq         $a0, $zero, L_800092EC
    if (ctx->r4 == 0) {
        // 0x800092AC: nop
    
            goto L_800092EC;
    }
    // 0x800092AC: nop

    // 0x800092B0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800092B4: beq         $v0, $zero, L_800092CC
    if (ctx->r2 == 0) {
        // 0x800092B8: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_800092CC;
    }
    // 0x800092B8: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_800092BC:
    // 0x800092BC: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800092C0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800092C4: bne         $v0, $zero, L_800092BC
    if (ctx->r2 != 0) {
        // 0x800092C8: nop
    
            goto L_800092BC;
    }
    // 0x800092C8: nop

L_800092CC:
    // 0x800092CC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800092D0: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x800092D4: beq         $v0, $zero, L_800092E0
    if (ctx->r2 == 0) {
        // 0x800092D8: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800092E0;
    }
    // 0x800092D8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800092DC: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_800092E0:
    // 0x800092E0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800092E4: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x800092E8: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_800092EC:
    // 0x800092EC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800092F0: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_800092F4:
    // 0x800092F4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800092F8: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x800092FC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80009300: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009304: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x80009308: bnel        $v0, $zero, L_80009310
    if (ctx->r2 != 0) {
        // 0x8000930C: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_80009310;
    }
    goto skip_7;
    // 0x8000930C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_7:
L_80009310:
    // 0x80009310: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80009314: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x80009318: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000931C: bne         $v0, $zero, L_8000932C
    if (ctx->r2 != 0) {
        // 0x80009320: nop
    
            goto L_8000932C;
    }
    // 0x80009320: nop

    // 0x80009324: j           L_80009344
    // 0x80009328: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_80009344;
    // 0x80009328: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000932C:
    // 0x8000932C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80009330: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x80009334: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80009338: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000933C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80009340: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_80009344:
    // 0x80009344: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80009348: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000934C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80009350: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80009354: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x80009358: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000935C: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x80009360: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80009364: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80009368: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_8000936C:
    // 0x8000936C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80009370: lw          $a1, -0x23A8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X23A8);
    // 0x80009374: andi        $a0, $s3, 0x3FF
    ctx->r4 = ctx->r19 & 0X3FF;
    // 0x80009378: sll         $a0, $a0, 14
    ctx->r4 = S32(ctx->r4 << 14);
    // 0x8000937C: lui         $v1, 0xF600
    ctx->r3 = S32(0XF600 << 16);
    // 0x80009380: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x80009384: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80009388: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x8000938C: andi        $v0, $s2, 0x3FF
    ctx->r2 = ctx->r18 & 0X3FF;
    // 0x80009390: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80009394: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80009398: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x8000939C: andi        $v1, $s5, 0x3FF
    ctx->r3 = ctx->r21 & 0X3FF;
    // 0x800093A0: sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3 << 14);
    // 0x800093A4: andi        $v0, $s4, 0x3FF
    ctx->r2 = ctx->r20 & 0X3FF;
    // 0x800093A8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800093AC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800093B0: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x800093B4: sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
L_800093B8:
    // 0x800093B8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800093BC: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x800093C0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800093C4: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x800093C8: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x800093CC: bne         $v0, $zero, L_800094B8
    if (ctx->r2 != 0) {
        // 0x800093D0: nop
    
            goto L_800094B8;
    }
    // 0x800093D0: nop

    // 0x800093D4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800093D8: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x800093DC: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
    // 0x800093E0: bne         $a0, $zero, L_80009440
    if (ctx->r4 != 0) {
        // 0x800093E4: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_80009440;
    }
    // 0x800093E4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800093E8: jal         0x8002221C
    // 0x800093EC: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_4;
    // 0x800093EC: nop

    after_4:
    // 0x800093F0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800093F4: beq         $a0, $zero, L_80009438
    if (ctx->r4 == 0) {
        // 0x800093F8: nop
    
            goto L_80009438;
    }
    // 0x800093F8: nop

    // 0x800093FC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80009400: beq         $v0, $zero, L_80009418
    if (ctx->r2 == 0) {
        // 0x80009404: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80009418;
    }
    // 0x80009404: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_80009408:
    // 0x80009408: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000940C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80009410: bne         $v0, $zero, L_80009408
    if (ctx->r2 != 0) {
        // 0x80009414: nop
    
            goto L_80009408;
    }
    // 0x80009414: nop

L_80009418:
    // 0x80009418: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000941C: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80009420: beq         $v0, $zero, L_8000942C
    if (ctx->r2 == 0) {
        // 0x80009424: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000942C;
    }
    // 0x80009424: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80009428: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000942C:
    // 0x8000942C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009430: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x80009434: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_80009438:
    // 0x80009438: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000943C: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_80009440:
    // 0x80009440: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80009444: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80009448: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000944C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009450: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x80009454: bnel        $v0, $zero, L_8000945C
    if (ctx->r2 != 0) {
        // 0x80009458: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000945C;
    }
    goto skip_8;
    // 0x80009458: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_8:
L_8000945C:
    // 0x8000945C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80009460: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x80009464: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80009468: bne         $v0, $zero, L_80009478
    if (ctx->r2 != 0) {
        // 0x8000946C: nop
    
            goto L_80009478;
    }
    // 0x8000946C: nop

    // 0x80009470: j           L_80009490
    // 0x80009474: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_80009490;
    // 0x80009474: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_80009478:
    // 0x80009478: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000947C: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x80009480: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80009484: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80009488: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000948C: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_80009490:
    // 0x80009490: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80009494: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x80009498: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000949C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800094A0: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x800094A4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800094A8: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x800094AC: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x800094B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800094B4: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_800094B8:
    // 0x800094B8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800094BC: lw          $a1, -0x23A8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X23A8);
    // 0x800094C0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800094C4: lhu         $v1, -0x202A($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X202A);
    // 0x800094C8: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x800094CC: addiu       $a0, $a1, 0x8
    ctx->r4 = ADD32(ctx->r5, 0X8);
    // 0x800094D0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800094D4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800094D8: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800094DC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800094E0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800094E4: sw          $a0, -0x1FF0($at)
    MEM_W(-0X1FF0, ctx->r1) = ctx->r4;
    // 0x800094E8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800094EC: lh          $v0, -0x57B8($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X57B8);
    // 0x800094F0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800094F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800094F8: sw          $a0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r4;
    // 0x800094FC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009500: sh          $v1, -0x202A($at)
    MEM_H(-0X202A, ctx->r1) = ctx->r3;
    // 0x80009504: slti        $v0, $v0, 0x18
    ctx->r2 = SIGNED(ctx->r2) < 0X18 ? 1 : 0;
    // 0x80009508: bne         $v0, $zero, L_80009758
    if (ctx->r2 != 0) {
        // 0x8000950C: nop
    
            goto L_80009758;
    }
    // 0x8000950C: nop

    // 0x80009510: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80009514: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x80009518: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8000951C: bne         $v0, $zero, L_80009608
    if (ctx->r2 != 0) {
        // 0x80009520: nop
    
            goto L_80009608;
    }
    // 0x80009520: nop

    // 0x80009524: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80009528: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000952C: sw          $s0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r16;
    // 0x80009530: bne         $a0, $zero, L_80009590
    if (ctx->r4 != 0) {
        // 0x80009534: sw          $zero, 0xC($a1)
        MEM_W(0XC, ctx->r5) = 0;
            goto L_80009590;
    }
    // 0x80009534: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x80009538: jal         0x8002221C
    // 0x8000953C: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_5;
    // 0x8000953C: nop

    after_5:
    // 0x80009540: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80009544: beq         $a0, $zero, L_80009588
    if (ctx->r4 == 0) {
        // 0x80009548: nop
    
            goto L_80009588;
    }
    // 0x80009548: nop

    // 0x8000954C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80009550: beq         $v0, $zero, L_80009568
    if (ctx->r2 == 0) {
        // 0x80009554: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80009568;
    }
    // 0x80009554: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_80009558:
    // 0x80009558: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000955C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80009560: bne         $v0, $zero, L_80009558
    if (ctx->r2 != 0) {
        // 0x80009564: nop
    
            goto L_80009558;
    }
    // 0x80009564: nop

L_80009568:
    // 0x80009568: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000956C: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80009570: beq         $v0, $zero, L_8000957C
    if (ctx->r2 == 0) {
        // 0x80009574: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000957C;
    }
    // 0x80009574: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80009578: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000957C:
    // 0x8000957C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009580: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x80009584: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_80009588:
    // 0x80009588: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000958C: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_80009590:
    // 0x80009590: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80009594: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80009598: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000959C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800095A0: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x800095A4: bnel        $v0, $zero, L_800095AC
    if (ctx->r2 != 0) {
        // 0x800095A8: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_800095AC;
    }
    goto skip_9;
    // 0x800095A8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_9:
L_800095AC:
    // 0x800095AC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800095B0: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x800095B4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800095B8: bne         $v0, $zero, L_800095C8
    if (ctx->r2 != 0) {
        // 0x800095BC: nop
    
            goto L_800095C8;
    }
    // 0x800095BC: nop

    // 0x800095C0: j           L_800095E0
    // 0x800095C4: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_800095E0;
    // 0x800095C4: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_800095C8:
    // 0x800095C8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800095CC: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x800095D0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800095D4: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x800095D8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800095DC: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_800095E0:
    // 0x800095E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800095E4: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x800095E8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800095EC: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800095F0: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x800095F4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800095F8: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x800095FC: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80009600: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80009604: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_80009608:
    // 0x80009608: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000960C: lw          $a2, -0x23A8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X23A8);
    // 0x80009610: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80009614: lw          $v0, -0x57C8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X57C8);
    // 0x80009618: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8000961C: lw          $a1, 0x63D4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X63D4);
    // 0x80009620: lui         $v1, 0xFF18
    ctx->r3 = S32(0XFF18 << 16);
    // 0x80009624: addiu       $a0, $a2, 0x8
    ctx->r4 = ADD32(ctx->r6, 0X8);
    // 0x80009628: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000962C: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80009630: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80009634: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80009638: sw          $a0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r4;
    // 0x8000963C: sltu        $a0, $a0, $a1
    ctx->r4 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x80009640: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80009644: bne         $a0, $zero, L_80009730
    if (ctx->r4 != 0) {
        // 0x80009648: sw          $zero, 0x4($a2)
        MEM_W(0X4, ctx->r6) = 0;
            goto L_80009730;
    }
    // 0x80009648: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x8000964C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80009650: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x80009654: sw          $s0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r16;
    // 0x80009658: bne         $a0, $zero, L_800096B8
    if (ctx->r4 != 0) {
        // 0x8000965C: sw          $zero, 0xC($a2)
        MEM_W(0XC, ctx->r6) = 0;
            goto L_800096B8;
    }
    // 0x8000965C: sw          $zero, 0xC($a2)
    MEM_W(0XC, ctx->r6) = 0;
    // 0x80009660: jal         0x8002221C
    // 0x80009664: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_6;
    // 0x80009664: nop

    after_6:
    // 0x80009668: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000966C: beq         $a0, $zero, L_800096B0
    if (ctx->r4 == 0) {
        // 0x80009670: nop
    
            goto L_800096B0;
    }
    // 0x80009670: nop

    // 0x80009674: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80009678: beq         $v0, $zero, L_80009690
    if (ctx->r2 == 0) {
        // 0x8000967C: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80009690;
    }
    // 0x8000967C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_80009680:
    // 0x80009680: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80009684: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80009688: bne         $v0, $zero, L_80009680
    if (ctx->r2 != 0) {
        // 0x8000968C: nop
    
            goto L_80009680;
    }
    // 0x8000968C: nop

L_80009690:
    // 0x80009690: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80009694: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80009698: beq         $v0, $zero, L_800096A4
    if (ctx->r2 == 0) {
        // 0x8000969C: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800096A4;
    }
    // 0x8000969C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800096A0: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_800096A4:
    // 0x800096A4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800096A8: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x800096AC: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_800096B0:
    // 0x800096B0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800096B4: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_800096B8:
    // 0x800096B8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800096BC: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x800096C0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800096C4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800096C8: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x800096CC: bnel        $v0, $zero, L_800096D4
    if (ctx->r2 != 0) {
        // 0x800096D0: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_800096D4;
    }
    goto skip_10;
    // 0x800096D0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_10:
L_800096D4:
    // 0x800096D4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800096D8: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x800096DC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800096E0: bne         $v0, $zero, L_800096F0
    if (ctx->r2 != 0) {
        // 0x800096E4: nop
    
            goto L_800096F0;
    }
    // 0x800096E4: nop

    // 0x800096E8: j           L_80009708
    // 0x800096EC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_80009708;
    // 0x800096EC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_800096F0:
    // 0x800096F0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800096F4: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x800096F8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800096FC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80009700: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80009704: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_80009708:
    // 0x80009708: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000970C: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x80009710: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80009714: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80009718: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000971C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009720: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x80009724: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80009728: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000972C: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_80009730:
    // 0x80009730: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80009734: lw          $v0, -0x23A8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X23A8);
    // 0x80009738: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x8000973C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80009740: sw          $v1, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r3;
    // 0x80009744: lui         $v1, 0xF700
    ctx->r3 = S32(0XF700 << 16);
    // 0x80009748: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8000974C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80009750: j           L_800099A8
    // 0x80009754: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
        goto L_800099A8;
    // 0x80009754: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
L_80009758:
    // 0x80009758: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000975C: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x80009760: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80009764: bne         $v0, $zero, L_80009850
    if (ctx->r2 != 0) {
        // 0x80009768: nop
    
            goto L_80009850;
    }
    // 0x80009768: nop

    // 0x8000976C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80009770: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x80009774: sw          $s0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r16;
    // 0x80009778: bne         $a0, $zero, L_800097D8
    if (ctx->r4 != 0) {
        // 0x8000977C: sw          $zero, 0xC($a1)
        MEM_W(0XC, ctx->r5) = 0;
            goto L_800097D8;
    }
    // 0x8000977C: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x80009780: jal         0x8002221C
    // 0x80009784: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_7;
    // 0x80009784: nop

    after_7:
    // 0x80009788: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000978C: beq         $a0, $zero, L_800097D0
    if (ctx->r4 == 0) {
        // 0x80009790: nop
    
            goto L_800097D0;
    }
    // 0x80009790: nop

    // 0x80009794: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80009798: beq         $v0, $zero, L_800097B0
    if (ctx->r2 == 0) {
        // 0x8000979C: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_800097B0;
    }
    // 0x8000979C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_800097A0:
    // 0x800097A0: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800097A4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800097A8: bne         $v0, $zero, L_800097A0
    if (ctx->r2 != 0) {
        // 0x800097AC: nop
    
            goto L_800097A0;
    }
    // 0x800097AC: nop

L_800097B0:
    // 0x800097B0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800097B4: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x800097B8: beq         $v0, $zero, L_800097C4
    if (ctx->r2 == 0) {
        // 0x800097BC: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800097C4;
    }
    // 0x800097BC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800097C0: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_800097C4:
    // 0x800097C4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800097C8: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x800097CC: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_800097D0:
    // 0x800097D0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800097D4: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_800097D8:
    // 0x800097D8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800097DC: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x800097E0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800097E4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800097E8: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x800097EC: bnel        $v0, $zero, L_800097F4
    if (ctx->r2 != 0) {
        // 0x800097F0: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_800097F4;
    }
    goto skip_11;
    // 0x800097F0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_11:
L_800097F4:
    // 0x800097F4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800097F8: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x800097FC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80009800: bne         $v0, $zero, L_80009810
    if (ctx->r2 != 0) {
        // 0x80009804: nop
    
            goto L_80009810;
    }
    // 0x80009804: nop

    // 0x80009808: j           L_80009828
    // 0x8000980C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_80009828;
    // 0x8000980C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_80009810:
    // 0x80009810: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80009814: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x80009818: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000981C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80009820: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80009824: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_80009828:
    // 0x80009828: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000982C: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x80009830: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80009834: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80009838: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000983C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009840: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x80009844: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80009848: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000984C: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_80009850:
    // 0x80009850: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80009854: lw          $a2, -0x23A8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X23A8);
    // 0x80009858: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000985C: lw          $v0, -0x57C8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X57C8);
    // 0x80009860: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80009864: lw          $a1, 0x63D4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X63D4);
    // 0x80009868: lui         $v1, 0xFF10
    ctx->r3 = S32(0XFF10 << 16);
    // 0x8000986C: addiu       $a0, $a2, 0x8
    ctx->r4 = ADD32(ctx->r6, 0X8);
    // 0x80009870: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80009874: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80009878: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8000987C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80009880: sw          $a0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r4;
    // 0x80009884: sltu        $a0, $a0, $a1
    ctx->r4 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x80009888: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x8000988C: bne         $a0, $zero, L_80009978
    if (ctx->r4 != 0) {
        // 0x80009890: sw          $zero, 0x4($a2)
        MEM_W(0X4, ctx->r6) = 0;
            goto L_80009978;
    }
    // 0x80009890: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x80009894: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80009898: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000989C: sw          $s0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r16;
    // 0x800098A0: bne         $a0, $zero, L_80009900
    if (ctx->r4 != 0) {
        // 0x800098A4: sw          $zero, 0xC($a2)
        MEM_W(0XC, ctx->r6) = 0;
            goto L_80009900;
    }
    // 0x800098A4: sw          $zero, 0xC($a2)
    MEM_W(0XC, ctx->r6) = 0;
    // 0x800098A8: jal         0x8002221C
    // 0x800098AC: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_8;
    // 0x800098AC: nop

    after_8:
    // 0x800098B0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800098B4: beq         $a0, $zero, L_800098F8
    if (ctx->r4 == 0) {
        // 0x800098B8: nop
    
            goto L_800098F8;
    }
    // 0x800098B8: nop

    // 0x800098BC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800098C0: beq         $v0, $zero, L_800098D8
    if (ctx->r2 == 0) {
        // 0x800098C4: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_800098D8;
    }
    // 0x800098C4: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_800098C8:
    // 0x800098C8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800098CC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800098D0: bne         $v0, $zero, L_800098C8
    if (ctx->r2 != 0) {
        // 0x800098D4: nop
    
            goto L_800098C8;
    }
    // 0x800098D4: nop

L_800098D8:
    // 0x800098D8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800098DC: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x800098E0: beq         $v0, $zero, L_800098EC
    if (ctx->r2 == 0) {
        // 0x800098E4: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800098EC;
    }
    // 0x800098E4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800098E8: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_800098EC:
    // 0x800098EC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800098F0: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x800098F4: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_800098F8:
    // 0x800098F8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800098FC: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_80009900:
    // 0x80009900: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80009904: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80009908: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000990C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009910: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x80009914: bnel        $v0, $zero, L_8000991C
    if (ctx->r2 != 0) {
        // 0x80009918: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000991C;
    }
    goto skip_12;
    // 0x80009918: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_12:
L_8000991C:
    // 0x8000991C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80009920: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x80009924: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80009928: bne         $v0, $zero, L_80009938
    if (ctx->r2 != 0) {
        // 0x8000992C: nop
    
            goto L_80009938;
    }
    // 0x8000992C: nop

    // 0x80009930: j           L_80009950
    // 0x80009934: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_80009950;
    // 0x80009934: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_80009938:
    // 0x80009938: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000993C: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x80009940: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80009944: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80009948: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000994C: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_80009950:
    // 0x80009950: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80009954: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x80009958: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000995C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80009960: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x80009964: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009968: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000996C: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80009970: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80009974: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_80009978:
    // 0x80009978: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000997C: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x80009980: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80009984: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80009988: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x8000998C: lui         $v0, 0xF700
    ctx->r2 = S32(0XF700 << 16);
    // 0x80009990: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80009994: ori         $v0, $fp, 0x1
    ctx->r2 = ctx->r30 | 0X1;
    // 0x80009998: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000999C: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x800099A0: or          $v0, $v0, $fp
    ctx->r2 = ctx->r2 | ctx->r30;
    // 0x800099A4: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800099A8:
    // 0x800099A8: lbu         $v0, 0x27($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X27);
    // 0x800099AC: beq         $v0, $zero, L_80009B00
    if (ctx->r2 == 0) {
        // 0x800099B0: nop
    
            goto L_80009B00;
    }
    // 0x800099B0: nop

    // 0x800099B4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800099B8: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x800099BC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800099C0: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x800099C4: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x800099C8: bne         $v0, $zero, L_80009AB4
    if (ctx->r2 != 0) {
        // 0x800099CC: nop
    
            goto L_80009AB4;
    }
    // 0x800099CC: nop

    // 0x800099D0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800099D4: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x800099D8: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
    // 0x800099DC: bne         $a0, $zero, L_80009A3C
    if (ctx->r4 != 0) {
        // 0x800099E0: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_80009A3C;
    }
    // 0x800099E0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800099E4: jal         0x8002221C
    // 0x800099E8: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_9;
    // 0x800099E8: nop

    after_9:
    // 0x800099EC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800099F0: beq         $a0, $zero, L_80009A34
    if (ctx->r4 == 0) {
        // 0x800099F4: nop
    
            goto L_80009A34;
    }
    // 0x800099F4: nop

    // 0x800099F8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800099FC: beq         $v0, $zero, L_80009A14
    if (ctx->r2 == 0) {
        // 0x80009A00: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80009A14;
    }
    // 0x80009A00: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_80009A04:
    // 0x80009A04: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80009A08: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80009A0C: bne         $v0, $zero, L_80009A04
    if (ctx->r2 != 0) {
        // 0x80009A10: nop
    
            goto L_80009A04;
    }
    // 0x80009A10: nop

L_80009A14:
    // 0x80009A14: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80009A18: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80009A1C: beq         $v0, $zero, L_80009A28
    if (ctx->r2 == 0) {
        // 0x80009A20: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80009A28;
    }
    // 0x80009A20: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80009A24: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_80009A28:
    // 0x80009A28: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009A2C: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x80009A30: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_80009A34:
    // 0x80009A34: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80009A38: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_80009A3C:
    // 0x80009A3C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80009A40: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80009A44: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80009A48: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009A4C: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x80009A50: bnel        $v0, $zero, L_80009A58
    if (ctx->r2 != 0) {
        // 0x80009A54: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_80009A58;
    }
    goto skip_13;
    // 0x80009A54: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_13:
L_80009A58:
    // 0x80009A58: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80009A5C: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x80009A60: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80009A64: bne         $v0, $zero, L_80009A74
    if (ctx->r2 != 0) {
        // 0x80009A68: nop
    
            goto L_80009A74;
    }
    // 0x80009A68: nop

    // 0x80009A6C: j           L_80009A8C
    // 0x80009A70: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_80009A8C;
    // 0x80009A70: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_80009A74:
    // 0x80009A74: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80009A78: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x80009A7C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80009A80: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80009A84: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80009A88: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_80009A8C:
    // 0x80009A8C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80009A90: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x80009A94: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80009A98: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80009A9C: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x80009AA0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009AA4: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x80009AA8: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80009AAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80009AB0: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_80009AB4:
    // 0x80009AB4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80009AB8: lw          $a1, -0x23A8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X23A8);
    // 0x80009ABC: andi        $a0, $s3, 0x3FF
    ctx->r4 = ctx->r19 & 0X3FF;
    // 0x80009AC0: sll         $a0, $a0, 14
    ctx->r4 = S32(ctx->r4 << 14);
    // 0x80009AC4: lui         $v1, 0xF600
    ctx->r3 = S32(0XF600 << 16);
    // 0x80009AC8: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x80009ACC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80009AD0: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x80009AD4: andi        $v0, $s2, 0x3FF
    ctx->r2 = ctx->r18 & 0X3FF;
    // 0x80009AD8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80009ADC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80009AE0: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x80009AE4: andi        $v1, $s5, 0x3FF
    ctx->r3 = ctx->r21 & 0X3FF;
    // 0x80009AE8: sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3 << 14);
    // 0x80009AEC: andi        $v0, $s4, 0x3FF
    ctx->r2 = ctx->r20 & 0X3FF;
    // 0x80009AF0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80009AF4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80009AF8: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x80009AFC: sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
L_80009B00:
    // 0x80009B00: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x80009B04: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80009B08: sltu        $v0, $s6, $v0
    ctx->r2 = ctx->r22 < ctx->r2 ? 1 : 0;
    // 0x80009B0C: bne         $v0, $zero, L_80008EA0
    if (ctx->r2 != 0) {
        // 0x80009B10: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_80008EA0;
    }
    // 0x80009B10: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
L_80009B14:
    // 0x80009B14: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80009B18: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x80009B1C: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x80009B20: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80009B24: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x80009B28: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80009B2C: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80009B30: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80009B34: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80009B38: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80009B3C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80009B40: jr          $ra
    // 0x80009B44: nop

    return;
    // 0x80009B44: nop

;}
RECOMP_FUNC void func_80009B48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009B48: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009B4C: sw          $a0, 0x42C4($at)
    MEM_W(0X42C4, ctx->r1) = ctx->r4;
    // 0x80009B50: jr          $ra
    // 0x80009B54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80009B54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80009B58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009B58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80009B5C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80009B60: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80009B64: lbu         $s0, -0x5778($s0)
    ctx->r16 = MEM_BU(ctx->r16, -0X5778);
    // 0x80009B68: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80009B6C: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x80009B70: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80009B74: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x80009B78: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80009B7C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80009B80: lbu         $s1, -0x5777($s1)
    ctx->r17 = MEM_BU(ctx->r17, -0X5777);
    // 0x80009B84: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80009B88: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80009B8C: lbu         $s2, -0x5776($s2)
    ctx->r18 = MEM_BU(ctx->r18, -0X5776);
    // 0x80009B90: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80009B94: bne         $v0, $zero, L_80009C84
    if (ctx->r2 != 0) {
        // 0x80009B98: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80009C84;
    }
    // 0x80009B98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80009B9C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80009BA0: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x80009BA4: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80009BA8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80009BAC: bne         $a0, $zero, L_80009C0C
    if (ctx->r4 != 0) {
        // 0x80009BB0: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_80009C0C;
    }
    // 0x80009BB0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80009BB4: jal         0x8002221C
    // 0x80009BB8: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_0;
    // 0x80009BB8: nop

    after_0:
    // 0x80009BBC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80009BC0: beq         $a0, $zero, L_80009C04
    if (ctx->r4 == 0) {
        // 0x80009BC4: nop
    
            goto L_80009C04;
    }
    // 0x80009BC4: nop

    // 0x80009BC8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80009BCC: beq         $v0, $zero, L_80009BE4
    if (ctx->r2 == 0) {
        // 0x80009BD0: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80009BE4;
    }
    // 0x80009BD0: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_80009BD4:
    // 0x80009BD4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80009BD8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80009BDC: bne         $v0, $zero, L_80009BD4
    if (ctx->r2 != 0) {
        // 0x80009BE0: nop
    
            goto L_80009BD4;
    }
    // 0x80009BE0: nop

L_80009BE4:
    // 0x80009BE4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80009BE8: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80009BEC: beq         $v0, $zero, L_80009BF8
    if (ctx->r2 == 0) {
        // 0x80009BF0: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80009BF8;
    }
    // 0x80009BF0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80009BF4: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_80009BF8:
    // 0x80009BF8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009BFC: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x80009C00: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_80009C04:
    // 0x80009C04: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80009C08: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_80009C0C:
    // 0x80009C0C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80009C10: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80009C14: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80009C18: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009C1C: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x80009C20: bnel        $v0, $zero, L_80009C28
    if (ctx->r2 != 0) {
        // 0x80009C24: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_80009C28;
    }
    goto skip_0;
    // 0x80009C24: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_0:
L_80009C28:
    // 0x80009C28: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80009C2C: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x80009C30: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80009C34: bne         $v0, $zero, L_80009C44
    if (ctx->r2 != 0) {
        // 0x80009C38: nop
    
            goto L_80009C44;
    }
    // 0x80009C38: nop

    // 0x80009C3C: j           L_80009C5C
    // 0x80009C40: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_80009C5C;
    // 0x80009C40: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_80009C44:
    // 0x80009C44: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80009C48: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x80009C4C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80009C50: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80009C54: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80009C58: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_80009C5C:
    // 0x80009C5C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80009C60: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x80009C64: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80009C68: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80009C6C: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x80009C70: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009C74: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x80009C78: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80009C7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80009C80: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_80009C84:
    // 0x80009C84: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80009C88: lw          $a1, -0x23A8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X23A8);
    // 0x80009C8C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80009C90: lw          $a0, 0x63D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63D4);
    // 0x80009C94: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x80009C98: addiu       $v1, $a1, 0x8
    ctx->r3 = ADD32(ctx->r5, 0X8);
    // 0x80009C9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80009CA0: sw          $v1, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r3;
    // 0x80009CA4: sltu        $v1, $v1, $a0
    ctx->r3 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x80009CA8: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80009CAC: bne         $v1, $zero, L_80009D9C
    if (ctx->r3 != 0) {
        // 0x80009CB0: sw          $zero, 0x4($a1)
        MEM_W(0X4, ctx->r5) = 0;
            goto L_80009D9C;
    }
    // 0x80009CB0: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80009CB4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80009CB8: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x80009CBC: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80009CC0: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x80009CC4: bne         $a0, $zero, L_80009D24
    if (ctx->r4 != 0) {
        // 0x80009CC8: sw          $zero, 0xC($a1)
        MEM_W(0XC, ctx->r5) = 0;
            goto L_80009D24;
    }
    // 0x80009CC8: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x80009CCC: jal         0x8002221C
    // 0x80009CD0: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_1;
    // 0x80009CD0: nop

    after_1:
    // 0x80009CD4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80009CD8: beq         $a0, $zero, L_80009D1C
    if (ctx->r4 == 0) {
        // 0x80009CDC: nop
    
            goto L_80009D1C;
    }
    // 0x80009CDC: nop

    // 0x80009CE0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80009CE4: beq         $v0, $zero, L_80009CFC
    if (ctx->r2 == 0) {
        // 0x80009CE8: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80009CFC;
    }
    // 0x80009CE8: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_80009CEC:
    // 0x80009CEC: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80009CF0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80009CF4: bne         $v0, $zero, L_80009CEC
    if (ctx->r2 != 0) {
        // 0x80009CF8: nop
    
            goto L_80009CEC;
    }
    // 0x80009CF8: nop

L_80009CFC:
    // 0x80009CFC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80009D00: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80009D04: beq         $v0, $zero, L_80009D10
    if (ctx->r2 == 0) {
        // 0x80009D08: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80009D10;
    }
    // 0x80009D08: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80009D0C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_80009D10:
    // 0x80009D10: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009D14: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x80009D18: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_80009D1C:
    // 0x80009D1C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80009D20: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_80009D24:
    // 0x80009D24: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80009D28: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80009D2C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80009D30: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009D34: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x80009D38: bnel        $v0, $zero, L_80009D40
    if (ctx->r2 != 0) {
        // 0x80009D3C: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_80009D40;
    }
    goto skip_1;
    // 0x80009D3C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_1:
L_80009D40:
    // 0x80009D40: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80009D44: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x80009D48: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80009D4C: bne         $v0, $zero, L_80009D5C
    if (ctx->r2 != 0) {
        // 0x80009D50: nop
    
            goto L_80009D5C;
    }
    // 0x80009D50: nop

    // 0x80009D54: j           L_80009D74
    // 0x80009D58: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_80009D74;
    // 0x80009D58: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_80009D5C:
    // 0x80009D5C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80009D60: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x80009D64: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80009D68: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80009D6C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80009D70: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_80009D74:
    // 0x80009D74: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80009D78: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x80009D7C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80009D80: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80009D84: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x80009D88: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009D8C: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x80009D90: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80009D94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80009D98: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_80009D9C:
    // 0x80009D9C: lui         $a1, 0xB900
    ctx->r5 = S32(0XB900 << 16);
    // 0x80009DA0: ori         $a1, $a1, 0x31D
    ctx->r5 = ctx->r5 | 0X31D;
    // 0x80009DA4: lui         $a0, 0xF0A
    ctx->r4 = S32(0XF0A << 16);
    // 0x80009DA8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80009DAC: lw          $a2, -0x23A8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X23A8);
    // 0x80009DB0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80009DB4: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80009DB8: ori         $a0, $a0, 0x4000
    ctx->r4 = ctx->r4 | 0X4000;
    // 0x80009DBC: addiu       $v0, $a2, 0x8
    ctx->r2 = ADD32(ctx->r6, 0X8);
    // 0x80009DC0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80009DC4: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x80009DC8: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80009DCC: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    // 0x80009DD0: bne         $v0, $zero, L_80009EC0
    if (ctx->r2 != 0) {
        // 0x80009DD4: sw          $a0, 0x4($a2)
        MEM_W(0X4, ctx->r6) = ctx->r4;
            goto L_80009EC0;
    }
    // 0x80009DD4: sw          $a0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r4;
    // 0x80009DD8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80009DDC: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x80009DE0: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80009DE4: sw          $v0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r2;
    // 0x80009DE8: bne         $a0, $zero, L_80009E48
    if (ctx->r4 != 0) {
        // 0x80009DEC: sw          $zero, 0xC($a2)
        MEM_W(0XC, ctx->r6) = 0;
            goto L_80009E48;
    }
    // 0x80009DEC: sw          $zero, 0xC($a2)
    MEM_W(0XC, ctx->r6) = 0;
    // 0x80009DF0: jal         0x8002221C
    // 0x80009DF4: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_2;
    // 0x80009DF4: nop

    after_2:
    // 0x80009DF8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80009DFC: beq         $a0, $zero, L_80009E40
    if (ctx->r4 == 0) {
        // 0x80009E00: nop
    
            goto L_80009E40;
    }
    // 0x80009E00: nop

    // 0x80009E04: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80009E08: beq         $v0, $zero, L_80009E20
    if (ctx->r2 == 0) {
        // 0x80009E0C: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80009E20;
    }
    // 0x80009E0C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_80009E10:
    // 0x80009E10: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80009E14: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80009E18: bne         $v0, $zero, L_80009E10
    if (ctx->r2 != 0) {
        // 0x80009E1C: nop
    
            goto L_80009E10;
    }
    // 0x80009E1C: nop

L_80009E20:
    // 0x80009E20: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80009E24: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80009E28: beq         $v0, $zero, L_80009E34
    if (ctx->r2 == 0) {
        // 0x80009E2C: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80009E34;
    }
    // 0x80009E2C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80009E30: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_80009E34:
    // 0x80009E34: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009E38: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x80009E3C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_80009E40:
    // 0x80009E40: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80009E44: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_80009E48:
    // 0x80009E48: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80009E4C: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80009E50: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80009E54: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009E58: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x80009E5C: bnel        $v0, $zero, L_80009E64
    if (ctx->r2 != 0) {
        // 0x80009E60: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_80009E64;
    }
    goto skip_2;
    // 0x80009E60: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_2:
L_80009E64:
    // 0x80009E64: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80009E68: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x80009E6C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80009E70: bne         $v0, $zero, L_80009E80
    if (ctx->r2 != 0) {
        // 0x80009E74: nop
    
            goto L_80009E80;
    }
    // 0x80009E74: nop

    // 0x80009E78: j           L_80009E98
    // 0x80009E7C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_80009E98;
    // 0x80009E7C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_80009E80:
    // 0x80009E80: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80009E84: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x80009E88: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80009E8C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80009E90: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80009E94: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_80009E98:
    // 0x80009E98: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80009E9C: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x80009EA0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80009EA4: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80009EA8: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x80009EAC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009EB0: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x80009EB4: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80009EB8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80009EBC: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_80009EC0:
    // 0x80009EC0: lui         $v0, 0xBA00
    ctx->r2 = S32(0XBA00 << 16);
    // 0x80009EC4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80009EC8: lw          $a1, -0x23A8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X23A8);
    // 0x80009ECC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80009ED0: lw          $a0, 0x63D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63D4);
    // 0x80009ED4: ori         $v0, $v0, 0x1402
    ctx->r2 = ctx->r2 | 0X1402;
    // 0x80009ED8: addiu       $v1, $a1, 0x8
    ctx->r3 = ADD32(ctx->r5, 0X8);
    // 0x80009EDC: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80009EE0: lui         $v0, 0x30
    ctx->r2 = S32(0X30 << 16);
    // 0x80009EE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80009EE8: sw          $v1, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r3;
    // 0x80009EEC: sltu        $v1, $v1, $a0
    ctx->r3 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x80009EF0: bne         $v1, $zero, L_80009FE0
    if (ctx->r3 != 0) {
        // 0x80009EF4: sw          $v0, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->r2;
            goto L_80009FE0;
    }
    // 0x80009EF4: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80009EF8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80009EFC: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x80009F00: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80009F04: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x80009F08: bne         $a0, $zero, L_80009F68
    if (ctx->r4 != 0) {
        // 0x80009F0C: sw          $zero, 0xC($a1)
        MEM_W(0XC, ctx->r5) = 0;
            goto L_80009F68;
    }
    // 0x80009F0C: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x80009F10: jal         0x8002221C
    // 0x80009F14: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_3;
    // 0x80009F14: nop

    after_3:
    // 0x80009F18: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80009F1C: beq         $a0, $zero, L_80009F60
    if (ctx->r4 == 0) {
        // 0x80009F20: nop
    
            goto L_80009F60;
    }
    // 0x80009F20: nop

    // 0x80009F24: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80009F28: beq         $v0, $zero, L_80009F40
    if (ctx->r2 == 0) {
        // 0x80009F2C: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80009F40;
    }
    // 0x80009F2C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_80009F30:
    // 0x80009F30: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80009F34: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80009F38: bne         $v0, $zero, L_80009F30
    if (ctx->r2 != 0) {
        // 0x80009F3C: nop
    
            goto L_80009F30;
    }
    // 0x80009F3C: nop

L_80009F40:
    // 0x80009F40: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80009F44: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80009F48: beq         $v0, $zero, L_80009F54
    if (ctx->r2 == 0) {
        // 0x80009F4C: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80009F54;
    }
    // 0x80009F4C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80009F50: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_80009F54:
    // 0x80009F54: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009F58: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x80009F5C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_80009F60:
    // 0x80009F60: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80009F64: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_80009F68:
    // 0x80009F68: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80009F6C: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x80009F70: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80009F74: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009F78: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x80009F7C: bnel        $v0, $zero, L_80009F84
    if (ctx->r2 != 0) {
        // 0x80009F80: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_80009F84;
    }
    goto skip_3;
    // 0x80009F80: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_3:
L_80009F84:
    // 0x80009F84: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80009F88: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x80009F8C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80009F90: bne         $v0, $zero, L_80009FA0
    if (ctx->r2 != 0) {
        // 0x80009F94: nop
    
            goto L_80009FA0;
    }
    // 0x80009F94: nop

    // 0x80009F98: j           L_80009FB8
    // 0x80009F9C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_80009FB8;
    // 0x80009F9C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_80009FA0:
    // 0x80009FA0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80009FA4: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x80009FA8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80009FAC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80009FB0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80009FB4: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_80009FB8:
    // 0x80009FB8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80009FBC: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x80009FC0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80009FC4: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80009FC8: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x80009FCC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80009FD0: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x80009FD4: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80009FD8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80009FDC: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_80009FE0:
    // 0x80009FE0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80009FE4: lh          $v0, -0x57B8($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X57B8);
    // 0x80009FE8: slti        $v0, $v0, 0x18
    ctx->r2 = SIGNED(ctx->r2) < 0X18 ? 1 : 0;
    // 0x80009FEC: bne         $v0, $zero, L_8000A02C
    if (ctx->r2 != 0) {
        // 0x80009FF0: sll         $v1, $s0, 8
        ctx->r3 = S32(ctx->r16 << 8);
            goto L_8000A02C;
    }
    // 0x80009FF0: sll         $v1, $s0, 8
    ctx->r3 = S32(ctx->r16 << 8);
    // 0x80009FF4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80009FF8: lw          $a0, -0x23A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X23A8);
    // 0x80009FFC: sll         $v1, $s1, 16
    ctx->r3 = S32(ctx->r17 << 16);
    // 0x8000A000: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000A004: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A008: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x8000A00C: lui         $v0, 0xF700
    ctx->r2 = S32(0XF700 << 16);
    // 0x8000A010: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8000A014: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
    // 0x8000A018: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8000A01C: sll         $v1, $s2, 8
    ctx->r3 = S32(ctx->r18 << 8);
    // 0x8000A020: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8000A024: j           L_8000A074
    // 0x8000A028: ori         $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 | 0XFF;
        goto L_8000A074;
    // 0x8000A028: ori         $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 | 0XFF;
L_8000A02C:
    // 0x8000A02C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000A030: lw          $a0, -0x23A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X23A8);
    // 0x8000A034: andi        $v1, $v1, 0xF800
    ctx->r3 = ctx->r3 & 0XF800;
    // 0x8000A038: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000A03C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A040: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x8000A044: lui         $v0, 0xF700
    ctx->r2 = S32(0XF700 << 16);
    // 0x8000A048: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8000A04C: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
    // 0x8000A050: andi        $v0, $v0, 0x7C0
    ctx->r2 = ctx->r2 & 0X7C0;
    // 0x8000A054: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8000A058: srl         $v0, $s2, 2
    ctx->r2 = S32(U32(ctx->r18) >> 2);
    // 0x8000A05C: andi        $v0, $v0, 0x3E
    ctx->r2 = ctx->r2 & 0X3E;
    // 0x8000A060: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8000A064: ori         $v0, $v1, 0x1
    ctx->r2 = ctx->r3 | 0X1;
    // 0x8000A068: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000A06C: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x8000A070: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
L_8000A074:
    // 0x8000A074: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8000A078: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A07C: lhu         $v0, -0x577E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X577E);
    // 0x8000A080: beq         $v0, $zero, L_8000A1D0
    if (ctx->r2 == 0) {
        // 0x8000A084: nop
    
            goto L_8000A1D0;
    }
    // 0x8000A084: nop

    // 0x8000A088: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000A08C: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000A090: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000A094: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x8000A098: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000A09C: bne         $v0, $zero, L_8000A188
    if (ctx->r2 != 0) {
        // 0x8000A0A0: lui         $v0, 0xB500
        ctx->r2 = S32(0XB500 << 16);
            goto L_8000A188;
    }
    // 0x8000A0A0: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x8000A0A4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000A0A8: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000A0AC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000A0B0: bne         $a0, $zero, L_8000A110
    if (ctx->r4 != 0) {
        // 0x8000A0B4: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8000A110;
    }
    // 0x8000A0B4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000A0B8: jal         0x8002221C
    // 0x8000A0BC: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_4;
    // 0x8000A0BC: nop

    after_4:
    // 0x8000A0C0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000A0C4: beq         $a0, $zero, L_8000A108
    if (ctx->r4 == 0) {
        // 0x8000A0C8: nop
    
            goto L_8000A108;
    }
    // 0x8000A0C8: nop

    // 0x8000A0CC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000A0D0: beq         $v0, $zero, L_8000A0E8
    if (ctx->r2 == 0) {
        // 0x8000A0D4: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000A0E8;
    }
    // 0x8000A0D4: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000A0D8:
    // 0x8000A0D8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000A0DC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000A0E0: bne         $v0, $zero, L_8000A0D8
    if (ctx->r2 != 0) {
        // 0x8000A0E4: nop
    
            goto L_8000A0D8;
    }
    // 0x8000A0E4: nop

L_8000A0E8:
    // 0x8000A0E8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000A0EC: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000A0F0: beq         $v0, $zero, L_8000A0FC
    if (ctx->r2 == 0) {
        // 0x8000A0F4: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000A0FC;
    }
    // 0x8000A0F4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000A0F8: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000A0FC:
    // 0x8000A0FC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000A100: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000A104: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000A108:
    // 0x8000A108: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000A10C: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000A110:
    // 0x8000A110: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000A114: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000A118: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000A11C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000A120: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000A124: bnel        $v0, $zero, L_8000A12C
    if (ctx->r2 != 0) {
        // 0x8000A128: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000A12C;
    }
    goto skip_4;
    // 0x8000A128: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_4:
L_8000A12C:
    // 0x8000A12C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000A130: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000A134: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000A138: bne         $v0, $zero, L_8000A148
    if (ctx->r2 != 0) {
        // 0x8000A13C: nop
    
            goto L_8000A148;
    }
    // 0x8000A13C: nop

    // 0x8000A140: j           L_8000A160
    // 0x8000A144: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000A160;
    // 0x8000A144: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000A148:
    // 0x8000A148: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A14C: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000A150: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000A154: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000A158: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000A15C: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000A160:
    // 0x8000A160: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A164: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000A168: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000A16C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000A170: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000A174: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000A178: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000A17C: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000A180: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A184: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_8000A188:
    // 0x8000A188: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000A18C: lw          $a1, -0x23A8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X23A8);
    // 0x8000A190: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000A194: lw          $v1, -0x57C8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X57C8);
    // 0x8000A198: lui         $a0, 0xF600
    ctx->r4 = S32(0XF600 << 16);
    // 0x8000A19C: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x8000A1A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A1A4: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x8000A1A8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A1AC: lhu         $v0, -0x577E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X577E);
    // 0x8000A1B0: andi        $v1, $v1, 0x3FF
    ctx->r3 = ctx->r3 & 0X3FF;
    // 0x8000A1B4: sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3 << 14);
    // 0x8000A1B8: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8000A1BC: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x8000A1C0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000A1C4: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x8000A1C8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8000A1CC: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
L_8000A1D0:
    // 0x8000A1D0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A1D4: lhu         $v0, -0x577A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X577A);
    // 0x8000A1D8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000A1DC: lw          $v1, -0x57C4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X57C4);
    // 0x8000A1E0: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8000A1E4: beq         $v0, $zero, L_8000A344
    if (ctx->r2 == 0) {
        // 0x8000A1E8: nop
    
            goto L_8000A344;
    }
    // 0x8000A1E8: nop

    // 0x8000A1EC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000A1F0: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000A1F4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000A1F8: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x8000A1FC: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000A200: bne         $v0, $zero, L_8000A2EC
    if (ctx->r2 != 0) {
        // 0x8000A204: lui         $v0, 0xB500
        ctx->r2 = S32(0XB500 << 16);
            goto L_8000A2EC;
    }
    // 0x8000A204: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x8000A208: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000A20C: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000A210: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000A214: bne         $a0, $zero, L_8000A274
    if (ctx->r4 != 0) {
        // 0x8000A218: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8000A274;
    }
    // 0x8000A218: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000A21C: jal         0x8002221C
    // 0x8000A220: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_5;
    // 0x8000A220: nop

    after_5:
    // 0x8000A224: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000A228: beq         $a0, $zero, L_8000A26C
    if (ctx->r4 == 0) {
        // 0x8000A22C: nop
    
            goto L_8000A26C;
    }
    // 0x8000A22C: nop

    // 0x8000A230: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000A234: beq         $v0, $zero, L_8000A24C
    if (ctx->r2 == 0) {
        // 0x8000A238: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000A24C;
    }
    // 0x8000A238: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000A23C:
    // 0x8000A23C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000A240: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000A244: bne         $v0, $zero, L_8000A23C
    if (ctx->r2 != 0) {
        // 0x8000A248: nop
    
            goto L_8000A23C;
    }
    // 0x8000A248: nop

L_8000A24C:
    // 0x8000A24C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000A250: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000A254: beq         $v0, $zero, L_8000A260
    if (ctx->r2 == 0) {
        // 0x8000A258: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000A260;
    }
    // 0x8000A258: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000A25C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000A260:
    // 0x8000A260: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000A264: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000A268: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000A26C:
    // 0x8000A26C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000A270: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000A274:
    // 0x8000A274: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000A278: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000A27C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000A280: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000A284: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000A288: bnel        $v0, $zero, L_8000A290
    if (ctx->r2 != 0) {
        // 0x8000A28C: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000A290;
    }
    goto skip_5;
    // 0x8000A28C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_5:
L_8000A290:
    // 0x8000A290: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000A294: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000A298: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000A29C: bne         $v0, $zero, L_8000A2AC
    if (ctx->r2 != 0) {
        // 0x8000A2A0: nop
    
            goto L_8000A2AC;
    }
    // 0x8000A2A0: nop

    // 0x8000A2A4: j           L_8000A2C4
    // 0x8000A2A8: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000A2C4;
    // 0x8000A2A8: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000A2AC:
    // 0x8000A2AC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A2B0: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000A2B4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000A2B8: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000A2BC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000A2C0: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000A2C4:
    // 0x8000A2C4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A2C8: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000A2CC: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000A2D0: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000A2D4: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000A2D8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000A2DC: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000A2E0: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000A2E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A2E8: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_8000A2EC:
    // 0x8000A2EC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000A2F0: lw          $v1, -0x57C8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X57C8);
    // 0x8000A2F4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000A2F8: lw          $a1, -0x23A8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X23A8);
    // 0x8000A2FC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A300: lw          $v0, -0x57C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X57C4);
    // 0x8000A304: lui         $a0, 0xF600
    ctx->r4 = S32(0XF600 << 16);
    // 0x8000A308: andi        $v1, $v1, 0x3FF
    ctx->r3 = ctx->r3 & 0X3FF;
    // 0x8000A30C: sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3 << 14);
    // 0x8000A310: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x8000A314: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000A318: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x8000A31C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8000A320: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x8000A324: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A328: lhu         $v0, -0x577A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X577A);
    // 0x8000A32C: addiu       $v1, $a1, 0x8
    ctx->r3 = ADD32(ctx->r5, 0X8);
    // 0x8000A330: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A334: sw          $v1, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r3;
    // 0x8000A338: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x8000A33C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000A340: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
L_8000A344:
    // 0x8000A344: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A348: lhu         $v0, -0x5780($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X5780);
    // 0x8000A34C: beq         $v0, $zero, L_8000A4AC
    if (ctx->r2 == 0) {
        // 0x8000A350: nop
    
            goto L_8000A4AC;
    }
    // 0x8000A350: nop

    // 0x8000A354: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000A358: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000A35C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000A360: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x8000A364: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000A368: bne         $v0, $zero, L_8000A454
    if (ctx->r2 != 0) {
        // 0x8000A36C: lui         $v0, 0xB500
        ctx->r2 = S32(0XB500 << 16);
            goto L_8000A454;
    }
    // 0x8000A36C: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x8000A370: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000A374: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000A378: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000A37C: bne         $a0, $zero, L_8000A3DC
    if (ctx->r4 != 0) {
        // 0x8000A380: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8000A3DC;
    }
    // 0x8000A380: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000A384: jal         0x8002221C
    // 0x8000A388: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_6;
    // 0x8000A388: nop

    after_6:
    // 0x8000A38C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000A390: beq         $a0, $zero, L_8000A3D4
    if (ctx->r4 == 0) {
        // 0x8000A394: nop
    
            goto L_8000A3D4;
    }
    // 0x8000A394: nop

    // 0x8000A398: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000A39C: beq         $v0, $zero, L_8000A3B4
    if (ctx->r2 == 0) {
        // 0x8000A3A0: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000A3B4;
    }
    // 0x8000A3A0: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000A3A4:
    // 0x8000A3A4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000A3A8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000A3AC: bne         $v0, $zero, L_8000A3A4
    if (ctx->r2 != 0) {
        // 0x8000A3B0: nop
    
            goto L_8000A3A4;
    }
    // 0x8000A3B0: nop

L_8000A3B4:
    // 0x8000A3B4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000A3B8: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000A3BC: beq         $v0, $zero, L_8000A3C8
    if (ctx->r2 == 0) {
        // 0x8000A3C0: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000A3C8;
    }
    // 0x8000A3C0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000A3C4: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000A3C8:
    // 0x8000A3C8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000A3CC: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000A3D0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000A3D4:
    // 0x8000A3D4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000A3D8: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000A3DC:
    // 0x8000A3DC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000A3E0: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000A3E4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000A3E8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000A3EC: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000A3F0: bnel        $v0, $zero, L_8000A3F8
    if (ctx->r2 != 0) {
        // 0x8000A3F4: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000A3F8;
    }
    goto skip_6;
    // 0x8000A3F4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_6:
L_8000A3F8:
    // 0x8000A3F8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000A3FC: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000A400: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000A404: bne         $v0, $zero, L_8000A414
    if (ctx->r2 != 0) {
        // 0x8000A408: nop
    
            goto L_8000A414;
    }
    // 0x8000A408: nop

    // 0x8000A40C: j           L_8000A42C
    // 0x8000A410: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000A42C;
    // 0x8000A410: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000A414:
    // 0x8000A414: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A418: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000A41C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000A420: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000A424: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000A428: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000A42C:
    // 0x8000A42C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A430: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000A434: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000A438: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000A43C: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000A440: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000A444: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000A448: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000A44C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A450: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_8000A454:
    // 0x8000A454: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000A458: lhu         $v1, -0x5780($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X5780);
    // 0x8000A45C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000A460: lw          $a1, -0x23A8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X23A8);
    // 0x8000A464: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A468: lhu         $v0, -0x577A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X577A);
    // 0x8000A46C: lui         $a0, 0xF600
    ctx->r4 = S32(0XF600 << 16);
    // 0x8000A470: andi        $v1, $v1, 0x3FF
    ctx->r3 = ctx->r3 & 0X3FF;
    // 0x8000A474: sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3 << 14);
    // 0x8000A478: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x8000A47C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000A480: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x8000A484: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8000A488: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x8000A48C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A490: lhu         $v0, -0x577E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X577E);
    // 0x8000A494: addiu       $v1, $a1, 0x8
    ctx->r3 = ADD32(ctx->r5, 0X8);
    // 0x8000A498: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A49C: sw          $v1, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r3;
    // 0x8000A4A0: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x8000A4A4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000A4A8: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
L_8000A4AC:
    // 0x8000A4AC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A4B0: lhu         $v0, -0x577C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X577C);
    // 0x8000A4B4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000A4B8: lw          $v1, -0x57C8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X57C8);
    // 0x8000A4BC: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8000A4C0: beq         $v0, $zero, L_8000A634
    if (ctx->r2 == 0) {
        // 0x8000A4C4: nop
    
            goto L_8000A634;
    }
    // 0x8000A4C4: nop

    // 0x8000A4C8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000A4CC: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000A4D0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000A4D4: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x8000A4D8: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000A4DC: bne         $v0, $zero, L_8000A5C8
    if (ctx->r2 != 0) {
        // 0x8000A4E0: lui         $v0, 0xB500
        ctx->r2 = S32(0XB500 << 16);
            goto L_8000A5C8;
    }
    // 0x8000A4E0: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x8000A4E4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000A4E8: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000A4EC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000A4F0: bne         $a0, $zero, L_8000A550
    if (ctx->r4 != 0) {
        // 0x8000A4F4: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8000A550;
    }
    // 0x8000A4F4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000A4F8: jal         0x8002221C
    // 0x8000A4FC: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_7;
    // 0x8000A4FC: nop

    after_7:
    // 0x8000A500: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000A504: beq         $a0, $zero, L_8000A548
    if (ctx->r4 == 0) {
        // 0x8000A508: nop
    
            goto L_8000A548;
    }
    // 0x8000A508: nop

    // 0x8000A50C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000A510: beq         $v0, $zero, L_8000A528
    if (ctx->r2 == 0) {
        // 0x8000A514: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000A528;
    }
    // 0x8000A514: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000A518:
    // 0x8000A518: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000A51C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000A520: bne         $v0, $zero, L_8000A518
    if (ctx->r2 != 0) {
        // 0x8000A524: nop
    
            goto L_8000A518;
    }
    // 0x8000A524: nop

L_8000A528:
    // 0x8000A528: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000A52C: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000A530: beq         $v0, $zero, L_8000A53C
    if (ctx->r2 == 0) {
        // 0x8000A534: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000A53C;
    }
    // 0x8000A534: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000A538: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000A53C:
    // 0x8000A53C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000A540: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000A544: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000A548:
    // 0x8000A548: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000A54C: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000A550:
    // 0x8000A550: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000A554: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000A558: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000A55C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000A560: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000A564: bnel        $v0, $zero, L_8000A56C
    if (ctx->r2 != 0) {
        // 0x8000A568: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000A56C;
    }
    goto skip_7;
    // 0x8000A568: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_7:
L_8000A56C:
    // 0x8000A56C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000A570: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000A574: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000A578: bne         $v0, $zero, L_8000A588
    if (ctx->r2 != 0) {
        // 0x8000A57C: nop
    
            goto L_8000A588;
    }
    // 0x8000A57C: nop

    // 0x8000A580: j           L_8000A5A0
    // 0x8000A584: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000A5A0;
    // 0x8000A584: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000A588:
    // 0x8000A588: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A58C: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000A590: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000A594: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000A598: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000A59C: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000A5A0:
    // 0x8000A5A0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A5A4: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000A5A8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000A5AC: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000A5B0: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000A5B4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000A5B8: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000A5BC: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000A5C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A5C4: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_8000A5C8:
    // 0x8000A5C8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000A5CC: lw          $v1, -0x57C8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X57C8);
    // 0x8000A5D0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000A5D4: lw          $a1, -0x23A8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X23A8);
    // 0x8000A5D8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A5DC: lhu         $v0, -0x577A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X577A);
    // 0x8000A5E0: lui         $a0, 0xF600
    ctx->r4 = S32(0XF600 << 16);
    // 0x8000A5E4: andi        $v1, $v1, 0x3FF
    ctx->r3 = ctx->r3 & 0X3FF;
    // 0x8000A5E8: sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3 << 14);
    // 0x8000A5EC: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x8000A5F0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000A5F4: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x8000A5F8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8000A5FC: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x8000A600: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A604: lhu         $v0, -0x577C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X577C);
    // 0x8000A608: addiu       $v1, $a1, 0x8
    ctx->r3 = ADD32(ctx->r5, 0X8);
    // 0x8000A60C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A610: sw          $v1, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r3;
    // 0x8000A614: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000A618: lhu         $v1, -0x577E($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X577E);
    // 0x8000A61C: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x8000A620: sll         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2 << 14);
    // 0x8000A624: andi        $v1, $v1, 0x3FF
    ctx->r3 = ctx->r3 & 0X3FF;
    // 0x8000A628: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8000A62C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8000A630: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
L_8000A634:
    // 0x8000A634: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A638: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8000A63C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8000A640: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000A644: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000A648: jr          $ra
    // 0x8000A64C: nop

    return;
    // 0x8000A64C: nop

;}
RECOMP_FUNC void func_8000A650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A650: lhu         $t2, 0x12($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X12);
    // 0x8000A654: lbu         $v1, 0x17($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X17);
    // 0x8000A658: lbu         $t0, 0x1B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1B);
    // 0x8000A65C: lbu         $t1, 0x1F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1F);
    // 0x8000A660: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000A664: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A668: sb          $v0, -0x5774($at)
    MEM_B(-0X5774, ctx->r1) = ctx->r2;
    // 0x8000A66C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A670: sh          $a1, -0x5780($at)
    MEM_H(-0X5780, ctx->r1) = ctx->r5;
    // 0x8000A674: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A678: sh          $a2, -0x577E($at)
    MEM_H(-0X577E, ctx->r1) = ctx->r6;
    // 0x8000A67C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A680: sh          $a3, -0x577C($at)
    MEM_H(-0X577C, ctx->r1) = ctx->r7;
    // 0x8000A684: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A688: sb          $a0, -0x5773($at)
    MEM_B(-0X5773, ctx->r1) = ctx->r4;
    // 0x8000A68C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A690: sb          $zero, -0x5772($at)
    MEM_B(-0X5772, ctx->r1) = 0;
    // 0x8000A694: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A698: sb          $v1, -0x5778($at)
    MEM_B(-0X5778, ctx->r1) = ctx->r3;
    // 0x8000A69C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A6A0: sb          $t0, -0x5777($at)
    MEM_B(-0X5777, ctx->r1) = ctx->r8;
    // 0x8000A6A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A6A8: sb          $t1, -0x5776($at)
    MEM_B(-0X5776, ctx->r1) = ctx->r9;
    // 0x8000A6AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A6B0: sh          $t2, -0x577A($at)
    MEM_H(-0X577A, ctx->r1) = ctx->r10;
    // 0x8000A6B4: jr          $ra
    // 0x8000A6B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8000A6B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_8000A6BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A6BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A6C0: sb          $zero, -0x5774($at)
    MEM_B(-0X5774, ctx->r1) = 0;
    // 0x8000A6C4: jr          $ra
    // 0x8000A6C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8000A6C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void frameStartReset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A6CC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A6D0: lw          $v0, -0x57C8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X57C8);
    // 0x8000A6D4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000A6D8: lw          $v1, -0x57C4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X57C4);
    // 0x8000A6DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000A6E0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000A6E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A6E8: sh          $zero, -0x56F6($at)
    MEM_H(-0X56F6, ctx->r1) = 0;
    // 0x8000A6EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A6F0: sh          $zero, -0x56F4($at)
    MEM_H(-0X56F4, ctx->r1) = 0;
    // 0x8000A6F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A6F8: sw          $zero, -0x23B0($at)
    MEM_W(-0X23B0, ctx->r1) = 0;
    // 0x8000A6FC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000A700: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8000A704: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A708: sh          $v0, -0x56F2($at)
    MEM_H(-0X56F2, ctx->r1) = ctx->r2;
    // 0x8000A70C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A710: sh          $v1, -0x56F0($at)
    MEM_H(-0X56F0, ctx->r1) = ctx->r3;
    // 0x8000A714: jal         0x800079F0
    // 0x8000A718: nop

    heapWalker(rdram, ctx);
        goto after_0;
    // 0x8000A718: nop

    after_0:
    // 0x8000A71C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A720: lbu         $v0, -0x5767($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5767);
    // 0x8000A724: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000A728: addiu       $v1, $v1, -0x2B68
    ctx->r3 = ADD32(ctx->r3, -0X2B68);
    // 0x8000A72C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000A730: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A734: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000A738: lw          $v0, -0x5740($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5740);
    // 0x8000A73C: addiu       $a2, $v1, 0x100
    ctx->r6 = ADD32(ctx->r3, 0X100);
    // 0x8000A740: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8000A744: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8000A748: sw          $zero, -0x7394($at)
    MEM_W(-0X7394, ctx->r1) = 0;
    // 0x8000A74C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000A750: sw          $zero, 0x43A0($at)
    MEM_W(0X43A0, ctx->r1) = 0;
    // 0x8000A754: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A758: sw          $v0, -0x23A4($at)
    MEM_W(-0X23A4, ctx->r1) = ctx->r2;
L_8000A75C:
    // 0x8000A75C: addiu       $v0, $zero, 0x3F
    ctx->r2 = ADD32(0, 0X3F);
    // 0x8000A760: addiu       $a0, $v1, 0xFC
    ctx->r4 = ADD32(ctx->r3, 0XFC);
L_8000A764:
    // 0x8000A764: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000A768: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000A76C: bgez        $v0, L_8000A764
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000A770: addiu       $a0, $a0, -0x4
        ctx->r4 = ADD32(ctx->r4, -0X4);
            goto L_8000A764;
    }
    // 0x8000A770: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x8000A774: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
    // 0x8000A778: addiu       $a0, $a2, 0x7C
    ctx->r4 = ADD32(ctx->r6, 0X7C);
L_8000A77C:
    // 0x8000A77C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000A780: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000A784: bgez        $v0, L_8000A77C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000A788: addiu       $a0, $a0, -0x4
        ctx->r4 = ADD32(ctx->r4, -0X4);
            goto L_8000A77C;
    }
    // 0x8000A788: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x8000A78C: addiu       $a2, $a2, 0x180
    ctx->r6 = ADD32(ctx->r6, 0X180);
    // 0x8000A790: addiu       $a1, $a1, 0x180
    ctx->r5 = ADD32(ctx->r5, 0X180);
    // 0x8000A794: slti        $v0, $a1, 0x600
    ctx->r2 = SIGNED(ctx->r5) < 0X600 ? 1 : 0;
    // 0x8000A798: bne         $v0, $zero, L_8000A75C
    if (ctx->r2 != 0) {
        // 0x8000A79C: addiu       $v1, $v1, 0x180
        ctx->r3 = ADD32(ctx->r3, 0X180);
            goto L_8000A75C;
    }
    // 0x8000A79C: addiu       $v1, $v1, 0x180
    ctx->r3 = ADD32(ctx->r3, 0X180);
    // 0x8000A7A0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A7A4: lbu         $v0, -0x5774($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5774);
    // 0x8000A7A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A7AC: sw          $zero, -0x5BA0($at)
    MEM_W(-0X5BA0, ctx->r1) = 0;
    // 0x8000A7B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A7B4: sw          $zero, -0x5B58($at)
    MEM_W(-0X5B58, ctx->r1) = 0;
    // 0x8000A7B8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000A7BC: sw          $zero, 0x7C00($at)
    MEM_W(0X7C00, ctx->r1) = 0;
    // 0x8000A7C0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000A7C4: sh          $zero, -0x202C($at)
    MEM_H(-0X202C, ctx->r1) = 0;
    // 0x8000A7C8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000A7CC: sh          $zero, -0x202A($at)
    MEM_H(-0X202A, ctx->r1) = 0;
    // 0x8000A7D0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000A7D4: sh          $zero, -0x2A64($at)
    MEM_H(-0X2A64, ctx->r1) = 0;
    // 0x8000A7D8: beq         $v0, $zero, L_8000A844
    if (ctx->r2 == 0) {
        // 0x8000A7DC: nop
    
            goto L_8000A844;
    }
    // 0x8000A7DC: nop

    // 0x8000A7E0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000A7E4: lbu         $v1, -0x5773($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X5773);
    // 0x8000A7E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000A7EC: bne         $v1, $v0, L_8000A83C
    if (ctx->r3 != ctx->r2) {
        // 0x8000A7F0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000A83C;
    }
    // 0x8000A7F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000A7F4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000A7F8: lbu         $v1, -0x5772($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X5772);
    // 0x8000A7FC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8000A800: lbu         $v0, -0x7153($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7153);
    // 0x8000A804: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000A808: beq         $v0, $zero, L_8000A82C
    if (ctx->r2 == 0) {
        // 0x8000A80C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8000A82C;
    }
    // 0x8000A80C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000A810: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000A814: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8000A818: sb          $v0, 0x7650($at)
    MEM_B(0X7650, ctx->r1) = ctx->r2;
    // 0x8000A81C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A820: sb          $v1, -0x5772($at)
    MEM_B(-0X5772, ctx->r1) = ctx->r3;
    // 0x8000A824: j           L_8000A844
    // 0x8000A828: nop

        goto L_8000A844;
    // 0x8000A828: nop

L_8000A82C:
    // 0x8000A82C: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8000A830: sb          $zero, 0x7650($at)
    MEM_B(0X7650, ctx->r1) = 0;
    // 0x8000A834: j           L_8000A844
    // 0x8000A838: nop

        goto L_8000A844;
    // 0x8000A838: nop

L_8000A83C:
    // 0x8000A83C: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8000A840: sb          $v0, 0x7650($at)
    MEM_B(0X7650, ctx->r1) = ctx->r2;
L_8000A844:
    // 0x8000A844: jal         0x80022048
    // 0x8000A848: nop

    tickTextureMaterialExpiry(rdram, ctx);
        goto after_1;
    // 0x8000A848: nop

    after_1:
    // 0x8000A84C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8000A850: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000A854: jr          $ra
    // 0x8000A858: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000A858: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void clearStructPair2C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A85C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000A860: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x8000A864: jr          $ra
    // 0x8000A868: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    return;
    // 0x8000A868: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
;}
RECOMP_FUNC void waitForPrevFrameDone(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A86C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000A870: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000A874: jal         0x8001C260
    // 0x8000A878: nop

    waitForPostSwapAck(rdram, ctx);
        goto after_0;
    // 0x8000A878: nop

    after_0:
    // 0x8000A87C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000A880: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A884: sb          $v0, -0x5766($at)
    MEM_B(-0X5766, ctx->r1) = ctx->r2;
    // 0x8000A888: jal         0x80001880
    // 0x8000A88C: nop

    clearFrameReadyFlag(rdram, ctx);
        goto after_1;
    // 0x8000A88C: nop

    after_1:
    // 0x8000A890: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8000A894: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000A898: jr          $ra
    // 0x8000A89C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000A89C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void beginFrameDLChunk(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A8A0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000A8A4: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000A8A8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8000A8AC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8000A8B0: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8000A8B4: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8000A8B8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8000A8BC: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8000A8C0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8000A8C4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8000A8C8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8000A8CC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8000A8D0: bne         $a0, $zero, L_8000A930
    if (ctx->r4 != 0) {
        // 0x8000A8D4: sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
            goto L_8000A930;
    }
    // 0x8000A8D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000A8D8: jal         0x8002221C
    // 0x8000A8DC: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_0;
    // 0x8000A8DC: nop

    after_0:
    // 0x8000A8E0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000A8E4: beq         $a0, $zero, L_8000A928
    if (ctx->r4 == 0) {
        // 0x8000A8E8: nop
    
            goto L_8000A928;
    }
    // 0x8000A8E8: nop

    // 0x8000A8EC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000A8F0: beq         $v0, $zero, L_8000A908
    if (ctx->r2 == 0) {
        // 0x8000A8F4: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000A908;
    }
    // 0x8000A8F4: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000A8F8:
    // 0x8000A8F8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000A8FC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000A900: bne         $v0, $zero, L_8000A8F8
    if (ctx->r2 != 0) {
        // 0x8000A904: nop
    
            goto L_8000A8F8;
    }
    // 0x8000A904: nop

L_8000A908:
    // 0x8000A908: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000A90C: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000A910: beq         $v0, $zero, L_8000A91C
    if (ctx->r2 == 0) {
        // 0x8000A914: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000A91C;
    }
    // 0x8000A914: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000A918: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000A91C:
    // 0x8000A91C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000A920: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000A924: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000A928:
    // 0x8000A928: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000A92C: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000A930:
    // 0x8000A930: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000A934: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000A938: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000A93C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000A940: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000A944: bnel        $v0, $zero, L_8000A94C
    if (ctx->r2 != 0) {
        // 0x8000A948: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000A94C;
    }
    goto skip_0;
    // 0x8000A948: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_0:
L_8000A94C:
    // 0x8000A94C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000A950: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000A954: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000A958: bne         $v0, $zero, L_8000A968
    if (ctx->r2 != 0) {
        // 0x8000A95C: nop
    
            goto L_8000A968;
    }
    // 0x8000A95C: nop

    // 0x8000A960: j           L_8000A980
    // 0x8000A964: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000A980;
    // 0x8000A964: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000A968:
    // 0x8000A968: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A96C: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000A970: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000A974: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000A978: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000A97C: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000A980:
    // 0x8000A980: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A984: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000A988: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000A98C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000A990: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000A994: lw          $v1, -0x23B0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23B0);
    // 0x8000A998: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000A99C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000A9A0: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000A9A4: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000A9A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A9AC: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x8000A9B0: beq         $v1, $zero, L_8000A9C8
    if (ctx->r3 == 0) {
        // 0x8000A9B4: nop
    
            goto L_8000A9C8;
    }
    // 0x8000A9B4: nop

    // 0x8000A9B8: lui         $v0, 0x700
    ctx->r2 = S32(0X700 << 16);
    // 0x8000A9BC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000A9C0: j           L_8000A9F0
    // 0x8000A9C4: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
        goto L_8000A9F0;
    // 0x8000A9C4: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
L_8000A9C8:
    // 0x8000A9C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A9CC: sw          $v0, -0x5B40($at)
    MEM_W(-0X5B40, ctx->r1) = ctx->r2;
    // 0x8000A9D0: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    // 0x8000A9D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000A9D8: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x8000A9DC: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x8000A9E0: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x8000A9E4: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x8000A9E8: addiu       $v0, $v0, 0x7658
    ctx->r2 = ADD32(ctx->r2, 0X7658);
    // 0x8000A9EC: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
L_8000A9F0:
    // 0x8000A9F0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000A9F4: lw          $v0, 0x7C00($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7C00);
    // 0x8000A9F8: blez        $v0, L_8000B500
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000A9FC: addu        $s7, $zero, $zero
        ctx->r23 = ADD32(0, 0);
            goto L_8000B500;
    }
    // 0x8000A9FC: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // 0x8000AA00: lui         $s5, 0xB500
    ctx->r21 = S32(0XB500 << 16);
    // 0x8000AA04: lui         $s6, 0x600
    ctx->r22 = S32(0X600 << 16);
    // 0x8000AA08: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000AA0C: addiu       $v0, $v0, -0x2B68
    ctx->r2 = ADD32(ctx->r2, -0X2B68);
    // 0x8000AA10: addiu       $a1, $v0, 0x100
    ctx->r5 = ADD32(ctx->r2, 0X100);
    // 0x8000AA14: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000AA18: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x8000AA1C: addu        $fp, $v0, $zero
    ctx->r30 = ADD32(ctx->r2, 0);
L_8000AA20:
    // 0x8000AA20: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000AA24: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000AA28: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000AA2C: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x8000AA30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000AA34: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x8000AA38: lhu         $s2, -0x5B90($at)
    ctx->r18 = MEM_HU(ctx->r1, -0X5B90);
    // 0x8000AA3C: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000AA40: bnel        $v0, $zero, L_8000AB38
    if (ctx->r2 != 0) {
        // 0x8000AA44: sll         $v0, $s2, 1
        ctx->r2 = S32(ctx->r18 << 1);
            goto L_8000AB38;
    }
    goto skip_1;
    // 0x8000AA44: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    skip_1:
    // 0x8000AA48: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000AA4C: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000AA50: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x8000AA54: bne         $a0, $zero, L_8000AAB4
    if (ctx->r4 != 0) {
        // 0x8000AA58: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8000AAB4;
    }
    // 0x8000AA58: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000AA5C: jal         0x8002221C
    // 0x8000AA60: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_1;
    // 0x8000AA60: nop

    after_1:
    // 0x8000AA64: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000AA68: beq         $a0, $zero, L_8000AAAC
    if (ctx->r4 == 0) {
        // 0x8000AA6C: nop
    
            goto L_8000AAAC;
    }
    // 0x8000AA6C: nop

    // 0x8000AA70: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000AA74: beq         $v0, $zero, L_8000AA8C
    if (ctx->r2 == 0) {
        // 0x8000AA78: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000AA8C;
    }
    // 0x8000AA78: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000AA7C:
    // 0x8000AA7C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000AA80: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000AA84: bne         $v0, $zero, L_8000AA7C
    if (ctx->r2 != 0) {
        // 0x8000AA88: nop
    
            goto L_8000AA7C;
    }
    // 0x8000AA88: nop

L_8000AA8C:
    // 0x8000AA8C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000AA90: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000AA94: beq         $v0, $zero, L_8000AAA0
    if (ctx->r2 == 0) {
        // 0x8000AA98: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000AAA0;
    }
    // 0x8000AA98: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000AA9C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000AAA0:
    // 0x8000AAA0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000AAA4: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000AAA8: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000AAAC:
    // 0x8000AAAC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000AAB0: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000AAB4:
    // 0x8000AAB4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000AAB8: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000AABC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000AAC0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000AAC4: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000AAC8: bnel        $v0, $zero, L_8000AAD0
    if (ctx->r2 != 0) {
        // 0x8000AACC: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000AAD0;
    }
    goto skip_2;
    // 0x8000AACC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_2:
L_8000AAD0:
    // 0x8000AAD0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000AAD4: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000AAD8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000AADC: bne         $v0, $zero, L_8000AAEC
    if (ctx->r2 != 0) {
        // 0x8000AAE0: nop
    
            goto L_8000AAEC;
    }
    // 0x8000AAE0: nop

    // 0x8000AAE4: j           L_8000AB04
    // 0x8000AAE8: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000AB04;
    // 0x8000AAE8: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000AAEC:
    // 0x8000AAEC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000AAF0: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000AAF4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000AAF8: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000AAFC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000AB00: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000AB04:
    // 0x8000AB04: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000AB08: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000AB0C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000AB10: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000AB14: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000AB18: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000AB1C: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000AB20: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000AB24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000AB28: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x8000AB2C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000AB30: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000AB34: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
L_8000AB38:
    // 0x8000AB38: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8000AB3C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000AB40: sw          $s6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r22;
    // 0x8000AB44: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000AB48: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000AB4C: lw          $v0, 0x6400($at)
    ctx->r2 = MEM_W(ctx->r1, 0X6400);
    // 0x8000AB50: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // 0x8000AB54: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8000AB58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000AB5C: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x8000AB60: lhu         $s0, -0x5B88($at)
    ctx->r16 = MEM_HU(ctx->r1, -0X5B88);
    // 0x8000AB64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000AB68: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x8000AB6C: lhu         $v0, -0x5B86($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X5B86);
    // 0x8000AB70: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8000AB74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000AB78: sw          $v1, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r3;
    // 0x8000AB7C: slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000AB80: beq         $v0, $zero, L_8000ACDC
    if (ctx->r2 == 0) {
        // 0x8000AB84: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8000ACDC;
    }
    // 0x8000AB84: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000AB88: addu        $s4, $s3, $zero
    ctx->r20 = ADD32(ctx->r19, 0);
    // 0x8000AB8C: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x8000AB90: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000AB94: addiu       $a1, $a1, -0x5B30
    ctx->r5 = ADD32(ctx->r5, -0X5B30);
    // 0x8000AB98: addu        $s1, $v0, $a1
    ctx->r17 = ADD32(ctx->r2, ctx->r5);
L_8000AB9C:
    // 0x8000AB9C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000ABA0: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000ABA4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000ABA8: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x8000ABAC: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000ABB0: bne         $v0, $zero, L_8000AC9C
    if (ctx->r2 != 0) {
        // 0x8000ABB4: nop
    
            goto L_8000AC9C;
    }
    // 0x8000ABB4: nop

    // 0x8000ABB8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000ABBC: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000ABC0: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x8000ABC4: bne         $a0, $zero, L_8000AC24
    if (ctx->r4 != 0) {
        // 0x8000ABC8: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8000AC24;
    }
    // 0x8000ABC8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000ABCC: jal         0x8002221C
    // 0x8000ABD0: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_2;
    // 0x8000ABD0: nop

    after_2:
    // 0x8000ABD4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000ABD8: beq         $a0, $zero, L_8000AC1C
    if (ctx->r4 == 0) {
        // 0x8000ABDC: nop
    
            goto L_8000AC1C;
    }
    // 0x8000ABDC: nop

    // 0x8000ABE0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000ABE4: beq         $v0, $zero, L_8000ABFC
    if (ctx->r2 == 0) {
        // 0x8000ABE8: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000ABFC;
    }
    // 0x8000ABE8: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000ABEC:
    // 0x8000ABEC: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000ABF0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000ABF4: bne         $v0, $zero, L_8000ABEC
    if (ctx->r2 != 0) {
        // 0x8000ABF8: nop
    
            goto L_8000ABEC;
    }
    // 0x8000ABF8: nop

L_8000ABFC:
    // 0x8000ABFC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000AC00: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000AC04: beq         $v0, $zero, L_8000AC10
    if (ctx->r2 == 0) {
        // 0x8000AC08: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000AC10;
    }
    // 0x8000AC08: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000AC0C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000AC10:
    // 0x8000AC10: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000AC14: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000AC18: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000AC1C:
    // 0x8000AC1C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000AC20: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000AC24:
    // 0x8000AC24: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000AC28: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000AC2C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000AC30: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000AC34: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000AC38: bnel        $v0, $zero, L_8000AC40
    if (ctx->r2 != 0) {
        // 0x8000AC3C: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000AC40;
    }
    goto skip_3;
    // 0x8000AC3C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_3:
L_8000AC40:
    // 0x8000AC40: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000AC44: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000AC48: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000AC4C: bne         $v0, $zero, L_8000AC5C
    if (ctx->r2 != 0) {
        // 0x8000AC50: nop
    
            goto L_8000AC5C;
    }
    // 0x8000AC50: nop

    // 0x8000AC54: j           L_8000AC74
    // 0x8000AC58: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000AC74;
    // 0x8000AC58: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000AC5C:
    // 0x8000AC5C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000AC60: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000AC64: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000AC68: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000AC6C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000AC70: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000AC74:
    // 0x8000AC74: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000AC78: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000AC7C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000AC80: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000AC84: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000AC88: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000AC8C: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000AC90: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000AC94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000AC98: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_8000AC9C:
    // 0x8000AC9C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000ACA0: lw          $v0, -0x23A8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X23A8);
    // 0x8000ACA4: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x8000ACA8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000ACAC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000ACB0: addiu       $v1, $v1, -0x8
    ctx->r3 = ADD32(ctx->r3, -0X8);
    // 0x8000ACB4: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x8000ACB8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000ACBC: addu        $at, $at, $s4
    ctx->r1 = ADD32(ctx->r1, ctx->r20);
    // 0x8000ACC0: lhu         $v1, -0x5B86($at)
    ctx->r3 = MEM_HU(ctx->r1, -0X5B86);
    // 0x8000ACC4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8000ACC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000ACCC: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x8000ACD0: slt         $v1, $s0, $v1
    ctx->r3 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000ACD4: bne         $v1, $zero, L_8000AB9C
    if (ctx->r3 != 0) {
        // 0x8000ACD8: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8000AB9C;
    }
    // 0x8000ACD8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8000ACDC:
    // 0x8000ACDC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000ACE0: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x8000ACE4: lhu         $v0, -0x5B8E($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X5B8E);
    // 0x8000ACE8: slt         $v0, $s2, $v0
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000ACEC: beq         $v0, $zero, L_8000AF8C
    if (ctx->r2 == 0) {
        // 0x8000ACF0: addu        $s1, $s3, $zero
        ctx->r17 = ADD32(ctx->r19, 0);
            goto L_8000AF8C;
    }
    // 0x8000ACF0: addu        $s1, $s3, $zero
    ctx->r17 = ADD32(ctx->r19, 0);
    // 0x8000ACF4: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    // 0x8000ACF8: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8000ACFC: sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2 << 2);
L_8000AD00:
    // 0x8000AD00: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000AD04: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8000AD08: lw          $v0, 0x6404($at)
    ctx->r2 = MEM_W(ctx->r1, 0X6404);
    // 0x8000AD0C: beq         $v0, $zero, L_8000AE44
    if (ctx->r2 == 0) {
        // 0x8000AD10: nop
    
            goto L_8000AE44;
    }
    // 0x8000AD10: nop

    // 0x8000AD14: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000AD18: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000AD1C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000AD20: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x8000AD24: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000AD28: bnel        $v0, $zero, L_8000AE20
    if (ctx->r2 != 0) {
        // 0x8000AD2C: lui         $v0, 0x102
        ctx->r2 = S32(0X102 << 16);
            goto L_8000AE20;
    }
    goto skip_4;
    // 0x8000AD2C: lui         $v0, 0x102
    ctx->r2 = S32(0X102 << 16);
    skip_4:
    // 0x8000AD30: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000AD34: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000AD38: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x8000AD3C: bne         $a0, $zero, L_8000AD9C
    if (ctx->r4 != 0) {
        // 0x8000AD40: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8000AD9C;
    }
    // 0x8000AD40: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000AD44: jal         0x8002221C
    // 0x8000AD48: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_3;
    // 0x8000AD48: nop

    after_3:
    // 0x8000AD4C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000AD50: beq         $a0, $zero, L_8000AD94
    if (ctx->r4 == 0) {
        // 0x8000AD54: nop
    
            goto L_8000AD94;
    }
    // 0x8000AD54: nop

    // 0x8000AD58: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000AD5C: beq         $v0, $zero, L_8000AD74
    if (ctx->r2 == 0) {
        // 0x8000AD60: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000AD74;
    }
    // 0x8000AD60: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000AD64:
    // 0x8000AD64: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000AD68: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000AD6C: bne         $v0, $zero, L_8000AD64
    if (ctx->r2 != 0) {
        // 0x8000AD70: nop
    
            goto L_8000AD64;
    }
    // 0x8000AD70: nop

L_8000AD74:
    // 0x8000AD74: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000AD78: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000AD7C: beq         $v0, $zero, L_8000AD88
    if (ctx->r2 == 0) {
        // 0x8000AD80: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000AD88;
    }
    // 0x8000AD80: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000AD84: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000AD88:
    // 0x8000AD88: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000AD8C: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000AD90: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000AD94:
    // 0x8000AD94: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000AD98: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000AD9C:
    // 0x8000AD9C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000ADA0: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000ADA4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000ADA8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000ADAC: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000ADB0: bnel        $v0, $zero, L_8000ADB8
    if (ctx->r2 != 0) {
        // 0x8000ADB4: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000ADB8;
    }
    goto skip_5;
    // 0x8000ADB4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_5:
L_8000ADB8:
    // 0x8000ADB8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000ADBC: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000ADC0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000ADC4: bne         $v0, $zero, L_8000ADD4
    if (ctx->r2 != 0) {
        // 0x8000ADC8: nop
    
            goto L_8000ADD4;
    }
    // 0x8000ADC8: nop

    // 0x8000ADCC: j           L_8000ADEC
    // 0x8000ADD0: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000ADEC;
    // 0x8000ADD0: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000ADD4:
    // 0x8000ADD4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000ADD8: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000ADDC: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000ADE0: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000ADE4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000ADE8: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000ADEC:
    // 0x8000ADEC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000ADF0: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000ADF4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000ADF8: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000ADFC: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000AE00: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000AE04: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000AE08: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000AE0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000AE10: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x8000AE14: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000AE18: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000AE1C: lui         $v0, 0x102
    ctx->r2 = S32(0X102 << 16);
L_8000AE20:
    // 0x8000AE20: ori         $v0, $v0, 0x40
    ctx->r2 = ctx->r2 | 0X40;
    // 0x8000AE24: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000AE28: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000AE2C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8000AE30: lw          $a0, 0x6404($at)
    ctx->r4 = MEM_W(ctx->r1, 0X6404);
    // 0x8000AE34: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8000AE38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000AE3C: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x8000AE40: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
L_8000AE44:
    // 0x8000AE44: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000AE48: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000AE4C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000AE50: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x8000AE54: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000AE58: bne         $v0, $zero, L_8000AF44
    if (ctx->r2 != 0) {
        // 0x8000AE5C: nop
    
            goto L_8000AF44;
    }
    // 0x8000AE5C: nop

    // 0x8000AE60: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000AE64: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000AE68: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x8000AE6C: bne         $a0, $zero, L_8000AECC
    if (ctx->r4 != 0) {
        // 0x8000AE70: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8000AECC;
    }
    // 0x8000AE70: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000AE74: jal         0x8002221C
    // 0x8000AE78: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_4;
    // 0x8000AE78: nop

    after_4:
    // 0x8000AE7C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000AE80: beq         $a0, $zero, L_8000AEC4
    if (ctx->r4 == 0) {
        // 0x8000AE84: nop
    
            goto L_8000AEC4;
    }
    // 0x8000AE84: nop

    // 0x8000AE88: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000AE8C: beq         $v0, $zero, L_8000AEA4
    if (ctx->r2 == 0) {
        // 0x8000AE90: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000AEA4;
    }
    // 0x8000AE90: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000AE94:
    // 0x8000AE94: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000AE98: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000AE9C: bne         $v0, $zero, L_8000AE94
    if (ctx->r2 != 0) {
        // 0x8000AEA0: nop
    
            goto L_8000AE94;
    }
    // 0x8000AEA0: nop

L_8000AEA4:
    // 0x8000AEA4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000AEA8: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000AEAC: beq         $v0, $zero, L_8000AEB8
    if (ctx->r2 == 0) {
        // 0x8000AEB0: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000AEB8;
    }
    // 0x8000AEB0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000AEB4: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000AEB8:
    // 0x8000AEB8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000AEBC: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000AEC0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000AEC4:
    // 0x8000AEC4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000AEC8: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000AECC:
    // 0x8000AECC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000AED0: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000AED4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000AED8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000AEDC: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000AEE0: bnel        $v0, $zero, L_8000AEE8
    if (ctx->r2 != 0) {
        // 0x8000AEE4: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000AEE8;
    }
    goto skip_6;
    // 0x8000AEE4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_6:
L_8000AEE8:
    // 0x8000AEE8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000AEEC: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000AEF0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000AEF4: bne         $v0, $zero, L_8000AF04
    if (ctx->r2 != 0) {
        // 0x8000AEF8: nop
    
            goto L_8000AF04;
    }
    // 0x8000AEF8: nop

    // 0x8000AEFC: j           L_8000AF1C
    // 0x8000AF00: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000AF1C;
    // 0x8000AF00: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000AF04:
    // 0x8000AF04: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000AF08: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000AF0C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000AF10: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000AF14: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000AF18: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000AF1C:
    // 0x8000AF1C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000AF20: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000AF24: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000AF28: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000AF2C: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000AF30: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000AF34: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000AF38: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000AF3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000AF40: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_8000AF44:
    // 0x8000AF44: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000AF48: lw          $v0, -0x23A8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X23A8);
    // 0x8000AF4C: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x8000AF50: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000AF54: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8000AF58: lw          $v1, 0x6400($at)
    ctx->r3 = MEM_W(ctx->r1, 0X6400);
    // 0x8000AF5C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000AF60: addiu       $v1, $v1, -0x8
    ctx->r3 = ADD32(ctx->r3, -0X8);
    // 0x8000AF64: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x8000AF68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000AF6C: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8000AF70: lhu         $v1, -0x5B8E($at)
    ctx->r3 = MEM_HU(ctx->r1, -0X5B8E);
    // 0x8000AF74: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8000AF78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000AF7C: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x8000AF80: slt         $v1, $s2, $v1
    ctx->r3 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000AF84: bne         $v1, $zero, L_8000AD00
    if (ctx->r3 != 0) {
        // 0x8000AF88: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_8000AD00;
    }
    // 0x8000AF88: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_8000AF8C:
    // 0x8000AF8C: addiu       $s2, $zero, 0x3F
    ctx->r18 = ADD32(0, 0X3F);
    // 0x8000AF90: addiu       $s1, $fp, 0xFC
    ctx->r17 = ADD32(ctx->r30, 0XFC);
L_8000AF94:
    // 0x8000AF94: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8000AF98: beql        $s0, $zero, L_8000B208
    if (ctx->r16 == 0) {
        // 0x8000AF9C: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_8000B208;
    }
    goto skip_7;
    // 0x8000AF9C: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_7:
L_8000AFA0:
    // 0x8000AFA0: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8000AFA4: beq         $v0, $zero, L_8000B0D4
    if (ctx->r2 == 0) {
        // 0x8000AFA8: nop
    
            goto L_8000B0D4;
    }
    // 0x8000AFA8: nop

    // 0x8000AFAC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000AFB0: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000AFB4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000AFB8: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x8000AFBC: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000AFC0: bnel        $v0, $zero, L_8000B0B8
    if (ctx->r2 != 0) {
        // 0x8000AFC4: lui         $v0, 0x102
        ctx->r2 = S32(0X102 << 16);
            goto L_8000B0B8;
    }
    goto skip_8;
    // 0x8000AFC4: lui         $v0, 0x102
    ctx->r2 = S32(0X102 << 16);
    skip_8:
    // 0x8000AFC8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000AFCC: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000AFD0: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x8000AFD4: bne         $a0, $zero, L_8000B034
    if (ctx->r4 != 0) {
        // 0x8000AFD8: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8000B034;
    }
    // 0x8000AFD8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000AFDC: jal         0x8002221C
    // 0x8000AFE0: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_5;
    // 0x8000AFE0: nop

    after_5:
    // 0x8000AFE4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000AFE8: beq         $a0, $zero, L_8000B02C
    if (ctx->r4 == 0) {
        // 0x8000AFEC: nop
    
            goto L_8000B02C;
    }
    // 0x8000AFEC: nop

    // 0x8000AFF0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000AFF4: beq         $v0, $zero, L_8000B00C
    if (ctx->r2 == 0) {
        // 0x8000AFF8: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000B00C;
    }
    // 0x8000AFF8: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000AFFC:
    // 0x8000AFFC: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000B000: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000B004: bne         $v0, $zero, L_8000AFFC
    if (ctx->r2 != 0) {
        // 0x8000B008: nop
    
            goto L_8000AFFC;
    }
    // 0x8000B008: nop

L_8000B00C:
    // 0x8000B00C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000B010: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000B014: beq         $v0, $zero, L_8000B020
    if (ctx->r2 == 0) {
        // 0x8000B018: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000B020;
    }
    // 0x8000B018: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000B01C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000B020:
    // 0x8000B020: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000B024: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000B028: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000B02C:
    // 0x8000B02C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000B030: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000B034:
    // 0x8000B034: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000B038: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000B03C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000B040: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000B044: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000B048: bnel        $v0, $zero, L_8000B050
    if (ctx->r2 != 0) {
        // 0x8000B04C: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000B050;
    }
    goto skip_9;
    // 0x8000B04C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_9:
L_8000B050:
    // 0x8000B050: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000B054: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000B058: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000B05C: bne         $v0, $zero, L_8000B06C
    if (ctx->r2 != 0) {
        // 0x8000B060: nop
    
            goto L_8000B06C;
    }
    // 0x8000B060: nop

    // 0x8000B064: j           L_8000B084
    // 0x8000B068: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000B084;
    // 0x8000B068: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000B06C:
    // 0x8000B06C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000B070: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000B074: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000B078: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000B07C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000B080: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000B084:
    // 0x8000B084: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000B088: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000B08C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000B090: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000B094: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000B098: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000B09C: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000B0A0: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000B0A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B0A8: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x8000B0AC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000B0B0: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000B0B4: lui         $v0, 0x102
    ctx->r2 = S32(0X102 << 16);
L_8000B0B8:
    // 0x8000B0B8: ori         $v0, $v0, 0x40
    ctx->r2 = ctx->r2 | 0X40;
    // 0x8000B0BC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000B0C0: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8000B0C4: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8000B0C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B0CC: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x8000B0D0: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
L_8000B0D4:
    // 0x8000B0D4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000B0D8: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000B0DC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000B0E0: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x8000B0E4: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000B0E8: bnel        $v0, $zero, L_8000B1E0
    if (ctx->r2 != 0) {
        // 0x8000B0EC: sw          $s6, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r22;
            goto L_8000B1E0;
    }
    goto skip_10;
    // 0x8000B0EC: sw          $s6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r22;
    skip_10:
    // 0x8000B0F0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000B0F4: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000B0F8: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x8000B0FC: bne         $a0, $zero, L_8000B15C
    if (ctx->r4 != 0) {
        // 0x8000B100: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8000B15C;
    }
    // 0x8000B100: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000B104: jal         0x8002221C
    // 0x8000B108: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_6;
    // 0x8000B108: nop

    after_6:
    // 0x8000B10C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000B110: beq         $a0, $zero, L_8000B154
    if (ctx->r4 == 0) {
        // 0x8000B114: nop
    
            goto L_8000B154;
    }
    // 0x8000B114: nop

    // 0x8000B118: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000B11C: beq         $v0, $zero, L_8000B134
    if (ctx->r2 == 0) {
        // 0x8000B120: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000B134;
    }
    // 0x8000B120: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000B124:
    // 0x8000B124: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000B128: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000B12C: bne         $v0, $zero, L_8000B124
    if (ctx->r2 != 0) {
        // 0x8000B130: nop
    
            goto L_8000B124;
    }
    // 0x8000B130: nop

L_8000B134:
    // 0x8000B134: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000B138: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000B13C: beq         $v0, $zero, L_8000B148
    if (ctx->r2 == 0) {
        // 0x8000B140: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000B148;
    }
    // 0x8000B140: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000B144: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000B148:
    // 0x8000B148: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000B14C: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000B150: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000B154:
    // 0x8000B154: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000B158: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000B15C:
    // 0x8000B15C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000B160: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000B164: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000B168: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000B16C: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000B170: bnel        $v0, $zero, L_8000B178
    if (ctx->r2 != 0) {
        // 0x8000B174: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000B178;
    }
    goto skip_11;
    // 0x8000B174: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_11:
L_8000B178:
    // 0x8000B178: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000B17C: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000B180: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000B184: bne         $v0, $zero, L_8000B194
    if (ctx->r2 != 0) {
        // 0x8000B188: nop
    
            goto L_8000B194;
    }
    // 0x8000B188: nop

    // 0x8000B18C: j           L_8000B1AC
    // 0x8000B190: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000B1AC;
    // 0x8000B190: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000B194:
    // 0x8000B194: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000B198: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000B19C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000B1A0: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000B1A4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000B1A8: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000B1AC:
    // 0x8000B1AC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000B1B0: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000B1B4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000B1B8: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000B1BC: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000B1C0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000B1C4: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000B1C8: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000B1CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B1D0: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x8000B1D4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000B1D8: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000B1DC: sw          $s6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r22;
L_8000B1E0:
    // 0x8000B1E0: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8000B1E4: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // 0x8000B1E8: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8000B1EC: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x8000B1F0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8000B1F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B1F8: sw          $v1, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r3;
    // 0x8000B1FC: bne         $s0, $zero, L_8000AFA0
    if (ctx->r16 != 0) {
        // 0x8000B200: nop
    
            goto L_8000AFA0;
    }
    // 0x8000B200: nop

    // 0x8000B204: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_8000B208:
    // 0x8000B208: bgez        $s2, L_8000AF94
    if (SIGNED(ctx->r18) >= 0) {
        // 0x8000B20C: addiu       $s1, $s1, -0x4
        ctx->r17 = ADD32(ctx->r17, -0X4);
            goto L_8000AF94;
    }
    // 0x8000B20C: addiu       $s1, $s1, -0x4
    ctx->r17 = ADD32(ctx->r17, -0X4);
    // 0x8000B210: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B214: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x8000B218: lhu         $s0, -0x5B8C($at)
    ctx->r16 = MEM_HU(ctx->r1, -0X5B8C);
    // 0x8000B21C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B220: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x8000B224: lhu         $v0, -0x5B8A($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X5B8A);
    // 0x8000B228: slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000B22C: beq         $v0, $zero, L_8000B384
    if (ctx->r2 == 0) {
        // 0x8000B230: addu        $s2, $s3, $zero
        ctx->r18 = ADD32(ctx->r19, 0);
            goto L_8000B384;
    }
    // 0x8000B230: addu        $s2, $s3, $zero
    ctx->r18 = ADD32(ctx->r19, 0);
    // 0x8000B234: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x8000B238: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000B23C: addiu       $a1, $a1, -0x5B30
    ctx->r5 = ADD32(ctx->r5, -0X5B30);
    // 0x8000B240: addu        $s1, $v0, $a1
    ctx->r17 = ADD32(ctx->r2, ctx->r5);
L_8000B244:
    // 0x8000B244: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000B248: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000B24C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000B250: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x8000B254: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000B258: bne         $v0, $zero, L_8000B344
    if (ctx->r2 != 0) {
        // 0x8000B25C: nop
    
            goto L_8000B344;
    }
    // 0x8000B25C: nop

    // 0x8000B260: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000B264: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000B268: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x8000B26C: bne         $a0, $zero, L_8000B2CC
    if (ctx->r4 != 0) {
        // 0x8000B270: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8000B2CC;
    }
    // 0x8000B270: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000B274: jal         0x8002221C
    // 0x8000B278: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_7;
    // 0x8000B278: nop

    after_7:
    // 0x8000B27C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000B280: beq         $a0, $zero, L_8000B2C4
    if (ctx->r4 == 0) {
        // 0x8000B284: nop
    
            goto L_8000B2C4;
    }
    // 0x8000B284: nop

    // 0x8000B288: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000B28C: beq         $v0, $zero, L_8000B2A4
    if (ctx->r2 == 0) {
        // 0x8000B290: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000B2A4;
    }
    // 0x8000B290: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000B294:
    // 0x8000B294: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000B298: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000B29C: bne         $v0, $zero, L_8000B294
    if (ctx->r2 != 0) {
        // 0x8000B2A0: nop
    
            goto L_8000B294;
    }
    // 0x8000B2A0: nop

L_8000B2A4:
    // 0x8000B2A4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000B2A8: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000B2AC: beq         $v0, $zero, L_8000B2B8
    if (ctx->r2 == 0) {
        // 0x8000B2B0: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000B2B8;
    }
    // 0x8000B2B0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000B2B4: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000B2B8:
    // 0x8000B2B8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000B2BC: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000B2C0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000B2C4:
    // 0x8000B2C4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000B2C8: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000B2CC:
    // 0x8000B2CC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000B2D0: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000B2D4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000B2D8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000B2DC: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000B2E0: bnel        $v0, $zero, L_8000B2E8
    if (ctx->r2 != 0) {
        // 0x8000B2E4: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000B2E8;
    }
    goto skip_12;
    // 0x8000B2E4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_12:
L_8000B2E8:
    // 0x8000B2E8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000B2EC: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000B2F0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000B2F4: bne         $v0, $zero, L_8000B304
    if (ctx->r2 != 0) {
        // 0x8000B2F8: nop
    
            goto L_8000B304;
    }
    // 0x8000B2F8: nop

    // 0x8000B2FC: j           L_8000B31C
    // 0x8000B300: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000B31C;
    // 0x8000B300: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000B304:
    // 0x8000B304: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000B308: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000B30C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000B310: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000B314: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000B318: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000B31C:
    // 0x8000B31C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000B320: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000B324: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000B328: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000B32C: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000B330: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000B334: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000B338: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000B33C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B340: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_8000B344:
    // 0x8000B344: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000B348: lw          $v0, -0x23A8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X23A8);
    // 0x8000B34C: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x8000B350: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000B354: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000B358: addiu       $v1, $v1, -0x8
    ctx->r3 = ADD32(ctx->r3, -0X8);
    // 0x8000B35C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x8000B360: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B364: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x8000B368: lhu         $v1, -0x5B8A($at)
    ctx->r3 = MEM_HU(ctx->r1, -0X5B8A);
    // 0x8000B36C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8000B370: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B374: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x8000B378: slt         $v1, $s0, $v1
    ctx->r3 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000B37C: bne         $v1, $zero, L_8000B244
    if (ctx->r3 != 0) {
        // 0x8000B380: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8000B244;
    }
    // 0x8000B380: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8000B384:
    // 0x8000B384: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B388: addiu       $s2, $zero, 0x1F
    ctx->r18 = ADD32(0, 0X1F);
    // 0x8000B38C: addiu       $s1, $a1, 0x7C
    ctx->r17 = ADD32(ctx->r5, 0X7C);
L_8000B390:
    // 0x8000B390: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8000B394: beql        $s0, $zero, L_8000B4D0
    if (ctx->r16 == 0) {
        // 0x8000B398: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_8000B4D0;
    }
    goto skip_13;
    // 0x8000B398: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_13:
L_8000B39C:
    // 0x8000B39C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000B3A0: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000B3A4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000B3A8: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x8000B3AC: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000B3B0: bnel        $v0, $zero, L_8000B4A8
    if (ctx->r2 != 0) {
        // 0x8000B3B4: sw          $s6, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r22;
            goto L_8000B4A8;
    }
    goto skip_14;
    // 0x8000B3B4: sw          $s6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r22;
    skip_14:
    // 0x8000B3B8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000B3BC: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000B3C0: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x8000B3C4: bne         $a0, $zero, L_8000B424
    if (ctx->r4 != 0) {
        // 0x8000B3C8: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8000B424;
    }
    // 0x8000B3C8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000B3CC: jal         0x8002221C
    // 0x8000B3D0: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_8;
    // 0x8000B3D0: nop

    after_8:
    // 0x8000B3D4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000B3D8: beq         $a0, $zero, L_8000B41C
    if (ctx->r4 == 0) {
        // 0x8000B3DC: nop
    
            goto L_8000B41C;
    }
    // 0x8000B3DC: nop

    // 0x8000B3E0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000B3E4: beq         $v0, $zero, L_8000B3FC
    if (ctx->r2 == 0) {
        // 0x8000B3E8: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000B3FC;
    }
    // 0x8000B3E8: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000B3EC:
    // 0x8000B3EC: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000B3F0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000B3F4: bne         $v0, $zero, L_8000B3EC
    if (ctx->r2 != 0) {
        // 0x8000B3F8: nop
    
            goto L_8000B3EC;
    }
    // 0x8000B3F8: nop

L_8000B3FC:
    // 0x8000B3FC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000B400: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000B404: beq         $v0, $zero, L_8000B410
    if (ctx->r2 == 0) {
        // 0x8000B408: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000B410;
    }
    // 0x8000B408: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000B40C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000B410:
    // 0x8000B410: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000B414: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000B418: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000B41C:
    // 0x8000B41C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000B420: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000B424:
    // 0x8000B424: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000B428: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000B42C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000B430: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000B434: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000B438: bnel        $v0, $zero, L_8000B440
    if (ctx->r2 != 0) {
        // 0x8000B43C: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000B440;
    }
    goto skip_15;
    // 0x8000B43C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_15:
L_8000B440:
    // 0x8000B440: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000B444: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000B448: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000B44C: bne         $v0, $zero, L_8000B45C
    if (ctx->r2 != 0) {
        // 0x8000B450: nop
    
            goto L_8000B45C;
    }
    // 0x8000B450: nop

    // 0x8000B454: j           L_8000B474
    // 0x8000B458: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000B474;
    // 0x8000B458: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000B45C:
    // 0x8000B45C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000B460: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000B464: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000B468: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000B46C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000B470: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000B474:
    // 0x8000B474: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000B478: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000B47C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000B480: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000B484: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000B488: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000B48C: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000B490: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000B494: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B498: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x8000B49C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000B4A0: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000B4A4: sw          $s6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r22;
L_8000B4A8:
    // 0x8000B4A8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8000B4AC: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // 0x8000B4B0: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8000B4B4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x8000B4B8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8000B4BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B4C0: sw          $v1, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r3;
    // 0x8000B4C4: bne         $s0, $zero, L_8000B39C
    if (ctx->r16 != 0) {
        // 0x8000B4C8: nop
    
            goto L_8000B39C;
    }
    // 0x8000B4C8: nop

    // 0x8000B4CC: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_8000B4D0:
    // 0x8000B4D0: bgez        $s2, L_8000B390
    if (SIGNED(ctx->r18) >= 0) {
        // 0x8000B4D4: addiu       $s1, $s1, -0x4
        ctx->r17 = ADD32(ctx->r17, -0X4);
            goto L_8000B390;
    }
    // 0x8000B4D4: addiu       $s1, $s1, -0x4
    ctx->r17 = ADD32(ctx->r17, -0X4);
    // 0x8000B4D8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B4DC: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
    // 0x8000B4E0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000B4E4: lw          $v0, 0x7C00($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7C00);
    // 0x8000B4E8: addiu       $fp, $fp, 0x180
    ctx->r30 = ADD32(ctx->r30, 0X180);
    // 0x8000B4EC: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8000B4F0: addiu       $a1, $a1, 0x180
    ctx->r5 = ADD32(ctx->r5, 0X180);
    // 0x8000B4F4: slt         $v0, $s7, $v0
    ctx->r2 = SIGNED(ctx->r23) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000B4F8: bne         $v0, $zero, L_8000AA20
    if (ctx->r2 != 0) {
        // 0x8000B4FC: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_8000AA20;
    }
    // 0x8000B4FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
L_8000B500:
    // 0x8000B500: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000B504: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000B508: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000B50C: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x8000B510: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000B514: bne         $v0, $zero, L_8000B600
    if (ctx->r2 != 0) {
        // 0x8000B518: lui         $v0, 0xB500
        ctx->r2 = S32(0XB500 << 16);
            goto L_8000B600;
    }
    // 0x8000B518: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x8000B51C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000B520: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000B524: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000B528: bne         $a0, $zero, L_8000B588
    if (ctx->r4 != 0) {
        // 0x8000B52C: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8000B588;
    }
    // 0x8000B52C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000B530: jal         0x8002221C
    // 0x8000B534: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_9;
    // 0x8000B534: nop

    after_9:
    // 0x8000B538: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000B53C: beq         $a0, $zero, L_8000B580
    if (ctx->r4 == 0) {
        // 0x8000B540: nop
    
            goto L_8000B580;
    }
    // 0x8000B540: nop

    // 0x8000B544: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000B548: beq         $v0, $zero, L_8000B560
    if (ctx->r2 == 0) {
        // 0x8000B54C: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000B560;
    }
    // 0x8000B54C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000B550:
    // 0x8000B550: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000B554: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000B558: bne         $v0, $zero, L_8000B550
    if (ctx->r2 != 0) {
        // 0x8000B55C: nop
    
            goto L_8000B550;
    }
    // 0x8000B55C: nop

L_8000B560:
    // 0x8000B560: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000B564: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000B568: beq         $v0, $zero, L_8000B574
    if (ctx->r2 == 0) {
        // 0x8000B56C: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000B574;
    }
    // 0x8000B56C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000B570: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000B574:
    // 0x8000B574: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000B578: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000B57C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000B580:
    // 0x8000B580: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000B584: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000B588:
    // 0x8000B588: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000B58C: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000B590: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000B594: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000B598: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000B59C: bnel        $v0, $zero, L_8000B5A4
    if (ctx->r2 != 0) {
        // 0x8000B5A0: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000B5A4;
    }
    goto skip_16;
    // 0x8000B5A0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_16:
L_8000B5A4:
    // 0x8000B5A4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000B5A8: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000B5AC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000B5B0: bne         $v0, $zero, L_8000B5C0
    if (ctx->r2 != 0) {
        // 0x8000B5B4: nop
    
            goto L_8000B5C0;
    }
    // 0x8000B5B4: nop

    // 0x8000B5B8: j           L_8000B5D8
    // 0x8000B5BC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000B5D8;
    // 0x8000B5BC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000B5C0:
    // 0x8000B5C0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000B5C4: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000B5C8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000B5CC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000B5D0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000B5D4: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000B5D8:
    // 0x8000B5D8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000B5DC: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000B5E0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000B5E4: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000B5E8: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000B5EC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000B5F0: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000B5F4: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000B5F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B5FC: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_8000B600:
    // 0x8000B600: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000B604: lw          $a0, -0x23A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X23A8);
    // 0x8000B608: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000B60C: addiu       $v1, $a0, 0x8
    ctx->r3 = ADD32(ctx->r4, 0X8);
    // 0x8000B610: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B614: sw          $v1, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r3;
    // 0x8000B618: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B61C: sw          $a0, -0x23B0($at)
    MEM_W(-0X23B0, ctx->r1) = ctx->r4;
    // 0x8000B620: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8000B624: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8000B628: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8000B62C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8000B630: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8000B634: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8000B638: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8000B63C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8000B640: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8000B644: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000B648: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8000B64C: jr          $ra
    // 0x8000B650: nop

    return;
    // 0x8000B650: nop

;}
RECOMP_FUNC void initRenderStateArrays(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B654: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000B658: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000B65C: jal         0x8000A8A0
    // 0x8000B660: nop

    beginFrameDLChunk(rdram, ctx);
        goto after_0;
    // 0x8000B660: nop

    after_0:
    // 0x8000B664: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000B668: addiu       $v0, $v0, -0x2B68
    ctx->r2 = ADD32(ctx->r2, -0X2B68);
    // 0x8000B66C: addiu       $a2, $v0, 0x100
    ctx->r6 = ADD32(ctx->r2, 0X100);
    // 0x8000B670: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8000B674: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000B678: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8000B67C: sw          $zero, -0x7394($at)
    MEM_W(-0X7394, ctx->r1) = 0;
    // 0x8000B680: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000B684: sw          $zero, 0x43A0($at)
    MEM_W(0X43A0, ctx->r1) = 0;
L_8000B688:
    // 0x8000B688: addiu       $v0, $zero, 0x3F
    ctx->r2 = ADD32(0, 0X3F);
    // 0x8000B68C: addiu       $v1, $a0, 0xFC
    ctx->r3 = ADD32(ctx->r4, 0XFC);
L_8000B690:
    // 0x8000B690: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8000B694: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000B698: bgez        $v0, L_8000B690
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000B69C: addiu       $v1, $v1, -0x4
        ctx->r3 = ADD32(ctx->r3, -0X4);
            goto L_8000B690;
    }
    // 0x8000B69C: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8000B6A0: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
    // 0x8000B6A4: addiu       $v1, $a2, 0x7C
    ctx->r3 = ADD32(ctx->r6, 0X7C);
L_8000B6A8:
    // 0x8000B6A8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8000B6AC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000B6B0: bgez        $v0, L_8000B6A8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000B6B4: addiu       $v1, $v1, -0x4
        ctx->r3 = ADD32(ctx->r3, -0X4);
            goto L_8000B6A8;
    }
    // 0x8000B6B4: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8000B6B8: addiu       $a2, $a2, 0x180
    ctx->r6 = ADD32(ctx->r6, 0X180);
    // 0x8000B6BC: addiu       $a1, $a1, 0x180
    ctx->r5 = ADD32(ctx->r5, 0X180);
    // 0x8000B6C0: slti        $v0, $a1, 0x600
    ctx->r2 = SIGNED(ctx->r5) < 0X600 ? 1 : 0;
    // 0x8000B6C4: bne         $v0, $zero, L_8000B688
    if (ctx->r2 != 0) {
        // 0x8000B6C8: addiu       $a0, $a0, 0x180
        ctx->r4 = ADD32(ctx->r4, 0X180);
            goto L_8000B688;
    }
    // 0x8000B6C8: addiu       $a0, $a0, 0x180
    ctx->r4 = ADD32(ctx->r4, 0X180);
    // 0x8000B6CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B6D0: sw          $zero, -0x5BA0($at)
    MEM_W(-0X5BA0, ctx->r1) = 0;
    // 0x8000B6D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B6D8: sw          $zero, -0x5B58($at)
    MEM_W(-0X5B58, ctx->r1) = 0;
    // 0x8000B6DC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000B6E0: sw          $zero, 0x7C00($at)
    MEM_W(0X7C00, ctx->r1) = 0;
    // 0x8000B6E4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8000B6E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000B6EC: jr          $ra
    // 0x8000B6F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000B6F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void drawFrameProfilerBars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B6F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000B6F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000B6FC: jal         0x8000A8A0
    // 0x8000B700: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    beginFrameDLChunk(rdram, ctx);
        goto after_0;
    // 0x8000B700: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8000B704: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000B708: lw          $a0, -0x23B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X23B0);
    // 0x8000B70C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000B710: lw          $a1, -0x56EC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X56EC);
    // 0x8000B714: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000B718: lhu         $a2, -0x56F0($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X56F0);
    // 0x8000B71C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8000B720: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    // 0x8000B724: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000B728: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8000B72C: addiu       $a2, $a2, -0x28
    ctx->r6 = ADD32(ctx->r6, -0X28);
    // 0x8000B730: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8000B734: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B738: sw          $a0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r4;
    // 0x8000B73C: jal         0x80023D40
    // 0x8000B740: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    emitProfilerBarSegment(rdram, ctx);
        goto after_1;
    // 0x8000B740: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    after_1:
    // 0x8000B744: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8000B748: lw          $a1, -0x7120($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7120);
    // 0x8000B74C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000B750: lhu         $a2, -0x56F0($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X56F0);
    // 0x8000B754: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000B758: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8000B75C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B760: sw          $a0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r4;
    // 0x8000B764: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8000B768: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000B76C: addiu       $a2, $a2, -0x23
    ctx->r6 = ADD32(ctx->r6, -0X23);
    // 0x8000B770: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8000B774: jal         0x80023D40
    // 0x8000B778: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    emitProfilerBarSegment(rdram, ctx);
        goto after_2;
    // 0x8000B778: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    after_2:
    // 0x8000B77C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8000B780: lw          $a1, -0x7124($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7124);
    // 0x8000B784: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000B788: lhu         $a2, -0x56F0($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X56F0);
    // 0x8000B78C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000B790: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8000B794: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B798: sw          $a0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r4;
    // 0x8000B79C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8000B7A0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8000B7A4: addiu       $a2, $a2, -0x1E
    ctx->r6 = ADD32(ctx->r6, -0X1E);
    // 0x8000B7A8: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8000B7AC: jal         0x80023D40
    // 0x8000B7B0: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    emitProfilerBarSegment(rdram, ctx);
        goto after_3;
    // 0x8000B7B0: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    after_3:
    // 0x8000B7B4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000B7B8: lw          $a1, -0x56E0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X56E0);
    // 0x8000B7BC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000B7C0: lhu         $a2, -0x56F0($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X56F0);
    // 0x8000B7C4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000B7C8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8000B7CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B7D0: sw          $a0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r4;
    // 0x8000B7D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8000B7D8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000B7DC: addiu       $a2, $a2, -0x19
    ctx->r6 = ADD32(ctx->r6, -0X19);
    // 0x8000B7E0: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8000B7E4: jal         0x80023D40
    // 0x8000B7E8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    emitProfilerBarSegment(rdram, ctx);
        goto after_4;
    // 0x8000B7E8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    after_4:
    // 0x8000B7EC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000B7F0: lw          $a1, -0x23AC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X23AC);
    // 0x8000B7F4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000B7F8: lhu         $a2, -0x56F0($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X56F0);
    // 0x8000B7FC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000B800: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8000B804: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B808: sw          $a0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r4;
    // 0x8000B80C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000B810: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000B814: addiu       $a2, $a2, -0x14
    ctx->r6 = ADD32(ctx->r6, -0X14);
    // 0x8000B818: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8000B81C: jal         0x80023D40
    // 0x8000B820: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    emitProfilerBarSegment(rdram, ctx);
        goto after_5;
    // 0x8000B820: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    after_5:
    // 0x8000B824: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000B828: lw          $a1, -0x23B4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X23B4);
    // 0x8000B82C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000B830: lhu         $a2, -0x56F0($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X56F0);
    // 0x8000B834: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000B838: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8000B83C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B840: sw          $a0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r4;
    // 0x8000B844: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000B848: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8000B84C: addiu       $a2, $a2, -0xF
    ctx->r6 = ADD32(ctx->r6, -0XF);
    // 0x8000B850: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8000B854: jal         0x80023D40
    // 0x8000B858: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    emitProfilerBarSegment(rdram, ctx);
        goto after_6;
    // 0x8000B858: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    after_6:
    // 0x8000B85C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000B860: lw          $a1, -0x56E8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X56E8);
    // 0x8000B864: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000B868: lhu         $a2, -0x56F0($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X56F0);
    // 0x8000B86C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000B870: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8000B874: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B878: sw          $a0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r4;
    // 0x8000B87C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000B880: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000B884: addiu       $a2, $a2, -0xA
    ctx->r6 = ADD32(ctx->r6, -0XA);
    // 0x8000B888: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8000B88C: jal         0x80023D40
    // 0x8000B890: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    emitProfilerBarSegment(rdram, ctx);
        goto after_7;
    // 0x8000B890: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    after_7:
    // 0x8000B894: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000B898: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B89C: sw          $a0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r4;
    // 0x8000B8A0: jal         0x80024130
    // 0x8000B8A4: nop

    func_80024130(rdram, ctx);
        goto after_8;
    // 0x8000B8A4: nop

    after_8:
    // 0x8000B8A8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000B8AC: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x8000B8B0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000B8B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B8B8: sw          $a0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r4;
    // 0x8000B8BC: sltu        $v1, $a0, $v1
    ctx->r3 = ctx->r4 < ctx->r3 ? 1 : 0;
    // 0x8000B8C0: bne         $v1, $zero, L_8000B9AC
    if (ctx->r3 != 0) {
        // 0x8000B8C4: lui         $v0, 0xB500
        ctx->r2 = S32(0XB500 << 16);
            goto L_8000B9AC;
    }
    // 0x8000B8C4: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x8000B8C8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8000B8CC: lw          $a1, 0x63B0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X63B0);
    // 0x8000B8D0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8000B8D4: bne         $a1, $zero, L_8000B934
    if (ctx->r5 != 0) {
        // 0x8000B8D8: sw          $zero, 0x4($a0)
        MEM_W(0X4, ctx->r4) = 0;
            goto L_8000B934;
    }
    // 0x8000B8D8: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8000B8DC: jal         0x8002221C
    // 0x8000B8E0: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_9;
    // 0x8000B8E0: nop

    after_9:
    // 0x8000B8E4: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8000B8E8: beq         $a1, $zero, L_8000B92C
    if (ctx->r5 == 0) {
        // 0x8000B8EC: nop
    
            goto L_8000B92C;
    }
    // 0x8000B8EC: nop

    // 0x8000B8F0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8000B8F4: beq         $v0, $zero, L_8000B90C
    if (ctx->r2 == 0) {
        // 0x8000B8F8: addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
            goto L_8000B90C;
    }
    // 0x8000B8F8: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
L_8000B8FC:
    // 0x8000B8FC: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000B900: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000B904: bne         $v0, $zero, L_8000B8FC
    if (ctx->r2 != 0) {
        // 0x8000B908: nop
    
            goto L_8000B8FC;
    }
    // 0x8000B908: nop

L_8000B90C:
    // 0x8000B90C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000B910: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000B914: beq         $v0, $zero, L_8000B920
    if (ctx->r2 == 0) {
        // 0x8000B918: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000B920;
    }
    // 0x8000B918: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000B91C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000B920:
    // 0x8000B920: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000B924: sw          $a1, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r5;
    // 0x8000B928: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_8000B92C:
    // 0x8000B92C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8000B930: lw          $a1, 0x63B0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X63B0);
L_8000B934:
    // 0x8000B934: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000B938: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000B93C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000B940: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000B944: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000B948: bnel        $v0, $zero, L_8000B950
    if (ctx->r2 != 0) {
        // 0x8000B94C: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000B950;
    }
    goto skip_0;
    // 0x8000B94C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_0:
L_8000B950:
    // 0x8000B950: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000B954: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000B958: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000B95C: bne         $v0, $zero, L_8000B96C
    if (ctx->r2 != 0) {
        // 0x8000B960: addu        $a0, $a1, $zero
        ctx->r4 = ADD32(ctx->r5, 0);
            goto L_8000B96C;
    }
    // 0x8000B960: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x8000B964: j           L_8000B984
    // 0x8000B968: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000B984;
    // 0x8000B968: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000B96C:
    // 0x8000B96C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000B970: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000B974: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000B978: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000B97C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000B980: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000B984:
    // 0x8000B984: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000B988: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000B98C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000B990: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000B994: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000B998: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000B99C: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000B9A0: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000B9A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B9A8: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_8000B9AC:
    // 0x8000B9AC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000B9B0: lw          $a1, -0x23A8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X23A8);
    // 0x8000B9B4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000B9B8: lw          $a0, 0x63D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63D4);
    // 0x8000B9BC: lui         $v0, 0xE900
    ctx->r2 = S32(0XE900 << 16);
    // 0x8000B9C0: addiu       $v1, $a1, 0x8
    ctx->r3 = ADD32(ctx->r5, 0X8);
    // 0x8000B9C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B9C8: sw          $v1, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r3;
    // 0x8000B9CC: sltu        $v1, $v1, $a0
    ctx->r3 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x8000B9D0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8000B9D4: bne         $v1, $zero, L_8000BAC4
    if (ctx->r3 != 0) {
        // 0x8000B9D8: sw          $zero, 0x4($a1)
        MEM_W(0X4, ctx->r5) = 0;
            goto L_8000BAC4;
    }
    // 0x8000B9D8: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8000B9DC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000B9E0: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000B9E4: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x8000B9E8: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x8000B9EC: bne         $a0, $zero, L_8000BA4C
    if (ctx->r4 != 0) {
        // 0x8000B9F0: sw          $zero, 0xC($a1)
        MEM_W(0XC, ctx->r5) = 0;
            goto L_8000BA4C;
    }
    // 0x8000B9F0: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x8000B9F4: jal         0x8002221C
    // 0x8000B9F8: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_10;
    // 0x8000B9F8: nop

    after_10:
    // 0x8000B9FC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000BA00: beq         $a0, $zero, L_8000BA44
    if (ctx->r4 == 0) {
        // 0x8000BA04: nop
    
            goto L_8000BA44;
    }
    // 0x8000BA04: nop

    // 0x8000BA08: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000BA0C: beq         $v0, $zero, L_8000BA24
    if (ctx->r2 == 0) {
        // 0x8000BA10: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000BA24;
    }
    // 0x8000BA10: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000BA14:
    // 0x8000BA14: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000BA18: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000BA1C: bne         $v0, $zero, L_8000BA14
    if (ctx->r2 != 0) {
        // 0x8000BA20: nop
    
            goto L_8000BA14;
    }
    // 0x8000BA20: nop

L_8000BA24:
    // 0x8000BA24: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000BA28: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000BA2C: beq         $v0, $zero, L_8000BA38
    if (ctx->r2 == 0) {
        // 0x8000BA30: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000BA38;
    }
    // 0x8000BA30: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000BA34: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000BA38:
    // 0x8000BA38: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000BA3C: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000BA40: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000BA44:
    // 0x8000BA44: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000BA48: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000BA4C:
    // 0x8000BA4C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000BA50: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000BA54: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000BA58: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000BA5C: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000BA60: bnel        $v0, $zero, L_8000BA68
    if (ctx->r2 != 0) {
        // 0x8000BA64: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000BA68;
    }
    goto skip_1;
    // 0x8000BA64: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_1:
L_8000BA68:
    // 0x8000BA68: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000BA6C: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000BA70: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000BA74: bne         $v0, $zero, L_8000BA84
    if (ctx->r2 != 0) {
        // 0x8000BA78: nop
    
            goto L_8000BA84;
    }
    // 0x8000BA78: nop

    // 0x8000BA7C: j           L_8000BA9C
    // 0x8000BA80: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000BA9C;
    // 0x8000BA80: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000BA84:
    // 0x8000BA84: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000BA88: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000BA8C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000BA90: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000BA94: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000BA98: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000BA9C:
    // 0x8000BA9C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000BAA0: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000BAA4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000BAA8: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000BAAC: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000BAB0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000BAB4: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000BAB8: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000BABC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BAC0: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_8000BAC4:
    // 0x8000BAC4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000BAC8: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000BACC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000BAD0: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8000BAD4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BAD8: sw          $a0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r4;
    // 0x8000BADC: lui         $a0, 0xB800
    ctx->r4 = S32(0XB800 << 16);
    // 0x8000BAE0: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000BAE4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000BAE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BAEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000BAF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000BAF4: jr          $ra
    // 0x8000BAF8: nop

    return;
    // 0x8000BAF8: nop

;}
RECOMP_FUNC void func_8000BAFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BAFC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000BB00: lhu         $v0, -0x202A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X202A);
    // 0x8000BB04: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8000BB08: blez        $v0, L_8000BB34
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000BB0C: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_8000BB34;
    }
    // 0x8000BB0C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8000BB10: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x8000BB14: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000BB18: addiu       $v1, $v1, -0x1FF0
    ctx->r3 = ADD32(ctx->r3, -0X1FF0);
L_8000BB1C:
    // 0x8000BB1C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000BB20: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000BB24: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x8000BB28: slt         $v0, $a2, $a3
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8000BB2C: bne         $v0, $zero, L_8000BB1C
    if (ctx->r2 != 0) {
        // 0x8000BB30: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8000BB1C;
    }
    // 0x8000BB30: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8000BB34:
    // 0x8000BB34: lui         $a3, 0x300
    ctx->r7 = S32(0X300 << 16);
    // 0x8000BB38: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8000BB3C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8000BB40: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8000BB44: and         $v0, $v0, $a3
    ctx->r2 = ctx->r2 & ctx->r7;
    // 0x8000BB48: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x8000BB4C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000BB50: lhu         $a0, -0x2A64($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X2A64);
    // 0x8000BB54: or          $a3, $v0, $v1
    ctx->r7 = ctx->r2 | ctx->r3;
    // 0x8000BB58: blez        $a0, L_8000BBA4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8000BB5C: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_8000BBA4;
    }
    // 0x8000BB5C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8000BB60: lui         $t0, 0xFCFF
    ctx->r8 = S32(0XFCFF << 16);
    // 0x8000BB64: ori         $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 | 0XFFFF;
    // 0x8000BB68: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8000BB6C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000BB70: addiu       $a0, $a0, -0x20B0
    ctx->r4 = ADD32(ctx->r4, -0X20B0);
L_8000BB74:
    // 0x8000BB74: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8000BB78: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8000BB7C: and         $v0, $v0, $t0
    ctx->r2 = ctx->r2 & ctx->r8;
    // 0x8000BB80: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8000BB84: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8000BB88: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8000BB8C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000BB90: or          $v0, $v0, $a3
    ctx->r2 = ctx->r2 | ctx->r7;
    // 0x8000BB94: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8000BB98: slt         $v0, $a2, $a1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000BB9C: bne         $v0, $zero, L_8000BB74
    if (ctx->r2 != 0) {
        // 0x8000BBA0: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8000BB74;
    }
    // 0x8000BBA0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_8000BBA4:
    // 0x8000BBA4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x8000BBA8: jr          $ra
    // 0x8000BBAC: nop

    return;
    // 0x8000BBAC: nop

;}
RECOMP_FUNC void func_8000BBB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BBB0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000BBB4: lw          $v1, -0x5700($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5700);
    // 0x8000BBB8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000BBBC: bne         $v1, $v0, L_8000BBD4
    if (ctx->r3 != ctx->r2) {
        // 0x8000BBC0: nop
    
            goto L_8000BBD4;
    }
    // 0x8000BBC0: nop

    // 0x8000BBC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BBC8: sw          $zero, -0x56FC($at)
    MEM_W(-0X56FC, ctx->r1) = 0;
    // 0x8000BBCC: j           L_8000BBE8
    // 0x8000BBD0: nop

        goto L_8000BBE8;
    // 0x8000BBD0: nop

L_8000BBD4:
    // 0x8000BBD4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8000BBD8: lw          $v0, -0x7128($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7128);
    // 0x8000BBDC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8000BBE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BBE4: sw          $v0, -0x56FC($at)
    MEM_W(-0X56FC, ctx->r1) = ctx->r2;
L_8000BBE8:
    // 0x8000BBE8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8000BBEC: lw          $v0, -0x7128($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7128);
    // 0x8000BBF0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BBF4: sw          $v0, -0x5700($at)
    MEM_W(-0X5700, ctx->r1) = ctx->r2;
    // 0x8000BBF8: jr          $ra
    // 0x8000BBFC: nop

    return;
    // 0x8000BBFC: nop

;}
RECOMP_FUNC void timeSnapshotFiller(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BC00: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000BC04: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000BC08: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8000BC0C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000BC10: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8000BC14: jal         0x80019810
    // 0x8000BC18: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    awaitFrameSyncMesgBlock(rdram, ctx);
        goto after_0;
    // 0x8000BC18: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x8000BC1C: jal         0x8002BF00
    // 0x8000BC20: nop

    osGetTime_recomp(rdram, ctx);
        goto after_1;
    // 0x8000BC20: nop

    after_1:
    // 0x8000BC24: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000BC28: addiu       $a1, $a1, -0x5710
    ctx->r5 = ADD32(ctx->r5, -0X5710);
    // 0x8000BC2C: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8000BC30: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000BC34: bne         $a0, $v0, L_8000BC4C
    if (ctx->r4 != ctx->r2) {
        // 0x8000BC38: addu        $s1, $v1, $zero
        ctx->r17 = ADD32(ctx->r3, 0);
            goto L_8000BC4C;
    }
    // 0x8000BC38: addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
    // 0x8000BC3C: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x8000BC40: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8000BC44: j           L_8000BCBC
    // 0x8000BC48: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
        goto L_8000BCBC;
    // 0x8000BC48: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_8000BC4C:
    // 0x8000BC4C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000BC50: addiu       $v1, $v1, -0x5770
    ctx->r3 = ADD32(ctx->r3, -0X5770);
    // 0x8000BC54: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000BC58: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000BC5C: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8000BC60: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000BC64: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000BC68: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8000BC6C: subu        $v0, $s1, $v0
    ctx->r2 = SUB32(ctx->r17, ctx->r2);
    // 0x8000BC70: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8000BC74: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x8000BC78: bgez        $v0, L_8000BC8C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000BC7C: nop
    
            goto L_8000BC8C;
    }
    // 0x8000BC7C: nop

    // 0x8000BC80: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000BC84: ldc1        $f0, 0x520($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X520);
    // 0x8000BC88: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
L_8000BC8C:
    // 0x8000BC8C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8000BC90: lw          $v0, -0x6EFC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6EFC);
    // 0x8000BC94: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8000BC98: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x8000BC9C: bgez        $v0, L_8000BCB0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000BCA0: cvt.s.d     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f4.fl = CVT_S_D(ctx->f4.d);
            goto L_8000BCB0;
    }
    // 0x8000BCA0: cvt.s.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f4.fl = CVT_S_D(ctx->f4.d);
    // 0x8000BCA4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000BCA8: ldc1        $f0, 0x528($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X528);
    // 0x8000BCAC: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
L_8000BCB0:
    // 0x8000BCB0: cvt.s.d     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
    // 0x8000BCB4: div.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8000BCB8: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_8000BCBC:
    // 0x8000BCBC: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x8000BCC0: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8000BCC4: jal         0x8001BCA0
    // 0x8000BCC8: addiu       $a2, $sp, 0x14
    ctx->r6 = ADD32(ctx->r29, 0X14);
    func_8001BCA0(rdram, ctx);
        goto after_2;
    // 0x8000BCC8: addiu       $a2, $sp, 0x14
    ctx->r6 = ADD32(ctx->r29, 0X14);
    after_2:
    // 0x8000BCCC: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x8000BCD0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000BCD4: addiu       $v1, $v1, -0x5708
    ctx->r3 = ADD32(ctx->r3, -0X5708);
    // 0x8000BCD8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8000BCDC: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x8000BCE0: bgez        $v0, L_8000BCF4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000BCE4: nop
    
            goto L_8000BCF4;
    }
    // 0x8000BCE4: nop

    // 0x8000BCE8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000BCEC: ldc1        $f0, 0x530($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X530);
    // 0x8000BCF0: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
L_8000BCF4:
    // 0x8000BCF4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000BCF8: addiu       $a0, $a0, -0x6EFC
    ctx->r4 = ADD32(ctx->r4, -0X6EFC);
    // 0x8000BCFC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000BD00: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8000BD04: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x8000BD08: bgez        $v0, L_8000BD1C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000BD0C: cvt.s.d     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f4.fl = CVT_S_D(ctx->f4.d);
            goto L_8000BD1C;
    }
    // 0x8000BD0C: cvt.s.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f4.fl = CVT_S_D(ctx->f4.d);
    // 0x8000BD10: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000BD14: ldc1        $f0, 0x538($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X538);
    // 0x8000BD18: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
L_8000BD1C:
    // 0x8000BD1C: cvt.s.d     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
    // 0x8000BD20: div.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8000BD24: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x8000BD28: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8000BD2C: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x8000BD30: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8000BD34: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8000BD38: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x8000BD3C: bgez        $v0, L_8000BD50
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000BD40: swc1        $f2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
            goto L_8000BD50;
    }
    // 0x8000BD40: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    // 0x8000BD44: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000BD48: ldc1        $f0, 0x540($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X540);
    // 0x8000BD4C: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
L_8000BD50:
    // 0x8000BD50: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000BD54: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8000BD58: cvt.d.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.d = CVT_D_W(ctx->f6.u32l);
    // 0x8000BD5C: bgez        $v0, L_8000BD70
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000BD60: cvt.s.d     $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
            goto L_8000BD70;
    }
    // 0x8000BD60: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x8000BD64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000BD68: ldc1        $f0, 0x548($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X548);
    // 0x8000BD6C: add.d       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f6.d + ctx->f0.d;
L_8000BD70:
    // 0x8000BD70: cvt.s.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f6.fl = CVT_S_D(ctx->f6.d);
    // 0x8000BD74: div.s       $f6, $f2, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8000BD78: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000BD7C: lwc1        $f0, 0x550($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X550);
    // 0x8000BD80: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x8000BD84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BD88: lwc1        $f4, -0x570C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X570C);
    // 0x8000BD8C: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8000BD90: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8000BD94: div.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8000BD98: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8000BD9C: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8000BDA0: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x8000BDA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BDA8: swc1        $f4, -0x570C($at)
    MEM_W(-0X570C, ctx->r1) = ctx->f4.u32l;
    // 0x8000BDAC: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
    // 0x8000BDB0: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8000BDB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BDB8: lwc1        $f2, -0x570C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X570C);
    // 0x8000BDBC: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8000BDC0: jal         0x80002710
    // 0x8000BDC4: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    getViModePeriod(rdram, ctx);
        goto after_3;
    // 0x8000BDC4: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    after_3:
    // 0x8000BDC8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000BDCC: lwc1        $f2, 0x554($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X554);
    // 0x8000BDD0: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8000BDD4: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x8000BDD8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000BDDC: lbu         $v0, -0x5737($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5737);
    // 0x8000BDE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BDE4: sw          $s1, -0x5710($at)
    MEM_W(-0X5710, ctx->r1) = ctx->r17;
    // 0x8000BDE8: beq         $v0, $zero, L_8000BEE8
    if (ctx->r2 == 0) {
        // 0x8000BDEC: nop
    
            goto L_8000BEE8;
    }
    // 0x8000BDEC: nop

    // 0x8000BDF0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000BDF4: lbu         $v0, -0x5738($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5738);
    // 0x8000BDF8: beq         $v0, $zero, L_8000BEE8
    if (ctx->r2 == 0) {
        // 0x8000BDFC: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8000BEE8;
    }
    // 0x8000BDFC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000BE00: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000BE04: lw          $v1, -0x5700($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5700);
    // 0x8000BE08: bne         $v1, $v0, L_8000BE1C
    if (ctx->r3 != ctx->r2) {
        // 0x8000BE0C: nop
    
            goto L_8000BE1C;
    }
    // 0x8000BE0C: nop

    // 0x8000BE10: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000BE14: j           L_8000BF38
    // 0x8000BE18: nop

        goto L_8000BF38;
    // 0x8000BE18: nop

L_8000BE1C:
    // 0x8000BE1C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8000BE20: lw          $v0, -0x7128($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7128);
    // 0x8000BE24: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8000BE28: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8000BE2C: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x8000BE30: bgez        $v0, L_8000BE44
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000BE34: nop
    
            goto L_8000BE44;
    }
    // 0x8000BE34: nop

    // 0x8000BE38: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000BE3C: ldc1        $f0, 0x558($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X558);
    // 0x8000BE40: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
L_8000BE44:
    // 0x8000BE44: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8000BE48: lw          $v0, -0x6EFC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6EFC);
    // 0x8000BE4C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8000BE50: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x8000BE54: bgez        $v0, L_8000BE68
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000BE58: cvt.s.d     $f2, $f2
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
            goto L_8000BE68;
    }
    // 0x8000BE58: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x8000BE5C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000BE60: ldc1        $f0, 0x560($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X560);
    // 0x8000BE64: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
L_8000BE68:
    // 0x8000BE68: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8000BE6C: lbu         $v0, -0x7151($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7151);
    // 0x8000BE70: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8000BE74: lbu         $v1, -0x7152($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X7152);
    // 0x8000BE78: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x8000BE7C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8000BE80: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8000BE84: bne         $v0, $zero, L_8000BEC8
    if (ctx->r2 != 0) {
        // 0x8000BE88: div.s       $f20, $f2, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
            goto L_8000BEC8;
    }
    // 0x8000BE88: div.s       $f20, $f2, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8000BE8C: jal         0x80002710
    // 0x8000BE90: nop

    getViModePeriod(rdram, ctx);
        goto after_4;
    // 0x8000BE90: nop

    after_4:
    // 0x8000BE94: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000BE98: lwc1        $f2, 0x568($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X568);
    // 0x8000BE9C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8000BEA0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8000BEA4: lbu         $v0, -0x7151($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7151);
    // 0x8000BEA8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8000BEAC: lbu         $v1, -0x7152($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X7152);
    // 0x8000BEB0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8000BEB4: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8000BEB8: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8000BEBC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8000BEC0: j           L_8000BEDC
    // 0x8000BEC4: nop

        goto L_8000BEDC;
    // 0x8000BEC4: nop

L_8000BEC8:
    // 0x8000BEC8: jal         0x80002710
    // 0x8000BECC: nop

    getViModePeriod(rdram, ctx);
        goto after_5;
    // 0x8000BECC: nop

    after_5:
    // 0x8000BED0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000BED4: lwc1        $f2, 0x56C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X56C);
    // 0x8000BED8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
L_8000BEDC:
    // 0x8000BEDC: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x8000BEE0: j           L_8000BF38
    // 0x8000BEE4: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
        goto L_8000BF38;
    // 0x8000BEE4: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_8000BEE8:
    // 0x8000BEE8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000BEEC: lw          $v0, -0x56FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X56FC);
    // 0x8000BEF0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8000BEF4: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x8000BEF8: bgez        $v0, L_8000BF0C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000BEFC: nop
    
            goto L_8000BF0C;
    }
    // 0x8000BEFC: nop

    // 0x8000BF00: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000BF04: ldc1        $f0, 0x570($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X570);
    // 0x8000BF08: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
L_8000BF0C:
    // 0x8000BF0C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8000BF10: lw          $v0, -0x6EFC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6EFC);
    // 0x8000BF14: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8000BF18: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x8000BF1C: bgez        $v0, L_8000BF30
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000BF20: cvt.s.d     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f4.fl = CVT_S_D(ctx->f4.d);
            goto L_8000BF30;
    }
    // 0x8000BF20: cvt.s.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f4.fl = CVT_S_D(ctx->f4.d);
    // 0x8000BF24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000BF28: ldc1        $f0, 0x578($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X578);
    // 0x8000BF2C: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
L_8000BF30:
    // 0x8000BF30: cvt.s.d     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
    // 0x8000BF34: div.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
L_8000BF38:
    // 0x8000BF38: jal         0x8001983C
    // 0x8000BF3C: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    signalFrameSyncMesgNonblock(rdram, ctx);
        goto after_6;
    // 0x8000BF3C: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    after_6:
    // 0x8000BF40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000BF44: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8000BF48: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BF4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000BF50: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8000BF54: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8000BF58: jr          $ra
    // 0x8000BF5C: nop

    return;
    // 0x8000BF5C: nop

;}
RECOMP_FUNC void bufferArbiterProducerScanWait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BF60: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000BF64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000BF68: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8000BF6C: addiu       $s0, $s0, -0x5762
    ctx->r16 = ADD32(ctx->r16, -0X5762);
    // 0x8000BF70: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x8000BF74: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000BF78: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000BF7C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000BF80: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8000BF84: beq         $v0, $zero, L_8000BFA8
    if (ctx->r2 == 0) {
        // 0x8000BF88: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8000BFA8;
    }
    // 0x8000BF88: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8000BF8C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000BF90: addiu       $a0, $a0, -0x57E8
    ctx->r4 = ADD32(ctx->r4, -0X57E8);
    // 0x8000BF94: jal         0x800331D0
    // 0x8000BF98: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8000BF98: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_0:
    // 0x8000BF9C: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8000BFA0: jal         0x80037510
    // 0x8000BFA4: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_1;
    // 0x8000BFA4: nop

    after_1:
L_8000BFA8:
    // 0x8000BFA8: jal         0x8001BEC8
    // 0x8000BFAC: nop

    bufferArbiterMarkSlotReady(rdram, ctx);
        goto after_2;
    // 0x8000BFAC: nop

    after_2:
    // 0x8000BFB0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000BFB4: lbu         $v0, -0x5763($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5763);
    // 0x8000BFB8: beq         $v0, $zero, L_8000BFE0
    if (ctx->r2 == 0) {
        // 0x8000BFBC: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8000BFE0;
    }
    // 0x8000BFBC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8000BFC0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000BFC4: addiu       $a0, $a0, -0x5818
    ctx->r4 = ADD32(ctx->r4, -0X5818);
    // 0x8000BFC8: jal         0x800331D0
    // 0x8000BFCC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x8000BFCC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_3:
    // 0x8000BFD0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BFD4: sb          $zero, -0x5763($at)
    MEM_B(-0X5763, ctx->r1) = 0;
    // 0x8000BFD8: jal         0x80037510
    // 0x8000BFDC: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_4;
    // 0x8000BFDC: nop

    after_4:
L_8000BFE0:
    // 0x8000BFE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BFE4: sb          $zero, -0x5766($at)
    MEM_B(-0X5766, ctx->r1) = 0;
    // 0x8000BFE8: jal         0x8001BCE4
    // 0x8000BFEC: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    bufferArbiterProducerMark(rdram, ctx);
        goto after_5;
    // 0x8000BFEC: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    after_5:
    // 0x8000BFF0: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8000BFF4: addiu       $s3, $s3, -0x7153
    ctx->r19 = ADD32(ctx->r19, -0X7153);
    // 0x8000BFF8: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_8000BFFC:
    // 0x8000BFFC: jal         0x8001BE80
    // 0x8000C000: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    waitOnVideoQueue(rdram, ctx);
        goto after_6;
    // 0x8000C000: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    after_6:
    // 0x8000C004: jal         0x80019810
    // 0x8000C008: nop

    awaitFrameSyncMesgBlock(rdram, ctx);
        goto after_7;
    // 0x8000C008: nop

    after_7:
    // 0x8000C00C: lbu         $v0, 0x0($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X0);
    // 0x8000C010: beq         $v0, $zero, L_8000C044
    if (ctx->r2 == 0) {
        // 0x8000C014: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8000C044;
    }
    // 0x8000C014: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_8000C018:
    // 0x8000C018: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8000C01C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8000C020: lbu         $v0, -0x7156($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X7156);
    // 0x8000C024: beq         $v0, $s2, L_8000C044
    if (ctx->r2 == ctx->r18) {
        // 0x8000C028: nop
    
            goto L_8000C044;
    }
    // 0x8000C028: nop

    // 0x8000C02C: beq         $v0, $s1, L_8000C044
    if (ctx->r2 == ctx->r17) {
        // 0x8000C030: nop
    
            goto L_8000C044;
    }
    // 0x8000C030: nop

    // 0x8000C034: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000C038: sltu        $v0, $s0, $v1
    ctx->r2 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x8000C03C: bne         $v0, $zero, L_8000C018
    if (ctx->r2 != 0) {
        // 0x8000C040: nop
    
            goto L_8000C018;
    }
    // 0x8000C040: nop

L_8000C044:
    // 0x8000C044: jal         0x8001983C
    // 0x8000C048: nop

    signalFrameSyncMesgNonblock(rdram, ctx);
        goto after_8;
    // 0x8000C048: nop

    after_8:
    // 0x8000C04C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8000C050: lbu         $v0, -0x7153($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7153);
    // 0x8000C054: bne         $s0, $v0, L_8000BFFC
    if (ctx->r16 != ctx->r2) {
        // 0x8000C058: nop
    
            goto L_8000BFFC;
    }
    // 0x8000C058: nop

    // 0x8000C05C: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8000C060: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000C064: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000C068: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C06C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000C070: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8000C074: jr          $ra
    // 0x8000C078: nop

    return;
    // 0x8000C078: nop

;}
RECOMP_FUNC void submitGfxFrame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C07C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8000C080: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x8000C084: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8000C088: jal         0x80023D08
    // 0x8000C08C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    getTimeSinceLastFrame(rdram, ctx);
        goto after_0;
    // 0x8000C08C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    after_0:
    // 0x8000C090: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000C094: addiu       $v1, $v1, -0x5762
    ctx->r3 = ADD32(ctx->r3, -0X5762);
    // 0x8000C098: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x8000C09C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C0A0: sw          $v0, -0x56EC($at)
    MEM_W(-0X56EC, ctx->r1) = ctx->r2;
    // 0x8000C0A4: beq         $v1, $zero, L_8000C0C4
    if (ctx->r3 == 0) {
        // 0x8000C0A8: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8000C0C4;
    }
    // 0x8000C0A8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8000C0AC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000C0B0: addiu       $a0, $a0, -0x57E8
    ctx->r4 = ADD32(ctx->r4, -0X57E8);
    // 0x8000C0B4: jal         0x800331D0
    // 0x8000C0B8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8000C0B8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_1:
    // 0x8000C0BC: jal         0x8001A018
    // 0x8000C0C0: nop

    yieldFromSpThread(rdram, ctx);
        goto after_2;
    // 0x8000C0C0: nop

    after_2:
L_8000C0C4:
    // 0x8000C0C4: jal         0x8001BEC8
    // 0x8000C0C8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    bufferArbiterMarkSlotReady(rdram, ctx);
        goto after_3;
    // 0x8000C0C8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    after_3:
    // 0x8000C0CC: jal         0x8000815C
    // 0x8000C0D0: nop

    drainMeshReleaseQueue(rdram, ctx);
        goto after_4;
    // 0x8000C0D0: nop

    after_4:
    // 0x8000C0D4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000C0D8: lhu         $v0, -0x202C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X202C);
    // 0x8000C0DC: blez        $v0, L_8000C110
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000C0E0: nop
    
            goto L_8000C110;
    }
    // 0x8000C0E0: nop

    // 0x8000C0E4: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x8000C0E8: addiu       $s1, $s1, -0x1F70
    ctx->r17 = ADD32(ctx->r17, -0X1F70);
L_8000C0EC:
    // 0x8000C0EC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8000C0F0: jal         0x80008550
    // 0x8000C0F4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    commitMeshDrawBatchRefs(rdram, ctx);
        goto after_5;
    // 0x8000C0F4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    after_5:
    // 0x8000C0F8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000C0FC: lhu         $v0, -0x202C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X202C);
    // 0x8000C100: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000C104: slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000C108: bne         $v0, $zero, L_8000C0EC
    if (ctx->r2 != 0) {
        // 0x8000C10C: nop
    
            goto L_8000C0EC;
    }
    // 0x8000C10C: nop

L_8000C110:
    // 0x8000C110: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000C114: lbu         $v0, -0x5767($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5767);
    // 0x8000C118: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000C11C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000C120: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000C124: lw          $v0, 0x63C8($at)
    ctx->r2 = MEM_W(ctx->r1, 0X63C8);
    // 0x8000C128: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000C12C: addiu       $v1, $v1, -0x5763
    ctx->r3 = ADD32(ctx->r3, -0X5763);
    // 0x8000C130: lbu         $s1, 0x0($v1)
    ctx->r17 = MEM_BU(ctx->r3, 0X0);
    // 0x8000C134: beq         $v0, $zero, L_8000C640
    if (ctx->r2 == 0) {
        // 0x8000C138: nop
    
            goto L_8000C640;
    }
    // 0x8000C138: nop

    // 0x8000C13C: jal         0x8001BF20
    // 0x8000C140: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    bufferArbiterAllocSlot(rdram, ctx);
        goto after_6;
    // 0x8000C140: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x8000C144: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8000C148: beq         $s0, $zero, L_8000C498
    if (ctx->r16 == 0) {
        // 0x8000C14C: nop
    
            goto L_8000C498;
    }
    // 0x8000C14C: nop

    // 0x8000C150: jal         0x80019BE4
    // 0x8000C154: nop

    getInactiveBufferIndex(rdram, ctx);
        goto after_7;
    // 0x8000C154: nop

    after_7:
    // 0x8000C158: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000C15C: lhu         $v1, -0x202A($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X202A);
    // 0x8000C160: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8000C164: blez        $v1, L_8000C190
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000C168: addu        $a3, $v0, $zero
        ctx->r7 = ADD32(ctx->r2, 0);
            goto L_8000C190;
    }
    // 0x8000C168: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x8000C16C: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x8000C170: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000C174: addiu       $v1, $v1, -0x1FF0
    ctx->r3 = ADD32(ctx->r3, -0X1FF0);
L_8000C178:
    // 0x8000C178: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000C17C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000C180: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x8000C184: slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000C188: bne         $v0, $zero, L_8000C178
    if (ctx->r2 != 0) {
        // 0x8000C18C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8000C178;
    }
    // 0x8000C18C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8000C190:
    // 0x8000C190: lui         $a2, 0x300
    ctx->r6 = S32(0X300 << 16);
    // 0x8000C194: andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // 0x8000C198: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8000C19C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8000C1A0: and         $v0, $v0, $a2
    ctx->r2 = ctx->r2 & ctx->r6;
    // 0x8000C1A4: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x8000C1A8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8000C1AC: lhu         $a1, -0x2A64($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X2A64);
    // 0x8000C1B0: or          $a2, $v0, $v1
    ctx->r6 = ctx->r2 | ctx->r3;
    // 0x8000C1B4: blez        $a1, L_8000C200
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8000C1B8: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8000C200;
    }
    // 0x8000C1B8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8000C1BC: lui         $t0, 0xFCFF
    ctx->r8 = S32(0XFCFF << 16);
    // 0x8000C1C0: ori         $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 | 0XFFFF;
    // 0x8000C1C4: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8000C1C8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8000C1CC: addiu       $a1, $a1, -0x20B0
    ctx->r5 = ADD32(ctx->r5, -0X20B0);
L_8000C1D0:
    // 0x8000C1D0: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000C1D4: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8000C1D8: and         $v0, $v0, $t0
    ctx->r2 = ctx->r2 & ctx->r8;
    // 0x8000C1DC: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8000C1E0: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000C1E4: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8000C1E8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000C1EC: or          $v0, $v0, $a2
    ctx->r2 = ctx->r2 | ctx->r6;
    // 0x8000C1F0: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8000C1F4: slt         $v0, $a0, $a3
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8000C1F8: bne         $v0, $zero, L_8000C1D0
    if (ctx->r2 != 0) {
        // 0x8000C1FC: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8000C1D0;
    }
    // 0x8000C1FC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8000C200:
    // 0x8000C200: jal         0x80035930
    // 0x8000C204: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_8;
    // 0x8000C204: nop

    after_8:
    // 0x8000C208: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000C20C: addiu       $a0, $a0, -0x5BE0
    ctx->r4 = ADD32(ctx->r4, -0X5BE0);
    // 0x8000C210: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8000C214: addiu       $a1, $a1, 0x2AE0
    ctx->r5 = ADD32(ctx->r5, 0X2AE0);
    // 0x8000C218: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000C21C: addiu       $v1, $v1, 0x25D0
    ctx->r3 = ADD32(ctx->r3, 0X25D0);
    // 0x8000C220: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000C224: addiu       $v0, $v0, 0x26A0
    ctx->r2 = ADD32(ctx->r2, 0X26A0);
    // 0x8000C228: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8000C22C: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8000C230: sw          $v0, 0x77D4($at)
    MEM_W(0X77D4, ctx->r1) = ctx->r2;
    // 0x8000C234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000C238: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8000C23C: sw          $zero, 0x77FC($at)
    MEM_W(0X77FC, ctx->r1) = 0;
    // 0x8000C240: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8000C244: sw          $v1, 0x77D0($at)
    MEM_W(0X77D0, ctx->r1) = ctx->r3;
    // 0x8000C248: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C24C: sb          $v0, -0x5762($at)
    MEM_B(-0X5762, ctx->r1) = ctx->r2;
    // 0x8000C250: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C254: sb          $v0, -0x5763($at)
    MEM_B(-0X5763, ctx->r1) = ctx->r2;
    // 0x8000C258: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x8000C25C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000C260: lw          $v1, -0x5B40($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5B40);
    // 0x8000C264: lui         $t0, 0x8003
    ctx->r8 = S32(0X8003 << 16);
    // 0x8000C268: lw          $t0, 0x77C0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X77C0);
    // 0x8000C26C: lui         $t1, 0x8003
    ctx->r9 = S32(0X8003 << 16);
    // 0x8000C270: lw          $t1, 0x77C4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X77C4);
    // 0x8000C274: lui         $a3, 0x8003
    ctx->r7 = S32(0X8003 << 16);
    // 0x8000C278: addiu       $a3, $a3, 0x77F8
    ctx->r7 = ADD32(ctx->r7, 0X77F8);
    // 0x8000C27C: addiu       $v0, $a3, -0x30
    ctx->r2 = ADD32(ctx->r7, -0X30);
    // 0x8000C280: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000C284: sw          $v0, 0x2AE4($at)
    MEM_W(0X2AE4, ctx->r1) = ctx->r2;
    // 0x8000C288: addiu       $v1, $v1, -0x8
    ctx->r3 = ADD32(ctx->r3, -0X8);
    // 0x8000C28C: sw          $v1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r3;
    // 0x8000C290: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8000C294: sw          $t0, 0x77D8($at)
    MEM_W(0X77D8, ctx->r1) = ctx->r8;
    // 0x8000C298: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8000C29C: sw          $t1, 0x77E0($at)
    MEM_W(0X77E0, ctx->r1) = ctx->r9;
    // 0x8000C2A0: jal         0x80033410
    // 0x8000C2A4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_9;
    // 0x8000C2A4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_9:
    // 0x8000C2A8: beq         $s1, $zero, L_8000C2C8
    if (ctx->r17 == 0) {
        // 0x8000C2AC: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8000C2C8;
    }
    // 0x8000C2AC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8000C2B0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000C2B4: addiu       $a0, $a0, -0x5818
    ctx->r4 = ADD32(ctx->r4, -0X5818);
    // 0x8000C2B8: jal         0x800331D0
    // 0x8000C2BC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    osRecvMesg_recomp(rdram, ctx);
        goto after_10;
    // 0x8000C2BC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_10:
    // 0x8000C2C0: jal         0x8001A038
    // 0x8000C2C4: nop

    yieldFromGfxFrame(rdram, ctx);
        goto after_11;
    // 0x8000C2C4: nop

    after_11:
L_8000C2C8:
    // 0x8000C2C8: jal         0x8002B590
    // 0x8000C2CC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    osDpGetCounters_recomp(rdram, ctx);
        goto after_12;
    // 0x8000C2CC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_12:
    // 0x8000C2D0: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x8000C2D4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8000C2D8: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x8000C2DC: bgez        $v0, L_8000C2F0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000C2E0: nop
    
            goto L_8000C2F0;
    }
    // 0x8000C2E0: nop

    // 0x8000C2E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000C2E8: ldc1        $f0, 0x580($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X580);
    // 0x8000C2EC: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
L_8000C2F0:
    // 0x8000C2F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000C2F4: ldc1        $f2, 0x588($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X588);
    // 0x8000C2F8: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x8000C2FC: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8000C300: mul.d       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x8000C304: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000C308: ldc1        $f0, 0x590($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X590);
    // 0x8000C30C: c.le.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d <= ctx->f2.d;
    // 0x8000C310: nop

    // 0x8000C314: bc1tl       L_8000C32C
    if (c1cs) {
        // 0x8000C318: sub.d       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
            goto L_8000C32C;
    }
    goto skip_0;
    // 0x8000C318: sub.d       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
    skip_0:
    // 0x8000C31C: trunc.w.d   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x8000C320: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x8000C324: j           L_8000C33C
    // 0x8000C328: nop

        goto L_8000C33C;
    // 0x8000C328: nop

L_8000C32C:
    // 0x8000C32C: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x8000C330: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8000C334: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8000C338: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_8000C33C:
    // 0x8000C33C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8000C340: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C344: sw          $v1, -0x56E0($at)
    MEM_W(-0X56E0, ctx->r1) = ctx->r3;
    // 0x8000C348: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8000C34C: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x8000C350: bgez        $v0, L_8000C364
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000C354: nop
    
            goto L_8000C364;
    }
    // 0x8000C354: nop

    // 0x8000C358: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000C35C: ldc1        $f0, 0x598($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X598);
    // 0x8000C360: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
L_8000C364:
    // 0x8000C364: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000C368: ldc1        $f2, 0x5A0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X5A0);
    // 0x8000C36C: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x8000C370: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8000C374: mul.d       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x8000C378: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000C37C: ldc1        $f0, 0x5A8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X5A8);
    // 0x8000C380: c.le.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d <= ctx->f2.d;
    // 0x8000C384: nop

    // 0x8000C388: bc1tl       L_8000C3A0
    if (c1cs) {
        // 0x8000C38C: sub.d       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
            goto L_8000C3A0;
    }
    goto skip_1;
    // 0x8000C38C: sub.d       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
    skip_1:
    // 0x8000C390: trunc.w.d   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x8000C394: mfc1        $a0, $f0
    ctx->r4 = (int32_t)ctx->f0.u32l;
    // 0x8000C398: j           L_8000C3B0
    // 0x8000C39C: nop

        goto L_8000C3B0;
    // 0x8000C39C: nop

L_8000C3A0:
    // 0x8000C3A0: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x8000C3A4: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x8000C3A8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8000C3AC: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
L_8000C3B0:
    // 0x8000C3B0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C3B4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000C3B8: lw          $v0, -0x56E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X56E0);
    // 0x8000C3BC: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8000C3C0: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x8000C3C4: subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // 0x8000C3C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C3CC: sw          $v0, -0x23AC($at)
    MEM_W(-0X23AC, ctx->r1) = ctx->r2;
    // 0x8000C3D0: bgez        $v1, L_8000C3E4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8000C3D4: nop
    
            goto L_8000C3E4;
    }
    // 0x8000C3D4: nop

    // 0x8000C3D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000C3DC: ldc1        $f0, 0x5B0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X5B0);
    // 0x8000C3E0: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
L_8000C3E4:
    // 0x8000C3E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000C3E8: ldc1        $f2, 0x5B8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X5B8);
    // 0x8000C3EC: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x8000C3F0: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8000C3F4: mul.d       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x8000C3F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000C3FC: ldc1        $f0, 0x5C0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X5C0);
    // 0x8000C400: c.le.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d <= ctx->f2.d;
    // 0x8000C404: nop

    // 0x8000C408: bc1tl       L_8000C420
    if (c1cs) {
        // 0x8000C40C: sub.d       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
            goto L_8000C420;
    }
    goto skip_2;
    // 0x8000C40C: sub.d       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
    skip_2:
    // 0x8000C410: trunc.w.d   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x8000C414: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x8000C418: j           L_8000C430
    // 0x8000C41C: nop

        goto L_8000C430;
    // 0x8000C41C: nop

L_8000C420:
    // 0x8000C420: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x8000C424: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8000C428: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8000C42C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_8000C430:
    // 0x8000C430: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C434: sw          $v1, -0x23B4($at)
    MEM_W(-0X23B4, ctx->r1) = ctx->r3;
    // 0x8000C438: jal         0x8002B5E0
    // 0x8000C43C: addiu       $a0, $zero, 0x1C0
    ctx->r4 = ADD32(0, 0X1C0);
    osDpSetStatus_recomp(rdram, ctx);
        goto after_13;
    // 0x8000C43C: addiu       $a0, $zero, 0x1C0
    ctx->r4 = ADD32(0, 0X1C0);
    after_13:
    // 0x8000C440: jal         0x8001BCE4
    // 0x8000C444: nop

    bufferArbiterProducerMark(rdram, ctx);
        goto after_14;
    // 0x8000C444: nop

    after_14:
    // 0x8000C448: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000C44C: lw          $v1, -0x5700($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5700);
    // 0x8000C450: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000C454: bne         $v1, $v0, L_8000C46C
    if (ctx->r3 != ctx->r2) {
        // 0x8000C458: nop
    
            goto L_8000C46C;
    }
    // 0x8000C458: nop

    // 0x8000C45C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C460: sw          $zero, -0x56FC($at)
    MEM_W(-0X56FC, ctx->r1) = 0;
    // 0x8000C464: j           L_8000C480
    // 0x8000C468: nop

        goto L_8000C480;
    // 0x8000C468: nop

L_8000C46C:
    // 0x8000C46C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8000C470: lw          $v0, -0x7128($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7128);
    // 0x8000C474: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8000C478: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C47C: sw          $v0, -0x56FC($at)
    MEM_W(-0X56FC, ctx->r1) = ctx->r2;
L_8000C480:
    // 0x8000C480: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8000C484: lw          $v0, -0x7128($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7128);
    // 0x8000C488: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C48C: sw          $v0, -0x5700($at)
    MEM_W(-0X5700, ctx->r1) = ctx->r2;
    // 0x8000C490: j           L_8000C654
    // 0x8000C494: nop

        goto L_8000C654;
    // 0x8000C494: nop

L_8000C498:
    // 0x8000C498: beq         $s1, $zero, L_8000C4B8
    if (ctx->r17 == 0) {
        // 0x8000C49C: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8000C4B8;
    }
    // 0x8000C49C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8000C4A0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000C4A4: addiu       $a0, $a0, -0x5818
    ctx->r4 = ADD32(ctx->r4, -0X5818);
    // 0x8000C4A8: jal         0x800331D0
    // 0x8000C4AC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    osRecvMesg_recomp(rdram, ctx);
        goto after_15;
    // 0x8000C4AC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_15:
    // 0x8000C4B0: jal         0x8001A038
    // 0x8000C4B4: nop

    yieldFromGfxFrame(rdram, ctx);
        goto after_16;
    // 0x8000C4B4: nop

    after_16:
L_8000C4B8:
    // 0x8000C4B8: jal         0x8002B590
    // 0x8000C4BC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    osDpGetCounters_recomp(rdram, ctx);
        goto after_17;
    // 0x8000C4BC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_17:
    // 0x8000C4C0: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x8000C4C4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8000C4C8: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x8000C4CC: bgez        $v0, L_8000C4E0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000C4D0: nop
    
            goto L_8000C4E0;
    }
    // 0x8000C4D0: nop

    // 0x8000C4D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000C4D8: ldc1        $f0, 0x5C8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X5C8);
    // 0x8000C4DC: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
L_8000C4E0:
    // 0x8000C4E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000C4E4: ldc1        $f2, 0x5D0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X5D0);
    // 0x8000C4E8: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x8000C4EC: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8000C4F0: mul.d       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x8000C4F4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000C4F8: ldc1        $f0, 0x5D8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X5D8);
    // 0x8000C4FC: c.le.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d <= ctx->f2.d;
    // 0x8000C500: nop

    // 0x8000C504: bc1tl       L_8000C51C
    if (c1cs) {
        // 0x8000C508: sub.d       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
            goto L_8000C51C;
    }
    goto skip_3;
    // 0x8000C508: sub.d       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
    skip_3:
    // 0x8000C50C: trunc.w.d   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x8000C510: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x8000C514: j           L_8000C52C
    // 0x8000C518: nop

        goto L_8000C52C;
    // 0x8000C518: nop

L_8000C51C:
    // 0x8000C51C: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x8000C520: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8000C524: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8000C528: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_8000C52C:
    // 0x8000C52C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8000C530: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C534: sw          $v1, -0x56E0($at)
    MEM_W(-0X56E0, ctx->r1) = ctx->r3;
    // 0x8000C538: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8000C53C: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x8000C540: bgez        $v0, L_8000C554
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000C544: nop
    
            goto L_8000C554;
    }
    // 0x8000C544: nop

    // 0x8000C548: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000C54C: ldc1        $f0, 0x5E0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X5E0);
    // 0x8000C550: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
L_8000C554:
    // 0x8000C554: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000C558: ldc1        $f2, 0x5E8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X5E8);
    // 0x8000C55C: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x8000C560: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8000C564: mul.d       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x8000C568: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000C56C: ldc1        $f0, 0x5F0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X5F0);
    // 0x8000C570: c.le.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d <= ctx->f2.d;
    // 0x8000C574: nop

    // 0x8000C578: bc1tl       L_8000C590
    if (c1cs) {
        // 0x8000C57C: sub.d       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
            goto L_8000C590;
    }
    goto skip_4;
    // 0x8000C57C: sub.d       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
    skip_4:
    // 0x8000C580: trunc.w.d   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x8000C584: mfc1        $a0, $f0
    ctx->r4 = (int32_t)ctx->f0.u32l;
    // 0x8000C588: j           L_8000C5A0
    // 0x8000C58C: nop

        goto L_8000C5A0;
    // 0x8000C58C: nop

L_8000C590:
    // 0x8000C590: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x8000C594: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x8000C598: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8000C59C: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
L_8000C5A0:
    // 0x8000C5A0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C5A4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000C5A8: lw          $v0, -0x56E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X56E0);
    // 0x8000C5AC: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8000C5B0: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x8000C5B4: subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // 0x8000C5B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5BC: sw          $v0, -0x23AC($at)
    MEM_W(-0X23AC, ctx->r1) = ctx->r2;
    // 0x8000C5C0: bgez        $v1, L_8000C5D4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8000C5C4: nop
    
            goto L_8000C5D4;
    }
    // 0x8000C5C4: nop

    // 0x8000C5C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000C5CC: ldc1        $f0, 0x5F8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X5F8);
    // 0x8000C5D0: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
L_8000C5D4:
    // 0x8000C5D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000C5D8: ldc1        $f2, 0x600($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X600);
    // 0x8000C5DC: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x8000C5E0: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8000C5E4: mul.d       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x8000C5E8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000C5EC: ldc1        $f0, 0x608($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X608);
    // 0x8000C5F0: c.le.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d <= ctx->f2.d;
    // 0x8000C5F4: nop

    // 0x8000C5F8: bc1tl       L_8000C610
    if (c1cs) {
        // 0x8000C5FC: sub.d       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
            goto L_8000C610;
    }
    goto skip_5;
    // 0x8000C5FC: sub.d       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
    skip_5:
    // 0x8000C600: trunc.w.d   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x8000C604: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x8000C608: j           L_8000C620
    // 0x8000C60C: nop

        goto L_8000C620;
    // 0x8000C60C: nop

L_8000C610:
    // 0x8000C610: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x8000C614: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8000C618: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8000C61C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_8000C620:
    // 0x8000C620: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C624: sw          $v1, -0x23B4($at)
    MEM_W(-0X23B4, ctx->r1) = ctx->r3;
    // 0x8000C628: jal         0x8001BCE4
    // 0x8000C62C: nop

    bufferArbiterProducerMark(rdram, ctx);
        goto after_18;
    // 0x8000C62C: nop

    after_18:
    // 0x8000C630: jal         0x8001C244
    // 0x8000C634: nop

    setPostSwapPendingFlags(rdram, ctx);
        goto after_19;
    // 0x8000C634: nop

    after_19:
    // 0x8000C638: j           L_8000C654
    // 0x8000C63C: nop

        goto L_8000C654;
    // 0x8000C63C: nop

L_8000C640:
    // 0x8000C640: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8000C644: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C648: sb          $zero, -0x5762($at)
    MEM_B(-0X5762, ctx->r1) = 0;
    // 0x8000C64C: jal         0x8001BCE4
    // 0x8000C650: nop

    bufferArbiterProducerMark(rdram, ctx);
        goto after_20;
    // 0x8000C650: nop

    after_20:
L_8000C654:
    // 0x8000C654: jal         0x80000C50
    // 0x8000C658: nop

    func_80000C50(rdram, ctx);
        goto after_21;
    // 0x8000C658: nop

    after_21:
    // 0x8000C65C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8000C660: bne         $v0, $zero, L_8000C654
    if (ctx->r2 != 0) {
        // 0x8000C664: nop
    
            goto L_8000C654;
    }
    // 0x8000C664: nop

    // 0x8000C668: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000C66C: addiu       $a1, $a1, -0x5770
    ctx->r5 = ADD32(ctx->r5, -0X5770);
    // 0x8000C670: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8000C674: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000C678: lbu         $v1, -0x5767($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X5767);
    // 0x8000C67C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000C680: lbu         $a0, 0x42C2($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X42C2);
    // 0x8000C684: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000C688: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x8000C68C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8000C690: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C694: sb          $v1, -0x5767($at)
    MEM_B(-0X5767, ctx->r1) = ctx->r3;
    // 0x8000C698: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // 0x8000C69C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8000C6A0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000C6A4: sb          $v1, 0x42C2($at)
    MEM_B(0X42C2, ctx->r1) = ctx->r3;
    // 0x8000C6A8: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8000C6AC: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x8000C6B0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000C6B4: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8000C6B8: sh          $zero, 0x3242($at)
    MEM_H(0X3242, ctx->r1) = 0;
    // 0x8000C6BC: bne         $v1, $v0, L_8000C6CC
    if (ctx->r3 != ctx->r2) {
        // 0x8000C6C0: nop
    
            goto L_8000C6CC;
    }
    // 0x8000C6C0: nop

    // 0x8000C6C4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000C6C8: sb          $zero, 0x42C2($at)
    MEM_B(0X42C2, ctx->r1) = 0;
L_8000C6CC:
    // 0x8000C6CC: jal         0x80023CC0
    // 0x8000C6D0: nop

    recordFrameTimestamp(rdram, ctx);
        goto after_22;
    // 0x8000C6D0: nop

    after_22:
    // 0x8000C6D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000C6D8: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x8000C6DC: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8000C6E0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8000C6E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8000C6E8: jr          $ra
    // 0x8000C6EC: nop

    return;
    // 0x8000C6EC: nop

;}
RECOMP_FUNC void func_8000C6F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C6F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000C6F4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000C6F8: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x8000C6FC: lui         $v0, 0x4000
    ctx->r2 = S32(0X4000 << 16);
    // 0x8000C700: and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
    // 0x8000C704: beq         $a0, $zero, L_8000C808
    if (ctx->r4 == 0) {
        // 0x8000C708: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8000C808;
    }
    // 0x8000C708: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000C70C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000C710: lbu         $v0, 0x63BC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X63BC);
    // 0x8000C714: sltiu       $v0, $v0, 0x40
    ctx->r2 = ctx->r2 < 0X40 ? 1 : 0;
    // 0x8000C718: bne         $v0, $zero, L_8000C7E0
    if (ctx->r2 != 0) {
        // 0x8000C71C: nop
    
            goto L_8000C7E0;
    }
    // 0x8000C71C: nop

    // 0x8000C720: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000C724: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000C728: bne         $a0, $zero, L_8000C788
    if (ctx->r4 != 0) {
        // 0x8000C72C: nop
    
            goto L_8000C788;
    }
    // 0x8000C72C: nop

    // 0x8000C730: jal         0x8002221C
    // 0x8000C734: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_0;
    // 0x8000C734: nop

    after_0:
    // 0x8000C738: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000C73C: beq         $a0, $zero, L_8000C780
    if (ctx->r4 == 0) {
        // 0x8000C740: nop
    
            goto L_8000C780;
    }
    // 0x8000C740: nop

    // 0x8000C744: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000C748: beq         $v0, $zero, L_8000C760
    if (ctx->r2 == 0) {
        // 0x8000C74C: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000C760;
    }
    // 0x8000C74C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000C750:
    // 0x8000C750: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000C754: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000C758: bne         $v0, $zero, L_8000C750
    if (ctx->r2 != 0) {
        // 0x8000C75C: nop
    
            goto L_8000C750;
    }
    // 0x8000C75C: nop

L_8000C760:
    // 0x8000C760: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000C764: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000C768: beq         $v0, $zero, L_8000C774
    if (ctx->r2 == 0) {
        // 0x8000C76C: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000C774;
    }
    // 0x8000C76C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000C770: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000C774:
    // 0x8000C774: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000C778: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000C77C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000C780:
    // 0x8000C780: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000C784: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000C788:
    // 0x8000C788: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000C78C: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000C790: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000C794: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000C798: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000C79C: bnel        $v0, $zero, L_8000C7A4
    if (ctx->r2 != 0) {
        // 0x8000C7A0: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000C7A4;
    }
    goto skip_0;
    // 0x8000C7A0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_0:
L_8000C7A4:
    // 0x8000C7A4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000C7A8: lw          $v0, -0x5B48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5B48);
    // 0x8000C7AC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000C7B0: bnel        $v0, $zero, L_8000C7B8
    if (ctx->r2 != 0) {
        // 0x8000C7B4: sw          $a0, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r4;
            goto L_8000C7B8;
    }
    goto skip_1;
    // 0x8000C7B4: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    skip_1:
L_8000C7B8:
    // 0x8000C7B8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000C7BC: lw          $v0, -0x5B48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5B48);
    // 0x8000C7C0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000C7C4: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x8000C7C8: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000C7CC: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000C7D0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000C7D4: sw          $v0, 0x63B8($at)
    MEM_W(0X63B8, ctx->r1) = ctx->r2;
    // 0x8000C7D8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000C7DC: sb          $zero, 0x63BC($at)
    MEM_B(0X63BC, ctx->r1) = 0;
L_8000C7E0:
    // 0x8000C7E0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000C7E4: addiu       $a0, $a0, 0x63BC
    ctx->r4 = ADD32(ctx->r4, 0X63BC);
    // 0x8000C7E8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8000C7EC: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8000C7F0: lw          $a1, 0x63B8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X63B8);
    // 0x8000C7F4: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8000C7F8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000C7FC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8000C800: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8000C804: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
L_8000C808:
    // 0x8000C808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000C80C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000C810: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000C814: jr          $ra
    // 0x8000C818: nop

    return;
    // 0x8000C818: nop

;}
RECOMP_FUNC void func_8000C81C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C81C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000C820: lui         $v0, 0x4000
    ctx->r2 = S32(0X4000 << 16);
    // 0x8000C824: and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
    // 0x8000C828: beq         $a0, $zero, L_8000C92C
    if (ctx->r4 == 0) {
        // 0x8000C82C: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8000C92C;
    }
    // 0x8000C82C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000C830: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000C834: lbu         $v0, 0x63BC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X63BC);
    // 0x8000C838: sltiu       $v0, $v0, 0x40
    ctx->r2 = ctx->r2 < 0X40 ? 1 : 0;
    // 0x8000C83C: bne         $v0, $zero, L_8000C904
    if (ctx->r2 != 0) {
        // 0x8000C840: nop
    
            goto L_8000C904;
    }
    // 0x8000C840: nop

    // 0x8000C844: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000C848: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000C84C: bne         $a0, $zero, L_8000C8AC
    if (ctx->r4 != 0) {
        // 0x8000C850: nop
    
            goto L_8000C8AC;
    }
    // 0x8000C850: nop

    // 0x8000C854: jal         0x8002221C
    // 0x8000C858: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_0;
    // 0x8000C858: nop

    after_0:
    // 0x8000C85C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000C860: beq         $a0, $zero, L_8000C8A4
    if (ctx->r4 == 0) {
        // 0x8000C864: nop
    
            goto L_8000C8A4;
    }
    // 0x8000C864: nop

    // 0x8000C868: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000C86C: beq         $v0, $zero, L_8000C884
    if (ctx->r2 == 0) {
        // 0x8000C870: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000C884;
    }
    // 0x8000C870: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000C874:
    // 0x8000C874: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000C878: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000C87C: bne         $v0, $zero, L_8000C874
    if (ctx->r2 != 0) {
        // 0x8000C880: nop
    
            goto L_8000C874;
    }
    // 0x8000C880: nop

L_8000C884:
    // 0x8000C884: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000C888: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000C88C: beq         $v0, $zero, L_8000C898
    if (ctx->r2 == 0) {
        // 0x8000C890: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000C898;
    }
    // 0x8000C890: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000C894: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000C898:
    // 0x8000C898: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000C89C: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000C8A0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000C8A4:
    // 0x8000C8A4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000C8A8: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000C8AC:
    // 0x8000C8AC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000C8B0: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000C8B4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000C8B8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000C8BC: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000C8C0: bnel        $v0, $zero, L_8000C8C8
    if (ctx->r2 != 0) {
        // 0x8000C8C4: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000C8C8;
    }
    goto skip_0;
    // 0x8000C8C4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_0:
L_8000C8C8:
    // 0x8000C8C8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000C8CC: lw          $v0, -0x5B48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5B48);
    // 0x8000C8D0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000C8D4: bnel        $v0, $zero, L_8000C8DC
    if (ctx->r2 != 0) {
        // 0x8000C8D8: sw          $a0, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r4;
            goto L_8000C8DC;
    }
    goto skip_1;
    // 0x8000C8D8: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    skip_1:
L_8000C8DC:
    // 0x8000C8DC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000C8E0: lw          $v0, -0x5B48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5B48);
    // 0x8000C8E4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000C8E8: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x8000C8EC: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000C8F0: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000C8F4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000C8F8: sw          $v0, 0x63B8($at)
    MEM_W(0X63B8, ctx->r1) = ctx->r2;
    // 0x8000C8FC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000C900: sb          $zero, 0x63BC($at)
    MEM_B(0X63BC, ctx->r1) = 0;
L_8000C904:
    // 0x8000C904: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000C908: addiu       $a0, $a0, 0x63BC
    ctx->r4 = ADD32(ctx->r4, 0X63BC);
    // 0x8000C90C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8000C910: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8000C914: lw          $a1, 0x63B8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X63B8);
    // 0x8000C918: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8000C91C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000C920: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8000C924: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8000C928: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_8000C92C:
    // 0x8000C92C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8000C930: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000C934: jr          $ra
    // 0x8000C938: nop

    return;
    // 0x8000C938: nop

;}
RECOMP_FUNC void func_8000C93C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C93C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000C940: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000C944: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x8000C948: lui         $v0, 0x4000
    ctx->r2 = S32(0X4000 << 16);
    // 0x8000C94C: and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
    // 0x8000C950: beq         $a0, $zero, L_8000CA54
    if (ctx->r4 == 0) {
        // 0x8000C954: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8000CA54;
    }
    // 0x8000C954: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000C958: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000C95C: lbu         $v0, 0x63BC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X63BC);
    // 0x8000C960: sltiu       $v0, $v0, 0x40
    ctx->r2 = ctx->r2 < 0X40 ? 1 : 0;
    // 0x8000C964: bne         $v0, $zero, L_8000CA2C
    if (ctx->r2 != 0) {
        // 0x8000C968: nop
    
            goto L_8000CA2C;
    }
    // 0x8000C968: nop

    // 0x8000C96C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000C970: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000C974: bne         $a0, $zero, L_8000C9D4
    if (ctx->r4 != 0) {
        // 0x8000C978: nop
    
            goto L_8000C9D4;
    }
    // 0x8000C978: nop

    // 0x8000C97C: jal         0x8002221C
    // 0x8000C980: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_0;
    // 0x8000C980: nop

    after_0:
    // 0x8000C984: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000C988: beq         $a0, $zero, L_8000C9CC
    if (ctx->r4 == 0) {
        // 0x8000C98C: nop
    
            goto L_8000C9CC;
    }
    // 0x8000C98C: nop

    // 0x8000C990: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000C994: beq         $v0, $zero, L_8000C9AC
    if (ctx->r2 == 0) {
        // 0x8000C998: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000C9AC;
    }
    // 0x8000C998: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000C99C:
    // 0x8000C99C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000C9A0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000C9A4: bne         $v0, $zero, L_8000C99C
    if (ctx->r2 != 0) {
        // 0x8000C9A8: nop
    
            goto L_8000C99C;
    }
    // 0x8000C9A8: nop

L_8000C9AC:
    // 0x8000C9AC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000C9B0: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000C9B4: beq         $v0, $zero, L_8000C9C0
    if (ctx->r2 == 0) {
        // 0x8000C9B8: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000C9C0;
    }
    // 0x8000C9B8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000C9BC: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000C9C0:
    // 0x8000C9C0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000C9C4: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000C9C8: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000C9CC:
    // 0x8000C9CC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000C9D0: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000C9D4:
    // 0x8000C9D4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000C9D8: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000C9DC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000C9E0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000C9E4: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000C9E8: bnel        $v0, $zero, L_8000C9F0
    if (ctx->r2 != 0) {
        // 0x8000C9EC: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000C9F0;
    }
    goto skip_0;
    // 0x8000C9EC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_0:
L_8000C9F0:
    // 0x8000C9F0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000C9F4: lw          $v0, -0x5B48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5B48);
    // 0x8000C9F8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000C9FC: bnel        $v0, $zero, L_8000CA04
    if (ctx->r2 != 0) {
        // 0x8000CA00: sw          $a0, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r4;
            goto L_8000CA04;
    }
    goto skip_1;
    // 0x8000CA00: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    skip_1:
L_8000CA04:
    // 0x8000CA04: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000CA08: lw          $v0, -0x5B48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5B48);
    // 0x8000CA0C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000CA10: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x8000CA14: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000CA18: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000CA1C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000CA20: sw          $v0, 0x63B8($at)
    MEM_W(0X63B8, ctx->r1) = ctx->r2;
    // 0x8000CA24: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000CA28: sb          $zero, 0x63BC($at)
    MEM_B(0X63BC, ctx->r1) = 0;
L_8000CA2C:
    // 0x8000CA2C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000CA30: lbu         $v0, 0x63BC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X63BC);
    // 0x8000CA34: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000CA38: lw          $a0, 0x63B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B8);
    // 0x8000CA3C: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8000CA40: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000CA44: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000CA48: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000CA4C: sb          $v1, 0x63BC($at)
    MEM_B(0X63BC, ctx->r1) = ctx->r3;
    // 0x8000CA50: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
L_8000CA54:
    // 0x8000CA54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000CA58: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000CA5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000CA60: jr          $ra
    // 0x8000CA64: nop

    return;
    // 0x8000CA64: nop

;}
RECOMP_FUNC void func_8000CA68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CA68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000CA6C: lui         $v0, 0x4000
    ctx->r2 = S32(0X4000 << 16);
    // 0x8000CA70: and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
    // 0x8000CA74: beq         $a0, $zero, L_8000CB78
    if (ctx->r4 == 0) {
        // 0x8000CA78: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8000CB78;
    }
    // 0x8000CA78: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000CA7C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000CA80: lbu         $v0, 0x63BC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X63BC);
    // 0x8000CA84: sltiu       $v0, $v0, 0x40
    ctx->r2 = ctx->r2 < 0X40 ? 1 : 0;
    // 0x8000CA88: bne         $v0, $zero, L_8000CB50
    if (ctx->r2 != 0) {
        // 0x8000CA8C: nop
    
            goto L_8000CB50;
    }
    // 0x8000CA8C: nop

    // 0x8000CA90: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000CA94: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000CA98: bne         $a0, $zero, L_8000CAF8
    if (ctx->r4 != 0) {
        // 0x8000CA9C: nop
    
            goto L_8000CAF8;
    }
    // 0x8000CA9C: nop

    // 0x8000CAA0: jal         0x8002221C
    // 0x8000CAA4: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_0;
    // 0x8000CAA4: nop

    after_0:
    // 0x8000CAA8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000CAAC: beq         $a0, $zero, L_8000CAF0
    if (ctx->r4 == 0) {
        // 0x8000CAB0: nop
    
            goto L_8000CAF0;
    }
    // 0x8000CAB0: nop

    // 0x8000CAB4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000CAB8: beq         $v0, $zero, L_8000CAD0
    if (ctx->r2 == 0) {
        // 0x8000CABC: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000CAD0;
    }
    // 0x8000CABC: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000CAC0:
    // 0x8000CAC0: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000CAC4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000CAC8: bne         $v0, $zero, L_8000CAC0
    if (ctx->r2 != 0) {
        // 0x8000CACC: nop
    
            goto L_8000CAC0;
    }
    // 0x8000CACC: nop

L_8000CAD0:
    // 0x8000CAD0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000CAD4: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000CAD8: beq         $v0, $zero, L_8000CAE4
    if (ctx->r2 == 0) {
        // 0x8000CADC: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000CAE4;
    }
    // 0x8000CADC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000CAE0: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000CAE4:
    // 0x8000CAE4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000CAE8: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000CAEC: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000CAF0:
    // 0x8000CAF0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000CAF4: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000CAF8:
    // 0x8000CAF8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000CAFC: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000CB00: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000CB04: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000CB08: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000CB0C: bnel        $v0, $zero, L_8000CB14
    if (ctx->r2 != 0) {
        // 0x8000CB10: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000CB14;
    }
    goto skip_0;
    // 0x8000CB10: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_0:
L_8000CB14:
    // 0x8000CB14: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000CB18: lw          $v0, -0x5B48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5B48);
    // 0x8000CB1C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000CB20: bnel        $v0, $zero, L_8000CB28
    if (ctx->r2 != 0) {
        // 0x8000CB24: sw          $a0, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r4;
            goto L_8000CB28;
    }
    goto skip_1;
    // 0x8000CB24: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    skip_1:
L_8000CB28:
    // 0x8000CB28: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000CB2C: lw          $v0, -0x5B48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5B48);
    // 0x8000CB30: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000CB34: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x8000CB38: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000CB3C: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000CB40: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000CB44: sw          $v0, 0x63B8($at)
    MEM_W(0X63B8, ctx->r1) = ctx->r2;
    // 0x8000CB48: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000CB4C: sb          $zero, 0x63BC($at)
    MEM_B(0X63BC, ctx->r1) = 0;
L_8000CB50:
    // 0x8000CB50: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000CB54: lbu         $v0, 0x63BC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X63BC);
    // 0x8000CB58: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000CB5C: lw          $a0, 0x63B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B8);
    // 0x8000CB60: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8000CB64: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000CB68: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000CB6C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000CB70: sb          $v1, 0x63BC($at)
    MEM_B(0X63BC, ctx->r1) = ctx->r3;
    // 0x8000CB74: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_8000CB78:
    // 0x8000CB78: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8000CB7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000CB80: jr          $ra
    // 0x8000CB84: nop

    return;
    // 0x8000CB84: nop

;}
RECOMP_FUNC void func_8000CB88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CB88: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000CB8C: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x8000CB90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000CB94: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000CB98: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8000CB9C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8000CBA0: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x8000CBA4: sltu        $v0, $s0, $v0
    ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x8000CBA8: bne         $v0, $zero, L_8000CC90
    if (ctx->r2 != 0) {
        // 0x8000CBAC: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_8000CC90;
    }
    // 0x8000CBAC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8000CBB0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000CBB4: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000CBB8: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x8000CBBC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000CBC0: bne         $a0, $zero, L_8000CC20
    if (ctx->r4 != 0) {
        // 0x8000CBC4: sw          $zero, 0x4($s0)
        MEM_W(0X4, ctx->r16) = 0;
            goto L_8000CC20;
    }
    // 0x8000CBC4: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8000CBC8: jal         0x8002221C
    // 0x8000CBCC: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_0;
    // 0x8000CBCC: nop

    after_0:
    // 0x8000CBD0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000CBD4: beq         $a0, $zero, L_8000CC18
    if (ctx->r4 == 0) {
        // 0x8000CBD8: nop
    
            goto L_8000CC18;
    }
    // 0x8000CBD8: nop

    // 0x8000CBDC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000CBE0: beq         $v0, $zero, L_8000CBF8
    if (ctx->r2 == 0) {
        // 0x8000CBE4: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000CBF8;
    }
    // 0x8000CBE4: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000CBE8:
    // 0x8000CBE8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000CBEC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000CBF0: bne         $v0, $zero, L_8000CBE8
    if (ctx->r2 != 0) {
        // 0x8000CBF4: nop
    
            goto L_8000CBE8;
    }
    // 0x8000CBF4: nop

L_8000CBF8:
    // 0x8000CBF8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000CBFC: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000CC00: beq         $v0, $zero, L_8000CC0C
    if (ctx->r2 == 0) {
        // 0x8000CC04: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000CC0C;
    }
    // 0x8000CC04: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000CC08: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000CC0C:
    // 0x8000CC0C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000CC10: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000CC14: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000CC18:
    // 0x8000CC18: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000CC1C: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000CC20:
    // 0x8000CC20: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000CC24: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000CC28: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000CC2C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000CC30: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000CC34: bnel        $v0, $zero, L_8000CC3C
    if (ctx->r2 != 0) {
        // 0x8000CC38: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000CC3C;
    }
    goto skip_0;
    // 0x8000CC38: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_0:
L_8000CC3C:
    // 0x8000CC3C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000CC40: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000CC44: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000CC48: bne         $v0, $zero, L_8000CC58
    if (ctx->r2 != 0) {
        // 0x8000CC4C: nop
    
            goto L_8000CC58;
    }
    // 0x8000CC4C: nop

    // 0x8000CC50: j           L_8000CC70
    // 0x8000CC54: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000CC70;
    // 0x8000CC54: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000CC58:
    // 0x8000CC58: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000CC5C: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000CC60: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000CC64: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000CC68: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000CC6C: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000CC70:
    // 0x8000CC70: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000CC74: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000CC78: addiu       $s0, $a0, 0x8
    ctx->r16 = ADD32(ctx->r4, 0X8);
    // 0x8000CC7C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000CC80: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000CC84: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000CC88: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000CC8C: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
L_8000CC90:
    // 0x8000CC90: lui         $v0, 0x4000
    ctx->r2 = S32(0X4000 << 16);
    // 0x8000CC94: and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // 0x8000CC98: beq         $v0, $zero, L_8000CDB0
    if (ctx->r2 == 0) {
        // 0x8000CC9C: nop
    
            goto L_8000CDB0;
    }
    // 0x8000CC9C: nop

    // 0x8000CCA0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000CCA4: lbu         $v0, -0x2F6C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2F6C);
    // 0x8000CCA8: sltiu       $v0, $v0, 0x40
    ctx->r2 = ctx->r2 < 0X40 ? 1 : 0;
    // 0x8000CCAC: bne         $v0, $zero, L_8000CD78
    if (ctx->r2 != 0) {
        // 0x8000CCB0: lui         $a0, 0xFF
        ctx->r4 = S32(0XFF << 16);
            goto L_8000CD78;
    }
    // 0x8000CCB0: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x8000CCB4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000CCB8: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000CCBC: bne         $a0, $zero, L_8000CD1C
    if (ctx->r4 != 0) {
        // 0x8000CCC0: nop
    
            goto L_8000CD1C;
    }
    // 0x8000CCC0: nop

    // 0x8000CCC4: jal         0x8002221C
    // 0x8000CCC8: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_1;
    // 0x8000CCC8: nop

    after_1:
    // 0x8000CCCC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000CCD0: beq         $a0, $zero, L_8000CD14
    if (ctx->r4 == 0) {
        // 0x8000CCD4: nop
    
            goto L_8000CD14;
    }
    // 0x8000CCD4: nop

    // 0x8000CCD8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000CCDC: beq         $v0, $zero, L_8000CCF4
    if (ctx->r2 == 0) {
        // 0x8000CCE0: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000CCF4;
    }
    // 0x8000CCE0: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000CCE4:
    // 0x8000CCE4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000CCE8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000CCEC: bne         $v0, $zero, L_8000CCE4
    if (ctx->r2 != 0) {
        // 0x8000CCF0: nop
    
            goto L_8000CCE4;
    }
    // 0x8000CCF0: nop

L_8000CCF4:
    // 0x8000CCF4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000CCF8: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000CCFC: beq         $v0, $zero, L_8000CD08
    if (ctx->r2 == 0) {
        // 0x8000CD00: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000CD08;
    }
    // 0x8000CD00: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000CD04: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000CD08:
    // 0x8000CD08: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000CD0C: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000CD10: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000CD14:
    // 0x8000CD14: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000CD18: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000CD1C:
    // 0x8000CD1C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000CD20: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000CD24: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000CD28: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000CD2C: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000CD30: bnel        $v0, $zero, L_8000CD38
    if (ctx->r2 != 0) {
        // 0x8000CD34: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000CD38;
    }
    goto skip_1;
    // 0x8000CD34: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_1:
L_8000CD38:
    // 0x8000CD38: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000CD3C: lw          $v0, -0x5B44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5B44);
    // 0x8000CD40: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000CD44: bnel        $v0, $zero, L_8000CD4C
    if (ctx->r2 != 0) {
        // 0x8000CD48: sw          $a0, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r4;
            goto L_8000CD4C;
    }
    goto skip_2;
    // 0x8000CD48: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    skip_2:
L_8000CD4C:
    // 0x8000CD4C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000CD50: lw          $v0, -0x5B44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5B44);
    // 0x8000CD54: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000CD58: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x8000CD5C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000CD60: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000CD64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CD68: sw          $v0, -0x2F70($at)
    MEM_W(-0X2F70, ctx->r1) = ctx->r2;
    // 0x8000CD6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CD70: sb          $zero, -0x2F6C($at)
    MEM_B(-0X2F6C, ctx->r1) = 0;
    // 0x8000CD74: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
L_8000CD78:
    // 0x8000CD78: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000CD7C: lbu         $v1, -0x2F6C($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X2F6C);
    // 0x8000CD80: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000CD84: lw          $a1, -0x2F70($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2F70);
    // 0x8000CD88: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x8000CD8C: and         $a0, $s0, $a0
    ctx->r4 = ctx->r16 & ctx->r4;
    // 0x8000CD90: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8000CD94: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8000CD98: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8000CD9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CDA0: sb          $v0, -0x2F6C($at)
    MEM_B(-0X2F6C, ctx->r1) = ctx->r2;
    // 0x8000CDA4: lui         $v0, 0x100
    ctx->r2 = S32(0X100 << 16);
    // 0x8000CDA8: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x8000CDAC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000CDB0:
    // 0x8000CDB0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8000CDB4: lw          $a1, 0x63B0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X63B0);
    // 0x8000CDB8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CDBC: sw          $s0, -0x5BC8($at)
    MEM_W(-0X5BC8, ctx->r1) = ctx->r16;
    // 0x8000CDC0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CDC4: sb          $zero, -0x5BC0($at)
    MEM_B(-0X5BC0, ctx->r1) = 0;
    // 0x8000CDC8: bne         $a1, $zero, L_8000CE28
    if (ctx->r5 != 0) {
        // 0x8000CDCC: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_8000CE28;
    }
    // 0x8000CDCC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8000CDD0: jal         0x8002221C
    // 0x8000CDD4: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_2;
    // 0x8000CDD4: nop

    after_2:
    // 0x8000CDD8: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8000CDDC: beq         $a1, $zero, L_8000CE20
    if (ctx->r5 == 0) {
        // 0x8000CDE0: nop
    
            goto L_8000CE20;
    }
    // 0x8000CDE0: nop

    // 0x8000CDE4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8000CDE8: beq         $v0, $zero, L_8000CE00
    if (ctx->r2 == 0) {
        // 0x8000CDEC: addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
            goto L_8000CE00;
    }
    // 0x8000CDEC: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
L_8000CDF0:
    // 0x8000CDF0: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000CDF4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000CDF8: bne         $v0, $zero, L_8000CDF0
    if (ctx->r2 != 0) {
        // 0x8000CDFC: nop
    
            goto L_8000CDF0;
    }
    // 0x8000CDFC: nop

L_8000CE00:
    // 0x8000CE00: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000CE04: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000CE08: beq         $v0, $zero, L_8000CE14
    if (ctx->r2 == 0) {
        // 0x8000CE0C: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000CE14;
    }
    // 0x8000CE0C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000CE10: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000CE14:
    // 0x8000CE14: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000CE18: sw          $a1, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r5;
    // 0x8000CE1C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_8000CE20:
    // 0x8000CE20: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8000CE24: lw          $a1, 0x63B0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X63B0);
L_8000CE28:
    // 0x8000CE28: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000CE2C: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000CE30: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000CE34: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000CE38: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000CE3C: bnel        $v0, $zero, L_8000CE44
    if (ctx->r2 != 0) {
        // 0x8000CE40: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000CE44;
    }
    goto skip_3;
    // 0x8000CE40: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_3:
L_8000CE44:
    // 0x8000CE44: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000CE48: lw          $v0, -0x5B54($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5B54);
    // 0x8000CE4C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000CE50: bnel        $v0, $zero, L_8000CE58
    if (ctx->r2 != 0) {
        // 0x8000CE54: sw          $a1, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r5;
            goto L_8000CE58;
    }
    goto skip_4;
    // 0x8000CE54: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    skip_4:
L_8000CE58:
    // 0x8000CE58: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000CE5C: lw          $a0, -0x5B54($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5B54);
    // 0x8000CE60: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8000CE64: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8000CE68: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x8000CE6C: addiu       $v1, $a1, 0x8
    ctx->r3 = ADD32(ctx->r5, 0X8);
    // 0x8000CE70: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x8000CE74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CE78: sw          $v1, -0x5BC4($at)
    MEM_W(-0X5BC4, ctx->r1) = ctx->r3;
    // 0x8000CE7C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8000CE80: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8000CE84: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000CE88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000CE8C: jr          $ra
    // 0x8000CE90: nop

    return;
    // 0x8000CE90: nop

;}
RECOMP_FUNC void func_8000CE94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CE94: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000CE98: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x8000CE9C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000CEA0: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x8000CEA4: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8000CEA8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8000CEAC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8000CEB0: addiu       $s2, $s2, -0x5BC0
    ctx->r18 = ADD32(ctx->r18, -0X5BC0);
    // 0x8000CEB4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000CEB8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8000CEBC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8000CEC0: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x8000CEC4: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x8000CEC8: andi        $s1, $s3, 0xFF
    ctx->r17 = ctx->r19 & 0XFF;
    // 0x8000CECC: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x8000CED0: slti        $v0, $v0, 0x41
    ctx->r2 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
    // 0x8000CED4: bne         $v0, $zero, L_8000CF28
    if (ctx->r2 != 0) {
        // 0x8000CED8: addu        $s4, $a3, $zero
        ctx->r20 = ADD32(ctx->r7, 0);
            goto L_8000CF28;
    }
    // 0x8000CED8: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x8000CEDC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000CEE0: lbu         $v0, -0x5BC0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5BC0);
    // 0x8000CEE4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000CEE8: lw          $a0, -0x5BC8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5BC8);
    // 0x8000CEEC: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x8000CEF0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000CEF4: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x8000CEF8: andi        $v0, $v0, 0xFFF0
    ctx->r2 = ctx->r2 & 0XFFF0;
    // 0x8000CEFC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000CF00: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8000CF04: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8000CF08: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8000CF0C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000CF10: lw          $v0, -0x5BC4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5BC4);
    // 0x8000CF14: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8000CF18: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8000CF1C: jal         0x8000CB88
    // 0x8000CF20: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    func_8000CB88(rdram, ctx);
        goto after_0;
    // 0x8000CF20: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    after_0:
    // 0x8000CF24: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_8000CF28:
    // 0x8000CF28: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x8000CF2C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8000CF30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000CF34: bne         $s1, $v0, L_8000CF50
    if (ctx->r17 != ctx->r2) {
        // 0x8000CF38: sb          $v1, 0x1($s0)
        MEM_B(0X1, ctx->r16) = ctx->r3;
            goto L_8000CF50;
    }
    // 0x8000CF38: sb          $v1, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r3;
    // 0x8000CF3C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x8000CF40: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x8000CF44: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // 0x8000CF48: j           L_8000CF7C
    // 0x8000CF4C: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
        goto L_8000CF7C;
    // 0x8000CF4C: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
L_8000CF50:
    // 0x8000CF50: addiu       $v0, $v1, 0x4
    ctx->r2 = ADD32(ctx->r3, 0X4);
    // 0x8000CF54: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x8000CF58: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8000CF5C: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // 0x8000CF60: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000CF64: bne         $s1, $v0, L_8000CF78
    if (ctx->r17 != ctx->r2) {
        // 0x8000CF68: addiu       $v0, $v1, 0xC
        ctx->r2 = ADD32(ctx->r3, 0XC);
            goto L_8000CF78;
    }
    // 0x8000CF68: addiu       $v0, $v1, 0xC
    ctx->r2 = ADD32(ctx->r3, 0XC);
    // 0x8000CF6C: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x8000CF70: j           L_8000CF7C
    // 0x8000CF74: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
        goto L_8000CF7C;
    // 0x8000CF74: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
L_8000CF78:
    // 0x8000CF78: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
L_8000CF7C:
    // 0x8000CF7C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000CF80: lbu         $v0, -0x5BC0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5BC0);
    // 0x8000CF84: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000CF88: lw          $v1, -0x5BC4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5BC4);
    // 0x8000CF8C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000CF90: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000CF94: sw          $v1, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r3;
    // 0x8000CF98: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000CF9C: lbu         $v1, -0x5BC0($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X5BC0);
    // 0x8000CFA0: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    // 0x8000CFA4: addu        $v1, $v1, $s3
    ctx->r3 = ADD32(ctx->r3, ctx->r19);
    // 0x8000CFA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CFAC: sb          $v1, -0x5BC0($at)
    MEM_B(-0X5BC0, ctx->r1) = ctx->r3;
    // 0x8000CFB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000CFB4: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8000CFB8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8000CFBC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8000CFC0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8000CFC4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000CFC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000CFCC: jr          $ra
    // 0x8000CFD0: nop

    return;
    // 0x8000CFD0: nop

;}
RECOMP_FUNC void heapFreeListDequeue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CFD4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8000CFD8: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x8000CFDC: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x8000CFE0: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x8000CFE4: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x8000CFE8: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x8000CFEC: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x8000CFF0: sw          $ra, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r31;
    // 0x8000CFF4: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x8000CFF8: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x8000CFFC: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x8000D000: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x8000D004: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x8000D008: lw          $v0, 0x2C($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X2C);
    // 0x8000D00C: lui         $v1, 0x4000
    ctx->r3 = S32(0X4000 << 16);
    // 0x8000D010: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8000D014: beq         $v0, $zero, L_8000D118
    if (ctx->r2 == 0) {
        // 0x8000D018: addu        $s7, $a3, $zero
        ctx->r23 = ADD32(ctx->r7, 0);
            goto L_8000D118;
    }
    // 0x8000D018: addu        $s7, $a3, $zero
    ctx->r23 = ADD32(ctx->r7, 0);
    // 0x8000D01C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000D020: lbu         $v0, 0x63BC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X63BC);
    // 0x8000D024: sltiu       $v0, $v0, 0x40
    ctx->r2 = ctx->r2 < 0X40 ? 1 : 0;
    // 0x8000D028: bne         $v0, $zero, L_8000D0F0
    if (ctx->r2 != 0) {
        // 0x8000D02C: nop
    
            goto L_8000D0F0;
    }
    // 0x8000D02C: nop

    // 0x8000D030: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000D034: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000D038: bne         $a0, $zero, L_8000D098
    if (ctx->r4 != 0) {
        // 0x8000D03C: nop
    
            goto L_8000D098;
    }
    // 0x8000D03C: nop

    // 0x8000D040: jal         0x8002221C
    // 0x8000D044: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_0;
    // 0x8000D044: nop

    after_0:
    // 0x8000D048: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000D04C: beq         $a0, $zero, L_8000D090
    if (ctx->r4 == 0) {
        // 0x8000D050: nop
    
            goto L_8000D090;
    }
    // 0x8000D050: nop

    // 0x8000D054: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000D058: beq         $v0, $zero, L_8000D070
    if (ctx->r2 == 0) {
        // 0x8000D05C: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000D070;
    }
    // 0x8000D05C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000D060:
    // 0x8000D060: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000D064: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000D068: bne         $v0, $zero, L_8000D060
    if (ctx->r2 != 0) {
        // 0x8000D06C: nop
    
            goto L_8000D060;
    }
    // 0x8000D06C: nop

L_8000D070:
    // 0x8000D070: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000D074: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000D078: beq         $v0, $zero, L_8000D084
    if (ctx->r2 == 0) {
        // 0x8000D07C: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000D084;
    }
    // 0x8000D07C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000D080: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000D084:
    // 0x8000D084: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000D088: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000D08C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000D090:
    // 0x8000D090: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000D094: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000D098:
    // 0x8000D098: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000D09C: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000D0A0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000D0A4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000D0A8: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000D0AC: bnel        $v0, $zero, L_8000D0B4
    if (ctx->r2 != 0) {
        // 0x8000D0B0: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000D0B4;
    }
    goto skip_0;
    // 0x8000D0B0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_0:
L_8000D0B4:
    // 0x8000D0B4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000D0B8: lw          $v0, -0x5B48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5B48);
    // 0x8000D0BC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000D0C0: bnel        $v0, $zero, L_8000D0C8
    if (ctx->r2 != 0) {
        // 0x8000D0C4: sw          $a0, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r4;
            goto L_8000D0C8;
    }
    goto skip_1;
    // 0x8000D0C4: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    skip_1:
L_8000D0C8:
    // 0x8000D0C8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000D0CC: lw          $v0, -0x5B48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5B48);
    // 0x8000D0D0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000D0D4: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x8000D0D8: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000D0DC: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000D0E0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000D0E4: sw          $v0, 0x63B8($at)
    MEM_W(0X63B8, ctx->r1) = ctx->r2;
    // 0x8000D0E8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000D0EC: sb          $zero, 0x63BC($at)
    MEM_B(0X63BC, ctx->r1) = 0;
L_8000D0F0:
    // 0x8000D0F0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000D0F4: lbu         $v0, 0x63BC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X63BC);
    // 0x8000D0F8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000D0FC: lw          $a0, 0x63B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B8);
    // 0x8000D100: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8000D104: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000D108: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000D10C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000D110: sb          $v1, 0x63BC($at)
    MEM_B(0X63BC, ctx->r1) = ctx->r3;
    // 0x8000D114: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
L_8000D118:
    // 0x8000D118: lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X4);
    // 0x8000D11C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8000D120: lw          $s0, -0x23A8($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X23A8);
    // 0x8000D124: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    // 0x8000D128: srl         $v1, $v0, 16
    ctx->r3 = S32(U32(ctx->r2) >> 16);
    // 0x8000D12C: andi        $v1, $v1, 0xFC
    ctx->r3 = ctx->r3 & 0XFC;
    // 0x8000D130: srl         $v0, $v0, 10
    ctx->r2 = S32(U32(ctx->r2) >> 10);
    // 0x8000D134: andi        $v0, $v0, 0xFC
    ctx->r2 = ctx->r2 & 0XFC;
    // 0x8000D138: addu        $s4, $s3, $v0
    ctx->r20 = ADD32(ctx->r19, ctx->r2);
    // 0x8000D13C: xor         $v0, $s1, $s2
    ctx->r2 = ctx->r17 ^ ctx->r18;
    // 0x8000D140: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x8000D144: beq         $v0, $zero, L_8000D26C
    if (ctx->r2 == 0) {
        // 0x8000D148: addu        $s6, $s3, $v1
        ctx->r22 = ADD32(ctx->r19, ctx->r3);
            goto L_8000D26C;
    }
    // 0x8000D148: addu        $s6, $s3, $v1
    ctx->r22 = ADD32(ctx->r19, ctx->r3);
    // 0x8000D14C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000D150: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x8000D154: sltu        $v0, $s0, $v0
    ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x8000D158: bne         $v0, $zero, L_8000D244
    if (ctx->r2 != 0) {
        // 0x8000D15C: andi        $v0, $s2, 0x80
        ctx->r2 = ctx->r18 & 0X80;
            goto L_8000D244;
    }
    // 0x8000D15C: andi        $v0, $s2, 0x80
    ctx->r2 = ctx->r18 & 0X80;
    // 0x8000D160: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000D164: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000D168: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x8000D16C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000D170: bne         $a0, $zero, L_8000D1D0
    if (ctx->r4 != 0) {
        // 0x8000D174: sw          $zero, 0x4($s0)
        MEM_W(0X4, ctx->r16) = 0;
            goto L_8000D1D0;
    }
    // 0x8000D174: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8000D178: jal         0x8002221C
    // 0x8000D17C: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_1;
    // 0x8000D17C: nop

    after_1:
    // 0x8000D180: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000D184: beq         $a0, $zero, L_8000D1C8
    if (ctx->r4 == 0) {
        // 0x8000D188: nop
    
            goto L_8000D1C8;
    }
    // 0x8000D188: nop

    // 0x8000D18C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000D190: beq         $v0, $zero, L_8000D1A8
    if (ctx->r2 == 0) {
        // 0x8000D194: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000D1A8;
    }
    // 0x8000D194: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000D198:
    // 0x8000D198: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000D19C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000D1A0: bne         $v0, $zero, L_8000D198
    if (ctx->r2 != 0) {
        // 0x8000D1A4: nop
    
            goto L_8000D198;
    }
    // 0x8000D1A4: nop

L_8000D1A8:
    // 0x8000D1A8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000D1AC: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000D1B0: beq         $v0, $zero, L_8000D1BC
    if (ctx->r2 == 0) {
        // 0x8000D1B4: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000D1BC;
    }
    // 0x8000D1B4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000D1B8: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000D1BC:
    // 0x8000D1BC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000D1C0: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000D1C4: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000D1C8:
    // 0x8000D1C8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000D1CC: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000D1D0:
    // 0x8000D1D0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000D1D4: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000D1D8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000D1DC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000D1E0: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000D1E4: bnel        $v0, $zero, L_8000D1EC
    if (ctx->r2 != 0) {
        // 0x8000D1E8: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000D1EC;
    }
    goto skip_2;
    // 0x8000D1E8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_2:
L_8000D1EC:
    // 0x8000D1EC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000D1F0: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000D1F4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000D1F8: bne         $v0, $zero, L_8000D208
    if (ctx->r2 != 0) {
        // 0x8000D1FC: nop
    
            goto L_8000D208;
    }
    // 0x8000D1FC: nop

    // 0x8000D200: j           L_8000D220
    // 0x8000D204: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000D220;
    // 0x8000D204: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000D208:
    // 0x8000D208: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000D20C: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000D210: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000D214: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000D218: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000D21C: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000D220:
    // 0x8000D220: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000D224: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000D228: addiu       $s0, $a0, 0x8
    ctx->r16 = ADD32(ctx->r4, 0X8);
    // 0x8000D22C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000D230: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000D234: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000D238: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000D23C: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000D240: andi        $v0, $s2, 0x80
    ctx->r2 = ctx->r18 & 0X80;
L_8000D244:
    // 0x8000D244: beq         $v0, $zero, L_8000D258
    if (ctx->r2 == 0) {
        // 0x8000D248: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_8000D258;
    }
    // 0x8000D248: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8000D24C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8000D250: j           L_8000D260
    // 0x8000D254: lui         $v1, 0xB600
    ctx->r3 = S32(0XB600 << 16);
        goto L_8000D260;
    // 0x8000D254: lui         $v1, 0xB600
    ctx->r3 = S32(0XB600 << 16);
L_8000D258:
    // 0x8000D258: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8000D25C: lui         $v1, 0xB700
    ctx->r3 = S32(0XB700 << 16);
L_8000D260:
    // 0x8000D260: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8000D264: addiu       $v1, $zero, 0x2000
    ctx->r3 = ADD32(0, 0X2000);
    // 0x8000D268: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000D26C:
    // 0x8000D26C: andi        $v0, $s2, 0x2
    ctx->r2 = ctx->r18 & 0X2;
    // 0x8000D270: beq         $v0, $zero, L_8000D3A8
    if (ctx->r2 == 0) {
        // 0x8000D274: lui         $v1, 0x1
        ctx->r3 = S32(0X1 << 16);
            goto L_8000D3A8;
    }
    // 0x8000D274: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x8000D278: lw          $v0, 0xC($s5)
    ctx->r2 = MEM_W(ctx->r21, 0XC);
    // 0x8000D27C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8000D280: bne         $v0, $zero, L_8000D3AC
    if (ctx->r2 != 0) {
        // 0x8000D284: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_8000D3AC;
    }
    // 0x8000D284: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8000D288: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000D28C: lbu         $v0, -0x5768($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5768);
    // 0x8000D290: beq         $v0, $zero, L_8000D3B0
    if (ctx->r2 == 0) {
        // 0x8000D294: andi        $s1, $s2, 0x8
        ctx->r17 = ctx->r18 & 0X8;
            goto L_8000D3B0;
    }
    // 0x8000D294: andi        $s1, $s2, 0x8
    ctx->r17 = ctx->r18 & 0X8;
    // 0x8000D298: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000D29C: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x8000D2A0: sltu        $v0, $s0, $v0
    ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x8000D2A4: bne         $v0, $zero, L_8000D390
    if (ctx->r2 != 0) {
        // 0x8000D2A8: lui         $v0, 0xFA00
        ctx->r2 = S32(0XFA00 << 16);
            goto L_8000D390;
    }
    // 0x8000D2A8: lui         $v0, 0xFA00
    ctx->r2 = S32(0XFA00 << 16);
    // 0x8000D2AC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000D2B0: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000D2B4: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x8000D2B8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000D2BC: bne         $a0, $zero, L_8000D31C
    if (ctx->r4 != 0) {
        // 0x8000D2C0: sw          $zero, 0x4($s0)
        MEM_W(0X4, ctx->r16) = 0;
            goto L_8000D31C;
    }
    // 0x8000D2C0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8000D2C4: jal         0x8002221C
    // 0x8000D2C8: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_2;
    // 0x8000D2C8: nop

    after_2:
    // 0x8000D2CC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000D2D0: beq         $a0, $zero, L_8000D314
    if (ctx->r4 == 0) {
        // 0x8000D2D4: nop
    
            goto L_8000D314;
    }
    // 0x8000D2D4: nop

    // 0x8000D2D8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000D2DC: beq         $v0, $zero, L_8000D2F4
    if (ctx->r2 == 0) {
        // 0x8000D2E0: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000D2F4;
    }
    // 0x8000D2E0: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000D2E4:
    // 0x8000D2E4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000D2E8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000D2EC: bne         $v0, $zero, L_8000D2E4
    if (ctx->r2 != 0) {
        // 0x8000D2F0: nop
    
            goto L_8000D2E4;
    }
    // 0x8000D2F0: nop

L_8000D2F4:
    // 0x8000D2F4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000D2F8: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000D2FC: beq         $v0, $zero, L_8000D308
    if (ctx->r2 == 0) {
        // 0x8000D300: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000D308;
    }
    // 0x8000D300: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000D304: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000D308:
    // 0x8000D308: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000D30C: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000D310: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000D314:
    // 0x8000D314: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000D318: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000D31C:
    // 0x8000D31C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000D320: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    { ctx->r2 = (((uint64_t)ctx->r2 & 0xFFFFFFFFE0000000ULL) == 0xFFFFFFFF80000000ULL) ? MEM_W(ctx->r2, 0x0) : 0; }
    // 0x8000D324: nop

    // 0x8000D328: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000D32C: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000D330: bnel        $v0, $zero, L_8000D338
    if (ctx->r2 != 0) {
        // 0x8000D334: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000D338;
    }
    goto skip_3;
    // 0x8000D334: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_3:
L_8000D338:
    // 0x8000D338: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000D33C: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000D340: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000D344: bne         $v0, $zero, L_8000D354
    if (ctx->r2 != 0) {
        // 0x8000D348: nop
    
            goto L_8000D354;
    }
    // 0x8000D348: nop

    // 0x8000D34C: j           L_8000D36C
    // 0x8000D350: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000D36C;
    // 0x8000D350: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000D354:
    // 0x8000D354: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000D358: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000D35C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000D360: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000D364: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000D368: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000D36C:
    // 0x8000D36C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000D370: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000D374: addiu       $s0, $a0, 0x8
    ctx->r16 = ADD32(ctx->r4, 0X8);
    // 0x8000D378: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000D37C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000D380: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000D384: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000D388: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000D38C: lui         $v0, 0xFA00
    ctx->r2 = S32(0XFA00 << 16);
L_8000D390:
    // 0x8000D390: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // 0x8000D394: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x8000D398: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000D39C: lbu         $v0, 0x3($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X3);
    // 0x8000D3A0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8000D3A4: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_8000D3A8:
    // 0x8000D3A8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_8000D3AC:
    // 0x8000D3AC: andi        $s1, $s2, 0x8
    ctx->r17 = ctx->r18 & 0X8;
L_8000D3B0:
    // 0x8000D3B0: beq         $s1, $zero, L_8000D3BC
    if (ctx->r17 == 0) {
        // 0x8000D3B4: addiu       $a2, $sp, 0x30
        ctx->r6 = ADD32(ctx->r29, 0X30);
            goto L_8000D3BC;
    }
    // 0x8000D3B4: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x8000D3B8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
L_8000D3BC:
    // 0x8000D3BC: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    // 0x8000D3C0: lw          $v0, 0x2C($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X2C);
    // 0x8000D3C4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8000D3C8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8000D3CC: jal         0x8000898C
    // 0x8000D3D0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_8000898C(rdram, ctx);
        goto after_3;
    // 0x8000D3D0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_3:
    // 0x8000D3D4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000D3D8: andi        $v0, $s2, 0x30
    ctx->r2 = ctx->r18 & 0X30;
    // 0x8000D3DC: beql        $v0, $zero, L_8000D3F0
    if (ctx->r2 == 0) {
        // 0x8000D3E0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000D3F0;
    }
    goto skip_4;
    // 0x8000D3E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_4:
    // 0x8000D3E4: beq         $s1, $zero, L_8000D3F0
    if (ctx->r17 == 0) {
        // 0x8000D3E8: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8000D3F0;
    }
    // 0x8000D3E8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000D3EC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8000D3F0:
    // 0x8000D3F0: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8000D3F4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000D3F8: lbu         $v1, -0x5BC0($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X5BC0);
    // 0x8000D3FC: lw          $a1, 0x2C($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X2C);
    // 0x8000D400: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
    // 0x8000D404: addu        $v0, $v1, $s0
    ctx->r2 = ADD32(ctx->r3, ctx->r16);
    // 0x8000D408: slti        $v0, $v0, 0x41
    ctx->r2 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
    // 0x8000D40C: bne         $v0, $zero, L_8000D450
    if (ctx->r2 != 0) {
        // 0x8000D410: addu        $a3, $a0, $zero
        ctx->r7 = ADD32(ctx->r4, 0);
            goto L_8000D450;
    }
    // 0x8000D410: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x8000D414: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000D418: lw          $a2, -0x5BC8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X5BC8);
    // 0x8000D41C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8000D420: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x8000D424: andi        $v0, $v0, 0xFFF0
    ctx->r2 = ctx->r2 & 0XFFF0;
    // 0x8000D428: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000D42C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8000D430: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x8000D434: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8000D438: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x8000D43C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000D440: lw          $v0, -0x5BC4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5BC4);
    // 0x8000D444: jal         0x8000CB88
    // 0x8000D448: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    func_8000CB88(rdram, ctx);
        goto after_4;
    // 0x8000D448: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    after_4:
    // 0x8000D44C: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
L_8000D450:
    // 0x8000D450: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000D454: lbu         $v0, -0x5BC0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5BC0);
    // 0x8000D458: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8000D45C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000D460: bne         $s0, $v0, L_8000D47C
    if (ctx->r16 != ctx->r2) {
        // 0x8000D464: sb          $v1, 0x39($sp)
        MEM_B(0X39, ctx->r29) = ctx->r3;
            goto L_8000D47C;
    }
    // 0x8000D464: sb          $v1, 0x39($sp)
    MEM_B(0X39, ctx->r29) = ctx->r3;
    // 0x8000D468: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x8000D46C: sb          $v0, 0x38($sp)
    MEM_B(0X38, ctx->r29) = ctx->r2;
    // 0x8000D470: sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    // 0x8000D474: j           L_8000D4A8
    // 0x8000D478: sb          $v0, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = ctx->r2;
        goto L_8000D4A8;
    // 0x8000D478: sb          $v0, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = ctx->r2;
L_8000D47C:
    // 0x8000D47C: addiu       $v0, $v1, 0x4
    ctx->r2 = ADD32(ctx->r3, 0X4);
    // 0x8000D480: sb          $v0, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = ctx->r2;
    // 0x8000D484: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8000D488: sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    // 0x8000D48C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000D490: bne         $s0, $v0, L_8000D4A0
    if (ctx->r16 != ctx->r2) {
        // 0x8000D494: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_8000D4A0;
    }
    // 0x8000D494: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8000D498: j           L_8000D4A8
    // 0x8000D49C: sb          $a0, 0x38($sp)
    MEM_B(0X38, ctx->r29) = ctx->r4;
        goto L_8000D4A8;
    // 0x8000D49C: sb          $a0, 0x38($sp)
    MEM_B(0X38, ctx->r29) = ctx->r4;
L_8000D4A0:
    // 0x8000D4A0: addiu       $v0, $v1, 0xC
    ctx->r2 = ADD32(ctx->r3, 0XC);
    // 0x8000D4A4: sb          $v0, 0x38($sp)
    MEM_B(0X38, ctx->r29) = ctx->r2;
L_8000D4A8:
    // 0x8000D4A8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000D4AC: lbu         $a0, -0x5BC0($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X5BC0);
    // 0x8000D4B0: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // 0x8000D4B4: addu        $v0, $a0, $s1
    ctx->r2 = ADD32(ctx->r4, ctx->r17);
    // 0x8000D4B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D4BC: sb          $v0, -0x5BC0($at)
    MEM_B(-0X5BC0, ctx->r1) = ctx->r2;
    // 0x8000D4C0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000D4C4: lw          $v0, -0x5BC4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5BC4);
    // 0x8000D4C8: lw          $v1, 0xC($s5)
    ctx->r3 = MEM_W(ctx->r21, 0XC);
    // 0x8000D4CC: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8000D4D0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000D4D4: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x8000D4D8: beq         $v1, $zero, L_8000D584
    if (ctx->r3 == 0) {
        // 0x8000D4DC: sw          $v0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r2;
            goto L_8000D584;
    }
    // 0x8000D4DC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8000D4E0: lw          $t2, 0x24($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X24);
    // 0x8000D4E4: andi        $v0, $s2, 0x8
    ctx->r2 = ctx->r18 & 0X8;
    // 0x8000D4E8: beq         $v0, $zero, L_8000D4F4
    if (ctx->r2 == 0) {
        // 0x8000D4EC: addiu       $t1, $zero, 0x3
        ctx->r9 = ADD32(0, 0X3);
            goto L_8000D4F4;
    }
    // 0x8000D4EC: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8000D4F0: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
L_8000D4F4:
    // 0x8000D4F4: beq         $t1, $zero, L_8000D654
    if (ctx->r9 == 0) {
        // 0x8000D4F8: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_8000D654;
    }
    // 0x8000D4F8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8000D4FC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000D500: lwc1        $f4, 0x610($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X610);
    // 0x8000D504: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // 0x8000D508: addu        $t0, $s6, $zero
    ctx->r8 = ADD32(ctx->r22, 0);
L_8000D50C:
    // 0x8000D50C: lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X0);
    // 0x8000D510: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8000D514: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000D518: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8000D51C: addu        $v1, $t2, $v1
    ctx->r3 = ADD32(ctx->r10, ctx->r3);
    // 0x8000D520: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8000D524: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8000D528: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x8000D52C: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8000D530: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8000D534: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x8000D538: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8000D53C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8000D540: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x8000D544: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8000D548: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8000D54C: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    // 0x8000D550: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8000D554: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8000D558: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x8000D55C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000D560: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8000D564: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8000D568: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8000D56C: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
    // 0x8000D570: slt         $v0, $a2, $t1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8000D574: bne         $v0, $zero, L_8000D50C
    if (ctx->r2 != 0) {
        // 0x8000D578: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_8000D50C;
    }
    // 0x8000D578: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8000D57C: j           L_8000D658
    // 0x8000D580: andi        $v0, $s2, 0x4
    ctx->r2 = ctx->r18 & 0X4;
        goto L_8000D658;
    // 0x8000D580: andi        $v0, $s2, 0x4
    ctx->r2 = ctx->r18 & 0X4;
L_8000D584:
    // 0x8000D584: lhu         $v0, 0x0($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X0);
    // 0x8000D588: lw          $t0, 0x24($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X24);
    // 0x8000D58C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8000D590: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8000D594: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8000D598: lwl         $a0, 0x0($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r2, 0X0);
    // 0x8000D59C: lwr         $a0, 0x3($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r2, 0X3);
    // 0x8000D5A0: lwl         $a1, 0x4($v0)
    ctx->r5 = do_lwl(rdram, ctx->r5, ctx->r2, 0X4);
    // 0x8000D5A4: lwr         $a1, 0x7($v0)
    ctx->r5 = do_lwr(rdram, ctx->r5, ctx->r2, 0X7);
    // 0x8000D5A8: swl         $a0, 0x0($v1)
    do_swl(rdram, 0X0, ctx->r3, ctx->r4);
    // 0x8000D5AC: swr         $a0, 0x3($v1)
    do_swr(rdram, 0X3, ctx->r3, ctx->r4);
    // 0x8000D5B0: swl         $a1, 0x4($v1)
    do_swl(rdram, 0X4, ctx->r3, ctx->r5);
    // 0x8000D5B4: swr         $a1, 0x7($v1)
    do_swr(rdram, 0X7, ctx->r3, ctx->r5);
    // 0x8000D5B8: lhu         $v0, 0x2($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X2);
    // 0x8000D5BC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8000D5C0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8000D5C4: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8000D5C8: lwl         $a0, 0x0($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r2, 0X0);
    // 0x8000D5CC: lwr         $a0, 0x3($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r2, 0X3);
    // 0x8000D5D0: lwl         $a1, 0x4($v0)
    ctx->r5 = do_lwl(rdram, ctx->r5, ctx->r2, 0X4);
    // 0x8000D5D4: lwr         $a1, 0x7($v0)
    ctx->r5 = do_lwr(rdram, ctx->r5, ctx->r2, 0X7);
    // 0x8000D5D8: swl         $a0, 0x0($v1)
    do_swl(rdram, 0X0, ctx->r3, ctx->r4);
    // 0x8000D5DC: swr         $a0, 0x3($v1)
    do_swr(rdram, 0X3, ctx->r3, ctx->r4);
    // 0x8000D5E0: swl         $a1, 0x4($v1)
    do_swl(rdram, 0X4, ctx->r3, ctx->r5);
    // 0x8000D5E4: swr         $a1, 0x7($v1)
    do_swr(rdram, 0X7, ctx->r3, ctx->r5);
    // 0x8000D5E8: lhu         $v0, 0x4($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X4);
    // 0x8000D5EC: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8000D5F0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8000D5F4: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8000D5F8: lwl         $a0, 0x0($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r2, 0X0);
    // 0x8000D5FC: lwr         $a0, 0x3($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r2, 0X3);
    // 0x8000D600: lwl         $a1, 0x4($v0)
    ctx->r5 = do_lwl(rdram, ctx->r5, ctx->r2, 0X4);
    // 0x8000D604: lwr         $a1, 0x7($v0)
    ctx->r5 = do_lwr(rdram, ctx->r5, ctx->r2, 0X7);
    // 0x8000D608: swl         $a0, 0x0($v1)
    do_swl(rdram, 0X0, ctx->r3, ctx->r4);
    // 0x8000D60C: swr         $a0, 0x3($v1)
    do_swr(rdram, 0X3, ctx->r3, ctx->r4);
    // 0x8000D610: swl         $a1, 0x4($v1)
    do_swl(rdram, 0X4, ctx->r3, ctx->r5);
    // 0x8000D614: swr         $a1, 0x7($v1)
    do_swr(rdram, 0X7, ctx->r3, ctx->r5);
    // 0x8000D618: andi        $v0, $s2, 0x8
    ctx->r2 = ctx->r18 & 0X8;
    // 0x8000D61C: beq         $v0, $zero, L_8000D658
    if (ctx->r2 == 0) {
        // 0x8000D620: andi        $v0, $s2, 0x4
        ctx->r2 = ctx->r18 & 0X4;
            goto L_8000D658;
    }
    // 0x8000D620: andi        $v0, $s2, 0x4
    ctx->r2 = ctx->r18 & 0X4;
    // 0x8000D624: lhu         $v0, 0x6($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X6);
    // 0x8000D628: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8000D62C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8000D630: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8000D634: lwl         $a0, 0x0($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r2, 0X0);
    // 0x8000D638: lwr         $a0, 0x3($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r2, 0X3);
    // 0x8000D63C: lwl         $a1, 0x4($v0)
    ctx->r5 = do_lwl(rdram, ctx->r5, ctx->r2, 0X4);
    // 0x8000D640: lwr         $a1, 0x7($v0)
    ctx->r5 = do_lwr(rdram, ctx->r5, ctx->r2, 0X7);
    // 0x8000D644: swl         $a0, 0x0($v1)
    do_swl(rdram, 0X0, ctx->r3, ctx->r4);
    // 0x8000D648: swr         $a0, 0x3($v1)
    do_swr(rdram, 0X3, ctx->r3, ctx->r4);
    // 0x8000D64C: swl         $a1, 0x4($v1)
    do_swl(rdram, 0X4, ctx->r3, ctx->r5);
    // 0x8000D650: swr         $a1, 0x7($v1)
    do_swr(rdram, 0X7, ctx->r3, ctx->r5);
L_8000D654:
    // 0x8000D654: andi        $v0, $s2, 0x4
    ctx->r2 = ctx->r18 & 0X4;
L_8000D658:
    // 0x8000D658: beq         $v0, $zero, L_8000D664
    if (ctx->r2 == 0) {
        // 0x8000D65C: addiu       $s1, $zero, 0x2
        ctx->r17 = ADD32(0, 0X2);
            goto L_8000D664;
    }
    // 0x8000D65C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x8000D660: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_8000D664:
    // 0x8000D664: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000D668: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x8000D66C: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
    // 0x8000D670: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x8000D674: sltu        $v1, $v1, $v0
    ctx->r3 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000D678: beq         $v1, $zero, L_8000D75C
    if (ctx->r3 == 0) {
        // 0x8000D67C: lui         $v0, 0xB500
        ctx->r2 = S32(0XB500 << 16);
            goto L_8000D75C;
    }
    // 0x8000D67C: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x8000D680: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000D684: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000D688: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000D68C: bne         $a0, $zero, L_8000D6EC
    if (ctx->r4 != 0) {
        // 0x8000D690: sw          $zero, 0x4($s0)
        MEM_W(0X4, ctx->r16) = 0;
            goto L_8000D6EC;
    }
    // 0x8000D690: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8000D694: jal         0x8002221C
    // 0x8000D698: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_5;
    // 0x8000D698: nop

    after_5:
    // 0x8000D69C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000D6A0: beq         $a0, $zero, L_8000D6E4
    if (ctx->r4 == 0) {
        // 0x8000D6A4: nop
    
            goto L_8000D6E4;
    }
    // 0x8000D6A4: nop

    // 0x8000D6A8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000D6AC: beq         $v0, $zero, L_8000D6C4
    if (ctx->r2 == 0) {
        // 0x8000D6B0: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000D6C4;
    }
    // 0x8000D6B0: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000D6B4:
    // 0x8000D6B4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000D6B8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000D6BC: bne         $v0, $zero, L_8000D6B4
    if (ctx->r2 != 0) {
        // 0x8000D6C0: nop
    
            goto L_8000D6B4;
    }
    // 0x8000D6C0: nop

L_8000D6C4:
    // 0x8000D6C4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000D6C8: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000D6CC: beq         $v0, $zero, L_8000D6D8
    if (ctx->r2 == 0) {
        // 0x8000D6D0: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000D6D8;
    }
    // 0x8000D6D0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000D6D4: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000D6D8:
    // 0x8000D6D8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000D6DC: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000D6E0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000D6E4:
    // 0x8000D6E4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000D6E8: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000D6EC:
    // 0x8000D6EC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000D6F0: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000D6F4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000D6F8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000D6FC: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000D700: bnel        $v0, $zero, L_8000D708
    if (ctx->r2 != 0) {
        // 0x8000D704: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000D708;
    }
    goto skip_5;
    // 0x8000D704: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_5:
L_8000D708:
    // 0x8000D708: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000D70C: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000D710: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000D714: bne         $v0, $zero, L_8000D724
    if (ctx->r2 != 0) {
        // 0x8000D718: nop
    
            goto L_8000D724;
    }
    // 0x8000D718: nop

    // 0x8000D71C: j           L_8000D73C
    // 0x8000D720: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000D73C;
    // 0x8000D720: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000D724:
    // 0x8000D724: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000D728: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000D72C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000D730: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000D734: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000D738: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000D73C:
    // 0x8000D73C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000D740: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000D744: addiu       $s0, $a0, 0x8
    ctx->r16 = ADD32(ctx->r4, 0X8);
    // 0x8000D748: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000D74C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000D750: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000D754: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000D758: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
L_8000D75C:
    // 0x8000D75C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8000D760: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x8000D764: lbu         $v0, 0x30($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X30);
    // 0x8000D768: lbu         $a0, 0x31($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X31);
    // 0x8000D76C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8000D770: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000D774: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8000D778: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8000D77C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000D780: lbu         $a0, 0x32($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X32);
    // 0x8000D784: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8000D788: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8000D78C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8000D790: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000D794: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8000D798: andi        $v0, $s2, 0x8
    ctx->r2 = ctx->r18 & 0X8;
    // 0x8000D79C: beq         $v0, $zero, L_8000D7BC
    if (ctx->r2 == 0) {
        // 0x8000D7A0: sw          $v1, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->r3;
            goto L_8000D7BC;
    }
    // 0x8000D7A0: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x8000D7A4: lui         $v0, 0xB400
    ctx->r2 = S32(0XB400 << 16);
    // 0x8000D7A8: ori         $v0, $v0, 0x4
    ctx->r2 = ctx->r2 | 0X4;
    // 0x8000D7AC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000D7B0: lbu         $a0, 0x33($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X33);
    // 0x8000D7B4: j           L_8000D7C8
    // 0x8000D7B8: nop

        goto L_8000D7C8;
    // 0x8000D7B8: nop

L_8000D7BC:
    // 0x8000D7BC: lui         $v0, 0xBF00
    ctx->r2 = S32(0XBF00 << 16);
    // 0x8000D7C0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000D7C4: lbu         $a0, 0x30($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X30);
L_8000D7C8:
    // 0x8000D7C8: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x8000D7CC: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8000D7D0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000D7D4: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8000D7D8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8000D7DC: andi        $v0, $s2, 0x4
    ctx->r2 = ctx->r18 & 0X4;
    // 0x8000D7E0: beq         $v0, $zero, L_8000D8A4
    if (ctx->r2 == 0) {
        // 0x8000D7E4: sw          $v1, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->r3;
            goto L_8000D8A4;
    }
    // 0x8000D7E4: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x8000D7E8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000D7EC: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // 0x8000D7F0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000D7F4: lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X4);
    // 0x8000D7F8: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    // 0x8000D7FC: lw          $v1, 0x8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X8);
    // 0x8000D800: andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // 0x8000D804: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000D808: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x8000D80C: beq         $v1, $zero, L_8000D878
    if (ctx->r3 == 0) {
        // 0x8000D810: addu        $a0, $s3, $v0
        ctx->r4 = ADD32(ctx->r19, ctx->r2);
            goto L_8000D878;
    }
    // 0x8000D810: addu        $a0, $s3, $v0
    ctx->r4 = ADD32(ctx->r19, ctx->r2);
    // 0x8000D814: andi        $v0, $s2, 0x8
    ctx->r2 = ctx->r18 & 0X8;
    // 0x8000D818: beq         $v0, $zero, L_8000D824
    if (ctx->r2 == 0) {
        // 0x8000D81C: addiu       $t1, $zero, 0x3
        ctx->r9 = ADD32(0, 0X3);
            goto L_8000D824;
    }
    // 0x8000D81C: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8000D820: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
L_8000D824:
    // 0x8000D824: beq         $t1, $zero, L_8000D8A4
    if (ctx->r9 == 0) {
        // 0x8000D828: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_8000D8A4;
    }
    // 0x8000D828: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8000D82C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000D830: lwc1        $f4, 0x614($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X614);
L_8000D834:
    // 0x8000D834: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000D838: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8000D83C: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8000D840: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8000D844: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8000D848: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8000D84C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8000D850: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000D854: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000D858: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8000D85C: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8000D860: sh          $v0, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r2;
    // 0x8000D864: slt         $v0, $a2, $t1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8000D868: bne         $v0, $zero, L_8000D834
    if (ctx->r2 != 0) {
        // 0x8000D86C: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8000D834;
    }
    // 0x8000D86C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8000D870: j           L_8000D8A8
    // 0x8000D874: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
        goto L_8000D8A8;
    // 0x8000D874: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
L_8000D878:
    // 0x8000D878: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000D87C: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x8000D880: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8000D884: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x8000D888: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x8000D88C: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x8000D890: andi        $v0, $s2, 0x8
    ctx->r2 = ctx->r18 & 0X8;
    // 0x8000D894: beq         $v0, $zero, L_8000D8A8
    if (ctx->r2 == 0) {
        // 0x8000D898: sll         $v0, $s1, 3
        ctx->r2 = S32(ctx->r17 << 3);
            goto L_8000D8A8;
    }
    // 0x8000D898: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
    // 0x8000D89C: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x8000D8A0: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
L_8000D8A4:
    // 0x8000D8A4: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
L_8000D8A8:
    // 0x8000D8A8: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x8000D8AC: andi        $v0, $s2, 0x40
    ctx->r2 = ctx->r18 & 0X40;
    // 0x8000D8B0: beq         $v0, $zero, L_8000D924
    if (ctx->r2 == 0) {
        // 0x8000D8B4: lui         $v1, 0x10
        ctx->r3 = S32(0X10 << 16);
            goto L_8000D924;
    }
    // 0x8000D8B4: lui         $v1, 0x10
    ctx->r3 = S32(0X10 << 16);
    // 0x8000D8B8: lw          $v0, 0xC($s5)
    ctx->r2 = MEM_W(ctx->r21, 0XC);
    // 0x8000D8BC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8000D8C0: bne         $v0, $zero, L_8000D924
    if (ctx->r2 != 0) {
        // 0x8000D8C4: nop
    
            goto L_8000D924;
    }
    // 0x8000D8C4: nop

    // 0x8000D8C8: lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X4);
    // 0x8000D8CC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000D8D0: lw          $v1, 0x63B4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63B4);
    // 0x8000D8D4: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8000D8D8: andi        $v0, $v0, 0xFC0
    ctx->r2 = ctx->r2 & 0XFC0;
    // 0x8000D8DC: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x8000D8E0: beq         $v1, $zero, L_8000D8F8
    if (ctx->r3 == 0) {
        // 0x8000D8E4: addu        $a3, $s3, $v0
        ctx->r7 = ADD32(ctx->r19, ctx->r2);
            goto L_8000D8F8;
    }
    // 0x8000D8E4: addu        $a3, $s3, $v0
    ctx->r7 = ADD32(ctx->r19, ctx->r2);
    // 0x8000D8E8: lhu         $v0, 0x8($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X8);
    // 0x8000D8EC: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8000D8F0: j           L_8000D900
    // 0x8000D8F4: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
        goto L_8000D900;
    // 0x8000D8F4: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
L_8000D8F8:
    // 0x8000D8F8: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x8000D8FC: addiu       $v0, $v0, 0x7640
    ctx->r2 = ADD32(ctx->r2, 0X7640);
L_8000D900:
    // 0x8000D900: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8000D904: sw          $s7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r23;
    // 0x8000D908: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x8000D90C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8000D910: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // 0x8000D914: jal         0x80018818
    // 0x8000D918: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    func_80018818(rdram, ctx);
        goto after_6;
    // 0x8000D918: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_6:
    // 0x8000D91C: j           L_8000D998
    // 0x8000D920: nop

        goto L_8000D998;
    // 0x8000D920: nop

L_8000D924:
    // 0x8000D924: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8000D928: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8000D92C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8000D930: andi        $v0, $s2, 0x10
    ctx->r2 = ctx->r18 & 0X10;
    // 0x8000D934: beq         $v0, $zero, L_8000D968
    if (ctx->r2 == 0) {
        // 0x8000D938: andi        $v0, $s2, 0x20
        ctx->r2 = ctx->r18 & 0X20;
            goto L_8000D968;
    }
    // 0x8000D938: andi        $v0, $s2, 0x20
    ctx->r2 = ctx->r18 & 0X20;
    // 0x8000D93C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8000D940: lw          $v0, 0x4($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X4);
    // 0x8000D944: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8000D948: lw          $v0, 0x8($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X8);
    // 0x8000D94C: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8000D950: andi        $v0, $s2, 0x8
    ctx->r2 = ctx->r18 & 0X8;
    // 0x8000D954: beq         $v0, $zero, L_8000D998
    if (ctx->r2 == 0) {
        // 0x8000D958: nop
    
            goto L_8000D998;
    }
    // 0x8000D958: nop

    // 0x8000D95C: lw          $v0, 0xC($s4)
    ctx->r2 = MEM_W(ctx->r20, 0XC);
    // 0x8000D960: j           L_8000D998
    // 0x8000D964: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
        goto L_8000D998;
    // 0x8000D964: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
L_8000D968:
    // 0x8000D968: beq         $v0, $zero, L_8000D998
    if (ctx->r2 == 0) {
        // 0x8000D96C: nop
    
            goto L_8000D998;
    }
    // 0x8000D96C: nop

    // 0x8000D970: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8000D974: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8000D978: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8000D97C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8000D980: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8000D984: andi        $v0, $s2, 0x8
    ctx->r2 = ctx->r18 & 0X8;
    // 0x8000D988: beq         $v0, $zero, L_8000D998
    if (ctx->r2 == 0) {
        // 0x8000D98C: nop
    
            goto L_8000D998;
    }
    // 0x8000D98C: nop

    // 0x8000D990: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8000D994: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
L_8000D998:
    // 0x8000D998: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D99C: sw          $s0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r16;
    // 0x8000D9A0: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x8000D9A4: lw          $ra, 0x70($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X70);
    // 0x8000D9A8: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x8000D9AC: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x8000D9B0: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x8000D9B4: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x8000D9B8: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x8000D9BC: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x8000D9C0: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x8000D9C4: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x8000D9C8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8000D9CC: jr          $ra
    // 0x8000D9D0: nop

    return;
    // 0x8000D9D0: nop

;}
RECOMP_FUNC void func_8000D9D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D9D4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8000D9D8: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8000D9DC: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x8000D9E0: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x8000D9E4: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8000D9E8: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x8000D9EC: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8000D9F0: lw          $s1, 0x68($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X68);
    // 0x8000D9F4: addu        $t5, $a0, $zero
    ctx->r13 = ADD32(ctx->r4, 0);
    // 0x8000D9F8: addu        $t8, $a1, $zero
    ctx->r24 = ADD32(ctx->r5, 0);
    // 0x8000D9FC: sw          $ra, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r31;
    // 0x8000DA00: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8000DA04: lw          $v0, 0x4($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X4);
    // 0x8000DA08: lbu         $a1, 0x6F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X6F);
    // 0x8000DA0C: lbu         $a0, 0x73($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X73);
    // 0x8000DA10: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x8000DA14: srl         $v1, $v0, 16
    ctx->r3 = S32(U32(ctx->r2) >> 16);
    // 0x8000DA18: andi        $v1, $v1, 0xFC
    ctx->r3 = ctx->r3 & 0XFC;
    // 0x8000DA1C: addu        $s0, $t5, $v1
    ctx->r16 = ADD32(ctx->r13, ctx->r3);
    // 0x8000DA20: srl         $v0, $v0, 10
    ctx->r2 = S32(U32(ctx->r2) >> 10);
    // 0x8000DA24: lw          $v1, 0xC($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XC);
    // 0x8000DA28: andi        $v0, $v0, 0xFC
    ctx->r2 = ctx->r2 & 0XFC;
    // 0x8000DA2C: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8000DA30: andi        $v0, $v1, 0x40
    ctx->r2 = ctx->r3 & 0X40;
    // 0x8000DA34: beq         $v0, $zero, L_8000DB58
    if (ctx->r2 == 0) {
        // 0x8000DA38: andi        $v0, $t4, 0x8
        ctx->r2 = ctx->r12 & 0X8;
            goto L_8000DB58;
    }
    // 0x8000DA38: andi        $v0, $t4, 0x8
    ctx->r2 = ctx->r12 & 0X8;
    // 0x8000DA3C: beq         $v0, $zero, L_8000DA48
    if (ctx->r2 == 0) {
        // 0x8000DA40: addiu       $t3, $zero, 0x3
        ctx->r11 = ADD32(0, 0X3);
            goto L_8000DA48;
    }
    // 0x8000DA40: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8000DA44: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
L_8000DA48:
    // 0x8000DA48: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x8000DA4C: beq         $v0, $zero, L_8000DAEC
    if (ctx->r2 == 0) {
        // 0x8000DA50: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_8000DAEC;
    }
    // 0x8000DA50: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8000DA54: lw          $t1, 0x24($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X24);
    // 0x8000DA58: beq         $t3, $zero, L_8000DBA0
    if (ctx->r11 == 0) {
        // 0x8000DA5C: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_8000DBA0;
    }
    // 0x8000DA5C: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8000DA60: andi        $a2, $a1, 0xFF
    ctx->r6 = ctx->r5 & 0XFF;
    // 0x8000DA64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000DA68: lwc1        $f4, 0x618($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X618);
    // 0x8000DA6C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_8000DA70:
    // 0x8000DA70: and         $v0, $a2, $t2
    ctx->r2 = ctx->r6 & ctx->r10;
    // 0x8000DA74: beql        $v0, $zero, L_8000DAD4
    if (ctx->r2 == 0) {
        // 0x8000DA78: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_8000DAD4;
    }
    goto skip_0;
    // 0x8000DA78: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    skip_0:
    // 0x8000DA7C: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8000DA80: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8000DA84: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000DA88: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8000DA8C: addu        $v1, $t1, $v1
    ctx->r3 = ADD32(ctx->r9, ctx->r3);
    // 0x8000DA90: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8000DA94: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8000DA98: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8000DA9C: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8000DAA0: sh          $v0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r2;
    // 0x8000DAA4: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8000DAA8: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8000DAAC: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8000DAB0: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8000DAB4: sh          $v0, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r2;
    // 0x8000DAB8: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8000DABC: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8000DAC0: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8000DAC4: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8000DAC8: sh          $v0, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r2;
    // 0x8000DACC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8000DAD0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
L_8000DAD4:
    // 0x8000DAD4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8000DAD8: slt         $v0, $t0, $t3
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8000DADC: bne         $v0, $zero, L_8000DA70
    if (ctx->r2 != 0) {
        // 0x8000DAE0: sll         $t2, $t2, 1
        ctx->r10 = S32(ctx->r10 << 1);
            goto L_8000DA70;
    }
    // 0x8000DAE0: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8000DAE4: j           L_8000DBA0
    // 0x8000DAE8: nop

        goto L_8000DBA0;
    // 0x8000DAE8: nop

L_8000DAEC:
    // 0x8000DAEC: lw          $t9, 0x24($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X24);
    // 0x8000DAF0: beq         $t3, $zero, L_8000DBA0
    if (ctx->r11 == 0) {
        // 0x8000DAF4: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_8000DBA0;
    }
    // 0x8000DAF4: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8000DAF8: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x8000DAFC: addu        $t1, $s0, $zero
    ctx->r9 = ADD32(ctx->r16, 0);
L_8000DB00:
    // 0x8000DB00: and         $v0, $t7, $t2
    ctx->r2 = ctx->r15 & ctx->r10;
    // 0x8000DB04: beql        $v0, $zero, L_8000DB40
    if (ctx->r2 == 0) {
        // 0x8000DB08: addiu       $t1, $t1, 0x2
        ctx->r9 = ADD32(ctx->r9, 0X2);
            goto L_8000DB40;
    }
    goto skip_1;
    // 0x8000DB08: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    skip_1:
    // 0x8000DB0C: lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X0);
    // 0x8000DB10: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8000DB14: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8000DB18: lwl         $v1, 0x0($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r2, 0X0);
    // 0x8000DB1C: lwr         $v1, 0x3($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r2, 0X3);
    // 0x8000DB20: lwl         $a0, 0x4($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r2, 0X4);
    // 0x8000DB24: lwr         $a0, 0x7($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r2, 0X7);
    // 0x8000DB28: swl         $v1, 0x0($a3)
    do_swl(rdram, 0X0, ctx->r7, ctx->r3);
    // 0x8000DB2C: swr         $v1, 0x3($a3)
    do_swr(rdram, 0X3, ctx->r7, ctx->r3);
    // 0x8000DB30: swl         $a0, 0x4($a3)
    do_swl(rdram, 0X4, ctx->r7, ctx->r4);
    // 0x8000DB34: swr         $a0, 0x7($a3)
    do_swr(rdram, 0X7, ctx->r7, ctx->r4);
    // 0x8000DB38: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8000DB3C: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
L_8000DB40:
    // 0x8000DB40: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8000DB44: slt         $v0, $t0, $t3
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8000DB48: bne         $v0, $zero, L_8000DB00
    if (ctx->r2 != 0) {
        // 0x8000DB4C: sll         $t2, $t2, 1
        ctx->r10 = S32(ctx->r10 << 1);
            goto L_8000DB00;
    }
    // 0x8000DB4C: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8000DB50: j           L_8000DBA0
    // 0x8000DB54: nop

        goto L_8000DBA0;
    // 0x8000DB54: nop

L_8000DB58:
    // 0x8000DB58: beq         $a2, $zero, L_8000DBA0
    if (ctx->r6 == 0) {
        // 0x8000DB5C: nop
    
            goto L_8000DBA0;
    }
    // 0x8000DB5C: nop

    // 0x8000DB60: andi        $t1, $a0, 0xFF
    ctx->r9 = ctx->r4 & 0XFF;
    // 0x8000DB64: blez        $t1, L_8000DBA0
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8000DB68: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_8000DBA0;
    }
    // 0x8000DB68: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
L_8000DB6C:
    // 0x8000DB6C: lwl         $v0, 0x0($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r6, 0X0);
    // 0x8000DB70: lwr         $v0, 0x3($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r6, 0X3);
    // 0x8000DB74: lwl         $v1, 0x4($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r6, 0X4);
    // 0x8000DB78: lwr         $v1, 0x7($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r6, 0X7);
    // 0x8000DB7C: swl         $v0, 0x0($a3)
    do_swl(rdram, 0X0, ctx->r7, ctx->r2);
    // 0x8000DB80: swr         $v0, 0x3($a3)
    do_swr(rdram, 0X3, ctx->r7, ctx->r2);
    // 0x8000DB84: swl         $v1, 0x4($a3)
    do_swl(rdram, 0X4, ctx->r7, ctx->r3);
    // 0x8000DB88: swr         $v1, 0x7($a3)
    do_swr(rdram, 0X7, ctx->r7, ctx->r3);
    // 0x8000DB8C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8000DB90: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8000DB94: slt         $v0, $t0, $t1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8000DB98: bne         $v0, $zero, L_8000DB6C
    if (ctx->r2 != 0) {
        // 0x8000DB9C: addiu       $a2, $a2, 0x8
        ctx->r6 = ADD32(ctx->r6, 0X8);
            goto L_8000DB6C;
    }
    // 0x8000DB9C: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
L_8000DBA0:
    // 0x8000DBA0: lw          $v1, 0xC($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XC);
    // 0x8000DBA4: andi        $v0, $v1, 0x20
    ctx->r2 = ctx->r3 & 0X20;
    // 0x8000DBA8: beq         $v0, $zero, L_8000DC8C
    if (ctx->r2 == 0) {
        // 0x8000DBAC: andi        $v0, $t4, 0x40
        ctx->r2 = ctx->r12 & 0X40;
            goto L_8000DC8C;
    }
    // 0x8000DBAC: andi        $v0, $t4, 0x40
    ctx->r2 = ctx->r12 & 0X40;
    // 0x8000DBB0: beq         $v0, $zero, L_8000DC20
    if (ctx->r2 == 0) {
        // 0x8000DBB4: lui         $v0, 0x10
        ctx->r2 = S32(0X10 << 16);
            goto L_8000DC20;
    }
    // 0x8000DBB4: lui         $v0, 0x10
    ctx->r2 = S32(0X10 << 16);
    // 0x8000DBB8: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8000DBBC: bne         $v0, $zero, L_8000DC20
    if (ctx->r2 != 0) {
        // 0x8000DBC0: nop
    
            goto L_8000DC20;
    }
    // 0x8000DBC0: nop

    // 0x8000DBC4: lw          $v0, 0x4($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X4);
    // 0x8000DBC8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000DBCC: lw          $v1, 0x63B4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63B4);
    // 0x8000DBD0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8000DBD4: andi        $v0, $v0, 0xFC0
    ctx->r2 = ctx->r2 & 0XFC0;
    // 0x8000DBD8: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x8000DBDC: beq         $v1, $zero, L_8000DBF4
    if (ctx->r3 == 0) {
        // 0x8000DBE0: addu        $a3, $t5, $v0
        ctx->r7 = ADD32(ctx->r13, ctx->r2);
            goto L_8000DBF4;
    }
    // 0x8000DBE0: addu        $a3, $t5, $v0
    ctx->r7 = ADD32(ctx->r13, ctx->r2);
    // 0x8000DBE4: lhu         $v0, 0x8($t5)
    ctx->r2 = MEM_HU(ctx->r13, 0X8);
    // 0x8000DBE8: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8000DBEC: j           L_8000DBFC
    // 0x8000DBF0: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
        goto L_8000DBFC;
    // 0x8000DBF0: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
L_8000DBF4:
    // 0x8000DBF4: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x8000DBF8: addiu       $v0, $v0, 0x7640
    ctx->r2 = ADD32(ctx->r2, 0X7640);
L_8000DBFC:
    // 0x8000DBFC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8000DC00: addu        $a0, $t8, $zero
    ctx->r4 = ADD32(ctx->r24, 0);
    // 0x8000DC04: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8000DC08: addu        $a2, $t6, $zero
    ctx->r6 = ADD32(ctx->r14, 0);
    // 0x8000DC0C: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    // 0x8000DC10: jal         0x80018818
    // 0x8000DC14: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    func_80018818(rdram, ctx);
        goto after_0;
    // 0x8000DC14: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_0:
    // 0x8000DC18: j           L_8000DCDC
    // 0x8000DC1C: nop

        goto L_8000DCDC;
    // 0x8000DC1C: nop

L_8000DC20:
    // 0x8000DC20: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8000DC24: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x8000DC28: andi        $v0, $t4, 0x10
    ctx->r2 = ctx->r12 & 0X10;
    // 0x8000DC2C: beq         $v0, $zero, L_8000DC5C
    if (ctx->r2 == 0) {
        // 0x8000DC30: andi        $v0, $t4, 0x20
        ctx->r2 = ctx->r12 & 0X20;
            goto L_8000DC5C;
    }
    // 0x8000DC30: andi        $v0, $t4, 0x20
    ctx->r2 = ctx->r12 & 0X20;
    // 0x8000DC34: lw          $v0, 0x4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4);
    // 0x8000DC38: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
    // 0x8000DC3C: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
    // 0x8000DC40: sw          $v0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r2;
    // 0x8000DC44: andi        $v0, $t4, 0x8
    ctx->r2 = ctx->r12 & 0X8;
    // 0x8000DC48: beq         $v0, $zero, L_8000DCDC
    if (ctx->r2 == 0) {
        // 0x8000DC4C: nop
    
            goto L_8000DCDC;
    }
    // 0x8000DC4C: nop

    // 0x8000DC50: lw          $v0, 0xC($t6)
    ctx->r2 = MEM_W(ctx->r14, 0XC);
    // 0x8000DC54: j           L_8000DCDC
    // 0x8000DC58: sw          $v0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r2;
        goto L_8000DCDC;
    // 0x8000DC58: sw          $v0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r2;
L_8000DC5C:
    // 0x8000DC5C: beq         $v0, $zero, L_8000DCDC
    if (ctx->r2 == 0) {
        // 0x8000DC60: nop
    
            goto L_8000DCDC;
    }
    // 0x8000DC60: nop

    // 0x8000DC64: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8000DC68: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
    // 0x8000DC6C: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8000DC70: sw          $v0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r2;
    // 0x8000DC74: andi        $v0, $t4, 0x8
    ctx->r2 = ctx->r12 & 0X8;
    // 0x8000DC78: beq         $v0, $zero, L_8000DCDC
    if (ctx->r2 == 0) {
        // 0x8000DC7C: nop
    
            goto L_8000DCDC;
    }
    // 0x8000DC7C: nop

    // 0x8000DC80: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8000DC84: j           L_8000DCDC
    // 0x8000DC88: sw          $v0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r2;
        goto L_8000DCDC;
    // 0x8000DC88: sw          $v0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r2;
L_8000DC8C:
    // 0x8000DC8C: beq         $s2, $zero, L_8000DCDC
    if (ctx->r18 == 0) {
        // 0x8000DC90: andi        $v0, $t4, 0x30
        ctx->r2 = ctx->r12 & 0X30;
            goto L_8000DCDC;
    }
    // 0x8000DC90: andi        $v0, $t4, 0x30
    ctx->r2 = ctx->r12 & 0X30;
    // 0x8000DC94: beq         $v0, $zero, L_8000DCB0
    if (ctx->r2 == 0) {
        // 0x8000DC98: andi        $v0, $t4, 0x8
        ctx->r2 = ctx->r12 & 0X8;
            goto L_8000DCB0;
    }
    // 0x8000DC98: andi        $v0, $t4, 0x8
    ctx->r2 = ctx->r12 & 0X8;
    // 0x8000DC9C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8000DCA0: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8000DCA4: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x8000DCA8: j           L_8000DCB4
    // 0x8000DCAC: ori         $t0, $v0, 0x2
    ctx->r8 = ctx->r2 | 0X2;
        goto L_8000DCB4;
    // 0x8000DCAC: ori         $t0, $v0, 0x2
    ctx->r8 = ctx->r2 | 0X2;
L_8000DCB0:
    // 0x8000DCB0: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
L_8000DCB4:
    // 0x8000DCB4: bltz        $t0, L_8000DCDC
    if (SIGNED(ctx->r8) < 0) {
        // 0x8000DCB8: sll         $v0, $t0, 2
        ctx->r2 = S32(ctx->r8 << 2);
            goto L_8000DCDC;
    }
    // 0x8000DCB8: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x8000DCBC: addu        $a0, $v0, $t8
    ctx->r4 = ADD32(ctx->r2, ctx->r24);
    // 0x8000DCC0: addu        $a2, $v0, $s2
    ctx->r6 = ADD32(ctx->r2, ctx->r18);
L_8000DCC4:
    // 0x8000DCC4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8000DCC8: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x8000DCCC: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8000DCD0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8000DCD4: bgez        $t0, L_8000DCC4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8000DCD8: addiu       $a0, $a0, -0x4
        ctx->r4 = ADD32(ctx->r4, -0X4);
            goto L_8000DCC4;
    }
    // 0x8000DCD8: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
L_8000DCDC:
    // 0x8000DCDC: lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X48);
    // 0x8000DCE0: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8000DCE4: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8000DCE8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8000DCEC: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8000DCF0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8000DCF4: jr          $ra
    // 0x8000DCF8: nop

    return;
    // 0x8000DCF8: nop

;}
RECOMP_FUNC void func_8000DCFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DCFC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8000DD00: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8000DD04: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8000DD08: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000DD0C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8000DD10: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8000DD14: lbu         $v1, 0x8($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X8);
    // 0x8000DD18: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8000DD1C: beq         $v1, $v0, L_8000DD74
    if (ctx->r3 == ctx->r2) {
        // 0x8000DD20: addu        $s2, $a1, $zero
        ctx->r18 = ADD32(ctx->r5, 0);
            goto L_8000DD74;
    }
    // 0x8000DD20: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8000DD24: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8000DD28: beq         $v0, $zero, L_8000DD40
    if (ctx->r2 == 0) {
        // 0x8000DD2C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000DD40;
    }
    // 0x8000DD2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000DD30: beq         $v1, $v0, L_8000DD54
    if (ctx->r3 == ctx->r2) {
        // 0x8000DD34: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_8000DD54;
    }
    // 0x8000DD34: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8000DD38: j           L_8000DE54
    // 0x8000DD3C: nop

        goto L_8000DE54;
    // 0x8000DD3C: nop

L_8000DD40:
    // 0x8000DD40: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000DD44: beq         $v1, $v0, L_8000DDC8
    if (ctx->r3 == ctx->r2) {
        // 0x8000DD48: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_8000DDC8;
    }
    // 0x8000DD48: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8000DD4C: j           L_8000DE54
    // 0x8000DD50: nop

        goto L_8000DE54;
    // 0x8000DD50: nop

L_8000DD54:
    // 0x8000DD54: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    // 0x8000DD58: addiu       $s0, $s1, 0x44
    ctx->r16 = ADD32(ctx->r17, 0X44);
    // 0x8000DD5C: jal         0x800194A4
    // 0x8000DD60: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    rotateVec3ByMat3x3(rdram, ctx);
        goto after_0;
    // 0x8000DD60: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8000DD64: jal         0x8001CF58
    // 0x8000DD68: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    normalize_vector(rdram, ctx);
        goto after_1;
    // 0x8000DD68: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8000DD6C: j           L_8000DE54
    // 0x8000DD70: nop

        goto L_8000DE54;
    // 0x8000DD70: nop

L_8000DD74:
    // 0x8000DD74: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8000DD78: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    // 0x8000DD7C: jal         0x800193E8
    // 0x8000DD80: addiu       $a2, $s1, 0x38
    ctx->r6 = ADD32(ctx->r17, 0X38);
    transformVec3ByMat34(rdram, ctx);
        goto after_2;
    // 0x8000DD80: addiu       $a2, $s1, 0x38
    ctx->r6 = ADD32(ctx->r17, 0X38);
    after_2:
    // 0x8000DD84: lwc1        $f2, 0x30($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X30);
    // 0x8000DD88: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000DD8C: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8000DD90: nop

    // 0x8000DD94: bc1t        L_8000DE54
    if (c1cs) {
        // 0x8000DD98: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_8000DE54;
    }
    // 0x8000DD98: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8000DD9C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8000DDA0: addiu       $s0, $sp, 0x20
    ctx->r16 = ADD32(ctx->r29, 0X20);
    // 0x8000DDA4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8000DDA8: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x8000DDAC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8000DDB0: jal         0x800194A4
    // 0x8000DDB4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    rotateVec3ByMat3x3(rdram, ctx);
        goto after_3;
    // 0x8000DDB4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x8000DDB8: jal         0x8001CF2C
    // 0x8000DDBC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    vec3Length(rdram, ctx);
        goto after_4;
    // 0x8000DDBC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x8000DDC0: j           L_8000DE54
    // 0x8000DDC4: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
        goto L_8000DE54;
    // 0x8000DDC4: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
L_8000DDC8:
    // 0x8000DDC8: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    // 0x8000DDCC: jal         0x800193E8
    // 0x8000DDD0: addiu       $a2, $s1, 0x38
    ctx->r6 = ADD32(ctx->r17, 0X38);
    transformVec3ByMat34(rdram, ctx);
        goto after_5;
    // 0x8000DDD0: addiu       $a2, $s1, 0x38
    ctx->r6 = ADD32(ctx->r17, 0X38);
    after_5:
    // 0x8000DDD4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8000DDD8: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    // 0x8000DDDC: addiu       $s0, $s1, 0x44
    ctx->r16 = ADD32(ctx->r17, 0X44);
    // 0x8000DDE0: jal         0x800194A4
    // 0x8000DDE4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    rotateVec3ByMat3x3(rdram, ctx);
        goto after_6;
    // 0x8000DDE4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_6:
    // 0x8000DDE8: jal         0x8001CF58
    // 0x8000DDEC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    normalize_vector(rdram, ctx);
        goto after_7;
    // 0x8000DDEC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
    // 0x8000DDF0: lwc1        $f2, 0x30($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X30);
    // 0x8000DDF4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000DDF8: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8000DDFC: nop

    // 0x8000DE00: bc1t        L_8000DE30
    if (c1cs) {
        // 0x8000DE04: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_8000DE30;
    }
    // 0x8000DE04: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8000DE08: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8000DE0C: addiu       $s0, $sp, 0x20
    ctx->r16 = ADD32(ctx->r29, 0X20);
    // 0x8000DE10: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8000DE14: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x8000DE18: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8000DE1C: jal         0x800194A4
    // 0x8000DE20: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    rotateVec3ByMat3x3(rdram, ctx);
        goto after_8;
    // 0x8000DE20: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x8000DE24: jal         0x8001CF2C
    // 0x8000DE28: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    vec3Length(rdram, ctx);
        goto after_9;
    // 0x8000DE28: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_9:
    // 0x8000DE2C: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
L_8000DE30:
    // 0x8000DE30: lwc1        $f12, 0x34($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X34);
    // 0x8000DE34: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000DE38: lwc1        $f0, 0x61C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X61C);
    // 0x8000DE3C: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8000DE40: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000DE44: lwc1        $f0, 0x620($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X620);
    // 0x8000DE48: jal         0x8002B190
    // 0x8000DE4C: div.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f0.fl);
    cosf_recomp(rdram, ctx);
        goto after_10;
    // 0x8000DE4C: div.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f0.fl);
    after_10:
    // 0x8000DE50: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
L_8000DE54:
    // 0x8000DE54: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8000DE58: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8000DE5C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8000DE60: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8000DE64: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8000DE68: jr          $ra
    // 0x8000DE6C: nop

    return;
    // 0x8000DE6C: nop

;}
RECOMP_FUNC void appendRdpStateDl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DE70: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x8000DE74: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000DE78: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x8000DE7C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000DE80: lui         $v0, 0x20
    ctx->r2 = S32(0X20 << 16);
    // 0x8000DE84: and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // 0x8000DE88: beq         $v0, $zero, L_8000DEA0
    if (ctx->r2 == 0) {
        // 0x8000DE8C: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8000DEA0;
    }
    // 0x8000DE8C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000DE90: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8000DE94: addiu       $t1, $zero, 0x1000
    ctx->r9 = ADD32(0, 0X1000);
    // 0x8000DE98: j           L_8000DEAC
    // 0x8000DE9C: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
        goto L_8000DEAC;
    // 0x8000DE9C: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
L_8000DEA0:
    // 0x8000DEA0: lui         $t0, 0x8
    ctx->r8 = S32(0X8 << 16);
    // 0x8000DEA4: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x8000DEA8: addiu       $t2, $zero, 0x1000
    ctx->r10 = ADD32(0, 0X1000);
L_8000DEAC:
    // 0x8000DEAC: andi        $v0, $a1, 0x8000
    ctx->r2 = ctx->r5 & 0X8000;
    // 0x8000DEB0: beql        $v0, $zero, L_8000DEB8
    if (ctx->r2 == 0) {
        // 0x8000DEB4: ori         $t0, $t0, 0x2000
        ctx->r8 = ctx->r8 | 0X2000;
            goto L_8000DEB8;
    }
    goto skip_0;
    // 0x8000DEB4: ori         $t0, $t0, 0x2000
    ctx->r8 = ctx->r8 | 0X2000;
    skip_0:
L_8000DEB8:
    // 0x8000DEB8: lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
    // 0x8000DEBC: and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // 0x8000DEC0: beq         $v0, $zero, L_8000DF3C
    if (ctx->r2 == 0) {
        // 0x8000DEC4: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000DF3C;
    }
    // 0x8000DEC4: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x8000DEC8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000DECC: lui         $v0, 0xB900
    ctx->r2 = S32(0XB900 << 16);
    // 0x8000DED0: ori         $v0, $v0, 0x201
    ctx->r2 = ctx->r2 | 0X201;
    // 0x8000DED4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000DED8: lwc1        $f2, -0x2F78($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2F78);
    // 0x8000DEDC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000DEE0: lwc1        $f0, 0x624($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X624);
    // 0x8000DEE4: addu        $t3, $a0, $zero
    ctx->r11 = ADD32(ctx->r4, 0);
    // 0x8000DEE8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000DEEC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000DEF0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8000DEF4: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8000DEF8: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8000DEFC: lui         $v0, 0xEE00
    ctx->r2 = S32(0XEE00 << 16);
    // 0x8000DF00: bc1t        L_8000DF18
    if (c1cs) {
        // 0x8000DF04: sw          $v0, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->r2;
            goto L_8000DF18;
    }
    // 0x8000DF04: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    // 0x8000DF08: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8000DF0C: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x8000DF10: j           L_8000DF30
    // 0x8000DF14: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
        goto L_8000DF30;
    // 0x8000DF14: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
L_8000DF18:
    // 0x8000DF18: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8000DF1C: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8000DF20: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8000DF24: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8000DF28: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8000DF2C: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
L_8000DF30:
    // 0x8000DF30: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
    // 0x8000DF34: j           L_8000DF54
    // 0x8000DF38: ori         $t2, $t2, 0x1
    ctx->r10 = ctx->r10 | 0X1;
        goto L_8000DF54;
    // 0x8000DF38: ori         $t2, $t2, 0x1
    ctx->r10 = ctx->r10 | 0X1;
L_8000DF3C:
    // 0x8000DF3C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000DF40: lui         $v0, 0xB900
    ctx->r2 = S32(0XB900 << 16);
    // 0x8000DF44: ori         $v0, $v0, 0x201
    ctx->r2 = ctx->r2 | 0X201;
    // 0x8000DF48: ori         $t1, $t1, 0x1
    ctx->r9 = ctx->r9 | 0X1;
    // 0x8000DF4C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000DF50: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_8000DF54:
    // 0x8000DF54: lui         $v0, 0x1C0
    ctx->r2 = S32(0X1C0 << 16);
    // 0x8000DF58: and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // 0x8000DF5C: beq         $v0, $zero, L_8000DF78
    if (ctx->r2 == 0) {
        // 0x8000DF60: srl         $v0, $v0, 20
        ctx->r2 = S32(U32(ctx->r2) >> 20);
            goto L_8000DF78;
    }
    // 0x8000DF60: srl         $v0, $v0, 20
    ctx->r2 = S32(U32(ctx->r2) >> 20);
    // 0x8000DF64: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8000DF68: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000DF6C: lw          $v0, 0x775C($at)
    ctx->r2 = MEM_W(ctx->r1, 0X775C);
    // 0x8000DF70: j           L_8000DF84
    // 0x8000DF74: or          $t0, $t0, $v0
    ctx->r8 = ctx->r8 | ctx->r2;
        goto L_8000DF84;
    // 0x8000DF74: or          $t0, $t0, $v0
    ctx->r8 = ctx->r8 | ctx->r2;
L_8000DF78:
    // 0x8000DF78: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000DF7C: lw          $v0, -0x57A8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X57A8);
    // 0x8000DF80: or          $t0, $t0, $v0
    ctx->r8 = ctx->r8 | ctx->r2;
L_8000DF84:
    // 0x8000DF84: lui         $v0, 0xE00
    ctx->r2 = S32(0XE00 << 16);
    // 0x8000DF88: and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // 0x8000DF8C: beq         $v0, $zero, L_8000DFA8
    if (ctx->r2 == 0) {
        // 0x8000DF90: srl         $v0, $v0, 23
        ctx->r2 = S32(U32(ctx->r2) >> 23);
            goto L_8000DFA8;
    }
    // 0x8000DF90: srl         $v0, $v0, 23
    ctx->r2 = S32(U32(ctx->r2) >> 23);
    // 0x8000DF94: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8000DF98: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000DF9C: lw          $v0, 0x776C($at)
    ctx->r2 = MEM_W(ctx->r1, 0X776C);
    // 0x8000DFA0: j           L_8000DFB4
    // 0x8000DFA4: or          $t0, $t0, $v0
    ctx->r8 = ctx->r8 | ctx->r2;
        goto L_8000DFB4;
    // 0x8000DFA4: or          $t0, $t0, $v0
    ctx->r8 = ctx->r8 | ctx->r2;
L_8000DFA8:
    // 0x8000DFA8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000DFAC: lw          $v0, -0x57A4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X57A4);
    // 0x8000DFB0: or          $t0, $t0, $v0
    ctx->r8 = ctx->r8 | ctx->r2;
L_8000DFB4:
    // 0x8000DFB4: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x8000DFB8: and         $v0, $a1, $v1
    ctx->r2 = ctx->r5 & ctx->r3;
    // 0x8000DFBC: bne         $v0, $zero, L_8000DFE0
    if (ctx->r2 != 0) {
        // 0x8000DFC0: lui         $v0, 0x1
        ctx->r2 = S32(0X1 << 16);
            goto L_8000DFE0;
    }
    // 0x8000DFC0: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x8000DFC4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000DFC8: lbu         $v0, -0x5768($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5768);
    // 0x8000DFCC: beq         $v0, $zero, L_8000DFDC
    if (ctx->r2 == 0) {
        // 0x8000DFD0: addiu       $v0, $zero, 0x82
        ctx->r2 = ADD32(0, 0X82);
            goto L_8000DFDC;
    }
    // 0x8000DFD0: addiu       $v0, $zero, 0x82
    ctx->r2 = ADD32(0, 0X82);
    // 0x8000DFD4: j           L_8000DFE8
    // 0x8000DFD8: or          $t1, $t1, $v1
    ctx->r9 = ctx->r9 | ctx->r3;
        goto L_8000DFE8;
    // 0x8000DFD8: or          $t1, $t1, $v1
    ctx->r9 = ctx->r9 | ctx->r3;
L_8000DFDC:
    // 0x8000DFDC: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
L_8000DFE0:
    // 0x8000DFE0: or          $t2, $t2, $v0
    ctx->r10 = ctx->r10 | ctx->r2;
    // 0x8000DFE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000DFE8:
    // 0x8000DFE8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000DFEC: sb          $v0, -0x56F8($at)
    MEM_B(-0X56F8, ctx->r1) = ctx->r2;
    // 0x8000DFF0: beq         $t1, $zero, L_8000E008
    if (ctx->r9 == 0) {
        // 0x8000DFF4: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000E008;
    }
    // 0x8000DFF4: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x8000DFF8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000DFFC: lui         $v0, 0xB700
    ctx->r2 = S32(0XB700 << 16);
    // 0x8000E000: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000E004: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
L_8000E008:
    // 0x8000E008: beq         $t2, $zero, L_8000E020
    if (ctx->r10 == 0) {
        // 0x8000E00C: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000E020;
    }
    // 0x8000E00C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x8000E010: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000E014: lui         $v0, 0xB600
    ctx->r2 = S32(0XB600 << 16);
    // 0x8000E018: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000E01C: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
L_8000E020:
    // 0x8000E020: lui         $v1, 0xFFF7
    ctx->r3 = S32(0XFFF7 << 16);
    // 0x8000E024: ori         $v1, $v1, 0xCF0F
    ctx->r3 = ctx->r3 | 0XCF0F;
    // 0x8000E028: lui         $v0, 0xBE00
    ctx->r2 = S32(0XBE00 << 16);
    // 0x8000E02C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8000E030: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x8000E034: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
    // 0x8000E038: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x8000E03C: lui         $v1, 0x3000
    ctx->r3 = S32(0X3000 << 16);
    // 0x8000E040: and         $a1, $a1, $v1
    ctx->r5 = ctx->r5 & ctx->r3;
    // 0x8000E044: beq         $a1, $zero, L_8000E094
    if (ctx->r5 == 0) {
        // 0x8000E048: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_8000E094;
    }
    // 0x8000E048: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8000E04C: lui         $v0, 0x2000
    ctx->r2 = S32(0X2000 << 16);
    // 0x8000E050: beql        $a1, $v0, L_8000E09C
    if (ctx->r5 == ctx->r2) {
        // 0x8000E054: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8000E09C;
    }
    goto skip_1;
    // 0x8000E054: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_1:
    // 0x8000E058: sltu        $v0, $v0, $a1
    ctx->r2 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x8000E05C: bne         $v0, $zero, L_8000E074
    if (ctx->r2 != 0) {
        // 0x8000E060: lui         $v0, 0x1000
        ctx->r2 = S32(0X1000 << 16);
            goto L_8000E074;
    }
    // 0x8000E060: lui         $v0, 0x1000
    ctx->r2 = S32(0X1000 << 16);
    // 0x8000E064: beq         $a1, $v0, L_8000E084
    if (ctx->r5 == ctx->r2) {
        // 0x8000E068: nop
    
            goto L_8000E084;
    }
    // 0x8000E068: nop

    // 0x8000E06C: j           L_8000E0A8
    // 0x8000E070: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
        goto L_8000E0A8;
    // 0x8000E070: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
L_8000E074:
    // 0x8000E074: bnel        $a1, $v1, L_8000E0A8
    if (ctx->r5 != ctx->r3) {
        // 0x8000E078: addiu       $v0, $zero, 0x7F
        ctx->r2 = ADD32(0, 0X7F);
            goto L_8000E0A8;
    }
    goto skip_2;
    // 0x8000E078: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    skip_2:
    // 0x8000E07C: j           L_8000E09C
    // 0x8000E080: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000E09C;
    // 0x8000E080: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000E084:
    // 0x8000E084: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E088: sb          $zero, -0x579F($at)
    MEM_B(-0X579F, ctx->r1) = 0;
    // 0x8000E08C: j           L_8000E0A8
    // 0x8000E090: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
        goto L_8000E0A8;
    // 0x8000E090: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
L_8000E094:
    // 0x8000E094: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E098: lbu         $v0, -0x57A0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X57A0);
L_8000E09C:
    // 0x8000E09C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E0A0: sb          $v0, -0x579F($at)
    MEM_B(-0X579F, ctx->r1) = ctx->r2;
    // 0x8000E0A4: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
L_8000E0A8:
    // 0x8000E0A8: sb          $v0, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r2;
    // 0x8000E0AC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8000E0B0: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x8000E0B4: jr          $ra
    // 0x8000E0B8: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    return;
    // 0x8000E0B8: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
;}
RECOMP_FUNC void func_8000E0BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E0BC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8000E0C0: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8000E0C4: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8000E0C8: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8000E0CC: lw          $v0, 0x7760($at)
    ctx->r2 = MEM_W(ctx->r1, 0X7760);
    // 0x8000E0D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E0D4: sw          $v0, -0x57A8($at)
    MEM_W(-0X57A8, ctx->r1) = ctx->r2;
    // 0x8000E0D8: jr          $ra
    // 0x8000E0DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8000E0DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_8000E0E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E0E0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8000E0E4: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8000E0E8: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8000E0EC: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8000E0F0: lw          $v0, 0x7770($at)
    ctx->r2 = MEM_W(ctx->r1, 0X7770);
    // 0x8000E0F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E0F8: sw          $v0, -0x57A4($at)
    MEM_W(-0X57A4, ctx->r1) = ctx->r2;
    // 0x8000E0FC: jr          $ra
    // 0x8000E100: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8000E100: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_8000E104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E104: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000E108: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8000E10C: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x8000E110: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000E114: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x8000E118: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8000E11C: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8000E120: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E124: lw          $v0, -0x5BBC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5BBC);
    // 0x8000E128: andi        $v1, $s2, 0xFFFF
    ctx->r3 = ctx->r18 & 0XFFFF;
    // 0x8000E12C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8000E130: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000E134: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8000E138: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8000E13C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000E140: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8000E144: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x8000E148: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8000E14C: beq         $v0, $zero, L_8000E300
    if (ctx->r2 == 0) {
        // 0x8000E150: addu        $s1, $a3, $zero
        ctx->r17 = ADD32(ctx->r7, 0);
            goto L_8000E300;
    }
    // 0x8000E150: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // 0x8000E154: andi        $v0, $s0, 0x8
    ctx->r2 = ctx->r16 & 0X8;
    // 0x8000E158: bne         $v0, $zero, L_8000E300
    if (ctx->r2 != 0) {
        // 0x8000E15C: nop
    
            goto L_8000E300;
    }
    // 0x8000E15C: nop

    // 0x8000E160: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000E164: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000E168: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000E16C: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x8000E170: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000E174: bne         $v0, $zero, L_8000E260
    if (ctx->r2 != 0) {
        // 0x8000E178: lui         $v0, 0xB500
        ctx->r2 = S32(0XB500 << 16);
            goto L_8000E260;
    }
    // 0x8000E178: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x8000E17C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000E180: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000E184: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000E188: bne         $a0, $zero, L_8000E1E8
    if (ctx->r4 != 0) {
        // 0x8000E18C: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8000E1E8;
    }
    // 0x8000E18C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000E190: jal         0x8002221C
    // 0x8000E194: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_0;
    // 0x8000E194: nop

    after_0:
    // 0x8000E198: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000E19C: beq         $a0, $zero, L_8000E1E0
    if (ctx->r4 == 0) {
        // 0x8000E1A0: nop
    
            goto L_8000E1E0;
    }
    // 0x8000E1A0: nop

    // 0x8000E1A4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000E1A8: beq         $v0, $zero, L_8000E1C0
    if (ctx->r2 == 0) {
        // 0x8000E1AC: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000E1C0;
    }
    // 0x8000E1AC: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000E1B0:
    // 0x8000E1B0: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000E1B4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000E1B8: bne         $v0, $zero, L_8000E1B0
    if (ctx->r2 != 0) {
        // 0x8000E1BC: nop
    
            goto L_8000E1B0;
    }
    // 0x8000E1BC: nop

L_8000E1C0:
    // 0x8000E1C0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000E1C4: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000E1C8: beq         $v0, $zero, L_8000E1D4
    if (ctx->r2 == 0) {
        // 0x8000E1CC: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000E1D4;
    }
    // 0x8000E1CC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000E1D0: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000E1D4:
    // 0x8000E1D4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000E1D8: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000E1DC: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000E1E0:
    // 0x8000E1E0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000E1E4: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000E1E8:
    // 0x8000E1E8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000E1EC: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000E1F0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000E1F4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000E1F8: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000E1FC: bnel        $v0, $zero, L_8000E204
    if (ctx->r2 != 0) {
        // 0x8000E200: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000E204;
    }
    goto skip_0;
    // 0x8000E200: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_0:
L_8000E204:
    // 0x8000E204: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000E208: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000E20C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000E210: bne         $v0, $zero, L_8000E220
    if (ctx->r2 != 0) {
        // 0x8000E214: nop
    
            goto L_8000E220;
    }
    // 0x8000E214: nop

    // 0x8000E218: j           L_8000E238
    // 0x8000E21C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000E238;
    // 0x8000E21C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000E220:
    // 0x8000E220: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E224: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000E228: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000E22C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000E230: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000E234: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000E238:
    // 0x8000E238: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E23C: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000E240: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000E244: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000E248: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000E24C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000E250: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000E254: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000E258: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E25C: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_8000E260:
    // 0x8000E260: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000E264: lw          $a0, -0x23A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X23A8);
    // 0x8000E268: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000E26C: lw          $v1, -0x5BBC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5BBC);
    // 0x8000E270: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x8000E274: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8000E278: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
    // 0x8000E27C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000E280: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000E284: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8000E288: lhu         $a1, 0x2($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X2);
    // 0x8000E28C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000E290: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E294: sw          $a0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r4;
    // 0x8000E298: jal         0x800225F8
    // 0x8000E29C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_800225F8(rdram, ctx);
        goto after_1;
    // 0x8000E29C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8000E2A0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000E2A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E2A8: sw          $a0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r4;
    // 0x8000E2AC: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x8000E2B0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E2B4: lbu         $v0, -0x56F8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X56F8);
    // 0x8000E2B8: bne         $v1, $v0, L_8000E2D4
    if (ctx->r3 != ctx->r2) {
        // 0x8000E2BC: addu        $a1, $s4, $zero
        ctx->r5 = ADD32(ctx->r20, 0);
            goto L_8000E2D4;
    }
    // 0x8000E2BC: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x8000E2C0: lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X0);
    // 0x8000E2C4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000E2C8: lbu         $v0, 0x43A8($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X43A8);
    // 0x8000E2CC: beq         $v1, $v0, L_8000E7DC
    if (ctx->r3 == ctx->r2) {
        // 0x8000E2D0: nop
    
            goto L_8000E7DC;
    }
    // 0x8000E2D0: nop

L_8000E2D4:
    // 0x8000E2D4: jal         0x80023970
    // 0x8000E2D8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80023970(rdram, ctx);
        goto after_2;
    // 0x8000E2D8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8000E2DC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000E2E0: lbu         $v1, -0x56F8($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X56F8);
    // 0x8000E2E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E2E8: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x8000E2EC: sb          $v1, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r3;
    // 0x8000E2F0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000E2F4: lbu         $v0, 0x43A8($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X43A8);
    // 0x8000E2F8: j           L_8000E7DC
    // 0x8000E2FC: sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
        goto L_8000E7DC;
    // 0x8000E2FC: sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
L_8000E300:
    // 0x8000E300: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000E304: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000E308: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000E30C: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x8000E310: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000E314: bne         $v0, $zero, L_8000E400
    if (ctx->r2 != 0) {
        // 0x8000E318: lui         $v0, 0xB500
        ctx->r2 = S32(0XB500 << 16);
            goto L_8000E400;
    }
    // 0x8000E318: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x8000E31C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000E320: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000E324: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000E328: bne         $a0, $zero, L_8000E388
    if (ctx->r4 != 0) {
        // 0x8000E32C: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8000E388;
    }
    // 0x8000E32C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000E330: jal         0x8002221C
    // 0x8000E334: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_3;
    // 0x8000E334: nop

    after_3:
    // 0x8000E338: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000E33C: beq         $a0, $zero, L_8000E380
    if (ctx->r4 == 0) {
        // 0x8000E340: nop
    
            goto L_8000E380;
    }
    // 0x8000E340: nop

    // 0x8000E344: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000E348: beq         $v0, $zero, L_8000E360
    if (ctx->r2 == 0) {
        // 0x8000E34C: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000E360;
    }
    // 0x8000E34C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000E350:
    // 0x8000E350: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000E354: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000E358: bne         $v0, $zero, L_8000E350
    if (ctx->r2 != 0) {
        // 0x8000E35C: nop
    
            goto L_8000E350;
    }
    // 0x8000E35C: nop

L_8000E360:
    // 0x8000E360: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000E364: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000E368: beq         $v0, $zero, L_8000E374
    if (ctx->r2 == 0) {
        // 0x8000E36C: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000E374;
    }
    // 0x8000E36C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000E370: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000E374:
    // 0x8000E374: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000E378: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000E37C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000E380:
    // 0x8000E380: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000E384: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000E388:
    // 0x8000E388: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000E38C: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000E390: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000E394: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000E398: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000E39C: bnel        $v0, $zero, L_8000E3A4
    if (ctx->r2 != 0) {
        // 0x8000E3A0: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000E3A4;
    }
    goto skip_1;
    // 0x8000E3A0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_1:
L_8000E3A4:
    // 0x8000E3A4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000E3A8: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000E3AC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000E3B0: bne         $v0, $zero, L_8000E3C0
    if (ctx->r2 != 0) {
        // 0x8000E3B4: nop
    
            goto L_8000E3C0;
    }
    // 0x8000E3B4: nop

    // 0x8000E3B8: j           L_8000E3D8
    // 0x8000E3BC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000E3D8;
    // 0x8000E3BC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000E3C0:
    // 0x8000E3C0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E3C4: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000E3C8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000E3CC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000E3D0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000E3D4: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000E3D8:
    // 0x8000E3D8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E3DC: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000E3E0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000E3E4: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000E3E8: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000E3EC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000E3F0: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000E3F4: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000E3F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E3FC: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_8000E400:
    // 0x8000E400: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000E404: lw          $a1, -0x23A8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X23A8);
    // 0x8000E408: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x8000E40C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000E410: sb          $zero, 0x43A8($at)
    MEM_B(0X43A8, ctx->r1) = 0;
    // 0x8000E414: addiu       $a0, $a1, 0x8
    ctx->r4 = ADD32(ctx->r5, 0X8);
    // 0x8000E418: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E41C: sw          $a0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r4;
    // 0x8000E420: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8000E424: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8000E428: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x8000E42C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E430: lbu         $v0, -0x56F8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X56F8);
    // 0x8000E434: bne         $v1, $v0, L_8000E448
    if (ctx->r3 != ctx->r2) {
        // 0x8000E438: nop
    
            goto L_8000E448;
    }
    // 0x8000E438: nop

    // 0x8000E43C: lbu         $v0, 0x0($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X0);
    // 0x8000E440: beq         $v0, $zero, L_8000E594
    if (ctx->r2 == 0) {
        // 0x8000E444: nop
    
            goto L_8000E594;
    }
    // 0x8000E444: nop

L_8000E448:
    // 0x8000E448: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000E44C: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x8000E450: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8000E454: bne         $v0, $zero, L_8000E548
    if (ctx->r2 != 0) {
        // 0x8000E458: lui         $v1, 0xB900
        ctx->r3 = S32(0XB900 << 16);
            goto L_8000E548;
    }
    // 0x8000E458: lui         $v1, 0xB900
    ctx->r3 = S32(0XB900 << 16);
    // 0x8000E45C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000E460: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000E464: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x8000E468: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x8000E46C: bne         $a0, $zero, L_8000E4CC
    if (ctx->r4 != 0) {
        // 0x8000E470: sw          $zero, 0xC($a1)
        MEM_W(0XC, ctx->r5) = 0;
            goto L_8000E4CC;
    }
    // 0x8000E470: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x8000E474: jal         0x8002221C
    // 0x8000E478: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_4;
    // 0x8000E478: nop

    after_4:
    // 0x8000E47C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000E480: beq         $a0, $zero, L_8000E4C4
    if (ctx->r4 == 0) {
        // 0x8000E484: nop
    
            goto L_8000E4C4;
    }
    // 0x8000E484: nop

    // 0x8000E488: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000E48C: beq         $v0, $zero, L_8000E4A4
    if (ctx->r2 == 0) {
        // 0x8000E490: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000E4A4;
    }
    // 0x8000E490: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000E494:
    // 0x8000E494: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000E498: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000E49C: bne         $v0, $zero, L_8000E494
    if (ctx->r2 != 0) {
        // 0x8000E4A0: nop
    
            goto L_8000E494;
    }
    // 0x8000E4A0: nop

L_8000E4A4:
    // 0x8000E4A4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000E4A8: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000E4AC: beq         $v0, $zero, L_8000E4B8
    if (ctx->r2 == 0) {
        // 0x8000E4B0: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000E4B8;
    }
    // 0x8000E4B0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000E4B4: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000E4B8:
    // 0x8000E4B8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000E4BC: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000E4C0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000E4C4:
    // 0x8000E4C4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000E4C8: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000E4CC:
    // 0x8000E4CC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000E4D0: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000E4D4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000E4D8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000E4DC: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000E4E0: bnel        $v0, $zero, L_8000E4E8
    if (ctx->r2 != 0) {
        // 0x8000E4E4: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000E4E8;
    }
    goto skip_2;
    // 0x8000E4E4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_2:
L_8000E4E8:
    // 0x8000E4E8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000E4EC: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000E4F0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000E4F4: bne         $v0, $zero, L_8000E504
    if (ctx->r2 != 0) {
        // 0x8000E4F8: nop
    
            goto L_8000E504;
    }
    // 0x8000E4F8: nop

    // 0x8000E4FC: j           L_8000E51C
    // 0x8000E500: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000E51C;
    // 0x8000E500: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000E504:
    // 0x8000E504: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E508: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000E50C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000E510: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000E514: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000E518: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000E51C:
    // 0x8000E51C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E520: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000E524: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000E528: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000E52C: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000E530: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000E534: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000E538: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000E53C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E540: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x8000E544: lui         $v1, 0xB900
    ctx->r3 = S32(0XB900 << 16);
L_8000E548:
    // 0x8000E548: ori         $v1, $v1, 0x2
    ctx->r3 = ctx->r3 | 0X2;
    // 0x8000E54C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E550: lw          $v0, -0x23A8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X23A8);
    // 0x8000E554: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x8000E558: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8000E55C: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // 0x8000E560: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E564: sw          $a0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r4;
    // 0x8000E568: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8000E56C: jal         0x80023970
    // 0x8000E570: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    func_80023970(rdram, ctx);
        goto after_5;
    // 0x8000E570: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    after_5:
    // 0x8000E574: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000E578: lbu         $v1, -0x56F8($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X56F8);
    // 0x8000E57C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E580: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x8000E584: sb          $v1, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r3;
    // 0x8000E588: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000E58C: lbu         $v0, 0x43A8($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X43A8);
    // 0x8000E590: sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
L_8000E594:
    // 0x8000E594: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000E598: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000E59C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000E5A0: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x8000E5A4: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000E5A8: bne         $v0, $zero, L_8000E69C
    if (ctx->r2 != 0) {
        // 0x8000E5AC: lui         $a1, 0xFCFF
        ctx->r5 = S32(0XFCFF << 16);
            goto L_8000E69C;
    }
    // 0x8000E5AC: lui         $a1, 0xFCFF
    ctx->r5 = S32(0XFCFF << 16);
    // 0x8000E5B0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000E5B4: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000E5B8: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x8000E5BC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000E5C0: bne         $a0, $zero, L_8000E620
    if (ctx->r4 != 0) {
        // 0x8000E5C4: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8000E620;
    }
    // 0x8000E5C4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000E5C8: jal         0x8002221C
    // 0x8000E5CC: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_6;
    // 0x8000E5CC: nop

    after_6:
    // 0x8000E5D0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000E5D4: beq         $a0, $zero, L_8000E618
    if (ctx->r4 == 0) {
        // 0x8000E5D8: nop
    
            goto L_8000E618;
    }
    // 0x8000E5D8: nop

    // 0x8000E5DC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000E5E0: beq         $v0, $zero, L_8000E5F8
    if (ctx->r2 == 0) {
        // 0x8000E5E4: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000E5F8;
    }
    // 0x8000E5E4: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000E5E8:
    // 0x8000E5E8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000E5EC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000E5F0: bne         $v0, $zero, L_8000E5E8
    if (ctx->r2 != 0) {
        // 0x8000E5F4: nop
    
            goto L_8000E5E8;
    }
    // 0x8000E5F4: nop

L_8000E5F8:
    // 0x8000E5F8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000E5FC: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000E600: beq         $v0, $zero, L_8000E60C
    if (ctx->r2 == 0) {
        // 0x8000E604: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000E60C;
    }
    // 0x8000E604: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000E608: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000E60C:
    // 0x8000E60C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000E610: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000E614: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000E618:
    // 0x8000E618: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000E61C: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000E620:
    // 0x8000E620: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000E624: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000E628: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000E62C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000E630: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000E634: bnel        $v0, $zero, L_8000E63C
    if (ctx->r2 != 0) {
        // 0x8000E638: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000E63C;
    }
    goto skip_3;
    // 0x8000E638: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_3:
L_8000E63C:
    // 0x8000E63C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000E640: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000E644: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000E648: bne         $v0, $zero, L_8000E658
    if (ctx->r2 != 0) {
        // 0x8000E64C: nop
    
            goto L_8000E658;
    }
    // 0x8000E64C: nop

    // 0x8000E650: j           L_8000E670
    // 0x8000E654: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000E670;
    // 0x8000E654: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000E658:
    // 0x8000E658: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E65C: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000E660: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000E664: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000E668: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000E66C: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000E670:
    // 0x8000E670: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E674: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000E678: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000E67C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000E680: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000E684: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000E688: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000E68C: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000E690: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E694: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x8000E698: lui         $a1, 0xFCFF
    ctx->r5 = S32(0XFCFF << 16);
L_8000E69C:
    // 0x8000E69C: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8000E6A0: lui         $a0, 0xFFFE
    ctx->r4 = S32(0XFFFE << 16);
    // 0x8000E6A4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000E6A8: lw          $a2, -0x23A8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X23A8);
    // 0x8000E6AC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000E6B0: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x8000E6B4: ori         $a0, $a0, 0x793C
    ctx->r4 = ctx->r4 | 0X793C;
    // 0x8000E6B8: addiu       $v0, $a2, 0x8
    ctx->r2 = ADD32(ctx->r6, 0X8);
    // 0x8000E6BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E6C0: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x8000E6C4: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8000E6C8: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    // 0x8000E6CC: bne         $v0, $zero, L_8000E7BC
    if (ctx->r2 != 0) {
        // 0x8000E6D0: sw          $a0, 0x4($a2)
        MEM_W(0X4, ctx->r6) = ctx->r4;
            goto L_8000E7BC;
    }
    // 0x8000E6D0: sw          $a0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r4;
    // 0x8000E6D4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000E6D8: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000E6DC: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x8000E6E0: sw          $v0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r2;
    // 0x8000E6E4: bne         $a0, $zero, L_8000E744
    if (ctx->r4 != 0) {
        // 0x8000E6E8: sw          $zero, 0xC($a2)
        MEM_W(0XC, ctx->r6) = 0;
            goto L_8000E744;
    }
    // 0x8000E6E8: sw          $zero, 0xC($a2)
    MEM_W(0XC, ctx->r6) = 0;
    // 0x8000E6EC: jal         0x8002221C
    // 0x8000E6F0: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_7;
    // 0x8000E6F0: nop

    after_7:
    // 0x8000E6F4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000E6F8: beq         $a0, $zero, L_8000E73C
    if (ctx->r4 == 0) {
        // 0x8000E6FC: nop
    
            goto L_8000E73C;
    }
    // 0x8000E6FC: nop

    // 0x8000E700: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000E704: beq         $v0, $zero, L_8000E71C
    if (ctx->r2 == 0) {
        // 0x8000E708: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000E71C;
    }
    // 0x8000E708: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000E70C:
    // 0x8000E70C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000E710: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000E714: bne         $v0, $zero, L_8000E70C
    if (ctx->r2 != 0) {
        // 0x8000E718: nop
    
            goto L_8000E70C;
    }
    // 0x8000E718: nop

L_8000E71C:
    // 0x8000E71C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000E720: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000E724: beq         $v0, $zero, L_8000E730
    if (ctx->r2 == 0) {
        // 0x8000E728: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000E730;
    }
    // 0x8000E728: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000E72C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000E730:
    // 0x8000E730: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000E734: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000E738: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000E73C:
    // 0x8000E73C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000E740: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000E744:
    // 0x8000E744: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000E748: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000E74C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000E750: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000E754: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000E758: bnel        $v0, $zero, L_8000E760
    if (ctx->r2 != 0) {
        // 0x8000E75C: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000E760;
    }
    goto skip_4;
    // 0x8000E75C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_4:
L_8000E760:
    // 0x8000E760: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000E764: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000E768: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000E76C: bne         $v0, $zero, L_8000E77C
    if (ctx->r2 != 0) {
        // 0x8000E770: nop
    
            goto L_8000E77C;
    }
    // 0x8000E770: nop

    // 0x8000E774: j           L_8000E794
    // 0x8000E778: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000E794;
    // 0x8000E778: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000E77C:
    // 0x8000E77C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E780: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000E784: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000E788: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000E78C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000E790: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000E794:
    // 0x8000E794: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E798: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000E79C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000E7A0: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000E7A4: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000E7A8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000E7AC: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000E7B0: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000E7B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E7B8: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_8000E7BC:
    // 0x8000E7BC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E7C0: lw          $v0, -0x23A8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X23A8);
    // 0x8000E7C4: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x8000E7C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E7CC: sw          $v1, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r3;
    // 0x8000E7D0: lui         $v1, 0xBB00
    ctx->r3 = S32(0XBB00 << 16);
    // 0x8000E7D4: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8000E7D8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
L_8000E7DC:
    // 0x8000E7DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000E7E0: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8000E7E4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E7E8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8000E7EC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8000E7F0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000E7F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000E7F8: jr          $ra
    // 0x8000E7FC: nop

    return;
    // 0x8000E7FC: nop

;}
RECOMP_FUNC void func_8000E800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E800: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000E804: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8000E808: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x8000E80C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8000E810: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8000E814: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E818: lw          $v0, -0x5BBC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5BBC);
    // 0x8000E81C: andi        $v1, $s2, 0xFFFF
    ctx->r3 = ctx->r18 & 0XFFFF;
    // 0x8000E820: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8000E824: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8000E828: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8000E82C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000E830: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000E834: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8000E838: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // 0x8000E83C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8000E840: beq         $v0, $zero, L_8000E9D4
    if (ctx->r2 == 0) {
        // 0x8000E844: ori         $s0, $a2, 0x1
        ctx->r16 = ctx->r6 | 0X1;
            goto L_8000E9D4;
    }
    // 0x8000E844: ori         $s0, $a2, 0x1
    ctx->r16 = ctx->r6 | 0X1;
    // 0x8000E848: andi        $v0, $s0, 0x8
    ctx->r2 = ctx->r16 & 0X8;
    // 0x8000E84C: bne         $v0, $zero, L_8000E9D4
    if (ctx->r2 != 0) {
        // 0x8000E850: nop
    
            goto L_8000E9D4;
    }
    // 0x8000E850: nop

    // 0x8000E854: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000E858: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000E85C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000E860: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x8000E864: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000E868: bne         $v0, $zero, L_8000E954
    if (ctx->r2 != 0) {
        // 0x8000E86C: lui         $v0, 0xB500
        ctx->r2 = S32(0XB500 << 16);
            goto L_8000E954;
    }
    // 0x8000E86C: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x8000E870: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000E874: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000E878: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000E87C: bne         $a0, $zero, L_8000E8DC
    if (ctx->r4 != 0) {
        // 0x8000E880: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8000E8DC;
    }
    // 0x8000E880: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000E884: jal         0x8002221C
    // 0x8000E888: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_0;
    // 0x8000E888: nop

    after_0:
    // 0x8000E88C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000E890: beq         $a0, $zero, L_8000E8D4
    if (ctx->r4 == 0) {
        // 0x8000E894: nop
    
            goto L_8000E8D4;
    }
    // 0x8000E894: nop

    // 0x8000E898: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000E89C: beq         $v0, $zero, L_8000E8B4
    if (ctx->r2 == 0) {
        // 0x8000E8A0: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000E8B4;
    }
    // 0x8000E8A0: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000E8A4:
    // 0x8000E8A4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000E8A8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000E8AC: bne         $v0, $zero, L_8000E8A4
    if (ctx->r2 != 0) {
        // 0x8000E8B0: nop
    
            goto L_8000E8A4;
    }
    // 0x8000E8B0: nop

L_8000E8B4:
    // 0x8000E8B4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000E8B8: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000E8BC: beq         $v0, $zero, L_8000E8C8
    if (ctx->r2 == 0) {
        // 0x8000E8C0: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000E8C8;
    }
    // 0x8000E8C0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000E8C4: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000E8C8:
    // 0x8000E8C8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000E8CC: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000E8D0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000E8D4:
    // 0x8000E8D4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000E8D8: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000E8DC:
    // 0x8000E8DC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000E8E0: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000E8E4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000E8E8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000E8EC: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000E8F0: bnel        $v0, $zero, L_8000E8F8
    if (ctx->r2 != 0) {
        // 0x8000E8F4: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000E8F8;
    }
    goto skip_0;
    // 0x8000E8F4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_0:
L_8000E8F8:
    // 0x8000E8F8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000E8FC: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000E900: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000E904: bne         $v0, $zero, L_8000E914
    if (ctx->r2 != 0) {
        // 0x8000E908: nop
    
            goto L_8000E914;
    }
    // 0x8000E908: nop

    // 0x8000E90C: j           L_8000E92C
    // 0x8000E910: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000E92C;
    // 0x8000E910: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000E914:
    // 0x8000E914: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E918: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000E91C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000E920: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000E924: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000E928: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000E92C:
    // 0x8000E92C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E930: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000E934: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000E938: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000E93C: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000E940: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000E944: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000E948: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000E94C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E950: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_8000E954:
    // 0x8000E954: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000E958: lw          $a0, -0x23A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X23A8);
    // 0x8000E95C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000E960: lw          $v1, -0x5BBC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5BBC);
    // 0x8000E964: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x8000E968: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8000E96C: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
    // 0x8000E970: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000E974: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000E978: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8000E97C: lhu         $a1, 0x2($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X2);
    // 0x8000E980: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000E984: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E988: sw          $a0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r4;
    // 0x8000E98C: jal         0x800225F8
    // 0x8000E990: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_800225F8(rdram, ctx);
        goto after_1;
    // 0x8000E990: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8000E994: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000E998: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E99C: sw          $a0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r4;
    // 0x8000E9A0: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x8000E9A4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E9A8: lbu         $v0, -0x56F8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X56F8);
    // 0x8000E9AC: beq         $v1, $v0, L_8000EEE4
    if (ctx->r3 == ctx->r2) {
        // 0x8000E9B0: addu        $a1, $s3, $zero
        ctx->r5 = ADD32(ctx->r19, 0);
            goto L_8000EEE4;
    }
    // 0x8000E9B0: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8000E9B4: jal         0x80023B38
    // 0x8000E9B8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80023B38(rdram, ctx);
        goto after_2;
    // 0x8000E9B8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8000E9BC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000E9C0: lbu         $v1, -0x56F8($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X56F8);
    // 0x8000E9C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E9C8: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x8000E9CC: j           L_8000EEE4
    // 0x8000E9D0: sb          $v1, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r3;
        goto L_8000EEE4;
    // 0x8000E9D0: sb          $v1, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r3;
L_8000E9D4:
    // 0x8000E9D4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E9D8: lbu         $v0, -0x56F8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X56F8);
    // 0x8000E9DC: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x8000E9E0: bne         $v0, $zero, L_8000E9F0
    if (ctx->r2 != 0) {
        // 0x8000E9E4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000E9F0;
    }
    // 0x8000E9E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000E9E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E9EC: sb          $v0, -0x56F8($at)
    MEM_B(-0X56F8, ctx->r1) = ctx->r2;
L_8000E9F0:
    // 0x8000E9F0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000E9F4: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000E9F8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000E9FC: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x8000EA00: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000EA04: bne         $v0, $zero, L_8000EAF0
    if (ctx->r2 != 0) {
        // 0x8000EA08: lui         $v0, 0xB500
        ctx->r2 = S32(0XB500 << 16);
            goto L_8000EAF0;
    }
    // 0x8000EA08: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x8000EA0C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000EA10: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000EA14: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000EA18: bne         $a0, $zero, L_8000EA78
    if (ctx->r4 != 0) {
        // 0x8000EA1C: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8000EA78;
    }
    // 0x8000EA1C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000EA20: jal         0x8002221C
    // 0x8000EA24: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_3;
    // 0x8000EA24: nop

    after_3:
    // 0x8000EA28: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000EA2C: beq         $a0, $zero, L_8000EA70
    if (ctx->r4 == 0) {
        // 0x8000EA30: nop
    
            goto L_8000EA70;
    }
    // 0x8000EA30: nop

    // 0x8000EA34: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000EA38: beq         $v0, $zero, L_8000EA50
    if (ctx->r2 == 0) {
        // 0x8000EA3C: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000EA50;
    }
    // 0x8000EA3C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000EA40:
    // 0x8000EA40: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000EA44: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000EA48: bne         $v0, $zero, L_8000EA40
    if (ctx->r2 != 0) {
        // 0x8000EA4C: nop
    
            goto L_8000EA40;
    }
    // 0x8000EA4C: nop

L_8000EA50:
    // 0x8000EA50: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000EA54: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000EA58: beq         $v0, $zero, L_8000EA64
    if (ctx->r2 == 0) {
        // 0x8000EA5C: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000EA64;
    }
    // 0x8000EA5C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000EA60: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000EA64:
    // 0x8000EA64: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000EA68: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000EA6C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000EA70:
    // 0x8000EA70: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000EA74: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000EA78:
    // 0x8000EA78: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000EA7C: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000EA80: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000EA84: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000EA88: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000EA8C: bnel        $v0, $zero, L_8000EA94
    if (ctx->r2 != 0) {
        // 0x8000EA90: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000EA94;
    }
    goto skip_1;
    // 0x8000EA90: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_1:
L_8000EA94:
    // 0x8000EA94: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000EA98: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000EA9C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000EAA0: bne         $v0, $zero, L_8000EAB0
    if (ctx->r2 != 0) {
        // 0x8000EAA4: nop
    
            goto L_8000EAB0;
    }
    // 0x8000EAA4: nop

    // 0x8000EAA8: j           L_8000EAC8
    // 0x8000EAAC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000EAC8;
    // 0x8000EAAC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000EAB0:
    // 0x8000EAB0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000EAB4: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000EAB8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000EABC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000EAC0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000EAC4: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000EAC8:
    // 0x8000EAC8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000EACC: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000EAD0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000EAD4: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000EAD8: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000EADC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000EAE0: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000EAE4: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000EAE8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000EAEC: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_8000EAF0:
    // 0x8000EAF0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000EAF4: lw          $a1, -0x23A8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X23A8);
    // 0x8000EAF8: lui         $v0, 0xB900
    ctx->r2 = S32(0XB900 << 16);
    // 0x8000EAFC: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // 0x8000EB00: addiu       $a0, $a1, 0x8
    ctx->r4 = ADD32(ctx->r5, 0X8);
    // 0x8000EB04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000EB08: sw          $a0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r4;
    // 0x8000EB0C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8000EB10: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8000EB14: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x8000EB18: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000EB1C: lbu         $v0, -0x56F8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X56F8);
    // 0x8000EB20: beq         $v1, $v0, L_8000EC60
    if (ctx->r3 == ctx->r2) {
        // 0x8000EB24: nop
    
            goto L_8000EC60;
    }
    // 0x8000EB24: nop

    // 0x8000EB28: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000EB2C: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x8000EB30: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8000EB34: bne         $v0, $zero, L_8000EC20
    if (ctx->r2 != 0) {
        // 0x8000EB38: lui         $v0, 0xB500
        ctx->r2 = S32(0XB500 << 16);
            goto L_8000EC20;
    }
    // 0x8000EB38: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x8000EB3C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000EB40: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000EB44: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x8000EB48: bne         $a0, $zero, L_8000EBA8
    if (ctx->r4 != 0) {
        // 0x8000EB4C: sw          $zero, 0xC($a1)
        MEM_W(0XC, ctx->r5) = 0;
            goto L_8000EBA8;
    }
    // 0x8000EB4C: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x8000EB50: jal         0x8002221C
    // 0x8000EB54: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_4;
    // 0x8000EB54: nop

    after_4:
    // 0x8000EB58: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000EB5C: beq         $a0, $zero, L_8000EBA0
    if (ctx->r4 == 0) {
        // 0x8000EB60: nop
    
            goto L_8000EBA0;
    }
    // 0x8000EB60: nop

    // 0x8000EB64: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000EB68: beq         $v0, $zero, L_8000EB80
    if (ctx->r2 == 0) {
        // 0x8000EB6C: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000EB80;
    }
    // 0x8000EB6C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000EB70:
    // 0x8000EB70: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000EB74: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000EB78: bne         $v0, $zero, L_8000EB70
    if (ctx->r2 != 0) {
        // 0x8000EB7C: nop
    
            goto L_8000EB70;
    }
    // 0x8000EB7C: nop

L_8000EB80:
    // 0x8000EB80: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000EB84: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000EB88: beq         $v0, $zero, L_8000EB94
    if (ctx->r2 == 0) {
        // 0x8000EB8C: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000EB94;
    }
    // 0x8000EB8C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000EB90: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000EB94:
    // 0x8000EB94: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000EB98: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000EB9C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000EBA0:
    // 0x8000EBA0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000EBA4: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000EBA8:
    // 0x8000EBA8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000EBAC: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000EBB0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000EBB4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000EBB8: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000EBBC: bnel        $v0, $zero, L_8000EBC4
    if (ctx->r2 != 0) {
        // 0x8000EBC0: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000EBC4;
    }
    goto skip_2;
    // 0x8000EBC0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_2:
L_8000EBC4:
    // 0x8000EBC4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000EBC8: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000EBCC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000EBD0: bne         $v0, $zero, L_8000EBE0
    if (ctx->r2 != 0) {
        // 0x8000EBD4: nop
    
            goto L_8000EBE0;
    }
    // 0x8000EBD4: nop

    // 0x8000EBD8: j           L_8000EBF8
    // 0x8000EBDC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000EBF8;
    // 0x8000EBDC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000EBE0:
    // 0x8000EBE0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000EBE4: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000EBE8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000EBEC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000EBF0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000EBF4: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000EBF8:
    // 0x8000EBF8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000EBFC: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000EC00: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000EC04: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000EC08: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000EC0C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000EC10: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000EC14: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000EC18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000EC1C: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_8000EC20:
    // 0x8000EC20: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000EC24: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000EC28: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8000EC2C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8000EC30: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x8000EC34: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8000EC38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000EC3C: sw          $a0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r4;
    // 0x8000EC40: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000EC44: jal         0x80023B38
    // 0x8000EC48: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    func_80023B38(rdram, ctx);
        goto after_5;
    // 0x8000EC48: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    after_5:
    // 0x8000EC4C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000EC50: lbu         $v1, -0x56F8($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X56F8);
    // 0x8000EC54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000EC58: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x8000EC5C: sb          $v1, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r3;
L_8000EC60:
    // 0x8000EC60: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000EC64: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000EC68: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000EC6C: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x8000EC70: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000EC74: bne         $v0, $zero, L_8000ED68
    if (ctx->r2 != 0) {
        // 0x8000EC78: lui         $v0, 0x1
        ctx->r2 = S32(0X1 << 16);
            goto L_8000ED68;
    }
    // 0x8000EC78: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x8000EC7C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000EC80: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000EC84: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x8000EC88: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000EC8C: bne         $a0, $zero, L_8000ECEC
    if (ctx->r4 != 0) {
        // 0x8000EC90: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8000ECEC;
    }
    // 0x8000EC90: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000EC94: jal         0x8002221C
    // 0x8000EC98: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_6;
    // 0x8000EC98: nop

    after_6:
    // 0x8000EC9C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000ECA0: beq         $a0, $zero, L_8000ECE4
    if (ctx->r4 == 0) {
        // 0x8000ECA4: nop
    
            goto L_8000ECE4;
    }
    // 0x8000ECA4: nop

    // 0x8000ECA8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000ECAC: beq         $v0, $zero, L_8000ECC4
    if (ctx->r2 == 0) {
        // 0x8000ECB0: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000ECC4;
    }
    // 0x8000ECB0: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000ECB4:
    // 0x8000ECB4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000ECB8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000ECBC: bne         $v0, $zero, L_8000ECB4
    if (ctx->r2 != 0) {
        // 0x8000ECC0: nop
    
            goto L_8000ECB4;
    }
    // 0x8000ECC0: nop

L_8000ECC4:
    // 0x8000ECC4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000ECC8: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000ECCC: beq         $v0, $zero, L_8000ECD8
    if (ctx->r2 == 0) {
        // 0x8000ECD0: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000ECD8;
    }
    // 0x8000ECD0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000ECD4: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000ECD8:
    // 0x8000ECD8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000ECDC: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000ECE0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000ECE4:
    // 0x8000ECE4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000ECE8: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000ECEC:
    // 0x8000ECEC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000ECF0: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000ECF4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000ECF8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000ECFC: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000ED00: bnel        $v0, $zero, L_8000ED08
    if (ctx->r2 != 0) {
        // 0x8000ED04: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000ED08;
    }
    goto skip_3;
    // 0x8000ED04: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_3:
L_8000ED08:
    // 0x8000ED08: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000ED0C: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000ED10: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000ED14: bne         $v0, $zero, L_8000ED24
    if (ctx->r2 != 0) {
        // 0x8000ED18: nop
    
            goto L_8000ED24;
    }
    // 0x8000ED18: nop

    // 0x8000ED1C: j           L_8000ED3C
    // 0x8000ED20: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000ED3C;
    // 0x8000ED20: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000ED24:
    // 0x8000ED24: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000ED28: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000ED2C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000ED30: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000ED34: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000ED38: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000ED3C:
    // 0x8000ED3C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000ED40: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000ED44: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000ED48: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000ED4C: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000ED50: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000ED54: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000ED58: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000ED5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000ED60: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x8000ED64: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
L_8000ED68:
    // 0x8000ED68: and         $v0, $s3, $v0
    ctx->r2 = ctx->r19 & ctx->r2;
    // 0x8000ED6C: bne         $v0, $zero, L_8000ED9C
    if (ctx->r2 != 0) {
        // 0x8000ED70: lui         $a1, 0xFCFF
        ctx->r5 = S32(0XFCFF << 16);
            goto L_8000ED9C;
    }
    // 0x8000ED70: lui         $a1, 0xFCFF
    ctx->r5 = S32(0XFCFF << 16);
    // 0x8000ED74: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000ED78: lbu         $v0, -0x5768($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5768);
    // 0x8000ED7C: beq         $v0, $zero, L_8000ED98
    if (ctx->r2 == 0) {
        // 0x8000ED80: ori         $a1, $a1, 0xFFFF
        ctx->r5 = ctx->r5 | 0XFFFF;
            goto L_8000ED98;
    }
    // 0x8000ED80: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8000ED84: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000ED88: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000ED8C: lui         $a0, 0xFFFE
    ctx->r4 = S32(0XFFFE << 16);
    // 0x8000ED90: j           L_8000EDB0
    // 0x8000ED94: ori         $a0, $a0, 0x7638
    ctx->r4 = ctx->r4 | 0X7638;
        goto L_8000EDB0;
    // 0x8000ED94: ori         $a0, $a0, 0x7638
    ctx->r4 = ctx->r4 | 0X7638;
L_8000ED98:
    // 0x8000ED98: lui         $a1, 0xFCFF
    ctx->r5 = S32(0XFCFF << 16);
L_8000ED9C:
    // 0x8000ED9C: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8000EDA0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000EDA4: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000EDA8: lui         $a0, 0xFFFE
    ctx->r4 = S32(0XFFFE << 16);
    // 0x8000EDAC: ori         $a0, $a0, 0x793C
    ctx->r4 = ctx->r4 | 0X793C;
L_8000EDB0:
    // 0x8000EDB0: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8000EDB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000EDB8: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
    // 0x8000EDBC: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x8000EDC0: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x8000EDC4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000EDC8: lw          $v1, -0x23A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X23A8);
    // 0x8000EDCC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000EDD0: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x8000EDD4: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000EDD8: bne         $v0, $zero, L_8000EEC4
    if (ctx->r2 != 0) {
        // 0x8000EDDC: lui         $v0, 0xB500
        ctx->r2 = S32(0XB500 << 16);
            goto L_8000EEC4;
    }
    // 0x8000EDDC: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x8000EDE0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000EDE4: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
    // 0x8000EDE8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000EDEC: bne         $a0, $zero, L_8000EE4C
    if (ctx->r4 != 0) {
        // 0x8000EDF0: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8000EE4C;
    }
    // 0x8000EDF0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000EDF4: jal         0x8002221C
    // 0x8000EDF8: nop

    findAndUnlinkSmallestEntry(rdram, ctx);
        goto after_7;
    // 0x8000EDF8: nop

    after_7:
    // 0x8000EDFC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000EE00: beq         $a0, $zero, L_8000EE44
    if (ctx->r4 == 0) {
        // 0x8000EE04: nop
    
            goto L_8000EE44;
    }
    // 0x8000EE04: nop

    // 0x8000EE08: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000EE0C: beq         $v0, $zero, L_8000EE24
    if (ctx->r2 == 0) {
        // 0x8000EE10: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000EE24;
    }
    // 0x8000EE10: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8000EE14:
    // 0x8000EE14: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000EE18: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000EE1C: bne         $v0, $zero, L_8000EE14
    if (ctx->r2 != 0) {
        // 0x8000EE20: nop
    
            goto L_8000EE14;
    }
    // 0x8000EE20: nop

L_8000EE24:
    // 0x8000EE24: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000EE28: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000EE2C: beq         $v0, $zero, L_8000EE38
    if (ctx->r2 == 0) {
        // 0x8000EE30: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000EE38;
    }
    // 0x8000EE30: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000EE34: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8000EE38:
    // 0x8000EE38: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000EE3C: sw          $a0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r4;
    // 0x8000EE40: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000EE44:
    // 0x8000EE44: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000EE48: lw          $a0, 0x63B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63B0);
L_8000EE4C:
    // 0x8000EE4C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000EE50: lw          $v0, 0x63B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63B0);
    // 0x8000EE54: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000EE58: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000EE5C: sw          $v0, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r2;
    // 0x8000EE60: bnel        $v0, $zero, L_8000EE68
    if (ctx->r2 != 0) {
        // 0x8000EE64: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8000EE68;
    }
    goto skip_4;
    // 0x8000EE64: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_4:
L_8000EE68:
    // 0x8000EE68: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000EE6C: lw          $v1, 0x63FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63FC);
    // 0x8000EE70: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000EE74: bne         $v0, $zero, L_8000EE84
    if (ctx->r2 != 0) {
        // 0x8000EE78: nop
    
            goto L_8000EE84;
    }
    // 0x8000EE78: nop

    // 0x8000EE7C: j           L_8000EE9C
    // 0x8000EE80: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8000EE9C;
    // 0x8000EE80: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8000EE84:
    // 0x8000EE84: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000EE88: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000EE8C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000EE90: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000EE94: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000EE98: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8000EE9C:
    // 0x8000EE9C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000EEA0: lw          $v0, -0x5824($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5824);
    // 0x8000EEA4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000EEA8: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000EEAC: addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // 0x8000EEB0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000EEB4: sw          $v0, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r2;
    // 0x8000EEB8: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000EEBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000EEC0: sw          $v0, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r2;
L_8000EEC4:
    // 0x8000EEC4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000EEC8: lw          $v0, -0x23A8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X23A8);
    // 0x8000EECC: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x8000EED0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000EED4: sw          $v1, -0x23A8($at)
    MEM_W(-0X23A8, ctx->r1) = ctx->r3;
    // 0x8000EED8: lui         $v1, 0xBB00
    ctx->r3 = S32(0XBB00 << 16);
    // 0x8000EEDC: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8000EEE0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
L_8000EEE4:
    // 0x8000EEE4: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8000EEE8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8000EEEC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8000EEF0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8000EEF4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000EEF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000EEFC: jr          $ra
    // 0x8000EF00: nop

    return;
    // 0x8000EF00: nop

;}
RECOMP_FUNC void func_8000EF04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000EF04: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8000EF08: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000EF0C: addiu       $a1, $a1, -0x5748
    ctx->r5 = ADD32(ctx->r5, -0X5748);
    // 0x8000EF10: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000EF14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000EF18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000EF1C: sb          $v0, -0x5BAC($at)
    MEM_B(-0X5BAC, ctx->r1) = ctx->r2;
    // 0x8000EF20: beq         $v1, $zero, L_8000EF4C
    if (ctx->r3 == 0) {
        // 0x8000EF24: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8000EF4C;
    }
    // 0x8000EF24: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8000EF28:
    // 0x8000EF28: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000EF2C: lw          $v0, -0x1754($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1754);
    // 0x8000EF30: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000EF34: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8000EF38: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8000EF3C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000EF40: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8000EF44: bne         $v0, $zero, L_8000EF28
    if (ctx->r2 != 0) {
        // 0x8000EF48: nop
    
            goto L_8000EF28;
    }
    // 0x8000EF48: nop

L_8000EF4C:
    // 0x8000EF4C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000EF50: sw          $zero, 0x4380($at)
    MEM_W(0X4380, ctx->r1) = 0;
    // 0x8000EF54: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8000EF58:
    // 0x8000EF58: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000EF5C: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8000EF60: sb          $zero, -0x750($at)
    MEM_B(-0X750, ctx->r1) = 0;
    // 0x8000EF64: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000EF68: sltiu       $v0, $a0, 0x400
    ctx->r2 = ctx->r4 < 0X400 ? 1 : 0;
    // 0x8000EF6C: bne         $v0, $zero, L_8000EF58
    if (ctx->r2 != 0) {
        // 0x8000EF70: nop
    
            goto L_8000EF58;
    }
    // 0x8000EF70: nop

    // 0x8000EF74: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000EF78: sw          $zero, 0x43A4($at)
    MEM_W(0X43A4, ctx->r1) = 0;
    // 0x8000EF7C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8000EF80: jr          $ra
    // 0x8000EF84: nop

    return;
    // 0x8000EF84: nop

;}
RECOMP_FUNC void func_8000EF88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000EF88: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8000EF8C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8000EF90: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8000EF94: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8000EF98: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x8000EF9C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8000EFA0: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x8000EFA4: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8000EFA8: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x8000EFAC: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8000EFB0: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x8000EFB4: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x8000EFB8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000EFBC: addiu       $v0, $v0, 0x437C
    ctx->r2 = ADD32(ctx->r2, 0X437C);
    // 0x8000EFC0: sw          $ra, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r31;
    // 0x8000EFC4: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
L_8000EFC8:
    // 0x8000EFC8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8000EFCC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8000EFD0: bgez        $a0, L_8000EFC8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8000EFD4: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_8000EFC8;
    }
    // 0x8000EFD4: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x8000EFD8: lw          $s0, 0x10($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X10);
    // 0x8000EFDC: beq         $s0, $zero, L_8000EFF8
    if (ctx->r16 == 0) {
        // 0x8000EFE0: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8000EFF8;
    }
    // 0x8000EFE0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_8000EFE4:
    // 0x8000EFE4: jal         0x8000DCFC
    // 0x8000EFE8: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8000DCFC(rdram, ctx);
        goto after_0;
    // 0x8000EFE8: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_0:
    // 0x8000EFEC: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x8000EFF0: bne         $s0, $zero, L_8000EFE4
    if (ctx->r16 != 0) {
        // 0x8000EFF4: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8000EFE4;
    }
    // 0x8000EFF4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_8000EFF8:
    // 0x8000EFF8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000EFFC: lbu         $v0, -0x5BAC($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5BAC);
    // 0x8000F000: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000F004: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000F008: sb          $v0, -0x5BAC($at)
    MEM_B(-0X5BAC, ctx->r1) = ctx->r2;
    // 0x8000F00C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8000F010: bne         $v0, $zero, L_8000F020
    if (ctx->r2 != 0) {
        // 0x8000F014: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000F020;
    }
    // 0x8000F014: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000F018: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000F01C: sb          $v0, -0x5BAC($at)
    MEM_B(-0X5BAC, ctx->r1) = ctx->r2;
L_8000F020:
    // 0x8000F020: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000F024: lw          $v0, -0x5744($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5744);
    // 0x8000F028: beq         $v0, $zero, L_8000F0C8
    if (ctx->r2 == 0) {
        // 0x8000F02C: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8000F0C8;
    }
    // 0x8000F02C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8000F030: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
L_8000F034:
    // 0x8000F034: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000F038: lw          $a0, 0x4380($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4380);
    // 0x8000F03C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000F040: lw          $v1, -0x1754($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1754);
    // 0x8000F044: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8000F048: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8000F04C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000F050: sw          $v0, 0x4380($at)
    MEM_W(0X4380, ctx->r1) = ctx->r2;
    // 0x8000F054: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8000F058: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000F05C: lw          $v1, 0x4380($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4380);
    // 0x8000F060: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000F064: lw          $v0, -0x5748($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5748);
    // 0x8000F068: bne         $v1, $v0, L_8000F078
    if (ctx->r3 != ctx->r2) {
        // 0x8000F06C: nop
    
            goto L_8000F078;
    }
    // 0x8000F06C: nop

    // 0x8000F070: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000F074: sw          $zero, 0x4380($at)
    MEM_W(0X4380, ctx->r1) = 0;
L_8000F078:
    // 0x8000F078: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000F07C: lw          $v0, 0x43A4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43A4);
    // 0x8000F080: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8000F084: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000F088: sw          $v1, 0x43A4($at)
    MEM_W(0X43A4, ctx->r1) = ctx->r3;
    // 0x8000F08C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000F090: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000F094: sb          $zero, -0x750($at)
    MEM_B(-0X750, ctx->r1) = 0;
    // 0x8000F098: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000F09C: lw          $v0, 0x43A4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43A4);
    // 0x8000F0A0: bne         $v0, $a2, L_8000F0B0
    if (ctx->r2 != ctx->r6) {
        // 0x8000F0A4: nop
    
            goto L_8000F0B0;
    }
    // 0x8000F0A4: nop

    // 0x8000F0A8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000F0AC: sw          $zero, 0x43A4($at)
    MEM_W(0X43A4, ctx->r1) = 0;
L_8000F0B0:
    // 0x8000F0B0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000F0B4: lw          $v0, -0x5744($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5744);
    // 0x8000F0B8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000F0BC: sltu        $v0, $a1, $v0
    ctx->r2 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x8000F0C0: bne         $v0, $zero, L_8000F034
    if (ctx->r2 != 0) {
        // 0x8000F0C4: nop
    
            goto L_8000F034;
    }
    // 0x8000F0C4: nop

L_8000F0C8:
    // 0x8000F0C8: sb          $zero, 0x0($s4)
    MEM_B(0X0, ctx->r20) = 0;
    // 0x8000F0CC: sb          $zero, 0x0($s5)
    MEM_B(0X0, ctx->r21) = 0;
    // 0x8000F0D0: lw          $a3, 0x20($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X20);
    // 0x8000F0D4: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x8000F0D8: addiu       $t1, $t1, 0x43B0
    ctx->r9 = ADD32(ctx->r9, 0X43B0);
    // 0x8000F0DC: beq         $a3, $zero, L_8000F3D0
    if (ctx->r7 == 0) {
        // 0x8000F0E0: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8000F3D0;
    }
    // 0x8000F0E0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8000F0E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000F0E8: lwc1        $f8, 0x628($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X628);
    // 0x8000F0EC: addiu       $t3, $zero, 0x60
    ctx->r11 = ADD32(0, 0X60);
    // 0x8000F0F0: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x8000F0F4: addiu       $t2, $t2, -0x1750
    ctx->r10 = ADD32(ctx->r10, -0X1750);
L_8000F0F8:
    // 0x8000F0F8: lw          $v0, 0xC($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XC);
    // 0x8000F0FC: lw          $a2, 0x8($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X8);
    // 0x8000F100: beq         $v0, $zero, L_8000F3C4
    if (ctx->r2 == 0) {
        // 0x8000F104: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_8000F3C4;
    }
    // 0x8000F104: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
L_8000F108:
    // 0x8000F108: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8000F10C: andi        $v0, $v1, 0x100
    ctx->r2 = ctx->r3 & 0X100;
    // 0x8000F110: bne         $v0, $zero, L_8000F3A4
    if (ctx->r2 != 0) {
        // 0x8000F114: andi        $v0, $v1, 0x2
        ctx->r2 = ctx->r3 & 0X2;
            goto L_8000F3A4;
    }
    // 0x8000F114: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x8000F118: beql        $v0, $zero, L_8000F2D8
    if (ctx->r2 == 0) {
        // 0x8000F11C: sb          $t4, 0x0($s4)
        MEM_B(0X0, ctx->r20) = ctx->r12;
            goto L_8000F2D8;
    }
    goto skip_0;
    // 0x8000F11C: sb          $t4, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r12;
    skip_0:
    // 0x8000F120: sb          $t4, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r12;
    // 0x8000F124: lhu         $v0, 0x4($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X4);
    // 0x8000F128: lw          $v1, 0xC($s2)
    ctx->r3 = MEM_W(ctx->r18, 0XC);
    // 0x8000F12C: andi        $v0, $v0, 0xFC
    ctx->r2 = ctx->r2 & 0XFC;
    // 0x8000F130: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8000F134: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x8000F138: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x8000F13C: beq         $v1, $zero, L_8000F198
    if (ctx->r3 == 0) {
        // 0x8000F140: sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4 << 1);
            goto L_8000F198;
    }
    // 0x8000F140: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8000F144: lw          $v1, 0x24($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X24);
    // 0x8000F148: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000F14C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000F150: lwc1        $f2, 0x18($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8000F154: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000F158: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000F15C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8000F160: lwc1        $f6, 0x1C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8000F164: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8000F168: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8000F16C: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8000F170: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8000F174: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8000F178: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x8000F17C: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8000F180: lwc1        $f0, 0x2C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x8000F184: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8000F188: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8000F18C: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x8000F190: j           L_8000F220
    // 0x8000F194: nop

        goto L_8000F220;
    // 0x8000F194: nop

L_8000F198:
    // 0x8000F198: lw          $v0, 0x24($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X24);
    // 0x8000F19C: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x8000F1A0: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8000F1A4: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x8000F1A8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8000F1AC: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000F1B0: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8000F1B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8000F1B8: lw          $v0, 0x24($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X24);
    // 0x8000F1BC: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8000F1C0: lh          $v0, 0x2($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2);
    // 0x8000F1C4: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8000F1C8: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8000F1CC: mul.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8000F1D0: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x8000F1D4: lw          $v0, 0x24($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X24);
    // 0x8000F1D8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000F1DC: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x8000F1E0: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8000F1E4: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000F1E8: mul.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8000F1EC: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8000F1F0: lwc1        $f0, 0x18($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8000F1F4: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8000F1F8: lwc1        $f4, 0x1C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8000F1FC: mul.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8000F200: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8000F204: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8000F208: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8000F20C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8000F210: lwc1        $f2, 0x2C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x8000F214: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8000F218: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8000F21C: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
L_8000F220:
    // 0x8000F220: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000F224: lwc1        $f2, 0x62C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X62C);
    // 0x8000F228: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x8000F22C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8000F230: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8000F234: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000F238: lwc1        $f2, 0x630($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X630);
    // 0x8000F23C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8000F240: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8000F244: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x8000F248: bltz        $a0, L_8000F260
    if (SIGNED(ctx->r4) < 0) {
        // 0x8000F24C: slti        $v0, $a0, 0x200
        ctx->r2 = SIGNED(ctx->r4) < 0X200 ? 1 : 0;
            goto L_8000F260;
    }
    // 0x8000F24C: slti        $v0, $a0, 0x200
    ctx->r2 = SIGNED(ctx->r4) < 0X200 ? 1 : 0;
    // 0x8000F250: beq         $v0, $zero, L_8000F264
    if (ctx->r2 == 0) {
        // 0x8000F254: addiu       $a1, $zero, 0x1FF
        ctx->r5 = ADD32(0, 0X1FF);
            goto L_8000F264;
    }
    // 0x8000F254: addiu       $a1, $zero, 0x1FF
    ctx->r5 = ADD32(0, 0X1FF);
    // 0x8000F258: j           L_8000F264
    // 0x8000F25C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
        goto L_8000F264;
    // 0x8000F25C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
L_8000F260:
    // 0x8000F260: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8000F264:
    // 0x8000F264: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8000F268: andi        $v0, $v1, 0x10
    ctx->r2 = ctx->r3 & 0X10;
    // 0x8000F26C: bne         $v0, $zero, L_8000F280
    if (ctx->r2 != 0) {
        // 0x8000F270: addu        $a0, $a1, $zero
        ctx->r4 = ADD32(ctx->r5, 0);
            goto L_8000F280;
    }
    // 0x8000F270: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x8000F274: andi        $v0, $v1, 0x60
    ctx->r2 = ctx->r3 & 0X60;
    // 0x8000F278: bne         $v0, $t3, L_8000F284
    if (ctx->r2 != ctx->r11) {
        // 0x8000F27C: nop
    
            goto L_8000F284;
    }
    // 0x8000F27C: nop

L_8000F280:
    // 0x8000F280: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
L_8000F284:
    // 0x8000F284: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000F288: lbu         $v1, -0x5BAC($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X5BAC);
    // 0x8000F28C: addu        $a1, $t1, $zero
    ctx->r5 = ADD32(ctx->r9, 0);
    // 0x8000F290: sw          $a2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r6;
    // 0x8000F294: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000F298: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8000F29C: lbu         $v0, -0x750($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X750);
    // 0x8000F2A0: bne         $v0, $v1, L_8000F2BC
    if (ctx->r2 != ctx->r3) {
        // 0x8000F2A4: addiu       $t1, $a1, 0x8
        ctx->r9 = ADD32(ctx->r5, 0X8);
            goto L_8000F2BC;
    }
    // 0x8000F2A4: addiu       $t1, $a1, 0x8
    ctx->r9 = ADD32(ctx->r5, 0X8);
    // 0x8000F2A8: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8000F2AC: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x8000F2B0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000F2B4: j           L_8000F2CC
    // 0x8000F2B8: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_8000F2CC;
    // 0x8000F2B8: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_8000F2BC:
    // 0x8000F2BC: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8000F2C0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000F2C4: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8000F2C8: sb          $v1, -0x750($at)
    MEM_B(-0X750, ctx->r1) = ctx->r3;
L_8000F2CC:
    // 0x8000F2CC: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8000F2D0: j           L_8000F3A0
    // 0x8000F2D4: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
        goto L_8000F3A0;
    // 0x8000F2D4: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
L_8000F2D8:
    // 0x8000F2D8: lhu         $a0, 0x8($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X8);
    // 0x8000F2DC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000F2E0: lw          $v1, -0x5BBC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5BBC);
    // 0x8000F2E4: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8000F2E8: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // 0x8000F2EC: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8000F2F0: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8000F2F4: beq         $v0, $zero, L_8000F318
    if (ctx->r2 == 0) {
        // 0x8000F2F8: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8000F318;
    }
    // 0x8000F2F8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8000F2FC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8000F300: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x8000F304: beq         $v0, $zero, L_8000F318
    if (ctx->r2 == 0) {
        // 0x8000F308: nop
    
            goto L_8000F318;
    }
    // 0x8000F308: nop

    // 0x8000F30C: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x8000F310: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000F314: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
L_8000F318:
    // 0x8000F318: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8000F31C: andi        $v0, $v1, 0x10
    ctx->r2 = ctx->r3 & 0X10;
    // 0x8000F320: bnel        $v0, $zero, L_8000F338
    if (ctx->r2 != 0) {
        // 0x8000F324: ori         $a0, $a0, 0x1
        ctx->r4 = ctx->r4 | 0X1;
            goto L_8000F338;
    }
    goto skip_1;
    // 0x8000F324: ori         $a0, $a0, 0x1
    ctx->r4 = ctx->r4 | 0X1;
    skip_1:
    // 0x8000F328: andi        $v0, $v1, 0x60
    ctx->r2 = ctx->r3 & 0X60;
    // 0x8000F32C: bne         $v0, $t3, L_8000F33C
    if (ctx->r2 != ctx->r11) {
        // 0x8000F330: addu        $a1, $t1, $zero
        ctx->r5 = ADD32(ctx->r9, 0);
            goto L_8000F33C;
    }
    // 0x8000F330: addu        $a1, $t1, $zero
    ctx->r5 = ADD32(ctx->r9, 0);
    // 0x8000F334: ori         $a0, $a0, 0x1
    ctx->r4 = ctx->r4 | 0X1;
L_8000F338:
    // 0x8000F338: addu        $a1, $t1, $zero
    ctx->r5 = ADD32(ctx->r9, 0);
L_8000F33C:
    // 0x8000F33C: sw          $a2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r6;
    // 0x8000F340: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000F344: lw          $v0, -0x1754($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1754);
    // 0x8000F348: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000F34C: lbu         $v1, -0x5BAC($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X5BAC);
    // 0x8000F350: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000F354: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8000F358: bne         $v0, $v1, L_8000F37C
    if (ctx->r2 != ctx->r3) {
        // 0x8000F35C: addiu       $t1, $a1, 0x8
        ctx->r9 = ADD32(ctx->r5, 0X8);
            goto L_8000F37C;
    }
    // 0x8000F35C: addiu       $t1, $a1, 0x8
    ctx->r9 = ADD32(ctx->r5, 0X8);
    // 0x8000F360: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000F364: lw          $v0, -0x1758($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1758);
    // 0x8000F368: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8000F36C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000F370: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000F374: j           L_8000F390
    // 0x8000F378: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_8000F390;
    // 0x8000F378: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_8000F37C:
    // 0x8000F37C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8000F380: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000F384: lw          $v0, -0x1754($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1754);
    // 0x8000F388: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000F38C: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_8000F390:
    // 0x8000F390: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000F394: lw          $v1, -0x1758($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1758);
    // 0x8000F398: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8000F39C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_8000F3A0:
    // 0x8000F3A0: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_8000F3A4:
    // 0x8000F3A4: lbu         $v0, 0x4($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X4);
    // 0x8000F3A8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8000F3AC: lw          $v1, 0xC($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XC);
    // 0x8000F3B0: andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // 0x8000F3B4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000F3B8: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x8000F3BC: bne         $v1, $zero, L_8000F108
    if (ctx->r3 != 0) {
        // 0x8000F3C0: addu        $a2, $a2, $v0
        ctx->r6 = ADD32(ctx->r6, ctx->r2);
            goto L_8000F108;
    }
    // 0x8000F3C0: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
L_8000F3C4:
    // 0x8000F3C4: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    // 0x8000F3C8: bne         $a3, $zero, L_8000F0F8
    if (ctx->r7 != 0) {
        // 0x8000F3CC: nop
    
            goto L_8000F0F8;
    }
    // 0x8000F3CC: nop

L_8000F3D0:
    // 0x8000F3D0: lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X48);
    // 0x8000F3D4: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8000F3D8: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8000F3DC: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F3E0: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8000F3E4: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8000F3E8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8000F3EC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8000F3F0: jr          $ra
    // 0x8000F3F4: nop

    return;
    // 0x8000F3F4: nop

;}
RECOMP_FUNC void func_8000F3F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F3F8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000F3FC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8000F400: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x8000F404: beq         $v0, $zero, L_8000F410
    if (ctx->r2 == 0) {
        // 0x8000F408: addiu       $t5, $zero, 0x3
        ctx->r13 = ADD32(0, 0X3);
            goto L_8000F410;
    }
    // 0x8000F408: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8000F40C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
L_8000F410:
    // 0x8000F410: lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X4);
    // 0x8000F414: addu        $t3, $zero, $zero
    ctx->r11 = ADD32(0, 0);
    // 0x8000F418: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x8000F41C: andi        $v0, $v0, 0xFC
    ctx->r2 = ctx->r2 & 0XFC;
    // 0x8000F420: addu        $t6, $a0, $v0
    ctx->r14 = ADD32(ctx->r4, ctx->r2);
    // 0x8000F424: andi        $v0, $t5, 0xFF
    ctx->r2 = ctx->r13 & 0XFF;
    // 0x8000F428: beq         $v0, $zero, L_8000F4B4
    if (ctx->r2 == 0) {
        // 0x8000F42C: addu        $t4, $sp, $zero
        ctx->r12 = ADD32(ctx->r29, 0);
            goto L_8000F4B4;
    }
    // 0x8000F42C: addu        $t4, $sp, $zero
    ctx->r12 = ADD32(ctx->r29, 0);
    // 0x8000F430: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8000F434: addu        $t7, $v0, $zero
    ctx->r15 = ADD32(ctx->r2, 0);
    // 0x8000F438: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
L_8000F43C:
    // 0x8000F43C: sll         $v0, $t2, 1
    ctx->r2 = S32(ctx->r10 << 1);
    // 0x8000F440: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8000F444: lhu         $a3, 0x0($v0)
    ctx->r7 = MEM_HU(ctx->r2, 0X0);
    // 0x8000F448: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000F44C: addu        $at, $at, $a3
    ctx->r1 = ADD32(ctx->r1, ctx->r7);
    // 0x8000F450: lbu         $t0, 0x32C0($at)
    ctx->r8 = MEM_BU(ctx->r1, 0X32C0);
    // 0x8000F454: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000F458: lhu         $v0, 0x42C0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X42C0);
    // 0x8000F45C: sll         $a0, $t0, 2
    ctx->r4 = S32(ctx->r8 << 2);
    // 0x8000F460: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000F464: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8000F468: lhu         $v1, 0x3242($at)
    ctx->r3 = MEM_HU(ctx->r1, 0X3242);
    // 0x8000F46C: bne         $v1, $v0, L_8000F494
    if (ctx->r3 != ctx->r2) {
        // 0x8000F470: andi        $v0, $t1, 0xFF
        ctx->r2 = ctx->r9 & 0XFF;
            goto L_8000F494;
    }
    // 0x8000F470: andi        $v0, $t1, 0xFF
    ctx->r2 = ctx->r9 & 0XFF;
    // 0x8000F474: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000F478: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8000F47C: lhu         $v0, 0x3240($at)
    ctx->r2 = MEM_HU(ctx->r1, 0X3240);
    // 0x8000F480: bne         $v0, $a3, L_8000F494
    if (ctx->r2 != ctx->r7) {
        // 0x8000F484: andi        $v0, $t1, 0xFF
        ctx->r2 = ctx->r9 & 0XFF;
            goto L_8000F494;
    }
    // 0x8000F484: andi        $v0, $t1, 0xFF
    ctx->r2 = ctx->r9 & 0XFF;
    // 0x8000F488: addu        $v0, $t4, $t2
    ctx->r2 = ADD32(ctx->r12, ctx->r10);
    // 0x8000F48C: j           L_8000F4A0
    // 0x8000F490: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
        goto L_8000F4A0;
    // 0x8000F490: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
L_8000F494:
    // 0x8000F494: addu        $v0, $t4, $v0
    ctx->r2 = ADD32(ctx->r12, ctx->r2);
    // 0x8000F498: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x8000F49C: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
L_8000F4A0:
    // 0x8000F4A0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8000F4A4: andi        $v0, $t1, 0xFF
    ctx->r2 = ctx->r9 & 0XFF;
    // 0x8000F4A8: sltu        $v0, $v0, $t7
    ctx->r2 = ctx->r2 < ctx->r15 ? 1 : 0;
    // 0x8000F4AC: bnel        $v0, $zero, L_8000F43C
    if (ctx->r2 != 0) {
        // 0x8000F4B0: andi        $t2, $t1, 0xFF
        ctx->r10 = ctx->r9 & 0XFF;
            goto L_8000F43C;
    }
    goto skip_0;
    // 0x8000F4B0: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    skip_0:
L_8000F4B4:
    // 0x8000F4B4: andi        $v1, $t3, 0xFF
    ctx->r3 = ctx->r11 & 0XFF;
    // 0x8000F4B8: bne         $v1, $zero, L_8000F4C8
    if (ctx->r3 != 0) {
        // 0x8000F4BC: addu        $t2, $v1, $zero
        ctx->r10 = ADD32(ctx->r3, 0);
            goto L_8000F4C8;
    }
    // 0x8000F4BC: addu        $t2, $v1, $zero
    ctx->r10 = ADD32(ctx->r3, 0);
    // 0x8000F4C0: j           L_8000F618
    // 0x8000F4C4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8000F618;
    // 0x8000F4C4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8000F4C8:
    // 0x8000F4C8: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x8000F4CC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000F4D0: slti        $v0, $v0, 0x21
    ctx->r2 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
    // 0x8000F4D4: bnel        $v0, $zero, L_8000F578
    if (ctx->r2 != 0) {
        // 0x8000F4D8: sb          $zero, 0x0($a1)
        MEM_B(0X0, ctx->r5) = 0;
            goto L_8000F578;
    }
    goto skip_1;
    // 0x8000F4D8: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    skip_1:
    // 0x8000F4DC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000F4E0: lhu         $v0, 0x42C0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X42C0);
    // 0x8000F4E4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000F4E8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000F4EC: sh          $v0, 0x42C0($at)
    MEM_H(0X42C0, ctx->r1) = ctx->r2;
    // 0x8000F4F0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8000F4F4: bne         $v0, $zero, L_8000F508
    if (ctx->r2 != 0) {
        // 0x8000F4F8: andi        $a2, $t5, 0xFF
        ctx->r6 = ctx->r13 & 0XFF;
            goto L_8000F508;
    }
    // 0x8000F4F8: andi        $a2, $t5, 0xFF
    ctx->r6 = ctx->r13 & 0XFF;
    // 0x8000F4FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000F500: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000F504: sh          $v0, 0x42C0($at)
    MEM_H(0X42C0, ctx->r1) = ctx->r2;
L_8000F508:
    // 0x8000F508: beq         $a2, $zero, L_8000F568
    if (ctx->r6 == 0) {
        // 0x8000F50C: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_8000F568;
    }
    // 0x8000F50C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8000F510: andi        $a0, $a3, 0xFF
    ctx->r4 = ctx->r7 & 0XFF;
L_8000F514:
    // 0x8000F514: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x8000F518: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x8000F51C: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8000F520: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000F524: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000F528: sb          $a3, 0x32C0($at)
    MEM_B(0X32C0, ctx->r1) = ctx->r7;
    // 0x8000F52C: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8000F530: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000F534: lhu         $v1, 0x42C0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X42C0);
    // 0x8000F538: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8000F53C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8000F540: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000F544: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8000F548: sh          $v0, 0x3240($at)
    MEM_H(0X3240, ctx->r1) = ctx->r2;
    // 0x8000F54C: andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // 0x8000F550: sltu        $v0, $v0, $a2
    ctx->r2 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x8000F554: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000F558: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8000F55C: sh          $v1, 0x3242($at)
    MEM_H(0X3242, ctx->r1) = ctx->r3;
    // 0x8000F560: bne         $v0, $zero, L_8000F514
    if (ctx->r2 != 0) {
        // 0x8000F564: andi        $a0, $a3, 0xFF
        ctx->r4 = ctx->r7 & 0XFF;
            goto L_8000F514;
    }
    // 0x8000F564: andi        $a0, $a3, 0xFF
    ctx->r4 = ctx->r7 & 0XFF;
L_8000F568:
    // 0x8000F568: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x8000F56C: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x8000F570: j           L_8000F618
    // 0x8000F574: addu        $v0, $t5, $zero
    ctx->r2 = ADD32(ctx->r13, 0);
        goto L_8000F618;
    // 0x8000F574: addu        $v0, $t5, $zero
    ctx->r2 = ADD32(ctx->r13, 0);
L_8000F578:
    // 0x8000F578: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8000F57C: andi        $v0, $t5, 0xFF
    ctx->r2 = ctx->r13 & 0XFF;
    // 0x8000F580: beq         $v0, $zero, L_8000F614
    if (ctx->r2 == 0) {
        // 0x8000F584: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8000F614;
    }
    // 0x8000F584: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8000F588: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8000F58C: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_8000F590:
    // 0x8000F590: andi        $v1, $a3, 0xFF
    ctx->r3 = ctx->r7 & 0XFF;
    // 0x8000F594: addu        $v0, $sp, $v1
    ctx->r2 = ADD32(ctx->r29, ctx->r3);
    // 0x8000F598: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8000F59C: bne         $v0, $t1, L_8000F604
    if (ctx->r2 != ctx->r9) {
        // 0x8000F5A0: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_8000F604;
    }
    // 0x8000F5A0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8000F5A4: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8000F5A8: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x8000F5AC: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8000F5B0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000F5B4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000F5B8: sb          $a2, 0x32C0($at)
    MEM_B(0X32C0, ctx->r1) = ctx->r6;
    // 0x8000F5BC: lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X0);
    // 0x8000F5C0: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x8000F5C4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000F5C8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000F5CC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000F5D0: sh          $v1, 0x3240($at)
    MEM_H(0X3240, ctx->r1) = ctx->r3;
    // 0x8000F5D4: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // 0x8000F5D8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000F5DC: lhu         $v1, 0x42C0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X42C0);
    // 0x8000F5E0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8000F5E4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000F5E8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000F5EC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000F5F0: sh          $v1, 0x3242($at)
    MEM_H(0X3242, ctx->r1) = ctx->r3;
    // 0x8000F5F4: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8000F5F8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000F5FC: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x8000F600: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
L_8000F604:
    // 0x8000F604: andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // 0x8000F608: sltu        $v0, $v0, $t0
    ctx->r2 = ctx->r2 < ctx->r8 ? 1 : 0;
    // 0x8000F60C: bne         $v0, $zero, L_8000F590
    if (ctx->r2 != 0) {
        // 0x8000F610: sll         $a0, $a0, 1
        ctx->r4 = S32(ctx->r4 << 1);
            goto L_8000F590;
    }
    // 0x8000F610: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
L_8000F614:
    // 0x8000F614: addu        $v0, $t2, $zero
    ctx->r2 = ADD32(ctx->r10, 0);
L_8000F618:
    // 0x8000F618: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8000F61C: jr          $ra
    // 0x8000F620: nop

    return;
    // 0x8000F620: nop

;}
