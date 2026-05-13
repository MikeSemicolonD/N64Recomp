#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void removeLookupTableEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800643C4: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x800643C8: lhu         $v0, 0x4($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X4);
    // 0x800643CC: beq         $v0, $zero, L_80064480
    if (ctx->r2 == 0) {
        // 0x800643D0: nop
    
            goto L_80064480;
    }
    // 0x800643D0: nop

    // 0x800643D4: beq         $v0, $zero, L_80064410
    if (ctx->r2 == 0) {
        // 0x800643D8: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80064410;
    }
    // 0x800643D8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800643DC: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x800643E0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800643E4: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
L_800643E8:
    // 0x800643E8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800643EC: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x800643F0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800643F4: beq         $v0, $a1, L_80064410
    if (ctx->r2 == ctx->r5) {
        // 0x800643F8: nop
    
            goto L_80064410;
    }
    // 0x800643F8: nop

    // 0x800643FC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80064400: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80064404: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80064408: bne         $v0, $zero, L_800643E8
    if (ctx->r2 != 0) {
        // 0x8006440C: andi        $v0, $a0, 0xFF
        ctx->r2 = ctx->r4 & 0XFF;
            goto L_800643E8;
    }
    // 0x8006440C: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
L_80064410:
    // 0x80064410: lhu         $v1, 0x4($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X4);
    // 0x80064414: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80064418: beq         $v0, $v1, L_80064474
    if (ctx->r2 == ctx->r3) {
        // 0x8006441C: addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
            goto L_80064474;
    }
    // 0x8006441C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80064420: j           L_80064460
    // 0x80064424: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80064460;
    // 0x80064424: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80064428:
    // 0x80064428: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8006442C: addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // 0x80064430: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80064434: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80064438: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8006443C: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80064440: lbu         $v1, 0xC($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XC);
    // 0x80064444: sb          $v1, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r3;
    // 0x80064448: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8006444C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80064450: lbu         $v0, 0xD($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XD);
    // 0x80064454: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80064458: sb          $v0, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r2;
    // 0x8006445C: lhu         $v0, 0x4($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X4);
L_80064460:
    // 0x80064460: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x80064464: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80064468: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006446C: bne         $v0, $zero, L_80064428
    if (ctx->r2 != 0) {
        // 0x80064470: sll         $a0, $a0, 3
        ctx->r4 = S32(ctx->r4 << 3);
            goto L_80064428;
    }
    // 0x80064470: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
L_80064474:
    // 0x80064474: lhu         $v0, 0x4($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X4);
    // 0x80064478: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8006447C: sh          $v0, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r2;
L_80064480:
    // 0x80064480: jr          $ra
    // 0x80064484: nop

    return;
    // 0x80064484: nop

;}
RECOMP_FUNC void func_80064488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064488: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006448C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80064490: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80064494: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x80064498: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006449C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800644A0: jal         0x80001ACC
    // 0x800644A4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x800644A4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x800644A8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800644AC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800644B0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800644B4: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x800644B8: beq         $v0, $zero, L_80064540
    if (ctx->r2 == 0) {
        // 0x800644BC: addu        $a2, $a1, $zero
        ctx->r6 = ADD32(ctx->r5, 0);
            goto L_80064540;
    }
    // 0x800644BC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800644C0: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
L_800644C4:
    // 0x800644C4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800644C8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800644CC: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // 0x800644D0: lbu         $v0, 0x5($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X5);
    // 0x800644D4: beql        $v0, $zero, L_8006452C
    if (ctx->r2 == 0) {
        // 0x800644D8: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8006452C;
    }
    goto skip_0;
    // 0x800644D8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_0:
    // 0x800644DC: lw          $s0, 0x0($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X0);
    // 0x800644E0: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x800644E4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800644E8: beq         $v0, $zero, L_800644FC
    if (ctx->r2 == 0) {
        // 0x800644EC: nop
    
            goto L_800644FC;
    }
    // 0x800644EC: nop

    // 0x800644F0: lbu         $v0, 0x2F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2F);
    // 0x800644F4: beql        $v0, $zero, L_8006452C
    if (ctx->r2 == 0) {
        // 0x800644F8: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8006452C;
    }
    goto skip_1;
    // 0x800644F8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_1:
L_800644FC:
    // 0x800644FC: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x80064500: beql        $v0, $zero, L_8006452C
    if (ctx->r2 == 0) {
        // 0x80064504: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8006452C;
    }
    goto skip_2;
    // 0x80064504: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_2:
    // 0x80064508: lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XA);
    // 0x8006450C: beq         $v0, $zero, L_80064528
    if (ctx->r2 == 0) {
        // 0x80064510: addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
            goto L_80064528;
    }
    // 0x80064510: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x80064514: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80064518: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8006451C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80064520: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80064524: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
L_80064528:
    // 0x80064528: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8006452C:
    // 0x8006452C: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
    // 0x80064530: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x80064534: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80064538: bne         $v0, $zero, L_800644C4
    if (ctx->r2 != 0) {
        // 0x8006453C: andi        $v0, $a2, 0xFF
        ctx->r2 = ctx->r6 & 0XFF;
            goto L_800644C4;
    }
    // 0x8006453C: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
L_80064540:
    // 0x80064540: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x80064544: beq         $v0, $zero, L_800645A8
    if (ctx->r2 == 0) {
        // 0x80064548: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_800645A8;
    }
    // 0x80064548: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8006454C: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x80064550: addiu       $t0, $a3, -0x1
    ctx->r8 = ADD32(ctx->r7, -0X1);
    // 0x80064554: andi        $v1, $a2, 0xFF
    ctx->r3 = ctx->r6 & 0XFF;
L_80064558:
    // 0x80064558: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8006455C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80064560: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80064564: beql        $v1, $zero, L_80064574
    if (ctx->r3 == 0) {
        // 0x80064568: sw          $zero, 0x4($a1)
        MEM_W(0X4, ctx->r5) = 0;
            goto L_80064574;
    }
    goto skip_3;
    // 0x80064568: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    skip_3:
    // 0x8006456C: lw          $v0, -0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4);
    // 0x80064570: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
L_80064574:
    // 0x80064574: andi        $v1, $a2, 0xFF
    ctx->r3 = ctx->r6 & 0XFF;
    // 0x80064578: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8006457C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80064580: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80064584: beql        $v1, $t0, L_80064594
    if (ctx->r3 == ctx->r8) {
        // 0x80064588: sw          $zero, 0x0($a1)
        MEM_W(0X0, ctx->r5) = 0;
            goto L_80064594;
    }
    goto skip_4;
    // 0x80064588: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    skip_4:
    // 0x8006458C: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80064590: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_80064594:
    // 0x80064594: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80064598: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x8006459C: sltu        $v0, $v0, $a3
    ctx->r2 = ctx->r2 < ctx->r7 ? 1 : 0;
    // 0x800645A0: bne         $v0, $zero, L_80064558
    if (ctx->r2 != 0) {
        // 0x800645A4: andi        $v1, $a2, 0xFF
        ctx->r3 = ctx->r6 & 0XFF;
            goto L_80064558;
    }
    // 0x800645A4: andi        $v1, $a2, 0xFF
    ctx->r3 = ctx->r6 & 0XFF;
L_800645A8:
    // 0x800645A8: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x800645AC: jal         0x80001C98
    // 0x800645B0: nop

    rs_free(rdram, ctx);
        goto after_1;
    // 0x800645B0: nop

    after_1:
    // 0x800645B4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800645B8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800645BC: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x800645C0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800645C4: jr          $ra
    // 0x800645C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800645C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void allocateSlotTable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800645CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800645D0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800645D4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800645D8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x800645DC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800645E0: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800645E4: jal         0x80001ACC
    // 0x800645E8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x800645E8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_0:
    // 0x800645EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800645F0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800645F4: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x800645F8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800645FC: jal         0x80001ACC
    // 0x80064600: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x80064600: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    after_1:
    // 0x80064604: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80064608: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x8006460C: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x80064610: sh          $s0, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r16;
    // 0x80064614: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80064618: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8006461C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80064620: jr          $ra
    // 0x80064624: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80064624: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void destroyLookupTable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064628: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006462C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80064630: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80064634: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064638: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8006463C: jal         0x80001C98
    // 0x80064640: nop

    rs_free(rdram, ctx);
        goto after_0;
    // 0x80064640: nop

    after_0:
    // 0x80064644: jal         0x80001C98
    // 0x80064648: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    rs_free(rdram, ctx);
        goto after_1;
    // 0x80064648: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8006464C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064650: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80064654: jr          $ra
    // 0x80064658: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80064658: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void getLookupEntryField5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006465C: lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X4);
    // 0x80064660: beq         $v0, $zero, L_800646A4
    if (ctx->r2 == 0) {
        // 0x80064664: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_800646A4;
    }
    // 0x80064664: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80064668: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8006466C: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x80064670: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
L_80064674:
    // 0x80064674: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80064678: addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // 0x8006467C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80064680: bne         $v0, $a1, L_80064694
    if (ctx->r2 != ctx->r5) {
        // 0x80064684: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80064694;
    }
    // 0x80064684: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80064688: lbu         $v0, 0x5($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X5);
    // 0x8006468C: jr          $ra
    // 0x80064690: nop

    return;
    // 0x80064690: nop

L_80064694:
    // 0x80064694: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x80064698: sltu        $v0, $v0, $a3
    ctx->r2 = ctx->r2 < ctx->r7 ? 1 : 0;
    // 0x8006469C: bne         $v0, $zero, L_80064674
    if (ctx->r2 != 0) {
        // 0x800646A0: andi        $v0, $a2, 0xFF
        ctx->r2 = ctx->r6 & 0XFF;
            goto L_80064674;
    }
    // 0x800646A0: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
L_800646A4:
    // 0x800646A4: jr          $ra
    // 0x800646A8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800646A8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void setLookupEntryField5ByKey(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    { if (((uint64_t)ctx->r4 & 0xFFFFFFFFE0000000ULL) != 0xFFFFFFFF80000000ULL) return; }
    // 0x800646AC: lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X4);
    // 0x800646B0: beq         $v0, $zero, L_800646F0
    if (ctx->r2 == 0) {
        // 0x800646B4: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_800646F0;
    }
    // 0x800646B4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800646B8: andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
L_800646BC:
    // 0x800646BC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800646C0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800646C4: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // 0x800646C8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800646CC: bne         $v0, $a1, L_800646DC
    if (ctx->r2 != ctx->r5) {
        // 0x800646D0: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800646DC;
    }
    // 0x800646D0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800646D4: jr          $ra
    // 0x800646D8: sb          $a2, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r6;
    return;
    // 0x800646D8: sb          $a2, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r6;
L_800646DC:
    // 0x800646DC: lhu         $v1, 0x4($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X4);
    // 0x800646E0: andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // 0x800646E4: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800646E8: bne         $v0, $zero, L_800646BC
    if (ctx->r2 != 0) {
        // 0x800646EC: andi        $v0, $a3, 0xFF
        ctx->r2 = ctx->r7 & 0XFF;
            goto L_800646BC;
    }
    // 0x800646EC: andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
L_800646F0:
    // 0x800646F0: jr          $ra
    // 0x800646F4: nop

    return;
    // 0x800646F4: nop

;}
RECOMP_FUNC void func_800646F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800646F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800646FC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80064700: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80064704: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80064708: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8006470C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80064710: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80064714: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80064718: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8006471C: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x80064720: beq         $v0, $zero, L_800647C4
    if (ctx->r2 == 0) {
        // 0x80064724: addu        $s3, $a2, $zero
        ctx->r19 = ADD32(ctx->r6, 0);
            goto L_800647C4;
    }
    // 0x80064724: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x80064728: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
L_8006472C:
    // 0x8006472C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80064730: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80064734: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // 0x80064738: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8006473C: bnel        $v0, $s2, L_800647B0
    if (ctx->r2 != ctx->r18) {
        // 0x80064740: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800647B0;
    }
    goto skip_0;
    // 0x80064740: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x80064744: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80064748: lbu         $s1, 0x5($v1)
    ctx->r17 = MEM_BU(ctx->r3, 0X5);
    // 0x8006474C: jal         0x800643C4
    // 0x80064750: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    removeLookupTableEntry(rdram, ctx);
        goto after_0;
    // 0x80064750: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_0:
    // 0x80064754: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80064758: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8006475C: jal         0x800642A0
    // 0x80064760: andi        $a2, $s3, 0xFF
    ctx->r6 = ctx->r19 & 0XFF;
    findLookupEntryByKey(rdram, ctx);
        goto after_1;
    // 0x80064760: andi        $a2, $s3, 0xFF
    ctx->r6 = ctx->r19 & 0XFF;
    after_1:
    // 0x80064764: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x80064768: beq         $v0, $zero, L_800647C4
    if (ctx->r2 == 0) {
        // 0x8006476C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800647C4;
    }
    // 0x8006476C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80064770: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
L_80064774:
    // 0x80064774: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80064778: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8006477C: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // 0x80064780: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80064784: bnel        $v0, $s2, L_80064794
    if (ctx->r2 != ctx->r18) {
        // 0x80064788: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80064794;
    }
    goto skip_1;
    // 0x80064788: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_1:
    // 0x8006478C: j           L_800647C4
    // 0x80064790: sb          $s1, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r17;
        goto L_800647C4;
    // 0x80064790: sb          $s1, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r17;
L_80064794:
    // 0x80064794: lhu         $v1, 0x4($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X4);
    // 0x80064798: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8006479C: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800647A0: bne         $v0, $zero, L_80064774
    if (ctx->r2 != 0) {
        // 0x800647A4: andi        $v0, $a0, 0xFF
        ctx->r2 = ctx->r4 & 0XFF;
            goto L_80064774;
    }
    // 0x800647A4: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x800647A8: j           L_800647C4
    // 0x800647AC: nop

        goto L_800647C4;
    // 0x800647AC: nop

L_800647B0:
    // 0x800647B0: lhu         $v1, 0x4($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X4);
    // 0x800647B4: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x800647B8: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800647BC: bne         $v0, $zero, L_8006472C
    if (ctx->r2 != 0) {
        // 0x800647C0: andi        $v0, $a0, 0xFF
        ctx->r2 = ctx->r4 & 0XFF;
            goto L_8006472C;
    }
    // 0x800647C0: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
L_800647C4:
    // 0x800647C4: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800647C8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800647CC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800647D0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800647D4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800647D8: jr          $ra
    // 0x800647DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800647DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void load_asset_with_malloc_flags(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800647E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800647E4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800647E8: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800647EC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800647F0: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800647F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800647F8: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x800647FC: lw          $a0, 0x7CFC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X7CFC);
    // 0x80064800: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80064804: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x80064808: jal         0x80004D5C
    // 0x8006480C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    get_asset_size_extra(rdram, ctx);
        goto after_0;
    // 0x8006480C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    after_0:
    // 0x80064810: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80064814: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80064818: jal         0x80001ACC
    // 0x8006481C: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x8006481C: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    after_1:
    // 0x80064820: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80064824: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80064828: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x8006482C: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x80064830: lw          $a2, 0x7CFC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X7CFC);
    // 0x80064834: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x80064838: jal         0x80004AAC
    // 0x8006483C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    findAssetAcrossSegments(rdram, ctx);
        goto after_2;
    // 0x8006483C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x80064840: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80064844: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80064848: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8006484C: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x80064850: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x80064854: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80064858: jal         0x80004E70
    // 0x8006485C: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    setupAssetDma(rdram, ctx);
        goto after_3;
    // 0x8006485C: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    after_3:
    // 0x80064860: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x80064864: jal         0x80004C70
    // 0x80064868: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    teardownAssetDma(rdram, ctx);
        goto after_4;
    // 0x80064868: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_4:
    // 0x8006486C: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x80064870: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x80064874: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80064878: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006487C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80064880: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    {
    static int s_force = -1;
    if (s_force < 0) {
        const char* e = getenv("ROGUESQ_DISABLE_EMPTY_POOL_SENTINEL");
        s_force = (e && *e && *e != '0') ? 0 : 1;
    }
    if (s_force) {
        uint32_t buf_ptr = (uint32_t)ctx->r2;
        if (buf_ptr >= 0x80000000u && buf_ptr < 0x80800000u) {
            int32_t* word_ptr = (int32_t*)(rdram + (buf_ptr - 0x80000000u));
            if (*word_ptr == 0) {
                *word_ptr = -1;
            }
        }
    }
}
    // 0x80064884: jr          $ra
    // 0x80064888: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80064888: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void load_asset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006488C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80064890: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80064894: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80064898: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006489C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800648A0: lw          $a0, 0x7CFC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X7CFC);
    // 0x800648A4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800648A8: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800648AC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800648B0: jal         0x80004D5C
    // 0x800648B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    get_asset_size_extra(rdram, ctx);
        goto after_0;
    // 0x800648B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800648B8: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x800648BC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800648C0: jal         0x80001ACC
    // 0x800648C4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x800648C4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x800648C8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800648CC: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800648D0: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x800648D4: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x800648D8: lw          $a2, 0x7CFC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X7CFC);
    // 0x800648DC: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x800648E0: jal         0x80004AAC
    // 0x800648E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    findAssetAcrossSegments(rdram, ctx);
        goto after_2;
    // 0x800648E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x800648E8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800648EC: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800648F0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x800648F4: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x800648F8: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x800648FC: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80064900: jal         0x80004E70
    // 0x80064904: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    setupAssetDma(rdram, ctx);
        goto after_3;
    // 0x80064904: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    after_3:
    // 0x80064908: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x8006490C: jal         0x80004C70
    // 0x80064910: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    teardownAssetDma(rdram, ctx);
        goto after_4;
    // 0x80064910: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_4:
    // 0x80064914: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x80064918: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8006491C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80064920: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80064924: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80064928: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006492C: jr          $ra
    // 0x80064930: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80064930: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void fake_func_80064934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void load_dat_file_assets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064940: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80064944: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80064948: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x8006494C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80064950: addiu       $a0, $a0, -0x6608
    ctx->r4 = ADD32(ctx->r4, -0X6608);
    // 0x80064954: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80064958: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8006495C: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80064960: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80064964: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80064968: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8006496C: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80064970: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80064974: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80064978: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8006497C: sdc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X68, ctx->r29);
    // 0x80064980: jal         0x800078E0
    // 0x80064984: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    rs_memset(rdram, ctx);
        goto after_0;
    // 0x80064984: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_0:
    // 0x80064988: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006498C: addiu       $s1, $v0, -0x6670
    ctx->r17 = ADD32(ctx->r2, -0X6670);
    // 0x80064990: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80064994: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80064998: jal         0x800078E0
    // 0x8006499C: addiu       $a2, $zero, 0x53
    ctx->r6 = ADD32(0, 0X53);
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x8006499C: addiu       $a2, $zero, 0x53
    ctx->r6 = ADD32(0, 0X53);
    after_1:
    // 0x800649A0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800649A4: addiu       $a0, $a0, -0x6618
    ctx->r4 = ADD32(ctx->r4, -0X6618);
    // 0x800649A8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800649AC: jal         0x800078E0
    // 0x800649B0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    rs_memset(rdram, ctx);
        goto after_2;
    // 0x800649B0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_2:
    // 0x800649B4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800649B8: lw          $v0, 0x75D8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X75D8);
    // 0x800649BC: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x800649C0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800649C4: beq         $v0, $zero, L_80065038
    if (ctx->r2 == 0) {
        // 0x800649C8: addu        $s0, $s3, $zero
        ctx->r16 = ADD32(ctx->r19, 0);
            goto L_80065038;
    }
    // 0x800649C8: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
    // 0x800649CC: addu        $s7, $s1, $zero
    ctx->r23 = ADD32(ctx->r17, 0);
    // 0x800649D0: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x800649D4: lui         $fp, 0x8004
    ctx->r30 = S32(0X8004 << 16);
    // 0x800649D8: lui         $s6, 0x8004
    ctx->r22 = S32(0X8004 << 16);
    // 0x800649DC: addu        $s5, $s3, $zero
    ctx->r21 = ADD32(ctx->r19, 0);
L_800649E0:
    // 0x800649E0: lw          $v0, 0x75D8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X75D8);
    // 0x800649E4: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x800649E8: addu        $v0, $s5, $v0
    ctx->r2 = ADD32(ctx->r21, ctx->r2);
    // 0x800649EC: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800649F0: lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X3);
    // 0x800649F4: beql        $v0, $zero, L_80064A14
    if (ctx->r2 == 0) {
        // 0x800649F8: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_80064A14;
    }
    goto skip_0;
    // 0x800649F8: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    skip_0:
    // 0x800649FC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80064A00: addiu       $t0, $t0, 0xB40
    ctx->r8 = ADD32(ctx->r8, 0XB40);
    // 0x80064A04: lbu         $v0, 0x23($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X23);
    // 0x80064A08: beql        $v0, $zero, L_80065018
    if (ctx->r2 == 0) {
        // 0x80064A0C: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_80065018;
    }
    goto skip_1;
    // 0x80064A0C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    skip_1:
    // 0x80064A10: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
L_80064A14:
    // 0x80064A14: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064A18: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x80064A1C: addiu       $s1, $v0, -0x47D0
    ctx->r17 = ADD32(ctx->r2, -0X47D0);
    // 0x80064A20: addu        $v1, $a0, $s7
    ctx->r3 = ADD32(ctx->r4, ctx->r23);
    // 0x80064A24: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80064A28: bne         $v0, $zero, L_80065014
    if (ctx->r2 != 0) {
        // 0x80064A2C: addiu       $s4, $zero, 0x1
        ctx->r20 = ADD32(0, 0X1);
            goto L_80065014;
    }
    // 0x80064A2C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80064A30: sb          $s4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r20;
    // 0x80064A34: addiu       $v1, $a0, -0xC
    ctx->r3 = ADD32(ctx->r4, -0XC);
    // 0x80064A38: sltiu       $v0, $v1, 0x45
    ctx->r2 = ctx->r3 < 0X45 ? 1 : 0;
    // 0x80064A3C: beq         $v0, $zero, L_80064FC4
    if (ctx->r2 == 0) {
        // 0x80064A40: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_80064FC4;
    }
    // 0x80064A40: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064A44: addiu       $v0, $v0, -0x43B0
    ctx->r2 = ADD32(ctx->r2, -0X43B0);
    // 0x80064A48: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80064A4C: addu        $v1, $v1, $v0
    gpr jr_addend_80064A54 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80064A50: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x80064A54: jr          $v0
    // 0x80064A58: nop

    switch (jr_addend_80064A54 >> 2) {
        case 0: goto L_80064A5C; break;
        case 1: goto L_80064AC0; break;
        case 2: goto L_80064AE8; break;
        case 3: goto L_80064D04; break;
        case 4: goto L_80064FC4; break;
        case 5: goto L_80064FC4; break;
        case 6: goto L_80064A6C; break;
        case 7: goto L_80064A7C; break;
        case 8: goto L_80064B20; break;
        case 9: goto L_80064FC4; break;
        case 10: goto L_80064FC4; break;
        case 11: goto L_80064FC4; break;
        case 12: goto L_80064FC4; break;
        case 13: goto L_80064FC4; break;
        case 14: goto L_80064FC4; break;
        case 15: goto L_80064FC4; break;
        case 16: goto L_80064FC4; break;
        case 17: goto L_80064FC4; break;
        case 18: goto L_80064AF8; break;
        case 19: goto L_80064D64; break;
        case 20: goto L_80064FC4; break;
        case 21: goto L_80064FC4; break;
        case 22: goto L_80064FC4; break;
        case 23: goto L_80064FC4; break;
        case 24: goto L_80064B40; break;
        case 25: goto L_80064B50; break;
        case 26: goto L_80064FC4; break;
        case 27: goto L_80064EBC; break;
        case 28: goto L_80064E20; break;
        case 29: goto L_80064A94; break;
        case 30: goto L_80064B30; break;
        case 31: goto L_80064B60; break;
        case 32: goto L_80064CE4; break;
        case 33: goto L_80064B70; break;
        case 34: goto L_80064BA0; break;
        case 35: goto L_80064E60; break;
        case 36: goto L_80064E60; break;
        case 37: goto L_80064E60; break;
        case 38: goto L_80064BB0; break;
        case 39: goto L_80064E80; break;
        case 40: goto L_80064E90; break;
        case 41: goto L_80064E90; break;
        case 42: goto L_80064EAC; break;
        case 43: goto L_80064BE8; break;
        case 44: goto L_80064FC4; break;
        case 45: goto L_80064FC4; break;
        case 46: goto L_80064FC4; break;
        case 47: goto L_80064C10; break;
        case 48: goto L_80064C30; break;
        case 49: goto L_80064C40; break;
        case 50: goto L_80064B80; break;
        case 51: goto L_80064FC4; break;
        case 52: goto L_80064B90; break;
        case 53: goto L_80064C50; break;
        case 54: goto L_80064C60; break;
        case 55: goto L_80064C70; break;
        case 56: goto L_80064C80; break;
        case 57: goto L_80064FC8; break;
        case 58: goto L_80064FC4; break;
        case 59: goto L_80064DCC; break;
        case 60: goto L_80064CF4; break;
        case 61: goto L_80064FC4; break;
        case 62: goto L_80064CB0; break;
        case 63: goto L_80064FC4; break;
        case 64: goto L_80064CC0; break;
        case 65: goto L_80064CD4; break;
        case 66: goto L_80064FC4; break;
        case 67: goto L_80064FC4; break;
        case 68: goto L_80064C20; break;
        default: switch_error(__func__, 0x80064A54, 0x8003BC50);
    }
    // 0x80064A58: nop

L_80064A5C:
    // 0x80064A5C: addiu       $s1, $s2, -0x47CC
    ctx->r17 = ADD32(ctx->r18, -0X47CC);
    // 0x80064A60: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064A64: j           L_80064FC8
    // 0x80064A68: addiu       $s0, $v0, -0x47C0
    ctx->r16 = ADD32(ctx->r2, -0X47C0);
        goto L_80064FC8;
    // 0x80064A68: addiu       $s0, $v0, -0x47C0
    ctx->r16 = ADD32(ctx->r2, -0X47C0);
L_80064A6C:
    // 0x80064A6C: addiu       $s1, $s2, -0x47CC
    ctx->r17 = ADD32(ctx->r18, -0X47CC);
    // 0x80064A70: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064A74: j           L_80064FC8
    // 0x80064A78: addiu       $s0, $v0, -0x47B4
    ctx->r16 = ADD32(ctx->r2, -0X47B4);
        goto L_80064FC8;
    // 0x80064A78: addiu       $s0, $v0, -0x47B4
    ctx->r16 = ADD32(ctx->r2, -0X47B4);
L_80064A7C:
    // 0x80064A7C: jal         0x8006B710
    // 0x80064A80: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    loadCraftShadowTextures(rdram, ctx);
        goto after_3;
    // 0x80064A80: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_3:
    // 0x80064A84: addiu       $s1, $s2, -0x47CC
    ctx->r17 = ADD32(ctx->r18, -0X47CC);
    // 0x80064A88: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064A8C: j           L_80064FC8
    // 0x80064A90: addiu       $s0, $v0, -0x47A8
    ctx->r16 = ADD32(ctx->r2, -0X47A8);
        goto L_80064FC8;
    // 0x80064A90: addiu       $s0, $v0, -0x47A8
    ctx->r16 = ADD32(ctx->r2, -0X47A8);
L_80064A94:
    // 0x80064A94: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80064A98: addiu       $t0, $t0, 0xB40
    ctx->r8 = ADD32(ctx->r8, 0XB40);
    // 0x80064A9C: lbu         $v0, 0x23($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X23);
    // 0x80064AA0: beq         $v0, $zero, L_80064AB4
    if (ctx->r2 == 0) {
        // 0x80064AA4: addiu       $s1, $s2, -0x47CC
        ctx->r17 = ADD32(ctx->r18, -0X47CC);
            goto L_80064AB4;
    }
    // 0x80064AA4: addiu       $s1, $s2, -0x47CC
    ctx->r17 = ADD32(ctx->r18, -0X47CC);
    // 0x80064AA8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064AAC: j           L_80064FC8
    // 0x80064AB0: addiu       $s0, $v0, -0x479C
    ctx->r16 = ADD32(ctx->r2, -0X479C);
        goto L_80064FC8;
    // 0x80064AB0: addiu       $s0, $v0, -0x479C
    ctx->r16 = ADD32(ctx->r2, -0X479C);
L_80064AB4:
    // 0x80064AB4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064AB8: j           L_80064FC8
    // 0x80064ABC: addiu       $s0, $v0, -0x4794
    ctx->r16 = ADD32(ctx->r2, -0X4794);
        goto L_80064FC8;
    // 0x80064ABC: addiu       $s0, $v0, -0x4794
    ctx->r16 = ADD32(ctx->r2, -0X4794);
L_80064AC0:
    // 0x80064AC0: addiu       $s1, $s2, -0x47CC
    ctx->r17 = ADD32(ctx->r18, -0X47CC);
    // 0x80064AC4: jal         0x8006B180
    // 0x80064AC8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    isCraftAvailableByIdx(rdram, ctx);
        goto after_4;
    // 0x80064AC8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_4:
    // 0x80064ACC: beq         $v0, $zero, L_80064ADC
    if (ctx->r2 == 0) {
        // 0x80064AD0: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_80064ADC;
    }
    // 0x80064AD0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064AD4: j           L_80064FC8
    // 0x80064AD8: addiu       $s0, $v0, -0x478C
    ctx->r16 = ADD32(ctx->r2, -0X478C);
        goto L_80064FC8;
    // 0x80064AD8: addiu       $s0, $v0, -0x478C
    ctx->r16 = ADD32(ctx->r2, -0X478C);
L_80064ADC:
    // 0x80064ADC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064AE0: j           L_80064FC8
    // 0x80064AE4: addiu       $s0, $v0, -0x4780
    ctx->r16 = ADD32(ctx->r2, -0X4780);
        goto L_80064FC8;
    // 0x80064AE4: addiu       $s0, $v0, -0x4780
    ctx->r16 = ADD32(ctx->r2, -0X4780);
L_80064AE8:
    // 0x80064AE8: addiu       $s1, $s2, -0x47CC
    ctx->r17 = ADD32(ctx->r18, -0X47CC);
    // 0x80064AEC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064AF0: j           L_80064FC8
    // 0x80064AF4: addiu       $s0, $v0, -0x4774
    ctx->r16 = ADD32(ctx->r2, -0X4774);
        goto L_80064FC8;
    // 0x80064AF4: addiu       $s0, $v0, -0x4774
    ctx->r16 = ADD32(ctx->r2, -0X4774);
L_80064AF8:
    // 0x80064AF8: addiu       $s1, $s2, -0x47CC
    ctx->r17 = ADD32(ctx->r18, -0X47CC);
    // 0x80064AFC: jal         0x8006B180
    // 0x80064B00: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    isCraftAvailableByIdx(rdram, ctx);
        goto after_5;
    // 0x80064B00: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_5:
    // 0x80064B04: beq         $v0, $zero, L_80064B14
    if (ctx->r2 == 0) {
        // 0x80064B08: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_80064B14;
    }
    // 0x80064B08: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064B0C: j           L_80064FC8
    // 0x80064B10: addiu       $s0, $v0, -0x4768
    ctx->r16 = ADD32(ctx->r2, -0X4768);
        goto L_80064FC8;
    // 0x80064B10: addiu       $s0, $v0, -0x4768
    ctx->r16 = ADD32(ctx->r2, -0X4768);
L_80064B14:
    // 0x80064B14: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064B18: j           L_80064FC8
    // 0x80064B1C: addiu       $s0, $v0, -0x475C
    ctx->r16 = ADD32(ctx->r2, -0X475C);
        goto L_80064FC8;
    // 0x80064B1C: addiu       $s0, $v0, -0x475C
    ctx->r16 = ADD32(ctx->r2, -0X475C);
L_80064B20:
    // 0x80064B20: addiu       $s1, $fp, -0x4750
    ctx->r17 = ADD32(ctx->r30, -0X4750);
    // 0x80064B24: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064B28: j           L_80064FC8
    // 0x80064B2C: addiu       $s0, $v0, -0x4744
    ctx->r16 = ADD32(ctx->r2, -0X4744);
        goto L_80064FC8;
    // 0x80064B2C: addiu       $s0, $v0, -0x4744
    ctx->r16 = ADD32(ctx->r2, -0X4744);
L_80064B30:
    // 0x80064B30: addiu       $s1, $fp, -0x4750
    ctx->r17 = ADD32(ctx->r30, -0X4750);
    // 0x80064B34: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064B38: j           L_80064FC8
    // 0x80064B3C: addiu       $s0, $v0, -0x4738
    ctx->r16 = ADD32(ctx->r2, -0X4738);
        goto L_80064FC8;
    // 0x80064B3C: addiu       $s0, $v0, -0x4738
    ctx->r16 = ADD32(ctx->r2, -0X4738);
L_80064B40:
    // 0x80064B40: addiu       $s1, $s2, -0x47CC
    ctx->r17 = ADD32(ctx->r18, -0X47CC);
    // 0x80064B44: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064B48: j           L_80064FC8
    // 0x80064B4C: addiu       $s0, $v0, -0x472C
    ctx->r16 = ADD32(ctx->r2, -0X472C);
        goto L_80064FC8;
    // 0x80064B4C: addiu       $s0, $v0, -0x472C
    ctx->r16 = ADD32(ctx->r2, -0X472C);
L_80064B50:
    // 0x80064B50: addiu       $s1, $s2, -0x47CC
    ctx->r17 = ADD32(ctx->r18, -0X47CC);
    // 0x80064B54: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064B58: j           L_80064FC8
    // 0x80064B5C: addiu       $s0, $v0, -0x4724
    ctx->r16 = ADD32(ctx->r2, -0X4724);
        goto L_80064FC8;
    // 0x80064B5C: addiu       $s0, $v0, -0x4724
    ctx->r16 = ADD32(ctx->r2, -0X4724);
L_80064B60:
    // 0x80064B60: addiu       $s1, $s6, -0x4718
    ctx->r17 = ADD32(ctx->r22, -0X4718);
    // 0x80064B64: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064B68: j           L_80064FC8
    // 0x80064B6C: addiu       $s0, $v0, -0x470C
    ctx->r16 = ADD32(ctx->r2, -0X470C);
        goto L_80064FC8;
    // 0x80064B6C: addiu       $s0, $v0, -0x470C
    ctx->r16 = ADD32(ctx->r2, -0X470C);
L_80064B70:
    // 0x80064B70: addiu       $s1, $s2, -0x47CC
    ctx->r17 = ADD32(ctx->r18, -0X47CC);
    // 0x80064B74: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064B78: j           L_80064FC8
    // 0x80064B7C: addiu       $s0, $v0, -0x4700
    ctx->r16 = ADD32(ctx->r2, -0X4700);
        goto L_80064FC8;
    // 0x80064B7C: addiu       $s0, $v0, -0x4700
    ctx->r16 = ADD32(ctx->r2, -0X4700);
L_80064B80:
    // 0x80064B80: addiu       $s1, $s2, -0x47CC
    ctx->r17 = ADD32(ctx->r18, -0X47CC);
    // 0x80064B84: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064B88: j           L_80064FC8
    // 0x80064B8C: addiu       $s0, $v0, -0x46F8
    ctx->r16 = ADD32(ctx->r2, -0X46F8);
        goto L_80064FC8;
    // 0x80064B8C: addiu       $s0, $v0, -0x46F8
    ctx->r16 = ADD32(ctx->r2, -0X46F8);
L_80064B90:
    // 0x80064B90: addiu       $s1, $s2, -0x47CC
    ctx->r17 = ADD32(ctx->r18, -0X47CC);
    // 0x80064B94: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064B98: j           L_80064FC8
    // 0x80064B9C: addiu       $s0, $v0, -0x46F0
    ctx->r16 = ADD32(ctx->r2, -0X46F0);
        goto L_80064FC8;
    // 0x80064B9C: addiu       $s0, $v0, -0x46F0
    ctx->r16 = ADD32(ctx->r2, -0X46F0);
L_80064BA0:
    // 0x80064BA0: addiu       $s1, $s6, -0x4718
    ctx->r17 = ADD32(ctx->r22, -0X4718);
    // 0x80064BA4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064BA8: j           L_80064FC8
    // 0x80064BAC: addiu       $s0, $v0, -0x46E4
    ctx->r16 = ADD32(ctx->r2, -0X46E4);
        goto L_80064FC8;
    // 0x80064BAC: addiu       $s0, $v0, -0x46E4
    ctx->r16 = ADD32(ctx->r2, -0X46E4);
L_80064BB0:
    // 0x80064BB0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80064BB4: lw          $v0, 0x75D8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X75D8);
    // 0x80064BB8: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80064BBC: addu        $v0, $s5, $v0
    ctx->r2 = ADD32(ctx->r21, ctx->r2);
    // 0x80064BC0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80064BC4: lw          $v0, 0x70($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X70);
    // 0x80064BC8: beq         $v0, $zero, L_80064BDC
    if (ctx->r2 == 0) {
        // 0x80064BCC: addiu       $s1, $fp, -0x4750
        ctx->r17 = ADD32(ctx->r30, -0X4750);
            goto L_80064BDC;
    }
    // 0x80064BCC: addiu       $s1, $fp, -0x4750
    ctx->r17 = ADD32(ctx->r30, -0X4750);
    // 0x80064BD0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064BD4: j           L_80064CCC
    // 0x80064BD8: addiu       $s0, $v0, -0x46D8
    ctx->r16 = ADD32(ctx->r2, -0X46D8);
        goto L_80064CCC;
    // 0x80064BD8: addiu       $s0, $v0, -0x46D8
    ctx->r16 = ADD32(ctx->r2, -0X46D8);
L_80064BDC:
    // 0x80064BDC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064BE0: j           L_80064CCC
    // 0x80064BE4: addiu       $s0, $v0, -0x46CC
    ctx->r16 = ADD32(ctx->r2, -0X46CC);
        goto L_80064CCC;
    // 0x80064BE4: addiu       $s0, $v0, -0x46CC
    ctx->r16 = ADD32(ctx->r2, -0X46CC);
L_80064BE8:
    // 0x80064BE8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80064BEC: addiu       $a0, $a0, -0x46C4
    ctx->r4 = ADD32(ctx->r4, -0X46C4);
    // 0x80064BF0: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80064BF4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80064BF8: jal         0x8005645C
    // 0x80064BFC: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    load_hmt_and_hob(rdram, ctx);
        goto after_6;
    // 0x80064BFC: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    after_6:
    // 0x80064C00: addiu       $s1, $s2, -0x47CC
    ctx->r17 = ADD32(ctx->r18, -0X47CC);
    // 0x80064C04: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064C08: j           L_80064FC8
    // 0x80064C0C: addiu       $s0, $v0, -0x46B0
    ctx->r16 = ADD32(ctx->r2, -0X46B0);
        goto L_80064FC8;
    // 0x80064C0C: addiu       $s0, $v0, -0x46B0
    ctx->r16 = ADD32(ctx->r2, -0X46B0);
L_80064C10:
    // 0x80064C10: addiu       $s1, $s2, -0x47CC
    ctx->r17 = ADD32(ctx->r18, -0X47CC);
    // 0x80064C14: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064C18: j           L_80064FC8
    // 0x80064C1C: addiu       $s0, $v0, -0x46A4
    ctx->r16 = ADD32(ctx->r2, -0X46A4);
        goto L_80064FC8;
    // 0x80064C1C: addiu       $s0, $v0, -0x46A4
    ctx->r16 = ADD32(ctx->r2, -0X46A4);
L_80064C20:
    // 0x80064C20: addiu       $s1, $s2, -0x47CC
    ctx->r17 = ADD32(ctx->r18, -0X47CC);
    // 0x80064C24: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064C28: j           L_80064FC8
    // 0x80064C2C: addiu       $s0, $v0, -0x469C
    ctx->r16 = ADD32(ctx->r2, -0X469C);
        goto L_80064FC8;
    // 0x80064C2C: addiu       $s0, $v0, -0x469C
    ctx->r16 = ADD32(ctx->r2, -0X469C);
L_80064C30:
    // 0x80064C30: addiu       $s1, $s6, -0x4718
    ctx->r17 = ADD32(ctx->r22, -0X4718);
    // 0x80064C34: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064C38: j           L_80064FC8
    // 0x80064C3C: addiu       $s0, $v0, -0x4690
    ctx->r16 = ADD32(ctx->r2, -0X4690);
        goto L_80064FC8;
    // 0x80064C3C: addiu       $s0, $v0, -0x4690
    ctx->r16 = ADD32(ctx->r2, -0X4690);
L_80064C40:
    // 0x80064C40: addiu       $s1, $fp, -0x4750
    ctx->r17 = ADD32(ctx->r30, -0X4750);
    // 0x80064C44: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064C48: j           L_80064FC8
    // 0x80064C4C: addiu       $s0, $v0, -0x4688
    ctx->r16 = ADD32(ctx->r2, -0X4688);
        goto L_80064FC8;
    // 0x80064C4C: addiu       $s0, $v0, -0x4688
    ctx->r16 = ADD32(ctx->r2, -0X4688);
L_80064C50:
    // 0x80064C50: addiu       $s1, $s6, -0x4718
    ctx->r17 = ADD32(ctx->r22, -0X4718);
    // 0x80064C54: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064C58: j           L_80064FC8
    // 0x80064C5C: addiu       $s0, $v0, -0x467C
    ctx->r16 = ADD32(ctx->r2, -0X467C);
        goto L_80064FC8;
    // 0x80064C5C: addiu       $s0, $v0, -0x467C
    ctx->r16 = ADD32(ctx->r2, -0X467C);
L_80064C60:
    // 0x80064C60: addiu       $s1, $s2, -0x47CC
    ctx->r17 = ADD32(ctx->r18, -0X47CC);
    // 0x80064C64: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064C68: j           L_80064FC8
    // 0x80064C6C: addiu       $s0, $v0, -0x4670
    ctx->r16 = ADD32(ctx->r2, -0X4670);
        goto L_80064FC8;
    // 0x80064C6C: addiu       $s0, $v0, -0x4670
    ctx->r16 = ADD32(ctx->r2, -0X4670);
L_80064C70:
    // 0x80064C70: addiu       $s1, $fp, -0x4750
    ctx->r17 = ADD32(ctx->r30, -0X4750);
    // 0x80064C74: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064C78: j           L_80064FC8
    // 0x80064C7C: addiu       $s0, $v0, -0x4664
    ctx->r16 = ADD32(ctx->r2, -0X4664);
        goto L_80064FC8;
    // 0x80064C7C: addiu       $s0, $v0, -0x4664
    ctx->r16 = ADD32(ctx->r2, -0X4664);
L_80064C80:
    // 0x80064C80: jal         0x8006B180
    // 0x80064C84: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    isCraftAvailableByIdx(rdram, ctx);
        goto after_7;
    // 0x80064C84: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_7:
    // 0x80064C88: beq         $v0, $zero, L_80064C98
    if (ctx->r2 == 0) {
        // 0x80064C8C: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_80064C98;
    }
    // 0x80064C8C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064C90: j           L_80064CA0
    // 0x80064C94: addiu       $a0, $v0, -0x4658
    ctx->r4 = ADD32(ctx->r2, -0X4658);
        goto L_80064CA0;
    // 0x80064C94: addiu       $a0, $v0, -0x4658
    ctx->r4 = ADD32(ctx->r2, -0X4658);
L_80064C98:
    // 0x80064C98: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064C9C: addiu       $a0, $v0, -0x4640
    ctx->r4 = ADD32(ctx->r2, -0X4640);
L_80064CA0:
    // 0x80064CA0: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80064CA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80064CA8: j           L_8006500C
    // 0x80064CAC: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
        goto L_8006500C;
    // 0x80064CAC: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
L_80064CB0:
    // 0x80064CB0: addiu       $s1, $s2, -0x47CC
    ctx->r17 = ADD32(ctx->r18, -0X47CC);
    // 0x80064CB4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064CB8: j           L_80064FC8
    // 0x80064CBC: addiu       $s0, $v0, -0x462C
    ctx->r16 = ADD32(ctx->r2, -0X462C);
        goto L_80064FC8;
    // 0x80064CBC: addiu       $s0, $v0, -0x462C
    ctx->r16 = ADD32(ctx->r2, -0X462C);
L_80064CC0:
    // 0x80064CC0: addiu       $s1, $fp, -0x4750
    ctx->r17 = ADD32(ctx->r30, -0X4750);
    // 0x80064CC4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064CC8: addiu       $s0, $v0, -0x4624
    ctx->r16 = ADD32(ctx->r2, -0X4624);
L_80064CCC:
    // 0x80064CCC: j           L_80064FC8
    // 0x80064CD0: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
        goto L_80064FC8;
    // 0x80064CD0: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
L_80064CD4:
    // 0x80064CD4: addiu       $s1, $s2, -0x47CC
    ctx->r17 = ADD32(ctx->r18, -0X47CC);
    // 0x80064CD8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064CDC: j           L_80064FC8
    // 0x80064CE0: addiu       $s0, $v0, -0x461C
    ctx->r16 = ADD32(ctx->r2, -0X461C);
        goto L_80064FC8;
    // 0x80064CE0: addiu       $s0, $v0, -0x461C
    ctx->r16 = ADD32(ctx->r2, -0X461C);
L_80064CE4:
    // 0x80064CE4: addiu       $s1, $s2, -0x47CC
    ctx->r17 = ADD32(ctx->r18, -0X47CC);
    // 0x80064CE8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064CEC: j           L_80064FC8
    // 0x80064CF0: addiu       $s0, $v0, -0x4614
    ctx->r16 = ADD32(ctx->r2, -0X4614);
        goto L_80064FC8;
    // 0x80064CF0: addiu       $s0, $v0, -0x4614
    ctx->r16 = ADD32(ctx->r2, -0X4614);
L_80064CF4:
    // 0x80064CF4: addiu       $s1, $s2, -0x47CC
    ctx->r17 = ADD32(ctx->r18, -0X47CC);
    // 0x80064CF8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064CFC: j           L_80064FC8
    // 0x80064D00: addiu       $s0, $v0, -0x460C
    ctx->r16 = ADD32(ctx->r2, -0X460C);
        goto L_80064FC8;
    // 0x80064D00: addiu       $s0, $v0, -0x460C
    ctx->r16 = ADD32(ctx->r2, -0X460C);
L_80064D04:
    // 0x80064D04: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80064D08: addiu       $t0, $t0, 0xB40
    ctx->r8 = ADD32(ctx->r8, 0XB40);
    // 0x80064D0C: lbu         $v0, 0x23($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X23);
    // 0x80064D10: beq         $v0, $zero, L_80064D24
    if (ctx->r2 == 0) {
        // 0x80064D14: addiu       $s1, $s2, -0x47CC
        ctx->r17 = ADD32(ctx->r18, -0X47CC);
            goto L_80064D24;
    }
    // 0x80064D14: addiu       $s1, $s2, -0x47CC
    ctx->r17 = ADD32(ctx->r18, -0X47CC);
    // 0x80064D18: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064D1C: j           L_80064D2C
    // 0x80064D20: addiu       $s0, $v0, -0x4604
    ctx->r16 = ADD32(ctx->r2, -0X4604);
        goto L_80064D2C;
    // 0x80064D20: addiu       $s0, $v0, -0x4604
    ctx->r16 = ADD32(ctx->r2, -0X4604);
L_80064D24:
    // 0x80064D24: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064D28: addiu       $s0, $v0, -0x45FC
    ctx->r16 = ADD32(ctx->r2, -0X45FC);
L_80064D2C:
    // 0x80064D2C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80064D30: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x80064D34: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80064D38: bne         $v1, $v0, L_80064D48
    if (ctx->r3 != ctx->r2) {
        // 0x80064D3C: lui         $a0, 0x8004
        ctx->r4 = S32(0X8004 << 16);
            goto L_80064D48;
    }
    // 0x80064D3C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80064D40: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80064D44: addiu       $s3, $v0, -0x3C0
    ctx->r19 = ADD32(ctx->r2, -0X3C0);
L_80064D48:
    // 0x80064D48: jal         0x800F9E40
    // 0x80064D4C: addiu       $a0, $a0, -0x45F4
    ctx->r4 = ADD32(ctx->r4, -0X45F4);
    load_model_animation(rdram, ctx);
        goto after_8;
    // 0x80064D4C: addiu       $a0, $a0, -0x45F4
    ctx->r4 = ADD32(ctx->r4, -0X45F4);
    after_8:
    // 0x80064D50: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80064D54: jal         0x800F9E40
    // 0x80064D58: addiu       $a0, $a0, -0x45E0
    ctx->r4 = ADD32(ctx->r4, -0X45E0);
    load_model_animation(rdram, ctx);
        goto after_9;
    // 0x80064D58: addiu       $a0, $a0, -0x45E0
    ctx->r4 = ADD32(ctx->r4, -0X45E0);
    after_9:
    // 0x80064D5C: j           L_80064FC8
    // 0x80064D60: nop

        goto L_80064FC8;
    // 0x80064D60: nop

L_80064D64:
    // 0x80064D64: addiu       $s1, $s2, -0x47CC
    ctx->r17 = ADD32(ctx->r18, -0X47CC);
    // 0x80064D68: jal         0x8006B180
    // 0x80064D6C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    isCraftAvailableByIdx(rdram, ctx);
        goto after_10;
    // 0x80064D6C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x80064D70: beq         $v0, $zero, L_80064D80
    if (ctx->r2 == 0) {
        // 0x80064D74: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_80064D80;
    }
    // 0x80064D74: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064D78: j           L_80064D88
    // 0x80064D7C: addiu       $s0, $v0, -0x45CC
    ctx->r16 = ADD32(ctx->r2, -0X45CC);
        goto L_80064D88;
    // 0x80064D7C: addiu       $s0, $v0, -0x45CC
    ctx->r16 = ADD32(ctx->r2, -0X45CC);
L_80064D80:
    // 0x80064D80: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064D84: addiu       $s0, $v0, -0x45C4
    ctx->r16 = ADD32(ctx->r2, -0X45C4);
L_80064D88:
    // 0x80064D88: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80064D8C: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x80064D90: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80064D94: bne         $v1, $v0, L_80064DA4
    if (ctx->r3 != ctx->r2) {
        // 0x80064D98: lui         $a0, 0x8004
        ctx->r4 = S32(0X8004 << 16);
            goto L_80064DA4;
    }
    // 0x80064D98: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80064D9C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80064DA0: addiu       $s3, $v0, -0x3C0
    ctx->r19 = ADD32(ctx->r2, -0X3C0);
L_80064DA4:
    // 0x80064DA4: jal         0x800F9E40
    // 0x80064DA8: addiu       $a0, $a0, -0x45BC
    ctx->r4 = ADD32(ctx->r4, -0X45BC);
    load_model_animation(rdram, ctx);
        goto after_11;
    // 0x80064DA8: addiu       $a0, $a0, -0x45BC
    ctx->r4 = ADD32(ctx->r4, -0X45BC);
    after_11:
    // 0x80064DAC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80064DB0: jal         0x800F9E40
    // 0x80064DB4: addiu       $a0, $a0, -0x45A8
    ctx->r4 = ADD32(ctx->r4, -0X45A8);
    load_model_animation(rdram, ctx);
        goto after_12;
    // 0x80064DB4: addiu       $a0, $a0, -0x45A8
    ctx->r4 = ADD32(ctx->r4, -0X45A8);
    after_12:
    // 0x80064DB8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80064DBC: jal         0x800F9E40
    // 0x80064DC0: addiu       $a0, $a0, -0x4590
    ctx->r4 = ADD32(ctx->r4, -0X4590);
    load_model_animation(rdram, ctx);
        goto after_13;
    // 0x80064DC0: addiu       $a0, $a0, -0x4590
    ctx->r4 = ADD32(ctx->r4, -0X4590);
    after_13:
    // 0x80064DC4: j           L_80064FC8
    // 0x80064DC8: nop

        goto L_80064FC8;
    // 0x80064DC8: nop

L_80064DCC:
    // 0x80064DCC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80064DD0: addiu       $t0, $t0, 0xB40
    ctx->r8 = ADD32(ctx->r8, 0XB40);
    // 0x80064DD4: lbu         $v0, 0x23($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X23);
    // 0x80064DD8: beq         $v0, $zero, L_80064DEC
    if (ctx->r2 == 0) {
        // 0x80064DDC: addiu       $s1, $s6, -0x4718
        ctx->r17 = ADD32(ctx->r22, -0X4718);
            goto L_80064DEC;
    }
    // 0x80064DDC: addiu       $s1, $s6, -0x4718
    ctx->r17 = ADD32(ctx->r22, -0X4718);
    // 0x80064DE0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064DE4: j           L_80064DF4
    // 0x80064DE8: addiu       $s0, $v0, -0x457C
    ctx->r16 = ADD32(ctx->r2, -0X457C);
        goto L_80064DF4;
    // 0x80064DE8: addiu       $s0, $v0, -0x457C
    ctx->r16 = ADD32(ctx->r2, -0X457C);
L_80064DEC:
    // 0x80064DEC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064DF0: addiu       $s0, $v0, -0x4570
    ctx->r16 = ADD32(ctx->r2, -0X4570);
L_80064DF4:
    // 0x80064DF4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80064DF8: jal         0x800F9E40
    // 0x80064DFC: addiu       $a0, $a0, -0x4568
    ctx->r4 = ADD32(ctx->r4, -0X4568);
    load_model_animation(rdram, ctx);
        goto after_14;
    // 0x80064DFC: addiu       $a0, $a0, -0x4568
    ctx->r4 = ADD32(ctx->r4, -0X4568);
    after_14:
    // 0x80064E00: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80064E04: jal         0x800F9E40
    // 0x80064E08: addiu       $a0, $a0, -0x4554
    ctx->r4 = ADD32(ctx->r4, -0X4554);
    load_model_animation(rdram, ctx);
        goto after_15;
    // 0x80064E08: addiu       $a0, $a0, -0x4554
    ctx->r4 = ADD32(ctx->r4, -0X4554);
    after_15:
    // 0x80064E0C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80064E10: jal         0x800F9E40
    // 0x80064E14: addiu       $a0, $a0, -0x453C
    ctx->r4 = ADD32(ctx->r4, -0X453C);
    load_model_animation(rdram, ctx);
        goto after_16;
    // 0x80064E14: addiu       $a0, $a0, -0x453C
    ctx->r4 = ADD32(ctx->r4, -0X453C);
    after_16:
    // 0x80064E18: j           L_80064FC8
    // 0x80064E1C: nop

        goto L_80064FC8;
    // 0x80064E1C: nop

L_80064E20:
    // 0x80064E20: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80064E24: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x80064E28: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80064E2C: beq         $v1, $v0, L_80064E48
    if (ctx->r3 == ctx->r2) {
        // 0x80064E30: addiu       $s1, $s2, -0x47CC
        ctx->r17 = ADD32(ctx->r18, -0X47CC);
            goto L_80064E48;
    }
    // 0x80064E30: addiu       $s1, $s2, -0x47CC
    ctx->r17 = ADD32(ctx->r18, -0X47CC);
    // 0x80064E34: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // 0x80064E38: beq         $v1, $v0, L_80064E54
    if (ctx->r3 == ctx->r2) {
        // 0x80064E3C: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_80064E54;
    }
    // 0x80064E3C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064E40: j           L_80064FC8
    // 0x80064E44: addiu       $s0, $v0, -0x4510
    ctx->r16 = ADD32(ctx->r2, -0X4510);
        goto L_80064FC8;
    // 0x80064E44: addiu       $s0, $v0, -0x4510
    ctx->r16 = ADD32(ctx->r2, -0X4510);
L_80064E48:
    // 0x80064E48: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064E4C: j           L_80064FC8
    // 0x80064E50: addiu       $s0, $v0, -0x4528
    ctx->r16 = ADD32(ctx->r2, -0X4528);
        goto L_80064FC8;
    // 0x80064E50: addiu       $s0, $v0, -0x4528
    ctx->r16 = ADD32(ctx->r2, -0X4528);
L_80064E54:
    // 0x80064E54: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064E58: j           L_80064FC8
    // 0x80064E5C: addiu       $s0, $v0, -0x451C
    ctx->r16 = ADD32(ctx->r2, -0X451C);
        goto L_80064FC8;
    // 0x80064E5C: addiu       $s0, $v0, -0x451C
    ctx->r16 = ADD32(ctx->r2, -0X451C);
L_80064E60:
    // 0x80064E60: addiu       $s1, $s2, -0x47CC
    ctx->r17 = ADD32(ctx->r18, -0X47CC);
    // 0x80064E64: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064E68: addiu       $s0, $v0, -0x4504
    ctx->r16 = ADD32(ctx->r2, -0X4504);
    // 0x80064E6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80064E70: sb          $v0, 0x31($s7)
    MEM_B(0X31, ctx->r23) = ctx->r2;
    // 0x80064E74: sb          $v0, 0x30($s7)
    MEM_B(0X30, ctx->r23) = ctx->r2;
    // 0x80064E78: j           L_80064FC8
    // 0x80064E7C: sb          $v0, 0x2F($s7)
    MEM_B(0X2F, ctx->r23) = ctx->r2;
        goto L_80064FC8;
    // 0x80064E7C: sb          $v0, 0x2F($s7)
    MEM_B(0X2F, ctx->r23) = ctx->r2;
L_80064E80:
    // 0x80064E80: addiu       $s1, $s2, -0x47CC
    ctx->r17 = ADD32(ctx->r18, -0X47CC);
    // 0x80064E84: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064E88: j           L_80064FC8
    // 0x80064E8C: addiu       $s0, $v0, -0x44FC
    ctx->r16 = ADD32(ctx->r2, -0X44FC);
        goto L_80064FC8;
    // 0x80064E8C: addiu       $s0, $v0, -0x44FC
    ctx->r16 = ADD32(ctx->r2, -0X44FC);
L_80064E90:
    // 0x80064E90: addiu       $s1, $s6, -0x4718
    ctx->r17 = ADD32(ctx->r22, -0X4718);
    // 0x80064E94: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064E98: addiu       $s0, $v0, -0x44F0
    ctx->r16 = ADD32(ctx->r2, -0X44F0);
    // 0x80064E9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80064EA0: sb          $v0, 0x35($s7)
    MEM_B(0X35, ctx->r23) = ctx->r2;
    // 0x80064EA4: j           L_80064FC8
    // 0x80064EA8: sb          $v0, 0x34($s7)
    MEM_B(0X34, ctx->r23) = ctx->r2;
        goto L_80064FC8;
    // 0x80064EA8: sb          $v0, 0x34($s7)
    MEM_B(0X34, ctx->r23) = ctx->r2;
L_80064EAC:
    // 0x80064EAC: addiu       $s1, $s6, -0x4718
    ctx->r17 = ADD32(ctx->r22, -0X4718);
    // 0x80064EB0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064EB4: j           L_80064FC8
    // 0x80064EB8: addiu       $s0, $v0, -0x44E8
    ctx->r16 = ADD32(ctx->r2, -0X44E8);
        goto L_80064FC8;
    // 0x80064EB8: addiu       $s0, $v0, -0x44E8
    ctx->r16 = ADD32(ctx->r2, -0X44E8);
L_80064EBC:
    // 0x80064EBC: addu        $v0, $a0, $s7
    ctx->r2 = ADD32(ctx->r4, ctx->r23);
    // 0x80064EC0: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x80064EC4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80064EC8: lw          $v0, 0x75D8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X75D8);
    // 0x80064ECC: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80064ED0: addu        $v0, $s5, $v0
    ctx->r2 = ADD32(ctx->r21, ctx->r2);
    // 0x80064ED4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80064ED8: lw          $v1, 0x8C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8C);
    // 0x80064EDC: sltiu       $v0, $v1, 0x8
    ctx->r2 = ctx->r3 < 0X8 ? 1 : 0;
    // 0x80064EE0: beq         $v0, $zero, L_80064F00
    if (ctx->r2 == 0) {
        // 0x80064EE4: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_80064F00;
    }
    // 0x80064EE4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064EE8: addiu       $v0, $v0, -0x4298
    ctx->r2 = ADD32(ctx->r2, -0X4298);
    // 0x80064EEC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80064EF0: addu        $v1, $v1, $v0
    gpr jr_addend_80064EF8 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80064EF4: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x80064EF8: jr          $v0
    // 0x80064EFC: nop

    switch (jr_addend_80064EF8 >> 2) {
        case 0: goto L_80064F00; break;
        case 1: goto L_80064F10; break;
        case 2: goto L_80064F20; break;
        case 3: goto L_80064F30; break;
        case 4: goto L_80064F40; break;
        case 5: goto L_80064F50; break;
        case 6: goto L_80064F60; break;
        case 7: goto L_80064F70; break;
        default: switch_error(__func__, 0x80064EF8, 0x8003BD68);
    }
    // 0x80064EFC: nop

L_80064F00:
    // 0x80064F00: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064F04: addiu       $s0, $v0, -0x44DC
    ctx->r16 = ADD32(ctx->r2, -0X44DC);
    // 0x80064F08: j           L_80064F7C
    // 0x80064F0C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_80064F7C;
    // 0x80064F0C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80064F10:
    // 0x80064F10: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064F14: addiu       $s0, $v0, -0x44D4
    ctx->r16 = ADD32(ctx->r2, -0X44D4);
    // 0x80064F18: j           L_80064F7C
    // 0x80064F1C: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
        goto L_80064F7C;
    // 0x80064F1C: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
L_80064F20:
    // 0x80064F20: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064F24: addiu       $s0, $v0, -0x44CC
    ctx->r16 = ADD32(ctx->r2, -0X44CC);
    // 0x80064F28: j           L_80064F7C
    // 0x80064F2C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
        goto L_80064F7C;
    // 0x80064F2C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_80064F30:
    // 0x80064F30: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064F34: addiu       $s0, $v0, -0x44C4
    ctx->r16 = ADD32(ctx->r2, -0X44C4);
    // 0x80064F38: j           L_80064F7C
    // 0x80064F3C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_80064F7C;
    // 0x80064F3C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80064F40:
    // 0x80064F40: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064F44: addiu       $s0, $v0, -0x44BC
    ctx->r16 = ADD32(ctx->r2, -0X44BC);
    // 0x80064F48: j           L_80064F7C
    // 0x80064F4C: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
        goto L_80064F7C;
    // 0x80064F4C: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_80064F50:
    // 0x80064F50: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064F54: addiu       $s0, $v0, -0x44B4
    ctx->r16 = ADD32(ctx->r2, -0X44B4);
    // 0x80064F58: j           L_80064F7C
    // 0x80064F5C: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
        goto L_80064F7C;
    // 0x80064F5C: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
L_80064F60:
    // 0x80064F60: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064F64: addiu       $s0, $v0, -0x44AC
    ctx->r16 = ADD32(ctx->r2, -0X44AC);
    // 0x80064F68: j           L_80064F7C
    // 0x80064F6C: addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
        goto L_80064F7C;
    // 0x80064F6C: addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
L_80064F70:
    // 0x80064F70: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80064F74: addiu       $s0, $v0, -0x44A8
    ctx->r16 = ADD32(ctx->r2, -0X44A8);
    // 0x80064F78: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
L_80064F7C:
    // 0x80064F7C: jal         0x80056DA4
    // 0x80064F80: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    isHobObjectLoaded(rdram, ctx);
        goto after_17;
    // 0x80064F80: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_17:
    // 0x80064F84: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80064F88: bne         $v0, $zero, L_80064FB4
    if (ctx->r2 != 0) {
        // 0x80064F8C: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_80064FB4;
    }
    // 0x80064F8C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80064F90: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80064F94: addiu       $a1, $a1, -0x44A4
    ctx->r5 = ADD32(ctx->r5, -0X44A4);
    // 0x80064F98: jal         0x80033CC4
    // 0x80064F9C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sprintf_recomp(rdram, ctx);
        goto after_18;
    // 0x80064F9C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_18:
    // 0x80064FA0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80064FA4: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80064FA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80064FAC: jal         0x8005645C
    // 0x80064FB0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    load_hmt_and_hob(rdram, ctx);
        goto after_19;
    // 0x80064FB0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_19:
L_80064FB4:
    // 0x80064FB4: jal         0x8006B710
    // 0x80064FB8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    loadCraftShadowTextures(rdram, ctx);
        goto after_20;
    // 0x80064FB8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_20:
    // 0x80064FBC: j           L_80065018
    // 0x80064FC0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
        goto L_80065018;
    // 0x80064FC0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
L_80064FC4:
    // 0x80064FC4: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_80064FC8:
    // 0x80064FC8: beq         $s0, $zero, L_80065018
    if (ctx->r16 == 0) {
        // 0x80064FCC: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_80065018;
    }
    // 0x80064FCC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80064FD0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80064FD4: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80064FD8: addiu       $a1, $a1, -0x4494
    ctx->r5 = ADD32(ctx->r5, -0X4494);
    // 0x80064FDC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x80064FE0: jal         0x80033CC4
    // 0x80064FE4: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    sprintf_recomp(rdram, ctx);
        goto after_21;
    // 0x80064FE4: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_21:
    // 0x80064FE8: andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
    // 0x80064FEC: beq         $v0, $zero, L_80065000
    if (ctx->r2 == 0) {
        // 0x80064FF0: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_80065000;
    }
    // 0x80064FF0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80064FF4: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80064FF8: j           L_80065008
    // 0x80064FFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80065008;
    // 0x80064FFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80065000:
    // 0x80065000: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80065004: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80065008:
    // 0x80065008: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8006500C:
    // 0x8006500C: jal         0x8005645C
    // 0x80065010: nop

    load_hmt_and_hob(rdram, ctx);
        goto after_22;
    // 0x80065010: nop

    after_22:
L_80065014:
    // 0x80065014: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
L_80065018:
    // 0x80065018: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x8006501C: lw          $v0, 0x75D8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X75D8);
    // 0x80065020: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80065024: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80065028: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8006502C: sltu        $v0, $t0, $v0
    ctx->r2 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x80065030: bne         $v0, $zero, L_800649E0
    if (ctx->r2 != 0) {
        // 0x80065034: sw          $t0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r8;
            goto L_800649E0;
    }
    // 0x80065034: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
L_80065038:
    // 0x80065038: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006503C: lw          $v0, 0xB70($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB70);
    // 0x80065040: addiu       $v1, $v0, -0x5
    ctx->r3 = ADD32(ctx->r2, -0X5);
    // 0x80065044: sltiu       $v0, $v1, 0xA
    ctx->r2 = ctx->r3 < 0XA ? 1 : 0;
    // 0x80065048: beq         $v0, $zero, L_80065080
    if (ctx->r2 == 0) {
        // 0x8006504C: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_80065080;
    }
    // 0x8006504C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80065050: addiu       $v0, $v0, -0x4278
    ctx->r2 = ADD32(ctx->r2, -0X4278);
    // 0x80065054: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80065058: addu        $v1, $v1, $v0
    gpr jr_addend_80065060 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8006505C: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x80065060: jr          $v0
    // 0x80065064: nop

    switch (jr_addend_80065060 >> 2) {
        case 0: goto L_80065068; break;
        case 1: goto L_80065068; break;
        case 2: goto L_80065080; break;
        case 3: goto L_80065080; break;
        case 4: goto L_80065068; break;
        case 5: goto L_80065080; break;
        case 6: goto L_80065068; break;
        case 7: goto L_80065080; break;
        case 8: goto L_80065068; break;
        case 9: goto L_80065068; break;
        default: switch_error(__func__, 0x80065060, 0x8003BD88);
    }
    // 0x80065064: nop

L_80065068:
    // 0x80065068: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8006506C: addiu       $a0, $a0, -0x448C
    ctx->r4 = ADD32(ctx->r4, -0X448C);
    // 0x80065070: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80065074: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80065078: jal         0x8005645C
    // 0x8006507C: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    load_hmt_and_hob(rdram, ctx);
        goto after_23;
    // 0x8006507C: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    after_23:
L_80065080:
    // 0x80065080: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80065084: lbu         $v0, -0x663E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X663E);
    // 0x80065088: bne         $v0, $zero, L_800650A0
    if (ctx->r2 != 0) {
        // 0x8006508C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800650A0;
    }
    // 0x8006508C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80065090: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x80065094: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80065098: bne         $v1, $v0, L_800650AC
    if (ctx->r3 != ctx->r2) {
        // 0x8006509C: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800650AC;
    }
    // 0x8006509C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_800650A0:
    // 0x800650A0: jal         0x8007C268
    // 0x800650A4: nop

    loadShieldPalette(rdram, ctx);
        goto after_24;
    // 0x800650A4: nop

    after_24:
    // 0x800650A8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_800650AC:
    // 0x800650AC: lbu         $v0, -0x6635($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6635);
    // 0x800650B0: beq         $v0, $zero, L_8006519C
    if (ctx->r2 == 0) {
        // 0x800650B4: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_8006519C;
    }
    // 0x800650B4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800650B8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800650BC: lbu         $v1, 0xB63($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XB63);
    // 0x800650C0: beq         $v1, $zero, L_80065150
    if (ctx->r3 == 0) {
        // 0x800650C4: addiu       $s1, $v0, -0x47CC
        ctx->r17 = ADD32(ctx->r2, -0X47CC);
            goto L_80065150;
    }
    // 0x800650C4: addiu       $s1, $v0, -0x47CC
    ctx->r17 = ADD32(ctx->r2, -0X47CC);
    // 0x800650C8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800650CC: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800650D0: addiu       $a1, $a1, -0x4478
    ctx->r5 = ADD32(ctx->r5, -0X4478);
    // 0x800650D4: jal         0x80033CC4
    // 0x800650D8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    sprintf_recomp(rdram, ctx);
        goto after_25;
    // 0x800650D8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_25:
    // 0x800650DC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800650E0: addiu       $a0, $a0, -0x4468
    ctx->r4 = ADD32(ctx->r4, -0X4468);
    // 0x800650E4: jal         0x800547C0
    // 0x800650E8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    loadAssetIntoNewSlot(rdram, ctx);
        goto after_26;
    // 0x800650E8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_26:
    // 0x800650EC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800650F0: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800650F4: addiu       $a1, $a1, -0x4460
    ctx->r5 = ADD32(ctx->r5, -0X4460);
    // 0x800650F8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x800650FC: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80065100: jal         0x80033CC4
    // 0x80065104: sh          $v0, -0x6618($s0)
    MEM_H(-0X6618, ctx->r16) = ctx->r2;
    sprintf_recomp(rdram, ctx);
        goto after_27;
    // 0x80065104: sh          $v0, -0x6618($s0)
    MEM_H(-0X6618, ctx->r16) = ctx->r2;
    after_27:
    // 0x80065108: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8006510C: addiu       $a0, $a0, -0x4450
    ctx->r4 = ADD32(ctx->r4, -0X4450);
    // 0x80065110: jal         0x800547C0
    // 0x80065114: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    loadAssetIntoNewSlot(rdram, ctx);
        goto after_28;
    // 0x80065114: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_28:
    // 0x80065118: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8006511C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80065120: lwc1        $f20, -0x4250($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X4250);
    // 0x80065124: lhu         $a0, -0x6618($s0)
    ctx->r4 = MEM_HU(ctx->r16, -0X6618);
    // 0x80065128: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8006512C: addiu       $s0, $s0, -0x6618
    ctx->r16 = ADD32(ctx->r16, -0X6618);
    // 0x80065130: jal         0x80054B0C
    // 0x80065134: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    func_80054B0C(rdram, ctx);
        goto after_29;
    // 0x80065134: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    after_29:
    // 0x80065138: lhu         $a0, 0x2($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X2);
    // 0x8006513C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80065140: jal         0x80054B0C
    // 0x80065144: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80054B0C(rdram, ctx);
        goto after_30;
    // 0x80065144: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_30:
    // 0x80065148: j           L_800651A0
    // 0x8006514C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
        goto L_800651A0;
    // 0x8006514C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_80065150:
    // 0x80065150: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80065154: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80065158: addiu       $a1, $a1, -0x4448
    ctx->r5 = ADD32(ctx->r5, -0X4448);
    // 0x8006515C: jal         0x80033CC4
    // 0x80065160: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    sprintf_recomp(rdram, ctx);
        goto after_31;
    // 0x80065160: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_31:
    // 0x80065164: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80065168: addiu       $a0, $a0, -0x4468
    ctx->r4 = ADD32(ctx->r4, -0X4468);
    // 0x8006516C: jal         0x800547C0
    // 0x80065170: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    loadAssetIntoNewSlot(rdram, ctx);
        goto after_32;
    // 0x80065170: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_32:
    // 0x80065174: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80065178: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8006517C: sh          $v0, -0x6618($s0)
    MEM_H(-0X6618, ctx->r16) = ctx->r2;
    // 0x80065180: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x80065184: lui         $a1, 0x4019
    ctx->r5 = S32(0X4019 << 16);
    // 0x80065188: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8006518C: jal         0x80054B0C
    // 0x80065190: addiu       $s0, $s0, -0x6618
    ctx->r16 = ADD32(ctx->r16, -0X6618);
    func_80054B0C(rdram, ctx);
        goto after_33;
    // 0x80065190: addiu       $s0, $s0, -0x6618
    ctx->r16 = ADD32(ctx->r16, -0X6618);
    after_33:
    // 0x80065194: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80065198: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
L_8006519C:
    // 0x8006519C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_800651A0:
    // 0x800651A0: lbu         $v0, -0x6634($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6634);
    // 0x800651A4: beq         $v0, $zero, L_8006523C
    if (ctx->r2 == 0) {
        // 0x800651A8: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_8006523C;
    }
    // 0x800651A8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800651AC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800651B0: lbu         $v1, 0xB63($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XB63);
    // 0x800651B4: beq         $v1, $zero, L_800651F8
    if (ctx->r3 == 0) {
        // 0x800651B8: addiu       $s1, $v0, -0x4718
        ctx->r17 = ADD32(ctx->r2, -0X4718);
            goto L_800651F8;
    }
    // 0x800651B8: addiu       $s1, $v0, -0x4718
    ctx->r17 = ADD32(ctx->r2, -0X4718);
    // 0x800651BC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800651C0: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800651C4: addiu       $a1, $a1, -0x4434
    ctx->r5 = ADD32(ctx->r5, -0X4434);
    // 0x800651C8: jal         0x80033CC4
    // 0x800651CC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    sprintf_recomp(rdram, ctx);
        goto after_34;
    // 0x800651CC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_34:
    // 0x800651D0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800651D4: addiu       $a0, $a0, -0x4424
    ctx->r4 = ADD32(ctx->r4, -0X4424);
    // 0x800651D8: jal         0x800547C0
    // 0x800651DC: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    loadAssetIntoNewSlot(rdram, ctx);
        goto after_35;
    // 0x800651DC: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_35:
    // 0x800651E0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800651E4: addiu       $v1, $v1, -0x6618
    ctx->r3 = ADD32(ctx->r3, -0X6618);
    // 0x800651E8: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
    // 0x800651EC: lui         $a1, 0x4140
    ctx->r5 = S32(0X4140 << 16);
    // 0x800651F0: j           L_80065234
    // 0x800651F4: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
        goto L_80065234;
    // 0x800651F4: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
L_800651F8:
    // 0x800651F8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800651FC: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80065200: addiu       $a1, $a1, -0x441C
    ctx->r5 = ADD32(ctx->r5, -0X441C);
    // 0x80065204: jal         0x80033CC4
    // 0x80065208: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    sprintf_recomp(rdram, ctx);
        goto after_36;
    // 0x80065208: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_36:
    // 0x8006520C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80065210: addiu       $a0, $a0, -0x4424
    ctx->r4 = ADD32(ctx->r4, -0X4424);
    // 0x80065214: jal         0x800547C0
    // 0x80065218: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    loadAssetIntoNewSlot(rdram, ctx);
        goto after_37;
    // 0x80065218: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_37:
    // 0x8006521C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80065220: addiu       $v1, $v1, -0x6618
    ctx->r3 = ADD32(ctx->r3, -0X6618);
    // 0x80065224: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
    // 0x80065228: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x8006522C: lui         $a1, 0x4019
    ctx->r5 = S32(0X4019 << 16);
    // 0x80065230: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
L_80065234:
    // 0x80065234: jal         0x80054B0C
    // 0x80065238: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80054B0C(rdram, ctx);
        goto after_38;
    // 0x80065238: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_38:
L_8006523C:
    // 0x8006523C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80065240: lbu         $v0, -0x6633($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6633);
    // 0x80065244: beq         $v0, $zero, L_800652DC
    if (ctx->r2 == 0) {
        // 0x80065248: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_800652DC;
    }
    // 0x80065248: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8006524C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80065250: lbu         $v1, 0xB63($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XB63);
    // 0x80065254: beq         $v1, $zero, L_80065298
    if (ctx->r3 == 0) {
        // 0x80065258: addiu       $s1, $v0, -0x4750
        ctx->r17 = ADD32(ctx->r2, -0X4750);
            goto L_80065298;
    }
    // 0x80065258: addiu       $s1, $v0, -0x4750
    ctx->r17 = ADD32(ctx->r2, -0X4750);
    // 0x8006525C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80065260: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80065264: addiu       $a1, $a1, -0x4408
    ctx->r5 = ADD32(ctx->r5, -0X4408);
    // 0x80065268: jal         0x80033CC4
    // 0x8006526C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    sprintf_recomp(rdram, ctx);
        goto after_39;
    // 0x8006526C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_39:
    // 0x80065270: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80065274: addiu       $a0, $a0, -0x43F8
    ctx->r4 = ADD32(ctx->r4, -0X43F8);
    // 0x80065278: jal         0x800547C0
    // 0x8006527C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    loadAssetIntoNewSlot(rdram, ctx);
        goto after_40;
    // 0x8006527C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_40:
    // 0x80065280: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80065284: addiu       $v1, $v1, -0x6618
    ctx->r3 = ADD32(ctx->r3, -0X6618);
    // 0x80065288: sh          $v0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r2;
    // 0x8006528C: lui         $a1, 0x4140
    ctx->r5 = S32(0X4140 << 16);
    // 0x80065290: j           L_800652D4
    // 0x80065294: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
        goto L_800652D4;
    // 0x80065294: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
L_80065298:
    // 0x80065298: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8006529C: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800652A0: addiu       $a1, $a1, -0x43F0
    ctx->r5 = ADD32(ctx->r5, -0X43F0);
    // 0x800652A4: jal         0x80033CC4
    // 0x800652A8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    sprintf_recomp(rdram, ctx);
        goto after_41;
    // 0x800652A8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_41:
    // 0x800652AC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800652B0: addiu       $a0, $a0, -0x43F8
    ctx->r4 = ADD32(ctx->r4, -0X43F8);
    // 0x800652B4: jal         0x800547C0
    // 0x800652B8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    loadAssetIntoNewSlot(rdram, ctx);
        goto after_42;
    // 0x800652B8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_42:
    // 0x800652BC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800652C0: addiu       $v1, $v1, -0x6618
    ctx->r3 = ADD32(ctx->r3, -0X6618);
    // 0x800652C4: sh          $v0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r2;
    // 0x800652C8: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x800652CC: lui         $a1, 0x4019
    ctx->r5 = S32(0X4019 << 16);
    // 0x800652D0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
L_800652D4:
    // 0x800652D4: jal         0x80054B0C
    // 0x800652D8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80054B0C(rdram, ctx);
        goto after_43;
    // 0x800652D8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_43:
L_800652DC:
    // 0x800652DC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800652E0: lbu         $v0, -0x6620($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6620);
    // 0x800652E4: beq         $v0, $zero, L_8006537C
    if (ctx->r2 == 0) {
        // 0x800652E8: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_8006537C;
    }
    // 0x800652E8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800652EC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800652F0: lbu         $v1, 0xB63($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XB63);
    // 0x800652F4: beq         $v1, $zero, L_80065338
    if (ctx->r3 == 0) {
        // 0x800652F8: addiu       $s1, $v0, -0x47CC
        ctx->r17 = ADD32(ctx->r2, -0X47CC);
            goto L_80065338;
    }
    // 0x800652F8: addiu       $s1, $v0, -0x47CC
    ctx->r17 = ADD32(ctx->r2, -0X47CC);
    // 0x800652FC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80065300: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80065304: addiu       $a1, $a1, -0x43DC
    ctx->r5 = ADD32(ctx->r5, -0X43DC);
    // 0x80065308: jal         0x80033CC4
    // 0x8006530C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    sprintf_recomp(rdram, ctx);
        goto after_44;
    // 0x8006530C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_44:
    // 0x80065310: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80065314: addiu       $a0, $a0, -0x43CC
    ctx->r4 = ADD32(ctx->r4, -0X43CC);
    // 0x80065318: jal         0x800547C0
    // 0x8006531C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    loadAssetIntoNewSlot(rdram, ctx);
        goto after_45;
    // 0x8006531C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_45:
    // 0x80065320: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80065324: addiu       $v1, $v1, -0x6618
    ctx->r3 = ADD32(ctx->r3, -0X6618);
    // 0x80065328: sh          $v0, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r2;
    // 0x8006532C: lui         $a1, 0x4140
    ctx->r5 = S32(0X4140 << 16);
    // 0x80065330: j           L_80065374
    // 0x80065334: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
        goto L_80065374;
    // 0x80065334: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
L_80065338:
    // 0x80065338: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8006533C: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80065340: addiu       $a1, $a1, -0x43C4
    ctx->r5 = ADD32(ctx->r5, -0X43C4);
    // 0x80065344: jal         0x80033CC4
    // 0x80065348: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    sprintf_recomp(rdram, ctx);
        goto after_46;
    // 0x80065348: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_46:
    // 0x8006534C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80065350: addiu       $a0, $a0, -0x43CC
    ctx->r4 = ADD32(ctx->r4, -0X43CC);
    // 0x80065354: jal         0x800547C0
    // 0x80065358: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    loadAssetIntoNewSlot(rdram, ctx);
        goto after_47;
    // 0x80065358: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_47:
    // 0x8006535C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80065360: addiu       $v1, $v1, -0x6618
    ctx->r3 = ADD32(ctx->r3, -0X6618);
    // 0x80065364: sh          $v0, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r2;
    // 0x80065368: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x8006536C: lui         $a1, 0x4019
    ctx->r5 = S32(0X4019 << 16);
    // 0x80065370: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
L_80065374:
    // 0x80065374: jal         0x80054B0C
    // 0x80065378: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80054B0C(rdram, ctx);
        goto after_48;
    // 0x80065378: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_48:
L_8006537C:
    // 0x8006537C: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80065380: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x80065384: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x80065388: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x8006538C: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x80065390: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80065394: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80065398: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8006539C: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800653A0: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800653A4: ldc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X68);
    // 0x800653A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800653AC: jr          $ra
    // 0x800653B0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800653B0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void setupNpcUpdateFunctions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800653B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800653B8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800653BC: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800653C0: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800653C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800653C8: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x800653CC: addiu       $v1, $v0, -0xC
    ctx->r3 = ADD32(ctx->r2, -0XC);
    // 0x800653D0: sltiu       $v0, $v1, 0x47
    ctx->r2 = ctx->r3 < 0X47 ? 1 : 0;
    // 0x800653D4: beq         $v0, $zero, L_80065650
    if (ctx->r2 == 0) {
        // 0x800653D8: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_80065650;
    }
    // 0x800653D8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800653DC: addiu       $v0, $v0, -0x4248
    ctx->r2 = ADD32(ctx->r2, -0X4248);
    // 0x800653E0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800653E4: addu        $v1, $v1, $v0
    gpr jr_addend_800653EC = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800653E8: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800653EC: jr          $v0
    // 0x800653F0: nop

    switch (jr_addend_800653EC >> 2) {
        case 0: goto L_80065420; break;
        case 1: goto L_80065438; break;
        case 2: goto L_80065450; break;
        case 3: goto L_80065468; break;
        case 4: goto L_80065558; break;
        case 5: goto L_80065650; break;
        case 6: goto L_80065420; break;
        case 7: goto L_80065420; break;
        case 8: goto L_800653F4; break;
        case 9: goto L_80065650; break;
        case 10: goto L_80065650; break;
        case 11: goto L_80065650; break;
        case 12: goto L_80065650; break;
        case 13: goto L_80065570; break;
        case 14: goto L_80065650; break;
        case 15: goto L_80065650; break;
        case 16: goto L_80065650; break;
        case 17: goto L_80065650; break;
        case 18: goto L_80065438; break;
        case 19: goto L_80065480; break;
        case 20: goto L_80065650; break;
        case 21: goto L_800654B0; break;
        case 22: goto L_80065650; break;
        case 23: goto L_80065650; break;
        case 24: goto L_800654C8; break;
        case 25: goto L_800654E0; break;
        case 26: goto L_80065650; break;
        case 27: goto L_80065510; break;
        case 28: goto L_80065438; break;
        case 29: goto L_80065420; break;
        case 30: goto L_80065528; break;
        case 31: goto L_80065540; break;
        case 32: goto L_800654C8; break;
        case 33: goto L_80065540; break;
        case 34: goto L_80065540; break;
        case 35: goto L_80065588; break;
        case 36: goto L_80065588; break;
        case 37: goto L_80065588; break;
        case 38: goto L_800655A0; break;
        case 39: goto L_800655B8; break;
        case 40: goto L_80065588; break;
        case 41: goto L_80065588; break;
        case 42: goto L_800655B8; break;
        case 43: goto L_800655F4; break;
        case 44: goto L_80065650; break;
        case 45: goto L_80065650; break;
        case 46: goto L_80065650; break;
        case 47: goto L_800654F8; break;
        case 48: goto L_800654F8; break;
        case 49: goto L_800654F8; break;
        case 50: goto L_800655C4; break;
        case 51: goto L_80065650; break;
        case 52: goto L_800655DC; break;
        case 53: goto L_80065438; break;
        case 54: goto L_80065438; break;
        case 55: goto L_80065420; break;
        case 56: goto L_800655B8; break;
        case 57: goto L_80065650; break;
        case 58: goto L_8006560C; break;
        case 59: goto L_80065498; break;
        case 60: goto L_800654C8; break;
        case 61: goto L_80065650; break;
        case 62: goto L_80065620; break;
        case 63: goto L_800655B8; break;
        case 64: goto L_80065638; break;
        case 65: goto L_800654C8; break;
        case 66: goto L_80065650; break;
        case 67: goto L_800655B8; break;
        case 68: goto L_800654F8; break;
        case 69: goto L_80065650; break;
        case 70: goto L_80065650; break;
        default: switch_error(__func__, 0x800653EC, 0x8003BDB8);
    }
    // 0x800653F0: nop

L_800653F4:
    // 0x800653F4: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800653F8: addiu       $a0, $a0, -0x3450
    ctx->r4 = ADD32(ctx->r4, -0X3450);
    // 0x800653FC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80065400: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    // 0x80065404: lhu         $v0, 0x8A($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X8A);
    // 0x80065408: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8006540C: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // 0x80065410: sll         $a2, $a2, 6
    ctx->r6 = S32(ctx->r6 << 6);
    // 0x80065414: ori         $a2, $a2, 0x1
    ctx->r6 = ctx->r6 | 0X1;
    // 0x80065418: j           L_80065664
    // 0x8006541C: andi        $a2, $a2, 0xFFC1
    ctx->r6 = ctx->r6 & 0XFFC1;
        goto L_80065664;
    // 0x8006541C: andi        $a2, $a2, 0xFFC1
    ctx->r6 = ctx->r6 & 0XFFC1;
L_80065420:
    // 0x80065420: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80065424: addiu       $a0, $a0, -0x4EE4
    ctx->r4 = ADD32(ctx->r4, -0X4EE4);
    // 0x80065428: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8006542C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80065430: j           L_80065664
    // 0x80065434: addiu       $a3, $zero, 0x55
    ctx->r7 = ADD32(0, 0X55);
        goto L_80065664;
    // 0x80065434: addiu       $a3, $zero, 0x55
    ctx->r7 = ADD32(0, 0X55);
L_80065438:
    // 0x80065438: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8006543C: addiu       $a0, $a0, -0x7070
    ctx->r4 = ADD32(ctx->r4, -0X7070);
    // 0x80065440: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80065444: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80065448: j           L_80065664
    // 0x8006544C: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
        goto L_80065664;
    // 0x8006544C: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
L_80065450:
    // 0x80065450: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80065454: addiu       $a0, $a0, -0x542C
    ctx->r4 = ADD32(ctx->r4, -0X542C);
    // 0x80065458: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8006545C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80065460: j           L_80065664
    // 0x80065464: addiu       $a3, $zero, 0x55
    ctx->r7 = ADD32(0, 0X55);
        goto L_80065664;
    // 0x80065464: addiu       $a3, $zero, 0x55
    ctx->r7 = ADD32(0, 0X55);
L_80065468:
    // 0x80065468: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8006546C: addiu       $a0, $a0, -0x28E4
    ctx->r4 = ADD32(ctx->r4, -0X28E4);
    // 0x80065470: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80065474: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80065478: j           L_80065664
    // 0x8006547C: addiu       $a3, $zero, 0x55
    ctx->r7 = ADD32(0, 0X55);
        goto L_80065664;
    // 0x8006547C: addiu       $a3, $zero, 0x55
    ctx->r7 = ADD32(0, 0X55);
L_80065480:
    // 0x80065480: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80065484: addiu       $a0, $a0, -0x184
    ctx->r4 = ADD32(ctx->r4, -0X184);
    // 0x80065488: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8006548C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80065490: j           L_80065664
    // 0x80065494: addiu       $a3, $zero, 0x55
    ctx->r7 = ADD32(0, 0X55);
        goto L_80065664;
    // 0x80065494: addiu       $a3, $zero, 0x55
    ctx->r7 = ADD32(0, 0X55);
L_80065498:
    // 0x80065498: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8006549C: addiu       $a0, $a0, -0x5A20
    ctx->r4 = ADD32(ctx->r4, -0X5A20);
    // 0x800654A0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800654A4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800654A8: j           L_80065664
    // 0x800654AC: addiu       $a3, $zero, 0x55
    ctx->r7 = ADD32(0, 0X55);
        goto L_80065664;
    // 0x800654AC: addiu       $a3, $zero, 0x55
    ctx->r7 = ADD32(0, 0X55);
L_800654B0:
    // 0x800654B0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800654B4: addiu       $a0, $a0, 0x5208
    ctx->r4 = ADD32(ctx->r4, 0X5208);
    // 0x800654B8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800654BC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800654C0: j           L_80065664
    // 0x800654C4: addiu       $a3, $zero, 0x55
    ctx->r7 = ADD32(0, 0X55);
        goto L_80065664;
    // 0x800654C4: addiu       $a3, $zero, 0x55
    ctx->r7 = ADD32(0, 0X55);
L_800654C8:
    // 0x800654C8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800654CC: addiu       $a0, $a0, 0x3894
    ctx->r4 = ADD32(ctx->r4, 0X3894);
    // 0x800654D0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800654D4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800654D8: j           L_80065664
    // 0x800654DC: addiu       $a3, $zero, 0x55
    ctx->r7 = ADD32(0, 0X55);
        goto L_80065664;
    // 0x800654DC: addiu       $a3, $zero, 0x55
    ctx->r7 = ADD32(0, 0X55);
L_800654E0:
    // 0x800654E0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800654E4: addiu       $a0, $a0, 0x6998
    ctx->r4 = ADD32(ctx->r4, 0X6998);
    // 0x800654E8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800654EC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800654F0: j           L_80065664
    // 0x800654F4: addiu       $a3, $zero, 0x55
    ctx->r7 = ADD32(0, 0X55);
        goto L_80065664;
    // 0x800654F4: addiu       $a3, $zero, 0x55
    ctx->r7 = ADD32(0, 0X55);
L_800654F8:
    // 0x800654F8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800654FC: addiu       $a0, $a0, 0x7860
    ctx->r4 = ADD32(ctx->r4, 0X7860);
    // 0x80065500: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80065504: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80065508: j           L_80065664
    // 0x8006550C: addiu       $a3, $zero, 0x55
    ctx->r7 = ADD32(0, 0X55);
        goto L_80065664;
    // 0x8006550C: addiu       $a3, $zero, 0x55
    ctx->r7 = ADD32(0, 0X55);
L_80065510:
    // 0x80065510: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80065514: addiu       $a0, $a0, -0x6C40
    ctx->r4 = ADD32(ctx->r4, -0X6C40);
    // 0x80065518: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8006551C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80065520: j           L_80065664
    // 0x80065524: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
        goto L_80065664;
    // 0x80065524: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
L_80065528:
    // 0x80065528: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006552C: addiu       $a0, $a0, -0x3910
    ctx->r4 = ADD32(ctx->r4, -0X3910);
    // 0x80065530: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80065534: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80065538: j           L_80065664
    // 0x8006553C: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
        goto L_80065664;
    // 0x8006553C: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
L_80065540:
    // 0x80065540: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80065544: addiu       $a0, $a0, -0x17F4
    ctx->r4 = ADD32(ctx->r4, -0X17F4);
    // 0x80065548: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8006554C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80065550: j           L_80065664
    // 0x80065554: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
        goto L_80065664;
    // 0x80065554: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
L_80065558:
    // 0x80065558: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8006555C: addiu       $a0, $a0, -0x33D8
    ctx->r4 = ADD32(ctx->r4, -0X33D8);
    // 0x80065560: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80065564: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80065568: j           L_80065664
    // 0x8006556C: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
        goto L_80065664;
    // 0x8006556C: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
L_80065570:
    // 0x80065570: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80065574: addiu       $a0, $a0, -0x31F0
    ctx->r4 = ADD32(ctx->r4, -0X31F0);
    // 0x80065578: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8006557C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80065580: j           L_80065664
    // 0x80065584: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
        goto L_80065664;
    // 0x80065584: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
L_80065588:
    // 0x80065588: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006558C: addiu       $a0, $a0, 0x2818
    ctx->r4 = ADD32(ctx->r4, 0X2818);
    // 0x80065590: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80065594: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80065598: j           L_80065664
    // 0x8006559C: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
        goto L_80065664;
    // 0x8006559C: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
L_800655A0:
    // 0x800655A0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800655A4: addiu       $a0, $a0, -0x5108
    ctx->r4 = ADD32(ctx->r4, -0X5108);
    // 0x800655A8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800655AC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800655B0: j           L_80065664
    // 0x800655B4: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
        goto L_80065664;
    // 0x800655B4: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
L_800655B8:
    // 0x800655B8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800655BC: j           L_80065658
    // 0x800655C0: addiu       $a0, $a0, 0x4070
    ctx->r4 = ADD32(ctx->r4, 0X4070);
        goto L_80065658;
    // 0x800655C0: addiu       $a0, $a0, 0x4070
    ctx->r4 = ADD32(ctx->r4, 0X4070);
L_800655C4:
    // 0x800655C4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800655C8: addiu       $a0, $a0, 0x614C
    ctx->r4 = ADD32(ctx->r4, 0X614C);
    // 0x800655CC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800655D0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800655D4: j           L_80065664
    // 0x800655D8: addiu       $a3, $zero, 0x55
    ctx->r7 = ADD32(0, 0X55);
        goto L_80065664;
    // 0x800655D8: addiu       $a3, $zero, 0x55
    ctx->r7 = ADD32(0, 0X55);
L_800655DC:
    // 0x800655DC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800655E0: addiu       $a0, $a0, 0x614C
    ctx->r4 = ADD32(ctx->r4, 0X614C);
    // 0x800655E4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800655E8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800655EC: j           L_80065664
    // 0x800655F0: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
        goto L_80065664;
    // 0x800655F0: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
L_800655F4:
    // 0x800655F4: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800655F8: addiu       $a0, $a0, -0x10E4
    ctx->r4 = ADD32(ctx->r4, -0X10E4);
    // 0x800655FC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80065600: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80065604: j           L_80065664
    // 0x80065608: addiu       $a3, $zero, 0x55
    ctx->r7 = ADD32(0, 0X55);
        goto L_80065664;
    // 0x80065608: addiu       $a3, $zero, 0x55
    ctx->r7 = ADD32(0, 0X55);
L_8006560C:
    // 0x8006560C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80065610: addiu       $a0, $a0, -0x7124
    ctx->r4 = ADD32(ctx->r4, -0X7124);
    // 0x80065614: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80065618: j           L_80065660
    // 0x8006561C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
        goto L_80065660;
    // 0x8006561C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_80065620:
    // 0x80065620: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80065624: addiu       $a0, $a0, 0x7AF0
    ctx->r4 = ADD32(ctx->r4, 0X7AF0);
    // 0x80065628: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8006562C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80065630: j           L_80065664
    // 0x80065634: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
        goto L_80065664;
    // 0x80065634: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
L_80065638:
    // 0x80065638: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8006563C: addiu       $a0, $a0, -0x4670
    ctx->r4 = ADD32(ctx->r4, -0X4670);
    // 0x80065640: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80065644: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80065648: j           L_80065664
    // 0x8006564C: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
        goto L_80065664;
    // 0x8006564C: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
L_80065650:
    // 0x80065650: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80065654: addiu       $a0, $a0, 0x77A0
    ctx->r4 = ADD32(ctx->r4, 0X77A0);
L_80065658:
    // 0x80065658: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8006565C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80065660:
    // 0x80065660: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
L_80065664:
    // 0x80065664: jal         0x8003FFEC
    // 0x80065668: nop

    spawnNpcOfType(rdram, ctx);
        goto after_0;
    // 0x80065668: nop

    after_0:
    // 0x8006566C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80065670: andi        $s0, $v1, 0xFFFF
    ctx->r16 = ctx->r3 & 0XFFFF;
    // 0x80065674: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80065678: lwc1        $f0, -0x412C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X412C);
    // 0x8006567C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80065680: beq         $s0, $v0, L_8006569C
    if (ctx->r16 == ctx->r2) {
        // 0x80065684: swc1        $f0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
            goto L_8006569C;
    }
    // 0x80065684: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80065688: sh          $v1, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r3;
    // 0x8006568C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80065690: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80065694: jal         0x8003E8DC
    // 0x80065698: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    slotDispatcherIter(rdram, ctx);
        goto after_1;
    // 0x80065698: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_1:
L_8006569C:
    // 0x8006569C: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x800656A0: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800656A4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800656A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800656AC: jr          $ra
    // 0x800656B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800656B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800656B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800656B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800656B8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800656BC: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800656C0: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800656C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800656C8: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x800656CC: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800656D0: addiu       $v1, $v0, -0xC
    ctx->r3 = ADD32(ctx->r2, -0XC);
    // 0x800656D4: sltiu       $v0, $v1, 0x45
    ctx->r2 = ctx->r3 < 0X45 ? 1 : 0;
    // 0x800656D8: beq         $v0, $zero, L_80065748
    if (ctx->r2 == 0) {
        // 0x800656DC: ori         $a3, $zero, 0xFFFF
        ctx->r7 = 0 | 0XFFFF;
            goto L_80065748;
    }
    // 0x800656DC: ori         $a3, $zero, 0xFFFF
    ctx->r7 = 0 | 0XFFFF;
    // 0x800656E0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800656E4: addiu       $v0, $v0, -0x4128
    ctx->r2 = ADD32(ctx->r2, -0X4128);
    // 0x800656E8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800656EC: addu        $v1, $v1, $v0
    gpr jr_addend_800656F4 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800656F0: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800656F4: jr          $v0
    // 0x800656F8: nop

    switch (jr_addend_800656F4 >> 2) {
        case 0: goto L_800656FC; break;
        case 1: goto L_80065748; break;
        case 2: goto L_80065748; break;
        case 3: goto L_80065748; break;
        case 4: goto L_80065748; break;
        case 5: goto L_80065748; break;
        case 6: goto L_800656FC; break;
        case 7: goto L_800656FC; break;
        case 8: goto L_80065748; break;
        case 9: goto L_80065748; break;
        case 10: goto L_80065748; break;
        case 11: goto L_80065748; break;
        case 12: goto L_80065748; break;
        case 13: goto L_80065748; break;
        case 14: goto L_80065748; break;
        case 15: goto L_80065748; break;
        case 16: goto L_80065748; break;
        case 17: goto L_80065748; break;
        case 18: goto L_80065748; break;
        case 19: goto L_80065720; break;
        case 20: goto L_80065748; break;
        case 21: goto L_80065714; break;
        case 22: goto L_80065748; break;
        case 23: goto L_80065748; break;
        case 24: goto L_80065708; break;
        case 25: goto L_80065748; break;
        case 26: goto L_80065748; break;
        case 27: goto L_80065748; break;
        case 28: goto L_80065748; break;
        case 29: goto L_800656FC; break;
        case 30: goto L_80065748; break;
        case 31: goto L_80065748; break;
        case 32: goto L_80065708; break;
        case 33: goto L_80065748; break;
        case 34: goto L_80065748; break;
        case 35: goto L_80065748; break;
        case 36: goto L_80065748; break;
        case 37: goto L_80065748; break;
        case 38: goto L_80065748; break;
        case 39: goto L_80065748; break;
        case 40: goto L_80065748; break;
        case 41: goto L_80065748; break;
        case 42: goto L_80065748; break;
        case 43: goto L_80065748; break;
        case 44: goto L_80065748; break;
        case 45: goto L_80065748; break;
        case 46: goto L_80065748; break;
        case 47: goto L_8006572C; break;
        case 48: goto L_8006572C; break;
        case 49: goto L_8006572C; break;
        case 50: goto L_80065748; break;
        case 51: goto L_80065748; break;
        case 52: goto L_80065748; break;
        case 53: goto L_80065748; break;
        case 54: goto L_80065748; break;
        case 55: goto L_800656FC; break;
        case 56: goto L_80065748; break;
        case 57: goto L_80065748; break;
        case 58: goto L_80065748; break;
        case 59: goto L_80065748; break;
        case 60: goto L_80065708; break;
        case 61: goto L_80065748; break;
        case 62: goto L_80065748; break;
        case 63: goto L_80065748; break;
        case 64: goto L_80065748; break;
        case 65: goto L_80065708; break;
        case 66: goto L_80065748; break;
        case 67: goto L_80065748; break;
        case 68: goto L_8006572C; break;
        default: switch_error(__func__, 0x800656F4, 0x8003BED8);
    }
    // 0x800656F8: nop

L_800656FC:
    // 0x800656FC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80065700: j           L_80065734
    // 0x80065704: addiu       $a0, $a0, -0x4EE4
    ctx->r4 = ADD32(ctx->r4, -0X4EE4);
        goto L_80065734;
    // 0x80065704: addiu       $a0, $a0, -0x4EE4
    ctx->r4 = ADD32(ctx->r4, -0X4EE4);
L_80065708:
    // 0x80065708: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8006570C: j           L_80065734
    // 0x80065710: addiu       $a0, $a0, 0x3894
    ctx->r4 = ADD32(ctx->r4, 0X3894);
        goto L_80065734;
    // 0x80065710: addiu       $a0, $a0, 0x3894
    ctx->r4 = ADD32(ctx->r4, 0X3894);
L_80065714:
    // 0x80065714: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80065718: j           L_80065734
    // 0x8006571C: addiu       $a0, $a0, 0x5208
    ctx->r4 = ADD32(ctx->r4, 0X5208);
        goto L_80065734;
    // 0x8006571C: addiu       $a0, $a0, 0x5208
    ctx->r4 = ADD32(ctx->r4, 0X5208);
L_80065720:
    // 0x80065720: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80065724: j           L_80065734
    // 0x80065728: addiu       $a0, $a0, -0x184
    ctx->r4 = ADD32(ctx->r4, -0X184);
        goto L_80065734;
    // 0x80065728: addiu       $a0, $a0, -0x184
    ctx->r4 = ADD32(ctx->r4, -0X184);
L_8006572C:
    // 0x8006572C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80065730: addiu       $a0, $a0, 0x7860
    ctx->r4 = ADD32(ctx->r4, 0X7860);
L_80065734:
    // 0x80065734: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80065738: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    // 0x8006573C: jal         0x8003FE9C
    // 0x80065740: addiu       $a3, $zero, 0x55
    ctx->r7 = ADD32(0, 0X55);
    func_8003FE9C(rdram, ctx);
        goto after_0;
    // 0x80065740: addiu       $a3, $zero, 0x55
    ctx->r7 = ADD32(0, 0X55);
    after_0:
    // 0x80065744: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
L_80065748:
    // 0x80065748: andi        $s0, $a3, 0xFFFF
    ctx->r16 = ctx->r7 & 0XFFFF;
    // 0x8006574C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80065750: lwc1        $f0, -0x4014($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4014);
    // 0x80065754: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80065758: beq         $s0, $v0, L_80065778
    if (ctx->r16 == ctx->r2) {
        // 0x8006575C: swc1        $f0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
            goto L_80065778;
    }
    // 0x8006575C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80065760: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80065764: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80065768: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x8006576C: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // 0x80065770: jal         0x8003E8DC
    // 0x80065774: sh          $a3, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r7;
    slotDispatcherIter(rdram, ctx);
        goto after_1;
    // 0x80065774: sh          $a3, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r7;
    after_1:
L_80065778:
    // 0x80065778: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8006577C: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80065780: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80065784: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80065788: jr          $ra
    // 0x8006578C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006578C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void parseDatSpawnPositions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065790: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80065794: lbu         $v0, 0xB63($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB63);
    // 0x80065798: bne         $v0, $zero, L_800657AC
    if (ctx->r2 != 0) {
        // 0x8006579C: nop
    
            goto L_800657AC;
    }
    // 0x8006579C: nop

    // 0x800657A0: lbu         $v0, 0x3($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X3);
    // 0x800657A4: bne         $v0, $zero, L_80065820
    if (ctx->r2 != 0) {
        // 0x800657A8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80065820;
    }
    // 0x800657A8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800657AC:
    // 0x800657AC: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x800657B0: sltiu       $v0, $v1, 0x53
    ctx->r2 = ctx->r3 < 0X53 ? 1 : 0;
    // 0x800657B4: beq         $v0, $zero, L_80065818
    if (ctx->r2 == 0) {
        // 0x800657B8: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_80065818;
    }
    // 0x800657B8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800657BC: addiu       $v0, $v0, -0x4010
    ctx->r2 = ADD32(ctx->r2, -0X4010);
    // 0x800657C0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800657C4: addu        $v1, $v1, $v0
    gpr jr_addend_800657CC = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800657C8: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800657CC: jr          $v0
    // 0x800657D0: nop

    switch (jr_addend_800657CC >> 2) {
        case 0: goto L_800657D4; break;
        case 1: goto L_80065818; break;
        case 2: goto L_80065818; break;
        case 3: goto L_80065818; break;
        case 4: goto L_80065818; break;
        case 5: goto L_80065818; break;
        case 6: goto L_80065818; break;
        case 7: goto L_80065818; break;
        case 8: goto L_80065818; break;
        case 9: goto L_80065818; break;
        case 10: goto L_80065818; break;
        case 11: goto L_80065818; break;
        case 12: goto L_800657DC; break;
        case 13: goto L_800657DC; break;
        case 14: goto L_800657DC; break;
        case 15: goto L_800657DC; break;
        case 16: goto L_80065818; break;
        case 17: goto L_80065818; break;
        case 18: goto L_800657DC; break;
        case 19: goto L_800657DC; break;
        case 20: goto L_800657D4; break;
        case 21: goto L_80065818; break;
        case 22: goto L_80065818; break;
        case 23: goto L_80065818; break;
        case 24: goto L_800657D4; break;
        case 25: goto L_8006580C; break;
        case 26: goto L_80065818; break;
        case 27: goto L_80065818; break;
        case 28: goto L_80065818; break;
        case 29: goto L_80065818; break;
        case 30: goto L_800657DC; break;
        case 31: goto L_800657DC; break;
        case 32: goto L_80065818; break;
        case 33: goto L_800657DC; break;
        case 34: goto L_80065818; break;
        case 35: goto L_80065818; break;
        case 36: goto L_800657DC; break;
        case 37: goto L_800657DC; break;
        case 38: goto L_80065818; break;
        case 39: goto L_800657DC; break;
        case 40: goto L_800657DC; break;
        case 41: goto L_800657DC; break;
        case 42: goto L_800657DC; break;
        case 43: goto L_800657DC; break;
        case 44: goto L_800657DC; break;
        case 45: goto L_800657DC; break;
        case 46: goto L_800657DC; break;
        case 47: goto L_800657DC; break;
        case 48: goto L_800657DC; break;
        case 49: goto L_800657DC; break;
        case 50: goto L_80065800; break;
        case 51: goto L_800657F4; break;
        case 52: goto L_800657DC; break;
        case 53: goto L_800657DC; break;
        case 54: goto L_800657F4; break;
        case 55: goto L_800657DC; break;
        case 56: goto L_80065818; break;
        case 57: goto L_80065818; break;
        case 58: goto L_80065818; break;
        case 59: goto L_800657DC; break;
        case 60: goto L_800657DC; break;
        case 61: goto L_800657DC; break;
        case 62: goto L_800657DC; break;
        case 63: goto L_80065818; break;
        case 64: goto L_800657DC; break;
        case 65: goto L_800657DC; break;
        case 66: goto L_800657DC; break;
        case 67: goto L_800657DC; break;
        case 68: goto L_800657F4; break;
        case 69: goto L_80065818; break;
        case 70: goto L_800657DC; break;
        case 71: goto L_800657DC; break;
        case 72: goto L_800657DC; break;
        case 73: goto L_80065818; break;
        case 74: goto L_800657DC; break;
        case 75: goto L_800657F4; break;
        case 76: goto L_800657D4; break;
        case 77: goto L_800657DC; break;
        case 78: goto L_80065818; break;
        case 79: goto L_800657F4; break;
        case 80: goto L_800657DC; break;
        case 81: goto L_80065818; break;
        case 82: goto L_800657D4; break;
        default: switch_error(__func__, 0x800657CC, 0x8003BFF0);
    }
    // 0x800657D0: nop

L_800657D4:
    // 0x800657D4: jr          $ra
    // 0x800657D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800657D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800657DC:
    // 0x800657DC: lw          $v0, 0x88($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X88);
L_800657E0:
    // 0x800657E0: beq         $v0, $zero, L_800657EC
    if (ctx->r2 == 0) {
        // 0x800657E4: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_800657EC;
    }
    // 0x800657E4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800657E8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800657EC:
    // 0x800657EC: jr          $ra
    // 0x800657F0: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    return;
    // 0x800657F0: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_800657F4:
    // 0x800657F4: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x800657F8: j           L_800657E0
    // 0x800657FC: nop

        goto L_800657E0;
    // 0x800657FC: nop

L_80065800:
    // 0x80065800: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x80065804: j           L_800657E0
    // 0x80065808: nop

        goto L_800657E0;
    // 0x80065808: nop

L_8006580C:
    // 0x8006580C: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x80065810: j           L_800657E0
    // 0x80065814: nop

        goto L_800657E0;
    // 0x80065814: nop

L_80065818:
    // 0x80065818: jr          $ra
    // 0x8006581C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8006581C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80065820:
    // 0x80065820: jr          $ra
    // 0x80065824: nop

    return;
    // 0x80065824: nop

;}
RECOMP_FUNC void func_80065828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065828: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8006582C: addiu       $v1, $v0, -0xC
    ctx->r3 = ADD32(ctx->r2, -0XC);
    // 0x80065830: sltiu       $v0, $v1, 0x47
    ctx->r2 = ctx->r3 < 0X47 ? 1 : 0;
    // 0x80065834: beq         $v0, $zero, L_80065900
    if (ctx->r2 == 0) {
        // 0x80065838: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_80065900;
    }
    // 0x80065838: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8006583C: addiu       $v0, $v0, -0x3EC0
    ctx->r2 = ADD32(ctx->r2, -0X3EC0);
    // 0x80065840: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80065844: addu        $v1, $v1, $v0
    gpr jr_addend_8006584C = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80065848: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x8006584C: jr          $v0
    // 0x80065850: nop

    switch (jr_addend_8006584C >> 2) {
        case 0: goto L_80065854; break;
        case 1: goto L_80065854; break;
        case 2: goto L_80065854; break;
        case 3: goto L_80065854; break;
        case 4: goto L_80065900; break;
        case 5: goto L_80065900; break;
        case 6: goto L_80065854; break;
        case 7: goto L_80065854; break;
        case 8: goto L_80065854; break;
        case 9: goto L_80065900; break;
        case 10: goto L_80065900; break;
        case 11: goto L_80065900; break;
        case 12: goto L_80065900; break;
        case 13: goto L_800658AC; break;
        case 14: goto L_80065900; break;
        case 15: goto L_80065900; break;
        case 16: goto L_80065900; break;
        case 17: goto L_80065900; break;
        case 18: goto L_80065854; break;
        case 19: goto L_80065854; break;
        case 20: goto L_80065900; break;
        case 21: goto L_80065854; break;
        case 22: goto L_80065900; break;
        case 23: goto L_80065900; break;
        case 24: goto L_80065854; break;
        case 25: goto L_80065854; break;
        case 26: goto L_80065900; break;
        case 27: goto L_80065854; break;
        case 28: goto L_80065854; break;
        case 29: goto L_80065854; break;
        case 30: goto L_80065854; break;
        case 31: goto L_80065854; break;
        case 32: goto L_80065854; break;
        case 33: goto L_80065854; break;
        case 34: goto L_80065854; break;
        case 35: goto L_80065854; break;
        case 36: goto L_80065854; break;
        case 37: goto L_80065854; break;
        case 38: goto L_80065854; break;
        case 39: goto L_80065854; break;
        case 40: goto L_80065854; break;
        case 41: goto L_80065854; break;
        case 42: goto L_80065854; break;
        case 43: goto L_80065854; break;
        case 44: goto L_80065900; break;
        case 45: goto L_80065900; break;
        case 46: goto L_80065900; break;
        case 47: goto L_80065854; break;
        case 48: goto L_80065854; break;
        case 49: goto L_80065854; break;
        case 50: goto L_80065854; break;
        case 51: goto L_80065900; break;
        case 52: goto L_80065854; break;
        case 53: goto L_80065854; break;
        case 54: goto L_80065854; break;
        case 55: goto L_80065854; break;
        case 56: goto L_80065854; break;
        case 57: goto L_80065900; break;
        case 58: goto L_80065854; break;
        case 59: goto L_80065854; break;
        case 60: goto L_80065854; break;
        case 61: goto L_80065900; break;
        case 62: goto L_80065854; break;
        case 63: goto L_80065854; break;
        case 64: goto L_80065854; break;
        case 65: goto L_80065854; break;
        case 66: goto L_80065900; break;
        case 67: goto L_80065854; break;
        case 68: goto L_80065854; break;
        case 69: goto L_80065900; break;
        case 70: goto L_80065854; break;
        default: switch_error(__func__, 0x8006584C, 0x8003C140);
    }
    // 0x80065850: nop

L_80065854:
    // 0x80065854: lw          $v1, 0x60($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X60);
    // 0x80065858: beq         $v1, $zero, L_80065874
    if (ctx->r3 == 0) {
        // 0x8006585C: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80065874;
    }
    // 0x8006585C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80065860: addiu       $v0, $v0, -0x7760
    ctx->r2 = ADD32(ctx->r2, -0X7760);
    // 0x80065864: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80065868: lbu         $v0, -0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X1);
    // 0x8006586C: beq         $v0, $zero, L_800658CC
    if (ctx->r2 == 0) {
        // 0x80065870: nop
    
            goto L_800658CC;
    }
    // 0x80065870: nop

L_80065874:
    // 0x80065874: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80065878: beq         $v0, $zero, L_800658A4
    if (ctx->r2 == 0) {
        // 0x8006587C: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_800658A4;
    }
    // 0x8006587C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80065880: addiu       $v1, $v1, -0x7FA0
    ctx->r3 = ADD32(ctx->r3, -0X7FA0);
    // 0x80065884: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80065888: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8006588C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80065890: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80065894: lw          $a0, 0x68($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68);
    // 0x80065898: slt         $v1, $v1, $a0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_8006589C:
    // 0x8006589C: bne         $v1, $zero, L_80065904
    if (ctx->r3 != 0) {
        // 0x800658A0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80065904;
    }
    // 0x800658A0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800658A4:
    // 0x800658A4: jr          $ra
    // 0x800658A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800658A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800658AC:
    // 0x800658AC: lw          $v1, 0x34($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X34);
    // 0x800658B0: beq         $v1, $zero, L_800658D4
    if (ctx->r3 == 0) {
        // 0x800658B4: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800658D4;
    }
    // 0x800658B4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800658B8: addiu       $v0, $v0, -0x7760
    ctx->r2 = ADD32(ctx->r2, -0X7760);
    // 0x800658BC: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800658C0: lbu         $v0, -0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X1);
    // 0x800658C4: bne         $v0, $zero, L_800658D4
    if (ctx->r2 != 0) {
        // 0x800658C8: nop
    
            goto L_800658D4;
    }
    // 0x800658C8: nop

L_800658CC:
    // 0x800658CC: jr          $ra
    // 0x800658D0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800658D0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800658D4:
    // 0x800658D4: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x800658D8: beq         $v0, $zero, L_800658A4
    if (ctx->r2 == 0) {
        // 0x800658DC: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_800658A4;
    }
    // 0x800658DC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800658E0: addiu       $v1, $v1, -0x7FA0
    ctx->r3 = ADD32(ctx->r3, -0X7FA0);
    // 0x800658E4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800658E8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800658EC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800658F0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800658F4: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    // 0x800658F8: j           L_8006589C
    // 0x800658FC: slt         $v1, $v1, $a0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
        goto L_8006589C;
    // 0x800658FC: slt         $v1, $v1, $a0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_80065900:
    // 0x80065900: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80065904:
    // 0x80065904: jr          $ra
    // 0x80065908: nop

    return;
    // 0x80065908: nop

;}
RECOMP_FUNC void func_8006590C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006590C: jr          $ra
    // 0x80065910: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80065910: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void datItemSetObjectiveBooleanCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065914: lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10);
    // 0x80065918: beq         $a0, $zero, L_8006592C
    if (ctx->r4 == 0) {
        // 0x8006591C: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_8006592C;
    }
    // 0x8006591C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80065920: addiu       $v0, $v0, -0x7760
    ctx->r2 = ADD32(ctx->r2, -0X7760);
    // 0x80065924: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80065928: sb          $a1, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r5;
L_8006592C:
    // 0x8006592C: beq         $a2, $zero, L_80065950
    if (ctx->r6 == 0) {
        // 0x80065930: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80065950;
    }
    // 0x80065930: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80065934: addiu       $v0, $v0, -0x7FA0
    ctx->r2 = ADD32(ctx->r2, -0X7FA0);
    // 0x80065938: addiu       $v1, $a2, -0x1
    ctx->r3 = ADD32(ctx->r6, -0X1);
    // 0x8006593C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80065940: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80065944: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80065948: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8006594C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80065950:
    // 0x80065950: beq         $t0, $zero, L_80065978
    if (ctx->r8 == 0) {
        // 0x80065954: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80065978;
    }
    // 0x80065954: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80065958: addiu       $v0, $v0, -0x7FA0
    ctx->r2 = ADD32(ctx->r2, -0X7FA0);
    // 0x8006595C: addiu       $v1, $t0, -0x1
    ctx->r3 = ADD32(ctx->r8, -0X1);
    // 0x80065960: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80065964: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80065968: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8006596C: lw          $a0, 0x14($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X14);
    // 0x80065970: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80065974: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80065978:
    // 0x80065978: jr          $ra
    // 0x8006597C: nop

    return;
    // 0x8006597C: nop

;}
RECOMP_FUNC void func_80065980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065980: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x80065984: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // 0x80065988: beq         $v1, $v0, L_800659A0
    if (ctx->r3 == ctx->r2) {
        // 0x8006598C: addiu       $v0, $zero, 0x19
        ctx->r2 = ADD32(0, 0X19);
            goto L_800659A0;
    }
    // 0x8006598C: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    // 0x80065990: beq         $v1, $v0, L_800659FC
    if (ctx->r3 == ctx->r2) {
        // 0x80065994: addiu       $a2, $a0, 0x48
        ctx->r6 = ADD32(ctx->r4, 0X48);
            goto L_800659FC;
    }
    // 0x80065994: addiu       $a2, $a0, 0x48
    ctx->r6 = ADD32(ctx->r4, 0X48);
L_80065998:
    // 0x80065998: jr          $ra
    // 0x8006599C: nop

    return;
    // 0x8006599C: nop

L_800659A0:
    // 0x800659A0: lw          $v1, 0x28($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X28);
    // 0x800659A4: beq         $v1, $zero, L_800659C4
    if (ctx->r3 == 0) {
        // 0x800659A8: addiu       $a2, $a0, 0x38
        ctx->r6 = ADD32(ctx->r4, 0X38);
            goto L_800659C4;
    }
    // 0x800659A8: addiu       $a2, $a0, 0x38
    ctx->r6 = ADD32(ctx->r4, 0X38);
    // 0x800659AC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800659B0: addiu       $v0, $v0, -0x7760
    ctx->r2 = ADD32(ctx->r2, -0X7760);
    // 0x800659B4: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800659B8: lbu         $v0, -0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X1);
    // 0x800659BC: beq         $v0, $zero, L_80065A54
    if (ctx->r2 == 0) {
        // 0x800659C0: nop
    
            goto L_80065A54;
    }
    // 0x800659C0: nop

L_800659C4:
    // 0x800659C4: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x800659C8: beq         $v0, $zero, L_800659FC
    if (ctx->r2 == 0) {
        // 0x800659CC: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_800659FC;
    }
    // 0x800659CC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800659D0: addiu       $v1, $v1, -0x7FA0
    ctx->r3 = ADD32(ctx->r3, -0X7FA0);
    // 0x800659D4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800659D8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800659DC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800659E0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800659E4: lw          $v1, 0x30($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X30);
    // 0x800659E8: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800659EC: bne         $v0, $zero, L_80065998
    if (ctx->r2 != 0) {
        // 0x800659F0: andi        $v1, $a1, 0xFF
        ctx->r3 = ctx->r5 & 0XFF;
            goto L_80065998;
    }
    // 0x800659F0: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x800659F4: j           L_80065A04
    // 0x800659F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80065A04;
    // 0x800659F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800659FC:
    // 0x800659FC: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x80065A00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80065A04:
    // 0x80065A04: bnel        $v1, $v0, L_80065A0C
    if (ctx->r3 != ctx->r2) {
        // 0x80065A08: addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
            goto L_80065A0C;
    }
    goto skip_0;
    // 0x80065A08: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    skip_0:
L_80065A0C:
    // 0x80065A0C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80065A10: beq         $v1, $zero, L_80065A38
    if (ctx->r3 == 0) {
        // 0x80065A14: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80065A38;
    }
    // 0x80065A14: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80065A18: addiu       $v0, $v0, -0x7FA0
    ctx->r2 = ADD32(ctx->r2, -0X7FA0);
    // 0x80065A1C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80065A20: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80065A24: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80065A28: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80065A2C: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x80065A30: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80065A34: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80065A38:
    // 0x80065A38: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x80065A3C: beq         $a0, $zero, L_80065998
    if (ctx->r4 == 0) {
        // 0x80065A40: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80065998;
    }
    // 0x80065A40: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80065A44: addiu       $v0, $v0, -0x7760
    ctx->r2 = ADD32(ctx->r2, -0X7760);
    // 0x80065A48: lbu         $v1, 0xF($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0XF);
    // 0x80065A4C: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80065A50: sb          $v1, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r3;
L_80065A54:
    // 0x80065A54: jr          $ra
    // 0x80065A58: nop

    return;
    // 0x80065A58: nop

;}
RECOMP_FUNC void fake_func_80065A5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void buildPositionAndCallTransformHelper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065A60: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80065A64: sdc1        $f20, 0x98($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X98, ctx->r29);
    // 0x80065A68: lwc1        $f20, 0xC0($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80065A6C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80065A70: lwc1        $f0, -0x3DA0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3DA0);
    // 0x80065A74: sw          $s1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r17;
    // 0x80065A78: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80065A7C: sw          $s0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r16;
    // 0x80065A80: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80065A84: sw          $s2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r18;
    // 0x80065A88: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x80065A8C: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80065A90: sw          $s3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r19;
    // 0x80065A94: addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // 0x80065A98: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80065A9C: lwc1        $f2, -0x3D9C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3D9C);
    // 0x80065AA0: add.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80065AA4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80065AA8: lwc1        $f0, -0x3D98($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3D98);
    // 0x80065AAC: sub.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x80065AB0: sw          $ra, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r31;
    // 0x80065AB4: sdc1        $f22, 0xA0($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XA0, ctx->r29);
    // 0x80065AB8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80065ABC: lwc1        $f22, 0x4($s3)
    ctx->f22.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80065AC0: jal         0x80018F98
    // 0x80065AC4: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    func_80018F98(rdram, ctx);
        goto after_0;
    // 0x80065AC4: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x80065AC8: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80065ACC: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80065AD0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80065AD4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80065AD8: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80065ADC: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80065AE0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80065AE4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80065AE8: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80065AEC: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80065AF0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80065AF4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80065AF8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80065AFC: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x80065B00: jal         0x80018F98
    // 0x80065B04: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_80018F98(rdram, ctx);
        goto after_1;
    // 0x80065B04: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80065B08: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80065B0C: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80065B10: add.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80065B14: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80065B18: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80065B1C: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80065B20: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80065B24: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80065B28: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x80065B2C: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80065B30: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80065B34: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80065B38: sub.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80065B3C: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80065B40: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80065B44: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80065B48: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80065B4C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x80065B50: sub.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80065B54: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x80065B58: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x80065B5C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80065B60: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80065B64: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80065B68: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80065B6C: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x80065B70: sw          $v1, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r3;
    // 0x80065B74: sw          $t0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r8;
    // 0x80065B78: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80065B7C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80065B80: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80065B84: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80065B88: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80065B8C: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // 0x80065B90: jal         0x8001CF58
    // 0x80065B94: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    normalize_vector(rdram, ctx);
        goto after_2;
    // 0x80065B94: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    after_2:
    // 0x80065B98: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80065B9C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80065BA0: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80065BA4: nop

    // 0x80065BA8: bc1f        L_80065BEC
    if (!c1cs) {
        // 0x80065BAC: nop
    
            goto L_80065BEC;
    }
    // 0x80065BAC: nop

    // 0x80065BB0: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80065BB4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80065BB8: nop

    // 0x80065BBC: bc1f        L_80065BEC
    if (!c1cs) {
        // 0x80065BC0: nop
    
            goto L_80065BEC;
    }
    // 0x80065BC0: nop

    // 0x80065BC4: jal         0x8001C400
    // 0x80065BC8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    sinfApprox(rdram, ctx);
        goto after_3;
    // 0x80065BC8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_3:
    // 0x80065BCC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80065BD0: lwc1        $f2, -0x3D94($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3D94);
    // 0x80065BD4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80065BD8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80065BDC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80065BE0: lwc1        $f2, -0x3D90($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3D90);
    // 0x80065BE4: j           L_80065C38
    // 0x80065BE8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_80065C38;
    // 0x80065BE8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_80065BEC:
    // 0x80065BEC: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    // 0x80065BF0: nop

    // 0x80065BF4: bc1f        L_80065C40
    if (!c1cs) {
        // 0x80065BF8: nop
    
            goto L_80065C40;
    }
    // 0x80065BF8: nop

    // 0x80065BFC: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80065C00: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80065C04: nop

    // 0x80065C08: bc1f        L_80065C40
    if (!c1cs) {
        // 0x80065C0C: nop
    
            goto L_80065C40;
    }
    // 0x80065C0C: nop

    // 0x80065C10: jal         0x8001C400
    // 0x80065C14: nop

    sinfApprox(rdram, ctx);
        goto after_4;
    // 0x80065C14: nop

    after_4:
    // 0x80065C18: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80065C1C: lwc1        $f2, -0x3D8C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3D8C);
    // 0x80065C20: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80065C24: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80065C28: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80065C2C: lwc1        $f2, -0x3D88($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3D88);
    // 0x80065C30: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80065C34: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_80065C38:
    // 0x80065C38: j           L_80065CAC
    // 0x80065C3C: swc1        $f0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f0.u32l;
        goto L_80065CAC;
    // 0x80065C3C: swc1        $f0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f0.u32l;
L_80065C40:
    // 0x80065C40: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80065C44: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80065C48: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80065C4C: nop

    // 0x80065C50: bc1f        L_80065C90
    if (!c1cs) {
        // 0x80065C54: nop
    
            goto L_80065C90;
    }
    // 0x80065C54: nop

    // 0x80065C58: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80065C5C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80065C60: nop

    // 0x80065C64: bc1f        L_80065C90
    if (!c1cs) {
        // 0x80065C68: nop
    
            goto L_80065C90;
    }
    // 0x80065C68: nop

    // 0x80065C6C: jal         0x8001C400
    // 0x80065C70: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    sinfApprox(rdram, ctx);
        goto after_5;
    // 0x80065C70: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_5:
    // 0x80065C74: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80065C78: lwc1        $f2, -0x3D84($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3D84);
    // 0x80065C7C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80065C80: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80065C84: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80065C88: j           L_80065CAC
    // 0x80065C8C: swc1        $f0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f0.u32l;
        goto L_80065CAC;
    // 0x80065C8C: swc1        $f0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f0.u32l;
L_80065C90:
    // 0x80065C90: jal         0x8001C400
    // 0x80065C94: nop

    sinfApprox(rdram, ctx);
        goto after_6;
    // 0x80065C94: nop

    after_6:
    // 0x80065C98: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80065C9C: lwc1        $f2, -0x3D80($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3D80);
    // 0x80065CA0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80065CA4: abs.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = fabsf(ctx->f0.fl);
    // 0x80065CA8: swc1        $f8, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f8.u32l;
L_80065CAC:
    // 0x80065CAC: lwc1        $f0, 0x4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80065CB0: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
    // 0x80065CB4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80065CB8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80065CBC: jal         0x8001CD6C
    // 0x80065CC0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    buildRotationMatrixSlot1(rdram, ctx);
        goto after_7;
    // 0x80065CC0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
    // 0x80065CC4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80065CC8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80065CCC: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x80065CD0: jal         0x800193E8
    // 0x80065CD4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    transformVec3ByMat34(rdram, ctx);
        goto after_8;
    // 0x80065CD4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_8:
    // 0x80065CD8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80065CDC: jal         0x8001CF58
    // 0x80065CE0: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    normalize_vector(rdram, ctx);
        goto after_9;
    // 0x80065CE0: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    after_9:
    // 0x80065CE4: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80065CE8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80065CEC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80065CF0: nop

    // 0x80065CF4: bc1f        L_80065D38
    if (!c1cs) {
        // 0x80065CF8: nop
    
            goto L_80065D38;
    }
    // 0x80065CF8: nop

    // 0x80065CFC: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80065D00: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80065D04: nop

    // 0x80065D08: bc1f        L_80065D38
    if (!c1cs) {
        // 0x80065D0C: nop
    
            goto L_80065D38;
    }
    // 0x80065D0C: nop

    // 0x80065D10: jal         0x8001C400
    // 0x80065D14: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    sinfApprox(rdram, ctx);
        goto after_10;
    // 0x80065D14: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_10:
    // 0x80065D18: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80065D1C: lwc1        $f2, -0x3D7C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3D7C);
    // 0x80065D20: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80065D24: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80065D28: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80065D2C: lwc1        $f2, -0x3D78($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3D78);
    // 0x80065D30: j           L_80065E00
    // 0x80065D34: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_80065E00;
    // 0x80065D34: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_80065D38:
    // 0x80065D38: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80065D3C: nop

    // 0x80065D40: bc1f        L_80065D84
    if (!c1cs) {
        // 0x80065D44: nop
    
            goto L_80065D84;
    }
    // 0x80065D44: nop

    // 0x80065D48: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80065D4C: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80065D50: nop

    // 0x80065D54: bc1f        L_80065D84
    if (!c1cs) {
        // 0x80065D58: nop
    
            goto L_80065D84;
    }
    // 0x80065D58: nop

    // 0x80065D5C: jal         0x8001C400
    // 0x80065D60: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    sinfApprox(rdram, ctx);
        goto after_11;
    // 0x80065D60: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_11:
    // 0x80065D64: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80065D68: lwc1        $f2, -0x3D74($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3D74);
    // 0x80065D6C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80065D70: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80065D74: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80065D78: lwc1        $f2, -0x3D70($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3D70);
    // 0x80065D7C: j           L_80065DFC
    // 0x80065D80: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_80065DFC;
    // 0x80065D80: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_80065D84:
    // 0x80065D84: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80065D88: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80065D8C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80065D90: nop

    // 0x80065D94: bc1f        L_80065DD8
    if (!c1cs) {
        // 0x80065D98: nop
    
            goto L_80065DD8;
    }
    // 0x80065D98: nop

    // 0x80065D9C: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80065DA0: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    // 0x80065DA4: nop

    // 0x80065DA8: bc1f        L_80065DDC
    if (!c1cs) {
        // 0x80065DAC: nop
    
            goto L_80065DDC;
    }
    // 0x80065DAC: nop

    // 0x80065DB0: jal         0x8001C400
    // 0x80065DB4: nop

    sinfApprox(rdram, ctx);
        goto after_12;
    // 0x80065DB4: nop

    after_12:
    // 0x80065DB8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80065DBC: lwc1        $f2, -0x3D6C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3D6C);
    // 0x80065DC0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80065DC4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80065DC8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80065DCC: lwc1        $f2, -0x3D68($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3D68);
    // 0x80065DD0: j           L_80065DFC
    // 0x80065DD4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_80065DFC;
    // 0x80065DD4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_80065DD8:
    // 0x80065DD8: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
L_80065DDC:
    // 0x80065DDC: jal         0x8001C400
    // 0x80065DE0: nop

    sinfApprox(rdram, ctx);
        goto after_13;
    // 0x80065DE0: nop

    after_13:
    // 0x80065DE4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80065DE8: lwc1        $f2, -0x3D64($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3D64);
    // 0x80065DEC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80065DF0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80065DF4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80065DF8: lwc1        $f2, -0x3D60($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3D60);
L_80065DFC:
    // 0x80065DFC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_80065E00:
    // 0x80065E00: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
    // 0x80065E04: lwc1        $f0, 0x4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80065E08: sub.s       $f2, $f0, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80065E0C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80065E10: lwc1        $f0, -0x3D5C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3D5C);
    // 0x80065E14: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80065E18: nop

    // 0x80065E1C: bc1f        L_80065E30
    if (!c1cs) {
        // 0x80065E20: nop
    
            goto L_80065E30;
    }
    // 0x80065E20: nop

    // 0x80065E24: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80065E28: lwc1        $f0, -0x3D58($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3D58);
    // 0x80065E2C: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
L_80065E30:
    // 0x80065E30: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80065E34: lwc1        $f0, -0x3D54($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3D54);
    // 0x80065E38: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80065E3C: nop

    // 0x80065E40: bc1f        L_80065E54
    if (!c1cs) {
        // 0x80065E44: nop
    
            goto L_80065E54;
    }
    // 0x80065E44: nop

    // 0x80065E48: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80065E4C: lwc1        $f0, -0x3D50($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3D50);
    // 0x80065E50: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
L_80065E54:
    // 0x80065E54: lwc1        $f0, 0xB8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80065E58: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80065E5C: lwc1        $f2, 0x8($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80065E60: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80065E64: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80065E68: lwc1        $f0, -0x3D4C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3D4C);
    // 0x80065E6C: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80065E70: swc1        $f0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f0.u32l;
    // 0x80065E74: lw          $ra, 0x90($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X90);
    // 0x80065E78: lw          $s3, 0x8C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X8C);
    // 0x80065E7C: lw          $s2, 0x88($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X88);
    // 0x80065E80: lw          $s1, 0x84($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X84);
    // 0x80065E84: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
    // 0x80065E88: ldc1        $f22, 0xA0($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XA0);
    // 0x80065E8C: ldc1        $f20, 0x98($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X98);
    // 0x80065E90: jr          $ra
    // 0x80065E94: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80065E94: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_80065E98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065E98: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x80065E9C: sw          $s6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r22;
    // 0x80065EA0: addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // 0x80065EA4: addiu       $a0, $s6, 0x2C
    ctx->r4 = ADD32(ctx->r22, 0X2C);
    // 0x80065EA8: sw          $s5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r21;
    // 0x80065EAC: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x80065EB0: sw          $s7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r23;
    // 0x80065EB4: lbu         $s7, 0x103($sp)
    ctx->r23 = MEM_BU(ctx->r29, 0X103);
    // 0x80065EB8: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    // 0x80065EBC: sw          $s4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r20;
    // 0x80065EC0: sw          $ra, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r31;
    // 0x80065EC4: sw          $s3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r19;
    // 0x80065EC8: sw          $s2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r18;
    // 0x80065ECC: sw          $s1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r17;
    // 0x80065ED0: sw          $s0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r16;
    // 0x80065ED4: sdc1        $f24, 0xE8($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0XE8, ctx->r29);
    // 0x80065ED8: sdc1        $f22, 0xE0($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XE0, ctx->r29);
    // 0x80065EDC: sdc1        $f20, 0xD8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XD8, ctx->r29);
    // 0x80065EE0: jal         0x800191C4
    // 0x80065EE4: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    mat3x4Multiply(rdram, ctx);
        goto after_0;
    // 0x80065EE4: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    after_0:
    // 0x80065EE8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80065EEC: addiu       $s2, $sp, 0x10
    ctx->r18 = ADD32(ctx->r29, 0X10);
    // 0x80065EF0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80065EF4: addiu       $s3, $v0, -0x3B0
    ctx->r19 = ADD32(ctx->r2, -0X3B0);
    // 0x80065EF8: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80065EFC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80065F00: lwc1        $f20, -0x3D48($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X3D48);
    // 0x80065F04: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80065F08: lwc1        $f24, -0x3D44($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X3D44);
    // 0x80065F0C: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
L_80065F10:
    // 0x80065F10: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80065F14: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80065F18: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80065F1C: addu        $v0, $v1, $s3
    ctx->r2 = ADD32(ctx->r3, ctx->r19);
    // 0x80065F20: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80065F24: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80065F28: nop

    // 0x80065F2C: bc1f        L_80065F40
    if (!c1cs) {
        // 0x80065F30: addu        $v0, $s2, $v1
        ctx->r2 = ADD32(ctx->r18, ctx->r3);
            goto L_80065F40;
    }
    // 0x80065F30: addu        $v0, $s2, $v1
    ctx->r2 = ADD32(ctx->r18, ctx->r3);
    // 0x80065F34: lwc1        $f0, 0x0($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X0);
    // 0x80065F38: j           L_80065F48
    // 0x80065F3C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
        goto L_80065F48;
    // 0x80065F3C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_80065F40:
    // 0x80065F40: lwc1        $f0, 0x0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80065F44: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_80065F48:
    // 0x80065F48: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x80065F4C: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80065F50: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80065F54: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80065F58: addu        $v0, $v1, $s3
    ctx->r2 = ADD32(ctx->r3, ctx->r19);
    // 0x80065F5C: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80065F60: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80065F64: nop

    // 0x80065F68: bc1f        L_80065F7C
    if (!c1cs) {
        // 0x80065F6C: addu        $v0, $s2, $v1
        ctx->r2 = ADD32(ctx->r18, ctx->r3);
            goto L_80065F7C;
    }
    // 0x80065F6C: addu        $v0, $s2, $v1
    ctx->r2 = ADD32(ctx->r18, ctx->r3);
    // 0x80065F70: lwc1        $f0, 0x4($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X4);
    // 0x80065F74: j           L_80065F84
    // 0x80065F78: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
        goto L_80065F84;
    // 0x80065F78: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_80065F7C:
    // 0x80065F7C: lwc1        $f0, 0x4($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X4);
    // 0x80065F80: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_80065F84:
    // 0x80065F84: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x80065F88: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80065F8C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80065F90: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80065F94: addu        $v0, $v1, $s3
    ctx->r2 = ADD32(ctx->r3, ctx->r19);
    // 0x80065F98: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80065F9C: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80065FA0: nop

    // 0x80065FA4: bc1f        L_80065FB8
    if (!c1cs) {
        // 0x80065FA8: addu        $v0, $s2, $v1
        ctx->r2 = ADD32(ctx->r18, ctx->r3);
            goto L_80065FB8;
    }
    // 0x80065FA8: addu        $v0, $s2, $v1
    ctx->r2 = ADD32(ctx->r18, ctx->r3);
    // 0x80065FAC: lwc1        $f0, 0x8($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X8);
    // 0x80065FB0: j           L_80065FC0
    // 0x80065FB4: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
        goto L_80065FC0;
    // 0x80065FB4: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
L_80065FB8:
    // 0x80065FB8: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x80065FBC: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
L_80065FC0:
    // 0x80065FC0: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x80065FC4: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x80065FC8: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80065FCC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80065FD0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80065FD4: addu        $s0, $s2, $v1
    ctx->r16 = ADD32(ctx->r18, ctx->r3);
    // 0x80065FD8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80065FDC: jal         0x800193E8
    // 0x80065FE0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    transformVec3ByMat34(rdram, ctx);
        goto after_1;
    // 0x80065FE0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80065FE4: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // 0x80065FE8: bne         $v0, $zero, L_80066078
    if (ctx->r2 != 0) {
        // 0x80065FEC: andi        $v1, $s1, 0xFF
        ctx->r3 = ctx->r17 & 0XFF;
            goto L_80066078;
    }
    // 0x80065FEC: andi        $v1, $s1, 0xFF
    ctx->r3 = ctx->r17 & 0XFF;
    // 0x80065FF0: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80065FF4: c.eq.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl == ctx->f22.fl;
    // 0x80065FF8: nop

    // 0x80065FFC: bc1tl       L_80066204
    if (c1cs) {
        // 0x80066000: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80066204;
    }
    goto skip_0;
    // 0x80066000: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80066004: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80066008: div.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8006600C: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80066010: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x80066014: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80066018: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006601C: div.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80066020: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80066024: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x80066028: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006602C: div.s       $f0, $f20, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80066030: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80066034: swc1        $f2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f2.u32l;
    // 0x80066038: lwc1        $f0, 0x24($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X24);
    // 0x8006603C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80066040: nop

    // 0x80066044: bc1fl       L_8006607C
    if (!c1cs) {
        // 0x80066048: sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3 << 1);
            goto L_8006607C;
    }
    goto skip_1;
    // 0x80066048: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    skip_1:
    // 0x8006604C: abs.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = fabsf(ctx->f6.fl);
    // 0x80066050: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80066054: nop

    // 0x80066058: bc1f        L_8006607C
    if (!c1cs) {
        // 0x8006605C: sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3 << 1);
            goto L_8006607C;
    }
    // 0x8006605C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80066060: abs.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = fabsf(ctx->f4.fl);
    // 0x80066064: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80066068: nop

    // 0x8006606C: bc1t        L_80066204
    if (c1cs) {
        // 0x80066070: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80066204;
    }
    // 0x80066070: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80066074: andi        $v1, $s1, 0xFF
    ctx->r3 = ctx->r17 & 0XFF;
L_80066078:
    // 0x80066078: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
L_8006607C:
    // 0x8006607C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80066080: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80066084: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x80066088: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8006608C: mul.s       $f2, $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x80066090: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80066094: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x80066098: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006609C: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x800660A0: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x800660A4: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x800660A8: sltiu       $v0, $v0, 0x8
    ctx->r2 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x800660AC: bne         $v0, $zero, L_80065F10
    if (ctx->r2 != 0) {
        // 0x800660B0: andi        $v0, $s1, 0xFF
        ctx->r2 = ctx->r17 & 0XFF;
            goto L_80065F10;
    }
    // 0x800660B0: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x800660B4: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800660B8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800660BC: addiu       $t1, $v0, -0x350
    ctx->r9 = ADD32(ctx->r2, -0X350);
    // 0x800660C0: addiu       $t0, $sp, 0x10
    ctx->r8 = ADD32(ctx->r29, 0X10);
    // 0x800660C4: lwc1        $f6, 0x24($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X24);
    // 0x800660C8: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
L_800660CC:
    // 0x800660CC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800660D0: addu        $a3, $v0, $t1
    ctx->r7 = ADD32(ctx->r2, ctx->r9);
    // 0x800660D4: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x800660D8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800660DC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800660E0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800660E4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800660E8: addu        $a2, $t0, $v0
    ctx->r6 = ADD32(ctx->r8, ctx->r2);
    // 0x800660EC: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800660F0: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x800660F4: nop

    // 0x800660F8: bc1f        L_80066128
    if (!c1cs) {
        // 0x800660FC: addu        $a0, $a1, $zero
        ctx->r4 = ADD32(ctx->r5, 0);
            goto L_80066128;
    }
    // 0x800660FC: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x80066100: lbu         $v0, 0x1($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X1);
    // 0x80066104: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80066108: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8006610C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80066110: addu        $v1, $t0, $v1
    ctx->r3 = ADD32(ctx->r8, ctx->r3);
    // 0x80066114: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80066118: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8006611C: nop

    // 0x80066120: bc1tl       L_800661F0
    if (c1cs) {
        // 0x80066124: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800661F0;
    }
    goto skip_2;
    // 0x80066124: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
L_80066128:
    // 0x80066128: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8006612C: neg.s       $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = -ctx->f4.fl;
    // 0x80066130: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80066134: nop

    // 0x80066138: bc1tl       L_80066140
    if (c1cs) {
        // 0x8006613C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80066140;
    }
    goto skip_3;
    // 0x8006613C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_3:
L_80066140:
    // 0x80066140: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80066144: nop

    // 0x80066148: bc1tl       L_80066150
    if (c1cs) {
        // 0x8006614C: ori         $a0, $a0, 0x2
        ctx->r4 = ctx->r4 | 0X2;
            goto L_80066150;
    }
    goto skip_4;
    // 0x8006614C: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    skip_4:
L_80066150:
    // 0x80066150: lwc1        $f0, 0x4($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80066154: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80066158: nop

    // 0x8006615C: bc1tl       L_80066164
    if (c1cs) {
        // 0x80066160: ori         $a0, $a0, 0x4
        ctx->r4 = ctx->r4 | 0X4;
            goto L_80066164;
    }
    goto skip_5;
    // 0x80066160: ori         $a0, $a0, 0x4
    ctx->r4 = ctx->r4 | 0X4;
    skip_5:
L_80066164:
    // 0x80066164: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80066168: nop

    // 0x8006616C: bc1tl       L_80066174
    if (c1cs) {
        // 0x80066170: ori         $a0, $a0, 0x8
        ctx->r4 = ctx->r4 | 0X8;
            goto L_80066174;
    }
    goto skip_6;
    // 0x80066170: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    skip_6:
L_80066174:
    // 0x80066174: lbu         $v1, 0x1($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X1);
    // 0x80066178: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8006617C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80066180: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80066184: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x80066188: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8006618C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80066190: neg.s       $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = -ctx->f2.fl;
    // 0x80066194: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80066198: nop

    // 0x8006619C: bc1tl       L_800661A4
    if (c1cs) {
        // 0x800661A0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_800661A4;
    }
    goto skip_7;
    // 0x800661A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    skip_7:
L_800661A4:
    // 0x800661A4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800661A8: nop

    // 0x800661AC: bc1tl       L_800661B4
    if (c1cs) {
        // 0x800661B0: ori         $a1, $a1, 0x2
        ctx->r5 = ctx->r5 | 0X2;
            goto L_800661B4;
    }
    goto skip_8;
    // 0x800661B0: ori         $a1, $a1, 0x2
    ctx->r5 = ctx->r5 | 0X2;
    skip_8:
L_800661B4:
    // 0x800661B4: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800661B8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800661BC: nop

    // 0x800661C0: bc1tl       L_800661C8
    if (c1cs) {
        // 0x800661C4: ori         $a1, $a1, 0x4
        ctx->r5 = ctx->r5 | 0X4;
            goto L_800661C8;
    }
    goto skip_9;
    // 0x800661C4: ori         $a1, $a1, 0x4
    ctx->r5 = ctx->r5 | 0X4;
    skip_9:
L_800661C8:
    // 0x800661C8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800661CC: nop

    // 0x800661D0: bc1tl       L_800661D8
    if (c1cs) {
        // 0x800661D4: ori         $a1, $a1, 0x8
        ctx->r5 = ctx->r5 | 0X8;
            goto L_800661D8;
    }
    goto skip_10;
    // 0x800661D4: ori         $a1, $a1, 0x8
    ctx->r5 = ctx->r5 | 0X8;
    skip_10:
L_800661D8:
    // 0x800661D8: and         $v0, $a0, $a1
    ctx->r2 = ctx->r4 & ctx->r5;
    // 0x800661DC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800661E0: bne         $v0, $zero, L_800661F0
    if (ctx->r2 != 0) {
        // 0x800661E4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800661F0;
    }
    // 0x800661E4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800661E8: j           L_80066204
    // 0x800661EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80066204;
    // 0x800661EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800661F0:
    // 0x800661F0: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x800661F4: sltiu       $v0, $v0, 0xC
    ctx->r2 = ctx->r2 < 0XC ? 1 : 0;
    // 0x800661F8: bne         $v0, $zero, L_800660CC
    if (ctx->r2 != 0) {
        // 0x800661FC: andi        $v0, $s1, 0xFF
        ctx->r2 = ctx->r17 & 0XFF;
            goto L_800660CC;
    }
    // 0x800661FC: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x80066200: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80066204:
    // 0x80066204: lw          $ra, 0xD0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XD0);
    // 0x80066208: lw          $s7, 0xCC($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XCC);
    // 0x8006620C: lw          $s6, 0xC8($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XC8);
    // 0x80066210: lw          $s5, 0xC4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XC4);
    // 0x80066214: lw          $s4, 0xC0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XC0);
    // 0x80066218: lw          $s3, 0xBC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XBC);
    // 0x8006621C: lw          $s2, 0xB8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XB8);
    // 0x80066220: lw          $s1, 0xB4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XB4);
    // 0x80066224: lw          $s0, 0xB0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XB0);
    // 0x80066228: ldc1        $f24, 0xE8($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0XE8);
    // 0x8006622C: ldc1        $f22, 0xE0($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XE0);
    // 0x80066230: ldc1        $f20, 0xD8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XD8);
    // 0x80066234: jr          $ra
    // 0x80066238: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x80066238: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void func_8006623C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006623C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80066240: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80066244: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80066248: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8006624C: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x80066250: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80066254: jal         0x80018F98
    // 0x80066258: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80018F98(rdram, ctx);
        goto after_0;
    // 0x80066258: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x8006625C: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80066260: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80066264: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80066268: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8006626C: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80066270: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80066274: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80066278: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x8006627C: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80066280: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80066284: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80066288: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x8006628C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80066290: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80066294: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80066298: jr          $ra
    // 0x8006629C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006629C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void setupActorAnchorTransformType1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800662A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800662A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800662A8: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // 0x800662AC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800662B0: lwc1        $f0, -0x3D40($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3D40);
    // 0x800662B4: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800662B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800662BC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800662C0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800662C4: jal         0x80065A60
    // 0x800662C8: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    buildPositionAndCallTransformHelper(rdram, ctx);
        goto after_0;
    // 0x800662C8: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x800662CC: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x800662D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800662D4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800662D8: jr          $ra
    // 0x800662DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800662DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void quadraticEaseInOut(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800662E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800662E4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800662E8: nop

    // 0x800662EC: bc1tl       L_8006630C
    if (c1cs) {
        // 0x800662F0: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_8006630C;
    }
    goto skip_0;
    // 0x800662F0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    skip_0:
    // 0x800662F4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800662F8: lwc1        $f0, -0x3D3C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3D3C);
    // 0x800662FC: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80066300: nop

    // 0x80066304: bc1tl       L_8006630C
    if (c1cs) {
        // 0x80066308: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_8006630C;
    }
    goto skip_1;
    // 0x80066308: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    skip_1:
L_8006630C:
    // 0x8006630C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80066310: lwc1        $f0, -0x3D38($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3D38);
    // 0x80066314: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x80066318: nop

    // 0x8006631C: bc1f        L_80066334
    if (!c1cs) {
        // 0x80066320: nop
    
            goto L_80066334;
    }
    // 0x80066320: nop

    // 0x80066324: add.s       $f0, $f12, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x80066328: mul.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8006632C: jr          $ra
    // 0x80066330: nop

    return;
    // 0x80066330: nop

L_80066334:
    // 0x80066334: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80066338: lwc1        $f0, -0x3D34($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3D34);
    // 0x8006633C: sub.s       $f2, $f0, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80066340: add.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x80066344: mul.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80066348: jr          $ra
    // 0x8006634C: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    return;
    // 0x8006634C: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
;}
RECOMP_FUNC void func_80066350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066350: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x80066354: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80066358: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8006635C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80066360: lwc1        $f4, -0x3D30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3D30);
    // 0x80066364: sub.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80066368: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8006636C: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80066370: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80066374: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
    // 0x80066378: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8006637C: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80066380: lwc1        $f0, 0x4($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80066384: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80066388: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8006638C: swc1        $f2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f2.u32l;
    // 0x80066390: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80066394: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80066398: lwc1        $f0, 0x8($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8006639C: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800663A0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800663A4: jr          $ra
    // 0x800663A8: swc1        $f2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x800663A8: swc1        $f2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f2.u32l;
;}
RECOMP_FUNC void fake_func_800663AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void loadSndFiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800663B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800663B4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800663B8: addiu       $v1, $zero, 0xF
    ctx->r3 = ADD32(0, 0XF);
    // 0x800663BC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800663C0: addiu       $v0, $v0, -0x6600
    ctx->r2 = ADD32(ctx->r2, -0X6600);
    // 0x800663C4: addiu       $v0, $v0, 0x78
    ctx->r2 = ADD32(ctx->r2, 0X78);
    // 0x800663C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800663CC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800663D0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800663D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
L_800663D8:
    // 0x800663D8: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800663DC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800663E0: bgez        $v1, L_800663D8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800663E4: addiu       $v0, $v0, -0x8
        ctx->r2 = ADD32(ctx->r2, -0X8);
            goto L_800663D8;
    }
    // 0x800663E4: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // 0x800663E8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800663EC: addiu       $a0, $a0, -0x38D4
    ctx->r4 = ADD32(ctx->r4, -0X38D4);
    // 0x800663F0: jal         0x800647E0
    // 0x800663F4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    load_asset_with_malloc_flags(rdram, ctx);
        goto after_0;
    // 0x800663F4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x800663F8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800663FC: addiu       $a0, $a0, -0x38C4
    ctx->r4 = ADD32(ctx->r4, -0X38C4);
    // 0x80066400: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80066404: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x80066408: jal         0x800647E0
    // 0x8006640C: sw          $v0, -0x64AC($s2)
    MEM_W(-0X64AC, ctx->r18) = ctx->r2;
    load_asset_with_malloc_flags(rdram, ctx);
        goto after_1;
    // 0x8006640C: sw          $v0, -0x64AC($s2)
    MEM_W(-0X64AC, ctx->r18) = ctx->r2;
    after_1:
    // 0x80066410: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80066414: addiu       $a0, $a0, -0x38B4
    ctx->r4 = ADD32(ctx->r4, -0X38B4);
    // 0x80066418: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006641C: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80066420: jal         0x800647E0
    // 0x80066424: sw          $v0, -0x64B0($s1)
    MEM_W(-0X64B0, ctx->r17) = ctx->r2;
    load_asset_with_malloc_flags(rdram, ctx);
        goto after_2;
    // 0x80066424: sw          $v0, -0x64B0($s1)
    MEM_W(-0X64B0, ctx->r17) = ctx->r2;
    after_2:
    // 0x80066428: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006642C: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80066430: addiu       $a3, $a3, -0x38A4
    ctx->r7 = ADD32(ctx->r7, -0X38A4);
    // 0x80066434: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80066438: lw          $a0, -0x76E0($v1)
    ctx->r4 = MEM_W(ctx->r3, -0X76E0);
    // 0x8006643C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80066440: lw          $a2, 0x7CFC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X7CFC);
    // 0x80066444: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80066448: sw          $v0, -0x64B4($s0)
    MEM_W(-0X64B4, ctx->r16) = ctx->r2;
    // 0x8006644C: jal         0x80004AAC
    // 0x80066450: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    findAssetAcrossSegments(rdram, ctx);
        goto after_3;
    // 0x80066450: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x80066454: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x80066458: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8006645C: lw          $a0, -0x64AC($s2)
    ctx->r4 = MEM_W(ctx->r18, -0X64AC);
    // 0x80066460: lw          $a3, -0x64B4($s0)
    ctx->r7 = MEM_W(ctx->r16, -0X64B4);
    // 0x80066464: lw          $v1, -0x64B0($s1)
    ctx->r3 = MEM_W(ctx->r17, -0X64B0);
    // 0x80066468: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8006646C: sw          $a2, -0x330($v0)
    MEM_W(-0X330, ctx->r2) = ctx->r6;
    // 0x80066470: jal         0x80097518
    // 0x80066474: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    parseSndFiles(rdram, ctx);
        goto after_4;
    // 0x80066474: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_4:
    // 0x80066478: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8006647C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80066480: jal         0x8008E0B0
    // 0x80066484: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    playSimpleAudioCmd(rdram, ctx);
        goto after_5;
    // 0x80066484: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    after_5:
    // 0x80066488: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8006648C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80066490: jal         0x8008E0B0
    // 0x80066494: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    playSimpleAudioCmd(rdram, ctx);
        goto after_6;
    // 0x80066494: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    after_6:
    // 0x80066498: jal         0x8006E468
    // 0x8006649C: nop

    applyVolumeSettingsToMixer(rdram, ctx);
        goto after_7;
    // 0x8006649C: nop

    after_7:
    // 0x800664A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800664A4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800664A8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800664AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800664B0: jr          $ra
    // 0x800664B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800664B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800664B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800664B8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800664BC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800664C0: lw          $v0, -0x72E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X72E4);
    // 0x800664C4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800664C8: lwc1        $f4, -0x3894($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3894);
    // 0x800664CC: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800664D0: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800664D4: lwc1        $f0, 0x4C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x800664D8: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800664DC: swc1        $f0, -0x64A8($a1)
    MEM_W(-0X64A8, ctx->r5) = ctx->f0.u32l;
    // 0x800664E0: lwc1        $f0, 0x50($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X50);
    // 0x800664E4: addiu       $a1, $a1, -0x64A8
    ctx->r5 = ADD32(ctx->r5, -0X64A8);
    // 0x800664E8: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x800664EC: lwc1        $f0, 0x54($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X54);
    // 0x800664F0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800664F4: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x800664F8: lwc1        $f0, 0x30($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800664FC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80066500: swc1        $f0, -0x64D0($a2)
    MEM_W(-0X64D0, ctx->r6) = ctx->f0.u32l;
    // 0x80066504: lwc1        $f0, 0x3C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x80066508: addiu       $a2, $a2, -0x64D0
    ctx->r6 = ADD32(ctx->r6, -0X64D0);
    // 0x8006650C: swc1        $f0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f0.u32l;
    // 0x80066510: lwc1        $f0, 0x48($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80066514: addiu       $a0, $a0, -0x6580
    ctx->r4 = ADD32(ctx->r4, -0X6580);
    // 0x80066518: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
    // 0x8006651C: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80066520: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x80066524: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80066528: swc1        $f0, -0x64C0($v1)
    MEM_W(-0X64C0, ctx->r3) = ctx->f0.u32l;
    // 0x8006652C: lwc1        $f0, 0x38($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80066530: addiu       $v1, $v1, -0x64C0
    ctx->r3 = ADD32(ctx->r3, -0X64C0);
    // 0x80066534: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80066538: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x8006653C: lwc1        $f2, 0x44($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80066540: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80066544: lwc1        $f0, -0x3890($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3890);
    // 0x80066548: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x8006654C: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x80066550: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80066554: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80066558: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8006655C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80066560: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80066564: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80066568: jal         0x8009912C
    // 0x8006656C: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
    func_8009912C(rdram, ctx);
        goto after_0;
    // 0x8006656C: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
    after_0:
    // 0x80066570: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x80066574: jr          $ra
    // 0x80066578: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80066578: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void loadSongAssetByName(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006657C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80066580: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80066584: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80066588: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8006658C: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x80066590: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80066594: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066598: addiu       $v1, $v0, -0x6600
    ctx->r3 = ADD32(ctx->r2, -0X6600);
    // 0x8006659C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800665A0: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800665A4: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800665A8: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
L_800665AC:
    // 0x800665AC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800665B0: bnel        $v0, $s4, L_800665C0
    if (ctx->r2 != ctx->r20) {
        // 0x800665B4: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800665C0;
    }
    goto skip_0;
    // 0x800665B4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_0:
    // 0x800665B8: j           L_800666BC
    // 0x800665BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800666BC;
    // 0x800665BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800665C0:
    // 0x800665C0: slti        $v0, $a2, 0x10
    ctx->r2 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x800665C4: bne         $v0, $zero, L_800665AC
    if (ctx->r2 != 0) {
        // 0x800665C8: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_800665AC;
    }
    // 0x800665C8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800665CC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800665D0: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x800665D4: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x800665D8: addiu       $t1, $t0, -0x32C
    ctx->r9 = ADD32(ctx->r8, -0X32C);
    // 0x800665DC: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800665E0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800665E4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800665E8: addiu       $a0, $v0, -0x6600
    ctx->r4 = ADD32(ctx->r2, -0X6600);
L_800665EC:
    // 0x800665EC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800665F0: bnel        $v0, $a3, L_800666AC
    if (ctx->r2 != ctx->r7) {
        // 0x800665F4: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800666AC;
    }
    goto skip_1;
    // 0x800665F4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_1:
    // 0x800665F8: lw          $v0, -0x32C($t0)
    ctx->r2 = MEM_W(ctx->r8, -0X32C);
    // 0x800665FC: beql        $v0, $a3, L_800666AC
    if (ctx->r2 == ctx->r7) {
        // 0x80066600: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800666AC;
    }
    goto skip_2;
    // 0x80066600: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_2:
    // 0x80066604: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80066608: addu        $v1, $t1, $zero
    ctx->r3 = ADD32(ctx->r9, 0);
L_8006660C:
    // 0x8006660C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80066610: bnel        $v0, $s4, L_8006669C
    if (ctx->r2 != ctx->r20) {
        // 0x80066614: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_8006669C;
    }
    goto skip_3;
    // 0x80066614: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    skip_3:
    // 0x80066618: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8006661C: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x80066620: jal         0x80033CC4
    // 0x80066624: addiu       $a1, $a1, -0x388C
    ctx->r5 = ADD32(ctx->r5, -0X388C);
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x80066624: addiu       $a1, $a1, -0x388C
    ctx->r5 = ADD32(ctx->r5, -0X388C);
    after_0:
    // 0x80066628: lw          $a0, 0x7CFC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X7CFC);
    // 0x8006662C: jal         0x80004D5C
    // 0x80066630: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    get_asset_size_extra(rdram, ctx);
        goto after_1;
    // 0x80066630: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x80066634: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80066638: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8006663C: jal         0x80001ACC
    // 0x80066640: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_2;
    // 0x80066640: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
    // 0x80066644: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80066648: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006664C: lw          $a2, 0x7CFC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X7CFC);
    // 0x80066650: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x80066654: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    // 0x80066658: jal         0x80004AAC
    // 0x8006665C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    findAssetAcrossSegments(rdram, ctx);
        goto after_3;
    // 0x8006665C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x80066660: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80066664: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80066668: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8006666C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80066670: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80066674: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x80066678: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8006667C: jal         0x80004E70
    // 0x80066680: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    setupAssetDma(rdram, ctx);
        goto after_4;
    // 0x80066680: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_4:
    // 0x80066684: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80066688: jal         0x80004C70
    // 0x8006668C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    teardownAssetDma(rdram, ctx);
        goto after_5;
    // 0x8006668C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_5:
    // 0x80066690: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80066694: j           L_800666BC
    // 0x80066698: sw          $s4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r20;
        goto L_800666BC;
    // 0x80066698: sw          $s4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r20;
L_8006669C:
    // 0x8006669C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800666A0: bne         $v0, $a3, L_8006660C
    if (ctx->r2 != ctx->r7) {
        // 0x800666A4: nop
    
            goto L_8006660C;
    }
    // 0x800666A4: nop

    // 0x800666A8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800666AC:
    // 0x800666AC: slti        $v0, $a2, 0x10
    ctx->r2 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x800666B0: bne         $v0, $zero, L_800665EC
    if (ctx->r2 != 0) {
        // 0x800666B4: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_800665EC;
    }
    // 0x800666B4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800666B8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800666BC:
    // 0x800666BC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x800666C0: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800666C4: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800666C8: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800666CC: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800666D0: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800666D4: jr          $ra
    // 0x800666D8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800666D8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void updateAudioListenerVelocity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800666DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800666E0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800666E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800666E8: lw          $s0, -0x72E4($v0)
    ctx->r16 = MEM_W(ctx->r2, -0X72E4);
    // 0x800666EC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800666F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800666F4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800666F8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800666FC: lwc1        $f2, 0x4C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80066700: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066704: swc1        $f2, -0x64A8($v0)
    MEM_W(-0X64A8, ctx->r2) = ctx->f2.u32l;
    // 0x80066708: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8006670C: addiu       $v0, $v0, -0x64A8
    ctx->r2 = ADD32(ctx->r2, -0X64A8);
    // 0x80066710: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80066714: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80066718: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8006671C: nop

    // 0x80066720: bc1f        L_8006676C
    if (!c1cs) {
        // 0x80066724: swc1        $f4, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
            goto L_8006676C;
    }
    // 0x80066724: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80066728: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006672C: lwc1        $f0, -0x64F0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X64F0);
    // 0x80066730: addiu       $v0, $v0, -0x64F0
    ctx->r2 = ADD32(ctx->r2, -0X64F0);
    // 0x80066734: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80066738: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8006673C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80066740: sub.s       $f2, $f6, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80066744: div.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80066748: swc1        $f0, -0x64E0($v1)
    MEM_W(-0X64E0, ctx->r3) = ctx->f0.u32l;
    // 0x8006674C: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80066750: addiu       $v1, $v1, -0x64E0
    ctx->r3 = ADD32(ctx->r3, -0X64E0);
    // 0x80066754: sub.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80066758: div.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8006675C: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    // 0x80066760: div.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80066764: j           L_80066780
    // 0x80066768: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
        goto L_80066780;
    // 0x80066768: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
L_8006676C:
    // 0x8006676C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80066770: addiu       $v0, $v1, -0x64E0
    ctx->r2 = ADD32(ctx->r3, -0X64E0);
    // 0x80066774: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80066778: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8006677C: swc1        $f0, -0x64E0($v1)
    MEM_W(-0X64E0, ctx->r3) = ctx->f0.u32l;
L_80066780:
    // 0x80066780: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80066784: addiu       $s2, $s1, -0x64E0
    ctx->r18 = ADD32(ctx->r17, -0X64E0);
    // 0x80066788: jal         0x8001CF2C
    // 0x8006678C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    vec3Length(rdram, ctx);
        goto after_0;
    // 0x8006678C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_0:
    // 0x80066790: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80066794: lwc1        $f2, -0x387C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X387C);
    // 0x80066798: mov.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
    // 0x8006679C: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x800667A0: nop

    // 0x800667A4: bc1f        L_800667E8
    if (!c1cs) {
        // 0x800667A8: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800667E8;
    }
    // 0x800667A8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800667AC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800667B0: lwc1        $f0, -0x3878($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3878);
    // 0x800667B4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800667B8: lwc1        $f2, -0x3874($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3874);
    // 0x800667BC: lwc1        $f6, -0x64E0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, -0X64E0);
    // 0x800667C0: div.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800667C4: div.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800667C8: mul.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800667CC: lwc1        $f4, 0x4($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X4);
    // 0x800667D0: mul.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800667D4: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800667D8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800667DC: swc1        $f6, -0x64E0($s1)
    MEM_W(-0X64E0, ctx->r17) = ctx->f6.u32l;
    // 0x800667E0: swc1        $f4, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f4.u32l;
    // 0x800667E4: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
L_800667E8:
    // 0x800667E8: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800667EC: lui         $a3, 0x8014
    ctx->r7 = S32(0X8014 << 16);
    // 0x800667F0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800667F4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800667F8: addiu       $t3, $a1, -0x64A8
    ctx->r11 = ADD32(ctx->r5, -0X64A8);
    // 0x800667FC: addiu       $t2, $v0, -0x64F0
    ctx->r10 = ADD32(ctx->r2, -0X64F0);
    // 0x80066800: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x80066804: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x80066808: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x8006680C: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x80066810: lw          $t0, 0x8($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X8);
    // 0x80066814: sw          $t0, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r8;
    // 0x80066818: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8006681C: addiu       $a0, $a0, -0x6580
    ctx->r4 = ADD32(ctx->r4, -0X6580);
    // 0x80066820: swc1        $f0, -0x64D0($a3)
    MEM_W(-0X64D0, ctx->r7) = ctx->f0.u32l;
    // 0x80066824: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80066828: addiu       $a3, $a3, -0x64D0
    ctx->r7 = ADD32(ctx->r7, -0X64D0);
    // 0x8006682C: swc1        $f0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f0.u32l;
    // 0x80066830: lwc1        $f0, 0x48($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80066834: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x80066838: swc1        $f0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f0.u32l;
    // 0x8006683C: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80066840: addiu       $a1, $a1, -0x64A8
    ctx->r5 = ADD32(ctx->r5, -0X64A8);
    // 0x80066844: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80066848: swc1        $f0, -0x64C0($v1)
    MEM_W(-0X64C0, ctx->r3) = ctx->f0.u32l;
    // 0x8006684C: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80066850: addiu       $v1, $v1, -0x64C0
    ctx->r3 = ADD32(ctx->r3, -0X64C0);
    // 0x80066854: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80066858: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x8006685C: lwc1        $f0, 0x44($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80066860: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x80066864: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x80066868: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8006686C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80066870: jal         0x80098FA8
    // 0x80066874: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    setMusyX3DProperties(rdram, ctx);
        goto after_1;
    // 0x80066874: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    after_1:
    // 0x80066878: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006687C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80066880: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80066884: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80066888: jr          $ra
    // 0x8006688C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006688C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80066890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066890: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066894: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80066898: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8006689C: jal         0x80099310
    // 0x800668A0: addiu       $a0, $a0, -0x6580
    ctx->r4 = ADD32(ctx->r4, -0X6580);
    unlinkMusyXListNode(rdram, ctx);
        goto after_0;
    // 0x800668A0: addiu       $a0, $a0, -0x6580
    ctx->r4 = ADD32(ctx->r4, -0X6580);
    after_0:
    // 0x800668A4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800668A8: jr          $ra
    // 0x800668AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800668AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void waitForAnyAudioSlot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800668B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800668B4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800668B8: jal         0x8008DA00
    // 0x800668BC: nop

    tickMusyXIfActive(rdram, ctx);
        goto after_0;
    // 0x800668BC: nop

    after_0:
    // 0x800668C0: jal         0x8008E57C
    // 0x800668C4: nop

    anyAudioSlotActive(rdram, ctx);
        goto after_1;
    // 0x800668C4: nop

    after_1:
    // 0x800668C8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800668CC: nop

    // 0x800668D0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800668D4: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x800668D8: bne         $v0, $zero, L_8006690C
    if (ctx->r2 != 0) {
        // 0x800668DC: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_8006690C;
    }
    // 0x800668DC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800668E0: lw          $a0, -0x64AC($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X64AC);
    // 0x800668E4: jal         0x80001C98
    // 0x800668E8: nop

    rs_free(rdram, ctx);
        goto after_2;
    // 0x800668E8: nop

    after_2:
    // 0x800668EC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800668F0: lw          $a0, -0x64B0($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X64B0);
    // 0x800668F4: jal         0x80001C98
    // 0x800668F8: nop

    rs_free(rdram, ctx);
        goto after_3;
    // 0x800668F8: nop

    after_3:
    // 0x800668FC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066900: lw          $a0, -0x64B4($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X64B4);
    // 0x80066904: jal         0x80001C98
    // 0x80066908: nop

    rs_free(rdram, ctx);
        goto after_4;
    // 0x80066908: nop

    after_4:
L_8006690C:
    // 0x8006690C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80066910: jr          $ra
    // 0x80066914: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80066914: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void parseLoadedSndSection(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066918: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006691C: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80066920: andi        $a1, $a0, 0xFFFF
    ctx->r5 = ctx->r4 & 0XFFFF;
    // 0x80066924: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80066928: lw          $v0, -0x64B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X64B0);
    // 0x8006692C: lw          $a0, -0x64AC($a2)
    ctx->r4 = MEM_W(ctx->r6, -0X64AC);
    // 0x80066930: lw          $a3, -0x64B4($v1)
    ctx->r7 = MEM_W(ctx->r3, -0X64B4);
    // 0x80066934: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80066938: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8006693C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80066940: lw          $a2, -0x330($v0)
    ctx->r6 = MEM_W(ctx->r2, -0X330);
    // 0x80066944: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80066948: jal         0x80097518
    // 0x8006694C: nop

    parseSndFiles(rdram, ctx);
        goto after_0;
    // 0x8006694C: nop

    after_0:
    // 0x80066950: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80066954: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80066958: jr          $ra
    // 0x8006695C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006695C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void freeAudioCacheEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066960: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80066964: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80066968: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8006696C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80066970: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80066974: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80066978: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8006697C: bne         $s2, $v0, L_800669C4
    if (ctx->r18 != ctx->r2) {
        // 0x80066980: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_800669C4;
    }
    // 0x80066980: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80066984: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80066988: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8006698C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066990: addiu       $s0, $v0, -0x6600
    ctx->r16 = ADD32(ctx->r2, -0X6600);
L_80066994:
    // 0x80066994: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80066998: beq         $v0, $s2, L_800669B0
    if (ctx->r2 == ctx->r18) {
        // 0x8006699C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800669B0;
    }
    // 0x8006699C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800669A0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800669A4: jal         0x80001C98
    // 0x800669A8: nop

    rs_free(rdram, ctx);
        goto after_0;
    // 0x800669A8: nop

    after_0:
    // 0x800669AC: sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
L_800669B0:
    // 0x800669B0: slti        $v0, $s1, 0x10
    ctx->r2 = SIGNED(ctx->r17) < 0X10 ? 1 : 0;
    // 0x800669B4: bne         $v0, $zero, L_80066994
    if (ctx->r2 != 0) {
        // 0x800669B8: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_80066994;
    }
    // 0x800669B8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800669BC: j           L_800669FC
    // 0x800669C0: nop

        goto L_800669FC;
    // 0x800669C0: nop

L_800669C4:
    // 0x800669C4: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800669C8: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x800669CC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800669D0: addiu       $s0, $v0, -0x6600
    ctx->r16 = ADD32(ctx->r2, -0X6600);
L_800669D4:
    // 0x800669D4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800669D8: bne         $v0, $s2, L_800669F0
    if (ctx->r2 != ctx->r18) {
        // 0x800669DC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800669F0;
    }
    // 0x800669DC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800669E0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800669E4: jal         0x80001C98
    // 0x800669E8: nop

    rs_free(rdram, ctx);
        goto after_1;
    // 0x800669E8: nop

    after_1:
    // 0x800669EC: sw          $s3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r19;
L_800669F0:
    // 0x800669F0: slti        $v0, $s1, 0x10
    ctx->r2 = SIGNED(ctx->r17) < 0X10 ? 1 : 0;
    // 0x800669F4: bne         $v0, $zero, L_800669D4
    if (ctx->r2 != 0) {
        // 0x800669F8: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_800669D4;
    }
    // 0x800669F8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800669FC:
    // 0x800669FC: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80066A00: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80066A04: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80066A08: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80066A0C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80066A10: jr          $ra
    // 0x80066A14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80066A14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void findAudioChannelById(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066A18: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80066A1C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066A20: addiu       $v1, $v0, -0x6600
    ctx->r3 = ADD32(ctx->r2, -0X6600);
L_80066A24:
    // 0x80066A24: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80066A28: bne         $v0, $a0, L_80066A3C
    if (ctx->r2 != ctx->r4) {
        // 0x80066A2C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80066A3C;
    }
    // 0x80066A2C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80066A30: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80066A34: jr          $ra
    // 0x80066A38: nop

    return;
    // 0x80066A38: nop

L_80066A3C:
    // 0x80066A3C: slti        $v0, $a1, 0x10
    ctx->r2 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x80066A40: bne         $v0, $zero, L_80066A24
    if (ctx->r2 != 0) {
        // 0x80066A44: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_80066A24;
    }
    // 0x80066A44: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80066A48: jr          $ra
    // 0x80066A4C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80066A4C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void updateAudioListenerPosFromPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066A50: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066A54: lw          $a0, -0x72E4($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X72E4);
    // 0x80066A58: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80066A5C: lwc1        $f0, 0x4C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x80066A60: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066A64: swc1        $f0, -0x64F0($v1)
    MEM_W(-0X64F0, ctx->r3) = ctx->f0.u32l;
    // 0x80066A68: addiu       $v1, $v1, -0x64F0
    ctx->r3 = ADD32(ctx->r3, -0X64F0);
    // 0x80066A6C: swc1        $f0, -0x64A8($v0)
    MEM_W(-0X64A8, ctx->r2) = ctx->f0.u32l;
    // 0x80066A70: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80066A74: addiu       $v0, $v0, -0x64A8
    ctx->r2 = ADD32(ctx->r2, -0X64A8);
    // 0x80066A78: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x80066A7C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80066A80: lwc1        $f0, 0x54($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X54);
    // 0x80066A84: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x80066A88: jr          $ra
    // 0x80066A8C: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    return;
    // 0x80066A8C: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
;}
RECOMP_FUNC void initSpeechSubsystem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066A90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80066A94: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80066A98: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80066A9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80066AA0: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80066AA4: jal         0x8009BBA0
    // 0x80066AA8: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    initMusyXVoiceTable(rdram, ctx);
        goto after_0;
    // 0x80066AA8: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    after_0:
    // 0x80066AAC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066AB0: sb          $zero, -0x638F($v0)
    MEM_B(-0X638F, ctx->r2) = 0;
    // 0x80066AB4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066AB8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80066ABC: sb          $zero, -0x6390($v0)
    MEM_B(-0X6390, ctx->r2) = 0;
    // 0x80066AC0: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80066AC4: sb          $v0, -0x638E($v1)
    MEM_B(-0X638E, ctx->r3) = ctx->r2;
    // 0x80066AC8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066ACC: sb          $zero, -0x638D($v0)
    MEM_B(-0X638D, ctx->r2) = 0;
    // 0x80066AD0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066AD4: sw          $zero, -0x6388($v0)
    MEM_W(-0X6388, ctx->r2) = 0;
    // 0x80066AD8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066ADC: sw          $zero, -0x6384($v0)
    MEM_W(-0X6384, ctx->r2) = 0;
    // 0x80066AE0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066AE4: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80066AE8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80066AEC: lwc1        $f2, -0x3868($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3868);
    // 0x80066AF0: mtc1        $s0, $f0
    ctx->f0.u32l = ctx->r16;
    // 0x80066AF4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80066AF8: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80066AFC: swc1        $f0, -0x637C($v0)
    MEM_W(-0X637C, ctx->r2) = ctx->f0.u32l;
    // 0x80066B00: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066B04: swc1        $f0, -0x6380($v0)
    MEM_W(-0X6380, ctx->r2) = ctx->f0.u32l;
    // 0x80066B08: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80066B0C: lwc1        $f0, -0x3864($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3864);
    // 0x80066B10: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066B14: swc1        $f0, -0x6378($v0)
    MEM_W(-0X6378, ctx->r2) = ctx->f0.u32l;
    // 0x80066B18: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x80066B1C: bne         $v0, $zero, L_80066B64
    if (ctx->r2 != 0) {
        // 0x80066B20: lui         $v1, 0x800A
        ctx->r3 = S32(0X800A << 16);
            goto L_80066B64;
    }
    // 0x80066B20: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80066B24: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80066B28: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80066B2C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80066B30: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x80066B34: lw          $a2, 0x7CFC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X7CFC);
    // 0x80066B38: lw          $a3, 0x5C8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X5C8);
    // 0x80066B3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80066B40: jal         0x80004AAC
    // 0x80066B44: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    findAssetAcrossSegments(rdram, ctx);
        goto after_1;
    // 0x80066B44: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x80066B48: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80066B4C: lw          $a1, -0x76E0($s0)
    ctx->r5 = MEM_W(ctx->r16, -0X76E0);
    // 0x80066B50: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066B54: sw          $a0, -0x6490($v0)
    MEM_W(-0X6490, ctx->r2) = ctx->r4;
    // 0x80066B58: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066B5C: j           L_80066B90
    // 0x80066B60: sw          $zero, -0x648C($v0)
    MEM_W(-0X648C, ctx->r2) = 0;
        goto L_80066B90;
    // 0x80066B60: sw          $zero, -0x648C($v0)
    MEM_W(-0X648C, ctx->r2) = 0;
L_80066B64:
    // 0x80066B64: addiu       $v1, $v1, 0x5C8
    ctx->r3 = ADD32(ctx->r3, 0X5C8);
    // 0x80066B68: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80066B6C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80066B70: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80066B74: jal         0x8006488C
    // 0x80066B78: nop

    load_asset(rdram, ctx);
        goto after_2;
    // 0x80066B78: nop

    after_2:
    // 0x80066B7C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80066B80: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066B84: lw          $a1, -0x76E0($v0)
    ctx->r5 = MEM_W(ctx->r2, -0X76E0);
    // 0x80066B88: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066B8C: sw          $a0, -0x648C($v0)
    MEM_W(-0X648C, ctx->r2) = ctx->r4;
L_80066B90:
    // 0x80066B90: jal         0x8009BA38
    // 0x80066B94: nop

    loadSpeechFile(rdram, ctx);
        goto after_3;
    // 0x80066B94: nop

    after_3:
    // 0x80066B98: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80066B9C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80066BA0: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // 0x80066BA4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066BA8: addiu       $v0, $v0, -0x6480
    ctx->r2 = ADD32(ctx->r2, -0X6480);
    // 0x80066BAC: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
L_80066BB0:
    // 0x80066BB0: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x80066BB4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80066BB8: bgez        $v1, L_80066BB0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80066BBC: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_80066BB0;
    }
    // 0x80066BBC: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80066BC0: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80066BC4: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80066BC8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80066BCC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80066BD0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80066BD4: sh          $zero, -0x6458($v1)
    MEM_H(-0X6458, ctx->r3) = 0;
    // 0x80066BD8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80066BDC: sb          $zero, -0x6371($v1)
    MEM_B(-0X6371, ctx->r3) = 0;
    // 0x80066BE0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80066BE4: sb          $zero, -0x6374($v1)
    MEM_B(-0X6374, ctx->r3) = 0;
    // 0x80066BE8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80066BEC: sb          $zero, -0x6373($v1)
    MEM_B(-0X6373, ctx->r3) = 0;
    // 0x80066BF0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80066BF4: sb          $zero, -0x6372($v1)
    MEM_B(-0X6372, ctx->r3) = 0;
    // 0x80066BF8: jr          $ra
    // 0x80066BFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80066BFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void enqueueSpeechClip(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066C00: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80066C04: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80066C08: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80066C0C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80066C10: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x80066C14: sltiu       $v0, $s3, 0x2F4
    ctx->r2 = ctx->r19 < 0X2F4 ? 1 : 0;
    // 0x80066C18: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80066C1C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80066C20: beq         $v0, $zero, L_80066D6C
    if (ctx->r2 == 0) {
        // 0x80066C24: sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
            goto L_80066D6C;
    }
    // 0x80066C24: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80066C28: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80066C2C: lh          $a0, -0x6458($a1)
    ctx->r4 = MEM_H(ctx->r5, -0X6458);
    // 0x80066C30: addiu       $a2, $a1, -0x6458
    ctx->r6 = ADD32(ctx->r5, -0X6458);
    // 0x80066C34: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // 0x80066C38: bgez        $v1, L_80066C44
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80066C3C: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_80066C44;
    }
    // 0x80066C3C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x80066C40: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
L_80066C44:
    // 0x80066C44: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80066C48: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80066C4C: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x80066C50: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80066C54: sh          $v0, -0x6458($a1)
    MEM_H(-0X6458, ctx->r5) = ctx->r2;
    // 0x80066C58: lbu         $v0, 0x1($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X1);
    // 0x80066C5C: addiu       $v1, $v1, -0x6480
    ctx->r3 = ADD32(ctx->r3, -0X6480);
    // 0x80066C60: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80066C64: addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // 0x80066C68: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80066C6C: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80066C70: beq         $a0, $s1, L_80066CA0
    if (ctx->r4 == ctx->r17) {
        // 0x80066C74: lui         $v1, 0x800A
        ctx->r3 = S32(0X800A << 16);
            goto L_80066CA0;
    }
    // 0x80066C74: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80066C78: jal         0x8009B3CC
    // 0x80066C7C: nop

    isVoiceHandleActive(rdram, ctx);
        goto after_0;
    // 0x80066C7C: nop

    after_0:
    // 0x80066C80: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80066C84: beql        $v0, $zero, L_80066C9C
    if (ctx->r2 == 0) {
        // 0x80066C88: sw          $s1, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r17;
            goto L_80066C9C;
    }
    goto skip_0;
    // 0x80066C88: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
    skip_0:
    // 0x80066C8C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80066C90: jal         0x8009B33C
    // 0x80066C94: nop

    stopVoiceByHandle(rdram, ctx);
        goto after_1;
    // 0x80066C94: nop

    after_1:
    // 0x80066C98: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
L_80066C9C:
    // 0x80066C9C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
L_80066CA0:
    // 0x80066CA0: addiu       $v1, $v1, -0x20
    ctx->r3 = ADD32(ctx->r3, -0X20);
    // 0x80066CA4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066CA8: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    // 0x80066CAC: lwc1        $f2, -0x637C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X637C);
    // 0x80066CB0: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x80066CB4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80066CB8: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80066CBC: sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19 << 1);
    // 0x80066CC0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80066CC4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80066CC8: lwc1        $f2, -0x3860($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3860);
    // 0x80066CCC: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x80066CD0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80066CD4: nop

    // 0x80066CD8: bc1tl       L_80066CF0
    if (c1cs) {
        // 0x80066CDC: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_80066CF0;
    }
    goto skip_1;
    // 0x80066CDC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_1:
    // 0x80066CE0: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80066CE4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80066CE8: j           L_80066D04
    // 0x80066CEC: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
        goto L_80066D04;
    // 0x80066CEC: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
L_80066CF0:
    // 0x80066CF0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80066CF4: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80066CF8: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80066CFC: or          $a3, $a3, $v0
    ctx->r7 = ctx->r7 | ctx->r2;
    // 0x80066D00: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
L_80066D04:
    // 0x80066D04: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80066D08: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80066D0C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x80066D10: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80066D14: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80066D18: jal         0x8009B048
    // 0x80066D1C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    allocAndConfigureNewVoice(rdram, ctx);
        goto after_2;
    // 0x80066D1C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_2:
    // 0x80066D20: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80066D24: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80066D28: beq         $a2, $v0, L_80066D6C
    if (ctx->r6 == ctx->r2) {
        // 0x80066D2C: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_80066D6C;
    }
    // 0x80066D2C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80066D30: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80066D34: addiu       $v1, $v1, -0x6480
    ctx->r3 = ADD32(ctx->r3, -0X6480);
    // 0x80066D38: lh          $a0, -0x6458($a1)
    ctx->r4 = MEM_H(ctx->r5, -0X6458);
    // 0x80066D3C: addiu       $a1, $a1, -0x6458
    ctx->r5 = ADD32(ctx->r5, -0X6458);
    // 0x80066D40: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80066D44: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80066D48: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x80066D4C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066D50: addiu       $v0, $v0, -0x6460
    ctx->r2 = ADD32(ctx->r2, -0X6460);
    // 0x80066D54: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80066D58: sb          $s2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r18;
    // 0x80066D5C: lbu         $v0, 0x1($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1);
    // 0x80066D60: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80066D64: j           L_80066D70
    // 0x80066D68: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
        goto L_80066D70;
    // 0x80066D68: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_80066D6C:
    // 0x80066D6C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80066D70:
    // 0x80066D70: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80066D74: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80066D78: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80066D7C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80066D80: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80066D84: jr          $ra
    // 0x80066D88: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80066D88: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void applySpeechVolumeScalar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066D8C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80066D90: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066D94: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80066D98: addiu       $s2, $v0, -0x6480
    ctx->r18 = ADD32(ctx->r2, -0X6480);
    // 0x80066D9C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066DA0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80066DA4: addiu       $s4, $v0, -0x6460
    ctx->r20 = ADD32(ctx->r2, -0X6460);
    // 0x80066DA8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066DAC: lwc1        $f0, -0x6380($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X6380);
    // 0x80066DB0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80066DB4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80066DB8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80066DBC: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80066DC0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80066DC4: lui         $s3, 0x8000
    ctx->r19 = S32(0X8000 << 16);
    // 0x80066DC8: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x80066DCC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80066DD0: lwc1        $f20, -0x385C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X385C);
    // 0x80066DD4: mul.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80066DD8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066DDC: swc1        $f12, -0x6378($v0)
    MEM_W(-0X6378, ctx->r2) = ctx->f12.u32l;
    // 0x80066DE0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066DE4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80066DE8: swc1        $f0, -0x637C($v0)
    MEM_W(-0X637C, ctx->r2) = ctx->f0.u32l;
    // 0x80066DEC: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
L_80066DF0:
    // 0x80066DF0: beq         $v0, $zero, L_80066E1C
    if (ctx->r2 == 0) {
        // 0x80066DF4: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80066E1C;
    }
    // 0x80066DF4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80066DF8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80066DFC: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80066E00: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80066E04: beq         $a0, $s1, L_80066E20
    if (ctx->r4 == ctx->r17) {
        // 0x80066E08: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80066E20;
    }
    // 0x80066E08: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80066E0C: jal         0x8009B3CC
    // 0x80066E10: nop

    isVoiceHandleActive(rdram, ctx);
        goto after_0;
    // 0x80066E10: nop

    after_0:
    // 0x80066E14: j           L_80066E24
    // 0x80066E18: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_80066E24;
    // 0x80066E18: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_80066E1C:
    // 0x80066E1C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80066E20:
    // 0x80066E20: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_80066E24:
    // 0x80066E24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80066E28: bnel        $v1, $v0, L_80066EB0
    if (ctx->r3 != ctx->r2) {
        // 0x80066E2C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80066EB0;
    }
    goto skip_0;
    // 0x80066E2C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80066E30: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x80066E34: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x80066E38: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80066E3C: lbu         $v0, -0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X1);
    // 0x80066E40: lwc1        $f2, -0x637C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, -0X637C);
    // 0x80066E44: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80066E48: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80066E4C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80066E50: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x80066E54: nop

    // 0x80066E58: bc1tl       L_80066E70
    if (c1cs) {
        // 0x80066E5C: sub.s       $f0, $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
            goto L_80066E70;
    }
    goto skip_1;
    // 0x80066E5C: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    skip_1:
    // 0x80066E60: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80066E64: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80066E68: j           L_80066E80
    // 0x80066E6C: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
        goto L_80066E80;
    // 0x80066E6C: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
L_80066E70:
    // 0x80066E70: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80066E74: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80066E78: or          $a1, $a1, $s3
    ctx->r5 = ctx->r5 | ctx->r19;
    // 0x80066E7C: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
L_80066E80:
    // 0x80066E80: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80066E84: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80066E88: addu        $a0, $v0, $s2
    ctx->r4 = ADD32(ctx->r2, ctx->r18);
    // 0x80066E8C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80066E90: beq         $v0, $s1, L_80066EAC
    if (ctx->r2 == ctx->r17) {
        // 0x80066E94: andi        $a1, $a1, 0xFF
        ctx->r5 = ctx->r5 & 0XFF;
            goto L_80066EAC;
    }
    // 0x80066E94: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80066E98: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x80066E9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80066EA0: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80066EA4: jal         0x8009B464
    // 0x80066EA8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8009B464(rdram, ctx);
        goto after_1;
    // 0x80066EA8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
L_80066EAC:
    // 0x80066EAC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80066EB0:
    // 0x80066EB0: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x80066EB4: sltiu       $v0, $v0, 0x9
    ctx->r2 = ctx->r2 < 0X9 ? 1 : 0;
    // 0x80066EB8: bnel        $v0, $zero, L_80066DF0
    if (ctx->r2 != 0) {
        // 0x80066EBC: andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
            goto L_80066DF0;
    }
    goto skip_2;
    // 0x80066EBC: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    skip_2:
    // 0x80066EC0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80066EC4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80066EC8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80066ECC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80066ED0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80066ED4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80066ED8: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x80066EDC: jr          $ra
    // 0x80066EE0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80066EE0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void playSpeechClip(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066EE4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80066EE8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80066EEC: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80066EF0: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80066EF4: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x80066EF8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80066EFC: addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    // 0x80066F00: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80066F04: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x80066F08: slti        $v0, $s3, 0x2F4
    ctx->r2 = SIGNED(ctx->r19) < 0X2F4 ? 1 : 0;
    // 0x80066F0C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80066F10: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80066F14: beq         $v0, $zero, L_800670E4
    if (ctx->r2 == 0) {
        // 0x80066F18: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_800670E4;
    }
    // 0x80066F18: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80066F1C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066F20: lbu         $v0, -0x6372($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6372);
    // 0x80066F24: bne         $v0, $zero, L_800670E4
    if (ctx->r2 != 0) {
        // 0x80066F28: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800670E4;
    }
    // 0x80066F28: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066F2C: lbu         $v0, -0x6374($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6374);
    // 0x80066F30: beq         $v0, $zero, L_80066F40
    if (ctx->r2 == 0) {
        // 0x80066F34: andi        $v0, $a3, 0x40
        ctx->r2 = ctx->r7 & 0X40;
            goto L_80066F40;
    }
    // 0x80066F34: andi        $v0, $a3, 0x40
    ctx->r2 = ctx->r7 & 0X40;
    // 0x80066F38: beq         $v0, $zero, L_800670E4
    if (ctx->r2 == 0) {
        // 0x80066F3C: nop
    
            goto L_800670E4;
    }
    // 0x80066F3C: nop

L_80066F40:
    // 0x80066F40: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066F44: lbu         $v1, -0x638E($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X638E);
    // 0x80066F48: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80066F4C: beq         $v1, $v0, L_80066F5C
    if (ctx->r3 == ctx->r2) {
        // 0x80066F50: andi        $v0, $a3, 0x8
        ctx->r2 = ctx->r7 & 0X8;
            goto L_80066F5C;
    }
    // 0x80066F50: andi        $v0, $a3, 0x8
    ctx->r2 = ctx->r7 & 0X8;
    // 0x80066F54: bne         $v0, $zero, L_800670E4
    if (ctx->r2 != 0) {
        // 0x80066F58: nop
    
            goto L_800670E4;
    }
    // 0x80066F58: nop

L_80066F5C:
    // 0x80066F5C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80066F60: lw          $v0, 0xB50($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB50);
    // 0x80066F64: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x80066F68: bne         $v0, $zero, L_800670E4
    if (ctx->r2 != 0) {
        // 0x80066F6C: addiu       $v0, $zero, 0x28C
        ctx->r2 = ADD32(0, 0X28C);
            goto L_800670E4;
    }
    // 0x80066F6C: addiu       $v0, $zero, 0x28C
    ctx->r2 = ADD32(0, 0X28C);
    // 0x80066F70: beq         $s3, $v0, L_800670E4
    if (ctx->r19 == ctx->r2) {
        // 0x80066F74: andi        $v0, $a3, 0x10
        ctx->r2 = ctx->r7 & 0X10;
            goto L_800670E4;
    }
    // 0x80066F74: andi        $v0, $a3, 0x10
    ctx->r2 = ctx->r7 & 0X10;
    // 0x80066F78: beq         $v0, $zero, L_80067010
    if (ctx->r2 == 0) {
        // 0x80066F7C: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80067010;
    }
    // 0x80066F7C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066F80: lbu         $v0, -0x638D($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X638D);
    // 0x80066F84: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x80066F88: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80066F8C: sltiu       $v0, $v0, 0x8
    ctx->r2 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x80066F90: beq         $v0, $zero, L_80066FDC
    if (ctx->r2 == 0) {
        // 0x80066F94: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_80066FDC;
    }
    // 0x80066F94: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80066F98: addiu       $v1, $v1, -0x6480
    ctx->r3 = ADD32(ctx->r3, -0X6480);
    // 0x80066F9C: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80066FA0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80066FA4: addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // 0x80066FA8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80066FAC: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80066FB0: beq         $a0, $s1, L_80066FE0
    if (ctx->r4 == ctx->r17) {
        // 0x80066FB4: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80066FE0;
    }
    // 0x80066FB4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066FB8: jal         0x8009B3CC
    // 0x80066FBC: nop

    isVoiceHandleActive(rdram, ctx);
        goto after_0;
    // 0x80066FBC: nop

    after_0:
    // 0x80066FC0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80066FC4: beql        $v0, $zero, L_80066FDC
    if (ctx->r2 == 0) {
        // 0x80066FC8: sw          $s1, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r17;
            goto L_80066FDC;
    }
    goto skip_0;
    // 0x80066FC8: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
    skip_0:
    // 0x80066FCC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80066FD0: jal         0x8009B33C
    // 0x80066FD4: nop

    stopVoiceByHandle(rdram, ctx);
        goto after_1;
    // 0x80066FD4: nop

    after_1:
    // 0x80066FD8: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
L_80066FDC:
    // 0x80066FDC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_80066FE0:
    // 0x80066FE0: sb          $zero, -0x638F($v0)
    MEM_B(-0X638F, ctx->r2) = 0;
    // 0x80066FE4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066FE8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80066FEC: sb          $zero, -0x6390($v0)
    MEM_B(-0X6390, ctx->r2) = 0;
    // 0x80066FF0: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80066FF4: sb          $v0, -0x638E($v1)
    MEM_B(-0X638E, ctx->r3) = ctx->r2;
    // 0x80066FF8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80066FFC: sb          $zero, -0x638D($v0)
    MEM_B(-0X638D, ctx->r2) = 0;
    // 0x80067000: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067004: sw          $zero, -0x6388($v0)
    MEM_W(-0X6388, ctx->r2) = 0;
    // 0x80067008: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006700C: sw          $zero, -0x6384($v0)
    MEM_W(-0X6384, ctx->r2) = 0;
L_80067010:
    // 0x80067010: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067014: lbu         $v1, -0x638E($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X638E);
    // 0x80067018: beq         $v1, $zero, L_800670D0
    if (ctx->r3 == 0) {
        // 0x8006701C: addiu       $v0, $zero, 0x10
        ctx->r2 = ADD32(0, 0X10);
            goto L_800670D0;
    }
    // 0x8006701C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80067020: bne         $v1, $v0, L_80067064
    if (ctx->r3 != ctx->r2) {
        // 0x80067024: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_80067064;
    }
    // 0x80067024: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80067028: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006702C: lwc1        $f0, -0x3858($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3858);
    // 0x80067030: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80067034: nop

    // 0x80067038: bc1f        L_80067058
    if (!c1cs) {
        // 0x8006703C: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80067058;
    }
    // 0x8006703C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067040: lbu         $v0, -0x6371($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6371);
    // 0x80067044: bne         $v0, $zero, L_8006705C
    if (ctx->r2 != 0) {
        // 0x80067048: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_8006705C;
    }
    // 0x80067048: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006704C: andi        $v0, $s2, 0x6
    ctx->r2 = ctx->r18 & 0X6;
    // 0x80067050: bnel        $v0, $zero, L_80067058
    if (ctx->r2 != 0) {
        // 0x80067054: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_80067058;
    }
    goto skip_1;
    // 0x80067054: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_1:
L_80067058:
    // 0x80067058: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_8006705C:
    // 0x8006705C: swc1        $f20, -0x6388($v0)
    MEM_W(-0X6388, ctx->r2) = ctx->f20.u32l;
    // 0x80067060: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
L_80067064:
    // 0x80067064: lui         $a3, 0x8014
    ctx->r7 = S32(0X8014 << 16);
    // 0x80067068: lbu         $v1, -0x638F($a3)
    ctx->r3 = MEM_BU(ctx->r7, -0X638F);
    // 0x8006706C: addiu       $a0, $a0, -0x6450
    ctx->r4 = ADD32(ctx->r4, -0X6450);
    // 0x80067070: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80067074: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80067078: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8006707C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80067080: sb          $s4, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r20;
    // 0x80067084: lbu         $v1, -0x638F($a3)
    ctx->r3 = MEM_BU(ctx->r7, -0X638F);
    // 0x80067088: sh          $s3, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r19;
    // 0x8006708C: sh          $s2, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r18;
    // 0x80067090: addiu       $a1, $v1, 0x1
    ctx->r5 = ADD32(ctx->r3, 0X1);
    // 0x80067094: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80067098: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8006709C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800670A0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800670A4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800670A8: bgez        $a1, L_800670B4
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800670AC: swc1        $f20, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f20.u32l;
            goto L_800670B4;
    }
    // 0x800670AC: swc1        $f20, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f20.u32l;
    // 0x800670B0: addiu       $a2, $v1, 0x10
    ctx->r6 = ADD32(ctx->r3, 0X10);
L_800670B4:
    // 0x800670B4: andi        $v0, $a2, 0x1F0
    ctx->r2 = ctx->r6 & 0X1F0;
    // 0x800670B8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800670BC: lbu         $v1, -0x638E($a0)
    ctx->r3 = MEM_BU(ctx->r4, -0X638E);
    // 0x800670C0: subu        $v0, $a1, $v0
    ctx->r2 = SUB32(ctx->r5, ctx->r2);
    // 0x800670C4: sb          $v0, -0x638F($a3)
    MEM_B(-0X638F, ctx->r7) = ctx->r2;
    // 0x800670C8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800670CC: sb          $v1, -0x638E($a0)
    MEM_B(-0X638E, ctx->r4) = ctx->r3;
L_800670D0:
    // 0x800670D0: andi        $v0, $s2, 0x20
    ctx->r2 = ctx->r18 & 0X20;
    // 0x800670D4: beq         $v0, $zero, L_800670E4
    if (ctx->r2 == 0) {
        // 0x800670D8: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_800670E4;
    }
    // 0x800670D8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800670DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800670E0: sb          $v0, -0x6374($v1)
    MEM_B(-0X6374, ctx->r3) = ctx->r2;
L_800670E4:
    // 0x800670E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800670E8: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800670EC: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800670F0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800670F4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800670F8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800670FC: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80067100: jr          $ra
    // 0x80067104: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80067104: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80067108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067108: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006710C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067110: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80067114: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x80067118: lbu         $v0, -0x6372($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6372);
    // 0x8006711C: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80067120: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x80067124: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80067128: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x8006712C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80067130: addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    // 0x80067134: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80067138: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8006713C: bne         $v0, $zero, L_800672DC
    if (ctx->r2 != 0) {
        // 0x80067140: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_800672DC;
    }
    // 0x80067140: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80067144: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067148: lbu         $v0, -0x6374($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6374);
    // 0x8006714C: beq         $v0, $zero, L_8006715C
    if (ctx->r2 == 0) {
        // 0x80067150: andi        $v0, $a3, 0x40
        ctx->r2 = ctx->r7 & 0X40;
            goto L_8006715C;
    }
    // 0x80067150: andi        $v0, $a3, 0x40
    ctx->r2 = ctx->r7 & 0X40;
    // 0x80067154: beq         $v0, $zero, L_800672DC
    if (ctx->r2 == 0) {
        // 0x80067158: nop
    
            goto L_800672DC;
    }
    // 0x80067158: nop

L_8006715C:
    // 0x8006715C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067160: lbu         $v1, -0x638E($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X638E);
    // 0x80067164: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80067168: beq         $v1, $v0, L_80067178
    if (ctx->r3 == ctx->r2) {
        // 0x8006716C: andi        $v0, $a3, 0x8
        ctx->r2 = ctx->r7 & 0X8;
            goto L_80067178;
    }
    // 0x8006716C: andi        $v0, $a3, 0x8
    ctx->r2 = ctx->r7 & 0X8;
    // 0x80067170: bne         $v0, $zero, L_800672DC
    if (ctx->r2 != 0) {
        // 0x80067174: nop
    
            goto L_800672DC;
    }
    // 0x80067174: nop

L_80067178:
    // 0x80067178: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006717C: lw          $v0, 0xB50($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB50);
    // 0x80067180: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x80067184: bne         $v0, $zero, L_800672DC
    if (ctx->r2 != 0) {
        // 0x80067188: andi        $v0, $a3, 0x10
        ctx->r2 = ctx->r7 & 0X10;
            goto L_800672DC;
    }
    // 0x80067188: andi        $v0, $a3, 0x10
    ctx->r2 = ctx->r7 & 0X10;
    // 0x8006718C: beq         $v0, $zero, L_80067224
    if (ctx->r2 == 0) {
        // 0x80067190: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80067224;
    }
    // 0x80067190: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067194: lbu         $v0, -0x638D($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X638D);
    // 0x80067198: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x8006719C: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x800671A0: sltiu       $v0, $v0, 0x8
    ctx->r2 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x800671A4: beq         $v0, $zero, L_800671F0
    if (ctx->r2 == 0) {
        // 0x800671A8: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_800671F0;
    }
    // 0x800671A8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800671AC: addiu       $v1, $v1, -0x6480
    ctx->r3 = ADD32(ctx->r3, -0X6480);
    // 0x800671B0: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x800671B4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800671B8: addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // 0x800671BC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800671C0: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x800671C4: beq         $a0, $s1, L_800671F4
    if (ctx->r4 == ctx->r17) {
        // 0x800671C8: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800671F4;
    }
    // 0x800671C8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800671CC: jal         0x8009B3CC
    // 0x800671D0: nop

    isVoiceHandleActive(rdram, ctx);
        goto after_0;
    // 0x800671D0: nop

    after_0:
    // 0x800671D4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800671D8: beql        $v0, $zero, L_800671F0
    if (ctx->r2 == 0) {
        // 0x800671DC: sw          $s1, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r17;
            goto L_800671F0;
    }
    goto skip_0;
    // 0x800671DC: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
    skip_0:
    // 0x800671E0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800671E4: jal         0x8009B33C
    // 0x800671E8: nop

    stopVoiceByHandle(rdram, ctx);
        goto after_1;
    // 0x800671E8: nop

    after_1:
    // 0x800671EC: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
L_800671F0:
    // 0x800671F0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_800671F4:
    // 0x800671F4: sb          $zero, -0x638F($v0)
    MEM_B(-0X638F, ctx->r2) = 0;
    // 0x800671F8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800671FC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80067200: sb          $zero, -0x6390($v0)
    MEM_B(-0X6390, ctx->r2) = 0;
    // 0x80067204: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80067208: sb          $v0, -0x638E($v1)
    MEM_B(-0X638E, ctx->r3) = ctx->r2;
    // 0x8006720C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067210: sb          $zero, -0x638D($v0)
    MEM_B(-0X638D, ctx->r2) = 0;
    // 0x80067214: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067218: sw          $zero, -0x6388($v0)
    MEM_W(-0X6388, ctx->r2) = 0;
    // 0x8006721C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067220: sw          $zero, -0x6384($v0)
    MEM_W(-0X6384, ctx->r2) = 0;
L_80067224:
    // 0x80067224: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067228: lbu         $v0, -0x638E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X638E);
    // 0x8006722C: beq         $v0, $zero, L_800672C8
    if (ctx->r2 == 0) {
        // 0x80067230: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800672C8;
    }
    // 0x80067230: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067234: lbu         $a0, -0x6390($v0)
    ctx->r4 = MEM_BU(ctx->r2, -0X6390);
    // 0x80067238: addiu       $v1, $a0, 0xF
    ctx->r3 = ADD32(ctx->r4, 0XF);
    // 0x8006723C: bgez        $v1, L_80067248
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80067240: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_80067248;
    }
    // 0x80067240: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x80067244: addiu       $v0, $a0, 0x1E
    ctx->r2 = ADD32(ctx->r4, 0X1E);
L_80067248:
    // 0x80067248: andi        $v0, $v0, 0x1F0
    ctx->r2 = ctx->r2 & 0X1F0;
    // 0x8006724C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80067250: lwc1        $f0, -0x3854($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3854);
    // 0x80067254: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80067258: nop

    // 0x8006725C: bc1f        L_80067280
    if (!c1cs) {
        // 0x80067260: subu        $a1, $v1, $v0
        ctx->r5 = SUB32(ctx->r3, ctx->r2);
            goto L_80067280;
    }
    // 0x80067260: subu        $a1, $v1, $v0
    ctx->r5 = SUB32(ctx->r3, ctx->r2);
    // 0x80067264: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067268: lbu         $v0, -0x6371($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6371);
    // 0x8006726C: bne         $v0, $zero, L_80067284
    if (ctx->r2 != 0) {
        // 0x80067270: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80067284;
    }
    // 0x80067270: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067274: andi        $v0, $s2, 0x6
    ctx->r2 = ctx->r18 & 0X6;
    // 0x80067278: bnel        $v0, $zero, L_80067280
    if (ctx->r2 != 0) {
        // 0x8006727C: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_80067280;
    }
    goto skip_1;
    // 0x8006727C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_1:
L_80067280:
    // 0x80067280: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_80067284:
    // 0x80067284: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80067288: addiu       $v1, $v1, -0x6450
    ctx->r3 = ADD32(ctx->r3, -0X6450);
    // 0x8006728C: swc1        $f20, -0x6388($v0)
    MEM_W(-0X6388, ctx->r2) = ctx->f20.u32l;
    // 0x80067290: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x80067294: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80067298: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8006729C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800672A0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800672A4: sh          $s4, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r20;
    // 0x800672A8: sh          $s2, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r18;
    // 0x800672AC: sb          $s3, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r19;
    // 0x800672B0: swc1        $f20, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f20.u32l;
    // 0x800672B4: lbu         $v0, -0x638E($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X638E);
    // 0x800672B8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800672BC: sb          $a1, -0x6390($v1)
    MEM_B(-0X6390, ctx->r3) = ctx->r5;
    // 0x800672C0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800672C4: sb          $v0, -0x638E($a0)
    MEM_B(-0X638E, ctx->r4) = ctx->r2;
L_800672C8:
    // 0x800672C8: andi        $v0, $s2, 0x20
    ctx->r2 = ctx->r18 & 0X20;
    // 0x800672CC: beq         $v0, $zero, L_800672DC
    if (ctx->r2 == 0) {
        // 0x800672D0: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_800672DC;
    }
    // 0x800672D0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800672D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800672D8: sb          $v0, -0x6374($v1)
    MEM_B(-0X6374, ctx->r3) = ctx->r2;
L_800672DC:
    // 0x800672DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800672E0: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800672E4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800672E8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800672EC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800672F0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800672F4: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800672F8: jr          $ra
    // 0x800672FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800672FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void tickSpeechSubsystem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067300: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067304: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80067308: lbu         $a0, -0x638F($v0)
    ctx->r4 = MEM_BU(ctx->r2, -0X638F);
    // 0x8006730C: lbu         $v0, -0x6390($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X6390);
    // 0x80067310: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80067314: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80067318: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x8006731C: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80067320: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80067324: bne         $a0, $v0, L_80067340
    if (ctx->r4 != ctx->r2) {
        // 0x80067328: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80067340;
    }
    // 0x80067328: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006732C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067330: lbu         $v1, -0x638E($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X638E);
    // 0x80067334: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80067338: beq         $v1, $v0, L_800675D8
    if (ctx->r3 == ctx->r2) {
        // 0x8006733C: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800675D8;
    }
    // 0x8006733C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_80067340:
    // 0x80067340: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067344: lbu         $v1, -0x638D($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X638D);
    // 0x80067348: beq         $v1, $zero, L_80067380
    if (ctx->r3 == 0) {
        // 0x8006734C: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80067380;
    }
    // 0x8006734C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067350: addiu       $v0, $v0, -0x6480
    ctx->r2 = ADD32(ctx->r2, -0X6480);
    // 0x80067354: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80067358: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8006735C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80067360: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80067364: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80067368: beq         $a0, $v0, L_80067384
    if (ctx->r4 == ctx->r2) {
        // 0x8006736C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80067384;
    }
    // 0x8006736C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80067370: jal         0x8009B3CC
    // 0x80067374: nop

    isVoiceHandleActive(rdram, ctx);
        goto after_0;
    // 0x80067374: nop

    after_0:
    // 0x80067378: j           L_80067388
    // 0x8006737C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
        goto L_80067388;
    // 0x8006737C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_80067380:
    // 0x80067380: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80067384:
    // 0x80067384: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_80067388:
    // 0x80067388: bne         $v0, $zero, L_80067670
    if (ctx->r2 != 0) {
        // 0x8006738C: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_80067670;
    }
    // 0x8006738C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80067390: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067394: lbu         $v0, -0x6373($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6373);
    // 0x80067398: beq         $v0, $zero, L_800673E4
    if (ctx->r2 == 0) {
        // 0x8006739C: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800673E4;
    }
    // 0x8006739C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800673A0: lwc1        $f2, -0x6384($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X6384);
    // 0x800673A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800673A8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800673AC: nop

    // 0x800673B0: bc1f        L_8006766C
    if (!c1cs) {
        // 0x800673B4: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_8006766C;
    }
    // 0x800673B4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800673B8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800673BC: lbu         $a0, -0x6390($v0)
    ctx->r4 = MEM_BU(ctx->r2, -0X6390);
    // 0x800673C0: addiu       $v1, $v1, -0x6450
    ctx->r3 = ADD32(ctx->r3, -0X6450);
    // 0x800673C4: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x800673C8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800673CC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800673D0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800673D4: lhu         $v0, 0x6($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6);
    // 0x800673D8: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x800673DC: beq         $v0, $zero, L_80067670
    if (ctx->r2 == 0) {
        // 0x800673E0: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_80067670;
    }
    // 0x800673E0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
L_800673E4:
    // 0x800673E4: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800673E8: lwc1        $f2, -0x6388($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, -0X6388);
    // 0x800673EC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800673F0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800673F4: nop

    // 0x800673F8: bc1f        L_8006752C
    if (!c1cs) {
        // 0x800673FC: lui         $s0, 0x8014
        ctx->r16 = S32(0X8014 << 16);
            goto L_8006752C;
    }
    // 0x800673FC: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80067400: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80067404: lbu         $v1, -0x6390($s1)
    ctx->r3 = MEM_BU(ctx->r17, -0X6390);
    // 0x80067408: addiu       $s0, $s0, -0x6450
    ctx->r16 = ADD32(ctx->r16, -0X6450);
    // 0x8006740C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80067410: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80067414: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80067418: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8006741C: lhu         $a0, 0x4($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X4);
    // 0x80067420: lbu         $a1, 0x8($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X8);
    // 0x80067424: jal         0x80066C00
    // 0x80067428: nop

    enqueueSpeechClip(rdram, ctx);
        goto after_1;
    // 0x80067428: nop

    after_1:
    // 0x8006742C: lbu         $v1, -0x6390($s1)
    ctx->r3 = MEM_BU(ctx->r17, -0X6390);
    // 0x80067430: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80067434: sb          $v0, -0x638D($a2)
    MEM_B(-0X638D, ctx->r6) = ctx->r2;
    // 0x80067438: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8006743C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80067440: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80067444: addu        $a1, $v0, $s0
    ctx->r5 = ADD32(ctx->r2, ctx->r16);
    // 0x80067448: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8006744C: lhu         $v0, 0x6($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X6);
    // 0x80067450: lhu         $a0, 0x4($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X4);
    // 0x80067454: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80067458: beq         $v0, $zero, L_800674B0
    if (ctx->r2 == 0) {
        // 0x8006745C: sh          $a0, -0x638C($v1)
        MEM_H(-0X638C, ctx->r3) = ctx->r4;
            goto L_800674B0;
    }
    // 0x8006745C: sh          $a0, -0x638C($v1)
    MEM_H(-0X638C, ctx->r3) = ctx->r4;
    // 0x80067460: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80067464: lw          $v0, 0xB50($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB50);
    // 0x80067468: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8006746C: bnel        $v0, $zero, L_800674B4
    if (ctx->r2 != 0) {
        // 0x80067470: lui         $a2, 0x8014
        ctx->r6 = S32(0X8014 << 16);
            goto L_800674B4;
    }
    goto skip_0;
    // 0x80067470: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    skip_0:
    // 0x80067474: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80067478: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8006747C: addiu       $v1, $v1, -0x20
    ctx->r3 = ADD32(ctx->r3, -0X20);
    // 0x80067480: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80067484: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80067488: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8006748C: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x80067490: lbu         $v0, -0x638D($a2)
    ctx->r2 = MEM_BU(ctx->r6, -0X638D);
    // 0x80067494: addiu       $v1, $v1, -0x6480
    ctx->r3 = ADD32(ctx->r3, -0X6480);
    // 0x80067498: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8006749C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800674A0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800674A4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800674A8: jal         0x800562E0
    // 0x800674AC: nop

    setActiveVoiceLine(rdram, ctx);
        goto after_2;
    // 0x800674AC: nop

    after_2:
L_800674B0:
    // 0x800674B0: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
L_800674B4:
    // 0x800674B4: lbu         $v0, -0x6390($a2)
    ctx->r2 = MEM_BU(ctx->r6, -0X6390);
    // 0x800674B8: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    // 0x800674BC: bgez        $a1, L_800674C8
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800674C0: addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
            goto L_800674C8;
    }
    // 0x800674C0: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // 0x800674C4: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
L_800674C8:
    // 0x800674C8: andi        $v1, $v1, 0x1F0
    ctx->r3 = ctx->r3 & 0X1F0;
    // 0x800674CC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800674D0: lbu         $v0, -0x638E($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X638E);
    // 0x800674D4: subu        $v1, $a1, $v1
    ctx->r3 = SUB32(ctx->r5, ctx->r3);
    // 0x800674D8: sb          $v1, -0x6390($a2)
    MEM_B(-0X6390, ctx->r6) = ctx->r3;
    // 0x800674DC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800674E0: sb          $v0, -0x638E($a0)
    MEM_B(-0X638E, ctx->r4) = ctx->r2;
    // 0x800674E4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800674E8: lbu         $v0, -0x638F($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X638F);
    // 0x800674EC: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x800674F0: beq         $v0, $v1, L_80067520
    if (ctx->r2 == ctx->r3) {
        // 0x800674F4: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_80067520;
    }
    // 0x800674F4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800674F8: lbu         $a0, -0x6390($a2)
    ctx->r4 = MEM_BU(ctx->r6, -0X6390);
    // 0x800674FC: addiu       $v1, $v1, -0x6450
    ctx->r3 = ADD32(ctx->r3, -0X6450);
    // 0x80067500: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80067504: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80067508: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8006750C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80067510: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80067514: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067518: j           L_8006766C
    // 0x8006751C: swc1        $f0, -0x6388($v0)
    MEM_W(-0X6388, ctx->r2) = ctx->f0.u32l;
        goto L_8006766C;
    // 0x8006751C: swc1        $f0, -0x6388($v0)
    MEM_W(-0X6388, ctx->r2) = ctx->f0.u32l;
L_80067520:
    // 0x80067520: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067524: j           L_8006766C
    // 0x80067528: sw          $zero, -0x6388($v0)
    MEM_W(-0X6388, ctx->r2) = 0;
        goto L_8006766C;
    // 0x80067528: sw          $zero, -0x6388($v0)
    MEM_W(-0X6388, ctx->r2) = 0;
L_8006752C:
    // 0x8006752C: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80067530: lbu         $v0, -0x6371($s0)
    ctx->r2 = MEM_BU(ctx->r16, -0X6371);
    // 0x80067534: bne         $v0, $zero, L_800675B4
    if (ctx->r2 != 0) {
        // 0x80067538: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800675B4;
    }
    // 0x80067538: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006753C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80067540: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067544: lbu         $a0, -0x6390($v0)
    ctx->r4 = MEM_BU(ctx->r2, -0X6390);
    // 0x80067548: addiu       $v1, $v1, -0x6450
    ctx->r3 = ADD32(ctx->r3, -0X6450);
    // 0x8006754C: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80067550: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80067554: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80067558: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006755C: lhu         $v0, 0x6($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6);
    // 0x80067560: andi        $v0, $v0, 0x6
    ctx->r2 = ctx->r2 & 0X6;
    // 0x80067564: beq         $v0, $zero, L_800675B4
    if (ctx->r2 == 0) {
        // 0x80067568: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800675B4;
    }
    // 0x80067568: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006756C: sub.s       $f0, $f2, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f20.fl;
    // 0x80067570: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80067574: lwc1        $f2, -0x3850($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3850);
    // 0x80067578: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8006757C: nop

    // 0x80067580: bc1f        L_8006766C
    if (!c1cs) {
        // 0x80067584: swc1        $f0, -0x6388($a1)
        MEM_W(-0X6388, ctx->r5) = ctx->f0.u32l;
            goto L_8006766C;
    }
    // 0x80067584: swc1        $f0, -0x6388($a1)
    MEM_W(-0X6388, ctx->r5) = ctx->f0.u32l;
    // 0x80067588: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    // 0x8006758C: addiu       $a1, $zero, 0x258
    ctx->r5 = ADD32(0, 0X258);
    // 0x80067590: jal         0x8008E4E4
    // 0x80067594: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    func_8008E4E4(rdram, ctx);
        goto after_3;
    // 0x80067594: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    after_3:
    // 0x80067598: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    // 0x8006759C: addiu       $a1, $zero, 0x258
    ctx->r5 = ADD32(0, 0X258);
    // 0x800675A0: jal         0x8008E4E4
    // 0x800675A4: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    func_8008E4E4(rdram, ctx);
        goto after_4;
    // 0x800675A4: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    after_4:
    // 0x800675A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800675AC: j           L_8006766C
    // 0x800675B0: sb          $v0, -0x6371($s0)
    MEM_B(-0X6371, ctx->r16) = ctx->r2;
        goto L_8006766C;
    // 0x800675B0: sb          $v0, -0x6371($s0)
    MEM_B(-0X6371, ctx->r16) = ctx->r2;
L_800675B4:
    // 0x800675B4: lwc1        $f0, -0x6388($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X6388);
    // 0x800675B8: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800675BC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800675C0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800675C4: nop

    // 0x800675C8: bc1f        L_8006766C
    if (!c1cs) {
        // 0x800675CC: swc1        $f0, -0x6388($v0)
        MEM_W(-0X6388, ctx->r2) = ctx->f0.u32l;
            goto L_8006766C;
    }
    // 0x800675CC: swc1        $f0, -0x6388($v0)
    MEM_W(-0X6388, ctx->r2) = ctx->f0.u32l;
    // 0x800675D0: j           L_8006766C
    // 0x800675D4: swc1        $f2, -0x6388($v0)
    MEM_W(-0X6388, ctx->r2) = ctx->f2.u32l;
        goto L_8006766C;
    // 0x800675D4: swc1        $f2, -0x6388($v0)
    MEM_W(-0X6388, ctx->r2) = ctx->f2.u32l;
L_800675D8:
    // 0x800675D8: lbu         $v0, -0x6371($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6371);
    // 0x800675DC: beq         $v0, $zero, L_8006766C
    if (ctx->r2 == 0) {
        // 0x800675E0: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_8006766C;
    }
    // 0x800675E0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800675E4: lbu         $v1, -0x638D($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X638D);
    // 0x800675E8: beq         $v1, $zero, L_80067620
    if (ctx->r3 == 0) {
        // 0x800675EC: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80067620;
    }
    // 0x800675EC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800675F0: addiu       $v0, $v0, -0x6480
    ctx->r2 = ADD32(ctx->r2, -0X6480);
    // 0x800675F4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800675F8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800675FC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80067600: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80067604: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80067608: beq         $a0, $v0, L_80067624
    if (ctx->r4 == ctx->r2) {
        // 0x8006760C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80067624;
    }
    // 0x8006760C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80067610: jal         0x8009B3CC
    // 0x80067614: nop

    isVoiceHandleActive(rdram, ctx);
        goto after_5;
    // 0x80067614: nop

    after_5:
    // 0x80067618: j           L_80067628
    // 0x8006761C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
        goto L_80067628;
    // 0x8006761C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_80067620:
    // 0x80067620: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80067624:
    // 0x80067624: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_80067628:
    // 0x80067628: bne         $v0, $zero, L_80067670
    if (ctx->r2 != 0) {
        // 0x8006762C: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_80067670;
    }
    // 0x8006762C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80067630: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067634: lwc1        $f0, -0x6388($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X6388);
    // 0x80067638: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x8006763C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80067640: lwc1        $f2, -0x384C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X384C);
    // 0x80067644: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80067648: nop

    // 0x8006764C: bc1f        L_80067670
    if (!c1cs) {
        // 0x80067650: swc1        $f0, -0x6388($v0)
        MEM_W(-0X6388, ctx->r2) = ctx->f0.u32l;
            goto L_80067670;
    }
    // 0x80067650: swc1        $f0, -0x6388($v0)
    MEM_W(-0X6388, ctx->r2) = ctx->f0.u32l;
    // 0x80067654: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    // 0x80067658: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    // 0x8006765C: jal         0x8008E4E4
    // 0x80067660: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_8008E4E4(rdram, ctx);
        goto after_6;
    // 0x80067660: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_6:
    // 0x80067664: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067668: sb          $zero, -0x6371($v0)
    MEM_B(-0X6371, ctx->r2) = 0;
L_8006766C:
    // 0x8006766C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
L_80067670:
    // 0x80067670: lwc1        $f2, -0x6384($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, -0X6384);
    // 0x80067674: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80067678: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8006767C: nop

    // 0x80067680: bc1f        L_80067808
    if (!c1cs) {
        // 0x80067684: nop
    
            goto L_80067808;
    }
    // 0x80067684: nop

    // 0x80067688: add.s       $f0, $f20, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f20.fl;
    // 0x8006768C: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80067690: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80067694: nop

    // 0x80067698: bc1f        L_8006770C
    if (!c1cs) {
        // 0x8006769C: swc1        $f0, -0x6384($v1)
        MEM_W(-0X6384, ctx->r3) = ctx->f0.u32l;
            goto L_8006770C;
    }
    // 0x8006769C: swc1        $f0, -0x6384($v1)
    MEM_W(-0X6384, ctx->r3) = ctx->f0.u32l;
    // 0x800676A0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800676A4: lbu         $v0, -0x638D($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X638D);
    // 0x800676A8: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x800676AC: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x800676B0: sltiu       $v0, $v0, 0x8
    ctx->r2 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x800676B4: beq         $v0, $zero, L_80067704
    if (ctx->r2 == 0) {
        // 0x800676B8: swc1        $f4, -0x6384($v1)
        MEM_W(-0X6384, ctx->r3) = ctx->f4.u32l;
            goto L_80067704;
    }
    // 0x800676B8: swc1        $f4, -0x6384($v1)
    MEM_W(-0X6384, ctx->r3) = ctx->f4.u32l;
    // 0x800676BC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800676C0: addiu       $v1, $v1, -0x6480
    ctx->r3 = ADD32(ctx->r3, -0X6480);
    // 0x800676C4: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x800676C8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800676CC: addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // 0x800676D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800676D4: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x800676D8: beq         $a0, $s1, L_80067704
    if (ctx->r4 == ctx->r17) {
        // 0x800676DC: nop
    
            goto L_80067704;
    }
    // 0x800676DC: nop

    // 0x800676E0: jal         0x8009B3CC
    // 0x800676E4: nop

    isVoiceHandleActive(rdram, ctx);
        goto after_7;
    // 0x800676E4: nop

    after_7:
    // 0x800676E8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800676EC: beql        $v0, $zero, L_80067704
    if (ctx->r2 == 0) {
        // 0x800676F0: sw          $s1, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r17;
            goto L_80067704;
    }
    goto skip_1;
    // 0x800676F0: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
    skip_1:
    // 0x800676F4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800676F8: jal         0x8009B33C
    // 0x800676FC: nop

    stopVoiceByHandle(rdram, ctx);
        goto after_8;
    // 0x800676FC: nop

    after_8:
    // 0x80067700: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
L_80067704:
    // 0x80067704: jal         0x80056330
    // 0x80067708: nop

    clearActiveVoiceLine(rdram, ctx);
        goto after_9;
    // 0x80067708: nop

    after_9:
L_8006770C:
    // 0x8006770C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067710: lbu         $v1, -0x638D($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X638D);
    // 0x80067714: beq         $v1, $zero, L_8006774C
    if (ctx->r3 == 0) {
        // 0x80067718: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_8006774C;
    }
    // 0x80067718: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006771C: addiu       $v0, $v0, -0x6480
    ctx->r2 = ADD32(ctx->r2, -0X6480);
    // 0x80067720: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80067724: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80067728: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8006772C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80067730: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80067734: beq         $a0, $v0, L_80067750
    if (ctx->r4 == ctx->r2) {
        // 0x80067738: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80067750;
    }
    // 0x80067738: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8006773C: jal         0x8009B3CC
    // 0x80067740: nop

    isVoiceHandleActive(rdram, ctx);
        goto after_10;
    // 0x80067740: nop

    after_10:
    // 0x80067744: j           L_80067754
    // 0x80067748: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
        goto L_80067754;
    // 0x80067748: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_8006774C:
    // 0x8006774C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80067750:
    // 0x80067750: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_80067754:
    // 0x80067754: beq         $v0, $zero, L_80067808
    if (ctx->r2 == 0) {
        // 0x80067758: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80067808;
    }
    // 0x80067758: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006775C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80067760: lbu         $v1, -0x638D($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X638D);
    // 0x80067764: addiu       $v0, $v0, -0x6460
    ctx->r2 = ADD32(ctx->r2, -0X6460);
    // 0x80067768: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8006776C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067770: lbu         $v1, -0x1($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X1);
    // 0x80067774: lwc1        $f2, -0x637C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X637C);
    // 0x80067778: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x8006777C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80067780: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80067784: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067788: lwc1        $f2, -0x6384($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X6384);
    // 0x8006778C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80067790: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80067794: lwc1        $f2, -0x3848($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3848);
    // 0x80067798: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8006779C: nop

    // 0x800677A0: bc1tl       L_800677B8
    if (c1cs) {
        // 0x800677A4: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800677B8;
    }
    goto skip_2;
    // 0x800677A4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_2:
    // 0x800677A8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800677AC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800677B0: j           L_800677CC
    // 0x800677B4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
        goto L_800677CC;
    // 0x800677B4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_800677B8:
    // 0x800677B8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800677BC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800677C0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800677C4: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x800677C8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_800677CC:
    // 0x800677CC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800677D0: lbu         $v0, -0x638D($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X638D);
    // 0x800677D4: addiu       $v1, $v1, -0x6480
    ctx->r3 = ADD32(ctx->r3, -0X6480);
    // 0x800677D8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800677DC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800677E0: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x800677E4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800677E8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800677EC: beq         $v1, $v0, L_80067808
    if (ctx->r3 == ctx->r2) {
        // 0x800677F0: andi        $a1, $a1, 0xFF
        ctx->r5 = ctx->r5 & 0XFF;
            goto L_80067808;
    }
    // 0x800677F0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800677F4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x800677F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800677FC: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80067800: jal         0x8009B464
    // 0x80067804: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8009B464(rdram, ctx);
        goto after_11;
    // 0x80067804: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_11:
L_80067808:
    // 0x80067808: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8006780C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80067810: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80067814: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80067818: jr          $ra
    // 0x8006781C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8006781C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void resetSpeechSubsystem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067820: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067824: lbu         $v0, -0x638D($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X638D);
    // 0x80067828: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006782C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80067830: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80067834: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x80067838: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8006783C: sltiu       $v0, $v0, 0x8
    ctx->r2 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x80067840: beq         $v0, $zero, L_80067890
    if (ctx->r2 == 0) {
        // 0x80067844: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_80067890;
    }
    // 0x80067844: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80067848: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8006784C: addiu       $v1, $v1, -0x6480
    ctx->r3 = ADD32(ctx->r3, -0X6480);
    // 0x80067850: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80067854: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80067858: addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // 0x8006785C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80067860: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80067864: beq         $a0, $s1, L_80067894
    if (ctx->r4 == ctx->r17) {
        // 0x80067868: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80067894;
    }
    // 0x80067868: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006786C: jal         0x8009B3CC
    // 0x80067870: nop

    isVoiceHandleActive(rdram, ctx);
        goto after_0;
    // 0x80067870: nop

    after_0:
    // 0x80067874: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80067878: beql        $v0, $zero, L_80067890
    if (ctx->r2 == 0) {
        // 0x8006787C: sw          $s1, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r17;
            goto L_80067890;
    }
    goto skip_0;
    // 0x8006787C: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
    skip_0:
    // 0x80067880: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80067884: jal         0x8009B33C
    // 0x80067888: nop

    stopVoiceByHandle(rdram, ctx);
        goto after_1;
    // 0x80067888: nop

    after_1:
    // 0x8006788C: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
L_80067890:
    // 0x80067890: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_80067894:
    // 0x80067894: sb          $zero, -0x638F($v0)
    MEM_B(-0X638F, ctx->r2) = 0;
    // 0x80067898: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006789C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800678A0: sb          $zero, -0x6390($v0)
    MEM_B(-0X6390, ctx->r2) = 0;
    // 0x800678A4: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x800678A8: sb          $v0, -0x638E($v1)
    MEM_B(-0X638E, ctx->r3) = ctx->r2;
    // 0x800678AC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800678B0: sb          $zero, -0x638D($v0)
    MEM_B(-0X638D, ctx->r2) = 0;
    // 0x800678B4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800678B8: sw          $zero, -0x6388($v0)
    MEM_W(-0X6388, ctx->r2) = 0;
    // 0x800678BC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800678C0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800678C4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800678C8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800678CC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800678D0: sw          $zero, -0x6384($v0)
    MEM_W(-0X6384, ctx->r2) = 0;
    // 0x800678D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800678D8: sb          $v0, -0x6372($v1)
    MEM_B(-0X6372, ctx->r3) = ctx->r2;
    // 0x800678DC: jr          $ra
    // 0x800678E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800678E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void finalizeCurrentSpeechBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800678E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800678E8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800678EC: jal         0x8009BCC4
    // 0x800678F0: nop

    shutdownMusyXVoices(rdram, ctx);
        goto after_0;
    // 0x800678F0: nop

    after_0:
    // 0x800678F4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800678F8: lw          $a0, -0x648C($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X648C);
    // 0x800678FC: beq         $a0, $zero, L_80067914
    if (ctx->r4 == 0) {
        // 0x80067900: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80067914;
    }
    // 0x80067900: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067904: jal         0x80001C98
    // 0x80067908: nop

    rs_free(rdram, ctx);
        goto after_1;
    // 0x80067908: nop

    after_1:
    // 0x8006790C: j           L_80067928
    // 0x80067910: nop

        goto L_80067928;
    // 0x80067910: nop

L_80067914:
    // 0x80067914: lw          $a0, -0x76E0($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X76E0);
    // 0x80067918: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006791C: lw          $a1, -0x6490($v0)
    ctx->r5 = MEM_W(ctx->r2, -0X6490);
    // 0x80067920: jal         0x80004C70
    // 0x80067924: nop

    teardownAssetDma(rdram, ctx);
        goto after_2;
    // 0x80067924: nop

    after_2:
L_80067928:
    // 0x80067928: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8006792C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80067930: jr          $ra
    // 0x80067934: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80067934: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80067938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067938: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006793C: sb          $zero, -0x638F($v0)
    MEM_B(-0X638F, ctx->r2) = 0;
    // 0x80067940: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067944: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80067948: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8006794C: sb          $zero, -0x6390($v0)
    MEM_B(-0X6390, ctx->r2) = 0;
    // 0x80067950: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80067954: sb          $v0, -0x638E($v1)
    MEM_B(-0X638E, ctx->r3) = ctx->r2;
    // 0x80067958: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006795C: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80067960: lbu         $a2, -0x638D($a0)
    ctx->r6 = MEM_BU(ctx->r4, -0X638D);
    // 0x80067964: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80067968: lwc1        $f0, -0x3844($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3844);
    // 0x8006796C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80067970: sw          $zero, -0x6388($v0)
    MEM_W(-0X6388, ctx->r2) = 0;
    // 0x80067974: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80067978: sb          $zero, -0x638D($a0)
    MEM_B(-0X638D, ctx->r4) = 0;
    // 0x8006797C: sw          $zero, -0x6384($a1)
    MEM_W(-0X6384, ctx->r5) = 0;
    // 0x80067980: sb          $v0, -0x6374($v1)
    MEM_B(-0X6374, ctx->r3) = ctx->r2;
    // 0x80067984: sb          $a2, -0x638D($a0)
    MEM_B(-0X638D, ctx->r4) = ctx->r6;
    // 0x80067988: jr          $ra
    // 0x8006798C: swc1        $f0, -0x6384($a1)
    MEM_W(-0X6384, ctx->r5) = ctx->f0.u32l;
    return;
    // 0x8006798C: swc1        $f0, -0x6384($a1)
    MEM_W(-0X6384, ctx->r5) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_80067990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067990: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067994: sb          $zero, -0x6374($v0)
    MEM_B(-0X6374, ctx->r2) = 0;
    // 0x80067998: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006799C: jr          $ra
    // 0x800679A0: sb          $zero, -0x6372($v0)
    MEM_B(-0X6372, ctx->r2) = 0;
    return;
    // 0x800679A0: sb          $zero, -0x6372($v0)
    MEM_B(-0X6372, ctx->r2) = 0;
;}
RECOMP_FUNC void func_800679A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800679A4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800679A8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800679AC: lwc1        $f0, -0x3840($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3840);
    // 0x800679B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800679B4: sb          $v0, -0x6373($v1)
    MEM_B(-0X6373, ctx->r3) = ctx->r2;
    // 0x800679B8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800679BC: jr          $ra
    // 0x800679C0: swc1        $f0, -0x6384($v0)
    MEM_W(-0X6384, ctx->r2) = ctx->f0.u32l;
    return;
    // 0x800679C0: swc1        $f0, -0x6384($v0)
    MEM_W(-0X6384, ctx->r2) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_800679C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800679C4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800679C8: jr          $ra
    // 0x800679CC: sb          $zero, -0x6373($v0)
    MEM_B(-0X6373, ctx->r2) = 0;
    return;
    // 0x800679CC: sb          $zero, -0x6373($v0)
    MEM_B(-0X6373, ctx->r2) = 0;
;}
RECOMP_FUNC void func_800679D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800679D0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800679D4: lbu         $v1, -0x638D($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X638D);
    // 0x800679D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800679DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800679E0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800679E4: beq         $v1, $zero, L_80067A20
    if (ctx->r3 == 0) {
        // 0x800679E8: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80067A20;
    }
    // 0x800679E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800679EC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800679F0: addiu       $v0, $v0, -0x6480
    ctx->r2 = ADD32(ctx->r2, -0X6480);
    // 0x800679F4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800679F8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800679FC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80067A00: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80067A04: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80067A08: beq         $a0, $v0, L_80067A24
    if (ctx->r4 == ctx->r2) {
        // 0x80067A0C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80067A24;
    }
    // 0x80067A0C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80067A10: jal         0x8009B3CC
    // 0x80067A14: nop

    isVoiceHandleActive(rdram, ctx);
        goto after_0;
    // 0x80067A14: nop

    after_0:
    // 0x80067A18: j           L_80067A28
    // 0x80067A1C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
        goto L_80067A28;
    // 0x80067A1C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_80067A20:
    // 0x80067A20: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80067A24:
    // 0x80067A24: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_80067A28:
    // 0x80067A28: beq         $v0, $zero, L_80067A70
    if (ctx->r2 == 0) {
        // 0x80067A2C: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80067A70;
    }
    // 0x80067A2C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80067A30: beq         $s0, $zero, L_80067A68
    if (ctx->r16 == 0) {
        // 0x80067A34: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_80067A68;
    }
    // 0x80067A34: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80067A38: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067A3C: lbu         $v0, -0x638D($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X638D);
    // 0x80067A40: addiu       $v1, $v1, -0x6480
    ctx->r3 = ADD32(ctx->r3, -0X6480);
    // 0x80067A44: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80067A48: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80067A4C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80067A50: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80067A54: jal         0x8009B8A8
    // 0x80067A58: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8009B8A8(rdram, ctx);
        goto after_1;
    // 0x80067A58: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x80067A5C: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80067A60: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80067A64: swc1        $f2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f2.u32l;
L_80067A68:
    // 0x80067A68: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067A6C: lhu         $v0, -0x638C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X638C);
L_80067A70:
    // 0x80067A70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80067A74: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80067A78: jr          $ra
    // 0x80067A7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80067A7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void isSpeechBusyOrQueued(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067A80: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067A84: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80067A88: lbu         $a0, -0x638F($v0)
    ctx->r4 = MEM_BU(ctx->r2, -0X638F);
    // 0x80067A8C: lbu         $v0, -0x6390($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X6390);
    // 0x80067A90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067A94: bne         $a0, $v0, L_80067AEC
    if (ctx->r4 != ctx->r2) {
        // 0x80067A98: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80067AEC;
    }
    // 0x80067A98: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80067A9C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067AA0: lbu         $v1, -0x638D($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X638D);
    // 0x80067AA4: beq         $v1, $zero, L_80067ADC
    if (ctx->r3 == 0) {
        // 0x80067AA8: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80067ADC;
    }
    // 0x80067AA8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067AAC: addiu       $v0, $v0, -0x6480
    ctx->r2 = ADD32(ctx->r2, -0X6480);
    // 0x80067AB0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80067AB4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80067AB8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80067ABC: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80067AC0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80067AC4: beq         $a0, $v0, L_80067AE0
    if (ctx->r4 == ctx->r2) {
        // 0x80067AC8: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80067AE0;
    }
    // 0x80067AC8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80067ACC: jal         0x8009B3CC
    // 0x80067AD0: nop

    isVoiceHandleActive(rdram, ctx);
        goto after_0;
    // 0x80067AD0: nop

    after_0:
    // 0x80067AD4: j           L_80067AE0
    // 0x80067AD8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
        goto L_80067AE0;
    // 0x80067AD8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_80067ADC:
    // 0x80067ADC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80067AE0:
    // 0x80067AE0: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80067AE4: beq         $v1, $zero, L_80067AF0
    if (ctx->r3 == 0) {
        // 0x80067AE8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80067AF0;
    }
    // 0x80067AE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80067AEC:
    // 0x80067AEC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80067AF0:
    // 0x80067AF0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80067AF4: jr          $ra
    // 0x80067AF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80067AF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
