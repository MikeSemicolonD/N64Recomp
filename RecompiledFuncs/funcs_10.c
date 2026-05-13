#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void loadLevelAssets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800453C8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800453CC: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800453D0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800453D4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800453D8: sh          $s0, 0xC4C($v0)
    MEM_H(0XC4C, ctx->r2) = ctx->r16;
    // 0x800453DC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800453E0: addiu       $a0, $v0, 0x6F80
    ctx->r4 = ADD32(ctx->r2, 0X6F80);
    // 0x800453E4: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800453E8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800453EC: lw          $a2, 0xB70($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XB70);
    // 0x800453F0: addiu       $a1, $v1, -0x5A80
    ctx->r5 = ADD32(ctx->r3, -0X5A80);
    // 0x800453F4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800453F8: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800453FC: slti        $v0, $a2, 0xA
    ctx->r2 = SIGNED(ctx->r6) < 0XA ? 1 : 0;
    // 0x80045400: beq         $v0, $zero, L_80045410
    if (ctx->r2 == 0) {
        // 0x80045404: sw          $s1, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r17;
            goto L_80045410;
    }
    // 0x80045404: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80045408: j           L_80045414
    // 0x8004540C: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
        goto L_80045414;
    // 0x8004540C: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
L_80045410:
    // 0x80045410: addiu       $a2, $a2, 0x57
    ctx->r6 = ADD32(ctx->r6, 0X57);
L_80045414:
    // 0x80045414: jal         0x80033CC4
    // 0x80045418: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x80045418: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    after_0:
    // 0x8004541C: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80045420: lw          $v1, 0xB70($s2)
    ctx->r3 = MEM_W(ctx->r18, 0XB70);
    // 0x80045424: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80045428: beq         $v1, $v0, L_80045454
    if (ctx->r3 == ctx->r2) {
        // 0x8004542C: sw          $zero, 0x6FC4($s1)
        MEM_W(0X6FC4, ctx->r17) = 0;
            goto L_80045454;
    }
    // 0x8004542C: sw          $zero, 0x6FC4($s1)
    MEM_W(0X6FC4, ctx->r17) = 0;
    // 0x80045430: jal         0x80047E50
    // 0x80045434: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80047E50(rdram, ctx);
        goto after_1;
    // 0x80045434: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80045438: sll         $a0, $s0, 1
    ctx->r4 = S32(ctx->r16 << 1);
    // 0x8004543C: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // 0x80045440: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80045444: jal         0x80001ACC
    // 0x80045448: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_2;
    // 0x80045448: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
    // 0x8004544C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80045450: sw          $v0, 0x6E1C($v1)
    MEM_W(0X6E1C, ctx->r3) = ctx->r2;
L_80045454:
    // 0x80045454: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80045458: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8004545C: addiu       $s0, $s0, 0x6F80
    ctx->r16 = ADD32(ctx->r16, 0X6F80);
    // 0x80045460: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80045464: jal         0x80043D74
    // 0x80045468: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    load_level_hmp(rdram, ctx);
        goto after_3;
    // 0x80045468: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_3:
    // 0x8004546C: jal         0x80046784
    // 0x80045470: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    loadDatFile(rdram, ctx);
        goto after_4;
    // 0x80045470: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x80045474: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80045478: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8004547C: addiu       $a1, $a1, -0x5A74
    ctx->r5 = ADD32(ctx->r5, -0X5A74);
    // 0x80045480: jal         0x80033CC4
    // 0x80045484: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sprintf_recomp(rdram, ctx);
        goto after_5;
    // 0x80045484: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_5:
    // 0x80045488: jal         0x800543F4
    // 0x8004548C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    load_full_header_image(rdram, ctx);
        goto after_6;
    // 0x8004548C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_6:
    // 0x80045490: lw          $v0, 0x6FC4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X6FC4);
    // 0x80045494: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80045498: lhu         $a1, 0x18($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X18);
    // 0x8004549C: jal         0x800457D0
    // 0x800454A0: addiu       $a0, $a0, 0x6DC0
    ctx->r4 = ADD32(ctx->r4, 0X6DC0);
    func_800457D0(rdram, ctx);
        goto after_7;
    // 0x800454A0: addiu       $a0, $a0, 0x6DC0
    ctx->r4 = ADD32(ctx->r4, 0X6DC0);
    after_7:
    // 0x800454A4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800454A8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800454AC: lwc1        $f0, -0x5A68($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5A68);
    // 0x800454B0: lw          $v1, 0xB70($s2)
    ctx->r3 = MEM_W(ctx->r18, 0XB70);
    // 0x800454B4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800454B8: bne         $v1, $v0, L_800454CC
    if (ctx->r3 != ctx->r2) {
        // 0x800454BC: swc1        $f0, 0x6FBC($a0)
        MEM_W(0X6FBC, ctx->r4) = ctx->f0.u32l;
            goto L_800454CC;
    }
    // 0x800454BC: swc1        $f0, 0x6FBC($a0)
    MEM_W(0X6FBC, ctx->r4) = ctx->f0.u32l;
    // 0x800454C0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800454C4: lwc1        $f0, -0x5A64($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5A64);
    // 0x800454C8: swc1        $f0, 0x6FBC($a0)
    MEM_W(0X6FBC, ctx->r4) = ctx->f0.u32l;
L_800454CC:
    // 0x800454CC: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800454D0: addiu       $s0, $s1, 0x6E18
    ctx->r16 = ADD32(ctx->r17, 0X6E18);
    // 0x800454D4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800454D8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800454DC: lwc1        $f0, -0x5A60($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5A60);
    // 0x800454E0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800454E4: jal         0x8006B568
    // 0x800454E8: swc1        $f0, 0x6FAC($v0)
    MEM_W(0X6FAC, ctx->r2) = ctx->f0.u32l;
    func_8006B568(rdram, ctx);
        goto after_8;
    // 0x800454E8: swc1        $f0, 0x6FAC($v0)
    MEM_W(0X6FAC, ctx->r2) = ctx->f0.u32l;
    after_8:
    // 0x800454EC: lbu         $a0, 0x6E18($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X6E18);
    // 0x800454F0: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    // 0x800454F4: lbu         $a2, 0x2($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X2);
    // 0x800454F8: jal         0x80017A90
    // 0x800454FC: nop

    setFrameLevelStateBytes(rdram, ctx);
        goto after_9;
    // 0x800454FC: nop

    after_9:
    // 0x80045500: jal         0x80017B48
    // 0x80045504: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    setMissionLevelInitByte(rdram, ctx);
        goto after_10;
    // 0x80045504: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x80045508: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004550C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80045510: lwc1        $f4, -0x5A5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5A5C);
    // 0x80045514: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80045518: lwc1        $f2, -0x5A58($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5A58);
    // 0x8004551C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80045520: lwc1        $f0, -0x5A54($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5A54);
    // 0x80045524: lw          $a0, 0xB70($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XB70);
    // 0x80045528: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x8004552C: swc1        $f2, 0xC54($v0)
    MEM_W(0XC54, ctx->r2) = ctx->f2.u32l;
    // 0x80045530: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045534: swc1        $f0, 0xC58($v0)
    MEM_W(0XC58, ctx->r2) = ctx->f0.u32l;
    // 0x80045538: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8004553C: bne         $a0, $v1, L_8004554C
    if (ctx->r4 != ctx->r3) {
        // 0x80045540: swc1        $f2, -0x2154($v0)
        MEM_W(-0X2154, ctx->r2) = ctx->f2.u32l;
            goto L_8004554C;
    }
    // 0x80045540: swc1        $f2, -0x2154($v0)
    MEM_W(-0X2154, ctx->r2) = ctx->f2.u32l;
    // 0x80045544: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80045548: lwc1        $f4, -0x5A50($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5A50);
L_8004554C:
    // 0x8004554C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80045550: lwc1        $f0, -0x5A4C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5A4C);
    // 0x80045554: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045558: bne         $a0, $v1, L_80045568
    if (ctx->r4 != ctx->r3) {
        // 0x8004555C: swc1        $f4, 0xC5C($v0)
        MEM_W(0XC5C, ctx->r2) = ctx->f4.u32l;
            goto L_80045568;
    }
    // 0x8004555C: swc1        $f4, 0xC5C($v0)
    MEM_W(0XC5C, ctx->r2) = ctx->f4.u32l;
    // 0x80045560: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80045564: lwc1        $f0, -0x5A48($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5A48);
L_80045568:
    // 0x80045568: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004556C: swc1        $f0, 0xC60($v0)
    MEM_W(0XC60, ctx->r2) = ctx->f0.u32l;
    // 0x80045570: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045574: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80045578: lwc1        $f0, -0x5A44($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5A44);
    // 0x8004557C: lbu         $v1, 0xB39($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB39);
    // 0x80045580: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045584: bne         $v1, $zero, L_800455A0
    if (ctx->r3 != 0) {
        // 0x80045588: swc1        $f0, 0xC50($v0)
        MEM_W(0XC50, ctx->r2) = ctx->f0.u32l;
            goto L_800455A0;
    }
    // 0x80045588: swc1        $f0, 0xC50($v0)
    MEM_W(0XC50, ctx->r2) = ctx->f0.u32l;
    // 0x8004558C: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // 0x80045590: beq         $a0, $v0, L_800455A0
    if (ctx->r4 == ctx->r2) {
        // 0x80045594: nop
    
            goto L_800455A0;
    }
    // 0x80045594: nop

    // 0x80045598: jal         0x80044BE4
    // 0x8004559C: nop

    func_80044BE4(rdram, ctx);
        goto after_11;
    // 0x8004559C: nop

    after_11:
L_800455A0:
    // 0x800455A0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800455A4: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800455A8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800455AC: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800455B0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800455B4: sw          $zero, -0x76D8($v0)
    MEM_W(-0X76D8, ctx->r2) = 0;
    // 0x800455B8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800455BC: sw          $zero, -0x7768($v0)
    MEM_W(-0X7768, ctx->r2) = 0;
    // 0x800455C0: jr          $ra
    // 0x800455C4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800455C4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800455C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800455C8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800455CC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800455D0: lw          $v0, -0x72E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X72E4);
    // 0x800455D4: lwc1        $f8, 0xC5C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC5C);
    // 0x800455D8: lwc1        $f2, 0x50($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X50);
    // 0x800455DC: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x800455E0: nop

    // 0x800455E4: bc1t        L_80045604
    if (c1cs) {
        // 0x800455E8: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80045604;
    }
    // 0x800455E8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800455EC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800455F0: lwc1        $f6, 0xC60($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC60);
    // 0x800455F4: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x800455F8: nop

    // 0x800455FC: bc1f        L_80045610
    if (!c1cs) {
        // 0x80045600: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80045610;
    }
    // 0x80045600: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_80045604:
    // 0x80045604: lwc1        $f0, 0xC54($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC54);
    // 0x80045608: j           L_80045628
    // 0x8004560C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
        goto L_80045628;
    // 0x8004560C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
L_80045610:
    // 0x80045610: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80045614: nop

    // 0x80045618: bc1f        L_80045630
    if (!c1cs) {
        // 0x8004561C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80045630;
    }
    // 0x8004561C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045620: lwc1        $f0, 0xC58($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC58);
    // 0x80045624: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
L_80045628:
    // 0x80045628: j           L_8004565C
    // 0x8004562C: swc1        $f0, -0x2154($v0)
    MEM_W(-0X2154, ctx->r2) = ctx->f0.u32l;
        goto L_8004565C;
    // 0x8004562C: swc1        $f0, -0x2154($v0)
    MEM_W(-0X2154, ctx->r2) = ctx->f0.u32l;
L_80045630:
    // 0x80045630: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80045634: lwc1        $f0, 0xC58($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC58);
    // 0x80045638: sub.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x8004563C: lwc1        $f4, 0xC54($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC54);
    // 0x80045640: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80045644: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80045648: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8004564C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80045650: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80045654: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80045658: swc1        $f4, -0x2154($v0)
    MEM_W(-0X2154, ctx->r2) = ctx->f4.u32l;
L_8004565C:
    // 0x8004565C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045660: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x80045664: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80045668: bne         $v1, $v0, L_80045684
    if (ctx->r3 != ctx->r2) {
        // 0x8004566C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80045684;
    }
    // 0x8004566C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80045670: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80045674: lwc1        $f0, -0x5A40($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5A40);
    // 0x80045678: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8004567C: swc1        $f0, -0x2154($v0)
    MEM_W(-0X2154, ctx->r2) = ctx->f0.u32l;
    // 0x80045680: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80045684:
    // 0x80045684: beq         $v1, $v0, L_80045694
    if (ctx->r3 == ctx->r2) {
        // 0x80045688: addiu       $v0, $zero, 0x13
        ctx->r2 = ADD32(0, 0X13);
            goto L_80045694;
    }
    // 0x80045688: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // 0x8004568C: bne         $v1, $v0, L_800456A0
    if (ctx->r3 != ctx->r2) {
        // 0x80045690: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800456A0;
    }
    // 0x80045690: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_80045694:
    // 0x80045694: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80045698: j           L_800456D8
    // 0x8004569C: sw          $zero, -0x214C($v0)
    MEM_W(-0X214C, ctx->r2) = 0;
        goto L_800456D8;
    // 0x8004569C: sw          $zero, -0x214C($v0)
    MEM_W(-0X214C, ctx->r2) = 0;
L_800456A0:
    // 0x800456A0: lwc1        $f4, 0x6FBC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6FBC);
    // 0x800456A4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800456A8: lwc1        $f0, -0x5A3C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5A3C);
    // 0x800456AC: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800456B0: nop

    // 0x800456B4: mul.s       $f0, $f4, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800456B8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800456BC: lwc1        $f2, -0x2154($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X2154);
    // 0x800456C0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800456C4: nop

    // 0x800456C8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800456CC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800456D0: swc1        $f4, -0x214C($v0)
    MEM_W(-0X214C, ctx->r2) = ctx->f4.u32l;
    // 0x800456D4: swc1        $f0, -0x214C($v0)
    MEM_W(-0X214C, ctx->r2) = ctx->f0.u32l;
L_800456D8:
    // 0x800456D8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800456DC: lwc1        $f0, -0x2154($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X2154);
    // 0x800456E0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800456E4: lwc1        $f2, -0x5A38($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5A38);
    // 0x800456E8: mul.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800456EC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800456F0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800456F4: lwc1        $f2, -0x5A34($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5A34);
    // 0x800456F8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800456FC: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80045700: jr          $ra
    // 0x80045704: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x80045704: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_80045708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045708: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004570C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80045710: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80045714: lw          $v0, 0x6FC4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X6FC4);
    // 0x80045718: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8004571C: beq         $v0, $zero, L_80045754
    if (ctx->r2 == 0) {
        // 0x80045720: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_80045754;
    }
    // 0x80045720: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80045724: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80045728: addiu       $s0, $s0, 0x6DC0
    ctx->r16 = ADD32(ctx->r16, 0X6DC0);
    // 0x8004572C: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80045730: jal         0x80001C98
    // 0x80045734: nop

    rs_free(rdram, ctx);
        goto after_0;
    // 0x80045734: nop

    after_0:
    // 0x80045738: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x8004573C: jal         0x80001C98
    // 0x80045740: nop

    rs_free(rdram, ctx);
        goto after_1;
    // 0x80045740: nop

    after_1:
    // 0x80045744: lw          $a0, 0x6FC4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X6FC4);
    // 0x80045748: jal         0x80001C98
    // 0x8004574C: nop

    rs_free(rdram, ctx);
        goto after_2;
    // 0x8004574C: nop

    after_2:
    // 0x80045750: sw          $zero, 0x6FC4($s1)
    MEM_W(0X6FC4, ctx->r17) = 0;
L_80045754:
    // 0x80045754: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045758: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x8004575C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80045760: beq         $v1, $v0, L_80045798
    if (ctx->r3 == ctx->r2) {
        // 0x80045764: nop
    
            goto L_80045798;
    }
    // 0x80045764: nop

    // 0x80045768: jal         0x800495B0
    // 0x8004576C: nop

    func_800495B0(rdram, ctx);
        goto after_3;
    // 0x8004576C: nop

    after_3:
    // 0x80045770: jal         0x8004955C
    // 0x80045774: nop

    func_8004955C(rdram, ctx);
        goto after_4;
    // 0x80045774: nop

    after_4:
    // 0x80045778: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004577C: lw          $a0, 0x6FCC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X6FCC);
    // 0x80045780: jal         0x80001C98
    // 0x80045784: nop

    rs_free(rdram, ctx);
        goto after_5;
    // 0x80045784: nop

    after_5:
    // 0x80045788: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004578C: lw          $a0, 0x6E1C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X6E1C);
    // 0x80045790: jal         0x80001C98
    // 0x80045794: nop

    rs_free(rdram, ctx);
        goto after_6;
    // 0x80045794: nop

    after_6:
L_80045798:
    // 0x80045798: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8004579C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800457A0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800457A4: jr          $ra
    // 0x800457A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800457A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800457AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800457AC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800457B0: jr          $ra
    // 0x800457B4: swc1        $f12, 0xC50($v0)
    MEM_W(0XC50, ctx->r2) = ctx->f12.u32l;
    return;
    // 0x800457B4: swc1        $f12, 0xC50($v0)
    MEM_W(0XC50, ctx->r2) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_800457B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800457B8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800457BC: swc1        $f12, 0xC54($v0)
    MEM_W(0XC54, ctx->r2) = ctx->f12.u32l;
    // 0x800457C0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800457C4: jr          $ra
    // 0x800457C8: swc1        $f14, 0xC58($v0)
    MEM_W(0XC58, ctx->r2) = ctx->f14.u32l;
    return;
    // 0x800457C8: swc1        $f14, 0xC58($v0)
    MEM_W(0XC58, ctx->r2) = ctx->f14.u32l;
;}
RECOMP_FUNC void fake_func_800457CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800457D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800457D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800457D4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800457D8: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800457DC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800457E0: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x800457E4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800457E8: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800457EC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800457F0: addiu       $a0, $a0, -0x5A30
    ctx->r4 = ADD32(ctx->r4, -0X5A30);
    // 0x800457F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800457F8: jal         0x80047B48
    // 0x800457FC: sb          $zero, 0x7150($s1)
    MEM_B(0X7150, ctx->r17) = 0;
    getLevelDatItemByName(rdram, ctx);
        goto after_0;
    // 0x800457FC: sb          $zero, 0x7150($s1)
    MEM_B(0X7150, ctx->r17) = 0;
    after_0:
    // 0x80045800: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80045804: beq         $v1, $zero, L_80045B48
    if (ctx->r3 == 0) {
        // 0x80045808: nop
    
            goto L_80045B48;
    }
    // 0x80045808: nop

    // 0x8004580C: lw          $a1, 0x60($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X60);
    // 0x80045810: beq         $a1, $zero, L_80045B48
    if (ctx->r5 == 0) {
        // 0x80045814: addiu       $v0, $zero, 0x7F
        ctx->r2 = ADD32(0, 0X7F);
            goto L_80045B48;
    }
    // 0x80045814: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x80045818: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8004581C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80045820: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x80045824: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80045828: lw          $t1, 0x4($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X4);
    // 0x8004582C: lwc1        $f2, 0x10($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X10);
    // 0x80045830: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80045834: lwc1        $f4, -0x5A18($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5A18);
    // 0x80045838: lwc1        $f0, 0x64($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X64);
    // 0x8004583C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80045840: swc1        $f0, 0x7164($a1)
    MEM_W(0X7164, ctx->r5) = ctx->f0.u32l;
    // 0x80045844: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80045848: sw          $v0, 0x75C0($a2)
    MEM_W(0X75C0, ctx->r6) = ctx->r2;
    // 0x8004584C: lwc1        $f2, 0x68($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X68);
    // 0x80045850: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045854: swc1        $f2, 0x715C($v0)
    MEM_W(0X715C, ctx->r2) = ctx->f2.u32l;
    // 0x80045858: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8004585C: lwc1        $f2, 0x6C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X6C);
    // 0x80045860: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045864: swc1        $f2, 0x7160($v0)
    MEM_W(0X7160, ctx->r2) = ctx->f2.u32l;
    // 0x80045868: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004586C: blez        $s0, L_80045910
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80045870: swc1        $f0, 0x6FA8($v0)
        MEM_W(0X6FA8, ctx->r2) = ctx->f0.u32l;
            goto L_80045910;
    }
    // 0x80045870: swc1        $f0, 0x6FA8($v0)
    MEM_W(0X6FA8, ctx->r2) = ctx->f0.u32l;
    // 0x80045874: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x80045878: addu        $t2, $s1, $zero
    ctx->r10 = ADD32(ctx->r17, 0);
    // 0x8004587C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80045880: addiu       $v1, $t1, 0x4
    ctx->r3 = ADD32(ctx->r9, 0X4);
L_80045884:
    // 0x80045884: lb          $v0, -0x1($v1)
    ctx->r2 = MEM_B(ctx->r3, -0X1);
    // 0x80045888: lw          $a1, 0x75C0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X75C0);
    // 0x8004588C: slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80045890: bne         $v0, $zero, L_800458C4
    if (ctx->r2 != 0) {
        // 0x80045894: nop
    
            goto L_800458C4;
    }
    // 0x80045894: nop

    // 0x80045898: lbu         $v0, -0x2($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X2);
    // 0x8004589C: ori         $v0, $v0, 0x8
    ctx->r2 = ctx->r2 | 0X8;
    // 0x800458A0: sb          $v0, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r2;
    // 0x800458A4: lwc1        $f2, 0x7164($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X7164);
    // 0x800458A8: lwc1        $f0, 0x75C0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X75C0);
    // 0x800458AC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800458B0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800458B4: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800458B8: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800458BC: j           L_800458E0
    // 0x800458C0: sb          $v0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r2;
        goto L_800458E0;
    // 0x800458C0: sb          $v0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r2;
L_800458C4:
    // 0x800458C4: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x800458C8: slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800458CC: bnel        $v0, $zero, L_80045904
    if (ctx->r2 != 0) {
        // 0x800458D0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80045904;
    }
    goto skip_0;
    // 0x800458D0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x800458D4: lbu         $v0, -0x2($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X2);
    // 0x800458D8: ori         $v0, $v0, 0x10
    ctx->r2 = ctx->r2 | 0X10;
    // 0x800458DC: sb          $v0, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r2;
L_800458E0:
    // 0x800458E0: lwc1        $f2, 0x7164($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X7164);
    // 0x800458E4: lwc1        $f0, 0x75C0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X75C0);
    // 0x800458E8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800458EC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800458F0: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800458F4: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800458F8: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x800458FC: sb          $t0, 0x7150($t2)
    MEM_B(0X7150, ctx->r10) = ctx->r8;
    // 0x80045900: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80045904:
    // 0x80045904: slt         $v0, $a0, $s0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80045908: bne         $v0, $zero, L_80045884
    if (ctx->r2 != 0) {
        // 0x8004590C: addiu       $v1, $v1, 0x1E
        ctx->r3 = ADD32(ctx->r3, 0X1E);
            goto L_80045884;
    }
    // 0x8004590C: addiu       $v1, $v1, 0x1E
    ctx->r3 = ADD32(ctx->r3, 0X1E);
L_80045910:
    // 0x80045910: lhu         $v1, 0x38($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X38);
    // 0x80045914: lhu         $v0, 0x3A($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X3A);
    // 0x80045918: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004591C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80045920: lw          $t1, 0x4($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X4);
    // 0x80045924: mflo        $t3
    ctx->r11 = lo;
    // 0x80045928: blez        $t3, L_800459CC
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8004592C: addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
            goto L_800459CC;
    }
    // 0x8004592C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
L_80045930:
    // 0x80045930: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80045934: sll         $a2, $a0, 1
    ctx->r6 = S32(ctx->r4 << 1);
    // 0x80045938: addu        $t0, $a2, $v0
    ctx->r8 = ADD32(ctx->r6, ctx->r2);
    // 0x8004593C: lhu         $a3, 0x0($t0)
    ctx->r7 = MEM_HU(ctx->r8, 0X0);
    // 0x80045940: andi        $v1, $a3, 0x1FFF
    ctx->r3 = ctx->r7 & 0X1FFF;
    // 0x80045944: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80045948: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004594C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80045950: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80045954: lbu         $v0, 0x2($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2);
    // 0x80045958: andi        $v0, $v0, 0x18
    ctx->r2 = ctx->r2 & 0X18;
    // 0x8004595C: beq         $v0, $zero, L_800459AC
    if (ctx->r2 == 0) {
        // 0x80045960: ori         $v0, $a3, 0x2000
        ctx->r2 = ctx->r7 | 0X2000;
            goto L_800459AC;
    }
    // 0x80045960: ori         $v0, $a3, 0x2000
    ctx->r2 = ctx->r7 | 0X2000;
    // 0x80045964: sh          $v0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r2;
    // 0x80045968: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8004596C: addu        $v1, $a2, $v1
    ctx->r3 = ADD32(ctx->r6, ctx->r3);
    // 0x80045970: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80045974: andi        $v0, $v0, 0x3FFF
    ctx->r2 = ctx->r2 & 0X3FFF;
    // 0x80045978: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8004597C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80045980: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80045984: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x80045988: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x8004598C: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80045990: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80045994: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80045998: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8004599C: lbu         $v0, 0x2($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2);
    // 0x800459A0: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800459A4: bnel        $v0, $zero, L_800459AC
    if (ctx->r2 != 0) {
        // 0x800459A8: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800459AC;
    }
    goto skip_1;
    // 0x800459A8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_1:
L_800459AC:
    // 0x800459AC: lhu         $v1, 0x38($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X38);
    // 0x800459B0: lhu         $v0, 0x3A($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X3A);
    // 0x800459B4: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800459B8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800459BC: mflo        $t3
    ctx->r11 = lo;
    // 0x800459C0: slt         $v0, $a0, $t3
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800459C4: bne         $v0, $zero, L_80045930
    if (ctx->r2 != 0) {
        // 0x800459C8: nop
    
            goto L_80045930;
    }
    // 0x800459C8: nop

L_800459CC:
    // 0x800459CC: blez        $a1, L_80045A08
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800459D0: sll         $s0, $a1, 1
        ctx->r16 = S32(ctx->r5 << 1);
            goto L_80045A08;
    }
    // 0x800459D0: sll         $s0, $a1, 1
    ctx->r16 = S32(ctx->r5 << 1);
    // 0x800459D4: addu        $s0, $s0, $a1
    ctx->r16 = ADD32(ctx->r16, ctx->r5);
    // 0x800459D8: sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16 << 3);
    // 0x800459DC: addu        $s0, $s0, $a1
    ctx->r16 = ADD32(ctx->r16, ctx->r5);
    // 0x800459E0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800459E4: jal         0x80001ACC
    // 0x800459E8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x800459E8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x800459EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800459F0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800459F4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800459F8: sw          $v0, 0x7148($s0)
    MEM_W(0X7148, ctx->r16) = ctx->r2;
    // 0x800459FC: jal         0x80001ACC
    // 0x80045A00: addiu       $s0, $s0, 0x7148
    ctx->r16 = ADD32(ctx->r16, 0X7148);
    rs_malloc(rdram, ctx);
        goto after_2;
    // 0x80045A00: addiu       $s0, $s0, 0x7148
    ctx->r16 = ADD32(ctx->r16, 0X7148);
    after_2:
    // 0x80045A04: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_80045A08:
    // 0x80045A08: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80045A0C: addiu       $s0, $s1, 0x7450
    ctx->r16 = ADD32(ctx->r17, 0X7450);
    // 0x80045A10: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80045A14: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80045A18: jal         0x80018EF4
    // 0x80045A1C: addiu       $a2, $zero, 0x58
    ctx->r6 = ADD32(0, 0X58);
    zmemcpy(rdram, ctx);
        goto after_3;
    // 0x80045A1C: addiu       $a2, $zero, 0x58
    ctx->r6 = ADD32(0, 0X58);
    after_3:
    // 0x80045A20: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80045A24: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // 0x80045A28: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045A2C: addiu       $a0, $v0, 0x7170
    ctx->r4 = ADD32(ctx->r2, 0X7170);
    // 0x80045A30: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045A34: addiu       $v0, $v0, 0x74B0
    ctx->r2 = ADD32(ctx->r2, 0X74B0);
    // 0x80045A38: sw          $v0, 0x7450($s1)
    MEM_W(0X7450, ctx->r17) = ctx->r2;
    // 0x80045A3C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80045A40: sh          $v0, 0x3A($s0)
    MEM_H(0X3A, ctx->r16) = ctx->r2;
    // 0x80045A44: sh          $v0, 0x38($s0)
    MEM_H(0X38, ctx->r16) = ctx->r2;
    // 0x80045A48: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045A4C: addiu       $v0, $v0, 0x74D0
    ctx->r2 = ADD32(ctx->r2, 0X74D0);
    // 0x80045A50: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x80045A54: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
L_80045A58:
    // 0x80045A58: srl         $v0, $a1, 31
    ctx->r2 = S32(U32(ctx->r5) >> 31);
    // 0x80045A5C: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x80045A60: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80045A64: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80045A68: subu        $v1, $a1, $v1
    ctx->r3 = SUB32(ctx->r5, ctx->r3);
    // 0x80045A6C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80045A70: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80045A74: sh          $v1, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r3;
    // 0x80045A78: sh          $v0, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r2;
    // 0x80045A7C: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x80045A80: sh          $zero, 0x12($a0)
    MEM_H(0X12, ctx->r4) = 0;
    // 0x80045A84: sh          $zero, 0x10($a0)
    MEM_H(0X10, ctx->r4) = 0;
    // 0x80045A88: sh          $zero, 0xE($a0)
    MEM_H(0XE, ctx->r4) = 0;
    // 0x80045A8C: sh          $zero, 0xC($a0)
    MEM_H(0XC, ctx->r4) = 0;
    // 0x80045A90: sh          $zero, 0xA($a0)
    MEM_H(0XA, ctx->r4) = 0;
    // 0x80045A94: sh          $zero, 0x14($a0)
    MEM_H(0X14, ctx->r4) = 0;
    // 0x80045A98: sh          $a2, 0x1E($a0)
    MEM_H(0X1E, ctx->r4) = ctx->r6;
    // 0x80045A9C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80045AA0: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80045AA4: bne         $v0, $zero, L_80045A58
    if (ctx->r2 != 0) {
        // 0x80045AA8: addiu       $a0, $a0, 0xB8
        ctx->r4 = ADD32(ctx->r4, 0XB8);
            goto L_80045A58;
    }
    // 0x80045AA8: addiu       $a0, $a0, 0xB8
    ctx->r4 = ADD32(ctx->r4, 0XB8);
    // 0x80045AAC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80045AB0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045AB4: addiu       $t0, $v0, 0x74B0
    ctx->r8 = ADD32(ctx->r2, 0X74B0);
    // 0x80045AB8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80045ABC:
    // 0x80045ABC: sll         $a3, $a1, 2
    ctx->r7 = S32(ctx->r5 << 2);
    // 0x80045AC0: addiu       $v1, $a1, 0x1
    ctx->r3 = ADD32(ctx->r5, 0X1);
    // 0x80045AC4: srl         $v0, $v1, 31
    ctx->r2 = S32(U32(ctx->r3) >> 31);
    // 0x80045AC8: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80045ACC: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80045AD0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80045AD4: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80045AD8: sll         $a2, $v1, 1
    ctx->r6 = S32(ctx->r3 << 1);
    // 0x80045ADC: addu        $v1, $a3, $a0
    ctx->r3 = ADD32(ctx->r7, ctx->r4);
L_80045AE0:
    // 0x80045AE0: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80045AE4: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80045AE8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80045AEC: srl         $v0, $a0, 31
    ctx->r2 = S32(U32(ctx->r4) >> 31);
    // 0x80045AF0: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80045AF4: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80045AF8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80045AFC: subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // 0x80045B00: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80045B04: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80045B08: slti        $v0, $a0, 0x4
    ctx->r2 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x80045B0C: bnel        $v0, $zero, L_80045AE0
    if (ctx->r2 != 0) {
        // 0x80045B10: addu        $v1, $a3, $a0
        ctx->r3 = ADD32(ctx->r7, ctx->r4);
            goto L_80045AE0;
    }
    goto skip_2;
    // 0x80045B10: addu        $v1, $a3, $a0
    ctx->r3 = ADD32(ctx->r7, ctx->r4);
    skip_2:
    // 0x80045B14: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80045B18: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80045B1C: bnel        $v0, $zero, L_80045ABC
    if (ctx->r2 != 0) {
        // 0x80045B20: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80045ABC;
    }
    goto skip_3;
    // 0x80045B20: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_3:
    // 0x80045B24: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80045B28: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045B2C: sb          $zero, 0x7151($v0)
    MEM_B(0X7151, ctx->r2) = 0;
    // 0x80045B30: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045B34: sw          $zero, 0x7168($v0)
    MEM_W(0X7168, ctx->r2) = 0;
    // 0x80045B38: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045B3C: swc1        $f0, 0x7158($v0)
    MEM_W(0X7158, ctx->r2) = ctx->f0.u32l;
    // 0x80045B40: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045B44: swc1        $f0, 0x7154($v0)
    MEM_W(0X7154, ctx->r2) = ctx->f0.u32l;
L_80045B48:
    // 0x80045B48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80045B4C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80045B50: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80045B54: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80045B58: jr          $ra
    // 0x80045B5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80045B5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80045B60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045B60: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045B64: lbu         $v0, 0x7150($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7150);
    // 0x80045B68: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80045B6C: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80045B70: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x80045B74: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80045B78: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80045B7C: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80045B80: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80045B84: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80045B88: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80045B8C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80045B90: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x80045B94: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x80045B98: beq         $v0, $zero, L_80045FFC
    if (ctx->r2 == 0) {
        // 0x80045B9C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80045FFC;
    }
    // 0x80045B9C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045BA0: lwc1        $f6, 0x715C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X715C);
    // 0x80045BA4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80045BA8: lwc1        $f0, -0x5A14($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5A14);
    // 0x80045BAC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045BB0: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80045BB4: addiu       $s0, $v0, 0x6FD0
    ctx->r16 = ADD32(ctx->r2, 0X6FD0);
    // 0x80045BB8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045BBC: lwc1        $f4, 0x7160($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X7160);
    // 0x80045BC0: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80045BC4: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80045BC8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045BCC: mul.s       $f6, $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80045BD0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80045BD4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80045BD8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80045BDC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80045BE0: lwc1        $f22, -0x5A10($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X5A10);
    // 0x80045BE4: mul.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80045BE8: sw          $zero, 0x7168($v0)
    MEM_W(0X7168, ctx->r2) = 0;
    // 0x80045BEC: lbu         $v0, 0x7151($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X7151);
    // 0x80045BF0: lwc1        $f0, 0x7154($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X7154);
    // 0x80045BF4: lwc1        $f2, 0x7158($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X7158);
    // 0x80045BF8: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80045BFC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80045C00: sb          $v0, 0x7151($v1)
    MEM_B(0X7151, ctx->r3) = ctx->r2;
    // 0x80045C04: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80045C08: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80045C0C: swc1        $f20, 0x7154($a1)
    MEM_W(0X7154, ctx->r5) = ctx->f20.u32l;
    // 0x80045C10: swc1        $f2, 0x7158($a0)
    MEM_W(0X7158, ctx->r4) = ctx->f2.u32l;
L_80045C14:
    // 0x80045C14: jal         0x80033960
    // 0x80045C18: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x80045C18: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x80045C1C: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x80045C20: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80045C24: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80045C28: slti        $v0, $s1, 0x8
    ctx->r2 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
    // 0x80045C2C: bne         $v0, $zero, L_80045C14
    if (ctx->r2 != 0) {
        // 0x80045C30: add.s       $f20, $f20, $f22
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f22.fl;
            goto L_80045C14;
    }
    // 0x80045C30: add.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x80045C34: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80045C38: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x80045C3C: addiu       $s6, $s7, 0x6FD0
    ctx->r22 = ADD32(ctx->r23, 0X6FD0);
    // 0x80045C40: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80045C44: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045C48: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80045C4C: lbu         $v0, 0x7151($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7151);
    // 0x80045C50: lwc1        $f20, 0x7158($v1)
    ctx->f20.u32l = MEM_W(ctx->r3, 0X7158);
    // 0x80045C54: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80045C58: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80045C5C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80045C60: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045C64: addiu       $v0, $v0, 0x74D5
    ctx->r2 = ADD32(ctx->r2, 0X74D5);
    // 0x80045C68: addu        $s4, $v1, $v0
    ctx->r20 = ADD32(ctx->r3, ctx->r2);
    // 0x80045C6C: addiu       $v0, $v0, 0x19
    ctx->r2 = ADD32(ctx->r2, 0X19);
    // 0x80045C70: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80045C74: addiu       $s5, $v1, 0x5
    ctx->r21 = ADD32(ctx->r3, 0X5);
    // 0x80045C78: addiu       $s1, $v1, 0x8
    ctx->r17 = ADD32(ctx->r3, 0X8);
    // 0x80045C7C: addiu       $s0, $s4, 0x4
    ctx->r16 = ADD32(ctx->r20, 0X4);
L_80045C80:
    // 0x80045C80: jal         0x80033960
    // 0x80045C84: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x80045C84: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x80045C88: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045C8C: lwc1        $f2, 0x7164($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X7164);
    // 0x80045C90: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80045C94: lwc1        $f0, 0x6FD0($s7)
    ctx->f0.u32l = MEM_W(ctx->r23, 0X6FD0);
    // 0x80045C98: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80045C9C: lwc1        $f2, 0x75C0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X75C0);
    // 0x80045CA0: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80045CA4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80045CA8: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80045CAC: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80045CB0: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x80045CB4: sb          $v0, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r2;
    // 0x80045CB8: lwc1        $f0, 0x4($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X4);
    // 0x80045CBC: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80045CC0: lwc1        $f2, 0x75C0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X75C0);
    // 0x80045CC4: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80045CC8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80045CCC: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80045CD0: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80045CD4: sb          $v0, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r2;
    // 0x80045CD8: lwc1        $f0, 0x8($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X8);
    // 0x80045CDC: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80045CE0: lwc1        $f2, 0x75C0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X75C0);
    // 0x80045CE4: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80045CE8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80045CEC: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80045CF0: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80045CF4: sb          $v0, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r2;
    // 0x80045CF8: lwc1        $f0, 0xC($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0XC);
    // 0x80045CFC: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80045D00: lwc1        $f2, 0x75C0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X75C0);
    // 0x80045D04: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80045D08: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80045D0C: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80045D10: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80045D14: sb          $v0, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r2;
    // 0x80045D18: lwc1        $f0, 0x10($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X10);
    // 0x80045D1C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80045D20: lwc1        $f2, 0x75C0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X75C0);
    // 0x80045D24: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80045D28: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80045D2C: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80045D30: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80045D34: sb          $v0, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r2;
    // 0x80045D38: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x80045D3C: lwc1        $f0, 0x14($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X14);
    // 0x80045D40: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80045D44: lwc1        $f2, 0x75C0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X75C0);
    // 0x80045D48: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80045D4C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80045D50: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80045D54: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80045D58: sb          $v0, -0x2($s1)
    MEM_B(-0X2, ctx->r17) = ctx->r2;
    // 0x80045D5C: lwc1        $f0, 0x18($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X18);
    // 0x80045D60: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80045D64: lwc1        $f2, 0x75C0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X75C0);
    // 0x80045D68: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80045D6C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80045D70: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80045D74: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80045D78: sb          $v0, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r2;
    // 0x80045D7C: lwc1        $f2, 0x1C($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X1C);
    // 0x80045D80: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80045D84: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80045D88: addiu       $s4, $s4, 0x5
    ctx->r20 = ADD32(ctx->r20, 0X5);
    // 0x80045D8C: addiu       $s0, $s0, 0x5
    ctx->r16 = ADD32(ctx->r16, 0X5);
    // 0x80045D90: lwc1        $f0, 0x75C0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X75C0);
    // 0x80045D94: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80045D98: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80045D9C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80045DA0: lwc1        $f4, -0x5A0C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5A0C);
    // 0x80045DA4: addiu       $s5, $s5, 0x5
    ctx->r21 = ADD32(ctx->r21, 0X5);
    // 0x80045DA8: add.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f4.fl;
    // 0x80045DAC: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80045DB0: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80045DB4: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // 0x80045DB8: slti        $v0, $s3, 0x5
    ctx->r2 = SIGNED(ctx->r19) < 0X5 ? 1 : 0;
    // 0x80045DBC: bne         $v0, $zero, L_80045C80
    if (ctx->r2 != 0) {
        // 0x80045DC0: addiu       $s1, $s1, 0x5
        ctx->r17 = ADD32(ctx->r17, 0X5);
            goto L_80045C80;
    }
    // 0x80045DC0: addiu       $s1, $s1, 0x5
    ctx->r17 = ADD32(ctx->r17, 0X5);
    // 0x80045DC4: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80045DC8: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x80045DCC: addiu       $s6, $s7, 0x6FD0
    ctx->r22 = ADD32(ctx->r23, 0X6FD0);
    // 0x80045DD0: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80045DD4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045DD8: lbu         $v1, 0x7151($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X7151);
    // 0x80045DDC: sub.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f4.fl;
    // 0x80045DE0: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80045DE4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80045DE8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80045DEC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80045DF0: addiu       $v1, $v1, 0x750C
    ctx->r3 = ADD32(ctx->r3, 0X750C);
    // 0x80045DF4: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x80045DF8: addiu       $s4, $a0, 0x5
    ctx->r20 = ADD32(ctx->r4, 0X5);
    // 0x80045DFC: addiu       $v1, $v1, 0x1E
    ctx->r3 = ADD32(ctx->r3, 0X1E);
    // 0x80045E00: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80045E04: addiu       $s5, $v0, 0x5
    ctx->r21 = ADD32(ctx->r2, 0X5);
    // 0x80045E08: addiu       $s1, $v0, 0x8
    ctx->r17 = ADD32(ctx->r2, 0X8);
    // 0x80045E0C: addiu       $s0, $a0, 0x9
    ctx->r16 = ADD32(ctx->r4, 0X9);
L_80045E10:
    // 0x80045E10: jal         0x80033960
    // 0x80045E14: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x80045E14: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_2:
    // 0x80045E18: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045E1C: lwc1        $f2, 0x7164($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X7164);
    // 0x80045E20: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80045E24: lwc1        $f0, 0x6FD0($s7)
    ctx->f0.u32l = MEM_W(ctx->r23, 0X6FD0);
    // 0x80045E28: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80045E2C: lwc1        $f2, 0x75C0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X75C0);
    // 0x80045E30: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80045E34: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80045E38: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80045E3C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80045E40: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x80045E44: sb          $v0, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r2;
    // 0x80045E48: lwc1        $f0, 0x4($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X4);
    // 0x80045E4C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80045E50: lwc1        $f2, 0x75C0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X75C0);
    // 0x80045E54: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80045E58: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80045E5C: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80045E60: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80045E64: sb          $v0, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r2;
    // 0x80045E68: lwc1        $f0, 0x8($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X8);
    // 0x80045E6C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80045E70: lwc1        $f2, 0x75C0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X75C0);
    // 0x80045E74: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80045E78: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80045E7C: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80045E80: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80045E84: sb          $v0, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r2;
    // 0x80045E88: lwc1        $f0, 0xC($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0XC);
    // 0x80045E8C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80045E90: lwc1        $f2, 0x75C0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X75C0);
    // 0x80045E94: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80045E98: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80045E9C: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80045EA0: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80045EA4: sb          $v0, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r2;
    // 0x80045EA8: lwc1        $f0, 0x10($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X10);
    // 0x80045EAC: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80045EB0: lwc1        $f2, 0x75C0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X75C0);
    // 0x80045EB4: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80045EB8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80045EBC: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80045EC0: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80045EC4: sb          $v0, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r2;
    // 0x80045EC8: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x80045ECC: lwc1        $f0, 0x14($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X14);
    // 0x80045ED0: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80045ED4: lwc1        $f2, 0x75C0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X75C0);
    // 0x80045ED8: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80045EDC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80045EE0: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80045EE4: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80045EE8: sb          $v0, -0x2($s1)
    MEM_B(-0X2, ctx->r17) = ctx->r2;
    // 0x80045EEC: lwc1        $f0, 0x18($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X18);
    // 0x80045EF0: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80045EF4: lwc1        $f2, 0x75C0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X75C0);
    // 0x80045EF8: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80045EFC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80045F00: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80045F04: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80045F08: sb          $v0, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r2;
    // 0x80045F0C: lwc1        $f2, 0x1C($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X1C);
    // 0x80045F10: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80045F14: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80045F18: lwc1        $f0, -0x5A08($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5A08);
    // 0x80045F1C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80045F20: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x80045F24: addiu       $s4, $s4, 0x5
    ctx->r20 = ADD32(ctx->r20, 0X5);
    // 0x80045F28: lwc1        $f0, 0x75C0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X75C0);
    // 0x80045F2C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80045F30: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80045F34: addiu       $s0, $s0, 0x5
    ctx->r16 = ADD32(ctx->r16, 0X5);
    // 0x80045F38: addiu       $s5, $s5, 0x5
    ctx->r21 = ADD32(ctx->r21, 0X5);
    // 0x80045F3C: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80045F40: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80045F44: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // 0x80045F48: slti        $v0, $s3, 0x5
    ctx->r2 = SIGNED(ctx->r19) < 0X5 ? 1 : 0;
    // 0x80045F4C: bne         $v0, $zero, L_80045E10
    if (ctx->r2 != 0) {
        // 0x80045F50: addiu       $s1, $s1, 0x5
        ctx->r17 = ADD32(ctx->r17, 0X5);
            goto L_80045E10;
    }
    // 0x80045F50: addiu       $s1, $s1, 0x5
    ctx->r17 = ADD32(ctx->r17, 0X5);
    // 0x80045F54: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80045F58: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045F5C: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // 0x80045F60: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045F64: addiu       $v0, $v0, 0x7450
    ctx->r2 = ADD32(ctx->r2, 0X7450);
    // 0x80045F68: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x80045F6C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80045F70: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045F74: addiu       $v0, $v0, 0x74D0
    ctx->r2 = ADD32(ctx->r2, 0X74D0);
    // 0x80045F78: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80045F7C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045F80: lbu         $v1, 0x7151($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X7151);
    // 0x80045F84: addiu       $s0, $v0, 0x7170
    ctx->r16 = ADD32(ctx->r2, 0X7170);
    // 0x80045F88: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80045F8C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80045F90: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80045F94: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80045F98: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
L_80045F9C:
    // 0x80045F9C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80045FA0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80045FA4: lbu         $v0, 0x7151($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X7151);
    // 0x80045FA8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80045FAC: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80045FB0: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80045FB4: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80045FB8: addu        $v1, $v1, $s1
    ctx->r3 = ADD32(ctx->r3, ctx->r17);
    // 0x80045FBC: addiu       $v1, $v1, 0x5
    ctx->r3 = ADD32(ctx->r3, 0X5);
    // 0x80045FC0: jal         0x80049814
    // 0x80045FC4: sw          $v1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r3;
    func_80049814(rdram, ctx);
        goto after_3;
    // 0x80045FC4: sw          $v1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r3;
    after_3:
    // 0x80045FC8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80045FCC: jal         0x80049BBC
    // 0x80045FD0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_80049BBC(rdram, ctx);
        goto after_4;
    // 0x80045FD0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_4:
    // 0x80045FD4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80045FD8: jal         0x80049FB8
    // 0x80045FDC: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_80049FB8(rdram, ctx);
        goto after_5;
    // 0x80045FDC: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_5:
    // 0x80045FE0: jal         0x8004AA94
    // 0x80045FE4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8004AA94(rdram, ctx);
        goto after_6;
    // 0x80045FE4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // 0x80045FE8: addiu       $s1, $s1, 0x1E
    ctx->r17 = ADD32(ctx->r17, 0X1E);
    // 0x80045FEC: sb          $s5, 0x57($s0)
    MEM_B(0X57, ctx->r16) = ctx->r21;
    // 0x80045FF0: slti        $v0, $s3, 0x4
    ctx->r2 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
    // 0x80045FF4: bne         $v0, $zero, L_80045F9C
    if (ctx->r2 != 0) {
        // 0x80045FF8: addiu       $s0, $s0, 0xB8
        ctx->r16 = ADD32(ctx->r16, 0XB8);
            goto L_80045F9C;
    }
    // 0x80045FF8: addiu       $s0, $s0, 0xB8
    ctx->r16 = ADD32(ctx->r16, 0XB8);
L_80045FFC:
    // 0x80045FFC: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80046000: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x80046004: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x80046008: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8004600C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80046010: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80046014: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80046018: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8004601C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80046020: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x80046024: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x80046028: jr          $ra
    // 0x8004602C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8004602C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80046030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046030: addu        $t2, $a0, $zero
    ctx->r10 = ADD32(ctx->r4, 0);
    // 0x80046034: lhu         $v0, 0x14($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X14);
    // 0x80046038: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // 0x8004603C: beq         $v0, $zero, L_800460E0
    if (ctx->r2 == 0) {
        // 0x80046040: addu        $t1, $zero, $zero
        ctx->r9 = ADD32(0, 0);
            goto L_800460E0;
    }
    // 0x80046040: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x80046044: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80046048: lhu         $a1, 0x1A($t2)
    ctx->r5 = MEM_HU(ctx->r10, 0X1A);
    // 0x8004604C: lhu         $v1, 0x18($t2)
    ctx->r3 = MEM_HU(ctx->r10, 0X18);
    // 0x80046050: lbu         $v0, 0x7151($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7151);
    // 0x80046054: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    // 0x80046058: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x8004605C: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x80046060: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x80046064: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x80046068: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8004606C: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80046070: sll         $v0, $a1, 4
    ctx->r2 = S32(ctx->r5 << 4);
    // 0x80046074: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x80046078: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8004607C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80046080: addiu       $v1, $v1, 0x74D0
    ctx->r3 = ADD32(ctx->r3, 0X74D0);
    // 0x80046084: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80046088: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004608C: addiu       $a0, $a0, 0x5
    ctx->r4 = ADD32(ctx->r4, 0X5);
    // 0x80046090: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80046094: addiu       $v1, $v1, 0x7170
    ctx->r3 = ADD32(ctx->r3, 0X7170);
    // 0x80046098: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8004609C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800460A0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800460A4: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x800460A8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800460AC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800460B0: sw          $a0, 0x44($t2)
    MEM_W(0X44, ctx->r10) = ctx->r4;
    // 0x800460B4: lhu         $v1, 0xA($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XA);
    // 0x800460B8: sh          $v1, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r3;
    // 0x800460BC: lhu         $v1, 0xC($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XC);
    // 0x800460C0: sh          $v1, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r3;
    // 0x800460C4: lhu         $v1, 0xE($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XE);
    // 0x800460C8: sh          $v1, 0xE($t2)
    MEM_H(0XE, ctx->r10) = ctx->r3;
    // 0x800460CC: lhu         $v1, 0x10($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X10);
    // 0x800460D0: sh          $v1, 0x10($t2)
    MEM_H(0X10, ctx->r10) = ctx->r3;
    // 0x800460D4: lhu         $v0, 0x12($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X12);
    // 0x800460D8: jr          $ra
    // 0x800460DC: sh          $v0, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r2;
    return;
    // 0x800460DC: sh          $v0, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r2;
L_800460E0:
    // 0x800460E0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800460E4: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800460E8: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800460EC: addiu       $t0, $a3, 0x6DC0
    ctx->r8 = ADD32(ctx->r7, 0X6DC0);
    // 0x800460F0: lbu         $a2, 0x7151($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X7151);
    // 0x800460F4: lhu         $v1, 0x1A($t2)
    ctx->r3 = MEM_HU(ctx->r10, 0X1A);
    // 0x800460F8: lhu         $v0, 0x18($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X18);
    // 0x800460FC: lh          $a1, 0x1A($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X1A);
    // 0x80046100: sll         $a0, $a2, 4
    ctx->r4 = S32(ctx->r6 << 4);
    // 0x80046104: subu        $a0, $a0, $a2
    ctx->r4 = SUB32(ctx->r4, ctx->r6);
    // 0x80046108: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x8004610C: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x80046110: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80046114: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80046118: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004611C: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80046120: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80046124: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80046128: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004612C: addiu       $v1, $v1, 0x74D0
    ctx->r3 = ADD32(ctx->r3, 0X74D0);
    // 0x80046130: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80046134: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80046138: addiu       $t3, $a0, 0x5
    ctx->r11 = ADD32(ctx->r4, 0X5);
    // 0x8004613C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80046140: addiu       $v0, $v0, 0x7148
    ctx->r2 = ADD32(ctx->r2, 0X7148);
    // 0x80046144: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80046148: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8004614C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80046150: lw          $v1, 0x7168($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X7168);
    // 0x80046154: lhu         $v0, 0x38($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X38);
    // 0x80046158: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
    // 0x8004615C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80046160: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80046164: mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80046168: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8004616C: lh          $v0, 0x18($t2)
    ctx->r2 = MEM_H(ctx->r10, 0X18);
    // 0x80046170: lw          $v1, 0x6DC0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X6DC0);
    // 0x80046174: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x80046178: mflo        $t5
    ctx->r13 = lo;
    // 0x8004617C: addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // 0x80046180: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80046184: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80046188: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8004618C: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
    // 0x80046190: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x80046194: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80046198: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004619C: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x800461A0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800461A4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800461A8: addiu       $a3, $v1, 0x5
    ctx->r7 = ADD32(ctx->r3, 0X5);
    // 0x800461AC: addu        $v0, $a3, $t1
    ctx->r2 = ADD32(ctx->r7, ctx->r9);
L_800461B0:
    // 0x800461B0: lb          $v1, 0x0($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X0);
    // 0x800461B4: lw          $a0, 0x75C0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X75C0);
    // 0x800461B8: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800461BC: slt         $v1, $v1, $a0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800461C0: bne         $v1, $zero, L_800461D0
    if (ctx->r3 != 0) {
        // 0x800461C4: addu        $a2, $a1, $t1
        ctx->r6 = ADD32(ctx->r5, ctx->r9);
            goto L_800461D0;
    }
    // 0x800461C4: addu        $a2, $a1, $t1
    ctx->r6 = ADD32(ctx->r5, ctx->r9);
    // 0x800461C8: addu        $v0, $t3, $t1
    ctx->r2 = ADD32(ctx->r11, ctx->r9);
    // 0x800461CC: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
L_800461D0:
    // 0x800461D0: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x800461D4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800461D8: slti        $v0, $t1, 0x19
    ctx->r2 = SIGNED(ctx->r9) < 0X19 ? 1 : 0;
    // 0x800461DC: bne         $v0, $zero, L_800461B0
    if (ctx->r2 != 0) {
        // 0x800461E0: addu        $v0, $a3, $t1
        ctx->r2 = ADD32(ctx->r7, ctx->r9);
            goto L_800461B0;
    }
    // 0x800461E0: addu        $v0, $a3, $t1
    ctx->r2 = ADD32(ctx->r7, ctx->r9);
    // 0x800461E4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800461E8: sw          $a1, 0x44($t2)
    MEM_W(0X44, ctx->r10) = ctx->r5;
    // 0x800461EC: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800461F0: lw          $v1, 0x7168($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X7168);
    // 0x800461F4: lw          $v0, -0x2140($a1)
    ctx->r2 = MEM_W(ctx->r5, -0X2140);
    // 0x800461F8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800461FC: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80046200: beq         $v0, $zero, L_8004620C
    if (ctx->r2 == 0) {
        // 0x80046204: sw          $v1, 0x7168($a0)
        MEM_W(0X7168, ctx->r4) = ctx->r3;
            goto L_8004620C;
    }
    // 0x80046204: sw          $v1, 0x7168($a0)
    MEM_W(0X7168, ctx->r4) = ctx->r3;
    // 0x80046208: sw          $v1, -0x2140($a1)
    MEM_W(-0X2140, ctx->r5) = ctx->r3;
L_8004620C:
    // 0x8004620C: jr          $ra
    // 0x80046210: nop

    return;
    // 0x80046210: nop

;}
RECOMP_FUNC void func_80046214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046214: addu        $t1, $a0, $zero
    ctx->r9 = ADD32(ctx->r4, 0);
    // 0x80046218: lhu         $t0, 0x1A($t1)
    ctx->r8 = MEM_HU(ctx->r9, 0X1A);
    // 0x8004621C: lhu         $t2, 0x18($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X18);
    // 0x80046220: lhu         $a0, 0x14($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X14);
    // 0x80046224: andi        $v1, $t0, 0x1
    ctx->r3 = ctx->r8 & 0X1;
    // 0x80046228: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8004622C: andi        $v0, $t2, 0x1
    ctx->r2 = ctx->r10 & 0X1;
    // 0x80046230: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80046234: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80046238: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004623C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80046240: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80046244: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80046248: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004624C: addiu       $v1, $v1, 0x71C4
    ctx->r3 = ADD32(ctx->r3, 0X71C4);
    // 0x80046250: andi        $a0, $a0, 0x40
    ctx->r4 = ctx->r4 & 0X40;
    // 0x80046254: beq         $a0, $zero, L_80046264
    if (ctx->r4 == 0) {
        // 0x80046258: addu        $a3, $v0, $v1
        ctx->r7 = ADD32(ctx->r2, ctx->r3);
            goto L_80046264;
    }
    // 0x80046258: addu        $a3, $v0, $v1
    ctx->r7 = ADD32(ctx->r2, ctx->r3);
    // 0x8004625C: jr          $ra
    // 0x80046260: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    return;
    // 0x80046260: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
L_80046264:
    // 0x80046264: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80046268: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8004626C: addiu       $a1, $a0, 0x6DC0
    ctx->r5 = ADD32(ctx->r4, 0X6DC0);
    // 0x80046270: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x80046274: lhu         $v1, 0x38($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X38);
    // 0x80046278: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8004627C: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80046280: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80046284: sll         $v0, $t2, 16
    ctx->r2 = S32(ctx->r10 << 16);
    // 0x80046288: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8004628C: lw          $v1, 0x6DC0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X6DC0);
    // 0x80046290: mflo        $t3
    ctx->r11 = lo;
    // 0x80046294: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x80046298: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8004629C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800462A0: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x800462A4: addu        $a0, $t1, $zero
    ctx->r4 = ADD32(ctx->r9, 0);
    // 0x800462A8: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x800462AC: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x800462B0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800462B4: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x800462B8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800462BC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800462C0: addiu       $a1, $v1, 0x5
    ctx->r5 = ADD32(ctx->r3, 0X5);
L_800462C4:
    // 0x800462C4: addu        $v0, $a1, $a2
    ctx->r2 = ADD32(ctx->r5, ctx->r6);
    // 0x800462C8: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x800462CC: lw          $v1, 0x75C0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X75C0);
    // 0x800462D0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800462D4: bnel        $v0, $zero, L_800462F0
    if (ctx->r2 != 0) {
        // 0x800462D8: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_800462F0;
    }
    goto skip_0;
    // 0x800462D8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    skip_0:
    // 0x800462DC: lwl         $t4, 0x0($a3)
    ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r7, 0X0);
    // 0x800462E0: lwr         $t4, 0x3($a3)
    ctx->r12 = do_lwr(rdram, ctx->r12, ctx->r7, 0X3);
    // 0x800462E4: swl         $t4, 0x54($a0)
    do_swl(rdram, 0X54, ctx->r4, ctx->r12);
    // 0x800462E8: swr         $t4, 0x57($a0)
    do_swr(rdram, 0X57, ctx->r4, ctx->r12);
    // 0x800462EC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_800462F0:
    // 0x800462F0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800462F4: slti        $v0, $a2, 0x19
    ctx->r2 = SIGNED(ctx->r6) < 0X19 ? 1 : 0;
    // 0x800462F8: bne         $v0, $zero, L_800462C4
    if (ctx->r2 != 0) {
        // 0x800462FC: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800462C4;
    }
    // 0x800462FC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80046300: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80046304: sb          $v0, 0x57($t1)
    MEM_B(0X57, ctx->r9) = ctx->r2;
    // 0x80046308: jr          $ra
    // 0x8004630C: addiu       $v0, $t1, 0x54
    ctx->r2 = ADD32(ctx->r9, 0X54);
    return;
    // 0x8004630C: addiu       $v0, $t1, 0x54
    ctx->r2 = ADD32(ctx->r9, 0X54);
;}
RECOMP_FUNC void func_80046310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046310: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80046314: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80046318: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8004631C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80046320: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80046324: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80046328: jal         0x8006B180
    // 0x8004632C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    isCraftAvailableByIdx(rdram, ctx);
        goto after_0;
    // 0x8004632C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_0:
    // 0x80046330: beq         $v0, $zero, L_80046344
    if (ctx->r2 == 0) {
        // 0x80046334: addiu       $a2, $zero, 0xF
        ctx->r6 = ADD32(0, 0XF);
            goto L_80046344;
    }
    // 0x80046334: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80046338: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004633C: j           L_80046470
    // 0x80046340: sw          $zero, 0x7140($v0)
    MEM_W(0X7140, ctx->r2) = 0;
        goto L_80046470;
    // 0x80046340: sw          $zero, 0x7140($v0)
    MEM_W(0X7140, ctx->r2) = 0;
L_80046344:
    // 0x80046344: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80046348: addiu       $v0, $v0, 0x7130
    ctx->r2 = ADD32(ctx->r2, 0X7130);
    // 0x8004634C: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
L_80046350:
    // 0x80046350: sb          $a2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r6;
    // 0x80046354: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80046358: bgez        $a2, L_80046350
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8004635C: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80046350;
    }
    // 0x8004635C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80046360: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80046364: addiu       $a3, $s0, 0x3
    ctx->r7 = ADD32(ctx->r16, 0X3);
    // 0x80046368: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x8004636C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80046370: addiu       $v0, $v0, 0x6DC0
    ctx->r2 = ADD32(ctx->r2, 0X6DC0);
    // 0x80046374: addu        $t1, $v0, $zero
    ctx->r9 = ADD32(ctx->r2, 0);
    // 0x80046378: addiu       $t2, $zero, -0x8000
    ctx->r10 = ADD32(0, -0X8000);
    // 0x8004637C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80046380: addiu       $a1, $v0, 0x6FF0
    ctx->r5 = ADD32(ctx->r2, 0X6FF0);
    // 0x80046384: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x80046388: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004638C: lwc1        $f2, -0x5A04($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5A04);
    // 0x80046390: lw          $v1, 0xC($t1)
    ctx->r3 = MEM_W(ctx->r9, 0XC);
    // 0x80046394: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80046398: lwc1        $f4, -0x5A00($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5A00);
    // 0x8004639C: addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
L_800463A0:
    // 0x800463A0: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800463A4: beq         $v0, $t0, L_8004646C
    if (ctx->r2 == ctx->r8) {
        // 0x800463A8: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004646C;
    }
    // 0x800463A8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800463AC: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x800463B0: swc1        $f20, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f20.u32l;
    // 0x800463B4: lhu         $v0, 0x8($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X8);
    // 0x800463B8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800463BC: lwc1        $f0, -0x59FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X59FC);
    // 0x800463C0: beq         $v0, $zero, L_800463D0
    if (ctx->r2 == 0) {
        // 0x800463C4: nop
    
            goto L_800463D0;
    }
    // 0x800463C4: nop

    // 0x800463C8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800463CC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
L_800463D0:
    // 0x800463D0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800463D4: nop

    // 0x800463D8: bc1f        L_800463E4
    if (!c1cs) {
        // 0x800463DC: swc1        $f0, 0x10($a1)
        MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
            goto L_800463E4;
    }
    // 0x800463DC: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x800463E0: swc1        $f2, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f2.u32l;
L_800463E4:
    // 0x800463E4: sh          $a3, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r7;
    // 0x800463E8: lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X4);
    // 0x800463EC: sh          $v0, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r2;
    // 0x800463F0: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800463F4: sh          $v0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r2;
    // 0x800463F8: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x800463FC: lw          $v0, 0xC($t1)
    ctx->r2 = MEM_W(ctx->r9, 0XC);
    // 0x80046400: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80046404: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80046408: or          $v0, $a3, $t2
    ctx->r2 = ctx->r7 | ctx->r10;
    // 0x8004640C: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80046410: lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X4);
    // 0x80046414: beq         $v0, $zero, L_80046440
    if (ctx->r2 == 0) {
        // 0x80046418: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80046440;
    }
    // 0x80046418: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8004641C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_80046420:
    // 0x80046420: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // 0x80046424: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80046428: sh          $t0, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r8;
    // 0x8004642C: lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X4);
    // 0x80046430: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80046434: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80046438: bne         $v0, $zero, L_80046420
    if (ctx->r2 != 0) {
        // 0x8004643C: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80046420;
    }
    // 0x8004643C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_80046440:
    // 0x80046440: addiu       $v0, $a3, 0x3
    ctx->r2 = ADD32(ctx->r7, 0X3);
    // 0x80046444: addu        $a3, $v0, $v1
    ctx->r7 = ADD32(ctx->r2, ctx->r3);
    // 0x80046448: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8004644C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80046450: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80046454: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    // 0x80046458: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8004645C: slti        $v0, $a2, 0x10
    ctx->r2 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x80046460: bne         $v0, $zero, L_800463A0
    if (ctx->r2 != 0) {
        // 0x80046464: add.s       $f20, $f20, $f4
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f4.fl;
            goto L_800463A0;
    }
    // 0x80046464: add.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f4.fl;
    // 0x80046468: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_8004646C:
    // 0x8004646C: sw          $a2, 0x7140($v0)
    MEM_W(0X7140, ctx->r2) = ctx->r6;
L_80046470:
    // 0x80046470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80046474: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80046478: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8004647C: jr          $ra
    // 0x80046480: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80046480: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80046484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046484: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80046488: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x8004648C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80046490: lw          $v0, 0x7140($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X7140);
    // 0x80046494: blez        $v0, L_800465A0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80046498: addu        $a2, $t1, $zero
        ctx->r6 = ADD32(ctx->r9, 0);
            goto L_800465A0;
    }
    // 0x80046498: addu        $a2, $t1, $zero
    ctx->r6 = ADD32(ctx->r9, 0);
    // 0x8004649C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800464A0: addiu       $t6, $v0, 0x7130
    ctx->r14 = ADD32(ctx->r2, 0X7130);
    // 0x800464A4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800464A8: addiu       $t5, $v0, 0x6FF0
    ctx->r13 = ADD32(ctx->r2, 0X6FF0);
    // 0x800464AC: addiu       $t4, $zero, -0x8000
    ctx->r12 = ADD32(0, -0X8000);
    // 0x800464B0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800464B4: addiu       $t0, $v0, 0x6DC0
    ctx->r8 = ADD32(ctx->r2, 0X6DC0);
    // 0x800464B8: addiu       $t3, $zero, -0x4001
    ctx->r11 = ADD32(0, -0X4001);
    // 0x800464BC: addu        $t2, $v1, $zero
    ctx->r10 = ADD32(ctx->r3, 0);
    // 0x800464C0: addu        $v0, $a2, $t6
    ctx->r2 = ADD32(ctx->r6, ctx->r14);
L_800464C4:
    // 0x800464C4: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800464C8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800464CC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800464D0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800464D4: addu        $a0, $v0, $t5
    ctx->r4 = ADD32(ctx->r2, ctx->r13);
    // 0x800464D8: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800464DC: mul.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800464E0: lwc1        $f2, 0xC($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800464E4: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800464E8: lhu         $v1, 0x6($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X6);
    // 0x800464EC: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800464F0: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800464F4: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x800464F8: bne         $v1, $zero, L_80046504
    if (ctx->r3 != 0) {
        // 0x800464FC: nop
    
            goto L_80046504;
    }
    // 0x800464FC: nop

    // 0x80046500: break       7
    do_break(2147771648);
L_80046504:
    // 0x80046504: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80046508: bne         $v1, $at, L_8004651C
    if (ctx->r3 != ctx->r1) {
        // 0x8004650C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8004651C;
    }
    // 0x8004650C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80046510: bne         $v0, $at, L_8004651C
    if (ctx->r2 != ctx->r1) {
        // 0x80046514: nop
    
            goto L_8004651C;
    }
    // 0x80046514: nop

    // 0x80046518: break       6
    do_break(2147771672);
L_8004651C:
    // 0x8004651C: mfhi        $v1
    ctx->r3 = hi;
    // 0x80046520: lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X4);
    // 0x80046524: swc1        $f2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f2.u32l;
    // 0x80046528: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004652C: or          $a3, $v0, $t4
    ctx->r7 = ctx->r2 | ctx->r12;
    // 0x80046530: slti        $v0, $t1, 0x4
    ctx->r2 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x80046534: beq         $v0, $zero, L_8004658C
    if (ctx->r2 == 0) {
        // 0x80046538: addu        $a1, $a3, $zero
        ctx->r5 = ADD32(ctx->r7, 0);
            goto L_8004658C;
    }
    // 0x80046538: addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
    // 0x8004653C: lhu         $v0, 0x8($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X8);
    // 0x80046540: lw          $v1, 0xC($t0)
    ctx->r3 = MEM_W(ctx->r8, 0XC);
    // 0x80046544: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80046548: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // 0x8004654C: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80046550: andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // 0x80046554: beq         $v0, $zero, L_8004658C
    if (ctx->r2 == 0) {
        // 0x80046558: nop
    
            goto L_8004658C;
    }
    // 0x80046558: nop

    // 0x8004655C: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80046560: andi        $v1, $a1, 0xFFFF
    ctx->r3 = ctx->r5 & 0XFFFF;
    // 0x80046564: and         $v0, $v0, $t3
    ctx->r2 = ctx->r2 & ctx->r11;
    // 0x80046568: beq         $v0, $v1, L_8004658C
    if (ctx->r2 == ctx->r3) {
        // 0x8004656C: addu        $v0, $sp, $t1
        ctx->r2 = ADD32(ctx->r29, ctx->r9);
            goto L_8004658C;
    }
    // 0x8004656C: addu        $v0, $sp, $t1
    ctx->r2 = ADD32(ctx->r29, ctx->r9);
    // 0x80046570: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80046574: sb          $a2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r6;
    // 0x80046578: lhu         $v0, 0x8($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X8);
    // 0x8004657C: lw          $v1, 0xC($t0)
    ctx->r3 = MEM_W(ctx->r8, 0XC);
    // 0x80046580: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80046584: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80046588: sh          $a3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r7;
L_8004658C:
    // 0x8004658C: lw          $v0, 0x7140($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X7140);
    // 0x80046590: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80046594: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80046598: bne         $v0, $zero, L_800464C4
    if (ctx->r2 != 0) {
        // 0x8004659C: addu        $v0, $a2, $t6
        ctx->r2 = ADD32(ctx->r6, ctx->r14);
            goto L_800464C4;
    }
    // 0x8004659C: addu        $v0, $a2, $t6
    ctx->r2 = ADD32(ctx->r6, ctx->r14);
L_800465A0:
    // 0x800465A0: blez        $t1, L_80046614
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800465A4: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_80046614;
    }
    // 0x800465A4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800465A8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800465AC: addiu       $a3, $v0, 0x7130
    ctx->r7 = ADD32(ctx->r2, 0X7130);
    // 0x800465B0: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800465B4: addu        $v0, $sp, $a2
    ctx->r2 = ADD32(ctx->r29, ctx->r6);
L_800465B8:
    // 0x800465B8: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800465BC: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800465C0: addu        $v1, $a1, $a3
    ctx->r3 = ADD32(ctx->r5, ctx->r7);
    // 0x800465C4: lw          $v0, 0x7140($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X7140);
    // 0x800465C8: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
    // 0x800465CC: j           L_800465F0
    // 0x800465D0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_800465F0;
    // 0x800465D0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800465D4:
    // 0x800465D4: addu        $v0, $a0, $a3
    ctx->r2 = ADD32(ctx->r4, ctx->r7);
    // 0x800465D8: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800465DC: addu        $v0, $a1, $a3
    ctx->r2 = ADD32(ctx->r5, ctx->r7);
    // 0x800465E0: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x800465E4: lw          $v0, 0x7140($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X7140);
    // 0x800465E8: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800465EC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800465F0:
    // 0x800465F0: slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800465F4: bne         $v0, $zero, L_800465D4
    if (ctx->r2 != 0) {
        // 0x800465F8: addiu       $a0, $a1, 0x1
        ctx->r4 = ADD32(ctx->r5, 0X1);
            goto L_800465D4;
    }
    // 0x800465F8: addiu       $a0, $a1, 0x1
    ctx->r4 = ADD32(ctx->r5, 0X1);
    // 0x800465FC: addu        $v0, $a1, $a3
    ctx->r2 = ADD32(ctx->r5, ctx->r7);
    // 0x80046600: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
    // 0x80046604: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80046608: slt         $v0, $a2, $t1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8004660C: bne         $v0, $zero, L_800465B8
    if (ctx->r2 != 0) {
        // 0x80046610: addu        $v0, $sp, $a2
        ctx->r2 = ADD32(ctx->r29, ctx->r6);
            goto L_800465B8;
    }
    // 0x80046610: addu        $v0, $sp, $a2
    ctx->r2 = ADD32(ctx->r29, ctx->r6);
L_80046614:
    // 0x80046614: jr          $ra
    // 0x80046618: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80046618: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void fake_func_8004661C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void parseDatItemCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046620: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80046624: addiu       $v0, $v0, 0x75D8
    ctx->r2 = ADD32(ctx->r2, 0X75D8);
    // 0x80046628: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8004662C: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80046630: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80046634: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80046638: lwc1        $f2, -0x59F0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X59F0);
    // 0x8004663C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80046640: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80046644: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80046648: bgez        $a2, L_80046658
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8004664C: nop
    
            goto L_80046658;
    }
    // 0x8004664C: nop

    // 0x80046650: j           L_80046668
    // 0x80046654: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
        goto L_80046668;
    // 0x80046654: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80046658:
    // 0x80046658: lw          $v1, 0x14($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14);
    // 0x8004665C: slt         $v0, $a2, $v1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80046660: beql        $v0, $zero, L_80046668
    if (ctx->r2 == 0) {
        // 0x80046664: addiu       $a2, $v1, -0x1
        ctx->r6 = ADD32(ctx->r3, -0X1);
            goto L_80046668;
    }
    goto skip_0;
    // 0x80046664: addiu       $a2, $v1, -0x1
    ctx->r6 = ADD32(ctx->r3, -0X1);
    skip_0:
L_80046668:
    // 0x80046668: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004666C: addiu       $v0, $v0, 0x75D8
    ctx->r2 = ADD32(ctx->r2, 0X75D8);
    // 0x80046670: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80046674: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80046678: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004667C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80046680: lwc1        $f2, -0x59EC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X59EC);
    // 0x80046684: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80046688: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004668C: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x80046690: bgez        $v1, L_800466A0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80046694: nop
    
            goto L_800466A0;
    }
    // 0x80046694: nop

    // 0x80046698: j           L_800466B0
    // 0x8004669C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_800466B0;
    // 0x8004669C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800466A0:
    // 0x800466A0: lw          $a1, 0x18($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X18);
    // 0x800466A4: slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800466A8: beql        $v0, $zero, L_800466B0
    if (ctx->r2 == 0) {
        // 0x800466AC: addiu       $v1, $a1, -0x1
        ctx->r3 = ADD32(ctx->r5, -0X1);
            goto L_800466B0;
    }
    goto skip_1;
    // 0x800466AC: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    skip_1:
L_800466B0:
    // 0x800466B0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800466B4: addiu       $t2, $v0, 0x75D8
    ctx->r10 = ADD32(ctx->r2, 0X75D8);
    // 0x800466B8: lw          $v0, 0x14($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X14);
    // 0x800466BC: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800466C0: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800466C4: lhu         $t0, 0x6FC0($a3)
    ctx->r8 = MEM_HU(ctx->r7, 0X6FC0);
    // 0x800466C8: ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
    // 0x800466CC: andi        $v1, $t0, 0xFFFF
    ctx->r3 = ctx->r8 & 0XFFFF;
    // 0x800466D0: mflo        $t5
    ctx->r13 = lo;
    // 0x800466D4: beq         $v1, $t1, L_8004677C
    if (ctx->r3 == ctx->r9) {
        // 0x800466D8: addu        $t3, $a2, $t5
        ctx->r11 = ADD32(ctx->r6, ctx->r13);
            goto L_8004677C;
    }
    // 0x800466D8: addu        $t3, $a2, $t5
    ctx->r11 = ADD32(ctx->r6, ctx->r13);
    // 0x800466DC: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800466E0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800466E4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800466E8: lw          $a2, 0x6FCC($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X6FCC);
    // 0x800466EC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800466F0: addu        $a1, $a2, $v0
    ctx->r5 = ADD32(ctx->r6, ctx->r2);
    // 0x800466F4: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x800466F8: sh          $v0, 0x6FC0($a3)
    MEM_H(0X6FC0, ctx->r7) = ctx->r2;
    // 0x800466FC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80046700: beq         $v0, $t1, L_80046720
    if (ctx->r2 == ctx->r9) {
        // 0x80046704: nop
    
            goto L_80046720;
    }
    // 0x80046704: nop

    // 0x80046708: lhu         $v1, 0x6FC0($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X6FC0);
    // 0x8004670C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80046710: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80046714: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80046718: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8004671C: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
L_80046720:
    // 0x80046720: lw          $v0, 0x1C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X1C);
    // 0x80046724: sll         $a2, $t3, 1
    ctx->r6 = S32(ctx->r11 << 1);
    // 0x80046728: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x8004672C: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80046730: sh          $v0, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r2;
    // 0x80046734: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80046738: beq         $v0, $t1, L_80046760
    if (ctx->r2 == ctx->r9) {
        // 0x8004673C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80046760;
    }
    // 0x8004673C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80046740: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x80046744: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80046748: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004674C: lw          $v0, 0x6FCC($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X6FCC);
    // 0x80046750: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80046754: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80046758: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
    // 0x8004675C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80046760:
    // 0x80046760: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x80046764: sh          $t3, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r11;
    // 0x80046768: sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
    // 0x8004676C: sw          $a0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r4;
    // 0x80046770: lw          $v0, 0x1C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X1C);
    // 0x80046774: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80046778: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
L_8004677C:
    // 0x8004677C: jr          $ra
    // 0x80046780: nop

    return;
    // 0x80046780: nop

;}
RECOMP_FUNC void loadDatFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046784: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80046788: sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // 0x8004678C: addu        $fp, $a0, $zero
    ctx->r30 = ADD32(ctx->r4, 0);
    // 0x80046790: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80046794: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80046798: addiu       $a1, $a1, -0x59E8
    ctx->r5 = ADD32(ctx->r5, -0X59E8);
    // 0x8004679C: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x800467A0: sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // 0x800467A4: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x800467A8: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x800467AC: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x800467B0: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x800467B4: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x800467B8: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x800467BC: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x800467C0: sdc1        $f20, 0x80($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X80, ctx->r29);
    // 0x800467C4: jal         0x80033CC4
    // 0x800467C8: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800467C8: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    after_0:
    // 0x800467CC: jal         0x8006488C
    // 0x800467D0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    load_asset(rdram, ctx);
        goto after_1;
    // 0x800467D0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x800467D4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800467D8: addiu       $v1, $v1, 0x6DC0
    ctx->r3 = ADD32(ctx->r3, 0X6DC0);
    // 0x800467DC: lwc1        $f2, 0x20($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X20);
    // 0x800467E0: lwc1        $f4, 0x2C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x800467E4: lwc1        $f6, 0x24($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X24);
    // 0x800467E8: lwc1        $f8, 0x30($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X30);
    // 0x800467EC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800467F0: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x800467F4: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x800467F8: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x800467FC: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x80046800: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x80046804: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80046808: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8004680C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80046810: beq         $v0, $zero, L_800469BC
    if (ctx->r2 == 0) {
        // 0x80046814: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_800469BC;
    }
    // 0x80046814: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80046818: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x8004681C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80046820: addu        $a3, $s2, $v0
    ctx->r7 = ADD32(ctx->r18, ctx->r2);
    // 0x80046824: beq         $v1, $zero, L_800469C0
    if (ctx->r3 == 0) {
        // 0x80046828: sw          $a3, 0x4($s2)
        MEM_W(0X4, ctx->r18) = ctx->r7;
            goto L_800469C0;
    }
    // 0x80046828: sw          $a3, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r7;
    // 0x8004682C: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // 0x80046830: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x80046834: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80046838: addiu       $t4, $v0, -0x59C0
    ctx->r12 = ADD32(ctx->r2, -0X59C0);
    // 0x8004683C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80046840: addiu       $t3, $v0, 0xB40
    ctx->r11 = ADD32(ctx->r2, 0XB40);
    // 0x80046844: addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
    // 0x80046848: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004684C: lbu         $t2, 0xB39($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0XB39);
    // 0x80046850: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80046854: lbu         $t1, 0xBA0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0XBA0);
    // 0x80046858: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004685C: lw          $t0, 0xB70($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XB70);
L_80046860:
    // 0x80046860: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80046864: addu        $a0, $a3, $v0
    ctx->r4 = ADD32(ctx->r7, ctx->r2);
    // 0x80046868: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x8004686C: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x80046870: beq         $v0, $zero, L_80046888
    if (ctx->r2 == 0) {
        // 0x80046874: addu        $v0, $a0, $v0
        ctx->r2 = ADD32(ctx->r4, ctx->r2);
            goto L_80046888;
    }
    // 0x80046874: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80046878: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // 0x8004687C: sh          $a2, 0x34($a0)
    MEM_H(0X34, ctx->r4) = ctx->r6;
    // 0x80046880: sh          $a2, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r6;
    // 0x80046884: sw          $t5, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r13;
L_80046888:
    // 0x80046888: lw          $v0, 0x4C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4C);
    // 0x8004688C: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80046890: bne         $v0, $zero, L_800468A8
    if (ctx->r2 != 0) {
        // 0x80046894: nop
    
            goto L_800468A8;
    }
    // 0x80046894: nop

    // 0x80046898: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x8004689C: beq         $v0, $zero, L_800468A8
    if (ctx->r2 == 0) {
        // 0x800468A0: addu        $v0, $a0, $v0
        ctx->r2 = ADD32(ctx->r4, ctx->r2);
            goto L_800468A8;
    }
    // 0x800468A0: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800468A4: sw          $v0, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->r2;
L_800468A8:
    // 0x800468A8: beq         $t2, $zero, L_800468E0
    if (ctx->r10 == 0) {
        // 0x800468AC: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800468E0;
    }
    // 0x800468AC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800468B0: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x800468B4: sltiu       $v0, $v1, 0x4C
    ctx->r2 = ctx->r3 < 0X4C ? 1 : 0;
    // 0x800468B8: beq         $v0, $zero, L_800468D8
    if (ctx->r2 == 0) {
        // 0x800468BC: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800468D8;
    }
    // 0x800468BC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800468C0: addu        $v0, $v0, $t4
    gpr jr_addend_800468C8 = ctx->r2;
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x800468C4: lw          $v0, 0x0($v0)
    ctx->r2 = ADD32(ctx->r2, 0X0);
    // 0x800468C8: jr          $v0
    // 0x800468CC: nop

    switch (jr_addend_800468C8 >> 2) {
        case 0: goto L_80046904; break;
        case 1: goto L_800468D8; break;
        case 2: goto L_800468D8; break;
        case 3: goto L_800468D8; break;
        case 4: goto L_800468D8; break;
        case 5: goto L_800468D8; break;
        case 6: goto L_800468D8; break;
        case 7: goto L_800468D8; break;
        case 8: goto L_800468D8; break;
        case 9: goto L_800468D8; break;
        case 10: goto L_800468D8; break;
        case 11: goto L_800468D8; break;
        case 12: goto L_800468D8; break;
        case 13: goto L_80046904; break;
        case 14: goto L_800468D8; break;
        case 15: goto L_800468D8; break;
        case 16: goto L_800468D8; break;
        case 17: goto L_800468D8; break;
        case 18: goto L_800468D8; break;
        case 19: goto L_800468D8; break;
        case 20: goto L_80046904; break;
        case 21: goto L_800468D8; break;
        case 22: goto L_800468D8; break;
        case 23: goto L_800468D8; break;
        case 24: goto L_800468D8; break;
        case 25: goto L_800468D8; break;
        case 26: goto L_800468D8; break;
        case 27: goto L_800468D8; break;
        case 28: goto L_800468D8; break;
        case 29: goto L_800468D8; break;
        case 30: goto L_800468D8; break;
        case 31: goto L_800468D8; break;
        case 32: goto L_800468D8; break;
        case 33: goto L_80046904; break;
        case 34: goto L_800468D8; break;
        case 35: goto L_800468D8; break;
        case 36: goto L_800468D8; break;
        case 37: goto L_800468D8; break;
        case 38: goto L_800468D8; break;
        case 39: goto L_800468D8; break;
        case 40: goto L_80046904; break;
        case 41: goto L_800468D8; break;
        case 42: goto L_80046904; break;
        case 43: goto L_80046904; break;
        case 44: goto L_800468D8; break;
        case 45: goto L_800468D8; break;
        case 46: goto L_80046904; break;
        case 47: goto L_800468D8; break;
        case 48: goto L_800468D8; break;
        case 49: goto L_800468D8; break;
        case 50: goto L_800468D0; break;
        case 51: goto L_80046904; break;
        case 52: goto L_800468D8; break;
        case 53: goto L_800468D8; break;
        case 54: goto L_800468D8; break;
        case 55: goto L_800468D8; break;
        case 56: goto L_800468D8; break;
        case 57: goto L_800468D8; break;
        case 58: goto L_800468D8; break;
        case 59: goto L_800468D8; break;
        case 60: goto L_800468D8; break;
        case 61: goto L_800468D8; break;
        case 62: goto L_800468D8; break;
        case 63: goto L_800468D8; break;
        case 64: goto L_800468D8; break;
        case 65: goto L_80046904; break;
        case 66: goto L_80046904; break;
        case 67: goto L_800468D8; break;
        case 68: goto L_80046904; break;
        case 69: goto L_800468D8; break;
        case 70: goto L_800468D8; break;
        case 71: goto L_800468D8; break;
        case 72: goto L_800468D8; break;
        case 73: goto L_800468D8; break;
        case 74: goto L_80046904; break;
        case 75: goto L_80046904; break;
        default: switch_error(__func__, 0x800468C8, 0x8003A640);
    }
    // 0x800468CC: nop

L_800468D0:
    // 0x800468D0: beq         $t1, $zero, L_80046904
    if (ctx->r9 == 0) {
        // 0x800468D4: nop
    
            goto L_80046904;
    }
    // 0x800468D4: nop

L_800468D8:
    // 0x800468D8: j           L_80046904
    // 0x800468DC: sh          $a2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r6;
        goto L_80046904;
    // 0x800468DC: sh          $a2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r6;
L_800468E0:
    // 0x800468E0: bne         $t0, $v0, L_80046904
    if (ctx->r8 != ctx->r2) {
        // 0x800468E4: nop
    
            goto L_80046904;
    }
    // 0x800468E4: nop

    // 0x800468E8: lbu         $v0, 0x23($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0X23);
    // 0x800468EC: bne         $v0, $zero, L_80046904
    if (ctx->r2 != 0) {
        // 0x800468F0: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_80046904;
    }
    // 0x800468F0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x800468F4: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x800468F8: bne         $v1, $v0, L_80046904
    if (ctx->r3 != ctx->r2) {
        // 0x800468FC: addiu       $v0, $zero, 0x13
        ctx->r2 = ADD32(0, 0X13);
            goto L_80046904;
    }
    // 0x800468FC: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // 0x80046900: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
L_80046904:
    // 0x80046904: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80046908: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8004690C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80046910: nop

    // 0x80046914: bc1f        L_80046924
    if (!c1cs) {
        // 0x80046918: nop
    
            goto L_80046924;
    }
    // 0x80046918: nop

    // 0x8004691C: j           L_80046938
    // 0x80046920: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
        goto L_80046938;
    // 0x80046920: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
L_80046924:
    // 0x80046924: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80046928: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8004692C: nop

    // 0x80046930: bc1tl       L_80046938
    if (c1cs) {
        // 0x80046934: swc1        $f2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
            goto L_80046938;
    }
    goto skip_0;
    // 0x80046934: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    skip_0:
L_80046938:
    // 0x80046938: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8004693C: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80046940: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80046944: nop

    // 0x80046948: bc1f        L_80046958
    if (!c1cs) {
        // 0x8004694C: nop
    
            goto L_80046958;
    }
    // 0x8004694C: nop

    // 0x80046950: j           L_8004696C
    // 0x80046954: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
        goto L_8004696C;
    // 0x80046954: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
L_80046958:
    // 0x80046958: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8004695C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80046960: nop

    // 0x80046964: bc1tl       L_8004696C
    if (c1cs) {
        // 0x80046968: swc1        $f2, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
            goto L_8004696C;
    }
    goto skip_1;
    // 0x80046968: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    skip_1:
L_8004696C:
    // 0x8004696C: lwc1        $f2, 0x18($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80046970: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80046974: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80046978: nop

    // 0x8004697C: bc1f        L_8004698C
    if (!c1cs) {
        // 0x80046980: nop
    
            goto L_8004698C;
    }
    // 0x80046980: nop

    // 0x80046984: j           L_800469A0
    // 0x80046988: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
        goto L_800469A0;
    // 0x80046988: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
L_8004698C:
    // 0x8004698C: lwc1        $f0, 0x50($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80046990: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80046994: nop

    // 0x80046998: bc1tl       L_800469A0
    if (c1cs) {
        // 0x8004699C: swc1        $f2, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
            goto L_800469A0;
    }
    goto skip_2;
    // 0x8004699C: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    skip_2:
L_800469A0:
    // 0x800469A0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800469A4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800469A8: sltu        $v0, $s1, $v0
    ctx->r2 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x800469AC: bne         $v0, $zero, L_80046860
    if (ctx->r2 != 0) {
        // 0x800469B0: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80046860;
    }
    // 0x800469B0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800469B4: j           L_800469C0
    // 0x800469B8: nop

        goto L_800469C0;
    // 0x800469B8: nop

L_800469BC:
    // 0x800469BC: sw          $zero, 0x4($s2)
    MEM_W(0X4, ctx->r18) = 0;
L_800469C0:
    // 0x800469C0: lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X10);
    // 0x800469C4: beq         $v0, $zero, L_80046AB8
    if (ctx->r2 == 0) {
        // 0x800469C8: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80046AB8;
    }
    // 0x800469C8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800469CC: lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X14);
    // 0x800469D0: lw          $v1, 0x10($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X10);
    // 0x800469D4: addu        $a1, $s2, $v0
    ctx->r5 = ADD32(ctx->r18, ctx->r2);
    // 0x800469D8: beq         $v1, $zero, L_80046ABC
    if (ctx->r3 == 0) {
        // 0x800469DC: sw          $a1, 0x14($s2)
        MEM_W(0X14, ctx->r18) = ctx->r5;
            goto L_80046ABC;
    }
    // 0x800469DC: sw          $a1, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r5;
    // 0x800469E0: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
L_800469E4:
    // 0x800469E4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800469E8: addu        $v1, $a1, $v0
    ctx->r3 = ADD32(ctx->r5, ctx->r2);
    // 0x800469EC: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800469F0: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800469F4: beq         $v0, $zero, L_80046A00
    if (ctx->r2 == 0) {
        // 0x800469F8: addu        $v0, $v1, $v0
        ctx->r2 = ADD32(ctx->r3, ctx->r2);
            goto L_80046A00;
    }
    // 0x800469F8: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800469FC: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
L_80046A00:
    // 0x80046A00: lwc1        $f2, 0x10($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80046A04: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80046A08: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80046A0C: nop

    // 0x80046A10: bc1f        L_80046A20
    if (!c1cs) {
        // 0x80046A14: nop
    
            goto L_80046A20;
    }
    // 0x80046A14: nop

    // 0x80046A18: j           L_80046A34
    // 0x80046A1C: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
        goto L_80046A34;
    // 0x80046A1C: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
L_80046A20:
    // 0x80046A20: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80046A24: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80046A28: nop

    // 0x80046A2C: bc1tl       L_80046A34
    if (c1cs) {
        // 0x80046A30: swc1        $f2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
            goto L_80046A34;
    }
    goto skip_3;
    // 0x80046A30: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    skip_3:
L_80046A34:
    // 0x80046A34: lwc1        $f2, 0x14($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80046A38: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80046A3C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80046A40: nop

    // 0x80046A44: bc1f        L_80046A54
    if (!c1cs) {
        // 0x80046A48: nop
    
            goto L_80046A54;
    }
    // 0x80046A48: nop

    // 0x80046A4C: j           L_80046A68
    // 0x80046A50: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
        goto L_80046A68;
    // 0x80046A50: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
L_80046A54:
    // 0x80046A54: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80046A58: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80046A5C: nop

    // 0x80046A60: bc1tl       L_80046A68
    if (c1cs) {
        // 0x80046A64: swc1        $f2, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
            goto L_80046A68;
    }
    goto skip_4;
    // 0x80046A64: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    skip_4:
L_80046A68:
    // 0x80046A68: lwc1        $f2, 0x18($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80046A6C: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80046A70: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80046A74: nop

    // 0x80046A78: bc1f        L_80046A88
    if (!c1cs) {
        // 0x80046A7C: nop
    
            goto L_80046A88;
    }
    // 0x80046A7C: nop

    // 0x80046A80: j           L_80046A9C
    // 0x80046A84: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
        goto L_80046A9C;
    // 0x80046A84: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
L_80046A88:
    // 0x80046A88: lwc1        $f0, 0x50($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80046A8C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80046A90: nop

    // 0x80046A94: bc1tl       L_80046A9C
    if (c1cs) {
        // 0x80046A98: swc1        $f2, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
            goto L_80046A9C;
    }
    goto skip_5;
    // 0x80046A98: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    skip_5:
L_80046A9C:
    // 0x80046A9C: lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X10);
    // 0x80046AA0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80046AA4: sltu        $v0, $s1, $v0
    ctx->r2 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x80046AA8: bne         $v0, $zero, L_800469E4
    if (ctx->r2 != 0) {
        // 0x80046AAC: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800469E4;
    }
    // 0x80046AAC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80046AB0: j           L_80046ABC
    // 0x80046AB4: nop

        goto L_80046ABC;
    // 0x80046AB4: nop

L_80046AB8:
    // 0x80046AB8: sw          $zero, 0x14($s2)
    MEM_W(0X14, ctx->r18) = 0;
L_80046ABC:
    // 0x80046ABC: lw          $v0, 0x18($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X18);
    // 0x80046AC0: beq         $v0, $zero, L_80046B40
    if (ctx->r2 == 0) {
        // 0x80046AC4: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80046B40;
    }
    // 0x80046AC4: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80046AC8: lw          $v0, 0x1C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1C);
    // 0x80046ACC: lw          $v1, 0x18($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X18);
    // 0x80046AD0: addu        $a1, $s2, $v0
    ctx->r5 = ADD32(ctx->r18, ctx->r2);
    // 0x80046AD4: beq         $v1, $zero, L_80046B44
    if (ctx->r3 == 0) {
        // 0x80046AD8: sw          $a1, 0x1C($s2)
        MEM_W(0X1C, ctx->r18) = ctx->r5;
            goto L_80046B44;
    }
    // 0x80046AD8: sw          $a1, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r5;
    // 0x80046ADC: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
L_80046AE0:
    // 0x80046AE0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80046AE4: addu        $v1, $a1, $v0
    ctx->r3 = ADD32(ctx->r5, ctx->r2);
    // 0x80046AE8: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80046AEC: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80046AF0: beq         $v0, $zero, L_80046AFC
    if (ctx->r2 == 0) {
        // 0x80046AF4: addu        $v0, $v1, $v0
        ctx->r2 = ADD32(ctx->r3, ctx->r2);
            goto L_80046AFC;
    }
    // 0x80046AF4: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80046AF8: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
L_80046AFC:
    // 0x80046AFC: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
    // 0x80046B00: beq         $v0, $zero, L_80046B0C
    if (ctx->r2 == 0) {
        // 0x80046B04: addu        $v0, $v1, $v0
        ctx->r2 = ADD32(ctx->r3, ctx->r2);
            goto L_80046B0C;
    }
    // 0x80046B04: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80046B08: sw          $v0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r2;
L_80046B0C:
    // 0x80046B0C: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
    // 0x80046B10: beq         $v0, $zero, L_80046B24
    if (ctx->r2 == 0) {
        // 0x80046B14: nop
    
            goto L_80046B24;
    }
    // 0x80046B14: nop

    // 0x80046B18: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x80046B1C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80046B20: sw          $v0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r2;
L_80046B24:
    // 0x80046B24: lw          $v0, 0x18($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X18);
    // 0x80046B28: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80046B2C: sltu        $v0, $s1, $v0
    ctx->r2 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x80046B30: bne         $v0, $zero, L_80046AE0
    if (ctx->r2 != 0) {
        // 0x80046B34: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80046AE0;
    }
    // 0x80046B34: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80046B38: j           L_80046B44
    // 0x80046B3C: nop

        goto L_80046B44;
    // 0x80046B3C: nop

L_80046B40:
    // 0x80046B40: sw          $zero, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = 0;
L_80046B44:
    // 0x80046B44: lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X30);
    // 0x80046B48: beq         $v0, $zero, L_80046C20
    if (ctx->r2 == 0) {
        // 0x80046B4C: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80046C20;
    }
    // 0x80046B4C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80046B50: lw          $v0, 0x34($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X34);
    // 0x80046B54: lw          $v1, 0x30($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X30);
    // 0x80046B58: addu        $s3, $s2, $v0
    ctx->r19 = ADD32(ctx->r18, ctx->r2);
    // 0x80046B5C: beq         $v1, $zero, L_80046C24
    if (ctx->r3 == 0) {
        // 0x80046B60: sw          $s3, 0x34($s2)
        MEM_W(0X34, ctx->r18) = ctx->r19;
            goto L_80046C24;
    }
    // 0x80046B60: sw          $s3, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r19;
    // 0x80046B64: ori         $s6, $zero, 0xFFFF
    ctx->r22 = 0 | 0XFFFF;
    // 0x80046B68: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x80046B6C: addiu       $s4, $zero, 0x5
    ctx->r20 = ADD32(0, 0X5);
    // 0x80046B70: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
L_80046B74:
    // 0x80046B74: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80046B78: addu        $v1, $s3, $v0
    ctx->r3 = ADD32(ctx->r19, ctx->r2);
    // 0x80046B7C: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // 0x80046B80: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80046B84: beq         $v0, $zero, L_80046B94
    if (ctx->r2 == 0) {
        // 0x80046B88: addu        $v0, $v1, $v0
        ctx->r2 = ADD32(ctx->r3, ctx->r2);
            goto L_80046B94;
    }
    // 0x80046B88: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80046B8C: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x80046B90: sh          $s6, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r22;
L_80046B94:
    // 0x80046B94: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80046B98: beq         $v0, $s5, L_80046BB0
    if (ctx->r2 == ctx->r21) {
        // 0x80046B9C: nop
    
            goto L_80046BB0;
    }
    // 0x80046B9C: nop

    // 0x80046BA0: beq         $v0, $s4, L_80046BDC
    if (ctx->r2 == ctx->r20) {
        // 0x80046BA4: nop
    
            goto L_80046BDC;
    }
    // 0x80046BA4: nop

    // 0x80046BA8: j           L_80046C04
    // 0x80046BAC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
        goto L_80046C04;
    // 0x80046BAC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80046BB0:
    // 0x80046BB0: lwc1        $f2, 0x18($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80046BB4: lwc1        $f0, 0x30($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X30);
    // 0x80046BB8: lwc1        $f12, 0x10($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80046BBC: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80046BC0: lwc1        $f14, 0x28($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X28);
    // 0x80046BC4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80046BC8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80046BCC: jal         0x80043C30
    // 0x80046BD0: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    markHighLodCellsInGrid(rdram, ctx);
        goto after_2;
    // 0x80046BD0: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    after_2:
    // 0x80046BD4: j           L_80046C04
    // 0x80046BD8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
        goto L_80046C04;
    // 0x80046BD8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80046BDC:
    // 0x80046BDC: lwc1        $f2, 0x18($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80046BE0: lwc1        $f0, 0x30($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X30);
    // 0x80046BE4: lwc1        $f12, 0x10($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80046BE8: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80046BEC: lwc1        $f14, 0x28($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X28);
    // 0x80046BF0: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80046BF4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80046BF8: jal         0x80043AEC
    // 0x80046BFC: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    markLowLodCellsInGrid(rdram, ctx);
        goto after_3;
    // 0x80046BFC: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    after_3:
    // 0x80046C00: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80046C04:
    // 0x80046C04: lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X30);
    // 0x80046C08: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80046C0C: sltu        $v0, $s1, $v0
    ctx->r2 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x80046C10: beq         $v0, $zero, L_80046C24
    if (ctx->r2 == 0) {
        // 0x80046C14: nop
    
            goto L_80046C24;
    }
    // 0x80046C14: nop

    // 0x80046C18: j           L_80046B74
    // 0x80046C1C: nop

        goto L_80046B74;
    // 0x80046C1C: nop

L_80046C20:
    // 0x80046C20: sw          $zero, 0x34($s2)
    MEM_W(0X34, ctx->r18) = 0;
L_80046C24:
    // 0x80046C24: lw          $v0, 0x38($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X38);
    // 0x80046C28: beq         $v0, $zero, L_80046C88
    if (ctx->r2 == 0) {
        // 0x80046C2C: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80046C88;
    }
    // 0x80046C2C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80046C30: lw          $v0, 0x3C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X3C);
    // 0x80046C34: lw          $v1, 0x38($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X38);
    // 0x80046C38: addu        $a1, $s2, $v0
    ctx->r5 = ADD32(ctx->r18, ctx->r2);
    // 0x80046C3C: beq         $v1, $zero, L_80046C8C
    if (ctx->r3 == 0) {
        // 0x80046C40: sw          $a1, 0x3C($s2)
        MEM_W(0X3C, ctx->r18) = ctx->r5;
            goto L_80046C8C;
    }
    // 0x80046C40: sw          $a1, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->r5;
    // 0x80046C44: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // 0x80046C48: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
L_80046C4C:
    // 0x80046C4C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80046C50: addu        $v1, $a1, $v0
    ctx->r3 = ADD32(ctx->r5, ctx->r2);
    // 0x80046C54: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80046C58: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80046C5C: beq         $v0, $zero, L_80046C6C
    if (ctx->r2 == 0) {
        // 0x80046C60: addu        $v0, $v1, $v0
        ctx->r2 = ADD32(ctx->r3, ctx->r2);
            goto L_80046C6C;
    }
    // 0x80046C60: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80046C64: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x80046C68: sh          $a2, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r6;
L_80046C6C:
    // 0x80046C6C: lw          $v0, 0x38($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X38);
    // 0x80046C70: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80046C74: sltu        $v0, $s1, $v0
    ctx->r2 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x80046C78: bne         $v0, $zero, L_80046C4C
    if (ctx->r2 != 0) {
        // 0x80046C7C: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80046C4C;
    }
    // 0x80046C7C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80046C80: j           L_80046C8C
    // 0x80046C84: nop

        goto L_80046C8C;
    // 0x80046C84: nop

L_80046C88:
    // 0x80046C88: sw          $zero, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = 0;
L_80046C8C:
    // 0x80046C8C: lw          $v0, 0x44($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X44);
    // 0x80046C90: beq         $v0, $zero, L_80046D8C
    if (ctx->r2 == 0) {
        // 0x80046C94: addu        $v0, $v0, $s2
        ctx->r2 = ADD32(ctx->r2, ctx->r18);
            goto L_80046D8C;
    }
    // 0x80046C94: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80046C98: sw          $v0, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->r2;
    // 0x80046C9C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80046CA0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80046CA4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80046CA8: addiu       $a3, $v0, -0x5890
    ctx->r7 = ADD32(ctx->r2, -0X5890);
L_80046CAC:
    // 0x80046CAC: lw          $a0, 0x44($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X44);
    // 0x80046CB0: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x80046CB4: addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // 0x80046CB8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80046CBC: beql        $v0, $zero, L_80046D80
    if (ctx->r2 == 0) {
        // 0x80046CC0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80046D80;
    }
    goto skip_6;
    // 0x80046CC0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_6:
    // 0x80046CC4: addu        $a1, $v0, $a0
    ctx->r5 = ADD32(ctx->r2, ctx->r4);
    // 0x80046CC8: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x80046CCC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80046CD0: beql        $v0, $t0, L_80046D80
    if (ctx->r2 == ctx->r8) {
        // 0x80046CD4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80046D80;
    }
    goto skip_7;
    // 0x80046CD4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_7:
    // 0x80046CD8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80046CDC: addiu       $a0, $a1, 0x4
    ctx->r4 = ADD32(ctx->r5, 0X4);
L_80046CE0:
    // 0x80046CE0: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80046CE4: sltiu       $v0, $v1, 0x8
    ctx->r2 = ctx->r3 < 0X8 ? 1 : 0;
    // 0x80046CE8: beq         $v0, $zero, L_80046D64
    if (ctx->r2 == 0) {
        // 0x80046CEC: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80046D64;
    }
    // 0x80046CEC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80046CF0: addu        $v0, $v0, $a3
    gpr jr_addend_80046CF8 = ctx->r2;
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80046CF4: lw          $v0, 0x0($v0)
    ctx->r2 = ADD32(ctx->r2, 0X0);
    // 0x80046CF8: jr          $v0
    // 0x80046CFC: nop

    switch (jr_addend_80046CF8 >> 2) {
        case 0: goto L_80046D00; break;
        case 1: goto L_80046D64; break;
        case 2: goto L_80046D10; break;
        case 3: goto L_80046D20; break;
        case 4: goto L_80046D64; break;
        case 5: goto L_80046D64; break;
        case 6: goto L_80046D30; break;
        case 7: goto L_80046D40; break;
        default: switch_error(__func__, 0x80046CF8, 0x8003A770);
    }
    // 0x80046CFC: nop

L_80046D00:
    // 0x80046D00: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80046D04: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x80046D08: j           L_80046D4C
    // 0x80046D0C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
        goto L_80046D4C;
    // 0x80046D0C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
L_80046D10:
    // 0x80046D10: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80046D14: lw          $v1, 0x14($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X14);
    // 0x80046D18: j           L_80046D4C
    // 0x80046D1C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
        goto L_80046D4C;
    // 0x80046D1C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
L_80046D20:
    // 0x80046D20: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80046D24: lw          $v1, 0x1C($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1C);
    // 0x80046D28: j           L_80046D4C
    // 0x80046D2C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
        goto L_80046D4C;
    // 0x80046D2C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
L_80046D30:
    // 0x80046D30: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80046D34: lw          $v1, 0x34($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X34);
    // 0x80046D38: j           L_80046D4C
    // 0x80046D3C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
        goto L_80046D4C;
    // 0x80046D3C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
L_80046D40:
    // 0x80046D40: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80046D44: lw          $v1, 0x3C($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X3C);
    // 0x80046D48: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
L_80046D4C:
    // 0x80046D4C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80046D50: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80046D54: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80046D58: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x80046D5C: j           L_80046D6C
    // 0x80046D60: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
        goto L_80046D6C;
    // 0x80046D60: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_80046D64:
    // 0x80046D64: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80046D68: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_80046D6C:
    // 0x80046D6C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80046D70: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80046D74: bne         $v0, $a2, L_80046CE0
    if (ctx->r2 != ctx->r6) {
        // 0x80046D78: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_80046CE0;
    }
    // 0x80046D78: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80046D7C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80046D80:
    // 0x80046D80: slti        $v0, $s1, 0x100
    ctx->r2 = SIGNED(ctx->r17) < 0X100 ? 1 : 0;
    // 0x80046D84: bne         $v0, $zero, L_80046CAC
    if (ctx->r2 != 0) {
        // 0x80046D88: nop
    
            goto L_80046CAC;
    }
    // 0x80046D88: nop

L_80046D8C:
    // 0x80046D8C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80046D90: lbu         $v1, 0xB3A($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB3A);
    // 0x80046D94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80046D98: bne         $v1, $v0, L_80046DA8
    if (ctx->r3 != ctx->r2) {
        // 0x80046D9C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80046DA8;
    }
    // 0x80046D9C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80046DA0: j           L_80047334
    // 0x80046DA4: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
        goto L_80047334;
    // 0x80046DA4: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
L_80046DA8:
    // 0x80046DA8: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80046DAC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80046DB0: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80046DB4: nop

    // 0x80046DB8: bc1f        L_80046DDC
    if (!c1cs) {
        // 0x80046DBC: sw          $s2, 0x75D8($v0)
        MEM_W(0X75D8, ctx->r2) = ctx->r18;
            goto L_80046DDC;
    }
    // 0x80046DBC: sw          $s2, 0x75D8($v0)
    MEM_W(0X75D8, ctx->r2) = ctx->r18;
    // 0x80046DC0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80046DC4: lwc1        $f20, -0x5870($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X5870);
    // 0x80046DC8: jal         0x8001E20C
    // 0x80046DCC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    floatModulo(rdram, ctx);
        goto after_4;
    // 0x80046DCC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_4:
    // 0x80046DD0: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80046DD4: j           L_80046DF0
    // 0x80046DD8: sub.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f20.fl;
        goto L_80046DF0;
    // 0x80046DD8: sub.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f20.fl;
L_80046DDC:
    // 0x80046DDC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80046DE0: lwc1        $f14, -0x586C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X586C);
    // 0x80046DE4: jal         0x8001E20C
    // 0x80046DE8: nop

    floatModulo(rdram, ctx);
        goto after_5;
    // 0x80046DE8: nop

    after_5:
    // 0x80046DEC: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
L_80046DF0:
    // 0x80046DF0: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80046DF4: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80046DF8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80046DFC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80046E00: nop

    // 0x80046E04: bc1f        L_80046E28
    if (!c1cs) {
        // 0x80046E08: swc1        $f2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
            goto L_80046E28;
    }
    // 0x80046E08: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x80046E0C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80046E10: lwc1        $f20, -0x5868($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X5868);
    // 0x80046E14: jal         0x8001E20C
    // 0x80046E18: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    floatModulo(rdram, ctx);
        goto after_6;
    // 0x80046E18: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_6:
    // 0x80046E1C: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80046E20: j           L_80046E3C
    // 0x80046E24: sub.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f20.fl;
        goto L_80046E3C;
    // 0x80046E24: sub.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f20.fl;
L_80046E28:
    // 0x80046E28: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80046E2C: lwc1        $f14, -0x5864($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X5864);
    // 0x80046E30: jal         0x8001E20C
    // 0x80046E34: nop

    floatModulo(rdram, ctx);
        goto after_7;
    // 0x80046E34: nop

    after_7:
    // 0x80046E38: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
L_80046E3C:
    // 0x80046E3C: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80046E40: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80046E44: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80046E48: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80046E4C: nop

    // 0x80046E50: bc1f        L_80046E74
    if (!c1cs) {
        // 0x80046E54: swc1        $f2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
            goto L_80046E74;
    }
    // 0x80046E54: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x80046E58: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80046E5C: lwc1        $f14, -0x5860($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X5860);
    // 0x80046E60: jal         0x8001E20C
    // 0x80046E64: nop

    floatModulo(rdram, ctx);
        goto after_8;
    // 0x80046E64: nop

    after_8:
    // 0x80046E68: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80046E6C: j           L_80046E90
    // 0x80046E70: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
        goto L_80046E90;
    // 0x80046E70: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
L_80046E74:
    // 0x80046E74: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80046E78: lwc1        $f20, -0x585C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X585C);
    // 0x80046E7C: jal         0x8001E20C
    // 0x80046E80: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    floatModulo(rdram, ctx);
        goto after_9;
    // 0x80046E80: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_9:
    // 0x80046E84: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80046E88: add.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f20.fl;
    // 0x80046E8C: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
L_80046E90:
    // 0x80046E90: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80046E94: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80046E98: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80046E9C: nop

    // 0x80046EA0: bc1f        L_80046EC4
    if (!c1cs) {
        // 0x80046EA4: swc1        $f2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
            goto L_80046EC4;
    }
    // 0x80046EA4: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x80046EA8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80046EAC: lwc1        $f14, -0x5858($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X5858);
    // 0x80046EB0: jal         0x8001E20C
    // 0x80046EB4: nop

    floatModulo(rdram, ctx);
        goto after_10;
    // 0x80046EB4: nop

    after_10:
    // 0x80046EB8: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80046EBC: j           L_80046EE0
    // 0x80046EC0: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
        goto L_80046EE0;
    // 0x80046EC0: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
L_80046EC4:
    // 0x80046EC4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80046EC8: lwc1        $f20, -0x5854($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X5854);
    // 0x80046ECC: jal         0x8001E20C
    // 0x80046ED0: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    floatModulo(rdram, ctx);
        goto after_11;
    // 0x80046ED0: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_11:
    // 0x80046ED4: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80046ED8: add.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f20.fl;
    // 0x80046EDC: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
L_80046EE0:
    // 0x80046EE0: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80046EE4: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80046EE8: sub.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80046EEC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80046EF0: lwc1        $f10, -0x5850($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5850);
    // 0x80046EF4: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80046EF8: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80046EFC: addiu       $v1, $s3, 0x75D8
    ctx->r3 = ADD32(ctx->r19, 0X75D8);
    // 0x80046F00: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    // 0x80046F04: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80046F08: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80046F0C: bgtz        $v0, L_80046F1C
    if (SIGNED(ctx->r2) > 0) {
        // 0x80046F10: sw          $v0, 0x14($v1)
        MEM_W(0X14, ctx->r3) = ctx->r2;
            goto L_80046F1C;
    }
    // 0x80046F10: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x80046F14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80046F18: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
L_80046F1C:
    // 0x80046F1C: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80046F20: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80046F24: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80046F28: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80046F2C: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80046F30: bgtz        $v0, L_80046F40
    if (SIGNED(ctx->r2) > 0) {
        // 0x80046F34: sw          $v0, 0x18($v1)
        MEM_W(0X18, ctx->r3) = ctx->r2;
            goto L_80046F40;
    }
    // 0x80046F34: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x80046F38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80046F3C: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
L_80046F40:
    // 0x80046F40: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80046F44: lbu         $v0, 0xB39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XB39);
    // 0x80046F48: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
    // 0x80046F4C: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x80046F50: swc1        $f8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f8.u32l;
    // 0x80046F54: bne         $v0, $zero, L_80046F6C
    if (ctx->r2 != 0) {
        // 0x80046F58: swc1        $f2, 0x10($v1)
        MEM_W(0X10, ctx->r3) = ctx->f2.u32l;
            goto L_80046F6C;
    }
    // 0x80046F58: swc1        $f2, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f2.u32l;
    // 0x80046F5C: lw          $a0, 0x3C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X3C);
    // 0x80046F60: lw          $a1, 0x38($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X38);
    // 0x80046F64: jal         0x800AA870
    // 0x80046F68: nop

    parseDatEventTriggers(rdram, ctx);
        goto after_12;
    // 0x80046F68: nop

    after_12:
L_80046F6C:
    // 0x80046F6C: jal         0x80064940
    // 0x80046F70: nop

    load_dat_file_assets(rdram, ctx);
        goto after_13;
    // 0x80046F70: nop

    after_13:
    // 0x80046F74: lbu         $v0, 0xB39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XB39);
    // 0x80046F78: beq         $v0, $zero, L_80047014
    if (ctx->r2 == 0) {
        // 0x80046F7C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80047014;
    }
    // 0x80046F7C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80046F80: lw          $v0, 0x75D8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X75D8);
    // 0x80046F84: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80046F88: beq         $v0, $zero, L_80047010
    if (ctx->r2 == 0) {
        // 0x80046F8C: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80047010;
    }
    // 0x80046F8C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80046F90: ori         $s7, $zero, 0xFFFF
    ctx->r23 = 0 | 0XFFFF;
    // 0x80046F94: addiu       $s6, $zero, 0x14
    ctx->r22 = ADD32(0, 0X14);
    // 0x80046F98: addiu       $s5, $zero, 0x32
    ctx->r21 = ADD32(0, 0X32);
    // 0x80046F9C: addiu       $s4, $zero, 0x4A
    ctx->r20 = ADD32(0, 0X4A);
L_80046FA0:
    // 0x80046FA0: lw          $v0, 0x75D8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X75D8);
    // 0x80046FA4: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80046FA8: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x80046FAC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80046FB0: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x80046FB4: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x80046FB8: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x80046FBC: beq         $v0, $s7, L_80046FF8
    if (ctx->r2 == ctx->r23) {
        // 0x80046FC0: nop
    
            goto L_80046FF8;
    }
    // 0x80046FC0: nop

    // 0x80046FC4: beq         $v0, $s6, L_80046FF8
    if (ctx->r2 == ctx->r22) {
        // 0x80046FC8: nop
    
            goto L_80046FF8;
    }
    // 0x80046FC8: nop

    // 0x80046FCC: beq         $v0, $s5, L_80046FF8
    if (ctx->r2 == ctx->r21) {
        // 0x80046FD0: nop
    
            goto L_80046FF8;
    }
    // 0x80046FD0: nop

    // 0x80046FD4: beq         $v0, $s4, L_80046FF8
    if (ctx->r2 == ctx->r20) {
        // 0x80046FD8: nop
    
            goto L_80046FF8;
    }
    // 0x80046FD8: nop

    // 0x80046FDC: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x80046FE0: bnel        $v0, $zero, L_80046FF8
    if (ctx->r2 != 0) {
        // 0x80046FE4: sh          $zero, 0x0($s0)
        MEM_H(0X0, ctx->r16) = 0;
            goto L_80046FF8;
    }
    goto skip_8;
    // 0x80046FE4: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    skip_8:
    // 0x80046FE8: jal         0x800AE98C
    // 0x80046FEC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    getAssetNameForNpcType(rdram, ctx);
        goto after_14;
    // 0x80046FEC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    after_14:
    // 0x80046FF0: sw          $v0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r2;
    // 0x80046FF4: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_80046FF8:
    // 0x80046FF8: lw          $v0, 0x75D8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X75D8);
    // 0x80046FFC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80047000: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80047004: sltu        $v0, $s1, $v0
    ctx->r2 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x80047008: bne         $v0, $zero, L_80046FA0
    if (ctx->r2 != 0) {
        // 0x8004700C: nop
    
            goto L_80046FA0;
    }
    // 0x8004700C: nop

L_80047010:
    // 0x80047010: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_80047014:
    // 0x80047014: addiu       $s0, $v0, 0x75D8
    ctx->r16 = ADD32(ctx->r2, 0X75D8);
    // 0x80047018: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
    // 0x8004701C: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x80047020: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80047024: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80047028: mflo        $t6
    ctx->r14 = lo;
    // 0x8004702C: jal         0x80001ACC
    // 0x80047030: sll         $a0, $t6, 1
    ctx->r4 = S32(ctx->r14 << 1);
    rs_malloc(rdram, ctx);
        goto after_15;
    // 0x80047030: sll         $a0, $t6, 1
    ctx->r4 = S32(ctx->r14 << 1);
    after_15:
    // 0x80047034: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x80047038: lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X18);
    // 0x8004703C: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80047040: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80047044: mflo        $t6
    ctx->r14 = lo;
    // 0x80047048: blez        $t6, L_8004708C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8004704C: sw          $v0, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = ctx->r2;
            goto L_8004708C;
    }
    // 0x8004704C: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x80047050: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80047054: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
L_80047058:
    // 0x80047058: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x8004705C: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
    // 0x80047060: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80047064: sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
    // 0x80047068: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x8004706C: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x80047070: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80047074: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80047078: mflo        $t6
    ctx->r14 = lo;
    // 0x8004707C: slt         $v0, $s1, $t6
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80047080: bne         $v0, $zero, L_80047058
    if (ctx->r2 != 0) {
        // 0x80047084: nop
    
            goto L_80047058;
    }
    // 0x80047084: nop

    // 0x80047088: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_8004708C:
    // 0x8004708C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80047090: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80047094: beq         $v0, $zero, L_80047134
    if (ctx->r2 == 0) {
        // 0x80047098: sw          $zero, 0x75D4($v1)
        MEM_W(0X75D4, ctx->r3) = 0;
            goto L_80047134;
    }
    // 0x80047098: sw          $zero, 0x75D4($v1)
    MEM_W(0X75D4, ctx->r3) = 0;
    // 0x8004709C: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800470A0: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800470A4: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800470A8: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x800470AC: addu        $s3, $v1, $zero
    ctx->r19 = ADD32(ctx->r3, 0);
    // 0x800470B0: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
L_800470B4:
    // 0x800470B4: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x800470B8: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800470BC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800470C0: lw          $v0, 0x4C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4C);
    // 0x800470C4: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800470C8: bnel        $v0, $zero, L_80047120
    if (ctx->r2 != 0) {
        // 0x800470CC: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80047120;
    }
    goto skip_9;
    // 0x800470CC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_9:
    // 0x800470D0: lbu         $v0, 0xB39($s7)
    ctx->r2 = MEM_BU(ctx->r23, 0XB39);
    // 0x800470D4: bne         $v0, $zero, L_800470E8
    if (ctx->r2 != 0) {
        // 0x800470D8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800470E8;
    }
    // 0x800470D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800470DC: lw          $a1, 0x7CE4($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X7CE4);
    // 0x800470E0: jal         0x80065790
    // 0x800470E4: nop

    parseDatSpawnPositions(rdram, ctx);
        goto after_16;
    // 0x800470E4: nop

    after_16:
L_800470E8:
    // 0x800470E8: bne         $v0, $s5, L_8004710C
    if (ctx->r2 != ctx->r21) {
        // 0x800470EC: nop
    
            goto L_8004710C;
    }
    // 0x800470EC: nop

    // 0x800470F0: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x800470F4: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800470F8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800470FC: jal         0x80046620
    // 0x80047100: addiu       $a1, $a0, 0x10
    ctx->r5 = ADD32(ctx->r4, 0X10);
    parseDatItemCommon(rdram, ctx);
        goto after_17;
    // 0x80047100: addiu       $a1, $a0, 0x10
    ctx->r5 = ADD32(ctx->r4, 0X10);
    after_17:
    // 0x80047104: j           L_80047120
    // 0x80047108: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
        goto L_80047120;
    // 0x80047108: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8004710C:
    // 0x8004710C: bne         $v0, $s4, L_80047120
    if (ctx->r2 != ctx->r20) {
        // 0x80047110: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80047120;
    }
    // 0x80047110: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80047114: lw          $v0, 0x75D4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X75D4);
    // 0x80047118: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004711C: sw          $v0, 0x75D4($s3)
    MEM_W(0X75D4, ctx->r19) = ctx->r2;
L_80047120:
    // 0x80047120: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80047124: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80047128: sltu        $v0, $s1, $v0
    ctx->r2 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x8004712C: bne         $v0, $zero, L_800470B4
    if (ctx->r2 != 0) {
        // 0x80047130: nop
    
            goto L_800470B4;
    }
    // 0x80047130: nop

L_80047134:
    // 0x80047134: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80047138: lw          $a0, 0x75D4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X75D4);
    // 0x8004713C: beq         $a0, $zero, L_800471DC
    if (ctx->r4 == 0) {
        // 0x80047140: sll         $a0, $a0, 2
        ctx->r4 = S32(ctx->r4 << 2);
            goto L_800471DC;
    }
    // 0x80047140: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80047144: jal         0x80001ACC
    // 0x80047148: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_18;
    // 0x80047148: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_18:
    // 0x8004714C: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80047150: addu        $s1, $s3, $zero
    ctx->r17 = ADD32(ctx->r19, 0);
    // 0x80047154: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80047158: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8004715C: beq         $v1, $zero, L_800471E4
    if (ctx->r3 == 0) {
        // 0x80047160: sw          $v0, 0x75D0($s0)
        MEM_W(0X75D0, ctx->r16) = ctx->r2;
            goto L_800471E4;
    }
    // 0x80047160: sw          $v0, 0x75D0($s0)
    MEM_W(0X75D0, ctx->r16) = ctx->r2;
    // 0x80047164: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x80047168: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x8004716C: addu        $s4, $s0, $zero
    ctx->r20 = ADD32(ctx->r16, 0);
L_80047170:
    // 0x80047170: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x80047174: sll         $s0, $s1, 2
    ctx->r16 = S32(ctx->r17 << 2);
    // 0x80047178: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x8004717C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80047180: lw          $v0, 0x4C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4C);
    // 0x80047184: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x80047188: bne         $v0, $zero, L_800471C0
    if (ctx->r2 != 0) {
        // 0x8004718C: nop
    
            goto L_800471C0;
    }
    // 0x8004718C: nop

    // 0x80047190: lw          $a1, 0x7CE4($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X7CE4);
    // 0x80047194: jal         0x80065790
    // 0x80047198: nop

    parseDatSpawnPositions(rdram, ctx);
        goto after_19;
    // 0x80047198: nop

    after_19:
    // 0x8004719C: bne         $v0, $s5, L_800471C0
    if (ctx->r2 != ctx->r21) {
        // 0x800471A0: sll         $a0, $s3, 2
        ctx->r4 = S32(ctx->r19 << 2);
            goto L_800471C0;
    }
    // 0x800471A0: sll         $a0, $s3, 2
    ctx->r4 = S32(ctx->r19 << 2);
    // 0x800471A4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800471A8: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x800471AC: lw          $v1, 0x75D0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X75D0);
    // 0x800471B0: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800471B4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800471B8: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x800471BC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_800471C0:
    // 0x800471C0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800471C4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800471C8: sltu        $v0, $s1, $v0
    ctx->r2 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x800471CC: bne         $v0, $zero, L_80047170
    if (ctx->r2 != 0) {
        // 0x800471D0: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80047170;
    }
    // 0x800471D0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800471D4: j           L_800471E8
    // 0x800471D8: nop

        goto L_800471E8;
    // 0x800471D8: nop

L_800471DC:
    // 0x800471DC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800471E0: sw          $zero, 0x75D0($v0)
    MEM_W(0X75D0, ctx->r2) = 0;
L_800471E4:
    // 0x800471E4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800471E8:
    // 0x800471E8: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x800471EC: bne         $v0, $zero, L_80047288
    if (ctx->r2 != 0) {
        // 0x800471F0: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_80047288;
    }
    // 0x800471F0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800471F4: lw          $v0, 0x38($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X38);
    // 0x800471F8: beq         $v0, $zero, L_8004723C
    if (ctx->r2 == 0) {
        // 0x800471FC: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_8004723C;
    }
    // 0x800471FC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_80047200:
    // 0x80047200: lw          $v0, 0x3C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X3C);
    // 0x80047204: sll         $v1, $s1, 2
    ctx->r3 = S32(ctx->r17 << 2);
    // 0x80047208: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004720C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80047210: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x80047214: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x80047218: bne         $v0, $zero, L_80047228
    if (ctx->r2 != 0) {
        // 0x8004721C: nop
    
            goto L_80047228;
    }
    // 0x8004721C: nop

    // 0x80047220: jal         0x80046620
    // 0x80047224: addiu       $a1, $a0, 0x10
    ctx->r5 = ADD32(ctx->r4, 0X10);
    parseDatItemCommon(rdram, ctx);
        goto after_20;
    // 0x80047224: addiu       $a1, $a0, 0x10
    ctx->r5 = ADD32(ctx->r4, 0X10);
    after_20:
L_80047228:
    // 0x80047228: lw          $v0, 0x38($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X38);
    // 0x8004722C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80047230: sltu        $v0, $s1, $v0
    ctx->r2 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x80047234: bne         $v0, $zero, L_80047200
    if (ctx->r2 != 0) {
        // 0x80047238: nop
    
            goto L_80047200;
    }
    // 0x80047238: nop

L_8004723C:
    // 0x8004723C: lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X30);
    // 0x80047240: beq         $v0, $zero, L_80047284
    if (ctx->r2 == 0) {
        // 0x80047244: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80047284;
    }
    // 0x80047244: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_80047248:
    // 0x80047248: lw          $v0, 0x34($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X34);
    // 0x8004724C: sll         $v1, $s1, 2
    ctx->r3 = S32(ctx->r17 << 2);
    // 0x80047250: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80047254: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80047258: lw          $v0, 0x34($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X34);
    // 0x8004725C: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80047260: beq         $v0, $zero, L_80047270
    if (ctx->r2 == 0) {
        // 0x80047264: nop
    
            goto L_80047270;
    }
    // 0x80047264: nop

    // 0x80047268: jal         0x800653B4
    // 0x8004726C: nop

    setupNpcUpdateFunctions(rdram, ctx);
        goto after_21;
    // 0x8004726C: nop

    after_21:
L_80047270:
    // 0x80047270: lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X30);
    // 0x80047274: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80047278: sltu        $v0, $s1, $v0
    ctx->r2 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x8004727C: bne         $v0, $zero, L_80047248
    if (ctx->r2 != 0) {
        // 0x80047280: nop
    
            goto L_80047248;
    }
    // 0x80047280: nop

L_80047284:
    // 0x80047284: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_80047288:
    // 0x80047288: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8004728C: addiu       $a1, $a1, -0x59E0
    ctx->r5 = ADD32(ctx->r5, -0X59E0);
    // 0x80047290: jal         0x80033CC4
    // 0x80047294: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    sprintf_recomp(rdram, ctx);
        goto after_22;
    // 0x80047294: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    after_22:
    // 0x80047298: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8004729C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800472A0: addiu       $s0, $v0, 0x6FB0
    ctx->r16 = ADD32(ctx->r2, 0X6FB0);
    // 0x800472A4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800472A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800472AC: jal         0x8005645C
    // 0x800472B0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    load_hmt_and_hob(rdram, ctx);
        goto after_23;
    // 0x800472B0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_23:
    // 0x800472B4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800472B8: lbu         $v0, 0xB63($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB63);
    // 0x800472BC: beq         $v0, $zero, L_800472E8
    if (ctx->r2 == 0) {
        // 0x800472C0: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_800472E8;
    }
    // 0x800472C0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800472C4: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800472C8: addiu       $a1, $a1, -0x59D8
    ctx->r5 = ADD32(ctx->r5, -0X59D8);
    // 0x800472CC: jal         0x80033CC4
    // 0x800472D0: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    sprintf_recomp(rdram, ctx);
        goto after_24;
    // 0x800472D0: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    after_24:
    // 0x800472D4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800472D8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800472DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800472E0: jal         0x8005645C
    // 0x800472E4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    load_hmt_and_hob(rdram, ctx);
        goto after_25;
    // 0x800472E4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_25:
L_800472E8:
    // 0x800472E8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800472EC: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x800472F0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x800472F4: bne         $v1, $v0, L_80047334
    if (ctx->r3 != ctx->r2) {
        // 0x800472F8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80047334;
    }
    // 0x800472F8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800472FC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80047300: jal         0x80056EB0
    // 0x80047304: addiu       $a0, $a0, -0x59CC
    ctx->r4 = ADD32(ctx->r4, -0X59CC);
    walkMeshdef0List(rdram, ctx);
        goto after_26;
    // 0x80047304: addiu       $a0, $a0, -0x59CC
    ctx->r4 = ADD32(ctx->r4, -0X59CC);
    after_26:
    // 0x80047308: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8004730C: beq         $a0, $zero, L_80047334
    if (ctx->r4 == 0) {
        // 0x80047310: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80047334;
    }
    // 0x80047310: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80047314: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80047318: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004731C: lwc1        $f2, -0x584C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X584C);
    // 0x80047320: lwc1        $f0, 0x44($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80047324: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80047328: jal         0x8005779C
    // 0x8004732C: swc1        $f0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f0.u32l;
    releaseMeshAsset(rdram, ctx);
        goto after_27;
    // 0x8004732C: swc1        $f0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f0.u32l;
    after_27:
    // 0x80047330: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80047334:
    // 0x80047334: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x80047338: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x8004733C: lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X74);
    // 0x80047340: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x80047344: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x80047348: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x8004734C: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x80047350: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x80047354: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x80047358: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x8004735C: ldc1        $f20, 0x80($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X80);
    // 0x80047360: jr          $ra
    // 0x80047364: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80047364: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void updateActiveGridCellState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047368: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8004736C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80047370: addiu       $v0, $v0, 0x75D8
    ctx->r2 = ADD32(ctx->r2, 0X75D8);
    // 0x80047374: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80047378: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8004737C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80047380: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80047384: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80047388: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8004738C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80047390: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80047394: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80047398: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8004739C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800473A0: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800473A4: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800473A8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800473AC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800473B0: lwc1        $f6, -0x5848($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5848);
    // 0x800473B4: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800473B8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800473BC: lwc1        $f8, -0x5844($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5844);
    // 0x800473C0: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800473C4: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800473C8: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800473CC: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800473D0: trunc.w.s   $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800473D4: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x800473D8: lw          $a2, 0x10($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X10);
    // 0x800473DC: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800473E0: bgez        $a2, L_800473F0
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800473E4: nop
    
            goto L_800473F0;
    }
    // 0x800473E4: nop

    // 0x800473E8: j           L_80047408
    // 0x800473EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
        goto L_80047408;
    // 0x800473EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_800473F0:
    // 0x800473F0: lw          $v1, 0x14($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14);
    // 0x800473F4: slt         $v0, $a2, $v1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800473F8: bnel        $v0, $zero, L_8004740C
    if (ctx->r2 != 0) {
        // 0x800473FC: sub.s       $f0, $f2, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f8.fl;
            goto L_8004740C;
    }
    goto skip_0;
    // 0x800473FC: sub.s       $f0, $f2, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f8.fl;
    skip_0:
    // 0x80047400: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80047404: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
L_80047408:
    // 0x80047408: sub.s       $f0, $f2, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f8.fl;
L_8004740C:
    // 0x8004740C: trunc.w.s   $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80047410: mfc1        $fp, $f12
    ctx->r30 = (int32_t)ctx->f12.u32l;
    // 0x80047414: bgez        $fp, L_80047424
    if (SIGNED(ctx->r30) >= 0) {
        // 0x80047418: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80047424;
    }
    // 0x80047418: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004741C: j           L_80047434
    // 0x80047420: addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
        goto L_80047434;
    // 0x80047420: addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
L_80047424:
    // 0x80047424: lw          $v1, 0x75F0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X75F0);
    // 0x80047428: slt         $v0, $fp, $v1
    ctx->r2 = SIGNED(ctx->r30) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8004742C: beql        $v0, $zero, L_80047434
    if (ctx->r2 == 0) {
        // 0x80047430: addiu       $fp, $v1, -0x1
        ctx->r30 = ADD32(ctx->r3, -0X1);
            goto L_80047434;
    }
    goto skip_1;
    // 0x80047430: addiu       $fp, $v1, -0x1
    ctx->r30 = ADD32(ctx->r3, -0X1);
    skip_1:
L_80047434:
    // 0x80047434: add.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80047438: trunc.w.s   $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004743C: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x80047440: lw          $a2, 0x14($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X14);
    // 0x80047444: bgez        $a2, L_80047454
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80047448: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80047454;
    }
    // 0x80047448: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004744C: j           L_80047470
    // 0x80047450: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
        goto L_80047470;
    // 0x80047450: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
L_80047454:
    // 0x80047454: lw          $v1, 0x75EC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X75EC);
    // 0x80047458: lw          $a2, 0x14($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X14);
    // 0x8004745C: slt         $v0, $a2, $v1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80047460: bnel        $v0, $zero, L_80047474
    if (ctx->r2 != 0) {
        // 0x80047464: add.s       $f0, $f2, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f8.fl;
            goto L_80047474;
    }
    goto skip_2;
    // 0x80047464: add.s       $f0, $f2, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f8.fl;
    skip_2:
    // 0x80047468: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8004746C: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
L_80047470:
    // 0x80047470: add.s       $f0, $f2, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f8.fl;
L_80047474:
    // 0x80047474: trunc.w.s   $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80047478: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x8004747C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80047480: bgez        $a2, L_80047490
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80047484: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80047490;
    }
    // 0x80047484: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80047488: j           L_800474AC
    // 0x8004748C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
        goto L_800474AC;
    // 0x8004748C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_80047490:
    // 0x80047490: lw          $v1, 0x75F0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X75F0);
    // 0x80047494: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80047498: slt         $v0, $a2, $v1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8004749C: bne         $v0, $zero, L_800474B4
    if (ctx->r2 != 0) {
        // 0x800474A0: slt         $v0, $fp, $a2
        ctx->r2 = SIGNED(ctx->r30) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800474B4;
    }
    // 0x800474A0: slt         $v0, $fp, $a2
    ctx->r2 = SIGNED(ctx->r30) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800474A4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800474A8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
L_800474AC:
    // 0x800474AC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800474B0: slt         $v0, $fp, $a2
    ctx->r2 = SIGNED(ctx->r30) < SIGNED(ctx->r6) ? 1 : 0;
L_800474B4:
    // 0x800474B4: beq         $v0, $zero, L_800476FC
    if (ctx->r2 == 0) {
        // 0x800474B8: lui         $s3, 0x8013
        ctx->r19 = S32(0X8013 << 16);
            goto L_800476FC;
    }
    // 0x800474B8: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800474BC: ori         $s5, $zero, 0xFFFF
    ctx->r21 = 0 | 0XFFFF;
    // 0x800474C0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
L_800474C4:
    // 0x800474C4: addiu       $a2, $a2, 0x75D8
    ctx->r6 = ADD32(ctx->r6, 0X75D8);
    // 0x800474C8: lw          $v0, 0x14($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X14);
    // 0x800474CC: mult        $fp, $v0
    result = S64(S32(ctx->r30)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800474D0: lw          $s6, 0x10($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X10);
    // 0x800474D4: mflo        $a2
    ctx->r6 = lo;
    // 0x800474D8: addu        $s7, $s6, $a2
    ctx->r23 = ADD32(ctx->r22, ctx->r6);
    // 0x800474DC: lw          $a2, 0x14($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X14);
    // 0x800474E0: slt         $v0, $s6, $a2
    ctx->r2 = SIGNED(ctx->r22) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800474E4: beq         $v0, $zero, L_800476E8
    if (ctx->r2 == 0) {
        // 0x800474E8: nop
    
            goto L_800476E8;
    }
    // 0x800474E8: nop

L_800474EC:
    // 0x800474EC: andi        $v1, $s7, 0xFFFF
    ctx->r3 = ctx->r23 & 0XFFFF;
    // 0x800474F0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800474F4: addiu       $a2, $a2, 0x75D8
    ctx->r6 = ADD32(ctx->r6, 0X75D8);
    // 0x800474F8: lw          $v0, 0x1C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1C);
    // 0x800474FC: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80047500: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80047504: lhu         $s1, 0x0($v0)
    ctx->r17 = MEM_HU(ctx->r2, 0X0);
    // 0x80047508: beql        $s1, $s5, L_800476D8
    if (ctx->r17 == ctx->r21) {
        // 0x8004750C: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_800476D8;
    }
    goto skip_3;
    // 0x8004750C: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    skip_3:
    // 0x80047510: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80047514: andi        $v1, $s1, 0xFFFF
    ctx->r3 = ctx->r17 & 0XFFFF;
L_80047518:
    // 0x80047518: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004751C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80047520: sll         $s2, $v0, 2
    ctx->r18 = S32(ctx->r2 << 2);
    // 0x80047524: lw          $v1, 0x6FCC($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X6FCC);
    // 0x80047528: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004752C: addu        $v1, $s2, $v1
    ctx->r3 = ADD32(ctx->r18, ctx->r3);
    // 0x80047530: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    // 0x80047534: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    { if (((uint64_t)ctx->r5 & 0xFFFFFFFFE0000000ULL) == 0xFFFFFFFF80000000ULL) { ctx->r20 = MEM_HU(ctx->r5, 0x0); } else { ctx->r20 = 0; } }
    // 0x80047538: nop

    // 0x8004753C: bne         $v0, $zero, L_80047580
    if (ctx->r2 != 0) {
        // 0x80047540: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_80047580;
    }
    // 0x80047540: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80047544: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x80047548: bne         $v0, $a2, L_800475A0
    if (ctx->r2 != ctx->r6) {
        // 0x8004754C: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_800475A0;
    }
    // 0x8004754C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80047550: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80047554: jal         0x80047DAC
    // 0x80047558: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    isPointXzWithinRangeOfRef(rdram, ctx);
        goto after_0;
    // 0x80047558: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_0:
    // 0x8004755C: beq         $v0, $zero, L_800475A4
    if (ctx->r2 == 0) {
        // 0x80047560: andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
            goto L_800475A4;
    }
    // 0x80047560: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x80047564: lw          $v0, 0x6FCC($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X6FCC);
    // 0x80047568: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x8004756C: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x80047570: jal         0x80065828
    // 0x80047574: nop

    func_80065828(rdram, ctx);
        goto after_1;
    // 0x80047574: nop

    after_1:
    // 0x80047578: j           L_8004759C
    // 0x8004757C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
        goto L_8004759C;
    // 0x8004757C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
L_80047580:
    // 0x80047580: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x80047584: bne         $v0, $a2, L_800475A0
    if (ctx->r2 != ctx->r6) {
        // 0x80047588: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_800475A0;
    }
    // 0x80047588: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8004758C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80047590: jal         0x80047DAC
    // 0x80047594: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    isPointXzWithinRangeOfRef(rdram, ctx);
        goto after_2;
    // 0x80047594: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_2:
    // 0x80047598: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
L_8004759C:
    // 0x8004759C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_800475A0:
    // 0x800475A0: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
L_800475A4:
    // 0x800475A4: beq         $v0, $zero, L_800476AC
    if (ctx->r2 == 0) {
        // 0x800475A8: andi        $v1, $s1, 0xFFFF
        ctx->r3 = ctx->r17 & 0XFFFF;
            goto L_800476AC;
    }
    // 0x800475A8: andi        $v1, $s1, 0xFFFF
    ctx->r3 = ctx->r17 & 0XFFFF;
    // 0x800475AC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800475B0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800475B4: lw          $a1, 0x6FCC($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X6FCC);
    // 0x800475B8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800475BC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800475C0: lhu         $s0, 0x2($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0X2);
    // 0x800475C4: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x800475C8: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
    // 0x800475CC: beq         $v1, $s5, L_800475E4
    if (ctx->r3 == ctx->r21) {
        // 0x800475D0: sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3 << 1);
            goto L_800475E4;
    }
    // 0x800475D0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800475D4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800475D8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800475DC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800475E0: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
L_800475E4:
    // 0x800475E4: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x800475E8: beq         $v1, $s5, L_80047608
    if (ctx->r3 == ctx->r21) {
        // 0x800475EC: sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3 << 1);
            goto L_80047608;
    }
    // 0x800475EC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800475F0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800475F4: lw          $v1, 0x6FCC($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X6FCC);
    // 0x800475F8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800475FC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80047600: j           L_80047620
    // 0x80047604: sh          $s0, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r16;
        goto L_80047620;
    // 0x80047604: sh          $s0, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r16;
L_80047608:
    // 0x80047608: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8004760C: addiu       $a2, $a2, 0x75D8
    ctx->r6 = ADD32(ctx->r6, 0X75D8);
    // 0x80047610: lw          $v0, 0x1C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1C);
    // 0x80047614: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80047618: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x8004761C: sh          $s0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r16;
L_80047620:
    // 0x80047620: beq         $s4, $s5, L_80047648
    if (ctx->r20 == ctx->r21) {
        // 0x80047624: andi        $v0, $s1, 0xFFFF
        ctx->r2 = ctx->r17 & 0XFFFF;
            goto L_80047648;
    }
    // 0x80047624: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
    // 0x80047628: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8004762C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80047630: lw          $v0, 0x6FCC($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X6FCC);
    // 0x80047634: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80047638: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004763C: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    // 0x80047640: jal         0x800653B4
    // 0x80047644: nop

    setupNpcUpdateFunctions(rdram, ctx);
        goto after_3;
    // 0x80047644: nop

    after_3:
L_80047648:
    // 0x80047648: andi        $v1, $s1, 0xFFFF
    ctx->r3 = ctx->r17 & 0XFFFF;
    // 0x8004764C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80047650: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80047654: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x80047658: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8004765C: lw          $a0, 0x6FCC($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X6FCC);
    // 0x80047660: lhu         $v1, 0x6FC0($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6FC0);
    // 0x80047664: addu        $v0, $a1, $a0
    ctx->r2 = ADD32(ctx->r5, ctx->r4);
    // 0x80047668: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // 0x8004766C: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80047670: beq         $v1, $s5, L_80047690
    if (ctx->r3 == ctx->r21) {
        // 0x80047674: nop
    
            goto L_80047690;
    }
    // 0x80047674: nop

    // 0x80047678: lhu         $v1, 0x6FC0($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6FC0);
    // 0x8004767C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80047680: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80047684: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80047688: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004768C: sh          $s1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r17;
L_80047690:
    // 0x80047690: lw          $v0, 0x6FCC($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X6FCC);
    // 0x80047694: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80047698: sh          $s1, 0x6FC0($a2)
    MEM_H(0X6FC0, ctx->r6) = ctx->r17;
    // 0x8004769C: addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
    // 0x800476A0: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800476A4: j           L_800476C8
    // 0x800476A8: sh          $s5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r21;
        goto L_800476C8;
    // 0x800476A8: sh          $s5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r21;
L_800476AC:
    // 0x800476AC: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
    // 0x800476B0: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x800476B4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800476B8: lw          $v0, 0x6FCC($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X6FCC);
    // 0x800476BC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800476C0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800476C4: lhu         $s1, 0x2($v1)
    ctx->r17 = MEM_HU(ctx->r3, 0X2);
L_800476C8:
    // 0x800476C8: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
    // 0x800476CC: bne         $v0, $s5, L_80047518
    if (ctx->r2 != ctx->r21) {
        // 0x800476D0: andi        $v1, $s1, 0xFFFF
        ctx->r3 = ctx->r17 & 0XFFFF;
            goto L_80047518;
    }
    // 0x800476D0: andi        $v1, $s1, 0xFFFF
    ctx->r3 = ctx->r17 & 0XFFFF;
    // 0x800476D4: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
L_800476D8:
    // 0x800476D8: lw          $a2, 0x14($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X14);
    // 0x800476DC: slt         $v0, $s6, $a2
    ctx->r2 = SIGNED(ctx->r22) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800476E0: bne         $v0, $zero, L_800474EC
    if (ctx->r2 != 0) {
        // 0x800476E4: addiu       $s7, $s7, 0x1
        ctx->r23 = ADD32(ctx->r23, 0X1);
            goto L_800474EC;
    }
    // 0x800476E4: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
L_800476E8:
    // 0x800476E8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800476EC: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x800476F0: slt         $v0, $fp, $a2
    ctx->r2 = SIGNED(ctx->r30) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800476F4: bne         $v0, $zero, L_800474C4
    if (ctx->r2 != 0) {
        // 0x800476F8: lui         $a2, 0x8013
        ctx->r6 = S32(0X8013 << 16);
            goto L_800474C4;
    }
    // 0x800476F8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
L_800476FC:
    // 0x800476FC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80047700: lw          $v0, 0x75D4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X75D4);
    // 0x80047704: blez        $v0, L_80047770
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80047708: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80047770;
    }
    // 0x80047708: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8004770C: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80047710: addu        $s3, $v1, $zero
    ctx->r19 = ADD32(ctx->r3, 0);
L_80047714:
    // 0x80047714: lw          $v0, 0x75D0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X75D0);
    // 0x80047718: sll         $s0, $s1, 2
    ctx->r16 = S32(ctx->r17 << 2);
    // 0x8004771C: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x80047720: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80047724: beq         $a0, $zero, L_8004775C
    if (ctx->r4 == 0) {
        // 0x80047728: nop
    
            goto L_8004775C;
    }
    // 0x80047728: nop

    // 0x8004772C: jal         0x80065828
    // 0x80047730: nop

    func_80065828(rdram, ctx);
        goto after_4;
    // 0x80047730: nop

    after_4:
    // 0x80047734: beq         $v0, $zero, L_8004775C
    if (ctx->r2 == 0) {
        // 0x80047738: nop
    
            goto L_8004775C;
    }
    // 0x80047738: nop

    // 0x8004773C: lw          $v0, 0x75D0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X75D0);
    // 0x80047740: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x80047744: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80047748: jal         0x800653B4
    // 0x8004774C: nop

    setupNpcUpdateFunctions(rdram, ctx);
        goto after_5;
    // 0x8004774C: nop

    after_5:
    // 0x80047750: lw          $v0, 0x75D0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X75D0);
    // 0x80047754: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x80047758: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_8004775C:
    // 0x8004775C: lw          $v0, 0x75D4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X75D4);
    // 0x80047760: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80047764: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80047768: bne         $v0, $zero, L_80047714
    if (ctx->r2 != 0) {
        // 0x8004776C: nop
    
            goto L_80047714;
    }
    // 0x8004776C: nop

L_80047770:
    // 0x80047770: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80047774: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80047778: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8004777C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80047780: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80047784: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80047788: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8004778C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80047790: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80047794: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80047798: jr          $ra
    // 0x8004779C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8004779C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void parseDatItemSubtypes1To5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800477A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800477A4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800477A8: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x800477AC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800477B0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800477B4: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    // 0x800477B8: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x800477BC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800477C0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800477C4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800477C8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800477CC: lw          $s0, 0x4($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X4);
    // 0x800477D0: beq         $v0, $zero, L_80047AD4
    if (ctx->r2 == 0) {
        // 0x800477D4: addu        $s3, $a2, $zero
        ctx->r19 = ADD32(ctx->r6, 0);
            goto L_80047AD4;
    }
    // 0x800477D4: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x800477D8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800477DC: addiu       $v0, $v0, -0x5840
    ctx->r2 = ADD32(ctx->r2, -0X5840);
    // 0x800477E0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800477E4: addu        $v1, $v1, $v0
    gpr jr_addend_800477EC = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800477E8: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800477EC: jr          $v0
    // 0x800477F0: nop

    switch (jr_addend_800477EC >> 2) {
        case 0: goto L_800477F4; break;
        case 1: goto L_800479A0; break;
        case 2: goto L_800479DC; break;
        case 3: goto L_80047AA0; break;
        case 4: goto L_80047A88; break;
        default: switch_error(__func__, 0x800477EC, 0x8003A7C0);
    }
    // 0x800477F0: nop

L_800477F4:
    // 0x800477F4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800477F8: lbu         $v1, 0xB39($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB39);
    // 0x800477FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80047800: lw          $s2, 0x5C($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X5C);
    // 0x80047804: bne         $v1, $v0, L_8004782C
    if (ctx->r3 != ctx->r2) {
        // 0x80047808: addu        $s1, $s3, $zero
        ctx->r17 = ADD32(ctx->r19, 0);
            goto L_8004782C;
    }
    // 0x80047808: addu        $s1, $s3, $zero
    ctx->r17 = ADD32(ctx->r19, 0);
    // 0x8004780C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80047810: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80047814: addiu       $a2, $s3, 0x10
    ctx->r6 = ADD32(ctx->r19, 0X10);
    // 0x80047818: jal         0x800AA850
    // 0x8004781C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_800AA850(rdram, ctx);
        goto after_0;
    // 0x8004781C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
    // 0x80047820: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80047824: bnel        $v0, $zero, L_8004782C
    if (ctx->r2 != 0) {
        // 0x80047828: addiu       $s2, $sp, 0x10
        ctx->r18 = ADD32(ctx->r29, 0X10);
            goto L_8004782C;
    }
    goto skip_0;
    // 0x80047828: addiu       $s2, $sp, 0x10
    ctx->r18 = ADD32(ctx->r29, 0X10);
    skip_0:
L_8004782C:
    // 0x8004782C: jal         0x80056EB0
    // 0x80047830: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    walkMeshdef0List(rdram, ctx);
        goto after_1;
    // 0x80047830: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_1:
    // 0x80047834: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80047838: bne         $v1, $zero, L_80047854
    if (ctx->r3 != 0) {
        // 0x8004783C: sw          $v1, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r3;
            goto L_80047854;
    }
    // 0x8004783C: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // 0x80047840: lhu         $a0, 0x16($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X16);
    // 0x80047844: jal         0x8003ED74
    // 0x80047848: nop

    destroyNpcSlotByIndex(rdram, ctx);
        goto after_2;
    // 0x80047848: nop

    after_2:
    // 0x8004784C: j           L_80047AD8
    // 0x80047850: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80047AD8;
    // 0x80047850: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80047854:
    // 0x80047854: lhu         $v0, 0x8($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X8);
    // 0x80047858: ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    // 0x8004785C: sh          $v0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r2;
    // 0x80047860: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80047864: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80047868: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x8004786C: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80047870: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x80047874: lwc1        $f0, 0x18($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80047878: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x8004787C: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x80047880: jal         0x8001CC3C
    // 0x80047884: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    buildRotationMatrixSlot0(rdram, ctx);
        goto after_3;
    // 0x80047884: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_3:
    // 0x80047888: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8004788C: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
    // 0x80047890: jal         0x8001CCCC
    // 0x80047894: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    composeRotationMatrixSlot1(rdram, ctx);
        goto after_4;
    // 0x80047894: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_4:
    // 0x80047898: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8004789C: lw          $a1, 0x24($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X24);
    // 0x800478A0: jal         0x8001CDFC
    // 0x800478A4: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    composeRotationMatrixSlot2(rdram, ctx);
        goto after_5;
    // 0x800478A4: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_5:
    // 0x800478A8: lw          $a1, 0x28($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X28);
    // 0x800478AC: lw          $a2, 0x2C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X2C);
    // 0x800478B0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800478B4: lw          $a3, 0x30($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X30);
    // 0x800478B8: jal         0x8001CB04
    // 0x800478BC: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    applyScaleToMat3x4(rdram, ctx);
        goto after_6;
    // 0x800478BC: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_6:
    // 0x800478C0: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x800478C4: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x800478C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800478CC: lw          $a3, 0x10($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X10);
    // 0x800478D0: jal         0x8001CA90
    // 0x800478D4: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    addVec3At0x24(rdram, ctx);
        goto after_7;
    // 0x800478D4: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_7:
    // 0x800478D8: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // 0x800478DC: sw          $v0, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r2;
    // 0x800478E0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800478E4: sw          $v0, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r2;
    // 0x800478E8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800478EC: lhu         $a0, -0x6A8C($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A8C);
    // 0x800478F0: jal         0x8003E684
    // 0x800478F4: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    popNpcSlotFromTail(rdram, ctx);
        goto after_8;
    // 0x800478F4: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_8:
    // 0x800478F8: sw          $zero, 0x38($s0)
    MEM_W(0X38, ctx->r16) = 0;
    // 0x800478FC: sw          $s1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r17;
    // 0x80047900: lwc1        $f4, 0x2C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80047904: lwc1        $f2, 0x28($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80047908: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x8004790C: nop

    // 0x80047910: bc1f        L_8004794C
    if (!c1cs) {
        // 0x80047914: nop
    
            goto L_8004794C;
    }
    // 0x80047914: nop

    // 0x80047918: lwc1        $f0, 0x30($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X30);
    // 0x8004791C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80047920: nop

    // 0x80047924: bc1f        L_80047960
    if (!c1cs) {
        // 0x80047928: nop
    
            goto L_80047960;
    }
    // 0x80047928: nop

    // 0x8004792C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80047930: lhu         $v1, 0x8($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X8);
    // 0x80047934: ori         $v1, $v1, 0x400
    ctx->r3 = ctx->r3 | 0X400;
    // 0x80047938: sh          $v1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r3;
    // 0x8004793C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80047940: lwc1        $f2, 0x2C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80047944: j           L_80047978
    // 0x80047948: nop

        goto L_80047978;
    // 0x80047948: nop

L_8004794C:
    // 0x8004794C: lwc1        $f0, 0x30($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X30);
    // 0x80047950: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80047954: nop

    // 0x80047958: bc1f        L_80047978
    if (!c1cs) {
        // 0x8004795C: nop
    
            goto L_80047978;
    }
    // 0x8004795C: nop

L_80047960:
    // 0x80047960: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80047964: lhu         $v1, 0x8($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X8);
    // 0x80047968: ori         $v1, $v1, 0x800
    ctx->r3 = ctx->r3 | 0X800;
    // 0x8004796C: sh          $v1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r3;
    // 0x80047970: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80047974: lwc1        $f2, 0x30($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X30);
L_80047978:
    // 0x80047978: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004797C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80047980: lwc1        $f0, 0x44($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80047984: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80047988: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8004798C: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x80047990: jal         0x80071308
    // 0x80047994: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    dispatchDatSubtypeByRandomIndex(rdram, ctx);
        goto after_9;
    // 0x80047994: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    after_9:
    // 0x80047998: j           L_80047AD8
    // 0x8004799C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80047AD8;
    // 0x8004799C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800479A0:
    // 0x800479A0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800479A4: beq         $v0, $zero, L_800479D4
    if (ctx->r2 == 0) {
        // 0x800479A8: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_800479D4;
    }
    // 0x800479A8: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800479AC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800479B0: jal         0x80046620
    // 0x800479B4: addiu       $a1, $a0, 0x10
    ctx->r5 = ADD32(ctx->r4, 0X10);
    parseDatItemCommon(rdram, ctx);
        goto after_10;
    // 0x800479B4: addiu       $a1, $a0, 0x10
    ctx->r5 = ADD32(ctx->r4, 0X10);
    after_10:
    // 0x800479B8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800479BC: jal         0x80072AF8
    // 0x800479C0: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    walkDatTreeAndCollectSubtypes(rdram, ctx);
        goto after_11;
    // 0x800479C0: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    after_11:
    // 0x800479C4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800479C8: jal         0x8005779C
    // 0x800479CC: nop

    releaseMeshAsset(rdram, ctx);
        goto after_12;
    // 0x800479CC: nop

    after_12:
    // 0x800479D0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_800479D4:
    // 0x800479D4: j           L_80047AD4
    // 0x800479D8: sh          $v0, 0x16($s4)
    MEM_H(0X16, ctx->r20) = ctx->r2;
        goto L_80047AD4;
    // 0x800479D8: sh          $v0, 0x16($s4)
    MEM_H(0X16, ctx->r20) = ctx->r2;
L_800479DC:
    // 0x800479DC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800479E0: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x800479E4: bne         $v0, $zero, L_80047A18
    if (ctx->r2 != 0) {
        // 0x800479E8: addiu       $s1, $s0, 0x8
        ctx->r17 = ADD32(ctx->r16, 0X8);
            goto L_80047A18;
    }
    // 0x800479E8: addiu       $s1, $s0, 0x8
    ctx->r17 = ADD32(ctx->r16, 0X8);
    // 0x800479EC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800479F0: lw          $v0, -0x35E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E4);
    // 0x800479F4: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x800479F8: bne         $v0, $zero, L_80047A10
    if (ctx->r2 != 0) {
        // 0x800479FC: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80047A10;
    }
    // 0x800479FC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80047A00: jal         0x8006C8F0
    // 0x80047A04: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    getCraftRecordByIdx(rdram, ctx);
        goto after_13;
    // 0x80047A04: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_13:
    // 0x80047A08: j           L_80047A24
    // 0x80047A0C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
        goto L_80047A24;
    // 0x80047A0C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_80047A10:
    // 0x80047A10: j           L_80047A20
    // 0x80047A14: addiu       $v0, $v0, 0x75F8
    ctx->r2 = ADD32(ctx->r2, 0X75F8);
        goto L_80047A20;
    // 0x80047A14: addiu       $v0, $v0, 0x75F8
    ctx->r2 = ADD32(ctx->r2, 0X75F8);
L_80047A18:
    // 0x80047A18: jal         0x800AEA18
    // 0x80047A1C: nop

    func_800AEA18(rdram, ctx);
        goto after_14;
    // 0x80047A1C: nop

    after_14:
L_80047A20:
    // 0x80047A20: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_80047A24:
    // 0x80047A24: jal         0x80047DAC
    // 0x80047A28: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    isPointXzWithinRangeOfRef(rdram, ctx);
        goto after_15;
    // 0x80047A28: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_15:
    // 0x80047A2C: bnel        $v0, $zero, L_80047A60
    if (ctx->r2 != 0) {
        // 0x80047A30: sw          $zero, 0x38($s0)
        MEM_W(0X38, ctx->r16) = 0;
            goto L_80047A60;
    }
    goto skip_1;
    // 0x80047A30: sw          $zero, 0x38($s0)
    MEM_W(0X38, ctx->r16) = 0;
    skip_1:
    // 0x80047A34: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x80047A38: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80047A3C: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
    // 0x80047A40: slti        $v0, $v0, 0x15
    ctx->r2 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x80047A44: bne         $v0, $zero, L_80047A60
    if (ctx->r2 != 0) {
        // 0x80047A48: nop
    
            goto L_80047A60;
    }
    // 0x80047A48: nop

    // 0x80047A4C: lhu         $a0, 0x16($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X16);
    // 0x80047A50: jal         0x8003ED74
    // 0x80047A54: nop

    destroyNpcSlotByIndex(rdram, ctx);
        goto after_16;
    // 0x80047A54: nop

    after_16:
    // 0x80047A58: j           L_80047AD8
    // 0x80047A5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80047AD8;
    // 0x80047A5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80047A60:
    // 0x80047A60: lbu         $v1, 0x40($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X40);
    // 0x80047A64: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80047A68: beq         $v1, $v0, L_80047AD8
    if (ctx->r3 == ctx->r2) {
        // 0x80047A6C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80047AD8;
    }
    // 0x80047A6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80047A70: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80047A74: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    // 0x80047A78: jal         0x80072BE0
    // 0x80047A7C: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    walkDatTreeAndScaleLeafByFloat(rdram, ctx);
        goto after_17;
    // 0x80047A7C: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    after_17:
    // 0x80047A80: j           L_80047AD8
    // 0x80047A84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80047AD8;
    // 0x80047A84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80047A88:
    // 0x80047A88: lhu         $v0, 0x0($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X0);
    // 0x80047A8C: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x80047A90: bnel        $v0, $v1, L_80047AD4
    if (ctx->r2 != ctx->r3) {
        // 0x80047A94: sh          $v1, 0x0($s3)
        MEM_H(0X0, ctx->r19) = ctx->r3;
            goto L_80047AD4;
    }
    goto skip_2;
    // 0x80047A94: sh          $v1, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r3;
    skip_2:
    // 0x80047A98: j           L_80047AD8
    // 0x80047A9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80047AD8;
    // 0x80047A9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80047AA0:
    // 0x80047AA0: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80047AA4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80047AA8: lw          $a3, 0x3C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X3C);
    // 0x80047AAC: jal         0x80057C8C
    // 0x80047AB0: addiu       $a2, $s0, 0x8
    ctx->r6 = ADD32(ctx->r16, 0X8);
    addNpcToVisibilityBucket(rdram, ctx);
        goto after_18;
    // 0x80047AB0: addiu       $a2, $s0, 0x8
    ctx->r6 = ADD32(ctx->r16, 0X8);
    after_18:
    // 0x80047AB4: beq         $v0, $zero, L_80047AD4
    if (ctx->r2 == 0) {
        // 0x80047AB8: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_80047AD4;
    }
    // 0x80047AB8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80047ABC: lbu         $v1, 0x40($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X40);
    // 0x80047AC0: beq         $v1, $v0, L_80047AD4
    if (ctx->r3 == ctx->r2) {
        // 0x80047AC4: addiu       $a0, $s0, 0x40
        ctx->r4 = ADD32(ctx->r16, 0X40);
            goto L_80047AD4;
    }
    // 0x80047AC4: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x80047AC8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80047ACC: jal         0x80071928
    // 0x80047AD0: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    walkDatTreeAndVisitChildren(rdram, ctx);
        goto after_19;
    // 0x80047AD0: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_19:
L_80047AD4:
    // 0x80047AD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80047AD8:
    // 0x80047AD8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80047ADC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80047AE0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80047AE4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80047AE8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80047AEC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80047AF0: jr          $ra
    // 0x80047AF4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80047AF4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80047AF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047AF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80047AFC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80047B00: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80047B04: lw          $a0, 0x75D0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X75D0);
    // 0x80047B08: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80047B0C: jal         0x80001C98
    // 0x80047B10: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    rs_free(rdram, ctx);
        goto after_0;
    // 0x80047B10: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80047B14: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80047B18: lw          $a0, 0x75D8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X75D8);
    // 0x80047B1C: addiu       $s0, $s0, 0x75D8
    ctx->r16 = ADD32(ctx->r16, 0X75D8);
    // 0x80047B20: jal         0x80001C98
    // 0x80047B24: sw          $zero, 0x75D0($s1)
    MEM_W(0X75D0, ctx->r17) = 0;
    rs_free(rdram, ctx);
        goto after_1;
    // 0x80047B24: sw          $zero, 0x75D0($s1)
    MEM_W(0X75D0, ctx->r17) = 0;
    after_1:
    // 0x80047B28: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80047B2C: jal         0x80001C98
    // 0x80047B30: nop

    rs_free(rdram, ctx);
        goto after_2;
    // 0x80047B30: nop

    after_2:
    // 0x80047B34: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80047B38: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80047B3C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80047B40: jr          $ra
    // 0x80047B44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80047B44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void getLevelDatItemByName(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047B48: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80047B4C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80047B50: lw          $a0, 0x75D8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X75D8);
    // 0x80047B54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80047B58: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80047B5C: jal         0x80047B70
    // 0x80047B60: nop

    getDatItemByName(rdram, ctx);
        goto after_0;
    // 0x80047B60: nop

    after_0:
    // 0x80047B64: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80047B68: jr          $ra
    // 0x80047B6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80047B6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void getDatItemByName(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047B70: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x80047B74: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80047B78: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x80047B7C: beq         $v0, $zero, L_80047BA4
    if (ctx->r2 == 0) {
        // 0x80047B80: ori         $a3, $zero, 0xFFFF
        ctx->r7 = 0 | 0XFFFF;
            goto L_80047BA4;
    }
    // 0x80047B80: ori         $a3, $zero, 0xFFFF
    ctx->r7 = 0 | 0XFFFF;
L_80047B84:
    // 0x80047B84: lbu         $a0, 0x0($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X0);
    // 0x80047B88: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80047B8C: andi        $v1, $a3, 0xFFFF
    ctx->r3 = ctx->r7 & 0XFFFF;
    // 0x80047B90: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
    // 0x80047B94: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80047B98: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
    // 0x80047B9C: bne         $v1, $zero, L_80047B84
    if (ctx->r3 != 0) {
        // 0x80047BA0: addu        $a3, $a0, $v0
        ctx->r7 = ADD32(ctx->r4, ctx->r2);
            goto L_80047B84;
    }
    // 0x80047BA0: addu        $a3, $a0, $v0
    ctx->r7 = ADD32(ctx->r4, ctx->r2);
L_80047BA4:
    // 0x80047BA4: andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // 0x80047BA8: lw          $v1, 0x44($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X44);
    // 0x80047BAC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80047BB0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80047BB4: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x80047BB8: bne         $a3, $zero, L_80047BD4
    if (ctx->r7 != 0) {
        // 0x80047BBC: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80047BD4;
    }
    // 0x80047BBC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80047BC0: jr          $ra
    // 0x80047BC4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80047BC4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80047BC8:
    // 0x80047BC8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80047BCC: jr          $ra
    // 0x80047BD0: nop

    return;
    // 0x80047BD0: nop

L_80047BD4:
    // 0x80047BD4: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80047BD8: beq         $v1, $v0, L_80047C30
    if (ctx->r3 == ctx->r2) {
        // 0x80047BDC: addu        $t0, $v0, $zero
        ctx->r8 = ADD32(ctx->r2, 0);
            goto L_80047C30;
    }
    // 0x80047BDC: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80047BE0:
    // 0x80047BE0: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    // 0x80047BE4: j           L_80047BF8
    // 0x80047BE8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
        goto L_80047BF8;
    // 0x80047BE8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
L_80047BEC:
    // 0x80047BEC: beq         $v1, $zero, L_80047C14
    if (ctx->r3 == 0) {
        // 0x80047BF0: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80047C14;
    }
    // 0x80047BF0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80047BF4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80047BF8:
    // 0x80047BF8: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
    // 0x80047BFC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80047C00: beq         $v1, $v0, L_80047BEC
    if (ctx->r3 == ctx->r2) {
        // 0x80047C04: nop
    
            goto L_80047BEC;
    }
    // 0x80047C04: nop

    // 0x80047C08: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x80047C0C: bnel        $v0, $zero, L_80047C24
    if (ctx->r2 != 0) {
        // 0x80047C10: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_80047C24;
    }
    goto skip_0;
    // 0x80047C10: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    skip_0:
L_80047C14:
    // 0x80047C14: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80047C18: beq         $v0, $zero, L_80047BC8
    if (ctx->r2 == 0) {
        // 0x80047C1C: nop
    
            goto L_80047BC8;
    }
    // 0x80047C1C: nop

    // 0x80047C20: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
L_80047C24:
    // 0x80047C24: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80047C28: bne         $v0, $t0, L_80047BE0
    if (ctx->r2 != ctx->r8) {
        // 0x80047C2C: nop
    
            goto L_80047BE0;
    }
    // 0x80047C2C: nop

L_80047C30:
    // 0x80047C30: jr          $ra
    // 0x80047C34: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80047C34: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_80047C38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047C38: addu        $t1, $a0, $zero
    ctx->r9 = ADD32(ctx->r4, 0);
    // 0x80047C3C: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x80047C40: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x80047C44: beq         $v0, $zero, L_80047C6C
    if (ctx->r2 == 0) {
        // 0x80047C48: ori         $t0, $zero, 0xFFFF
        ctx->r8 = 0 | 0XFFFF;
            goto L_80047C6C;
    }
    // 0x80047C48: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
L_80047C4C:
    // 0x80047C4C: lbu         $a0, 0x0($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X0);
    // 0x80047C50: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80047C54: andi        $v1, $t0, 0xFFFF
    ctx->r3 = ctx->r8 & 0XFFFF;
    // 0x80047C58: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
    // 0x80047C5C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80047C60: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x80047C64: bne         $v1, $zero, L_80047C4C
    if (ctx->r3 != 0) {
        // 0x80047C68: addu        $t0, $a0, $v0
        ctx->r8 = ADD32(ctx->r4, ctx->r2);
            goto L_80047C4C;
    }
    // 0x80047C68: addu        $t0, $a0, $v0
    ctx->r8 = ADD32(ctx->r4, ctx->r2);
L_80047C6C:
    // 0x80047C6C: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // 0x80047C70: lw          $v1, 0x44($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X44);
    // 0x80047C74: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80047C78: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80047C7C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80047C80: bne         $t0, $zero, L_80047C9C
    if (ctx->r8 != 0) {
        // 0x80047C84: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80047C9C;
    }
    // 0x80047C84: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80047C88: j           L_80047CFC
    // 0x80047C8C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
        goto L_80047CFC;
    // 0x80047C8C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80047C90:
    // 0x80047C90: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80047C94: j           L_80047CFC
    // 0x80047C98: nop

        goto L_80047CFC;
    // 0x80047C98: nop

L_80047C9C:
    // 0x80047C9C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80047CA0: beq         $v1, $v0, L_80047CFC
    if (ctx->r3 == ctx->r2) {
        // 0x80047CA4: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80047CFC;
    }
    // 0x80047CA4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80047CA8: addu        $t1, $v0, $zero
    ctx->r9 = ADD32(ctx->r2, 0);
L_80047CAC:
    // 0x80047CAC: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    // 0x80047CB0: j           L_80047CC4
    // 0x80047CB4: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
        goto L_80047CC4;
    // 0x80047CB4: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
L_80047CB8:
    // 0x80047CB8: beq         $v1, $zero, L_80047CE0
    if (ctx->r3 == 0) {
        // 0x80047CBC: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80047CE0;
    }
    // 0x80047CBC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80047CC0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80047CC4:
    // 0x80047CC4: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x80047CC8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80047CCC: beq         $v1, $v0, L_80047CB8
    if (ctx->r3 == ctx->r2) {
        // 0x80047CD0: nop
    
            goto L_80047CB8;
    }
    // 0x80047CD0: nop

    // 0x80047CD4: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x80047CD8: bnel        $v0, $zero, L_80047CF0
    if (ctx->r2 != 0) {
        // 0x80047CDC: addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_80047CF0;
    }
    goto skip_0;
    // 0x80047CDC: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    skip_0:
L_80047CE0:
    // 0x80047CE0: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80047CE4: beq         $v0, $zero, L_80047C90
    if (ctx->r2 == 0) {
        // 0x80047CE8: nop
    
            goto L_80047C90;
    }
    // 0x80047CE8: nop

    // 0x80047CEC: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
L_80047CF0:
    // 0x80047CF0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80047CF4: bne         $v0, $t1, L_80047CAC
    if (ctx->r2 != ctx->r9) {
        // 0x80047CF8: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80047CAC;
    }
    // 0x80047CF8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80047CFC:
    // 0x80047CFC: beq         $a0, $zero, L_80047D38
    if (ctx->r4 == 0) {
        // 0x80047D00: nop
    
            goto L_80047D38;
    }
    // 0x80047D00: nop

    // 0x80047D04: beq         $a1, $zero, L_80047D38
    if (ctx->r5 == 0) {
        // 0x80047D08: nop
    
            goto L_80047D38;
    }
    // 0x80047D08: nop

    // 0x80047D0C: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x80047D10: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80047D14: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x80047D18: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80047D1C: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x80047D20: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80047D24: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80047D28: lw          $v1, 0x20($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X20);
    // 0x80047D2C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80047D30: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80047D34: sw          $v1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r3;
L_80047D38:
    // 0x80047D38: jr          $ra
    // 0x80047D3C: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    return;
    // 0x80047D3C: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
;}
RECOMP_FUNC void isNpcWithinActiveReferenceRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047D40: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80047D44: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x80047D48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80047D4C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80047D50: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80047D54: bne         $v0, $zero, L_80047D88
    if (ctx->r2 != 0) {
        // 0x80047D58: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80047D88;
    }
    // 0x80047D58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80047D5C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80047D60: lw          $v0, -0x35E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E4);
    // 0x80047D64: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x80047D68: bne         $v0, $zero, L_80047D80
    if (ctx->r2 != 0) {
        // 0x80047D6C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80047D80;
    }
    // 0x80047D6C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80047D70: jal         0x8006C8F0
    // 0x80047D74: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    getCraftRecordByIdx(rdram, ctx);
        goto after_0;
    // 0x80047D74: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // 0x80047D78: j           L_80047D94
    // 0x80047D7C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
        goto L_80047D94;
    // 0x80047D7C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_80047D80:
    // 0x80047D80: j           L_80047D90
    // 0x80047D84: addiu       $v0, $v0, 0x75F8
    ctx->r2 = ADD32(ctx->r2, 0X75F8);
        goto L_80047D90;
    // 0x80047D84: addiu       $v0, $v0, 0x75F8
    ctx->r2 = ADD32(ctx->r2, 0X75F8);
L_80047D88:
    // 0x80047D88: jal         0x800AEA18
    // 0x80047D8C: nop

    func_800AEA18(rdram, ctx);
        goto after_1;
    // 0x80047D8C: nop

    after_1:
L_80047D90:
    // 0x80047D90: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_80047D94:
    // 0x80047D94: jal         0x80047DAC
    // 0x80047D98: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    isPointXzWithinRangeOfRef(rdram, ctx);
        goto after_2;
    // 0x80047D98: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80047D9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80047DA0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80047DA4: jr          $ra
    // 0x80047DA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80047DA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void isPointXzWithinRangeOfRef(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047DAC: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80047DB0: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80047DB4: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80047DB8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80047DBC: lwc1        $f6, -0x582C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X582C);
    // 0x80047DC0: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80047DC4: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80047DC8: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80047DCC: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80047DD0: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80047DD4: nop

    // 0x80047DD8: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80047DDC: nop

    // 0x80047DE0: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80047DE4: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80047DE8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80047DEC: lwc1        $f0, -0x5828($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5828);
    // 0x80047DF0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80047DF4: nop

    // 0x80047DF8: bc1t        L_80047E04
    if (c1cs) {
        // 0x80047DFC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80047E04;
    }
    // 0x80047DFC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80047E00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80047E04:
    // 0x80047E04: jr          $ra
    // 0x80047E08: nop

    return;
    // 0x80047E08: nop

;}
RECOMP_FUNC void lookupActivePlayerCraftGridCell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047E0C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80047E10: lw          $v0, -0x35E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E4);
    // 0x80047E14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80047E18: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x80047E1C: bne         $v0, $zero, L_80047E34
    if (ctx->r2 != 0) {
        // 0x80047E20: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80047E34;
    }
    // 0x80047E20: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80047E24: jal         0x8006C8F0
    // 0x80047E28: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    getCraftRecordByIdx(rdram, ctx);
        goto after_0;
    // 0x80047E28: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // 0x80047E2C: j           L_80047E3C
    // 0x80047E30: nop

        goto L_80047E3C;
    // 0x80047E30: nop

L_80047E34:
    // 0x80047E34: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80047E38: addiu       $v0, $v0, 0x75F8
    ctx->r2 = ADD32(ctx->r2, 0X75F8);
L_80047E3C:
    // 0x80047E3C: jal         0x80047368
    // 0x80047E40: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    updateActiveGridCellState(rdram, ctx);
        goto after_1;
    // 0x80047E40: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_1:
    // 0x80047E44: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80047E48: jr          $ra
    // 0x80047E4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80047E4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80047E50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047E50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80047E54: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80047E58: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80047E5C: sll         $a0, $s1, 1
    ctx->r4 = S32(ctx->r17 << 1);
    // 0x80047E60: addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    // 0x80047E64: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80047E68: subu        $a0, $a0, $s1
    ctx->r4 = SUB32(ctx->r4, ctx->r17);
    // 0x80047E6C: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80047E70: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80047E74: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80047E78: jal         0x80001ACC
    // 0x80047E7C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x80047E7C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80047E80: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80047E84: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80047E88: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80047E8C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80047E90: sw          $a0, 0x7A5C($v1)
    MEM_W(0X7A5C, ctx->r3) = ctx->r4;
    // 0x80047E94: blez        $s1, L_80047EB4
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80047E98: sw          $s1, 0x7610($v0)
        MEM_W(0X7610, ctx->r2) = ctx->r17;
            goto L_80047EB4;
    }
    // 0x80047E98: sw          $s1, 0x7610($v0)
    MEM_W(0X7610, ctx->r2) = ctx->r17;
    // 0x80047E9C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_80047EA0:
    // 0x80047EA0: sh          $a1, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r5;
    // 0x80047EA4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80047EA8: slt         $v0, $a1, $s1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80047EAC: bne         $v0, $zero, L_80047EA0
    if (ctx->r2 != 0) {
        // 0x80047EB0: addiu       $v1, $v1, 0xB8
        ctx->r3 = ADD32(ctx->r3, 0XB8);
            goto L_80047EA0;
    }
    // 0x80047EB0: addiu       $v1, $v1, 0xB8
    ctx->r3 = ADD32(ctx->r3, 0XB8);
L_80047EB4:
    // 0x80047EB4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80047EB8: slt         $v0, $a1, $s1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80047EBC: beq         $v0, $zero, L_80047F54
    if (ctx->r2 == 0) {
        // 0x80047EC0: addiu       $a2, $zero, 0x398
        ctx->r6 = ADD32(0, 0X398);
            goto L_80047F54;
    }
    // 0x80047EC0: addiu       $a2, $zero, 0x398
    ctx->r6 = ADD32(0, 0X398);
    // 0x80047EC4: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80047EC8: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x80047ECC: addu        $t3, $a1, $zero
    ctx->r11 = ADD32(ctx->r5, 0);
    // 0x80047ED0: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x80047ED4: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
L_80047ED8:
    // 0x80047ED8: lw          $v0, 0x7A5C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X7A5C);
    // 0x80047EDC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80047EE0: addu        $a3, $v0, $a2
    ctx->r7 = ADD32(ctx->r2, ctx->r6);
    // 0x80047EE4: addiu       $v1, $a3, 0x60
    ctx->r3 = ADD32(ctx->r7, 0X60);
    // 0x80047EE8: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
    // 0x80047EEC: sh          $v0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r2;
    // 0x80047EF0: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x80047EF4: sh          $v0, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r2;
    // 0x80047EF8: addiu       $v0, $a3, 0x54
    ctx->r2 = ADD32(ctx->r7, 0X54);
    // 0x80047EFC: sh          $t0, 0x1E($a3)
    MEM_H(0X1E, ctx->r7) = ctx->r8;
    // 0x80047F00: sh          $t0, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r8;
    // 0x80047F04: sh          $t0, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r8;
    // 0x80047F08: sh          $t0, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r8;
    // 0x80047F0C: sw          $v0, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r2;
    // 0x80047F10: sb          $zero, 0x35($a3)
    MEM_B(0X35, ctx->r7) = 0;
    // 0x80047F14: sh          $zero, 0x4E($a3)
    MEM_H(0X4E, ctx->r7) = 0;
    // 0x80047F18: sh          $t3, 0x40($a3)
    MEM_H(0X40, ctx->r7) = ctx->r11;
    // 0x80047F1C: sh          $t2, 0x42($a3)
    MEM_H(0X42, ctx->r7) = ctx->r10;
L_80047F20:
    // 0x80047F20: sb          $t1, 0x57($v1)
    MEM_B(0X57, ctx->r3) = ctx->r9;
    // 0x80047F24: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80047F28: bgez        $a0, L_80047F20
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80047F2C: addiu       $v1, $v1, -0x4
        ctx->r3 = ADD32(ctx->r3, -0X4);
            goto L_80047F20;
    }
    // 0x80047F2C: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x80047F30: addiu       $a2, $a2, 0xB8
    ctx->r6 = ADD32(ctx->r6, 0XB8);
    // 0x80047F34: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80047F38: slt         $v0, $a1, $s1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80047F3C: sh          $zero, 0x12($a3)
    MEM_H(0X12, ctx->r7) = 0;
    // 0x80047F40: sh          $zero, 0x10($a3)
    MEM_H(0X10, ctx->r7) = 0;
    // 0x80047F44: sh          $zero, 0xE($a3)
    MEM_H(0XE, ctx->r7) = 0;
    // 0x80047F48: sh          $zero, 0xC($a3)
    MEM_H(0XC, ctx->r7) = 0;
    // 0x80047F4C: bne         $v0, $zero, L_80047ED8
    if (ctx->r2 != 0) {
        // 0x80047F50: sh          $zero, 0xA($a3)
        MEM_H(0XA, ctx->r7) = 0;
            goto L_80047ED8;
    }
    // 0x80047F50: sh          $zero, 0xA($a3)
    MEM_H(0XA, ctx->r7) = 0;
L_80047F54:
    // 0x80047F54: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80047F58: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80047F5C: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // 0x80047F60: lw          $v0, 0x7A5C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A5C);
    // 0x80047F64: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x80047F68: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80047F6C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80047F70: sh          $v0, 0x398($a0)
    MEM_H(0X398, ctx->r4) = ctx->r2;
    // 0x80047F74: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
    // 0x80047F78: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80047F7C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80047F80: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x80047F84: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80047F88: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80047F8C: sh          $v1, -0xB6($v0)
    MEM_H(-0XB6, ctx->r2) = ctx->r3;
L_80047F90:
    // 0x80047F90: sh          $a2, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r6;
    // 0x80047F94: sh          $a2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r6;
    // 0x80047F98: sh          $a2, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r6;
    // 0x80047F9C: sh          $a2, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r6;
    // 0x80047FA0: sh          $a2, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r6;
    // 0x80047FA4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80047FA8: slti        $v0, $a1, 0x3
    ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x80047FAC: bne         $v0, $zero, L_80047F90
    if (ctx->r2 != 0) {
        // 0x80047FB0: addiu       $a0, $a0, 0xB8
        ctx->r4 = ADD32(ctx->r4, 0XB8);
            goto L_80047F90;
    }
    // 0x80047FB0: addiu       $a0, $a0, 0xB8
    ctx->r4 = ADD32(ctx->r4, 0XB8);
    // 0x80047FB4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80047FB8: sll         $v1, $s1, 1
    ctx->r3 = S32(ctx->r17 << 1);
    // 0x80047FBC: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
    // 0x80047FC0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80047FC4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80047FC8: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x80047FCC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80047FD0: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80047FD4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80047FD8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80047FDC: lw          $a2, 0x7A5C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A5C);
    // 0x80047FE0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80047FE4: sw          $v1, 0x7A70($s0)
    MEM_W(0X7A70, ctx->r16) = ctx->r3;
    // 0x80047FE8: addiu       $v1, $s1, -0x1
    ctx->r3 = ADD32(ctx->r17, -0X1);
    // 0x80047FEC: addiu       $a3, $a2, 0x228
    ctx->r7 = ADD32(ctx->r6, 0X228);
    // 0x80047FF0: sh          $v0, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r2;
    // 0x80047FF4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80047FF8: sh          $v0, 0x228($a2)
    MEM_H(0X228, ctx->r6) = ctx->r2;
    // 0x80047FFC: sh          $v0, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r2;
    // 0x80048000: sh          $v0, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r2;
    // 0x80048004: sh          $v0, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r2;
    // 0x80048008: addiu       $a3, $a2, 0x2E0
    ctx->r7 = ADD32(ctx->r6, 0X2E0);
    // 0x8004800C: sh          $v1, 0x2E0($a2)
    MEM_H(0X2E0, ctx->r6) = ctx->r3;
    // 0x80048010: sh          $v0, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r2;
    // 0x80048014: sh          $v0, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r2;
    // 0x80048018: sh          $v0, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r2;
    // 0x8004801C: jal         0x80001ACC
    // 0x80048020: sh          $v0, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r2;
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x80048020: sh          $v0, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r2;
    after_1:
    // 0x80048024: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80048028: lw          $a0, 0x7A70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X7A70);
    // 0x8004802C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80048030: sw          $v0, 0x7A54($v1)
    MEM_W(0X7A54, ctx->r3) = ctx->r2;
    // 0x80048034: jal         0x80001ACC
    // 0x80048038: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    rs_malloc(rdram, ctx);
        goto after_2;
    // 0x80048038: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    after_2:
    // 0x8004803C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80048040: lw          $a0, 0x7A70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X7A70);
    // 0x80048044: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80048048: blez        $a0, L_80048074
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8004804C: sw          $v0, 0x7A4C($v1)
        MEM_W(0X7A4C, ctx->r3) = ctx->r2;
            goto L_80048074;
    }
    // 0x8004804C: sw          $v0, 0x7A4C($v1)
    MEM_W(0X7A4C, ctx->r3) = ctx->r2;
    // 0x80048050: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80048054: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80048058: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8004805C:
    // 0x8004805C: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
    // 0x80048060: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80048064: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80048068: slt         $v0, $a1, $a2
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8004806C: bne         $v0, $zero, L_8004805C
    if (ctx->r2 != 0) {
        // 0x80048070: addiu       $v1, $v1, 0x5
        ctx->r3 = ADD32(ctx->r3, 0X5);
            goto L_8004805C;
    }
    // 0x80048070: addiu       $v1, $v1, 0x5
    ctx->r3 = ADD32(ctx->r3, 0X5);
L_80048074:
    // 0x80048074: lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    // 0x80048078: ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // 0x8004807C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80048080: mult        $s1, $v0
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80048084: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80048088: lhu         $v1, 0x7A72($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X7A72);
    // 0x8004808C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80048090: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80048094: sh          $v1, 0x7A58($v0)
    MEM_H(0X7A58, ctx->r2) = ctx->r3;
    // 0x80048098: sra         $v0, $s1, 31
    ctx->r2 = S32(SIGNED(ctx->r17) >> 31);
    // 0x8004809C: mfhi        $t5
    ctx->r13 = hi;
    // 0x800480A0: sra         $v1, $t5, 2
    ctx->r3 = S32(SIGNED(ctx->r13) >> 2);
    // 0x800480A4: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800480A8: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
    // 0x800480AC: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x800480B0: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x800480B4: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x800480B8: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x800480BC: jal         0x80001ACC
    // 0x800480C0: sw          $v1, 0x7A60($s0)
    MEM_W(0X7A60, ctx->r16) = ctx->r3;
    rs_malloc(rdram, ctx);
        goto after_3;
    // 0x800480C0: sw          $v1, 0x7A60($s0)
    MEM_W(0X7A60, ctx->r16) = ctx->r3;
    after_3:
    // 0x800480C4: lw          $a0, 0x7A60($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X7A60);
    // 0x800480C8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800480CC: sw          $v0, 0x7A68($a1)
    MEM_W(0X7A68, ctx->r5) = ctx->r2;
    // 0x800480D0: addiu       $a1, $a1, 0x7A68
    ctx->r5 = ADD32(ctx->r5, 0X7A68);
    // 0x800480D4: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x800480D8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800480DC: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800480E0: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800480E4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800480E8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800480EC: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x800480F0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800480F4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800480F8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800480FC: jr          $ra
    // 0x80048100: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80048100: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void loadLevelTextureCache(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048104: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80048108: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004810C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80048110: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80048114: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80048118: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8004811C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80048120: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80048124: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80048128: jal         0x80023950
    // 0x8004812C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    func_80023950(rdram, ctx);
        goto after_0;
    // 0x8004812C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_0:
    // 0x80048130: lui         $v1, 0x3E0F
    ctx->r3 = S32(0X3E0F << 16);
    // 0x80048134: ori         $v1, $v1, 0x83E1
    ctx->r3 = ctx->r3 | 0X83E1;
    // 0x80048138: subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x8004813C: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80048140: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80048144: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    // 0x80048148: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8004814C: mfhi        $t0
    ctx->r8 = hi;
    // 0x80048150: srl         $v0, $t0, 9
    ctx->r2 = S32(U32(ctx->r8) >> 9);
    // 0x80048154: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80048158: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x8004815C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80048160: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80048164: jal         0x80001ACC
    // 0x80048168: sw          $v0, 0x7A44($s0)
    MEM_W(0X7A44, ctx->r16) = ctx->r2;
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x80048168: sw          $v0, 0x7A44($s0)
    MEM_W(0X7A44, ctx->r16) = ctx->r2;
    after_1:
    // 0x8004816C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80048170: lw          $a1, 0x7A44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X7A44);
    // 0x80048174: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80048178: slt         $v0, $s1, $a1
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8004817C: beq         $v0, $zero, L_800481B8
    if (ctx->r2 == 0) {
        // 0x80048180: sw          $a0, 0x7614($v1)
        MEM_W(0X7614, ctx->r3) = ctx->r4;
            goto L_800481B8;
    }
    // 0x80048180: sw          $a0, 0x7614($v1)
    MEM_W(0X7614, ctx->r3) = ctx->r4;
    // 0x80048184: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80048188: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
L_8004818C:
    // 0x8004818C: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80048190: addiu       $a0, $s1, -0x1
    ctx->r4 = ADD32(ctx->r17, -0X1);
    // 0x80048194: addiu       $v1, $s1, 0x1
    ctx->r3 = ADD32(ctx->r17, 0X1);
    // 0x80048198: addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
    // 0x8004819C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800481A0: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800481A4: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x800481A8: sh          $s1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r17;
    // 0x800481AC: slt         $v0, $s1, $a1
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800481B0: bne         $v0, $zero, L_8004818C
    if (ctx->r2 != 0) {
        // 0x800481B4: sll         $v0, $s1, 1
        ctx->r2 = S32(ctx->r17 << 1);
            goto L_8004818C;
    }
    // 0x800481B4: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
L_800481B8:
    // 0x800481B8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800481BC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800481C0: lw          $v0, 0x7614($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7614);
    // 0x800481C4: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x800481C8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800481CC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800481D0: lw          $v1, 0x7A44($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X7A44);
    // 0x800481D4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800481D8: sh          $v0, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r2;
    // 0x800481DC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800481E0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800481E4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800481E8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800481EC: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x800481F0: sh          $v1, -0xA($v0)
    MEM_H(-0XA, ctx->r2) = ctx->r3;
L_800481F4:
    // 0x800481F4: sh          $a1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r5;
    // 0x800481F8: sh          $a1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r5;
    // 0x800481FC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80048200: slti        $v0, $s1, 0x3
    ctx->r2 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x80048204: bne         $v0, $zero, L_800481F4
    if (ctx->r2 != 0) {
        // 0x80048208: addiu       $a0, $a0, 0xC
        ctx->r4 = ADD32(ctx->r4, 0XC);
            goto L_800481F4;
    }
    // 0x80048208: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x8004820C: addiu       $a0, $zero, 0x136C
    ctx->r4 = ADD32(0, 0X136C);
    // 0x80048210: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80048214: addiu       $s1, $zero, 0xFFF
    ctx->r17 = ADD32(0, 0XFFF);
    // 0x80048218: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004821C: ori         $a3, $zero, 0xFFFF
    ctx->r7 = 0 | 0XFFFF;
    // 0x80048220: lw          $a2, 0x7614($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X7614);
    // 0x80048224: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80048228: lhu         $v0, 0x7A46($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7A46);
    // 0x8004822C: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x80048230: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80048234: sh          $a3, 0x24($a2)
    MEM_H(0X24, ctx->r6) = ctx->r7;
    // 0x80048238: sh          $v1, 0x26($a2)
    MEM_H(0X26, ctx->r6) = ctx->r3;
    // 0x8004823C: sh          $v0, 0x30($a2)
    MEM_H(0X30, ctx->r6) = ctx->r2;
    // 0x80048240: jal         0x80001ACC
    // 0x80048244: sh          $a3, 0x32($a2)
    MEM_H(0X32, ctx->r6) = ctx->r7;
    rs_malloc(rdram, ctx);
        goto after_2;
    // 0x80048244: sh          $a3, 0x32($a2)
    MEM_H(0X32, ctx->r6) = ctx->r7;
    after_2:
    // 0x80048248: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8004824C: addu        $v0, $s0, $s1
    ctx->r2 = ADD32(ctx->r16, ctx->r17);
L_80048250:
    // 0x80048250: sb          $s1, 0x58($v0)
    MEM_B(0X58, ctx->r2) = ctx->r17;
    // 0x80048254: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80048258: bgez        $s1, L_80048250
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8004825C: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80048250;
    }
    // 0x8004825C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80048260: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80048264: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80048268: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004826C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_80048270:
    // 0x80048270: addu        $a0, $s0, $a3
    ctx->r4 = ADD32(ctx->r16, ctx->r7);
    // 0x80048274: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    // 0x80048278: addu        $v1, $s0, $a2
    ctx->r3 = ADD32(ctx->r16, ctx->r6);
    // 0x8004827C: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x80048280: sll         $v0, $s1, 4
    ctx->r2 = S32(ctx->r17 << 4);
    // 0x80048284: sb          $v0, 0x1058($a0)
    MEM_B(0X1058, ctx->r4) = ctx->r2;
    // 0x80048288: sb          $v0, 0x1058($v1)
    MEM_B(0X1058, ctx->r3) = ctx->r2;
    // 0x8004828C: sb          $v0, 0x1058($a1)
    MEM_B(0X1058, ctx->r5) = ctx->r2;
    // 0x80048290: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80048294: slti        $v0, $s1, 0x100
    ctx->r2 = SIGNED(ctx->r17) < 0X100 ? 1 : 0;
    // 0x80048298: bne         $v0, $zero, L_80048270
    if (ctx->r2 != 0) {
        // 0x8004829C: addiu       $a1, $a1, 0x3
        ctx->r5 = ADD32(ctx->r5, 0X3);
            goto L_80048270;
    }
    // 0x8004829C: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x800482A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800482A4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800482A8: lwc1        $f0, -0x5804($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5804);
    // 0x800482AC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800482B0: lwc1        $f2, -0x5800($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5800);
    // 0x800482B4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800482B8: sb          $v0, 0x44($s0)
    MEM_B(0X44, ctx->r16) = ctx->r2;
    // 0x800482BC: sb          $v0, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r2;
    // 0x800482C0: lw          $v1, 0x7A44($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X7A44);
    // 0x800482C4: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    // 0x800482C8: sh          $v0, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r2;
    // 0x800482CC: addiu       $v0, $s0, 0x58
    ctx->r2 = ADD32(ctx->r16, 0X58);
    // 0x800482D0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800482D4: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // 0x800482D8: sh          $v0, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = ctx->r2;
    // 0x800482DC: sh          $v0, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r2;
    // 0x800482E0: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x800482E4: sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
    // 0x800482E8: addiu       $v0, $s0, 0x1058
    ctx->r2 = ADD32(ctx->r16, 0X1058);
    // 0x800482EC: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x800482F0: addiu       $v0, $s0, 0x48
    ctx->r2 = ADD32(ctx->r16, 0X48);
    // 0x800482F4: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    // 0x800482F8: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x800482FC: slt         $v1, $s1, $v1
    ctx->r3 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80048300: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80048304: beq         $v1, $zero, L_80048378
    if (ctx->r3 == 0) {
        // 0x80048308: swc1        $f2, 0x3C($s0)
        MEM_W(0X3C, ctx->r16) = ctx->f2.u32l;
            goto L_80048378;
    }
    // 0x80048308: swc1        $f2, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f2.u32l;
    // 0x8004830C: lui         $s6, 0x8004
    ctx->r22 = S32(0X8004 << 16);
    // 0x80048310: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80048314: ori         $s5, $zero, 0xFFFF
    ctx->r21 = 0 | 0XFFFF;
    // 0x80048318: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x8004831C: addiu       $s2, $zero, 0x3C
    ctx->r18 = ADD32(0, 0X3C);
L_80048320:
    // 0x80048320: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x80048324: addiu       $a1, $s6, -0x5820
    ctx->r5 = ADD32(ctx->r22, -0X5820);
    // 0x80048328: jal         0x80033CC4
    // 0x8004832C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    sprintf_recomp(rdram, ctx);
        goto after_3;
    // 0x8004832C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_3:
    // 0x80048330: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x80048334: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80048338: jal         0x80022B90
    // 0x8004833C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    registerHmtTextureInTable(rdram, ctx);
        goto after_4;
    // 0x8004833C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_4:
    // 0x80048340: lw          $v1, 0x7614($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X7614);
    // 0x80048344: addu        $v1, $s2, $v1
    ctx->r3 = ADD32(ctx->r18, ctx->r3);
    // 0x80048348: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
    // 0x8004834C: jal         0x80023364
    // 0x80048350: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    func_80023364(rdram, ctx);
        goto after_5;
    // 0x80048350: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    after_5:
    // 0x80048354: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80048358: lw          $v1, 0x7614($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X7614);
    // 0x8004835C: lw          $a0, 0x7A44($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X7A44);
    // 0x80048360: addu        $v1, $s2, $v1
    ctx->r3 = ADD32(ctx->r18, ctx->r3);
    // 0x80048364: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x80048368: slt         $a0, $s1, $a0
    ctx->r4 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8004836C: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
    // 0x80048370: bne         $a0, $zero, L_80048320
    if (ctx->r4 != 0) {
        // 0x80048374: sh          $s5, 0x8($v1)
        MEM_H(0X8, ctx->r3) = ctx->r21;
            goto L_80048320;
    }
    // 0x80048374: sh          $s5, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r21;
L_80048378:
    // 0x80048378: jal         0x80001C98
    // 0x8004837C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    rs_free(rdram, ctx);
        goto after_6;
    // 0x8004837C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // 0x80048380: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80048384: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80048388: addiu       $a3, $a3, -0x5810
    ctx->r7 = ADD32(ctx->r7, -0X5810);
    // 0x8004838C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80048390: lw          $a0, -0x76E0($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X76E0);
    // 0x80048394: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80048398: lw          $a2, 0x7CFC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X7CFC);
    // 0x8004839C: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800483A0: jal         0x80004AAC
    // 0x800483A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    findAssetAcrossSegments(rdram, ctx);
        goto after_7;
    // 0x800483A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_7:
    // 0x800483A8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800483AC: addiu       $a1, $v1, 0x7A20
    ctx->r5 = ADD32(ctx->r3, 0X7A20);
    // 0x800483B0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800483B4: addiu       $a0, $v1, 0x7620
    ctx->r4 = ADD32(ctx->r3, 0X7620);
    // 0x800483B8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800483BC: sw          $v0, 0x7A48($v1)
    MEM_W(0X7A48, ctx->r3) = ctx->r2;
L_800483C0:
    // 0x800483C0: addu        $v0, $s1, $a1
    ctx->r2 = ADD32(ctx->r17, ctx->r5);
    // 0x800483C4: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x800483C8: sb          $s1, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r17;
    // 0x800483CC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800483D0: slti        $v0, $s1, 0x20
    ctx->r2 = SIGNED(ctx->r17) < 0X20 ? 1 : 0;
    // 0x800483D4: bne         $v0, $zero, L_800483C0
    if (ctx->r2 != 0) {
        // 0x800483D8: addiu       $a0, $a0, 0x20
        ctx->r4 = ADD32(ctx->r4, 0X20);
            goto L_800483C0;
    }
    // 0x800483D8: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x800483DC: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    // 0x800483E0: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    // 0x800483E4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x800483E8: lui         $a3, 0x8005
    ctx->r7 = S32(0X8005 << 16);
    // 0x800483EC: jal         0x80006C28
    // 0x800483F0: addiu       $a3, $a3, -0x6A04
    ctx->r7 = ADD32(ctx->r7, -0X6A04);
    registerServiceWorker(rdram, ctx);
        goto after_8;
    // 0x800483F0: addiu       $a3, $a3, -0x6A04
    ctx->r7 = ADD32(ctx->r7, -0X6A04);
    after_8:
    // 0x800483F4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800483F8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800483FC: jal         0x80006D9C
    // 0x80048400: sw          $v0, 0x7A40($v1)
    MEM_W(0X7A40, ctx->r3) = ctx->r2;
    startServiceWorker(rdram, ctx);
        goto after_9;
    // 0x80048400: sw          $v0, 0x7A40($v1)
    MEM_W(0X7A40, ctx->r3) = ctx->r2;
    after_9:
    // 0x80048404: jal         0x80023950
    // 0x80048408: nop

    func_80023950(rdram, ctx);
        goto after_10;
    // 0x80048408: nop

    after_10:
    // 0x8004840C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80048410: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80048414: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80048418: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8004841C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80048420: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80048424: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80048428: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004842C: jr          $ra
    // 0x80048430: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80048430: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80048434(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048434: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80048438: lw          $v1, 0x7A44($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X7A44);
    // 0x8004843C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80048440: slt         $v0, $a1, $v1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80048444: beq         $v0, $zero, L_80048484
    if (ctx->r2 == 0) {
        // 0x80048448: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80048484;
    }
    // 0x80048448: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004844C: lw          $a3, 0x7614($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X7614);
    // 0x80048450: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x80048454: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
L_80048458:
    // 0x80048458: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8004845C: addiu       $a0, $a1, -0x1
    ctx->r4 = ADD32(ctx->r5, -0X1);
    // 0x80048460: addiu       $v1, $a1, 0x1
    ctx->r3 = ADD32(ctx->r5, 0X1);
    // 0x80048464: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x80048468: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004846C: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80048470: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x80048474: sh          $a1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r5;
    // 0x80048478: slt         $v0, $a1, $a2
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8004847C: bne         $v0, $zero, L_80048458
    if (ctx->r2 != 0) {
        // 0x80048480: sll         $v0, $a1, 1
        ctx->r2 = S32(ctx->r5 << 1);
            goto L_80048458;
    }
    // 0x80048480: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
L_80048484:
    // 0x80048484: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80048488: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004848C: lw          $v0, 0x7614($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7614);
    // 0x80048490: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // 0x80048494: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80048498: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004849C: lw          $v1, 0x7A44($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X7A44);
    // 0x800484A0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800484A4: sh          $v0, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r2;
    // 0x800484A8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800484AC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800484B0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800484B4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800484B8: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x800484BC: sh          $v1, -0xA($v0)
    MEM_H(-0XA, ctx->r2) = ctx->r3;
L_800484C0:
    // 0x800484C0: sh          $a2, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r6;
    // 0x800484C4: sh          $a2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r6;
    // 0x800484C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800484CC: slti        $v0, $a1, 0x3
    ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x800484D0: bne         $v0, $zero, L_800484C0
    if (ctx->r2 != 0) {
        // 0x800484D4: addiu       $a0, $a0, 0xC
        ctx->r4 = ADD32(ctx->r4, 0XC);
            goto L_800484C0;
    }
    // 0x800484D4: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x800484D8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800484DC: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x800484E0: lw          $a0, 0x7614($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X7614);
    // 0x800484E4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800484E8: lhu         $v0, 0x7A46($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7A46);
    // 0x800484EC: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x800484F0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800484F4: sh          $a1, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r5;
    // 0x800484F8: sh          $v1, 0x26($a0)
    MEM_H(0X26, ctx->r4) = ctx->r3;
    // 0x800484FC: sh          $v0, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r2;
    // 0x80048500: jr          $ra
    // 0x80048504: sh          $a1, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r5;
    return;
    // 0x80048504: sh          $a1, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_80048508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048508: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004850C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80048510: addu        $t3, $a0, $zero
    ctx->r11 = ADD32(ctx->r4, 0);
    // 0x80048514: bltz        $t3, L_80048550
    if (SIGNED(ctx->r11) < 0) {
        // 0x80048518: addu        $t4, $a1, $zero
        ctx->r12 = ADD32(ctx->r5, 0);
            goto L_80048550;
    }
    // 0x80048518: addu        $t4, $a1, $zero
    ctx->r12 = ADD32(ctx->r5, 0);
    // 0x8004851C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80048520: addiu       $a0, $v0, 0x6DC0
    ctx->r4 = ADD32(ctx->r2, 0X6DC0);
    // 0x80048524: lhu         $v1, 0x38($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X38);
    // 0x80048528: slt         $v0, $t3, $v1
    ctx->r2 = SIGNED(ctx->r11) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8004852C: beql        $v0, $zero, L_80048554
    if (ctx->r2 == 0) {
        // 0x80048530: addu        $a0, $t3, $zero
        ctx->r4 = ADD32(ctx->r11, 0);
            goto L_80048554;
    }
    goto skip_0;
    // 0x80048530: addu        $a0, $t3, $zero
    ctx->r4 = ADD32(ctx->r11, 0);
    skip_0:
    // 0x80048534: bltzl       $t4, L_80048554
    if (SIGNED(ctx->r12) < 0) {
        // 0x80048538: addu        $a0, $t3, $zero
        ctx->r4 = ADD32(ctx->r11, 0);
            goto L_80048554;
    }
    goto skip_1;
    // 0x80048538: addu        $a0, $t3, $zero
    ctx->r4 = ADD32(ctx->r11, 0);
    skip_1:
    // 0x8004853C: lhu         $v0, 0x3A($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3A);
    // 0x80048540: slt         $v0, $t4, $v0
    ctx->r2 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80048544: mult        $t4, $v1
    result = S64(S32(ctx->r12)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80048548: bne         $v0, $zero, L_80048564
    if (ctx->r2 != 0) {
        // 0x8004854C: nop
    
            goto L_80048564;
    }
    // 0x8004854C: nop

L_80048550:
    // 0x80048550: addu        $a0, $t3, $zero
    ctx->r4 = ADD32(ctx->r11, 0);
L_80048554:
    // 0x80048554: jal         0x80048948
    // 0x80048558: addu        $a1, $t4, $zero
    ctx->r5 = ADD32(ctx->r12, 0);
    func_80048948(rdram, ctx);
        goto after_0;
    // 0x80048558: addu        $a1, $t4, $zero
    ctx->r5 = ADD32(ctx->r12, 0);
    after_0:
    // 0x8004855C: j           L_8004893C
    // 0x80048560: nop

        goto L_8004893C;
    // 0x80048560: nop

L_80048564:
    // 0x80048564: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x80048568: mflo        $t5
    ctx->r13 = lo;
    // 0x8004856C: addu        $t2, $t3, $t5
    ctx->r10 = ADD32(ctx->r11, ctx->r13);
    // 0x80048570: sll         $v0, $t2, 1
    ctx->r2 = S32(ctx->r10 << 1);
    // 0x80048574: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80048578: lhu         $a3, 0x0($v0)
    ctx->r7 = MEM_HU(ctx->r2, 0X0);
    // 0x8004857C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80048580: andi        $v1, $a3, 0xFFFF
    ctx->r3 = ctx->r7 & 0XFFFF;
    // 0x80048584: beq         $v1, $v0, L_800485C0
    if (ctx->r3 == ctx->r2) {
        // 0x80048588: andi        $v0, $a3, 0x8000
        ctx->r2 = ctx->r7 & 0X8000;
            goto L_800485C0;
    }
    // 0x80048588: andi        $v0, $a3, 0x8000
    ctx->r2 = ctx->r7 & 0X8000;
    // 0x8004858C: beq         $v0, $zero, L_800485C4
    if (ctx->r2 == 0) {
        // 0x80048590: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800485C4;
    }
    // 0x80048590: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80048594: beq         $a2, $zero, L_800485C4
    if (ctx->r6 == 0) {
        // 0x80048598: andi        $v1, $v1, 0x7FFF
        ctx->r3 = ctx->r3 & 0X7FFF;
            goto L_800485C4;
    }
    // 0x80048598: andi        $v1, $v1, 0x7FFF
    ctx->r3 = ctx->r3 & 0X7FFF;
    // 0x8004859C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800485A0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800485A4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800485A8: lw          $v1, 0x6FCC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X6FCC);
    // 0x800485AC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800485B0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800485B4: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x800485B8: j           L_8004893C
    // 0x800485BC: nop

        goto L_8004893C;
    // 0x800485BC: nop

L_800485C0:
    // 0x800485C0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800485C4:
    // 0x800485C4: lw          $v1, 0x6DC0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X6DC0);
    // 0x800485C8: sll         $v0, $t2, 1
    ctx->r2 = S32(ctx->r10 << 1);
    // 0x800485CC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800485D0: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800485D4: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x800485D8: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x800485DC: beq         $v0, $a1, L_8004866C
    if (ctx->r2 == ctx->r5) {
        // 0x800485E0: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004866C;
    }
    // 0x800485E0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800485E4: lw          $a0, 0x7A5C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X7A5C);
    // 0x800485E8: lhu         $v1, 0x22A($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X22A);
    // 0x800485EC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800485F0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800485F4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800485F8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800485FC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80048600: addu        $a2, $a0, $v0
    ctx->r6 = ADD32(ctx->r4, ctx->r2);
    // 0x80048604: lhu         $v0, 0x6($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X6);
    // 0x80048608: beq         $v0, $a1, L_8004864C
    if (ctx->r2 == ctx->r5) {
        // 0x8004860C: nop
    
            goto L_8004864C;
    }
    // 0x8004860C: nop

    // 0x80048610: ori         $a3, $zero, 0xFFFF
    ctx->r7 = 0 | 0XFFFF;
    // 0x80048614: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
L_80048618:
    // 0x80048618: lhu         $a0, 0x8($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X8);
    // 0x8004861C: bne         $a0, $a3, L_8004864C
    if (ctx->r4 != ctx->r7) {
        // 0x80048620: nop
    
            goto L_8004864C;
    }
    // 0x80048620: nop

    // 0x80048624: lhu         $v0, 0x2($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X2);
    // 0x80048628: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8004862C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80048630: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80048634: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80048638: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8004863C: addu        $a2, $a1, $v1
    ctx->r6 = ADD32(ctx->r5, ctx->r3);
    // 0x80048640: lhu         $v0, 0x6($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X6);
    // 0x80048644: bne         $v0, $a0, L_80048618
    if (ctx->r2 != ctx->r4) {
        // 0x80048648: nop
    
            goto L_80048618;
    }
    // 0x80048648: nop

L_8004864C:
    // 0x8004864C: lhu         $v1, 0x16($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X16);
    // 0x80048650: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80048654: beq         $v1, $v0, L_8004866C
    if (ctx->r3 == ctx->r2) {
        // 0x80048658: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004866C;
    }
    // 0x80048658: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004865C: lhu         $v0, 0x6FC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6FC0);
    // 0x80048660: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x80048664: bne         $v0, $t0, L_80048674
    if (ctx->r2 != ctx->r8) {
        // 0x80048668: nop
    
            goto L_80048674;
    }
    // 0x80048668: nop

L_8004866C:
    // 0x8004866C: j           L_8004893C
    // 0x80048670: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8004893C;
    // 0x80048670: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80048674:
    // 0x80048674: lhu         $a3, 0x1E($a2)
    ctx->r7 = MEM_HU(ctx->r6, 0X1E);
    // 0x80048678: andi        $a0, $a3, 0xFFFF
    ctx->r4 = ctx->r7 & 0XFFFF;
    // 0x8004867C: beql        $a0, $t0, L_800488B0
    if (ctx->r4 == ctx->r8) {
        // 0x80048680: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800488B0;
    }
    goto skip_2;
    // 0x80048680: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    skip_2:
    // 0x80048684: lhu         $v0, 0x14($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X14);
    // 0x80048688: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x8004868C: beq         $v0, $zero, L_80048724
    if (ctx->r2 == 0) {
        // 0x80048690: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80048724;
    }
    // 0x80048690: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80048694: lhu         $a0, 0x4($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X4);
    // 0x80048698: beq         $a0, $t0, L_800486C4
    if (ctx->r4 == ctx->r8) {
        // 0x8004869C: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800486C4;
    }
    // 0x8004869C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800486A0: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x800486A4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800486A8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800486AC: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800486B0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800486B4: lw          $v1, 0x7A5C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A5C);
    // 0x800486B8: lhu         $a0, 0x6($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X6);
    // 0x800486BC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800486C0: sh          $a0, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r4;
L_800486C4:
    // 0x800486C4: lhu         $a0, 0x6($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X6);
    // 0x800486C8: beq         $a0, $t0, L_800486F4
    if (ctx->r4 == ctx->r8) {
        // 0x800486CC: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800486F4;
    }
    // 0x800486CC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800486D0: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x800486D4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800486D8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800486DC: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800486E0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800486E4: lw          $v1, 0x7A5C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A5C);
    // 0x800486E8: lhu         $a0, 0x4($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X4);
    // 0x800486EC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800486F0: sh          $a0, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r4;
L_800486F4:
    // 0x800486F4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800486F8: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
L_800486FC:
    // 0x800486FC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80048700: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80048704: sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // 0x80048708: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8004870C: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x80048710: sltiu       $v0, $v0, 0x5
    ctx->r2 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x80048714: bne         $v0, $zero, L_800486FC
    if (ctx->r2 != 0) {
        // 0x80048718: andi        $v0, $a3, 0xFFFF
        ctx->r2 = ctx->r7 & 0XFFFF;
            goto L_800486FC;
    }
    // 0x80048718: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x8004871C: j           L_800488A8
    // 0x80048720: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
        goto L_800488A8;
    // 0x80048720: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80048724:
    // 0x80048724: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x80048728: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8004872C: lw          $a0, 0x6FCC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X6FCC);
    // 0x80048730: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80048734: addu        $a1, $v1, $a0
    ctx->r5 = ADD32(ctx->r3, ctx->r4);
    // 0x80048738: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8004873C: beq         $v0, $t0, L_8004875C
    if (ctx->r2 == ctx->r8) {
        // 0x80048740: sll         $v1, $v0, 1
        ctx->r3 = S32(ctx->r2 << 1);
            goto L_8004875C;
    }
    // 0x80048740: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80048744: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80048748: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8004874C: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x80048750: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80048754: j           L_80048790
    // 0x80048758: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
        goto L_80048790;
    // 0x80048758: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
L_8004875C:
    // 0x8004875C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80048760: addiu       $v1, $v1, 0x6DC0
    ctx->r3 = ADD32(ctx->r3, 0X6DC0);
    // 0x80048764: lh          $a0, 0x1A($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X1A);
    // 0x80048768: lhu         $v0, 0x38($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X38);
    // 0x8004876C: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80048770: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x80048774: lh          $v0, 0x18($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X18);
    // 0x80048778: lhu         $a0, 0x2($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X2);
    // 0x8004877C: mflo        $t5
    ctx->r13 = lo;
    // 0x80048780: addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // 0x80048784: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80048788: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004878C: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
L_80048790:
    // 0x80048790: andi        $v1, $a3, 0xFFFF
    ctx->r3 = ctx->r7 & 0XFFFF;
    // 0x80048794: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80048798: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004879C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800487A0: lw          $a1, 0x6FCC($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X6FCC);
    // 0x800487A4: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x800487A8: addu        $a0, $t0, $a1
    ctx->r4 = ADD32(ctx->r8, ctx->r5);
    // 0x800487AC: lhu         $v1, 0x2($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X2);
    // 0x800487B0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800487B4: beq         $v1, $v0, L_800487D4
    if (ctx->r3 == ctx->r2) {
        // 0x800487B8: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_800487D4;
    }
    // 0x800487B8: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x800487BC: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x800487C0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800487C4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800487C8: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800487CC: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800487D0: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_800487D4:
    // 0x800487D4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800487D8: lhu         $a0, 0x6FC0($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X6FC0);
    // 0x800487DC: lw          $v1, 0x6FCC($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X6FCC);
    // 0x800487E0: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x800487E4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800487E8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800487EC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800487F0: addu        $v1, $t0, $v1
    ctx->r3 = ADD32(ctx->r8, ctx->r3);
    // 0x800487F4: sh          $a3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r7;
    // 0x800487F8: sh          $a0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r4;
    // 0x800487FC: lhu         $v0, 0x14($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X14);
    // 0x80048800: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // 0x80048804: bne         $v0, $zero, L_8004887C
    if (ctx->r2 != 0) {
        // 0x80048808: sh          $a3, 0x6FC0($a1)
        MEM_H(0X6FC0, ctx->r5) = ctx->r7;
            goto L_8004887C;
    }
    // 0x80048808: sh          $a3, 0x6FC0($a1)
    MEM_H(0X6FC0, ctx->r5) = ctx->r7;
    // 0x8004880C: lhu         $v0, 0xA($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0XA);
    // 0x80048810: beq         $v0, $zero, L_800488A4
    if (ctx->r2 == 0) {
        // 0x80048814: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_800488A4;
    }
    // 0x80048814: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80048818: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8004881C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80048820: lw          $t1, 0x7A4C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X7A4C);
    // 0x80048824: andi        $v1, $a3, 0xFFFF
    ctx->r3 = ctx->r7 & 0XFFFF;
L_80048828:
    // 0x80048828: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x8004882C: beq         $v0, $zero, L_800488A4
    if (ctx->r2 == 0) {
        // 0x80048830: sll         $v1, $v1, 1
        ctx->r3 = S32(ctx->r3 << 1);
            goto L_800488A4;
    }
    // 0x80048830: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80048834: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80048838: addu        $v1, $a2, $v1
    ctx->r3 = ADD32(ctx->r6, ctx->r3);
    // 0x8004883C: lhu         $a1, 0x7A58($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0X7A58);
    // 0x80048840: lhu         $a0, 0xA($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0XA);
    // 0x80048844: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x80048848: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8004884C: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80048850: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x80048854: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x80048858: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8004885C: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80048860: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // 0x80048864: lhu         $v0, 0xA($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0XA);
    // 0x80048868: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8004886C: beq         $v0, $zero, L_800488A4
    if (ctx->r2 == 0) {
        // 0x80048870: sh          $a1, 0x7A58($t0)
        MEM_H(0X7A58, ctx->r8) = ctx->r5;
            goto L_800488A4;
    }
    // 0x80048870: sh          $a1, 0x7A58($t0)
    MEM_H(0X7A58, ctx->r8) = ctx->r5;
    // 0x80048874: j           L_80048828
    // 0x80048878: andi        $v1, $a3, 0xFFFF
    ctx->r3 = ctx->r7 & 0XFFFF;
        goto L_80048828;
    // 0x80048878: andi        $v1, $a3, 0xFFFF
    ctx->r3 = ctx->r7 & 0XFFFF;
L_8004887C:
    // 0x8004887C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80048880: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
L_80048884:
    // 0x80048884: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80048888: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x8004888C: sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // 0x80048890: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80048894: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x80048898: sltiu       $v0, $v0, 0x5
    ctx->r2 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x8004889C: bne         $v0, $zero, L_80048884
    if (ctx->r2 != 0) {
        // 0x800488A0: andi        $v0, $a3, 0xFFFF
        ctx->r2 = ctx->r7 & 0XFFFF;
            goto L_80048884;
    }
    // 0x800488A0: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
L_800488A4:
    // 0x800488A4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_800488A8:
    // 0x800488A8: sh          $v0, 0x1E($a2)
    MEM_H(0X1E, ctx->r6) = ctx->r2;
    // 0x800488AC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
L_800488B0:
    // 0x800488B0: sh          $t3, 0x18($a2)
    MEM_H(0X18, ctx->r6) = ctx->r11;
    // 0x800488B4: sh          $t4, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r12;
    // 0x800488B8: lw          $v1, 0x6DC0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X6DC0);
    // 0x800488BC: sll         $v0, $t2, 1
    ctx->r2 = S32(ctx->r10 << 1);
    // 0x800488C0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800488C4: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x800488C8: addiu       $a0, $a0, 0x6DC0
    ctx->r4 = ADD32(ctx->r4, 0X6DC0);
    // 0x800488CC: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x800488D0: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x800488D4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800488D8: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x800488DC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800488E0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800488E4: lb          $a1, 0x3($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X3);
    // 0x800488E8: lb          $v0, 0x4($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X4);
    // 0x800488EC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800488F0: lwc1        $f4, -0x57FC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X57FC);
    // 0x800488F4: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x800488F8: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800488FC: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80048900: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80048904: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x80048908: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004890C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80048910: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80048914: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80048918: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004891C: lwc1        $f2, -0x57F8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X57F8);
    // 0x80048920: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80048924: nop

    // 0x80048928: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8004892C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80048930: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // 0x80048934: sh          $v1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r3;
    // 0x80048938: swc1        $f0, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f0.u32l;
L_8004893C:
    // 0x8004893C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80048940: jr          $ra
    // 0x80048944: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80048944: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80048948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048948: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004894C: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80048950: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x80048954: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80048958: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x8004895C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80048960: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80048964: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80048968: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_8004896C:
    // 0x8004896C: bgez        $s4, L_8004898C
    if (SIGNED(ctx->r20) >= 0) {
        // 0x80048970: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004898C;
    }
    // 0x80048970: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80048974: bltz        $s3, L_800489E0
    if (SIGNED(ctx->r19) < 0) {
        // 0x80048978: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_800489E0;
    }
    // 0x80048978: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8004897C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80048980: lhu         $v1, 0x6DFA($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X6DFA);
    // 0x80048984: j           L_800489B0
    // 0x80048988: addu        $s1, $s3, $zero
    ctx->r17 = ADD32(ctx->r19, 0);
        goto L_800489B0;
    // 0x80048988: addu        $s1, $s3, $zero
    ctx->r17 = ADD32(ctx->r19, 0);
L_8004898C:
    // 0x8004898C: addiu       $v0, $v0, 0x6DC0
    ctx->r2 = ADD32(ctx->r2, 0X6DC0);
    // 0x80048990: lhu         $a0, 0x38($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X38);
    // 0x80048994: slt         $v1, $s4, $a0
    ctx->r3 = SIGNED(ctx->r20) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80048998: bne         $v1, $zero, L_800489C4
    if (ctx->r3 != 0) {
        // 0x8004899C: nop
    
            goto L_800489C4;
    }
    // 0x8004899C: nop

    // 0x800489A0: bltz        $s3, L_800489E0
    if (SIGNED(ctx->r19) < 0) {
        // 0x800489A4: addiu       $s2, $a0, -0x1
        ctx->r18 = ADD32(ctx->r4, -0X1);
            goto L_800489E0;
    }
    // 0x800489A4: addiu       $s2, $a0, -0x1
    ctx->r18 = ADD32(ctx->r4, -0X1);
    // 0x800489A8: lhu         $v1, 0x3A($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X3A);
    // 0x800489AC: addu        $s1, $s3, $zero
    ctx->r17 = ADD32(ctx->r19, 0);
L_800489B0:
    // 0x800489B0: slt         $v0, $s3, $v1
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800489B4: beql        $v0, $zero, L_80048A08
    if (ctx->r2 == 0) {
        // 0x800489B8: addiu       $s1, $v1, -0x1
        ctx->r17 = ADD32(ctx->r3, -0X1);
            goto L_80048A08;
    }
    goto skip_0;
    // 0x800489B8: addiu       $s1, $v1, -0x1
    ctx->r17 = ADD32(ctx->r3, -0X1);
    skip_0:
    // 0x800489BC: j           L_80048A0C
    // 0x800489C0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
        goto L_80048A0C;
    // 0x800489C0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
L_800489C4:
    // 0x800489C4: bgez        $s3, L_800489E8
    if (SIGNED(ctx->r19) >= 0) {
        // 0x800489C8: nop
    
            goto L_800489E8;
    }
    // 0x800489C8: nop

    // 0x800489CC: bltz        $s4, L_800489E0
    if (SIGNED(ctx->r20) < 0) {
        // 0x800489D0: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_800489E0;
    }
    // 0x800489D0: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800489D4: bne         $v1, $zero, L_800489E0
    if (ctx->r3 != 0) {
        // 0x800489D8: addu        $s2, $s4, $zero
        ctx->r18 = ADD32(ctx->r20, 0);
            goto L_800489E0;
    }
    // 0x800489D8: addu        $s2, $s4, $zero
    ctx->r18 = ADD32(ctx->r20, 0);
    // 0x800489DC: addiu       $s2, $a0, -0x1
    ctx->r18 = ADD32(ctx->r4, -0X1);
L_800489E0:
    // 0x800489E0: j           L_80048A08
    // 0x800489E4: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
        goto L_80048A08;
    // 0x800489E4: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_800489E8:
    // 0x800489E8: bltz        $s4, L_800489FC
    if (SIGNED(ctx->r20) < 0) {
        // 0x800489EC: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_800489FC;
    }
    // 0x800489EC: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800489F0: bne         $v1, $zero, L_800489FC
    if (ctx->r3 != 0) {
        // 0x800489F4: addu        $s2, $s4, $zero
        ctx->r18 = ADD32(ctx->r20, 0);
            goto L_800489FC;
    }
    // 0x800489F4: addu        $s2, $s4, $zero
    ctx->r18 = ADD32(ctx->r20, 0);
    // 0x800489F8: addiu       $s2, $a0, -0x1
    ctx->r18 = ADD32(ctx->r4, -0X1);
L_800489FC:
    // 0x800489FC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80048A00: lhu         $v0, 0x6DFA($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6DFA);
    // 0x80048A04: addiu       $s1, $v0, -0x1
    ctx->r17 = ADD32(ctx->r2, -0X1);
L_80048A08:
    // 0x80048A08: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
L_80048A0C:
    // 0x80048A0C: addiu       $v1, $v1, 0x6DC0
    ctx->r3 = ADD32(ctx->r3, 0X6DC0);
    // 0x80048A10: lhu         $v0, 0x38($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X38);
    // 0x80048A14: mult        $s1, $v0
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80048A18: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x80048A1C: mflo        $t0
    ctx->r8 = lo;
    // 0x80048A20: addu        $v0, $s2, $t0
    ctx->r2 = ADD32(ctx->r18, ctx->r8);
    // 0x80048A24: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80048A28: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80048A2C: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80048A30: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x80048A34: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80048A38: beq         $v1, $a1, L_80048B58
    if (ctx->r3 == ctx->r5) {
        // 0x80048A3C: andi        $v0, $v0, 0x8000
        ctx->r2 = ctx->r2 & 0X8000;
            goto L_80048B58;
    }
    // 0x80048A3C: andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // 0x80048A40: beq         $v0, $zero, L_80048B58
    if (ctx->r2 == 0) {
        // 0x80048A44: andi        $v1, $v1, 0x7FFF
        ctx->r3 = ctx->r3 & 0X7FFF;
            goto L_80048B58;
    }
    // 0x80048A44: andi        $v1, $v1, 0x7FFF
    ctx->r3 = ctx->r3 & 0X7FFF;
    // 0x80048A48: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80048A4C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80048A50: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80048A54: lw          $v1, 0x6FCC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X6FCC);
    // 0x80048A58: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80048A5C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80048A60: lw          $s0, 0x8($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X8);
    // 0x80048A64: lhu         $a0, 0x6($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X6);
    // 0x80048A68: beq         $a0, $a1, L_80048AC4
    if (ctx->r4 == ctx->r5) {
        // 0x80048A6C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80048AC4;
    }
    // 0x80048A6C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80048A70: lw          $a2, 0x7A5C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X7A5C);
    // 0x80048A74: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x80048A78: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
L_80048A7C:
    // 0x80048A7C: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80048A80: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80048A84: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80048A88: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80048A8C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80048A90: addu        $a1, $a2, $v1
    ctx->r5 = ADD32(ctx->r6, ctx->r3);
    // 0x80048A94: lh          $v0, 0x18($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X18);
    // 0x80048A98: bne         $v0, $s4, L_80048AAC
    if (ctx->r2 != ctx->r20) {
        // 0x80048A9C: nop
    
            goto L_80048AAC;
    }
    // 0x80048A9C: nop

    // 0x80048AA0: lh          $v0, 0x1A($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X1A);
    // 0x80048AA4: beq         $v0, $s3, L_80048ABC
    if (ctx->r2 == ctx->r19) {
        // 0x80048AA8: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_80048ABC;
    }
    // 0x80048AA8: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80048AAC:
    // 0x80048AAC: lhu         $a0, 0x6($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X6);
    // 0x80048AB0: bne         $a0, $a3, L_80048A7C
    if (ctx->r4 != ctx->r7) {
        // 0x80048AB4: andi        $v0, $a0, 0xFFFF
        ctx->r2 = ctx->r4 & 0XFFFF;
            goto L_80048A7C;
    }
    // 0x80048AB4: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x80048AB8: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80048ABC:
    // 0x80048ABC: bne         $a0, $v0, L_80048B8C
    if (ctx->r4 != ctx->r2) {
        // 0x80048AC0: addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
            goto L_80048B8C;
    }
    // 0x80048AC0: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
L_80048AC4:
    // 0x80048AC4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80048AC8: jal         0x80048BAC
    // 0x80048ACC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80048BAC(rdram, ctx);
        goto after_0;
    // 0x80048ACC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80048AD0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80048AD4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80048AD8: jal         0x80048508
    // 0x80048ADC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80048508(rdram, ctx);
        goto after_1;
    // 0x80048ADC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // 0x80048AE0: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80048AE4: beq         $a1, $zero, L_80048B88
    if (ctx->r5 == 0) {
        // 0x80048AE8: ori         $v1, $zero, 0xFFFF
        ctx->r3 = 0 | 0XFFFF;
            goto L_80048B88;
    }
    // 0x80048AE8: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x80048AEC: lhu         $v0, 0x14($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X14);
    // 0x80048AF0: sh          $s4, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r20;
    // 0x80048AF4: sh          $s3, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r19;
    // 0x80048AF8: ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    // 0x80048AFC: sh          $v0, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r2;
    // 0x80048B00: lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6);
    // 0x80048B04: sh          $v0, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r2;
    // 0x80048B08: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80048B0C: beq         $v0, $v1, L_80048B3C
    if (ctx->r2 == ctx->r3) {
        // 0x80048B10: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80048B3C;
    }
    // 0x80048B10: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80048B14: lhu         $v1, 0x6($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X6);
    // 0x80048B18: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80048B1C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80048B20: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80048B24: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80048B28: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80048B2C: lw          $v1, 0x7A5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X7A5C);
    // 0x80048B30: lhu         $a0, 0x16($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X16);
    // 0x80048B34: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80048B38: sh          $a0, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r4;
L_80048B3C:
    // 0x80048B3C: lhu         $v0, 0x16($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X16);
    // 0x80048B40: lhu         $v1, 0x16($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X16);
    // 0x80048B44: sh          $v0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r2;
    // 0x80048B48: sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
    // 0x80048B4C: sh          $v1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r3;
    // 0x80048B50: j           L_80048B8C
    // 0x80048B54: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
        goto L_80048B8C;
    // 0x80048B54: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
L_80048B58:
    // 0x80048B58: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80048B5C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80048B60: jal         0x80048508
    // 0x80048B64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80048508(rdram, ctx);
        goto after_2;
    // 0x80048B64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80048B68: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80048B6C: beq         $s0, $zero, L_80048B8C
    if (ctx->r16 == 0) {
        // 0x80048B70: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80048B8C;
    }
    // 0x80048B70: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80048B74: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80048B78: jal         0x80048BAC
    // 0x80048B7C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80048BAC(rdram, ctx);
        goto after_3;
    // 0x80048B7C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80048B80: j           L_8004896C
    // 0x80048B84: nop

        goto L_8004896C;
    // 0x80048B84: nop

L_80048B88:
    // 0x80048B88: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80048B8C:
    // 0x80048B8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80048B90: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80048B94: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80048B98: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80048B9C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80048BA0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80048BA4: jr          $ra
    // 0x80048BA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80048BA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80048BAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048BAC: mtc1        $a1, $f2
    ctx->f2.u32l = ctx->r5;
    // 0x80048BB0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80048BB4: lwc1        $f0, -0x57F4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X57F4);
    // 0x80048BB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80048BBC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80048BC0: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80048BC4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80048BC8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80048BCC: nop

    // 0x80048BD0: bc1f        L_80048C00
    if (!c1cs) {
        // 0x80048BD4: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_80048C00;
    }
    // 0x80048BD4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80048BD8: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x80048BDC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80048BE0: beq         $v1, $v0, L_800492F0
    if (ctx->r3 == ctx->r2) {
        // 0x80048BE4: nop
    
            goto L_800492F0;
    }
    // 0x80048BE4: nop

    // 0x80048BE8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80048BEC: lwc1        $f0, -0x57F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X57F0);
    // 0x80048BF0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80048BF4: nop

    // 0x80048BF8: bc1t        L_800492F0
    if (c1cs) {
        // 0x80048BFC: nop
    
            goto L_800492F0;
    }
    // 0x80048BFC: nop

L_80048C00:
    // 0x80048C00: lhu         $t0, 0x1E($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X1E);
    // 0x80048C04: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // 0x80048C08: beq         $t0, $a2, L_80048CF4
    if (ctx->r8 == ctx->r6) {
        // 0x80048C0C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80048CF4;
    }
    // 0x80048C0C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80048C10: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
    // 0x80048C14: beq         $v0, $a2, L_80048C44
    if (ctx->r2 == ctx->r6) {
        // 0x80048C18: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_80048C44;
    }
    // 0x80048C18: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80048C1C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80048C20: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80048C24: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80048C28: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80048C2C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80048C30: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80048C34: lw          $v1, 0x7A5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X7A5C);
    // 0x80048C38: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    // 0x80048C3C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80048C40: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
L_80048C44:
    // 0x80048C44: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80048C48: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x80048C4C: lw          $a1, 0x7A5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X7A5C);
    // 0x80048C50: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80048C54: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80048C58: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80048C5C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80048C60: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80048C64: lhu         $v1, 0x2($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X2);
    // 0x80048C68: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80048C6C: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // 0x80048C70: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x80048C74: sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // 0x80048C78: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80048C7C: beq         $v0, $a2, L_80048CA8
    if (ctx->r2 == ctx->r6) {
        // 0x80048C80: nop
    
            goto L_80048CA8;
    }
    // 0x80048C80: nop

    // 0x80048C84: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
    // 0x80048C88: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80048C8C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80048C90: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80048C94: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80048C98: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80048C9C: lhu         $v0, 0x16($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X16);
    // 0x80048CA0: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80048CA4: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_80048CA8:
    // 0x80048CA8: lw          $v1, 0x7A5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X7A5C);
    // 0x80048CAC: lhu         $v0, 0x16($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X16);
    // 0x80048CB0: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // 0x80048CB4: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
    // 0x80048CB8: lhu         $v0, 0x14($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X14);
    // 0x80048CBC: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x80048CC0: beq         $v0, $zero, L_80048FF8
    if (ctx->r2 == 0) {
        // 0x80048CC4: nop
    
            goto L_80048FF8;
    }
    // 0x80048CC4: nop

    // 0x80048CC8: lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X8);
    // 0x80048CCC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80048CD0: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x80048CD4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80048CD8: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80048CDC: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80048CE0: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80048CE4: jal         0x80048BAC
    // 0x80048CE8: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    func_80048BAC(rdram, ctx);
        goto after_0;
    // 0x80048CE8: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    after_0:
    // 0x80048CEC: j           L_80048FF8
    // 0x80048CF0: nop

        goto L_80048FF8;
    // 0x80048CF0: nop

L_80048CF4:
    // 0x80048CF4: addiu       $t3, $v0, 0x6DC0
    ctx->r11 = ADD32(ctx->r2, 0X6DC0);
    // 0x80048CF8: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80048CFC: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80048D00: lhu         $v1, 0x2($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X2);
    // 0x80048D04: lh          $a2, 0x18($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X18);
    // 0x80048D08: lh          $a1, 0x1A($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X1A);
    // 0x80048D0C: lhu         $a0, 0x38($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X38);
    // 0x80048D10: lw          $a3, 0x7A5C($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X7A5C);
    // 0x80048D14: lhu         $t1, 0x6FC0($t4)
    ctx->r9 = MEM_HU(ctx->r12, 0X6FC0);
    // 0x80048D18: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80048D1C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80048D20: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80048D24: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80048D28: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80048D2C: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x80048D30: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80048D34: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x80048D38: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x80048D3C: mult        $a1, $a0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80048D40: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80048D44: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80048D48: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80048D4C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80048D50: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80048D54: lhu         $v1, 0x2($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X2);
    // 0x80048D58: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80048D5C: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // 0x80048D60: lhu         $v0, 0x2($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X2);
    // 0x80048D64: mflo        $t5
    ctx->r13 = lo;
    // 0x80048D68: sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // 0x80048D6C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80048D70: beq         $v0, $t0, L_80048D9C
    if (ctx->r2 == ctx->r8) {
        // 0x80048D74: addu        $s0, $a2, $t5
        ctx->r16 = ADD32(ctx->r6, ctx->r13);
            goto L_80048D9C;
    }
    // 0x80048D74: addu        $s0, $a2, $t5
    ctx->r16 = ADD32(ctx->r6, ctx->r13);
    // 0x80048D78: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
    // 0x80048D7C: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80048D80: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80048D84: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80048D88: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80048D8C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80048D90: lhu         $v0, 0x16($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X16);
    // 0x80048D94: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80048D98: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_80048D9C:
    // 0x80048D9C: lw          $v1, 0x7A5C($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X7A5C);
    // 0x80048DA0: lhu         $v0, 0x16($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X16);
    // 0x80048DA4: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // 0x80048DA8: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
    // 0x80048DAC: lhu         $v0, 0x14($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X14);
    // 0x80048DB0: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x80048DB4: beql        $v0, $zero, L_80048E08
    if (ctx->r2 == 0) {
        // 0x80048DB8: andi        $v1, $t1, 0xFFFF
        ctx->r3 = ctx->r9 & 0XFFFF;
            goto L_80048E08;
    }
    goto skip_0;
    // 0x80048DB8: andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
    skip_0:
    // 0x80048DBC: lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X8);
    // 0x80048DC0: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x80048DC4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80048DC8: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80048DCC: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80048DD0: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80048DD4: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    // 0x80048DD8: lh          $v1, 0x1A($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X1A);
    // 0x80048DDC: lhu         $v0, 0x38($t3)
    ctx->r2 = MEM_HU(ctx->r11, 0X38);
    // 0x80048DE0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80048DE4: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80048DE8: lhu         $v0, 0x1E($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1E);
    // 0x80048DEC: lh          $v1, 0x18($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X18);
    // 0x80048DF0: sh          $v0, 0x1E($s1)
    MEM_H(0X1E, ctx->r17) = ctx->r2;
    // 0x80048DF4: mflo        $t5
    ctx->r13 = lo;
    // 0x80048DF8: jal         0x80048BAC
    // 0x80048DFC: addu        $s0, $v1, $t5
    ctx->r16 = ADD32(ctx->r3, ctx->r13);
    func_80048BAC(rdram, ctx);
        goto after_1;
    // 0x80048DFC: addu        $s0, $v1, $t5
    ctx->r16 = ADD32(ctx->r3, ctx->r13);
    after_1:
    // 0x80048E00: j           L_80048F18
    // 0x80048E04: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
        goto L_80048F18;
    // 0x80048E04: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
L_80048E08:
    // 0x80048E08: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80048E0C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80048E10: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80048E14: lw          $a1, 0x6FCC($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X6FCC);
    // 0x80048E18: sll         $a2, $v0, 2
    ctx->r6 = S32(ctx->r2 << 2);
    // 0x80048E1C: sh          $t0, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r8;
    // 0x80048E20: sh          $t0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r8;
    // 0x80048E24: sh          $t0, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r8;
    // 0x80048E28: addu        $v1, $a2, $a1
    ctx->r3 = ADD32(ctx->r6, ctx->r5);
    // 0x80048E2C: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
    // 0x80048E30: beq         $a0, $t0, L_80048E4C
    if (ctx->r4 == ctx->r8) {
        // 0x80048E34: sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4 << 1);
            goto L_80048E4C;
    }
    // 0x80048E34: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80048E38: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80048E3C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80048E40: lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X0);
    // 0x80048E44: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80048E48: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
L_80048E4C:
    // 0x80048E4C: lw          $a1, 0x6FCC($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X6FCC);
    // 0x80048E50: addu        $a0, $a2, $a1
    ctx->r4 = ADD32(ctx->r6, ctx->r5);
    // 0x80048E54: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x80048E58: beq         $v1, $t0, L_80048E78
    if (ctx->r3 == ctx->r8) {
        // 0x80048E5C: sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3 << 1);
            goto L_80048E78;
    }
    // 0x80048E5C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80048E60: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80048E64: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80048E68: lhu         $v1, 0x2($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X2);
    // 0x80048E6C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80048E70: j           L_80048E80
    // 0x80048E74: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
        goto L_80048E80;
    // 0x80048E74: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
L_80048E78:
    // 0x80048E78: lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2);
    // 0x80048E7C: sh          $v0, 0x6FC0($t4)
    MEM_H(0X6FC0, ctx->r12) = ctx->r2;
L_80048E80:
    // 0x80048E80: andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
    // 0x80048E84: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80048E88: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80048E8C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80048E90: sll         $a3, $v0, 2
    ctx->r7 = S32(ctx->r2 << 2);
    // 0x80048E94: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80048E98: addiu       $a2, $v0, 0x6DC0
    ctx->r6 = ADD32(ctx->r2, 0X6DC0);
    // 0x80048E9C: sll         $a0, $s0, 1
    ctx->r4 = S32(ctx->r16 << 1);
    // 0x80048EA0: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x80048EA4: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
    // 0x80048EA8: lw          $a1, 0x6FCC($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X6FCC);
    // 0x80048EAC: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80048EB0: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80048EB4: addu        $v1, $a3, $a1
    ctx->r3 = ADD32(ctx->r7, ctx->r5);
    // 0x80048EB8: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
    // 0x80048EBC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80048EC0: beq         $v0, $t0, L_80048EE8
    if (ctx->r2 == ctx->r8) {
        // 0x80048EC4: nop
    
            goto L_80048EE8;
    }
    // 0x80048EC4: nop

    // 0x80048EC8: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
    // 0x80048ECC: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80048ED0: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x80048ED4: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80048ED8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80048EDC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80048EE0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80048EE4: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
L_80048EE8:
    // 0x80048EE8: lw          $v0, 0x6FCC($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X6FCC);
    // 0x80048EEC: addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // 0x80048EF0: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x80048EF4: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x80048EF8: sh          $s0, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r16;
    // 0x80048EFC: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x80048F00: addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // 0x80048F04: ori         $a0, $t1, 0x8000
    ctx->r4 = ctx->r9 | 0X8000;
    // 0x80048F08: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x80048F0C: sw          $s1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r17;
    // 0x80048F10: sh          $t1, 0x1E($s1)
    MEM_H(0X1E, ctx->r17) = ctx->r9;
    // 0x80048F14: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
L_80048F18:
    // 0x80048F18: lw          $v0, 0x6DC0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X6DC0);
    // 0x80048F1C: sll         $a2, $s0, 1
    ctx->r6 = S32(ctx->r16 << 1);
    // 0x80048F20: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80048F24: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x80048F28: addiu       $a1, $a3, 0x6DC0
    ctx->r5 = ADD32(ctx->r7, 0X6DC0);
    // 0x80048F2C: andi        $v1, $a0, 0x1FFF
    ctx->r3 = ctx->r4 & 0X1FFF;
    // 0x80048F30: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80048F34: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80048F38: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80048F3C: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x80048F40: andi        $a0, $a0, 0x8000
    ctx->r4 = ctx->r4 & 0X8000;
    // 0x80048F44: beq         $a0, $zero, L_80048F58
    if (ctx->r4 == 0) {
        // 0x80048F48: addu        $v1, $v1, $v0
        ctx->r3 = ADD32(ctx->r3, ctx->r2);
            goto L_80048F58;
    }
    // 0x80048F48: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80048F4C: lhu         $v0, 0x14($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X14);
    // 0x80048F50: ori         $v0, $v0, 0x4
    ctx->r2 = ctx->r2 | 0X4;
    // 0x80048F54: sh          $v0, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r2;
L_80048F58:
    // 0x80048F58: lw          $v0, 0x6DC0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X6DC0);
    // 0x80048F5C: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80048F60: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80048F64: andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // 0x80048F68: beq         $v0, $zero, L_80048F7C
    if (ctx->r2 == 0) {
        // 0x80048F6C: nop
    
            goto L_80048F7C;
    }
    // 0x80048F6C: nop

    // 0x80048F70: lhu         $v0, 0x14($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X14);
    // 0x80048F74: ori         $v0, $v0, 0x8
    ctx->r2 = ctx->r2 | 0X8;
    // 0x80048F78: sh          $v0, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r2;
L_80048F7C:
    // 0x80048F7C: lbu         $v0, 0x2($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2);
    // 0x80048F80: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x80048F84: beq         $v0, $zero, L_80048F98
    if (ctx->r2 == 0) {
        // 0x80048F88: nop
    
            goto L_80048F98;
    }
    // 0x80048F88: nop

    // 0x80048F8C: lhu         $v0, 0x14($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X14);
    // 0x80048F90: ori         $v0, $v0, 0x40
    ctx->r2 = ctx->r2 | 0X40;
    // 0x80048F94: sh          $v0, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r2;
L_80048F98:
    // 0x80048F98: lbu         $v0, 0x2($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2);
    // 0x80048F9C: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80048FA0: beq         $v0, $zero, L_80048FB8
    if (ctx->r2 == 0) {
        // 0x80048FA4: addiu       $v0, $v1, 0x5
        ctx->r2 = ADD32(ctx->r3, 0X5);
            goto L_80048FB8;
    }
    // 0x80048FA4: addiu       $v0, $v1, 0x5
    ctx->r2 = ADD32(ctx->r3, 0X5);
    // 0x80048FA8: lhu         $v0, 0x14($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X14);
    // 0x80048FAC: ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // 0x80048FB0: sh          $v0, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r2;
    // 0x80048FB4: addiu       $v0, $v1, 0x5
    ctx->r2 = ADD32(ctx->r3, 0X5);
L_80048FB8:
    // 0x80048FB8: sw          $v0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->r2;
    // 0x80048FBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80048FC0: sb          $zero, 0x34($s1)
    MEM_B(0X34, ctx->r17) = 0;
    // 0x80048FC4: sb          $zero, 0x33($s1)
    MEM_B(0X33, ctx->r17) = 0;
    // 0x80048FC8: sb          $zero, 0x32($s1)
    MEM_B(0X32, ctx->r17) = 0;
    // 0x80048FCC: sb          $zero, 0x31($s1)
    MEM_B(0X31, ctx->r17) = 0;
    // 0x80048FD0: sb          $zero, 0x30($s1)
    MEM_B(0X30, ctx->r17) = 0;
    // 0x80048FD4: sh          $zero, 0x3E($s1)
    MEM_H(0X3E, ctx->r17) = 0;
    // 0x80048FD8: sh          $zero, 0x3C($s1)
    MEM_H(0X3C, ctx->r17) = 0;
    // 0x80048FDC: sh          $zero, 0x3A($s1)
    MEM_H(0X3A, ctx->r17) = 0;
    // 0x80048FE0: sh          $zero, 0x38($s1)
    MEM_H(0X38, ctx->r17) = 0;
    // 0x80048FE4: sh          $zero, 0x36($s1)
    MEM_H(0X36, ctx->r17) = 0;
    // 0x80048FE8: sb          $v0, 0x57($s1)
    MEM_B(0X57, ctx->r17) = ctx->r2;
    // 0x80048FEC: sh          $zero, 0x4C($s1)
    MEM_H(0X4C, ctx->r17) = 0;
    // 0x80048FF0: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80048FF4: sh          $v0, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r2;
L_80048FF8:
    // 0x80048FF8: lhu         $v0, 0x1C($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X1C);
    // 0x80048FFC: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x80049000: beq         $v0, $t0, L_800492F0
    if (ctx->r2 == ctx->r8) {
        // 0x80049004: sll         $a1, $v0, 1
        ctx->r5 = S32(ctx->r2 << 1);
            goto L_800492F0;
    }
    // 0x80049004: sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2 << 1);
    // 0x80049008: addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // 0x8004900C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80049010: addiu       $t2, $v0, 0x6DC0
    ctx->r10 = ADD32(ctx->r2, 0X6DC0);
    // 0x80049014: andi        $v0, $t1, 0xFFFF
    ctx->r2 = ctx->r9 & 0XFFFF;
    // 0x80049018: lw          $v1, 0xC($t2)
    ctx->r3 = MEM_W(ctx->r10, 0XC);
    // 0x8004901C: sll         $a3, $v0, 1
    ctx->r7 = S32(ctx->r2 << 1);
    // 0x80049020: addu        $a2, $a3, $v1
    ctx->r6 = ADD32(ctx->r7, ctx->r3);
    // 0x80049024: lhu         $a0, 0x0($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X0);
    // 0x80049028: andi        $v0, $a0, 0x8000
    ctx->r2 = ctx->r4 & 0X8000;
    // 0x8004902C: beq         $v0, $zero, L_800490A4
    if (ctx->r2 == 0) {
        // 0x80049030: ori         $v0, $a0, 0x4000
        ctx->r2 = ctx->r4 | 0X4000;
            goto L_800490A4;
    }
    // 0x80049030: ori         $v0, $a0, 0x4000
    ctx->r2 = ctx->r4 | 0X4000;
    // 0x80049034: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x80049038: lw          $a1, 0xC($t2)
    ctx->r5 = MEM_W(ctx->r10, 0XC);
    // 0x8004903C: addu        $v0, $a3, $a1
    ctx->r2 = ADD32(ctx->r7, ctx->r5);
    // 0x80049040: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x80049044: andi        $v1, $v1, 0x3FFF
    ctx->r3 = ctx->r3 & 0X3FFF;
    // 0x80049048: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8004904C: ori         $v0, $v1, 0x1
    ctx->r2 = ctx->r3 | 0X1;
    // 0x80049050: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80049054: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80049058: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8004905C: beq         $v0, $t0, L_800490A4
    if (ctx->r2 == ctx->r8) {
        // 0x80049060: addu        $t1, $v1, $zero
        ctx->r9 = ADD32(ctx->r3, 0);
            goto L_800490A4;
    }
    // 0x80049060: addu        $t1, $v1, $zero
    ctx->r9 = ADD32(ctx->r3, 0);
    // 0x80049064: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80049068: andi        $v1, $v0, 0x3FFF
    ctx->r3 = ctx->r2 & 0X3FFF;
    // 0x8004906C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80049070: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049074: lw          $v1, 0x7614($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X7614);
    // 0x80049078: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004907C: addu        $a3, $v1, $v0
    ctx->r7 = ADD32(ctx->r3, ctx->r2);
    // 0x80049080: lbu         $v0, 0xA($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0XA);
    // 0x80049084: beq         $v0, $zero, L_800490A8
    if (ctx->r2 == 0) {
        // 0x80049088: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800490A8;
    }
    // 0x80049088: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004908C: lhu         $v0, 0x1C($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X1C);
    // 0x80049090: lhu         $v1, 0x4($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X4);
    // 0x80049094: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80049098: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // 0x8004909C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800490A0: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
L_800490A4:
    // 0x800490A4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800490A8:
    // 0x800490A8: ori         $v1, $t1, 0x1
    ctx->r3 = ctx->r9 | 0X1;
    // 0x800490AC: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x800490B0: lw          $v0, 0x6DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6DCC);
    // 0x800490B4: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800490B8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800490BC: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    // 0x800490C0: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // 0x800490C4: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x800490C8: beq         $v0, $a2, L_80049178
    if (ctx->r2 == ctx->r6) {
        // 0x800490CC: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_80049178;
    }
    // 0x800490CC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800490D0: andi        $v0, $v0, 0x3FFF
    ctx->r2 = ctx->r2 & 0X3FFF;
    // 0x800490D4: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x800490D8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800490DC: lw          $a0, 0x7614($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X7614);
    // 0x800490E0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800490E4: addu        $a3, $a0, $v1
    ctx->r7 = ADD32(ctx->r4, ctx->r3);
    // 0x800490E8: lbu         $v0, 0xA($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0XA);
    // 0x800490EC: beq         $v0, $zero, L_800492F0
    if (ctx->r2 == 0) {
        // 0x800490F0: nop
    
            goto L_800492F0;
    }
    // 0x800490F0: nop

    // 0x800490F4: lhu         $v0, 0x2($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X2);
    // 0x800490F8: beq         $v0, $a2, L_80049114
    if (ctx->r2 == ctx->r6) {
        // 0x800490FC: sll         $v1, $v0, 1
        ctx->r3 = S32(ctx->r2 << 1);
            goto L_80049114;
    }
    // 0x800490FC: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80049100: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80049104: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80049108: lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X0);
    // 0x8004910C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80049110: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_80049114:
    // 0x80049114: lhu         $v1, 0x0($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X0);
    // 0x80049118: lw          $a0, 0x7614($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X7614);
    // 0x8004911C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80049120: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049124: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80049128: lhu         $v1, 0x2($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X2);
    // 0x8004912C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80049130: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // 0x80049134: lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2);
    // 0x80049138: sh          $v0, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r2;
    // 0x8004913C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80049140: beq         $v0, $a2, L_80049160
    if (ctx->r2 == ctx->r6) {
        // 0x80049144: nop
    
            goto L_80049160;
    }
    // 0x80049144: nop

    // 0x80049148: lhu         $v1, 0x2($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X2);
    // 0x8004914C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80049150: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049154: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80049158: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004915C: sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
L_80049160:
    // 0x80049160: lw          $v0, 0x7614($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X7614);
    // 0x80049164: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
    // 0x80049168: sh          $a1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r5;
    // 0x8004916C: lhu         $v0, 0x4($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X4);
    // 0x80049170: j           L_800492F0
    // 0x80049174: sh          $v0, 0x4C($s1)
    MEM_H(0X4C, ctx->r17) = ctx->r2;
        goto L_800492F0;
    // 0x80049174: sh          $v0, 0x4C($s1)
    MEM_H(0X4C, ctx->r17) = ctx->r2;
L_80049178:
    // 0x80049178: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8004917C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80049180: addiu       $t3, $v0, 0x7A20
    ctx->r11 = ADD32(ctx->r2, 0X7A20);
    // 0x80049184: addu        $v0, $s0, $t3
    ctx->r2 = ADD32(ctx->r16, ctx->r11);
L_80049188:
    // 0x80049188: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8004918C: beq         $v0, $zero, L_800491A8
    if (ctx->r2 == 0) {
        // 0x80049190: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_800491A8;
    }
    // 0x80049190: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80049194: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80049198: sltiu       $v0, $s0, 0x20
    ctx->r2 = ctx->r16 < 0X20 ? 1 : 0;
    // 0x8004919C: bne         $v0, $zero, L_80049188
    if (ctx->r2 != 0) {
        // 0x800491A0: addu        $v0, $s0, $t3
        ctx->r2 = ADD32(ctx->r16, ctx->r11);
            goto L_80049188;
    }
    // 0x800491A0: addu        $v0, $s0, $t3
    ctx->r2 = ADD32(ctx->r16, ctx->r11);
    // 0x800491A4: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
L_800491A8:
    // 0x800491A8: lw          $v1, 0x7614($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X7614);
    // 0x800491AC: lhu         $a1, 0x26($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X26);
    // 0x800491B0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800491B4: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    // 0x800491B8: beq         $a0, $v0, L_800492F0
    if (ctx->r4 == ctx->r2) {
        // 0x800491BC: sltiu       $v0, $s0, 0x20
        ctx->r2 = ctx->r16 < 0X20 ? 1 : 0;
            goto L_800492F0;
    }
    // 0x800491BC: sltiu       $v0, $s0, 0x20
    ctx->r2 = ctx->r16 < 0X20 ? 1 : 0;
    // 0x800491C0: beq         $v0, $zero, L_800492F0
    if (ctx->r2 == 0) {
        // 0x800491C4: sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4 << 1);
            goto L_800492F0;
    }
    // 0x800491C4: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x800491C8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800491CC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800491D0: addu        $a3, $v1, $v0
    ctx->r7 = ADD32(ctx->r3, ctx->r2);
    // 0x800491D4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800491D8: addiu       $t2, $v0, 0x6DC0
    ctx->r10 = ADD32(ctx->r2, 0X6DC0);
    // 0x800491DC: ori         $v0, $t1, 0x1
    ctx->r2 = ctx->r9 | 0X1;
    // 0x800491E0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800491E4: lw          $v1, 0xC($t2)
    ctx->r3 = MEM_W(ctx->r10, 0XC);
    // 0x800491E8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800491EC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800491F0: sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
    // 0x800491F4: lhu         $v0, 0x8($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X8);
    // 0x800491F8: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // 0x800491FC: beq         $v0, $a2, L_80049214
    if (ctx->r2 == ctx->r6) {
        // 0x80049200: ori         $v0, $v0, 0x1
        ctx->r2 = ctx->r2 | 0X1;
            goto L_80049214;
    }
    // 0x80049200: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80049204: lw          $v1, 0xC($t2)
    ctx->r3 = MEM_W(ctx->r10, 0XC);
    // 0x80049208: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8004920C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049210: sh          $a2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r6;
L_80049214:
    // 0x80049214: lhu         $v1, 0x2($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X2);
    // 0x80049218: lw          $a0, 0x7614($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X7614);
    // 0x8004921C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80049220: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049224: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80049228: lhu         $v1, 0x0($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X0);
    // 0x8004922C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80049230: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x80049234: lhu         $v1, 0x0($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X0);
    // 0x80049238: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004923C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049240: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80049244: lhu         $v1, 0x2($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X2);
    // 0x80049248: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004924C: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // 0x80049250: lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2);
    // 0x80049254: sh          $v0, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r2;
    // 0x80049258: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8004925C: beq         $v0, $a2, L_80049280
    if (ctx->r2 == ctx->r6) {
        // 0x80049260: addu        $v1, $s0, $t3
        ctx->r3 = ADD32(ctx->r16, ctx->r11);
            goto L_80049280;
    }
    // 0x80049260: addu        $v1, $s0, $t3
    ctx->r3 = ADD32(ctx->r16, ctx->r11);
    // 0x80049264: lhu         $v1, 0x2($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X2);
    // 0x80049268: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004926C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049270: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80049274: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80049278: sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
    // 0x8004927C: addu        $v1, $s0, $t3
    ctx->r3 = ADD32(ctx->r16, ctx->r11);
L_80049280:
    // 0x80049280: lw          $v0, 0x7614($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X7614);
    // 0x80049284: sll         $a2, $s0, 5
    ctx->r6 = S32(ctx->r16 << 5);
    // 0x80049288: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
    // 0x8004928C: sh          $a1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r5;
    // 0x80049290: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80049294: sh          $t1, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r9;
    // 0x80049298: sb          $zero, 0xA($a3)
    MEM_B(0XA, ctx->r7) = 0;
    // 0x8004929C: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x800492A0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800492A4: lw          $a0, -0x76E0($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X76E0);
    // 0x800492A8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800492AC: lw          $a1, 0x7A40($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X7A40);
    // 0x800492B0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800492B4: addiu       $v0, $v0, 0x7620
    ctx->r2 = ADD32(ctx->r2, 0X7620);
    // 0x800492B8: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x800492BC: sw          $a3, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r7;
    // 0x800492C0: lhu         $v0, 0x8($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X8);
    // 0x800492C4: lw          $v1, 0xC($t2)
    ctx->r3 = MEM_W(ctx->r10, 0XC);
    // 0x800492C8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800492CC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800492D0: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800492D4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800492D8: jal         0x80006F78
    // 0x800492DC: sw          $v0, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r2;
    sendServiceMessage(rdram, ctx);
        goto after_2;
    // 0x800492DC: sw          $v0, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r2;
    after_2:
    // 0x800492E0: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800492E4: lw          $v0, -0x2130($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2130);
    // 0x800492E8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800492EC: sw          $v0, -0x2130($v1)
    MEM_W(-0X2130, ctx->r3) = ctx->r2;
L_800492F0:
    // 0x800492F0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800492F4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800492F8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800492FC: jr          $ra
    // 0x80049300: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80049300: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80049304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049304: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80049308: lw          $a3, 0x7A5C($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X7A5C);
    // 0x8004930C: lhu         $a2, 0x172($a3)
    ctx->r6 = MEM_HU(ctx->r7, 0X172);
    // 0x80049310: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x80049314: andi        $a1, $a2, 0xFFFF
    ctx->r5 = ctx->r6 & 0XFFFF;
    // 0x80049318: beq         $a1, $t0, L_800493E0
    if (ctx->r5 == ctx->r8) {
        // 0x8004931C: sll         $v1, $a1, 1
        ctx->r3 = S32(ctx->r5 << 1);
            goto L_800493E0;
    }
    // 0x8004931C: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x80049320: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80049324: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80049328: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x8004932C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80049330: lhu         $v0, 0x2E0($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X2E0);
    // 0x80049334: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80049338: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8004933C: lhu         $a0, 0x2E0($a3)
    ctx->r4 = MEM_HU(ctx->r7, 0X2E0);
    // 0x80049340: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80049344: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80049348: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8004934C: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80049350: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80049354: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80049358: sh          $a2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r6;
    // 0x8004935C: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x80049360: beq         $v0, $t0, L_800493B0
    if (ctx->r2 == ctx->r8) {
        // 0x80049364: addu        $v1, $a3, $zero
        ctx->r3 = ADD32(ctx->r7, 0);
            goto L_800493B0;
    }
    // 0x80049364: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
    // 0x80049368: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x8004936C: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
L_80049370:
    // 0x80049370: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80049374: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80049378: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x8004937C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80049380: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049384: lhu         $a2, 0x2($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X2);
    // 0x80049388: andi        $a1, $a2, 0xFFFF
    ctx->r5 = ctx->r6 & 0XFFFF;
    // 0x8004938C: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x80049390: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80049394: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80049398: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x8004939C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800493A0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800493A4: lhu         $v0, 0x2($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X2);
    // 0x800493A8: bne         $v0, $a0, L_80049370
    if (ctx->r2 != ctx->r4) {
        // 0x800493AC: sll         $v0, $a1, 1
        ctx->r2 = S32(ctx->r5 << 1);
            goto L_80049370;
    }
    // 0x800493AC: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
L_800493B0:
    // 0x800493B0: andi        $v1, $a2, 0xFFFF
    ctx->r3 = ctx->r6 & 0XFFFF;
    // 0x800493B4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800493B8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800493BC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800493C0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800493C4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800493C8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800493CC: lw          $a0, 0x7A5C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7A5C);
    // 0x800493D0: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x800493D4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800493D8: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // 0x800493DC: sh          $a2, 0x2E0($a0)
    MEM_H(0X2E0, ctx->r4) = ctx->r6;
L_800493E0:
    // 0x800493E0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800493E4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800493E8: lw          $a2, 0x7A5C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X7A5C);
    // 0x800493EC: ori         $a3, $zero, 0xFFFF
    ctx->r7 = 0 | 0XFFFF;
    // 0x800493F0: addiu       $v1, $a2, 0x170
    ctx->r3 = ADD32(ctx->r6, 0X170);
L_800493F4:
    // 0x800493F4: addiu       $a1, $v1, -0xB8
    ctx->r5 = ADD32(ctx->r3, -0XB8);
    // 0x800493F8: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x800493FC: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
    // 0x80049400: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80049404: beql        $v0, $a3, L_80049430
    if (ctx->r2 == ctx->r7) {
        // 0x80049408: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_80049430;
    }
    goto skip_0;
    // 0x80049408: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    skip_0:
    // 0x8004940C: lhu         $v1, 0x2($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X2);
    // 0x80049410: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80049414: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049418: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8004941C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80049420: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80049424: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80049428: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x8004942C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
L_80049430:
    // 0x80049430: bgtz        $a0, L_800493F4
    if (SIGNED(ctx->r4) > 0) {
        // 0x80049434: addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
            goto L_800493F4;
    }
    // 0x80049434: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // 0x80049438: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004943C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80049440: lw          $a0, 0x7A5C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X7A5C);
    // 0x80049444: lw          $a3, 0x7614($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X7614);
    // 0x80049448: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8004944C: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    // 0x80049450: lhu         $a2, 0x1A($a3)
    ctx->r6 = MEM_HU(ctx->r7, 0X1A);
    // 0x80049454: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x80049458: andi        $a1, $a2, 0xFFFF
    ctx->r5 = ctx->r6 & 0XFFFF;
    // 0x8004945C: beq         $a1, $t0, L_800494F8
    if (ctx->r5 == ctx->r8) {
        // 0x80049460: sll         $v1, $a1, 1
        ctx->r3 = S32(ctx->r5 << 1);
            goto L_800494F8;
    }
    // 0x80049460: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x80049464: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80049468: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8004946C: lhu         $v0, 0x30($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X30);
    // 0x80049470: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80049474: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80049478: lhu         $a0, 0x30($a3)
    ctx->r4 = MEM_HU(ctx->r7, 0X30);
    // 0x8004947C: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80049480: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80049484: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80049488: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8004948C: sh          $a2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r6;
    // 0x80049490: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x80049494: beq         $v0, $t0, L_800494D4
    if (ctx->r2 == ctx->r8) {
        // 0x80049498: addu        $v1, $a3, $zero
        ctx->r3 = ADD32(ctx->r7, 0);
            goto L_800494D4;
    }
    // 0x80049498: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
    // 0x8004949C: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x800494A0: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
L_800494A4:
    // 0x800494A4: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800494A8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800494AC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800494B0: lhu         $a2, 0x2($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X2);
    // 0x800494B4: andi        $a1, $a2, 0xFFFF
    ctx->r5 = ctx->r6 & 0XFFFF;
    // 0x800494B8: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x800494BC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800494C0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800494C4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800494C8: lhu         $v0, 0x2($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X2);
    // 0x800494CC: bne         $v0, $a0, L_800494A4
    if (ctx->r2 != ctx->r4) {
        // 0x800494D0: sll         $v0, $a1, 1
        ctx->r2 = S32(ctx->r5 << 1);
            goto L_800494A4;
    }
    // 0x800494D0: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
L_800494D4:
    // 0x800494D4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800494D8: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800494DC: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800494E0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800494E4: lw          $a0, 0x7614($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X7614);
    // 0x800494E8: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x800494EC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800494F0: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // 0x800494F4: sh          $a2, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r6;
L_800494F8:
    // 0x800494F8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800494FC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80049500: lw          $a2, 0x7614($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X7614);
    // 0x80049504: ori         $a3, $zero, 0xFFFF
    ctx->r7 = 0 | 0XFFFF;
    // 0x80049508: addiu       $v1, $a2, 0x18
    ctx->r3 = ADD32(ctx->r6, 0X18);
L_8004950C:
    // 0x8004950C: addiu       $a1, $v1, -0xC
    ctx->r5 = ADD32(ctx->r3, -0XC);
    // 0x80049510: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x80049514: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
    // 0x80049518: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8004951C: beql        $v0, $a3, L_80049540
    if (ctx->r2 == ctx->r7) {
        // 0x80049520: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_80049540;
    }
    goto skip_1;
    // 0x80049520: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    skip_1:
    // 0x80049524: lhu         $v1, 0x2($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X2);
    // 0x80049528: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004952C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049530: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80049534: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80049538: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x8004953C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
L_80049540:
    // 0x80049540: bgtz        $a0, L_8004950C
    if (SIGNED(ctx->r4) > 0) {
        // 0x80049544: addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
            goto L_8004950C;
    }
    // 0x80049544: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // 0x80049548: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004954C: lw          $v1, 0x7614($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X7614);
    // 0x80049550: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80049554: jr          $ra
    // 0x80049558: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
    return;
    // 0x80049558: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_8004955C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004955C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80049560: lw          $a0, 0x7A5C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X7A5C);
    // 0x80049564: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80049568: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8004956C: jal         0x80001C98
    // 0x80049570: nop

    rs_free(rdram, ctx);
        goto after_0;
    // 0x80049570: nop

    after_0:
    // 0x80049574: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80049578: lw          $a0, 0x7A54($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X7A54);
    // 0x8004957C: jal         0x80001C98
    // 0x80049580: nop

    rs_free(rdram, ctx);
        goto after_1;
    // 0x80049580: nop

    after_1:
    // 0x80049584: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80049588: lw          $a0, 0x7A4C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X7A4C);
    // 0x8004958C: jal         0x80001C98
    // 0x80049590: nop

    rs_free(rdram, ctx);
        goto after_2;
    // 0x80049590: nop

    after_2:
    // 0x80049594: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80049598: lw          $a0, 0x7A68($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X7A68);
    // 0x8004959C: jal         0x80001C98
    // 0x800495A0: nop

    rs_free(rdram, ctx);
        goto after_3;
    // 0x800495A0: nop

    after_3:
    // 0x800495A4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800495A8: jr          $ra
    // 0x800495AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800495AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800495B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800495B0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800495B4: lw          $a0, 0x7614($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X7614);
    // 0x800495B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800495BC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800495C0: jal         0x80001C98
    // 0x800495C4: nop

    rs_free(rdram, ctx);
        goto after_0;
    // 0x800495C4: nop

    after_0:
    // 0x800495C8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800495CC: lw          $a0, 0x7A40($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X7A40);
    // 0x800495D0: jal         0x800070BC
    // 0x800495D4: nop

    unregisterServiceWorker(rdram, ctx);
        goto after_1;
    // 0x800495D4: nop

    after_1:
    // 0x800495D8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800495DC: lw          $a0, -0x76E0($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X76E0);
    // 0x800495E0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800495E4: lw          $a1, 0x7A48($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X7A48);
    // 0x800495E8: jal         0x80004C70
    // 0x800495EC: nop

    teardownAssetDma(rdram, ctx);
        goto after_2;
    // 0x800495EC: nop

    after_2:
    // 0x800495F0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800495F4: jr          $ra
    // 0x800495F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800495F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void hudDisplayUpdateWorker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800495FC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80049600: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80049604: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80049608: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8004960C: addiu       $s6, $zero, 0x820
    ctx->r22 = ADD32(0, 0X820);
    // 0x80049610: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80049614: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x80049618: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004961C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80049620: addiu       $s4, $v0, 0x7A20
    ctx->r20 = ADD32(ctx->r2, 0X7A20);
    // 0x80049624: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80049628: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8004962C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80049630: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
L_80049634:
    // 0x80049634: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80049638: jal         0x80006F24
    // 0x8004963C: nop

    recvServiceMessage(rdram, ctx);
        goto after_0;
    // 0x8004963C: nop

    after_0:
    // 0x80049640: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80049644: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80049648: lhu         $a0, 0x4($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X4);
    // 0x8004964C: jal         0x800232F8
    // 0x80049650: nop

    getTextureDataByMaterialId(rdram, ctx);
        goto after_1;
    // 0x80049650: nop

    after_1:
    // 0x80049654: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
    // 0x80049658: lhu         $a0, 0x6($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X6);
    // 0x8004965C: jal         0x8002333C
    // 0x80049660: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    lookupIndexedPointer_8002333C(rdram, ctx);
        goto after_2;
    // 0x80049660: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    after_2:
    // 0x80049664: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80049668: lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X18);
    // 0x8004966C: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x80049670: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    // 0x80049674: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80049678: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8004967C: lw          $a2, 0x7A48($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X7A48);
    // 0x80049680: sll         $a3, $v1, 6
    ctx->r7 = S32(ctx->r3 << 6);
    // 0x80049684: addu        $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
    // 0x80049688: jal         0x80004E70
    // 0x8004968C: sll         $a3, $a3, 5
    ctx->r7 = S32(ctx->r7 << 5);
    setupAssetDma(rdram, ctx);
        goto after_3;
    // 0x8004968C: sll         $a3, $a3, 5
    ctx->r7 = S32(ctx->r7 << 5);
    after_3:
    // 0x80049690: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80049694: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80049698: addu        $v1, $s1, $zero
    ctx->r3 = ADD32(ctx->r17, 0);
L_8004969C:
    // 0x8004969C: lw          $v0, 0x800($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X800);
    // 0x800496A0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800496A4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800496A8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800496AC: slti        $v0, $a1, 0x8
    ctx->r2 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x800496B0: bne         $v0, $zero, L_8004969C
    if (ctx->r2 != 0) {
        // 0x800496B4: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8004969C;
    }
    // 0x800496B4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800496B8: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x800496BC: lhu         $a0, 0x4($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X4);
    // 0x800496C0: jal         0x80023334
    // 0x800496C4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    returnOne_80023334(rdram, ctx);
        goto after_4;
    // 0x800496C4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_4:
    // 0x800496C8: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x800496CC: lhu         $a0, 0x6($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X6);
    // 0x800496D0: jal         0x8002335C
    // 0x800496D4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    returnOne_8002335C(rdram, ctx);
        goto after_5;
    // 0x800496D4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_5:
    // 0x800496D8: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
    // 0x800496DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800496E0: sb          $v0, 0xA($v1)
    MEM_B(0XA, ctx->r3) = ctx->r2;
    // 0x800496E4: lbu         $v0, 0x1C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1C);
    // 0x800496E8: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x800496EC: j           L_80049634
    // 0x800496F0: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
        goto L_80049634;
    // 0x800496F0: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
;}
RECOMP_FUNC void fake_func_800496F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80049700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049700: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80049704: lw          $a0, 0x7A5C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X7A5C);
    // 0x80049708: lhu         $v1, 0x22A($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X22A);
    // 0x8004970C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80049710: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80049714: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049718: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8004971C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80049720: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80049724: lhu         $v1, 0x7A58($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X7A58);
    // 0x80049728: sltiu       $v1, $v1, 0xA
    ctx->r3 = ctx->r3 < 0XA ? 1 : 0;
    // 0x8004972C: beq         $v1, $zero, L_80049804
    if (ctx->r3 == 0) {
        // 0x80049730: addu        $a2, $a0, $v0
        ctx->r6 = ADD32(ctx->r4, ctx->r2);
            goto L_80049804;
    }
    // 0x80049730: addu        $a2, $a0, $v0
    ctx->r6 = ADD32(ctx->r4, ctx->r2);
    // 0x80049734: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80049738: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x8004973C: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x80049740: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80049744: lw          $t1, 0x7A4C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X7A4C);
    // 0x80049748: addu        $t3, $a0, $zero
    ctx->r11 = ADD32(ctx->r4, 0);
L_8004974C:
    // 0x8004974C: lhu         $v0, 0x16($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X16);
    // 0x80049750: beq         $v0, $t4, L_8004980C
    if (ctx->r2 == ctx->r12) {
        // 0x80049754: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8004980C;
    }
    // 0x80049754: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80049758: lhu         $v0, 0x6($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X6);
    // 0x8004975C: beq         $v0, $t2, L_80049770
    if (ctx->r2 == ctx->r10) {
        // 0x80049760: nop
    
            goto L_80049770;
    }
    // 0x80049760: nop

    // 0x80049764: lhu         $v0, 0x8($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X8);
    // 0x80049768: beq         $v0, $t2, L_800497DC
    if (ctx->r2 == ctx->r10) {
        // 0x8004976C: nop
    
            goto L_800497DC;
    }
    // 0x8004976C: nop

L_80049770:
    // 0x80049770: lhu         $v0, 0x14($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X14);
    // 0x80049774: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // 0x80049778: bne         $v0, $zero, L_800497DC
    if (ctx->r2 != 0) {
        // 0x8004977C: nop
    
            goto L_800497DC;
    }
    // 0x8004977C: nop

    // 0x80049780: lhu         $v0, 0xA($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0XA);
    // 0x80049784: beq         $v0, $zero, L_800497DC
    if (ctx->r2 == 0) {
        // 0x80049788: nop
    
            goto L_800497DC;
    }
    // 0x80049788: nop

    // 0x8004978C: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // 0x80049790: addiu       $a3, $a2, 0xA
    ctx->r7 = ADD32(ctx->r6, 0XA);
L_80049794:
    // 0x80049794: slt         $v0, $a1, $a3
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80049798: beq         $v0, $zero, L_800497D0
    if (ctx->r2 == 0) {
        // 0x8004979C: nop
    
            goto L_800497D0;
    }
    // 0x8004979C: nop

    // 0x800497A0: lhu         $a0, 0x7A58($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X7A58);
    // 0x800497A4: lhu         $v1, 0xA($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0XA);
    // 0x800497A8: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800497AC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800497B0: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800497B4: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x800497B8: sh          $zero, 0xA($a1)
    MEM_H(0XA, ctx->r5) = 0;
    // 0x800497BC: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800497C0: lhu         $v0, 0xA($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XA);
    // 0x800497C4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800497C8: bne         $v0, $zero, L_80049794
    if (ctx->r2 != 0) {
        // 0x800497CC: sh          $a0, 0x7A58($t0)
        MEM_H(0X7A58, ctx->r8) = ctx->r4;
            goto L_80049794;
    }
    // 0x800497CC: sh          $a0, 0x7A58($t0)
    MEM_H(0X7A58, ctx->r8) = ctx->r4;
L_800497D0:
    // 0x800497D0: lhu         $v0, 0x14($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X14);
    // 0x800497D4: ori         $v0, $v0, 0x3
    ctx->r2 = ctx->r2 | 0X3;
    // 0x800497D8: sh          $v0, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r2;
L_800497DC:
    // 0x800497DC: lhu         $v0, 0x2($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X2);
    // 0x800497E0: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x800497E4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800497E8: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800497EC: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800497F0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800497F4: lhu         $v0, 0x7A58($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X7A58);
    // 0x800497F8: sltiu       $v0, $v0, 0xA
    ctx->r2 = ctx->r2 < 0XA ? 1 : 0;
    // 0x800497FC: bne         $v0, $zero, L_8004974C
    if (ctx->r2 != 0) {
        // 0x80049800: addu        $a2, $t3, $v1
        ctx->r6 = ADD32(ctx->r11, ctx->r3);
            goto L_8004974C;
    }
    // 0x80049800: addu        $a2, $t3, $v1
    ctx->r6 = ADD32(ctx->r11, ctx->r3);
L_80049804:
    // 0x80049804: jr          $ra
    // 0x80049808: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80049808: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004980C:
    // 0x8004980C: jr          $ra
    // 0x80049810: nop

    return;
    // 0x80049810: nop

;}
RECOMP_FUNC void func_80049814(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049814: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80049818: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8004981C: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x80049820: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80049824: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80049828: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004982C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80049830: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80049834: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80049838: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8004983C: lh          $v1, 0x1A($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X1A);
    // 0x80049840: lhu         $v0, 0x38($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X38);
    // 0x80049844: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80049848: lwc1        $f2, 0x10($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8004984C: lh          $v0, 0x18($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X18);
    // 0x80049850: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80049854: mflo        $t1
    ctx->r9 = lo;
    // 0x80049858: addu        $s2, $v0, $t1
    ctx->r18 = ADD32(ctx->r2, ctx->r9);
    // 0x8004985C: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    // 0x80049860: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049864: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80049868: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004986C: lwc1        $f0, -0x57E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X57E0);
    // 0x80049870: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x80049874: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80049878: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8004987C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80049880: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80049884: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049888: addiu       $s3, $v0, 0x5
    ctx->r19 = ADD32(ctx->r2, 0X5);
    // 0x8004988C: lhu         $v0, 0xA($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0XA);
    // 0x80049890: bne         $v0, $zero, L_800498DC
    if (ctx->r2 != 0) {
        // 0x80049894: div.s       $f20, $f0, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
            goto L_800498DC;
    }
    // 0x80049894: div.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80049898: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8004989C: lhu         $v0, 0x7A58($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X7A58);
    // 0x800498A0: bne         $v0, $zero, L_800498B8
    if (ctx->r2 != 0) {
        // 0x800498A4: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800498B8;
    }
    // 0x800498A4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800498A8: jal         0x80049700
    // 0x800498AC: nop

    func_80049700(rdram, ctx);
        goto after_0;
    // 0x800498AC: nop

    after_0:
    // 0x800498B0: beq         $v0, $zero, L_80049B98
    if (ctx->r2 == 0) {
        // 0x800498B4: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_80049B98;
    }
    // 0x800498B4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
L_800498B8:
    // 0x800498B8: lhu         $a0, 0x7A58($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X7A58);
    // 0x800498BC: lw          $v1, 0x7A4C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A4C);
    // 0x800498C0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800498C4: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800498C8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800498CC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800498D0: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800498D4: sh          $a0, 0x7A58($s1)
    MEM_H(0X7A58, ctx->r17) = ctx->r4;
    // 0x800498D8: sh          $v0, 0xA($s4)
    MEM_H(0XA, ctx->r20) = ctx->r2;
L_800498DC:
    // 0x800498DC: lhu         $v1, 0xA($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0XA);
    // 0x800498E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800498E4: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800498E8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800498EC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800498F0: lw          $v1, 0x7A54($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X7A54);
    // 0x800498F4: lh          $a0, 0x18($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X18);
    // 0x800498F8: blez        $a0, L_80049918
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800498FC: addu        $a1, $v1, $v0
        ctx->r5 = ADD32(ctx->r3, ctx->r2);
            goto L_80049918;
    }
    // 0x800498FC: addu        $a1, $v1, $v0
    ctx->r5 = ADD32(ctx->r3, ctx->r2);
    // 0x80049900: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80049904: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    // 0x80049908: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004990C: lhu         $v0, -0x2($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2);
    // 0x80049910: j           L_8004992C
    // 0x80049914: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
        goto L_8004992C;
    // 0x80049914: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
L_80049918:
    // 0x80049918: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8004991C: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    // 0x80049920: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049924: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80049928: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
L_8004992C:
    // 0x8004992C: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80049930: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80049934: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80049938: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8004993C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049940: addiu       $t0, $v0, 0x5
    ctx->r8 = ADD32(ctx->r2, 0X5);
    // 0x80049944: lhu         $v0, 0x38($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X38);
    // 0x80049948: lh          $v1, 0x18($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X18);
    // 0x8004994C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80049950: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80049954: beq         $v1, $zero, L_80049970
    if (ctx->r3 == 0) {
        // 0x80049958: sll         $v0, $s2, 1
        ctx->r2 = S32(ctx->r18 << 1);
            goto L_80049970;
    }
    // 0x80049958: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    // 0x8004995C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80049960: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049964: lhu         $v0, 0x2($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X2);
    // 0x80049968: j           L_80049980
    // 0x8004996C: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
        goto L_80049980;
    // 0x8004996C: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
L_80049970:
    // 0x80049970: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80049974: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049978: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8004997C: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
L_80049980:
    // 0x80049980: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80049984: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80049988: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8004998C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80049990: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049994: addiu       $a3, $v0, 0x5
    ctx->r7 = ADD32(ctx->r2, 0X5);
    // 0x80049998: lh          $v0, 0x1A($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X1A);
    // 0x8004999C: blezl       $v0, L_800499B8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800499A0: sll         $v0, $s2, 1
        ctx->r2 = S32(ctx->r18 << 1);
            goto L_800499B8;
    }
    goto skip_0;
    // 0x800499A0: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    skip_0:
    // 0x800499A4: lhu         $v0, 0x38($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X38);
    // 0x800499A8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800499AC: subu        $v0, $s2, $v0
    ctx->r2 = SUB32(ctx->r18, ctx->r2);
    // 0x800499B0: j           L_800499BC
    // 0x800499B4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
        goto L_800499BC;
    // 0x800499B4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
L_800499B8:
    // 0x800499B8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_800499BC:
    // 0x800499BC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800499C0: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800499C4: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x800499C8: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x800499CC: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800499D0: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800499D4: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800499D8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800499DC: addiu       $a0, $v0, 0x5
    ctx->r4 = ADD32(ctx->r2, 0X5);
    // 0x800499E0: lhu         $v0, 0x3A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X3A);
    // 0x800499E4: lh          $v1, 0x1A($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X1A);
    // 0x800499E8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800499EC: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800499F0: beql        $v1, $zero, L_80049A0C
    if (ctx->r3 == 0) {
        // 0x800499F4: sll         $v0, $s2, 1
        ctx->r2 = S32(ctx->r18 << 1);
            goto L_80049A0C;
    }
    goto skip_1;
    // 0x800499F4: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    skip_1:
    // 0x800499F8: lhu         $v0, 0x38($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X38);
    // 0x800499FC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80049A00: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x80049A04: j           L_80049A10
    // 0x80049A08: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
        goto L_80049A10;
    // 0x80049A08: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
L_80049A0C:
    // 0x80049A0C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80049A10:
    // 0x80049A10: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049A14: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80049A18: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x80049A1C: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80049A20: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80049A24: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80049A28: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80049A2C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049A30: addiu       $a2, $v0, 0x5
    ctx->r6 = ADD32(ctx->r2, 0X5);
    // 0x80049A34: lb          $v0, 0x3($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X3);
    // 0x80049A38: lb          $v1, 0x1($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X1);
    // 0x80049A3C: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80049A40: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80049A44: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80049A48: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80049A4C: lb          $v0, 0xF($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XF);
    // 0x80049A50: mul.s       $f0, $f8, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80049A54: lb          $v1, 0x5($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X5);
    // 0x80049A58: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80049A5C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80049A60: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80049A64: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80049A68: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80049A6C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80049A70: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80049A74: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80049A78: swc1        $f2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f2.u32l;
    // 0x80049A7C: div.s       $f2, $f20, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80049A80: div.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80049A84: swc1        $f2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f2.u32l;
    // 0x80049A88: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x80049A8C: lb          $v0, 0x3($s3)
    ctx->r2 = MEM_B(ctx->r19, 0X3);
    // 0x80049A90: lb          $v1, 0x1($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X1);
    // 0x80049A94: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80049A98: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80049A9C: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80049AA0: lb          $v0, 0x13($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X13);
    // 0x80049AA4: mul.s       $f0, $f8, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80049AA8: lb          $v1, 0x9($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X9);
    // 0x80049AAC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80049AB0: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80049AB4: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80049AB8: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80049ABC: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80049AC0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80049AC4: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80049AC8: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80049ACC: swc1        $f2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f2.u32l;
    // 0x80049AD0: div.s       $f2, $f20, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80049AD4: div.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80049AD8: swc1        $f2, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f2.u32l;
    // 0x80049ADC: swc1        $f0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f0.u32l;
    // 0x80049AE0: lb          $v0, 0x17($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X17);
    // 0x80049AE4: lb          $v1, 0x15($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X15);
    // 0x80049AE8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80049AEC: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80049AF0: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80049AF4: lb          $v0, 0xF($s3)
    ctx->r2 = MEM_B(ctx->r19, 0XF);
    // 0x80049AF8: mul.s       $f0, $f8, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80049AFC: lb          $v1, 0x5($a2)
    ctx->r3 = MEM_B(ctx->r6, 0X5);
    // 0x80049B00: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80049B04: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80049B08: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80049B0C: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80049B10: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80049B14: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80049B18: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80049B1C: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80049B20: swc1        $f2, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f2.u32l;
    // 0x80049B24: div.s       $f2, $f20, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80049B28: div.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80049B2C: swc1        $f2, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f2.u32l;
    // 0x80049B30: swc1        $f0, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f0.u32l;
    // 0x80049B34: lb          $v0, 0x17($s3)
    ctx->r2 = MEM_B(ctx->r19, 0X17);
    // 0x80049B38: lb          $v1, 0x15($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X15);
    // 0x80049B3C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80049B40: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80049B44: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80049B48: lb          $v0, 0x13($s3)
    ctx->r2 = MEM_B(ctx->r19, 0X13);
    // 0x80049B4C: mul.s       $f0, $f8, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80049B50: lb          $v1, 0x9($a2)
    ctx->r3 = MEM_B(ctx->r6, 0X9);
    // 0x80049B54: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80049B58: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80049B5C: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80049B60: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80049B64: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80049B68: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80049B6C: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80049B70: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80049B74: swc1        $f2, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f2.u32l;
    // 0x80049B78: div.s       $f2, $f20, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80049B7C: div.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80049B80: swc1        $f2, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->f2.u32l;
    // 0x80049B84: swc1        $f0, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f0.u32l;
    // 0x80049B88: lhu         $v0, 0x14($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X14);
    // 0x80049B8C: andi        $v0, $v0, 0xFFFC
    ctx->r2 = ctx->r2 & 0XFFFC;
    // 0x80049B90: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // 0x80049B94: sh          $v0, 0x14($s4)
    MEM_H(0X14, ctx->r20) = ctx->r2;
L_80049B98:
    // 0x80049B98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80049B9C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80049BA0: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80049BA4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80049BA8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80049BAC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80049BB0: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80049BB4: jr          $ra
    // 0x80049BB8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80049BB8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80049BBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049BBC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80049BC0: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80049BC4: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x80049BC8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80049BCC: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80049BD0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80049BD4: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80049BD8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80049BDC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80049BE0: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80049BE4: lh          $v1, 0x1A($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X1A);
    // 0x80049BE8: lhu         $v0, 0x38($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X38);
    // 0x80049BEC: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80049BF0: lwc1        $f2, 0x10($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80049BF4: lh          $v0, 0x18($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X18);
    // 0x80049BF8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80049BFC: mflo        $t1
    ctx->r9 = lo;
    // 0x80049C00: addu        $s3, $v0, $t1
    ctx->r19 = ADD32(ctx->r2, ctx->r9);
    // 0x80049C04: sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19 << 1);
    // 0x80049C08: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049C0C: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80049C10: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80049C14: lwc1        $f0, -0x57DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X57DC);
    // 0x80049C18: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x80049C1C: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80049C20: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80049C24: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80049C28: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80049C2C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049C30: addiu       $s1, $v0, 0x5
    ctx->r17 = ADD32(ctx->r2, 0X5);
    // 0x80049C34: lhu         $v0, 0xC($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0XC);
    // 0x80049C38: bne         $v0, $zero, L_80049C84
    if (ctx->r2 != 0) {
        // 0x80049C3C: div.s       $f20, $f0, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
            goto L_80049C84;
    }
    // 0x80049C3C: div.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80049C40: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80049C44: lhu         $v0, 0x7A58($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X7A58);
    // 0x80049C48: bne         $v0, $zero, L_80049C60
    if (ctx->r2 != 0) {
        // 0x80049C4C: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_80049C60;
    }
    // 0x80049C4C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80049C50: jal         0x80049700
    // 0x80049C54: nop

    func_80049700(rdram, ctx);
        goto after_0;
    // 0x80049C54: nop

    after_0:
    // 0x80049C58: beq         $v0, $zero, L_80049F94
    if (ctx->r2 == 0) {
        // 0x80049C5C: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_80049F94;
    }
    // 0x80049C5C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
L_80049C60:
    // 0x80049C60: lhu         $a0, 0x7A58($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X7A58);
    // 0x80049C64: lw          $v1, 0x7A4C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A4C);
    // 0x80049C68: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80049C6C: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x80049C70: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80049C74: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049C78: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80049C7C: sh          $a0, 0x7A58($s2)
    MEM_H(0X7A58, ctx->r18) = ctx->r4;
    // 0x80049C80: sh          $v0, 0xC($s4)
    MEM_H(0XC, ctx->r20) = ctx->r2;
L_80049C84:
    // 0x80049C84: lhu         $v1, 0xC($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0XC);
    // 0x80049C88: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80049C8C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80049C90: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049C94: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80049C98: lw          $v1, 0x7A54($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X7A54);
    // 0x80049C9C: lh          $a0, 0x18($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X18);
    // 0x80049CA0: blez        $a0, L_80049CC0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80049CA4: addu        $a1, $v1, $v0
        ctx->r5 = ADD32(ctx->r3, ctx->r2);
            goto L_80049CC0;
    }
    // 0x80049CA4: addu        $a1, $v1, $v0
    ctx->r5 = ADD32(ctx->r3, ctx->r2);
    // 0x80049CA8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80049CAC: sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19 << 1);
    // 0x80049CB0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049CB4: lhu         $v0, -0x2($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2);
    // 0x80049CB8: j           L_80049CD4
    // 0x80049CBC: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
        goto L_80049CD4;
    // 0x80049CBC: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
L_80049CC0:
    // 0x80049CC0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80049CC4: sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19 << 1);
    // 0x80049CC8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049CCC: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80049CD0: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
L_80049CD4:
    // 0x80049CD4: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80049CD8: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80049CDC: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80049CE0: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80049CE4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049CE8: addiu       $a3, $v0, 0x5
    ctx->r7 = ADD32(ctx->r2, 0X5);
    // 0x80049CEC: lhu         $v0, 0x38($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X38);
    // 0x80049CF0: lh          $v1, 0x18($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X18);
    // 0x80049CF4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80049CF8: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80049CFC: beq         $v1, $zero, L_80049D18
    if (ctx->r3 == 0) {
        // 0x80049D00: sll         $v0, $s3, 1
        ctx->r2 = S32(ctx->r19 << 1);
            goto L_80049D18;
    }
    // 0x80049D00: sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19 << 1);
    // 0x80049D04: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80049D08: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049D0C: lhu         $v0, 0x2($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X2);
    // 0x80049D10: j           L_80049D28
    // 0x80049D14: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
        goto L_80049D28;
    // 0x80049D14: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
L_80049D18:
    // 0x80049D18: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80049D1C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049D20: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80049D24: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
L_80049D28:
    // 0x80049D28: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80049D2C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80049D30: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80049D34: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80049D38: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049D3C: addiu       $t0, $v0, 0x5
    ctx->r8 = ADD32(ctx->r2, 0X5);
    // 0x80049D40: lh          $v0, 0x1A($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X1A);
    // 0x80049D44: blezl       $v0, L_80049D60
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80049D48: sll         $v0, $s3, 1
        ctx->r2 = S32(ctx->r19 << 1);
            goto L_80049D60;
    }
    goto skip_0;
    // 0x80049D48: sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19 << 1);
    skip_0:
    // 0x80049D4C: lhu         $v0, 0x38($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X38);
    // 0x80049D50: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80049D54: subu        $v0, $s3, $v0
    ctx->r2 = SUB32(ctx->r19, ctx->r2);
    // 0x80049D58: j           L_80049D64
    // 0x80049D5C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
        goto L_80049D64;
    // 0x80049D5C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
L_80049D60:
    // 0x80049D60: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80049D64:
    // 0x80049D64: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049D68: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80049D6C: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x80049D70: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80049D74: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80049D78: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80049D7C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80049D80: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049D84: addiu       $a0, $v0, 0x5
    ctx->r4 = ADD32(ctx->r2, 0X5);
    // 0x80049D88: lhu         $v0, 0x3A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X3A);
    // 0x80049D8C: lh          $v1, 0x1A($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X1A);
    // 0x80049D90: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80049D94: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80049D98: beql        $v1, $zero, L_80049DB4
    if (ctx->r3 == 0) {
        // 0x80049D9C: sll         $v0, $s3, 1
        ctx->r2 = S32(ctx->r19 << 1);
            goto L_80049DB4;
    }
    goto skip_1;
    // 0x80049D9C: sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19 << 1);
    skip_1:
    // 0x80049DA0: lhu         $v0, 0x38($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X38);
    // 0x80049DA4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80049DA8: addu        $v0, $s3, $v0
    ctx->r2 = ADD32(ctx->r19, ctx->r2);
    // 0x80049DAC: j           L_80049DB8
    // 0x80049DB0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
        goto L_80049DB8;
    // 0x80049DB0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
L_80049DB4:
    // 0x80049DB4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80049DB8:
    // 0x80049DB8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049DBC: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80049DC0: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x80049DC4: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80049DC8: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80049DCC: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80049DD0: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80049DD4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049DD8: addiu       $a2, $v0, 0x5
    ctx->r6 = ADD32(ctx->r2, 0X5);
    // 0x80049DDC: lb          $v0, 0x1($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X1);
    // 0x80049DE0: lb          $v1, 0x3($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3);
    // 0x80049DE4: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80049DE8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80049DEC: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80049DF0: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80049DF4: lb          $v0, 0x11($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X11);
    // 0x80049DF8: mul.s       $f0, $f8, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80049DFC: lb          $v1, 0x7($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X7);
    // 0x80049E00: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80049E04: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80049E08: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80049E0C: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80049E10: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80049E14: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80049E18: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80049E1C: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80049E20: swc1        $f2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f2.u32l;
    // 0x80049E24: div.s       $f2, $f20, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80049E28: div.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80049E2C: swc1        $f2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f2.u32l;
    // 0x80049E30: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x80049E34: lb          $v0, 0xD($a3)
    ctx->r2 = MEM_B(ctx->r7, 0XD);
    // 0x80049E38: lb          $v1, 0xB($s1)
    ctx->r3 = MEM_B(ctx->r17, 0XB);
    // 0x80049E3C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80049E40: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80049E44: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80049E48: lb          $v0, 0x5($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X5);
    // 0x80049E4C: mul.s       $f0, $f8, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80049E50: lb          $v1, 0xF($s1)
    ctx->r3 = MEM_B(ctx->r17, 0XF);
    // 0x80049E54: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80049E58: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80049E5C: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80049E60: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80049E64: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80049E68: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80049E6C: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80049E70: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80049E74: swc1        $f2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f2.u32l;
    // 0x80049E78: div.s       $f2, $f20, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80049E7C: div.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80049E80: swc1        $f2, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f2.u32l;
    // 0x80049E84: swc1        $f0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f0.u32l;
    // 0x80049E88: lb          $v0, 0xB($s1)
    ctx->r2 = MEM_B(ctx->r17, 0XB);
    // 0x80049E8C: lb          $v1, 0xD($s1)
    ctx->r3 = MEM_B(ctx->r17, 0XD);
    // 0x80049E90: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80049E94: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80049E98: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80049E9C: lb          $v0, 0x7($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X7);
    // 0x80049EA0: mul.s       $f0, $f8, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80049EA4: lb          $v1, 0x11($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X11);
    // 0x80049EA8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80049EAC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80049EB0: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80049EB4: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80049EB8: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80049EBC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80049EC0: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80049EC4: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80049EC8: swc1        $f2, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f2.u32l;
    // 0x80049ECC: div.s       $f2, $f20, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80049ED0: div.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80049ED4: swc1        $f2, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f2.u32l;
    // 0x80049ED8: swc1        $f0, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f0.u32l;
    // 0x80049EDC: lb          $v0, 0xD($s1)
    ctx->r2 = MEM_B(ctx->r17, 0XD);
    // 0x80049EE0: lb          $v1, 0xB($t0)
    ctx->r3 = MEM_B(ctx->r8, 0XB);
    // 0x80049EE4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80049EE8: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80049EEC: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80049EF0: lb          $v0, 0x9($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X9);
    // 0x80049EF4: mul.s       $f0, $f8, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80049EF8: lb          $v1, 0x13($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X13);
    // 0x80049EFC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80049F00: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80049F04: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80049F08: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80049F0C: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80049F10: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80049F14: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80049F18: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80049F1C: swc1        $f2, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f2.u32l;
    // 0x80049F20: div.s       $f2, $f20, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80049F24: div.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80049F28: swc1        $f2, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->f2.u32l;
    // 0x80049F2C: swc1        $f0, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f0.u32l;
    // 0x80049F30: lb          $v0, 0x15($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X15);
    // 0x80049F34: lb          $v1, 0x17($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X17);
    // 0x80049F38: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80049F3C: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80049F40: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80049F44: lb          $v0, 0x11($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X11);
    // 0x80049F48: mul.s       $f0, $f8, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80049F4C: lb          $v1, 0x7($a2)
    ctx->r3 = MEM_B(ctx->r6, 0X7);
    // 0x80049F50: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80049F54: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80049F58: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80049F5C: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80049F60: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80049F64: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80049F68: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80049F6C: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80049F70: swc1        $f2, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f2.u32l;
    // 0x80049F74: div.s       $f2, $f20, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80049F78: div.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80049F7C: swc1        $f2, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->f2.u32l;
    // 0x80049F80: swc1        $f0, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f0.u32l;
    // 0x80049F84: lhu         $v0, 0x14($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X14);
    // 0x80049F88: andi        $v0, $v0, 0xFFFC
    ctx->r2 = ctx->r2 & 0XFFFC;
    // 0x80049F8C: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80049F90: sh          $v0, 0x14($s4)
    MEM_H(0X14, ctx->r20) = ctx->r2;
L_80049F94:
    // 0x80049F94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80049F98: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80049F9C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80049FA0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80049FA4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80049FA8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80049FAC: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80049FB0: jr          $ra
    // 0x80049FB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80049FB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80049FB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049FB8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80049FBC: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80049FC0: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x80049FC4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80049FC8: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80049FCC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80049FD0: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80049FD4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80049FD8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80049FDC: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80049FE0: lh          $v1, 0x1A($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X1A);
    // 0x80049FE4: lhu         $v0, 0x38($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X38);
    // 0x80049FE8: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80049FEC: lwc1        $f2, 0x10($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80049FF0: lh          $v0, 0x18($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X18);
    // 0x80049FF4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80049FF8: mflo        $t4
    ctx->r12 = lo;
    // 0x80049FFC: addu        $s2, $v0, $t4
    ctx->r18 = ADD32(ctx->r2, ctx->r12);
    // 0x8004A000: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    // 0x8004A004: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004A008: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8004A00C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004A010: lwc1        $f0, -0x57D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X57D8);
    // 0x8004A014: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x8004A018: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x8004A01C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8004A020: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x8004A024: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8004A028: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004A02C: addiu       $s0, $v0, 0x5
    ctx->r16 = ADD32(ctx->r2, 0X5);
    // 0x8004A030: lhu         $v0, 0xE($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0XE);
    // 0x8004A034: bne         $v0, $zero, L_8004A0BC
    if (ctx->r2 != 0) {
        // 0x8004A038: div.s       $f20, $f0, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
            goto L_8004A0BC;
    }
    // 0x8004A038: div.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8004A03C: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8004A040: lhu         $v0, 0x7A58($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X7A58);
    // 0x8004A044: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x8004A048: beq         $v0, $zero, L_8004A060
    if (ctx->r2 == 0) {
        // 0x8004A04C: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_8004A060;
    }
    // 0x8004A04C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004A050: jal         0x80049700
    // 0x8004A054: nop

    func_80049700(rdram, ctx);
        goto after_0;
    // 0x8004A054: nop

    after_0:
    // 0x8004A058: beq         $v0, $zero, L_8004A69C
    if (ctx->r2 == 0) {
        // 0x8004A05C: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_8004A69C;
    }
    // 0x8004A05C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
L_8004A060:
    // 0x8004A060: lhu         $a0, 0x7A58($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X7A58);
    // 0x8004A064: lw          $v1, 0x7A4C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A4C);
    // 0x8004A068: addiu       $a2, $a0, -0x1
    ctx->r6 = ADD32(ctx->r4, -0X1);
    // 0x8004A06C: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x8004A070: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8004A074: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004A078: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8004A07C: addiu       $a1, $a0, -0x2
    ctx->r5 = ADD32(ctx->r4, -0X2);
    // 0x8004A080: sh          $v0, 0xE($s4)
    MEM_H(0XE, ctx->r20) = ctx->r2;
    // 0x8004A084: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x8004A088: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8004A08C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004A090: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8004A094: addiu       $a0, $a0, -0x3
    ctx->r4 = ADD32(ctx->r4, -0X3);
    // 0x8004A098: sh          $v0, 0x10($s4)
    MEM_H(0X10, ctx->r20) = ctx->r2;
    // 0x8004A09C: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8004A0A0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8004A0A4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004A0A8: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8004A0AC: sh          $a2, 0x7A58($s3)
    MEM_H(0X7A58, ctx->r19) = ctx->r6;
    // 0x8004A0B0: sh          $a1, 0x7A58($s3)
    MEM_H(0X7A58, ctx->r19) = ctx->r5;
    // 0x8004A0B4: sh          $a0, 0x7A58($s3)
    MEM_H(0X7A58, ctx->r19) = ctx->r4;
    // 0x8004A0B8: sh          $v0, 0x12($s4)
    MEM_H(0X12, ctx->r20) = ctx->r2;
L_8004A0BC:
    // 0x8004A0BC: lh          $v0, 0x18($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X18);
    // 0x8004A0C0: blez        $v0, L_8004A0DC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004A0C4: sll         $v0, $s2, 1
        ctx->r2 = S32(ctx->r18 << 1);
            goto L_8004A0DC;
    }
    // 0x8004A0C4: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    // 0x8004A0C8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8004A0CC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004A0D0: lhu         $v0, -0x2($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2);
    // 0x8004A0D4: j           L_8004A0EC
    // 0x8004A0D8: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
        goto L_8004A0EC;
    // 0x8004A0D8: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
L_8004A0DC:
    // 0x8004A0DC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8004A0E0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004A0E4: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8004A0E8: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
L_8004A0EC:
    // 0x8004A0EC: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x8004A0F0: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8004A0F4: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x8004A0F8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8004A0FC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004A100: addiu       $t0, $v0, 0x5
    ctx->r8 = ADD32(ctx->r2, 0X5);
    // 0x8004A104: lhu         $v0, 0x38($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X38);
    // 0x8004A108: lh          $v1, 0x18($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X18);
    // 0x8004A10C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8004A110: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004A114: beq         $v1, $zero, L_8004A130
    if (ctx->r3 == 0) {
        // 0x8004A118: sll         $v0, $s2, 1
        ctx->r2 = S32(ctx->r18 << 1);
            goto L_8004A130;
    }
    // 0x8004A118: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    // 0x8004A11C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8004A120: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004A124: lhu         $v0, 0x2($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X2);
    // 0x8004A128: j           L_8004A140
    // 0x8004A12C: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
        goto L_8004A140;
    // 0x8004A12C: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
L_8004A130:
    // 0x8004A130: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8004A134: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004A138: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8004A13C: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
L_8004A140:
    // 0x8004A140: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x8004A144: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8004A148: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x8004A14C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8004A150: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004A154: addiu       $t1, $v0, 0x5
    ctx->r9 = ADD32(ctx->r2, 0X5);
    // 0x8004A158: lh          $v0, 0x1A($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X1A);
    // 0x8004A15C: blezl       $v0, L_8004A178
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004A160: sll         $v0, $s2, 1
        ctx->r2 = S32(ctx->r18 << 1);
            goto L_8004A178;
    }
    goto skip_0;
    // 0x8004A160: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    skip_0:
    // 0x8004A164: lhu         $v0, 0x38($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X38);
    // 0x8004A168: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8004A16C: subu        $v0, $s2, $v0
    ctx->r2 = SUB32(ctx->r18, ctx->r2);
    // 0x8004A170: j           L_8004A17C
    // 0x8004A174: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
        goto L_8004A17C;
    // 0x8004A174: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
L_8004A178:
    // 0x8004A178: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
L_8004A17C:
    // 0x8004A17C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004A180: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8004A184: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x8004A188: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x8004A18C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8004A190: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x8004A194: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8004A198: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004A19C: addiu       $t2, $v0, 0x5
    ctx->r10 = ADD32(ctx->r2, 0X5);
    // 0x8004A1A0: lhu         $v0, 0x3A($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X3A);
    // 0x8004A1A4: lh          $v1, 0x1A($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X1A);
    // 0x8004A1A8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8004A1AC: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004A1B0: beql        $v1, $zero, L_8004A1CC
    if (ctx->r3 == 0) {
        // 0x8004A1B4: sll         $v0, $s2, 1
        ctx->r2 = S32(ctx->r18 << 1);
            goto L_8004A1CC;
    }
    goto skip_1;
    // 0x8004A1B4: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    skip_1:
    // 0x8004A1B8: lhu         $v0, 0x38($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X38);
    // 0x8004A1BC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8004A1C0: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x8004A1C4: j           L_8004A1D0
    // 0x8004A1C8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
        goto L_8004A1D0;
    // 0x8004A1C8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
L_8004A1CC:
    // 0x8004A1CC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
L_8004A1D0:
    // 0x8004A1D0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004A1D4: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8004A1D8: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x8004A1DC: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x8004A1E0: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8004A1E4: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x8004A1E8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8004A1EC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004A1F0: addiu       $t3, $v0, 0x5
    ctx->r11 = ADD32(ctx->r2, 0X5);
    // 0x8004A1F4: lb          $v0, 0x8($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X8);
    // 0x8004A1F8: lb          $v1, 0x6($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X6);
    // 0x8004A1FC: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8004A200: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004A204: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8004A208: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004A20C: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x8004A210: lb          $v1, 0xA($s0)
    ctx->r3 = MEM_B(ctx->r16, 0XA);
    // 0x8004A214: mul.s       $f0, $f8, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8004A218: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004A21C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8004A220: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004A224: lhu         $v1, 0xE($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0XE);
    // 0x8004A228: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8004A22C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8004A230: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004A234: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004A238: lw          $v1, 0x7A54($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X7A54);
    // 0x8004A23C: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8004A240: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004A244: addu        $a3, $v1, $v0
    ctx->r7 = ADD32(ctx->r3, ctx->r2);
    // 0x8004A248: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8004A24C: sqrt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = sqrtf(ctx->f0.fl);
    // 0x8004A250: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8004A254: addiu       $a2, $a3, 0xC
    ctx->r6 = ADD32(ctx->r7, 0XC);
    // 0x8004A258: div.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8004A25C: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
    // 0x8004A260: div.s       $f0, $f20, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8004A264: swc1        $f0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f0.u32l;
    // 0x8004A268: div.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8004A26C: swc1        $f0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f0.u32l;
L_8004A270:
    // 0x8004A270: addu        $a0, $a1, $s0
    ctx->r4 = ADD32(ctx->r5, ctx->r16);
    // 0x8004A274: lb          $v0, 0x4($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X4);
    // 0x8004A278: lb          $v1, 0x6($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X6);
    // 0x8004A27C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004A280: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8004A284: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004A288: lb          $v1, 0x0($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X0);
    // 0x8004A28C: mul.s       $f0, $f8, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8004A290: lb          $v0, 0xA($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XA);
    // 0x8004A294: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8004A298: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x8004A29C: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004A2A0: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8004A2A4: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8004A2A8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8004A2AC: sqrt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = sqrtf(ctx->f0.fl);
    // 0x8004A2B0: div.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8004A2B4: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x8004A2B8: div.s       $f0, $f20, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8004A2BC: swc1        $f0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f0.u32l;
    // 0x8004A2C0: div.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8004A2C4: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
    // 0x8004A2C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8004A2CC: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x8004A2D0: bne         $v0, $zero, L_8004A270
    if (ctx->r2 != 0) {
        // 0x8004A2D4: addiu       $a2, $a2, 0xC
        ctx->r6 = ADD32(ctx->r6, 0XC);
            goto L_8004A270;
    }
    // 0x8004A2D4: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x8004A2D8: lb          $v0, 0x8($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X8);
    // 0x8004A2DC: lb          $v1, 0x6($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X6);
    // 0x8004A2E0: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8004A2E4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004A2E8: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8004A2EC: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004A2F0: lb          $v0, 0x4($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X4);
    // 0x8004A2F4: mul.s       $f0, $f8, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8004A2F8: lb          $v1, 0xE($s0)
    ctx->r3 = MEM_B(ctx->r16, 0XE);
    // 0x8004A2FC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004A300: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8004A304: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004A308: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8004A30C: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8004A310: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8004A314: sqrt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = sqrtf(ctx->f0.fl);
    // 0x8004A318: div.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8004A31C: swc1        $f0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->f0.u32l;
    // 0x8004A320: div.s       $f0, $f20, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8004A324: swc1        $f0, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f0.u32l;
    // 0x8004A328: div.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8004A32C: swc1        $f0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f0.u32l;
    // 0x8004A330: lb          $v0, 0x12($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X12);
    // 0x8004A334: lb          $v1, 0x10($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X10);
    // 0x8004A338: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004A33C: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8004A340: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004A344: lb          $v0, 0xA($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XA);
    // 0x8004A348: lb          $v1, 0x14($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X14);
    // 0x8004A34C: mul.s       $f0, $f8, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8004A350: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004A354: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8004A358: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004A35C: lhu         $v1, 0x10($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X10);
    // 0x8004A360: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8004A364: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8004A368: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004A36C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004A370: lw          $v1, 0x7A54($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X7A54);
    // 0x8004A374: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8004A378: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004A37C: addu        $a3, $v1, $v0
    ctx->r7 = ADD32(ctx->r3, ctx->r2);
    // 0x8004A380: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8004A384: sqrt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = sqrtf(ctx->f0.fl);
    // 0x8004A388: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8004A38C: addiu       $a2, $a3, 0xC
    ctx->r6 = ADD32(ctx->r7, 0XC);
    // 0x8004A390: div.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8004A394: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
    // 0x8004A398: div.s       $f0, $f20, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8004A39C: swc1        $f0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f0.u32l;
    // 0x8004A3A0: div.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8004A3A4: swc1        $f0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f0.u32l;
L_8004A3A8:
    // 0x8004A3A8: addu        $a0, $a1, $s0
    ctx->r4 = ADD32(ctx->r5, ctx->r16);
    // 0x8004A3AC: lb          $v0, 0xE($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XE);
    // 0x8004A3B0: lb          $v1, 0x10($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X10);
    // 0x8004A3B4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004A3B8: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8004A3BC: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004A3C0: lb          $v1, 0xA($a0)
    ctx->r3 = MEM_B(ctx->r4, 0XA);
    // 0x8004A3C4: mul.s       $f0, $f8, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8004A3C8: lb          $v0, 0x14($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X14);
    // 0x8004A3CC: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8004A3D0: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x8004A3D4: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004A3D8: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8004A3DC: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8004A3E0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8004A3E4: sqrt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = sqrtf(ctx->f0.fl);
    // 0x8004A3E8: div.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8004A3EC: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x8004A3F0: div.s       $f0, $f20, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8004A3F4: swc1        $f0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f0.u32l;
    // 0x8004A3F8: div.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8004A3FC: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
    // 0x8004A400: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8004A404: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x8004A408: bne         $v0, $zero, L_8004A3A8
    if (ctx->r2 != 0) {
        // 0x8004A40C: addiu       $a2, $a2, 0xC
        ctx->r6 = ADD32(ctx->r6, 0XC);
            goto L_8004A3A8;
    }
    // 0x8004A40C: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x8004A410: lb          $v0, 0x12($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X12);
    // 0x8004A414: lb          $v1, 0x10($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X10);
    // 0x8004A418: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8004A41C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004A420: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8004A424: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004A428: lb          $v0, 0xE($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XE);
    // 0x8004A42C: mul.s       $f0, $f8, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8004A430: lb          $v1, 0x18($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X18);
    // 0x8004A434: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004A438: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8004A43C: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004A440: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8004A444: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8004A448: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8004A44C: sqrt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = sqrtf(ctx->f0.fl);
    // 0x8004A450: div.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8004A454: swc1        $f0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->f0.u32l;
    // 0x8004A458: div.s       $f0, $f20, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8004A45C: swc1        $f0, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f0.u32l;
    // 0x8004A460: div.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8004A464: swc1        $f0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f0.u32l;
    // 0x8004A468: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x8004A46C: lb          $v1, 0x2($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X2);
    // 0x8004A470: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004A474: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8004A478: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004A47C: lb          $v0, 0x10($t2)
    ctx->r2 = MEM_B(ctx->r10, 0X10);
    // 0x8004A480: mul.s       $f0, $f8, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8004A484: lb          $v1, 0x6($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X6);
    // 0x8004A488: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8004A48C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004A490: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8004A494: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004A498: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8004A49C: lhu         $v1, 0x12($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X12);
    // 0x8004A4A0: lw          $a0, 0x7A54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7A54);
    // 0x8004A4A4: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004A4A8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004A4AC: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8004A4B0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004A4B4: addu        $a3, $a0, $v0
    ctx->r7 = ADD32(ctx->r4, ctx->r2);
    // 0x8004A4B8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8004A4BC: sqrt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = sqrtf(ctx->f0.fl);
    // 0x8004A4C0: div.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8004A4C4: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
    // 0x8004A4C8: div.s       $f0, $f20, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8004A4CC: swc1        $f0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f0.u32l;
    // 0x8004A4D0: div.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8004A4D4: swc1        $f0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f0.u32l;
    // 0x8004A4D8: lb          $v0, 0x2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X2);
    // 0x8004A4DC: lb          $v1, 0x4($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X4);
    // 0x8004A4E0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004A4E4: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8004A4E8: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004A4EC: lb          $v0, 0x12($t2)
    ctx->r2 = MEM_B(ctx->r10, 0X12);
    // 0x8004A4F0: mul.s       $f0, $f8, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8004A4F4: lb          $v1, 0x8($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X8);
    // 0x8004A4F8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004A4FC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8004A500: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004A504: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8004A508: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8004A50C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8004A510: sqrt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = sqrtf(ctx->f0.fl);
    // 0x8004A514: div.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8004A518: swc1        $f0, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f0.u32l;
    // 0x8004A51C: div.s       $f0, $f20, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8004A520: swc1        $f0, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f0.u32l;
    // 0x8004A524: div.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8004A528: swc1        $f0, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f0.u32l;
    // 0x8004A52C: lb          $v0, 0xA($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XA);
    // 0x8004A530: lb          $v1, 0xC($s0)
    ctx->r3 = MEM_B(ctx->r16, 0XC);
    // 0x8004A534: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004A538: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8004A53C: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004A540: lb          $v0, 0x6($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X6);
    // 0x8004A544: mul.s       $f0, $f8, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8004A548: lb          $v1, 0x10($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X10);
    // 0x8004A54C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004A550: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8004A554: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004A558: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8004A55C: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8004A560: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8004A564: sqrt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = sqrtf(ctx->f0.fl);
    // 0x8004A568: div.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8004A56C: swc1        $f0, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f0.u32l;
    // 0x8004A570: div.s       $f0, $f20, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8004A574: swc1        $f0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f0.u32l;
    // 0x8004A578: div.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8004A57C: swc1        $f0, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f0.u32l;
    // 0x8004A580: lb          $v0, 0xC($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XC);
    // 0x8004A584: lb          $v1, 0xE($s0)
    ctx->r3 = MEM_B(ctx->r16, 0XE);
    // 0x8004A588: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004A58C: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8004A590: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004A594: lb          $v0, 0x8($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X8);
    // 0x8004A598: mul.s       $f0, $f8, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8004A59C: lb          $v1, 0x12($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X12);
    // 0x8004A5A0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004A5A4: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8004A5A8: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004A5AC: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8004A5B0: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8004A5B4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8004A5B8: sqrt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = sqrtf(ctx->f0.fl);
    // 0x8004A5BC: div.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8004A5C0: swc1        $f0, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f0.u32l;
    // 0x8004A5C4: div.s       $f0, $f20, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8004A5C8: swc1        $f0, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f0.u32l;
    // 0x8004A5CC: div.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8004A5D0: swc1        $f0, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f0.u32l;
    // 0x8004A5D4: lb          $v0, 0x14($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X14);
    // 0x8004A5D8: lb          $v1, 0x16($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X16);
    // 0x8004A5DC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004A5E0: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8004A5E4: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004A5E8: lb          $v0, 0x10($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X10);
    // 0x8004A5EC: mul.s       $f0, $f8, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8004A5F0: lb          $v1, 0x6($t3)
    ctx->r3 = MEM_B(ctx->r11, 0X6);
    // 0x8004A5F4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004A5F8: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8004A5FC: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004A600: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8004A604: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8004A608: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8004A60C: sqrt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = sqrtf(ctx->f0.fl);
    // 0x8004A610: div.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8004A614: swc1        $f0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->f0.u32l;
    // 0x8004A618: div.s       $f0, $f20, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8004A61C: swc1        $f0, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f0.u32l;
    // 0x8004A620: div.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8004A624: swc1        $f0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f0.u32l;
    // 0x8004A628: lb          $v0, 0x16($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X16);
    // 0x8004A62C: lb          $v1, 0x18($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X18);
    // 0x8004A630: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004A634: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8004A638: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004A63C: lb          $v0, 0x12($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X12);
    // 0x8004A640: mul.s       $f0, $f8, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8004A644: lb          $v1, 0x8($t3)
    ctx->r3 = MEM_B(ctx->r11, 0X8);
    // 0x8004A648: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004A64C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8004A650: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004A654: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8004A658: lhu         $v1, 0xA($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0XA);
    // 0x8004A65C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004A660: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004A664: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8004A668: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004A66C: addu        $a3, $a0, $v0
    ctx->r7 = ADD32(ctx->r4, ctx->r2);
    // 0x8004A670: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8004A674: sqrt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = sqrtf(ctx->f0.fl);
    // 0x8004A678: div.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8004A67C: swc1        $f0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->f0.u32l;
    // 0x8004A680: div.s       $f0, $f20, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8004A684: swc1        $f0, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f0.u32l;
    // 0x8004A688: div.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8004A68C: swc1        $f0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f0.u32l;
    // 0x8004A690: lhu         $v0, 0x14($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X14);
    // 0x8004A694: andi        $v0, $v0, 0xFFFC
    ctx->r2 = ctx->r2 & 0XFFFC;
    // 0x8004A698: sh          $v0, 0x14($s4)
    MEM_H(0X14, ctx->r20) = ctx->r2;
L_8004A69C:
    // 0x8004A69C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004A6A0: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8004A6A4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8004A6A8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8004A6AC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8004A6B0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8004A6B4: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8004A6B8: jr          $ra
    // 0x8004A6BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8004A6BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8004A6C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A6C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004A6C4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004A6C8: addiu       $v0, $v0, 0x6DC0
    ctx->r2 = ADD32(ctx->r2, 0X6DC0);
    // 0x8004A6CC: sdc1        $f30, 0x28($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X28, ctx->r29);
    // 0x8004A6D0: sdc1        $f28, 0x20($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X20, ctx->r29);
    // 0x8004A6D4: sdc1        $f26, 0x18($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X18, ctx->r29);
    // 0x8004A6D8: sdc1        $f24, 0x10($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X10, ctx->r29);
    // 0x8004A6DC: sdc1        $f22, 0x8($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X8, ctx->r29);
    // 0x8004A6E0: sdc1        $f20, 0x0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X0, ctx->r29);
    // 0x8004A6E4: lw          $v1, 0x48($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X48);
    // 0x8004A6E8: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8004A6EC: lwc1        $f0, 0x10($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8004A6F0: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8004A6F4: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8004A6F8: lwc1        $f0, 0x14($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8004A6FC: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8004A700: lwc1        $f2, 0x18($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X18);
    // 0x8004A704: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8004A708: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8004A70C: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8004A710: mtc1        $a3, $f24
    ctx->f24.u32l = ctx->r7;
    // 0x8004A714: lwc1        $f30, 0x40($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8004A718: add.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8004A71C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004A720: lwc1        $f22, 0x44($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8004A724: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8004A728: nop

    // 0x8004A72C: bc1f        L_8004A768
    if (!c1cs) {
        // 0x8004A730: nop
    
            goto L_8004A768;
    }
    // 0x8004A730: nop

    // 0x8004A734: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8004A738: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8004A73C: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8004A740: mul.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8004A744: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8004A748: mul.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8004A74C: lwc1        $f0, 0x3C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8004A750: add.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8004A754: lwc1        $f0, 0x40($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8004A758: add.s       $f14, $f0, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8004A75C: lwc1        $f0, 0x44($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8004A760: j           L_8004A774
    // 0x8004A764: add.s       $f16, $f0, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f6.fl;
        goto L_8004A774;
    // 0x8004A764: add.s       $f16, $f0, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f6.fl;
L_8004A768:
    // 0x8004A768: lwc1        $f12, 0x3C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8004A76C: lwc1        $f14, 0x40($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8004A770: lwc1        $f16, 0x44($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X44);
L_8004A774:
    // 0x8004A774: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8004A778: beq         $v1, $zero, L_8004A90C
    if (ctx->r3 == 0) {
        // 0x8004A77C: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_8004A90C;
    }
    // 0x8004A77C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8004A780: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8004A784: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004A788: lwc1        $f18, -0x57D4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X57D4);
    // 0x8004A78C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004A790: lwc1        $f28, -0x57D0($at)
    ctx->f28.u32l = MEM_W(ctx->r1, -0X57D0);
L_8004A794:
    // 0x8004A794: lbu         $v0, 0xE($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XE);
    // 0x8004A798: beq         $v0, $zero, L_8004A818
    if (ctx->r2 == 0) {
        // 0x8004A79C: nop
    
            goto L_8004A818;
    }
    // 0x8004A79C: nop

    // 0x8004A7A0: lwc1        $f0, 0x10($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8004A7A4: sub.s       $f8, $f24, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f24.fl - ctx->f0.fl;
    // 0x8004A7A8: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x8004A7AC: nop

    // 0x8004A7B0: bc1tl       L_8004A7B8
    if (c1cs) {
        // 0x8004A7B4: neg.s       $f8, $f8
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = -ctx->f8.fl;
            goto L_8004A7B8;
    }
    goto skip_0;
    // 0x8004A7B4: neg.s       $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = -ctx->f8.fl;
    skip_0:
L_8004A7B8:
    // 0x8004A7B8: lwc1        $f0, 0x18($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X18);
    // 0x8004A7BC: sub.s       $f10, $f22, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f22.fl - ctx->f0.fl;
    // 0x8004A7C0: c.lt.s      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.fl < ctx->f20.fl;
    // 0x8004A7C4: nop

    // 0x8004A7C8: bc1tl       L_8004A7D0
    if (c1cs) {
        // 0x8004A7CC: neg.s       $f10, $f10
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = -ctx->f10.fl;
            goto L_8004A7D0;
    }
    goto skip_1;
    // 0x8004A7CC: neg.s       $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = -ctx->f10.fl;
    skip_1:
L_8004A7D0:
    // 0x8004A7D0: lwc1        $f2, 0x1C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8004A7D4: c.le.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl <= ctx->f8.fl;
    // 0x8004A7D8: nop

    // 0x8004A7DC: bc1t        L_8004A900
    if (c1cs) {
        // 0x8004A7E0: nop
    
            goto L_8004A900;
    }
    // 0x8004A7E0: nop

    // 0x8004A7E4: c.le.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl <= ctx->f10.fl;
    // 0x8004A7E8: nop

    // 0x8004A7EC: bc1t        L_8004A900
    if (c1cs) {
        // 0x8004A7F0: nop
    
            goto L_8004A900;
    }
    // 0x8004A7F0: nop

    // 0x8004A7F4: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8004A7F8: nop

    // 0x8004A7FC: bc1fl       L_8004A808
    if (!c1cs) {
        // 0x8004A800: div.s       $f0, $f10, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
            goto L_8004A808;
    }
    goto skip_2;
    // 0x8004A800: div.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    skip_2:
    // 0x8004A804: div.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
L_8004A808:
    // 0x8004A808: sub.s       $f0, $f18, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x8004A80C: sqrt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = sqrtf(ctx->f0.fl);
    // 0x8004A810: j           L_8004A8DC
    // 0x8004A814: nop

        goto L_8004A8DC;
    // 0x8004A814: nop

L_8004A818:
    // 0x8004A818: lwc1        $f0, 0x10($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8004A81C: sub.s       $f8, $f24, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f24.fl - ctx->f0.fl;
    // 0x8004A820: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8004A824: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8004A828: nop

    // 0x8004A82C: mul.s       $f8, $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8004A830: lwc1        $f0, 0x14($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8004A834: sub.s       $f4, $f30, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f30.fl - ctx->f0.fl;
    // 0x8004A838: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8004A83C: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8004A840: nop

    // 0x8004A844: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8004A848: lwc1        $f0, 0x18($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X18);
    // 0x8004A84C: sub.s       $f4, $f22, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f22.fl - ctx->f0.fl;
    // 0x8004A850: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8004A854: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8004A858: nop

    // 0x8004A85C: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8004A860: add.s       $f10, $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8004A864: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8004A868: add.s       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8004A86C: c.lt.s      $f28, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f28.fl < ctx->f10.fl;
    // 0x8004A870: nop

    // 0x8004A874: bc1f        L_8004A900
    if (!c1cs) {
        // 0x8004A878: add.s       $f8, $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
            goto L_8004A900;
    }
    // 0x8004A878: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8004A87C: lwc1        $f2, 0x1C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8004A880: mul.s       $f0, $f2, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8004A884: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8004A888: nop

    // 0x8004A88C: bc1f        L_8004A900
    if (!c1cs) {
        // 0x8004A890: nop
    
            goto L_8004A900;
    }
    // 0x8004A890: nop

    // 0x8004A894: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004A898: lwc1        $f26, -0x57CC($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X57CC);
    // 0x8004A89C: c.lt.s      $f8, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f8.fl < ctx->f26.fl;
    // 0x8004A8A0: nop

    // 0x8004A8A4: bc1f        L_8004A8C8
    if (!c1cs) {
        // 0x8004A8A8: nop
    
            goto L_8004A8C8;
    }
    // 0x8004A8A8: nop

    // 0x8004A8AC: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8004A8B0: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x8004A8B4: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8004A8B8: add.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x8004A8BC: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8004A8C0: j           L_8004A900
    // 0x8004A8C4: add.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f0.fl;
        goto L_8004A900;
    // 0x8004A8C4: add.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f0.fl;
L_8004A8C8:
    // 0x8004A8C8: sqrt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = sqrtf(ctx->f8.fl);
    // 0x8004A8CC: div.s       $f0, $f18, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8004A8D0: div.s       $f2, $f18, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8004A8D4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004A8D8: mul.s       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
L_8004A8DC:
    // 0x8004A8DC: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8004A8E0: mul.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8004A8E4: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8004A8E8: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8004A8EC: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8004A8F0: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8004A8F4: add.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8004A8F8: add.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x8004A8FC: add.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f0.fl;
L_8004A900:
    // 0x8004A900: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8004A904: bne         $v1, $zero, L_8004A794
    if (ctx->r3 != 0) {
        // 0x8004A908: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_8004A794;
    }
    // 0x8004A908: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_8004A90C:
    // 0x8004A90C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004A910: lwc1        $f0, -0x57C8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X57C8);
    // 0x8004A914: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x8004A918: nop

    // 0x8004A91C: bc1f        L_8004A92C
    if (!c1cs) {
        // 0x8004A920: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8004A92C;
    }
    // 0x8004A920: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8004A924: j           L_8004A98C
    // 0x8004A928: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
        goto L_8004A98C;
    // 0x8004A928: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_8004A92C:
    // 0x8004A92C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004A930: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8004A934: nop

    // 0x8004A938: bc1f        L_8004A948
    if (!c1cs) {
        // 0x8004A93C: nop
    
            goto L_8004A948;
    }
    // 0x8004A93C: nop

    // 0x8004A940: j           L_8004A984
    // 0x8004A944: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
        goto L_8004A984;
    // 0x8004A944: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
L_8004A948:
    // 0x8004A948: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004A94C: lwc1        $f0, -0x57C4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X57C4);
    // 0x8004A950: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x8004A954: nop

    // 0x8004A958: bc1tl       L_8004A970
    if (c1cs) {
        // 0x8004A95C: sub.s       $f0, $f12, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f0.fl;
            goto L_8004A970;
    }
    goto skip_3;
    // 0x8004A95C: sub.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f0.fl;
    skip_3:
    // 0x8004A960: trunc.w.s   $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    ctx->f26.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8004A964: mfc1        $v1, $f26
    ctx->r3 = (int32_t)ctx->f26.u32l;
    // 0x8004A968: j           L_8004A984
    // 0x8004A96C: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
        goto L_8004A984;
    // 0x8004A96C: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
L_8004A970:
    // 0x8004A970: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8004A974: trunc.w.s   $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004A978: mfc1        $v1, $f26
    ctx->r3 = (int32_t)ctx->f26.u32l;
    // 0x8004A97C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8004A980: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
L_8004A984:
    // 0x8004A984: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004A988: lwc1        $f0, -0x57C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X57C0);
L_8004A98C:
    // 0x8004A98C: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x8004A990: nop

    // 0x8004A994: bc1f        L_8004A9A4
    if (!c1cs) {
        // 0x8004A998: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8004A9A4;
    }
    // 0x8004A998: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8004A99C: j           L_8004A9FC
    // 0x8004A9A0: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
        goto L_8004A9FC;
    // 0x8004A9A0: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
L_8004A9A4:
    // 0x8004A9A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004A9A8: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x8004A9AC: nop

    // 0x8004A9B0: bc1f        L_8004A9C0
    if (!c1cs) {
        // 0x8004A9B4: nop
    
            goto L_8004A9C0;
    }
    // 0x8004A9B4: nop

    // 0x8004A9B8: j           L_8004A9FC
    // 0x8004A9BC: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
        goto L_8004A9FC;
    // 0x8004A9BC: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
L_8004A9C0:
    // 0x8004A9C0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004A9C4: lwc1        $f0, -0x57BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X57BC);
    // 0x8004A9C8: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x8004A9CC: nop

    // 0x8004A9D0: bc1tl       L_8004A9E8
    if (c1cs) {
        // 0x8004A9D4: sub.s       $f0, $f14, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f0.fl;
            goto L_8004A9E8;
    }
    goto skip_4;
    // 0x8004A9D4: sub.s       $f0, $f14, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f0.fl;
    skip_4:
    // 0x8004A9D8: trunc.w.s   $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    ctx->f26.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8004A9DC: mfc1        $v1, $f26
    ctx->r3 = (int32_t)ctx->f26.u32l;
    // 0x8004A9E0: j           L_8004A9FC
    // 0x8004A9E4: sb          $v1, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r3;
        goto L_8004A9FC;
    // 0x8004A9E4: sb          $v1, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r3;
L_8004A9E8:
    // 0x8004A9E8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8004A9EC: trunc.w.s   $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004A9F0: mfc1        $v1, $f26
    ctx->r3 = (int32_t)ctx->f26.u32l;
    // 0x8004A9F4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8004A9F8: sb          $v1, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r3;
L_8004A9FC:
    // 0x8004A9FC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004AA00: lwc1        $f0, -0x57B8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X57B8);
    // 0x8004AA04: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x8004AA08: nop

    // 0x8004AA0C: bc1f        L_8004AA1C
    if (!c1cs) {
        // 0x8004AA10: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8004AA1C;
    }
    // 0x8004AA10: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8004AA14: j           L_8004AA74
    // 0x8004AA18: sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
        goto L_8004AA74;
    // 0x8004AA18: sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
L_8004AA1C:
    // 0x8004AA1C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004AA20: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8004AA24: nop

    // 0x8004AA28: bc1f        L_8004AA38
    if (!c1cs) {
        // 0x8004AA2C: nop
    
            goto L_8004AA38;
    }
    // 0x8004AA2C: nop

    // 0x8004AA30: j           L_8004AA74
    // 0x8004AA34: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
        goto L_8004AA74;
    // 0x8004AA34: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
L_8004AA38:
    // 0x8004AA38: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004AA3C: lwc1        $f0, -0x57B4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X57B4);
    // 0x8004AA40: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x8004AA44: nop

    // 0x8004AA48: bc1tl       L_8004AA60
    if (c1cs) {
        // 0x8004AA4C: sub.s       $f0, $f16, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f0.fl;
            goto L_8004AA60;
    }
    goto skip_5;
    // 0x8004AA4C: sub.s       $f0, $f16, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f0.fl;
    skip_5:
    // 0x8004AA50: trunc.w.s   $f26, $f16
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    ctx->f26.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8004AA54: mfc1        $v1, $f26
    ctx->r3 = (int32_t)ctx->f26.u32l;
    // 0x8004AA58: j           L_8004AA74
    // 0x8004AA5C: sb          $v1, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r3;
        goto L_8004AA74;
    // 0x8004AA5C: sb          $v1, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r3;
L_8004AA60:
    // 0x8004AA60: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8004AA64: trunc.w.s   $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004AA68: mfc1        $v1, $f26
    ctx->r3 = (int32_t)ctx->f26.u32l;
    // 0x8004AA6C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8004AA70: sb          $v1, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r3;
L_8004AA74:
    // 0x8004AA74: ldc1        $f30, 0x28($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X28);
    // 0x8004AA78: ldc1        $f28, 0x20($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X20);
    // 0x8004AA7C: ldc1        $f26, 0x18($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X18);
    // 0x8004AA80: ldc1        $f24, 0x10($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X10);
    // 0x8004AA84: ldc1        $f22, 0x8($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X8);
    // 0x8004AA88: ldc1        $f20, 0x0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X0);
    // 0x8004AA8C: jr          $ra
    // 0x8004AA90: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8004AA90: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8004AA94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004AA94: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8004AA98: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x8004AA9C: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x8004AAA0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004AAA4: addiu       $v0, $v0, 0x6DC0
    ctx->r2 = ADD32(ctx->r2, 0X6DC0);
    // 0x8004AAA8: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8004AAAC: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x8004AAB0: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x8004AAB4: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x8004AAB8: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x8004AABC: sdc1        $f30, 0x98($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X98, ctx->r29);
    // 0x8004AAC0: sdc1        $f28, 0x90($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X90, ctx->r29);
    // 0x8004AAC4: sdc1        $f26, 0x88($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X88, ctx->r29);
    // 0x8004AAC8: sdc1        $f24, 0x80($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X80, ctx->r29);
    // 0x8004AACC: sdc1        $f22, 0x78($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X78, ctx->r29);
    // 0x8004AAD0: sdc1        $f20, 0x70($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X70, ctx->r29);
    // 0x8004AAD4: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x8004AAD8: beq         $a0, $zero, L_8004AB84
    if (ctx->r4 == 0) {
        // 0x8004AADC: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8004AB84;
    }
    // 0x8004AADC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8004AAE0: lh          $v1, 0x1A($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X1A);
    // 0x8004AAE4: lhu         $v0, 0x38($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X38);
    // 0x8004AAE8: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004AAEC: lh          $v0, 0x18($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X18);
    // 0x8004AAF0: mflo        $t1
    ctx->r9 = lo;
    // 0x8004AAF4: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8004AAF8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8004AAFC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004AB00: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8004AB04: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // 0x8004AB08: beq         $v1, $a2, L_8004AB84
    if (ctx->r3 == ctx->r6) {
        // 0x8004AB0C: andi        $v0, $v1, 0x7FFF
        ctx->r2 = ctx->r3 & 0X7FFF;
            goto L_8004AB84;
    }
    // 0x8004AB0C: andi        $v0, $v1, 0x7FFF
    ctx->r2 = ctx->r3 & 0X7FFF;
    // 0x8004AB10: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8004AB14: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8004AB18: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004AB1C: lw          $v0, 0x6FCC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6FCC);
    // 0x8004AB20: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8004AB24: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004AB28: lhu         $v1, 0x2($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X2);
    // 0x8004AB2C: beq         $v1, $a2, L_8004AB84
    if (ctx->r3 == ctx->r6) {
        // 0x8004AB30: addu        $a2, $v0, $zero
        ctx->r6 = ADD32(ctx->r2, 0);
            goto L_8004AB84;
    }
    // 0x8004AB30: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8004AB34: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8004AB38: ori         $a3, $zero, 0xFFFF
    ctx->r7 = 0 | 0XFFFF;
    // 0x8004AB3C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8004AB40: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
L_8004AB44:
    // 0x8004AB44: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004AB48: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004AB4C: addu        $v1, $v0, $a2
    ctx->r3 = ADD32(ctx->r2, ctx->r6);
    // 0x8004AB50: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x8004AB54: bne         $v0, $t0, L_8004AB70
    if (ctx->r2 != ctx->r8) {
        // 0x8004AB58: slti        $v0, $a1, 0x9
        ctx->r2 = SIGNED(ctx->r5) < 0X9 ? 1 : 0;
            goto L_8004AB70;
    }
    // 0x8004AB58: slti        $v0, $a1, 0x9
    ctx->r2 = SIGNED(ctx->r5) < 0X9 ? 1 : 0;
    // 0x8004AB5C: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x8004AB60: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8004AB64: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8004AB68: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8004AB6C: slti        $v0, $a1, 0x9
    ctx->r2 = SIGNED(ctx->r5) < 0X9 ? 1 : 0;
L_8004AB70:
    // 0x8004AB70: beq         $v0, $zero, L_8004AB88
    if (ctx->r2 == 0) {
        // 0x8004AB74: sll         $v0, $a1, 2
        ctx->r2 = S32(ctx->r5 << 2);
            goto L_8004AB88;
    }
    // 0x8004AB74: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8004AB78: lhu         $v1, 0x2($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X2);
    // 0x8004AB7C: bne         $v1, $a3, L_8004AB44
    if (ctx->r3 != ctx->r7) {
        // 0x8004AB80: sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3 << 1);
            goto L_8004AB44;
    }
    // 0x8004AB80: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
L_8004AB84:
    // 0x8004AB84: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
L_8004AB88:
    // 0x8004AB88: addiu       $s2, $sp, 0x18
    ctx->r18 = ADD32(ctx->r29, 0X18);
    // 0x8004AB8C: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x8004AB90: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8004AB94: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004AB98: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x8004AB9C: lwc1        $f0, 0x6DD0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X6DD0);
    // 0x8004ABA0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004ABA4: lwc1        $f2, -0x57B0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X57B0);
    // 0x8004ABA8: lhu         $v1, 0xA($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0XA);
    // 0x8004ABAC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004ABB0: lwc1        $f22, -0x57AC($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X57AC);
    // 0x8004ABB4: lw          $s1, 0x44($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X44);
    // 0x8004ABB8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8004ABBC: lh          $a1, 0x18($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X18);
    // 0x8004ABC0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004ABC4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004ABC8: mtc1        $a1, $f26
    ctx->f26.u32l = ctx->r5;
    // 0x8004ABCC: cvt.s.w     $f26, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    ctx->f26.fl = CVT_S_W(ctx->f26.u32l);
    // 0x8004ABD0: add.s       $f4, $f26, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f26.fl + ctx->f2.fl;
    // 0x8004ABD4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004ABD8: lb          $v1, 0x0($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X0);
    // 0x8004ABDC: mul.s       $f28, $f0, $f22
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f28.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8004ABE0: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x8004ABE4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004ABE8: lw          $v1, 0x7A54($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X7A54);
    // 0x8004ABEC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004ABF0: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x8004ABF4: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x8004ABF8: lh          $v0, 0x1A($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X1A);
    // 0x8004ABFC: addiu       $a0, $s3, 0x54
    ctx->r4 = ADD32(ctx->r19, 0X54);
    // 0x8004AC00: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8004AC04: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004AC08: add.s       $f2, $f4, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8004AC0C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004AC10: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8004AC14: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004AC18: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004AC1C: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x8004AC20: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x8004AC24: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x8004AC28: jal         0x8004A6C0
    // 0x8004AC2C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8004A6C0(rdram, ctx);
        goto after_0;
    // 0x8004AC2C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8004AC30: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004AC34: lwc1        $f20, -0x57A8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X57A8);
    // 0x8004AC38: add.s       $f4, $f26, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f26.fl + ctx->f20.fl;
    // 0x8004AC3C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004AC40: addiu       $a0, $s3, 0x64
    ctx->r4 = ADD32(ctx->r19, 0X64);
    // 0x8004AC44: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x8004AC48: lb          $v0, 0x4($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X4);
    // 0x8004AC4C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004AC50: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004AC54: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004AC58: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004AC5C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8004AC60: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8004AC64: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004AC68: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8004AC6C: jal         0x8004A6C0
    // 0x8004AC70: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8004A6C0(rdram, ctx);
        goto after_1;
    // 0x8004AC70: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8004AC74: lb          $v0, 0x14($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X14);
    // 0x8004AC78: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004AC7C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004AC80: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004AC84: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004AC88: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004AC8C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004AC90: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8004AC94: addiu       $a0, $s3, 0xA4
    ctx->r4 = ADD32(ctx->r19, 0XA4);
    // 0x8004AC98: add.s       $f20, $f4, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8004AC9C: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8004ACA0: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004ACA4: swc1        $f20, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f20.u32l;
    // 0x8004ACA8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8004ACAC: jal         0x8004A6C0
    // 0x8004ACB0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8004A6C0(rdram, ctx);
        goto after_2;
    // 0x8004ACB0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8004ACB4: addiu       $a0, $s3, 0xB4
    ctx->r4 = ADD32(ctx->r19, 0XB4);
    // 0x8004ACB8: lb          $v0, 0x18($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X18);
    // 0x8004ACBC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004ACC0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004ACC4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004ACC8: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004ACCC: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8004ACD0: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8004ACD4: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004ACD8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8004ACDC: jal         0x8004A6C0
    // 0x8004ACE0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8004A6C0(rdram, ctx);
        goto after_3;
    // 0x8004ACE0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x8004ACE4: lbu         $v0, 0x30($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X30);
    // 0x8004ACE8: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8004ACEC: beq         $v0, $zero, L_8004B1AC
    if (ctx->r2 == 0) {
        // 0x8004ACF0: addiu       $a0, $s3, 0x5C
        ctx->r4 = ADD32(ctx->r19, 0X5C);
            goto L_8004B1AC;
    }
    // 0x8004ACF0: addiu       $a0, $s3, 0x5C
    ctx->r4 = ADD32(ctx->r19, 0X5C);
    // 0x8004ACF4: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004ACF8: add.s       $f30, $f26, $f22
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f30.fl = ctx->f26.fl + ctx->f22.fl;
    // 0x8004ACFC: lhu         $v1, 0xC($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0XC);
    // 0x8004AD00: lb          $a1, 0x2($s1)
    ctx->r5 = MEM_B(ctx->r17, 0X2);
    // 0x8004AD04: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8004AD08: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004AD0C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004AD10: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004AD14: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x8004AD18: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004AD1C: lw          $v1, 0x7A54($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X7A54);
    // 0x8004AD20: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004AD24: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8004AD28: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x8004AD2C: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x8004AD30: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004AD34: jal         0x8004A6C0
    // 0x8004AD38: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8004A6C0(rdram, ctx);
        goto after_4;
    // 0x8004AD38: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8004AD3C: lb          $v0, 0xA($s1)
    ctx->r2 = MEM_B(ctx->r17, 0XA);
    // 0x8004AD40: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004AD44: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004AD48: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004AD4C: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004AD50: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004AD54: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004AD58: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8004AD5C: addiu       $a0, $s3, 0x7C
    ctx->r4 = ADD32(ctx->r19, 0X7C);
    // 0x8004AD60: add.s       $f22, $f4, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x8004AD64: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8004AD68: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004AD6C: swc1        $f22, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f22.u32l;
    // 0x8004AD70: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x8004AD74: jal         0x8004A6C0
    // 0x8004AD78: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8004A6C0(rdram, ctx);
        goto after_5;
    // 0x8004AD78: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x8004AD7C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004AD80: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004AD84: lb          $v0, 0xC($s1)
    ctx->r2 = MEM_B(ctx->r17, 0XC);
    // 0x8004AD88: addiu       $a0, $s3, 0x84
    ctx->r4 = ADD32(ctx->r19, 0X84);
    // 0x8004AD8C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004AD90: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004AD94: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004AD98: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x8004AD9C: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8004ADA0: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004ADA4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8004ADA8: jal         0x8004A6C0
    // 0x8004ADAC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8004A6C0(rdram, ctx);
        goto after_6;
    // 0x8004ADAC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x8004ADB0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004ADB4: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004ADB8: lb          $v0, 0xE($s1)
    ctx->r2 = MEM_B(ctx->r17, 0XE);
    // 0x8004ADBC: addiu       $a0, $s3, 0x8C
    ctx->r4 = ADD32(ctx->r19, 0X8C);
    // 0x8004ADC0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004ADC4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004ADC8: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004ADCC: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8004ADD0: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8004ADD4: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004ADD8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8004ADDC: jal         0x8004A6C0
    // 0x8004ADE0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8004A6C0(rdram, ctx);
        goto after_7;
    // 0x8004ADE0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x8004ADE4: addiu       $a0, $s3, 0xAC
    ctx->r4 = ADD32(ctx->r19, 0XAC);
    // 0x8004ADE8: lb          $v0, 0x16($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X16);
    // 0x8004ADEC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004ADF0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004ADF4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004ADF8: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004ADFC: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x8004AE00: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8004AE04: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004AE08: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8004AE0C: jal         0x8004A6C0
    // 0x8004AE10: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8004A6C0(rdram, ctx);
        goto after_8;
    // 0x8004AE10: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x8004AE14: lbu         $v0, 0x30($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X30);
    // 0x8004AE18: bne         $v0, $zero, L_8004B1AC
    if (ctx->r2 != 0) {
        // 0x8004AE1C: addiu       $a0, $s3, 0x68
        ctx->r4 = ADD32(ctx->r19, 0X68);
            goto L_8004B1AC;
    }
    // 0x8004AE1C: addiu       $a0, $s3, 0x68
    ctx->r4 = ADD32(ctx->r19, 0X68);
    // 0x8004AE20: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004AE24: lhu         $a1, 0xE($s3)
    ctx->r5 = MEM_HU(ctx->r19, 0XE);
    // 0x8004AE28: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8004AE2C: lb          $v1, 0x5($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X5);
    // 0x8004AE30: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004AE34: lwc1        $f24, -0x57A4($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X57A4);
    // 0x8004AE38: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8004AE3C: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x8004AE40: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004AE44: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004AE48: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8004AE4C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8004AE50: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004AE54: lw          $v1, 0x7A54($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X7A54);
    // 0x8004AE58: add.s       $f22, $f4, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x8004AE5C: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x8004AE60: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004AE64: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004AE68: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x8004AE6C: jal         0x8004A6C0
    // 0x8004AE70: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8004A6C0(rdram, ctx);
        goto after_9;
    // 0x8004AE70: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x8004AE74: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004AE78: add.s       $f24, $f26, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f24.fl = ctx->f26.fl + ctx->f24.fl;
    // 0x8004AE7C: lb          $v0, 0x6($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X6);
    // 0x8004AE80: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004AE84: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004AE88: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004AE8C: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004AE90: addiu       $a0, $s3, 0x6C
    ctx->r4 = ADD32(ctx->r19, 0X6C);
    // 0x8004AE94: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8004AE98: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004AE9C: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x8004AEA0: jal         0x8004A6C0
    // 0x8004AEA4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8004A6C0(rdram, ctx);
        goto after_10;
    // 0x8004AEA4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x8004AEA8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004AEAC: lb          $v0, 0x7($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X7);
    // 0x8004AEB0: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004AEB4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004AEB8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004AEBC: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004AEC0: addiu       $a0, $s3, 0x70
    ctx->r4 = ADD32(ctx->r19, 0X70);
    // 0x8004AEC4: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x8004AEC8: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004AECC: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x8004AED0: jal         0x8004A6C0
    // 0x8004AED4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8004A6C0(rdram, ctx);
        goto after_11;
    // 0x8004AED4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_11:
    // 0x8004AED8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004AEDC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004AEE0: lwc1        $f20, -0x57A0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X57A0);
    // 0x8004AEE4: lb          $v0, 0x8($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X8);
    // 0x8004AEE8: add.s       $f26, $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f26.fl = ctx->f26.fl + ctx->f20.fl;
    // 0x8004AEEC: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004AEF0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004AEF4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004AEF8: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004AEFC: addiu       $a0, $s3, 0x74
    ctx->r4 = ADD32(ctx->r19, 0X74);
    // 0x8004AF00: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x8004AF04: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004AF08: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x8004AF0C: jal         0x8004A6C0
    // 0x8004AF10: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8004A6C0(rdram, ctx);
        goto after_12;
    // 0x8004AF10: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_12:
    // 0x8004AF14: lb          $v0, 0x9($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X9);
    // 0x8004AF18: addiu       $a0, $s3, 0x78
    ctx->r4 = ADD32(ctx->r19, 0X78);
    // 0x8004AF1C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004AF20: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004AF24: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004AF28: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004AF2C: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8004AF30: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004AF34: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x8004AF38: jal         0x8004A6C0
    // 0x8004AF3C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8004A6C0(rdram, ctx);
        goto after_13;
    // 0x8004AF3C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x8004AF40: addiu       $a0, $s3, 0x90
    ctx->r4 = ADD32(ctx->r19, 0X90);
    // 0x8004AF44: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004AF48: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8004AF4C: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8004AF50: lhu         $v1, 0x10($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0X10);
    // 0x8004AF54: lb          $a1, 0xF($s1)
    ctx->r5 = MEM_B(ctx->r17, 0XF);
    // 0x8004AF58: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004AF5C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004AF60: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004AF64: add.s       $f20, $f4, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8004AF68: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x8004AF6C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004AF70: lw          $v1, 0x7A54($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X7A54);
    // 0x8004AF74: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004AF78: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x8004AF7C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004AF80: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004AF84: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8004AF88: jal         0x8004A6C0
    // 0x8004AF8C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8004A6C0(rdram, ctx);
        goto after_14;
    // 0x8004AF8C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_14:
    // 0x8004AF90: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004AF94: lb          $v0, 0x10($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X10);
    // 0x8004AF98: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004AF9C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004AFA0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004AFA4: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004AFA8: addiu       $a0, $s3, 0x94
    ctx->r4 = ADD32(ctx->r19, 0X94);
    // 0x8004AFAC: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8004AFB0: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004AFB4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8004AFB8: jal         0x8004A6C0
    // 0x8004AFBC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8004A6C0(rdram, ctx);
        goto after_15;
    // 0x8004AFBC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_15:
    // 0x8004AFC0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004AFC4: lb          $v0, 0x11($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X11);
    // 0x8004AFC8: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004AFCC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004AFD0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004AFD4: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004AFD8: addiu       $a0, $s3, 0x98
    ctx->r4 = ADD32(ctx->r19, 0X98);
    // 0x8004AFDC: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x8004AFE0: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004AFE4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8004AFE8: jal         0x8004A6C0
    // 0x8004AFEC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8004A6C0(rdram, ctx);
        goto after_16;
    // 0x8004AFEC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_16:
    // 0x8004AFF0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004AFF4: lb          $v0, 0x12($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X12);
    // 0x8004AFF8: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004AFFC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004B000: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004B004: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004B008: addiu       $a0, $s3, 0x9C
    ctx->r4 = ADD32(ctx->r19, 0X9C);
    // 0x8004B00C: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x8004B010: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004B014: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8004B018: jal         0x8004A6C0
    // 0x8004B01C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8004A6C0(rdram, ctx);
        goto after_17;
    // 0x8004B01C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_17:
    // 0x8004B020: lb          $v0, 0x13($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X13);
    // 0x8004B024: addiu       $a0, $s3, 0xA0
    ctx->r4 = ADD32(ctx->r19, 0XA0);
    // 0x8004B028: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004B02C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004B030: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004B034: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004B038: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8004B03C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004B040: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8004B044: jal         0x8004A6C0
    // 0x8004B048: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8004A6C0(rdram, ctx);
        goto after_18;
    // 0x8004B048: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_18:
    // 0x8004B04C: addiu       $a0, $s3, 0x58
    ctx->r4 = ADD32(ctx->r19, 0X58);
    // 0x8004B050: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004B054: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8004B058: lhu         $v1, 0x12($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0X12);
    // 0x8004B05C: lb          $a1, 0x1($s1)
    ctx->r5 = MEM_B(ctx->r17, 0X1);
    // 0x8004B060: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8004B064: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004B068: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004B06C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004B070: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x8004B074: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004B078: lw          $v1, 0x7A54($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X7A54);
    // 0x8004B07C: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004B080: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8004B084: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x8004B088: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004B08C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004B090: jal         0x8004A6C0
    // 0x8004B094: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8004A6C0(rdram, ctx);
        goto after_19;
    // 0x8004B094: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_19:
    // 0x8004B098: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004B09C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004B0A0: lb          $v0, 0x3($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X3);
    // 0x8004B0A4: addiu       $a0, $s3, 0x60
    ctx->r4 = ADD32(ctx->r19, 0X60);
    // 0x8004B0A8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004B0AC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004B0B0: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004B0B4: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x8004B0B8: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8004B0BC: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004B0C0: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8004B0C4: jal         0x8004A6C0
    // 0x8004B0C8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8004A6C0(rdram, ctx);
        goto after_20;
    // 0x8004B0C8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_20:
    // 0x8004B0CC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004B0D0: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004B0D4: lb          $v0, 0xB($s1)
    ctx->r2 = MEM_B(ctx->r17, 0XB);
    // 0x8004B0D8: addiu       $a0, $s3, 0x80
    ctx->r4 = ADD32(ctx->r19, 0X80);
    // 0x8004B0DC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004B0E0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004B0E4: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004B0E8: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8004B0EC: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8004B0F0: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004B0F4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8004B0F8: jal         0x8004A6C0
    // 0x8004B0FC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8004A6C0(rdram, ctx);
        goto after_21;
    // 0x8004B0FC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_21:
    // 0x8004B100: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004B104: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004B108: lb          $v0, 0xD($s1)
    ctx->r2 = MEM_B(ctx->r17, 0XD);
    // 0x8004B10C: addiu       $a0, $s3, 0x88
    ctx->r4 = ADD32(ctx->r19, 0X88);
    // 0x8004B110: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004B114: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004B118: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004B11C: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x8004B120: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8004B124: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004B128: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8004B12C: jal         0x8004A6C0
    // 0x8004B130: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8004A6C0(rdram, ctx);
        goto after_22;
    // 0x8004B130: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_22:
    // 0x8004B134: addiu       $a0, $s3, 0xA8
    ctx->r4 = ADD32(ctx->r19, 0XA8);
    // 0x8004B138: lb          $v0, 0x15($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X15);
    // 0x8004B13C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004B140: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004B144: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004B148: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004B14C: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8004B150: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8004B154: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004B158: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8004B15C: jal         0x8004A6C0
    // 0x8004B160: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8004A6C0(rdram, ctx);
        goto after_23;
    // 0x8004B160: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_23:
    // 0x8004B164: addiu       $a0, $s3, 0xB0
    ctx->r4 = ADD32(ctx->r19, 0XB0);
    // 0x8004B168: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004B16C: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x8004B170: lhu         $v1, 0xA($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0XA);
    // 0x8004B174: lb          $a1, 0x17($s1)
    ctx->r5 = MEM_B(ctx->r17, 0X17);
    // 0x8004B178: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8004B17C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004B180: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004B184: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x8004B188: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004B18C: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004B190: lw          $v1, 0x7A54($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X7A54);
    // 0x8004B194: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004B198: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8004B19C: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x8004B1A0: addiu       $a1, $s0, 0x30
    ctx->r5 = ADD32(ctx->r16, 0X30);
    // 0x8004B1A4: jal         0x8004A6C0
    // 0x8004B1A8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8004A6C0(rdram, ctx);
        goto after_24;
    // 0x8004B1A8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_24:
L_8004B1AC:
    // 0x8004B1AC: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8004B1B0: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x8004B1B4: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x8004B1B8: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x8004B1BC: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x8004B1C0: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x8004B1C4: ldc1        $f30, 0x98($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X98);
    // 0x8004B1C8: ldc1        $f28, 0x90($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X90);
    // 0x8004B1CC: ldc1        $f26, 0x88($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X88);
    // 0x8004B1D0: ldc1        $f24, 0x80($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X80);
    // 0x8004B1D4: ldc1        $f22, 0x78($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X78);
    // 0x8004B1D8: ldc1        $f20, 0x70($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X70);
    // 0x8004B1DC: jr          $ra
    // 0x8004B1E0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8004B1E0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_8004B1E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004B1E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004B1E8: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8004B1EC: sw          $s3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r19;
    // 0x8004B1F0: sw          $s2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r18;
    // 0x8004B1F4: sw          $s1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r17;
    // 0x8004B1F8: sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // 0x8004B1FC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8004B200: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8004B204: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004B208: lwc1        $f8, -0x579C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X579C);
    // 0x8004B20C: mul.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8004B210: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8004B214: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8004B218: lwc1        $f2, 0x18($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8004B21C: mul.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8004B220: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8004B224: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8004B228: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8004B22C: addiu       $a2, $a3, 0x6DC0
    ctx->r6 = ADD32(ctx->r7, 0X6DC0);
    // 0x8004B230: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004B234: lwc1        $f0, -0x5798($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5798);
    // 0x8004B238: mul.s       $f18, $f10, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8004B23C: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x8004B240: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
    // 0x8004B244: swc1        $f2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f2.u32l;
    // 0x8004B248: swc1        $f10, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f10.u32l;
    // 0x8004B24C: lwc1        $f2, 0x10($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X10);
    // 0x8004B250: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8004B254: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8004B258: sub.s       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8004B25C: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8004B260: trunc.w.s   $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004B264: mfc1        $t6, $f20
    ctx->r14 = (int32_t)ctx->f20.u32l;
    // 0x8004B268: mul.s       $f12, $f2, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8004B26C: bgez        $t6, L_8004B278
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8004B270: addu        $t7, $zero, $zero
        ctx->r15 = ADD32(0, 0);
            goto L_8004B278;
    }
    // 0x8004B270: addu        $t7, $zero, $zero
    ctx->r15 = ADD32(0, 0);
    // 0x8004B274: addu        $t6, $t7, $zero
    ctx->r14 = ADD32(ctx->r15, 0);
L_8004B278:
    // 0x8004B278: add.s       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8004B27C: lhu         $v1, 0x3A($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X3A);
    // 0x8004B280: trunc.w.s   $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004B284: mfc1        $s0, $f20
    ctx->r16 = (int32_t)ctx->f20.u32l;
    // 0x8004B288: slt         $v0, $s0, $v1
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8004B28C: beql        $v0, $zero, L_8004B294
    if (ctx->r2 == 0) {
        // 0x8004B290: addiu       $s0, $v1, -0x1
        ctx->r16 = ADD32(ctx->r3, -0X1);
            goto L_8004B294;
    }
    goto skip_0;
    // 0x8004B290: addiu       $s0, $v1, -0x1
    ctx->r16 = ADD32(ctx->r3, -0X1);
    skip_0:
L_8004B294:
    // 0x8004B294: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8004B298: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8004B29C: lhu         $v1, 0x38($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X38);
    // 0x8004B2A0: trunc.w.s   $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004B2A4: mfc1        $t8, $f20
    ctx->r24 = (int32_t)ctx->f20.u32l;
    // 0x8004B2A8: slt         $v0, $t8, $v1
    ctx->r2 = SIGNED(ctx->r24) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8004B2AC: beql        $v0, $zero, L_8004B2B4
    if (ctx->r2 == 0) {
        // 0x8004B2B0: addiu       $t8, $v1, -0x1
        ctx->r24 = ADD32(ctx->r3, -0X1);
            goto L_8004B2B4;
    }
    goto skip_1;
    // 0x8004B2B0: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    skip_1:
L_8004B2B4:
    // 0x8004B2B4: slt         $v0, $s0, $t6
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8004B2B8: bne         $v0, $zero, L_8004B5E8
    if (ctx->r2 != 0) {
        // 0x8004B2BC: addu        $s3, $a3, $zero
        ctx->r19 = ADD32(ctx->r7, 0);
            goto L_8004B5E8;
    }
    // 0x8004B2BC: addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // 0x8004B2C0: addu        $t9, $a2, $zero
    ctx->r25 = ADD32(ctx->r6, 0);
    // 0x8004B2C4: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8004B2C8: ori         $t4, $zero, 0xFFFF
    ctx->r12 = 0 | 0XFFFF;
    // 0x8004B2CC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004B2D0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004B2D4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004B2D8: lwc1        $f16, -0x5794($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X5794);
    // 0x8004B2DC: lw          $t1, 0x6FCC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X6FCC);
L_8004B2E0:
    // 0x8004B2E0: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8004B2E4: lwc1        $f2, 0x1C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8004B2E8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004B2EC: trunc.w.s   $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004B2F0: mfc1        $t2, $f20
    ctx->r10 = (int32_t)ctx->f20.u32l;
    // 0x8004B2F4: bltzl       $t2, L_8004B2FC
    if (SIGNED(ctx->r10) < 0) {
        // 0x8004B2F8: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_8004B2FC;
    }
    goto skip_2;
    // 0x8004B2F8: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    skip_2:
L_8004B2FC:
    // 0x8004B2FC: lhu         $v0, 0x38($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X38);
    // 0x8004B300: mult        $t6, $v0
    result = S64(S32(ctx->r14)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004B304: slt         $v0, $t8, $t2
    ctx->r2 = SIGNED(ctx->r24) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8004B308: mflo        $s4
    ctx->r20 = lo;
    // 0x8004B30C: bne         $v0, $zero, L_8004B5D8
    if (ctx->r2 != 0) {
        // 0x8004B310: addu        $t5, $t2, $s4
        ctx->r13 = ADD32(ctx->r10, ctx->r20);
            goto L_8004B5D8;
    }
    // 0x8004B310: addu        $t5, $t2, $s4
    ctx->r13 = ADD32(ctx->r10, ctx->r20);
    // 0x8004B314: mtc1        $t6, $f14
    ctx->f14.u32l = ctx->r14;
    // 0x8004B318: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x8004B31C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8004B320: sll         $t3, $t5, 1
    ctx->r11 = S32(ctx->r13 << 1);
L_8004B324:
    // 0x8004B324: lw          $v0, 0x6DC0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X6DC0);
    // 0x8004B328: lwc1        $f0, 0x18($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8004B32C: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8004B330: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8004B334: sub.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x8004B338: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x8004B33C: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8004B340: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004B344: lw          $v1, 0x4($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X4);
    // 0x8004B348: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8004B34C: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x8004B350: nop

    // 0x8004B354: bc1f        L_8004B360
    if (!c1cs) {
        // 0x8004B358: addu        $v1, $v1, $v0
        ctx->r3 = ADD32(ctx->r3, ctx->r2);
            goto L_8004B360;
    }
    // 0x8004B358: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004B35C: sub.s       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f16.fl;
L_8004B360:
    // 0x8004B360: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8004B364: mtc1        $t2, $f0
    ctx->f0.u32l = ctx->r10;
    // 0x8004B368: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004B36C: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8004B370: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x8004B374: nop

    // 0x8004B378: bc1tl       L_8004B380
    if (c1cs) {
        // 0x8004B37C: sub.s       $f6, $f6, $f16
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f16.fl;
            goto L_8004B380;
    }
    goto skip_3;
    // 0x8004B37C: sub.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f16.fl;
    skip_3:
L_8004B380:
    // 0x8004B380: lb          $v0, 0x3($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X3);
    // 0x8004B384: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004B388: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004B38C: mul.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8004B390: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8004B394: sub.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8004B398: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x8004B39C: nop

    // 0x8004B3A0: bc1f        L_8004B3CC
    if (!c1cs) {
        // 0x8004B3A4: nop
    
            goto L_8004B3CC;
    }
    // 0x8004B3A4: nop

    // 0x8004B3A8: lb          $v0, 0x4($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X4);
    // 0x8004B3AC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004B3B0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004B3B4: mul.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8004B3B8: sub.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8004B3BC: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x8004B3C0: nop

    // 0x8004B3C4: bc1tl       L_8004B3CC
    if (c1cs) {
        // 0x8004B3C8: mov.s       $f2, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = ctx->f10.fl;
            goto L_8004B3CC;
    }
    goto skip_4;
    // 0x8004B3C8: mov.s       $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = ctx->f10.fl;
    skip_4:
L_8004B3CC:
    // 0x8004B3CC: mul.s       $f0, $f6, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8004B3D0: nop

    // 0x8004B3D4: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8004B3D8: nop

    // 0x8004B3DC: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8004B3E0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8004B3E4: lbu         $v0, 0xE($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XE);
    // 0x8004B3E8: bne         $v0, $zero, L_8004B400
    if (ctx->r2 != 0) {
        // 0x8004B3EC: add.s       $f0, $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
            goto L_8004B400;
    }
    // 0x8004B3EC: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8004B3F0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8004B3F4: nop

    // 0x8004B3F8: bc1fl       L_8004B5C4
    if (!c1cs) {
        // 0x8004B3FC: addiu       $t3, $t3, 0x2
        ctx->r11 = ADD32(ctx->r11, 0X2);
            goto L_8004B5C4;
    }
    goto skip_5;
    // 0x8004B3FC: addiu       $t3, $t3, 0x2
    ctx->r11 = ADD32(ctx->r11, 0X2);
    skip_5:
L_8004B400:
    // 0x8004B400: beq         $s2, $zero, L_8004B5C8
    if (ctx->r18 == 0) {
        // 0x8004B404: addiu       $t7, $t7, 0x1
        ctx->r15 = ADD32(ctx->r15, 0X1);
            goto L_8004B5C8;
    }
    // 0x8004B404: addiu       $t7, $t7, 0x1
    ctx->r15 = ADD32(ctx->r15, 0X1);
    // 0x8004B408: lhu         $t0, 0x6FC0($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X6FC0);
    // 0x8004B40C: beq         $t0, $t4, L_8004B620
    if (ctx->r8 == ctx->r12) {
        // 0x8004B410: sll         $v0, $t0, 1
        ctx->r2 = S32(ctx->r8 << 1);
            goto L_8004B620;
    }
    // 0x8004B410: sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8 << 1);
    // 0x8004B414: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8004B418: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004B41C: addu        $a3, $v0, $t1
    ctx->r7 = ADD32(ctx->r2, ctx->r9);
    // 0x8004B420: lhu         $a2, 0x2($a3)
    ctx->r6 = MEM_HU(ctx->r7, 0X2);
    // 0x8004B424: beq         $a2, $t4, L_8004B440
    if (ctx->r6 == ctx->r12) {
        // 0x8004B428: sll         $v0, $a2, 1
        ctx->r2 = S32(ctx->r6 << 1);
            goto L_8004B440;
    }
    // 0x8004B428: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x8004B42C: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8004B430: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004B434: lhu         $v1, 0x0($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X0);
    // 0x8004B438: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8004B43C: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
L_8004B440:
    // 0x8004B440: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
    // 0x8004B444: lhu         $a2, 0x0($v1)
    ctx->r6 = MEM_HU(ctx->r3, 0X0);
    // 0x8004B448: beq         $a2, $t4, L_8004B488
    if (ctx->r6 == ctx->r12) {
        // 0x8004B44C: sll         $v0, $a2, 1
        ctx->r2 = S32(ctx->r6 << 1);
            goto L_8004B488;
    }
    // 0x8004B44C: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x8004B450: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8004B454: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004B458: lhu         $v1, 0x2($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X2);
    // 0x8004B45C: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8004B460: j           L_8004B490
    // 0x8004B464: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
        goto L_8004B490;
    // 0x8004B464: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
L_8004B468:
    // 0x8004B468: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8004B46C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004B470: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8004B474: sh          $t0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r8;
    // 0x8004B478: sh          $a2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r6;
    // 0x8004B47C: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // 0x8004B480: j           L_8004B4FC
    // 0x8004B484: sh          $a2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r6;
        goto L_8004B4FC;
    // 0x8004B484: sh          $a2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r6;
L_8004B488:
    // 0x8004B488: lhu         $v0, 0x2($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X2);
    // 0x8004B48C: sh          $v0, 0x6FC0($s1)
    MEM_H(0X6FC0, ctx->r17) = ctx->r2;
L_8004B490:
    // 0x8004B490: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
    // 0x8004B494: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8004B498: lhu         $a2, 0x0($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X0);
    // 0x8004B49C: beq         $a2, $t4, L_8004B584
    if (ctx->r6 == ctx->r12) {
        // 0x8004B4A0: sll         $v0, $t0, 1
        ctx->r2 = S32(ctx->r8 << 1);
            goto L_8004B584;
    }
    // 0x8004B4A0: sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8 << 1);
    // 0x8004B4A4: andi        $a2, $a2, 0x7FFF
    ctx->r6 = ctx->r6 & 0X7FFF;
    // 0x8004B4A8: sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6 << 1);
    // 0x8004B4AC: addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
    // 0x8004B4B0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004B4B4: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8004B4B8: lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4);
    // 0x8004B4BC: beq         $v0, $a1, L_8004B4FC
    if (ctx->r2 == ctx->r5) {
        // 0x8004B4C0: addu        $v0, $v1, $a2
        ctx->r2 = ADD32(ctx->r3, ctx->r6);
            goto L_8004B4FC;
    }
    // 0x8004B4C0: addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
    // 0x8004B4C4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_8004B4C8:
    // 0x8004B4C8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004B4CC: addu        $v1, $v0, $t1
    ctx->r3 = ADD32(ctx->r2, ctx->r9);
    // 0x8004B4D0: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x8004B4D4: beql        $v0, $t4, L_8004B468
    if (ctx->r2 == ctx->r12) {
        // 0x8004B4D8: sll         $v0, $t0, 1
        ctx->r2 = S32(ctx->r8 << 1);
            goto L_8004B468;
    }
    goto skip_6;
    // 0x8004B4D8: sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8 << 1);
    skip_6:
    // 0x8004B4DC: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8004B4E0: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8004B4E4: addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
    // 0x8004B4E8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004B4EC: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8004B4F0: lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4);
    // 0x8004B4F4: bne         $v0, $a3, L_8004B4C8
    if (ctx->r2 != ctx->r7) {
        // 0x8004B4F8: addu        $v0, $v1, $a2
        ctx->r2 = ADD32(ctx->r3, ctx->r6);
            goto L_8004B4C8;
    }
    // 0x8004B4F8: addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
L_8004B4FC:
    // 0x8004B4FC: beq         $a2, $t4, L_8004B5A4
    if (ctx->r6 == ctx->r12) {
        // 0x8004B500: sll         $v0, $t0, 1
        ctx->r2 = S32(ctx->r8 << 1);
            goto L_8004B5A4;
    }
    // 0x8004B500: sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8 << 1);
    // 0x8004B504: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8004B508: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004B50C: sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6 << 1);
    // 0x8004B510: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8004B514: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8004B518: addu        $a3, $v1, $t1
    ctx->r7 = ADD32(ctx->r3, ctx->r9);
    // 0x8004B51C: lhu         $v1, 0x0($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X0);
    // 0x8004B520: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8004B524: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x8004B528: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x8004B52C: beq         $v1, $t4, L_8004B550
    if (ctx->r3 == ctx->r12) {
        // 0x8004B530: nop
    
            goto L_8004B550;
    }
    // 0x8004B530: nop

    // 0x8004B534: lhu         $v1, 0x0($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X0);
    // 0x8004B538: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004B53C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004B540: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004B544: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8004B548: j           L_8004B55C
    // 0x8004B54C: sh          $t0, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r8;
        goto L_8004B55C;
    // 0x8004B54C: sh          $t0, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r8;
L_8004B550:
    // 0x8004B550: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
    // 0x8004B554: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8004B558: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
L_8004B55C:
    // 0x8004B55C: sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8 << 1);
    // 0x8004B560: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8004B564: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004B568: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8004B56C: sh          $a2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r6;
    // 0x8004B570: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x8004B574: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8004B578: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004B57C: j           L_8004B5A0
    // 0x8004B580: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
        goto L_8004B5A0;
    // 0x8004B580: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
L_8004B584:
    // 0x8004B584: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8004B588: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004B58C: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8004B590: sh          $a2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r6;
    // 0x8004B594: sh          $a2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r6;
    // 0x8004B598: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
    // 0x8004B59C: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
L_8004B5A0:
    // 0x8004B5A0: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
L_8004B5A4:
    // 0x8004B5A4: sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8 << 1);
    // 0x8004B5A8: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8004B5AC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004B5B0: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8004B5B4: sh          $a1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r5;
    // 0x8004B5B8: sh          $t5, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r13;
    // 0x8004B5BC: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x8004B5C0: addiu       $t3, $t3, 0x2
    ctx->r11 = ADD32(ctx->r11, 0X2);
L_8004B5C4:
    // 0x8004B5C4: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
L_8004B5C8:
    // 0x8004B5C8: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8004B5CC: slt         $v0, $t8, $t2
    ctx->r2 = SIGNED(ctx->r24) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8004B5D0: beq         $v0, $zero, L_8004B324
    if (ctx->r2 == 0) {
        // 0x8004B5D4: nop
    
            goto L_8004B324;
    }
    // 0x8004B5D4: nop

L_8004B5D8:
    // 0x8004B5D8: addiu       $t6, $t6, 0x1
    ctx->r14 = ADD32(ctx->r14, 0X1);
    // 0x8004B5DC: slt         $v0, $s0, $t6
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8004B5E0: beq         $v0, $zero, L_8004B2E0
    if (ctx->r2 == 0) {
        // 0x8004B5E4: nop
    
            goto L_8004B2E0;
    }
    // 0x8004B5E4: nop

L_8004B5E8:
    // 0x8004B5E8: bne         $s2, $zero, L_8004B624
    if (ctx->r18 != 0) {
        // 0x8004B5EC: addu        $v0, $t7, $zero
        ctx->r2 = ADD32(ctx->r15, 0);
            goto L_8004B624;
    }
    // 0x8004B5EC: addu        $v0, $t7, $zero
    ctx->r2 = ADD32(ctx->r15, 0);
    // 0x8004B5F0: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8004B5F4: add.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f4.fl;
    // 0x8004B5F8: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8004B5FC: add.s       $f6, $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f6.fl;
    // 0x8004B600: lwc1        $f2, 0x18($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8004B604: add.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x8004B608: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8004B60C: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8004B610: swc1        $f4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f4.u32l;
    // 0x8004B614: swc1        $f6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f6.u32l;
    // 0x8004B618: swc1        $f2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f2.u32l;
    // 0x8004B61C: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
L_8004B620:
    // 0x8004B620: addu        $v0, $t7, $zero
    ctx->r2 = ADD32(ctx->r15, 0);
L_8004B624:
    // 0x8004B624: lw          $s4, 0x10($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X10);
    // 0x8004B628: lw          $s3, 0xC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XC);
    // 0x8004B62C: lw          $s2, 0x8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X8);
    // 0x8004B630: lw          $s1, 0x4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4);
    // 0x8004B634: lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X0);
    // 0x8004B638: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8004B63C: jr          $ra
    // 0x8004B640: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8004B640: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8004B644(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004B644: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8004B648: sdc1        $f30, 0x30($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X30, ctx->r29);
    // 0x8004B64C: sdc1        $f28, 0x28($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X28, ctx->r29);
    // 0x8004B650: sdc1        $f26, 0x20($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X20, ctx->r29);
    // 0x8004B654: sdc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X18, ctx->r29);
    // 0x8004B658: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x8004B65C: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x8004B660: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x8004B664: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x8004B668: lbu         $v1, 0x2($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X2);
    // 0x8004B66C: lwc1        $f30, 0x50($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8004B670: mtc1        $v0, $f12
    ctx->f12.u32l = ctx->r2;
    // 0x8004B674: cvt.s.w     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.fl = CVT_S_W(ctx->f12.u32l);
    // 0x8004B678: lbu         $v0, 0x1($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X1);
    // 0x8004B67C: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x8004B680: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004B684: mtc1        $v0, $f14
    ctx->f14.u32l = ctx->r2;
    // 0x8004B688: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x8004B68C: beq         $t0, $zero, L_8004B7A8
    if (ctx->r8 == 0) {
        // 0x8004B690: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_8004B7A8;
    }
    // 0x8004B690: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8004B694: lwc1        $f20, 0x8($a1)
    ctx->f20.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8004B698: lwc1        $f24, 0x0($a1)
    ctx->f24.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8004B69C: lwc1        $f22, 0x4($a1)
    ctx->f22.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8004B6A0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004B6A4: lwc1        $f28, -0x5790($at)
    ctx->f28.u32l = MEM_W(ctx->r1, -0X5790);
    // 0x8004B6A8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004B6AC: lwc1        $f26, -0x578C($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X578C);
    // 0x8004B6B0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004B6B4: lwc1        $f18, -0x5788($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5788);
    // 0x8004B6B8: swc1        $f20, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f20.u32l;
L_8004B6BC:
    // 0x8004B6BC: lwc1        $f0, 0x10($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X10);
    // 0x8004B6C0: lwc1        $f20, 0x48($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8004B6C4: sub.s       $f8, $f20, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8004B6C8: mul.s       $f10, $f24, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f8.fl);
    // 0x8004B6CC: nop

    // 0x8004B6D0: mul.s       $f8, $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8004B6D4: lwc1        $f0, 0x14($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X14);
    // 0x8004B6D8: lwc1        $f20, 0x4C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8004B6DC: sub.s       $f2, $f20, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8004B6E0: mul.s       $f4, $f22, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x8004B6E4: nop

    // 0x8004B6E8: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8004B6EC: lwc1        $f0, 0x18($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X18);
    // 0x8004B6F0: sub.s       $f2, $f30, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f30.fl - ctx->f0.fl;
    // 0x8004B6F4: lwc1        $f20, 0x0($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8004B6F8: mul.s       $f0, $f20, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8004B6FC: nop

    // 0x8004B700: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8004B704: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8004B708: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8004B70C: add.s       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8004B710: c.lt.s      $f28, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f28.fl < ctx->f10.fl;
    // 0x8004B714: nop

    // 0x8004B718: bc1f        L_8004B79C
    if (!c1cs) {
        // 0x8004B71C: add.s       $f8, $f8, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f2.fl;
            goto L_8004B79C;
    }
    // 0x8004B71C: add.s       $f8, $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8004B720: lwc1        $f2, 0x1C($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x8004B724: mul.s       $f0, $f2, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8004B728: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8004B72C: nop

    // 0x8004B730: bc1f        L_8004B79C
    if (!c1cs) {
        // 0x8004B734: nop
    
            goto L_8004B79C;
    }
    // 0x8004B734: nop

    // 0x8004B738: c.lt.s      $f8, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f8.fl < ctx->f26.fl;
    // 0x8004B73C: nop

    // 0x8004B740: bc1f        L_8004B764
    if (!c1cs) {
        // 0x8004B744: nop
    
            goto L_8004B764;
    }
    // 0x8004B744: nop

    // 0x8004B748: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8004B74C: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x8004B750: lwc1        $f0, 0x4($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8004B754: add.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x8004B758: lwc1        $f0, 0x8($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8004B75C: j           L_8004B79C
    // 0x8004B760: add.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f0.fl;
        goto L_8004B79C;
    // 0x8004B760: add.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f0.fl;
L_8004B764:
    // 0x8004B764: sqrt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = sqrtf(ctx->f8.fl);
    // 0x8004B768: div.s       $f0, $f18, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8004B76C: div.s       $f2, $f18, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8004B770: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004B774: mul.s       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8004B778: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8004B77C: mul.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8004B780: lwc1        $f2, 0x4($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8004B784: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8004B788: lwc1        $f0, 0x8($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8004B78C: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8004B790: add.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8004B794: add.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x8004B798: add.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f0.fl;
L_8004B79C:
    // 0x8004B79C: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x8004B7A0: bne         $t0, $zero, L_8004B6BC
    if (ctx->r8 != 0) {
        // 0x8004B7A4: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_8004B6BC;
    }
    // 0x8004B7A4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_8004B7A8:
    // 0x8004B7A8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004B7AC: lwc1        $f0, -0x5784($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5784);
    // 0x8004B7B0: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x8004B7B4: nop

    // 0x8004B7B8: bc1f        L_8004B7C8
    if (!c1cs) {
        // 0x8004B7BC: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8004B7C8;
    }
    // 0x8004B7BC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8004B7C0: j           L_8004B828
    // 0x8004B7C4: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
        goto L_8004B828;
    // 0x8004B7C4: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_8004B7C8:
    // 0x8004B7C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004B7CC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8004B7D0: nop

    // 0x8004B7D4: bc1f        L_8004B7E4
    if (!c1cs) {
        // 0x8004B7D8: nop
    
            goto L_8004B7E4;
    }
    // 0x8004B7D8: nop

    // 0x8004B7DC: j           L_8004B820
    // 0x8004B7E0: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
        goto L_8004B820;
    // 0x8004B7E0: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
L_8004B7E4:
    // 0x8004B7E4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004B7E8: lwc1        $f0, -0x5780($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5780);
    // 0x8004B7EC: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x8004B7F0: nop

    // 0x8004B7F4: bc1tl       L_8004B80C
    if (c1cs) {
        // 0x8004B7F8: sub.s       $f0, $f12, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f0.fl;
            goto L_8004B80C;
    }
    goto skip_0;
    // 0x8004B7F8: sub.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f0.fl;
    skip_0:
    // 0x8004B7FC: trunc.w.s   $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8004B800: mfc1        $v1, $f20
    ctx->r3 = (int32_t)ctx->f20.u32l;
    // 0x8004B804: j           L_8004B820
    // 0x8004B808: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
        goto L_8004B820;
    // 0x8004B808: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
L_8004B80C:
    // 0x8004B80C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8004B810: trunc.w.s   $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004B814: mfc1        $v1, $f20
    ctx->r3 = (int32_t)ctx->f20.u32l;
    // 0x8004B818: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8004B81C: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
L_8004B820:
    // 0x8004B820: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004B824: lwc1        $f0, -0x577C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X577C);
L_8004B828:
    // 0x8004B828: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x8004B82C: nop

    // 0x8004B830: bc1f        L_8004B840
    if (!c1cs) {
        // 0x8004B834: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8004B840;
    }
    // 0x8004B834: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8004B838: j           L_8004B898
    // 0x8004B83C: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
        goto L_8004B898;
    // 0x8004B83C: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
L_8004B840:
    // 0x8004B840: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004B844: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x8004B848: nop

    // 0x8004B84C: bc1f        L_8004B85C
    if (!c1cs) {
        // 0x8004B850: nop
    
            goto L_8004B85C;
    }
    // 0x8004B850: nop

    // 0x8004B854: j           L_8004B898
    // 0x8004B858: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
        goto L_8004B898;
    // 0x8004B858: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
L_8004B85C:
    // 0x8004B85C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004B860: lwc1        $f0, -0x5778($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5778);
    // 0x8004B864: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x8004B868: nop

    // 0x8004B86C: bc1tl       L_8004B884
    if (c1cs) {
        // 0x8004B870: sub.s       $f0, $f14, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f0.fl;
            goto L_8004B884;
    }
    goto skip_1;
    // 0x8004B870: sub.s       $f0, $f14, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f0.fl;
    skip_1:
    // 0x8004B874: trunc.w.s   $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    ctx->f20.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8004B878: mfc1        $v1, $f20
    ctx->r3 = (int32_t)ctx->f20.u32l;
    // 0x8004B87C: j           L_8004B898
    // 0x8004B880: sb          $v1, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r3;
        goto L_8004B898;
    // 0x8004B880: sb          $v1, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r3;
L_8004B884:
    // 0x8004B884: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8004B888: trunc.w.s   $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004B88C: mfc1        $v1, $f20
    ctx->r3 = (int32_t)ctx->f20.u32l;
    // 0x8004B890: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8004B894: sb          $v1, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r3;
L_8004B898:
    // 0x8004B898: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004B89C: lwc1        $f0, -0x5774($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5774);
    // 0x8004B8A0: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x8004B8A4: nop

    // 0x8004B8A8: bc1f        L_8004B8B8
    if (!c1cs) {
        // 0x8004B8AC: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8004B8B8;
    }
    // 0x8004B8AC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8004B8B0: j           L_8004B910
    // 0x8004B8B4: sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
        goto L_8004B910;
    // 0x8004B8B4: sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
L_8004B8B8:
    // 0x8004B8B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004B8BC: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8004B8C0: nop

    // 0x8004B8C4: bc1f        L_8004B8D4
    if (!c1cs) {
        // 0x8004B8C8: nop
    
            goto L_8004B8D4;
    }
    // 0x8004B8C8: nop

    // 0x8004B8CC: j           L_8004B910
    // 0x8004B8D0: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
        goto L_8004B910;
    // 0x8004B8D0: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
L_8004B8D4:
    // 0x8004B8D4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004B8D8: lwc1        $f0, -0x5770($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5770);
    // 0x8004B8DC: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x8004B8E0: nop

    // 0x8004B8E4: bc1tl       L_8004B8FC
    if (c1cs) {
        // 0x8004B8E8: sub.s       $f0, $f16, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f0.fl;
            goto L_8004B8FC;
    }
    goto skip_2;
    // 0x8004B8E8: sub.s       $f0, $f16, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f0.fl;
    skip_2:
    // 0x8004B8EC: trunc.w.s   $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8004B8F0: mfc1        $v1, $f20
    ctx->r3 = (int32_t)ctx->f20.u32l;
    // 0x8004B8F4: j           L_8004B910
    // 0x8004B8F8: sb          $v1, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r3;
        goto L_8004B910;
    // 0x8004B8F8: sb          $v1, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r3;
L_8004B8FC:
    // 0x8004B8FC: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8004B900: trunc.w.s   $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004B904: mfc1        $v1, $f20
    ctx->r3 = (int32_t)ctx->f20.u32l;
    // 0x8004B908: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8004B90C: sb          $v1, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r3;
L_8004B910:
    // 0x8004B910: ldc1        $f30, 0x30($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X30);
    // 0x8004B914: ldc1        $f28, 0x28($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X28);
    // 0x8004B918: ldc1        $f26, 0x20($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X20);
    // 0x8004B91C: ldc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X18);
    // 0x8004B920: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x8004B924: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x8004B928: jr          $ra
    // 0x8004B92C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8004B92C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8004B930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004B930: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8004B934: sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // 0x8004B938: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x8004B93C: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x8004B940: sw          $s6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r22;
    // 0x8004B944: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // 0x8004B948: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x8004B94C: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x8004B950: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x8004B954: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x8004B958: sdc1        $f30, 0xA8($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0XA8, ctx->r29);
    // 0x8004B95C: sdc1        $f28, 0xA0($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0XA0, ctx->r29);
    // 0x8004B960: sdc1        $f26, 0x98($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X98, ctx->r29);
    // 0x8004B964: sdc1        $f24, 0x90($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X90, ctx->r29);
    // 0x8004B968: sdc1        $f22, 0x88($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X88, ctx->r29);
    // 0x8004B96C: sdc1        $f20, 0x80($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X80, ctx->r29);
    // 0x8004B970: lhu         $v1, 0x14($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0X14);
    // 0x8004B974: andi        $v0, $v1, 0x20
    ctx->r2 = ctx->r3 & 0X20;
    // 0x8004B978: beq         $v0, $zero, L_8004BA50
    if (ctx->r2 == 0) {
        // 0x8004B97C: andi        $v0, $v1, 0x40
        ctx->r2 = ctx->r3 & 0X40;
            goto L_8004BA50;
    }
    // 0x8004B97C: andi        $v0, $v1, 0x40
    ctx->r2 = ctx->r3 & 0X40;
    // 0x8004B980: beql        $v0, $zero, L_8004B998
    if (ctx->r2 == 0) {
        // 0x8004B984: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_8004B998;
    }
    goto skip_0;
    // 0x8004B984: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    skip_0:
    // 0x8004B988: jal         0x80046214
    // 0x8004B98C: nop

    func_80046214(rdram, ctx);
        goto after_0;
    // 0x8004B98C: nop

    after_0:
    // 0x8004B990: j           L_8004C294
    // 0x8004B994: sw          $v0, 0x48($s5)
    MEM_W(0X48, ctx->r21) = ctx->r2;
        goto L_8004C294;
    // 0x8004B994: sw          $v0, 0x48($s5)
    MEM_W(0X48, ctx->r21) = ctx->r2;
L_8004B998:
    // 0x8004B998: lhu         $v1, 0x8($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0X8);
    // 0x8004B99C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004B9A0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004B9A4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8004B9A8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004B9AC: lw          $v1, 0x7A5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X7A5C);
    // 0x8004B9B0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8004B9B4: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x8004B9B8: lhu         $v1, 0x14($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X14);
    // 0x8004B9BC: andi        $v0, $v1, 0x40
    ctx->r2 = ctx->r3 & 0X40;
    // 0x8004B9C0: bne         $v0, $zero, L_8004BA48
    if (ctx->r2 != 0) {
        // 0x8004B9C4: addiu       $v0, $s0, 0x54
        ctx->r2 = ADD32(ctx->r16, 0X54);
            goto L_8004BA48;
    }
    // 0x8004B9C4: addiu       $v0, $s0, 0x54
    ctx->r2 = ADD32(ctx->r16, 0X54);
    // 0x8004B9C8: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x8004B9CC: beql        $v1, $zero, L_8004C294
    if (ctx->r3 == 0) {
        // 0x8004B9D0: sw          $v0, 0x48($s5)
        MEM_W(0X48, ctx->r21) = ctx->r2;
            goto L_8004C294;
    }
    goto skip_1;
    // 0x8004B9D0: sw          $v0, 0x48($s5)
    MEM_W(0X48, ctx->r21) = ctx->r2;
    skip_1:
    // 0x8004B9D4: lbu         $v0, 0x30($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X30);
    // 0x8004B9D8: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x8004B9DC: beq         $v0, $zero, L_8004B9F8
    if (ctx->r2 == 0) {
        // 0x8004B9E0: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8004B9F8;
    }
    // 0x8004B9E0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8004B9E4: bne         $v1, $v0, L_8004B9F8
    if (ctx->r3 != ctx->r2) {
        // 0x8004B9E8: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8004B9F8;
    }
    // 0x8004B9E8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004B9EC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8004B9F0: jal         0x80049814
    // 0x8004B9F4: addiu       $a1, $a1, 0x6DC0
    ctx->r5 = ADD32(ctx->r5, 0X6DC0);
    func_80049814(rdram, ctx);
        goto after_1;
    // 0x8004B9F4: addiu       $a1, $a1, 0x6DC0
    ctx->r5 = ADD32(ctx->r5, 0X6DC0);
    after_1:
L_8004B9F8:
    // 0x8004B9F8: lbu         $v0, 0x30($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X30);
    // 0x8004B9FC: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8004BA00: beq         $v0, $zero, L_8004BA24
    if (ctx->r2 == 0) {
        // 0x8004BA04: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_8004BA24;
    }
    // 0x8004BA04: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8004BA08: lhu         $v0, 0x14($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X14);
    // 0x8004BA0C: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x8004BA10: bne         $v0, $v1, L_8004BA24
    if (ctx->r2 != ctx->r3) {
        // 0x8004BA14: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8004BA24;
    }
    // 0x8004BA14: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004BA18: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8004BA1C: jal         0x80049BBC
    // 0x8004BA20: addiu       $a1, $a1, 0x6DC0
    ctx->r5 = ADD32(ctx->r5, 0X6DC0);
    func_80049BBC(rdram, ctx);
        goto after_2;
    // 0x8004BA20: addiu       $a1, $a1, 0x6DC0
    ctx->r5 = ADD32(ctx->r5, 0X6DC0);
    after_2:
L_8004BA24:
    // 0x8004BA24: lbu         $v0, 0x30($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X30);
    // 0x8004BA28: bne         $v0, $zero, L_8004BA3C
    if (ctx->r2 != 0) {
        // 0x8004BA2C: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8004BA3C;
    }
    // 0x8004BA2C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004BA30: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8004BA34: jal         0x80049FB8
    // 0x8004BA38: addiu       $a1, $a1, 0x6DC0
    ctx->r5 = ADD32(ctx->r5, 0X6DC0);
    func_80049FB8(rdram, ctx);
        goto after_3;
    // 0x8004BA38: addiu       $a1, $a1, 0x6DC0
    ctx->r5 = ADD32(ctx->r5, 0X6DC0);
    after_3:
L_8004BA3C:
    // 0x8004BA3C: jal         0x8004AA94
    // 0x8004BA40: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8004AA94(rdram, ctx);
        goto after_4;
    // 0x8004BA40: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x8004BA44: addiu       $v0, $s0, 0x54
    ctx->r2 = ADD32(ctx->r16, 0X54);
L_8004BA48:
    // 0x8004BA48: j           L_8004C294
    // 0x8004BA4C: sw          $v0, 0x48($s5)
    MEM_W(0X48, ctx->r21) = ctx->r2;
        goto L_8004C294;
    // 0x8004BA4C: sw          $v0, 0x48($s5)
    MEM_W(0X48, ctx->r21) = ctx->r2;
L_8004BA50:
    // 0x8004BA50: bne         $v0, $zero, L_8004BAD8
    if (ctx->r2 != 0) {
        // 0x8004BA54: andi        $v1, $v1, 0x3
        ctx->r3 = ctx->r3 & 0X3;
            goto L_8004BAD8;
    }
    // 0x8004BA54: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x8004BA58: lbu         $a0, 0x30($s5)
    ctx->r4 = MEM_BU(ctx->r21, 0X30);
    // 0x8004BA5C: sltu        $v0, $a0, $v1
    ctx->r2 = ctx->r4 < ctx->r3 ? 1 : 0;
    // 0x8004BA60: beq         $v0, $zero, L_8004BAD8
    if (ctx->r2 == 0) {
        // 0x8004BA64: sltiu       $v0, $a0, 0x3
        ctx->r2 = ctx->r4 < 0X3 ? 1 : 0;
            goto L_8004BAD8;
    }
    // 0x8004BA64: sltiu       $v0, $a0, 0x3
    ctx->r2 = ctx->r4 < 0X3 ? 1 : 0;
    // 0x8004BA68: beq         $v0, $zero, L_8004BA84
    if (ctx->r2 == 0) {
        // 0x8004BA6C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8004BA84;
    }
    // 0x8004BA6C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8004BA70: bne         $v1, $v0, L_8004BA84
    if (ctx->r3 != ctx->r2) {
        // 0x8004BA74: addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
            goto L_8004BA84;
    }
    // 0x8004BA74: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x8004BA78: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8004BA7C: jal         0x80049814
    // 0x8004BA80: addiu       $a1, $a1, 0x6DC0
    ctx->r5 = ADD32(ctx->r5, 0X6DC0);
    func_80049814(rdram, ctx);
        goto after_5;
    // 0x8004BA80: addiu       $a1, $a1, 0x6DC0
    ctx->r5 = ADD32(ctx->r5, 0X6DC0);
    after_5:
L_8004BA84:
    // 0x8004BA84: lbu         $v0, 0x30($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X30);
    // 0x8004BA88: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8004BA8C: beq         $v0, $zero, L_8004BAB0
    if (ctx->r2 == 0) {
        // 0x8004BA90: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_8004BAB0;
    }
    // 0x8004BA90: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8004BA94: lhu         $v0, 0x14($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X14);
    // 0x8004BA98: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x8004BA9C: bne         $v0, $v1, L_8004BAB0
    if (ctx->r2 != ctx->r3) {
        // 0x8004BAA0: addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
            goto L_8004BAB0;
    }
    // 0x8004BAA0: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x8004BAA4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8004BAA8: jal         0x80049BBC
    // 0x8004BAAC: addiu       $a1, $a1, 0x6DC0
    ctx->r5 = ADD32(ctx->r5, 0X6DC0);
    func_80049BBC(rdram, ctx);
        goto after_6;
    // 0x8004BAAC: addiu       $a1, $a1, 0x6DC0
    ctx->r5 = ADD32(ctx->r5, 0X6DC0);
    after_6:
L_8004BAB0:
    // 0x8004BAB0: lbu         $v0, 0x30($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X30);
    // 0x8004BAB4: bne         $v0, $zero, L_8004BAC8
    if (ctx->r2 != 0) {
        // 0x8004BAB8: addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
            goto L_8004BAC8;
    }
    // 0x8004BAB8: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x8004BABC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8004BAC0: jal         0x80049FB8
    // 0x8004BAC4: addiu       $a1, $a1, 0x6DC0
    ctx->r5 = ADD32(ctx->r5, 0X6DC0);
    func_80049FB8(rdram, ctx);
        goto after_7;
    // 0x8004BAC4: addiu       $a1, $a1, 0x6DC0
    ctx->r5 = ADD32(ctx->r5, 0X6DC0);
    after_7:
L_8004BAC8:
    // 0x8004BAC8: jal         0x8004AA94
    // 0x8004BACC: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    func_8004AA94(rdram, ctx);
        goto after_8;
    // 0x8004BACC: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_8:
    // 0x8004BAD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004BAD4: sb          $v0, 0x57($s5)
    MEM_B(0X57, ctx->r21) = ctx->r2;
L_8004BAD8:
    // 0x8004BAD8: lhu         $v0, 0x14($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X14);
    // 0x8004BADC: andi        $v0, $v0, 0xC0
    ctx->r2 = ctx->r2 & 0XC0;
    // 0x8004BAE0: beq         $v0, $zero, L_8004BAF4
    if (ctx->r2 == 0) {
        // 0x8004BAE4: addiu       $s4, $s5, 0x54
        ctx->r20 = ADD32(ctx->r21, 0X54);
            goto L_8004BAF4;
    }
    // 0x8004BAE4: addiu       $s4, $s5, 0x54
    ctx->r20 = ADD32(ctx->r21, 0X54);
    // 0x8004BAE8: jal         0x80046214
    // 0x8004BAEC: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    func_80046214(rdram, ctx);
        goto after_9;
    // 0x8004BAEC: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_9:
    // 0x8004BAF0: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
L_8004BAF4:
    // 0x8004BAF4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8004BAF8: lhu         $v1, 0x1E($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0X1E);
    // 0x8004BAFC: lw          $a0, 0x6FCC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6FCC);
    // 0x8004BB00: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004BB04: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004BB08: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004BB0C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004BB10: lhu         $a1, 0x2($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X2);
    // 0x8004BB14: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8004BB18: beq         $a1, $v0, L_8004BB3C
    if (ctx->r5 == ctx->r2) {
        // 0x8004BB1C: sll         $v0, $a1, 1
        ctx->r2 = S32(ctx->r5 << 1);
            goto L_8004BB3C;
    }
    // 0x8004BB1C: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8004BB20: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8004BB24: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004BB28: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004BB2C: lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X4);
    // 0x8004BB30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004BB34: beq         $v1, $v0, L_8004BB44
    if (ctx->r3 == ctx->r2) {
        // 0x8004BB38: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004BB44;
    }
    // 0x8004BB38: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_8004BB3C:
    // 0x8004BB3C: j           L_8004C294
    // 0x8004BB40: sw          $s4, 0x48($s5)
    MEM_W(0X48, ctx->r21) = ctx->r20;
        goto L_8004C294;
    // 0x8004BB40: sw          $s4, 0x48($s5)
    MEM_W(0X48, ctx->r21) = ctx->r20;
L_8004BB44:
    // 0x8004BB44: lw          $v1, 0x7A74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X7A74);
    // 0x8004BB48: bgtz        $v1, L_8004BB5C
    if (SIGNED(ctx->r3) > 0) {
        // 0x8004BB4C: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_8004BB5C;
    }
    // 0x8004BB4C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8004BB50: addiu       $v0, $s5, 0x54
    ctx->r2 = ADD32(ctx->r21, 0X54);
    // 0x8004BB54: j           L_8004C294
    // 0x8004BB58: sw          $v0, 0x48($s5)
    MEM_W(0X48, ctx->r21) = ctx->r2;
        goto L_8004C294;
    // 0x8004BB58: sw          $v0, 0x48($s5)
    MEM_W(0X48, ctx->r21) = ctx->r2;
L_8004BB5C:
    // 0x8004BB5C: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x8004BB60: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x8004BB64: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8004BB68: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // 0x8004BB6C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8004BB70: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8004BB74: sw          $v1, 0x7A74($v0)
    MEM_W(0X7A74, ctx->r2) = ctx->r3;
    // 0x8004BB78: sllv        $v0, $v1, $t1
    ctx->r2 = S32(ctx->r3 << (ctx->r9 & 31));
    // 0x8004BB7C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004BB80: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8004BB84: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004BB88: lw          $v1, 0x7A50($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X7A50);
    // 0x8004BB8C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004BB90: addu        $s3, $v1, $v0
    ctx->r19 = ADD32(ctx->r3, ctx->r2);
    // 0x8004BB94: sw          $s3, 0x48($s5)
    MEM_W(0X48, ctx->r21) = ctx->r19;
    // 0x8004BB98: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
L_8004BB9C:
    // 0x8004BB9C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8004BBA0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004BBA4: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8004BBA8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8004BBAC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8004BBB0: sw          $v1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r3;
    // 0x8004BBB4: lhu         $a1, 0x2($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X2);
    // 0x8004BBB8: beq         $a1, $t2, L_8004BBE4
    if (ctx->r5 == ctx->r10) {
        // 0x8004BBBC: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_8004BBE4;
    }
    // 0x8004BBBC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8004BBC0: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8004BBC4: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8004BBC8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004BBCC: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8004BBD0: lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4);
    // 0x8004BBD4: bne         $v0, $t1, L_8004BBE4
    if (ctx->r2 != ctx->r9) {
        // 0x8004BBD8: slti        $v0, $a2, 0x8
        ctx->r2 = SIGNED(ctx->r6) < 0X8 ? 1 : 0;
            goto L_8004BBE4;
    }
    // 0x8004BBD8: slti        $v0, $a2, 0x8
    ctx->r2 = SIGNED(ctx->r6) < 0X8 ? 1 : 0;
    // 0x8004BBDC: bne         $v0, $zero, L_8004BB9C
    if (ctx->r2 != 0) {
        // 0x8004BBE0: sll         $v0, $a1, 1
        ctx->r2 = S32(ctx->r5 << 1);
            goto L_8004BB9C;
    }
    // 0x8004BBE0: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
L_8004BBE4:
    // 0x8004BBE4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8004BBE8: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8004BBEC: addiu       $s1, $sp, 0x20
    ctx->r17 = ADD32(ctx->r29, 0X20);
    // 0x8004BBF0: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x8004BBF4: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004BBF8: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // 0x8004BBFC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8004BC00: lh          $v0, 0x18($s5)
    ctx->r2 = MEM_H(ctx->r21, 0X18);
    // 0x8004BC04: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004BC08: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004BC0C: lwc1        $f2, -0x576C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X576C);
    // 0x8004BC10: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004BC14: lwc1        $f22, -0x5768($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X5768);
    // 0x8004BC18: mtc1        $v0, $f26
    ctx->f26.u32l = ctx->r2;
    // 0x8004BC1C: cvt.s.w     $f26, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    ctx->f26.fl = CVT_S_W(ctx->f26.u32l);
    // 0x8004BC20: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004BC24: add.s       $f6, $f26, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f26.fl + ctx->f4.fl;
    // 0x8004BC28: lwc1        $f0, 0x6DD0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X6DD0);
    // 0x8004BC2C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004BC30: lwc1        $f20, -0x5764($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X5764);
    // 0x8004BC34: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8004BC38: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x8004BC3C: lw          $s2, 0x44($s5)
    ctx->r18 = MEM_W(ctx->r21, 0X44);
    // 0x8004BC40: lh          $t0, 0x1A($s5)
    ctx->r8 = MEM_H(ctx->r21, 0X1A);
    // 0x8004BC44: lhu         $v1, 0xA($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0XA);
    // 0x8004BC48: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x8004BC4C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8004BC50: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004BC54: mul.s       $f28, $f0, $f22
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f28.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8004BC58: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004BC5C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004BC60: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8004BC64: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004BC68: lb          $v1, 0x0($s2)
    ctx->r3 = MEM_B(ctx->r18, 0X0);
    // 0x8004BC6C: add.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8004BC70: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x8004BC74: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x8004BC78: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004BC7C: lw          $v1, 0x7A54($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X7A54);
    // 0x8004BC80: add.s       $f6, $f26, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f26.fl + ctx->f20.fl;
    // 0x8004BC84: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x8004BC88: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8004BC8C: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004BC90: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x8004BC94: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x8004BC98: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004BC9C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004BCA0: jal         0x8004B644
    // 0x8004BCA4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8004B644(rdram, ctx);
        goto after_10;
    // 0x8004BCA4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x8004BCA8: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8004BCAC: addiu       $a0, $s3, 0x10
    ctx->r4 = ADD32(ctx->r19, 0X10);
    // 0x8004BCB0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8004BCB4: lb          $v0, 0x4($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X4);
    // 0x8004BCB8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004BCBC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004BCC0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004BCC4: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004BCC8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004BCCC: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8004BCD0: addiu       $a3, $s4, 0x10
    ctx->r7 = ADD32(ctx->r20, 0X10);
    // 0x8004BCD4: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8004BCD8: jal         0x8004B644
    // 0x8004BCDC: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8004B644(rdram, ctx);
        goto after_11;
    // 0x8004BCDC: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_11:
    // 0x8004BCE0: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8004BCE4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8004BCE8: lb          $v0, 0x14($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X14);
    // 0x8004BCEC: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004BCF0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004BCF4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004BCF8: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004BCFC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004BD00: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004BD04: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8004BD08: addiu       $a0, $s3, 0x50
    ctx->r4 = ADD32(ctx->r19, 0X50);
    // 0x8004BD0C: add.s       $f20, $f6, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x8004BD10: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004BD14: addiu       $a3, $s4, 0x50
    ctx->r7 = ADD32(ctx->r20, 0X50);
    // 0x8004BD18: swc1        $f20, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f20.u32l;
    // 0x8004BD1C: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8004BD20: jal         0x8004B644
    // 0x8004BD24: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8004B644(rdram, ctx);
        goto after_12;
    // 0x8004BD24: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_12:
    // 0x8004BD28: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8004BD2C: addiu       $a0, $s3, 0x60
    ctx->r4 = ADD32(ctx->r19, 0X60);
    // 0x8004BD30: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8004BD34: lb          $v0, 0x18($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X18);
    // 0x8004BD38: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004BD3C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004BD40: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004BD44: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004BD48: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004BD4C: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8004BD50: addiu       $a3, $s4, 0x60
    ctx->r7 = ADD32(ctx->r20, 0X60);
    // 0x8004BD54: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8004BD58: jal         0x8004B644
    // 0x8004BD5C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8004B644(rdram, ctx);
        goto after_13;
    // 0x8004BD5C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x8004BD60: lbu         $v0, 0x30($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X30);
    // 0x8004BD64: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8004BD68: beq         $v0, $zero, L_8004C294
    if (ctx->r2 == 0) {
        // 0x8004BD6C: addiu       $a0, $s3, 0x8
        ctx->r4 = ADD32(ctx->r19, 0X8);
            goto L_8004C294;
    }
    // 0x8004BD6C: addiu       $a0, $s3, 0x8
    ctx->r4 = ADD32(ctx->r19, 0X8);
    // 0x8004BD70: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004BD74: addiu       $a3, $s4, 0x8
    ctx->r7 = ADD32(ctx->r20, 0X8);
    // 0x8004BD78: lhu         $v1, 0xC($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0XC);
    // 0x8004BD7C: add.s       $f30, $f26, $f22
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f30.fl = ctx->f26.fl + ctx->f22.fl;
    // 0x8004BD80: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004BD84: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004BD88: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    // 0x8004BD8C: lb          $v1, 0x2($s2)
    ctx->r3 = MEM_B(ctx->r18, 0X2);
    // 0x8004BD90: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8004BD94: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x8004BD98: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004BD9C: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004BDA0: lw          $v1, 0x7A54($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X7A54);
    // 0x8004BDA4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004BDA8: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8004BDAC: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x8004BDB0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004BDB4: jal         0x8004B644
    // 0x8004BDB8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8004B644(rdram, ctx);
        goto after_14;
    // 0x8004BDB8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_14:
    // 0x8004BDBC: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8004BDC0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8004BDC4: lb          $v0, 0xA($s2)
    ctx->r2 = MEM_B(ctx->r18, 0XA);
    // 0x8004BDC8: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004BDCC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004BDD0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004BDD4: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004BDD8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004BDDC: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004BDE0: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8004BDE4: addiu       $a0, $s3, 0x28
    ctx->r4 = ADD32(ctx->r19, 0X28);
    // 0x8004BDE8: add.s       $f22, $f6, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x8004BDEC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004BDF0: addiu       $a3, $s4, 0x28
    ctx->r7 = ADD32(ctx->r20, 0X28);
    // 0x8004BDF4: swc1        $f22, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f22.u32l;
    // 0x8004BDF8: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x8004BDFC: jal         0x8004B644
    // 0x8004BE00: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8004B644(rdram, ctx);
        goto after_15;
    // 0x8004BE00: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_15:
    // 0x8004BE04: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004BE08: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004BE0C: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    // 0x8004BE10: lb          $v0, 0xC($s2)
    ctx->r2 = MEM_B(ctx->r18, 0XC);
    // 0x8004BE14: addiu       $a0, $s3, 0x30
    ctx->r4 = ADD32(ctx->r19, 0X30);
    // 0x8004BE18: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004BE1C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004BE20: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004BE24: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004BE28: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8004BE2C: addiu       $a3, $s4, 0x30
    ctx->r7 = ADD32(ctx->r20, 0X30);
    // 0x8004BE30: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8004BE34: jal         0x8004B644
    // 0x8004BE38: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8004B644(rdram, ctx);
        goto after_16;
    // 0x8004BE38: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_16:
    // 0x8004BE3C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004BE40: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8004BE44: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004BE48: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8004BE4C: lb          $v0, 0xE($s2)
    ctx->r2 = MEM_B(ctx->r18, 0XE);
    // 0x8004BE50: addiu       $a0, $s3, 0x38
    ctx->r4 = ADD32(ctx->r19, 0X38);
    // 0x8004BE54: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004BE58: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004BE5C: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004BE60: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004BE64: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8004BE68: addiu       $a3, $s4, 0x38
    ctx->r7 = ADD32(ctx->r20, 0X38);
    // 0x8004BE6C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8004BE70: jal         0x8004B644
    // 0x8004BE74: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8004B644(rdram, ctx);
        goto after_17;
    // 0x8004BE74: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_17:
    // 0x8004BE78: addiu       $a0, $s3, 0x58
    ctx->r4 = ADD32(ctx->r19, 0X58);
    // 0x8004BE7C: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    // 0x8004BE80: lb          $v0, 0x16($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X16);
    // 0x8004BE84: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004BE88: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004BE8C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004BE90: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004BE94: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004BE98: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8004BE9C: addiu       $a3, $s4, 0x58
    ctx->r7 = ADD32(ctx->r20, 0X58);
    // 0x8004BEA0: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8004BEA4: jal         0x8004B644
    // 0x8004BEA8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8004B644(rdram, ctx);
        goto after_18;
    // 0x8004BEA8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_18:
    // 0x8004BEAC: lbu         $v0, 0x30($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X30);
    // 0x8004BEB0: bne         $v0, $zero, L_8004C294
    if (ctx->r2 != 0) {
        // 0x8004BEB4: addiu       $a0, $s3, 0x14
        ctx->r4 = ADD32(ctx->r19, 0X14);
            goto L_8004C294;
    }
    // 0x8004BEB4: addiu       $a0, $s3, 0x14
    ctx->r4 = ADD32(ctx->r19, 0X14);
    // 0x8004BEB8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004BEBC: lhu         $a1, 0xE($s5)
    ctx->r5 = MEM_HU(ctx->r21, 0XE);
    // 0x8004BEC0: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8004BEC4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004BEC8: lwc1        $f24, -0x5760($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X5760);
    // 0x8004BECC: addiu       $a3, $s4, 0x14
    ctx->r7 = ADD32(ctx->r20, 0X14);
    // 0x8004BED0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8004BED4: lb          $v1, 0x5($s2)
    ctx->r3 = MEM_B(ctx->r18, 0X5);
    // 0x8004BED8: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8004BEDC: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x8004BEE0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004BEE4: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004BEE8: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8004BEEC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004BEF0: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8004BEF4: lw          $v1, 0x7A54($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X7A54);
    // 0x8004BEF8: add.s       $f22, $f6, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x8004BEFC: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x8004BF00: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004BF04: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x8004BF08: jal         0x8004B644
    // 0x8004BF0C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8004B644(rdram, ctx);
        goto after_19;
    // 0x8004BF0C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_19:
    // 0x8004BF10: add.s       $f24, $f26, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f24.fl = ctx->f26.fl + ctx->f24.fl;
    // 0x8004BF14: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004BF18: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004BF1C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8004BF20: lb          $v0, 0x6($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X6);
    // 0x8004BF24: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004BF28: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004BF2C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004BF30: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004BF34: addiu       $a0, $s3, 0x18
    ctx->r4 = ADD32(ctx->r19, 0X18);
    // 0x8004BF38: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004BF3C: addiu       $a3, $s4, 0x18
    ctx->r7 = ADD32(ctx->r20, 0X18);
    // 0x8004BF40: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x8004BF44: jal         0x8004B644
    // 0x8004BF48: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8004B644(rdram, ctx);
        goto after_20;
    // 0x8004BF48: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_20:
    // 0x8004BF4C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004BF50: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    // 0x8004BF54: lb          $v0, 0x7($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X7);
    // 0x8004BF58: addiu       $a0, $s3, 0x1C
    ctx->r4 = ADD32(ctx->r19, 0X1C);
    // 0x8004BF5C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004BF60: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004BF64: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004BF68: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004BF6C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004BF70: lwc1        $f20, -0x575C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X575C);
    // 0x8004BF74: addiu       $a3, $s4, 0x1C
    ctx->r7 = ADD32(ctx->r20, 0X1C);
    // 0x8004BF78: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x8004BF7C: jal         0x8004B644
    // 0x8004BF80: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8004B644(rdram, ctx);
        goto after_21;
    // 0x8004BF80: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_21:
    // 0x8004BF84: add.s       $f26, $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f26.fl = ctx->f26.fl + ctx->f20.fl;
    // 0x8004BF88: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004BF8C: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x8004BF90: lb          $v0, 0x8($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X8);
    // 0x8004BF94: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004BF98: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004BF9C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004BFA0: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004BFA4: addiu       $a0, $s3, 0x20
    ctx->r4 = ADD32(ctx->r19, 0X20);
    // 0x8004BFA8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004BFAC: addiu       $a3, $s4, 0x20
    ctx->r7 = ADD32(ctx->r20, 0X20);
    // 0x8004BFB0: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x8004BFB4: jal         0x8004B644
    // 0x8004BFB8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8004B644(rdram, ctx);
        goto after_22;
    // 0x8004BFB8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_22:
    // 0x8004BFBC: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8004BFC0: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004BFC4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8004BFC8: lb          $v0, 0x9($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X9);
    // 0x8004BFCC: addiu       $a0, $s3, 0x24
    ctx->r4 = ADD32(ctx->r19, 0X24);
    // 0x8004BFD0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004BFD4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004BFD8: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004BFDC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004BFE0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004BFE4: addiu       $a3, $s4, 0x24
    ctx->r7 = ADD32(ctx->r20, 0X24);
    // 0x8004BFE8: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x8004BFEC: jal         0x8004B644
    // 0x8004BFF0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8004B644(rdram, ctx);
        goto after_23;
    // 0x8004BFF0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_23:
    // 0x8004BFF4: addiu       $a0, $s3, 0x3C
    ctx->r4 = ADD32(ctx->r19, 0X3C);
    // 0x8004BFF8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004BFFC: addiu       $a3, $s4, 0x3C
    ctx->r7 = ADD32(ctx->r20, 0X3C);
    // 0x8004C000: lhu         $v1, 0x10($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0X10);
    // 0x8004C004: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8004C008: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004C00C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8004C010: lb          $a1, 0xF($s2)
    ctx->r5 = MEM_B(ctx->r18, 0XF);
    // 0x8004C014: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004C018: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x8004C01C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004C020: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004C024: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004C028: lw          $v1, 0x7A54($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X7A54);
    // 0x8004C02C: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8004C030: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x8004C034: add.s       $f20, $f6, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x8004C038: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004C03C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004C040: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8004C044: jal         0x8004B644
    // 0x8004C048: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8004B644(rdram, ctx);
        goto after_24;
    // 0x8004C048: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_24:
    // 0x8004C04C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004C050: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8004C054: lb          $v0, 0x10($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X10);
    // 0x8004C058: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004C05C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004C060: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004C064: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004C068: addiu       $a0, $s3, 0x40
    ctx->r4 = ADD32(ctx->r19, 0X40);
    // 0x8004C06C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004C070: addiu       $a3, $s4, 0x40
    ctx->r7 = ADD32(ctx->r20, 0X40);
    // 0x8004C074: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8004C078: jal         0x8004B644
    // 0x8004C07C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8004B644(rdram, ctx);
        goto after_25;
    // 0x8004C07C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_25:
    // 0x8004C080: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004C084: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    // 0x8004C088: lb          $v0, 0x11($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X11);
    // 0x8004C08C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004C090: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004C094: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004C098: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004C09C: addiu       $a0, $s3, 0x44
    ctx->r4 = ADD32(ctx->r19, 0X44);
    // 0x8004C0A0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004C0A4: addiu       $a3, $s4, 0x44
    ctx->r7 = ADD32(ctx->r20, 0X44);
    // 0x8004C0A8: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8004C0AC: jal         0x8004B644
    // 0x8004C0B0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8004B644(rdram, ctx);
        goto after_26;
    // 0x8004C0B0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_26:
    // 0x8004C0B4: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x8004C0B8: lb          $v0, 0x12($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X12);
    // 0x8004C0BC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004C0C0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004C0C4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004C0C8: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004C0CC: addiu       $a0, $s3, 0x48
    ctx->r4 = ADD32(ctx->r19, 0X48);
    // 0x8004C0D0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004C0D4: addiu       $a3, $s4, 0x48
    ctx->r7 = ADD32(ctx->r20, 0X48);
    // 0x8004C0D8: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8004C0DC: jal         0x8004B644
    // 0x8004C0E0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8004B644(rdram, ctx);
        goto after_27;
    // 0x8004C0E0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_27:
    // 0x8004C0E4: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8004C0E8: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004C0EC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8004C0F0: lb          $v0, 0x13($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X13);
    // 0x8004C0F4: addiu       $a0, $s3, 0x4C
    ctx->r4 = ADD32(ctx->r19, 0X4C);
    // 0x8004C0F8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004C0FC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004C100: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004C104: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004C108: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004C10C: addiu       $a3, $s4, 0x4C
    ctx->r7 = ADD32(ctx->r20, 0X4C);
    // 0x8004C110: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8004C114: jal         0x8004B644
    // 0x8004C118: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8004B644(rdram, ctx);
        goto after_28;
    // 0x8004C118: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_28:
    // 0x8004C11C: addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);
    // 0x8004C120: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004C124: lhu         $v1, 0x12($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0X12);
    // 0x8004C128: addiu       $a3, $s4, 0x4
    ctx->r7 = ADD32(ctx->r20, 0X4);
    // 0x8004C12C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8004C130: lb          $a1, 0x1($s2)
    ctx->r5 = MEM_B(ctx->r18, 0X1);
    // 0x8004C134: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8004C138: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004C13C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004C140: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004C144: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x8004C148: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004C14C: lw          $v1, 0x7A54($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X7A54);
    // 0x8004C150: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004C154: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8004C158: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x8004C15C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004C160: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004C164: jal         0x8004B644
    // 0x8004C168: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8004B644(rdram, ctx);
        goto after_29;
    // 0x8004C168: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_29:
    // 0x8004C16C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004C170: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004C174: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x8004C178: lb          $v0, 0x3($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X3);
    // 0x8004C17C: addiu       $a0, $s3, 0xC
    ctx->r4 = ADD32(ctx->r19, 0XC);
    // 0x8004C180: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004C184: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004C188: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004C18C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004C190: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8004C194: addiu       $a3, $s4, 0xC
    ctx->r7 = ADD32(ctx->r20, 0XC);
    // 0x8004C198: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8004C19C: jal         0x8004B644
    // 0x8004C1A0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8004B644(rdram, ctx);
        goto after_30;
    // 0x8004C1A0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_30:
    // 0x8004C1A4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004C1A8: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004C1AC: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8004C1B0: lb          $v0, 0xB($s2)
    ctx->r2 = MEM_B(ctx->r18, 0XB);
    // 0x8004C1B4: addiu       $a0, $s3, 0x2C
    ctx->r4 = ADD32(ctx->r19, 0X2C);
    // 0x8004C1B8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004C1BC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004C1C0: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004C1C4: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004C1C8: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8004C1CC: addiu       $a3, $s4, 0x2C
    ctx->r7 = ADD32(ctx->r20, 0X2C);
    // 0x8004C1D0: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8004C1D4: jal         0x8004B644
    // 0x8004C1D8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8004B644(rdram, ctx);
        goto after_31;
    // 0x8004C1D8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_31:
    // 0x8004C1DC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004C1E0: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004C1E4: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x8004C1E8: lb          $v0, 0xD($s2)
    ctx->r2 = MEM_B(ctx->r18, 0XD);
    // 0x8004C1EC: addiu       $a0, $s3, 0x34
    ctx->r4 = ADD32(ctx->r19, 0X34);
    // 0x8004C1F0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004C1F4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004C1F8: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004C1FC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004C200: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8004C204: addiu       $a3, $s4, 0x34
    ctx->r7 = ADD32(ctx->r20, 0X34);
    // 0x8004C208: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8004C20C: jal         0x8004B644
    // 0x8004C210: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8004B644(rdram, ctx);
        goto after_32;
    // 0x8004C210: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_32:
    // 0x8004C214: addiu       $a0, $s3, 0x54
    ctx->r4 = ADD32(ctx->r19, 0X54);
    // 0x8004C218: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8004C21C: lb          $v0, 0x15($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X15);
    // 0x8004C220: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004C224: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004C228: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004C22C: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004C230: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004C234: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8004C238: addiu       $a3, $s4, 0x54
    ctx->r7 = ADD32(ctx->r20, 0X54);
    // 0x8004C23C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8004C240: jal         0x8004B644
    // 0x8004C244: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8004B644(rdram, ctx);
        goto after_33;
    // 0x8004C244: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_33:
    // 0x8004C248: addiu       $a0, $s3, 0x5C
    ctx->r4 = ADD32(ctx->r19, 0X5C);
    // 0x8004C24C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004C250: lhu         $v1, 0xA($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0XA);
    // 0x8004C254: addiu       $a3, $s4, 0x5C
    ctx->r7 = ADD32(ctx->r20, 0X5C);
    // 0x8004C258: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x8004C25C: lb          $a1, 0x17($s2)
    ctx->r5 = MEM_B(ctx->r18, 0X17);
    // 0x8004C260: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8004C264: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004C268: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004C26C: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x8004C270: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004C274: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8004C278: lw          $v1, 0x7A54($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X7A54);
    // 0x8004C27C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004C280: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8004C284: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x8004C288: addiu       $a1, $s0, 0x30
    ctx->r5 = ADD32(ctx->r16, 0X30);
    // 0x8004C28C: jal         0x8004B644
    // 0x8004C290: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8004B644(rdram, ctx);
        goto after_34;
    // 0x8004C290: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_34:
L_8004C294:
    // 0x8004C294: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x8004C298: lw          $s6, 0x78($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X78);
    // 0x8004C29C: lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X74);
    // 0x8004C2A0: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x8004C2A4: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x8004C2A8: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x8004C2AC: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x8004C2B0: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x8004C2B4: ldc1        $f30, 0xA8($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0XA8);
    // 0x8004C2B8: ldc1        $f28, 0xA0($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0XA0);
    // 0x8004C2BC: ldc1        $f26, 0x98($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X98);
    // 0x8004C2C0: ldc1        $f24, 0x90($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X90);
    // 0x8004C2C4: ldc1        $f22, 0x88($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X88);
    // 0x8004C2C8: ldc1        $f20, 0x80($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X80);
    // 0x8004C2CC: jr          $ra
    // 0x8004C2D0: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8004C2D0: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_8004C2D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004C2D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004C2D8: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8004C2DC: addiu       $a3, $t0, 0x6DC0
    ctx->r7 = ADD32(ctx->r8, 0X6DC0);
    // 0x8004C2E0: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8004C2E4: sw          $s3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r19;
    // 0x8004C2E8: sw          $s2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r18;
    // 0x8004C2EC: sw          $s1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r17;
    // 0x8004C2F0: sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // 0x8004C2F4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8004C2F8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8004C2FC: lwc1        $f2, 0x10($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8004C300: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004C304: lwc1        $f0, -0x5758($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5758);
    // 0x8004C308: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8004C30C: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8004C310: lwc1        $f8, 0x1C($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x8004C314: lwc1        $f16, 0x18($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8004C318: lwc1        $f10, 0x10($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8004C31C: sub.s       $f0, $f16, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x8004C320: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004C324: lwc1        $f4, -0x5754($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5754);
    // 0x8004C328: lwc1        $f14, 0x14($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8004C32C: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004C330: mfc1        $t7, $f22
    ctx->r15 = (int32_t)ctx->f22.u32l;
    // 0x8004C334: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8004C338: bltzl       $t7, L_8004C340
    if (SIGNED(ctx->r15) < 0) {
        // 0x8004C33C: addu        $t7, $zero, $zero
        ctx->r15 = ADD32(0, 0);
            goto L_8004C340;
    }
    goto skip_0;
    // 0x8004C33C: addu        $t7, $zero, $zero
    ctx->r15 = ADD32(0, 0);
    skip_0:
L_8004C340:
    // 0x8004C340: add.s       $f0, $f16, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8004C344: lhu         $v1, 0x3A($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X3A);
    // 0x8004C348: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004C34C: mfc1        $s1, $f22
    ctx->r17 = (int32_t)ctx->f22.u32l;
    // 0x8004C350: slt         $v0, $s1, $v1
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8004C354: beql        $v0, $zero, L_8004C35C
    if (ctx->r2 == 0) {
        // 0x8004C358: addiu       $s1, $v1, -0x1
        ctx->r17 = ADD32(ctx->r3, -0X1);
            goto L_8004C35C;
    }
    goto skip_1;
    // 0x8004C358: addiu       $s1, $v1, -0x1
    ctx->r17 = ADD32(ctx->r3, -0X1);
    skip_1:
L_8004C35C:
    // 0x8004C35C: add.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8004C360: lhu         $a2, 0x38($a3)
    ctx->r6 = MEM_HU(ctx->r7, 0X38);
    // 0x8004C364: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004C368: mfc1        $t9, $f22
    ctx->r25 = (int32_t)ctx->f22.u32l;
    // 0x8004C36C: slt         $v0, $t9, $a2
    ctx->r2 = SIGNED(ctx->r25) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8004C370: beql        $v0, $zero, L_8004C378
    if (ctx->r2 == 0) {
        // 0x8004C374: addiu       $t9, $a2, -0x1
        ctx->r25 = ADD32(ctx->r6, -0X1);
            goto L_8004C378;
    }
    goto skip_2;
    // 0x8004C374: addiu       $t9, $a2, -0x1
    ctx->r25 = ADD32(ctx->r6, -0X1);
    skip_2:
L_8004C378:
    // 0x8004C378: sub.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8004C37C: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004C380: mfc1        $t8, $f22
    ctx->r24 = (int32_t)ctx->f22.u32l;
    // 0x8004C384: bltzl       $t8, L_8004C38C
    if (SIGNED(ctx->r24) < 0) {
        // 0x8004C388: addu        $t8, $zero, $zero
        ctx->r24 = ADD32(0, 0);
            goto L_8004C38C;
    }
    goto skip_3;
    // 0x8004C388: addu        $t8, $zero, $zero
    ctx->r24 = ADD32(0, 0);
    skip_3:
L_8004C38C:
    // 0x8004C38C: mult        $t7, $a2
    result = S64(S32(ctx->r15)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004C390: mul.s       $f8, $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8004C394: mtc1        $t8, $f0
    ctx->f0.u32l = ctx->r24;
    // 0x8004C398: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004C39C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8004C3A0: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
    // 0x8004C3A4: sub.s       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8004C3A8: lw          $v0, 0x6DC0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X6DC0);
    // 0x8004C3AC: lw          $v1, 0x8($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X8);
    // 0x8004C3B0: mflo        $s4
    ctx->r20 = lo;
    // 0x8004C3B4: addu        $t4, $t8, $s4
    ctx->r12 = ADD32(ctx->r24, ctx->r20);
    // 0x8004C3B8: sll         $a0, $t4, 1
    ctx->r4 = S32(ctx->r12 << 1);
    // 0x8004C3BC: addu        $t5, $v0, $a0
    ctx->r13 = ADD32(ctx->r2, ctx->r4);
    // 0x8004C3C0: subu        $v0, $a2, $t9
    ctx->r2 = SUB32(ctx->r6, ctx->r25);
    // 0x8004C3C4: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8004C3C8: slt         $v0, $s1, $t7
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8004C3CC: bne         $v0, $zero, L_8004C66C
    if (ctx->r2 != 0) {
        // 0x8004C3D0: addu        $t1, $v1, $a0
        ctx->r9 = ADD32(ctx->r3, ctx->r4);
            goto L_8004C66C;
    }
    // 0x8004C3D0: addu        $t1, $v1, $a0
    ctx->r9 = ADD32(ctx->r3, ctx->r4);
    // 0x8004C3D4: mov.s       $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = ctx->f4.fl;
    // 0x8004C3D8: addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // 0x8004C3DC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8004C3E0: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x8004C3E4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8004C3E8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004C3EC: lwc1        $f18, -0x5750($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5750);
    // 0x8004C3F0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
L_8004C3F4:
    // 0x8004C3F4: mtc1        $t7, $f0
    ctx->f0.u32l = ctx->r15;
    // 0x8004C3F8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004C3FC: sub.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x8004C400: c.lt.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl < ctx->f6.fl;
    // 0x8004C404: nop

    // 0x8004C408: bc1tl       L_8004C410
    if (c1cs) {
        // 0x8004C40C: sub.s       $f6, $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f18.fl;
            goto L_8004C410;
    }
    goto skip_4;
    // 0x8004C40C: sub.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f18.fl;
    skip_4:
L_8004C410:
    // 0x8004C410: mul.s       $f6, $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8004C414: bltz        $t9, L_8004C650
    if (SIGNED(ctx->r25) < 0) {
        // 0x8004C418: addu        $t3, $zero, $zero
        ctx->r11 = ADD32(0, 0);
            goto L_8004C650;
    }
    // 0x8004C418: addu        $t3, $zero, $zero
    ctx->r11 = ADD32(0, 0);
L_8004C41C:
    // 0x8004C41C: mtc1        $t3, $f0
    ctx->f0.u32l = ctx->r11;
    // 0x8004C420: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004C424: sub.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8004C428: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8004C42C: nop

    // 0x8004C430: bc1tl       L_8004C438
    if (c1cs) {
        // 0x8004C434: sub.s       $f0, $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f18.fl;
            goto L_8004C438;
    }
    goto skip_5;
    // 0x8004C434: sub.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f18.fl;
    skip_5:
L_8004C438:
    // 0x8004C438: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8004C43C: add.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8004C440: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8004C444: nop

    // 0x8004C448: bc1fl       L_8004C63C
    if (!c1cs) {
        // 0x8004C44C: addiu       $t5, $t5, 0x2
        ctx->r13 = ADD32(ctx->r13, 0X2);
            goto L_8004C63C;
    }
    goto skip_6;
    // 0x8004C44C: addiu       $t5, $t5, 0x2
    ctx->r13 = ADD32(ctx->r13, 0X2);
    skip_6:
    // 0x8004C450: lhu         $v1, 0x0($t5)
    ctx->r3 = MEM_HU(ctx->r13, 0X0);
    // 0x8004C454: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x8004C458: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8004C45C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004C460: lw          $v1, 0x4($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X4);
    // 0x8004C464: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8004C468: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // 0x8004C46C: lb          $v0, 0x3($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X3);
    // 0x8004C470: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004C474: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004C478: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8004C47C: sub.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x8004C480: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8004C484: nop

    // 0x8004C488: bc1f        L_8004C4B4
    if (!c1cs) {
        // 0x8004C48C: nop
    
            goto L_8004C4B4;
    }
    // 0x8004C48C: nop

    // 0x8004C490: lb          $v0, 0x4($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X4);
    // 0x8004C494: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004C498: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004C49C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8004C4A0: sub.s       $f0, $f14, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8004C4A4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8004C4A8: nop

    // 0x8004C4AC: bc1tl       L_8004C4B4
    if (c1cs) {
        // 0x8004C4B0: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_8004C4B4;
    }
    goto skip_7;
    // 0x8004C4B0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_7:
L_8004C4B4:
    // 0x8004C4B4: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8004C4B8: add.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8004C4BC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8004C4C0: nop

    // 0x8004C4C4: bc1fl       L_8004C63C
    if (!c1cs) {
        // 0x8004C4C8: addiu       $t5, $t5, 0x2
        ctx->r13 = ADD32(ctx->r13, 0X2);
            goto L_8004C63C;
    }
    goto skip_8;
    // 0x8004C4C8: addiu       $t5, $t5, 0x2
    ctx->r13 = ADD32(ctx->r13, 0X2);
    skip_8:
    // 0x8004C4CC: lhu         $v0, 0x6FC0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X6FC0);
    // 0x8004C4D0: bne         $v0, $t2, L_8004C500
    if (ctx->r2 != ctx->r10) {
        // 0x8004C4D4: sll         $v1, $v0, 1
        ctx->r3 = S32(ctx->r2 << 1);
            goto L_8004C500;
    }
    // 0x8004C4D4: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8004C4D8: j           L_8004C6A4
    // 0x8004C4DC: sh          $t2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r10;
        goto L_8004C6A4;
    // 0x8004C4DC: sh          $t2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r10;
L_8004C4E0:
    // 0x8004C4E0: lhu         $v0, 0x6FC0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X6FC0);
    // 0x8004C4E4: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
    // 0x8004C4E8: lhu         $v0, 0x2($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X2);
    // 0x8004C4EC: sh          $a2, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r6;
    // 0x8004C4F0: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // 0x8004C4F4: sh          $a2, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r6;
    // 0x8004C4F8: j           L_8004C568
    // 0x8004C4FC: sh          $v0, 0x6FC0($t0)
    MEM_H(0X6FC0, ctx->r8) = ctx->r2;
        goto L_8004C568;
    // 0x8004C4FC: sh          $v0, 0x6FC0($t0)
    MEM_H(0X6FC0, ctx->r8) = ctx->r2;
L_8004C500:
    // 0x8004C500: lw          $a0, 0x6FCC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X6FCC);
    // 0x8004C504: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8004C508: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8004C50C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004C510: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8004C514: lhu         $a2, 0x0($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0X0);
    // 0x8004C518: beq         $a2, $t2, L_8004C5E4
    if (ctx->r6 == ctx->r10) {
        // 0x8004C51C: addu        $a3, $a0, $v1
        ctx->r7 = ADD32(ctx->r4, ctx->r3);
            goto L_8004C5E4;
    }
    // 0x8004C51C: addu        $a3, $a0, $v1
    ctx->r7 = ADD32(ctx->r4, ctx->r3);
    // 0x8004C520: andi        $a2, $a2, 0x7FFF
    ctx->r6 = ctx->r6 & 0X7FFF;
    // 0x8004C524: sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6 << 1);
    // 0x8004C528: lw          $a0, 0x6FCC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X6FCC);
    // 0x8004C52C: j           L_8004C554
    // 0x8004C530: addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
        goto L_8004C554;
    // 0x8004C530: addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
L_8004C534:
    // 0x8004C534: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004C538: addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // 0x8004C53C: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x8004C540: beq         $v0, $t2, L_8004C4E0
    if (ctx->r2 == ctx->r10) {
        // 0x8004C544: nop
    
            goto L_8004C4E0;
    }
    // 0x8004C544: nop

    // 0x8004C548: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8004C54C: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8004C550: addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
L_8004C554:
    // 0x8004C554: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004C558: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004C55C: lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4);
    // 0x8004C560: beq         $v0, $zero, L_8004C534
    if (ctx->r2 == 0) {
        // 0x8004C564: addu        $v0, $v1, $a2
        ctx->r2 = ADD32(ctx->r3, ctx->r6);
            goto L_8004C534;
    }
    // 0x8004C564: addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
L_8004C568:
    // 0x8004C568: beq         $a2, $t2, L_8004C5FC
    if (ctx->r6 == ctx->r10) {
        // 0x8004C56C: sll         $v0, $a2, 1
        ctx->r2 = S32(ctx->r6 << 1);
            goto L_8004C5FC;
    }
    // 0x8004C56C: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x8004C570: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8004C574: lw          $a0, 0x6FCC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X6FCC);
    // 0x8004C578: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004C57C: addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // 0x8004C580: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8004C584: sh          $v0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r2;
    // 0x8004C588: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8004C58C: beq         $v0, $t2, L_8004C5B4
    if (ctx->r2 == ctx->r10) {
        // 0x8004C590: nop
    
            goto L_8004C5B4;
    }
    // 0x8004C590: nop

    // 0x8004C594: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8004C598: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8004C59C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004C5A0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8004C5A4: lhu         $v0, 0x6FC0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X6FC0);
    // 0x8004C5A8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8004C5AC: j           L_8004C5BC
    // 0x8004C5B0: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
        goto L_8004C5BC;
    // 0x8004C5B0: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
L_8004C5B4:
    // 0x8004C5B4: lhu         $v0, 0x6FC0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X6FC0);
    // 0x8004C5B8: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
L_8004C5BC:
    // 0x8004C5BC: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x8004C5C0: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8004C5C4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004C5C8: lw          $v1, 0x6FCC($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X6FCC);
    // 0x8004C5CC: lhu         $a0, 0x6FC0($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X6FC0);
    // 0x8004C5D0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004C5D4: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x8004C5D8: lhu         $v0, 0x2($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X2);
    // 0x8004C5DC: j           L_8004C5F8
    // 0x8004C5E0: sh          $a2, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r6;
        goto L_8004C5F8;
    // 0x8004C5E0: sh          $a2, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r6;
L_8004C5E4:
    // 0x8004C5E4: lhu         $v0, 0x6FC0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X6FC0);
    // 0x8004C5E8: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    // 0x8004C5EC: lhu         $v0, 0x2($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X2);
    // 0x8004C5F0: sh          $t2, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r10;
    // 0x8004C5F4: sh          $t2, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r10;
L_8004C5F8:
    // 0x8004C5F8: sh          $v0, 0x6FC0($t0)
    MEM_H(0X6FC0, ctx->r8) = ctx->r2;
L_8004C5FC:
    // 0x8004C5FC: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8004C600: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004C604: sh          $v0, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r2;
    // 0x8004C608: sh          $t4, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r12;
    // 0x8004C60C: bne         $s0, $zero, L_8004C638
    if (ctx->r16 != 0) {
        // 0x8004C610: sw          $s2, 0x8($a3)
        MEM_W(0X8, ctx->r7) = ctx->r18;
            goto L_8004C638;
    }
    // 0x8004C610: sw          $s2, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r18;
    // 0x8004C614: lhu         $v0, 0x6FC0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X6FC0);
    // 0x8004C618: beq         $v0, $t2, L_8004C6A4
    if (ctx->r2 == ctx->r10) {
        // 0x8004C61C: sll         $v1, $v0, 1
        ctx->r3 = S32(ctx->r2 << 1);
            goto L_8004C6A4;
    }
    // 0x8004C61C: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8004C620: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004C624: lw          $v0, 0x6FCC($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X6FCC);
    // 0x8004C628: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8004C62C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004C630: j           L_8004C6A4
    // 0x8004C634: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
        goto L_8004C6A4;
    // 0x8004C634: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
L_8004C638:
    // 0x8004C638: addiu       $t5, $t5, 0x2
    ctx->r13 = ADD32(ctx->r13, 0X2);
L_8004C63C:
    // 0x8004C63C: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x8004C640: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8004C644: slt         $v0, $t9, $t3
    ctx->r2 = SIGNED(ctx->r25) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8004C648: beq         $v0, $zero, L_8004C41C
    if (ctx->r2 == 0) {
        // 0x8004C64C: addiu       $t4, $t4, 0x1
        ctx->r12 = ADD32(ctx->r12, 0X1);
            goto L_8004C41C;
    }
    // 0x8004C64C: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
L_8004C650:
    // 0x8004C650: sll         $v0, $t8, 1
    ctx->r2 = S32(ctx->r24 << 1);
    // 0x8004C654: addu        $t5, $t5, $v0
    ctx->r13 = ADD32(ctx->r13, ctx->r2);
    // 0x8004C658: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x8004C65C: addiu       $t7, $t7, 0x1
    ctx->r15 = ADD32(ctx->r15, 0X1);
    // 0x8004C660: slt         $v0, $s1, $t7
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8004C664: beq         $v0, $zero, L_8004C3F4
    if (ctx->r2 == 0) {
        // 0x8004C668: addu        $t4, $t4, $t8
        ctx->r12 = ADD32(ctx->r12, ctx->r24);
            goto L_8004C3F4;
    }
    // 0x8004C668: addu        $t4, $t4, $t8
    ctx->r12 = ADD32(ctx->r12, ctx->r24);
L_8004C66C:
    // 0x8004C66C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8004C670: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004C674: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8004C678: lhu         $v0, 0x6FC0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X6FC0);
    // 0x8004C67C: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x8004C680: beq         $v0, $a1, L_8004C6A4
    if (ctx->r2 == ctx->r5) {
        // 0x8004C684: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8004C6A4;
    }
    // 0x8004C684: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8004C688: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8004C68C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004C690: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004C694: lw          $v1, 0x6FCC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X6FCC);
    // 0x8004C698: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004C69C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004C6A0: sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
L_8004C6A4:
    // 0x8004C6A4: lw          $s4, 0x10($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X10);
    // 0x8004C6A8: lw          $s3, 0xC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XC);
    // 0x8004C6AC: lw          $s2, 0x8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X8);
    // 0x8004C6B0: lw          $s1, 0x4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4);
    // 0x8004C6B4: lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X0);
    // 0x8004C6B8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8004C6BC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8004C6C0: jr          $ra
    // 0x8004C6C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8004C6C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void byteAnimatedDebrisNpcHandler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004C6C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004C6CC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8004C6D0: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x8004C6D4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8004C6D8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8004C6DC: andi        $s1, $a1, 0xFFFF
    ctx->r17 = ctx->r5 & 0XFFFF;
    // 0x8004C6E0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8004C6E4: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8004C6E8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8004C6EC: lw          $s0, 0x4($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X4);
    // 0x8004C6F0: beq         $s1, $v0, L_8004C9EC
    if (ctx->r17 == ctx->r2) {
        // 0x8004C6F4: addu        $s2, $a2, $zero
        ctx->r18 = ADD32(ctx->r6, 0);
            goto L_8004C9EC;
    }
    // 0x8004C6F4: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x8004C6F8: slti        $v0, $s1, 0x4
    ctx->r2 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8004C6FC: beq         $v0, $zero, L_8004C71C
    if (ctx->r2 == 0) {
        // 0x8004C700: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8004C71C;
    }
    // 0x8004C700: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004C704: beq         $s1, $v0, L_8004C738
    if (ctx->r17 == ctx->r2) {
        // 0x8004C708: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8004C738;
    }
    // 0x8004C708: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8004C70C: beq         $s1, $v0, L_8004C8F0
    if (ctx->r17 == ctx->r2) {
        // 0x8004C710: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8004C8F0;
    }
    // 0x8004C710: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004C714: j           L_8004CBE0
    // 0x8004C718: nop

        goto L_8004CBE0;
    // 0x8004C718: nop

L_8004C71C:
    // 0x8004C71C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8004C720: beq         $s1, $v0, L_8004CBDC
    if (ctx->r17 == ctx->r2) {
        // 0x8004C724: addiu       $v0, $zero, 0x1000
        ctx->r2 = ADD32(0, 0X1000);
            goto L_8004CBDC;
    }
    // 0x8004C724: addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // 0x8004C728: beq         $s1, $v0, L_8004C790
    if (ctx->r17 == ctx->r2) {
        // 0x8004C72C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8004C790;
    }
    // 0x8004C72C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004C730: j           L_8004CBE0
    // 0x8004C734: nop

        goto L_8004CBE0;
    // 0x8004C734: nop

L_8004C738:
    // 0x8004C738: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8004C73C: lhu         $a0, -0x6A6A($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A6A);
    // 0x8004C740: jal         0x8003E684
    // 0x8004C744: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    popNpcSlotFromTail(rdram, ctx);
        goto after_0;
    // 0x8004C744: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_0:
    // 0x8004C748: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8004C74C: sw          $zero, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = 0;
    // 0x8004C750: sh          $v0, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r2;
    // 0x8004C754: sb          $s1, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r17;
    // 0x8004C758: beq         $s2, $zero, L_8004C784
    if (ctx->r18 == 0) {
        // 0x8004C75C: sb          $zero, 0xE($s0)
        MEM_B(0XE, ctx->r16) = 0;
            goto L_8004C784;
    }
    // 0x8004C75C: sb          $zero, 0xE($s0)
    MEM_B(0XE, ctx->r16) = 0;
    // 0x8004C760: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8004C764: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // 0x8004C768: lhu         $v0, 0x10($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X10);
    // 0x8004C76C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004C770: ori         $v0, $v0, 0x3
    ctx->r2 = ctx->r2 | 0X3;
    // 0x8004C774: jal         0x8004C6C8
    // 0x8004C778: sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    byteAnimatedDebrisNpcHandler(rdram, ctx);
        goto after_1;
    // 0x8004C778: sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    after_1:
    // 0x8004C77C: j           L_8004CBE0
    // 0x8004C780: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8004CBE0;
    // 0x8004C780: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004C784:
    // 0x8004C784: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x8004C788: j           L_8004CBDC
    // 0x8004C78C: sw          $v0, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->r2;
        goto L_8004CBDC;
    // 0x8004C78C: sw          $v0, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->r2;
L_8004C790:
    // 0x8004C790: beq         $s2, $zero, L_8004CBE0
    if (ctx->r18 == 0) {
        // 0x8004C794: nop
    
            goto L_8004CBE0;
    }
    // 0x8004C794: nop

    // 0x8004C798: lhu         $v0, 0x10($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X10);
    // 0x8004C79C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8004C7A0: beq         $v0, $zero, L_8004C808
    if (ctx->r2 == 0) {
        // 0x8004C7A4: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004C808;
    }
    // 0x8004C7A4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004C7A8: addiu       $v0, $v0, 0x6DC0
    ctx->r2 = ADD32(ctx->r2, 0X6DC0);
    // 0x8004C7AC: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8004C7B0: lwc1        $f2, 0x14($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8004C7B4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004C7B8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004C7BC: lwc1        $f4, -0x574C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X574C);
    // 0x8004C7C0: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8004C7C4: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x8004C7C8: lwc1        $f0, 0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8004C7CC: lwc1        $f2, 0x18($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8004C7D0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004C7D4: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8004C7D8: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x8004C7DC: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8004C7E0: lwc1        $f2, 0x1C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8004C7E4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004C7E8: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8004C7EC: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x8004C7F0: lwc1        $f0, 0xC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8004C7F4: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8004C7F8: lw          $v0, 0xA0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA0);
    // 0x8004C7FC: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x8004C800: sw          $v0, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->r2;
    // 0x8004C804: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
L_8004C808:
    // 0x8004C808: lhu         $v1, 0x10($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X10);
    // 0x8004C80C: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x8004C810: beq         $v0, $zero, L_8004CBDC
    if (ctx->r2 == 0) {
        // 0x8004C814: andi        $v0, $v1, 0x100
        ctx->r2 = ctx->r3 & 0X100;
            goto L_8004CBDC;
    }
    // 0x8004C814: andi        $v0, $v1, 0x100
    ctx->r2 = ctx->r3 & 0X100;
    // 0x8004C818: beq         $v0, $zero, L_8004C8BC
    if (ctx->r2 == 0) {
        // 0x8004C81C: nop
    
            goto L_8004C8BC;
    }
    // 0x8004C81C: nop

    // 0x8004C820: lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X14);
    // 0x8004C824: sw          $v0, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->r2;
    // 0x8004C828: lbu         $v0, 0x18($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X18);
    // 0x8004C82C: lw          $v1, 0xA4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XA4);
    // 0x8004C830: sb          $v0, 0xA8($s0)
    MEM_B(0XA8, ctx->r16) = ctx->r2;
    // 0x8004C834: lbu         $v0, 0x19($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X19);
    // 0x8004C838: sb          $v0, 0xA9($s0)
    MEM_B(0XA9, ctx->r16) = ctx->r2;
    // 0x8004C83C: lbu         $v0, 0xA8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XA8);
    // 0x8004C840: lwc1        $f2, 0x1C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x8004C844: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004C848: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004C84C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004C850: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004C854: swc1        $f0, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->f0.u32l;
    // 0x8004C858: swc1        $f2, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f2.u32l;
    // 0x8004C85C: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8004C860: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004C864: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004C868: lbu         $v0, 0xA8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XA8);
    // 0x8004C86C: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8004C870: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004C874: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004C878: lbu         $v0, 0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1);
    // 0x8004C87C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004C880: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004C884: lbu         $v0, 0xA8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XA8);
    // 0x8004C888: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x8004C88C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004C890: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004C894: lbu         $v0, 0x2($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2);
    // 0x8004C898: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004C89C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004C8A0: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x8004C8A4: lhu         $v0, 0x10($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X10);
    // 0x8004C8A8: lw          $v1, 0xA0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XA0);
    // 0x8004C8AC: andi        $v0, $v0, 0x300
    ctx->r2 = ctx->r2 & 0X300;
    // 0x8004C8B0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8004C8B4: j           L_8004CBDC
    // 0x8004C8B8: sw          $v1, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->r3;
        goto L_8004CBDC;
    // 0x8004C8B8: sw          $v1, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->r3;
L_8004C8BC:
    // 0x8004C8BC: lbu         $v0, 0x14($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X14);
    // 0x8004C8C0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004C8C4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004C8C8: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8004C8CC: lbu         $v0, 0x15($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X15);
    // 0x8004C8D0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004C8D4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004C8D8: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x8004C8DC: lbu         $v0, 0x16($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X16);
    // 0x8004C8E0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004C8E4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004C8E8: j           L_8004CBDC
    // 0x8004C8EC: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
        goto L_8004CBDC;
    // 0x8004C8EC: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
L_8004C8F0:
    // 0x8004C8F0: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x8004C8F4: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x8004C8F8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004C8FC: lw          $t0, 0x6FCC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X6FCC);
    // 0x8004C900: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004C904: addiu       $t4, $v0, 0x6DC0
    ctx->r12 = ADD32(ctx->r2, 0X6DC0);
    // 0x8004C908: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8004C90C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_8004C910:
    // 0x8004C910: lhu         $a3, 0x20($a0)
    ctx->r7 = MEM_HU(ctx->r4, 0X20);
    // 0x8004C914: beq         $a3, $t2, L_8004C9C0
    if (ctx->r7 == ctx->r10) {
        // 0x8004C918: sll         $v0, $a3, 1
        ctx->r2 = S32(ctx->r7 << 1);
            goto L_8004C9C0;
    }
    // 0x8004C918: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x8004C91C: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8004C920: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004C924: addu        $a2, $v0, $t0
    ctx->r6 = ADD32(ctx->r2, ctx->r8);
    // 0x8004C928: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    // 0x8004C92C: lhu         $v1, 0x0($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X0);
    // 0x8004C930: beq         $a1, $t2, L_8004C948
    if (ctx->r5 == ctx->r10) {
        // 0x8004C934: sll         $v0, $a1, 1
        ctx->r2 = S32(ctx->r5 << 1);
            goto L_8004C948;
    }
    // 0x8004C934: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8004C938: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8004C93C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004C940: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8004C944: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
L_8004C948:
    // 0x8004C948: beq         $v1, $t2, L_8004C964
    if (ctx->r3 == ctx->r10) {
        // 0x8004C94C: sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3 << 1);
            goto L_8004C964;
    }
    // 0x8004C94C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004C950: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004C954: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004C958: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8004C95C: j           L_8004C978
    // 0x8004C960: sh          $a1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r5;
        goto L_8004C978;
    // 0x8004C960: sh          $a1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r5;
L_8004C964:
    // 0x8004C964: lhu         $v0, 0x6($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X6);
    // 0x8004C968: lw          $v1, 0x8($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X8);
    // 0x8004C96C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8004C970: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004C974: sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
L_8004C978:
    // 0x8004C978: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x8004C97C: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8004C980: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004C984: lhu         $v1, 0x6FC0($t3)
    ctx->r3 = MEM_HU(ctx->r11, 0X6FC0);
    // 0x8004C988: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8004C98C: andi        $a1, $v1, 0xFFFF
    ctx->r5 = ctx->r3 & 0XFFFF;
    // 0x8004C990: beq         $a1, $t2, L_8004C9AC
    if (ctx->r5 == ctx->r10) {
        // 0x8004C994: sh          $v1, 0x2($v0)
        MEM_H(0X2, ctx->r2) = ctx->r3;
            goto L_8004C9AC;
    }
    // 0x8004C994: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // 0x8004C998: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8004C99C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8004C9A0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004C9A4: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8004C9A8: sh          $a3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r7;
L_8004C9AC:
    // 0x8004C9AC: sh          $a3, 0x6FC0($t3)
    MEM_H(0X6FC0, ctx->r11) = ctx->r7;
    // 0x8004C9B0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8004C9B4: slti        $v0, $t1, 0x40
    ctx->r2 = SIGNED(ctx->r9) < 0X40 ? 1 : 0;
    // 0x8004C9B8: bne         $v0, $zero, L_8004C910
    if (ctx->r2 != 0) {
        // 0x8004C9BC: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_8004C910;
    }
    // 0x8004C9BC: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
L_8004C9C0:
    // 0x8004C9C0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004C9C4: lhu         $v1, 0x6FC0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X6FC0);
    // 0x8004C9C8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8004C9CC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004C9D0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004C9D4: lw          $v1, 0x6FCC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X6FCC);
    // 0x8004C9D8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004C9DC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004C9E0: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x8004C9E4: j           L_8004CBDC
    // 0x8004C9E8: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
        goto L_8004CBDC;
    // 0x8004C9E8: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
L_8004C9EC:
    // 0x8004C9EC: lw          $v0, 0xA0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA0);
    // 0x8004C9F0: andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // 0x8004C9F4: beq         $v0, $zero, L_8004CAC0
    if (ctx->r2 == 0) {
        // 0x8004C9F8: nop
    
            goto L_8004CAC0;
    }
    // 0x8004C9F8: nop

    // 0x8004C9FC: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8004CA00: lwc1        $f2, 0xAC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x8004CA04: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8004CA08: lwc1        $f2, 0xB0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XB0);
    // 0x8004CA0C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8004CA10: lbu         $v0, 0xA9($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XA9);
    // 0x8004CA14: trunc.w.s   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8004CA18: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x8004CA1C: slt         $v0, $t1, $v0
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004CA20: bne         $v0, $zero, L_8004CA74
    if (ctx->r2 != 0) {
        // 0x8004CA24: swc1        $f2, 0xB0($s0)
        MEM_W(0XB0, ctx->r16) = ctx->f2.u32l;
            goto L_8004CA74;
    }
    // 0x8004CA24: swc1        $f2, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->f2.u32l;
    // 0x8004CA28: lw          $v0, 0xA0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA0);
    // 0x8004CA2C: andi        $v0, $v0, 0x200
    ctx->r2 = ctx->r2 & 0X200;
    // 0x8004CA30: beq         $v0, $zero, L_8004CA4C
    if (ctx->r2 == 0) {
        // 0x8004CA34: nop
    
            goto L_8004CA4C;
    }
    // 0x8004CA34: nop

    // 0x8004CA38: lhu         $a0, 0x16($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X16);
    // 0x8004CA3C: jal         0x8003ED74
    // 0x8004CA40: nop

    destroyNpcSlotByIndex(rdram, ctx);
        goto after_2;
    // 0x8004CA40: nop

    after_2:
    // 0x8004CA44: j           L_8004CBE0
    // 0x8004CA48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8004CBE0;
    // 0x8004CA48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004CA4C:
    // 0x8004CA4C: mtc1        $t1, $f0
    ctx->f0.u32l = ctx->r9;
    // 0x8004CA50: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004CA54: lbu         $v0, 0xA8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XA8);
    // 0x8004CA58: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8004CA5C: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8004CA60: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8004CA64: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8004CA68: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004CA6C: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x8004CA70: swc1        $f0, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->f0.u32l;
L_8004CA74:
    // 0x8004CA74: lw          $v0, 0xA4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA4);
    // 0x8004CA78: sll         $v1, $t1, 2
    ctx->r3 = S32(ctx->r9 << 2);
    // 0x8004CA7C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8004CA80: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x8004CA84: lw          $v0, 0xA4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA4);
    // 0x8004CA88: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x8004CA8C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004CA90: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8004CA94: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8004CA98: lbu         $v0, 0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1);
    // 0x8004CA9C: lw          $a0, 0xA4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XA4);
    // 0x8004CAA0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004CAA4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004CAA8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8004CAAC: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x8004CAB0: lbu         $v0, 0x2($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2);
    // 0x8004CAB4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004CAB8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004CABC: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
L_8004CAC0:
    // 0x8004CAC0: lw          $v1, 0xA0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XA0);
    // 0x8004CAC4: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x8004CAC8: beq         $v0, $zero, L_8004CBDC
    if (ctx->r2 == 0) {
        // 0x8004CACC: addu        $t1, $zero, $zero
        ctx->r9 = ADD32(0, 0);
            goto L_8004CBDC;
    }
    // 0x8004CACC: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x8004CAD0: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x8004CAD4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004CAD8: addiu       $t4, $v0, 0x6DC0
    ctx->r12 = ADD32(ctx->r2, 0X6DC0);
    // 0x8004CADC: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8004CAE0: addu        $t0, $s0, $zero
    ctx->r8 = ADD32(ctx->r16, 0);
    // 0x8004CAE4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004CAE8: lw          $a2, 0x6FCC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X6FCC);
    // 0x8004CAEC: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // 0x8004CAF0: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8004CAF4: sw          $v0, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->r2;
L_8004CAF8:
    // 0x8004CAF8: lhu         $a3, 0x20($t0)
    ctx->r7 = MEM_HU(ctx->r8, 0X20);
    // 0x8004CAFC: beq         $a3, $t2, L_8004CBA8
    if (ctx->r7 == ctx->r10) {
        // 0x8004CB00: sll         $v0, $a3, 1
        ctx->r2 = S32(ctx->r7 << 1);
            goto L_8004CBA8;
    }
    // 0x8004CB00: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x8004CB04: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8004CB08: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004CB0C: addu        $a0, $v0, $a2
    ctx->r4 = ADD32(ctx->r2, ctx->r6);
    // 0x8004CB10: lhu         $a1, 0x2($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X2);
    // 0x8004CB14: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x8004CB18: beq         $a1, $t2, L_8004CB30
    if (ctx->r5 == ctx->r10) {
        // 0x8004CB1C: sll         $v0, $a1, 1
        ctx->r2 = S32(ctx->r5 << 1);
            goto L_8004CB30;
    }
    // 0x8004CB1C: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8004CB20: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8004CB24: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004CB28: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8004CB2C: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
L_8004CB30:
    // 0x8004CB30: beq         $v1, $t2, L_8004CB4C
    if (ctx->r3 == ctx->r10) {
        // 0x8004CB34: sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3 << 1);
            goto L_8004CB4C;
    }
    // 0x8004CB34: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004CB38: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004CB3C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004CB40: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8004CB44: j           L_8004CB60
    // 0x8004CB48: sh          $a1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r5;
        goto L_8004CB60;
    // 0x8004CB48: sh          $a1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r5;
L_8004CB4C:
    // 0x8004CB4C: lhu         $v0, 0x6($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X6);
    // 0x8004CB50: lw          $v1, 0x8($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X8);
    // 0x8004CB54: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8004CB58: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004CB5C: sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
L_8004CB60:
    // 0x8004CB60: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x8004CB64: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8004CB68: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004CB6C: lhu         $v1, 0x6FC0($t3)
    ctx->r3 = MEM_HU(ctx->r11, 0X6FC0);
    // 0x8004CB70: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8004CB74: andi        $a1, $v1, 0xFFFF
    ctx->r5 = ctx->r3 & 0XFFFF;
    // 0x8004CB78: beq         $a1, $t2, L_8004CB94
    if (ctx->r5 == ctx->r10) {
        // 0x8004CB7C: sh          $v1, 0x2($v0)
        MEM_H(0X2, ctx->r2) = ctx->r3;
            goto L_8004CB94;
    }
    // 0x8004CB7C: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // 0x8004CB80: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8004CB84: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8004CB88: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004CB8C: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8004CB90: sh          $a3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r7;
L_8004CB94:
    // 0x8004CB94: sh          $a3, 0x6FC0($t3)
    MEM_H(0X6FC0, ctx->r11) = ctx->r7;
    // 0x8004CB98: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8004CB9C: slti        $v0, $t1, 0x40
    ctx->r2 = SIGNED(ctx->r9) < 0X40 ? 1 : 0;
    // 0x8004CBA0: bne         $v0, $zero, L_8004CAF8
    if (ctx->r2 != 0) {
        // 0x8004CBA4: addiu       $t0, $t0, 0x2
        ctx->r8 = ADD32(ctx->r8, 0X2);
            goto L_8004CAF8;
    }
    // 0x8004CBA4: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
L_8004CBA8:
    // 0x8004CBA8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004CBAC: addiu       $a1, $a0, 0x20
    ctx->r5 = ADD32(ctx->r4, 0X20);
    // 0x8004CBB0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004CBB4: lhu         $v1, 0x6FC0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X6FC0);
    // 0x8004CBB8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8004CBBC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004CBC0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004CBC4: lw          $v1, 0x6FCC($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X6FCC);
    // 0x8004CBC8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004CBCC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004CBD0: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x8004CBD4: jal         0x8004C2D4
    // 0x8004CBD8: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    func_8004C2D4(rdram, ctx);
        goto after_3;
    // 0x8004CBD8: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    after_3:
L_8004CBDC:
    // 0x8004CBDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004CBE0:
    // 0x8004CBE0: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8004CBE4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8004CBE8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8004CBEC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8004CBF0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8004CBF4: jr          $ra
    // 0x8004CBF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8004CBF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8004CBFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004CBFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004CC00: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8004CC04: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8004CC08: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8004CC0C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8004CC10: lhu         $v0, 0x14($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X14);
    // 0x8004CC14: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // 0x8004CC18: beql        $v0, $zero, L_8004CC30
    if (ctx->r2 == 0) {
        // 0x8004CC1C: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_8004CC30;
    }
    goto skip_0;
    // 0x8004CC1C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    skip_0:
    // 0x8004CC20: jal         0x80046214
    // 0x8004CC24: nop

    func_80046214(rdram, ctx);
        goto after_0;
    // 0x8004CC24: nop

    after_0:
    // 0x8004CC28: j           L_8004CCE4
    // 0x8004CC2C: sw          $v0, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->r2;
        goto L_8004CCE4;
    // 0x8004CC2C: sw          $v0, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->r2;
L_8004CC30:
    // 0x8004CC30: lhu         $v1, 0x8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X8);
    // 0x8004CC34: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004CC38: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004CC3C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8004CC40: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004CC44: lw          $v1, 0x7A5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X7A5C);
    // 0x8004CC48: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8004CC4C: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x8004CC50: lhu         $v1, 0x14($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X14);
    // 0x8004CC54: andi        $v0, $v1, 0x40
    ctx->r2 = ctx->r3 & 0X40;
    // 0x8004CC58: bne         $v0, $zero, L_8004CCE0
    if (ctx->r2 != 0) {
        // 0x8004CC5C: addiu       $v0, $s0, 0x54
        ctx->r2 = ADD32(ctx->r16, 0X54);
            goto L_8004CCE0;
    }
    // 0x8004CC5C: addiu       $v0, $s0, 0x54
    ctx->r2 = ADD32(ctx->r16, 0X54);
    // 0x8004CC60: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x8004CC64: beql        $v1, $zero, L_8004CCE4
    if (ctx->r3 == 0) {
        // 0x8004CC68: sw          $v0, 0x48($s1)
        MEM_W(0X48, ctx->r17) = ctx->r2;
            goto L_8004CCE4;
    }
    goto skip_1;
    // 0x8004CC68: sw          $v0, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->r2;
    skip_1:
    // 0x8004CC6C: lbu         $v0, 0x30($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X30);
    // 0x8004CC70: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x8004CC74: beq         $v0, $zero, L_8004CC90
    if (ctx->r2 == 0) {
        // 0x8004CC78: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8004CC90;
    }
    // 0x8004CC78: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8004CC7C: bne         $v1, $v0, L_8004CC90
    if (ctx->r3 != ctx->r2) {
        // 0x8004CC80: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8004CC90;
    }
    // 0x8004CC80: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004CC84: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8004CC88: jal         0x80049814
    // 0x8004CC8C: addiu       $a1, $a1, 0x6DC0
    ctx->r5 = ADD32(ctx->r5, 0X6DC0);
    func_80049814(rdram, ctx);
        goto after_1;
    // 0x8004CC8C: addiu       $a1, $a1, 0x6DC0
    ctx->r5 = ADD32(ctx->r5, 0X6DC0);
    after_1:
L_8004CC90:
    // 0x8004CC90: lbu         $v0, 0x30($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X30);
    // 0x8004CC94: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8004CC98: beq         $v0, $zero, L_8004CCBC
    if (ctx->r2 == 0) {
        // 0x8004CC9C: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_8004CCBC;
    }
    // 0x8004CC9C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8004CCA0: lhu         $v0, 0x14($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X14);
    // 0x8004CCA4: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x8004CCA8: bne         $v0, $v1, L_8004CCBC
    if (ctx->r2 != ctx->r3) {
        // 0x8004CCAC: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8004CCBC;
    }
    // 0x8004CCAC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004CCB0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8004CCB4: jal         0x80049BBC
    // 0x8004CCB8: addiu       $a1, $a1, 0x6DC0
    ctx->r5 = ADD32(ctx->r5, 0X6DC0);
    func_80049BBC(rdram, ctx);
        goto after_2;
    // 0x8004CCB8: addiu       $a1, $a1, 0x6DC0
    ctx->r5 = ADD32(ctx->r5, 0X6DC0);
    after_2:
L_8004CCBC:
    // 0x8004CCBC: lbu         $v0, 0x30($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X30);
    // 0x8004CCC0: bne         $v0, $zero, L_8004CCD4
    if (ctx->r2 != 0) {
        // 0x8004CCC4: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8004CCD4;
    }
    // 0x8004CCC4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004CCC8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8004CCCC: jal         0x80049FB8
    // 0x8004CCD0: addiu       $a1, $a1, 0x6DC0
    ctx->r5 = ADD32(ctx->r5, 0X6DC0);
    func_80049FB8(rdram, ctx);
        goto after_3;
    // 0x8004CCD0: addiu       $a1, $a1, 0x6DC0
    ctx->r5 = ADD32(ctx->r5, 0X6DC0);
    after_3:
L_8004CCD4:
    // 0x8004CCD4: jal         0x8004AA94
    // 0x8004CCD8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8004AA94(rdram, ctx);
        goto after_4;
    // 0x8004CCD8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x8004CCDC: addiu       $v0, $s0, 0x54
    ctx->r2 = ADD32(ctx->r16, 0X54);
L_8004CCE0:
    // 0x8004CCE0: sw          $v0, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->r2;
L_8004CCE4:
    // 0x8004CCE4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8004CCE8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8004CCEC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8004CCF0: jr          $ra
    // 0x8004CCF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8004CCF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void fake_func_8004CCF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void applyPlayerVehicleStateUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004CD00: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x8004CD04: sw          $s1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r17;
    // 0x8004CD08: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8004CD0C: sw          $ra, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r31;
    // 0x8004CD10: sw          $s5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r21;
    // 0x8004CD14: sw          $s4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r20;
    // 0x8004CD18: sw          $s3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r19;
    // 0x8004CD1C: sw          $s2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r18;
    // 0x8004CD20: sw          $s0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r16;
    // 0x8004CD24: sdc1        $f20, 0xD0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XD0, ctx->r29);
    // 0x8004CD28: lw          $v1, 0xC($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XC);
    // 0x8004CD2C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8004CD30: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004CD34: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8004CD38: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004CD3C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004CD40: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8004CD44: addiu       $v1, $v1, -0x72E8
    ctx->r3 = ADD32(ctx->r3, -0X72E8);
    // 0x8004CD48: addu        $s2, $v0, $v1
    ctx->r18 = ADD32(ctx->r2, ctx->r3);
    // 0x8004CD4C: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x8004CD50: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x8004CD54: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8004CD58: beq         $v0, $a0, L_8004D050
    if (ctx->r2 == ctx->r4) {
        // 0x8004CD5C: nop
    
            goto L_8004D050;
    }
    // 0x8004CD5C: nop

    // 0x8004CD60: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x8004CD64: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x8004CD68: beq         $v0, $zero, L_8004CD84
    if (ctx->r2 == 0) {
        // 0x8004CD6C: nop
    
            goto L_8004CD84;
    }
    // 0x8004CD6C: nop

    // 0x8004CD70: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x8004CD74: beq         $v0, $a0, L_8004D050
    if (ctx->r2 == ctx->r4) {
        // 0x8004CD78: lui         $a2, 0x8014
        ctx->r6 = S32(0X8014 << 16);
            goto L_8004D050;
    }
    // 0x8004CD78: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x8004CD7C: j           L_8004CFDC
    // 0x8004CD80: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
        goto L_8004CFDC;
    // 0x8004CD80: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
L_8004CD84:
    // 0x8004CD84: bne         $s1, $v1, L_8004CFC8
    if (ctx->r17 != ctx->r3) {
        // 0x8004CD88: nop
    
            goto L_8004CFC8;
    }
    // 0x8004CD88: nop

    // 0x8004CD8C: lw          $v0, 0x18($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X18);
    // 0x8004CD90: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004CD94: ldc1        $f6, -0x5730($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X5730);
    // 0x8004CD98: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8004CD9C: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8004CDA0: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8004CDA4: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8004CDA8: mul.d       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x8004CDAC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004CDB0: ldc1        $f4, -0x5728($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X5728);
    // 0x8004CDB4: lwc1        $f0, 0x1C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x8004CDB8: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x8004CDBC: div.d       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x8004CDC0: mul.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f0.d);
    // 0x8004CDC4: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x8004CDC8: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x8004CDCC: lw          $v1, 0x1C($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1C);
    // 0x8004CDD0: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x8004CDD4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004CDD8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004CDDC: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8004CDE0: mul.d       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x8004CDE4: mtc1        $v1, $f2
    ctx->f2.u32l = ctx->r3;
    // 0x8004CDE8: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x8004CDEC: div.d       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = DIV_D(ctx->f4.d, ctx->f2.d);
    // 0x8004CDF0: mul.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x8004CDF4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004CDF8: lwc1        $f2, -0x5720($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5720);
    // 0x8004CDFC: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8004CE00: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8004CE04: lwc1        $f0, 0x28($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X28);
    // 0x8004CE08: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8004CE0C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004CE10: lwc1        $f2, -0x571C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X571C);
    // 0x8004CE14: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8004CE18: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004CE1C: lwc1        $f2, -0x5718($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5718);
    // 0x8004CE20: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8004CE24: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004CE28: lwc1        $f2, -0x5714($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5714);
    // 0x8004CE2C: div.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8004CE30: jal         0x80033960
    // 0x8004CE34: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x8004CE34: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x8004CE38: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8004CE3C: jal         0x8002B190
    // 0x8004CE40: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8004CE40: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_1:
    // 0x8004CE44: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8004CE48: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004CE4C: lwc1        $f2, -0x5710($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5710);
    // 0x8004CE50: addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // 0x8004CE54: div.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f20.fl);
    // 0x8004CE58: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x8004CE5C: lwc1        $f0, 0x2C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x8004CE60: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004CE64: jal         0x8001CF58
    // 0x8004CE68: add.s       $f20, $f0, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f0.fl + ctx->f0.fl;
    normalize_vector(rdram, ctx);
        goto after_2;
    // 0x8004CE68: add.s       $f20, $f0, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f0.fl + ctx->f0.fl;
    after_2:
    // 0x8004CE6C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8004CE70: mul.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8004CE74: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x8004CE78: addu        $s2, $s0, $zero
    ctx->r18 = ADD32(ctx->r16, 0);
    // 0x8004CE7C: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8004CE80: addiu       $s5, $sp, 0x10
    ctx->r21 = ADD32(ctx->r29, 0X10);
    // 0x8004CE84: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x8004CE88: addu        $s3, $s5, $zero
    ctx->r19 = ADD32(ctx->r21, 0);
    // 0x8004CE8C: addiu       $s0, $s1, 0x28
    ctx->r16 = ADD32(ctx->r17, 0X28);
    // 0x8004CE90: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8004CE94: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004CE98: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8004CE9C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8004CEA0: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x8004CEA4: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x8004CEA8: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x8004CEAC: jal         0x800193E8
    // 0x8004CEB0: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    transformVec3ByMat34(rdram, ctx);
        goto after_3;
    // 0x8004CEB0: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x8004CEB4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004CEB8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8004CEBC: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8004CEC0: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x8004CEC4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8004CEC8: jal         0x800193E8
    // 0x8004CECC: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    transformVec3ByMat34(rdram, ctx);
        goto after_4;
    // 0x8004CECC: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8004CED0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004CED4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8004CED8: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8004CEDC: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    // 0x8004CEE0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8004CEE4: jal         0x800193E8
    // 0x8004CEE8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    transformVec3ByMat34(rdram, ctx);
        goto after_5;
    // 0x8004CEE8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x8004CEEC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004CEF0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8004CEF4: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8004CEF8: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x8004CEFC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8004CF00: jal         0x800193E8
    // 0x8004CF04: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    transformVec3ByMat34(rdram, ctx);
        goto after_6;
    // 0x8004CF04: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x8004CF08: addiu       $s0, $s1, 0x10
    ctx->r16 = ADD32(ctx->r17, 0X10);
L_8004CF0C:
    // 0x8004CF0C: lwc1        $f0, 0x38($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X38);
    // 0x8004CF10: lwc1        $f2, 0x10($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004CF14: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004CF18: addiu       $v0, $s3, 0x38
    ctx->r2 = ADD32(ctx->r19, 0X38);
    // 0x8004CF1C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8004CF20: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8004CF24: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004CF28: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8004CF2C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004CF30: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8004CF34: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x8004CF38: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8004CF3C: lwc1        $f2, 0x18($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8004CF40: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x8004CF44: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004CF48: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x8004CF4C: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // 0x8004CF50: jal         0x80068D5C
    // 0x8004CF54: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    sampleTerrainAtNpcPosition(rdram, ctx);
        goto after_7;
    // 0x8004CF54: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x8004CF58: beql        $v0, $zero, L_8004CFBC
    if (ctx->r2 == 0) {
        // 0x8004CF5C: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_8004CFBC;
    }
    goto skip_0;
    // 0x8004CF5C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_0:
    // 0x8004CF60: jal         0x800AA350
    // 0x8004CF64: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    clampVec3ToUnitIfLongerThan(rdram, ctx);
        goto after_8;
    // 0x8004CF64: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_8:
    // 0x8004CF68: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004CF6C: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x8004CF70: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x8004CF74: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8004CF78: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8004CF7C: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8004CF80: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8004CF84: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8004CF88: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8004CF8C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8004CF90: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x8004CF94: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8004CF98: jal         0x800AA3E0
    // 0x8004CF9C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    func_800AA3E0(rdram, ctx);
        goto after_9;
    // 0x8004CF9C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x8004CFA0: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004CFA4: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004CFA8: lwc1        $f4, 0x18($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8004CFAC: swc1        $f0, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f0.u32l;
    // 0x8004CFB0: swc1        $f2, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f2.u32l;
    // 0x8004CFB4: swc1        $f4, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f4.u32l;
    // 0x8004CFB8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_8004CFBC:
    // 0x8004CFBC: slti        $v0, $s4, 0x3
    ctx->r2 = SIGNED(ctx->r20) < 0X3 ? 1 : 0;
    // 0x8004CFC0: bne         $v0, $zero, L_8004CF0C
    if (ctx->r2 != 0) {
        // 0x8004CFC4: addiu       $s3, $s3, 0xC
        ctx->r19 = ADD32(ctx->r19, 0XC);
            goto L_8004CF0C;
    }
    // 0x8004CFC4: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
L_8004CFC8:
    // 0x8004CFC8: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
    // 0x8004CFCC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8004CFD0: beq         $v1, $v0, L_8004D050
    if (ctx->r3 == ctx->r2) {
        // 0x8004CFD4: lui         $a2, 0x8014
        ctx->r6 = S32(0X8014 << 16);
            goto L_8004D050;
    }
    // 0x8004CFD4: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x8004CFD8: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
L_8004CFDC:
    // 0x8004CFDC: lwc1        $f12, 0x4C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4C);
    // 0x8004CFE0: lwc1        $f14, 0x54($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X54);
    // 0x8004CFE4: jal         0x80067D90
    // 0x8004CFE8: addiu       $a3, $sp, 0x78
    ctx->r7 = ADD32(ctx->r29, 0X78);
    wrapAngleToCyclicRange(rdram, ctx);
        goto after_10;
    // 0x8004CFE8: addiu       $a3, $sp, 0x78
    ctx->r7 = ADD32(ctx->r29, 0X78);
    after_10:
    // 0x8004CFEC: lwc1        $f2, 0x10($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004CFF0: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8004CFF4: lwc1        $f6, 0x50($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X50);
    // 0x8004CFF8: sub.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8004CFFC: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8004D000: swc1        $f2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f2.u32l;
    // 0x8004D004: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004D008: sub.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8004D00C: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8004D010: swc1        $f2, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f2.u32l;
    // 0x8004D014: lwc1        $f2, 0x18($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8004D018: sub.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8004D01C: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x8004D020: sub.s       $f20, $f0, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8004D024: jal         0x8001CF2C
    // 0x8004D028: swc1        $f2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f2.u32l;
    vec3Length(rdram, ctx);
        goto after_11;
    // 0x8004D028: swc1        $f2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f2.u32l;
    after_11:
    // 0x8004D02C: lwc1        $f2, 0xB8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XB8);
    // 0x8004D030: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x8004D034: nop

    // 0x8004D038: bc1f        L_8004D050
    if (!c1cs) {
        // 0x8004D03C: nop
    
            goto L_8004D050;
    }
    // 0x8004D03C: nop

    // 0x8004D040: lwc1        $f0, 0x7C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8004D044: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004D048: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
    // 0x8004D04C: swc1        $f0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f0.u32l;
L_8004D050:
    // 0x8004D050: lw          $ra, 0xC8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XC8);
    // 0x8004D054: lw          $s5, 0xC4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XC4);
    // 0x8004D058: lw          $s4, 0xC0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XC0);
    // 0x8004D05C: lw          $s3, 0xBC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XBC);
    // 0x8004D060: lw          $s2, 0xB8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XB8);
    // 0x8004D064: lw          $s1, 0xB4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XB4);
    // 0x8004D068: lw          $s0, 0xB0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XB0);
    // 0x8004D06C: ldc1        $f20, 0xD0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XD0);
    // 0x8004D070: jr          $ra
    // 0x8004D074: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x8004D074: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void func_8004D078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D078: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8004D07C: sw          $s2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r18;
    // 0x8004D080: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8004D084: addiu       $v1, $sp, 0x10
    ctx->r3 = ADD32(ctx->r29, 0X10);
    // 0x8004D088: sw          $ra, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r31;
    // 0x8004D08C: sw          $s1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r17;
    // 0x8004D090: sw          $s0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r16;
    // 0x8004D094: sdc1        $f20, 0xB0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XB0, ctx->r29);
    // 0x8004D098: lw          $v0, 0x74($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X74);
    // 0x8004D09C: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x8004D0A0: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
L_8004D0A4:
    // 0x8004D0A4: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x8004D0A8: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x8004D0AC: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x8004D0B0: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x8004D0B4: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x8004D0B8: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8004D0BC: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x8004D0C0: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x8004D0C4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8004D0C8: bne         $v0, $a0, L_8004D0A4
    if (ctx->r2 != ctx->r4) {
        // 0x8004D0CC: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8004D0A4;
    }
    // 0x8004D0CC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8004D0D0: lw          $a3, 0x58($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X58);
    // 0x8004D0D4: lw          $t0, 0x5C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X5C);
    // 0x8004D0D8: lw          $t1, 0x60($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X60);
    // 0x8004D0DC: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    // 0x8004D0E0: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x8004D0E4: sw          $t1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r9;
    // 0x8004D0E8: lwc1        $f0, 0x50($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8004D0EC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004D0F0: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8004D0F4: nop

    // 0x8004D0F8: bc1f        L_8004D128
    if (!c1cs) {
        // 0x8004D0FC: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_8004D128;
    }
    // 0x8004D0FC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8004D100: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8004D104: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8004D108: nop

    // 0x8004D10C: bc1f        L_8004D12C
    if (!c1cs) {
        // 0x8004D110: addiu       $a1, $sp, 0x50
        ctx->r5 = ADD32(ctx->r29, 0X50);
            goto L_8004D12C;
    }
    // 0x8004D110: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8004D114: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8004D118: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8004D11C: nop

    // 0x8004D120: bc1t        L_8004D150
    if (c1cs) {
        // 0x8004D124: nop
    
            goto L_8004D150;
    }
    // 0x8004D124: nop

L_8004D128:
    // 0x8004D128: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
L_8004D12C:
    // 0x8004D12C: jal         0x800193E8
    // 0x8004D130: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    transformVec3ByMat34(rdram, ctx);
        goto after_0;
    // 0x8004D130: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_0:
    // 0x8004D134: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8004D138: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8004D13C: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8004D140: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8004D144: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x8004D148: j           L_8004D168
    // 0x8004D14C: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
        goto L_8004D168;
    // 0x8004D14C: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
L_8004D150:
    // 0x8004D150: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8004D154: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8004D158: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8004D15C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8004D160: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x8004D164: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
L_8004D168:
    // 0x8004D168: addiu       $s1, $sp, 0x70
    ctx->r17 = ADD32(ctx->r29, 0X70);
    // 0x8004D16C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8004D170: lw          $a2, 0xD0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0XD0);
    // 0x8004D174: jal         0x8001D038
    // 0x8004D178: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    quatFromCardinalAxis(rdram, ctx);
        goto after_1;
    // 0x8004D178: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8004D17C: addiu       $s0, $sp, 0x80
    ctx->r16 = ADD32(ctx->r29, 0X80);
    // 0x8004D180: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004D184: lw          $a2, 0xE0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0XE0);
    // 0x8004D188: jal         0x8001D038
    // 0x8004D18C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    quatFromCardinalAxis(rdram, ctx);
        goto after_2;
    // 0x8004D18C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
    // 0x8004D190: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8004D194: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004D198: addiu       $s0, $sp, 0x90
    ctx->r16 = ADD32(ctx->r29, 0X90);
    // 0x8004D19C: jal         0x8001D2C0
    // 0x8004D1A0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    quatMultiply(rdram, ctx);
        goto after_3;
    // 0x8004D1A0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_3:
    // 0x8004D1A4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004D1A8: jal         0x8001D548
    // 0x8004D1AC: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8001D548(rdram, ctx);
        goto after_4;
    // 0x8004D1AC: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_4:
    // 0x8004D1B0: lwc1        $f0, 0xDC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XDC);
    // 0x8004D1B4: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8004D1B8: lwc1        $f2, 0x94($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X94);
    // 0x8004D1BC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8004D1C0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004D1C4: lwc1        $f0, -0x570C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X570C);
    // 0x8004D1C8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8004D1CC: nop

    // 0x8004D1D0: bc1f        L_8004D1E0
    if (!c1cs) {
        // 0x8004D1D4: swc1        $f2, 0x94($s2)
        MEM_W(0X94, ctx->r18) = ctx->f2.u32l;
            goto L_8004D1E0;
    }
    // 0x8004D1D4: swc1        $f2, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->f2.u32l;
    // 0x8004D1D8: swc1        $f0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->f0.u32l;
    // 0x8004D1DC: sw          $zero, 0xDC($s2)
    MEM_W(0XDC, ctx->r18) = 0;
L_8004D1E0:
    // 0x8004D1E0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8004D1E4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8004D1E8: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x8004D1EC: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x8004D1F0: lwc1        $f0, 0x94($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X94);
    // 0x8004D1F4: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8004D1F8: jal         0x800194A4
    // 0x8004D1FC: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    rotateVec3ByMat3x3(rdram, ctx);
        goto after_5;
    // 0x8004D1FC: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x8004D200: lw          $v0, 0x74($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X74);
    // 0x8004D204: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8004D208: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8004D20C: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8004D210: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8004D214: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x8004D218: lw          $v0, 0x74($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X74);
    // 0x8004D21C: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8004D220: lwc1        $f6, 0x28($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8004D224: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x8004D228: lw          $v0, 0x74($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X74);
    // 0x8004D22C: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x8004D230: lwc1        $f6, 0x2C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8004D234: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x8004D238: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8004D23C: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x8004D240: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    // 0x8004D244: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8004D248: swc1        $f4, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f4.u32l;
    // 0x8004D24C: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8004D250: swc1        $f0, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f0.u32l;
    // 0x8004D254: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8004D258: swc1        $f0, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f0.u32l;
    // 0x8004D25C: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x8004D260: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8004D264: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x8004D268: sw          $a3, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r7;
    // 0x8004D26C: sw          $t0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r8;
    // 0x8004D270: sw          $t1, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r9;
    // 0x8004D274: lwc1        $f0, 0xD8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XD8);
    // 0x8004D278: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8004D27C: lwc1        $f12, 0xD0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0XD0);
    // 0x8004D280: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x8004D284: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004D288: lwc1        $f14, -0x5708($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X5708);
    // 0x8004D28C: jal         0x8001E20C
    // 0x8004D290: swc1        $f12, 0xD0($s2)
    MEM_W(0XD0, ctx->r18) = ctx->f12.u32l;
    floatModulo(rdram, ctx);
        goto after_6;
    // 0x8004D290: swc1        $f12, 0xD0($s2)
    MEM_W(0XD0, ctx->r18) = ctx->f12.u32l;
    after_6:
    // 0x8004D294: lw          $ra, 0xAC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XAC);
    // 0x8004D298: lw          $s2, 0xA8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA8);
    // 0x8004D29C: lw          $s1, 0xA4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XA4);
    // 0x8004D2A0: lw          $s0, 0xA0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA0);
    // 0x8004D2A4: ldc1        $f20, 0xB0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XB0);
    // 0x8004D2A8: jr          $ra
    // 0x8004D2AC: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x8004D2AC: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
