#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_800F34DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F34DC: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x800F34E0: sw          $s1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r17;
    // 0x800F34E4: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800F34E8: sw          $s5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r21;
    // 0x800F34EC: sw          $ra, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r31;
    // 0x800F34F0: sw          $s4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r20;
    // 0x800F34F4: sw          $s3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r19;
    // 0x800F34F8: sw          $s2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r18;
    // 0x800F34FC: sw          $s0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r16;
    // 0x800F3500: sdc1        $f22, 0xB8($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XB8, ctx->r29);
    // 0x800F3504: sdc1        $f20, 0xB0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XB0, ctx->r29);
    // 0x800F3508: lwc1        $f0, 0x60($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X60);
    // 0x800F350C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800F3510: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x800F3514: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x800F3518: nop

    // 0x800F351C: bc1f        L_800F354C
    if (!c1cs) {
        // 0x800F3520: addu        $s5, $a2, $zero
        ctx->r21 = ADD32(ctx->r6, 0);
            goto L_800F354C;
    }
    // 0x800F3520: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x800F3524: lwc1        $f0, 0x64($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X64);
    // 0x800F3528: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x800F352C: nop

    // 0x800F3530: bc1f        L_800F3550
    if (!c1cs) {
        // 0x800F3534: nop
    
            goto L_800F3550;
    }
    // 0x800F3534: nop

    // 0x800F3538: lwc1        $f0, 0x68($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X68);
    // 0x800F353C: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x800F3540: nop

    // 0x800F3544: bc1t        L_800F3C6C
    if (c1cs) {
        // 0x800F3548: addiu       $a0, $s1, 0xBC
        ctx->r4 = ADD32(ctx->r17, 0XBC);
            goto L_800F3C6C;
    }
    // 0x800F3548: addiu       $a0, $s1, 0xBC
    ctx->r4 = ADD32(ctx->r17, 0XBC);
L_800F354C:
    // 0x800F354C: lwc1        $f0, 0x64($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X64);
L_800F3550:
    // 0x800F3550: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800F3554: mov.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
    // 0x800F3558: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800F355C: nop

    // 0x800F3560: bc1f        L_800F356C
    if (!c1cs) {
        // 0x800F3564: nop
    
            goto L_800F356C;
    }
    // 0x800F3564: nop

    // 0x800F3568: lwc1        $f4, 0x60($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X60);
L_800F356C:
    // 0x800F356C: lwc1        $f8, 0x68($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X68);
    // 0x800F3570: c.eq.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl == ctx->f4.fl;
    // 0x800F3574: nop

    // 0x800F3578: bc1t        L_800F3630
    if (c1cs) {
        // 0x800F357C: nop
    
            goto L_800F3630;
    }
    // 0x800F357C: nop

    // 0x800F3580: lwc1        $f0, 0x6C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x800F3584: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x800F3588: nop

    // 0x800F358C: bc1f        L_800F35C4
    if (!c1cs) {
        // 0x800F3590: nop
    
            goto L_800F35C4;
    }
    // 0x800F3590: nop

    // 0x800F3594: lwc1        $f2, 0x70($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X70);
    // 0x800F3598: c.eq.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl == ctx->f6.fl;
    // 0x800F359C: nop

    // 0x800F35A0: bc1t        L_800F35B8
    if (c1cs) {
        // 0x800F35A4: nop
    
            goto L_800F35B8;
    }
    // 0x800F35A4: nop

    // 0x800F35A8: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800F35AC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800F35B0: j           L_800F35C0
    // 0x800F35B4: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
        goto L_800F35C0;
    // 0x800F35B4: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
L_800F35B8:
    // 0x800F35B8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F35BC: lwc1        $f0, -0x75C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X75C0);
L_800F35C0:
    // 0x800F35C0: swc1        $f0, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f0.u32l;
L_800F35C4:
    // 0x800F35C4: lwc1        $f0, 0x68($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X68);
    // 0x800F35C8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800F35CC: nop

    // 0x800F35D0: bc1f        L_800F35FC
    if (!c1cs) {
        // 0x800F35D4: nop
    
            goto L_800F35FC;
    }
    // 0x800F35D4: nop

    // 0x800F35D8: lwc1        $f2, 0x6C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x800F35DC: mul.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x800F35E0: add.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F35E4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F35E8: lwc1        $f0, -0x75BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X75BC);
    // 0x800F35EC: sub.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800F35F0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800F35F4: j           L_800F361C
    // 0x800F35F8: swc1        $f2, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->f2.u32l;
        goto L_800F361C;
    // 0x800F35F8: swc1        $f2, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->f2.u32l;
L_800F35FC:
    // 0x800F35FC: lwc1        $f2, 0x6C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x800F3600: mul.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x800F3604: sub.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F3608: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F360C: lwc1        $f0, -0x75B8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X75B8);
    // 0x800F3610: add.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800F3614: swc1        $f2, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->f2.u32l;
    // 0x800F3618: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_800F361C:
    // 0x800F361C: nop

    // 0x800F3620: bc1f        L_800F3630
    if (!c1cs) {
        // 0x800F3624: nop
    
            goto L_800F3630;
    }
    // 0x800F3624: nop

    // 0x800F3628: swc1        $f4, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->f4.u32l;
    // 0x800F362C: sw          $zero, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = 0;
L_800F3630:
    // 0x800F3630: lwc1        $f0, 0x88($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X88);
    // 0x800F3634: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x800F3638: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800F363C: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x800F3640: nop

    // 0x800F3644: bc1f        L_800F36FC
    if (!c1cs) {
        // 0x800F3648: swc1        $f0, 0x88($s1)
        MEM_W(0X88, ctx->r17) = ctx->f0.u32l;
            goto L_800F36FC;
    }
    // 0x800F3648: swc1        $f0, 0x88($s1)
    MEM_W(0X88, ctx->r17) = ctx->f0.u32l;
    // 0x800F364C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F3650: lwc1        $f0, -0x75B4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X75B4);
    // 0x800F3654: jal         0x80003430
    // 0x800F3658: swc1        $f0, 0x88($s1)
    MEM_W(0X88, ctx->r17) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_0;
    // 0x800F3658: swc1        $f0, 0x88($s1)
    MEM_W(0X88, ctx->r17) = ctx->f0.u32l;
    after_0:
    // 0x800F365C: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800F3660: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F3664: lwc1        $f2, -0x75B0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X75B0);
    // 0x800F3668: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F366C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F3670: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F3674: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F3678: lwc1        $f2, -0x75AC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X75AC);
    // 0x800F367C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F3680: lwc1        $f4, -0x75A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X75A8);
    // 0x800F3684: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F3688: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x800F368C: lwc1        $f0, 0x90($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X90);
    // 0x800F3690: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800F3694: nop

    // 0x800F3698: bc1f        L_800F36C0
    if (!c1cs) {
        // 0x800F369C: add.s       $f2, $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
            goto L_800F36C0;
    }
    // 0x800F369C: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800F36A0: lwc1        $f0, 0x84($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X84);
    // 0x800F36A4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F36A8: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800F36AC: nop

    // 0x800F36B0: bc1f        L_800F36E4
    if (!c1cs) {
        // 0x800F36B4: swc1        $f0, 0x84($s1)
        MEM_W(0X84, ctx->r17) = ctx->f0.u32l;
            goto L_800F36E4;
    }
    // 0x800F36B4: swc1        $f0, 0x84($s1)
    MEM_W(0X84, ctx->r17) = ctx->f0.u32l;
    // 0x800F36B8: j           L_800F36E4
    // 0x800F36BC: swc1        $f20, 0x84($s1)
    MEM_W(0X84, ctx->r17) = ctx->f20.u32l;
        goto L_800F36E4;
    // 0x800F36BC: swc1        $f20, 0x84($s1)
    MEM_W(0X84, ctx->r17) = ctx->f20.u32l;
L_800F36C0:
    // 0x800F36C0: lwc1        $f0, 0x84($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X84);
    // 0x800F36C4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F36C8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F36CC: lwc1        $f2, -0x75A4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X75A4);
    // 0x800F36D0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800F36D4: nop

    // 0x800F36D8: bc1f        L_800F36E4
    if (!c1cs) {
        // 0x800F36DC: swc1        $f0, 0x84($s1)
        MEM_W(0X84, ctx->r17) = ctx->f0.u32l;
            goto L_800F36E4;
    }
    // 0x800F36DC: swc1        $f0, 0x84($s1)
    MEM_W(0X84, ctx->r17) = ctx->f0.u32l;
    // 0x800F36E0: swc1        $f2, 0x84($s1)
    MEM_W(0X84, ctx->r17) = ctx->f2.u32l;
L_800F36E4:
    // 0x800F36E4: lwc1        $f2, 0x80($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X80);
    // 0x800F36E8: lwc1        $f0, 0x84($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X84);
    // 0x800F36EC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F36F0: sw          $zero, 0x8C($s1)
    MEM_W(0X8C, ctx->r17) = 0;
    // 0x800F36F4: swc1        $f2, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->f2.u32l;
    // 0x800F36F8: swc1        $f0, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->f0.u32l;
L_800F36FC:
    // 0x800F36FC: lwc1        $f2, 0x80($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X80);
    // 0x800F3700: lwc1        $f0, 0x84($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X84);
    // 0x800F3704: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x800F3708: nop

    // 0x800F370C: bc1tl       L_800F3794
    if (c1cs) {
        // 0x800F3710: sw          $zero, 0x88($s1)
        MEM_W(0X88, ctx->r17) = 0;
            goto L_800F3794;
    }
    goto skip_0;
    // 0x800F3710: sw          $zero, 0x88($s1)
    MEM_W(0X88, ctx->r17) = 0;
    skip_0:
    // 0x800F3714: lwc1        $f2, 0x48($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X48);
    // 0x800F3718: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F371C: lwc1        $f0, -0x75A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X75A0);
    // 0x800F3720: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F3724: lwc1        $f0, 0x74($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X74);
    // 0x800F3728: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F372C: lwc1        $f2, 0x8C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8C);
    // 0x800F3730: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800F3734: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F3738: lwc1        $f20, -0x759C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X759C);
    // 0x800F373C: c.le.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl <= ctx->f2.fl;
    // 0x800F3740: nop

    // 0x800F3744: bc1f        L_800F375C
    if (!c1cs) {
        // 0x800F3748: swc1        $f2, 0x8C($s1)
        MEM_W(0X8C, ctx->r17) = ctx->f2.u32l;
            goto L_800F375C;
    }
    // 0x800F3748: swc1        $f2, 0x8C($s1)
    MEM_W(0X8C, ctx->r17) = ctx->f2.u32l;
    // 0x800F374C: lwc1        $f0, 0x84($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X84);
    // 0x800F3750: sw          $zero, 0x88($s1)
    MEM_W(0X88, ctx->r17) = 0;
    // 0x800F3754: j           L_800F3794
    // 0x800F3758: swc1        $f0, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->f0.u32l;
        goto L_800F3794;
    // 0x800F3758: swc1        $f0, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->f0.u32l;
L_800F375C:
    // 0x800F375C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F3760: lwc1        $f12, -0x7598($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7598);
    // 0x800F3764: mul.s       $f12, $f2, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800F3768: jal         0x8002B190
    // 0x800F376C: nop

    cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x800F376C: nop

    after_1:
    // 0x800F3770: sub.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x800F3774: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F3778: lwc1        $f2, -0x7594($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7594);
    // 0x800F377C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F3780: lwc1        $f2, 0x90($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X90);
    // 0x800F3784: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F3788: lwc1        $f2, 0x94($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X94);
    // 0x800F378C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800F3790: swc1        $f2, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->f2.u32l;
L_800F3794:
    // 0x800F3794: lwc1        $f0, 0xA0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XA0);
    // 0x800F3798: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x800F379C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800F37A0: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x800F37A4: nop

    // 0x800F37A8: bc1f        L_800F38F4
    if (!c1cs) {
        // 0x800F37AC: swc1        $f0, 0xA0($s1)
        MEM_W(0XA0, ctx->r17) = ctx->f0.u32l;
            goto L_800F38F4;
    }
    // 0x800F37AC: swc1        $f0, 0xA0($s1)
    MEM_W(0XA0, ctx->r17) = ctx->f0.u32l;
    // 0x800F37B0: lwc1        $f0, 0xA8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x800F37B4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F37B8: lwc1        $f2, -0x7590($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7590);
    // 0x800F37BC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F37C0: lwc1        $f20, -0x758C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X758C);
    // 0x800F37C4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800F37C8: nop

    // 0x800F37CC: bc1f        L_800F380C
    if (!c1cs) {
        // 0x800F37D0: swc1        $f2, 0xA0($s1)
        MEM_W(0XA0, ctx->r17) = ctx->f2.u32l;
            goto L_800F380C;
    }
    // 0x800F37D0: swc1        $f2, 0xA0($s1)
    MEM_W(0XA0, ctx->r17) = ctx->f2.u32l;
    // 0x800F37D4: jal         0x80003430
    // 0x800F37D8: nop

    rand_recomp(rdram, ctx);
        goto after_2;
    // 0x800F37D8: nop

    after_2:
    // 0x800F37DC: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800F37E0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F37E4: lwc1        $f2, -0x7588($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7588);
    // 0x800F37E8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F37EC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F37F0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F37F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F37F8: lwc1        $f2, -0x7584($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7584);
    // 0x800F37FC: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F3800: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800F3804: j           L_800F3844
    // 0x800F3808: add.s       $f20, $f0, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f0.fl + ctx->f20.fl;
        goto L_800F3844;
    // 0x800F3808: add.s       $f20, $f0, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f0.fl + ctx->f20.fl;
L_800F380C:
    // 0x800F380C: jal         0x80003430
    // 0x800F3810: nop

    rand_recomp(rdram, ctx);
        goto after_3;
    // 0x800F3810: nop

    after_3:
    // 0x800F3814: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800F3818: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F381C: lwc1        $f2, -0x7580($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7580);
    // 0x800F3820: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F3824: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F3828: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F382C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F3830: lwc1        $f2, -0x757C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X757C);
    // 0x800F3834: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F3838: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800F383C: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x800F3840: neg.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = -ctx->f0.fl;
L_800F3844:
    // 0x800F3844: lwc1        $f0, 0x48($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X48);
    // 0x800F3848: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F384C: lwc1        $f2, -0x7578($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7578);
    // 0x800F3850: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F3854: nop

    // 0x800F3858: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800F385C: lwc1        $f12, 0x98($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X98);
    // 0x800F3860: add.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f20.fl;
    // 0x800F3864: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F3868: lwc1        $f22, -0x7574($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X7574);
    // 0x800F386C: add.s       $f12, $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f22.fl;
    // 0x800F3870: jal         0x8001E20C
    // 0x800F3874: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    floatModulo(rdram, ctx);
        goto after_4;
    // 0x800F3874: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_4:
    // 0x800F3878: lwc1        $f12, 0x98($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X98);
    // 0x800F387C: swc1        $f0, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->f0.u32l;
    // 0x800F3880: sw          $zero, 0xA4($s1)
    MEM_W(0XA4, ctx->r17) = 0;
    // 0x800F3884: swc1        $f12, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->f12.u32l;
    // 0x800F3888: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x800F388C: abs.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = fabsf(ctx->f0.fl);
    // 0x800F3890: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F3894: lwc1        $f0, -0x7570($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7570);
    // 0x800F3898: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800F389C: nop

    // 0x800F38A0: bc1tl       L_800F38A8
    if (c1cs) {
        // 0x800F38A4: sub.s       $f20, $f22, $f20
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f22.fl - ctx->f20.fl;
            goto L_800F38A8;
    }
    goto skip_1;
    // 0x800F38A4: sub.s       $f20, $f22, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f22.fl - ctx->f20.fl;
    skip_1:
L_800F38A8:
    // 0x800F38A8: add.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f20.fl;
    // 0x800F38AC: jal         0x8001E20C
    // 0x800F38B0: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    floatModulo(rdram, ctx);
        goto after_5;
    // 0x800F38B0: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_5:
    // 0x800F38B4: lwc1        $f6, 0x9C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x800F38B8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F38BC: lwc1        $f8, -0x756C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X756C);
    // 0x800F38C0: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800F38C4: mov.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
    // 0x800F38C8: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x800F38CC: nop

    // 0x800F38D0: bc1tl       L_800F38F0
    if (c1cs) {
        // 0x800F38D4: neg.s       $f20, $f20
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
            goto L_800F38F0;
    }
    goto skip_2;
    // 0x800F38D4: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    skip_2:
    // 0x800F38D8: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800F38DC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800F38E0: nop

    // 0x800F38E4: bc1fl       L_800F38F4
    if (!c1cs) {
        // 0x800F38E8: swc1        $f20, 0xA8($s1)
        MEM_W(0XA8, ctx->r17) = ctx->f20.u32l;
            goto L_800F38F4;
    }
    goto skip_3;
    // 0x800F38E8: swc1        $f20, 0xA8($s1)
    MEM_W(0XA8, ctx->r17) = ctx->f20.u32l;
    skip_3:
    // 0x800F38EC: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
L_800F38F0:
    // 0x800F38F0: swc1        $f20, 0xA8($s1)
    MEM_W(0XA8, ctx->r17) = ctx->f20.u32l;
L_800F38F4:
    // 0x800F38F4: lwc1        $f2, 0x98($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X98);
    // 0x800F38F8: lwc1        $f0, 0x9C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x800F38FC: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x800F3900: nop

    // 0x800F3904: bc1tl       L_800F3978
    if (c1cs) {
        // 0x800F3908: sw          $zero, 0xA0($s1)
        MEM_W(0XA0, ctx->r17) = 0;
            goto L_800F3978;
    }
    goto skip_4;
    // 0x800F3908: sw          $zero, 0xA0($s1)
    MEM_W(0XA0, ctx->r17) = 0;
    skip_4:
    // 0x800F390C: lwc1        $f2, 0xA4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XA4);
    // 0x800F3910: lwc1        $f0, 0x78($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X78);
    // 0x800F3914: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800F3918: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F391C: lwc1        $f20, -0x7568($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7568);
    // 0x800F3920: c.le.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl <= ctx->f2.fl;
    // 0x800F3924: nop

    // 0x800F3928: bc1f        L_800F3940
    if (!c1cs) {
        // 0x800F392C: swc1        $f2, 0xA4($s1)
        MEM_W(0XA4, ctx->r17) = ctx->f2.u32l;
            goto L_800F3940;
    }
    // 0x800F392C: swc1        $f2, 0xA4($s1)
    MEM_W(0XA4, ctx->r17) = ctx->f2.u32l;
    // 0x800F3930: lwc1        $f0, 0x9C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x800F3934: sw          $zero, 0xA0($s1)
    MEM_W(0XA0, ctx->r17) = 0;
    // 0x800F3938: j           L_800F3978
    // 0x800F393C: swc1        $f0, 0x98($s1)
    MEM_W(0X98, ctx->r17) = ctx->f0.u32l;
        goto L_800F3978;
    // 0x800F393C: swc1        $f0, 0x98($s1)
    MEM_W(0X98, ctx->r17) = ctx->f0.u32l;
L_800F3940:
    // 0x800F3940: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F3944: lwc1        $f12, -0x7564($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7564);
    // 0x800F3948: mul.s       $f12, $f2, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800F394C: jal         0x8002B190
    // 0x800F3950: nop

    cosf_recomp(rdram, ctx);
        goto after_6;
    // 0x800F3950: nop

    after_6:
    // 0x800F3954: sub.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x800F3958: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F395C: lwc1        $f2, -0x7560($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7560);
    // 0x800F3960: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F3964: lwc1        $f2, 0xA8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x800F3968: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F396C: lwc1        $f2, 0xAC($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XAC);
    // 0x800F3970: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800F3974: swc1        $f2, 0x98($s1)
    MEM_W(0X98, ctx->r17) = ctx->f2.u32l;
L_800F3978:
    // 0x800F3978: lwc1        $f12, 0x98($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X98);
    // 0x800F397C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F3980: lwc1        $f14, -0x755C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X755C);
    // 0x800F3984: jal         0x8001E20C
    // 0x800F3988: nop

    floatModulo(rdram, ctx);
        goto after_7;
    // 0x800F3988: nop

    after_7:
    // 0x800F398C: swc1        $f0, 0x98($s1)
    MEM_W(0X98, ctx->r17) = ctx->f0.u32l;
    // 0x800F3990: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x800F3994: lwc1        $f0, 0x80($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X80);
    // 0x800F3998: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F399C: lwc1        $f12, -0x7558($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7558);
    // 0x800F39A0: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800F39A4: jal         0x8002B190
    // 0x800F39A8: nop

    cosf_recomp(rdram, ctx);
        goto after_8;
    // 0x800F39A8: nop

    after_8:
    // 0x800F39AC: lwc1        $f2, 0x68($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X68);
    // 0x800F39B0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F39B4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F39B8: lwc1        $f2, -0x7554($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7554);
    // 0x800F39BC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F39C0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800F39C4: lwc1        $f0, 0x48($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X48);
    // 0x800F39C8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F39CC: lwc1        $f2, 0x7C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X7C);
    // 0x800F39D0: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F39D4: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800F39D8: mul.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F39DC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F39E0: lwc1        $f0, -0x7550($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7550);
    // 0x800F39E4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800F39E8: nop

    // 0x800F39EC: bc1fl       L_800F3A14
    if (!c1cs) {
        // 0x800F39F0: sw          $zero, 0x34($sp)
        MEM_W(0X34, ctx->r29) = 0;
            goto L_800F3A14;
    }
    goto skip_5;
    // 0x800F39F0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    skip_5:
    // 0x800F39F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F39F8: lwc1        $f12, -0x754C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X754C);
    // 0x800F39FC: mul.s       $f12, $f2, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800F3A00: jal         0x8002B190
    // 0x800F3A04: nop

    cosf_recomp(rdram, ctx);
        goto after_9;
    // 0x800F3A04: nop

    after_9:
    // 0x800F3A08: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800F3A0C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F3A10: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
L_800F3A14:
    // 0x800F3A14: lwc1        $f0, 0x48($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X48);
    // 0x800F3A18: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F3A1C: lwc1        $f22, -0x7548($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X7548);
    // 0x800F3A20: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F3A24: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800F3A28: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F3A2C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800F3A30: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x800F3A34: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x800F3A38: lwc1        $f0, 0x98($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X98);
    // 0x800F3A3C: addiu       $s4, $s5, 0xC
    ctx->r20 = ADD32(ctx->r21, 0XC);
    // 0x800F3A40: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F3A44: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800F3A48: jal         0x8001D240
    // 0x800F3A4C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    quatFromAxisAngle(rdram, ctx);
        goto after_10;
    // 0x800F3A4C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_10:
    // 0x800F3A50: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800F3A54: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x800F3A58: jal         0x8001D3C4
    // 0x800F3A5C: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    rotateVec3ByQuat(rdram, ctx);
        goto after_11;
    // 0x800F3A5C: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_11:
    // 0x800F3A60: lwc1        $f0, 0x0($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800F3A64: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F3A68: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F3A6C: swc1        $f0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f0.u32l;
    // 0x800F3A70: lwc1        $f0, 0x4($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X4);
    // 0x800F3A74: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F3A78: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F3A7C: swc1        $f0, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->f0.u32l;
    // 0x800F3A80: lwc1        $f0, 0x8($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X8);
    // 0x800F3A84: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F3A88: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F3A8C: lwc1        $f6, 0x24($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X24);
    // 0x800F3A90: swc1        $f0, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->f0.u32l;
    // 0x800F3A94: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F3A98: add.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800F3A9C: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F3AA0: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x800F3AA4: lwc1        $f4, 0x28($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X28);
    // 0x800F3AA8: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800F3AAC: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F3AB0: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x800F3AB4: lwc1        $f2, 0x2C($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X2C);
    // 0x800F3AB8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800F3ABC: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    // 0x800F3AC0: lwc1        $f0, 0xB0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XB0);
    // 0x800F3AC4: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800F3AC8: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x800F3ACC: lwc1        $f0, 0xB4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XB4);
    // 0x800F3AD0: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800F3AD4: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x800F3AD8: lwc1        $f0, 0xB8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XB8);
    // 0x800F3ADC: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800F3AE0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F3AE4: lwc1        $f20, -0x7544($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7544);
    // 0x800F3AE8: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x800F3AEC: swc1        $f6, 0xB0($s1)
    MEM_W(0XB0, ctx->r17) = ctx->f6.u32l;
    // 0x800F3AF0: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800F3AF4: addiu       $s2, $sp, 0x50
    ctx->r18 = ADD32(ctx->r29, 0X50);
    // 0x800F3AF8: swc1        $f0, 0xB4($s1)
    MEM_W(0XB4, ctx->r17) = ctx->f0.u32l;
    // 0x800F3AFC: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800F3B00: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F3B04: jal         0x8001CF2C
    // 0x800F3B08: swc1        $f0, 0xB8($s1)
    MEM_W(0XB8, ctx->r17) = ctx->f0.u32l;
    vec3Length(rdram, ctx);
        goto after_12;
    // 0x800F3B08: swc1        $f0, 0xB8($s1)
    MEM_W(0XB8, ctx->r17) = ctx->f0.u32l;
    after_12:
    // 0x800F3B0C: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800F3B10: nop

    // 0x800F3B14: bc1f        L_800F3C84
    if (!c1cs) {
        // 0x800F3B18: addiu       $s3, $sp, 0x40
        ctx->r19 = ADD32(ctx->r29, 0X40);
            goto L_800F3C84;
    }
    // 0x800F3B18: addiu       $s3, $sp, 0x40
    ctx->r19 = ADD32(ctx->r29, 0X40);
    // 0x800F3B1C: jal         0x8001CF2C
    // 0x800F3B20: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    vec3Length(rdram, ctx);
        goto after_13;
    // 0x800F3B20: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_13:
    // 0x800F3B24: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800F3B28: nop

    // 0x800F3B2C: bc1f        L_800F3C84
    if (!c1cs) {
        // 0x800F3B30: nop
    
            goto L_800F3C84;
    }
    // 0x800F3B30: nop

    // 0x800F3B34: jal         0x8001CF58
    // 0x800F3B38: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    normalize_vector(rdram, ctx);
        goto after_14;
    // 0x800F3B38: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_14:
    // 0x800F3B3C: jal         0x8001CF58
    // 0x800F3B40: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    normalize_vector(rdram, ctx);
        goto after_15;
    // 0x800F3B40: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_15:
    // 0x800F3B44: addiu       $s0, $sp, 0x60
    ctx->r16 = ADD32(ctx->r29, 0X60);
    // 0x800F3B48: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F3B4C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800F3B50: jal         0x80019548
    // 0x800F3B54: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    vec3Cross(rdram, ctx);
        goto after_16;
    // 0x800F3B54: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_16:
    // 0x800F3B58: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F3B5C: jal         0x8001CFE8
    // 0x800F3B60: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    vec3Dot(rdram, ctx);
        goto after_17;
    // 0x800F3B60: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_17:
    // 0x800F3B64: jal         0x8001C5CC
    // 0x800F3B68: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    constMinusSinfApprox(rdram, ctx);
        goto after_18;
    // 0x800F3B68: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_18:
    // 0x800F3B6C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F3B70: lwc1        $f2, -0x7540($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7540);
    // 0x800F3B74: mul.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F3B78: lwc1        $f0, 0x48($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X48);
    // 0x800F3B7C: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F3B80: nop

    // 0x800F3B84: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800F3B88: addiu       $s2, $sp, 0x70
    ctx->r18 = ADD32(ctx->r29, 0X70);
    // 0x800F3B8C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F3B90: neg.s       $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = -ctx->f20.fl;
    // 0x800F3B94: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800F3B98: jal         0x8001D240
    // 0x800F3B9C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    quatFromAxisAngle(rdram, ctx);
        goto after_19;
    // 0x800F3B9C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_19:
    // 0x800F3BA0: lwc1        $f0, 0xCC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XCC);
    // 0x800F3BA4: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800F3BA8: nop

    // 0x800F3BAC: bc1f        L_800F3BE8
    if (!c1cs) {
        // 0x800F3BB0: addiu       $a0, $s1, 0xBC
        ctx->r4 = ADD32(ctx->r17, 0XBC);
            goto L_800F3BE8;
    }
    // 0x800F3BB0: addiu       $a0, $s1, 0xBC
    ctx->r4 = ADD32(ctx->r17, 0XBC);
    // 0x800F3BB4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800F3BB8: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800F3BBC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800F3BC0: jal         0x8001D850
    // 0x800F3BC4: addiu       $a3, $sp, 0x80
    ctx->r7 = ADD32(ctx->r29, 0X80);
    func_8001D850(rdram, ctx);
        goto after_20;
    // 0x800F3BC4: addiu       $a3, $sp, 0x80
    ctx->r7 = ADD32(ctx->r29, 0X80);
    after_20:
    // 0x800F3BC8: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x800F3BCC: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x800F3BD0: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x800F3BD4: lw          $t2, 0x8C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8C);
    // 0x800F3BD8: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    // 0x800F3BDC: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    // 0x800F3BE0: sw          $t1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r9;
    // 0x800F3BE4: sw          $t2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r10;
L_800F3BE8:
    // 0x800F3BE8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F3BEC: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x800F3BF0: lw          $v1, 0x70($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X70);
    // 0x800F3BF4: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x800F3BF8: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x800F3BFC: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x800F3C00: sw          $v1, 0xBC($s1)
    MEM_W(0XBC, ctx->r17) = ctx->r3;
    // 0x800F3C04: sw          $t0, 0xC0($s1)
    MEM_W(0XC0, ctx->r17) = ctx->r8;
    // 0x800F3C08: sw          $t1, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->r9;
    // 0x800F3C0C: sw          $t2, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->r10;
    // 0x800F3C10: jal         0x8001D3C4
    // 0x800F3C14: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_21;
    // 0x800F3C14: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_21:
    // 0x800F3C18: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F3C1C: addiu       $a1, $s5, 0x18
    ctx->r5 = ADD32(ctx->r21, 0X18);
    // 0x800F3C20: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800F3C24: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800F3C28: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800F3C2C: sw          $v1, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r3;
    // 0x800F3C30: sw          $t0, 0x10($s5)
    MEM_W(0X10, ctx->r21) = ctx->r8;
    // 0x800F3C34: sw          $t1, 0x14($s5)
    MEM_W(0X14, ctx->r21) = ctx->r9;
    // 0x800F3C38: jal         0x8001D3C4
    // 0x800F3C3C: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_22;
    // 0x800F3C3C: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_22:
    // 0x800F3C40: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800F3C44: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800F3C48: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800F3C4C: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800F3C50: sw          $v1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r3;
    // 0x800F3C54: sw          $t0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r8;
    // 0x800F3C58: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x800F3C5C: jal         0x80059F10
    // 0x800F3C60: nop

    orthonormalizeFrame(rdram, ctx);
        goto after_23;
    // 0x800F3C60: nop

    after_23:
    // 0x800F3C64: j           L_800F3C84
    // 0x800F3C68: nop

        goto L_800F3C84;
    // 0x800F3C68: nop

L_800F3C6C:
    // 0x800F3C6C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800F3C70: jal         0x8001D038
    // 0x800F3C74: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    quatFromCardinalAxis(rdram, ctx);
        goto after_24;
    // 0x800F3C74: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_24:
    // 0x800F3C78: swc1        $f20, 0xB0($s1)
    MEM_W(0XB0, ctx->r17) = ctx->f20.u32l;
    // 0x800F3C7C: swc1        $f20, 0xB4($s1)
    MEM_W(0XB4, ctx->r17) = ctx->f20.u32l;
    // 0x800F3C80: swc1        $f20, 0xB8($s1)
    MEM_W(0XB8, ctx->r17) = ctx->f20.u32l;
L_800F3C84:
    // 0x800F3C84: lw          $ra, 0xA8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA8);
    // 0x800F3C88: lw          $s5, 0xA4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XA4);
    // 0x800F3C8C: lw          $s4, 0xA0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XA0);
    // 0x800F3C90: lw          $s3, 0x9C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X9C);
    // 0x800F3C94: lw          $s2, 0x98($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X98);
    // 0x800F3C98: lw          $s1, 0x94($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X94);
    // 0x800F3C9C: lw          $s0, 0x90($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X90);
    // 0x800F3CA0: ldc1        $f22, 0xB8($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XB8);
    // 0x800F3CA4: ldc1        $f20, 0xB0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XB0);
    // 0x800F3CA8: jr          $ra
    // 0x800F3CAC: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x800F3CAC: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void func_800F3CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F3CB0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800F3CB4: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800F3CB8: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800F3CBC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800F3CC0: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x800F3CC4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800F3CC8: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800F3CCC: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x800F3CD0: beq         $a1, $zero, L_800F3D0C
    if (ctx->r5 == 0) {
        // 0x800F3CD4: addu        $s1, $s0, $zero
        ctx->r17 = ADD32(ctx->r16, 0);
            goto L_800F3D0C;
    }
    // 0x800F3CD4: addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
    // 0x800F3CD8: slti        $v0, $a1, 0x81
    ctx->r2 = SIGNED(ctx->r5) < 0X81 ? 1 : 0;
    // 0x800F3CDC: beq         $v0, $zero, L_800F3CF8
    if (ctx->r2 == 0) {
        // 0x800F3CE0: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800F3CF8;
    }
    // 0x800F3CE0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800F3CE4: addiu       $v0, $v0, -0x7760
    ctx->r2 = ADD32(ctx->r2, -0X7760);
    // 0x800F3CE8: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800F3CEC: lbu         $v0, -0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X1);
    // 0x800F3CF0: j           L_800F3D00
    // 0x800F3CF4: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
        goto L_800F3D00;
    // 0x800F3CF4: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
L_800F3CF8:
    // 0x800F3CF8: jal         0x800F3258
    // 0x800F3CFC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    returnZero_800F3258(rdram, ctx);
        goto after_0;
    // 0x800F3CFC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_0:
L_800F3D00:
    // 0x800F3D00: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800F3D04: beq         $v0, $zero, L_800F40F4
    if (ctx->r2 == 0) {
        // 0x800F3D08: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F40F4;
    }
    // 0x800F3D08: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F3D0C:
    // 0x800F3D0C: lw          $v0, 0x2C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X2C);
    // 0x800F3D10: beq         $v0, $zero, L_800F3D3C
    if (ctx->r2 == 0) {
        // 0x800F3D14: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_800F3D3C;
    }
    // 0x800F3D14: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800F3D18: addiu       $v1, $v1, -0x7FA0
    ctx->r3 = ADD32(ctx->r3, -0X7FA0);
    // 0x800F3D1C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800F3D20: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800F3D24: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800F3D28: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800F3D2C: lw          $v1, 0x30($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X30);
    // 0x800F3D30: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800F3D34: bne         $v0, $zero, L_800F40F4
    if (ctx->r2 != 0) {
        // 0x800F3D38: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F40F4;
    }
    // 0x800F3D38: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F3D3C:
    // 0x800F3D3C: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
    // 0x800F3D40: beq         $a0, $zero, L_800F3D58
    if (ctx->r4 == 0) {
        // 0x800F3D44: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800F3D58;
    }
    // 0x800F3D44: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800F3D48: addiu       $v0, $v0, -0x7760
    ctx->r2 = ADD32(ctx->r2, -0X7760);
    // 0x800F3D4C: lbu         $v1, 0x43($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X43);
    // 0x800F3D50: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800F3D54: sb          $v1, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r3;
L_800F3D58:
    // 0x800F3D58: lw          $v1, 0x34($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X34);
    // 0x800F3D5C: beq         $v1, $zero, L_800F3D84
    if (ctx->r3 == 0) {
        // 0x800F3D60: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800F3D84;
    }
    // 0x800F3D60: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800F3D64: addiu       $v0, $v0, -0x7FA0
    ctx->r2 = ADD32(ctx->r2, -0X7FA0);
    // 0x800F3D68: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F3D6C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800F3D70: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800F3D74: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800F3D78: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800F3D7C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800F3D80: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800F3D84:
    // 0x800F3D84: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x800F3D88: addiu       $v1, $v0, -0x1A
    ctx->r3 = ADD32(ctx->r2, -0X1A);
    // 0x800F3D8C: sltiu       $v0, $v1, 0x35
    ctx->r2 = ctx->r3 < 0X35 ? 1 : 0;
    // 0x800F3D90: beq         $v0, $zero, L_800F40F0
    if (ctx->r2 == 0) {
        // 0x800F3D94: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_800F40F0;
    }
    // 0x800F3D94: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800F3D98: addiu       $v0, $v0, -0x7538
    ctx->r2 = ADD32(ctx->r2, -0X7538);
    // 0x800F3D9C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800F3DA0: addu        $v1, $v1, $v0
    gpr jr_addend_800F3DA8 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800F3DA4: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800F3DA8: jr          $v0
    // 0x800F3DAC: nop

    switch (jr_addend_800F3DA8 >> 2) {
        case 0: goto L_800F3DB0; break;
        case 1: goto L_800F3DF0; break;
        case 2: goto L_800F3EB4; break;
        case 3: goto L_800F3F10; break;
        case 4: goto L_800F40F0; break;
        case 5: goto L_800F40F0; break;
        case 6: goto L_800F3F2C; break;
        case 7: goto L_800F40F0; break;
        case 8: goto L_800F3F90; break;
        case 9: goto L_800F4080; break;
        case 10: goto L_800F40F0; break;
        case 11: goto L_800F40F0; break;
        case 12: goto L_800F40F0; break;
        case 13: goto L_800F40F0; break;
        case 14: goto L_800F40F0; break;
        case 15: goto L_800F40F0; break;
        case 16: goto L_800F40F0; break;
        case 17: goto L_800F40F0; break;
        case 18: goto L_800F40F0; break;
        case 19: goto L_800F40F0; break;
        case 20: goto L_800F40F0; break;
        case 21: goto L_800F40F0; break;
        case 22: goto L_800F40F0; break;
        case 23: goto L_800F40F0; break;
        case 24: goto L_800F40F0; break;
        case 25: goto L_800F40F0; break;
        case 26: goto L_800F40F0; break;
        case 27: goto L_800F40F0; break;
        case 28: goto L_800F40F0; break;
        case 29: goto L_800F40F0; break;
        case 30: goto L_800F40F0; break;
        case 31: goto L_800F40F0; break;
        case 32: goto L_800F40F0; break;
        case 33: goto L_800F40F0; break;
        case 34: goto L_800F40F0; break;
        case 35: goto L_800F40F0; break;
        case 36: goto L_800F40F0; break;
        case 37: goto L_800F40F0; break;
        case 38: goto L_800F40F0; break;
        case 39: goto L_800F40F0; break;
        case 40: goto L_800F40F0; break;
        case 41: goto L_800F40F0; break;
        case 42: goto L_800F40F0; break;
        case 43: goto L_800F40F0; break;
        case 44: goto L_800F40F0; break;
        case 45: goto L_800F40F0; break;
        case 46: goto L_800F40F0; break;
        case 47: goto L_800F40F0; break;
        case 48: goto L_800F40F0; break;
        case 49: goto L_800F40F0; break;
        case 50: goto L_800F40F0; break;
        case 51: goto L_800F40F0; break;
        case 52: goto L_800F40CC; break;
        default: switch_error(__func__, 0x800F3DA8, 0x800A8AC8);
    }
    // 0x800F3DAC: nop

L_800F3DB0:
    // 0x800F3DB0: sb          $zero, 0x28($sp)
    MEM_B(0X28, ctx->r29) = 0;
    // 0x800F3DB4: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x800F3DB8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800F3DBC: lwc1        $f0, 0x48($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800F3DC0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800F3DC4: lwc1        $f0, 0x4C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x800F3DC8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800F3DCC: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800F3DD0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800F3DD4: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800F3DD8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800F3DDC: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800F3DE0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x800F3DE4: lhu         $a0, 0x198($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X198);
    // 0x800F3DE8: j           L_800F4070
    // 0x800F3DEC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
        goto L_800F4070;
    // 0x800F3DEC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
L_800F3DF0:
    // 0x800F3DF0: lhu         $v0, 0x110($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X110);
    // 0x800F3DF4: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x800F3DF8: bne         $v0, $zero, L_800F40F0
    if (ctx->r2 != 0) {
        // 0x800F3DFC: addu        $v1, $s0, $zero
        ctx->r3 = ADD32(ctx->r16, 0);
            goto L_800F40F0;
    }
    // 0x800F3DFC: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x800F3E00: lw          $v0, 0x48($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X48);
    // 0x800F3E04: beq         $v0, $zero, L_800F3E20
    if (ctx->r2 == 0) {
        // 0x800F3E08: addiu       $a0, $s2, 0x8
        ctx->r4 = ADD32(ctx->r18, 0X8);
            goto L_800F3E20;
    }
    // 0x800F3E08: addiu       $a0, $s2, 0x8
    ctx->r4 = ADD32(ctx->r18, 0X8);
    // 0x800F3E0C: lwc1        $f0, 0x48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800F3E10: lwc1        $f2, 0x44($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800F3E14: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F3E18: j           L_800F3E28
    // 0x800F3E1C: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
        goto L_800F3E28;
    // 0x800F3E1C: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
L_800F3E20:
    // 0x800F3E20: lwc1        $f0, 0x44($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800F3E24: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
L_800F3E28:
    // 0x800F3E28: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800F3E2C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800F3E30: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x800F3E34: nop

    // 0x800F3E38: bc1f        L_800F3E50
    if (!c1cs) {
        // 0x800F3E3C: nop
    
            goto L_800F3E50;
    }
    // 0x800F3E3C: nop

    // 0x800F3E40: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F3E44: lwc1        $f0, -0x7464($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7464);
    // 0x800F3E48: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    // 0x800F3E4C: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
L_800F3E50:
    // 0x800F3E50: lwc1        $f2, 0x48($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800F3E54: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F3E58: swc1        $f2, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f2.u32l;
    // 0x800F3E5C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800F3E60: nop

    // 0x800F3E64: bc1t        L_800F40F0
    if (c1cs) {
        // 0x800F3E68: swc1        $f0, 0x54($a0)
        MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
            goto L_800F40F0;
    }
    // 0x800F3E68: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    // 0x800F3E6C: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    // 0x800F3E70: lwc1        $f2, 0x4C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4C);
    // 0x800F3E74: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x800F3E78: nop

    // 0x800F3E7C: bc1f        L_800F3E98
    if (!c1cs) {
        // 0x800F3E80: nop
    
            goto L_800F3E98;
    }
    // 0x800F3E80: nop

    // 0x800F3E84: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F3E88: lwc1        $f0, -0x7460($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7460);
    // 0x800F3E8C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F3E90: j           L_800F40F0
    // 0x800F3E94: swc1        $f0, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f0.u32l;
        goto L_800F40F0;
    // 0x800F3E94: swc1        $f0, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f0.u32l;
L_800F3E98:
    // 0x800F3E98: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800F3E9C: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x800F3EA0: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    // 0x800F3EA4: lwc1        $f2, 0x24($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800F3EA8: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F3EAC: j           L_800F40F0
    // 0x800F3EB0: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
        goto L_800F40F0;
    // 0x800F3EB0: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
L_800F3EB4:
    // 0x800F3EB4: lhu         $v0, 0x110($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X110);
    // 0x800F3EB8: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x800F3EBC: bne         $v0, $zero, L_800F40F4
    if (ctx->r2 != 0) {
        // 0x800F3EC0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F40F4;
    }
    // 0x800F3EC0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F3EC4: lw          $v0, 0x48($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X48);
    // 0x800F3EC8: bne         $v0, $zero, L_800F3EE8
    if (ctx->r2 != 0) {
        // 0x800F3ECC: addu        $v1, $s0, $zero
        ctx->r3 = ADD32(ctx->r16, 0);
            goto L_800F3EE8;
    }
    // 0x800F3ECC: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x800F3ED0: lwc1        $f0, 0x44($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800F3ED4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F3ED8: lwc1        $f2, -0x745C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X745C);
    // 0x800F3EDC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F3EE0: j           L_800F3F04
    // 0x800F3EE4: swc1        $f0, 0x68($s2)
    MEM_W(0X68, ctx->r18) = ctx->f0.u32l;
        goto L_800F3F04;
    // 0x800F3EE4: swc1        $f0, 0x68($s2)
    MEM_W(0X68, ctx->r18) = ctx->f0.u32l;
L_800F3EE8:
    // 0x800F3EE8: lwc1        $f0, 0x44($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800F3EEC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F3EF0: lwc1        $f2, -0x7458($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7458);
    // 0x800F3EF4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F3EF8: lwc1        $f2, 0x68($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X68);
    // 0x800F3EFC: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F3F00: swc1        $f2, 0x68($s2)
    MEM_W(0X68, ctx->r18) = ctx->f2.u32l;
L_800F3F04:
    // 0x800F3F04: lwc1        $f0, 0x4C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4C);
    // 0x800F3F08: j           L_800F40F0
    // 0x800F3F0C: swc1        $f0, 0x78($s2)
    MEM_W(0X78, ctx->r18) = ctx->f0.u32l;
        goto L_800F40F0;
    // 0x800F3F0C: swc1        $f0, 0x78($s2)
    MEM_W(0X78, ctx->r18) = ctx->f0.u32l;
L_800F3F10:
    // 0x800F3F10: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x800F3F14: beq         $v0, $zero, L_800F3F20
    if (ctx->r2 == 0) {
        // 0x800F3F18: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F3F20;
    }
    // 0x800F3F18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F3F1C: sb          $v0, 0x1A5($s2)
    MEM_B(0X1A5, ctx->r18) = ctx->r2;
L_800F3F20:
    // 0x800F3F20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F3F24: j           L_800F40F0
    // 0x800F3F28: sb          $v0, 0x1A6($s2)
    MEM_B(0X1A6, ctx->r18) = ctx->r2;
        goto L_800F40F0;
    // 0x800F3F28: sb          $v0, 0x1A6($s2)
    MEM_B(0X1A6, ctx->r18) = ctx->r2;
L_800F3F2C:
    // 0x800F3F2C: lbu         $v0, 0x47($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X47);
    // 0x800F3F30: sb          $v0, 0x12C($s2)
    MEM_B(0X12C, ctx->r18) = ctx->r2;
    // 0x800F3F34: lbu         $v0, 0x4B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4B);
    // 0x800F3F38: sb          $v0, 0x12D($s2)
    MEM_B(0X12D, ctx->r18) = ctx->r2;
    // 0x800F3F3C: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    // 0x800F3F40: jal         0x800F2FC0
    // 0x800F3F44: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    setEffectIntensity(rdram, ctx);
        goto after_1;
    // 0x800F3F44: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_1:
    // 0x800F3F48: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800F3F4C: addu        $a0, $v0, $s0
    ctx->r4 = ADD32(ctx->r2, ctx->r16);
    // 0x800F3F50: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800F3F54: beq         $v1, $zero, L_800F3F64
    if (ctx->r3 == 0) {
        // 0x800F3F58: addiu       $v0, $zero, 0x2D
        ctx->r2 = ADD32(0, 0X2D);
            goto L_800F3F64;
    }
    // 0x800F3F58: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
    // 0x800F3F5C: bnel        $v1, $v0, L_800F3F68
    if (ctx->r3 != ctx->r2) {
        // 0x800F3F60: sw          $a0, 0x128($s2)
        MEM_W(0X128, ctx->r18) = ctx->r4;
            goto L_800F3F68;
    }
    goto skip_0;
    // 0x800F3F60: sw          $a0, 0x128($s2)
    MEM_W(0X128, ctx->r18) = ctx->r4;
    skip_0:
L_800F3F64:
    // 0x800F3F64: sw          $zero, 0x128($s2)
    MEM_W(0X128, ctx->r18) = 0;
L_800F3F68:
    // 0x800F3F68: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800F3F6C: sw          $zero, 0x124($s2)
    MEM_W(0X124, ctx->r18) = 0;
    // 0x800F3F70: sb          $v0, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r2;
    // 0x800F3F74: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x800F3F78: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800F3F7C: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800F3F80: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800F3F84: lhu         $a0, 0x198($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X198);
    // 0x800F3F88: j           L_800F4070
    // 0x800F3F8C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
        goto L_800F4070;
    // 0x800F3F8C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
L_800F3F90:
    // 0x800F3F90: lhu         $v0, 0x110($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X110);
    // 0x800F3F94: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x800F3F98: bne         $v0, $zero, L_800F40F4
    if (ctx->r2 != 0) {
        // 0x800F3F9C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F40F4;
    }
    // 0x800F3F9C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F3FA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F3FA4: sb          $v0, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r2;
    // 0x800F3FA8: lwc1        $f0, 0x44($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800F3FAC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800F3FB0: lw          $v1, 0x48($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X48);
    // 0x800F3FB4: beq         $v1, $zero, L_800F3FE4
    if (ctx->r3 == 0) {
        // 0x800F3FB8: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800F3FE4;
    }
    // 0x800F3FB8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F3FBC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800F3FC0: addiu       $v0, $v0, -0x7760
    ctx->r2 = ADD32(ctx->r2, -0X7760);
    // 0x800F3FC4: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800F3FC8: lbu         $v1, -0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X1);
    // 0x800F3FCC: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800F3FD0: bne         $v1, $v0, L_800F3FE4
    if (ctx->r3 != ctx->r2) {
        // 0x800F3FD4: nop
    
            goto L_800F3FE4;
    }
    // 0x800F3FD4: nop

    // 0x800F3FD8: sb          $zero, 0x19($sp)
    MEM_B(0X19, ctx->r29) = 0;
    // 0x800F3FDC: j           L_800F3FF4
    // 0x800F3FE0: sb          $zero, 0x1A($sp)
    MEM_B(0X1A, ctx->r29) = 0;
        goto L_800F3FF4;
    // 0x800F3FE0: sb          $zero, 0x1A($sp)
    MEM_B(0X1A, ctx->r29) = 0;
L_800F3FE4:
    // 0x800F3FE4: lbu         $v0, 0x4B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4B);
    // 0x800F3FE8: sb          $v0, 0x19($sp)
    MEM_B(0X19, ctx->r29) = ctx->r2;
    // 0x800F3FEC: lbu         $v0, 0x4F($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4F);
    // 0x800F3FF0: sb          $v0, 0x1A($sp)
    MEM_B(0X1A, ctx->r29) = ctx->r2;
L_800F3FF4:
    // 0x800F3FF4: lw          $v0, 0x50($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X50);
    // 0x800F3FF8: beq         $v0, $zero, L_800F4030
    if (ctx->r2 == 0) {
        // 0x800F3FFC: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_800F4030;
    }
    // 0x800F3FFC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800F4000: addiu       $v1, $v1, -0x7FA0
    ctx->r3 = ADD32(ctx->r3, -0X7FA0);
    // 0x800F4004: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800F4008: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800F400C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800F4010: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800F4014: lw          $v1, 0x54($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X54);
    // 0x800F4018: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800F401C: bne         $v0, $zero, L_800F4030
    if (ctx->r2 != 0) {
        // 0x800F4020: nop
    
            goto L_800F4030;
    }
    // 0x800F4020: nop

    // 0x800F4024: sb          $zero, 0x18($sp)
    MEM_B(0X18, ctx->r29) = 0;
    // 0x800F4028: j           L_800F4040
    // 0x800F402C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
        goto L_800F4040;
    // 0x800F402C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
L_800F4030:
    // 0x800F4030: lbu         $v0, 0x53($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X53);
    // 0x800F4034: sb          $v0, 0x18($sp)
    MEM_B(0X18, ctx->r29) = ctx->r2;
    // 0x800F4038: lw          $v0, 0x54($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X54);
    // 0x800F403C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
L_800F4040:
    // 0x800F4040: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F4044: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F4048: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x800F404C: nop

    // 0x800F4050: bc1f        L_800F4068
    if (!c1cs) {
        // 0x800F4054: lui         $v1, 0xFFFF
        ctx->r3 = S32(0XFFFF << 16);
            goto L_800F4068;
    }
    // 0x800F4054: lui         $v1, 0xFFFF
    ctx->r3 = S32(0XFFFF << 16);
    // 0x800F4058: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800F405C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800F4060: beq         $v0, $zero, L_800F40F4
    if (ctx->r2 == 0) {
        // 0x800F4064: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F40F4;
    }
    // 0x800F4064: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F4068:
    // 0x800F4068: lhu         $a0, 0x198($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X198);
    // 0x800F406C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
L_800F4070:
    // 0x800F4070: jal         0x8003E8DC
    // 0x800F4074: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    slotDispatcherIter(rdram, ctx);
        goto after_2;
    // 0x800F4074: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_2:
    // 0x800F4078: j           L_800F40F4
    // 0x800F407C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800F40F4;
    // 0x800F407C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F4080:
    // 0x800F4080: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x800F4084: beq         $v0, $zero, L_800F40A8
    if (ctx->r2 == 0) {
        // 0x800F4088: nop
    
            goto L_800F40A8;
    }
    // 0x800F4088: nop

    // 0x800F408C: lwc1        $f2, 0x48($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800F4090: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F4094: lwc1        $f0, -0x7454($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7454);
    // 0x800F4098: sw          $zero, 0x100($s2)
    MEM_W(0X100, ctx->r18) = 0;
    // 0x800F409C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F40A0: j           L_800F40F0
    // 0x800F40A4: swc1        $f0, 0xFC($s2)
    MEM_W(0XFC, ctx->r18) = ctx->f0.u32l;
        goto L_800F40F0;
    // 0x800F40A4: swc1        $f0, 0xFC($s2)
    MEM_W(0XFC, ctx->r18) = ctx->f0.u32l;
L_800F40A8:
    // 0x800F40A8: lwc1        $f0, 0x48($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800F40AC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F40B0: lwc1        $f2, -0x7450($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7450);
    // 0x800F40B4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F40B8: lwc1        $f4, -0x744C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X744C);
    // 0x800F40BC: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F40C0: swc1        $f2, 0xFC($s2)
    MEM_W(0XFC, ctx->r18) = ctx->f2.u32l;
    // 0x800F40C4: j           L_800F40F0
    // 0x800F40C8: swc1        $f4, 0x100($s2)
    MEM_W(0X100, ctx->r18) = ctx->f4.u32l;
        goto L_800F40F0;
    // 0x800F40C8: swc1        $f4, 0x100($s2)
    MEM_W(0X100, ctx->r18) = ctx->f4.u32l;
L_800F40CC:
    // 0x800F40CC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800F40D0: addiu       $v1, $a0, -0x3B80
    ctx->r3 = ADD32(ctx->r4, -0X3B80);
    // 0x800F40D4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800F40D8: sb          $v0, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r2;
    // 0x800F40DC: lw          $v1, 0x44($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X44);
    // 0x800F40E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F40E4: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x800F40E8: j           L_800F40F4
    // 0x800F40EC: sw          $v1, -0x3B80($a0)
    MEM_W(-0X3B80, ctx->r4) = ctx->r3;
        goto L_800F40F4;
    // 0x800F40EC: sw          $v1, -0x3B80($a0)
    MEM_W(-0X3B80, ctx->r4) = ctx->r3;
L_800F40F0:
    // 0x800F40F0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F40F4:
    // 0x800F40F4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800F40F8: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800F40FC: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800F4100: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800F4104: jr          $ra
    // 0x800F4108: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800F4108: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void executeActorType1Effect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F410C: addiu       $sp, $sp, -0x1A8
    ctx->r29 = ADD32(ctx->r29, -0X1A8);
    // 0x800F4110: sw          $s7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r23;
    // 0x800F4114: addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // 0x800F4118: sw          $fp, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->r30;
    // 0x800F411C: addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // 0x800F4120: sw          $s5, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r21;
    // 0x800F4124: sw          $ra, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r31;
    // 0x800F4128: sw          $s6, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r22;
    // 0x800F412C: sw          $s4, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r20;
    // 0x800F4130: sw          $s3, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r19;
    // 0x800F4134: sw          $s2, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r18;
    // 0x800F4138: sw          $s1, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r17;
    // 0x800F413C: sw          $s0, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r16;
    // 0x800F4140: sdc1        $f22, 0x1A0($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X1A0, ctx->r29);
    // 0x800F4144: sdc1        $f20, 0x198($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X198, ctx->r29);
    // 0x800F4148: lhu         $a0, 0x198($s7)
    ctx->r4 = MEM_HU(ctx->r23, 0X198);
    // 0x800F414C: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x800F4150: jal         0x8004015C
    // 0x800F4154: addiu       $s5, $s7, 0x8
    ctx->r21 = ADD32(ctx->r23, 0X8);
    getNpcContextField8(rdram, ctx);
        goto after_0;
    // 0x800F4154: addiu       $s5, $s7, 0x8
    ctx->r21 = ADD32(ctx->r23, 0X8);
    after_0:
    // 0x800F4158: lw          $t0, 0xD8($s7)
    ctx->r8 = MEM_W(ctx->r23, 0XD8);
    // 0x800F415C: lw          $t1, 0xDC($s7)
    ctx->r9 = MEM_W(ctx->r23, 0XDC);
    // 0x800F4160: lw          $t2, 0xE0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0XE0);
    // 0x800F4164: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x800F4168: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x800F416C: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x800F4170: lwc1        $f0, 0x104($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X104);
    // 0x800F4174: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800F4178: addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    // 0x800F417C: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800F4180: nop

    // 0x800F4184: bc1f        L_800F41A4
    if (!c1cs) {
        // 0x800F4188: sb          $zero, 0x168($sp)
        MEM_B(0X168, ctx->r29) = 0;
            goto L_800F41A4;
    }
    // 0x800F4188: sb          $zero, 0x168($sp)
    MEM_B(0X168, ctx->r29) = 0;
    // 0x800F418C: lui         $v1, 0xFF00
    ctx->r3 = S32(0XFF00 << 16);
    // 0x800F4190: lw          $v0, 0xFC($s5)
    ctx->r2 = MEM_W(ctx->r21, 0XFC);
    // 0x800F4194: ori         $v1, $v1, 0xFF00
    ctx->r3 = ctx->r3 | 0XFF00;
    // 0x800F4198: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800F419C: beq         $v0, $zero, L_800F4258
    if (ctx->r2 == 0) {
        // 0x800F41A0: nop
    
            goto L_800F4258;
    }
    // 0x800F41A0: nop

L_800F41A4:
    // 0x800F41A4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800F41A8: nop

    // 0x800F41AC: bc1f        L_800F41CC
    if (!c1cs) {
        // 0x800F41B0: nop
    
            goto L_800F41CC;
    }
    // 0x800F41B0: nop

    // 0x800F41B4: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x800F41B8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800F41BC: nop

    // 0x800F41C0: bc1t        L_800F4224
    if (c1cs) {
        // 0x800F41C4: swc1        $f0, 0x104($s5)
        MEM_W(0X104, ctx->r21) = ctx->f0.u32l;
            goto L_800F4224;
    }
    // 0x800F41C4: swc1        $f0, 0x104($s5)
    MEM_W(0X104, ctx->r21) = ctx->f0.u32l;
    // 0x800F41C8: swc1        $f2, 0x104($s5)
    MEM_W(0X104, ctx->r21) = ctx->f2.u32l;
L_800F41CC:
    // 0x800F41CC: lbu         $v0, 0xFC($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0XFC);
    // 0x800F41D0: beq         $v0, $zero, L_800F41F4
    if (ctx->r2 == 0) {
        // 0x800F41D4: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800F41F4;
    }
    // 0x800F41D4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800F41D8: lbu         $v1, 0xFC($s5)
    ctx->r3 = MEM_BU(ctx->r21, 0XFC);
    // 0x800F41DC: addiu       $v0, $v0, -0x7760
    ctx->r2 = ADD32(ctx->r2, -0X7760);
    // 0x800F41E0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800F41E4: lbu         $v1, -0x1($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X1);
    // 0x800F41E8: lbu         $v0, 0xFD($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0XFD);
    // 0x800F41EC: bnel        $v1, $v0, L_800F4480
    if (ctx->r3 != ctx->r2) {
        // 0x800F41F0: addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
            goto L_800F4480;
    }
    goto skip_0;
    // 0x800F41F0: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    skip_0:
L_800F41F4:
    // 0x800F41F4: lbu         $v0, 0xFE($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0XFE);
    // 0x800F41F8: beq         $v0, $zero, L_800F422C
    if (ctx->r2 == 0) {
        // 0x800F41FC: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_800F422C;
    }
    // 0x800F41FC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800F4200: addiu       $v1, $v1, -0x7FA0
    ctx->r3 = ADD32(ctx->r3, -0X7FA0);
    // 0x800F4204: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800F4208: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800F420C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800F4210: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800F4214: lw          $v1, 0x100($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X100);
    // 0x800F4218: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800F421C: beq         $v0, $zero, L_800F422C
    if (ctx->r2 == 0) {
        // 0x800F4220: nop
    
            goto L_800F422C;
    }
    // 0x800F4220: nop

L_800F4224:
    // 0x800F4224: j           L_800F4480
    // 0x800F4228: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
        goto L_800F4480;
    // 0x800F4228: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
L_800F422C:
    // 0x800F422C: lhu         $v0, 0x110($s7)
    ctx->r2 = MEM_HU(ctx->r23, 0X110);
    // 0x800F4230: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800F4234: beq         $v0, $zero, L_800F4258
    if (ctx->r2 == 0) {
        // 0x800F4238: addiu       $a1, $zero, 0x9
        ctx->r5 = ADD32(0, 0X9);
            goto L_800F4258;
    }
    // 0x800F4238: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800F423C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800F4240: sb          $zero, 0xFE($s5)
    MEM_B(0XFE, ctx->r21) = 0;
    // 0x800F4244: sb          $zero, 0xFC($s5)
    MEM_B(0XFC, ctx->r21) = 0;
    // 0x800F4248: sb          $v0, 0x78($sp)
    MEM_B(0X78, ctx->r29) = ctx->r2;
    // 0x800F424C: lhu         $a0, 0x198($s7)
    ctx->r4 = MEM_HU(ctx->r23, 0X198);
    // 0x800F4250: jal         0x8003E8DC
    // 0x800F4254: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    slotDispatcherIter(rdram, ctx);
        goto after_1;
    // 0x800F4254: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    after_1:
L_800F4258:
    // 0x800F4258: lwc1        $f2, 0x48($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X48);
    // 0x800F425C: lwc1        $f0, 0x50($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X50);
    // 0x800F4260: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x800F4264: nop

    // 0x800F4268: bc1t        L_800F4318
    if (c1cs) {
        // 0x800F426C: nop
    
            goto L_800F4318;
    }
    // 0x800F426C: nop

    // 0x800F4270: lwc1        $f0, 0x5C($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X5C);
    // 0x800F4274: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F4278: lwc1        $f2, 0x58($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X58);
    // 0x800F427C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800F4280: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F4284: lwc1        $f0, -0x743C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X743C);
    // 0x800F4288: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800F428C: nop

    // 0x800F4290: bc1f        L_800F42A4
    if (!c1cs) {
        // 0x800F4294: swc1        $f2, 0x58($s5)
        MEM_W(0X58, ctx->r21) = ctx->f2.u32l;
            goto L_800F42A4;
    }
    // 0x800F4294: swc1        $f2, 0x58($s5)
    MEM_W(0X58, ctx->r21) = ctx->f2.u32l;
    // 0x800F4298: lwc1        $f0, 0x50($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X50);
    // 0x800F429C: j           L_800F42D8
    // 0x800F42A0: swc1        $f0, 0x48($s5)
    MEM_W(0X48, ctx->r21) = ctx->f0.u32l;
        goto L_800F42D8;
    // 0x800F42A0: swc1        $f0, 0x48($s5)
    MEM_W(0X48, ctx->r21) = ctx->f0.u32l;
L_800F42A4:
    // 0x800F42A4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F42A8: lwc1        $f12, -0x7438($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7438);
    // 0x800F42AC: mul.s       $f12, $f2, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800F42B0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F42B4: lwc1        $f0, -0x7434($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7434);
    // 0x800F42B8: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800F42BC: jal         0x80033960
    // 0x800F42C0: nop

    sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x800F42C0: nop

    after_2:
    // 0x800F42C4: lwc1        $f2, 0x54($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X54);
    // 0x800F42C8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F42CC: lwc1        $f2, 0x4C($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X4C);
    // 0x800F42D0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800F42D4: swc1        $f2, 0x48($s5)
    MEM_W(0X48, ctx->r21) = ctx->f2.u32l;
L_800F42D8:
    // 0x800F42D8: lw          $v0, 0x24($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X24);
    // 0x800F42DC: lwc1        $f0, 0x48($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X48);
    // 0x800F42E0: lwc1        $f2, 0x24($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800F42E4: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F42E8: swc1        $f0, 0x2C($s5)
    MEM_W(0X2C, ctx->r21) = ctx->f0.u32l;
    // 0x800F42EC: lhu         $v0, 0x110($s7)
    ctx->r2 = MEM_HU(ctx->r23, 0X110);
    // 0x800F42F0: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800F42F4: beq         $v0, $zero, L_800F4318
    if (ctx->r2 == 0) {
        // 0x800F42F8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800F4318;
    }
    // 0x800F42F8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800F42FC: sb          $v0, 0x78($sp)
    MEM_B(0X78, ctx->r29) = ctx->r2;
    // 0x800F4300: lwc1        $f0, 0x48($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X48);
    // 0x800F4304: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800F4308: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x800F430C: lhu         $a0, 0x198($s7)
    ctx->r4 = MEM_HU(ctx->r23, 0X198);
    // 0x800F4310: jal         0x8003E8DC
    // 0x800F4314: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    slotDispatcherIter(rdram, ctx);
        goto after_3;
    // 0x800F4314: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    after_3:
L_800F4318:
    // 0x800F4318: lwc1        $f0, 0x2C($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X2C);
    // 0x800F431C: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F4320: lwc1        $f2, 0x30($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X30);
    // 0x800F4324: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800F4328: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F432C: lwc1        $f20, -0x7430($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7430);
    // 0x800F4330: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x800F4334: nop

    // 0x800F4338: bc1f        L_800F4480
    if (!c1cs) {
        // 0x800F433C: swc1        $f2, 0x30($s5)
        MEM_W(0X30, ctx->r21) = ctx->f2.u32l;
            goto L_800F4480;
    }
    // 0x800F433C: swc1        $f2, 0x30($s5)
    MEM_W(0X30, ctx->r21) = ctx->f2.u32l;
    // 0x800F4340: lw          $v0, 0x34($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X34);
    // 0x800F4344: lw          $a1, 0x24($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X24);
    // 0x800F4348: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800F434C: sw          $v0, 0x34($s5)
    MEM_W(0X34, ctx->r21) = ctx->r2;
    // 0x800F4350: lw          $v1, 0x40($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X40);
    // 0x800F4354: beq         $v1, $zero, L_800F437C
    if (ctx->r3 == 0) {
        // 0x800F4358: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800F437C;
    }
    // 0x800F4358: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800F435C: addiu       $v0, $v0, -0x7FA0
    ctx->r2 = ADD32(ctx->r2, -0X7FA0);
    // 0x800F4360: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F4364: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800F4368: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800F436C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800F4370: lw          $a0, 0x44($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X44);
    // 0x800F4374: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800F4378: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800F437C:
    // 0x800F437C: lw          $a0, 0x48($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X48);
    // 0x800F4380: beq         $a0, $zero, L_800F4398
    if (ctx->r4 == 0) {
        // 0x800F4384: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800F4398;
    }
    // 0x800F4384: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800F4388: addiu       $v0, $v0, -0x7760
    ctx->r2 = ADD32(ctx->r2, -0X7760);
    // 0x800F438C: lbu         $v1, 0x4F($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X4F);
    // 0x800F4390: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800F4394: sb          $v1, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r3;
L_800F4398:
    // 0x800F4398: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x800F439C: jal         0x800F3290
    // 0x800F43A0: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    func_800F3290(rdram, ctx);
        goto after_4;
    // 0x800F43A0: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_4:
    // 0x800F43A4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800F43A8: bne         $v0, $zero, L_800F43BC
    if (ctx->r2 != 0) {
        // 0x800F43AC: addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
            goto L_800F43BC;
    }
    // 0x800F43AC: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800F43B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F43B4: j           L_800F4E38
    // 0x800F43B8: sb          $v0, 0x1A4($s7)
    MEM_B(0X1A4, ctx->r23) = ctx->r2;
        goto L_800F4E38;
    // 0x800F43B8: sb          $v0, 0x1A4($s7)
    MEM_B(0X1A4, ctx->r23) = ctx->r2;
L_800F43BC:
    // 0x800F43BC: lwc1        $f0, 0x30($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X30);
    // 0x800F43C0: lw          $v0, 0x28($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X28);
    // 0x800F43C4: lwc1        $f2, 0x48($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X48);
    // 0x800F43C8: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800F43CC: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800F43D0: lwc1        $f6, 0x2C($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X2C);
    // 0x800F43D4: div.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800F43D8: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800F43DC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F43E0: lwc1        $f20, 0x14($s5)
    ctx->f20.u32l = MEM_W(ctx->r21, 0X14);
    // 0x800F43E4: swc1        $f0, 0x30($s5)
    MEM_W(0X30, ctx->r21) = ctx->f0.u32l;
    // 0x800F43E8: lwc1        $f2, 0x24($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800F43EC: lwc1        $f0, 0x48($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X48);
    // 0x800F43F0: sw          $v0, 0x24($s5)
    MEM_W(0X24, ctx->r21) = ctx->r2;
    // 0x800F43F4: lw          $v1, 0x24($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X24);
    // 0x800F43F8: lw          $a1, 0x24($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X24);
    // 0x800F43FC: addiu       $a2, $s5, 0xD0
    ctx->r6 = ADD32(ctx->r21, 0XD0);
    // 0x800F4400: sw          $zero, 0x28($s5)
    MEM_W(0X28, ctx->r21) = 0;
    // 0x800F4404: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F4408: swc1        $f0, 0x2C($s5)
    MEM_W(0X2C, ctx->r21) = ctx->f0.u32l;
    // 0x800F440C: lw          $v0, 0x1C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1C);
    // 0x800F4410: addiu       $a3, $s5, 0xC
    ctx->r7 = ADD32(ctx->r21, 0XC);
    // 0x800F4414: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
    // 0x800F4418: lw          $v1, 0x20($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X20);
    // 0x800F441C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800F4420: sw          $v1, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r3;
    // 0x800F4424: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x800F4428: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800F442C: lw          $v0, 0x24($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X24);
    // 0x800F4430: lwc1        $f0, 0x30($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X30);
    // 0x800F4434: lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X20);
    // 0x800F4438: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800F443C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800F4440: sw          $v0, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->r2;
    // 0x800F4444: jal         0x800662A0
    // 0x800F4448: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    setupActorAnchorTransformType1(rdram, ctx);
        goto after_5;
    // 0x800F4448: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x800F444C: lw          $v1, 0x24($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X24);
    // 0x800F4450: swc1        $f20, 0x14($s5)
    MEM_W(0X14, ctx->r21) = ctx->f20.u32l;
    // 0x800F4454: sw          $zero, 0x3C($s5)
    MEM_W(0X3C, ctx->r21) = 0;
    // 0x800F4458: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
    // 0x800F445C: beq         $v0, $zero, L_800F4474
    if (ctx->r2 == 0) {
        // 0x800F4460: nop
    
            goto L_800F4474;
    }
    // 0x800F4460: nop

    // 0x800F4464: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x800F4468: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800F446C: j           L_800F4480
    // 0x800F4470: swc1        $f0, 0x40($s5)
    MEM_W(0X40, ctx->r21) = ctx->f0.u32l;
        goto L_800F4480;
    // 0x800F4470: swc1        $f0, 0x40($s5)
    MEM_W(0X40, ctx->r21) = ctx->f0.u32l;
L_800F4474:
    // 0x800F4474: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F4478: lwc1        $f0, -0x742C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X742C);
    // 0x800F447C: swc1        $f0, 0x40($s5)
    MEM_W(0X40, ctx->r21) = ctx->f0.u32l;
L_800F4480:
    // 0x800F4480: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800F4484: addiu       $a2, $s5, 0xD0
    ctx->r6 = ADD32(ctx->r21, 0XD0);
    // 0x800F4488: lw          $a1, 0x24($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X24);
    // 0x800F448C: lwc1        $f0, 0x44($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X44);
    // 0x800F4490: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F4494: lwc1        $f2, -0x7428($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7428);
    // 0x800F4498: addiu       $a3, $s5, 0xC
    ctx->r7 = ADD32(ctx->r21, 0XC);
    // 0x800F449C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800F44A0: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800F44A4: lwc1        $f0, 0x30($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X30);
    // 0x800F44A8: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800F44AC: jal         0x80065A60
    // 0x800F44B0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    buildPositionAndCallTransformHelper(rdram, ctx);
        goto after_6;
    // 0x800F44B0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x800F44B4: lwc1        $f0, 0xD0($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0XD0);
    // 0x800F44B8: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800F44BC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F44C0: div.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F44C4: swc1        $f0, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->f0.u32l;
    // 0x800F44C8: lwc1        $f0, 0xD4($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0XD4);
    // 0x800F44CC: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800F44D0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F44D4: div.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F44D8: swc1        $f0, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->f0.u32l;
    // 0x800F44DC: lwc1        $f0, 0xD8($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0XD8);
    // 0x800F44E0: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800F44E4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F44E8: div.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F44EC: swc1        $f0, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = ctx->f0.u32l;
    // 0x800F44F0: lw          $a1, 0x14($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X14);
    // 0x800F44F4: jal         0x8001CE9C
    // 0x800F44F8: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    buildRotationMatrixSlot2(rdram, ctx);
        goto after_7;
    // 0x800F44F8: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_7:
    // 0x800F44FC: lw          $a1, 0xC($s5)
    ctx->r5 = MEM_W(ctx->r21, 0XC);
    // 0x800F4500: jal         0x8001CB9C
    // 0x800F4504: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    composeRotationMatrixSlot0(rdram, ctx);
        goto after_8;
    // 0x800F4504: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_8:
    // 0x800F4508: lw          $a1, 0x10($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X10);
    // 0x800F450C: jal         0x8001CCCC
    // 0x800F4510: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    composeRotationMatrixSlot1(rdram, ctx);
        goto after_9;
    // 0x800F4510: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_9:
    // 0x800F4514: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F4518: swc1        $f0, 0x18($s6)
    MEM_W(0X18, ctx->r22) = ctx->f0.u32l;
    // 0x800F451C: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800F4520: swc1        $f0, 0x1C($s6)
    MEM_W(0X1C, ctx->r22) = ctx->f0.u32l;
    // 0x800F4524: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800F4528: swc1        $f0, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->f0.u32l;
    // 0x800F452C: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F4530: swc1        $f0, 0xC($s6)
    MEM_W(0XC, ctx->r22) = ctx->f0.u32l;
    // 0x800F4534: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800F4538: swc1        $f0, 0x10($s6)
    MEM_W(0X10, ctx->r22) = ctx->f0.u32l;
    // 0x800F453C: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800F4540: swc1        $f0, 0x14($s6)
    MEM_W(0X14, ctx->r22) = ctx->f0.u32l;
    // 0x800F4544: lhu         $v0, 0x110($s7)
    ctx->r2 = MEM_HU(ctx->r23, 0X110);
    // 0x800F4548: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x800F454C: beq         $v0, $zero, L_800F4648
    if (ctx->r2 == 0) {
        // 0x800F4550: addiu       $s4, $s6, 0x18
        ctx->r20 = ADD32(ctx->r22, 0X18);
            goto L_800F4648;
    }
    // 0x800F4550: addiu       $s4, $s6, 0x18
    ctx->r20 = ADD32(ctx->r22, 0X18);
    // 0x800F4554: addiu       $s2, $sp, 0x90
    ctx->r18 = ADD32(ctx->r29, 0X90);
    // 0x800F4558: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F455C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x800F4560: addiu       $s3, $s6, 0xC
    ctx->r19 = ADD32(ctx->r22, 0XC);
    // 0x800F4564: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800F4568: addiu       $t3, $v0, -0x7448
    ctx->r11 = ADD32(ctx->r2, -0X7448);
    // 0x800F456C: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800F4570: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x800F4574: lw          $t2, 0x8($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X8);
    // 0x800F4578: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    // 0x800F457C: sw          $t1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r9;
    // 0x800F4580: sw          $t2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r10;
    // 0x800F4584: jal         0x80019548
    // 0x800F4588: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    vec3Cross(rdram, ctx);
        goto after_10;
    // 0x800F4588: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_10:
    // 0x800F458C: addiu       $s0, $sp, 0xA0
    ctx->r16 = ADD32(ctx->r29, 0XA0);
    // 0x800F4590: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F4594: addiu       $s1, $sp, 0x80
    ctx->r17 = ADD32(ctx->r29, 0X80);
    // 0x800F4598: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800F459C: jal         0x80019548
    // 0x800F45A0: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    vec3Cross(rdram, ctx);
        goto after_11;
    // 0x800F45A0: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_11:
    // 0x800F45A4: jal         0x8001CF58
    // 0x800F45A8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    normalize_vector(rdram, ctx);
        goto after_12;
    // 0x800F45A8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_12:
    // 0x800F45AC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F45B0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800F45B4: jal         0x80019548
    // 0x800F45B8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    vec3Cross(rdram, ctx);
        goto after_13;
    // 0x800F45B8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_13:
    // 0x800F45BC: jal         0x8001CF58
    // 0x800F45C0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    normalize_vector(rdram, ctx);
        goto after_14;
    // 0x800F45C0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_14:
    // 0x800F45C4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800F45C8: jal         0x8001CFE8
    // 0x800F45CC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    vec3Dot(rdram, ctx);
        goto after_15;
    // 0x800F45CC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_15:
    // 0x800F45D0: jal         0x8001C400
    // 0x800F45D4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    sinfApprox(rdram, ctx);
        goto after_16;
    // 0x800F45D4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_16:
    // 0x800F45D8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F45DC: lwc1        $f2, -0x7424($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7424);
    // 0x800F45E0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F45E4: addiu       $s0, $sp, 0xB0
    ctx->r16 = ADD32(ctx->r29, 0XB0);
    // 0x800F45E8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F45EC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800F45F0: jal         0x8001D240
    // 0x800F45F4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    quatFromAxisAngle(rdram, ctx);
        goto after_17;
    // 0x800F45F4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_17:
    // 0x800F45F8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F45FC: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x800F4600: jal         0x8001D3C4
    // 0x800F4604: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_18;
    // 0x800F4604: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_18:
    // 0x800F4608: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F460C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800F4610: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x800F4614: lw          $t1, 0x84($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X84);
    // 0x800F4618: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x800F461C: sw          $t0, 0x18($s6)
    MEM_W(0X18, ctx->r22) = ctx->r8;
    // 0x800F4620: sw          $t1, 0x1C($s6)
    MEM_W(0X1C, ctx->r22) = ctx->r9;
    // 0x800F4624: sw          $t2, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r10;
    // 0x800F4628: jal         0x8001D3C4
    // 0x800F462C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_19;
    // 0x800F462C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_19:
    // 0x800F4630: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x800F4634: lw          $t1, 0x84($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X84);
    // 0x800F4638: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x800F463C: sw          $t0, 0xC($s6)
    MEM_W(0XC, ctx->r22) = ctx->r8;
    // 0x800F4640: sw          $t1, 0x10($s6)
    MEM_W(0X10, ctx->r22) = ctx->r9;
    // 0x800F4644: sw          $t2, 0x14($s6)
    MEM_W(0X14, ctx->r22) = ctx->r10;
L_800F4648:
    // 0x800F4648: lwc1        $f2, 0x30($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X30);
    // 0x800F464C: lwc1        $f0, 0x40($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X40);
    // 0x800F4650: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800F4654: nop

    // 0x800F4658: bc1f        L_800F46F4
    if (!c1cs) {
        // 0x800F465C: nop
    
            goto L_800F46F4;
    }
    // 0x800F465C: nop

    // 0x800F4660: lw          $v1, 0x24($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X24);
    // 0x800F4664: lw          $a0, 0xD8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XD8);
    // 0x800F4668: lw          $v0, 0x3C($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X3C);
    // 0x800F466C: addiu       $a0, $a0, 0xD4
    ctx->r4 = ADD32(ctx->r4, 0XD4);
    // 0x800F4670: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    // 0x800F4674: lw          $v1, 0x2C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2C);
    // 0x800F4678: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800F467C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800F4680: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800F4684: lhu         $v0, 0x6($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6);
    // 0x800F4688: lw          $v1, 0x75D8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X75D8);
    // 0x800F468C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800F4690: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800F4694: lhu         $v0, 0x2($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X2);
    // 0x800F4698: lw          $v1, 0x3C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3C);
    // 0x800F469C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800F46A0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800F46A4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800F46A8: jal         0x800F3CB0
    // 0x800F46AC: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    func_800F3CB0(rdram, ctx);
        goto after_20;
    // 0x800F46AC: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    after_20:
    // 0x800F46B0: lw          $v1, 0x3C($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X3C);
    // 0x800F46B4: lw          $a1, 0x24($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X24);
    // 0x800F46B8: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x800F46BC: sw          $a0, 0x3C($s5)
    MEM_W(0X3C, ctx->r21) = ctx->r4;
    // 0x800F46C0: lw          $v1, 0x28($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X28);
    // 0x800F46C4: slt         $v1, $a0, $v1
    ctx->r3 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800F46C8: beq         $v1, $zero, L_800F46E8
    if (ctx->r3 == 0) {
        // 0x800F46CC: sb          $v0, 0x168($sp)
        MEM_B(0X168, ctx->r29) = ctx->r2;
            goto L_800F46E8;
    }
    // 0x800F46CC: sb          $v0, 0x168($sp)
    MEM_B(0X168, ctx->r29) = ctx->r2;
    // 0x800F46D0: lw          $v0, 0x2C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X2C);
    // 0x800F46D4: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x800F46D8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800F46DC: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800F46E0: j           L_800F46F4
    // 0x800F46E4: swc1        $f0, 0x40($s5)
    MEM_W(0X40, ctx->r21) = ctx->f0.u32l;
        goto L_800F46F4;
    // 0x800F46E4: swc1        $f0, 0x40($s5)
    MEM_W(0X40, ctx->r21) = ctx->f0.u32l;
L_800F46E8:
    // 0x800F46E8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F46EC: lwc1        $f0, -0x7420($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7420);
    // 0x800F46F0: swc1        $f0, 0x40($s5)
    MEM_W(0X40, ctx->r21) = ctx->f0.u32l;
L_800F46F4:
    // 0x800F46F4: lwc1        $f0, 0xDC($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0XDC);
    // 0x800F46F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800F46FC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800F4700: nop

    // 0x800F4704: bc1f        L_800F4784
    if (!c1cs) {
        // 0x800F4708: addiu       $s0, $sp, 0xE0
        ctx->r16 = ADD32(ctx->r29, 0XE0);
            goto L_800F4784;
    }
    // 0x800F4708: addiu       $s0, $sp, 0xE0
    ctx->r16 = ADD32(ctx->r29, 0XE0);
    // 0x800F470C: swc1        $f4, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f4.u32l;
    // 0x800F4710: lwc1        $f2, 0xDC($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0XDC);
    // 0x800F4714: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F4718: lwc1        $f0, -0x741C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X741C);
    // 0x800F471C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F4720: swc1        $f4, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f4.u32l;
    // 0x800F4724: swc1        $f2, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f2.u32l;
    // 0x800F4728: lwc1        $f0, 0xE0($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0XE0);
    // 0x800F472C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F4730: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F4734: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800F4738: jal         0x8001D240
    // 0x800F473C: addiu       $a1, $s6, 0xC
    ctx->r5 = ADD32(ctx->r22, 0XC);
    quatFromAxisAngle(rdram, ctx);
        goto after_21;
    // 0x800F473C: addiu       $a1, $s6, 0xC
    ctx->r5 = ADD32(ctx->r22, 0XC);
    after_21:
    // 0x800F4740: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F4744: addiu       $a1, $sp, 0xD0
    ctx->r5 = ADD32(ctx->r29, 0XD0);
    // 0x800F4748: jal         0x8001D3C4
    // 0x800F474C: addiu       $a2, $sp, 0xC0
    ctx->r6 = ADD32(ctx->r29, 0XC0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_22;
    // 0x800F474C: addiu       $a2, $sp, 0xC0
    ctx->r6 = ADD32(ctx->r29, 0XC0);
    after_22:
    // 0x800F4750: lwc1        $f0, 0xD0($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0XD0);
    // 0x800F4754: lwc1        $f2, 0xC0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x800F4758: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F475C: swc1        $f0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f0.u32l;
    // 0x800F4760: lwc1        $f0, 0xD4($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0XD4);
    // 0x800F4764: lwc1        $f2, 0xC4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x800F4768: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F476C: swc1        $f0, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->f0.u32l;
    // 0x800F4770: lwc1        $f0, 0xD8($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0XD8);
    // 0x800F4774: lwc1        $f2, 0xC8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800F4778: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F477C: j           L_800F479C
    // 0x800F4780: swc1        $f0, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->f0.u32l;
        goto L_800F479C;
    // 0x800F4780: swc1        $f0, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->f0.u32l;
L_800F4784:
    // 0x800F4784: lw          $t0, 0xD0($s5)
    ctx->r8 = MEM_W(ctx->r21, 0XD0);
    // 0x800F4788: lw          $t1, 0xD4($s5)
    ctx->r9 = MEM_W(ctx->r21, 0XD4);
    // 0x800F478C: lw          $t2, 0xD8($s5)
    ctx->r10 = MEM_W(ctx->r21, 0XD8);
    // 0x800F4790: sw          $t0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r8;
    // 0x800F4794: sw          $t1, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->r9;
    // 0x800F4798: sw          $t2, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r10;
L_800F479C:
    // 0x800F479C: lwc1        $f0, 0xE8($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0XE8);
    // 0x800F47A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800F47A4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800F47A8: nop

    // 0x800F47AC: bc1f        L_800F48D8
    if (!c1cs) {
        // 0x800F47B0: andi        $v0, $fp, 0xFF
        ctx->r2 = ctx->r30 & 0XFF;
            goto L_800F48D8;
    }
    // 0x800F47B0: andi        $v0, $fp, 0xFF
    ctx->r2 = ctx->r30 & 0XFF;
    // 0x800F47B4: lwc1        $f0, 0xF0($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0XF0);
    // 0x800F47B8: mul.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800F47BC: lwc1        $f2, 0xEC($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0XEC);
    // 0x800F47C0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800F47C4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F47C8: lwc1        $f20, -0x7418($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7418);
    // 0x800F47CC: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x800F47D0: nop

    // 0x800F47D4: bc1f        L_800F48D0
    if (!c1cs) {
        // 0x800F47D8: swc1        $f2, 0xEC($s5)
        MEM_W(0XEC, ctx->r21) = ctx->f2.u32l;
            goto L_800F48D0;
    }
    // 0x800F47D8: swc1        $f2, 0xEC($s5)
    MEM_W(0XEC, ctx->r21) = ctx->f2.u32l;
    // 0x800F47DC: swc1        $f4, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f4.u32l;
    // 0x800F47E0: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
    // 0x800F47E4: lwc1        $f12, 0xEC($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0XEC);
    // 0x800F47E8: add.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x800F47EC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F47F0: lwc1        $f0, -0x7414($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7414);
    // 0x800F47F4: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800F47F8: jal         0x8002B190
    // 0x800F47FC: nop

    cosf_recomp(rdram, ctx);
        goto after_23;
    // 0x800F47FC: nop

    after_23:
    // 0x800F4800: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x800F4804: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F4808: lwc1        $f2, -0x7410($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7410);
    // 0x800F480C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F4810: sub.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x800F4814: lwc1        $f2, 0xE8($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0XE8);
    // 0x800F4818: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x800F481C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F4820: addiu       $s0, $sp, 0x100
    ctx->r16 = ADD32(ctx->r29, 0X100);
    // 0x800F4824: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F4828: swc1        $f2, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f2.u32l;
    // 0x800F482C: lw          $a2, 0xE4($s5)
    ctx->r6 = MEM_W(ctx->r21, 0XE4);
    // 0x800F4830: jal         0x8001D240
    // 0x800F4834: addiu       $a1, $s6, 0xC
    ctx->r5 = ADD32(ctx->r22, 0XC);
    quatFromAxisAngle(rdram, ctx);
        goto after_24;
    // 0x800F4834: addiu       $a1, $s6, 0xC
    ctx->r5 = ADD32(ctx->r22, 0XC);
    after_24:
    // 0x800F4838: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F483C: addiu       $a1, $sp, 0xF0
    ctx->r5 = ADD32(ctx->r29, 0XF0);
    // 0x800F4840: jal         0x8001D3C4
    // 0x800F4844: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_25;
    // 0x800F4844: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_25:
    // 0x800F4848: lwc1        $f0, 0x0($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800F484C: lwc1        $f2, 0xF0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800F4850: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F4854: swc1        $f0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f0.u32l;
    // 0x800F4858: lwc1        $f0, 0x4($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800F485C: lwc1        $f2, 0xF4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800F4860: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F4864: lwc1        $f14, 0x8($s6)
    ctx->f14.u32l = MEM_W(ctx->r22, 0X8);
    // 0x800F4868: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800F486C: swc1        $f0, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->f0.u32l;
    // 0x800F4870: lwc1        $f0, 0xF8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x800F4874: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x800F4878: add.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x800F487C: lwc1        $f12, 0x0($s6)
    ctx->f12.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800F4880: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800F4884: jal         0x80067D90
    // 0x800F4888: swc1        $f14, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->f14.u32l;
    wrapAngleToCyclicRange(rdram, ctx);
        goto after_26;
    // 0x800F4888: swc1        $f14, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->f14.u32l;
    after_26:
    // 0x800F488C: lwc1        $f2, 0x4($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800F4890: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800F4894: nop

    // 0x800F4898: bc1f        L_800F48D4
    if (!c1cs) {
        // 0x800F489C: addiu       $a1, $zero, 0x5
        ctx->r5 = ADD32(0, 0X5);
            goto L_800F48D4;
    }
    // 0x800F489C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800F48A0: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x800F48A4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800F48A8: sh          $v1, 0x110($sp)
    MEM_H(0X110, ctx->r29) = ctx->r3;
    // 0x800F48AC: sh          $v1, 0x112($sp)
    MEM_H(0X112, ctx->r29) = ctx->r3;
    // 0x800F48B0: sh          $v0, 0x114($sp)
    MEM_H(0X114, ctx->r29) = ctx->r2;
    // 0x800F48B4: sh          $v1, 0x116($sp)
    MEM_H(0X116, ctx->r29) = ctx->r3;
    // 0x800F48B8: sw          $zero, 0x118($sp)
    MEM_W(0X118, ctx->r29) = 0;
    // 0x800F48BC: lhu         $a0, 0x198($s7)
    ctx->r4 = MEM_HU(ctx->r23, 0X198);
    // 0x800F48C0: jal         0x8003E8DC
    // 0x800F48C4: addiu       $a2, $sp, 0x110
    ctx->r6 = ADD32(ctx->r29, 0X110);
    slotDispatcherIter(rdram, ctx);
        goto after_27;
    // 0x800F48C4: addiu       $a2, $sp, 0x110
    ctx->r6 = ADD32(ctx->r29, 0X110);
    after_27:
    // 0x800F48C8: j           L_800F48D8
    // 0x800F48CC: andi        $v0, $fp, 0xFF
    ctx->r2 = ctx->r30 & 0XFF;
        goto L_800F48D8;
    // 0x800F48CC: andi        $v0, $fp, 0xFF
    ctx->r2 = ctx->r30 & 0XFF;
L_800F48D0:
    // 0x800F48D0: swc1        $f4, 0xE8($s5)
    MEM_W(0XE8, ctx->r21) = ctx->f4.u32l;
L_800F48D4:
    // 0x800F48D4: andi        $v0, $fp, 0xFF
    ctx->r2 = ctx->r30 & 0XFF;
L_800F48D8:
    // 0x800F48D8: bne         $v0, $zero, L_800F48F0
    if (ctx->r2 != 0) {
        // 0x800F48DC: addu        $a0, $s7, $zero
        ctx->r4 = ADD32(ctx->r23, 0);
            goto L_800F48F0;
    }
    // 0x800F48DC: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x800F48E0: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x800F48E4: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x800F48E8: jal         0x800F34DC
    // 0x800F48EC: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    func_800F34DC(rdram, ctx);
        goto after_28;
    // 0x800F48EC: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    after_28:
L_800F48F0:
    // 0x800F48F0: lwc1        $f4, 0xF8($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0XF8);
    // 0x800F48F4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800F48F8: c.eq.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl == ctx->f2.fl;
    // 0x800F48FC: nop

    // 0x800F4900: bc1f        L_800F491C
    if (!c1cs) {
        // 0x800F4904: nop
    
            goto L_800F491C;
    }
    // 0x800F4904: nop

    // 0x800F4908: lwc1        $f0, 0xF4($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0XF4);
    // 0x800F490C: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800F4910: nop

    // 0x800F4914: bc1t        L_800F4A80
    if (c1cs) {
        // 0x800F4918: nop
    
            goto L_800F4A80;
    }
    // 0x800F4918: nop

L_800F491C:
    // 0x800F491C: lwc1        $f0, 0xF4($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0XF4);
    // 0x800F4920: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800F4924: nop

    // 0x800F4928: bc1f        L_800F4958
    if (!c1cs) {
        // 0x800F492C: nop
    
            goto L_800F4958;
    }
    // 0x800F492C: nop

    // 0x800F4930: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F4934: add.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800F4938: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F493C: lwc1        $f4, -0x740C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X740C);
    // 0x800F4940: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800F4944: nop

    // 0x800F4948: bc1f        L_800F4988
    if (!c1cs) {
        // 0x800F494C: swc1        $f0, 0xF8($s5)
        MEM_W(0XF8, ctx->r21) = ctx->f0.u32l;
            goto L_800F4988;
    }
    // 0x800F494C: swc1        $f0, 0xF8($s5)
    MEM_W(0XF8, ctx->r21) = ctx->f0.u32l;
    // 0x800F4950: j           L_800F4984
    // 0x800F4954: swc1        $f4, 0xF8($s5)
    MEM_W(0XF8, ctx->r21) = ctx->f4.u32l;
        goto L_800F4984;
    // 0x800F4954: swc1        $f4, 0xF8($s5)
    MEM_W(0XF8, ctx->r21) = ctx->f4.u32l;
L_800F4958:
    // 0x800F4958: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800F495C: nop

    // 0x800F4960: bc1f        L_800F498C
    if (!c1cs) {
        // 0x800F4964: addiu       $s0, $sp, 0xF0
        ctx->r16 = ADD32(ctx->r29, 0XF0);
            goto L_800F498C;
    }
    // 0x800F4964: addiu       $s0, $sp, 0xF0
    ctx->r16 = ADD32(ctx->r29, 0XF0);
    // 0x800F4968: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F496C: add.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800F4970: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800F4974: nop

    // 0x800F4978: bc1f        L_800F498C
    if (!c1cs) {
        // 0x800F497C: swc1        $f0, 0xF8($s5)
        MEM_W(0XF8, ctx->r21) = ctx->f0.u32l;
            goto L_800F498C;
    }
    // 0x800F497C: swc1        $f0, 0xF8($s5)
    MEM_W(0XF8, ctx->r21) = ctx->f0.u32l;
    // 0x800F4980: swc1        $f2, 0xF8($s5)
    MEM_W(0XF8, ctx->r21) = ctx->f2.u32l;
L_800F4984:
    // 0x800F4984: swc1        $f2, 0xF4($s5)
    MEM_W(0XF4, ctx->r21) = ctx->f2.u32l;
L_800F4988:
    // 0x800F4988: addiu       $s0, $sp, 0xF0
    ctx->r16 = ADD32(ctx->r29, 0XF0);
L_800F498C:
    // 0x800F498C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F4990: addiu       $a1, $s6, 0x18
    ctx->r5 = ADD32(ctx->r22, 0X18);
    // 0x800F4994: jal         0x80019548
    // 0x800F4998: addiu       $a2, $s6, 0xC
    ctx->r6 = ADD32(ctx->r22, 0XC);
    vec3Cross(rdram, ctx);
        goto after_29;
    // 0x800F4998: addiu       $a2, $s6, 0xC
    ctx->r6 = ADD32(ctx->r22, 0XC);
    after_29:
    // 0x800F499C: lw          $v0, 0x24($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X24);
    // 0x800F49A0: lw          $v0, 0x50($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X50);
    // 0x800F49A4: bne         $v0, $zero, L_800F49DC
    if (ctx->r2 != 0) {
        // 0x800F49A8: nop
    
            goto L_800F49DC;
    }
    // 0x800F49A8: nop

    // 0x800F49AC: lwc1        $f0, 0xF8($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0XF8);
    // 0x800F49B0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F49B4: lwc1        $f12, -0x7408($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7408);
    // 0x800F49B8: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800F49BC: jal         0x8002B190
    // 0x800F49C0: nop

    cosf_recomp(rdram, ctx);
        goto after_30;
    // 0x800F49C0: nop

    after_30:
    // 0x800F49C4: jal         0x8001C5CC
    // 0x800F49C8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    constMinusSinfApprox(rdram, ctx);
        goto after_31;
    // 0x800F49C8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_31:
    // 0x800F49CC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F49D0: lwc1        $f2, -0x7404($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7404);
    // 0x800F49D4: j           L_800F4A08
    // 0x800F49D8: nop

        goto L_800F4A08;
    // 0x800F49D8: nop

L_800F49DC:
    // 0x800F49DC: lwc1        $f0, 0xF8($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0XF8);
    // 0x800F49E0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F49E4: lwc1        $f12, -0x7400($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7400);
    // 0x800F49E8: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800F49EC: jal         0x8002B190
    // 0x800F49F0: nop

    cosf_recomp(rdram, ctx);
        goto after_32;
    // 0x800F49F0: nop

    after_32:
    // 0x800F49F4: jal         0x8001C5CC
    // 0x800F49F8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    constMinusSinfApprox(rdram, ctx);
        goto after_33;
    // 0x800F49F8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_33:
    // 0x800F49FC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F4A00: lwc1        $f2, -0x73FC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X73FC);
    // 0x800F4A04: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_800F4A08:
    // 0x800F4A08: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F4A0C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F4A10: lwc1        $f2, -0x73F8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X73F8);
    // 0x800F4A14: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F4A18: addiu       $a0, $sp, 0x100
    ctx->r4 = ADD32(ctx->r29, 0X100);
    // 0x800F4A1C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800F4A20: jal         0x8001D240
    // 0x800F4A24: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    quatFromAxisAngle(rdram, ctx);
        goto after_34;
    // 0x800F4A24: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_34:
    // 0x800F4A28: addiu       $s1, $sp, 0x100
    ctx->r17 = ADD32(ctx->r29, 0X100);
    // 0x800F4A2C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F4A30: addiu       $a1, $s6, 0xC
    ctx->r5 = ADD32(ctx->r22, 0XC);
    // 0x800F4A34: addiu       $s0, $sp, 0xF0
    ctx->r16 = ADD32(ctx->r29, 0XF0);
    // 0x800F4A38: jal         0x8001D3C4
    // 0x800F4A3C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_35;
    // 0x800F4A3C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_35:
    // 0x800F4A40: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F4A44: addiu       $a1, $s6, 0x18
    ctx->r5 = ADD32(ctx->r22, 0X18);
    // 0x800F4A48: lw          $t0, 0xF0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XF0);
    // 0x800F4A4C: lw          $t1, 0xF4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XF4);
    // 0x800F4A50: lw          $t2, 0xF8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF8);
    // 0x800F4A54: sw          $t0, 0xC($s6)
    MEM_W(0XC, ctx->r22) = ctx->r8;
    // 0x800F4A58: sw          $t1, 0x10($s6)
    MEM_W(0X10, ctx->r22) = ctx->r9;
    // 0x800F4A5C: sw          $t2, 0x14($s6)
    MEM_W(0X14, ctx->r22) = ctx->r10;
    // 0x800F4A60: jal         0x8001D3C4
    // 0x800F4A64: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_36;
    // 0x800F4A64: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_36:
    // 0x800F4A68: lw          $t0, 0xF0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XF0);
    // 0x800F4A6C: lw          $t1, 0xF4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XF4);
    // 0x800F4A70: lw          $t2, 0xF8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF8);
    // 0x800F4A74: sw          $t0, 0x18($s6)
    MEM_W(0X18, ctx->r22) = ctx->r8;
    // 0x800F4A78: sw          $t1, 0x1C($s6)
    MEM_W(0X1C, ctx->r22) = ctx->r9;
    // 0x800F4A7C: sw          $t2, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r10;
L_800F4A80:
    // 0x800F4A80: lbu         $v0, 0x168($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X168);
    // 0x800F4A84: beq         $v0, $zero, L_800F4AA4
    if (ctx->r2 == 0) {
        // 0x800F4A88: addiu       $a1, $zero, 0x9
        ctx->r5 = ADD32(0, 0X9);
            goto L_800F4AA4;
    }
    // 0x800F4A88: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800F4A8C: lhu         $a0, 0x198($s7)
    ctx->r4 = MEM_HU(ctx->r23, 0X198);
    // 0x800F4A90: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x800F4A94: jal         0x8003E8DC
    // 0x800F4A98: addiu       $a2, $a2, -0x3B80
    ctx->r6 = ADD32(ctx->r6, -0X3B80);
    slotDispatcherIter(rdram, ctx);
        goto after_37;
    // 0x800F4A98: addiu       $a2, $a2, -0x3B80
    ctx->r6 = ADD32(ctx->r6, -0X3B80);
    after_37:
    // 0x800F4A9C: j           L_800F4E3C
    // 0x800F4AA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800F4E3C;
    // 0x800F4AA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F4AA4:
    // 0x800F4AA4: lhu         $a0, 0x110($s7)
    ctx->r4 = MEM_HU(ctx->r23, 0X110);
    // 0x800F4AA8: andi        $v0, $a0, 0x4
    ctx->r2 = ctx->r4 & 0X4;
    // 0x800F4AAC: beq         $v0, $zero, L_800F4C9C
    if (ctx->r2 == 0) {
        // 0x800F4AB0: andi        $v0, $a0, 0x10
        ctx->r2 = ctx->r4 & 0X10;
            goto L_800F4C9C;
    }
    // 0x800F4AB0: andi        $v0, $a0, 0x10
    ctx->r2 = ctx->r4 & 0X10;
    // 0x800F4AB4: bne         $v0, $zero, L_800F4AEC
    if (ctx->r2 != 0) {
        // 0x800F4AB8: lui         $a2, 0x8014
        ctx->r6 = S32(0X8014 << 16);
            goto L_800F4AEC;
    }
    // 0x800F4AB8: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800F4ABC: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x800F4AC0: lwc1        $f12, 0x0($s6)
    ctx->f12.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800F4AC4: lwc1        $f14, 0x8($s6)
    ctx->f14.u32l = MEM_W(ctx->r22, 0X8);
    // 0x800F4AC8: jal         0x80067D90
    // 0x800F4ACC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    wrapAngleToCyclicRange(rdram, ctx);
        goto after_38;
    // 0x800F4ACC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_38:
    // 0x800F4AD0: lwc1        $f2, 0x38($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X38);
    // 0x800F4AD4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F4AD8: lwc1        $f4, -0x73F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X73F4);
    // 0x800F4ADC: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800F4AE0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F4AE4: j           L_800F4E38
    // 0x800F4AE8: swc1        $f0, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->f0.u32l;
        goto L_800F4E38;
    // 0x800F4AE8: swc1        $f0, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->f0.u32l;
L_800F4AEC:
    // 0x800F4AEC: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x800F4AF0: lwc1        $f12, 0x0($s6)
    ctx->f12.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800F4AF4: lwc1        $f14, 0x8($s6)
    ctx->f14.u32l = MEM_W(ctx->r22, 0X8);
    // 0x800F4AF8: jal         0x80068180
    // 0x800F4AFC: addiu       $a3, $sp, 0x120
    ctx->r7 = ADD32(ctx->r29, 0X120);
    func_80068180(rdram, ctx);
        goto after_39;
    // 0x800F4AFC: addiu       $a3, $sp, 0x120
    ctx->r7 = ADD32(ctx->r29, 0X120);
    after_39:
    // 0x800F4B00: lwc1        $f4, 0x38($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X38);
    // 0x800F4B04: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F4B08: lwc1        $f2, -0x73F0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X73F0);
    // 0x800F4B0C: mul.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800F4B10: addiu       $s2, $s5, 0x18
    ctx->r18 = ADD32(ctx->r21, 0X18);
    // 0x800F4B14: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F4B18: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800F4B1C: addiu       $s1, $sp, 0x12C
    ctx->r17 = ADD32(ctx->r29, 0X12C);
    // 0x800F4B20: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800F4B24: jal         0x8001CFE8
    // 0x800F4B28: swc1        $f0, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->f0.u32l;
    vec3Dot(rdram, ctx);
        goto after_40;
    // 0x800F4B28: swc1        $f0, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->f0.u32l;
    after_40:
    // 0x800F4B2C: jal         0x8001C5CC
    // 0x800F4B30: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    constMinusSinfApprox(rdram, ctx);
        goto after_41;
    // 0x800F4B30: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_41:
    // 0x800F4B34: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F4B38: lwc1        $f2, -0x73EC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x800F4B3C: mul.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F4B40: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F4B44: lwc1        $f0, -0x73E8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X73E8);
    // 0x800F4B48: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800F4B4C: nop

    // 0x800F4B50: bc1f        L_800F4BCC
    if (!c1cs) {
        // 0x800F4B54: addiu       $s0, $s5, 0x18
        ctx->r16 = ADD32(ctx->r21, 0X18);
            goto L_800F4BCC;
    }
    // 0x800F4B54: addiu       $s0, $s5, 0x18
    ctx->r16 = ADD32(ctx->r21, 0X18);
    // 0x800F4B58: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F4B5C: lwc1        $f0, -0x73E4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X73E4);
    // 0x800F4B60: mul.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800F4B64: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800F4B68: nop

    // 0x800F4B6C: bc1tl       L_800F4B74
    if (c1cs) {
        // 0x800F4B70: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_800F4B74;
    }
    goto skip_1;
    // 0x800F4B70: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_1:
L_800F4B74:
    // 0x800F4B74: addiu       $s0, $sp, 0x148
    ctx->r16 = ADD32(ctx->r29, 0X148);
    // 0x800F4B78: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F4B7C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800F4B80: jal         0x80019548
    // 0x800F4B84: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    vec3Cross(rdram, ctx);
        goto after_42;
    // 0x800F4B84: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_42:
    // 0x800F4B88: addiu       $s1, $sp, 0x158
    ctx->r17 = ADD32(ctx->r29, 0X158);
    // 0x800F4B8C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F4B90: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800F4B94: jal         0x8001D144
    // 0x800F4B98: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    quatFromAxisAngleSafe(rdram, ctx);
        goto after_43;
    // 0x800F4B98: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_43:
    // 0x800F4B9C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F4BA0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800F4BA4: jal         0x8001D3C4
    // 0x800F4BA8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_44;
    // 0x800F4BA8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_44:
    // 0x800F4BAC: lw          $t0, 0x148($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X148);
    // 0x800F4BB0: lw          $t1, 0x14C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14C);
    // 0x800F4BB4: lw          $t2, 0x150($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X150);
    // 0x800F4BB8: sw          $t0, 0x18($s5)
    MEM_W(0X18, ctx->r21) = ctx->r8;
    // 0x800F4BBC: sw          $t1, 0x1C($s5)
    MEM_W(0X1C, ctx->r21) = ctx->r9;
    // 0x800F4BC0: sw          $t2, 0x20($s5)
    MEM_W(0X20, ctx->r21) = ctx->r10;
    // 0x800F4BC4: j           L_800F4BE4
    // 0x800F4BC8: addiu       $s0, $s5, 0x18
    ctx->r16 = ADD32(ctx->r21, 0X18);
        goto L_800F4BE4;
    // 0x800F4BC8: addiu       $s0, $s5, 0x18
    ctx->r16 = ADD32(ctx->r21, 0X18);
L_800F4BCC:
    // 0x800F4BCC: lw          $t0, 0x12C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X12C);
    // 0x800F4BD0: lw          $t1, 0x130($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X130);
    // 0x800F4BD4: lw          $t2, 0x134($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X134);
    // 0x800F4BD8: sw          $t0, 0x18($s5)
    MEM_W(0X18, ctx->r21) = ctx->r8;
    // 0x800F4BDC: sw          $t1, 0x1C($s5)
    MEM_W(0X1C, ctx->r21) = ctx->r9;
    // 0x800F4BE0: sw          $t2, 0x20($s5)
    MEM_W(0X20, ctx->r21) = ctx->r10;
L_800F4BE4:
    // 0x800F4BE4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F4BE8: addiu       $s2, $s6, 0x18
    ctx->r18 = ADD32(ctx->r22, 0X18);
    // 0x800F4BEC: jal         0x8001CFE8
    // 0x800F4BF0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    vec3Dot(rdram, ctx);
        goto after_45;
    // 0x800F4BF0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_45:
    // 0x800F4BF4: jal         0x8001C5CC
    // 0x800F4BF8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    constMinusSinfApprox(rdram, ctx);
        goto after_46;
    // 0x800F4BF8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_46:
    // 0x800F4BFC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F4C00: lwc1        $f2, -0x73E0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X73E0);
    // 0x800F4C04: mul.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F4C08: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F4C0C: lwc1        $f0, -0x73DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X73DC);
    // 0x800F4C10: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800F4C14: nop

    // 0x800F4C18: bc1f        L_800F4E38
    if (!c1cs) {
        // 0x800F4C1C: addiu       $s1, $sp, 0x148
        ctx->r17 = ADD32(ctx->r29, 0X148);
            goto L_800F4E38;
    }
    // 0x800F4C1C: addiu       $s1, $sp, 0x148
    ctx->r17 = ADD32(ctx->r29, 0X148);
    // 0x800F4C20: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F4C24: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800F4C28: jal         0x80019548
    // 0x800F4C2C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    vec3Cross(rdram, ctx);
        goto after_47;
    // 0x800F4C2C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_47:
    // 0x800F4C30: addiu       $s0, $sp, 0x158
    ctx->r16 = ADD32(ctx->r29, 0X158);
    // 0x800F4C34: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F4C38: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800F4C3C: jal         0x8001D144
    // 0x800F4C40: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    quatFromAxisAngleSafe(rdram, ctx);
        goto after_48;
    // 0x800F4C40: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_48:
    // 0x800F4C44: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F4C48: addiu       $a1, $s6, 0xC
    ctx->r5 = ADD32(ctx->r22, 0XC);
    // 0x800F4C4C: jal         0x8001D3C4
    // 0x800F4C50: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_49;
    // 0x800F4C50: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_49:
    // 0x800F4C54: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F4C58: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800F4C5C: lw          $t0, 0x148($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X148);
    // 0x800F4C60: lw          $t1, 0x14C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14C);
    // 0x800F4C64: lw          $t2, 0x150($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X150);
    // 0x800F4C68: sw          $t0, 0xC($s6)
    MEM_W(0XC, ctx->r22) = ctx->r8;
    // 0x800F4C6C: sw          $t1, 0x10($s6)
    MEM_W(0X10, ctx->r22) = ctx->r9;
    // 0x800F4C70: sw          $t2, 0x14($s6)
    MEM_W(0X14, ctx->r22) = ctx->r10;
    // 0x800F4C74: jal         0x8001D3C4
    // 0x800F4C78: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_50;
    // 0x800F4C78: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_50:
    // 0x800F4C7C: lw          $t0, 0x148($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X148);
    // 0x800F4C80: lw          $t1, 0x14C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14C);
    // 0x800F4C84: lw          $t2, 0x150($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X150);
    // 0x800F4C88: sw          $t0, 0x18($s6)
    MEM_W(0X18, ctx->r22) = ctx->r8;
    // 0x800F4C8C: sw          $t1, 0x1C($s6)
    MEM_W(0X1C, ctx->r22) = ctx->r9;
    // 0x800F4C90: sw          $t2, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r10;
    // 0x800F4C94: j           L_800F4E3C
    // 0x800F4C98: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800F4E3C;
    // 0x800F4C98: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F4C9C:
    // 0x800F4C9C: beq         $v0, $zero, L_800F4E3C
    if (ctx->r2 == 0) {
        // 0x800F4CA0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F4E3C;
    }
    // 0x800F4CA0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F4CA4: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800F4CA8: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x800F4CAC: lwc1        $f12, 0x0($s6)
    ctx->f12.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800F4CB0: lwc1        $f14, 0x8($s6)
    ctx->f14.u32l = MEM_W(ctx->r22, 0X8);
    // 0x800F4CB4: jal         0x80068180
    // 0x800F4CB8: addiu       $a3, $sp, 0x110
    ctx->r7 = ADD32(ctx->r29, 0X110);
    func_80068180(rdram, ctx);
        goto after_51;
    // 0x800F4CB8: addiu       $a3, $sp, 0x110
    ctx->r7 = ADD32(ctx->r29, 0X110);
    after_51:
    // 0x800F4CBC: addiu       $s2, $s5, 0x18
    ctx->r18 = ADD32(ctx->r21, 0X18);
    // 0x800F4CC0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F4CC4: addiu       $s1, $sp, 0x11C
    ctx->r17 = ADD32(ctx->r29, 0X11C);
    // 0x800F4CC8: jal         0x8001CFE8
    // 0x800F4CCC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    vec3Dot(rdram, ctx);
        goto after_52;
    // 0x800F4CCC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_52:
    // 0x800F4CD0: jal         0x8001C5CC
    // 0x800F4CD4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    constMinusSinfApprox(rdram, ctx);
        goto after_53;
    // 0x800F4CD4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_53:
    // 0x800F4CD8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F4CDC: lwc1        $f2, -0x73D8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X73D8);
    // 0x800F4CE0: mul.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F4CE4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F4CE8: lwc1        $f0, -0x73D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x800F4CEC: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800F4CF0: nop

    // 0x800F4CF4: bc1f        L_800F4D70
    if (!c1cs) {
        // 0x800F4CF8: addiu       $s0, $s5, 0x18
        ctx->r16 = ADD32(ctx->r21, 0X18);
            goto L_800F4D70;
    }
    // 0x800F4CF8: addiu       $s0, $s5, 0x18
    ctx->r16 = ADD32(ctx->r21, 0X18);
    // 0x800F4CFC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F4D00: lwc1        $f0, -0x73D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X73D0);
    // 0x800F4D04: mul.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800F4D08: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800F4D0C: nop

    // 0x800F4D10: bc1tl       L_800F4D18
    if (c1cs) {
        // 0x800F4D14: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_800F4D18;
    }
    goto skip_2;
    // 0x800F4D14: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_2:
L_800F4D18:
    // 0x800F4D18: addiu       $s0, $sp, 0x138
    ctx->r16 = ADD32(ctx->r29, 0X138);
    // 0x800F4D1C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F4D20: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800F4D24: jal         0x80019548
    // 0x800F4D28: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    vec3Cross(rdram, ctx);
        goto after_54;
    // 0x800F4D28: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_54:
    // 0x800F4D2C: addiu       $s1, $sp, 0x148
    ctx->r17 = ADD32(ctx->r29, 0X148);
    // 0x800F4D30: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F4D34: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800F4D38: jal         0x8001D144
    // 0x800F4D3C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    quatFromAxisAngleSafe(rdram, ctx);
        goto after_55;
    // 0x800F4D3C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_55:
    // 0x800F4D40: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F4D44: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800F4D48: jal         0x8001D3C4
    // 0x800F4D4C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_56;
    // 0x800F4D4C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_56:
    // 0x800F4D50: lw          $t0, 0x138($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X138);
    // 0x800F4D54: lw          $t1, 0x13C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X13C);
    // 0x800F4D58: lw          $t2, 0x140($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X140);
    // 0x800F4D5C: sw          $t0, 0x18($s5)
    MEM_W(0X18, ctx->r21) = ctx->r8;
    // 0x800F4D60: sw          $t1, 0x1C($s5)
    MEM_W(0X1C, ctx->r21) = ctx->r9;
    // 0x800F4D64: sw          $t2, 0x20($s5)
    MEM_W(0X20, ctx->r21) = ctx->r10;
    // 0x800F4D68: j           L_800F4D88
    // 0x800F4D6C: addiu       $s0, $s5, 0x18
    ctx->r16 = ADD32(ctx->r21, 0X18);
        goto L_800F4D88;
    // 0x800F4D6C: addiu       $s0, $s5, 0x18
    ctx->r16 = ADD32(ctx->r21, 0X18);
L_800F4D70:
    // 0x800F4D70: lw          $t0, 0x11C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X11C);
    // 0x800F4D74: lw          $t1, 0x120($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X120);
    // 0x800F4D78: lw          $t2, 0x124($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X124);
    // 0x800F4D7C: sw          $t0, 0x18($s5)
    MEM_W(0X18, ctx->r21) = ctx->r8;
    // 0x800F4D80: sw          $t1, 0x1C($s5)
    MEM_W(0X1C, ctx->r21) = ctx->r9;
    // 0x800F4D84: sw          $t2, 0x20($s5)
    MEM_W(0X20, ctx->r21) = ctx->r10;
L_800F4D88:
    // 0x800F4D88: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F4D8C: addiu       $s2, $s6, 0x18
    ctx->r18 = ADD32(ctx->r22, 0X18);
    // 0x800F4D90: jal         0x8001CFE8
    // 0x800F4D94: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    vec3Dot(rdram, ctx);
        goto after_57;
    // 0x800F4D94: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_57:
    // 0x800F4D98: jal         0x8001C5CC
    // 0x800F4D9C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    constMinusSinfApprox(rdram, ctx);
        goto after_58;
    // 0x800F4D9C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_58:
    // 0x800F4DA0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F4DA4: lwc1        $f2, -0x73CC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X73CC);
    // 0x800F4DA8: mul.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F4DAC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F4DB0: lwc1        $f0, -0x73C8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X73C8);
    // 0x800F4DB4: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800F4DB8: nop

    // 0x800F4DBC: bc1f        L_800F4E38
    if (!c1cs) {
        // 0x800F4DC0: addiu       $s1, $sp, 0x138
        ctx->r17 = ADD32(ctx->r29, 0X138);
            goto L_800F4E38;
    }
    // 0x800F4DC0: addiu       $s1, $sp, 0x138
    ctx->r17 = ADD32(ctx->r29, 0X138);
    // 0x800F4DC4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F4DC8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800F4DCC: jal         0x80019548
    // 0x800F4DD0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    vec3Cross(rdram, ctx);
        goto after_59;
    // 0x800F4DD0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_59:
    // 0x800F4DD4: addiu       $s0, $sp, 0x148
    ctx->r16 = ADD32(ctx->r29, 0X148);
    // 0x800F4DD8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F4DDC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800F4DE0: jal         0x8001D144
    // 0x800F4DE4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    quatFromAxisAngleSafe(rdram, ctx);
        goto after_60;
    // 0x800F4DE4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_60:
    // 0x800F4DE8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F4DEC: addiu       $a1, $s6, 0xC
    ctx->r5 = ADD32(ctx->r22, 0XC);
    // 0x800F4DF0: jal         0x8001D3C4
    // 0x800F4DF4: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_61;
    // 0x800F4DF4: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_61:
    // 0x800F4DF8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F4DFC: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800F4E00: lw          $t0, 0x138($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X138);
    // 0x800F4E04: lw          $t1, 0x13C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X13C);
    // 0x800F4E08: lw          $t2, 0x140($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X140);
    // 0x800F4E0C: sw          $t0, 0xC($s6)
    MEM_W(0XC, ctx->r22) = ctx->r8;
    // 0x800F4E10: sw          $t1, 0x10($s6)
    MEM_W(0X10, ctx->r22) = ctx->r9;
    // 0x800F4E14: sw          $t2, 0x14($s6)
    MEM_W(0X14, ctx->r22) = ctx->r10;
    // 0x800F4E18: jal         0x8001D3C4
    // 0x800F4E1C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_62;
    // 0x800F4E1C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_62:
    // 0x800F4E20: lw          $t0, 0x138($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X138);
    // 0x800F4E24: lw          $t1, 0x13C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X13C);
    // 0x800F4E28: lw          $t2, 0x140($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X140);
    // 0x800F4E2C: sw          $t0, 0x18($s6)
    MEM_W(0X18, ctx->r22) = ctx->r8;
    // 0x800F4E30: sw          $t1, 0x1C($s6)
    MEM_W(0X1C, ctx->r22) = ctx->r9;
    // 0x800F4E34: sw          $t2, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r10;
L_800F4E38:
    // 0x800F4E38: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F4E3C:
    // 0x800F4E3C: lw          $ra, 0x194($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X194);
    // 0x800F4E40: lw          $fp, 0x190($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X190);
    // 0x800F4E44: lw          $s7, 0x18C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X18C);
    // 0x800F4E48: lw          $s6, 0x188($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X188);
    // 0x800F4E4C: lw          $s5, 0x184($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X184);
    // 0x800F4E50: lw          $s4, 0x180($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X180);
    // 0x800F4E54: lw          $s3, 0x17C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X17C);
    // 0x800F4E58: lw          $s2, 0x178($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X178);
    // 0x800F4E5C: lw          $s1, 0x174($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X174);
    // 0x800F4E60: lw          $s0, 0x170($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X170);
    // 0x800F4E64: ldc1        $f22, 0x1A0($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X1A0);
    // 0x800F4E68: ldc1        $f20, 0x198($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X198);
    // 0x800F4E6C: jr          $ra
    // 0x800F4E70: addiu       $sp, $sp, 0x1A8
    ctx->r29 = ADD32(ctx->r29, 0X1A8);
    return;
    // 0x800F4E70: addiu       $sp, $sp, 0x1A8
    ctx->r29 = ADD32(ctx->r29, 0X1A8);
;}
RECOMP_FUNC void executeActorType2Effect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4E74: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800F4E78: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x800F4E7C: addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // 0x800F4E80: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x800F4E84: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x800F4E88: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x800F4E8C: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x800F4E90: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x800F4E94: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x800F4E98: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x800F4E9C: sdc1        $f24, 0x80($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X80, ctx->r29);
    // 0x800F4EA0: sdc1        $f22, 0x78($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X78, ctx->r29);
    // 0x800F4EA4: sdc1        $f20, 0x70($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X70, ctx->r29);
    // 0x800F4EA8: lhu         $a0, 0x198($s6)
    ctx->r4 = MEM_HU(ctx->r22, 0X198);
    // 0x800F4EAC: mtc1        $a1, $f24
    ctx->f24.u32l = ctx->r5;
    // 0x800F4EB0: jal         0x8004015C
    // 0x800F4EB4: addiu       $s2, $s6, 0x8
    ctx->r18 = ADD32(ctx->r22, 0X8);
    getNpcContextField8(rdram, ctx);
        goto after_0;
    // 0x800F4EB4: addiu       $s2, $s6, 0x8
    ctx->r18 = ADD32(ctx->r22, 0X8);
    after_0:
    // 0x800F4EB8: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x800F4EBC: lwc1        $f2, 0x24($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X24);
    // 0x800F4EC0: lwc1        $f0, 0x0($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X0);
    // 0x800F4EC4: lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X30);
    // 0x800F4EC8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F4ECC: lwc1        $f2, 0x10($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800F4ED0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F4ED4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800F4ED8: lwc1        $f2, 0x28($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X28);
    // 0x800F4EDC: lwc1        $f0, 0x4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X4);
    // 0x800F4EE0: lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X30);
    // 0x800F4EE4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F4EE8: lwc1        $f2, 0x14($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800F4EEC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F4EF0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800F4EF4: lwc1        $f2, 0x2C($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X2C);
    // 0x800F4EF8: lwc1        $f0, 0x8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800F4EFC: lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X30);
    // 0x800F4F00: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F4F04: lwc1        $f2, 0x18($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800F4F08: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F4F0C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800F4F10: jal         0x8001CF2C
    // 0x800F4F14: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    vec3Length(rdram, ctx);
        goto after_1;
    // 0x800F4F14: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800F4F18: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800F4F1C: mov.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
    // 0x800F4F20: c.eq.s      $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f4.fl == ctx->f22.fl;
    // 0x800F4F24: nop

    // 0x800F4F28: bc1f        L_800F4F38
    if (!c1cs) {
        // 0x800F4F2C: addiu       $s4, $sp, 0x20
        ctx->r20 = ADD32(ctx->r29, 0X20);
            goto L_800F4F38;
    }
    // 0x800F4F2C: addiu       $s4, $sp, 0x20
    ctx->r20 = ADD32(ctx->r29, 0X20);
    // 0x800F4F30: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F4F34: lwc1        $f4, -0x73C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X73C4);
L_800F4F38:
    // 0x800F4F38: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800F4F3C: addiu       $s5, $s3, 0xC
    ctx->r21 = ADD32(ctx->r19, 0XC);
    // 0x800F4F40: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x800F4F44: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F4F48: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F4F4C: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800F4F50: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800F4F54: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800F4F58: div.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800F4F5C: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x800F4F60: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800F4F64: jal         0x8001CFE8
    // 0x800F4F68: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    vec3Dot(rdram, ctx);
        goto after_2;
    // 0x800F4F68: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x800F4F6C: jal         0x8001C5CC
    // 0x800F4F70: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    constMinusSinfApprox(rdram, ctx);
        goto after_3;
    // 0x800F4F70: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x800F4F74: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F4F78: lwc1        $f2, -0x73C0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X73C0);
    // 0x800F4F7C: mul.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F4F80: jal         0x8001CF2C
    // 0x800F4F84: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    vec3Length(rdram, ctx);
        goto after_4;
    // 0x800F4F84: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_4:
    // 0x800F4F88: lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X30);
    // 0x800F4F8C: lwc1        $f2, 0x1C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800F4F90: mov.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
    // 0x800F4F94: c.le.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl <= ctx->f4.fl;
    // 0x800F4F98: nop

    // 0x800F4F9C: bc1f        L_800F50AC
    if (!c1cs) {
        // 0x800F4FA0: nop
    
            goto L_800F50AC;
    }
    // 0x800F4FA0: nop

    // 0x800F4FA4: lbu         $v0, 0x34($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X34);
    // 0x800F4FA8: bne         $v0, $zero, L_800F5088
    if (ctx->r2 != 0) {
        // 0x800F4FAC: nop
    
            goto L_800F5088;
    }
    // 0x800F4FAC: nop

    // 0x800F4FB0: lbu         $v0, 0x35($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X35);
    // 0x800F4FB4: bne         $v0, $zero, L_800F5018
    if (ctx->r2 != 0) {
        // 0x800F4FB8: addiu       $s0, $sp, 0x30
        ctx->r16 = ADD32(ctx->r29, 0X30);
            goto L_800F5018;
    }
    // 0x800F4FB8: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x800F4FBC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F4FC0: lui         $a2, 0x4334
    ctx->r6 = S32(0X4334 << 16);
    // 0x800F4FC4: jal         0x8001D240
    // 0x800F4FC8: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    quatFromAxisAngle(rdram, ctx);
        goto after_5;
    // 0x800F4FC8: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_5:
    // 0x800F4FCC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F4FD0: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x800F4FD4: jal         0x8001D3C4
    // 0x800F4FD8: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_6;
    // 0x800F4FD8: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_6:
    // 0x800F4FDC: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F4FE0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F4FE4: swc1        $f0, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->f0.u32l;
    // 0x800F4FE8: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F4FEC: lwc1        $f2, 0xC($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0XC);
    // 0x800F4FF0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F4FF4: swc1        $f0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f0.u32l;
    // 0x800F4FF8: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F4FFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F5000: sb          $v0, 0x34($s2)
    MEM_B(0X34, ctx->r18) = ctx->r2;
    // 0x800F5004: sb          $zero, 0x35($s2)
    MEM_B(0X35, ctx->r18) = 0;
    // 0x800F5008: swc1        $f2, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f2.u32l;
    // 0x800F500C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F5010: j           L_800F5198
    // 0x800F5014: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
        goto L_800F5198;
    // 0x800F5014: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
L_800F5018:
    // 0x800F5018: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F501C: lwc1        $f0, -0x73BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X73BC);
    // 0x800F5020: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800F5024: nop

    // 0x800F5028: bc1f        L_800F5198
    if (!c1cs) {
        // 0x800F502C: addiu       $s1, $sp, 0x40
        ctx->r17 = ADD32(ctx->r29, 0X40);
            goto L_800F5198;
    }
    // 0x800F502C: addiu       $s1, $sp, 0x40
    ctx->r17 = ADD32(ctx->r29, 0X40);
    // 0x800F5030: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F5034: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x800F5038: jal         0x80019548
    // 0x800F503C: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    vec3Cross(rdram, ctx);
        goto after_7;
    // 0x800F503C: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    after_7:
    // 0x800F5040: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5044: lwc1        $f0, -0x73B8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X73B8);
    // 0x800F5048: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800F504C: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x800F5050: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F5054: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800F5058: jal         0x8001D144
    // 0x800F505C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    quatFromAxisAngleSafe(rdram, ctx);
        goto after_8;
    // 0x800F505C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_8:
    // 0x800F5060: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F5064: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x800F5068: jal         0x8001D3C4
    // 0x800F506C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_9;
    // 0x800F506C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_9:
    // 0x800F5070: lwc1        $f0, 0xC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC);
    // 0x800F5074: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F5078: sb          $v0, 0x34($s2)
    MEM_B(0X34, ctx->r18) = ctx->r2;
    // 0x800F507C: sb          $zero, 0x35($s2)
    MEM_B(0X35, ctx->r18) = 0;
    // 0x800F5080: j           L_800F5198
    // 0x800F5084: swc1        $f0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f0.u32l;
        goto L_800F5198;
    // 0x800F5084: swc1        $f0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f0.u32l;
L_800F5088:
    // 0x800F5088: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F508C: lwc1        $f0, -0x73B4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X73B4);
    // 0x800F5090: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800F5094: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x800F5098: nop

    // 0x800F509C: bc1f        L_800F5198
    if (!c1cs) {
        // 0x800F50A0: nop
    
            goto L_800F5198;
    }
    // 0x800F50A0: nop

    // 0x800F50A4: j           L_800F5194
    // 0x800F50A8: sb          $zero, 0x34($s2)
    MEM_B(0X34, ctx->r18) = 0;
        goto L_800F5194;
    // 0x800F50A8: sb          $zero, 0x34($s2)
    MEM_B(0X34, ctx->r18) = 0;
L_800F50AC:
    // 0x800F50AC: lwc1        $f0, 0x24($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X24);
    // 0x800F50B0: c.eq.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl == ctx->f22.fl;
    // 0x800F50B4: nop

    // 0x800F50B8: bc1tl       L_800F5198
    if (c1cs) {
        // 0x800F50BC: sb          $zero, 0x35($s2)
        MEM_B(0X35, ctx->r18) = 0;
            goto L_800F5198;
    }
    goto skip_0;
    // 0x800F50BC: sb          $zero, 0x35($s2)
    MEM_B(0X35, ctx->r18) = 0;
    skip_0:
    // 0x800F50C0: lwc1        $f0, 0x18($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X18);
    // 0x800F50C4: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x800F50C8: lbu         $v0, 0x34($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X34);
    // 0x800F50CC: bne         $v0, $zero, L_800F5194
    if (ctx->r2 != 0) {
        // 0x800F50D0: swc1        $f0, 0x18($s2)
        MEM_W(0X18, ctx->r18) = ctx->f0.u32l;
            goto L_800F5194;
    }
    // 0x800F50D0: swc1        $f0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f0.u32l;
    // 0x800F50D4: c.le.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl <= ctx->f22.fl;
    // 0x800F50D8: nop

    // 0x800F50DC: bc1fl       L_800F5198
    if (!c1cs) {
        // 0x800F50E0: sb          $zero, 0x35($s2)
        MEM_B(0X35, ctx->r18) = 0;
            goto L_800F5198;
    }
    goto skip_1;
    // 0x800F50E0: sb          $zero, 0x35($s2)
    MEM_B(0X35, ctx->r18) = 0;
    skip_1:
    // 0x800F50E4: jal         0x80003430
    // 0x800F50E8: nop

    rand_recomp(rdram, ctx);
        goto after_10;
    // 0x800F50E8: nop

    after_10:
    // 0x800F50EC: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800F50F0: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800F50F4: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800F50F8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F50FC: lwc1        $f20, -0x73B0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X73B0);
    // 0x800F5100: lwc1        $f0, 0x28($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X28);
    // 0x800F5104: sub.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f20.fl;
    // 0x800F5108: div.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800F510C: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F5110: abs.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = fabsf(ctx->f2.fl);
    // 0x800F5114: lwc1        $f0, 0x24($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X24);
    // 0x800F5118: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F511C: jal         0x80003430
    // 0x800F5120: swc1        $f0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_11;
    // 0x800F5120: swc1        $f0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f0.u32l;
    after_11:
    // 0x800F5124: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800F5128: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F512C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F5130: lwc1        $f2, 0x20($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X20);
    // 0x800F5134: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800F5138: div.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x800F513C: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800F5140: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x800F5144: lwc1        $f0, 0x1C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x800F5148: jal         0x80003430
    // 0x800F514C: add.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f0.fl + ctx->f2.fl;
    rand_recomp(rdram, ctx);
        goto after_12;
    // 0x800F514C: add.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f0.fl + ctx->f2.fl;
    after_12:
    // 0x800F5150: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800F5154: bne         $v0, $zero, L_800F5160
    if (ctx->r2 != 0) {
        // 0x800F5158: mov.s       $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
            goto L_800F5160;
    }
    // 0x800F5158: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x800F515C: neg.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = -ctx->f20.fl;
L_800F5160:
    // 0x800F5160: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x800F5164: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F5168: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800F516C: jal         0x8001D240
    // 0x800F5170: addiu       $a1, $s3, 0x18
    ctx->r5 = ADD32(ctx->r19, 0X18);
    quatFromAxisAngle(rdram, ctx);
        goto after_13;
    // 0x800F5170: addiu       $a1, $s3, 0x18
    ctx->r5 = ADD32(ctx->r19, 0X18);
    after_13:
    // 0x800F5174: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F5178: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x800F517C: jal         0x8001D3C4
    // 0x800F5180: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_14;
    // 0x800F5180: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_14:
    // 0x800F5184: lwc1        $f0, 0x2C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x800F5188: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F518C: sb          $v0, 0x34($s2)
    MEM_B(0X34, ctx->r18) = ctx->r2;
    // 0x800F5190: swc1        $f0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f0.u32l;
L_800F5194:
    // 0x800F5194: sb          $zero, 0x35($s2)
    MEM_B(0X35, ctx->r18) = 0;
L_800F5198:
    // 0x800F5198: lwc1        $f2, 0x10($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X10);
    // 0x800F519C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F51A0: lwc1        $f0, -0x73AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X73AC);
    // 0x800F51A4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F51A8: lhu         $v0, 0x110($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X110);
    // 0x800F51AC: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800F51B0: mul.s       $f22, $f2, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x800F51B4: beq         $v0, $zero, L_800F51C8
    if (ctx->r2 == 0) {
        // 0x800F51B8: nop
    
            goto L_800F51C8;
    }
    // 0x800F51B8: nop

    // 0x800F51BC: sw          $zero, 0x4($s2)
    MEM_W(0X4, ctx->r18) = 0;
    // 0x800F51C0: jal         0x8001CF58
    // 0x800F51C4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    normalize_vector(rdram, ctx);
        goto after_15;
    // 0x800F51C4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_15:
L_800F51C8:
    // 0x800F51C8: lbu         $v0, 0x34($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X34);
    // 0x800F51CC: beq         $v0, $zero, L_800F52C8
    if (ctx->r2 == 0) {
        // 0x800F51D0: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_800F52C8;
    }
    // 0x800F51D0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F51D4: addiu       $s1, $s3, 0xC
    ctx->r17 = ADD32(ctx->r19, 0XC);
    // 0x800F51D8: jal         0x8001CFE8
    // 0x800F51DC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    vec3Dot(rdram, ctx);
        goto after_16;
    // 0x800F51DC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_16:
    // 0x800F51E0: jal         0x8001C5CC
    // 0x800F51E4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    constMinusSinfApprox(rdram, ctx);
        goto after_17;
    // 0x800F51E4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_17:
    // 0x800F51E8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F51EC: lwc1        $f2, -0x73A8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X73A8);
    // 0x800F51F0: mul.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F51F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F51F8: lwc1        $f0, -0x73A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X73A4);
    // 0x800F51FC: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800F5200: nop

    // 0x800F5204: bc1f        L_800F52A4
    if (!c1cs) {
        // 0x800F5208: addiu       $s4, $sp, 0x40
        ctx->r20 = ADD32(ctx->r29, 0X40);
            goto L_800F52A4;
    }
    // 0x800F5208: addiu       $s4, $sp, 0x40
    ctx->r20 = ADD32(ctx->r29, 0X40);
    // 0x800F520C: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800F5210: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800F5214: jal         0x80019548
    // 0x800F5218: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    vec3Cross(rdram, ctx);
        goto after_18;
    // 0x800F5218: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_18:
    // 0x800F521C: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x800F5220: nop

    // 0x800F5224: bc1tl       L_800F522C
    if (c1cs) {
        // 0x800F5228: mov.s       $f20, $f22
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
            goto L_800F522C;
    }
    goto skip_2;
    // 0x800F5228: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    skip_2:
L_800F522C:
    // 0x800F522C: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x800F5230: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F5234: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800F5238: jal         0x8001D144
    // 0x800F523C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    quatFromAxisAngleSafe(rdram, ctx);
        goto after_19;
    // 0x800F523C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_19:
    // 0x800F5240: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F5244: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800F5248: addiu       $s1, $sp, 0x20
    ctx->r17 = ADD32(ctx->r29, 0X20);
    // 0x800F524C: jal         0x8001D3C4
    // 0x800F5250: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_20;
    // 0x800F5250: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_20:
    // 0x800F5254: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F5258: addiu       $a1, $s3, 0x18
    ctx->r5 = ADD32(ctx->r19, 0X18);
    // 0x800F525C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x800F5260: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800F5264: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800F5268: sw          $v1, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r3;
    // 0x800F526C: sw          $t0, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r8;
    // 0x800F5270: sw          $t1, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r9;
    // 0x800F5274: jal         0x8001D3C4
    // 0x800F5278: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_21;
    // 0x800F5278: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_21:
    // 0x800F527C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x800F5280: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800F5284: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800F5288: sw          $v1, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r3;
    // 0x800F528C: sw          $t0, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->r8;
    // 0x800F5290: sw          $t1, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->r9;
    // 0x800F5294: jal         0x80059F10
    // 0x800F5298: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    orthonormalizeFrame(rdram, ctx);
        goto after_22;
    // 0x800F5298: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_22:
    // 0x800F529C: j           L_800F52C8
    // 0x800F52A0: nop

        goto L_800F52C8;
    // 0x800F52A0: nop

L_800F52A4:
    // 0x800F52A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F52A8: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800F52AC: lw          $t0, 0x4($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X4);
    // 0x800F52B0: lw          $t1, 0x8($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X8);
    // 0x800F52B4: sw          $v1, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r3;
    // 0x800F52B8: sw          $t0, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r8;
    // 0x800F52BC: sw          $t1, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r9;
    // 0x800F52C0: sb          $zero, 0x34($s2)
    MEM_B(0X34, ctx->r18) = 0;
    // 0x800F52C4: sb          $v0, 0x35($s2)
    MEM_B(0X35, ctx->r18) = ctx->r2;
L_800F52C8:
    // 0x800F52C8: lwc1        $f0, 0xC($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XC);
    // 0x800F52CC: lwc1        $f2, 0x14($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X14);
    // 0x800F52D0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F52D4: swc1        $f0, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->f0.u32l;
    // 0x800F52D8: lwc1        $f0, 0x10($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X10);
    // 0x800F52DC: lwc1        $f2, 0x14($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X14);
    // 0x800F52E0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F52E4: lwc1        $f2, 0x14($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X14);
    // 0x800F52E8: swc1        $f0, 0x28($s3)
    MEM_W(0X28, ctx->r19) = ctx->f0.u32l;
    // 0x800F52EC: lwc1        $f0, 0x14($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X14);
    // 0x800F52F0: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F52F4: lwc1        $f8, 0x28($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X28);
    // 0x800F52F8: mul.s       $f8, $f8, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x800F52FC: lwc1        $f0, 0x24($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X24);
    // 0x800F5300: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800F5304: swc1        $f2, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->f2.u32l;
    // 0x800F5308: mov.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.fl = ctx->f2.fl;
    // 0x800F530C: mul.s       $f6, $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x800F5310: lwc1        $f4, 0x0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
    // 0x800F5314: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800F5318: lwc1        $f2, 0x4($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X4);
    // 0x800F531C: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x800F5320: lwc1        $f0, 0x8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800F5324: add.s       $f14, $f0, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800F5328: swc1        $f4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f4.u32l;
    // 0x800F532C: swc1        $f2, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f2.u32l;
    // 0x800F5330: swc1        $f14, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f14.u32l;
    // 0x800F5334: lhu         $v0, 0x110($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X110);
    // 0x800F5338: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800F533C: beq         $v0, $zero, L_800F5358
    if (ctx->r2 == 0) {
        // 0x800F5340: lui         $a2, 0x8014
        ctx->r6 = S32(0X8014 << 16);
            goto L_800F5358;
    }
    // 0x800F5340: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800F5344: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x800F5348: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
    // 0x800F534C: jal         0x80067D90
    // 0x800F5350: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    wrapAngleToCyclicRange(rdram, ctx);
        goto after_23;
    // 0x800F5350: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_23:
    // 0x800F5354: swc1        $f0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f0.u32l;
L_800F5358:
    // 0x800F5358: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x800F535C: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x800F5360: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x800F5364: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x800F5368: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x800F536C: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x800F5370: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x800F5374: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x800F5378: ldc1        $f24, 0x80($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X80);
    // 0x800F537C: ldc1        $f22, 0x78($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X78);
    // 0x800F5380: ldc1        $f20, 0x70($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X70);
    // 0x800F5384: jr          $ra
    // 0x800F5388: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x800F5388: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void executeActorType3Effect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F538C: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x800F5390: sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // 0x800F5394: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x800F5398: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x800F539C: sw          $ra, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r31;
    // 0x800F53A0: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // 0x800F53A4: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x800F53A8: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x800F53AC: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x800F53B0: sdc1        $f24, 0x90($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X90, ctx->r29);
    // 0x800F53B4: sdc1        $f22, 0x88($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X88, ctx->r29);
    // 0x800F53B8: sdc1        $f20, 0x80($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X80, ctx->r29);
    // 0x800F53BC: lhu         $a0, 0x198($s5)
    ctx->r4 = MEM_HU(ctx->r21, 0X198);
    // 0x800F53C0: mtc1        $a1, $f24
    ctx->f24.u32l = ctx->r5;
    // 0x800F53C4: jal         0x8004015C
    // 0x800F53C8: addiu       $s3, $s5, 0x8
    ctx->r19 = ADD32(ctx->r21, 0X8);
    getNpcContextField8(rdram, ctx);
        goto after_0;
    // 0x800F53C8: addiu       $s3, $s5, 0x8
    ctx->r19 = ADD32(ctx->r21, 0X8);
    after_0:
    // 0x800F53CC: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // 0x800F53D0: lwc1        $f2, 0x24($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X24);
    // 0x800F53D4: lwc1        $f0, 0x0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X0);
    // 0x800F53D8: lw          $v0, 0x30($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X30);
    // 0x800F53DC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F53E0: lwc1        $f2, 0x10($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800F53E4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F53E8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800F53EC: lwc1        $f2, 0x28($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X28);
    // 0x800F53F0: lwc1        $f0, 0x4($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X4);
    // 0x800F53F4: lw          $v0, 0x30($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X30);
    // 0x800F53F8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F53FC: lwc1        $f2, 0x14($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800F5400: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F5404: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800F5408: lwc1        $f2, 0x2C($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X2C);
    // 0x800F540C: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x800F5410: lw          $v0, 0x30($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X30);
    // 0x800F5414: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F5418: lwc1        $f2, 0x18($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800F541C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F5420: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800F5424: lw          $v0, 0x30($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X30);
    // 0x800F5428: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F542C: lwc1        $f4, -0x73A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X73A0);
    // 0x800F5430: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800F5434: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800F5438: lwc1        $f2, 0x10($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800F543C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800F5440: lwc1        $f0, 0x0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X0);
    // 0x800F5444: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F5448: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800F544C: lw          $v0, 0x30($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X30);
    // 0x800F5450: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800F5454: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800F5458: lwc1        $f2, 0x14($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800F545C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800F5460: lwc1        $f0, 0x4($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X4);
    // 0x800F5464: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F5468: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x800F546C: lw          $v0, 0x30($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X30);
    // 0x800F5470: lwc1        $f0, 0x30($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800F5474: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800F5478: lwc1        $f2, 0x18($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800F547C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800F5480: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x800F5484: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F5488: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800F548C: jal         0x8001CF58
    // 0x800F5490: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    normalize_vector(rdram, ctx);
        goto after_1;
    // 0x800F5490: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800F5494: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F5498: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F549C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800F54A0: nop

    // 0x800F54A4: bc1f        L_800F54B4
    if (!c1cs) {
        // 0x800F54A8: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800F54B4;
    }
    // 0x800F54A8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800F54AC: j           L_800F54CC
    // 0x800F54B0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800F54CC;
    // 0x800F54B0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800F54B4:
    // 0x800F54B4: lw          $v0, 0x30($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X30);
    // 0x800F54B8: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800F54BC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800F54C0: nop

    // 0x800F54C4: bc1tl       L_800F54CC
    if (c1cs) {
        // 0x800F54C8: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_800F54CC;
    }
    goto skip_0;
    // 0x800F54C8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    skip_0:
L_800F54CC:
    // 0x800F54CC: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F54D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F54D4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800F54D8: nop

    // 0x800F54DC: bc1f        L_800F54EC
    if (!c1cs) {
        // 0x800F54E0: nop
    
            goto L_800F54EC;
    }
    // 0x800F54E0: nop

    // 0x800F54E4: j           L_800F5504
    // 0x800F54E8: ori         $v1, $v1, 0x4
    ctx->r3 = ctx->r3 | 0X4;
        goto L_800F5504;
    // 0x800F54E8: ori         $v1, $v1, 0x4
    ctx->r3 = ctx->r3 | 0X4;
L_800F54EC:
    // 0x800F54EC: lw          $v0, 0x30($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X30);
    // 0x800F54F0: lwc1        $f0, 0x30($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800F54F4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800F54F8: nop

    // 0x800F54FC: bc1tl       L_800F5504
    if (c1cs) {
        // 0x800F5500: ori         $v1, $v1, 0x8
        ctx->r3 = ctx->r3 | 0X8;
            goto L_800F5504;
    }
    goto skip_1;
    // 0x800F5500: ori         $v1, $v1, 0x8
    ctx->r3 = ctx->r3 | 0X8;
    skip_1:
L_800F5504:
    // 0x800F5504: beq         $v1, $zero, L_800F5750
    if (ctx->r3 == 0) {
        // 0x800F5508: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_800F5750;
    }
    // 0x800F5508: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F550C: sltiu       $v0, $v1, 0xA
    ctx->r2 = ctx->r3 < 0XA ? 1 : 0;
    // 0x800F5510: beq         $v0, $zero, L_800F55CC
    if (ctx->r2 == 0) {
        // 0x800F5514: sw          $zero, 0x34($sp)
        MEM_W(0X34, ctx->r29) = 0;
            goto L_800F55CC;
    }
    // 0x800F5514: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x800F5518: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800F551C: addiu       $v0, $v0, -0x7398
    ctx->r2 = ADD32(ctx->r2, -0X7398);
    // 0x800F5520: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800F5524: addu        $v1, $v1, $v0
    gpr jr_addend_800F552C = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800F5528: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800F552C: jr          $v0
    // 0x800F5530: nop

    switch (jr_addend_800F552C >> 2) {
        case 0: goto L_800F5534; break;
        case 1: goto L_800F5544; break;
        case 2: goto L_800F55CC; break;
        case 3: goto L_800F557C; break;
        case 4: goto L_800F5554; break;
        case 5: goto L_800F5564; break;
        case 6: goto L_800F55CC; break;
        case 7: goto L_800F558C; break;
        case 8: goto L_800F55A0; break;
        case 9: goto L_800F55BC; break;
        default: switch_error(__func__, 0x800F552C, 0x800A8C68);
    }
    // 0x800F5530: nop

L_800F5534:
    // 0x800F5534: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5538: lwc1        $f0, -0x7370($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7370);
    // 0x800F553C: j           L_800F55C8
    // 0x800F5540: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
        goto L_800F55C8;
    // 0x800F5540: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_800F5544:
    // 0x800F5544: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5548: lwc1        $f0, -0x736C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X736C);
    // 0x800F554C: j           L_800F55C8
    // 0x800F5550: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
        goto L_800F55C8;
    // 0x800F5550: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_800F5554:
    // 0x800F5554: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5558: lwc1        $f0, -0x7368($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7368);
    // 0x800F555C: j           L_800F55C8
    // 0x800F5560: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
        goto L_800F55C8;
    // 0x800F5560: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
L_800F5564:
    // 0x800F5564: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5568: lwc1        $f0, -0x7364($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7364);
    // 0x800F556C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5570: lwc1        $f2, -0x7360($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7360);
    // 0x800F5574: j           L_800F55B4
    // 0x800F5578: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
        goto L_800F55B4;
    // 0x800F5578: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
L_800F557C:
    // 0x800F557C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5580: lwc1        $f0, -0x735C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X735C);
    // 0x800F5584: j           L_800F5598
    // 0x800F5588: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
        goto L_800F5598;
    // 0x800F5588: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_800F558C:
    // 0x800F558C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5590: lwc1        $f0, -0x7358($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7358);
    // 0x800F5594: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_800F5598:
    // 0x800F5598: j           L_800F55CC
    // 0x800F559C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
        goto L_800F55CC;
    // 0x800F559C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
L_800F55A0:
    // 0x800F55A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F55A4: lwc1        $f0, -0x7354($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7354);
    // 0x800F55A8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F55AC: lwc1        $f2, -0x7350($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7350);
    // 0x800F55B0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
L_800F55B4:
    // 0x800F55B4: j           L_800F55CC
    // 0x800F55B8: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
        goto L_800F55CC;
    // 0x800F55B8: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
L_800F55BC:
    // 0x800F55BC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F55C0: lwc1        $f0, -0x734C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X734C);
    // 0x800F55C4: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
L_800F55C8:
    // 0x800F55C8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
L_800F55CC:
    // 0x800F55CC: addiu       $s2, $sp, 0x20
    ctx->r18 = ADD32(ctx->r29, 0X20);
    // 0x800F55D0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F55D4: addiu       $s1, $s4, 0xC
    ctx->r17 = ADD32(ctx->r20, 0XC);
    // 0x800F55D8: jal         0x8001CFE8
    // 0x800F55DC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    vec3Dot(rdram, ctx);
        goto after_2;
    // 0x800F55DC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_2:
    // 0x800F55E0: jal         0x8001C5CC
    // 0x800F55E4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    constMinusSinfApprox(rdram, ctx);
        goto after_3;
    // 0x800F55E4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x800F55E8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F55EC: lwc1        $f2, -0x7348($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7348);
    // 0x800F55F0: lbu         $v0, 0x34($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X34);
    // 0x800F55F4: mul.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F55F8: bne         $v0, $zero, L_800F56DC
    if (ctx->r2 != 0) {
        // 0x800F55FC: nop
    
            goto L_800F56DC;
    }
    // 0x800F55FC: nop

    // 0x800F5600: lbu         $v0, 0x35($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X35);
    // 0x800F5604: bne         $v0, $zero, L_800F5668
    if (ctx->r2 != 0) {
        // 0x800F5608: addiu       $s0, $sp, 0x40
        ctx->r16 = ADD32(ctx->r29, 0X40);
            goto L_800F5668;
    }
    // 0x800F5608: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x800F560C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F5610: lui         $a2, 0x4334
    ctx->r6 = S32(0X4334 << 16);
    // 0x800F5614: jal         0x8001D240
    // 0x800F5618: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    quatFromAxisAngle(rdram, ctx);
        goto after_4;
    // 0x800F5618: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x800F561C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F5620: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800F5624: jal         0x8001D3C4
    // 0x800F5628: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_5;
    // 0x800F5628: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_5:
    // 0x800F562C: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F5630: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F5634: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
    // 0x800F5638: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F563C: lwc1        $f2, 0xC($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0XC);
    // 0x800F5640: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F5644: swc1        $f0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f0.u32l;
    // 0x800F5648: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F564C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F5650: sb          $v0, 0x34($s3)
    MEM_B(0X34, ctx->r19) = ctx->r2;
    // 0x800F5654: sb          $zero, 0x35($s3)
    MEM_B(0X35, ctx->r19) = 0;
    // 0x800F5658: swc1        $f2, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f2.u32l;
    // 0x800F565C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F5660: j           L_800F5840
    // 0x800F5664: swc1        $f0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f0.u32l;
        goto L_800F5840;
    // 0x800F5664: swc1        $f0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f0.u32l;
L_800F5668:
    // 0x800F5668: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F566C: lwc1        $f0, -0x7344($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7344);
    // 0x800F5670: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800F5674: nop

    // 0x800F5678: bc1f        L_800F5840
    if (!c1cs) {
        // 0x800F567C: addiu       $s1, $sp, 0x50
        ctx->r17 = ADD32(ctx->r29, 0X50);
            goto L_800F5840;
    }
    // 0x800F567C: addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
L_800F5680:
    // 0x800F5680: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_800F5684:
    // 0x800F5684: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
L_800F5688:
    // 0x800F5688: addiu       $s2, $s4, 0xC
    ctx->r18 = ADD32(ctx->r20, 0XC);
L_800F568C:
    // 0x800F568C: jal         0x80019548
    // 0x800F5690: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    vec3Cross(rdram, ctx);
        goto after_6;
    // 0x800F5690: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_6:
    // 0x800F5694: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5698: lwc1        $f0, -0x7340($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7340);
    // 0x800F569C: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800F56A0: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x800F56A4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F56A8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800F56AC: jal         0x8001D144
    // 0x800F56B0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    quatFromAxisAngleSafe(rdram, ctx);
        goto after_7;
    // 0x800F56B0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_7:
    // 0x800F56B4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F56B8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800F56BC: jal         0x8001D3C4
    // 0x800F56C0: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_8;
    // 0x800F56C0: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_8:
    // 0x800F56C4: lwc1        $f0, 0xC($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XC);
    // 0x800F56C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F56CC: sb          $v0, 0x34($s3)
    MEM_B(0X34, ctx->r19) = ctx->r2;
    // 0x800F56D0: sb          $zero, 0x35($s3)
    MEM_B(0X35, ctx->r19) = 0;
    // 0x800F56D4: j           L_800F5840
    // 0x800F56D8: swc1        $f0, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f0.u32l;
        goto L_800F5840;
    // 0x800F56D8: swc1        $f0, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f0.u32l;
L_800F56DC:
    // 0x800F56DC: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F56E0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F56E4: lwc1        $f6, -0x733C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X733C);
    // 0x800F56E8: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800F56EC: nop

    // 0x800F56F0: bc1t        L_800F5680
    if (c1cs) {
        // 0x800F56F4: addiu       $s1, $sp, 0x50
        ctx->r17 = ADD32(ctx->r29, 0X50);
            goto L_800F5680;
    }
    // 0x800F56F4: addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
    // 0x800F56F8: lw          $v0, 0x30($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X30);
    // 0x800F56FC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5700: lwc1        $f4, -0x7338($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7338);
    // 0x800F5704: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800F5708: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800F570C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800F5710: nop

    // 0x800F5714: bc1t        L_800F5684
    if (c1cs) {
        // 0x800F5718: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_800F5684;
    }
    // 0x800F5718: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F571C: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F5720: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800F5724: nop

    // 0x800F5728: bc1t        L_800F5688
    if (c1cs) {
        // 0x800F572C: addiu       $a1, $sp, 0x20
        ctx->r5 = ADD32(ctx->r29, 0X20);
            goto L_800F5688;
    }
    // 0x800F572C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800F5730: lwc1        $f0, 0x30($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800F5734: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800F5738: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800F573C: nop

    // 0x800F5740: bc1t        L_800F568C
    if (c1cs) {
        // 0x800F5744: addiu       $s2, $s4, 0xC
        ctx->r18 = ADD32(ctx->r20, 0XC);
            goto L_800F568C;
    }
    // 0x800F5744: addiu       $s2, $s4, 0xC
    ctx->r18 = ADD32(ctx->r20, 0XC);
    // 0x800F5748: j           L_800F5840
    // 0x800F574C: nop

        goto L_800F5840;
    // 0x800F574C: nop

L_800F5750:
    // 0x800F5750: lwc1        $f0, 0x24($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X24);
    // 0x800F5754: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800F5758: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800F575C: nop

    // 0x800F5760: bc1tl       L_800F5840
    if (c1cs) {
        // 0x800F5764: sb          $zero, 0x35($s3)
        MEM_B(0X35, ctx->r19) = 0;
            goto L_800F5840;
    }
    goto skip_2;
    // 0x800F5764: sb          $zero, 0x35($s3)
    MEM_B(0X35, ctx->r19) = 0;
    skip_2:
    // 0x800F5768: lwc1        $f0, 0x18($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X18);
    // 0x800F576C: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x800F5770: lbu         $v0, 0x34($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X34);
    // 0x800F5774: bne         $v0, $zero, L_800F583C
    if (ctx->r2 != 0) {
        // 0x800F5778: swc1        $f0, 0x18($s3)
        MEM_W(0X18, ctx->r19) = ctx->f0.u32l;
            goto L_800F583C;
    }
    // 0x800F5778: swc1        $f0, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->f0.u32l;
    // 0x800F577C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800F5780: nop

    // 0x800F5784: bc1fl       L_800F5840
    if (!c1cs) {
        // 0x800F5788: sb          $zero, 0x35($s3)
        MEM_B(0X35, ctx->r19) = 0;
            goto L_800F5840;
    }
    goto skip_3;
    // 0x800F5788: sb          $zero, 0x35($s3)
    MEM_B(0X35, ctx->r19) = 0;
    skip_3:
    // 0x800F578C: jal         0x80003430
    // 0x800F5790: nop

    rand_recomp(rdram, ctx);
        goto after_9;
    // 0x800F5790: nop

    after_9:
    // 0x800F5794: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800F5798: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800F579C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800F57A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F57A4: lwc1        $f20, -0x7334($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7334);
    // 0x800F57A8: lwc1        $f0, 0x28($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X28);
    // 0x800F57AC: sub.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f20.fl;
    // 0x800F57B0: div.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800F57B4: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F57B8: abs.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = fabsf(ctx->f2.fl);
    // 0x800F57BC: lwc1        $f0, 0x24($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X24);
    // 0x800F57C0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F57C4: jal         0x80003430
    // 0x800F57C8: swc1        $f0, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_10;
    // 0x800F57C8: swc1        $f0, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->f0.u32l;
    after_10:
    // 0x800F57CC: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800F57D0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F57D4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F57D8: lwc1        $f2, 0x20($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X20);
    // 0x800F57DC: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800F57E0: div.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x800F57E4: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800F57E8: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x800F57EC: lwc1        $f0, 0x1C($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X1C);
    // 0x800F57F0: jal         0x80003430
    // 0x800F57F4: add.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f0.fl + ctx->f2.fl;
    rand_recomp(rdram, ctx);
        goto after_11;
    // 0x800F57F4: add.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f0.fl + ctx->f2.fl;
    after_11:
    // 0x800F57F8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800F57FC: bne         $v0, $zero, L_800F5808
    if (ctx->r2 != 0) {
        // 0x800F5800: mov.s       $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
            goto L_800F5808;
    }
    // 0x800F5800: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x800F5804: neg.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = -ctx->f20.fl;
L_800F5808:
    // 0x800F5808: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x800F580C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F5810: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800F5814: jal         0x8001D240
    // 0x800F5818: addiu       $a1, $s4, 0x18
    ctx->r5 = ADD32(ctx->r20, 0X18);
    quatFromAxisAngle(rdram, ctx);
        goto after_12;
    // 0x800F5818: addiu       $a1, $s4, 0x18
    ctx->r5 = ADD32(ctx->r20, 0X18);
    after_12:
    // 0x800F581C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F5820: addiu       $a1, $s4, 0xC
    ctx->r5 = ADD32(ctx->r20, 0XC);
    // 0x800F5824: jal         0x8001D3C4
    // 0x800F5828: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_13;
    // 0x800F5828: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_13:
    // 0x800F582C: lwc1        $f0, 0x2C($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X2C);
    // 0x800F5830: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F5834: sb          $v0, 0x34($s3)
    MEM_B(0X34, ctx->r19) = ctx->r2;
    // 0x800F5838: swc1        $f0, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f0.u32l;
L_800F583C:
    // 0x800F583C: sb          $zero, 0x35($s3)
    MEM_B(0X35, ctx->r19) = 0;
L_800F5840:
    // 0x800F5840: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x800F5844: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5848: lwc1        $f0, -0x7330($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7330);
    // 0x800F584C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F5850: lhu         $v0, 0x110($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X110);
    // 0x800F5854: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800F5858: mul.s       $f22, $f2, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x800F585C: beq         $v0, $zero, L_800F5870
    if (ctx->r2 == 0) {
        // 0x800F5860: nop
    
            goto L_800F5870;
    }
    // 0x800F5860: nop

    // 0x800F5864: sw          $zero, 0x4($s3)
    MEM_W(0X4, ctx->r19) = 0;
    // 0x800F5868: jal         0x8001CF58
    // 0x800F586C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    normalize_vector(rdram, ctx);
        goto after_14;
    // 0x800F586C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_14:
L_800F5870:
    // 0x800F5870: lbu         $v0, 0x34($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X34);
    // 0x800F5874: beq         $v0, $zero, L_800F5970
    if (ctx->r2 == 0) {
        // 0x800F5878: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_800F5970;
    }
    // 0x800F5878: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800F587C: addiu       $s1, $s4, 0xC
    ctx->r17 = ADD32(ctx->r20, 0XC);
    // 0x800F5880: jal         0x8001CFE8
    // 0x800F5884: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    vec3Dot(rdram, ctx);
        goto after_15;
    // 0x800F5884: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_15:
    // 0x800F5888: jal         0x8001C5CC
    // 0x800F588C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    constMinusSinfApprox(rdram, ctx);
        goto after_16;
    // 0x800F588C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_16:
    // 0x800F5890: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5894: lwc1        $f2, -0x732C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X732C);
    // 0x800F5898: mul.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F589C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F58A0: lwc1        $f0, -0x7328($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7328);
    // 0x800F58A4: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800F58A8: nop

    // 0x800F58AC: bc1f        L_800F594C
    if (!c1cs) {
        // 0x800F58B0: addiu       $s2, $sp, 0x50
        ctx->r18 = ADD32(ctx->r29, 0X50);
            goto L_800F594C;
    }
    // 0x800F58B0: addiu       $s2, $sp, 0x50
    ctx->r18 = ADD32(ctx->r29, 0X50);
    // 0x800F58B4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F58B8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800F58BC: jal         0x80019548
    // 0x800F58C0: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    vec3Cross(rdram, ctx);
        goto after_17;
    // 0x800F58C0: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_17:
    // 0x800F58C4: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x800F58C8: nop

    // 0x800F58CC: bc1tl       L_800F58D4
    if (c1cs) {
        // 0x800F58D0: mov.s       $f20, $f22
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
            goto L_800F58D4;
    }
    goto skip_4;
    // 0x800F58D0: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    skip_4:
L_800F58D4:
    // 0x800F58D4: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x800F58D8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F58DC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800F58E0: jal         0x8001D144
    // 0x800F58E4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    quatFromAxisAngleSafe(rdram, ctx);
        goto after_18;
    // 0x800F58E4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_18:
    // 0x800F58E8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F58EC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800F58F0: addiu       $s1, $sp, 0x20
    ctx->r17 = ADD32(ctx->r29, 0X20);
    // 0x800F58F4: jal         0x8001D3C4
    // 0x800F58F8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_19;
    // 0x800F58F8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_19:
    // 0x800F58FC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F5900: addiu       $a1, $s4, 0x18
    ctx->r5 = ADD32(ctx->r20, 0X18);
    // 0x800F5904: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800F5908: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800F590C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800F5910: sw          $t0, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r8;
    // 0x800F5914: sw          $t1, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->r9;
    // 0x800F5918: sw          $t2, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->r10;
    // 0x800F591C: jal         0x8001D3C4
    // 0x800F5920: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_20;
    // 0x800F5920: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_20:
    // 0x800F5924: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800F5928: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800F592C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800F5930: sw          $t0, 0x18($s4)
    MEM_W(0X18, ctx->r20) = ctx->r8;
    // 0x800F5934: sw          $t1, 0x1C($s4)
    MEM_W(0X1C, ctx->r20) = ctx->r9;
    // 0x800F5938: sw          $t2, 0x20($s4)
    MEM_W(0X20, ctx->r20) = ctx->r10;
    // 0x800F593C: jal         0x80059F10
    // 0x800F5940: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    orthonormalizeFrame(rdram, ctx);
        goto after_21;
    // 0x800F5940: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_21:
    // 0x800F5944: j           L_800F5970
    // 0x800F5948: nop

        goto L_800F5970;
    // 0x800F5948: nop

L_800F594C:
    // 0x800F594C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F5950: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x800F5954: lw          $t1, 0x4($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X4);
    // 0x800F5958: lw          $t2, 0x8($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X8);
    // 0x800F595C: sw          $t0, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r8;
    // 0x800F5960: sw          $t1, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->r9;
    // 0x800F5964: sw          $t2, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->r10;
    // 0x800F5968: sb          $zero, 0x34($s3)
    MEM_B(0X34, ctx->r19) = 0;
    // 0x800F596C: sb          $v0, 0x35($s3)
    MEM_B(0X35, ctx->r19) = ctx->r2;
L_800F5970:
    // 0x800F5970: lwc1        $f0, 0xC($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XC);
    // 0x800F5974: lwc1        $f2, 0x14($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X14);
    // 0x800F5978: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F597C: swc1        $f0, 0x24($s4)
    MEM_W(0X24, ctx->r20) = ctx->f0.u32l;
    // 0x800F5980: lwc1        $f0, 0x10($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X10);
    // 0x800F5984: lwc1        $f2, 0x14($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X14);
    // 0x800F5988: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F598C: lwc1        $f2, 0x14($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X14);
    // 0x800F5990: swc1        $f0, 0x28($s4)
    MEM_W(0X28, ctx->r20) = ctx->f0.u32l;
    // 0x800F5994: lwc1        $f0, 0x14($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X14);
    // 0x800F5998: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F599C: lwc1        $f8, 0x28($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X28);
    // 0x800F59A0: mul.s       $f8, $f8, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x800F59A4: lwc1        $f0, 0x24($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X24);
    // 0x800F59A8: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800F59AC: swc1        $f2, 0x2C($s4)
    MEM_W(0X2C, ctx->r20) = ctx->f2.u32l;
    // 0x800F59B0: mov.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.fl = ctx->f2.fl;
    // 0x800F59B4: mul.s       $f6, $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x800F59B8: lwc1        $f4, 0x0($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X0);
    // 0x800F59BC: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800F59C0: lwc1        $f2, 0x4($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X4);
    // 0x800F59C4: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x800F59C8: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x800F59CC: add.s       $f14, $f0, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800F59D0: swc1        $f4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f4.u32l;
    // 0x800F59D4: swc1        $f2, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->f2.u32l;
    // 0x800F59D8: swc1        $f14, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->f14.u32l;
    // 0x800F59DC: lhu         $v0, 0x110($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X110);
    // 0x800F59E0: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800F59E4: beq         $v0, $zero, L_800F5A00
    if (ctx->r2 == 0) {
        // 0x800F59E8: lui         $a2, 0x8014
        ctx->r6 = S32(0X8014 << 16);
            goto L_800F5A00;
    }
    // 0x800F59E8: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800F59EC: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x800F59F0: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
    // 0x800F59F4: jal         0x80067D90
    // 0x800F59F8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    wrapAngleToCyclicRange(rdram, ctx);
        goto after_22;
    // 0x800F59F8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_22:
    // 0x800F59FC: swc1        $f0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->f0.u32l;
L_800F5A00:
    // 0x800F5A00: lw          $ra, 0x78($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X78);
    // 0x800F5A04: lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X74);
    // 0x800F5A08: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x800F5A0C: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x800F5A10: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x800F5A14: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x800F5A18: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x800F5A1C: ldc1        $f24, 0x90($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X90);
    // 0x800F5A20: ldc1        $f22, 0x88($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X88);
    // 0x800F5A24: ldc1        $f20, 0x80($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X80);
    // 0x800F5A28: jr          $ra
    // 0x800F5A2C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800F5A2C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void initActorAsType4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5A30: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F5A34: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800F5A38: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800F5A3C: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x800F5A40: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800F5A44: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x800F5A48: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800F5A4C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800F5A50: addiu       $s0, $s1, 0x8
    ctx->r16 = ADD32(ctx->r17, 0X8);
    // 0x800F5A54: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800F5A58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F5A5C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800F5A60: sb          $v0, 0x112($s1)
    MEM_B(0X112, ctx->r17) = ctx->r2;
    // 0x800F5A64: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800F5A68: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x800F5A6C: beq         $v0, $zero, L_800F5B78
    if (ctx->r2 == 0) {
        // 0x800F5A70: addiu       $s2, $s1, 0x50
        ctx->r18 = ADD32(ctx->r17, 0X50);
            goto L_800F5B78;
    }
    // 0x800F5A70: addiu       $s2, $s1, 0x50
    ctx->r18 = ADD32(ctx->r17, 0X50);
    // 0x800F5A74: jal         0x80047B48
    // 0x800F5A78: nop

    getLevelDatItemByName(rdram, ctx);
        goto after_0;
    // 0x800F5A78: nop

    after_0:
    // 0x800F5A7C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800F5A80: beq         $v1, $zero, L_800F5B78
    if (ctx->r3 == 0) {
        // 0x800F5A84: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_800F5B78;
    }
    // 0x800F5A84: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800F5A88: lbu         $a0, 0x2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2);
    // 0x800F5A8C: beq         $a0, $v0, L_800F5AA4
    if (ctx->r4 == ctx->r2) {
        // 0x800F5A90: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_800F5AA4;
    }
    // 0x800F5A90: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800F5A94: beq         $a0, $v0, L_800F5B24
    if (ctx->r4 == ctx->r2) {
        // 0x800F5A98: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800F5B24;
    }
    // 0x800F5A98: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800F5A9C: j           L_800F5B78
    // 0x800F5AA0: nop

        goto L_800F5B78;
    // 0x800F5AA0: nop

L_800F5AA4:
    // 0x800F5AA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F5AA8: sh          $v0, 0xEC($s0)
    MEM_H(0XEC, ctx->r16) = ctx->r2;
    // 0x800F5AAC: lw          $t0, 0x10($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10);
    // 0x800F5AB0: lw          $t1, 0x14($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X14);
    // 0x800F5AB4: lw          $t2, 0x18($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X18);
    // 0x800F5AB8: sw          $t0, 0xD0($s1)
    MEM_W(0XD0, ctx->r17) = ctx->r8;
    // 0x800F5ABC: sw          $t1, 0xD4($s1)
    MEM_W(0XD4, ctx->r17) = ctx->r9;
    // 0x800F5AC0: sw          $t2, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->r10;
    // 0x800F5AC4: lw          $t0, 0x28($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X28);
    // 0x800F5AC8: lw          $t1, 0x2C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X2C);
    // 0x800F5ACC: lw          $t2, 0x30($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X30);
    // 0x800F5AD0: sw          $t0, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->r8;
    // 0x800F5AD4: sw          $t1, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->r9;
    // 0x800F5AD8: sw          $t2, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->r10;
    // 0x800F5ADC: lwc1        $f2, 0x28($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X28);
    // 0x800F5AE0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5AE4: lwc1        $f4, -0x7324($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7324);
    // 0x800F5AE8: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800F5AEC: lwc1        $f0, 0x10($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800F5AF0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F5AF4: swc1        $f0, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f0.u32l;
    // 0x800F5AF8: lwc1        $f2, 0x2C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x800F5AFC: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800F5B00: lwc1        $f0, 0x14($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X14);
    // 0x800F5B04: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F5B08: swc1        $f0, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f0.u32l;
    // 0x800F5B0C: lwc1        $f2, 0x30($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X30);
    // 0x800F5B10: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800F5B14: lwc1        $f0, 0x18($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X18);
    // 0x800F5B18: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F5B1C: j           L_800F5BB8
    // 0x800F5B20: swc1        $f0, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f0.u32l;
        goto L_800F5BB8;
    // 0x800F5B20: swc1        $f0, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f0.u32l;
L_800F5B24:
    // 0x800F5B24: sh          $v0, 0xEC($s0)
    MEM_H(0XEC, ctx->r16) = ctx->r2;
    // 0x800F5B28: lw          $t0, 0x10($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10);
    // 0x800F5B2C: lw          $t1, 0x14($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X14);
    // 0x800F5B30: lw          $t2, 0x18($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X18);
    // 0x800F5B34: sw          $t0, 0xD0($s1)
    MEM_W(0XD0, ctx->r17) = ctx->r8;
    // 0x800F5B38: sw          $t1, 0xD4($s1)
    MEM_W(0XD4, ctx->r17) = ctx->r9;
    // 0x800F5B3C: sw          $t2, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->r10;
    // 0x800F5B40: lwc1        $f0, 0x1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x800F5B44: swc1        $f0, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f0.u32l;
    // 0x800F5B48: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800F5B4C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5B50: lwc1        $f0, -0x7320($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7320);
    // 0x800F5B54: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F5B58: lwc1        $f6, 0xC8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x800F5B5C: lwc1        $f0, 0xCC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XCC);
    // 0x800F5B60: lwc1        $f4, 0xD0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x800F5B64: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F5B68: swc1        $f6, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f6.u32l;
    // 0x800F5B6C: swc1        $f4, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f4.u32l;
    // 0x800F5B70: j           L_800F5BB8
    // 0x800F5B74: swc1        $f0, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f0.u32l;
        goto L_800F5BB8;
    // 0x800F5B74: swc1        $f0, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f0.u32l;
L_800F5B78:
    // 0x800F5B78: lhu         $a0, 0x198($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X198);
    // 0x800F5B7C: jal         0x8004015C
    // 0x800F5B80: nop

    getNpcContextField8(rdram, ctx);
        goto after_1;
    // 0x800F5B80: nop

    after_1:
    // 0x800F5B84: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800F5B88: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x800F5B8C: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x800F5B90: sw          $t0, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->r8;
    // 0x800F5B94: sw          $t1, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->r9;
    // 0x800F5B98: sw          $t2, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->r10;
    // 0x800F5B9C: lw          $t0, 0xD4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XD4);
    // 0x800F5BA0: lw          $t1, 0xD8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XD8);
    // 0x800F5BA4: lw          $t2, 0xDC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XDC);
    // 0x800F5BA8: sw          $t0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->r8;
    // 0x800F5BAC: sw          $t1, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->r9;
    // 0x800F5BB0: sw          $t2, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->r10;
    // 0x800F5BB4: sh          $zero, 0xEC($s0)
    MEM_H(0XEC, ctx->r16) = 0;
L_800F5BB8:
    // 0x800F5BB8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5BBC: lwc1        $f2, -0x731C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X731C);
    // 0x800F5BC0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5BC4: lwc1        $f10, -0x7318($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7318);
    // 0x800F5BC8: lw          $t0, 0xD4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XD4);
    // 0x800F5BCC: lw          $t1, 0xD8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XD8);
    // 0x800F5BD0: lw          $t2, 0xDC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XDC);
    // 0x800F5BD4: sw          $t0, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->r8;
    // 0x800F5BD8: sw          $t1, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->r9;
    // 0x800F5BDC: sw          $t2, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->r10;
    // 0x800F5BE0: sw          $zero, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = 0;
    // 0x800F5BE4: sw          $zero, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = 0;
    // 0x800F5BE8: sw          $zero, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = 0;
    // 0x800F5BEC: sw          $zero, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = 0;
    // 0x800F5BF0: sw          $zero, 0xBC($s0)
    MEM_W(0XBC, ctx->r16) = 0;
    // 0x800F5BF4: sw          $zero, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = 0;
    // 0x800F5BF8: sw          $zero, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = 0;
    // 0x800F5BFC: sb          $zero, 0x96($s0)
    MEM_B(0X96, ctx->r16) = 0;
    // 0x800F5C00: swc1        $f22, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f22.u32l;
    // 0x800F5C04: swc1        $f22, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f22.u32l;
    // 0x800F5C08: swc1        $f22, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f22.u32l;
    // 0x800F5C0C: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x800F5C10: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x800F5C14: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x800F5C18: swc1        $f10, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f10.u32l;
    // 0x800F5C1C: bc1f        L_800F5C28
    if (!c1cs) {
        // 0x800F5C20: swc1        $f10, 0xB4($s0)
        MEM_W(0XB4, ctx->r16) = ctx->f10.u32l;
            goto L_800F5C28;
    }
    // 0x800F5C20: swc1        $f10, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f10.u32l;
    // 0x800F5C24: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
L_800F5C28:
    // 0x800F5C28: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5C2C: lwc1        $f0, -0x7314($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7314);
    // 0x800F5C30: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800F5C34: nop

    // 0x800F5C38: bc1tl       L_800F5C40
    if (c1cs) {
        // 0x800F5C3C: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_800F5C40;
    }
    goto skip_0;
    // 0x800F5C3C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_0:
L_800F5C40:
    // 0x800F5C40: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800F5C44: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F5C48: div.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F5C4C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5C50: lwc1        $f2, -0x7310($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7310);
    // 0x800F5C54: sub.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800F5C58: swc1        $f20, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f20.u32l;
    // 0x800F5C5C: swc1        $f20, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f20.u32l;
    // 0x800F5C60: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800F5C64: nop

    // 0x800F5C68: bc1f        L_800F5C74
    if (!c1cs) {
        // 0x800F5C6C: swc1        $f0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
            goto L_800F5C74;
    }
    // 0x800F5C6C: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x800F5C70: swc1        $f2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f2.u32l;
L_800F5C74:
    // 0x800F5C74: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5C78: lwc1        $f2, -0x730C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X730C);
    // 0x800F5C7C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5C80: lwc1        $f4, -0x7308($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7308);
    // 0x800F5C84: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5C88: lwc1        $f6, -0x7304($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7304);
    // 0x800F5C8C: swc1        $f2, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f2.u32l;
    // 0x800F5C90: swc1        $f2, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f2.u32l;
    // 0x800F5C94: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5C98: lwc1        $f2, -0x7300($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7300);
    // 0x800F5C9C: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800F5CA0: sw          $zero, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = 0;
    // 0x800F5CA4: sh          $zero, 0xF2($s0)
    MEM_H(0XF2, ctx->r16) = 0;
    // 0x800F5CA8: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x800F5CAC: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x800F5CB0: swc1        $f6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f6.u32l;
    // 0x800F5CB4: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x800F5CB8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F5CBC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5CC0: lwc1        $f2, -0x72FC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X72FC);
    // 0x800F5CC4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800F5CC8: nop

    // 0x800F5CCC: bc1f        L_800F5CD8
    if (!c1cs) {
        // 0x800F5CD0: swc1        $f0, 0x8($s2)
        MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
            goto L_800F5CD8;
    }
    // 0x800F5CD0: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
    // 0x800F5CD4: swc1        $f10, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f10.u32l;
L_800F5CD8:
    // 0x800F5CD8: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x800F5CDC: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800F5CE0: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800F5CE4: nop

    // 0x800F5CE8: bc1f        L_800F5CFC
    if (!c1cs) {
        // 0x800F5CEC: swc1        $f0, 0xC($s2)
        MEM_W(0XC, ctx->r18) = ctx->f0.u32l;
            goto L_800F5CFC;
    }
    // 0x800F5CEC: swc1        $f0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f0.u32l;
    // 0x800F5CF0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5CF4: lwc1        $f0, -0x72F8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X72F8);
    // 0x800F5CF8: swc1        $f0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f0.u32l;
L_800F5CFC:
    // 0x800F5CFC: addiu       $a0, $s2, 0x10
    ctx->r4 = ADD32(ctx->r18, 0X10);
    // 0x800F5D00: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800F5D04: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x800F5D08: jal         0x800078E0
    // 0x800F5D0C: sw          $zero, 0x100($s0)
    MEM_W(0X100, ctx->r16) = 0;
    rs_memset(rdram, ctx);
        goto after_2;
    // 0x800F5D0C: sw          $zero, 0x100($s0)
    MEM_W(0X100, ctx->r16) = 0;
    after_2:
    // 0x800F5D10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F5D14: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800F5D18: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800F5D1C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800F5D20: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800F5D24: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800F5D28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F5D2C: jr          $ra
    // 0x800F5D30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800F5D30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800F5D34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5D34: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800F5D38: sdc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X50, ctx->r29);
    // 0x800F5D3C: mtc1        $a2, $f24
    ctx->f24.u32l = ctx->r6;
    // 0x800F5D40: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800F5D44: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800F5D48: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800F5D4C: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x800F5D50: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800F5D54: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // 0x800F5D58: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800F5D5C: sdc1        $f26, 0x58($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X58, ctx->r29);
    // 0x800F5D60: sdc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X48, ctx->r29);
    // 0x800F5D64: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x800F5D68: lwc1        $f20, 0x8($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800F5D6C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5D70: lwc1        $f0, -0x72F4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X72F4);
    // 0x800F5D74: lwc1        $f12, 0x8($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800F5D78: jal         0x8001C400
    // 0x800F5D7C: div.s       $f22, $f0, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    sinfApprox(rdram, ctx);
        goto after_0;
    // 0x800F5D7C: div.s       $f22, $f0, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    after_0:
    // 0x800F5D80: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5D84: lwc1        $f26, -0x72F0($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X72F0);
    // 0x800F5D88: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5D8C: lwc1        $f2, -0x72EC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X72EC);
    // 0x800F5D90: div.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f26.fl);
    // 0x800F5D94: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800F5D98: mul.s       $f2, $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x800F5D9C: add.s       $f0, $f24, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f24.fl + ctx->f2.fl;
    // 0x800F5DA0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800F5DA4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800F5DA8: nop

    // 0x800F5DAC: bc1f        L_800F5DB8
    if (!c1cs) {
        // 0x800F5DB0: swc1        $f0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
            goto L_800F5DB8;
    }
    // 0x800F5DB0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800F5DB4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
L_800F5DB8:
    // 0x800F5DB8: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F5DBC: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800F5DC0: nop

    // 0x800F5DC4: bc1tl       L_800F5DCC
    if (c1cs) {
        // 0x800F5DC8: swc1        $f20, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
            goto L_800F5DCC;
    }
    goto skip_0;
    // 0x800F5DC8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    skip_0:
L_800F5DCC:
    // 0x800F5DCC: sub.s       $f0, $f24, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f2.fl;
    // 0x800F5DD0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800F5DD4: nop

    // 0x800F5DD8: bc1f        L_800F5DE4
    if (!c1cs) {
        // 0x800F5DDC: swc1        $f0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
            goto L_800F5DE4;
    }
    // 0x800F5DDC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800F5DE0: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
L_800F5DE4:
    // 0x800F5DE4: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F5DE8: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800F5DEC: nop

    // 0x800F5DF0: bc1tl       L_800F5DF8
    if (c1cs) {
        // 0x800F5DF4: swc1        $f20, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
            goto L_800F5DF8;
    }
    goto skip_1;
    // 0x800F5DF4: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    skip_1:
L_800F5DF8:
    // 0x800F5DF8: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800F5DFC: jal         0x8001C400
    // 0x800F5E00: nop

    sinfApprox(rdram, ctx);
        goto after_1;
    // 0x800F5E00: nop

    after_1:
    // 0x800F5E04: sub.s       $f2, $f20, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x800F5E08: div.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f26.fl);
    // 0x800F5E0C: mul.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F5E10: add.s       $f0, $f24, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f24.fl + ctx->f2.fl;
    // 0x800F5E14: sub.s       $f2, $f24, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f24.fl - ctx->f2.fl;
    // 0x800F5E18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F5E1C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800F5E20: beq         $s1, $v0, L_800F61B8
    if (ctx->r17 == ctx->r2) {
        // 0x800F5E24: swc1        $f2, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
            goto L_800F61B8;
    }
    // 0x800F5E24: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x800F5E28: slti        $v0, $s1, 0x2
    ctx->r2 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // 0x800F5E2C: beql        $v0, $zero, L_800F5E44
    if (ctx->r2 == 0) {
        // 0x800F5E30: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800F5E44;
    }
    goto skip_2;
    // 0x800F5E30: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_2:
    // 0x800F5E34: beq         $s1, $zero, L_800F5E54
    if (ctx->r17 == 0) {
        // 0x800F5E38: nop
    
            goto L_800F5E54;
    }
    // 0x800F5E38: nop

    // 0x800F5E3C: j           L_800F692C
    // 0x800F5E40: nop

        goto L_800F692C;
    // 0x800F5E40: nop

L_800F5E44:
    // 0x800F5E44: beq         $s1, $v0, L_800F6574
    if (ctx->r17 == ctx->r2) {
        // 0x800F5E48: nop
    
            goto L_800F6574;
    }
    // 0x800F5E48: nop

    // 0x800F5E4C: j           L_800F692C
    // 0x800F5E50: nop

        goto L_800F692C;
    // 0x800F5E50: nop

L_800F5E54:
    // 0x800F5E54: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F5E58: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F5E5C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5E60: lwc1        $f2, -0x72E8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X72E8);
    // 0x800F5E64: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F5E68: nop

    // 0x800F5E6C: bc1tl       L_800F5E84
    if (c1cs) {
        // 0x800F5E70: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F5E84;
    }
    goto skip_3;
    // 0x800F5E70: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_3:
    // 0x800F5E74: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F5E78: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F5E7C: j           L_800F5E98
    // 0x800F5E80: sb          $v1, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r3;
        goto L_800F5E98;
    // 0x800F5E80: sb          $v1, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r3;
L_800F5E84:
    // 0x800F5E84: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F5E88: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F5E8C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F5E90: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F5E94: sb          $v1, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r3;
L_800F5E98:
    // 0x800F5E98: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F5E9C: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F5EA0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5EA4: lwc1        $f2, -0x72E4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X72E4);
    // 0x800F5EA8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F5EAC: nop

    // 0x800F5EB0: bc1tl       L_800F5EC8
    if (c1cs) {
        // 0x800F5EB4: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F5EC8;
    }
    goto skip_4;
    // 0x800F5EB4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_4:
    // 0x800F5EB8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F5EBC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F5EC0: j           L_800F5EDC
    // 0x800F5EC4: sb          $v1, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = ctx->r3;
        goto L_800F5EDC;
    // 0x800F5EC4: sb          $v1, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = ctx->r3;
L_800F5EC8:
    // 0x800F5EC8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F5ECC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F5ED0: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F5ED4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F5ED8: sb          $v1, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = ctx->r3;
L_800F5EDC:
    // 0x800F5EDC: lbu         $v1, 0x14($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X14);
    // 0x800F5EE0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800F5EE4: bne         $v1, $v0, L_800F5F14
    if (ctx->r3 != ctx->r2) {
        // 0x800F5EE8: nop
    
            goto L_800F5F14;
    }
    // 0x800F5EE8: nop

    // 0x800F5EEC: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F5EF0: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F5EF4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5EF8: lwc1        $f2, -0x72E0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X72E0);
    // 0x800F5EFC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F5F00: nop

    // 0x800F5F04: bc1f        L_800F5F54
    if (!c1cs) {
        // 0x800F5F08: nop
    
            goto L_800F5F54;
    }
    // 0x800F5F08: nop

    // 0x800F5F0C: j           L_800F5F64
    // 0x800F5F10: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_800F5F64;
    // 0x800F5F10: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_800F5F14:
    // 0x800F5F14: lbu         $v0, 0x14($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X14);
    // 0x800F5F18: lbu         $v1, 0x1A($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1A);
    // 0x800F5F1C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F5F20: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F5F24: mtc1        $v1, $f2
    ctx->f2.u32l = ctx->r3;
    // 0x800F5F28: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800F5F2C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F5F30: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5F34: lwc1        $f2, -0x72DC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X72DC);
    // 0x800F5F38: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F5F3C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5F40: lwc1        $f2, -0x72D8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X72D8);
    // 0x800F5F44: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F5F48: nop

    // 0x800F5F4C: bc1tl       L_800F5F64
    if (c1cs) {
        // 0x800F5F50: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F5F64;
    }
    goto skip_5;
    // 0x800F5F50: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_5:
L_800F5F54:
    // 0x800F5F54: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F5F58: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F5F5C: j           L_800F5F78
    // 0x800F5F60: sb          $v1, 0x17($s0)
    MEM_B(0X17, ctx->r16) = ctx->r3;
        goto L_800F5F78;
    // 0x800F5F60: sb          $v1, 0x17($s0)
    MEM_B(0X17, ctx->r16) = ctx->r3;
L_800F5F64:
    // 0x800F5F64: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F5F68: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F5F6C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F5F70: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F5F74: sb          $v1, 0x17($s0)
    MEM_B(0X17, ctx->r16) = ctx->r3;
L_800F5F78:
    // 0x800F5F78: lbu         $v1, 0x20($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X20);
    // 0x800F5F7C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800F5F80: bne         $v1, $v0, L_800F5FB0
    if (ctx->r3 != ctx->r2) {
        // 0x800F5F84: nop
    
            goto L_800F5FB0;
    }
    // 0x800F5F84: nop

    // 0x800F5F88: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F5F8C: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F5F90: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5F94: lwc1        $f2, -0x72D4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X72D4);
    // 0x800F5F98: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F5F9C: nop

    // 0x800F5FA0: bc1f        L_800F5FF0
    if (!c1cs) {
        // 0x800F5FA4: nop
    
            goto L_800F5FF0;
    }
    // 0x800F5FA4: nop

    // 0x800F5FA8: j           L_800F6000
    // 0x800F5FAC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_800F6000;
    // 0x800F5FAC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_800F5FB0:
    // 0x800F5FB0: lbu         $v0, 0x20($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X20);
    // 0x800F5FB4: lbu         $v1, 0x1A($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1A);
    // 0x800F5FB8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F5FBC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F5FC0: mtc1        $v1, $f2
    ctx->f2.u32l = ctx->r3;
    // 0x800F5FC4: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800F5FC8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F5FCC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5FD0: lwc1        $f2, -0x72D0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X72D0);
    // 0x800F5FD4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F5FD8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F5FDC: lwc1        $f2, -0x72CC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X72CC);
    // 0x800F5FE0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F5FE4: nop

    // 0x800F5FE8: bc1tl       L_800F6000
    if (c1cs) {
        // 0x800F5FEC: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F6000;
    }
    goto skip_6;
    // 0x800F5FEC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_6:
L_800F5FF0:
    // 0x800F5FF0: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F5FF4: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F5FF8: j           L_800F6014
    // 0x800F5FFC: sb          $v1, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r3;
        goto L_800F6014;
    // 0x800F5FFC: sb          $v1, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r3;
L_800F6000:
    // 0x800F6000: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F6004: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6008: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F600C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F6010: sb          $v1, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r3;
L_800F6014:
    // 0x800F6014: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F6018: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F601C: div.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800F6020: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F6024: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x800F6028: nop

    // 0x800F602C: bc1f        L_800F6038
    if (!c1cs) {
        // 0x800F6030: swc1        $f2, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
            goto L_800F6038;
    }
    // 0x800F6030: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x800F6034: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
L_800F6038:
    // 0x800F6038: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800F603C: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F6040: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6044: lwc1        $f2, -0x72C8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X72C8);
    // 0x800F6048: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F604C: nop

    // 0x800F6050: bc1tl       L_800F6068
    if (c1cs) {
        // 0x800F6054: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F6068;
    }
    goto skip_7;
    // 0x800F6054: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_7:
    // 0x800F6058: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F605C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6060: j           L_800F607C
    // 0x800F6064: sb          $v1, 0x16($s0)
    MEM_B(0X16, ctx->r16) = ctx->r3;
        goto L_800F607C;
    // 0x800F6064: sb          $v1, 0x16($s0)
    MEM_B(0X16, ctx->r16) = ctx->r3;
L_800F6068:
    // 0x800F6068: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F606C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6070: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6074: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F6078: sb          $v1, 0x16($s0)
    MEM_B(0X16, ctx->r16) = ctx->r3;
L_800F607C:
    // 0x800F607C: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F6080: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F6084: div.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800F6088: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F608C: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x800F6090: nop

    // 0x800F6094: bc1f        L_800F60A0
    if (!c1cs) {
        // 0x800F6098: swc1        $f2, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
            goto L_800F60A0;
    }
    // 0x800F6098: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800F609C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
L_800F60A0:
    // 0x800F60A0: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800F60A4: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F60A8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F60AC: lwc1        $f2, -0x72C4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X72C4);
    // 0x800F60B0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F60B4: nop

    // 0x800F60B8: bc1tl       L_800F60D0
    if (c1cs) {
        // 0x800F60BC: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F60D0;
    }
    goto skip_8;
    // 0x800F60BC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_8:
    // 0x800F60C0: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F60C4: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F60C8: j           L_800F60E4
    // 0x800F60CC: sb          $v1, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r3;
        goto L_800F60E4;
    // 0x800F60CC: sb          $v1, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r3;
L_800F60D0:
    // 0x800F60D0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F60D4: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F60D8: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F60DC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F60E0: sb          $v1, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r3;
L_800F60E4:
    // 0x800F60E4: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F60E8: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F60EC: div.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800F60F0: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F60F4: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x800F60F8: nop

    // 0x800F60FC: bc1f        L_800F6108
    if (!c1cs) {
        // 0x800F6100: swc1        $f2, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
            goto L_800F6108;
    }
    // 0x800F6100: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x800F6104: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
L_800F6108:
    // 0x800F6108: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F610C: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F6110: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6114: lwc1        $f2, -0x72C0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X72C0);
    // 0x800F6118: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F611C: nop

    // 0x800F6120: bc1tl       L_800F6138
    if (c1cs) {
        // 0x800F6124: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F6138;
    }
    goto skip_9;
    // 0x800F6124: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_9:
    // 0x800F6128: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F612C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6130: j           L_800F614C
    // 0x800F6134: sb          $v1, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r3;
        goto L_800F614C;
    // 0x800F6134: sb          $v1, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r3;
L_800F6138:
    // 0x800F6138: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F613C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6140: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6144: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F6148: sb          $v1, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r3;
L_800F614C:
    // 0x800F614C: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F6150: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F6154: div.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800F6158: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F615C: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x800F6160: nop

    // 0x800F6164: bc1f        L_800F6170
    if (!c1cs) {
        // 0x800F6168: swc1        $f2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
            goto L_800F6170;
    }
    // 0x800F6168: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x800F616C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
L_800F6170:
    // 0x800F6170: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F6174: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F6178: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F617C: lwc1        $f2, -0x72BC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X72BC);
    // 0x800F6180: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6184: nop

    // 0x800F6188: bc1tl       L_800F61A0
    if (c1cs) {
        // 0x800F618C: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F61A0;
    }
    goto skip_10;
    // 0x800F618C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_10:
    // 0x800F6190: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6194: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6198: j           L_800F692C
    // 0x800F619C: sb          $v1, 0x1E($s0)
    MEM_B(0X1E, ctx->r16) = ctx->r3;
        goto L_800F692C;
    // 0x800F619C: sb          $v1, 0x1E($s0)
    MEM_B(0X1E, ctx->r16) = ctx->r3;
L_800F61A0:
    // 0x800F61A0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F61A4: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F61A8: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F61AC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F61B0: j           L_800F692C
    // 0x800F61B4: sb          $v1, 0x1E($s0)
    MEM_B(0X1E, ctx->r16) = ctx->r3;
        goto L_800F692C;
    // 0x800F61B4: sb          $v1, 0x1E($s0)
    MEM_B(0X1E, ctx->r16) = ctx->r3;
L_800F61B8:
    // 0x800F61B8: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F61BC: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F61C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F61C4: lwc1        $f2, -0x72B8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X72B8);
    // 0x800F61C8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F61CC: nop

    // 0x800F61D0: bc1tl       L_800F61E8
    if (c1cs) {
        // 0x800F61D4: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F61E8;
    }
    goto skip_11;
    // 0x800F61D4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_11:
    // 0x800F61D8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F61DC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F61E0: j           L_800F61FC
    // 0x800F61E4: sb          $v1, 0x13($s0)
    MEM_B(0X13, ctx->r16) = ctx->r3;
        goto L_800F61FC;
    // 0x800F61E4: sb          $v1, 0x13($s0)
    MEM_B(0X13, ctx->r16) = ctx->r3;
L_800F61E8:
    // 0x800F61E8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F61EC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F61F0: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F61F4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F61F8: sb          $v1, 0x13($s0)
    MEM_B(0X13, ctx->r16) = ctx->r3;
L_800F61FC:
    // 0x800F61FC: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F6200: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F6204: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6208: lwc1        $f2, -0x72B4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X72B4);
    // 0x800F620C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6210: nop

    // 0x800F6214: bc1tl       L_800F622C
    if (c1cs) {
        // 0x800F6218: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F622C;
    }
    goto skip_12;
    // 0x800F6218: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_12:
    // 0x800F621C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6220: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6224: j           L_800F6240
    // 0x800F6228: sb          $v1, 0x15($s0)
    MEM_B(0X15, ctx->r16) = ctx->r3;
        goto L_800F6240;
    // 0x800F6228: sb          $v1, 0x15($s0)
    MEM_B(0X15, ctx->r16) = ctx->r3;
L_800F622C:
    // 0x800F622C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F6230: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6234: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6238: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F623C: sb          $v1, 0x15($s0)
    MEM_B(0X15, ctx->r16) = ctx->r3;
L_800F6240:
    // 0x800F6240: lbu         $v1, 0x1A($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1A);
    // 0x800F6244: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800F6248: bne         $v1, $v0, L_800F6278
    if (ctx->r3 != ctx->r2) {
        // 0x800F624C: nop
    
            goto L_800F6278;
    }
    // 0x800F624C: nop

    // 0x800F6250: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F6254: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F6258: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F625C: lwc1        $f2, -0x72B0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X72B0);
    // 0x800F6260: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6264: nop

    // 0x800F6268: bc1f        L_800F62B8
    if (!c1cs) {
        // 0x800F626C: nop
    
            goto L_800F62B8;
    }
    // 0x800F626C: nop

    // 0x800F6270: j           L_800F62C8
    // 0x800F6274: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_800F62C8;
    // 0x800F6274: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_800F6278:
    // 0x800F6278: lbu         $v0, 0x1A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1A);
    // 0x800F627C: lbu         $v1, 0x14($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X14);
    // 0x800F6280: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F6284: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F6288: mtc1        $v1, $f2
    ctx->f2.u32l = ctx->r3;
    // 0x800F628C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800F6290: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F6294: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6298: lwc1        $f2, -0x72AC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X72AC);
    // 0x800F629C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F62A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F62A4: lwc1        $f2, -0x72A8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X72A8);
    // 0x800F62A8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F62AC: nop

    // 0x800F62B0: bc1tl       L_800F62C8
    if (c1cs) {
        // 0x800F62B4: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F62C8;
    }
    goto skip_13;
    // 0x800F62B4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_13:
L_800F62B8:
    // 0x800F62B8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F62BC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F62C0: j           L_800F62DC
    // 0x800F62C4: sb          $v1, 0x17($s0)
    MEM_B(0X17, ctx->r16) = ctx->r3;
        goto L_800F62DC;
    // 0x800F62C4: sb          $v1, 0x17($s0)
    MEM_B(0X17, ctx->r16) = ctx->r3;
L_800F62C8:
    // 0x800F62C8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F62CC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F62D0: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F62D4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F62D8: sb          $v1, 0x17($s0)
    MEM_B(0X17, ctx->r16) = ctx->r3;
L_800F62DC:
    // 0x800F62DC: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F62E0: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F62E4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F62E8: lwc1        $f2, -0x72A4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X72A4);
    // 0x800F62EC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F62F0: nop

    // 0x800F62F4: bc1tl       L_800F630C
    if (c1cs) {
        // 0x800F62F8: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F630C;
    }
    goto skip_14;
    // 0x800F62F8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_14:
    // 0x800F62FC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6300: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6304: j           L_800F6320
    // 0x800F6308: sb          $v1, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r3;
        goto L_800F6320;
    // 0x800F6308: sb          $v1, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r3;
L_800F630C:
    // 0x800F630C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F6310: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6314: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6318: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F631C: sb          $v1, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r3;
L_800F6320:
    // 0x800F6320: lbu         $v1, 0x16($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X16);
    // 0x800F6324: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800F6328: bne         $v1, $v0, L_800F637C
    if (ctx->r3 != ctx->r2) {
        // 0x800F632C: nop
    
            goto L_800F637C;
    }
    // 0x800F632C: nop

    // 0x800F6330: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F6334: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F6338: div.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800F633C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F6340: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x800F6344: nop

    // 0x800F6348: bc1f        L_800F6354
    if (!c1cs) {
        // 0x800F634C: swc1        $f2, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
            goto L_800F6354;
    }
    // 0x800F634C: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800F6350: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
L_800F6354:
    // 0x800F6354: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800F6358: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F635C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6360: lwc1        $f2, -0x72A0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X72A0);
    // 0x800F6364: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6368: nop

    // 0x800F636C: bc1f        L_800F63BC
    if (!c1cs) {
        // 0x800F6370: nop
    
            goto L_800F63BC;
    }
    // 0x800F6370: nop

    // 0x800F6374: j           L_800F63CC
    // 0x800F6378: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_800F63CC;
    // 0x800F6378: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_800F637C:
    // 0x800F637C: lbu         $v0, 0x13($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X13);
    // 0x800F6380: lbu         $v1, 0x19($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X19);
    // 0x800F6384: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F6388: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F638C: mtc1        $v1, $f2
    ctx->f2.u32l = ctx->r3;
    // 0x800F6390: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800F6394: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F6398: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F639C: lwc1        $f2, -0x729C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X729C);
    // 0x800F63A0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F63A4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F63A8: lwc1        $f2, -0x7298($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7298);
    // 0x800F63AC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F63B0: nop

    // 0x800F63B4: bc1tl       L_800F63CC
    if (c1cs) {
        // 0x800F63B8: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F63CC;
    }
    goto skip_15;
    // 0x800F63B8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_15:
L_800F63BC:
    // 0x800F63BC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F63C0: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F63C4: j           L_800F63E0
    // 0x800F63C8: sb          $v1, 0x16($s0)
    MEM_B(0X16, ctx->r16) = ctx->r3;
        goto L_800F63E0;
    // 0x800F63C8: sb          $v1, 0x16($s0)
    MEM_B(0X16, ctx->r16) = ctx->r3;
L_800F63CC:
    // 0x800F63CC: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F63D0: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F63D4: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F63D8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F63DC: sb          $v1, 0x16($s0)
    MEM_B(0X16, ctx->r16) = ctx->r3;
L_800F63E0:
    // 0x800F63E0: lbu         $v1, 0x18($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X18);
    // 0x800F63E4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800F63E8: bne         $v1, $v0, L_800F643C
    if (ctx->r3 != ctx->r2) {
        // 0x800F63EC: nop
    
            goto L_800F643C;
    }
    // 0x800F63EC: nop

    // 0x800F63F0: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F63F4: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F63F8: div.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800F63FC: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F6400: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x800F6404: nop

    // 0x800F6408: bc1f        L_800F6414
    if (!c1cs) {
        // 0x800F640C: swc1        $f2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
            goto L_800F6414;
    }
    // 0x800F640C: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x800F6410: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
L_800F6414:
    // 0x800F6414: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F6418: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F641C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6420: lwc1        $f2, -0x7294($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7294);
    // 0x800F6424: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6428: nop

    // 0x800F642C: bc1f        L_800F647C
    if (!c1cs) {
        // 0x800F6430: nop
    
            goto L_800F647C;
    }
    // 0x800F6430: nop

    // 0x800F6434: j           L_800F648C
    // 0x800F6438: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_800F648C;
    // 0x800F6438: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_800F643C:
    // 0x800F643C: lbu         $v0, 0x15($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X15);
    // 0x800F6440: lbu         $v1, 0x1B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1B);
    // 0x800F6444: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F6448: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F644C: mtc1        $v1, $f2
    ctx->f2.u32l = ctx->r3;
    // 0x800F6450: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800F6454: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F6458: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F645C: lwc1        $f2, -0x7290($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7290);
    // 0x800F6460: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F6464: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6468: lwc1        $f2, -0x728C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X728C);
    // 0x800F646C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6470: nop

    // 0x800F6474: bc1tl       L_800F648C
    if (c1cs) {
        // 0x800F6478: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F648C;
    }
    goto skip_16;
    // 0x800F6478: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_16:
L_800F647C:
    // 0x800F647C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6480: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6484: j           L_800F64A0
    // 0x800F6488: sb          $v1, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r3;
        goto L_800F64A0;
    // 0x800F6488: sb          $v1, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r3;
L_800F648C:
    // 0x800F648C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F6490: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6494: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6498: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F649C: sb          $v1, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r3;
L_800F64A0:
    // 0x800F64A0: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F64A4: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F64A8: div.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800F64AC: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F64B0: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x800F64B4: nop

    // 0x800F64B8: bc1f        L_800F64C4
    if (!c1cs) {
        // 0x800F64BC: swc1        $f2, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
            goto L_800F64C4;
    }
    // 0x800F64BC: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x800F64C0: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
L_800F64C4:
    // 0x800F64C4: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800F64C8: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F64CC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F64D0: lwc1        $f2, -0x7288($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7288);
    // 0x800F64D4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F64D8: nop

    // 0x800F64DC: bc1tl       L_800F64F4
    if (c1cs) {
        // 0x800F64E0: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F64F4;
    }
    goto skip_17;
    // 0x800F64E0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_17:
    // 0x800F64E4: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F64E8: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F64EC: j           L_800F6508
    // 0x800F64F0: sb          $v1, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r3;
        goto L_800F6508;
    // 0x800F64F0: sb          $v1, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r3;
L_800F64F4:
    // 0x800F64F4: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F64F8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F64FC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6500: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F6504: sb          $v1, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r3;
L_800F6508:
    // 0x800F6508: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F650C: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F6510: div.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800F6514: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F6518: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x800F651C: nop

    // 0x800F6520: bc1f        L_800F652C
    if (!c1cs) {
        // 0x800F6524: swc1        $f2, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
            goto L_800F652C;
    }
    // 0x800F6524: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x800F6528: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
L_800F652C:
    // 0x800F652C: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F6530: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F6534: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6538: lwc1        $f2, -0x7284($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7284);
    // 0x800F653C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6540: nop

    // 0x800F6544: bc1tl       L_800F655C
    if (c1cs) {
        // 0x800F6548: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F655C;
    }
    goto skip_18;
    // 0x800F6548: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_18:
    // 0x800F654C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6550: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6554: j           L_800F692C
    // 0x800F6558: sb          $v1, 0x12($s0)
    MEM_B(0X12, ctx->r16) = ctx->r3;
        goto L_800F692C;
    // 0x800F6558: sb          $v1, 0x12($s0)
    MEM_B(0X12, ctx->r16) = ctx->r3;
L_800F655C:
    // 0x800F655C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F6560: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6564: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6568: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F656C: j           L_800F692C
    // 0x800F6570: sb          $v1, 0x12($s0)
    MEM_B(0X12, ctx->r16) = ctx->r3;
        goto L_800F692C;
    // 0x800F6570: sb          $v1, 0x12($s0)
    MEM_B(0X12, ctx->r16) = ctx->r3;
L_800F6574:
    // 0x800F6574: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F6578: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F657C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6580: lwc1        $f2, -0x7280($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7280);
    // 0x800F6584: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6588: nop

    // 0x800F658C: bc1tl       L_800F65A4
    if (c1cs) {
        // 0x800F6590: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F65A4;
    }
    goto skip_19;
    // 0x800F6590: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_19:
    // 0x800F6594: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6598: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F659C: j           L_800F65B8
    // 0x800F65A0: sb          $v1, 0x1F($s0)
    MEM_B(0X1F, ctx->r16) = ctx->r3;
        goto L_800F65B8;
    // 0x800F65A0: sb          $v1, 0x1F($s0)
    MEM_B(0X1F, ctx->r16) = ctx->r3;
L_800F65A4:
    // 0x800F65A4: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F65A8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F65AC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F65B0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F65B4: sb          $v1, 0x1F($s0)
    MEM_B(0X1F, ctx->r16) = ctx->r3;
L_800F65B8:
    // 0x800F65B8: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F65BC: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F65C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F65C4: lwc1        $f2, -0x727C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X727C);
    // 0x800F65C8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F65CC: nop

    // 0x800F65D0: bc1tl       L_800F65E8
    if (c1cs) {
        // 0x800F65D4: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F65E8;
    }
    goto skip_20;
    // 0x800F65D4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_20:
    // 0x800F65D8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F65DC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F65E0: j           L_800F65FC
    // 0x800F65E4: sb          $v1, 0x21($s0)
    MEM_B(0X21, ctx->r16) = ctx->r3;
        goto L_800F65FC;
    // 0x800F65E4: sb          $v1, 0x21($s0)
    MEM_B(0X21, ctx->r16) = ctx->r3;
L_800F65E8:
    // 0x800F65E8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F65EC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F65F0: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F65F4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F65F8: sb          $v1, 0x21($s0)
    MEM_B(0X21, ctx->r16) = ctx->r3;
L_800F65FC:
    // 0x800F65FC: lbu         $v1, 0x1A($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1A);
    // 0x800F6600: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800F6604: bne         $v1, $v0, L_800F6634
    if (ctx->r3 != ctx->r2) {
        // 0x800F6608: nop
    
            goto L_800F6634;
    }
    // 0x800F6608: nop

    // 0x800F660C: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F6610: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F6614: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6618: lwc1        $f2, -0x7278($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7278);
    // 0x800F661C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6620: nop

    // 0x800F6624: bc1f        L_800F6674
    if (!c1cs) {
        // 0x800F6628: nop
    
            goto L_800F6674;
    }
    // 0x800F6628: nop

    // 0x800F662C: j           L_800F6684
    // 0x800F6630: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_800F6684;
    // 0x800F6630: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_800F6634:
    // 0x800F6634: lbu         $v0, 0x1A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1A);
    // 0x800F6638: lbu         $v1, 0x20($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X20);
    // 0x800F663C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F6640: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F6644: mtc1        $v1, $f2
    ctx->f2.u32l = ctx->r3;
    // 0x800F6648: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800F664C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F6650: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6654: lwc1        $f2, -0x7274($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7274);
    // 0x800F6658: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F665C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6660: lwc1        $f2, -0x7270($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7270);
    // 0x800F6664: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6668: nop

    // 0x800F666C: bc1tl       L_800F6684
    if (c1cs) {
        // 0x800F6670: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F6684;
    }
    goto skip_21;
    // 0x800F6670: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_21:
L_800F6674:
    // 0x800F6674: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6678: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F667C: j           L_800F6698
    // 0x800F6680: sb          $v1, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r3;
        goto L_800F6698;
    // 0x800F6680: sb          $v1, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r3;
L_800F6684:
    // 0x800F6684: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F6688: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F668C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6690: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F6694: sb          $v1, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r3;
L_800F6698:
    // 0x800F6698: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F669C: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F66A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F66A4: lwc1        $f2, -0x726C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X726C);
    // 0x800F66A8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F66AC: nop

    // 0x800F66B0: bc1tl       L_800F66C8
    if (c1cs) {
        // 0x800F66B4: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F66C8;
    }
    goto skip_22;
    // 0x800F66B4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_22:
    // 0x800F66B8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F66BC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F66C0: j           L_800F66DC
    // 0x800F66C4: sb          $v1, 0x23($s0)
    MEM_B(0X23, ctx->r16) = ctx->r3;
        goto L_800F66DC;
    // 0x800F66C4: sb          $v1, 0x23($s0)
    MEM_B(0X23, ctx->r16) = ctx->r3;
L_800F66C8:
    // 0x800F66C8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F66CC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F66D0: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F66D4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F66D8: sb          $v1, 0x23($s0)
    MEM_B(0X23, ctx->r16) = ctx->r3;
L_800F66DC:
    // 0x800F66DC: lbu         $v1, 0x1C($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1C);
    // 0x800F66E0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800F66E4: bne         $v1, $v0, L_800F6738
    if (ctx->r3 != ctx->r2) {
        // 0x800F66E8: nop
    
            goto L_800F6738;
    }
    // 0x800F66E8: nop

    // 0x800F66EC: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F66F0: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F66F4: div.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800F66F8: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F66FC: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x800F6700: nop

    // 0x800F6704: bc1f        L_800F6710
    if (!c1cs) {
        // 0x800F6708: swc1        $f2, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
            goto L_800F6710;
    }
    // 0x800F6708: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x800F670C: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
L_800F6710:
    // 0x800F6710: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800F6714: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F6718: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F671C: lwc1        $f2, -0x7268($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7268);
    // 0x800F6720: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6724: nop

    // 0x800F6728: bc1f        L_800F6778
    if (!c1cs) {
        // 0x800F672C: nop
    
            goto L_800F6778;
    }
    // 0x800F672C: nop

    // 0x800F6730: j           L_800F6788
    // 0x800F6734: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_800F6788;
    // 0x800F6734: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_800F6738:
    // 0x800F6738: lbu         $v0, 0x1F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1F);
    // 0x800F673C: lbu         $v1, 0x19($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X19);
    // 0x800F6740: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F6744: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F6748: mtc1        $v1, $f2
    ctx->f2.u32l = ctx->r3;
    // 0x800F674C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800F6750: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F6754: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6758: lwc1        $f2, -0x7264($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7264);
    // 0x800F675C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F6760: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6764: lwc1        $f2, -0x7260($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7260);
    // 0x800F6768: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F676C: nop

    // 0x800F6770: bc1tl       L_800F6788
    if (c1cs) {
        // 0x800F6774: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F6788;
    }
    goto skip_23;
    // 0x800F6774: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_23:
L_800F6778:
    // 0x800F6778: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F677C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6780: j           L_800F679C
    // 0x800F6784: sb          $v1, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r3;
        goto L_800F679C;
    // 0x800F6784: sb          $v1, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r3;
L_800F6788:
    // 0x800F6788: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F678C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6790: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6794: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F6798: sb          $v1, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r3;
L_800F679C:
    // 0x800F679C: lbu         $v1, 0x1E($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1E);
    // 0x800F67A0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800F67A4: bne         $v1, $v0, L_800F67F8
    if (ctx->r3 != ctx->r2) {
        // 0x800F67A8: nop
    
            goto L_800F67F8;
    }
    // 0x800F67A8: nop

    // 0x800F67AC: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F67B0: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F67B4: div.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800F67B8: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F67BC: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x800F67C0: nop

    // 0x800F67C4: bc1f        L_800F67D0
    if (!c1cs) {
        // 0x800F67C8: swc1        $f2, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
            goto L_800F67D0;
    }
    // 0x800F67C8: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x800F67CC: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
L_800F67D0:
    // 0x800F67D0: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F67D4: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F67D8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F67DC: lwc1        $f2, -0x725C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X725C);
    // 0x800F67E0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F67E4: nop

    // 0x800F67E8: bc1f        L_800F6838
    if (!c1cs) {
        // 0x800F67EC: nop
    
            goto L_800F6838;
    }
    // 0x800F67EC: nop

    // 0x800F67F0: j           L_800F6848
    // 0x800F67F4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_800F6848;
    // 0x800F67F4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_800F67F8:
    // 0x800F67F8: lbu         $v0, 0x21($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X21);
    // 0x800F67FC: lbu         $v1, 0x1B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1B);
    // 0x800F6800: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F6804: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F6808: mtc1        $v1, $f2
    ctx->f2.u32l = ctx->r3;
    // 0x800F680C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800F6810: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F6814: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6818: lwc1        $f2, -0x7258($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7258);
    // 0x800F681C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F6820: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6824: lwc1        $f2, -0x7254($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7254);
    // 0x800F6828: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F682C: nop

    // 0x800F6830: bc1tl       L_800F6848
    if (c1cs) {
        // 0x800F6834: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F6848;
    }
    goto skip_24;
    // 0x800F6834: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_24:
L_800F6838:
    // 0x800F6838: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F683C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6840: j           L_800F685C
    // 0x800F6844: sb          $v1, 0x1E($s0)
    MEM_B(0X1E, ctx->r16) = ctx->r3;
        goto L_800F685C;
    // 0x800F6844: sb          $v1, 0x1E($s0)
    MEM_B(0X1E, ctx->r16) = ctx->r3;
L_800F6848:
    // 0x800F6848: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F684C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6850: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6854: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F6858: sb          $v1, 0x1E($s0)
    MEM_B(0X1E, ctx->r16) = ctx->r3;
L_800F685C:
    // 0x800F685C: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F6860: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F6864: div.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800F6868: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F686C: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x800F6870: nop

    // 0x800F6874: bc1f        L_800F6880
    if (!c1cs) {
        // 0x800F6878: swc1        $f2, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
            goto L_800F6880;
    }
    // 0x800F6878: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800F687C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
L_800F6880:
    // 0x800F6880: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800F6884: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F6888: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F688C: lwc1        $f2, -0x7250($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7250);
    // 0x800F6890: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6894: nop

    // 0x800F6898: bc1tl       L_800F68B0
    if (c1cs) {
        // 0x800F689C: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F68B0;
    }
    goto skip_25;
    // 0x800F689C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_25:
    // 0x800F68A0: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F68A4: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F68A8: j           L_800F68C4
    // 0x800F68AC: sb          $v1, 0x22($s0)
    MEM_B(0X22, ctx->r16) = ctx->r3;
        goto L_800F68C4;
    // 0x800F68AC: sb          $v1, 0x22($s0)
    MEM_B(0X22, ctx->r16) = ctx->r3;
L_800F68B0:
    // 0x800F68B0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F68B4: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F68B8: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F68BC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F68C0: sb          $v1, 0x22($s0)
    MEM_B(0X22, ctx->r16) = ctx->r3;
L_800F68C4:
    // 0x800F68C4: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F68C8: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F68CC: div.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800F68D0: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F68D4: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x800F68D8: nop

    // 0x800F68DC: bc1f        L_800F68E8
    if (!c1cs) {
        // 0x800F68E0: swc1        $f2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
            goto L_800F68E8;
    }
    // 0x800F68E0: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x800F68E4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
L_800F68E8:
    // 0x800F68E8: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F68EC: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F68F0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F68F4: lwc1        $f2, -0x724C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X724C);
    // 0x800F68F8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F68FC: nop

    // 0x800F6900: bc1tl       L_800F6918
    if (c1cs) {
        // 0x800F6904: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F6918;
    }
    goto skip_26;
    // 0x800F6904: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_26:
    // 0x800F6908: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F690C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6910: j           L_800F692C
    // 0x800F6914: sb          $v1, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r3;
        goto L_800F692C;
    // 0x800F6914: sb          $v1, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r3;
L_800F6918:
    // 0x800F6918: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F691C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6920: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6924: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F6928: sb          $v1, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r3;
L_800F692C:
    // 0x800F692C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800F6930: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800F6934: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800F6938: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800F693C: ldc1        $f26, 0x58($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X58);
    // 0x800F6940: ldc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X50);
    // 0x800F6944: ldc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X48);
    // 0x800F6948: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x800F694C: jr          $ra
    // 0x800F6950: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800F6950: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_800F6954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6954: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800F6958: sdc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X50, ctx->r29);
    // 0x800F695C: mtc1        $a2, $f24
    ctx->f24.u32l = ctx->r6;
    // 0x800F6960: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800F6964: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800F6968: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800F696C: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x800F6970: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800F6974: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // 0x800F6978: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800F697C: sdc1        $f26, 0x58($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X58, ctx->r29);
    // 0x800F6980: sdc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X48, ctx->r29);
    // 0x800F6984: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x800F6988: lwc1        $f20, 0x8($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800F698C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6990: lwc1        $f0, -0x7248($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7248);
    // 0x800F6994: lwc1        $f12, 0x8($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800F6998: jal         0x8001C400
    // 0x800F699C: div.s       $f22, $f0, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    sinfApprox(rdram, ctx);
        goto after_0;
    // 0x800F699C: div.s       $f22, $f0, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    after_0:
    // 0x800F69A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F69A4: lwc1        $f26, -0x7244($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X7244);
    // 0x800F69A8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F69AC: lwc1        $f2, -0x7240($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7240);
    // 0x800F69B0: div.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f26.fl);
    // 0x800F69B4: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800F69B8: mul.s       $f2, $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x800F69BC: add.s       $f0, $f24, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f24.fl + ctx->f2.fl;
    // 0x800F69C0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800F69C4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800F69C8: nop

    // 0x800F69CC: bc1f        L_800F69D8
    if (!c1cs) {
        // 0x800F69D0: swc1        $f0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
            goto L_800F69D8;
    }
    // 0x800F69D0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800F69D4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
L_800F69D8:
    // 0x800F69D8: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F69DC: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800F69E0: nop

    // 0x800F69E4: bc1tl       L_800F69EC
    if (c1cs) {
        // 0x800F69E8: swc1        $f20, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
            goto L_800F69EC;
    }
    goto skip_0;
    // 0x800F69E8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    skip_0:
L_800F69EC:
    // 0x800F69EC: sub.s       $f0, $f24, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f2.fl;
    // 0x800F69F0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800F69F4: nop

    // 0x800F69F8: bc1f        L_800F6A04
    if (!c1cs) {
        // 0x800F69FC: swc1        $f0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
            goto L_800F6A04;
    }
    // 0x800F69FC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800F6A00: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
L_800F6A04:
    // 0x800F6A04: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F6A08: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800F6A0C: nop

    // 0x800F6A10: bc1tl       L_800F6A18
    if (c1cs) {
        // 0x800F6A14: swc1        $f20, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
            goto L_800F6A18;
    }
    goto skip_1;
    // 0x800F6A14: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    skip_1:
L_800F6A18:
    // 0x800F6A18: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800F6A1C: jal         0x8001C400
    // 0x800F6A20: nop

    sinfApprox(rdram, ctx);
        goto after_1;
    // 0x800F6A20: nop

    after_1:
    // 0x800F6A24: sub.s       $f2, $f20, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x800F6A28: div.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f26.fl);
    // 0x800F6A2C: mul.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F6A30: add.s       $f0, $f24, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f24.fl + ctx->f2.fl;
    // 0x800F6A34: sub.s       $f2, $f24, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f24.fl - ctx->f2.fl;
    // 0x800F6A38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F6A3C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800F6A40: beq         $s1, $v0, L_800F6C14
    if (ctx->r17 == ctx->r2) {
        // 0x800F6A44: swc1        $f2, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
            goto L_800F6C14;
    }
    // 0x800F6A44: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x800F6A48: slti        $v0, $s1, 0x2
    ctx->r2 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // 0x800F6A4C: beql        $v0, $zero, L_800F6A64
    if (ctx->r2 == 0) {
        // 0x800F6A50: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800F6A64;
    }
    goto skip_2;
    // 0x800F6A50: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_2:
    // 0x800F6A54: beq         $s1, $zero, L_800F6A74
    if (ctx->r17 == 0) {
        // 0x800F6A58: nop
    
            goto L_800F6A74;
    }
    // 0x800F6A58: nop

    // 0x800F6A5C: j           L_800F7108
    // 0x800F6A60: nop

        goto L_800F7108;
    // 0x800F6A60: nop

L_800F6A64:
    // 0x800F6A64: beq         $s1, $v0, L_800F6E90
    if (ctx->r17 == ctx->r2) {
        // 0x800F6A68: nop
    
            goto L_800F6E90;
    }
    // 0x800F6A68: nop

    // 0x800F6A6C: j           L_800F7108
    // 0x800F6A70: nop

        goto L_800F7108;
    // 0x800F6A70: nop

L_800F6A74:
    // 0x800F6A74: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F6A78: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F6A7C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6A80: lwc1        $f2, -0x723C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X723C);
    // 0x800F6A84: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6A88: nop

    // 0x800F6A8C: bc1tl       L_800F6AA4
    if (c1cs) {
        // 0x800F6A90: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F6AA4;
    }
    goto skip_3;
    // 0x800F6A90: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_3:
    // 0x800F6A94: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6A98: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6A9C: j           L_800F6AB8
    // 0x800F6AA0: sb          $v1, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = ctx->r3;
        goto L_800F6AB8;
    // 0x800F6AA0: sb          $v1, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = ctx->r3;
L_800F6AA4:
    // 0x800F6AA4: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F6AA8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6AAC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6AB0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F6AB4: sb          $v1, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = ctx->r3;
L_800F6AB8:
    // 0x800F6AB8: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F6ABC: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F6AC0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6AC4: lwc1        $f2, -0x7238($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7238);
    // 0x800F6AC8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6ACC: nop

    // 0x800F6AD0: bc1tl       L_800F6AE8
    if (c1cs) {
        // 0x800F6AD4: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F6AE8;
    }
    goto skip_4;
    // 0x800F6AD4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_4:
    // 0x800F6AD8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6ADC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6AE0: j           L_800F6AFC
    // 0x800F6AE4: sb          $v1, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r3;
        goto L_800F6AFC;
    // 0x800F6AE4: sb          $v1, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r3;
L_800F6AE8:
    // 0x800F6AE8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F6AEC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6AF0: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6AF4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F6AF8: sb          $v1, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r3;
L_800F6AFC:
    // 0x800F6AFC: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F6B00: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F6B04: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6B08: lwc1        $f2, -0x7234($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7234);
    // 0x800F6B0C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6B10: nop

    // 0x800F6B14: bc1tl       L_800F6B2C
    if (c1cs) {
        // 0x800F6B18: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F6B2C;
    }
    goto skip_5;
    // 0x800F6B18: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_5:
    // 0x800F6B1C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6B20: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6B24: j           L_800F6B40
    // 0x800F6B28: sb          $v1, 0x1E($s0)
    MEM_B(0X1E, ctx->r16) = ctx->r3;
        goto L_800F6B40;
    // 0x800F6B28: sb          $v1, 0x1E($s0)
    MEM_B(0X1E, ctx->r16) = ctx->r3;
L_800F6B2C:
    // 0x800F6B2C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F6B30: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6B34: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6B38: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F6B3C: sb          $v1, 0x1E($s0)
    MEM_B(0X1E, ctx->r16) = ctx->r3;
L_800F6B40:
    // 0x800F6B40: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F6B44: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F6B48: div.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800F6B4C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F6B50: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x800F6B54: nop

    // 0x800F6B58: bc1f        L_800F6B64
    if (!c1cs) {
        // 0x800F6B5C: swc1        $f2, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
            goto L_800F6B64;
    }
    // 0x800F6B5C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x800F6B60: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
L_800F6B64:
    // 0x800F6B64: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800F6B68: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F6B6C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6B70: lwc1        $f2, -0x7230($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7230);
    // 0x800F6B74: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6B78: nop

    // 0x800F6B7C: bc1tl       L_800F6B94
    if (c1cs) {
        // 0x800F6B80: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F6B94;
    }
    goto skip_6;
    // 0x800F6B80: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_6:
    // 0x800F6B84: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6B88: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6B8C: j           L_800F6BA8
    // 0x800F6B90: sb          $v1, 0x17($s0)
    MEM_B(0X17, ctx->r16) = ctx->r3;
        goto L_800F6BA8;
    // 0x800F6B90: sb          $v1, 0x17($s0)
    MEM_B(0X17, ctx->r16) = ctx->r3;
L_800F6B94:
    // 0x800F6B94: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F6B98: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6B9C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6BA0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F6BA4: sb          $v1, 0x17($s0)
    MEM_B(0X17, ctx->r16) = ctx->r3;
L_800F6BA8:
    // 0x800F6BA8: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F6BAC: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F6BB0: div.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800F6BB4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F6BB8: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x800F6BBC: nop

    // 0x800F6BC0: bc1f        L_800F6BCC
    if (!c1cs) {
        // 0x800F6BC4: swc1        $f2, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
            goto L_800F6BCC;
    }
    // 0x800F6BC4: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800F6BC8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
L_800F6BCC:
    // 0x800F6BCC: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800F6BD0: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F6BD4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6BD8: lwc1        $f2, -0x722C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X722C);
    // 0x800F6BDC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6BE0: nop

    // 0x800F6BE4: bc1tl       L_800F6BFC
    if (c1cs) {
        // 0x800F6BE8: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F6BFC;
    }
    goto skip_7;
    // 0x800F6BE8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_7:
    // 0x800F6BEC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6BF0: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6BF4: j           L_800F7108
    // 0x800F6BF8: sb          $v1, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r3;
        goto L_800F7108;
    // 0x800F6BF8: sb          $v1, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r3;
L_800F6BFC:
    // 0x800F6BFC: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F6C00: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6C04: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6C08: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F6C0C: j           L_800F7108
    // 0x800F6C10: sb          $v1, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r3;
        goto L_800F7108;
    // 0x800F6C10: sb          $v1, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r3;
L_800F6C14:
    // 0x800F6C14: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F6C18: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F6C1C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6C20: lwc1        $f2, -0x7228($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7228);
    // 0x800F6C24: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6C28: nop

    // 0x800F6C2C: bc1tl       L_800F6C44
    if (c1cs) {
        // 0x800F6C30: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F6C44;
    }
    goto skip_8;
    // 0x800F6C30: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_8:
    // 0x800F6C34: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6C38: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6C3C: j           L_800F6C58
    // 0x800F6C40: sb          $v1, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r3;
        goto L_800F6C58;
    // 0x800F6C40: sb          $v1, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r3;
L_800F6C44:
    // 0x800F6C44: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F6C48: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6C4C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6C50: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F6C54: sb          $v1, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r3;
L_800F6C58:
    // 0x800F6C58: lbu         $v1, 0x1A($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1A);
    // 0x800F6C5C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800F6C60: bne         $v1, $v0, L_800F6D18
    if (ctx->r3 != ctx->r2) {
        // 0x800F6C64: nop
    
            goto L_800F6D18;
    }
    // 0x800F6C64: nop

    // 0x800F6C68: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F6C6C: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F6C70: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6C74: lwc1        $f2, -0x7224($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7224);
    // 0x800F6C78: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6C7C: nop

    // 0x800F6C80: bc1tl       L_800F6C98
    if (c1cs) {
        // 0x800F6C84: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F6C98;
    }
    goto skip_9;
    // 0x800F6C84: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_9:
    // 0x800F6C88: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6C8C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6C90: j           L_800F6CAC
    // 0x800F6C94: sb          $v1, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r3;
        goto L_800F6CAC;
    // 0x800F6C94: sb          $v1, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r3;
L_800F6C98:
    // 0x800F6C98: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F6C9C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6CA0: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6CA4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F6CA8: sb          $v1, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r3;
L_800F6CAC:
    // 0x800F6CAC: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F6CB0: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F6CB4: div.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800F6CB8: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F6CBC: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x800F6CC0: nop

    // 0x800F6CC4: bc1f        L_800F6CD0
    if (!c1cs) {
        // 0x800F6CC8: swc1        $f2, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
            goto L_800F6CD0;
    }
    // 0x800F6CC8: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800F6CCC: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
L_800F6CD0:
    // 0x800F6CD0: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800F6CD4: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F6CD8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6CDC: lwc1        $f2, -0x7220($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7220);
    // 0x800F6CE0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6CE4: nop

    // 0x800F6CE8: bc1tl       L_800F6D00
    if (c1cs) {
        // 0x800F6CEC: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F6D00;
    }
    goto skip_10;
    // 0x800F6CEC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_10:
    // 0x800F6CF0: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6CF4: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6CF8: j           L_800F6DE0
    // 0x800F6CFC: sb          $v1, 0x17($s0)
    MEM_B(0X17, ctx->r16) = ctx->r3;
        goto L_800F6DE0;
    // 0x800F6CFC: sb          $v1, 0x17($s0)
    MEM_B(0X17, ctx->r16) = ctx->r3;
L_800F6D00:
    // 0x800F6D00: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F6D04: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6D08: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6D0C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F6D10: j           L_800F6DE0
    // 0x800F6D14: sb          $v1, 0x17($s0)
    MEM_B(0X17, ctx->r16) = ctx->r3;
        goto L_800F6DE0;
    // 0x800F6D14: sb          $v1, 0x17($s0)
    MEM_B(0X17, ctx->r16) = ctx->r3;
L_800F6D18:
    // 0x800F6D18: lbu         $v0, 0x1A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1A);
    // 0x800F6D1C: lbu         $v1, 0x14($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X14);
    // 0x800F6D20: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F6D24: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F6D28: mtc1        $v1, $f2
    ctx->f2.u32l = ctx->r3;
    // 0x800F6D2C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800F6D30: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F6D34: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6D38: lwc1        $f2, -0x721C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X721C);
    // 0x800F6D3C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F6D40: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6D44: lwc1        $f2, -0x7218($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7218);
    // 0x800F6D48: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6D4C: nop

    // 0x800F6D50: bc1tl       L_800F6D68
    if (c1cs) {
        // 0x800F6D54: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F6D68;
    }
    goto skip_11;
    // 0x800F6D54: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_11:
    // 0x800F6D58: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6D5C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800F6D60: j           L_800F6D78
    // 0x800F6D64: nop

        goto L_800F6D78;
    // 0x800F6D64: nop

L_800F6D68:
    // 0x800F6D68: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F6D6C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6D70: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800F6D74: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
L_800F6D78:
    // 0x800F6D78: lbu         $v0, 0x1B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1B);
    // 0x800F6D7C: lbu         $v1, 0x15($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X15);
    // 0x800F6D80: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F6D84: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F6D88: mtc1        $v1, $f2
    ctx->f2.u32l = ctx->r3;
    // 0x800F6D8C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800F6D90: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F6D94: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6D98: lwc1        $f2, -0x7214($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7214);
    // 0x800F6D9C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F6DA0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6DA4: lwc1        $f2, -0x7210($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7210);
    // 0x800F6DA8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6DAC: nop

    // 0x800F6DB0: bc1t        L_800F6DC8
    if (c1cs) {
        // 0x800F6DB4: sb          $a0, 0x17($s0)
        MEM_B(0X17, ctx->r16) = ctx->r4;
            goto L_800F6DC8;
    }
    // 0x800F6DB4: sb          $a0, 0x17($s0)
    MEM_B(0X17, ctx->r16) = ctx->r4;
    // 0x800F6DB8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6DBC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6DC0: j           L_800F6DE0
    // 0x800F6DC4: sb          $v1, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r3;
        goto L_800F6DE0;
    // 0x800F6DC4: sb          $v1, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r3;
L_800F6DC8:
    // 0x800F6DC8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F6DCC: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F6DD0: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6DD4: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6DD8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F6DDC: sb          $v1, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r3;
L_800F6DE0:
    // 0x800F6DE0: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F6DE4: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F6DE8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6DEC: lwc1        $f2, -0x720C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X720C);
    // 0x800F6DF0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6DF4: nop

    // 0x800F6DF8: bc1tl       L_800F6E10
    if (c1cs) {
        // 0x800F6DFC: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F6E10;
    }
    goto skip_12;
    // 0x800F6DFC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_12:
    // 0x800F6E00: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6E04: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6E08: j           L_800F6E24
    // 0x800F6E0C: sb          $v1, 0x12($s0)
    MEM_B(0X12, ctx->r16) = ctx->r3;
        goto L_800F6E24;
    // 0x800F6E0C: sb          $v1, 0x12($s0)
    MEM_B(0X12, ctx->r16) = ctx->r3;
L_800F6E10:
    // 0x800F6E10: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F6E14: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6E18: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6E1C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F6E20: sb          $v1, 0x12($s0)
    MEM_B(0X12, ctx->r16) = ctx->r3;
L_800F6E24:
    // 0x800F6E24: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F6E28: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F6E2C: div.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800F6E30: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F6E34: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x800F6E38: nop

    // 0x800F6E3C: bc1f        L_800F6E48
    if (!c1cs) {
        // 0x800F6E40: swc1        $f2, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
            goto L_800F6E48;
    }
    // 0x800F6E40: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x800F6E44: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
L_800F6E48:
    // 0x800F6E48: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800F6E4C: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F6E50: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6E54: lwc1        $f2, -0x7208($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7208);
    // 0x800F6E58: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6E5C: nop

    // 0x800F6E60: bc1tl       L_800F6E78
    if (c1cs) {
        // 0x800F6E64: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F6E78;
    }
    goto skip_13;
    // 0x800F6E64: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_13:
    // 0x800F6E68: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6E6C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6E70: j           L_800F7108
    // 0x800F6E74: sb          $v1, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r3;
        goto L_800F7108;
    // 0x800F6E74: sb          $v1, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r3;
L_800F6E78:
    // 0x800F6E78: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F6E7C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6E80: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6E84: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F6E88: j           L_800F7108
    // 0x800F6E8C: sb          $v1, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r3;
        goto L_800F7108;
    // 0x800F6E8C: sb          $v1, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r3;
L_800F6E90:
    // 0x800F6E90: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F6E94: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F6E98: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6E9C: lwc1        $f2, -0x7204($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7204);
    // 0x800F6EA0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6EA4: nop

    // 0x800F6EA8: bc1tl       L_800F6EC0
    if (c1cs) {
        // 0x800F6EAC: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F6EC0;
    }
    goto skip_14;
    // 0x800F6EAC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_14:
    // 0x800F6EB0: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6EB4: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6EB8: j           L_800F6ED4
    // 0x800F6EBC: sb          $v1, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r3;
        goto L_800F6ED4;
    // 0x800F6EBC: sb          $v1, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r3;
L_800F6EC0:
    // 0x800F6EC0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F6EC4: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6EC8: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6ECC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F6ED0: sb          $v1, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r3;
L_800F6ED4:
    // 0x800F6ED4: lbu         $v1, 0x1A($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1A);
    // 0x800F6ED8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800F6EDC: bne         $v1, $v0, L_800F6F94
    if (ctx->r3 != ctx->r2) {
        // 0x800F6EE0: nop
    
            goto L_800F6F94;
    }
    // 0x800F6EE0: nop

    // 0x800F6EE4: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F6EE8: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F6EEC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6EF0: lwc1        $f2, -0x7200($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7200);
    // 0x800F6EF4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6EF8: nop

    // 0x800F6EFC: bc1tl       L_800F6F14
    if (c1cs) {
        // 0x800F6F00: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F6F14;
    }
    goto skip_15;
    // 0x800F6F00: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_15:
    // 0x800F6F04: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6F08: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6F0C: j           L_800F6F28
    // 0x800F6F10: sb          $v1, 0x1E($s0)
    MEM_B(0X1E, ctx->r16) = ctx->r3;
        goto L_800F6F28;
    // 0x800F6F10: sb          $v1, 0x1E($s0)
    MEM_B(0X1E, ctx->r16) = ctx->r3;
L_800F6F14:
    // 0x800F6F14: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F6F18: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6F1C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6F20: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F6F24: sb          $v1, 0x1E($s0)
    MEM_B(0X1E, ctx->r16) = ctx->r3;
L_800F6F28:
    // 0x800F6F28: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F6F2C: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F6F30: div.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800F6F34: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F6F38: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x800F6F3C: nop

    // 0x800F6F40: bc1f        L_800F6F4C
    if (!c1cs) {
        // 0x800F6F44: swc1        $f2, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
            goto L_800F6F4C;
    }
    // 0x800F6F44: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x800F6F48: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
L_800F6F4C:
    // 0x800F6F4C: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800F6F50: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F6F54: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6F58: lwc1        $f2, -0x71FC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X71FC);
    // 0x800F6F5C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6F60: nop

    // 0x800F6F64: bc1tl       L_800F6F7C
    if (c1cs) {
        // 0x800F6F68: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F6F7C;
    }
    goto skip_16;
    // 0x800F6F68: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_16:
    // 0x800F6F6C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6F70: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6F74: j           L_800F705C
    // 0x800F6F78: sb          $v1, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r3;
        goto L_800F705C;
    // 0x800F6F78: sb          $v1, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r3;
L_800F6F7C:
    // 0x800F6F7C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F6F80: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6F84: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F6F88: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F6F8C: j           L_800F705C
    // 0x800F6F90: sb          $v1, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r3;
        goto L_800F705C;
    // 0x800F6F90: sb          $v1, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r3;
L_800F6F94:
    // 0x800F6F94: lbu         $v0, 0x1A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1A);
    // 0x800F6F98: lbu         $v1, 0x20($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X20);
    // 0x800F6F9C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F6FA0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F6FA4: mtc1        $v1, $f2
    ctx->f2.u32l = ctx->r3;
    // 0x800F6FA8: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800F6FAC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F6FB0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6FB4: lwc1        $f2, -0x71F8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X71F8);
    // 0x800F6FB8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F6FBC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F6FC0: lwc1        $f2, -0x71F4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X71F4);
    // 0x800F6FC4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F6FC8: nop

    // 0x800F6FCC: bc1tl       L_800F6FE4
    if (c1cs) {
        // 0x800F6FD0: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F6FE4;
    }
    goto skip_17;
    // 0x800F6FD0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_17:
    // 0x800F6FD4: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6FD8: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800F6FDC: j           L_800F6FF4
    // 0x800F6FE0: nop

        goto L_800F6FF4;
    // 0x800F6FE0: nop

L_800F6FE4:
    // 0x800F6FE4: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F6FE8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F6FEC: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800F6FF0: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
L_800F6FF4:
    // 0x800F6FF4: lbu         $v0, 0x1B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1B);
    // 0x800F6FF8: lbu         $v1, 0x21($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X21);
    // 0x800F6FFC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F7000: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F7004: mtc1        $v1, $f2
    ctx->f2.u32l = ctx->r3;
    // 0x800F7008: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800F700C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F7010: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F7014: lwc1        $f2, -0x71F0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X71F0);
    // 0x800F7018: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F701C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F7020: lwc1        $f2, -0x71EC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X71EC);
    // 0x800F7024: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F7028: nop

    // 0x800F702C: bc1t        L_800F7044
    if (c1cs) {
        // 0x800F7030: sb          $a0, 0x1D($s0)
        MEM_B(0X1D, ctx->r16) = ctx->r4;
            goto L_800F7044;
    }
    // 0x800F7030: sb          $a0, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r4;
    // 0x800F7034: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F7038: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F703C: j           L_800F705C
    // 0x800F7040: sb          $v1, 0x1E($s0)
    MEM_B(0X1E, ctx->r16) = ctx->r3;
        goto L_800F705C;
    // 0x800F7040: sb          $v1, 0x1E($s0)
    MEM_B(0X1E, ctx->r16) = ctx->r3;
L_800F7044:
    // 0x800F7044: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F7048: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F704C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F7050: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F7054: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F7058: sb          $v1, 0x1E($s0)
    MEM_B(0X1E, ctx->r16) = ctx->r3;
L_800F705C:
    // 0x800F705C: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F7060: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F7064: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F7068: lwc1        $f2, -0x71E8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X71E8);
    // 0x800F706C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F7070: nop

    // 0x800F7074: bc1tl       L_800F708C
    if (c1cs) {
        // 0x800F7078: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F708C;
    }
    goto skip_18;
    // 0x800F7078: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_18:
    // 0x800F707C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F7080: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F7084: j           L_800F70A0
    // 0x800F7088: sb          $v1, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r3;
        goto L_800F70A0;
    // 0x800F7088: sb          $v1, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r3;
L_800F708C:
    // 0x800F708C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F7090: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F7094: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F7098: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F709C: sb          $v1, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r3;
L_800F70A0:
    // 0x800F70A0: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F70A4: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F70A8: div.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800F70AC: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F70B0: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x800F70B4: nop

    // 0x800F70B8: bc1f        L_800F70C4
    if (!c1cs) {
        // 0x800F70BC: swc1        $f2, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
            goto L_800F70C4;
    }
    // 0x800F70BC: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800F70C0: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
L_800F70C4:
    // 0x800F70C4: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800F70C8: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F70CC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F70D0: lwc1        $f2, -0x71E4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X71E4);
    // 0x800F70D4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F70D8: nop

    // 0x800F70DC: bc1tl       L_800F70F4
    if (c1cs) {
        // 0x800F70E0: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F70F4;
    }
    goto skip_19;
    // 0x800F70E0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_19:
    // 0x800F70E4: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F70E8: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F70EC: j           L_800F7108
    // 0x800F70F0: sb          $v1, 0x23($s0)
    MEM_B(0X23, ctx->r16) = ctx->r3;
        goto L_800F7108;
    // 0x800F70F0: sb          $v1, 0x23($s0)
    MEM_B(0X23, ctx->r16) = ctx->r3;
L_800F70F4:
    // 0x800F70F4: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F70F8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F70FC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F7100: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F7104: sb          $v1, 0x23($s0)
    MEM_B(0X23, ctx->r16) = ctx->r3;
L_800F7108:
    // 0x800F7108: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800F710C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800F7110: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800F7114: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800F7118: ldc1        $f26, 0x58($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X58);
    // 0x800F711C: ldc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X50);
    // 0x800F7120: ldc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X48);
    // 0x800F7124: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x800F7128: jr          $ra
    // 0x800F712C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800F712C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_800F7130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7130: addiu       $sp, $sp, -0x1B0
    ctx->r29 = ADD32(ctx->r29, -0X1B0);
    // 0x800F7134: sw          $ra, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r31;
    // 0x800F7138: sw          $fp, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->r30;
    // 0x800F713C: sw          $s7, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r23;
    // 0x800F7140: sw          $s6, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->r22;
    // 0x800F7144: sw          $s5, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r21;
    // 0x800F7148: sw          $s4, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r20;
    // 0x800F714C: sw          $s3, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r19;
    // 0x800F7150: sw          $s2, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r18;
    // 0x800F7154: sw          $s1, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r17;
    // 0x800F7158: sw          $s0, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r16;
    // 0x800F715C: sdc1        $f22, 0x1A8($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X1A8, ctx->r29);
    // 0x800F7160: sdc1        $f20, 0x1A0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X1A0, ctx->r29);
    // 0x800F7164: sw          $a0, 0x1B0($sp)
    MEM_W(0X1B0, ctx->r29) = ctx->r4;
    // 0x800F7168: sb          $zero, 0x160($sp)
    MEM_B(0X160, ctx->r29) = 0;
    // 0x800F716C: lhu         $a0, 0x198($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X198);
    // 0x800F7170: lw          $t0, 0x1B0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1B0);
    // 0x800F7174: lw          $t1, 0x1B0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1B0);
    // 0x800F7178: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800F717C: addiu       $s1, $t1, 0x50
    ctx->r17 = ADD32(ctx->r9, 0X50);
    // 0x800F7180: jal         0x8004015C
    // 0x800F7184: sw          $t0, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r8;
    getNpcContextField8(rdram, ctx);
        goto after_0;
    // 0x800F7184: sw          $t0, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r8;
    after_0:
    // 0x800F7188: addiu       $s2, $sp, 0x110
    ctx->r18 = ADD32(ctx->r29, 0X110);
    // 0x800F718C: addu        $v1, $s2, $zero
    ctx->r3 = ADD32(ctx->r18, 0);
    // 0x800F7190: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
L_800F7194:
    // 0x800F7194: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800F7198: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x800F719C: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x800F71A0: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x800F71A4: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800F71A8: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x800F71AC: sw          $t0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r8;
    // 0x800F71B0: sw          $t1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r9;
    // 0x800F71B4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800F71B8: bne         $v0, $a0, L_800F7194
    if (ctx->r2 != ctx->r4) {
        // 0x800F71BC: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800F7194;
    }
    // 0x800F71BC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800F71C0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800F71C4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800F71C8: jal         0x80059B50
    // 0x800F71CC: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    mat34CrossRowsAndCopyPos(rdram, ctx);
        goto after_1;
    // 0x800F71CC: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_1:
    // 0x800F71D0: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800F71D4: jal         0x8001C774
    // 0x800F71D8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    mat3x3InverseInto(rdram, ctx);
        goto after_2;
    // 0x800F71D8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x800F71DC: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
    // 0x800F71E0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800F71E4: jal         0x800078E0
    // 0x800F71E8: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    rs_memset(rdram, ctx);
        goto after_3;
    // 0x800F71E8: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    after_3:
    // 0x800F71EC: lw          $t2, 0x1B0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1B0);
    // 0x800F71F0: lhu         $v0, 0x110($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X110);
    // 0x800F71F4: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // 0x800F71F8: bne         $v0, $zero, L_800F77BC
    if (ctx->r2 != 0) {
        // 0x800F71FC: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_800F77BC;
    }
    // 0x800F71FC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F7200: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    // 0x800F7204: addiu       $a3, $sp, 0x158
    ctx->r7 = ADD32(ctx->r29, 0X158);
    // 0x800F7208: lhu         $a2, 0x198($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0X198);
    // 0x800F720C: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800F7210: addiu       $v0, $sp, 0x140
    ctx->r2 = ADD32(ctx->r29, 0X140);
    // 0x800F7214: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800F7218: addiu       $v0, $sp, 0xC8
    ctx->r2 = ADD32(ctx->r29, 0XC8);
    // 0x800F721C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800F7220: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F7224: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800F7228: addiu       $v0, $sp, 0x150
    ctx->r2 = ADD32(ctx->r29, 0X150);
    // 0x800F722C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800F7230: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800F7234: jal         0x800F1B40
    // 0x800F7238: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F1B40(rdram, ctx);
        goto after_4;
    // 0x800F7238: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x800F723C: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800F7240: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F7244: lwc1        $f2, -0x71E0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X71E0);
    // 0x800F7248: div.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800F724C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F7250: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F7254: lwc1        $f2, -0x71DC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X71DC);
    // 0x800F7258: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F725C: nop

    // 0x800F7260: bc1t        L_800F7278
    if (c1cs) {
        // 0x800F7264: addiu       $s4, $zero, 0x1
        ctx->r20 = ADD32(0, 0X1);
            goto L_800F7278;
    }
    // 0x800F7264: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800F7268: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F726C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F7270: j           L_800F728C
    // 0x800F7274: nop

        goto L_800F728C;
    // 0x800F7274: nop

L_800F7278:
    // 0x800F7278: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F727C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F7280: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F7284: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F7288: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_800F728C:
    // 0x800F728C: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800F7290: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F7294: lwc1        $f0, -0x71D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X71D8);
    // 0x800F7298: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F729C: addiu       $s0, $sp, 0x88
    ctx->r16 = ADD32(ctx->r29, 0X88);
    // 0x800F72A0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F72A4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800F72A8: addiu       $a1, $s2, 0x18
    ctx->r5 = ADD32(ctx->r18, 0X18);
    // 0x800F72AC: jal         0x8001D240
    // 0x800F72B0: sb          $v1, 0x1A($s1)
    MEM_B(0X1A, ctx->r17) = ctx->r3;
    quatFromAxisAngle(rdram, ctx);
        goto after_5;
    // 0x800F72B0: sb          $v1, 0x1A($s1)
    MEM_B(0X1A, ctx->r17) = ctx->r3;
    after_5:
    // 0x800F72B4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F72B8: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    // 0x800F72BC: addiu       $s0, $sp, 0xF0
    ctx->r16 = ADD32(ctx->r29, 0XF0);
    // 0x800F72C0: jal         0x8001D3C4
    // 0x800F72C4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_6;
    // 0x800F72C4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_6:
    // 0x800F72C8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F72CC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800F72D0: addiu       $a3, $sp, 0x158
    ctx->r7 = ADD32(ctx->r29, 0X158);
    // 0x800F72D4: lw          $t1, 0x1B0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1B0);
    // 0x800F72D8: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800F72DC: lhu         $a2, 0x198($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0X198);
    // 0x800F72E0: addiu       $v0, $sp, 0x144
    ctx->r2 = ADD32(ctx->r29, 0X144);
    // 0x800F72E4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800F72E8: addiu       $v0, $sp, 0xD4
    ctx->r2 = ADD32(ctx->r29, 0XD4);
    // 0x800F72EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800F72F0: addiu       $v0, $sp, 0x151
    ctx->r2 = ADD32(ctx->r29, 0X151);
    // 0x800F72F4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800F72F8: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800F72FC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800F7300: jal         0x800F1B40
    // 0x800F7304: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F1B40(rdram, ctx);
        goto after_7;
    // 0x800F7304: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x800F7308: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800F730C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F7310: lwc1        $f2, -0x71D4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X71D4);
    // 0x800F7314: div.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800F7318: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F731C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F7320: lwc1        $f2, -0x71D0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X71D0);
    // 0x800F7324: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F7328: nop

    // 0x800F732C: bc1tl       L_800F7344
    if (c1cs) {
        // 0x800F7330: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F7344;
    }
    goto skip_0;
    // 0x800F7330: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_0:
    // 0x800F7334: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F7338: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F733C: j           L_800F7354
    // 0x800F7340: nop

        goto L_800F7354;
    // 0x800F7340: nop

L_800F7344:
    // 0x800F7344: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F7348: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F734C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F7350: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_800F7354:
    // 0x800F7354: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800F7358: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F735C: lwc1        $f0, -0x71CC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X71CC);
    // 0x800F7360: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F7364: addiu       $s0, $sp, 0x98
    ctx->r16 = ADD32(ctx->r29, 0X98);
    // 0x800F7368: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F736C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800F7370: addiu       $a1, $s2, 0x18
    ctx->r5 = ADD32(ctx->r18, 0X18);
    // 0x800F7374: jal         0x8001D240
    // 0x800F7378: sb          $v1, 0x14($s1)
    MEM_B(0X14, ctx->r17) = ctx->r3;
    quatFromAxisAngle(rdram, ctx);
        goto after_8;
    // 0x800F7378: sb          $v1, 0x14($s1)
    MEM_B(0X14, ctx->r17) = ctx->r3;
    after_8:
    // 0x800F737C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F7380: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    // 0x800F7384: addiu       $s0, $sp, 0xF0
    ctx->r16 = ADD32(ctx->r29, 0XF0);
    // 0x800F7388: jal         0x8001D3C4
    // 0x800F738C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_9;
    // 0x800F738C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_9:
    // 0x800F7390: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F7394: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800F7398: addiu       $a3, $sp, 0x158
    ctx->r7 = ADD32(ctx->r29, 0X158);
    // 0x800F739C: lw          $t1, 0x1B0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1B0);
    // 0x800F73A0: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800F73A4: lhu         $a2, 0x198($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0X198);
    // 0x800F73A8: addiu       $v0, $sp, 0x148
    ctx->r2 = ADD32(ctx->r29, 0X148);
    // 0x800F73AC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800F73B0: addiu       $v0, $sp, 0xE0
    ctx->r2 = ADD32(ctx->r29, 0XE0);
    // 0x800F73B4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800F73B8: addiu       $v0, $sp, 0x152
    ctx->r2 = ADD32(ctx->r29, 0X152);
    // 0x800F73BC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800F73C0: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800F73C4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800F73C8: jal         0x800F1B40
    // 0x800F73CC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F1B40(rdram, ctx);
        goto after_10;
    // 0x800F73CC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x800F73D0: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800F73D4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F73D8: lwc1        $f2, -0x71C8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x800F73DC: div.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800F73E0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F73E4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F73E8: lwc1        $f2, -0x71C4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X71C4);
    // 0x800F73EC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F73F0: nop

    // 0x800F73F4: bc1tl       L_800F740C
    if (c1cs) {
        // 0x800F73F8: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F740C;
    }
    goto skip_1;
    // 0x800F73F8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_1:
    // 0x800F73FC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F7400: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F7404: j           L_800F7420
    // 0x800F7408: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
        goto L_800F7420;
    // 0x800F7408: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
L_800F740C:
    // 0x800F740C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F7410: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F7414: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F7418: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F741C: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
L_800F7420:
    // 0x800F7420: addiu       $s7, $sp, 0x100
    ctx->r23 = ADD32(ctx->r29, 0X100);
    // 0x800F7424: addiu       $s6, $sp, 0xF0
    ctx->r22 = ADD32(ctx->r29, 0XF0);
    // 0x800F7428: andi        $s4, $s4, 0xFF
    ctx->r20 = ctx->r20 & 0XFF;
    // 0x800F742C: addiu       $fp, $sp, 0xB8
    ctx->r30 = ADD32(ctx->r29, 0XB8);
    // 0x800F7430: addiu       $t1, $sp, 0x140
    ctx->r9 = ADD32(ctx->r29, 0X140);
    // 0x800F7434: addu        $s5, $t1, $zero
    ctx->r21 = ADD32(ctx->r9, 0);
    // 0x800F7438: addiu       $t2, $sp, 0xC8
    ctx->r10 = ADD32(ctx->r29, 0XC8);
    // 0x800F743C: addu        $s0, $t2, $zero
    ctx->r16 = ADD32(ctx->r10, 0);
    // 0x800F7440: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F7444: lwc1        $f22, -0x71C0($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X71C0);
    // 0x800F7448: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F744C: lwc1        $f20, -0x71BC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X71BC);
    // 0x800F7450: addiu       $t3, $sp, 0x150
    ctx->r11 = ADD32(ctx->r29, 0X150);
    // 0x800F7454: sw          $s4, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r20;
    // 0x800F7458: addu        $s4, $t3, $zero
    ctx->r20 = ADD32(ctx->r11, 0);
    // 0x800F745C: sw          $t1, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r9;
    // 0x800F7460: sw          $t2, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r10;
    // 0x800F7464: sw          $t3, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r11;
    // 0x800F7468: sb          $v1, 0x20($s1)
    MEM_B(0X20, ctx->r17) = ctx->r3;
L_800F746C:
    // 0x800F746C: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800F7470: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800F7474: beq         $v0, $zero, L_800F74A4
    if (ctx->r2 == 0) {
        // 0x800F7478: addiu       $a0, $sp, 0x58
        ctx->r4 = ADD32(ctx->r29, 0X58);
            goto L_800F74A4;
    }
    // 0x800F7478: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800F747C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800F7480: jal         0x800194A4
    // 0x800F7484: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    rotateVec3ByMat3x3(rdram, ctx);
        goto after_11;
    // 0x800F7484: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_11:
    // 0x800F7488: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800F748C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800F7490: lw          $a2, 0x0($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X0);
    // 0x800F7494: jal         0x800F5D34
    // 0x800F7498: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    func_800F5D34(rdram, ctx);
        goto after_12;
    // 0x800F7498: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    after_12:
    // 0x800F749C: j           L_800F77A4
    // 0x800F74A0: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
        goto L_800F77A4;
    // 0x800F74A0: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_800F74A4:
    // 0x800F74A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F74A8: beq         $s3, $v0, L_800F75AC
    if (ctx->r19 == ctx->r2) {
        // 0x800F74AC: slti        $v0, $s3, 0x2
        ctx->r2 = SIGNED(ctx->r19) < 0X2 ? 1 : 0;
            goto L_800F75AC;
    }
    // 0x800F74AC: slti        $v0, $s3, 0x2
    ctx->r2 = SIGNED(ctx->r19) < 0X2 ? 1 : 0;
    // 0x800F74B0: beq         $v0, $zero, L_800F74C8
    if (ctx->r2 == 0) {
        // 0x800F74B4: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800F74C8;
    }
    // 0x800F74B4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800F74B8: beq         $s3, $zero, L_800F74D8
    if (ctx->r19 == 0) {
        // 0x800F74BC: nop
    
            goto L_800F74D8;
    }
    // 0x800F74BC: nop

    // 0x800F74C0: j           L_800F77A4
    // 0x800F74C4: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
        goto L_800F77A4;
    // 0x800F74C4: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_800F74C8:
    // 0x800F74C8: beq         $s3, $v0, L_800F7690
    if (ctx->r19 == ctx->r2) {
        // 0x800F74CC: nop
    
            goto L_800F7690;
    }
    // 0x800F74CC: nop

    // 0x800F74D0: j           L_800F77A4
    // 0x800F74D4: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
        goto L_800F77A4;
    // 0x800F74D4: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_800F74D8:
    // 0x800F74D8: lbu         $v0, 0x160($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X160);
    // 0x800F74DC: bne         $v0, $zero, L_800F7518
    if (ctx->r2 != 0) {
        // 0x800F74E0: addiu       $a0, $sp, 0xA8
        ctx->r4 = ADD32(ctx->r29, 0XA8);
            goto L_800F7518;
    }
    // 0x800F74E0: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x800F74E4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800F74E8: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x800F74EC: addiu       $a1, $s2, 0x18
    ctx->r5 = ADD32(ctx->r18, 0X18);
    // 0x800F74F0: addiu       $a2, $s2, 0xC
    ctx->r6 = ADD32(ctx->r18, 0XC);
    // 0x800F74F4: jal         0x80019548
    // 0x800F74F8: sb          $t0, 0x160($sp)
    MEM_B(0X160, ctx->r29) = ctx->r8;
    vec3Cross(rdram, ctx);
        goto after_13;
    // 0x800F74F8: sb          $t0, 0x160($sp)
    MEM_B(0X160, ctx->r29) = ctx->r8;
    after_13:
    // 0x800F74FC: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800F7500: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x800F7504: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F7508: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800F750C: jal         0x8001D240
    // 0x800F7510: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    quatFromAxisAngle(rdram, ctx);
        goto after_14;
    // 0x800F7510: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    after_14:
    // 0x800F7514: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
L_800F7518:
    // 0x800F7518: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    // 0x800F751C: jal         0x8001D3C4
    // 0x800F7520: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_15;
    // 0x800F7520: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    after_15:
    // 0x800F7524: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F7528: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // 0x800F752C: lw          $t1, 0x1B0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1B0);
    // 0x800F7530: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800F7534: lw          $t2, 0x16C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X16C);
    // 0x800F7538: lw          $t3, 0x168($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X168);
    // 0x800F753C: lw          $t0, 0x170($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X170);
    // 0x800F7540: lhu         $a2, 0x198($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0X198);
    // 0x800F7544: lw          $t1, 0x164($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X164);
    // 0x800F7548: addiu       $a3, $sp, 0x158
    ctx->r7 = ADD32(ctx->r29, 0X158);
    // 0x800F754C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800F7550: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800F7554: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800F7558: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800F755C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800F7560: jal         0x800F1B40
    // 0x800F7564: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    func_800F1B40(rdram, ctx);
        goto after_16;
    // 0x800F7564: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    after_16:
    // 0x800F7568: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800F756C: div.s       $f2, $f22, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f22.fl, ctx->f2.fl);
    // 0x800F7570: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F7574: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x800F7578: nop

    // 0x800F757C: bc1tl       L_800F7594
    if (c1cs) {
        // 0x800F7580: sub.s       $f0, $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
            goto L_800F7594;
    }
    goto skip_2;
    // 0x800F7580: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    skip_2:
    // 0x800F7584: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F7588: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800F758C: j           L_800F7770
    // 0x800F7590: sb          $v0, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = ctx->r2;
        goto L_800F7770;
    // 0x800F7590: sb          $v0, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = ctx->r2;
L_800F7594:
    // 0x800F7594: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x800F7598: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F759C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800F75A0: or          $v0, $v0, $t1
    ctx->r2 = ctx->r2 | ctx->r9;
    // 0x800F75A4: j           L_800F7770
    // 0x800F75A8: sb          $v0, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = ctx->r2;
        goto L_800F7770;
    // 0x800F75A8: sb          $v0, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = ctx->r2;
L_800F75AC:
    // 0x800F75AC: lbu         $v0, 0x160($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X160);
    // 0x800F75B0: bne         $v0, $zero, L_800F75EC
    if (ctx->r2 != 0) {
        // 0x800F75B4: addiu       $a0, $sp, 0x88
        ctx->r4 = ADD32(ctx->r29, 0X88);
            goto L_800F75EC;
    }
    // 0x800F75B4: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x800F75B8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800F75BC: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x800F75C0: addiu       $a1, $s2, 0x18
    ctx->r5 = ADD32(ctx->r18, 0X18);
    // 0x800F75C4: addiu       $a2, $s2, 0xC
    ctx->r6 = ADD32(ctx->r18, 0XC);
    // 0x800F75C8: jal         0x80019548
    // 0x800F75CC: sb          $t2, 0x160($sp)
    MEM_B(0X160, ctx->r29) = ctx->r10;
    vec3Cross(rdram, ctx);
        goto after_17;
    // 0x800F75CC: sb          $t2, 0x160($sp)
    MEM_B(0X160, ctx->r29) = ctx->r10;
    after_17:
    // 0x800F75D0: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800F75D4: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x800F75D8: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F75DC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800F75E0: jal         0x8001D240
    // 0x800F75E4: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    quatFromAxisAngle(rdram, ctx);
        goto after_18;
    // 0x800F75E4: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    after_18:
    // 0x800F75E8: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
L_800F75EC:
    // 0x800F75EC: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    // 0x800F75F0: jal         0x8001D2C0
    // 0x800F75F4: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    quatMultiply(rdram, ctx);
        goto after_19;
    // 0x800F75F4: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    after_19:
    // 0x800F75F8: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // 0x800F75FC: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    // 0x800F7600: jal         0x8001D3C4
    // 0x800F7604: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_20;
    // 0x800F7604: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    after_20:
    // 0x800F7608: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F760C: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // 0x800F7610: addiu       $a3, $sp, 0x158
    ctx->r7 = ADD32(ctx->r29, 0X158);
    // 0x800F7614: lw          $t3, 0x1B0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1B0);
    // 0x800F7618: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800F761C: lw          $t0, 0x170($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X170);
    // 0x800F7620: lhu         $a2, 0x198($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X198);
    // 0x800F7624: addiu       $v0, $sp, 0x144
    ctx->r2 = ADD32(ctx->r29, 0X144);
    // 0x800F7628: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800F762C: addiu       $v0, $sp, 0xD4
    ctx->r2 = ADD32(ctx->r29, 0XD4);
    // 0x800F7630: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800F7634: addiu       $v0, $sp, 0x151
    ctx->r2 = ADD32(ctx->r29, 0X151);
    // 0x800F7638: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800F763C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800F7640: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800F7644: jal         0x800F1B40
    // 0x800F7648: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F1B40(rdram, ctx);
        goto after_21;
    // 0x800F7648: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_21:
    // 0x800F764C: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800F7650: div.s       $f2, $f22, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f22.fl, ctx->f2.fl);
    // 0x800F7654: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F7658: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x800F765C: nop

    // 0x800F7660: bc1tl       L_800F7678
    if (c1cs) {
        // 0x800F7664: sub.s       $f0, $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
            goto L_800F7678;
    }
    goto skip_3;
    // 0x800F7664: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    skip_3:
    // 0x800F7668: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F766C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800F7670: j           L_800F7770
    // 0x800F7674: sb          $v0, 0x15($s1)
    MEM_B(0X15, ctx->r17) = ctx->r2;
        goto L_800F7770;
    // 0x800F7674: sb          $v0, 0x15($s1)
    MEM_B(0X15, ctx->r17) = ctx->r2;
L_800F7678:
    // 0x800F7678: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x800F767C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F7680: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800F7684: or          $v0, $v0, $t1
    ctx->r2 = ctx->r2 | ctx->r9;
    // 0x800F7688: j           L_800F7770
    // 0x800F768C: sb          $v0, 0x15($s1)
    MEM_B(0X15, ctx->r17) = ctx->r2;
        goto L_800F7770;
    // 0x800F768C: sb          $v0, 0x15($s1)
    MEM_B(0X15, ctx->r17) = ctx->r2;
L_800F7690:
    // 0x800F7690: lbu         $v0, 0x160($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X160);
    // 0x800F7694: bne         $v0, $zero, L_800F76D0
    if (ctx->r2 != 0) {
        // 0x800F7698: addiu       $a0, $sp, 0x98
        ctx->r4 = ADD32(ctx->r29, 0X98);
            goto L_800F76D0;
    }
    // 0x800F7698: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    // 0x800F769C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800F76A0: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x800F76A4: addiu       $a1, $s2, 0x18
    ctx->r5 = ADD32(ctx->r18, 0X18);
    // 0x800F76A8: addiu       $a2, $s2, 0xC
    ctx->r6 = ADD32(ctx->r18, 0XC);
    // 0x800F76AC: jal         0x80019548
    // 0x800F76B0: sb          $t2, 0x160($sp)
    MEM_B(0X160, ctx->r29) = ctx->r10;
    vec3Cross(rdram, ctx);
        goto after_22;
    // 0x800F76B0: sb          $t2, 0x160($sp)
    MEM_B(0X160, ctx->r29) = ctx->r10;
    after_22:
    // 0x800F76B4: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800F76B8: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x800F76BC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F76C0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800F76C4: jal         0x8001D240
    // 0x800F76C8: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    quatFromAxisAngle(rdram, ctx);
        goto after_23;
    // 0x800F76C8: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    after_23:
    // 0x800F76CC: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
L_800F76D0:
    // 0x800F76D0: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    // 0x800F76D4: jal         0x8001D2C0
    // 0x800F76D8: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    quatMultiply(rdram, ctx);
        goto after_24;
    // 0x800F76D8: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    after_24:
    // 0x800F76DC: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // 0x800F76E0: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    // 0x800F76E4: jal         0x8001D3C4
    // 0x800F76E8: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_25;
    // 0x800F76E8: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    after_25:
    // 0x800F76EC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F76F0: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // 0x800F76F4: addiu       $a3, $sp, 0x158
    ctx->r7 = ADD32(ctx->r29, 0X158);
    // 0x800F76F8: lw          $t3, 0x1B0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1B0);
    // 0x800F76FC: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800F7700: lw          $t0, 0x170($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X170);
    // 0x800F7704: lhu         $a2, 0x198($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X198);
    // 0x800F7708: addiu       $v0, $sp, 0x148
    ctx->r2 = ADD32(ctx->r29, 0X148);
    // 0x800F770C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800F7710: addiu       $v0, $sp, 0xE0
    ctx->r2 = ADD32(ctx->r29, 0XE0);
    // 0x800F7714: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800F7718: addiu       $v0, $sp, 0x152
    ctx->r2 = ADD32(ctx->r29, 0X152);
    // 0x800F771C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800F7720: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800F7724: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800F7728: jal         0x800F1B40
    // 0x800F772C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F1B40(rdram, ctx);
        goto after_26;
    // 0x800F772C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_26:
    // 0x800F7730: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800F7734: div.s       $f2, $f22, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f22.fl, ctx->f2.fl);
    // 0x800F7738: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F773C: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x800F7740: nop

    // 0x800F7744: bc1tl       L_800F775C
    if (c1cs) {
        // 0x800F7748: sub.s       $f0, $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
            goto L_800F775C;
    }
    goto skip_4;
    // 0x800F7748: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    skip_4:
    // 0x800F774C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F7750: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800F7754: j           L_800F7770
    // 0x800F7758: sb          $v0, 0x21($s1)
    MEM_B(0X21, ctx->r17) = ctx->r2;
        goto L_800F7770;
    // 0x800F7758: sb          $v0, 0x21($s1)
    MEM_B(0X21, ctx->r17) = ctx->r2;
L_800F775C:
    // 0x800F775C: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x800F7760: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F7764: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800F7768: or          $v0, $v0, $t1
    ctx->r2 = ctx->r2 | ctx->r9;
    // 0x800F776C: sb          $v0, 0x21($s1)
    MEM_B(0X21, ctx->r17) = ctx->r2;
L_800F7770:
    // 0x800F7770: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800F7774: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800F7778: beq         $v0, $zero, L_800F77A0
    if (ctx->r2 == 0) {
        // 0x800F777C: addiu       $a0, $sp, 0x58
        ctx->r4 = ADD32(ctx->r29, 0X58);
            goto L_800F77A0;
    }
    // 0x800F777C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800F7780: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800F7784: jal         0x800194A4
    // 0x800F7788: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    rotateVec3ByMat3x3(rdram, ctx);
        goto after_27;
    // 0x800F7788: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_27:
    // 0x800F778C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800F7790: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800F7794: lw          $a2, 0x0($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X0);
    // 0x800F7798: jal         0x800F6954
    // 0x800F779C: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    func_800F6954(rdram, ctx);
        goto after_28;
    // 0x800F779C: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    after_28:
L_800F77A0:
    // 0x800F77A0: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_800F77A4:
    // 0x800F77A4: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800F77A8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800F77AC: slti        $v0, $s3, 0x3
    ctx->r2 = SIGNED(ctx->r19) < 0X3 ? 1 : 0;
    // 0x800F77B0: bne         $v0, $zero, L_800F746C
    if (ctx->r2 != 0) {
        // 0x800F77B4: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_800F746C;
    }
    // 0x800F77B4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800F77B8: lw          $t2, 0x1B0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1B0);
L_800F77BC:
    // 0x800F77BC: lhu         $v0, 0x110($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X110);
    // 0x800F77C0: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x800F77C4: bne         $v0, $zero, L_800F7C3C
    if (ctx->r2 != 0) {
        // 0x800F77C8: nop
    
            goto L_800F7C3C;
    }
    // 0x800F77C8: nop

    // 0x800F77CC: lbu         $v0, 0x160($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X160);
    // 0x800F77D0: bne         $v0, $zero, L_800F77EC
    if (ctx->r2 != 0) {
        // 0x800F77D4: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_800F77EC;
    }
    // 0x800F77D4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F77D8: addiu       $a0, $sp, 0x100
    ctx->r4 = ADD32(ctx->r29, 0X100);
    // 0x800F77DC: addiu       $a1, $s2, 0x18
    ctx->r5 = ADD32(ctx->r18, 0X18);
    // 0x800F77E0: jal         0x80019548
    // 0x800F77E4: addiu       $a2, $s2, 0xC
    ctx->r6 = ADD32(ctx->r18, 0XC);
    vec3Cross(rdram, ctx);
        goto after_29;
    // 0x800F77E4: addiu       $a2, $s2, 0xC
    ctx->r6 = ADD32(ctx->r18, 0XC);
    after_29:
    // 0x800F77E8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_800F77EC:
    // 0x800F77EC: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    // 0x800F77F0: addiu       $a3, $sp, 0x158
    ctx->r7 = ADD32(ctx->r29, 0X158);
    // 0x800F77F4: lw          $t3, 0x1B0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1B0);
    // 0x800F77F8: lbu         $v0, 0x1A($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1A);
    // 0x800F77FC: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800F7800: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F7804: lwc1        $f20, -0x71B8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X71B8);
    // 0x800F7808: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F780C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F7810: div.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800F7814: lhu         $a2, 0x198($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X198);
    // 0x800F7818: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800F781C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800F7820: addiu       $v0, $sp, 0x150
    ctx->r2 = ADD32(ctx->r29, 0X150);
    // 0x800F7824: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F7828: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800F782C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800F7830: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800F7834: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800F7838: jal         0x800F1B40
    // 0x800F783C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F1B40(rdram, ctx);
        goto after_30;
    // 0x800F783C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_30:
    // 0x800F7840: lbu         $v0, 0x150($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X150);
    // 0x800F7844: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800F7848: beq         $v0, $zero, L_800F78A8
    if (ctx->r2 == 0) {
        // 0x800F784C: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800F78A8;
    }
    // 0x800F784C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800F7850: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800F7854: div.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800F7858: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F785C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F7860: lwc1        $f2, -0x71B4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X71B4);
    // 0x800F7864: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F7868: nop

    // 0x800F786C: bc1tl       L_800F7884
    if (c1cs) {
        // 0x800F7870: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F7884;
    }
    goto skip_5;
    // 0x800F7870: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_5:
    // 0x800F7874: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F7878: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F787C: j           L_800F7898
    // 0x800F7880: sb          $v1, 0x1A($s1)
    MEM_B(0X1A, ctx->r17) = ctx->r3;
        goto L_800F7898;
    // 0x800F7880: sb          $v1, 0x1A($s1)
    MEM_B(0X1A, ctx->r17) = ctx->r3;
L_800F7884:
    // 0x800F7884: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F7888: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F788C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F7890: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F7894: sb          $v1, 0x1A($s1)
    MEM_B(0X1A, ctx->r17) = ctx->r3;
L_800F7898:
    // 0x800F7898: lhu         $v0, 0x158($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X158);
    // 0x800F789C: lw          $t1, 0x15C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X15C);
    // 0x800F78A0: j           L_800F78B4
    // 0x800F78A4: sh          $v0, 0xF0($t1)
    MEM_H(0XF0, ctx->r9) = ctx->r2;
        goto L_800F78B4;
    // 0x800F78A4: sh          $v0, 0xF0($t1)
    MEM_H(0XF0, ctx->r9) = ctx->r2;
L_800F78A8:
    // 0x800F78A8: lw          $t2, 0x15C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X15C);
    // 0x800F78AC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800F78B0: sh          $v0, 0xF0($t2)
    MEM_H(0XF0, ctx->r10) = ctx->r2;
L_800F78B4:
    // 0x800F78B4: addiu       $s0, $sp, 0xB8
    ctx->r16 = ADD32(ctx->r29, 0XB8);
    // 0x800F78B8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F78BC: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x800F78C0: jal         0x8001D240
    // 0x800F78C4: addiu       $a1, $sp, 0x100
    ctx->r5 = ADD32(ctx->r29, 0X100);
    quatFromAxisAngle(rdram, ctx);
        goto after_31;
    // 0x800F78C4: addiu       $a1, $sp, 0x100
    ctx->r5 = ADD32(ctx->r29, 0X100);
    after_31:
    // 0x800F78C8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F78CC: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    // 0x800F78D0: addiu       $s0, $sp, 0xF0
    ctx->r16 = ADD32(ctx->r29, 0XF0);
    // 0x800F78D4: jal         0x8001D3C4
    // 0x800F78D8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_32;
    // 0x800F78D8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_32:
    // 0x800F78DC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F78E0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800F78E4: addiu       $a3, $sp, 0x158
    ctx->r7 = ADD32(ctx->r29, 0X158);
    // 0x800F78E8: lw          $t3, 0x1B0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1B0);
    // 0x800F78EC: lbu         $v0, 0x19($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X19);
    // 0x800F78F0: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800F78F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F78F8: lwc1        $f20, -0x71B0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X71B0);
    // 0x800F78FC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F7900: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F7904: div.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800F7908: lhu         $a2, 0x198($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X198);
    // 0x800F790C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800F7910: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800F7914: addiu       $v0, $sp, 0x150
    ctx->r2 = ADD32(ctx->r29, 0X150);
    // 0x800F7918: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F791C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800F7920: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800F7924: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800F7928: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800F792C: jal         0x800F1B40
    // 0x800F7930: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F1B40(rdram, ctx);
        goto after_33;
    // 0x800F7930: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_33:
    // 0x800F7934: lbu         $v0, 0x150($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X150);
    // 0x800F7938: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800F793C: beq         $v0, $zero, L_800F798C
    if (ctx->r2 == 0) {
        // 0x800F7940: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800F798C;
    }
    // 0x800F7940: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800F7944: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800F7948: div.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800F794C: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F7950: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F7954: lwc1        $f2, -0x71AC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X71AC);
    // 0x800F7958: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F795C: nop

    // 0x800F7960: bc1tl       L_800F7978
    if (c1cs) {
        // 0x800F7964: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F7978;
    }
    goto skip_6;
    // 0x800F7964: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_6:
    // 0x800F7968: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F796C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F7970: j           L_800F798C
    // 0x800F7974: sb          $v1, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r3;
        goto L_800F798C;
    // 0x800F7974: sb          $v1, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r3;
L_800F7978:
    // 0x800F7978: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F797C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F7980: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F7984: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F7988: sb          $v1, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r3;
L_800F798C:
    // 0x800F798C: addiu       $s0, $sp, 0xB8
    ctx->r16 = ADD32(ctx->r29, 0XB8);
    // 0x800F7990: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800F7994: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F7998: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F799C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800F79A0: jal         0x8001D240
    // 0x800F79A4: addiu       $a1, $sp, 0x100
    ctx->r5 = ADD32(ctx->r29, 0X100);
    quatFromAxisAngle(rdram, ctx);
        goto after_34;
    // 0x800F79A4: addiu       $a1, $sp, 0x100
    ctx->r5 = ADD32(ctx->r29, 0X100);
    after_34:
    // 0x800F79A8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F79AC: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    // 0x800F79B0: addiu       $s0, $sp, 0xF0
    ctx->r16 = ADD32(ctx->r29, 0XF0);
    // 0x800F79B4: jal         0x8001D3C4
    // 0x800F79B8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_35;
    // 0x800F79B8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_35:
    // 0x800F79BC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F79C0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800F79C4: addiu       $a3, $sp, 0x158
    ctx->r7 = ADD32(ctx->r29, 0X158);
    // 0x800F79C8: lw          $t1, 0x1B0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1B0);
    // 0x800F79CC: lbu         $v0, 0x1B($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1B);
    // 0x800F79D0: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800F79D4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F79D8: lwc1        $f20, -0x71A8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X71A8);
    // 0x800F79DC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F79E0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F79E4: div.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800F79E8: lhu         $a2, 0x198($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0X198);
    // 0x800F79EC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800F79F0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800F79F4: addiu       $v0, $sp, 0x150
    ctx->r2 = ADD32(ctx->r29, 0X150);
    // 0x800F79F8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F79FC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800F7A00: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800F7A04: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800F7A08: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800F7A0C: jal         0x800F1B40
    // 0x800F7A10: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F1B40(rdram, ctx);
        goto after_36;
    // 0x800F7A10: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_36:
    // 0x800F7A14: lbu         $v0, 0x150($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X150);
    // 0x800F7A18: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800F7A1C: beq         $v0, $zero, L_800F7A6C
    if (ctx->r2 == 0) {
        // 0x800F7A20: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800F7A6C;
    }
    // 0x800F7A20: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800F7A24: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800F7A28: div.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800F7A2C: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F7A30: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F7A34: lwc1        $f2, -0x71A4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X71A4);
    // 0x800F7A38: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F7A3C: nop

    // 0x800F7A40: bc1tl       L_800F7A58
    if (c1cs) {
        // 0x800F7A44: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F7A58;
    }
    goto skip_7;
    // 0x800F7A44: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_7:
    // 0x800F7A48: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F7A4C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F7A50: j           L_800F7A6C
    // 0x800F7A54: sb          $v1, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = ctx->r3;
        goto L_800F7A6C;
    // 0x800F7A54: sb          $v1, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = ctx->r3;
L_800F7A58:
    // 0x800F7A58: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F7A5C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F7A60: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F7A64: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F7A68: sb          $v1, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = ctx->r3;
L_800F7A6C:
    // 0x800F7A6C: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800F7A70: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F7A74: lwc1        $f0, -0x71A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X71A0);
    // 0x800F7A78: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F7A7C: addiu       $s0, $sp, 0xB8
    ctx->r16 = ADD32(ctx->r29, 0XB8);
    // 0x800F7A80: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F7A84: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800F7A88: jal         0x8001D240
    // 0x800F7A8C: addiu       $a1, $s2, 0x18
    ctx->r5 = ADD32(ctx->r18, 0X18);
    quatFromAxisAngle(rdram, ctx);
        goto after_37;
    // 0x800F7A8C: addiu       $a1, $s2, 0x18
    ctx->r5 = ADD32(ctx->r18, 0X18);
    after_37:
    // 0x800F7A90: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F7A94: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    // 0x800F7A98: addiu       $s0, $sp, 0xF0
    ctx->r16 = ADD32(ctx->r29, 0XF0);
    // 0x800F7A9C: jal         0x8001D3C4
    // 0x800F7AA0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_38;
    // 0x800F7AA0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_38:
    // 0x800F7AA4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F7AA8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800F7AAC: addiu       $a3, $sp, 0x158
    ctx->r7 = ADD32(ctx->r29, 0X158);
    // 0x800F7AB0: lw          $t1, 0x1B0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1B0);
    // 0x800F7AB4: lbu         $v0, 0x17($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X17);
    // 0x800F7AB8: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800F7ABC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F7AC0: lwc1        $f20, -0x719C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X719C);
    // 0x800F7AC4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F7AC8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F7ACC: div.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800F7AD0: lhu         $a2, 0x198($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0X198);
    // 0x800F7AD4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800F7AD8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800F7ADC: addiu       $v0, $sp, 0x150
    ctx->r2 = ADD32(ctx->r29, 0X150);
    // 0x800F7AE0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F7AE4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800F7AE8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800F7AEC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800F7AF0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800F7AF4: jal         0x800F1B40
    // 0x800F7AF8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F1B40(rdram, ctx);
        goto after_39;
    // 0x800F7AF8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_39:
    // 0x800F7AFC: lbu         $v0, 0x150($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X150);
    // 0x800F7B00: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800F7B04: beq         $v0, $zero, L_800F7B54
    if (ctx->r2 == 0) {
        // 0x800F7B08: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800F7B54;
    }
    // 0x800F7B08: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800F7B0C: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800F7B10: div.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800F7B14: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F7B18: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F7B1C: lwc1        $f2, -0x7198($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7198);
    // 0x800F7B20: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F7B24: nop

    // 0x800F7B28: bc1tl       L_800F7B40
    if (c1cs) {
        // 0x800F7B2C: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F7B40;
    }
    goto skip_8;
    // 0x800F7B2C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_8:
    // 0x800F7B30: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F7B34: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F7B38: j           L_800F7B54
    // 0x800F7B3C: sb          $v1, 0x17($s1)
    MEM_B(0X17, ctx->r17) = ctx->r3;
        goto L_800F7B54;
    // 0x800F7B3C: sb          $v1, 0x17($s1)
    MEM_B(0X17, ctx->r17) = ctx->r3;
L_800F7B40:
    // 0x800F7B40: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F7B44: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F7B48: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F7B4C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F7B50: sb          $v1, 0x17($s1)
    MEM_B(0X17, ctx->r17) = ctx->r3;
L_800F7B54:
    // 0x800F7B54: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800F7B58: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F7B5C: lwc1        $f0, -0x7194($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7194);
    // 0x800F7B60: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F7B64: addiu       $s0, $sp, 0xB8
    ctx->r16 = ADD32(ctx->r29, 0XB8);
    // 0x800F7B68: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F7B6C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800F7B70: jal         0x8001D240
    // 0x800F7B74: addiu       $a1, $s2, 0x18
    ctx->r5 = ADD32(ctx->r18, 0X18);
    quatFromAxisAngle(rdram, ctx);
        goto after_40;
    // 0x800F7B74: addiu       $a1, $s2, 0x18
    ctx->r5 = ADD32(ctx->r18, 0X18);
    after_40:
    // 0x800F7B78: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F7B7C: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    // 0x800F7B80: addiu       $s0, $sp, 0xF0
    ctx->r16 = ADD32(ctx->r29, 0XF0);
    // 0x800F7B84: jal         0x8001D3C4
    // 0x800F7B88: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_41;
    // 0x800F7B88: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_41:
    // 0x800F7B8C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F7B90: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800F7B94: addiu       $a3, $sp, 0x158
    ctx->r7 = ADD32(ctx->r29, 0X158);
    // 0x800F7B98: lw          $t1, 0x1B0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1B0);
    // 0x800F7B9C: lbu         $v0, 0x1D($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1D);
    // 0x800F7BA0: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800F7BA4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F7BA8: lwc1        $f20, -0x7190($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7190);
    // 0x800F7BAC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F7BB0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F7BB4: div.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800F7BB8: lhu         $a2, 0x198($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0X198);
    // 0x800F7BBC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800F7BC0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800F7BC4: addiu       $v0, $sp, 0x150
    ctx->r2 = ADD32(ctx->r29, 0X150);
    // 0x800F7BC8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F7BCC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800F7BD0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800F7BD4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800F7BD8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800F7BDC: jal         0x800F1B40
    // 0x800F7BE0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F1B40(rdram, ctx);
        goto after_42;
    // 0x800F7BE0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_42:
    // 0x800F7BE4: lbu         $v0, 0x150($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X150);
    // 0x800F7BE8: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800F7BEC: beq         $v0, $zero, L_800F7C3C
    if (ctx->r2 == 0) {
        // 0x800F7BF0: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800F7C3C;
    }
    // 0x800F7BF0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800F7BF4: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800F7BF8: div.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800F7BFC: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F7C00: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F7C04: lwc1        $f2, -0x718C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X718C);
    // 0x800F7C08: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F7C0C: nop

    // 0x800F7C10: bc1tl       L_800F7C28
    if (c1cs) {
        // 0x800F7C14: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800F7C28;
    }
    goto skip_9;
    // 0x800F7C14: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_9:
    // 0x800F7C18: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F7C1C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F7C20: j           L_800F7C3C
    // 0x800F7C24: sb          $v1, 0x1D($s1)
    MEM_B(0X1D, ctx->r17) = ctx->r3;
        goto L_800F7C3C;
    // 0x800F7C24: sb          $v1, 0x1D($s1)
    MEM_B(0X1D, ctx->r17) = ctx->r3;
L_800F7C28:
    // 0x800F7C28: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F7C2C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F7C30: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800F7C34: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F7C38: sb          $v1, 0x1D($s1)
    MEM_B(0X1D, ctx->r17) = ctx->r3;
L_800F7C3C:
    // 0x800F7C3C: lw          $ra, 0x19C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X19C);
    // 0x800F7C40: lw          $fp, 0x198($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X198);
    // 0x800F7C44: lw          $s7, 0x194($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X194);
    // 0x800F7C48: lw          $s6, 0x190($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X190);
    // 0x800F7C4C: lw          $s5, 0x18C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X18C);
    // 0x800F7C50: lw          $s4, 0x188($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X188);
    // 0x800F7C54: lw          $s3, 0x184($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X184);
    // 0x800F7C58: lw          $s2, 0x180($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X180);
    // 0x800F7C5C: lw          $s1, 0x17C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X17C);
    // 0x800F7C60: lw          $s0, 0x178($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X178);
    // 0x800F7C64: ldc1        $f22, 0x1A8($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X1A8);
    // 0x800F7C68: ldc1        $f20, 0x1A0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X1A0);
    // 0x800F7C6C: jr          $ra
    // 0x800F7C70: addiu       $sp, $sp, 0x1B0
    ctx->r29 = ADD32(ctx->r29, 0X1B0);
    return;
    // 0x800F7C70: addiu       $sp, $sp, 0x1B0
    ctx->r29 = ADD32(ctx->r29, 0X1B0);
;}
RECOMP_FUNC void func_800F7C74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7C74: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x800F7C78: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x800F7C7C: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800F7C80: sw          $s3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r19;
    // 0x800F7C84: addu        $s3, $s2, $zero
    ctx->r19 = ADD32(ctx->r18, 0);
    // 0x800F7C88: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800F7C8C: sw          $s0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r16;
    // 0x800F7C90: addiu       $s0, $a0, 0x50
    ctx->r16 = ADD32(ctx->r4, 0X50);
    // 0x800F7C94: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800F7C98: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800F7C9C: sw          $ra, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r31;
    // 0x800F7CA0: sw          $fp, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r30;
    // 0x800F7CA4: sw          $s7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r23;
    // 0x800F7CA8: sw          $s6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r22;
    // 0x800F7CAC: sw          $s5, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r21;
    // 0x800F7CB0: sw          $s4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r20;
    // 0x800F7CB4: sw          $s1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r17;
    // 0x800F7CB8: sdc1        $f20, 0xC0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XC0, ctx->r29);
    // 0x800F7CBC: sw          $a2, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r6;
    // 0x800F7CC0: sw          $a3, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r7;
    // 0x800F7CC4: lbu         $v1, 0x1A($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1A);
    // 0x800F7CC8: beq         $v1, $v0, L_800F8350
    if (ctx->r3 == ctx->r2) {
        // 0x800F7CCC: mov.s       $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = ctx->f6.fl;
            goto L_800F8350;
    }
    // 0x800F7CCC: mov.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = ctx->f6.fl;
    // 0x800F7CD0: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x800F7CD4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F7CD8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F7CDC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F7CE0: lwc1        $f2, -0x7188($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7188);
    // 0x800F7CE4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800F7CE8: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F7CEC: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800F7CF0: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800F7CF4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800F7CF8: nop

    // 0x800F7CFC: bc1f        L_800F8350
    if (!c1cs) {
        // 0x800F7D00: addu        $a3, $s2, $zero
        ctx->r7 = ADD32(ctx->r18, 0);
            goto L_800F8350;
    }
    // 0x800F7D00: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x800F7D04: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x800F7D08: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800F7D0C: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    // 0x800F7D10: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    // 0x800F7D14: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800F7D18: addiu       $v1, $sp, 0x60
    ctx->r3 = ADD32(ctx->r29, 0X60);
L_800F7D1C:
    // 0x800F7D1C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800F7D20: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x800F7D24: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x800F7D28: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x800F7D2C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800F7D30: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800F7D34: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800F7D38: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800F7D3C: slti        $v0, $a3, 0x3
    ctx->r2 = SIGNED(ctx->r7) < 0X3 ? 1 : 0;
    // 0x800F7D40: bne         $v0, $zero, L_800F7D1C
    if (ctx->r2 != 0) {
        // 0x800F7D44: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800F7D1C;
    }
    // 0x800F7D44: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800F7D48: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x800F7D4C: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x800F7D50: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x800F7D54: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800F7D58: lbu         $v0, 0x19($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X19);
    // 0x800F7D5C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F7D60: lwc1        $f4, -0x7184($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7184);
    // 0x800F7D64: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800F7D68: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F7D6C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F7D70: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800F7D74: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F7D78: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800F7D7C: addiu       $fp, $sp, 0x70
    ctx->r30 = ADD32(ctx->r29, 0X70);
    // 0x800F7D80: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x800F7D84: addiu       $s7, $sp, 0x30
    ctx->r23 = ADD32(ctx->r29, 0X30);
    // 0x800F7D88: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x800F7D8C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800F7D90: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800F7D94: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800F7D98: lbu         $v0, 0x1B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1B);
    // 0x800F7D9C: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800F7DA0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F7DA4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F7DA8: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800F7DAC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F7DB0: addiu       $s6, $sp, 0x10
    ctx->r22 = ADD32(ctx->r29, 0X10);
    // 0x800F7DB4: addiu       $s5, $sp, 0x50
    ctx->r21 = ADD32(ctx->r29, 0X50);
    // 0x800F7DB8: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x800F7DBC: sw          $s5, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r21;
    // 0x800F7DC0: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x800F7DC4: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800F7DC8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800F7DCC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
L_800F7DD0:
    // 0x800F7DD0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800F7DD4: addu        $s1, $t6, $zero
    ctx->r17 = ADD32(ctx->r14, 0);
    // 0x800F7DD8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800F7DDC: subu        $t4, $v0, $a3
    ctx->r12 = SUB32(ctx->r2, ctx->r7);
    // 0x800F7DE0: sll         $v0, $t4, 1
    ctx->r2 = S32(ctx->r12 << 1);
    // 0x800F7DE4: addu        $t9, $v0, $t4
    ctx->r25 = ADD32(ctx->r2, ctx->r12);
    // 0x800F7DE8: addiu       $t8, $sp, 0x80
    ctx->r24 = ADD32(ctx->r29, 0X80);
    // 0x800F7DEC: addiu       $t7, $sp, 0x40
    ctx->r15 = ADD32(ctx->r29, 0X40);
    // 0x800F7DF0: addiu       $t5, $sp, 0x60
    ctx->r13 = ADD32(ctx->r29, 0X60);
    // 0x800F7DF4: addiu       $t1, $sp, 0x20
    ctx->r9 = ADD32(ctx->r29, 0X20);
    // 0x800F7DF8: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x800F7DFC: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
    // 0x800F7E00: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    // 0x800F7E04: addu        $t2, $s7, $zero
    ctx->r10 = ADD32(ctx->r23, 0);
    // 0x800F7E08: addu        $a1, $fp, $zero
    ctx->r5 = ADD32(ctx->r30, 0);
L_800F7E0C:
    // 0x800F7E0C: addu        $v0, $a0, $s1
    ctx->r2 = ADD32(ctx->r4, ctx->r17);
    // 0x800F7E10: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800F7E14: lbu         $v0, 0x10($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X10);
    // 0x800F7E18: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800F7E1C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F7E20: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F7E24: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800F7E28: mul.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F7E2C: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800F7E30: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800F7E34: nop

    // 0x800F7E38: bc1f        L_800F7E54
    if (!c1cs) {
        // 0x800F7E3C: nop
    
            goto L_800F7E54;
    }
    // 0x800F7E3C: nop

    // 0x800F7E40: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800F7E44: bne         $v0, $s4, L_800F7E54
    if (ctx->r2 != ctx->r20) {
        // 0x800F7E48: nop
    
            goto L_800F7E54;
    }
    // 0x800F7E48: nop

    // 0x800F7E4C: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x800F7E50: swc1        $f2, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f2.u32l;
L_800F7E54:
    // 0x800F7E54: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800F7E58: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800F7E5C: nop

    // 0x800F7E60: bc1f        L_800F7E70
    if (!c1cs) {
        // 0x800F7E64: addu        $v0, $a0, $t9
        ctx->r2 = ADD32(ctx->r4, ctx->r25);
            goto L_800F7E70;
    }
    // 0x800F7E64: addu        $v0, $a0, $t9
    ctx->r2 = ADD32(ctx->r4, ctx->r25);
    // 0x800F7E68: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
    // 0x800F7E6C: sw          $a3, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r7;
L_800F7E70:
    // 0x800F7E70: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800F7E74: lbu         $v0, 0x10($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X10);
    // 0x800F7E78: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800F7E7C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F7E80: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F7E84: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800F7E88: mul.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F7E8C: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800F7E90: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800F7E94: nop

    // 0x800F7E98: bc1f        L_800F7EB4
    if (!c1cs) {
        // 0x800F7E9C: addu        $v1, $t8, $t0
        ctx->r3 = ADD32(ctx->r24, ctx->r8);
            goto L_800F7EB4;
    }
    // 0x800F7E9C: addu        $v1, $t8, $t0
    ctx->r3 = ADD32(ctx->r24, ctx->r8);
    // 0x800F7EA0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800F7EA4: bne         $v0, $s4, L_800F7EB4
    if (ctx->r2 != ctx->r20) {
        // 0x800F7EA8: addu        $v0, $t7, $t0
        ctx->r2 = ADD32(ctx->r15, ctx->r8);
            goto L_800F7EB4;
    }
    // 0x800F7EA8: addu        $v0, $t7, $t0
    ctx->r2 = ADD32(ctx->r15, ctx->r8);
    // 0x800F7EAC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800F7EB0: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
L_800F7EB4:
    // 0x800F7EB4: lwc1        $f0, 0x0($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800F7EB8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800F7EBC: nop

    // 0x800F7EC0: bc1fl       L_800F7ED4
    if (!c1cs) {
        // 0x800F7EC4: addiu       $t5, $t5, 0x4
        ctx->r13 = ADD32(ctx->r13, 0X4);
            goto L_800F7ED4;
    }
    goto skip_0;
    // 0x800F7EC4: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    skip_0:
    // 0x800F7EC8: swc1        $f2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f2.u32l;
    // 0x800F7ECC: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800F7ED0: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
L_800F7ED4:
    // 0x800F7ED4: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800F7ED8: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800F7EDC: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x800F7EE0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800F7EE4: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x800F7EE8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800F7EEC: slti        $v0, $a0, 0x3
    ctx->r2 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x800F7EF0: bne         $v0, $zero, L_800F7E0C
    if (ctx->r2 != 0) {
        // 0x800F7EF4: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_800F7E0C;
    }
    // 0x800F7EF4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800F7EF8: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x800F7EFC: bgez        $a3, L_800F7DD0
    if (SIGNED(ctx->r7) >= 0) {
        // 0x800F7F00: addiu       $t6, $t6, -0x3
        ctx->r14 = ADD32(ctx->r14, -0X3);
            goto L_800F7DD0;
    }
    // 0x800F7F00: addiu       $t6, $t6, -0x3
    ctx->r14 = ADD32(ctx->r14, -0X3);
    // 0x800F7F04: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x800F7F08: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800F7F0C: bne         $v1, $v0, L_800F7F3C
    if (ctx->r3 != ctx->r2) {
        // 0x800F7F10: nop
    
            goto L_800F7F3C;
    }
    // 0x800F7F10: nop

    // 0x800F7F14: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
    // 0x800F7F18: bnel        $v0, $v1, L_800F7F3C
    if (ctx->r2 != ctx->r3) {
        // 0x800F7F1C: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800F7F3C;
    }
    goto skip_1;
    // 0x800F7F1C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_1:
    // 0x800F7F20: lw          $v1, 0x70($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X70);
    // 0x800F7F24: bne         $v1, $v0, L_800F7F38
    if (ctx->r3 != ctx->r2) {
        // 0x800F7F28: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800F7F38;
    }
    // 0x800F7F28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800F7F2C: lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X80);
    // 0x800F7F30: beq         $v0, $v1, L_800F8068
    if (ctx->r2 == ctx->r3) {
        // 0x800F7F34: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800F8068;
    }
    // 0x800F7F34: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800F7F38:
    // 0x800F7F38: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
L_800F7F3C:
    // 0x800F7F3C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F7F40: lwc1        $f20, -0x7180($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7180);
    // 0x800F7F44: beq         $v1, $v0, L_800F7F6C
    if (ctx->r3 == ctx->r2) {
        // 0x800F7F48: nop
    
            goto L_800F7F6C;
    }
    // 0x800F7F48: nop

    // 0x800F7F4C: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800F7F50: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800F7F54: nop

    // 0x800F7F58: bc1f        L_800F7F6C
    if (!c1cs) {
        // 0x800F7F5C: nop
    
            goto L_800F7F6C;
    }
    // 0x800F7F5C: nop

    // 0x800F7F60: addu        $s2, $v1, $zero
    ctx->r18 = ADD32(ctx->r3, 0);
    // 0x800F7F64: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800F7F68: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
L_800F7F6C:
    // 0x800F7F6C: lw          $v1, 0x84($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X84);
    // 0x800F7F70: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800F7F74: beq         $v1, $v0, L_800F7FC0
    if (ctx->r3 == ctx->r2) {
        // 0x800F7F78: nop
    
            goto L_800F7FC0;
    }
    // 0x800F7F78: nop

    // 0x800F7F7C: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800F7F80: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800F7F84: nop

    // 0x800F7F88: bc1tl       L_800F7FB8
    if (c1cs) {
        // 0x800F7F8C: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_800F7FB8;
    }
    goto skip_2;
    // 0x800F7F8C: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    skip_2:
    // 0x800F7F90: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x800F7F94: nop

    // 0x800F7F98: bc1f        L_800F7FC0
    if (!c1cs) {
        // 0x800F7F9C: nop
    
            goto L_800F7FC0;
    }
    // 0x800F7F9C: nop

    // 0x800F7FA0: jal         0x80003430
    // 0x800F7FA4: nop

    rand_recomp(rdram, ctx);
        goto after_0;
    // 0x800F7FA4: nop

    after_0:
    // 0x800F7FA8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800F7FAC: beq         $v0, $zero, L_800F7FC0
    if (ctx->r2 == 0) {
        // 0x800F7FB0: nop
    
            goto L_800F7FC0;
    }
    // 0x800F7FB0: nop

    // 0x800F7FB4: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
L_800F7FB8:
    // 0x800F7FB8: lw          $s2, 0x84($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X84);
    // 0x800F7FBC: lwc1        $f20, 0x44($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X44);
L_800F7FC0:
    // 0x800F7FC0: lw          $v1, 0x70($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X70);
    // 0x800F7FC4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800F7FC8: beq         $v1, $v0, L_800F8014
    if (ctx->r3 == ctx->r2) {
        // 0x800F7FCC: nop
    
            goto L_800F8014;
    }
    // 0x800F7FCC: nop

    // 0x800F7FD0: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800F7FD4: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800F7FD8: nop

    // 0x800F7FDC: bc1tl       L_800F800C
    if (c1cs) {
        // 0x800F7FE0: addiu       $s3, $zero, 0x1
        ctx->r19 = ADD32(0, 0X1);
            goto L_800F800C;
    }
    goto skip_3;
    // 0x800F7FE0: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    skip_3:
    // 0x800F7FE4: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x800F7FE8: nop

    // 0x800F7FEC: bc1f        L_800F8014
    if (!c1cs) {
        // 0x800F7FF0: nop
    
            goto L_800F8014;
    }
    // 0x800F7FF0: nop

    // 0x800F7FF4: jal         0x80003430
    // 0x800F7FF8: nop

    rand_recomp(rdram, ctx);
        goto after_1;
    // 0x800F7FF8: nop

    after_1:
    // 0x800F7FFC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800F8000: beq         $v0, $zero, L_800F8014
    if (ctx->r2 == 0) {
        // 0x800F8004: nop
    
            goto L_800F8014;
    }
    // 0x800F8004: nop

    // 0x800F8008: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_800F800C:
    // 0x800F800C: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x800F8010: lwc1        $f20, 0x30($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X30);
L_800F8014:
    // 0x800F8014: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x800F8018: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800F801C: beq         $v1, $v0, L_800F8288
    if (ctx->r3 == ctx->r2) {
        // 0x800F8020: nop
    
            goto L_800F8288;
    }
    // 0x800F8020: nop

    // 0x800F8024: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800F8028: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800F802C: nop

    // 0x800F8030: bc1t        L_800F805C
    if (c1cs) {
        // 0x800F8034: nop
    
            goto L_800F805C;
    }
    // 0x800F8034: nop

    // 0x800F8038: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x800F803C: nop

    // 0x800F8040: bc1f        L_800F8288
    if (!c1cs) {
        // 0x800F8044: nop
    
            goto L_800F8288;
    }
    // 0x800F8044: nop

    // 0x800F8048: jal         0x80003430
    // 0x800F804C: nop

    rand_recomp(rdram, ctx);
        goto after_2;
    // 0x800F804C: nop

    after_2:
    // 0x800F8050: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800F8054: beq         $v0, $zero, L_800F8288
    if (ctx->r2 == 0) {
        // 0x800F8058: nop
    
            goto L_800F8288;
    }
    // 0x800F8058: nop

L_800F805C:
    // 0x800F805C: lw          $s2, 0x80($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X80);
    // 0x800F8060: j           L_800F8288
    // 0x800F8064: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_800F8288;
    // 0x800F8064: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_800F8068:
    // 0x800F8068: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F806C: lwc1        $f20, -0x717C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X717C);
    // 0x800F8070: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800F8074: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800F8078: nop

    // 0x800F807C: bc1f        L_800F8090
    if (!c1cs) {
        // 0x800F8080: nop
    
            goto L_800F8090;
    }
    // 0x800F8080: nop

    // 0x800F8084: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x800F8088: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800F808C: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
L_800F8090:
    // 0x800F8090: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F8094: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800F8098: nop

    // 0x800F809C: bc1tl       L_800F80CC
    if (c1cs) {
        // 0x800F80A0: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_800F80CC;
    }
    goto skip_4;
    // 0x800F80A0: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    skip_4:
    // 0x800F80A4: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x800F80A8: nop

    // 0x800F80AC: bc1f        L_800F80D4
    if (!c1cs) {
        // 0x800F80B0: nop
    
            goto L_800F80D4;
    }
    // 0x800F80B0: nop

    // 0x800F80B4: jal         0x80003430
    // 0x800F80B8: nop

    rand_recomp(rdram, ctx);
        goto after_3;
    // 0x800F80B8: nop

    after_3:
    // 0x800F80BC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800F80C0: beq         $v0, $zero, L_800F80D4
    if (ctx->r2 == 0) {
        // 0x800F80C4: nop
    
            goto L_800F80D4;
    }
    // 0x800F80C4: nop

    // 0x800F80C8: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
L_800F80CC:
    // 0x800F80CC: lw          $s2, 0x64($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X64);
    // 0x800F80D0: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
L_800F80D4:
    // 0x800F80D4: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F80D8: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800F80DC: nop

    // 0x800F80E0: bc1tl       L_800F8110
    if (c1cs) {
        // 0x800F80E4: addiu       $s3, $zero, 0x1
        ctx->r19 = ADD32(0, 0X1);
            goto L_800F8110;
    }
    goto skip_5;
    // 0x800F80E4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    skip_5:
    // 0x800F80E8: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x800F80EC: nop

    // 0x800F80F0: bc1f        L_800F8118
    if (!c1cs) {
        // 0x800F80F4: nop
    
            goto L_800F8118;
    }
    // 0x800F80F4: nop

    // 0x800F80F8: jal         0x80003430
    // 0x800F80FC: nop

    rand_recomp(rdram, ctx);
        goto after_4;
    // 0x800F80FC: nop

    after_4:
    // 0x800F8100: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800F8104: beq         $v0, $zero, L_800F8118
    if (ctx->r2 == 0) {
        // 0x800F8108: nop
    
            goto L_800F8118;
    }
    // 0x800F8108: nop

    // 0x800F810C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_800F8110:
    // 0x800F8110: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800F8114: lwc1        $f20, 0x10($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X10);
L_800F8118:
    // 0x800F8118: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F811C: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800F8120: nop

    // 0x800F8124: bc1tl       L_800F8154
    if (c1cs) {
        // 0x800F8128: addiu       $s3, $zero, 0x1
        ctx->r19 = ADD32(0, 0X1);
            goto L_800F8154;
    }
    goto skip_6;
    // 0x800F8128: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    skip_6:
    // 0x800F812C: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x800F8130: nop

    // 0x800F8134: bc1f        L_800F815C
    if (!c1cs) {
        // 0x800F8138: nop
    
            goto L_800F815C;
    }
    // 0x800F8138: nop

    // 0x800F813C: jal         0x80003430
    // 0x800F8140: nop

    rand_recomp(rdram, ctx);
        goto after_5;
    // 0x800F8140: nop

    after_5:
    // 0x800F8144: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800F8148: beq         $v0, $zero, L_800F815C
    if (ctx->r2 == 0) {
        // 0x800F814C: nop
    
            goto L_800F815C;
    }
    // 0x800F814C: nop

    // 0x800F8150: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_800F8154:
    // 0x800F8154: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x800F8158: lwc1        $f20, 0x20($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X20);
L_800F815C:
    // 0x800F815C: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800F8160: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800F8164: nop

    // 0x800F8168: bc1f        L_800F8288
    if (!c1cs) {
        // 0x800F816C: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800F8288;
    }
    // 0x800F816C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800F8170: lw          $v1, 0x78($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X78);
    // 0x800F8174: beq         $v1, $v0, L_800F819C
    if (ctx->r3 == ctx->r2) {
        // 0x800F8178: nop
    
            goto L_800F819C;
    }
    // 0x800F8178: nop

    // 0x800F817C: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800F8180: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800F8184: nop

    // 0x800F8188: bc1f        L_800F819C
    if (!c1cs) {
        // 0x800F818C: nop
    
            goto L_800F819C;
    }
    // 0x800F818C: nop

    // 0x800F8190: addu        $s2, $v1, $zero
    ctx->r18 = ADD32(ctx->r3, 0);
    // 0x800F8194: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800F8198: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
L_800F819C:
    // 0x800F819C: lw          $v1, 0x88($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X88);
    // 0x800F81A0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800F81A4: beq         $v1, $v0, L_800F81F0
    if (ctx->r3 == ctx->r2) {
        // 0x800F81A8: nop
    
            goto L_800F81F0;
    }
    // 0x800F81A8: nop

    // 0x800F81AC: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800F81B0: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800F81B4: nop

    // 0x800F81B8: bc1tl       L_800F81E8
    if (c1cs) {
        // 0x800F81BC: addiu       $s3, $zero, -0x1
        ctx->r19 = ADD32(0, -0X1);
            goto L_800F81E8;
    }
    goto skip_7;
    // 0x800F81BC: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    skip_7:
    // 0x800F81C0: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x800F81C4: nop

    // 0x800F81C8: bc1f        L_800F81F0
    if (!c1cs) {
        // 0x800F81CC: nop
    
            goto L_800F81F0;
    }
    // 0x800F81CC: nop

    // 0x800F81D0: jal         0x80003430
    // 0x800F81D4: nop

    rand_recomp(rdram, ctx);
        goto after_6;
    // 0x800F81D4: nop

    after_6:
    // 0x800F81D8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800F81DC: beq         $v0, $zero, L_800F81F0
    if (ctx->r2 == 0) {
        // 0x800F81E0: nop
    
            goto L_800F81F0;
    }
    // 0x800F81E0: nop

    // 0x800F81E4: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_800F81E8:
    // 0x800F81E8: lw          $s2, 0x88($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X88);
    // 0x800F81EC: lwc1        $f20, 0x48($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X48);
L_800F81F0:
    // 0x800F81F0: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800F81F4: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800F81F8: nop

    // 0x800F81FC: bc1f        L_800F8288
    if (!c1cs) {
        // 0x800F8200: nop
    
            goto L_800F8288;
    }
    // 0x800F8200: nop

    // 0x800F8204: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F8208: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800F820C: nop

    // 0x800F8210: bc1tl       L_800F8240
    if (c1cs) {
        // 0x800F8214: addiu       $s3, $zero, -0x1
        ctx->r19 = ADD32(0, -0X1);
            goto L_800F8240;
    }
    goto skip_8;
    // 0x800F8214: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    skip_8:
    // 0x800F8218: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x800F821C: nop

    // 0x800F8220: bc1f        L_800F8248
    if (!c1cs) {
        // 0x800F8224: nop
    
            goto L_800F8248;
    }
    // 0x800F8224: nop

    // 0x800F8228: jal         0x80003430
    // 0x800F822C: nop

    rand_recomp(rdram, ctx);
        goto after_7;
    // 0x800F822C: nop

    after_7:
    // 0x800F8230: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800F8234: beq         $v0, $zero, L_800F8248
    if (ctx->r2 == 0) {
        // 0x800F8238: nop
    
            goto L_800F8248;
    }
    // 0x800F8238: nop

    // 0x800F823C: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_800F8240:
    // 0x800F8240: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x800F8244: lwc1        $f20, 0x18($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X18);
L_800F8248:
    // 0x800F8248: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F824C: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800F8250: nop

    // 0x800F8254: bc1t        L_800F8280
    if (c1cs) {
        // 0x800F8258: nop
    
            goto L_800F8280;
    }
    // 0x800F8258: nop

    // 0x800F825C: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x800F8260: nop

    // 0x800F8264: bc1f        L_800F8288
    if (!c1cs) {
        // 0x800F8268: nop
    
            goto L_800F8288;
    }
    // 0x800F8268: nop

    // 0x800F826C: jal         0x80003430
    // 0x800F8270: nop

    rand_recomp(rdram, ctx);
        goto after_8;
    // 0x800F8270: nop

    after_8:
    // 0x800F8274: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800F8278: beq         $v0, $zero, L_800F8288
    if (ctx->r2 == 0) {
        // 0x800F827C: nop
    
            goto L_800F8288;
    }
    // 0x800F827C: nop

L_800F8280:
    // 0x800F8280: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x800F8284: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_800F8288:
    // 0x800F8288: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800F828C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F8290: lwc1        $f0, -0x7178($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7178);
    // 0x800F8294: addiu       $v0, $s2, -0x3
    ctx->r2 = ADD32(ctx->r18, -0X3);
    // 0x800F8298: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F829C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F82A0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F82A4: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F82A8: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800F82AC: mtc1        $s3, $f0
    ctx->f0.u32l = ctx->r19;
    // 0x800F82B0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F82B4: mul.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F82B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F82BC: c.eq.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl == ctx->f0.fl;
    // 0x800F82C0: nop

    // 0x800F82C4: bc1f        L_800F82F4
    if (!c1cs) {
        // 0x800F82C8: nop
    
            goto L_800F82F4;
    }
    // 0x800F82C8: nop

    // 0x800F82CC: c.eq.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl == ctx->f0.fl;
    // 0x800F82D0: nop

    // 0x800F82D4: bc1t        L_800F8350
    if (c1cs) {
        // 0x800F82D8: addiu       $a1, $zero, 0x8
        ctx->r5 = ADD32(0, 0X8);
            goto L_800F8350;
    }
    // 0x800F82D8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800F82DC: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800F82E0: nop

    // 0x800F82E4: bc1f        L_800F8350
    if (!c1cs) {
        // 0x800F82E8: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_800F8350;
    }
    // 0x800F82E8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800F82EC: j           L_800F8350
    // 0x800F82F0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
        goto L_800F8350;
    // 0x800F82F0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
L_800F82F4:
    // 0x800F82F4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800F82F8: nop

    // 0x800F82FC: bc1f        L_800F832C
    if (!c1cs) {
        // 0x800F8300: nop
    
            goto L_800F832C;
    }
    // 0x800F8300: nop

    // 0x800F8304: c.eq.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl == ctx->f0.fl;
    // 0x800F8308: nop

    // 0x800F830C: bc1t        L_800F8350
    if (c1cs) {
        // 0x800F8310: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800F8350;
    }
    // 0x800F8310: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800F8314: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800F8318: nop

    // 0x800F831C: bc1f        L_800F8350
    if (!c1cs) {
        // 0x800F8320: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_800F8350;
    }
    // 0x800F8320: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800F8324: j           L_800F8350
    // 0x800F8328: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
        goto L_800F8350;
    // 0x800F8328: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
L_800F832C:
    // 0x800F832C: c.eq.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl == ctx->f0.fl;
    // 0x800F8330: nop

    // 0x800F8334: bc1t        L_800F8350
    if (c1cs) {
        // 0x800F8338: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_800F8350;
    }
    // 0x800F8338: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800F833C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800F8340: nop

    // 0x800F8344: bc1f        L_800F8350
    if (!c1cs) {
        // 0x800F8348: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_800F8350;
    }
    // 0x800F8348: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800F834C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_800F8350:
    // 0x800F8350: lw          $s5, 0xD0($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XD0);
    // 0x800F8354: swc1        $f8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f8.u32l;
    // 0x800F8358: lw          $s5, 0xD4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XD4);
    // 0x800F835C: swc1        $f6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f6.u32l;
    // 0x800F8360: lw          $ra, 0xBC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XBC);
    // 0x800F8364: lw          $fp, 0xB8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XB8);
    // 0x800F8368: lw          $s7, 0xB4($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XB4);
    // 0x800F836C: lw          $s6, 0xB0($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XB0);
    // 0x800F8370: lw          $s5, 0xAC($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XAC);
    // 0x800F8374: lw          $s4, 0xA8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XA8);
    // 0x800F8378: lw          $s3, 0xA4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XA4);
    // 0x800F837C: lw          $s2, 0xA0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA0);
    // 0x800F8380: lw          $s1, 0x9C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X9C);
    // 0x800F8384: lw          $s0, 0x98($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X98);
    // 0x800F8388: ldc1        $f20, 0xC0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XC0);
    // 0x800F838C: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x800F8390: jr          $ra
    // 0x800F8394: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x800F8394: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void executeActorType4Effect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8398: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x800F839C: sw          $s7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r23;
    // 0x800F83A0: addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // 0x800F83A4: sw          $s4, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r20;
    // 0x800F83A8: addiu       $s4, $s7, 0x8
    ctx->r20 = ADD32(ctx->r23, 0X8);
    // 0x800F83AC: sw          $s6, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r22;
    // 0x800F83B0: sw          $ra, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r31;
    // 0x800F83B4: sw          $fp, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r30;
    // 0x800F83B8: sw          $s5, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r21;
    // 0x800F83BC: sw          $s3, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r19;
    // 0x800F83C0: sw          $s2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r18;
    // 0x800F83C4: sw          $s1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r17;
    // 0x800F83C8: sw          $s0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r16;
    // 0x800F83CC: sdc1        $f30, 0x110($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X110, ctx->r29);
    // 0x800F83D0: sdc1        $f28, 0x108($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X108, ctx->r29);
    // 0x800F83D4: sdc1        $f26, 0x100($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X100, ctx->r29);
    // 0x800F83D8: sdc1        $f24, 0xF8($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0XF8, ctx->r29);
    // 0x800F83DC: sdc1        $f22, 0xF0($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XF0, ctx->r29);
    // 0x800F83E0: sdc1        $f20, 0xE8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XE8, ctx->r29);
    // 0x800F83E4: lhu         $a0, 0x198($s7)
    ctx->r4 = MEM_HU(ctx->r23, 0X198);
    // 0x800F83E8: mtc1        $a1, $f26
    ctx->f26.u32l = ctx->r5;
    // 0x800F83EC: jal         0x8004015C
    // 0x800F83F0: addiu       $s6, $s7, 0x50
    ctx->r22 = ADD32(ctx->r23, 0X50);
    getNpcContextField8(rdram, ctx);
        goto after_0;
    // 0x800F83F0: addiu       $s6, $s7, 0x50
    ctx->r22 = ADD32(ctx->r23, 0X50);
    after_0:
    // 0x800F83F4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800F83F8: jal         0x8006C994
    // 0x800F83FC: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    getPlayerField2(rdram, ctx);
        goto after_1;
    // 0x800F83FC: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    after_1:
    // 0x800F8400: jal         0x8004013C
    // 0x800F8404: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    getNpcContextByIndex(rdram, ctx);
        goto after_2;
    // 0x800F8404: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    after_2:
    // 0x800F8408: lhu         $v0, 0x14($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X14);
    // 0x800F840C: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800F8410: bne         $v0, $zero, L_800F8450
    if (ctx->r2 != 0) {
        // 0x800F8414: addiu       $fp, $s7, 0xA0
        ctx->r30 = ADD32(ctx->r23, 0XA0);
            goto L_800F8450;
    }
    // 0x800F8414: addiu       $fp, $s7, 0xA0
    ctx->r30 = ADD32(ctx->r23, 0XA0);
    // 0x800F8418: jal         0x8006C8F0
    // 0x800F841C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    getCraftRecordByIdx(rdram, ctx);
        goto after_3;
    // 0x800F841C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_3:
    // 0x800F8420: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800F8424: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x800F8428: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x800F842C: sw          $t0, 0x8($s7)
    MEM_W(0X8, ctx->r23) = ctx->r8;
    // 0x800F8430: sw          $t1, 0xC($s7)
    MEM_W(0XC, ctx->r23) = ctx->r9;
    // 0x800F8434: sw          $t2, 0x10($s7)
    MEM_W(0X10, ctx->r23) = ctx->r10;
    // 0x800F8438: jal         0x8006C918
    // 0x800F843C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8006C918(rdram, ctx);
        goto after_4;
    // 0x800F843C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_4:
    // 0x800F8440: addu        $fp, $v0, $zero
    ctx->r30 = ADD32(ctx->r2, 0);
    // 0x800F8444: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800F8448: j           L_800F846C
    // 0x800F844C: sb          $t0, 0xB8($sp)
    MEM_B(0XB8, ctx->r29) = ctx->r8;
        goto L_800F846C;
    // 0x800F844C: sb          $t0, 0xB8($sp)
    MEM_B(0XB8, ctx->r29) = ctx->r8;
L_800F8450:
    // 0x800F8450: lw          $t1, 0xA0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0XA0);
    // 0x800F8454: lw          $t2, 0xA4($s7)
    ctx->r10 = MEM_W(ctx->r23, 0XA4);
    // 0x800F8458: lw          $t3, 0xA8($s7)
    ctx->r11 = MEM_W(ctx->r23, 0XA8);
    // 0x800F845C: sw          $t1, 0x8($s7)
    MEM_W(0X8, ctx->r23) = ctx->r9;
    // 0x800F8460: sw          $t2, 0xC($s7)
    MEM_W(0XC, ctx->r23) = ctx->r10;
    // 0x800F8464: sw          $t3, 0x10($s7)
    MEM_W(0X10, ctx->r23) = ctx->r11;
    // 0x800F8468: sb          $zero, 0xB8($sp)
    MEM_B(0XB8, ctx->r29) = 0;
L_800F846C:
    // 0x800F846C: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x800F8470: jal         0x800F7130
    // 0x800F8474: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    func_800F7130(rdram, ctx);
        goto after_5;
    // 0x800F8474: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    after_5:
    // 0x800F8478: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x800F847C: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    // 0x800F8480: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x800F8484: jal         0x800F7C74
    // 0x800F8488: addiu       $a3, $sp, 0xB4
    ctx->r7 = ADD32(ctx->r29, 0XB4);
    func_800F7C74(rdram, ctx);
        goto after_6;
    // 0x800F8488: addiu       $a3, $sp, 0xB4
    ctx->r7 = ADD32(ctx->r29, 0XB4);
    after_6:
    // 0x800F848C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800F8490: sltiu       $v0, $v1, 0x8
    ctx->r2 = ctx->r3 < 0X8 ? 1 : 0;
    // 0x800F8494: lwc1        $f2, 0x34($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X34);
    // 0x800F8498: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F849C: lwc1        $f6, -0x7174($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7174);
    // 0x800F84A0: lwc1        $f0, 0x1C($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X1C);
    // 0x800F84A4: mul.s       $f20, $f2, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800F84A8: beq         $v0, $zero, L_800F8754
    if (ctx->r2 == 0) {
        // 0x800F84AC: swc1        $f0, 0x24($s4)
        MEM_W(0X24, ctx->r20) = ctx->f0.u32l;
            goto L_800F8754;
    }
    // 0x800F84AC: swc1        $f0, 0x24($s4)
    MEM_W(0X24, ctx->r20) = ctx->f0.u32l;
    // 0x800F84B0: lbu         $v0, 0x96($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X96);
    // 0x800F84B4: bne         $v0, $zero, L_800F864C
    if (ctx->r2 != 0) {
        // 0x800F84B8: nop
    
            goto L_800F864C;
    }
    // 0x800F84B8: nop

L_800F84BC:
    // 0x800F84BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F84C0:
    // 0x800F84C0: sb          $v0, 0x96($s4)
    MEM_B(0X96, ctx->r20) = ctx->r2;
L_800F84C4:
    // 0x800F84C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F84C8: sb          $v1, 0x95($s4)
    MEM_B(0X95, ctx->r20) = ctx->r3;
    // 0x800F84CC: sb          $v1, 0x94($s4)
    MEM_B(0X94, ctx->r20) = ctx->r3;
    // 0x800F84D0: sh          $v0, 0x90($s4)
    MEM_H(0X90, ctx->r20) = ctx->r2;
    // 0x800F84D4: sh          $zero, 0x92($s4)
    MEM_H(0X92, ctx->r20) = 0;
    // 0x800F84D8: lbu         $v0, 0x1A($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X1A);
    // 0x800F84DC: lwc1        $f0, 0x8($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X8);
    // 0x800F84E0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F84E4: lwc1        $f4, -0x7170($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7170);
    // 0x800F84E8: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800F84EC: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800F84F0: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800F84F4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F84F8: swc1        $f2, 0x88($s4)
    MEM_W(0X88, ctx->r20) = ctx->f2.u32l;
    // 0x800F84FC: lwc1        $f0, 0xC($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0XC);
    // 0x800F8500: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800F8504: nop

    // 0x800F8508: bc1f        L_800F8524
    if (!c1cs) {
        // 0x800F850C: addiu       $s0, $sp, 0x40
        ctx->r16 = ADD32(ctx->r29, 0X40);
            goto L_800F8524;
    }
    // 0x800F850C: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x800F8510: lwc1        $f0, 0x20($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X20);
    // 0x800F8514: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F8518: lwc1        $f2, -0x716C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X716C);
    // 0x800F851C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F8520: swc1        $f0, 0x2C($s4)
    MEM_W(0X2C, ctx->r20) = ctx->f0.u32l;
L_800F8524:
    // 0x800F8524: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F8528: addiu       $s2, $s5, 0x18
    ctx->r18 = ADD32(ctx->r21, 0X18);
    // 0x800F852C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800F8530: addiu       $s3, $s5, 0xC
    ctx->r19 = ADD32(ctx->r21, 0XC);
    // 0x800F8534: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F8538: lwc1        $f0, -0x7168($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7168);
    // 0x800F853C: lwc1        $f2, 0xB0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F8540: lwc1        $f4, 0xB4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800F8544: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x800F8548: sw          $zero, 0x7C($s4)
    MEM_W(0X7C, ctx->r20) = 0;
    // 0x800F854C: swc1        $f0, 0x8C($s4)
    MEM_W(0X8C, ctx->r20) = ctx->f0.u32l;
    // 0x800F8550: swc1        $f2, 0x80($s4)
    MEM_W(0X80, ctx->r20) = ctx->f2.u32l;
    // 0x800F8554: jal         0x80019548
    // 0x800F8558: swc1        $f4, 0x84($s4)
    MEM_W(0X84, ctx->r20) = ctx->f4.u32l;
    vec3Cross(rdram, ctx);
        goto after_7;
    // 0x800F8558: swc1        $f4, 0x84($s4)
    MEM_W(0X84, ctx->r20) = ctx->f4.u32l;
    after_7:
    // 0x800F855C: addiu       $s1, $sp, 0x70
    ctx->r17 = ADD32(ctx->r29, 0X70);
    // 0x800F8560: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F8564: lw          $a2, 0xB0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB0);
    // 0x800F8568: jal         0x8001D240
    // 0x800F856C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    quatFromAxisAngle(rdram, ctx);
        goto after_8;
    // 0x800F856C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_8:
    // 0x800F8570: addiu       $s0, $sp, 0x60
    ctx->r16 = ADD32(ctx->r29, 0X60);
    // 0x800F8574: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F8578: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x800F857C: jal         0x8001D240
    // 0x800F8580: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    quatFromAxisAngle(rdram, ctx);
        goto after_9;
    // 0x800F8580: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_9:
    // 0x800F8584: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F8588: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800F858C: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
    // 0x800F8590: jal         0x8001D2C0
    // 0x800F8594: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    quatMultiply(rdram, ctx);
        goto after_10;
    // 0x800F8594: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_10:
    // 0x800F8598: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F859C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800F85A0: jal         0x8001D3C4
    // 0x800F85A4: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    rotateVec3ByQuat(rdram, ctx);
        goto after_11;
    // 0x800F85A4: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_11:
    // 0x800F85A8: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800F85AC: lwc1        $f0, 0x20($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X20);
    // 0x800F85B0: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F85B4: nop

    // 0x800F85B8: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800F85BC: lwc1        $f0, 0x34($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X34);
    // 0x800F85C0: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F85C4: lwc1        $f0, 0x0($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800F85C8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F85CC: swc1        $f0, 0x70($s4)
    MEM_W(0X70, ctx->r20) = ctx->f0.u32l;
    // 0x800F85D0: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800F85D4: lwc1        $f0, 0x20($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X20);
    // 0x800F85D8: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F85DC: nop

    // 0x800F85E0: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800F85E4: lwc1        $f0, 0x34($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X34);
    // 0x800F85E8: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F85EC: lwc1        $f0, 0x4($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X4);
    // 0x800F85F0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F85F4: swc1        $f0, 0x74($s4)
    MEM_W(0X74, ctx->r20) = ctx->f0.u32l;
    // 0x800F85F8: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800F85FC: lwc1        $f0, 0x20($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X20);
    // 0x800F8600: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F8604: nop

    // 0x800F8608: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800F860C: lwc1        $f0, 0x34($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X34);
    // 0x800F8610: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F8614: lwc1        $f0, 0x8($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X8);
    // 0x800F8618: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F861C: swc1        $f0, 0x78($s4)
    MEM_W(0X78, ctx->r20) = ctx->f0.u32l;
    // 0x800F8620: lw          $t1, 0x70($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X70);
    // 0x800F8624: lw          $t2, 0x74($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X74);
    // 0x800F8628: lw          $t3, 0x78($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X78);
    // 0x800F862C: sw          $t1, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r9;
    // 0x800F8630: sw          $t2, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->r10;
    // 0x800F8634: sw          $t3, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->r11;
    // 0x800F8638: lwc1        $f0, 0x8($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X8);
    // 0x800F863C: lwc1        $f2, 0x20($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X20);
    // 0x800F8640: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F8644: j           L_800F8838
    // 0x800F8648: swc1        $f0, 0xFC($s4)
    MEM_W(0XFC, ctx->r20) = ctx->f0.u32l;
        goto L_800F8838;
    // 0x800F8648: swc1        $f0, 0xFC($s4)
    MEM_W(0XFC, ctx->r20) = ctx->f0.u32l;
L_800F864C:
    // 0x800F864C: lwc1        $f0, 0x7C($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X7C);
    // 0x800F8650: add.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f26.fl;
    // 0x800F8654: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F8658: lwc1        $f2, -0x7164($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7164);
    // 0x800F865C: swc1        $f0, 0x7C($s4)
    MEM_W(0X7C, ctx->r20) = ctx->f0.u32l;
    // 0x800F8660: lbu         $v0, 0x1A($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X1A);
    // 0x800F8664: lwc1        $f0, 0x8($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X8);
    // 0x800F8668: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800F866C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F8670: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F8674: lb          $v0, 0x94($s4)
    ctx->r2 = MEM_B(ctx->r20, 0X94);
    // 0x800F8678: mul.s       $f22, $f4, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800F867C: bne         $v1, $v0, L_800F86FC
    if (ctx->r3 != ctx->r2) {
        // 0x800F8680: nop
    
            goto L_800F86FC;
    }
    // 0x800F8680: nop

    // 0x800F8684: lwc1        $f0, 0x8C($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8C);
    // 0x800F8688: lhu         $v0, 0x90($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X90);
    // 0x800F868C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800F8690: sub.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f26.fl;
    // 0x800F8694: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800F8698: sh          $v0, 0x90($s4)
    MEM_H(0X90, ctx->r20) = ctx->r2;
    // 0x800F869C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800F86A0: nop

    // 0x800F86A4: bc1f        L_800F86EC
    if (!c1cs) {
        // 0x800F86A8: swc1        $f0, 0x8C($s4)
        MEM_W(0X8C, ctx->r20) = ctx->f0.u32l;
            goto L_800F86EC;
    }
    // 0x800F86A8: swc1        $f0, 0x8C($s4)
    MEM_W(0X8C, ctx->r20) = ctx->f0.u32l;
    // 0x800F86AC: lwc1        $f0, 0x88($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X88);
    // 0x800F86B0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F86B4: lwc1        $f2, -0x7160($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7160);
    // 0x800F86B8: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x800F86BC: nop

    // 0x800F86C0: bc1f        L_800F86D8
    if (!c1cs) {
        // 0x800F86C4: swc1        $f2, 0x8C($s4)
        MEM_W(0X8C, ctx->r20) = ctx->f2.u32l;
            goto L_800F86D8;
    }
    // 0x800F86C4: swc1        $f2, 0x8C($s4)
    MEM_W(0X8C, ctx->r20) = ctx->f2.u32l;
    // 0x800F86C8: lwc1        $f0, 0x34($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X34);
    // 0x800F86CC: mul.s       $f20, $f0, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800F86D0: j           L_800F84C0
    // 0x800F86D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800F84C0;
    // 0x800F86D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F86D8:
    // 0x800F86D8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F86DC: lwc1        $f0, -0x715C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X715C);
    // 0x800F86E0: lwc1        $f20, 0x34($s4)
    ctx->f20.u32l = MEM_W(ctx->r20, 0X34);
    // 0x800F86E4: j           L_800F84BC
    // 0x800F86E8: swc1        $f0, 0x24($s4)
    MEM_W(0X24, ctx->r20) = ctx->f0.u32l;
        goto L_800F84BC;
    // 0x800F86E8: swc1        $f0, 0x24($s4)
    MEM_W(0X24, ctx->r20) = ctx->f0.u32l;
L_800F86EC:
    // 0x800F86EC: lbu         $v0, 0x94($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X94);
    // 0x800F86F0: sh          $zero, 0x92($s4)
    MEM_H(0X92, ctx->r20) = 0;
    // 0x800F86F4: j           L_800F8838
    // 0x800F86F8: sb          $v0, 0x95($s4)
    MEM_B(0X95, ctx->r20) = ctx->r2;
        goto L_800F8838;
    // 0x800F86F8: sb          $v0, 0x95($s4)
    MEM_B(0X95, ctx->r20) = ctx->r2;
L_800F86FC:
    // 0x800F86FC: lb          $v0, 0x95($s4)
    ctx->r2 = MEM_B(ctx->r20, 0X95);
    // 0x800F8700: bne         $v1, $v0, L_800F8748
    if (ctx->r3 != ctx->r2) {
        // 0x800F8704: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F8748;
    }
    // 0x800F8704: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F8708: lhu         $v0, 0x92($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X92);
    // 0x800F870C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800F8710: sh          $v0, 0x92($s4)
    MEM_H(0X92, ctx->r20) = ctx->r2;
    // 0x800F8714: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800F8718: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800F871C: slti        $v0, $v0, 0x14
    ctx->r2 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x800F8720: beq         $v0, $zero, L_800F84C0
    if (ctx->r2 == 0) {
        // 0x800F8724: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F84C0;
    }
    // 0x800F8724: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F8728: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F872C: lwc1        $f0, -0x7158($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7158);
    // 0x800F8730: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x800F8734: nop

    // 0x800F8738: bc1tl       L_800F84C4
    if (c1cs) {
        // 0x800F873C: sb          $v0, 0x96($s4)
        MEM_B(0X96, ctx->r20) = ctx->r2;
            goto L_800F84C4;
    }
    goto skip_0;
    // 0x800F873C: sb          $v0, 0x96($s4)
    MEM_B(0X96, ctx->r20) = ctx->r2;
    skip_0:
    // 0x800F8740: j           L_800F883C
    // 0x800F8744: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
        goto L_800F883C;
    // 0x800F8744: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
L_800F8748:
    // 0x800F8748: sb          $v1, 0x95($s4)
    MEM_B(0X95, ctx->r20) = ctx->r3;
    // 0x800F874C: j           L_800F8838
    // 0x800F8750: sh          $v0, 0x92($s4)
    MEM_H(0X92, ctx->r20) = ctx->r2;
        goto L_800F8838;
    // 0x800F8750: sh          $v0, 0x92($s4)
    MEM_H(0X92, ctx->r20) = ctx->r2;
L_800F8754:
    // 0x800F8754: lbu         $v0, 0x96($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X96);
    // 0x800F8758: beq         $v0, $zero, L_800F881C
    if (ctx->r2 == 0) {
        // 0x800F875C: nop
    
            goto L_800F881C;
    }
    // 0x800F875C: nop

    // 0x800F8760: lwc1        $f0, 0xFC($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XFC);
    // 0x800F8764: sub.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f26.fl;
    // 0x800F8768: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800F876C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800F8770: nop

    // 0x800F8774: bc1f        L_800F8814
    if (!c1cs) {
        // 0x800F8778: swc1        $f0, 0xFC($s4)
        MEM_W(0XFC, ctx->r20) = ctx->f0.u32l;
            goto L_800F8814;
    }
    // 0x800F8778: swc1        $f0, 0xFC($s4)
    MEM_W(0XFC, ctx->r20) = ctx->f0.u32l;
    // 0x800F877C: lwc1        $f2, 0xC($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0XC);
    // 0x800F8780: lwc1        $f0, 0x20($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X20);
    // 0x800F8784: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F8788: nop

    // 0x800F878C: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800F8790: lwc1        $f0, 0x34($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X34);
    // 0x800F8794: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F8798: lwc1        $f0, 0x0($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800F879C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F87A0: swc1        $f0, 0x70($s4)
    MEM_W(0X70, ctx->r20) = ctx->f0.u32l;
    // 0x800F87A4: lwc1        $f2, 0x10($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X10);
    // 0x800F87A8: lwc1        $f0, 0x20($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X20);
    // 0x800F87AC: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F87B0: nop

    // 0x800F87B4: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800F87B8: lwc1        $f0, 0x34($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X34);
    // 0x800F87BC: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F87C0: lwc1        $f0, 0x4($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X4);
    // 0x800F87C4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F87C8: swc1        $f0, 0x74($s4)
    MEM_W(0X74, ctx->r20) = ctx->f0.u32l;
    // 0x800F87CC: lwc1        $f2, 0x14($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X14);
    // 0x800F87D0: lwc1        $f0, 0x20($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X20);
    // 0x800F87D4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F87D8: nop

    // 0x800F87DC: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800F87E0: lwc1        $f0, 0x34($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X34);
    // 0x800F87E4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F87E8: lwc1        $f0, 0x8($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X8);
    // 0x800F87EC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F87F0: swc1        $f0, 0x78($s4)
    MEM_W(0X78, ctx->r20) = ctx->f0.u32l;
    // 0x800F87F4: lw          $t1, 0x70($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X70);
    // 0x800F87F8: lw          $t2, 0x74($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X74);
    // 0x800F87FC: lw          $t3, 0x78($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X78);
    // 0x800F8800: sw          $t1, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r9;
    // 0x800F8804: sw          $t2, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->r10;
    // 0x800F8808: sw          $t3, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->r11;
    // 0x800F880C: j           L_800F8838
    // 0x800F8810: sw          $zero, 0x2C($s4)
    MEM_W(0X2C, ctx->r20) = 0;
        goto L_800F8838;
    // 0x800F8810: sw          $zero, 0x2C($s4)
    MEM_W(0X2C, ctx->r20) = 0;
L_800F8814:
    // 0x800F8814: j           L_800F8834
    // 0x800F8818: sb          $zero, 0x96($s4)
    MEM_B(0X96, ctx->r20) = 0;
        goto L_800F8834;
    // 0x800F8818: sb          $zero, 0x96($s4)
    MEM_B(0X96, ctx->r20) = 0;
L_800F881C:
    // 0x800F881C: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x800F8820: lw          $t2, 0x4($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X4);
    // 0x800F8824: lw          $t3, 0x8($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X8);
    // 0x800F8828: sw          $t1, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r9;
    // 0x800F882C: sw          $t2, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->r10;
    // 0x800F8830: sw          $t3, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->r11;
L_800F8834:
    // 0x800F8834: sw          $zero, 0x2C($s4)
    MEM_W(0X2C, ctx->r20) = 0;
L_800F8838:
    // 0x800F8838: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
L_800F883C:
    // 0x800F883C: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x800F8840: lwc1        $f12, 0x0($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800F8844: lwc1        $f14, 0x8($s5)
    ctx->f14.u32l = MEM_W(ctx->r21, 0X8);
    // 0x800F8848: jal         0x80067D90
    // 0x800F884C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    wrapAngleToCyclicRange(rdram, ctx);
        goto after_12;
    // 0x800F884C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_12:
    // 0x800F8850: lwc1        $f2, 0x4($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X4);
    // 0x800F8854: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F8858: lwc1        $f24, -0x7154($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X7154);
    // 0x800F885C: add.s       $f2, $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f24.fl;
    // 0x800F8860: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    // 0x800F8864: c.le.s      $f30, $f2
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f30.fl <= ctx->f2.fl;
    // 0x800F8868: nop

    // 0x800F886C: bc1f        L_800F88A0
    if (!c1cs) {
        // 0x800F8870: nop
    
            goto L_800F88A0;
    }
    // 0x800F8870: nop

    // 0x800F8874: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F8878: lwc1        $f0, -0x7150($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7150);
    // 0x800F887C: lwc1        $f2, 0x0($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800F8880: sub.s       $f0, $f30, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f30.fl - ctx->f0.fl;
    // 0x800F8884: swc1        $f2, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->f2.u32l;
    // 0x800F8888: swc1        $f0, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->f0.u32l;
    // 0x800F888C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F8890: lwc1        $f0, -0x714C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X714C);
    // 0x800F8894: lwc1        $f2, 0x8($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X8);
    // 0x800F8898: swc1        $f0, 0x24($s4)
    MEM_W(0X24, ctx->r20) = ctx->f0.u32l;
    // 0x800F889C: swc1        $f2, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->f2.u32l;
L_800F88A0:
    // 0x800F88A0: lh          $v1, 0xEC($s4)
    ctx->r3 = MEM_H(ctx->r20, 0XEC);
    // 0x800F88A4: beq         $v1, $zero, L_800F8B04
    if (ctx->r3 == 0) {
        // 0x800F88A8: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_800F8B04;
    }
    // 0x800F88A8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800F88AC: beq         $v1, $s0, L_800F8954
    if (ctx->r3 == ctx->r16) {
        // 0x800F88B0: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800F8954;
    }
    // 0x800F88B0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800F88B4: bne         $v1, $v0, L_800F8B04
    if (ctx->r3 != ctx->r2) {
        // 0x800F88B8: addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
            goto L_800F8B04;
    }
    // 0x800F88B8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800F88BC: lwc1        $f0, 0x0($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800F88C0: lwc1        $f2, 0xC8($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0XC8);
    // 0x800F88C4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F88C8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800F88CC: lwc1        $f0, 0x4($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X4);
    // 0x800F88D0: lwc1        $f2, 0xCC($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0XCC);
    // 0x800F88D4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F88D8: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800F88DC: lwc1        $f0, 0x8($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X8);
    // 0x800F88E0: lwc1        $f2, 0xD0($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0XD0);
    // 0x800F88E4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F88E8: jal         0x8001CF2C
    // 0x800F88EC: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    vec3Length(rdram, ctx);
        goto after_13;
    // 0x800F88EC: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x800F88F0: lh          $v0, 0xF2($s4)
    ctx->r2 = MEM_H(ctx->r20, 0XF2);
    // 0x800F88F4: bne         $v0, $s0, L_800F8938
    if (ctx->r2 != ctx->r16) {
        // 0x800F88F8: mov.s       $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
            goto L_800F8938;
    }
    // 0x800F88F8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x800F88FC: lwc1        $f0, 0xE0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XE0);
    // 0x800F8900: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F8904: lwc1        $f2, -0x7148($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7148);
    // 0x800F8908: sub.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F890C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F8910: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x800F8914: nop

    // 0x800F8918: bc1tl       L_800F8920
    if (c1cs) {
        // 0x800F891C: mov.s       $f20, $f24
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
            goto L_800F8920;
    }
    goto skip_1;
    // 0x800F891C: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
    skip_1:
L_800F8920:
    // 0x800F8920: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x800F8924: nop

    // 0x800F8928: bc1tl       L_800F8B04
    if (c1cs) {
        // 0x800F892C: sh          $zero, 0xF2($s4)
        MEM_H(0XF2, ctx->r20) = 0;
            goto L_800F8B04;
    }
    goto skip_2;
    // 0x800F892C: sh          $zero, 0xF2($s4)
    MEM_H(0XF2, ctx->r20) = 0;
    skip_2:
    // 0x800F8930: j           L_800F8AEC
    // 0x800F8934: nop

        goto L_800F8AEC;
    // 0x800F8934: nop

L_800F8938:
    // 0x800F8938: lwc1        $f0, 0xE0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XE0);
    // 0x800F893C: c.le.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl <= ctx->f22.fl;
    // 0x800F8940: nop

    // 0x800F8944: bc1f        L_800F8B04
    if (!c1cs) {
        // 0x800F8948: nop
    
            goto L_800F8B04;
    }
    // 0x800F8948: nop

    // 0x800F894C: j           L_800F8AEC
    // 0x800F8950: sh          $s0, 0xF2($s4)
    MEM_H(0XF2, ctx->r20) = ctx->r16;
        goto L_800F8AEC;
    // 0x800F8950: sh          $s0, 0xF2($s4)
    MEM_H(0XF2, ctx->r20) = ctx->r16;
L_800F8954:
    // 0x800F8954: lh          $v0, 0xF2($s4)
    ctx->r2 = MEM_H(ctx->r20, 0XF2);
    // 0x800F8958: bne         $v0, $v1, L_800F8A58
    if (ctx->r2 != ctx->r3) {
        // 0x800F895C: nop
    
            goto L_800F8A58;
    }
    // 0x800F895C: nop

    // 0x800F8960: lwc1        $f0, 0xE0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XE0);
    // 0x800F8964: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800F8968: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F896C: lwc1        $f4, -0x7144($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7144);
    // 0x800F8970: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800F8974: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800F8978: c.le.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl <= ctx->f2.fl;
    // 0x800F897C: nop

    // 0x800F8980: bc1tl       L_800F8988
    if (c1cs) {
        // 0x800F8984: mov.s       $f6, $f24
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    ctx->f6.fl = ctx->f24.fl;
            goto L_800F8988;
    }
    goto skip_3;
    // 0x800F8984: mov.s       $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    ctx->f6.fl = ctx->f24.fl;
    skip_3:
L_800F8988:
    // 0x800F8988: lwc1        $f0, 0xE4($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XE4);
    // 0x800F898C: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800F8990: sub.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800F8994: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x800F8998: nop

    // 0x800F899C: bc1tl       L_800F89A4
    if (c1cs) {
        // 0x800F89A0: mov.s       $f8, $f24
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    ctx->f8.fl = ctx->f24.fl;
            goto L_800F89A4;
    }
    goto skip_4;
    // 0x800F89A0: mov.s       $f8, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    ctx->f8.fl = ctx->f24.fl;
    skip_4:
L_800F89A4:
    // 0x800F89A4: lwc1        $f0, 0xE8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XE8);
    // 0x800F89A8: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800F89AC: sub.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800F89B0: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x800F89B4: nop

    // 0x800F89B8: bc1tl       L_800F89C0
    if (c1cs) {
        // 0x800F89BC: mov.s       $f10, $f24
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    ctx->f10.fl = ctx->f24.fl;
            goto L_800F89C0;
    }
    goto skip_5;
    // 0x800F89BC: mov.s       $f10, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    ctx->f10.fl = ctx->f24.fl;
    skip_5:
L_800F89C0:
    // 0x800F89C0: lwc1        $f4, 0xD4($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0XD4);
    // 0x800F89C4: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800F89C8: lwc1        $f2, 0x0($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800F89CC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800F89D0: nop

    // 0x800F89D4: bc1f        L_800F8AEC
    if (!c1cs) {
        // 0x800F89D8: nop
    
            goto L_800F8AEC;
    }
    // 0x800F89D8: nop

    // 0x800F89DC: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F89E0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800F89E4: nop

    // 0x800F89E8: bc1f        L_800F8AEC
    if (!c1cs) {
        // 0x800F89EC: nop
    
            goto L_800F8AEC;
    }
    // 0x800F89EC: nop

    // 0x800F89F0: lwc1        $f4, 0xD8($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0XD8);
    // 0x800F89F4: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800F89F8: lwc1        $f2, 0x4($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X4);
    // 0x800F89FC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800F8A00: nop

    // 0x800F8A04: bc1f        L_800F8AEC
    if (!c1cs) {
        // 0x800F8A08: nop
    
            goto L_800F8AEC;
    }
    // 0x800F8A08: nop

    // 0x800F8A0C: add.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800F8A10: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800F8A14: nop

    // 0x800F8A18: bc1f        L_800F8AEC
    if (!c1cs) {
        // 0x800F8A1C: nop
    
            goto L_800F8AEC;
    }
    // 0x800F8A1C: nop

    // 0x800F8A20: lwc1        $f4, 0xDC($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0XDC);
    // 0x800F8A24: sub.s       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800F8A28: lwc1        $f2, 0x8($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X8);
    // 0x800F8A2C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800F8A30: nop

    // 0x800F8A34: bc1f        L_800F8AEC
    if (!c1cs) {
        // 0x800F8A38: nop
    
            goto L_800F8AEC;
    }
    // 0x800F8A38: nop

    // 0x800F8A3C: add.s       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800F8A40: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800F8A44: nop

    // 0x800F8A48: bc1f        L_800F8AEC
    if (!c1cs) {
        // 0x800F8A4C: nop
    
            goto L_800F8AEC;
    }
    // 0x800F8A4C: nop

    // 0x800F8A50: j           L_800F8B04
    // 0x800F8A54: sh          $zero, 0xF2($s4)
    MEM_H(0XF2, ctx->r20) = 0;
        goto L_800F8B04;
    // 0x800F8A54: sh          $zero, 0xF2($s4)
    MEM_H(0XF2, ctx->r20) = 0;
L_800F8A58:
    // 0x800F8A58: lwc1        $f4, 0x0($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800F8A5C: lwc1        $f2, 0xC8($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0XC8);
    // 0x800F8A60: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x800F8A64: nop

    // 0x800F8A68: bc1t        L_800F8AE8
    if (c1cs) {
        // 0x800F8A6C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F8AE8;
    }
    // 0x800F8A6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F8A70: lwc1        $f0, 0xE0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XE0);
    // 0x800F8A74: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800F8A78: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800F8A7C: nop

    // 0x800F8A80: bc1tl       L_800F8AEC
    if (c1cs) {
        // 0x800F8A84: sh          $v0, 0xF2($s4)
        MEM_H(0XF2, ctx->r20) = ctx->r2;
            goto L_800F8AEC;
    }
    goto skip_6;
    // 0x800F8A84: sh          $v0, 0xF2($s4)
    MEM_H(0XF2, ctx->r20) = ctx->r2;
    skip_6:
    // 0x800F8A88: lwc1        $f4, 0x4($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X4);
    // 0x800F8A8C: lwc1        $f2, 0xCC($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0XCC);
    // 0x800F8A90: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x800F8A94: nop

    // 0x800F8A98: bc1tl       L_800F8AEC
    if (c1cs) {
        // 0x800F8A9C: sh          $v0, 0xF2($s4)
        MEM_H(0XF2, ctx->r20) = ctx->r2;
            goto L_800F8AEC;
    }
    goto skip_7;
    // 0x800F8A9C: sh          $v0, 0xF2($s4)
    MEM_H(0XF2, ctx->r20) = ctx->r2;
    skip_7:
    // 0x800F8AA0: lwc1        $f0, 0xE4($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XE4);
    // 0x800F8AA4: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800F8AA8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800F8AAC: nop

    // 0x800F8AB0: bc1tl       L_800F8AEC
    if (c1cs) {
        // 0x800F8AB4: sh          $v0, 0xF2($s4)
        MEM_H(0XF2, ctx->r20) = ctx->r2;
            goto L_800F8AEC;
    }
    goto skip_8;
    // 0x800F8AB4: sh          $v0, 0xF2($s4)
    MEM_H(0XF2, ctx->r20) = ctx->r2;
    skip_8:
    // 0x800F8AB8: lwc1        $f4, 0x8($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X8);
    // 0x800F8ABC: lwc1        $f2, 0xD0($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0XD0);
    // 0x800F8AC0: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x800F8AC4: nop

    // 0x800F8AC8: bc1tl       L_800F8AEC
    if (c1cs) {
        // 0x800F8ACC: sh          $v0, 0xF2($s4)
        MEM_H(0XF2, ctx->r20) = ctx->r2;
            goto L_800F8AEC;
    }
    goto skip_9;
    // 0x800F8ACC: sh          $v0, 0xF2($s4)
    MEM_H(0XF2, ctx->r20) = ctx->r2;
    skip_9:
    // 0x800F8AD0: lwc1        $f0, 0xE8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XE8);
    // 0x800F8AD4: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800F8AD8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800F8ADC: nop

    // 0x800F8AE0: bc1f        L_800F8B04
    if (!c1cs) {
        // 0x800F8AE4: nop
    
            goto L_800F8B04;
    }
    // 0x800F8AE4: nop

L_800F8AE8:
    // 0x800F8AE8: sh          $v0, 0xF2($s4)
    MEM_H(0XF2, ctx->r20) = ctx->r2;
L_800F8AEC:
    // 0x800F8AEC: lw          $t1, 0xD4($s4)
    ctx->r9 = MEM_W(ctx->r20, 0XD4);
    // 0x800F8AF0: lw          $t2, 0xD8($s4)
    ctx->r10 = MEM_W(ctx->r20, 0XD8);
    // 0x800F8AF4: lw          $t3, 0xDC($s4)
    ctx->r11 = MEM_W(ctx->r20, 0XDC);
    // 0x800F8AF8: sw          $t1, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r9;
    // 0x800F8AFC: sw          $t2, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->r10;
    // 0x800F8B00: sw          $t3, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->r11;
L_800F8B04:
    // 0x800F8B04: lwc1        $f0, 0x0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X0);
    // 0x800F8B08: lwc1        $f2, 0x0($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800F8B0C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F8B10: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800F8B14: lwc1        $f0, 0x4($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X4);
    // 0x800F8B18: lwc1        $f2, 0x4($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X4);
    // 0x800F8B1C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F8B20: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800F8B24: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x800F8B28: lwc1        $f2, 0x8($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X8);
    // 0x800F8B2C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F8B30: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800F8B34: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800F8B38: lwc1        $f0, 0x100($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X100);
    // 0x800F8B3C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800F8B40: nop

    // 0x800F8B44: bc1f        L_800F8B64
    if (!c1cs) {
        // 0x800F8B48: nop
    
            goto L_800F8B64;
    }
    // 0x800F8B48: nop

    // 0x800F8B4C: sub.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f26.fl;
    // 0x800F8B50: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800F8B54: nop

    // 0x800F8B58: bc1f        L_800F8B64
    if (!c1cs) {
        // 0x800F8B5C: swc1        $f0, 0x100($s4)
        MEM_W(0X100, ctx->r20) = ctx->f0.u32l;
            goto L_800F8B64;
    }
    // 0x800F8B5C: swc1        $f0, 0x100($s4)
    MEM_W(0X100, ctx->r20) = ctx->f0.u32l;
    // 0x800F8B60: swc1        $f2, 0x100($s4)
    MEM_W(0X100, ctx->r20) = ctx->f2.u32l;
L_800F8B64:
    // 0x800F8B64: lbu         $v0, 0xB8($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0XB8);
    // 0x800F8B68: beql        $v0, $zero, L_800F8D84
    if (ctx->r2 == 0) {
        // 0x800F8B6C: sw          $zero, 0x30($s4)
        MEM_W(0X30, ctx->r20) = 0;
            goto L_800F8D84;
    }
    goto skip_10;
    // 0x800F8B6C: sw          $zero, 0x30($s4)
    MEM_W(0X30, ctx->r20) = 0;
    skip_10:
    // 0x800F8B70: jal         0x8001CF2C
    // 0x800F8B74: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    vec3Length(rdram, ctx);
        goto after_14;
    // 0x800F8B74: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_14:
    // 0x800F8B78: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800F8B7C: addiu       $a1, $s5, 0xC
    ctx->r5 = ADD32(ctx->r21, 0XC);
    // 0x800F8B80: jal         0x8001CFE8
    // 0x800F8B84: swc1        $f0, 0x28($s4)
    MEM_W(0X28, ctx->r20) = ctx->f0.u32l;
    vec3Dot(rdram, ctx);
        goto after_15;
    // 0x800F8B84: swc1        $f0, 0x28($s4)
    MEM_W(0X28, ctx->r20) = ctx->f0.u32l;
    after_15:
    // 0x800F8B88: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800F8B8C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F8B90: nop

    // 0x800F8B94: bc1f        L_800F8D78
    if (!c1cs) {
        // 0x800F8B98: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800F8D78;
    }
    // 0x800F8B98: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800F8B9C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800F8BA0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F8BA4: lwc1        $f28, -0x7140($at)
    ctx->f28.u32l = MEM_W(ctx->r1, -0X7140);
    // 0x800F8BA8: lwc1        $f2, 0x8($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X8);
    // 0x800F8BAC: lw          $v1, -0x72E4($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X72E4);
    // 0x800F8BB0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F8BB4: lwc1        $f0, -0x713C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X713C);
    // 0x800F8BB8: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800F8BBC: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x800F8BC0: beq         $v0, $zero, L_800F8BD8
    if (ctx->r2 == 0) {
        // 0x800F8BC4: add.s       $f20, $f2, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f2.fl + ctx->f0.fl;
            goto L_800F8BD8;
    }
    // 0x800F8BC4: add.s       $f20, $f2, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800F8BC8: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800F8BCC: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800F8BD0: beq         $v0, $zero, L_800F8BE0
    if (ctx->r2 == 0) {
        // 0x800F8BD4: andi        $v0, $a0, 0xFF
        ctx->r2 = ctx->r4 & 0XFF;
            goto L_800F8BE0;
    }
    // 0x800F8BD4: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
L_800F8BD8:
    // 0x800F8BD8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800F8BDC: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
L_800F8BE0:
    // 0x800F8BE0: beq         $v0, $zero, L_800F8C54
    if (ctx->r2 == 0) {
        // 0x800F8BE4: nop
    
            goto L_800F8C54;
    }
    // 0x800F8BE4: nop

    // 0x800F8BE8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F8BEC: lwc1        $f0, -0x7138($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7138);
    // 0x800F8BF0: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800F8BF4: nop

    // 0x800F8BF8: bc1tl       L_800F8C00
    if (c1cs) {
        // 0x800F8BFC: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_800F8C00;
    }
    goto skip_11;
    // 0x800F8BFC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_11:
L_800F8C00:
    // 0x800F8C00: lwc1        $f2, 0x28($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X28);
    // 0x800F8C04: c.le.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl <= ctx->f20.fl;
    // 0x800F8C08: nop

    // 0x800F8C0C: bc1f        L_800F8C34
    if (!c1cs) {
        // 0x800F8C10: nop
    
            goto L_800F8C34;
    }
    // 0x800F8C10: nop

    // 0x800F8C14: jal         0x8001CF2C
    // 0x800F8C18: addiu       $a0, $fp, 0x24
    ctx->r4 = ADD32(ctx->r30, 0X24);
    vec3Length(rdram, ctx);
        goto after_16;
    // 0x800F8C18: addiu       $a0, $fp, 0x24
    ctx->r4 = ADD32(ctx->r30, 0X24);
    after_16:
    // 0x800F8C1C: lwc1        $f2, 0x18($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X18);
    // 0x800F8C20: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F8C24: lwc1        $f4, -0x7134($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7134);
    // 0x800F8C28: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800F8C2C: j           L_800F8D10
    // 0x800F8C30: swc1        $f0, 0x30($s4)
    MEM_W(0X30, ctx->r20) = ctx->f0.u32l;
        goto L_800F8D10;
    // 0x800F8C30: swc1        $f0, 0x30($s4)
    MEM_W(0X30, ctx->r20) = ctx->f0.u32l;
L_800F8C34:
    // 0x800F8C34: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F8C38: lwc1        $f0, -0x7130($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7130);
    // 0x800F8C3C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800F8C40: nop

    // 0x800F8C44: bc1t        L_800F8D40
    if (c1cs) {
        // 0x800F8C48: nop
    
            goto L_800F8D40;
    }
    // 0x800F8C48: nop

    // 0x800F8C4C: j           L_800F8D98
    // 0x800F8C50: sw          $zero, 0x30($s4)
    MEM_W(0X30, ctx->r20) = 0;
        goto L_800F8D98;
    // 0x800F8C50: sw          $zero, 0x30($s4)
    MEM_W(0X30, ctx->r20) = 0;
L_800F8C54:
    // 0x800F8C54: lwc1        $f2, 0x100($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X100);
    // 0x800F8C58: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F8C5C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800F8C60: nop

    // 0x800F8C64: bc1f        L_800F8C80
    if (!c1cs) {
        // 0x800F8C68: nop
    
            goto L_800F8C80;
    }
    // 0x800F8C68: nop

    // 0x800F8C6C: lwc1        $f2, 0x34($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X34);
    // 0x800F8C70: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F8C74: lwc1        $f0, -0x712C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X712C);
    // 0x800F8C78: j           L_800F8C88
    // 0x800F8C7C: add.s       $f22, $f2, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f2.fl + ctx->f0.fl;
        goto L_800F8C88;
    // 0x800F8C7C: add.s       $f22, $f2, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f2.fl + ctx->f0.fl;
L_800F8C80:
    // 0x800F8C80: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F8C84: lwc1        $f22, -0x7128($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X7128);
L_800F8C88:
    // 0x800F8C88: c.lt.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
    // 0x800F8C8C: nop

    // 0x800F8C90: bc1tl       L_800F8C98
    if (c1cs) {
        // 0x800F8C94: mov.s       $f20, $f22
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
            goto L_800F8C98;
    }
    goto skip_12;
    // 0x800F8C94: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    skip_12:
L_800F8C98:
    // 0x800F8C98: lwc1        $f2, 0x28($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X28);
    // 0x800F8C9C: c.le.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl <= ctx->f20.fl;
    // 0x800F8CA0: nop

    // 0x800F8CA4: bc1f        L_800F8D28
    if (!c1cs) {
        // 0x800F8CA8: nop
    
            goto L_800F8D28;
    }
    // 0x800F8CA8: nop

    // 0x800F8CAC: jal         0x8001CF2C
    // 0x800F8CB0: addiu       $a0, $fp, 0x24
    ctx->r4 = ADD32(ctx->r30, 0X24);
    vec3Length(rdram, ctx);
        goto after_17;
    // 0x800F8CB0: addiu       $a0, $fp, 0x24
    ctx->r4 = ADD32(ctx->r30, 0X24);
    after_17:
    // 0x800F8CB4: lwc1        $f4, 0x100($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X100);
    // 0x800F8CB8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800F8CBC: mov.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.fl = ctx->f0.fl;
    // 0x800F8CC0: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x800F8CC4: nop

    // 0x800F8CC8: bc1f        L_800F8CE8
    if (!c1cs) {
        // 0x800F8CCC: swc1        $f6, 0x30($s4)
        MEM_W(0X30, ctx->r20) = ctx->f6.u32l;
            goto L_800F8CE8;
    }
    // 0x800F8CCC: swc1        $f6, 0x30($s4)
    MEM_W(0X30, ctx->r20) = ctx->f6.u32l;
    // 0x800F8CD0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F8CD4: lwc1        $f0, -0x7124($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7124);
    // 0x800F8CD8: div.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800F8CDC: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800F8CE0: j           L_800F8CFC
    // 0x800F8CE4: swc1        $f0, 0x30($s4)
    MEM_W(0X30, ctx->r20) = ctx->f0.u32l;
        goto L_800F8CFC;
    // 0x800F8CE4: swc1        $f0, 0x30($s4)
    MEM_W(0X30, ctx->r20) = ctx->f0.u32l;
L_800F8CE8:
    // 0x800F8CE8: lwc1        $f0, 0x34($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X34);
    // 0x800F8CEC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F8CF0: lwc1        $f2, -0x7120($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7120);
    // 0x800F8CF4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F8CF8: swc1        $f0, 0x100($s4)
    MEM_W(0X100, ctx->r20) = ctx->f0.u32l;
L_800F8CFC:
    // 0x800F8CFC: lwc1        $f0, 0x18($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X18);
    // 0x800F8D00: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F8D04: lwc1        $f2, -0x711C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X711C);
    // 0x800F8D08: add.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F8D0C: lwc1        $f0, 0x30($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X30);
L_800F8D10:
    // 0x800F8D10: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800F8D14: nop

    // 0x800F8D18: bc1f        L_800F8D98
    if (!c1cs) {
        // 0x800F8D1C: nop
    
            goto L_800F8D98;
    }
    // 0x800F8D1C: nop

    // 0x800F8D20: j           L_800F8D98
    // 0x800F8D24: swc1        $f2, 0x30($s4)
    MEM_W(0X30, ctx->r20) = ctx->f2.u32l;
        goto L_800F8D98;
    // 0x800F8D24: swc1        $f2, 0x30($s4)
    MEM_W(0X30, ctx->r20) = ctx->f2.u32l;
L_800F8D28:
    // 0x800F8D28: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F8D2C: lwc1        $f0, -0x7118($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7118);
    // 0x800F8D30: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800F8D34: nop

    // 0x800F8D38: bc1f        L_800F8D58
    if (!c1cs) {
        // 0x800F8D3C: nop
    
            goto L_800F8D58;
    }
    // 0x800F8D3C: nop

L_800F8D40:
    // 0x800F8D40: lwc1        $f0, 0x18($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X18);
    // 0x800F8D44: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F8D48: lwc1        $f2, -0x7114($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7114);
    // 0x800F8D4C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F8D50: j           L_800F8D98
    // 0x800F8D54: swc1        $f0, 0x30($s4)
    MEM_W(0X30, ctx->r20) = ctx->f0.u32l;
        goto L_800F8D98;
    // 0x800F8D54: swc1        $f0, 0x30($s4)
    MEM_W(0X30, ctx->r20) = ctx->f0.u32l;
L_800F8D58:
    // 0x800F8D58: lwc1        $f0, 0x100($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X100);
    // 0x800F8D5C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800F8D60: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800F8D64: nop

    // 0x800F8D68: bc1tl       L_800F8D98
    if (c1cs) {
        // 0x800F8D6C: swc1        $f2, 0x30($s4)
        MEM_W(0X30, ctx->r20) = ctx->f2.u32l;
            goto L_800F8D98;
    }
    goto skip_13;
    // 0x800F8D6C: swc1        $f2, 0x30($s4)
    MEM_W(0X30, ctx->r20) = ctx->f2.u32l;
    skip_13:
    // 0x800F8D70: j           L_800F8D98
    // 0x800F8D74: swc1        $f2, 0x100($s4)
    MEM_W(0X100, ctx->r20) = ctx->f2.u32l;
        goto L_800F8D98;
    // 0x800F8D74: swc1        $f2, 0x100($s4)
    MEM_W(0X100, ctx->r20) = ctx->f2.u32l;
L_800F8D78:
    // 0x800F8D78: lwc1        $f28, 0x38($s4)
    ctx->f28.u32l = MEM_W(ctx->r20, 0X38);
    // 0x800F8D7C: j           L_800F8D98
    // 0x800F8D80: swc1        $f2, 0x30($s4)
    MEM_W(0X30, ctx->r20) = ctx->f2.u32l;
        goto L_800F8D98;
    // 0x800F8D80: swc1        $f2, 0x30($s4)
    MEM_W(0X30, ctx->r20) = ctx->f2.u32l;
L_800F8D84:
    // 0x800F8D84: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F8D88: lwc1        $f28, -0x7110($at)
    ctx->f28.u32l = MEM_W(ctx->r1, -0X7110);
    // 0x800F8D8C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F8D90: lwc1        $f0, -0x710C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X710C);
    // 0x800F8D94: swc1        $f0, 0x28($s4)
    MEM_W(0X28, ctx->r20) = ctx->f0.u32l;
L_800F8D98:
    // 0x800F8D98: lwc1        $f2, 0x20($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X20);
    // 0x800F8D9C: lwc1        $f0, 0x3C($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X3C);
    // 0x800F8DA0: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x800F8DA4: nop

    // 0x800F8DA8: bc1t        L_800F8DF0
    if (c1cs) {
        // 0x800F8DAC: nop
    
            goto L_800F8DF0;
    }
    // 0x800F8DAC: nop

    // 0x800F8DB0: lwc1        $f0, 0x40($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X40);
    // 0x800F8DB4: sub.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f26.fl;
    // 0x800F8DB8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800F8DBC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800F8DC0: nop

    // 0x800F8DC4: bc1f        L_800F8DE4
    if (!c1cs) {
        // 0x800F8DC8: swc1        $f0, 0x40($s4)
        MEM_W(0X40, ctx->r20) = ctx->f0.u32l;
            goto L_800F8DE4;
    }
    // 0x800F8DC8: swc1        $f0, 0x40($s4)
    MEM_W(0X40, ctx->r20) = ctx->f0.u32l;
    // 0x800F8DCC: lwc1        $f2, 0x44($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X44);
    // 0x800F8DD0: mul.s       $f2, $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f26.fl);
    // 0x800F8DD4: lwc1        $f0, 0x20($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X20);
    // 0x800F8DD8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F8DDC: j           L_800F8F80
    // 0x800F8DE0: swc1        $f0, 0x20($s4)
    MEM_W(0X20, ctx->r20) = ctx->f0.u32l;
        goto L_800F8F80;
    // 0x800F8DE0: swc1        $f0, 0x20($s4)
    MEM_W(0X20, ctx->r20) = ctx->f0.u32l;
L_800F8DE4:
    // 0x800F8DE4: lwc1        $f0, 0x3C($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X3C);
    // 0x800F8DE8: j           L_800F8F80
    // 0x800F8DEC: swc1        $f0, 0x20($s4)
    MEM_W(0X20, ctx->r20) = ctx->f0.u32l;
        goto L_800F8F80;
    // 0x800F8DEC: swc1        $f0, 0x20($s4)
    MEM_W(0X20, ctx->r20) = ctx->f0.u32l;
L_800F8DF0:
    // 0x800F8DF0: lwc1        $f0, 0x30($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X30);
    // 0x800F8DF4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800F8DF8: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800F8DFC: nop

    // 0x800F8E00: bc1f        L_800F8E28
    if (!c1cs) {
        // 0x800F8E04: nop
    
            goto L_800F8E28;
    }
    // 0x800F8E04: nop

    // 0x800F8E08: lwc1        $f0, 0x2C($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X2C);
    // 0x800F8E0C: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800F8E10: nop

    // 0x800F8E14: bc1t        L_800F8E90
    if (c1cs) {
        // 0x800F8E18: mov.s       $f22, $f2
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
            goto L_800F8E90;
    }
    // 0x800F8E18: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
    // 0x800F8E1C: lwc1        $f0, 0x30($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X30);
    // 0x800F8E20: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800F8E24: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
L_800F8E28:
    // 0x800F8E28: nop

    // 0x800F8E2C: bc1f        L_800F8E48
    if (!c1cs) {
        // 0x800F8E30: nop
    
            goto L_800F8E48;
    }
    // 0x800F8E30: nop

    // 0x800F8E34: lwc1        $f0, 0x2C($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X2C);
    // 0x800F8E38: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800F8E3C: nop

    // 0x800F8E40: bc1f        L_800F8E90
    if (!c1cs) {
        // 0x800F8E44: mov.s       $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
            goto L_800F8E90;
    }
    // 0x800F8E44: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_800F8E48:
    // 0x800F8E48: lwc1        $f2, 0x30($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X30);
    // 0x800F8E4C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800F8E50: c.eq.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl == ctx->f4.fl;
    // 0x800F8E54: nop

    // 0x800F8E58: bc1t        L_800F8E74
    if (c1cs) {
        // 0x800F8E5C: nop
    
            goto L_800F8E74;
    }
    // 0x800F8E5C: nop

    // 0x800F8E60: lwc1        $f0, 0x2C($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X2C);
    // 0x800F8E64: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800F8E68: nop

    // 0x800F8E6C: bc1t        L_800F8E90
    if (c1cs) {
        // 0x800F8E70: mov.s       $f22, $f2
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
            goto L_800F8E90;
    }
    // 0x800F8E70: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
L_800F8E74:
    // 0x800F8E74: lwc1        $f0, 0x30($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X30);
    // 0x800F8E78: lwc1        $f2, 0x2C($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X2C);
    // 0x800F8E7C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x800F8E80: c.lt.s      $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f22.fl < ctx->f2.fl;
    // 0x800F8E84: nop

    // 0x800F8E88: bc1tl       L_800F8E90
    if (c1cs) {
        // 0x800F8E8C: mov.s       $f22, $f2
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
            goto L_800F8E90;
    }
    goto skip_14;
    // 0x800F8E8C: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
    skip_14:
L_800F8E90:
    // 0x800F8E90: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F8E94: c.eq.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl == ctx->f0.fl;
    // 0x800F8E98: nop

    // 0x800F8E9C: bc1t        L_800F8EF0
    if (c1cs) {
        // 0x800F8EA0: nop
    
            goto L_800F8EF0;
    }
    // 0x800F8EA0: nop

    // 0x800F8EA4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F8EA8: lwc1        $f0, -0x7108($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7108);
    // 0x800F8EAC: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x800F8EB0: nop

    // 0x800F8EB4: bc1f        L_800F8EC0
    if (!c1cs) {
        // 0x800F8EB8: swc1        $f22, 0x3C($s4)
        MEM_W(0X3C, ctx->r20) = ctx->f22.u32l;
            goto L_800F8EC0;
    }
    // 0x800F8EB8: swc1        $f22, 0x3C($s4)
    MEM_W(0X3C, ctx->r20) = ctx->f22.u32l;
    // 0x800F8EBC: swc1        $f0, 0x3C($s4)
    MEM_W(0X3C, ctx->r20) = ctx->f0.u32l;
L_800F8EC0:
    // 0x800F8EC0: lwc1        $f2, 0x3C($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X3C);
    // 0x800F8EC4: lwc1        $f0, 0x20($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X20);
    // 0x800F8EC8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800F8ECC: nop

    // 0x800F8ED0: bc1f        L_800F8EE4
    if (!c1cs) {
        // 0x800F8ED4: nop
    
            goto L_800F8EE4;
    }
    // 0x800F8ED4: nop

    // 0x800F8ED8: lwc1        $f0, 0x34($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X34);
    // 0x800F8EDC: j           L_800F8F58
    // 0x800F8EE0: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
        goto L_800F8F58;
    // 0x800F8EE0: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
L_800F8EE4:
    // 0x800F8EE4: lwc1        $f0, 0x34($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X34);
    // 0x800F8EE8: j           L_800F8F58
    // 0x800F8EEC: nop

        goto L_800F8F58;
    // 0x800F8EEC: nop

L_800F8EF0:
    // 0x800F8EF0: lwc1        $f2, 0x3C($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X3C);
    // 0x800F8EF4: lwc1        $f0, 0x18($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X18);
    // 0x800F8EF8: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x800F8EFC: nop

    // 0x800F8F00: bc1tl       L_800F8F80
    if (c1cs) {
        // 0x800F8F04: swc1        $f2, 0x20($s4)
        MEM_W(0X20, ctx->r20) = ctx->f2.u32l;
            goto L_800F8F80;
    }
    goto skip_15;
    // 0x800F8F04: swc1        $f2, 0x20($s4)
    MEM_W(0X20, ctx->r20) = ctx->f2.u32l;
    skip_15:
    // 0x800F8F08: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F8F0C: lwc1        $f2, -0x7104($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7104);
    // 0x800F8F10: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800F8F14: nop

    // 0x800F8F18: bc1f        L_800F8F24
    if (!c1cs) {
        // 0x800F8F1C: swc1        $f0, 0x3C($s4)
        MEM_W(0X3C, ctx->r20) = ctx->f0.u32l;
            goto L_800F8F24;
    }
    // 0x800F8F1C: swc1        $f0, 0x3C($s4)
    MEM_W(0X3C, ctx->r20) = ctx->f0.u32l;
    // 0x800F8F20: swc1        $f2, 0x3C($s4)
    MEM_W(0X3C, ctx->r20) = ctx->f2.u32l;
L_800F8F24:
    // 0x800F8F24: lwc1        $f2, 0x3C($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X3C);
    // 0x800F8F28: lwc1        $f0, 0x20($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X20);
    // 0x800F8F2C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800F8F30: nop

    // 0x800F8F34: bc1f        L_800F8F48
    if (!c1cs) {
        // 0x800F8F38: nop
    
            goto L_800F8F48;
    }
    // 0x800F8F38: nop

    // 0x800F8F3C: lwc1        $f0, 0x34($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X34);
    // 0x800F8F40: j           L_800F8F58
    // 0x800F8F44: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
        goto L_800F8F58;
    // 0x800F8F44: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
L_800F8F48:
    // 0x800F8F48: lwc1        $f0, 0x34($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X34);
    // 0x800F8F4C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F8F50: lwc1        $f2, -0x7100($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7100);
    // 0x800F8F54: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
L_800F8F58:
    // 0x800F8F58: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F8F5C: lwc1        $f2, -0x70FC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X70FC);
    // 0x800F8F60: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F8F64: swc1        $f0, 0x40($s4)
    MEM_W(0X40, ctx->r20) = ctx->f0.u32l;
    // 0x800F8F68: lwc1        $f0, 0x3C($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X3C);
    // 0x800F8F6C: lwc1        $f2, 0x20($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X20);
    // 0x800F8F70: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F8F74: lwc1        $f2, 0x40($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X40);
    // 0x800F8F78: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F8F7C: swc1        $f0, 0x44($s4)
    MEM_W(0X44, ctx->r20) = ctx->f0.u32l;
L_800F8F80:
    // 0x800F8F80: lwc1        $f0, 0xC($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XC);
    // 0x800F8F84: lwc1        $f2, 0x0($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800F8F88: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F8F8C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800F8F90: lwc1        $f0, 0x10($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X10);
    // 0x800F8F94: lwc1        $f2, 0x4($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X4);
    // 0x800F8F98: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F8F9C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800F8FA0: lwc1        $f0, 0x14($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X14);
    // 0x800F8FA4: lwc1        $f2, 0x8($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X8);
    // 0x800F8FA8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F8FAC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800F8FB0: jal         0x8001CF2C
    // 0x800F8FB4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    vec3Length(rdram, ctx);
        goto after_18;
    // 0x800F8FB4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_18:
    // 0x800F8FB8: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x800F8FBC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x800F8FC0: c.eq.s      $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f22.fl == ctx->f24.fl;
    // 0x800F8FC4: nop

    // 0x800F8FC8: bc1t        L_800F918C
    if (c1cs) {
        // 0x800F8FCC: nop
    
            goto L_800F918C;
    }
    // 0x800F8FCC: nop

    // 0x800F8FD0: jal         0x8001CF58
    // 0x800F8FD4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    normalize_vector(rdram, ctx);
        goto after_19;
    // 0x800F8FD4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_19:
    // 0x800F8FD8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800F8FDC: addiu       $s3, $s5, 0xC
    ctx->r19 = ADD32(ctx->r21, 0XC);
    // 0x800F8FE0: jal         0x8001CFE8
    // 0x800F8FE4: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    vec3Dot(rdram, ctx);
        goto after_20;
    // 0x800F8FE4: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_20:
    // 0x800F8FE8: jal         0x8001C5CC
    // 0x800F8FEC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    constMinusSinfApprox(rdram, ctx);
        goto after_21;
    // 0x800F8FEC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_21:
    // 0x800F8FF0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F8FF4: lwc1        $f2, -0x70F8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X70F8);
    // 0x800F8FF8: mul.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F8FFC: c.eq.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl == ctx->f24.fl;
    // 0x800F9000: nop

    // 0x800F9004: bc1t        L_800F90B4
    if (c1cs) {
        // 0x800F9008: nop
    
            goto L_800F90B4;
    }
    // 0x800F9008: nop

    // 0x800F900C: lwc1        $f0, 0x24($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X24);
    // 0x800F9010: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x800F9014: nop

    // 0x800F9018: mul.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x800F901C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800F9020: nop

    // 0x800F9024: bc1tl       L_800F902C
    if (c1cs) {
        // 0x800F9028: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_800F902C;
    }
    goto skip_16;
    // 0x800F9028: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_16:
L_800F902C:
    // 0x800F902C: addiu       $s1, $sp, 0x20
    ctx->r17 = ADD32(ctx->r29, 0X20);
    // 0x800F9030: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F9034: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800F9038: jal         0x80019548
    // 0x800F903C: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    vec3Cross(rdram, ctx);
        goto after_22;
    // 0x800F903C: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_22:
    // 0x800F9040: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
    // 0x800F9044: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F9048: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800F904C: jal         0x8001D144
    // 0x800F9050: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    quatFromAxisAngleSafe(rdram, ctx);
        goto after_23;
    // 0x800F9050: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_23:
    // 0x800F9054: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F9058: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800F905C: jal         0x8001D3C4
    // 0x800F9060: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_24;
    // 0x800F9060: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_24:
    // 0x800F9064: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F9068: addiu       $a1, $s5, 0x18
    ctx->r5 = ADD32(ctx->r21, 0X18);
    // 0x800F906C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800F9070: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800F9074: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800F9078: sw          $t1, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r9;
    // 0x800F907C: sw          $t2, 0x10($s5)
    MEM_W(0X10, ctx->r21) = ctx->r10;
    // 0x800F9080: sw          $t3, 0x14($s5)
    MEM_W(0X14, ctx->r21) = ctx->r11;
    // 0x800F9084: jal         0x8001D3C4
    // 0x800F9088: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_25;
    // 0x800F9088: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_25:
    // 0x800F908C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800F9090: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800F9094: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800F9098: sw          $t1, 0x18($s5)
    MEM_W(0X18, ctx->r21) = ctx->r9;
    // 0x800F909C: sw          $t2, 0x1C($s5)
    MEM_W(0X1C, ctx->r21) = ctx->r10;
    // 0x800F90A0: sw          $t3, 0x20($s5)
    MEM_W(0X20, ctx->r21) = ctx->r11;
    // 0x800F90A4: jal         0x80059F70
    // 0x800F90A8: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    func_80059F70(rdram, ctx);
        goto after_26;
    // 0x800F90A8: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_26:
    // 0x800F90AC: j           L_800F9188
    // 0x800F90B0: swc1        $f24, 0xF4($s4)
    MEM_W(0XF4, ctx->r20) = ctx->f24.u32l;
        goto L_800F9188;
    // 0x800F90B0: swc1        $f24, 0xF4($s4)
    MEM_W(0XF4, ctx->r20) = ctx->f24.u32l;
L_800F90B4:
    // 0x800F90B4: lwc1        $f0, 0xF4($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XF4);
    // 0x800F90B8: add.s       $f2, $f0, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f26.fl;
    // 0x800F90BC: lwc1        $f0, 0xF8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XF8);
    // 0x800F90C0: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x800F90C4: nop

    // 0x800F90C8: bc1f        L_800F9188
    if (!c1cs) {
        // 0x800F90CC: swc1        $f2, 0xF4($s4)
        MEM_W(0XF4, ctx->r20) = ctx->f2.u32l;
            goto L_800F9188;
    }
    // 0x800F90CC: swc1        $f2, 0xF4($s4)
    MEM_W(0XF4, ctx->r20) = ctx->f2.u32l;
    // 0x800F90D0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F90D4: lwc1        $f0, -0x70F4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X70F4);
    // 0x800F90D8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800F90DC: nop

    // 0x800F90E0: bc1fl       L_800F918C
    if (!c1cs) {
        // 0x800F90E4: swc1        $f22, 0xF8($s4)
        MEM_W(0XF8, ctx->r20) = ctx->f22.u32l;
            goto L_800F918C;
    }
    goto skip_17;
    // 0x800F90E4: swc1        $f22, 0xF8($s4)
    MEM_W(0XF8, ctx->r20) = ctx->f22.u32l;
    skip_17:
    // 0x800F90E8: jal         0x80003430
    // 0x800F90EC: addiu       $s2, $s5, 0x18
    ctx->r18 = ADD32(ctx->r21, 0X18);
    rand_recomp(rdram, ctx);
        goto after_27;
    // 0x800F90EC: addiu       $s2, $s5, 0x18
    ctx->r18 = ADD32(ctx->r21, 0X18);
    after_27:
    // 0x800F90F0: lwc1        $f4, 0x24($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X24);
    // 0x800F90F4: addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
    // 0x800F90F8: mul.s       $f4, $f4, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x800F90FC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F9100: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800F9104: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F9108: lwc1        $f0, -0x70F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X70F0);
    // 0x800F910C: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800F9110: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800F9114: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800F9118: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800F911C: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F9120: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800F9124: jal         0x8001D240
    // 0x800F9128: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    quatFromAxisAngle(rdram, ctx);
        goto after_28;
    // 0x800F9128: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_28:
    // 0x800F912C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F9130: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800F9134: addiu       $s0, $sp, 0x20
    ctx->r16 = ADD32(ctx->r29, 0X20);
    // 0x800F9138: jal         0x8001D3C4
    // 0x800F913C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_29;
    // 0x800F913C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_29:
    // 0x800F9140: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F9144: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800F9148: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800F914C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800F9150: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800F9154: sw          $t1, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r9;
    // 0x800F9158: sw          $t2, 0x10($s5)
    MEM_W(0X10, ctx->r21) = ctx->r10;
    // 0x800F915C: sw          $t3, 0x14($s5)
    MEM_W(0X14, ctx->r21) = ctx->r11;
    // 0x800F9160: jal         0x8001D3C4
    // 0x800F9164: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_30;
    // 0x800F9164: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_30:
    // 0x800F9168: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800F916C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800F9170: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800F9174: sw          $t1, 0x18($s5)
    MEM_W(0X18, ctx->r21) = ctx->r9;
    // 0x800F9178: sw          $t2, 0x1C($s5)
    MEM_W(0X1C, ctx->r21) = ctx->r10;
    // 0x800F917C: sw          $t3, 0x20($s5)
    MEM_W(0X20, ctx->r21) = ctx->r11;
    // 0x800F9180: jal         0x80059F70
    // 0x800F9184: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    func_80059F70(rdram, ctx);
        goto after_31;
    // 0x800F9184: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_31:
L_800F9188:
    // 0x800F9188: swc1        $f22, 0xF8($s4)
    MEM_W(0XF8, ctx->r20) = ctx->f22.u32l;
L_800F918C:
    // 0x800F918C: lwc1        $f0, 0xC($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0XC);
    // 0x800F9190: lwc1        $f2, 0x20($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X20);
    // 0x800F9194: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F9198: swc1        $f0, 0x24($s5)
    MEM_W(0X24, ctx->r21) = ctx->f0.u32l;
    // 0x800F919C: lwc1        $f0, 0x10($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X10);
    // 0x800F91A0: lwc1        $f2, 0x20($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X20);
    // 0x800F91A4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F91A8: lwc1        $f2, 0x14($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X14);
    // 0x800F91AC: swc1        $f0, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->f0.u32l;
    // 0x800F91B0: lwc1        $f0, 0x20($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X20);
    // 0x800F91B4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F91B8: lwc1        $f6, 0x28($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X28);
    // 0x800F91BC: mul.s       $f6, $f6, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x800F91C0: lwc1        $f0, 0x24($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X24);
    // 0x800F91C4: mul.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x800F91C8: addiu       $s2, $sp, 0x30
    ctx->r18 = ADD32(ctx->r29, 0X30);
    // 0x800F91CC: swc1        $f2, 0x2C($s5)
    MEM_W(0X2C, ctx->r21) = ctx->f2.u32l;
    // 0x800F91D0: mov.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.fl = ctx->f2.fl;
    // 0x800F91D4: mul.s       $f8, $f8, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x800F91D8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F91DC: addiu       $a1, $s5, 0x18
    ctx->r5 = ADD32(ctx->r21, 0X18);
    // 0x800F91E0: lwc1        $f4, 0x0($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800F91E4: addiu       $s1, $s5, 0xC
    ctx->r17 = ADD32(ctx->r21, 0XC);
    // 0x800F91E8: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800F91EC: lwc1        $f2, 0x4($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X4);
    // 0x800F91F0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x800F91F4: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x800F91F8: lwc1        $f0, 0x8($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X8);
    // 0x800F91FC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F9200: lwc1        $f6, -0x70EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X70EC);
    // 0x800F9204: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x800F9208: swc1        $f4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f4.u32l;
    // 0x800F920C: swc1        $f2, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->f2.u32l;
    // 0x800F9210: swc1        $f0, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->f0.u32l;
    // 0x800F9214: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800F9218: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800F921C: jal         0x80019548
    // 0x800F9220: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    vec3Cross(rdram, ctx);
        goto after_32;
    // 0x800F9220: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_32:
    // 0x800F9224: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x800F9228: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F922C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800F9230: jal         0x80019548
    // 0x800F9234: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    vec3Cross(rdram, ctx);
        goto after_33;
    // 0x800F9234: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_33:
    // 0x800F9238: jal         0x8001CF2C
    // 0x800F923C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    vec3Length(rdram, ctx);
        goto after_34;
    // 0x800F923C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_34:
    // 0x800F9240: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F9244: lwc1        $f2, -0x70E8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X70E8);
    // 0x800F9248: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x800F924C: c.lt.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl < ctx->f22.fl;
    // 0x800F9250: nop

    // 0x800F9254: bc1f        L_800F932C
    if (!c1cs) {
        // 0x800F9258: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_800F932C;
    }
    // 0x800F9258: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800F925C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800F9260: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800F9264: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800F9268: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800F926C: div.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F9270: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x800F9274: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800F9278: div.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f22.fl);
    // 0x800F927C: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x800F9280: div.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800F9284: jal         0x80019548
    // 0x800F9288: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    vec3Cross(rdram, ctx);
        goto after_35;
    // 0x800F9288: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_35:
    // 0x800F928C: jal         0x8001CF58
    // 0x800F9290: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    normalize_vector(rdram, ctx);
        goto after_36;
    // 0x800F9290: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_36:
    // 0x800F9294: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F9298: jal         0x8001CFE8
    // 0x800F929C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    vec3Dot(rdram, ctx);
        goto after_37;
    // 0x800F929C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_37:
    // 0x800F92A0: jal         0x8001C400
    // 0x800F92A4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    sinfApprox(rdram, ctx);
        goto after_38;
    // 0x800F92A4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_38:
    // 0x800F92A8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F92AC: lwc1        $f2, -0x70E4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X70E4);
    // 0x800F92B0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F92B4: mul.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F92B8: abs.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = fabsf(ctx->f20.fl);
    // 0x800F92BC: lwc1        $f0, 0x24($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X24);
    // 0x800F92C0: mul.s       $f4, $f0, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x800F92C4: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x800F92C8: nop

    // 0x800F92CC: bc1f        L_800F92F4
    if (!c1cs) {
        // 0x800F92D0: addiu       $s0, $sp, 0x50
        ctx->r16 = ADD32(ctx->r29, 0X50);
            goto L_800F92F4;
    }
    // 0x800F92D0: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
    // 0x800F92D4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F92D8: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800F92DC: nop

    // 0x800F92E0: bc1f        L_800F92EC
    if (!c1cs) {
        // 0x800F92E4: mov.s       $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = ctx->f4.fl;
            goto L_800F92EC;
    }
    // 0x800F92E4: mov.s       $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = ctx->f4.fl;
    // 0x800F92E8: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_800F92EC:
    // 0x800F92EC: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    // 0x800F92F0: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
L_800F92F4:
    // 0x800F92F4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F92F8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800F92FC: jal         0x8001D240
    // 0x800F9300: addiu       $a1, $s5, 0xC
    ctx->r5 = ADD32(ctx->r21, 0XC);
    quatFromAxisAngle(rdram, ctx);
        goto after_39;
    // 0x800F9300: addiu       $a1, $s5, 0xC
    ctx->r5 = ADD32(ctx->r21, 0XC);
    after_39:
    // 0x800F9304: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F9308: addiu       $a1, $s5, 0x18
    ctx->r5 = ADD32(ctx->r21, 0X18);
    // 0x800F930C: jal         0x8001D3C4
    // 0x800F9310: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    rotateVec3ByQuat(rdram, ctx);
        goto after_40;
    // 0x800F9310: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_40:
    // 0x800F9314: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800F9318: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800F931C: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800F9320: sw          $t1, 0x18($s5)
    MEM_W(0X18, ctx->r21) = ctx->r9;
    // 0x800F9324: sw          $t2, 0x1C($s5)
    MEM_W(0X1C, ctx->r21) = ctx->r10;
    // 0x800F9328: sw          $t3, 0x20($s5)
    MEM_W(0X20, ctx->r21) = ctx->r11;
L_800F932C:
    // 0x800F932C: lwc1        $f0, 0x4($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X4);
    // 0x800F9330: c.le.s      $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.fl <= ctx->f0.fl;
    // 0x800F9334: nop

    // 0x800F9338: bc1f        L_800F9368
    if (!c1cs) {
        // 0x800F933C: addiu       $a1, $zero, 0x9
        ctx->r5 = ADD32(0, 0X9);
            goto L_800F9368;
    }
    // 0x800F933C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
L_800F9340:
    // 0x800F9340: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_800F9344:
    // 0x800F9344: sb          $v0, 0x98($sp)
    MEM_B(0X98, ctx->r29) = ctx->r2;
    // 0x800F9348: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800F934C: sh          $v0, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r2;
    // 0x800F9350: sh          $v0, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r2;
    // 0x800F9354: lhu         $a0, 0x198($s7)
    ctx->r4 = MEM_HU(ctx->r23, 0X198);
    // 0x800F9358: jal         0x8003E8DC
    // 0x800F935C: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    slotDispatcherIter(rdram, ctx);
        goto after_41;
    // 0x800F935C: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    after_41:
    // 0x800F9360: j           L_800F942C
    // 0x800F9364: nop

        goto L_800F942C;
    // 0x800F9364: nop

L_800F9368:
    // 0x800F9368: lbu         $v0, 0x1A($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X1A);
    // 0x800F936C: bne         $v0, $zero, L_800F942C
    if (ctx->r2 != 0) {
        // 0x800F9370: ori         $s0, $zero, 0xFFFF
        ctx->r16 = 0 | 0XFFFF;
            goto L_800F942C;
    }
    // 0x800F9370: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    // 0x800F9374: lhu         $v0, 0xF0($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0XF0);
    // 0x800F9378: beq         $v0, $s0, L_800F942C
    if (ctx->r2 == ctx->r16) {
        // 0x800F937C: nop
    
            goto L_800F942C;
    }
    // 0x800F937C: nop

    // 0x800F9380: jal         0x8004013C
    // 0x800F9384: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    getNpcContextByIndex(rdram, ctx);
        goto after_42;
    // 0x800F9384: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_42:
    // 0x800F9388: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x800F938C: beq         $v0, $zero, L_800F9340
    if (ctx->r2 == 0) {
        // 0x800F9390: addiu       $a1, $zero, 0x9
        ctx->r5 = ADD32(0, 0X9);
            goto L_800F9340;
    }
    // 0x800F9390: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800F9394: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800F9398: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F939C: lwc1        $f0, -0x70E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X70E0);
    // 0x800F93A0: lwc1        $f2, 0x48($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X48);
    // 0x800F93A4: sub.s       $f22, $f0, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F93A8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F93AC: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x800F93B0: nop

    // 0x800F93B4: bc1f        L_800F9344
    if (!c1cs) {
        // 0x800F93B8: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_800F9344;
    }
    // 0x800F93B8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800F93BC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F93C0: lwc1        $f0, -0x70DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X70DC);
    // 0x800F93C4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F93C8: lwc1        $f2, -0x70D8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X70D8);
    // 0x800F93CC: mul.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800F93D0: sh          $s0, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = ctx->r16;
    // 0x800F93D4: sh          $s0, 0xA2($sp)
    MEM_H(0XA2, ctx->r29) = ctx->r16;
    // 0x800F93D8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800F93DC: nop

    // 0x800F93E0: bc1t        L_800F93F8
    if (c1cs) {
        // 0x800F93E4: sh          $zero, 0xA4($sp)
        MEM_H(0XA4, ctx->r29) = 0;
            goto L_800F93F8;
    }
    // 0x800F93E4: sh          $zero, 0xA4($sp)
    MEM_H(0XA4, ctx->r29) = 0;
    // 0x800F93E8: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F93EC: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800F93F0: j           L_800F9410
    // 0x800F93F4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
        goto L_800F9410;
    // 0x800F93F4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_800F93F8:
    // 0x800F93F8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F93FC: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F9400: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F9404: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800F9408: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800F940C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_800F9410:
    // 0x800F9410: sh          $v1, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r3;
    // 0x800F9414: sw          $zero, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = 0;
    // 0x800F9418: lhu         $a0, 0xF0($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0XF0);
    // 0x800F941C: jal         0x8003E8DC
    // 0x800F9420: addiu       $a2, $sp, 0xA0
    ctx->r6 = ADD32(ctx->r29, 0XA0);
    slotDispatcherIter(rdram, ctx);
        goto after_43;
    // 0x800F9420: addiu       $a2, $sp, 0xA0
    ctx->r6 = ADD32(ctx->r29, 0XA0);
    after_43:
    // 0x800F9424: j           L_800F9340
    // 0x800F9428: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
        goto L_800F9340;
    // 0x800F9428: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
L_800F942C:
    // 0x800F942C: lw          $ra, 0xE4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XE4);
    // 0x800F9430: lw          $fp, 0xE0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XE0);
    // 0x800F9434: lw          $s7, 0xDC($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XDC);
    // 0x800F9438: lw          $s6, 0xD8($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XD8);
    // 0x800F943C: lw          $s5, 0xD4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XD4);
    // 0x800F9440: lw          $s4, 0xD0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XD0);
    // 0x800F9444: lw          $s3, 0xCC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XCC);
    // 0x800F9448: lw          $s2, 0xC8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC8);
    // 0x800F944C: lw          $s1, 0xC4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC4);
    // 0x800F9450: lw          $s0, 0xC0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XC0);
    // 0x800F9454: ldc1        $f30, 0x110($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X110);
    // 0x800F9458: ldc1        $f28, 0x108($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X108);
    // 0x800F945C: ldc1        $f26, 0x100($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X100);
    // 0x800F9460: ldc1        $f24, 0xF8($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0XF8);
    // 0x800F9464: ldc1        $f22, 0xF0($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XF0);
    // 0x800F9468: ldc1        $f20, 0xE8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XE8);
    // 0x800F946C: jr          $ra
    // 0x800F9470: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    return;
    // 0x800F9470: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
;}
RECOMP_FUNC void clearObjectField112(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9474: jr          $ra
    // 0x800F9478: sb          $zero, 0x112($a0)
    MEM_B(0X112, ctx->r4) = 0;
    return;
    // 0x800F9478: sb          $zero, 0x112($a0)
    MEM_B(0X112, ctx->r4) = 0;
;}
RECOMP_FUNC void initActorAsType1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F947C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F9480: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x800F9484: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800F9488: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x800F948C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F9490: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800F9494: addiu       $s1, $t0, 0x8
    ctx->r17 = ADD32(ctx->r8, 0X8);
    // 0x800F9498: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800F949C: sb          $v0, 0x112($t0)
    MEM_B(0X112, ctx->r8) = ctx->r2;
    // 0x800F94A0: sw          $s0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r16;
    // 0x800F94A4: sw          $zero, 0x28($s1)
    MEM_W(0X28, ctx->r17) = 0;
    // 0x800F94A8: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x800F94AC: mtc1        $a2, $f2
    ctx->f2.u32l = ctx->r6;
    // 0x800F94B0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F94B4: lwc1        $f4, -0x70D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X70D4);
    // 0x800F94B8: sw          $v0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r2;
    // 0x800F94BC: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x800F94C0: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x800F94C4: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x800F94C8: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
    // 0x800F94CC: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    // 0x800F94D0: sw          $zero, 0x10($s1)
    MEM_W(0X10, ctx->r17) = 0;
    // 0x800F94D4: sw          $zero, 0xC($s1)
    MEM_W(0XC, ctx->r17) = 0;
    // 0x800F94D8: sw          $zero, 0x34($s1)
    MEM_W(0X34, ctx->r17) = 0;
    // 0x800F94DC: sw          $zero, 0x20($s1)
    MEM_W(0X20, ctx->r17) = 0;
    // 0x800F94E0: sw          $zero, 0x18($s1)
    MEM_W(0X18, ctx->r17) = 0;
    // 0x800F94E4: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x800F94E8: swc1        $f2, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f2.u32l;
    // 0x800F94EC: swc1        $f2, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f2.u32l;
    // 0x800F94F0: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x800F94F4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800F94F8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800F94FC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800F9500: sw          $v1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r3;
    // 0x800F9504: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800F9508: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x800F950C: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F9510: swc1        $f2, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f2.u32l;
    // 0x800F9514: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800F9518: mul.s       $f0, $f8, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800F951C: sw          $zero, 0x104($s1)
    MEM_W(0X104, ctx->r17) = 0;
    // 0x800F9520: sb          $zero, 0xFC($s1)
    MEM_B(0XFC, ctx->r17) = 0;
    // 0x800F9524: sb          $zero, 0xFE($s1)
    MEM_B(0XFE, ctx->r17) = 0;
    // 0x800F9528: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800F952C: nop

    // 0x800F9530: bc1f        L_800F953C
    if (!c1cs) {
        // 0x800F9534: swc1        $f0, 0x30($s1)
        MEM_W(0X30, ctx->r17) = ctx->f0.u32l;
            goto L_800F953C;
    }
    // 0x800F9534: swc1        $f0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f0.u32l;
    // 0x800F9538: sw          $zero, 0x30($s1)
    MEM_W(0X30, ctx->r17) = 0;
L_800F953C:
    // 0x800F953C: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x800F9540: beq         $v0, $zero, L_800F9558
    if (ctx->r2 == 0) {
        // 0x800F9544: nop
    
            goto L_800F9558;
    }
    // 0x800F9544: nop

    // 0x800F9548: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
    // 0x800F954C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800F9550: j           L_800F9564
    // 0x800F9554: swc1        $f0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f0.u32l;
        goto L_800F9564;
    // 0x800F9554: swc1        $f0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f0.u32l;
L_800F9558:
    // 0x800F9558: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F955C: lwc1        $f0, -0x70D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X70D0);
    // 0x800F9560: swc1        $f0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f0.u32l;
L_800F9564:
    // 0x800F9564: sw          $zero, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = 0;
    // 0x800F9568: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800F956C: sw          $zero, 0x38($s1)
    MEM_W(0X38, ctx->r17) = 0;
    // 0x800F9570: swc1        $f0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f0.u32l;
    // 0x800F9574: lhu         $a0, 0x198($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X198);
    // 0x800F9578: jal         0x8004015C
    // 0x800F957C: nop

    getNpcContextField8(rdram, ctx);
        goto after_0;
    // 0x800F957C: nop

    after_0:
    // 0x800F9580: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F9584: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    // 0x800F9588: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800F958C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800F9590: lwc1        $f0, 0x30($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X30);
    // 0x800F9594: addiu       $a3, $s1, 0xC
    ctx->r7 = ADD32(ctx->r17, 0XC);
    // 0x800F9598: jal         0x800662A0
    // 0x800F959C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    setupActorAnchorTransformType1(rdram, ctx);
        goto after_1;
    // 0x800F959C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800F95A0: addiu       $a0, $s1, 0xBC
    ctx->r4 = ADD32(ctx->r17, 0XBC);
    // 0x800F95A4: sw          $zero, 0xA8($s1)
    MEM_W(0XA8, ctx->r17) = 0;
    // 0x800F95A8: lw          $a2, 0xA8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XA8);
    // 0x800F95AC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F95B0: lwc1        $f2, -0x70CC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X70CC);
    // 0x800F95B4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F95B8: lwc1        $f4, -0x70C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X70C8);
    // 0x800F95BC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F95C0: lwc1        $f6, -0x70C4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X70C4);
    // 0x800F95C4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F95C8: lwc1        $f0, -0x70C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X70C0);
    // 0x800F95CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800F95D0: sw          $zero, 0x60($s1)
    MEM_W(0X60, ctx->r17) = 0;
    // 0x800F95D4: sw          $zero, 0x64($s1)
    MEM_W(0X64, ctx->r17) = 0;
    // 0x800F95D8: sw          $zero, 0x68($s1)
    MEM_W(0X68, ctx->r17) = 0;
    // 0x800F95DC: sw          $zero, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = 0;
    // 0x800F95E0: sw          $zero, 0x88($s1)
    MEM_W(0X88, ctx->r17) = 0;
    // 0x800F95E4: sw          $zero, 0x98($s1)
    MEM_W(0X98, ctx->r17) = 0;
    // 0x800F95E8: sw          $zero, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = 0;
    // 0x800F95EC: sw          $zero, 0xA0($s1)
    MEM_W(0XA0, ctx->r17) = 0;
    // 0x800F95F0: sw          $zero, 0x90($s1)
    MEM_W(0X90, ctx->r17) = 0;
    // 0x800F95F4: swc1        $f2, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f2.u32l;
    // 0x800F95F8: swc1        $f4, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f4.u32l;
    // 0x800F95FC: swc1        $f6, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->f6.u32l;
    // 0x800F9600: swc1        $f0, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->f0.u32l;
    // 0x800F9604: jal         0x8001D038
    // 0x800F9608: swc1        $f0, 0x84($s1)
    MEM_W(0X84, ctx->r17) = ctx->f0.u32l;
    quatFromCardinalAxis(rdram, ctx);
        goto after_2;
    // 0x800F9608: swc1        $f0, 0x84($s1)
    MEM_W(0X84, ctx->r17) = ctx->f0.u32l;
    after_2:
    // 0x800F960C: sw          $zero, 0xB0($s1)
    MEM_W(0XB0, ctx->r17) = 0;
    // 0x800F9610: sw          $zero, 0xB4($s1)
    MEM_W(0XB4, ctx->r17) = 0;
    // 0x800F9614: sw          $zero, 0xB8($s1)
    MEM_W(0XB8, ctx->r17) = 0;
    // 0x800F9618: sw          $zero, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = 0;
    // 0x800F961C: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800F9620: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F9624: lwc1        $f2, -0x70BC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X70BC);
    // 0x800F9628: swc1        $f0, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f0.u32l;
    // 0x800F962C: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800F9630: swc1        $f2, 0xCC($s1)
    MEM_W(0XCC, ctx->r17) = ctx->f2.u32l;
    // 0x800F9634: swc1        $f0, 0xE0($s1)
    MEM_W(0XE0, ctx->r17) = ctx->f0.u32l;
    // 0x800F9638: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x800F963C: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x800F9640: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    // 0x800F9644: sw          $t1, 0xD0($s1)
    MEM_W(0XD0, ctx->r17) = ctx->r9;
    // 0x800F9648: sw          $t2, 0xD4($s1)
    MEM_W(0XD4, ctx->r17) = ctx->r10;
    // 0x800F964C: sw          $t3, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->r11;
    // 0x800F9650: sw          $zero, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = 0;
    // 0x800F9654: sw          $zero, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = 0;
    // 0x800F9658: sw          $zero, 0xF8($s1)
    MEM_W(0XF8, ctx->r17) = 0;
    // 0x800F965C: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800F9660: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800F9664: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800F9668: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F966C: jr          $ra
    // 0x800F9670: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800F9670: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void initActorAsType1WithAnchor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9674: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F9678: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x800F967C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800F9680: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800F9684: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F9688: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800F968C: addiu       $s0, $t0, 0x8
    ctx->r16 = ADD32(ctx->r8, 0X8);
    // 0x800F9690: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800F9694: sb          $v0, 0x112($t0)
    MEM_B(0X112, ctx->r8) = ctx->r2;
    // 0x800F9698: sw          $s1, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r17;
    // 0x800F969C: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x800F96A0: lw          $v0, 0x1C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1C);
    // 0x800F96A4: mtc1        $a2, $f2
    ctx->f2.u32l = ctx->r6;
    // 0x800F96A8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F96AC: lwc1        $f4, -0x70B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X70B8);
    // 0x800F96B0: sw          $v0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r2;
    // 0x800F96B4: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    // 0x800F96B8: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x800F96BC: lw          $a0, 0x1C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X1C);
    // 0x800F96C0: lw          $v1, 0x20($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X20);
    // 0x800F96C4: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x800F96C8: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x800F96CC: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x800F96D0: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x800F96D4: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x800F96D8: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x800F96DC: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    // 0x800F96E0: swc1        $f2, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f2.u32l;
    // 0x800F96E4: swc1        $f2, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f2.u32l;
    // 0x800F96E8: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x800F96EC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800F96F0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800F96F4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800F96F8: sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    // 0x800F96FC: lwc1        $f0, 0x24($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800F9700: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x800F9704: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F9708: swc1        $f2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f2.u32l;
    // 0x800F970C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800F9710: mul.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800F9714: sw          $zero, 0x104($s0)
    MEM_W(0X104, ctx->r16) = 0;
    // 0x800F9718: sb          $zero, 0xFC($s0)
    MEM_B(0XFC, ctx->r16) = 0;
    // 0x800F971C: sb          $zero, 0xFE($s0)
    MEM_B(0XFE, ctx->r16) = 0;
    // 0x800F9720: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800F9724: nop

    // 0x800F9728: bc1f        L_800F9734
    if (!c1cs) {
        // 0x800F972C: swc1        $f0, 0x30($s0)
        MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
            goto L_800F9734;
    }
    // 0x800F972C: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x800F9730: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
L_800F9734:
    // 0x800F9734: lw          $v0, 0x28($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X28);
    // 0x800F9738: beq         $v0, $zero, L_800F9750
    if (ctx->r2 == 0) {
        // 0x800F973C: nop
    
            goto L_800F9750;
    }
    // 0x800F973C: nop

    // 0x800F9740: lw          $v0, 0x2C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X2C);
    // 0x800F9744: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800F9748: j           L_800F975C
    // 0x800F974C: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
        goto L_800F975C;
    // 0x800F974C: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
L_800F9750:
    // 0x800F9750: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F9754: lwc1        $f0, -0x70B4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X70B4);
    // 0x800F9758: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
L_800F975C:
    // 0x800F975C: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x800F9760: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800F9764: sw          $zero, 0x38($s0)
    MEM_W(0X38, ctx->r16) = 0;
    // 0x800F9768: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x800F976C: lhu         $a0, 0x198($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X198);
    // 0x800F9770: jal         0x8004015C
    // 0x800F9774: nop

    getNpcContextField8(rdram, ctx);
        goto after_0;
    // 0x800F9774: nop

    after_0:
    // 0x800F9778: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F977C: addiu       $a1, $s1, 0x10
    ctx->r5 = ADD32(ctx->r17, 0X10);
    // 0x800F9780: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x800F9784: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800F9788: addiu       $a3, $s0, 0xC
    ctx->r7 = ADD32(ctx->r16, 0XC);
    // 0x800F978C: jal         0x800662A0
    // 0x800F9790: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    setupActorAnchorTransformType1(rdram, ctx);
        goto after_1;
    // 0x800F9790: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800F9794: sw          $zero, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = 0;
    // 0x800F9798: sw          $zero, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = 0;
    // 0x800F979C: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800F97A0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800F97A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800F97A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F97AC: jr          $ra
    // 0x800F97B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800F97B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void setType1ActorVelocity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F97B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F97B8: mtc1        $a1, $f2
    ctx->f2.u32l = ctx->r5;
    // 0x800F97BC: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x800F97C0: lbu         $v1, 0x112($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X112);
    // 0x800F97C4: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x800F97C8: beq         $v1, $v0, L_800F97D8
    if (ctx->r3 == ctx->r2) {
        // 0x800F97CC: addiu       $v1, $a0, 0x8
        ctx->r3 = ADD32(ctx->r4, 0X8);
            goto L_800F97D8;
    }
    // 0x800F97CC: addiu       $v1, $a0, 0x8
    ctx->r3 = ADD32(ctx->r4, 0X8);
    // 0x800F97D0: jr          $ra
    // 0x800F97D4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800F97D4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F97D8:
    // 0x800F97D8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F97DC: lwc1        $f0, -0x70B0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X70B0);
    // 0x800F97E0: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F97E4: swc1        $f4, 0x7C($v1)
    MEM_W(0X7C, ctx->r3) = ctx->f4.u32l;
    // 0x800F97E8: swc1        $f6, 0xCC($v1)
    MEM_W(0XCC, ctx->r3) = ctx->f6.u32l;
    // 0x800F97EC: jr          $ra
    // 0x800F97F0: swc1        $f0, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->f0.u32l;
    return;
    // 0x800F97F0: swc1        $f0, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->f0.u32l;
;}
RECOMP_FUNC void setType1ActorField40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F97F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F97F8: mtc1        $a1, $f2
    ctx->f2.u32l = ctx->r5;
    // 0x800F97FC: lbu         $v1, 0x112($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X112);
    // 0x800F9800: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F9804: bne         $v1, $v0, L_800F9814
    if (ctx->r3 != ctx->r2) {
        // 0x800F9808: nop
    
            goto L_800F9814;
    }
    // 0x800F9808: nop

    // 0x800F980C: lwc1        $f0, 0x40($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X40);
    // 0x800F9810: swc1        $f2, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f2.u32l;
L_800F9814:
    // 0x800F9814: jr          $ra
    // 0x800F9818: nop

    return;
    // 0x800F9818: nop

;}
RECOMP_FUNC void initActorAsType2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F981C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F9820: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800F9824: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x800F9828: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800F982C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800F9830: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800F9834: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x800F9838: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800F983C: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x800F9840: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800F9844: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F9848: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800F984C: lhu         $a0, 0x198($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X198);
    // 0x800F9850: addiu       $s0, $s1, 0x8
    ctx->r16 = ADD32(ctx->r17, 0X8);
    // 0x800F9854: jal         0x8004015C
    // 0x800F9858: sb          $v0, 0x112($s1)
    MEM_B(0X112, ctx->r17) = ctx->r2;
    getNpcContextField8(rdram, ctx);
        goto after_0;
    // 0x800F9858: sb          $v0, 0x112($s1)
    MEM_B(0X112, ctx->r17) = ctx->r2;
    after_0:
    // 0x800F985C: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800F9860: lw          $t0, 0x10($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X10);
    // 0x800F9864: lw          $t1, 0x14($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X14);
    // 0x800F9868: sw          $v1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r3;
    // 0x800F986C: sw          $t0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r8;
    // 0x800F9870: sw          $t1, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r9;
    // 0x800F9874: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x800F9878: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800F987C: swc1        $f20, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f20.u32l;
    // 0x800F9880: swc1        $f20, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f20.u32l;
    // 0x800F9884: swc1        $f22, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f22.u32l;
    // 0x800F9888: sw          $s2, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r18;
    // 0x800F988C: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
    // 0x800F9890: sb          $zero, 0x34($s0)
    MEM_B(0X34, ctx->r16) = 0;
    // 0x800F9894: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x800F9898: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x800F989C: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x800F98A0: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x800F98A4: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x800F98A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F98AC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800F98B0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800F98B4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800F98B8: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800F98BC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800F98C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F98C4: jr          $ra
    // 0x800F98C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800F98C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void setType2ActorVelocity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F98CC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800F98D0: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x800F98D4: mtc1        $a2, $f2
    ctx->f2.u32l = ctx->r6;
    // 0x800F98D8: lbu         $v0, 0x112($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X112);
    // 0x800F98DC: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x800F98E0: beq         $v0, $v1, L_800F98F0
    if (ctx->r2 == ctx->r3) {
        // 0x800F98E4: addiu       $v1, $a0, 0x8
        ctx->r3 = ADD32(ctx->r4, 0X8);
            goto L_800F98F0;
    }
    // 0x800F98E4: addiu       $v1, $a0, 0x8
    ctx->r3 = ADD32(ctx->r4, 0X8);
    // 0x800F98E8: jr          $ra
    // 0x800F98EC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800F98EC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F98F0:
    // 0x800F98F0: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x800F98F4: swc1        $f0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f0.u32l;
    // 0x800F98F8: swc1        $f2, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f2.u32l;
    // 0x800F98FC: swc1        $f4, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f4.u32l;
    // 0x800F9900: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F9904: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    // 0x800F9908: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800F990C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F9910: jr          $ra
    // 0x800F9914: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
    return;
    // 0x800F9914: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
;}
RECOMP_FUNC void initActorAsType3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9918: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F991C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800F9920: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x800F9924: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800F9928: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800F992C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800F9930: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x800F9934: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800F9938: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x800F993C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800F9940: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F9944: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800F9948: lhu         $a0, 0x198($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X198);
    // 0x800F994C: addiu       $s0, $s1, 0x8
    ctx->r16 = ADD32(ctx->r17, 0X8);
    // 0x800F9950: jal         0x8004015C
    // 0x800F9954: sb          $v0, 0x112($s1)
    MEM_B(0X112, ctx->r17) = ctx->r2;
    getNpcContextField8(rdram, ctx);
        goto after_0;
    // 0x800F9954: sb          $v0, 0x112($s1)
    MEM_B(0X112, ctx->r17) = ctx->r2;
    after_0:
    // 0x800F9958: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800F995C: lw          $t0, 0x10($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X10);
    // 0x800F9960: lw          $t1, 0x14($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X14);
    // 0x800F9964: sw          $v1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r3;
    // 0x800F9968: sw          $t0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r8;
    // 0x800F996C: sw          $t1, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r9;
    // 0x800F9970: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x800F9974: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800F9978: swc1        $f20, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f20.u32l;
    // 0x800F997C: swc1        $f20, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f20.u32l;
    // 0x800F9980: swc1        $f22, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f22.u32l;
    // 0x800F9984: sw          $s2, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r18;
    // 0x800F9988: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
    // 0x800F998C: sb          $zero, 0x34($s0)
    MEM_B(0X34, ctx->r16) = 0;
    // 0x800F9990: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x800F9994: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x800F9998: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x800F999C: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x800F99A0: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x800F99A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F99A8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800F99AC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800F99B0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800F99B4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800F99B8: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800F99BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F99C0: jr          $ra
    // 0x800F99C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800F99C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void setType3ActorParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F99C8: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x800F99CC: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x800F99D0: mtc1        $a2, $f2
    ctx->f2.u32l = ctx->r6;
    // 0x800F99D4: lbu         $v0, 0x112($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X112);
    // 0x800F99D8: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x800F99DC: beq         $v0, $v1, L_800F99EC
    if (ctx->r2 == ctx->r3) {
        // 0x800F99E0: addiu       $v1, $a0, 0x8
        ctx->r3 = ADD32(ctx->r4, 0X8);
            goto L_800F99EC;
    }
    // 0x800F99E0: addiu       $v1, $a0, 0x8
    ctx->r3 = ADD32(ctx->r4, 0X8);
    // 0x800F99E4: jr          $ra
    // 0x800F99E8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800F99E8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F99EC:
    // 0x800F99EC: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x800F99F0: swc1        $f0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f0.u32l;
    // 0x800F99F4: swc1        $f2, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f2.u32l;
    // 0x800F99F8: swc1        $f4, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f4.u32l;
    // 0x800F99FC: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F9A00: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    // 0x800F9A04: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800F9A08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F9A0C: jr          $ra
    // 0x800F9A10: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
    return;
    // 0x800F9A10: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
;}
RECOMP_FUNC void dispatchEffectByActorType(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9A14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F9A18: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800F9A1C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800F9A20: lbu         $v1, 0x112($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X112);
    // 0x800F9A24: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x800F9A28: beq         $v1, $v0, L_800F9A78
    if (ctx->r3 == ctx->r2) {
        // 0x800F9A2C: slti        $v0, $v1, 0x3
        ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_800F9A78;
    }
    // 0x800F9A2C: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800F9A30: beq         $v0, $zero, L_800F9A48
    if (ctx->r2 == 0) {
        // 0x800F9A34: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F9A48;
    }
    // 0x800F9A34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F9A38: beq         $v1, $v0, L_800F9A64
    if (ctx->r3 == ctx->r2) {
        // 0x800F9A3C: nop
    
            goto L_800F9A64;
    }
    // 0x800F9A3C: nop

    // 0x800F9A40: j           L_800F9AAC
    // 0x800F9A44: nop

        goto L_800F9AAC;
    // 0x800F9A44: nop

L_800F9A48:
    // 0x800F9A48: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800F9A4C: beq         $v1, $v0, L_800F9A8C
    if (ctx->r3 == ctx->r2) {
        // 0x800F9A50: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800F9A8C;
    }
    // 0x800F9A50: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800F9A54: beq         $v1, $v0, L_800F9AA0
    if (ctx->r3 == ctx->r2) {
        // 0x800F9A58: nop
    
            goto L_800F9AA0;
    }
    // 0x800F9A58: nop

    // 0x800F9A5C: j           L_800F9AAC
    // 0x800F9A60: nop

        goto L_800F9AAC;
    // 0x800F9A60: nop

L_800F9A64:
    // 0x800F9A64: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800F9A68: jal         0x800F410C
    // 0x800F9A6C: nop

    executeActorType1Effect(rdram, ctx);
        goto after_0;
    // 0x800F9A6C: nop

    after_0:
    // 0x800F9A70: j           L_800F9AAC
    // 0x800F9A74: nop

        goto L_800F9AAC;
    // 0x800F9A74: nop

L_800F9A78:
    // 0x800F9A78: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800F9A7C: jal         0x800F4E74
    // 0x800F9A80: nop

    executeActorType2Effect(rdram, ctx);
        goto after_1;
    // 0x800F9A80: nop

    after_1:
    // 0x800F9A84: j           L_800F9AAC
    // 0x800F9A88: nop

        goto L_800F9AAC;
    // 0x800F9A88: nop

L_800F9A8C:
    // 0x800F9A8C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800F9A90: jal         0x800F538C
    // 0x800F9A94: nop

    executeActorType3Effect(rdram, ctx);
        goto after_2;
    // 0x800F9A94: nop

    after_2:
    // 0x800F9A98: j           L_800F9AAC
    // 0x800F9A9C: nop

        goto L_800F9AAC;
    // 0x800F9A9C: nop

L_800F9AA0:
    // 0x800F9AA0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800F9AA4: jal         0x800F8398
    // 0x800F9AA8: nop

    executeActorType4Effect(rdram, ctx);
        goto after_3;
    // 0x800F9AA8: nop

    after_3:
L_800F9AAC:
    // 0x800F9AAC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800F9AB0: jr          $ra
    // 0x800F9AB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F9AB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void setType1ActorParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9AB8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800F9ABC: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x800F9AC0: lbu         $v0, 0x112($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X112);
    // 0x800F9AC4: lw          $a1, 0x10($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X10);
    // 0x800F9AC8: beql        $v0, $v1, L_800F9AD8
    if (ctx->r2 == ctx->r3) {
        // 0x800F9ACC: swc1        $f0, 0x10C($a0)
        MEM_W(0X10C, ctx->r4) = ctx->f0.u32l;
            goto L_800F9AD8;
    }
    goto skip_0;
    // 0x800F9ACC: swc1        $f0, 0x10C($a0)
    MEM_W(0X10C, ctx->r4) = ctx->f0.u32l;
    skip_0:
    // 0x800F9AD0: jr          $ra
    // 0x800F9AD4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800F9AD4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F9AD8:
    // 0x800F9AD8: sb          $a2, 0x104($a0)
    MEM_B(0X104, ctx->r4) = ctx->r6;
    // 0x800F9ADC: sb          $a3, 0x105($a0)
    MEM_B(0X105, ctx->r4) = ctx->r7;
    // 0x800F9AE0: sb          $a1, 0x106($a0)
    MEM_B(0X106, ctx->r4) = ctx->r5;
    // 0x800F9AE4: lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X14);
    // 0x800F9AE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F9AEC: jr          $ra
    // 0x800F9AF0: sw          $v1, 0x108($a0)
    MEM_W(0X108, ctx->r4) = ctx->r3;
    return;
    // 0x800F9AF0: sw          $v1, 0x108($a0)
    MEM_W(0X108, ctx->r4) = ctx->r3;
;}
RECOMP_FUNC void updateObjectFlags110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9AF4: lhu         $v0, 0x110($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X110);
    // 0x800F9AF8: nor         $a2, $zero, $a2
    ctx->r6 = ~(0 | ctx->r6);
    // 0x800F9AFC: or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // 0x800F9B00: and         $v0, $v0, $a2
    ctx->r2 = ctx->r2 & ctx->r6;
    // 0x800F9B04: jr          $ra
    // 0x800F9B08: sh          $v0, 0x110($a0)
    MEM_H(0X110, ctx->r4) = ctx->r2;
    return;
    // 0x800F9B08: sh          $v0, 0x110($a0)
    MEM_H(0X110, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void resetType1FxFields(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9B0C: lbu         $v1, 0x112($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X112);
    // 0x800F9B10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F9B14: bne         $v1, $v0, L_800F9B2C
    if (ctx->r3 != ctx->r2) {
        // 0x800F9B18: nop
    
            goto L_800F9B2C;
    }
    // 0x800F9B18: nop

    // 0x800F9B1C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F9B20: lwc1        $f0, -0x70AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X70AC);
    // 0x800F9B24: sw          $zero, 0xFC($a0)
    MEM_W(0XFC, ctx->r4) = 0;
    // 0x800F9B28: swc1        $f0, 0x100($a0)
    MEM_W(0X100, ctx->r4) = ctx->f0.u32l;
L_800F9B2C:
    // 0x800F9B2C: jr          $ra
    // 0x800F9B30: nop

    return;
    // 0x800F9B30: nop

;}
RECOMP_FUNC void updateType1AnimRamp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9B34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F9B38: mtc1        $a1, $f2
    ctx->f2.u32l = ctx->r5;
    // 0x800F9B3C: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x800F9B40: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x800F9B44: lbu         $v1, 0x112($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X112);
    // 0x800F9B48: lbu         $a1, 0x13($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X13);
    // 0x800F9B4C: bne         $v1, $v0, L_800F9BE4
    if (ctx->r3 != ctx->r2) {
        // 0x800F9B50: nop
    
            goto L_800F9BE4;
    }
    // 0x800F9B50: nop

    // 0x800F9B54: bne         $a1, $v1, L_800F9B6C
    if (ctx->r5 != ctx->r3) {
        // 0x800F9B58: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_800F9B6C;
    }
    // 0x800F9B58: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800F9B5C: lwc1        $f0, 0x48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800F9B60: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F9B64: j           L_800F9B70
    // 0x800F9B68: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
        goto L_800F9B70;
    // 0x800F9B68: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
L_800F9B6C:
    // 0x800F9B6C: swc1        $f2, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f2.u32l;
L_800F9B70:
    // 0x800F9B70: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800F9B74: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800F9B78: nop

    // 0x800F9B7C: bc1tl       L_800F9B84
    if (c1cs) {
        // 0x800F9B80: swc1        $f4, 0x50($a0)
        MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
            goto L_800F9B84;
    }
    goto skip_0;
    // 0x800F9B80: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    skip_0:
L_800F9B84:
    // 0x800F9B84: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800F9B88: lwc1        $f2, 0x48($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800F9B8C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800F9B90: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F9B94: swc1        $f2, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f2.u32l;
    // 0x800F9B98: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800F9B9C: nop

    // 0x800F9BA0: bc1t        L_800F9BE4
    if (c1cs) {
        // 0x800F9BA4: swc1        $f0, 0x54($a0)
        MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
            goto L_800F9BE4;
    }
    // 0x800F9BA4: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    // 0x800F9BA8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800F9BAC: nop

    // 0x800F9BB0: bc1f        L_800F9BCC
    if (!c1cs) {
        // 0x800F9BB4: swc1        $f4, 0x58($a0)
        MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
            goto L_800F9BCC;
    }
    // 0x800F9BB4: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    // 0x800F9BB8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F9BBC: lwc1        $f0, -0x70A8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X70A8);
    // 0x800F9BC0: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800F9BC4: jr          $ra
    // 0x800F9BC8: swc1        $f0, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x800F9BC8: swc1        $f0, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f0.u32l;
L_800F9BCC:
    // 0x800F9BCC: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800F9BD0: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x800F9BD4: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    // 0x800F9BD8: lwc1        $f2, 0x24($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800F9BDC: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F9BE0: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
L_800F9BE4:
    // 0x800F9BE4: jr          $ra
    // 0x800F9BE8: nop

    return;
    // 0x800F9BE8: nop

;}
RECOMP_FUNC void getActorCurrentValueByType(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9BEC: lbu         $v1, 0x112($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X112);
    // 0x800F9BF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F9BF4: beq         $v1, $v0, L_800F9C0C
    if (ctx->r3 == ctx->r2) {
        // 0x800F9BF8: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800F9C0C;
    }
    // 0x800F9BF8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800F9BFC: beq         $v1, $v0, L_800F9C18
    if (ctx->r3 == ctx->r2) {
        // 0x800F9C00: nop
    
            goto L_800F9C18;
    }
    // 0x800F9C00: nop

    // 0x800F9C04: j           L_800F9C24
    // 0x800F9C08: nop

        goto L_800F9C24;
    // 0x800F9C08: nop

L_800F9C0C:
    // 0x800F9C0C: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800F9C10: jr          $ra
    // 0x800F9C14: nop

    return;
    // 0x800F9C14: nop

L_800F9C18:
    // 0x800F9C18: lwc1        $f0, 0x28($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800F9C1C: jr          $ra
    // 0x800F9C20: nop

    return;
    // 0x800F9C20: nop

L_800F9C24:
    // 0x800F9C24: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F9C28: jr          $ra
    // 0x800F9C2C: nop

    return;
    // 0x800F9C2C: nop

;}
RECOMP_FUNC void syncType1ActorFrameToAnchorIfZeroGate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9C30: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800F9C34: sw          $s2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r18;
    // 0x800F9C38: sw          $ra, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r31;
    // 0x800F9C3C: sw          $s1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r17;
    // 0x800F9C40: sw          $s0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r16;
    // 0x800F9C44: sdc1        $f22, 0x98($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X98, ctx->r29);
    // 0x800F9C48: sdc1        $f20, 0x90($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X90, ctx->r29);
    // 0x800F9C4C: lbu         $v1, 0x112($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X112);
    // 0x800F9C50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F9C54: bne         $v1, $v0, L_800F9D48
    if (ctx->r3 != ctx->r2) {
        // 0x800F9C58: addu        $s2, $a1, $zero
        ctx->r18 = ADD32(ctx->r5, 0);
            goto L_800F9D48;
    }
    // 0x800F9C58: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x800F9C5C: addiu       $s1, $a0, 0x8
    ctx->r17 = ADD32(ctx->r4, 0X8);
    // 0x800F9C60: lwc1        $f0, 0xE8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x800F9C64: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800F9C68: c.eq.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl == ctx->f22.fl;
    // 0x800F9C6C: nop

    // 0x800F9C70: bc1f        L_800F9D48
    if (!c1cs) {
        // 0x800F9C74: nop
    
            goto L_800F9D48;
    }
    // 0x800F9C74: nop

    // 0x800F9C78: lhu         $a0, 0x198($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X198);
    // 0x800F9C7C: jal         0x8004015C
    // 0x800F9C80: nop

    getNpcContextField8(rdram, ctx);
        goto after_0;
    // 0x800F9C80: nop

    after_0:
    // 0x800F9C84: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800F9C88: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800F9C8C: jal         0x80059B50
    // 0x800F9C90: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    mat34CrossRowsAndCopyPos(rdram, ctx);
        goto after_1;
    // 0x800F9C90: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_1:
    // 0x800F9C94: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x800F9C98: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F9C9C: jal         0x8001C774
    // 0x800F9CA0: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    mat3x3InverseInto(rdram, ctx);
        goto after_2;
    // 0x800F9CA0: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_2:
    // 0x800F9CA4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F9CA8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800F9CAC: addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // 0x800F9CB0: jal         0x800194A4
    // 0x800F9CB4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    rotateVec3ByMat3x3(rdram, ctx);
        goto after_3;
    // 0x800F9CB4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_3:
    // 0x800F9CB8: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800F9CBC: c.eq.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl == ctx->f22.fl;
    // 0x800F9CC0: nop

    // 0x800F9CC4: bc1f        L_800F9CE0
    if (!c1cs) {
        // 0x800F9CC8: nop
    
            goto L_800F9CE0;
    }
    // 0x800F9CC8: nop

    // 0x800F9CCC: lwc1        $f0, 0x74($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800F9CD0: c.eq.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl == ctx->f22.fl;
    // 0x800F9CD4: nop

    // 0x800F9CD8: bc1t        L_800F9D48
    if (c1cs) {
        // 0x800F9CDC: nop
    
            goto L_800F9D48;
    }
    // 0x800F9CDC: nop

L_800F9CE0:
    // 0x800F9CE0: jal         0x8001CF58
    // 0x800F9CE4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    normalize_vector(rdram, ctx);
        goto after_4;
    // 0x800F9CE4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x800F9CE8: lwc1        $f12, 0x70($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800F9CEC: lwc1        $f14, 0x74($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800F9CF0: jal         0x8001C5F4
    // 0x800F9CF4: nop

    func_8001C5F4(rdram, ctx);
        goto after_5;
    // 0x800F9CF4: nop

    after_5:
    // 0x800F9CF8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800F9CFC: jal         0x80033960
    // 0x800F9D00: add.s       $f12, $f20, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f20.fl + ctx->f20.fl;
    sinf_recomp(rdram, ctx);
        goto after_6;
    // 0x800F9D00: add.s       $f12, $f20, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f20.fl + ctx->f20.fl;
    after_6:
    // 0x800F9D04: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F9D08: lwc1        $f2, -0x70A4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X70A4);
    // 0x800F9D0C: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x800F9D10: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F9D14: lwc1        $f2, -0x70A0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X70A0);
    // 0x800F9D18: swc1        $f20, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->f20.u32l;
    // 0x800F9D1C: mul.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F9D20: jal         0x8001CF2C
    // 0x800F9D24: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    vec3Length(rdram, ctx);
        goto after_7;
    // 0x800F9D24: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_7:
    // 0x800F9D28: swc1        $f0, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f0.u32l;
    // 0x800F9D2C: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800F9D30: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F9D34: lwc1        $f2, -0x709C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X709C);
    // 0x800F9D38: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x800F9D3C: swc1        $f22, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->f22.u32l;
    // 0x800F9D40: swc1        $f2, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->f2.u32l;
    // 0x800F9D44: swc1        $f0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f0.u32l;
L_800F9D48:
    // 0x800F9D48: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
    // 0x800F9D4C: lw          $s2, 0x88($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X88);
    // 0x800F9D50: lw          $s1, 0x84($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X84);
    // 0x800F9D54: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
    // 0x800F9D58: ldc1        $f22, 0x98($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X98);
    // 0x800F9D5C: ldc1        $f20, 0x90($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X90);
    // 0x800F9D60: jr          $ra
    // 0x800F9D64: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x800F9D64: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_800F9D68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9D68: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800F9D6C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800F9D70: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800F9D74: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800F9D78: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x800F9D7C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800F9D80: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800F9D84: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800F9D88: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800F9D8C: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x800F9D90: lhu         $a0, 0x198($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X198);
    // 0x800F9D94: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x800F9D98: jal         0x8004015C
    // 0x800F9D9C: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    getNpcContextField8(rdram, ctx);
        goto after_0;
    // 0x800F9D9C: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    after_0:
    // 0x800F9DA0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800F9DA4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800F9DA8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800F9DAC: lhu         $a1, 0x198($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X198);
    // 0x800F9DB0: lhu         $v0, -0x6A84($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6A84);
    // 0x800F9DB4: ori         $a3, $zero, 0xFFFF
    ctx->r7 = 0 | 0XFFFF;
    // 0x800F9DB8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800F9DBC: jal         0x8005EA9C
    // 0x800F9DC0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_8005EA9C(rdram, ctx);
        goto after_1;
    // 0x800F9DC0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x800F9DC4: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x800F9DC8: ori         $s1, $zero, 0xFFFF
    ctx->r17 = 0 | 0XFFFF;
    // 0x800F9DCC: beq         $s0, $s1, L_800F9E18
    if (ctx->r16 == ctx->r17) {
        // 0x800F9DD0: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800F9E18;
    }
    // 0x800F9DD0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F9DD4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800F9DD8: lhu         $v0, 0x198($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X198);
    // 0x800F9DDC: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x800F9DE0: jal         0x8003E8DC
    // 0x800F9DE4: sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    slotDispatcherIter(rdram, ctx);
        goto after_2;
    // 0x800F9DE4: sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    after_2:
    // 0x800F9DE8: beq         $s4, $zero, L_800F9E14
    if (ctx->r20 == 0) {
        // 0x800F9DEC: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800F9E14;
    }
    // 0x800F9DEC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F9DF0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800F9DF4: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x800F9DF8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800F9DFC: sh          $s1, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r17;
    // 0x800F9E00: sh          $s1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r17;
    // 0x800F9E04: sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    // 0x800F9E08: sh          $s4, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r20;
    // 0x800F9E0C: jal         0x8003E8DC
    // 0x800F9E10: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    slotDispatcherIter(rdram, ctx);
        goto after_3;
    // 0x800F9E10: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_3:
L_800F9E14:
    // 0x800F9E14: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_800F9E18:
    // 0x800F9E18: addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
    // 0x800F9E1C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800F9E20: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800F9E24: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800F9E28: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800F9E2C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800F9E30: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800F9E34: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x800F9E38: jr          $ra
    // 0x800F9E3C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800F9E3C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void load_model_animation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9E40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F9E44: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800F9E48: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x800F9E4C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800F9E50: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800F9E54: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800F9E58: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x800F9E5C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800F9E60: addiu       $v0, $v0, -0x3B60
    ctx->r2 = ADD32(ctx->r2, -0X3B60);
    // 0x800F9E64: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800F9E68: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800F9E6C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800F9E70: addiu       $s2, $s0, 0x4
    ctx->r18 = ADD32(ctx->r16, 0X4);
    // 0x800F9E74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
L_800F9E78:
    // 0x800F9E78: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800F9E7C: beq         $v0, $zero, L_800F9EA0
    if (ctx->r2 == 0) {
        // 0x800F9E80: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_800F9EA0;
    }
    // 0x800F9E80: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F9E84: jal         0x800076F8
    // 0x800F9E88: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    rs_strcmp(rdram, ctx);
        goto after_0;
    // 0x800F9E88: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_0:
    // 0x800F9E8C: bnel        $v0, $zero, L_800F9EA8
    if (ctx->r2 != 0) {
        // 0x800F9E90: addiu       $s0, $s0, 0x24
        ctx->r16 = ADD32(ctx->r16, 0X24);
            goto L_800F9EA8;
    }
    goto skip_0;
    // 0x800F9E90: addiu       $s0, $s0, 0x24
    ctx->r16 = ADD32(ctx->r16, 0X24);
    skip_0:
    // 0x800F9E94: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800F9E98: j           L_800F9F0C
    // 0x800F9E9C: nop

        goto L_800F9F0C;
    // 0x800F9E9C: nop

L_800F9EA0:
    // 0x800F9EA0: addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
    // 0x800F9EA4: addiu       $s0, $s0, 0x24
    ctx->r16 = ADD32(ctx->r16, 0X24);
L_800F9EA8:
    // 0x800F9EA8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800F9EAC: slti        $v0, $s1, 0x10
    ctx->r2 = SIGNED(ctx->r17) < 0X10 ? 1 : 0;
    // 0x800F9EB0: bne         $v0, $zero, L_800F9E78
    if (ctx->r2 != 0) {
        // 0x800F9EB4: addiu       $s2, $s2, 0x24
        ctx->r18 = ADD32(ctx->r18, 0X24);
            goto L_800F9E78;
    }
    // 0x800F9EB4: addiu       $s2, $s2, 0x24
    ctx->r18 = ADD32(ctx->r18, 0X24);
    // 0x800F9EB8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800F9EBC: beq         $s3, $v0, L_800F9F08
    if (ctx->r19 == ctx->r2) {
        // 0x800F9EC0: sll         $s0, $s3, 3
        ctx->r16 = S32(ctx->r19 << 3);
            goto L_800F9F08;
    }
    // 0x800F9EC0: sll         $s0, $s3, 3
    ctx->r16 = S32(ctx->r19 << 3);
    // 0x800F9EC4: addu        $s0, $s0, $s3
    ctx->r16 = ADD32(ctx->r16, ctx->r19);
    // 0x800F9EC8: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x800F9ECC: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x800F9ED0: addiu       $s1, $s1, -0x3B5C
    ctx->r17 = ADD32(ctx->r17, -0X3B5C);
    // 0x800F9ED4: addu        $a0, $s0, $s1
    ctx->r4 = ADD32(ctx->r16, ctx->r17);
    // 0x800F9ED8: jal         0x8000761C
    // 0x800F9EDC: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    rs_strcpy(rdram, ctx);
        goto after_1;
    // 0x800F9EDC: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_1:
    // 0x800F9EE0: jal         0x8006488C
    // 0x800F9EE4: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    load_asset(rdram, ctx);
        goto after_2;
    // 0x800F9EE4: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_2:
    // 0x800F9EE8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800F9EEC: addiu       $s1, $s1, -0x4
    ctx->r17 = ADD32(ctx->r17, -0X4);
    // 0x800F9EF0: addu        $s0, $s0, $s1
    ctx->r16 = ADD32(ctx->r16, ctx->r17);
    // 0x800F9EF4: jal         0x80082BD0
    // 0x800F9EF8: sw          $a0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r4;
    model_animation_offset_convert(rdram, ctx);
        goto after_3;
    // 0x800F9EF8: sw          $a0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r4;
    after_3:
    // 0x800F9EFC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800F9F00: j           L_800F9F0C
    // 0x800F9F04: nop

        goto L_800F9F0C;
    // 0x800F9F04: nop

L_800F9F08:
    // 0x800F9F08: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F9F0C:
    // 0x800F9F0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800F9F10: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800F9F14: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800F9F18: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800F9F1C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800F9F20: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800F9F24: jr          $ra
    // 0x800F9F28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800F9F28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void reset_model_animations(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9F2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F9F30: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800F9F34: jal         0x80082870
    // 0x800F9F38: nop

    resetModelAnimSlotTable(rdram, ctx);
        goto after_0;
    // 0x800F9F38: nop

    after_0:
    // 0x800F9F3C: addiu       $v1, $zero, 0xF
    ctx->r3 = ADD32(0, 0XF);
    // 0x800F9F40: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800F9F44: addiu       $v0, $v0, -0x3B60
    ctx->r2 = ADD32(ctx->r2, -0X3B60);
    // 0x800F9F48: addiu       $v0, $v0, 0x21C
    ctx->r2 = ADD32(ctx->r2, 0X21C);
L_800F9F4C:
    // 0x800F9F4C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800F9F50: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F9F54: bgez        $v1, L_800F9F4C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800F9F58: addiu       $v0, $v0, -0x24
        ctx->r2 = ADD32(ctx->r2, -0X24);
            goto L_800F9F4C;
    }
    // 0x800F9F58: addiu       $v0, $v0, -0x24
    ctx->r2 = ADD32(ctx->r2, -0X24);
    // 0x800F9F5C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800F9F60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F9F64: jr          $ra
    // 0x800F9F68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F9F68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void reset_and_free_model_animations(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9F6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F9F70: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800F9F74: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800F9F78: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800F9F7C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800F9F80: addiu       $s0, $v0, -0x3B60
    ctx->r16 = ADD32(ctx->r2, -0X3B60);
    // 0x800F9F84: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
L_800F9F88:
    // 0x800F9F88: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800F9F8C: beql        $a0, $zero, L_800F9FA0
    if (ctx->r4 == 0) {
        // 0x800F9F90: sw          $zero, 0x0($s0)
        MEM_W(0X0, ctx->r16) = 0;
            goto L_800F9FA0;
    }
    goto skip_0;
    // 0x800F9F90: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    skip_0:
    // 0x800F9F94: jal         0x80001C98
    // 0x800F9F98: nop

    rs_free(rdram, ctx);
        goto after_0;
    // 0x800F9F98: nop

    after_0:
    // 0x800F9F9C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_800F9FA0:
    // 0x800F9FA0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800F9FA4: slti        $v0, $s1, 0x10
    ctx->r2 = SIGNED(ctx->r17) < 0X10 ? 1 : 0;
    // 0x800F9FA8: bne         $v0, $zero, L_800F9F88
    if (ctx->r2 != 0) {
        // 0x800F9FAC: addiu       $s0, $s0, 0x24
        ctx->r16 = ADD32(ctx->r16, 0X24);
            goto L_800F9F88;
    }
    // 0x800F9FAC: addiu       $s0, $s0, 0x24
    ctx->r16 = ADD32(ctx->r16, 0X24);
    // 0x800F9FB0: jal         0x80082870
    // 0x800F9FB4: nop

    resetModelAnimSlotTable(rdram, ctx);
        goto after_1;
    // 0x800F9FB4: nop

    after_1:
    // 0x800F9FB8: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800F9FBC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800F9FC0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800F9FC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F9FC8: jr          $ra
    // 0x800F9FCC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800F9FCC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void checkObjectiveHandles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9FD0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F9FD4: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x800F9FD8: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x800F9FDC: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800F9FE0: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800F9FE4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800F9FE8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800F9FEC: addiu       $s1, $v0, -0x3920
    ctx->r17 = ADD32(ctx->r2, -0X3920);
    // 0x800F9FF0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800F9FF4: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800F9FF8: addiu       $s4, $v0, -0x7760
    ctx->r20 = ADD32(ctx->r2, -0X7760);
    // 0x800F9FFC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800FA000: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800FA004: addiu       $s3, $v0, -0x7FA0
    ctx->r19 = ADD32(ctx->r2, -0X7FA0);
    // 0x800FA008: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800FA00C: addiu       $s0, $s1, 0xD
    ctx->r16 = ADD32(ctx->r17, 0XD);
    // 0x800FA010: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
L_800FA014:
    // 0x800FA014: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    // 0x800FA018: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FA01C: bnel        $a1, $v0, L_800FA0FC
    if (ctx->r5 != ctx->r2) {
        // 0x800FA020: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800FA0FC;
    }
    goto skip_0;
    // 0x800FA020: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x800FA024: lbu         $v0, -0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, -0X1);
    // 0x800FA028: beq         $v0, $zero, L_800FA040
    if (ctx->r2 == 0) {
        // 0x800FA02C: nop
    
            goto L_800FA040;
    }
    // 0x800FA02C: nop

    // 0x800FA030: beq         $v0, $a1, L_800FA0C4
    if (ctx->r2 == ctx->r5) {
        // 0x800FA034: nop
    
            goto L_800FA0C4;
    }
    // 0x800FA034: nop

    // 0x800FA038: j           L_800FA0FC
    // 0x800FA03C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_800FA0FC;
    // 0x800FA03C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800FA040:
    // 0x800FA040: lbu         $v0, -0x9($s0)
    ctx->r2 = MEM_BU(ctx->r16, -0X9);
    // 0x800FA044: beq         $v0, $zero, L_800FA05C
    if (ctx->r2 == 0) {
        // 0x800FA048: addu        $v0, $v0, $s4
        ctx->r2 = ADD32(ctx->r2, ctx->r20);
            goto L_800FA05C;
    }
    // 0x800FA048: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x800FA04C: lbu         $v1, -0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X1);
    // 0x800FA050: lbu         $v0, -0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, -0X8);
    // 0x800FA054: bnel        $v1, $v0, L_800FA0FC
    if (ctx->r3 != ctx->r2) {
        // 0x800FA058: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800FA0FC;
    }
    goto skip_1;
    // 0x800FA058: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_1:
L_800FA05C:
    // 0x800FA05C: lbu         $v0, -0x7($s0)
    ctx->r2 = MEM_BU(ctx->r16, -0X7);
    // 0x800FA060: beq         $v0, $zero, L_800FA0E0
    if (ctx->r2 == 0) {
        // 0x800FA064: nop
    
            goto L_800FA0E0;
    }
    // 0x800FA064: nop

    // 0x800FA068: lbu         $a0, -0x6($s0)
    ctx->r4 = MEM_BU(ctx->r16, -0X6);
    // 0x800FA06C: bne         $a0, $zero, L_800FA090
    if (ctx->r4 != 0) {
        // 0x800FA070: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800FA090;
    }
    // 0x800FA070: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800FA074: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FA078: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x800FA07C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800FA080: lw          $v1, -0x5($s0)
    ctx->r3 = MEM_W(ctx->r16, -0X5);
    // 0x800FA084: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800FA088: bnel        $v0, $zero, L_800FA0FC
    if (ctx->r2 != 0) {
        // 0x800FA08C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800FA0FC;
    }
    goto skip_2;
    // 0x800FA08C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_2:
L_800FA090:
    // 0x800FA090: bne         $a0, $a1, L_800FA0E0
    if (ctx->r4 != ctx->r5) {
        // 0x800FA094: nop
    
            goto L_800FA0E0;
    }
    // 0x800FA094: nop

    // 0x800FA098: lbu         $v0, -0x7($s0)
    ctx->r2 = MEM_BU(ctx->r16, -0X7);
    // 0x800FA09C: lw          $v1, -0x5($s0)
    ctx->r3 = MEM_W(ctx->r16, -0X5);
    // 0x800FA0A0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800FA0A4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FA0A8: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x800FA0AC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800FA0B0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800FA0B4: beql        $v0, $zero, L_800FA0FC
    if (ctx->r2 == 0) {
        // 0x800FA0B8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800FA0FC;
    }
    goto skip_3;
    // 0x800FA0B8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_3:
    // 0x800FA0BC: j           L_800FA0E0
    // 0x800FA0C0: nop

        goto L_800FA0E0;
    // 0x800FA0C0: nop

L_800FA0C4:
    // 0x800FA0C4: lwc1        $f0, -0x9($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, -0X9);
    // 0x800FA0C8: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800FA0CC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800FA0D0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800FA0D4: nop

    // 0x800FA0D8: bc1t        L_800FA0F8
    if (c1cs) {
        // 0x800FA0DC: swc1        $f0, -0x9($s0)
        MEM_W(-0X9, ctx->r16) = ctx->f0.u32l;
            goto L_800FA0F8;
    }
    // 0x800FA0DC: swc1        $f0, -0x9($s0)
    MEM_W(-0X9, ctx->r16) = ctx->f0.u32l;
L_800FA0E0:
    // 0x800FA0E0: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800FA0E4: bne         $v0, $zero, L_800FA0F8
    if (ctx->r2 != 0) {
        // 0x800FA0E8: sb          $zero, 0x1($s0)
        MEM_B(0X1, ctx->r16) = 0;
            goto L_800FA0F8;
    }
    // 0x800FA0E8: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // 0x800FA0EC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800FA0F0: jalr        $v0
    // 0x800FA0F4: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800FA0F4: nop

    after_0:
L_800FA0F8:
    // 0x800FA0F8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800FA0FC:
    // 0x800FA0FC: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800FA100: slti        $v0, $s2, 0x30
    ctx->r2 = SIGNED(ctx->r18) < 0X30 ? 1 : 0;
    // 0x800FA104: bne         $v0, $zero, L_800FA014
    if (ctx->r2 != 0) {
        // 0x800FA108: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_800FA014;
    }
    // 0x800FA108: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x800FA10C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800FA110: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800FA114: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800FA118: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800FA11C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800FA120: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800FA124: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800FA128: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FA12C: jr          $ra
    // 0x800FA130: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800FA130: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void initializeObjectiveHandles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FA134: addiu       $v1, $zero, 0x2F
    ctx->r3 = ADD32(0, 0X2F);
    // 0x800FA138: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FA13C: addiu       $v0, $v0, -0x3920
    ctx->r2 = ADD32(ctx->r2, -0X3920);
    // 0x800FA140: addiu       $v0, $v0, 0x2F0
    ctx->r2 = ADD32(ctx->r2, 0X2F0);
L_800FA144:
    // 0x800FA144: sb          $zero, 0xE($v0)
    MEM_B(0XE, ctx->r2) = 0;
    // 0x800FA148: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800FA14C: bgez        $v1, L_800FA144
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800FA150: addiu       $v0, $v0, -0x10
        ctx->r2 = ADD32(ctx->r2, -0X10);
            goto L_800FA144;
    }
    // 0x800FA150: addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // 0x800FA154: jr          $ra
    // 0x800FA158: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800FA158: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void addBooleanCountHandle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FA15C: addu        $t2, $a0, $zero
    ctx->r10 = ADD32(ctx->r4, 0);
    // 0x800FA160: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800FA164: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FA168: addiu       $t0, $v0, -0x3920
    ctx->r8 = ADD32(ctx->r2, -0X3920);
    // 0x800FA16C: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x800FA170: lbu         $t1, 0x17($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X17);
L_800FA174:
    // 0x800FA174: lbu         $v0, 0xE($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XE);
    // 0x800FA178: beq         $v0, $zero, L_800FA194
    if (ctx->r2 == 0) {
        // 0x800FA17C: addiu       $v0, $zero, 0x30
        ctx->r2 = ADD32(0, 0X30);
            goto L_800FA194;
    }
    // 0x800FA17C: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x800FA180: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800FA184: slti        $v0, $v1, 0x30
    ctx->r2 = SIGNED(ctx->r3) < 0X30 ? 1 : 0;
    // 0x800FA188: bne         $v0, $zero, L_800FA174
    if (ctx->r2 != 0) {
        // 0x800FA18C: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_800FA174;
    }
    // 0x800FA18C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800FA190: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
L_800FA194:
    // 0x800FA194: beq         $v1, $v0, L_800FA1D4
    if (ctx->r3 == ctx->r2) {
        // 0x800FA198: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800FA1D4;
    }
    // 0x800FA198: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FA19C: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800FA1A0: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x800FA1A4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800FA1A8: sb          $a0, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r4;
    // 0x800FA1AC: sb          $zero, 0xD($v1)
    MEM_B(0XD, ctx->r3) = 0;
    // 0x800FA1B0: sb          $zero, 0xC($v1)
    MEM_B(0XC, ctx->r3) = 0;
    // 0x800FA1B4: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800FA1B8: sb          $a1, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r5;
    // 0x800FA1BC: sb          $a2, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r6;
    // 0x800FA1C0: sb          $a3, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r7;
    // 0x800FA1C4: lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X10);
    // 0x800FA1C8: sb          $t1, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r9;
    // 0x800FA1CC: jr          $ra
    // 0x800FA1D0: sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    return;
    // 0x800FA1D0: sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
L_800FA1D4:
    // 0x800FA1D4: jr          $ra
    // 0x800FA1D8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800FA1D8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void addTimerHandle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FA1DC: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x800FA1E0: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x800FA1E4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800FA1E8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FA1EC: addiu       $a1, $v0, -0x3920
    ctx->r5 = ADD32(ctx->r2, -0X3920);
    // 0x800FA1F0: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
L_800FA1F4:
    // 0x800FA1F4: lbu         $v0, 0xE($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XE);
    // 0x800FA1F8: beq         $v0, $zero, L_800FA214
    if (ctx->r2 == 0) {
        // 0x800FA1FC: addiu       $v0, $zero, 0x30
        ctx->r2 = ADD32(0, 0X30);
            goto L_800FA214;
    }
    // 0x800FA1FC: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x800FA200: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800FA204: slti        $v0, $v1, 0x30
    ctx->r2 = SIGNED(ctx->r3) < 0X30 ? 1 : 0;
    // 0x800FA208: bne         $v0, $zero, L_800FA1F4
    if (ctx->r2 != 0) {
        // 0x800FA20C: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_800FA1F4;
    }
    // 0x800FA20C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800FA210: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
L_800FA214:
    // 0x800FA214: beq         $v1, $v0, L_800FA240
    if (ctx->r3 == ctx->r2) {
        // 0x800FA218: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800FA240;
    }
    // 0x800FA218: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FA21C: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800FA220: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800FA224: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800FA228: sb          $a0, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r4;
    // 0x800FA22C: sb          $zero, 0xD($v1)
    MEM_B(0XD, ctx->r3) = 0;
    // 0x800FA230: sb          $a0, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r4;
    // 0x800FA234: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x800FA238: jr          $ra
    // 0x800FA23C: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    return;
    // 0x800FA23C: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
L_800FA240:
    // 0x800FA240: jr          $ra
    // 0x800FA244: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800FA244: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void fake_func_800FA248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void initMission(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FA250: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800FA254: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x800FA258: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FA25C: sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // 0x800FA260: addiu       $s2, $s0, 0xB40
    ctx->r18 = ADD32(ctx->r16, 0XB40);
    // 0x800FA264: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x800FA268: sw          $s4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r20;
    // 0x800FA26C: sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // 0x800FA270: sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // 0x800FA274: lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X10);
    // 0x800FA278: andi        $v0, $v0, 0x60
    ctx->r2 = ctx->r2 & 0X60;
    // 0x800FA27C: beq         $v0, $zero, L_800FA28C
    if (ctx->r2 == 0) {
        // 0x800FA280: nop
    
            goto L_800FA28C;
    }
    // 0x800FA280: nop

    // 0x800FA284: jal         0x80003460
    // 0x800FA288: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    setRngSeed(rdram, ctx);
        goto after_0;
    // 0x800FA288: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
L_800FA28C:
    // 0x800FA28C: jal         0x8003E560
    // 0x800FA290: nop

    initNpcSlotList(rdram, ctx);
        goto after_1;
    // 0x800FA290: nop

    after_1:
    // 0x800FA294: jal         0x8003FD54
    // 0x800FA298: nop

    allocNpcContextArrays(rdram, ctx);
        goto after_2;
    // 0x800FA298: nop

    after_2:
    // 0x800FA29C: jal         0x8005C5D0
    // 0x800FA2A0: nop

    allocAllInitialNpcSlots(rdram, ctx);
        goto after_3;
    // 0x800FA2A0: nop

    after_3:
    // 0x800FA2A4: jal         0x80056350
    // 0x800FA2A8: nop

    initNpcBookkeepingTables(rdram, ctx);
        goto after_4;
    // 0x800FA2A8: nop

    after_4:
    // 0x800FA2AC: jal         0x80017B48
    // 0x800FA2B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    setMissionLevelInitByte(rdram, ctx);
        goto after_5;
    // 0x800FA2B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x800FA2B4: jal         0x80054A18
    // 0x800FA2B8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80054A18(rdram, ctx);
        goto after_6;
    // 0x800FA2B8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_6:
    // 0x800FA2BC: jal         0x80054C54
    // 0x800FA2C0: nop

    func_80054C54(rdram, ctx);
        goto after_7;
    // 0x800FA2C0: nop

    after_7:
    // 0x800FA2C4: jal         0x800663B0
    // 0x800FA2C8: nop

    loadSndFiles(rdram, ctx);
        goto after_8;
    // 0x800FA2C8: nop

    after_8:
    // 0x800FA2CC: jal         0x800F9F2C
    // 0x800FA2D0: nop

    reset_model_animations(rdram, ctx);
        goto after_9;
    // 0x800FA2D0: nop

    after_9:
    // 0x800FA2D4: jal         0x800EC4D8
    // 0x800FA2D8: nop

    func_800EC4D8(rdram, ctx);
        goto after_10;
    // 0x800FA2D8: nop

    after_10:
    // 0x800FA2DC: jal         0x800FA134
    // 0x800FA2E0: nop

    initializeObjectiveHandles(rdram, ctx);
        goto after_11;
    // 0x800FA2E0: nop

    after_11:
    // 0x800FA2E4: jal         0x80040310
    // 0x800FA2E8: nop

    allocAndInitParticlePool(rdram, ctx);
        goto after_12;
    // 0x800FA2E8: nop

    after_12:
    // 0x800FA2EC: jal         0x8006C6D0
    // 0x800FA2F0: nop

    clearTrackedNpcSlots(rdram, ctx);
        goto after_13;
    // 0x800FA2F0: nop

    after_13:
    // 0x800FA2F4: jal         0x8000E0BC
    // 0x800FA2F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8000E0BC(rdram, ctx);
        goto after_14;
    // 0x800FA2F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_14:
    // 0x800FA2FC: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x800FA300: lh          $v0, 0x7576($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7576);
    // 0x800FA304: slti        $v0, $v0, 0x11
    ctx->r2 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x800FA308: bnel        $v0, $zero, L_800FA324
    if (ctx->r2 != 0) {
        // 0x800FA30C: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_800FA324;
    }
    goto skip_0;
    // 0x800FA30C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    skip_0:
    // 0x800FA310: jal         0x8000E0BC
    // 0x800FA314: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8000E0BC(rdram, ctx);
        goto after_15;
    // 0x800FA314: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_15:
    // 0x800FA318: jal         0x8000E0E0
    // 0x800FA31C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8000E0E0(rdram, ctx);
        goto after_16;
    // 0x800FA31C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_16:
    // 0x800FA320: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_800FA324:
    // 0x800FA324: jal         0x80055880
    // 0x800FA328: addiu       $a0, $a0, -0x7090
    ctx->r4 = ADD32(ctx->r4, -0X7090);
    loadGameOrFrontTxtFile(rdram, ctx);
        goto after_17;
    // 0x800FA328: addiu       $a0, $a0, -0x7090
    ctx->r4 = ADD32(ctx->r4, -0X7090);
    after_17:
    // 0x800FA32C: jal         0x80055A30
    // 0x800FA330: nop

    initVoiceSubtitleSystem(rdram, ctx);
        goto after_18;
    // 0x800FA330: nop

    after_18:
    // 0x800FA334: lbu         $v1, 0x1($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X1);
    // 0x800FA338: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800FA33C: beq         $v1, $v0, L_800FA348
    if (ctx->r3 == ctx->r2) {
        // 0x800FA340: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800FA348;
    }
    // 0x800FA340: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800FA344: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
L_800FA348:
    // 0x800FA348: jal         0x800561AC
    // 0x800FA34C: addiu       $a1, $zero, -0xA
    ctx->r5 = ADD32(0, -0XA);
    func_800561AC(rdram, ctx);
        goto after_19;
    // 0x800FA34C: addiu       $a1, $zero, -0xA
    ctx->r5 = ADD32(0, -0XA);
    after_19:
    // 0x800FA350: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FA354: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x800FA358: sw          $zero, -0x35E0($v0)
    MEM_W(-0X35E0, ctx->r2) = 0;
    // 0x800FA35C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FA360: sw          $zero, -0x3620($v0)
    MEM_W(-0X3620, ctx->r2) = 0;
    // 0x800FA364: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FA368: sw          $zero, -0x35E4($s1)
    MEM_W(-0X35E4, ctx->r17) = 0;
    // 0x800FA36C: sw          $zero, -0x3618($v0)
    MEM_W(-0X3618, ctx->r2) = 0;
    // 0x800FA370: lbu         $v1, 0x2($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X2);
    // 0x800FA374: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FA378: sw          $v1, 0x7CE4($v0)
    MEM_W(0X7CE4, ctx->r2) = ctx->r3;
    // 0x800FA37C: lbu         $v0, 0xB40($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XB40);
    // 0x800FA380: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FA384: jal         0x8006E9E4
    // 0x800FA388: sw          $v0, 0xB70($s0)
    MEM_W(0XB70, ctx->r16) = ctx->r2;
    initPlayerMissionStateFromSettings(rdram, ctx);
        goto after_20;
    // 0x800FA388: sw          $v0, 0xB70($s0)
    MEM_W(0XB70, ctx->r16) = ctx->r2;
    after_20:
    // 0x800FA38C: jal         0x8006EDB8
    // 0x800FA390: nop

    gatherActiveUnlockFlags(rdram, ctx);
        goto after_21;
    // 0x800FA390: nop

    after_21:
    // 0x800FA394: lw          $v1, 0xB70($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XB70);
    // 0x800FA398: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x800FA39C: bne         $v1, $v0, L_800FA3B4
    if (ctx->r3 != ctx->r2) {
        // 0x800FA3A0: addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
            goto L_800FA3B4;
    }
    // 0x800FA3A0: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x800FA3A4: lw          $v0, -0x35E4($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X35E4);
    // 0x800FA3A8: ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
    // 0x800FA3AC: sw          $v0, -0x35E4($s1)
    MEM_W(-0X35E4, ctx->r17) = ctx->r2;
    // 0x800FA3B0: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_800FA3B4:
    // 0x800FA3B4: bne         $v1, $v0, L_800FA3C8
    if (ctx->r3 != ctx->r2) {
        // 0x800FA3B8: nop
    
            goto L_800FA3C8;
    }
    // 0x800FA3B8: nop

    // 0x800FA3BC: lw          $v0, -0x35E4($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X35E4);
    // 0x800FA3C0: ori         $v0, $v0, 0x800
    ctx->r2 = ctx->r2 | 0X800;
    // 0x800FA3C4: sw          $v0, -0x35E4($s1)
    MEM_W(-0X35E4, ctx->r17) = ctx->r2;
L_800FA3C8:
    // 0x800FA3C8: lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC);
    // 0x800FA3CC: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x800FA3D0: beq         $v0, $zero, L_800FA3E4
    if (ctx->r2 == 0) {
        // 0x800FA3D4: addiu       $v1, $zero, -0x81
        ctx->r3 = ADD32(0, -0X81);
            goto L_800FA3E4;
    }
    // 0x800FA3D4: addiu       $v1, $zero, -0x81
    ctx->r3 = ADD32(0, -0X81);
    // 0x800FA3D8: lw          $v0, -0x35E4($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X35E4);
    // 0x800FA3DC: j           L_800FA3EC
    // 0x800FA3E0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
        goto L_800FA3EC;
    // 0x800FA3E0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
L_800FA3E4:
    // 0x800FA3E4: lw          $v0, -0x35E4($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X35E4);
    // 0x800FA3E8: ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
L_800FA3EC:
    // 0x800FA3EC: sw          $v0, -0x35E4($s1)
    MEM_W(-0X35E4, ctx->r17) = ctx->r2;
    // 0x800FA3F0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800FA3F4: addiu       $a0, $a0, -0x7FA0
    ctx->r4 = ADD32(ctx->r4, -0X7FA0);
    // 0x800FA3F8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800FA3FC: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    // 0x800FA400: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FA404: sb          $zero, 0x7CF4($v0)
    MEM_B(0X7CF4, ctx->r2) = 0;
    // 0x800FA408: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800FA40C: sb          $zero, -0x7770($v0)
    MEM_B(-0X7770, ctx->r2) = 0;
    // 0x800FA410: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800FA414: sb          $zero, -0x76DB($v0)
    MEM_B(-0X76DB, ctx->r2) = 0;
    // 0x800FA418: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800FA41C: sb          $zero, -0x77C8($v0)
    MEM_B(-0X77C8, ctx->r2) = 0;
    // 0x800FA420: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800FA424: sb          $zero, -0x77C7($v0)
    MEM_B(-0X77C7, ctx->r2) = 0;
    // 0x800FA428: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800FA42C: sb          $zero, -0x76D9($v0)
    MEM_B(-0X76D9, ctx->r2) = 0;
    // 0x800FA430: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800FA434: sb          $zero, -0x76DC($v0)
    MEM_B(-0X76DC, ctx->r2) = 0;
    // 0x800FA438: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800FA43C: sw          $zero, -0x72F0($v0)
    MEM_W(-0X72F0, ctx->r2) = 0;
    // 0x800FA440: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800FA444: jal         0x800078E0
    // 0x800FA448: sw          $zero, -0x7764($v0)
    MEM_W(-0X7764, ctx->r2) = 0;
    rs_memset(rdram, ctx);
        goto after_22;
    // 0x800FA448: sw          $zero, -0x7764($v0)
    MEM_W(-0X7764, ctx->r2) = 0;
    after_22:
    // 0x800FA44C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800FA450: addiu       $a0, $a0, -0x7760
    ctx->r4 = ADD32(ctx->r4, -0X7760);
    // 0x800FA454: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800FA458: jal         0x800078E0
    // 0x800FA45C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    rs_memset(rdram, ctx);
        goto after_23;
    // 0x800FA45C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_23:
    // 0x800FA460: jal         0x800555F0
    // 0x800FA464: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    initPlayerStructs(rdram, ctx);
        goto after_24;
    // 0x800FA464: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    after_24:
    // 0x800FA468: jal         0x800BEEAC
    // 0x800FA46C: nop

    func_800BEEAC(rdram, ctx);
        goto after_25;
    // 0x800FA46C: nop

    after_25:
    // 0x800FA470: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FA474: addiu       $a3, $v0, 0xB40
    ctx->r7 = ADD32(ctx->r2, 0XB40);
    // 0x800FA478: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800FA47C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FA480: addiu       $a0, $v0, -0x4058
    ctx->r4 = ADD32(ctx->r2, -0X4058);
    // 0x800FA484: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FA488: addiu       $a1, $v0, -0x41E8
    ctx->r5 = ADD32(ctx->r2, -0X41E8);
L_800FA48C:
    // 0x800FA48C: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800FA490: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x800FA494: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800FA498: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x800FA49C: lhu         $v1, 0x4($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X4);
    // 0x800FA4A0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800FA4A4: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x800FA4A8: lhu         $v1, 0x2($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X2);
    // 0x800FA4AC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800FA4B0: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x800FA4B4: lhu         $v1, 0x1E($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X1E);
    // 0x800FA4B8: or          $v1, $v0, $v1
    ctx->r3 = ctx->r2 | ctx->r3;
    // 0x800FA4BC: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
    // 0x800FA4C0: lbu         $v0, 0x1($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X1);
    // 0x800FA4C4: beql        $v0, $a2, L_800FA4DC
    if (ctx->r2 == ctx->r6) {
        // 0x800FA4C8: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_800FA4DC;
    }
    goto skip_1;
    // 0x800FA4C8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    skip_1:
    // 0x800FA4CC: lhu         $v0, 0x22($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X22);
    // 0x800FA4D0: or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    // 0x800FA4D4: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x800FA4D8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
L_800FA4DC:
    // 0x800FA4DC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800FA4E0: blez        $s1, L_800FA48C
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800FA4E4: addiu       $a1, $a1, 0x24
        ctx->r5 = ADD32(ctx->r5, 0X24);
            goto L_800FA48C;
    }
    // 0x800FA4E4: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    // 0x800FA4E8: jal         0x8005360C
    // 0x800FA4EC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    func_8005360C(rdram, ctx);
        goto after_26;
    // 0x800FA4EC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    after_26:
    // 0x800FA4F0: jal         0x8004FFA8
    // 0x800FA4F4: nop

    initPlayerVehicleStateTables(rdram, ctx);
        goto after_27;
    // 0x800FA4F4: nop

    after_27:
    // 0x800FA4F8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800FA4FC: addiu       $s4, $v0, -0x13BC
    ctx->r20 = ADD32(ctx->r2, -0X13BC);
    // 0x800FA500: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800FA504: addiu       $s3, $v0, -0x7FF4
    ctx->r19 = ADD32(ctx->r2, -0X7FF4);
    // 0x800FA508: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800FA50C: addiu       $s0, $v0, -0x7D98
    ctx->r16 = ADD32(ctx->r2, -0X7D98);
    // 0x800FA510: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800FA514: addiu       $s2, $v0, -0x72E8
    ctx->r18 = ADD32(ctx->r2, -0X72E8);
L_800FA518:
    // 0x800FA518: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800FA51C: beq         $v0, $zero, L_800FA548
    if (ctx->r2 == 0) {
        // 0x800FA520: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800FA548;
    }
    // 0x800FA520: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800FA524: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x800FA528: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x800FA52C: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    // 0x800FA530: sw          $s3, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r19;
    // 0x800FA534: andi        $v0, $v0, 0xFFFE
    ctx->r2 = ctx->r2 & 0XFFFE;
    // 0x800FA538: jal         0x80053288
    // 0x800FA53C: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    func_80053288(rdram, ctx);
        goto after_28;
    // 0x800FA53C: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    after_28:
    // 0x800FA540: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800FA544: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
L_800FA548:
    // 0x800FA548: addiu       $s3, $s3, 0x2A0
    ctx->r19 = ADD32(ctx->r19, 0X2A0);
    // 0x800FA54C: addiu       $s0, $s0, 0x5D0
    ctx->r16 = ADD32(ctx->r16, 0X5D0);
    // 0x800FA550: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800FA554: blez        $s1, L_800FA518
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800FA558: addiu       $s2, $s2, 0x144
        ctx->r18 = ADD32(ctx->r18, 0X144);
            goto L_800FA518;
    }
    // 0x800FA558: addiu       $s2, $s2, 0x144
    ctx->r18 = ADD32(ctx->r18, 0X144);
    // 0x800FA55C: jal         0x8005E7EC
    // 0x800FA560: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    loadWeaponsHobObjects(rdram, ctx);
        goto after_29;
    // 0x800FA560: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    after_29:
    // 0x800FA564: jal         0x8006B630
    // 0x800FA568: nop

    func_8006B630(rdram, ctx);
        goto after_30;
    // 0x800FA568: nop

    after_30:
    // 0x800FA56C: jal         0x800453C8
    // 0x800FA570: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    loadLevelAssets(rdram, ctx);
        goto after_31;
    // 0x800FA570: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_31:
    // 0x800FA574: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800FA578: addiu       $a0, $a0, 0x4724
    ctx->r4 = ADD32(ctx->r4, 0X4724);
    // 0x800FA57C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800FA580: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800FA584: jal         0x8003FFEC
    // 0x800FA588: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    spawnNpcOfType(rdram, ctx);
        goto after_32;
    // 0x800FA588: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    after_32:
    // 0x800FA58C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800FA590: sh          $v0, 0xBA2($v1)
    MEM_H(0XBA2, ctx->r3) = ctx->r2;
    // 0x800FA594: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FA598: addiu       $a0, $v0, 0xB40
    ctx->r4 = ADD32(ctx->r2, 0XB40);
    // 0x800FA59C: addiu       $v1, $sp, 0x60
    ctx->r3 = ADD32(ctx->r29, 0X60);
L_800FA5A0:
    // 0x800FA5A0: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x800FA5A4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800FA5A8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800FA5AC: bgez        $s1, L_800FA5A0
    if (SIGNED(ctx->r17) >= 0) {
        // 0x800FA5B0: addiu       $v1, $v1, -0x4
        ctx->r3 = ADD32(ctx->r3, -0X4);
            goto L_800FA5A0;
    }
    // 0x800FA5B0: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800FA5B4: jal         0x800FB6C0
    // 0x800FA5B8: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    choosePlayerCraftAssets(rdram, ctx);
        goto after_33;
    // 0x800FA5B8: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    after_33:
    // 0x800FA5BC: jal         0x800C3F70
    // 0x800FA5C0: addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
    spawnHudNpc(rdram, ctx);
        goto after_34;
    // 0x800FA5C0: addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
    after_34:
    // 0x800FA5C4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FA5C8: lbu         $a1, 0xB62($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0XB62);
    // 0x800FA5CC: jal         0x80066A90
    // 0x800FA5D0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    initSpeechSubsystem(rdram, ctx);
        goto after_35;
    // 0x800FA5D0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_35:
    // 0x800FA5D4: jal         0x800664B8
    // 0x800FA5D8: nop

    func_800664B8(rdram, ctx);
        goto after_36;
    // 0x800FA5D8: nop

    after_36:
    // 0x800FA5DC: jal         0x800EF048
    // 0x800FA5E0: nop

    func_800EF048(rdram, ctx);
        goto after_37;
    // 0x800FA5E0: nop

    after_37:
    // 0x800FA5E4: jal         0x800EFB94
    // 0x800FA5E8: nop

    func_800EFB94(rdram, ctx);
        goto after_38;
    // 0x800FA5E8: nop

    after_38:
    // 0x800FA5EC: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    // 0x800FA5F0: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    // 0x800FA5F4: jal         0x8008E0B0
    // 0x800FA5F8: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    playSimpleAudioCmd(rdram, ctx);
        goto after_39;
    // 0x800FA5F8: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    after_39:
    // 0x800FA5FC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FA600: addiu       $v0, $v0, -0x3608
    ctx->r2 = ADD32(ctx->r2, -0X3608);
    // 0x800FA604: addiu       $v1, $v0, 0x1C
    ctx->r3 = ADD32(ctx->r2, 0X1C);
    // 0x800FA608: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FA60C: sw          $zero, 0xBA4($v0)
    MEM_W(0XBA4, ctx->r2) = 0;
    // 0x800FA610: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FA614: sw          $zero, -0x361C($v0)
    MEM_W(-0X361C, ctx->r2) = 0;
L_800FA618:
    // 0x800FA618: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800FA61C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800FA620: bgez        $s1, L_800FA618
    if (SIGNED(ctx->r17) >= 0) {
        // 0x800FA624: addiu       $v1, $v1, -0x4
        ctx->r3 = ADD32(ctx->r3, -0X4);
            goto L_800FA618;
    }
    // 0x800FA624: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800FA628: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FA62C: sw          $zero, 0xB78($v0)
    MEM_W(0XB78, ctx->r2) = 0;
    // 0x800FA630: addiu       $v0, $v0, 0xB78
    ctx->r2 = ADD32(ctx->r2, 0XB78);
    // 0x800FA634: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800FA638: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x800FA63C: sh          $zero, 0xC($v0)
    MEM_H(0XC, ctx->r2) = 0;
    // 0x800FA640: sb          $zero, 0xE($v0)
    MEM_B(0XE, ctx->r2) = 0;
    // 0x800FA644: jal         0x800C3FEC
    // 0x800FA648: sb          $zero, 0xF($v0)
    MEM_B(0XF, ctx->r2) = 0;
    func_800C3FEC(rdram, ctx);
        goto after_40;
    // 0x800FA648: sb          $zero, 0xF($v0)
    MEM_B(0XF, ctx->r2) = 0;
    after_40:
    // 0x800FA64C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800FA650: jal         0x80047B48
    // 0x800FA654: addiu       $a0, $a0, -0x7084
    ctx->r4 = ADD32(ctx->r4, -0X7084);
    getLevelDatItemByName(rdram, ctx);
        goto after_41;
    // 0x800FA654: addiu       $a0, $a0, -0x7084
    ctx->r4 = ADD32(ctx->r4, -0X7084);
    after_41:
    // 0x800FA658: jal         0x800C72B0
    // 0x800FA65C: nop

    initializeObjectiveTracking(rdram, ctx);
        goto after_42;
    // 0x800FA65C: nop

    after_42:
    // 0x800FA660: jal         0x80079A70
    // 0x800FA664: nop

    func_80079A70(rdram, ctx);
        goto after_43;
    // 0x800FA664: nop

    after_43:
    // 0x800FA668: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FA66C: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x800FA670: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x800FA674: beq         $v1, $v0, L_800FA684
    if (ctx->r3 == ctx->r2) {
        // 0x800FA678: nop
    
            goto L_800FA684;
    }
    // 0x800FA678: nop

    // 0x800FA67C: jal         0x80048104
    // 0x800FA680: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    loadLevelTextureCache(rdram, ctx);
        goto after_44;
    // 0x800FA680: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    after_44:
L_800FA684:
    // 0x800FA684: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x800FA688: lw          $s4, 0x78($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X78);
    // 0x800FA68C: lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X74);
    // 0x800FA690: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x800FA694: lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6C);
    // 0x800FA698: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x800FA69C: jr          $ra
    // 0x800FA6A0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800FA6A0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void runInMissionFrame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FA6A4: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x800FA6A8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800FA6AC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FA6B0: addiu       $a1, $v0, 0xB40
    ctx->r5 = ADD32(ctx->r2, 0XB40);
    // 0x800FA6B4: sw          $ra, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r31;
    // 0x800FA6B8: sw          $fp, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r30;
    // 0x800FA6BC: sw          $s7, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r23;
    // 0x800FA6C0: sw          $s6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r22;
    // 0x800FA6C4: sw          $s5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r21;
    // 0x800FA6C8: sw          $s4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r20;
    // 0x800FA6CC: sw          $s3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r19;
    // 0x800FA6D0: sw          $s2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r18;
    // 0x800FA6D4: sw          $s1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r17;
    // 0x800FA6D8: sw          $s0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r16;
    // 0x800FA6DC: sdc1        $f22, 0xC0($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XC0, ctx->r29);
    // 0x800FA6E0: sdc1        $f20, 0xB8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XB8, ctx->r29);
    // 0x800FA6E4: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    // 0x800FA6E8: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x800FA6EC: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x800FA6F0: beq         $v0, $zero, L_800FA704
    if (ctx->r2 == 0) {
        // 0x800FA6F4: sw          $v1, -0x3618($a0)
        MEM_W(-0X3618, ctx->r4) = ctx->r3;
            goto L_800FA704;
    }
    // 0x800FA6F4: sw          $v1, -0x3618($a0)
    MEM_W(-0X3618, ctx->r4) = ctx->r3;
    // 0x800FA6F8: lbu         $a0, 0x14($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X14);
    // 0x800FA6FC: jal         0x800BF408
    // 0x800FA700: nop

    loadAndStartDemo(rdram, ctx);
        goto after_0;
    // 0x800FA700: nop

    after_0:
L_800FA704:
    // 0x800FA704: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FA708: lw          $v0, -0x35E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E4);
    // 0x800FA70C: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // 0x800FA710: bne         $v0, $zero, L_800FADAC
    if (ctx->r2 != 0) {
        // 0x800FA714: lui         $s7, 0x8011
        ctx->r23 = S32(0X8011 << 16);
            goto L_800FADAC;
    }
    // 0x800FA714: lui         $s7, 0x8011
    ctx->r23 = S32(0X8011 << 16);
    // 0x800FA718: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800FA71C: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800FA720: lui         $fp, 0x8014
    ctx->r30 = S32(0X8014 << 16);
    // 0x800FA724: addiu       $s4, $fp, -0x6AA0
    ctx->r20 = ADD32(ctx->r30, -0X6AA0);
L_800FA728:
    // 0x800FA728: jal         0x8000BC00
    // 0x800FA72C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    timeSnapshotFiller(rdram, ctx);
        goto after_1;
    // 0x800FA72C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x800FA730: lwc1        $f20, 0x30($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800FA734: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800FA738: jal         0x8001E20C
    // 0x800FA73C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    floatModulo(rdram, ctx);
        goto after_2;
    // 0x800FA73C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_2:
    // 0x800FA740: mov.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
    // 0x800FA744: c.lt.s      $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f22.fl < ctx->f4.fl;
    // 0x800FA748: nop

    // 0x800FA74C: bc1f        L_800FA780
    if (!c1cs) {
        // 0x800FA750: nop
    
            goto L_800FA780;
    }
    // 0x800FA750: nop

    // 0x800FA754: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800FA758: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FA75C: lwc1        $f2, -0x706C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X706C);
    // 0x800FA760: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800FA764: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800FA768: nop

    // 0x800FA76C: bc1fl       L_800FA77C
    if (!c1cs) {
        // 0x800FA770: add.s       $f0, $f20, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f6.fl;
            goto L_800FA77C;
    }
    goto skip_0;
    // 0x800FA770: add.s       $f0, $f20, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f6.fl;
    skip_0:
    // 0x800FA774: j           L_800FA780
    // 0x800FA778: sub.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f4.fl;
        goto L_800FA780;
    // 0x800FA778: sub.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f4.fl;
L_800FA77C:
    // 0x800FA77C: sub.s       $f20, $f0, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f4.fl;
L_800FA780:
    // 0x800FA780: c.le.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl <= ctx->f22.fl;
    // 0x800FA784: nop

    // 0x800FA788: bc1f        L_800FA798
    if (!c1cs) {
        // 0x800FA78C: nop
    
            goto L_800FA798;
    }
    // 0x800FA78C: nop

    // 0x800FA790: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FA794: lwc1        $f20, -0x7068($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7068);
L_800FA798:
    // 0x800FA798: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FA79C: lwc1        $f0, -0x7064($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7064);
    // 0x800FA7A0: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800FA7A4: nop

    // 0x800FA7A8: bc1tl       L_800FA7B0
    if (c1cs) {
        // 0x800FA7AC: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_800FA7B0;
    }
    goto skip_1;
    // 0x800FA7AC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_1:
L_800FA7B0:
    // 0x800FA7B0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FA7B4: lw          $v0, 0xB50($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB50);
    // 0x800FA7B8: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x800FA7BC: beq         $v0, $zero, L_800FA7D0
    if (ctx->r2 == 0) {
        // 0x800FA7C0: nop
    
            goto L_800FA7D0;
    }
    // 0x800FA7C0: nop

    // 0x800FA7C4: jal         0x800BF468
    // 0x800FA7C8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800BF468(rdram, ctx);
        goto after_3;
    // 0x800FA7C8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_3:
    // 0x800FA7CC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_800FA7D0:
    // 0x800FA7D0: jal         0x80002FF4
    // 0x800FA7D4: swc1        $f20, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f20.u32l;
    pollControllerInputs(rdram, ctx);
        goto after_4;
    // 0x800FA7D4: swc1        $f20, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f20.u32l;
    after_4:
    // 0x800FA7D8: jal         0x800BEFBC
    // 0x800FA7DC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800BEFBC(rdram, ctx);
        goto after_5;
    // 0x800FA7DC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_5:
    // 0x800FA7E0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FA7E4: lbu         $v1, -0x4CB0($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X4CB0);
    // 0x800FA7E8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800FA7EC: beql        $v1, $v0, L_800FA858
    if (ctx->r3 == ctx->r2) {
        // 0x800FA7F0: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800FA858;
    }
    goto skip_2;
    // 0x800FA7F0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    skip_2:
    // 0x800FA7F4: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800FA7F8: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800FA7FC: addiu       $s0, $s0, -0x4CB0
    ctx->r16 = ADD32(ctx->r16, -0X4CB0);
L_800FA800:
    // 0x800FA800: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x800FA804: lw          $v0, -0x3620($s7)
    ctx->r2 = MEM_W(ctx->r23, -0X3620);
    // 0x800FA808: sllv        $v1, $s6, $a0
    ctx->r3 = S32(ctx->r22 << (ctx->r4 & 31));
    // 0x800FA80C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800FA810: beql        $v0, $zero, L_800FA84C
    if (ctx->r2 == 0) {
        // 0x800FA814: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_800FA84C;
    }
    goto skip_3;
    // 0x800FA814: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    skip_3:
    // 0x800FA818: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800FA81C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800FA820: jalr        $v0
    // 0x800FA824: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x800FA824: nop

    after_6:
    // 0x800FA828: beql        $v0, $zero, L_800FA84C
    if (ctx->r2 == 0) {
        // 0x800FA82C: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_800FA84C;
    }
    goto skip_4;
    // 0x800FA82C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    skip_4:
    // 0x800FA830: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800FA834: lw          $v1, -0x3620($s7)
    ctx->r3 = MEM_W(ctx->r23, -0X3620);
    // 0x800FA838: sllv        $v0, $s6, $v0
    ctx->r2 = S32(ctx->r22 << (ctx->r2 & 31));
    // 0x800FA83C: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x800FA840: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x800FA844: sw          $v1, -0x3620($s7)
    MEM_W(-0X3620, ctx->r23) = ctx->r3;
    // 0x800FA848: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800FA84C:
    // 0x800FA84C: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800FA850: bne         $v0, $s1, L_800FA800
    if (ctx->r2 != ctx->r17) {
        // 0x800FA854: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800FA800;
    }
    // 0x800FA854: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800FA858:
    // 0x800FA858: lw          $v1, -0x35E0($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X35E0);
    // 0x800FA85C: sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // 0x800FA860: beq         $v0, $zero, L_800FA8D8
    if (ctx->r2 == 0) {
        // 0x800FA864: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_800FA8D8;
    }
    // 0x800FA864: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800FA868: addiu       $v0, $v0, -0x7060
    ctx->r2 = ADD32(ctx->r2, -0X7060);
    // 0x800FA86C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800FA870: addu        $v1, $v1, $v0
    gpr jr_addend_800FA878 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800FA874: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800FA878: jr          $v0
    // 0x800FA87C: nop

    switch (jr_addend_800FA878 >> 2) {
        case 0: goto L_800FA8D0; break;
        case 1: goto L_800FA8A0; break;
        case 2: goto L_800FA8D8; break;
        case 3: goto L_800FA8C0; break;
        case 4: goto L_800FA8B0; break;
        case 5: goto L_800FA880; break;
        case 6: goto L_800FA890; break;
        default: switch_error(__func__, 0x800FA878, 0x800A8FA0);
    }
    // 0x800FA87C: nop

L_800FA880:
    // 0x800FA880: jal         0x800FBBA0
    // 0x800FA884: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    noopHandler_800FBBA0(rdram, ctx);
        goto after_7;
    // 0x800FA884: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_7:
    // 0x800FA888: j           L_800FA8DC
    // 0x800FA88C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
        goto L_800FA8DC;
    // 0x800FA88C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800FA890:
    // 0x800FA890: jal         0x800FBBA8
    // 0x800FA894: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800FBBA8(rdram, ctx);
        goto after_8;
    // 0x800FA894: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_8:
    // 0x800FA898: j           L_800FA8DC
    // 0x800FA89C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
        goto L_800FA8DC;
    // 0x800FA89C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800FA8A0:
    // 0x800FA8A0: jal         0x800FBC4C
    // 0x800FA8A4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    tickMissionObjectives(rdram, ctx);
        goto after_9;
    // 0x800FA8A4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_9:
    // 0x800FA8A8: j           L_800FA8DC
    // 0x800FA8AC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
        goto L_800FA8DC;
    // 0x800FA8AC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800FA8B0:
    // 0x800FA8B0: jal         0x800FBAE8
    // 0x800FA8B4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    requestSpeechResponseMode2(rdram, ctx);
        goto after_10;
    // 0x800FA8B4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_10:
    // 0x800FA8B8: j           L_800FA8DC
    // 0x800FA8BC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
        goto L_800FA8DC;
    // 0x800FA8BC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800FA8C0:
    // 0x800FA8C0: jal         0x800FBB44
    // 0x800FA8C4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    requestSpeechResponseMode1(rdram, ctx);
        goto after_11;
    // 0x800FA8C4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_11:
    // 0x800FA8C8: j           L_800FA8DC
    // 0x800FA8CC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
        goto L_800FA8DC;
    // 0x800FA8CC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800FA8D0:
    // 0x800FA8D0: jal         0x800FADEC
    // 0x800FA8D4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800FADEC(rdram, ctx);
        goto after_12;
    // 0x800FA8D4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_12:
L_800FA8D8:
    // 0x800FA8D8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800FA8DC:
    // 0x800FA8DC: lw          $v0, -0x35E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E4);
    // 0x800FA8E0: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800FA8E4: bne         $v0, $zero, L_800FAA44
    if (ctx->r2 != 0) {
        // 0x800FA8E8: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_800FAA44;
    }
    // 0x800FA8E8: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x800FA8EC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FA8F0: lwc1        $f2, 0xBA4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XBA4);
    // 0x800FA8F4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800FA8F8: add.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f20.fl;
    // 0x800FA8FC: lwc1        $f0, -0x361C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, -0X361C);
    // 0x800FA900: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FA904: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x800FA908: addiu       $a1, $v0, -0x3608
    ctx->r5 = ADD32(ctx->r2, -0X3608);
    // 0x800FA90C: swc1        $f2, 0xBA4($a0)
    MEM_W(0XBA4, ctx->r4) = ctx->f2.u32l;
    // 0x800FA910: swc1        $f0, -0x361C($v1)
    MEM_W(-0X361C, ctx->r3) = ctx->f0.u32l;
L_800FA914:
    // 0x800FA914: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800FA918: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x800FA91C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800FA920: slti        $v0, $s3, 0x8
    ctx->r2 = SIGNED(ctx->r19) < 0X8 ? 1 : 0;
    // 0x800FA924: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x800FA928: bne         $v0, $zero, L_800FA914
    if (ctx->r2 != 0) {
        // 0x800FA92C: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_800FA914;
    }
    // 0x800FA92C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800FA930: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FA934: lw          $v0, -0x35E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E0);
    // 0x800FA938: bne         $v0, $zero, L_800FA94C
    if (ctx->r2 != 0) {
        // 0x800FA93C: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_800FA94C;
    }
    // 0x800FA93C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800FA940: jal         0x800C7358
    // 0x800FA944: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    checkComplexObjectives(rdram, ctx);
        goto after_13;
    // 0x800FA944: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_13:
    // 0x800FA948: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_800FA94C:
    // 0x800FA94C: addiu       $s0, $sp, 0x88
    ctx->r16 = ADD32(ctx->r29, 0X88);
    // 0x800FA950: lhu         $a0, 0x6($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X6);
    // 0x800FA954: jal         0x8003E8DC
    // 0x800FA958: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_14;
    // 0x800FA958: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_14:
    // 0x800FA95C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800FA960: lhu         $a0, 0x8($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X8);
    // 0x800FA964: jal         0x8003E8DC
    // 0x800FA968: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_15;
    // 0x800FA968: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_15:
    // 0x800FA96C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800FA970: lhu         $a0, 0x2($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X2);
    // 0x800FA974: jal         0x8003E8DC
    // 0x800FA978: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_16;
    // 0x800FA978: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_16:
    // 0x800FA97C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800FA980: lhu         $a0, 0x14($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X14);
    // 0x800FA984: jal         0x8003E8DC
    // 0x800FA988: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_17;
    // 0x800FA988: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_17:
    // 0x800FA98C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800FA990: lhu         $a0, 0xA($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0XA);
    // 0x800FA994: jal         0x8003E8DC
    // 0x800FA998: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_18;
    // 0x800FA998: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_18:
    // 0x800FA99C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800FA9A0: lhu         $a0, -0x6AA0($fp)
    ctx->r4 = MEM_HU(ctx->r30, -0X6AA0);
    // 0x800FA9A4: jal         0x8003E8DC
    // 0x800FA9A8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_19;
    // 0x800FA9A8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_19:
    // 0x800FA9AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800FA9B0: lhu         $a0, 0xC($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0XC);
    // 0x800FA9B4: jal         0x8003E8DC
    // 0x800FA9B8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_20;
    // 0x800FA9B8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_20:
    // 0x800FA9BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800FA9C0: lhu         $a0, 0x10($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X10);
    // 0x800FA9C4: jal         0x8003E8DC
    // 0x800FA9C8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_21;
    // 0x800FA9C8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_21:
    // 0x800FA9CC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800FA9D0: lhu         $a0, 0xE($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0XE);
    // 0x800FA9D4: jal         0x8003E8DC
    // 0x800FA9D8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_22;
    // 0x800FA9D8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_22:
    // 0x800FA9DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800FA9E0: lhu         $a0, 0x12($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X12);
    // 0x800FA9E4: jal         0x8003E8DC
    // 0x800FA9E8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_23;
    // 0x800FA9E8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_23:
    // 0x800FA9EC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800FA9F0: lhu         $a0, 0x3E($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X3E);
    // 0x800FA9F4: jal         0x8003E8DC
    // 0x800FA9F8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_24;
    // 0x800FA9F8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_24:
    // 0x800FA9FC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800FAA00: lhu         $a0, 0x36($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X36);
    // 0x800FAA04: jal         0x8003E8DC
    // 0x800FAA08: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_25;
    // 0x800FAA08: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_25:
    // 0x800FAA0C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800FAA10: lhu         $a0, 0x38($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X38);
    // 0x800FAA14: jal         0x8003E8DC
    // 0x800FAA18: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_26;
    // 0x800FAA18: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_26:
    // 0x800FAA1C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800FAA20: lhu         $a0, 0x3C($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X3C);
    // 0x800FAA24: jal         0x8003E8DC
    // 0x800FAA28: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_27;
    // 0x800FAA28: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_27:
    // 0x800FAA2C: jal         0x80045B60
    // 0x800FAA30: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80045B60(rdram, ctx);
        goto after_28;
    // 0x800FAA30: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_28:
    // 0x800FAA34: jal         0x800F9FD0
    // 0x800FAA38: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    checkObjectiveHandles(rdram, ctx);
        goto after_29;
    // 0x800FAA38: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_29:
    // 0x800FAA3C: j           L_800FAA50
    // 0x800FAA40: nop

        goto L_800FAA50;
    // 0x800FAA40: nop

L_800FAA44:
    // 0x800FAA44: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800FAA48: jal         0x80045B60
    // 0x800FAA4C: nop

    func_80045B60(rdram, ctx);
        goto after_30;
    // 0x800FAA4C: nop

    after_30:
L_800FAA50:
    // 0x800FAA50: jal         0x80067300
    // 0x800FAA54: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    tickSpeechSubsystem(rdram, ctx);
        goto after_31;
    // 0x800FAA54: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_31:
    // 0x800FAA58: jal         0x80055CB0
    // 0x800FAA5C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    tickVoiceSubtitleDisplay(rdram, ctx);
        goto after_32;
    // 0x800FAA5C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_32:
    // 0x800FAA60: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800FAA64: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    // 0x800FAA68: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x800FAA6C: lhu         $a0, 0x16($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X16);
    // 0x800FAA70: jal         0x8003E8DC
    // 0x800FAA74: addiu       $s2, $sp, 0x38
    ctx->r18 = ADD32(ctx->r29, 0X38);
    slotDispatcherIter(rdram, ctx);
        goto after_33;
    // 0x800FAA74: addiu       $s2, $sp, 0x38
    ctx->r18 = ADD32(ctx->r29, 0X38);
    after_33:
    // 0x800FAA78: jal         0x8005010C
    // 0x800FAA7C: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    func_8005010C(rdram, ctx);
        goto after_34;
    // 0x800FAA7C: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    after_34:
    // 0x800FAA80: jal         0x80053700
    // 0x800FAA84: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80053700(rdram, ctx);
        goto after_35;
    // 0x800FAA84: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_35:
    // 0x800FAA88: jal         0x800666DC
    // 0x800FAA8C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    updateAudioListenerVelocity(rdram, ctx);
        goto after_36;
    // 0x800FAA8C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_36:
    // 0x800FAA90: jal         0x800EF2F8
    // 0x800FAA94: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800EF2F8(rdram, ctx);
        goto after_37;
    // 0x800FAA94: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_37:
    // 0x800FAA98: jal         0x80047E0C
    // 0x800FAA9C: nop

    lookupActivePlayerCraftGridCell(rdram, ctx);
        goto after_38;
    // 0x800FAA9C: nop

    after_38:
    // 0x800FAAA0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800FAAA4: lw          $v1, -0x72F0($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X72F0);
    // 0x800FAAA8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800FAAAC: jal         0x8000A86C
    // 0x800FAAB0: sw          $v1, -0x72F0($v0)
    MEM_W(-0X72F0, ctx->r2) = ctx->r3;
    waitForPrevFrameDone(rdram, ctx);
        goto after_39;
    // 0x800FAAB0: sw          $v1, -0x72F0($v0)
    MEM_W(-0X72F0, ctx->r2) = ctx->r3;
    after_39:
    // 0x800FAAB4: jal         0x8000A6CC
    // 0x800FAAB8: nop

    frameStartReset(rdram, ctx);
        goto after_40;
    // 0x800FAAB8: nop

    after_40:
    // 0x800FAABC: jal         0x8005368C
    // 0x800FAAC0: nop

    func_8005368C(rdram, ctx);
        goto after_41;
    // 0x800FAAC0: nop

    after_41:
    // 0x800FAAC4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800FAAC8: addiu       $s1, $v0, -0x72E8
    ctx->r17 = ADD32(ctx->r2, -0X72E8);
L_800FAACC:
    // 0x800FAACC: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x800FAAD0: beq         $v0, $zero, L_800FAC90
    if (ctx->r2 == 0) {
        // 0x800FAAD4: addiu       $v0, $s1, 0x8
        ctx->r2 = ADD32(ctx->r17, 0X8);
            goto L_800FAC90;
    }
    // 0x800FAAD4: addiu       $v0, $s1, 0x8
    ctx->r2 = ADD32(ctx->r17, 0X8);
    // 0x800FAAD8: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800FAADC: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800FAAE0: addiu       $v0, $s1, 0x64
    ctx->r2 = ADD32(ctx->r17, 0X64);
    // 0x800FAAE4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800FAAE8: addiu       $v0, $s1, 0x68
    ctx->r2 = ADD32(ctx->r17, 0X68);
    // 0x800FAAEC: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x800FAAF0: addiu       $v0, $s1, 0x6C
    ctx->r2 = ADD32(ctx->r17, 0X6C);
    // 0x800FAAF4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x800FAAF8: addiu       $v0, $s1, 0x70
    ctx->r2 = ADD32(ctx->r17, 0X70);
    // 0x800FAAFC: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x800FAB00: addiu       $v0, $s1, 0x74
    ctx->r2 = ADD32(ctx->r17, 0X74);
    // 0x800FAB04: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x800FAB08: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x800FAB0C: addiu       $v0, $s1, 0x7C
    ctx->r2 = ADD32(ctx->r17, 0X7C);
    // 0x800FAB10: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x800FAB14: sw          $v0, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->r2;
    // 0x800FAB18: jal         0x80059D18
    // 0x800FAB1C: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    extractOrthonormalFrameFromStruct(rdram, ctx);
        goto after_42;
    // 0x800FAB1C: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_42:
    // 0x800FAB20: addiu       $s0, $s1, 0xE8
    ctx->r16 = ADD32(ctx->r17, 0XE8);
    // 0x800FAB24: sw          $zero, 0xA8($s1)
    MEM_W(0XA8, ctx->r17) = 0;
    // 0x800FAB28: sw          $zero, 0xA4($s1)
    MEM_W(0XA4, ctx->r17) = 0;
    // 0x800FAB2C: sw          $zero, 0xA0($s1)
    MEM_W(0XA0, ctx->r17) = 0;
    // 0x800FAB30: sw          $zero, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = 0;
    // 0x800FAB34: sw          $zero, 0xB0($s1)
    MEM_W(0XB0, ctx->r17) = 0;
    // 0x800FAB38: sw          $s0, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->r16;
    // 0x800FAB3C: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x800FAB40: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x800FAB44: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x800FAB48: jal         0x8001CAC4
    // 0x800FAB4C: addiu       $a0, $s1, 0xB8
    ctx->r4 = ADD32(ctx->r17, 0XB8);
    setVec3At0x24(rdram, ctx);
        goto after_43;
    // 0x800FAB4C: addiu       $a0, $s1, 0xB8
    ctx->r4 = ADD32(ctx->r17, 0XB8);
    after_43:
    // 0x800FAB50: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800FAB54: lui         $v0, 0x4900
    ctx->r2 = S32(0X4900 << 16);
    // 0x800FAB58: sw          $zero, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = 0;
    // 0x800FAB5C: sw          $zero, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = 0;
    // 0x800FAB60: sw          $zero, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = 0;
    // 0x800FAB64: sw          $v0, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->r2;
    // 0x800FAB68: sw          $zero, 0xF8($s1)
    MEM_W(0XF8, ctx->r17) = 0;
    // 0x800FAB6C: sw          $zero, 0x100($s1)
    MEM_W(0X100, ctx->r17) = 0;
    // 0x800FAB70: sw          $zero, 0xFC($s1)
    MEM_W(0XFC, ctx->r17) = 0;
    // 0x800FAB74: jal         0x8000A85C
    // 0x800FAB78: sw          $zero, 0x108($s1)
    MEM_W(0X108, ctx->r17) = 0;
    clearStructPair2C30(rdram, ctx);
        goto after_44;
    // 0x800FAB78: sw          $zero, 0x108($s1)
    MEM_W(0X108, ctx->r17) = 0;
    after_44:
    // 0x800FAB7C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800FAB80: lhu         $a0, 0x6($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X6);
    // 0x800FAB84: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x800FAB88: jal         0x8003E8DC
    // 0x800FAB8C: sw          $s0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r16;
    slotDispatcherIter(rdram, ctx);
        goto after_45;
    // 0x800FAB8C: sw          $s0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r16;
    after_45:
    // 0x800FAB90: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800FAB94: lhu         $a0, 0x8($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X8);
    // 0x800FAB98: jal         0x8003E8DC
    // 0x800FAB9C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_46;
    // 0x800FAB9C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_46:
    // 0x800FABA0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800FABA4: lhu         $a0, 0x2($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X2);
    // 0x800FABA8: jal         0x8003E8DC
    // 0x800FABAC: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_47;
    // 0x800FABAC: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_47:
    // 0x800FABB0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800FABB4: lhu         $a0, 0xA($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0XA);
    // 0x800FABB8: jal         0x8003E8DC
    // 0x800FABBC: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_48;
    // 0x800FABBC: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_48:
    // 0x800FABC0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800FABC4: lhu         $a0, -0x6AA0($fp)
    ctx->r4 = MEM_HU(ctx->r30, -0X6AA0);
    // 0x800FABC8: jal         0x8003E8DC
    // 0x800FABCC: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_49;
    // 0x800FABCC: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_49:
    // 0x800FABD0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800FABD4: lhu         $a0, 0xC($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0XC);
    // 0x800FABD8: jal         0x8003E8DC
    // 0x800FABDC: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_50;
    // 0x800FABDC: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_50:
    // 0x800FABE0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800FABE4: lhu         $a0, 0x10($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X10);
    // 0x800FABE8: jal         0x8003E8DC
    // 0x800FABEC: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_51;
    // 0x800FABEC: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_51:
    // 0x800FABF0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800FABF4: lhu         $a0, 0xE($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0XE);
    // 0x800FABF8: jal         0x8003E8DC
    // 0x800FABFC: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_52;
    // 0x800FABFC: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_52:
    // 0x800FAC00: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800FAC04: lhu         $a0, 0x12($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X12);
    // 0x800FAC08: jal         0x8003E8DC
    // 0x800FAC0C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_53;
    // 0x800FAC0C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_53:
    // 0x800FAC10: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800FAC14: lhu         $a0, 0x14($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X14);
    // 0x800FAC18: jal         0x8003E8DC
    // 0x800FAC1C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_54;
    // 0x800FAC1C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_54:
    // 0x800FAC20: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800FAC24: lhu         $a0, 0x34($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X34);
    // 0x800FAC28: jal         0x8003E8DC
    // 0x800FAC2C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_55;
    // 0x800FAC2C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_55:
    // 0x800FAC30: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800FAC34: lhu         $a0, 0x16($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X16);
    // 0x800FAC38: jal         0x8003E8DC
    // 0x800FAC3C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_56;
    // 0x800FAC3C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_56:
    // 0x800FAC40: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800FAC44: lw          $v0, -0x7DA0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DA0);
    // 0x800FAC48: bne         $v0, $s6, L_800FAC68
    if (ctx->r2 != ctx->r22) {
        // 0x800FAC4C: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_800FAC68;
    }
    // 0x800FAC4C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800FAC50: lhu         $v1, 0xBA2($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0XBA2);
    // 0x800FAC54: beq         $v1, $v0, L_800FAC68
    if (ctx->r3 == ctx->r2) {
        // 0x800FAC58: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_800FAC68;
    }
    // 0x800FAC58: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x800FAC5C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800FAC60: jal         0x8003E8DC
    // 0x800FAC64: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_57;
    // 0x800FAC64: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_57:
L_800FAC68:
    // 0x800FAC68: jal         0x80055B8C
    // 0x800FAC6C: addiu       $a0, $s1, 0x8
    ctx->r4 = ADD32(ctx->r17, 0X8);
    func_80055B8C(rdram, ctx);
        goto after_58;
    // 0x800FAC6C: addiu       $a0, $s1, 0x8
    ctx->r4 = ADD32(ctx->r17, 0X8);
    after_58:
    // 0x800FAC70: lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X8);
    // 0x800FAC74: beq         $v1, $zero, L_800FAC84
    if (ctx->r3 == 0) {
        // 0x800FAC78: sw          $v1, 0x9C($s1)
        MEM_W(0X9C, ctx->r17) = ctx->r3;
            goto L_800FAC84;
    }
    // 0x800FAC78: sw          $v1, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->r3;
    // 0x800FAC7C: addiu       $v0, $s1, 0x9C
    ctx->r2 = ADD32(ctx->r17, 0X9C);
    // 0x800FAC80: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800FAC84:
    // 0x800FAC84: addiu       $v0, $s1, 0x9C
    ctx->r2 = ADD32(ctx->r17, 0X9C);
    // 0x800FAC88: sw          $zero, 0xA0($s1)
    MEM_W(0XA0, ctx->r17) = 0;
    // 0x800FAC8C: sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
L_800FAC90:
    // 0x800FAC90: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800FAC94: blez        $s3, L_800FAACC
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800FAC98: addiu       $s1, $s1, 0x144
        ctx->r17 = ADD32(ctx->r17, 0X144);
            goto L_800FAACC;
    }
    // 0x800FAC98: addiu       $s1, $s1, 0x144
    ctx->r17 = ADD32(ctx->r17, 0X144);
    // 0x800FAC9C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FACA0: lw          $v0, -0x35E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E4);
    // 0x800FACA4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800FACA8: bne         $v0, $zero, L_800FACC0
    if (ctx->r2 != 0) {
        // 0x800FACAC: nop
    
            goto L_800FACC0;
    }
    // 0x800FACAC: nop

    // 0x800FACB0: jal         0x80054650
    // 0x800FACB4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    tickWrappingTimerAccumulatorList(rdram, ctx);
        goto after_59;
    // 0x800FACB4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_59:
    // 0x800FACB8: jal         0x80054DC8
    // 0x800FACBC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80054DC8(rdram, ctx);
        goto after_60;
    // 0x800FACBC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_60:
L_800FACC0:
    // 0x800FACC0: jal         0x80046484
    // 0x800FACC4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80046484(rdram, ctx);
        goto after_61;
    // 0x800FACC4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_61:
    // 0x800FACC8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FACCC: lw          $v0, -0x3618($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3618);
    // 0x800FACD0: blez        $v0, L_800FAD58
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800FACD4: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800FAD58;
    }
    // 0x800FACD4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800FACD8: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800FACDC: jal         0x80017A90
    // 0x800FACE0: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    setFrameLevelStateBytes(rdram, ctx);
        goto after_62;
    // 0x800FACE0: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_62:
    // 0x800FACE4: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x800FACE8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800FACEC: addiu       $s0, $v0, -0x72E8
    ctx->r16 = ADD32(ctx->r2, -0X72E8);
L_800FACF0:
    // 0x800FACF0: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800FACF4: beq         $v0, $zero, L_800FAD38
    if (ctx->r2 == 0) {
        // 0x800FACF8: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800FAD38;
    }
    // 0x800FACF8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800FACFC: addiu       $v0, $s0, 0x7C
    ctx->r2 = ADD32(ctx->r16, 0X7C);
    // 0x800FAD00: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
    // 0x800FAD04: sw          $zero, 0x68($s0)
    MEM_W(0X68, ctx->r16) = 0;
    // 0x800FAD08: sw          $zero, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = 0;
    // 0x800FAD0C: sw          $zero, 0x70($s0)
    MEM_W(0X70, ctx->r16) = 0;
    // 0x800FAD10: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
    // 0x800FAD14: jal         0x80009B48
    // 0x800FAD18: sw          $v0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r2;
    func_80009B48(rdram, ctx);
        goto after_63;
    // 0x800FAD18: sw          $v0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r2;
    after_63:
    // 0x800FAD1C: jal         0x80017AB0
    // 0x800FAD20: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80017AB0(rdram, ctx);
        goto after_64;
    // 0x800FAD20: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_64:
    // 0x800FAD24: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x800FAD28: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x800FAD2C: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x800FAD30: jal         0x80016C44
    // 0x800FAD34: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    setupCameraMatrices(rdram, ctx);
        goto after_65;
    // 0x800FAD34: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    after_65:
L_800FAD38:
    // 0x800FAD38: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800FAD3C: blez        $s3, L_800FACF0
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800FAD40: addiu       $s0, $s0, 0x144
        ctx->r16 = ADD32(ctx->r16, 0X144);
            goto L_800FACF0;
    }
    // 0x800FAD40: addiu       $s0, $s0, 0x144
    ctx->r16 = ADD32(ctx->r16, 0X144);
    // 0x800FAD44: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800FAD48: lw          $v0, -0x3618($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X3618);
    // 0x800FAD4C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800FAD50: j           L_800FAD7C
    // 0x800FAD54: sw          $v0, -0x3618($v1)
    MEM_W(-0X3618, ctx->r3) = ctx->r2;
        goto L_800FAD7C;
    // 0x800FAD54: sw          $v0, -0x3618($v1)
    MEM_W(-0X3618, ctx->r3) = ctx->r2;
L_800FAD58:
    // 0x800FAD58: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FAD5C: lbu         $a0, 0x6E18($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X6E18);
    // 0x800FAD60: addiu       $v0, $v0, 0x6E18
    ctx->r2 = ADD32(ctx->r2, 0X6E18);
    // 0x800FAD64: lbu         $a1, 0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X1);
    // 0x800FAD68: lbu         $a2, 0x2($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X2);
    // 0x800FAD6C: jal         0x80017A90
    // 0x800FAD70: nop

    setFrameLevelStateBytes(rdram, ctx);
        goto after_66;
    // 0x800FAD70: nop

    after_66:
    // 0x800FAD74: jal         0x80052F94
    // 0x800FAD78: nop

    func_80052F94(rdram, ctx);
        goto after_67;
    // 0x800FAD78: nop

    after_67:
L_800FAD7C:
    // 0x800FAD7C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800FAD80: lw          $v0, -0x7764($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X7764);
    // 0x800FAD84: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800FAD88: jal         0x8000B6F4
    // 0x800FAD8C: sw          $v0, -0x7764($v1)
    MEM_W(-0X7764, ctx->r3) = ctx->r2;
    drawFrameProfilerBars(rdram, ctx);
        goto after_68;
    // 0x800FAD8C: sw          $v0, -0x7764($v1)
    MEM_W(-0X7764, ctx->r3) = ctx->r2;
    after_68:
    // 0x800FAD90: jal         0x8000C07C
    // 0x800FAD94: nop

    submitGfxFrame(rdram, ctx);
        goto after_69;
    // 0x800FAD94: nop

    after_69:
    // 0x800FAD98: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FAD9C: lw          $v0, -0x35E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E4);
    // 0x800FADA0: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // 0x800FADA4: beq         $v0, $zero, L_800FA728
    if (ctx->r2 == 0) {
        // 0x800FADA8: nop
    
            goto L_800FA728;
    }
    // 0x800FADA8: nop

L_800FADAC:
    // 0x800FADAC: jal         0x8000BF60
    // 0x800FADB0: nop

    bufferArbiterProducerScanWait(rdram, ctx);
        goto after_70;
    // 0x800FADB0: nop

    after_70:
    // 0x800FADB4: lw          $ra, 0xB4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XB4);
    // 0x800FADB8: lw          $fp, 0xB0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XB0);
    // 0x800FADBC: lw          $s7, 0xAC($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XAC);
    // 0x800FADC0: lw          $s6, 0xA8($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XA8);
    // 0x800FADC4: lw          $s5, 0xA4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XA4);
    // 0x800FADC8: lw          $s4, 0xA0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XA0);
    // 0x800FADCC: lw          $s3, 0x9C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X9C);
    // 0x800FADD0: lw          $s2, 0x98($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X98);
    // 0x800FADD4: lw          $s1, 0x94($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X94);
    // 0x800FADD8: lw          $s0, 0x90($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X90);
    // 0x800FADDC: ldc1        $f22, 0xC0($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XC0);
    // 0x800FADE0: ldc1        $f20, 0xB8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XB8);
    // 0x800FADE4: jr          $ra
    // 0x800FADE8: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x800FADE8: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void func_800FADEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FADEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FADF0: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x800FADF4: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x800FADF8: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x800FADFC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800FAE00: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FAE04: addiu       $a3, $v0, -0x4058
    ctx->r7 = ADD32(ctx->r2, -0X4058);
    // 0x800FAE08: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FAE0C: addiu       $a2, $v0, -0x41E8
    ctx->r6 = ADD32(ctx->r2, -0X41E8);
    // 0x800FAE10: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FAE14: addiu       $t0, $v0, 0xB88
    ctx->r8 = ADD32(ctx->r2, 0XB88);
    // 0x800FAE18: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FAE1C: addiu       $a1, $v0, 0x7DB8
    ctx->r5 = ADD32(ctx->r2, 0X7DB8);
    // 0x800FAE20: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FAE24: lbu         $t4, 0x7CF4($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X7CF4);
    // 0x800FAE28: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800FAE2C: lbu         $t3, -0x77C8($v0)
    ctx->r11 = MEM_BU(ctx->r2, -0X77C8);
    // 0x800FAE30: addiu       $t5, $zero, 0x1D
    ctx->r13 = ADD32(0, 0X1D);
    // 0x800FAE34: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
L_800FAE38:
    // 0x800FAE38: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800FAE3C: beql        $v0, $zero, L_800FAE94
    if (ctx->r2 == 0) {
        // 0x800FAE40: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_800FAE94;
    }
    goto skip_0;
    // 0x800FAE40: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    skip_0:
    // 0x800FAE44: lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X0);
    // 0x800FAE48: lhu         $v1, 0x0($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X0);
    // 0x800FAE4C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800FAE50: beql        $v0, $zero, L_800FAE94
    if (ctx->r2 == 0) {
        // 0x800FAE54: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_800FAE94;
    }
    goto skip_1;
    // 0x800FAE54: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    skip_1:
    // 0x800FAE58: bnel        $t4, $zero, L_800FAE94
    if (ctx->r12 != 0) {
        // 0x800FAE5C: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_800FAE94;
    }
    goto skip_2;
    // 0x800FAE5C: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    skip_2:
    // 0x800FAE60: bnel        $t3, $zero, L_800FAE94
    if (ctx->r11 != 0) {
        // 0x800FAE64: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_800FAE94;
    }
    goto skip_3;
    // 0x800FAE64: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    skip_3:
    // 0x800FAE68: lw          $v0, -0x3620($t2)
    ctx->r2 = MEM_W(ctx->r10, -0X3620);
    // 0x800FAE6C: sw          $zero, 0x298($a1)
    MEM_W(0X298, ctx->r5) = 0;
    // 0x800FAE70: sw          $t5, 0x29C($a1)
    MEM_W(0X29C, ctx->r5) = ctx->r13;
    // 0x800FAE74: lhu         $v1, 0x0($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X0);
    // 0x800FAE78: lhu         $a0, 0x1A($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X1A);
    // 0x800FAE7C: sb          $t6, -0x76DB($t7)
    MEM_B(-0X76DB, ctx->r15) = ctx->r14;
    // 0x800FAE80: ori         $v0, $v0, 0x10
    ctx->r2 = ctx->r2 | 0X10;
    // 0x800FAE84: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x800FAE88: sw          $v0, -0x3620($t2)
    MEM_W(-0X3620, ctx->r10) = ctx->r2;
    // 0x800FAE8C: sh          $v1, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r3;
    // 0x800FAE90: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
L_800FAE94:
    // 0x800FAE94: addiu       $a2, $a2, 0x24
    ctx->r6 = ADD32(ctx->r6, 0X24);
    // 0x800FAE98: addiu       $t0, $t0, 0x6
    ctx->r8 = ADD32(ctx->r8, 0X6);
    // 0x800FAE9C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800FAEA0: blez        $t1, L_800FAE38
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800FAEA4: addiu       $a1, $a1, 0x2A0
        ctx->r5 = ADD32(ctx->r5, 0X2A0);
            goto L_800FAE38;
    }
    // 0x800FAEA4: addiu       $a1, $a1, 0x2A0
    ctx->r5 = ADD32(ctx->r5, 0X2A0);
    // 0x800FAEA8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FAEAC: lw          $v0, 0xB4C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB4C);
    // 0x800FAEB0: lui         $v1, 0x400
    ctx->r3 = S32(0X400 << 16);
    // 0x800FAEB4: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800FAEB8: beq         $v0, $zero, L_800FAF00
    if (ctx->r2 == 0) {
        // 0x800FAEBC: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800FAF00;
    }
    // 0x800FAEBC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FAEC0: addiu       $v0, $v0, 0x7DB8
    ctx->r2 = ADD32(ctx->r2, 0X7DB8);
    // 0x800FAEC4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800FAEC8: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800FAECC: lwc1        $f0, 0x27C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X27C);
    // 0x800FAED0: lwc1        $f2, 0x280($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X280);
    // 0x800FAED4: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x800FAED8: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x800FAEDC: sdc1        $f0, 0x10($sp)
    CHECK_FR(ctx, 0);
    SD(ctx->f0.u64, 0X10, ctx->r29);
    // 0x800FAEE0: sdc1        $f2, 0x18($sp)
    CHECK_FR(ctx, 2);
    SD(ctx->f2.u64, 0X18, ctx->r29);
    // 0x800FAEE4: lwc1        $f0, 0x278($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X278);
    // 0x800FAEE8: addiu       $a0, $a0, -0x77C0
    ctx->r4 = ADD32(ctx->r4, -0X77C0);
    // 0x800FAEEC: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800FAEF0: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800FAEF4: mfc1        $a2, $f5
    ctx->r6 = (int32_t)ctx->f_odd[(5 - 1) * 2];
    // 0x800FAEF8: jal         0x80033CC4
    // 0x800FAEFC: addiu       $a1, $a1, -0x7044
    ctx->r5 = ADD32(ctx->r5, -0X7044);
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800FAEFC: addiu       $a1, $a1, -0x7044
    ctx->r5 = ADD32(ctx->r5, -0X7044);
    after_0:
L_800FAF00:
    // 0x800FAF00: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800FAF04: jr          $ra
    // 0x800FAF08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800FAF08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800FAF0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FAF0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FAF10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FAF14: jal         0x80007CB8
    // 0x800FAF18: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80007CB8(rdram, ctx);
        goto after_0;
    // 0x800FAF18: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x800FAF1C: slti        $v0, $v0, 0x3A98
    ctx->r2 = SIGNED(ctx->r2) < 0X3A98 ? 1 : 0;
    // 0x800FAF20: bne         $v0, $zero, L_800FB04C
    if (ctx->r2 != 0) {
        // 0x800FAF24: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800FB04C;
    }
    // 0x800FAF24: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800FAF28: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800FAF2C: lw          $v0, -0x35E0($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X35E0);
    // 0x800FAF30: bne         $v0, $zero, L_800FB04C
    if (ctx->r2 != 0) {
        // 0x800FAF34: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800FB04C;
    }
    // 0x800FAF34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FAF38: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800FAF3C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FAF40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800FAF44: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800FAF48: sw          $v0, -0x35E0($v1)
    MEM_W(-0X35E0, ctx->r3) = ctx->r2;
    // 0x800FAF4C: lw          $v1, -0x35E4($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X35E4);
    // 0x800FAF50: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800FAF54: sb          $a1, 0x7CF4($s0)
    MEM_B(0X7CF4, ctx->r16) = ctx->r5;
    // 0x800FAF58: sb          $a1, -0x76DB($v0)
    MEM_B(-0X76DB, ctx->r2) = ctx->r5;
    // 0x800FAF5C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800FAF60: ori         $v0, $v1, 0x1
    ctx->r2 = ctx->r3 | 0X1;
    // 0x800FAF64: sw          $v0, -0x35E4($a0)
    MEM_W(-0X35E4, ctx->r4) = ctx->r2;
    // 0x800FAF68: srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // 0x800FAF6C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x800FAF70: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800FAF74: ori         $v1, $v1, 0x101
    ctx->r3 = ctx->r3 | 0X101;
    // 0x800FAF78: sb          $v0, -0x360F($a1)
    MEM_B(-0X360F, ctx->r5) = ctx->r2;
    // 0x800FAF7C: jal         0x80002D28
    // 0x800FAF80: sw          $v1, -0x35E4($a0)
    MEM_W(-0X35E4, ctx->r4) = ctx->r3;
    func_80002D28(rdram, ctx);
        goto after_1;
    // 0x800FAF80: sw          $v1, -0x35E4($a0)
    MEM_W(-0X35E4, ctx->r4) = ctx->r3;
    after_1:
    // 0x800FAF84: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x800FAF88: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    // 0x800FAF8C: jal         0x8008E4E4
    // 0x800FAF90: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    func_8008E4E4(rdram, ctx);
        goto after_2;
    // 0x800FAF90: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    after_2:
    // 0x800FAF94: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800FAF98: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    // 0x800FAF9C: jal         0x8008E4E4
    // 0x800FAFA0: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    func_8008E4E4(rdram, ctx);
        goto after_3;
    // 0x800FAFA0: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    after_3:
    // 0x800FAFA4: jal         0x800679A4
    // 0x800FAFA8: nop

    func_800679A4(rdram, ctx);
        goto after_4;
    // 0x800FAFA8: nop

    after_4:
    // 0x800FAFAC: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x800FAFB0: addiu       $t3, $zero, 0x1D
    ctx->r11 = ADD32(0, 0X1D);
    // 0x800FAFB4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FAFB8: addiu       $a2, $v0, -0x4058
    ctx->r6 = ADD32(ctx->r2, -0X4058);
    // 0x800FAFBC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FAFC0: addiu       $a1, $v0, -0x41E8
    ctx->r5 = ADD32(ctx->r2, -0X41E8);
    // 0x800FAFC4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FAFC8: addiu       $a3, $v0, 0xB88
    ctx->r7 = ADD32(ctx->r2, 0XB88);
    // 0x800FAFCC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FAFD0: addiu       $a0, $v0, 0x7DB8
    ctx->r4 = ADD32(ctx->r2, 0X7DB8);
    // 0x800FAFD4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800FAFD8: lbu         $t2, 0x7CF4($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X7CF4);
    // 0x800FAFDC: lbu         $t1, -0x77C8($v0)
    ctx->r9 = MEM_BU(ctx->r2, -0X77C8);
    // 0x800FAFE0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800FAFE4: sb          $zero, -0x6371($v0)
    MEM_B(-0X6371, ctx->r2) = 0;
L_800FAFE8:
    // 0x800FAFE8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800FAFEC: beql        $v0, $zero, L_800FB034
    if (ctx->r2 == 0) {
        // 0x800FAFF0: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_800FB034;
    }
    goto skip_0;
    // 0x800FAFF0: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    skip_0:
    // 0x800FAFF4: lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X0);
    // 0x800FAFF8: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x800FAFFC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800FB000: beql        $v0, $zero, L_800FB034
    if (ctx->r2 == 0) {
        // 0x800FB004: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_800FB034;
    }
    goto skip_1;
    // 0x800FB004: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    skip_1:
    // 0x800FB008: bnel        $t2, $zero, L_800FB034
    if (ctx->r10 != 0) {
        // 0x800FB00C: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_800FB034;
    }
    goto skip_2;
    // 0x800FB00C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    skip_2:
    // 0x800FB010: bnel        $t1, $zero, L_800FB034
    if (ctx->r9 != 0) {
        // 0x800FB014: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_800FB034;
    }
    goto skip_3;
    // 0x800FB014: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    skip_3:
    // 0x800FB018: sw          $zero, 0x298($a0)
    MEM_W(0X298, ctx->r4) = 0;
    // 0x800FB01C: sw          $t3, 0x29C($a0)
    MEM_W(0X29C, ctx->r4) = ctx->r11;
    // 0x800FB020: lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X0);
    // 0x800FB024: lhu         $v1, 0x1A($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X1A);
    // 0x800FB028: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800FB02C: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x800FB030: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
L_800FB034:
    // 0x800FB034: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    // 0x800FB038: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    // 0x800FB03C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800FB040: blez        $t0, L_800FAFE8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800FB044: addiu       $a0, $a0, 0x2A0
        ctx->r4 = ADD32(ctx->r4, 0X2A0);
            goto L_800FAFE8;
    }
    // 0x800FB044: addiu       $a0, $a0, 0x2A0
    ctx->r4 = ADD32(ctx->r4, 0X2A0);
    // 0x800FB048: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800FB04C:
    // 0x800FB04C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FB050: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800FB054: jr          $ra
    // 0x800FB058: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800FB058: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800FB05C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB05C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800FB060: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800FB064: lw          $v1, -0x35E0($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X35E0);
    // 0x800FB068: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800FB06C: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800FB070: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800FB074: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800FB078: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800FB07C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800FB080: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800FB084: bne         $v1, $v0, L_800FB168
    if (ctx->r3 != ctx->r2) {
        // 0x800FB088: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_800FB168;
    }
    // 0x800FB088: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800FB08C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800FB090: sw          $zero, -0x35E0($a0)
    MEM_W(-0X35E0, ctx->r4) = 0;
    // 0x800FB094: addiu       $a0, $zero, -0x2
    ctx->r4 = ADD32(0, -0X2);
    // 0x800FB098: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FB09C: lw          $v1, -0x35E4($a1)
    ctx->r3 = MEM_W(ctx->r5, -0X35E4);
    // 0x800FB0A0: lbu         $v0, -0x360F($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X360F);
    // 0x800FB0A4: and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // 0x800FB0A8: beq         $v0, $zero, L_800FB0BC
    if (ctx->r2 == 0) {
        // 0x800FB0AC: sw          $v1, -0x35E4($a1)
        MEM_W(-0X35E4, ctx->r5) = ctx->r3;
            goto L_800FB0BC;
    }
    // 0x800FB0AC: sw          $v1, -0x35E4($a1)
    MEM_W(-0X35E4, ctx->r5) = ctx->r3;
    // 0x800FB0B0: addiu       $v0, $zero, -0x101
    ctx->r2 = ADD32(0, -0X101);
    // 0x800FB0B4: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x800FB0B8: sw          $v0, -0x35E4($a1)
    MEM_W(-0X35E4, ctx->r5) = ctx->r2;
L_800FB0BC:
    // 0x800FB0BC: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    // 0x800FB0C0: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    // 0x800FB0C4: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    // 0x800FB0C8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FB0CC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800FB0D0: sb          $zero, 0x7CF4($s0)
    MEM_B(0X7CF4, ctx->r16) = 0;
    // 0x800FB0D4: jal         0x8008E4E4
    // 0x800FB0D8: sb          $zero, -0x76DB($v0)
    MEM_B(-0X76DB, ctx->r2) = 0;
    func_8008E4E4(rdram, ctx);
        goto after_0;
    // 0x800FB0D8: sb          $zero, -0x76DB($v0)
    MEM_B(-0X76DB, ctx->r2) = 0;
    after_0:
    // 0x800FB0DC: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    // 0x800FB0E0: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    // 0x800FB0E4: jal         0x8008E4E4
    // 0x800FB0E8: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    func_8008E4E4(rdram, ctx);
        goto after_1;
    // 0x800FB0E8: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    after_1:
    // 0x800FB0EC: jal         0x800679C4
    // 0x800FB0F0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    func_800679C4(rdram, ctx);
        goto after_2;
    // 0x800FB0F0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    after_2:
    // 0x800FB0F4: addu        $s5, $s0, $zero
    ctx->r21 = ADD32(ctx->r16, 0);
    // 0x800FB0F8: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x800FB0FC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FB100: addiu       $s0, $v0, -0x4058
    ctx->r16 = ADD32(ctx->r2, -0X4058);
    // 0x800FB104: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FB108: addiu       $s3, $v0, -0x41E8
    ctx->r19 = ADD32(ctx->r2, -0X41E8);
    // 0x800FB10C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FB110: addiu       $s2, $v0, 0x7DB8
    ctx->r18 = ADD32(ctx->r2, 0X7DB8);
L_800FB114:
    // 0x800FB114: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800FB118: beq         $v0, $zero, L_800FB14C
    if (ctx->r2 == 0) {
        // 0x800FB11C: nop
    
            goto L_800FB14C;
    }
    // 0x800FB11C: nop

    // 0x800FB120: lbu         $v0, 0x7CF4($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X7CF4);
    // 0x800FB124: bne         $v0, $zero, L_800FB14C
    if (ctx->r2 != 0) {
        // 0x800FB128: nop
    
            goto L_800FB14C;
    }
    // 0x800FB128: nop

    // 0x800FB12C: lbu         $v0, -0x77C8($s4)
    ctx->r2 = MEM_BU(ctx->r20, -0X77C8);
    // 0x800FB130: bne         $v0, $zero, L_800FB14C
    if (ctx->r2 != 0) {
        // 0x800FB134: nop
    
            goto L_800FB14C;
    }
    // 0x800FB134: nop

    // 0x800FB138: lhu         $v0, 0x1A($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X1A);
    // 0x800FB13C: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x800FB140: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x800FB144: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x800FB148: sh          $v1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r3;
L_800FB14C:
    // 0x800FB14C: jal         0x80003188
    // 0x800FB150: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    func_80003188(rdram, ctx);
        goto after_3;
    // 0x800FB150: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_3:
    // 0x800FB154: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800FB158: addiu       $s3, $s3, 0x24
    ctx->r19 = ADD32(ctx->r19, 0X24);
    // 0x800FB15C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800FB160: blez        $s1, L_800FB114
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800FB164: addiu       $s2, $s2, 0x2A0
        ctx->r18 = ADD32(ctx->r18, 0X2A0);
            goto L_800FB114;
    }
    // 0x800FB164: addiu       $s2, $s2, 0x2A0
    ctx->r18 = ADD32(ctx->r18, 0X2A0);
L_800FB168:
    // 0x800FB168: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x800FB16C: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800FB170: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800FB174: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800FB178: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800FB17C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800FB180: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800FB184: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FB188: jr          $ra
    // 0x800FB18C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800FB18C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800FB190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB190: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FB194: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800FB198: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x800FB19C: lw          $v0, -0x35E0($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X35E0);
    // 0x800FB1A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FB1A4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800FB1A8: beq         $v0, $zero, L_800FB1B8
    if (ctx->r2 == 0) {
        // 0x800FB1AC: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_800FB1B8;
    }
    // 0x800FB1AC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800FB1B0: j           L_800FB2E0
    // 0x800FB1B4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800FB2E0;
    // 0x800FB1B4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800FB1B8:
    // 0x800FB1B8: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x800FB1BC: bne         $a0, $s2, L_800FB1CC
    if (ctx->r4 != ctx->r18) {
        // 0x800FB1C0: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800FB1CC;
    }
    // 0x800FB1C0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800FB1C4: j           L_800FB2CC
    // 0x800FB1C8: sw          $s2, -0x35E0($s1)
    MEM_W(-0X35E0, ctx->r17) = ctx->r18;
        goto L_800FB2CC;
    // 0x800FB1C8: sw          $s2, -0x35E0($s1)
    MEM_W(-0X35E0, ctx->r17) = ctx->r18;
L_800FB1CC:
    // 0x800FB1CC: bne         $a0, $v0, L_800FB1DC
    if (ctx->r4 != ctx->r2) {
        // 0x800FB1D0: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800FB1DC;
    }
    // 0x800FB1D0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FB1D4: j           L_800FB2C8
    // 0x800FB1D8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_800FB2C8;
    // 0x800FB1D8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_800FB1DC:
    // 0x800FB1DC: addiu       $s0, $v0, 0xB40
    ctx->r16 = ADD32(ctx->r2, 0XB40);
    // 0x800FB1E0: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x800FB1E4: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x800FB1E8: beq         $v0, $zero, L_800FB210
    if (ctx->r2 == 0) {
        // 0x800FB1EC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800FB210;
    }
    // 0x800FB1EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FB1F0: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x800FB1F4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800FB1F8: lw          $v1, -0x3620($a2)
    ctx->r3 = MEM_W(ctx->r6, -0X3620);
    // 0x800FB1FC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800FB200: sb          $a0, 0xB14($a1)
    MEM_B(0XB14, ctx->r5) = ctx->r4;
    // 0x800FB204: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800FB208: j           L_800FB2E0
    // 0x800FB20C: sw          $v1, -0x3620($a2)
    MEM_W(-0X3620, ctx->r6) = ctx->r3;
        goto L_800FB2E0;
    // 0x800FB20C: sw          $v1, -0x3620($a2)
    MEM_W(-0X3620, ctx->r6) = ctx->r3;
L_800FB210:
    // 0x800FB210: jal         0x800FEE28
    // 0x800FB214: nop

    func_800FEE28(rdram, ctx);
        goto after_0;
    // 0x800FB214: nop

    after_0:
    // 0x800FB218: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FB21C: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x800FB220: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x800FB224: bne         $v1, $v0, L_800FB244
    if (ctx->r3 != ctx->r2) {
        // 0x800FB228: lui         $v1, 0x40
        ctx->r3 = S32(0X40 << 16);
            goto L_800FB244;
    }
    // 0x800FB228: lui         $v1, 0x40
    ctx->r3 = S32(0X40 << 16);
    // 0x800FB22C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800FB230: lw          $v1, -0x3620($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X3620);
    // 0x800FB234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FB238: ori         $v1, $v1, 0x4
    ctx->r3 = ctx->r3 | 0X4;
    // 0x800FB23C: j           L_800FB2E0
    // 0x800FB240: sw          $v1, -0x3620($a0)
    MEM_W(-0X3620, ctx->r4) = ctx->r3;
        goto L_800FB2E0;
    // 0x800FB240: sw          $v1, -0x3620($a0)
    MEM_W(-0X3620, ctx->r4) = ctx->r3;
L_800FB244:
    // 0x800FB244: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x800FB248: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800FB24C: beq         $v0, $zero, L_800FB270
    if (ctx->r2 == 0) {
        // 0x800FB250: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800FB270;
    }
    // 0x800FB250: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FB254: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800FB258: lbu         $v1, -0x35E8($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X35E8);
    // 0x800FB25C: addiu       $v0, $v0, 0xB10
    ctx->r2 = ADD32(ctx->r2, 0XB10);
    // 0x800FB260: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800FB264: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800FB268: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800FB26C: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_800FB270:
    // 0x800FB270: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FB274: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FB278: lbu         $v1, -0x35E8($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X35E8);
    // 0x800FB27C: addiu       $a0, $a0, 0xB10
    ctx->r4 = ADD32(ctx->r4, 0XB10);
    // 0x800FB280: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800FB284: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800FB288: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800FB28C: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x800FB290: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x800FB294: bnel        $v0, $zero, L_800FB2B4
    if (ctx->r2 != 0) {
        // 0x800FB298: addiu       $a0, $zero, 0x1D
        ctx->r4 = ADD32(0, 0X1D);
            goto L_800FB2B4;
    }
    goto skip_0;
    // 0x800FB298: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    skip_0:
    // 0x800FB29C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800FB2A0: lw          $v0, -0x3620($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X3620);
    // 0x800FB2A4: sb          $s2, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r18;
    // 0x800FB2A8: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x800FB2AC: j           L_800FB2CC
    // 0x800FB2B0: sw          $v0, -0x3620($v1)
    MEM_W(-0X3620, ctx->r3) = ctx->r2;
        goto L_800FB2CC;
    // 0x800FB2B0: sw          $v0, -0x3620($v1)
    MEM_W(-0X3620, ctx->r3) = ctx->r2;
L_800FB2B4:
    // 0x800FB2B4: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    // 0x800FB2B8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800FB2BC: jal         0x800EFC84
    // 0x800FB2C0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800EFC84(rdram, ctx);
        goto after_1;
    // 0x800FB2C0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x800FB2C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800FB2C8:
    // 0x800FB2C8: sw          $v0, -0x35E0($s1)
    MEM_W(-0X35E0, ctx->r17) = ctx->r2;
L_800FB2CC:
    // 0x800FB2CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FB2D0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800FB2D4: sb          $zero, -0x3610($v1)
    MEM_B(-0X3610, ctx->r3) = 0;
    // 0x800FB2D8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800FB2DC: sw          $zero, -0x3614($v1)
    MEM_W(-0X3614, ctx->r3) = 0;
L_800FB2E0:
    // 0x800FB2E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FB2E4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800FB2E8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800FB2EC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800FB2F0: jr          $ra
    // 0x800FB2F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FB2F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800FB2F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB2F8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800FB2FC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FB300: lw          $v1, -0x35E0($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X35E0);
    // 0x800FB304: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800FB308: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800FB30C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800FB310: beq         $v1, $v0, L_800FB320
    if (ctx->r3 == ctx->r2) {
        // 0x800FB314: sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
            goto L_800FB320;
    }
    // 0x800FB314: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800FB318: bne         $v1, $zero, L_800FB49C
    if (ctx->r3 != 0) {
        // 0x800FB31C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800FB49C;
    }
    // 0x800FB31C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800FB320:
    // 0x800FB320: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x800FB324: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800FB328: lw          $a0, -0x13F0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X13F0);
    // 0x800FB32C: lw          $v0, -0x1440($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1440);
    // 0x800FB330: beq         $a0, $v0, L_800FB374
    if (ctx->r4 == ctx->r2) {
        // 0x800FB334: nop
    
            goto L_800FB374;
    }
    // 0x800FB334: nop

    // 0x800FB338: jal         0x80047B48
    // 0x800FB33C: nop

    getLevelDatItemByName(rdram, ctx);
        goto after_0;
    // 0x800FB33C: nop

    after_0:
    // 0x800FB340: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800FB344: lw          $v1, -0x35E4($a1)
    ctx->r3 = MEM_W(ctx->r5, -0X35E4);
    // 0x800FB348: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FB34C: addiu       $t3, $a0, 0x75F8
    ctx->r11 = ADD32(ctx->r4, 0X75F8);
    // 0x800FB350: lw          $t0, 0x10($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X10);
    // 0x800FB354: lw          $t1, 0x14($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X14);
    // 0x800FB358: lw          $t2, 0x18($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X18);
    // 0x800FB35C: sw          $t0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r8;
    // 0x800FB360: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x800FB364: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    // 0x800FB368: ori         $v1, $v1, 0x8
    ctx->r3 = ctx->r3 | 0X8;
    // 0x800FB36C: jal         0x80047E0C
    // 0x800FB370: sw          $v1, -0x35E4($a1)
    MEM_W(-0X35E4, ctx->r5) = ctx->r3;
    lookupActivePlayerCraftGridCell(rdram, ctx);
        goto after_1;
    // 0x800FB370: sw          $v1, -0x35E4($a1)
    MEM_W(-0X35E4, ctx->r5) = ctx->r3;
    after_1:
L_800FB374:
    // 0x800FB374: lw          $a1, -0x13F0($s0)
    ctx->r5 = MEM_W(ctx->r16, -0X13F0);
    // 0x800FB378: jal         0x80052A10
    // 0x800FB37C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80052A10(rdram, ctx);
        goto after_2;
    // 0x800FB37C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // 0x800FB380: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800FB384: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FB388: lwc1        $f12, -0x702C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X702C);
    // 0x800FB38C: jal         0x800457AC
    // 0x800FB390: addiu       $s0, $s0, -0x72E0
    ctx->r16 = ADD32(ctx->r16, -0X72E0);
    func_800457AC(rdram, ctx);
        goto after_3;
    // 0x800FB390: addiu       $s0, $s0, -0x72E0
    ctx->r16 = ADD32(ctx->r16, -0X72E0);
    after_3:
    // 0x800FB394: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FB398: lwc1        $f0, -0x7028($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7028);
    // 0x800FB39C: jal         0x8006B3E0
    // 0x800FB3A0: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    getBootConfigField14(rdram, ctx);
        goto after_4;
    // 0x800FB3A0: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    after_4:
    // 0x800FB3A4: lui         $a0, 0x9249
    ctx->r4 = S32(0X9249 << 16);
    // 0x800FB3A8: ori         $a0, $a0, 0x2493
    ctx->r4 = ctx->r4 | 0X2493;
    // 0x800FB3AC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800FB3B0: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800FB3B4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800FB3B8: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x800FB3BC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800FB3C0: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800FB3C4: mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800FB3C8: mfhi        $t0
    ctx->r8 = hi;
    // 0x800FB3CC: addu        $v0, $t0, $v1
    ctx->r2 = ADD32(ctx->r8, ctx->r3);
    // 0x800FB3D0: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800FB3D4: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x800FB3D8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800FB3DC: jal         0x8006B3E0
    // 0x800FB3E0: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    getBootConfigField14(rdram, ctx);
        goto after_5;
    // 0x800FB3E0: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    after_5:
    // 0x800FB3E4: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
    // 0x800FB3E8: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x800FB3EC: subu        $s0, $s0, $v1
    ctx->r16 = SUB32(ctx->r16, ctx->r3);
    // 0x800FB3F0: srl         $v0, $s0, 31
    ctx->r2 = S32(U32(ctx->r16) >> 31);
    // 0x800FB3F4: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x800FB3F8: jal         0x8006B3D0
    // 0x800FB3FC: sra         $s0, $s0, 1
    ctx->r16 = S32(SIGNED(ctx->r16) >> 1);
    getBootConfigField12(rdram, ctx);
        goto after_6;
    // 0x800FB3FC: sra         $s0, $s0, 1
    ctx->r16 = S32(SIGNED(ctx->r16) >> 1);
    after_6:
    // 0x800FB400: jal         0x8006B3E0
    // 0x800FB404: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    getBootConfigField14(rdram, ctx);
        goto after_7;
    // 0x800FB404: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    after_7:
    // 0x800FB408: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800FB40C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800FB410: addiu       $v1, $s0, 0x1
    ctx->r3 = ADD32(ctx->r16, 0X1);
    // 0x800FB414: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800FB418: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800FB41C: andi        $a2, $s0, 0xFFFF
    ctx->r6 = ctx->r16 & 0XFFFF;
    // 0x800FB420: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x800FB424: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800FB428: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800FB42C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800FB430: jal         0x8000A650
    // 0x800FB434: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    func_8000A650(rdram, ctx);
        goto after_8;
    // 0x800FB434: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_8:
    // 0x800FB438: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800FB43C: jal         0x800561AC
    // 0x800FB440: addiu       $a1, $zero, -0x4
    ctx->r5 = ADD32(0, -0X4);
    func_800561AC(rdram, ctx);
        goto after_9;
    // 0x800FB440: addiu       $a1, $zero, -0x4
    ctx->r5 = ADD32(0, -0X4);
    after_9:
    // 0x800FB444: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FB448: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800FB44C: sw          $zero, -0x4024($v0)
    MEM_W(-0X4024, ctx->r2) = 0;
    // 0x800FB450: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800FB454: sw          $v0, -0x35E0($v1)
    MEM_W(-0X35E0, ctx->r3) = ctx->r2;
    // 0x800FB458: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FB45C: sb          $zero, -0x3610($v0)
    MEM_B(-0X3610, ctx->r2) = 0;
    // 0x800FB460: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FB464: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800FB468: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800FB46C: sw          $zero, -0x3614($v0)
    MEM_W(-0X3614, ctx->r2) = 0;
    // 0x800FB470: lw          $v0, -0x35E4($a1)
    ctx->r2 = MEM_W(ctx->r5, -0X35E4);
    // 0x800FB474: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x800FB478: sw          $v1, -0x3618($a0)
    MEM_W(-0X3618, ctx->r4) = ctx->r3;
    // 0x800FB47C: ori         $v0, $v0, 0x104
    ctx->r2 = ctx->r2 | 0X104;
    // 0x800FB480: jal         0x80048434
    // 0x800FB484: sw          $v0, -0x35E4($a1)
    MEM_W(-0X35E4, ctx->r5) = ctx->r2;
    func_80048434(rdram, ctx);
        goto after_10;
    // 0x800FB484: sw          $v0, -0x35E4($a1)
    MEM_W(-0X35E4, ctx->r5) = ctx->r2;
    after_10:
    // 0x800FB488: jal         0x80057978
    // 0x800FB48C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80057978(rdram, ctx);
        goto after_11;
    // 0x800FB48C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_11:
    // 0x800FB490: jal         0x80100594
    // 0x800FB494: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80100594(rdram, ctx);
        goto after_12;
    // 0x800FB494: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_12:
    // 0x800FB498: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800FB49C:
    // 0x800FB49C: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x800FB4A0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800FB4A4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800FB4A8: jr          $ra
    // 0x800FB4AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800FB4AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800FB4B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB4B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800FB4B4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FB4B8: lw          $v0, 0x7F3C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7F3C);
    // 0x800FB4BC: lui         $v1, 0x38
    ctx->r3 = S32(0X38 << 16);
    // 0x800FB4C0: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800FB4C4: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800FB4C8: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800FB4CC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800FB4D0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800FB4D4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800FB4D8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800FB4DC: beq         $v0, $zero, L_800FB530
    if (ctx->r2 == 0) {
        // 0x800FB4E0: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_800FB530;
    }
    // 0x800FB4E0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800FB4E4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FB4E8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FB4EC: lbu         $v1, -0x35E8($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X35E8);
    // 0x800FB4F0: addiu       $a2, $a0, 0xB10
    ctx->r6 = ADD32(ctx->r4, 0XB10);
    // 0x800FB4F4: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x800FB4F8: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800FB4FC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800FB500: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x800FB504: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x800FB508: bne         $v0, $zero, L_800FB534
    if (ctx->r2 != 0) {
        // 0x800FB50C: lui         $s4, 0x8011
        ctx->r20 = S32(0X8011 << 16);
            goto L_800FB534;
    }
    // 0x800FB50C: lui         $s4, 0x8011
    ctx->r20 = S32(0X8011 << 16);
    // 0x800FB510: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FB514: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800FB518: lw          $a0, -0x3620($v1)
    ctx->r4 = MEM_W(ctx->r3, -0X3620);
    // 0x800FB51C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800FB520: sb          $a1, 0x4($a2)
    MEM_B(0X4, ctx->r6) = ctx->r5;
    // 0x800FB524: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x800FB528: j           L_800FB69C
    // 0x800FB52C: sw          $a0, -0x3620($v1)
    MEM_W(-0X3620, ctx->r3) = ctx->r4;
        goto L_800FB69C;
    // 0x800FB52C: sw          $a0, -0x3620($v1)
    MEM_W(-0X3620, ctx->r3) = ctx->r4;
L_800FB530:
    // 0x800FB530: lui         $s4, 0x8011
    ctx->r20 = S32(0X8011 << 16);
L_800FB534:
    // 0x800FB534: lw          $a0, -0x3620($s4)
    ctx->r4 = MEM_W(ctx->r20, -0X3620);
    // 0x800FB538: andi        $v0, $a0, 0xC
    ctx->r2 = ctx->r4 & 0XC;
    // 0x800FB53C: beq         $v0, $zero, L_800FB584
    if (ctx->r2 == 0) {
        // 0x800FB540: andi        $v0, $a0, 0x4
        ctx->r2 = ctx->r4 & 0X4;
            goto L_800FB584;
    }
    // 0x800FB540: andi        $v0, $a0, 0x4
    ctx->r2 = ctx->r4 & 0X4;
    // 0x800FB544: beq         $v0, $zero, L_800FB550
    if (ctx->r2 == 0) {
        // 0x800FB548: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_800FB550;
    }
    // 0x800FB548: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800FB54C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_800FB550:
    // 0x800FB550: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FB554: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800FB558: sw          $a1, -0x35E0($v1)
    MEM_W(-0X35E0, ctx->r3) = ctx->r5;
    // 0x800FB55C: addiu       $v1, $zero, -0x5
    ctx->r3 = ADD32(0, -0X5);
    // 0x800FB560: and         $v1, $a0, $v1
    ctx->r3 = ctx->r4 & ctx->r3;
    // 0x800FB564: addiu       $a0, $zero, -0x9
    ctx->r4 = ADD32(0, -0X9);
    // 0x800FB568: and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // 0x800FB56C: sw          $v1, -0x3620($s4)
    MEM_W(-0X3620, ctx->r20) = ctx->r3;
    // 0x800FB570: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800FB574: sb          $zero, -0x3610($v1)
    MEM_B(-0X3610, ctx->r3) = 0;
    // 0x800FB578: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800FB57C: j           L_800FB69C
    // 0x800FB580: sw          $zero, -0x3614($v1)
    MEM_W(-0X3614, ctx->r3) = 0;
        goto L_800FB69C;
    // 0x800FB580: sw          $zero, -0x3614($v1)
    MEM_W(-0X3614, ctx->r3) = 0;
L_800FB584:
    // 0x800FB584: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x800FB588: lw          $v0, -0x35E4($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X35E4);
    // 0x800FB58C: addiu       $v1, $zero, -0x9
    ctx->r3 = ADD32(0, -0X9);
    // 0x800FB590: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800FB594: jal         0x800FED40
    // 0x800FB598: sw          $v0, -0x35E4($s1)
    MEM_W(-0X35E4, ctx->r17) = ctx->r2;
    resetTransientPlayerStateFlags(rdram, ctx);
        goto after_0;
    // 0x800FB598: sw          $v0, -0x35E4($s1)
    MEM_W(-0X35E4, ctx->r17) = ctx->r2;
    after_0:
    // 0x800FB59C: jal         0x80100594
    // 0x800FB5A0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80100594(rdram, ctx);
        goto after_1;
    // 0x800FB5A0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // 0x800FB5A4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FB5A8: addiu       $s2, $v0, 0x7DBC
    ctx->r18 = ADD32(ctx->r2, 0X7DBC);
    // 0x800FB5AC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800FB5B0: jal         0x800AFE4C
    // 0x800FB5B4: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    loadPlayerStartPosition(rdram, ctx);
        goto after_2;
    // 0x800FB5B4: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    after_2:
    // 0x800FB5B8: jal         0x80052EC0
    // 0x800FB5BC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80052EC0(rdram, ctx);
        goto after_3;
    // 0x800FB5BC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_3:
    // 0x800FB5C0: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800FB5C4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FB5C8: lwc1        $f12, -0x7024($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7024);
    // 0x800FB5CC: jal         0x800457AC
    // 0x800FB5D0: addiu       $s0, $s0, -0x72E0
    ctx->r16 = ADD32(ctx->r16, -0X72E0);
    func_800457AC(rdram, ctx);
        goto after_4;
    // 0x800FB5D0: addiu       $s0, $s0, -0x72E0
    ctx->r16 = ADD32(ctx->r16, -0X72E0);
    after_4:
    // 0x800FB5D4: jal         0x8006B3E0
    // 0x800FB5D8: nop

    getBootConfigField14(rdram, ctx);
        goto after_5;
    // 0x800FB5D8: nop

    after_5:
    // 0x800FB5DC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FB5E0: lwc1        $f0, -0x7020($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7020);
    // 0x800FB5E4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800FB5E8: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x800FB5EC: jal         0x8000A6BC
    // 0x800FB5F0: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    func_8000A6BC(rdram, ctx);
        goto after_6;
    // 0x800FB5F0: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    after_6:
    // 0x800FB5F4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FB5F8: lbu         $v1, 0xB41($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB41);
    // 0x800FB5FC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800FB600: beq         $v1, $v0, L_800FB60C
    if (ctx->r3 == ctx->r2) {
        // 0x800FB604: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800FB60C;
    }
    // 0x800FB604: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800FB608: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
L_800FB60C:
    // 0x800FB60C: jal         0x800561AC
    // 0x800FB610: addiu       $a1, $zero, -0xA
    ctx->r5 = ADD32(0, -0XA);
    func_800561AC(rdram, ctx);
        goto after_7;
    // 0x800FB610: addiu       $a1, $zero, -0xA
    ctx->r5 = ADD32(0, -0XA);
    after_7:
    // 0x800FB614: lui         $s5, 0x8011
    ctx->r21 = S32(0X8011 << 16);
    // 0x800FB618: lui         $s3, 0x8011
    ctx->r19 = S32(0X8011 << 16);
    // 0x800FB61C: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800FB620: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800FB624: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800FB628: sw          $v0, -0x3618($v1)
    MEM_W(-0X3618, ctx->r3) = ctx->r2;
    // 0x800FB62C: lw          $v0, -0x35E4($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X35E4);
    // 0x800FB630: addiu       $v1, $zero, -0x5
    ctx->r3 = ADD32(0, -0X5);
    // 0x800FB634: sw          $zero, -0x35E0($s5)
    MEM_W(-0X35E0, ctx->r21) = 0;
    // 0x800FB638: sb          $zero, -0x3610($s3)
    MEM_B(-0X3610, ctx->r19) = 0;
    // 0x800FB63C: sw          $zero, -0x3614($s0)
    MEM_W(-0X3614, ctx->r16) = 0;
    // 0x800FB640: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800FB644: addiu       $v1, $zero, -0x101
    ctx->r3 = ADD32(0, -0X101);
    // 0x800FB648: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800FB64C: jal         0x80048434
    // 0x800FB650: sw          $v0, -0x35E4($s1)
    MEM_W(-0X35E4, ctx->r17) = ctx->r2;
    func_80048434(rdram, ctx);
        goto after_8;
    // 0x800FB650: sw          $v0, -0x35E4($s1)
    MEM_W(-0X35E4, ctx->r17) = ctx->r2;
    after_8:
    // 0x800FB654: jal         0x80057978
    // 0x800FB658: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80057978(rdram, ctx);
        goto after_9;
    // 0x800FB658: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_9:
    // 0x800FB65C: lw          $v0, 0x180($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X180);
    // 0x800FB660: lui         $v1, 0x78
    ctx->r3 = S32(0X78 << 16);
    // 0x800FB664: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800FB668: beq         $v0, $zero, L_800FB69C
    if (ctx->r2 == 0) {
        // 0x800FB66C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800FB69C;
    }
    // 0x800FB66C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FB670: jal         0x800FEE28
    // 0x800FB674: nop

    func_800FEE28(rdram, ctx);
        goto after_10;
    // 0x800FB674: nop

    after_10:
    // 0x800FB678: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FB67C: sw          $v0, -0x35E0($s5)
    MEM_W(-0X35E0, ctx->r21) = ctx->r2;
    // 0x800FB680: sb          $v0, -0x3610($s3)
    MEM_B(-0X3610, ctx->r19) = ctx->r2;
    // 0x800FB684: lw          $v0, -0x3620($s4)
    ctx->r2 = MEM_W(ctx->r20, -0X3620);
    // 0x800FB688: addiu       $v1, $zero, -0x3
    ctx->r3 = ADD32(0, -0X3);
    // 0x800FB68C: sw          $zero, -0x3614($s0)
    MEM_W(-0X3614, ctx->r16) = 0;
    // 0x800FB690: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800FB694: sw          $v0, -0x3620($s4)
    MEM_W(-0X3620, ctx->r20) = ctx->r2;
    // 0x800FB698: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800FB69C:
    // 0x800FB69C: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x800FB6A0: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800FB6A4: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800FB6A8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800FB6AC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800FB6B0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800FB6B4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800FB6B8: jr          $ra
    // 0x800FB6BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800FB6BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void choosePlayerCraftAssets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB6C0: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800FB6C4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FB6C8: addiu       $v0, $v0, 0x6DC0
    ctx->r2 = ADD32(ctx->r2, 0X6DC0);
    // 0x800FB6CC: sw          $ra, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r31;
    // 0x800FB6D0: sw          $fp, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r30;
    // 0x800FB6D4: sw          $s7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r23;
    // 0x800FB6D8: sw          $s6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r22;
    // 0x800FB6DC: sw          $s5, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r21;
    // 0x800FB6E0: sw          $s4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r20;
    // 0x800FB6E4: sw          $s3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r19;
    // 0x800FB6E8: sw          $s2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r18;
    // 0x800FB6EC: sw          $s1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r17;
    // 0x800FB6F0: sw          $s0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r16;
    // 0x800FB6F4: lwc1        $f2, 0x24($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800FB6F8: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800FB6FC: sub.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x800FB700: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FB704: lwc1        $f8, -0x6F78($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6F78);
    // 0x800FB708: mul.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x800FB70C: lwc1        $f0, 0x30($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800FB710: lwc1        $f4, 0x2C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800FB714: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800FB718: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800FB71C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FB720: add.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x800FB724: addiu       $v1, $v0, 0x7CE8
    ctx->r3 = ADD32(ctx->r2, 0X7CE8);
    // 0x800FB728: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800FB72C: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800FB730: swc1        $f6, 0x7CE8($v0)
    MEM_W(0X7CE8, ctx->r2) = ctx->f6.u32l;
    // 0x800FB734: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FB738: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x800FB73C: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x800FB740: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x800FB744: bne         $v1, $v0, L_800FB7E8
    if (ctx->r3 != ctx->r2) {
        // 0x800FB748: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_800FB7E8;
    }
    // 0x800FB748: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800FB74C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800FB750: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800FB754: addiu       $a1, $a1, -0x6FD0
    ctx->r5 = ADD32(ctx->r5, -0X6FD0);
    // 0x800FB758: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FB75C: addiu       $s0, $s0, 0x7DB8
    ctx->r16 = ADD32(ctx->r16, 0X7DB8);
    // 0x800FB760: jal         0x80033CC4
    // 0x800FB764: sw          $zero, 0x294($s0)
    MEM_W(0X294, ctx->r16) = 0;
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800FB764: sw          $zero, 0x294($s0)
    MEM_W(0X294, ctx->r16) = 0;
    after_0:
    // 0x800FB768: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800FB76C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800FB770: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800FB774: jal         0x8005645C
    // 0x800FB778: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    load_hmt_and_hob(rdram, ctx);
        goto after_1;
    // 0x800FB778: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_1:
    // 0x800FB77C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800FB780: addiu       $a0, $a0, 0x2208
    ctx->r4 = ADD32(ctx->r4, 0X2208);
    // 0x800FB784: addiu       $s1, $sp, 0x60
    ctx->r17 = ADD32(ctx->r29, 0X60);
    // 0x800FB788: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800FB78C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800FB790: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    // 0x800FB794: jal         0x8003FFEC
    // 0x800FB798: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    spawnNpcOfType(rdram, ctx);
        goto after_2;
    // 0x800FB798: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    after_2:
    // 0x800FB79C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800FB7A0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FB7A4: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800FB7A8: lw          $a2, -0x5F04($v0)
    ctx->r6 = MEM_W(ctx->r2, -0X5F04);
    // 0x800FB7AC: jal         0x80033CC4
    // 0x800FB7B0: addiu       $a1, $a1, -0x6FBC
    ctx->r5 = ADD32(ctx->r5, -0X6FBC);
    sprintf_recomp(rdram, ctx);
        goto after_3;
    // 0x800FB7B0: addiu       $a1, $a1, -0x6FBC
    ctx->r5 = ADD32(ctx->r5, -0X6FBC);
    after_3:
    // 0x800FB7B4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800FB7B8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800FB7BC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800FB7C0: jal         0x8005645C
    // 0x800FB7C4: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    load_hmt_and_hob(rdram, ctx);
        goto after_4;
    // 0x800FB7C4: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_4:
    // 0x800FB7C8: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x800FB7CC: addiu       $a0, $a0, 0x68A0
    ctx->r4 = ADD32(ctx->r4, 0X68A0);
    // 0x800FB7D0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800FB7D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800FB7D8: jal         0x8003FFEC
    // 0x800FB7DC: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    spawnNpcOfType(rdram, ctx);
        goto after_5;
    // 0x800FB7DC: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    after_5:
    // 0x800FB7E0: j           L_800FB9B4
    // 0x800FB7E4: sh          $v0, 0x292($s0)
    MEM_H(0X292, ctx->r16) = ctx->r2;
        goto L_800FB9B4;
    // 0x800FB7E4: sh          $v0, 0x292($s0)
    MEM_H(0X292, ctx->r16) = ctx->r2;
L_800FB7E8:
    // 0x800FB7E8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FB7EC: addiu       $s7, $v0, -0x4C60
    ctx->r23 = ADD32(ctx->r2, -0X4C60);
    // 0x800FB7F0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FB7F4: addiu       $s6, $v0, 0xB40
    ctx->r22 = ADD32(ctx->r2, 0XB40);
    // 0x800FB7F8: addiu       $s5, $zero, 0x8
    ctx->r21 = ADD32(0, 0X8);
    // 0x800FB7FC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FB800: addiu       $fp, $v0, -0x4C3C
    ctx->r30 = ADD32(ctx->r2, -0X4C3C);
    // 0x800FB804: addiu       $s3, $sp, 0x60
    ctx->r19 = ADD32(ctx->r29, 0X60);
    // 0x800FB808: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FB80C: addiu       $s4, $v0, -0x5F04
    ctx->r20 = ADD32(ctx->r2, -0X5F04);
    // 0x800FB810: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800FB814: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FB818: addiu       $s0, $v0, 0x7DB8
    ctx->r16 = ADD32(ctx->r2, 0X7DB8);
L_800FB81C:
    // 0x800FB81C: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800FB820: beql        $v0, $zero, L_800FB9A8
    if (ctx->r2 == 0) {
        // 0x800FB824: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800FB9A8;
    }
    goto skip_0;
    // 0x800FB824: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    skip_0:
    // 0x800FB828: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800FB82C: sw          $v0, 0x294($s0)
    MEM_W(0X294, ctx->r16) = ctx->r2;
    // 0x800FB830: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FB834: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x800FB838: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800FB83C: jal         0x80056DA4
    // 0x800FB840: nop

    isHobObjectLoaded(rdram, ctx);
        goto after_6;
    // 0x800FB840: nop

    after_6:
    // 0x800FB844: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800FB848: bne         $v0, $zero, L_800FB908
    if (ctx->r2 != 0) {
        // 0x800FB84C: addu        $a1, $s3, $zero
        ctx->r5 = ADD32(ctx->r19, 0);
            goto L_800FB908;
    }
    // 0x800FB84C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800FB850: lw          $v1, 0x294($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X294);
    // 0x800FB854: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800FB858: beq         $v1, $v0, L_800FB868
    if (ctx->r3 == ctx->r2) {
        // 0x800FB85C: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_800FB868;
    }
    // 0x800FB85C: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800FB860: j           L_800FB870
    // 0x800FB864: addiu       $a2, $v0, -0x6FA4
    ctx->r6 = ADD32(ctx->r2, -0X6FA4);
        goto L_800FB870;
    // 0x800FB864: addiu       $a2, $v0, -0x6FA4
    ctx->r6 = ADD32(ctx->r2, -0X6FA4);
L_800FB868:
    // 0x800FB868: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800FB86C: addiu       $a2, $v0, -0x6F98
    ctx->r6 = ADD32(ctx->r2, -0X6F98);
L_800FB870:
    // 0x800FB870: lw          $v0, 0x294($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X294);
    // 0x800FB874: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FB878: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x800FB87C: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800FB880: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800FB884: addiu       $a1, $a1, -0x6FAC
    ctx->r5 = ADD32(ctx->r5, -0X6FAC);
    // 0x800FB888: jal         0x80033CC4
    // 0x800FB88C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    sprintf_recomp(rdram, ctx);
        goto after_7;
    // 0x800FB88C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_7:
    // 0x800FB890: lw          $v1, 0x294($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X294);
    // 0x800FB894: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800FB898: bne         $v1, $v0, L_800FB8DC
    if (ctx->r3 != ctx->r2) {
        // 0x800FB89C: nop
    
            goto L_800FB8DC;
    }
    // 0x800FB89C: nop

    // 0x800FB8A0: lw          $v0, 0x18($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X18);
    // 0x800FB8A4: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800FB8A8: beq         $v0, $zero, L_800FB8DC
    if (ctx->r2 == 0) {
        // 0x800FB8AC: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_800FB8DC;
    }
    // 0x800FB8AC: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800FB8B0: addiu       $t3, $v0, -0x6F8C
    ctx->r11 = ADD32(ctx->r2, -0X6F8C);
    // 0x800FB8B4: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800FB8B8: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x800FB8BC: lw          $t2, 0x8($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X8);
    // 0x800FB8C0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800FB8C4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800FB8C8: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800FB8CC: lw          $t0, 0xC($t3)
    ctx->r8 = MEM_W(ctx->r11, 0XC);
    // 0x800FB8D0: lb          $t1, 0x10($t3)
    ctx->r9 = MEM_B(ctx->r11, 0X10);
    // 0x800FB8D4: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800FB8D8: sb          $t1, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r9;
L_800FB8DC:
    // 0x800FB8DC: lw          $v0, 0x294($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X294);
    // 0x800FB8E0: bne         $v0, $s5, L_800FB8EC
    if (ctx->r2 != ctx->r21) {
        // 0x800FB8E4: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800FB8EC;
    }
    // 0x800FB8E4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800FB8E8: lw          $a1, 0x28($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X28);
L_800FB8EC:
    // 0x800FB8EC: bne         $v0, $s5, L_800FB8F8
    if (ctx->r2 != ctx->r21) {
        // 0x800FB8F0: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_800FB8F8;
    }
    // 0x800FB8F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800FB8F4: addiu       $a2, $zero, -0x7FFF
    ctx->r6 = ADD32(0, -0X7FFF);
L_800FB8F8:
    // 0x800FB8F8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800FB8FC: jal         0x8005645C
    // 0x800FB900: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    load_hmt_and_hob(rdram, ctx);
        goto after_8;
    // 0x800FB900: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    after_8:
    // 0x800FB904: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
L_800FB908:
    // 0x800FB908: mtc1        $s1, $f0
    ctx->f0.u32l = ctx->r17;
    // 0x800FB90C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FB910: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x800FB914: lw          $v0, 0x294($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X294);
    // 0x800FB918: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800FB91C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FB920: addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // 0x800FB924: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800FB928: jal         0x8003FFEC
    // 0x800FB92C: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    spawnNpcOfType(rdram, ctx);
        goto after_9;
    // 0x800FB92C: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    after_9:
    // 0x800FB930: lw          $v0, 0x294($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X294);
    // 0x800FB934: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FB938: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x800FB93C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800FB940: jal         0x80056DA4
    // 0x800FB944: nop

    isHobObjectLoaded(rdram, ctx);
        goto after_10;
    // 0x800FB944: nop

    after_10:
    // 0x800FB948: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800FB94C: bne         $v0, $zero, L_800FB98C
    if (ctx->r2 != 0) {
        // 0x800FB950: lui         $a0, 0x800C
        ctx->r4 = S32(0X800C << 16);
            goto L_800FB98C;
    }
    // 0x800FB950: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x800FB954: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800FB958: lw          $v0, 0x294($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X294);
    // 0x800FB95C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800FB960: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FB964: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x800FB968: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x800FB96C: jal         0x80033CC4
    // 0x800FB970: addiu       $a1, $a1, -0x6FBC
    ctx->r5 = ADD32(ctx->r5, -0X6FBC);
    sprintf_recomp(rdram, ctx);
        goto after_11;
    // 0x800FB970: addiu       $a1, $a1, -0x6FBC
    ctx->r5 = ADD32(ctx->r5, -0X6FBC);
    after_11:
    // 0x800FB974: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800FB978: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800FB97C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800FB980: jal         0x8005645C
    // 0x800FB984: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    load_hmt_and_hob(rdram, ctx);
        goto after_12;
    // 0x800FB984: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    after_12:
    // 0x800FB988: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
L_800FB98C:
    // 0x800FB98C: addiu       $a0, $a0, 0x68A0
    ctx->r4 = ADD32(ctx->r4, 0X68A0);
    // 0x800FB990: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800FB994: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800FB998: jal         0x8003FFEC
    // 0x800FB99C: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    spawnNpcOfType(rdram, ctx);
        goto after_13;
    // 0x800FB99C: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    after_13:
    // 0x800FB9A0: sh          $v0, 0x292($s0)
    MEM_H(0X292, ctx->r16) = ctx->r2;
    // 0x800FB9A4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_800FB9A8:
    // 0x800FB9A8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800FB9AC: blez        $s1, L_800FB81C
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800FB9B0: addiu       $s0, $s0, 0x2A0
        ctx->r16 = ADD32(ctx->r16, 0X2A0);
            goto L_800FB81C;
    }
    // 0x800FB9B0: addiu       $s0, $s0, 0x2A0
    ctx->r16 = ADD32(ctx->r16, 0X2A0);
L_800FB9B4:
    // 0x800FB9B4: lw          $ra, 0xA4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA4);
    // 0x800FB9B8: lw          $fp, 0xA0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XA0);
    // 0x800FB9BC: lw          $s7, 0x9C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X9C);
    // 0x800FB9C0: lw          $s6, 0x98($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X98);
    // 0x800FB9C4: lw          $s5, 0x94($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X94);
    // 0x800FB9C8: lw          $s4, 0x90($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X90);
    // 0x800FB9CC: lw          $s3, 0x8C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X8C);
    // 0x800FB9D0: lw          $s2, 0x88($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X88);
    // 0x800FB9D4: lw          $s1, 0x84($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X84);
    // 0x800FB9D8: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
    // 0x800FB9DC: jr          $ra
    // 0x800FB9E0: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x800FB9E0: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void endMissionCleanup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB9E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FB9E8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800FB9EC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FB9F0: lwc1        $f0, 0xBA4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XBA4);
    // 0x800FB9F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FB9F8: lwc1        $f2, -0x6F74($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6F74);
    // 0x800FB9FC: addiu       $v1, $v1, 0xB78
    ctx->r3 = ADD32(ctx->r3, 0XB78);
    // 0x800FBA00: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800FBA04: nop

    // 0x800FBA08: bc1t        L_800FBA20
    if (c1cs) {
        // 0x800FBA0C: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_800FBA20;
    }
    // 0x800FBA0C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800FBA10: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800FBA14: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x800FBA18: j           L_800FBA34
    // 0x800FBA1C: nop

        goto L_800FBA34;
    // 0x800FBA1C: nop

L_800FBA20:
    // 0x800FBA20: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800FBA24: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800FBA28: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800FBA2C: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x800FBA30: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
L_800FBA34:
    // 0x800FBA34: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FBA38: lwc1        $f12, -0x6F70($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X6F70);
    // 0x800FBA3C: jal         0x800EF1B0
    // 0x800FBA40: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    func_800EF1B0(rdram, ctx);
        goto after_0;
    // 0x800FBA40: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    after_0:
    // 0x800FBA44: jal         0x80067820
    // 0x800FBA48: nop

    resetSpeechSubsystem(rdram, ctx);
        goto after_1;
    // 0x800FBA48: nop

    after_1:
    // 0x800FBA4C: jal         0x800678E4
    // 0x800FBA50: nop

    finalizeCurrentSpeechBuffer(rdram, ctx);
        goto after_2;
    // 0x800FBA50: nop

    after_2:
    // 0x800FBA54: jal         0x800562AC
    // 0x800FBA58: nop

    func_800562AC(rdram, ctx);
        goto after_3;
    // 0x800FBA58: nop

    after_3:
    // 0x800FBA5C: jal         0x8005EBA4
    // 0x800FBA60: nop

    func_8005EBA4(rdram, ctx);
        goto after_4;
    // 0x800FBA60: nop

    after_4:
    // 0x800FBA64: jal         0x8006590C
    // 0x800FBA68: nop

    func_8006590C(rdram, ctx);
        goto after_5;
    // 0x800FBA68: nop

    after_5:
    // 0x800FBA6C: jal         0x800558D4
    // 0x800FBA70: nop

    freeTxtFile(rdram, ctx);
        goto after_6;
    // 0x800FBA70: nop

    after_6:
    // 0x800FBA74: jal         0x8003FDD8
    // 0x800FBA78: nop

    func_8003FDD8(rdram, ctx);
        goto after_7;
    // 0x800FBA78: nop

    after_7:
    // 0x800FBA7C: jal         0x80041B48
    // 0x800FBA80: nop

    func_80041B48(rdram, ctx);
        goto after_8;
    // 0x800FBA80: nop

    after_8:
    // 0x800FBA84: jal         0x80066890
    // 0x800FBA88: nop

    func_80066890(rdram, ctx);
        goto after_9;
    // 0x800FBA88: nop

    after_9:
    // 0x800FBA8C: jal         0x800668B0
    // 0x800FBA90: nop

    waitForAnyAudioSlot(rdram, ctx);
        goto after_10;
    // 0x800FBA90: nop

    after_10:
    // 0x800FBA94: jal         0x80054A7C
    // 0x800FBA98: nop

    func_80054A7C(rdram, ctx);
        goto after_11;
    // 0x800FBA98: nop

    after_11:
    // 0x800FBA9C: jal         0x800591D4
    // 0x800FBAA0: nop

    freeAllHobFiles(rdram, ctx);
        goto after_12;
    // 0x800FBAA0: nop

    after_12:
    // 0x800FBAA4: jal         0x8003FBF8
    // 0x800FBAA8: nop

    func_8003FBF8(rdram, ctx);
        goto after_13;
    // 0x800FBAA8: nop

    after_13:
    // 0x800FBAAC: jal         0x80047AF8
    // 0x800FBAB0: nop

    func_80047AF8(rdram, ctx);
        goto after_14;
    // 0x800FBAB0: nop

    after_14:
    // 0x800FBAB4: jal         0x80045708
    // 0x800FBAB8: nop

    func_80045708(rdram, ctx);
        goto after_15;
    // 0x800FBAB8: nop

    after_15:
    // 0x800FBABC: jal         0x800EFB40
    // 0x800FBAC0: nop

    func_800EFB40(rdram, ctx);
        goto after_16;
    // 0x800FBAC0: nop

    after_16:
    // 0x800FBAC4: jal         0x800F9F6C
    // 0x800FBAC8: nop

    reset_and_free_model_animations(rdram, ctx);
        goto after_17;
    // 0x800FBAC8: nop

    after_17:
    // 0x800FBACC: jal         0x800C7320
    // 0x800FBAD0: nop

    calculateFriendliesSaved(rdram, ctx);
        goto after_18;
    // 0x800FBAD0: nop

    after_18:
    // 0x800FBAD4: jal         0x800EC514
    // 0x800FBAD8: nop

    func_800EC514(rdram, ctx);
        goto after_19;
    // 0x800FBAD8: nop

    after_19:
    // 0x800FBADC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800FBAE0: jr          $ra
    // 0x800FBAE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800FBAE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void requestSpeechResponseMode2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FBAE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FBAEC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800FBAF0: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800FBAF4: lbu         $v0, -0x3610($s0)
    ctx->r2 = MEM_BU(ctx->r16, -0X3610);
    // 0x800FBAF8: bne         $v0, $zero, L_800FBB34
    if (ctx->r2 != 0) {
        // 0x800FBAFC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800FBB34;
    }
    // 0x800FBAFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FBB00: jal         0x80067A80
    // 0x800FBB04: nop

    isSpeechBusyOrQueued(rdram, ctx);
        goto after_0;
    // 0x800FBB04: nop

    after_0:
    // 0x800FBB08: beq         $v0, $zero, L_800FBB34
    if (ctx->r2 == 0) {
        // 0x800FBB0C: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800FBB34;
    }
    // 0x800FBB0C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800FBB10: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800FBB14: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800FBB18: sb          $v0, 0xB14($v1)
    MEM_B(0XB14, ctx->r3) = ctx->r2;
    // 0x800FBB1C: lw          $v0, -0x3620($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X3620);
    // 0x800FBB20: lbu         $v1, -0x3610($s0)
    ctx->r3 = MEM_BU(ctx->r16, -0X3610);
    // 0x800FBB24: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x800FBB28: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800FBB2C: sw          $v0, -0x3620($a0)
    MEM_W(-0X3620, ctx->r4) = ctx->r2;
    // 0x800FBB30: sb          $v1, -0x3610($s0)
    MEM_B(-0X3610, ctx->r16) = ctx->r3;
L_800FBB34:
    // 0x800FBB34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FBB38: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800FBB3C: jr          $ra
    // 0x800FBB40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800FBB40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void requestSpeechResponseMode1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FBB44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FBB48: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800FBB4C: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800FBB50: lbu         $v0, -0x3610($s0)
    ctx->r2 = MEM_BU(ctx->r16, -0X3610);
    // 0x800FBB54: bne         $v0, $zero, L_800FBB90
    if (ctx->r2 != 0) {
        // 0x800FBB58: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800FBB90;
    }
    // 0x800FBB58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FBB5C: jal         0x80067A80
    // 0x800FBB60: nop

    isSpeechBusyOrQueued(rdram, ctx);
        goto after_0;
    // 0x800FBB60: nop

    after_0:
    // 0x800FBB64: beq         $v0, $zero, L_800FBB90
    if (ctx->r2 == 0) {
        // 0x800FBB68: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800FBB90;
    }
    // 0x800FBB68: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800FBB6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FBB70: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800FBB74: sb          $v0, 0xB14($v1)
    MEM_B(0XB14, ctx->r3) = ctx->r2;
    // 0x800FBB78: lw          $v0, -0x3620($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X3620);
    // 0x800FBB7C: lbu         $v1, -0x3610($s0)
    ctx->r3 = MEM_BU(ctx->r16, -0X3610);
    // 0x800FBB80: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x800FBB84: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800FBB88: sw          $v0, -0x3620($a0)
    MEM_W(-0X3620, ctx->r4) = ctx->r2;
    // 0x800FBB8C: sb          $v1, -0x3610($s0)
    MEM_B(-0X3610, ctx->r16) = ctx->r3;
L_800FBB90:
    // 0x800FBB90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FBB94: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800FBB98: jr          $ra
    // 0x800FBB9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800FBB9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void noopHandler_800FBBA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FBBA0: jr          $ra
    // 0x800FBBA4: nop

    return;
    // 0x800FBBA4: nop

;}
RECOMP_FUNC void func_800FBBA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FBBA8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FBBAC: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800FBBB0: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x800FBBB4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800FBBB8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800FBBBC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800FBBC0: jal         0x800078E0
    // 0x800FBBC4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    rs_memset(rdram, ctx);
        goto after_0;
    // 0x800FBBC4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x800FBBC8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FBBCC: lwc1        $f0, -0x3614($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X3614);
    // 0x800FBBD0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FBBD4: lwc1        $f2, -0x6F6C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6F6C);
    // 0x800FBBD8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800FBBDC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800FBBE0: nop

    // 0x800FBBE4: bc1f        L_800FBC0C
    if (!c1cs) {
        // 0x800FBBE8: sb          $v0, 0x13($sp)
        MEM_B(0X13, ctx->r29) = ctx->r2;
            goto L_800FBC0C;
    }
    // 0x800FBBE8: sb          $v0, 0x13($sp)
    MEM_B(0X13, ctx->r29) = ctx->r2;
    // 0x800FBBEC: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800FBBF0: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800FBBF4: nop

    // 0x800FBBF8: bc1f        L_800FBC10
    if (!c1cs) {
        // 0x800FBBFC: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800FBC10;
    }
    // 0x800FBBFC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FBC00: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x800FBC04: jal         0x800C401C
    // 0x800FBC08: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_800C401C(rdram, ctx);
        goto after_1;
    // 0x800FBC08: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_1:
L_800FBC0C:
    // 0x800FBC0C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800FBC10:
    // 0x800FBC10: lwc1        $f0, -0x3614($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X3614);
    // 0x800FBC14: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800FBC18: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800FBC1C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800FBC20: nop

    // 0x800FBC24: bc1f        L_800FBC3C
    if (!c1cs) {
        // 0x800FBC28: swc1        $f0, -0x3614($v0)
        MEM_W(-0X3614, ctx->r2) = ctx->f0.u32l;
            goto L_800FBC3C;
    }
    // 0x800FBC28: swc1        $f0, -0x3614($v0)
    MEM_W(-0X3614, ctx->r2) = ctx->f0.u32l;
    // 0x800FBC2C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800FBC30: lw          $v0, -0x35E4($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X35E4);
    // 0x800FBC34: ori         $v0, $v0, 0x40
    ctx->r2 = ctx->r2 | 0X40;
    // 0x800FBC38: sw          $v0, -0x35E4($v1)
    MEM_W(-0X35E4, ctx->r3) = ctx->r2;
L_800FBC3C:
    // 0x800FBC3C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800FBC40: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800FBC44: jr          $ra
    // 0x800FBC48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800FBC48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
