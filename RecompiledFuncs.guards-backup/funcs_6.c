#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8001D678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D678: addu        $t2, $a0, $zero
    ctx->r10 = ADD32(ctx->r4, 0);
    // 0x8001D67C: lwc1        $f6, 0x0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8001D680: lwc1        $f2, 0x10($t2)
    ctx->f2.u32l = MEM_W(ctx->r10, 0X10);
    // 0x8001D684: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8001D688: lwc1        $f8, 0x20($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X20);
    // 0x8001D68C: add.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8001D690: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001D694: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8001D698: nop

    // 0x8001D69C: bc1f        L_8001D708
    if (!c1cs) {
        // 0x8001D6A0: addu        $t3, $a1, $zero
        ctx->r11 = ADD32(ctx->r5, 0);
            goto L_8001D708;
    }
    // 0x8001D6A0: addu        $t3, $a1, $zero
    ctx->r11 = ADD32(ctx->r5, 0);
    // 0x8001D6A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D6A8: lwc1        $f0, 0x8FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X8FC);
    // 0x8001D6AC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D6B0: lwc1        $f2, 0x900($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X900);
    // 0x8001D6B4: add.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8001D6B8: sqrt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = sqrtf(ctx->f0.fl);
    // 0x8001D6BC: mul.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8001D6C0: div.s       $f6, $f2, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8001D6C4: swc1        $f0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f0.u32l;
    // 0x8001D6C8: lwc1        $f0, 0x1C($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x8001D6CC: lwc1        $f2, 0x14($t2)
    ctx->f2.u32l = MEM_W(ctx->r10, 0X14);
    // 0x8001D6D0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8001D6D4: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8001D6D8: swc1        $f0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f0.u32l;
    // 0x8001D6DC: lwc1        $f0, 0x8($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X8);
    // 0x8001D6E0: lwc1        $f2, 0x18($t2)
    ctx->f2.u32l = MEM_W(ctx->r10, 0X18);
    // 0x8001D6E4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8001D6E8: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8001D6EC: swc1        $f0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f0.u32l;
    // 0x8001D6F0: lwc1        $f0, 0xC($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8001D6F4: lwc1        $f2, 0x4($t2)
    ctx->f2.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8001D6F8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8001D6FC: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8001D700: j           L_8001D848
    // 0x8001D704: swc1        $f0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f0.u32l;
        goto L_8001D848;
    // 0x8001D704: swc1        $f0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f0.u32l;
L_8001D708:
    // 0x8001D708: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8001D70C: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x8001D710: bc1f        L_8001D71C
    if (!c1cs) {
        // 0x8001D714: addiu       $t4, $t3, 0x4
        ctx->r12 = ADD32(ctx->r11, 0X4);
            goto L_8001D71C;
    }
    // 0x8001D714: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x8001D718: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8001D71C:
    // 0x8001D71C: andi        $v0, $t1, 0xFF
    ctx->r2 = ctx->r9 & 0XFF;
    // 0x8001D720: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8001D724: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001D728: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8001D72C: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x8001D730: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001D734: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001D738: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001D73C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8001D740: nop

    // 0x8001D744: bc1tl       L_8001D74C
    if (c1cs) {
        // 0x8001D748: addiu       $t1, $zero, 0x2
        ctx->r9 = ADD32(0, 0X2);
            goto L_8001D74C;
    }
    goto skip_0;
    // 0x8001D748: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    skip_0:
L_8001D74C:
    // 0x8001D74C: andi        $t1, $t1, 0xFF
    ctx->r9 = ctx->r9 & 0XFF;
    // 0x8001D750: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001D754: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8001D758: lbu         $a2, 0x7840($at)
    ctx->r6 = MEM_BU(ctx->r1, 0X7840);
    // 0x8001D75C: sll         $a3, $t1, 1
    ctx->r7 = S32(ctx->r9 << 1);
    // 0x8001D760: addu        $a3, $a3, $t1
    ctx->r7 = ADD32(ctx->r7, ctx->r9);
    // 0x8001D764: sll         $a3, $a3, 2
    ctx->r7 = S32(ctx->r7 << 2);
    // 0x8001D768: addu        $a3, $a3, $t2
    ctx->r7 = ADD32(ctx->r7, ctx->r10);
    // 0x8001D76C: sll         $a0, $a2, 1
    ctx->r4 = S32(ctx->r6 << 1);
    // 0x8001D770: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8001D774: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8001D778: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x8001D77C: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001D780: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x8001D784: lbu         $t0, 0x7840($at)
    ctx->r8 = MEM_BU(ctx->r1, 0X7840);
    // 0x8001D788: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x8001D78C: addu        $v1, $a2, $a0
    ctx->r3 = ADD32(ctx->r6, ctx->r4);
    // 0x8001D790: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8001D794: sll         $a1, $t0, 1
    ctx->r5 = S32(ctx->r8 << 1);
    // 0x8001D798: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x8001D79C: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x8001D7A0: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    // 0x8001D7A4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8001D7A8: addu        $v0, $t0, $a1
    ctx->r2 = ADD32(ctx->r8, ctx->r5);
    // 0x8001D7AC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001D7B0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8001D7B4: addu        $v0, $t1, $a3
    ctx->r2 = ADD32(ctx->r9, ctx->r7);
    // 0x8001D7B8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8001D7BC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001D7C0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8001D7C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D7C8: lwc1        $f2, 0x904($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X904);
    // 0x8001D7CC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D7D0: lwc1        $f4, 0x908($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X908);
    // 0x8001D7D4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8001D7D8: sqrt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = sqrtf(ctx->f0.fl);
    // 0x8001D7DC: mul.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8001D7E0: div.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001D7E4: addu        $v1, $t0, $a0
    ctx->r3 = ADD32(ctx->r8, ctx->r4);
    // 0x8001D7E8: addu        $v0, $t1, $t4
    ctx->r2 = ADD32(ctx->r9, ctx->r12);
    // 0x8001D7EC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8001D7F0: addu        $v0, $a2, $a1
    ctx->r2 = ADD32(ctx->r6, ctx->r5);
    // 0x8001D7F4: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001D7F8: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8001D7FC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8001D800: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8001D804: addu        $a0, $t1, $a0
    ctx->r4 = ADD32(ctx->r9, ctx->r4);
    // 0x8001D808: addu        $v0, $a2, $a3
    ctx->r2 = ADD32(ctx->r6, ctx->r7);
    // 0x8001D80C: swc1        $f0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f0.u32l;
    // 0x8001D810: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8001D814: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001D818: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8001D81C: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8001D820: addu        $t1, $t1, $a1
    ctx->r9 = ADD32(ctx->r9, ctx->r5);
    // 0x8001D824: addu        $a2, $a2, $t4
    ctx->r6 = ADD32(ctx->r6, ctx->r12);
    // 0x8001D828: addu        $a3, $t0, $a3
    ctx->r7 = ADD32(ctx->r8, ctx->r7);
    // 0x8001D82C: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x8001D830: lwc1        $f0, 0x0($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8001D834: lwc1        $f2, 0x0($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8001D838: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8001D83C: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8001D840: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x8001D844: swc1        $f0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f0.u32l;
L_8001D848:
    // 0x8001D848: jr          $ra
    // 0x8001D84C: nop

    return;
    // 0x8001D84C: nop

;}
RECOMP_FUNC void func_8001D850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D850: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8001D854: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001D858: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001D85C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8001D860: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8001D864: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001D868: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8001D86C: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8001D870: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8001D874: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8001D878: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8001D87C: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8001D880: lwc1        $f0, 0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8001D884: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001D888: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8001D88C: lwc1        $f4, 0x8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8001D890: mul.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8001D894: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8001D898: lwc1        $f0, 0xC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8001D89C: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001D8A0: lwc1        $f8, 0x0($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8001D8A4: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8001D8A8: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8001D8AC: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8001D8B0: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x8001D8B4: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8001D8B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D8BC: ldc1        $f4, 0x910($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X910);
    // 0x8001D8C0: cvt.d.s     $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f20.d = CVT_D_S(ctx->f2.fl);
    // 0x8001D8C4: add.d       $f0, $f20, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f20.d + ctx->f4.d;
    // 0x8001D8C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D8CC: ldc1        $f2, 0x918($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X918);
    // 0x8001D8D0: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x8001D8D4: mtc1        $a2, $f26
    ctx->f26.u32l = ctx->r6;
    // 0x8001D8D8: bc1f        L_8001DA04
    if (!c1cs) {
        // 0x8001D8DC: addu        $s1, $a3, $zero
        ctx->r17 = ADD32(ctx->r7, 0);
            goto L_8001DA04;
    }
    // 0x8001D8DC: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // 0x8001D8E0: sub.d       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f0.d = ctx->f4.d - ctx->f20.d;
    // 0x8001D8E4: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x8001D8E8: nop

    // 0x8001D8EC: bc1fl       L_8001D960
    if (!c1cs) {
        // 0x8001D8F0: cvt.d.s     $f12, $f26
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f12.d = CVT_D_S(ctx->f26.fl);
            goto L_8001D960;
    }
    goto skip_0;
    // 0x8001D8F0: cvt.d.s     $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f12.d = CVT_D_S(ctx->f26.fl);
    skip_0:
    // 0x8001D8F4: jal         0x8001C400
    // 0x8001D8F8: cvt.s.d     $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); 
    ctx->f12.fl = CVT_S_D(ctx->f20.d);
    func_8001C400(rdram, ctx);
        goto after_0;
    // 0x8001D8F8: cvt.s.d     $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); 
    ctx->f12.fl = CVT_S_D(ctx->f20.d);
    after_0:
    // 0x8001D8FC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D900: lwc1        $f22, 0x920($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X920);
    // 0x8001D904: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D908: lwc1        $f2, 0x924($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X924);
    // 0x8001D90C: sub.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f0.fl;
    // 0x8001D910: mul.d       $f0, $f20, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f20.d); 
    ctx->f0.d = MUL_D(ctx->f20.d, ctx->f20.d);
    // 0x8001D914: sub.s       $f12, $f2, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f26.fl;
    // 0x8001D918: cvt.d.s     $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f22.d = CVT_D_S(ctx->f22.fl);
    // 0x8001D91C: cvt.d.s     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.d = CVT_D_S(ctx->f12.fl);
    // 0x8001D920: mul.d       $f12, $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f22.d); 
    ctx->f12.d = MUL_D(ctx->f12.d, ctx->f22.d);
    // 0x8001D924: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001D928: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8001D92C: sqrt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = sqrtf(ctx->f2.fl);
    // 0x8001D930: cvt.d.s     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.d = CVT_D_S(ctx->f20.fl);
    // 0x8001D934: jal         0x80033960
    // 0x8001D938: cvt.s.d     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f12.fl = CVT_S_D(ctx->f12.d);
    sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001D938: cvt.s.d     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f12.fl = CVT_S_D(ctx->f12.d);
    after_1:
    // 0x8001D93C: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001D940: div.d       $f24, $f0, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f20.d); 
    ctx->f24.d = DIV_D(ctx->f0.d, ctx->f20.d);
    // 0x8001D944: cvt.d.s     $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f12.d = CVT_D_S(ctx->f26.fl);
    // 0x8001D948: mul.d       $f12, $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f22.d); 
    ctx->f12.d = MUL_D(ctx->f12.d, ctx->f22.d);
    // 0x8001D94C: jal         0x80033960
    // 0x8001D950: cvt.s.d     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f12.fl = CVT_S_D(ctx->f12.d);
    sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x8001D950: cvt.s.d     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f12.fl = CVT_S_D(ctx->f12.d);
    after_2:
    // 0x8001D954: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001D958: j           L_8001D970
    // 0x8001D95C: div.d       $f12, $f0, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f20.d); 
    ctx->f12.d = DIV_D(ctx->f0.d, ctx->f20.d);
        goto L_8001D970;
    // 0x8001D95C: div.d       $f12, $f0, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f20.d); 
    ctx->f12.d = DIV_D(ctx->f0.d, ctx->f20.d);
L_8001D960:
    // 0x8001D960: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D964: lwc1        $f0, 0x928($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X928);
    // 0x8001D968: sub.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f26.fl;
    // 0x8001D96C: cvt.d.s     $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f24.d = CVT_D_S(ctx->f0.fl);
L_8001D970:
    // 0x8001D970: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8001D974: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8001D978: mul.d       $f2, $f24, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = MUL_D(ctx->f24.d, ctx->f2.d);
    // 0x8001D97C: lwc1        $f0, 0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8001D980: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001D984: mul.d       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = MUL_D(ctx->f12.d, ctx->f0.d);
    // 0x8001D988: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
    // 0x8001D98C: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x8001D990: swc1        $f2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f2.u32l;
    // 0x8001D994: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8001D998: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8001D99C: mul.d       $f2, $f24, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = MUL_D(ctx->f24.d, ctx->f2.d);
    // 0x8001D9A0: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8001D9A4: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001D9A8: mul.d       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = MUL_D(ctx->f12.d, ctx->f0.d);
    // 0x8001D9AC: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
    // 0x8001D9B0: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x8001D9B4: swc1        $f2, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f2.u32l;
    // 0x8001D9B8: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8001D9BC: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8001D9C0: mul.d       $f2, $f24, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = MUL_D(ctx->f24.d, ctx->f2.d);
    // 0x8001D9C4: lwc1        $f0, 0xC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8001D9C8: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001D9CC: mul.d       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = MUL_D(ctx->f12.d, ctx->f0.d);
    // 0x8001D9D0: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
    // 0x8001D9D4: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x8001D9D8: swc1        $f2, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f2.u32l;
    // 0x8001D9DC: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8001D9E0: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8001D9E4: mul.d       $f2, $f24, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = MUL_D(ctx->f24.d, ctx->f2.d);
    // 0x8001D9E8: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8001D9EC: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001D9F0: mul.d       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = MUL_D(ctx->f12.d, ctx->f0.d);
    // 0x8001D9F4: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
    // 0x8001D9F8: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x8001D9FC: j           L_8001DAC0
    // 0x8001DA00: swc1        $f2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f2.u32l;
        goto L_8001DAC0;
    // 0x8001DA00: swc1        $f2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f2.u32l;
L_8001DA04:
    // 0x8001DA04: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001DA08: lwc1        $f12, 0x92C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X92C);
    // 0x8001DA0C: neg.s       $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = -ctx->f10.fl;
    // 0x8001DA10: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x8001DA14: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8001DA18: sub.s       $f12, $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f26.fl;
    // 0x8001DA1C: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x8001DA20: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8001DA24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001DA28: lwc1        $f20, 0x930($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X930);
    // 0x8001DA2C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8001DA30: mul.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x8001DA34: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    // 0x8001DA38: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8001DA3C: jal         0x80033960
    // 0x8001DA40: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x8001DA40: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    after_3:
    // 0x8001DA44: mul.s       $f12, $f26, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f26.fl, ctx->f20.fl);
    // 0x8001DA48: jal         0x80033960
    // 0x8001DA4C: cvt.d.s     $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f24.d = CVT_D_S(ctx->f0.fl);
    sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x8001DA4C: cvt.d.s     $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f24.d = CVT_D_S(ctx->f0.fl);
    after_4:
    // 0x8001DA50: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8001DA54: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8001DA58: mul.d       $f2, $f24, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = MUL_D(ctx->f24.d, ctx->f2.d);
    // 0x8001DA5C: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8001DA60: cvt.d.s     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.d = CVT_D_S(ctx->f0.fl);
    // 0x8001DA64: cvt.d.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f4.d = CVT_D_S(ctx->f4.fl);
    // 0x8001DA68: mul.d       $f4, $f12, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f4.d); 
    ctx->f4.d = MUL_D(ctx->f12.d, ctx->f4.d);
    // 0x8001DA6C: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8001DA70: add.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d + ctx->f4.d;
    // 0x8001DA74: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001DA78: mul.d       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = MUL_D(ctx->f12.d, ctx->f0.d);
    // 0x8001DA7C: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x8001DA80: swc1        $f2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f2.u32l;
    // 0x8001DA84: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8001DA88: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8001DA8C: mul.d       $f2, $f24, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = MUL_D(ctx->f24.d, ctx->f2.d);
    // 0x8001DA90: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
    // 0x8001DA94: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8001DA98: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001DA9C: mul.d       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = MUL_D(ctx->f12.d, ctx->f0.d);
    // 0x8001DAA0: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x8001DAA4: swc1        $f2, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f2.u32l;
    // 0x8001DAA8: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8001DAAC: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8001DAB0: mul.d       $f2, $f24, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = MUL_D(ctx->f24.d, ctx->f2.d);
    // 0x8001DAB4: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
    // 0x8001DAB8: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x8001DABC: swc1        $f2, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f2.u32l;
L_8001DAC0:
    // 0x8001DAC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001DAC4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8001DAC8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8001DACC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001DAD0: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8001DAD4: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8001DAD8: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8001DADC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8001DAE0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8001DAE4: jr          $ra
    // 0x8001DAE8: nop

    return;
    // 0x8001DAE8: nop

;}
RECOMP_FUNC void func_8001DAEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DAEC: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8001DAF0: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x8001DAF4: sdc1        $f28, 0x68($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X68, ctx->r29);
    // 0x8001DAF8: sdc1        $f26, 0x60($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X60, ctx->r29);
    // 0x8001DAFC: sdc1        $f24, 0x58($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X58, ctx->r29);
    // 0x8001DB00: sdc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X50, ctx->r29);
    // 0x8001DB04: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x8001DB08: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001DB0C: mul.s       $f0, $f8, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8001DB10: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8001DB14: mul.s       $f2, $f10, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8001DB18: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8001DB1C: mul.s       $f12, $f6, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8001DB20: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001DB24: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8001DB28: mul.s       $f2, $f4, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8001DB2C: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8001DB30: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8001DB34: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001DB38: lwc1        $f2, 0x934($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X934);
    // 0x8001DB3C: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001DB40: mul.s       $f20, $f8, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8001DB44: nop

    // 0x8001DB48: mul.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8001DB4C: nop

    // 0x8001DB50: mul.s       $f2, $f6, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8001DB54: nop

    // 0x8001DB58: mul.s       $f22, $f4, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001DB5C: nop

    // 0x8001DB60: mul.s       $f18, $f4, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8001DB64: nop

    // 0x8001DB68: mul.s       $f28, $f10, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f28.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8001DB6C: nop

    // 0x8001DB70: mul.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8001DB74: nop

    // 0x8001DB78: mul.s       $f0, $f8, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001DB7C: nop

    // 0x8001DB80: mul.s       $f14, $f8, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8001DB84: nop

    // 0x8001DB88: mul.s       $f8, $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8001DB8C: add.s       $f16, $f28, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f28.fl + ctx->f6.fl;
    // 0x8001DB90: add.s       $f24, $f0, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x8001DB94: mul.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8001DB98: sub.s       $f26, $f14, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f26.fl = ctx->f14.fl - ctx->f22.fl;
    // 0x8001DB9C: sub.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8001DBA0: mul.s       $f10, $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8001DBA4: add.s       $f6, $f8, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8001DBA8: add.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8001DBAC: add.s       $f14, $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f22.fl;
    // 0x8001DBB0: sub.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8001DBB4: add.s       $f8, $f8, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f28.fl;
    // 0x8001DBB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001DBBC: lwc1        $f12, 0x938($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X938);
    // 0x8001DBC0: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x8001DBC4: sub.s       $f16, $f12, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x8001DBC8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8001DBCC: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8001DBD0: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8001DBD4: sub.s       $f6, $f12, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x8001DBD8: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8001DBDC: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8001DBE0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8001DBE4: sub.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x8001DBE8: swc1        $f24, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f24.u32l;
    // 0x8001DBEC: swc1        $f26, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f26.u32l;
    // 0x8001DBF0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8001DBF4: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x8001DBF8: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x8001DBFC: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8001DC00: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8001DC04: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8001DC08: jal         0x800191C4
    // 0x8001DC0C: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    func_800191C4(rdram, ctx);
        goto after_0;
    // 0x8001DC0C: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8001DC10: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x8001DC14: ldc1        $f28, 0x68($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X68);
    // 0x8001DC18: ldc1        $f26, 0x60($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X60);
    // 0x8001DC1C: ldc1        $f24, 0x58($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X58);
    // 0x8001DC20: ldc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X50);
    // 0x8001DC24: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x8001DC28: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x8001DC2C: jr          $ra
    // 0x8001DC30: nop

    return;
    // 0x8001DC30: nop

;}
RECOMP_FUNC void func_8001DC34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DC34: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8001DC38: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8001DC3C: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x8001DC40: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8001DC44: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8001DC48: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8001DC4C: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x8001DC50: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // 0x8001DC54: sdc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X48, ctx->r29);
    // 0x8001DC58: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x8001DC5C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001DC60: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x8001DC64: bne         $s0, $zero, L_8001DC70
    if (ctx->r16 != 0) {
        // 0x8001DC68: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_8001DC70;
    }
    // 0x8001DC68: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8001DC6C: addiu       $v0, $s1, 0x2C
    ctx->r2 = ADD32(ctx->r17, 0X2C);
L_8001DC70:
    // 0x8001DC70: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8001DC74: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8001DC78: jal         0x800193E8
    // 0x8001DC7C: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    func_800193E8(rdram, ctx);
        goto after_0;
    // 0x8001DC7C: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x8001DC80: beq         $s2, $zero, L_8001DC90
    if (ctx->r18 == 0) {
        // 0x8001DC84: nop
    
            goto L_8001DC90;
    }
    // 0x8001DC84: nop

    // 0x8001DC88: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8001DC8C: swc1        $f0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f0.u32l;
L_8001DC90:
    // 0x8001DC90: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8001DC94: c.eq.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl == ctx->f20.fl;
    // 0x8001DC98: nop

    // 0x8001DC9C: bc1t        L_8001DFE8
    if (c1cs) {
        // 0x8001DCA0: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8001DFE8;
    }
    // 0x8001DCA0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8001DCA4: lui         $a1, 0x8003
    ctx->r5 = S32(0X8003 << 16);
    // 0x8001DCA8: addiu       $a1, $a1, 0x784C
    ctx->r5 = ADD32(ctx->r5, 0X784C);
    // 0x8001DCAC: jal         0x800194A4
    // 0x8001DCB0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_800194A4(rdram, ctx);
        goto after_1;
    // 0x8001DCB0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x8001DCB4: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8001DCB8: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001DCBC: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001DCC0: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8001DCC4: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8001DCC8: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8001DCCC: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8001DCD0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8001DCD4: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8001DCD8: mul.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8001DCDC: lwc1        $f8, 0x10($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8001DCE0: sub.s       $f0, $f8, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f22.fl;
    // 0x8001DCE4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001DCE8: lwc1        $f2, 0x93C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X93C);
    // 0x8001DCEC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8001DCF0: nop

    // 0x8001DCF4: bc1t        L_8001E1E8
    if (c1cs) {
        // 0x8001DCF8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8001E1E8;
    }
    // 0x8001DCF8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8001DCFC: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8001DD00: sub.s       $f0, $f6, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f22.fl;
    // 0x8001DD04: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8001DD08: nop

    // 0x8001DD0C: bc1t        L_8001E1E8
    if (c1cs) {
        // 0x8001DD10: nop
    
            goto L_8001E1E8;
    }
    // 0x8001DD10: nop

    // 0x8001DD14: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8001DD18: sub.s       $f0, $f4, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x8001DD1C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8001DD20: nop

    // 0x8001DD24: bc1t        L_8001E1E8
    if (c1cs) {
        // 0x8001DD28: nop
    
            goto L_8001E1E8;
    }
    // 0x8001DD28: nop

    // 0x8001DD2C: add.s       $f0, $f8, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x8001DD30: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001DD34: lwc1        $f2, 0x940($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X940);
    // 0x8001DD38: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8001DD3C: nop

    // 0x8001DD40: bc1t        L_8001E1E8
    if (c1cs) {
        // 0x8001DD44: nop
    
            goto L_8001E1E8;
    }
    // 0x8001DD44: nop

    // 0x8001DD48: add.s       $f0, $f6, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x8001DD4C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8001DD50: nop

    // 0x8001DD54: bc1t        L_8001E1E8
    if (c1cs) {
        // 0x8001DD58: nop
    
            goto L_8001E1E8;
    }
    // 0x8001DD58: nop

    // 0x8001DD5C: add.s       $f0, $f4, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x8001DD60: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8001DD64: nop

    // 0x8001DD68: bc1t        L_8001E1E8
    if (c1cs) {
        // 0x8001DD6C: nop
    
            goto L_8001E1E8;
    }
    // 0x8001DD6C: nop

    // 0x8001DD70: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8001DD74: nop

    // 0x8001DD78: bc1f        L_8001E1E8
    if (!c1cs) {
        // 0x8001DD7C: nop
    
            goto L_8001E1E8;
    }
    // 0x8001DD7C: nop

    // 0x8001DD80: lwc1        $f0, 0x24($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8001DD84: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8001DD88: nop

    // 0x8001DD8C: bc1tl       L_8001DD94
    if (c1cs) {
        // 0x8001DD90: swc1        $f0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
            goto L_8001DD94;
    }
    goto skip_0;
    // 0x8001DD90: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    skip_0:
L_8001DD94:
    // 0x8001DD94: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8001DD98: sub.s       $f2, $f12, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f22.fl;
    // 0x8001DD9C: lwc1        $f0, 0x28($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X28);
    // 0x8001DDA0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8001DDA4: nop

    // 0x8001DDA8: bc1f        L_8001E1E8
    if (!c1cs) {
        // 0x8001DDAC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8001E1E8;
    }
    // 0x8001DDAC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8001DDB0: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x8001DDB4: addiu       $v0, $v0, 0x7844
    ctx->r2 = ADD32(ctx->r2, 0X7844);
    // 0x8001DDB8: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8001DDBC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001DDC0: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8001DDC4: nop

    // 0x8001DDC8: bc1fl       L_8001DDE0
    if (!c1cs) {
        // 0x8001DDCC: swc1        $f2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
            goto L_8001DDE0;
    }
    goto skip_1;
    // 0x8001DDCC: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    skip_1:
    // 0x8001DDD0: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001DDD4: lwc1        $f0, 0x7848($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7848);
    // 0x8001DDD8: j           L_8001DE18
    // 0x8001DDDC: div.s       $f20, $f0, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
        goto L_8001DE18;
    // 0x8001DDDC: div.s       $f20, $f0, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
L_8001DDE0:
    // 0x8001DDE0: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8001DDE4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001DDE8: lwc1        $f0, 0x944($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X944);
    // 0x8001DDEC: mul.s       $f20, $f2, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001DDF0: jal         0x8002B190
    // 0x8001DDF4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x8001DDF4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_2:
    // 0x8001DDF8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8001DDFC: jal         0x80033960
    // 0x8001DE00: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x8001DE00: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_3:
    // 0x8001DE04: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8001DE08: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8001DE0C: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001DE10: swc1        $f20, 0x7848($at)
    MEM_W(0X7848, ctx->r1) = ctx->f20.u32l;
    // 0x8001DE14: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
L_8001DE18:
    // 0x8001DE18: mul.s       $f22, $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
    // 0x8001DE1C: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8001DE20: mul.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001DE24: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001DE28: lw          $v0, -0x57BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X57BC);
    // 0x8001DE2C: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8001DE30: lwc1        $f2, 0x10($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8001DE34: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8001DE38: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8001DE3C: cvt.d.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.d = CVT_D_W(ctx->f6.u32l);
    // 0x8001DE40: mul.s       $f12, $f0, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001DE44: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8001DE48: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001DE4C: bgez        $v0, L_8001DE60
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001DE50: div.s       $f2, $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
            goto L_8001DE60;
    }
    // 0x8001DE50: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001DE54: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001DE58: ldc1        $f0, 0x948($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X948);
    // 0x8001DE5C: add.d       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f6.d + ctx->f0.d;
L_8001DE60:
    // 0x8001DE60: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001DE64: lw          $v0, -0x57C8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X57C8);
    // 0x8001DE68: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8001DE6C: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x8001DE70: bgez        $v0, L_8001DE84
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001DE74: cvt.s.d     $f6, $f6
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f6.fl = CVT_S_D(ctx->f6.d);
            goto L_8001DE84;
    }
    // 0x8001DE74: cvt.s.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f6.fl = CVT_S_D(ctx->f6.d);
    // 0x8001DE78: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001DE7C: ldc1        $f0, 0x950($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X950);
    // 0x8001DE80: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
L_8001DE84:
    // 0x8001DE84: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x8001DE88: div.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001DE8C: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001DE90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001DE94: lwc1        $f6, 0x958($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X958);
    // 0x8001DE98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001DE9C: lwc1        $f2, -0x57C0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X57C0);
    // 0x8001DEA0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001DEA4: lwc1        $f4, 0x95C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X95C);
    // 0x8001DEA8: sub.s       $f6, $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x8001DEAC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001DEB0: sub.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x8001DEB4: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x8001DEB8: sub.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8001DEBC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001DEC0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8001DEC4: nop

    // 0x8001DEC8: bc1f        L_8001DF48
    if (!c1cs) {
        // 0x8001DECC: sub.s       $f2, $f2, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f10.fl;
            goto L_8001DF48;
    }
    // 0x8001DECC: sub.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x8001DED0: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8001DED4: nop

    // 0x8001DED8: bc1f        L_8001DF10
    if (!c1cs) {
        // 0x8001DEDC: nop
    
            goto L_8001DF10;
    }
    // 0x8001DEDC: nop

    // 0x8001DEE0: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
L_8001DEE4:
    // 0x8001DEE4: nop

    // 0x8001DEE8: mul.s       $f2, $f4, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
L_8001DEEC:
    // 0x8001DEEC: nop

    // 0x8001DEF0: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8001DEF4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8001DEF8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
L_8001DEFC:
    // 0x8001DEFC: nop

    // 0x8001DF00: bc1t        L_8001E1E8
    if (c1cs) {
        // 0x8001DF04: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001E1E8;
    }
    // 0x8001DF04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001DF08: j           L_8001E1E8
    // 0x8001DF0C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8001E1E8;
    // 0x8001DF0C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8001DF10:
    // 0x8001DF10: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x8001DF14: nop

    // 0x8001DF18: bc1fl       L_8001DF34
    if (!c1cs) {
        // 0x8001DF1C: cvt.d.s     $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
            goto L_8001DF34;
    }
    goto skip_2;
    // 0x8001DF1C: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    skip_2:
    // 0x8001DF20: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001DF24: nop

    // 0x8001DF28: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8001DF2C: j           L_8001DEEC
    // 0x8001DF30: nop

        goto L_8001DEEC;
    // 0x8001DF30: nop

L_8001DF34:
    // 0x8001DF34: abs.d       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = fabs(ctx->f0.d);
    // 0x8001DF38: cvt.d.s     $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f2.d = CVT_D_S(ctx->f22.fl);
    // 0x8001DF3C: c.lt.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d < ctx->f2.d;
    // 0x8001DF40: j           L_8001DEFC
    // 0x8001DF44: nop

        goto L_8001DEFC;
    // 0x8001DF44: nop

L_8001DF48:
    // 0x8001DF48: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x8001DF4C: nop

    // 0x8001DF50: bc1f        L_8001DFA4
    if (!c1cs) {
        // 0x8001DF54: nop
    
            goto L_8001DFA4;
    }
    // 0x8001DF54: nop

    // 0x8001DF58: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8001DF5C: nop

    // 0x8001DF60: bc1f        L_8001DF74
    if (!c1cs) {
        // 0x8001DF64: nop
    
            goto L_8001DF74;
    }
    // 0x8001DF64: nop

    // 0x8001DF68: mul.s       $f0, $f2, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8001DF6C: j           L_8001DEE4
    // 0x8001DF70: nop

        goto L_8001DEE4;
    // 0x8001DF70: nop

L_8001DF74:
    // 0x8001DF74: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x8001DF78: nop

    // 0x8001DF7C: bc1f        L_8001DF98
    if (!c1cs) {
        // 0x8001DF80: nop
    
            goto L_8001DF98;
    }
    // 0x8001DF80: nop

    // 0x8001DF84: mul.s       $f0, $f2, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8001DF88: nop

    // 0x8001DF8C: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8001DF90: j           L_8001DEEC
    // 0x8001DF94: nop

        goto L_8001DEEC;
    // 0x8001DF94: nop

L_8001DF98:
    // 0x8001DF98: c.lt.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl < ctx->f22.fl;
    // 0x8001DF9C: j           L_8001DEFC
    // 0x8001DFA0: nop

        goto L_8001DEFC;
    // 0x8001DFA0: nop

L_8001DFA4:
    // 0x8001DFA4: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8001DFA8: nop

    // 0x8001DFAC: bc1f        L_8001DFCC
    if (!c1cs) {
        // 0x8001DFB0: nop
    
            goto L_8001DFCC;
    }
    // 0x8001DFB0: nop

    // 0x8001DFB4: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8001DFB8: abs.d       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = fabs(ctx->f0.d);
    // 0x8001DFBC: cvt.d.s     $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f2.d = CVT_D_S(ctx->f22.fl);
    // 0x8001DFC0: c.lt.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d < ctx->f2.d;
    // 0x8001DFC4: j           L_8001DEFC
    // 0x8001DFC8: nop

        goto L_8001DEFC;
    // 0x8001DFC8: nop

L_8001DFCC:
    // 0x8001DFCC: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x8001DFD0: nop

    // 0x8001DFD4: bc1f        L_8001E1E8
    if (!c1cs) {
        // 0x8001DFD8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001E1E8;
    }
    // 0x8001DFD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001DFDC: c.lt.s      $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f6.fl < ctx->f22.fl;
    // 0x8001DFE0: j           L_8001DEFC
    // 0x8001DFE4: nop

        goto L_8001DEFC;
    // 0x8001DFE4: nop

L_8001DFE8:
    // 0x8001DFE8: lwc1        $f6, 0x10($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8001DFEC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001DFF0: lwc1        $f0, 0x960($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X960);
    // 0x8001DFF4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8001DFF8: nop

    // 0x8001DFFC: bc1t        L_8001E1E8
    if (c1cs) {
        // 0x8001E000: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8001E1E8;
    }
    // 0x8001E000: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8001E004: lwc1        $f4, 0x14($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8001E008: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8001E00C: nop

    // 0x8001E010: bc1t        L_8001E1E8
    if (c1cs) {
        // 0x8001E014: nop
    
            goto L_8001E1E8;
    }
    // 0x8001E014: nop

    // 0x8001E018: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8001E01C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8001E020: nop

    // 0x8001E024: bc1t        L_8001E1E8
    if (c1cs) {
        // 0x8001E028: nop
    
            goto L_8001E1E8;
    }
    // 0x8001E028: nop

    // 0x8001E02C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001E030: lwc1        $f0, 0x964($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X964);
    // 0x8001E034: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8001E038: nop

    // 0x8001E03C: bc1t        L_8001E1E8
    if (c1cs) {
        // 0x8001E040: nop
    
            goto L_8001E1E8;
    }
    // 0x8001E040: nop

    // 0x8001E044: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8001E048: nop

    // 0x8001E04C: bc1t        L_8001E1E8
    if (c1cs) {
        // 0x8001E050: nop
    
            goto L_8001E1E8;
    }
    // 0x8001E050: nop

    // 0x8001E054: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8001E058: nop

    // 0x8001E05C: bc1t        L_8001E1E8
    if (c1cs) {
        // 0x8001E060: nop
    
            goto L_8001E1E8;
    }
    // 0x8001E060: nop

    // 0x8001E064: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x8001E068: nop

    // 0x8001E06C: bc1f        L_8001E1E8
    if (!c1cs) {
        // 0x8001E070: nop
    
            goto L_8001E1E8;
    }
    // 0x8001E070: nop

    // 0x8001E074: lwc1        $f0, 0x28($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X28);
    // 0x8001E078: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8001E07C: nop

    // 0x8001E080: bc1f        L_8001E1E8
    if (!c1cs) {
        // 0x8001E084: nop
    
            goto L_8001E1E8;
    }
    // 0x8001E084: nop

    // 0x8001E088: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x8001E08C: addiu       $v0, $v0, 0x7844
    ctx->r2 = ADD32(ctx->r2, 0X7844);
    // 0x8001E090: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8001E094: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001E098: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x8001E09C: nop

    // 0x8001E0A0: bc1fl       L_8001E0B8
    if (!c1cs) {
        // 0x8001E0A4: swc1        $f4, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
            goto L_8001E0B8;
    }
    goto skip_3;
    // 0x8001E0A4: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    skip_3:
    // 0x8001E0A8: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001E0AC: lwc1        $f0, 0x7848($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7848);
    // 0x8001E0B0: j           L_8001E0F0
    // 0x8001E0B4: div.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
        goto L_8001E0F0;
    // 0x8001E0B4: div.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
L_8001E0B8:
    // 0x8001E0B8: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8001E0BC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001E0C0: lwc1        $f0, 0x968($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X968);
    // 0x8001E0C4: mul.s       $f20, $f2, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001E0C8: jal         0x8002B190
    // 0x8001E0CC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    cosf_recomp(rdram, ctx);
        goto after_4;
    // 0x8001E0CC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_4:
    // 0x8001E0D0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8001E0D4: jal         0x80033960
    // 0x8001E0D8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    sinf_recomp(rdram, ctx);
        goto after_5;
    // 0x8001E0D8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_5:
    // 0x8001E0DC: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8001E0E0: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8001E0E4: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001E0E8: swc1        $f20, 0x7848($at)
    MEM_W(0X7848, ctx->r1) = ctx->f20.u32l;
    // 0x8001E0EC: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
L_8001E0F0:
    // 0x8001E0F0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001E0F4: lw          $v0, -0x57BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X57BC);
    // 0x8001E0F8: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8001E0FC: lwc1        $f4, 0x10($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8001E100: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001E104: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8001E108: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001E10C: div.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001E110: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8001E114: cvt.d.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.d = CVT_D_W(ctx->f6.u32l);
    // 0x8001E118: mul.s       $f8, $f2, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x8001E11C: bgez        $v0, L_8001E130
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001E120: nop
    
            goto L_8001E130;
    }
    // 0x8001E120: nop

    // 0x8001E124: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001E128: ldc1        $f0, 0x970($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X970);
    // 0x8001E12C: add.d       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f6.d + ctx->f0.d;
L_8001E130:
    // 0x8001E130: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001E134: lw          $v0, -0x57C8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X57C8);
    // 0x8001E138: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8001E13C: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x8001E140: bgez        $v0, L_8001E154
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001E144: cvt.s.d     $f6, $f6
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f6.fl = CVT_S_D(ctx->f6.d);
            goto L_8001E154;
    }
    // 0x8001E144: cvt.s.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f6.fl = CVT_S_D(ctx->f6.d);
    // 0x8001E148: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001E14C: ldc1        $f0, 0x978($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X978);
    // 0x8001E150: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
L_8001E154:
    // 0x8001E154: cvt.s.d     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
    // 0x8001E158: div.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001E15C: mul.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001E160: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001E164: lwc1        $f2, -0x57C0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X57C0);
    // 0x8001E168: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001E16C: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001E170: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001E174: lwc1        $f2, 0x980($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X980);
    // 0x8001E178: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8001E17C: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x8001E180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001E184: mul.s       $f12, $f0, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001E188: bc1t        L_8001E194
    if (c1cs) {
        // 0x8001E18C: nop
    
            goto L_8001E194;
    }
    // 0x8001E18C: nop

    // 0x8001E190: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8001E194:
    // 0x8001E194: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001E198: lwc1        $f0, 0x984($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X984);
    // 0x8001E19C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8001E1A0: nop

    // 0x8001E1A4: bc1t        L_8001E1B0
    if (c1cs) {
        // 0x8001E1A8: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8001E1B0;
    }
    // 0x8001E1A8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8001E1AC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8001E1B0:
    // 0x8001E1B0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8001E1B4: beql        $v0, $zero, L_8001E1E8
    if (ctx->r2 == 0) {
        // 0x8001E1B8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8001E1E8;
    }
    goto skip_4;
    // 0x8001E1B8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_4:
    // 0x8001E1BC: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8001E1C0: nop

    // 0x8001E1C4: bc1t        L_8001E1D0
    if (c1cs) {
        // 0x8001E1C8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001E1D0;
    }
    // 0x8001E1C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001E1CC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8001E1D0:
    // 0x8001E1D0: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8001E1D4: nop

    // 0x8001E1D8: bc1t        L_8001E1E4
    if (c1cs) {
        // 0x8001E1DC: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8001E1E4;
    }
    // 0x8001E1DC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8001E1E0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8001E1E4:
    // 0x8001E1E4: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
L_8001E1E8:
    // 0x8001E1E8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001E1EC: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8001E1F0: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8001E1F4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8001E1F8: ldc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X48);
    // 0x8001E1FC: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x8001E200: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8001E204: jr          $ra
    // 0x8001E208: nop

    return;
    // 0x8001E208: nop

;}
RECOMP_FUNC void func_8001E20C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E20C: div.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8001E210: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001E214: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8001E218: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8001E21C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8001E220: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8001E224: mul.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x8001E228: jr          $ra
    // 0x8001E22C: nop

    return;
    // 0x8001E22C: nop

;}
RECOMP_FUNC void func_8001E230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E230: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001E234: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x8001E238: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x8001E23C: sll         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2 << 3);
    // 0x8001E240: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8001E244: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8001E248: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001E24C: sh          $a1, -0x70FC($at)
    MEM_H(-0X70FC, ctx->r1) = ctx->r5;
    // 0x8001E250: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8001E254: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001E258: sh          $v1, -0x7110($at)
    MEM_H(-0X7110, ctx->r1) = ctx->r3;
    // 0x8001E25C: jal         0x80001ACC
    // 0x8001E260: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x8001E260: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x8001E264: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001E268: lhu         $a0, -0x70FC($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X70FC);
    // 0x8001E26C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8001E270: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001E274: sw          $v0, -0x70F8($at)
    MEM_W(-0X70F8, ctx->r1) = ctx->r2;
    // 0x8001E278: jal         0x80001ACC
    // 0x8001E27C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x8001E27C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_1:
    // 0x8001E280: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001E284: lhu         $a0, -0x7110($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X7110);
    // 0x8001E288: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8001E28C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001E290: sw          $v0, -0x7104($at)
    MEM_W(-0X7104, ctx->r1) = ctx->r2;
    // 0x8001E294: jal         0x80001ACC
    // 0x8001E298: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    rs_malloc(rdram, ctx);
        goto after_2;
    // 0x8001E298: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_2:
    // 0x8001E29C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001E2A0: lhu         $a0, -0x7110($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X7110);
    // 0x8001E2A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001E2A8: sw          $v0, -0x7100($at)
    MEM_W(-0X7100, ctx->r1) = ctx->r2;
    // 0x8001E2AC: blez        $a0, L_8001E2D4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8001E2B0: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8001E2D4;
    }
    // 0x8001E2B0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8001E2B4: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8001E2B8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001E2BC: lw          $a0, -0x70F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X70F8);
L_8001E2C0:
    // 0x8001E2C0: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x8001E2C4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001E2C8: slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8001E2CC: bne         $v0, $zero, L_8001E2C0
    if (ctx->r2 != 0) {
        // 0x8001E2D0: addiu       $a0, $a0, 0x24
        ctx->r4 = ADD32(ctx->r4, 0X24);
            goto L_8001E2C0;
    }
    // 0x8001E2D0: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
L_8001E2D4:
    // 0x8001E2D4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001E2D8: lhu         $v0, -0x70FC($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X70FC);
    // 0x8001E2DC: blez        $v0, L_8001E304
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001E2E0: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8001E304;
    }
    // 0x8001E2E0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8001E2E4: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8001E2E8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001E2EC: lw          $a0, -0x7104($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7104);
L_8001E2F0:
    // 0x8001E2F0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8001E2F4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001E2F8: slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8001E2FC: bne         $v0, $zero, L_8001E2F0
    if (ctx->r2 != 0) {
        // 0x8001E300: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8001E2F0;
    }
    // 0x8001E300: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_8001E304:
    // 0x8001E304: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001E308: lw          $v0, -0x57B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X57B0);
    // 0x8001E30C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001E310: lw          $v1, -0x57AC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X57AC);
    // 0x8001E314: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001E318: sw          $v0, -0x5828($at)
    MEM_W(-0X5828, ctx->r1) = ctx->r2;
    // 0x8001E31C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001E320: sw          $v1, -0x5830($at)
    MEM_W(-0X5830, ctx->r1) = ctx->r3;
    // 0x8001E324: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8001E328: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001E32C: jr          $ra
    // 0x8001E330: nop

    return;
    // 0x8001E330: nop

;}
RECOMP_FUNC void func_8001E334(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E334: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001E338: lw          $a0, -0x70F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X70F8);
    // 0x8001E33C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E340: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8001E344: jal         0x80001C98
    // 0x8001E348: nop

    rs_free(rdram, ctx);
        goto after_0;
    // 0x8001E348: nop

    after_0:
    // 0x8001E34C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001E350: lw          $a0, -0x7104($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7104);
    // 0x8001E354: jal         0x80001C98
    // 0x8001E358: nop

    rs_free(rdram, ctx);
        goto after_1;
    // 0x8001E358: nop

    after_1:
    // 0x8001E35C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8001E360: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E364: jr          $ra
    // 0x8001E368: nop

    return;
    // 0x8001E368: nop

;}
RECOMP_FUNC void func_8001E36C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E36C: addu        $t1, $a0, $zero
    ctx->r9 = ADD32(ctx->r4, 0);
    // 0x8001E370: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x8001E374: andi        $v1, $a1, 0x8000
    ctx->r3 = ctx->r5 & 0X8000;
    // 0x8001E378: beq         $v1, $zero, L_8001E438
    if (ctx->r3 == 0) {
        // 0x8001E37C: addu        $t0, $a2, $zero
        ctx->r8 = ADD32(ctx->r6, 0);
            goto L_8001E438;
    }
    // 0x8001E37C: addu        $t0, $a2, $zero
    ctx->r8 = ADD32(ctx->r6, 0);
    // 0x8001E380: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    // 0x8001E384: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8001E388: blez        $v0, L_8001E598
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001E38C: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_8001E598;
    }
    // 0x8001E38C: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8001E390: addiu       $a1, $zero, -0x800
    ctx->r5 = ADD32(0, -0X800);
    // 0x8001E394: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x8001E398: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
L_8001E39C:
    // 0x8001E39C: lbu         $v0, 0x1($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X1);
    // 0x8001E3A0: beq         $v0, $zero, L_8001E3DC
    if (ctx->r2 == 0) {
        // 0x8001E3A4: nop
    
            goto L_8001E3DC;
    }
    // 0x8001E3A4: nop

    // 0x8001E3A8: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x8001E3AC: lbu         $a0, -0x1($a2)
    ctx->r4 = MEM_BU(ctx->r6, -0X1);
    // 0x8001E3B0: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
    // 0x8001E3B4: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8001E3B8: and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // 0x8001E3BC: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x8001E3C0: andi        $a0, $a0, 0x7C0
    ctx->r4 = ctx->r4 & 0X7C0;
    // 0x8001E3C4: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x8001E3C8: srl         $v1, $v1, 2
    ctx->r3 = S32(U32(ctx->r3) >> 2);
    // 0x8001E3CC: andi        $v1, $v1, 0x3E
    ctx->r3 = ctx->r3 & 0X3E;
    // 0x8001E3D0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8001E3D4: j           L_8001E408
    // 0x8001E3D8: ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
        goto L_8001E408;
    // 0x8001E3D8: ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
L_8001E3DC:
    // 0x8001E3DC: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x8001E3E0: lbu         $a0, -0x1($a2)
    ctx->r4 = MEM_BU(ctx->r6, -0X1);
    // 0x8001E3E4: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
    // 0x8001E3E8: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8001E3EC: and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // 0x8001E3F0: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x8001E3F4: andi        $a0, $a0, 0x7C0
    ctx->r4 = ctx->r4 & 0X7C0;
    // 0x8001E3F8: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x8001E3FC: srl         $v1, $v1, 2
    ctx->r3 = S32(U32(ctx->r3) >> 2);
    // 0x8001E400: andi        $v1, $v1, 0x3E
    ctx->r3 = ctx->r3 & 0X3E;
    // 0x8001E404: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_8001E408:
    // 0x8001E408: sh          $v1, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r3;
    // 0x8001E40C: addiu       $v0, $t2, 0x1
    ctx->r2 = ADD32(ctx->r10, 0X1);
    // 0x8001E410: addu        $t2, $v0, $zero
    ctx->r10 = ADD32(ctx->r2, 0);
    // 0x8001E414: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x8001E418: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8001E41C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8001E420: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8001E424: slt         $v0, $v0, $a3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001E428: bne         $v0, $zero, L_8001E39C
    if (ctx->r2 != 0) {
        // 0x8001E42C: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_8001E39C;
    }
    // 0x8001E42C: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8001E430: j           L_8001E598
    // 0x8001E434: nop

        goto L_8001E598;
    // 0x8001E434: nop

L_8001E438:
    // 0x8001E438: andi        $a1, $a1, 0x4000
    ctx->r5 = ctx->r5 & 0X4000;
    // 0x8001E43C: beql        $a1, $zero, L_8001E524
    if (ctx->r5 == 0) {
        // 0x8001E440: sll         $v0, $a3, 16
        ctx->r2 = S32(ctx->r7 << 16);
            goto L_8001E524;
    }
    goto skip_0;
    // 0x8001E440: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    skip_0:
    // 0x8001E444: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x8001E448: lbu         $a2, 0x1($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X1);
    // 0x8001E44C: lbu         $t3, 0x2($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X2);
    // 0x8001E450: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    // 0x8001E454: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8001E458: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001E45C: beq         $v0, $zero, L_8001E598
    if (ctx->r2 == 0) {
        // 0x8001E460: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_8001E598;
    }
    // 0x8001E460: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8001E464: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8001E468: andi        $t5, $a2, 0xFF
    ctx->r13 = ctx->r6 & 0XFF;
    // 0x8001E46C: addiu       $a3, $zero, -0x800
    ctx->r7 = ADD32(0, -0X800);
    // 0x8001E470: andi        $a2, $t3, 0xFF
    ctx->r6 = ctx->r11 & 0XFF;
    // 0x8001E474: srl         $v0, $a2, 2
    ctx->r2 = S32(U32(ctx->r6) >> 2);
    // 0x8001E478: andi        $v0, $v0, 0x3E
    ctx->r2 = ctx->r2 & 0X3E;
    // 0x8001E47C: andi        $t4, $v0, 0xFF
    ctx->r12 = ctx->r2 & 0XFF;
    // 0x8001E480: addu        $t3, $a0, $zero
    ctx->r11 = ADD32(ctx->r4, 0);
    // 0x8001E484: addiu       $a1, $t0, 0x2
    ctx->r5 = ADD32(ctx->r8, 0X2);
L_8001E488:
    // 0x8001E488: lbu         $v1, 0x0($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X0);
    // 0x8001E48C: bne         $t6, $v1, L_8001E4AC
    if (ctx->r14 != ctx->r3) {
        // 0x8001E490: nop
    
            goto L_8001E4AC;
    }
    // 0x8001E490: nop

    // 0x8001E494: lbu         $a0, -0x1($a1)
    ctx->r4 = MEM_BU(ctx->r5, -0X1);
    // 0x8001E498: bne         $t5, $a0, L_8001E4AC
    if (ctx->r13 != ctx->r4) {
        // 0x8001E49C: nop
    
            goto L_8001E4AC;
    }
    // 0x8001E49C: nop

    // 0x8001E4A0: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8001E4A4: beql        $a2, $v0, L_8001E4E0
    if (ctx->r6 == ctx->r2) {
        // 0x8001E4A8: sll         $v1, $v1, 8
        ctx->r3 = S32(ctx->r3 << 8);
            goto L_8001E4E0;
    }
    goto skip_1;
    // 0x8001E4A8: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    skip_1:
L_8001E4AC:
    // 0x8001E4AC: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x8001E4B0: lbu         $a0, -0x1($a1)
    ctx->r4 = MEM_BU(ctx->r5, -0X1);
    // 0x8001E4B4: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x8001E4B8: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8001E4BC: and         $v0, $v0, $a3
    ctx->r2 = ctx->r2 & ctx->r7;
    // 0x8001E4C0: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x8001E4C4: andi        $a0, $a0, 0x7C0
    ctx->r4 = ctx->r4 & 0X7C0;
    // 0x8001E4C8: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x8001E4CC: srl         $v1, $v1, 2
    ctx->r3 = S32(U32(ctx->r3) >> 2);
    // 0x8001E4D0: andi        $v1, $v1, 0x3E
    ctx->r3 = ctx->r3 & 0X3E;
    // 0x8001E4D4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8001E4D8: j           L_8001E4F4
    // 0x8001E4DC: ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
        goto L_8001E4F4;
    // 0x8001E4DC: ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
L_8001E4E0:
    // 0x8001E4E0: and         $v1, $v1, $a3
    ctx->r3 = ctx->r3 & ctx->r7;
    // 0x8001E4E4: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x8001E4E8: andi        $v0, $v0, 0x7C0
    ctx->r2 = ctx->r2 & 0X7C0;
    // 0x8001E4EC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8001E4F0: or          $v1, $t4, $v1
    ctx->r3 = ctx->r12 | ctx->r3;
L_8001E4F4:
    // 0x8001E4F4: sh          $v1, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r3;
    // 0x8001E4F8: addiu       $v0, $t2, 0x1
    ctx->r2 = ADD32(ctx->r10, 0X1);
    // 0x8001E4FC: addu        $t2, $v0, $zero
    ctx->r10 = ADD32(ctx->r2, 0);
    // 0x8001E500: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x8001E504: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x8001E508: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8001E50C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8001E510: slt         $v0, $v0, $t3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8001E514: bne         $v0, $zero, L_8001E488
    if (ctx->r2 != 0) {
        // 0x8001E518: addiu       $t0, $t0, 0x3
        ctx->r8 = ADD32(ctx->r8, 0X3);
            goto L_8001E488;
    }
    // 0x8001E518: addiu       $t0, $t0, 0x3
    ctx->r8 = ADD32(ctx->r8, 0X3);
    // 0x8001E51C: j           L_8001E598
    // 0x8001E520: nop

        goto L_8001E598;
    // 0x8001E520: nop

L_8001E524:
    // 0x8001E524: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8001E528: slt         $v0, $a1, $v1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E52C: beq         $v0, $zero, L_8001E598
    if (ctx->r2 == 0) {
        // 0x8001E530: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_8001E598;
    }
    // 0x8001E530: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8001E534: addiu       $t3, $zero, -0x800
    ctx->r11 = ADD32(0, -0X800);
    // 0x8001E538: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    // 0x8001E53C: addiu       $a2, $t0, 0x2
    ctx->r6 = ADD32(ctx->r8, 0X2);
L_8001E540:
    // 0x8001E540: addiu       $a1, $t2, 0x1
    ctx->r5 = ADD32(ctx->r10, 0X1);
    // 0x8001E544: addu        $t2, $a1, $zero
    ctx->r10 = ADD32(ctx->r5, 0);
    // 0x8001E548: lbu         $v1, 0x0($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X0);
    // 0x8001E54C: lbu         $a0, -0x1($a2)
    ctx->r4 = MEM_BU(ctx->r6, -0X1);
    // 0x8001E550: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x8001E554: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x8001E558: addiu       $t0, $t0, 0x3
    ctx->r8 = ADD32(ctx->r8, 0X3);
    // 0x8001E55C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8001E560: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8001E564: slt         $a1, $a1, $a3
    ctx->r5 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001E568: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    // 0x8001E56C: and         $v1, $v1, $t3
    ctx->r3 = ctx->r3 & ctx->r11;
    // 0x8001E570: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x8001E574: andi        $a0, $a0, 0x7C0
    ctx->r4 = ctx->r4 & 0X7C0;
    // 0x8001E578: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x8001E57C: srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // 0x8001E580: andi        $v0, $v0, 0x3E
    ctx->r2 = ctx->r2 & 0X3E;
    // 0x8001E584: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8001E588: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x8001E58C: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    // 0x8001E590: bne         $a1, $zero, L_8001E540
    if (ctx->r5 != 0) {
        // 0x8001E594: addiu       $t1, $t1, 0x2
        ctx->r9 = ADD32(ctx->r9, 0X2);
            goto L_8001E540;
    }
    // 0x8001E594: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
L_8001E598:
    // 0x8001E598: jr          $ra
    // 0x8001E59C: addu        $v0, $t1, $zero
    ctx->r2 = ADD32(ctx->r9, 0);
    return;
    // 0x8001E59C: addu        $v0, $t1, $zero
    ctx->r2 = ADD32(ctx->r9, 0);
;}
RECOMP_FUNC void func_8001E5A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E5A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001E5A4: addu        $t2, $a1, $zero
    ctx->r10 = ADD32(ctx->r5, 0);
    // 0x8001E5A8: addu        $t3, $a3, $zero
    ctx->r11 = ADD32(ctx->r7, 0);
    // 0x8001E5AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001E5B0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001E5B4: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // 0x8001E5B8: andi        $a2, $a2, 0xF
    ctx->r6 = ctx->r6 & 0XF;
    // 0x8001E5BC: beq         $a2, $zero, L_8001E5D8
    if (ctx->r6 == 0) {
        // 0x8001E5C0: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8001E5D8;
    }
    // 0x8001E5C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001E5C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001E5C8: beq         $a2, $v0, L_8001E5DC
    if (ctx->r6 == ctx->r2) {
        // 0x8001E5CC: addiu       $t1, $zero, 0x100
        ctx->r9 = ADD32(0, 0X100);
            goto L_8001E5DC;
    }
    // 0x8001E5CC: addiu       $t1, $zero, 0x100
    ctx->r9 = ADD32(0, 0X100);
    // 0x8001E5D0: j           L_8001E6CC
    // 0x8001E5D4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
        goto L_8001E6CC;
    // 0x8001E5D4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_8001E5D8:
    // 0x8001E5D8: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
L_8001E5DC:
    // 0x8001E5DC: lui         $v0, 0xFF00
    ctx->r2 = S32(0XFF00 << 16);
    // 0x8001E5E0: and         $v0, $t2, $v0
    ctx->r2 = ctx->r10 & ctx->r2;
    // 0x8001E5E4: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x8001E5E8: bne         $v0, $v1, L_8001E6CC
    if (ctx->r2 != ctx->r3) {
        // 0x8001E5EC: andi        $v0, $t2, 0xFFFF
        ctx->r2 = ctx->r10 & 0XFFFF;
            goto L_8001E6CC;
    }
    // 0x8001E5EC: andi        $v0, $t2, 0xFFFF
    ctx->r2 = ctx->r10 & 0XFFFF;
    // 0x8001E5F0: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x8001E5F4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8001E5F8: bnel        $a0, $v0, L_8001E6A0
    if (ctx->r4 != ctx->r2) {
        // 0x8001E5FC: andi        $a1, $a1, 0xFFFF
        ctx->r5 = ctx->r5 & 0XFFFF;
            goto L_8001E6A0;
    }
    goto skip_0;
    // 0x8001E5FC: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    skip_0:
    // 0x8001E600: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001E604: lhu         $v0, -0x70FC($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X70FC);
    // 0x8001E608: beq         $v0, $zero, L_8001E650
    if (ctx->r2 == 0) {
        // 0x8001E60C: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8001E650;
    }
    // 0x8001E60C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8001E610: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001E614: lw          $a0, -0x7104($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7104);
    // 0x8001E618: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8001E61C: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
L_8001E620:
    // 0x8001E620: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001E624: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8001E628: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8001E62C: beq         $v0, $zero, L_8001E648
    if (ctx->r2 == 0) {
        // 0x8001E630: nop
    
            goto L_8001E648;
    }
    // 0x8001E630: nop

    // 0x8001E634: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001E638: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x8001E63C: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8001E640: bne         $v0, $zero, L_8001E620
    if (ctx->r2 != 0) {
        // 0x8001E644: andi        $v0, $s0, 0xFFFF
        ctx->r2 = ctx->r16 & 0XFFFF;
            goto L_8001E620;
    }
    // 0x8001E644: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
L_8001E648:
    // 0x8001E648: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001E64C: lhu         $v0, -0x70FC($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X70FC);
L_8001E650:
    // 0x8001E650: andi        $t0, $s0, 0xFFFF
    ctx->r8 = ctx->r16 & 0XFFFF;
    // 0x8001E654: bne         $t0, $v0, L_8001E664
    if (ctx->r8 != ctx->r2) {
        // 0x8001E658: andi        $a1, $a1, 0xFFFF
        ctx->r5 = ctx->r5 & 0XFFFF;
            goto L_8001E664;
    }
    // 0x8001E658: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8001E65C: j           L_8001E6CC
    // 0x8001E660: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
        goto L_8001E6CC;
    // 0x8001E660: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_8001E664:
    // 0x8001E664: addu        $a2, $t2, $zero
    ctx->r6 = ADD32(ctx->r10, 0);
    // 0x8001E668: addu        $a3, $t1, $zero
    ctx->r7 = ADD32(ctx->r9, 0);
    // 0x8001E66C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001E670: lw          $a0, -0x5830($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5830);
    // 0x8001E674: sll         $v0, $t1, 1
    ctx->r2 = S32(ctx->r9 << 1);
    // 0x8001E678: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001E67C: lw          $v1, -0x7104($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7104);
    // 0x8001E680: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8001E684: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x8001E688: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001E68C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001E690: sw          $a0, -0x5830($at)
    MEM_W(-0X5830, ctx->r1) = ctx->r4;
    // 0x8001E694: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8001E698: j           L_8001E6C0
    // 0x8001E69C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
        goto L_8001E6C0;
    // 0x8001E69C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
L_8001E6A0:
    // 0x8001E6A0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001E6A4: lw          $v1, -0x7104($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7104);
    // 0x8001E6A8: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8001E6AC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8001E6B0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001E6B4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8001E6B8: addu        $a2, $t2, $zero
    ctx->r6 = ADD32(ctx->r10, 0);
    // 0x8001E6BC: addu        $a3, $t1, $zero
    ctx->r7 = ADD32(ctx->r9, 0);
L_8001E6C0:
    // 0x8001E6C0: jal         0x8001E36C
    // 0x8001E6C4: nop

    func_8001E36C(rdram, ctx);
        goto after_0;
    // 0x8001E6C4: nop

    after_0:
    // 0x8001E6C8: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
L_8001E6CC:
    // 0x8001E6CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001E6D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001E6D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001E6D8: jr          $ra
    // 0x8001E6DC: nop

    return;
    // 0x8001E6DC: nop

;}
RECOMP_FUNC void func_8001E6E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E6E0: andi        $a1, $a1, 0x3F
    ctx->r5 = ctx->r5 & 0X3F;
    // 0x8001E6E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001E6E8: bne         $a1, $v0, L_8001E6F4
    if (ctx->r5 != ctx->r2) {
        // 0x8001E6EC: addiu       $t0, $zero, 0x100
        ctx->r8 = ADD32(0, 0X100);
            goto L_8001E6F4;
    }
    // 0x8001E6EC: addiu       $t0, $zero, 0x100
    ctx->r8 = ADD32(0, 0X100);
    // 0x8001E6F0: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
L_8001E6F4:
    // 0x8001E6F4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001E6F8: lw          $v1, -0x7104($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7104);
    // 0x8001E6FC: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8001E700: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001E704: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001E708: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x8001E70C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001E710: lw          $v1, -0x5830($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5830);
    // 0x8001E714: sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8 << 1);
    // 0x8001E718: addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
    // 0x8001E71C: beq         $a3, $v1, L_8001E744
    if (ctx->r7 == ctx->r3) {
        // 0x8001E720: addu        $a2, $a3, $v0
        ctx->r6 = ADD32(ctx->r7, ctx->r2);
            goto L_8001E744;
    }
    // 0x8001E720: addu        $a2, $a3, $v0
    ctx->r6 = ADD32(ctx->r7, ctx->r2);
    // 0x8001E724: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
L_8001E728:
    // 0x8001E728: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8001E72C: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x8001E730: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x8001E734: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001E738: lw          $v0, -0x5830($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5830);
    // 0x8001E73C: bnel        $a1, $v0, L_8001E728
    if (ctx->r5 != ctx->r2) {
        // 0x8001E740: addiu       $a1, $a1, -0x4
        ctx->r5 = ADD32(ctx->r5, -0X4);
            goto L_8001E728;
    }
    goto skip_0;
    // 0x8001E740: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    skip_0:
L_8001E744:
    // 0x8001E744: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8001E748: lw          $a2, -0x7104($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7104);
    // 0x8001E74C: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8001E750: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001E754: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8001E758: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8001E75C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001E760: lw          $v0, -0x5830($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5830);
    // 0x8001E764: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001E768: lhu         $a0, -0x70FC($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X70FC);
    // 0x8001E76C: sll         $v1, $t0, 1
    ctx->r3 = S32(ctx->r8 << 1);
    // 0x8001E770: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001E774: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001E778: sw          $v0, -0x5830($at)
    MEM_W(-0X5830, ctx->r1) = ctx->r2;
    // 0x8001E77C: beq         $a0, $zero, L_8001E7C8
    if (ctx->r4 == 0) {
        // 0x8001E780: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8001E7C8;
    }
    // 0x8001E780: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8001E784: addu        $t1, $a2, $zero
    ctx->r9 = ADD32(ctx->r6, 0);
    // 0x8001E788: addu        $t0, $v1, $zero
    ctx->r8 = ADD32(ctx->r3, 0);
    // 0x8001E78C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8001E790: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
L_8001E794:
    // 0x8001E794: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001E798: addu        $a0, $v0, $t1
    ctx->r4 = ADD32(ctx->r2, ctx->r9);
    // 0x8001E79C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8001E7A0: beq         $v1, $zero, L_8001E7B4
    if (ctx->r3 == 0) {
        // 0x8001E7A4: sltu        $v0, $v1, $a3
        ctx->r2 = ctx->r3 < ctx->r7 ? 1 : 0;
            goto L_8001E7B4;
    }
    // 0x8001E7A4: sltu        $v0, $v1, $a3
    ctx->r2 = ctx->r3 < ctx->r7 ? 1 : 0;
    // 0x8001E7A8: beq         $v0, $zero, L_8001E7B4
    if (ctx->r2 == 0) {
        // 0x8001E7AC: addu        $v0, $v1, $t0
        ctx->r2 = ADD32(ctx->r3, ctx->r8);
            goto L_8001E7B4;
    }
    // 0x8001E7AC: addu        $v0, $v1, $t0
    ctx->r2 = ADD32(ctx->r3, ctx->r8);
    // 0x8001E7B0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_8001E7B4:
    // 0x8001E7B4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001E7B8: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x8001E7BC: sltu        $v0, $v0, $a2
    ctx->r2 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x8001E7C0: bne         $v0, $zero, L_8001E794
    if (ctx->r2 != 0) {
        // 0x8001E7C4: andi        $v0, $a1, 0xFFFF
        ctx->r2 = ctx->r5 & 0XFFFF;
            goto L_8001E794;
    }
    // 0x8001E7C4: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
L_8001E7C8:
    // 0x8001E7C8: jr          $ra
    // 0x8001E7CC: nop

    return;
    // 0x8001E7CC: nop

;}
RECOMP_FUNC void func_8001E7D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E7D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001E7D4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8001E7D8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8001E7DC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8001E7E0: andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
    // 0x8001E7E4: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x8001E7E8: jal         0x80021F78
    // 0x8001E7EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80021F78(rdram, ctx);
        goto after_0;
    // 0x8001E7EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8001E7F0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001E7F4: lw          $v1, -0x70F8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X70F8);
    // 0x8001E7F8: sll         $v0, $s0, 3
    ctx->r2 = S32(ctx->r16 << 3);
    // 0x8001E7FC: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8001E800: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001E804: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001E808: lhu         $a0, 0xC($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0XC);
    // 0x8001E80C: lw          $a1, 0x10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X10);
    // 0x8001E810: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001E814: lw          $v1, -0x5828($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5828);
    // 0x8001E818: addu        $a0, $a1, $a0
    ctx->r4 = ADD32(ctx->r5, ctx->r4);
    // 0x8001E81C: subu        $a2, $v1, $a0
    ctx->r6 = SUB32(ctx->r3, ctx->r4);
    // 0x8001E820: beq         $a2, $zero, L_8001E850
    if (ctx->r6 == 0) {
        // 0x8001E824: sh          $zero, 0x0($v0)
        MEM_H(0X0, ctx->r2) = 0;
            goto L_8001E850;
    }
    // 0x8001E824: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x8001E828: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // 0x8001E82C: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // 0x8001E830: blez        $a1, L_8001E854
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8001E834: andi        $v0, $s1, 0xFFFF
        ctx->r2 = ctx->r17 & 0XFFFF;
            goto L_8001E854;
    }
    // 0x8001E834: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
L_8001E838:
    // 0x8001E838: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001E83C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001E840: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x8001E844: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8001E848: bgtz        $a1, L_8001E838
    if (SIGNED(ctx->r5) > 0) {
        // 0x8001E84C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8001E838;
    }
    // 0x8001E84C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8001E850:
    // 0x8001E850: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
L_8001E854:
    // 0x8001E854: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8001E858: lw          $a3, -0x70F8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X70F8);
    // 0x8001E85C: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x8001E860: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001E864: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8001E868: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x8001E86C: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x8001E870: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001E874: lhu         $a0, -0x7110($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X7110);
    // 0x8001E878: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8001E87C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001E880: sw          $v0, -0x5828($at)
    MEM_W(-0X5828, ctx->r1) = ctx->r2;
    // 0x8001E884: blez        $a0, L_8001E8CC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8001E888: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8001E8CC;
    }
    // 0x8001E888: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8001E88C: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x8001E890: addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
L_8001E894:
    // 0x8001E894: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8001E898: beq         $v0, $zero, L_8001E8C0
    if (ctx->r2 == 0) {
        // 0x8001E89C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8001E8C0;
    }
    // 0x8001E89C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001E8A0: lw          $a2, 0x10($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X10);
    // 0x8001E8A4: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x8001E8A8: sltu        $v0, $v0, $a2
    ctx->r2 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x8001E8AC: beq         $v0, $zero, L_8001E8C0
    if (ctx->r2 == 0) {
        // 0x8001E8B0: nop
    
            goto L_8001E8C0;
    }
    // 0x8001E8B0: nop

    // 0x8001E8B4: lhu         $v0, 0xC($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XC);
    // 0x8001E8B8: subu        $v0, $a2, $v0
    ctx->r2 = SUB32(ctx->r6, ctx->r2);
    // 0x8001E8BC: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
L_8001E8C0:
    // 0x8001E8C0: slt         $v0, $a1, $t0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8001E8C4: bne         $v0, $zero, L_8001E894
    if (ctx->r2 != 0) {
        // 0x8001E8C8: addiu       $a0, $a0, 0x24
        ctx->r4 = ADD32(ctx->r4, 0X24);
            goto L_8001E894;
    }
    // 0x8001E8C8: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
L_8001E8CC:
    // 0x8001E8CC: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
    // 0x8001E8D0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8001E8D4: lw          $t0, -0x70F8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X70F8);
    // 0x8001E8D8: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x8001E8DC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001E8E0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8001E8E4: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x8001E8E8: lhu         $a0, 0xE($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0XE);
    // 0x8001E8EC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8001E8F0: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x8001E8F4: beq         $v1, $v0, L_8001E960
    if (ctx->r3 == ctx->r2) {
        // 0x8001E8F8: nop
    
            goto L_8001E960;
    }
    // 0x8001E8F8: nop

    // 0x8001E8FC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001E900: lhu         $v0, -0x7110($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7110);
    // 0x8001E904: blez        $v0, L_8001E93C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001E908: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8001E93C;
    }
    // 0x8001E908: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8001E90C: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    // 0x8001E910: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8001E914: addu        $v1, $t0, $zero
    ctx->r3 = ADD32(ctx->r8, 0);
L_8001E918:
    // 0x8001E918: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8001E91C: beq         $v0, $zero, L_8001E930
    if (ctx->r2 == 0) {
        // 0x8001E920: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8001E930;
    }
    // 0x8001E920: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001E924: lhu         $v0, 0xE($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XE);
    // 0x8001E928: beq         $v0, $a3, L_8001E960
    if (ctx->r2 == ctx->r7) {
        // 0x8001E92C: nop
    
            goto L_8001E960;
    }
    // 0x8001E92C: nop

L_8001E930:
    // 0x8001E930: slt         $v0, $a1, $a2
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8001E934: bne         $v0, $zero, L_8001E918
    if (ctx->r2 != 0) {
        // 0x8001E938: addiu       $v1, $v1, 0x24
        ctx->r3 = ADD32(ctx->r3, 0X24);
            goto L_8001E918;
    }
    // 0x8001E938: addiu       $v1, $v1, 0x24
    ctx->r3 = ADD32(ctx->r3, 0X24);
L_8001E93C:
    // 0x8001E93C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001E940: lw          $v1, -0x70F8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X70F8);
    // 0x8001E944: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x8001E948: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8001E94C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001E950: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001E954: lhu         $a1, 0x0($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X0);
    // 0x8001E958: jal         0x8001E6E0
    // 0x8001E95C: nop

    func_8001E6E0(rdram, ctx);
        goto after_1;
    // 0x8001E95C: nop

    after_1:
L_8001E960:
    // 0x8001E960: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8001E964: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8001E968: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8001E96C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001E970: jr          $ra
    // 0x8001E974: nop

    return;
    // 0x8001E974: nop

;}
RECOMP_FUNC void func_8001E978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E978: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8001E97C: andi        $a0, $a0, 0x3F
    ctx->r4 = ctx->r4 & 0X3F;
    // 0x8001E980: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8001E984: sltiu       $v0, $a0, 0x6
    ctx->r2 = ctx->r4 < 0X6 ? 1 : 0;
    // 0x8001E988: beq         $v0, $zero, L_8001E9D0
    if (ctx->r2 == 0) {
        // 0x8001E98C: sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4 << 2);
            goto L_8001E9D0;
    }
    // 0x8001E98C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8001E990: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001E994: addu        $at, $at, $v0
    gpr jr_addend_8001E99C = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001E998: lw          $v0, 0x990($at)
    ctx->r2 = ADD32(ctx->r1, 0X990);
    // 0x8001E99C: jr          $v0
    // 0x8001E9A0: nop

    switch (jr_addend_8001E99C >> 2) {
        case 0: goto L_8001E9A4; break;
        case 1: goto L_8001E9AC; break;
        case 2: goto L_8001E9B4; break;
        case 3: goto L_8001E9BC; break;
        case 4: goto L_8001E9C4; break;
        case 5: goto L_8001E9CC; break;
        default: switch_error(__func__, 0x8001E99C, 0x80000990);
    }
    // 0x8001E9A0: nop

L_8001E9A4:
    // 0x8001E9A4: j           L_8001E9D0
    // 0x8001E9A8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_8001E9D0;
    // 0x8001E9A8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8001E9AC:
    // 0x8001E9AC: j           L_8001E9D0
    // 0x8001E9B0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8001E9D0;
    // 0x8001E9B0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8001E9B4:
    // 0x8001E9B4: j           L_8001E9D0
    // 0x8001E9B8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_8001E9D0;
    // 0x8001E9B8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8001E9BC:
    // 0x8001E9BC: j           L_8001E9D0
    // 0x8001E9C0: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_8001E9D0;
    // 0x8001E9C0: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_8001E9C4:
    // 0x8001E9C4: j           L_8001E9D0
    // 0x8001E9C8: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_8001E9D0;
    // 0x8001E9C8: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_8001E9CC:
    // 0x8001E9CC: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_8001E9D0:
    // 0x8001E9D0: andi        $v0, $a1, 0x8000
    ctx->r2 = ctx->r5 & 0X8000;
    // 0x8001E9D4: bnel        $v0, $zero, L_8001E9DC
    if (ctx->r2 != 0) {
        // 0x8001E9D8: ori         $v1, $v1, 0x8000
        ctx->r3 = ctx->r3 | 0X8000;
            goto L_8001E9DC;
    }
    goto skip_0;
    // 0x8001E9D8: ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    skip_0:
L_8001E9DC:
    // 0x8001E9DC: andi        $v0, $a1, 0x4000
    ctx->r2 = ctx->r5 & 0X4000;
    // 0x8001E9E0: bnel        $v0, $zero, L_8001E9E8
    if (ctx->r2 != 0) {
        // 0x8001E9E4: ori         $v1, $v1, 0x4000
        ctx->r3 = ctx->r3 | 0X4000;
            goto L_8001E9E8;
    }
    goto skip_1;
    // 0x8001E9E4: ori         $v1, $v1, 0x4000
    ctx->r3 = ctx->r3 | 0X4000;
    skip_1:
L_8001E9E8:
    // 0x8001E9E8: andi        $v0, $a1, 0x2000
    ctx->r2 = ctx->r5 & 0X2000;
    // 0x8001E9EC: bnel        $v0, $zero, L_8001E9F4
    if (ctx->r2 != 0) {
        // 0x8001E9F0: ori         $v1, $v1, 0x2000
        ctx->r3 = ctx->r3 | 0X2000;
            goto L_8001E9F4;
    }
    goto skip_2;
    // 0x8001E9F0: ori         $v1, $v1, 0x2000
    ctx->r3 = ctx->r3 | 0X2000;
    skip_2:
L_8001E9F4:
    // 0x8001E9F4: andi        $v0, $a1, 0x1000
    ctx->r2 = ctx->r5 & 0X1000;
    // 0x8001E9F8: bnel        $v0, $zero, L_8001EA00
    if (ctx->r2 != 0) {
        // 0x8001E9FC: ori         $v1, $v1, 0x1000
        ctx->r3 = ctx->r3 | 0X1000;
            goto L_8001EA00;
    }
    goto skip_3;
    // 0x8001E9FC: ori         $v1, $v1, 0x1000
    ctx->r3 = ctx->r3 | 0X1000;
    skip_3:
L_8001EA00:
    // 0x8001EA00: andi        $v0, $a1, 0x800
    ctx->r2 = ctx->r5 & 0X800;
    // 0x8001EA04: bnel        $v0, $zero, L_8001EA0C
    if (ctx->r2 != 0) {
        // 0x8001EA08: ori         $v1, $v1, 0x800
        ctx->r3 = ctx->r3 | 0X800;
            goto L_8001EA0C;
    }
    goto skip_4;
    // 0x8001EA08: ori         $v1, $v1, 0x800
    ctx->r3 = ctx->r3 | 0X800;
    skip_4:
L_8001EA0C:
    // 0x8001EA0C: andi        $v0, $a1, 0x400
    ctx->r2 = ctx->r5 & 0X400;
    // 0x8001EA10: bnel        $v0, $zero, L_8001EA18
    if (ctx->r2 != 0) {
        // 0x8001EA14: ori         $v1, $v1, 0x400
        ctx->r3 = ctx->r3 | 0X400;
            goto L_8001EA18;
    }
    goto skip_5;
    // 0x8001EA14: ori         $v1, $v1, 0x400
    ctx->r3 = ctx->r3 | 0X400;
    skip_5:
L_8001EA18:
    // 0x8001EA18: andi        $v0, $a1, 0x200
    ctx->r2 = ctx->r5 & 0X200;
    // 0x8001EA1C: bnel        $v0, $zero, L_8001EA24
    if (ctx->r2 != 0) {
        // 0x8001EA20: ori         $v1, $v1, 0x200
        ctx->r3 = ctx->r3 | 0X200;
            goto L_8001EA24;
    }
    goto skip_6;
    // 0x8001EA20: ori         $v1, $v1, 0x200
    ctx->r3 = ctx->r3 | 0X200;
    skip_6:
L_8001EA24:
    // 0x8001EA24: andi        $v0, $a1, 0x100
    ctx->r2 = ctx->r5 & 0X100;
    // 0x8001EA28: bnel        $v0, $zero, L_8001EA30
    if (ctx->r2 != 0) {
        // 0x8001EA2C: ori         $v1, $v1, 0x100
        ctx->r3 = ctx->r3 | 0X100;
            goto L_8001EA30;
    }
    goto skip_7;
    // 0x8001EA2C: ori         $v1, $v1, 0x100
    ctx->r3 = ctx->r3 | 0X100;
    skip_7:
L_8001EA30:
    // 0x8001EA30: andi        $v0, $a1, 0x80
    ctx->r2 = ctx->r5 & 0X80;
    // 0x8001EA34: bnel        $v0, $zero, L_8001EA3C
    if (ctx->r2 != 0) {
        // 0x8001EA38: ori         $v1, $v1, 0x80
        ctx->r3 = ctx->r3 | 0X80;
            goto L_8001EA3C;
    }
    goto skip_8;
    // 0x8001EA38: ori         $v1, $v1, 0x80
    ctx->r3 = ctx->r3 | 0X80;
    skip_8:
L_8001EA3C:
    // 0x8001EA3C: andi        $v0, $a1, 0x40
    ctx->r2 = ctx->r5 & 0X40;
    // 0x8001EA40: bnel        $v0, $zero, L_8001EA48
    if (ctx->r2 != 0) {
        // 0x8001EA44: ori         $v1, $v1, 0x40
        ctx->r3 = ctx->r3 | 0X40;
            goto L_8001EA48;
    }
    goto skip_9;
    // 0x8001EA44: ori         $v1, $v1, 0x40
    ctx->r3 = ctx->r3 | 0X40;
    skip_9:
L_8001EA48:
    // 0x8001EA48: jr          $ra
    // 0x8001EA4C: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    return;
    // 0x8001EA4C: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
;}
RECOMP_FUNC void func_8001EA50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EA50: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8001EA54: andi        $a0, $a0, 0xF
    ctx->r4 = ctx->r4 & 0XF;
    // 0x8001EA58: sltiu       $v0, $a0, 0x6
    ctx->r2 = ctx->r4 < 0X6 ? 1 : 0;
    // 0x8001EA5C: beq         $v0, $zero, L_8001EAA4
    if (ctx->r2 == 0) {
        // 0x8001EA60: sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4 << 2);
            goto L_8001EAA4;
    }
    // 0x8001EA60: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8001EA64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001EA68: addu        $at, $at, $v0
    gpr jr_addend_8001EA70 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001EA6C: lw          $v0, 0x9A8($at)
    ctx->r2 = ADD32(ctx->r1, 0X9A8);
    // 0x8001EA70: jr          $v0
    // 0x8001EA74: nop

    switch (jr_addend_8001EA70 >> 2) {
        case 0: goto L_8001EA80; break;
        case 1: goto L_8001EA90; break;
        case 2: goto L_8001EA98; break;
        case 3: goto L_8001EAA0; break;
        case 4: goto L_8001EA78; break;
        case 5: goto L_8001EA88; break;
        default: switch_error(__func__, 0x8001EA70, 0x800009A8);
    }
    // 0x8001EA74: nop

L_8001EA78:
    // 0x8001EA78: j           L_8001EAA4
    // 0x8001EA7C: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
        goto L_8001EAA4;
    // 0x8001EA7C: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_8001EA80:
    // 0x8001EA80: j           L_8001EAA4
    // 0x8001EA84: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8001EAA4;
    // 0x8001EA84: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8001EA88:
    // 0x8001EA88: j           L_8001EAA4
    // 0x8001EA8C: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
        goto L_8001EAA4;
    // 0x8001EA8C: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
L_8001EA90:
    // 0x8001EA90: j           L_8001EAA4
    // 0x8001EA94: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_8001EAA4;
    // 0x8001EA94: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8001EA98:
    // 0x8001EA98: j           L_8001EAA4
    // 0x8001EA9C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_8001EAA4;
    // 0x8001EA9C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_8001EAA0:
    // 0x8001EAA0: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_8001EAA4:
    // 0x8001EAA4: andi        $v0, $a1, 0x8000
    ctx->r2 = ctx->r5 & 0X8000;
    // 0x8001EAA8: bnel        $v0, $zero, L_8001EAB0
    if (ctx->r2 != 0) {
        // 0x8001EAAC: ori         $v1, $v1, 0x8000
        ctx->r3 = ctx->r3 | 0X8000;
            goto L_8001EAB0;
    }
    goto skip_0;
    // 0x8001EAAC: ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    skip_0:
L_8001EAB0:
    // 0x8001EAB0: andi        $v0, $a1, 0x4000
    ctx->r2 = ctx->r5 & 0X4000;
    // 0x8001EAB4: bnel        $v0, $zero, L_8001EABC
    if (ctx->r2 != 0) {
        // 0x8001EAB8: ori         $v1, $v1, 0x4000
        ctx->r3 = ctx->r3 | 0X4000;
            goto L_8001EABC;
    }
    goto skip_1;
    // 0x8001EAB8: ori         $v1, $v1, 0x4000
    ctx->r3 = ctx->r3 | 0X4000;
    skip_1:
L_8001EABC:
    // 0x8001EABC: andi        $v0, $a1, 0x2000
    ctx->r2 = ctx->r5 & 0X2000;
    // 0x8001EAC0: bnel        $v0, $zero, L_8001EAC8
    if (ctx->r2 != 0) {
        // 0x8001EAC4: ori         $v1, $v1, 0x2000
        ctx->r3 = ctx->r3 | 0X2000;
            goto L_8001EAC8;
    }
    goto skip_2;
    // 0x8001EAC4: ori         $v1, $v1, 0x2000
    ctx->r3 = ctx->r3 | 0X2000;
    skip_2:
L_8001EAC8:
    // 0x8001EAC8: andi        $v0, $a1, 0x1000
    ctx->r2 = ctx->r5 & 0X1000;
    // 0x8001EACC: bnel        $v0, $zero, L_8001EAD4
    if (ctx->r2 != 0) {
        // 0x8001EAD0: ori         $v1, $v1, 0x1000
        ctx->r3 = ctx->r3 | 0X1000;
            goto L_8001EAD4;
    }
    goto skip_3;
    // 0x8001EAD0: ori         $v1, $v1, 0x1000
    ctx->r3 = ctx->r3 | 0X1000;
    skip_3:
L_8001EAD4:
    // 0x8001EAD4: andi        $v0, $a1, 0x800
    ctx->r2 = ctx->r5 & 0X800;
    // 0x8001EAD8: bnel        $v0, $zero, L_8001EAE0
    if (ctx->r2 != 0) {
        // 0x8001EADC: ori         $v1, $v1, 0x800
        ctx->r3 = ctx->r3 | 0X800;
            goto L_8001EAE0;
    }
    goto skip_4;
    // 0x8001EADC: ori         $v1, $v1, 0x800
    ctx->r3 = ctx->r3 | 0X800;
    skip_4:
L_8001EAE0:
    // 0x8001EAE0: andi        $v0, $a1, 0x400
    ctx->r2 = ctx->r5 & 0X400;
    // 0x8001EAE4: bnel        $v0, $zero, L_8001EAEC
    if (ctx->r2 != 0) {
        // 0x8001EAE8: ori         $v1, $v1, 0x400
        ctx->r3 = ctx->r3 | 0X400;
            goto L_8001EAEC;
    }
    goto skip_5;
    // 0x8001EAE8: ori         $v1, $v1, 0x400
    ctx->r3 = ctx->r3 | 0X400;
    skip_5:
L_8001EAEC:
    // 0x8001EAEC: andi        $v0, $a1, 0x200
    ctx->r2 = ctx->r5 & 0X200;
    // 0x8001EAF0: bnel        $v0, $zero, L_8001EAF8
    if (ctx->r2 != 0) {
        // 0x8001EAF4: ori         $v1, $v1, 0x200
        ctx->r3 = ctx->r3 | 0X200;
            goto L_8001EAF8;
    }
    goto skip_6;
    // 0x8001EAF4: ori         $v1, $v1, 0x200
    ctx->r3 = ctx->r3 | 0X200;
    skip_6:
L_8001EAF8:
    // 0x8001EAF8: andi        $v0, $a1, 0x100
    ctx->r2 = ctx->r5 & 0X100;
    // 0x8001EAFC: bnel        $v0, $zero, L_8001EB04
    if (ctx->r2 != 0) {
        // 0x8001EB00: ori         $v1, $v1, 0x100
        ctx->r3 = ctx->r3 | 0X100;
            goto L_8001EB04;
    }
    goto skip_7;
    // 0x8001EB00: ori         $v1, $v1, 0x100
    ctx->r3 = ctx->r3 | 0X100;
    skip_7:
L_8001EB04:
    // 0x8001EB04: andi        $v0, $a1, 0x80
    ctx->r2 = ctx->r5 & 0X80;
    // 0x8001EB08: bnel        $v0, $zero, L_8001EB10
    if (ctx->r2 != 0) {
        // 0x8001EB0C: ori         $v1, $v1, 0x80
        ctx->r3 = ctx->r3 | 0X80;
            goto L_8001EB10;
    }
    goto skip_8;
    // 0x8001EB0C: ori         $v1, $v1, 0x80
    ctx->r3 = ctx->r3 | 0X80;
    skip_8:
L_8001EB10:
    // 0x8001EB10: andi        $v0, $a1, 0x40
    ctx->r2 = ctx->r5 & 0X40;
    // 0x8001EB14: bnel        $v0, $zero, L_8001EB1C
    if (ctx->r2 != 0) {
        // 0x8001EB18: ori         $v1, $v1, 0x40
        ctx->r3 = ctx->r3 | 0X40;
            goto L_8001EB1C;
    }
    goto skip_9;
    // 0x8001EB18: ori         $v1, $v1, 0x40
    ctx->r3 = ctx->r3 | 0X40;
    skip_9:
L_8001EB1C:
    // 0x8001EB1C: jr          $ra
    // 0x8001EB20: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    return;
    // 0x8001EB20: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
;}
RECOMP_FUNC void func_8001EB24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EB24: addiu       $sp, $sp, -0x178
    ctx->r29 = ADD32(ctx->r29, -0X178);
    // 0x8001EB28: addu        $t3, $a0, $zero
    ctx->r11 = ADD32(ctx->r4, 0);
    // 0x8001EB2C: lw          $a0, 0x18C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18C);
    // 0x8001EB30: sw          $s6, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r22;
    // 0x8001EB34: lw          $s6, 0x190($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X190);
    // 0x8001EB38: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // 0x8001EB3C: lbu         $t9, 0x18B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X18B);
    // 0x8001EB40: andi        $a1, $a1, 0xF
    ctx->r5 = ctx->r5 & 0XF;
    // 0x8001EB44: sltiu       $v0, $a1, 0x6
    ctx->r2 = ctx->r5 < 0X6 ? 1 : 0;
    // 0x8001EB48: sw          $ra, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r31;
    // 0x8001EB4C: sw          $fp, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r30;
    // 0x8001EB50: sw          $s7, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r23;
    // 0x8001EB54: sw          $s5, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r21;
    // 0x8001EB58: sw          $s4, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r20;
    // 0x8001EB5C: sw          $s3, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r19;
    // 0x8001EB60: sw          $s2, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r18;
    // 0x8001EB64: sw          $s1, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r17;
    // 0x8001EB68: beq         $v0, $zero, L_8001F91C
    if (ctx->r2 == 0) {
        // 0x8001EB6C: sw          $s0, 0x150($sp)
        MEM_W(0X150, ctx->r29) = ctx->r16;
            goto L_8001F91C;
    }
    // 0x8001EB6C: sw          $s0, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r16;
    // 0x8001EB70: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8001EB74: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001EB78: addu        $at, $at, $v0
    gpr jr_addend_8001EB80 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001EB7C: lw          $v0, 0x9C0($at)
    ctx->r2 = ADD32(ctx->r1, 0X9C0);
    // 0x8001EB80: jr          $v0
    // 0x8001EB84: nop

    switch (jr_addend_8001EB80 >> 2) {
        case 0: goto L_8001EE8C; break;
        case 1: goto L_8001F2D0; break;
        case 2: goto L_8001F3AC; break;
        case 3: goto L_8001F660; break;
        case 4: goto L_8001EB88; break;
        case 5: goto L_8001EFF0; break;
        default: switch_error(__func__, 0x8001EB80, 0x800009C0);
    }
    // 0x8001EB84: nop

L_8001EB88:
    // 0x8001EB88: andi        $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 & 0X8000;
    // 0x8001EB8C: beq         $v0, $zero, L_8001EC6C
    if (ctx->r2 == 0) {
        // 0x8001EB90: addiu       $v0, $a2, 0x7
        ctx->r2 = ADD32(ctx->r6, 0X7);
            goto L_8001EC6C;
    }
    // 0x8001EB90: addiu       $v0, $a2, 0x7
    ctx->r2 = ADD32(ctx->r6, 0X7);
    // 0x8001EB94: andi        $s0, $v0, 0xFFF8
    ctx->r16 = ctx->r2 & 0XFFF8;
    // 0x8001EB98: andi        $v0, $t9, 0xFF
    ctx->r2 = ctx->r25 & 0XFF;
    // 0x8001EB9C: blez        $v0, L_8001F91C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001EBA0: addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
            goto L_8001F91C;
    }
    // 0x8001EBA0: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x8001EBA4: addiu       $s1, $zero, -0x8
    ctx->r17 = ADD32(0, -0X8);
    // 0x8001EBA8: addu        $t7, $v0, $zero
    ctx->r15 = ADD32(ctx->r2, 0);
    // 0x8001EBAC: addu        $t6, $a0, $zero
    ctx->r14 = ADD32(ctx->r4, 0);
L_8001EBB0:
    // 0x8001EBB0: lw          $t1, 0x0($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X0);
    // 0x8001EBB4: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x8001EBB8: blez        $v0, L_8001EC34
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001EBBC: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_8001EC34;
    }
    // 0x8001EBBC: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8001EBC0: andi        $t4, $a2, 0xFFFF
    ctx->r12 = ctx->r6 & 0XFFFF;
    // 0x8001EBC4: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    // 0x8001EBC8: addu        $t5, $v0, $zero
    ctx->r13 = ADD32(ctx->r2, 0);
L_8001EBCC:
    // 0x8001EBCC: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8001EBD0: andi        $v0, $t2, 0x1
    ctx->r2 = ctx->r10 & 0X1;
    // 0x8001EBD4: beq         $t4, $zero, L_8001EBFC
    if (ctx->r12 == 0) {
        // 0x8001EBD8: sll         $a0, $v0, 2
        ctx->r4 = S32(ctx->r2 << 2);
            goto L_8001EBFC;
    }
    // 0x8001EBD8: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
L_8001EBDC:
    // 0x8001EBDC: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x8001EBE0: xor         $v0, $t0, $a0
    ctx->r2 = ctx->r8 ^ ctx->r4;
    // 0x8001EBE4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001EBE8: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8001EBEC: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x8001EBF0: slt         $v0, $t0, $t4
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001EBF4: bne         $v0, $zero, L_8001EBDC
    if (ctx->r2 != 0) {
        // 0x8001EBF8: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_8001EBDC;
    }
    // 0x8001EBF8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_8001EBFC:
    // 0x8001EBFC: slt         $v0, $t0, $a1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8001EC00: beq         $v0, $zero, L_8001EC24
    if (ctx->r2 == 0) {
        // 0x8001EC04: addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
            goto L_8001EC24;
    }
    // 0x8001EC04: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // 0x8001EC08: xor         $v0, $t0, $a0
    ctx->r2 = ctx->r8 ^ ctx->r4;
L_8001EC0C:
    // 0x8001EC0C: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8001EC10: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8001EC14: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001EC18: slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001EC1C: bne         $v0, $zero, L_8001EC0C
    if (ctx->r2 != 0) {
        // 0x8001EC20: xor         $v0, $t0, $a0
        ctx->r2 = ctx->r8 ^ ctx->r4;
            goto L_8001EC0C;
    }
    // 0x8001EC20: xor         $v0, $t0, $a0
    ctx->r2 = ctx->r8 ^ ctx->r4;
L_8001EC24:
    // 0x8001EC24: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8001EC28: slt         $v0, $t2, $t5
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8001EC2C: bne         $v0, $zero, L_8001EBCC
    if (ctx->r2 != 0) {
        // 0x8001EC30: addu        $t3, $t3, $a1
        ctx->r11 = ADD32(ctx->r11, ctx->r5);
            goto L_8001EBCC;
    }
    // 0x8001EC30: addu        $t3, $t3, $a1
    ctx->r11 = ADD32(ctx->r11, ctx->r5);
L_8001EC34:
    // 0x8001EC34: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x8001EC38: srl         $a2, $v0, 1
    ctx->r6 = S32(U32(ctx->r2) >> 1);
    // 0x8001EC3C: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x8001EC40: srl         $a3, $v0, 1
    ctx->r7 = S32(U32(ctx->r2) >> 1);
    // 0x8001EC44: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x8001EC48: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x8001EC4C: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // 0x8001EC50: and         $s0, $v0, $s1
    ctx->r16 = ctx->r2 & ctx->r17;
    // 0x8001EC54: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8001EC58: slt         $v0, $s4, $t7
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001EC5C: bne         $v0, $zero, L_8001EBB0
    if (ctx->r2 != 0) {
        // 0x8001EC60: addiu       $t6, $t6, 0x4
        ctx->r14 = ADD32(ctx->r14, 0X4);
            goto L_8001EBB0;
    }
    // 0x8001EC60: addiu       $t6, $t6, 0x4
    ctx->r14 = ADD32(ctx->r14, 0X4);
    // 0x8001EC64: j           L_8001F920
    // 0x8001EC68: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
        goto L_8001F920;
    // 0x8001EC68: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
L_8001EC6C:
    // 0x8001EC6C: andi        $v0, $v1, 0x4000
    ctx->r2 = ctx->r3 & 0X4000;
    // 0x8001EC70: beq         $v0, $zero, L_8001ED90
    if (ctx->r2 == 0) {
        // 0x8001EC74: addiu       $v0, $a2, 0x7
        ctx->r2 = ADD32(ctx->r6, 0X7);
            goto L_8001ED90;
    }
    // 0x8001EC74: addiu       $v0, $a2, 0x7
    ctx->r2 = ADD32(ctx->r6, 0X7);
    // 0x8001EC78: andi        $s0, $v0, 0xFFF8
    ctx->r16 = ctx->r2 & 0XFFF8;
    // 0x8001EC7C: andi        $v0, $t9, 0xFF
    ctx->r2 = ctx->r25 & 0XFF;
    // 0x8001EC80: blez        $v0, L_8001F91C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001EC84: addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
            goto L_8001F91C;
    }
    // 0x8001EC84: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x8001EC88: addiu       $s5, $zero, -0x8
    ctx->r21 = ADD32(0, -0X8);
    // 0x8001EC8C: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8001EC90: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
L_8001EC94:
    // 0x8001EC94: lbu         $v0, 0x0($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X0);
    // 0x8001EC98: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8001EC9C: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8001ECA0: andi        $v1, $a3, 0xFFFF
    ctx->r3 = ctx->r7 & 0XFFFF;
    // 0x8001ECA4: blez        $v1, L_8001ED58
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001ECA8: andi        $v0, $v0, 0xF0
        ctx->r2 = ctx->r2 & 0XF0;
            goto L_8001ED58;
    }
    // 0x8001ECA8: andi        $v0, $v0, 0xF0
    ctx->r2 = ctx->r2 & 0XF0;
    // 0x8001ECAC: andi        $s1, $a2, 0xFFFF
    ctx->r17 = ctx->r6 & 0XFFFF;
    // 0x8001ECB0: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x8001ECB4: andi        $t4, $s0, 0xFFFF
    ctx->r12 = ctx->r16 & 0XFFFF;
    // 0x8001ECB8: addu        $t7, $v1, $zero
    ctx->r15 = ADD32(ctx->r3, 0);
L_8001ECBC:
    // 0x8001ECBC: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8001ECC0: andi        $v0, $t2, 0x1
    ctx->r2 = ctx->r10 & 0X1;
    // 0x8001ECC4: beq         $s1, $zero, L_8001ED20
    if (ctx->r17 == 0) {
        // 0x8001ECC8: sll         $a1, $v0, 2
        ctx->r5 = S32(ctx->r2 << 2);
            goto L_8001ED20;
    }
    // 0x8001ECC8: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x8001ECCC: andi        $t5, $a2, 0xFFFF
    ctx->r13 = ctx->r6 & 0XFFFF;
    // 0x8001ECD0: andi        $v0, $t0, 0x1
    ctx->r2 = ctx->r8 & 0X1;
L_8001ECD4:
    // 0x8001ECD4: beq         $v0, $zero, L_8001ECF0
    if (ctx->r2 == 0) {
        // 0x8001ECD8: nop
    
            goto L_8001ECF0;
    }
    // 0x8001ECD8: nop

    // 0x8001ECDC: lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X0);
    // 0x8001ECE0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001ECE4: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x8001ECE8: j           L_8001ECF8
    // 0x8001ECEC: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
        goto L_8001ECF8;
    // 0x8001ECEC: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
L_8001ECF0:
    // 0x8001ECF0: lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X0);
    // 0x8001ECF4: andi        $v1, $v0, 0xF0
    ctx->r3 = ctx->r2 & 0XF0;
L_8001ECF8:
    // 0x8001ECF8: xor         $v0, $t0, $a1
    ctx->r2 = ctx->r8 ^ ctx->r5;
    // 0x8001ECFC: addu        $a0, $t3, $v0
    ctx->r4 = ADD32(ctx->r11, ctx->r2);
    // 0x8001ED00: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8001ED04: bnel        $v0, $t6, L_8001ED0C
    if (ctx->r2 != ctx->r14) {
        // 0x8001ED08: ori         $v0, $v0, 0xF
        ctx->r2 = ctx->r2 | 0XF;
            goto L_8001ED0C;
    }
    goto skip_0;
    // 0x8001ED08: ori         $v0, $v0, 0xF
    ctx->r2 = ctx->r2 | 0XF;
    skip_0:
L_8001ED0C:
    // 0x8001ED0C: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x8001ED10: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001ED14: slt         $v0, $t0, $t5
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8001ED18: bne         $v0, $zero, L_8001ECD4
    if (ctx->r2 != 0) {
        // 0x8001ED1C: andi        $v0, $t0, 0x1
        ctx->r2 = ctx->r8 & 0X1;
            goto L_8001ECD4;
    }
    // 0x8001ED1C: andi        $v0, $t0, 0x1
    ctx->r2 = ctx->r8 & 0X1;
L_8001ED20:
    // 0x8001ED20: slt         $v0, $t0, $t4
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001ED24: beq         $v0, $zero, L_8001ED48
    if (ctx->r2 == 0) {
        // 0x8001ED28: addu        $v1, $t4, $zero
        ctx->r3 = ADD32(ctx->r12, 0);
            goto L_8001ED48;
    }
    // 0x8001ED28: addu        $v1, $t4, $zero
    ctx->r3 = ADD32(ctx->r12, 0);
    // 0x8001ED2C: xor         $v0, $t0, $a1
    ctx->r2 = ctx->r8 ^ ctx->r5;
L_8001ED30:
    // 0x8001ED30: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8001ED34: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8001ED38: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001ED3C: slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001ED40: bne         $v0, $zero, L_8001ED30
    if (ctx->r2 != 0) {
        // 0x8001ED44: xor         $v0, $t0, $a1
        ctx->r2 = ctx->r8 ^ ctx->r5;
            goto L_8001ED30;
    }
    // 0x8001ED44: xor         $v0, $t0, $a1
    ctx->r2 = ctx->r8 ^ ctx->r5;
L_8001ED48:
    // 0x8001ED48: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8001ED4C: slt         $v0, $t2, $t7
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001ED50: bne         $v0, $zero, L_8001ECBC
    if (ctx->r2 != 0) {
        // 0x8001ED54: addu        $t3, $t3, $t4
        ctx->r11 = ADD32(ctx->r11, ctx->r12);
            goto L_8001ECBC;
    }
    // 0x8001ED54: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
L_8001ED58:
    // 0x8001ED58: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x8001ED5C: srl         $a2, $v0, 1
    ctx->r6 = S32(U32(ctx->r2) >> 1);
    // 0x8001ED60: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x8001ED64: srl         $a3, $v0, 1
    ctx->r7 = S32(U32(ctx->r2) >> 1);
    // 0x8001ED68: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x8001ED6C: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x8001ED70: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // 0x8001ED74: and         $s0, $v0, $s5
    ctx->r16 = ctx->r2 & ctx->r21;
    // 0x8001ED78: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8001ED7C: slt         $v0, $s4, $s3
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8001ED80: bne         $v0, $zero, L_8001EC94
    if (ctx->r2 != 0) {
        // 0x8001ED84: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8001EC94;
    }
    // 0x8001ED84: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8001ED88: j           L_8001F920
    // 0x8001ED8C: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
        goto L_8001F920;
    // 0x8001ED8C: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
L_8001ED90:
    // 0x8001ED90: addiu       $v0, $a2, 0xF
    ctx->r2 = ADD32(ctx->r6, 0XF);
    // 0x8001ED94: andi        $s0, $v0, 0xFFF0
    ctx->r16 = ctx->r2 & 0XFFF0;
    // 0x8001ED98: andi        $v0, $t9, 0xFF
    ctx->r2 = ctx->r25 & 0XFF;
    // 0x8001ED9C: blez        $v0, L_8001F91C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001EDA0: addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
            goto L_8001F91C;
    }
    // 0x8001EDA0: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x8001EDA4: addiu       $s6, $zero, -0x10
    ctx->r22 = ADD32(0, -0X10);
    // 0x8001EDA8: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // 0x8001EDAC: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
L_8001EDB0:
    // 0x8001EDB0: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x8001EDB4: andi        $v1, $a3, 0xFFFF
    ctx->r3 = ctx->r7 & 0XFFFF;
    // 0x8001EDB8: blez        $v1, L_8001EE54
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001EDBC: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_8001EE54;
    }
    // 0x8001EDBC: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8001EDC0: andi        $t7, $a2, 0xFFFF
    ctx->r15 = ctx->r6 & 0XFFFF;
    // 0x8001EDC4: addiu       $v0, $t7, 0x1
    ctx->r2 = ADD32(ctx->r15, 0X1);
    // 0x8001EDC8: sra         $s2, $v0, 1
    ctx->r18 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8001EDCC: andi        $t6, $s0, 0xFFFF
    ctx->r14 = ctx->r16 & 0XFFFF;
    // 0x8001EDD0: srl         $t5, $t6, 1
    ctx->r13 = S32(U32(ctx->r14) >> 1);
    // 0x8001EDD4: addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
L_8001EDD8:
    // 0x8001EDD8: andi        $v0, $t2, 0x1
    ctx->r2 = ctx->r10 & 0X1;
    // 0x8001EDDC: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x8001EDE0: beq         $s2, $zero, L_8001EE14
    if (ctx->r18 == 0) {
        // 0x8001EDE4: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_8001EE14;
    }
    // 0x8001EDE4: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8001EDE8: andi        $t4, $a0, 0xFF
    ctx->r12 = ctx->r4 & 0XFF;
    // 0x8001EDEC: addiu       $v0, $t7, 0x1
    ctx->r2 = ADD32(ctx->r15, 0X1);
    // 0x8001EDF0: sra         $a1, $v0, 1
    ctx->r5 = S32(SIGNED(ctx->r2) >> 1);
L_8001EDF4:
    // 0x8001EDF4: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x8001EDF8: xor         $v0, $t0, $t4
    ctx->r2 = ctx->r8 ^ ctx->r12;
    // 0x8001EDFC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001EE00: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8001EE04: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x8001EE08: slt         $v0, $t0, $a1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8001EE0C: bne         $v0, $zero, L_8001EDF4
    if (ctx->r2 != 0) {
        // 0x8001EE10: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_8001EDF4;
    }
    // 0x8001EE10: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_8001EE14:
    // 0x8001EE14: slt         $v0, $t0, $t5
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8001EE18: beql        $v0, $zero, L_8001EE48
    if (ctx->r2 == 0) {
        // 0x8001EE1C: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_8001EE48;
    }
    goto skip_1;
    // 0x8001EE1C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_1:
    // 0x8001EE20: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001EE24: srl         $v1, $t6, 1
    ctx->r3 = S32(U32(ctx->r14) >> 1);
    // 0x8001EE28: xor         $v0, $t0, $a0
    ctx->r2 = ctx->r8 ^ ctx->r4;
L_8001EE2C:
    // 0x8001EE2C: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8001EE30: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8001EE34: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001EE38: slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001EE3C: bne         $v0, $zero, L_8001EE2C
    if (ctx->r2 != 0) {
        // 0x8001EE40: xor         $v0, $t0, $a0
        ctx->r2 = ctx->r8 ^ ctx->r4;
            goto L_8001EE2C;
    }
    // 0x8001EE40: xor         $v0, $t0, $a0
    ctx->r2 = ctx->r8 ^ ctx->r4;
    // 0x8001EE44: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_8001EE48:
    // 0x8001EE48: slt         $v0, $t2, $s1
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8001EE4C: bne         $v0, $zero, L_8001EDD8
    if (ctx->r2 != 0) {
        // 0x8001EE50: addu        $t3, $t3, $t5
        ctx->r11 = ADD32(ctx->r11, ctx->r13);
            goto L_8001EDD8;
    }
    // 0x8001EE50: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
L_8001EE54:
    // 0x8001EE54: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x8001EE58: srl         $a2, $v0, 1
    ctx->r6 = S32(U32(ctx->r2) >> 1);
    // 0x8001EE5C: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x8001EE60: srl         $a3, $v0, 1
    ctx->r7 = S32(U32(ctx->r2) >> 1);
    // 0x8001EE64: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x8001EE68: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x8001EE6C: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x8001EE70: and         $s0, $v0, $s6
    ctx->r16 = ctx->r2 & ctx->r22;
    // 0x8001EE74: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8001EE78: slt         $v0, $s4, $s5
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x8001EE7C: bne         $v0, $zero, L_8001EDB0
    if (ctx->r2 != 0) {
        // 0x8001EE80: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_8001EDB0;
    }
    // 0x8001EE80: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8001EE84: j           L_8001F920
    // 0x8001EE88: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
        goto L_8001F920;
    // 0x8001EE88: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
L_8001EE8C:
    // 0x8001EE8C: addiu       $v0, $a2, 0xF
    ctx->r2 = ADD32(ctx->r6, 0XF);
    // 0x8001EE90: andi        $s0, $v0, 0xFFF0
    ctx->r16 = ctx->r2 & 0XFFF0;
    // 0x8001EE94: andi        $v0, $t3, 0x7
    ctx->r2 = ctx->r11 & 0X7;
    // 0x8001EE98: bne         $v0, $zero, L_8001EF08
    if (ctx->r2 != 0) {
        // 0x8001EE9C: andi        $v0, $t9, 0xFF
        ctx->r2 = ctx->r25 & 0XFF;
            goto L_8001EF08;
    }
    // 0x8001EE9C: andi        $v0, $t9, 0xFF
    ctx->r2 = ctx->r25 & 0XFF;
    // 0x8001EEA0: blez        $v0, L_8001F91C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001EEA4: addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
            goto L_8001F91C;
    }
    // 0x8001EEA4: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x8001EEA8: addiu       $s6, $zero, -0x10
    ctx->r22 = ADD32(0, -0X10);
    // 0x8001EEAC: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // 0x8001EEB0: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
L_8001EEB4:
    // 0x8001EEB4: andi        $s2, $a3, 0xFFFF
    ctx->r18 = ctx->r7 & 0XFFFF;
    // 0x8001EEB8: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8001EEBC: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    // 0x8001EEC0: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8001EEC4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8001EEC8: andi        $s1, $a2, 0xFFFF
    ctx->r17 = ctx->r6 & 0XFFFF;
    // 0x8001EECC: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x8001EED0: addu        $a0, $t3, $zero
    ctx->r4 = ADD32(ctx->r11, 0);
    // 0x8001EED4: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8001EED8: jal         0x80024880
    // 0x8001EEDC: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    func_80024880(rdram, ctx);
        goto after_0;
    // 0x8001EEDC: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8001EEE0: addu        $t3, $v0, $zero
    ctx->r11 = ADD32(ctx->r2, 0);
    // 0x8001EEE4: srl         $a2, $s1, 1
    ctx->r6 = S32(U32(ctx->r17) >> 1);
    // 0x8001EEE8: srl         $a3, $s2, 1
    ctx->r7 = S32(U32(ctx->r18) >> 1);
    // 0x8001EEEC: srl         $s0, $s0, 1
    ctx->r16 = S32(U32(ctx->r16) >> 1);
    // 0x8001EEF0: addiu       $s0, $s0, 0xF
    ctx->r16 = ADD32(ctx->r16, 0XF);
    // 0x8001EEF4: slt         $v0, $s4, $s5
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x8001EEF8: bne         $v0, $zero, L_8001EEB4
    if (ctx->r2 != 0) {
        // 0x8001EEFC: and         $s0, $s0, $s6
        ctx->r16 = ctx->r16 & ctx->r22;
            goto L_8001EEB4;
    }
    // 0x8001EEFC: and         $s0, $s0, $s6
    ctx->r16 = ctx->r16 & ctx->r22;
    // 0x8001EF00: j           L_8001F920
    // 0x8001EF04: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
        goto L_8001F920;
    // 0x8001EF04: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
L_8001EF08:
    // 0x8001EF08: blez        $v0, L_8001F91C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001EF0C: addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
            goto L_8001F91C;
    }
    // 0x8001EF0C: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x8001EF10: addiu       $s5, $zero, -0x10
    ctx->r21 = ADD32(0, -0X10);
    // 0x8001EF14: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8001EF18: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
L_8001EF1C:
    // 0x8001EF1C: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x8001EF20: andi        $v1, $a3, 0xFFFF
    ctx->r3 = ctx->r7 & 0XFFFF;
    // 0x8001EF24: blez        $v1, L_8001EFB8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001EF28: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_8001EFB8;
    }
    // 0x8001EF28: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8001EF2C: andi        $t7, $a2, 0xFFFF
    ctx->r15 = ctx->r6 & 0XFFFF;
    // 0x8001EF30: addiu       $v0, $t7, 0x1
    ctx->r2 = ADD32(ctx->r15, 0X1);
    // 0x8001EF34: sra         $s2, $v0, 1
    ctx->r18 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8001EF38: andi        $t6, $s0, 0xFFFF
    ctx->r14 = ctx->r16 & 0XFFFF;
    // 0x8001EF3C: srl         $t5, $t6, 1
    ctx->r13 = S32(U32(ctx->r14) >> 1);
    // 0x8001EF40: addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
L_8001EF44:
    // 0x8001EF44: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8001EF48: andi        $v0, $t2, 0x1
    ctx->r2 = ctx->r10 & 0X1;
    // 0x8001EF4C: beq         $s2, $zero, L_8001EF7C
    if (ctx->r18 == 0) {
        // 0x8001EF50: sll         $a0, $v0, 2
        ctx->r4 = S32(ctx->r2 << 2);
            goto L_8001EF7C;
    }
    // 0x8001EF50: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x8001EF54: addiu       $v0, $t7, 0x1
    ctx->r2 = ADD32(ctx->r15, 0X1);
    // 0x8001EF58: sra         $t4, $v0, 1
    ctx->r12 = S32(SIGNED(ctx->r2) >> 1);
L_8001EF5C:
    // 0x8001EF5C: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x8001EF60: xor         $v0, $t0, $a0
    ctx->r2 = ctx->r8 ^ ctx->r4;
    // 0x8001EF64: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001EF68: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8001EF6C: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x8001EF70: slt         $v0, $t0, $t4
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001EF74: bne         $v0, $zero, L_8001EF5C
    if (ctx->r2 != 0) {
        // 0x8001EF78: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_8001EF5C;
    }
    // 0x8001EF78: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_8001EF7C:
    // 0x8001EF7C: slt         $v0, $t0, $t5
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8001EF80: beql        $v0, $zero, L_8001EFAC
    if (ctx->r2 == 0) {
        // 0x8001EF84: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_8001EFAC;
    }
    goto skip_2;
    // 0x8001EF84: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_2:
    // 0x8001EF88: srl         $v1, $t6, 1
    ctx->r3 = S32(U32(ctx->r14) >> 1);
    // 0x8001EF8C: xor         $v0, $t0, $a0
    ctx->r2 = ctx->r8 ^ ctx->r4;
L_8001EF90:
    // 0x8001EF90: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8001EF94: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8001EF98: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001EF9C: slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001EFA0: bne         $v0, $zero, L_8001EF90
    if (ctx->r2 != 0) {
        // 0x8001EFA4: xor         $v0, $t0, $a0
        ctx->r2 = ctx->r8 ^ ctx->r4;
            goto L_8001EF90;
    }
    // 0x8001EFA4: xor         $v0, $t0, $a0
    ctx->r2 = ctx->r8 ^ ctx->r4;
    // 0x8001EFA8: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_8001EFAC:
    // 0x8001EFAC: slt         $v0, $t2, $s1
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8001EFB0: bne         $v0, $zero, L_8001EF44
    if (ctx->r2 != 0) {
        // 0x8001EFB4: addu        $t3, $t3, $t5
        ctx->r11 = ADD32(ctx->r11, ctx->r13);
            goto L_8001EF44;
    }
    // 0x8001EFB4: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
L_8001EFB8:
    // 0x8001EFB8: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x8001EFBC: srl         $a2, $v0, 1
    ctx->r6 = S32(U32(ctx->r2) >> 1);
    // 0x8001EFC0: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x8001EFC4: srl         $a3, $v0, 1
    ctx->r7 = S32(U32(ctx->r2) >> 1);
    // 0x8001EFC8: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x8001EFCC: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x8001EFD0: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x8001EFD4: and         $s0, $v0, $s5
    ctx->r16 = ctx->r2 & ctx->r21;
    // 0x8001EFD8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8001EFDC: slt         $v0, $s4, $s3
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8001EFE0: bne         $v0, $zero, L_8001EF1C
    if (ctx->r2 != 0) {
        // 0x8001EFE4: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8001EF1C;
    }
    // 0x8001EFE4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8001EFE8: j           L_8001F920
    // 0x8001EFEC: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
        goto L_8001F920;
    // 0x8001EFEC: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
L_8001EFF0:
    // 0x8001EFF0: andi        $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 & 0X8000;
    // 0x8001EFF4: beq         $v0, $zero, L_8001F0F0
    if (ctx->r2 == 0) {
        // 0x8001EFF8: addiu       $v0, $a2, 0x3
        ctx->r2 = ADD32(ctx->r6, 0X3);
            goto L_8001F0F0;
    }
    // 0x8001EFF8: addiu       $v0, $a2, 0x3
    ctx->r2 = ADD32(ctx->r6, 0X3);
    // 0x8001EFFC: andi        $s0, $v0, 0xFFFC
    ctx->r16 = ctx->r2 & 0XFFFC;
    // 0x8001F000: andi        $v0, $t9, 0xFF
    ctx->r2 = ctx->r25 & 0XFF;
    // 0x8001F004: blez        $v0, L_8001F91C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001F008: addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
            goto L_8001F91C;
    }
    // 0x8001F008: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x8001F00C: addiu       $s2, $zero, -0x4
    ctx->r18 = ADD32(0, -0X4);
    // 0x8001F010: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8001F014: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
L_8001F018:
    // 0x8001F018: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x8001F01C: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x8001F020: blez        $v0, L_8001F0B8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001F024: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_8001F0B8;
    }
    // 0x8001F024: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8001F028: andi        $t4, $a2, 0xFFFF
    ctx->r12 = ctx->r6 & 0XFFFF;
    // 0x8001F02C: andi        $t5, $s0, 0xFFFF
    ctx->r13 = ctx->r16 & 0XFFFF;
    // 0x8001F030: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x8001F034: addu        $t6, $v0, $zero
    ctx->r14 = ADD32(ctx->r2, 0);
L_8001F038:
    // 0x8001F038: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8001F03C: andi        $v0, $t2, 0x1
    ctx->r2 = ctx->r10 & 0X1;
    // 0x8001F040: beq         $t4, $zero, L_8001F078
    if (ctx->r12 == 0) {
        // 0x8001F044: sll         $a0, $v0, 1
        ctx->r4 = S32(ctx->r2 << 1);
            goto L_8001F078;
    }
    // 0x8001F044: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
L_8001F048:
    // 0x8001F048: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x8001F04C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001F050: xor         $v0, $t0, $a0
    ctx->r2 = ctx->r8 ^ ctx->r4;
    // 0x8001F054: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001F058: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8001F05C: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x8001F060: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x8001F064: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001F068: sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
    // 0x8001F06C: slt         $v0, $t0, $t4
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001F070: bne         $v0, $zero, L_8001F048
    if (ctx->r2 != 0) {
        // 0x8001F074: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_8001F048;
    }
    // 0x8001F074: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_8001F078:
    // 0x8001F078: addu        $v1, $t5, $zero
    ctx->r3 = ADD32(ctx->r13, 0);
    // 0x8001F07C: slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001F080: beql        $v0, $zero, L_8001F0AC
    if (ctx->r2 == 0) {
        // 0x8001F084: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_8001F0AC;
    }
    goto skip_3;
    // 0x8001F084: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_3:
    // 0x8001F088: xor         $v0, $t0, $a0
    ctx->r2 = ctx->r8 ^ ctx->r4;
L_8001F08C:
    // 0x8001F08C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001F090: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8001F094: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x8001F098: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001F09C: slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001F0A0: bne         $v0, $zero, L_8001F08C
    if (ctx->r2 != 0) {
        // 0x8001F0A4: xor         $v0, $t0, $a0
        ctx->r2 = ctx->r8 ^ ctx->r4;
            goto L_8001F08C;
    }
    // 0x8001F0A4: xor         $v0, $t0, $a0
    ctx->r2 = ctx->r8 ^ ctx->r4;
    // 0x8001F0A8: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_8001F0AC:
    // 0x8001F0AC: slt         $v0, $t2, $t6
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001F0B0: bne         $v0, $zero, L_8001F038
    if (ctx->r2 != 0) {
        // 0x8001F0B4: addu        $t3, $t3, $t7
        ctx->r11 = ADD32(ctx->r11, ctx->r15);
            goto L_8001F038;
    }
    // 0x8001F0B4: addu        $t3, $t3, $t7
    ctx->r11 = ADD32(ctx->r11, ctx->r15);
L_8001F0B8:
    // 0x8001F0B8: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x8001F0BC: srl         $a2, $v0, 1
    ctx->r6 = S32(U32(ctx->r2) >> 1);
    // 0x8001F0C0: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x8001F0C4: srl         $a3, $v0, 1
    ctx->r7 = S32(U32(ctx->r2) >> 1);
    // 0x8001F0C8: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x8001F0CC: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x8001F0D0: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x8001F0D4: and         $s0, $v0, $s2
    ctx->r16 = ctx->r2 & ctx->r18;
    // 0x8001F0D8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8001F0DC: slt         $v0, $s4, $s1
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8001F0E0: bne         $v0, $zero, L_8001F018
    if (ctx->r2 != 0) {
        // 0x8001F0E4: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8001F018;
    }
    // 0x8001F0E4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8001F0E8: j           L_8001F920
    // 0x8001F0EC: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
        goto L_8001F920;
    // 0x8001F0EC: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
L_8001F0F0:
    // 0x8001F0F0: andi        $v0, $v1, 0x4000
    ctx->r2 = ctx->r3 & 0X4000;
    // 0x8001F0F4: beq         $v0, $zero, L_8001F1F4
    if (ctx->r2 == 0) {
        // 0x8001F0F8: addiu       $v0, $a2, 0x3
        ctx->r2 = ADD32(ctx->r6, 0X3);
            goto L_8001F1F4;
    }
    // 0x8001F0F8: addiu       $v0, $a2, 0x3
    ctx->r2 = ADD32(ctx->r6, 0X3);
    // 0x8001F0FC: andi        $s0, $v0, 0xFFFC
    ctx->r16 = ctx->r2 & 0XFFFC;
    // 0x8001F100: lbu         $v0, 0x0($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X0);
    // 0x8001F104: beq         $t9, $zero, L_8001F91C
    if (ctx->r25 == 0) {
        // 0x8001F108: addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
            goto L_8001F91C;
    }
    // 0x8001F108: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x8001F10C: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x8001F110: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
L_8001F114:
    // 0x8001F114: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x8001F118: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x8001F11C: blez        $v0, L_8001F1BC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001F120: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_8001F1BC;
    }
    // 0x8001F120: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8001F124: andi        $t4, $a2, 0xFFFF
    ctx->r12 = ctx->r6 & 0XFFFF;
    // 0x8001F128: andi        $t5, $s0, 0xFFFF
    ctx->r13 = ctx->r16 & 0XFFFF;
    // 0x8001F12C: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x8001F130: addu        $t6, $v0, $zero
    ctx->r14 = ADD32(ctx->r2, 0);
L_8001F134:
    // 0x8001F134: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8001F138: andi        $v0, $t2, 0x1
    ctx->r2 = ctx->r10 & 0X1;
    // 0x8001F13C: beq         $t4, $zero, L_8001F17C
    if (ctx->r12 == 0) {
        // 0x8001F140: sll         $a0, $v0, 1
        ctx->r4 = S32(ctx->r2 << 1);
            goto L_8001F17C;
    }
    // 0x8001F140: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
L_8001F144:
    // 0x8001F144: xor         $v1, $t0, $a0
    ctx->r3 = ctx->r8 ^ ctx->r4;
    // 0x8001F148: lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X0);
    // 0x8001F14C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8001F150: addu        $v1, $t3, $v1
    ctx->r3 = ADD32(ctx->r11, ctx->r3);
    // 0x8001F154: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8001F158: lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X0);
    // 0x8001F15C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001F160: xor         $v0, $s1, $v0
    ctx->r2 = ctx->r17 ^ ctx->r2;
    // 0x8001F164: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8001F168: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8001F16C: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // 0x8001F170: slt         $v0, $t0, $t4
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001F174: bne         $v0, $zero, L_8001F144
    if (ctx->r2 != 0) {
        // 0x8001F178: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_8001F144;
    }
    // 0x8001F178: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_8001F17C:
    // 0x8001F17C: addu        $v1, $t5, $zero
    ctx->r3 = ADD32(ctx->r13, 0);
    // 0x8001F180: slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001F184: beql        $v0, $zero, L_8001F1B0
    if (ctx->r2 == 0) {
        // 0x8001F188: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_8001F1B0;
    }
    goto skip_4;
    // 0x8001F188: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_4:
    // 0x8001F18C: xor         $v0, $t0, $a0
    ctx->r2 = ctx->r8 ^ ctx->r4;
L_8001F190:
    // 0x8001F190: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001F194: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8001F198: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x8001F19C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001F1A0: slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001F1A4: bne         $v0, $zero, L_8001F190
    if (ctx->r2 != 0) {
        // 0x8001F1A8: xor         $v0, $t0, $a0
        ctx->r2 = ctx->r8 ^ ctx->r4;
            goto L_8001F190;
    }
    // 0x8001F1A8: xor         $v0, $t0, $a0
    ctx->r2 = ctx->r8 ^ ctx->r4;
    // 0x8001F1AC: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_8001F1B0:
    // 0x8001F1B0: slt         $v0, $t2, $t6
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001F1B4: bne         $v0, $zero, L_8001F134
    if (ctx->r2 != 0) {
        // 0x8001F1B8: addu        $t3, $t3, $t7
        ctx->r11 = ADD32(ctx->r11, ctx->r15);
            goto L_8001F134;
    }
    // 0x8001F1B8: addu        $t3, $t3, $t7
    ctx->r11 = ADD32(ctx->r11, ctx->r15);
L_8001F1BC:
    // 0x8001F1BC: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x8001F1C0: srl         $a2, $v0, 1
    ctx->r6 = S32(U32(ctx->r2) >> 1);
    // 0x8001F1C4: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x8001F1C8: srl         $a3, $v0, 1
    ctx->r7 = S32(U32(ctx->r2) >> 1);
    // 0x8001F1CC: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x8001F1D0: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x8001F1D4: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x8001F1D8: andi        $s0, $v0, 0xFFFC
    ctx->r16 = ctx->r2 & 0XFFFC;
    // 0x8001F1DC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8001F1E0: slt         $v0, $s4, $t9
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001F1E4: bne         $v0, $zero, L_8001F114
    if (ctx->r2 != 0) {
        // 0x8001F1E8: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8001F114;
    }
    // 0x8001F1E8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8001F1EC: j           L_8001F920
    // 0x8001F1F0: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
        goto L_8001F920;
    // 0x8001F1F0: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
L_8001F1F4:
    // 0x8001F1F4: addiu       $v0, $a2, 0x7
    ctx->r2 = ADD32(ctx->r6, 0X7);
    // 0x8001F1F8: andi        $s0, $v0, 0xFFF8
    ctx->r16 = ctx->r2 & 0XFFF8;
    // 0x8001F1FC: andi        $v0, $t9, 0xFF
    ctx->r2 = ctx->r25 & 0XFF;
    // 0x8001F200: blez        $v0, L_8001F91C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001F204: addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
            goto L_8001F91C;
    }
    // 0x8001F204: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x8001F208: addiu       $s1, $zero, -0x8
    ctx->r17 = ADD32(0, -0X8);
    // 0x8001F20C: addu        $t7, $v0, $zero
    ctx->r15 = ADD32(ctx->r2, 0);
    // 0x8001F210: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
L_8001F214:
    // 0x8001F214: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x8001F218: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x8001F21C: blez        $v0, L_8001F298
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001F220: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_8001F298;
    }
    // 0x8001F220: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8001F224: andi        $t5, $a2, 0xFFFF
    ctx->r13 = ctx->r6 & 0XFFFF;
    // 0x8001F228: andi        $t4, $s0, 0xFFFF
    ctx->r12 = ctx->r16 & 0XFFFF;
    // 0x8001F22C: addu        $t6, $v0, $zero
    ctx->r14 = ADD32(ctx->r2, 0);
L_8001F230:
    // 0x8001F230: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8001F234: andi        $v0, $t2, 0x1
    ctx->r2 = ctx->r10 & 0X1;
    // 0x8001F238: beq         $t5, $zero, L_8001F260
    if (ctx->r13 == 0) {
        // 0x8001F23C: sll         $a0, $v0, 2
        ctx->r4 = S32(ctx->r2 << 2);
            goto L_8001F260;
    }
    // 0x8001F23C: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
L_8001F240:
    // 0x8001F240: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x8001F244: xor         $v0, $t0, $a0
    ctx->r2 = ctx->r8 ^ ctx->r4;
    // 0x8001F248: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001F24C: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8001F250: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x8001F254: slt         $v0, $t0, $t5
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8001F258: bne         $v0, $zero, L_8001F240
    if (ctx->r2 != 0) {
        // 0x8001F25C: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_8001F240;
    }
    // 0x8001F25C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_8001F260:
    // 0x8001F260: slt         $v0, $t0, $t4
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001F264: beq         $v0, $zero, L_8001F288
    if (ctx->r2 == 0) {
        // 0x8001F268: addu        $v1, $t4, $zero
        ctx->r3 = ADD32(ctx->r12, 0);
            goto L_8001F288;
    }
    // 0x8001F268: addu        $v1, $t4, $zero
    ctx->r3 = ADD32(ctx->r12, 0);
    // 0x8001F26C: xor         $v0, $t0, $a0
    ctx->r2 = ctx->r8 ^ ctx->r4;
L_8001F270:
    // 0x8001F270: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8001F274: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8001F278: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001F27C: slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001F280: bne         $v0, $zero, L_8001F270
    if (ctx->r2 != 0) {
        // 0x8001F284: xor         $v0, $t0, $a0
        ctx->r2 = ctx->r8 ^ ctx->r4;
            goto L_8001F270;
    }
    // 0x8001F284: xor         $v0, $t0, $a0
    ctx->r2 = ctx->r8 ^ ctx->r4;
L_8001F288:
    // 0x8001F288: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8001F28C: slt         $v0, $t2, $t6
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001F290: bne         $v0, $zero, L_8001F230
    if (ctx->r2 != 0) {
        // 0x8001F294: addu        $t3, $t3, $t4
        ctx->r11 = ADD32(ctx->r11, ctx->r12);
            goto L_8001F230;
    }
    // 0x8001F294: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
L_8001F298:
    // 0x8001F298: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x8001F29C: srl         $a2, $v0, 1
    ctx->r6 = S32(U32(ctx->r2) >> 1);
    // 0x8001F2A0: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x8001F2A4: srl         $a3, $v0, 1
    ctx->r7 = S32(U32(ctx->r2) >> 1);
    // 0x8001F2A8: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x8001F2AC: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x8001F2B0: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // 0x8001F2B4: and         $s0, $v0, $s1
    ctx->r16 = ctx->r2 & ctx->r17;
    // 0x8001F2B8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8001F2BC: slt         $v0, $s4, $t7
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001F2C0: bne         $v0, $zero, L_8001F214
    if (ctx->r2 != 0) {
        // 0x8001F2C4: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8001F214;
    }
    // 0x8001F2C4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8001F2C8: j           L_8001F920
    // 0x8001F2CC: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
        goto L_8001F920;
    // 0x8001F2CC: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
L_8001F2D0:
    // 0x8001F2D0: addiu       $v0, $a2, 0x7
    ctx->r2 = ADD32(ctx->r6, 0X7);
    // 0x8001F2D4: andi        $s0, $v0, 0xFFF8
    ctx->r16 = ctx->r2 & 0XFFF8;
    // 0x8001F2D8: andi        $v0, $t9, 0xFF
    ctx->r2 = ctx->r25 & 0XFF;
    // 0x8001F2DC: blez        $v0, L_8001F91C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001F2E0: addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
            goto L_8001F91C;
    }
    // 0x8001F2E0: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x8001F2E4: addiu       $s1, $zero, -0x8
    ctx->r17 = ADD32(0, -0X8);
    // 0x8001F2E8: addu        $t7, $v0, $zero
    ctx->r15 = ADD32(ctx->r2, 0);
    // 0x8001F2EC: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
L_8001F2F0:
    // 0x8001F2F0: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x8001F2F4: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x8001F2F8: blez        $v0, L_8001F374
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001F2FC: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_8001F374;
    }
    // 0x8001F2FC: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8001F300: andi        $t5, $a2, 0xFFFF
    ctx->r13 = ctx->r6 & 0XFFFF;
    // 0x8001F304: andi        $t4, $s0, 0xFFFF
    ctx->r12 = ctx->r16 & 0XFFFF;
    // 0x8001F308: addu        $t6, $v0, $zero
    ctx->r14 = ADD32(ctx->r2, 0);
L_8001F30C:
    // 0x8001F30C: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8001F310: andi        $v0, $t2, 0x1
    ctx->r2 = ctx->r10 & 0X1;
    // 0x8001F314: beq         $t5, $zero, L_8001F33C
    if (ctx->r13 == 0) {
        // 0x8001F318: sll         $a0, $v0, 2
        ctx->r4 = S32(ctx->r2 << 2);
            goto L_8001F33C;
    }
    // 0x8001F318: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
L_8001F31C:
    // 0x8001F31C: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x8001F320: xor         $v0, $t0, $a0
    ctx->r2 = ctx->r8 ^ ctx->r4;
    // 0x8001F324: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001F328: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8001F32C: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x8001F330: slt         $v0, $t0, $t5
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8001F334: bne         $v0, $zero, L_8001F31C
    if (ctx->r2 != 0) {
        // 0x8001F338: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_8001F31C;
    }
    // 0x8001F338: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_8001F33C:
    // 0x8001F33C: slt         $v0, $t0, $t4
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001F340: beq         $v0, $zero, L_8001F364
    if (ctx->r2 == 0) {
        // 0x8001F344: addu        $v1, $t4, $zero
        ctx->r3 = ADD32(ctx->r12, 0);
            goto L_8001F364;
    }
    // 0x8001F344: addu        $v1, $t4, $zero
    ctx->r3 = ADD32(ctx->r12, 0);
    // 0x8001F348: xor         $v0, $t0, $a0
    ctx->r2 = ctx->r8 ^ ctx->r4;
L_8001F34C:
    // 0x8001F34C: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8001F350: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8001F354: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001F358: slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001F35C: bne         $v0, $zero, L_8001F34C
    if (ctx->r2 != 0) {
        // 0x8001F360: xor         $v0, $t0, $a0
        ctx->r2 = ctx->r8 ^ ctx->r4;
            goto L_8001F34C;
    }
    // 0x8001F360: xor         $v0, $t0, $a0
    ctx->r2 = ctx->r8 ^ ctx->r4;
L_8001F364:
    // 0x8001F364: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8001F368: slt         $v0, $t2, $t6
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001F36C: bne         $v0, $zero, L_8001F30C
    if (ctx->r2 != 0) {
        // 0x8001F370: addu        $t3, $t3, $t4
        ctx->r11 = ADD32(ctx->r11, ctx->r12);
            goto L_8001F30C;
    }
    // 0x8001F370: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
L_8001F374:
    // 0x8001F374: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x8001F378: srl         $a2, $v0, 1
    ctx->r6 = S32(U32(ctx->r2) >> 1);
    // 0x8001F37C: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x8001F380: srl         $a3, $v0, 1
    ctx->r7 = S32(U32(ctx->r2) >> 1);
    // 0x8001F384: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x8001F388: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x8001F38C: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // 0x8001F390: and         $s0, $v0, $s1
    ctx->r16 = ctx->r2 & ctx->r17;
    // 0x8001F394: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8001F398: slt         $v0, $s4, $t7
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001F39C: bne         $v0, $zero, L_8001F2F0
    if (ctx->r2 != 0) {
        // 0x8001F3A0: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8001F2F0;
    }
    // 0x8001F3A0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8001F3A4: j           L_8001F920
    // 0x8001F3A8: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
        goto L_8001F920;
    // 0x8001F3A8: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
L_8001F3AC:
    // 0x8001F3AC: addiu       $v0, $a2, 0x3
    ctx->r2 = ADD32(ctx->r6, 0X3);
    // 0x8001F3B0: andi        $s0, $v0, 0xFFFC
    ctx->r16 = ctx->r2 & 0XFFFC;
    // 0x8001F3B4: beq         $t9, $zero, L_8001F91C
    if (ctx->r25 == 0) {
        // 0x8001F3B8: addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
            goto L_8001F91C;
    }
    // 0x8001F3B8: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x8001F3BC: andi        $t8, $v1, 0x8000
    ctx->r24 = ctx->r3 & 0X8000;
    // 0x8001F3C0: andi        $s5, $v1, 0x4000
    ctx->r21 = ctx->r3 & 0X4000;
    // 0x8001F3C4: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
L_8001F3C8:
    // 0x8001F3C8: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x8001F3CC: beq         $t8, $zero, L_8001F480
    if (ctx->r24 == 0) {
        // 0x8001F3D0: andi        $v0, $a3, 0xFFFF
        ctx->r2 = ctx->r7 & 0XFFFF;
            goto L_8001F480;
    }
    // 0x8001F3D0: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x8001F3D4: blez        $v0, L_8001F628
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001F3D8: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_8001F628;
    }
    // 0x8001F3D8: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8001F3DC: andi        $t6, $a2, 0xFFFF
    ctx->r14 = ctx->r6 & 0XFFFF;
    // 0x8001F3E0: andi        $t7, $s0, 0xFFFF
    ctx->r15 = ctx->r16 & 0XFFFF;
    // 0x8001F3E4: sll         $s2, $t7, 1
    ctx->r18 = S32(ctx->r15 << 1);
    // 0x8001F3E8: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_8001F3EC:
    // 0x8001F3EC: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8001F3F0: andi        $v0, $t2, 0x1
    ctx->r2 = ctx->r10 & 0X1;
    // 0x8001F3F4: beq         $t6, $zero, L_8001F438
    if (ctx->r14 == 0) {
        // 0x8001F3F8: sll         $t5, $v0, 1
        ctx->r13 = S32(ctx->r2 << 1);
            goto L_8001F438;
    }
    // 0x8001F3F8: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
L_8001F3FC:
    // 0x8001F3FC: xor         $a0, $t0, $t5
    ctx->r4 = ctx->r8 ^ ctx->r13;
    // 0x8001F400: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001F404: lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X0);
    // 0x8001F408: lbu         $v1, 0x1($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X1);
    // 0x8001F40C: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x8001F410: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x8001F414: addu        $a0, $t3, $a0
    ctx->r4 = ADD32(ctx->r11, ctx->r4);
    // 0x8001F418: srl         $a1, $v0, 7
    ctx->r5 = S32(U32(ctx->r2) >> 7);
    // 0x8001F41C: sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2 << 9);
    // 0x8001F420: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8001F424: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8001F428: or          $t4, $a1, $v0
    ctx->r12 = ctx->r5 | ctx->r2;
    // 0x8001F42C: slt         $v0, $t0, $t6
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001F430: bne         $v0, $zero, L_8001F3FC
    if (ctx->r2 != 0) {
        // 0x8001F434: sh          $t4, 0x0($a0)
        MEM_H(0X0, ctx->r4) = ctx->r12;
            goto L_8001F3FC;
    }
    // 0x8001F434: sh          $t4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r12;
L_8001F438:
    // 0x8001F438: addu        $v1, $t7, $zero
    ctx->r3 = ADD32(ctx->r15, 0);
    // 0x8001F43C: slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001F440: beql        $v0, $zero, L_8001F46C
    if (ctx->r2 == 0) {
        // 0x8001F444: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_8001F46C;
    }
    goto skip_5;
    // 0x8001F444: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_5:
    // 0x8001F448: xor         $v0, $t0, $t5
    ctx->r2 = ctx->r8 ^ ctx->r13;
L_8001F44C:
    // 0x8001F44C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001F450: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8001F454: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
    // 0x8001F458: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001F45C: slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001F460: bne         $v0, $zero, L_8001F44C
    if (ctx->r2 != 0) {
        // 0x8001F464: xor         $v0, $t0, $t5
        ctx->r2 = ctx->r8 ^ ctx->r13;
            goto L_8001F44C;
    }
    // 0x8001F464: xor         $v0, $t0, $t5
    ctx->r2 = ctx->r8 ^ ctx->r13;
    // 0x8001F468: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_8001F46C:
    // 0x8001F46C: slt         $v0, $t2, $s1
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8001F470: bne         $v0, $zero, L_8001F3EC
    if (ctx->r2 != 0) {
        // 0x8001F474: addu        $t3, $t3, $s2
        ctx->r11 = ADD32(ctx->r11, ctx->r18);
            goto L_8001F3EC;
    }
    // 0x8001F474: addu        $t3, $t3, $s2
    ctx->r11 = ADD32(ctx->r11, ctx->r18);
    // 0x8001F478: j           L_8001F62C
    // 0x8001F47C: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
        goto L_8001F62C;
    // 0x8001F47C: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
L_8001F480:
    // 0x8001F480: beql        $s5, $zero, L_8001F588
    if (ctx->r21 == 0) {
        // 0x8001F484: andi        $v0, $a3, 0xFFFF
        ctx->r2 = ctx->r7 & 0XFFFF;
            goto L_8001F588;
    }
    goto skip_6;
    // 0x8001F484: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    skip_6:
    // 0x8001F488: lbu         $a0, 0x0($s6)
    ctx->r4 = MEM_BU(ctx->r22, 0X0);
    // 0x8001F48C: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8001F490: lbu         $v1, 0x1($s6)
    ctx->r3 = MEM_BU(ctx->r22, 0X1);
    // 0x8001F494: lbu         $v0, 0x2($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X2);
    // 0x8001F498: sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4 << 8);
    // 0x8001F49C: andi        $a0, $a0, 0xF800
    ctx->r4 = ctx->r4 & 0XF800;
    // 0x8001F4A0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8001F4A4: andi        $v1, $v1, 0x7C0
    ctx->r3 = ctx->r3 & 0X7C0;
    // 0x8001F4A8: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x8001F4AC: srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // 0x8001F4B0: andi        $v0, $v0, 0x3E
    ctx->r2 = ctx->r2 & 0X3E;
    // 0x8001F4B4: andi        $v1, $a3, 0xFFFF
    ctx->r3 = ctx->r7 & 0XFFFF;
    // 0x8001F4B8: blez        $v1, L_8001F628
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001F4BC: or          $v0, $v0, $a0
        ctx->r2 = ctx->r2 | ctx->r4;
            goto L_8001F628;
    }
    // 0x8001F4BC: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x8001F4C0: andi        $t6, $a2, 0xFFFF
    ctx->r14 = ctx->r6 & 0XFFFF;
    // 0x8001F4C4: andi        $t5, $v0, 0xFFFF
    ctx->r13 = ctx->r2 & 0XFFFF;
    // 0x8001F4C8: andi        $t7, $s0, 0xFFFF
    ctx->r15 = ctx->r16 & 0XFFFF;
    // 0x8001F4CC: sll         $s2, $t7, 1
    ctx->r18 = S32(ctx->r15 << 1);
    // 0x8001F4D0: addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
L_8001F4D4:
    // 0x8001F4D4: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8001F4D8: andi        $v0, $t2, 0x1
    ctx->r2 = ctx->r10 & 0X1;
    // 0x8001F4DC: beq         $t6, $zero, L_8001F52C
    if (ctx->r14 == 0) {
        // 0x8001F4E0: sll         $a1, $v0, 1
        ctx->r5 = S32(ctx->r2 << 1);
            goto L_8001F52C;
    }
    // 0x8001F4E0: sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2 << 1);
L_8001F4E4:
    // 0x8001F4E4: xor         $a0, $t0, $a1
    ctx->r4 = ctx->r8 ^ ctx->r5;
    // 0x8001F4E8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001F4EC: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x8001F4F0: lbu         $v0, 0x1($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X1);
    // 0x8001F4F4: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x8001F4F8: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x8001F4FC: addu        $a0, $t3, $a0
    ctx->r4 = ADD32(ctx->r11, ctx->r4);
    // 0x8001F500: sll         $v1, $v1, 9
    ctx->r3 = S32(ctx->r3 << 9);
    // 0x8001F504: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001F508: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8001F50C: addu        $t4, $v1, $zero
    ctx->r12 = ADD32(ctx->r3, 0);
    // 0x8001F510: andi        $v0, $t4, 0xFFFF
    ctx->r2 = ctx->r12 & 0XFFFF;
    // 0x8001F514: xor         $v0, $v0, $t5
    ctx->r2 = ctx->r2 ^ ctx->r13;
    // 0x8001F518: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8001F51C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8001F520: slt         $v0, $t0, $t6
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001F524: bne         $v0, $zero, L_8001F4E4
    if (ctx->r2 != 0) {
        // 0x8001F528: sh          $v1, 0x0($a0)
        MEM_H(0X0, ctx->r4) = ctx->r3;
            goto L_8001F4E4;
    }
    // 0x8001F528: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
L_8001F52C:
    // 0x8001F52C: andi        $v0, $t4, 0xFFFF
    ctx->r2 = ctx->r12 & 0XFFFF;
    // 0x8001F530: bne         $v0, $t5, L_8001F53C
    if (ctx->r2 != ctx->r13) {
        // 0x8001F534: ori         $v0, $t4, 0x1
        ctx->r2 = ctx->r12 | 0X1;
            goto L_8001F53C;
    }
    // 0x8001F534: ori         $v0, $t4, 0x1
    ctx->r2 = ctx->r12 | 0X1;
    // 0x8001F538: addu        $v0, $t4, $zero
    ctx->r2 = ADD32(ctx->r12, 0);
L_8001F53C:
    // 0x8001F53C: addu        $t4, $v0, $zero
    ctx->r12 = ADD32(ctx->r2, 0);
    // 0x8001F540: addu        $v1, $t7, $zero
    ctx->r3 = ADD32(ctx->r15, 0);
    // 0x8001F544: slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001F548: beql        $v0, $zero, L_8001F574
    if (ctx->r2 == 0) {
        // 0x8001F54C: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_8001F574;
    }
    goto skip_7;
    // 0x8001F54C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_7:
    // 0x8001F550: xor         $v0, $t0, $a1
    ctx->r2 = ctx->r8 ^ ctx->r5;
L_8001F554:
    // 0x8001F554: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001F558: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8001F55C: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
    // 0x8001F560: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001F564: slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001F568: bne         $v0, $zero, L_8001F554
    if (ctx->r2 != 0) {
        // 0x8001F56C: xor         $v0, $t0, $a1
        ctx->r2 = ctx->r8 ^ ctx->r5;
            goto L_8001F554;
    }
    // 0x8001F56C: xor         $v0, $t0, $a1
    ctx->r2 = ctx->r8 ^ ctx->r5;
    // 0x8001F570: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_8001F574:
    // 0x8001F574: slt         $v0, $t2, $s1
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8001F578: bne         $v0, $zero, L_8001F4D4
    if (ctx->r2 != 0) {
        // 0x8001F57C: addu        $t3, $t3, $s2
        ctx->r11 = ADD32(ctx->r11, ctx->r18);
            goto L_8001F4D4;
    }
    // 0x8001F57C: addu        $t3, $t3, $s2
    ctx->r11 = ADD32(ctx->r11, ctx->r18);
    // 0x8001F580: j           L_8001F62C
    // 0x8001F584: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
        goto L_8001F62C;
    // 0x8001F584: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
L_8001F588:
    // 0x8001F588: blez        $v0, L_8001F628
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001F58C: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_8001F628;
    }
    // 0x8001F58C: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8001F590: andi        $t5, $a2, 0xFFFF
    ctx->r13 = ctx->r6 & 0XFFFF;
    // 0x8001F594: andi        $t6, $s0, 0xFFFF
    ctx->r14 = ctx->r16 & 0XFFFF;
    // 0x8001F598: sll         $s1, $t6, 1
    ctx->r17 = S32(ctx->r14 << 1);
    // 0x8001F59C: addu        $t7, $v0, $zero
    ctx->r15 = ADD32(ctx->r2, 0);
L_8001F5A0:
    // 0x8001F5A0: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8001F5A4: andi        $v0, $t2, 0x1
    ctx->r2 = ctx->r10 & 0X1;
    // 0x8001F5A8: beq         $t5, $zero, L_8001F5E8
    if (ctx->r13 == 0) {
        // 0x8001F5AC: sll         $a1, $v0, 1
        ctx->r5 = S32(ctx->r2 << 1);
            goto L_8001F5E8;
    }
    // 0x8001F5AC: sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2 << 1);
L_8001F5B0:
    // 0x8001F5B0: xor         $a0, $t0, $a1
    ctx->r4 = ctx->r8 ^ ctx->r5;
    // 0x8001F5B4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001F5B8: lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X0);
    // 0x8001F5BC: lbu         $v1, 0x1($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X1);
    // 0x8001F5C0: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x8001F5C4: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x8001F5C8: addu        $a0, $t3, $a0
    ctx->r4 = ADD32(ctx->r11, ctx->r4);
    // 0x8001F5CC: sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2 << 9);
    // 0x8001F5D0: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8001F5D4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8001F5D8: ori         $t4, $v0, 0x1
    ctx->r12 = ctx->r2 | 0X1;
    // 0x8001F5DC: slt         $v0, $t0, $t5
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8001F5E0: bne         $v0, $zero, L_8001F5B0
    if (ctx->r2 != 0) {
        // 0x8001F5E4: sh          $t4, 0x0($a0)
        MEM_H(0X0, ctx->r4) = ctx->r12;
            goto L_8001F5B0;
    }
    // 0x8001F5E4: sh          $t4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r12;
L_8001F5E8:
    // 0x8001F5E8: addu        $v1, $t6, $zero
    ctx->r3 = ADD32(ctx->r14, 0);
    // 0x8001F5EC: slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001F5F0: beql        $v0, $zero, L_8001F61C
    if (ctx->r2 == 0) {
        // 0x8001F5F4: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_8001F61C;
    }
    goto skip_8;
    // 0x8001F5F4: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_8:
    // 0x8001F5F8: xor         $v0, $t0, $a1
    ctx->r2 = ctx->r8 ^ ctx->r5;
L_8001F5FC:
    // 0x8001F5FC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001F600: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8001F604: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
    // 0x8001F608: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001F60C: slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001F610: bne         $v0, $zero, L_8001F5FC
    if (ctx->r2 != 0) {
        // 0x8001F614: xor         $v0, $t0, $a1
        ctx->r2 = ctx->r8 ^ ctx->r5;
            goto L_8001F5FC;
    }
    // 0x8001F614: xor         $v0, $t0, $a1
    ctx->r2 = ctx->r8 ^ ctx->r5;
    // 0x8001F618: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_8001F61C:
    // 0x8001F61C: slt         $v0, $t2, $t7
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001F620: bne         $v0, $zero, L_8001F5A0
    if (ctx->r2 != 0) {
        // 0x8001F624: addu        $t3, $t3, $s1
        ctx->r11 = ADD32(ctx->r11, ctx->r17);
            goto L_8001F5A0;
    }
    // 0x8001F624: addu        $t3, $t3, $s1
    ctx->r11 = ADD32(ctx->r11, ctx->r17);
L_8001F628:
    // 0x8001F628: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
L_8001F62C:
    // 0x8001F62C: srl         $a2, $v0, 1
    ctx->r6 = S32(U32(ctx->r2) >> 1);
    // 0x8001F630: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x8001F634: srl         $a3, $v0, 1
    ctx->r7 = S32(U32(ctx->r2) >> 1);
    // 0x8001F638: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x8001F63C: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x8001F640: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x8001F644: andi        $s0, $v0, 0xFFFC
    ctx->r16 = ctx->r2 & 0XFFFC;
    // 0x8001F648: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8001F64C: slt         $v0, $s4, $t9
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001F650: bne         $v0, $zero, L_8001F3C8
    if (ctx->r2 != 0) {
        // 0x8001F654: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_8001F3C8;
    }
    // 0x8001F654: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8001F658: j           L_8001F920
    // 0x8001F65C: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
        goto L_8001F920;
    // 0x8001F65C: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
L_8001F660:
    // 0x8001F660: addiu       $v0, $a2, 0x3
    ctx->r2 = ADD32(ctx->r6, 0X3);
    // 0x8001F664: andi        $s0, $v0, 0xFFFC
    ctx->r16 = ctx->r2 & 0XFFFC;
    // 0x8001F668: beq         $t9, $zero, L_8001F91C
    if (ctx->r25 == 0) {
        // 0x8001F66C: addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
            goto L_8001F91C;
    }
    // 0x8001F66C: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x8001F670: andi        $fp, $v1, 0x8000
    ctx->r30 = ctx->r3 & 0X8000;
    // 0x8001F674: andi        $s7, $v1, 0x4000
    ctx->r23 = ctx->r3 & 0X4000;
    // 0x8001F678: addiu       $s5, $zero, 0xFF
    ctx->r21 = ADD32(0, 0XFF);
    // 0x8001F67C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
L_8001F680:
    // 0x8001F680: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x8001F684: beq         $fp, $zero, L_8001F744
    if (ctx->r30 == 0) {
        // 0x8001F688: andi        $v0, $a3, 0xFFFF
        ctx->r2 = ctx->r7 & 0XFFFF;
            goto L_8001F744;
    }
    // 0x8001F688: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x8001F68C: blez        $v0, L_8001F8EC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001F690: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_8001F8EC;
    }
    // 0x8001F690: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8001F694: andi        $t4, $a2, 0xFFFF
    ctx->r12 = ctx->r6 & 0XFFFF;
    // 0x8001F698: andi        $t5, $s0, 0xFFFF
    ctx->r13 = ctx->r16 & 0XFFFF;
    // 0x8001F69C: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8001F6A0: addu        $t6, $v0, $zero
    ctx->r14 = ADD32(ctx->r2, 0);
L_8001F6A4:
    // 0x8001F6A4: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8001F6A8: andi        $v0, $t2, 0x1
    ctx->r2 = ctx->r10 & 0X1;
    // 0x8001F6AC: beq         $t4, $zero, L_8001F6FC
    if (ctx->r12 == 0) {
        // 0x8001F6B0: sll         $a0, $v0, 1
        ctx->r4 = S32(ctx->r2 << 1);
            goto L_8001F6FC;
    }
    // 0x8001F6B0: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
L_8001F6B4:
    // 0x8001F6B4: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x8001F6B8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001F6BC: xor         $v0, $t0, $a0
    ctx->r2 = ctx->r8 ^ ctx->r4;
    // 0x8001F6C0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001F6C4: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8001F6C8: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x8001F6CC: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x8001F6D0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001F6D4: sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
    // 0x8001F6D8: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x8001F6DC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001F6E0: sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    // 0x8001F6E4: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x8001F6E8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001F6EC: sb          $v1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r3;
    // 0x8001F6F0: slt         $v0, $t0, $t4
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001F6F4: bne         $v0, $zero, L_8001F6B4
    if (ctx->r2 != 0) {
        // 0x8001F6F8: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_8001F6B4;
    }
    // 0x8001F6F8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_8001F6FC:
    // 0x8001F6FC: addu        $v1, $t5, $zero
    ctx->r3 = ADD32(ctx->r13, 0);
    // 0x8001F700: slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001F704: beql        $v0, $zero, L_8001F730
    if (ctx->r2 == 0) {
        // 0x8001F708: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_8001F730;
    }
    goto skip_9;
    // 0x8001F708: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_9:
    // 0x8001F70C: xor         $v0, $t0, $a0
    ctx->r2 = ctx->r8 ^ ctx->r4;
L_8001F710:
    // 0x8001F710: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001F714: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8001F718: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8001F71C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001F720: slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001F724: bne         $v0, $zero, L_8001F710
    if (ctx->r2 != 0) {
        // 0x8001F728: xor         $v0, $t0, $a0
        ctx->r2 = ctx->r8 ^ ctx->r4;
            goto L_8001F710;
    }
    // 0x8001F728: xor         $v0, $t0, $a0
    ctx->r2 = ctx->r8 ^ ctx->r4;
    // 0x8001F72C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_8001F730:
    // 0x8001F730: slt         $v0, $t2, $t6
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001F734: bne         $v0, $zero, L_8001F6A4
    if (ctx->r2 != 0) {
        // 0x8001F738: addu        $t3, $t3, $t7
        ctx->r11 = ADD32(ctx->r11, ctx->r15);
            goto L_8001F6A4;
    }
    // 0x8001F738: addu        $t3, $t3, $t7
    ctx->r11 = ADD32(ctx->r11, ctx->r15);
    // 0x8001F73C: j           L_8001F8F0
    // 0x8001F740: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
        goto L_8001F8F0;
    // 0x8001F740: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
L_8001F744:
    // 0x8001F744: beql        $s7, $zero, L_8001F844
    if (ctx->r23 == 0) {
        // 0x8001F748: andi        $v0, $a3, 0xFFFF
        ctx->r2 = ctx->r7 & 0XFFFF;
            goto L_8001F844;
    }
    goto skip_10;
    // 0x8001F748: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    skip_10:
    // 0x8001F74C: lbu         $v1, 0x0($s6)
    ctx->r3 = MEM_BU(ctx->r22, 0X0);
    // 0x8001F750: lbu         $a0, 0x1($s6)
    ctx->r4 = MEM_BU(ctx->r22, 0X1);
    // 0x8001F754: lbu         $t0, 0x2($s6)
    ctx->r8 = MEM_BU(ctx->r22, 0X2);
    // 0x8001F758: blez        $v0, L_8001F8EC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001F75C: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_8001F8EC;
    }
    // 0x8001F75C: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8001F760: andi        $t8, $a2, 0xFFFF
    ctx->r24 = ctx->r6 & 0XFFFF;
    // 0x8001F764: andi        $s2, $v1, 0xFF
    ctx->r18 = ctx->r3 & 0XFF;
    // 0x8001F768: andi        $s1, $a0, 0xFF
    ctx->r17 = ctx->r4 & 0XFF;
    // 0x8001F76C: andi        $t7, $t0, 0xFF
    ctx->r15 = ctx->r8 & 0XFF;
    // 0x8001F770: andi        $t6, $s0, 0xFFFF
    ctx->r14 = ctx->r16 & 0XFFFF;
    // 0x8001F774: sll         $s3, $t6, 2
    ctx->r19 = S32(ctx->r14 << 2);
L_8001F778:
    // 0x8001F778: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8001F77C: andi        $v0, $t2, 0x1
    ctx->r2 = ctx->r10 & 0X1;
    // 0x8001F780: beq         $t8, $zero, L_8001F7F8
    if (ctx->r24 == 0) {
        // 0x8001F784: sll         $t4, $v0, 1
        ctx->r12 = S32(ctx->r2 << 1);
            goto L_8001F7F8;
    }
    // 0x8001F784: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x8001F788: andi        $t5, $a2, 0xFFFF
    ctx->r13 = ctx->r6 & 0XFFFF;
L_8001F78C:
    // 0x8001F78C: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x8001F790: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001F794: xor         $v0, $t0, $t4
    ctx->r2 = ctx->r8 ^ ctx->r12;
    // 0x8001F798: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001F79C: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8001F7A0: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x8001F7A4: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x8001F7A8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001F7AC: sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
    // 0x8001F7B0: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x8001F7B4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001F7B8: sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    // 0x8001F7BC: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x8001F7C0: bne         $v1, $s2, L_8001F7E0
    if (ctx->r3 != ctx->r18) {
        // 0x8001F7C4: addiu       $a0, $v0, 0x3
        ctx->r4 = ADD32(ctx->r2, 0X3);
            goto L_8001F7E0;
    }
    // 0x8001F7C4: addiu       $a0, $v0, 0x3
    ctx->r4 = ADD32(ctx->r2, 0X3);
    // 0x8001F7C8: lbu         $v0, 0x1($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X1);
    // 0x8001F7CC: bne         $v0, $s1, L_8001F7E4
    if (ctx->r2 != ctx->r17) {
        // 0x8001F7D0: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8001F7E4;
    }
    // 0x8001F7D0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8001F7D4: lbu         $v0, 0x2($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X2);
    // 0x8001F7D8: beq         $v0, $t7, L_8001F7E4
    if (ctx->r2 == ctx->r15) {
        // 0x8001F7DC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8001F7E4;
    }
    // 0x8001F7DC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8001F7E0:
    // 0x8001F7E0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8001F7E4:
    // 0x8001F7E4: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x8001F7E8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001F7EC: slt         $v0, $t0, $t5
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8001F7F0: bne         $v0, $zero, L_8001F78C
    if (ctx->r2 != 0) {
        // 0x8001F7F4: nop
    
            goto L_8001F78C;
    }
    // 0x8001F7F4: nop

L_8001F7F8:
    // 0x8001F7F8: addu        $v1, $t6, $zero
    ctx->r3 = ADD32(ctx->r14, 0);
    // 0x8001F7FC: slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001F800: beql        $v0, $zero, L_8001F82C
    if (ctx->r2 == 0) {
        // 0x8001F804: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_8001F82C;
    }
    goto skip_11;
    // 0x8001F804: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_11:
    // 0x8001F808: xor         $v0, $t0, $t4
    ctx->r2 = ctx->r8 ^ ctx->r12;
L_8001F80C:
    // 0x8001F80C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001F810: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8001F814: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8001F818: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001F81C: slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001F820: bne         $v0, $zero, L_8001F80C
    if (ctx->r2 != 0) {
        // 0x8001F824: xor         $v0, $t0, $t4
        ctx->r2 = ctx->r8 ^ ctx->r12;
            goto L_8001F80C;
    }
    // 0x8001F824: xor         $v0, $t0, $t4
    ctx->r2 = ctx->r8 ^ ctx->r12;
    // 0x8001F828: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_8001F82C:
    // 0x8001F82C: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x8001F830: slt         $v0, $t2, $v0
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001F834: bne         $v0, $zero, L_8001F778
    if (ctx->r2 != 0) {
        // 0x8001F838: addu        $t3, $t3, $s3
        ctx->r11 = ADD32(ctx->r11, ctx->r19);
            goto L_8001F778;
    }
    // 0x8001F838: addu        $t3, $t3, $s3
    ctx->r11 = ADD32(ctx->r11, ctx->r19);
    // 0x8001F83C: j           L_8001F8F0
    // 0x8001F840: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
        goto L_8001F8F0;
    // 0x8001F840: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
L_8001F844:
    // 0x8001F844: blez        $v0, L_8001F8EC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001F848: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_8001F8EC;
    }
    // 0x8001F848: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8001F84C: andi        $t4, $a2, 0xFFFF
    ctx->r12 = ctx->r6 & 0XFFFF;
    // 0x8001F850: andi        $t5, $s0, 0xFFFF
    ctx->r13 = ctx->r16 & 0XFFFF;
    // 0x8001F854: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8001F858: addu        $t6, $v0, $zero
    ctx->r14 = ADD32(ctx->r2, 0);
L_8001F85C:
    // 0x8001F85C: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8001F860: andi        $v0, $t2, 0x1
    ctx->r2 = ctx->r10 & 0X1;
    // 0x8001F864: beq         $t4, $zero, L_8001F8AC
    if (ctx->r12 == 0) {
        // 0x8001F868: sll         $a0, $v0, 1
        ctx->r4 = S32(ctx->r2 << 1);
            goto L_8001F8AC;
    }
    // 0x8001F868: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
L_8001F86C:
    // 0x8001F86C: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x8001F870: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001F874: xor         $v0, $t0, $a0
    ctx->r2 = ctx->r8 ^ ctx->r4;
    // 0x8001F878: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001F87C: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8001F880: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x8001F884: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x8001F888: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001F88C: sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
    // 0x8001F890: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x8001F894: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001F898: sb          $s5, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r21;
    // 0x8001F89C: sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    // 0x8001F8A0: slt         $v0, $t0, $t4
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001F8A4: bne         $v0, $zero, L_8001F86C
    if (ctx->r2 != 0) {
        // 0x8001F8A8: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_8001F86C;
    }
    // 0x8001F8A8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_8001F8AC:
    // 0x8001F8AC: addu        $v1, $t5, $zero
    ctx->r3 = ADD32(ctx->r13, 0);
    // 0x8001F8B0: slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001F8B4: beql        $v0, $zero, L_8001F8E0
    if (ctx->r2 == 0) {
        // 0x8001F8B8: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_8001F8E0;
    }
    goto skip_12;
    // 0x8001F8B8: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_12:
    // 0x8001F8BC: xor         $v0, $t0, $a0
    ctx->r2 = ctx->r8 ^ ctx->r4;
L_8001F8C0:
    // 0x8001F8C0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001F8C4: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8001F8C8: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x8001F8CC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001F8D0: slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001F8D4: bne         $v0, $zero, L_8001F8C0
    if (ctx->r2 != 0) {
        // 0x8001F8D8: xor         $v0, $t0, $a0
        ctx->r2 = ctx->r8 ^ ctx->r4;
            goto L_8001F8C0;
    }
    // 0x8001F8D8: xor         $v0, $t0, $a0
    ctx->r2 = ctx->r8 ^ ctx->r4;
    // 0x8001F8DC: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_8001F8E0:
    // 0x8001F8E0: slt         $v0, $t2, $t6
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001F8E4: bne         $v0, $zero, L_8001F85C
    if (ctx->r2 != 0) {
        // 0x8001F8E8: addu        $t3, $t3, $t7
        ctx->r11 = ADD32(ctx->r11, ctx->r15);
            goto L_8001F85C;
    }
    // 0x8001F8E8: addu        $t3, $t3, $t7
    ctx->r11 = ADD32(ctx->r11, ctx->r15);
L_8001F8EC:
    // 0x8001F8EC: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
L_8001F8F0:
    // 0x8001F8F0: srl         $a2, $v0, 1
    ctx->r6 = S32(U32(ctx->r2) >> 1);
    // 0x8001F8F4: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x8001F8F8: srl         $a3, $v0, 1
    ctx->r7 = S32(U32(ctx->r2) >> 1);
    // 0x8001F8FC: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x8001F900: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x8001F904: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x8001F908: andi        $s0, $v0, 0xFFFC
    ctx->r16 = ctx->r2 & 0XFFFC;
    // 0x8001F90C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8001F910: slt         $v0, $s4, $t9
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001F914: bne         $v0, $zero, L_8001F680
    if (ctx->r2 != 0) {
        // 0x8001F918: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8001F680;
    }
    // 0x8001F918: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8001F91C:
    // 0x8001F91C: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
L_8001F920:
    // 0x8001F920: lw          $ra, 0x174($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X174);
    // 0x8001F924: lw          $fp, 0x170($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X170);
    // 0x8001F928: lw          $s7, 0x16C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X16C);
    // 0x8001F92C: lw          $s6, 0x168($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X168);
    // 0x8001F930: lw          $s5, 0x164($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X164);
    // 0x8001F934: lw          $s4, 0x160($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X160);
    // 0x8001F938: lw          $s3, 0x15C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X15C);
    // 0x8001F93C: lw          $s2, 0x158($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X158);
    // 0x8001F940: lw          $s1, 0x154($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X154);
    // 0x8001F944: lw          $s0, 0x150($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X150);
    // 0x8001F948: addiu       $sp, $sp, 0x178
    ctx->r29 = ADD32(ctx->r29, 0X178);
    // 0x8001F94C: jr          $ra
    // 0x8001F950: nop

    return;
    // 0x8001F950: nop

;}
RECOMP_FUNC void func_8001F954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F954: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8001F958: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x8001F95C: lw          $fp, 0x98($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X98);
    // 0x8001F960: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x8001F964: lw          $s1, 0x9C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X9C);
    // 0x8001F968: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x8001F96C: lhu         $s3, 0x8A($sp)
    ctx->r19 = MEM_HU(ctx->r29, 0X8A);
    // 0x8001F970: lhu         $t2, 0x96($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X96);
    // 0x8001F974: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x8001F978: lbu         $s6, 0x93($sp)
    ctx->r22 = MEM_BU(ctx->r29, 0X93);
    // 0x8001F97C: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x8001F980: addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // 0x8001F984: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x8001F988: sh          $t2, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r10;
    // 0x8001F98C: lbu         $t2, 0x8F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X8F);
    // 0x8001F990: lhu         $v1, 0x3E($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X3E);
    // 0x8001F994: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x8001F998: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8001F99C: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x8001F9A0: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x8001F9A4: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x8001F9A8: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x8001F9AC: sh          $a2, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r6;
    // 0x8001F9B0: sh          $a3, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r7;
    // 0x8001F9B4: bne         $v1, $v0, L_8001FA5C
    if (ctx->r3 != ctx->r2) {
        // 0x8001F9B8: sb          $t2, 0x37($sp)
        MEM_B(0X37, ctx->r29) = ctx->r10;
            goto L_8001FA5C;
    }
    // 0x8001F9B8: sb          $t2, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r10;
    // 0x8001F9BC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001F9C0: lhu         $v0, -0x7110($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7110);
    // 0x8001F9C4: blez        $v0, L_8001FA1C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001F9C8: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_8001FA1C;
    }
    // 0x8001F9C8: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8001F9CC: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8001F9D0:
    // 0x8001F9D0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001F9D4: lw          $v0, -0x70F8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X70F8);
    // 0x8001F9D8: addu        $a0, $s0, $v0
    ctx->r4 = ADD32(ctx->r16, ctx->r2);
    // 0x8001F9DC: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8001F9E0: beq         $v0, $zero, L_8001F9FC
    if (ctx->r2 == 0) {
        // 0x8001F9E4: addiu       $a0, $a0, 0x14
        ctx->r4 = ADD32(ctx->r4, 0X14);
            goto L_8001F9FC;
    }
    // 0x8001F9E4: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x8001F9E8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8001F9EC: jal         0x800077A8
    // 0x8001F9F0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    rs_strncmp(rdram, ctx);
        goto after_0;
    // 0x8001F9F0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_0:
    // 0x8001F9F4: beq         $v0, $zero, L_8001FE40
    if (ctx->r2 == 0) {
        // 0x8001F9F8: andi        $v0, $s2, 0xFFFF
        ctx->r2 = ctx->r18 & 0XFFFF;
            goto L_8001FE40;
    }
    // 0x8001F9F8: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
L_8001F9FC:
    // 0x8001F9FC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001FA00: lhu         $v0, -0x7110($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7110);
    // 0x8001FA04: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8001FA08: slt         $v0, $s2, $v0
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001FA0C: bne         $v0, $zero, L_8001F9D0
    if (ctx->r2 != 0) {
        // 0x8001FA10: addiu       $s0, $s0, 0x24
        ctx->r16 = ADD32(ctx->r16, 0X24);
            goto L_8001F9D0;
    }
    // 0x8001FA10: addiu       $s0, $s0, 0x24
    ctx->r16 = ADD32(ctx->r16, 0X24);
    // 0x8001FA14: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001FA18: lhu         $v0, -0x7110($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7110);
L_8001FA1C:
    // 0x8001FA1C: blez        $v0, L_8001FA4C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001FA20: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_8001FA4C;
    }
    // 0x8001FA20: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8001FA24: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8001FA28: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001FA2C: lw          $v1, -0x70F8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X70F8);
L_8001FA30:
    // 0x8001FA30: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8001FA34: beq         $v0, $zero, L_8001FA4C
    if (ctx->r2 == 0) {
        // 0x8001FA38: nop
    
            goto L_8001FA4C;
    }
    // 0x8001FA38: nop

    // 0x8001FA3C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8001FA40: slt         $v0, $s2, $a0
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001FA44: bne         $v0, $zero, L_8001FA30
    if (ctx->r2 != 0) {
        // 0x8001FA48: addiu       $v1, $v1, 0x24
        ctx->r3 = ADD32(ctx->r3, 0X24);
            goto L_8001FA30;
    }
    // 0x8001FA48: addiu       $v1, $v1, 0x24
    ctx->r3 = ADD32(ctx->r3, 0X24);
L_8001FA4C:
    // 0x8001FA4C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8001FA50: lw          $s0, -0x5828($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X5828);
    // 0x8001FA54: j           L_8001FA7C
    // 0x8001FA58: nop

        goto L_8001FA7C;
    // 0x8001FA58: nop

L_8001FA5C:
    // 0x8001FA5C: addu        $s2, $v1, $zero
    ctx->r18 = ADD32(ctx->r3, 0);
    // 0x8001FA60: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001FA64: lw          $v1, -0x70F8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X70F8);
    // 0x8001FA68: sll         $v0, $s2, 3
    ctx->r2 = S32(ctx->r18 << 3);
    // 0x8001FA6C: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8001FA70: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001FA74: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001FA78: lw          $s0, 0x10($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X10);
L_8001FA7C:
    // 0x8001FA7C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001FA80: lhu         $v0, -0x7110($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7110);
    // 0x8001FA84: beq         $s2, $v0, L_8001FE3C
    if (ctx->r18 == ctx->r2) {
        // 0x8001FA88: addu        $a1, $s1, $zero
        ctx->r5 = ADD32(ctx->r17, 0);
            goto L_8001FE3C;
    }
    // 0x8001FA88: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8001FA8C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8001FA90: sll         $v0, $s2, 3
    ctx->r2 = S32(ctx->r18 << 3);
    // 0x8001FA94: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001FA98: lw          $a0, -0x70F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X70F8);
    // 0x8001FA9C: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8001FAA0: sll         $s1, $v0, 2
    ctx->r17 = S32(ctx->r2 << 2);
    // 0x8001FAA4: addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    // 0x8001FAA8: jal         0x80007640
    // 0x8001FAAC: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    rs_strncpy(rdram, ctx);
        goto after_1;
    // 0x8001FAAC: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_1:
    // 0x8001FAB0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001FAB4: lw          $v0, -0x70F8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X70F8);
    // 0x8001FAB8: andi        $s4, $s3, 0xFFFF
    ctx->r20 = ctx->r19 & 0XFFFF;
    // 0x8001FABC: lbu         $t2, 0x37($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X37);
    // 0x8001FAC0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x8001FAC4: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x8001FAC8: jal         0x8001EA50
    // 0x8001FACC: sb          $t2, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r10;
    func_8001EA50(rdram, ctx);
        goto after_2;
    // 0x8001FACC: sb          $t2, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r10;
    after_2:
    // 0x8001FAD0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001FAD4: lw          $v1, -0x70F8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X70F8);
    // 0x8001FAD8: addu        $v1, $s1, $v1
    ctx->r3 = ADD32(ctx->r17, ctx->r3);
    // 0x8001FADC: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8001FAE0: lhu         $t2, 0x26($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X26);
    // 0x8001FAE4: sh          $t2, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r10;
    // 0x8001FAE8: lhu         $t2, 0x2E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X2E);
    // 0x8001FAEC: sw          $s0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r16;
    // 0x8001FAF0: sb          $s6, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r22;
    // 0x8001FAF4: beq         $fp, $zero, L_8001FB18
    if (ctx->r30 == 0) {
        // 0x8001FAF8: sh          $t2, 0xA($v1)
        MEM_H(0XA, ctx->r3) = ctx->r10;
            goto L_8001FB18;
    }
    // 0x8001FAF8: sh          $t2, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r10;
    // 0x8001FAFC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001FB00: lw          $v0, -0x70F8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X70F8);
    // 0x8001FB04: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x8001FB08: lwl         $v1, 0x0($fp)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r30, 0X0);
    // 0x8001FB0C: lwr         $v1, 0x3($fp)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r30, 0X3);
    // 0x8001FB10: swl         $v1, 0x4($v0)
    do_swl(rdram, 0X4, ctx->r2, ctx->r3);
    // 0x8001FB14: swr         $v1, 0x7($v0)
    do_swr(rdram, 0X7, ctx->r2, ctx->r3);
L_8001FB18:
    // 0x8001FB18: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8001FB1C: lhu         $s0, 0x26($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0X26);
    // 0x8001FB20: lhu         $s1, 0x2E($sp)
    ctx->r17 = MEM_HU(ctx->r29, 0X2E);
    // 0x8001FB24: lbu         $t2, 0x37($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X37);
    // 0x8001FB28: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x8001FB2C: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    // 0x8001FB30: sw          $fp, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r30;
    // 0x8001FB34: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8001FB38: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x8001FB3C: jal         0x8001EB24
    // 0x8001FB40: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_8001EB24(rdram, ctx);
        goto after_3;
    // 0x8001FB40: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_3:
    // 0x8001FB44: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8001FB48: andi        $v0, $s3, 0x800
    ctx->r2 = ctx->r19 & 0X800;
    // 0x8001FB4C: bne         $v0, $zero, L_8001FB60
    if (ctx->r2 != 0) {
        // 0x8001FB50: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_8001FB60;
    }
    // 0x8001FB50: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8001FB54: andi        $v0, $s3, 0x400
    ctx->r2 = ctx->r19 & 0X400;
    // 0x8001FB58: beq         $v0, $zero, L_8001FB90
    if (ctx->r2 == 0) {
        // 0x8001FB5C: addiu       $a1, $zero, 0x5
        ctx->r5 = ADD32(0, 0X5);
            goto L_8001FB90;
    }
    // 0x8001FB5C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_8001FB60:
    // 0x8001FB60: andi        $a3, $s6, 0xFF
    ctx->r7 = ctx->r22 & 0XFF;
    // 0x8001FB64: srav        $a2, $s0, $a3
    ctx->r6 = S32(SIGNED(ctx->r16) >> (ctx->r7 & 31));
    // 0x8001FB68: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x8001FB6C: srav        $a3, $s1, $a3
    ctx->r7 = S32(SIGNED(ctx->r17) >> (ctx->r7 & 31));
    // 0x8001FB70: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x8001FB74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001FB78: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8001FB7C: addiu       $v0, $s7, 0x4
    ctx->r2 = ADD32(ctx->r23, 0X4);
    // 0x8001FB80: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8001FB84: jal         0x8001EB24
    // 0x8001FB88: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_8001EB24(rdram, ctx);
        goto after_4;
    // 0x8001FB88: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_4:
    // 0x8001FB8C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_8001FB90:
    // 0x8001FB90: addiu       $v0, $a0, 0xF
    ctx->r2 = ADD32(ctx->r4, 0XF);
    // 0x8001FB94: addiu       $v1, $zero, -0x10
    ctx->r3 = ADD32(0, -0X10);
    // 0x8001FB98: and         $s0, $v0, $v1
    ctx->r16 = ctx->r2 & ctx->r3;
    // 0x8001FB9C: andi        $v0, $s3, 0x20
    ctx->r2 = ctx->r19 & 0X20;
    // 0x8001FBA0: beq         $v0, $zero, L_8001FBC4
    if (ctx->r2 == 0) {
        // 0x8001FBA4: andi        $v1, $s3, 0xF
        ctx->r3 = ctx->r19 & 0XF;
            goto L_8001FBC4;
    }
    // 0x8001FBA4: andi        $v1, $s3, 0xF
    ctx->r3 = ctx->r19 & 0XF;
    // 0x8001FBA8: beq         $v1, $zero, L_8001FBC0
    if (ctx->r3 == 0) {
        // 0x8001FBAC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001FBC0;
    }
    // 0x8001FBAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001FBB0: beql        $v1, $v0, L_8001FBC4
    if (ctx->r3 == ctx->r2) {
        // 0x8001FBB4: addiu       $s0, $s0, 0x200
        ctx->r16 = ADD32(ctx->r16, 0X200);
            goto L_8001FBC4;
    }
    goto skip_0;
    // 0x8001FBB4: addiu       $s0, $s0, 0x200
    ctx->r16 = ADD32(ctx->r16, 0X200);
    skip_0:
    // 0x8001FBB8: j           L_8001FBC4
    // 0x8001FBBC: nop

        goto L_8001FBC4;
    // 0x8001FBBC: nop

L_8001FBC0:
    // 0x8001FBC0: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
L_8001FBC4:
    // 0x8001FBC4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001FBC8: lw          $v1, -0x70F8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X70F8);
    // 0x8001FBCC: sll         $v0, $s2, 3
    ctx->r2 = S32(ctx->r18 << 3);
    // 0x8001FBD0: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8001FBD4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001FBD8: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x8001FBDC: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x8001FBE0: subu        $v0, $s0, $v0
    ctx->r2 = SUB32(ctx->r16, ctx->r2);
    // 0x8001FBE4: sh          $v0, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r2;
    // 0x8001FBE8: lhu         $v1, 0x3E($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X3E);
    // 0x8001FBEC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8001FBF0: bne         $v1, $v0, L_8001FD30
    if (ctx->r3 != ctx->r2) {
        // 0x8001FBF4: andi        $v1, $s3, 0xF
        ctx->r3 = ctx->r19 & 0XF;
            goto L_8001FD30;
    }
    // 0x8001FBF4: andi        $v1, $s3, 0xF
    ctx->r3 = ctx->r19 & 0XF;
    // 0x8001FBF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001FBFC: sw          $s0, -0x5828($at)
    MEM_W(-0X5828, ctx->r1) = ctx->r16;
    // 0x8001FC00: beq         $v1, $zero, L_8001FC1C
    if (ctx->r3 == 0) {
        // 0x8001FC04: ori         $s0, $zero, 0xFFFF
        ctx->r16 = 0 | 0XFFFF;
            goto L_8001FC1C;
    }
    // 0x8001FC04: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    // 0x8001FC08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001FC0C: beq         $v1, $v0, L_8001FC20
    if (ctx->r3 == ctx->r2) {
        // 0x8001FC10: addiu       $t1, $zero, 0x100
        ctx->r9 = ADD32(0, 0X100);
            goto L_8001FC20;
    }
    // 0x8001FC10: addiu       $t1, $zero, 0x100
    ctx->r9 = ADD32(0, 0X100);
    // 0x8001FC14: j           L_8001FD10
    // 0x8001FC18: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
        goto L_8001FD10;
    // 0x8001FC18: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
L_8001FC1C:
    // 0x8001FC1C: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
L_8001FC20:
    // 0x8001FC20: lui         $v0, 0xFF00
    ctx->r2 = S32(0XFF00 << 16);
    // 0x8001FC24: and         $v0, $s5, $v0
    ctx->r2 = ctx->r21 & ctx->r2;
    // 0x8001FC28: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x8001FC2C: bne         $v0, $v1, L_8001FD10
    if (ctx->r2 != ctx->r3) {
        // 0x8001FC30: addu        $a1, $s5, $zero
        ctx->r5 = ADD32(ctx->r21, 0);
            goto L_8001FD10;
    }
    // 0x8001FC30: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x8001FC34: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x8001FC38: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8001FC3C: bne         $a0, $v0, L_8001FCE4
    if (ctx->r4 != ctx->r2) {
        // 0x8001FC40: addu        $a1, $s3, $zero
        ctx->r5 = ADD32(ctx->r19, 0);
            goto L_8001FCE4;
    }
    // 0x8001FC40: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8001FC44: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001FC48: lhu         $v0, -0x70FC($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X70FC);
    // 0x8001FC4C: beq         $v0, $zero, L_8001FC94
    if (ctx->r2 == 0) {
        // 0x8001FC50: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8001FC94;
    }
    // 0x8001FC50: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8001FC54: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001FC58: lw          $a0, -0x7104($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7104);
    // 0x8001FC5C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8001FC60: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
L_8001FC64:
    // 0x8001FC64: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001FC68: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8001FC6C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8001FC70: beq         $v0, $zero, L_8001FC8C
    if (ctx->r2 == 0) {
        // 0x8001FC74: nop
    
            goto L_8001FC8C;
    }
    // 0x8001FC74: nop

    // 0x8001FC78: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001FC7C: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x8001FC80: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8001FC84: bne         $v0, $zero, L_8001FC64
    if (ctx->r2 != 0) {
        // 0x8001FC88: andi        $v0, $s0, 0xFFFF
        ctx->r2 = ctx->r16 & 0XFFFF;
            goto L_8001FC64;
    }
    // 0x8001FC88: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
L_8001FC8C:
    // 0x8001FC8C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001FC90: lhu         $v0, -0x70FC($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X70FC);
L_8001FC94:
    // 0x8001FC94: andi        $t0, $s0, 0xFFFF
    ctx->r8 = ctx->r16 & 0XFFFF;
    // 0x8001FC98: bne         $t0, $v0, L_8001FCA8
    if (ctx->r8 != ctx->r2) {
        // 0x8001FC9C: addu        $a1, $s3, $zero
        ctx->r5 = ADD32(ctx->r19, 0);
            goto L_8001FCA8;
    }
    // 0x8001FC9C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8001FCA0: j           L_8001FD10
    // 0x8001FCA4: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
        goto L_8001FD10;
    // 0x8001FCA4: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
L_8001FCA8:
    // 0x8001FCA8: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x8001FCAC: addu        $a3, $t1, $zero
    ctx->r7 = ADD32(ctx->r9, 0);
    // 0x8001FCB0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001FCB4: lw          $a0, -0x5830($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5830);
    // 0x8001FCB8: sll         $v0, $t1, 1
    ctx->r2 = S32(ctx->r9 << 1);
    // 0x8001FCBC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001FCC0: lw          $v1, -0x7104($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7104);
    // 0x8001FCC4: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8001FCC8: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x8001FCCC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001FCD0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001FCD4: sw          $a0, -0x5830($at)
    MEM_W(-0X5830, ctx->r1) = ctx->r4;
    // 0x8001FCD8: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8001FCDC: j           L_8001FD04
    // 0x8001FCE0: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
        goto L_8001FD04;
    // 0x8001FCE0: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
L_8001FCE4:
    // 0x8001FCE4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001FCE8: lw          $v1, -0x7104($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7104);
    // 0x8001FCEC: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8001FCF0: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x8001FCF4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001FCF8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8001FCFC: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x8001FD00: addu        $a3, $t1, $zero
    ctx->r7 = ADD32(ctx->r9, 0);
L_8001FD04:
    // 0x8001FD04: jal         0x8001E36C
    // 0x8001FD08: nop

    func_8001E36C(rdram, ctx);
        goto after_5;
    // 0x8001FD08: nop

    after_5:
    // 0x8001FD0C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_8001FD10:
    // 0x8001FD10: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001FD14: lw          $v1, -0x70F8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X70F8);
    // 0x8001FD18: sll         $v0, $s2, 3
    ctx->r2 = S32(ctx->r18 << 3);
    // 0x8001FD1C: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8001FD20: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001FD24: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001FD28: j           L_8001FE34
    // 0x8001FD2C: sh          $a1, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r5;
        goto L_8001FE34;
    // 0x8001FD2C: sh          $a1, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r5;
L_8001FD30:
    // 0x8001FD30: lhu         $a0, 0xE($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XE);
    // 0x8001FD34: beq         $v1, $zero, L_8001FD4C
    if (ctx->r3 == 0) {
        // 0x8001FD38: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001FD4C;
    }
    // 0x8001FD38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001FD3C: beq         $v1, $v0, L_8001FD50
    if (ctx->r3 == ctx->r2) {
        // 0x8001FD40: addiu       $t0, $zero, 0x100
        ctx->r8 = ADD32(0, 0X100);
            goto L_8001FD50;
    }
    // 0x8001FD40: addiu       $t0, $zero, 0x100
    ctx->r8 = ADD32(0, 0X100);
    // 0x8001FD44: j           L_8001FE40
    // 0x8001FD48: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
        goto L_8001FE40;
    // 0x8001FD48: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
L_8001FD4C:
    // 0x8001FD4C: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
L_8001FD50:
    // 0x8001FD50: lui         $v0, 0xFF00
    ctx->r2 = S32(0XFF00 << 16);
    // 0x8001FD54: and         $v0, $s5, $v0
    ctx->r2 = ctx->r21 & ctx->r2;
    // 0x8001FD58: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x8001FD5C: bne         $v0, $v1, L_8001FE40
    if (ctx->r2 != ctx->r3) {
        // 0x8001FD60: andi        $v0, $s2, 0xFFFF
        ctx->r2 = ctx->r18 & 0XFFFF;
            goto L_8001FE40;
    }
    // 0x8001FD60: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
    // 0x8001FD64: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8001FD68: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8001FD6C: bne         $a0, $v0, L_8001FE0C
    if (ctx->r4 != ctx->r2) {
        // 0x8001FD70: addu        $a1, $s3, $zero
        ctx->r5 = ADD32(ctx->r19, 0);
            goto L_8001FE0C;
    }
    // 0x8001FD70: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8001FD74: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001FD78: lhu         $v0, -0x70FC($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X70FC);
    // 0x8001FD7C: beq         $v0, $zero, L_8001FDC4
    if (ctx->r2 == 0) {
        // 0x8001FD80: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8001FDC4;
    }
    // 0x8001FD80: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8001FD84: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8001FD88: lw          $a1, -0x7104($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7104);
    // 0x8001FD8C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8001FD90: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
L_8001FD94:
    // 0x8001FD94: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001FD98: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8001FD9C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8001FDA0: beq         $v0, $zero, L_8001FDBC
    if (ctx->r2 == 0) {
        // 0x8001FDA4: nop
    
            goto L_8001FDBC;
    }
    // 0x8001FDA4: nop

    // 0x8001FDA8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001FDAC: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8001FDB0: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8001FDB4: bne         $v0, $zero, L_8001FD94
    if (ctx->r2 != 0) {
        // 0x8001FDB8: andi        $v0, $a0, 0xFFFF
        ctx->r2 = ctx->r4 & 0XFFFF;
            goto L_8001FD94;
    }
    // 0x8001FDB8: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
L_8001FDBC:
    // 0x8001FDBC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001FDC0: lhu         $v0, -0x70FC($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X70FC);
L_8001FDC4:
    // 0x8001FDC4: andi        $t1, $a0, 0xFFFF
    ctx->r9 = ctx->r4 & 0XFFFF;
    // 0x8001FDC8: beq         $t1, $v0, L_8001FE34
    if (ctx->r9 == ctx->r2) {
        // 0x8001FDCC: addu        $a1, $s3, $zero
        ctx->r5 = ADD32(ctx->r19, 0);
            goto L_8001FE34;
    }
    // 0x8001FDCC: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8001FDD0: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x8001FDD4: addu        $a3, $t0, $zero
    ctx->r7 = ADD32(ctx->r8, 0);
    // 0x8001FDD8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001FDDC: lw          $a0, -0x5830($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5830);
    // 0x8001FDE0: sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8 << 1);
    // 0x8001FDE4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001FDE8: lw          $v1, -0x7104($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7104);
    // 0x8001FDEC: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8001FDF0: sll         $v0, $t1, 2
    ctx->r2 = S32(ctx->r9 << 2);
    // 0x8001FDF4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001FDF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001FDFC: sw          $a0, -0x5830($at)
    MEM_W(-0X5830, ctx->r1) = ctx->r4;
    // 0x8001FE00: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8001FE04: j           L_8001FE2C
    // 0x8001FE08: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
        goto L_8001FE2C;
    // 0x8001FE08: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
L_8001FE0C:
    // 0x8001FE0C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001FE10: lw          $v1, -0x7104($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7104);
    // 0x8001FE14: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8001FE18: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x8001FE1C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001FE20: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8001FE24: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x8001FE28: addu        $a3, $t0, $zero
    ctx->r7 = ADD32(ctx->r8, 0);
L_8001FE2C:
    // 0x8001FE2C: jal         0x8001E36C
    // 0x8001FE30: nop

    func_8001E36C(rdram, ctx);
        goto after_6;
    // 0x8001FE30: nop

    after_6:
L_8001FE34:
    // 0x8001FE34: j           L_8001FE40
    // 0x8001FE38: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
        goto L_8001FE40;
    // 0x8001FE38: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
L_8001FE3C:
    // 0x8001FE3C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_8001FE40:
    // 0x8001FE40: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x8001FE44: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x8001FE48: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x8001FE4C: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x8001FE50: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x8001FE54: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x8001FE58: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x8001FE5C: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x8001FE60: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x8001FE64: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x8001FE68: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8001FE6C: jr          $ra
    // 0x8001FE70: nop

    return;
    // 0x8001FE70: nop

;}
RECOMP_FUNC void func_8001FE74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FE74: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x8001FE78: lw          $t1, 0x100($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X100);
    // 0x8001FE7C: lw          $t2, 0xFC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XFC);
    // 0x8001FE80: sw          $ra, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r31;
    // 0x8001FE84: sw          $fp, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r30;
    // 0x8001FE88: sw          $s7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r23;
    // 0x8001FE8C: sw          $s6, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r22;
    // 0x8001FE90: sw          $s5, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r21;
    // 0x8001FE94: sw          $s4, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r20;
    // 0x8001FE98: sw          $s3, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r19;
    // 0x8001FE9C: sw          $s2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r18;
    // 0x8001FEA0: sw          $s1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r17;
    // 0x8001FEA4: sw          $s0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r16;
    // 0x8001FEA8: sw          $a1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r5;
    // 0x8001FEAC: lw          $t1, 0x0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X0);
    // 0x8001FEB0: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x8001FEB4: lhu         $t2, 0x0($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X0);
    // 0x8001FEB8: lbu         $t1, 0xFB($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XFB);
    // 0x8001FEBC: sh          $t2, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r10;
    // 0x8001FEC0: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8001FEC4: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x8001FEC8: addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // 0x8001FECC: sb          $a3, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r7;
    // 0x8001FED0: andi        $v0, $v0, 0x200
    ctx->r2 = ctx->r2 & 0X200;
    // 0x8001FED4: beq         $v0, $zero, L_8001FF10
    if (ctx->r2 == 0) {
        // 0x8001FED8: sb          $t1, 0x27($sp)
        MEM_B(0X27, ctx->r29) = ctx->r9;
            goto L_8001FF10;
    }
    // 0x8001FED8: sb          $t1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r9;
    // 0x8001FEDC: lhu         $v0, 0x8($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X8);
    // 0x8001FEE0: srav        $v0, $v0, $s6
    ctx->r2 = S32(SIGNED(ctx->r2) >> (ctx->r22 & 31));
    // 0x8001FEE4: addiu       $s0, $v0, -0x1
    ctx->r16 = ADD32(ctx->r2, -0X1);
    // 0x8001FEE8: beq         $s0, $zero, L_8001FEFC
    if (ctx->r16 == 0) {
        // 0x8001FEEC: addu        $fp, $zero, $zero
        ctx->r30 = ADD32(0, 0);
            goto L_8001FEFC;
    }
    // 0x8001FEEC: addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
L_8001FEF0:
    // 0x8001FEF0: srl         $s0, $s0, 1
    ctx->r16 = S32(U32(ctx->r16) >> 1);
    // 0x8001FEF4: bne         $s0, $zero, L_8001FEF0
    if (ctx->r16 != 0) {
        // 0x8001FEF8: addiu       $fp, $fp, 0x1
        ctx->r30 = ADD32(ctx->r30, 0X1);
            goto L_8001FEF0;
    }
    // 0x8001FEF8: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
L_8001FEFC:
    // 0x8001FEFC: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x8001FF00: lbu         $v0, 0x1($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X1);
    // 0x8001FF04: srl         $v0, $v0, 7
    ctx->r2 = S32(U32(ctx->r2) >> 7);
    // 0x8001FF08: j           L_8001FF18
    // 0x8001FF0C: sb          $v0, 0x47($sp)
    MEM_B(0X47, ctx->r29) = ctx->r2;
        goto L_8001FF18;
    // 0x8001FF0C: sb          $v0, 0x47($sp)
    MEM_B(0X47, ctx->r29) = ctx->r2;
L_8001FF10:
    // 0x8001FF10: sb          $zero, 0x47($sp)
    MEM_B(0X47, ctx->r29) = 0;
    // 0x8001FF14: addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
L_8001FF18:
    // 0x8001FF18: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x8001FF1C: lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X0);
    // 0x8001FF20: andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // 0x8001FF24: beq         $v0, $zero, L_8001FF60
    if (ctx->r2 == 0) {
        // 0x8001FF28: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_8001FF60;
    }
    // 0x8001FF28: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8001FF2C: lhu         $v0, 0xA($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0XA);
    // 0x8001FF30: srav        $v0, $v0, $s6
    ctx->r2 = S32(SIGNED(ctx->r2) >> (ctx->r22 & 31));
    // 0x8001FF34: addiu       $s0, $v0, -0x1
    ctx->r16 = ADD32(ctx->r2, -0X1);
    // 0x8001FF38: beq         $s0, $zero, L_8001FF4C
    if (ctx->r16 == 0) {
        // 0x8001FF3C: addu        $s7, $zero, $zero
        ctx->r23 = ADD32(0, 0);
            goto L_8001FF4C;
    }
    // 0x8001FF3C: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
L_8001FF40:
    // 0x8001FF40: srl         $s0, $s0, 1
    ctx->r16 = S32(U32(ctx->r16) >> 1);
    // 0x8001FF44: bne         $s0, $zero, L_8001FF40
    if (ctx->r16 != 0) {
        // 0x8001FF48: addiu       $s7, $s7, 0x1
        ctx->r23 = ADD32(ctx->r23, 0X1);
            goto L_8001FF40;
    }
    // 0x8001FF48: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
L_8001FF4C:
    // 0x8001FF4C: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x8001FF50: lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X0);
    // 0x8001FF54: srl         $v0, $v0, 6
    ctx->r2 = S32(U32(ctx->r2) >> 6);
    // 0x8001FF58: j           L_8001FF64
    // 0x8001FF5C: andi        $s1, $v0, 0x1
    ctx->r17 = ctx->r2 & 0X1;
        goto L_8001FF64;
    // 0x8001FF5C: andi        $s1, $v0, 0x1
    ctx->r17 = ctx->r2 & 0X1;
L_8001FF60:
    // 0x8001FF60: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
L_8001FF64:
    // 0x8001FF64: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
    // 0x8001FF68: beq         $v0, $zero, L_8001FF8C
    if (ctx->r2 == 0) {
        // 0x8001FF6C: nop
    
            goto L_8001FF8C;
    }
    // 0x8001FF6C: nop

    // 0x8001FF70: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x8001FF74: lhu         $v1, 0x0($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X0);
    // 0x8001FF78: andi        $v0, $v1, 0x800
    ctx->r2 = ctx->r3 & 0X800;
    // 0x8001FF7C: bne         $v0, $zero, L_80020498
    if (ctx->r2 != 0) {
        // 0x8001FF80: andi        $v0, $v1, 0x400
        ctx->r2 = ctx->r3 & 0X400;
            goto L_80020498;
    }
    // 0x8001FF80: andi        $v0, $v1, 0x400
    ctx->r2 = ctx->r3 & 0X400;
    // 0x8001FF84: bne         $v0, $zero, L_80020EA4
    if (ctx->r2 != 0) {
        // 0x8001FF88: nop
    
            goto L_80020EA4;
    }
    // 0x8001FF88: nop

L_8001FF8C:
    // 0x8001FF8C: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x8001FF90: lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X0);
    // 0x8001FF94: andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // 0x8001FF98: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x8001FF9C: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x8001FFA0: beq         $v0, $zero, L_800219CC
    if (ctx->r2 == 0) {
        // 0x8001FFA4: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800219CC;
    }
    // 0x8001FFA4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001FFA8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001FFAC: addu        $at, $at, $v0
    gpr jr_addend_8001FFB4 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001FFB0: lw          $v0, 0x9D8($at)
    ctx->r2 = ADD32(ctx->r1, 0X9D8);
    // 0x8001FFB4: jr          $v0
    // 0x8001FFB8: nop

    switch (jr_addend_8001FFB4 >> 2) {
        case 0: goto L_8001FFBC; break;
        case 1: goto L_80020A50; break;
        case 2: goto L_80021418; break;
        case 3: goto L_800216D0; break;
        case 4: goto L_80020494; break;
        case 5: goto L_80020EA4; break;
        default: switch_error(__func__, 0x8001FFB4, 0x800009D8);
    }
    // 0x8001FFB8: nop

L_8001FFBC:
    // 0x8001FFBC: lbu         $t1, 0x27($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X27);
    // 0x8001FFC0: beq         $t1, $zero, L_80020188
    if (ctx->r9 == 0) {
        // 0x8001FFC4: nop
    
            goto L_80020188;
    }
    // 0x8001FFC4: nop

    // 0x8001FFC8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8001FFCC: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x8001FFD0: sltu        $v0, $t0, $v0
    ctx->r2 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x8001FFD4: bne         $v0, $zero, L_8001FFF4
    if (ctx->r2 != 0) {
        // 0x8001FFD8: addu        $a0, $t0, $zero
        ctx->r4 = ADD32(ctx->r8, 0);
            goto L_8001FFF4;
    }
    // 0x8001FFD8: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x8001FFDC: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x8001FFE0: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8001FFE4: jal         0x80007D74
    // 0x8001FFE8: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_0;
    // 0x8001FFE8: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_0:
    // 0x8001FFEC: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x8001FFF0: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
L_8001FFF4:
    // 0x8001FFF4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8001FFF8: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x8001FFFC: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020000: lui         $v0, 0xE600
    ctx->r2 = S32(0XE600 << 16);
    // 0x80020004: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80020008: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x8002000C: bne         $v1, $zero, L_80020028
    if (ctx->r3 != 0) {
        // 0x80020010: sw          $zero, 0x4($a0)
        MEM_W(0X4, ctx->r4) = 0;
            goto L_80020028;
    }
    // 0x80020010: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80020014: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80020018: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8002001C: jal         0x80007D74
    // 0x80020020: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_1;
    // 0x80020020: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_1:
    // 0x80020024: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80020028:
    // 0x80020028: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x8002002C: lui         $v0, 0xFD10
    ctx->r2 = S32(0XFD10 << 16);
    // 0x80020030: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80020034: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x80020038: lhu         $v0, 0xE($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0XE);
    // 0x8002003C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80020040: lw          $v1, -0x7104($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7104);
    // 0x80020044: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80020048: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8002004C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80020050: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80020054: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x80020058: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8002005C: sltu        $v0, $t0, $v0
    ctx->r2 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x80020060: bne         $v0, $zero, L_8002007C
    if (ctx->r2 != 0) {
        // 0x80020064: sw          $v1, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r3;
            goto L_8002007C;
    }
    // 0x80020064: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x80020068: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x8002006C: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80020070: jal         0x80007D74
    // 0x80020074: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_2;
    // 0x80020074: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_2:
    // 0x80020078: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_8002007C:
    // 0x8002007C: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x80020080: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80020084: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80020088: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8002008C: lui         $v0, 0xE800
    ctx->r2 = S32(0XE800 << 16);
    // 0x80020090: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80020094: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80020098: bne         $v1, $zero, L_800200B4
    if (ctx->r3 != 0) {
        // 0x8002009C: sw          $zero, 0x4($a0)
        MEM_W(0X4, ctx->r4) = 0;
            goto L_800200B4;
    }
    // 0x8002009C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800200A0: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x800200A4: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x800200A8: jal         0x80007D74
    // 0x800200AC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_3;
    // 0x800200AC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_3:
    // 0x800200B0: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_800200B4:
    // 0x800200B4: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x800200B8: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800200BC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800200C0: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x800200C4: lui         $v0, 0xF500
    ctx->r2 = S32(0XF500 << 16);
    // 0x800200C8: ori         $v0, $v0, 0x1F0
    ctx->r2 = ctx->r2 | 0X1F0;
    // 0x800200CC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800200D0: lui         $v0, 0x700
    ctx->r2 = S32(0X700 << 16);
    // 0x800200D4: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800200D8: bne         $v1, $zero, L_800200F4
    if (ctx->r3 != 0) {
        // 0x800200DC: sw          $v0, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r2;
            goto L_800200F4;
    }
    // 0x800200DC: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x800200E0: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x800200E4: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x800200E8: jal         0x80007D74
    // 0x800200EC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_4;
    // 0x800200EC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_4:
    // 0x800200F0: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_800200F4:
    // 0x800200F4: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x800200F8: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800200FC: lui         $a1, 0x703
    ctx->r5 = S32(0X703 << 16);
    // 0x80020100: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80020104: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80020108: ori         $a1, $a1, 0xC000
    ctx->r5 = ctx->r5 | 0XC000;
    // 0x8002010C: lui         $v0, 0xF000
    ctx->r2 = S32(0XF000 << 16);
    // 0x80020110: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80020114: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80020118: bne         $v1, $zero, L_80020134
    if (ctx->r3 != 0) {
        // 0x8002011C: sw          $a1, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r5;
            goto L_80020134;
    }
    // 0x8002011C: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80020120: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80020124: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80020128: jal         0x80007D74
    // 0x8002012C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_5;
    // 0x8002012C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_5:
    // 0x80020130: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80020134:
    // 0x80020134: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x80020138: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8002013C: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80020140: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020144: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x80020148: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8002014C: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80020150: bne         $v1, $zero, L_8002016C
    if (ctx->r3 != 0) {
        // 0x80020154: sw          $zero, 0x4($a0)
        MEM_W(0X4, ctx->r4) = 0;
            goto L_8002016C;
    }
    // 0x80020154: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80020158: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x8002015C: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80020160: jal         0x80007D74
    // 0x80020164: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_6;
    // 0x80020164: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_6:
    // 0x80020168: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_8002016C:
    // 0x8002016C: addu        $v1, $t0, $zero
    ctx->r3 = ADD32(ctx->r8, 0);
    // 0x80020170: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020174: lui         $v0, 0xBA00
    ctx->r2 = S32(0XBA00 << 16);
    // 0x80020178: ori         $v0, $v0, 0xE02
    ctx->r2 = ctx->r2 | 0XE02;
    // 0x8002017C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80020180: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x80020184: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80020188:
    // 0x80020188: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x8002018C: lbu         $s0, 0x1F($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X1F);
    // 0x80020190: lhu         $v1, 0x8($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X8);
    // 0x80020194: andi        $a1, $s6, 0xFF
    ctx->r5 = ctx->r22 & 0XFF;
    // 0x80020198: lhu         $a0, 0xA($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0XA);
    // 0x8002019C: srav        $v1, $v1, $a1
    ctx->r3 = S32(SIGNED(ctx->r3) >> (ctx->r5 & 31));
    // 0x800201A0: addiu       $v0, $v1, 0xF
    ctx->r2 = ADD32(ctx->r3, 0XF);
    // 0x800201A4: andi        $s2, $v0, 0xFFF0
    ctx->r18 = ctx->r2 & 0XFFF0;
    // 0x800201A8: lbu         $v0, 0x2($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X2);
    // 0x800201AC: srav        $s5, $a0, $a1
    ctx->r21 = S32(SIGNED(ctx->r4) >> (ctx->r5 & 31));
    // 0x800201B0: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800201B4: sltu        $v0, $s0, $v0
    ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800201B8: beq         $v0, $zero, L_800219CC
    if (ctx->r2 == 0) {
        // 0x800201BC: sh          $v1, 0x2E($sp)
        MEM_H(0X2E, ctx->r29) = ctx->r3;
            goto L_800219CC;
    }
    // 0x800201BC: sh          $v1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r3;
    // 0x800201C0: sll         $v1, $s1, 18
    ctx->r3 = S32(ctx->r17 << 18);
    // 0x800201C4: lui         $v0, 0xF0
    ctx->r2 = S32(0XF0 << 16);
    // 0x800201C8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800201CC: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
L_800201D0:
    // 0x800201D0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800201D4: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x800201D8: sltu        $v0, $t0, $v0
    ctx->r2 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x800201DC: bne         $v0, $zero, L_800201FC
    if (ctx->r2 != 0) {
        // 0x800201E0: addu        $a0, $t0, $zero
        ctx->r4 = ADD32(ctx->r8, 0);
            goto L_800201FC;
    }
    // 0x800201E0: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x800201E4: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x800201E8: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800201EC: jal         0x80007D74
    // 0x800201F0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_7;
    // 0x800201F0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_7:
    // 0x800201F4: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x800201F8: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
L_800201FC:
    // 0x800201FC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80020200: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80020204: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020208: lui         $v0, 0xE600
    ctx->r2 = S32(0XE600 << 16);
    // 0x8002020C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80020210: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80020214: bne         $v1, $zero, L_80020230
    if (ctx->r3 != 0) {
        // 0x80020218: sw          $zero, 0x4($a0)
        MEM_W(0X4, ctx->r4) = 0;
            goto L_80020230;
    }
    // 0x80020218: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8002021C: lui         $t1, 0xB500
    ctx->r9 = S32(0XB500 << 16);
    // 0x80020220: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x80020224: jal         0x80007D74
    // 0x80020228: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_8;
    // 0x80020228: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_8:
    // 0x8002022C: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80020230:
    // 0x80020230: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80020234: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80020238: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x8002023C: lui         $v0, 0xFD50
    ctx->r2 = S32(0XFD50 << 16);
    // 0x80020240: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80020244: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80020248: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8002024C: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80020250: bne         $v1, $zero, L_8002026C
    if (ctx->r3 != 0) {
        // 0x80020254: sw          $t2, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r10;
            goto L_8002026C;
    }
    // 0x80020254: sw          $t2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r10;
    // 0x80020258: lui         $t1, 0xB500
    ctx->r9 = S32(0XB500 << 16);
    // 0x8002025C: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x80020260: jal         0x80007D74
    // 0x80020264: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_9;
    // 0x80020264: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_9:
    // 0x80020268: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_8002026C:
    // 0x8002026C: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x80020270: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020274: lui         $a1, 0x708
    ctx->r5 = S32(0X708 << 16);
    // 0x80020278: lhu         $t2, 0x36($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X36);
    // 0x8002027C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80020280: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80020284: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x80020288: lui         $v0, 0xF550
    ctx->r2 = S32(0XF550 << 16);
    // 0x8002028C: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80020290: andi        $s3, $t2, 0x1FF
    ctx->r19 = ctx->r10 & 0X1FF;
    // 0x80020294: or          $v0, $s3, $v0
    ctx->r2 = ctx->r19 | ctx->r2;
    // 0x80020298: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x8002029C: bne         $v1, $zero, L_800202B8
    if (ctx->r3 != 0) {
        // 0x800202A0: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_800202B8;
    }
    // 0x800202A0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800202A4: lui         $t1, 0xB500
    ctx->r9 = S32(0XB500 << 16);
    // 0x800202A8: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x800202AC: jal         0x80007D74
    // 0x800202B0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_10;
    // 0x800202B0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_10:
    // 0x800202B4: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_800202B8:
    // 0x800202B8: andi        $s2, $s2, 0xFFFF
    ctx->r18 = ctx->r18 & 0XFFFF;
    // 0x800202BC: andi        $s4, $s5, 0xFFFF
    ctx->r20 = ctx->r21 & 0XFFFF;
    // 0x800202C0: mult        $s2, $s4
    result = S64(S32(ctx->r18)) * S64(S32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800202C4: mflo        $s1
    ctx->r17 = lo;
    // 0x800202C8: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x800202CC: lui         $v0, 0xF300
    ctx->r2 = S32(0XF300 << 16);
    // 0x800202D0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800202D4: sra         $v0, $s1, 2
    ctx->r2 = S32(SIGNED(ctx->r17) >> 2);
    // 0x800202D8: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x800202DC: slti        $v0, $v1, 0x800
    ctx->r2 = SIGNED(ctx->r3) < 0X800 ? 1 : 0;
    // 0x800202E0: bne         $v0, $zero, L_800202EC
    if (ctx->r2 != 0) {
        // 0x800202E4: addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_800202EC;
    }
    // 0x800202E4: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800202E8: addiu       $v1, $zero, 0x7FF
    ctx->r3 = ADD32(0, 0X7FF);
L_800202EC:
    // 0x800202EC: andi        $v0, $v1, 0xFFF
    ctx->r2 = ctx->r3 & 0XFFF;
    // 0x800202F0: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x800202F4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800202F8: lw          $a0, 0x63D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63D4);
    // 0x800202FC: lui         $v1, 0x700
    ctx->r3 = S32(0X700 << 16);
    // 0x80020300: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80020304: sltu        $a0, $t0, $a0
    ctx->r4 = ctx->r8 < ctx->r4 ? 1 : 0;
    // 0x80020308: bne         $a0, $zero, L_80020324
    if (ctx->r4 != 0) {
        // 0x8002030C: sw          $v0, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->r2;
            goto L_80020324;
    }
    // 0x8002030C: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80020310: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x80020314: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80020318: jal         0x80007D74
    // 0x8002031C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_11;
    // 0x8002031C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_11:
    // 0x80020320: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80020324:
    // 0x80020324: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x80020328: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8002032C: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80020330: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020334: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x80020338: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8002033C: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80020340: bne         $v1, $zero, L_8002035C
    if (ctx->r3 != 0) {
        // 0x80020344: sw          $zero, 0x4($a0)
        MEM_W(0X4, ctx->r4) = 0;
            goto L_8002035C;
    }
    // 0x80020344: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80020348: lui         $t1, 0xB500
    ctx->r9 = S32(0XB500 << 16);
    // 0x8002034C: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x80020350: jal         0x80007D74
    // 0x80020354: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_12;
    // 0x80020354: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_12:
    // 0x80020358: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_8002035C:
    // 0x8002035C: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    // 0x80020360: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020364: srl         $v1, $s2, 4
    ctx->r3 = S32(U32(ctx->r18) >> 4);
    // 0x80020368: andi        $v1, $v1, 0x1FF
    ctx->r3 = ctx->r3 & 0X1FF;
    // 0x8002036C: sll         $v1, $v1, 9
    ctx->r3 = S32(ctx->r3 << 9);
    // 0x80020370: lui         $v0, 0xF540
    ctx->r2 = S32(0XF540 << 16);
    // 0x80020374: or          $v0, $s3, $v0
    ctx->r2 = ctx->r19 | ctx->r2;
    // 0x80020378: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8002037C: andi        $v0, $s0, 0x7
    ctx->r2 = ctx->r16 & 0X7;
    // 0x80020380: sll         $s3, $v0, 24
    ctx->r19 = S32(ctx->r2 << 24);
    // 0x80020384: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x80020388: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x8002038C: andi        $v0, $s7, 0xF
    ctx->r2 = ctx->r23 & 0XF;
    // 0x80020390: sll         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2 << 14);
    // 0x80020394: andi        $a1, $s6, 0xF
    ctx->r5 = ctx->r22 & 0XF;
    // 0x80020398: lbu         $t1, 0x47($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X47);
    // 0x8002039C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800203A0: lw          $a0, 0x63D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63D4);
    // 0x800203A4: or          $v1, $s3, $t2
    ctx->r3 = ctx->r19 | ctx->r10;
    // 0x800203A8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800203AC: sll         $v0, $a1, 10
    ctx->r2 = S32(ctx->r5 << 10);
    // 0x800203B0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800203B4: andi        $v0, $t1, 0x3
    ctx->r2 = ctx->r9 & 0X3;
    // 0x800203B8: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x800203BC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800203C0: andi        $v0, $fp, 0xF
    ctx->r2 = ctx->r30 & 0XF;
    // 0x800203C4: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800203C8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800203CC: or          $v1, $v1, $a1
    ctx->r3 = ctx->r3 | ctx->r5;
    // 0x800203D0: sltu        $a0, $t0, $a0
    ctx->r4 = ctx->r8 < ctx->r4 ? 1 : 0;
    // 0x800203D4: bne         $a0, $zero, L_800203F0
    if (ctx->r4 != 0) {
        // 0x800203D8: sw          $v1, 0x4($a2)
        MEM_W(0X4, ctx->r6) = ctx->r3;
            goto L_800203F0;
    }
    // 0x800203D8: sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
    // 0x800203DC: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x800203E0: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800203E4: jal         0x80007D74
    // 0x800203E8: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_13;
    // 0x800203E8: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_13:
    // 0x800203EC: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_800203F0:
    // 0x800203F0: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x800203F4: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800203F8: sra         $v0, $s1, 1
    ctx->r2 = S32(SIGNED(ctx->r17) >> 1);
    // 0x800203FC: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80020400: lhu         $t2, 0x36($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X36);
    // 0x80020404: lhu         $v1, 0x2E($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X2E);
    // 0x80020408: srl         $s5, $s4, 1
    ctx->r21 = S32(U32(ctx->r20) >> 1);
    // 0x8002040C: addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
    // 0x80020410: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x80020414: sra         $v0, $s1, 4
    ctx->r2 = S32(SIGNED(ctx->r17) >> 4);
    // 0x80020418: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x8002041C: srl         $v0, $s2, 1
    ctx->r2 = S32(U32(ctx->r18) >> 1);
    // 0x80020420: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x80020424: andi        $s2, $v0, 0xFFF0
    ctx->r18 = ctx->r2 & 0XFFF0;
    // 0x80020428: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x8002042C: srl         $t1, $v1, 1
    ctx->r9 = S32(U32(ctx->r3) >> 1);
    // 0x80020430: lui         $v0, 0xF200
    ctx->r2 = S32(0XF200 << 16);
    // 0x80020434: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80020438: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8002043C: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x80020440: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x80020444: or          $v1, $s3, $v1
    ctx->r3 = ctx->r19 | ctx->r3;
    // 0x80020448: sh          $t2, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r10;
    // 0x8002044C: sh          $t1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r9;
    // 0x80020450: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80020454: addiu       $v0, $s4, -0x1
    ctx->r2 = ADD32(ctx->r20, -0X1);
    // 0x80020458: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002045C: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80020460: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80020464: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x80020468: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x8002046C: addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
    // 0x80020470: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
    // 0x80020474: lbu         $v1, 0x2($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X2);
    // 0x80020478: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002047C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80020480: sltu        $v1, $s0, $v1
    ctx->r3 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80020484: bne         $v1, $zero, L_800201D0
    if (ctx->r3 != 0) {
        // 0x80020488: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_800201D0;
    }
    // 0x80020488: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x8002048C: j           L_800219CC
    // 0x80020490: nop

        goto L_800219CC;
    // 0x80020490: nop

L_80020494:
    // 0x80020494: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
L_80020498:
    // 0x80020498: lhu         $v1, 0xA($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0XA);
    // 0x8002049C: lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X0);
    // 0x800204A0: andi        $a0, $s6, 0xFF
    ctx->r4 = ctx->r22 & 0XFF;
    // 0x800204A4: andi        $v0, $v0, 0xC000
    ctx->r2 = ctx->r2 & 0XC000;
    // 0x800204A8: beq         $v0, $zero, L_80020760
    if (ctx->r2 == 0) {
        // 0x800204AC: srav        $s5, $v1, $a0
        ctx->r21 = S32(SIGNED(ctx->r3) >> (ctx->r4 & 31));
            goto L_80020760;
    }
    // 0x800204AC: srav        $s5, $v1, $a0
    ctx->r21 = S32(SIGNED(ctx->r3) >> (ctx->r4 & 31));
    // 0x800204B0: lhu         $v0, 0x8($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X8);
    // 0x800204B4: lbu         $s0, 0x1F($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X1F);
    // 0x800204B8: lbu         $v1, 0x2($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X2);
    // 0x800204BC: srav        $v0, $v0, $a0
    ctx->r2 = S32(SIGNED(ctx->r2) >> (ctx->r4 & 31));
    // 0x800204C0: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // 0x800204C4: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x800204C8: sltu        $v1, $s0, $v1
    ctx->r3 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x800204CC: beq         $v1, $zero, L_80021980
    if (ctx->r3 == 0) {
        // 0x800204D0: andi        $s2, $v0, 0xFFF8
        ctx->r18 = ctx->r2 & 0XFFF8;
            goto L_80021980;
    }
    // 0x800204D0: andi        $s2, $v0, 0xFFF8
    ctx->r18 = ctx->r2 & 0XFFF8;
    // 0x800204D4: lbu         $t2, 0x47($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X47);
    // 0x800204D8: sll         $s1, $s1, 18
    ctx->r17 = S32(ctx->r17 << 18);
    // 0x800204DC: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x800204E0: andi        $v0, $t2, 0x3
    ctx->r2 = ctx->r10 & 0X3;
    // 0x800204E4: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x800204E8: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
L_800204EC:
    // 0x800204EC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800204F0: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x800204F4: sltu        $v0, $t0, $v0
    ctx->r2 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x800204F8: bne         $v0, $zero, L_80020518
    if (ctx->r2 != 0) {
        // 0x800204FC: addu        $a0, $t0, $zero
        ctx->r4 = ADD32(ctx->r8, 0);
            goto L_80020518;
    }
    // 0x800204FC: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x80020500: lui         $t1, 0xB500
    ctx->r9 = S32(0XB500 << 16);
    // 0x80020504: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x80020508: jal         0x80007D74
    // 0x8002050C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_14;
    // 0x8002050C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_14:
    // 0x80020510: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80020514: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
L_80020518:
    // 0x80020518: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8002051C: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80020520: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020524: lui         $v0, 0xE600
    ctx->r2 = S32(0XE600 << 16);
    // 0x80020528: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8002052C: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80020530: bne         $v1, $zero, L_8002054C
    if (ctx->r3 != 0) {
        // 0x80020534: sw          $zero, 0x4($a0)
        MEM_W(0X4, ctx->r4) = 0;
            goto L_8002054C;
    }
    // 0x80020534: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80020538: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x8002053C: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80020540: jal         0x80007D74
    // 0x80020544: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_15;
    // 0x80020544: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_15:
    // 0x80020548: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_8002054C:
    // 0x8002054C: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x80020550: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020554: lui         $a1, 0x708
    ctx->r5 = S32(0X708 << 16);
    // 0x80020558: lhu         $t1, 0x36($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X36);
    // 0x8002055C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80020560: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80020564: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x80020568: lui         $v0, 0xF570
    ctx->r2 = S32(0XF570 << 16);
    // 0x8002056C: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80020570: andi        $s4, $t1, 0x1FF
    ctx->r20 = ctx->r9 & 0X1FF;
    // 0x80020574: or          $v0, $s4, $v0
    ctx->r2 = ctx->r20 | ctx->r2;
    // 0x80020578: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x8002057C: bne         $v1, $zero, L_80020598
    if (ctx->r3 != 0) {
        // 0x80020580: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_80020598;
    }
    // 0x80020580: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80020584: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x80020588: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x8002058C: jal         0x80007D74
    // 0x80020590: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_16;
    // 0x80020590: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_16:
    // 0x80020594: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80020598:
    // 0x80020598: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8002059C: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x800205A0: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x800205A4: lui         $v0, 0xFD70
    ctx->r2 = S32(0XFD70 << 16);
    // 0x800205A8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800205AC: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800205B0: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800205B4: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800205B8: bne         $v1, $zero, L_800205D4
    if (ctx->r3 != 0) {
        // 0x800205BC: sw          $t1, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r9;
            goto L_800205D4;
    }
    // 0x800205BC: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x800205C0: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x800205C4: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800205C8: jal         0x80007D74
    // 0x800205CC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_17;
    // 0x800205CC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_17:
    // 0x800205D0: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_800205D4:
    // 0x800205D4: andi        $s1, $s2, 0xFFFF
    ctx->r17 = ctx->r18 & 0XFFFF;
    // 0x800205D8: andi        $s3, $s5, 0xFFFF
    ctx->r19 = ctx->r21 & 0XFFFF;
    // 0x800205DC: mult        $s1, $s3
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800205E0: mflo        $s2
    ctx->r18 = lo;
    // 0x800205E4: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x800205E8: lui         $v0, 0xF300
    ctx->r2 = S32(0XF300 << 16);
    // 0x800205EC: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800205F0: sra         $v0, $s2, 1
    ctx->r2 = S32(SIGNED(ctx->r18) >> 1);
    // 0x800205F4: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x800205F8: slti        $v0, $v1, 0x800
    ctx->r2 = SIGNED(ctx->r3) < 0X800 ? 1 : 0;
    // 0x800205FC: bne         $v0, $zero, L_80020608
    if (ctx->r2 != 0) {
        // 0x80020600: addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_80020608;
    }
    // 0x80020600: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020604: addiu       $v1, $zero, 0x7FF
    ctx->r3 = ADD32(0, 0X7FF);
L_80020608:
    // 0x80020608: andi        $v0, $v1, 0xFFF
    ctx->r2 = ctx->r3 & 0XFFF;
    // 0x8002060C: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x80020610: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80020614: lw          $a0, 0x63D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63D4);
    // 0x80020618: lui         $v1, 0x700
    ctx->r3 = S32(0X700 << 16);
    // 0x8002061C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80020620: sltu        $a0, $t0, $a0
    ctx->r4 = ctx->r8 < ctx->r4 ? 1 : 0;
    // 0x80020624: bne         $a0, $zero, L_80020640
    if (ctx->r4 != 0) {
        // 0x80020628: sw          $v0, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->r2;
            goto L_80020640;
    }
    // 0x80020628: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x8002062C: lui         $t1, 0xB500
    ctx->r9 = S32(0XB500 << 16);
    // 0x80020630: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x80020634: jal         0x80007D74
    // 0x80020638: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_18;
    // 0x80020638: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_18:
    // 0x8002063C: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80020640:
    // 0x80020640: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    // 0x80020644: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020648: srl         $v1, $s1, 3
    ctx->r3 = S32(U32(ctx->r17) >> 3);
    // 0x8002064C: andi        $v1, $v1, 0x1FF
    ctx->r3 = ctx->r3 & 0X1FF;
    // 0x80020650: sll         $v1, $v1, 9
    ctx->r3 = S32(ctx->r3 << 9);
    // 0x80020654: lui         $v0, 0xF568
    ctx->r2 = S32(0XF568 << 16);
    // 0x80020658: or          $v0, $s4, $v0
    ctx->r2 = ctx->r20 | ctx->r2;
    // 0x8002065C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80020660: andi        $v0, $s0, 0x7
    ctx->r2 = ctx->r16 & 0X7;
    // 0x80020664: sll         $s4, $v0, 24
    ctx->r20 = S32(ctx->r2 << 24);
    // 0x80020668: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x8002066C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80020670: andi        $v0, $s7, 0xF
    ctx->r2 = ctx->r23 & 0XF;
    // 0x80020674: sll         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2 << 14);
    // 0x80020678: andi        $a1, $s6, 0xF
    ctx->r5 = ctx->r22 & 0XF;
    // 0x8002067C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80020680: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80020684: lw          $a0, 0x63D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63D4);
    // 0x80020688: or          $v1, $s4, $t2
    ctx->r3 = ctx->r20 | ctx->r10;
    // 0x8002068C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80020690: sll         $v0, $a1, 10
    ctx->r2 = S32(ctx->r5 << 10);
    // 0x80020694: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80020698: or          $v1, $v1, $t1
    ctx->r3 = ctx->r3 | ctx->r9;
    // 0x8002069C: andi        $v0, $fp, 0xF
    ctx->r2 = ctx->r30 & 0XF;
    // 0x800206A0: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800206A4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800206A8: or          $v1, $v1, $a1
    ctx->r3 = ctx->r3 | ctx->r5;
    // 0x800206AC: sltu        $a0, $t0, $a0
    ctx->r4 = ctx->r8 < ctx->r4 ? 1 : 0;
    // 0x800206B0: bne         $a0, $zero, L_800206CC
    if (ctx->r4 != 0) {
        // 0x800206B4: sw          $v1, 0x4($a2)
        MEM_W(0X4, ctx->r6) = ctx->r3;
            goto L_800206CC;
    }
    // 0x800206B4: sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
    // 0x800206B8: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x800206BC: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800206C0: jal         0x80007D74
    // 0x800206C4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_19;
    // 0x800206C4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_19:
    // 0x800206C8: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_800206CC:
    // 0x800206CC: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x800206D0: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800206D4: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800206D8: sra         $v0, $s2, 3
    ctx->r2 = S32(SIGNED(ctx->r18) >> 3);
    // 0x800206DC: lhu         $t2, 0x36($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X36);
    // 0x800206E0: srl         $s5, $s3, 1
    ctx->r21 = S32(U32(ctx->r19) >> 1);
    // 0x800206E4: addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
    // 0x800206E8: addiu       $v1, $s1, -0x1
    ctx->r3 = ADD32(ctx->r17, -0X1);
    // 0x800206EC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800206F0: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x800206F4: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x800206F8: or          $v1, $s4, $v1
    ctx->r3 = ctx->r20 | ctx->r3;
    // 0x800206FC: addu        $t1, $t1, $s2
    ctx->r9 = ADD32(ctx->r9, ctx->r18);
    // 0x80020700: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x80020704: srl         $v0, $s1, 1
    ctx->r2 = S32(U32(ctx->r17) >> 1);
    // 0x80020708: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // 0x8002070C: andi        $s2, $v0, 0xFFF8
    ctx->r18 = ctx->r2 & 0XFFF8;
    // 0x80020710: lui         $v0, 0xF200
    ctx->r2 = S32(0XF200 << 16);
    // 0x80020714: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x80020718: sh          $t2, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r10;
    // 0x8002071C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80020720: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // 0x80020724: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80020728: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8002072C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80020730: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x80020734: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x80020738: addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
    // 0x8002073C: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
    // 0x80020740: lbu         $v1, 0x2($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X2);
    // 0x80020744: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80020748: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8002074C: sltu        $v1, $s0, $v1
    ctx->r3 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80020750: bne         $v1, $zero, L_800204EC
    if (ctx->r3 != 0) {
        // 0x80020754: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_800204EC;
    }
    // 0x80020754: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80020758: j           L_80021980
    // 0x8002075C: nop

        goto L_80021980;
    // 0x8002075C: nop

L_80020760:
    // 0x80020760: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x80020764: lhu         $v0, 0x8($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X8);
    // 0x80020768: lbu         $s0, 0x1F($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X1F);
    // 0x8002076C: lbu         $v1, 0x2($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X2);
    // 0x80020770: srav        $v0, $v0, $a0
    ctx->r2 = S32(SIGNED(ctx->r2) >> (ctx->r4 & 31));
    // 0x80020774: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x80020778: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x8002077C: sltu        $v1, $s0, $v1
    ctx->r3 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80020780: beq         $v1, $zero, L_80021980
    if (ctx->r3 == 0) {
        // 0x80020784: andi        $s2, $v0, 0xFFF0
        ctx->r18 = ctx->r2 & 0XFFF0;
            goto L_80021980;
    }
    // 0x80020784: andi        $s2, $v0, 0xFFF0
    ctx->r18 = ctx->r2 & 0XFFF0;
    // 0x80020788: lbu         $t1, 0x47($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X47);
    // 0x8002078C: sll         $s1, $s1, 18
    ctx->r17 = S32(ctx->r17 << 18);
    // 0x80020790: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x80020794: andi        $v0, $t1, 0x3
    ctx->r2 = ctx->r9 & 0X3;
    // 0x80020798: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8002079C: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
L_800207A0:
    // 0x800207A0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800207A4: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x800207A8: sltu        $v0, $t0, $v0
    ctx->r2 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x800207AC: bne         $v0, $zero, L_800207CC
    if (ctx->r2 != 0) {
        // 0x800207B0: addu        $a0, $t0, $zero
        ctx->r4 = ADD32(ctx->r8, 0);
            goto L_800207CC;
    }
    // 0x800207B0: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x800207B4: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x800207B8: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800207BC: jal         0x80007D74
    // 0x800207C0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_20;
    // 0x800207C0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_20:
    // 0x800207C4: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x800207C8: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
L_800207CC:
    // 0x800207CC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800207D0: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x800207D4: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800207D8: lui         $v0, 0xE600
    ctx->r2 = S32(0XE600 << 16);
    // 0x800207DC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800207E0: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800207E4: bne         $v1, $zero, L_80020800
    if (ctx->r3 != 0) {
        // 0x800207E8: sw          $zero, 0x4($a0)
        MEM_W(0X4, ctx->r4) = 0;
            goto L_80020800;
    }
    // 0x800207E8: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800207EC: lui         $t1, 0xB500
    ctx->r9 = S32(0XB500 << 16);
    // 0x800207F0: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x800207F4: jal         0x80007D74
    // 0x800207F8: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_21;
    // 0x800207F8: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_21:
    // 0x800207FC: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80020800:
    // 0x80020800: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80020804: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80020808: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x8002080C: lui         $v0, 0xFD90
    ctx->r2 = S32(0XFD90 << 16);
    // 0x80020810: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80020814: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80020818: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8002081C: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80020820: bne         $v1, $zero, L_8002083C
    if (ctx->r3 != 0) {
        // 0x80020824: sw          $t2, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r10;
            goto L_8002083C;
    }
    // 0x80020824: sw          $t2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r10;
    // 0x80020828: lui         $t1, 0xB500
    ctx->r9 = S32(0XB500 << 16);
    // 0x8002082C: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x80020830: jal         0x80007D74
    // 0x80020834: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_22;
    // 0x80020834: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_22:
    // 0x80020838: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_8002083C:
    // 0x8002083C: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x80020840: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020844: lui         $a1, 0x708
    ctx->r5 = S32(0X708 << 16);
    // 0x80020848: lhu         $t2, 0x36($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X36);
    // 0x8002084C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80020850: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80020854: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x80020858: lui         $v0, 0xF590
    ctx->r2 = S32(0XF590 << 16);
    // 0x8002085C: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80020860: andi        $s3, $t2, 0x1FF
    ctx->r19 = ctx->r10 & 0X1FF;
    // 0x80020864: or          $v0, $s3, $v0
    ctx->r2 = ctx->r19 | ctx->r2;
    // 0x80020868: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x8002086C: bne         $v1, $zero, L_80020888
    if (ctx->r3 != 0) {
        // 0x80020870: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_80020888;
    }
    // 0x80020870: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80020874: lui         $t1, 0xB500
    ctx->r9 = S32(0XB500 << 16);
    // 0x80020878: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x8002087C: jal         0x80007D74
    // 0x80020880: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_23;
    // 0x80020880: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_23:
    // 0x80020884: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80020888:
    // 0x80020888: andi        $s1, $s2, 0xFFFF
    ctx->r17 = ctx->r18 & 0XFFFF;
    // 0x8002088C: andi        $s4, $s5, 0xFFFF
    ctx->r20 = ctx->r21 & 0XFFFF;
    // 0x80020890: mult        $s1, $s4
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80020894: mflo        $s2
    ctx->r18 = lo;
    // 0x80020898: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x8002089C: lui         $v0, 0xF300
    ctx->r2 = S32(0XF300 << 16);
    // 0x800208A0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800208A4: sra         $v0, $s2, 2
    ctx->r2 = S32(SIGNED(ctx->r18) >> 2);
    // 0x800208A8: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x800208AC: slti        $v0, $v1, 0x800
    ctx->r2 = SIGNED(ctx->r3) < 0X800 ? 1 : 0;
    // 0x800208B0: bne         $v0, $zero, L_800208BC
    if (ctx->r2 != 0) {
        // 0x800208B4: addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_800208BC;
    }
    // 0x800208B4: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800208B8: addiu       $v1, $zero, 0x7FF
    ctx->r3 = ADD32(0, 0X7FF);
L_800208BC:
    // 0x800208BC: andi        $v0, $v1, 0xFFF
    ctx->r2 = ctx->r3 & 0XFFF;
    // 0x800208C0: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x800208C4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800208C8: lw          $a0, 0x63D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63D4);
    // 0x800208CC: lui         $v1, 0x700
    ctx->r3 = S32(0X700 << 16);
    // 0x800208D0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800208D4: sltu        $a0, $t0, $a0
    ctx->r4 = ctx->r8 < ctx->r4 ? 1 : 0;
    // 0x800208D8: bne         $a0, $zero, L_800208F4
    if (ctx->r4 != 0) {
        // 0x800208DC: sw          $v0, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->r2;
            goto L_800208F4;
    }
    // 0x800208DC: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x800208E0: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x800208E4: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800208E8: jal         0x80007D74
    // 0x800208EC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_24;
    // 0x800208EC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_24:
    // 0x800208F0: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_800208F4:
    // 0x800208F4: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x800208F8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800208FC: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80020900: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020904: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x80020908: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8002090C: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80020910: bne         $v1, $zero, L_8002092C
    if (ctx->r3 != 0) {
        // 0x80020914: sw          $zero, 0x4($a0)
        MEM_W(0X4, ctx->r4) = 0;
            goto L_8002092C;
    }
    // 0x80020914: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80020918: lui         $t1, 0xB500
    ctx->r9 = S32(0XB500 << 16);
    // 0x8002091C: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x80020920: jal         0x80007D74
    // 0x80020924: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_25;
    // 0x80020924: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_25:
    // 0x80020928: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_8002092C:
    // 0x8002092C: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    // 0x80020930: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020934: srl         $v1, $s1, 4
    ctx->r3 = S32(U32(ctx->r17) >> 4);
    // 0x80020938: andi        $v1, $v1, 0x1FF
    ctx->r3 = ctx->r3 & 0X1FF;
    // 0x8002093C: sll         $v1, $v1, 9
    ctx->r3 = S32(ctx->r3 << 9);
    // 0x80020940: lui         $v0, 0xF580
    ctx->r2 = S32(0XF580 << 16);
    // 0x80020944: or          $v0, $s3, $v0
    ctx->r2 = ctx->r19 | ctx->r2;
    // 0x80020948: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8002094C: andi        $v0, $s0, 0x7
    ctx->r2 = ctx->r16 & 0X7;
    // 0x80020950: sll         $s3, $v0, 24
    ctx->r19 = S32(ctx->r2 << 24);
    // 0x80020954: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x80020958: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x8002095C: andi        $v0, $s7, 0xF
    ctx->r2 = ctx->r23 & 0XF;
    // 0x80020960: sll         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2 << 14);
    // 0x80020964: andi        $a1, $s6, 0xF
    ctx->r5 = ctx->r22 & 0XF;
    // 0x80020968: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x8002096C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80020970: lw          $a0, 0x63D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63D4);
    // 0x80020974: or          $v1, $s3, $t2
    ctx->r3 = ctx->r19 | ctx->r10;
    // 0x80020978: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8002097C: sll         $v0, $a1, 10
    ctx->r2 = S32(ctx->r5 << 10);
    // 0x80020980: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80020984: or          $v1, $v1, $t1
    ctx->r3 = ctx->r3 | ctx->r9;
    // 0x80020988: andi        $v0, $fp, 0xF
    ctx->r2 = ctx->r30 & 0XF;
    // 0x8002098C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80020990: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80020994: or          $v1, $v1, $a1
    ctx->r3 = ctx->r3 | ctx->r5;
    // 0x80020998: sltu        $a0, $t0, $a0
    ctx->r4 = ctx->r8 < ctx->r4 ? 1 : 0;
    // 0x8002099C: bne         $a0, $zero, L_800209B8
    if (ctx->r4 != 0) {
        // 0x800209A0: sw          $v1, 0x4($a2)
        MEM_W(0X4, ctx->r6) = ctx->r3;
            goto L_800209B8;
    }
    // 0x800209A0: sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
    // 0x800209A4: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x800209A8: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800209AC: jal         0x80007D74
    // 0x800209B0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_26;
    // 0x800209B0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_26:
    // 0x800209B4: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_800209B8:
    // 0x800209B8: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x800209BC: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800209C0: sra         $v0, $s2, 1
    ctx->r2 = S32(SIGNED(ctx->r18) >> 1);
    // 0x800209C4: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800209C8: lhu         $t2, 0x36($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X36);
    // 0x800209CC: srl         $s5, $s4, 1
    ctx->r21 = S32(U32(ctx->r20) >> 1);
    // 0x800209D0: addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
    // 0x800209D4: addiu       $v1, $s1, -0x1
    ctx->r3 = ADD32(ctx->r17, -0X1);
    // 0x800209D8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800209DC: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x800209E0: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x800209E4: or          $v1, $s3, $v1
    ctx->r3 = ctx->r19 | ctx->r3;
    // 0x800209E8: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x800209EC: sra         $v0, $s2, 4
    ctx->r2 = S32(SIGNED(ctx->r18) >> 4);
    // 0x800209F0: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x800209F4: srl         $v0, $s1, 1
    ctx->r2 = S32(U32(ctx->r17) >> 1);
    // 0x800209F8: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x800209FC: andi        $s2, $v0, 0xFFF0
    ctx->r18 = ctx->r2 & 0XFFF0;
    // 0x80020A00: lui         $v0, 0xF200
    ctx->r2 = S32(0XF200 << 16);
    // 0x80020A04: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x80020A08: sh          $t2, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r10;
    // 0x80020A0C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80020A10: addiu       $v0, $s4, -0x1
    ctx->r2 = ADD32(ctx->r20, -0X1);
    // 0x80020A14: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80020A18: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80020A1C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80020A20: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x80020A24: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x80020A28: addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
    // 0x80020A2C: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
    // 0x80020A30: lbu         $v1, 0x2($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X2);
    // 0x80020A34: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80020A38: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80020A3C: sltu        $v1, $s0, $v1
    ctx->r3 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80020A40: bne         $v1, $zero, L_800207A0
    if (ctx->r3 != 0) {
        // 0x80020A44: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_800207A0;
    }
    // 0x80020A44: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80020A48: j           L_80021980
    // 0x80020A4C: nop

        goto L_80021980;
    // 0x80020A4C: nop

L_80020A50:
    // 0x80020A50: lbu         $t1, 0x27($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X27);
    // 0x80020A54: beq         $t1, $zero, L_80020BE4
    if (ctx->r9 == 0) {
        // 0x80020A58: nop
    
            goto L_80020BE4;
    }
    // 0x80020A58: nop

    // 0x80020A5C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80020A60: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x80020A64: sltu        $v0, $t0, $v0
    ctx->r2 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x80020A68: bne         $v0, $zero, L_80020A88
    if (ctx->r2 != 0) {
        // 0x80020A6C: addu        $a0, $t0, $zero
        ctx->r4 = ADD32(ctx->r8, 0);
            goto L_80020A88;
    }
    // 0x80020A6C: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x80020A70: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80020A74: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80020A78: jal         0x80007D74
    // 0x80020A7C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_27;
    // 0x80020A7C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_27:
    // 0x80020A80: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80020A84: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
L_80020A88:
    // 0x80020A88: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80020A8C: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80020A90: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020A94: lui         $v0, 0xE600
    ctx->r2 = S32(0XE600 << 16);
    // 0x80020A98: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80020A9C: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80020AA0: bne         $v1, $zero, L_80020ABC
    if (ctx->r3 != 0) {
        // 0x80020AA4: sw          $zero, 0x4($a0)
        MEM_W(0X4, ctx->r4) = 0;
            goto L_80020ABC;
    }
    // 0x80020AA4: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80020AA8: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80020AAC: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80020AB0: jal         0x80007D74
    // 0x80020AB4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_28;
    // 0x80020AB4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_28:
    // 0x80020AB8: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80020ABC:
    // 0x80020ABC: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x80020AC0: lui         $v0, 0xFD10
    ctx->r2 = S32(0XFD10 << 16);
    // 0x80020AC4: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80020AC8: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x80020ACC: lhu         $v0, 0xE($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0XE);
    // 0x80020AD0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80020AD4: lw          $v1, -0x7104($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7104);
    // 0x80020AD8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80020ADC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80020AE0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80020AE4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80020AE8: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x80020AEC: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020AF0: sltu        $v0, $t0, $v0
    ctx->r2 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x80020AF4: bne         $v0, $zero, L_80020B10
    if (ctx->r2 != 0) {
        // 0x80020AF8: sw          $v1, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r3;
            goto L_80020B10;
    }
    // 0x80020AF8: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x80020AFC: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80020B00: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80020B04: jal         0x80007D74
    // 0x80020B08: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_29;
    // 0x80020B08: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_29:
    // 0x80020B0C: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80020B10:
    // 0x80020B10: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x80020B14: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80020B18: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80020B1C: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020B20: lui         $v0, 0xE800
    ctx->r2 = S32(0XE800 << 16);
    // 0x80020B24: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80020B28: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80020B2C: bne         $v1, $zero, L_80020B48
    if (ctx->r3 != 0) {
        // 0x80020B30: sw          $zero, 0x4($a0)
        MEM_W(0X4, ctx->r4) = 0;
            goto L_80020B48;
    }
    // 0x80020B30: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80020B34: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80020B38: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80020B3C: jal         0x80007D74
    // 0x80020B40: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_30;
    // 0x80020B40: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_30:
    // 0x80020B44: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80020B48:
    // 0x80020B48: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x80020B4C: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020B50: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80020B54: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80020B58: lui         $v0, 0xF500
    ctx->r2 = S32(0XF500 << 16);
    // 0x80020B5C: ori         $v0, $v0, 0x100
    ctx->r2 = ctx->r2 | 0X100;
    // 0x80020B60: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80020B64: lui         $v0, 0x700
    ctx->r2 = S32(0X700 << 16);
    // 0x80020B68: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80020B6C: bne         $v1, $zero, L_80020B88
    if (ctx->r3 != 0) {
        // 0x80020B70: sw          $v0, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r2;
            goto L_80020B88;
    }
    // 0x80020B70: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x80020B74: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80020B78: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80020B7C: jal         0x80007D74
    // 0x80020B80: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_31;
    // 0x80020B80: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_31:
    // 0x80020B84: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80020B88:
    // 0x80020B88: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x80020B8C: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020B90: lui         $a1, 0x73F
    ctx->r5 = S32(0X73F << 16);
    // 0x80020B94: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80020B98: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80020B9C: ori         $a1, $a1, 0xC000
    ctx->r5 = ctx->r5 | 0XC000;
    // 0x80020BA0: lui         $v0, 0xF000
    ctx->r2 = S32(0XF000 << 16);
    // 0x80020BA4: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80020BA8: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80020BAC: bne         $v1, $zero, L_80020BC8
    if (ctx->r3 != 0) {
        // 0x80020BB0: sw          $a1, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r5;
            goto L_80020BC8;
    }
    // 0x80020BB0: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80020BB4: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80020BB8: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80020BBC: jal         0x80007D74
    // 0x80020BC0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_32;
    // 0x80020BC0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_32:
    // 0x80020BC4: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80020BC8:
    // 0x80020BC8: addu        $v1, $t0, $zero
    ctx->r3 = ADD32(ctx->r8, 0);
    // 0x80020BCC: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020BD0: lui         $v0, 0xBA00
    ctx->r2 = S32(0XBA00 << 16);
    // 0x80020BD4: ori         $v0, $v0, 0xE02
    ctx->r2 = ctx->r2 | 0XE02;
    // 0x80020BD8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80020BDC: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x80020BE0: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80020BE4:
    // 0x80020BE4: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x80020BE8: lbu         $s0, 0x1F($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X1F);
    // 0x80020BEC: andi        $a1, $s6, 0xFF
    ctx->r5 = ctx->r22 & 0XFF;
    // 0x80020BF0: lhu         $v1, 0x8($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X8);
    // 0x80020BF4: lhu         $a0, 0xA($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0XA);
    // 0x80020BF8: lbu         $v0, 0x2($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X2);
    // 0x80020BFC: srav        $v1, $v1, $a1
    ctx->r3 = S32(SIGNED(ctx->r3) >> (ctx->r5 & 31));
    // 0x80020C00: addiu       $v1, $v1, 0x7
    ctx->r3 = ADD32(ctx->r3, 0X7);
    // 0x80020C04: andi        $s2, $v1, 0xFFF8
    ctx->r18 = ctx->r3 & 0XFFF8;
    // 0x80020C08: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80020C0C: sltu        $v0, $s0, $v0
    ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x80020C10: beq         $v0, $zero, L_800219CC
    if (ctx->r2 == 0) {
        // 0x80020C14: srav        $s5, $a0, $a1
        ctx->r21 = S32(SIGNED(ctx->r4) >> (ctx->r5 & 31));
            goto L_800219CC;
    }
    // 0x80020C14: srav        $s5, $a0, $a1
    ctx->r21 = S32(SIGNED(ctx->r4) >> (ctx->r5 & 31));
    // 0x80020C18: lbu         $t2, 0x47($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X47);
    // 0x80020C1C: sll         $s1, $s1, 18
    ctx->r17 = S32(ctx->r17 << 18);
    // 0x80020C20: sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
    // 0x80020C24: andi        $v0, $t2, 0x3
    ctx->r2 = ctx->r10 & 0X3;
    // 0x80020C28: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x80020C2C: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
L_80020C30:
    // 0x80020C30: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80020C34: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x80020C38: sltu        $v0, $t0, $v0
    ctx->r2 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x80020C3C: bne         $v0, $zero, L_80020C5C
    if (ctx->r2 != 0) {
        // 0x80020C40: addu        $a0, $t0, $zero
        ctx->r4 = ADD32(ctx->r8, 0);
            goto L_80020C5C;
    }
    // 0x80020C40: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x80020C44: lui         $t1, 0xB500
    ctx->r9 = S32(0XB500 << 16);
    // 0x80020C48: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x80020C4C: jal         0x80007D74
    // 0x80020C50: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_33;
    // 0x80020C50: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_33:
    // 0x80020C54: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80020C58: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
L_80020C5C:
    // 0x80020C5C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80020C60: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80020C64: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020C68: lui         $v0, 0xE600
    ctx->r2 = S32(0XE600 << 16);
    // 0x80020C6C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80020C70: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80020C74: bne         $v1, $zero, L_80020C90
    if (ctx->r3 != 0) {
        // 0x80020C78: sw          $zero, 0x4($a0)
        MEM_W(0X4, ctx->r4) = 0;
            goto L_80020C90;
    }
    // 0x80020C78: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80020C7C: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x80020C80: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80020C84: jal         0x80007D74
    // 0x80020C88: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_34;
    // 0x80020C88: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_34:
    // 0x80020C8C: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80020C90:
    // 0x80020C90: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x80020C94: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020C98: lui         $a1, 0x708
    ctx->r5 = S32(0X708 << 16);
    // 0x80020C9C: lhu         $t1, 0x36($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X36);
    // 0x80020CA0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80020CA4: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80020CA8: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x80020CAC: lui         $v0, 0xF550
    ctx->r2 = S32(0XF550 << 16);
    // 0x80020CB0: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80020CB4: andi        $s4, $t1, 0x1FF
    ctx->r20 = ctx->r9 & 0X1FF;
    // 0x80020CB8: or          $v0, $s4, $v0
    ctx->r2 = ctx->r20 | ctx->r2;
    // 0x80020CBC: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80020CC0: bne         $v1, $zero, L_80020CDC
    if (ctx->r3 != 0) {
        // 0x80020CC4: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_80020CDC;
    }
    // 0x80020CC4: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80020CC8: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x80020CCC: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80020CD0: jal         0x80007D74
    // 0x80020CD4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_35;
    // 0x80020CD4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_35:
    // 0x80020CD8: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80020CDC:
    // 0x80020CDC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80020CE0: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80020CE4: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x80020CE8: lui         $v0, 0xFD50
    ctx->r2 = S32(0XFD50 << 16);
    // 0x80020CEC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80020CF0: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80020CF4: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020CF8: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80020CFC: bne         $v1, $zero, L_80020D18
    if (ctx->r3 != 0) {
        // 0x80020D00: sw          $t1, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r9;
            goto L_80020D18;
    }
    // 0x80020D00: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x80020D04: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x80020D08: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80020D0C: jal         0x80007D74
    // 0x80020D10: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_36;
    // 0x80020D10: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_36:
    // 0x80020D14: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80020D18:
    // 0x80020D18: andi        $s1, $s2, 0xFFFF
    ctx->r17 = ctx->r18 & 0XFFFF;
    // 0x80020D1C: andi        $s3, $s5, 0xFFFF
    ctx->r19 = ctx->r21 & 0XFFFF;
    // 0x80020D20: mult        $s1, $s3
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80020D24: mflo        $s2
    ctx->r18 = lo;
    // 0x80020D28: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x80020D2C: lui         $v0, 0xF300
    ctx->r2 = S32(0XF300 << 16);
    // 0x80020D30: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80020D34: sra         $v0, $s2, 1
    ctx->r2 = S32(SIGNED(ctx->r18) >> 1);
    // 0x80020D38: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x80020D3C: slti        $v0, $v1, 0x800
    ctx->r2 = SIGNED(ctx->r3) < 0X800 ? 1 : 0;
    // 0x80020D40: bne         $v0, $zero, L_80020D4C
    if (ctx->r2 != 0) {
        // 0x80020D44: addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_80020D4C;
    }
    // 0x80020D44: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020D48: addiu       $v1, $zero, 0x7FF
    ctx->r3 = ADD32(0, 0X7FF);
L_80020D4C:
    // 0x80020D4C: andi        $v0, $v1, 0xFFF
    ctx->r2 = ctx->r3 & 0XFFF;
    // 0x80020D50: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x80020D54: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80020D58: lw          $a0, 0x63D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63D4);
    // 0x80020D5C: lui         $v1, 0x700
    ctx->r3 = S32(0X700 << 16);
    // 0x80020D60: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80020D64: sltu        $a0, $t0, $a0
    ctx->r4 = ctx->r8 < ctx->r4 ? 1 : 0;
    // 0x80020D68: bne         $a0, $zero, L_80020D84
    if (ctx->r4 != 0) {
        // 0x80020D6C: sw          $v0, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->r2;
            goto L_80020D84;
    }
    // 0x80020D6C: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80020D70: lui         $t1, 0xB500
    ctx->r9 = S32(0XB500 << 16);
    // 0x80020D74: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x80020D78: jal         0x80007D74
    // 0x80020D7C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_37;
    // 0x80020D7C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_37:
    // 0x80020D80: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80020D84:
    // 0x80020D84: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    // 0x80020D88: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020D8C: srl         $v1, $s1, 3
    ctx->r3 = S32(U32(ctx->r17) >> 3);
    // 0x80020D90: andi        $v1, $v1, 0x1FF
    ctx->r3 = ctx->r3 & 0X1FF;
    // 0x80020D94: sll         $v1, $v1, 9
    ctx->r3 = S32(ctx->r3 << 9);
    // 0x80020D98: lui         $v0, 0xF548
    ctx->r2 = S32(0XF548 << 16);
    // 0x80020D9C: or          $v0, $s4, $v0
    ctx->r2 = ctx->r20 | ctx->r2;
    // 0x80020DA0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80020DA4: andi        $v0, $s0, 0x7
    ctx->r2 = ctx->r16 & 0X7;
    // 0x80020DA8: sll         $s4, $v0, 24
    ctx->r20 = S32(ctx->r2 << 24);
    // 0x80020DAC: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x80020DB0: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x80020DB4: andi        $v0, $s7, 0xF
    ctx->r2 = ctx->r23 & 0XF;
    // 0x80020DB8: sll         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2 << 14);
    // 0x80020DBC: andi        $a1, $s6, 0xF
    ctx->r5 = ctx->r22 & 0XF;
    // 0x80020DC0: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x80020DC4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80020DC8: lw          $a0, 0x63D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63D4);
    // 0x80020DCC: or          $v1, $s4, $t2
    ctx->r3 = ctx->r20 | ctx->r10;
    // 0x80020DD0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80020DD4: sll         $v0, $a1, 10
    ctx->r2 = S32(ctx->r5 << 10);
    // 0x80020DD8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80020DDC: or          $v1, $v1, $t1
    ctx->r3 = ctx->r3 | ctx->r9;
    // 0x80020DE0: andi        $v0, $fp, 0xF
    ctx->r2 = ctx->r30 & 0XF;
    // 0x80020DE4: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80020DE8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80020DEC: or          $v1, $v1, $a1
    ctx->r3 = ctx->r3 | ctx->r5;
    // 0x80020DF0: sltu        $a0, $t0, $a0
    ctx->r4 = ctx->r8 < ctx->r4 ? 1 : 0;
    // 0x80020DF4: bne         $a0, $zero, L_80020E10
    if (ctx->r4 != 0) {
        // 0x80020DF8: sw          $v1, 0x4($a2)
        MEM_W(0X4, ctx->r6) = ctx->r3;
            goto L_80020E10;
    }
    // 0x80020DF8: sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
    // 0x80020DFC: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x80020E00: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80020E04: jal         0x80007D74
    // 0x80020E08: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_38;
    // 0x80020E08: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_38:
    // 0x80020E0C: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80020E10:
    // 0x80020E10: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x80020E14: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020E18: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80020E1C: sra         $v0, $s2, 3
    ctx->r2 = S32(SIGNED(ctx->r18) >> 3);
    // 0x80020E20: lhu         $t2, 0x36($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X36);
    // 0x80020E24: srl         $s5, $s3, 1
    ctx->r21 = S32(U32(ctx->r19) >> 1);
    // 0x80020E28: addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
    // 0x80020E2C: addiu       $v1, $s1, -0x1
    ctx->r3 = ADD32(ctx->r17, -0X1);
    // 0x80020E30: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80020E34: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x80020E38: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x80020E3C: or          $v1, $s4, $v1
    ctx->r3 = ctx->r20 | ctx->r3;
    // 0x80020E40: addu        $t1, $t1, $s2
    ctx->r9 = ADD32(ctx->r9, ctx->r18);
    // 0x80020E44: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x80020E48: srl         $v0, $s1, 1
    ctx->r2 = S32(U32(ctx->r17) >> 1);
    // 0x80020E4C: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // 0x80020E50: andi        $s2, $v0, 0xFFF8
    ctx->r18 = ctx->r2 & 0XFFF8;
    // 0x80020E54: lui         $v0, 0xF200
    ctx->r2 = S32(0XF200 << 16);
    // 0x80020E58: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x80020E5C: sh          $t2, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r10;
    // 0x80020E60: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80020E64: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // 0x80020E68: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80020E6C: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80020E70: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80020E74: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x80020E78: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x80020E7C: addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
    // 0x80020E80: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
    // 0x80020E84: lbu         $v1, 0x2($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X2);
    // 0x80020E88: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80020E8C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80020E90: sltu        $v1, $s0, $v1
    ctx->r3 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80020E94: bne         $v1, $zero, L_80020C30
    if (ctx->r3 != 0) {
        // 0x80020E98: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_80020C30;
    }
    // 0x80020E98: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80020E9C: j           L_800219CC
    // 0x80020EA0: nop

        goto L_800219CC;
    // 0x80020EA0: nop

L_80020EA4:
    // 0x80020EA4: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x80020EA8: lhu         $v1, 0xA($t2)
    ctx->r3 = MEM_HU(ctx->r10, 0XA);
    // 0x80020EAC: lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X0);
    // 0x80020EB0: andi        $a0, $s6, 0xFF
    ctx->r4 = ctx->r22 & 0XFF;
    // 0x80020EB4: andi        $v0, $v0, 0xC000
    ctx->r2 = ctx->r2 & 0XC000;
    // 0x80020EB8: beq         $v0, $zero, L_80021164
    if (ctx->r2 == 0) {
        // 0x80020EBC: srav        $s5, $v1, $a0
        ctx->r21 = S32(SIGNED(ctx->r3) >> (ctx->r4 & 31));
            goto L_80021164;
    }
    // 0x80020EBC: srav        $s5, $v1, $a0
    ctx->r21 = S32(SIGNED(ctx->r3) >> (ctx->r4 & 31));
    // 0x80020EC0: lhu         $v0, 0x8($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X8);
    // 0x80020EC4: lbu         $s0, 0x1F($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X1F);
    // 0x80020EC8: lbu         $v1, 0x2($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X2);
    // 0x80020ECC: srav        $v0, $v0, $a0
    ctx->r2 = S32(SIGNED(ctx->r2) >> (ctx->r4 & 31));
    // 0x80020ED0: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x80020ED4: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x80020ED8: sltu        $v1, $s0, $v1
    ctx->r3 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80020EDC: beq         $v1, $zero, L_80021980
    if (ctx->r3 == 0) {
        // 0x80020EE0: andi        $s2, $v0, 0xFFFC
        ctx->r18 = ctx->r2 & 0XFFFC;
            goto L_80021980;
    }
    // 0x80020EE0: andi        $s2, $v0, 0xFFFC
    ctx->r18 = ctx->r2 & 0XFFFC;
    // 0x80020EE4: lbu         $t1, 0x47($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X47);
    // 0x80020EE8: sll         $s1, $s1, 18
    ctx->r17 = S32(ctx->r17 << 18);
    // 0x80020EEC: andi        $s6, $s6, 0xF
    ctx->r22 = ctx->r22 & 0XF;
    // 0x80020EF0: sw          $s1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r17;
    // 0x80020EF4: andi        $v0, $t1, 0x3
    ctx->r2 = ctx->r9 & 0X3;
    // 0x80020EF8: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x80020EFC: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
L_80020F00:
    // 0x80020F00: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80020F04: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x80020F08: sltu        $v0, $t0, $v0
    ctx->r2 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x80020F0C: bne         $v0, $zero, L_80020F2C
    if (ctx->r2 != 0) {
        // 0x80020F10: addu        $a0, $t0, $zero
        ctx->r4 = ADD32(ctx->r8, 0);
            goto L_80020F2C;
    }
    // 0x80020F10: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x80020F14: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x80020F18: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80020F1C: jal         0x80007D74
    // 0x80020F20: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_39;
    // 0x80020F20: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_39:
    // 0x80020F24: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80020F28: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
L_80020F2C:
    // 0x80020F2C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80020F30: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80020F34: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020F38: lui         $v0, 0xE600
    ctx->r2 = S32(0XE600 << 16);
    // 0x80020F3C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80020F40: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80020F44: bne         $v1, $zero, L_80020F60
    if (ctx->r3 != 0) {
        // 0x80020F48: sw          $zero, 0x4($a0)
        MEM_W(0X4, ctx->r4) = 0;
            goto L_80020F60;
    }
    // 0x80020F48: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80020F4C: lui         $t1, 0xB500
    ctx->r9 = S32(0XB500 << 16);
    // 0x80020F50: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x80020F54: jal         0x80007D74
    // 0x80020F58: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_40;
    // 0x80020F58: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_40:
    // 0x80020F5C: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80020F60:
    // 0x80020F60: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x80020F64: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020F68: lui         $a2, 0x708
    ctx->r6 = S32(0X708 << 16);
    // 0x80020F6C: lhu         $t2, 0x36($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X36);
    // 0x80020F70: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80020F74: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80020F78: ori         $a2, $a2, 0x200
    ctx->r6 = ctx->r6 | 0X200;
    // 0x80020F7C: lui         $v0, 0xF570
    ctx->r2 = S32(0XF570 << 16);
    // 0x80020F80: sw          $a2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r6;
    // 0x80020F84: andi        $a0, $t2, 0x1FF
    ctx->r4 = ctx->r10 & 0X1FF;
    // 0x80020F88: or          $s4, $a0, $v0
    ctx->r20 = ctx->r4 | ctx->r2;
    // 0x80020F8C: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80020F90: bne         $v1, $zero, L_80020FAC
    if (ctx->r3 != 0) {
        // 0x80020F94: sw          $s4, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r20;
            goto L_80020FAC;
    }
    // 0x80020F94: sw          $s4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r20;
    // 0x80020F98: lui         $t1, 0xB500
    ctx->r9 = S32(0XB500 << 16);
    // 0x80020F9C: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x80020FA0: jal         0x80007D74
    // 0x80020FA4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_41;
    // 0x80020FA4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_41:
    // 0x80020FA8: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80020FAC:
    // 0x80020FAC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80020FB0: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80020FB4: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x80020FB8: lui         $v0, 0xFD70
    ctx->r2 = S32(0XFD70 << 16);
    // 0x80020FBC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80020FC0: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80020FC4: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80020FC8: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80020FCC: bne         $v1, $zero, L_80020FE8
    if (ctx->r3 != 0) {
        // 0x80020FD0: sw          $t2, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r10;
            goto L_80020FE8;
    }
    // 0x80020FD0: sw          $t2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r10;
    // 0x80020FD4: lui         $t1, 0xB500
    ctx->r9 = S32(0XB500 << 16);
    // 0x80020FD8: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x80020FDC: jal         0x80007D74
    // 0x80020FE0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_42;
    // 0x80020FE0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_42:
    // 0x80020FE4: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80020FE8:
    // 0x80020FE8: andi        $s1, $s2, 0xFFFF
    ctx->r17 = ctx->r18 & 0XFFFF;
    // 0x80020FEC: andi        $s3, $s5, 0xFFFF
    ctx->r19 = ctx->r21 & 0XFFFF;
    // 0x80020FF0: mult        $s1, $s3
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80020FF4: mflo        $s2
    ctx->r18 = lo;
    // 0x80020FF8: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x80020FFC: lui         $v0, 0xF300
    ctx->r2 = S32(0XF300 << 16);
    // 0x80021000: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80021004: addiu       $v1, $s2, -0x1
    ctx->r3 = ADD32(ctx->r18, -0X1);
    // 0x80021008: slti        $v0, $v1, 0x800
    ctx->r2 = SIGNED(ctx->r3) < 0X800 ? 1 : 0;
    // 0x8002100C: bne         $v0, $zero, L_80021018
    if (ctx->r2 != 0) {
        // 0x80021010: addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_80021018;
    }
    // 0x80021010: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80021014: addiu       $v1, $zero, 0x7FF
    ctx->r3 = ADD32(0, 0X7FF);
L_80021018:
    // 0x80021018: andi        $v0, $v1, 0xFFF
    ctx->r2 = ctx->r3 & 0XFFF;
    // 0x8002101C: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x80021020: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80021024: lw          $a0, 0x63D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63D4);
    // 0x80021028: lui         $v1, 0x700
    ctx->r3 = S32(0X700 << 16);
    // 0x8002102C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80021030: sltu        $a0, $t0, $a0
    ctx->r4 = ctx->r8 < ctx->r4 ? 1 : 0;
    // 0x80021034: bne         $a0, $zero, L_80021050
    if (ctx->r4 != 0) {
        // 0x80021038: sw          $v0, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->r2;
            goto L_80021050;
    }
    // 0x80021038: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x8002103C: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x80021040: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80021044: jal         0x80007D74
    // 0x80021048: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_43;
    // 0x80021048: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_43:
    // 0x8002104C: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80021050:
    // 0x80021050: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x80021054: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80021058: srl         $v0, $s1, 2
    ctx->r2 = S32(U32(ctx->r17) >> 2);
    // 0x8002105C: andi        $v0, $v0, 0x1FF
    ctx->r2 = ctx->r2 & 0X1FF;
    // 0x80021060: sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2 << 9);
    // 0x80021064: or          $v0, $v0, $s4
    ctx->r2 = ctx->r2 | ctx->r20;
    // 0x80021068: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8002106C: andi        $v0, $s0, 0x7
    ctx->r2 = ctx->r16 & 0X7;
    // 0x80021070: sll         $s4, $v0, 24
    ctx->r20 = S32(ctx->r2 << 24);
    // 0x80021074: lw          $t1, 0x84($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X84);
    // 0x80021078: andi        $v0, $s7, 0xF
    ctx->r2 = ctx->r23 & 0XF;
    // 0x8002107C: sll         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2 << 14);
    // 0x80021080: lw          $t2, 0x8C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8C);
    // 0x80021084: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80021088: lw          $a0, 0x63D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63D4);
    // 0x8002108C: or          $v1, $s4, $t1
    ctx->r3 = ctx->r20 | ctx->r9;
    // 0x80021090: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80021094: sll         $v0, $s6, 10
    ctx->r2 = S32(ctx->r22 << 10);
    // 0x80021098: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8002109C: or          $v1, $v1, $t2
    ctx->r3 = ctx->r3 | ctx->r10;
    // 0x800210A0: andi        $v0, $fp, 0xF
    ctx->r2 = ctx->r30 & 0XF;
    // 0x800210A4: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800210A8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800210AC: or          $v1, $v1, $s6
    ctx->r3 = ctx->r3 | ctx->r22;
    // 0x800210B0: sltu        $a0, $t0, $a0
    ctx->r4 = ctx->r8 < ctx->r4 ? 1 : 0;
    // 0x800210B4: bne         $a0, $zero, L_800210D0
    if (ctx->r4 != 0) {
        // 0x800210B8: sw          $v1, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->r3;
            goto L_800210D0;
    }
    // 0x800210B8: sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    // 0x800210BC: lui         $t1, 0xB500
    ctx->r9 = S32(0XB500 << 16);
    // 0x800210C0: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x800210C4: jal         0x80007D74
    // 0x800210C8: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_44;
    // 0x800210C8: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_44:
    // 0x800210CC: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_800210D0:
    // 0x800210D0: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x800210D4: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800210D8: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    // 0x800210DC: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800210E0: lhu         $t1, 0x36($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X36);
    // 0x800210E4: srl         $s5, $s3, 1
    ctx->r21 = S32(U32(ctx->r19) >> 1);
    // 0x800210E8: addiu       $v1, $s1, -0x1
    ctx->r3 = ADD32(ctx->r17, -0X1);
    // 0x800210EC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800210F0: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x800210F4: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x800210F8: or          $v1, $s4, $v1
    ctx->r3 = ctx->r20 | ctx->r3;
    // 0x800210FC: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x80021100: sra         $v0, $s2, 2
    ctx->r2 = S32(SIGNED(ctx->r18) >> 2);
    // 0x80021104: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x80021108: srl         $v0, $s1, 1
    ctx->r2 = S32(U32(ctx->r17) >> 1);
    // 0x8002110C: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x80021110: andi        $s2, $v0, 0xFFFC
    ctx->r18 = ctx->r2 & 0XFFFC;
    // 0x80021114: lui         $v0, 0xF200
    ctx->r2 = S32(0XF200 << 16);
    // 0x80021118: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x8002111C: sh          $t1, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r9;
    // 0x80021120: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80021124: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // 0x80021128: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002112C: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80021130: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80021134: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x80021138: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x8002113C: addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
    // 0x80021140: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
    // 0x80021144: lbu         $v1, 0x2($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X2);
    // 0x80021148: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002114C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80021150: sltu        $v1, $s0, $v1
    ctx->r3 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80021154: bne         $v1, $zero, L_80020F00
    if (ctx->r3 != 0) {
        // 0x80021158: addiu       $s7, $s7, -0x1
        ctx->r23 = ADD32(ctx->r23, -0X1);
            goto L_80020F00;
    }
    // 0x80021158: addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
    // 0x8002115C: j           L_80021980
    // 0x80021160: nop

        goto L_80021980;
    // 0x80021160: nop

L_80021164:
    // 0x80021164: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x80021168: lhu         $v0, 0x8($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X8);
    // 0x8002116C: lbu         $s0, 0x1F($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X1F);
    // 0x80021170: lbu         $v1, 0x2($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X2);
    // 0x80021174: srav        $v0, $v0, $a0
    ctx->r2 = S32(SIGNED(ctx->r2) >> (ctx->r4 & 31));
    // 0x80021178: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // 0x8002117C: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x80021180: sltu        $v1, $s0, $v1
    ctx->r3 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80021184: beq         $v1, $zero, L_80021980
    if (ctx->r3 == 0) {
        // 0x80021188: andi        $s2, $v0, 0xFFF8
        ctx->r18 = ctx->r2 & 0XFFF8;
            goto L_80021980;
    }
    // 0x80021188: andi        $s2, $v0, 0xFFF8
    ctx->r18 = ctx->r2 & 0XFFF8;
    // 0x8002118C: lbu         $t2, 0x47($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X47);
    // 0x80021190: sll         $s1, $s1, 18
    ctx->r17 = S32(ctx->r17 << 18);
    // 0x80021194: sw          $s1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r17;
    // 0x80021198: andi        $v0, $t2, 0x3
    ctx->r2 = ctx->r10 & 0X3;
    // 0x8002119C: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x800211A0: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
L_800211A4:
    // 0x800211A4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800211A8: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x800211AC: sltu        $v0, $t0, $v0
    ctx->r2 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x800211B0: bne         $v0, $zero, L_800211D0
    if (ctx->r2 != 0) {
        // 0x800211B4: addu        $a0, $t0, $zero
        ctx->r4 = ADD32(ctx->r8, 0);
            goto L_800211D0;
    }
    // 0x800211B4: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x800211B8: lui         $t1, 0xB500
    ctx->r9 = S32(0XB500 << 16);
    // 0x800211BC: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x800211C0: jal         0x80007D74
    // 0x800211C4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_45;
    // 0x800211C4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_45:
    // 0x800211C8: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x800211CC: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
L_800211D0:
    // 0x800211D0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800211D4: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x800211D8: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800211DC: lui         $v0, 0xE600
    ctx->r2 = S32(0XE600 << 16);
    // 0x800211E0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800211E4: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800211E8: bne         $v1, $zero, L_80021204
    if (ctx->r3 != 0) {
        // 0x800211EC: sw          $zero, 0x4($a0)
        MEM_W(0X4, ctx->r4) = 0;
            goto L_80021204;
    }
    // 0x800211EC: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800211F0: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x800211F4: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800211F8: jal         0x80007D74
    // 0x800211FC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_46;
    // 0x800211FC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_46:
    // 0x80021200: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80021204:
    // 0x80021204: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x80021208: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8002120C: lui         $a1, 0x708
    ctx->r5 = S32(0X708 << 16);
    // 0x80021210: lhu         $t1, 0x36($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X36);
    // 0x80021214: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80021218: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x8002121C: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x80021220: lui         $v0, 0xF590
    ctx->r2 = S32(0XF590 << 16);
    // 0x80021224: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80021228: andi        $s4, $t1, 0x1FF
    ctx->r20 = ctx->r9 & 0X1FF;
    // 0x8002122C: or          $v0, $s4, $v0
    ctx->r2 = ctx->r20 | ctx->r2;
    // 0x80021230: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80021234: bne         $v1, $zero, L_80021250
    if (ctx->r3 != 0) {
        // 0x80021238: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_80021250;
    }
    // 0x80021238: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8002123C: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x80021240: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80021244: jal         0x80007D74
    // 0x80021248: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_47;
    // 0x80021248: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_47:
    // 0x8002124C: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80021250:
    // 0x80021250: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80021254: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80021258: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x8002125C: lui         $v0, 0xFD90
    ctx->r2 = S32(0XFD90 << 16);
    // 0x80021260: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80021264: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80021268: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8002126C: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80021270: bne         $v1, $zero, L_8002128C
    if (ctx->r3 != 0) {
        // 0x80021274: sw          $t1, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r9;
            goto L_8002128C;
    }
    // 0x80021274: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x80021278: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x8002127C: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80021280: jal         0x80007D74
    // 0x80021284: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_48;
    // 0x80021284: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_48:
    // 0x80021288: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_8002128C:
    // 0x8002128C: andi        $s1, $s2, 0xFFFF
    ctx->r17 = ctx->r18 & 0XFFFF;
    // 0x80021290: andi        $s3, $s5, 0xFFFF
    ctx->r19 = ctx->r21 & 0XFFFF;
    // 0x80021294: mult        $s1, $s3
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021298: mflo        $s2
    ctx->r18 = lo;
    // 0x8002129C: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x800212A0: lui         $v0, 0xF300
    ctx->r2 = S32(0XF300 << 16);
    // 0x800212A4: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800212A8: sra         $v0, $s2, 1
    ctx->r2 = S32(SIGNED(ctx->r18) >> 1);
    // 0x800212AC: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x800212B0: slti        $v0, $v1, 0x800
    ctx->r2 = SIGNED(ctx->r3) < 0X800 ? 1 : 0;
    // 0x800212B4: bne         $v0, $zero, L_800212C0
    if (ctx->r2 != 0) {
        // 0x800212B8: addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_800212C0;
    }
    // 0x800212B8: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800212BC: addiu       $v1, $zero, 0x7FF
    ctx->r3 = ADD32(0, 0X7FF);
L_800212C0:
    // 0x800212C0: andi        $v0, $v1, 0xFFF
    ctx->r2 = ctx->r3 & 0XFFF;
    // 0x800212C4: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x800212C8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800212CC: lw          $a0, 0x63D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63D4);
    // 0x800212D0: lui         $v1, 0x700
    ctx->r3 = S32(0X700 << 16);
    // 0x800212D4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800212D8: sltu        $a0, $t0, $a0
    ctx->r4 = ctx->r8 < ctx->r4 ? 1 : 0;
    // 0x800212DC: bne         $a0, $zero, L_800212F8
    if (ctx->r4 != 0) {
        // 0x800212E0: sw          $v0, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->r2;
            goto L_800212F8;
    }
    // 0x800212E0: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x800212E4: lui         $t1, 0xB500
    ctx->r9 = S32(0XB500 << 16);
    // 0x800212E8: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x800212EC: jal         0x80007D74
    // 0x800212F0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_49;
    // 0x800212F0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_49:
    // 0x800212F4: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_800212F8:
    // 0x800212F8: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    // 0x800212FC: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80021300: srl         $v1, $s1, 3
    ctx->r3 = S32(U32(ctx->r17) >> 3);
    // 0x80021304: andi        $v1, $v1, 0x1FF
    ctx->r3 = ctx->r3 & 0X1FF;
    // 0x80021308: sll         $v1, $v1, 9
    ctx->r3 = S32(ctx->r3 << 9);
    // 0x8002130C: lui         $v0, 0xF588
    ctx->r2 = S32(0XF588 << 16);
    // 0x80021310: or          $v0, $s4, $v0
    ctx->r2 = ctx->r20 | ctx->r2;
    // 0x80021314: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80021318: andi        $v0, $s0, 0x7
    ctx->r2 = ctx->r16 & 0X7;
    // 0x8002131C: sll         $s4, $v0, 24
    ctx->r20 = S32(ctx->r2 << 24);
    // 0x80021320: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x80021324: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x80021328: andi        $v0, $s7, 0xF
    ctx->r2 = ctx->r23 & 0XF;
    // 0x8002132C: sll         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2 << 14);
    // 0x80021330: andi        $a1, $s6, 0xF
    ctx->r5 = ctx->r22 & 0XF;
    // 0x80021334: lw          $t1, 0x9C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9C);
    // 0x80021338: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8002133C: lw          $a0, 0x63D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63D4);
    // 0x80021340: or          $v1, $s4, $t2
    ctx->r3 = ctx->r20 | ctx->r10;
    // 0x80021344: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80021348: sll         $v0, $a1, 10
    ctx->r2 = S32(ctx->r5 << 10);
    // 0x8002134C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80021350: or          $v1, $v1, $t1
    ctx->r3 = ctx->r3 | ctx->r9;
    // 0x80021354: andi        $v0, $fp, 0xF
    ctx->r2 = ctx->r30 & 0XF;
    // 0x80021358: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8002135C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80021360: or          $v1, $v1, $a1
    ctx->r3 = ctx->r3 | ctx->r5;
    // 0x80021364: sltu        $a0, $t0, $a0
    ctx->r4 = ctx->r8 < ctx->r4 ? 1 : 0;
    // 0x80021368: bne         $a0, $zero, L_80021384
    if (ctx->r4 != 0) {
        // 0x8002136C: sw          $v1, 0x4($a2)
        MEM_W(0X4, ctx->r6) = ctx->r3;
            goto L_80021384;
    }
    // 0x8002136C: sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
    // 0x80021370: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x80021374: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80021378: jal         0x80007D74
    // 0x8002137C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_50;
    // 0x8002137C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_50:
    // 0x80021380: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80021384:
    // 0x80021384: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x80021388: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8002138C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80021390: sra         $v0, $s2, 3
    ctx->r2 = S32(SIGNED(ctx->r18) >> 3);
    // 0x80021394: lhu         $t2, 0x36($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X36);
    // 0x80021398: srl         $s5, $s3, 1
    ctx->r21 = S32(U32(ctx->r19) >> 1);
    // 0x8002139C: addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
    // 0x800213A0: addiu       $v1, $s1, -0x1
    ctx->r3 = ADD32(ctx->r17, -0X1);
    // 0x800213A4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800213A8: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x800213AC: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x800213B0: or          $v1, $s4, $v1
    ctx->r3 = ctx->r20 | ctx->r3;
    // 0x800213B4: addu        $t1, $t1, $s2
    ctx->r9 = ADD32(ctx->r9, ctx->r18);
    // 0x800213B8: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x800213BC: srl         $v0, $s1, 1
    ctx->r2 = S32(U32(ctx->r17) >> 1);
    // 0x800213C0: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // 0x800213C4: andi        $s2, $v0, 0xFFF8
    ctx->r18 = ctx->r2 & 0XFFF8;
    // 0x800213C8: lui         $v0, 0xF200
    ctx->r2 = S32(0XF200 << 16);
    // 0x800213CC: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x800213D0: sh          $t2, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r10;
    // 0x800213D4: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800213D8: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // 0x800213DC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800213E0: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x800213E4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800213E8: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x800213EC: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x800213F0: addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
    // 0x800213F4: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
    // 0x800213F8: lbu         $v1, 0x2($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X2);
    // 0x800213FC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80021400: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80021404: sltu        $v1, $s0, $v1
    ctx->r3 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80021408: bne         $v1, $zero, L_800211A4
    if (ctx->r3 != 0) {
        // 0x8002140C: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_800211A4;
    }
    // 0x8002140C: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80021410: j           L_80021980
    // 0x80021414: nop

        goto L_80021980;
    // 0x80021414: nop

L_80021418:
    // 0x80021418: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x8002141C: lbu         $s0, 0x1F($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X1F);
    // 0x80021420: andi        $a1, $s6, 0xFF
    ctx->r5 = ctx->r22 & 0XFF;
    // 0x80021424: lhu         $v1, 0x8($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X8);
    // 0x80021428: lhu         $a0, 0xA($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0XA);
    // 0x8002142C: lbu         $v0, 0x2($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X2);
    // 0x80021430: srav        $v1, $v1, $a1
    ctx->r3 = S32(SIGNED(ctx->r3) >> (ctx->r5 & 31));
    // 0x80021434: addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
    // 0x80021438: andi        $s2, $v1, 0xFFFC
    ctx->r18 = ctx->r3 & 0XFFFC;
    // 0x8002143C: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80021440: sltu        $v0, $s0, $v0
    ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x80021444: beq         $v0, $zero, L_80021980
    if (ctx->r2 == 0) {
        // 0x80021448: srav        $s5, $a0, $a1
        ctx->r21 = S32(SIGNED(ctx->r4) >> (ctx->r5 & 31));
            goto L_80021980;
    }
    // 0x80021448: srav        $s5, $a0, $a1
    ctx->r21 = S32(SIGNED(ctx->r4) >> (ctx->r5 & 31));
    // 0x8002144C: lbu         $t2, 0x47($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X47);
    // 0x80021450: sll         $s1, $s1, 18
    ctx->r17 = S32(ctx->r17 << 18);
    // 0x80021454: sw          $s1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r17;
    // 0x80021458: andi        $v0, $t2, 0x3
    ctx->r2 = ctx->r10 & 0X3;
    // 0x8002145C: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x80021460: sw          $v0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r2;
L_80021464:
    // 0x80021464: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80021468: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x8002146C: sltu        $v0, $t0, $v0
    ctx->r2 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x80021470: bne         $v0, $zero, L_80021490
    if (ctx->r2 != 0) {
        // 0x80021474: addu        $a0, $t0, $zero
        ctx->r4 = ADD32(ctx->r8, 0);
            goto L_80021490;
    }
    // 0x80021474: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x80021478: lui         $t1, 0xB500
    ctx->r9 = S32(0XB500 << 16);
    // 0x8002147C: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x80021480: jal         0x80007D74
    // 0x80021484: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_51;
    // 0x80021484: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_51:
    // 0x80021488: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x8002148C: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
L_80021490:
    // 0x80021490: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80021494: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80021498: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8002149C: lui         $v0, 0xE600
    ctx->r2 = S32(0XE600 << 16);
    // 0x800214A0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800214A4: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800214A8: bne         $v1, $zero, L_800214C4
    if (ctx->r3 != 0) {
        // 0x800214AC: sw          $zero, 0x4($a0)
        MEM_W(0X4, ctx->r4) = 0;
            goto L_800214C4;
    }
    // 0x800214AC: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800214B0: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x800214B4: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800214B8: jal         0x80007D74
    // 0x800214BC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_52;
    // 0x800214BC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_52:
    // 0x800214C0: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_800214C4:
    // 0x800214C4: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x800214C8: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800214CC: lui         $a2, 0x708
    ctx->r6 = S32(0X708 << 16);
    // 0x800214D0: lhu         $t1, 0x36($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X36);
    // 0x800214D4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800214D8: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x800214DC: ori         $a2, $a2, 0x200
    ctx->r6 = ctx->r6 | 0X200;
    // 0x800214E0: lui         $v0, 0xF510
    ctx->r2 = S32(0XF510 << 16);
    // 0x800214E4: sw          $a2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r6;
    // 0x800214E8: andi        $a0, $t1, 0x1FF
    ctx->r4 = ctx->r9 & 0X1FF;
    // 0x800214EC: or          $s4, $a0, $v0
    ctx->r20 = ctx->r4 | ctx->r2;
    // 0x800214F0: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800214F4: bne         $v1, $zero, L_80021510
    if (ctx->r3 != 0) {
        // 0x800214F8: sw          $s4, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r20;
            goto L_80021510;
    }
    // 0x800214F8: sw          $s4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r20;
    // 0x800214FC: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x80021500: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80021504: jal         0x80007D74
    // 0x80021508: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_53;
    // 0x80021508: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_53:
    // 0x8002150C: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80021510:
    // 0x80021510: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80021514: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80021518: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x8002151C: lui         $v0, 0xFD10
    ctx->r2 = S32(0XFD10 << 16);
    // 0x80021520: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80021524: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80021528: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8002152C: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80021530: bne         $v1, $zero, L_8002154C
    if (ctx->r3 != 0) {
        // 0x80021534: sw          $t1, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r9;
            goto L_8002154C;
    }
    // 0x80021534: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x80021538: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x8002153C: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80021540: jal         0x80007D74
    // 0x80021544: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_54;
    // 0x80021544: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_54:
    // 0x80021548: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_8002154C:
    // 0x8002154C: andi        $s1, $s2, 0xFFFF
    ctx->r17 = ctx->r18 & 0XFFFF;
    // 0x80021550: andi        $s3, $s5, 0xFFFF
    ctx->r19 = ctx->r21 & 0XFFFF;
    // 0x80021554: mult        $s1, $s3
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021558: mflo        $s2
    ctx->r18 = lo;
    // 0x8002155C: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x80021560: lui         $v0, 0xF300
    ctx->r2 = S32(0XF300 << 16);
    // 0x80021564: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80021568: addiu       $v1, $s2, -0x1
    ctx->r3 = ADD32(ctx->r18, -0X1);
    // 0x8002156C: slti        $v0, $v1, 0x800
    ctx->r2 = SIGNED(ctx->r3) < 0X800 ? 1 : 0;
    // 0x80021570: bne         $v0, $zero, L_8002157C
    if (ctx->r2 != 0) {
        // 0x80021574: addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_8002157C;
    }
    // 0x80021574: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80021578: addiu       $v1, $zero, 0x7FF
    ctx->r3 = ADD32(0, 0X7FF);
L_8002157C:
    // 0x8002157C: andi        $v0, $v1, 0xFFF
    ctx->r2 = ctx->r3 & 0XFFF;
    // 0x80021580: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x80021584: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80021588: lw          $a0, 0x63D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63D4);
    // 0x8002158C: lui         $v1, 0x700
    ctx->r3 = S32(0X700 << 16);
    // 0x80021590: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80021594: sltu        $a0, $t0, $a0
    ctx->r4 = ctx->r8 < ctx->r4 ? 1 : 0;
    // 0x80021598: bne         $a0, $zero, L_800215B4
    if (ctx->r4 != 0) {
        // 0x8002159C: sw          $v0, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->r2;
            goto L_800215B4;
    }
    // 0x8002159C: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x800215A0: lui         $t1, 0xB500
    ctx->r9 = S32(0XB500 << 16);
    // 0x800215A4: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x800215A8: jal         0x80007D74
    // 0x800215AC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_55;
    // 0x800215AC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_55:
    // 0x800215B0: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_800215B4:
    // 0x800215B4: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    // 0x800215B8: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800215BC: srl         $v0, $s1, 2
    ctx->r2 = S32(U32(ctx->r17) >> 2);
    // 0x800215C0: andi        $v0, $v0, 0x1FF
    ctx->r2 = ctx->r2 & 0X1FF;
    // 0x800215C4: sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2 << 9);
    // 0x800215C8: or          $v0, $v0, $s4
    ctx->r2 = ctx->r2 | ctx->r20;
    // 0x800215CC: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x800215D0: andi        $v0, $s0, 0x7
    ctx->r2 = ctx->r16 & 0X7;
    // 0x800215D4: sll         $s4, $v0, 24
    ctx->r20 = S32(ctx->r2 << 24);
    // 0x800215D8: lw          $t2, 0xA4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA4);
    // 0x800215DC: andi        $v0, $s7, 0xF
    ctx->r2 = ctx->r23 & 0XF;
    // 0x800215E0: sll         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2 << 14);
    // 0x800215E4: andi        $a1, $s6, 0xF
    ctx->r5 = ctx->r22 & 0XF;
    // 0x800215E8: lw          $t1, 0xAC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XAC);
    // 0x800215EC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800215F0: lw          $a0, 0x63D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63D4);
    // 0x800215F4: or          $v1, $s4, $t2
    ctx->r3 = ctx->r20 | ctx->r10;
    // 0x800215F8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800215FC: sll         $v0, $a1, 10
    ctx->r2 = S32(ctx->r5 << 10);
    // 0x80021600: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80021604: or          $v1, $v1, $t1
    ctx->r3 = ctx->r3 | ctx->r9;
    // 0x80021608: andi        $v0, $fp, 0xF
    ctx->r2 = ctx->r30 & 0XF;
    // 0x8002160C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80021610: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80021614: or          $v1, $v1, $a1
    ctx->r3 = ctx->r3 | ctx->r5;
    // 0x80021618: sltu        $a0, $t0, $a0
    ctx->r4 = ctx->r8 < ctx->r4 ? 1 : 0;
    // 0x8002161C: bne         $a0, $zero, L_80021638
    if (ctx->r4 != 0) {
        // 0x80021620: sw          $v1, 0x4($a2)
        MEM_W(0X4, ctx->r6) = ctx->r3;
            goto L_80021638;
    }
    // 0x80021620: sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
    // 0x80021624: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x80021628: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x8002162C: jal         0x80007D74
    // 0x80021630: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_56;
    // 0x80021630: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_56:
    // 0x80021634: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80021638:
    // 0x80021638: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x8002163C: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80021640: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    // 0x80021644: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80021648: lhu         $t2, 0x36($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X36);
    // 0x8002164C: srl         $s5, $s3, 1
    ctx->r21 = S32(U32(ctx->r19) >> 1);
    // 0x80021650: addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
    // 0x80021654: addiu       $v1, $s1, -0x1
    ctx->r3 = ADD32(ctx->r17, -0X1);
    // 0x80021658: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8002165C: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x80021660: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x80021664: or          $v1, $s4, $v1
    ctx->r3 = ctx->r20 | ctx->r3;
    // 0x80021668: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x8002166C: sra         $v0, $s2, 2
    ctx->r2 = S32(SIGNED(ctx->r18) >> 2);
    // 0x80021670: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x80021674: srl         $v0, $s1, 1
    ctx->r2 = S32(U32(ctx->r17) >> 1);
    // 0x80021678: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x8002167C: andi        $s2, $v0, 0xFFFC
    ctx->r18 = ctx->r2 & 0XFFFC;
    // 0x80021680: lui         $v0, 0xF200
    ctx->r2 = S32(0XF200 << 16);
    // 0x80021684: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x80021688: sh          $t2, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r10;
    // 0x8002168C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80021690: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // 0x80021694: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80021698: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8002169C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800216A0: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x800216A4: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x800216A8: addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
    // 0x800216AC: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
    // 0x800216B0: lbu         $v1, 0x2($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X2);
    // 0x800216B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800216B8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800216BC: sltu        $v1, $s0, $v1
    ctx->r3 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x800216C0: bne         $v1, $zero, L_80021464
    if (ctx->r3 != 0) {
        // 0x800216C4: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_80021464;
    }
    // 0x800216C4: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800216C8: j           L_80021980
    // 0x800216CC: nop

        goto L_80021980;
    // 0x800216CC: nop

L_800216D0:
    // 0x800216D0: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x800216D4: lbu         $s0, 0x1F($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X1F);
    // 0x800216D8: andi        $a1, $s6, 0xFF
    ctx->r5 = ctx->r22 & 0XFF;
    // 0x800216DC: lhu         $v1, 0x8($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X8);
    // 0x800216E0: lhu         $a0, 0xA($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0XA);
    // 0x800216E4: lbu         $v0, 0x2($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X2);
    // 0x800216E8: srav        $v1, $v1, $a1
    ctx->r3 = S32(SIGNED(ctx->r3) >> (ctx->r5 & 31));
    // 0x800216EC: addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
    // 0x800216F0: andi        $s2, $v1, 0xFFFC
    ctx->r18 = ctx->r3 & 0XFFFC;
    // 0x800216F4: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800216F8: sltu        $v0, $s0, $v0
    ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800216FC: beq         $v0, $zero, L_80021980
    if (ctx->r2 == 0) {
        // 0x80021700: srav        $s5, $a0, $a1
        ctx->r21 = S32(SIGNED(ctx->r4) >> (ctx->r5 & 31));
            goto L_80021980;
    }
    // 0x80021700: srav        $s5, $a0, $a1
    ctx->r21 = S32(SIGNED(ctx->r4) >> (ctx->r5 & 31));
    // 0x80021704: lbu         $t2, 0x47($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X47);
    // 0x80021708: sll         $s1, $s1, 18
    ctx->r17 = S32(ctx->r17 << 18);
    // 0x8002170C: sw          $s1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r17;
    // 0x80021710: andi        $v0, $t2, 0x3
    ctx->r2 = ctx->r10 & 0X3;
    // 0x80021714: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x80021718: sw          $v0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r2;
L_8002171C:
    // 0x8002171C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80021720: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x80021724: sltu        $v0, $t0, $v0
    ctx->r2 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x80021728: bne         $v0, $zero, L_80021748
    if (ctx->r2 != 0) {
        // 0x8002172C: addu        $a0, $t0, $zero
        ctx->r4 = ADD32(ctx->r8, 0);
            goto L_80021748;
    }
    // 0x8002172C: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x80021730: lui         $t1, 0xB500
    ctx->r9 = S32(0XB500 << 16);
    // 0x80021734: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x80021738: jal         0x80007D74
    // 0x8002173C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_57;
    // 0x8002173C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_57:
    // 0x80021740: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80021744: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
L_80021748:
    // 0x80021748: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8002174C: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80021750: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80021754: lui         $v0, 0xE600
    ctx->r2 = S32(0XE600 << 16);
    // 0x80021758: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8002175C: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80021760: bne         $v1, $zero, L_8002177C
    if (ctx->r3 != 0) {
        // 0x80021764: sw          $zero, 0x4($a0)
        MEM_W(0X4, ctx->r4) = 0;
            goto L_8002177C;
    }
    // 0x80021764: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80021768: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x8002176C: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80021770: jal         0x80007D74
    // 0x80021774: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_58;
    // 0x80021774: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_58:
    // 0x80021778: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_8002177C:
    // 0x8002177C: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x80021780: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80021784: lui         $a2, 0x708
    ctx->r6 = S32(0X708 << 16);
    // 0x80021788: lhu         $t1, 0x36($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X36);
    // 0x8002178C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80021790: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80021794: ori         $a2, $a2, 0x200
    ctx->r6 = ctx->r6 | 0X200;
    // 0x80021798: lui         $v0, 0xF518
    ctx->r2 = S32(0XF518 << 16);
    // 0x8002179C: sw          $a2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r6;
    // 0x800217A0: andi        $a0, $t1, 0x1FF
    ctx->r4 = ctx->r9 & 0X1FF;
    // 0x800217A4: or          $s4, $a0, $v0
    ctx->r20 = ctx->r4 | ctx->r2;
    // 0x800217A8: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800217AC: bne         $v1, $zero, L_800217C8
    if (ctx->r3 != 0) {
        // 0x800217B0: sw          $s4, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r20;
            goto L_800217C8;
    }
    // 0x800217B0: sw          $s4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r20;
    // 0x800217B4: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x800217B8: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800217BC: jal         0x80007D74
    // 0x800217C0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_59;
    // 0x800217C0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_59:
    // 0x800217C4: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_800217C8:
    // 0x800217C8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800217CC: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x800217D0: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x800217D4: lui         $v0, 0xFD18
    ctx->r2 = S32(0XFD18 << 16);
    // 0x800217D8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800217DC: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800217E0: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800217E4: sltu        $v1, $t0, $v1
    ctx->r3 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800217E8: bne         $v1, $zero, L_80021804
    if (ctx->r3 != 0) {
        // 0x800217EC: sw          $t1, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r9;
            goto L_80021804;
    }
    // 0x800217EC: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x800217F0: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x800217F4: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800217F8: jal         0x80007D74
    // 0x800217FC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_60;
    // 0x800217FC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_60:
    // 0x80021800: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80021804:
    // 0x80021804: andi        $s1, $s2, 0xFFFF
    ctx->r17 = ctx->r18 & 0XFFFF;
    // 0x80021808: andi        $s3, $s5, 0xFFFF
    ctx->r19 = ctx->r21 & 0XFFFF;
    // 0x8002180C: mult        $s1, $s3
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021810: mflo        $s2
    ctx->r18 = lo;
    // 0x80021814: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x80021818: lui         $v0, 0xF300
    ctx->r2 = S32(0XF300 << 16);
    // 0x8002181C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80021820: addiu       $v1, $s2, -0x1
    ctx->r3 = ADD32(ctx->r18, -0X1);
    // 0x80021824: slti        $v0, $v1, 0x800
    ctx->r2 = SIGNED(ctx->r3) < 0X800 ? 1 : 0;
    // 0x80021828: bne         $v0, $zero, L_80021834
    if (ctx->r2 != 0) {
        // 0x8002182C: addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_80021834;
    }
    // 0x8002182C: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80021830: addiu       $v1, $zero, 0x7FF
    ctx->r3 = ADD32(0, 0X7FF);
L_80021834:
    // 0x80021834: andi        $v0, $v1, 0xFFF
    ctx->r2 = ctx->r3 & 0XFFF;
    // 0x80021838: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x8002183C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80021840: lw          $a0, 0x63D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63D4);
    // 0x80021844: lui         $v1, 0x700
    ctx->r3 = S32(0X700 << 16);
    // 0x80021848: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8002184C: sltu        $a0, $t0, $a0
    ctx->r4 = ctx->r8 < ctx->r4 ? 1 : 0;
    // 0x80021850: bne         $a0, $zero, L_8002186C
    if (ctx->r4 != 0) {
        // 0x80021854: sw          $v0, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->r2;
            goto L_8002186C;
    }
    // 0x80021854: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80021858: lui         $t1, 0xB500
    ctx->r9 = S32(0XB500 << 16);
    // 0x8002185C: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x80021860: jal         0x80007D74
    // 0x80021864: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_61;
    // 0x80021864: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_61:
    // 0x80021868: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_8002186C:
    // 0x8002186C: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    // 0x80021870: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80021874: srl         $v0, $s1, 2
    ctx->r2 = S32(U32(ctx->r17) >> 2);
    // 0x80021878: andi        $v0, $v0, 0x1FF
    ctx->r2 = ctx->r2 & 0X1FF;
    // 0x8002187C: sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2 << 9);
    // 0x80021880: or          $v0, $v0, $s4
    ctx->r2 = ctx->r2 | ctx->r20;
    // 0x80021884: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80021888: andi        $v0, $s0, 0x7
    ctx->r2 = ctx->r16 & 0X7;
    // 0x8002188C: sll         $s4, $v0, 24
    ctx->r20 = S32(ctx->r2 << 24);
    // 0x80021890: lw          $t2, 0xB4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB4);
    // 0x80021894: andi        $v0, $s7, 0xF
    ctx->r2 = ctx->r23 & 0XF;
    // 0x80021898: sll         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2 << 14);
    // 0x8002189C: andi        $a1, $s6, 0xF
    ctx->r5 = ctx->r22 & 0XF;
    // 0x800218A0: lw          $t1, 0xBC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XBC);
    // 0x800218A4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800218A8: lw          $a0, 0x63D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63D4);
    // 0x800218AC: or          $v1, $s4, $t2
    ctx->r3 = ctx->r20 | ctx->r10;
    // 0x800218B0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800218B4: sll         $v0, $a1, 10
    ctx->r2 = S32(ctx->r5 << 10);
    // 0x800218B8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800218BC: or          $v1, $v1, $t1
    ctx->r3 = ctx->r3 | ctx->r9;
    // 0x800218C0: andi        $v0, $fp, 0xF
    ctx->r2 = ctx->r30 & 0XF;
    // 0x800218C4: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800218C8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800218CC: or          $v1, $v1, $a1
    ctx->r3 = ctx->r3 | ctx->r5;
    // 0x800218D0: sltu        $a0, $t0, $a0
    ctx->r4 = ctx->r8 < ctx->r4 ? 1 : 0;
    // 0x800218D4: bne         $a0, $zero, L_800218F0
    if (ctx->r4 != 0) {
        // 0x800218D8: sw          $v1, 0x4($a2)
        MEM_W(0X4, ctx->r6) = ctx->r3;
            goto L_800218F0;
    }
    // 0x800218D8: sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
    // 0x800218DC: lui         $t2, 0xB500
    ctx->r10 = S32(0XB500 << 16);
    // 0x800218E0: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800218E4: jal         0x80007D74
    // 0x800218E8: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_62;
    // 0x800218E8: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_62:
    // 0x800218EC: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_800218F0:
    // 0x800218F0: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x800218F4: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800218F8: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    // 0x800218FC: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80021900: lhu         $t2, 0x36($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X36);
    // 0x80021904: srl         $s5, $s3, 1
    ctx->r21 = S32(U32(ctx->r19) >> 1);
    // 0x80021908: addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
    // 0x8002190C: addiu       $v1, $s1, -0x1
    ctx->r3 = ADD32(ctx->r17, -0X1);
    // 0x80021910: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80021914: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x80021918: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x8002191C: or          $v1, $s4, $v1
    ctx->r3 = ctx->r20 | ctx->r3;
    // 0x80021920: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x80021924: sra         $v0, $s2, 2
    ctx->r2 = S32(SIGNED(ctx->r18) >> 2);
    // 0x80021928: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x8002192C: srl         $v0, $s1, 1
    ctx->r2 = S32(U32(ctx->r17) >> 1);
    // 0x80021930: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x80021934: andi        $s2, $v0, 0xFFFC
    ctx->r18 = ctx->r2 & 0XFFFC;
    // 0x80021938: lui         $v0, 0xF200
    ctx->r2 = S32(0XF200 << 16);
    // 0x8002193C: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x80021940: sh          $t2, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r10;
    // 0x80021944: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80021948: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // 0x8002194C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80021950: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80021954: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80021958: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x8002195C: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x80021960: addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
    // 0x80021964: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
    // 0x80021968: lbu         $v1, 0x2($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X2);
    // 0x8002196C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80021970: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80021974: sltu        $v1, $s0, $v1
    ctx->r3 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80021978: bne         $v1, $zero, L_8002171C
    if (ctx->r3 != 0) {
        // 0x8002197C: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_8002171C;
    }
    // 0x8002197C: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
L_80021980:
    // 0x80021980: lbu         $t2, 0x27($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X27);
    // 0x80021984: beq         $t2, $zero, L_800219CC
    if (ctx->r10 == 0) {
        // 0x80021988: nop
    
            goto L_800219CC;
    }
    // 0x80021988: nop

    // 0x8002198C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80021990: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x80021994: sltu        $v0, $t0, $v0
    ctx->r2 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x80021998: bne         $v0, $zero, L_800219B8
    if (ctx->r2 != 0) {
        // 0x8002199C: addu        $v1, $t0, $zero
        ctx->r3 = ADD32(ctx->r8, 0);
            goto L_800219B8;
    }
    // 0x8002199C: addu        $v1, $t0, $zero
    ctx->r3 = ADD32(ctx->r8, 0);
    // 0x800219A0: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x800219A4: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x800219A8: jal         0x80007D74
    // 0x800219AC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_63;
    // 0x800219AC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_63:
    // 0x800219B0: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x800219B4: addu        $v1, $t0, $zero
    ctx->r3 = ADD32(ctx->r8, 0);
L_800219B8:
    // 0x800219B8: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800219BC: lui         $v0, 0xBA00
    ctx->r2 = S32(0XBA00 << 16);
    // 0x800219C0: ori         $v0, $v0, 0xE02
    ctx->r2 = ctx->r2 | 0XE02;
    // 0x800219C4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800219C8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_800219CC:
    // 0x800219CC: lhu         $t2, 0x36($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X36);
    // 0x800219D0: lw          $t1, 0xFC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XFC);
    // 0x800219D4: sh          $t2, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r10;
    // 0x800219D8: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800219DC: lw          $t1, 0x100($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X100);
    // 0x800219E0: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    // 0x800219E4: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x800219E8: lw          $ra, 0xE4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XE4);
    // 0x800219EC: lw          $fp, 0xE0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XE0);
    // 0x800219F0: lw          $s7, 0xDC($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XDC);
    // 0x800219F4: lw          $s6, 0xD8($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XD8);
    // 0x800219F8: lw          $s5, 0xD4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XD4);
    // 0x800219FC: lw          $s4, 0xD0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XD0);
    // 0x80021A00: lw          $s3, 0xCC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XCC);
    // 0x80021A04: lw          $s2, 0xC8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC8);
    // 0x80021A08: lw          $s1, 0xC4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC4);
    // 0x80021A0C: lw          $s0, 0xC0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XC0);
    // 0x80021A10: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    // 0x80021A14: jr          $ra
    // 0x80021A18: nop

    return;
    // 0x80021A18: nop

;}
RECOMP_FUNC void func_80021A1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021A1C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80021A20: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80021A24: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x80021A28: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80021A2C: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x80021A30: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80021A34: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x80021A38: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80021A3C: lw          $v1, -0x70F8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X70F8);
    // 0x80021A40: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80021A44: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80021A48: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80021A4C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80021A50: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80021A54: addiu       $s2, $sp, 0x20
    ctx->r18 = ADD32(ctx->r29, 0X20);
    // 0x80021A58: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80021A5C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80021A60: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80021A64: addu        $s1, $v1, $v0
    ctx->r17 = ADD32(ctx->r3, ctx->r2);
    // 0x80021A68: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x80021A6C: addiu       $s0, $sp, 0x24
    ctx->r16 = ADD32(ctx->r29, 0X24);
    // 0x80021A70: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80021A74: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
    // 0x80021A78: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80021A7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80021A80: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80021A84: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x80021A88: jal         0x8001FE74
    // 0x80021A8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_8001FE74(rdram, ctx);
        goto after_0;
    // 0x80021A8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80021A90: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x80021A94: andi        $v1, $v1, 0x1C00
    ctx->r3 = ctx->r3 & 0X1C00;
    // 0x80021A98: beq         $v1, $zero, L_80021AC4
    if (ctx->r3 == 0) {
        // 0x80021A9C: addu        $a3, $v0, $zero
        ctx->r7 = ADD32(ctx->r2, 0);
            goto L_80021AC4;
    }
    // 0x80021A9C: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x80021AA0: addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
    // 0x80021AA4: lbu         $a2, 0x3($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X3);
    // 0x80021AA8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80021AAC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80021AB0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80021AB4: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x80021AB8: jal         0x8001FE74
    // 0x80021ABC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_8001FE74(rdram, ctx);
        goto after_1;
    // 0x80021ABC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_1:
    // 0x80021AC0: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
L_80021AC4:
    // 0x80021AC4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80021AC8: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x80021ACC: sltu        $v0, $a3, $v0
    ctx->r2 = ctx->r7 < ctx->r2 ? 1 : 0;
    // 0x80021AD0: bne         $v0, $zero, L_80021AE8
    if (ctx->r2 != 0) {
        // 0x80021AD4: lui         $v0, 0xB500
        ctx->r2 = S32(0XB500 << 16);
            goto L_80021AE8;
    }
    // 0x80021AD4: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80021AD8: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80021ADC: jal         0x80007D74
    // 0x80021AE0: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    func_80007D74(rdram, ctx);
        goto after_2;
    // 0x80021AE0: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    after_2:
    // 0x80021AE4: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
L_80021AE8:
    // 0x80021AE8: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
    // 0x80021AEC: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80021AF0: bne         $v0, $zero, L_80021B18
    if (ctx->r2 != 0) {
        // 0x80021AF4: addu        $v1, $a3, $zero
        ctx->r3 = ADD32(ctx->r7, 0);
            goto L_80021B18;
    }
    // 0x80021AF4: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
    // 0x80021AF8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80021AFC: lui         $v0, 0xBA00
    ctx->r2 = S32(0XBA00 << 16);
    // 0x80021B00: ori         $v0, $v0, 0x1001
    ctx->r2 = ctx->r2 | 0X1001;
    // 0x80021B04: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
    // 0x80021B08: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80021B0C: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80021B10: j           L_80021B30
    // 0x80021B14: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
        goto L_80021B30;
    // 0x80021B14: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80021B18:
    // 0x80021B18: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80021B1C: lui         $v0, 0xBA00
    ctx->r2 = S32(0XBA00 << 16);
    // 0x80021B20: ori         $v0, $v0, 0x1001
    ctx->r2 = ctx->r2 | 0X1001;
    // 0x80021B24: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80021B28: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80021B2C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_80021B30:
    // 0x80021B30: andi        $v0, $s3, 0x1
    ctx->r2 = ctx->r19 & 0X1;
    // 0x80021B34: bnel        $v0, $zero, L_80021B3C
    if (ctx->r2 != 0) {
        // 0x80021B38: ori         $s0, $s0, 0x1
        ctx->r16 = ctx->r16 | 0X1;
            goto L_80021B3C;
    }
    goto skip_0;
    // 0x80021B38: ori         $s0, $s0, 0x1
    ctx->r16 = ctx->r16 | 0X1;
    skip_0:
L_80021B3C:
    // 0x80021B3C: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x80021B40: andi        $v0, $v1, 0xA000
    ctx->r2 = ctx->r3 & 0XA000;
    // 0x80021B44: bnel        $v0, $zero, L_80021B4C
    if (ctx->r2 != 0) {
        // 0x80021B48: ori         $s0, $s0, 0x2
        ctx->r16 = ctx->r16 | 0X2;
            goto L_80021B4C;
    }
    goto skip_1;
    // 0x80021B48: ori         $s0, $s0, 0x2
    ctx->r16 = ctx->r16 | 0X2;
    skip_1:
L_80021B4C:
    // 0x80021B4C: andi        $v0, $v1, 0xC00
    ctx->r2 = ctx->r3 & 0XC00;
    // 0x80021B50: bnel        $v0, $zero, L_80021B58
    if (ctx->r2 != 0) {
        // 0x80021B54: ori         $s0, $s0, 0x12
        ctx->r16 = ctx->r16 | 0X12;
            goto L_80021B58;
    }
    goto skip_2;
    // 0x80021B54: ori         $s0, $s0, 0x12
    ctx->r16 = ctx->r16 | 0X12;
    skip_2:
L_80021B58:
    // 0x80021B58: andi        $v0, $s3, 0x2
    ctx->r2 = ctx->r19 & 0X2;
    // 0x80021B5C: bnel        $v0, $zero, L_80021B64
    if (ctx->r2 != 0) {
        // 0x80021B60: ori         $s0, $s0, 0x8
        ctx->r16 = ctx->r16 | 0X8;
            goto L_80021B64;
    }
    goto skip_3;
    // 0x80021B60: ori         $s0, $s0, 0x8
    ctx->r16 = ctx->r16 | 0X8;
    skip_3:
L_80021B64:
    // 0x80021B64: andi        $v0, $s3, 0x4
    ctx->r2 = ctx->r19 & 0X4;
    // 0x80021B68: bnel        $v0, $zero, L_80021B70
    if (ctx->r2 != 0) {
        // 0x80021B6C: ori         $s0, $s0, 0x100
        ctx->r16 = ctx->r16 | 0X100;
            goto L_80021B70;
    }
    goto skip_4;
    // 0x80021B6C: ori         $s0, $s0, 0x100
    ctx->r16 = ctx->r16 | 0X100;
    skip_4:
L_80021B70:
    // 0x80021B70: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80021B74: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x80021B78: sltu        $v0, $a3, $v0
    ctx->r2 = ctx->r7 < ctx->r2 ? 1 : 0;
    // 0x80021B7C: bne         $v0, $zero, L_80021B94
    if (ctx->r2 != 0) {
        // 0x80021B80: lui         $v0, 0xB500
        ctx->r2 = S32(0XB500 << 16);
            goto L_80021B94;
    }
    // 0x80021B80: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80021B84: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80021B88: jal         0x80007D74
    // 0x80021B8C: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    func_80007D74(rdram, ctx);
        goto after_3;
    // 0x80021B8C: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    after_3:
    // 0x80021B90: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
L_80021B94:
    // 0x80021B94: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x80021B98: andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // 0x80021B9C: beq         $v0, $zero, L_80021BD0
    if (ctx->r2 == 0) {
        // 0x80021BA0: addu        $v1, $a3, $zero
        ctx->r3 = ADD32(ctx->r7, 0);
            goto L_80021BD0;
    }
    // 0x80021BA0: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
    // 0x80021BA4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80021BA8: lui         $v0, 0xB900
    ctx->r2 = S32(0XB900 << 16);
    // 0x80021BAC: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // 0x80021BB0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80021BB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80021BB8: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80021BBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80021BC0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80021BC4: sb          $v0, 0x43A8($at)
    MEM_B(0X43A8, ctx->r1) = ctx->r2;
    // 0x80021BC8: j           L_80021BEC
    // 0x80021BCC: ori         $s0, $s0, 0x40
    ctx->r16 = ctx->r16 | 0X40;
        goto L_80021BEC;
    // 0x80021BCC: ori         $s0, $s0, 0x40
    ctx->r16 = ctx->r16 | 0X40;
L_80021BD0:
    // 0x80021BD0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80021BD4: lui         $v0, 0xB900
    ctx->r2 = S32(0XB900 << 16);
    // 0x80021BD8: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // 0x80021BDC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80021BE0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80021BE4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80021BE8: sb          $zero, 0x43A8($at)
    MEM_B(0X43A8, ctx->r1) = 0;
L_80021BEC:
    // 0x80021BEC: andi        $v0, $s0, 0x7F
    ctx->r2 = ctx->r16 & 0X7F;
    // 0x80021BF0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80021BF4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021BF8: lbu         $v1, -0x77A0($at)
    ctx->r3 = MEM_BU(ctx->r1, -0X77A0);
    // 0x80021BFC: sb          $v1, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r3;
    // 0x80021C00: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80021C04: lbu         $v0, -0x56F8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X56F8);
    // 0x80021C08: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80021C0C: bnel        $v0, $zero, L_80021C4C
    if (ctx->r2 != 0) {
        // 0x80021C10: ori         $s0, $s0, 0x80
        ctx->r16 = ctx->r16 | 0X80;
            goto L_80021C4C;
    }
    goto skip_5;
    // 0x80021C10: ori         $s0, $s0, 0x80
    ctx->r16 = ctx->r16 | 0X80;
    skip_5:
    // 0x80021C14: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80021C18: sb          $v1, -0x56F8($at)
    MEM_B(-0X56F8, ctx->r1) = ctx->r3;
    // 0x80021C1C: andi        $v1, $v1, 0x7F
    ctx->r3 = ctx->r3 & 0X7F;
    // 0x80021C20: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80021C24: beql        $v1, $v0, L_80021C4C
    if (ctx->r3 == ctx->r2) {
        // 0x80021C28: ori         $s0, $s0, 0x80
        ctx->r16 = ctx->r16 | 0X80;
            goto L_80021C4C;
    }
    goto skip_6;
    // 0x80021C28: ori         $s0, $s0, 0x80
    ctx->r16 = ctx->r16 | 0X80;
    skip_6:
    // 0x80021C2C: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x80021C30: andi        $v0, $v0, 0x1C00
    ctx->r2 = ctx->r2 & 0X1C00;
    // 0x80021C34: beq         $v0, $zero, L_80021C4C
    if (ctx->r2 == 0) {
        // 0x80021C38: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80021C4C;
    }
    // 0x80021C38: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80021C3C: ori         $s0, $s0, 0x80
    ctx->r16 = ctx->r16 | 0X80;
    // 0x80021C40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80021C44: sb          $v0, -0x56F8($at)
    MEM_B(-0X56F8, ctx->r1) = ctx->r2;
    // 0x80021C48: sb          $v0, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r2;
L_80021C4C:
    // 0x80021C4C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80021C50: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x80021C54: sltu        $v0, $a3, $v0
    ctx->r2 = ctx->r7 < ctx->r2 ? 1 : 0;
    // 0x80021C58: bne         $v0, $zero, L_80021C78
    if (ctx->r2 != 0) {
        // 0x80021C5C: andi        $v0, $s0, 0xFFFF
        ctx->r2 = ctx->r16 & 0XFFFF;
            goto L_80021C78;
    }
    // 0x80021C5C: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x80021C60: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80021C64: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80021C68: jal         0x80007D74
    // 0x80021C6C: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    func_80007D74(rdram, ctx);
        goto after_4;
    // 0x80021C6C: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    after_4:
    // 0x80021C70: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x80021C74: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
L_80021C78:
    // 0x80021C78: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021C7C: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x80021C80: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021C84: lw          $v1, 0x7860($at)
    ctx->r3 = MEM_W(ctx->r1, 0X7860);
    // 0x80021C88: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x80021C8C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021C90: lw          $a0, 0x7864($at)
    ctx->r4 = MEM_W(ctx->r1, 0X7864);
    // 0x80021C94: sw          $v1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r3;
    // 0x80021C98: sw          $a0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r4;
    // 0x80021C9C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80021CA0: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x80021CA4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80021CA8: sltu        $v0, $a3, $v0
    ctx->r2 = ctx->r7 < ctx->r2 ? 1 : 0;
    // 0x80021CAC: bne         $v0, $zero, L_80021CCC
    if (ctx->r2 != 0) {
        // 0x80021CB0: addu        $a1, $a3, $zero
        ctx->r5 = ADD32(ctx->r7, 0);
            goto L_80021CCC;
    }
    // 0x80021CB0: addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
    // 0x80021CB4: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80021CB8: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80021CBC: jal         0x80007D74
    // 0x80021CC0: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    func_80007D74(rdram, ctx);
        goto after_5;
    // 0x80021CC0: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    after_5:
    // 0x80021CC4: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x80021CC8: addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
L_80021CCC:
    // 0x80021CCC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80021CD0: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
    // 0x80021CD4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80021CD8: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80021CDC: lui         $a0, 0xBB00
    ctx->r4 = S32(0XBB00 << 16);
    // 0x80021CE0: ori         $a0, $a0, 0x1
    ctx->r4 = ctx->r4 | 0X1;
    // 0x80021CE4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80021CE8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80021CEC: andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // 0x80021CF0: sll         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2 << 11);
    // 0x80021CF4: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x80021CF8: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80021CFC: addiu       $v0, $a3, 0x10
    ctx->r2 = ADD32(ctx->r7, 0X10);
    // 0x80021D00: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80021D04: bne         $v0, $zero, L_80021D24
    if (ctx->r2 != 0) {
        // 0x80021D08: lui         $v0, 0x382
        ctx->r2 = S32(0X382 << 16);
            goto L_80021D24;
    }
    // 0x80021D08: lui         $v0, 0x382
    ctx->r2 = S32(0X382 << 16);
    // 0x80021D0C: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80021D10: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80021D14: jal         0x80007D74
    // 0x80021D18: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    func_80007D74(rdram, ctx);
        goto after_6;
    // 0x80021D18: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    after_6:
    // 0x80021D1C: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x80021D20: lui         $v0, 0x382
    ctx->r2 = S32(0X382 << 16);
L_80021D24:
    // 0x80021D24: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80021D28: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x80021D2C: lhu         $v1, 0x8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X8);
    // 0x80021D30: lhu         $v0, 0xA($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XA);
    // 0x80021D34: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80021D38: sll         $v1, $v1, 9
    ctx->r3 = S32(ctx->r3 << 9);
    // 0x80021D3C: srl         $v1, $v1, 16
    ctx->r3 = S32(U32(ctx->r3) >> 16);
    // 0x80021D40: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80021D44: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80021D48: sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2 << 9);
    // 0x80021D4C: srl         $v0, $v0, 16
    ctx->r2 = S32(U32(ctx->r2) >> 16);
    // 0x80021D50: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80021D54: sw          $v1, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r3;
    // 0x80021D58: lhu         $v1, 0x8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X8);
    // 0x80021D5C: lhu         $v0, 0xA($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XA);
    // 0x80021D60: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80021D64: sll         $v1, $v1, 9
    ctx->r3 = S32(ctx->r3 << 9);
    // 0x80021D68: srl         $v1, $v1, 16
    ctx->r3 = S32(U32(ctx->r3) >> 16);
    // 0x80021D6C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80021D70: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80021D74: sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2 << 9);
    // 0x80021D78: srl         $v0, $v0, 16
    ctx->r2 = S32(U32(ctx->r2) >> 16);
    // 0x80021D7C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80021D80: sw          $v1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r3;
    // 0x80021D84: lhu         $v1, 0x8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X8);
    // 0x80021D88: lhu         $v0, 0xA($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XA);
    // 0x80021D8C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80021D90: sll         $v1, $v1, 25
    ctx->r3 = S32(ctx->r3 << 25);
    // 0x80021D94: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80021D98: sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2 << 9);
    // 0x80021D9C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80021DA0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80021DA4: sw          $v1, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r3;
    // 0x80021DA8: lhu         $a0, 0x8($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X8);
    // 0x80021DAC: addiu       $v0, $a3, 0x18
    ctx->r2 = ADD32(ctx->r7, 0X18);
    // 0x80021DB0: lhu         $v1, 0xA($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XA);
    // 0x80021DB4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80021DB8: sll         $a0, $a0, 25
    ctx->r4 = S32(ctx->r4 << 25);
    // 0x80021DBC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80021DC0: sll         $v1, $v1, 9
    ctx->r3 = S32(ctx->r3 << 9);
    // 0x80021DC4: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80021DC8: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x80021DCC: sw          $a0, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r4;
    // 0x80021DD0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80021DD4: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80021DD8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80021DDC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80021DE0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80021DE4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80021DE8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80021DEC: jr          $ra
    // 0x80021DF0: nop

    return;
    // 0x80021DF0: nop

;}
RECOMP_FUNC void func_80021DF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021DF4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80021DF8: lhu         $v0, -0x7110($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7110);
    // 0x80021DFC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80021E00: beq         $v0, $zero, L_80021E28
    if (ctx->r2 == 0) {
        // 0x80021E04: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80021E28;
    }
    // 0x80021E04: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80021E08: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80021E0C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80021E10: lw          $v1, -0x7100($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7100);
L_80021E14:
    // 0x80021E14: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80021E18: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80021E1C: sltu        $v0, $a0, $a1
    ctx->r2 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x80021E20: bne         $v0, $zero, L_80021E14
    if (ctx->r2 != 0) {
        // 0x80021E24: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80021E14;
    }
    // 0x80021E24: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80021E28:
    // 0x80021E28: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80021E2C: lw          $v0, -0x710C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X710C);
    // 0x80021E30: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80021E34: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80021E38: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80021E3C: addiu       $v1, $a2, 0x18
    ctx->r3 = ADD32(ctx->r6, 0X18);
    // 0x80021E40: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80021E44: sw          $a2, -0x7108($at)
    MEM_W(-0X7108, ctx->r1) = ctx->r6;
    // 0x80021E48: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
L_80021E4C:
    // 0x80021E4C: addu        $v0, $a2, $a1
    ctx->r2 = ADD32(ctx->r6, ctx->r5);
    // 0x80021E50: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x80021E54: sw          $v1, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->r3;
    // 0x80021E58: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80021E5C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80021E60: sltiu       $v0, $a0, 0x200
    ctx->r2 = ctx->r4 < 0X200 ? 1 : 0;
    // 0x80021E64: bne         $v0, $zero, L_80021E4C
    if (ctx->r2 != 0) {
        // 0x80021E68: addiu       $v1, $v1, 0x18
        ctx->r3 = ADD32(ctx->r3, 0X18);
            goto L_80021E4C;
    }
    // 0x80021E68: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80021E6C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80021E70: lw          $v1, -0x710C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X710C);
    // 0x80021E74: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80021E78: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80021E7C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021E80: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80021E84: sw          $zero, -0x18($v0)
    MEM_W(-0X18, ctx->r2) = 0;
    // 0x80021E88: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80021E8C: jr          $ra
    // 0x80021E90: nop

    return;
    // 0x80021E90: nop

;}
RECOMP_FUNC void func_80021E94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021E94: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80021E98: lhu         $v0, -0x7110($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7110);
    // 0x80021E9C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80021EA0: beq         $v0, $zero, L_80021EC8
    if (ctx->r2 == 0) {
        // 0x80021EA4: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80021EC8;
    }
    // 0x80021EA4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80021EA8: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80021EAC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80021EB0: lw          $v1, -0x7100($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7100);
L_80021EB4:
    // 0x80021EB4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80021EB8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80021EBC: sltu        $v0, $a0, $a1
    ctx->r2 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x80021EC0: bne         $v0, $zero, L_80021EB4
    if (ctx->r2 != 0) {
        // 0x80021EC4: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80021EB4;
    }
    // 0x80021EC4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80021EC8:
    // 0x80021EC8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80021ECC: lw          $v0, -0x710C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X710C);
    // 0x80021ED0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80021ED4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80021ED8: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80021EDC: addiu       $v1, $a2, 0x18
    ctx->r3 = ADD32(ctx->r6, 0X18);
    // 0x80021EE0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80021EE4: sw          $a2, -0x7108($at)
    MEM_W(-0X7108, ctx->r1) = ctx->r6;
    // 0x80021EE8: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
L_80021EEC:
    // 0x80021EEC: addu        $v0, $a2, $a1
    ctx->r2 = ADD32(ctx->r6, ctx->r5);
    // 0x80021EF0: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x80021EF4: sw          $v1, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->r3;
    // 0x80021EF8: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80021EFC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80021F00: sltiu       $v0, $a0, 0x200
    ctx->r2 = ctx->r4 < 0X200 ? 1 : 0;
    // 0x80021F04: bne         $v0, $zero, L_80021EEC
    if (ctx->r2 != 0) {
        // 0x80021F08: addiu       $v1, $v1, 0x18
        ctx->r3 = ADD32(ctx->r3, 0X18);
            goto L_80021EEC;
    }
    // 0x80021F08: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80021F0C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80021F10: lw          $v1, -0x710C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X710C);
    // 0x80021F14: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80021F18: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80021F1C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021F20: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80021F24: sw          $zero, -0x18($v0)
    MEM_W(-0X18, ctx->r2) = 0;
    // 0x80021F28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80021F2C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80021F30: jr          $ra
    // 0x80021F34: nop

    return;
    // 0x80021F34: nop

;}
RECOMP_FUNC void func_80021F38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021F38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80021F3C: addiu       $a0, $zero, 0x3000
    ctx->r4 = ADD32(0, 0X3000);
    // 0x80021F40: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80021F44: jal         0x80001ACC
    // 0x80021F48: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x80021F48: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_0:
    // 0x80021F4C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80021F50: sw          $v0, -0x710C($at)
    MEM_W(-0X710C, ctx->r1) = ctx->r2;
    // 0x80021F54: beq         $v0, $zero, L_80021F68
    if (ctx->r2 == 0) {
        // 0x80021F58: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80021F68;
    }
    // 0x80021F58: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80021F5C: jal         0x80021E94
    // 0x80021F60: nop

    func_80021E94(rdram, ctx);
        goto after_1;
    // 0x80021F60: nop

    after_1:
    // 0x80021F64: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_80021F68:
    // 0x80021F68: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80021F6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80021F70: jr          $ra
    // 0x80021F74: nop

    return;
    // 0x80021F74: nop

;}
RECOMP_FUNC void func_80021F78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021F78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80021F7C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80021F80: lw          $v0, -0x7100($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7100);
    // 0x80021F84: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80021F88: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80021F8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80021F90: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80021F94: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80021F98: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80021F9C: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80021FA0: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x80021FA4: beq         $s0, $zero, L_8002202C
    if (ctx->r16 == 0) {
        // 0x80021FA8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002202C;
    }
    // 0x80021FA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80021FAC: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
L_80021FB0:
    // 0x80021FB0: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x80021FB4: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80021FB8: jal         0x800079A4
    // 0x80021FBC: nop

    func_800079A4(rdram, ctx);
        goto after_0;
    // 0x80021FBC: nop

    after_0:
    // 0x80021FC0: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x80021FC4: beq         $v1, $zero, L_80021FD8
    if (ctx->r3 == 0) {
        // 0x80021FC8: nop
    
            goto L_80021FD8;
    }
    // 0x80021FC8: nop

    // 0x80021FCC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80021FD0: j           L_80021FEC
    // 0x80021FD4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_80021FEC;
    // 0x80021FD4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80021FD8:
    // 0x80021FD8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80021FDC: lw          $v0, -0x7100($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7100);
    // 0x80021FE0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80021FE4: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x80021FE8: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
L_80021FEC:
    // 0x80021FEC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80021FF0: beq         $v1, $zero, L_80022000
    if (ctx->r3 == 0) {
        // 0x80021FF4: nop
    
            goto L_80022000;
    }
    // 0x80021FF4: nop

    // 0x80021FF8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80021FFC: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80022000:
    // 0x80022000: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80022004: lw          $v0, -0x7108($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7108);
    // 0x80022008: beq         $v0, $zero, L_80022014
    if (ctx->r2 == 0) {
        // 0x8002200C: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_80022014;
    }
    // 0x8002200C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80022010: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
L_80022014:
    // 0x80022014: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80022018: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8002201C: sw          $s0, -0x7108($at)
    MEM_W(-0X7108, ctx->r1) = ctx->r16;
    // 0x80022020: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
    // 0x80022024: bne         $s0, $zero, L_80021FB0
    if (ctx->r16 != 0) {
        // 0x80022028: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80021FB0;
    }
    // 0x80022028: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002202C:
    // 0x8002202C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80022030: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80022034: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80022038: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002203C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80022040: jr          $ra
    // 0x80022044: nop

    return;
    // 0x80022044: nop

;}
RECOMP_FUNC void func_80022048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022048: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8002204C: lhu         $v0, -0x7110($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7110);
    // 0x80022050: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80022054: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80022058: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8002205C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80022060: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80022064: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80022068: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002206C: beq         $v0, $zero, L_80022140
    if (ctx->r2 == 0) {
        // 0x80022070: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80022140;
    }
    // 0x80022070: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80022074: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_80022078:
    // 0x80022078: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8002207C: lw          $v0, -0x7100($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7100);
    // 0x80022080: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x80022084: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x80022088: beq         $s0, $zero, L_80022128
    if (ctx->r16 == 0) {
        // 0x8002208C: nop
    
            goto L_80022128;
    }
    // 0x8002208C: nop

    // 0x80022090: addu        $s4, $s1, $zero
    ctx->r20 = ADD32(ctx->r17, 0);
L_80022094:
    // 0x80022094: lhu         $v1, 0x8($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X8);
    // 0x80022098: lw          $s3, 0x0($s0)
    ctx->r19 = MEM_W(ctx->r16, 0X0);
    // 0x8002209C: sltiu       $v0, $v1, 0x708
    ctx->r2 = ctx->r3 < 0X708 ? 1 : 0;
    // 0x800220A0: beq         $v0, $zero, L_800220B0
    if (ctx->r2 == 0) {
        // 0x800220A4: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_800220B0;
    }
    // 0x800220A4: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800220A8: j           L_8002211C
    // 0x800220AC: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
        goto L_8002211C;
    // 0x800220AC: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
L_800220B0:
    // 0x800220B0: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x800220B4: jal         0x800079A4
    // 0x800220B8: nop

    func_800079A4(rdram, ctx);
        goto after_0;
    // 0x800220B8: nop

    after_0:
    // 0x800220BC: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x800220C0: beq         $v1, $zero, L_800220D4
    if (ctx->r3 == 0) {
        // 0x800220C4: nop
    
            goto L_800220D4;
    }
    // 0x800220C4: nop

    // 0x800220C8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800220CC: j           L_800220E8
    // 0x800220D0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_800220E8;
    // 0x800220D0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800220D4:
    // 0x800220D4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800220D8: lw          $v0, -0x7100($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7100);
    // 0x800220DC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800220E0: addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // 0x800220E4: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
L_800220E8:
    // 0x800220E8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800220EC: beq         $v1, $zero, L_800220FC
    if (ctx->r3 == 0) {
        // 0x800220F0: nop
    
            goto L_800220FC;
    }
    // 0x800220F0: nop

    // 0x800220F4: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800220F8: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800220FC:
    // 0x800220FC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80022100: lw          $v0, -0x7108($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7108);
    // 0x80022104: beq         $v0, $zero, L_80022110
    if (ctx->r2 == 0) {
        // 0x80022108: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_80022110;
    }
    // 0x80022108: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8002210C: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
L_80022110:
    // 0x80022110: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80022114: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80022118: sw          $s0, -0x7108($at)
    MEM_W(-0X7108, ctx->r1) = ctx->r16;
L_8002211C:
    // 0x8002211C: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
    // 0x80022120: bne         $s0, $zero, L_80022094
    if (ctx->r16 != 0) {
        // 0x80022124: nop
    
            goto L_80022094;
    }
    // 0x80022124: nop

L_80022128:
    // 0x80022128: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8002212C: lhu         $v0, -0x7110($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7110);
    // 0x80022130: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80022134: sltu        $v0, $s2, $v0
    ctx->r2 = ctx->r18 < ctx->r2 ? 1 : 0;
    // 0x80022138: bne         $v0, $zero, L_80022078
    if (ctx->r2 != 0) {
        // 0x8002213C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80022078;
    }
    // 0x8002213C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80022140:
    // 0x80022140: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80022144: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80022148: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8002214C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80022150: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80022154: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80022158: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8002215C: jr          $ra
    // 0x80022160: nop

    return;
    // 0x80022160: nop

;}
RECOMP_FUNC void func_80022164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022164: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80022168: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002216C: lbu         $v0, -0x5767($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5767);
    // 0x80022170: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80022174: lw          $a0, 0x63FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63FC);
    // 0x80022178: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8002217C: addiu       $v1, $v1, 0x63C8
    ctx->r3 = ADD32(ctx->r3, 0X63C8);
    // 0x80022180: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80022184: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80022188: bne         $a0, $v0, L_80022214
    if (ctx->r4 != ctx->r2) {
        // 0x8002218C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80022214;
    }
    // 0x8002218C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80022190: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80022194: lw          $v1, -0x7100($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7100);
    // 0x80022198: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x8002219C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800221A0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800221A4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800221A8: beq         $v1, $zero, L_80022214
    if (ctx->r3 == 0) {
        // 0x800221AC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80022214;
    }
    // 0x800221AC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800221B0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800221B4: lbu         $v0, -0x56F8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X56F8);
    // 0x800221B8: andi        $a1, $a1, 0x7
    ctx->r5 = ctx->r5 & 0X7;
    // 0x800221BC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800221C0: andi        $a2, $v0, 0x80
    ctx->r6 = ctx->r2 & 0X80;
L_800221C4:
    // 0x800221C4: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x800221C8: bne         $v0, $a1, L_80022208
    if (ctx->r2 != ctx->r5) {
        // 0x800221CC: nop
    
            goto L_80022208;
    }
    // 0x800221CC: nop

    // 0x800221D0: lbu         $a0, 0xC($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XC);
    // 0x800221D4: andi        $v0, $a0, 0x7F
    ctx->r2 = ctx->r4 & 0X7F;
    // 0x800221D8: bne         $v0, $a3, L_800221E8
    if (ctx->r2 != ctx->r7) {
        // 0x800221DC: nop
    
            goto L_800221E8;
    }
    // 0x800221DC: nop

    // 0x800221E0: bnel        $a2, $zero, L_80022200
    if (ctx->r6 != 0) {
        // 0x800221E4: sh          $zero, 0x8($v1)
        MEM_H(0X8, ctx->r3) = 0;
            goto L_80022200;
    }
    goto skip_0;
    // 0x800221E4: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    skip_0:
L_800221E8:
    // 0x800221E8: lbu         $v0, 0xE($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XE);
    // 0x800221EC: bne         $a0, $v0, L_80022208
    if (ctx->r4 != ctx->r2) {
        // 0x800221F0: nop
    
            goto L_80022208;
    }
    // 0x800221F0: nop

    // 0x800221F4: bne         $a2, $zero, L_80022208
    if (ctx->r6 != 0) {
        // 0x800221F8: nop
    
            goto L_80022208;
    }
    // 0x800221F8: nop

    // 0x800221FC: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
L_80022200:
    // 0x80022200: j           L_80022214
    // 0x80022204: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80022214;
    // 0x80022204: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80022208:
    // 0x80022208: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8002220C: bne         $v1, $zero, L_800221C4
    if (ctx->r3 != 0) {
        // 0x80022210: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800221C4;
    }
    // 0x80022210: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80022214:
    // 0x80022214: jr          $ra
    // 0x80022218: nop

    return;
    // 0x80022218: nop

;}
RECOMP_FUNC void func_8002221C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002221C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80022220: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80022224: lhu         $v0, -0x7110($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7110);
    // 0x80022228: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8002222C: beq         $v0, $zero, L_8002228C
    if (ctx->r2 == 0) {
        // 0x80022230: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8002228C;
    }
    // 0x80022230: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80022234: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80022238: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8002223C: lw          $a2, -0x7100($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7100);
L_80022240:
    // 0x80022240: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80022244: beql        $v1, $zero, L_80022280
    if (ctx->r3 == 0) {
        // 0x80022248: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80022280;
    }
    goto skip_0;
    // 0x80022248: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_0:
L_8002224C:
    // 0x8002224C: lhu         $a0, 0x8($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X8);
    // 0x80022250: beq         $a0, $zero, L_80022270
    if (ctx->r4 == 0) {
        // 0x80022254: nop
    
            goto L_80022270;
    }
    // 0x80022254: nop

    // 0x80022258: beql        $a1, $zero, L_80022270
    if (ctx->r5 == 0) {
        // 0x8002225C: addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
            goto L_80022270;
    }
    goto skip_1;
    // 0x8002225C: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    skip_1:
    // 0x80022260: lhu         $v0, 0x8($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X8);
    // 0x80022264: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80022268: beql        $v0, $zero, L_80022270
    if (ctx->r2 == 0) {
        // 0x8002226C: addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
            goto L_80022270;
    }
    goto skip_2;
    // 0x8002226C: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    skip_2:
L_80022270:
    // 0x80022270: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80022274: bne         $v1, $zero, L_8002224C
    if (ctx->r3 != 0) {
        // 0x80022278: nop
    
            goto L_8002224C;
    }
    // 0x80022278: nop

    // 0x8002227C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_80022280:
    // 0x80022280: sltu        $v0, $a3, $t0
    ctx->r2 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x80022284: bne         $v0, $zero, L_80022240
    if (ctx->r2 != 0) {
        // 0x80022288: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80022240;
    }
    // 0x80022288: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_8002228C:
    // 0x8002228C: beq         $a1, $zero, L_80022300
    if (ctx->r5 == 0) {
        // 0x80022290: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80022300;
    }
    // 0x80022290: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80022294: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x80022298: beq         $v1, $zero, L_800222AC
    if (ctx->r3 == 0) {
        // 0x8002229C: nop
    
            goto L_800222AC;
    }
    // 0x8002229C: nop

    // 0x800222A0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800222A4: j           L_800222C8
    // 0x800222A8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_800222C8;
    // 0x800222A8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800222AC:
    // 0x800222AC: lhu         $v0, 0xA($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XA);
    // 0x800222B0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800222B4: lw          $v1, -0x7100($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7100);
    // 0x800222B8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800222BC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800222C0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800222C4: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
L_800222C8:
    // 0x800222C8: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800222CC: beq         $v1, $zero, L_800222DC
    if (ctx->r3 == 0) {
        // 0x800222D0: nop
    
            goto L_800222DC;
    }
    // 0x800222D0: nop

    // 0x800222D4: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x800222D8: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800222DC:
    // 0x800222DC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800222E0: lw          $v0, -0x7108($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7108);
    // 0x800222E4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800222E8: beq         $v0, $zero, L_800222F4
    if (ctx->r2 == 0) {
        // 0x800222EC: sw          $v0, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r2;
            goto L_800222F4;
    }
    // 0x800222EC: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800222F0: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
L_800222F4:
    // 0x800222F4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x800222F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800222FC: sw          $a1, -0x7108($at)
    MEM_W(-0X7108, ctx->r1) = ctx->r5;
L_80022300:
    // 0x80022300: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80022304: jr          $ra
    // 0x80022308: nop

    return;
    // 0x80022308: nop

;}
RECOMP_FUNC void func_8002230C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002230C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80022310: lw          $a1, -0x7108($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7108);
    // 0x80022314: beq         $a1, $zero, L_80022364
    if (ctx->r5 == 0) {
        // 0x80022318: nop
    
            goto L_80022364;
    }
    // 0x80022318: nop

    // 0x8002231C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80022320: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80022324: sw          $v0, -0x7108($at)
    MEM_W(-0X7108, ctx->r1) = ctx->r2;
    // 0x80022328: bnel        $v0, $zero, L_80022330
    if (ctx->r2 != 0) {
        // 0x8002232C: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_80022330;
    }
    goto skip_0;
    // 0x8002232C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_0:
L_80022330:
    // 0x80022330: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80022334: lw          $v0, -0x7100($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7100);
    // 0x80022338: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x8002233C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80022340: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80022344: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80022348: beq         $v0, $zero, L_80022354
    if (ctx->r2 == 0) {
        // 0x8002234C: sw          $v0, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r2;
            goto L_80022354;
    }
    // 0x8002234C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80022350: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
L_80022354:
    // 0x80022354: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80022358: lw          $v0, -0x7100($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7100);
    // 0x8002235C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80022360: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_80022364:
    // 0x80022364: jr          $ra
    // 0x80022368: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    return;
    // 0x80022368: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
;}
RECOMP_FUNC void func_8002236C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002236C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80022370: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80022374: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80022378: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002237C: lbu         $v0, -0x5767($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5767);
    // 0x80022380: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80022384: lw          $a0, 0x63FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63FC);
    // 0x80022388: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8002238C: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x80022390: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80022394: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x80022398: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8002239C: addiu       $v1, $v1, 0x63C8
    ctx->r3 = ADD32(ctx->r3, 0X63C8);
    // 0x800223A0: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x800223A4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800223A8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800223AC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800223B0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800223B4: bne         $a0, $v0, L_800225BC
    if (ctx->r4 != ctx->r2) {
        // 0x800223B8: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800225BC;
    }
    // 0x800223B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800223BC: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800223C0: lw          $a3, -0x7108($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7108);
    // 0x800223C4: beq         $a3, $zero, L_80022418
    if (ctx->r7 == 0) {
        // 0x800223C8: addu        $s0, $a3, $zero
        ctx->r16 = ADD32(ctx->r7, 0);
            goto L_80022418;
    }
    // 0x800223C8: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // 0x800223CC: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800223D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800223D4: sw          $v0, -0x7108($at)
    MEM_W(-0X7108, ctx->r1) = ctx->r2;
    // 0x800223D8: bnel        $v0, $zero, L_800223E0
    if (ctx->r2 != 0) {
        // 0x800223DC: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_800223E0;
    }
    goto skip_0;
    // 0x800223DC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_0:
L_800223E0:
    // 0x800223E0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800223E4: lw          $v0, -0x7100($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7100);
    // 0x800223E8: andi        $v1, $s2, 0xFFFF
    ctx->r3 = ctx->r18 & 0XFFFF;
    // 0x800223EC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800223F0: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800223F4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800223F8: beq         $v0, $zero, L_80022404
    if (ctx->r2 == 0) {
        // 0x800223FC: sw          $v0, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r2;
            goto L_80022404;
    }
    // 0x800223FC: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80022400: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
L_80022404:
    // 0x80022404: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80022408: lw          $v0, -0x7100($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7100);
    // 0x8002240C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80022410: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x80022414: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
L_80022418:
    // 0x80022418: bne         $s0, $zero, L_8002249C
    if (ctx->r16 != 0) {
        // 0x8002241C: nop
    
            goto L_8002249C;
    }
    // 0x8002241C: nop

    // 0x80022420: jal         0x8002221C
    // 0x80022424: nop

    func_8002221C(rdram, ctx);
        goto after_0;
    // 0x80022424: nop

    after_0:
    // 0x80022428: beq         $v0, $zero, L_80022494
    if (ctx->r2 == 0) {
        // 0x8002242C: nop
    
            goto L_80022494;
    }
    // 0x8002242C: nop

    // 0x80022430: jal         0x800079A4
    // 0x80022434: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_800079A4(rdram, ctx);
        goto after_1;
    // 0x80022434: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_1:
    // 0x80022438: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8002243C: lw          $a3, -0x7108($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7108);
    // 0x80022440: beql        $a3, $zero, L_80022494
    if (ctx->r7 == 0) {
        // 0x80022444: addu        $s0, $a3, $zero
        ctx->r16 = ADD32(ctx->r7, 0);
            goto L_80022494;
    }
    goto skip_1;
    // 0x80022444: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    skip_1:
    // 0x80022448: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8002244C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80022450: sw          $v0, -0x7108($at)
    MEM_W(-0X7108, ctx->r1) = ctx->r2;
    // 0x80022454: bnel        $v0, $zero, L_8002245C
    if (ctx->r2 != 0) {
        // 0x80022458: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_8002245C;
    }
    goto skip_2;
    // 0x80022458: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_2:
L_8002245C:
    // 0x8002245C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80022460: lw          $v0, -0x7100($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7100);
    // 0x80022464: andi        $v1, $s2, 0xFFFF
    ctx->r3 = ctx->r18 & 0XFFFF;
    // 0x80022468: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8002246C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80022470: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80022474: beq         $v0, $zero, L_80022480
    if (ctx->r2 == 0) {
        // 0x80022478: sw          $v0, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r2;
            goto L_80022480;
    }
    // 0x80022478: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8002247C: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
L_80022480:
    // 0x80022480: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80022484: lw          $v0, -0x7100($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7100);
    // 0x80022488: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8002248C: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x80022490: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
L_80022494:
    // 0x80022494: beq         $s0, $zero, L_800225C0
    if (ctx->r16 == 0) {
        // 0x80022498: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_800225C0;
    }
    // 0x80022498: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_8002249C:
    // 0x8002249C: lui         $s3, 0x8011
    ctx->r19 = S32(0X8011 << 16);
    // 0x800224A0: lw          $s3, 0x63D4($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X63D4);
    // 0x800224A4: addiu       $v0, $s0, 0x14
    ctx->r2 = ADD32(ctx->r16, 0X14);
    // 0x800224A8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800224AC: sw          $v0, 0x63FC($at)
    MEM_W(0X63FC, ctx->r1) = ctx->r2;
    // 0x800224B0: addiu       $v0, $sp, 0x10
    ctx->r2 = ADD32(ctx->r29, 0X10);
    // 0x800224B4: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x800224B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800224BC: sw          $v0, -0x5824($at)
    MEM_W(-0X5824, ctx->r1) = ctx->r2;
    // 0x800224C0: jal         0x80007D74
    // 0x800224C4: nop

    func_80007D74(rdram, ctx);
        goto after_2;
    // 0x800224C4: nop

    after_2:
    // 0x800224C8: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // 0x800224CC: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800224D0: andi        $a1, $s2, 0xFFFF
    ctx->r5 = ctx->r18 & 0XFFFF;
    // 0x800224D4: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    // 0x800224D8: jal         0x80021A1C
    // 0x800224DC: addiu       $a3, $s0, 0xE
    ctx->r7 = ADD32(ctx->r16, 0XE);
    func_80021A1C(rdram, ctx);
        goto after_3;
    // 0x800224DC: addiu       $a3, $s0, 0xE
    ctx->r7 = ADD32(ctx->r16, 0XE);
    after_3:
    // 0x800224E0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800224E4: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x800224E8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800224EC: sltu        $v1, $a0, $v1
    ctx->r3 = ctx->r4 < ctx->r3 ? 1 : 0;
    // 0x800224F0: bne         $v1, $zero, L_80022510
    if (ctx->r3 != 0) {
        // 0x800224F4: lui         $v0, 0xB800
        ctx->r2 = S32(0XB800 << 16);
            goto L_80022510;
    }
    // 0x800224F4: lui         $v0, 0xB800
    ctx->r2 = S32(0XB800 << 16);
    // 0x800224F8: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x800224FC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80022500: jal         0x80007D74
    // 0x80022504: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    func_80007D74(rdram, ctx);
        goto after_4;
    // 0x80022504: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    after_4:
    // 0x80022508: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8002250C: lui         $v0, 0xB800
    ctx->r2 = S32(0XB800 << 16);
L_80022510:
    // 0x80022510: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80022514: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80022518: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002251C: lbu         $v1, -0x5767($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X5767);
    // 0x80022520: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80022524: lbu         $a0, -0x56F8($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X56F8);
    // 0x80022528: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8002252C: addiu       $v0, $v0, 0x63C8
    ctx->r2 = ADD32(ctx->r2, 0X63C8);
    // 0x80022530: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80022534: sw          $s3, 0x63D4($at)
    MEM_W(0X63D4, ctx->r1) = ctx->r19;
    // 0x80022538: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8002253C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80022540: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80022544: sw          $v0, 0x63FC($at)
    MEM_W(0X63FC, ctx->r1) = ctx->r2;
    // 0x80022548: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002254C: addiu       $v0, $v0, -0x5820
    ctx->r2 = ADD32(ctx->r2, -0X5820);
    // 0x80022550: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80022554: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80022558: sw          $v1, -0x5824($at)
    MEM_W(-0X5824, ctx->r1) = ctx->r3;
    // 0x8002255C: sb          $a0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r4;
    // 0x80022560: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80022564: lbu         $v0, 0x43A8($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X43A8);
    // 0x80022568: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    // 0x8002256C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80022570: lw          $v1, 0x63D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D4);
    // 0x80022574: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x80022578: sh          $s2, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r18;
    // 0x8002257C: andi        $v0, $s4, 0x7
    ctx->r2 = ctx->r20 & 0X7;
    // 0x80022580: sltu        $v1, $s1, $v1
    ctx->r3 = ctx->r17 < ctx->r3 ? 1 : 0;
    // 0x80022584: bne         $v1, $zero, L_800225A0
    if (ctx->r3 != 0) {
        // 0x80022588: sw          $v0, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->r2;
            goto L_800225A0;
    }
    // 0x80022588: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x8002258C: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x80022590: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80022594: jal         0x80007D74
    // 0x80022598: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
    func_80007D74(rdram, ctx);
        goto after_5;
    // 0x80022598: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
    after_5:
    // 0x8002259C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_800225A0:
    // 0x800225A0: addiu       $v0, $s1, 0x8
    ctx->r2 = ADD32(ctx->r17, 0X8);
    // 0x800225A4: addu        $v1, $s1, $zero
    ctx->r3 = ADD32(ctx->r17, 0);
    // 0x800225A8: lui         $a0, 0x600
    ctx->r4 = S32(0X600 << 16);
    // 0x800225AC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x800225B0: addiu       $a0, $s5, -0x8
    ctx->r4 = ADD32(ctx->r21, -0X8);
    // 0x800225B4: j           L_800225D0
    // 0x800225B8: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
        goto L_800225D0;
    // 0x800225B8: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
L_800225BC:
    // 0x800225BC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_800225C0:
    // 0x800225C0: andi        $a1, $s2, 0xFFFF
    ctx->r5 = ctx->r18 & 0XFFFF;
    // 0x800225C4: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    // 0x800225C8: jal         0x80021A1C
    // 0x800225CC: addiu       $a3, $sp, 0x14
    ctx->r7 = ADD32(ctx->r29, 0X14);
    func_80021A1C(rdram, ctx);
        goto after_6;
    // 0x800225CC: addiu       $a3, $sp, 0x14
    ctx->r7 = ADD32(ctx->r29, 0X14);
    after_6:
L_800225D0:
    // 0x800225D0: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x800225D4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800225D8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800225DC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800225E0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800225E4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800225E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800225EC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800225F0: jr          $ra
    // 0x800225F4: nop

    return;
    // 0x800225F4: nop

;}
RECOMP_FUNC void func_800225F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800225F8: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x800225FC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80022600: lbu         $v0, -0x5767($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5767);
    // 0x80022604: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80022608: lw          $a0, 0x63FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63FC);
    // 0x8002260C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80022610: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80022614: addiu       $v1, $v1, 0x63C8
    ctx->r3 = ADD32(ctx->r3, 0X63C8);
    // 0x80022618: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002261C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80022620: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80022624: bne         $a0, $v0, L_800226B0
    if (ctx->r4 != ctx->r2) {
        // 0x80022628: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_800226B0;
    }
    // 0x80022628: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002262C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80022630: lw          $v1, -0x7100($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7100);
    // 0x80022634: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x80022638: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002263C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80022640: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80022644: beq         $v1, $zero, L_800226B4
    if (ctx->r3 == 0) {
        // 0x80022648: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_800226B4;
    }
    // 0x80022648: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8002264C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80022650: lbu         $v0, -0x56F8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X56F8);
    // 0x80022654: andi        $t1, $a2, 0x7
    ctx->r9 = ctx->r6 & 0X7;
    // 0x80022658: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8002265C: andi        $a3, $v0, 0x80
    ctx->r7 = ctx->r2 & 0X80;
L_80022660:
    // 0x80022660: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x80022664: bne         $v0, $t1, L_800226A4
    if (ctx->r2 != ctx->r9) {
        // 0x80022668: nop
    
            goto L_800226A4;
    }
    // 0x80022668: nop

    // 0x8002266C: lbu         $a0, 0xC($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XC);
    // 0x80022670: andi        $v0, $a0, 0x7F
    ctx->r2 = ctx->r4 & 0X7F;
    // 0x80022674: bne         $v0, $t2, L_80022684
    if (ctx->r2 != ctx->r10) {
        // 0x80022678: nop
    
            goto L_80022684;
    }
    // 0x80022678: nop

    // 0x8002267C: bnel        $a3, $zero, L_8002269C
    if (ctx->r7 != 0) {
        // 0x80022680: sh          $zero, 0x8($v1)
        MEM_H(0X8, ctx->r3) = 0;
            goto L_8002269C;
    }
    goto skip_0;
    // 0x80022680: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    skip_0:
L_80022684:
    // 0x80022684: lbu         $v0, 0xE($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XE);
    // 0x80022688: bne         $a0, $v0, L_800226A4
    if (ctx->r4 != ctx->r2) {
        // 0x8002268C: nop
    
            goto L_800226A4;
    }
    // 0x8002268C: nop

    // 0x80022690: bne         $a3, $zero, L_800226A4
    if (ctx->r7 != 0) {
        // 0x80022694: nop
    
            goto L_800226A4;
    }
    // 0x80022694: nop

    // 0x80022698: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
L_8002269C:
    // 0x8002269C: j           L_800226B4
    // 0x800226A0: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
        goto L_800226B4;
    // 0x800226A0: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
L_800226A4:
    // 0x800226A4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800226A8: bne         $v1, $zero, L_80022660
    if (ctx->r3 != 0) {
        // 0x800226AC: nop
    
            goto L_80022660;
    }
    // 0x800226AC: nop

L_800226B0:
    // 0x800226B0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_800226B4:
    // 0x800226B4: bne         $s0, $zero, L_800226CC
    if (ctx->r16 != 0) {
        // 0x800226B8: addu        $a0, $t0, $zero
        ctx->r4 = ADD32(ctx->r8, 0);
            goto L_800226CC;
    }
    // 0x800226B8: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x800226BC: jal         0x8002236C
    // 0x800226C0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    func_8002236C(rdram, ctx);
        goto after_0;
    // 0x800226C0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_0:
    // 0x800226C4: j           L_80022728
    // 0x800226C8: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
        goto L_80022728;
    // 0x800226C8: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_800226CC:
    // 0x800226CC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800226D0: lw          $v0, 0x63D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D4);
    // 0x800226D4: sltu        $v0, $t0, $v0
    ctx->r2 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x800226D8: bne         $v0, $zero, L_800226F8
    if (ctx->r2 != 0) {
        // 0x800226DC: addu        $v1, $t0, $zero
        ctx->r3 = ADD32(ctx->r8, 0);
            goto L_800226F8;
    }
    // 0x800226DC: addu        $v1, $t0, $zero
    ctx->r3 = ADD32(ctx->r8, 0);
    // 0x800226E0: lui         $v0, 0xB500
    ctx->r2 = S32(0XB500 << 16);
    // 0x800226E4: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x800226E8: jal         0x80007D74
    // 0x800226EC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    func_80007D74(rdram, ctx);
        goto after_1;
    // 0x800226EC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_1:
    // 0x800226F0: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x800226F4: addu        $v1, $t0, $zero
    ctx->r3 = ADD32(ctx->r8, 0);
L_800226F8:
    // 0x800226F8: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x800226FC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80022700: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80022704: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // 0x80022708: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8002270C: lbu         $v0, 0xC($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XC);
    // 0x80022710: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80022714: sb          $v0, -0x56F8($at)
    MEM_B(-0X56F8, ctx->r1) = ctx->r2;
    // 0x80022718: lbu         $v0, 0xD($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XD);
    // 0x8002271C: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80022720: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80022724: sb          $v0, 0x43A8($at)
    MEM_B(0X43A8, ctx->r1) = ctx->r2;
L_80022728:
    // 0x80022728: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    // 0x8002272C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80022730: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80022734: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80022738: jr          $ra
    // 0x8002273C: nop

    return;
    // 0x8002273C: nop

;}
RECOMP_FUNC void func_80022740(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022740: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80022744: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80022748: lw          $v1, -0x70F8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X70F8);
    // 0x8002274C: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x80022750: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80022754: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80022758: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8002275C: lhu         $v0, 0x8($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X8);
    // 0x80022760: jr          $ra
    // 0x80022764: nop

    return;
    // 0x80022764: nop

;}
RECOMP_FUNC void func_80022768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022768: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8002276C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80022770: lw          $v1, -0x70F8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X70F8);
    // 0x80022774: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x80022778: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8002277C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80022780: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80022784: lhu         $v0, 0xA($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0XA);
    // 0x80022788: jr          $ra
    // 0x8002278C: nop

    return;
    // 0x8002278C: nop

;}
RECOMP_FUNC void func_80022790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022790: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80022794: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x80022798: beq         $v0, $zero, L_80022830
    if (ctx->r2 == 0) {
        // 0x8002279C: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80022830;
    }
    // 0x8002279C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800227A0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800227A4: lw          $v1, -0x5BBC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5BBC);
    // 0x800227A8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800227AC: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x800227B0: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800227B4: beq         $v0, $zero, L_80022830
    if (ctx->r2 == 0) {
        // 0x800227B8: andi        $v0, $v0, 0x1
        ctx->r2 = ctx->r2 & 0X1;
            goto L_80022830;
    }
    // 0x800227B8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800227BC: beq         $v0, $zero, L_80022828
    if (ctx->r2 == 0) {
        // 0x800227C0: sh          $zero, 0x0($a0)
        MEM_H(0X0, ctx->r4) = 0;
            goto L_80022828;
    }
    // 0x800227C0: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x800227C4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800227C8: lhu         $v0, -0x574C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X574C);
    // 0x800227CC: lhu         $a0, 0x2($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X2);
    // 0x800227D0: beq         $v0, $zero, L_80022818
    if (ctx->r2 == 0) {
        // 0x800227D4: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80022818;
    }
    // 0x800227D4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800227D8: addu        $t0, $v1, $zero
    ctx->r8 = ADD32(ctx->r3, 0);
    // 0x800227DC: andi        $a3, $a0, 0xFFFF
    ctx->r7 = ctx->r4 & 0XFFFF;
    // 0x800227E0: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x800227E4: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
L_800227E8:
    // 0x800227E8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800227EC: addu        $v1, $v0, $t0
    ctx->r3 = ADD32(ctx->r2, ctx->r8);
    // 0x800227F0: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800227F4: beq         $v0, $zero, L_80022808
    if (ctx->r2 == 0) {
        // 0x800227F8: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80022808;
    }
    // 0x800227F8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800227FC: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x80022800: beq         $v0, $a3, L_80022834
    if (ctx->r2 == ctx->r7) {
        // 0x80022804: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80022834;
    }
    // 0x80022804: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80022808:
    // 0x80022808: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x8002280C: sltu        $v0, $v0, $a2
    ctx->r2 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x80022810: bne         $v0, $zero, L_800227E8
    if (ctx->r2 != 0) {
        // 0x80022814: andi        $v0, $a1, 0xFFFF
        ctx->r2 = ctx->r5 & 0XFFFF;
            goto L_800227E8;
    }
    // 0x80022814: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
L_80022818:
    // 0x80022818: jal         0x8001E7D0
    // 0x8002281C: nop

    func_8001E7D0(rdram, ctx);
        goto after_0;
    // 0x8002281C: nop

    after_0:
    // 0x80022820: j           L_80022834
    // 0x80022824: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80022834;
    // 0x80022824: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80022828:
    // 0x80022828: j           L_80022834
    // 0x8002282C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80022834;
    // 0x8002282C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80022830:
    // 0x80022830: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80022834:
    // 0x80022834: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80022838: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002283C: jr          $ra
    // 0x80022840: nop

    return;
    // 0x80022840: nop

;}
RECOMP_FUNC void func_80022844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022844: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80022848: lhu         $v0, -0x7110($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7110);
    // 0x8002284C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80022850: lhu         $v1, -0x70FC($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X70FC);
    // 0x80022854: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80022858: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8002285C: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80022860: sll         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2 << 3);
    // 0x80022864: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80022868: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8002286C: sh          $v0, -0x7110($at)
    MEM_H(-0X7110, ctx->r1) = ctx->r2;
    // 0x80022870: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80022874: sh          $v1, -0x70FC($at)
    MEM_H(-0X70FC, ctx->r1) = ctx->r3;
    // 0x80022878: jal         0x80001ACC
    // 0x8002287C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x8002287C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_0:
    // 0x80022880: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80022884: lhu         $a0, -0x70FC($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X70FC);
    // 0x80022888: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8002288C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80022890: sw          $v0, -0x70F8($at)
    MEM_W(-0X70F8, ctx->r1) = ctx->r2;
    // 0x80022894: jal         0x80001ACC
    // 0x80022898: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x80022898: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_1:
    // 0x8002289C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800228A0: lhu         $a0, -0x7110($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X7110);
    // 0x800228A4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800228A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800228AC: sw          $v0, -0x7104($at)
    MEM_W(-0X7104, ctx->r1) = ctx->r2;
    // 0x800228B0: jal         0x80001ACC
    // 0x800228B4: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    rs_malloc(rdram, ctx);
        goto after_2;
    // 0x800228B4: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_2:
    // 0x800228B8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800228BC: lhu         $a0, -0x7110($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X7110);
    // 0x800228C0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800228C4: sw          $v0, -0x7100($at)
    MEM_W(-0X7100, ctx->r1) = ctx->r2;
    // 0x800228C8: blez        $a0, L_800228F0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800228CC: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800228F0;
    }
    // 0x800228CC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800228D0: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800228D4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800228D8: lw          $a0, -0x70F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X70F8);
L_800228DC:
    // 0x800228DC: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x800228E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800228E4: slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800228E8: bne         $v0, $zero, L_800228DC
    if (ctx->r2 != 0) {
        // 0x800228EC: addiu       $a0, $a0, 0x24
        ctx->r4 = ADD32(ctx->r4, 0X24);
            goto L_800228DC;
    }
    // 0x800228EC: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
L_800228F0:
    // 0x800228F0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800228F4: lhu         $v0, -0x70FC($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X70FC);
    // 0x800228F8: blez        $v0, L_80022920
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800228FC: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80022920;
    }
    // 0x800228FC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80022900: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80022904: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80022908: lw          $a0, -0x7104($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7104);
L_8002290C:
    // 0x8002290C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80022910: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80022914: slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80022918: bne         $v0, $zero, L_8002290C
    if (ctx->r2 != 0) {
        // 0x8002291C: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8002290C;
    }
    // 0x8002291C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_80022920:
    // 0x80022920: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80022924: lw          $v0, -0x57B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X57B0);
    // 0x80022928: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002292C: lw          $v1, -0x57AC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X57AC);
    // 0x80022930: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80022934: sw          $v0, -0x5828($at)
    MEM_W(-0X5828, ctx->r1) = ctx->r2;
    // 0x80022938: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002293C: sw          $v1, -0x5830($at)
    MEM_W(-0X5830, ctx->r1) = ctx->r3;
    // 0x80022940: jal         0x80021E94
    // 0x80022944: nop

    func_80021E94(rdram, ctx);
        goto after_3;
    // 0x80022944: nop

    after_3:
    // 0x80022948: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8002294C: addiu       $a1, $a1, -0x574C
    ctx->r5 = ADD32(ctx->r5, -0X574C);
    // 0x80022950: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x80022954: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80022958: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002295C: beq         $v0, $zero, L_80022988
    if (ctx->r2 == 0) {
        // 0x80022960: nop
    
            goto L_80022988;
    }
    // 0x80022960: nop

    // 0x80022964: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80022968: lw          $v0, -0x5BBC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5BBC);
    // 0x8002296C: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
L_80022970:
    // 0x80022970: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x80022974: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x80022978: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002297C: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80022980: bne         $v0, $zero, L_80022970
    if (ctx->r2 != 0) {
        // 0x80022984: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80022970;
    }
    // 0x80022984: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_80022988:
    // 0x80022988: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8002298C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80022990: jr          $ra
    // 0x80022994: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80022994: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80022998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022998: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002299C: lw          $v0, -0x5BBC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5BBC);
    // 0x800229A0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800229A4: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800229A8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800229AC: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800229B0: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800229B4: beq         $v0, $zero, L_800229F8
    if (ctx->r2 == 0) {
        // 0x800229B8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800229F8;
    }
    // 0x800229B8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800229BC: lhu         $a0, 0x2($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X2);
    // 0x800229C0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800229C4: lw          $v1, -0x70F8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X70F8);
    // 0x800229C8: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x800229CC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800229D0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800229D4: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // 0x800229D8: lhu         $v1, 0x8($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X8);
    // 0x800229DC: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
    // 0x800229E0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800229E4: lw          $v1, -0x70F8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X70F8);
    // 0x800229E8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800229EC: lhu         $v1, 0xA($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XA);
    // 0x800229F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800229F4: sh          $v1, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r3;
L_800229F8:
    // 0x800229F8: jr          $ra
    // 0x800229FC: nop

    return;
    // 0x800229FC: nop

;}
RECOMP_FUNC void func_80022A00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022A00: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80022A04: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80022A08: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80022A0C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80022A10: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80022A14: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    // 0x80022A18: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80022A1C: lhu         $v1, -0x574C($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X574C);
    // 0x80022A20: lbu         $a1, 0x4B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X4B);
    // 0x80022A24: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x80022A28: xori        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 ^ 0XFFFF;
    // 0x80022A2C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80022A30: xor         $v1, $s1, $v1
    ctx->r3 = ctx->r17 ^ ctx->r3;
    // 0x80022A34: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x80022A38: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80022A3C: beq         $v1, $zero, L_80022B74
    if (ctx->r3 == 0) {
        // 0x80022A40: sw          $ra, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r31;
            goto L_80022B74;
    }
    // 0x80022A40: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80022A44: andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // 0x80022A48: beq         $v0, $zero, L_80022A6C
    if (ctx->r2 == 0) {
        // 0x80022A4C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80022A6C;
    }
    // 0x80022A4C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80022A50: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80022A54: lwc1        $f0, 0x9F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X9F0);
    // 0x80022A58: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x80022A5C: sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
    // 0x80022A60: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x80022A64: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x80022A68: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
L_80022A6C:
    // 0x80022A6C: beq         $a0, $zero, L_80022AF8
    if (ctx->r4 == 0) {
        // 0x80022A70: nop
    
            goto L_80022AF8;
    }
    // 0x80022A70: nop

    // 0x80022A74: lhu         $v0, 0x2E($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2E);
    // 0x80022A78: lhu         $a2, 0x28($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X28);
    // 0x80022A7C: lhu         $a3, 0x2A($a0)
    ctx->r7 = MEM_HU(ctx->r4, 0X2A);
    // 0x80022A80: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80022A84: lbu         $v0, 0x2C($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2C);
    // 0x80022A88: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80022A8C: lbu         $v0, 0x2D($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2D);
    // 0x80022A90: beq         $a1, $zero, L_80022AB4
    if (ctx->r5 == 0) {
        // 0x80022A94: sw          $v0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r2;
            goto L_80022AB4;
    }
    // 0x80022A94: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80022A98: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80022A9C: lw          $v0, -0x5BBC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5BBC);
    // 0x80022AA0: sll         $v1, $s1, 2
    ctx->r3 = S32(ctx->r17 << 2);
    // 0x80022AA4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80022AA8: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x80022AAC: j           L_80022AB8
    // 0x80022AB0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80022AB8;
    // 0x80022AB0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80022AB4:
    // 0x80022AB4: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
L_80022AB8:
    // 0x80022AB8: addiu       $v0, $a0, 0x30
    ctx->r2 = ADD32(ctx->r4, 0X30);
    // 0x80022ABC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80022AC0: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x80022AC4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80022AC8: lw          $a1, 0x20($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X20);
    // 0x80022ACC: jal         0x8001F954
    // 0x80022AD0: nop

    func_8001F954(rdram, ctx);
        goto after_0;
    // 0x80022AD0: nop

    after_0:
    // 0x80022AD4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80022AD8: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x80022ADC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80022AE0: beq         $v1, $v0, L_80022B78
    if (ctx->r3 == ctx->r2) {
        // 0x80022AE4: nop
    
            goto L_80022B78;
    }
    // 0x80022AE4: nop

    // 0x80022AE8: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80022AEC: sh          $a0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r4;
    // 0x80022AF0: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80022AF4: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_80022AF8:
    // 0x80022AF8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80022AFC: lw          $v1, 0x63B4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63B4);
    // 0x80022B00: beq         $v1, $zero, L_80022B2C
    if (ctx->r3 == 0) {
        // 0x80022B04: sll         $v0, $s1, 4
        ctx->r2 = S32(ctx->r17 << 4);
            goto L_80022B2C;
    }
    // 0x80022B04: sll         $v0, $s1, 4
    ctx->r2 = S32(ctx->r17 << 4);
    // 0x80022B08: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80022B0C: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x80022B10: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80022B14: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80022B18: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80022B1C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80022B20: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x80022B24: sw          $a1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r5;
    // 0x80022B28: sw          $a2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r6;
L_80022B2C:
    // 0x80022B2C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80022B30: lw          $v0, 0x43AC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43AC);
    // 0x80022B34: beq         $v0, $zero, L_80022B4C
    if (ctx->r2 == 0) {
        // 0x80022B38: sll         $a0, $s1, 4
        ctx->r4 = S32(ctx->r17 << 4);
            goto L_80022B4C;
    }
    // 0x80022B38: sll         $a0, $s1, 4
    ctx->r4 = S32(ctx->r17 << 4);
    // 0x80022B3C: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // 0x80022B40: addiu       $a1, $s0, 0x14
    ctx->r5 = ADD32(ctx->r16, 0X14);
    // 0x80022B44: jal         0x80007640
    // 0x80022B48: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    rs_strncpy(rdram, ctx);
        goto after_1;
    // 0x80022B48: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_1:
L_80022B4C:
    // 0x80022B4C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80022B50: lw          $v0, -0x5BBC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5BBC);
    // 0x80022B54: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x80022B58: sll         $v1, $s1, 2
    ctx->r3 = S32(ctx->r17 << 2);
    // 0x80022B5C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80022B60: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x80022B64: lhu         $a0, 0x2($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X2);
    // 0x80022B68: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
    // 0x80022B6C: j           L_80022B78
    // 0x80022B70: sh          $a0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r4;
        goto L_80022B78;
    // 0x80022B70: sh          $a0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r4;
L_80022B74:
    // 0x80022B74: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80022B78:
    // 0x80022B78: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80022B7C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80022B80: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80022B84: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80022B88: jr          $ra
    // 0x80022B8C: nop

    return;
    // 0x80022B8C: nop

;}
RECOMP_FUNC void func_80022B90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022B90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80022B94: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x80022B98: addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // 0x80022B9C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80022BA0: lhu         $v0, -0x574C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X574C);
    // 0x80022BA4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80022BA8: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x80022BAC: blez        $v0, L_80022BDC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80022BB0: sw          $ra, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r31;
            goto L_80022BDC;
    }
    // 0x80022BB0: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80022BB4: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80022BB8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80022BBC: lw          $v1, -0x5BBC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5BBC);
L_80022BC0:
    // 0x80022BC0: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80022BC4: beql        $v0, $zero, L_80022BE0
    if (ctx->r2 == 0) {
        // 0x80022BC8: sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
            goto L_80022BE0;
    }
    goto skip_0;
    // 0x80022BC8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    skip_0:
    // 0x80022BCC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80022BD0: slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80022BD4: bne         $v0, $zero, L_80022BC0
    if (ctx->r2 != 0) {
        // 0x80022BD8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80022BC0;
    }
    // 0x80022BD8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80022BDC:
    // 0x80022BDC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_80022BE0:
    // 0x80022BE0: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x80022BE4: addu        $a2, $t1, $zero
    ctx->r6 = ADD32(ctx->r9, 0);
    // 0x80022BE8: jal         0x80022A00
    // 0x80022BEC: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    func_80022A00(rdram, ctx);
        goto after_0;
    // 0x80022BEC: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_0:
    // 0x80022BF0: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80022BF4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80022BF8: jr          $ra
    // 0x80022BFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80022BFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80022C00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022C00: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80022C04: lw          $v1, -0x5BBC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5BBC);
    // 0x80022C08: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80022C0C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80022C10: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x80022C14: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80022C18: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x80022C1C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80022C20: andi        $s2, $s5, 0xFFFF
    ctx->r18 = ctx->r21 & 0XFFFF;
    // 0x80022C24: sll         $v0, $s2, 2
    ctx->r2 = S32(ctx->r18 << 2);
    // 0x80022C28: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x80022C2C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80022C30: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80022C34: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80022C38: addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // 0x80022C3C: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x80022C40: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x80022C44: beq         $v0, $zero, L_80022D3C
    if (ctx->r2 == 0) {
        // 0x80022C48: addu        $s4, $a3, $zero
        ctx->r20 = ADD32(ctx->r7, 0);
            goto L_80022D3C;
    }
    // 0x80022C48: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x80022C4C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80022C50: beq         $v0, $zero, L_80022CF0
    if (ctx->r2 == 0) {
        // 0x80022C54: nop
    
            goto L_80022CF0;
    }
    // 0x80022C54: nop

    // 0x80022C58: beq         $s1, $zero, L_80022D0C
    if (ctx->r17 == 0) {
        // 0x80022C5C: andi        $s0, $s5, 0xFFFF
        ctx->r16 = ctx->r21 & 0XFFFF;
            goto L_80022D0C;
    }
    // 0x80022C5C: andi        $s0, $s5, 0xFFFF
    ctx->r16 = ctx->r21 & 0XFFFF;
    // 0x80022C60: lhu         $v1, 0x2($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X2);
    // 0x80022C64: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80022C68: lw          $a2, -0x70F8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X70F8);
    // 0x80022C6C: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80022C70: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80022C74: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80022C78: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80022C7C: lhu         $v1, 0x8($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X8);
    // 0x80022C80: lhu         $a0, 0xA($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0XA);
    // 0x80022C84: sh          $v1, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r3;
    // 0x80022C88: sh          $a0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r4;
    // 0x80022C8C: lh          $v0, 0x28($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X28);
    // 0x80022C90: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80022C94: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80022C98: bne         $v1, $v0, L_80022D0C
    if (ctx->r3 != ctx->r2) {
        // 0x80022C9C: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_80022D0C;
    }
    // 0x80022C9C: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x80022CA0: lh          $v1, 0x2A($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X2A);
    // 0x80022CA4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80022CA8: bne         $v0, $v1, L_80022D0C
    if (ctx->r2 != ctx->r3) {
        // 0x80022CAC: nop
    
            goto L_80022D0C;
    }
    // 0x80022CAC: nop

    // 0x80022CB0: lhu         $v1, 0x2($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X2);
    // 0x80022CB4: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80022CB8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80022CBC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80022CC0: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80022CC4: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x80022CC8: lhu         $s0, 0x2E($s1)
    ctx->r16 = MEM_HU(ctx->r17, 0X2E);
    // 0x80022CCC: jal         0x8001E978
    // 0x80022CD0: nop

    func_8001E978(rdram, ctx);
        goto after_0;
    // 0x80022CD0: nop

    after_0:
    // 0x80022CD4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80022CD8: bne         $s0, $v0, L_80022D0C
    if (ctx->r16 != ctx->r2) {
        // 0x80022CDC: andi        $s0, $s5, 0xFFFF
        ctx->r16 = ctx->r21 & 0XFFFF;
            goto L_80022D0C;
    }
    // 0x80022CDC: andi        $s0, $s5, 0xFFFF
    ctx->r16 = ctx->r21 & 0XFFFF;
    // 0x80022CE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80022CE4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80022CE8: j           L_80022D24
    // 0x80022CEC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
        goto L_80022D24;
    // 0x80022CEC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_80022CF0:
    // 0x80022CF0: bne         $s1, $zero, L_80022D0C
    if (ctx->r17 != 0) {
        // 0x80022CF4: andi        $s0, $s5, 0xFFFF
        ctx->r16 = ctx->r21 & 0XFFFF;
            goto L_80022D0C;
    }
    // 0x80022CF4: andi        $s0, $s5, 0xFFFF
    ctx->r16 = ctx->r21 & 0XFFFF;
    // 0x80022CF8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80022CFC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80022D00: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80022D04: j           L_80022D2C
    // 0x80022D08: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
        goto L_80022D2C;
    // 0x80022D08: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80022D0C:
    // 0x80022D0C: jal         0x80022790
    // 0x80022D10: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80022790(rdram, ctx);
        goto after_1;
    // 0x80022D10: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80022D14: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80022D18: beq         $v0, $zero, L_80022D3C
    if (ctx->r2 == 0) {
        // 0x80022D1C: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80022D3C;
    }
    // 0x80022D1C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80022D20: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_80022D24:
    // 0x80022D24: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80022D28: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
L_80022D2C:
    // 0x80022D2C: jal         0x80022A00
    // 0x80022D30: andi        $a3, $s4, 0xFF
    ctx->r7 = ctx->r20 & 0XFF;
    func_80022A00(rdram, ctx);
        goto after_2;
    // 0x80022D30: andi        $a3, $s4, 0xFF
    ctx->r7 = ctx->r20 & 0XFF;
    after_2:
    // 0x80022D34: j           L_80022D40
    // 0x80022D38: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
        goto L_80022D40;
    // 0x80022D38: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_80022D3C:
    // 0x80022D3C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80022D40:
    // 0x80022D40: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x80022D44: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80022D48: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80022D4C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80022D50: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80022D54: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80022D58: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80022D5C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80022D60: jr          $ra
    // 0x80022D64: nop

    return;
    // 0x80022D64: nop

;}
RECOMP_FUNC void func_80022D68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022D68: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80022D6C: lhu         $v0, -0x574C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X574C);
    // 0x80022D70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80022D74: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80022D78: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80022D7C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80022D80: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80022D84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80022D88: beq         $v0, $zero, L_80022E38
    if (ctx->r2 == 0) {
        // 0x80022D8C: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_80022E38;
    }
    // 0x80022D8C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_80022D90:
    // 0x80022D90: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80022D94: lw          $v1, -0x5BBC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5BBC);
    // 0x80022D98: andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
    // 0x80022D9C: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x80022DA0: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // 0x80022DA4: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80022DA8: beq         $v0, $zero, L_80022E1C
    if (ctx->r2 == 0) {
        // 0x80022DAC: nop
    
            goto L_80022E1C;
    }
    // 0x80022DAC: nop

    // 0x80022DB0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80022DB4: lw          $a1, 0x43AC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X43AC);
    // 0x80022DB8: beql        $a1, $zero, L_80022DDC
    if (ctx->r5 == 0) {
        // 0x80022DBC: andi        $v0, $v0, 0x1
        ctx->r2 = ctx->r2 & 0X1;
            goto L_80022DDC;
    }
    goto skip_0;
    // 0x80022DBC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    skip_0:
    // 0x80022DC0: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80022DC4: beq         $v0, $zero, L_80022DE4
    if (ctx->r2 == 0) {
        // 0x80022DC8: sll         $a0, $s0, 4
        ctx->r4 = S32(ctx->r16 << 4);
            goto L_80022DE4;
    }
    // 0x80022DC8: sll         $a0, $s0, 4
    ctx->r4 = S32(ctx->r16 << 4);
    // 0x80022DCC: addu        $a0, $a1, $a0
    ctx->r4 = ADD32(ctx->r5, ctx->r4);
    // 0x80022DD0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80022DD4: j           L_80022E0C
    // 0x80022DD8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
        goto L_80022E0C;
    // 0x80022DD8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
L_80022DDC:
    // 0x80022DDC: beq         $v0, $zero, L_80022E1C
    if (ctx->r2 == 0) {
        // 0x80022DE0: nop
    
            goto L_80022E1C;
    }
    // 0x80022DE0: nop

L_80022DE4:
    // 0x80022DE4: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x80022DE8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80022DEC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80022DF0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80022DF4: lw          $a0, -0x70F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X70F8);
    // 0x80022DF8: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x80022DFC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80022E00: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80022E04: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80022E08: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
L_80022E0C:
    // 0x80022E0C: jal         0x800077A8
    // 0x80022E10: nop

    rs_strncmp(rdram, ctx);
        goto after_0;
    // 0x80022E10: nop

    after_0:
    // 0x80022E14: beq         $v0, $zero, L_80022E3C
    if (ctx->r2 == 0) {
        // 0x80022E18: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_80022E3C;
    }
    // 0x80022E18: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80022E1C:
    // 0x80022E1C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80022E20: lhu         $v1, -0x574C($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X574C);
    // 0x80022E24: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80022E28: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
    // 0x80022E2C: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80022E30: bne         $v0, $zero, L_80022D90
    if (ctx->r2 != 0) {
        // 0x80022E34: nop
    
            goto L_80022D90;
    }
    // 0x80022E34: nop

L_80022E38:
    // 0x80022E38: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80022E3C:
    // 0x80022E3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80022E40: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80022E44: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80022E48: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80022E4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80022E50: jr          $ra
    // 0x80022E54: nop

    return;
    // 0x80022E54: nop

;}
RECOMP_FUNC void func_80022E58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022E58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80022E5C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80022E60: lw          $v0, -0x5BBC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5BBC);
    // 0x80022E64: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x80022E68: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80022E6C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80022E70: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80022E74: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80022E78: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80022E7C: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80022E80: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80022E84: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80022E88: beq         $v0, $zero, L_80022F2C
    if (ctx->r2 == 0) {
        // 0x80022E8C: addu        $s1, $a2, $zero
        ctx->r17 = ADD32(ctx->r6, 0);
            goto L_80022F2C;
    }
    // 0x80022E8C: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x80022E90: lhu         $v1, 0x2($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X2);
    // 0x80022E94: sh          $a0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r4;
    // 0x80022E98: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80022E9C: lw          $a0, -0x70F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X70F8);
    // 0x80022EA0: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80022EA4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80022EA8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80022EAC: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // 0x80022EB0: lhu         $v1, 0xC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XC);
    // 0x80022EB4: sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // 0x80022EB8: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x80022EBC: sw          $v1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r3;
    // 0x80022EC0: lwl         $v1, 0x4($a0)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r4, 0X4);
    // 0x80022EC4: lwr         $v1, 0x7($a0)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r4, 0X7);
    // 0x80022EC8: swl         $v1, 0x6($s0)
    do_swl(rdram, 0X6, ctx->r16, ctx->r3);
    // 0x80022ECC: swr         $v1, 0x9($s0)
    do_swr(rdram, 0X9, ctx->r16, ctx->r3);
    // 0x80022ED0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80022ED4: lw          $v1, -0x70F8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X70F8);
    // 0x80022ED8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80022EDC: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x80022EE0: jal         0x8001E978
    // 0x80022EE4: nop

    func_8001E978(rdram, ctx);
        goto after_0;
    // 0x80022EE4: nop

    after_0:
    // 0x80022EE8: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
    // 0x80022EEC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80022EF0: bnel        $v0, $zero, L_80022F14
    if (ctx->r2 != 0) {
        // 0x80022EF4: sb          $zero, 0x2($s0)
        MEM_B(0X2, ctx->r16) = 0;
            goto L_80022F14;
    }
    goto skip_0;
    // 0x80022EF4: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
    skip_0:
    // 0x80022EF8: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80022EFC: jal         0x80001ACC
    // 0x80022F00: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x80022F00: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x80022F04: beq         $v0, $zero, L_80022F2C
    if (ctx->r2 == 0) {
        // 0x80022F08: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_80022F2C;
    }
    // 0x80022F08: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80022F0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80022F10: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
L_80022F14:
    // 0x80022F14: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    // 0x80022F18: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80022F1C: jal         0x800346F0
    // 0x80022F20: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    memcpy_recomp(rdram, ctx);
        goto after_2;
    // 0x80022F20: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
    // 0x80022F24: j           L_80022F30
    // 0x80022F28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80022F30;
    // 0x80022F28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80022F2C:
    // 0x80022F2C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80022F30:
    // 0x80022F30: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80022F34: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80022F38: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80022F3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80022F40: jr          $ra
    // 0x80022F44: nop

    return;
    // 0x80022F44: nop

;}
RECOMP_FUNC void func_80022F48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022F48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80022F4C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80022F50: lw          $v0, -0x5BBC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5BBC);
    // 0x80022F54: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x80022F58: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80022F5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022F60: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80022F64: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80022F68: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80022F6C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80022F70: bne         $v0, $zero, L_80022F80
    if (ctx->r2 != 0) {
        // 0x80022F74: addu        $s0, $a1, $zero
        ctx->r16 = ADD32(ctx->r5, 0);
            goto L_80022F80;
    }
    // 0x80022F74: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80022F78: j           L_80022FE4
    // 0x80022F7C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80022FE4;
    // 0x80022F7C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80022F80:
    // 0x80022F80: lhu         $v1, 0x2($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X2);
    // 0x80022F84: sh          $a0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r4;
    // 0x80022F88: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80022F8C: lw          $a0, -0x70F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X70F8);
    // 0x80022F90: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80022F94: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80022F98: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80022F9C: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // 0x80022FA0: lhu         $v1, 0xC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XC);
    // 0x80022FA4: sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // 0x80022FA8: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x80022FAC: sw          $v1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r3;
    // 0x80022FB0: lwl         $v1, 0x4($a0)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r4, 0X4);
    // 0x80022FB4: lwr         $v1, 0x7($a0)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r4, 0X7);
    // 0x80022FB8: swl         $v1, 0x6($s0)
    do_swl(rdram, 0X6, ctx->r16, ctx->r3);
    // 0x80022FBC: swr         $v1, 0x9($s0)
    do_swr(rdram, 0X9, ctx->r16, ctx->r3);
    // 0x80022FC0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80022FC4: lw          $v1, -0x70F8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X70F8);
    // 0x80022FC8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80022FCC: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x80022FD0: jal         0x8001E978
    // 0x80022FD4: nop

    func_8001E978(rdram, ctx);
        goto after_0;
    // 0x80022FD4: nop

    after_0:
    // 0x80022FD8: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
    // 0x80022FDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80022FE0: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
L_80022FE4:
    // 0x80022FE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80022FE8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80022FEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80022FF0: jr          $ra
    // 0x80022FF4: nop

    return;
    // 0x80022FF4: nop

;}
RECOMP_FUNC void func_80022FF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022FF8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80022FFC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80023000: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80023004: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80023008: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x8002300C: sw          $ra, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r31;
    // 0x80023010: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80023014: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80023018: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8002301C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80023020: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80023024: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80023028: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8002302C: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x80023030: bne         $v0, $zero, L_80023060
    if (ctx->r2 != 0) {
        // 0x80023034: addu        $s7, $a3, $zero
        ctx->r23 = ADD32(ctx->r7, 0);
            goto L_80023060;
    }
    // 0x80023034: addu        $s7, $a3, $zero
    ctx->r23 = ADD32(ctx->r7, 0);
    // 0x80023038: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x8002303C: jal         0x80001ACC
    // 0x80023040: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x80023040: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80023044: bne         $v0, $zero, L_80023054
    if (ctx->r2 != 0) {
        // 0x80023048: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_80023054;
    }
    // 0x80023048: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8002304C: j           L_80023244
    // 0x80023050: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80023244;
    // 0x80023050: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80023054:
    // 0x80023054: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80023058: j           L_80023064
    // 0x8002305C: sb          $v0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r2;
        goto L_80023064;
    // 0x8002305C: sb          $v0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r2;
L_80023060:
    // 0x80023060: sb          $zero, 0x2($s1)
    MEM_B(0X2, ctx->r17) = 0;
L_80023064:
    // 0x80023064: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x80023068: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002306C: lw          $v1, -0x5BBC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5BBC);
    // 0x80023070: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80023074: lhu         $s0, 0x4($s1)
    ctx->r16 = MEM_HU(ctx->r17, 0X4);
    // 0x80023078: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002307C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80023080: lh          $t0, 0x2($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X2);
    // 0x80023084: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80023088: lw          $v1, -0x70F8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X70F8);
    // 0x8002308C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80023090: sll         $v0, $t0, 3
    ctx->r2 = S32(ctx->r8 << 3);
    // 0x80023094: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80023098: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002309C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800230A0: lbu         $s5, 0x3($v0)
    ctx->r21 = MEM_BU(ctx->r2, 0X3);
    // 0x800230A4: lhu         $s2, 0x8($v0)
    ctx->r18 = MEM_HU(ctx->r2, 0X8);
    // 0x800230A8: lhu         $s3, 0xA($v0)
    ctx->r19 = MEM_HU(ctx->r2, 0XA);
    // 0x800230AC: lbu         $v1, 0x2($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X2);
    // 0x800230B0: addiu       $v0, $s1, 0x6
    ctx->r2 = ADD32(ctx->r17, 0X6);
    // 0x800230B4: addu        $s6, $t0, $zero
    ctx->r22 = ADD32(ctx->r8, 0);
    // 0x800230B8: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x800230BC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800230C0: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x800230C4: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // 0x800230C8: jal         0x8001EB24
    // 0x800230CC: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    func_8001EB24(rdram, ctx);
        goto after_1;
    // 0x800230CC: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_1:
    // 0x800230D0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800230D4: andi        $v0, $s0, 0x800
    ctx->r2 = ctx->r16 & 0X800;
    // 0x800230D8: bne         $v0, $zero, L_800230EC
    if (ctx->r2 != 0) {
        // 0x800230DC: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_800230EC;
    }
    // 0x800230DC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800230E0: andi        $v0, $s0, 0x400
    ctx->r2 = ctx->r16 & 0X400;
    // 0x800230E4: beq         $v0, $zero, L_80023118
    if (ctx->r2 == 0) {
        // 0x800230E8: addiu       $a1, $zero, 0x5
        ctx->r5 = ADD32(0, 0X5);
            goto L_80023118;
    }
    // 0x800230E8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_800230EC:
    // 0x800230EC: andi        $a3, $s5, 0xFF
    ctx->r7 = ctx->r21 & 0XFF;
    // 0x800230F0: srav        $a2, $s2, $a3
    ctx->r6 = S32(SIGNED(ctx->r18) >> (ctx->r7 & 31));
    // 0x800230F4: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x800230F8: srav        $a3, $s3, $a3
    ctx->r7 = S32(SIGNED(ctx->r19) >> (ctx->r7 & 31));
    // 0x800230FC: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x80023100: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80023104: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80023108: addiu       $v0, $s4, 0x4
    ctx->r2 = ADD32(ctx->r20, 0X4);
    // 0x8002310C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80023110: jal         0x8001EB24
    // 0x80023114: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_8001EB24(rdram, ctx);
        goto after_2;
    // 0x80023114: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_2:
L_80023118:
    // 0x80023118: sll         $v0, $s6, 16
    ctx->r2 = S32(ctx->r22 << 16);
    // 0x8002311C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80023120: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80023124: lw          $a0, -0x70F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X70F8);
    // 0x80023128: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x8002312C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80023130: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80023134: lhu         $a1, 0x4($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X4);
    // 0x80023138: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8002313C: lhu         $a0, 0xE($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0XE);
    // 0x80023140: andi        $v1, $a1, 0xF
    ctx->r3 = ctx->r5 & 0XF;
    // 0x80023144: beq         $v1, $zero, L_80023160
    if (ctx->r3 == 0) {
        // 0x80023148: addiu       $t2, $s1, 0x6
        ctx->r10 = ADD32(ctx->r17, 0X6);
            goto L_80023160;
    }
    // 0x80023148: addiu       $t2, $s1, 0x6
    ctx->r10 = ADD32(ctx->r17, 0X6);
    // 0x8002314C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80023150: beq         $v1, $v0, L_80023164
    if (ctx->r3 == ctx->r2) {
        // 0x80023154: addiu       $t0, $zero, 0x100
        ctx->r8 = ADD32(0, 0X100);
            goto L_80023164;
    }
    // 0x80023154: addiu       $t0, $zero, 0x100
    ctx->r8 = ADD32(0, 0X100);
    // 0x80023158: j           L_80023244
    // 0x8002315C: nop

        goto L_80023244;
    // 0x8002315C: nop

L_80023160:
    // 0x80023160: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
L_80023164:
    // 0x80023164: lui         $v0, 0xFF00
    ctx->r2 = S32(0XFF00 << 16);
    // 0x80023168: and         $v0, $s7, $v0
    ctx->r2 = ctx->r23 & ctx->r2;
    // 0x8002316C: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x80023170: bne         $v0, $v1, L_80023244
    if (ctx->r2 != ctx->r3) {
        // 0x80023174: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80023244;
    }
    // 0x80023174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80023178: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8002317C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80023180: bne         $a0, $v0, L_8002321C
    if (ctx->r4 != ctx->r2) {
        // 0x80023184: sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4 << 2);
            goto L_8002321C;
    }
    // 0x80023184: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80023188: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8002318C: lhu         $v0, -0x70FC($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X70FC);
    // 0x80023190: beq         $v0, $zero, L_800231D8
    if (ctx->r2 == 0) {
        // 0x80023194: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800231D8;
    }
    // 0x80023194: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80023198: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8002319C: lw          $a2, -0x7104($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7104);
    // 0x800231A0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800231A4: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
L_800231A8:
    // 0x800231A8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800231AC: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800231B0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800231B4: beq         $v0, $zero, L_800231D0
    if (ctx->r2 == 0) {
        // 0x800231B8: nop
    
            goto L_800231D0;
    }
    // 0x800231B8: nop

    // 0x800231BC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800231C0: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800231C4: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800231C8: bne         $v0, $zero, L_800231A8
    if (ctx->r2 != 0) {
        // 0x800231CC: andi        $v0, $a0, 0xFFFF
        ctx->r2 = ctx->r4 & 0XFFFF;
            goto L_800231A8;
    }
    // 0x800231CC: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
L_800231D0:
    // 0x800231D0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800231D4: lhu         $v0, -0x70FC($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X70FC);
L_800231D8:
    // 0x800231D8: andi        $t1, $a0, 0xFFFF
    ctx->r9 = ctx->r4 & 0XFFFF;
    // 0x800231DC: beq         $t1, $v0, L_80023240
    if (ctx->r9 == ctx->r2) {
        // 0x800231E0: addu        $a2, $s7, $zero
        ctx->r6 = ADD32(ctx->r23, 0);
            goto L_80023240;
    }
    // 0x800231E0: addu        $a2, $s7, $zero
    ctx->r6 = ADD32(ctx->r23, 0);
    // 0x800231E4: addu        $a3, $t0, $zero
    ctx->r7 = ADD32(ctx->r8, 0);
    // 0x800231E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800231EC: lw          $a0, -0x5830($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5830);
    // 0x800231F0: sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8 << 1);
    // 0x800231F4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800231F8: lw          $v1, -0x7104($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7104);
    // 0x800231FC: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80023200: sll         $v0, $t1, 2
    ctx->r2 = S32(ctx->r9 << 2);
    // 0x80023204: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80023208: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002320C: sw          $a0, -0x5830($at)
    MEM_W(-0X5830, ctx->r1) = ctx->r4;
    // 0x80023210: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80023214: j           L_80023238
    // 0x80023218: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
        goto L_80023238;
    // 0x80023218: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
L_8002321C:
    // 0x8002321C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80023220: lw          $v1, -0x7104($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7104);
    // 0x80023224: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80023228: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8002322C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80023230: addu        $a2, $s7, $zero
    ctx->r6 = ADD32(ctx->r23, 0);
    // 0x80023234: addu        $a3, $t0, $zero
    ctx->r7 = ADD32(ctx->r8, 0);
L_80023238:
    // 0x80023238: jal         0x8001E36C
    // 0x8002323C: nop

    func_8001E36C(rdram, ctx);
        goto after_3;
    // 0x8002323C: nop

    after_3:
L_80023240:
    // 0x80023240: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80023244:
    // 0x80023244: lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X48);
    // 0x80023248: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8002324C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80023250: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80023254: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80023258: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8002325C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80023260: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80023264: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80023268: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8002326C: jr          $ra
    // 0x80023270: nop

    return;
    // 0x80023270: nop

;}
RECOMP_FUNC void func_80023274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023274: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80023278: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002327C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80023280: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80023284: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80023288: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x8002328C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80023290: lw          $v1, -0x5BBC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5BBC);
    // 0x80023294: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80023298: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8002329C: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800232A0: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800232A4: beq         $v0, $zero, L_800232DC
    if (ctx->r2 == 0) {
        // 0x800232A8: addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
            goto L_800232DC;
    }
    // 0x800232A8: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800232AC: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x800232B0: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x800232B4: jal         0x800346F0
    // 0x800232B8: nop

    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x800232B8: nop

    after_0:
    // 0x800232BC: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x800232C0: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800232C4: beq         $v0, $zero, L_800232E0
    if (ctx->r2 == 0) {
        // 0x800232C8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800232E0;
    }
    // 0x800232C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800232CC: jal         0x80001C98
    // 0x800232D0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    rs_free(rdram, ctx);
        goto after_1;
    // 0x800232D0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x800232D4: j           L_800232E0
    // 0x800232D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800232E0;
    // 0x800232D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800232DC:
    // 0x800232DC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800232E0:
    // 0x800232E0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800232E4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800232E8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800232EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800232F0: jr          $ra
    // 0x800232F4: nop

    return;
    // 0x800232F4: nop

;}
RECOMP_FUNC void func_800232F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800232F8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800232FC: lw          $v0, -0x5BBC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5BBC);
    // 0x80023300: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80023304: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80023308: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8002330C: lhu         $v1, 0x2($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X2);
    // 0x80023310: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80023314: lw          $a0, -0x70F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X70F8);
    // 0x80023318: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x8002331C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80023320: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80023324: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80023328: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x8002332C: jr          $ra
    // 0x80023330: nop

    return;
    // 0x80023330: nop

;}
RECOMP_FUNC void func_80023334(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023334: jr          $ra
    // 0x80023338: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80023338: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_8002333C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002333C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80023340: lw          $v0, -0x7104($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7104);
    // 0x80023344: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80023348: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8002334C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80023350: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80023354: jr          $ra
    // 0x80023358: nop

    return;
    // 0x80023358: nop

;}
RECOMP_FUNC void func_8002335C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002335C: jr          $ra
    // 0x80023360: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80023360: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80023364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023364: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80023368: lw          $v0, -0x5BBC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5BBC);
    // 0x8002336C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80023370: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80023374: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80023378: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8002337C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80023380: beq         $v0, $zero, L_800233A8
    if (ctx->r2 == 0) {
        // 0x80023384: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_800233A8;
    }
    // 0x80023384: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80023388: lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2);
    // 0x8002338C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80023390: lw          $a0, -0x70F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X70F8);
    // 0x80023394: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x80023398: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8002339C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800233A0: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800233A4: lhu         $v0, 0xE($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XE);
L_800233A8:
    // 0x800233A8: jr          $ra
    // 0x800233AC: nop

    return;
    // 0x800233AC: nop

;}
RECOMP_FUNC void func_800233B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800233B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800233B4: addu        $t3, $a0, $zero
    ctx->r11 = ADD32(ctx->r4, 0);
    // 0x800233B8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800233BC: xori        $a1, $a1, 0x10
    ctx->r5 = ctx->r5 ^ 0X10;
    // 0x800233C0: sltu        $a1, $zero, $a1
    ctx->r5 = 0 < ctx->r5 ? 1 : 0;
    // 0x800233C4: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x800233C8: addu        $t4, $a3, $zero
    ctx->r12 = ADD32(ctx->r7, 0);
    // 0x800233CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800233D0: beq         $t4, $zero, L_800233DC
    if (ctx->r12 == 0) {
        // 0x800233D4: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800233DC;
    }
    // 0x800233D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800233D8: ori         $t0, $a1, 0x4000
    ctx->r8 = ctx->r5 | 0X4000;
L_800233DC:
    // 0x800233DC: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x800233E0: bnel        $v0, $zero, L_800233E8
    if (ctx->r2 != 0) {
        // 0x800233E4: ori         $t0, $t0, 0x8000
        ctx->r8 = ctx->r8 | 0X8000;
            goto L_800233E8;
    }
    goto skip_0;
    // 0x800233E4: ori         $t0, $t0, 0x8000
    ctx->r8 = ctx->r8 | 0X8000;
    skip_0:
L_800233E8:
    // 0x800233E8: andi        $v1, $t0, 0xF
    ctx->r3 = ctx->r8 & 0XF;
    // 0x800233EC: beq         $v1, $zero, L_80023408
    if (ctx->r3 == 0) {
        // 0x800233F0: ori         $s0, $zero, 0xFFFF
        ctx->r16 = 0 | 0XFFFF;
            goto L_80023408;
    }
    // 0x800233F0: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    // 0x800233F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800233F8: beq         $v1, $v0, L_8002340C
    if (ctx->r3 == ctx->r2) {
        // 0x800233FC: addiu       $t2, $zero, 0x100
        ctx->r10 = ADD32(0, 0X100);
            goto L_8002340C;
    }
    // 0x800233FC: addiu       $t2, $zero, 0x100
    ctx->r10 = ADD32(0, 0X100);
    // 0x80023400: j           L_800234FC
    // 0x80023404: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
        goto L_800234FC;
    // 0x80023404: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80023408:
    // 0x80023408: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
L_8002340C:
    // 0x8002340C: lui         $v0, 0xFF00
    ctx->r2 = S32(0XFF00 << 16);
    // 0x80023410: and         $v0, $t3, $v0
    ctx->r2 = ctx->r11 & ctx->r2;
    // 0x80023414: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x80023418: bne         $v0, $v1, L_800234FC
    if (ctx->r2 != ctx->r3) {
        // 0x8002341C: addu        $v0, $t3, $zero
        ctx->r2 = ADD32(ctx->r11, 0);
            goto L_800234FC;
    }
    // 0x8002341C: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
    // 0x80023420: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x80023424: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80023428: bne         $a0, $v0, L_800234D0
    if (ctx->r4 != ctx->r2) {
        // 0x8002342C: andi        $a1, $t0, 0xFFFF
        ctx->r5 = ctx->r8 & 0XFFFF;
            goto L_800234D0;
    }
    // 0x8002342C: andi        $a1, $t0, 0xFFFF
    ctx->r5 = ctx->r8 & 0XFFFF;
    // 0x80023430: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80023434: lhu         $v0, -0x70FC($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X70FC);
    // 0x80023438: beq         $v0, $zero, L_80023480
    if (ctx->r2 == 0) {
        // 0x8002343C: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_80023480;
    }
    // 0x8002343C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80023440: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80023444: lw          $a0, -0x7104($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7104);
    // 0x80023448: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8002344C: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
L_80023450:
    // 0x80023450: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80023454: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80023458: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8002345C: beq         $v0, $zero, L_80023478
    if (ctx->r2 == 0) {
        // 0x80023460: nop
    
            goto L_80023478;
    }
    // 0x80023460: nop

    // 0x80023464: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80023468: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x8002346C: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80023470: bne         $v0, $zero, L_80023450
    if (ctx->r2 != 0) {
        // 0x80023474: andi        $v0, $s0, 0xFFFF
        ctx->r2 = ctx->r16 & 0XFFFF;
            goto L_80023450;
    }
    // 0x80023474: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
L_80023478:
    // 0x80023478: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8002347C: lhu         $v0, -0x70FC($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X70FC);
L_80023480:
    // 0x80023480: andi        $t1, $s0, 0xFFFF
    ctx->r9 = ctx->r16 & 0XFFFF;
    // 0x80023484: bne         $t1, $v0, L_80023494
    if (ctx->r9 != ctx->r2) {
        // 0x80023488: andi        $a1, $t0, 0xFFFF
        ctx->r5 = ctx->r8 & 0XFFFF;
            goto L_80023494;
    }
    // 0x80023488: andi        $a1, $t0, 0xFFFF
    ctx->r5 = ctx->r8 & 0XFFFF;
    // 0x8002348C: j           L_800234FC
    // 0x80023490: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
        goto L_800234FC;
    // 0x80023490: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80023494:
    // 0x80023494: addu        $a2, $t3, $zero
    ctx->r6 = ADD32(ctx->r11, 0);
    // 0x80023498: addu        $a3, $t2, $zero
    ctx->r7 = ADD32(ctx->r10, 0);
    // 0x8002349C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800234A0: lw          $a0, -0x5830($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5830);
    // 0x800234A4: sll         $v0, $t2, 1
    ctx->r2 = S32(ctx->r10 << 1);
    // 0x800234A8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800234AC: lw          $v1, -0x7104($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7104);
    // 0x800234B0: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x800234B4: sll         $v0, $t1, 2
    ctx->r2 = S32(ctx->r9 << 2);
    // 0x800234B8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800234BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800234C0: sw          $a0, -0x5830($at)
    MEM_W(-0X5830, ctx->r1) = ctx->r4;
    // 0x800234C4: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800234C8: j           L_800234F0
    // 0x800234CC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
        goto L_800234F0;
    // 0x800234CC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
L_800234D0:
    // 0x800234D0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800234D4: lw          $v1, -0x7104($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7104);
    // 0x800234D8: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800234DC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800234E0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800234E4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800234E8: addu        $a2, $t3, $zero
    ctx->r6 = ADD32(ctx->r11, 0);
    // 0x800234EC: addu        $a3, $t2, $zero
    ctx->r7 = ADD32(ctx->r10, 0);
L_800234F0:
    // 0x800234F0: jal         0x8001E36C
    // 0x800234F4: nop

    func_8001E36C(rdram, ctx);
        goto after_0;
    // 0x800234F4: nop

    after_0:
    // 0x800234F8: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_800234FC:
    // 0x800234FC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80023500: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80023504: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80023508: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002350C: jr          $ra
    // 0x80023510: nop

    return;
    // 0x80023510: nop

;}
RECOMP_FUNC void func_80023514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023514: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80023518: addu        $t2, $a1, $zero
    ctx->r10 = ADD32(ctx->r5, 0);
    // 0x8002351C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80023520: xori        $a2, $a2, 0x10
    ctx->r6 = ctx->r6 ^ 0X10;
    // 0x80023524: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80023528: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    // 0x8002352C: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // 0x80023530: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80023534: beq         $t3, $zero, L_80023540
    if (ctx->r11 == 0) {
        // 0x80023538: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80023540;
    }
    // 0x80023538: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002353C: ori         $a1, $a2, 0x4000
    ctx->r5 = ctx->r6 | 0X4000;
L_80023540:
    // 0x80023540: andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // 0x80023544: bnel        $v0, $zero, L_8002354C
    if (ctx->r2 != 0) {
        // 0x80023548: ori         $a1, $a1, 0x8000
        ctx->r5 = ctx->r5 | 0X8000;
            goto L_8002354C;
    }
    goto skip_0;
    // 0x80023548: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    skip_0:
L_8002354C:
    // 0x8002354C: andi        $v1, $a1, 0xF
    ctx->r3 = ctx->r5 & 0XF;
    // 0x80023550: beq         $v1, $zero, L_8002356C
    if (ctx->r3 == 0) {
        // 0x80023554: addu        $s0, $a0, $zero
        ctx->r16 = ADD32(ctx->r4, 0);
            goto L_8002356C;
    }
    // 0x80023554: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80023558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002355C: beq         $v1, $v0, L_80023570
    if (ctx->r3 == ctx->r2) {
        // 0x80023560: addiu       $t1, $zero, 0x100
        ctx->r9 = ADD32(0, 0X100);
            goto L_80023570;
    }
    // 0x80023560: addiu       $t1, $zero, 0x100
    ctx->r9 = ADD32(0, 0X100);
    // 0x80023564: j           L_80023660
    // 0x80023568: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
        goto L_80023660;
    // 0x80023568: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
L_8002356C:
    // 0x8002356C: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
L_80023570:
    // 0x80023570: lui         $v0, 0xFF00
    ctx->r2 = S32(0XFF00 << 16);
    // 0x80023574: and         $v0, $t2, $v0
    ctx->r2 = ctx->r10 & ctx->r2;
    // 0x80023578: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x8002357C: bne         $v0, $v1, L_80023660
    if (ctx->r2 != ctx->r3) {
        // 0x80023580: addu        $a0, $t2, $zero
        ctx->r4 = ADD32(ctx->r10, 0);
            goto L_80023660;
    }
    // 0x80023580: addu        $a0, $t2, $zero
    ctx->r4 = ADD32(ctx->r10, 0);
    // 0x80023584: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x80023588: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8002358C: bnel        $a0, $v0, L_80023634
    if (ctx->r4 != ctx->r2) {
        // 0x80023590: andi        $a1, $a1, 0xFFFF
        ctx->r5 = ctx->r5 & 0XFFFF;
            goto L_80023634;
    }
    goto skip_1;
    // 0x80023590: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    skip_1:
    // 0x80023594: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80023598: lhu         $v0, -0x70FC($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X70FC);
    // 0x8002359C: beq         $v0, $zero, L_800235E4
    if (ctx->r2 == 0) {
        // 0x800235A0: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_800235E4;
    }
    // 0x800235A0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800235A4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800235A8: lw          $a0, -0x7104($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7104);
    // 0x800235AC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800235B0: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
L_800235B4:
    // 0x800235B4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800235B8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800235BC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800235C0: beq         $v0, $zero, L_800235DC
    if (ctx->r2 == 0) {
        // 0x800235C4: nop
    
            goto L_800235DC;
    }
    // 0x800235C4: nop

    // 0x800235C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800235CC: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x800235D0: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800235D4: bne         $v0, $zero, L_800235B4
    if (ctx->r2 != 0) {
        // 0x800235D8: andi        $v0, $s0, 0xFFFF
        ctx->r2 = ctx->r16 & 0XFFFF;
            goto L_800235B4;
    }
    // 0x800235D8: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
L_800235DC:
    // 0x800235DC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800235E0: lhu         $v0, -0x70FC($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X70FC);
L_800235E4:
    // 0x800235E4: andi        $t0, $s0, 0xFFFF
    ctx->r8 = ctx->r16 & 0XFFFF;
    // 0x800235E8: bne         $t0, $v0, L_800235F8
    if (ctx->r8 != ctx->r2) {
        // 0x800235EC: andi        $a1, $a1, 0xFFFF
        ctx->r5 = ctx->r5 & 0XFFFF;
            goto L_800235F8;
    }
    // 0x800235EC: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800235F0: j           L_80023660
    // 0x800235F4: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
        goto L_80023660;
    // 0x800235F4: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
L_800235F8:
    // 0x800235F8: addu        $a2, $t2, $zero
    ctx->r6 = ADD32(ctx->r10, 0);
    // 0x800235FC: addu        $a3, $t1, $zero
    ctx->r7 = ADD32(ctx->r9, 0);
    // 0x80023600: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80023604: lw          $a0, -0x5830($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5830);
    // 0x80023608: sll         $v0, $t1, 1
    ctx->r2 = S32(ctx->r9 << 1);
    // 0x8002360C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80023610: lw          $v1, -0x7104($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7104);
    // 0x80023614: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80023618: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x8002361C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80023620: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80023624: sw          $a0, -0x5830($at)
    MEM_W(-0X5830, ctx->r1) = ctx->r4;
    // 0x80023628: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8002362C: j           L_80023654
    // 0x80023630: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
        goto L_80023654;
    // 0x80023630: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
L_80023634:
    // 0x80023634: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80023638: lw          $v1, -0x7104($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7104);
    // 0x8002363C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80023640: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80023644: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80023648: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8002364C: addu        $a2, $t2, $zero
    ctx->r6 = ADD32(ctx->r10, 0);
    // 0x80023650: addu        $a3, $t1, $zero
    ctx->r7 = ADD32(ctx->r9, 0);
L_80023654:
    // 0x80023654: jal         0x8001E36C
    // 0x80023658: nop

    func_8001E36C(rdram, ctx);
        goto after_0;
    // 0x80023658: nop

    after_0:
    // 0x8002365C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80023660:
    // 0x80023660: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x80023664: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80023668: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002366C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80023670: jr          $ra
    // 0x80023674: nop

    return;
    // 0x80023674: nop

;}
RECOMP_FUNC void func_80023678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023678: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002367C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80023680: sltu        $v0, $zero, $t2
    ctx->r2 = 0 < ctx->r10 ? 1 : 0;
    // 0x80023684: sll         $v1, $v0, 14
    ctx->r3 = S32(ctx->r2 << 14);
    // 0x80023688: lbu         $v0, 0x33($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X33);
    // 0x8002368C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80023690: beq         $v0, $zero, L_800236AC
    if (ctx->r2 == 0) {
        // 0x80023694: addu        $t1, $v1, $zero
        ctx->r9 = ADD32(ctx->r3, 0);
            goto L_800236AC;
    }
    // 0x80023694: addu        $t1, $v1, $zero
    ctx->r9 = ADD32(ctx->r3, 0);
    // 0x80023698: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x8002369C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800236A0: addu        $t0, $a1, $v0
    ctx->r8 = ADD32(ctx->r5, ctx->r2);
    // 0x800236A4: j           L_800236BC
    // 0x800236A8: ori         $t1, $v1, 0x8000
    ctx->r9 = ctx->r3 | 0X8000;
        goto L_800236BC;
    // 0x800236A8: ori         $t1, $v1, 0x8000
    ctx->r9 = ctx->r3 | 0X8000;
L_800236AC:
    // 0x800236AC: andi        $v1, $a2, 0xFF
    ctx->r3 = ctx->r6 & 0XFF;
    // 0x800236B0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800236B4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800236B8: addu        $t0, $a1, $v0
    ctx->r8 = ADD32(ctx->r5, ctx->r2);
L_800236BC:
    // 0x800236BC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800236C0: lw          $v1, -0x7104($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7104);
    // 0x800236C4: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800236C8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800236CC: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x800236D0: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x800236D4: addu        $a1, $t1, $zero
    ctx->r5 = ADD32(ctx->r9, 0);
    // 0x800236D8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800236DC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800236E0: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    // 0x800236E4: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x800236E8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800236EC: jal         0x8001E36C
    // 0x800236F0: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    func_8001E36C(rdram, ctx);
        goto after_0;
    // 0x800236F0: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_0:
    // 0x800236F4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800236F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800236FC: jr          $ra
    // 0x80023700: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80023700: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80023704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023704: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80023708: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8002370C: lw          $v0, -0x7104($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7104);
    // 0x80023710: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80023714: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80023718: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8002371C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80023720: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80023724: lbu         $v1, 0x23($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X23);
    // 0x80023728: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x8002372C: beq         $v1, $zero, L_800237C8
    if (ctx->r3 == 0) {
        // 0x80023730: addu        $v0, $v0, $a2
        ctx->r2 = ADD32(ctx->r2, ctx->r6);
            goto L_800237C8;
    }
    // 0x80023730: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80023734: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x80023738: blez        $a3, L_8002383C
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8002373C: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_8002383C;
    }
    // 0x8002373C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80023740: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80023744:
    // 0x80023744: lhu         $a0, 0x0($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X0);
    // 0x80023748: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8002374C: srl         $v0, $a0, 11
    ctx->r2 = S32(U32(ctx->r4) >> 11);
    // 0x80023750: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x80023754: srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // 0x80023758: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8002375C: sb          $v1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r3;
    // 0x80023760: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80023764: srl         $v0, $a0, 6
    ctx->r2 = S32(U32(ctx->r4) >> 6);
    // 0x80023768: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x8002376C: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x80023770: srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // 0x80023774: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80023778: sb          $v1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r3;
    // 0x8002377C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80023780: srl         $a0, $a0, 1
    ctx->r4 = S32(U32(ctx->r4) >> 1);
    // 0x80023784: andi        $a0, $a0, 0x1F
    ctx->r4 = ctx->r4 & 0X1F;
    // 0x80023788: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x8002378C: srl         $a0, $a0, 2
    ctx->r4 = S32(U32(ctx->r4) >> 2);
    // 0x80023790: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x80023794: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x80023798: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8002379C: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // 0x800237A0: lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X0);
    // 0x800237A4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800237A8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800237AC: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x800237B0: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x800237B4: slt         $v0, $a2, $a3
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800237B8: bne         $v0, $zero, L_80023744
    if (ctx->r2 != 0) {
        // 0x800237BC: addiu       $t0, $t0, 0x2
        ctx->r8 = ADD32(ctx->r8, 0X2);
            goto L_80023744;
    }
    // 0x800237BC: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x800237C0: j           L_80023840
    // 0x800237C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80023840;
    // 0x800237C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800237C8:
    // 0x800237C8: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x800237CC: blez        $a3, L_8002383C
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800237D0: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_8002383C;
    }
    // 0x800237D0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800237D4: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_800237D8:
    // 0x800237D8: lhu         $a0, 0x0($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X0);
    // 0x800237DC: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x800237E0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800237E4: srl         $v0, $a0, 11
    ctx->r2 = S32(U32(ctx->r4) >> 11);
    // 0x800237E8: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x800237EC: srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // 0x800237F0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800237F4: sb          $v1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r3;
    // 0x800237F8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800237FC: srl         $v0, $a0, 6
    ctx->r2 = S32(U32(ctx->r4) >> 6);
    // 0x80023800: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x80023804: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x80023808: srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // 0x8002380C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80023810: sb          $v1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r3;
    // 0x80023814: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80023818: srl         $a0, $a0, 1
    ctx->r4 = S32(U32(ctx->r4) >> 1);
    // 0x8002381C: andi        $a0, $a0, 0x1F
    ctx->r4 = ctx->r4 & 0X1F;
    // 0x80023820: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x80023824: srl         $a0, $a0, 2
    ctx->r4 = S32(U32(ctx->r4) >> 2);
    // 0x80023828: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x8002382C: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x80023830: slt         $v0, $a2, $a3
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80023834: bne         $v0, $zero, L_800237D8
    if (ctx->r2 != 0) {
        // 0x80023838: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800237D8;
    }
    // 0x80023838: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8002383C:
    // 0x8002383C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80023840:
    // 0x80023840: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x80023844: jr          $ra
    // 0x80023848: nop

    return;
    // 0x80023848: nop

;}
RECOMP_FUNC void func_8002384C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002384C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80023850: lw          $v0, -0x7104($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7104);
    // 0x80023854: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80023858: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8002385C: sll         $a3, $a3, 24
    ctx->r7 = S32(ctx->r7 << 24);
    // 0x80023860: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80023864: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80023868: bgez        $a3, L_800238DC
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8002386C: andi        $v0, $a1, 0xFF
        ctx->r2 = ctx->r5 & 0XFF;
            goto L_800238DC;
    }
    // 0x8002386C: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x80023870: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x80023874: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80023878: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8002387C: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
    // 0x80023880: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x80023884: addiu       $a3, $v0, 0x1
    ctx->r7 = ADD32(ctx->r2, 0X1);
    // 0x80023888: andi        $a1, $a3, 0xFFFF
    ctx->r5 = ctx->r7 & 0XFFFF;
    // 0x8002388C: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x80023890: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80023894: slt         $v0, $a1, $v1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80023898: beq         $v0, $zero, L_800238CC
    if (ctx->r2 == 0) {
        // 0x8002389C: andi        $v0, $a3, 0xFFFF
        ctx->r2 = ctx->r7 & 0XFFFF;
            goto L_800238CC;
    }
    // 0x8002389C: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x800238A0: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x800238A4: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
L_800238A8:
    // 0x800238A8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800238AC: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x800238B0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800238B4: andi        $a1, $a3, 0xFFFF
    ctx->r5 = ctx->r7 & 0XFFFF;
    // 0x800238B8: sh          $v1, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r3;
    // 0x800238BC: slt         $v0, $a1, $a2
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800238C0: bne         $v0, $zero, L_800238A8
    if (ctx->r2 != 0) {
        // 0x800238C4: sll         $v0, $a1, 1
        ctx->r2 = S32(ctx->r5 << 1);
            goto L_800238A8;
    }
    // 0x800238C4: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x800238C8: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
L_800238CC:
    // 0x800238CC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800238D0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800238D4: j           L_80023948
    // 0x800238D8: sh          $t0, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r8;
        goto L_80023948;
    // 0x800238D8: sh          $t0, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r8;
L_800238DC:
    // 0x800238DC: andi        $v1, $a2, 0xFF
    ctx->r3 = ctx->r6 & 0XFF;
    // 0x800238E0: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // 0x800238E4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800238E8: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    // 0x800238EC: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x800238F0: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800238F4: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800238F8: lhu         $t0, 0x0($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X0);
    // 0x800238FC: andi        $a1, $a3, 0xFFFF
    ctx->r5 = ctx->r7 & 0XFFFF;
    // 0x80023900: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80023904: sltu        $v0, $v1, $a1
    ctx->r2 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x80023908: beq         $v0, $zero, L_8002393C
    if (ctx->r2 == 0) {
        // 0x8002390C: andi        $v0, $a3, 0xFFFF
        ctx->r2 = ctx->r7 & 0XFFFF;
            goto L_8002393C;
    }
    // 0x8002390C: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x80023910: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x80023914: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
L_80023918:
    // 0x80023918: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8002391C: lhu         $v1, -0x2($v0)
    ctx->r3 = MEM_HU(ctx->r2, -0X2);
    // 0x80023920: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x80023924: andi        $a1, $a3, 0xFFFF
    ctx->r5 = ctx->r7 & 0XFFFF;
    // 0x80023928: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x8002392C: sltu        $v0, $a2, $a1
    ctx->r2 = ctx->r6 < ctx->r5 ? 1 : 0;
    // 0x80023930: bnel        $v0, $zero, L_80023918
    if (ctx->r2 != 0) {
        // 0x80023934: sll         $v0, $a1, 1
        ctx->r2 = S32(ctx->r5 << 1);
            goto L_80023918;
    }
    goto skip_0;
    // 0x80023934: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    skip_0:
    // 0x80023938: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
L_8002393C:
    // 0x8002393C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80023940: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80023944: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
L_80023948:
    // 0x80023948: jr          $ra
    // 0x8002394C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8002394C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
