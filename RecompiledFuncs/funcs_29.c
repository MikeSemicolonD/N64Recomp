#include "recomp.h"
#include "funcs.h"
#include <stdio.h>

RECOMP_FUNC void func_800AE518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE518: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800AE51C: sw          $s2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r18;
    // 0x800AE520: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800AE524: sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
    // 0x800AE528: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800AE52C: addiu       $v1, $sp, 0x10
    ctx->r3 = ADD32(ctx->r29, 0X10);
    // 0x800AE530: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800AE534: addiu       $v0, $v0, 0x5B88
    ctx->r2 = ADD32(ctx->r2, 0X5B88);
    // 0x800AE538: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x800AE53C: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x800AE540: sw          $s4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r20;
    // 0x800AE544: sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // 0x800AE548: sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
L_800AE54C:
    // 0x800AE54C: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800AE550: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800AE554: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800AE558: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800AE55C: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800AE560: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800AE564: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x800AE568: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x800AE56C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800AE570: bne         $v0, $a0, L_800AE54C
    if (ctx->r2 != ctx->r4) {
        // 0x800AE574: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800AE54C;
    }
    // 0x800AE574: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800AE578: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800AE57C: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800AE580: addiu       $v1, $sp, 0x38
    ctx->r3 = ADD32(ctx->r29, 0X38);
    // 0x800AE584: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800AE588: addiu       $v0, $v0, 0x5BAC
    ctx->r2 = ADD32(ctx->r2, 0X5BAC);
    // 0x800AE58C: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
L_800AE590:
    // 0x800AE590: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800AE594: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800AE598: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800AE59C: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800AE5A0: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800AE5A4: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800AE5A8: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x800AE5AC: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x800AE5B0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800AE5B4: bne         $v0, $a0, L_800AE590
    if (ctx->r2 != ctx->r4) {
        // 0x800AE5B8: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800AE590;
    }
    // 0x800AE5B8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800AE5BC: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x800AE5C0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x800AE5C4: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800AE5C8: jal         0x80001ACC
    // 0x800AE5CC: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x800AE5CC: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    after_0:
    // 0x800AE5D0: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x800AE5D4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800AE5D8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AE5DC: jal         0x800078E0
    // 0x800AE5E0: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x800AE5E0: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    after_1:
    // 0x800AE5E4: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // 0x800AE5E8: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x800AE5EC: sh          $v0, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r2;
    // 0x800AE5F0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800AE5F4: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800AE5F8: addu        $a0, $s2, $v0
    ctx->r4 = ADD32(ctx->r18, ctx->r2);
    // 0x800AE5FC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800AE600: div         $zero, $a0, $v0
    if (S32(ctx->r2) != 0) { lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r2))); } else { lo = 0; hi = S32(ctx->r4); }
    // 0x800AE604: bne         $v0, $zero, L_800AE610
    if (ctx->r2 != 0) {
        // 0x800AE608: nop
    
            goto L_800AE610;
    }
    // 0x800AE608: nop

    // 0x800AE60C: break       7
    do_break(2148197900);
L_800AE610:
    // 0x800AE610: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AE614: bne         $v0, $at, L_800AE628
    if (ctx->r2 != ctx->r1) {
        // 0x800AE618: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AE628;
    }
    // 0x800AE618: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AE61C: bne         $a0, $at, L_800AE628
    if (ctx->r4 != ctx->r1) {
        // 0x800AE620: nop
    
            goto L_800AE628;
    }
    // 0x800AE620: nop

    // 0x800AE624: break       6
    do_break(2148197924);
L_800AE628:
    // 0x800AE628: mflo        $a0
    ctx->r4 = lo;
    // 0x800AE62C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x800AE630: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x800AE634: sh          $v0, 0x2($s3)
    MEM_H(0X2, ctx->r19) = ctx->r2;
    // 0x800AE638: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x800AE63C: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800AE640: addu        $v0, $s1, $v1
    ctx->r2 = ADD32(ctx->r17, ctx->r3);
    // 0x800AE644: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800AE648: div         $zero, $v0, $v1
    if (S32(ctx->r3) != 0) { lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3))); } else { lo = 0; hi = S32(ctx->r2); }
    // 0x800AE64C: bne         $v1, $zero, L_800AE658
    if (ctx->r3 != 0) {
        // 0x800AE650: nop
    
            goto L_800AE658;
    }
    // 0x800AE650: nop

    // 0x800AE654: break       7
    do_break(2148197972);
L_800AE658:
    // 0x800AE658: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AE65C: bne         $v1, $at, L_800AE670
    if (ctx->r3 != ctx->r1) {
        // 0x800AE660: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AE670;
    }
    // 0x800AE660: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AE664: bne         $v0, $at, L_800AE670
    if (ctx->r2 != ctx->r1) {
        // 0x800AE668: nop
    
            goto L_800AE670;
    }
    // 0x800AE668: nop

    // 0x800AE66C: break       6
    do_break(2148197996);
L_800AE670:
    // 0x800AE670: mflo        $v0
    ctx->r2 = lo;
    // 0x800AE674: nop

    // 0x800AE678: nop

    // 0x800AE67C: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE680: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x800AE684: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x800AE688: sh          $v1, 0x4($s3)
    MEM_H(0X4, ctx->r19) = ctx->r3;
    // 0x800AE68C: sw          $a0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r4;
    // 0x800AE690: mflo        $v0
    ctx->r2 = lo;
    // 0x800AE694: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x800AE698: jal         0x80001ACC
    // 0x800AE69C: sw          $v0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r2;
    rs_malloc(rdram, ctx);
        goto after_2;
    // 0x800AE69C: sw          $v0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r2;
    after_2:
    // 0x800AE6A0: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x800AE6A4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x800AE6A8: jal         0x80001ACC
    // 0x800AE6AC: sw          $v0, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r2;
    rs_malloc(rdram, ctx);
        goto after_3;
    // 0x800AE6AC: sw          $v0, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r2;
    after_3:
    // 0x800AE6B0: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // 0x800AE6B4: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800AE6B8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AE6BC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x800AE6C0: jal         0x800078E0
    // 0x800AE6C4: sw          $s4, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r20;
    rs_memset(rdram, ctx);
        goto after_4;
    // 0x800AE6C4: sw          $s4, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r20;
    after_4:
    // 0x800AE6C8: lw          $a0, 0x8($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X8);
    // 0x800AE6CC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x800AE6D0: jal         0x80001ACC
    // 0x800AE6D4: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    rs_malloc(rdram, ctx);
        goto after_5;
    // 0x800AE6D4: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    after_5:
    // 0x800AE6D8: sw          $v0, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r2;
    // 0x800AE6DC: lhu         $v1, 0x0($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0X0);
    // 0x800AE6E0: lhu         $v0, 0x2($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X2);
    // 0x800AE6E4: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE6E8: mflo        $t3
    ctx->r11 = lo;
    // 0x800AE6EC: lhu         $s0, 0x4($s3)
    ctx->r16 = MEM_HU(ctx->r19, 0X4);
    // 0x800AE6F0: nop

    // 0x800AE6F4: mult        $t3, $s0
    result = S64(S32(ctx->r11)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE6F8: sh          $v1, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r3;
    // 0x800AE6FC: lhu         $v0, 0x2($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X2);
    // 0x800AE700: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x800AE704: sh          $v0, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r2;
    // 0x800AE708: mflo        $s0
    ctx->r16 = lo;
    // 0x800AE70C: srl         $v0, $s0, 31
    ctx->r2 = S32(U32(ctx->r16) >> 31);
    // 0x800AE710: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x800AE714: sra         $s0, $s0, 1
    ctx->r16 = S32(SIGNED(ctx->r16) >> 1);
    // 0x800AE718: jal         0x80001ACC
    // 0x800AE71C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    rs_malloc(rdram, ctx);
        goto after_6;
    // 0x800AE71C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // 0x800AE720: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800AE724: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800AE728: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800AE72C: jal         0x800078E0
    // 0x800AE730: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    rs_memset(rdram, ctx);
        goto after_7;
    // 0x800AE730: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_7:
    // 0x800AE734: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800AE738: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800AE73C: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x800AE740: lbu         $v0, -0x91C($a2)
    ctx->r2 = MEM_BU(ctx->r6, -0X91C);
    // 0x800AE744: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x800AE748: addiu       $v0, $v0, 0x41
    ctx->r2 = ADD32(ctx->r2, 0X41);
    // 0x800AE74C: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // 0x800AE750: lbu         $v0, -0x91C($a2)
    ctx->r2 = MEM_BU(ctx->r6, -0X91C);
    // 0x800AE754: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AE758: addiu       $v0, $v0, 0x41
    ctx->r2 = ADD32(ctx->r2, 0X41);
    // 0x800AE75C: jal         0x80022B90
    // 0x800AE760: sb          $v0, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r2;
    func_80022B90(rdram, ctx);
        goto after_8;
    // 0x800AE760: sb          $v0, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r2;
    after_8:
    // 0x800AE764: lw          $v1, 0x14($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X14);
    // 0x800AE768: lw          $a0, 0xC($s4)
    ctx->r4 = MEM_W(ctx->r20, 0XC);
    // 0x800AE76C: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800AE770: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x800AE774: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800AE778: jal         0x80001C98
    // 0x800AE77C: nop

    rs_free(rdram, ctx);
        goto after_9;
    // 0x800AE77C: nop

    after_9:
    // 0x800AE780: lhu         $v0, 0x0($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X0);
    // 0x800AE784: div         $zero, $s2, $v0
    if (S32(ctx->r2) != 0) { lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2))); } else { lo = 0; hi = S32(ctx->r18); }
    // 0x800AE788: bne         $v0, $zero, L_800AE794
    if (ctx->r2 != 0) {
        // 0x800AE78C: nop
    
            goto L_800AE794;
    }
    // 0x800AE78C: nop

    // 0x800AE790: break       7
    do_break(2148198288);
L_800AE794:
    // 0x800AE794: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AE798: bne         $v0, $at, L_800AE7AC
    if (ctx->r2 != ctx->r1) {
        // 0x800AE79C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AE7AC;
    }
    // 0x800AE79C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AE7A0: bne         $s2, $at, L_800AE7AC
    if (ctx->r18 != ctx->r1) {
        // 0x800AE7A4: nop
    
            goto L_800AE7AC;
    }
    // 0x800AE7A4: nop

    // 0x800AE7A8: break       6
    do_break(2148198312);
L_800AE7AC:
    // 0x800AE7AC: mflo        $s2
    ctx->r18 = lo;
    // 0x800AE7B0: sh          $s2, 0x8($s4)
    MEM_H(0X8, ctx->r20) = ctx->r18;
    // 0x800AE7B4: lhu         $v0, 0x2($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X2);
    // 0x800AE7B8: div         $zero, $s1, $v0
    if (S32(ctx->r2) != 0) { lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r2))); } else { lo = 0; hi = S32(ctx->r17); }
    // 0x800AE7BC: bne         $v0, $zero, L_800AE7C8
    if (ctx->r2 != 0) {
        // 0x800AE7C0: nop
    
            goto L_800AE7C8;
    }
    // 0x800AE7C0: nop

    // 0x800AE7C4: break       7
    do_break(2148198340);
L_800AE7C8:
    // 0x800AE7C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AE7CC: bne         $v0, $at, L_800AE7E0
    if (ctx->r2 != ctx->r1) {
        // 0x800AE7D0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AE7E0;
    }
    // 0x800AE7D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AE7D4: bne         $s1, $at, L_800AE7E0
    if (ctx->r17 != ctx->r1) {
        // 0x800AE7D8: nop
    
            goto L_800AE7E0;
    }
    // 0x800AE7D8: nop

    // 0x800AE7DC: break       6
    do_break(2148198364);
L_800AE7E0:
    // 0x800AE7E0: mflo        $s1
    ctx->r17 = lo;
    // 0x800AE7E4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AE7E8: lwc1        $f0, 0x5BE0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5BE0);
    // 0x800AE7EC: swc1        $f0, 0x28($s4)
    MEM_W(0X28, ctx->r20) = ctx->f0.u32l;
    // 0x800AE7F0: swc1        $f0, 0x24($s4)
    MEM_W(0X24, ctx->r20) = ctx->f0.u32l;
    // 0x800AE7F4: sh          $s1, 0xA($s4)
    MEM_H(0XA, ctx->r20) = ctx->r17;
    // 0x800AE7F8: lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X8);
    // 0x800AE7FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800AE800: sltu        $v0, $a1, $v0
    ctx->r2 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x800AE804: beq         $v0, $zero, L_800AE844
    if (ctx->r2 == 0) {
        // 0x800AE808: lui         $v1, 0x800B
        ctx->r3 = S32(0X800B << 16);
            goto L_800AE844;
    }
    // 0x800AE808: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x800AE80C: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
L_800AE810:
    // 0x800AE810: lw          $v0, 0xC($s4)
    ctx->r2 = MEM_W(ctx->r20, 0XC);
    // 0x800AE814: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x800AE818: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x800AE81C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800AE820: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x800AE824: lw          $v0, 0x14($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X14);
    // 0x800AE828: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800AE82C: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x800AE830: lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X8);
    // 0x800AE834: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800AE838: sltu        $v0, $a1, $v0
    ctx->r2 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x800AE83C: bne         $v0, $zero, L_800AE810
    if (ctx->r2 != 0) {
        // 0x800AE840: lui         $v1, 0x800B
        ctx->r3 = S32(0X800B << 16);
            goto L_800AE810;
    }
    // 0x800AE840: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
L_800AE844:
    // 0x800AE844: lbu         $a1, -0x91C($v1)
    ctx->r5 = MEM_BU(ctx->r3, -0X91C);
    // 0x800AE848: addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
    // 0x800AE84C: addiu       $a0, $a1, 0x1
    ctx->r4 = ADD32(ctx->r5, 0X1);
    // 0x800AE850: sb          $a0, -0x91C($v1)
    MEM_B(-0X91C, ctx->r3) = ctx->r4;
    // 0x800AE854: sb          $a1, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r5;
    // 0x800AE858: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    // 0x800AE85C: lw          $s4, 0x80($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X80);
    // 0x800AE860: lw          $s3, 0x7C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X7C);
    // 0x800AE864: lw          $s2, 0x78($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X78);
    // 0x800AE868: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x800AE86C: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x800AE870: jr          $ra
    // 0x800AE874: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x800AE874: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void hangarGenerateSecondaryWeaponString(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE530: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800AE534: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800AE538: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800AE53C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800AE540: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AE544: lbu         $a2, -0x2930($v0)
    ctx->r6 = MEM_BU(ctx->r2, -0X2930);
    // 0x800AE548: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800AE54C: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x800AE550: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800AE554: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800AE558: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800AE55C: addiu       $t3, $v0, 0x5840
    ctx->r11 = ADD32(ctx->r2, 0X5840);
    // 0x800AE560: lwl         $t0, 0x0($t3)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r11, 0X0);
    // 0x800AE564: lwr         $t0, 0x3($t3)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r11, 0X3);
    // 0x800AE568: lwl         $t1, 0x4($t3)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r11, 0X4);
    // 0x800AE56C: lwr         $t1, 0x7($t3)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r11, 0X7);
    // 0x800AE570: lwl         $t2, 0x8($t3)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r11, 0X8);
    // 0x800AE574: lwr         $t2, 0xB($t3)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r11, 0XB);
    // 0x800AE578: swl         $t0, 0x18($sp)
    do_swl(rdram, 0X18, ctx->r29, ctx->r8);
    // 0x800AE57C: swr         $t0, 0x1B($sp)
    do_swr(rdram, 0X1B, ctx->r29, ctx->r8);
    // 0x800AE580: swl         $t1, 0x1C($sp)
    do_swl(rdram, 0X1C, ctx->r29, ctx->r9);
    // 0x800AE584: swr         $t1, 0x1F($sp)
    do_swr(rdram, 0X1F, ctx->r29, ctx->r9);
    // 0x800AE588: swl         $t2, 0x20($sp)
    do_swl(rdram, 0X20, ctx->r29, ctx->r10);
    // 0x800AE58C: swr         $t2, 0x23($sp)
    do_swr(rdram, 0X23, ctx->r29, ctx->r10);
    // 0x800AE590: lwl         $t0, 0xC($t3)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r11, 0XC);
    // 0x800AE594: lwr         $t0, 0xF($t3)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r11, 0XF);
    // 0x800AE598: lwl         $t1, 0x10($t3)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r11, 0X10);
    // 0x800AE59C: lwr         $t1, 0x13($t3)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r11, 0X13);
    // 0x800AE5A0: swl         $t0, 0x24($sp)
    do_swl(rdram, 0X24, ctx->r29, ctx->r8);
    // 0x800AE5A4: swr         $t0, 0x27($sp)
    do_swr(rdram, 0X27, ctx->r29, ctx->r8);
    // 0x800AE5A8: swl         $t1, 0x28($sp)
    do_swl(rdram, 0X28, ctx->r29, ctx->r9);
    // 0x800AE5AC: swr         $t1, 0x2B($sp)
    do_swr(rdram, 0X2B, ctx->r29, ctx->r9);
    // 0x800AE5B0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AE5B4: lbu         $s2, -0x3918($v0)
    ctx->r18 = MEM_BU(ctx->r2, -0X3918);
    // 0x800AE5B8: jal         0x800C6728
    // 0x800AE5BC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    getSecondaryWeaponForLevelAndCraft(rdram, ctx);
        goto after_0;
    // 0x800AE5BC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_0:
    // 0x800AE5C0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800AE5C4: andi        $v1, $s0, 0xFF
    ctx->r3 = ctx->r16 & 0XFF;
    // 0x800AE5C8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800AE5CC: beq         $v1, $v0, L_800AE6BC
    if (ctx->r3 == ctx->r2) {
        // 0x800AE5D0: addiu       $v0, $s0, -0x2
        ctx->r2 = ADD32(ctx->r16, -0X2);
            goto L_800AE6BC;
    }
    // 0x800AE5D0: addiu       $v0, $s0, -0x2
    ctx->r2 = ADD32(ctx->r16, -0X2);
    // 0x800AE5D4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800AE5D8: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800AE5DC: beq         $v0, $zero, L_800AE5F4
    if (ctx->r2 == 0) {
        // 0x800AE5E0: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800AE5F4;
    }
    // 0x800AE5E0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AE5E4: lw          $v0, 0xB4C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB4C);
    // 0x800AE5E8: andi        $v0, $v0, 0x400
    ctx->r2 = ctx->r2 & 0X400;
    // 0x800AE5EC: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x800AE5F0: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_800AE5F4:
    // 0x800AE5F4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800AE5F8: bne         $v1, $v0, L_800AE618
    if (ctx->r3 != ctx->r2) {
        // 0x800AE5FC: andi        $v1, $s0, 0xFF
        ctx->r3 = ctx->r16 & 0XFF;
            goto L_800AE618;
    }
    // 0x800AE5FC: andi        $v1, $s0, 0xFF
    ctx->r3 = ctx->r16 & 0XFF;
    // 0x800AE600: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AE604: lw          $v0, 0xB4C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB4C);
    // 0x800AE608: andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // 0x800AE60C: bnel        $v0, $zero, L_800AE618
    if (ctx->r2 != 0) {
        // 0x800AE610: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_800AE618;
    }
    goto skip_0;
    // 0x800AE610: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    skip_0:
    // 0x800AE614: andi        $v1, $s0, 0xFF
    ctx->r3 = ctx->r16 & 0XFF;
L_800AE618:
    // 0x800AE618: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800AE61C: bne         $v1, $v0, L_800AE63C
    if (ctx->r3 != ctx->r2) {
        // 0x800AE620: andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
            goto L_800AE63C;
    }
    // 0x800AE620: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800AE624: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AE628: lw          $v0, 0xB4C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB4C);
    // 0x800AE62C: andi        $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 & 0X1000;
    // 0x800AE630: bnel        $v0, $zero, L_800AE638
    if (ctx->r2 != 0) {
        // 0x800AE634: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_800AE638;
    }
    goto skip_1;
    // 0x800AE634: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    skip_1:
L_800AE638:
    // 0x800AE638: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
L_800AE63C:
    // 0x800AE63C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800AE640: addiu       $v1, $sp, 0x18
    ctx->r3 = ADD32(ctx->r29, 0X18);
    // 0x800AE644: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800AE648: lbu         $s0, 0x1($v1)
    ctx->r16 = MEM_BU(ctx->r3, 0X1);
    // 0x800AE64C: jal         0x8005589C
    // 0x800AE650: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    getGameOrFrontText(rdram, ctx);
        goto after_1;
    // 0x800AE650: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    after_1:
    // 0x800AE654: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x800AE658: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x800AE65C: beq         $v0, $zero, L_800AE674
    if (ctx->r2 == 0) {
        // 0x800AE660: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_800AE674;
    }
    // 0x800AE660: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800AE664: jal         0x8005589C
    // 0x800AE668: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    getGameOrFrontText(rdram, ctx);
        goto after_2;
    // 0x800AE668: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    after_2:
    // 0x800AE66C: j           L_800AE678
    // 0x800AE670: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
        goto L_800AE678;
    // 0x800AE670: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_800AE674:
    // 0x800AE674: addiu       $s1, $v0, 0x514C
    ctx->r17 = ADD32(ctx->r2, 0X514C);
L_800AE678:
    // 0x800AE678: jal         0x8005589C
    // 0x800AE67C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    getGameOrFrontText(rdram, ctx);
        goto after_3;
    // 0x800AE67C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_3:
    // 0x800AE680: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800AE684: andi        $v1, $s2, 0xFF
    ctx->r3 = ctx->r18 & 0XFF;
    // 0x800AE688: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800AE68C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800AE690: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800AE694: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800AE698: addiu       $a0, $a0, -0x2AC0
    ctx->r4 = ADD32(ctx->r4, -0X2AC0);
    // 0x800AE69C: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // 0x800AE6A0: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800AE6A4: addiu       $a1, $a1, 0x5854
    ctx->r5 = ADD32(ctx->r5, 0X5854);
    // 0x800AE6A8: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x800AE6AC: jal         0x80033CC4
    // 0x800AE6B0: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    sprintf_recomp(rdram, ctx);
        goto after_4;
    // 0x800AE6B0: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    after_4:
    // 0x800AE6B4: j           L_800AE704
    // 0x800AE6B8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
        goto L_800AE704;
    // 0x800AE6B8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
L_800AE6BC:
    // 0x800AE6BC: jal         0x8005589C
    // 0x800AE6C0: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    getGameOrFrontText(rdram, ctx);
        goto after_5;
    // 0x800AE6C0: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    after_5:
    // 0x800AE6C4: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    // 0x800AE6C8: jal         0x8005589C
    // 0x800AE6CC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    getGameOrFrontText(rdram, ctx);
        goto after_6;
    // 0x800AE6CC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_6:
    // 0x800AE6D0: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    // 0x800AE6D4: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x800AE6D8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800AE6DC: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800AE6E0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800AE6E4: addiu       $a0, $a0, -0x2AC0
    ctx->r4 = ADD32(ctx->r4, -0X2AC0);
    // 0x800AE6E8: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    // 0x800AE6EC: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800AE6F0: addiu       $a1, $a1, 0x585C
    ctx->r5 = ADD32(ctx->r5, 0X585C);
    // 0x800AE6F4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800AE6F8: jal         0x80033CC4
    // 0x800AE6FC: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    sprintf_recomp(rdram, ctx);
        goto after_7;
    // 0x800AE6FC: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    after_7:
    // 0x800AE700: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
L_800AE704:
    // 0x800AE704: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800AE708: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x800AE70C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800AE710: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x800AE714: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AE718: addiu       $v0, $v0, -0x2AC0
    ctx->r2 = ADD32(ctx->r2, -0X2AC0);
    // 0x800AE71C: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800AE720: lbu         $v1, -0x3918($a1)
    ctx->r3 = MEM_BU(ctx->r5, -0X3918);
    // 0x800AE724: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x800AE728: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800AE72C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800AE730: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800AE734: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800AE738: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800AE73C: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x800AE740: sb          $v1, -0x3918($a1)
    MEM_B(-0X3918, ctx->r5) = ctx->r3;
    // 0x800AE744: jr          $ra
    // 0x800AE748: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800AE748: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800AE5C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE5C4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800AE5C8: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800AE5CC: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800AE5D0: sdc1        $f28, 0x60($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X60, ctx->r29);
    // 0x800AE5D4: mtc1        $a1, $f28
    ctx->f28.u32l = ctx->r5;
    // 0x800AE5D8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AE5DC: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800AE5E0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800AE5E4: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800AE5E8: sdc1        $f26, 0x58($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X58, ctx->r29);
    // 0x800AE5EC: sdc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X50, ctx->r29);
    // 0x800AE5F0: sdc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X48, ctx->r29);
    // 0x800AE5F4: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x800AE5F8: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800AE5FC: lwc1        $f2, -0x4870($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X4870);
    // 0x800AE600: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800AE604: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800AE608: nop

    // 0x800AE60C: bc1f        L_800AE618
    if (!c1cs) {
        // 0x800AE610: addiu       $s2, $s1, 0x4
        ctx->r18 = ADD32(ctx->r17, 0X4);
            goto L_800AE618;
    }
    // 0x800AE610: addiu       $s2, $s1, 0x4
    ctx->r18 = ADD32(ctx->r17, 0X4);
    // 0x800AE614: sub.s       $f20, $f2, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f2.fl - ctx->f0.fl;
L_800AE618:
    // 0x800AE618: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AE61C: lwc1        $f2, -0x486C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X486C);
    // 0x800AE620: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800AE624: nop

    // 0x800AE628: bc1tl       L_800AE630
    if (c1cs) {
        // 0x800AE62C: sub.s       $f20, $f0, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800AE630;
    }
    goto skip_0;
    // 0x800AE62C: sub.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f2.fl;
    skip_0:
L_800AE630:
    // 0x800AE630: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AE634: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800AE638: lwc1        $f2, -0x4868($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X4868);
    // 0x800AE63C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800AE640: nop

    // 0x800AE644: bc1tl       L_800AE64C
    if (c1cs) {
        // 0x800AE648: sub.s       $f20, $f2, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_800AE64C;
    }
    goto skip_1;
    // 0x800AE648: sub.s       $f20, $f2, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f2.fl - ctx->f0.fl;
    skip_1:
L_800AE64C:
    // 0x800AE64C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AE650: lwc1        $f2, -0x4864($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X4864);
    // 0x800AE654: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800AE658: nop

    // 0x800AE65C: bc1tl       L_800AE664
    if (c1cs) {
        // 0x800AE660: sub.s       $f20, $f0, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800AE664;
    }
    goto skip_2;
    // 0x800AE660: sub.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f2.fl;
    skip_2:
L_800AE664:
    // 0x800AE664: lw          $v0, 0xB8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XB8);
    // 0x800AE668: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800AE66C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800AE670: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800AE674: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800AE678: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800AE67C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800AE680: addiu       $v0, $v0, -0x7FF4
    ctx->r2 = ADD32(ctx->r2, -0X7FF4);
    // 0x800AE684: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800AE688: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800AE68C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800AE690: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800AE694: lwc1        $f0, 0xC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800AE698: addiu       $s0, $sp, 0x20
    ctx->r16 = ADD32(ctx->r29, 0X20);
    // 0x800AE69C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800AE6A0: lwc1        $f2, 0x18($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X18);
    // 0x800AE6A4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AE6A8: lwc1        $f0, 0x543C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X543C);
    // 0x800AE6AC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800AE6B0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800AE6B4: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800AE6B8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x800AE6BC: jal         0x8001CFE8
    // 0x800AE6C0: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    func_8001CFE8(rdram, ctx);
        goto after_0;
    // 0x800AE6C0: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x800AE6C4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AE6C8: lwc1        $f26, 0x5440($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X5440);
    // 0x800AE6CC: jal         0x8001C400
    // 0x800AE6D0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8001C400(rdram, ctx);
        goto after_1;
    // 0x800AE6D0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x800AE6D4: mul.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x800AE6D8: abs.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = fabsf(ctx->f0.fl);
    // 0x800AE6DC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800AE6E0: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x800AE6E4: nop

    // 0x800AE6E8: bc1f        L_800AE7F8
    if (!c1cs) {
        // 0x800AE6EC: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_800AE7F8;
    }
    // 0x800AE6EC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800AE6F0: lhu         $v0, 0x180($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X180);
    // 0x800AE6F4: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800AE6F8: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // 0x800AE6FC: sh          $v0, 0x180($s1)
    MEM_H(0X180, ctx->r17) = ctx->r2;
    // 0x800AE700: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AE704: lwc1        $f0, 0x7CE8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X7CE8);
    // 0x800AE708: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800AE70C: addiu       $v0, $v0, 0x7CE8
    ctx->r2 = ADD32(ctx->r2, 0X7CE8);
    // 0x800AE710: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800AE714: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800AE718: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    // 0x800AE71C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800AE720: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800AE724: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800AE728: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800AE72C: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800AE730: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x800AE734: jal         0x800AA350
    // 0x800AE738: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    func_800AA350(rdram, ctx);
        goto after_2;
    // 0x800AE738: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x800AE73C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800AE740: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x800AE744: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x800AE748: lw          $t0, 0x18($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X18);
    // 0x800AE74C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800AE750: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800AE754: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800AE758: jal         0x800AA350
    // 0x800AE75C: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    func_800AA350(rdram, ctx);
        goto after_3;
    // 0x800AE75C: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    after_3:
    // 0x800AE760: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800AE764: jal         0x8001CFE8
    // 0x800AE768: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8001CFE8(rdram, ctx);
        goto after_4;
    // 0x800AE768: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_4:
    // 0x800AE76C: lwc1        $f6, 0x10($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800AE770: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800AE774: mul.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800AE778: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800AE77C: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800AE780: mul.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800AE784: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AE788: lwc1        $f2, 0x5444($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5444);
    // 0x800AE78C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x800AE790: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800AE794: nop

    // 0x800AE798: bc1f        L_800AE804
    if (!c1cs) {
        // 0x800AE79C: sub.s       $f20, $f6, $f4
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f6.fl - ctx->f4.fl;
            goto L_800AE804;
    }
    // 0x800AE79C: sub.s       $f20, $f6, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800AE7A0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AE7A4: lwc1        $f0, 0x5448($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5448);
    // 0x800AE7A8: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    // 0x800AE7AC: nop

    // 0x800AE7B0: bc1f        L_800AE804
    if (!c1cs) {
        // 0x800AE7B4: nop
    
            goto L_800AE804;
    }
    // 0x800AE7B4: nop

    // 0x800AE7B8: jal         0x8001C400
    // 0x800AE7BC: nop

    func_8001C400(rdram, ctx);
        goto after_5;
    // 0x800AE7BC: nop

    after_5:
    // 0x800AE7C0: mul.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x800AE7C4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AE7C8: lwc1        $f2, 0x544C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X544C);
    // 0x800AE7CC: c.lt.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
    // 0x800AE7D0: nop

    // 0x800AE7D4: bc1f        L_800AE7E8
    if (!c1cs) {
        // 0x800AE7D8: sub.s       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_800AE7E8;
    }
    // 0x800AE7D8: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800AE7DC: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x800AE7E0: j           L_800AE804
    // 0x800AE7E4: swc1        $f0, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f0.u32l;
        goto L_800AE804;
    // 0x800AE7E4: swc1        $f0, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f0.u32l;
L_800AE7E8:
    // 0x800AE7E8: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x800AE7EC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800AE7F0: j           L_800AE804
    // 0x800AE7F4: swc1        $f0, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f0.u32l;
        goto L_800AE804;
    // 0x800AE7F4: swc1        $f0, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f0.u32l;
L_800AE7F8:
    // 0x800AE7F8: lhu         $v0, 0x180($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X180);
    // 0x800AE7FC: andi        $v0, $v0, 0xFFFD
    ctx->r2 = ctx->r2 & 0XFFFD;
    // 0x800AE800: sh          $v0, 0x180($s1)
    MEM_H(0X180, ctx->r17) = ctx->r2;
L_800AE804:
    // 0x800AE804: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800AE808: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800AE80C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800AE810: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800AE814: ldc1        $f28, 0x60($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X60);
    // 0x800AE818: ldc1        $f26, 0x58($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X58);
    // 0x800AE81C: ldc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X50);
    // 0x800AE820: ldc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X48);
    // 0x800AE824: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x800AE828: jr          $ra
    // 0x800AE82C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800AE82C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_800AE74C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE74C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AE750: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800AE754: jal         0x8008DA00
    // 0x800AE758: nop

    func_8008DA00(rdram, ctx);
        goto after_0;
    // 0x800AE758: nop

    after_0:
L_800AE75C:
    // 0x800AE75C: jal         0x8008E57C
    // 0x800AE760: nop

    func_8008E57C(rdram, ctx);
        goto after_1;
    // 0x800AE760: nop

    after_1:
    // 0x800AE764: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800AE768: beq         $v0, $zero, L_800AE75C
    if (ctx->r2 == 0) {
        // 0x800AE76C: nop
    
            goto L_800AE75C;
    }
    // 0x800AE76C: nop

    // 0x800AE770: jal         0x8000BF60
    // 0x800AE774: nop

    func_8000BF60(rdram, ctx);
        goto after_2;
    // 0x800AE774: nop

    after_2:
    // 0x800AE778: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AE77C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800AE780: lw          $a0, -0x2998($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X2998);
    // 0x800AE784: jal         0x800B4274
    // 0x800AE788: addiu       $a1, $a1, -0x2990
    ctx->r5 = ADD32(ctx->r5, -0X2990);
    func_800B4274(rdram, ctx);
        goto after_3;
    // 0x800AE788: addiu       $a1, $a1, -0x2990
    ctx->r5 = ADD32(ctx->r5, -0X2990);
    after_3:
    // 0x800AE78C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800AE790: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800AE794:
    // 0x800AE794: bgez        $v0, L_800AE794
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800AE798: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800AE794;
    }
    // 0x800AE798: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800AE79C: jal         0x800678E4
    // 0x800AE7A0: nop

    func_800678E4(rdram, ctx);
        goto after_4;
    // 0x800AE7A0: nop

    after_4:
    // 0x800AE7A4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800AE7A8: jr          $ra
    // 0x800AE7AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800AE7AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800AE7B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE7B0: lbu         $a1, 0x1($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X1);
    // 0x800AE7B4: beq         $a1, $zero, L_800AE800
    if (ctx->r5 == 0) {
        // 0x800AE7B8: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800AE800;
    }
    // 0x800AE7B8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800AE7BC: addiu       $v0, $zero, 0x23
    ctx->r2 = ADD32(0, 0X23);
    // 0x800AE7C0: beq         $a1, $v0, L_800AE800
    if (ctx->r5 == ctx->r2) {
        // 0x800AE7C4: addiu       $t0, $zero, 0x2A
        ctx->r8 = ADD32(0, 0X2A);
            goto L_800AE800;
    }
    // 0x800AE7C4: addiu       $t0, $zero, 0x2A
    ctx->r8 = ADD32(0, 0X2A);
    // 0x800AE7C8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AE7CC: addiu       $a3, $v0, -0x2AE0
    ctx->r7 = ADD32(ctx->r2, -0X2AE0);
    // 0x800AE7D0: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    // 0x800AE7D4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800AE7D8:
    // 0x800AE7D8: lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X0);
    // 0x800AE7DC: beq         $a1, $t0, L_800AE800
    if (ctx->r5 == ctx->r8) {
        // 0x800AE7E0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800AE800;
    }
    // 0x800AE7E0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800AE7E4: addu        $v0, $v1, $a3
    ctx->r2 = ADD32(ctx->r3, ctx->r7);
    // 0x800AE7E8: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x800AE7EC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800AE7F0: beq         $v0, $zero, L_800AE800
    if (ctx->r2 == 0) {
        // 0x800AE7F4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800AE800;
    }
    // 0x800AE7F4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800AE7F8: bne         $v0, $a2, L_800AE7D8
    if (ctx->r2 != ctx->r6) {
        // 0x800AE7FC: nop
    
            goto L_800AE7D8;
    }
    // 0x800AE7FC: nop

L_800AE800:
    // 0x800AE800: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AE804: addiu       $v0, $v0, -0x2AE0
    ctx->r2 = ADD32(ctx->r2, -0X2AE0);
    // 0x800AE808: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800AE80C: jr          $ra
    // 0x800AE810: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    return;
    // 0x800AE810: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
;}
RECOMP_FUNC void func_800AE814(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE814: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800AE818: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x800AE81C: lwc1        $f20, 0x50($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800AE820: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800AE824: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x800AE828: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800AE82C: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x800AE830: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x800AE834: addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // 0x800AE838: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x800AE83C: addu        $s7, $a3, $zero
    ctx->r23 = ADD32(ctx->r7, 0);
    // 0x800AE840: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x800AE844: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800AE848: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800AE84C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800AE850: beq         $s4, $zero, L_800AE9B0
    if (ctx->r20 == 0) {
        // 0x800AE854: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_800AE9B0;
    }
    // 0x800AE854: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800AE858: beq         $s5, $zero, L_800AE9B0
    if (ctx->r21 == 0) {
        // 0x800AE85C: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_800AE9B0;
    }
    // 0x800AE85C: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800AE860: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
L_800AE864:
    // 0x800AE864: bne         $v0, $zero, L_800AE870
    if (ctx->r2 != 0) {
        // 0x800AE868: addiu       $s1, $s5, 0x1C
        ctx->r17 = ADD32(ctx->r21, 0X1C);
            goto L_800AE870;
    }
    // 0x800AE868: addiu       $s1, $s5, 0x1C
    ctx->r17 = ADD32(ctx->r21, 0X1C);
    // 0x800AE86C: addiu       $s1, $s4, 0x1C
    ctx->r17 = ADD32(ctx->r20, 0X1C);
L_800AE870:
    // 0x800AE870: andi        $s3, $s2, 0xFFFF
    ctx->r19 = ctx->r18 & 0XFFFF;
    // 0x800AE874: bne         $s3, $zero, L_800AE880
    if (ctx->r19 != 0) {
        // 0x800AE878: addu        $s0, $s7, $zero
        ctx->r16 = ADD32(ctx->r23, 0);
            goto L_800AE880;
    }
    // 0x800AE878: addu        $s0, $s7, $zero
    ctx->r16 = ADD32(ctx->r23, 0);
    // 0x800AE87C: addu        $s0, $s6, $zero
    ctx->r16 = ADD32(ctx->r22, 0);
L_800AE880:
    // 0x800AE880: jal         0x8001CA50
    // 0x800AE884: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA50(rdram, ctx);
        goto after_0;
    // 0x800AE884: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // 0x800AE888: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800AE88C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800AE890: beq         $v0, $zero, L_800AE8C4
    if (ctx->r2 == 0) {
        // 0x800AE894: nop
    
            goto L_800AE8C4;
    }
    // 0x800AE894: nop

    // 0x800AE898: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800AE89C: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800AE8A0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800AE8A4: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x800AE8A8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800AE8AC: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800AE8B0: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800AE8B4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800AE8B8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800AE8BC: jal         0x8001CA90
    // 0x800AE8C0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_1;
    // 0x800AE8C0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
L_800AE8C4:
    // 0x800AE8C4: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800AE8C8: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800AE8CC: beq         $v0, $zero, L_800AE8E8
    if (ctx->r2 == 0) {
        // 0x800AE8D0: nop
    
            goto L_800AE8E8;
    }
    // 0x800AE8D0: nop

    // 0x800AE8D4: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x800AE8D8: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
    // 0x800AE8DC: lw          $a3, 0x64($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X64);
    // 0x800AE8E0: jal         0x8001CB04
    // 0x800AE8E4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CB04(rdram, ctx);
        goto after_2;
    // 0x800AE8E4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
L_800AE8E8:
    // 0x800AE8E8: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800AE8EC: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800AE8F0: beq         $v0, $zero, L_800AE900
    if (ctx->r2 == 0) {
        // 0x800AE8F4: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_800AE900;
    }
    // 0x800AE8F4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800AE8F8: jal         0x8001DAEC
    // 0x800AE8FC: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    func_8001DAEC(rdram, ctx);
        goto after_3;
    // 0x800AE8FC: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    after_3:
L_800AE900:
    // 0x800AE900: beq         $s3, $zero, L_800AE90C
    if (ctx->r19 == 0) {
        // 0x800AE904: mov.s       $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
            goto L_800AE90C;
    }
    // 0x800AE904: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x800AE908: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_800AE90C:
    // 0x800AE90C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800AE910: jal         0x8001CDFC
    // 0x800AE914: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CDFC(rdram, ctx);
        goto after_4;
    // 0x800AE914: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_4:
    // 0x800AE918: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x800AE91C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x800AE920: andi        $v1, $a0, 0x9
    ctx->r3 = ctx->r4 & 0X9;
    // 0x800AE924: bne         $v1, $v0, L_800AE964
    if (ctx->r3 != ctx->r2) {
        // 0x800AE928: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_800AE964;
    }
    // 0x800AE928: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800AE92C: lwc1        $f2, 0x78($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800AE930: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800AE934: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800AE938: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800AE93C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800AE940: lwc1        $f2, 0x7C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x800AE944: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800AE948: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800AE94C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800AE950: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x800AE954: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800AE958: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800AE95C: j           L_800AE994
    // 0x800AE960: nop

        goto L_800AE994;
    // 0x800AE960: nop

L_800AE964:
    // 0x800AE964: bne         $v1, $v0, L_800AE980
    if (ctx->r3 != ctx->r2) {
        // 0x800AE968: andi        $v0, $a0, 0x1
        ctx->r2 = ctx->r4 & 0X1;
            goto L_800AE980;
    }
    // 0x800AE968: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x800AE96C: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x800AE970: lw          $a2, 0x7C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X7C);
    // 0x800AE974: lw          $a3, 0x80($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X80);
    // 0x800AE978: j           L_800AE994
    // 0x800AE97C: nop

        goto L_800AE994;
    // 0x800AE97C: nop

L_800AE980:
    // 0x800AE980: beql        $v0, $zero, L_800AE9A0
    if (ctx->r2 == 0) {
        // 0x800AE984: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800AE9A0;
    }
    goto skip_0;
    // 0x800AE984: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x800AE988: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x800AE98C: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    // 0x800AE990: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
L_800AE994:
    // 0x800AE994: jal         0x8001CA90
    // 0x800AE998: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_5;
    // 0x800AE998: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_5:
    // 0x800AE99C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800AE9A0:
    // 0x800AE9A0: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
    // 0x800AE9A4: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800AE9A8: bne         $v0, $zero, L_800AE864
    if (ctx->r2 != 0) {
        // 0x800AE9AC: andi        $v0, $s2, 0xFFFF
        ctx->r2 = ctx->r18 & 0XFFFF;
            goto L_800AE864;
    }
    // 0x800AE9AC: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
L_800AE9B0:
    // 0x800AE9B0: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x800AE9B4: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x800AE9B8: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x800AE9BC: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800AE9C0: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800AE9C4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800AE9C8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800AE9CC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800AE9D0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800AE9D4: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x800AE9D8: jr          $ra
    // 0x800AE9DC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800AE9DC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800AE830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE830: addiu       $v1, $zero, 0xD
    ctx->r3 = ADD32(0, 0XD);
    // 0x800AE834: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AE838: addiu       $v0, $v0, -0x4880
    ctx->r2 = ADD32(ctx->r2, -0X4880);
    // 0x800AE83C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_800AE840:
    // 0x800AE840: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x800AE844: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800AE848: bgez        $v1, L_800AE840
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800AE84C: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800AE840;
    }
    // 0x800AE84C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800AE850: addiu       $a0, $zero, 0x28C
    ctx->r4 = ADD32(0, 0X28C);
    // 0x800AE854: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800AE858: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AE85C: addiu       $a3, $v0, 0xB40
    ctx->r7 = ADD32(ctx->r2, 0XB40);
    // 0x800AE860: lbu         $v1, 0xB40($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB40);
    // 0x800AE864: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800AE868: beq         $v1, $v0, L_800AE874
    if (ctx->r3 == ctx->r2) {
        // 0x800AE86C: addiu       $a2, $a1, -0x48C0
        ctx->r6 = ADD32(ctx->r5, -0X48C0);
            goto L_800AE874;
    }
    // 0x800AE86C: addiu       $a2, $a1, -0x48C0
    ctx->r6 = ADD32(ctx->r5, -0X48C0);
    // 0x800AE870: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
L_800AE874:
    // 0x800AE874: sw          $a0, -0x48C0($a1)
    MEM_W(-0X48C0, ctx->r5) = ctx->r4;
    // 0x800AE878: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800AE87C: beq         $v1, $v0, L_800AE888
    if (ctx->r3 == ctx->r2) {
        // 0x800AE880: addiu       $a0, $zero, 0x28C
        ctx->r4 = ADD32(0, 0X28C);
            goto L_800AE888;
    }
    // 0x800AE880: addiu       $a0, $zero, 0x28C
    ctx->r4 = ADD32(0, 0X28C);
    // 0x800AE884: addiu       $a0, $zero, 0x272
    ctx->r4 = ADD32(0, 0X272);
L_800AE888:
    // 0x800AE888: sw          $a0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r4;
    // 0x800AE88C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800AE890: beq         $v1, $v0, L_800AE89C
    if (ctx->r3 == ctx->r2) {
        // 0x800AE894: addiu       $a0, $zero, 0x28C
        ctx->r4 = ADD32(0, 0X28C);
            goto L_800AE89C;
    }
    // 0x800AE894: addiu       $a0, $zero, 0x28C
    ctx->r4 = ADD32(0, 0X28C);
    // 0x800AE898: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
L_800AE89C:
    // 0x800AE89C: sw          $a0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r4;
    // 0x800AE8A0: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800AE8A4: beq         $v1, $v0, L_800AE8B0
    if (ctx->r3 == ctx->r2) {
        // 0x800AE8A8: addiu       $a0, $zero, 0x206
        ctx->r4 = ADD32(0, 0X206);
            goto L_800AE8B0;
    }
    // 0x800AE8A8: addiu       $a0, $zero, 0x206
    ctx->r4 = ADD32(0, 0X206);
    // 0x800AE8AC: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
L_800AE8B0:
    // 0x800AE8B0: sw          $a0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r4;
    // 0x800AE8B4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x800AE8B8: beq         $v1, $a1, L_800AE8C4
    if (ctx->r3 == ctx->r5) {
        // 0x800AE8BC: addiu       $v0, $zero, 0x207
        ctx->r2 = ADD32(0, 0X207);
            goto L_800AE8C4;
    }
    // 0x800AE8BC: addiu       $v0, $zero, 0x207
    ctx->r2 = ADD32(0, 0X207);
    // 0x800AE8C0: addiu       $v0, $zero, 0x123
    ctx->r2 = ADD32(0, 0X123);
L_800AE8C4:
    // 0x800AE8C4: sw          $v0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r2;
    // 0x800AE8C8: beq         $v1, $a1, L_800AE8D4
    if (ctx->r3 == ctx->r5) {
        // 0x800AE8CC: addiu       $v0, $zero, 0x208
        ctx->r2 = ADD32(0, 0X208);
            goto L_800AE8D4;
    }
    // 0x800AE8CC: addiu       $v0, $zero, 0x208
    ctx->r2 = ADD32(0, 0X208);
    // 0x800AE8D0: addiu       $v0, $zero, 0x124
    ctx->r2 = ADD32(0, 0X124);
L_800AE8D4:
    // 0x800AE8D4: sw          $v0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r2;
    // 0x800AE8D8: beq         $v1, $a1, L_800AE8E4
    if (ctx->r3 == ctx->r5) {
        // 0x800AE8DC: addiu       $v0, $zero, 0x20F
        ctx->r2 = ADD32(0, 0X20F);
            goto L_800AE8E4;
    }
    // 0x800AE8DC: addiu       $v0, $zero, 0x20F
    ctx->r2 = ADD32(0, 0X20F);
    // 0x800AE8E0: addiu       $v0, $zero, 0x12B
    ctx->r2 = ADD32(0, 0X12B);
L_800AE8E4:
    // 0x800AE8E4: sw          $v0, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r2;
    // 0x800AE8E8: beq         $v1, $a1, L_800AE8F4
    if (ctx->r3 == ctx->r5) {
        // 0x800AE8EC: addiu       $v0, $zero, 0x212
        ctx->r2 = ADD32(0, 0X212);
            goto L_800AE8F4;
    }
    // 0x800AE8EC: addiu       $v0, $zero, 0x212
    ctx->r2 = ADD32(0, 0X212);
    // 0x800AE8F0: addiu       $v0, $zero, 0x12E
    ctx->r2 = ADD32(0, 0X12E);
L_800AE8F4:
    // 0x800AE8F4: sw          $v0, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r2;
    // 0x800AE8F8: beq         $v1, $a1, L_800AE904
    if (ctx->r3 == ctx->r5) {
        // 0x800AE8FC: addiu       $v0, $zero, 0x213
        ctx->r2 = ADD32(0, 0X213);
            goto L_800AE904;
    }
    // 0x800AE8FC: addiu       $v0, $zero, 0x213
    ctx->r2 = ADD32(0, 0X213);
    // 0x800AE900: addiu       $v0, $zero, 0x12F
    ctx->r2 = ADD32(0, 0X12F);
L_800AE904:
    // 0x800AE904: sw          $v0, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r2;
    // 0x800AE908: beq         $v1, $a1, L_800AE914
    if (ctx->r3 == ctx->r5) {
        // 0x800AE90C: addiu       $a0, $zero, 0x211
        ctx->r4 = ADD32(0, 0X211);
            goto L_800AE914;
    }
    // 0x800AE90C: addiu       $a0, $zero, 0x211
    ctx->r4 = ADD32(0, 0X211);
    // 0x800AE910: addiu       $a0, $zero, 0x12D
    ctx->r4 = ADD32(0, 0X12D);
L_800AE914:
    // 0x800AE914: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x800AE918: addiu       $v1, $zero, 0x214
    ctx->r3 = ADD32(0, 0X214);
    // 0x800AE91C: beq         $v0, $a1, L_800AE928
    if (ctx->r2 == ctx->r5) {
        // 0x800AE920: sw          $a0, 0x24($a2)
        MEM_W(0X24, ctx->r6) = ctx->r4;
            goto L_800AE928;
    }
    // 0x800AE920: sw          $a0, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r4;
    // 0x800AE924: addiu       $v1, $zero, 0x130
    ctx->r3 = ADD32(0, 0X130);
L_800AE928:
    // 0x800AE928: sw          $v1, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r3;
    // 0x800AE92C: beq         $v0, $a1, L_800AE938
    if (ctx->r2 == ctx->r5) {
        // 0x800AE930: addiu       $v1, $zero, 0x28C
        ctx->r3 = ADD32(0, 0X28C);
            goto L_800AE938;
    }
    // 0x800AE930: addiu       $v1, $zero, 0x28C
    ctx->r3 = ADD32(0, 0X28C);
    // 0x800AE934: addiu       $v1, $zero, 0x131
    ctx->r3 = ADD32(0, 0X131);
L_800AE938:
    // 0x800AE938: sw          $v1, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->r3;
    // 0x800AE93C: beq         $v0, $a1, L_800AE948
    if (ctx->r2 == ctx->r5) {
        // 0x800AE940: addiu       $v1, $zero, 0x28C
        ctx->r3 = ADD32(0, 0X28C);
            goto L_800AE948;
    }
    // 0x800AE940: addiu       $v1, $zero, 0x28C
    ctx->r3 = ADD32(0, 0X28C);
    // 0x800AE944: addiu       $v1, $zero, 0x132
    ctx->r3 = ADD32(0, 0X132);
L_800AE948:
    // 0x800AE948: sw          $v1, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->r3;
    // 0x800AE94C: beq         $v0, $a1, L_800AE958
    if (ctx->r2 == ctx->r5) {
        // 0x800AE950: addiu       $v1, $zero, 0x28C
        ctx->r3 = ADD32(0, 0X28C);
            goto L_800AE958;
    }
    // 0x800AE950: addiu       $v1, $zero, 0x28C
    ctx->r3 = ADD32(0, 0X28C);
    // 0x800AE954: addiu       $v1, $zero, 0x133
    ctx->r3 = ADD32(0, 0X133);
L_800AE958:
    // 0x800AE958: jr          $ra
    // 0x800AE95C: sw          $v1, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->r3;
    return;
    // 0x800AE95C: sw          $v1, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->r3;
;}
RECOMP_FUNC void func_800AE878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE878: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AE87C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800AE880: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800AE884: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800AE888: addu        $t0, $a3, $zero
    ctx->r8 = ADD32(ctx->r7, 0);
    // 0x800AE88C: addu        $t1, $a3, $zero
    ctx->r9 = ADD32(ctx->r7, 0);
    // 0x800AE890: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AE894: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
L_800AE898:
    // 0x800AE898: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800AE89C: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800AE8A0: sltiu       $v0, $v1, 0x3
    ctx->r2 = ctx->r3 < 0X3 ? 1 : 0;
    // 0x800AE8A4: bnel        $v0, $zero, L_800AE8AC
    if (ctx->r2 != 0) {
        // 0x800AE8A8: addu        $t1, $zero, $zero
        ctx->r9 = ADD32(0, 0);
            goto L_800AE8AC;
    }
    goto skip_0;
    // 0x800AE8A8: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    skip_0:
L_800AE8AC:
    // 0x800AE8AC: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x800AE8B0: bnel        $v0, $zero, L_800AE8B8
    if (ctx->r2 != 0) {
        // 0x800AE8B4: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_800AE8B8;
    }
    goto skip_1;
    // 0x800AE8B4: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    skip_1:
L_800AE8B8:
    // 0x800AE8B8: beql        $v1, $zero, L_800AE8C0
    if (ctx->r3 == 0) {
        // 0x800AE8BC: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_800AE8C0;
    }
    goto skip_2;
    // 0x800AE8BC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    skip_2:
L_800AE8C0:
    // 0x800AE8C0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800AE8C4: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x800AE8C8: sltiu       $v0, $v0, 0x10
    ctx->r2 = ctx->r2 < 0X10 ? 1 : 0;
    // 0x800AE8CC: bne         $v0, $zero, L_800AE898
    if (ctx->r2 != 0) {
        // 0x800AE8D0: andi        $v0, $a1, 0xFF
        ctx->r2 = ctx->r5 & 0XFF;
            goto L_800AE898;
    }
    // 0x800AE8D0: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x800AE8D4: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x800AE8D8: andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // 0x800AE8DC: beq         $v0, $zero, L_800AE8EC
    if (ctx->r2 == 0) {
        // 0x800AE8E0: sb          $zero, 0xB1E($v1)
        MEM_B(0XB1E, ctx->r3) = 0;
            goto L_800AE8EC;
    }
    // 0x800AE8E0: sb          $zero, 0xB1E($v1)
    MEM_B(0XB1E, ctx->r3) = 0;
    // 0x800AE8E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AE8E8: sb          $v0, 0xB1E($v1)
    MEM_B(0XB1E, ctx->r3) = ctx->r2;
L_800AE8EC:
    // 0x800AE8EC: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // 0x800AE8F0: beq         $v0, $zero, L_800AE8FC
    if (ctx->r2 == 0) {
        // 0x800AE8F4: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800AE8FC;
    }
    // 0x800AE8F4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800AE8F8: sb          $v0, 0xB1E($v1)
    MEM_B(0XB1E, ctx->r3) = ctx->r2;
L_800AE8FC:
    // 0x800AE8FC: andi        $v0, $t1, 0xFF
    ctx->r2 = ctx->r9 & 0XFF;
    // 0x800AE900: beq         $v0, $zero, L_800AE90C
    if (ctx->r2 == 0) {
        // 0x800AE904: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800AE90C;
    }
    // 0x800AE904: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800AE908: sb          $v0, 0xB1E($v1)
    MEM_B(0XB1E, ctx->r3) = ctx->r2;
L_800AE90C:
    // 0x800AE90C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800AE910: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800AE914: jal         0x800A5D80
    // 0x800AE918: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    func_800A5D80(rdram, ctx);
        goto after_0;
    // 0x800AE918: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_0:
    // 0x800AE91C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800AE920: jr          $ra
    // 0x800AE924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800AE924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800AE928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE928: andi        $a3, $a1, 0xFF
    ctx->r7 = ctx->r5 & 0XFF;
    // 0x800AE92C: sltiu       $v0, $a3, 0x1
    ctx->r2 = ctx->r7 < 0X1 ? 1 : 0;
    // 0x800AE930: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x800AE934: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AE938: beql        $a3, $v0, L_800AE940
    if (ctx->r7 == ctx->r2) {
        // 0x800AE93C: addu        $a2, $v0, $zero
        ctx->r6 = ADD32(ctx->r2, 0);
            goto L_800AE940;
    }
    goto skip_0;
    // 0x800AE93C: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    skip_0:
L_800AE940:
    // 0x800AE940: andi        $t0, $a0, 0xFF
    ctx->r8 = ctx->r4 & 0XFF;
    // 0x800AE944: sltiu       $v0, $t0, 0x10
    ctx->r2 = ctx->r8 < 0X10 ? 1 : 0;
    // 0x800AE948: beql        $v0, $zero, L_800AE950
    if (ctx->r2 == 0) {
        // 0x800AE94C: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_800AE950;
    }
    goto skip_1;
    // 0x800AE94C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    skip_1:
L_800AE950:
    // 0x800AE950: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800AE954: bne         $t0, $v0, L_800AE96C
    if (ctx->r8 != ctx->r2) {
        // 0x800AE958: andi        $v1, $a0, 0xFF
        ctx->r3 = ctx->r4 & 0XFF;
            goto L_800AE96C;
    }
    // 0x800AE958: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x800AE95C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800AE960: beql        $a3, $v0, L_800AE96C
    if (ctx->r7 == ctx->r2) {
        // 0x800AE964: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_800AE96C;
    }
    goto skip_2;
    // 0x800AE964: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    skip_2:
    // 0x800AE968: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
L_800AE96C:
    // 0x800AE96C: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // 0x800AE970: bne         $v1, $v0, L_800AE984
    if (ctx->r3 != ctx->r2) {
        // 0x800AE974: andi        $v1, $a1, 0xFF
        ctx->r3 = ctx->r5 & 0XFF;
            goto L_800AE984;
    }
    // 0x800AE974: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x800AE978: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800AE97C: beql        $v1, $v0, L_800AE984
    if (ctx->r3 == ctx->r2) {
        // 0x800AE980: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_800AE984;
    }
    goto skip_3;
    // 0x800AE980: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    skip_3:
L_800AE984:
    // 0x800AE984: jr          $ra
    // 0x800AE988: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    return;
    // 0x800AE988: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
;}
RECOMP_FUNC void func_800AE960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE960: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AE964: lwc1        $f2, -0x6950($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X6950);
    // 0x800AE968: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AE96C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800AE970: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800AE974: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x800AE978: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800AE97C: lw          $s0, -0x694C($s1)
    ctx->r16 = MEM_W(ctx->r17, -0X694C);
    // 0x800AE980: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800AE984: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800AE988: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x800AE98C: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800AE990: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800AE994: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800AE998: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x800AE99C: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x800AE9A0: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800AE9A4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800AE9A8: nop

    // 0x800AE9AC: bc1t        L_800AECC4
    if (c1cs) {
        // 0x800AE9B0: addu        $s4, $a0, $zero
        ctx->r20 = ADD32(ctx->r4, 0);
            goto L_800AECC4;
    }
    // 0x800AE9B0: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x800AE9B4: jal         0x80003430
    // 0x800AE9B8: nop

    rand_recomp(rdram, ctx);
        goto after_0;
    // 0x800AE9B8: nop

    after_0:
    // 0x800AE9BC: andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // 0x800AE9C0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AE9C4: lwc1        $f2, 0x5450($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5450);
    // 0x800AE9C8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800AE9CC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800AE9D0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800AE9D4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AE9D8: lwc1        $f2, 0x5454($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5454);
    // 0x800AE9DC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800AE9E0: nop

    // 0x800AE9E4: bc1t        L_800AECC4
    if (c1cs) {
        // 0x800AE9E8: nop
    
            goto L_800AECC4;
    }
    // 0x800AE9E8: nop

    // 0x800AE9EC: lw          $v0, -0x694C($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X694C);
    // 0x800AE9F0: bne         $s0, $v0, L_800AEA84
    if (ctx->r16 != ctx->r2) {
        // 0x800AE9F4: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800AEA84;
    }
    // 0x800AE9F4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AE9F8: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800AE9FC: addiu       $s5, $zero, 0xF
    ctx->r21 = ADD32(0, 0XF);
    // 0x800AEA00: addiu       $s3, $v0, -0x6980
    ctx->r19 = ADD32(ctx->r2, -0X6980);
    // 0x800AEA04: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEA08: lwc1        $f20, 0x5458($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5458);
    // 0x800AEA0C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AEA10: addiu       $s2, $v0, -0x6968
    ctx->r18 = ADD32(ctx->r2, -0X6968);
L_800AEA14:
    // 0x800AEA14: lbu         $v0, 0xB40($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0XB40);
    // 0x800AEA18: beq         $v0, $s5, L_800AEA4C
    if (ctx->r2 == ctx->r21) {
        // 0x800AEA1C: nop
    
            goto L_800AEA4C;
    }
    // 0x800AEA1C: nop

    // 0x800AEA20: jal         0x80003430
    // 0x800AEA24: nop

    rand_recomp(rdram, ctx);
        goto after_1;
    // 0x800AEA24: nop

    after_1:
    // 0x800AEA28: andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // 0x800AEA2C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800AEA30: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800AEA34: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800AEA38: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800AEA3C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800AEA40: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800AEA44: j           L_800AEA74
    // 0x800AEA48: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
        goto L_800AEA74;
    // 0x800AEA48: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
L_800AEA4C:
    // 0x800AEA4C: jal         0x80003430
    // 0x800AEA50: nop

    rand_recomp(rdram, ctx);
        goto after_2;
    // 0x800AEA50: nop

    after_2:
    // 0x800AEA54: andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // 0x800AEA58: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800AEA5C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800AEA60: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800AEA64: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800AEA68: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800AEA6C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800AEA70: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
L_800AEA74:
    // 0x800AEA74: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x800AEA78: lw          $v0, -0x694C($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X694C);
    // 0x800AEA7C: beq         $s0, $v0, L_800AEA14
    if (ctx->r16 == ctx->r2) {
        // 0x800AEA80: nop
    
            goto L_800AEA14;
    }
    // 0x800AEA80: nop

L_800AEA84:
    // 0x800AEA84: lhu         $v1, 0xB4($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0XB4);
    // 0x800AEA88: bltz        $v1, L_800AEC98
    if (SIGNED(ctx->r3) < 0) {
        // 0x800AEA8C: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_800AEC98;
    }
    // 0x800AEA8C: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800AEA90: bne         $v0, $zero, L_800AEAA8
    if (ctx->r2 != 0) {
        // 0x800AEA94: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800AEAA8;
    }
    // 0x800AEA94: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AEA98: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800AEA9C: bne         $v1, $v0, L_800AEC9C
    if (ctx->r3 != ctx->r2) {
        // 0x800AEAA0: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800AEC9C;
    }
    // 0x800AEAA0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AEAA4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800AEAA8:
    // 0x800AEAA8: lbu         $v1, -0x6948($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X6948);
    // 0x800AEAAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AEAB0: bne         $v1, $v0, L_800AEC9C
    if (ctx->r3 != ctx->r2) {
        // 0x800AEAB4: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800AEC9C;
    }
    // 0x800AEAB4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AEAB8: jal         0x80003430
    // 0x800AEABC: nop

    rand_recomp(rdram, ctx);
        goto after_3;
    // 0x800AEABC: nop

    after_3:
    // 0x800AEAC0: andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // 0x800AEAC4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEAC8: lwc1        $f2, 0x545C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X545C);
    // 0x800AEACC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800AEAD0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800AEAD4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800AEAD8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEADC: lwc1        $f2, 0x5460($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5460);
    // 0x800AEAE0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800AEAE4: nop

    // 0x800AEAE8: bc1f        L_800AEB30
    if (!c1cs) {
        // 0x800AEAEC: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_800AEB30;
    }
    // 0x800AEAEC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800AEAF0: lw          $v1, -0x694C($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X694C);
    // 0x800AEAF4: addiu       $v0, $zero, 0x112
    ctx->r2 = ADD32(0, 0X112);
    // 0x800AEAF8: beq         $v1, $v0, L_800AEB30
    if (ctx->r3 == ctx->r2) {
        // 0x800AEAFC: nop
    
            goto L_800AEB30;
    }
    // 0x800AEAFC: nop

    // 0x800AEB00: lwc1        $f0, 0xC0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XC0);
    // 0x800AEB04: lwc1        $f2, 0xC4($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0XC4);
    // 0x800AEB08: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEB0C: lwc1        $f4, 0x5464($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5464);
    // 0x800AEB10: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800AEB14: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800AEB18: nop

    // 0x800AEB1C: bc1f        L_800AEB30
    if (!c1cs) {
        // 0x800AEB20: nop
    
            goto L_800AEB30;
    }
    // 0x800AEB20: nop

    // 0x800AEB24: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800AEB28: j           L_800AECA0
    // 0x800AEB2C: sw          $s0, -0x694C($a0)
    MEM_W(-0X694C, ctx->r4) = ctx->r16;
        goto L_800AECA0;
    // 0x800AEB2C: sw          $s0, -0x694C($a0)
    MEM_W(-0X694C, ctx->r4) = ctx->r16;
L_800AEB30:
    // 0x800AEB30: jal         0x80003430
    // 0x800AEB34: nop

    rand_recomp(rdram, ctx);
        goto after_4;
    // 0x800AEB34: nop

    after_4:
    // 0x800AEB38: andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // 0x800AEB3C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEB40: lwc1        $f22, 0x5468($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X5468);
    // 0x800AEB44: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800AEB48: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800AEB4C: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800AEB50: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEB54: lwc1        $f20, 0x546C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X546C);
    // 0x800AEB58: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800AEB5C: nop

    // 0x800AEB60: bc1f        L_800AEC5C
    if (!c1cs) {
        // 0x800AEB64: lui         $s3, 0x8013
        ctx->r19 = S32(0X8013 << 16);
            goto L_800AEC5C;
    }
    // 0x800AEB64: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800AEB68: addiu       $s2, $zero, 0xF
    ctx->r18 = ADD32(0, 0XF);
    // 0x800AEB6C: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x800AEB70: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEB74: lwc1        $f24, 0x5470($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X5470);
    // 0x800AEB78: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEB7C: lwc1        $f22, 0x5474($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X5474);
    // 0x800AEB80: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEB84: lwc1        $f20, 0x5478($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5478);
L_800AEB88:
    // 0x800AEB88: jal         0x80003430
    // 0x800AEB8C: nop

    rand_recomp(rdram, ctx);
        goto after_5;
    // 0x800AEB8C: nop

    after_5:
    // 0x800AEB90: andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // 0x800AEB94: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800AEB98: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800AEB9C: lbu         $v0, 0xB40($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0XB40);
    // 0x800AEBA0: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800AEBA4: beql        $v0, $s2, L_800AEBB0
    if (ctx->r2 == ctx->r18) {
        // 0x800AEBA8: add.s       $f0, $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
            goto L_800AEBB0;
    }
    goto skip_0;
    // 0x800AEBA8: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    skip_0:
    // 0x800AEBAC: add.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f22.fl;
L_800AEBB0:
    // 0x800AEBB0: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800AEBB4: mfc1        $s0, $f6
    ctx->r16 = (int32_t)ctx->f6.u32l;
    // 0x800AEBB8: lw          $v0, -0x694C($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X694C);
    // 0x800AEBBC: beq         $s0, $v0, L_800AEB88
    if (ctx->r16 == ctx->r2) {
        // 0x800AEBC0: nop
    
            goto L_800AEB88;
    }
    // 0x800AEBC0: nop

    // 0x800AEBC4: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x800AEBC8: lw          $v0, -0x694C($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X694C);
    // 0x800AEBCC: beq         $s0, $v0, L_800AEC00
    if (ctx->r16 == ctx->r2) {
        // 0x800AEBD0: addiu       $v0, $zero, 0x28C
        ctx->r2 = ADD32(0, 0X28C);
            goto L_800AEC00;
    }
    // 0x800AEBD0: addiu       $v0, $zero, 0x28C
    ctx->r2 = ADD32(0, 0X28C);
    // 0x800AEBD4: beq         $s0, $v0, L_800AEC00
    if (ctx->r16 == ctx->r2) {
        // 0x800AEBD8: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800AEC00;
    }
    // 0x800AEBD8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800AEBDC: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x800AEBE0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800AEBE4: jal         0x80066EE4
    // 0x800AEBE8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80066EE4(rdram, ctx);
        goto after_6;
    // 0x800AEBE8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_6:
    // 0x800AEBEC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEBF0: lwc1        $f0, 0x547C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X547C);
    // 0x800AEBF4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AEBF8: sw          $s0, -0x694C($s1)
    MEM_W(-0X694C, ctx->r17) = ctx->r16;
    // 0x800AEBFC: swc1        $f0, -0x6950($v0)
    MEM_W(-0X6950, ctx->r2) = ctx->f0.u32l;
L_800AEC00:
    // 0x800AEC00: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AEC04: jal         0x80003430
    // 0x800AEC08: sw          $s0, -0x694C($v0)
    MEM_W(-0X694C, ctx->r2) = ctx->r16;
    rand_recomp(rdram, ctx);
        goto after_7;
    // 0x800AEC08: sw          $s0, -0x694C($v0)
    MEM_W(-0X694C, ctx->r2) = ctx->r16;
    after_7:
    // 0x800AEC0C: andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // 0x800AEC10: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800AEC14: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800AEC18: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AEC1C: addiu       $v1, $zero, 0xF
    ctx->r3 = ADD32(0, 0XF);
    // 0x800AEC20: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEC24: lwc1        $f0, 0x5480($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5480);
    // 0x800AEC28: lbu         $v0, 0xB40($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB40);
    // 0x800AEC2C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800AEC30: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEC34: lwc1        $f0, 0x5484($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5484);
    // 0x800AEC38: beql        $v0, $v1, L_800AEC4C
    if (ctx->r2 == ctx->r3) {
        // 0x800AEC3C: add.s       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
            goto L_800AEC4C;
    }
    goto skip_1;
    // 0x800AEC3C: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    skip_1:
    // 0x800AEC40: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEC44: lwc1        $f0, 0x5488($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5488);
    // 0x800AEC48: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
L_800AEC4C:
    // 0x800AEC4C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800AEC50: mfc1        $s0, $f6
    ctx->r16 = (int32_t)ctx->f6.u32l;
    // 0x800AEC54: j           L_800AECA4
    // 0x800AEC58: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
        goto L_800AECA4;
    // 0x800AEC58: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_800AEC5C:
    // 0x800AEC5C: jal         0x80003430
    // 0x800AEC60: nop

    rand_recomp(rdram, ctx);
        goto after_8;
    // 0x800AEC60: nop

    after_8:
    // 0x800AEC64: andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // 0x800AEC68: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800AEC6C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800AEC70: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800AEC74: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800AEC78: nop

    // 0x800AEC7C: bc1f        L_800AECA0
    if (!c1cs) {
        // 0x800AEC80: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800AECA0;
    }
    // 0x800AEC80: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AEC84: lbu         $v1, 0xB40($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB40);
    // 0x800AEC88: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800AEC8C: beq         $v1, $v0, L_800AEC98
    if (ctx->r3 == ctx->r2) {
        // 0x800AEC90: addiu       $s0, $zero, 0x28C
        ctx->r16 = ADD32(0, 0X28C);
            goto L_800AEC98;
    }
    // 0x800AEC90: addiu       $s0, $zero, 0x28C
    ctx->r16 = ADD32(0, 0X28C);
    // 0x800AEC94: addiu       $s0, $zero, 0x102
    ctx->r16 = ADD32(0, 0X102);
L_800AEC98:
    // 0x800AEC98: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800AEC9C:
    // 0x800AEC9C: sw          $s0, -0x694C($v0)
    MEM_W(-0X694C, ctx->r2) = ctx->r16;
L_800AECA0:
    // 0x800AECA0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_800AECA4:
    // 0x800AECA4: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x800AECA8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800AECAC: jal         0x80066EE4
    // 0x800AECB0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80066EE4(rdram, ctx);
        goto after_9;
    // 0x800AECB0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_9:
    // 0x800AECB4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AECB8: lwc1        $f0, 0x548C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X548C);
    // 0x800AECBC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AECC0: swc1        $f0, -0x6950($v0)
    MEM_W(-0X6950, ctx->r2) = ctx->f0.u32l;
L_800AECC4:
    // 0x800AECC4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800AECC8: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x800AECCC: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800AECD0: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800AECD4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800AECD8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800AECDC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800AECE0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800AECE4: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x800AECE8: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x800AECEC: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800AECF0: jr          $ra
    // 0x800AECF4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800AECF4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800AE98C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE98C: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x800AE990: sltiu       $v0, $v1, 0x4C
    ctx->r2 = ctx->r3 < 0X4C ? 1 : 0;
    // 0x800AE994: beq         $v0, $zero, L_800AEA10
    if (ctx->r2 == 0) {
        // 0x800AE998: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_800AEA10;
    }
    // 0x800AE998: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800AE99C: addiu       $v0, $v0, 0x5C08
    ctx->r2 = ADD32(ctx->r2, 0X5C08);
    // 0x800AE9A0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800AE9A4: addu        $v1, $v1, $v0
    gpr jr_addend_800AE9AC = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800AE9A8: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800AE9AC: jr          $v0
    // 0x800AE9B0: nop

    switch (jr_addend_800AE9AC >> 2) {
        case 0: goto L_800AE9B4; break;
        case 1: goto L_800AEA10; break;
        case 2: goto L_800AEA10; break;
        case 3: goto L_800AEA10; break;
        case 4: goto L_800AEA10; break;
        case 5: goto L_800AEA10; break;
        case 6: goto L_800AEA10; break;
        case 7: goto L_800AEA10; break;
        case 8: goto L_800AEA10; break;
        case 9: goto L_800AEA10; break;
        case 10: goto L_800AEA10; break;
        case 11: goto L_800AEA10; break;
        case 12: goto L_800AEA10; break;
        case 13: goto L_800AEA04; break;
        case 14: goto L_800AEA10; break;
        case 15: goto L_800AEA10; break;
        case 16: goto L_800AEA10; break;
        case 17: goto L_800AEA10; break;
        case 18: goto L_800AEA10; break;
        case 19: goto L_800AEA10; break;
        case 20: goto L_800AE9B4; break;
        case 21: goto L_800AEA10; break;
        case 22: goto L_800AEA10; break;
        case 23: goto L_800AEA10; break;
        case 24: goto L_800AEA10; break;
        case 25: goto L_800AEA10; break;
        case 26: goto L_800AEA10; break;
        case 27: goto L_800AEA10; break;
        case 28: goto L_800AEA10; break;
        case 29: goto L_800AEA10; break;
        case 30: goto L_800AEA10; break;
        case 31: goto L_800AEA10; break;
        case 32: goto L_800AEA10; break;
        case 33: goto L_800AE9B4; break;
        case 34: goto L_800AEA10; break;
        case 35: goto L_800AEA10; break;
        case 36: goto L_800AEA10; break;
        case 37: goto L_800AEA10; break;
        case 38: goto L_800AEA10; break;
        case 39: goto L_800AEA10; break;
        case 40: goto L_800AE9EC; break;
        case 41: goto L_800AEA10; break;
        case 42: goto L_800AE9C8; break;
        case 43: goto L_800AE9D4; break;
        case 44: goto L_800AEA10; break;
        case 45: goto L_800AEA10; break;
        case 46: goto L_800AE9E0; break;
        case 47: goto L_800AEA10; break;
        case 48: goto L_800AEA10; break;
        case 49: goto L_800AEA10; break;
        case 50: goto L_800AEA10; break;
        case 51: goto L_800AE9B4; break;
        case 52: goto L_800AEA10; break;
        case 53: goto L_800AEA10; break;
        case 54: goto L_800AEA10; break;
        case 55: goto L_800AEA10; break;
        case 56: goto L_800AEA10; break;
        case 57: goto L_800AEA10; break;
        case 58: goto L_800AEA10; break;
        case 59: goto L_800AEA10; break;
        case 60: goto L_800AEA10; break;
        case 61: goto L_800AEA10; break;
        case 62: goto L_800AEA10; break;
        case 63: goto L_800AEA10; break;
        case 64: goto L_800AEA10; break;
        case 65: goto L_800AE9F8; break;
        case 66: goto L_800AE9BC; break;
        case 67: goto L_800AEA10; break;
        case 68: goto L_800AE9B4; break;
        case 69: goto L_800AEA10; break;
        case 70: goto L_800AEA10; break;
        case 71: goto L_800AEA10; break;
        case 72: goto L_800AEA10; break;
        case 73: goto L_800AEA10; break;
        case 74: goto L_800AE9B4; break;
        case 75: goto L_800AE9B4; break;
        default: switch_error(__func__, 0x800AE9AC, 0x800A5C08);
    }
    // 0x800AE9B0: nop

L_800AE9B4:
    // 0x800AE9B4: jr          $ra
    // 0x800AE9B8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800AE9B8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800AE9BC:
    // 0x800AE9BC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800AE9C0: jr          $ra
    // 0x800AE9C4: addiu       $v0, $v0, 0x5524
    ctx->r2 = ADD32(ctx->r2, 0X5524);
    return;
    // 0x800AE9C4: addiu       $v0, $v0, 0x5524
    ctx->r2 = ADD32(ctx->r2, 0X5524);
L_800AE9C8:
    // 0x800AE9C8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800AE9CC: jr          $ra
    // 0x800AE9D0: addiu       $v0, $v0, 0x5BE4
    ctx->r2 = ADD32(ctx->r2, 0X5BE4);
    return;
    // 0x800AE9D0: addiu       $v0, $v0, 0x5BE4
    ctx->r2 = ADD32(ctx->r2, 0X5BE4);
L_800AE9D4:
    // 0x800AE9D4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800AE9D8: jr          $ra
    // 0x800AE9DC: addiu       $v0, $v0, 0x5BEC
    ctx->r2 = ADD32(ctx->r2, 0X5BEC);
    return;
    // 0x800AE9DC: addiu       $v0, $v0, 0x5BEC
    ctx->r2 = ADD32(ctx->r2, 0X5BEC);
L_800AE9E0:
    // 0x800AE9E0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800AE9E4: jr          $ra
    // 0x800AE9E8: addiu       $v0, $v0, 0x5BFC
    ctx->r2 = ADD32(ctx->r2, 0X5BFC);
    return;
    // 0x800AE9E8: addiu       $v0, $v0, 0x5BFC
    ctx->r2 = ADD32(ctx->r2, 0X5BFC);
L_800AE9EC:
    // 0x800AE9EC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800AE9F0: jr          $ra
    // 0x800AE9F4: addiu       $v0, $v0, 0x54F4
    ctx->r2 = ADD32(ctx->r2, 0X54F4);
    return;
    // 0x800AE9F4: addiu       $v0, $v0, 0x54F4
    ctx->r2 = ADD32(ctx->r2, 0X54F4);
L_800AE9F8:
    // 0x800AE9F8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800AE9FC: jr          $ra
    // 0x800AEA00: addiu       $v0, $v0, 0x550C
    ctx->r2 = ADD32(ctx->r2, 0X550C);
    return;
    // 0x800AEA00: addiu       $v0, $v0, 0x550C
    ctx->r2 = ADD32(ctx->r2, 0X550C);
L_800AEA04:
    // 0x800AEA04: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800AEA08: jr          $ra
    // 0x800AEA0C: addiu       $v0, $v0, 0x54CC
    ctx->r2 = ADD32(ctx->r2, 0X54CC);
    return;
    // 0x800AEA0C: addiu       $v0, $v0, 0x54CC
    ctx->r2 = ADD32(ctx->r2, 0X54CC);
L_800AEA10:
    // 0x800AEA10: jr          $ra
    // 0x800AEA14: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800AEA14: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void hangarLoadShadows(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE9E0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800AE9E4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800AE9E8: addiu       $a0, $a0, 0x5804
    ctx->r4 = ADD32(ctx->r4, 0X5804);
    // 0x800AE9EC: sw          $ra, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r31;
    // 0x800AE9F0: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x800AE9F4: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800AE9F8: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800AE9FC: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800AEA00: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800AEA04: jal         0x8006488C
    // 0x800AEA08: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    load_asset(rdram, ctx);
        goto after_0;
    // 0x800AEA08: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    after_0:
    // 0x800AEA0C: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // 0x800AEA10: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800AEA14: addiu       $s5, $zero, -0x4
    ctx->r21 = ADD32(0, -0X4);
    // 0x800AEA18: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800AEA1C: addiu       $s3, $v0, -0x5AD8
    ctx->r19 = ADD32(ctx->r2, -0X5AD8);
L_800AEA20:
    // 0x800AEA20: addu        $s1, $s4, $zero
    ctx->r17 = ADD32(ctx->r20, 0);
    // 0x800AEA24: blez        $s2, L_800AEA4C
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800AEA28: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800AEA4C;
    }
    // 0x800AEA28: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800AEA2C:
    // 0x800AEA2C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800AEA30: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800AEA34: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800AEA38: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // 0x800AEA3C: and         $s1, $v0, $s5
    ctx->r17 = ctx->r2 & ctx->r21;
    // 0x800AEA40: slt         $v0, $v1, $s2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800AEA44: bne         $v0, $zero, L_800AEA2C
    if (ctx->r2 != 0) {
        // 0x800AEA48: nop
    
            goto L_800AEA2C;
    }
    // 0x800AEA48: nop

L_800AEA4C:
    // 0x800AEA4C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x800AEA50: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800AEA54: jal         0x80055488
    // 0x800AEA58: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    full_header_image_offset_convert(rdram, ctx);
        goto after_1;
    // 0x800AEA58: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800AEA5C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800AEA60: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800AEA64: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800AEA68: lhu         $v0, 0x32($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X32);
    // 0x800AEA6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AEA70: ori         $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 | 0X2000;
    // 0x800AEA74: sh          $v0, 0x32($s1)
    MEM_H(0X32, ctx->r17) = ctx->r2;
    // 0x800AEA78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AEA7C: jal         0x80022B90
    // 0x800AEA80: sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    func_80022B90(rdram, ctx);
        goto after_2;
    // 0x800AEA80: sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x800AEA84: sh          $v0, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r2;
    // 0x800AEA88: slti        $v0, $s2, 0xE
    ctx->r2 = SIGNED(ctx->r18) < 0XE ? 1 : 0;
    // 0x800AEA8C: bne         $v0, $zero, L_800AEA20
    if (ctx->r2 != 0) {
        // 0x800AEA90: addiu       $s3, $s3, 0x2
        ctx->r19 = ADD32(ctx->r19, 0X2);
            goto L_800AEA20;
    }
    // 0x800AEA90: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x800AEA94: jal         0x80001C98
    // 0x800AEA98: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    rs_free(rdram, ctx);
        goto after_3;
    // 0x800AEA98: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_3:
    // 0x800AEA9C: lw          $ra, 0x50($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X50);
    // 0x800AEAA0: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800AEAA4: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800AEAA8: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800AEAAC: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800AEAB0: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800AEAB4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800AEAB8: jr          $ra
    // 0x800AEABC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800AEABC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800AEA18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEA18: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800AEA1C: lw          $v0, 0x1A08($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1A08);
    // 0x800AEA20: jr          $ra
    // 0x800AEA24: nop

    return;
    // 0x800AEA24: nop

;}
RECOMP_FUNC void cuts_0058_bubble_sort(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEA28: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800AEA2C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800AEA30: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x800AEA34: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800AEA38: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800AEA3C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800AEA40: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800AEA44: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800AEA48: lhu         $v1, 0x4E($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X4E);
    // 0x800AEA4C: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
    // 0x800AEA50: sltiu       $v0, $a0, 0x2
    ctx->r2 = ctx->r4 < 0X2 ? 1 : 0;
    // 0x800AEA54: bne         $v0, $zero, L_800AEB10
    if (ctx->r2 != 0) {
        // 0x800AEA58: nop
    
            goto L_800AEB10;
    }
    // 0x800AEA58: nop

    // 0x800AEA5C: beq         $a0, $zero, L_800AEB10
    if (ctx->r4 == 0) {
        // 0x800AEA60: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_800AEB10;
    }
    // 0x800AEA60: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x800AEA64: addiu       $s2, $s3, 0x1
    ctx->r18 = ADD32(ctx->r19, 0X1);
L_800AEA68:
    // 0x800AEA68: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    // 0x800AEA6C: sltu        $v0, $a0, $v1
    ctx->r2 = ctx->r4 < ctx->r3 ? 1 : 0;
    // 0x800AEA70: beq         $v0, $zero, L_800AEAF8
    if (ctx->r2 == 0) {
        // 0x800AEA74: andi        $v1, $s3, 0xFFFF
        ctx->r3 = ctx->r19 & 0XFFFF;
            goto L_800AEAF8;
    }
    // 0x800AEA74: andi        $v1, $s3, 0xFFFF
    ctx->r3 = ctx->r19 & 0XFFFF;
    // 0x800AEA78: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800AEA7C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800AEA80: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800AEA84: addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
    // 0x800AEA88: addu        $s1, $s4, $v0
    ctx->r17 = ADD32(ctx->r20, ctx->r2);
    // 0x800AEA8C: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
L_800AEA90:
    // 0x800AEA90: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800AEA94: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800AEA98: addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
    // 0x800AEA9C: addu        $s0, $s4, $v0
    ctx->r16 = ADD32(ctx->r20, ctx->r2);
    // 0x800AEAA0: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x800AEAA4: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800AEAA8: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800AEAAC: beq         $v0, $zero, L_800AEAE0
    if (ctx->r2 == 0) {
        // 0x800AEAB0: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_800AEAE0;
    }
    // 0x800AEAB0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800AEAB4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800AEAB8: jal         0x80018EF4
    // 0x800AEABC: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    zmemcpy(rdram, ctx);
        goto after_0;
    // 0x800AEABC: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_0:
    // 0x800AEAC0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800AEAC4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800AEAC8: jal         0x80018EF4
    // 0x800AEACC: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    zmemcpy(rdram, ctx);
        goto after_1;
    // 0x800AEACC: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_1:
    // 0x800AEAD0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800AEAD4: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800AEAD8: jal         0x80018EF4
    // 0x800AEADC: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    zmemcpy(rdram, ctx);
        goto after_2;
    // 0x800AEADC: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_2:
L_800AEAE0:
    // 0x800AEAE0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800AEAE4: lhu         $v0, 0x4E($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X4E);
    // 0x800AEAE8: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    // 0x800AEAEC: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x800AEAF0: bne         $v0, $zero, L_800AEA90
    if (ctx->r2 != 0) {
        // 0x800AEAF4: sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4 << 1);
            goto L_800AEA90;
    }
    // 0x800AEAF4: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
L_800AEAF8:
    // 0x800AEAF8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800AEAFC: lhu         $v1, 0x4E($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X4E);
    // 0x800AEB00: andi        $v0, $s3, 0xFFFF
    ctx->r2 = ctx->r19 & 0XFFFF;
    // 0x800AEB04: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800AEB08: bne         $v0, $zero, L_800AEA68
    if (ctx->r2 != 0) {
        // 0x800AEB0C: addiu       $s2, $s3, 0x1
        ctx->r18 = ADD32(ctx->r19, 0X1);
            goto L_800AEA68;
    }
    // 0x800AEB0C: addiu       $s2, $s3, 0x1
    ctx->r18 = ADD32(ctx->r19, 0X1);
L_800AEB10:
    // 0x800AEB10: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800AEB14: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800AEB18: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800AEB1C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800AEB20: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800AEB24: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800AEB28: jr          $ra
    // 0x800AEB2C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800AEB2C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800AEAC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEAC0: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x800AEAC4: lw          $a2, 0x8($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X8);
    // 0x800AEAC8: beq         $v0, $zero, L_800AEAE8
    if (ctx->r2 == 0) {
        // 0x800AEACC: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800AEAE8;
    }
    // 0x800AEACC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800AEAD0:
    // 0x800AEAD0: sb          $a1, 0x27($a2)
    MEM_B(0X27, ctx->r6) = ctx->r5;
    // 0x800AEAD4: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x800AEAD8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800AEADC: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x800AEAE0: bne         $v0, $zero, L_800AEAD0
    if (ctx->r2 != 0) {
        // 0x800AEAE4: addiu       $a2, $a2, 0x28
        ctx->r6 = ADD32(ctx->r6, 0X28);
            goto L_800AEAD0;
    }
    // 0x800AEAE4: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
L_800AEAE8:
    // 0x800AEAE8: jr          $ra
    // 0x800AEAEC: nop

    return;
    // 0x800AEAEC: nop

;}
RECOMP_FUNC void func_800AEAF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEAF0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AEAF4: sw          $zero, -0x28FC($v0)
    MEM_W(-0X28FC, ctx->r2) = 0;
    // 0x800AEAF8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AEAFC: sw          $zero, -0x28F8($v0)
    MEM_W(-0X28F8, ctx->r2) = 0;
    // 0x800AEB00: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AEB04: addiu       $t0, $v0, -0x25A0
    ctx->r8 = ADD32(ctx->r2, -0X25A0);
    // 0x800AEB08: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800AEB0C: lw          $a2, 0x4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X4);
    // 0x800AEB10: lw          $a3, 0x8($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X8);
    // 0x800AEB14: sw          $v1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r3;
    // 0x800AEB18: sw          $a2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r6;
    // 0x800AEB1C: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
    // 0x800AEB20: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AEB24: addiu       $t0, $v0, -0x2590
    ctx->r8 = ADD32(ctx->r2, -0X2590);
    // 0x800AEB28: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800AEB2C: lw          $a2, 0x4($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X4);
    // 0x800AEB30: lw          $a3, 0x8($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X8);
    // 0x800AEB34: sw          $v1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r3;
    // 0x800AEB38: sw          $a2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r6;
    // 0x800AEB3C: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
    // 0x800AEB40: jr          $ra
    // 0x800AEB44: nop

    return;
    // 0x800AEB44: nop

;}
RECOMP_FUNC void func_800AEB30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEB30: jr          $ra
    // 0x800AEB34: nop

    return;
    // 0x800AEB34: nop

;}
RECOMP_FUNC void func_800AEB38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEB38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AEB3C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800AEB40: jal         0x800558D4
    // 0x800AEB44: nop

    freeTxtFile(rdram, ctx);
        goto after_0;
    // 0x800AEB44: nop

    after_0:
    // 0x800AEB48: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AEB4C: lw          $a0, 0x7CFC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X7CFC);
    // 0x800AEB50: jal         0x80004994
    // 0x800AEB54: nop

    func_80004994(rdram, ctx);
        goto after_1;
    // 0x800AEB54: nop

    after_1:
    // 0x800AEB58: lui         $a0, 0x8003
    ctx->r4 = S32(0X8003 << 16);
    // 0x800AEB5C: addiu       $a0, $a0, 0x7560
    ctx->r4 = ADD32(ctx->r4, 0X7560);
    // 0x800AEB60: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800AEB64: addiu       $a1, $a1, 0x960
    ctx->r5 = ADD32(ctx->r5, 0X960);
    // 0x800AEB68: jal         0x80018EF4
    // 0x800AEB6C: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    zmemcpy(rdram, ctx);
        goto after_2;
    // 0x800AEB6C: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_2:
    // 0x800AEB70: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800AEB74: jr          $ra
    // 0x800AEB78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800AEB78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800AEB48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEB48: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AEB4C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AEB50: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800AEB54: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800AEB58: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    // 0x800AEB5C: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800AEB60: jal         0x800AE530
    // 0x800AEB64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    hangarGenerateSecondaryWeaponString(rdram, ctx);
        goto after_0;
    // 0x800AEB64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800AEB68: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800AEB6C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800AEB70: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800AEB74: addiu       $v0, $zero, -0x100
    ctx->r2 = ADD32(0, -0X100);
    // 0x800AEB78: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800AEB7C: addiu       $v0, $zero, 0x97
    ctx->r2 = ADD32(0, 0X97);
    // 0x800AEB80: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800AEB84: jal         0x800625C4
    // 0x800AEB88: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_800625C4(rdram, ctx);
        goto after_1;
    // 0x800AEB88: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_1:
    // 0x800AEB8C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800AEB90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800AEB94: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800AEB98: addiu       $s0, $s0, -0x3A6C
    ctx->r16 = ADD32(ctx->r16, -0X3A6C);
    // 0x800AEB9C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800AEBA0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AEBA4: jal         0x80063E54
    // 0x800AEBA8: sw          $v0, -0x2584($v1)
    MEM_W(-0X2584, ctx->r3) = ctx->r2;
    func_80063E54(rdram, ctx);
        goto after_2;
    // 0x800AEBA8: sw          $v0, -0x2584($v1)
    MEM_W(-0X2584, ctx->r3) = ctx->r2;
    after_2:
    // 0x800AEBAC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800AEBB0: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800AEBB4: jal         0x80063E54
    // 0x800AEBB8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80063E54(rdram, ctx);
        goto after_3;
    // 0x800AEBB8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_3:
    // 0x800AEBBC: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800AEBC0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AEBC4: sb          $s1, -0x2580($v0)
    MEM_B(-0X2580, ctx->r2) = ctx->r17;
    // 0x800AEBC8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800AEBCC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AEBD0: jr          $ra
    // 0x800AEBD4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800AEBD4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800AEB7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEB7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AEB80: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800AEB84: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800AEB88: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800AEB8C: addiu       $a1, $v0, 0xBC0
    ctx->r5 = ADD32(ctx->r2, 0XBC0);
L_800AEB90:
    // 0x800AEB90: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800AEB94: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800AEB98: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800AEB9C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800AEBA0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800AEBA4: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800AEBA8: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800AEBAC: sltiu       $v0, $v0, 0x10
    ctx->r2 = ctx->r2 < 0X10 ? 1 : 0;
    // 0x800AEBB0: sb          $zero, 0x12($v1)
    MEM_B(0X12, ctx->r3) = 0;
    // 0x800AEBB4: bne         $v0, $zero, L_800AEB90
    if (ctx->r2 != 0) {
        // 0x800AEBB8: sw          $zero, 0x0($v1)
        MEM_W(0X0, ctx->r3) = 0;
            goto L_800AEB90;
    }
    // 0x800AEBB8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800AEBBC: jal         0x800AA4F4
    // 0x800AEBC0: nop

    func_800AA4F4(rdram, ctx);
        goto after_0;
    // 0x800AEBC0: nop

    after_0:
    // 0x800AEBC4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800AEBC8: jr          $ra
    // 0x800AEBCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800AEBCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800AEBD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEBD0: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x800AEBD4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AEBD8: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800AEBDC: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x800AEBE0: addiu       $a2, $v0, 0xBC0
    ctx->r6 = ADD32(ctx->r2, 0XBC0);
    // 0x800AEBE4: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x800AEBE8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800AEBEC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEBF0: lwc1        $f2, 0x5D38($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5D38);
    // 0x800AEBF4: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
L_800AEBF8:
    // 0x800AEBF8: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800AEBFC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800AEC00: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800AEC04: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x800AEC08: lbu         $v0, 0x12($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X12);
    // 0x800AEC0C: bne         $v0, $zero, L_800AEC30
    if (ctx->r2 != 0) {
        // 0x800AEC10: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800AEC30;
    }
    // 0x800AEC10: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800AEC14: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800AEC18: sh          $a0, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r4;
    // 0x800AEC1C: sb          $a3, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r7;
    // 0x800AEC20: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x800AEC24: swc1        $f6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f6.u32l;
    // 0x800AEC28: jr          $ra
    // 0x800AEC2C: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    return;
    // 0x800AEC2C: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
L_800AEC30:
    // 0x800AEC30: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x800AEC34: sltiu       $v0, $v0, 0x10
    ctx->r2 = ctx->r2 < 0X10 ? 1 : 0;
    // 0x800AEC38: bne         $v0, $zero, L_800AEBF8
    if (ctx->r2 != 0) {
        // 0x800AEC3C: andi        $v0, $a1, 0xFFFF
        ctx->r2 = ctx->r5 & 0XFFFF;
            goto L_800AEBF8;
    }
    // 0x800AEC3C: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x800AEC40: jr          $ra
    // 0x800AEC44: nop

    return;
    // 0x800AEC44: nop

;}
RECOMP_FUNC void func_800AEBD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEBD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AEBDC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800AEBE0: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x800AEBE4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800AEBE8: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800AEBEC: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800AEBF0: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800AEBF4: lbu         $v0, -0x2580($s1)
    ctx->r2 = MEM_BU(ctx->r17, -0X2580);
    // 0x800AEBF8: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // 0x800AEBFC: beq         $a1, $v0, L_800AEC20
    if (ctx->r5 == ctx->r2) {
        // 0x800AEC00: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_800AEC20;
    }
    // 0x800AEC00: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800AEC04: jal         0x800AE530
    // 0x800AEC08: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    hangarGenerateSecondaryWeaponString(rdram, ctx);
        goto after_0;
    // 0x800AEC08: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    after_0:
    // 0x800AEC0C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AEC10: lw          $a0, -0x2584($v1)
    ctx->r4 = MEM_W(ctx->r3, -0X2584);
    // 0x800AEC14: jal         0x80062854
    // 0x800AEC18: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_80062854(rdram, ctx);
        goto after_1;
    // 0x800AEC18: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_1:
    // 0x800AEC1C: sb          $s0, -0x2580($s1)
    MEM_B(-0X2580, ctx->r17) = ctx->r16;
L_800AEC20:
    // 0x800AEC20: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AEC24: lw          $a0, -0x2584($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X2584);
    // 0x800AEC28: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AEC2C: lw          $a1, -0x2924($v0)
    ctx->r5 = MEM_W(ctx->r2, -0X2924);
    // 0x800AEC30: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800AEC34: jal         0x80062B04
    // 0x800AEC38: nop

    func_80062B04(rdram, ctx);
        goto after_2;
    // 0x800AEC38: nop

    after_2:
    // 0x800AEC3C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800AEC40: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800AEC44: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800AEC48: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800AEC4C: jr          $ra
    // 0x800AEC50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800AEC50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800AEC48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEC48: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800AEC4C: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x800AEC50: lwc1        $f20, 0x50($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800AEC54: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800AEC58: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x800AEC5C: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800AEC60: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x800AEC64: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x800AEC68: addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // 0x800AEC6C: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x800AEC70: addu        $s7, $a3, $zero
    ctx->r23 = ADD32(ctx->r7, 0);
    // 0x800AEC74: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x800AEC78: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800AEC7C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800AEC80: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800AEC84: beq         $s4, $zero, L_800AEDE4
    if (ctx->r20 == 0) {
        // 0x800AEC88: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_800AEDE4;
    }
    // 0x800AEC88: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800AEC8C: beq         $s5, $zero, L_800AEDE4
    if (ctx->r21 == 0) {
        // 0x800AEC90: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_800AEDE4;
    }
    // 0x800AEC90: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800AEC94: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
L_800AEC98:
    // 0x800AEC98: bne         $v0, $zero, L_800AECA4
    if (ctx->r2 != 0) {
        // 0x800AEC9C: addiu       $s1, $s5, 0x1C
        ctx->r17 = ADD32(ctx->r21, 0X1C);
            goto L_800AECA4;
    }
    // 0x800AEC9C: addiu       $s1, $s5, 0x1C
    ctx->r17 = ADD32(ctx->r21, 0X1C);
    // 0x800AECA0: addiu       $s1, $s4, 0x1C
    ctx->r17 = ADD32(ctx->r20, 0X1C);
L_800AECA4:
    // 0x800AECA4: andi        $s3, $s2, 0xFFFF
    ctx->r19 = ctx->r18 & 0XFFFF;
    // 0x800AECA8: bne         $s3, $zero, L_800AECB4
    if (ctx->r19 != 0) {
        // 0x800AECAC: addu        $s0, $s7, $zero
        ctx->r16 = ADD32(ctx->r23, 0);
            goto L_800AECB4;
    }
    // 0x800AECAC: addu        $s0, $s7, $zero
    ctx->r16 = ADD32(ctx->r23, 0);
    // 0x800AECB0: addu        $s0, $s6, $zero
    ctx->r16 = ADD32(ctx->r22, 0);
L_800AECB4:
    // 0x800AECB4: jal         0x8001CA50
    // 0x800AECB8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA50(rdram, ctx);
        goto after_0;
    // 0x800AECB8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // 0x800AECBC: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800AECC0: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800AECC4: beq         $v0, $zero, L_800AECF8
    if (ctx->r2 == 0) {
        // 0x800AECC8: nop
    
            goto L_800AECF8;
    }
    // 0x800AECC8: nop

    // 0x800AECCC: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800AECD0: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800AECD4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800AECD8: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x800AECDC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800AECE0: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800AECE4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800AECE8: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800AECEC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800AECF0: jal         0x8001CA90
    // 0x800AECF4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_1;
    // 0x800AECF4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
L_800AECF8:
    // 0x800AECF8: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800AECFC: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800AED00: beq         $v0, $zero, L_800AED1C
    if (ctx->r2 == 0) {
        // 0x800AED04: nop
    
            goto L_800AED1C;
    }
    // 0x800AED04: nop

    // 0x800AED08: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x800AED0C: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
    // 0x800AED10: lw          $a3, 0x64($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X64);
    // 0x800AED14: jal         0x8001CB04
    // 0x800AED18: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CB04(rdram, ctx);
        goto after_2;
    // 0x800AED18: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
L_800AED1C:
    // 0x800AED1C: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800AED20: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800AED24: beq         $v0, $zero, L_800AED34
    if (ctx->r2 == 0) {
        // 0x800AED28: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_800AED34;
    }
    // 0x800AED28: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800AED2C: jal         0x8001DAEC
    // 0x800AED30: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    func_8001DAEC(rdram, ctx);
        goto after_3;
    // 0x800AED30: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    after_3:
L_800AED34:
    // 0x800AED34: beq         $s3, $zero, L_800AED40
    if (ctx->r19 == 0) {
        // 0x800AED38: mov.s       $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
            goto L_800AED40;
    }
    // 0x800AED38: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x800AED3C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_800AED40:
    // 0x800AED40: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800AED44: jal         0x8001CDFC
    // 0x800AED48: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CDFC(rdram, ctx);
        goto after_4;
    // 0x800AED48: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_4:
    // 0x800AED4C: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x800AED50: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x800AED54: andi        $v1, $a0, 0x9
    ctx->r3 = ctx->r4 & 0X9;
    // 0x800AED58: bne         $v1, $v0, L_800AED98
    if (ctx->r3 != ctx->r2) {
        // 0x800AED5C: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_800AED98;
    }
    // 0x800AED5C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800AED60: lwc1        $f2, 0x78($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800AED64: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800AED68: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800AED6C: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800AED70: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800AED74: lwc1        $f2, 0x7C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x800AED78: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800AED7C: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800AED80: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800AED84: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x800AED88: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800AED8C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800AED90: j           L_800AEDC8
    // 0x800AED94: nop

        goto L_800AEDC8;
    // 0x800AED94: nop

L_800AED98:
    // 0x800AED98: bne         $v1, $v0, L_800AEDB4
    if (ctx->r3 != ctx->r2) {
        // 0x800AED9C: andi        $v0, $a0, 0x1
        ctx->r2 = ctx->r4 & 0X1;
            goto L_800AEDB4;
    }
    // 0x800AED9C: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x800AEDA0: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x800AEDA4: lw          $a2, 0x7C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X7C);
    // 0x800AEDA8: lw          $a3, 0x80($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X80);
    // 0x800AEDAC: j           L_800AEDC8
    // 0x800AEDB0: nop

        goto L_800AEDC8;
    // 0x800AEDB0: nop

L_800AEDB4:
    // 0x800AEDB4: beql        $v0, $zero, L_800AEDD4
    if (ctx->r2 == 0) {
        // 0x800AEDB8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800AEDD4;
    }
    goto skip_0;
    // 0x800AEDB8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x800AEDBC: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x800AEDC0: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    // 0x800AEDC4: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
L_800AEDC8:
    // 0x800AEDC8: jal         0x8001CA90
    // 0x800AEDCC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_5;
    // 0x800AEDCC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_5:
    // 0x800AEDD0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800AEDD4:
    // 0x800AEDD4: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
    // 0x800AEDD8: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800AEDDC: bne         $v0, $zero, L_800AEC98
    if (ctx->r2 != 0) {
        // 0x800AEDE0: andi        $v0, $s2, 0xFFFF
        ctx->r2 = ctx->r18 & 0XFFFF;
            goto L_800AEC98;
    }
    // 0x800AEDE0: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
L_800AEDE4:
    // 0x800AEDE4: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x800AEDE8: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x800AEDEC: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x800AEDF0: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800AEDF4: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800AEDF8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800AEDFC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800AEE00: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800AEE04: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800AEE08: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x800AEE0C: jr          $ra
    // 0x800AEE10: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800AEE10: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void fake_func_800AEC54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800AEC60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEC60: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800AEC64: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800AEC68: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AEC6C: sw          $a2, -0x2530($v0)
    MEM_W(-0X2530, ctx->r2) = ctx->r6;
    // 0x800AEC70: and         $a2, $a1, $a2
    ctx->r6 = ctx->r5 & ctx->r6;
    // 0x800AEC74: sw          $ra, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r31;
    // 0x800AEC78: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x800AEC7C: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800AEC80: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800AEC84: sdc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X60, ctx->r29);
    // 0x800AEC88: bne         $a2, $zero, L_800AEC94
    if (ctx->r6 != 0) {
        // 0x800AEC8C: addu        $s0, $a0, $zero
        ctx->r16 = ADD32(ctx->r4, 0);
            goto L_800AEC94;
    }
    // 0x800AEC8C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800AEC90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800AEC94:
    // 0x800AEC94: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AEC98: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800AEC9C: sb          $v0, -0x253F($v1)
    MEM_B(-0X253F, ctx->r3) = ctx->r2;
    // 0x800AECA0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800AECA4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800AECA8: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x800AECAC: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800AECB0: sllv        $v0, $a0, $s1
    ctx->r2 = S32(ctx->r4 << (ctx->r17 & 31));
L_800AECB4:
    // 0x800AECB4: and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // 0x800AECB8: beql        $v0, $zero, L_800AECD0
    if (ctx->r2 == 0) {
        // 0x800AECBC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800AECD0;
    }
    goto skip_0;
    // 0x800AECBC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x800AECC0: sb          $s1, -0x253F($v1)
    MEM_B(-0X253F, ctx->r3) = ctx->r17;
    // 0x800AECC4: sb          $s1, -0x253E($a2)
    MEM_B(-0X253E, ctx->r6) = ctx->r17;
    // 0x800AECC8: j           L_800AECDC
    // 0x800AECCC: sb          $s1, -0x253D($a3)
    MEM_B(-0X253D, ctx->r7) = ctx->r17;
        goto L_800AECDC;
    // 0x800AECCC: sb          $s1, -0x253D($a3)
    MEM_B(-0X253D, ctx->r7) = ctx->r17;
L_800AECD0:
    // 0x800AECD0: sltiu       $v0, $s1, 0x13
    ctx->r2 = ctx->r17 < 0X13 ? 1 : 0;
    // 0x800AECD4: bne         $v0, $zero, L_800AECB4
    if (ctx->r2 != 0) {
        // 0x800AECD8: sllv        $v0, $a0, $s1
        ctx->r2 = S32(ctx->r4 << (ctx->r17 & 31));
            goto L_800AECB4;
    }
    // 0x800AECD8: sllv        $v0, $a0, $s1
    ctx->r2 = S32(ctx->r4 << (ctx->r17 & 31));
L_800AECDC:
    // 0x800AECDC: lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // 0x800AECE0: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x800AECE4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800AECE8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AECEC: lbu         $a1, 0xB62($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0XB62);
    // 0x800AECF0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AECF4: lwc1        $f20, 0x58C4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X58C4);
    // 0x800AECF8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AECFC: lwc1        $f0, 0x58C8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X58C8);
    // 0x800AED00: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AED04: sb          $zero, -0x2539($v0)
    MEM_B(-0X2539, ctx->r2) = 0;
    // 0x800AED08: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AED0C: sw          $v1, -0x2534($v0)
    MEM_W(-0X2534, ctx->r2) = ctx->r3;
    // 0x800AED10: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AED14: sb          $zero, -0x2545($v0)
    MEM_B(-0X2545, ctx->r2) = 0;
    // 0x800AED18: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AED1C: sb          $zero, -0x2544($v0)
    MEM_B(-0X2544, ctx->r2) = 0;
    // 0x800AED20: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AED24: sb          $zero, -0x2540($v0)
    MEM_B(-0X2540, ctx->r2) = 0;
    // 0x800AED28: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AED2C: sb          $zero, -0x2542($v0)
    MEM_B(-0X2542, ctx->r2) = 0;
    // 0x800AED30: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AED34: sw          $zero, -0x195C($v0)
    MEM_W(-0X195C, ctx->r2) = 0;
    // 0x800AED38: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AED3C: sw          $zero, -0x1958($v0)
    MEM_W(-0X1958, ctx->r2) = 0;
    // 0x800AED40: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AED44: swc1        $f20, -0x24FC($v0)
    MEM_W(-0X24FC, ctx->r2) = ctx->f20.u32l;
    // 0x800AED48: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AED4C: jal         0x80066A90
    // 0x800AED50: swc1        $f0, -0x24F4($v0)
    MEM_W(-0X24F4, ctx->r2) = ctx->f0.u32l;
    func_80066A90(rdram, ctx);
        goto after_0;
    // 0x800AED50: swc1        $f0, -0x24F4($v0)
    MEM_W(-0X24F4, ctx->r2) = ctx->f0.u32l;
    after_0:
    // 0x800AED54: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800AED58: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AED5C: sw          $zero, -0x2050($v0)
    MEM_W(-0X2050, ctx->r2) = 0;
    // 0x800AED60: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AED64: jal         0x80066918
    // 0x800AED68: sb          $zero, -0x2541($v0)
    MEM_B(-0X2541, ctx->r2) = 0;
    func_80066918(rdram, ctx);
        goto after_1;
    // 0x800AED68: sb          $zero, -0x2541($v0)
    MEM_B(-0X2541, ctx->r2) = 0;
    after_1:
    // 0x800AED6C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800AED70: lw          $a0, -0x76E0($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X76E0);
    // 0x800AED74: jal         0x8006657C
    // 0x800AED78: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8006657C(rdram, ctx);
        goto after_2;
    // 0x800AED78: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x800AED7C: addiu       $a0, $zero, 0x74
    ctx->r4 = ADD32(0, 0X74);
    // 0x800AED80: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AED84: jal         0x8008E0B0
    // 0x800AED88: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    func_8008E0B0(rdram, ctx);
        goto after_3;
    // 0x800AED88: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    after_3:
    // 0x800AED8C: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    // 0x800AED90: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AED94: jal         0x8008E0B0
    // 0x800AED98: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    func_8008E0B0(rdram, ctx);
        goto after_4;
    // 0x800AED98: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    after_4:
    // 0x800AED9C: jal         0x80066A18
    // 0x800AEDA0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_80066A18(rdram, ctx);
        goto after_5;
    // 0x800AEDA0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_5:
    // 0x800AEDA4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800AEDA8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800AEDAC: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x800AEDB0: jal         0x80097C2C
    // 0x800AEDB4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80097C2C(rdram, ctx);
        goto after_6;
    // 0x800AEDB4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_6:
    // 0x800AEDB8: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    // 0x800AEDBC: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x800AEDC0: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x800AEDC4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AEDC8: jal         0x80087EE8
    // 0x800AEDCC: sw          $v0, -0x2320($v1)
    MEM_W(-0X2320, ctx->r3) = ctx->r2;
    func_80087EE8(rdram, ctx);
        goto after_7;
    // 0x800AEDCC: sw          $v0, -0x2320($v1)
    MEM_W(-0X2320, ctx->r3) = ctx->r2;
    after_7:
    // 0x800AEDD0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800AEDD4: addiu       $a1, $a1, -0x2380
    ctx->r5 = ADD32(ctx->r5, -0X2380);
    // 0x800AEDD8: addiu       $a0, $a1, 0x2C
    ctx->r4 = ADD32(ctx->r5, 0X2C);
    // 0x800AEDDC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AEDE0: sw          $v0, -0x231C($v1)
    MEM_W(-0X231C, ctx->r3) = ctx->r2;
    // 0x800AEDE4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AEDE8: sb          $s0, -0x2538($v0)
    MEM_B(-0X2538, ctx->r2) = ctx->r16;
    // 0x800AEDEC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800AEDF0: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800AEDF4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AEDF8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEDFC: lwc1        $f2, 0x58CC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X58CC);
    // 0x800AEE00: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEE04: lwc1        $f4, 0x58D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X58D0);
    // 0x800AEE08: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEE0C: lwc1        $f6, 0x58D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X58D4);
    // 0x800AEE10: addiu       $s0, $s0, -0x24E0
    ctx->r16 = ADD32(ctx->r16, -0X24E0);
    // 0x800AEE14: sw          $zero, -0x7764($v0)
    MEM_W(-0X7764, ctx->r2) = 0;
    // 0x800AEE18: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // 0x800AEE1C: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x800AEE20: addiu       $v0, $zero, 0x154
    ctx->r2 = ADD32(0, 0X154);
    // 0x800AEE24: sw          $v0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r2;
    // 0x800AEE28: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // 0x800AEE2C: sw          $v0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r2;
    // 0x800AEE30: addiu       $v0, $zero, 0xAA
    ctx->r2 = ADD32(0, 0XAA);
    // 0x800AEE34: sw          $v0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r2;
    // 0x800AEE38: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AEE3C: sw          $s0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r16;
    // 0x800AEE40: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x800AEE44: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x800AEE48: swc1        $f0, -0x24E8($v0)
    MEM_W(-0X24E8, ctx->r2) = ctx->f0.u32l;
    // 0x800AEE4C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AEE50: swc1        $f0, -0x24EC($v0)
    MEM_W(-0X24EC, ctx->r2) = ctx->f0.u32l;
    // 0x800AEE54: swc1        $f2, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f2.u32l;
    // 0x800AEE58: swc1        $f4, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f4.u32l;
    // 0x800AEE5C: jal         0x8001CA50
    // 0x800AEE60: swc1        $f6, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->f6.u32l;
    func_8001CA50(rdram, ctx);
        goto after_8;
    // 0x800AEE60: swc1        $f6, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->f6.u32l;
    after_8:
    // 0x800AEE64: jal         0x80017AB0
    // 0x800AEE68: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80017AB0(rdram, ctx);
        goto after_9;
    // 0x800AEE68: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
    // 0x800AEE6C: jal         0x80017AC0
    // 0x800AEE70: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80017AC0(rdram, ctx);
        goto after_10;
    // 0x800AEE70: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x800AEE74: jal         0x80017AD0
    // 0x800AEE78: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80017AD0(rdram, ctx);
        goto after_11;
    // 0x800AEE78: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_11:
    // 0x800AEE7C: jal         0x800645CC
    // 0x800AEE80: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    func_800645CC(rdram, ctx);
        goto after_12;
    // 0x800AEE80: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_12:
    // 0x800AEE84: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800AEE88: addiu       $a1, $s0, 0x58
    ctx->r5 = ADD32(ctx->r16, 0X58);
    // 0x800AEE8C: addiu       $a0, $s0, -0x58
    ctx->r4 = ADD32(ctx->r16, -0X58);
    // 0x800AEE90: addu        $t0, $s0, $zero
    ctx->r8 = ADD32(ctx->r16, 0);
    // 0x800AEE94: addiu       $a3, $s0, 0x108
    ctx->r7 = ADD32(ctx->r16, 0X108);
    // 0x800AEE98: addiu       $a2, $s0, 0x160
    ctx->r6 = ADD32(ctx->r16, 0X160);
    // 0x800AEE9C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEEA0: lwc1        $f0, 0x58D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X58D8);
    // 0x800AEEA4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AEEA8: sw          $v0, -0x2324($v1)
    MEM_W(-0X2324, ctx->r3) = ctx->r2;
L_800AEEAC:
    // 0x800AEEAC: beql        $s0, $t0, L_800AEEB8
    if (ctx->r16 == ctx->r8) {
        // 0x800AEEB0: sw          $zero, 0x4($s0)
        MEM_W(0X4, ctx->r16) = 0;
            goto L_800AEEB8;
    }
    goto skip_1;
    // 0x800AEEB0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    skip_1:
    // 0x800AEEB4: sw          $a0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r4;
L_800AEEB8:
    // 0x800AEEB8: sltu        $v0, $s0, $a3
    ctx->r2 = ctx->r16 < ctx->r7 ? 1 : 0;
    // 0x800AEEBC: beql        $v0, $zero, L_800AEEC8
    if (ctx->r2 == 0) {
        // 0x800AEEC0: sw          $zero, 0x0($s0)
        MEM_W(0X0, ctx->r16) = 0;
            goto L_800AEEC8;
    }
    goto skip_2;
    // 0x800AEEC0: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    skip_2:
    // 0x800AEEC4: sw          $a1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r5;
L_800AEEC8:
    // 0x800AEEC8: sb          $t1, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r9;
    // 0x800AEECC: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x800AEED0: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x800AEED4: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x800AEED8: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x800AEEDC: swc1        $f20, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f20.u32l;
    // 0x800AEEE0: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x800AEEE4: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x800AEEE8: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x800AEEEC: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x800AEEF0: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x800AEEF4: swc1        $f20, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f20.u32l;
    // 0x800AEEF8: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // 0x800AEEFC: addiu       $a1, $a1, 0x58
    ctx->r5 = ADD32(ctx->r5, 0X58);
    // 0x800AEF00: sltu        $v0, $s0, $a2
    ctx->r2 = ctx->r16 < ctx->r6 ? 1 : 0;
    // 0x800AEF04: bne         $v0, $zero, L_800AEEAC
    if (ctx->r2 != 0) {
        // 0x800AEF08: addiu       $a0, $a0, 0x58
        ctx->r4 = ADD32(ctx->r4, 0X58);
            goto L_800AEEAC;
    }
    // 0x800AEF08: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    // 0x800AEF0C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800AEF10: addiu       $a0, $a0, 0x5870
    ctx->r4 = ADD32(ctx->r4, 0X5870);
    // 0x800AEF14: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800AEF18: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AEF1C: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x800AEF20: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AEF24: addiu       $v0, $v0, -0x24E0
    ctx->r2 = ADD32(ctx->r2, -0X24E0);
    // 0x800AEF28: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEF2C: lwc1        $f0, 0x58DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X58DC);
    // 0x800AEF30: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEF34: lwc1        $f4, 0x58E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X58E0);
    // 0x800AEF38: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEF3C: lwc1        $f6, 0x58E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X58E4);
    // 0x800AEF40: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEF44: lwc1        $f8, 0x58E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X58E8);
    // 0x800AEF48: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEF4C: lwc1        $f10, 0x58EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X58EC);
    // 0x800AEF50: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEF54: lwc1        $f2, 0x58F0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X58F0);
    // 0x800AEF58: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEF5C: lwc1        $f12, 0x58F4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X58F4);
    // 0x800AEF60: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800AEF64: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x800AEF68: sb          $v1, 0xB8($v0)
    MEM_B(0XB8, ctx->r2) = ctx->r3;
    // 0x800AEF6C: sw          $zero, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = 0;
    // 0x800AEF70: sw          $zero, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = 0;
    // 0x800AEF74: sb          $v1, 0x110($v0)
    MEM_B(0X110, ctx->r2) = ctx->r3;
    // 0x800AEF78: sw          $zero, 0x114($v0)
    MEM_W(0X114, ctx->r2) = 0;
    // 0x800AEF7C: sw          $zero, 0x118($v0)
    MEM_W(0X118, ctx->r2) = 0;
    // 0x800AEF80: sw          $zero, 0x11C($v0)
    MEM_W(0X11C, ctx->r2) = 0;
    // 0x800AEF84: swc1        $f0, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->f0.u32l;
    // 0x800AEF88: swc1        $f0, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->f0.u32l;
    // 0x800AEF8C: swc1        $f0, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->f0.u32l;
    // 0x800AEF90: swc1        $f4, 0xD4($v0)
    MEM_W(0XD4, ctx->r2) = ctx->f4.u32l;
    // 0x800AEF94: swc1        $f4, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->f4.u32l;
    // 0x800AEF98: swc1        $f6, 0xDC($v0)
    MEM_W(0XDC, ctx->r2) = ctx->f6.u32l;
    // 0x800AEF9C: swc1        $f8, 0xC0($v0)
    MEM_W(0XC0, ctx->r2) = ctx->f8.u32l;
    // 0x800AEFA0: swc1        $f10, 0xE0($v0)
    MEM_W(0XE0, ctx->r2) = ctx->f10.u32l;
    // 0x800AEFA4: swc1        $f2, 0x12C($v0)
    MEM_W(0X12C, ctx->r2) = ctx->f2.u32l;
    // 0x800AEFA8: swc1        $f2, 0x130($v0)
    MEM_W(0X130, ctx->r2) = ctx->f2.u32l;
    // 0x800AEFAC: swc1        $f2, 0x134($v0)
    MEM_W(0X134, ctx->r2) = ctx->f2.u32l;
    // 0x800AEFB0: jal         0x80046784
    // 0x800AEFB4: swc1        $f12, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->f12.u32l;
    loadDatFile(rdram, ctx);
        goto after_13;
    // 0x800AEFB4: swc1        $f12, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->f12.u32l;
    after_13:
    // 0x800AEFB8: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800AEFBC: sw          $v0, -0x2318($s2)
    MEM_W(-0X2318, ctx->r18) = ctx->r2;
    // 0x800AEFC0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800AEFC4: addiu       $v0, $v0, 0x5880
    ctx->r2 = ADD32(ctx->r2, 0X5880);
    // 0x800AEFC8: sw          $v0, -0x2310($s0)
    MEM_W(-0X2310, ctx->r16) = ctx->r2;
    // 0x800AEFCC: addiu       $s0, $s0, -0x2310
    ctx->r16 = ADD32(ctx->r16, -0X2310);
    // 0x800AEFD0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800AEFD4: addiu       $v0, $v0, 0x5888
    ctx->r2 = ADD32(ctx->r2, 0X5888);
    // 0x800AEFD8: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x800AEFDC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800AEFE0: addiu       $v0, $v0, 0x5894
    ctx->r2 = ADD32(ctx->r2, 0X5894);
    // 0x800AEFE4: sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
    // 0x800AEFE8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800AEFEC: addiu       $v0, $v0, 0x589C
    ctx->r2 = ADD32(ctx->r2, 0X589C);
    // 0x800AEFF0: jal         0x80056350
    // 0x800AEFF4: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    func_80056350(rdram, ctx);
        goto after_14;
    // 0x800AEFF4: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    after_14:
    // 0x800AEFF8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800AEFFC: addiu       $a0, $a0, 0x58A4
    ctx->r4 = ADD32(ctx->r4, 0X58A4);
    // 0x800AF000: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800AF004: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x800AF008: jal         0x8005645C
    // 0x800AF00C: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    load_hmt_and_hob(rdram, ctx);
        goto after_15;
    // 0x800AF00C: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    after_15:
L_800AF010:
    // 0x800AF010: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800AF014: jal         0x800AE7B0
    // 0x800AF018: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    func_800AE7B0(rdram, ctx);
        goto after_16;
    // 0x800AF018: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_16:
    // 0x800AF01C: jal         0x80056EB0
    // 0x800AF020: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_80056EB0(rdram, ctx);
        goto after_17;
    // 0x800AF020: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_17:
    // 0x800AF024: addiu       $a0, $v0, 0x28
    ctx->r4 = ADD32(ctx->r2, 0X28);
    // 0x800AF028: jal         0x8001CA50
    // 0x800AF02C: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    func_8001CA50(rdram, ctx);
        goto after_18;
    // 0x800AF02C: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    after_18:
    // 0x800AF030: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AF034: lui         $a2, 0x1480
    ctx->r6 = S32(0X1480 << 16);
    // 0x800AF038: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800AF03C: jal         0x8005955C
    // 0x800AF040: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8005955C(rdram, ctx);
        goto after_19;
    // 0x800AF040: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_19:
    // 0x800AF044: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800AF048: lw          $a0, -0x2318($s2)
    ctx->r4 = MEM_W(ctx->r18, -0X2318);
    // 0x800AF04C: jal         0x80047B70
    // 0x800AF050: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    getDatItemByName(rdram, ctx);
        goto after_20;
    // 0x800AF050: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_20:
    // 0x800AF054: addiu       $v1, $v0, 0x1C
    ctx->r3 = ADD32(ctx->r2, 0X1C);
    // 0x800AF058: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x800AF05C: lw          $t2, 0x10($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X10);
    // 0x800AF060: lw          $t3, 0x14($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X14);
    // 0x800AF064: lw          $t4, 0x18($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X18);
    // 0x800AF068: sw          $t2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r10;
    // 0x800AF06C: sw          $t3, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r11;
    // 0x800AF070: sw          $t4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r12;
    // 0x800AF074: sw          $v1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r3;
    // 0x800AF078: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800AF07C: sltiu       $v0, $s1, 0x4
    ctx->r2 = ctx->r17 < 0X4 ? 1 : 0;
    // 0x800AF080: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x800AF084: bne         $v0, $zero, L_800AF010
    if (ctx->r2 != 0) {
        // 0x800AF088: addiu       $s0, $s0, 0x20
        ctx->r16 = ADD32(ctx->r16, 0X20);
            goto L_800AF010;
    }
    // 0x800AF088: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x800AF08C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AF090: lui         $a2, 0x4
    ctx->r6 = S32(0X4 << 16);
    // 0x800AF094: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF098: lw          $a0, -0x230C($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X230C);
    // 0x800AF09C: jal         0x8005955C
    // 0x800AF0A0: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8005955C(rdram, ctx);
        goto after_21;
    // 0x800AF0A0: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_21:
    // 0x800AF0A4: jal         0x80061A88
    // 0x800AF0A8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80061A88(rdram, ctx);
        goto after_22;
    // 0x800AF0A8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_22:
    // 0x800AF0AC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AF0B0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x800AF0B4: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800AF0B8: lw          $a0, -0x2324($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X2324);
    // 0x800AF0BC: jal         0x800613C0
    // 0x800AF0C0: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    func_800613C0(rdram, ctx);
        goto after_23;
    // 0x800AF0C0: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_23:
    // 0x800AF0C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800AF0C8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800AF0CC: lw          $a0, -0x2324($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X2324);
    // 0x800AF0D0: jal         0x800613C0
    // 0x800AF0D4: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    func_800613C0(rdram, ctx);
        goto after_24;
    // 0x800AF0D4: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_24:
    // 0x800AF0D8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800AF0DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AF0E0: lw          $a0, -0x2324($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X2324);
    // 0x800AF0E4: jal         0x800613C0
    // 0x800AF0E8: addiu       $a3, $zero, 0x200
    ctx->r7 = ADD32(0, 0X200);
    func_800613C0(rdram, ctx);
        goto after_25;
    // 0x800AF0E8: addiu       $a3, $zero, 0x200
    ctx->r7 = ADD32(0, 0X200);
    after_25:
    // 0x800AF0EC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800AF0F0: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    // 0x800AF0F4: jal         0x80063E2C
    // 0x800AF0F8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80063E2C(rdram, ctx);
        goto after_26;
    // 0x800AF0F8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_26:
    // 0x800AF0FC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800AF100: jal         0x80063C6C
    // 0x800AF104: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80063C6C(rdram, ctx);
        goto after_27;
    // 0x800AF104: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_27:
    // 0x800AF108: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800AF10C: jal         0x80063C6C
    // 0x800AF110: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80063C6C(rdram, ctx);
        goto after_28;
    // 0x800AF110: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_28:
    // 0x800AF114: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800AF118: jal         0x80063C6C
    // 0x800AF11C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80063C6C(rdram, ctx);
        goto after_29;
    // 0x800AF11C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_29:
    // 0x800AF120: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800AF124: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800AF128: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800AF12C: addiu       $s1, $s1, -0x390C
    ctx->r17 = ADD32(ctx->r17, -0X390C);
    // 0x800AF130: jal         0x80063E54
    // 0x800AF134: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_80063E54(rdram, ctx);
        goto after_30;
    // 0x800AF134: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_30:
    // 0x800AF138: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800AF13C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800AF140: jal         0x80063E54
    // 0x800AF144: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_80063E54(rdram, ctx);
        goto after_31;
    // 0x800AF144: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_31:
    // 0x800AF148: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800AF14C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800AF150: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800AF154: addiu       $s0, $s0, -0x3910
    ctx->r16 = ADD32(ctx->r16, -0X3910);
    // 0x800AF158: jal         0x80063E54
    // 0x800AF15C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80063E54(rdram, ctx);
        goto after_32;
    // 0x800AF15C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_32:
    // 0x800AF160: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800AF164: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800AF168: jal         0x80063E54
    // 0x800AF16C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80063E54(rdram, ctx);
        goto after_33;
    // 0x800AF16C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_33:
    // 0x800AF170: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800AF174: jal         0x800B19EC
    // 0x800AF178: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    func_800B19EC(rdram, ctx);
        goto after_34;
    // 0x800AF178: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    after_34:
    // 0x800AF17C: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x800AF180: lbu         $a0, -0x253F($s2)
    ctx->r4 = MEM_BU(ctx->r18, -0X253F);
    // 0x800AF184: jal         0x8005589C
    // 0x800AF188: addiu       $s0, $zero, -0x100
    ctx->r16 = ADD32(0, -0X100);
    getGameOrFrontText(rdram, ctx);
        goto after_35;
    // 0x800AF188: addiu       $s0, $zero, -0x100
    ctx->r16 = ADD32(0, -0X100);
    after_35:
    // 0x800AF18C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800AF190: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800AF194: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800AF198: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x800AF19C: addiu       $v0, $zero, 0x75
    ctx->r2 = ADD32(0, 0X75);
    // 0x800AF1A0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800AF1A4: jal         0x800625C4
    // 0x800AF1A8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_800625C4(rdram, ctx);
        goto after_36;
    // 0x800AF1A8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_36:
    // 0x800AF1AC: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x800AF1B0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AF1B4: jal         0x8005589C
    // 0x800AF1B8: sw          $v0, -0x205C($v1)
    MEM_W(-0X205C, ctx->r3) = ctx->r2;
    getGameOrFrontText(rdram, ctx);
        goto after_37;
    // 0x800AF1B8: sw          $v0, -0x205C($v1)
    MEM_W(-0X205C, ctx->r3) = ctx->r2;
    after_37:
    // 0x800AF1BC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800AF1C0: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800AF1C4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800AF1C8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800AF1CC: addiu       $v0, $zero, -0xA3
    ctx->r2 = ADD32(0, -0XA3);
    // 0x800AF1D0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800AF1D4: jal         0x800625C4
    // 0x800AF1D8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_800625C4(rdram, ctx);
        goto after_38;
    // 0x800AF1D8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_38:
    // 0x800AF1DC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800AF1E0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AF1E4: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x800AF1E8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AF1EC: jal         0x80063E54
    // 0x800AF1F0: sw          $v0, -0x2058($v1)
    MEM_W(-0X2058, ctx->r3) = ctx->r2;
    func_80063E54(rdram, ctx);
        goto after_39;
    // 0x800AF1F0: sw          $v0, -0x2058($v1)
    MEM_W(-0X2058, ctx->r3) = ctx->r2;
    after_39:
    // 0x800AF1F4: jal         0x8005589C
    // 0x800AF1F8: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    getGameOrFrontText(rdram, ctx);
        goto after_40;
    // 0x800AF1F8: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    after_40:
    // 0x800AF1FC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800AF200: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800AF204: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800AF208: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x800AF20C: addiu       $v0, $zero, 0x97
    ctx->r2 = ADD32(0, 0X97);
    // 0x800AF210: jal         0x80063CFC
    // 0x800AF214: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80063CFC(rdram, ctx);
        goto after_41;
    // 0x800AF214: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_41:
    // 0x800AF218: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800AF21C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AF220: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800AF224: jal         0x80063E54
    // 0x800AF228: addiu       $a2, $a2, -0x3908
    ctx->r6 = ADD32(ctx->r6, -0X3908);
    func_80063E54(rdram, ctx);
        goto after_42;
    // 0x800AF228: addiu       $a2, $a2, -0x3908
    ctx->r6 = ADD32(ctx->r6, -0X3908);
    after_42:
    // 0x800AF22C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800AF230: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x800AF234: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800AF238: addiu       $a3, $zero, -0x94
    ctx->r7 = ADD32(0, -0X94);
    // 0x800AF23C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF240: lwc1        $f0, 0x58F8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X58F8);
    // 0x800AF244: addiu       $v0, $zero, -0x5F
    ctx->r2 = ADD32(0, -0X5F);
    // 0x800AF248: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800AF24C: addiu       $v0, $zero, 0x96
    ctx->r2 = ADD32(0, 0X96);
    // 0x800AF250: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x800AF254: jal         0x80062C7C
    // 0x800AF258: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_80062C7C(rdram, ctx);
        goto after_43;
    // 0x800AF258: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_43:
    // 0x800AF25C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800AF260: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800AF264: addiu       $a1, $a1, 0x58BC
    ctx->r5 = ADD32(ctx->r5, 0X58BC);
    // 0x800AF268: lbu         $a2, -0x253F($s2)
    ctx->r6 = MEM_BU(ctx->r18, -0X253F);
    // 0x800AF26C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AF270: jal         0x80033CC4
    // 0x800AF274: sw          $v0, -0x2054($v1)
    MEM_W(-0X2054, ctx->r3) = ctx->r2;
    sprintf_recomp(rdram, ctx);
        goto after_44;
    // 0x800AF274: sw          $v0, -0x2054($v1)
    MEM_W(-0X2054, ctx->r3) = ctx->r2;
    after_44:
    // 0x800AF278: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800AF27C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800AF280: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x800AF284: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x800AF288: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800AF28C: lw          $v1, -0x76E0($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X76E0);
    // 0x800AF290: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800AF294: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800AF298: jal         0x800B3AFC
    // 0x800AF29C: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    func_800B3AFC(rdram, ctx);
        goto after_45;
    // 0x800AF29C: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    after_45:
    // 0x800AF2A0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800AF2A4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF2A8: jal         0x800B3D08
    // 0x800AF2AC: sw          $a0, -0x2290($v0)
    MEM_W(-0X2290, ctx->r2) = ctx->r4;
    func_800B3D08(rdram, ctx);
        goto after_46;
    // 0x800AF2AC: sw          $a0, -0x2290($v0)
    MEM_W(-0X2290, ctx->r2) = ctx->r4;
    after_46:
    // 0x800AF2B0: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x800AF2B4: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x800AF2B8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AF2BC: addiu       $v1, $v1, -0x2280
    ctx->r3 = ADD32(ctx->r3, -0X2280);
    // 0x800AF2C0: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x800AF2C4: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800AF2C8: addiu       $a3, $a1, 0x30
    ctx->r7 = ADD32(ctx->r5, 0X30);
    // 0x800AF2CC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF2D0: sw          $a1, -0x228C($v0)
    MEM_W(-0X228C, ctx->r2) = ctx->r5;
    // 0x800AF2D4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x800AF2D8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AF2DC: sw          $a2, -0x2288($v1)
    MEM_W(-0X2288, ctx->r3) = ctx->r6;
    // 0x800AF2E0: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x800AF2E4: sw          $v0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r2;
L_800AF2E8:
    // 0x800AF2E8: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x800AF2EC: lw          $t3, 0x4($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X4);
    // 0x800AF2F0: lw          $t4, 0x8($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X8);
    // 0x800AF2F4: lw          $t5, 0xC($a1)
    ctx->r13 = MEM_W(ctx->r5, 0XC);
    // 0x800AF2F8: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x800AF2FC: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
    // 0x800AF300: sw          $t4, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r12;
    // 0x800AF304: sw          $t5, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r13;
    // 0x800AF308: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800AF30C: bne         $a1, $a3, L_800AF2E8
    if (ctx->r5 != ctx->r7) {
        // 0x800AF310: addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
            goto L_800AF2E8;
    }
    // 0x800AF310: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800AF314: jal         0x800B1430
    // 0x800AF318: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    func_800B1430(rdram, ctx);
        goto after_47;
    // 0x800AF318: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    after_47:
    // 0x800AF31C: lw          $a0, -0x2324($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X2324);
    // 0x800AF320: jal         0x800B165C
    // 0x800AF324: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    bridgeLoadShipBlueprints(rdram, ctx);
        goto after_48;
    // 0x800AF324: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    after_48:
    // 0x800AF328: lbu         $a0, -0x253F($s3)
    ctx->r4 = MEM_BU(ctx->r19, -0X253F);
    // 0x800AF32C: jal         0x800B1D54
    // 0x800AF330: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    func_800B1D54(rdram, ctx);
        goto after_49;
    // 0x800AF330: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    after_49:
    // 0x800AF334: lw          $a0, -0x2324($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X2324);
    // 0x800AF338: lw          $a1, -0x228C($s2)
    ctx->r5 = MEM_W(ctx->r18, -0X228C);
    // 0x800AF33C: jal         0x800642A0
    // 0x800AF340: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_800642A0(rdram, ctx);
        goto after_50;
    // 0x800AF340: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_50:
    // 0x800AF344: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800AF348: lw          $a0, -0x2324($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X2324);
    // 0x800AF34C: lw          $a1, -0x2288($s1)
    ctx->r5 = MEM_W(ctx->r17, -0X2288);
    // 0x800AF350: jal         0x800642A0
    // 0x800AF354: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_800642A0(rdram, ctx);
        goto after_51;
    // 0x800AF354: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_51:
    // 0x800AF358: lw          $a0, -0x2324($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X2324);
    // 0x800AF35C: lw          $a1, -0x228C($s2)
    ctx->r5 = MEM_W(ctx->r18, -0X228C);
    // 0x800AF360: jal         0x800646AC
    // 0x800AF364: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800646AC(rdram, ctx);
        goto after_52;
    // 0x800AF364: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_52:
    // 0x800AF368: lw          $a0, -0x2324($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X2324);
    // 0x800AF36C: lw          $a1, -0x2288($s1)
    ctx->r5 = MEM_W(ctx->r17, -0X2288);
    // 0x800AF370: jal         0x800646AC
    // 0x800AF374: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800646AC(rdram, ctx);
        goto after_53;
    // 0x800AF374: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_53:
    // 0x800AF378: lw          $a0, -0x2324($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X2324);
    // 0x800AF37C: lbu         $a1, -0x253F($s3)
    ctx->r5 = MEM_BU(ctx->r19, -0X253F);
    // 0x800AF380: jal         0x800B180C
    // 0x800AF384: nop

    func_800B180C(rdram, ctx);
        goto after_54;
    // 0x800AF384: nop

    after_54:
    // 0x800AF388: jal         0x800B3EB8
    // 0x800AF38C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800B3EB8(rdram, ctx);
        goto after_55;
    // 0x800AF38C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_55:
    // 0x800AF390: lw          $ra, 0x58($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X58);
    // 0x800AF394: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800AF398: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800AF39C: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800AF3A0: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800AF3A4: ldc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X60);
    // 0x800AF3A8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF3AC: sb          $zero, -0x253B($v0)
    MEM_B(-0X253B, ctx->r2) = 0;
    // 0x800AF3B0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF3B4: sb          $zero, -0x253C($v0)
    MEM_B(-0X253C, ctx->r2) = 0;
    // 0x800AF3B8: jr          $ra
    // 0x800AF3BC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800AF3BC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_800AECF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AECF8: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x800AECFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AED00: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800AED04: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800AED08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AED0C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800AED10: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800AED14: lwc1        $f2, 0x198($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X198);
    // 0x800AED18: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800AED1C: lwc1        $f4, 0x19C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X19C);
    // 0x800AED20: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800AED24: lwc1        $f8, 0x1A0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1A0);
    // 0x800AED28: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800AED2C: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800AED30: add.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x800AED34: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AED38: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x800AED3C: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800AED40: lwc1        $f10, 0x198($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X198);
    // 0x800AED44: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800AED48: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800AED4C: c.eq.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl == ctx->f4.fl;
    // 0x800AED50: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x800AED54: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x800AED58: bc1f        L_800AED88
    if (!c1cs) {
        // 0x800AED5C: swc1        $f2, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
            goto L_800AED88;
    }
    // 0x800AED5C: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    // 0x800AED60: lwc1        $f0, 0x19C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X19C);
    // 0x800AED64: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800AED68: nop

    // 0x800AED6C: bc1f        L_800AED88
    if (!c1cs) {
        // 0x800AED70: nop
    
            goto L_800AED88;
    }
    // 0x800AED70: nop

    // 0x800AED74: lwc1        $f0, 0x1A0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1A0);
    // 0x800AED78: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800AED7C: nop

    // 0x800AED80: bc1t        L_800AEF30
    if (c1cs) {
        // 0x800AED84: nop
    
            goto L_800AEF30;
    }
    // 0x800AED84: nop

L_800AED88:
    // 0x800AED88: jal         0x8001CF2C
    // 0x800AED8C: addiu       $a0, $s0, 0x198
    ctx->r4 = ADD32(ctx->r16, 0X198);
    func_8001CF2C(rdram, ctx);
        goto after_0;
    // 0x800AED8C: addiu       $a0, $s0, 0x198
    ctx->r4 = ADD32(ctx->r16, 0X198);
    after_0:
    // 0x800AED90: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AED94: lwc1        $f2, 0x5490($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5490);
    // 0x800AED98: mov.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
    // 0x800AED9C: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x800AEDA0: nop

    // 0x800AEDA4: bc1f        L_800AEE20
    if (!c1cs) {
        // 0x800AEDA8: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800AEE20;
    }
    // 0x800AEDA8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AEDAC: lw          $v0, 0xB50($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB50);
    // 0x800AEDB0: andi        $v0, $v0, 0x60
    ctx->r2 = ctx->r2 & 0X60;
    // 0x800AEDB4: bne         $v0, $zero, L_800AEF30
    if (ctx->r2 != 0) {
        // 0x800AEDB8: addiu       $s2, $zero, 0x3
        ctx->r18 = ADD32(0, 0X3);
            goto L_800AEF30;
    }
    // 0x800AEDB8: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x800AEDBC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AEDC0: lw          $v0, -0x35E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E0);
    // 0x800AEDC4: bne         $v0, $zero, L_800AEF30
    if (ctx->r2 != 0) {
        // 0x800AEDC8: nop
    
            goto L_800AEF30;
    }
    // 0x800AEDC8: nop

    // 0x800AEDCC: lw          $v0, 0x1C4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C4);
    // 0x800AEDD0: slt         $v0, $s2, $v0
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800AEDD4: beq         $v0, $zero, L_800AEDF4
    if (ctx->r2 == 0) {
        // 0x800AEDD8: nop
    
            goto L_800AEDF4;
    }
    // 0x800AEDD8: nop

    // 0x800AEDDC: lbu         $a0, 0xBB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XBB);
    // 0x800AEDE0: jal         0x80003150
    // 0x800AEDE4: nop

    func_80003150(rdram, ctx);
        goto after_1;
    // 0x800AEDE4: nop

    after_1:
    // 0x800AEDE8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800AEDEC: bne         $v0, $zero, L_800AEF30
    if (ctx->r2 != 0) {
        // 0x800AEDF0: nop
    
            goto L_800AEF30;
    }
    // 0x800AEDF0: nop

L_800AEDF4:
    // 0x800AEDF4: lw          $a0, 0x1C0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C0);
    // 0x800AEDF8: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x800AEDFC: beql        $a0, $s1, L_800AEE10
    if (ctx->r4 == ctx->r17) {
        // 0x800AEE00: lui         $a1, 0x8011
        ctx->r5 = S32(0X8011 << 16);
            goto L_800AEE10;
    }
    goto skip_0;
    // 0x800AEE00: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    skip_0:
    // 0x800AEE04: jal         0x80002BA8
    // 0x800AEE08: nop

    func_80002BA8(rdram, ctx);
        goto after_2;
    // 0x800AEE08: nop

    after_2:
    // 0x800AEE0C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
L_800AEE10:
    // 0x800AEE10: addiu       $a1, $a1, -0x4430
    ctx->r5 = ADD32(ctx->r5, -0X4430);
    // 0x800AEE14: lbu         $a0, 0xBB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XBB);
    // 0x800AEE18: j           L_800AEF1C
    // 0x800AEE1C: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
        goto L_800AEF1C;
    // 0x800AEE1C: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
L_800AEE20:
    // 0x800AEE20: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEE24: lwc1        $f0, 0x5494($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5494);
    // 0x800AEE28: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800AEE2C: nop

    // 0x800AEE30: bc1fl       L_800AEEAC
    if (!c1cs) {
        // 0x800AEE34: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800AEEAC;
    }
    goto skip_1;
    // 0x800AEE34: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    skip_1:
    // 0x800AEE38: lw          $v0, 0xB50($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB50);
    // 0x800AEE3C: andi        $v0, $v0, 0x60
    ctx->r2 = ctx->r2 & 0X60;
    // 0x800AEE40: bne         $v0, $zero, L_800AEF30
    if (ctx->r2 != 0) {
        // 0x800AEE44: addiu       $s2, $zero, 0x2
        ctx->r18 = ADD32(0, 0X2);
            goto L_800AEF30;
    }
    // 0x800AEE44: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x800AEE48: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AEE4C: lw          $v0, -0x35E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E0);
    // 0x800AEE50: bne         $v0, $zero, L_800AEF30
    if (ctx->r2 != 0) {
        // 0x800AEE54: nop
    
            goto L_800AEF30;
    }
    // 0x800AEE54: nop

    // 0x800AEE58: lw          $v0, 0x1C4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C4);
    // 0x800AEE5C: slt         $v0, $s2, $v0
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800AEE60: beq         $v0, $zero, L_800AEE80
    if (ctx->r2 == 0) {
        // 0x800AEE64: nop
    
            goto L_800AEE80;
    }
    // 0x800AEE64: nop

    // 0x800AEE68: lbu         $a0, 0xBB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XBB);
    // 0x800AEE6C: jal         0x80003150
    // 0x800AEE70: nop

    func_80003150(rdram, ctx);
        goto after_3;
    // 0x800AEE70: nop

    after_3:
    // 0x800AEE74: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800AEE78: bne         $v0, $zero, L_800AEF30
    if (ctx->r2 != 0) {
        // 0x800AEE7C: nop
    
            goto L_800AEF30;
    }
    // 0x800AEE7C: nop

L_800AEE80:
    // 0x800AEE80: lw          $a0, 0x1C0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C0);
    // 0x800AEE84: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x800AEE88: beql        $a0, $s1, L_800AEE9C
    if (ctx->r4 == ctx->r17) {
        // 0x800AEE8C: lui         $a1, 0x8011
        ctx->r5 = S32(0X8011 << 16);
            goto L_800AEE9C;
    }
    goto skip_2;
    // 0x800AEE8C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    skip_2:
    // 0x800AEE90: jal         0x80002BA8
    // 0x800AEE94: nop

    func_80002BA8(rdram, ctx);
        goto after_4;
    // 0x800AEE94: nop

    after_4:
    // 0x800AEE98: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
L_800AEE9C:
    // 0x800AEE9C: addiu       $a1, $a1, -0x4430
    ctx->r5 = ADD32(ctx->r5, -0X4430);
    // 0x800AEEA0: lbu         $a0, 0xBB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XBB);
    // 0x800AEEA4: j           L_800AEF1C
    // 0x800AEEA8: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
        goto L_800AEF1C;
    // 0x800AEEA8: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
L_800AEEAC:
    // 0x800AEEAC: lw          $v0, 0xB50($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB50);
    // 0x800AEEB0: andi        $v0, $v0, 0x60
    ctx->r2 = ctx->r2 & 0X60;
    // 0x800AEEB4: bne         $v0, $zero, L_800AEF30
    if (ctx->r2 != 0) {
        // 0x800AEEB8: addiu       $s2, $zero, 0x1
        ctx->r18 = ADD32(0, 0X1);
            goto L_800AEF30;
    }
    // 0x800AEEB8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800AEEBC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AEEC0: lw          $v0, -0x35E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E0);
    // 0x800AEEC4: bne         $v0, $zero, L_800AEF30
    if (ctx->r2 != 0) {
        // 0x800AEEC8: nop
    
            goto L_800AEF30;
    }
    // 0x800AEEC8: nop

    // 0x800AEECC: lw          $v0, 0x1C4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C4);
    // 0x800AEED0: slt         $v0, $s2, $v0
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800AEED4: beq         $v0, $zero, L_800AEEF4
    if (ctx->r2 == 0) {
        // 0x800AEED8: nop
    
            goto L_800AEEF4;
    }
    // 0x800AEED8: nop

    // 0x800AEEDC: lbu         $a0, 0xBB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XBB);
    // 0x800AEEE0: jal         0x80003150
    // 0x800AEEE4: nop

    func_80003150(rdram, ctx);
        goto after_5;
    // 0x800AEEE4: nop

    after_5:
    // 0x800AEEE8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800AEEEC: bne         $v0, $zero, L_800AEF30
    if (ctx->r2 != 0) {
        // 0x800AEEF0: nop
    
            goto L_800AEF30;
    }
    // 0x800AEEF0: nop

L_800AEEF4:
    // 0x800AEEF4: lw          $a0, 0x1C0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C0);
    // 0x800AEEF8: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x800AEEFC: beq         $a0, $s1, L_800AEF10
    if (ctx->r4 == ctx->r17) {
        // 0x800AEF00: lui         $a1, 0x8011
        ctx->r5 = S32(0X8011 << 16);
            goto L_800AEF10;
    }
    // 0x800AEF00: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800AEF04: jal         0x80002BA8
    // 0x800AEF08: nop

    func_80002BA8(rdram, ctx);
        goto after_6;
    // 0x800AEF08: nop

    after_6:
    // 0x800AEF0C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
L_800AEF10:
    // 0x800AEF10: addiu       $a1, $a1, -0x4430
    ctx->r5 = ADD32(ctx->r5, -0X4430);
    // 0x800AEF14: lbu         $a0, 0xBB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XBB);
    // 0x800AEF18: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
L_800AEF1C:
    // 0x800AEF1C: jal         0x80002ADC
    // 0x800AEF20: nop

    func_80002ADC(rdram, ctx);
        goto after_7;
    // 0x800AEF20: nop

    after_7:
    // 0x800AEF24: beq         $v0, $s1, L_800AEF30
    if (ctx->r2 == ctx->r17) {
        // 0x800AEF28: sw          $v0, 0x1C0($s0)
        MEM_W(0X1C0, ctx->r16) = ctx->r2;
            goto L_800AEF30;
    }
    // 0x800AEF28: sw          $v0, 0x1C0($s0)
    MEM_W(0X1C0, ctx->r16) = ctx->r2;
    // 0x800AEF2C: sw          $s2, 0x1C4($s0)
    MEM_W(0X1C4, ctx->r16) = ctx->r18;
L_800AEF30:
    // 0x800AEF30: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AEF34: swc1        $f0, 0x1A0($s0)
    MEM_W(0X1A0, ctx->r16) = ctx->f0.u32l;
    // 0x800AEF38: swc1        $f0, 0x19C($s0)
    MEM_W(0X19C, ctx->r16) = ctx->f0.u32l;
    // 0x800AEF3C: swc1        $f0, 0x198($s0)
    MEM_W(0X198, ctx->r16) = ctx->f0.u32l;
    // 0x800AEF40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AEF44: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800AEF48: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800AEF4C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800AEF50: jr          $ra
    // 0x800AEF54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800AEF54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800AEE14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEE14: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800AEE18: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x800AEE1C: addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // 0x800AEE20: sw          $ra, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r31;
    // 0x800AEE24: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x800AEE28: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x800AEE2C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800AEE30: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800AEE34: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800AEE38: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800AEE3C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800AEE40: sdc1        $f22, 0x60($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X60, ctx->r29);
    // 0x800AEE44: sdc1        $f20, 0x58($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X58, ctx->r29);
    // 0x800AEE48: lhu         $v0, 0x4A($s7)
    ctx->r2 = MEM_HU(ctx->r23, 0X4A);
    // 0x800AEE4C: beq         $v0, $zero, L_800AEEFC
    if (ctx->r2 == 0) {
        // 0x800AEE50: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_800AEEFC;
    }
    // 0x800AEE50: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x800AEE54: lui         $s5, 0x800B
    ctx->r21 = S32(0X800B << 16);
    // 0x800AEE58: ori         $s6, $zero, 0xFFFF
    ctx->r22 = 0 | 0XFFFF;
    // 0x800AEE5C: addiu       $s4, $sp, 0x20
    ctx->r20 = ADD32(ctx->r29, 0X20);
    // 0x800AEE60: addu        $s2, $s3, $zero
    ctx->r18 = ADD32(ctx->r19, 0);
    // 0x800AEE64: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEE68: lwc1        $f22, 0x5D3C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X5D3C);
    // 0x800AEE6C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEE70: lwc1        $f20, 0x5D40($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5D40);
L_800AEE74:
    // 0x800AEE74: lw          $v0, 0x1900($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X1900);
    // 0x800AEE78: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x800AEE7C: lhu         $s0, 0xB8($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0XB8);
    // 0x800AEE80: beql        $s0, $s6, L_800AEEE8
    if (ctx->r16 == ctx->r22) {
        // 0x800AEE84: addiu       $s2, $s2, 0x13C
        ctx->r18 = ADD32(ctx->r18, 0X13C);
            goto L_800AEEE8;
    }
    goto skip_0;
    // 0x800AEE84: addiu       $s2, $s2, 0x13C
    ctx->r18 = ADD32(ctx->r18, 0X13C);
    skip_0:
    // 0x800AEE88: jal         0x80040218
    // 0x800AEE8C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80040218(rdram, ctx);
        goto after_0;
    // 0x800AEE8C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x800AEE90: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    // 0x800AEE94: beq         $s1, $s6, L_800AEED0
    if (ctx->r17 == ctx->r22) {
        // 0x800AEE98: addiu       $a1, $sp, 0x10
        ctx->r5 = ADD32(ctx->r29, 0X10);
            goto L_800AEED0;
    }
    // 0x800AEE98: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800AEE9C: lw          $a0, 0x1900($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X1900);
    // 0x800AEEA0: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    // 0x800AEEA4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800AEEA8: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x800AEEAC: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x800AEEB0: addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    // 0x800AEEB4: jal         0x800193E8
    // 0x800AEEB8: addiu       $a0, $a0, 0x88
    ctx->r4 = ADD32(ctx->r4, 0X88);
    func_800193E8(rdram, ctx);
        goto after_1;
    // 0x800AEEB8: addiu       $a0, $a0, 0x88
    ctx->r4 = ADD32(ctx->r4, 0X88);
    after_1:
    // 0x800AEEBC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800AEEC0: jal         0x80041E4C
    // 0x800AEEC4: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_80041E4C(rdram, ctx);
        goto after_2;
    // 0x800AEEC4: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_2:
    // 0x800AEEC8: j           L_800AEEE8
    // 0x800AEECC: addiu       $s2, $s2, 0x13C
    ctx->r18 = ADD32(ctx->r18, 0X13C);
        goto L_800AEEE8;
    // 0x800AEECC: addiu       $s2, $s2, 0x13C
    ctx->r18 = ADD32(ctx->r18, 0X13C);
L_800AEED0:
    // 0x800AEED0: jal         0x8003F0C8
    // 0x800AEED4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003F0C8(rdram, ctx);
        goto after_3;
    // 0x800AEED4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x800AEED8: lw          $v0, 0x1900($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X1900);
    // 0x800AEEDC: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x800AEEE0: sh          $s1, 0xB8($v0)
    MEM_H(0XB8, ctx->r2) = ctx->r17;
    // 0x800AEEE4: addiu       $s2, $s2, 0x13C
    ctx->r18 = ADD32(ctx->r18, 0X13C);
L_800AEEE8:
    // 0x800AEEE8: lhu         $v0, 0x4A($s7)
    ctx->r2 = MEM_HU(ctx->r23, 0X4A);
    // 0x800AEEEC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800AEEF0: sltu        $v0, $s3, $v0
    ctx->r2 = ctx->r19 < ctx->r2 ? 1 : 0;
    // 0x800AEEF4: bne         $v0, $zero, L_800AEE74
    if (ctx->r2 != 0) {
        // 0x800AEEF8: nop
    
            goto L_800AEE74;
    }
    // 0x800AEEF8: nop

L_800AEEFC:
    // 0x800AEEFC: lw          $ra, 0x50($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X50);
    // 0x800AEF00: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x800AEF04: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x800AEF08: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x800AEF0C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800AEF10: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800AEF14: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800AEF18: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800AEF1C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800AEF20: ldc1        $f22, 0x60($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X60);
    // 0x800AEF24: ldc1        $f20, 0x58($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X58);
    // 0x800AEF28: jr          $ra
    // 0x800AEF2C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800AEF2C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_800AEF30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEF30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AEF34: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800AEF38: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800AEF3C: lui         $s3, 0x800B
    ctx->r19 = S32(0X800B << 16);
    // 0x800AEF40: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800AEF44: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800AEF48: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800AEF4C: lw          $v1, 0x1900($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X1900);
    // 0x800AEF50: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800AEF54: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800AEF58: sll         $s2, $v0, 2
    ctx->r18 = S32(ctx->r2 << 2);
    // 0x800AEF5C: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800AEF60: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800AEF64: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800AEF68: addu        $v0, $s2, $v1
    ctx->r2 = ADD32(ctx->r18, ctx->r3);
    // 0x800AEF6C: lhu         $s1, 0xB8($v0)
    ctx->r17 = MEM_HU(ctx->r2, 0XB8);
    // 0x800AEF70: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    // 0x800AEF74: beq         $s1, $s0, L_800AEFAC
    if (ctx->r17 == ctx->r16) {
        // 0x800AEF78: nop
    
            goto L_800AEFAC;
    }
    // 0x800AEF78: nop

    // 0x800AEF7C: jal         0x80040218
    // 0x800AEF80: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80040218(rdram, ctx);
        goto after_0;
    // 0x800AEF80: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // 0x800AEF84: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x800AEF88: beq         $a0, $s0, L_800AEF98
    if (ctx->r4 == ctx->r16) {
        // 0x800AEF8C: nop
    
            goto L_800AEF98;
    }
    // 0x800AEF8C: nop

    // 0x800AEF90: jal         0x80041CEC
    // 0x800AEF94: nop

    func_80041CEC(rdram, ctx);
        goto after_1;
    // 0x800AEF94: nop

    after_1:
L_800AEF98:
    // 0x800AEF98: jal         0x8003F0C8
    // 0x800AEF9C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8003F0C8(rdram, ctx);
        goto after_2;
    // 0x800AEF9C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
    // 0x800AEFA0: lw          $v0, 0x1900($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X1900);
    // 0x800AEFA4: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x800AEFA8: sh          $s0, 0xB8($v0)
    MEM_H(0XB8, ctx->r2) = ctx->r16;
L_800AEFAC:
    // 0x800AEFAC: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800AEFB0: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800AEFB4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800AEFB8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800AEFBC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800AEFC0: jr          $ra
    // 0x800AEFC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800AEFC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800AEF58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEF58: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AEF5C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800AEF60: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800AEF64: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800AEF68: lbu         $v0, 0x24C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X24C);
    // 0x800AEF6C: bne         $v0, $zero, L_800AF03C
    if (ctx->r2 != 0) {
        // 0x800AEF70: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800AF03C;
    }
    // 0x800AEF70: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AEF74: lw          $v0, -0x35E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E0);
    // 0x800AEF78: bne         $v0, $zero, L_800AF03C
    if (ctx->r2 != 0) {
        // 0x800AEF7C: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800AF03C;
    }
    // 0x800AEF7C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800AEF80: lw          $v1, 0xB8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XB8);
    // 0x800AEF84: addiu       $a0, $a0, 0x7DB8
    ctx->r4 = ADD32(ctx->r4, 0X7DB8);
    // 0x800AEF88: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800AEF8C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800AEF90: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800AEF94: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800AEF98: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800AEF9C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800AEFA0: lhu         $v0, 0x184($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X184);
    // 0x800AEFA4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800AEFA8: beq         $v0, $zero, L_800AF03C
    if (ctx->r2 == 0) {
        // 0x800AEFAC: lui         $a2, 0x8014
        ctx->r6 = S32(0X8014 << 16);
            goto L_800AF03C;
    }
    // 0x800AEFAC: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800AEFB0: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x800AEFB4: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800AEFB8: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AEFBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AEFC0: jal         0x800698F4
    // 0x800AEFC4: sb          $v0, 0x24C($s0)
    MEM_B(0X24C, ctx->r16) = ctx->r2;
    func_800698F4(rdram, ctx);
        goto after_0;
    // 0x800AEFC4: sb          $v0, 0x24C($s0)
    MEM_B(0X24C, ctx->r16) = ctx->r2;
    after_0:
    // 0x800AEFC8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800AEFCC: beq         $v1, $zero, L_800AEFE0
    if (ctx->r3 == 0) {
        // 0x800AEFD0: addiu       $a0, $s0, 0x208
        ctx->r4 = ADD32(ctx->r16, 0X208);
            goto L_800AEFE0;
    }
    // 0x800AEFD0: addiu       $a0, $s0, 0x208
    ctx->r4 = ADD32(ctx->r16, 0X208);
    // 0x800AEFD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AEFD8: beq         $v1, $v0, L_800AF004
    if (ctx->r3 == ctx->r2) {
        // 0x800AEFDC: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_800AF004;
    }
    // 0x800AEFDC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
L_800AEFE0:
    // 0x800AEFE0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800AEFE4: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    // 0x800AEFE8: lui         $a3, 0x4190
    ctx->r7 = S32(0X4190 << 16);
    // 0x800AEFEC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AEFF0: lwc1        $f0, 0x5498($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5498);
    // 0x800AEFF4: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800AEFF8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x800AEFFC: j           L_800AF020
    // 0x800AF000: addiu       $v0, $zero, 0x7E
    ctx->r2 = ADD32(0, 0X7E);
        goto L_800AF020;
    // 0x800AF000: addiu       $v0, $zero, 0x7E
    ctx->r2 = ADD32(0, 0X7E);
L_800AF004:
    // 0x800AF004: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    // 0x800AF008: lui         $a3, 0x4190
    ctx->r7 = S32(0X4190 << 16);
    // 0x800AF00C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF010: lwc1        $f0, 0x549C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X549C);
    // 0x800AF014: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800AF018: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x800AF01C: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
L_800AF020:
    // 0x800AF020: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800AF024: addiu       $v0, $zero, 0x7D
    ctx->r2 = ADD32(0, 0X7D);
    // 0x800AF028: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800AF02C: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x800AF030: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800AF034: jal         0x800989D8
    // 0x800AF038: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_1;
    // 0x800AF038: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_1:
L_800AF03C:
    // 0x800AF03C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800AF040: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800AF044: jr          $ra
    // 0x800AF048: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800AF048: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800AEFC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEFC8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800AEFCC: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800AEFD0: addiu       $v1, $v0, 0xD00
    ctx->r3 = ADD32(ctx->r2, 0XD00);
L_800AEFD4:
    // 0x800AEFD4: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x800AEFD8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800AEFDC: sltiu       $v0, $a0, 0x40
    ctx->r2 = ctx->r4 < 0X40 ? 1 : 0;
    // 0x800AEFE0: bne         $v0, $zero, L_800AEFD4
    if (ctx->r2 != 0) {
        // 0x800AEFE4: addiu       $v1, $v1, 0x30
        ctx->r3 = ADD32(ctx->r3, 0X30);
            goto L_800AEFD4;
    }
    // 0x800AEFE4: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x800AEFE8: jr          $ra
    // 0x800AEFEC: nop

    return;
    // 0x800AEFEC: nop

;}
RECOMP_FUNC void func_800AEFF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEFF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AEFF4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800AEFF8: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800AEFFC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800AF000: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800AF004: addiu       $a0, $v0, 0xD00
    ctx->r4 = ADD32(ctx->r2, 0XD00);
L_800AF008:
    // 0x800AF008: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800AF00C: bne         $v0, $zero, L_800AF024
    if (ctx->r2 != 0) {
        // 0x800AF010: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800AF024;
    }
    // 0x800AF010: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800AF014: jal         0x80018EF4
    // 0x800AF018: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    zmemcpy(rdram, ctx);
        goto after_0;
    // 0x800AF018: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_0:
    // 0x800AF01C: j           L_800AF030
    // 0x800AF020: nop

        goto L_800AF030;
    // 0x800AF020: nop

L_800AF024:
    // 0x800AF024: sltiu       $v0, $v1, 0x40
    ctx->r2 = ctx->r3 < 0X40 ? 1 : 0;
    // 0x800AF028: bne         $v0, $zero, L_800AF008
    if (ctx->r2 != 0) {
        // 0x800AF02C: addiu       $a0, $a0, 0x30
        ctx->r4 = ADD32(ctx->r4, 0X30);
            goto L_800AF008;
    }
    // 0x800AF02C: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
L_800AF030:
    // 0x800AF030: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800AF034: jr          $ra
    // 0x800AF038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800AF038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800AF03C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF03C: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // 0x800AF040: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AF044: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800AF048: addiu       $a3, $v0, -0x84C
    ctx->r7 = ADD32(ctx->r2, -0X84C);
    // 0x800AF04C: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
L_800AF050:
    // 0x800AF050: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800AF054: addu        $v1, $v0, $a3
    ctx->r3 = ADD32(ctx->r2, ctx->r7);
    // 0x800AF058: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800AF05C: bne         $v0, $a0, L_800AF070
    if (ctx->r2 != ctx->r4) {
        // 0x800AF060: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800AF070;
    }
    // 0x800AF060: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800AF064: lhu         $a2, 0x2($v1)
    ctx->r6 = MEM_HU(ctx->r3, 0X2);
    // 0x800AF068: jr          $ra
    // 0x800AF06C: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    return;
    // 0x800AF06C: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
L_800AF070:
    // 0x800AF070: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x800AF074: sltiu       $v0, $v0, 0x5E
    ctx->r2 = ctx->r2 < 0X5E ? 1 : 0;
    // 0x800AF078: bne         $v0, $zero, L_800AF050
    if (ctx->r2 != 0) {
        // 0x800AF07C: andi        $v0, $a1, 0xFFFF
        ctx->r2 = ctx->r5 & 0XFFFF;
            goto L_800AF050;
    }
    // 0x800AF07C: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x800AF080: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // 0x800AF084: jr          $ra
    // 0x800AF088: nop

    return;
    // 0x800AF088: nop

;}
RECOMP_FUNC void func_800AF04C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF04C: addiu       $sp, $sp, -0x128
    ctx->r29 = ADD32(ctx->r29, -0X128);
    // 0x800AF050: sw          $s4, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r20;
    // 0x800AF054: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x800AF058: sw          $s5, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r21;
    // 0x800AF05C: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x800AF060: sw          $s6, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r22;
    // 0x800AF064: addu        $s6, $a3, $zero
    ctx->r22 = ADD32(ctx->r7, 0);
    // 0x800AF068: addiu       $a0, $sp, 0xC8
    ctx->r4 = ADD32(ctx->r29, 0XC8);
    // 0x800AF06C: sdc1        $f26, 0x118($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X118, ctx->r29);
    // 0x800AF070: mtc1        $a1, $f26
    ctx->f26.u32l = ctx->r5;
    // 0x800AF074: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AF078: sw          $s7, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r23;
    // 0x800AF07C: lw          $s7, 0x138($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X138);
    // 0x800AF080: sw          $ra, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r31;
    // 0x800AF084: sw          $s3, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r19;
    // 0x800AF088: sw          $s2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r18;
    // 0x800AF08C: sw          $s1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r17;
    // 0x800AF090: sw          $s0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r16;
    // 0x800AF094: sdc1        $f28, 0x120($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X120, ctx->r29);
    // 0x800AF098: sdc1        $f24, 0x110($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X110, ctx->r29);
    // 0x800AF09C: sdc1        $f22, 0x108($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X108, ctx->r29);
    // 0x800AF0A0: sdc1        $f20, 0x100($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X100, ctx->r29);
    // 0x800AF0A4: jal         0x800078E0
    // 0x800AF0A8: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    rs_memset(rdram, ctx);
        goto after_0;
    // 0x800AF0A8: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_0:
    // 0x800AF0AC: lbu         $v0, 0x24C($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X24C);
    // 0x800AF0B0: beq         $v0, $zero, L_800AF108
    if (ctx->r2 == 0) {
        // 0x800AF0B4: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800AF108;
    }
    // 0x800AF0B4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AF0B8: lw          $v0, -0x35E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E0);
    // 0x800AF0BC: bne         $v0, $zero, L_800AF10C
    if (ctx->r2 != 0) {
        // 0x800AF0C0: lui         $a2, 0x8014
        ctx->r6 = S32(0X8014 << 16);
            goto L_800AF10C;
    }
    // 0x800AF0C0: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800AF0C4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800AF0C8: lw          $v1, 0xB8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0XB8);
    // 0x800AF0CC: addiu       $a0, $a0, 0x7DB8
    ctx->r4 = ADD32(ctx->r4, 0X7DB8);
    // 0x800AF0D0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800AF0D4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800AF0D8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800AF0DC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800AF0E0: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800AF0E4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800AF0E8: lhu         $v0, 0x184($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X184);
    // 0x800AF0EC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800AF0F0: beq         $v0, $zero, L_800AF10C
    if (ctx->r2 == 0) {
        // 0x800AF0F4: addiu       $a0, $s4, 0x208
        ctx->r4 = ADD32(ctx->r20, 0X208);
            goto L_800AF10C;
    }
    // 0x800AF0F4: addiu       $a0, $s4, 0x208
    ctx->r4 = ADD32(ctx->r20, 0X208);
    // 0x800AF0F8: addiu       $a1, $s4, 0x4
    ctx->r5 = ADD32(ctx->r20, 0X4);
    // 0x800AF0FC: addiu       $a2, $s4, 0x10
    ctx->r6 = ADD32(ctx->r20, 0X10);
    // 0x800AF100: jal         0x800988E8
    // 0x800AF104: addiu       $a3, $zero, 0x7D
    ctx->r7 = ADD32(0, 0X7D);
    func_800988E8(rdram, ctx);
        goto after_1;
    // 0x800AF104: addiu       $a3, $zero, 0x7D
    ctx->r7 = ADD32(0, 0X7D);
    after_1:
L_800AF108:
    // 0x800AF108: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
L_800AF10C:
    // 0x800AF10C: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x800AF110: lwc1        $f12, 0x4($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X4);
    // 0x800AF114: lwc1        $f14, 0xC($s4)
    ctx->f14.u32l = MEM_W(ctx->r20, 0XC);
    // 0x800AF118: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF11C: lwc1        $f20, 0x54A0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X54A0);
    // 0x800AF120: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF124: lwc1        $f22, 0x54A4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X54A4);
    // 0x800AF128: jal         0x80067D90
    // 0x800AF12C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80067D90(rdram, ctx);
        goto after_2;
    // 0x800AF12C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_2:
    // 0x800AF130: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF134: lwc1        $f4, 0x54A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X54A8);
    // 0x800AF138: lhu         $v1, 0xB4($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0XB4);
    // 0x800AF13C: lwc1        $f2, 0x8($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X8);
    // 0x800AF140: sltiu       $v0, $v1, 0x9
    ctx->r2 = ctx->r3 < 0X9 ? 1 : 0;
    // 0x800AF144: beq         $v0, $zero, L_800AF298
    if (ctx->r2 == 0) {
        // 0x800AF148: sub.s       $f24, $f0, $f2
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800AF298;
    }
    // 0x800AF148: sub.s       $f24, $f0, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800AF14C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800AF150: addiu       $v0, $v0, 0x54B0
    ctx->r2 = ADD32(ctx->r2, 0X54B0);
    // 0x800AF154: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800AF158: addu        $v1, $v1, $v0
    gpr jr_addend_800AF160 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800AF15C: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800AF160: jr          $v0
    // 0x800AF164: nop

    switch (jr_addend_800AF160 >> 2) {
        case 0: goto L_800AF298; break;
        case 1: goto L_800AF298; break;
        case 2: goto L_800AF168; break;
        case 3: goto L_800AF178; break;
        case 4: goto L_800AF188; break;
        case 5: goto L_800AF234; break;
        case 6: goto L_800AF254; break;
        case 7: goto L_800AF26C; break;
        case 8: goto L_800AF28C; break;
        default: switch_error(__func__, 0x800AF160, 0x800A54B0);
    }
    // 0x800AF164: nop

L_800AF168:
    // 0x800AF168: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF16C: lwc1        $f20, 0x54D4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X54D4);
    // 0x800AF170: j           L_800AF298
    // 0x800AF174: nop

        goto L_800AF298;
    // 0x800AF174: nop

L_800AF178:
    // 0x800AF178: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF17C: lwc1        $f4, 0x54D8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X54D8);
    // 0x800AF180: j           L_800AF298
    // 0x800AF184: nop

        goto L_800AF298;
    // 0x800AF184: nop

L_800AF188:
    // 0x800AF188: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF18C: lwc1        $f4, 0x54DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X54DC);
    // 0x800AF190: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF194: lwc1        $f20, 0x54E0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X54E0);
    // 0x800AF198: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF19C: lwc1        $f22, 0x54E4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X54E4);
    // 0x800AF1A0: c.lt.s      $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f24.fl < ctx->f4.fl;
    // 0x800AF1A4: nop

    // 0x800AF1A8: bc1f        L_800AF20C
    if (!c1cs) {
        // 0x800AF1AC: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800AF20C;
    }
    // 0x800AF1AC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800AF1B0: lw          $v0, -0x72E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X72E4);
    // 0x800AF1B4: lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X4);
    // 0x800AF1B8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800AF1BC: beq         $v1, $v0, L_800AF1FC
    if (ctx->r3 == ctx->r2) {
        // 0x800AF1C0: addiu       $a1, $s4, 0x4
        ctx->r5 = ADD32(ctx->r20, 0X4);
            goto L_800AF1FC;
    }
    // 0x800AF1C0: addiu       $a1, $s4, 0x4
    ctx->r5 = ADD32(ctx->r20, 0X4);
    // 0x800AF1C4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800AF1C8: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x800AF1CC: lhu         $a0, 0xB6($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0XB6);
    // 0x800AF1D0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF1D4: lwc1        $f0, 0x54E8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X54E8);
    // 0x800AF1D8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF1DC: lwc1        $f2, 0x54EC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X54EC);
    // 0x800AF1E0: addiu       $v0, $sp, 0xC8
    ctx->r2 = ADD32(ctx->r29, 0XC8);
    // 0x800AF1E4: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x800AF1E8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800AF1EC: swc1        $f22, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f22.u32l;
    // 0x800AF1F0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800AF1F4: jal         0x80077250
    // 0x800AF1F8: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    func_80077250(rdram, ctx);
        goto after_3;
    // 0x800AF1F8: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    after_3:
L_800AF1FC:
    // 0x800AF1FC: jal         0x800AEF58
    // 0x800AF200: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    func_800AEF58(rdram, ctx);
        goto after_4;
    // 0x800AF200: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_4:
    // 0x800AF204: j           L_800AF224
    // 0x800AF208: nop

        goto L_800AF224;
    // 0x800AF208: nop

L_800AF20C:
    // 0x800AF20C: lbu         $v0, 0x24C($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X24C);
    // 0x800AF210: beq         $v0, $zero, L_800AF224
    if (ctx->r2 == 0) {
        // 0x800AF214: nop
    
            goto L_800AF224;
    }
    // 0x800AF214: nop

    // 0x800AF218: sb          $zero, 0x24C($s4)
    MEM_B(0X24C, ctx->r20) = 0;
    // 0x800AF21C: jal         0x80098DE0
    // 0x800AF220: addiu       $a0, $s4, 0x208
    ctx->r4 = ADD32(ctx->r20, 0X208);
    func_80098DE0(rdram, ctx);
        goto after_5;
    // 0x800AF220: addiu       $a0, $s4, 0x208
    ctx->r4 = ADD32(ctx->r20, 0X208);
    after_5:
L_800AF224:
    // 0x800AF224: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF228: lwc1        $f4, 0x54F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X54F0);
    // 0x800AF22C: j           L_800AF298
    // 0x800AF230: nop

        goto L_800AF298;
    // 0x800AF230: nop

L_800AF234:
    // 0x800AF234: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF238: lwc1        $f4, 0x54F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X54F4);
    // 0x800AF23C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF240: lwc1        $f20, 0x54F8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X54F8);
    // 0x800AF244: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF248: lwc1        $f22, 0x54FC($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X54FC);
    // 0x800AF24C: j           L_800AF298
    // 0x800AF250: nop

        goto L_800AF298;
    // 0x800AF250: nop

L_800AF254:
    // 0x800AF254: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF258: lwc1        $f20, 0x5500($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5500);
    // 0x800AF25C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF260: lwc1        $f22, 0x5504($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X5504);
    // 0x800AF264: j           L_800AF298
    // 0x800AF268: nop

        goto L_800AF298;
    // 0x800AF268: nop

L_800AF26C:
    // 0x800AF26C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF270: lwc1        $f20, 0x5508($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5508);
    // 0x800AF274: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF278: lwc1        $f4, 0x550C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X550C);
    // 0x800AF27C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF280: lwc1        $f22, 0x5510($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X5510);
    // 0x800AF284: j           L_800AF298
    // 0x800AF288: nop

        goto L_800AF298;
    // 0x800AF288: nop

L_800AF28C:
    // 0x800AF28C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF290: lwc1        $f20, 0x5514($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5514);
    // 0x800AF294: mov.s       $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    ctx->f22.fl = ctx->f20.fl;
L_800AF298:
    // 0x800AF298: c.lt.s      $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f24.fl < ctx->f4.fl;
    // 0x800AF29C: nop

    // 0x800AF2A0: bc1f        L_800AF30C
    if (!c1cs) {
        // 0x800AF2A4: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800AF30C;
    }
    // 0x800AF2A4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800AF2A8: lw          $v0, -0x72E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X72E4);
    // 0x800AF2AC: lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X4);
    // 0x800AF2B0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800AF2B4: beq         $v1, $v0, L_800AF2FC
    if (ctx->r3 == ctx->r2) {
        // 0x800AF2B8: addiu       $a1, $s4, 0x4
        ctx->r5 = ADD32(ctx->r20, 0X4);
            goto L_800AF2FC;
    }
    // 0x800AF2B8: addiu       $a1, $s4, 0x4
    ctx->r5 = ADD32(ctx->r20, 0X4);
    // 0x800AF2BC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800AF2C0: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800AF2C4: lhu         $a0, 0xB6($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0XB6);
    // 0x800AF2C8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF2CC: lwc1        $f0, 0x5518($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5518);
    // 0x800AF2D0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF2D4: lwc1        $f2, 0x551C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X551C);
    // 0x800AF2D8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF2DC: lwc1        $f4, 0x5520($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5520);
    // 0x800AF2E0: addiu       $v0, $sp, 0xC8
    ctx->r2 = ADD32(ctx->r29, 0XC8);
    // 0x800AF2E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800AF2E8: swc1        $f22, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f22.u32l;
    // 0x800AF2EC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800AF2F0: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800AF2F4: jal         0x80077250
    // 0x800AF2F8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    func_80077250(rdram, ctx);
        goto after_6;
    // 0x800AF2F8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_6:
L_800AF2FC:
    // 0x800AF2FC: jal         0x800AEF58
    // 0x800AF300: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    func_800AEF58(rdram, ctx);
        goto after_7;
    // 0x800AF300: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_7:
    // 0x800AF304: j           L_800AF324
    // 0x800AF308: nop

        goto L_800AF324;
    // 0x800AF308: nop

L_800AF30C:
    // 0x800AF30C: lbu         $v0, 0x24C($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X24C);
    // 0x800AF310: beq         $v0, $zero, L_800AF324
    if (ctx->r2 == 0) {
        // 0x800AF314: nop
    
            goto L_800AF324;
    }
    // 0x800AF314: nop

    // 0x800AF318: sb          $zero, 0x24C($s4)
    MEM_B(0X24C, ctx->r20) = 0;
    // 0x800AF31C: jal         0x80098DE0
    // 0x800AF320: addiu       $a0, $s4, 0x208
    ctx->r4 = ADD32(ctx->r20, 0X208);
    func_80098DE0(rdram, ctx);
        goto after_8;
    // 0x800AF320: addiu       $a0, $s4, 0x208
    ctx->r4 = ADD32(ctx->r20, 0X208);
    after_8:
L_800AF324:
    // 0x800AF324: lhu         $v1, 0xB4($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0XB4);
    // 0x800AF328: slti        $v0, $v1, 0x5
    ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x800AF32C: beq         $v0, $zero, L_800AF438
    if (ctx->r2 == 0) {
        // 0x800AF330: slti        $v0, $v1, 0x3
        ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_800AF438;
    }
    // 0x800AF330: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800AF334: bne         $v0, $zero, L_800AF43C
    if (ctx->r2 != 0) {
        // 0x800AF338: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800AF43C;
    }
    // 0x800AF338: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AF33C: lwc1        $f0, 0xE8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XE8);
    // 0x800AF340: mul.s       $f22, $f0, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f22.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x800AF344: lwc1        $f0, 0x10($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X10);
    // 0x800AF348: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800AF34C: lwc1        $f12, 0x4($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X4);
    // 0x800AF350: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x800AF354: swc1        $f12, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f12.u32l;
    // 0x800AF358: lwc1        $f2, 0x14($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X14);
    // 0x800AF35C: mul.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x800AF360: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x800AF364: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800AF368: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    // 0x800AF36C: lwc1        $f0, 0x18($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X18);
    // 0x800AF370: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800AF374: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800AF378: lwc1        $f14, 0xC($s4)
    ctx->f14.u32l = MEM_W(ctx->r20, 0XC);
    // 0x800AF37C: addiu       $s0, $v0, -0x7FA8
    ctx->r16 = ADD32(ctx->r2, -0X7FA8);
    // 0x800AF380: add.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x800AF384: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800AF388: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x800AF38C: jal         0x80068180
    // 0x800AF390: swc1        $f14, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f14.u32l;
    func_80068180(rdram, ctx);
        goto after_9;
    // 0x800AF390: swc1        $f14, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f14.u32l;
    after_9:
    // 0x800AF394: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AF398: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800AF39C: lwc1        $f2, 0x108($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X108);
    // 0x800AF3A0: neg.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f28.fl = -ctx->f0.fl;
    // 0x800AF3A4: add.s       $f20, $f2, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f2.fl + ctx->f28.fl;
    // 0x800AF3A8: lwc1        $f0, -0x485C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X485C);
    // 0x800AF3AC: lwc1        $f2, -0x4860($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, -0X4860);
    // 0x800AF3B0: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x800AF3B4: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x800AF3B8: nop

    // 0x800AF3BC: bc1f        L_800AF3C8
    if (!c1cs) {
        // 0x800AF3C0: neg.s       $f24, $f0
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = -ctx->f0.fl;
            goto L_800AF3C8;
    }
    // 0x800AF3C0: neg.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = -ctx->f0.fl;
    // 0x800AF3C4: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
L_800AF3C8:
    // 0x800AF3C8: lwc1        $f0, 0xE8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XE8);
    // 0x800AF3CC: mul.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x800AF3D0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF3D4: lwc1        $f2, 0x5524($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5524);
    // 0x800AF3D8: mul.s       $f22, $f0, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800AF3DC: lwc1        $f0, 0x10($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X10);
    // 0x800AF3E0: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800AF3E4: lwc1        $f12, 0x4($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X4);
    // 0x800AF3E8: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x800AF3EC: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x800AF3F0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800AF3F4: swc1        $f0, 0x100($s4)
    MEM_W(0X100, ctx->r20) = ctx->f0.u32l;
    // 0x800AF3F8: swc1        $f12, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f12.u32l;
    // 0x800AF3FC: lwc1        $f2, 0x14($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X14);
    // 0x800AF400: mul.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x800AF404: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x800AF408: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800AF40C: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    // 0x800AF410: lwc1        $f0, 0x18($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X18);
    // 0x800AF414: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800AF418: lwc1        $f14, 0xC($s4)
    ctx->f14.u32l = MEM_W(ctx->r20, 0XC);
    // 0x800AF41C: add.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x800AF420: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800AF424: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    // 0x800AF428: jal         0x80068180
    // 0x800AF42C: swc1        $f14, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f14.u32l;
    func_80068180(rdram, ctx);
        goto after_10;
    // 0x800AF42C: swc1        $f14, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f14.u32l;
    after_10:
    // 0x800AF430: j           L_800AF45C
    // 0x800AF434: nop

        goto L_800AF45C;
    // 0x800AF434: nop

L_800AF438:
    // 0x800AF438: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800AF43C:
    // 0x800AF43C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800AF440: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x800AF444: lwc1        $f2, -0x4860($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, -0X4860);
    // 0x800AF448: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800AF44C: swc1        $f0, 0x100($s4)
    MEM_W(0X100, ctx->r20) = ctx->f0.u32l;
    // 0x800AF450: lwc1        $f0, -0x485C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X485C);
    // 0x800AF454: neg.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = -ctx->f2.fl;
    // 0x800AF458: neg.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = -ctx->f0.fl;
L_800AF45C:
    // 0x800AF45C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF460: lwc1        $f4, 0x5528($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5528);
    // 0x800AF464: sub.s       $f0, $f20, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f20.fl - ctx->f4.fl;
    // 0x800AF468: lwc1        $f2, 0x100($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X100);
    // 0x800AF46C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800AF470: nop

    // 0x800AF474: bc1f        L_800AF5E0
    if (!c1cs) {
        // 0x800AF478: nop
    
            goto L_800AF5E0;
    }
    // 0x800AF478: nop

    // 0x800AF47C: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x800AF480: nop

    // 0x800AF484: bc1f        L_800AF4A4
    if (!c1cs) {
        // 0x800AF488: nop
    
            goto L_800AF4A4;
    }
    // 0x800AF488: nop

    // 0x800AF48C: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800AF490: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF494: lwc1        $f2, 0x552C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X552C);
    // 0x800AF498: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800AF49C: j           L_800AF4A8
    // 0x800AF4A0: sub.s       $f22, $f2, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f2.fl - ctx->f0.fl;
        goto L_800AF4A8;
    // 0x800AF4A0: sub.s       $f22, $f2, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f2.fl - ctx->f0.fl;
L_800AF4A4:
    // 0x800AF4A4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
L_800AF4A8:
    // 0x800AF4A8: lwc1        $f0, 0x14($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X14);
    // 0x800AF4AC: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x800AF4B0: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x800AF4B4: nop

    // 0x800AF4B8: bc1f        L_800AF5AC
    if (!c1cs) {
        // 0x800AF4BC: nop
    
            goto L_800AF5AC;
    }
    // 0x800AF4BC: nop

    // 0x800AF4C0: lwc1        $f0, 0xE8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XE8);
    // 0x800AF4C4: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    // 0x800AF4C8: nop

    // 0x800AF4CC: bc1f        L_800AF5AC
    if (!c1cs) {
        // 0x800AF4D0: addiu       $s2, $s4, 0x10
        ctx->r18 = ADD32(ctx->r20, 0X10);
            goto L_800AF5AC;
    }
    // 0x800AF4D0: addiu       $s2, $s4, 0x10
    ctx->r18 = ADD32(ctx->r20, 0X10);
    // 0x800AF4D4: lw          $t0, 0x10($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X10);
    // 0x800AF4D8: lw          $t1, 0x14($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X14);
    // 0x800AF4DC: lw          $t2, 0x18($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X18);
    // 0x800AF4E0: sw          $t0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r8;
    // 0x800AF4E4: sw          $t1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r9;
    // 0x800AF4E8: sw          $t2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r10;
    // 0x800AF4EC: lwc1        $f0, 0x14($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X14);
    // 0x800AF4F0: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800AF4F4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800AF4F8: jal         0x8001CF58
    // 0x800AF4FC: swc1        $f0, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->f0.u32l;
    normalize_vector(rdram, ctx);
        goto after_11;
    // 0x800AF4FC: swc1        $f0, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->f0.u32l;
    after_11:
    // 0x800AF500: addiu       $s3, $sp, 0xA8
    ctx->r19 = ADD32(ctx->r29, 0XA8);
    // 0x800AF504: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800AF508: addiu       $s1, $sp, 0x88
    ctx->r17 = ADD32(ctx->r29, 0X88);
    // 0x800AF50C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800AF510: jal         0x80019548
    // 0x800AF514: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_80019548(rdram, ctx);
        goto after_12;
    // 0x800AF514: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_12:
    // 0x800AF518: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800AF51C: jal         0x8001CFE8
    // 0x800AF520: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_8001CFE8(rdram, ctx);
        goto after_13;
    // 0x800AF520: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_13:
    // 0x800AF524: jal         0x8001C5CC
    // 0x800AF528: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8001C5CC(rdram, ctx);
        goto after_14;
    // 0x800AF528: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_14:
    // 0x800AF52C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF530: lwc1        $f2, 0x5530($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5530);
    // 0x800AF534: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800AF538: addiu       $s0, $sp, 0xB8
    ctx->r16 = ADD32(ctx->r29, 0XB8);
    // 0x800AF53C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800AF540: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800AF544: jal         0x8001D144
    // 0x800AF548: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8001D144(rdram, ctx);
        goto after_15;
    // 0x800AF548: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_15:
    // 0x800AF54C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800AF550: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800AF554: jal         0x8001D3C4
    // 0x800AF558: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_8001D3C4(rdram, ctx);
        goto after_16;
    // 0x800AF558: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_16:
    // 0x800AF55C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800AF560: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800AF564: lw          $t0, 0x1C($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X1C);
    // 0x800AF568: lw          $t1, 0x20($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X20);
    // 0x800AF56C: lw          $t2, 0x24($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X24);
    // 0x800AF570: sw          $t0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r8;
    // 0x800AF574: sw          $t1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r9;
    // 0x800AF578: sw          $t2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r10;
    // 0x800AF57C: jal         0x8001D3C4
    // 0x800AF580: addiu       $a2, $s4, 0x1C
    ctx->r6 = ADD32(ctx->r20, 0X1C);
    func_8001D3C4(rdram, ctx);
        goto after_17;
    // 0x800AF580: addiu       $a2, $s4, 0x1C
    ctx->r6 = ADD32(ctx->r20, 0X1C);
    after_17:
    // 0x800AF584: lwc1        $f0, 0x0($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800AF588: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800AF58C: swc1        $f0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f0.u32l;
    // 0x800AF590: lwc1        $f0, 0xDC($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XDC);
    // 0x800AF594: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x800AF598: nop

    // 0x800AF59C: bc1f        L_800AF5AC
    if (!c1cs) {
        // 0x800AF5A0: nop
    
            goto L_800AF5AC;
    }
    // 0x800AF5A0: nop

    // 0x800AF5A4: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800AF5A8: swc1        $f0, 0xDC($s4)
    MEM_W(0XDC, ctx->r20) = ctx->f0.u32l;
L_800AF5AC:
    // 0x800AF5AC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AF5B0: c.eq.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl == ctx->f0.fl;
    // 0x800AF5B4: nop

    // 0x800AF5B8: bc1f        L_800AFC44
    if (!c1cs) {
        // 0x800AF5BC: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800AFC44;
    }
    // 0x800AF5BC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800AF5C0: lwc1        $f0, 0x100($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X100);
    // 0x800AF5C4: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800AF5C8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF5CC: lwc1        $f2, 0x5534($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5534);
    // 0x800AF5D0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800AF5D4: lwc1        $f2, 0x8($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X8);
    // 0x800AF5D8: j           L_800AFC3C
    // 0x800AF5DC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
        goto L_800AFC3C;
    // 0x800AF5DC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
L_800AF5E0:
    // 0x800AF5E0: lhu         $v1, 0xB4($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0XB4);
    // 0x800AF5E4: addiu       $v0, $v1, -0x3
    ctx->r2 = ADD32(ctx->r3, -0X3);
    // 0x800AF5E8: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800AF5EC: beq         $v0, $zero, L_800AFAC8
    if (ctx->r2 == 0) {
        // 0x800AF5F0: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800AFAC8;
    }
    // 0x800AF5F0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800AF5F4: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x800AF5F8: neg.s       $f2, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); 
    ctx->f2.fl = -ctx->f28.fl;
    // 0x800AF5FC: bne         $v1, $v0, L_800AF61C
    if (ctx->r3 != ctx->r2) {
        // 0x800AF600: sub.s       $f28, $f2, $f0
        CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f28.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_800AF61C;
    }
    // 0x800AF600: sub.s       $f28, $f2, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f28.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800AF604: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF608: lwc1        $f0, 0x5538($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5538);
    // 0x800AF60C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF610: lwc1        $f24, 0x553C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X553C);
    // 0x800AF614: j           L_800AF62C
    // 0x800AF618: nop

        goto L_800AF62C;
    // 0x800AF618: nop

L_800AF61C:
    // 0x800AF61C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF620: lwc1        $f0, 0x5540($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5540);
    // 0x800AF624: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF628: lwc1        $f24, 0x5544($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X5544);
L_800AF62C:
    // 0x800AF62C: c.le.s      $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f28.fl <= ctx->f0.fl;
    // 0x800AF630: nop

    // 0x800AF634: bc1f        L_800AFC44
    if (!c1cs) {
        // 0x800AF638: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800AFC44;
    }
    // 0x800AF638: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800AF63C: c.lt.s      $f24, $f28
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f24.fl < ctx->f28.fl;
    // 0x800AF640: nop

    // 0x800AF644: bc1f        L_800AF65C
    if (!c1cs) {
        // 0x800AF648: nop
    
            goto L_800AF65C;
    }
    // 0x800AF648: nop

    // 0x800AF64C: sub.s       $f2, $f0, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f28.fl;
    // 0x800AF650: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x800AF654: j           L_800AF664
    // 0x800AF658: div.s       $f22, $f2, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
        goto L_800AF664;
    // 0x800AF658: div.s       $f22, $f2, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
L_800AF65C:
    // 0x800AF65C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF660: lwc1        $f22, 0x5548($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X5548);
L_800AF664:
    // 0x800AF664: lbu         $v0, 0x1BC($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X1BC);
    // 0x800AF668: beq         $v0, $zero, L_800AF7D8
    if (ctx->r2 == 0) {
        // 0x800AF66C: addiu       $s2, $zero, 0x1A4
        ctx->r18 = ADD32(0, 0X1A4);
            goto L_800AF7D8;
    }
    // 0x800AF66C: addiu       $s2, $zero, 0x1A4
    ctx->r18 = ADD32(0, 0X1A4);
    // 0x800AF670: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF674: lwc1        $f20, 0x554C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X554C);
    // 0x800AF678: addiu       $s3, $sp, 0x28
    ctx->r19 = ADD32(ctx->r29, 0X28);
    // 0x800AF67C: addu        $s1, $s3, $zero
    ctx->r17 = ADD32(ctx->r19, 0);
    // 0x800AF680: addu        $s0, $s4, $zero
    ctx->r16 = ADD32(ctx->r20, 0);
L_800AF684:
    // 0x800AF684: lwc1        $f2, 0x1A4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1A4);
    // 0x800AF688: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800AF68C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800AF690: nop

    // 0x800AF694: bc1f        L_800AF6B8
    if (!c1cs) {
        // 0x800AF698: nop
    
            goto L_800AF6B8;
    }
    // 0x800AF698: nop

    // 0x800AF69C: mul.s       $f0, $f26, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f26.fl, ctx->f20.fl);
    // 0x800AF6A0: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800AF6A4: swc1        $f0, 0x1A4($s0)
    MEM_W(0X1A4, ctx->r16) = ctx->f0.u32l;
    // 0x800AF6A8: lwc1        $f2, 0xC($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800AF6AC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800AF6B0: j           L_800AF6DC
    // 0x800AF6B4: nop

        goto L_800AF6DC;
    // 0x800AF6B4: nop

L_800AF6B8:
    // 0x800AF6B8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800AF6BC: nop

    // 0x800AF6C0: bc1f        L_800AF6E8
    if (!c1cs) {
        // 0x800AF6C4: nop
    
            goto L_800AF6E8;
    }
    // 0x800AF6C4: nop

    // 0x800AF6C8: mul.s       $f0, $f26, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f26.fl, ctx->f20.fl);
    // 0x800AF6CC: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800AF6D0: swc1        $f0, 0x1A4($s0)
    MEM_W(0X1A4, ctx->r16) = ctx->f0.u32l;
    // 0x800AF6D4: lwc1        $f2, 0xC($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800AF6D8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_800AF6DC:
    // 0x800AF6DC: nop

    // 0x800AF6E0: bc1tl       L_800AF6E8
    if (c1cs) {
        // 0x800AF6E4: swc1        $f2, 0x1A4($s0)
        MEM_W(0X1A4, ctx->r16) = ctx->f2.u32l;
            goto L_800AF6E8;
    }
    goto skip_0;
    // 0x800AF6E4: swc1        $f2, 0x1A4($s0)
    MEM_W(0X1A4, ctx->r16) = ctx->f2.u32l;
    skip_0:
L_800AF6E8:
    // 0x800AF6E8: lwc1        $f2, 0x1A8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1A8);
    // 0x800AF6EC: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800AF6F0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800AF6F4: nop

    // 0x800AF6F8: bc1f        L_800AF71C
    if (!c1cs) {
        // 0x800AF6FC: nop
    
            goto L_800AF71C;
    }
    // 0x800AF6FC: nop

    // 0x800AF700: mul.s       $f0, $f26, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f26.fl, ctx->f20.fl);
    // 0x800AF704: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800AF708: swc1        $f0, 0x1A8($s0)
    MEM_W(0X1A8, ctx->r16) = ctx->f0.u32l;
    // 0x800AF70C: lwc1        $f2, 0x10($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800AF710: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800AF714: j           L_800AF740
    // 0x800AF718: nop

        goto L_800AF740;
    // 0x800AF718: nop

L_800AF71C:
    // 0x800AF71C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800AF720: nop

    // 0x800AF724: bc1f        L_800AF74C
    if (!c1cs) {
        // 0x800AF728: nop
    
            goto L_800AF74C;
    }
    // 0x800AF728: nop

    // 0x800AF72C: mul.s       $f0, $f26, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f26.fl, ctx->f20.fl);
    // 0x800AF730: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800AF734: swc1        $f0, 0x1A8($s0)
    MEM_W(0X1A8, ctx->r16) = ctx->f0.u32l;
    // 0x800AF738: lwc1        $f2, 0x10($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800AF73C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_800AF740:
    // 0x800AF740: nop

    // 0x800AF744: bc1tl       L_800AF74C
    if (c1cs) {
        // 0x800AF748: swc1        $f2, 0x1A8($s0)
        MEM_W(0X1A8, ctx->r16) = ctx->f2.u32l;
            goto L_800AF74C;
    }
    goto skip_1;
    // 0x800AF748: swc1        $f2, 0x1A8($s0)
    MEM_W(0X1A8, ctx->r16) = ctx->f2.u32l;
    skip_1:
L_800AF74C:
    // 0x800AF74C: lwc1        $f2, 0x1AC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1AC);
    // 0x800AF750: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800AF754: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800AF758: nop

    // 0x800AF75C: bc1f        L_800AF780
    if (!c1cs) {
        // 0x800AF760: nop
    
            goto L_800AF780;
    }
    // 0x800AF760: nop

    // 0x800AF764: mul.s       $f0, $f26, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f26.fl, ctx->f20.fl);
    // 0x800AF768: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800AF76C: swc1        $f0, 0x1AC($s0)
    MEM_W(0X1AC, ctx->r16) = ctx->f0.u32l;
    // 0x800AF770: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800AF774: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800AF778: j           L_800AF7A4
    // 0x800AF77C: nop

        goto L_800AF7A4;
    // 0x800AF77C: nop

L_800AF780:
    // 0x800AF780: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800AF784: nop

    // 0x800AF788: bc1f        L_800AF7B0
    if (!c1cs) {
        // 0x800AF78C: nop
    
            goto L_800AF7B0;
    }
    // 0x800AF78C: nop

    // 0x800AF790: mul.s       $f0, $f26, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f26.fl, ctx->f20.fl);
    // 0x800AF794: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800AF798: swc1        $f0, 0x1AC($s0)
    MEM_W(0X1AC, ctx->r16) = ctx->f0.u32l;
    // 0x800AF79C: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800AF7A0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_800AF7A4:
    // 0x800AF7A4: nop

    // 0x800AF7A8: bc1tl       L_800AF7B0
    if (c1cs) {
        // 0x800AF7AC: swc1        $f2, 0x1AC($s0)
        MEM_W(0X1AC, ctx->r16) = ctx->f2.u32l;
            goto L_800AF7B0;
    }
    goto skip_2;
    // 0x800AF7AC: swc1        $f2, 0x1AC($s0)
    MEM_W(0X1AC, ctx->r16) = ctx->f2.u32l;
    skip_2:
L_800AF7B0:
    // 0x800AF7B0: jal         0x8001CF58
    // 0x800AF7B4: addu        $a0, $s4, $s2
    ctx->r4 = ADD32(ctx->r20, ctx->r18);
    normalize_vector(rdram, ctx);
        goto after_18;
    // 0x800AF7B4: addu        $a0, $s4, $s2
    ctx->r4 = ADD32(ctx->r20, ctx->r18);
    after_18:
    // 0x800AF7B8: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x800AF7BC: addiu       $s1, $s1, 0x28
    ctx->r17 = ADD32(ctx->r17, 0X28);
    // 0x800AF7C0: addiu       $v0, $s3, 0x50
    ctx->r2 = ADD32(ctx->r19, 0X50);
    // 0x800AF7C4: sltu        $v0, $s1, $v0
    ctx->r2 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x800AF7C8: bne         $v0, $zero, L_800AF684
    if (ctx->r2 != 0) {
        // 0x800AF7CC: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800AF684;
    }
    // 0x800AF7CC: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800AF7D0: j           L_800AF810
    // 0x800AF7D4: nop

        goto L_800AF810;
    // 0x800AF7D4: nop

L_800AF7D8:
    // 0x800AF7D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AF7DC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800AF7E0: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800AF7E4: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800AF7E8: sw          $t0, 0x1A4($s4)
    MEM_W(0X1A4, ctx->r20) = ctx->r8;
    // 0x800AF7EC: sw          $t1, 0x1A8($s4)
    MEM_W(0X1A8, ctx->r20) = ctx->r9;
    // 0x800AF7F0: sw          $t2, 0x1AC($s4)
    MEM_W(0X1AC, ctx->r20) = ctx->r10;
    // 0x800AF7F4: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800AF7F8: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x800AF7FC: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x800AF800: sw          $t0, 0x1B0($s4)
    MEM_W(0X1B0, ctx->r20) = ctx->r8;
    // 0x800AF804: sw          $t1, 0x1B4($s4)
    MEM_W(0X1B4, ctx->r20) = ctx->r9;
    // 0x800AF808: sw          $t2, 0x1B8($s4)
    MEM_W(0X1B8, ctx->r20) = ctx->r10;
    // 0x800AF80C: sb          $v0, 0x1BC($s4)
    MEM_B(0X1BC, ctx->r20) = ctx->r2;
L_800AF810:
    // 0x800AF810: lwc1        $f12, 0x0($s6)
    ctx->f12.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800AF814: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF818: lwc1        $f20, 0x5550($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5550);
    // 0x800AF81C: mul.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x800AF820: jal         0x80033960
    // 0x800AF824: addiu       $s1, $s4, 0x1A4
    ctx->r17 = ADD32(ctx->r20, 0X1A4);
    sinf_recomp(rdram, ctx);
        goto after_19;
    // 0x800AF824: addiu       $s1, $s4, 0x1A4
    ctx->r17 = ADD32(ctx->r20, 0X1A4);
    after_19:
    // 0x800AF828: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    // 0x800AF82C: sw          $zero, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = 0;
    // 0x800AF830: lwc1        $f12, 0x0($s6)
    ctx->f12.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800AF834: mul.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x800AF838: jal         0x8002B190
    // 0x800AF83C: addiu       $s2, $s4, 0x1B0
    ctx->r18 = ADD32(ctx->r20, 0X1B0);
    cosf_recomp(rdram, ctx);
        goto after_20;
    // 0x800AF83C: addiu       $s2, $s4, 0x1B0
    ctx->r18 = ADD32(ctx->r20, 0X1B0);
    after_20:
    // 0x800AF840: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800AF844: addiu       $s0, $sp, 0x88
    ctx->r16 = ADD32(ctx->r29, 0X88);
    // 0x800AF848: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800AF84C: jal         0x8001CFE8
    // 0x800AF850: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    func_8001CFE8(rdram, ctx);
        goto after_21;
    // 0x800AF850: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    after_21:
    // 0x800AF854: jal         0x8001C400
    // 0x800AF858: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8001C400(rdram, ctx);
        goto after_22;
    // 0x800AF858: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_22:
    // 0x800AF85C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF860: lwc1        $f20, 0x5554($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5554);
    // 0x800AF864: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800AF868: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800AF86C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800AF870: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800AF874: jal         0x8001CFE8
    // 0x800AF878: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    func_8001CFE8(rdram, ctx);
        goto after_23;
    // 0x800AF878: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    after_23:
    // 0x800AF87C: jal         0x8001C400
    // 0x800AF880: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8001C400(rdram, ctx);
        goto after_24;
    // 0x800AF880: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_24:
    // 0x800AF884: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800AF888: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800AF88C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800AF890: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800AF894: lwc1        $f2, 0x88($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800AF898: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800AF89C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x800AF8A0: swc1        $f2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f2.u32l;
    // 0x800AF8A4: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    // 0x800AF8A8: jal         0x8001CFE8
    // 0x800AF8AC: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    func_8001CFE8(rdram, ctx);
        goto after_25;
    // 0x800AF8AC: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    after_25:
    // 0x800AF8B0: jal         0x8001C400
    // 0x800AF8B4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8001C400(rdram, ctx);
        goto after_26;
    // 0x800AF8B4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_26:
    // 0x800AF8B8: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800AF8BC: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800AF8C0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800AF8C4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800AF8C8: jal         0x8001CFE8
    // 0x800AF8CC: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    func_8001CFE8(rdram, ctx);
        goto after_27;
    // 0x800AF8CC: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    after_27:
    // 0x800AF8D0: jal         0x8001C400
    // 0x800AF8D4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8001C400(rdram, ctx);
        goto after_28;
    // 0x800AF8D4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_28:
    // 0x800AF8D8: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800AF8DC: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800AF8E0: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800AF8E4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF8E8: lwc1        $f10, 0x5558($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5558);
    // 0x800AF8EC: mul.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AF8F0: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800AF8F4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF8F8: lwc1        $f4, 0x555C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X555C);
    // 0x800AF8FC: mul.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AF900: lwc1        $f2, 0x80($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800AF904: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800AF908: nop

    // 0x800AF90C: mul.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800AF910: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800AF914: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    // 0x800AF918: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800AF91C: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
    // 0x800AF920: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800AF924: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x800AF928: swc1        $f2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f2.u32l;
    // 0x800AF92C: lwc1        $f0, 0xDC($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XDC);
    // 0x800AF930: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800AF934: nop

    // 0x800AF938: bc1tl       L_800AF940
    if (c1cs) {
        // 0x800AF93C: swc1        $f4, 0xDC($s4)
        MEM_W(0XDC, ctx->r20) = ctx->f4.u32l;
            goto L_800AF940;
    }
    goto skip_3;
    // 0x800AF93C: swc1        $f4, 0xDC($s4)
    MEM_W(0XDC, ctx->r20) = ctx->f4.u32l;
    skip_3:
L_800AF940:
    // 0x800AF940: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AF944: lwc1        $f2, -0x4224($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X4224);
    // 0x800AF948: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF94C: lwc1        $f0, 0x5560($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5560);
    // 0x800AF950: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800AF954: nop

    // 0x800AF958: bc1f        L_800AF968
    if (!c1cs) {
        // 0x800AF95C: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800AF968;
    }
    // 0x800AF95C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AF960: j           L_800AFA00
    // 0x800AF964: swc1        $f4, -0x4394($v0)
    MEM_W(-0X4394, ctx->r2) = ctx->f4.u32l;
        goto L_800AFA00;
    // 0x800AF964: swc1        $f4, -0x4394($v0)
    MEM_W(-0X4394, ctx->r2) = ctx->f4.u32l;
L_800AF968:
    // 0x800AF968: lwc1        $f2, -0x4394($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X4394);
    // 0x800AF96C: c.eq.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl == ctx->f22.fl;
    // 0x800AF970: nop

    // 0x800AF974: bc1t        L_800AF9CC
    if (c1cs) {
        // 0x800AF978: nop
    
            goto L_800AF9CC;
    }
    // 0x800AF978: nop

    // 0x800AF97C: c.lt.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl < ctx->f22.fl;
    // 0x800AF980: nop

    // 0x800AF984: bc1f        L_800AF9A8
    if (!c1cs) {
        // 0x800AF988: nop
    
            goto L_800AF9A8;
    }
    // 0x800AF988: nop

    // 0x800AF98C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF990: lwc1        $f0, 0x5564($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5564);
    // 0x800AF994: mul.s       $f0, $f26, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x800AF998: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800AF99C: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x800AF9A0: j           L_800AF9C0
    // 0x800AF9A4: swc1        $f0, -0x4394($v0)
    MEM_W(-0X4394, ctx->r2) = ctx->f0.u32l;
        goto L_800AF9C0;
    // 0x800AF9A4: swc1        $f0, -0x4394($v0)
    MEM_W(-0X4394, ctx->r2) = ctx->f0.u32l;
L_800AF9A8:
    // 0x800AF9A8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF9AC: lwc1        $f0, 0x5568($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5568);
    // 0x800AF9B0: mul.s       $f0, $f26, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x800AF9B4: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800AF9B8: swc1        $f0, -0x4394($v0)
    MEM_W(-0X4394, ctx->r2) = ctx->f0.u32l;
    // 0x800AF9BC: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
L_800AF9C0:
    // 0x800AF9C0: nop

    // 0x800AF9C4: bc1tl       L_800AF9CC
    if (c1cs) {
        // 0x800AF9C8: swc1        $f22, -0x4394($v0)
        MEM_W(-0X4394, ctx->r2) = ctx->f22.u32l;
            goto L_800AF9CC;
    }
    goto skip_4;
    // 0x800AF9C8: swc1        $f22, -0x4394($v0)
    MEM_W(-0X4394, ctx->r2) = ctx->f22.u32l;
    skip_4:
L_800AF9CC:
    // 0x800AF9CC: lw          $v0, 0x13C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X13C);
    // 0x800AF9D0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF9D4: lwc1        $f2, 0x556C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X556C);
    // 0x800AF9D8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x800AF9DC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AF9E0: lwc1        $f4, -0x4394($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, -0X4394);
    // 0x800AF9E4: sub.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x800AF9E8: lwc1        $f0, 0x0($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800AF9EC: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800AF9F0: lwc1        $f0, 0x78($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800AF9F4: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800AF9F8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800AF9FC: swc1        $f2, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f2.u32l;
L_800AFA00:
    // 0x800AFA00: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AFA04: lwc1        $f16, -0x4228($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, -0X4228);
    // 0x800AFA08: abs.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = fabsf(ctx->f16.fl);
    // 0x800AFA0C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AFA10: lwc1        $f0, 0x5570($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5570);
    // 0x800AFA14: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800AFA18: nop

    // 0x800AFA1C: bc1f        L_800AFA2C
    if (!c1cs) {
        // 0x800AFA20: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800AFA2C;
    }
    // 0x800AFA20: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AFA24: j           L_800AFAA8
    // 0x800AFA28: sw          $zero, -0x4390($v0)
    MEM_W(-0X4390, ctx->r2) = 0;
        goto L_800AFAA8;
    // 0x800AFA28: sw          $zero, -0x4390($v0)
    MEM_W(-0X4390, ctx->r2) = 0;
L_800AFA2C:
    // 0x800AFA2C: lwc1        $f0, -0x4390($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X4390);
    // 0x800AFA30: c.eq.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl == ctx->f22.fl;
    // 0x800AFA34: nop

    // 0x800AFA38: bc1t        L_800AFA74
    if (c1cs) {
        // 0x800AFA3C: nop
    
            goto L_800AFA74;
    }
    // 0x800AFA3C: nop

    // 0x800AFA40: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x800AFA44: nop

    // 0x800AFA48: bc1fl       L_800AFA60
    if (!c1cs) {
        // 0x800AFA4C: sub.s       $f0, $f0, $f26
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f26.fl;
            goto L_800AFA60;
    }
    goto skip_5;
    // 0x800AFA4C: sub.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f26.fl;
    skip_5:
    // 0x800AFA50: add.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f26.fl;
    // 0x800AFA54: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x800AFA58: j           L_800AFA68
    // 0x800AFA5C: swc1        $f0, -0x4390($v0)
    MEM_W(-0X4390, ctx->r2) = ctx->f0.u32l;
        goto L_800AFA68;
    // 0x800AFA5C: swc1        $f0, -0x4390($v0)
    MEM_W(-0X4390, ctx->r2) = ctx->f0.u32l;
L_800AFA60:
    // 0x800AFA60: swc1        $f0, -0x4390($v0)
    MEM_W(-0X4390, ctx->r2) = ctx->f0.u32l;
    // 0x800AFA64: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
L_800AFA68:
    // 0x800AFA68: nop

    // 0x800AFA6C: bc1tl       L_800AFA74
    if (c1cs) {
        // 0x800AFA70: swc1        $f22, -0x4390($v0)
        MEM_W(-0X4390, ctx->r2) = ctx->f22.u32l;
            goto L_800AFA74;
    }
    goto skip_6;
    // 0x800AFA70: swc1        $f22, -0x4390($v0)
    MEM_W(-0X4390, ctx->r2) = ctx->f22.u32l;
    skip_6:
L_800AFA74:
    // 0x800AFA74: lw          $v0, 0x140($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X140);
    // 0x800AFA78: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AFA7C: lwc1        $f2, 0x5574($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5574);
    // 0x800AFA80: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x800AFA84: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AFA88: lwc1        $f4, -0x4390($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, -0X4390);
    // 0x800AFA8C: sub.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x800AFA90: lwc1        $f0, 0x0($s7)
    ctx->f0.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800AFA94: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800AFA98: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800AFA9C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800AFAA0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800AFAA4: swc1        $f2, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->f2.u32l;
L_800AFAA8:
    // 0x800AFAA8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AFAAC: lwc1        $f0, 0x5578($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5578);
    // 0x800AFAB0: c.eq.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl == ctx->f0.fl;
    // 0x800AFAB4: nop

    // 0x800AFAB8: bc1f        L_800AFC44
    if (!c1cs) {
        // 0x800AFABC: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800AFC44;
    }
    // 0x800AFABC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800AFAC0: j           L_800AFC28
    // 0x800AFAC4: sub.s       $f0, $f24, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f28.fl;
        goto L_800AFC28;
    // 0x800AFAC4: sub.s       $f0, $f24, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f28.fl;
L_800AFAC8:
    // 0x800AFAC8: sub.s       $f0, $f24, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f4.fl;
    // 0x800AFACC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800AFAD0: nop

    // 0x800AFAD4: bc1f        L_800AFC44
    if (!c1cs) {
        // 0x800AFAD8: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800AFC44;
    }
    // 0x800AFAD8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800AFADC: c.lt.s      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.fl < ctx->f24.fl;
    // 0x800AFAE0: nop

    // 0x800AFAE4: bc1f        L_800AFB04
    if (!c1cs) {
        // 0x800AFAE8: nop
    
            goto L_800AFB04;
    }
    // 0x800AFAE8: nop

    // 0x800AFAEC: sub.s       $f0, $f24, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f2.fl;
    // 0x800AFAF0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AFAF4: lwc1        $f2, 0x557C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X557C);
    // 0x800AFAF8: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800AFAFC: j           L_800AFB08
    // 0x800AFB00: sub.s       $f22, $f2, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f2.fl - ctx->f0.fl;
        goto L_800AFB08;
    // 0x800AFB00: sub.s       $f22, $f2, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f2.fl - ctx->f0.fl;
L_800AFB04:
    // 0x800AFB04: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
L_800AFB08:
    // 0x800AFB08: lwc1        $f0, 0x14($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X14);
    // 0x800AFB0C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800AFB10: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800AFB14: nop

    // 0x800AFB18: bc1f        L_800AFC0C
    if (!c1cs) {
        // 0x800AFB1C: nop
    
            goto L_800AFC0C;
    }
    // 0x800AFB1C: nop

    // 0x800AFB20: lwc1        $f0, 0xE8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XE8);
    // 0x800AFB24: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800AFB28: nop

    // 0x800AFB2C: bc1f        L_800AFC0C
    if (!c1cs) {
        // 0x800AFB30: addiu       $s2, $s4, 0x10
        ctx->r18 = ADD32(ctx->r20, 0X10);
            goto L_800AFC0C;
    }
    // 0x800AFB30: addiu       $s2, $s4, 0x10
    ctx->r18 = ADD32(ctx->r20, 0X10);
    // 0x800AFB34: lw          $t0, 0x10($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X10);
    // 0x800AFB38: lw          $t1, 0x14($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X14);
    // 0x800AFB3C: lw          $t2, 0x18($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X18);
    // 0x800AFB40: sw          $t0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r8;
    // 0x800AFB44: sw          $t1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r9;
    // 0x800AFB48: sw          $t2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r10;
    // 0x800AFB4C: lwc1        $f0, 0x14($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X14);
    // 0x800AFB50: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800AFB54: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800AFB58: jal         0x8001CF58
    // 0x800AFB5C: swc1        $f0, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->f0.u32l;
    normalize_vector(rdram, ctx);
        goto after_29;
    // 0x800AFB5C: swc1        $f0, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->f0.u32l;
    after_29:
    // 0x800AFB60: addiu       $s3, $sp, 0xA8
    ctx->r19 = ADD32(ctx->r29, 0XA8);
    // 0x800AFB64: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800AFB68: addiu       $s1, $sp, 0x88
    ctx->r17 = ADD32(ctx->r29, 0X88);
    // 0x800AFB6C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800AFB70: jal         0x80019548
    // 0x800AFB74: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_80019548(rdram, ctx);
        goto after_30;
    // 0x800AFB74: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_30:
    // 0x800AFB78: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800AFB7C: jal         0x8001CFE8
    // 0x800AFB80: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_8001CFE8(rdram, ctx);
        goto after_31;
    // 0x800AFB80: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_31:
    // 0x800AFB84: jal         0x8001C5CC
    // 0x800AFB88: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8001C5CC(rdram, ctx);
        goto after_32;
    // 0x800AFB88: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_32:
    // 0x800AFB8C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AFB90: lwc1        $f2, 0x5580($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5580);
    // 0x800AFB94: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800AFB98: addiu       $s0, $sp, 0xB8
    ctx->r16 = ADD32(ctx->r29, 0XB8);
    // 0x800AFB9C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800AFBA0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800AFBA4: jal         0x8001D144
    // 0x800AFBA8: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8001D144(rdram, ctx);
        goto after_33;
    // 0x800AFBA8: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_33:
    // 0x800AFBAC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800AFBB0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800AFBB4: jal         0x8001D3C4
    // 0x800AFBB8: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_8001D3C4(rdram, ctx);
        goto after_34;
    // 0x800AFBB8: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_34:
    // 0x800AFBBC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800AFBC0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800AFBC4: lw          $t0, 0x1C($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X1C);
    // 0x800AFBC8: lw          $t1, 0x20($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X20);
    // 0x800AFBCC: lw          $t2, 0x24($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X24);
    // 0x800AFBD0: sw          $t0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r8;
    // 0x800AFBD4: sw          $t1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r9;
    // 0x800AFBD8: sw          $t2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r10;
    // 0x800AFBDC: jal         0x8001D3C4
    // 0x800AFBE0: addiu       $a2, $s4, 0x1C
    ctx->r6 = ADD32(ctx->r20, 0X1C);
    func_8001D3C4(rdram, ctx);
        goto after_35;
    // 0x800AFBE0: addiu       $a2, $s4, 0x1C
    ctx->r6 = ADD32(ctx->r20, 0X1C);
    after_35:
    // 0x800AFBE4: lwc1        $f0, 0x0($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800AFBE8: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800AFBEC: swc1        $f0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f0.u32l;
    // 0x800AFBF0: lwc1        $f0, 0xDC($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XDC);
    // 0x800AFBF4: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800AFBF8: nop

    // 0x800AFBFC: bc1f        L_800AFC0C
    if (!c1cs) {
        // 0x800AFC00: nop
    
            goto L_800AFC0C;
    }
    // 0x800AFC00: nop

    // 0x800AFC04: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800AFC08: swc1        $f0, 0xDC($s4)
    MEM_W(0XDC, ctx->r20) = ctx->f0.u32l;
L_800AFC0C:
    // 0x800AFC0C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AFC10: c.eq.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl == ctx->f0.fl;
    // 0x800AFC14: nop

    // 0x800AFC18: bc1f        L_800AFC44
    if (!c1cs) {
        // 0x800AFC1C: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800AFC44;
    }
    // 0x800AFC1C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800AFC20: lwc1        $f0, 0x100($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X100);
    // 0x800AFC24: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
L_800AFC28:
    // 0x800AFC28: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AFC2C: lwc1        $f2, 0x5584($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5584);
    // 0x800AFC30: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800AFC34: lwc1        $f2, 0x8($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X8);
    // 0x800AFC38: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
L_800AFC3C:
    // 0x800AFC3C: swc1        $f2, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->f2.u32l;
    // 0x800AFC40: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
L_800AFC44:
    // 0x800AFC44: addiu       $a0, $a0, 0x7DB8
    ctx->r4 = ADD32(ctx->r4, 0X7DB8);
    // 0x800AFC48: lw          $v1, 0xB8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0XB8);
    // 0x800AFC4C: lwc1        $f0, 0x4($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X4);
    // 0x800AFC50: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800AFC54: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800AFC58: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800AFC5C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800AFC60: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800AFC64: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800AFC68: swc1        $f0, 0x278($v0)
    MEM_W(0X278, ctx->r2) = ctx->f0.u32l;
    // 0x800AFC6C: lw          $v1, 0xB8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0XB8);
    // 0x800AFC70: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x800AFC74: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800AFC78: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800AFC7C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800AFC80: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800AFC84: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800AFC88: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800AFC8C: swc1        $f0, 0x27C($v0)
    MEM_W(0X27C, ctx->r2) = ctx->f0.u32l;
    // 0x800AFC90: lw          $v1, 0xB8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0XB8);
    // 0x800AFC94: lwc1        $f0, 0xC($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XC);
    // 0x800AFC98: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800AFC9C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800AFCA0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800AFCA4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800AFCA8: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800AFCAC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800AFCB0: swc1        $f0, 0x280($v0)
    MEM_W(0X280, ctx->r2) = ctx->f0.u32l;
    // 0x800AFCB4: lw          $ra, 0xF8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XF8);
    // 0x800AFCB8: lw          $s7, 0xF4($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XF4);
    // 0x800AFCBC: lw          $s6, 0xF0($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XF0);
    // 0x800AFCC0: lw          $s5, 0xEC($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XEC);
    // 0x800AFCC4: lw          $s4, 0xE8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XE8);
    // 0x800AFCC8: lw          $s3, 0xE4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XE4);
    // 0x800AFCCC: lw          $s2, 0xE0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XE0);
    // 0x800AFCD0: lw          $s1, 0xDC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XDC);
    // 0x800AFCD4: lw          $s0, 0xD8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XD8);
    // 0x800AFCD8: ldc1        $f28, 0x120($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X120);
    // 0x800AFCDC: ldc1        $f26, 0x118($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X118);
    // 0x800AFCE0: ldc1        $f24, 0x110($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X110);
    // 0x800AFCE4: ldc1        $f22, 0x108($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X108);
    // 0x800AFCE8: ldc1        $f20, 0x100($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X100);
    // 0x800AFCEC: jr          $ra
    // 0x800AFCF0: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
    return;
    // 0x800AFCF0: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
;}
RECOMP_FUNC void func_800AF08C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF08C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AF090: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800AF094: addiu       $v0, $v0, -0x6AA0
    ctx->r2 = ADD32(ctx->r2, -0X6AA0);
    // 0x800AF098: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x800AF09C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AF0A0: addu        $s0, $a0, $v0
    ctx->r16 = ADD32(ctx->r4, ctx->r2);
    // 0x800AF0A4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AF0A8: ori         $s1, $zero, 0xFFFF
    ctx->r17 = 0 | 0XFFFF;
    // 0x800AF0AC: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
L_800AF0B0:
    // 0x800AF0B0: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x800AF0B4: jal         0x8003FC28
    // 0x800AF0B8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8003FC28(rdram, ctx);
        goto after_0;
    // 0x800AF0B8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x800AF0BC: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x800AF0C0: beq         $a0, $s1, L_800AF0D8
    if (ctx->r4 == ctx->r17) {
        // 0x800AF0C4: nop
    
            goto L_800AF0D8;
    }
    // 0x800AF0C4: nop

    // 0x800AF0C8: jal         0x8003ED74
    // 0x800AF0CC: nop

    func_8003ED74(rdram, ctx);
        goto after_1;
    // 0x800AF0CC: nop

    after_1:
    // 0x800AF0D0: j           L_800AF0B0
    // 0x800AF0D4: nop

        goto L_800AF0B0;
    // 0x800AF0D4: nop

L_800AF0D8:
    // 0x800AF0D8: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800AF0DC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF0E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AF0E4: jr          $ra
    // 0x800AF0E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800AF0E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800AF0EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF0EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AF0F0: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800AF0F4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800AF0F8: sw          $zero, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = 0;
    // 0x800AF0FC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800AF100: bne         $a0, $v0, L_800AF118
    if (ctx->r4 != ctx->r2) {
        // 0x800AF104: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_800AF118;
    }
    // 0x800AF104: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800AF108: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x800AF10C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AF110: beql        $v1, $v0, L_800AF130
    if (ctx->r3 == ctx->r2) {
        // 0x800AF114: lui         $a0, 0x800A
        ctx->r4 = S32(0X800A << 16);
            goto L_800AF130;
    }
    goto skip_0;
    // 0x800AF114: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    skip_0:
L_800AF118:
    // 0x800AF118: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800AF11C: bne         $a0, $v0, L_800AF158
    if (ctx->r4 != ctx->r2) {
        // 0x800AF120: andi        $v0, $a1, 0xFF
        ctx->r2 = ctx->r5 & 0XFF;
            goto L_800AF158;
    }
    // 0x800AF120: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x800AF124: bne         $v0, $zero, L_800AF158
    if (ctx->r2 != 0) {
        // 0x800AF128: nop
    
            goto L_800AF158;
    }
    // 0x800AF128: nop

    // 0x800AF12C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
L_800AF130:
    // 0x800AF130: addiu       $a0, $a0, 0x5578
    ctx->r4 = ADD32(ctx->r4, 0X5578);
    // 0x800AF134: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AF138: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AF13C: jal         0x8005645C
    // 0x800AF140: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    load_hmt_and_hob(rdram, ctx);
        goto after_0;
    // 0x800AF140: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    after_0:
    // 0x800AF144: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800AF148: jal         0x80056EB0
    // 0x800AF14C: addiu       $a0, $a0, 0x5594
    ctx->r4 = ADD32(ctx->r4, 0X5594);
    func_80056EB0(rdram, ctx);
        goto after_1;
    // 0x800AF14C: addiu       $a0, $a0, 0x5594
    ctx->r4 = ADD32(ctx->r4, 0X5594);
    after_1:
    // 0x800AF150: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x800AF154: sw          $v0, 0xB18($v1)
    MEM_W(0XB18, ctx->r3) = ctx->r2;
L_800AF158:
    // 0x800AF158: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800AF15C: jr          $ra
    // 0x800AF160: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800AF160: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800AF164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF164: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AF168: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800AF16C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800AF170: lw          $s0, 0xB18($v0)
    ctx->r16 = MEM_W(ctx->r2, 0XB18);
    // 0x800AF174: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800AF178: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800AF17C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800AF180: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x800AF184: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800AF188: beq         $s0, $zero, L_800AF244
    if (ctx->r16 == 0) {
        // 0x800AF18C: sw          $s1, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r17;
            goto L_800AF244;
    }
    // 0x800AF18C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800AF190: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF194: lwc1        $f0, 0x5D44($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5D44);
    // 0x800AF198: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // 0x800AF19C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800AF1A0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800AF1A4: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800AF1A8: jal         0x8001CB64
    // 0x800AF1AC: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8001CB64(rdram, ctx);
        goto after_0;
    // 0x800AF1AC: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_0:
    // 0x800AF1B0: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x800AF1B4: lwc1        $f0, 0xB2C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XB2C);
    // 0x800AF1B8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF1BC: lwc1        $f12, 0x5D48($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5D48);
    // 0x800AF1C0: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800AF1C4: jal         0x80033960
    // 0x800AF1C8: nop

    sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x800AF1C8: nop

    after_1:
    // 0x800AF1CC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF1D0: lwc1        $f2, 0x5D4C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5D4C);
    // 0x800AF1D4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800AF1D8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800AF1DC: jal         0x8001CDFC
    // 0x800AF1E0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001CDFC(rdram, ctx);
        goto after_2;
    // 0x800AF1E0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x800AF1E4: lwc1        $f12, 0xB2C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XB2C);
    // 0x800AF1E8: jal         0x80033960
    // 0x800AF1EC: add.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f12.fl;
    sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x800AF1EC: add.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f12.fl;
    after_3:
    // 0x800AF1F0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF1F4: lwc1        $f2, 0x5D50($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5D50);
    // 0x800AF1F8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800AF1FC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800AF200: jal         0x8001CB9C
    // 0x800AF204: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001CB9C(rdram, ctx);
        goto after_4;
    // 0x800AF204: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x800AF208: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800AF20C: lui         $a2, 0x3DB8
    ctx->r6 = S32(0X3DB8 << 16);
    // 0x800AF210: ori         $a2, $a2, 0x51EB
    ctx->r6 = ctx->r6 | 0X51EB;
    // 0x800AF214: lui         $a3, 0x3EFA
    ctx->r7 = S32(0X3EFA << 16);
    // 0x800AF218: ori         $a3, $a3, 0xE148
    ctx->r7 = ctx->r7 | 0XE148;
    // 0x800AF21C: jal         0x8001CA90
    // 0x800AF220: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8001CA90(rdram, ctx);
        goto after_5;
    // 0x800AF220: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_5:
    // 0x800AF224: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800AF228: jal         0x8001DAEC
    // 0x800AF22C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8001DAEC(rdram, ctx);
        goto after_6;
    // 0x800AF22C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_6:
    // 0x800AF230: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x800AF234: lw          $a2, 0x4($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X4);
    // 0x800AF238: lw          $a3, 0x8($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X8);
    // 0x800AF23C: jal         0x8001CA90
    // 0x800AF240: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001CA90(rdram, ctx);
        goto after_7;
    // 0x800AF240: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
L_800AF244:
    // 0x800AF244: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800AF248: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF24C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800AF250: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800AF254: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800AF258: jr          $ra
    // 0x800AF25C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800AF25C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800AF260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF260: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AF264: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800AF268: jal         0x800678E4
    // 0x800AF26C: nop

    func_800678E4(rdram, ctx);
        goto after_0;
    // 0x800AF26C: nop

    after_0:
    // 0x800AF270: jal         0x80045708
    // 0x800AF274: nop

    func_80045708(rdram, ctx);
        goto after_1;
    // 0x800AF274: nop

    after_1:
    // 0x800AF278: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800AF27C: jr          $ra
    // 0x800AF280: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800AF280: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800AF284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF284: beq         $a2, $zero, L_800AF2C0
    if (ctx->r6 == 0) {
        // 0x800AF288: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_800AF2C0;
    }
    // 0x800AF288: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800AF28C: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
L_800AF290:
    // 0x800AF290: addu        $v1, $a0, $v0
    ctx->r3 = ADD32(ctx->r4, ctx->r2);
    // 0x800AF294: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800AF298: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x800AF29C: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800AF2A0: beq         $v1, $v0, L_800AF2B0
    if (ctx->r3 == ctx->r2) {
        // 0x800AF2A4: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800AF2B0;
    }
    // 0x800AF2A4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800AF2A8: jr          $ra
    // 0x800AF2AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800AF2AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800AF2B0:
    // 0x800AF2B0: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x800AF2B4: sltu        $v0, $v0, $a2
    ctx->r2 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x800AF2B8: bne         $v0, $zero, L_800AF290
    if (ctx->r2 != 0) {
        // 0x800AF2BC: andi        $v0, $a3, 0xFFFF
        ctx->r2 = ctx->r7 & 0XFFFF;
            goto L_800AF290;
    }
    // 0x800AF2BC: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
L_800AF2C0:
    // 0x800AF2C0: jr          $ra
    // 0x800AF2C4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800AF2C4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_800AF2C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF2C8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800AF2CC: lw          $t0, 0x30($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X30);
    // 0x800AF2D0: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x800AF2D4: beq         $v0, $zero, L_800AF358
    if (ctx->r2 == 0) {
        // 0x800AF2D8: nop
    
            goto L_800AF358;
    }
    // 0x800AF2D8: nop

L_800AF2DC:
    // 0x800AF2DC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800AF2E0: addu        $v0, $t0, $a0
    ctx->r2 = ADD32(ctx->r8, ctx->r4);
L_800AF2E4:
    // 0x800AF2E4: addu        $v1, $a1, $a0
    ctx->r3 = ADD32(ctx->r5, ctx->r4);
    // 0x800AF2E8: lbu         $a3, 0x0($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X0);
    // 0x800AF2EC: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800AF2F0: bne         $a3, $v0, L_800AF338
    if (ctx->r7 != ctx->r2) {
        // 0x800AF2F4: nop
    
            goto L_800AF338;
    }
    // 0x800AF2F4: nop

    // 0x800AF2F8: beq         $a3, $zero, L_800AF314
    if (ctx->r7 == 0) {
        // 0x800AF2FC: addu        $v0, $t0, $a0
        ctx->r2 = ADD32(ctx->r8, ctx->r4);
            goto L_800AF314;
    }
    // 0x800AF2FC: addu        $v0, $t0, $a0
    ctx->r2 = ADD32(ctx->r8, ctx->r4);
    // 0x800AF300: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800AF304: slti        $v0, $a0, 0x6
    ctx->r2 = SIGNED(ctx->r4) < 0X6 ? 1 : 0;
    // 0x800AF308: bne         $v0, $zero, L_800AF2E4
    if (ctx->r2 != 0) {
        // 0x800AF30C: addu        $v0, $t0, $a0
        ctx->r2 = ADD32(ctx->r8, ctx->r4);
            goto L_800AF2E4;
    }
    // 0x800AF30C: addu        $v0, $t0, $a0
    ctx->r2 = ADD32(ctx->r8, ctx->r4);
    // 0x800AF310: addu        $v1, $a1, $a0
    ctx->r3 = ADD32(ctx->r5, ctx->r4);
L_800AF314:
    // 0x800AF314: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x800AF318: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800AF31C: bne         $a0, $v0, L_800AF338
    if (ctx->r4 != ctx->r2) {
        // 0x800AF320: nop
    
            goto L_800AF338;
    }
    // 0x800AF320: nop

    // 0x800AF324: bne         $a0, $zero, L_800AF338
    if (ctx->r4 != 0) {
        // 0x800AF328: nop
    
            goto L_800AF338;
    }
    // 0x800AF328: nop

    // 0x800AF32C: lbu         $v0, 0x7($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X7);
    // 0x800AF330: jr          $ra
    // 0x800AF334: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    return;
    // 0x800AF334: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
L_800AF338:
    // 0x800AF338: lbu         $v0, 0x7($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X7);
    // 0x800AF33C: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x800AF340: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800AF344: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800AF348: addu        $v1, $t0, $v1
    ctx->r3 = ADD32(ctx->r8, ctx->r3);
    // 0x800AF34C: lbu         $v0, 0x8($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X8);
    // 0x800AF350: bne         $v0, $zero, L_800AF2DC
    if (ctx->r2 != 0) {
        // 0x800AF354: addiu       $t0, $v1, 0x8
        ctx->r8 = ADD32(ctx->r3, 0X8);
            goto L_800AF2DC;
    }
    // 0x800AF354: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
L_800AF358:
    // 0x800AF358: jr          $ra
    // 0x800AF35C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800AF35C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_800AF360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF360: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800AF364: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x800AF368: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x800AF36C: jal         0x8000BC00
    // 0x800AF370: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8000BC00(rdram, ctx);
        goto after_0;
    // 0x800AF370: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x800AF374: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800AF378: lw          $v1, -0x7764($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X7764);
    // 0x800AF37C: lwc1        $f20, 0x30($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800AF380: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800AF384: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800AF388: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800AF38C: jal         0x8001E20C
    // 0x800AF390: sw          $v1, -0x7764($v0)
    MEM_W(-0X7764, ctx->r2) = ctx->r3;
    func_8001E20C(rdram, ctx);
        goto after_1;
    // 0x800AF390: sw          $v1, -0x7764($v0)
    MEM_W(-0X7764, ctx->r2) = ctx->r3;
    after_1:
    // 0x800AF394: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800AF398: mov.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
    // 0x800AF39C: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x800AF3A0: nop

    // 0x800AF3A4: bc1f        L_800AF3D8
    if (!c1cs) {
        // 0x800AF3A8: nop
    
            goto L_800AF3D8;
    }
    // 0x800AF3A8: nop

    // 0x800AF3AC: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800AF3B0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF3B4: lwc1        $f2, 0x5D54($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5D54);
    // 0x800AF3B8: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AF3BC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800AF3C0: nop

    // 0x800AF3C4: bc1fl       L_800AF3D4
    if (!c1cs) {
        // 0x800AF3C8: add.s       $f0, $f20, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f6.fl;
            goto L_800AF3D4;
    }
    goto skip_0;
    // 0x800AF3C8: add.s       $f0, $f20, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f6.fl;
    skip_0:
    // 0x800AF3CC: j           L_800AF3D8
    // 0x800AF3D0: sub.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f4.fl;
        goto L_800AF3D8;
    // 0x800AF3D0: sub.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f4.fl;
L_800AF3D4:
    // 0x800AF3D4: sub.s       $f20, $f0, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f4.fl;
L_800AF3D8:
    // 0x800AF3D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AF3DC: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x800AF3E0: nop

    // 0x800AF3E4: bc1f        L_800AF3F8
    if (!c1cs) {
        // 0x800AF3E8: mov.s       $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
            goto L_800AF3F8;
    }
    // 0x800AF3E8: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x800AF3EC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF3F0: lwc1        $f20, 0x5D58($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5D58);
    // 0x800AF3F4: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_800AF3F8:
    // 0x800AF3F8: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x800AF3FC: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x800AF400: jr          $ra
    // 0x800AF404: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800AF404: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800AF3C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF3C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AF3C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AF3C8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800AF3CC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800AF3D0: jal         0x800C6660
    // 0x800AF3D4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_800C6660(rdram, ctx);
        goto after_0;
    // 0x800AF3D4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x800AF3D8: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800AF3DC: jal         0x80002FF4
    // 0x800AF3E0: swc1        $f0, -0x24F0($s0)
    MEM_W(-0X24F0, ctx->r16) = ctx->f0.u32l;
    func_80002FF4(rdram, ctx);
        goto after_1;
    // 0x800AF3E0: swc1        $f0, -0x24F0($s0)
    MEM_W(-0X24F0, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x800AF3E4: jal         0x80079CE0
    // 0x800AF3E8: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    setNewAndPreviousButtonsPressed(rdram, ctx);
        goto after_2;
    // 0x800AF3E8: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    after_2:
    // 0x800AF3EC: lwc1        $f2, -0x24F0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, -0X24F0);
    // 0x800AF3F0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF3F4: lwc1        $f0, 0x58FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X58FC);
    // 0x800AF3F8: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800AF3FC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF400: lwc1        $f0, -0x24EC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X24EC);
    // 0x800AF404: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800AF408: jal         0x8000A86C
    // 0x800AF40C: swc1        $f0, -0x24EC($v0)
    MEM_W(-0X24EC, ctx->r2) = ctx->f0.u32l;
    func_8000A86C(rdram, ctx);
        goto after_3;
    // 0x800AF40C: swc1        $f0, -0x24EC($v0)
    MEM_W(-0X24EC, ctx->r2) = ctx->f0.u32l;
    after_3:
    // 0x800AF410: lwc1        $f12, -0x24F0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, -0X24F0);
    // 0x800AF414: jal         0x800B1B58
    // 0x800AF418: nop

    func_800B1B58(rdram, ctx);
        goto after_4;
    // 0x800AF418: nop

    after_4:
    // 0x800AF41C: jal         0x800AF6AC
    // 0x800AF420: nop

    func_800AF6AC(rdram, ctx);
        goto after_5;
    // 0x800AF420: nop

    after_5:
    // 0x800AF424: jal         0x800B07F4
    // 0x800AF428: nop

    func_800B07F4(rdram, ctx);
        goto after_6;
    // 0x800AF428: nop

    after_6:
    // 0x800AF42C: lwc1        $f12, -0x24F0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, -0X24F0);
    // 0x800AF430: jal         0x800B2520
    // 0x800AF434: nop

    func_800B2520(rdram, ctx);
        goto after_7;
    // 0x800AF434: nop

    after_7:
    // 0x800AF438: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF43C: lw          $a0, -0x205C($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X205C);
    // 0x800AF440: lw          $a1, -0x2504($s1)
    ctx->r5 = MEM_W(ctx->r17, -0X2504);
    // 0x800AF444: lw          $a2, -0x24F0($s0)
    ctx->r6 = MEM_W(ctx->r16, -0X24F0);
    // 0x800AF448: jal         0x80062B04
    // 0x800AF44C: nop

    func_80062B04(rdram, ctx);
        goto after_8;
    // 0x800AF44C: nop

    after_8:
    // 0x800AF450: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF454: lw          $a0, -0x2058($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X2058);
    // 0x800AF458: lw          $a1, -0x2504($s1)
    ctx->r5 = MEM_W(ctx->r17, -0X2504);
    // 0x800AF45C: lw          $a2, -0x24F0($s0)
    ctx->r6 = MEM_W(ctx->r16, -0X24F0);
    // 0x800AF460: jal         0x80062B04
    // 0x800AF464: nop

    func_80062B04(rdram, ctx);
        goto after_9;
    // 0x800AF464: nop

    after_9:
    // 0x800AF468: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF46C: lwc1        $f2, -0x1958($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X1958);
    // 0x800AF470: lwc1        $f0, -0x24F0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, -0X24F0);
    // 0x800AF474: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800AF478: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AF47C: lwc1        $f0, -0x195C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, -0X195C);
    // 0x800AF480: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800AF484: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF488: lwc1        $f2, 0x5900($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5900);
    // 0x800AF48C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800AF490: nop

    // 0x800AF494: bc1f        L_800AF4A0
    if (!c1cs) {
        // 0x800AF498: swc1        $f0, -0x195C($v1)
        MEM_W(-0X195C, ctx->r3) = ctx->f0.u32l;
            goto L_800AF4A0;
    }
    // 0x800AF498: swc1        $f0, -0x195C($v1)
    MEM_W(-0X195C, ctx->r3) = ctx->f0.u32l;
    // 0x800AF49C: swc1        $f2, -0x195C($v1)
    MEM_W(-0X195C, ctx->r3) = ctx->f2.u32l;
L_800AF4A0:
    // 0x800AF4A0: lwc1        $f0, -0x195C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, -0X195C);
    // 0x800AF4A4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800AF4A8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800AF4AC: nop

    // 0x800AF4B0: bc1tl       L_800AF4B8
    if (c1cs) {
        // 0x800AF4B4: swc1        $f2, -0x195C($v1)
        MEM_W(-0X195C, ctx->r3) = ctx->f2.u32l;
            goto L_800AF4B8;
    }
    goto skip_0;
    // 0x800AF4B4: swc1        $f2, -0x195C($v1)
    MEM_W(-0X195C, ctx->r3) = ctx->f2.u32l;
    skip_0:
L_800AF4B8:
    // 0x800AF4B8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF4BC: lbu         $a0, -0x253F($v0)
    ctx->r4 = MEM_BU(ctx->r2, -0X253F);
    // 0x800AF4C0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF4C4: lbu         $a1, -0x253D($v0)
    ctx->r5 = MEM_BU(ctx->r2, -0X253D);
    // 0x800AF4C8: lw          $a2, -0x195C($v1)
    ctx->r6 = MEM_W(ctx->r3, -0X195C);
    // 0x800AF4CC: jal         0x800B1EF4
    // 0x800AF4D0: nop

    func_800B1EF4(rdram, ctx);
        goto after_10;
    // 0x800AF4D0: nop

    after_10:
    // 0x800AF4D4: lwc1        $f2, -0x2504($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, -0X2504);
    // 0x800AF4D8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF4DC: lwc1        $f0, 0x5904($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5904);
    // 0x800AF4E0: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800AF4E4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF4E8: lwc1        $f2, 0x5908($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5908);
    // 0x800AF4EC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800AF4F0: nop

    // 0x800AF4F4: bc1tl       L_800AF50C
    if (c1cs) {
        // 0x800AF4F8: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800AF50C;
    }
    goto skip_1;
    // 0x800AF4F8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_1:
    // 0x800AF4FC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800AF500: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800AF504: j           L_800AF520
    // 0x800AF508: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_800AF520;
    // 0x800AF508: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_800AF50C:
    // 0x800AF50C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800AF510: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800AF514: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800AF518: or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
    // 0x800AF51C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_800AF520:
    // 0x800AF520: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AF524: jal         0x80061C74
    // 0x800AF528: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    func_80061C74(rdram, ctx);
        goto after_11;
    // 0x800AF528: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_11:
    // 0x800AF52C: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x800AF530: lwc1        $f12, -0x24F0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, -0X24F0);
    // 0x800AF534: jal         0x800B08F4
    // 0x800AF538: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    func_800B08F4(rdram, ctx);
        goto after_12;
    // 0x800AF538: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    after_12:
    // 0x800AF53C: jal         0x800B0148
    // 0x800AF540: sw          $zero, -0x2380($s0)
    MEM_W(-0X2380, ctx->r16) = 0;
    func_800B0148(rdram, ctx);
        goto after_13;
    // 0x800AF540: sw          $zero, -0x2380($s0)
    MEM_W(-0X2380, ctx->r16) = 0;
    after_13:
    // 0x800AF544: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF548: addiu       $a1, $v0, -0x2310
    ctx->r5 = ADD32(ctx->r2, -0X2310);
    // 0x800AF54C: lw          $v1, 0x64($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X64);
    // 0x800AF550: lw          $v0, -0x2380($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X2380);
    // 0x800AF554: beq         $v0, $zero, L_800AF56C
    if (ctx->r2 == 0) {
        // 0x800AF558: sw          $v0, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->r2;
            goto L_800AF56C;
    }
    // 0x800AF558: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x800AF55C: lw          $v0, 0x64($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X64);
    // 0x800AF560: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800AF564: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800AF568: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800AF56C:
    // 0x800AF56C: lw          $v0, 0x64($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X64);
    // 0x800AF570: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800AF574: lw          $v1, 0x64($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X64);
    // 0x800AF578: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x800AF57C: sw          $v1, -0x2380($s0)
    MEM_W(-0X2380, ctx->r16) = ctx->r3;
    // 0x800AF580: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x800AF584: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x800AF588: beq         $v1, $zero, L_800AF5A0
    if (ctx->r3 == 0) {
        // 0x800AF58C: sw          $v1, 0xC($v0)
        MEM_W(0XC, ctx->r2) = ctx->r3;
            goto L_800AF5A0;
    }
    // 0x800AF58C: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x800AF590: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x800AF594: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800AF598: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800AF59C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800AF5A0:
    // 0x800AF5A0: lw          $v0, 0x24($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X24);
    // 0x800AF5A4: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800AF5A8: lw          $v1, 0x24($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X24);
    // 0x800AF5AC: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x800AF5B0: sw          $v1, -0x2380($s0)
    MEM_W(-0X2380, ctx->r16) = ctx->r3;
    // 0x800AF5B4: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x800AF5B8: lw          $v0, 0x44($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X44);
    // 0x800AF5BC: beq         $v1, $zero, L_800AF5D4
    if (ctx->r3 == 0) {
        // 0x800AF5C0: sw          $v1, 0xC($v0)
        MEM_W(0XC, ctx->r2) = ctx->r3;
            goto L_800AF5D4;
    }
    // 0x800AF5C0: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x800AF5C4: lw          $v0, 0x44($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X44);
    // 0x800AF5C8: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800AF5CC: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800AF5D0: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800AF5D4:
    // 0x800AF5D4: lw          $v0, 0x44($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X44);
    // 0x800AF5D8: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800AF5DC: lw          $v1, 0x44($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X44);
    // 0x800AF5E0: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x800AF5E4: sw          $v1, -0x2380($s0)
    MEM_W(-0X2380, ctx->r16) = ctx->r3;
    // 0x800AF5E8: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x800AF5EC: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x800AF5F0: beq         $v1, $zero, L_800AF608
    if (ctx->r3 == 0) {
        // 0x800AF5F4: sw          $v1, 0xC($v0)
        MEM_W(0XC, ctx->r2) = ctx->r3;
            goto L_800AF608;
    }
    // 0x800AF5F4: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x800AF5F8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x800AF5FC: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800AF600: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800AF604: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800AF608:
    // 0x800AF608: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x800AF60C: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800AF610: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x800AF614: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800AF618: jal         0x8000A6CC
    // 0x800AF61C: sw          $v0, -0x2380($s0)
    MEM_W(-0X2380, ctx->r16) = ctx->r2;
    func_8000A6CC(rdram, ctx);
        goto after_14;
    // 0x800AF61C: sw          $v0, -0x2380($s0)
    MEM_W(-0X2380, ctx->r16) = ctx->r2;
    after_14:
    // 0x800AF620: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800AF624: lw          $a0, -0x2324($s1)
    ctx->r4 = MEM_W(ctx->r17, -0X2324);
    // 0x800AF628: jal         0x80064488
    // 0x800AF62C: addiu       $s0, $s0, -0x2380
    ctx->r16 = ADD32(ctx->r16, -0X2380);
    func_80064488(rdram, ctx);
        goto after_15;
    // 0x800AF62C: addiu       $s0, $s0, -0x2380
    ctx->r16 = ADD32(ctx->r16, -0X2380);
    after_15:
    // 0x800AF630: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800AF634: jal         0x80016C44
    // 0x800AF638: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    func_80016C44(rdram, ctx);
        goto after_16;
    // 0x800AF638: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    after_16:
    // 0x800AF63C: jal         0x8000B6F4
    // 0x800AF640: nop

    func_8000B6F4(rdram, ctx);
        goto after_17;
    // 0x800AF640: nop

    after_17:
    // 0x800AF644: jal         0x8000C07C
    // 0x800AF648: nop

    func_8000C07C(rdram, ctx);
        goto after_18;
    // 0x800AF648: nop

    after_18:
    // 0x800AF64C: jal         0x800B0650
    // 0x800AF650: nop

    func_800B0650(rdram, ctx);
        goto after_19;
    // 0x800AF650: nop

    after_19:
    // 0x800AF654: lw          $a0, -0x2324($s1)
    ctx->r4 = MEM_W(ctx->r17, -0X2324);
    // 0x800AF658: lw          $a2, -0x24F0($s2)
    ctx->r6 = MEM_W(ctx->r18, -0X24F0);
    // 0x800AF65C: jal         0x800B4168
    // 0x800AF660: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800B4168(rdram, ctx);
        goto after_20;
    // 0x800AF660: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_20:
    // 0x800AF664: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800AF668: beq         $v0, $zero, L_800AF68C
    if (ctx->r2 == 0) {
        // 0x800AF66C: lui         $v1, 0xFF
        ctx->r3 = S32(0XFF << 16);
            goto L_800AF68C;
    }
    // 0x800AF66C: lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // 0x800AF670: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF674: lw          $v0, -0x2534($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2534);
    // 0x800AF678: ori         $v1, $v1, 0xFFFE
    ctx->r3 = ctx->r3 | 0XFFFE;
    // 0x800AF67C: bnel        $v0, $v1, L_800AF684
    if (ctx->r2 != ctx->r3) {
        // 0x800AF680: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_800AF684;
    }
    goto skip_2;
    // 0x800AF680: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    skip_2:
L_800AF684:
    // 0x800AF684: j           L_800AF694
    // 0x800AF688: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_800AF694;
    // 0x800AF688: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_800AF68C:
    // 0x800AF68C: lui         $v0, 0xFF
    ctx->r2 = S32(0XFF << 16);
    // 0x800AF690: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
L_800AF694:
    // 0x800AF694: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF698: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800AF69C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800AF6A0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800AF6A4: jr          $ra
    // 0x800AF6A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800AF6A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800AF408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF408: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AF40C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800AF410: lui         $s2, 0x800B
    ctx->r18 = S32(0X800B << 16);
    // 0x800AF414: mtc1        $a2, $f2
    ctx->f2.u32l = ctx->r6;
    // 0x800AF418: lw          $v0, 0x934($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X934);
    // 0x800AF41C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800AF420: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800AF424: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800AF428: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800AF42C: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800AF430: bne         $v0, $zero, L_800AF508
    if (ctx->r2 != 0) {
        // 0x800AF434: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_800AF508;
    }
    // 0x800AF434: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800AF438: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF43C: lwc1        $f0, 0x5D5C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5D5C);
    // 0x800AF440: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x800AF444: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800AF448: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x800AF44C: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800AF450: sb          $zero, 0x938($v0)
    MEM_B(0X938, ctx->r2) = 0;
    // 0x800AF454: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800AF458: jal         0x800AE518
    // 0x800AF45C: swc1        $f0, 0x1EE8($v0)
    MEM_W(0X1EE8, ctx->r2) = ctx->f0.u32l;
    func_800AE518(rdram, ctx);
        goto after_0;
    // 0x800AF45C: swc1        $f0, 0x1EE8($v0)
    MEM_W(0X1EE8, ctx->r2) = ctx->f0.u32l;
    after_0:
    // 0x800AF460: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF464: lwc1        $f2, 0x5D60($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5D60);
    // 0x800AF468: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800AF46C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800AF470: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800AF474: lw          $s0, 0xC($v0)
    ctx->r16 = MEM_W(ctx->r2, 0XC);
    // 0x800AF478: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF47C: lwc1        $f2, 0x5D64($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5D64);
    // 0x800AF480: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x800AF484: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800AF488: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800AF48C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800AF490: lui         $v1, 0x240
    ctx->r3 = S32(0X240 << 16);
    // 0x800AF494: ori         $v1, $v1, 0x3
    ctx->r3 = ctx->r3 | 0X3;
    // 0x800AF498: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF49C: lwc1        $f2, 0x5D68($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5D68);
    // 0x800AF4A0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800AF4A4: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x800AF4A8: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800AF4AC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800AF4B0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800AF4B4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800AF4B8: sw          $v0, 0x934($s2)
    MEM_W(0X934, ctx->r18) = ctx->r2;
    // 0x800AF4BC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800AF4C0: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x800AF4C4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800AF4C8: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x800AF4CC: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800AF4D0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800AF4D4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800AF4D8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF4DC: lwc1        $f2, 0x5D6C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5D6C);
    // 0x800AF4E0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800AF4E4: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x800AF4E8: swc1        $f2, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f2.u32l;
    // 0x800AF4EC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800AF4F0: jal         0x800642A0
    // 0x800AF4F4: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    func_800642A0(rdram, ctx);
        goto after_1;
    // 0x800AF4F4: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x800AF4F8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800AF4FC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800AF500: jal         0x800646AC
    // 0x800AF504: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800646AC(rdram, ctx);
        goto after_2;
    // 0x800AF504: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_800AF508:
    // 0x800AF508: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x800AF50C: lw          $v0, 0x75A4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X75A4);
    // 0x800AF510: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x800AF514: bne         $v0, $zero, L_800AF524
    if (ctx->r2 != 0) {
        // 0x800AF518: nop
    
            goto L_800AF524;
    }
    // 0x800AF518: nop

    // 0x800AF51C: jal         0x8001B7C8
    // 0x800AF520: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_8001B7C8(rdram, ctx);
        goto after_3;
    // 0x800AF520: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_3:
L_800AF524:
    // 0x800AF524: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800AF528: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF52C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800AF530: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800AF534: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800AF538: jr          $ra
    // 0x800AF53C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800AF53C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800AF540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF540: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800AF544: lw          $v0, 0x934($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X934);
    // 0x800AF548: jr          $ra
    // 0x800AF54C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x800AF54C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
;}
RECOMP_FUNC void func_800AF550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF550: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800AF554: lw          $v1, 0x934($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X934);
    // 0x800AF558: mtc1        $a2, $f0
    ctx->f0.u32l = ctx->r6;
    // 0x800AF55C: beq         $v1, $zero, L_800AF604
    if (ctx->r3 == 0) {
        // 0x800AF560: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_800AF604;
    }
    // 0x800AF560: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800AF564: lwc1        $f2, 0x1EE8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X1EE8);
    // 0x800AF568: lw          $v1, 0xC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XC);
    // 0x800AF56C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800AF570: lbu         $v0, 0x2F($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2F);
    // 0x800AF574: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800AF578: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800AF57C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800AF580: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF584: lwc1        $f0, 0x5D70($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5D70);
    // 0x800AF588: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800AF58C: nop

    // 0x800AF590: bc1f        L_800AF5C4
    if (!c1cs) {
        // 0x800AF594: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_800AF5C4;
    }
    // 0x800AF594: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800AF598: sb          $v0, 0x2F($v1)
    MEM_B(0X2F, ctx->r3) = ctx->r2;
    // 0x800AF59C: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x800AF5A0: lbu         $v0, 0x938($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X938);
    // 0x800AF5A4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800AF5A8: sb          $v0, 0x938($v1)
    MEM_B(0X938, ctx->r3) = ctx->r2;
    // 0x800AF5AC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800AF5B0: sltiu       $v0, $v0, 0x7
    ctx->r2 = ctx->r2 < 0X7 ? 1 : 0;
    // 0x800AF5B4: bne         $v0, $zero, L_800AF604
    if (ctx->r2 != 0) {
        // 0x800AF5B8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800AF604;
    }
    // 0x800AF5B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AF5BC: jr          $ra
    // 0x800AF5C0: nop

    return;
    // 0x800AF5C0: nop

L_800AF5C4:
    // 0x800AF5C4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF5C8: lwc1        $f0, 0x5D74($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5D74);
    // 0x800AF5CC: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800AF5D0: nop

    // 0x800AF5D4: bc1t        L_800AF5EC
    if (c1cs) {
        // 0x800AF5D8: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_800AF5EC;
    }
    // 0x800AF5D8: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x800AF5DC: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800AF5E0: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800AF5E4: j           L_800AF604
    // 0x800AF5E8: sb          $v1, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = ctx->r3;
        goto L_800AF604;
    // 0x800AF5E8: sb          $v1, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = ctx->r3;
L_800AF5EC:
    // 0x800AF5EC: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800AF5F0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800AF5F4: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800AF5F8: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800AF5FC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800AF600: sb          $v1, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = ctx->r3;
L_800AF604:
    // 0x800AF604: jr          $ra
    // 0x800AF608: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800AF608: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_800AF60C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF60C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AF610: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800AF614: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x800AF618: lw          $v0, 0x934($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X934);
    // 0x800AF61C: beq         $v0, $zero, L_800AF64C
    if (ctx->r2 == 0) {
        // 0x800AF620: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800AF64C;
    }
    // 0x800AF620: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AF624: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x800AF628: jal         0x800643C4
    // 0x800AF62C: nop

    func_800643C4(rdram, ctx);
        goto after_0;
    // 0x800AF62C: nop

    after_0:
    // 0x800AF630: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x800AF634: lw          $v0, 0x75A4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X75A4);
    // 0x800AF638: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x800AF63C: bne         $v0, $zero, L_800AF64C
    if (ctx->r2 != 0) {
        // 0x800AF640: sw          $zero, 0x934($s0)
        MEM_W(0X934, ctx->r16) = 0;
            goto L_800AF64C;
    }
    // 0x800AF640: sw          $zero, 0x934($s0)
    MEM_W(0X934, ctx->r16) = 0;
    // 0x800AF644: jal         0x8001B7B8
    // 0x800AF648: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_8001B7B8(rdram, ctx);
        goto after_1;
    // 0x800AF648: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_1:
L_800AF64C:
    // 0x800AF64C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AF650: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800AF654: jr          $ra
    // 0x800AF658: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800AF658: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800AF65C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF65C: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x800AF660: jr          $ra
    // 0x800AF664: nop

    return;
    // 0x800AF664: nop

;}
RECOMP_FUNC void func_800AF668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF668: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800AF66C: lw          $v0, 0x934($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X934);
    // 0x800AF670: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF674: lwc1        $f4, 0x5D78($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5D78);
    // 0x800AF678: beq         $v0, $zero, L_800AF6A0
    if (ctx->r2 == 0) {
        // 0x800AF67C: nop
    
            goto L_800AF6A0;
    }
    // 0x800AF67C: nop

    // 0x800AF680: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x800AF684: lbu         $v0, 0x2F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2F);
    // 0x800AF688: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF68C: lwc1        $f2, 0x5D7C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5D7C);
    // 0x800AF690: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800AF694: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800AF698: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800AF69C: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
L_800AF6A0:
    // 0x800AF6A0: jr          $ra
    // 0x800AF6A4: mov.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = ctx->f4.fl;
    return;
    // 0x800AF6A4: mov.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = ctx->f4.fl;
;}
RECOMP_FUNC void fake_func_800AF6A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800AF6AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF6AC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF6B0: lwc1        $f4, -0x24F0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, -0X24F0);
    // 0x800AF6B4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF6B8: lwc1        $f0, 0x590C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X590C);
    // 0x800AF6BC: mul.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800AF6C0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF6C4: lwc1        $f2, -0x2520($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X2520);
    // 0x800AF6C8: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800AF6CC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF6D0: lwc1        $f2, 0x5910($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5910);
    // 0x800AF6D4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800AF6D8: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800AF6DC: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x800AF6E0: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x800AF6E4: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800AF6E8: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800AF6EC: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800AF6F0: sdc1        $f22, 0x68($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X68, ctx->r29);
    // 0x800AF6F4: sdc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X60, ctx->r29);
    // 0x800AF6F8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800AF6FC: nop

    // 0x800AF700: bc1f        L_800AF710
    if (!c1cs) {
        // 0x800AF704: swc1        $f0, -0x2520($v0)
        MEM_W(-0X2520, ctx->r2) = ctx->f0.u32l;
            goto L_800AF710;
    }
    // 0x800AF704: swc1        $f0, -0x2520($v0)
    MEM_W(-0X2520, ctx->r2) = ctx->f0.u32l;
    // 0x800AF708: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800AF70C: swc1        $f0, -0x2520($v0)
    MEM_W(-0X2520, ctx->r2) = ctx->f0.u32l;
L_800AF710:
    // 0x800AF710: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x800AF714: lbu         $v1, -0x253B($s4)
    ctx->r3 = MEM_BU(ctx->r20, -0X253B);
    // 0x800AF718: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800AF71C: beq         $v1, $s3, L_800AF794
    if (ctx->r3 == ctx->r19) {
        // 0x800AF720: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_800AF794;
    }
    // 0x800AF720: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800AF724: beq         $v0, $zero, L_800AF73C
    if (ctx->r2 == 0) {
        // 0x800AF728: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800AF73C;
    }
    // 0x800AF728: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800AF72C: beq         $v1, $zero, L_800AF754
    if (ctx->r3 == 0) {
        // 0x800AF730: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800AF754;
    }
    // 0x800AF730: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF734: j           L_800AFAAC
    // 0x800AF738: nop

        goto L_800AFAAC;
    // 0x800AF738: nop

L_800AF73C:
    // 0x800AF73C: beq         $v1, $v0, L_800AF898
    if (ctx->r3 == ctx->r2) {
        // 0x800AF740: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800AF898;
    }
    // 0x800AF740: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800AF744: beq         $v1, $v0, L_800AF914
    if (ctx->r3 == ctx->r2) {
        // 0x800AF748: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800AF914;
    }
    // 0x800AF748: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF74C: j           L_800AFAAC
    // 0x800AF750: nop

        goto L_800AFAAC;
    // 0x800AF750: nop

L_800AF754:
    // 0x800AF754: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF758: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AF75C: lbu         $a0, -0x253E($v0)
    ctx->r4 = MEM_BU(ctx->r2, -0X253E);
    // 0x800AF760: lbu         $v0, -0x253F($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X253F);
    // 0x800AF764: beq         $a0, $v0, L_800AFAA8
    if (ctx->r4 == ctx->r2) {
        // 0x800AF768: addiu       $a1, $zero, 0x51
        ctx->r5 = ADD32(0, 0X51);
            goto L_800AFAA8;
    }
    // 0x800AF768: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    // 0x800AF76C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    // 0x800AF770: jal         0x80087EE8
    // 0x800AF774: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80087EE8(rdram, ctx);
        goto after_0;
    // 0x800AF774: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_0:
    // 0x800AF778: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800AF77C: jal         0x80088D1C
    // 0x800AF780: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80088D1C(rdram, ctx);
        goto after_1;
    // 0x800AF780: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x800AF784: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF788: sw          $zero, -0x2500($v0)
    MEM_W(-0X2500, ctx->r2) = 0;
    // 0x800AF78C: j           L_800AFAA8
    // 0x800AF790: sb          $s3, -0x253B($s4)
    MEM_B(-0X253B, ctx->r20) = ctx->r19;
        goto L_800AFAA8;
    // 0x800AF790: sb          $s3, -0x253B($s4)
    MEM_B(-0X253B, ctx->r20) = ctx->r19;
L_800AF794:
    // 0x800AF794: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF798: lwc1        $f2, 0x5914($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5914);
    // 0x800AF79C: mul.s       $f2, $f4, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800AF7A0: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800AF7A4: lwc1        $f0, -0x2500($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, -0X2500);
    // 0x800AF7A8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800AF7AC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF7B0: lwc1        $f20, 0x5918($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5918);
    // 0x800AF7B4: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800AF7B8: nop

    // 0x800AF7BC: bc1f        L_800AF7C8
    if (!c1cs) {
        // 0x800AF7C0: swc1        $f0, -0x2500($s0)
        MEM_W(-0X2500, ctx->r16) = ctx->f0.u32l;
            goto L_800AF7C8;
    }
    // 0x800AF7C0: swc1        $f0, -0x2500($s0)
    MEM_W(-0X2500, ctx->r16) = ctx->f0.u32l;
    // 0x800AF7C4: swc1        $f20, -0x2500($s0)
    MEM_W(-0X2500, ctx->r16) = ctx->f20.u32l;
L_800AF7C8:
    // 0x800AF7C8: lwc1        $f12, -0x2500($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, -0X2500);
    // 0x800AF7CC: jal         0x800662E0
    // 0x800AF7D0: nop

    func_800662E0(rdram, ctx);
        goto after_2;
    // 0x800AF7D0: nop

    after_2:
    // 0x800AF7D4: sub.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x800AF7D8: lwc1        $f2, -0x2500($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, -0X2500);
    // 0x800AF7DC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF7E0: c.le.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl <= ctx->f2.fl;
    // 0x800AF7E4: nop

    // 0x800AF7E8: bc1f        L_800AFAA8
    if (!c1cs) {
        // 0x800AF7EC: swc1        $f0, -0x2510($v0)
        MEM_W(-0X2510, ctx->r2) = ctx->f0.u32l;
            goto L_800AFAA8;
    }
    // 0x800AF7EC: swc1        $f0, -0x2510($v0)
    MEM_W(-0X2510, ctx->r2) = ctx->f0.u32l;
    // 0x800AF7F0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF7F4: lbu         $v0, -0x2547($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2547);
    // 0x800AF7F8: bne         $v0, $s3, L_800AF83C
    if (ctx->r2 != ctx->r19) {
        // 0x800AF7FC: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800AF83C;
    }
    // 0x800AF7FC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF800: jal         0x800B4264
    // 0x800AF804: nop

    func_800B4264(rdram, ctx);
        goto after_3;
    // 0x800AF804: nop

    after_3:
    // 0x800AF808: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800AF80C: bne         $v0, $zero, L_800AF820
    if (ctx->r2 != 0) {
        // 0x800AF810: lui         $v1, 0x800D
        ctx->r3 = S32(0X800D << 16);
            goto L_800AF820;
    }
    // 0x800AF810: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AF814: jal         0x800B2564
    // 0x800AF818: nop

    func_800B2564(rdram, ctx);
        goto after_4;
    // 0x800AF818: nop

    after_4:
    // 0x800AF81C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
L_800AF820:
    // 0x800AF820: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800AF824: sb          $v0, -0x253C($v1)
    MEM_B(-0X253C, ctx->r3) = ctx->r2;
    // 0x800AF828: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF82C: lbu         $v1, -0x253F($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X253F);
    // 0x800AF830: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF834: j           L_800AFAA8
    // 0x800AF838: sw          $v1, -0x2534($v0)
    MEM_W(-0X2534, ctx->r2) = ctx->r3;
        goto L_800AFAA8;
    // 0x800AF838: sw          $v1, -0x2534($v0)
    MEM_W(-0X2534, ctx->r2) = ctx->r3;
L_800AF83C:
    // 0x800AF83C: sb          $zero, -0x253A($v0)
    MEM_B(-0X253A, ctx->r2) = 0;
    // 0x800AF840: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800AF844: sb          $v0, -0x253B($s4)
    MEM_B(-0X253B, ctx->r20) = ctx->r2;
    // 0x800AF848: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF84C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AF850: lbu         $v0, -0x253F($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X253F);
    // 0x800AF854: lbu         $v1, -0x2546($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X2546);
    // 0x800AF858: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800AF85C: bne         $v1, $zero, L_800AFAA8
    if (ctx->r3 != 0) {
        // 0x800AF860: sb          $v0, -0x253E($a1)
        MEM_B(-0X253E, ctx->r5) = ctx->r2;
            goto L_800AFAA8;
    }
    // 0x800AF860: sb          $v0, -0x253E($a1)
    MEM_B(-0X253E, ctx->r5) = ctx->r2;
    // 0x800AF864: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800AF868: addiu       $s0, $s0, -0x2570
    ctx->r16 = ADD32(ctx->r16, -0X2570);
    // 0x800AF86C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800AF870: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // 0x800AF874: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800AF878: jal         0x80033CC4
    // 0x800AF87C: addiu       $a1, $a1, 0x58BC
    ctx->r5 = ADD32(ctx->r5, 0X58BC);
    sprintf_recomp(rdram, ctx);
        goto after_5;
    // 0x800AF87C: addiu       $a1, $a1, 0x58BC
    ctx->r5 = ADD32(ctx->r5, 0X58BC);
    after_5:
    // 0x800AF880: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF884: lw          $a0, -0x2290($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X2290);
    // 0x800AF888: jal         0x800B3F24
    // 0x800AF88C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800B3F24(rdram, ctx);
        goto after_6;
    // 0x800AF88C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_6:
    // 0x800AF890: j           L_800AFAAC
    // 0x800AF894: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
        goto L_800AFAAC;
    // 0x800AF894: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
L_800AF898:
    // 0x800AF898: jal         0x800B3FD8
    // 0x800AF89C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    func_800B3FD8(rdram, ctx);
        goto after_7;
    // 0x800AF89C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_7:
    // 0x800AF8A0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800AF8A4: bne         $v0, $zero, L_800AF8BC
    if (ctx->r2 != 0) {
        // 0x800AF8A8: lui         $s0, 0x800D
        ctx->r16 = S32(0X800D << 16);
            goto L_800AF8BC;
    }
    // 0x800AF8A8: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800AF8AC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF8B0: lbu         $v0, -0x2546($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2546);
    // 0x800AF8B4: beq         $v0, $zero, L_800AFAAC
    if (ctx->r2 == 0) {
        // 0x800AF8B8: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800AFAAC;
    }
    // 0x800AF8B8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
L_800AF8BC:
    // 0x800AF8BC: lbu         $v0, -0x2546($s0)
    ctx->r2 = MEM_BU(ctx->r16, -0X2546);
    // 0x800AF8C0: bne         $v0, $zero, L_800AF8E4
    if (ctx->r2 != 0) {
        // 0x800AF8C4: addiu       $a0, $zero, 0x2C
        ctx->r4 = ADD32(0, 0X2C);
            goto L_800AF8E4;
    }
    // 0x800AF8C4: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    // 0x800AF8C8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF8CC: lw          $a0, -0x2324($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X2324);
    // 0x800AF8D0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF8D4: lbu         $a1, -0x253E($v0)
    ctx->r5 = MEM_BU(ctx->r2, -0X253E);
    // 0x800AF8D8: jal         0x800B180C
    // 0x800AF8DC: nop

    func_800B180C(rdram, ctx);
        goto after_8;
    // 0x800AF8DC: nop

    after_8:
    // 0x800AF8E0: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
L_800AF8E4:
    // 0x800AF8E4: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    // 0x800AF8E8: jal         0x80087EE8
    // 0x800AF8EC: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80087EE8(rdram, ctx);
        goto after_9;
    // 0x800AF8EC: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_9:
    // 0x800AF8F0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800AF8F4: jal         0x80088D1C
    // 0x800AF8F8: addiu       $a1, $zero, 0x3000
    ctx->r5 = ADD32(0, 0X3000);
    func_80088D1C(rdram, ctx);
        goto after_10;
    // 0x800AF8F8: addiu       $a1, $zero, 0x3000
    ctx->r5 = ADD32(0, 0X3000);
    after_10:
    // 0x800AF8FC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF900: sw          $zero, -0x2500($v0)
    MEM_W(-0X2500, ctx->r2) = 0;
    // 0x800AF904: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800AF908: sb          $zero, -0x2546($s0)
    MEM_B(-0X2546, ctx->r16) = 0;
    // 0x800AF90C: j           L_800AFAA8
    // 0x800AF910: sb          $v0, -0x253B($s4)
    MEM_B(-0X253B, ctx->r20) = ctx->r2;
        goto L_800AFAA8;
    // 0x800AF910: sb          $v0, -0x253B($s4)
    MEM_B(-0X253B, ctx->r20) = ctx->r2;
L_800AF914:
    // 0x800AF914: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF918: lwc1        $f2, 0x591C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X591C);
    // 0x800AF91C: mul.s       $f2, $f4, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800AF920: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800AF924: lwc1        $f0, -0x2500($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, -0X2500);
    // 0x800AF928: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800AF92C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF930: lwc1        $f22, 0x5920($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X5920);
    // 0x800AF934: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x800AF938: nop

    // 0x800AF93C: bc1f        L_800AF948
    if (!c1cs) {
        // 0x800AF940: swc1        $f0, -0x2500($s1)
        MEM_W(-0X2500, ctx->r17) = ctx->f0.u32l;
            goto L_800AF948;
    }
    // 0x800AF940: swc1        $f0, -0x2500($s1)
    MEM_W(-0X2500, ctx->r17) = ctx->f0.u32l;
    // 0x800AF944: swc1        $f22, -0x2500($s1)
    MEM_W(-0X2500, ctx->r17) = ctx->f22.u32l;
L_800AF948:
    // 0x800AF948: lwc1        $f12, -0x2500($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, -0X2500);
    // 0x800AF94C: jal         0x800662E0
    // 0x800AF950: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    func_800662E0(rdram, ctx);
        goto after_11;
    // 0x800AF950: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    after_11:
    // 0x800AF954: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AF958: lbu         $v0, -0x2548($s2)
    ctx->r2 = MEM_BU(ctx->r18, -0X2548);
    // 0x800AF95C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800AF960: bne         $v0, $s3, L_800AFA00
    if (ctx->r2 != ctx->r19) {
        // 0x800AF964: swc1        $f20, -0x2510($v1)
        MEM_W(-0X2510, ctx->r3) = ctx->f20.u32l;
            goto L_800AFA00;
    }
    // 0x800AF964: swc1        $f20, -0x2510($v1)
    MEM_W(-0X2510, ctx->r3) = ctx->f20.u32l;
    // 0x800AF968: lwc1        $f12, -0x2500($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, -0X2500);
    // 0x800AF96C: jal         0x800662E0
    // 0x800AF970: nop

    func_800662E0(rdram, ctx);
        goto after_12;
    // 0x800AF970: nop

    after_12:
    // 0x800AF974: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF978: lwc1        $f2, 0x5924($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5924);
    // 0x800AF97C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800AF980: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF984: lwc1        $f12, 0x5928($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5928);
    // 0x800AF988: mul.s       $f12, $f20, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f12.fl);
    // 0x800AF98C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF990: lwc1        $f8, 0x592C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X592C);
    // 0x800AF994: mul.s       $f8, $f20, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x800AF998: sub.s       $f4, $f22, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f22.fl - ctx->f20.fl;
    // 0x800AF99C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF9A0: lwc1        $f10, 0x5930($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5930);
    // 0x800AF9A4: mul.s       $f10, $f4, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800AF9A8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF9AC: lwc1        $f6, 0x5934($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5934);
    // 0x800AF9B0: mul.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AF9B4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF9B8: lwc1        $f2, 0x5938($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5938);
    // 0x800AF9BC: mul.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800AF9C0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AF9C4: lwc1        $f2, 0x593C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X593C);
    // 0x800AF9C8: mul.s       $f2, $f20, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x800AF9CC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF9D0: add.s       $f10, $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x800AF9D4: swc1        $f20, -0x2504($v0)
    MEM_W(-0X2504, ctx->r2) = ctx->f20.u32l;
    // 0x800AF9D8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF9DC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AF9E0: swc1        $f0, -0x251C($v0)
    MEM_W(-0X251C, ctx->r2) = ctx->f0.u32l;
    // 0x800AF9E4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF9E8: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800AF9EC: swc1        $f10, -0x2524($v0)
    MEM_W(-0X2524, ctx->r2) = ctx->f10.u32l;
    // 0x800AF9F0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF9F4: swc1        $f6, -0x252C($v0)
    MEM_W(-0X252C, ctx->r2) = ctx->f6.u32l;
    // 0x800AF9F8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AF9FC: swc1        $f4, -0x2528($v0)
    MEM_W(-0X2528, ctx->r2) = ctx->f4.u32l;
L_800AFA00:
    // 0x800AFA00: lwc1        $f0, -0x2500($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, -0X2500);
    // 0x800AFA04: c.eq.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl == ctx->f22.fl;
    // 0x800AFA08: nop

    // 0x800AFA0C: bc1f        L_800AFAAC
    if (!c1cs) {
        // 0x800AFA10: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800AFAAC;
    }
    // 0x800AFA10: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFA14: lbu         $v0, -0x2548($s2)
    ctx->r2 = MEM_BU(ctx->r18, -0X2548);
    // 0x800AFA18: bne         $v0, $s3, L_800AFA80
    if (ctx->r2 != ctx->r19) {
        // 0x800AFA1C: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800AFA80;
    }
    // 0x800AFA1C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFA20: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AFA24: lui         $a2, 0x2000
    ctx->r6 = S32(0X2000 << 16);
    // 0x800AFA28: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x800AFA2C: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800AFA30: addiu       $s0, $s0, -0x2310
    ctx->r16 = ADD32(ctx->r16, -0X2310);
    // 0x800AFA34: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x800AFA38: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFA3C: jal         0x8005955C
    // 0x800AFA40: sw          $zero, -0x2430($v0)
    MEM_W(-0X2430, ctx->r2) = 0;
    func_8005955C(rdram, ctx);
        goto after_13;
    // 0x800AFA40: sw          $zero, -0x2430($v0)
    MEM_W(-0X2430, ctx->r2) = 0;
    after_13:
    // 0x800AFA44: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AFA48: lui         $a2, 0x2000
    ctx->r6 = S32(0X2000 << 16);
    // 0x800AFA4C: lw          $a0, 0x64($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X64);
    // 0x800AFA50: jal         0x8005955C
    // 0x800AFA54: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8005955C(rdram, ctx);
        goto after_14;
    // 0x800AFA54: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_14:
    // 0x800AFA58: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x800AFA5C: jal         0x80059614
    // 0x800AFA60: nop

    func_80059614(rdram, ctx);
        goto after_15;
    // 0x800AFA60: nop

    after_15:
    // 0x800AFA64: lw          $a0, 0x64($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X64);
    // 0x800AFA68: jal         0x80059614
    // 0x800AFA6C: nop

    func_80059614(rdram, ctx);
        goto after_16;
    // 0x800AFA6C: nop

    after_16:
    // 0x800AFA70: jal         0x8001B7B8
    // 0x800AFA74: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001B7B8(rdram, ctx);
        goto after_17;
    // 0x800AFA74: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_17:
    // 0x800AFA78: sb          $zero, -0x2548($s2)
    MEM_B(-0X2548, ctx->r18) = 0;
    // 0x800AFA7C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
L_800AFA80:
    // 0x800AFA80: lbu         $v0, -0x2539($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2539);
    // 0x800AFA84: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800AFA88: bne         $v0, $s3, L_800AFA94
    if (ctx->r2 != ctx->r19) {
        // 0x800AFA8C: sw          $zero, -0x2500($s1)
        MEM_W(-0X2500, ctx->r17) = 0;
            goto L_800AFA94;
    }
    // 0x800AFA8C: sw          $zero, -0x2500($s1)
    MEM_W(-0X2500, ctx->r17) = 0;
    // 0x800AFA90: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_800AFA94:
    // 0x800AFA94: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFA98: sb          $v1, -0x253C($v0)
    MEM_B(-0X253C, ctx->r2) = ctx->r3;
    // 0x800AFA9C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFAA0: sb          $zero, -0x2541($v0)
    MEM_B(-0X2541, ctx->r2) = 0;
    // 0x800AFAA4: sb          $zero, -0x253B($s4)
    MEM_B(-0X253B, ctx->r20) = 0;
L_800AFAA8:
    // 0x800AFAA8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
L_800AFAAC:
    // 0x800AFAAC: lbu         $v0, -0x253C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X253C);
    // 0x800AFAB0: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x800AFAB4: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800AFAB8: beq         $v0, $zero, L_800AFBD4
    if (ctx->r2 == 0) {
        // 0x800AFABC: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800AFBD4;
    }
    // 0x800AFABC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFAC0: lbu         $v0, -0x253B($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X253B);
    // 0x800AFAC4: bne         $v0, $zero, L_800AFBD8
    if (ctx->r2 != 0) {
        // 0x800AFAC8: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800AFBD8;
    }
    // 0x800AFAC8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFACC: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x800AFAD0: lb          $v0, -0x2540($s2)
    ctx->r2 = MEM_B(ctx->r18, -0X2540);
    // 0x800AFAD4: bne         $v0, $zero, L_800AFBD8
    if (ctx->r2 != 0) {
        // 0x800AFAD8: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800AFBD8;
    }
    // 0x800AFAD8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFADC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFAE0: lbu         $a0, -0x2538($v0)
    ctx->r4 = MEM_BU(ctx->r2, -0X2538);
    // 0x800AFAE4: jal         0x80079F50
    // 0x800AFAE8: nop

    getControllerNewButtonsPressed(rdram, ctx);
        goto after_18;
    // 0x800AFAE8: nop

    after_18:
    // 0x800AFAEC: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x800AFAF0: bne         $v0, $zero, L_800AFB08
    if (ctx->r2 != 0) {
        // 0x800AFAF4: lui         $s0, 0x800D
        ctx->r16 = S32(0X800D << 16);
            goto L_800AFB08;
    }
    // 0x800AFAF4: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800AFAF8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFAFC: lbu         $v0, -0x2543($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2543);
    // 0x800AFB00: beq         $v0, $zero, L_800AFBD8
    if (ctx->r2 == 0) {
        // 0x800AFB04: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800AFBD8;
    }
    // 0x800AFB04: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
L_800AFB08:
    // 0x800AFB08: lbu         $v1, -0x2545($s0)
    ctx->r3 = MEM_BU(ctx->r16, -0X2545);
    // 0x800AFB0C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFB10: bne         $v1, $zero, L_800AFB84
    if (ctx->r3 != 0) {
        // 0x800AFB14: sb          $zero, -0x2543($v0)
        MEM_B(-0X2543, ctx->r2) = 0;
            goto L_800AFB84;
    }
    // 0x800AFB14: sb          $zero, -0x2543($v0)
    MEM_B(-0X2543, ctx->r2) = 0;
    // 0x800AFB18: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800AFB1C: lw          $a0, -0x2054($s1)
    ctx->r4 = MEM_W(ctx->r17, -0X2054);
    // 0x800AFB20: jal         0x80063F9C
    // 0x800AFB24: nop

    func_80063F9C(rdram, ctx);
        goto after_19;
    // 0x800AFB24: nop

    after_19:
    // 0x800AFB28: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800AFB2C: beq         $v0, $zero, L_800AFBD4
    if (ctx->r2 == 0) {
        // 0x800AFB30: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_800AFBD4;
    }
    // 0x800AFB30: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800AFB34: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800AFB38: addiu       $a2, $zero, 0x128
    ctx->r6 = ADD32(0, 0X128);
    // 0x800AFB3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AFB40: jal         0x80063E2C
    // 0x800AFB44: sb          $v0, -0x2545($s0)
    MEM_B(-0X2545, ctx->r16) = ctx->r2;
    func_80063E2C(rdram, ctx);
        goto after_20;
    // 0x800AFB44: sb          $v0, -0x2545($s0)
    MEM_B(-0X2545, ctx->r16) = ctx->r2;
    after_20:
    // 0x800AFB48: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFB4C: lbu         $a0, -0x253F($v0)
    ctx->r4 = MEM_BU(ctx->r2, -0X253F);
    // 0x800AFB50: jal         0x8005589C
    // 0x800AFB54: addiu       $a0, $a0, 0x21
    ctx->r4 = ADD32(ctx->r4, 0X21);
    getGameOrFrontText(rdram, ctx);
        goto after_21;
    // 0x800AFB54: addiu       $a0, $a0, 0x21
    ctx->r4 = ADD32(ctx->r4, 0X21);
    after_21:
    // 0x800AFB58: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800AFB5C: lw          $a0, -0x2054($s1)
    ctx->r4 = MEM_W(ctx->r17, -0X2054);
    // 0x800AFB60: jal         0x80062EDC
    // 0x800AFB64: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80062EDC(rdram, ctx);
        goto after_22;
    // 0x800AFB64: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_22:
    // 0x800AFB68: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800AFB6C: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    // 0x800AFB70: jal         0x80063E2C
    // 0x800AFB74: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80063E2C(rdram, ctx);
        goto after_23;
    // 0x800AFB74: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_23:
    // 0x800AFB78: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800AFB7C: j           L_800AFBD4
    // 0x800AFB80: sb          $v0, -0x2540($s2)
    MEM_B(-0X2540, ctx->r18) = ctx->r2;
        goto L_800AFBD4;
    // 0x800AFB80: sb          $v0, -0x2540($s2)
    MEM_B(-0X2540, ctx->r18) = ctx->r2;
L_800AFB84:
    // 0x800AFB84: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFB88: lw          $a0, -0x2054($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X2054);
    // 0x800AFB8C: jal         0x80063F7C
    // 0x800AFB90: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    func_80063F7C(rdram, ctx);
        goto after_24;
    // 0x800AFB90: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    after_24:
    // 0x800AFB94: lw          $a0, -0x3900($s1)
    ctx->r4 = MEM_W(ctx->r17, -0X3900);
    // 0x800AFB98: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x800AFB9C: beq         $a0, $s0, L_800AFBB4
    if (ctx->r4 == ctx->r16) {
        // 0x800AFBA0: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800AFBB4;
    }
    // 0x800AFBA0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFBA4: jal         0x800894F0
    // 0x800AFBA8: nop

    func_800894F0(rdram, ctx);
        goto after_25;
    // 0x800AFBA8: nop

    after_25:
    // 0x800AFBAC: sw          $s0, -0x3900($s1)
    MEM_W(-0X3900, ctx->r17) = ctx->r16;
    // 0x800AFBB0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
L_800AFBB4:
    // 0x800AFBB4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AFBB8: lwc1        $f0, 0x5940($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5940);
    // 0x800AFBBC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800AFBC0: sb          $v1, -0x2544($v0)
    MEM_B(-0X2544, ctx->r2) = ctx->r3;
    // 0x800AFBC4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFBC8: sb          $v1, -0x2541($v0)
    MEM_B(-0X2541, ctx->r2) = ctx->r3;
    // 0x800AFBCC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFBD0: swc1        $f0, -0x24F4($v0)
    MEM_W(-0X24F4, ctx->r2) = ctx->f0.u32l;
L_800AFBD4:
    // 0x800AFBD4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
L_800AFBD8:
    // 0x800AFBD8: lbu         $v1, -0x253C($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X253C);
    // 0x800AFBDC: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x800AFBE0: beq         $v0, $zero, L_800B0088
    if (ctx->r2 == 0) {
        // 0x800AFBE4: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_800B0088;
    }
    // 0x800AFBE4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800AFBE8: addiu       $v0, $v0, 0x5948
    ctx->r2 = ADD32(ctx->r2, 0X5948);
    // 0x800AFBEC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800AFBF0: addu        $v1, $v1, $v0
    gpr jr_addend_800AFBF8 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800AFBF4: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800AFBF8: jr          $v0
    // 0x800AFBFC: nop

    switch (jr_addend_800AFBF8 >> 2) {
        case 0: goto L_800AFC00; break;
        case 1: goto L_800AFCAC; break;
        case 2: goto L_800AFD28; break;
        case 3: goto L_800AFFA0; break;
        case 4: goto L_800B0088; break;
        default: switch_error(__func__, 0x800AFBF8, 0x800A5948);
    }
    // 0x800AFBFC: nop

L_800AFC00:
    // 0x800AFC00: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFC04: sw          $zero, -0x2518($v0)
    MEM_W(-0X2518, ctx->r2) = 0;
    // 0x800AFC08: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFC0C: sw          $zero, -0x2514($v0)
    MEM_W(-0X2514, ctx->r2) = 0;
    // 0x800AFC10: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFC14: sw          $zero, -0x251C($v0)
    MEM_W(-0X251C, ctx->r2) = 0;
    // 0x800AFC18: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFC1C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AFC20: lwc1        $f0, 0x595C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X595C);
    // 0x800AFC24: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800AFC28: sb          $v1, -0x2548($v0)
    MEM_B(-0X2548, ctx->r2) = ctx->r3;
    // 0x800AFC2C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFC30: sb          $zero, -0x2547($v0)
    MEM_B(-0X2547, ctx->r2) = 0;
    // 0x800AFC34: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFC38: sw          $zero, -0x2510($v0)
    MEM_W(-0X2510, ctx->r2) = 0;
    // 0x800AFC3C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFC40: sw          $zero, -0x250C($v0)
    MEM_W(-0X250C, ctx->r2) = 0;
    // 0x800AFC44: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFC48: sw          $zero, -0x2504($v0)
    MEM_W(-0X2504, ctx->r2) = 0;
    // 0x800AFC4C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFC50: sb          $v1, -0x253C($v0)
    MEM_B(-0X253C, ctx->r2) = ctx->r3;
    // 0x800AFC54: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFC58: sb          $zero, -0x2546($v0)
    MEM_B(-0X2546, ctx->r2) = 0;
    // 0x800AFC5C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFC60: sb          $zero, -0x2543($v0)
    MEM_B(-0X2543, ctx->r2) = 0;
    // 0x800AFC64: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFC68: swc1        $f0, -0x2508($v0)
    MEM_W(-0X2508, ctx->r2) = ctx->f0.u32l;
    // 0x800AFC6C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AFC70: lwc1        $f0, 0x5960($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5960);
    // 0x800AFC74: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFC78: swc1        $f0, -0x2524($v0)
    MEM_W(-0X2524, ctx->r2) = ctx->f0.u32l;
    // 0x800AFC7C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AFC80: lwc1        $f0, 0x5964($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5964);
    // 0x800AFC84: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFC88: swc1        $f0, -0x252C($v0)
    MEM_W(-0X252C, ctx->r2) = ctx->f0.u32l;
    // 0x800AFC8C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AFC90: lwc1        $f0, 0x5968($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5968);
    // 0x800AFC94: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFC98: swc1        $f0, -0x2528($v0)
    MEM_W(-0X2528, ctx->r2) = ctx->f0.u32l;
    // 0x800AFC9C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AFCA0: lwc1        $f0, 0x596C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X596C);
    // 0x800AFCA4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFCA8: swc1        $f0, -0x24F8($v0)
    MEM_W(-0X24F8, ctx->r2) = ctx->f0.u32l;
L_800AFCAC:
    // 0x800AFCAC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AFCB0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFCB4: lwc1        $f0, -0x2518($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, -0X2518);
    // 0x800AFCB8: lwc1        $f2, -0x24F0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X24F0);
    // 0x800AFCBC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800AFCC0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AFCC4: lwc1        $f2, 0x5970($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5970);
    // 0x800AFCC8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800AFCCC: nop

    // 0x800AFCD0: bc1f        L_800B0088
    if (!c1cs) {
        // 0x800AFCD4: swc1        $f0, -0x2518($v1)
        MEM_W(-0X2518, ctx->r3) = ctx->f0.u32l;
            goto L_800B0088;
    }
    // 0x800AFCD4: swc1        $f0, -0x2518($v1)
    MEM_W(-0X2518, ctx->r3) = ctx->f0.u32l;
    // 0x800AFCD8: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    // 0x800AFCDC: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    // 0x800AFCE0: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x800AFCE4: sw          $zero, -0x2518($v1)
    MEM_W(-0X2518, ctx->r3) = 0;
    // 0x800AFCE8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AFCEC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800AFCF0: sb          $v0, -0x253C($v1)
    MEM_B(-0X253C, ctx->r3) = ctx->r2;
    // 0x800AFCF4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFCF8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AFCFC: sw          $zero, -0x2500($v0)
    MEM_W(-0X2500, ctx->r2) = 0;
    // 0x800AFD00: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800AFD04: jal         0x80087EE8
    // 0x800AFD08: sb          $v0, -0x253B($v1)
    MEM_B(-0X253B, ctx->r3) = ctx->r2;
    func_80087EE8(rdram, ctx);
        goto after_26;
    // 0x800AFD08: sb          $v0, -0x253B($v1)
    MEM_B(-0X253B, ctx->r3) = ctx->r2;
    after_26:
    // 0x800AFD0C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800AFD10: jal         0x80088D1C
    // 0x800AFD14: addiu       $a1, $zero, 0x3000
    ctx->r5 = ADD32(0, 0X3000);
    func_80088D1C(rdram, ctx);
        goto after_27;
    // 0x800AFD14: addiu       $a1, $zero, 0x3000
    ctx->r5 = ADD32(0, 0X3000);
    after_27:
    // 0x800AFD18: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AFD1C: lwc1        $f0, 0x5974($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5974);
    // 0x800AFD20: j           L_800AFF98
    // 0x800AFD24: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
        goto L_800AFF98;
    // 0x800AFD24: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
L_800AFD28:
    // 0x800AFD28: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AFD2C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFD30: lwc1        $f2, -0x2518($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, -0X2518);
    // 0x800AFD34: lwc1        $f0, -0x24F0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X24F0);
    // 0x800AFD38: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFD3C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800AFD40: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AFD44: lwc1        $f0, 0x5978($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5978);
    // 0x800AFD48: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AFD4C: lwc1        $f4, 0x597C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X597C);
    // 0x800AFD50: div.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800AFD54: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x800AFD58: swc1        $f2, -0x2518($v1)
    MEM_W(-0X2518, ctx->r3) = ctx->f2.u32l;
    // 0x800AFD5C: bc1f        L_800AFD68
    if (!c1cs) {
        // 0x800AFD60: swc1        $f0, -0x2514($v0)
        MEM_W(-0X2514, ctx->r2) = ctx->f0.u32l;
            goto L_800AFD68;
    }
    // 0x800AFD60: swc1        $f0, -0x2514($v0)
    MEM_W(-0X2514, ctx->r2) = ctx->f0.u32l;
    // 0x800AFD64: swc1        $f4, -0x2514($v0)
    MEM_W(-0X2514, ctx->r2) = ctx->f4.u32l;
L_800AFD68:
    // 0x800AFD68: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800AFD6C: lbu         $a0, -0x2538($s0)
    ctx->r4 = MEM_BU(ctx->r16, -0X2538);
    // 0x800AFD70: jal         0x80079F50
    // 0x800AFD74: nop

    getControllerNewButtonsPressed(rdram, ctx);
        goto after_28;
    // 0x800AFD74: nop

    after_28:
    // 0x800AFD78: lui         $v1, 0x80
    ctx->r3 = S32(0X80 << 16);
    // 0x800AFD7C: ori         $v1, $v1, 0x200
    ctx->r3 = ctx->r3 | 0X200;
    // 0x800AFD80: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800AFD84: beq         $v0, $zero, L_800AFE64
    if (ctx->r2 == 0) {
        // 0x800AFD88: lui         $a0, 0x800D
        ctx->r4 = S32(0X800D << 16);
            goto L_800AFE64;
    }
    // 0x800AFD88: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800AFD8C: lbu         $v1, -0x253F($a0)
    ctx->r3 = MEM_BU(ctx->r4, -0X253F);
    // 0x800AFD90: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFD94: sb          $v1, -0x253D($v0)
    MEM_B(-0X253D, ctx->r2) = ctx->r3;
    // 0x800AFD98: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800AFD9C: beq         $v0, $zero, L_800AFDA8
    if (ctx->r2 == 0) {
        // 0x800AFDA0: addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
            goto L_800AFDA8;
    }
    // 0x800AFDA0: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x800AFDA4: sb          $v0, -0x253F($a0)
    MEM_B(-0X253F, ctx->r4) = ctx->r2;
L_800AFDA8:
    // 0x800AFDA8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
L_800AFDAC:
    // 0x800AFDAC: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800AFDB0: lbu         $v1, -0x253D($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X253D);
    // 0x800AFDB4: lbu         $v0, -0x253F($s0)
    ctx->r2 = MEM_BU(ctx->r16, -0X253F);
    // 0x800AFDB8: beq         $v1, $v0, L_800B0088
    if (ctx->r3 == ctx->r2) {
        // 0x800AFDBC: nop
    
            goto L_800B0088;
    }
    // 0x800AFDBC: nop

    // 0x800AFDC0: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x800AFDC4: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x800AFDC8: jal         0x80087EE8
    // 0x800AFDCC: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80087EE8(rdram, ctx);
        goto after_29;
    // 0x800AFDCC: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_29:
    // 0x800AFDD0: lbu         $a0, -0x253F($s0)
    ctx->r4 = MEM_BU(ctx->r16, -0X253F);
    // 0x800AFDD4: jal         0x8005589C
    // 0x800AFDD8: nop

    getGameOrFrontText(rdram, ctx);
        goto after_30;
    // 0x800AFDD8: nop

    after_30:
    // 0x800AFDDC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AFDE0: lw          $a0, -0x205C($v1)
    ctx->r4 = MEM_W(ctx->r3, -0X205C);
    // 0x800AFDE4: jal         0x80062854
    // 0x800AFDE8: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_80062854(rdram, ctx);
        goto after_31;
    // 0x800AFDE8: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_31:
    // 0x800AFDEC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFDF0: lw          $a0, -0x2050($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X2050);
    // 0x800AFDF4: beq         $a0, $zero, L_800AFE04
    if (ctx->r4 == 0) {
        // 0x800AFDF8: lui         $s2, 0x800D
        ctx->r18 = S32(0X800D << 16);
            goto L_800AFE04;
    }
    // 0x800AFDF8: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x800AFDFC: jal         0x800CC02C
    // 0x800AFE00: nop

    func_800CC02C(rdram, ctx);
        goto after_32;
    // 0x800AFE00: nop

    after_32:
L_800AFE04:
    // 0x800AFE04: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AFE08: lwc1        $f0, 0x5980($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5980);
    // 0x800AFE0C: lbu         $v1, -0x2545($s2)
    ctx->r3 = MEM_BU(ctx->r18, -0X2545);
    // 0x800AFE10: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFE14: beq         $v1, $zero, L_800B0088
    if (ctx->r3 == 0) {
        // 0x800AFE18: swc1        $f0, -0x24F4($v0)
        MEM_W(-0X24F4, ctx->r2) = ctx->f0.u32l;
            goto L_800B0088;
    }
    // 0x800AFE18: swc1        $f0, -0x24F4($v0)
    MEM_W(-0X24F4, ctx->r2) = ctx->f0.u32l;
    // 0x800AFE1C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFE20: lw          $a0, -0x2054($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X2054);
    // 0x800AFE24: jal         0x80063F7C
    // 0x800AFE28: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    func_80063F7C(rdram, ctx);
        goto after_33;
    // 0x800AFE28: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    after_33:
    // 0x800AFE2C: lw          $a0, -0x3900($s1)
    ctx->r4 = MEM_W(ctx->r17, -0X3900);
    // 0x800AFE30: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x800AFE34: beq         $a0, $s0, L_800AFE4C
    if (ctx->r4 == ctx->r16) {
        // 0x800AFE38: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800AFE4C;
    }
    // 0x800AFE38: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFE3C: jal         0x800894F0
    // 0x800AFE40: nop

    func_800894F0(rdram, ctx);
        goto after_34;
    // 0x800AFE40: nop

    after_34:
    // 0x800AFE44: sw          $s0, -0x3900($s1)
    MEM_W(-0X3900, ctx->r17) = ctx->r16;
    // 0x800AFE48: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
L_800AFE4C:
    // 0x800AFE4C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800AFE50: sb          $v1, -0x2544($v0)
    MEM_B(-0X2544, ctx->r2) = ctx->r3;
    // 0x800AFE54: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFE58: sb          $zero, -0x2545($s2)
    MEM_B(-0X2545, ctx->r18) = 0;
    // 0x800AFE5C: j           L_800B0088
    // 0x800AFE60: sb          $v1, -0x2543($v0)
    MEM_B(-0X2543, ctx->r2) = ctx->r3;
        goto L_800B0088;
    // 0x800AFE60: sb          $v1, -0x2543($v0)
    MEM_B(-0X2543, ctx->r2) = ctx->r3;
L_800AFE64:
    // 0x800AFE64: lbu         $a0, -0x2538($s0)
    ctx->r4 = MEM_BU(ctx->r16, -0X2538);
    // 0x800AFE68: jal         0x80079F50
    // 0x800AFE6C: nop

    getControllerNewButtonsPressed(rdram, ctx);
        goto after_35;
    // 0x800AFE6C: nop

    after_35:
    // 0x800AFE70: lui         $v1, 0x40
    ctx->r3 = S32(0X40 << 16);
    // 0x800AFE74: ori         $v1, $v1, 0x100
    ctx->r3 = ctx->r3 | 0X100;
    // 0x800AFE78: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800AFE7C: beq         $v0, $zero, L_800AFEBC
    if (ctx->r2 == 0) {
        // 0x800AFE80: lui         $a1, 0x800D
        ctx->r5 = S32(0X800D << 16);
            goto L_800AFEBC;
    }
    // 0x800AFE80: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800AFE84: lbu         $v1, -0x253F($a1)
    ctx->r3 = MEM_BU(ctx->r5, -0X253F);
    // 0x800AFE88: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFE8C: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x800AFE90: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800AFE94: sb          $v1, -0x253D($v0)
    MEM_B(-0X253D, ctx->r2) = ctx->r3;
    // 0x800AFE98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AFE9C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AFEA0: lw          $v1, -0x2530($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2530);
    // 0x800AFEA4: sllv        $v0, $v0, $a0
    ctx->r2 = S32(ctx->r2 << (ctx->r4 & 31));
    // 0x800AFEA8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800AFEAC: bnel        $v0, $zero, L_800AFDA8
    if (ctx->r2 != 0) {
        // 0x800AFEB0: sb          $a0, -0x253F($a1)
        MEM_B(-0X253F, ctx->r5) = ctx->r4;
            goto L_800AFDA8;
    }
    goto skip_0;
    // 0x800AFEB0: sb          $a0, -0x253F($a1)
    MEM_B(-0X253F, ctx->r5) = ctx->r4;
    skip_0:
    // 0x800AFEB4: j           L_800AFDAC
    // 0x800AFEB8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
        goto L_800AFDAC;
    // 0x800AFEB8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
L_800AFEBC:
    // 0x800AFEBC: lbu         $a0, -0x2538($s0)
    ctx->r4 = MEM_BU(ctx->r16, -0X2538);
    // 0x800AFEC0: jal         0x80079F50
    // 0x800AFEC4: nop

    getControllerNewButtonsPressed(rdram, ctx);
        goto after_36;
    // 0x800AFEC4: nop

    after_36:
    // 0x800AFEC8: andi        $v0, $v0, 0x9000
    ctx->r2 = ctx->r2 & 0X9000;
    // 0x800AFECC: beq         $v0, $zero, L_800B0088
    if (ctx->r2 == 0) {
        // 0x800AFED0: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800B0088;
    }
    // 0x800AFED0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFED4: lw          $a0, -0x2058($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X2058);
    // 0x800AFED8: jal         0x80063EE4
    // 0x800AFEDC: nop

    func_80063EE4(rdram, ctx);
        goto after_37;
    // 0x800AFEDC: nop

    after_37:
    // 0x800AFEE0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800AFEE4: bne         $v0, $zero, L_800B0088
    if (ctx->r2 != 0) {
        // 0x800AFEE8: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800B0088;
    }
    // 0x800AFEE8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFEEC: lbu         $v0, -0x253B($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X253B);
    // 0x800AFEF0: bne         $v0, $zero, L_800B0088
    if (ctx->r2 != 0) {
        // 0x800AFEF4: lui         $s2, 0x800D
        ctx->r18 = S32(0X800D << 16);
            goto L_800B0088;
    }
    // 0x800AFEF4: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x800AFEF8: lbu         $v0, -0x2545($s2)
    ctx->r2 = MEM_BU(ctx->r18, -0X2545);
    // 0x800AFEFC: beq         $v0, $zero, L_800AFF3C
    if (ctx->r2 == 0) {
        // 0x800AFF00: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800AFF3C;
    }
    // 0x800AFF00: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFF04: lw          $a0, -0x2054($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X2054);
    // 0x800AFF08: jal         0x80063F7C
    // 0x800AFF0C: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    func_80063F7C(rdram, ctx);
        goto after_38;
    // 0x800AFF0C: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    after_38:
    // 0x800AFF10: lw          $a0, -0x3900($s1)
    ctx->r4 = MEM_W(ctx->r17, -0X3900);
    // 0x800AFF14: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x800AFF18: beq         $a0, $s0, L_800AFF30
    if (ctx->r4 == ctx->r16) {
        // 0x800AFF1C: lui         $v1, 0x800D
        ctx->r3 = S32(0X800D << 16);
            goto L_800AFF30;
    }
    // 0x800AFF1C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AFF20: jal         0x800894F0
    // 0x800AFF24: nop

    func_800894F0(rdram, ctx);
        goto after_39;
    // 0x800AFF24: nop

    after_39:
    // 0x800AFF28: sw          $s0, -0x3900($s1)
    MEM_W(-0X3900, ctx->r17) = ctx->r16;
    // 0x800AFF2C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
L_800AFF30:
    // 0x800AFF30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AFF34: sb          $zero, -0x2545($s2)
    MEM_B(-0X2545, ctx->r18) = 0;
    // 0x800AFF38: sb          $v0, -0x2544($v1)
    MEM_B(-0X2544, ctx->r3) = ctx->r2;
L_800AFF3C:
    // 0x800AFF3C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x800AFF40: addiu       $a1, $zero, 0x5F
    ctx->r5 = ADD32(0, 0X5F);
    // 0x800AFF44: jal         0x80087EE8
    // 0x800AFF48: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80087EE8(rdram, ctx);
        goto after_40;
    // 0x800AFF48: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_40:
    // 0x800AFF4C: jal         0x8005589C
    // 0x800AFF50: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    getGameOrFrontText(rdram, ctx);
        goto after_41;
    // 0x800AFF50: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    after_41:
    // 0x800AFF54: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AFF58: lw          $a0, -0x2058($v1)
    ctx->r4 = MEM_W(ctx->r3, -0X2058);
    // 0x800AFF5C: jal         0x80062854
    // 0x800AFF60: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_80062854(rdram, ctx);
        goto after_42;
    // 0x800AFF60: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_42:
    // 0x800AFF64: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFF68: lbu         $a0, -0x253F($v0)
    ctx->r4 = MEM_BU(ctx->r2, -0X253F);
    // 0x800AFF6C: jal         0x800B19EC
    // 0x800AFF70: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_800B19EC(rdram, ctx);
        goto after_43;
    // 0x800AFF70: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_43:
    // 0x800AFF74: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AFF78: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800AFF7C: sb          $v0, -0x253C($v1)
    MEM_B(-0X253C, ctx->r3) = ctx->r2;
    // 0x800AFF80: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AFF84: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AFF88: lwc1        $f0, 0x5984($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5984);
    // 0x800AFF8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AFF90: sb          $v0, -0x2539($v1)
    MEM_B(-0X2539, ctx->r3) = ctx->r2;
    // 0x800AFF94: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
L_800AFF98:
    // 0x800AFF98: j           L_800B0088
    // 0x800AFF9C: swc1        $f0, -0x1958($v0)
    MEM_W(-0X1958, ctx->r2) = ctx->f0.u32l;
        goto L_800B0088;
    // 0x800AFF9C: swc1        $f0, -0x1958($v0)
    MEM_W(-0X1958, ctx->r2) = ctx->f0.u32l;
L_800AFFA0:
    // 0x800AFFA0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFFA4: lbu         $a0, -0x2538($v0)
    ctx->r4 = MEM_BU(ctx->r2, -0X2538);
    // 0x800AFFA8: jal         0x80079F50
    // 0x800AFFAC: nop

    getControllerNewButtonsPressed(rdram, ctx);
        goto after_44;
    // 0x800AFFAC: nop

    after_44:
    // 0x800AFFB0: andi        $v0, $v0, 0x9000
    ctx->r2 = ctx->r2 & 0X9000;
    // 0x800AFFB4: beq         $v0, $zero, L_800B0088
    if (ctx->r2 == 0) {
        // 0x800AFFB8: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800B0088;
    }
    // 0x800AFFB8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFFBC: lw          $a0, -0x2058($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X2058);
    // 0x800AFFC0: jal         0x80063EE4
    // 0x800AFFC4: nop

    func_80063EE4(rdram, ctx);
        goto after_45;
    // 0x800AFFC4: nop

    after_45:
    // 0x800AFFC8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800AFFCC: bne         $v0, $zero, L_800B0088
    if (ctx->r2 != 0) {
        // 0x800AFFD0: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800B0088;
    }
    // 0x800AFFD0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFFD4: lbu         $v0, -0x2547($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2547);
    // 0x800AFFD8: bne         $v0, $zero, L_800B0088
    if (ctx->r2 != 0) {
        // 0x800AFFDC: lui         $s2, 0x800D
        ctx->r18 = S32(0X800D << 16);
            goto L_800B0088;
    }
    // 0x800AFFDC: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x800AFFE0: lbu         $v0, -0x2545($s2)
    ctx->r2 = MEM_BU(ctx->r18, -0X2545);
    // 0x800AFFE4: beq         $v0, $zero, L_800B0024
    if (ctx->r2 == 0) {
        // 0x800AFFE8: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800B0024;
    }
    // 0x800AFFE8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AFFEC: lw          $a0, -0x2054($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X2054);
    // 0x800AFFF0: jal         0x80063F7C
    // 0x800AFFF4: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    func_80063F7C(rdram, ctx);
        goto after_46;
    // 0x800AFFF4: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    after_46:
    // 0x800AFFF8: lw          $a0, -0x3900($s1)
    ctx->r4 = MEM_W(ctx->r17, -0X3900);
    // 0x800AFFFC: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x800B0000: beq         $a0, $s0, L_800B0018
    if (ctx->r4 == ctx->r16) {
        // 0x800B0004: lui         $v1, 0x800D
        ctx->r3 = S32(0X800D << 16);
            goto L_800B0018;
    }
    // 0x800B0004: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800B0008: jal         0x800894F0
    // 0x800B000C: nop

    func_800894F0(rdram, ctx);
        goto after_47;
    // 0x800B000C: nop

    after_47:
    // 0x800B0010: sw          $s0, -0x3900($s1)
    MEM_W(-0X3900, ctx->r17) = ctx->r16;
    // 0x800B0014: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
L_800B0018:
    // 0x800B0018: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B001C: sb          $zero, -0x2545($s2)
    MEM_B(-0X2545, ctx->r18) = 0;
    // 0x800B0020: sb          $v0, -0x2544($v1)
    MEM_B(-0X2544, ctx->r3) = ctx->r2;
L_800B0024:
    // 0x800B0024: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x800B0028: addiu       $a1, $zero, 0x5F
    ctx->r5 = ADD32(0, 0X5F);
    // 0x800B002C: jal         0x80087EE8
    // 0x800B0030: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80087EE8(rdram, ctx);
        goto after_48;
    // 0x800B0030: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_48:
    // 0x800B0034: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B0038: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    // 0x800B003C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0040: lw          $a2, -0x2320($v0)
    ctx->r6 = MEM_W(ctx->r2, -0X2320);
    // 0x800B0044: jal         0x800964C8
    // 0x800B0048: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800964C8(rdram, ctx);
        goto after_49;
    // 0x800B0048: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_49:
    // 0x800B004C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B0050: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    // 0x800B0054: jal         0x8008E0B0
    // 0x800B0058: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    func_8008E0B0(rdram, ctx);
        goto after_50;
    // 0x800B0058: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    after_50:
    // 0x800B005C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0060: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800B0064: sb          $v1, -0x2547($v0)
    MEM_B(-0X2547, ctx->r2) = ctx->r3;
    // 0x800B0068: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B006C: sb          $v1, -0x2546($v0)
    MEM_B(-0X2546, ctx->r2) = ctx->r3;
    // 0x800B0070: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800B0074: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800B0078: sb          $v0, -0x253E($v1)
    MEM_B(-0X253E, ctx->r3) = ctx->r2;
    // 0x800B007C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800B0080: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800B0084: sb          $v0, -0x253C($v1)
    MEM_B(-0X253C, ctx->r3) = ctx->r2;
L_800B0088:
    // 0x800B0088: jal         0x8001CA50
    // 0x800B008C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CA50(rdram, ctx);
        goto after_51;
    // 0x800B008C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_51:
    // 0x800B0090: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0094: lw          $a1, -0x2524($v0)
    ctx->r5 = MEM_W(ctx->r2, -0X2524);
    // 0x800B0098: jal         0x8001CB9C
    // 0x800B009C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CB9C(rdram, ctx);
        goto after_52;
    // 0x800B009C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_52:
    // 0x800B00A0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B00A4: lwc1        $f0, -0x24EC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X24EC);
    // 0x800B00A8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B00AC: lwc1        $f12, 0x5988($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5988);
    // 0x800B00B0: jal         0x80033960
    // 0x800B00B4: div.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    sinf_recomp(rdram, ctx);
        goto after_53;
    // 0x800B00B4: div.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    after_53:
    // 0x800B00B8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B00BC: lwc1        $f2, -0x2514($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X2514);
    // 0x800B00C0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B00C4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B00C8: lwc1        $f2, 0x598C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X598C);
    // 0x800B00CC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B00D0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B00D4: lwc1        $f2, -0x2528($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X2528);
    // 0x800B00D8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800B00DC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B00E0: lwc1        $f0, 0x5990($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5990);
    // 0x800B00E4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800B00E8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800B00EC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B00F0: lw          $a2, -0x252C($v0)
    ctx->r6 = MEM_W(ctx->r2, -0X252C);
    // 0x800B00F4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800B00F8: jal         0x8001CA90
    // 0x800B00FC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8001CA90(rdram, ctx);
        goto after_54;
    // 0x800B00FC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_54:
    // 0x800B0100: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0104: lw          $a1, -0x2520($v0)
    ctx->r5 = MEM_W(ctx->r2, -0X2520);
    // 0x800B0108: jal         0x8001CCCC
    // 0x800B010C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CCCC(rdram, ctx);
        goto after_55;
    // 0x800B010C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_55:
    // 0x800B0110: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800B0114: addiu       $a0, $a0, -0x2354
    ctx->r4 = ADD32(ctx->r4, -0X2354);
    // 0x800B0118: jal         0x8001C774
    // 0x800B011C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8001C774(rdram, ctx);
        goto after_56;
    // 0x800B011C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_56:
    // 0x800B0120: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800B0124: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800B0128: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800B012C: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800B0130: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800B0134: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800B0138: ldc1        $f22, 0x68($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X68);
    // 0x800B013C: ldc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X60);
    // 0x800B0140: jr          $ra
    // 0x800B0144: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800B0144: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_800AFCF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AFCF4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800AFCF8: lw          $v0, 0x75D8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X75D8);
    // 0x800AFCFC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800AFD00: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800AFD04: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800AFD08: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800AFD0C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800AFD10: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800AFD14: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800AFD18: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800AFD1C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800AFD20: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800AFD24: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800AFD28: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x800AFD2C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800AFD30: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AFD34: lwc1        $f20, 0x5588($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5588);
    // 0x800AFD38: beq         $v0, $zero, L_800AFE1C
    if (ctx->r2 == 0) {
        // 0x800AFD3C: addu        $s2, $s1, $zero
        ctx->r18 = ADD32(ctx->r17, 0);
            goto L_800AFE1C;
    }
    // 0x800AFD3C: addu        $s2, $s1, $zero
    ctx->r18 = ADD32(ctx->r17, 0);
    // 0x800AFD40: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x800AFD44: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800AFD48: addiu       $s5, $v0, -0x7760
    ctx->r21 = ADD32(ctx->r2, -0X7760);
    // 0x800AFD4C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800AFD50: addiu       $s4, $v0, -0x7FA0
    ctx->r20 = ADD32(ctx->r2, -0X7FA0);
L_800AFD54:
    // 0x800AFD54: lw          $v0, 0x75D8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X75D8);
    // 0x800AFD58: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x800AFD5C: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x800AFD60: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800AFD64: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x800AFD68: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x800AFD6C: bnel        $v0, $s6, L_800AFE04
    if (ctx->r2 != ctx->r22) {
        // 0x800AFD70: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800AFE04;
    }
    goto skip_0;
    // 0x800AFD70: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    skip_0:
    // 0x800AFD74: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x800AFD78: beq         $v0, $zero, L_800AFD8C
    if (ctx->r2 == 0) {
        // 0x800AFD7C: addu        $v0, $v0, $s5
        ctx->r2 = ADD32(ctx->r2, ctx->r21);
            goto L_800AFD8C;
    }
    // 0x800AFD7C: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x800AFD80: lbu         $v0, -0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X1);
    // 0x800AFD84: beq         $v0, $zero, L_800AFE04
    if (ctx->r2 == 0) {
        // 0x800AFD88: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800AFE04;
    }
    // 0x800AFD88: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
L_800AFD8C:
    // 0x800AFD8C: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x800AFD90: beq         $v0, $zero, L_800AFDB4
    if (ctx->r2 == 0) {
        // 0x800AFD94: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800AFDB4;
    }
    // 0x800AFD94: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800AFD98: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800AFD9C: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x800AFDA0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800AFDA4: lw          $v1, 0x68($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X68);
    // 0x800AFDA8: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800AFDAC: bne         $v0, $zero, L_800AFE04
    if (ctx->r2 != 0) {
        // 0x800AFDB0: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800AFE04;
    }
    // 0x800AFDB0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
L_800AFDB4:
    // 0x800AFDB4: lwc1        $f0, 0x0($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X0);
    // 0x800AFDB8: lwc1        $f2, 0x10($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AFDBC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800AFDC0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800AFDC4: lwc1        $f0, 0x4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X4);
    // 0x800AFDC8: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800AFDCC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800AFDD0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800AFDD4: lwc1        $f0, 0x8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800AFDD8: lwc1        $f2, 0x18($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800AFDDC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800AFDE0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800AFDE4: jal         0x8001CF2C
    // 0x800AFDE8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8001CF2C(rdram, ctx);
        goto after_0;
    // 0x800AFDE8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800AFDEC: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800AFDF0: nop

    // 0x800AFDF4: bc1f        L_800AFE04
    if (!c1cs) {
        // 0x800AFDF8: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800AFE04;
    }
    // 0x800AFDF8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800AFDFC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800AFE00: addu        $s2, $s0, $zero
    ctx->r18 = ADD32(ctx->r16, 0);
L_800AFE04:
    // 0x800AFE04: lw          $v0, 0x75D8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X75D8);
    // 0x800AFE08: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800AFE0C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AFE10: sltu        $v0, $s1, $v0
    ctx->r2 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x800AFE14: bne         $v0, $zero, L_800AFD54
    if (ctx->r2 != 0) {
        // 0x800AFE18: nop
    
            goto L_800AFD54;
    }
    // 0x800AFE18: nop

L_800AFE1C:
    // 0x800AFE1C: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x800AFE20: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800AFE24: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800AFE28: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800AFE2C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800AFE30: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800AFE34: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800AFE38: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800AFE3C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800AFE40: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x800AFE44: jr          $ra
    // 0x800AFE48: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800AFE48: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
