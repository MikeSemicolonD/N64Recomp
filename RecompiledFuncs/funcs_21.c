#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80084B68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80084B6C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80084B70: jal         0x80084860
    // 0x80084B74: addiu       $a1, $a0, 0x108
    ctx->r5 = ADD32(ctx->r4, 0X108);
    func_80084860(rdram, ctx);
        goto after_0;
    // 0x80084B74: addiu       $a1, $a0, 0x108
    ctx->r5 = ADD32(ctx->r4, 0X108);
    after_0:
    // 0x80084B78: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80084B7C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80084B80: jr          $ra
    // 0x80084B84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80084B84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80084B88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80084B8C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80084B90: jal         0x80084860
    // 0x80084B94: addiu       $a1, $a0, 0x11A
    ctx->r5 = ADD32(ctx->r4, 0X11A);
    func_80084860(rdram, ctx);
        goto after_0;
    // 0x80084B94: addiu       $a1, $a0, 0x11A
    ctx->r5 = ADD32(ctx->r4, 0X11A);
    after_0:
    // 0x80084B98: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80084B9C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80084BA0: jr          $ra
    // 0x80084BA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80084BA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80084BA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084BA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80084BAC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80084BB0: jal         0x80084860
    // 0x80084BB4: addiu       $a1, $a0, 0x12C
    ctx->r5 = ADD32(ctx->r4, 0X12C);
    func_80084860(rdram, ctx);
        goto after_0;
    // 0x80084BB4: addiu       $a1, $a0, 0x12C
    ctx->r5 = ADD32(ctx->r4, 0X12C);
    after_0:
    // 0x80084BB8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80084BBC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80084BC0: jr          $ra
    // 0x80084BC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80084BC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80084BC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084BC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80084BCC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80084BD0: jal         0x80084860
    // 0x80084BD4: addiu       $a1, $a0, 0x13E
    ctx->r5 = ADD32(ctx->r4, 0X13E);
    func_80084860(rdram, ctx);
        goto after_0;
    // 0x80084BD4: addiu       $a1, $a0, 0x13E
    ctx->r5 = ADD32(ctx->r4, 0X13E);
    after_0:
    // 0x80084BD8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80084BDC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80084BE0: jr          $ra
    // 0x80084BE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80084BE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80084BE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084BE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80084BEC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80084BF0: jal         0x80084860
    // 0x80084BF4: addiu       $a1, $a0, 0x150
    ctx->r5 = ADD32(ctx->r4, 0X150);
    func_80084860(rdram, ctx);
        goto after_0;
    // 0x80084BF4: addiu       $a1, $a0, 0x150
    ctx->r5 = ADD32(ctx->r4, 0X150);
    after_0:
    // 0x80084BF8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80084BFC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80084C00: jr          $ra
    // 0x80084C04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80084C04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80084C08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084C08: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80084C0C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80084C10: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80084C14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80084C18: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80084C1C: jal         0x80092010
    // 0x80084C20: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    factor5MutexAcquire(rdram, ctx);
        goto after_0;
    // 0x80084C20: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80084C24: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80084C28: lw          $a0, -0x3BB0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3BB0);
    // 0x80084C2C: blez        $a0, L_80084CE8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80084C30: addu        $t1, $zero, $zero
        ctx->r9 = ADD32(0, 0);
            goto L_80084CE8;
    }
    // 0x80084C30: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x80084C34: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    // 0x80084C38: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80084C3C:
    // 0x80084C3C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80084C40: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80084C44: lhu         $v0, -0x43B4($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X43B4);
    // 0x80084C48: sltu        $v0, $v0, $a1
    ctx->r2 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x80084C4C: beq         $v0, $zero, L_80084C64
    if (ctx->r2 == 0) {
        // 0x80084C50: nop
    
            goto L_80084C64;
    }
    // 0x80084C50: nop

    // 0x80084C54: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80084C58: slt         $v0, $t1, $a0
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80084C5C: bne         $v0, $zero, L_80084C3C
    if (ctx->r2 != 0) {
        // 0x80084C60: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_80084C3C;
    }
    // 0x80084C60: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80084C64:
    // 0x80084C64: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80084C68: lw          $v1, -0x3BB0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3BB0);
    // 0x80084C6C: slt         $v0, $t1, $v1
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80084C70: beq         $v0, $zero, L_80084CF0
    if (ctx->r2 == 0) {
        // 0x80084C74: sll         $v0, $t1, 3
        ctx->r2 = S32(ctx->r9 << 3);
            goto L_80084CF0;
    }
    // 0x80084C74: sll         $v0, $t1, 3
    ctx->r2 = S32(ctx->r9 << 3);
    // 0x80084C78: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80084C7C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80084C80: lhu         $v0, -0x43B4($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X43B4);
    // 0x80084C84: beq         $v0, $a1, L_80084CFC
    if (ctx->r2 == ctx->r5) {
        // 0x80084C88: slti        $v0, $v1, 0x100
        ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
            goto L_80084CFC;
    }
    // 0x80084C88: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80084C8C: beq         $v0, $zero, L_80084CFC
    if (ctx->r2 == 0) {
        // 0x80084C90: addiu       $a3, $v1, -0x1
        ctx->r7 = ADD32(ctx->r3, -0X1);
            goto L_80084CFC;
    }
    // 0x80084C90: addiu       $a3, $v1, -0x1
    ctx->r7 = ADD32(ctx->r3, -0X1);
    // 0x80084C94: slt         $v0, $a3, $t1
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80084C98: bne         $v0, $zero, L_80084CD8
    if (ctx->r2 != 0) {
        // 0x80084C9C: sll         $v1, $a3, 3
        ctx->r3 = S32(ctx->r7 << 3);
            goto L_80084CD8;
    }
    // 0x80084C9C: sll         $v1, $a3, 3
    ctx->r3 = S32(ctx->r7 << 3);
    // 0x80084CA0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80084CA4: addiu       $v0, $v0, -0x43B0
    ctx->r2 = ADD32(ctx->r2, -0X43B0);
    // 0x80084CA8: addu        $t0, $v1, $v0
    ctx->r8 = ADD32(ctx->r3, ctx->r2);
    // 0x80084CAC: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // 0x80084CB0: addu        $a2, $v1, $v0
    ctx->r6 = ADD32(ctx->r3, ctx->r2);
L_80084CB4:
    // 0x80084CB4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80084CB8: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x80084CBC: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80084CC0: sw          $v1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r3;
    // 0x80084CC4: addiu       $t0, $t0, -0x8
    ctx->r8 = ADD32(ctx->r8, -0X8);
    // 0x80084CC8: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x80084CCC: slt         $v0, $a3, $t1
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80084CD0: beq         $v0, $zero, L_80084CB4
    if (ctx->r2 == 0) {
        // 0x80084CD4: addiu       $a2, $a2, -0x8
        ctx->r6 = ADD32(ctx->r6, -0X8);
            goto L_80084CB4;
    }
    // 0x80084CD4: addiu       $a2, $a2, -0x8
    ctx->r6 = ADD32(ctx->r6, -0X8);
L_80084CD8:
    // 0x80084CD8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80084CDC: lw          $v0, -0x3BB0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3BB0);
    // 0x80084CE0: j           L_80084D0C
    // 0x80084CE4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_80084D0C;
    // 0x80084CE4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80084CE8:
    // 0x80084CE8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80084CEC: lw          $v1, -0x3BB0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3BB0);
L_80084CF0:
    // 0x80084CF0: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80084CF4: bne         $v0, $zero, L_80084D0C
    if (ctx->r2 != 0) {
        // 0x80084CF8: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_80084D0C;
    }
    // 0x80084CF8: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_80084CFC:
    // 0x80084CFC: jal         0x8009205C
    // 0x80084D00: nop

    factor5MutexRelease(rdram, ctx);
        goto after_1;
    // 0x80084D00: nop

    after_1:
    // 0x80084D04: j           L_80084D3C
    // 0x80084D08: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80084D3C;
    // 0x80084D08: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80084D0C:
    // 0x80084D0C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80084D10: sw          $v0, -0x3BB0($at)
    MEM_W(-0X3BB0, ctx->r1) = ctx->r2;
    // 0x80084D14: sll         $v0, $t1, 3
    ctx->r2 = S32(ctx->r9 << 3);
    // 0x80084D18: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80084D1C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80084D20: sh          $s0, -0x43B4($at)
    MEM_H(-0X43B4, ctx->r1) = ctx->r16;
    // 0x80084D24: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80084D28: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80084D2C: sw          $s1, -0x43B8($at)
    MEM_W(-0X43B8, ctx->r1) = ctx->r17;
    // 0x80084D30: jal         0x8009205C
    // 0x80084D34: nop

    factor5MutexRelease(rdram, ctx);
        goto after_2;
    // 0x80084D34: nop

    after_2:
    // 0x80084D38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80084D3C:
    // 0x80084D3C: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80084D40: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80084D44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80084D48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80084D4C: jr          $ra
    // 0x80084D50: nop

    return;
    // 0x80084D50: nop

;}
RECOMP_FUNC void func_80084D54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084D54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80084D58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80084D5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80084D60: jal         0x80092010
    // 0x80084D64: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    factor5MutexAcquire(rdram, ctx);
        goto after_0;
    // 0x80084D64: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80084D68: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80084D6C: lw          $a2, -0x3BB0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X3BB0);
    // 0x80084D70: blez        $a2, L_80084DA4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80084D74: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80084DA4;
    }
    // 0x80084D74: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80084D78: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x80084D7C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80084D80:
    // 0x80084D80: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80084D84: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x80084D88: lhu         $v0, -0x43B4($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X43B4);
    // 0x80084D8C: beq         $v0, $a0, L_80084DA4
    if (ctx->r2 == ctx->r4) {
        // 0x80084D90: nop
    
            goto L_80084DA4;
    }
    // 0x80084D90: nop

    // 0x80084D94: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80084D98: slt         $v0, $v1, $a2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80084D9C: bne         $v0, $zero, L_80084D80
    if (ctx->r2 != 0) {
        // 0x80084DA0: addiu       $a1, $a1, 0x8
        ctx->r5 = ADD32(ctx->r5, 0X8);
            goto L_80084D80;
    }
    // 0x80084DA0: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
L_80084DA4:
    // 0x80084DA4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80084DA8: lw          $v0, -0x3BB0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3BB0);
    // 0x80084DAC: beq         $v1, $v0, L_80084E24
    if (ctx->r3 == ctx->r2) {
        // 0x80084DB0: addiu       $a2, $v1, 0x1
        ctx->r6 = ADD32(ctx->r3, 0X1);
            goto L_80084E24;
    }
    // 0x80084DB0: addiu       $a2, $v1, 0x1
    ctx->r6 = ADD32(ctx->r3, 0X1);
    // 0x80084DB4: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80084DB8: beq         $v0, $zero, L_80084E00
    if (ctx->r2 == 0) {
        // 0x80084DBC: sll         $v1, $a2, 3
        ctx->r3 = S32(ctx->r6 << 3);
            goto L_80084E00;
    }
    // 0x80084DBC: sll         $v1, $a2, 3
    ctx->r3 = S32(ctx->r6 << 3);
    // 0x80084DC0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80084DC4: addiu       $v0, $v0, -0x43C0
    ctx->r2 = ADD32(ctx->r2, -0X43C0);
    // 0x80084DC8: addu        $t0, $v1, $v0
    ctx->r8 = ADD32(ctx->r3, ctx->r2);
    // 0x80084DCC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80084DD0: addu        $a3, $v1, $v0
    ctx->r7 = ADD32(ctx->r3, ctx->r2);
L_80084DD4:
    // 0x80084DD4: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80084DD8: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
    // 0x80084DDC: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80084DE0: sw          $v1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r3;
    // 0x80084DE4: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80084DE8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80084DEC: lw          $v0, -0x3BB0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3BB0);
    // 0x80084DF0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80084DF4: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80084DF8: bne         $v0, $zero, L_80084DD4
    if (ctx->r2 != 0) {
        // 0x80084DFC: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_80084DD4;
    }
    // 0x80084DFC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
L_80084E00:
    // 0x80084E00: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80084E04: lw          $v0, -0x3BB0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3BB0);
    // 0x80084E08: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80084E0C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80084E10: sw          $v0, -0x3BB0($at)
    MEM_W(-0X3BB0, ctx->r1) = ctx->r2;
    // 0x80084E14: jal         0x8009205C
    // 0x80084E18: nop

    factor5MutexRelease(rdram, ctx);
        goto after_1;
    // 0x80084E18: nop

    after_1:
    // 0x80084E1C: j           L_80084E30
    // 0x80084E20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80084E30;
    // 0x80084E20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80084E24:
    // 0x80084E24: jal         0x8009205C
    // 0x80084E28: nop

    factor5MutexRelease(rdram, ctx);
        goto after_2;
    // 0x80084E28: nop

    after_2:
    // 0x80084E2C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80084E30:
    // 0x80084E30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80084E34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80084E38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80084E3C: jr          $ra
    // 0x80084E40: nop

    return;
    // 0x80084E40: nop

;}
RECOMP_FUNC void func_80084E44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084E44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80084E48: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80084E4C: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80084E50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80084E54: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80084E58: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80084E5C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80084E60: jal         0x80092010
    // 0x80084E64: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    factor5MutexAcquire(rdram, ctx);
        goto after_0;
    // 0x80084E64: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    after_0:
    // 0x80084E68: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80084E6C: lw          $a0, -0x50F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X50F8);
    // 0x80084E70: blez        $a0, L_80084F2C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80084E74: addu        $t1, $zero, $zero
        ctx->r9 = ADD32(0, 0);
            goto L_80084F2C;
    }
    // 0x80084E74: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x80084E78: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    // 0x80084E7C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80084E80:
    // 0x80084E80: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80084E84: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80084E88: lhu         $v0, -0x7BAC($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X7BAC);
    // 0x80084E8C: sltu        $v0, $v0, $a1
    ctx->r2 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x80084E90: beq         $v0, $zero, L_80084EA8
    if (ctx->r2 == 0) {
        // 0x80084E94: nop
    
            goto L_80084EA8;
    }
    // 0x80084E94: nop

    // 0x80084E98: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80084E9C: slt         $v0, $t1, $a0
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80084EA0: bne         $v0, $zero, L_80084E80
    if (ctx->r2 != 0) {
        // 0x80084EA4: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_80084E80;
    }
    // 0x80084EA4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80084EA8:
    // 0x80084EA8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80084EAC: lw          $v1, -0x50F8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X50F8);
    // 0x80084EB0: slt         $v0, $t1, $v1
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80084EB4: beq         $v0, $zero, L_80084F34
    if (ctx->r2 == 0) {
        // 0x80084EB8: sll         $v0, $t1, 3
        ctx->r2 = S32(ctx->r9 << 3);
            goto L_80084F34;
    }
    // 0x80084EB8: sll         $v0, $t1, 3
    ctx->r2 = S32(ctx->r9 << 3);
    // 0x80084EBC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80084EC0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80084EC4: lhu         $v0, -0x7BAC($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X7BAC);
    // 0x80084EC8: beq         $v0, $a1, L_80084F40
    if (ctx->r2 == ctx->r5) {
        // 0x80084ECC: slti        $v0, $v1, 0x100
        ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
            goto L_80084F40;
    }
    // 0x80084ECC: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80084ED0: beq         $v0, $zero, L_80084F40
    if (ctx->r2 == 0) {
        // 0x80084ED4: addiu       $a3, $v1, -0x1
        ctx->r7 = ADD32(ctx->r3, -0X1);
            goto L_80084F40;
    }
    // 0x80084ED4: addiu       $a3, $v1, -0x1
    ctx->r7 = ADD32(ctx->r3, -0X1);
    // 0x80084ED8: slt         $v0, $a3, $t1
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80084EDC: bne         $v0, $zero, L_80084F1C
    if (ctx->r2 != 0) {
        // 0x80084EE0: sll         $v1, $a3, 3
        ctx->r3 = S32(ctx->r7 << 3);
            goto L_80084F1C;
    }
    // 0x80084EE0: sll         $v1, $a3, 3
    ctx->r3 = S32(ctx->r7 << 3);
    // 0x80084EE4: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80084EE8: addiu       $v0, $v0, -0x7BA8
    ctx->r2 = ADD32(ctx->r2, -0X7BA8);
    // 0x80084EEC: addu        $t0, $v1, $v0
    ctx->r8 = ADD32(ctx->r3, ctx->r2);
    // 0x80084EF0: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // 0x80084EF4: addu        $a2, $v1, $v0
    ctx->r6 = ADD32(ctx->r3, ctx->r2);
L_80084EF8:
    // 0x80084EF8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80084EFC: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x80084F00: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80084F04: sw          $v1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r3;
    // 0x80084F08: addiu       $t0, $t0, -0x8
    ctx->r8 = ADD32(ctx->r8, -0X8);
    // 0x80084F0C: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x80084F10: slt         $v0, $a3, $t1
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80084F14: beq         $v0, $zero, L_80084EF8
    if (ctx->r2 == 0) {
        // 0x80084F18: addiu       $a2, $a2, -0x8
        ctx->r6 = ADD32(ctx->r6, -0X8);
            goto L_80084EF8;
    }
    // 0x80084F18: addiu       $a2, $a2, -0x8
    ctx->r6 = ADD32(ctx->r6, -0X8);
L_80084F1C:
    // 0x80084F1C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80084F20: lw          $v0, -0x50F8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X50F8);
    // 0x80084F24: j           L_80084F50
    // 0x80084F28: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_80084F50;
    // 0x80084F28: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80084F2C:
    // 0x80084F2C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80084F30: lw          $v1, -0x50F8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X50F8);
L_80084F34:
    // 0x80084F34: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80084F38: bne         $v0, $zero, L_80084F50
    if (ctx->r2 != 0) {
        // 0x80084F3C: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_80084F50;
    }
    // 0x80084F3C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_80084F40:
    // 0x80084F40: jal         0x8009205C
    // 0x80084F44: nop

    factor5MutexRelease(rdram, ctx);
        goto after_1;
    // 0x80084F44: nop

    after_1:
    // 0x80084F48: j           L_80084F8C
    // 0x80084F4C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80084F8C;
    // 0x80084F4C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80084F50:
    // 0x80084F50: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80084F54: sw          $v0, -0x50F8($at)
    MEM_W(-0X50F8, ctx->r1) = ctx->r2;
    // 0x80084F58: sll         $v0, $t1, 3
    ctx->r2 = S32(ctx->r9 << 3);
    // 0x80084F5C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80084F60: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80084F64: sh          $s0, -0x7BAC($at)
    MEM_H(-0X7BAC, ctx->r1) = ctx->r16;
    // 0x80084F68: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80084F6C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80084F70: sw          $s1, -0x7BB0($at)
    MEM_W(-0X7BB0, ctx->r1) = ctx->r17;
    // 0x80084F74: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80084F78: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80084F7C: sh          $s2, -0x7BAA($at)
    MEM_H(-0X7BAA, ctx->r1) = ctx->r18;
    // 0x80084F80: jal         0x8009205C
    // 0x80084F84: nop

    factor5MutexRelease(rdram, ctx);
        goto after_2;
    // 0x80084F84: nop

    after_2:
    // 0x80084F88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80084F8C:
    // 0x80084F8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80084F90: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80084F94: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80084F98: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80084F9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80084FA0: jr          $ra
    // 0x80084FA4: nop

    return;
    // 0x80084FA4: nop

;}
RECOMP_FUNC void func_80084FA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084FA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80084FAC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80084FB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80084FB4: jal         0x80092010
    // 0x80084FB8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    factor5MutexAcquire(rdram, ctx);
        goto after_0;
    // 0x80084FB8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80084FBC: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80084FC0: lw          $a2, -0x50F8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X50F8);
    // 0x80084FC4: blez        $a2, L_80084FF8
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80084FC8: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80084FF8;
    }
    // 0x80084FC8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80084FCC: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x80084FD0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80084FD4:
    // 0x80084FD4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80084FD8: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x80084FDC: lhu         $v0, -0x7BAC($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X7BAC);
    // 0x80084FE0: beq         $v0, $a0, L_80084FF8
    if (ctx->r2 == ctx->r4) {
        // 0x80084FE4: nop
    
            goto L_80084FF8;
    }
    // 0x80084FE4: nop

    // 0x80084FE8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80084FEC: slt         $v0, $v1, $a2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80084FF0: bne         $v0, $zero, L_80084FD4
    if (ctx->r2 != 0) {
        // 0x80084FF4: addiu       $a1, $a1, 0x8
        ctx->r5 = ADD32(ctx->r5, 0X8);
            goto L_80084FD4;
    }
    // 0x80084FF4: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
L_80084FF8:
    // 0x80084FF8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80084FFC: lw          $v0, -0x50F8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X50F8);
    // 0x80085000: beq         $v1, $v0, L_80085078
    if (ctx->r3 == ctx->r2) {
        // 0x80085004: addiu       $a2, $v1, 0x1
        ctx->r6 = ADD32(ctx->r3, 0X1);
            goto L_80085078;
    }
    // 0x80085004: addiu       $a2, $v1, 0x1
    ctx->r6 = ADD32(ctx->r3, 0X1);
    // 0x80085008: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008500C: beq         $v0, $zero, L_80085054
    if (ctx->r2 == 0) {
        // 0x80085010: sll         $v1, $a2, 3
        ctx->r3 = S32(ctx->r6 << 3);
            goto L_80085054;
    }
    // 0x80085010: sll         $v1, $a2, 3
    ctx->r3 = S32(ctx->r6 << 3);
    // 0x80085014: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80085018: addiu       $v0, $v0, -0x7BB8
    ctx->r2 = ADD32(ctx->r2, -0X7BB8);
    // 0x8008501C: addu        $t0, $v1, $v0
    ctx->r8 = ADD32(ctx->r3, ctx->r2);
    // 0x80085020: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80085024: addu        $a3, $v1, $v0
    ctx->r7 = ADD32(ctx->r3, ctx->r2);
L_80085028:
    // 0x80085028: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8008502C: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
    // 0x80085030: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80085034: sw          $v1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r3;
    // 0x80085038: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8008503C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80085040: lw          $v0, -0x50F8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X50F8);
    // 0x80085044: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80085048: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008504C: bne         $v0, $zero, L_80085028
    if (ctx->r2 != 0) {
        // 0x80085050: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_80085028;
    }
    // 0x80085050: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
L_80085054:
    // 0x80085054: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80085058: lw          $v0, -0x50F8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X50F8);
    // 0x8008505C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80085060: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085064: sw          $v0, -0x50F8($at)
    MEM_W(-0X50F8, ctx->r1) = ctx->r2;
    // 0x80085068: jal         0x8009205C
    // 0x8008506C: nop

    factor5MutexRelease(rdram, ctx);
        goto after_1;
    // 0x8008506C: nop

    after_1:
    // 0x80085070: j           L_80085084
    // 0x80085074: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80085084;
    // 0x80085074: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80085078:
    // 0x80085078: jal         0x8009205C
    // 0x8008507C: nop

    factor5MutexRelease(rdram, ctx);
        goto after_2;
    // 0x8008507C: nop

    after_2:
    // 0x80085080: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80085084:
    // 0x80085084: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80085088: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008508C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80085090: jr          $ra
    // 0x80085094: nop

    return;
    // 0x80085094: nop

;}
RECOMP_FUNC void func_80085098(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085098: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008509C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800850A0: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800850A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800850A8: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800850AC: jal         0x80092010
    // 0x800850B0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    factor5MutexAcquire(rdram, ctx);
        goto after_0;
    // 0x800850B0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x800850B4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800850B8: lw          $a0, -0x50F4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X50F4);
    // 0x800850BC: blez        $a0, L_80085178
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800850C0: addu        $t1, $zero, $zero
        ctx->r9 = ADD32(0, 0);
            goto L_80085178;
    }
    // 0x800850C0: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x800850C4: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    // 0x800850C8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800850CC:
    // 0x800850CC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800850D0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800850D4: lhu         $v0, -0x7394($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X7394);
    // 0x800850D8: sltu        $v0, $v0, $a1
    ctx->r2 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x800850DC: beq         $v0, $zero, L_800850F4
    if (ctx->r2 == 0) {
        // 0x800850E0: nop
    
            goto L_800850F4;
    }
    // 0x800850E0: nop

    // 0x800850E4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800850E8: slt         $v0, $t1, $a0
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800850EC: bne         $v0, $zero, L_800850CC
    if (ctx->r2 != 0) {
        // 0x800850F0: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_800850CC;
    }
    // 0x800850F0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_800850F4:
    // 0x800850F4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800850F8: lw          $v1, -0x50F4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X50F4);
    // 0x800850FC: slt         $v0, $t1, $v1
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80085100: beq         $v0, $zero, L_80085180
    if (ctx->r2 == 0) {
        // 0x80085104: sll         $v0, $t1, 3
        ctx->r2 = S32(ctx->r9 << 3);
            goto L_80085180;
    }
    // 0x80085104: sll         $v0, $t1, 3
    ctx->r2 = S32(ctx->r9 << 3);
    // 0x80085108: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008510C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80085110: lhu         $v0, -0x7394($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X7394);
    // 0x80085114: beq         $v0, $a1, L_8008518C
    if (ctx->r2 == ctx->r5) {
        // 0x80085118: slti        $v0, $v1, 0x100
        ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
            goto L_8008518C;
    }
    // 0x80085118: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x8008511C: beq         $v0, $zero, L_8008518C
    if (ctx->r2 == 0) {
        // 0x80085120: addiu       $a3, $v1, -0x1
        ctx->r7 = ADD32(ctx->r3, -0X1);
            goto L_8008518C;
    }
    // 0x80085120: addiu       $a3, $v1, -0x1
    ctx->r7 = ADD32(ctx->r3, -0X1);
    // 0x80085124: slt         $v0, $a3, $t1
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80085128: bne         $v0, $zero, L_80085168
    if (ctx->r2 != 0) {
        // 0x8008512C: sll         $v1, $a3, 3
        ctx->r3 = S32(ctx->r7 << 3);
            goto L_80085168;
    }
    // 0x8008512C: sll         $v1, $a3, 3
    ctx->r3 = S32(ctx->r7 << 3);
    // 0x80085130: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80085134: addiu       $v0, $v0, -0x7390
    ctx->r2 = ADD32(ctx->r2, -0X7390);
    // 0x80085138: addu        $t0, $v1, $v0
    ctx->r8 = ADD32(ctx->r3, ctx->r2);
    // 0x8008513C: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // 0x80085140: addu        $a2, $v1, $v0
    ctx->r6 = ADD32(ctx->r3, ctx->r2);
L_80085144:
    // 0x80085144: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80085148: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8008514C: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80085150: sw          $v1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r3;
    // 0x80085154: addiu       $t0, $t0, -0x8
    ctx->r8 = ADD32(ctx->r8, -0X8);
    // 0x80085158: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x8008515C: slt         $v0, $a3, $t1
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80085160: beq         $v0, $zero, L_80085144
    if (ctx->r2 == 0) {
        // 0x80085164: addiu       $a2, $a2, -0x8
        ctx->r6 = ADD32(ctx->r6, -0X8);
            goto L_80085144;
    }
    // 0x80085164: addiu       $a2, $a2, -0x8
    ctx->r6 = ADD32(ctx->r6, -0X8);
L_80085168:
    // 0x80085168: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008516C: lw          $v0, -0x50F4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X50F4);
    // 0x80085170: j           L_8008519C
    // 0x80085174: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_8008519C;
    // 0x80085174: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80085178:
    // 0x80085178: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8008517C: lw          $v1, -0x50F4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X50F4);
L_80085180:
    // 0x80085180: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80085184: bne         $v0, $zero, L_8008519C
    if (ctx->r2 != 0) {
        // 0x80085188: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8008519C;
    }
    // 0x80085188: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_8008518C:
    // 0x8008518C: jal         0x8009205C
    // 0x80085190: nop

    factor5MutexRelease(rdram, ctx);
        goto after_1;
    // 0x80085190: nop

    after_1:
    // 0x80085194: j           L_800851CC
    // 0x80085198: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800851CC;
    // 0x80085198: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8008519C:
    // 0x8008519C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800851A0: sw          $v0, -0x50F4($at)
    MEM_W(-0X50F4, ctx->r1) = ctx->r2;
    // 0x800851A4: sll         $v0, $t1, 3
    ctx->r2 = S32(ctx->r9 << 3);
    // 0x800851A8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800851AC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800851B0: sh          $s0, -0x7394($at)
    MEM_H(-0X7394, ctx->r1) = ctx->r16;
    // 0x800851B4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800851B8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800851BC: sw          $s1, -0x7398($at)
    MEM_W(-0X7398, ctx->r1) = ctx->r17;
    // 0x800851C0: jal         0x8009205C
    // 0x800851C4: nop

    factor5MutexRelease(rdram, ctx);
        goto after_2;
    // 0x800851C4: nop

    after_2:
    // 0x800851C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800851CC:
    // 0x800851CC: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800851D0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800851D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800851D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800851DC: jr          $ra
    // 0x800851E0: nop

    return;
    // 0x800851E0: nop

;}
RECOMP_FUNC void func_800851E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800851E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800851E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800851EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800851F0: jal         0x80092010
    // 0x800851F4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    factor5MutexAcquire(rdram, ctx);
        goto after_0;
    // 0x800851F4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x800851F8: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800851FC: lw          $a2, -0x50F4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X50F4);
    // 0x80085200: blez        $a2, L_80085234
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80085204: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80085234;
    }
    // 0x80085204: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80085208: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x8008520C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80085210:
    // 0x80085210: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80085214: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x80085218: lhu         $v0, -0x7394($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X7394);
    // 0x8008521C: beq         $v0, $a0, L_80085234
    if (ctx->r2 == ctx->r4) {
        // 0x80085220: nop
    
            goto L_80085234;
    }
    // 0x80085220: nop

    // 0x80085224: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80085228: slt         $v0, $v1, $a2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8008522C: bne         $v0, $zero, L_80085210
    if (ctx->r2 != 0) {
        // 0x80085230: addiu       $a1, $a1, 0x8
        ctx->r5 = ADD32(ctx->r5, 0X8);
            goto L_80085210;
    }
    // 0x80085230: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
L_80085234:
    // 0x80085234: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80085238: lw          $v0, -0x50F4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X50F4);
    // 0x8008523C: beq         $v1, $v0, L_800852B4
    if (ctx->r3 == ctx->r2) {
        // 0x80085240: addiu       $a2, $v1, 0x1
        ctx->r6 = ADD32(ctx->r3, 0X1);
            goto L_800852B4;
    }
    // 0x80085240: addiu       $a2, $v1, 0x1
    ctx->r6 = ADD32(ctx->r3, 0X1);
    // 0x80085244: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80085248: beq         $v0, $zero, L_80085290
    if (ctx->r2 == 0) {
        // 0x8008524C: sll         $v1, $a2, 3
        ctx->r3 = S32(ctx->r6 << 3);
            goto L_80085290;
    }
    // 0x8008524C: sll         $v1, $a2, 3
    ctx->r3 = S32(ctx->r6 << 3);
    // 0x80085250: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80085254: addiu       $v0, $v0, -0x73A0
    ctx->r2 = ADD32(ctx->r2, -0X73A0);
    // 0x80085258: addu        $t0, $v1, $v0
    ctx->r8 = ADD32(ctx->r3, ctx->r2);
    // 0x8008525C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80085260: addu        $a3, $v1, $v0
    ctx->r7 = ADD32(ctx->r3, ctx->r2);
L_80085264:
    // 0x80085264: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80085268: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
    // 0x8008526C: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80085270: sw          $v1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r3;
    // 0x80085274: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80085278: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008527C: lw          $v0, -0x50F4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X50F4);
    // 0x80085280: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80085284: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80085288: bne         $v0, $zero, L_80085264
    if (ctx->r2 != 0) {
        // 0x8008528C: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_80085264;
    }
    // 0x8008528C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
L_80085290:
    // 0x80085290: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80085294: lw          $v0, -0x50F4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X50F4);
    // 0x80085298: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8008529C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800852A0: sw          $v0, -0x50F4($at)
    MEM_W(-0X50F4, ctx->r1) = ctx->r2;
    // 0x800852A4: jal         0x8009205C
    // 0x800852A8: nop

    factor5MutexRelease(rdram, ctx);
        goto after_1;
    // 0x800852A8: nop

    after_1:
    // 0x800852AC: j           L_800852C0
    // 0x800852B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800852C0;
    // 0x800852B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800852B4:
    // 0x800852B4: jal         0x8009205C
    // 0x800852B8: nop

    factor5MutexRelease(rdram, ctx);
        goto after_2;
    // 0x800852B8: nop

    after_2:
    // 0x800852BC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800852C0:
    // 0x800852C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800852C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800852C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800852CC: jr          $ra
    // 0x800852D0: nop

    return;
    // 0x800852D0: nop

;}
RECOMP_FUNC void func_800852D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800852D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800852D8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800852DC: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800852E0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800852E4: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x800852E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800852EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800852F0: jal         0x80092010
    // 0x800852F4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    factor5MutexAcquire(rdram, ctx);
        goto after_0;
    // 0x800852F4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x800852F8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800852FC: lw          $a0, -0x3BB4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3BB4);
    // 0x80085300: blez        $a0, L_800853D8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80085304: addu        $t1, $zero, $zero
        ctx->r9 = ADD32(0, 0);
            goto L_800853D8;
    }
    // 0x80085304: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x80085308: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    // 0x8008530C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80085310:
    // 0x80085310: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085314: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80085318: lhu         $v0, -0x4FB0($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X4FB0);
    // 0x8008531C: sltu        $v0, $v0, $a1
    ctx->r2 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x80085320: beq         $v0, $zero, L_80085338
    if (ctx->r2 == 0) {
        // 0x80085324: nop
    
            goto L_80085338;
    }
    // 0x80085324: nop

    // 0x80085328: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8008532C: slt         $v0, $t1, $a0
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80085330: bne         $v0, $zero, L_80085310
    if (ctx->r2 != 0) {
        // 0x80085334: addiu       $v1, $v1, 0xC
        ctx->r3 = ADD32(ctx->r3, 0XC);
            goto L_80085310;
    }
    // 0x80085334: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
L_80085338:
    // 0x80085338: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8008533C: lw          $v1, -0x3BB4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3BB4);
    // 0x80085340: slt         $v0, $t1, $v1
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80085344: beq         $v0, $zero, L_800853E0
    if (ctx->r2 == 0) {
        // 0x80085348: sll         $v0, $t1, 1
        ctx->r2 = S32(ctx->r9 << 1);
            goto L_800853E0;
    }
    // 0x80085348: sll         $v0, $t1, 1
    ctx->r2 = S32(ctx->r9 << 1);
    // 0x8008534C: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80085350: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80085354: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085358: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8008535C: lhu         $v0, -0x4FB0($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X4FB0);
    // 0x80085360: beq         $v0, $a1, L_800853EC
    if (ctx->r2 == ctx->r5) {
        // 0x80085364: slti        $v0, $v1, 0x100
        ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
            goto L_800853EC;
    }
    // 0x80085364: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80085368: beq         $v0, $zero, L_800853EC
    if (ctx->r2 == 0) {
        // 0x8008536C: addiu       $a3, $v1, -0x1
        ctx->r7 = ADD32(ctx->r3, -0X1);
            goto L_800853EC;
    }
    // 0x8008536C: addiu       $a3, $v1, -0x1
    ctx->r7 = ADD32(ctx->r3, -0X1);
    // 0x80085370: slt         $v0, $a3, $t1
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80085374: bne         $v0, $zero, L_800853C8
    if (ctx->r2 != 0) {
        // 0x80085378: nop
    
            goto L_800853C8;
    }
    // 0x80085378: nop

    // 0x8008537C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80085380: addiu       $v1, $v1, -0x4FAC
    ctx->r3 = ADD32(ctx->r3, -0X4FAC);
    // 0x80085384: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x80085388: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8008538C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80085390: addu        $t0, $v0, $v1
    ctx->r8 = ADD32(ctx->r2, ctx->r3);
    // 0x80085394: addiu       $v1, $v1, -0xC
    ctx->r3 = ADD32(ctx->r3, -0XC);
    // 0x80085398: addu        $a2, $v0, $v1
    ctx->r6 = ADD32(ctx->r2, ctx->r3);
L_8008539C:
    // 0x8008539C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800853A0: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x800853A4: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x800853A8: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x800853AC: sw          $v1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r3;
    // 0x800853B0: sw          $a0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r4;
    // 0x800853B4: addiu       $t0, $t0, -0xC
    ctx->r8 = ADD32(ctx->r8, -0XC);
    // 0x800853B8: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x800853BC: slt         $v0, $a3, $t1
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800853C0: beq         $v0, $zero, L_8008539C
    if (ctx->r2 == 0) {
        // 0x800853C4: addiu       $a2, $a2, -0xC
        ctx->r6 = ADD32(ctx->r6, -0XC);
            goto L_8008539C;
    }
    // 0x800853C4: addiu       $a2, $a2, -0xC
    ctx->r6 = ADD32(ctx->r6, -0XC);
L_800853C8:
    // 0x800853C8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800853CC: lw          $v0, -0x3BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3BB4);
    // 0x800853D0: j           L_800853FC
    // 0x800853D4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_800853FC;
    // 0x800853D4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800853D8:
    // 0x800853D8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800853DC: lw          $v1, -0x3BB4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3BB4);
L_800853E0:
    // 0x800853E0: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x800853E4: bne         $v0, $zero, L_800853FC
    if (ctx->r2 != 0) {
        // 0x800853E8: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_800853FC;
    }
    // 0x800853E8: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_800853EC:
    // 0x800853EC: jal         0x8009205C
    // 0x800853F0: nop

    factor5MutexRelease(rdram, ctx);
        goto after_1;
    // 0x800853F0: nop

    after_1:
    // 0x800853F4: j           L_80085440
    // 0x800853F8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80085440;
    // 0x800853F8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800853FC:
    // 0x800853FC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085400: sw          $v0, -0x3BB4($at)
    MEM_W(-0X3BB4, ctx->r1) = ctx->r2;
    // 0x80085404: sll         $v0, $t1, 1
    ctx->r2 = S32(ctx->r9 << 1);
    // 0x80085408: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8008540C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80085410: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085414: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80085418: sh          $s0, -0x4FB0($at)
    MEM_H(-0X4FB0, ctx->r1) = ctx->r16;
    // 0x8008541C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085420: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80085424: sw          $s1, -0x4FB8($at)
    MEM_W(-0X4FB8, ctx->r1) = ctx->r17;
    // 0x80085428: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008542C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80085430: sw          $s2, -0x4FB4($at)
    MEM_W(-0X4FB4, ctx->r1) = ctx->r18;
    // 0x80085434: jal         0x8009205C
    // 0x80085438: nop

    factor5MutexRelease(rdram, ctx);
        goto after_2;
    // 0x80085438: nop

    after_2:
    // 0x8008543C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80085440:
    // 0x80085440: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80085444: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80085448: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008544C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80085450: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80085454: jr          $ra
    // 0x80085458: nop

    return;
    // 0x80085458: nop

;}
RECOMP_FUNC void func_8008545C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008545C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80085460: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80085464: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80085468: jal         0x80092010
    // 0x8008546C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    factor5MutexAcquire(rdram, ctx);
        goto after_0;
    // 0x8008546C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80085470: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80085474: lw          $a2, -0x3BB4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X3BB4);
    // 0x80085478: blez        $a2, L_800854AC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008547C: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800854AC;
    }
    // 0x8008547C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80085480: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x80085484: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80085488:
    // 0x80085488: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008548C: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x80085490: lhu         $v0, -0x4FB0($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X4FB0);
    // 0x80085494: beq         $v0, $a0, L_800854AC
    if (ctx->r2 == ctx->r4) {
        // 0x80085498: nop
    
            goto L_800854AC;
    }
    // 0x80085498: nop

    // 0x8008549C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800854A0: slt         $v0, $v1, $a2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800854A4: bne         $v0, $zero, L_80085488
    if (ctx->r2 != 0) {
        // 0x800854A8: addiu       $a1, $a1, 0xC
        ctx->r5 = ADD32(ctx->r5, 0XC);
            goto L_80085488;
    }
    // 0x800854A8: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
L_800854AC:
    // 0x800854AC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800854B0: lw          $v0, -0x3BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3BB4);
    // 0x800854B4: beq         $v1, $v0, L_80085540
    if (ctx->r3 == ctx->r2) {
        // 0x800854B8: addiu       $a2, $v1, 0x1
        ctx->r6 = ADD32(ctx->r3, 0X1);
            goto L_80085540;
    }
    // 0x800854B8: addiu       $a2, $v1, 0x1
    ctx->r6 = ADD32(ctx->r3, 0X1);
    // 0x800854BC: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800854C0: beq         $v0, $zero, L_8008551C
    if (ctx->r2 == 0) {
        // 0x800854C4: nop
    
            goto L_8008551C;
    }
    // 0x800854C4: nop

    // 0x800854C8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800854CC: addiu       $v1, $v1, -0x4FC4
    ctx->r3 = ADD32(ctx->r3, -0X4FC4);
    // 0x800854D0: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800854D4: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800854D8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800854DC: addu        $t0, $v0, $v1
    ctx->r8 = ADD32(ctx->r2, ctx->r3);
    // 0x800854E0: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x800854E4: addu        $a3, $v0, $v1
    ctx->r7 = ADD32(ctx->r2, ctx->r3);
L_800854E8:
    // 0x800854E8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800854EC: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
    // 0x800854F0: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    // 0x800854F4: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x800854F8: sw          $v1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r3;
    // 0x800854FC: sw          $a0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r4;
    // 0x80085500: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80085504: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80085508: lw          $v0, -0x3BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3BB4);
    // 0x8008550C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80085510: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80085514: bne         $v0, $zero, L_800854E8
    if (ctx->r2 != 0) {
        // 0x80085518: addiu       $a3, $a3, 0xC
        ctx->r7 = ADD32(ctx->r7, 0XC);
            goto L_800854E8;
    }
    // 0x80085518: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
L_8008551C:
    // 0x8008551C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80085520: lw          $v0, -0x3BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3BB4);
    // 0x80085524: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80085528: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008552C: sw          $v0, -0x3BB4($at)
    MEM_W(-0X3BB4, ctx->r1) = ctx->r2;
    // 0x80085530: jal         0x8009205C
    // 0x80085534: nop

    factor5MutexRelease(rdram, ctx);
        goto after_1;
    // 0x80085534: nop

    after_1:
    // 0x80085538: j           L_8008554C
    // 0x8008553C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008554C;
    // 0x8008553C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80085540:
    // 0x80085540: jal         0x8009205C
    // 0x80085544: nop

    factor5MutexRelease(rdram, ctx);
        goto after_2;
    // 0x80085544: nop

    after_2:
    // 0x80085548: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8008554C:
    // 0x8008554C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80085550: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80085554: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80085558: jr          $ra
    // 0x8008555C: nop

    return;
    // 0x8008555C: nop

;}
RECOMP_FUNC void func_80085560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085560: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80085564: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80085568: lbu         $s4, 0x4B($sp)
    ctx->r20 = MEM_BU(ctx->r29, 0X4B);
    // 0x8008556C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80085570: lbu         $s5, 0x4F($sp)
    ctx->r21 = MEM_BU(ctx->r29, 0X4F);
    // 0x80085574: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80085578: lbu         $s6, 0x53($sp)
    ctx->r22 = MEM_BU(ctx->r29, 0X53);
    // 0x8008557C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80085580: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80085584: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80085588: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x8008558C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80085590: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x80085594: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80085598: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8008559C: jal         0x80092010
    // 0x800855A0: addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    factor5MutexAcquire(rdram, ctx);
        goto after_0;
    // 0x800855A0: addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    after_0:
    // 0x800855A4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800855A8: lw          $a0, 0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X800);
    // 0x800855AC: blez        $a0, L_8008569C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800855B0: addu        $t1, $zero, $zero
        ctx->r9 = ADD32(0, 0);
            goto L_8008569C;
    }
    // 0x800855B0: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x800855B4: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    // 0x800855B8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800855BC:
    // 0x800855BC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800855C0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800855C4: lhu         $v0, -0x3380($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X3380);
    // 0x800855C8: sltu        $v0, $v0, $a1
    ctx->r2 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x800855CC: beq         $v0, $zero, L_800855E4
    if (ctx->r2 == 0) {
        // 0x800855D0: nop
    
            goto L_800855E4;
    }
    // 0x800855D0: nop

    // 0x800855D4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800855D8: slt         $v0, $t1, $a0
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800855DC: bne         $v0, $zero, L_800855BC
    if (ctx->r2 != 0) {
        // 0x800855E0: addiu       $v1, $v1, 0xC
        ctx->r3 = ADD32(ctx->r3, 0XC);
            goto L_800855BC;
    }
    // 0x800855E0: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
L_800855E4:
    // 0x800855E4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800855E8: lw          $v1, 0x800($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X800);
    // 0x800855EC: slt         $v0, $t1, $v1
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800855F0: beq         $v0, $zero, L_800856A4
    if (ctx->r2 == 0) {
        // 0x800855F4: sll         $v0, $t1, 1
        ctx->r2 = S32(ctx->r9 << 1);
            goto L_800856A4;
    }
    // 0x800855F4: sll         $v0, $t1, 1
    ctx->r2 = S32(ctx->r9 << 1);
    // 0x800855F8: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800855FC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80085600: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085604: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80085608: lhu         $v0, -0x3380($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X3380);
    // 0x8008560C: beq         $v0, $a1, L_800856C8
    if (ctx->r2 == ctx->r5) {
        // 0x80085610: slti        $v0, $v1, 0x100
        ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
            goto L_800856C8;
    }
    // 0x80085610: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80085614: beq         $v0, $zero, L_800856B0
    if (ctx->r2 == 0) {
        // 0x80085618: addiu       $a3, $v1, -0x1
        ctx->r7 = ADD32(ctx->r3, -0X1);
            goto L_800856B0;
    }
    // 0x80085618: addiu       $a3, $v1, -0x1
    ctx->r7 = ADD32(ctx->r3, -0X1);
    // 0x8008561C: slt         $v0, $a3, $t1
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80085620: bne         $v0, $zero, L_8008568C
    if (ctx->r2 != 0) {
        // 0x80085624: nop
    
            goto L_8008568C;
    }
    // 0x80085624: nop

    // 0x80085628: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8008562C: addiu       $v1, $v1, -0x3374
    ctx->r3 = ADD32(ctx->r3, -0X3374);
    // 0x80085630: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x80085634: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80085638: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008563C: addu        $t0, $v0, $v1
    ctx->r8 = ADD32(ctx->r2, ctx->r3);
    // 0x80085640: addiu       $v1, $v1, -0xC
    ctx->r3 = ADD32(ctx->r3, -0XC);
    // 0x80085644: addu        $a2, $v0, $v1
    ctx->r6 = ADD32(ctx->r2, ctx->r3);
L_80085648:
    // 0x80085648: lwl         $v0, 0x0($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r6, 0X0);
    // 0x8008564C: lwr         $v0, 0x3($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r6, 0X3);
    // 0x80085650: lwl         $v1, 0x4($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r6, 0X4);
    // 0x80085654: lwr         $v1, 0x7($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r6, 0X7);
    // 0x80085658: lwl         $a0, 0x8($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r6, 0X8);
    // 0x8008565C: lwr         $a0, 0xB($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r6, 0XB);
    // 0x80085660: swl         $v0, 0x0($t0)
    do_swl(rdram, 0X0, ctx->r8, ctx->r2);
    // 0x80085664: swr         $v0, 0x3($t0)
    do_swr(rdram, 0X3, ctx->r8, ctx->r2);
    // 0x80085668: swl         $v1, 0x4($t0)
    do_swl(rdram, 0X4, ctx->r8, ctx->r3);
    // 0x8008566C: swr         $v1, 0x7($t0)
    do_swr(rdram, 0X7, ctx->r8, ctx->r3);
    // 0x80085670: swl         $a0, 0x8($t0)
    do_swl(rdram, 0X8, ctx->r8, ctx->r4);
    // 0x80085674: swr         $a0, 0xB($t0)
    do_swr(rdram, 0XB, ctx->r8, ctx->r4);
    // 0x80085678: addiu       $t0, $t0, -0xC
    ctx->r8 = ADD32(ctx->r8, -0XC);
    // 0x8008567C: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x80085680: slt         $v0, $a3, $t1
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80085684: beq         $v0, $zero, L_80085648
    if (ctx->r2 == 0) {
        // 0x80085688: addiu       $a2, $a2, -0xC
        ctx->r6 = ADD32(ctx->r6, -0XC);
            goto L_80085648;
    }
    // 0x80085688: addiu       $a2, $a2, -0xC
    ctx->r6 = ADD32(ctx->r6, -0XC);
L_8008568C:
    // 0x8008568C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80085690: lw          $v0, 0x800($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X800);
    // 0x80085694: j           L_800856C0
    // 0x80085698: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_800856C0;
    // 0x80085698: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8008569C:
    // 0x8008569C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800856A0: lw          $v1, 0x800($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X800);
L_800856A4:
    // 0x800856A4: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x800856A8: bne         $v0, $zero, L_800856C0
    if (ctx->r2 != 0) {
        // 0x800856AC: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_800856C0;
    }
    // 0x800856AC: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_800856B0:
    // 0x800856B0: jal         0x8009205C
    // 0x800856B4: nop

    factor5MutexRelease(rdram, ctx);
        goto after_1;
    // 0x800856B4: nop

    after_1:
    // 0x800856B8: j           L_80085744
    // 0x800856BC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80085744;
    // 0x800856BC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800856C0:
    // 0x800856C0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800856C4: sw          $v0, 0x800($at)
    MEM_W(0X800, ctx->r1) = ctx->r2;
L_800856C8:
    // 0x800856C8: sll         $v0, $t1, 1
    ctx->r2 = S32(ctx->r9 << 1);
    // 0x800856CC: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800856D0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800856D4: addiu       $v1, $zero, 0x1F
    ctx->r3 = ADD32(0, 0X1F);
    // 0x800856D8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800856DC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800856E0: sh          $s0, -0x3380($at)
    MEM_H(-0X3380, ctx->r1) = ctx->r16;
    // 0x800856E4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800856E8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800856EC: sh          $s1, -0x337E($at)
    MEM_H(-0X337E, ctx->r1) = ctx->r17;
    // 0x800856F0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800856F4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800856F8: sb          $s2, -0x3379($at)
    MEM_B(-0X3379, ctx->r1) = ctx->r18;
    // 0x800856FC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085700: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80085704: sb          $s3, -0x337A($at)
    MEM_B(-0X337A, ctx->r1) = ctx->r19;
    // 0x80085708: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008570C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80085710: sb          $s4, -0x337B($at)
    MEM_B(-0X337B, ctx->r1) = ctx->r20;
    // 0x80085714: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085718: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8008571C: sb          $s5, -0x337C($at)
    MEM_B(-0X337C, ctx->r1) = ctx->r21;
    // 0x80085720: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085724: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80085728: sb          $s6, -0x3378($at)
    MEM_B(-0X3378, ctx->r1) = ctx->r22;
    // 0x8008572C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085730: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80085734: sb          $v1, -0x3377($at)
    MEM_B(-0X3377, ctx->r1) = ctx->r3;
    // 0x80085738: jal         0x8009205C
    // 0x8008573C: nop

    factor5MutexRelease(rdram, ctx);
        goto after_2;
    // 0x8008573C: nop

    after_2:
    // 0x80085740: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80085744:
    // 0x80085744: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80085748: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8008574C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80085750: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80085754: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80085758: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008575C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80085760: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80085764: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80085768: jr          $ra
    // 0x8008576C: nop

    return;
    // 0x8008576C: nop

;}
RECOMP_FUNC void func_80085770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085770: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80085774: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80085778: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008577C: jal         0x80092010
    // 0x80085780: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    factor5MutexAcquire(rdram, ctx);
        goto after_0;
    // 0x80085780: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80085784: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80085788: lw          $a2, 0x800($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X800);
    // 0x8008578C: blez        $a2, L_800857C0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80085790: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800857C0;
    }
    // 0x80085790: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80085794: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x80085798: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8008579C:
    // 0x8008579C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800857A0: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x800857A4: lhu         $v0, -0x3380($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X3380);
    // 0x800857A8: beq         $v0, $a0, L_800857C0
    if (ctx->r2 == ctx->r4) {
        // 0x800857AC: nop
    
            goto L_800857C0;
    }
    // 0x800857AC: nop

    // 0x800857B0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800857B4: slt         $v0, $v1, $a2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800857B8: bne         $v0, $zero, L_8008579C
    if (ctx->r2 != 0) {
        // 0x800857BC: addiu       $a1, $a1, 0xC
        ctx->r5 = ADD32(ctx->r5, 0XC);
            goto L_8008579C;
    }
    // 0x800857BC: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
L_800857C0:
    // 0x800857C0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800857C4: lw          $v0, 0x800($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X800);
    // 0x800857C8: beq         $v1, $v0, L_8008586C
    if (ctx->r3 == ctx->r2) {
        // 0x800857CC: addiu       $a2, $v1, 0x1
        ctx->r6 = ADD32(ctx->r3, 0X1);
            goto L_8008586C;
    }
    // 0x800857CC: addiu       $a2, $v1, 0x1
    ctx->r6 = ADD32(ctx->r3, 0X1);
    // 0x800857D0: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800857D4: beq         $v0, $zero, L_80085848
    if (ctx->r2 == 0) {
        // 0x800857D8: nop
    
            goto L_80085848;
    }
    // 0x800857D8: nop

    // 0x800857DC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800857E0: addiu       $v1, $v1, -0x338C
    ctx->r3 = ADD32(ctx->r3, -0X338C);
    // 0x800857E4: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800857E8: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800857EC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800857F0: addu        $t0, $v0, $v1
    ctx->r8 = ADD32(ctx->r2, ctx->r3);
    // 0x800857F4: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x800857F8: addu        $a3, $v0, $v1
    ctx->r7 = ADD32(ctx->r2, ctx->r3);
L_800857FC:
    // 0x800857FC: lwl         $v0, 0x0($a3)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r7, 0X0);
    // 0x80085800: lwr         $v0, 0x3($a3)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r7, 0X3);
    // 0x80085804: lwl         $v1, 0x4($a3)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r7, 0X4);
    // 0x80085808: lwr         $v1, 0x7($a3)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r7, 0X7);
    // 0x8008580C: lwl         $a0, 0x8($a3)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r7, 0X8);
    // 0x80085810: lwr         $a0, 0xB($a3)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r7, 0XB);
    // 0x80085814: swl         $v0, 0x0($t0)
    do_swl(rdram, 0X0, ctx->r8, ctx->r2);
    // 0x80085818: swr         $v0, 0x3($t0)
    do_swr(rdram, 0X3, ctx->r8, ctx->r2);
    // 0x8008581C: swl         $v1, 0x4($t0)
    do_swl(rdram, 0X4, ctx->r8, ctx->r3);
    // 0x80085820: swr         $v1, 0x7($t0)
    do_swr(rdram, 0X7, ctx->r8, ctx->r3);
    // 0x80085824: swl         $a0, 0x8($t0)
    do_swl(rdram, 0X8, ctx->r8, ctx->r4);
    // 0x80085828: swr         $a0, 0xB($t0)
    do_swr(rdram, 0XB, ctx->r8, ctx->r4);
    // 0x8008582C: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80085830: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80085834: lw          $v0, 0x800($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X800);
    // 0x80085838: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8008583C: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80085840: bne         $v0, $zero, L_800857FC
    if (ctx->r2 != 0) {
        // 0x80085844: addiu       $a3, $a3, 0xC
        ctx->r7 = ADD32(ctx->r7, 0XC);
            goto L_800857FC;
    }
    // 0x80085844: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
L_80085848:
    // 0x80085848: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008584C: lw          $v0, 0x800($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X800);
    // 0x80085850: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80085854: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085858: sw          $v0, 0x800($at)
    MEM_W(0X800, ctx->r1) = ctx->r2;
    // 0x8008585C: jal         0x8009205C
    // 0x80085860: nop

    factor5MutexRelease(rdram, ctx);
        goto after_1;
    // 0x80085860: nop

    after_1:
    // 0x80085864: j           L_80085878
    // 0x80085868: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80085878;
    // 0x80085868: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008586C:
    // 0x8008586C: jal         0x8009205C
    // 0x80085870: nop

    factor5MutexRelease(rdram, ctx);
        goto after_2;
    // 0x80085870: nop

    after_2:
    // 0x80085874: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80085878:
    // 0x80085878: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008587C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80085880: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80085884: jr          $ra
    // 0x80085888: nop

    return;
    // 0x80085888: nop

;}
RECOMP_FUNC void func_8008588C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008588C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80085890: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80085894: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80085898: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008589C: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800858A0: jal         0x80092010
    // 0x800858A4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    factor5MutexAcquire(rdram, ctx);
        goto after_0;
    // 0x800858A4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x800858A8: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x800858AC: srl         $t2, $a0, 6
    ctx->r10 = S32(U32(ctx->r4) >> 6);
    // 0x800858B0: sll         $v1, $t2, 2
    ctx->r3 = S32(ctx->r10 << 2);
    // 0x800858B4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800858B8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800858BC: lhu         $v0, -0x3B80($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X3B80);
    // 0x800858C0: bne         $v0, $zero, L_800858E8
    if (ctx->r2 != 0) {
        // 0x800858C4: nop
    
            goto L_800858E8;
    }
    // 0x800858C4: nop

    // 0x800858C8: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800858CC: lhu         $v0, -0x73AE($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X73AE);
    // 0x800858D0: andi        $t1, $v0, 0xFFFF
    ctx->r9 = ctx->r2 & 0XFFFF;
    // 0x800858D4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800858D8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800858DC: sh          $v0, -0x3B7E($at)
    MEM_H(-0X3B7E, ctx->r1) = ctx->r2;
    // 0x800858E0: j           L_80085974
    // 0x800858E4: addu        $a3, $t1, $zero
    ctx->r7 = ADD32(ctx->r9, 0);
        goto L_80085974;
    // 0x800858E4: addu        $a3, $t1, $zero
    ctx->r7 = ADD32(ctx->r9, 0);
L_800858E8:
    // 0x800858E8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800858EC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800858F0: lhu         $a3, -0x3B7E($at)
    ctx->r7 = MEM_HU(ctx->r1, -0X3B7E);
    // 0x800858F4: beq         $v0, $zero, L_80085970
    if (ctx->r2 == 0) {
        // 0x800858F8: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_80085970;
    }
    // 0x800858F8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800858FC: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80085900: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80085904: addu        $v0, $a3, $a2
    ctx->r2 = ADD32(ctx->r7, ctx->r6);
L_80085908:
    // 0x80085908: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8008590C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085910: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80085914: lhu         $v0, 0x20C4($at)
    ctx->r2 = MEM_HU(ctx->r1, 0X20C4);
    // 0x80085918: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8008591C: beq         $v0, $zero, L_80085938
    if (ctx->r2 == 0) {
        // 0x80085920: sll         $v0, $t2, 2
        ctx->r2 = S32(ctx->r10 << 2);
            goto L_80085938;
    }
    // 0x80085920: sll         $v0, $t2, 2
    ctx->r2 = S32(ctx->r10 << 2);
    // 0x80085924: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80085928: slt         $v0, $a2, $a0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8008592C: bne         $v0, $zero, L_80085908
    if (ctx->r2 != 0) {
        // 0x80085930: addu        $v0, $a3, $a2
        ctx->r2 = ADD32(ctx->r7, ctx->r6);
            goto L_80085908;
    }
    // 0x80085930: addu        $v0, $a3, $a2
    ctx->r2 = ADD32(ctx->r7, ctx->r6);
    // 0x80085934: sll         $v0, $t2, 2
    ctx->r2 = S32(ctx->r10 << 2);
L_80085938:
    // 0x80085938: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008593C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80085940: lhu         $v0, -0x3B80($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X3B80);
    // 0x80085944: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80085948: beq         $v0, $zero, L_80085970
    if (ctx->r2 == 0) {
        // 0x8008594C: addu        $t1, $a3, $a2
        ctx->r9 = ADD32(ctx->r7, ctx->r6);
            goto L_80085970;
    }
    // 0x8008594C: addu        $t1, $a3, $a2
    ctx->r9 = ADD32(ctx->r7, ctx->r6);
    // 0x80085950: sll         $v0, $t1, 3
    ctx->r2 = S32(ctx->r9 << 3);
    // 0x80085954: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085958: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8008595C: lhu         $v0, 0x20C4($at)
    ctx->r2 = MEM_HU(ctx->r1, 0X20C4);
    // 0x80085960: beq         $v0, $v1, L_80085A70
    if (ctx->r2 == ctx->r3) {
        // 0x80085964: nop
    
            goto L_80085A70;
    }
    // 0x80085964: nop

    // 0x80085968: j           L_80085974
    // 0x8008596C: nop

        goto L_80085974;
    // 0x8008596C: nop

L_80085970:
    // 0x80085970: addu        $t1, $a3, $a2
    ctx->r9 = ADD32(ctx->r7, ctx->r6);
L_80085974:
    // 0x80085974: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80085978: lw          $v0, -0x73B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X73B0);
    // 0x8008597C: slti        $v0, $v0, 0x400
    ctx->r2 = SIGNED(ctx->r2) < 0X400 ? 1 : 0;
    // 0x80085980: beq         $v0, $zero, L_80085A70
    if (ctx->r2 == 0) {
        // 0x80085984: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80085A70;
    }
    // 0x80085984: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80085988: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008598C: addiu       $a1, $a1, -0x3B80
    ctx->r5 = ADD32(ctx->r5, -0X3B80);
L_80085990:
    // 0x80085990: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085994: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80085998: lhu         $v1, -0x3B7E($at)
    ctx->r3 = MEM_HU(ctx->r1, -0X3B7E);
    // 0x8008599C: slt         $v0, $a3, $v1
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800859A0: beq         $v0, $zero, L_800859AC
    if (ctx->r2 == 0) {
        // 0x800859A4: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_800859AC;
    }
    // 0x800859A4: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800859A8: sh          $v0, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r2;
L_800859AC:
    // 0x800859AC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800859B0: slti        $v0, $a0, 0x800
    ctx->r2 = SIGNED(ctx->r4) < 0X800 ? 1 : 0;
    // 0x800859B4: bne         $v0, $zero, L_80085990
    if (ctx->r2 != 0) {
        // 0x800859B8: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80085990;
    }
    // 0x800859B8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800859BC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800859C0: lw          $v0, -0x73B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X73B0);
    // 0x800859C4: addiu       $a2, $v0, -0x1
    ctx->r6 = ADD32(ctx->r2, -0X1);
    // 0x800859C8: slt         $v0, $a2, $t1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800859CC: bne         $v0, $zero, L_80085A14
    if (ctx->r2 != 0) {
        // 0x800859D0: sll         $a0, $t1, 3
        ctx->r4 = S32(ctx->r9 << 3);
            goto L_80085A14;
    }
    // 0x800859D0: sll         $a0, $t1, 3
    ctx->r4 = S32(ctx->r9 << 3);
    // 0x800859D4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800859D8: addiu       $v0, $v0, 0x20C8
    ctx->r2 = ADD32(ctx->r2, 0X20C8);
    // 0x800859DC: sll         $v1, $a2, 3
    ctx->r3 = S32(ctx->r6 << 3);
    // 0x800859E0: addu        $t0, $v1, $v0
    ctx->r8 = ADD32(ctx->r3, ctx->r2);
    // 0x800859E4: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // 0x800859E8: addu        $a3, $v1, $v0
    ctx->r7 = ADD32(ctx->r3, ctx->r2);
L_800859EC:
    // 0x800859EC: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800859F0: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
    // 0x800859F4: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x800859F8: sw          $v1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r3;
    // 0x800859FC: addiu       $t0, $t0, -0x8
    ctx->r8 = ADD32(ctx->r8, -0X8);
    // 0x80085A00: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80085A04: slt         $v0, $a2, $t1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80085A08: beq         $v0, $zero, L_800859EC
    if (ctx->r2 == 0) {
        // 0x80085A0C: addiu       $a3, $a3, -0x8
        ctx->r7 = ADD32(ctx->r7, -0X8);
            goto L_800859EC;
    }
    // 0x80085A0C: addiu       $a3, $a3, -0x8
    ctx->r7 = ADD32(ctx->r7, -0X8);
    // 0x80085A10: sll         $a0, $t1, 3
    ctx->r4 = S32(ctx->r9 << 3);
L_80085A14:
    // 0x80085A14: sll         $a1, $t2, 2
    ctx->r5 = S32(ctx->r10 << 2);
    // 0x80085A18: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085A1C: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80085A20: sh          $s0, 0x20C4($at)
    MEM_H(0X20C4, ctx->r1) = ctx->r16;
    // 0x80085A24: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085A28: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x80085A2C: lhu         $v0, -0x3B80($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X3B80);
    // 0x80085A30: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80085A34: lw          $v1, -0x73B0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X73B0);
    // 0x80085A38: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085A3C: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80085A40: sw          $s1, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r17;
    // 0x80085A44: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80085A48: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80085A4C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085A50: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x80085A54: sh          $v0, -0x3B80($at)
    MEM_H(-0X3B80, ctx->r1) = ctx->r2;
    // 0x80085A58: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80085A5C: sw          $v1, -0x73B0($at)
    MEM_W(-0X73B0, ctx->r1) = ctx->r3;
    // 0x80085A60: jal         0x8009205C
    // 0x80085A64: nop

    factor5MutexRelease(rdram, ctx);
        goto after_1;
    // 0x80085A64: nop

    after_1:
    // 0x80085A68: j           L_80085A7C
    // 0x80085A6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80085A7C;
    // 0x80085A6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80085A70:
    // 0x80085A70: jal         0x8009205C
    // 0x80085A74: nop

    factor5MutexRelease(rdram, ctx);
        goto after_2;
    // 0x80085A74: nop

    after_2:
    // 0x80085A78: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80085A7C:
    // 0x80085A7C: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80085A80: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80085A84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80085A88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80085A8C: jr          $ra
    // 0x80085A90: nop

    return;
    // 0x80085A90: nop

;}
RECOMP_FUNC void func_80085A94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085A94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80085A98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80085A9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80085AA0: jal         0x80092010
    // 0x80085AA4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    factor5MutexAcquire(rdram, ctx);
        goto after_0;
    // 0x80085AA4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80085AA8: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x80085AAC: srl         $t2, $s0, 6
    ctx->r10 = S32(U32(ctx->r16) >> 6);
    // 0x80085AB0: sll         $v0, $t2, 2
    ctx->r2 = S32(ctx->r10 << 2);
    // 0x80085AB4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085AB8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80085ABC: lhu         $a0, -0x3B80($at)
    ctx->r4 = MEM_HU(ctx->r1, -0X3B80);
    // 0x80085AC0: beq         $a0, $zero, L_80085BEC
    if (ctx->r4 == 0) {
        // 0x80085AC4: nop
    
            goto L_80085BEC;
    }
    // 0x80085AC4: nop

    // 0x80085AC8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085ACC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80085AD0: lhu         $t1, -0x3B7E($at)
    ctx->r9 = MEM_HU(ctx->r1, -0X3B7E);
    // 0x80085AD4: beq         $a0, $zero, L_80085BEC
    if (ctx->r4 == 0) {
        // 0x80085AD8: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_80085BEC;
    }
    // 0x80085AD8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80085ADC: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80085AE0: addu        $v0, $t1, $a2
    ctx->r2 = ADD32(ctx->r9, ctx->r6);
L_80085AE4:
    // 0x80085AE4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80085AE8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085AEC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80085AF0: lhu         $v0, 0x20C4($at)
    ctx->r2 = MEM_HU(ctx->r1, 0X20C4);
    // 0x80085AF4: beq         $v0, $s0, L_80085B10
    if (ctx->r2 == ctx->r16) {
        // 0x80085AF8: sll         $v0, $t2, 2
        ctx->r2 = S32(ctx->r10 << 2);
            goto L_80085B10;
    }
    // 0x80085AF8: sll         $v0, $t2, 2
    ctx->r2 = S32(ctx->r10 << 2);
    // 0x80085AFC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80085B00: slt         $v0, $a2, $v1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80085B04: bne         $v0, $zero, L_80085AE4
    if (ctx->r2 != 0) {
        // 0x80085B08: addu        $v0, $t1, $a2
        ctx->r2 = ADD32(ctx->r9, ctx->r6);
            goto L_80085AE4;
    }
    // 0x80085B08: addu        $v0, $t1, $a2
    ctx->r2 = ADD32(ctx->r9, ctx->r6);
    // 0x80085B0C: sll         $v0, $t2, 2
    ctx->r2 = S32(ctx->r10 << 2);
L_80085B10:
    // 0x80085B10: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085B14: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80085B18: lhu         $v0, -0x3B80($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X3B80);
    // 0x80085B1C: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80085B20: beq         $v0, $zero, L_80085BEC
    if (ctx->r2 == 0) {
        // 0x80085B24: addu        $v1, $t1, $a2
        ctx->r3 = ADD32(ctx->r9, ctx->r6);
            goto L_80085BEC;
    }
    // 0x80085B24: addu        $v1, $t1, $a2
    ctx->r3 = ADD32(ctx->r9, ctx->r6);
    // 0x80085B28: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80085B2C: lw          $v0, -0x73B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X73B0);
    // 0x80085B30: addiu       $a2, $v1, 0x1
    ctx->r6 = ADD32(ctx->r3, 0X1);
    // 0x80085B34: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80085B38: beq         $v0, $zero, L_80085B80
    if (ctx->r2 == 0) {
        // 0x80085B3C: sll         $v1, $a2, 3
        ctx->r3 = S32(ctx->r6 << 3);
            goto L_80085B80;
    }
    // 0x80085B3C: sll         $v1, $a2, 3
    ctx->r3 = S32(ctx->r6 << 3);
    // 0x80085B40: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80085B44: addiu       $v0, $v0, 0x20B8
    ctx->r2 = ADD32(ctx->r2, 0X20B8);
    // 0x80085B48: addu        $t0, $v1, $v0
    ctx->r8 = ADD32(ctx->r3, ctx->r2);
    // 0x80085B4C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80085B50: addu        $a3, $v1, $v0
    ctx->r7 = ADD32(ctx->r3, ctx->r2);
L_80085B54:
    // 0x80085B54: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80085B58: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
    // 0x80085B5C: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80085B60: sw          $v1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r3;
    // 0x80085B64: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80085B68: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80085B6C: lw          $v0, -0x73B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X73B0);
    // 0x80085B70: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80085B74: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80085B78: bne         $v0, $zero, L_80085B54
    if (ctx->r2 != 0) {
        // 0x80085B7C: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_80085B54;
    }
    // 0x80085B7C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
L_80085B80:
    // 0x80085B80: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80085B84: addiu       $a1, $a1, -0x3B80
    ctx->r5 = ADD32(ctx->r5, -0X3B80);
    // 0x80085B88: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80085B8C:
    // 0x80085B8C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085B90: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80085B94: lhu         $v1, -0x3B7E($at)
    ctx->r3 = MEM_HU(ctx->r1, -0X3B7E);
    // 0x80085B98: slt         $v0, $t1, $v1
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80085B9C: beq         $v0, $zero, L_80085BA8
    if (ctx->r2 == 0) {
        // 0x80085BA0: addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
            goto L_80085BA8;
    }
    // 0x80085BA0: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x80085BA4: sh          $v0, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r2;
L_80085BA8:
    // 0x80085BA8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80085BAC: slti        $v0, $a0, 0x800
    ctx->r2 = SIGNED(ctx->r4) < 0X800 ? 1 : 0;
    // 0x80085BB0: bne         $v0, $zero, L_80085B8C
    if (ctx->r2 != 0) {
        // 0x80085BB4: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80085B8C;
    }
    // 0x80085BB4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80085BB8: sll         $v0, $t2, 2
    ctx->r2 = S32(ctx->r10 << 2);
    // 0x80085BBC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085BC0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80085BC4: lhu         $v1, -0x3B80($at)
    ctx->r3 = MEM_HU(ctx->r1, -0X3B80);
    // 0x80085BC8: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80085BCC: lw          $a0, -0x73B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X73B0);
    // 0x80085BD0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80085BD4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80085BD8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085BDC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80085BE0: sh          $v1, -0x3B80($at)
    MEM_H(-0X3B80, ctx->r1) = ctx->r3;
    // 0x80085BE4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80085BE8: sw          $a0, -0x73B0($at)
    MEM_W(-0X73B0, ctx->r1) = ctx->r4;
L_80085BEC:
    // 0x80085BEC: jal         0x8009205C
    // 0x80085BF0: nop

    factor5MutexRelease(rdram, ctx);
        goto after_1;
    // 0x80085BF0: nop

    after_1:
    // 0x80085BF4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80085BF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80085BFC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80085C00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80085C04: jr          $ra
    // 0x80085C08: nop

    return;
    // 0x80085C08: nop

;}
RECOMP_FUNC void binarySearchWithComparator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085C0C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80085C10: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x80085C14: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80085C18: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80085C1C: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x80085C20: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80085C24: addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // 0x80085C28: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x80085C2C: addu        $s7, $a3, $zero
    ctx->r23 = ADD32(ctx->r7, 0);
    // 0x80085C30: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80085C34: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80085C38: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80085C3C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80085C40: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80085C44: beq         $a2, $zero, L_80085CA0
    if (ctx->r6 == 0) {
        // 0x80085C48: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_80085CA0;
    }
    // 0x80085C48: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80085C4C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80085C50: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x80085C54: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_80085C58:
    // 0x80085C58: sra         $s2, $v0, 1
    ctx->r18 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80085C5C: addiu       $s1, $s2, -0x1
    ctx->r17 = ADD32(ctx->r18, -0X1);
    // 0x80085C60: mult        $s7, $s1
    result = S64(S32(ctx->r23)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80085C64: mflo        $v0
    ctx->r2 = lo;
    // 0x80085C68: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x80085C6C: addu        $s0, $s6, $v0
    ctx->r16 = ADD32(ctx->r22, ctx->r2);
    // 0x80085C70: jalr        $fp
    // 0x80085C74: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r30)(rdram, ctx);
        goto after_0;
    // 0x80085C74: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80085C78: bne         $v0, $zero, L_80085C88
    if (ctx->r2 != 0) {
        // 0x80085C7C: nop
    
            goto L_80085C88;
    }
    // 0x80085C7C: nop

    // 0x80085C80: j           L_80085CA4
    // 0x80085C84: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
        goto L_80085CA4;
    // 0x80085C84: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80085C88:
    // 0x80085C88: bgezl       $v0, L_80085C94
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80085C8C: addiu       $s4, $s2, 0x1
        ctx->r20 = ADD32(ctx->r18, 0X1);
            goto L_80085C94;
    }
    goto skip_0;
    // 0x80085C8C: addiu       $s4, $s2, 0x1
    ctx->r20 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x80085C90: addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
L_80085C94:
    // 0x80085C94: slt         $v0, $s3, $s4
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80085C98: beq         $v0, $zero, L_80085C58
    if (ctx->r2 == 0) {
        // 0x80085C9C: addu        $v0, $s4, $s3
        ctx->r2 = ADD32(ctx->r20, ctx->r19);
            goto L_80085C58;
    }
    // 0x80085C9C: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_80085CA0:
    // 0x80085CA0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80085CA4:
    // 0x80085CA4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80085CA8: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x80085CAC: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x80085CB0: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x80085CB4: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80085CB8: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80085CBC: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80085CC0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80085CC4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80085CC8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80085CCC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80085CD0: jr          $ra
    // 0x80085CD4: nop

    return;
    // 0x80085CD4: nop

;}
RECOMP_FUNC void compareHalfwordAtOffset4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085CD8: lhu         $v1, 0x4($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X4);
    // 0x80085CDC: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    // 0x80085CE0: jr          $ra
    // 0x80085CE4: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    return;
    // 0x80085CE4: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
;}
RECOMP_FUNC void func_80085CE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085CE8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80085CEC: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x80085CF0: srl         $v0, $v0, 6
    ctx->r2 = S32(U32(ctx->r2) >> 6);
    // 0x80085CF4: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x80085CF8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80085CFC: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80085D00: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80085D04: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80085D08: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80085D0C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80085D10: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80085D14: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80085D18: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085D1C: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x80085D20: lhu         $v1, -0x3B80($at)
    ctx->r3 = MEM_HU(ctx->r1, -0X3B80);
    // 0x80085D24: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085D28: sw          $v0, -0x53DC($at)
    MEM_W(-0X53DC, ctx->r1) = ctx->r2;
    // 0x80085D2C: beq         $v1, $zero, L_80085DE0
    if (ctx->r3 == 0) {
        // 0x80085D30: addiu       $s6, $zero, 0x8
        ctx->r22 = ADD32(0, 0X8);
            goto L_80085DE0;
    }
    // 0x80085D30: addiu       $s6, $zero, 0x8
    ctx->r22 = ADD32(0, 0X8);
    // 0x80085D34: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085D38: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x80085D3C: lhu         $v1, -0x3B7E($at)
    ctx->r3 = MEM_HU(ctx->r1, -0X3B7E);
    // 0x80085D40: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085D44: sh          $a0, -0x53D4($at)
    MEM_H(-0X53D4, ctx->r1) = ctx->r4;
    // 0x80085D48: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085D4C: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x80085D50: lhu         $a0, -0x3B80($at)
    ctx->r4 = MEM_HU(ctx->r1, -0X3B80);
    // 0x80085D54: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80085D58: addiu       $v0, $v0, 0x20C0
    ctx->r2 = ADD32(ctx->r2, 0X20C0);
    // 0x80085D5C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085D60: sw          $v1, -0x53E0($at)
    MEM_W(-0X53E0, ctx->r1) = ctx->r3;
    // 0x80085D64: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80085D68: beq         $a0, $zero, L_80085DC0
    if (ctx->r4 == 0) {
        // 0x80085D6C: addu        $s5, $v1, $v0
        ctx->r21 = ADD32(ctx->r3, ctx->r2);
            goto L_80085DC0;
    }
    // 0x80085D6C: addu        $s5, $v1, $v0
    ctx->r21 = ADD32(ctx->r3, ctx->r2);
    // 0x80085D70: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80085D74: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80085D78: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_80085D7C:
    // 0x80085D7C: sra         $s2, $v0, 1
    ctx->r18 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80085D80: addiu       $s1, $s2, -0x1
    ctx->r17 = ADD32(ctx->r18, -0X1);
    // 0x80085D84: mult        $s6, $s1
    result = S64(S32(ctx->r22)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80085D88: mflo        $v0
    ctx->r2 = lo;
    // 0x80085D8C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80085D90: addiu       $a0, $a0, -0x53D8
    ctx->r4 = ADD32(ctx->r4, -0X53D8);
    // 0x80085D94: addu        $s0, $s5, $v0
    ctx->r16 = ADD32(ctx->r21, ctx->r2);
    // 0x80085D98: jal         0x80085CD8
    // 0x80085D9C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    compareHalfwordAtOffset4(rdram, ctx);
        goto after_0;
    // 0x80085D9C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80085DA0: beql        $v0, $zero, L_80085DC4
    if (ctx->r2 == 0) {
        // 0x80085DA4: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_80085DC4;
    }
    goto skip_0;
    // 0x80085DA4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    skip_0:
    // 0x80085DA8: bgezl       $v0, L_80085DB4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80085DAC: addiu       $s4, $s2, 0x1
        ctx->r20 = ADD32(ctx->r18, 0X1);
            goto L_80085DB4;
    }
    goto skip_1;
    // 0x80085DAC: addiu       $s4, $s2, 0x1
    ctx->r20 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x80085DB0: addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
L_80085DB4:
    // 0x80085DB4: slt         $v0, $s3, $s4
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80085DB8: beq         $v0, $zero, L_80085D7C
    if (ctx->r2 == 0) {
        // 0x80085DBC: addu        $v0, $s4, $s3
        ctx->r2 = ADD32(ctx->r20, ctx->r19);
            goto L_80085D7C;
    }
    // 0x80085DBC: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_80085DC0:
    // 0x80085DC0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80085DC4:
    // 0x80085DC4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085DC8: sw          $a1, -0x53D0($at)
    MEM_W(-0X53D0, ctx->r1) = ctx->r5;
    // 0x80085DCC: beq         $a1, $zero, L_80085DE4
    if (ctx->r5 == 0) {
        // 0x80085DD0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80085DE4;
    }
    // 0x80085DD0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80085DD4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80085DD8: j           L_80085DE4
    // 0x80085DDC: nop

        goto L_80085DE4;
    // 0x80085DDC: nop

L_80085DE0:
    // 0x80085DE0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80085DE4:
    // 0x80085DE4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80085DE8: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x80085DEC: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80085DF0: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80085DF4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80085DF8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80085DFC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80085E00: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80085E04: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80085E08: jr          $ra
    // 0x80085E0C: nop

    return;
    // 0x80085E0C: nop

;}
RECOMP_FUNC void compareHalfwordAtOffset8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085E10: lhu         $v1, 0x8($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X8);
    // 0x80085E14: lhu         $v0, 0x8($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X8);
    // 0x80085E18: jr          $ra
    // 0x80085E1C: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    return;
    // 0x80085E1C: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
;}
RECOMP_FUNC void func_80085E20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085E20: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80085E24: lw          $v0, -0x3BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3BB4);
    // 0x80085E28: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80085E2C: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80085E30: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x80085E34: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x80085E38: lui         $s7, 0x8014
    ctx->r23 = S32(0X8014 << 16);
    // 0x80085E3C: addiu       $s7, $s7, -0x4FB8
    ctx->r23 = ADD32(ctx->r23, -0X4FB8);
    // 0x80085E40: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80085E44: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80085E48: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80085E4C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80085E50: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80085E54: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80085E58: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80085E5C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085E60: sh          $a0, -0x53B8($at)
    MEM_H(-0X53B8, ctx->r1) = ctx->r4;
    // 0x80085E64: beq         $v0, $zero, L_80085EBC
    if (ctx->r2 == 0) {
        // 0x80085E68: addiu       $s6, $zero, 0xC
        ctx->r22 = ADD32(0, 0XC);
            goto L_80085EBC;
    }
    // 0x80085E68: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
    // 0x80085E6C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80085E70: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80085E74: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_80085E78:
    // 0x80085E78: sra         $s2, $v0, 1
    ctx->r18 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80085E7C: addiu       $s1, $s2, -0x1
    ctx->r17 = ADD32(ctx->r18, -0X1);
    // 0x80085E80: mult        $s6, $s1
    result = S64(S32(ctx->r22)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80085E84: mflo        $v0
    ctx->r2 = lo;
    // 0x80085E88: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80085E8C: addiu       $a0, $a0, -0x53C0
    ctx->r4 = ADD32(ctx->r4, -0X53C0);
    // 0x80085E90: addu        $s0, $s7, $v0
    ctx->r16 = ADD32(ctx->r23, ctx->r2);
    // 0x80085E94: jal         0x80085E10
    // 0x80085E98: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    compareHalfwordAtOffset8(rdram, ctx);
        goto after_0;
    // 0x80085E98: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80085E9C: beql        $v0, $zero, L_80085EC0
    if (ctx->r2 == 0) {
        // 0x80085EA0: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_80085EC0;
    }
    goto skip_0;
    // 0x80085EA0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    skip_0:
    // 0x80085EA4: bgezl       $v0, L_80085EB0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80085EA8: addiu       $s4, $s2, 0x1
        ctx->r20 = ADD32(ctx->r18, 0X1);
            goto L_80085EB0;
    }
    goto skip_1;
    // 0x80085EA8: addiu       $s4, $s2, 0x1
    ctx->r20 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x80085EAC: addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
L_80085EB0:
    // 0x80085EB0: slt         $v0, $s3, $s4
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80085EB4: beq         $v0, $zero, L_80085E78
    if (ctx->r2 == 0) {
        // 0x80085EB8: addu        $v0, $s4, $s3
        ctx->r2 = ADD32(ctx->r20, ctx->r19);
            goto L_80085E78;
    }
    // 0x80085EB8: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_80085EBC:
    // 0x80085EBC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80085EC0:
    // 0x80085EC0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085EC4: sw          $a1, -0x53B4($at)
    MEM_W(-0X53B4, ctx->r1) = ctx->r5;
    // 0x80085EC8: bne         $a1, $zero, L_80085ED8
    if (ctx->r5 != 0) {
        // 0x80085ECC: lui         $v1, 0xFF
        ctx->r3 = S32(0XFF << 16);
            goto L_80085ED8;
    }
    // 0x80085ECC: lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // 0x80085ED0: j           L_80085F24
    // 0x80085ED4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80085F24;
    // 0x80085ED4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80085ED8:
    // 0x80085ED8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80085EDC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80085EE0: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
    // 0x80085EE4: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x80085EE8: sw          $zero, 0x8($s5)
    MEM_W(0X8, ctx->r21) = 0;
    // 0x80085EEC: sw          $v0, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r2;
    // 0x80085EF0: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80085EF4: sw          $v0, 0x10($s5)
    MEM_W(0X10, ctx->r21) = ctx->r2;
    // 0x80085EF8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80085EFC: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x80085F00: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80085F04: sw          $v0, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r2;
    // 0x80085F08: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x80085F0C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085F10: sw          $a0, -0x53B0($at)
    MEM_W(-0X53B0, ctx->r1) = ctx->r4;
    // 0x80085F14: sw          $v0, 0x14($s5)
    MEM_W(0X14, ctx->r21) = ctx->r2;
    // 0x80085F18: lbu         $v1, 0x4($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X4);
    // 0x80085F1C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80085F20: sb          $v1, 0x18($s5)
    MEM_B(0X18, ctx->r21) = ctx->r3;
L_80085F24:
    // 0x80085F24: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80085F28: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x80085F2C: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x80085F30: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80085F34: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80085F38: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80085F3C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80085F40: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80085F44: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80085F48: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80085F4C: jr          $ra
    // 0x80085F50: nop

    return;
    // 0x80085F50: nop

;}
RECOMP_FUNC void compareHalfwordAtOffset4_v2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085F54: lhu         $v1, 0x4($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X4);
    // 0x80085F58: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    // 0x80085F5C: jr          $ra
    // 0x80085F60: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    return;
    // 0x80085F60: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
;}
RECOMP_FUNC void func_80085F64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085F64: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80085F68: lw          $v0, -0x50F4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X50F4);
    // 0x80085F6C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80085F70: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80085F74: lui         $s6, 0x8015
    ctx->r22 = S32(0X8015 << 16);
    // 0x80085F78: addiu       $s6, $s6, -0x7398
    ctx->r22 = ADD32(ctx->r22, -0X7398);
    // 0x80085F7C: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80085F80: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80085F84: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80085F88: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80085F8C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80085F90: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80085F94: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80085F98: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80085F9C: sh          $a0, -0x53A4($at)
    MEM_H(-0X53A4, ctx->r1) = ctx->r4;
    // 0x80085FA0: beq         $v0, $zero, L_80085FF8
    if (ctx->r2 == 0) {
        // 0x80085FA4: addiu       $s5, $zero, 0x8
        ctx->r21 = ADD32(0, 0X8);
            goto L_80085FF8;
    }
    // 0x80085FA4: addiu       $s5, $zero, 0x8
    ctx->r21 = ADD32(0, 0X8);
    // 0x80085FA8: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80085FAC: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80085FB0: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_80085FB4:
    // 0x80085FB4: sra         $s2, $v0, 1
    ctx->r18 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80085FB8: addiu       $s1, $s2, -0x1
    ctx->r17 = ADD32(ctx->r18, -0X1);
    // 0x80085FBC: mult        $s5, $s1
    result = S64(S32(ctx->r21)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80085FC0: mflo        $v0
    ctx->r2 = lo;
    // 0x80085FC4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80085FC8: addiu       $a0, $a0, -0x53A8
    ctx->r4 = ADD32(ctx->r4, -0X53A8);
    // 0x80085FCC: addu        $s0, $s6, $v0
    ctx->r16 = ADD32(ctx->r22, ctx->r2);
    // 0x80085FD0: jal         0x80085F54
    // 0x80085FD4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    compareHalfwordAtOffset4_v2(rdram, ctx);
        goto after_0;
    // 0x80085FD4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80085FD8: beql        $v0, $zero, L_80085FFC
    if (ctx->r2 == 0) {
        // 0x80085FDC: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_80085FFC;
    }
    goto skip_0;
    // 0x80085FDC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    skip_0:
    // 0x80085FE0: bgezl       $v0, L_80085FEC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80085FE4: addiu       $s4, $s2, 0x1
        ctx->r20 = ADD32(ctx->r18, 0X1);
            goto L_80085FEC;
    }
    goto skip_1;
    // 0x80085FE4: addiu       $s4, $s2, 0x1
    ctx->r20 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x80085FE8: addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
L_80085FEC:
    // 0x80085FEC: slt         $v0, $s3, $s4
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80085FF0: beq         $v0, $zero, L_80085FB4
    if (ctx->r2 == 0) {
        // 0x80085FF4: addu        $v0, $s4, $s3
        ctx->r2 = ADD32(ctx->r20, ctx->r19);
            goto L_80085FB4;
    }
    // 0x80085FF4: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_80085FF8:
    // 0x80085FF8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80085FFC:
    // 0x80085FFC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086000: sw          $a1, -0x53A0($at)
    MEM_W(-0X53A0, ctx->r1) = ctx->r5;
    // 0x80086004: beq         $a1, $zero, L_80086010
    if (ctx->r5 == 0) {
        // 0x80086008: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80086010;
    }
    // 0x80086008: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8008600C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
L_80086010:
    // 0x80086010: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80086014: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x80086018: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8008601C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80086020: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80086024: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80086028: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8008602C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80086030: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80086034: jr          $ra
    // 0x80086038: nop

    return;
    // 0x80086038: nop

;}
RECOMP_FUNC void func_8008603C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008603C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80086040: lw          $v0, -0x3BB0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3BB0);
    // 0x80086044: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80086048: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x8008604C: lui         $s6, 0x8014
    ctx->r22 = S32(0X8014 << 16);
    // 0x80086050: addiu       $s6, $s6, -0x43B8
    ctx->r22 = ADD32(ctx->r22, -0X43B8);
    // 0x80086054: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80086058: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8008605C: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80086060: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80086064: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80086068: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8008606C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80086070: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086074: sh          $a0, -0x5394($at)
    MEM_H(-0X5394, ctx->r1) = ctx->r4;
    // 0x80086078: beq         $v0, $zero, L_800860D0
    if (ctx->r2 == 0) {
        // 0x8008607C: addiu       $s5, $zero, 0x8
        ctx->r21 = ADD32(0, 0X8);
            goto L_800860D0;
    }
    // 0x8008607C: addiu       $s5, $zero, 0x8
    ctx->r21 = ADD32(0, 0X8);
    // 0x80086080: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80086084: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80086088: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_8008608C:
    // 0x8008608C: sra         $s2, $v0, 1
    ctx->r18 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80086090: addiu       $s1, $s2, -0x1
    ctx->r17 = ADD32(ctx->r18, -0X1);
    // 0x80086094: mult        $s5, $s1
    result = S64(S32(ctx->r21)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80086098: mflo        $v0
    ctx->r2 = lo;
    // 0x8008609C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800860A0: addiu       $a0, $a0, -0x5398
    ctx->r4 = ADD32(ctx->r4, -0X5398);
    // 0x800860A4: addu        $s0, $s6, $v0
    ctx->r16 = ADD32(ctx->r22, ctx->r2);
    // 0x800860A8: jal         0x80085F54
    // 0x800860AC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    compareHalfwordAtOffset4_v2(rdram, ctx);
        goto after_0;
    // 0x800860AC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x800860B0: beql        $v0, $zero, L_800860D4
    if (ctx->r2 == 0) {
        // 0x800860B4: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_800860D4;
    }
    goto skip_0;
    // 0x800860B4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    skip_0:
    // 0x800860B8: bgezl       $v0, L_800860C4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800860BC: addiu       $s4, $s2, 0x1
        ctx->r20 = ADD32(ctx->r18, 0X1);
            goto L_800860C4;
    }
    goto skip_1;
    // 0x800860BC: addiu       $s4, $s2, 0x1
    ctx->r20 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x800860C0: addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
L_800860C4:
    // 0x800860C4: slt         $v0, $s3, $s4
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800860C8: beq         $v0, $zero, L_8008608C
    if (ctx->r2 == 0) {
        // 0x800860CC: addu        $v0, $s4, $s3
        ctx->r2 = ADD32(ctx->r20, ctx->r19);
            goto L_8008608C;
    }
    // 0x800860CC: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_800860D0:
    // 0x800860D0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_800860D4:
    // 0x800860D4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800860D8: sw          $a1, -0x5390($at)
    MEM_W(-0X5390, ctx->r1) = ctx->r5;
    // 0x800860DC: beq         $a1, $zero, L_800860E8
    if (ctx->r5 == 0) {
        // 0x800860E0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800860E8;
    }
    // 0x800860E0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800860E4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
L_800860E8:
    // 0x800860E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800860EC: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x800860F0: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800860F4: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800860F8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800860FC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80086100: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80086104: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80086108: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008610C: jr          $ra
    // 0x80086110: nop

    return;
    // 0x80086110: nop

;}
RECOMP_FUNC void compareHalfwordAtOffset4_v3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086114: lhu         $v1, 0x4($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X4);
    // 0x80086118: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    // 0x8008611C: jr          $ra
    // 0x80086120: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    return;
    // 0x80086120: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
;}
RECOMP_FUNC void func_80086124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086124: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80086128: lw          $v0, -0x50F8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X50F8);
    // 0x8008612C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80086130: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x80086134: addu        $s7, $a1, $zero
    ctx->r23 = ADD32(ctx->r5, 0);
    // 0x80086138: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x8008613C: lui         $s6, 0x8015
    ctx->r22 = S32(0X8015 << 16);
    // 0x80086140: addiu       $s6, $s6, -0x7BB0
    ctx->r22 = ADD32(ctx->r22, -0X7BB0);
    // 0x80086144: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80086148: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x8008614C: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80086150: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80086154: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80086158: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8008615C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80086160: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086164: sh          $a0, -0x5384($at)
    MEM_H(-0X5384, ctx->r1) = ctx->r4;
    // 0x80086168: beq         $v0, $zero, L_800861C0
    if (ctx->r2 == 0) {
        // 0x8008616C: addiu       $s5, $zero, 0x8
        ctx->r21 = ADD32(0, 0X8);
            goto L_800861C0;
    }
    // 0x8008616C: addiu       $s5, $zero, 0x8
    ctx->r21 = ADD32(0, 0X8);
    // 0x80086170: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80086174: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80086178: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_8008617C:
    // 0x8008617C: sra         $s2, $v0, 1
    ctx->r18 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80086180: addiu       $s1, $s2, -0x1
    ctx->r17 = ADD32(ctx->r18, -0X1);
    // 0x80086184: mult        $s5, $s1
    result = S64(S32(ctx->r21)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80086188: mflo        $v0
    ctx->r2 = lo;
    // 0x8008618C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80086190: addiu       $a0, $a0, -0x5388
    ctx->r4 = ADD32(ctx->r4, -0X5388);
    // 0x80086194: addu        $s0, $s6, $v0
    ctx->r16 = ADD32(ctx->r22, ctx->r2);
    // 0x80086198: jal         0x80086114
    // 0x8008619C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    compareHalfwordAtOffset4_v3(rdram, ctx);
        goto after_0;
    // 0x8008619C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x800861A0: beql        $v0, $zero, L_800861C4
    if (ctx->r2 == 0) {
        // 0x800861A4: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_800861C4;
    }
    goto skip_0;
    // 0x800861A4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    skip_0:
    // 0x800861A8: bgezl       $v0, L_800861B4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800861AC: addiu       $s4, $s2, 0x1
        ctx->r20 = ADD32(ctx->r18, 0X1);
            goto L_800861B4;
    }
    goto skip_1;
    // 0x800861AC: addiu       $s4, $s2, 0x1
    ctx->r20 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x800861B0: addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
L_800861B4:
    // 0x800861B4: slt         $v0, $s3, $s4
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800861B8: beq         $v0, $zero, L_8008617C
    if (ctx->r2 == 0) {
        // 0x800861BC: addu        $v0, $s4, $s3
        ctx->r2 = ADD32(ctx->r20, ctx->r19);
            goto L_8008617C;
    }
    // 0x800861BC: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_800861C0:
    // 0x800861C0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_800861C4:
    // 0x800861C4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800861C8: sw          $a1, -0x5380($at)
    MEM_W(-0X5380, ctx->r1) = ctx->r5;
    // 0x800861CC: beq         $a1, $zero, L_800861E8
    if (ctx->r5 == 0) {
        // 0x800861D0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800861E8;
    }
    // 0x800861D0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800861D4: lhu         $v0, 0x6($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X6);
    // 0x800861D8: sh          $v0, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r2;
    // 0x800861DC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800861E0: lw          $v0, -0x5380($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5380);
    // 0x800861E4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_800861E8:
    // 0x800861E8: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x800861EC: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x800861F0: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x800861F4: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800861F8: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800861FC: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80086200: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80086204: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80086208: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8008620C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80086210: jr          $ra
    // 0x80086214: nop

    return;
    // 0x80086214: nop

;}
RECOMP_FUNC void cmpU16ByValue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086218: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x8008621C: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x80086220: jr          $ra
    // 0x80086224: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    return;
    // 0x80086224: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
;}
RECOMP_FUNC void func_80086228(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086228: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008622C: lw          $v0, 0x800($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X800);
    // 0x80086230: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80086234: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80086238: lui         $s6, 0x8014
    ctx->r22 = S32(0X8014 << 16);
    // 0x8008623C: addiu       $s6, $s6, -0x3380
    ctx->r22 = ADD32(ctx->r22, -0X3380);
    // 0x80086240: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80086244: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80086248: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8008624C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80086250: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80086254: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80086258: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8008625C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086260: sh          $a0, -0x5370($at)
    MEM_H(-0X5370, ctx->r1) = ctx->r4;
    // 0x80086264: beq         $v0, $zero, L_800862C4
    if (ctx->r2 == 0) {
        // 0x80086268: addiu       $s5, $zero, 0xC
        ctx->r21 = ADD32(0, 0XC);
            goto L_800862C4;
    }
    // 0x80086268: addiu       $s5, $zero, 0xC
    ctx->r21 = ADD32(0, 0XC);
    // 0x8008626C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80086270: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80086274: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_80086278:
    // 0x80086278: sra         $s2, $v0, 1
    ctx->r18 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8008627C: addiu       $s1, $s2, -0x1
    ctx->r17 = ADD32(ctx->r18, -0X1);
    // 0x80086280: mult        $s5, $s1
    result = S64(S32(ctx->r21)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80086284: mflo        $v0
    ctx->r2 = lo;
    // 0x80086288: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008628C: addiu       $a0, $a0, -0x5370
    ctx->r4 = ADD32(ctx->r4, -0X5370);
    // 0x80086290: addu        $s0, $s6, $v0
    ctx->r16 = ADD32(ctx->r22, ctx->r2);
    // 0x80086294: jal         0x80086218
    // 0x80086298: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    cmpU16ByValue(rdram, ctx);
        goto after_0;
    // 0x80086298: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8008629C: bne         $v0, $zero, L_800862AC
    if (ctx->r2 != 0) {
        // 0x800862A0: nop
    
            goto L_800862AC;
    }
    // 0x800862A0: nop

    // 0x800862A4: j           L_800862C8
    // 0x800862A8: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
        goto L_800862C8;
    // 0x800862A8: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_800862AC:
    // 0x800862AC: bgezl       $v0, L_800862B8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800862B0: addiu       $s4, $s2, 0x1
        ctx->r20 = ADD32(ctx->r18, 0X1);
            goto L_800862B8;
    }
    goto skip_0;
    // 0x800862B0: addiu       $s4, $s2, 0x1
    ctx->r20 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x800862B4: addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
L_800862B8:
    // 0x800862B8: slt         $v0, $s3, $s4
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800862BC: beq         $v0, $zero, L_80086278
    if (ctx->r2 == 0) {
        // 0x800862C0: addu        $v0, $s4, $s3
        ctx->r2 = ADD32(ctx->r20, ctx->r19);
            goto L_80086278;
    }
    // 0x800862C0: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_800862C4:
    // 0x800862C4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800862C8:
    // 0x800862C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800862CC: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x800862D0: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800862D4: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800862D8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800862DC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800862E0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800862E4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800862E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800862EC: jr          $ra
    // 0x800862F0: nop

    return;
    // 0x800862F0: nop

;}
RECOMP_FUNC void func_800862F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800862F4: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800862F8: lw          $v0, 0x64($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X64);
    // 0x800862FC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80086300: beq         $v0, $a2, L_80086448
    if (ctx->r2 == ctx->r6) {
        // 0x80086304: nop
    
            goto L_80086448;
    }
    // 0x80086304: nop

    // 0x80086308: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x8008630C: beq         $a0, $a2, L_80086370
    if (ctx->r4 == ctx->r6) {
        // 0x80086310: andi        $v0, $a0, 0xFF
        ctx->r2 = ctx->r4 & 0XFF;
            goto L_80086370;
    }
    // 0x80086310: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80086314: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80086318: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8008631C: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80086320: lw          $a0, 0x10($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X10);
    // 0x80086324: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80086328: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8008632C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086330: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80086334: sw          $a0, -0x2770($at)
    MEM_W(-0X2770, ctx->r1) = ctx->r4;
    // 0x80086338: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    // 0x8008633C: beq         $v0, $a2, L_80086448
    if (ctx->r2 == ctx->r6) {
        // 0x80086340: andi        $v0, $v0, 0xFF
        ctx->r2 = ctx->r2 & 0XFF;
            goto L_80086448;
    }
    // 0x80086340: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80086344: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80086348: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8008634C: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80086350: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x80086354: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80086358: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8008635C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086360: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80086364: sw          $a0, -0x276C($at)
    MEM_W(-0X276C, ctx->r1) = ctx->r4;
    // 0x80086368: j           L_80086448
    // 0x8008636C: nop

        goto L_80086448;
    // 0x8008636C: nop

L_80086370:
    // 0x80086370: lw          $v1, 0x10($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X10);
    // 0x80086374: beq         $v1, $a0, L_800863D8
    if (ctx->r3 == ctx->r4) {
        // 0x80086378: nop
    
            goto L_800863D8;
    }
    // 0x80086378: nop

    // 0x8008637C: lw          $v0, 0x18($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X18);
    // 0x80086380: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x80086384: lbu         $v1, 0x13($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X13);
    // 0x80086388: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8008638C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80086390: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80086394: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80086398: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008639C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800863A0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800863A4: sw          $a0, -0x276C($at)
    MEM_W(-0X276C, ctx->r1) = ctx->r4;
    // 0x800863A8: lbu         $v1, 0x13($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X13);
    // 0x800863AC: lw          $a0, 0x18($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X18);
    // 0x800863B0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800863B4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800863B8: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800863BC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800863C0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800863C4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800863C8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800863CC: sw          $a0, -0x2768($at)
    MEM_W(-0X2768, ctx->r1) = ctx->r4;
    // 0x800863D0: j           L_80086448
    // 0x800863D4: nop

        goto L_80086448;
    // 0x800863D4: nop

L_800863D8:
    // 0x800863D8: lw          $v0, 0x18($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X18);
    // 0x800863DC: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x800863E0: beq         $v1, $zero, L_800863F4
    if (ctx->r3 == 0) {
        // 0x800863E4: nop
    
            goto L_800863F4;
    }
    // 0x800863E4: nop

    // 0x800863E8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800863EC: j           L_80086400
    // 0x800863F0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_80086400;
    // 0x800863F0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800863F4:
    // 0x800863F4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800863F8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800863FC: sw          $v0, -0x5100($at)
    MEM_W(-0X5100, ctx->r1) = ctx->r2;
L_80086400:
    // 0x80086400: lw          $v0, 0x18($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X18);
    // 0x80086404: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80086408: beq         $v1, $zero, L_8008641C
    if (ctx->r3 == 0) {
        // 0x8008640C: nop
    
            goto L_8008641C;
    }
    // 0x8008640C: nop

    // 0x80086410: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80086414: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80086418: lw          $v0, 0x18($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X18);
L_8008641C:
    // 0x8008641C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80086420: lw          $v1, -0x50FC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X50FC);
    // 0x80086424: beq         $v1, $zero, L_80086434
    if (ctx->r3 == 0) {
        // 0x80086428: sw          $v1, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r3;
            goto L_80086434;
    }
    // 0x80086428: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8008642C: lw          $v0, 0x18($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X18);
    // 0x80086430: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80086434:
    // 0x80086434: lw          $v0, 0x18($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X18);
    // 0x80086438: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8008643C: lw          $v0, 0x18($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X18);
    // 0x80086440: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086444: sw          $v0, -0x50FC($at)
    MEM_W(-0X50FC, ctx->r1) = ctx->r2;
L_80086448:
    // 0x80086448: jr          $ra
    // 0x8008644C: nop

    return;
    // 0x8008644C: nop

;}
RECOMP_FUNC void func_80086450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086450: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_80086454:
    // 0x80086454: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80086458: lw          $v1, -0x5308($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5308);
    // 0x8008645C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80086460: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086464: sw          $v0, -0x5308($at)
    MEM_W(-0X5308, ctx->r1) = ctx->r2;
    // 0x80086468: beq         $v1, $a1, L_80086454
    if (ctx->r3 == ctx->r5) {
        // 0x8008646C: addu        $a3, $v1, $zero
        ctx->r7 = ADD32(ctx->r3, 0);
            goto L_80086454;
    }
    // 0x8008646C: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    // 0x80086470: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80086474: lw          $a2, -0x5100($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X5100);
    // 0x80086478: beq         $a2, $zero, L_800864CC
    if (ctx->r6 == 0) {
        // 0x8008647C: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_800864CC;
    }
    // 0x8008647C: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80086480: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_80086484:
    // 0x80086484: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x80086488: sltu        $v0, $a3, $v1
    ctx->r2 = ctx->r7 < ctx->r3 ? 1 : 0;
    // 0x8008648C: bne         $v0, $zero, L_800864CC
    if (ctx->r2 != 0) {
        // 0x80086490: nop
    
            goto L_800864CC;
    }
    // 0x80086490: nop

    // 0x80086494: bnel        $v1, $a3, L_800864C0
    if (ctx->r3 != ctx->r7) {
        // 0x80086498: addu        $t0, $a2, $zero
        ctx->r8 = ADD32(ctx->r6, 0);
            goto L_800864C0;
    }
    goto skip_0;
    // 0x80086498: addu        $t0, $a2, $zero
    ctx->r8 = ADD32(ctx->r6, 0);
    skip_0:
L_8008649C:
    // 0x8008649C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800864A0: lw          $v1, -0x5308($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5308);
    // 0x800864A4: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800864A8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800864AC: sw          $v0, -0x5308($at)
    MEM_W(-0X5308, ctx->r1) = ctx->r2;
    // 0x800864B0: beq         $v1, $a1, L_8008649C
    if (ctx->r3 == ctx->r5) {
        // 0x800864B4: nop
    
            goto L_8008649C;
    }
    // 0x800864B4: nop

    // 0x800864B8: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    // 0x800864BC: addu        $t0, $a2, $zero
    ctx->r8 = ADD32(ctx->r6, 0);
L_800864C0:
    // 0x800864C0: lw          $a2, 0x0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X0);
    // 0x800864C4: bne         $a2, $zero, L_80086484
    if (ctx->r6 != 0) {
        // 0x800864C8: nop
    
            goto L_80086484;
    }
    // 0x800864C8: nop

L_800864CC:
    // 0x800864CC: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800864D0: lw          $a1, -0x50FC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X50FC);
    // 0x800864D4: beq         $a1, $zero, L_8008652C
    if (ctx->r5 == 0) {
        // 0x800864D8: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8008652C;
    }
    // 0x800864D8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800864DC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800864E0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800864E4: sw          $v0, -0x50FC($at)
    MEM_W(-0X50FC, ctx->r1) = ctx->r2;
    // 0x800864E8: bnel        $v0, $zero, L_800864F0
    if (ctx->r2 != 0) {
        // 0x800864EC: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_800864F0;
    }
    goto skip_1;
    // 0x800864EC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_1:
L_800864F0:
    // 0x800864F0: bnel        $t0, $zero, L_80086508
    if (ctx->r8 != 0) {
        // 0x800864F4: sw          $a1, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r5;
            goto L_80086508;
    }
    goto skip_2;
    // 0x800864F4: sw          $a1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r5;
    skip_2:
    // 0x800864F8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800864FC: sw          $a1, -0x5100($at)
    MEM_W(-0X5100, ctx->r1) = ctx->r5;
    // 0x80086500: j           L_8008650C
    // 0x80086504: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
        goto L_8008650C;
    // 0x80086504: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
L_80086508:
    // 0x80086508: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
L_8008650C:
    // 0x8008650C: beq         $a2, $zero, L_80086518
    if (ctx->r6 == 0) {
        // 0x80086510: sw          $a2, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r6;
            goto L_80086518;
    }
    // 0x80086510: sw          $a2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r6;
    // 0x80086514: sw          $a1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r5;
L_80086518:
    // 0x80086518: sw          $a3, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r7;
    // 0x8008651C: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x80086520: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    // 0x80086524: sw          $v1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r3;
    // 0x80086528: sw          $a1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r5;
L_8008652C:
    // 0x8008652C: jr          $ra
    // 0x80086530: nop

    return;
    // 0x80086530: nop

;}
RECOMP_FUNC void func_80086534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086534: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80086538: beq         $a0, $v0, L_8008658C
    if (ctx->r4 == ctx->r2) {
        // 0x8008653C: nop
    
            goto L_8008658C;
    }
    // 0x8008653C: nop

    // 0x80086540: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80086544: lw          $v1, -0x5100($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5100);
    // 0x80086548: beq         $v1, $zero, L_80086570
    if (ctx->r3 == 0) {
        // 0x8008654C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80086570;
    }
    // 0x8008654C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80086550:
    // 0x80086550: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80086554: beq         $v0, $a0, L_80086584
    if (ctx->r2 == ctx->r4) {
        // 0x80086558: sltu        $v0, $a0, $v0
        ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
            goto L_80086584;
    }
    // 0x80086558: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8008655C: bne         $v0, $zero, L_80086570
    if (ctx->r2 != 0) {
        // 0x80086560: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80086570;
    }
    // 0x80086560: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80086564: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80086568: bne         $v1, $zero, L_80086550
    if (ctx->r3 != 0) {
        // 0x8008656C: nop
    
            goto L_80086550;
    }
    // 0x8008656C: nop

L_80086570:
    // 0x80086570: beql        $v0, $zero, L_8008658C
    if (ctx->r2 == 0) {
        // 0x80086574: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8008658C;
    }
    goto skip_0;
    // 0x80086574: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_0:
    // 0x80086578: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x8008657C: j           L_8008658C
    // 0x80086580: nop

        goto L_8008658C;
    // 0x80086580: nop

L_80086584:
    // 0x80086584: j           L_80086570
    // 0x80086588: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80086570;
    // 0x80086588: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8008658C:
    // 0x8008658C: jr          $ra
    // 0x80086590: nop

    return;
    // 0x80086590: nop

;}
RECOMP_FUNC void func_80086594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086594: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80086598: lbu         $v0, -0x530C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X530C);
    // 0x8008659C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800865A0: bne         $v0, $zero, L_80086904
    if (ctx->r2 != 0) {
        // 0x800865A4: addu        $t8, $a0, $zero
        ctx->r24 = ADD32(ctx->r4, 0);
            goto L_80086904;
    }
    // 0x800865A4: addu        $t8, $a0, $zero
    ctx->r24 = ADD32(ctx->r4, 0);
    // 0x800865A8: andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // 0x800865AC: beq         $v0, $zero, L_800865C4
    if (ctx->r2 == 0) {
        // 0x800865B0: nop
    
            goto L_800865C4;
    }
    // 0x800865B0: nop

    // 0x800865B4: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x800865B8: lbu         $t6, -0x4FC8($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X4FC8);
    // 0x800865BC: j           L_800865CC
    // 0x800865C0: nop

        goto L_800865CC;
    // 0x800865C0: nop

L_800865C4:
    // 0x800865C4: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x800865C8: lbu         $t6, 0x1AD1($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X1AD1);
L_800865CC:
    // 0x800865CC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800865D0: lbu         $v1, 0x1AD0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X1AD0);
    // 0x800865D4: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x800865D8: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800865DC: bne         $v0, $zero, L_800865F0
    if (ctx->r2 != 0) {
        // 0x800865E0: addu        $t4, $zero, $zero
        ctx->r12 = ADD32(0, 0);
            goto L_800865F0;
    }
    // 0x800865E0: addu        $t4, $zero, $zero
    ctx->r12 = ADD32(0, 0);
    // 0x800865E4: slt         $v0, $t6, $v1
    ctx->r2 = SIGNED(ctx->r14) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800865E8: beq         $v0, $zero, L_80086804
    if (ctx->r2 == 0) {
        // 0x800865EC: nop
    
            goto L_80086804;
    }
    // 0x800865EC: nop

L_800865F0:
    // 0x800865F0: addu        $t5, $zero, $zero
    ctx->r13 = ADD32(0, 0);
    // 0x800865F4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800865F8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800865FC: beq         $v1, $zero, L_80086768
    if (ctx->r3 == 0) {
        // 0x80086600: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_80086768;
    }
    // 0x80086600: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80086604: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x80086608: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8008660C: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80086610: addu        $t9, $v1, $zero
    ctx->r25 = ADD32(ctx->r3, 0);
    // 0x80086614: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
L_80086618:
    // 0x80086618: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008661C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80086620: lbu         $v0, -0x26C7($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X26C7);
    // 0x80086624: bnel        $v0, $zero, L_8008675C
    if (ctx->r2 != 0) {
        // 0x80086628: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_8008675C;
    }
    goto skip_0;
    // 0x80086628: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_0:
    // 0x8008662C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086630: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80086634: lw          $v0, -0x2780($at)
    ctx->r2 = MEM_W(ctx->r1, -0X2780);
    // 0x80086638: beql        $v0, $zero, L_8008675C
    if (ctx->r2 == 0) {
        // 0x8008663C: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_8008675C;
    }
    goto skip_1;
    // 0x8008663C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_1:
    // 0x80086640: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086644: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80086648: lbu         $v0, -0x2730($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X2730);
    // 0x8008664C: bne         $v0, $a3, L_800866CC
    if (ctx->r2 != ctx->r7) {
        // 0x80086650: nop
    
            goto L_800866CC;
    }
    // 0x80086650: nop

    // 0x80086654: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086658: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8008665C: lw          $v0, -0x275C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X275C);
    // 0x80086660: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80086664: bne         $v0, $zero, L_800866CC
    if (ctx->r2 != 0) {
        // 0x80086668: addiu       $t5, $t5, 0x1
        ctx->r13 = ADD32(ctx->r13, 0X1);
            goto L_800866CC;
    }
    // 0x80086668: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x8008666C: beq         $t3, $t7, L_800866C8
    if (ctx->r11 == ctx->r15) {
        // 0x80086670: sll         $v0, $t3, 1
        ctx->r2 = S32(ctx->r11 << 1);
            goto L_800866C8;
    }
    // 0x80086670: sll         $v0, $t3, 1
    ctx->r2 = S32(ctx->r11 << 1);
    // 0x80086674: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x80086678: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8008667C: subu        $v0, $v0, $t3
    ctx->r2 = SUB32(ctx->r2, ctx->r11);
    // 0x80086680: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x80086684: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086688: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8008668C: lbu         $v0, -0x2752($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X2752);
    // 0x80086690: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086694: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80086698: lbu         $v1, -0x2752($at)
    ctx->r3 = MEM_BU(ctx->r1, -0X2752);
    // 0x8008669C: bne         $v0, $v1, L_800866C0
    if (ctx->r2 != ctx->r3) {
        // 0x800866A0: sltu        $v0, $v0, $v1
        ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
            goto L_800866C0;
    }
    // 0x800866A0: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800866A4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800866A8: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800866AC: lw          $v0, -0x2758($at)
    ctx->r2 = MEM_W(ctx->r1, -0X2758);
    // 0x800866B0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800866B4: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800866B8: lw          $v1, -0x2758($at)
    ctx->r3 = MEM_W(ctx->r1, -0X2758);
    // 0x800866BC: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
L_800866C0:
    // 0x800866C0: beq         $v0, $zero, L_800866CC
    if (ctx->r2 == 0) {
        // 0x800866C4: nop
    
            goto L_800866CC;
    }
    // 0x800866C4: nop

L_800866C8:
    // 0x800866C8: addu        $t3, $t0, $zero
    ctx->r11 = ADD32(ctx->r8, 0);
L_800866CC:
    // 0x800866CC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800866D0: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800866D4: lhu         $v0, -0x26CA($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X26CA);
    // 0x800866D8: bnel        $v0, $a2, L_8008675C
    if (ctx->r2 != ctx->r6) {
        // 0x800866DC: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_8008675C;
    }
    goto skip_2;
    // 0x800866DC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_2:
    // 0x800866E0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800866E4: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800866E8: lw          $v0, -0x275C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X275C);
    // 0x800866EC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800866F0: bne         $v0, $zero, L_80086758
    if (ctx->r2 != 0) {
        // 0x800866F4: addiu       $t4, $t4, 0x1
        ctx->r12 = ADD32(ctx->r12, 0X1);
            goto L_80086758;
    }
    // 0x800866F4: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800866F8: beq         $t2, $t7, L_80086754
    if (ctx->r10 == ctx->r15) {
        // 0x800866FC: sll         $v0, $t2, 1
        ctx->r2 = S32(ctx->r10 << 1);
            goto L_80086754;
    }
    // 0x800866FC: sll         $v0, $t2, 1
    ctx->r2 = S32(ctx->r10 << 1);
    // 0x80086700: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80086704: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80086708: subu        $v0, $v0, $t2
    ctx->r2 = SUB32(ctx->r2, ctx->r10);
    // 0x8008670C: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x80086710: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086714: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80086718: lbu         $v0, -0x2752($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X2752);
    // 0x8008671C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086720: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80086724: lbu         $v1, -0x2752($at)
    ctx->r3 = MEM_BU(ctx->r1, -0X2752);
    // 0x80086728: bne         $v0, $v1, L_8008674C
    if (ctx->r2 != ctx->r3) {
        // 0x8008672C: sltu        $v0, $v0, $v1
        ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
            goto L_8008674C;
    }
    // 0x8008672C: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80086730: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086734: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80086738: lw          $v0, -0x2758($at)
    ctx->r2 = MEM_W(ctx->r1, -0X2758);
    // 0x8008673C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086740: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80086744: lw          $v1, -0x2758($at)
    ctx->r3 = MEM_W(ctx->r1, -0X2758);
    // 0x80086748: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
L_8008674C:
    // 0x8008674C: beql        $v0, $zero, L_8008675C
    if (ctx->r2 == 0) {
        // 0x80086750: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_8008675C;
    }
    goto skip_3;
    // 0x80086750: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_3:
L_80086754:
    // 0x80086754: addu        $t2, $t0, $zero
    ctx->r10 = ADD32(ctx->r8, 0);
L_80086758:
    // 0x80086758: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_8008675C:
    // 0x8008675C: slt         $v0, $t0, $t9
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80086760: bne         $v0, $zero, L_80086618
    if (ctx->r2 != 0) {
        // 0x80086764: addiu       $t1, $t1, 0x17C
        ctx->r9 = ADD32(ctx->r9, 0X17C);
            goto L_80086618;
    }
    // 0x80086764: addiu       $t1, $t1, 0x17C
    ctx->r9 = ADD32(ctx->r9, 0X17C);
L_80086768:
    // 0x80086768: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8008676C: slt         $v0, $t4, $v0
    ctx->r2 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80086770: bnel        $v0, $zero, L_800867BC
    if (ctx->r2 != 0) {
        // 0x80086774: slt         $v0, $t5, $t6
        ctx->r2 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
            goto L_800867BC;
    }
    goto skip_4;
    // 0x80086774: slt         $v0, $t5, $t6
    ctx->r2 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    skip_4:
    // 0x80086778: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8008677C: beq         $t2, $v1, L_80086908
    if (ctx->r10 == ctx->r3) {
        // 0x80086780: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80086908;
    }
    // 0x80086780: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80086784: sll         $v1, $t2, 1
    ctx->r3 = S32(ctx->r10 << 1);
    // 0x80086788: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x8008678C: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80086790: subu        $v1, $v1, $t2
    ctx->r3 = SUB32(ctx->r3, ctx->r10);
    // 0x80086794: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80086798: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008679C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800867A0: lbu         $a0, -0x2752($at)
    ctx->r4 = MEM_BU(ctx->r1, -0X2752);
    // 0x800867A4: andi        $v1, $t8, 0xFF
    ctx->r3 = ctx->r24 & 0XFF;
    // 0x800867A8: sltu        $v1, $v1, $a0
    ctx->r3 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x800867AC: bne         $v1, $zero, L_80086908
    if (ctx->r3 != 0) {
        // 0x800867B0: nop
    
            goto L_80086908;
    }
    // 0x800867B0: nop

    // 0x800867B4: j           L_80086908
    // 0x800867B8: addu        $v0, $t2, $zero
    ctx->r2 = ADD32(ctx->r10, 0);
        goto L_80086908;
    // 0x800867B8: addu        $v0, $t2, $zero
    ctx->r2 = ADD32(ctx->r10, 0);
L_800867BC:
    // 0x800867BC: bne         $v0, $zero, L_80086804
    if (ctx->r2 != 0) {
        // 0x800867C0: addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
            goto L_80086804;
    }
    // 0x800867C0: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800867C4: beq         $t3, $v1, L_80086908
    if (ctx->r11 == ctx->r3) {
        // 0x800867C8: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80086908;
    }
    // 0x800867C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800867CC: sll         $v1, $t3, 1
    ctx->r3 = S32(ctx->r11 << 1);
    // 0x800867D0: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x800867D4: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800867D8: subu        $v1, $v1, $t3
    ctx->r3 = SUB32(ctx->r3, ctx->r11);
    // 0x800867DC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800867E0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800867E4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800867E8: lbu         $a0, -0x2752($at)
    ctx->r4 = MEM_BU(ctx->r1, -0X2752);
    // 0x800867EC: andi        $v1, $t8, 0xFF
    ctx->r3 = ctx->r24 & 0XFF;
    // 0x800867F0: sltu        $v1, $v1, $a0
    ctx->r3 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x800867F4: beql        $v1, $zero, L_80086908
    if (ctx->r3 == 0) {
        // 0x800867F8: addu        $v0, $t3, $zero
        ctx->r2 = ADD32(ctx->r11, 0);
            goto L_80086908;
    }
    goto skip_5;
    // 0x800867F8: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
    skip_5:
    // 0x800867FC: j           L_80086908
    // 0x80086800: nop

        goto L_80086908;
    // 0x80086800: nop

L_80086804:
    // 0x80086804: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80086808: lbu         $v0, 0x1AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1AD0);
    // 0x8008680C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80086810: blez        $v0, L_800868CC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80086814: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_800868CC;
    }
    // 0x80086814: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80086818: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8008681C: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x80086820: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80086824:
    // 0x80086824: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086828: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x8008682C: lw          $v0, -0x275C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X275C);
    // 0x80086830: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80086834: bnel        $v0, $zero, L_800868C0
    if (ctx->r2 != 0) {
        // 0x80086838: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800868C0;
    }
    goto skip_6;
    // 0x80086838: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_6:
    // 0x8008683C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086840: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x80086844: lbu         $v0, -0x26C7($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X26C7);
    // 0x80086848: bnel        $v0, $zero, L_800868C0
    if (ctx->r2 != 0) {
        // 0x8008684C: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800868C0;
    }
    goto skip_7;
    // 0x8008684C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_7:
    // 0x80086850: beq         $t2, $t1, L_800868B8
    if (ctx->r10 == ctx->r9) {
        // 0x80086854: sll         $v0, $t2, 1
        ctx->r2 = S32(ctx->r10 << 1);
            goto L_800868B8;
    }
    // 0x80086854: sll         $v0, $t2, 1
    ctx->r2 = S32(ctx->r10 << 1);
    // 0x80086858: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x8008685C: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80086860: subu        $v0, $v0, $t2
    ctx->r2 = SUB32(ctx->r2, ctx->r10);
    // 0x80086864: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x80086868: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008686C: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x80086870: lbu         $a0, -0x2752($at)
    ctx->r4 = MEM_BU(ctx->r1, -0X2752);
    // 0x80086874: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086878: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x8008687C: lbu         $v1, -0x2752($at)
    ctx->r3 = MEM_BU(ctx->r1, -0X2752);
    // 0x80086880: sltu        $v0, $a0, $v1
    ctx->r2 = ctx->r4 < ctx->r3 ? 1 : 0;
    // 0x80086884: bnel        $v0, $zero, L_800868BC
    if (ctx->r2 != 0) {
        // 0x80086888: addu        $t2, $t0, $zero
        ctx->r10 = ADD32(ctx->r8, 0);
            goto L_800868BC;
    }
    goto skip_8;
    // 0x80086888: addu        $t2, $t0, $zero
    ctx->r10 = ADD32(ctx->r8, 0);
    skip_8:
    // 0x8008688C: bnel        $v1, $a0, L_800868C0
    if (ctx->r3 != ctx->r4) {
        // 0x80086890: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800868C0;
    }
    goto skip_9;
    // 0x80086890: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_9:
    // 0x80086894: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086898: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x8008689C: lw          $v1, -0x2758($at)
    ctx->r3 = MEM_W(ctx->r1, -0X2758);
    // 0x800868A0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800868A4: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x800868A8: lw          $v0, -0x2758($at)
    ctx->r2 = MEM_W(ctx->r1, -0X2758);
    // 0x800868AC: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800868B0: beql        $v0, $zero, L_800868C0
    if (ctx->r2 == 0) {
        // 0x800868B4: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800868C0;
    }
    goto skip_10;
    // 0x800868B4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_10:
L_800868B8:
    // 0x800868B8: addu        $t2, $t0, $zero
    ctx->r10 = ADD32(ctx->r8, 0);
L_800868BC:
    // 0x800868BC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800868C0:
    // 0x800868C0: slt         $v0, $t0, $a3
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800868C4: bne         $v0, $zero, L_80086824
    if (ctx->r2 != 0) {
        // 0x800868C8: addiu       $a2, $a2, 0x17C
        ctx->r6 = ADD32(ctx->r6, 0X17C);
            goto L_80086824;
    }
    // 0x800868C8: addiu       $a2, $a2, 0x17C
    ctx->r6 = ADD32(ctx->r6, 0X17C);
L_800868CC:
    // 0x800868CC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800868D0: beq         $t2, $v0, L_80086904
    if (ctx->r10 == ctx->r2) {
        // 0x800868D4: sll         $v0, $t2, 1
        ctx->r2 = S32(ctx->r10 << 1);
            goto L_80086904;
    }
    // 0x800868D4: sll         $v0, $t2, 1
    ctx->r2 = S32(ctx->r10 << 1);
    // 0x800868D8: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x800868DC: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800868E0: subu        $v0, $v0, $t2
    ctx->r2 = SUB32(ctx->r2, ctx->r10);
    // 0x800868E4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800868E8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800868EC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800868F0: lbu         $v1, -0x2752($at)
    ctx->r3 = MEM_BU(ctx->r1, -0X2752);
    // 0x800868F4: andi        $v0, $t8, 0xFF
    ctx->r2 = ctx->r24 & 0XFF;
    // 0x800868F8: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800868FC: beq         $v0, $zero, L_80086908
    if (ctx->r2 == 0) {
        // 0x80086900: addu        $v0, $t2, $zero
        ctx->r2 = ADD32(ctx->r10, 0);
            goto L_80086908;
    }
    // 0x80086900: addu        $v0, $t2, $zero
    ctx->r2 = ADD32(ctx->r10, 0);
L_80086904:
    // 0x80086904: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80086908:
    // 0x80086908: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x8008690C: jr          $ra
    // 0x80086910: nop

    return;
    // 0x80086910: nop

;}
RECOMP_FUNC void func_80086914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086914: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80086918: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8008691C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80086920: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // 0x80086924: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80086928: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008692C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80086930: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80086934: jal         0x80086594
    // 0x80086938: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80086594(rdram, ctx);
        goto after_0;
    // 0x80086938: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x8008693C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80086940: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x80086944: beq         $s0, $s2, L_800869BC
    if (ctx->r16 == ctx->r18) {
        // 0x80086948: sll         $v0, $s0, 1
        ctx->r2 = S32(ctx->r16 << 1);
            goto L_800869BC;
    }
    // 0x80086948: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x8008694C: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80086950: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80086954: subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x80086958: sll         $s1, $v0, 2
    ctx->r17 = S32(ctx->r2 << 2);
    // 0x8008695C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80086960: addiu       $a0, $a0, -0x2780
    ctx->r4 = ADD32(ctx->r4, -0X2780);
    // 0x80086964: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80086968: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008696C: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x80086970: sb          $v0, -0x26C7($at)
    MEM_B(-0X26C7, ctx->r1) = ctx->r2;
    // 0x80086974: jal         0x800862F4
    // 0x80086978: addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    func_800862F4(rdram, ctx);
        goto after_1;
    // 0x80086978: addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    after_1:
    // 0x8008697C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086980: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x80086984: sw          $s2, -0x271C($at)
    MEM_W(-0X271C, ctx->r1) = ctx->r18;
    // 0x80086988: jal         0x800920FC
    // 0x8008698C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    isAudioSlotActive(rdram, ctx);
        goto after_2;
    // 0x8008698C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80086990: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80086994: beq         $v0, $zero, L_800869A4
    if (ctx->r2 == 0) {
        // 0x80086998: nop
    
            goto L_800869A4;
    }
    // 0x80086998: nop

    // 0x8008699C: jal         0x8009244C
    // 0x800869A0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8009244C(rdram, ctx);
        goto after_3;
    // 0x800869A0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
L_800869A4:
    // 0x800869A4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800869A8: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x800869AC: sw          $zero, -0x2780($at)
    MEM_W(-0X2780, ctx->r1) = 0;
    // 0x800869B0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800869B4: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x800869B8: sb          $zero, -0x2752($at)
    MEM_B(-0X2752, ctx->r1) = 0;
L_800869BC:
    // 0x800869BC: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x800869C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800869C4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800869C8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800869CC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800869D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800869D4: jr          $ra
    // 0x800869D8: nop

    return;
    // 0x800869D8: nop

;}
RECOMP_FUNC void func_800869DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800869DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800869E0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800869E4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800869E8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800869EC: beq         $s0, $v0, L_80086A30
    if (ctx->r16 == ctx->r2) {
        // 0x800869F0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80086A30;
    }
    // 0x800869F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800869F4: jal         0x800920FC
    // 0x800869F8: nop

    isAudioSlotActive(rdram, ctx);
        goto after_0;
    // 0x800869F8: nop

    after_0:
    // 0x800869FC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80086A00: beq         $v0, $zero, L_80086A14
    if (ctx->r2 == 0) {
        // 0x80086A04: sll         $v0, $s0, 1
        ctx->r2 = S32(ctx->r16 << 1);
            goto L_80086A14;
    }
    // 0x80086A04: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x80086A08: jal         0x8009244C
    // 0x80086A0C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8009244C(rdram, ctx);
        goto after_1;
    // 0x80086A0C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80086A10: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
L_80086A14:
    // 0x80086A14: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80086A18: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80086A1C: subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x80086A20: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80086A24: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086A28: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80086A2C: sb          $zero, -0x26C7($at)
    MEM_B(-0X26C7, ctx->r1) = 0;
L_80086A30:
    // 0x80086A30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80086A34: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80086A38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80086A3C: jr          $ra
    // 0x80086A40: nop

    return;
    // 0x80086A40: nop

;}
RECOMP_FUNC void func_80086A44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086A44: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80086A48: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
    // 0x80086A4C: andi        $v0, $v0, 0x800
    ctx->r2 = ctx->r2 & 0X800;
    // 0x80086A50: beq         $v0, $zero, L_80086AC0
    if (ctx->r2 == 0) {
        // 0x80086A54: nop
    
            goto L_80086AC0;
    }
    // 0x80086A54: nop

    // 0x80086A58: lw          $a3, 0x94($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X94);
    // 0x80086A5C: lw          $v1, 0x98($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X98);
    // 0x80086A60: sltu        $v0, $a3, $v1
    ctx->r2 = ctx->r7 < ctx->r3 ? 1 : 0;
    // 0x80086A64: beq         $v0, $zero, L_80086AC0
    if (ctx->r2 == 0) {
        // 0x80086A68: sll         $a0, $a3, 8
        ctx->r4 = S32(ctx->r7 << 8);
            goto L_80086AC0;
    }
    // 0x80086A68: sll         $a0, $a3, 8
    ctx->r4 = S32(ctx->r7 << 8);
    // 0x80086A6C: srl         $v0, $v1, 8
    ctx->r2 = S32(U32(ctx->r3) >> 8);
    // 0x80086A70: divu        $zero, $a0, $v0
    lo = S32(U32(ctx->r4) / U32(ctx->r2)); hi = S32(U32(ctx->r4) % U32(ctx->r2));
    // 0x80086A74: bne         $v0, $zero, L_80086A80
    if (ctx->r2 != 0) {
        // 0x80086A78: nop
    
            goto L_80086A80;
    }
    // 0x80086A78: nop

    // 0x80086A7C: break       7
    do_break(2148035196);
L_80086A80:
    // 0x80086A80: mflo        $a0
    ctx->r4 = lo;
    // 0x80086A84: lhu         $a1, 0x70($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X70);
    // 0x80086A88: nop

    // 0x80086A8C: mult        $a0, $a1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80086A90: mflo        $a1
    ctx->r5 = lo;
    // 0x80086A94: lhu         $v0, 0x9C($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X9C);
    // 0x80086A98: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80086A9C: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80086AA0: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80086AA4: mflo        $v1
    ctx->r3 = lo;
    // 0x80086AA8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80086AAC: lw          $v0, -0x5338($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5338);
    // 0x80086AB0: addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // 0x80086AB4: sw          $v0, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->r2;
    // 0x80086AB8: j           L_80086AC4
    // 0x80086ABC: addu        $v0, $a1, $v1
    ctx->r2 = ADD32(ctx->r5, ctx->r3);
        goto L_80086AC4;
    // 0x80086ABC: addu        $v0, $a1, $v1
    ctx->r2 = ADD32(ctx->r5, ctx->r3);
L_80086AC0:
    // 0x80086AC0: lw          $v0, 0x70($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X70);
L_80086AC4:
    // 0x80086AC4: jr          $ra
    // 0x80086AC8: nop

    return;
    // 0x80086AC8: nop

;}
RECOMP_FUNC void func_80086ACC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086ACC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80086AD0: beql        $a0, $v0, L_80086B28
    if (ctx->r4 == ctx->r2) {
        // 0x80086AD4: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_80086B28;
    }
    goto skip_0;
    // 0x80086AD4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    skip_0:
    // 0x80086AD8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80086ADC: lw          $v1, -0x5100($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5100);
    // 0x80086AE0: beq         $v1, $zero, L_80086B08
    if (ctx->r3 == 0) {
        // 0x80086AE4: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80086B08;
    }
    // 0x80086AE4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80086AE8:
    // 0x80086AE8: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80086AEC: beq         $v0, $a0, L_80086B1C
    if (ctx->r2 == ctx->r4) {
        // 0x80086AF0: sltu        $v0, $a0, $v0
        ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
            goto L_80086B1C;
    }
    // 0x80086AF0: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80086AF4: bne         $v0, $zero, L_80086B08
    if (ctx->r2 != 0) {
        // 0x80086AF8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80086B08;
    }
    // 0x80086AF8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80086AFC: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80086B00: bne         $v1, $zero, L_80086AE8
    if (ctx->r3 != 0) {
        // 0x80086B04: nop
    
            goto L_80086AE8;
    }
    // 0x80086B04: nop

L_80086B08:
    // 0x80086B08: beq         $v0, $zero, L_80086B24
    if (ctx->r2 == 0) {
        // 0x80086B0C: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_80086B24;
    }
    // 0x80086B0C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80086B10: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x80086B14: j           L_80086B28
    // 0x80086B18: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80086B28;
    // 0x80086B18: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80086B1C:
    // 0x80086B1C: j           L_80086B08
    // 0x80086B20: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80086B08;
    // 0x80086B20: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80086B24:
    // 0x80086B24: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80086B28:
    // 0x80086B28: beq         $a0, $v0, L_80086B84
    if (ctx->r4 == ctx->r2) {
        // 0x80086B2C: andi        $v0, $a0, 0xFF
        ctx->r2 = ctx->r4 & 0XFF;
            goto L_80086B84;
    }
    // 0x80086B2C: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80086B30: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80086B34: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80086B38: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80086B3C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80086B40: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80086B44: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086B48: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80086B4C: lw          $v0, -0x271C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X271C);
    // 0x80086B50: bne         $v0, $a0, L_80086B88
    if (ctx->r2 != ctx->r4) {
        // 0x80086B54: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80086B88;
    }
    // 0x80086B54: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80086B58: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086B5C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80086B60: lw          $v0, -0x275C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X275C);
    // 0x80086B64: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80086B68: bne         $v0, $zero, L_80086B88
    if (ctx->r2 != 0) {
        // 0x80086B6C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80086B88;
    }
    // 0x80086B6C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80086B70: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086B74: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80086B78: lhu         $v0, -0x26C2($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X26C2);
    // 0x80086B7C: j           L_80086B88
    // 0x80086B80: nop

        goto L_80086B88;
    // 0x80086B80: nop

L_80086B84:
    // 0x80086B84: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80086B88:
    // 0x80086B88: jr          $ra
    // 0x80086B8C: nop

    return;
    // 0x80086B8C: nop

;}
RECOMP_FUNC void func_80086B90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086B90: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80086B94: lbu         $v0, 0x1AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1AD0);
    // 0x80086B98: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80086B9C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80086BA0: addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // 0x80086BA4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80086BA8: addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // 0x80086BAC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80086BB0: addu        $fp, $a2, $zero
    ctx->r30 = ADD32(ctx->r6, 0);
    // 0x80086BB4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80086BB8: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x80086BBC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80086BC0: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80086BC4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80086BC8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80086BCC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80086BD0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80086BD4: beq         $v0, $zero, L_80086EAC
    if (ctx->r2 == 0) {
        // 0x80086BD8: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80086EAC;
    }
    // 0x80086BD8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80086BDC: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x80086BE0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80086BE4: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80086BE8: addiu       $s1, $s1, -0x2780
    ctx->r17 = ADD32(ctx->r17, -0X2780);
L_80086BEC:
    // 0x80086BEC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086BF0: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80086BF4: lbu         $v1, -0x2732($at)
    ctx->r3 = MEM_BU(ctx->r1, -0X2732);
    // 0x80086BF8: andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // 0x80086BFC: bnel        $v1, $v0, L_80086E94
    if (ctx->r3 != ctx->r2) {
        // 0x80086C00: addiu       $s0, $s0, 0x17C
        ctx->r16 = ADD32(ctx->r16, 0X17C);
            goto L_80086E94;
    }
    goto skip_0;
    // 0x80086C00: addiu       $s0, $s0, 0x17C
    ctx->r16 = ADD32(ctx->r16, 0X17C);
    skip_0:
    // 0x80086C04: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086C08: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80086C0C: lbu         $v1, -0x2731($at)
    ctx->r3 = MEM_BU(ctx->r1, -0X2731);
    // 0x80086C10: andi        $v0, $fp, 0xFF
    ctx->r2 = ctx->r30 & 0XFF;
    // 0x80086C14: bnel        $v1, $v0, L_80086E94
    if (ctx->r3 != ctx->r2) {
        // 0x80086C18: addiu       $s0, $s0, 0x17C
        ctx->r16 = ADD32(ctx->r16, 0X17C);
            goto L_80086E94;
    }
    goto skip_1;
    // 0x80086C18: addiu       $s0, $s0, 0x17C
    ctx->r16 = ADD32(ctx->r16, 0X17C);
    skip_1:
    // 0x80086C1C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086C20: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80086C24: lw          $v1, -0x275C($at)
    ctx->r3 = MEM_W(ctx->r1, -0X275C);
    // 0x80086C28: andi        $v0, $v1, 0x10
    ctx->r2 = ctx->r3 & 0X10;
    // 0x80086C2C: beq         $v0, $zero, L_80086E90
    if (ctx->r2 == 0) {
        // 0x80086C30: andi        $v0, $v1, 0x8
        ctx->r2 = ctx->r3 & 0X8;
            goto L_80086E90;
    }
    // 0x80086C30: andi        $v0, $v1, 0x8
    ctx->r2 = ctx->r3 & 0X8;
    // 0x80086C34: beq         $v0, $zero, L_80086C48
    if (ctx->r2 == 0) {
        // 0x80086C38: lui         $v0, 0x400
        ctx->r2 = S32(0X400 << 16);
            goto L_80086C48;
    }
    // 0x80086C38: lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // 0x80086C3C: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x80086C40: beql        $v0, $zero, L_80086E94
    if (ctx->r2 == 0) {
        // 0x80086C44: addiu       $s0, $s0, 0x17C
        ctx->r16 = ADD32(ctx->r16, 0X17C);
            goto L_80086E94;
    }
    goto skip_2;
    // 0x80086C44: addiu       $s0, $s0, 0x17C
    ctx->r16 = ADD32(ctx->r16, 0X17C);
    skip_2:
L_80086C48:
    // 0x80086C48: jal         0x800920FC
    // 0x80086C4C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    isAudioSlotActive(rdram, ctx);
        goto after_0;
    // 0x80086C4C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_0:
    // 0x80086C50: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80086C54: beql        $v0, $zero, L_80086E94
    if (ctx->r2 == 0) {
        // 0x80086C58: addiu       $s0, $s0, 0x17C
        ctx->r16 = ADD32(ctx->r16, 0X17C);
            goto L_80086E94;
    }
    goto skip_3;
    // 0x80086C58: addiu       $s0, $s0, 0x17C
    ctx->r16 = ADD32(ctx->r16, 0X17C);
    skip_3:
    // 0x80086C5C: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x80086C60: andi        $v0, $v0, 0x800
    ctx->r2 = ctx->r2 & 0X800;
    // 0x80086C64: beq         $v0, $zero, L_80086CD4
    if (ctx->r2 == 0) {
        // 0x80086C68: nop
    
            goto L_80086CD4;
    }
    // 0x80086C68: nop

    // 0x80086C6C: lw          $a2, 0x94($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X94);
    // 0x80086C70: lw          $v1, 0x98($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X98);
    // 0x80086C74: sltu        $v0, $a2, $v1
    ctx->r2 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x80086C78: beq         $v0, $zero, L_80086CD4
    if (ctx->r2 == 0) {
        // 0x80086C7C: srl         $v0, $v1, 8
        ctx->r2 = S32(U32(ctx->r3) >> 8);
            goto L_80086CD4;
    }
    // 0x80086C7C: srl         $v0, $v1, 8
    ctx->r2 = S32(U32(ctx->r3) >> 8);
    // 0x80086C80: sll         $a0, $a2, 8
    ctx->r4 = S32(ctx->r6 << 8);
    // 0x80086C84: divu        $zero, $a0, $v0
    lo = S32(U32(ctx->r4) / U32(ctx->r2)); hi = S32(U32(ctx->r4) % U32(ctx->r2));
    // 0x80086C88: bne         $v0, $zero, L_80086C94
    if (ctx->r2 != 0) {
        // 0x80086C8C: nop
    
            goto L_80086C94;
    }
    // 0x80086C8C: nop

    // 0x80086C90: break       7
    do_break(2148035728);
L_80086C94:
    // 0x80086C94: mflo        $a0
    ctx->r4 = lo;
    // 0x80086C98: lhu         $a1, 0x70($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X70);
    // 0x80086C9C: nop

    // 0x80086CA0: mult        $a0, $a1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80086CA4: mflo        $a1
    ctx->r5 = lo;
    // 0x80086CA8: lhu         $v0, 0x9C($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X9C);
    // 0x80086CAC: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80086CB0: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80086CB4: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80086CB8: mflo        $v1
    ctx->r3 = lo;
    // 0x80086CBC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80086CC0: lw          $v0, -0x5338($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5338);
    // 0x80086CC4: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80086CC8: sw          $v0, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->r2;
    // 0x80086CCC: j           L_80086CD8
    // 0x80086CD0: addu        $a2, $a1, $v1
    ctx->r6 = ADD32(ctx->r5, ctx->r3);
        goto L_80086CD8;
    // 0x80086CD0: addu        $a2, $a1, $v1
    ctx->r6 = ADD32(ctx->r5, ctx->r3);
L_80086CD4:
    // 0x80086CD4: lw          $a2, 0x70($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X70);
L_80086CD8:
    // 0x80086CD8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086CDC: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80086CE0: lhu         $v0, -0x272C($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X272C);
    // 0x80086CE4: andi        $v1, $s7, 0xFF
    ctx->r3 = ctx->r23 & 0XFF;
    // 0x80086CE8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086CEC: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80086CF0: sh          $v1, -0x272C($at)
    MEM_H(-0X272C, ctx->r1) = ctx->r3;
    // 0x80086CF4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086CF8: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80086CFC: lbu         $a0, -0x272B($at)
    ctx->r4 = MEM_BU(ctx->r1, -0X272B);
    // 0x80086D00: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086D04: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80086D08: lw          $a1, -0x2720($at)
    ctx->r5 = MEM_W(ctx->r1, -0X2720);
    // 0x80086D0C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086D10: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80086D14: sw          $a2, -0x26E4($at)
    MEM_W(-0X26E4, ctx->r1) = ctx->r6;
    // 0x80086D18: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086D1C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80086D20: sw          $zero, -0x26EC($at)
    MEM_W(-0X26EC, ctx->r1) = 0;
    // 0x80086D24: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086D28: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80086D2C: sb          $v0, -0x26C3($at)
    MEM_B(-0X26C3, ctx->r1) = ctx->r2;
    // 0x80086D30: jal         0x80093E80
    // 0x80086D34: nop

    musyxComputeNotePlaybackRate(rdram, ctx);
        goto after_1;
    // 0x80086D34: nop

    after_1:
    // 0x80086D38: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80086D3C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086D40: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80086D44: sw          $v0, -0x2710($at)
    MEM_W(-0X2710, ctx->r1) = ctx->r2;
    // 0x80086D48: jal         0x800862F4
    // 0x80086D4C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800862F4(rdram, ctx);
        goto after_2;
    // 0x80086D4C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
    // 0x80086D50: bne         $s2, $s5, L_80086E4C
    if (ctx->r18 != ctx->r21) {
        // 0x80086D54: andi        $v0, $s4, 0xFF
        ctx->r2 = ctx->r20 & 0XFF;
            goto L_80086E4C;
    }
    // 0x80086D54: andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
    // 0x80086D58: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x80086D5C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086D60: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80086D64: sw          $s2, -0x2770($at)
    MEM_W(-0X2770, ctx->r1) = ctx->r18;
    // 0x80086D68: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086D6C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80086D70: sw          $s2, -0x276C($at)
    MEM_W(-0X276C, ctx->r1) = ctx->r18;
L_80086D74:
    // 0x80086D74: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80086D78: lw          $v1, -0x5308($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5308);
    // 0x80086D7C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80086D80: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086D84: sw          $v0, -0x5308($at)
    MEM_W(-0X5308, ctx->r1) = ctx->r2;
    // 0x80086D88: beq         $v1, $s5, L_80086D74
    if (ctx->r3 == ctx->r21) {
        // 0x80086D8C: addu        $a2, $v1, $zero
        ctx->r6 = ADD32(ctx->r3, 0);
            goto L_80086D74;
    }
    // 0x80086D8C: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x80086D90: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80086D94: lw          $a0, -0x5100($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5100);
    // 0x80086D98: beq         $a0, $zero, L_80086DE8
    if (ctx->r4 == 0) {
        // 0x80086D9C: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80086DE8;
    }
    // 0x80086D9C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80086DA0:
    // 0x80086DA0: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x80086DA4: sltu        $v0, $a2, $v1
    ctx->r2 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x80086DA8: bne         $v0, $zero, L_80086DE8
    if (ctx->r2 != 0) {
        // 0x80086DAC: nop
    
            goto L_80086DE8;
    }
    // 0x80086DAC: nop

    // 0x80086DB0: bnel        $v1, $a2, L_80086DDC
    if (ctx->r3 != ctx->r6) {
        // 0x80086DB4: addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
            goto L_80086DDC;
    }
    goto skip_4;
    // 0x80086DB4: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    skip_4:
L_80086DB8:
    // 0x80086DB8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80086DBC: lw          $v1, -0x5308($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5308);
    // 0x80086DC0: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80086DC4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086DC8: sw          $v0, -0x5308($at)
    MEM_W(-0X5308, ctx->r1) = ctx->r2;
    // 0x80086DCC: beq         $v1, $s5, L_80086DB8
    if (ctx->r3 == ctx->r21) {
        // 0x80086DD0: nop
    
            goto L_80086DB8;
    }
    // 0x80086DD0: nop

    // 0x80086DD4: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x80086DD8: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
L_80086DDC:
    // 0x80086DDC: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80086DE0: bne         $a0, $zero, L_80086DA0
    if (ctx->r4 != 0) {
        // 0x80086DE4: nop
    
            goto L_80086DA0;
    }
    // 0x80086DE4: nop

L_80086DE8:
    // 0x80086DE8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80086DEC: lw          $v1, -0x50FC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X50FC);
    // 0x80086DF0: beq         $v1, $zero, L_80086E84
    if (ctx->r3 == 0) {
        // 0x80086DF4: addiu       $s2, $zero, -0x1
        ctx->r18 = ADD32(0, -0X1);
            goto L_80086E84;
    }
    // 0x80086DF4: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x80086DF8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80086DFC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086E00: sw          $v0, -0x50FC($at)
    MEM_W(-0X50FC, ctx->r1) = ctx->r2;
    // 0x80086E04: bnel        $v0, $zero, L_80086E0C
    if (ctx->r2 != 0) {
        // 0x80086E08: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_80086E0C;
    }
    goto skip_5;
    // 0x80086E08: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_5:
L_80086E0C:
    // 0x80086E0C: bnel        $a1, $zero, L_80086E24
    if (ctx->r5 != 0) {
        // 0x80086E10: sw          $v1, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r3;
            goto L_80086E24;
    }
    goto skip_6;
    // 0x80086E10: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    skip_6:
    // 0x80086E14: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086E18: sw          $v1, -0x5100($at)
    MEM_W(-0X5100, ctx->r1) = ctx->r3;
    // 0x80086E1C: j           L_80086E28
    // 0x80086E20: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
        goto L_80086E28;
    // 0x80086E20: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
L_80086E24:
    // 0x80086E24: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
L_80086E28:
    // 0x80086E28: beq         $a0, $zero, L_80086E34
    if (ctx->r4 == 0) {
        // 0x80086E2C: sw          $a0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r4;
            goto L_80086E34;
    }
    // 0x80086E2C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80086E30: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
L_80086E34:
    // 0x80086E34: sw          $a2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r6;
    // 0x80086E38: lw          $v0, 0x64($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X64);
    // 0x80086E3C: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x80086E40: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x80086E44: j           L_80086E84
    // 0x80086E48: sw          $v1, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r3;
        goto L_80086E84;
    // 0x80086E48: sw          $v1, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r3;
L_80086E4C:
    // 0x80086E4C: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80086E50: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80086E54: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80086E58: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086E5C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80086E60: lw          $a0, -0x271C($at)
    ctx->r4 = MEM_W(ctx->r1, -0X271C);
    // 0x80086E64: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80086E68: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80086E6C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086E70: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80086E74: sw          $a0, -0x2770($at)
    MEM_W(-0X2770, ctx->r1) = ctx->r4;
    // 0x80086E78: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086E7C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80086E80: sw          $s4, -0x276C($at)
    MEM_W(-0X276C, ctx->r1) = ctx->r20;
L_80086E84:
    // 0x80086E84: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086E88: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80086E8C: lw          $s4, -0x271C($at)
    ctx->r20 = MEM_W(ctx->r1, -0X271C);
L_80086E90:
    // 0x80086E90: addiu       $s0, $s0, 0x17C
    ctx->r16 = ADD32(ctx->r16, 0X17C);
L_80086E94:
    // 0x80086E94: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80086E98: lbu         $v0, 0x1AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1AD0);
    // 0x80086E9C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80086EA0: sltu        $v0, $s3, $v0
    ctx->r2 = ctx->r19 < ctx->r2 ? 1 : 0;
    // 0x80086EA4: bne         $v0, $zero, L_80086BEC
    if (ctx->r2 != 0) {
        // 0x80086EA8: addiu       $s1, $s1, 0x17C
        ctx->r17 = ADD32(ctx->r17, 0X17C);
            goto L_80086BEC;
    }
    // 0x80086EA8: addiu       $s1, $s1, 0x17C
    ctx->r17 = ADD32(ctx->r17, 0X17C);
L_80086EAC:
    // 0x80086EAC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80086EB0: beq         $s2, $v0, L_80086F0C
    if (ctx->r18 == ctx->r2) {
        // 0x80086EB4: sll         $v0, $s3, 1
        ctx->r2 = S32(ctx->r19 << 1);
            goto L_80086F0C;
    }
    // 0x80086EB4: sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19 << 1);
    // 0x80086EB8: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80086EBC: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80086EC0: subu        $v0, $v0, $s3
    ctx->r2 = SUB32(ctx->r2, ctx->r19);
    // 0x80086EC4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80086EC8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086ECC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80086ED0: lbu         $v1, -0x2731($at)
    ctx->r3 = MEM_BU(ctx->r1, -0X2731);
    // 0x80086ED4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80086ED8: beq         $v1, $v0, L_80086EFC
    if (ctx->r3 == ctx->r2) {
        // 0x80086EDC: sll         $v1, $v1, 4
        ctx->r3 = S32(ctx->r3 << 4);
            goto L_80086EFC;
    }
    // 0x80086EDC: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80086EE0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80086EE4: addiu       $v0, $v0, 0x2040
    ctx->r2 = ADD32(ctx->r2, 0X2040);
    // 0x80086EE8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80086EEC: andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // 0x80086EF0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80086EF4: j           L_80086F0C
    // 0x80086EF8: sb          $s7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r23;
        goto L_80086F0C;
    // 0x80086EF8: sb          $s7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r23;
L_80086EFC:
    // 0x80086EFC: andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // 0x80086F00: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086F04: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80086F08: sb          $s7, -0x3BA0($at)
    MEM_B(-0X3BA0, ctx->r1) = ctx->r23;
L_80086F0C:
    // 0x80086F0C: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x80086F10: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80086F14: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80086F18: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80086F1C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80086F20: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80086F24: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80086F28: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80086F2C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80086F30: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80086F34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80086F38: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80086F3C: jr          $ra
    // 0x80086F40: nop

    return;
    // 0x80086F40: nop

;}
RECOMP_FUNC void func_80086F44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80086F48: andi        $a3, $a1, 0xFF
    ctx->r7 = ctx->r5 & 0XFF;
    // 0x80086F4C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80086F50: beq         $a3, $v1, L_80086FB0
    if (ctx->r7 == ctx->r3) {
        // 0x80086F54: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80086FB0;
    }
    // 0x80086F54: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80086F58: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x80086F5C: beq         $v0, $v1, L_80086F80
    if (ctx->r2 == ctx->r3) {
        // 0x80086F60: sll         $v0, $v0, 4
        ctx->r2 = S32(ctx->r2 << 4);
            goto L_80086F80;
    }
    // 0x80086F60: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80086F64: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80086F68: addiu       $v1, $v1, -0x7C30
    ctx->r3 = ADD32(ctx->r3, -0X7C30);
    // 0x80086F6C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80086F70: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80086F74: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80086F78: j           L_80086F8C
    // 0x80086F7C: nop

        goto L_80086F8C;
    // 0x80086F7C: nop

L_80086F80:
    // 0x80086F80: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80086F84: addu        $at, $at, $a3
    ctx->r1 = ADD32(ctx->r1, ctx->r7);
    // 0x80086F88: lbu         $v0, 0x2018($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X2018);
L_80086F8C:
    // 0x80086F8C: beq         $v0, $zero, L_80086FB0
    if (ctx->r2 == 0) {
        // 0x80086F90: andi        $a0, $a0, 0x7F
        ctx->r4 = ctx->r4 & 0X7F;
            goto L_80086FB0;
    }
    // 0x80086F90: andi        $a0, $a0, 0x7F
    ctx->r4 = ctx->r4 & 0X7F;
    // 0x80086F94: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80086F98: jal         0x80086B90
    // 0x80086F9C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    func_80086B90(rdram, ctx);
        goto after_0;
    // 0x80086F9C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_0:
    // 0x80086FA0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80086FA4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80086FA8: bne         $v1, $v0, L_80086FB4
    if (ctx->r3 != ctx->r2) {
        // 0x80086FAC: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_80086FB4;
    }
    // 0x80086FAC: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80086FB0:
    // 0x80086FB0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80086FB4:
    // 0x80086FB4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80086FB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80086FBC: jr          $ra
    // 0x80086FC0: nop

    return;
    // 0x80086FC0: nop

;}
RECOMP_FUNC void func_80086FC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086FC4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80086FC8: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x80086FCC: srl         $t1, $v0, 8
    ctx->r9 = S32(U32(ctx->r2) >> 8);
    // 0x80086FD0: sb          $t1, 0x47($sp)
    MEM_B(0X47, ctx->r29) = ctx->r9;
    // 0x80086FD4: lbu         $t1, 0x83($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X83);
    // 0x80086FD8: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80086FDC: lbu         $s6, 0x87($sp)
    ctx->r22 = MEM_BU(ctx->r29, 0X87);
    // 0x80086FE0: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80086FE4: lbu         $s7, 0x8B($sp)
    ctx->r23 = MEM_BU(ctx->r29, 0X8B);
    // 0x80086FE8: sb          $t1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r9;
    // 0x80086FEC: lhu         $t1, 0x8E($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X8E);
    // 0x80086FF0: sh          $t1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r9;
    // 0x80086FF4: lhu         $t1, 0x92($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X92);
    // 0x80086FF8: sh          $t1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r9;
    // 0x80086FFC: lbu         $t1, 0x97($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X97);
    // 0x80087000: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80087004: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x80087008: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8008700C: addu        $s4, $s2, $zero
    ctx->r20 = ADD32(ctx->r18, 0);
    // 0x80087010: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80087014: sb          $t1, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r9;
    // 0x80087018: lbu         $t1, 0x9B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X9B);
    // 0x8008701C: srl         $s5, $v0, 16
    ctx->r21 = S32(U32(ctx->r2) >> 16);
    // 0x80087020: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x80087024: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80087028: addu        $fp, $a1, $zero
    ctx->r30 = ADD32(ctx->r5, 0);
    // 0x8008702C: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80087030: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80087034: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80087038: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8008703C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80087040: sb          $a3, 0x17($sp)
    MEM_B(0X17, ctx->r29) = ctx->r7;
    // 0x80087044: jal         0x80085CE8
    // 0x80087048: sb          $t1, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r9;
    func_80085CE8(rdram, ctx);
        goto after_0;
    // 0x80087048: sb          $t1, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r9;
    after_0:
    // 0x8008704C: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80087050: beq         $s3, $zero, L_8008739C
    if (ctx->r19 == 0) {
        // 0x80087054: andi        $a1, $s0, 0xFF
        ctx->r5 = ctx->r16 & 0XFF;
            goto L_8008739C;
    }
    // 0x80087054: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // 0x80087058: lbu         $a0, 0x47($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X47);
    // 0x8008705C: andi        $a3, $s4, 0xFF
    ctx->r7 = ctx->r20 & 0XFF;
    // 0x80087060: andi        $a2, $fp, 0xFFFF
    ctx->r6 = ctx->r30 & 0XFFFF;
    // 0x80087064: jal         0x80086594
    // 0x80087068: srl         $a3, $a3, 7
    ctx->r7 = S32(U32(ctx->r7) >> 7);
    func_80086594(rdram, ctx);
        goto after_1;
    // 0x80087068: srl         $a3, $a3, 7
    ctx->r7 = S32(U32(ctx->r7) >> 7);
    after_1:
    // 0x8008706C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80087070: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80087074: beq         $s1, $v0, L_8008739C
    if (ctx->r17 == ctx->r2) {
        // 0x80087078: sll         $v0, $s1, 1
        ctx->r2 = S32(ctx->r17 << 1);
            goto L_8008739C;
    }
    // 0x80087078: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
    // 0x8008707C: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80087080: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80087084: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x80087088: sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2 << 2);
    // 0x8008708C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80087090: addiu       $a0, $a0, -0x2780
    ctx->r4 = ADD32(ctx->r4, -0X2780);
    // 0x80087094: jal         0x800862F4
    // 0x80087098: addu        $a0, $s0, $a0
    ctx->r4 = ADD32(ctx->r16, ctx->r4);
    func_800862F4(rdram, ctx);
        goto after_2;
    // 0x80087098: addu        $a0, $s0, $a0
    ctx->r4 = ADD32(ctx->r16, ctx->r4);
    after_2:
    // 0x8008709C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800870A0: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x800870A4: lw          $v0, -0x275C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X275C);
    // 0x800870A8: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800870AC: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // 0x800870B0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800870B4: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x800870B8: sw          $v0, -0x275C($at)
    MEM_W(-0X275C, ctx->r1) = ctx->r2;
    // 0x800870BC: jal         0x800920FC
    // 0x800870C0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    isAudioSlotActive(rdram, ctx);
        goto after_3;
    // 0x800870C0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_3:
    // 0x800870C4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800870C8: beq         $v0, $zero, L_800870EC
    if (ctx->r2 == 0) {
        // 0x800870CC: nop
    
            goto L_800870EC;
    }
    // 0x800870CC: nop

    // 0x800870D0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800870D4: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x800870D8: lw          $v0, -0x275C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X275C);
    // 0x800870DC: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x800870E0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800870E4: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x800870E8: sw          $v0, -0x275C($at)
    MEM_W(-0X275C, ctx->r1) = ctx->r2;
L_800870EC:
    // 0x800870EC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800870F0: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x800870F4: sw          $zero, -0x2740($at)
    MEM_W(-0X2740, ctx->r1) = 0;
    // 0x800870F8: andi        $v0, $s2, 0x80
    ctx->r2 = ctx->r18 & 0X80;
    // 0x800870FC: beq         $v0, $zero, L_80087144
    if (ctx->r2 == 0) {
        // 0x80087100: andi        $a0, $s1, 0xFF
        ctx->r4 = ctx->r17 & 0XFF;
            goto L_80087144;
    }
    // 0x80087100: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x80087104: andi        $s4, $s2, 0x7F
    ctx->r20 = ctx->r18 & 0X7F;
    // 0x80087108: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008710C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80087110: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80087114: sb          $v0, -0x2730($at)
    MEM_B(-0X2730, ctx->r1) = ctx->r2;
    // 0x80087118: jal         0x80083F3C
    // 0x8008711C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    func_80083F3C(rdram, ctx);
        goto after_4;
    // 0x8008711C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_4:
    // 0x80087120: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80087124: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80087128: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008712C: sb          $s1, -0x2728($at)
    MEM_B(-0X2728, ctx->r1) = ctx->r17;
    // 0x80087130: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80087134: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80087138: sb          $v0, -0x2727($at)
    MEM_B(-0X2727, ctx->r1) = ctx->r2;
    // 0x8008713C: j           L_8008716C
    // 0x80087140: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
        goto L_8008716C;
    // 0x80087140: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
L_80087144:
    // 0x80087144: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80087148: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008714C: sb          $zero, -0x2730($at)
    MEM_B(-0X2730, ctx->r1) = 0;
    // 0x80087150: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80087154: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80087158: sb          $s6, -0x2728($at)
    MEM_B(-0X2728, ctx->r1) = ctx->r22;
    // 0x8008715C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80087160: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80087164: sb          $s7, -0x2727($at)
    MEM_B(-0X2727, ctx->r1) = ctx->r23;
    // 0x80087168: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
L_8008716C:
    // 0x8008716C: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80087170: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80087174: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x80087178: lbu         $t1, 0x47($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X47);
    // 0x8008717C: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x80087180: lui         $v0, 0xEA60
    ctx->r2 = S32(0XEA60 << 16);
    // 0x80087184: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80087188: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008718C: sb          $t1, -0x2752($at)
    MEM_B(-0X2752, ctx->r1) = ctx->r9;
    // 0x80087190: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80087194: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80087198: sw          $v0, -0x2758($at)
    MEM_W(-0X2758, ctx->r1) = ctx->r2;
    // 0x8008719C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x800871A0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800871A4: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800871A8: sh          $s5, -0x2718($at)
    MEM_H(-0X2718, ctx->r1) = ctx->r21;
    // 0x800871AC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800871B0: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800871B4: sh          $fp, -0x26CA($at)
    MEM_H(-0X26CA, ctx->r1) = ctx->r30;
    // 0x800871B8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800871BC: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800871C0: sh          $v0, -0x2754($at)
    MEM_H(-0X2754, ctx->r1) = ctx->r2;
    // 0x800871C4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800871C8: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800871CC: sw          $s3, -0x2780($at)
    MEM_W(-0X2780, ctx->r1) = ctx->r19;
    // 0x800871D0: lhu         $t1, 0x26($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X26);
    // 0x800871D4: sll         $v0, $t1, 3
    ctx->r2 = S32(ctx->r9 << 3);
    // 0x800871D8: addu        $v0, $s3, $v0
    ctx->r2 = ADD32(ctx->r19, ctx->r2);
    // 0x800871DC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800871E0: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800871E4: sw          $v0, -0x277C($at)
    MEM_W(-0X277C, ctx->r1) = ctx->r2;
    // 0x800871E8: andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
    // 0x800871EC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800871F0: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800871F4: sh          $v0, -0x272E($at)
    MEM_H(-0X272E, ctx->r1) = ctx->r2;
    // 0x800871F8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800871FC: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80087200: sh          $v0, -0x272C($at)
    MEM_H(-0X272C, ctx->r1) = ctx->r2;
    // 0x80087204: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80087208: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008720C: sb          $zero, -0x26C4($at)
    MEM_B(-0X26C4, ctx->r1) = 0;
    // 0x80087210: lbu         $t1, 0x17($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X17);
    // 0x80087214: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80087218: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008721C: sb          $t1, -0x272A($at)
    MEM_B(-0X272A, ctx->r1) = ctx->r9;
    // 0x80087220: lbu         $t1, 0x1F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1F);
    // 0x80087224: sll         $v1, $s5, 16
    ctx->r3 = S32(ctx->r21 << 16);
    // 0x80087228: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008722C: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80087230: sb          $t1, -0x2729($at)
    MEM_B(-0X2729, ctx->r1) = ctx->r9;
    // 0x80087234: lbu         $t1, 0x2F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X2F);
    // 0x80087238: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8008723C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80087240: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80087244: sw          $v0, -0x2770($at)
    MEM_W(-0X2770, ctx->r1) = ctx->r2;
    // 0x80087248: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008724C: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80087250: sw          $v0, -0x276C($at)
    MEM_W(-0X276C, ctx->r1) = ctx->r2;
    // 0x80087254: andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
    // 0x80087258: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8008725C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80087260: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80087264: sw          $zero, -0x2778($at)
    MEM_W(-0X2778, ctx->r1) = 0;
    // 0x80087268: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008726C: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80087270: sb          $t1, -0x2726($at)
    MEM_B(-0X2726, ctx->r1) = ctx->r9;
    // 0x80087274: lbu         $t1, 0x3F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X3F);
    // 0x80087278: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8008727C: or          $v0, $v1, $s1
    ctx->r2 = ctx->r3 | ctx->r17;
    // 0x80087280: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80087284: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80087288: sb          $t1, -0x26C5($at)
    MEM_B(-0X26C5, ctx->r1) = ctx->r9;
    // 0x8008728C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80087290: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80087294: sw          $v0, -0x271C($at)
    MEM_W(-0X271C, ctx->r1) = ctx->r2;
    // 0x80087298: lbu         $t1, 0x37($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X37);
    // 0x8008729C: beq         $t1, $zero, L_800873A0
    if (ctx->r9 == 0) {
        // 0x800872A0: nop
    
            goto L_800873A0;
    }
    // 0x800872A0: nop

    // 0x800872A4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800872A8: addiu       $v0, $v0, -0x2780
    ctx->r2 = ADD32(ctx->r2, -0X2780);
    // 0x800872AC: addu        $t0, $a0, $v0
    ctx->r8 = ADD32(ctx->r4, ctx->r2);
    // 0x800872B0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_800872B4:
    // 0x800872B4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800872B8: lw          $v1, -0x5308($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5308);
    // 0x800872BC: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800872C0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800872C4: sw          $v0, -0x5308($at)
    MEM_W(-0X5308, ctx->r1) = ctx->r2;
    // 0x800872C8: beq         $v1, $a0, L_800872B4
    if (ctx->r3 == ctx->r4) {
        // 0x800872CC: addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
            goto L_800872B4;
    }
    // 0x800872CC: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x800872D0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800872D4: lw          $a0, -0x5100($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5100);
    // 0x800872D8: beq         $a0, $zero, L_8008732C
    if (ctx->r4 == 0) {
        // 0x800872DC: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_8008732C;
    }
    // 0x800872DC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800872E0: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_800872E4:
    // 0x800872E4: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x800872E8: sltu        $v0, $a1, $v1
    ctx->r2 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x800872EC: bne         $v0, $zero, L_8008732C
    if (ctx->r2 != 0) {
        // 0x800872F0: nop
    
            goto L_8008732C;
    }
    // 0x800872F0: nop

    // 0x800872F4: bnel        $v1, $a1, L_80087320
    if (ctx->r3 != ctx->r5) {
        // 0x800872F8: addu        $a2, $a0, $zero
        ctx->r6 = ADD32(ctx->r4, 0);
            goto L_80087320;
    }
    goto skip_0;
    // 0x800872F8: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    skip_0:
L_800872FC:
    // 0x800872FC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80087300: lw          $v1, -0x5308($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5308);
    // 0x80087304: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80087308: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008730C: sw          $v0, -0x5308($at)
    MEM_W(-0X5308, ctx->r1) = ctx->r2;
    // 0x80087310: beq         $v1, $a3, L_800872FC
    if (ctx->r3 == ctx->r7) {
        // 0x80087314: nop
    
            goto L_800872FC;
    }
    // 0x80087314: nop

    // 0x80087318: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x8008731C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
L_80087320:
    // 0x80087320: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80087324: bne         $a0, $zero, L_800872E4
    if (ctx->r4 != 0) {
        // 0x80087328: nop
    
            goto L_800872E4;
    }
    // 0x80087328: nop

L_8008732C:
    // 0x8008732C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80087330: lw          $v1, -0x50FC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X50FC);
    // 0x80087334: bne         $v1, $zero, L_80087344
    if (ctx->r3 != 0) {
        // 0x80087338: nop
    
            goto L_80087344;
    }
    // 0x80087338: nop

    // 0x8008733C: j           L_80087394
    // 0x80087340: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80087394;
    // 0x80087340: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_80087344:
    // 0x80087344: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80087348: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008734C: sw          $v0, -0x50FC($at)
    MEM_W(-0X50FC, ctx->r1) = ctx->r2;
    // 0x80087350: bnel        $v0, $zero, L_80087358
    if (ctx->r2 != 0) {
        // 0x80087354: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_80087358;
    }
    goto skip_1;
    // 0x80087354: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_1:
L_80087358:
    // 0x80087358: bnel        $a2, $zero, L_80087370
    if (ctx->r6 != 0) {
        // 0x8008735C: sw          $v1, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r3;
            goto L_80087370;
    }
    goto skip_2;
    // 0x8008735C: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    skip_2:
    // 0x80087360: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80087364: sw          $v1, -0x5100($at)
    MEM_W(-0X5100, ctx->r1) = ctx->r3;
    // 0x80087368: j           L_80087374
    // 0x8008736C: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
        goto L_80087374;
    // 0x8008736C: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
L_80087370:
    // 0x80087370: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
L_80087374:
    // 0x80087374: beq         $a0, $zero, L_80087380
    if (ctx->r4 == 0) {
        // 0x80087378: sw          $a0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r4;
            goto L_80087380;
    }
    // 0x80087378: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8008737C: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
L_80087380:
    // 0x80087380: sw          $a1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r5;
    // 0x80087384: lw          $v0, 0x64($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X64);
    // 0x80087388: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x8008738C: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x80087390: sw          $v1, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r3;
L_80087394:
    // 0x80087394: j           L_800873A0
    // 0x80087398: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
        goto L_800873A0;
    // 0x80087398: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
L_8008739C:
    // 0x8008739C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800873A0:
    // 0x800873A0: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x800873A4: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x800873A8: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x800873AC: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x800873B0: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x800873B4: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800873B8: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800873BC: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800873C0: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800873C4: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800873C8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x800873CC: jr          $ra
    // 0x800873D0: nop

    return;
    // 0x800873D0: nop

;}
RECOMP_FUNC void func_800873D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800873D4: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x800873D8: lbu         $t1, 0xE3($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XE3);
    // 0x800873DC: sb          $t1, 0x5F($sp)
    MEM_B(0X5F, ctx->r29) = ctx->r9;
    // 0x800873E0: lbu         $t1, 0xE7($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XE7);
    // 0x800873E4: sb          $t1, 0x67($sp)
    MEM_B(0X67, ctx->r29) = ctx->r9;
    // 0x800873E8: lbu         $t1, 0xEB($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XEB);
    // 0x800873EC: sb          $t1, 0x6F($sp)
    MEM_B(0X6F, ctx->r29) = ctx->r9;
    // 0x800873F0: lhu         $t1, 0xEE($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0XEE);
    // 0x800873F4: sh          $t1, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r9;
    // 0x800873F8: lhu         $t1, 0xF2($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0XF2);
    // 0x800873FC: sh          $t1, 0x7E($sp)
    MEM_H(0X7E, ctx->r29) = ctx->r9;
    // 0x80087400: lbu         $t1, 0xF7($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XF7);
    // 0x80087404: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    // 0x80087408: srl         $v0, $a0, 16
    ctx->r2 = S32(U32(ctx->r4) >> 16);
    // 0x8008740C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80087410: sh          $v0, -0x5384($at)
    MEM_H(-0X5384, ctx->r1) = ctx->r2;
    // 0x80087414: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80087418: lw          $v0, -0x50F8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X50F8);
    // 0x8008741C: sw          $s6, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r22;
    // 0x80087420: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x80087424: sw          $fp, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r30;
    // 0x80087428: lui         $fp, 0x8015
    ctx->r30 = S32(0X8015 << 16);
    // 0x8008742C: addiu       $fp, $fp, -0x7BB0
    ctx->r30 = ADD32(ctx->r30, -0X7BB0);
    // 0x80087430: sw          $s7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r23;
    // 0x80087434: addiu       $s7, $zero, 0x8
    ctx->r23 = ADD32(0, 0X8);
    // 0x80087438: sw          $ra, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r31;
    // 0x8008743C: sw          $s5, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r21;
    // 0x80087440: sw          $s4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r20;
    // 0x80087444: sw          $s3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r19;
    // 0x80087448: sw          $s2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r18;
    // 0x8008744C: sw          $s1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r17;
    // 0x80087450: sw          $s0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r16;
    // 0x80087454: sh          $a1, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r5;
    // 0x80087458: sb          $a2, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r6;
    // 0x8008745C: sb          $a3, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r7;
    // 0x80087460: sb          $t1, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r9;
    // 0x80087464: addiu       $t1, $sp, 0x30
    ctx->r9 = ADD32(ctx->r29, 0X30);
    // 0x80087468: beq         $v0, $zero, L_800874C0
    if (ctx->r2 == 0) {
        // 0x8008746C: sw          $t1, 0x8C($sp)
        MEM_W(0X8C, ctx->r29) = ctx->r9;
            goto L_800874C0;
    }
    // 0x8008746C: sw          $t1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r9;
    // 0x80087470: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80087474: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80087478: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_8008747C:
    // 0x8008747C: sra         $s2, $v0, 1
    ctx->r18 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80087480: addiu       $s1, $s2, -0x1
    ctx->r17 = ADD32(ctx->r18, -0X1);
    // 0x80087484: mult        $s7, $s1
    result = S64(S32(ctx->r23)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80087488: mflo        $v0
    ctx->r2 = lo;
    // 0x8008748C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80087490: addiu       $a0, $a0, -0x5388
    ctx->r4 = ADD32(ctx->r4, -0X5388);
    // 0x80087494: addu        $s0, $fp, $v0
    ctx->r16 = ADD32(ctx->r30, ctx->r2);
    // 0x80087498: jal         0x80086114
    // 0x8008749C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    compareHalfwordAtOffset4_v3(rdram, ctx);
        goto after_0;
    // 0x8008749C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x800874A0: beql        $v0, $zero, L_800874C4
    if (ctx->r2 == 0) {
        // 0x800874A4: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_800874C4;
    }
    goto skip_0;
    // 0x800874A4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    skip_0:
    // 0x800874A8: bgezl       $v0, L_800874B4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800874AC: addiu       $s4, $s2, 0x1
        ctx->r20 = ADD32(ctx->r18, 0X1);
            goto L_800874B4;
    }
    goto skip_1;
    // 0x800874AC: addiu       $s4, $s2, 0x1
    ctx->r20 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x800874B0: addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
L_800874B4:
    // 0x800874B4: slt         $v0, $s3, $s4
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800874B8: beq         $v0, $zero, L_8008747C
    if (ctx->r2 == 0) {
        // 0x800874BC: addu        $v0, $s4, $s3
        ctx->r2 = ADD32(ctx->r20, ctx->r19);
            goto L_8008747C;
    }
    // 0x800874BC: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_800874C0:
    // 0x800874C0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_800874C4:
    // 0x800874C4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800874C8: sw          $a1, -0x5380($at)
    MEM_W(-0X5380, ctx->r1) = ctx->r5;
    // 0x800874CC: beq         $a1, $zero, L_800874EC
    if (ctx->r5 == 0) {
        // 0x800874D0: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800874EC;
    }
    // 0x800874D0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800874D4: lhu         $v0, 0x6($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X6);
    // 0x800874D8: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x800874DC: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    // 0x800874E0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800874E4: lw          $v0, -0x5380($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5380);
    // 0x800874E8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
L_800874EC:
    // 0x800874EC: beq         $a0, $zero, L_8008789C
    if (ctx->r4 == 0) {
        // 0x800874F0: addu        $v0, $s6, $zero
        ctx->r2 = ADD32(ctx->r22, 0);
            goto L_8008789C;
    }
    // 0x800874F0: addu        $v0, $s6, $zero
    ctx->r2 = ADD32(ctx->r22, 0);
    // 0x800874F4: lhu         $v0, 0x30($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X30);
    // 0x800874F8: blez        $v0, L_80087898
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800874FC: addu        $s7, $zero, $zero
        ctx->r23 = ADD32(0, 0);
            goto L_80087898;
    }
    // 0x800874FC: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // 0x80087500: lbu         $t1, 0x4F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X4F);
    // 0x80087504: lbu         $s3, 0x67($sp)
    ctx->r19 = MEM_BU(ctx->r29, 0X67);
    // 0x80087508: lbu         $s4, 0x6F($sp)
    ctx->r20 = MEM_BU(ctx->r29, 0X6F);
    // 0x8008750C: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80087510: addiu       $v1, $v1, -0x7C30
    ctx->r3 = ADD32(ctx->r3, -0X7C30);
    // 0x80087514: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x80087518: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8008751C: andi        $fp, $t1, 0x7F
    ctx->r30 = ctx->r9 & 0X7F;
    // 0x80087520: sll         $v0, $s4, 4
    ctx->r2 = S32(ctx->r20 << 4);
    // 0x80087524: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80087528: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x8008752C: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
L_80087530:
    // 0x80087530: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x80087534: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80087538: beq         $v1, $v0, L_80087884
    if (ctx->r3 == ctx->r2) {
        // 0x8008753C: nop
    
            goto L_80087884;
    }
    // 0x8008753C: nop

    // 0x80087540: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
    // 0x80087544: sltu        $v0, $fp, $v0
    ctx->r2 = ctx->r30 < ctx->r2 ? 1 : 0;
    // 0x80087548: bne         $v0, $zero, L_80087884
    if (ctx->r2 != 0) {
        // 0x8008754C: nop
    
            goto L_80087884;
    }
    // 0x8008754C: nop

    // 0x80087550: lbu         $v0, 0x3($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3);
    // 0x80087554: sltu        $v0, $v0, $fp
    ctx->r2 = ctx->r2 < ctx->r30 ? 1 : 0;
    // 0x80087558: bne         $v0, $zero, L_80087884
    if (ctx->r2 != 0) {
        // 0x8008755C: nop
    
            goto L_80087884;
    }
    // 0x8008755C: nop

    // 0x80087560: lb          $v0, 0x4($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X4);
    // 0x80087564: addu        $s0, $fp, $v0
    ctx->r16 = ADD32(ctx->r30, ctx->r2);
    // 0x80087568: slti        $v0, $s0, 0x80
    ctx->r2 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    // 0x8008756C: beq         $v0, $zero, L_80087580
    if (ctx->r2 == 0) {
        // 0x80087570: nor         $v0, $zero, $s0
        ctx->r2 = ~(0 | ctx->r16);
            goto L_80087580;
    }
    // 0x80087570: nor         $v0, $zero, $s0
    ctx->r2 = ~(0 | ctx->r16);
    // 0x80087574: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80087578: j           L_80087584
    // 0x8008757C: and         $v0, $s0, $v0
    ctx->r2 = ctx->r16 & ctx->r2;
        goto L_80087584;
    // 0x8008757C: and         $v0, $s0, $v0
    ctx->r2 = ctx->r16 & ctx->r2;
L_80087580:
    // 0x80087580: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
L_80087584:
    // 0x80087584: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80087588: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8008758C: beq         $s3, $v0, L_800875D8
    if (ctx->r19 == ctx->r2) {
        // 0x80087590: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800875D8;
    }
    // 0x80087590: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80087594: beq         $s4, $v0, L_800875AC
    if (ctx->r20 == ctx->r2) {
        // 0x80087598: nop
    
            goto L_800875AC;
    }
    // 0x80087598: nop

    // 0x8008759C: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x800875A0: lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X0);
    // 0x800875A4: j           L_800875B8
    // 0x800875A8: nop

        goto L_800875B8;
    // 0x800875A8: nop

L_800875AC:
    // 0x800875AC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800875B0: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x800875B4: lbu         $v0, 0x2018($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X2018);
L_800875B8:
    // 0x800875B8: beq         $v0, $zero, L_800875DC
    if (ctx->r2 == 0) {
        // 0x800875BC: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800875DC;
    }
    // 0x800875BC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800875C0: lbu         $a1, 0x67($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X67);
    // 0x800875C4: lbu         $a2, 0x6F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X6F);
    // 0x800875C8: jal         0x80086B90
    // 0x800875CC: andi        $a0, $a0, 0x7F
    ctx->r4 = ctx->r4 & 0X7F;
    func_80086B90(rdram, ctx);
        goto after_1;
    // 0x800875CC: andi        $a0, $a0, 0x7F
    ctx->r4 = ctx->r4 & 0X7F;
    after_1:
    // 0x800875D0: bne         $v0, $s2, L_800875DC
    if (ctx->r2 != ctx->r18) {
        // 0x800875D4: nop
    
            goto L_800875DC;
    }
    // 0x800875D4: nop

L_800875D8:
    // 0x800875D8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800875DC:
    // 0x800875DC: bne         $v0, $s2, L_8008789C
    if (ctx->r2 != ctx->r18) {
        // 0x800875E0: nop
    
            goto L_8008789C;
    }
    // 0x800875E0: nop

    // 0x800875E4: lbu         $v1, 0x8($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X8);
    // 0x800875E8: andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // 0x800875EC: bne         $v0, $zero, L_80087620
    if (ctx->r2 != 0) {
        // 0x800875F0: addiu       $t0, $zero, 0x80
        ctx->r8 = ADD32(0, 0X80);
            goto L_80087620;
    }
    // 0x800875F0: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x800875F4: lbu         $t1, 0x5F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X5F);
    // 0x800875F8: addiu       $t0, $v1, -0x40
    ctx->r8 = ADD32(ctx->r3, -0X40);
    // 0x800875FC: addu        $t0, $t1, $t0
    ctx->r8 = ADD32(ctx->r9, ctx->r8);
    // 0x80087600: bltz        $t0, L_80087618
    if (SIGNED(ctx->r8) < 0) {
        // 0x80087604: slti        $v0, $t0, 0x80
        ctx->r2 = SIGNED(ctx->r8) < 0X80 ? 1 : 0;
            goto L_80087618;
    }
    // 0x80087604: slti        $v0, $t0, 0x80
    ctx->r2 = SIGNED(ctx->r8) < 0X80 ? 1 : 0;
    // 0x80087608: beq         $v0, $zero, L_8008761C
    if (ctx->r2 == 0) {
        // 0x8008760C: addiu       $v1, $zero, 0x7F
        ctx->r3 = ADD32(0, 0X7F);
            goto L_8008761C;
    }
    // 0x8008760C: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
    // 0x80087610: j           L_8008761C
    // 0x80087614: addu        $v1, $t0, $zero
    ctx->r3 = ADD32(ctx->r8, 0);
        goto L_8008761C;
    // 0x80087614: addu        $v1, $t0, $zero
    ctx->r3 = ADD32(ctx->r8, 0);
L_80087618:
    // 0x80087618: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8008761C:
    // 0x8008761C: addu        $t0, $v1, $zero
    ctx->r8 = ADD32(ctx->r3, 0);
L_80087620:
    // 0x80087620: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x80087624: lbu         $v1, 0x57($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X57);
    // 0x80087628: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008762C: mflo        $v1
    ctx->r3 = lo;
    // 0x80087630: lui         $v0, 0x8102
    ctx->r2 = S32(0X8102 << 16);
    // 0x80087634: ori         $v0, $v0, 0x409
    ctx->r2 = ctx->r2 | 0X409;
    // 0x80087638: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008763C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80087640: lh          $a0, 0x6($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X6);
    // 0x80087644: srl         $v0, $t1, 8
    ctx->r2 = S32(U32(ctx->r9) >> 8);
    // 0x80087648: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x8008764C: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
    // 0x80087650: slti        $v0, $a1, 0x100
    ctx->r2 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x80087654: mfhi        $t1
    ctx->r9 = hi;
    // 0x80087658: addu        $v1, $t1, $v1
    ctx->r3 = ADD32(ctx->r9, ctx->r3);
    // 0x8008765C: beq         $v0, $zero, L_80087674
    if (ctx->r2 == 0) {
        // 0x80087660: srl         $a3, $v1, 6
        ctx->r7 = S32(U32(ctx->r3) >> 6);
            goto L_80087674;
    }
    // 0x80087660: srl         $a3, $v1, 6
    ctx->r7 = S32(U32(ctx->r3) >> 6);
    // 0x80087664: nor         $v0, $zero, $a1
    ctx->r2 = ~(0 | ctx->r5);
    // 0x80087668: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8008766C: j           L_80087678
    // 0x80087670: and         $v1, $a1, $v0
    ctx->r3 = ctx->r5 & ctx->r2;
        goto L_80087678;
    // 0x80087670: and         $v1, $a1, $v0
    ctx->r3 = ctx->r5 & ctx->r2;
L_80087674:
    // 0x80087674: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_80087678:
    // 0x80087678: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8008767C: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x80087680: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    // 0x80087684: andi        $a0, $t1, 0xFF
    ctx->r4 = ctx->r9 & 0XFF;
    // 0x80087688: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x8008768C: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x80087690: andi        $v0, $v0, 0xC000
    ctx->r2 = ctx->r2 & 0XC000;
    // 0x80087694: bne         $v0, $zero, L_80087884
    if (ctx->r2 != 0) {
        // 0x80087698: or          $a0, $a0, $v1
        ctx->r4 = ctx->r4 | ctx->r3;
            goto L_80087884;
    }
    // 0x80087698: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x8008769C: bne         $s6, $s2, L_800877EC
    if (ctx->r22 != ctx->r18) {
        // 0x800876A0: andi        $a3, $a3, 0xFF
        ctx->r7 = ctx->r7 & 0XFF;
            goto L_800877EC;
    }
    // 0x800876A0: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x800876A4: lbu         $t1, 0x4F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X4F);
    // 0x800876A8: lhu         $a1, 0x46($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X46);
    // 0x800876AC: andi        $a2, $t1, 0x80
    ctx->r6 = ctx->r9 & 0X80;
    // 0x800876B0: lhu         $t1, 0x76($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X76);
    // 0x800876B4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800876B8: lhu         $t1, 0x7E($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X7E);
    // 0x800876BC: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // 0x800876C0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800876C4: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x800876C8: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x800876CC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800876D0: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800876D4: lbu         $t1, 0x87($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X87);
    // 0x800876D8: or          $a2, $s0, $a2
    ctx->r6 = ctx->r16 | ctx->r6;
    // 0x800876DC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x800876E0: jal         0x80086FC4
    // 0x800876E4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    func_80086FC4(rdram, ctx);
        goto after_2;
    // 0x800876E4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    after_2:
    // 0x800876E8: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // 0x800876EC: beq         $s5, $s6, L_80087884
    if (ctx->r21 == ctx->r22) {
        // 0x800876F0: andi        $v0, $s5, 0xFF
        ctx->r2 = ctx->r21 & 0XFF;
            goto L_80087884;
    }
    // 0x800876F0: andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
    // 0x800876F4: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x800876F8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800876FC: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80087700: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80087704: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80087708: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008770C: addiu       $v0, $v0, -0x2780
    ctx->r2 = ADD32(ctx->r2, -0X2780);
    // 0x80087710: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
L_80087714:
    // 0x80087714: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80087718: lw          $a0, -0x5308($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5308);
    // 0x8008771C: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80087720: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80087724: sw          $v0, -0x5308($at)
    MEM_W(-0X5308, ctx->r1) = ctx->r2;
    // 0x80087728: beq         $a0, $s2, L_80087714
    if (ctx->r4 == ctx->r18) {
        // 0x8008772C: addu        $a3, $a0, $zero
        ctx->r7 = ADD32(ctx->r4, 0);
            goto L_80087714;
    }
    // 0x8008772C: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x80087730: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80087734: lw          $a1, -0x5100($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5100);
    // 0x80087738: beq         $a1, $zero, L_80087788
    if (ctx->r5 == 0) {
        // 0x8008773C: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_80087788;
    }
    // 0x8008773C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80087740:
    // 0x80087740: lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X8);
    // 0x80087744: sltu        $v0, $a3, $a0
    ctx->r2 = ctx->r7 < ctx->r4 ? 1 : 0;
    // 0x80087748: bne         $v0, $zero, L_80087788
    if (ctx->r2 != 0) {
        // 0x8008774C: nop
    
            goto L_80087788;
    }
    // 0x8008774C: nop

    // 0x80087750: bnel        $a0, $a3, L_8008777C
    if (ctx->r4 != ctx->r7) {
        // 0x80087754: addu        $a2, $a1, $zero
        ctx->r6 = ADD32(ctx->r5, 0);
            goto L_8008777C;
    }
    goto skip_2;
    // 0x80087754: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    skip_2:
L_80087758:
    // 0x80087758: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008775C: lw          $a0, -0x5308($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5308);
    // 0x80087760: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80087764: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80087768: sw          $v0, -0x5308($at)
    MEM_W(-0X5308, ctx->r1) = ctx->r2;
    // 0x8008776C: beq         $a0, $s2, L_80087758
    if (ctx->r4 == ctx->r18) {
        // 0x80087770: nop
    
            goto L_80087758;
    }
    // 0x80087770: nop

    // 0x80087774: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x80087778: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
L_8008777C:
    // 0x8008777C: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    // 0x80087780: bne         $a1, $zero, L_80087740
    if (ctx->r5 != 0) {
        // 0x80087784: nop
    
            goto L_80087740;
    }
    // 0x80087784: nop

L_80087788:
    // 0x80087788: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008778C: lw          $a0, -0x50FC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X50FC);
    // 0x80087790: beq         $a0, $zero, L_80087884
    if (ctx->r4 == 0) {
        // 0x80087794: addiu       $s6, $zero, -0x1
        ctx->r22 = ADD32(0, -0X1);
            goto L_80087884;
    }
    // 0x80087794: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x80087798: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8008779C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800877A0: sw          $v0, -0x50FC($at)
    MEM_W(-0X50FC, ctx->r1) = ctx->r2;
    // 0x800877A4: bnel        $v0, $zero, L_800877AC
    if (ctx->r2 != 0) {
        // 0x800877A8: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_800877AC;
    }
    goto skip_3;
    // 0x800877A8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_3:
L_800877AC:
    // 0x800877AC: bnel        $a2, $zero, L_800877C4
    if (ctx->r6 != 0) {
        // 0x800877B0: sw          $a0, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r4;
            goto L_800877C4;
    }
    goto skip_4;
    // 0x800877B0: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
    skip_4:
    // 0x800877B4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800877B8: sw          $a0, -0x5100($at)
    MEM_W(-0X5100, ctx->r1) = ctx->r4;
    // 0x800877BC: j           L_800877C8
    // 0x800877C0: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
        goto L_800877C8;
    // 0x800877C0: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
L_800877C4:
    // 0x800877C4: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
L_800877C8:
    // 0x800877C8: beq         $a1, $zero, L_800877D4
    if (ctx->r5 == 0) {
        // 0x800877CC: sw          $a1, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r5;
            goto L_800877D4;
    }
    // 0x800877CC: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x800877D0: sw          $a0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r4;
L_800877D4:
    // 0x800877D4: sw          $a3, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r7;
    // 0x800877D8: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x800877DC: addu        $s6, $a3, $zero
    ctx->r22 = ADD32(ctx->r7, 0);
    // 0x800877E0: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // 0x800877E4: j           L_80087884
    // 0x800877E8: sw          $a0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r4;
        goto L_80087884;
    // 0x800877E8: sw          $a0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r4;
L_800877EC:
    // 0x800877EC: lbu         $t1, 0x4F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X4F);
    // 0x800877F0: lhu         $a1, 0x46($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X46);
    // 0x800877F4: andi        $a2, $t1, 0x80
    ctx->r6 = ctx->r9 & 0X80;
    // 0x800877F8: lhu         $t1, 0x76($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X76);
    // 0x800877FC: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80087800: lhu         $t1, 0x7E($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X7E);
    // 0x80087804: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // 0x80087808: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8008780C: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80087810: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80087814: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80087818: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8008781C: lbu         $t1, 0x87($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X87);
    // 0x80087820: or          $a2, $s0, $a2
    ctx->r6 = ctx->r16 | ctx->r6;
    // 0x80087824: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80087828: jal         0x80086FC4
    // 0x8008782C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    func_80086FC4(rdram, ctx);
        goto after_3;
    // 0x8008782C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    after_3:
    // 0x80087830: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80087834: beq         $a0, $s2, L_80087884
    if (ctx->r4 == ctx->r18) {
        // 0x80087838: andi        $v1, $s5, 0xFF
        ctx->r3 = ctx->r21 & 0XFF;
            goto L_80087884;
    }
    // 0x80087838: andi        $v1, $s5, 0xFF
    ctx->r3 = ctx->r21 & 0XFF;
    // 0x8008783C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80087840: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80087844: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80087848: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008784C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80087850: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x80087854: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80087858: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8008785C: sw          $a0, -0x2770($at)
    MEM_W(-0X2770, ctx->r1) = ctx->r4;
    // 0x80087860: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80087864: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80087868: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8008786C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80087870: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80087874: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80087878: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8008787C: sw          $s5, -0x276C($at)
    MEM_W(-0X276C, ctx->r1) = ctx->r21;
    // 0x80087880: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
L_80087884:
    // 0x80087884: lhu         $v0, 0x30($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X30);
    // 0x80087888: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8008788C: slt         $v0, $s7, $v0
    ctx->r2 = SIGNED(ctx->r23) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80087890: bne         $v0, $zero, L_80087530
    if (ctx->r2 != 0) {
        // 0x80087894: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80087530;
    }
    // 0x80087894: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_80087898:
    // 0x80087898: addu        $v0, $s6, $zero
    ctx->r2 = ADD32(ctx->r22, 0);
L_8008789C:
    // 0x8008789C: lw          $ra, 0xCC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XCC);
    // 0x800878A0: lw          $fp, 0xC8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XC8);
    // 0x800878A4: lw          $s7, 0xC4($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XC4);
    // 0x800878A8: lw          $s6, 0xC0($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XC0);
    // 0x800878AC: lw          $s5, 0xBC($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XBC);
    // 0x800878B0: lw          $s4, 0xB8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XB8);
    // 0x800878B4: lw          $s3, 0xB4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XB4);
    // 0x800878B8: lw          $s2, 0xB0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XB0);
    // 0x800878BC: lw          $s1, 0xAC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XAC);
    // 0x800878C0: lw          $s0, 0xA8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA8);
    // 0x800878C4: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    // 0x800878C8: jr          $ra
    // 0x800878CC: nop

    return;
    // 0x800878CC: nop

;}
RECOMP_FUNC void func_800878D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800878D0: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800878D4: sw          $s6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r22;
    // 0x800878D8: addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // 0x800878DC: srl         $t0, $s6, 16
    ctx->r8 = S32(U32(ctx->r22) >> 16);
    // 0x800878E0: sh          $t0, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r8;
    // 0x800878E4: lbu         $t0, 0xA3($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XA3);
    // 0x800878E8: lh          $v1, 0xB6($sp)
    ctx->r3 = MEM_H(ctx->r29, 0XB6);
    // 0x800878EC: sb          $t0, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r8;
    // 0x800878F0: lbu         $t0, 0xA7($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XA7);
    // 0x800878F4: sb          $t0, 0x47($sp)
    MEM_B(0X47, ctx->r29) = ctx->r8;
    // 0x800878F8: lhu         $t0, 0xAA($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0XAA);
    // 0x800878FC: sh          $t0, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r8;
    // 0x80087900: lhu         $t0, 0xAE($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0XAE);
    // 0x80087904: sw          $s7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r23;
    // 0x80087908: addu        $s7, $a3, $zero
    ctx->r23 = ADD32(ctx->r7, 0);
    // 0x8008790C: sh          $t0, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r8;
    // 0x80087910: lbu         $t0, 0xB3($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XB3);
    // 0x80087914: srl         $v0, $s6, 8
    ctx->r2 = S32(U32(ctx->r22) >> 8);
    // 0x80087918: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8008791C: sw          $fp, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r30;
    // 0x80087920: addu        $fp, $a1, $zero
    ctx->r30 = ADD32(ctx->r5, 0);
    // 0x80087924: sw          $ra, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r31;
    // 0x80087928: sw          $s5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r21;
    // 0x8008792C: sw          $s4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r20;
    // 0x80087930: sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // 0x80087934: sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // 0x80087938: sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // 0x8008793C: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x80087940: sb          $a2, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r6;
    // 0x80087944: addu        $s5, $v0, $v1
    ctx->r21 = ADD32(ctx->r2, ctx->r3);
    // 0x80087948: bltz        $s5, L_80087964
    if (SIGNED(ctx->r21) < 0) {
        // 0x8008794C: sb          $t0, 0x5F($sp)
        MEM_B(0X5F, ctx->r29) = ctx->r8;
            goto L_80087964;
    }
    // 0x8008794C: sb          $t0, 0x5F($sp)
    MEM_B(0X5F, ctx->r29) = ctx->r8;
    // 0x80087950: slti        $v0, $s5, 0x100
    ctx->r2 = SIGNED(ctx->r21) < 0X100 ? 1 : 0;
    // 0x80087954: beq         $v0, $zero, L_80087968
    if (ctx->r2 == 0) {
        // 0x80087958: addiu       $v1, $zero, 0xFF
        ctx->r3 = ADD32(0, 0XFF);
            goto L_80087968;
    }
    // 0x80087958: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8008795C: j           L_80087968
    // 0x80087960: addu        $v1, $s5, $zero
    ctx->r3 = ADD32(ctx->r21, 0);
        goto L_80087968;
    // 0x80087960: addu        $v1, $s5, $zero
    ctx->r3 = ADD32(ctx->r21, 0);
L_80087964:
    // 0x80087964: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80087968:
    // 0x80087968: addu        $s5, $v1, $zero
    ctx->r21 = ADD32(ctx->r3, 0);
    // 0x8008796C: lui         $v0, 0xFFFF
    ctx->r2 = S32(0XFFFF << 16);
    // 0x80087970: ori         $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 | 0XFF;
    // 0x80087974: and         $v0, $s6, $v0
    ctx->r2 = ctx->r22 & ctx->r2;
    // 0x80087978: sll         $v1, $s5, 8
    ctx->r3 = S32(ctx->r21 << 8);
    // 0x8008797C: lhu         $t0, 0x66($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X66);
    // 0x80087980: or          $s6, $v0, $v1
    ctx->r22 = ctx->r2 | ctx->r3;
    // 0x80087984: addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
    // 0x80087988: andi        $v1, $t0, 0xC000
    ctx->r3 = ctx->r8 & 0XC000;
    // 0x8008798C: beq         $v1, $v0, L_80087A70
    if (ctx->r3 == ctx->r2) {
        // 0x80087990: slti        $v0, $v1, 0x4001
        ctx->r2 = SIGNED(ctx->r3) < 0X4001 ? 1 : 0;
            goto L_80087A70;
    }
    // 0x80087990: slti        $v0, $v1, 0x4001
    ctx->r2 = SIGNED(ctx->r3) < 0X4001 ? 1 : 0;
    // 0x80087994: beql        $v0, $zero, L_800879AC
    if (ctx->r2 == 0) {
        // 0x80087998: ori         $v0, $zero, 0x8000
        ctx->r2 = 0 | 0X8000;
            goto L_800879AC;
    }
    goto skip_0;
    // 0x80087998: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    skip_0:
    // 0x8008799C: beq         $v1, $zero, L_800879BC
    if (ctx->r3 == 0) {
        // 0x800879A0: addiu       $v1, $zero, 0xFF
        ctx->r3 = ADD32(0, 0XFF);
            goto L_800879BC;
    }
    // 0x800879A0: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x800879A4: j           L_80087D5C
    // 0x800879A8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80087D5C;
    // 0x800879A8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800879AC:
    // 0x800879AC: beq         $v1, $v0, L_80087D10
    if (ctx->r3 == ctx->r2) {
        // 0x800879B0: addu        $a0, $s6, $zero
        ctx->r4 = ADD32(ctx->r22, 0);
            goto L_80087D10;
    }
    // 0x800879B0: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x800879B4: j           L_80087D5C
    // 0x800879B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80087D5C;
    // 0x800879B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800879BC:
    // 0x800879BC: lbu         $a0, 0x3F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3F);
    // 0x800879C0: beql        $a0, $v1, L_80087A2C
    if (ctx->r4 == ctx->r3) {
        // 0x800879C4: addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
            goto L_80087A2C;
    }
    goto skip_1;
    // 0x800879C4: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    skip_1:
    // 0x800879C8: lbu         $v0, 0x47($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X47);
    // 0x800879CC: beq         $v0, $v1, L_800879F0
    if (ctx->r2 == ctx->r3) {
        // 0x800879D0: sll         $v0, $v0, 4
        ctx->r2 = S32(ctx->r2 << 4);
            goto L_800879F0;
    }
    // 0x800879D0: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800879D4: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x800879D8: addiu       $v1, $v1, -0x7C30
    ctx->r3 = ADD32(ctx->r3, -0X7C30);
    // 0x800879DC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800879E0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800879E4: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800879E8: j           L_800879FC
    // 0x800879EC: nop

        goto L_800879FC;
    // 0x800879EC: nop

L_800879F0:
    // 0x800879F0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800879F4: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800879F8: lbu         $v0, 0x2018($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X2018);
L_800879FC:
    // 0x800879FC: beq         $v0, $zero, L_80087A28
    if (ctx->r2 == 0) {
        // 0x80087A00: andi        $a0, $fp, 0x7F
        ctx->r4 = ctx->r30 & 0X7F;
            goto L_80087A28;
    }
    // 0x80087A00: andi        $a0, $fp, 0x7F
    ctx->r4 = ctx->r30 & 0X7F;
    // 0x80087A04: lbu         $t0, 0x3F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3F);
    // 0x80087A08: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x80087A0C: lbu         $t0, 0x47($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X47);
    // 0x80087A10: jal         0x80086B90
    // 0x80087A14: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    func_80086B90(rdram, ctx);
        goto after_0;
    // 0x80087A14: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    after_0:
    // 0x80087A18: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80087A1C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80087A20: bne         $v1, $v0, L_80087D5C
    if (ctx->r3 != ctx->r2) {
        // 0x80087A24: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_80087D5C;
    }
    // 0x80087A24: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80087A28:
    // 0x80087A28: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_80087A2C:
    // 0x80087A2C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80087A30: bne         $v1, $v0, L_80087D5C
    if (ctx->r3 != ctx->r2) {
        // 0x80087A34: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_80087D5C;
    }
    // 0x80087A34: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x80087A38: lbu         $t0, 0x3F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3F);
    // 0x80087A3C: lbu         $a3, 0x37($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X37);
    // 0x80087A40: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80087A44: lbu         $t0, 0x47($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X47);
    // 0x80087A48: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80087A4C: lhu         $t0, 0x4E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X4E);
    // 0x80087A50: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80087A54: lhu         $t0, 0x56($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X56);
    // 0x80087A58: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x80087A5C: srl         $a1, $a0, 16
    ctx->r5 = S32(U32(ctx->r4) >> 16);
    // 0x80087A60: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80087A64: lbu         $t0, 0x5F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X5F);
    // 0x80087A68: j           L_80087CAC
    // 0x80087A6C: andi        $a2, $fp, 0xFF
    ctx->r6 = ctx->r30 & 0XFF;
        goto L_80087CAC;
    // 0x80087A6C: andi        $a2, $fp, 0xFF
    ctx->r6 = ctx->r30 & 0XFF;
L_80087A70:
    // 0x80087A70: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80087A74: lw          $v0, -0x3BB0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3BB0);
    // 0x80087A78: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80087A7C: sh          $t0, -0x5394($at)
    MEM_H(-0X5394, ctx->r1) = ctx->r8;
    // 0x80087A80: beq         $v0, $zero, L_80087AE8
    if (ctx->r2 == 0) {
        // 0x80087A84: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80087AE8;
    }
    // 0x80087A84: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80087A88: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80087A8C: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80087A90: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_80087A94:
    // 0x80087A94: sra         $s2, $v0, 1
    ctx->r18 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80087A98: addiu       $s1, $s2, -0x1
    ctx->r17 = ADD32(ctx->r18, -0X1);
    // 0x80087A9C: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x80087AA0: mult        $t0, $s1
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80087AA4: mflo        $v0
    ctx->r2 = lo;
    // 0x80087AA8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80087AAC: addiu       $a0, $a0, -0x5398
    ctx->r4 = ADD32(ctx->r4, -0X5398);
    // 0x80087AB0: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80087AB4: addiu       $t0, $t0, -0x43B8
    ctx->r8 = ADD32(ctx->r8, -0X43B8);
    // 0x80087AB8: addu        $s0, $t0, $v0
    ctx->r16 = ADD32(ctx->r8, ctx->r2);
    // 0x80087ABC: jal         0x80085F54
    // 0x80087AC0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    compareHalfwordAtOffset4_v2(rdram, ctx);
        goto after_1;
    // 0x80087AC0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80087AC4: beql        $v0, $zero, L_80087AE8
    if (ctx->r2 == 0) {
        // 0x80087AC8: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_80087AE8;
    }
    goto skip_2;
    // 0x80087AC8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    skip_2:
    // 0x80087ACC: bgezl       $v0, L_80087AD8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80087AD0: addiu       $s4, $s2, 0x1
        ctx->r20 = ADD32(ctx->r18, 0X1);
            goto L_80087AD8;
    }
    goto skip_3;
    // 0x80087AD0: addiu       $s4, $s2, 0x1
    ctx->r20 = ADD32(ctx->r18, 0X1);
    skip_3:
    // 0x80087AD4: addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
L_80087AD8:
    // 0x80087AD8: slt         $v0, $s3, $s4
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80087ADC: beq         $v0, $zero, L_80087A94
    if (ctx->r2 == 0) {
        // 0x80087AE0: addu        $v0, $s4, $s3
        ctx->r2 = ADD32(ctx->r20, ctx->r19);
            goto L_80087A94;
    }
    // 0x80087AE0: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
    // 0x80087AE4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80087AE8:
    // 0x80087AE8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80087AEC: sw          $a1, -0x5390($at)
    MEM_W(-0X5390, ctx->r1) = ctx->r5;
    // 0x80087AF0: beq         $a1, $zero, L_80087AFC
    if (ctx->r5 == 0) {
        // 0x80087AF4: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_80087AFC;
    }
    // 0x80087AF4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80087AF8: lw          $a3, 0x0($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X0);
L_80087AFC:
    // 0x80087AFC: beq         $a3, $zero, L_80087D58
    if (ctx->r7 == 0) {
        // 0x80087B00: andi        $a1, $fp, 0x7F
        ctx->r5 = ctx->r30 & 0X7F;
            goto L_80087D58;
    }
    // 0x80087B00: andi        $a1, $fp, 0x7F
    ctx->r5 = ctx->r30 & 0X7F;
    // 0x80087B04: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x80087B08: addu        $a0, $v0, $a3
    ctx->r4 = ADD32(ctx->r2, ctx->r7);
    // 0x80087B0C: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x80087B10: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80087B14: beq         $v1, $v0, L_80087D5C
    if (ctx->r3 == ctx->r2) {
        // 0x80087B18: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80087D5C;
    }
    // 0x80087B18: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80087B1C: lbu         $v0, 0x3($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X3);
    // 0x80087B20: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80087B24: bnel        $v0, $zero, L_80087B64
    if (ctx->r2 != 0) {
        // 0x80087B28: addiu       $s7, $zero, 0x80
        ctx->r23 = ADD32(0, 0X80);
            goto L_80087B64;
    }
    goto skip_4;
    // 0x80087B28: addiu       $s7, $zero, 0x80
    ctx->r23 = ADD32(0, 0X80);
    skip_4:
    // 0x80087B2C: andi        $v0, $fp, 0xFF
    ctx->r2 = ctx->r30 & 0XFF;
    // 0x80087B30: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80087B34: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80087B38: lbu         $v0, 0x3($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X3);
    // 0x80087B3C: addiu       $v1, $v0, -0x40
    ctx->r3 = ADD32(ctx->r2, -0X40);
    // 0x80087B40: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // 0x80087B44: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80087B48: bgez        $v1, L_80087B58
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80087B4C: slti        $v0, $v1, 0x80
        ctx->r2 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
            goto L_80087B58;
    }
    // 0x80087B4C: slti        $v0, $v1, 0x80
    ctx->r2 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    // 0x80087B50: j           L_80087B64
    // 0x80087B54: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
        goto L_80087B64;
    // 0x80087B54: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
L_80087B58:
    // 0x80087B58: bne         $v0, $zero, L_80087B64
    if (ctx->r2 != 0) {
        // 0x80087B5C: addu        $s7, $v1, $zero
        ctx->r23 = ADD32(ctx->r3, 0);
            goto L_80087B64;
    }
    // 0x80087B5C: addu        $s7, $v1, $zero
    ctx->r23 = ADD32(ctx->r3, 0);
    // 0x80087B60: addiu       $s7, $zero, 0x7F
    ctx->r23 = ADD32(0, 0X7F);
L_80087B64:
    // 0x80087B64: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x80087B68: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80087B6C: lb          $v1, 0x2($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X2);
    // 0x80087B70: andi        $v0, $fp, 0x7F
    ctx->r2 = ctx->r30 & 0X7F;
    // 0x80087B74: addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // 0x80087B78: slti        $v0, $s0, 0x80
    ctx->r2 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    // 0x80087B7C: beq         $v0, $zero, L_80087B90
    if (ctx->r2 == 0) {
        // 0x80087B80: nor         $v0, $zero, $s0
        ctx->r2 = ~(0 | ctx->r16);
            goto L_80087B90;
    }
    // 0x80087B80: nor         $v0, $zero, $s0
    ctx->r2 = ~(0 | ctx->r16);
    // 0x80087B84: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80087B88: j           L_80087B94
    // 0x80087B8C: and         $a2, $s0, $v0
    ctx->r6 = ctx->r16 & ctx->r2;
        goto L_80087B94;
    // 0x80087B8C: and         $a2, $s0, $v0
    ctx->r6 = ctx->r16 & ctx->r2;
L_80087B90:
    // 0x80087B90: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
L_80087B94:
    // 0x80087B94: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x80087B98: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80087B9C: lh          $v0, 0x4($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X4);
    // 0x80087BA0: addu        $s5, $s5, $v0
    ctx->r21 = ADD32(ctx->r21, ctx->r2);
    // 0x80087BA4: slti        $v0, $s5, 0x100
    ctx->r2 = SIGNED(ctx->r21) < 0X100 ? 1 : 0;
    // 0x80087BA8: beq         $v0, $zero, L_80087BC0
    if (ctx->r2 == 0) {
        // 0x80087BAC: addu        $s0, $a2, $zero
        ctx->r16 = ADD32(ctx->r6, 0);
            goto L_80087BC0;
    }
    // 0x80087BAC: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x80087BB0: nor         $v0, $zero, $s5
    ctx->r2 = ~(0 | ctx->r21);
    // 0x80087BB4: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80087BB8: j           L_80087BC4
    // 0x80087BBC: and         $a0, $s5, $v0
    ctx->r4 = ctx->r21 & ctx->r2;
        goto L_80087BC4;
    // 0x80087BBC: and         $a0, $s5, $v0
    ctx->r4 = ctx->r21 & ctx->r2;
L_80087BC0:
    // 0x80087BC0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_80087BC4:
    // 0x80087BC4: andi        $s6, $s6, 0xFF
    ctx->r22 = ctx->r22 & 0XFF;
    // 0x80087BC8: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x80087BCC: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80087BD0: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x80087BD4: sll         $v0, $a0, 8
    ctx->r2 = S32(ctx->r4 << 8);
    // 0x80087BD8: or          $s6, $s6, $v0
    ctx->r22 = ctx->r22 | ctx->r2;
    // 0x80087BDC: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80087BE0: andi        $v1, $v1, 0xC000
    ctx->r3 = ctx->r3 & 0XC000;
    // 0x80087BE4: bne         $v1, $zero, L_80087CCC
    if (ctx->r3 != 0) {
        // 0x80087BE8: or          $s6, $s6, $v0
        ctx->r22 = ctx->r22 | ctx->r2;
            goto L_80087CCC;
    }
    // 0x80087BE8: or          $s6, $s6, $v0
    ctx->r22 = ctx->r22 | ctx->r2;
    // 0x80087BEC: lbu         $a1, 0x3F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3F);
    // 0x80087BF0: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80087BF4: beq         $a1, $v1, L_80087C5C
    if (ctx->r5 == ctx->r3) {
        // 0x80087BF8: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80087C5C;
    }
    // 0x80087BF8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80087BFC: lbu         $v0, 0x47($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X47);
    // 0x80087C00: beq         $v0, $v1, L_80087C24
    if (ctx->r2 == ctx->r3) {
        // 0x80087C04: sll         $v0, $v0, 4
        ctx->r2 = S32(ctx->r2 << 4);
            goto L_80087C24;
    }
    // 0x80087C04: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80087C08: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80087C0C: addiu       $v1, $v1, -0x7C30
    ctx->r3 = ADD32(ctx->r3, -0X7C30);
    // 0x80087C10: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80087C14: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80087C18: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80087C1C: j           L_80087C30
    // 0x80087C20: nop

        goto L_80087C30;
    // 0x80087C20: nop

L_80087C24:
    // 0x80087C24: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80087C28: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x80087C2C: lbu         $v0, 0x2018($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X2018);
L_80087C30:
    // 0x80087C30: beq         $v0, $zero, L_80087C5C
    if (ctx->r2 == 0) {
        // 0x80087C34: andi        $a0, $a0, 0x7F
        ctx->r4 = ctx->r4 & 0X7F;
            goto L_80087C5C;
    }
    // 0x80087C34: andi        $a0, $a0, 0x7F
    ctx->r4 = ctx->r4 & 0X7F;
    // 0x80087C38: lbu         $t0, 0x3F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3F);
    // 0x80087C3C: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x80087C40: lbu         $t0, 0x47($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X47);
    // 0x80087C44: jal         0x80086B90
    // 0x80087C48: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    func_80086B90(rdram, ctx);
        goto after_2;
    // 0x80087C48: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    after_2:
    // 0x80087C4C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80087C50: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80087C54: bne         $v1, $v0, L_80087D5C
    if (ctx->r3 != ctx->r2) {
        // 0x80087C58: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_80087D5C;
    }
    // 0x80087C58: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80087C5C:
    // 0x80087C5C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80087C60: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80087C64: bne         $v1, $v0, L_80087D5C
    if (ctx->r3 != ctx->r2) {
        // 0x80087C68: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_80087D5C;
    }
    // 0x80087C68: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x80087C6C: lhu         $t0, 0x66($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X66);
    // 0x80087C70: lbu         $a3, 0x37($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X37);
    // 0x80087C74: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x80087C78: lbu         $t0, 0x3F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3F);
    // 0x80087C7C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80087C80: lbu         $t0, 0x47($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X47);
    // 0x80087C84: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80087C88: lhu         $t0, 0x4E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X4E);
    // 0x80087C8C: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x80087C90: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80087C94: lhu         $t0, 0x56($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X56);
    // 0x80087C98: andi        $a2, $fp, 0x80
    ctx->r6 = ctx->r30 & 0X80;
    // 0x80087C9C: or          $a2, $s0, $a2
    ctx->r6 = ctx->r16 | ctx->r6;
    // 0x80087CA0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80087CA4: lbu         $t0, 0x5F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X5F);
    // 0x80087CA8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
L_80087CAC:
    // 0x80087CAC: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // 0x80087CB0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80087CB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80087CB8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80087CBC: jal         0x80086FC4
    // 0x80087CC0: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    func_80086FC4(rdram, ctx);
        goto after_3;
    // 0x80087CC0: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    after_3:
    // 0x80087CC4: j           L_80087D5C
    // 0x80087CC8: nop

        goto L_80087D5C;
    // 0x80087CC8: nop

L_80087CCC:
    // 0x80087CCC: lhu         $t0, 0x66($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X66);
    // 0x80087CD0: lbu         $a3, 0x37($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X37);
    // 0x80087CD4: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x80087CD8: lbu         $t0, 0x3F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3F);
    // 0x80087CDC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80087CE0: lbu         $t0, 0x47($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X47);
    // 0x80087CE4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80087CE8: lhu         $t0, 0x4E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X4E);
    // 0x80087CEC: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x80087CF0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80087CF4: lhu         $t0, 0x56($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X56);
    // 0x80087CF8: andi        $a2, $fp, 0x80
    ctx->r6 = ctx->r30 & 0X80;
    // 0x80087CFC: or          $a2, $s0, $a2
    ctx->r6 = ctx->r16 | ctx->r6;
    // 0x80087D00: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80087D04: lbu         $t0, 0x5F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X5F);
    // 0x80087D08: j           L_80087D40
    // 0x80087D0C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
        goto L_80087D40;
    // 0x80087D0C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
L_80087D10:
    // 0x80087D10: lbu         $t0, 0x3F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3F);
    // 0x80087D14: lbu         $a3, 0x37($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X37);
    // 0x80087D18: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80087D1C: lbu         $t0, 0x47($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X47);
    // 0x80087D20: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80087D24: lhu         $t0, 0x4E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X4E);
    // 0x80087D28: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80087D2C: lhu         $t0, 0x56($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X56);
    // 0x80087D30: srl         $a1, $a0, 16
    ctx->r5 = S32(U32(ctx->r4) >> 16);
    // 0x80087D34: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80087D38: lbu         $t0, 0x5F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X5F);
    // 0x80087D3C: andi        $a2, $fp, 0xFF
    ctx->r6 = ctx->r30 & 0XFF;
L_80087D40:
    // 0x80087D40: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // 0x80087D44: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80087D48: jal         0x800873D4
    // 0x80087D4C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    func_800873D4(rdram, ctx);
        goto after_4;
    // 0x80087D4C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_4:
    // 0x80087D50: j           L_80087D5C
    // 0x80087D54: nop

        goto L_80087D5C;
    // 0x80087D54: nop

L_80087D58:
    // 0x80087D58: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80087D5C:
    // 0x80087D5C: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
    // 0x80087D60: lw          $fp, 0x88($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X88);
    // 0x80087D64: lw          $s7, 0x84($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X84);
    // 0x80087D68: lw          $s6, 0x80($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X80);
    // 0x80087D6C: lw          $s5, 0x7C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X7C);
    // 0x80087D70: lw          $s4, 0x78($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X78);
    // 0x80087D74: lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X74);
    // 0x80087D78: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x80087D7C: lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6C);
    // 0x80087D80: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x80087D84: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x80087D88: jr          $ra
    // 0x80087D8C: nop

    return;
    // 0x80087D8C: nop

;}
RECOMP_FUNC void func_80087D90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087D90: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80087D94: lw          $v0, 0x800($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X800);
    // 0x80087D98: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80087D9C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80087DA0: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x80087DA4: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80087DA8: addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // 0x80087DAC: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80087DB0: addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
    // 0x80087DB4: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80087DB8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80087DBC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80087DC0: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80087DC4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80087DC8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80087DCC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80087DD0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80087DD4: sh          $a0, -0x5370($at)
    MEM_H(-0X5370, ctx->r1) = ctx->r4;
    // 0x80087DD8: beq         $v0, $zero, L_80087E38
    if (ctx->r2 == 0) {
        // 0x80087DDC: addiu       $fp, $zero, 0xC
        ctx->r30 = ADD32(0, 0XC);
            goto L_80087E38;
    }
    // 0x80087DDC: addiu       $fp, $zero, 0xC
    ctx->r30 = ADD32(0, 0XC);
    // 0x80087DE0: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80087DE4: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80087DE8: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_80087DEC:
    // 0x80087DEC: sra         $s2, $v0, 1
    ctx->r18 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80087DF0: addiu       $s1, $s2, -0x1
    ctx->r17 = ADD32(ctx->r18, -0X1);
    // 0x80087DF4: mult        $fp, $s1
    result = S64(S32(ctx->r30)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80087DF8: mflo        $v0
    ctx->r2 = lo;
    // 0x80087DFC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80087E00: addiu       $a0, $a0, -0x5370
    ctx->r4 = ADD32(ctx->r4, -0X5370);
    // 0x80087E04: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80087E08: addiu       $t0, $t0, -0x3380
    ctx->r8 = ADD32(ctx->r8, -0X3380);
    // 0x80087E0C: addu        $s0, $t0, $v0
    ctx->r16 = ADD32(ctx->r8, ctx->r2);
    // 0x80087E10: jal         0x80086218
    // 0x80087E14: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    cmpU16ByValue(rdram, ctx);
        goto after_0;
    // 0x80087E14: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80087E18: beq         $v0, $zero, L_80087E3C
    if (ctx->r2 == 0) {
        // 0x80087E1C: addu        $v1, $s0, $zero
        ctx->r3 = ADD32(ctx->r16, 0);
            goto L_80087E3C;
    }
    // 0x80087E1C: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x80087E20: bgezl       $v0, L_80087E2C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80087E24: addiu       $s4, $s2, 0x1
        ctx->r20 = ADD32(ctx->r18, 0X1);
            goto L_80087E2C;
    }
    goto skip_0;
    // 0x80087E24: addiu       $s4, $s2, 0x1
    ctx->r20 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x80087E28: addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
L_80087E2C:
    // 0x80087E2C: slt         $v0, $s3, $s4
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80087E30: beq         $v0, $zero, L_80087DEC
    if (ctx->r2 == 0) {
        // 0x80087E34: addu        $v0, $s4, $s3
        ctx->r2 = ADD32(ctx->r20, ctx->r19);
            goto L_80087DEC;
    }
    // 0x80087E34: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_80087E38:
    // 0x80087E38: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80087E3C:
    // 0x80087E3C: beq         $v1, $zero, L_80087EB0
    if (ctx->r3 == 0) {
        // 0x80087E40: andi        $v0, $s5, 0xFF
        ctx->r2 = ctx->r21 & 0XFF;
            goto L_80087EB0;
    }
    // 0x80087E40: andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
    // 0x80087E44: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80087E48: bne         $v0, $a3, L_80087E54
    if (ctx->r2 != ctx->r7) {
        // 0x80087E4C: andi        $v0, $s6, 0xFF
        ctx->r2 = ctx->r22 & 0XFF;
            goto L_80087E54;
    }
    // 0x80087E4C: andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // 0x80087E50: lbu         $s5, 0x6($v1)
    ctx->r21 = MEM_BU(ctx->r3, 0X6);
L_80087E54:
    // 0x80087E54: bne         $v0, $a3, L_80087E60
    if (ctx->r2 != ctx->r7) {
        // 0x80087E58: nop
    
            goto L_80087E60;
    }
    // 0x80087E58: nop

    // 0x80087E5C: lbu         $s6, 0x7($v1)
    ctx->r22 = MEM_BU(ctx->r3, 0X7);
L_80087E60:
    // 0x80087E60: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
    // 0x80087E64: lbu         $v0, 0x5($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X5);
    // 0x80087E68: lbu         $a2, 0x4($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X4);
    // 0x80087E6C: lbu         $a1, 0x8($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X8);
    // 0x80087E70: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80087E74: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    // 0x80087E78: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80087E7C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80087E80: lbu         $v1, 0x9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X9);
    // 0x80087E84: andi        $a3, $s6, 0xFF
    ctx->r7 = ctx->r22 & 0XFF;
    // 0x80087E88: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80087E8C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80087E90: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x80087E94: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x80087E98: or          $a0, $a0, $a2
    ctx->r4 = ctx->r4 | ctx->r6;
    // 0x80087E9C: ori         $a1, $a1, 0x80
    ctx->r5 = ctx->r5 | 0X80;
    // 0x80087EA0: andi        $a2, $s5, 0xFF
    ctx->r6 = ctx->r21 & 0XFF;
    // 0x80087EA4: jal         0x800878D0
    // 0x80087EA8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_800878D0(rdram, ctx);
        goto after_1;
    // 0x80087EA8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_1:
    // 0x80087EAC: addu        $s7, $v0, $zero
    ctx->r23 = ADD32(ctx->r2, 0);
L_80087EB0:
    // 0x80087EB0: addu        $v0, $s7, $zero
    ctx->r2 = ADD32(ctx->r23, 0);
    // 0x80087EB4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80087EB8: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80087EBC: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80087EC0: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80087EC4: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80087EC8: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80087ECC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80087ED0: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80087ED4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80087ED8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80087EDC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80087EE0: jr          $ra
    // 0x80087EE4: nop

    return;
    // 0x80087EE4: nop

;}
RECOMP_FUNC void bsearchFactor5TableByU16Key(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087EE8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80087EEC: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80087EF0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80087EF4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80087EF8: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80087EFC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80087F00: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80087F04: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80087F08: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x80087F0C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80087F10: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80087F14: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80087F18: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80087F1C: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80087F20: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80087F24: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80087F28: beq         $v0, $zero, L_80088030
    if (ctx->r2 == 0) {
        // 0x80087F2C: sw          $s4, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r20;
            goto L_80088030;
    }
    // 0x80087F2C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80087F30: jal         0x80092010
    // 0x80087F34: addu        $s5, $s1, $zero
    ctx->r21 = ADD32(ctx->r17, 0);
    factor5MutexAcquire(rdram, ctx);
        goto after_0;
    // 0x80087F34: addu        $s5, $s1, $zero
    ctx->r21 = ADD32(ctx->r17, 0);
    after_0:
    // 0x80087F38: addu        $s6, $s2, $zero
    ctx->r22 = ADD32(ctx->r18, 0);
    // 0x80087F3C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80087F40: lw          $v0, 0x800($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X800);
    // 0x80087F44: addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
    // 0x80087F48: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80087F4C: sh          $s3, -0x5370($at)
    MEM_H(-0X5370, ctx->r1) = ctx->r19;
    // 0x80087F50: beq         $v0, $zero, L_80087FB0
    if (ctx->r2 == 0) {
        // 0x80087F54: addiu       $fp, $zero, 0xC
        ctx->r30 = ADD32(0, 0XC);
            goto L_80087FB0;
    }
    // 0x80087F54: addiu       $fp, $zero, 0xC
    ctx->r30 = ADD32(0, 0XC);
    // 0x80087F58: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80087F5C: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80087F60: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_80087F64:
    // 0x80087F64: sra         $s2, $v0, 1
    ctx->r18 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80087F68: addiu       $s1, $s2, -0x1
    ctx->r17 = ADD32(ctx->r18, -0X1);
    // 0x80087F6C: mult        $fp, $s1
    result = S64(S32(ctx->r30)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80087F70: mflo        $v0
    ctx->r2 = lo;
    // 0x80087F74: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80087F78: addiu       $a0, $a0, -0x5370
    ctx->r4 = ADD32(ctx->r4, -0X5370);
    // 0x80087F7C: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80087F80: addiu       $t0, $t0, -0x3380
    ctx->r8 = ADD32(ctx->r8, -0X3380);
    // 0x80087F84: addu        $s0, $t0, $v0
    ctx->r16 = ADD32(ctx->r8, ctx->r2);
    // 0x80087F88: jal         0x80086218
    // 0x80087F8C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    cmpU16ByValue(rdram, ctx);
        goto after_1;
    // 0x80087F8C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80087F90: beq         $v0, $zero, L_80087FB4
    if (ctx->r2 == 0) {
        // 0x80087F94: addu        $v1, $s0, $zero
        ctx->r3 = ADD32(ctx->r16, 0);
            goto L_80087FB4;
    }
    // 0x80087F94: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x80087F98: bgezl       $v0, L_80087FA4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80087F9C: addiu       $s4, $s2, 0x1
        ctx->r20 = ADD32(ctx->r18, 0X1);
            goto L_80087FA4;
    }
    goto skip_0;
    // 0x80087F9C: addiu       $s4, $s2, 0x1
    ctx->r20 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x80087FA0: addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
L_80087FA4:
    // 0x80087FA4: slt         $v0, $s3, $s4
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80087FA8: beq         $v0, $zero, L_80087F64
    if (ctx->r2 == 0) {
        // 0x80087FAC: addu        $v0, $s4, $s3
        ctx->r2 = ADD32(ctx->r20, ctx->r19);
            goto L_80087F64;
    }
    // 0x80087FAC: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_80087FB0:
    // 0x80087FB0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80087FB4:
    // 0x80087FB4: beq         $v1, $zero, L_80088028
    if (ctx->r3 == 0) {
        // 0x80087FB8: andi        $v0, $s5, 0xFF
        ctx->r2 = ctx->r21 & 0XFF;
            goto L_80088028;
    }
    // 0x80087FB8: andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
    // 0x80087FBC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80087FC0: bne         $v0, $a3, L_80087FCC
    if (ctx->r2 != ctx->r7) {
        // 0x80087FC4: andi        $v0, $s6, 0xFF
        ctx->r2 = ctx->r22 & 0XFF;
            goto L_80087FCC;
    }
    // 0x80087FC4: andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // 0x80087FC8: lbu         $s5, 0x6($v1)
    ctx->r21 = MEM_BU(ctx->r3, 0X6);
L_80087FCC:
    // 0x80087FCC: bne         $v0, $a3, L_80087FD8
    if (ctx->r2 != ctx->r7) {
        // 0x80087FD0: nop
    
            goto L_80087FD8;
    }
    // 0x80087FD0: nop

    // 0x80087FD4: lbu         $s6, 0x7($v1)
    ctx->r22 = MEM_BU(ctx->r3, 0X7);
L_80087FD8:
    // 0x80087FD8: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
    // 0x80087FDC: lbu         $v0, 0x5($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X5);
    // 0x80087FE0: lbu         $a2, 0x4($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X4);
    // 0x80087FE4: lbu         $a1, 0x8($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X8);
    // 0x80087FE8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80087FEC: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    // 0x80087FF0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80087FF4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80087FF8: lbu         $v1, 0x9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X9);
    // 0x80087FFC: andi        $a3, $s6, 0xFF
    ctx->r7 = ctx->r22 & 0XFF;
    // 0x80088000: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80088004: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80088008: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8008800C: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x80088010: or          $a0, $a0, $a2
    ctx->r4 = ctx->r4 | ctx->r6;
    // 0x80088014: ori         $a1, $a1, 0x80
    ctx->r5 = ctx->r5 | 0X80;
    // 0x80088018: andi        $a2, $s5, 0xFF
    ctx->r6 = ctx->r21 & 0XFF;
    // 0x8008801C: jal         0x800878D0
    // 0x80088020: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_800878D0(rdram, ctx);
        goto after_2;
    // 0x80088020: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_2:
    // 0x80088024: addu        $s7, $v0, $zero
    ctx->r23 = ADD32(ctx->r2, 0);
L_80088028:
    // 0x80088028: jal         0x8009205C
    // 0x8008802C: addu        $s0, $s7, $zero
    ctx->r16 = ADD32(ctx->r23, 0);
    factor5MutexRelease(rdram, ctx);
        goto after_3;
    // 0x8008802C: addu        $s0, $s7, $zero
    ctx->r16 = ADD32(ctx->r23, 0);
    after_3:
L_80088030:
    // 0x80088030: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x80088034: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80088038: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8008803C: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80088040: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80088044: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80088048: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8008804C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80088050: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80088054: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80088058: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8008805C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80088060: jr          $ra
    // 0x80088064: nop

    return;
    // 0x80088064: nop

;}
RECOMP_FUNC void func_80088068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088068: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8008806C: beq         $a0, $v0, L_800880C0
    if (ctx->r4 == ctx->r2) {
        // 0x80088070: addiu       $a1, $zero, -0x1
        ctx->r5 = ADD32(0, -0X1);
            goto L_800880C0;
    }
    // 0x80088070: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80088074: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80088078: lw          $v1, -0x5100($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5100);
    // 0x8008807C: beq         $v1, $zero, L_800880A4
    if (ctx->r3 == 0) {
        // 0x80088080: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800880A4;
    }
    // 0x80088080: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80088084:
    // 0x80088084: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80088088: beq         $v0, $a0, L_800880B8
    if (ctx->r2 == ctx->r4) {
        // 0x8008808C: sltu        $v0, $a0, $v0
        ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
            goto L_800880B8;
    }
    // 0x8008808C: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80088090: bne         $v0, $zero, L_800880A4
    if (ctx->r2 != 0) {
        // 0x80088094: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800880A4;
    }
    // 0x80088094: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80088098: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8008809C: bne         $v1, $zero, L_80088084
    if (ctx->r3 != 0) {
        // 0x800880A0: nop
    
            goto L_80088084;
    }
    // 0x800880A0: nop

L_800880A4:
    // 0x800880A4: beq         $v0, $zero, L_800880C0
    if (ctx->r2 == 0) {
        // 0x800880A8: addiu       $a1, $zero, -0x1
        ctx->r5 = ADD32(0, -0X1);
            goto L_800880C0;
    }
    // 0x800880A8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800880AC: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x800880B0: j           L_800880C4
    // 0x800880B4: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_800880C4;
    // 0x800880B4: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_800880B8:
    // 0x800880B8: j           L_800880A4
    // 0x800880BC: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_800880A4;
    // 0x800880BC: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_800880C0:
    // 0x800880C0: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_800880C4:
    // 0x800880C4: bne         $a1, $v1, L_800880D0
    if (ctx->r5 != ctx->r3) {
        // 0x800880C8: addu        $v0, $a0, $zero
        ctx->r2 = ADD32(ctx->r4, 0);
            goto L_800880D0;
    }
    // 0x800880C8: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x800880CC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800880D0:
    // 0x800880D0: jr          $ra
    // 0x800880D4: nop

    return;
    // 0x800880D4: nop

;}
RECOMP_FUNC void func_800880D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800880D8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800880DC: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x800880E0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800880E4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800880E8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800880EC: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800880F0: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x800880F4: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x800880F8: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x800880FC: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80088100: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80088104: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80088108: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8008810C: beq         $v0, $zero, L_800881C4
    if (ctx->r2 == 0) {
        // 0x80088110: sw          $s1, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r17;
            goto L_800881C4;
    }
    // 0x80088110: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80088114: jal         0x80092010
    // 0x80088118: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
    factor5MutexAcquire(rdram, ctx);
        goto after_0;
    // 0x80088118: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
    after_0:
    // 0x8008811C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80088120: lw          $v0, 0x800($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X800);
    // 0x80088124: lui         $s7, 0x8014
    ctx->r23 = S32(0X8014 << 16);
    // 0x80088128: addiu       $s7, $s7, -0x3380
    ctx->r23 = ADD32(ctx->r23, -0X3380);
    // 0x8008812C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088130: sh          $s0, -0x5370($at)
    MEM_H(-0X5370, ctx->r1) = ctx->r16;
    // 0x80088134: beq         $v0, $zero, L_80088190
    if (ctx->r2 == 0) {
        // 0x80088138: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80088190;
    }
    // 0x80088138: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8008813C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80088140: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80088144: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_80088148:
    // 0x80088148: sra         $s2, $v0, 1
    ctx->r18 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8008814C: addiu       $s1, $s2, -0x1
    ctx->r17 = ADD32(ctx->r18, -0X1);
    // 0x80088150: mult        $s6, $s1
    result = S64(S32(ctx->r22)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80088154: mflo        $v0
    ctx->r2 = lo;
    // 0x80088158: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008815C: addiu       $a0, $a0, -0x5370
    ctx->r4 = ADD32(ctx->r4, -0X5370);
    // 0x80088160: addu        $s0, $s7, $v0
    ctx->r16 = ADD32(ctx->r23, ctx->r2);
    // 0x80088164: jal         0x80086218
    // 0x80088168: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    cmpU16ByValue(rdram, ctx);
        goto after_1;
    // 0x80088168: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8008816C: beql        $v0, $zero, L_80088190
    if (ctx->r2 == 0) {
        // 0x80088170: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_80088190;
    }
    goto skip_0;
    // 0x80088170: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    skip_0:
    // 0x80088174: bgezl       $v0, L_80088180
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80088178: addiu       $s4, $s2, 0x1
        ctx->r20 = ADD32(ctx->r18, 0X1);
            goto L_80088180;
    }
    goto skip_1;
    // 0x80088178: addiu       $s4, $s2, 0x1
    ctx->r20 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x8008817C: addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
L_80088180:
    // 0x80088180: slt         $v0, $s3, $s4
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80088184: beq         $v0, $zero, L_80088148
    if (ctx->r2 == 0) {
        // 0x80088188: addu        $v0, $s4, $s3
        ctx->r2 = ADD32(ctx->r20, ctx->r19);
            goto L_80088148;
    }
    // 0x80088188: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
    // 0x8008818C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80088190:
    // 0x80088190: beq         $a1, $zero, L_800881BC
    if (ctx->r5 == 0) {
        // 0x80088194: andi        $a0, $s5, 0xFF
        ctx->r4 = ctx->r21 & 0XFF;
            goto L_800881BC;
    }
    // 0x80088194: andi        $a0, $s5, 0xFF
    ctx->r4 = ctx->r21 & 0XFF;
    // 0x80088198: addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // 0x8008819C: beq         $a0, $v0, L_800881B8
    if (ctx->r4 == ctx->r2) {
        // 0x800881A0: addiu       $v0, $zero, 0x1F
        ctx->r2 = ADD32(0, 0X1F);
            goto L_800881B8;
    }
    // 0x800881A0: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
    // 0x800881A4: sb          $s5, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r21;
    // 0x800881A8: jal         0x8008E54C
    // 0x800881AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8008E54C(rdram, ctx);
        goto after_2;
    // 0x800881AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x800881B0: j           L_800881BC
    // 0x800881B4: nop

        goto L_800881BC;
    // 0x800881B4: nop

L_800881B8:
    // 0x800881B8: sb          $v0, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r2;
L_800881BC:
    // 0x800881BC: jal         0x8009205C
    // 0x800881C0: nop

    factor5MutexRelease(rdram, ctx);
        goto after_3;
    // 0x800881C0: nop

    after_3:
L_800881C4:
    // 0x800881C4: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x800881C8: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x800881CC: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x800881D0: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800881D4: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800881D8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800881DC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800881E0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800881E4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800881E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800881EC: jr          $ra
    // 0x800881F0: nop

    return;
    // 0x800881F0: nop

;}
RECOMP_FUNC void func_800881F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800881F4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800881F8: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x800881FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80088200: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80088204: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80088208: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8008820C: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80088210: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80088214: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x80088218: beq         $v0, $zero, L_800883A4
    if (ctx->r2 == 0) {
        // 0x8008821C: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800883A4;
    }
    // 0x8008821C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80088220: jal         0x80092010
    // 0x80088224: nop

    factor5MutexAcquire(rdram, ctx);
        goto after_0;
    // 0x80088224: nop

    after_0:
    // 0x80088228: beq         $s0, $s1, L_8008827C
    if (ctx->r16 == ctx->r17) {
        // 0x8008822C: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_8008827C;
    }
    // 0x8008822C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80088230: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80088234: lw          $v1, -0x5100($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5100);
    // 0x80088238: beq         $v1, $zero, L_80088260
    if (ctx->r3 == 0) {
        // 0x8008823C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80088260;
    }
    // 0x8008823C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80088240:
    // 0x80088240: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80088244: beq         $v0, $s0, L_80088274
    if (ctx->r2 == ctx->r16) {
        // 0x80088248: sltu        $v0, $s0, $v0
        ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
            goto L_80088274;
    }
    // 0x80088248: sltu        $v0, $s0, $v0
    ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x8008824C: bne         $v0, $zero, L_80088260
    if (ctx->r2 != 0) {
        // 0x80088250: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80088260;
    }
    // 0x80088250: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80088254: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80088258: bne         $v1, $zero, L_80088240
    if (ctx->r3 != 0) {
        // 0x8008825C: nop
    
            goto L_80088240;
    }
    // 0x8008825C: nop

L_80088260:
    // 0x80088260: beq         $v0, $zero, L_8008827C
    if (ctx->r2 == 0) {
        // 0x80088264: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_8008827C;
    }
    // 0x80088264: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80088268: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x8008826C: j           L_80088280
    // 0x80088270: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
        goto L_80088280;
    // 0x80088270: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
L_80088274:
    // 0x80088274: j           L_80088260
    // 0x80088278: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80088260;
    // 0x80088278: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8008827C:
    // 0x8008827C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
L_80088280:
    // 0x80088280: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80088284: beq         $s0, $v0, L_8008839C
    if (ctx->r16 == ctx->r2) {
        // 0x80088288: addiu       $t2, $zero, 0xFF
        ctx->r10 = ADD32(0, 0XFF);
            goto L_8008839C;
    }
    // 0x80088288: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8008828C: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80088290: addiu       $t1, $t1, 0x40C8
    ctx->r9 = ADD32(ctx->r9, 0X40C8);
    // 0x80088294: andi        $a1, $s2, 0x7F
    ctx->r5 = ctx->r18 & 0X7F;
    // 0x80088298: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x8008829C: addiu       $t0, $t0, 0xA10
    ctx->r8 = ADD32(ctx->r8, 0XA10);
L_800882A0:
    // 0x800882A0: andi        $a3, $s0, 0xFF
    ctx->r7 = ctx->r16 & 0XFF;
    // 0x800882A4: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x800882A8: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x800882AC: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800882B0: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x800882B4: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800882B8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800882BC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800882C0: lw          $v0, -0x271C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X271C);
    // 0x800882C4: bne         $v0, $s0, L_8008839C
    if (ctx->r2 != ctx->r16) {
        // 0x800882C8: nop
    
            goto L_8008839C;
    }
    // 0x800882C8: nop

    // 0x800882CC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800882D0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800882D4: lw          $v0, -0x275C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X275C);
    // 0x800882D8: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800882DC: beq         $v0, $zero, L_80088300
    if (ctx->r2 == 0) {
        // 0x800882E0: nop
    
            goto L_80088300;
    }
    // 0x800882E0: nop

    // 0x800882E4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800882E8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800882EC: lbu         $a2, -0x2727($at)
    ctx->r6 = MEM_BU(ctx->r1, -0X2727);
    // 0x800882F0: bne         $a2, $t2, L_80088314
    if (ctx->r6 != ctx->r10) {
        // 0x800882F4: addu        $v1, $a3, $zero
        ctx->r3 = ADD32(ctx->r7, 0);
            goto L_80088314;
    }
    // 0x800882F4: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
    // 0x800882F8: j           L_80088354
    // 0x800882FC: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_80088354;
    // 0x800882FC: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_80088300:
    // 0x80088300: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088304: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80088308: lbu         $a2, -0x2731($at)
    ctx->r6 = MEM_BU(ctx->r1, -0X2731);
    // 0x8008830C: beq         $a2, $t2, L_80088350
    if (ctx->r6 == ctx->r10) {
        // 0x80088310: addu        $v1, $a3, $zero
        ctx->r3 = ADD32(ctx->r7, 0);
            goto L_80088350;
    }
    // 0x80088310: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
L_80088314:
    // 0x80088314: sll         $v0, $a2, 4
    ctx->r2 = S32(ctx->r6 << 4);
    // 0x80088318: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8008831C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80088320: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80088324: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80088328: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8008832C: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x80088330: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x80088334: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80088338: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8008833C: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80088340: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80088344: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80088348: j           L_80088370
    // 0x8008834C: sb          $a1, 0x40($v1)
    MEM_B(0X40, ctx->r3) = ctx->r5;
        goto L_80088370;
    // 0x8008834C: sb          $a1, 0x40($v1)
    MEM_B(0X40, ctx->r3) = ctx->r5;
L_80088350:
    // 0x80088350: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_80088354:
    // 0x80088354: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80088358: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008835C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80088360: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80088364: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80088368: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8008836C: sb          $a1, 0x40($v0)
    MEM_B(0X40, ctx->r2) = ctx->r5;
L_80088370:
    // 0x80088370: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x80088374: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80088378: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8008837C: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x80088380: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80088384: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088388: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8008838C: lw          $s0, -0x2770($at)
    ctx->r16 = MEM_W(ctx->r1, -0X2770);
    // 0x80088390: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80088394: bne         $s0, $v0, L_800882A0
    if (ctx->r16 != ctx->r2) {
        // 0x80088398: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_800882A0;
    }
    // 0x80088398: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_8008839C:
    // 0x8008839C: jal         0x8009205C
    // 0x800883A0: nop

    factor5MutexRelease(rdram, ctx);
        goto after_1;
    // 0x800883A0: nop

    after_1:
L_800883A4:
    // 0x800883A4: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x800883A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800883AC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800883B0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800883B4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800883B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800883BC: jr          $ra
    // 0x800883C0: nop

    return;
    // 0x800883C0: nop

;}
RECOMP_FUNC void func_800883C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800883C4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800883C8: beql        $a0, $a2, L_8008841C
    if (ctx->r4 == ctx->r6) {
        // 0x800883CC: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_8008841C;
    }
    goto skip_0;
    // 0x800883CC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    skip_0:
    // 0x800883D0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800883D4: lw          $v1, -0x5100($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5100);
    // 0x800883D8: beq         $v1, $zero, L_80088400
    if (ctx->r3 == 0) {
        // 0x800883DC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80088400;
    }
    // 0x800883DC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800883E0:
    // 0x800883E0: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800883E4: beq         $v0, $a0, L_80088414
    if (ctx->r2 == ctx->r4) {
        // 0x800883E8: sltu        $v0, $a0, $v0
        ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
            goto L_80088414;
    }
    // 0x800883E8: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x800883EC: bne         $v0, $zero, L_80088400
    if (ctx->r2 != 0) {
        // 0x800883F0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80088400;
    }
    // 0x800883F0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800883F4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800883F8: bne         $v1, $zero, L_800883E0
    if (ctx->r3 != 0) {
        // 0x800883FC: nop
    
            goto L_800883E0;
    }
    // 0x800883FC: nop

L_80088400:
    // 0x80088400: beq         $v0, $zero, L_8008841C
    if (ctx->r2 == 0) {
        // 0x80088404: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_8008841C;
    }
    // 0x80088404: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80088408: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x8008840C: j           L_80088420
    // 0x80088410: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80088420;
    // 0x80088410: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80088414:
    // 0x80088414: j           L_80088400
    // 0x80088418: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80088400;
    // 0x80088418: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8008841C:
    // 0x8008841C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80088420:
    // 0x80088420: beq         $a0, $v0, L_8008853C
    if (ctx->r4 == ctx->r2) {
        // 0x80088424: nop
    
            goto L_8008853C;
    }
    // 0x80088424: nop

    // 0x80088428: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8008842C: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80088430: addiu       $t1, $t1, 0x40C8
    ctx->r9 = ADD32(ctx->r9, 0X40C8);
    // 0x80088434: andi        $a1, $a1, 0x7F
    ctx->r5 = ctx->r5 & 0X7F;
    // 0x80088438: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x8008843C: addiu       $t0, $t0, 0xA10
    ctx->r8 = ADD32(ctx->r8, 0XA10);
    // 0x80088440: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_80088444:
    // 0x80088444: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x80088448: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x8008844C: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80088450: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80088454: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x80088458: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8008845C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088460: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80088464: lw          $v0, -0x271C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X271C);
    // 0x80088468: bne         $v0, $a0, L_8008853C
    if (ctx->r2 != ctx->r4) {
        // 0x8008846C: nop
    
            goto L_8008853C;
    }
    // 0x8008846C: nop

    // 0x80088470: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088474: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80088478: lw          $v0, -0x275C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X275C);
    // 0x8008847C: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80088480: beq         $v0, $zero, L_800884A4
    if (ctx->r2 == 0) {
        // 0x80088484: nop
    
            goto L_800884A4;
    }
    // 0x80088484: nop

    // 0x80088488: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008848C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80088490: lbu         $a2, -0x2727($at)
    ctx->r6 = MEM_BU(ctx->r1, -0X2727);
    // 0x80088494: bne         $a2, $t2, L_800884B8
    if (ctx->r6 != ctx->r10) {
        // 0x80088498: addu        $v1, $a3, $zero
        ctx->r3 = ADD32(ctx->r7, 0);
            goto L_800884B8;
    }
    // 0x80088498: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
    // 0x8008849C: j           L_800884F8
    // 0x800884A0: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_800884F8;
    // 0x800884A0: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_800884A4:
    // 0x800884A4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800884A8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800884AC: lbu         $a2, -0x2731($at)
    ctx->r6 = MEM_BU(ctx->r1, -0X2731);
    // 0x800884B0: beq         $a2, $t2, L_800884F4
    if (ctx->r6 == ctx->r10) {
        // 0x800884B4: addu        $v1, $a3, $zero
        ctx->r3 = ADD32(ctx->r7, 0);
            goto L_800884F4;
    }
    // 0x800884B4: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
L_800884B8:
    // 0x800884B8: sll         $v0, $a2, 4
    ctx->r2 = S32(ctx->r6 << 4);
    // 0x800884BC: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800884C0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800884C4: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x800884C8: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800884CC: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800884D0: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x800884D4: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x800884D8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800884DC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800884E0: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800884E4: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800884E8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800884EC: j           L_80088514
    // 0x800884F0: sb          $a1, 0xA($v1)
    MEM_B(0XA, ctx->r3) = ctx->r5;
        goto L_80088514;
    // 0x800884F0: sb          $a1, 0xA($v1)
    MEM_B(0XA, ctx->r3) = ctx->r5;
L_800884F4:
    // 0x800884F4: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_800884F8:
    // 0x800884F8: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x800884FC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80088500: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80088504: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80088508: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8008850C: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80088510: sb          $a1, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r5;
L_80088514:
    // 0x80088514: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x80088518: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8008851C: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80088520: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x80088524: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80088528: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008852C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80088530: lw          $a0, -0x2770($at)
    ctx->r4 = MEM_W(ctx->r1, -0X2770);
    // 0x80088534: bne         $a0, $t3, L_80088444
    if (ctx->r4 != ctx->r11) {
        // 0x80088538: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_80088444;
    }
    // 0x80088538: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_8008853C:
    // 0x8008853C: jr          $ra
    // 0x80088540: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    return;
    // 0x80088540: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
;}
RECOMP_FUNC void func_80088544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088544: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80088548: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x8008854C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80088550: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80088554: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80088558: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8008855C: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80088560: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80088564: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80088568: beq         $v0, $zero, L_8008858C
    if (ctx->r2 == 0) {
        // 0x8008856C: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8008858C;
    }
    // 0x8008856C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80088570: jal         0x80092010
    // 0x80088574: nop

    factor5MutexAcquire(rdram, ctx);
        goto after_0;
    // 0x80088574: nop

    after_0:
    // 0x80088578: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8008857C: jal         0x800883C4
    // 0x80088580: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    func_800883C4(rdram, ctx);
        goto after_1;
    // 0x80088580: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    after_1:
    // 0x80088584: jal         0x8009205C
    // 0x80088588: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    factor5MutexRelease(rdram, ctx);
        goto after_2;
    // 0x80088588: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_2:
L_8008858C:
    // 0x8008858C: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x80088590: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80088594: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80088598: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8008859C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800885A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800885A4: jr          $ra
    // 0x800885A8: nop

    return;
    // 0x800885A8: nop

;}
RECOMP_FUNC void func_800885AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800885AC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800885B0: beql        $a0, $a2, L_80088604
    if (ctx->r4 == ctx->r6) {
        // 0x800885B4: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_80088604;
    }
    goto skip_0;
    // 0x800885B4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    skip_0:
    // 0x800885B8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800885BC: lw          $v1, -0x5100($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5100);
    // 0x800885C0: beq         $v1, $zero, L_800885E8
    if (ctx->r3 == 0) {
        // 0x800885C4: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800885E8;
    }
    // 0x800885C4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800885C8:
    // 0x800885C8: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800885CC: beq         $v0, $a0, L_800885FC
    if (ctx->r2 == ctx->r4) {
        // 0x800885D0: sltu        $v0, $a0, $v0
        ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
            goto L_800885FC;
    }
    // 0x800885D0: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x800885D4: bne         $v0, $zero, L_800885E8
    if (ctx->r2 != 0) {
        // 0x800885D8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800885E8;
    }
    // 0x800885D8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800885DC: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800885E0: bne         $v1, $zero, L_800885C8
    if (ctx->r3 != 0) {
        // 0x800885E4: nop
    
            goto L_800885C8;
    }
    // 0x800885E4: nop

L_800885E8:
    // 0x800885E8: beq         $v0, $zero, L_80088604
    if (ctx->r2 == 0) {
        // 0x800885EC: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_80088604;
    }
    // 0x800885EC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800885F0: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x800885F4: j           L_80088608
    // 0x800885F8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80088608;
    // 0x800885F8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800885FC:
    // 0x800885FC: j           L_800885E8
    // 0x80088600: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_800885E8;
    // 0x80088600: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80088604:
    // 0x80088604: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80088608:
    // 0x80088608: beq         $a0, $v0, L_80088724
    if (ctx->r4 == ctx->r2) {
        // 0x8008860C: nop
    
            goto L_80088724;
    }
    // 0x8008860C: nop

    // 0x80088610: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80088614: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80088618: addiu       $t1, $t1, 0x40C8
    ctx->r9 = ADD32(ctx->r9, 0X40C8);
    // 0x8008861C: andi        $a1, $a1, 0x7F
    ctx->r5 = ctx->r5 & 0X7F;
    // 0x80088620: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80088624: addiu       $t0, $t0, 0xA10
    ctx->r8 = ADD32(ctx->r8, 0XA10);
    // 0x80088628: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_8008862C:
    // 0x8008862C: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x80088630: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x80088634: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80088638: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8008863C: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x80088640: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80088644: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088648: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008864C: lw          $v0, -0x271C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X271C);
    // 0x80088650: bne         $v0, $a0, L_80088724
    if (ctx->r2 != ctx->r4) {
        // 0x80088654: nop
    
            goto L_80088724;
    }
    // 0x80088654: nop

    // 0x80088658: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008865C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80088660: lw          $v0, -0x275C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X275C);
    // 0x80088664: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80088668: beq         $v0, $zero, L_8008868C
    if (ctx->r2 == 0) {
        // 0x8008866C: nop
    
            goto L_8008868C;
    }
    // 0x8008866C: nop

    // 0x80088670: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088674: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80088678: lbu         $a2, -0x2727($at)
    ctx->r6 = MEM_BU(ctx->r1, -0X2727);
    // 0x8008867C: bne         $a2, $t2, L_800886A0
    if (ctx->r6 != ctx->r10) {
        // 0x80088680: addu        $v1, $a3, $zero
        ctx->r3 = ADD32(ctx->r7, 0);
            goto L_800886A0;
    }
    // 0x80088680: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
    // 0x80088684: j           L_800886E0
    // 0x80088688: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_800886E0;
    // 0x80088688: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_8008868C:
    // 0x8008868C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088690: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80088694: lbu         $a2, -0x2731($at)
    ctx->r6 = MEM_BU(ctx->r1, -0X2731);
    // 0x80088698: beq         $a2, $t2, L_800886DC
    if (ctx->r6 == ctx->r10) {
        // 0x8008869C: addu        $v1, $a3, $zero
        ctx->r3 = ADD32(ctx->r7, 0);
            goto L_800886DC;
    }
    // 0x8008869C: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
L_800886A0:
    // 0x800886A0: sll         $v0, $a2, 4
    ctx->r2 = S32(ctx->r6 << 4);
    // 0x800886A4: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800886A8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800886AC: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x800886B0: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800886B4: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800886B8: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x800886BC: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x800886C0: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800886C4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800886C8: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800886CC: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800886D0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800886D4: j           L_800886FC
    // 0x800886D8: sb          $a1, 0x83($v1)
    MEM_B(0X83, ctx->r3) = ctx->r5;
        goto L_800886FC;
    // 0x800886D8: sb          $a1, 0x83($v1)
    MEM_B(0X83, ctx->r3) = ctx->r5;
L_800886DC:
    // 0x800886DC: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_800886E0:
    // 0x800886E0: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x800886E4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800886E8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800886EC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800886F0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800886F4: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x800886F8: sb          $a1, 0x83($v0)
    MEM_B(0X83, ctx->r2) = ctx->r5;
L_800886FC:
    // 0x800886FC: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x80088700: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80088704: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80088708: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x8008870C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80088710: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80088714: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80088718: lw          $a0, -0x2770($at)
    ctx->r4 = MEM_W(ctx->r1, -0X2770);
    // 0x8008871C: bne         $a0, $t3, L_8008862C
    if (ctx->r4 != ctx->r11) {
        // 0x80088720: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_8008862C;
    }
    // 0x80088720: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80088724:
    // 0x80088724: jr          $ra
    // 0x80088728: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    return;
    // 0x80088728: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
;}
