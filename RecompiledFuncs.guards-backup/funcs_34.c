#include "recomp.h"
#include "funcs.h"
#include <stdio.h>

RECOMP_FUNC void func_800C4184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4184: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800C4188: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // 0x800C418C: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x800C4190: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x800C4194: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x800C4198: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800C419C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800C41A0: sdc1        $f28, 0x98($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X98, ctx->r29);
    // 0x800C41A4: mtc1        $a2, $f28
    ctx->f28.u32l = ctx->r6;
    // 0x800C41A8: addiu       $a2, $v0, -0xC0
    ctx->r6 = ADD32(ctx->r2, -0XC0);
    // 0x800C41AC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800C41B0: sdc1        $f26, 0x90($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X90, ctx->r29);
    // 0x800C41B4: mtc1        $a3, $f26
    ctx->f26.u32l = ctx->r7;
    // 0x800C41B8: addiu       $a1, $v0, -0x1C0
    ctx->r5 = ADD32(ctx->r2, -0X1C0);
    // 0x800C41BC: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x800C41C0: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x800C41C4: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x800C41C8: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x800C41CC: sdc1        $f24, 0x88($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X88, ctx->r29);
    // 0x800C41D0: sdc1        $f22, 0x80($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X80, ctx->r29);
    // 0x800C41D4: sdc1        $f20, 0x78($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X78, ctx->r29);
    // 0x800C41D8: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
L_800C41DC:
    // 0x800C41DC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800C41E0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C41E4: addu        $v1, $v0, $a2
    ctx->r3 = ADD32(ctx->r2, ctx->r6);
    // 0x800C41E8: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800C41EC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800C41F0: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x800C41F4: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x800C41F8: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x800C41FC: bne         $v0, $zero, L_800C41DC
    if (ctx->r2 != 0) {
        // 0x800C4200: andi        $v0, $a0, 0xFF
        ctx->r2 = ctx->r4 & 0XFF;
            goto L_800C41DC;
    }
    // 0x800C4200: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x800C4204: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800C4208: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800C420C: addiu       $s2, $v0, -0x1C0
    ctx->r18 = ADD32(ctx->r2, -0X1C0);
    // 0x800C4210: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800C4214: addiu       $s0, $s1, -0x170
    ctx->r16 = ADD32(ctx->r17, -0X170);
    // 0x800C4218: sw          $s4, -0x1C0($v0)
    MEM_W(-0X1C0, ctx->r2) = ctx->r20;
    // 0x800C421C: jal         0x8001CA50
    // 0x800C4220: sw          $s0, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->r16;
    func_8001CA50(rdram, ctx);
        goto after_0;
    // 0x800C4220: sw          $s0, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->r16;
    after_0:
    // 0x800C4224: addiu       $a0, $s2, 0x18
    ctx->r4 = ADD32(ctx->r18, 0X18);
    // 0x800C4228: jal         0x80059D18
    // 0x800C422C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_80059D18(rdram, ctx);
        goto after_1;
    // 0x800C422C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x800C4230: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800C4234: addiu       $v0, $v1, -0x110
    ctx->r2 = ADD32(ctx->r3, -0X110);
    // 0x800C4238: lw          $a1, 0x18($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X18);
    // 0x800C423C: lw          $a2, 0x1C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X1C);
    // 0x800C4240: lw          $a3, 0x20($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X20);
    // 0x800C4244: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    // 0x800C4248: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x800C424C: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x800C4250: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800C4254: sw          $zero, -0x110($v1)
    MEM_W(-0X110, ctx->r3) = 0;
    // 0x800C4258: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x800C425C: jal         0x8001CAC4
    // 0x800C4260: sw          $s0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r16;
    func_8001CAC4(rdram, ctx);
        goto after_2;
    // 0x800C4260: sw          $s0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r16;
    after_2:
    // 0x800C4264: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C4268: lui         $v0, 0x4900
    ctx->r2 = S32(0X4900 << 16);
    // 0x800C426C: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x800C4270: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800C4274: sw          $zero, -0x170($s1)
    MEM_W(-0X170, ctx->r17) = 0;
    // 0x800C4278: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // 0x800C427C: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x800C4280: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x800C4284: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800C4288: jal         0x8000A85C
    // 0x800C428C: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    func_8000A85C(rdram, ctx);
        goto after_3;
    // 0x800C428C: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    after_3:
    // 0x800C4290: lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X0);
    // 0x800C4294: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C4298: beq         $v1, $a0, L_800C42F4
    if (ctx->r3 == ctx->r4) {
        // 0x800C429C: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_800C42F4;
    }
    // 0x800C429C: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800C42A0: beql        $v0, $zero, L_800C42B8
    if (ctx->r2 == 0) {
        // 0x800C42A4: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800C42B8;
    }
    goto skip_0;
    // 0x800C42A4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x800C42A8: beq         $v1, $zero, L_800C42C8
    if (ctx->r3 == 0) {
        // 0x800C42AC: nop
    
            goto L_800C42C8;
    }
    // 0x800C42AC: nop

    // 0x800C42B0: j           L_800C4574
    // 0x800C42B4: nop

        goto L_800C4574;
    // 0x800C42B4: nop

L_800C42B8:
    // 0x800C42B8: beq         $v1, $v0, L_800C4410
    if (ctx->r3 == ctx->r2) {
        // 0x800C42BC: nop
    
            goto L_800C4410;
    }
    // 0x800C42BC: nop

    // 0x800C42C0: j           L_800C4574
    // 0x800C42C4: nop

        goto L_800C4574;
    // 0x800C42C4: nop

L_800C42C8:
    // 0x800C42C8: lwc1        $f0, 0x8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800C42CC: add.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f26.fl;
    // 0x800C42D0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C42D4: lwc1        $f2, 0x74A8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X74A8);
    // 0x800C42D8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800C42DC: nop

    // 0x800C42E0: bc1f        L_800C4574
    if (!c1cs) {
        // 0x800C42E4: swc1        $f0, 0x8($s3)
        MEM_W(0X8, ctx->r19) = ctx->f0.u32l;
            goto L_800C4574;
    }
    // 0x800C42E4: swc1        $f0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f0.u32l;
    // 0x800C42E8: swc1        $f2, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f2.u32l;
    // 0x800C42EC: j           L_800C4574
    // 0x800C42F0: sb          $a0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r4;
        goto L_800C4574;
    // 0x800C42F0: sb          $a0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r4;
L_800C42F4:
    // 0x800C42F4: lw          $v0, 0x14($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X14);
    // 0x800C42F8: beq         $v0, $zero, L_800C43A0
    if (ctx->r2 == 0) {
        // 0x800C42FC: lui         $s0, 0x800D
        ctx->r16 = S32(0X800D << 16);
            goto L_800C43A0;
    }
    // 0x800C42FC: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800C4300: lwc1        $f12, -0xF8C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, -0XF8C);
    // 0x800C4304: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4308: lwc1        $f0, 0x74AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X74AC);
    // 0x800C430C: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800C4310: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4314: lwc1        $f20, 0x74B0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X74B0);
    // 0x800C4318: mul.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x800C431C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4320: lwc1        $f22, 0x74B4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X74B4);
    // 0x800C4324: jal         0x8002B190
    // 0x800C4328: div.s       $f12, $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f22.fl);
    cosf_recomp(rdram, ctx);
        goto after_4;
    // 0x800C4328: div.s       $f12, $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f22.fl);
    after_4:
    // 0x800C432C: lwc1        $f12, -0xF8C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, -0XF8C);
    // 0x800C4330: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4334: lwc1        $f2, 0x74B8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X74B8);
    // 0x800C4338: mul.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x800C433C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4340: lwc1        $f24, 0x74BC($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X74BC);
    // 0x800C4344: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800C4348: nop

    // 0x800C434C: mul.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x800C4350: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x800C4354: jal         0x80033960
    // 0x800C4358: div.s       $f12, $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f22.fl);
    sinf_recomp(rdram, ctx);
        goto after_5;
    // 0x800C4358: div.s       $f12, $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f22.fl);
    after_5:
    // 0x800C435C: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800C4360: lwc1        $f12, -0xF8C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, -0XF8C);
    // 0x800C4364: mul.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x800C4368: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800C436C: jal         0x80033960
    // 0x800C4370: div.s       $f12, $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f22.fl);
    sinf_recomp(rdram, ctx);
        goto after_6;
    // 0x800C4370: div.s       $f12, $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f22.fl);
    after_6:
    // 0x800C4374: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4378: lwc1        $f2, 0x74C0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X74C0);
    // 0x800C437C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C4380: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4384: lwc1        $f2, 0x74C4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X74C4);
    // 0x800C4388: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800C438C: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    // 0x800C4390: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x800C4394: lw          $a0, 0x14($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X14);
    // 0x800C4398: jal         0x80053F7C
    // 0x800C439C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_80053F7C(rdram, ctx);
        goto after_7;
    // 0x800C439C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_7:
L_800C43A0:
    // 0x800C43A0: lbu         $v1, 0x18($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X18);
    // 0x800C43A4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800C43A8: beq         $v1, $v0, L_800C43D0
    if (ctx->r3 == ctx->r2) {
        // 0x800C43AC: addiu       $s0, $s3, 0x18
        ctx->r16 = ADD32(ctx->r19, 0X18);
            goto L_800C43D0;
    }
    // 0x800C43AC: addiu       $s0, $s3, 0x18
    ctx->r16 = ADD32(ctx->r19, 0X18);
    // 0x800C43B0: lw          $a1, 0x10($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X10);
    // 0x800C43B4: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x800C43B8: jal         0x80072BE0
    // 0x800C43BC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80072BE0(rdram, ctx);
        goto after_8;
    // 0x800C43BC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_8:
    // 0x800C43C0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C43C4: lw          $a1, 0x10($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X10);
    // 0x800C43C8: jal         0x80071928
    // 0x800C43CC: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_80071928(rdram, ctx);
        goto after_9;
    // 0x800C43CC: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_9:
L_800C43D0:
    // 0x800C43D0: lwc1        $f0, 0x4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X4);
    // 0x800C43D4: add.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f26.fl;
    // 0x800C43D8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C43DC: lwc1        $f2, 0x74C8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X74C8);
    // 0x800C43E0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800C43E4: nop

    // 0x800C43E8: bc1t        L_800C4404
    if (c1cs) {
        // 0x800C43EC: swc1        $f0, 0x4($s3)
        MEM_W(0X4, ctx->r19) = ctx->f0.u32l;
            goto L_800C4404;
    }
    // 0x800C43EC: swc1        $f0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f0.u32l;
    // 0x800C43F0: jal         0x80079F50
    // 0x800C43F4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    getControllerNewButtonsPressed(rdram, ctx);
        goto after_10;
    // 0x800C43F4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_10:
    // 0x800C43F8: andi        $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 & 0X2000;
    // 0x800C43FC: beq         $v0, $zero, L_800C4574
    if (ctx->r2 == 0) {
        // 0x800C4400: nop
    
            goto L_800C4574;
    }
    // 0x800C4400: nop

L_800C4404:
    // 0x800C4404: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800C4408: j           L_800C4574
    // 0x800C440C: sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
        goto L_800C4574;
    // 0x800C440C: sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
L_800C4410:
    // 0x800C4410: lwc1        $f0, 0x8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800C4414: sub.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f26.fl;
    // 0x800C4418: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800C441C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800C4420: nop

    // 0x800C4424: bc1f        L_800C4574
    if (!c1cs) {
        // 0x800C4428: swc1        $f0, 0x8($s3)
        MEM_W(0X8, ctx->r19) = ctx->f0.u32l;
            goto L_800C4574;
    }
    // 0x800C4428: swc1        $f0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f0.u32l;
    // 0x800C442C: lw          $a0, 0x10($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X10);
    // 0x800C4430: beq         $a0, $zero, L_800C4440
    if (ctx->r4 == 0) {
        // 0x800C4434: nop
    
            goto L_800C4440;
    }
    // 0x800C4434: nop

    // 0x800C4438: jal         0x8005779C
    // 0x800C443C: nop

    func_8005779C(rdram, ctx);
        goto after_11;
    // 0x800C443C: nop

    after_11:
L_800C4440:
    // 0x800C4440: lw          $a0, 0x14($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X14);
    // 0x800C4444: beq         $a0, $zero, L_800C4458
    if (ctx->r4 == 0) {
        // 0x800C4448: nop
    
            goto L_800C4458;
    }
    // 0x800C4448: nop

    // 0x800C444C: jal         0x80001C98
    // 0x800C4450: nop

    rs_free(rdram, ctx);
        goto after_12;
    // 0x800C4450: nop

    after_12:
    // 0x800C4454: sw          $zero, 0x14($s3)
    MEM_W(0X14, ctx->r19) = 0;
L_800C4458:
    // 0x800C4458: jal         0x80003430
    // 0x800C445C: nop

    rand_recomp(rdram, ctx);
        goto after_13;
    // 0x800C445C: nop

    after_13:
    // 0x800C4460: lui         $a1, 0x38E3
    ctx->r5 = S32(0X38E3 << 16);
    // 0x800C4464: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800C4468: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C446C: lbu         $v1, 0x1($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X1);
    // 0x800C4470: ori         $a1, $a1, 0x8E39
    ctx->r5 = ctx->r5 | 0X8E39;
    // 0x800C4474: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C4478: sb          $v1, 0x1($s3)
    MEM_B(0X1, ctx->r19) = ctx->r3;
    // 0x800C447C: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x800C4480: multu       $a0, $a1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C4484: mfhi        $t0
    ctx->r8 = hi;
    // 0x800C4488: srl         $v1, $t0, 2
    ctx->r3 = S32(U32(ctx->r8) >> 2);
    // 0x800C448C: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x800C4490: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C4494: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800C4498: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x800C449C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800C44A0: sb          $a0, 0x1($s3)
    MEM_B(0X1, ctx->r19) = ctx->r4;
    // 0x800C44A4: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x800C44A8: addiu       $s0, $v1, -0x2E7C
    ctx->r16 = ADD32(ctx->r3, -0X2E7C);
    // 0x800C44AC: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800C44B0: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800C44B4: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x800C44B8: jal         0x80056EB0
    // 0x800C44BC: nop

    func_80056EB0(rdram, ctx);
        goto after_14;
    // 0x800C44BC: nop

    after_14:
    // 0x800C44C0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800C44C4: jal         0x80054500
    // 0x800C44C8: sw          $a0, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r4;
    func_80054500(rdram, ctx);
        goto after_15;
    // 0x800C44C8: sw          $a0, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r4;
    after_15:
    // 0x800C44CC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800C44D0: sw          $a0, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r4;
    // 0x800C44D4: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    // 0x800C44D8: bgez        $v0, L_800C44EC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800C44DC: nop
    
            goto L_800C44EC;
    }
    // 0x800C44DC: nop

    // 0x800C44E0: jal         0x80001C98
    // 0x800C44E4: nop

    rs_free(rdram, ctx);
        goto after_16;
    // 0x800C44E4: nop

    after_16:
    // 0x800C44E8: sw          $zero, 0x14($s3)
    MEM_W(0X14, ctx->r19) = 0;
L_800C44EC:
    // 0x800C44EC: lw          $a1, 0x10($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X10);
    // 0x800C44F0: jal         0x80071308
    // 0x800C44F4: addiu       $a0, $s3, 0x18
    ctx->r4 = ADD32(ctx->r19, 0X18);
    func_80071308(rdram, ctx);
        goto after_17;
    // 0x800C44F4: addiu       $a0, $s3, 0x18
    ctx->r4 = ADD32(ctx->r19, 0X18);
    after_17:
    // 0x800C44F8: lbu         $v0, 0x1($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1);
    // 0x800C44FC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800C4500: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800C4504: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800C4508: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x800C450C: jal         0x800076F8
    // 0x800C4510: addiu       $a0, $a0, 0x6464
    ctx->r4 = ADD32(ctx->r4, 0X6464);
    rs_strcmp(rdram, ctx);
        goto after_18;
    // 0x800C4510: addiu       $a0, $a0, 0x6464
    ctx->r4 = ADD32(ctx->r4, 0X6464);
    after_18:
    // 0x800C4514: bnel        $v0, $zero, L_800C456C
    if (ctx->r2 != 0) {
        // 0x800C4518: swc1        $f20, 0x8($s3)
        MEM_W(0X8, ctx->r19) = ctx->f20.u32l;
            goto L_800C456C;
    }
    goto skip_1;
    // 0x800C4518: swc1        $f20, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f20.u32l;
    skip_1:
    // 0x800C451C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800C4520: addiu       $a1, $a1, 0x7490
    ctx->r5 = ADD32(ctx->r5, 0X7490);
    // 0x800C4524: lw          $a0, 0x10($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X10);
    // 0x800C4528: jal         0x80059434
    // 0x800C452C: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    func_80059434(rdram, ctx);
        goto after_19;
    // 0x800C452C: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    after_19:
    // 0x800C4530: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800C4534: addiu       $a1, $a1, 0x749C
    ctx->r5 = ADD32(ctx->r5, 0X749C);
    // 0x800C4538: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    // 0x800C453C: lw          $a0, 0x10($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X10);
    // 0x800C4540: jal         0x80059434
    // 0x800C4544: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    func_80059434(rdram, ctx);
        goto after_20;
    // 0x800C4544: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_20:
    // 0x800C4548: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C454C: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x800C4550: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x800C4554: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4558: lwc1        $f0, 0x74CC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X74CC);
    // 0x800C455C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800C4560: jal         0x800AE814
    // 0x800C4564: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800AE814(rdram, ctx);
        goto after_21;
    // 0x800C4564: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_21:
    // 0x800C4568: swc1        $f20, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f20.u32l;
L_800C456C:
    // 0x800C456C: swc1        $f20, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f20.u32l;
    // 0x800C4570: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
L_800C4574:
    // 0x800C4574: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4578: lwc1        $f2, 0x74D0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X74D0);
    // 0x800C457C: mul.s       $f2, $f26, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f26.fl, ctx->f2.fl);
    // 0x800C4580: lwc1        $f12, 0x8($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800C4584: mul.s       $f4, $f12, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f28.fl);
    // 0x800C4588: lwc1        $f0, 0xC($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XC);
    // 0x800C458C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800C4590: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4594: lwc1        $f2, 0x74D4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X74D4);
    // 0x800C4598: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x800C459C: nop

    // 0x800C45A0: bc1f        L_800C46CC
    if (!c1cs) {
        // 0x800C45A4: swc1        $f0, 0xC($s3)
        MEM_W(0XC, ctx->r19) = ctx->f0.u32l;
            goto L_800C46CC;
    }
    // 0x800C45A4: swc1        $f0, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->f0.u32l;
    // 0x800C45A8: jal         0x800662E0
    // 0x800C45AC: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    func_800662E0(rdram, ctx);
        goto after_22;
    // 0x800C45AC: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    after_22:
    // 0x800C45B0: lbu         $v0, 0x1($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1);
    // 0x800C45B4: addiu       $s2, $s2, -0x2E7C
    ctx->r18 = ADD32(ctx->r18, -0X2E7C);
    // 0x800C45B8: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800C45BC: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x800C45C0: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800C45C4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C45C8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C45CC: lwc1        $f0, 0x74D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X74D8);
    // 0x800C45D0: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C45D4: nop

    // 0x800C45D8: mul.s       $f2, $f2, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f28.fl);
    // 0x800C45DC: lw          $s0, 0x10($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X10);
    // 0x800C45E0: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // 0x800C45E4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800C45E8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C45EC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800C45F0: jal         0x8001CB64
    // 0x800C45F4: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8001CB64(rdram, ctx);
        goto after_23;
    // 0x800C45F4: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_23:
    // 0x800C45F8: lw          $a1, 0xC($s3)
    ctx->r5 = MEM_W(ctx->r19, 0XC);
    // 0x800C45FC: jal         0x8001CCCC
    // 0x800C4600: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001CCCC(rdram, ctx);
        goto after_24;
    // 0x800C4600: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_24:
    // 0x800C4604: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800C4608: lwc1        $f12, -0xF8C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, -0XF8C);
    // 0x800C460C: jal         0x80033960
    // 0x800C4610: nop

    sinf_recomp(rdram, ctx);
        goto after_25;
    // 0x800C4610: nop

    after_25:
    // 0x800C4614: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4618: lwc1        $f2, 0x74DC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X74DC);
    // 0x800C461C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C4620: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4624: lwc1        $f2, 0x74E0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X74E0);
    // 0x800C4628: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800C462C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800C4630: jal         0x8001CB9C
    // 0x800C4634: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001CB9C(rdram, ctx);
        goto after_26;
    // 0x800C4634: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_26:
    // 0x800C4638: lwc1        $f0, -0xF8C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, -0XF8C);
    // 0x800C463C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4640: lwc1        $f12, 0x74E4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X74E4);
    // 0x800C4644: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800C4648: jal         0x80033960
    // 0x800C464C: nop

    sinf_recomp(rdram, ctx);
        goto after_27;
    // 0x800C464C: nop

    after_27:
    // 0x800C4650: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4654: lwc1        $f2, 0x74E8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X74E8);
    // 0x800C4658: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C465C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800C4660: jal         0x8001CDFC
    // 0x800C4664: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001CDFC(rdram, ctx);
        goto after_28;
    // 0x800C4664: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_28:
    // 0x800C4668: lbu         $v0, 0x1($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1);
    // 0x800C466C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4670: lwc1        $f0, 0x74EC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X74EC);
    // 0x800C4674: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800C4678: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x800C467C: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800C4680: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C4684: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C4688: lui         $a3, 0x40E0
    ctx->r7 = S32(0X40E0 << 16);
    // 0x800C468C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800C4690: jal         0x8001CA90
    // 0x800C4694: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8001CA90(rdram, ctx);
        goto after_29;
    // 0x800C4694: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_29:
    // 0x800C4698: lw          $v1, 0x10($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X10);
    // 0x800C469C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800C46A0: beq         $v0, $zero, L_800C46B8
    if (ctx->r2 == 0) {
        // 0x800C46A4: sw          $v0, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->r2;
            goto L_800C46B8;
    }
    // 0x800C46A4: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x800C46A8: lw          $v0, 0x10($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X10);
    // 0x800C46AC: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800C46B0: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800C46B4: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800C46B8:
    // 0x800C46B8: lw          $v0, 0x10($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X10);
    // 0x800C46BC: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800C46C0: lw          $v0, 0x10($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X10);
    // 0x800C46C4: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800C46C8: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
L_800C46CC:
    // 0x800C46CC: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x800C46D0: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x800C46D4: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x800C46D8: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x800C46DC: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x800C46E0: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x800C46E4: ldc1        $f28, 0x98($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X98);
    // 0x800C46E8: ldc1        $f26, 0x90($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X90);
    // 0x800C46EC: ldc1        $f24, 0x88($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X88);
    // 0x800C46F0: ldc1        $f22, 0x80($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X80);
    // 0x800C46F4: ldc1        $f20, 0x78($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X78);
    // 0x800C46F8: jr          $ra
    // 0x800C46FC: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x800C46FC: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void fake_func_800C41AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800C41B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C41B0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800C41B4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800C41B8: addiu       $t0, $a2, 0x6DC0
    ctx->r8 = ADD32(ctx->r6, 0X6DC0);
    // 0x800C41BC: sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // 0x800C41C0: lh          $v1, 0x85E($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X85E);
    // 0x800C41C4: lhu         $v0, 0x3A($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X3A);
    // 0x800C41C8: addiu       $a3, $v1, -0x10
    ctx->r7 = ADD32(ctx->r3, -0X10);
    // 0x800C41CC: addiu       $t5, $v1, 0x10
    ctx->r13 = ADD32(ctx->r3, 0X10);
    // 0x800C41D0: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x800C41D4: andi        $v0, $a1, 0x1F
    ctx->r2 = ctx->r5 & 0X1F;
    // 0x800C41D8: bgez        $a1, L_800C41EC
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800C41DC: addu        $t7, $a0, $v0
        ctx->r15 = ADD32(ctx->r4, ctx->r2);
            goto L_800C41EC;
    }
    // 0x800C41DC: addu        $t7, $a0, $v0
    ctx->r15 = ADD32(ctx->r4, ctx->r2);
    // 0x800C41E0: lw          $t0, 0x6DC0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X6DC0);
    // 0x800C41E4: j           L_800C4214
    // 0x800C41E8: nop

        goto L_800C4214;
    // 0x800C41E8: nop

L_800C41EC:
    // 0x800C41EC: lhu         $v1, 0x38($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X38);
    // 0x800C41F0: slt         $v0, $a1, $v1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C41F4: bnel        $v0, $zero, L_800C420C
    if (ctx->r2 != 0) {
        // 0x800C41F8: sll         $v0, $a1, 1
        ctx->r2 = S32(ctx->r5 << 1);
            goto L_800C420C;
    }
    goto skip_0;
    // 0x800C41F8: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    skip_0:
    // 0x800C41FC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800C4200: lw          $v1, 0x6DC0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X6DC0);
    // 0x800C4204: j           L_800C4210
    // 0x800C4208: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
        goto L_800C4210;
    // 0x800C4208: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
L_800C420C:
    // 0x800C420C: lw          $v1, 0x6DC0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X6DC0);
L_800C4210:
    // 0x800C4210: addu        $t0, $v1, $v0
    ctx->r8 = ADD32(ctx->r3, ctx->r2);
L_800C4214:
    // 0x800C4214: blez        $a3, L_800C4248
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800C4218: slt         $v0, $t2, $a3
        ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_800C4248;
    }
    // 0x800C4218: slt         $v0, $t2, $a3
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800C421C: bne         $v0, $zero, L_800C4234
    if (ctx->r2 != 0) {
        // 0x800C4220: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800C4234;
    }
    // 0x800C4220: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C4224: lhu         $v0, 0x6DF8($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6DF8);
    // 0x800C4228: mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C422C: j           L_800C423C
    // 0x800C4230: nop

        goto L_800C423C;
    // 0x800C4230: nop

L_800C4234:
    // 0x800C4234: lhu         $v0, 0x6DF8($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6DF8);
    // 0x800C4238: mult        $t2, $v0
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
L_800C423C:
    // 0x800C423C: mflo        $t9
    ctx->r25 = lo;
    // 0x800C4240: sll         $v0, $t9, 1
    ctx->r2 = S32(ctx->r25 << 1);
    // 0x800C4244: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
L_800C4248:
    // 0x800C4248: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C424C: addiu       $v1, $v0, 0x6DC0
    ctx->r3 = ADD32(ctx->r2, 0X6DC0);
    // 0x800C4250: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x800C4254: slt         $v0, $a3, $t5
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800C4258: beq         $v0, $zero, L_800C4350
    if (ctx->r2 == 0) {
        // 0x800C425C: nop
    
            goto L_800C4350;
    }
    // 0x800C425C: nop

    // 0x800C4260: lui         $t1, 0x2E8B
    ctx->r9 = S32(0X2E8B << 16);
    // 0x800C4264: ori         $t1, $t1, 0xA2E9
    ctx->r9 = ctx->r9 | 0XA2E9;
    // 0x800C4268: addiu       $t4, $zero, -0x10
    ctx->r12 = ADD32(0, -0X10);
    // 0x800C426C: lui         $t3, 0xBA2E
    ctx->r11 = S32(0XBA2E << 16);
    // 0x800C4270: ori         $t3, $t3, 0x8BA3
    ctx->r11 = ctx->r11 | 0X8BA3;
    // 0x800C4274: addu        $t8, $v1, $zero
    ctx->r24 = ADD32(ctx->r3, 0);
L_800C4278:
    // 0x800C4278: lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X0);
    // 0x800C427C: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x800C4280: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x800C4284: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x800C4288: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x800C428C: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    // 0x800C4290: lb          $v1, 0x5($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X5);
    // 0x800C4294: addiu       $v1, $v1, 0x80
    ctx->r3 = ADD32(ctx->r3, 0X80);
    // 0x800C4298: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800C429C: mult        $v1, $t1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C42A0: andi        $a1, $a3, 0x1F
    ctx->r5 = ctx->r7 & 0X1F;
    // 0x800C42A4: sll         $a1, $a1, 6
    ctx->r5 = S32(ctx->r5 << 6);
    // 0x800C42A8: addu        $a1, $t7, $a1
    ctx->r5 = ADD32(ctx->r15, ctx->r5);
    // 0x800C42AC: lbu         $v0, 0x7($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X7);
    // 0x800C42B0: mfhi        $a2
    ctx->r6 = hi;
    // 0x800C42B4: addiu       $v0, $v0, -0x80
    ctx->r2 = ADD32(ctx->r2, -0X80);
    // 0x800C42B8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C42BC: multu       $v0, $t3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C42C0: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x800C42C4: sra         $v0, $a2, 2
    ctx->r2 = S32(SIGNED(ctx->r6) >> 2);
    // 0x800C42C8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800C42CC: and         $v0, $v0, $t4
    ctx->r2 = ctx->r2 & ctx->r12;
    // 0x800C42D0: mfhi        $s0
    ctx->r16 = hi;
    // 0x800C42D4: srl         $v1, $s0, 4
    ctx->r3 = S32(U32(ctx->r16) >> 4);
    // 0x800C42D8: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800C42DC: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x800C42E0: lb          $v1, 0xF($a0)
    ctx->r3 = MEM_B(ctx->r4, 0XF);
    // 0x800C42E4: addiu       $v1, $v1, 0x80
    ctx->r3 = ADD32(ctx->r3, 0X80);
    // 0x800C42E8: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800C42EC: mult        $v1, $t1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C42F0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800C42F4: lbu         $v0, 0x11($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X11);
    // 0x800C42F8: mfhi        $a2
    ctx->r6 = hi;
    // 0x800C42FC: addiu       $v0, $v0, -0x80
    ctx->r2 = ADD32(ctx->r2, -0X80);
    // 0x800C4300: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C4304: multu       $v0, $t3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C4308: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x800C430C: sra         $v0, $a2, 2
    ctx->r2 = S32(SIGNED(ctx->r6) >> 2);
    // 0x800C4310: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800C4314: and         $v0, $v0, $t4
    ctx->r2 = ctx->r2 & ctx->r12;
    // 0x800C4318: mfhi        $s0
    ctx->r16 = hi;
    // 0x800C431C: srl         $v1, $s0, 4
    ctx->r3 = S32(U32(ctx->r16) >> 4);
    // 0x800C4320: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800C4324: blez        $a3, L_800C4344
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800C4328: sb          $v0, 0x20($a1)
        MEM_B(0X20, ctx->r5) = ctx->r2;
            goto L_800C4344;
    }
    // 0x800C4328: sb          $v0, 0x20($a1)
    MEM_B(0X20, ctx->r5) = ctx->r2;
    // 0x800C432C: slt         $v0, $a3, $t2
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800C4330: beq         $v0, $zero, L_800C4348
    if (ctx->r2 == 0) {
        // 0x800C4334: slt         $v0, $a3, $t5
        ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r13) ? 1 : 0;
            goto L_800C4348;
    }
    // 0x800C4334: slt         $v0, $a3, $t5
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800C4338: lhu         $v0, 0x38($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X38);
    // 0x800C433C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800C4340: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
L_800C4344:
    // 0x800C4344: slt         $v0, $a3, $t5
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r13) ? 1 : 0;
L_800C4348:
    // 0x800C4348: bne         $v0, $zero, L_800C4278
    if (ctx->r2 != 0) {
        // 0x800C434C: nop
    
            goto L_800C4278;
    }
    // 0x800C434C: nop

L_800C4350:
    // 0x800C4350: lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X0);
    // 0x800C4354: jr          $ra
    // 0x800C4358: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800C4358: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800C435C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C435C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800C4360: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C4364: addiu       $t0, $v1, 0x6DC0
    ctx->r8 = ADD32(ctx->r3, 0X6DC0);
    // 0x800C4368: lh          $v0, 0x85C($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X85C);
    // 0x800C436C: lhu         $a1, 0x38($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0X38);
    // 0x800C4370: addiu       $a3, $v0, -0x10
    ctx->r7 = ADD32(ctx->r2, -0X10);
    // 0x800C4374: addiu       $t5, $v0, 0x10
    ctx->r13 = ADD32(ctx->r2, 0X10);
    // 0x800C4378: addiu       $t2, $a1, -0x1
    ctx->r10 = ADD32(ctx->r5, -0X1);
    // 0x800C437C: andi        $v0, $a2, 0x1F
    ctx->r2 = ctx->r6 & 0X1F;
    // 0x800C4380: sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2 << 6);
    // 0x800C4384: bgez        $a2, L_800C4398
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800C4388: addu        $t7, $a0, $v0
        ctx->r15 = ADD32(ctx->r4, ctx->r2);
            goto L_800C4398;
    }
    // 0x800C4388: addu        $t7, $a0, $v0
    ctx->r15 = ADD32(ctx->r4, ctx->r2);
    // 0x800C438C: lw          $t0, 0x6DC0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X6DC0);
    // 0x800C4390: j           L_800C43C4
    // 0x800C4394: nop

        goto L_800C43C4;
    // 0x800C4394: nop

L_800C4398:
    // 0x800C4398: lhu         $a0, 0x3A($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X3A);
    // 0x800C439C: slt         $v0, $a2, $a0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800C43A0: mult        $a2, $a1
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C43A4: bne         $v0, $zero, L_800C43B4
    if (ctx->r2 != 0) {
        // 0x800C43A8: nop
    
            goto L_800C43B4;
    }
    // 0x800C43A8: nop

    // 0x800C43AC: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x800C43B0: mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
L_800C43B4:
    // 0x800C43B4: lw          $v1, 0x6DC0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6DC0);
    // 0x800C43B8: mflo        $t8
    ctx->r24 = lo;
    // 0x800C43BC: sll         $v0, $t8, 1
    ctx->r2 = S32(ctx->r24 << 1);
    // 0x800C43C0: addu        $t0, $v1, $v0
    ctx->r8 = ADD32(ctx->r3, ctx->r2);
L_800C43C4:
    // 0x800C43C4: blez        $a3, L_800C43DC
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800C43C8: slt         $v0, $t2, $a3
        ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_800C43DC;
    }
    // 0x800C43C8: slt         $v0, $t2, $a3
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800C43CC: bne         $v0, $zero, L_800C43D8
    if (ctx->r2 != 0) {
        // 0x800C43D0: sll         $v0, $t2, 1
        ctx->r2 = S32(ctx->r10 << 1);
            goto L_800C43D8;
    }
    // 0x800C43D0: sll         $v0, $t2, 1
    ctx->r2 = S32(ctx->r10 << 1);
    // 0x800C43D4: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
L_800C43D8:
    // 0x800C43D8: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
L_800C43DC:
    // 0x800C43DC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C43E0: lw          $t6, 0x6DC4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X6DC4);
    // 0x800C43E4: slt         $v0, $a3, $t5
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800C43E8: beq         $v0, $zero, L_800C44C8
    if (ctx->r2 == 0) {
        // 0x800C43EC: lui         $t1, 0x2E8B
        ctx->r9 = S32(0X2E8B << 16);
            goto L_800C44C8;
    }
    // 0x800C43EC: lui         $t1, 0x2E8B
    ctx->r9 = S32(0X2E8B << 16);
    // 0x800C43F0: ori         $t1, $t1, 0xA2E9
    ctx->r9 = ctx->r9 | 0XA2E9;
    // 0x800C43F4: addiu       $t4, $zero, -0x10
    ctx->r12 = ADD32(0, -0X10);
    // 0x800C43F8: lui         $t3, 0xBA2E
    ctx->r11 = S32(0XBA2E << 16);
    // 0x800C43FC: ori         $t3, $t3, 0x8BA3
    ctx->r11 = ctx->r11 | 0X8BA3;
L_800C4400:
    // 0x800C4400: lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X0);
    // 0x800C4404: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x800C4408: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x800C440C: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x800C4410: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x800C4414: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    // 0x800C4418: lb          $v1, 0x5($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X5);
    // 0x800C441C: addiu       $v1, $v1, 0x80
    ctx->r3 = ADD32(ctx->r3, 0X80);
    // 0x800C4420: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800C4424: mult        $v1, $t1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C4428: andi        $a1, $a3, 0x1F
    ctx->r5 = ctx->r7 & 0X1F;
    // 0x800C442C: addu        $a1, $t7, $a1
    ctx->r5 = ADD32(ctx->r15, ctx->r5);
    // 0x800C4430: lbu         $v0, 0x7($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X7);
    // 0x800C4434: mfhi        $a2
    ctx->r6 = hi;
    // 0x800C4438: addiu       $v0, $v0, -0x80
    ctx->r2 = ADD32(ctx->r2, -0X80);
    // 0x800C443C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C4440: multu       $v0, $t3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C4444: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x800C4448: sra         $v0, $a2, 2
    ctx->r2 = S32(SIGNED(ctx->r6) >> 2);
    // 0x800C444C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800C4450: and         $v0, $v0, $t4
    ctx->r2 = ctx->r2 & ctx->r12;
    // 0x800C4454: mfhi        $t9
    ctx->r25 = hi;
    // 0x800C4458: srl         $v1, $t9, 4
    ctx->r3 = S32(U32(ctx->r25) >> 4);
    // 0x800C445C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800C4460: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x800C4464: lb          $v1, 0xF($a0)
    ctx->r3 = MEM_B(ctx->r4, 0XF);
    // 0x800C4468: addiu       $v1, $v1, 0x80
    ctx->r3 = ADD32(ctx->r3, 0X80);
    // 0x800C446C: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800C4470: mult        $v1, $t1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C4474: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800C4478: lbu         $v0, 0x11($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X11);
    // 0x800C447C: mfhi        $a2
    ctx->r6 = hi;
    // 0x800C4480: addiu       $v0, $v0, -0x80
    ctx->r2 = ADD32(ctx->r2, -0X80);
    // 0x800C4484: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C4488: multu       $v0, $t3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C448C: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x800C4490: sra         $v0, $a2, 2
    ctx->r2 = S32(SIGNED(ctx->r6) >> 2);
    // 0x800C4494: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800C4498: and         $v0, $v0, $t4
    ctx->r2 = ctx->r2 & ctx->r12;
    // 0x800C449C: mfhi        $t9
    ctx->r25 = hi;
    // 0x800C44A0: srl         $v1, $t9, 4
    ctx->r3 = S32(U32(ctx->r25) >> 4);
    // 0x800C44A4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800C44A8: blez        $a3, L_800C44BC
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800C44AC: sb          $v0, 0x20($a1)
        MEM_B(0X20, ctx->r5) = ctx->r2;
            goto L_800C44BC;
    }
    // 0x800C44AC: sb          $v0, 0x20($a1)
    MEM_B(0X20, ctx->r5) = ctx->r2;
    // 0x800C44B0: slt         $v0, $a3, $t2
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800C44B4: bnel        $v0, $zero, L_800C44BC
    if (ctx->r2 != 0) {
        // 0x800C44B8: addiu       $t0, $t0, 0x2
        ctx->r8 = ADD32(ctx->r8, 0X2);
            goto L_800C44BC;
    }
    goto skip_0;
    // 0x800C44B8: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    skip_0:
L_800C44BC:
    // 0x800C44BC: slt         $v0, $a3, $t5
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800C44C0: bne         $v0, $zero, L_800C4400
    if (ctx->r2 != 0) {
        // 0x800C44C4: nop
    
            goto L_800C4400;
    }
    // 0x800C44C4: nop

L_800C44C8:
    // 0x800C44C8: jr          $ra
    // 0x800C44CC: nop

    return;
    // 0x800C44CC: nop

;}
RECOMP_FUNC void initializeRadar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C44D0: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800C44D4: sw          $fp, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r30;
    // 0x800C44D8: addu        $fp, $a0, $zero
    ctx->r30 = ADD32(ctx->r4, 0);
    // 0x800C44DC: addiu       $a0, $zero, 0xDD4
    ctx->r4 = ADD32(0, 0XDD4);
    // 0x800C44E0: sw          $a1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r5;
    // 0x800C44E4: sw          $ra, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r31;
    // 0x800C44E8: sw          $s7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r23;
    // 0x800C44EC: sw          $s6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r22;
    // 0x800C44F0: sw          $s5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r21;
    // 0x800C44F4: sw          $s4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r20;
    // 0x800C44F8: sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // 0x800C44FC: sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // 0x800C4500: sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // 0x800C4504: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x800C4508: sdc1        $f28, 0xB0($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0XB0, ctx->r29);
    // 0x800C450C: sdc1        $f26, 0xA8($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0XA8, ctx->r29);
    // 0x800C4510: sdc1        $f24, 0xA0($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0XA0, ctx->r29);
    // 0x800C4514: sdc1        $f22, 0x98($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X98, ctx->r29);
    // 0x800C4518: sdc1        $f20, 0x90($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X90, ctx->r29);
    // 0x800C451C: jal         0x80001ACC
    // 0x800C4520: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x800C4520: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x800C4524: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800C4528: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800C452C: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x800C4530: sw          $s2, -0x4020($v1)
    MEM_W(-0X4020, ctx->r3) = ctx->r18;
    // 0x800C4534: sh          $zero, 0x85E($s2)
    MEM_H(0X85E, ctx->r18) = 0;
    // 0x800C4538: sh          $zero, 0x85C($s2)
    MEM_H(0X85C, ctx->r18) = 0;
    // 0x800C453C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_800C4540:
    // 0x800C4540: jal         0x800C41B0
    // 0x800C4544: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800C41B0(rdram, ctx);
        goto after_1;
    // 0x800C4544: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800C4548: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C454C: slti        $v0, $s0, 0x20
    ctx->r2 = SIGNED(ctx->r16) < 0X20 ? 1 : 0;
    // 0x800C4550: bne         $v0, $zero, L_800C4540
    if (ctx->r2 != 0) {
        // 0x800C4554: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_800C4540;
    }
    // 0x800C4554: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800C4558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C455C: sh          $v0, 0x800($s2)
    MEM_H(0X800, ctx->r18) = ctx->r2;
    // 0x800C4560: sb          $v0, 0x810($s2)
    MEM_B(0X810, ctx->r18) = ctx->r2;
    // 0x800C4564: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C4568: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C456C: lwc1        $f0, 0x6750($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6750);
    // 0x800C4570: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4574: lwc1        $f2, 0x6754($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6754);
    // 0x800C4578: lw          $v1, -0x35E4($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X35E4);
    // 0x800C457C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C4580: sw          $zero, 0x80C($s2)
    MEM_W(0X80C, ctx->r18) = 0;
    // 0x800C4584: andi        $v1, $v1, 0x200
    ctx->r3 = ctx->r3 & 0X200;
    // 0x800C4588: swc1        $f0, 0x804($s2)
    MEM_W(0X804, ctx->r18) = ctx->f0.u32l;
    // 0x800C458C: swc1        $f2, 0x808($s2)
    MEM_W(0X808, ctx->r18) = ctx->f2.u32l;
    // 0x800C4590: addiu       $t9, $v0, 0x6730
    ctx->r25 = ADD32(ctx->r2, 0X6730);
    // 0x800C4594: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800C4598: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x800C459C: lh          $t8, 0x8($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X8);
    // 0x800C45A0: sw          $t0, 0x814($s2)
    MEM_W(0X814, ctx->r18) = ctx->r8;
    // 0x800C45A4: sw          $t7, 0x818($s2)
    MEM_W(0X818, ctx->r18) = ctx->r15;
    // 0x800C45A8: sh          $t8, 0x81C($s2)
    MEM_H(0X81C, ctx->r18) = ctx->r24;
    // 0x800C45AC: lb          $t0, 0xA($t9)
    ctx->r8 = MEM_B(ctx->r25, 0XA);
    // 0x800C45B0: sb          $t0, 0x81E($s2)
    MEM_B(0X81E, ctx->r18) = ctx->r8;
    // 0x800C45B4: beq         $v1, $zero, L_800C45C8
    if (ctx->r3 == 0) {
        // 0x800C45B8: sw          $s2, 0x824($s2)
        MEM_W(0X824, ctx->r18) = ctx->r18;
            goto L_800C45C8;
    }
    // 0x800C45B8: sw          $s2, 0x824($s2)
    MEM_W(0X824, ctx->r18) = ctx->r18;
    // 0x800C45BC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C45C0: j           L_800C45D0
    // 0x800C45C4: addiu       $v0, $v0, -0x5FD8
    ctx->r2 = ADD32(ctx->r2, -0X5FD8);
        goto L_800C45D0;
    // 0x800C45C4: addiu       $v0, $v0, -0x5FD8
    ctx->r2 = ADD32(ctx->r2, -0X5FD8);
L_800C45C8:
    // 0x800C45C8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C45CC: addiu       $v0, $v0, -0x6008
    ctx->r2 = ADD32(ctx->r2, -0X6008);
L_800C45D0:
    // 0x800C45D0: sw          $v0, 0x844($s2)
    MEM_W(0X844, ctx->r18) = ctx->r2;
    // 0x800C45D4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C45D8: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x800C45DC: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x800C45E0: bne         $v1, $v0, L_800C45F4
    if (ctx->r3 != ctx->r2) {
        // 0x800C45E4: addiu       $a0, $s2, 0x800
        ctx->r4 = ADD32(ctx->r18, 0X800);
            goto L_800C45F4;
    }
    // 0x800C45E4: addiu       $a0, $s2, 0x800
    ctx->r4 = ADD32(ctx->r18, 0X800);
    // 0x800C45E8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C45EC: addiu       $v0, $v0, -0x5FA8
    ctx->r2 = ADD32(ctx->r2, -0X5FA8);
    // 0x800C45F0: sw          $v0, 0x844($s2)
    MEM_W(0X844, ctx->r18) = ctx->r2;
L_800C45F4:
    // 0x800C45F4: addiu       $a1, $s2, 0x824
    ctx->r5 = ADD32(ctx->r18, 0X824);
    // 0x800C45F8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C45FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C4600: sb          $v0, 0x850($s2)
    MEM_B(0X850, ctx->r18) = ctx->r2;
    // 0x800C4604: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // 0x800C4608: sh          $v0, 0x84E($s2)
    MEM_H(0X84E, ctx->r18) = ctx->r2;
    // 0x800C460C: sh          $v0, 0x84C($s2)
    MEM_H(0X84C, ctx->r18) = ctx->r2;
    // 0x800C4610: addiu       $v0, $zero, 0x300
    ctx->r2 = ADD32(0, 0X300);
    // 0x800C4614: sh          $v0, 0x852($s2)
    MEM_H(0X852, ctx->r18) = ctx->r2;
    // 0x800C4618: addiu       $v0, $s2, 0x814
    ctx->r2 = ADD32(ctx->r18, 0X814);
    // 0x800C461C: jal         0x80022B90
    // 0x800C4620: sw          $v0, 0x848($s2)
    MEM_W(0X848, ctx->r18) = ctx->r2;
    func_80022B90(rdram, ctx);
        goto after_2;
    // 0x800C4620: sw          $v0, 0x848($s2)
    MEM_W(0X848, ctx->r18) = ctx->r2;
    after_2:
    // 0x800C4624: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800C4628: addiu       $a0, $a0, 0x673C
    ctx->r4 = ADD32(ctx->r4, 0X673C);
    // 0x800C462C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C4630: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800C4634: jal         0x800554D8
    // 0x800C4638: sh          $v0, 0x858($s2)
    MEM_H(0X858, ctx->r18) = ctx->r2;
    func_800554D8(rdram, ctx);
        goto after_3;
    // 0x800C4638: sh          $v0, 0x858($s2)
    MEM_H(0X858, ctx->r18) = ctx->r2;
    after_3:
    // 0x800C463C: addiu       $a0, $s2, 0x8DC
    ctx->r4 = ADD32(ctx->r18, 0X8DC);
    // 0x800C4640: sh          $v0, 0x85A($s2)
    MEM_H(0X85A, ctx->r18) = ctx->r2;
    // 0x800C4644: lui         $v0, 0x277
    ctx->r2 = S32(0X277 << 16);
    // 0x800C4648: sw          $v0, 0x8E8($s2)
    MEM_W(0X8E8, ctx->r18) = ctx->r2;
    // 0x800C464C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x800C4650: sw          $v0, 0x8F0($s2)
    MEM_W(0X8F0, ctx->r18) = ctx->r2;
    // 0x800C4654: addiu       $v0, $s2, 0x938
    ctx->r2 = ADD32(ctx->r18, 0X938);
    // 0x800C4658: sw          $v0, 0x8FC($s2)
    MEM_W(0X8FC, ctx->r18) = ctx->r2;
    // 0x800C465C: addiu       $v0, $s2, 0x948
    ctx->r2 = ADD32(ctx->r18, 0X948);
    // 0x800C4660: sw          $zero, 0x89C($s2)
    MEM_W(0X89C, ctx->r18) = 0;
    // 0x800C4664: sw          $zero, 0x898($s2)
    MEM_W(0X898, ctx->r18) = 0;
    // 0x800C4668: sw          $zero, 0x894($s2)
    MEM_W(0X894, ctx->r18) = 0;
    // 0x800C466C: sw          $zero, 0x890($s2)
    MEM_W(0X890, ctx->r18) = 0;
    // 0x800C4670: sw          $a0, 0x8A0($s2)
    MEM_W(0X8A0, ctx->r18) = ctx->r4;
    // 0x800C4674: sw          $zero, 0x8A4($s2)
    MEM_W(0X8A4, ctx->r18) = 0;
    // 0x800C4678: sw          $zero, 0x8E0($s2)
    MEM_W(0X8E0, ctx->r18) = 0;
    // 0x800C467C: sw          $zero, 0x8DC($s2)
    MEM_W(0X8DC, ctx->r18) = 0;
    // 0x800C4680: sw          $zero, 0x8E4($s2)
    MEM_W(0X8E4, ctx->r18) = 0;
    // 0x800C4684: sw          $zero, 0x8F8($s2)
    MEM_W(0X8F8, ctx->r18) = 0;
    // 0x800C4688: sw          $zero, 0x8EC($s2)
    MEM_W(0X8EC, ctx->r18) = 0;
    // 0x800C468C: sw          $zero, 0x8F4($s2)
    MEM_W(0X8F4, ctx->r18) = 0;
    // 0x800C4690: sw          $v0, 0x900($s2)
    MEM_W(0X900, ctx->r18) = ctx->r2;
    // 0x800C4694: jal         0x8000A85C
    // 0x800C4698: sw          $zero, 0x904($s2)
    MEM_W(0X904, ctx->r18) = 0;
    func_8000A85C(rdram, ctx);
        goto after_4;
    // 0x800C4698: sw          $zero, 0x904($s2)
    MEM_W(0X904, ctx->r18) = 0;
    after_4:
    // 0x800C469C: addiu       $v0, $s2, 0x9F8
    ctx->r2 = ADD32(ctx->r18, 0X9F8);
    // 0x800C46A0: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800C46A4: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800C46A8: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800C46AC: lui         $s1, 0x90C
    ctx->r17 = S32(0X90C << 16);
    // 0x800C46B0: ori         $s1, $s1, 0x8005
    ctx->r17 = ctx->r17 | 0X8005;
    // 0x800C46B4: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x800C46B8: addiu       $t4, $zero, 0x800
    ctx->r12 = ADD32(0, 0X800);
    // 0x800C46BC: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x800C46C0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800C46C4: addiu       $t3, $zero, 0xD2
    ctx->r11 = ADD32(0, 0XD2);
    // 0x800C46C8: addiu       $t2, $zero, 0x8F
    ctx->r10 = ADD32(0, 0X8F);
    // 0x800C46CC: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x800C46D0: addiu       $v1, $s2, 0xA1B
    ctx->r3 = ADD32(ctx->r18, 0XA1B);
    // 0x800C46D4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800C46D8: sw          $zero, 0x93C($s2)
    MEM_W(0X93C, ctx->r18) = 0;
    // 0x800C46DC: sw          $zero, 0x938($s2)
    MEM_W(0X938, ctx->r18) = 0;
    // 0x800C46E0: sw          $a1, 0x940($s2)
    MEM_W(0X940, ctx->r18) = ctx->r5;
    // 0x800C46E4: sw          $v0, 0x944($s2)
    MEM_W(0X944, ctx->r18) = ctx->r2;
L_800C46E8:
    // 0x800C46E8: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800C46EC: sw          $s1, -0x1F($v1)
    MEM_W(-0X1F, ctx->r3) = ctx->r17;
    // 0x800C46F0: sw          $zero, -0x1B($v1)
    MEM_W(-0X1B, ctx->r3) = 0;
    // 0x800C46F4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800C46F8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C46FC: ori         $v0, $v0, 0x82
    ctx->r2 = ctx->r2 | 0X82;
    // 0x800C4700: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800C4704: bgez        $s0, L_800C4710
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800C4708: sh          $t5, -0x17($v1)
        MEM_H(-0X17, ctx->r3) = ctx->r13;
            goto L_800C4710;
    }
    // 0x800C4708: sh          $t5, -0x17($v1)
    MEM_H(-0X17, ctx->r3) = ctx->r13;
    // 0x800C470C: addiu       $a0, $s0, 0x7
    ctx->r4 = ADD32(ctx->r16, 0X7);
L_800C4710:
    // 0x800C4710: sra         $v0, $a0, 3
    ctx->r2 = S32(SIGNED(ctx->r4) >> 3);
    // 0x800C4714: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C4718: subu        $v0, $s0, $v0
    ctx->r2 = SUB32(ctx->r16, ctx->r2);
    // 0x800C471C: sh          $v0, -0x15($v1)
    MEM_H(-0X15, ctx->r3) = ctx->r2;
    // 0x800C4720: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    // 0x800C4724: bgez        $a0, L_800C4730
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800C4728: addu        $v0, $a0, $zero
        ctx->r2 = ADD32(ctx->r4, 0);
            goto L_800C4730;
    }
    // 0x800C4728: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x800C472C: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
L_800C4730:
    // 0x800C4730: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800C4734: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C4738: subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // 0x800C473C: sh          $v0, -0x13($v1)
    MEM_H(-0X13, ctx->r3) = ctx->r2;
    // 0x800C4740: slti        $v0, $s0, 0x8
    ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x800C4744: sh          $t4, -0xF($v1)
    MEM_H(-0XF, ctx->r3) = ctx->r12;
    // 0x800C4748: sh          $a3, -0xD($v1)
    MEM_H(-0XD, ctx->r3) = ctx->r7;
    // 0x800C474C: sh          $zero, -0xB($v1)
    MEM_H(-0XB, ctx->r3) = 0;
    // 0x800C4750: sh          $zero, -0x9($v1)
    MEM_H(-0X9, ctx->r3) = 0;
    // 0x800C4754: sh          $a3, -0x7($v1)
    MEM_H(-0X7, ctx->r3) = ctx->r7;
    // 0x800C4758: bne         $v0, $zero, L_800C4778
    if (ctx->r2 != 0) {
        // 0x800C475C: sh          $zero, -0x5($v1)
        MEM_H(-0X5, ctx->r3) = 0;
            goto L_800C4778;
    }
    // 0x800C475C: sh          $zero, -0x5($v1)
    MEM_H(-0X5, ctx->r3) = 0;
    // 0x800C4760: lhu         $v0, 0x858($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X858);
    // 0x800C4764: sb          $a2, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r6;
    // 0x800C4768: sb          $a2, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r6;
    // 0x800C476C: sb          $a2, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r6;
    // 0x800C4770: j           L_800C478C
    // 0x800C4774: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
        goto L_800C478C;
    // 0x800C4774: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
L_800C4778:
    // 0x800C4778: lhu         $v0, 0x85A($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X85A);
    // 0x800C477C: sb          $a2, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r6;
    // 0x800C4780: sb          $t2, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r10;
    // 0x800C4784: sb          $t1, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r9;
    // 0x800C4788: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
L_800C478C:
    // 0x800C478C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800C4790: sw          $v0, -0x1B($v1)
    MEM_W(-0X1B, ctx->r3) = ctx->r2;
    // 0x800C4794: addiu       $v1, $v1, 0x24
    ctx->r3 = ADD32(ctx->r3, 0X24);
    // 0x800C4798: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C479C: slti        $v0, $s0, 0x10
    ctx->r2 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x800C47A0: bne         $v0, $zero, L_800C46E8
    if (ctx->r2 != 0) {
        // 0x800C47A4: addiu       $a1, $a1, 0x24
        ctx->r5 = ADD32(ctx->r5, 0X24);
            goto L_800C46E8;
    }
    // 0x800C47A4: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    // 0x800C47A8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800C47AC: addu        $s1, $s2, $zero
    ctx->r17 = ADD32(ctx->r18, 0);
    // 0x800C47B0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C47B4: lwc1        $f28, 0x6758($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X6758);
    // 0x800C47B8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C47BC: lwc1        $f26, 0x675C($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X675C);
    // 0x800C47C0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C47C4: lwc1        $f24, 0x6760($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X6760);
    // 0x800C47C8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C47CC: lwc1        $f22, 0x6764($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X6764);
L_800C47D0:
    // 0x800C47D0: mtc1        $s0, $f20
    ctx->f20.u32l = ctx->r16;
    // 0x800C47D4: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x800C47D8: mul.s       $f20, $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f28.fl);
    // 0x800C47DC: add.s       $f20, $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f20.fl;
    // 0x800C47E0: mul.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x800C47E4: sub.s       $f20, $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x800C47E8: jal         0x80033960
    // 0x800C47EC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    sinf_recomp(rdram, ctx);
        goto after_5;
    // 0x800C47EC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_5:
    // 0x800C47F0: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800C47F4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800C47F8: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C47FC: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x800C4800: jal         0x8002B190
    // 0x800C4804: sh          $v0, 0x948($s1)
    MEM_H(0X948, ctx->r17) = ctx->r2;
    cosf_recomp(rdram, ctx);
        goto after_6;
    // 0x800C4804: sh          $v0, 0x948($s1)
    MEM_H(0X948, ctx->r17) = ctx->r2;
    after_6:
    // 0x800C4808: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800C480C: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800C4810: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C4814: sh          $zero, 0x94C($s1)
    MEM_H(0X94C, ctx->r17) = 0;
    // 0x800C4818: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C481C: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x800C4820: sh          $v0, 0x94A($s1)
    MEM_H(0X94A, ctx->r17) = ctx->r2;
    // 0x800C4824: slti        $v0, $s0, 0x8
    ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x800C4828: bne         $v0, $zero, L_800C47D0
    if (ctx->r2 != 0) {
        // 0x800C482C: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_800C47D0;
    }
    // 0x800C482C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x800C4830: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800C4834: addiu       $a0, $a0, 0x6748
    ctx->r4 = ADD32(ctx->r4, 0X6748);
    // 0x800C4838: sh          $zero, 0x998($s2)
    MEM_H(0X998, ctx->r18) = 0;
    // 0x800C483C: sh          $zero, 0x99A($s2)
    MEM_H(0X99A, ctx->r18) = 0;
    // 0x800C4840: jal         0x800C723C
    // 0x800C4844: sh          $zero, 0x99C($s2)
    MEM_H(0X99C, ctx->r18) = 0;
    func_800C723C(rdram, ctx);
        goto after_7;
    // 0x800C4844: sh          $zero, 0x99C($s2)
    MEM_H(0X99C, ctx->r18) = 0;
    after_7:
    // 0x800C4848: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800C484C: beq         $s1, $zero, L_800C4CE4
    if (ctx->r17 == 0) {
        // 0x800C4850: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_800C4CE4;
    }
    // 0x800C4850: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800C4854: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800C4858: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C485C: sb          $v0, 0xDD0($s2)
    MEM_B(0XDD0, ctx->r18) = ctx->r2;
    // 0x800C4860: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800C4864: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x800C4868: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
L_800C486C:
    // 0x800C486C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800C4870: lw          $v0, 0x24($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X24);
    // 0x800C4874: sll         $v1, $s0, 3
    ctx->r3 = S32(ctx->r16 << 3);
    // 0x800C4878: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800C487C: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x800C4880: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C4884: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C4888: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C488C: add.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C4890: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x800C4894: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800C4898: lw          $v0, 0x24($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X24);
    // 0x800C489C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800C48A0: lh          $v0, 0x2($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2);
    // 0x800C48A4: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C48A8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C48AC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C48B0: add.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C48B4: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x800C48B8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800C48BC: lw          $v0, 0x24($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X24);
    // 0x800C48C0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C48C4: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x800C48C8: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C48CC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C48D0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C48D4: add.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C48D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C48DC: sltiu       $v0, $s0, 0x9
    ctx->r2 = ctx->r16 < 0X9 ? 1 : 0;
    // 0x800C48E0: bne         $v0, $zero, L_800C486C
    if (ctx->r2 != 0) {
        // 0x800C48E4: swc1        $f4, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
            goto L_800C486C;
    }
    // 0x800C48E4: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x800C48E8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C48EC: lwc1        $f0, 0x6768($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6768);
    // 0x800C48F0: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800C48F4: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x800C48F8: div.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800C48FC: div.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800C4900: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x800C4904: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800C4908: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800C490C: lw          $v0, 0x24($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X24);
    // 0x800C4910: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800C4914: sh          $v0, 0x9F0($s2)
    MEM_H(0X9F0, ctx->r18) = ctx->r2;
    // 0x800C4918: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800C491C: lw          $v0, 0x24($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X24);
    // 0x800C4920: lhu         $v0, 0x2($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X2);
    // 0x800C4924: sh          $v0, 0x9F2($s2)
    MEM_H(0X9F2, ctx->r18) = ctx->r2;
    // 0x800C4928: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800C492C: lw          $v0, 0x24($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X24);
    // 0x800C4930: lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4);
    // 0x800C4934: sh          $v0, 0x9F4($s2)
    MEM_H(0X9F4, ctx->r18) = ctx->r2;
    // 0x800C4938: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800C493C: lw          $v0, 0x24($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X24);
    // 0x800C4940: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x800C4944: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C4948: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800C494C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C4950: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800C4954: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x800C4958: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800C495C: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800C4960: lw          $v0, 0x24($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X24);
    // 0x800C4964: lh          $v0, 0x2($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2);
    // 0x800C4968: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C496C: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800C4970: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800C4974: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800C4978: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x800C497C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800C4980: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800C4984: lw          $v0, 0x24($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X24);
    // 0x800C4988: lh          $v0, 0x4($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X4);
    // 0x800C498C: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C4990: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C4994: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C4998: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800C499C: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C49A0: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // 0x800C49A4: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800C49A8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800C49AC: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800C49B0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
L_800C49B4:
    // 0x800C49B4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800C49B8: lw          $v0, 0x24($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X24);
    // 0x800C49BC: sll         $v1, $s0, 3
    ctx->r3 = S32(ctx->r16 << 3);
    // 0x800C49C0: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800C49C4: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x800C49C8: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C49CC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800C49D0: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C49D4: sub.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800C49D8: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x800C49DC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800C49E0: lw          $v0, 0x24($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X24);
    // 0x800C49E4: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800C49E8: lh          $v0, 0x2($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2);
    // 0x800C49EC: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C49F0: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800C49F4: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800C49F8: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800C49FC: mul.s       $f6, $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800C4A00: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x800C4A04: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800C4A08: lw          $v0, 0x24($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X24);
    // 0x800C4A0C: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800C4A10: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800C4A14: lh          $v0, 0x4($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X4);
    // 0x800C4A18: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C4A1C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C4A20: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C4A24: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800C4A28: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C4A2C: add.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x800C4A30: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800C4A34: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x800C4A38: nop

    // 0x800C4A3C: bc1f        L_800C4A88
    if (!c1cs) {
        // 0x800C4A40: swc1        $f0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
            goto L_800C4A88;
    }
    // 0x800C4A40: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800C4A44: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800C4A48: lw          $v0, 0x24($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X24);
    // 0x800C4A4C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800C4A50: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800C4A54: sh          $v0, 0x9F0($s2)
    MEM_H(0X9F0, ctx->r18) = ctx->r2;
    // 0x800C4A58: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800C4A5C: lw          $v0, 0x24($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X24);
    // 0x800C4A60: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800C4A64: lhu         $v0, 0x2($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X2);
    // 0x800C4A68: sh          $v0, 0x9F2($s2)
    MEM_H(0X9F2, ctx->r18) = ctx->r2;
    // 0x800C4A6C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800C4A70: lw          $v0, 0x24($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X24);
    // 0x800C4A74: mov.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = ctx->f6.fl;
    // 0x800C4A78: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800C4A7C: lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4);
    // 0x800C4A80: addu        $s7, $s0, $zero
    ctx->r23 = ADD32(ctx->r16, 0);
    // 0x800C4A84: sh          $v0, 0x9F4($s2)
    MEM_H(0X9F4, ctx->r18) = ctx->r2;
L_800C4A88:
    // 0x800C4A88: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C4A8C: sltiu       $v0, $s0, 0x9
    ctx->r2 = ctx->r16 < 0X9 ? 1 : 0;
    // 0x800C4A90: bne         $v0, $zero, L_800C49B4
    if (ctx->r2 != 0) {
        // 0x800C4A94: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_800C49B4;
    }
    // 0x800C4A94: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x800C4A98: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
    // 0x800C4A9C: sll         $s6, $s7, 3
    ctx->r22 = S32(ctx->r23 << 3);
    // 0x800C4AA0: addiu       $s5, $sp, 0x48
    ctx->r21 = ADD32(ctx->r29, 0X48);
    // 0x800C4AA4: addu        $s4, $s3, $zero
    ctx->r20 = ADD32(ctx->r19, 0);
L_800C4AA8:
    // 0x800C4AA8: beql        $s0, $s7, L_800C4BF4
    if (ctx->r16 == ctx->r23) {
        // 0x800C4AAC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800C4BF4;
    }
    goto skip_0;
    // 0x800C4AAC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x800C4AB0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800C4AB4: lw          $v1, 0x24($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X24);
    // 0x800C4AB8: addu        $v0, $s4, $v1
    ctx->r2 = ADD32(ctx->r20, ctx->r3);
    // 0x800C4ABC: addu        $v1, $s6, $v1
    ctx->r3 = ADD32(ctx->r22, ctx->r3);
    // 0x800C4AC0: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x800C4AC4: lh          $v1, 0x0($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X0);
    // 0x800C4AC8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800C4ACC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C4AD0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C4AD4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800C4AD8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800C4ADC: lw          $v0, 0x24($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X24);
    // 0x800C4AE0: addu        $v1, $s4, $v0
    ctx->r3 = ADD32(ctx->r20, ctx->r2);
    // 0x800C4AE4: addu        $v0, $s6, $v0
    ctx->r2 = ADD32(ctx->r22, ctx->r2);
    // 0x800C4AE8: lh          $v1, 0x2($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X2);
    // 0x800C4AEC: lh          $v0, 0x2($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2);
    // 0x800C4AF0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800C4AF4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800C4AF8: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800C4AFC: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x800C4B00: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C4B04: jal         0x8001CF58
    // 0x800C4B08: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    normalize_vector(rdram, ctx);
        goto after_8;
    // 0x800C4B08: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x800C4B0C: lwc1        $f14, 0x14($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C4B10: lwc1        $f12, 0x10($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800C4B14: jal         0x8001C5F4
    // 0x800C4B18: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    func_8001C5F4(rdram, ctx);
        goto after_9;
    // 0x800C4B18: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    after_9:
    // 0x800C4B1C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C4B20: beq         $s3, $zero, L_800C4B50
    if (ctx->r19 == 0) {
        // 0x800C4B24: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800C4B50;
    }
    // 0x800C4B24: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800C4B28: addu        $v1, $s5, $zero
    ctx->r3 = ADD32(ctx->r21, 0);
L_800C4B2C:
    // 0x800C4B2C: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800C4B30: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800C4B34: nop

    // 0x800C4B38: bc1t        L_800C4B50
    if (c1cs) {
        // 0x800C4B3C: nop
    
            goto L_800C4B50;
    }
    // 0x800C4B3C: nop

    // 0x800C4B40: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800C4B44: sltu        $v0, $a2, $s3
    ctx->r2 = ctx->r6 < ctx->r19 ? 1 : 0;
    // 0x800C4B48: bne         $v0, $zero, L_800C4B2C
    if (ctx->r2 != 0) {
        // 0x800C4B4C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800C4B2C;
    }
    // 0x800C4B4C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800C4B50:
    // 0x800C4B50: beq         $s3, $a2, L_800C4BAC
    if (ctx->r19 == ctx->r6) {
        // 0x800C4B54: addu        $a1, $s3, $zero
        ctx->r5 = ADD32(ctx->r19, 0);
            goto L_800C4BAC;
    }
    // 0x800C4B54: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
L_800C4B58:
    // 0x800C4B58: sll         $v1, $a1, 3
    ctx->r3 = S32(ctx->r5 << 3);
    // 0x800C4B5C: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
    // 0x800C4B60: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x800C4B64: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800C4B68: addu        $v1, $s2, $v1
    ctx->r3 = ADD32(ctx->r18, ctx->r3);
    // 0x800C4B6C: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x800C4B70: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x800C4B74: lwl         $t7, 0x9A0($v0)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r2, 0X9A0);
    // 0x800C4B78: lwr         $t7, 0x9A3($v0)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r2, 0X9A3);
    // 0x800C4B7C: lwl         $t8, 0x9A4($v0)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r2, 0X9A4);
    // 0x800C4B80: lwr         $t8, 0x9A7($v0)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r2, 0X9A7);
    // 0x800C4B84: swl         $t7, 0x9A0($v1)
    do_swl(rdram, 0X9A0, ctx->r3, ctx->r15);
    // 0x800C4B88: swr         $t7, 0x9A3($v1)
    do_swr(rdram, 0X9A3, ctx->r3, ctx->r15);
    // 0x800C4B8C: swl         $t8, 0x9A4($v1)
    do_swl(rdram, 0X9A4, ctx->r3, ctx->r24);
    // 0x800C4B90: swr         $t8, 0x9A7($v1)
    do_swr(rdram, 0X9A7, ctx->r3, ctx->r24);
    // 0x800C4B94: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800C4B98: addu        $v0, $s5, $v0
    ctx->r2 = ADD32(ctx->r21, ctx->r2);
    // 0x800C4B9C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800C4BA0: addu        $a0, $s5, $a0
    ctx->r4 = ADD32(ctx->r21, ctx->r4);
    // 0x800C4BA4: bne         $a1, $a2, L_800C4B58
    if (ctx->r5 != ctx->r6) {
        // 0x800C4BA8: swc1        $f0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
            goto L_800C4B58;
    }
    // 0x800C4BA8: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
L_800C4BAC:
    // 0x800C4BAC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800C4BB0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800C4BB4: sll         $v1, $a2, 3
    ctx->r3 = S32(ctx->r6 << 3);
    // 0x800C4BB8: lw          $v0, 0x24($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X24);
    // 0x800C4BBC: addu        $v1, $s2, $v1
    ctx->r3 = ADD32(ctx->r18, ctx->r3);
    // 0x800C4BC0: addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // 0x800C4BC4: lwl         $t7, 0x0($v0)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r2, 0X0);
    // 0x800C4BC8: lwr         $t7, 0x3($v0)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r2, 0X3);
    // 0x800C4BCC: lwl         $t8, 0x4($v0)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r2, 0X4);
    // 0x800C4BD0: lwr         $t8, 0x7($v0)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r2, 0X7);
    // 0x800C4BD4: swl         $t7, 0x9A0($v1)
    do_swl(rdram, 0X9A0, ctx->r3, ctx->r15);
    // 0x800C4BD8: swr         $t7, 0x9A3($v1)
    do_swr(rdram, 0X9A3, ctx->r3, ctx->r15);
    // 0x800C4BDC: swl         $t8, 0x9A4($v1)
    do_swl(rdram, 0X9A4, ctx->r3, ctx->r24);
    // 0x800C4BE0: swr         $t8, 0x9A7($v1)
    do_swr(rdram, 0X9A7, ctx->r3, ctx->r24);
    // 0x800C4BE4: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x800C4BE8: addu        $v0, $s5, $v0
    ctx->r2 = ADD32(ctx->r21, ctx->r2);
    // 0x800C4BEC: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x800C4BF0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800C4BF4:
    // 0x800C4BF4: sltiu       $v0, $s0, 0x9
    ctx->r2 = ctx->r16 < 0X9 ? 1 : 0;
    // 0x800C4BF8: bne         $v0, $zero, L_800C4AA8
    if (ctx->r2 != 0) {
        // 0x800C4BFC: addiu       $s4, $s4, 0x8
        ctx->r20 = ADD32(ctx->r20, 0X8);
            goto L_800C4AA8;
    }
    // 0x800C4BFC: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x800C4C00: addiu       $v1, $s3, -0x1
    ctx->r3 = ADD32(ctx->r19, -0X1);
    // 0x800C4C04: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x800C4C08: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x800C4C0C: lwl         $t7, 0x9A0($v0)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r2, 0X9A0);
    // 0x800C4C10: lwr         $t7, 0x9A3($v0)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r2, 0X9A3);
    // 0x800C4C14: lwl         $t8, 0x9A4($v0)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r2, 0X9A4);
    // 0x800C4C18: lwr         $t8, 0x9A7($v0)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r2, 0X9A7);
    // 0x800C4C1C: swl         $t7, 0x40($sp)
    do_swl(rdram, 0X40, ctx->r29, ctx->r15);
    // 0x800C4C20: swr         $t7, 0x43($sp)
    do_swr(rdram, 0X43, ctx->r29, ctx->r15);
    // 0x800C4C24: swl         $t8, 0x44($sp)
    do_swl(rdram, 0X44, ctx->r29, ctx->r24);
    // 0x800C4C28: swr         $t8, 0x47($sp)
    do_swr(rdram, 0X47, ctx->r29, ctx->r24);
    // 0x800C4C2C: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    // 0x800C4C30: beq         $s0, $zero, L_800C4C74
    if (ctx->r16 == 0) {
        // 0x800C4C34: sll         $v1, $s0, 3
        ctx->r3 = S32(ctx->r16 << 3);
            goto L_800C4C74;
    }
    // 0x800C4C34: sll         $v1, $s0, 3
    ctx->r3 = S32(ctx->r16 << 3);
L_800C4C38:
    // 0x800C4C38: addu        $v1, $s2, $v1
    ctx->r3 = ADD32(ctx->r18, ctx->r3);
    // 0x800C4C3C: addiu       $a0, $s0, -0x1
    ctx->r4 = ADD32(ctx->r16, -0X1);
    // 0x800C4C40: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x800C4C44: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x800C4C48: lwl         $t7, 0x9A0($v0)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r2, 0X9A0);
    // 0x800C4C4C: lwr         $t7, 0x9A3($v0)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r2, 0X9A3);
    // 0x800C4C50: lwl         $t8, 0x9A4($v0)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r2, 0X9A4);
    // 0x800C4C54: lwr         $t8, 0x9A7($v0)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r2, 0X9A7);
    // 0x800C4C58: swl         $t7, 0x9A0($v1)
    do_swl(rdram, 0X9A0, ctx->r3, ctx->r15);
    // 0x800C4C5C: swr         $t7, 0x9A3($v1)
    do_swr(rdram, 0X9A3, ctx->r3, ctx->r15);
    // 0x800C4C60: swl         $t8, 0x9A4($v1)
    do_swl(rdram, 0X9A4, ctx->r3, ctx->r24);
    // 0x800C4C64: swr         $t8, 0x9A7($v1)
    do_swr(rdram, 0X9A7, ctx->r3, ctx->r24);
    // 0x800C4C68: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800C4C6C: bne         $s0, $zero, L_800C4C38
    if (ctx->r16 != 0) {
        // 0x800C4C70: sll         $v1, $s0, 3
        ctx->r3 = S32(ctx->r16 << 3);
            goto L_800C4C38;
    }
    // 0x800C4C70: sll         $v1, $s0, 3
    ctx->r3 = S32(ctx->r16 << 3);
L_800C4C74:
    // 0x800C4C74: lwl         $t7, 0x40($sp)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r29, 0X40);
    // 0x800C4C78: lwr         $t7, 0x43($sp)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r29, 0X43);
    // 0x800C4C7C: lwl         $t8, 0x44($sp)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r29, 0X44);
    // 0x800C4C80: lwr         $t8, 0x47($sp)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r29, 0X47);
    // 0x800C4C84: swl         $t7, 0x9A0($s2)
    do_swl(rdram, 0X9A0, ctx->r18, ctx->r15);
    // 0x800C4C88: swr         $t7, 0x9A3($s2)
    do_swr(rdram, 0X9A3, ctx->r18, ctx->r15);
    // 0x800C4C8C: swl         $t8, 0x9A4($s2)
    do_swl(rdram, 0X9A4, ctx->r18, ctx->r24);
    // 0x800C4C90: swr         $t8, 0x9A7($s2)
    do_swr(rdram, 0X9A7, ctx->r18, ctx->r24);
    // 0x800C4C94: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800C4C98: lw          $a1, 0x20($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X20);
    // 0x800C4C9C: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x800C4CA0: lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X8);
    // 0x800C4CA4: beq         $v0, $zero, L_800C4CE8
    if (ctx->r2 == 0) {
        // 0x800C4CA8: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_800C4CE8;
    }
    // 0x800C4CA8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800C4CAC: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
L_800C4CB0:
    // 0x800C4CB0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C4CB4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C4CB8: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x800C4CBC: ori         $v0, $v0, 0x100
    ctx->r2 = ctx->r2 | 0X100;
    // 0x800C4CC0: and         $v1, $v1, $a2
    ctx->r3 = ctx->r3 & ctx->r6;
    // 0x800C4CC4: srl         $v1, $v1, 22
    ctx->r3 = S32(U32(ctx->r3) >> 22);
    // 0x800C4CC8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800C4CCC: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x800C4CD0: sltu        $v0, $s0, $v0
    ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800C4CD4: bne         $v0, $zero, L_800C4CB0
    if (ctx->r2 != 0) {
        // 0x800C4CD8: addu        $a0, $a0, $v1
        ctx->r4 = ADD32(ctx->r4, ctx->r3);
            goto L_800C4CB0;
    }
    // 0x800C4CD8: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x800C4CDC: j           L_800C4CEC
    // 0x800C4CE0: addiu       $s0, $s2, 0x860
    ctx->r16 = ADD32(ctx->r18, 0X860);
        goto L_800C4CEC;
    // 0x800C4CE0: addiu       $s0, $s2, 0x860
    ctx->r16 = ADD32(ctx->r18, 0X860);
L_800C4CE4:
    // 0x800C4CE4: sb          $zero, 0xDD0($s2)
    MEM_B(0XDD0, ctx->r18) = 0;
L_800C4CE8:
    // 0x800C4CE8: addiu       $s0, $s2, 0x860
    ctx->r16 = ADD32(ctx->r18, 0X860);
L_800C4CEC:
    // 0x800C4CEC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4CF0: lwc1        $f0, 0x676C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X676C);
    // 0x800C4CF4: addiu       $v0, $s2, 0x890
    ctx->r2 = ADD32(ctx->r18, 0X890);
    // 0x800C4CF8: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
    // 0x800C4CFC: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x800C4D00: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800C4D04: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C4D08: sw          $s0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r16;
    // 0x800C4D0C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800C4D10: jal         0x8001CB64
    // 0x800C4D14: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8001CB64(rdram, ctx);
        goto after_10;
    // 0x800C4D14: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_10:
    // 0x800C4D18: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C4D1C: lui         $a2, 0xBE80
    ctx->r6 = S32(0XBE80 << 16);
    // 0x800C4D20: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800C4D24: jal         0x8001CA90
    // 0x800C4D28: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8001CA90(rdram, ctx);
        goto after_11;
    // 0x800C4D28: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_11:
    // 0x800C4D2C: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x800C4D30: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4D34: lwc1        $f0, 0x6770($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6770);
    // 0x800C4D38: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800C4D3C: sh          $zero, 0xDB8($v0)
    MEM_H(0XDB8, ctx->r2) = 0;
    // 0x800C4D40: sh          $v1, 0xDC8($v0)
    MEM_H(0XDC8, ctx->r2) = ctx->r3;
    // 0x800C4D44: swc1        $f0, 0xDCC($v0)
    MEM_W(0XDCC, ctx->r2) = ctx->f0.u32l;
    // 0x800C4D48: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
    // 0x800C4D4C: lw          $fp, 0x88($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X88);
    // 0x800C4D50: lw          $s7, 0x84($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X84);
    // 0x800C4D54: lw          $s6, 0x80($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X80);
    // 0x800C4D58: lw          $s5, 0x7C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X7C);
    // 0x800C4D5C: lw          $s4, 0x78($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X78);
    // 0x800C4D60: lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X74);
    // 0x800C4D64: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x800C4D68: lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6C);
    // 0x800C4D6C: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x800C4D70: ldc1        $f28, 0xB0($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0XB0);
    // 0x800C4D74: ldc1        $f26, 0xA8($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0XA8);
    // 0x800C4D78: ldc1        $f24, 0xA0($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0XA0);
    // 0x800C4D7C: ldc1        $f22, 0x98($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X98);
    // 0x800C4D80: ldc1        $f20, 0x90($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X90);
    // 0x800C4D84: jr          $ra
    // 0x800C4D88: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x800C4D88: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void getPlayerRankString(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4700: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C4704: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800C4708: jal         0x8005589C
    // 0x800C470C: addiu       $a0, $a0, 0x92
    ctx->r4 = ADD32(ctx->r4, 0X92);
    getGameOrFrontText(rdram, ctx);
        goto after_0;
    // 0x800C470C: addiu       $a0, $a0, 0x92
    ctx->r4 = ADD32(ctx->r4, 0X92);
    after_0:
    // 0x800C4710: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800C4714: jr          $ra
    // 0x800C4718: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C4718: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800C471C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C471C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C4720: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C4724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C4728: jal         0x800B3F00
    // 0x800C472C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_800B3F00(rdram, ctx);
        goto after_0;
    // 0x800C472C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x800C4730: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x800C4734: beq         $s0, $zero, L_800C4744
    if (ctx->r16 == 0) {
        // 0x800C4738: nop
    
            goto L_800C4744;
    }
    // 0x800C4738: nop

    // 0x800C473C: jal         0x800678E4
    // 0x800C4740: nop

    func_800678E4(rdram, ctx);
        goto after_1;
    // 0x800C4740: nop

    after_1:
L_800C4744:
    // 0x800C4744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C4748: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C474C: jr          $ra
    // 0x800C4750: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C4750: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800C4754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4754: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C4758: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800C475C: jal         0x80066918
    // 0x800C4760: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80066918(rdram, ctx);
        goto after_0;
    // 0x800C4760: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800C4764: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800C4768: lw          $a0, -0x76E0($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X76E0);
    // 0x800C476C: jal         0x8006657C
    // 0x800C4770: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8006657C(rdram, ctx);
        goto after_1;
    // 0x800C4770: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x800C4774: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    // 0x800C4778: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x800C477C: jal         0x8008E0B0
    // 0x800C4780: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    func_8008E0B0(rdram, ctx);
        goto after_2;
    // 0x800C4780: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    after_2:
    // 0x800C4784: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x800C4788: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x800C478C: jal         0x8008E0B0
    // 0x800C4790: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    func_8008E0B0(rdram, ctx);
        goto after_3;
    // 0x800C4790: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    after_3:
    // 0x800C4794: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800C4798: addiu       $a0, $v1, -0x1900
    ctx->r4 = ADD32(ctx->r3, -0X1900);
    // 0x800C479C: addiu       $v0, $zero, 0xA0
    ctx->r2 = ADD32(0, 0XA0);
    // 0x800C47A0: sh          $v0, -0x1900($v1)
    MEM_H(-0X1900, ctx->r3) = ctx->r2;
    // 0x800C47A4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C47A8: addiu       $v0, $zero, 0x9B
    ctx->r2 = ADD32(0, 0X9B);
    // 0x800C47AC: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    // 0x800C47B0: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x800C47B4: sb          $v0, 0x12($a0)
    MEM_B(0X12, ctx->r4) = ctx->r2;
    // 0x800C47B8: addiu       $v0, $zero, 0x41
    ctx->r2 = ADD32(0, 0X41);
    // 0x800C47BC: sb          $v0, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r2;
    // 0x800C47C0: addiu       $v0, $zero, 0x51E
    ctx->r2 = ADD32(0, 0X51E);
    // 0x800C47C4: sh          $v0, 0x1E($a0)
    MEM_H(0X1E, ctx->r4) = ctx->r2;
    // 0x800C47C8: addiu       $v0, $zero, 0xF5C
    ctx->r2 = ADD32(0, 0XF5C);
    // 0x800C47CC: sh          $v0, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r2;
    // 0x800C47D0: addiu       $v0, $zero, 0x1999
    ctx->r2 = ADD32(0, 0X1999);
    // 0x800C47D4: sh          $v0, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r2;
    // 0x800C47D8: addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    // 0x800C47DC: sb          $v1, 0x1A($a0)
    MEM_B(0X1A, ctx->r4) = ctx->r3;
    // 0x800C47E0: sb          $v1, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r3;
    // 0x800C47E4: jal         0x8008E8D8
    // 0x800C47E8: sh          $v0, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r2;
    func_8008E8D8(rdram, ctx);
        goto after_4;
    // 0x800C47E8: sh          $v0, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r2;
    after_4:
    // 0x800C47EC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800C47F0: jr          $ra
    // 0x800C47F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C47F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800C47F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C47F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C47FC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x800C4800: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C4804: jal         0x80066918
    // 0x800C4808: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80066918(rdram, ctx);
        goto after_0;
    // 0x800C4808: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x800C480C: jal         0x80066918
    // 0x800C4810: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    func_80066918(rdram, ctx);
        goto after_1;
    // 0x800C4810: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_1:
    // 0x800C4814: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800C4818: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x800C481C: jal         0x8006657C
    // 0x800C4820: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_8006657C(rdram, ctx);
        goto after_2;
    // 0x800C4820: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_2:
    // 0x800C4824: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x800C4828: jal         0x8006657C
    // 0x800C482C: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    func_8006657C(rdram, ctx);
        goto after_3;
    // 0x800C482C: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    after_3:
    // 0x800C4830: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x800C4834: jal         0x8006657C
    // 0x800C4838: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    func_8006657C(rdram, ctx);
        goto after_4;
    // 0x800C4838: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    after_4:
    // 0x800C483C: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x800C4840: jal         0x8006657C
    // 0x800C4844: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    func_8006657C(rdram, ctx);
        goto after_5;
    // 0x800C4844: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    after_5:
    // 0x800C4848: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    // 0x800C484C: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x800C4850: jal         0x8008E0B0
    // 0x800C4854: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    func_8008E0B0(rdram, ctx);
        goto after_6;
    // 0x800C4854: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    after_6:
    // 0x800C4858: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x800C485C: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x800C4860: jal         0x8008E0B0
    // 0x800C4864: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    func_8008E0B0(rdram, ctx);
        goto after_7;
    // 0x800C4864: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    after_7:
    // 0x800C4868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C486C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C4870: jr          $ra
    // 0x800C4874: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C4874: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800C4878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4878: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C487C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800C4880: jal         0x80066918
    // 0x800C4884: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    func_80066918(rdram, ctx);
        goto after_0;
    // 0x800C4884: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_0:
    // 0x800C4888: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800C488C: lw          $a0, -0x76E0($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X76E0);
    // 0x800C4890: jal         0x8006657C
    // 0x800C4894: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    func_8006657C(rdram, ctx);
        goto after_1;
    // 0x800C4894: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    after_1:
    // 0x800C4898: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    // 0x800C489C: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x800C48A0: jal         0x8008E0B0
    // 0x800C48A4: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    func_8008E0B0(rdram, ctx);
        goto after_2;
    // 0x800C48A4: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    after_2:
    // 0x800C48A8: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x800C48AC: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x800C48B0: jal         0x8008E0B0
    // 0x800C48B4: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    func_8008E0B0(rdram, ctx);
        goto after_3;
    // 0x800C48B4: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    after_3:
    // 0x800C48B8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800C48BC: addiu       $a0, $v1, -0xFE0
    ctx->r4 = ADD32(ctx->r3, -0XFE0);
    // 0x800C48C0: addiu       $v0, $zero, 0xA0
    ctx->r2 = ADD32(0, 0XA0);
    // 0x800C48C4: sh          $v0, -0xFE0($v1)
    MEM_H(-0XFE0, ctx->r3) = ctx->r2;
    // 0x800C48C8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C48CC: addiu       $v0, $zero, 0x9B
    ctx->r2 = ADD32(0, 0X9B);
    // 0x800C48D0: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    // 0x800C48D4: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x800C48D8: sb          $v0, 0x12($a0)
    MEM_B(0X12, ctx->r4) = ctx->r2;
    // 0x800C48DC: addiu       $v0, $zero, 0x41
    ctx->r2 = ADD32(0, 0X41);
    // 0x800C48E0: sb          $v0, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r2;
    // 0x800C48E4: addiu       $v0, $zero, 0x51E
    ctx->r2 = ADD32(0, 0X51E);
    // 0x800C48E8: sh          $v0, 0x1E($a0)
    MEM_H(0X1E, ctx->r4) = ctx->r2;
    // 0x800C48EC: addiu       $v0, $zero, 0xF5C
    ctx->r2 = ADD32(0, 0XF5C);
    // 0x800C48F0: sh          $v0, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r2;
    // 0x800C48F4: addiu       $v0, $zero, 0x1999
    ctx->r2 = ADD32(0, 0X1999);
    // 0x800C48F8: sh          $v0, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r2;
    // 0x800C48FC: addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    // 0x800C4900: sb          $v1, 0x1A($a0)
    MEM_B(0X1A, ctx->r4) = ctx->r3;
    // 0x800C4904: sb          $v1, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r3;
    // 0x800C4908: jal         0x8008E8D8
    // 0x800C490C: sh          $v0, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r2;
    func_8008E8D8(rdram, ctx);
        goto after_4;
    // 0x800C490C: sh          $v0, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r2;
    after_4:
    // 0x800C4910: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800C4914: jr          $ra
    // 0x800C4918: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C4918: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800C491C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C491C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C4920: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800C4924: addiu       $a0, $v0, -0x1010
    ctx->r4 = ADD32(ctx->r2, -0X1010);
    // 0x800C4928: addiu       $v1, $zero, 0xA0
    ctx->r3 = ADD32(0, 0XA0);
    // 0x800C492C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C4930: sh          $v1, -0x1010($v0)
    MEM_H(-0X1010, ctx->r2) = ctx->r3;
    // 0x800C4934: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x800C4938: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800C493C: sb          $v0, 0x12($a0)
    MEM_B(0X12, ctx->r4) = ctx->r2;
    // 0x800C4940: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // 0x800C4944: sb          $v0, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r2;
    // 0x800C4948: addiu       $v0, $zero, 0x51E
    ctx->r2 = ADD32(0, 0X51E);
    // 0x800C494C: sh          $v0, 0x1E($a0)
    MEM_H(0X1E, ctx->r4) = ctx->r2;
    // 0x800C4950: addiu       $v0, $zero, 0xF5C
    ctx->r2 = ADD32(0, 0XF5C);
    // 0x800C4954: sh          $v0, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r2;
    // 0x800C4958: addiu       $v0, $zero, 0x1999
    ctx->r2 = ADD32(0, 0X1999);
    // 0x800C495C: sh          $v0, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r2;
    // 0x800C4960: addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    // 0x800C4964: sb          $a1, 0x1A($a0)
    MEM_B(0X1A, ctx->r4) = ctx->r5;
    // 0x800C4968: sh          $v1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r3;
    // 0x800C496C: sb          $a1, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r5;
    // 0x800C4970: jal         0x8008E8D8
    // 0x800C4974: sh          $v0, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r2;
    func_8008E8D8(rdram, ctx);
        goto after_0;
    // 0x800C4974: sh          $v0, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r2;
    after_0:
    // 0x800C4978: jal         0x80066918
    // 0x800C497C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_80066918(rdram, ctx);
        goto after_1;
    // 0x800C497C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_1:
    // 0x800C4980: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800C4984: lw          $a0, -0x76E0($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X76E0);
    // 0x800C4988: jal         0x8006657C
    // 0x800C498C: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    func_8006657C(rdram, ctx);
        goto after_2;
    // 0x800C498C: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    after_2:
    // 0x800C4990: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    // 0x800C4994: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x800C4998: jal         0x8008E0B0
    // 0x800C499C: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    func_8008E0B0(rdram, ctx);
        goto after_3;
    // 0x800C499C: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    after_3:
    // 0x800C49A0: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x800C49A4: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x800C49A8: jal         0x8008E0B0
    // 0x800C49AC: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    func_8008E0B0(rdram, ctx);
        goto after_4;
    // 0x800C49AC: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    after_4:
    // 0x800C49B0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800C49B4: jr          $ra
    // 0x800C49B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C49B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void getControllerSettingsTitle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C49BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C49C0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800C49C4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C49C8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C49CC: addiu       $s0, $v0, 0xB40
    ctx->r16 = ADD32(ctx->r2, 0XB40);
    // 0x800C49D0: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800C49D4: lbu         $v1, 0x6($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X6);
    // 0x800C49D8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800C49DC: bne         $v1, $v0, L_800C49FC
    if (ctx->r3 != ctx->r2) {
        // 0x800C49E0: addu        $s1, $a0, $zero
        ctx->r17 = ADD32(ctx->r4, 0);
            goto L_800C49FC;
    }
    // 0x800C49E0: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800C49E4: jal         0x8005589C
    // 0x800C49E8: addiu       $a0, $zero, 0xB1
    ctx->r4 = ADD32(0, 0XB1);
    getGameOrFrontText(rdram, ctx);
        goto after_0;
    // 0x800C49E8: addiu       $a0, $zero, 0xB1
    ctx->r4 = ADD32(0, 0XB1);
    after_0:
    // 0x800C49EC: lbu         $a0, 0x5($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5);
    // 0x800C49F0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800C49F4: j           L_800C4A10
    // 0x800C49F8: addiu       $a0, $a0, 0x7F
    ctx->r4 = ADD32(ctx->r4, 0X7F);
        goto L_800C4A10;
    // 0x800C49F8: addiu       $a0, $a0, 0x7F
    ctx->r4 = ADD32(ctx->r4, 0X7F);
L_800C49FC:
    // 0x800C49FC: lbu         $a0, 0x5($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5);
    // 0x800C4A00: jal         0x8005589C
    // 0x800C4A04: addiu       $a0, $a0, 0x7F
    ctx->r4 = ADD32(ctx->r4, 0X7F);
    getGameOrFrontText(rdram, ctx);
        goto after_1;
    // 0x800C4A04: addiu       $a0, $a0, 0x7F
    ctx->r4 = ADD32(ctx->r4, 0X7F);
    after_1:
    // 0x800C4A08: addiu       $a0, $zero, 0xB1
    ctx->r4 = ADD32(0, 0XB1);
    // 0x800C4A0C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_800C4A10:
    // 0x800C4A10: jal         0x8005589C
    // 0x800C4A14: nop

    getGameOrFrontText(rdram, ctx);
        goto after_2;
    // 0x800C4A14: nop

    after_2:
    // 0x800C4A18: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800C4A1C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800C4A20: addiu       $a1, $a1, 0x74F0
    ctx->r5 = ADD32(ctx->r5, 0X74F0);
    // 0x800C4A24: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800C4A28: jal         0x80033CC4
    // 0x800C4A2C: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    sprintf_recomp(rdram, ctx);
        goto after_3;
    // 0x800C4A2C: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    after_3:
    // 0x800C4A30: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800C4A34: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C4A38: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C4A3C: jr          $ra
    // 0x800C4A40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C4A40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800C4A44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4A44: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800C4A48: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x800C4A4C: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
    // 0x800C4A50: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800C4A54: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800C4A58: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800C4A5C: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800C4A60: lbu         $s4, 0x53($sp)
    ctx->r20 = MEM_BU(ctx->r29, 0X53);
    // 0x800C4A64: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x800C4A68: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C4A6C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800C4A70: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C4A74: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x800C4A78: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x800C4A7C: beq         $a2, $zero, L_800C4AF0
    if (ctx->r6 == 0) {
        // 0x800C4A80: addu        $s3, $a3, $zero
        ctx->r19 = ADD32(ctx->r7, 0);
            goto L_800C4AF0;
    }
    // 0x800C4A80: addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // 0x800C4A84: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x800C4A88: lui         $s2, 0x8000
    ctx->r18 = S32(0X8000 << 16);
    // 0x800C4A8C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4A90: lwc1        $f0, 0x74F8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X74F8);
    // 0x800C4A94: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4A98: lwc1        $f22, 0x74FC($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X74FC);
    // 0x800C4A9C: mul.s       $f20, $f24, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
L_800C4AA0:
    // 0x800C4AA0: c.le.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl <= ctx->f20.fl;
    // 0x800C4AA4: nop

    // 0x800C4AA8: bc1t        L_800C4AC0
    if (c1cs) {
        // 0x800C4AAC: andi        $a1, $s0, 0xFF
        ctx->r5 = ctx->r16 & 0XFF;
            goto L_800C4AC0;
    }
    // 0x800C4AAC: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // 0x800C4AB0: trunc.w.s   $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x800C4AB4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800C4AB8: j           L_800C4AD4
    // 0x800C4ABC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
        goto L_800C4AD4;
    // 0x800C4ABC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_800C4AC0:
    // 0x800C4AC0: sub.s       $f0, $f20, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x800C4AC4: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C4AC8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800C4ACC: or          $a2, $a2, $s2
    ctx->r6 = ctx->r6 | ctx->r18;
    // 0x800C4AD0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_800C4AD4:
    // 0x800C4AD4: jal         0x80061C74
    // 0x800C4AD8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    func_80061C74(rdram, ctx);
        goto after_0;
    // 0x800C4AD8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_0:
    // 0x800C4ADC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C4AE0: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800C4AE4: sltiu       $v0, $v0, 0x5
    ctx->r2 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x800C4AE8: bne         $v0, $zero, L_800C4AA0
    if (ctx->r2 != 0) {
        // 0x800C4AEC: nop
    
            goto L_800C4AA0;
    }
    // 0x800C4AEC: nop

L_800C4AF0:
    // 0x800C4AF0: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x800C4AF4: beq         $v0, $zero, L_800C4B64
    if (ctx->r2 == 0) {
        // 0x800C4AF8: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_800C4B64;
    }
    // 0x800C4AF8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800C4AFC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800C4B00: lb          $a1, -0xE9E($v0)
    ctx->r5 = MEM_B(ctx->r2, -0XE9E);
    // 0x800C4B04: andi        $a3, $s3, 0xFF
    ctx->r7 = ctx->r19 & 0XFF;
    // 0x800C4B08: andi        $a0, $s4, 0xFF
    ctx->r4 = ctx->r20 & 0XFF;
    // 0x800C4B0C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800C4B10: addiu       $a2, $v0, -0xE80
    ctx->r6 = ADD32(ctx->r2, -0XE80);
    // 0x800C4B14: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
L_800C4B18:
    // 0x800C4B18: bne         $v0, $a1, L_800C4B30
    if (ctx->r2 != ctx->r5) {
        // 0x800C4B1C: nop
    
            goto L_800C4B30;
    }
    // 0x800C4B1C: nop

    // 0x800C4B20: beq         $a3, $zero, L_800C4B50
    if (ctx->r7 == 0) {
        // 0x800C4B24: andi        $v1, $s0, 0xFF
        ctx->r3 = ctx->r16 & 0XFF;
            goto L_800C4B50;
    }
    // 0x800C4B24: andi        $v1, $s0, 0xFF
    ctx->r3 = ctx->r16 & 0XFF;
    // 0x800C4B28: j           L_800C4B40
    // 0x800C4B2C: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
        goto L_800C4B40;
    // 0x800C4B2C: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
L_800C4B30:
    // 0x800C4B30: bnel        $a0, $zero, L_800C4B54
    if (ctx->r4 != 0) {
        // 0x800C4B34: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800C4B54;
    }
    goto skip_0;
    // 0x800C4B34: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x800C4B38: andi        $v1, $s0, 0xFF
    ctx->r3 = ctx->r16 & 0XFF;
    // 0x800C4B3C: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
L_800C4B40:
    // 0x800C4B40: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C4B44: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C4B48: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800C4B4C: swc1        $f24, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f24.u32l;
L_800C4B50:
    // 0x800C4B50: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800C4B54:
    // 0x800C4B54: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800C4B58: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x800C4B5C: bne         $v0, $zero, L_800C4B18
    if (ctx->r2 != 0) {
        // 0x800C4B60: andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
            goto L_800C4B18;
    }
    // 0x800C4B60: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
L_800C4B64:
    // 0x800C4B64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C4B68: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800C4B6C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4B70: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800C4B74: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C4B78: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C4B7C: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x800C4B80: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x800C4B84: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800C4B88: jr          $ra
    // 0x800C4B8C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800C4B8C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void loadControllerModel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4B90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C4B94: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800C4B98: addiu       $a0, $a0, 0x699C
    ctx->r4 = ADD32(ctx->r4, 0X699C);
    // 0x800C4B9C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C4BA0: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800C4BA4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800C4BA8: jal         0x8005645C
    // 0x800C4BAC: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    load_hmt_and_hob(rdram, ctx);
        goto after_0;
    // 0x800C4BAC: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_0:
    // 0x800C4BB0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800C4BB4: jal         0x80056EB0
    // 0x800C4BB8: addiu       $a0, $a0, 0x69BC
    ctx->r4 = ADD32(ctx->r4, 0X69BC);
    func_80056EB0(rdram, ctx);
        goto after_1;
    // 0x800C4BB8: addiu       $a0, $a0, 0x69BC
    ctx->r4 = ADD32(ctx->r4, 0X69BC);
    after_1:
    // 0x800C4BBC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800C4BC0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800C4BC4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C4BC8: lui         $a2, 0x106
    ctx->r6 = S32(0X106 << 16);
    // 0x800C4BCC: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x800C4BD0: jal         0x8005955C
    // 0x800C4BD4: sw          $v0, -0xF14($v1)
    MEM_W(-0XF14, ctx->r3) = ctx->r2;
    func_8005955C(rdram, ctx);
        goto after_2;
    // 0x800C4BD4: sw          $v0, -0xF14($v1)
    MEM_W(-0XF14, ctx->r3) = ctx->r2;
    after_2:
    // 0x800C4BD8: jal         0x800C4BF8
    // 0x800C4BDC: nop

    loadHelmetModel(rdram, ctx);
        goto after_3;
    // 0x800C4BDC: nop

    after_3:
    // 0x800C4BE0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C4BE4: jal         0x800B95D4
    // 0x800C4BE8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_800B95D4(rdram, ctx);
        goto after_4;
    // 0x800C4BE8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_4:
    // 0x800C4BEC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800C4BF0: jr          $ra
    // 0x800C4BF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C4BF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void loadHelmetModel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4BF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C4BFC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800C4C00: addiu       $a0, $a0, 0x69F4
    ctx->r4 = ADD32(ctx->r4, 0X69F4);
    // 0x800C4C04: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C4C08: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800C4C0C: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x800C4C10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C4C14: jal         0x8005645C
    // 0x800C4C18: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    load_hmt_and_hob(rdram, ctx);
        goto after_0;
    // 0x800C4C18: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x800C4C1C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800C4C20: jal         0x80056EB0
    // 0x800C4C24: addiu       $a0, $a0, 0x6A0C
    ctx->r4 = ADD32(ctx->r4, 0X6A0C);
    func_80056EB0(rdram, ctx);
        goto after_1;
    // 0x800C4C24: addiu       $a0, $a0, 0x6A0C
    ctx->r4 = ADD32(ctx->r4, 0X6A0C);
    after_1:
    // 0x800C4C28: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800C4C2C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C4C30: lui         $a2, 0x6
    ctx->r6 = S32(0X6 << 16);
    // 0x800C4C34: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x800C4C38: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800C4C3C: jal         0x8005955C
    // 0x800C4C40: sw          $a0, -0xF00($s0)
    MEM_W(-0XF00, ctx->r16) = ctx->r4;
    func_8005955C(rdram, ctx);
        goto after_2;
    // 0x800C4C40: sw          $a0, -0xF00($s0)
    MEM_W(-0XF00, ctx->r16) = ctx->r4;
    after_2:
    // 0x800C4C44: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800C4C48: addiu       $a1, $a1, 0x6A14
    ctx->r5 = ADD32(ctx->r5, 0X6A14);
    // 0x800C4C4C: lw          $a0, -0xF00($s0)
    ctx->r4 = MEM_W(ctx->r16, -0XF00);
    // 0x800C4C50: jal         0x80059434
    // 0x800C4C54: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80059434(rdram, ctx);
        goto after_3;
    // 0x800C4C54: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_3:
    // 0x800C4C58: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x800C4C5C: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x800C4C60: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x800C4C64: lui         $v1, 0x80
    ctx->r3 = S32(0X80 << 16);
    // 0x800C4C68: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800C4C6C: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // 0x800C4C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C4C74: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C4C78: jr          $ra
    // 0x800C4C7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C4C7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800C4C80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4C80: sb          $zero, 0x95($a0)
    MEM_B(0X95, ctx->r4) = 0;
    // 0x800C4C84: jr          $ra
    // 0x800C4C88: sh          $zero, 0x98($a0)
    MEM_H(0X98, ctx->r4) = 0;
    return;
    // 0x800C4C88: sh          $zero, 0x98($a0)
    MEM_H(0X98, ctx->r4) = 0;
;}
RECOMP_FUNC void func_800C4C8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4C8C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800C4C90: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C4C94: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x800C4C98: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800C4C9C: addu        $s7, $a1, $zero
    ctx->r23 = ADD32(ctx->r5, 0);
    // 0x800C4CA0: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x800C4CA4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800C4CA8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800C4CAC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C4CB0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C4CB4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C4CB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C4CBC: lbu         $v1, 0x95($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X95);
    // 0x800C4CC0: beq         $v1, $zero, L_800C4D8C
    if (ctx->r3 == 0) {
        // 0x800C4CC4: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_800C4D8C;
    }
    // 0x800C4CC4: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800C4CC8: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800C4CCC: andi        $s6, $a2, 0xFF
    ctx->r22 = ctx->r6 & 0XFF;
    // 0x800C4CD0: addu        $s3, $s2, $zero
    ctx->r19 = ADD32(ctx->r18, 0);
    // 0x800C4CD4: addu        $s0, $s4, $zero
    ctx->r16 = ADD32(ctx->r20, 0);
L_800C4CD8:
    // 0x800C4CD8: sllv        $v0, $s5, $s2
    ctx->r2 = S32(ctx->r21 << (ctx->r18 & 31));
    // 0x800C4CDC: and         $v0, $s7, $v0
    ctx->r2 = ctx->r23 & ctx->r2;
    // 0x800C4CE0: beq         $v0, $zero, L_800C4D74
    if (ctx->r2 == 0) {
        // 0x800C4CE4: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_800C4D74;
    }
    // 0x800C4CE4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800C4CE8: andi        $s1, $s2, 0xFFFF
    ctx->r17 = ctx->r18 & 0XFFFF;
    // 0x800C4CEC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x800C4CF0: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x800C4CF4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C4CF8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800C4CFC: subu        $v0, $s3, $v0
    ctx->r2 = SUB32(ctx->r19, ctx->r2);
    // 0x800C4D00: lhu         $a1, 0x96($s4)
    ctx->r5 = MEM_HU(ctx->r20, 0X96);
    // 0x800C4D04: lhu         $v1, 0x32($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X32);
    // 0x800C4D08: lhu         $a3, 0x30($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X30);
    // 0x800C4D0C: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800C4D10: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800C4D14: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x800C4D18: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800C4D1C: addiu       $a3, $a3, -0x100
    ctx->r7 = ADD32(ctx->r7, -0X100);
    // 0x800C4D20: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x800C4D24: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x800C4D28: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x800C4D2C: jal         0x80063CFC
    // 0x800C4D30: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    func_80063CFC(rdram, ctx);
        goto after_0;
    // 0x800C4D30: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    after_0:
    // 0x800C4D34: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800C4D38: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    // 0x800C4D3C: jal         0x80061F34
    // 0x800C4D40: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80061F34(rdram, ctx);
        goto after_1;
    // 0x800C4D40: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_1:
    // 0x800C4D44: bne         $s6, $s5, L_800C4D5C
    if (ctx->r22 != ctx->r21) {
        // 0x800C4D48: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_800C4D5C;
    }
    // 0x800C4D48: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800C4D4C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800C4D50: jal         0x80061C74
    // 0x800C4D54: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80061C74(rdram, ctx);
        goto after_2;
    // 0x800C4D54: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_2:
    // 0x800C4D58: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_800C4D5C:
    // 0x800C4D5C: jal         0x80063C3C
    // 0x800C4D60: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80063C3C(rdram, ctx);
        goto after_3;
    // 0x800C4D60: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_3:
    // 0x800C4D64: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800C4D68: swc1        $f0, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->f0.u32l;
    // 0x800C4D6C: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800C4D70: swc1        $f0, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f0.u32l;
L_800C4D74:
    // 0x800C4D74: addiu       $s3, $s3, 0x24
    ctx->r19 = ADD32(ctx->r19, 0X24);
    // 0x800C4D78: lbu         $v1, 0x95($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X95);
    // 0x800C4D7C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800C4D80: sltu        $v0, $s2, $v1
    ctx->r2 = ctx->r18 < ctx->r3 ? 1 : 0;
    // 0x800C4D84: bne         $v0, $zero, L_800C4CD8
    if (ctx->r2 != 0) {
        // 0x800C4D88: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800C4CD8;
    }
    // 0x800C4D88: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800C4D8C:
    // 0x800C4D8C: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x800C4D90: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800C4D94: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800C4D98: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800C4D9C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800C4DA0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C4DA4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C4DA8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4DAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C4DB0: jr          $ra
    // 0x800C4DB4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800C4DB4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800C4D8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4D8C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800C4D90: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C4D94: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800C4D98: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800C4D9C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800C4DA0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800C4DA4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C4DA8: sdc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X50, ctx->r29);
    // 0x800C4DAC: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x800C4DB0: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x800C4DB4: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x800C4DB8: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x800C4DBC: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x800C4DC0: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x800C4DC4: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800C4DC8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4DCC: lwc1        $f0, 0x6774($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6774);
    // 0x800C4DD0: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C4DD4: trunc.w.s   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800C4DD8: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800C4DDC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C4DE0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C4DE4: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800C4DE8: add.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800C4DEC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4DF0: lwc1        $f0, 0x6778($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6778);
    // 0x800C4DF4: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C4DF8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4DFC: lwc1        $f2, 0x677C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X677C);
    // 0x800C4E00: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C4E04: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4E08: lwc1        $f2, 0x6780($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6780);
    // 0x800C4E0C: mtc1        $a2, $f30
    ctx->f30.u32l = ctx->r6;
    // 0x800C4E10: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800C4E14: nop

    // 0x800C4E18: bc1t        L_800C4E30
    if (c1cs) {
        // 0x800C4E1C: addiu       $s0, $a0, 0xB18
        ctx->r16 = ADD32(ctx->r4, 0XB18);
            goto L_800C4E30;
    }
    // 0x800C4E1C: addiu       $s0, $a0, 0xB18
    ctx->r16 = ADD32(ctx->r4, 0XB18);
    // 0x800C4E20: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C4E24: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800C4E28: j           L_800C4E44
    // 0x800C4E2C: nop

        goto L_800C4E44;
    // 0x800C4E2C: nop

L_800C4E30:
    // 0x800C4E30: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800C4E34: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800C4E38: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C4E3C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800C4E40: or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
L_800C4E44:
    // 0x800C4E44: lh          $v1, 0x85C($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X85C);
    // 0x800C4E48: bgez        $v1, L_800C4E54
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800C4E4C: addu        $a3, $v1, $zero
        ctx->r7 = ADD32(ctx->r3, 0);
            goto L_800C4E54;
    }
    // 0x800C4E4C: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    // 0x800C4E50: addiu       $a3, $v1, 0x1F
    ctx->r7 = ADD32(ctx->r3, 0X1F);
L_800C4E54:
    // 0x800C4E54: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800C4E58: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4E5C: lwc1        $f0, 0x6784($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6784);
    // 0x800C4E60: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C4E64: trunc.w.s   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800C4E68: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800C4E6C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C4E70: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C4E74: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800C4E78: sra         $v0, $a3, 5
    ctx->r2 = S32(SIGNED(ctx->r7) >> 5);
    // 0x800C4E7C: add.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800C4E80: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4E84: lwc1        $f0, 0x6788($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6788);
    // 0x800C4E88: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800C4E8C: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C4E90: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x800C4E94: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800C4E98: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4E9C: lwc1        $f2, 0x678C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X678C);
    // 0x800C4EA0: sra         $v0, $v0, 9
    ctx->r2 = S32(SIGNED(ctx->r2) >> 9);
    // 0x800C4EA4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C4EA8: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x800C4EAC: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x800C4EB0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4EB4: lwc1        $f2, 0x6790($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6790);
    // 0x800C4EB8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800C4EBC: nop

    // 0x800C4EC0: bc1t        L_800C4ED8
    if (c1cs) {
        // 0x800C4EC4: ori         $s4, $v0, 0x1000
        ctx->r20 = ctx->r2 | 0X1000;
            goto L_800C4ED8;
    }
    // 0x800C4EC4: ori         $s4, $v0, 0x1000
    ctx->r20 = ctx->r2 | 0X1000;
    // 0x800C4EC8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C4ECC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800C4ED0: j           L_800C4EEC
    // 0x800C4ED4: nop

        goto L_800C4EEC;
    // 0x800C4ED4: nop

L_800C4ED8:
    // 0x800C4ED8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800C4EDC: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800C4EE0: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C4EE4: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800C4EE8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_800C4EEC:
    // 0x800C4EEC: lh          $a0, 0x85E($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X85E);
    // 0x800C4EF0: bgez        $a0, L_800C4EFC
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800C4EF4: addu        $v0, $a0, $zero
        ctx->r2 = ADD32(ctx->r4, 0);
            goto L_800C4EFC;
    }
    // 0x800C4EF4: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x800C4EF8: addiu       $v0, $a0, 0x1F
    ctx->r2 = ADD32(ctx->r4, 0X1F);
L_800C4EFC:
    // 0x800C4EFC: sra         $v0, $v0, 5
    ctx->r2 = S32(SIGNED(ctx->r2) >> 5);
    // 0x800C4F00: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800C4F04: subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // 0x800C4F08: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800C4F0C: sra         $v0, $v0, 9
    ctx->r2 = S32(SIGNED(ctx->r2) >> 9);
    // 0x800C4F10: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800C4F14: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x800C4F18: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4F1C: lwc1        $f20, 0x6794($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X6794);
    // 0x800C4F20: ori         $s2, $v0, 0x1000
    ctx->r18 = ctx->r2 | 0X1000;
    // 0x800C4F24: jal         0x80033960
    // 0x800C4F28: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x800C4F28: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x800C4F2C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x800C4F30: jal         0x8002B190
    // 0x800C4F34: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x800C4F34: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x800C4F38: mov.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
    // 0x800C4F3C: mul.s       $f0, $f4, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f30.fl);
    // 0x800C4F40: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800C4F44: mul.s       $f2, $f22, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f6.fl);
    // 0x800C4F48: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C4F4C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4F50: lwc1        $f0, 0x6798($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6798);
    // 0x800C4F54: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C4F58: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4F5C: lwc1        $f0, 0x679C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X679C);
    // 0x800C4F60: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C4F64: mtc1        $s4, $f0
    ctx->f0.u32l = ctx->r20;
    // 0x800C4F68: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C4F6C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800C4F70: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4F74: lwc1        $f2, 0x67A0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X67A0);
    // 0x800C4F78: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800C4F7C: nop

    // 0x800C4F80: bc1tl       L_800C4F98
    if (c1cs) {
        // 0x800C4F84: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800C4F98;
    }
    goto skip_0;
    // 0x800C4F84: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_0:
    // 0x800C4F88: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C4F8C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800C4F90: j           L_800C4FA8
    // 0x800C4F94: nop

        goto L_800C4FA8;
    // 0x800C4F94: nop

L_800C4F98:
    // 0x800C4F98: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800C4F9C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C4FA0: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800C4FA4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_800C4FA8:
    // 0x800C4FA8: mul.s       $f2, $f22, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f30.fl);
    // 0x800C4FAC: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800C4FB0: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C4FB4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800C4FB8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4FBC: lwc1        $f2, 0x67A4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X67A4);
    // 0x800C4FC0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800C4FC4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C4FC8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4FCC: lwc1        $f2, 0x67A8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X67A8);
    // 0x800C4FD0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C4FD4: mtc1        $s2, $f2
    ctx->f2.u32l = ctx->r18;
    // 0x800C4FD8: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800C4FDC: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800C4FE0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4FE4: lwc1        $f2, 0x67AC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X67AC);
    // 0x800C4FE8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800C4FEC: nop

    // 0x800C4FF0: bc1t        L_800C5008
    if (c1cs) {
        // 0x800C4FF4: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_800C5008;
    }
    // 0x800C4FF4: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x800C4FF8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C4FFC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800C5000: j           L_800C5020
    // 0x800C5004: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
        goto L_800C5020;
    // 0x800C5004: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_800C5008:
    // 0x800C5008: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800C500C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800C5010: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5014: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800C5018: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800C501C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_800C5020:
    // 0x800C5020: lui         $s3, 0x8000
    ctx->r19 = S32(0X8000 << 16);
    // 0x800C5024: addiu       $s0, $s0, 0x23
    ctx->r16 = ADD32(ctx->r16, 0X23);
    // 0x800C5028: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C502C: lwc1        $f28, 0x67B0($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X67B0);
    // 0x800C5030: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5034: lwc1        $f26, 0x67B4($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X67B4);
    // 0x800C5038: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C503C: lwc1        $f24, 0x67B8($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X67B8);
L_800C5040:
    // 0x800C5040: addiu       $v0, $s1, 0x1
    ctx->r2 = ADD32(ctx->r17, 0X1);
    // 0x800C5044: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5048: lwc1        $f0, 0x67BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X67BC);
    // 0x800C504C: mtc1        $v0, $f20
    ctx->f20.u32l = ctx->r2;
    // 0x800C5050: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x800C5054: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800C5058: add.s       $f20, $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f20.fl;
    // 0x800C505C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5060: lwc1        $f0, 0x67C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X67C0);
    // 0x800C5064: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800C5068: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C506C: lwc1        $f0, 0x67C4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X67C4);
    // 0x800C5070: sh          $s4, -0xF($s0)
    MEM_H(-0XF, ctx->r16) = ctx->r20;
    // 0x800C5074: sh          $s2, -0xD($s0)
    MEM_H(-0XD, ctx->r16) = ctx->r18;
    // 0x800C5078: sub.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x800C507C: sh          $a0, -0xB($s0)
    MEM_H(-0XB, ctx->r16) = ctx->r4;
    // 0x800C5080: sh          $v1, -0x9($s0)
    MEM_H(-0X9, ctx->r16) = ctx->r3;
    // 0x800C5084: jal         0x80033960
    // 0x800C5088: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x800C5088: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_2:
    // 0x800C508C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x800C5090: jal         0x8002B190
    // 0x800C5094: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x800C5094: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_3:
    // 0x800C5098: mov.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
    // 0x800C509C: mul.s       $f0, $f4, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f30.fl);
    // 0x800C50A0: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800C50A4: mul.s       $f2, $f22, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f6.fl);
    // 0x800C50A8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C50AC: mul.s       $f2, $f2, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f28.fl);
    // 0x800C50B0: nop

    // 0x800C50B4: mul.s       $f2, $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f26.fl);
    // 0x800C50B8: mtc1        $s4, $f0
    ctx->f0.u32l = ctx->r20;
    // 0x800C50BC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C50C0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800C50C4: c.le.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl <= ctx->f0.fl;
    // 0x800C50C8: nop

    // 0x800C50CC: bc1tl       L_800C50E4
    if (c1cs) {
        // 0x800C50D0: sub.s       $f0, $f0, $f24
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
            goto L_800C50E4;
    }
    goto skip_1;
    // 0x800C50D0: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    skip_1:
    // 0x800C50D4: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C50D8: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800C50DC: j           L_800C50F0
    // 0x800C50E0: nop

        goto L_800C50F0;
    // 0x800C50E0: nop

L_800C50E4:
    // 0x800C50E4: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C50E8: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800C50EC: or          $v0, $v0, $s3
    ctx->r2 = ctx->r2 | ctx->r19;
L_800C50F0:
    // 0x800C50F0: mul.s       $f2, $f22, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f30.fl);
    // 0x800C50F4: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800C50F8: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C50FC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800C5100: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800C5104: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x800C5108: nop

    // 0x800C510C: mul.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x800C5110: mtc1        $s2, $f2
    ctx->f2.u32l = ctx->r18;
    // 0x800C5114: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800C5118: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800C511C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800C5120: c.le.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl <= ctx->f0.fl;
    // 0x800C5124: nop

    // 0x800C5128: bc1t        L_800C5140
    if (c1cs) {
        // 0x800C512C: sh          $v0, -0x7($s0)
        MEM_H(-0X7, ctx->r16) = ctx->r2;
            goto L_800C5140;
    }
    // 0x800C512C: sh          $v0, -0x7($s0)
    MEM_H(-0X7, ctx->r16) = ctx->r2;
    // 0x800C5130: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5134: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800C5138: j           L_800C5150
    // 0x800C513C: nop

        goto L_800C5150;
    // 0x800C513C: nop

L_800C5140:
    // 0x800C5140: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x800C5144: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5148: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800C514C: or          $v0, $v0, $s3
    ctx->r2 = ctx->r2 | ctx->r19;
L_800C5150:
    // 0x800C5150: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5154: lwc1        $f0, 0x67C8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X67C8);
    // 0x800C5158: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800C515C: mul.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800C5160: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800C5164: c.le.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl <= ctx->f0.fl;
    // 0x800C5168: nop

    // 0x800C516C: bc1t        L_800C5184
    if (c1cs) {
        // 0x800C5170: sh          $v0, -0x5($s0)
        MEM_H(-0X5, ctx->r16) = ctx->r2;
            goto L_800C5184;
    }
    // 0x800C5170: sh          $v0, -0x5($s0)
    MEM_H(-0X5, ctx->r16) = ctx->r2;
    // 0x800C5174: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5178: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800C517C: j           L_800C5198
    // 0x800C5180: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
        goto L_800C5198;
    // 0x800C5180: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
L_800C5184:
    // 0x800C5184: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x800C5188: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C518C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800C5190: or          $v0, $v0, $s3
    ctx->r2 = ctx->r2 | ctx->r19;
    // 0x800C5194: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
L_800C5198:
    // 0x800C5198: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C519C: slti        $v0, $s1, 0x8
    ctx->r2 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
    // 0x800C51A0: bne         $v0, $zero, L_800C5040
    if (ctx->r2 != 0) {
        // 0x800C51A4: addiu       $s0, $s0, 0x24
        ctx->r16 = ADD32(ctx->r16, 0X24);
            goto L_800C5040;
    }
    // 0x800C51A4: addiu       $s0, $s0, 0x24
    ctx->r16 = ADD32(ctx->r16, 0X24);
    // 0x800C51A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C51AC: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800C51B0: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800C51B4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800C51B8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C51BC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C51C0: ldc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X50);
    // 0x800C51C4: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x800C51C8: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x800C51CC: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x800C51D0: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x800C51D4: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800C51D8: jr          $ra
    // 0x800C51DC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800C51DC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800C4DB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4DB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C4DBC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x800C4DC0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C4DC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C4DC8: jal         0x80001ACC
    // 0x800C4DCC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x800C4DCC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x800C4DD0: jal         0x800BC6F0
    // 0x800C4DD4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    func_800BC6F0(rdram, ctx);
        goto after_1;
    // 0x800C4DD4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_1:
    // 0x800C4DD8: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x800C4DDC: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x800C4DE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C4DE4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C4DE8: jr          $ra
    // 0x800C4DEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C4DEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800C4DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4DF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C4DF4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C4DF8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800C4DFC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800C4E00: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x800C4E04: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800C4E08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C4E0C: jal         0x80003430
    // 0x800C4E10: addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    rand_recomp(rdram, ctx);
        goto after_0;
    // 0x800C4E10: addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    after_0:
    // 0x800C4E14: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800C4E18: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // 0x800C4E1C: ori         $v0, $zero, 0xCDCD
    ctx->r2 = 0 | 0XCDCD;
    // 0x800C4E20: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C4E24: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800C4E28: sw          $s1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r17;
    // 0x800C4E2C: sw          $s2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r18;
    // 0x800C4E30: jal         0x800BC834
    // 0x800C4E34: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    func_800BC834(rdram, ctx);
        goto after_1;
    // 0x800C4E34: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    after_1:
    // 0x800C4E38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4E3C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800C4E40: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C4E44: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C4E48: jr          $ra
    // 0x800C4E4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C4E4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800C4E50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4E50: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4E54: lwc1        $f0, 0x7500($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7500);
    // 0x800C4E58: sw          $zero, 0x14EC($a0)
    MEM_W(0X14EC, ctx->r4) = 0;
    // 0x800C4E5C: sw          $a1, 0x14F8($a0)
    MEM_W(0X14F8, ctx->r4) = ctx->r5;
    // 0x800C4E60: sw          $a2, 0x14FC($a0)
    MEM_W(0X14FC, ctx->r4) = ctx->r6;
    // 0x800C4E64: jr          $ra
    // 0x800C4E68: swc1        $f0, 0x14F0($a0)
    MEM_W(0X14F0, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x800C4E68: swc1        $f0, 0x14F0($a0)
    MEM_W(0X14F0, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_800C4E6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4E6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C4E70: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C4E74: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // 0x800C4E78: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800C4E7C: jal         0x80082270
    // 0x800C4E80: sb          $zero, 0x10($sp)
    MEM_B(0X10, ctx->r29) = 0;
    func_80082270(rdram, ctx);
        goto after_0;
    // 0x800C4E80: sb          $zero, 0x10($sp)
    MEM_B(0X10, ctx->r29) = 0;
    after_0:
    // 0x800C4E84: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x800C4E88: beq         $v1, $zero, L_800C4EA0
    if (ctx->r3 == 0) {
        // 0x800C4E8C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800C4EA0;
    }
    // 0x800C4E8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C4E90: beq         $v1, $v0, L_800C4EAC
    if (ctx->r3 == ctx->r2) {
        // 0x800C4E94: addiu       $a0, $zero, 0x18
        ctx->r4 = ADD32(0, 0X18);
            goto L_800C4EAC;
    }
    // 0x800C4E94: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x800C4E98: j           L_800C4EB8
    // 0x800C4E9C: nop

        goto L_800C4EB8;
    // 0x800C4E9C: nop

L_800C4EA0:
    // 0x800C4EA0: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    // 0x800C4EA4: j           L_800C4EB0
    // 0x800C4EA8: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
        goto L_800C4EB0;
    // 0x800C4EA8: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
L_800C4EAC:
    // 0x800C4EAC: addiu       $a1, $zero, 0x5F
    ctx->r5 = ADD32(0, 0X5F);
L_800C4EB0:
    // 0x800C4EB0: jal         0x80087EE8
    // 0x800C4EB4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80087EE8(rdram, ctx);
        goto after_1;
    // 0x800C4EB4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_1:
L_800C4EB8:
    // 0x800C4EB8: lbu         $v0, 0x10($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X10);
    // 0x800C4EBC: beq         $v0, $zero, L_800C4ECC
    if (ctx->r2 == 0) {
        // 0x800C4EC0: nop
    
            goto L_800C4ECC;
    }
    // 0x800C4EC0: nop

    // 0x800C4EC4: jal         0x8006E1BC
    // 0x800C4EC8: nop

    func_8006E1BC(rdram, ctx);
        goto after_2;
    // 0x800C4EC8: nop

    after_2:
L_800C4ECC:
    // 0x800C4ECC: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800C4ED0: jr          $ra
    // 0x800C4ED4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C4ED4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800C4ED8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4ED8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800C4EDC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800C4EE0: addiu       $v1, $v1, -0x3764
    ctx->r3 = ADD32(ctx->r3, -0X3764);
    // 0x800C4EE4: lb          $a1, -0xEB0($v0)
    ctx->r5 = MEM_B(ctx->r2, -0XEB0);
    // 0x800C4EE8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800C4EEC: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x800C4EF0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800C4EF4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C4EF8: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // 0x800C4EFC: lhu         $v0, 0x16($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X16);
    // 0x800C4F00: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800C4F04: slt         $a0, $a0, $v0
    ctx->r4 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C4F08: beq         $a0, $zero, L_800C4F14
    if (ctx->r4 == 0) {
        // 0x800C4F0C: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_800C4F14;
    }
    // 0x800C4F0C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C4F10: lhu         $a2, 0x14($v1)
    ctx->r6 = MEM_HU(ctx->r3, 0X14);
L_800C4F14:
    // 0x800C4F14: sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6 << 16);
    // 0x800C4F18: jr          $ra
    // 0x800C4F1C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    return;
    // 0x800C4F1C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
;}
RECOMP_FUNC void func_800C4F20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4F20: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800C4F24: sb          $zero, -0x10C0($v0)
    MEM_B(-0X10C0, ctx->r2) = 0;
    // 0x800C4F28: addiu       $v0, $v0, -0x10C0
    ctx->r2 = ADD32(ctx->r2, -0X10C0);
    // 0x800C4F2C: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x800C4F30: jr          $ra
    // 0x800C4F34: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    return;
    // 0x800C4F34: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
;}
RECOMP_FUNC void func_800C4F38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4F38: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C4F3C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800C4F40: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800C4F44: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C4F48: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x800C4F4C: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x800C4F50: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x800C4F54: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C4F58: jal         0x800B32F4
    // 0x800C4F5C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    func_800B32F4(rdram, ctx);
        goto after_0;
    // 0x800C4F5C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    after_0:
    // 0x800C4F60: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800C4F64: addiu       $a1, $zero, -0x40
    ctx->r5 = ADD32(0, -0X40);
    // 0x800C4F68: jal         0x800C4FF4
    // 0x800C4F6C: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    func_800C4FF4(rdram, ctx);
        goto after_1;
    // 0x800C4F6C: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_1:
    // 0x800C4F70: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800C4F74: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800C4F78: addiu       $a2, $s0, -0x1
    ctx->r6 = ADD32(ctx->r16, -0X1);
    // 0x800C4F7C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x800C4F80: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800C4F84: jal         0x800642A0
    // 0x800C4F88: sw          $a1, -0x598($s1)
    MEM_W(-0X598, ctx->r17) = ctx->r5;
    func_800642A0(rdram, ctx);
        goto after_2;
    // 0x800C4F88: sw          $a1, -0x598($s1)
    MEM_W(-0X598, ctx->r17) = ctx->r5;
    after_2:
    // 0x800C4F8C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800C4F90: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x800C4F94: lw          $a1, -0x598($s1)
    ctx->r5 = MEM_W(ctx->r17, -0X598);
    // 0x800C4F98: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800C4F9C: jal         0x800642A0
    // 0x800C4FA0: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    func_800642A0(rdram, ctx);
        goto after_3;
    // 0x800C4FA0: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    after_3:
    // 0x800C4FA4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800C4FA8: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x800C4FAC: lw          $a2, -0x598($s1)
    ctx->r6 = MEM_W(ctx->r17, -0X598);
    // 0x800C4FB0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C4FB4: lwc1        $f0, 0x7504($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7504);
    // 0x800C4FB8: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x800C4FBC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800C4FC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C4FC4: addiu       $a1, $a2, 0x60
    ctx->r5 = ADD32(ctx->r6, 0X60);
    // 0x800C4FC8: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    // 0x800C4FCC: jal         0x800B44EC
    // 0x800C4FD0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_800B44EC(rdram, ctx);
        goto after_4;
    // 0x800C4FD0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x800C4FD4: lw          $v0, -0x598($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X598);
    // 0x800C4FD8: sb          $zero, 0x74($v0)
    MEM_B(0X74, ctx->r2) = 0;
    // 0x800C4FDC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C4FE0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800C4FE4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800C4FE8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C4FEC: jr          $ra
    // 0x800C4FF0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C4FF0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800C4FF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4FF4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C4FF8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800C4FFC: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800C5000: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800C5004: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800C5008: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800C500C: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x800C5010: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x800C5014: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C5018: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800C501C: jal         0x80001ACC
    // 0x800C5020: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x800C5020: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x800C5024: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800C5028: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C502C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C5030: jal         0x800078E0
    // 0x800C5034: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x800C5034: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    after_1:
    // 0x800C5038: jal         0x800B3D08
    // 0x800C503C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_800B3D08(rdram, ctx);
        goto after_2;
    // 0x800C503C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_2:
    // 0x800C5040: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    // 0x800C5044: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x800C5048: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800C504C: mtc1        $s1, $f0
    ctx->f0.u32l = ctx->r17;
    // 0x800C5050: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C5054: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x800C5058: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C505C: lwc1        $f2, 0x7508($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7508);
    // 0x800C5060: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800C5064: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x800C5068: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x800C506C: mtc1        $s2, $f0
    ctx->f0.u32l = ctx->r18;
    // 0x800C5070: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C5074: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x800C5078: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x800C507C: swc1        $f2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f2.u32l;
    // 0x800C5080: swc1        $f2, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f2.u32l;
    // 0x800C5084: swc1        $f2, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f2.u32l;
    // 0x800C5088: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
    // 0x800C508C: swc1        $f2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f2.u32l;
    // 0x800C5090: ori         $v1, $v1, 0x3
    ctx->r3 = ctx->r3 | 0X3;
    // 0x800C5094: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
    // 0x800C5098: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x800C509C: ori         $v1, $v1, 0x3
    ctx->r3 = ctx->r3 | 0X3;
    // 0x800C50A0: sw          $v1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r3;
    // 0x800C50A4: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800C50A8: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x800C50AC: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
    // 0x800C50B0: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x800C50B4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800C50B8: sh          $v1, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r3;
    // 0x800C50BC: sh          $v1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r3;
    // 0x800C50C0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C50C4: sh          $v1, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r3;
    // 0x800C50C8: sh          $v1, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r3;
    // 0x800C50CC: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x800C50D0: sb          $v1, 0x2C($v0)
    MEM_B(0X2C, ctx->r2) = ctx->r3;
    // 0x800C50D4: addiu       $v1, $zero, 0x8F
    ctx->r3 = ADD32(0, 0X8F);
    // 0x800C50D8: sb          $v1, 0x2D($v0)
    MEM_B(0X2D, ctx->r2) = ctx->r3;
    // 0x800C50DC: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // 0x800C50E0: sb          $v1, 0x2E($v0)
    MEM_B(0X2E, ctx->r2) = ctx->r3;
    // 0x800C50E4: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x800C50E8: sb          $v1, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = ctx->r3;
    // 0x800C50EC: addiu       $v1, $zero, 0x28
    ctx->r3 = ADD32(0, 0X28);
    // 0x800C50F0: sb          $v1, 0x2D($a0)
    MEM_B(0X2D, ctx->r4) = ctx->r3;
    // 0x800C50F4: addiu       $v1, $zero, 0x48
    ctx->r3 = ADD32(0, 0X48);
    // 0x800C50F8: sb          $v1, 0x2E($a0)
    MEM_B(0X2E, ctx->r4) = ctx->r3;
    // 0x800C50FC: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800C5100: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800C5104: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800C5108: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C510C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C5110: jr          $ra
    // 0x800C5114: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C5114: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800C5118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5118: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C511C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800C5120: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800C5124: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800C5128: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x800C512C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800C5130: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x800C5134: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x800C5138: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C513C: lwc1        $f2, 0x750C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X750C);
    // 0x800C5140: lw          $a1, -0x598($v0)
    ctx->r5 = MEM_W(ctx->r2, -0X598);
    // 0x800C5144: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5148: lwc1        $f6, 0x7510($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7510);
    // 0x800C514C: mtc1        $a3, $f0
    ctx->f0.u32l = ctx->r7;
    // 0x800C5150: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C5154: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800C5158: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C515C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800C5160: mul.s       $f4, $f22, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x800C5164: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5168: lwc1        $f2, 0x7514($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7514);
    // 0x800C516C: addiu       $s0, $a1, 0x30
    ctx->r16 = ADD32(ctx->r5, 0X30);
    // 0x800C5170: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C5174: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800C5178: nop

    // 0x800C517C: bc1t        L_800C5194
    if (c1cs) {
        // 0x800C5180: swc1        $f0, 0x24($a1)
        MEM_W(0X24, ctx->r5) = ctx->f0.u32l;
            goto L_800C5194;
    }
    // 0x800C5180: swc1        $f0, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f0.u32l;
    // 0x800C5184: trunc.w.s   $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800C5188: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800C518C: j           L_800C51A8
    // 0x800C5190: nop

        goto L_800C51A8;
    // 0x800C5190: nop

L_800C5194:
    // 0x800C5194: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800C5198: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800C519C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C51A0: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800C51A4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_800C51A8:
    // 0x800C51A8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800C51AC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C51B0: sb          $v1, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r3;
    // 0x800C51B4: sb          $v1, 0x2F($a1)
    MEM_B(0X2F, ctx->r5) = ctx->r3;
    // 0x800C51B8: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    // 0x800C51BC: c.eq.s      $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f22.fl == ctx->f2.fl;
    // 0x800C51C0: nop

    // 0x800C51C4: bc1t        L_800C51E0
    if (c1cs) {
        // 0x800C51C8: swc1        $f8, 0x1C($a1)
        MEM_W(0X1C, ctx->r5) = ctx->f8.u32l;
            goto L_800C51E0;
    }
    // 0x800C51C8: swc1        $f8, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f8.u32l;
    // 0x800C51CC: lwc1        $f0, 0x24($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800C51D0: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800C51D4: nop

    // 0x800C51D8: bc1fl       L_800C51E0
    if (!c1cs) {
        // 0x800C51DC: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_800C51E0;
    }
    goto skip_0;
    // 0x800C51DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    skip_0:
L_800C51E0:
    // 0x800C51E0: jal         0x800646AC
    // 0x800C51E4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800646AC(rdram, ctx);
        goto after_0;
    // 0x800C51E4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // 0x800C51E8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800C51EC: c.eq.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl == ctx->f20.fl;
    // 0x800C51F0: nop

    // 0x800C51F4: bc1f        L_800C5200
    if (!c1cs) {
        // 0x800C51F8: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_800C5200;
    }
    // 0x800C51F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800C51FC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_800C5200:
    // 0x800C5200: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800C5204: jal         0x800646AC
    // 0x800C5208: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800646AC(rdram, ctx);
        goto after_1;
    // 0x800C5208: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800C520C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800C5210: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800C5214: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800C5218: lw          $a2, -0x598($v0)
    ctx->r6 = MEM_W(ctx->r2, -0X598);
    // 0x800C521C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800C5220: jal         0x800B4618
    // 0x800C5224: addiu       $a2, $a2, 0x60
    ctx->r6 = ADD32(ctx->r6, 0X60);
    func_800B4618(rdram, ctx);
        goto after_2;
    // 0x800C5224: addiu       $a2, $a2, 0x60
    ctx->r6 = ADD32(ctx->r6, 0X60);
    after_2:
    // 0x800C5228: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800C522C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C5230: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C5234: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800C5238: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800C523C: jr          $ra
    // 0x800C5240: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C5240: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void placeRadarDots(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C51E0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800C51E4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800C51E8: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800C51EC: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800C51F0: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800C51F4: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800C51F8: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800C51FC: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800C5200: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800C5204: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800C5208: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800C520C: sdc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X58, ctx->r29);
    // 0x800C5210: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x800C5214: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800C5218: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800C521C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5220: lwc1        $f10, 0x67CC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X67CC);
    // 0x800C5224: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800C5228: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800C522C: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800C5230: add.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800C5234: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800C5238: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C523C: lwc1        $f4, 0x67D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X67D0);
    // 0x800C5240: sub.s       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x800C5244: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x800C5248: addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // 0x800C524C: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800C5250: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800C5254: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800C5258: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800C525C: lbu         $v1, -0x601C($a0)
    ctx->r3 = MEM_BU(ctx->r4, -0X601C);
    // 0x800C5260: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800C5264: trunc.w.s   $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800C5268: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x800C526C: trunc.w.s   $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800C5270: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    // 0x800C5274: trunc.w.s   $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800C5278: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x800C527C: trunc.w.s   $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5280: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x800C5284: beq         $v1, $v0, L_800C5544
    if (ctx->r3 == ctx->r2) {
        // 0x800C5288: addu        $s2, $fp, $zero
        ctx->r18 = ADD32(ctx->r30, 0);
            goto L_800C5544;
    }
    // 0x800C5288: addu        $s2, $fp, $zero
    ctx->r18 = ADD32(ctx->r30, 0);
    // 0x800C528C: mov.s       $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    ctx->f22.fl = ctx->f10.fl;
    // 0x800C5290: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5294: lwc1        $f20, 0x67D4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X67D4);
    // 0x800C5298: lui         $s7, 0x8011
    ctx->r23 = S32(0X8011 << 16);
    // 0x800C529C: addiu       $s7, $s7, -0x601C
    ctx->r23 = ADD32(ctx->r23, -0X601C);
L_800C52A0:
    // 0x800C52A0: slti        $v0, $s2, 0x40
    ctx->r2 = SIGNED(ctx->r18) < 0X40 ? 1 : 0;
    // 0x800C52A4: beq         $v0, $zero, L_800C5544
    if (ctx->r2 == 0) {
        // 0x800C52A8: addu        $s5, $zero, $zero
        ctx->r21 = ADD32(0, 0);
            goto L_800C5544;
    }
    // 0x800C52A8: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x800C52AC: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x800C52B0: addiu       $t1, $t1, -0x6AA0
    ctx->r9 = ADD32(ctx->r9, -0X6AA0);
    // 0x800C52B4: lbu         $v0, 0x0($s7)
    ctx->r2 = MEM_BU(ctx->r23, 0X0);
    // 0x800C52B8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800C52BC: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800C52C0: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C52C4: addiu       $t1, $t1, -0x601C
    ctx->r9 = ADD32(ctx->r9, -0X601C);
    // 0x800C52C8: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x800C52CC: addu        $v0, $fp, $t1
    ctx->r2 = ADD32(ctx->r30, ctx->r9);
    // 0x800C52D0: lbu         $s1, 0x1($v0)
    ctx->r17 = MEM_BU(ctx->r2, 0X1);
    // 0x800C52D4: jal         0x8003FC28
    // 0x800C52D8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8003FC28(rdram, ctx);
        goto after_0;
    // 0x800C52D8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x800C52DC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800C52E0: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800C52E4: ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
    // 0x800C52E8: beq         $v0, $t1, L_800C5518
    if (ctx->r2 == ctx->r9) {
        // 0x800C52EC: sll         $v0, $s2, 1
        ctx->r2 = S32(ctx->r18 << 1);
            goto L_800C5518;
    }
    // 0x800C52EC: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    // 0x800C52F0: sll         $s3, $s1, 4
    ctx->r19 = S32(ctx->r17 << 4);
    // 0x800C52F4: or          $s6, $s1, $s3
    ctx->r22 = ctx->r17 | ctx->r19;
    // 0x800C52F8: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x800C52FC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800C5300: addu        $s0, $v0, $s4
    ctx->r16 = ADD32(ctx->r2, ctx->r20);
L_800C5304:
    // 0x800C5304: jal         0x8004013C
    // 0x800C5308: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    func_8004013C(rdram, ctx);
        goto after_1;
    // 0x800C5308: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_1:
    // 0x800C530C: beq         $v0, $zero, L_800C54FC
    if (ctx->r2 == 0) {
        // 0x800C5310: nop
    
            goto L_800C54FC;
    }
    // 0x800C5310: nop

    // 0x800C5314: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x800C5318: beq         $t0, $zero, L_800C54FC
    if (ctx->r8 == 0) {
        // 0x800C531C: nop
    
            goto L_800C54FC;
    }
    // 0x800C531C: nop

    // 0x800C5320: lwc1        $f2, 0x0($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800C5324: mul.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x800C5328: lwc1        $f0, 0x8($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800C532C: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800C5330: add.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800C5334: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800C5338: sub.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f20.fl;
    // 0x800C533C: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800C5340: trunc.w.s   $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800C5344: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800C5348: trunc.w.s   $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C534C: mfc1        $a0, $f12
    ctx->r4 = (int32_t)ctx->f12.u32l;
    // 0x800C5350: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800C5354: slt         $v0, $t1, $a1
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800C5358: beq         $v0, $zero, L_800C54FC
    if (ctx->r2 == 0) {
        // 0x800C535C: nop
    
            goto L_800C54FC;
    }
    // 0x800C535C: nop

    // 0x800C5360: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800C5364: slt         $v0, $a1, $t1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800C5368: beq         $v0, $zero, L_800C54FC
    if (ctx->r2 == 0) {
        // 0x800C536C: nop
    
            goto L_800C54FC;
    }
    // 0x800C536C: nop

    // 0x800C5370: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800C5374: slt         $v0, $t1, $a0
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800C5378: beq         $v0, $zero, L_800C54FC
    if (ctx->r2 == 0) {
        // 0x800C537C: nop
    
            goto L_800C54FC;
    }
    // 0x800C537C: nop

    // 0x800C5380: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800C5384: slt         $v0, $a0, $t1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800C5388: beq         $v0, $zero, L_800C54FC
    if (ctx->r2 == 0) {
        // 0x800C538C: andi        $v1, $a1, 0x3F
        ctx->r3 = ctx->r5 & 0X3F;
            goto L_800C54FC;
    }
    // 0x800C538C: andi        $v1, $a1, 0x3F
    ctx->r3 = ctx->r5 & 0X3F;
    // 0x800C5390: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800C5394: andi        $v0, $a0, 0x3F
    ctx->r2 = ctx->r4 & 0X3F;
    // 0x800C5398: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800C539C: addu        $a3, $v1, $v0
    ctx->r7 = ADD32(ctx->r3, ctx->r2);
    // 0x800C53A0: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
    // 0x800C53A4: addu        $a0, $s4, $v1
    ctx->r4 = ADD32(ctx->r20, ctx->r3);
    // 0x800C53A8: sh          $a3, 0xC38($s0)
    MEM_H(0XC38, ctx->r16) = ctx->r7;
    // 0x800C53AC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800C53B0: sb          $v0, 0xC3A($s0)
    MEM_B(0XC3A, ctx->r16) = ctx->r2;
    // 0x800C53B4: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800C53B8: andi        $v0, $v0, 0x7FF
    ctx->r2 = ctx->r2 & 0X7FF;
    // 0x800C53BC: addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // 0x800C53C0: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800C53C4: sb          $v0, 0xC3B($s0)
    MEM_B(0XC3B, ctx->r16) = ctx->r2;
    // 0x800C53C8: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    // 0x800C53CC: andi        $v0, $v0, 0x7FF
    ctx->r2 = ctx->r2 & 0X7FF;
    // 0x800C53D0: addu        $a2, $s4, $v0
    ctx->r6 = ADD32(ctx->r20, ctx->r2);
    // 0x800C53D4: addiu       $v1, $v1, 0x21
    ctx->r3 = ADD32(ctx->r3, 0X21);
    // 0x800C53D8: andi        $v1, $v1, 0x7FF
    ctx->r3 = ctx->r3 & 0X7FF;
    // 0x800C53DC: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x800C53E0: addu        $v1, $s4, $v1
    ctx->r3 = ADD32(ctx->r20, ctx->r3);
    // 0x800C53E4: sb          $v0, 0xC3C($s0)
    MEM_B(0XC3C, ctx->r16) = ctx->r2;
    // 0x800C53E8: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800C53EC: andi        $v1, $s1, 0xFF
    ctx->r3 = ctx->r17 & 0XFF;
    // 0x800C53F0: sb          $v0, 0xC3D($s0)
    MEM_B(0XC3D, ctx->r16) = ctx->r2;
    // 0x800C53F4: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x800C53F8: bne         $v1, $v0, L_800C5430
    if (ctx->r3 != ctx->r2) {
        // 0x800C53FC: andi        $v0, $a1, 0x1
        ctx->r2 = ctx->r5 & 0X1;
            goto L_800C5430;
    }
    // 0x800C53FC: andi        $v0, $a1, 0x1
    ctx->r2 = ctx->r5 & 0X1;
    // 0x800C5400: beq         $v0, $zero, L_800C541C
    if (ctx->r2 == 0) {
        // 0x800C5404: nop
    
            goto L_800C541C;
    }
    // 0x800C5404: nop

    // 0x800C5408: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800C540C: andi        $v0, $v0, 0xF0
    ctx->r2 = ctx->r2 & 0XF0;
    // 0x800C5410: or          $v0, $s1, $v0
    ctx->r2 = ctx->r17 | ctx->r2;
    // 0x800C5414: j           L_800C54A4
    // 0x800C5418: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
        goto L_800C54A4;
    // 0x800C5418: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_800C541C:
    // 0x800C541C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800C5420: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x800C5424: or          $v0, $v0, $s3
    ctx->r2 = ctx->r2 | ctx->r19;
    // 0x800C5428: j           L_800C54A4
    // 0x800C542C: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
        goto L_800C54A4;
    // 0x800C542C: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_800C5430:
    // 0x800C5430: beq         $v0, $zero, L_800C549C
    if (ctx->r2 == 0) {
        // 0x800C5434: addiu       $v1, $a3, 0x1
        ctx->r3 = ADD32(ctx->r7, 0X1);
            goto L_800C549C;
    }
    // 0x800C5434: addiu       $v1, $a3, 0x1
    ctx->r3 = ADD32(ctx->r7, 0X1);
    // 0x800C5438: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800C543C: andi        $v1, $v1, 0x7FF
    ctx->r3 = ctx->r3 & 0X7FF;
    // 0x800C5440: andi        $v0, $v0, 0xF0
    ctx->r2 = ctx->r2 & 0XF0;
    // 0x800C5444: or          $v0, $s1, $v0
    ctx->r2 = ctx->r17 | ctx->r2;
    // 0x800C5448: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x800C544C: addu        $a0, $s4, $v1
    ctx->r4 = ADD32(ctx->r20, ctx->r3);
    // 0x800C5450: addiu       $v1, $v1, 0x1F
    ctx->r3 = ADD32(ctx->r3, 0X1F);
    // 0x800C5454: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800C5458: andi        $v1, $v1, 0x7FF
    ctx->r3 = ctx->r3 & 0X7FF;
    // 0x800C545C: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x800C5460: or          $v0, $v0, $s3
    ctx->r2 = ctx->r2 | ctx->r19;
    // 0x800C5464: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x800C5468: addu        $a0, $s4, $v1
    ctx->r4 = ADD32(ctx->r20, ctx->r3);
    // 0x800C546C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C5470: andi        $v1, $v1, 0x7FF
    ctx->r3 = ctx->r3 & 0X7FF;
    // 0x800C5474: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800C5478: addu        $v1, $s4, $v1
    ctx->r3 = ADD32(ctx->r20, ctx->r3);
    // 0x800C547C: andi        $v0, $v0, 0xF0
    ctx->r2 = ctx->r2 & 0XF0;
    // 0x800C5480: or          $v0, $s1, $v0
    ctx->r2 = ctx->r17 | ctx->r2;
    // 0x800C5484: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x800C5488: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800C548C: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x800C5490: or          $v0, $v0, $s3
    ctx->r2 = ctx->r2 | ctx->r19;
    // 0x800C5494: j           L_800C54A4
    // 0x800C5498: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
        goto L_800C54A4;
    // 0x800C5498: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_800C549C:
    // 0x800C549C: sb          $s6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r22;
    // 0x800C54A0: sb          $s6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r22;
L_800C54A4:
    // 0x800C54A4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800C54A8: slti        $v0, $s2, 0x40
    ctx->r2 = SIGNED(ctx->r18) < 0X40 ? 1 : 0;
    // 0x800C54AC: beq         $v0, $zero, L_800C5518
    if (ctx->r2 == 0) {
        // 0x800C54B0: addiu       $s0, $s0, 0x6
        ctx->r16 = ADD32(ctx->r16, 0X6);
            goto L_800C5518;
    }
    // 0x800C54B0: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x800C54B4: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x800C54B8: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800C54BC: lwc1        $f0, 0x0($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800C54C0: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800C54C4: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800C54C8: lwc1        $f2, 0x8($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800C54CC: lwc1        $f0, 0x8($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X8);
    // 0x800C54D0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C54D4: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800C54D8: lwc1        $f0, -0x6020($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X6020);
    // 0x800C54DC: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C54E0: nop

    // 0x800C54E4: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800C54E8: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800C54EC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800C54F0: nop

    // 0x800C54F4: bc1tl       L_800C54FC
    if (c1cs) {
        // 0x800C54F8: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_800C54FC;
    }
    goto skip_0;
    // 0x800C54F8: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    skip_0:
L_800C54FC:
    // 0x800C54FC: jal         0x8003EEF4
    // 0x800C5500: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8003EEF4(rdram, ctx);
        goto after_2;
    // 0x800C5500: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_2:
    // 0x800C5504: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800C5508: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800C550C: ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
    // 0x800C5510: bne         $v0, $t1, L_800C5304
    if (ctx->r2 != ctx->r9) {
        // 0x800C5514: nop
    
            goto L_800C5304;
    }
    // 0x800C5514: nop

L_800C5518:
    // 0x800C5518: addiu       $s7, $s7, 0x2
    ctx->r23 = ADD32(ctx->r23, 0X2);
    // 0x800C551C: sra         $v1, $fp, 1
    ctx->r3 = S32(SIGNED(ctx->r30) >> 1);
    // 0x800C5520: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C5524: addiu       $v0, $v0, -0x4010
    ctx->r2 = ADD32(ctx->r2, -0X4010);
    // 0x800C5528: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800C552C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C5530: sh          $s5, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r21;
    // 0x800C5534: lbu         $v1, 0x0($s7)
    ctx->r3 = MEM_BU(ctx->r23, 0X0);
    // 0x800C5538: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800C553C: bne         $v1, $v0, L_800C52A0
    if (ctx->r3 != ctx->r2) {
        // 0x800C5540: addiu       $fp, $fp, 0x2
        ctx->r30 = ADD32(ctx->r30, 0X2);
            goto L_800C52A0;
    }
    // 0x800C5540: addiu       $fp, $fp, 0x2
    ctx->r30 = ADD32(ctx->r30, 0X2);
L_800C5544:
    // 0x800C5544: sh          $s2, 0xDB8($s4)
    MEM_H(0XDB8, ctx->r20) = ctx->r18;
    // 0x800C5548: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800C554C: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800C5550: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800C5554: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800C5558: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800C555C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800C5560: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800C5564: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800C5568: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800C556C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800C5570: ldc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X58);
    // 0x800C5574: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x800C5578: jr          $ra
    // 0x800C557C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800C557C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_800C5244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5244: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5248: lwc1        $f0, 0x7518($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7518);
    // 0x800C524C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5250: lwc1        $f2, 0x751C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X751C);
    // 0x800C5254: mul.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800C5258: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C525C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800C5260: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800C5264: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800C5268: nop

    // 0x800C526C: bc1t        L_800C5284
    if (c1cs) {
        // 0x800C5270: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_800C5284;
    }
    // 0x800C5270: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C5274: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5278: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800C527C: j           L_800C529C
    // 0x800C5280: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
        goto L_800C529C;
    // 0x800C5280: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
L_800C5284:
    // 0x800C5284: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800C5288: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800C528C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5290: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800C5294: or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
    // 0x800C5298: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
L_800C529C:
    // 0x800C529C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800C52A0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_800C52A4:
    // 0x800C52A4: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // 0x800C52A8: jal         0x80061C74
    // 0x800C52AC: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    func_80061C74(rdram, ctx);
        goto after_0;
    // 0x800C52AC: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    after_0:
    // 0x800C52B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C52B4: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800C52B8: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x800C52BC: bne         $v0, $zero, L_800C52A4
    if (ctx->r2 != 0) {
        // 0x800C52C0: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_800C52A4;
    }
    // 0x800C52C0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800C52C4: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x800C52C8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_800C52CC:
    // 0x800C52CC: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // 0x800C52D0: jal         0x80061C74
    // 0x800C52D4: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    func_80061C74(rdram, ctx);
        goto after_1;
    // 0x800C52D4: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    after_1:
    // 0x800C52D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C52DC: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800C52E0: sltiu       $v0, $v0, 0x10
    ctx->r2 = ctx->r2 < 0X10 ? 1 : 0;
    // 0x800C52E4: bne         $v0, $zero, L_800C52CC
    if (ctx->r2 != 0) {
        // 0x800C52E8: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_800C52CC;
    }
    // 0x800C52E8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x800C52EC: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800C52F0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C52F4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C52F8: jr          $ra
    // 0x800C52FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C52FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800C5300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5300: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C5304: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x800C5308: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C530C: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800C5310: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800C5314: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800C5318: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800C531C: jal         0x80001ACC
    // 0x800C5320: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x800C5320: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x800C5324: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x800C5328: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800C532C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C5330: jal         0x800078E0
    // 0x800C5334: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x800C5334: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_1:
    // 0x800C5338: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800C533C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800C5340: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x800C5344: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800C5348: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x800C534C: lw          $a0, -0xF88($v0)
    ctx->r4 = MEM_W(ctx->r2, -0XF88);
    // 0x800C5350: jal         0x800613C0
    // 0x800C5354: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    func_800613C0(rdram, ctx);
        goto after_2;
    // 0x800C5354: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    after_2:
    // 0x800C5358: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x800C535C: jal         0x80063C6C
    // 0x800C5360: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80063C6C(rdram, ctx);
        goto after_3;
    // 0x800C5360: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_3:
    // 0x800C5364: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
L_800C5368:
    // 0x800C5368: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
    // 0x800C536C: jal         0x80063C3C
    // 0x800C5370: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80063C3C(rdram, ctx);
        goto after_4;
    // 0x800C5370: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_4:
    // 0x800C5374: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x800C5378: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800C537C: jal         0x80063E54
    // 0x800C5380: addiu       $a2, $s3, -0x377C
    ctx->r6 = ADD32(ctx->r19, -0X377C);
    func_80063E54(rdram, ctx);
        goto after_5;
    // 0x800C5380: addiu       $a2, $s3, -0x377C
    ctx->r6 = ADD32(ctx->r19, -0X377C);
    after_5:
    // 0x800C5384: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C5388: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x800C538C: sltiu       $v0, $v0, 0x12
    ctx->r2 = ctx->r2 < 0X12 ? 1 : 0;
    // 0x800C5390: bne         $v0, $zero, L_800C5368
    if (ctx->r2 != 0) {
        // 0x800C5394: addiu       $a0, $zero, 0x9
        ctx->r4 = ADD32(0, 0X9);
            goto L_800C5368;
    }
    // 0x800C5394: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x800C5398: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800C539C: lw          $v1, -0x2AF0($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X2AF0);
    // 0x800C53A0: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x800C53A4: sb          $zero, 0x15($v0)
    MEM_B(0X15, ctx->r2) = 0;
    // 0x800C53A8: sb          $zero, 0x14($v0)
    MEM_B(0X14, ctx->r2) = 0;
    // 0x800C53AC: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x800C53B0: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x800C53B4: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800C53B8: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800C53BC: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800C53C0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800C53C4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C53C8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C53CC: jr          $ra
    // 0x800C53D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C53D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800C53D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C53D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C53D8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800C53DC: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800C53E0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C53E4: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800C53E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C53EC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800C53F0: andi        $s1, $s0, 0xFF
    ctx->r17 = ctx->r16 & 0XFF;
L_800C53F4:
    // 0x800C53F4: sltiu       $v0, $s1, 0x2
    ctx->r2 = ctx->r17 < 0X2 ? 1 : 0;
    // 0x800C53F8: bnel        $v0, $zero, L_800C5420
    if (ctx->r2 != 0) {
        // 0x800C53FC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800C5420;
    }
    goto skip_0;
    // 0x800C53FC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x800C5400: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x800C5404: jal         0x80001ACC
    // 0x800C5408: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x800C5408: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x800C540C: addiu       $v1, $s1, -0x2
    ctx->r3 = ADD32(ctx->r17, -0X2);
    // 0x800C5410: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C5414: addu        $v1, $s2, $v1
    ctx->r3 = ADD32(ctx->r18, ctx->r3);
    // 0x800C5418: sw          $v0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r2;
    // 0x800C541C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800C5420:
    // 0x800C5420: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800C5424: sltiu       $v0, $v0, 0x10
    ctx->r2 = ctx->r2 < 0X10 ? 1 : 0;
    // 0x800C5428: bne         $v0, $zero, L_800C53F4
    if (ctx->r2 != 0) {
        // 0x800C542C: andi        $s1, $s0, 0xFF
        ctx->r17 = ctx->r16 & 0XFF;
            goto L_800C53F4;
    }
    // 0x800C542C: andi        $s1, $s0, 0xFF
    ctx->r17 = ctx->r16 & 0XFF;
    // 0x800C5430: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    // 0x800C5434: jal         0x80001ACC
    // 0x800C5438: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x800C5438: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x800C543C: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    // 0x800C5440: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C5444: jal         0x80001ACC
    // 0x800C5448: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    rs_malloc(rdram, ctx);
        goto after_2;
    // 0x800C5448: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    after_2:
    // 0x800C544C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5450: lwc1        $f0, 0x7520($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7520);
    // 0x800C5454: sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // 0x800C5458: sw          $zero, 0x58($s2)
    MEM_W(0X58, ctx->r18) = 0;
    // 0x800C545C: swc1        $f0, 0x5C($s2)
    MEM_W(0X5C, ctx->r18) = ctx->f0.u32l;
    // 0x800C5460: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C5464: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800C5468: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C546C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C5470: jr          $ra
    // 0x800C5474: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C5474: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800C5478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5478: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C547C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800C5480: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800C5484: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800C5488: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C548C: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x800C5490: jal         0x80001C98
    // 0x800C5494: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    rs_free(rdram, ctx);
        goto after_0;
    // 0x800C5494: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    after_0:
    // 0x800C5498: lw          $a0, 0x1C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X1C);
    // 0x800C549C: jal         0x80001C98
    // 0x800C54A0: nop

    rs_free(rdram, ctx);
        goto after_1;
    // 0x800C54A0: nop

    after_1:
    // 0x800C54A4: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
L_800C54A8:
    // 0x800C54A8: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x800C54AC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C54B0: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800C54B4: lw          $a0, 0x20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X20);
    // 0x800C54B8: jal         0x80001C98
    // 0x800C54BC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    rs_free(rdram, ctx);
        goto after_2;
    // 0x800C54BC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_2:
    // 0x800C54C0: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800C54C4: sltiu       $v0, $v0, 0x10
    ctx->r2 = ctx->r2 < 0X10 ? 1 : 0;
    // 0x800C54C8: bnel        $v0, $zero, L_800C54A8
    if (ctx->r2 != 0) {
        // 0x800C54CC: andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
            goto L_800C54A8;
    }
    goto skip_0;
    // 0x800C54CC: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    skip_0:
    // 0x800C54D0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800C54D4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C54D8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C54DC: jr          $ra
    // 0x800C54E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C54E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800C54E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C54E4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C54E8: lwc1        $f0, 0x7524($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7524);
    // 0x800C54EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C54F0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800C54F4: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x800C54F8: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800C54FC: nop

    // 0x800C5500: bc1f        L_800C55D8
    if (!c1cs) {
        // 0x800C5504: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_800C55D8;
    }
    // 0x800C5504: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800C5508: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C550C: lwc1        $f0, 0x7528($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7528);
    // 0x800C5510: mul.s       $f4, $f20, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800C5514: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5518: lwc1        $f0, 0x752C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X752C);
    // 0x800C551C: mul.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800C5520: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800C5524: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800C5528: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C552C: lwc1        $f2, 0x7530($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7530);
    // 0x800C5530: lw          $v0, -0x1D4($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X1D4);
    // 0x800C5534: div.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C5538: beq         $a1, $zero, L_800C5550
    if (ctx->r5 == 0) {
        // 0x800C553C: swc1        $f2, 0x24($v0)
        MEM_W(0X24, ctx->r2) = ctx->f2.u32l;
            goto L_800C5550;
    }
    // 0x800C553C: swc1        $f2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f2.u32l;
    // 0x800C5540: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5544: lwc1        $f0, 0x7534($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7534);
    // 0x800C5548: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C554C: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
L_800C5550:
    // 0x800C5550: lw          $v0, -0x1D4($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X1D4);
    // 0x800C5554: beq         $a1, $zero, L_800C556C
    if (ctx->r5 == 0) {
        // 0x800C5558: swc1        $f4, 0x28($v0)
        MEM_W(0X28, ctx->r2) = ctx->f4.u32l;
            goto L_800C556C;
    }
    // 0x800C5558: swc1        $f4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f4.u32l;
    // 0x800C555C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5560: lwc1        $f0, 0x7538($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7538);
    // 0x800C5564: mul.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800C5568: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
L_800C556C:
    // 0x800C556C: lw          $v0, -0x1D4($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X1D4);
    // 0x800C5570: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5574: lwc1        $f4, 0x753C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X753C);
    // 0x800C5578: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800C557C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800C5580: lwc1        $f2, 0x28($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800C5584: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800C5588: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C558C: lwc1        $f4, 0x7540($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7540);
    // 0x800C5590: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800C5594: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800C5598: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C559C: lwc1        $f4, 0x7544($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7544);
    // 0x800C55A0: lw          $a0, -0x1C8($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X1C8);
    // 0x800C55A4: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800C55A8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C55AC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800C55B0: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x800C55B4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800C55B8: trunc.w.s   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800C55BC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800C55C0: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x800C55C4: jal         0x800B3CD4
    // 0x800C55C8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    func_800B3CD4(rdram, ctx);
        goto after_0;
    // 0x800C55C8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    after_0:
    // 0x800C55CC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C55D0: lwc1        $f0, 0x7548($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7548);
    // 0x800C55D4: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
L_800C55D8:
    // 0x800C55D8: nop

    // 0x800C55DC: bc1t        L_800C55E8
    if (c1cs) {
        // 0x800C55E0: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_800C55E8;
    }
    // 0x800C55E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800C55E4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_800C55E8:
    // 0x800C55E8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800C55EC: lw          $a0, -0xF84($v0)
    ctx->r4 = MEM_W(ctx->r2, -0XF84);
    // 0x800C55F0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800C55F4: lw          $a1, -0x1D4($v0)
    ctx->r5 = MEM_W(ctx->r2, -0X1D4);
    // 0x800C55F8: jal         0x800646AC
    // 0x800C55FC: nop

    func_800646AC(rdram, ctx);
        goto after_1;
    // 0x800C55FC: nop

    after_1:
    // 0x800C5600: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800C5604: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800C5608: jr          $ra
    // 0x800C560C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C560C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800C5580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5580: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800C5584: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C5588: sdc1        $f24, 0x58($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X58, ctx->r29);
    // 0x800C558C: mtc1        $a3, $f24
    ctx->f24.u32l = ctx->r7;
    // 0x800C5590: lh          $v0, -0x3F80($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X3F80);
    // 0x800C5594: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800C5598: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x800C559C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800C55A0: addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // 0x800C55A4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800C55A8: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x800C55AC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800C55B0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800C55B4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800C55B8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800C55BC: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800C55C0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800C55C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C55C8: sdc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X50, ctx->r29);
    // 0x800C55CC: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x800C55D0: blez        $v0, L_800C5754
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C55D4: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_800C5754;
    }
    // 0x800C55D4: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800C55D8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800C55DC: addiu       $fp, $v0, -0x7760
    ctx->r30 = ADD32(ctx->r2, -0X7760);
    // 0x800C55E0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800C55E4: addiu       $s7, $v0, -0x7FA0
    ctx->r23 = ADD32(ctx->r2, -0X7FA0);
    // 0x800C55E8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C55EC: addiu       $s5, $v0, -0x4000
    ctx->r21 = ADD32(ctx->r2, -0X4000);
L_800C55F0:
    // 0x800C55F0: lw          $s1, 0x0($s5)
    ctx->r17 = MEM_W(ctx->r21, 0X0);
    // 0x800C55F4: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x800C55F8: blez        $v0, L_800C560C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C55FC: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800C560C;
    }
    // 0x800C55FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C5600: addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // 0x800C5604: lbu         $v0, -0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X1);
    // 0x800C5608: sltu        $a0, $zero, $v0
    ctx->r4 = 0 < ctx->r2 ? 1 : 0;
L_800C560C:
    // 0x800C560C: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x800C5610: blez        $v0, L_800C5634
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C5614: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800C5634;
    }
    // 0x800C5614: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800C5618: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C561C: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x800C5620: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800C5624: lw          $v1, 0x38($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X38);
    // 0x800C5628: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C562C: bnel        $v0, $zero, L_800C5634
    if (ctx->r2 != 0) {
        // 0x800C5630: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800C5634;
    }
    goto skip_0;
    // 0x800C5630: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_0:
L_800C5634:
    // 0x800C5634: lw          $v0, 0x3C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X3C);
    // 0x800C5638: blez        $v0, L_800C564C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C563C: addu        $v0, $v0, $fp
        ctx->r2 = ADD32(ctx->r2, ctx->r30);
            goto L_800C564C;
    }
    // 0x800C563C: addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // 0x800C5640: lbu         $v0, -0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X1);
    // 0x800C5644: bnel        $v0, $zero, L_800C564C
    if (ctx->r2 != 0) {
        // 0x800C5648: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800C564C;
    }
    goto skip_1;
    // 0x800C5648: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_1:
L_800C564C:
    // 0x800C564C: lw          $v0, 0x40($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X40);
    // 0x800C5650: blez        $v0, L_800C5674
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C5654: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800C5674;
    }
    // 0x800C5654: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800C5658: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C565C: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x800C5660: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800C5664: lw          $v1, 0x44($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X44);
    // 0x800C5668: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C566C: beql        $v0, $zero, L_800C5674
    if (ctx->r2 == 0) {
        // 0x800C5670: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800C5674;
    }
    goto skip_2;
    // 0x800C5670: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_2:
L_800C5674:
    // 0x800C5674: beq         $a0, $zero, L_800C5728
    if (ctx->r4 == 0) {
        // 0x800C5678: nop
    
            goto L_800C5728;
    }
    // 0x800C5678: nop

    // 0x800C567C: lw          $s0, 0x2C($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X2C);
    // 0x800C5680: beq         $s0, $zero, L_800C56DC
    if (ctx->r16 == 0) {
        // 0x800C5684: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_800C56DC;
    }
    // 0x800C5684: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800C5688: lhu         $v1, 0x6($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X6);
    // 0x800C568C: beq         $v1, $v0, L_800C56C4
    if (ctx->r3 == ctx->r2) {
        // 0x800C5690: nop
    
            goto L_800C56C4;
    }
    // 0x800C5690: nop

    // 0x800C5694: jal         0x8004015C
    // 0x800C5698: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    func_8004015C(rdram, ctx);
        goto after_0;
    // 0x800C5698: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_0:
    // 0x800C569C: beq         $v0, $zero, L_800C56C4
    if (ctx->r2 == 0) {
        // 0x800C56A0: nop
    
            goto L_800C56C4;
    }
    // 0x800C56A0: nop

    // 0x800C56A4: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x800C56A8: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800C56AC: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800C56B0: sw          $a2, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r6;
    // 0x800C56B4: sw          $t0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r8;
    // 0x800C56B8: sw          $t1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r9;
    // 0x800C56BC: j           L_800C56DC
    // 0x800C56C0: nop

        goto L_800C56DC;
    // 0x800C56C0: nop

L_800C56C4:
    // 0x800C56C4: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x800C56C8: lw          $t0, 0x14($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X14);
    // 0x800C56CC: lw          $t1, 0x18($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X18);
    // 0x800C56D0: sw          $a2, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r6;
    // 0x800C56D4: sw          $t0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r8;
    // 0x800C56D8: sw          $t1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r9;
L_800C56DC:
    // 0x800C56DC: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800C56E0: lwc1        $f2, 0x0($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800C56E4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800C56E8: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C56EC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800C56F0: lwc1        $f0, 0x18($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X18);
    // 0x800C56F4: lwc1        $f2, 0x8($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X8);
    // 0x800C56F8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800C56FC: mul.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C5700: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800C5704: bltz        $s3, L_800C571C
    if (SIGNED(ctx->r19) < 0) {
        // 0x800C5708: add.s       $f22, $f4, $f2
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f4.fl + ctx->f2.fl;
            goto L_800C571C;
    }
    // 0x800C5708: add.s       $f22, $f4, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800C570C: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x800C5710: nop

    // 0x800C5714: bc1f        L_800C5740
    if (!c1cs) {
        // 0x800C5718: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800C5740;
    }
    // 0x800C5718: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800C571C:
    // 0x800C571C: addu        $s3, $s2, $zero
    ctx->r19 = ADD32(ctx->r18, 0);
    // 0x800C5720: j           L_800C573C
    // 0x800C5724: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
        goto L_800C573C;
    // 0x800C5724: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
L_800C5728:
    // 0x800C5728: lh          $v0, 0xDC8($s4)
    ctx->r2 = MEM_H(ctx->r20, 0XDC8);
    // 0x800C572C: bne         $s2, $v0, L_800C5740
    if (ctx->r18 != ctx->r2) {
        // 0x800C5730: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800C5740;
    }
    // 0x800C5730: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C5734: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800C5738: sh          $v0, 0xDC8($s4)
    MEM_H(0XDC8, ctx->r20) = ctx->r2;
L_800C573C:
    // 0x800C573C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800C5740:
    // 0x800C5740: lh          $v0, -0x3F80($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X3F80);
    // 0x800C5744: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800C5748: slt         $v0, $s2, $v0
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C574C: bne         $v0, $zero, L_800C55F0
    if (ctx->r2 != 0) {
        // 0x800C5750: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_800C55F0;
    }
    // 0x800C5750: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_800C5754:
    // 0x800C5754: lh          $v0, 0xDC8($s4)
    ctx->r2 = MEM_H(ctx->r20, 0XDC8);
    // 0x800C5758: bltzl       $v0, L_800C57E8
    if (SIGNED(ctx->r2) < 0) {
        // 0x800C575C: sh          $s3, 0xDC8($s4)
        MEM_H(0XDC8, ctx->r20) = ctx->r19;
            goto L_800C57E8;
    }
    goto skip_3;
    // 0x800C575C: sh          $s3, 0xDC8($s4)
    MEM_H(0XDC8, ctx->r20) = ctx->r19;
    skip_3:
    // 0x800C5760: beq         $s3, $v0, L_800C57DC
    if (ctx->r19 == ctx->r2) {
        // 0x800C5764: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_800C57DC;
    }
    // 0x800C5764: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800C5768: addiu       $v1, $v1, -0x4000
    ctx->r3 = ADD32(ctx->r3, -0X4000);
    // 0x800C576C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C5770: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C5774: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800C5778: lwc1        $f0, 0x0($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800C577C: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800C5780: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800C5784: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800C5788: lh          $v0, 0xDC8($s4)
    ctx->r2 = MEM_H(ctx->r20, 0XDC8);
    // 0x800C578C: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800C5790: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C5794: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C5798: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800C579C: lwc1        $f2, 0x8($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X8);
    // 0x800C57A0: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800C57A4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800C57A8: mul.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C57AC: add.s       $f22, $f4, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800C57B0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C57B4: lwc1        $f2, 0x67D8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X67D8);
    // 0x800C57B8: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x800C57BC: bltz        $s3, L_800C57EC
    if (SIGNED(ctx->r19) < 0) {
        // 0x800C57C0: swc1        $f0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
            goto L_800C57EC;
    }
    // 0x800C57C0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800C57C4: c.lt.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
    // 0x800C57C8: nop

    // 0x800C57CC: bc1f        L_800C57EC
    if (!c1cs) {
        // 0x800C57D0: nop
    
            goto L_800C57EC;
    }
    // 0x800C57D0: nop

    // 0x800C57D4: j           L_800C57E8
    // 0x800C57D8: sh          $s3, 0xDC8($s4)
    MEM_H(0XDC8, ctx->r20) = ctx->r19;
        goto L_800C57E8;
    // 0x800C57D8: sh          $s3, 0xDC8($s4)
    MEM_H(0XDC8, ctx->r20) = ctx->r19;
L_800C57DC:
    // 0x800C57DC: bgez        $s3, L_800C57F8
    if (SIGNED(ctx->r19) >= 0) {
        // 0x800C57E0: nop
    
            goto L_800C57F8;
    }
    // 0x800C57E0: nop

    // 0x800C57E4: sh          $s3, 0xDC8($s4)
    MEM_H(0XDC8, ctx->r20) = ctx->r19;
L_800C57E8:
    // 0x800C57E8: sw          $zero, 0xDCC($s4)
    MEM_W(0XDCC, ctx->r20) = 0;
L_800C57EC:
    // 0x800C57EC: lh          $v0, 0xDC8($s4)
    ctx->r2 = MEM_H(ctx->r20, 0XDC8);
    // 0x800C57F0: bltz        $v0, L_800C58D8
    if (SIGNED(ctx->r2) < 0) {
        // 0x800C57F4: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_800C58D8;
    }
    // 0x800C57F4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
L_800C57F8:
    // 0x800C57F8: lh          $v0, 0xDC8($s4)
    ctx->r2 = MEM_H(ctx->r20, 0XDC8);
    // 0x800C57FC: addiu       $v1, $v1, -0x4000
    ctx->r3 = ADD32(ctx->r3, -0X4000);
    // 0x800C5800: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C5804: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C5808: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800C580C: lwc1        $f0, 0x0($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800C5810: lwc1        $f2, 0x10($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800C5814: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800C5818: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x800C581C: lh          $v0, 0xDC8($s4)
    ctx->r2 = MEM_H(ctx->r20, 0XDC8);
    // 0x800C5820: mul.s       $f2, $f12, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800C5824: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C5828: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C582C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800C5830: lwc1        $f0, 0x8($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X8);
    // 0x800C5834: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800C5838: sub.s       $f14, $f4, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800C583C: mul.s       $f0, $f14, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800C5840: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x800C5844: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C5848: sqrt.s      $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = sqrtf(ctx->f2.fl);
    // 0x800C584C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5850: lwc1        $f2, 0x67DC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X67DC);
    // 0x800C5854: c.lt.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl < ctx->f22.fl;
    // 0x800C5858: nop

    // 0x800C585C: bc1fl       L_800C58DC
    if (!c1cs) {
        // 0x800C5860: sw          $zero, 0xDC4($s4)
        MEM_W(0XDC4, ctx->r20) = 0;
            goto L_800C58DC;
    }
    goto skip_4;
    // 0x800C5860: sw          $zero, 0xDC4($s4)
    MEM_W(0XDC4, ctx->r20) = 0;
    skip_4:
    // 0x800C5864: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5868: lwc1        $f0, 0x67E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X67E0);
    // 0x800C586C: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x800C5870: nop

    // 0x800C5874: bc1tl       L_800C587C
    if (c1cs) {
        // 0x800C5878: mov.s       $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
            goto L_800C587C;
    }
    goto skip_5;
    // 0x800C5878: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    skip_5:
L_800C587C:
    // 0x800C587C: sub.s       $f0, $f22, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f22.fl - ctx->f2.fl;
    // 0x800C5880: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5884: lwc1        $f2, 0x67E4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X67E4);
    // 0x800C5888: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C588C: lwc1        $f20, 0x67E8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X67E8);
    // 0x800C5890: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C5894: jal         0x8001C5F4
    // 0x800C5898: sub.s       $f22, $f20, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f20.fl - ctx->f0.fl;
    func_8001C5F4(rdram, ctx);
        goto after_1;
    // 0x800C5898: sub.s       $f22, $f20, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f20.fl - ctx->f0.fl;
    after_1:
    // 0x800C589C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C58A0: lwc1        $f2, 0x67EC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X67EC);
    // 0x800C58A4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C58A8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C58AC: lwc1        $f4, 0x67F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X67F0);
    // 0x800C58B0: mul.s       $f4, $f22, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x800C58B4: sub.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x800C58B8: mul.s       $f20, $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x800C58BC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C58C0: lwc1        $f2, 0x67F4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X67F4);
    // 0x800C58C4: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800C58C8: swc1        $f0, 0xDBC($s4)
    MEM_W(0XDBC, ctx->r20) = ctx->f0.u32l;
    // 0x800C58CC: swc1        $f4, 0xDC0($s4)
    MEM_W(0XDC0, ctx->r20) = ctx->f4.u32l;
    // 0x800C58D0: j           L_800C58DC
    // 0x800C58D4: swc1        $f20, 0xDC4($s4)
    MEM_W(0XDC4, ctx->r20) = ctx->f20.u32l;
        goto L_800C58DC;
    // 0x800C58D4: swc1        $f20, 0xDC4($s4)
    MEM_W(0XDC4, ctx->r20) = ctx->f20.u32l;
L_800C58D8:
    // 0x800C58D8: sw          $zero, 0xDC4($s4)
    MEM_W(0XDC4, ctx->r20) = 0;
L_800C58DC:
    // 0x800C58DC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800C58E0: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800C58E4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800C58E8: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800C58EC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800C58F0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800C58F4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800C58F8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800C58FC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800C5900: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C5904: ldc1        $f24, 0x58($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X58);
    // 0x800C5908: ldc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X50);
    // 0x800C590C: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x800C5910: jr          $ra
    // 0x800C5914: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800C5914: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_800C5610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5610: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5614: lwc1        $f0, 0x754C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X754C);
    // 0x800C5618: mul.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800C561C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5620: lwc1        $f2, 0x7550($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7550);
    // 0x800C5624: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C5628: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C562C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800C5630: nop

    // 0x800C5634: bc1t        L_800C564C
    if (c1cs) {
        // 0x800C5638: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_800C564C;
    }
    // 0x800C5638: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C563C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5640: mfc1        $s0, $f4
    ctx->r16 = (int32_t)ctx->f4.u32l;
    // 0x800C5644: j           L_800C5664
    // 0x800C5648: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
        goto L_800C5664;
    // 0x800C5648: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_800C564C:
    // 0x800C564C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800C5650: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800C5654: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5658: mfc1        $s0, $f4
    ctx->r16 = (int32_t)ctx->f4.u32l;
    // 0x800C565C: or          $s0, $s0, $v0
    ctx->r16 = ctx->r16 | ctx->r2;
    // 0x800C5660: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_800C5664:
    // 0x800C5664: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C5668: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x800C566C: jal         0x80061C74
    // 0x800C5670: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80061C74(rdram, ctx);
        goto after_0;
    // 0x800C5670: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_0:
    // 0x800C5674: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x800C5678: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800C567C: jal         0x80061C74
    // 0x800C5680: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80061C74(rdram, ctx);
        goto after_1;
    // 0x800C5680: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800C5684: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x800C5688: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800C568C: jal         0x80061C74
    // 0x800C5690: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80061C74(rdram, ctx);
        goto after_2;
    // 0x800C5690: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_2:
    // 0x800C5694: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C5698: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C569C: jr          $ra
    // 0x800C56A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C56A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800C56A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C56A4: lwc1        $f2, 0xA4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XA4);
    // 0x800C56A8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800C56AC: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x800C56B0: nop

    // 0x800C56B4: bc1tl       L_800C56BC
    if (c1cs) {
        // 0x800C56B8: sw          $a1, 0xAC($a0)
        MEM_W(0XAC, ctx->r4) = ctx->r5;
            goto L_800C56BC;
    }
    goto skip_0;
    // 0x800C56B8: sw          $a1, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->r5;
    skip_0:
L_800C56BC:
    // 0x800C56BC: jr          $ra
    // 0x800C56C0: nop

    return;
    // 0x800C56C0: nop

;}
RECOMP_FUNC void func_800C56C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C56C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C56C8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800C56CC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800C56D0: jal         0x800B883C
    // 0x800C56D4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_800B883C(rdram, ctx);
        goto after_0;
    // 0x800C56D4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x800C56D8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800C56DC: jr          $ra
    // 0x800C56E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C56E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800C56E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C56E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C56E8: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // 0x800C56EC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C56F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C56F4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800C56F8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800C56FC: jal         0x80001ACC
    // 0x800C5700: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x800C5700: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x800C5704: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800C5708: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800C570C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C5710: jal         0x800078E0
    // 0x800C5714: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x800C5714: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_1:
    // 0x800C5718: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800C571C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800C5720: addiu       $s2, $v0, -0x2E7C
    ctx->r18 = ADD32(ctx->r2, -0X2E7C);
    // 0x800C5724: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
L_800C5728:
    // 0x800C5728: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800C572C: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x800C5730: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800C5734: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C5738: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800C573C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C5740: jal         0x8005645C
    // 0x800C5744: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    load_hmt_and_hob(rdram, ctx);
        goto after_2;
    // 0x800C5744: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_2:
    // 0x800C5748: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800C574C: sltiu       $v0, $v0, 0x12
    ctx->r2 = ctx->r2 < 0X12 ? 1 : 0;
    // 0x800C5750: bne         $v0, $zero, L_800C5728
    if (ctx->r2 != 0) {
        // 0x800C5754: andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
            goto L_800C5728;
    }
    // 0x800C5754: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800C5758: jal         0x80079A70
    // 0x800C575C: nop

    func_80079A70(rdram, ctx);
        goto after_3;
    // 0x800C575C: nop

    after_3:
    // 0x800C5760: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800C5764: jal         0x80003430
    // 0x800C5768: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    rand_recomp(rdram, ctx);
        goto after_4;
    // 0x800C5768: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    after_4:
    // 0x800C576C: lui         $a0, 0x38E3
    ctx->r4 = S32(0X38E3 << 16);
    // 0x800C5770: ori         $a0, $a0, 0x8E39
    ctx->r4 = ctx->r4 | 0X8E39;
    // 0x800C5774: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x800C5778: sra         $a1, $v1, 16
    ctx->r5 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800C577C: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x800C5780: mult        $a1, $a0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C5784: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x800C5788: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800C578C: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x800C5790: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800C5794: mfhi        $t0
    ctx->r8 = hi;
    // 0x800C5798: sra         $a0, $t0, 2
    ctx->r4 = S32(SIGNED(ctx->r8) >> 2);
    // 0x800C579C: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x800C57A0: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x800C57A4: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800C57A8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800C57AC: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x800C57B0: sb          $a1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r5;
    // 0x800C57B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C57B8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800C57BC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C57C0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C57C4: jr          $ra
    // 0x800C57C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C57C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800C57CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C57CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C57D0: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x800C57D4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800C57D8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800C57DC: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    // 0x800C57E0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800C57E4: jal         0x80006C28
    // 0x800C57E8: addiu       $a3, $a3, 0x5834
    ctx->r7 = ADD32(ctx->r7, 0X5834);
    func_80006C28(rdram, ctx);
        goto after_0;
    // 0x800C57E8: addiu       $a3, $a3, 0x5834
    ctx->r7 = ADD32(ctx->r7, 0X5834);
    after_0:
    // 0x800C57EC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800C57F0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800C57F4: jal         0x80006D9C
    // 0x800C57F8: sw          $v0, -0x31E8($v1)
    MEM_W(-0X31E8, ctx->r3) = ctx->r2;
    func_80006D9C(rdram, ctx);
        goto after_1;
    // 0x800C57F8: sw          $v0, -0x31E8($v1)
    MEM_W(-0X31E8, ctx->r3) = ctx->r2;
    after_1:
    // 0x800C57FC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800C5800: jr          $ra
    // 0x800C5804: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C5804: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800C5808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5808: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C580C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800C5810: lw          $a0, -0x31E8($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X31E8);
    // 0x800C5814: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800C5818: beq         $a0, $v0, L_800C5828
    if (ctx->r4 == ctx->r2) {
        // 0x800C581C: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_800C5828;
    }
    // 0x800C581C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800C5820: jal         0x800070BC
    // 0x800C5824: nop

    func_800070BC(rdram, ctx);
        goto after_0;
    // 0x800C5824: nop

    after_0:
L_800C5828:
    // 0x800C5828: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800C582C: jr          $ra
    // 0x800C5830: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C5830: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800C5834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5834: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C5838: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800C583C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800C5840: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x800C5844: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
L_800C5848:
    // 0x800C5848: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800C584C: jal         0x80006F24
    // 0x800C5850: nop

    func_80006F24(rdram, ctx);
        goto after_0;
    // 0x800C5850: nop

    after_0:
    // 0x800C5854: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800C5858: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x800C585C: jal         0x80066918
    // 0x800C5860: nop

    func_80066918(rdram, ctx);
        goto after_1;
    // 0x800C5860: nop

    after_1:
    // 0x800C5864: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800C5868: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x800C586C: jal         0x8006657C
    // 0x800C5870: nop

    func_8006657C(rdram, ctx);
        goto after_2;
    // 0x800C5870: nop

    after_2:
    // 0x800C5874: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // 0x800C5878: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800C587C: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x800C5880: jal         0x80006F78
    // 0x800C5884: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80006F78(rdram, ctx);
        goto after_3;
    // 0x800C5884: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_3:
    // 0x800C5888: jal         0x80001C98
    // 0x800C588C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    rs_free(rdram, ctx);
        goto after_4;
    // 0x800C588C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x800C5890: j           L_800C5848
    // 0x800C5894: nop

        goto L_800C5848;
    // 0x800C5894: nop

;}
RECOMP_FUNC void fake_func_800C5898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800C58A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    { if(0) fprintf(stderr, "[trace] menu_overlay_init func_800C58A0 ENTRY\n"); fflush(stderr); }
    // 0x800C58A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C58A4: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800C58A8: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800C58AC: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800C58B0: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x800C58B4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800C58B8: addiu       $a0, $a0, -0xA0
    ctx->r4 = ADD32(ctx->r4, -0XA0);
    // 0x800C58BC: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x800C58C0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C58C4: lui         $s0, 0x8003
    ctx->r16 = S32(0X8003 << 16);
    // 0x800C58C8: addiu       $s0, $s0, 0x7560
    ctx->r16 = ADD32(ctx->r16, 0X7560);
    // 0x800C58CC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800C58D0: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x800C58D4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800C58D8: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800C58DC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C58E0: sh          $v0, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r2;
    // 0x800C58E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C58E8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800C58EC: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x800C58F0: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x800C58F4: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x800C58F8: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800C58FC: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800C5900: jal         0x80018EF4
    // 0x800C5904: sb          $v0, 0xB3A($v1)
    MEM_B(0XB3A, ctx->r3) = ctx->r2;
    zmemcpy(rdram, ctx);
        goto after_0;
    // 0x800C5904: sb          $v0, 0xB3A($v1)
    MEM_B(0XB3A, ctx->r3) = ctx->r2;
    after_0:
    { static int n=0; if (++n<=3) { if(0) fprintf(stderr, "[trace] func_800C58A0 reached 0x800C5908 (after first zmemcpy)\n"); fflush(stderr); } }
    // 0x800C5908: jal         0x80079EB0
    // 0x800C590C: addiu       $fp, $zero, 0xB
    ctx->r30 = ADD32(0, 0XB);
    initNewAndPreviousButtonsPressed(rdram, ctx);
        goto after_1;
    // 0x800C590C: addiu       $fp, $zero, 0xB
    ctx->r30 = ADD32(0, 0XB);
    after_1:
    // 0x800C5910: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x800C5914: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800C5918: addiu       $s2, $t0, 0xB40
    ctx->r18 = ADD32(ctx->r8, 0XB40);
    // 0x800C591C: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
    // 0x800C5920: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C5924: addiu       $s5, $v0, 0xB10
    ctx->r21 = ADD32(ctx->r2, 0XB10);
L_800C5928:
    { static int n=0; if (++n<=3) { if(0) fprintf(stderr, "[trace] func_800C58A0 reached 0x800C5928 (loop top)\n"); fflush(stderr); } }
    // 0x800C5928: jal         0x8008DA00
    // 0x800C592C: nop

    func_8008DA00(rdram, ctx);
        goto after_2;
    // 0x800C592C: nop

    after_2:
L_800C5930:
    { static int n=0; if (++n<=3) { if(0) fprintf(stderr, "[trace] func_800C58A0 reached 0x800C5930 (busy-wait)\n"); fflush(stderr); } }
    // 0x800C5930: jal         0x8008E57C
    // 0x800C5934: nop

    func_8008E57C(rdram, ctx);
        goto after_3;
    // 0x800C5934: nop

    after_3:
    // 0x800C5938: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C593C: beq         $v0, $zero, L_800C5930
    if (ctx->r2 == 0) {
        // 0x800C5940: lui         $t0, 0x800D
        ctx->r8 = S32(0X800D << 16);
            goto L_800C5930;
    }
    // 0x800C5940: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    { static int n=0; if (++n<=3) { if(0) fprintf(stderr, "[trace] func_800C58A0 reached 0x800C5944 (after busy-wait)\n"); fflush(stderr); } }
    // 0x800C5944: lhu         $v0, -0xB0($s1)
    ctx->r2 = MEM_HU(ctx->r17, -0XB0);
    // 0x800C5948: addiu       $t0, $t0, -0x2D50
    ctx->r8 = ADD32(ctx->r8, -0X2D50);
    // 0x800C594C: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x800C5950: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C5954: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C5958: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C595C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800C5960: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x800C5964: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800C5968: sh          $v0, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r2;
    // 0x800C596C: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
    // 0x800C5970: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x800C5974: sh          $v0, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r2;
    // 0x800C5978: sh          $a0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r4;
    // 0x800C597C: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x800C5980: sh          $v0, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r2;
    // 0x800C5984: lhu         $v0, 0x6($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X6);
    // 0x800C5988: sh          $v0, 0x42($s0)
    MEM_H(0X42, ctx->r16) = ctx->r2;
    // 0x800C598C: lhu         $v0, 0x10($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X10);
    // 0x800C5990: sll         $v0, $v0, 10
    ctx->r2 = S32(ctx->r2 << 10);
    // 0x800C5994: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
    // 0x800C5998: lhu         $v0, 0x12($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X12);
    // 0x800C599C: sll         $v0, $v0, 10
    ctx->r2 = S32(ctx->r2 << 10);
    // 0x800C59A0: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x800C59A4: lhu         $a0, 0x14($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X14);
    // 0x800C59A8: sll         $v0, $a0, 10
    ctx->r2 = S32(ctx->r4 << 10);
    // 0x800C59AC: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x800C59B0: lhu         $v0, 0x16($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X16);
    // 0x800C59B4: sw          $v0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r2;
    // 0x800C59B8: lbu         $v0, 0x8($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X8);
    // 0x800C59BC: sb          $v0, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r2;
    // 0x800C59C0: lbu         $v0, 0x9($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X9);
    // 0x800C59C4: sb          $v0, 0x21($s0)
    MEM_B(0X21, ctx->r16) = ctx->r2;
    // 0x800C59C8: lbu         $v0, 0xA($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XA);
    // 0x800C59CC: sb          $v0, 0x22($s0)
    MEM_B(0X22, ctx->r16) = ctx->r2;
    // 0x800C59D0: lhu         $v0, 0xC($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XC);
    // 0x800C59D4: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x800C59D8: lbu         $v0, 0x18($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X18);
    // 0x800C59DC: sb          $v0, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r2;
    // 0x800C59E0: lhu         $v1, 0xE($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0XE);
    // 0x800C59E4: addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // 0x800C59E8: sh          $v0, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r2;
    // 0x800C59EC: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // 0x800C59F0: sh          $v0, 0x3E($s0)
    MEM_H(0X3E, ctx->r16) = ctx->r2;
    // 0x800C59F4: sh          $v1, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r3;
    // 0x800C59F8: lbu         $v0, 0x23($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X23);
    // 0x800C59FC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C5A00: bnel        $v0, $t0, L_800C5A14
    if (ctx->r2 != ctx->r8) {
        // 0x800C5A04: addiu       $a0, $s0, 0x10
        ctx->r4 = ADD32(ctx->r16, 0X10);
            goto L_800C5A14;
    }
    goto skip_0;
    // 0x800C5A04: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    skip_0:
    // 0x800C5A08: sll         $v0, $a0, 11
    ctx->r2 = S32(ctx->r4 << 11);
    // 0x800C5A0C: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x800C5A10: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
L_800C5A14:
    { static int n=0; if (++n<=3) { if(0) fprintf(stderr, "[trace] func_800C58A0 reached 0x800C5A14 (after state-setup)\n"); fflush(stderr); } }
    // 0x800C5A14: addiu       $a1, $s0, 0x2C
    ctx->r5 = ADD32(ctx->r16, 0X2C);
    // 0x800C5A18: jal         0x80001354
    // 0x800C5A1C: addiu       $a2, $s0, 0x1C
    ctx->r6 = ADD32(ctx->r16, 0X1C);
    func_80001354(rdram, ctx);
        goto after_4;
    // 0x800C5A1C: addiu       $a2, $s0, 0x1C
    ctx->r6 = ADD32(ctx->r16, 0X1C);
    after_4:
    { static int n=0; if (++n<=3) { if(0) fprintf(stderr, "[trace] func_800C58A0 returned from func_80001354 @0x800C5A20\n"); fflush(stderr); } }
    // 0x800C5A20: jal         0x8003DF20
    // 0x800C5A24: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8003DF20(rdram, ctx);
        goto after_5;
    // 0x800C5A24: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x800C5A28: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    { static int n=0; if (++n<=3) { if(0) fprintf(stderr, "[trace] func_800C58A0 returned from func_8003DF20 @0x800C5A2C\n"); fflush(stderr); } }
    // 0x800C5A2C: jal         0x800047F4
    // 0x800C5A30: addiu       $a0, $a0, 0x7560
    ctx->r4 = ADD32(ctx->r4, 0X7560);
    func_800047F4(rdram, ctx);
        goto after_6;
    // 0x800C5A30: addiu       $a0, $a0, 0x7560
    ctx->r4 = ADD32(ctx->r4, 0X7560);
    after_6:
    // 0x800C5A34: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    { static int n=0; if (++n<=3) { if(0) fprintf(stderr, "[trace] func_800C58A0 returned from func_800047F4 @0x800C5A38\n"); fflush(stderr); } }
    // 0x800C5A38: jal         0x800663B0
    // 0x800C5A3C: sw          $v0, 0x7CFC($v1)
    MEM_W(0X7CFC, ctx->r3) = ctx->r2;
    func_800663B0(rdram, ctx);
        goto after_7;
    // 0x800C5A3C: sw          $v0, 0x7CFC($v1)
    MEM_W(0X7CFC, ctx->r3) = ctx->r2;
    after_7:
    // 0x800C5A40: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    { static int n=0; if (++n<=3) { if(0) fprintf(stderr, "[trace] func_800C58A0 returned from func_800663B0 @0x800C5A44\n"); fflush(stderr); } }
    // 0x800C5A44: jal         0x80055880
    // 0x800C5A48: addiu       $a0, $a0, 0x7568
    ctx->r4 = ADD32(ctx->r4, 0X7568);
    loadGameOrFrontTxtFile(rdram, ctx);
        goto after_8;
    // 0x800C5A48: addiu       $a0, $a0, 0x7568
    ctx->r4 = ADD32(ctx->r4, 0X7568);
    after_8:
    { static int n=0; if (++n<=3) { if(0) fprintf(stderr, "[trace] func_800C58A0 returned from loadGameOrFrontTxtFile @0x800C5A4C\n"); fflush(stderr); } }
    // 0x800C5A4C: jal         0x8006EF98
    // 0x800C5A50: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_8006EF98(rdram, ctx);
        goto after_9;
    // 0x800C5A50: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_9:
    { static int n=0; if (++n<=3) { if(0) fprintf(stderr, "[trace] func_800C58A0 returned from func_8006EF98 @0x800C5A54\n"); fflush(stderr); } }
    // 0x800C5A54: jal         0x800B4020
    // 0x800C5A58: nop

    func_800B4020(rdram, ctx);
        goto after_10;
    // 0x800C5A58: nop

    after_10:
    { static int n=0; if (++n<=3) { if(0) fprintf(stderr, "[trace] func_800C58A0 returned from func_800B4020 @0x800C5A5C\n"); fflush(stderr); } }
    // 0x800C5A5C: lhu         $v1, -0xB0($s1)
    ctx->r3 = MEM_HU(ctx->r17, -0XB0);
    { static int n=0; if (++n<=10) { if(0) fprintf(stderr, "[trace] func_800C58A0 dispatch #%d state=%u (s1=0x%08X)\n", n, (unsigned)(ctx->r3 & 0xFFFFu), (uint32_t)ctx->r17); fflush(stderr); } }
    // 0x800C5A60: sltiu       $v0, $v1, 0xB
    ctx->r2 = ctx->r3 < 0XB ? 1 : 0;
    // 0x800C5A64: beq         $v0, $zero, L_800C5CEC
    if (ctx->r2 == 0) {
        // 0x800C5A68: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_800C5CEC;
    }
    // 0x800C5A68: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C5A6C: addiu       $v0, $v0, 0x75C0
    ctx->r2 = ADD32(ctx->r2, 0X75C0);
    // 0x800C5A70: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C5A74: addu        $v1, $v1, $v0
    gpr jr_addend_800C5A7C = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C5A78: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800C5A7C: jr          $v0
    // 0x800C5A80: nop

    { static int n=0; if (++n<=10) { if(0) fprintf(stderr, "[trace] func_800C58A0 switch #%d case=%u\n", n, (unsigned)(jr_addend_800C5A7C >> 2)); fflush(stderr); } }
    switch (jr_addend_800C5A7C >> 2) {
        case 0: goto L_800C5A84; break;
        case 1: goto L_800C5ACC; break;
        case 2: goto L_800C5B40; break;
        case 3: goto L_800C5C44; break;
        case 4: goto L_800C5B04; break;
        case 5: goto L_800C5B24; break;
        case 6: goto L_800C5C24; break;
        case 7: goto L_800C5CA8; break;
        case 8: goto L_800C5C64; break;
        case 9: goto L_800C5C98; break;
        case 10: goto L_800C5CC0; break;
        default: switch_error(__func__, 0x800C5A7C, 0x800A75C0);
    }
    // 0x800C5A80: nop

L_800C5A84:
    // 0x800C5A84: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800C5A88: lbu         $a2, 0x0($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0X0);
    // 0x800C5A8C: jal         0x800C6854
    // 0x800C5A90: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_800C6854(rdram, ctx);
        goto after_11;
    // 0x800C5A90: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_11:
    // 0x800C5A94: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C5A98: bne         $v0, $zero, L_800C5AA8
    if (ctx->r2 != 0) {
        // 0x800C5A9C: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_800C5AA8;
    }
    // 0x800C5A9C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C5AA0: j           L_800C5CEC
    // 0x800C5AA4: sh          $t0, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r8;
        goto L_800C5CEC;
    // 0x800C5AA4: sh          $t0, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r8;
L_800C5AA8:
    // 0x800C5AA8: lbu         $a0, 0x0($s3)
    ctx->r4 = MEM_BU(ctx->r19, 0X0);
    // 0x800C5AAC: jal         0x800C6900
    // 0x800C5AB0: nop

    getLevelIntroCrawlId(rdram, ctx);
        goto after_12;
    // 0x800C5AB0: nop

    after_12:
    // 0x800C5AB4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C5AB8: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x800C5ABC: beq         $v0, $v1, L_800C5C3C
    if (ctx->r2 == ctx->r3) {
        // 0x800C5AC0: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_800C5C3C;
    }
    // 0x800C5AC0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800C5AC4: j           L_800C5CEC
    // 0x800C5AC8: sh          $v0, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r2;
        goto L_800C5CEC;
    // 0x800C5AC8: sh          $v0, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r2;
L_800C5ACC:
    // 0x800C5ACC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800C5AD0: jal         0x800C5D9C
    // 0x800C5AD4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_800C5D9C(rdram, ctx);
        goto after_13;
    // 0x800C5AD4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_13:
    // 0x800C5AD8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C5ADC: bne         $v0, $zero, L_800C5AEC
    if (ctx->r2 != 0) {
        // 0x800C5AE0: addiu       $v0, $zero, 0x10
        ctx->r2 = ADD32(0, 0X10);
            goto L_800C5AEC;
    }
    // 0x800C5AE0: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x800C5AE4: j           L_800C5CEC
    // 0x800C5AE8: sh          $s7, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r23;
        goto L_800C5CEC;
    // 0x800C5AE8: sh          $s7, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r23;
L_800C5AEC:
    // 0x800C5AEC: lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X0);
    // 0x800C5AF0: bnel        $v1, $v0, L_800C5CEC
    if (ctx->r3 != ctx->r2) {
        // 0x800C5AF4: sh          $zero, -0xB0($s1)
        MEM_H(-0XB0, ctx->r17) = 0;
            goto L_800C5CEC;
    }
    goto skip_1;
    // 0x800C5AF4: sh          $zero, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = 0;
    skip_1:
    // 0x800C5AF8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800C5AFC: j           L_800C5AA8
    // 0x800C5B00: sb          $v0, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r2;
        goto L_800C5AA8;
    // 0x800C5B00: sb          $v0, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r2;
L_800C5B04:
    // 0x800C5B04: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800C5B08: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800C5B0C: jal         0x800C5EF8
    // 0x800C5B10: addiu       $a1, $a1, 0x7574
    ctx->r5 = ADD32(ctx->r5, 0X7574);
    func_800C5EF8(rdram, ctx);
        goto after_14;
    // 0x800C5B10: addiu       $a1, $a1, 0x7574
    ctx->r5 = ADD32(ctx->r5, 0X7574);
    after_14:
    // 0x800C5B14: sb          $v0, 0x2($s3)
    MEM_B(0X2, ctx->r19) = ctx->r2;
    // 0x800C5B18: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800C5B1C: j           L_800C5CEC
    // 0x800C5B20: sh          $v0, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r2;
        goto L_800C5CEC;
    // 0x800C5B20: sh          $v0, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r2;
L_800C5B24:
    // 0x800C5B24: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800C5B28: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800C5B2C: jal         0x800C5EF8
    // 0x800C5B30: addiu       $a1, $a1, 0x7588
    ctx->r5 = ADD32(ctx->r5, 0X7588);
    func_800C5EF8(rdram, ctx);
        goto after_15;
    // 0x800C5B30: addiu       $a1, $a1, 0x7588
    ctx->r5 = ADD32(ctx->r5, 0X7588);
    after_15:
    // 0x800C5B34: sb          $v0, 0x5($s3)
    MEM_B(0X5, ctx->r19) = ctx->r2;
    // 0x800C5B38: j           L_800C5CEC
    // 0x800C5B3C: sh          $zero, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = 0;
        goto L_800C5CEC;
    // 0x800C5B3C: sh          $zero, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = 0;
L_800C5B40:
    // 0x800C5B40: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800C5B44: jal         0x800B47D0
    // 0x800C5B48: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    func_800B47D0(rdram, ctx);
        goto after_16;
    // 0x800C5B48: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    after_16:
    // 0x800C5B4C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x800C5B50: bne         $s4, $v0, L_800C5B60
    if (ctx->r20 != ctx->r2) {
        // 0x800C5B54: sb          $zero, 0x24($s2)
        MEM_B(0X24, ctx->r18) = 0;
            goto L_800C5B60;
    }
    // 0x800C5B54: sb          $zero, 0x24($s2)
    MEM_B(0X24, ctx->r18) = 0;
    // 0x800C5B58: j           L_800C5C1C
    // 0x800C5B5C: sh          $s6, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r22;
        goto L_800C5C1C;
    // 0x800C5B5C: sh          $s6, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r22;
L_800C5B60:
    // 0x800C5B60: lw          $v1, 0x10($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X10);
    // 0x800C5B64: andi        $v0, $v1, 0x20
    ctx->r2 = ctx->r3 & 0X20;
    // 0x800C5B68: beq         $v0, $zero, L_800C5BB4
    if (ctx->r2 == 0) {
        // 0x800C5B6C: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800C5BB4;
    }
    // 0x800C5B6C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800C5B70: addiu       $v0, $v0, -0x2BFC
    ctx->r2 = ADD32(ctx->r2, -0X2BFC);
    // 0x800C5B74: lbu         $v1, 0x14($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X14);
    // 0x800C5B78: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800C5B7C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C5B80: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800C5B84: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800C5B88: addiu       $v1, $v1, -0x13B0
    ctx->r3 = ADD32(ctx->r3, -0X13B0);
    // 0x800C5B8C: sb          $v0, 0xB40($t0)
    MEM_B(0XB40, ctx->r8) = ctx->r2;
    // 0x800C5B90: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C5B94: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C5B98: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C5B9C: lbu         $v0, 0x3($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X3);
    // 0x800C5BA0: sb          $zero, 0x2($s2)
    MEM_B(0X2, ctx->r18) = 0;
    // 0x800C5BA4: sb          $zero, 0x20($s5)
    MEM_B(0X20, ctx->r21) = 0;
    // 0x800C5BA8: sh          $s6, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r22;
    // 0x800C5BAC: j           L_800C5C1C
    // 0x800C5BB0: sb          $v0, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r2;
        goto L_800C5C1C;
    // 0x800C5BB0: sb          $v0, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r2;
L_800C5BB4:
    // 0x800C5BB4: andi        $v0, $v1, 0x200
    ctx->r2 = ctx->r3 & 0X200;
    // 0x800C5BB8: beq         $v0, $zero, L_800C5BD0
    if (ctx->r2 == 0) {
        // 0x800C5BBC: addiu       $v0, $zero, -0x201
        ctx->r2 = ADD32(0, -0X201);
            goto L_800C5BD0;
    }
    // 0x800C5BBC: addiu       $v0, $zero, -0x201
    ctx->r2 = ADD32(0, -0X201);
    // 0x800C5BC0: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x800C5BC4: sw          $v0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r2;
    // 0x800C5BC8: j           L_800C5BE4
    // 0x800C5BCC: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_800C5BE4;
    // 0x800C5BCC: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_800C5BD0:
    // 0x800C5BD0: lw          $v1, 0x18($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X18);
    // 0x800C5BD4: lui         $v0, 0x20
    ctx->r2 = S32(0X20 << 16);
    // 0x800C5BD8: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x800C5BDC: beq         $v0, $zero, L_800C5BF0
    if (ctx->r2 == 0) {
        // 0x800C5BE0: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_800C5BF0;
    }
    // 0x800C5BE0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_800C5BE4:
    // 0x800C5BE4: sb          $zero, 0x20($s5)
    MEM_B(0X20, ctx->r21) = 0;
    // 0x800C5BE8: j           L_800C5C1C
    // 0x800C5BEC: sh          $v0, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r2;
        goto L_800C5C1C;
    // 0x800C5BEC: sh          $v0, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r2;
L_800C5BF0:
    // 0x800C5BF0: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x800C5BF4: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x800C5BF8: beq         $v0, $zero, L_800C5C0C
    if (ctx->r2 == 0) {
        // 0x800C5BFC: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_800C5C0C;
    }
    // 0x800C5BFC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C5C00: sb          $zero, 0x20($s5)
    MEM_B(0X20, ctx->r21) = 0;
    // 0x800C5C04: j           L_800C5C1C
    // 0x800C5C08: sh          $s6, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r22;
        goto L_800C5C1C;
    // 0x800C5C08: sh          $s6, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r22;
L_800C5C0C:
    // 0x800C5C0C: sb          $zero, 0x20($s5)
    MEM_B(0X20, ctx->r21) = 0;
    // 0x800C5C10: sb          $zero, 0x22($s5)
    MEM_B(0X22, ctx->r21) = 0;
    // 0x800C5C14: sb          $zero, 0x23($s5)
    MEM_B(0X23, ctx->r21) = 0;
    // 0x800C5C18: sh          $t0, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r8;
L_800C5C1C:
    // 0x800C5C1C: j           L_800C5CEC
    // 0x800C5C20: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
        goto L_800C5CEC;
    // 0x800C5C20: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
L_800C5C24:
    // 0x800C5C24: lbu         $a0, 0x0($s3)
    ctx->r4 = MEM_BU(ctx->r19, 0X0);
    // 0x800C5C28: jal         0x800C6900
    // 0x800C5C2C: nop

    getLevelIntroCrawlId(rdram, ctx);
        goto after_17;
    // 0x800C5C2C: nop

    after_17:
    // 0x800C5C30: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800C5C34: jal         0x800C9BF0
    // 0x800C5C38: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    func_800C9BF0(rdram, ctx);
        goto after_18;
    // 0x800C5C38: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_18:
L_800C5C3C:
    // 0x800C5C3C: j           L_800C5CEC
    // 0x800C5C40: sh          $fp, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r30;
        goto L_800C5CEC;
    // 0x800C5C40: sh          $fp, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r30;
L_800C5C44:
    // 0x800C5C44: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800C5C48: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C5C4C: addiu       $a1, $a1, 0xB78
    ctx->r5 = ADD32(ctx->r5, 0XB78);
    // 0x800C5C50: lbu         $a2, 0x0($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0X0);
    // 0x800C5C54: jal         0x800BF830
    // 0x800C5C58: andi        $a3, $s4, 0xFF
    ctx->r7 = ctx->r20 & 0XFF;
    func_800BF830(rdram, ctx);
        goto after_19;
    // 0x800C5C58: andi        $a3, $s4, 0xFF
    ctx->r7 = ctx->r20 & 0XFF;
    after_19:
    // 0x800C5C5C: j           L_800C5CEC
    // 0x800C5C60: sh          $s6, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r22;
        goto L_800C5CEC;
    // 0x800C5C60: sh          $s6, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r22;
L_800C5C64:
    // 0x800C5C64: jal         0x800C131C
    // 0x800C5C68: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_800C131C(rdram, ctx);
        goto after_20;
    // 0x800C5C68: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_20:
    // 0x800C5C6C: lw          $v1, 0x18($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X18);
    // 0x800C5C70: lui         $v0, 0x20
    ctx->r2 = S32(0X20 << 16);
    // 0x800C5C74: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x800C5C78: beq         $v0, $zero, L_800C5CEC
    if (ctx->r2 == 0) {
        // 0x800C5C7C: sh          $s6, -0xB0($s1)
        MEM_H(-0XB0, ctx->r17) = ctx->r22;
            goto L_800C5CEC;
    }
    // 0x800C5C7C: sh          $s6, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r22;
    // 0x800C5C80: lui         $v0, 0xFFDF
    ctx->r2 = S32(0XFFDF << 16);
    // 0x800C5C84: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x800C5C88: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x800C5C8C: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    // 0x800C5C90: j           L_800C5CEC
    // 0x800C5C94: sh          $s7, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r23;
        goto L_800C5CEC;
    // 0x800C5C94: sh          $s7, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r23;
L_800C5C98:
    { static int n=0; if (++n<=5) { if(0) fprintf(stderr, "[trace] L_800C5C98 case9 #%d before func_800C28F0\n", n); fflush(stderr); } }
    // 0x800C5C98: jal         0x800C28F0
    // 0x800C5C9C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_800C28F0(rdram, ctx);
        goto after_21;
    // 0x800C5C9C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_21:
    // 0x800C5CA0: j           L_800C5CEC
    // 0x800C5CA4: sh          $s6, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r22;
        goto L_800C5CEC;
    // 0x800C5CA4: sh          $s6, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r22;
L_800C5CA8:
    // 0x800C5CA8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800C5CAC: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800C5CB0: jal         0x800C5EF8
    // 0x800C5CB4: addiu       $a1, $a1, 0x75A4
    ctx->r5 = ADD32(ctx->r5, 0X75A4);
    func_800C5EF8(rdram, ctx);
        goto after_22;
    // 0x800C5CB4: addiu       $a1, $a1, 0x75A4
    ctx->r5 = ADD32(ctx->r5, 0X75A4);
    after_22:
    // 0x800C5CB8: j           L_800C5C3C
    // 0x800C5CBC: sb          $v0, 0x2D($s3)
    MEM_B(0X2D, ctx->r19) = ctx->r2;
        goto L_800C5C3C;
    // 0x800C5CBC: sb          $v0, 0x2D($s3)
    MEM_B(0X2D, ctx->r19) = ctx->r2;
L_800C5CC0:
    // 0x800C5CC0: jal         0x800C30C8
    // 0x800C5CC4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_800C30C8(rdram, ctx);
        goto after_23;
    // 0x800C5CC4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_23:
    // 0x800C5CC8: lw          $v1, 0x18($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X18);
    // 0x800C5CCC: lw          $a0, 0x10($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X10);
    // 0x800C5CD0: addiu       $v0, $zero, -0x21
    ctx->r2 = ADD32(0, -0X21);
    // 0x800C5CD4: sh          $s7, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r23;
    // 0x800C5CD8: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x800C5CDC: andi        $a0, $a0, 0x400
    ctx->r4 = ctx->r4 & 0X400;
    // 0x800C5CE0: beq         $a0, $zero, L_800C5CEC
    if (ctx->r4 == 0) {
        // 0x800C5CE4: sw          $v1, 0x18($s2)
        MEM_W(0X18, ctx->r18) = ctx->r3;
            goto L_800C5CEC;
    }
    // 0x800C5CE4: sw          $v1, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r3;
    // 0x800C5CE8: sh          $s6, -0xB0($s1)
    MEM_H(-0XB0, ctx->r17) = ctx->r22;
L_800C5CEC:
    { static int n=0; if (++n<=5) { if(0) fprintf(stderr, "[trace] L_800C5CEC #%d before func_8000BF60\n", n); fflush(stderr); } }
    // 0x800C5CEC: jal         0x8000BF60
    // 0x800C5CF0: nop

    func_8000BF60(rdram, ctx);
        goto after_24;
    // 0x800C5CF0: nop

    after_24:
    { static int n=0; if (++n<=5) { if(0) fprintf(stderr, "[trace] L_800C5CEC #%d after func_8000BF60, before func_800668B0\n", n); fflush(stderr); } }
    // 0x800C5CF4: jal         0x800668B0
    // 0x800C5CF8: nop

    func_800668B0(rdram, ctx);
        goto after_25;
    // 0x800C5CF8: nop

    after_25:
    { static int n=0; if (++n<=5) { if(0) fprintf(stderr, "[trace] L_800C5CEC #%d after func_800668B0, before freeTxtFile\n", n); fflush(stderr); } }
    // 0x800C5CFC: jal         0x800558D4
    // 0x800C5D00: nop

    freeTxtFile(rdram, ctx);
        goto after_26;
    // 0x800C5D00: nop

    after_26:
    { static int n=0; if (++n<=5) { if(0) fprintf(stderr, "[trace] L_800C5CEC #%d after freeTxtFile, before func_80004994\n", n); fflush(stderr); } }
    // 0x800C5D04: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C5D08: lw          $a0, 0x7CFC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X7CFC);
    // 0x800C5D0C: jal         0x80004994
    // 0x800C5D10: nop

    func_80004994(rdram, ctx);
        goto after_27;
    // 0x800C5D10: nop

    after_27:
    { static int n=0; if (++n<=5) { if(0) fprintf(stderr, "[trace] L_800C5CEC #%d after func_80004994, before func_8006EFDC\n", n); fflush(stderr); } }
    // 0x800C5D14: jal         0x8006EFDC
    // 0x800C5D18: nop

    func_8006EFDC(rdram, ctx);
        goto after_28;
    // 0x800C5D18: nop

    after_28:
    { static int n=0; if (++n<=5) { if(0) fprintf(stderr, "[trace] L_800C5CEC #%d after func_8006EFDC, before func_8003DF78\n", n); fflush(stderr); } }
    // 0x800C5D1C: jal         0x8003DF78
    // 0x800C5D20: nop

    func_8003DF78(rdram, ctx);
        goto after_29;
    // 0x800C5D20: nop

    after_29:
    { static int n=0; if (++n<=5) { if(0) fprintf(stderr, "[trace] L_800C5CEC #%d after func_8003DF78\n", n); fflush(stderr); } }
    // 0x800C5D24: lhu         $v0, -0xB0($s1)
    ctx->r2 = MEM_HU(ctx->r17, -0XB0);
    // 0x800C5D28: addiu       $v0, $v0, -0xB
    ctx->r2 = ADD32(ctx->r2, -0XB);
    // 0x800C5D2C: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800C5D30: beq         $v0, $zero, L_800C5928
    if (ctx->r2 == 0) {
        // 0x800C5D34: nop
    
            goto L_800C5928;
    }
    // 0x800C5D34: nop

    // 0x800C5D38: lbu         $a0, 0x0($s3)
    ctx->r4 = MEM_BU(ctx->r19, 0X0);
    // 0x800C5D3C: lbu         $a1, 0x1($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X1);
    // 0x800C5D40: jal         0x800C6728
    // 0x800C5D44: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    getSecondaryWeaponForLevelAndCraft(rdram, ctx);
        goto after_30;
    // 0x800C5D44: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_30:
    // 0x800C5D48: lui         $a0, 0x8003
    ctx->r4 = S32(0X8003 << 16);
    // 0x800C5D4C: addiu       $a0, $a0, 0x7560
    ctx->r4 = ADD32(ctx->r4, 0X7560);
    // 0x800C5D50: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800C5D54: addiu       $a1, $a1, -0xA0
    ctx->r5 = ADD32(ctx->r5, -0XA0);
    // 0x800C5D58: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    { static int n=0; if (++n<=3) { if(0) fprintf(stderr, "[trace] func_800C58A0 reached 0x800C5D5C (final zmemcpy)\n"); fflush(stderr); } }
    // 0x800C5D5C: jal         0x80018EF4
    // 0x800C5D60: sb          $v0, 0x3($s3)
    MEM_B(0X3, ctx->r19) = ctx->r2;
    zmemcpy(rdram, ctx);
        goto after_31;
    // 0x800C5D60: sb          $v0, 0x3($s3)
    MEM_B(0X3, ctx->r19) = ctx->r2;
    after_31:
    // 0x800C5D64: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800C5D68: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x800C5D6C: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x800C5D70: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x800C5D74: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800C5D78: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800C5D7C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800C5D80: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800C5D84: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C5D88: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C5D8C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C5D90: sb          $zero, 0xB3A($v0)
    MEM_B(0XB3A, ctx->r2) = 0;
    // 0x800C5D94: jr          $ra
    // 0x800C5D98: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    { if(0) fprintf(stderr, "[trace] menu_overlay_init func_800C58A0 EXIT\n"); fflush(stderr); }
    return;
    // 0x800C5D98: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800C5918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5918: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800C591C: sdc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X48, ctx->r29);
    // 0x800C5920: mtc1        $a2, $f26
    ctx->f26.u32l = ctx->r6;
    // 0x800C5924: sdc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X50, ctx->r29);
    // 0x800C5928: mtc1        $a3, $f28
    ctx->f28.u32l = ctx->r7;
    // 0x800C592C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C5930: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800C5934: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C5938: addiu       $s3, $s2, 0xAF4
    ctx->r19 = ADD32(ctx->r18, 0XAF4);
    // 0x800C593C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C5940: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800C5944: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C5948: sdc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X58, ctx->r29);
    // 0x800C594C: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x800C5950: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x800C5954: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800C5958: lwc1        $f0, 0xDC4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XDC4);
    // 0x800C595C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800C5960: lw          $s0, 0x900($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X900);
    // 0x800C5964: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x800C5968: nop

    // 0x800C596C: bc1f        L_800C5F4C
    if (!c1cs) {
        // 0x800C5970: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_800C5F4C;
    }
    // 0x800C5970: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800C5974: lwc1        $f0, 0xDCC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XDCC);
    // 0x800C5978: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C597C: lwc1        $f20, 0x67F8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X67F8);
    // 0x800C5980: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800C5984: nop

    // 0x800C5988: bc1f        L_800C5B38
    if (!c1cs) {
        // 0x800C598C: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_800C5B38;
    }
    // 0x800C598C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800C5990: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5994: lwc1        $f12, 0x67FC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X67FC);
    // 0x800C5998: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800C599C: add.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x800C59A0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C59A4: lwc1        $f0, 0x6800($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6800);
    // 0x800C59A8: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800C59AC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C59B0: lwc1        $f0, 0x6804($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6804);
    // 0x800C59B4: jal         0x80033960
    // 0x800C59B8: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
    sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x800C59B8: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
    after_0:
    // 0x800C59BC: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x800C59C0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C59C4: lwc1        $f2, 0x6808($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6808);
    // 0x800C59C8: mul.s       $f24, $f0, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C59CC: nop

    // 0x800C59D0: mul.s       $f2, $f24, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f22.fl);
    // 0x800C59D4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C59D8: lwc1        $f0, 0x680C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X680C);
    // 0x800C59DC: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C59E0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C59E4: lwc1        $f2, 0x6810($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6810);
    // 0x800C59E8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800C59EC: nop

    // 0x800C59F0: bc1tl       L_800C5A08
    if (c1cs) {
        // 0x800C59F4: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800C5A08;
    }
    goto skip_0;
    // 0x800C59F4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_0:
    // 0x800C59F8: trunc.w.s   $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C59FC: mfc1        $v1, $f30
    ctx->r3 = (int32_t)ctx->f30.u32l;
    // 0x800C5A00: j           L_800C5A18
    // 0x800C5A04: nop

        goto L_800C5A18;
    // 0x800C5A04: nop

L_800C5A08:
    // 0x800C5A08: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800C5A0C: trunc.w.s   $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5A10: mfc1        $v1, $f30
    ctx->r3 = (int32_t)ctx->f30.u32l;
    // 0x800C5A14: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_800C5A18:
    // 0x800C5A18: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5A1C: lwc1        $f0, 0x6814($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6814);
    // 0x800C5A20: mul.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800C5A24: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5A28: lwc1        $f2, 0x6818($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6818);
    // 0x800C5A2C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5A30: lwc1        $f4, 0x681C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X681C);
    // 0x800C5A34: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800C5A38: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x800C5A3C: nop

    // 0x800C5A40: bc1t        L_800C5A58
    if (c1cs) {
        // 0x800C5A44: sb          $v1, 0x10($sp)
        MEM_B(0X10, ctx->r29) = ctx->r3;
            goto L_800C5A58;
    }
    // 0x800C5A44: sb          $v1, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r3;
    // 0x800C5A48: trunc.w.s   $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5A4C: mfc1        $v1, $f30
    ctx->r3 = (int32_t)ctx->f30.u32l;
    // 0x800C5A50: j           L_800C5A6C
    // 0x800C5A54: nop

        goto L_800C5A6C;
    // 0x800C5A54: nop

L_800C5A58:
    // 0x800C5A58: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800C5A5C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800C5A60: trunc.w.s   $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5A64: mfc1        $v1, $f30
    ctx->r3 = (int32_t)ctx->f30.u32l;
    // 0x800C5A68: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_800C5A6C:
    // 0x800C5A6C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5A70: lwc1        $f0, 0x6820($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6820);
    // 0x800C5A74: mul.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800C5A78: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5A7C: lwc1        $f2, 0x6824($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6824);
    // 0x800C5A80: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5A84: lwc1        $f4, 0x6828($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6828);
    // 0x800C5A88: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800C5A8C: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x800C5A90: nop

    // 0x800C5A94: bc1t        L_800C5AAC
    if (c1cs) {
        // 0x800C5A98: sb          $v1, 0x11($sp)
        MEM_B(0X11, ctx->r29) = ctx->r3;
            goto L_800C5AAC;
    }
    // 0x800C5A98: sb          $v1, 0x11($sp)
    MEM_B(0X11, ctx->r29) = ctx->r3;
    // 0x800C5A9C: trunc.w.s   $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5AA0: mfc1        $v1, $f30
    ctx->r3 = (int32_t)ctx->f30.u32l;
    // 0x800C5AA4: j           L_800C5AC4
    // 0x800C5AA8: sb          $v1, 0x12($sp)
    MEM_B(0X12, ctx->r29) = ctx->r3;
        goto L_800C5AC4;
    // 0x800C5AA8: sb          $v1, 0x12($sp)
    MEM_B(0X12, ctx->r29) = ctx->r3;
L_800C5AAC:
    // 0x800C5AAC: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800C5AB0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800C5AB4: trunc.w.s   $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5AB8: mfc1        $v1, $f30
    ctx->r3 = (int32_t)ctx->f30.u32l;
    // 0x800C5ABC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800C5AC0: sb          $v1, 0x12($sp)
    MEM_B(0X12, ctx->r29) = ctx->r3;
L_800C5AC4:
    // 0x800C5AC4: lwc1        $f0, 0xDCC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XDCC);
    // 0x800C5AC8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5ACC: lwc1        $f2, 0x682C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X682C);
    // 0x800C5AD0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5AD4: lwc1        $f4, 0x6830($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6830);
    // 0x800C5AD8: div.s       $f24, $f0, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C5ADC: c.lt.s      $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f24.fl < ctx->f4.fl;
    // 0x800C5AE0: nop

    // 0x800C5AE4: bc1f        L_800C5B4C
    if (!c1cs) {
        // 0x800C5AE8: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_800C5B4C;
    }
    // 0x800C5AE8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800C5AEC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5AF0: lwc1        $f0, 0x6834($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6834);
    // 0x800C5AF4: mul.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800C5AF8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5AFC: lwc1        $f2, 0x6838($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6838);
    // 0x800C5B00: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800C5B04: nop

    // 0x800C5B08: bc1tl       L_800C5B20
    if (c1cs) {
        // 0x800C5B0C: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800C5B20;
    }
    goto skip_1;
    // 0x800C5B0C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_1:
    // 0x800C5B10: trunc.w.s   $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5B14: mfc1        $v1, $f30
    ctx->r3 = (int32_t)ctx->f30.u32l;
    // 0x800C5B18: j           L_800C5B50
    // 0x800C5B1C: sb          $v1, 0x13($sp)
    MEM_B(0X13, ctx->r29) = ctx->r3;
        goto L_800C5B50;
    // 0x800C5B1C: sb          $v1, 0x13($sp)
    MEM_B(0X13, ctx->r29) = ctx->r3;
L_800C5B20:
    // 0x800C5B20: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800C5B24: trunc.w.s   $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5B28: mfc1        $v1, $f30
    ctx->r3 = (int32_t)ctx->f30.u32l;
    // 0x800C5B2C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800C5B30: j           L_800C5B50
    // 0x800C5B34: sb          $v1, 0x13($sp)
    MEM_B(0X13, ctx->r29) = ctx->r3;
        goto L_800C5B50;
    // 0x800C5B34: sb          $v1, 0x13($sp)
    MEM_B(0X13, ctx->r29) = ctx->r3;
L_800C5B38:
    // 0x800C5B38: addiu       $v1, $zero, 0x8F
    ctx->r3 = ADD32(0, 0X8F);
    // 0x800C5B3C: sb          $v1, 0x11($sp)
    MEM_B(0X11, ctx->r29) = ctx->r3;
    // 0x800C5B40: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // 0x800C5B44: sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
    // 0x800C5B48: sb          $v1, 0x12($sp)
    MEM_B(0X12, ctx->r29) = ctx->r3;
L_800C5B4C:
    // 0x800C5B4C: sb          $v0, 0x13($sp)
    MEM_B(0X13, ctx->r29) = ctx->r2;
L_800C5B50:
    // 0x800C5B50: lbu         $v0, 0x13($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X13);
    // 0x800C5B54: lwc1        $f2, 0xDC4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0XDC4);
    // 0x800C5B58: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C5B5C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C5B60: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C5B64: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5B68: lwc1        $f2, 0x683C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X683C);
    // 0x800C5B6C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800C5B70: nop

    // 0x800C5B74: bc1tl       L_800C5B8C
    if (c1cs) {
        // 0x800C5B78: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800C5B8C;
    }
    goto skip_2;
    // 0x800C5B78: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_2:
    // 0x800C5B7C: trunc.w.s   $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5B80: mfc1        $v1, $f30
    ctx->r3 = (int32_t)ctx->f30.u32l;
    // 0x800C5B84: j           L_800C5B9C
    // 0x800C5B88: nop

        goto L_800C5B9C;
    // 0x800C5B88: nop

L_800C5B8C:
    // 0x800C5B8C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800C5B90: trunc.w.s   $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5B94: mfc1        $v1, $f30
    ctx->r3 = (int32_t)ctx->f30.u32l;
    // 0x800C5B98: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_800C5B9C:
    // 0x800C5B9C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800C5BA0: c.lt.s      $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f0.fl < ctx->f28.fl;
    // 0x800C5BA4: nop

    // 0x800C5BA8: bc1f        L_800C5BC0
    if (!c1cs) {
        // 0x800C5BAC: sb          $v1, 0x13($sp)
        MEM_B(0X13, ctx->r29) = ctx->r3;
            goto L_800C5BC0;
    }
    // 0x800C5BAC: sb          $v1, 0x13($sp)
    MEM_B(0X13, ctx->r29) = ctx->r3;
    // 0x800C5BB0: jal         0x8001C400
    // 0x800C5BB4: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    func_8001C400(rdram, ctx);
        goto after_1;
    // 0x800C5BB4: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    after_1:
    // 0x800C5BB8: j           L_800C5BD4
    // 0x800C5BBC: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
        goto L_800C5BD4;
    // 0x800C5BBC: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
L_800C5BC0:
    // 0x800C5BC0: jal         0x8001C400
    // 0x800C5BC4: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    func_8001C400(rdram, ctx);
        goto after_2;
    // 0x800C5BC4: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    after_2:
    // 0x800C5BC8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5BCC: lwc1        $f2, 0x6840($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6840);
    // 0x800C5BD0: sub.s       $f24, $f2, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = ctx->f2.fl - ctx->f0.fl;
L_800C5BD4:
    // 0x800C5BD4: lwc1        $f12, 0xDBC($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0XDBC);
    // 0x800C5BD8: lwc1        $f0, 0xDC0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XDC0);
    // 0x800C5BDC: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800C5BE0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5BE4: lwc1        $f22, 0x6844($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X6844);
    // 0x800C5BE8: mul.s       $f12, $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f22.fl);
    // 0x800C5BEC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5BF0: lwc1        $f20, 0x6848($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X6848);
    // 0x800C5BF4: add.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f20.fl;
    // 0x800C5BF8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5BFC: lwc1        $f26, 0x684C($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X684C);
    // 0x800C5C00: sub.s       $f12, $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f24.fl;
    // 0x800C5C04: jal         0x8001E20C
    // 0x800C5C08: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    func_8001E20C(rdram, ctx);
        goto after_3;
    // 0x800C5C08: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    after_3:
    // 0x800C5C0C: lwc1        $f12, 0xDBC($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0XDBC);
    // 0x800C5C10: lwc1        $f2, 0xDC0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0XDC0);
    // 0x800C5C14: add.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x800C5C18: mul.s       $f12, $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f22.fl);
    // 0x800C5C1C: add.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f20.fl;
    // 0x800C5C20: sub.s       $f12, $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f24.fl;
    // 0x800C5C24: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    // 0x800C5C28: jal         0x8001E20C
    // 0x800C5C2C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_8001E20C(rdram, ctx);
        goto after_4;
    // 0x800C5C2C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_4:
    // 0x800C5C30: mov.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.fl = ctx->f0.fl;
    // 0x800C5C34: c.lt.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl < ctx->f20.fl;
    // 0x800C5C38: nop

    // 0x800C5C3C: bc1tl       L_800C5C44
    if (c1cs) {
        // 0x800C5C40: add.s       $f6, $f6, $f26
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f26.fl;
            goto L_800C5C44;
    }
    goto skip_3;
    // 0x800C5C40: add.s       $f6, $f6, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f26.fl;
    skip_3:
L_800C5C44:
    // 0x800C5C44: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5C48: lwc1        $f0, 0x6850($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6850);
    // 0x800C5C4C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C5C50: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800C5C54: div.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800C5C58: c.lt.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl < ctx->f6.fl;
    // 0x800C5C5C: nop

    // 0x800C5C60: bc1f        L_800C5F4C
    if (!c1cs) {
        // 0x800C5C64: sub.s       $f10, $f6, $f20
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f20.fl;
            goto L_800C5F4C;
    }
    // 0x800C5C64: sub.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f20.fl;
    // 0x800C5C68: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x800C5C6C: addiu       $t0, $s3, 0x20
    ctx->r8 = ADD32(ctx->r19, 0X20);
    // 0x800C5C70: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5C74: lwc1        $f14, 0x6854($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X6854);
    // 0x800C5C78: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5C7C: lwc1        $f18, 0x6858($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6858);
    // 0x800C5C80: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5C84: lwc1        $f12, 0x685C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X685C);
    // 0x800C5C88: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C5C8C: lwc1        $f16, 0x6860($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6860);
    // 0x800C5C90: add.s       $f0, $f20, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f14.fl;
L_800C5C94:
    // 0x800C5C94: mov.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
    // 0x800C5C98: trunc.w.s   $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5C9C: mfc1        $v1, $f30
    ctx->r3 = (int32_t)ctx->f30.u32l;
    // 0x800C5CA0: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x800C5CA4: trunc.w.s   $f30, $f4
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    ctx->f30.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800C5CA8: mfc1        $v0, $f30
    ctx->r2 = (int32_t)ctx->f30.u32l;
    // 0x800C5CAC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C5CB0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C5CB4: bgez        $v1, L_800C5CC0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800C5CB8: sub.s       $f4, $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
            goto L_800C5CC0;
    }
    // 0x800C5CB8: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800C5CBC: addiu       $a1, $v1, 0x7
    ctx->r5 = ADD32(ctx->r3, 0X7);
L_800C5CC0:
    // 0x800C5CC0: sra         $a2, $a1, 3
    ctx->r6 = S32(SIGNED(ctx->r5) >> 3);
    // 0x800C5CC4: sll         $v0, $a2, 3
    ctx->r2 = S32(ctx->r6 << 3);
    // 0x800C5CC8: subu        $a2, $v1, $v0
    ctx->r6 = SUB32(ctx->r3, ctx->r2);
    // 0x800C5CCC: sh          $a2, -0x12($t0)
    MEM_H(-0X12, ctx->r8) = ctx->r6;
    // 0x800C5CD0: addiu       $a0, $a2, 0x1
    ctx->r4 = ADD32(ctx->r6, 0X1);
    // 0x800C5CD4: bgez        $a0, L_800C5CE0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800C5CD8: addu        $v0, $a0, $zero
        ctx->r2 = ADD32(ctx->r4, 0);
            goto L_800C5CE0;
    }
    // 0x800C5CD8: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x800C5CDC: addiu       $v0, $a2, 0x8
    ctx->r2 = ADD32(ctx->r6, 0X8);
L_800C5CE0:
    // 0x800C5CE0: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800C5CE4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C5CE8: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x800C5CEC: bne         $s1, $zero, L_800C5D9C
    if (ctx->r17 != 0) {
        // 0x800C5CF0: sh          $a0, -0x10($t0)
        MEM_H(-0X10, ctx->r8) = ctx->r4;
            goto L_800C5D9C;
    }
    // 0x800C5CF0: sh          $a0, -0x10($t0)
    MEM_H(-0X10, ctx->r8) = ctx->r4;
    // 0x800C5CF4: sll         $a1, $a2, 3
    ctx->r5 = S32(ctx->r6 << 3);
    // 0x800C5CF8: addu        $a1, $a1, $s0
    ctx->r5 = ADD32(ctx->r5, ctx->r16);
    // 0x800C5CFC: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x800C5D00: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // 0x800C5D04: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x800C5D08: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x800C5D0C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800C5D10: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800C5D14: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800C5D18: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800C5D1C: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x800C5D20: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C5D24: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800C5D28: trunc.w.s   $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5D2C: mfc1        $v0, $f30
    ctx->r2 = (int32_t)ctx->f30.u32l;
    // 0x800C5D30: sh          $v0, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r2;
    // 0x800C5D34: lh          $v1, 0x2($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X2);
    // 0x800C5D38: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    // 0x800C5D3C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800C5D40: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800C5D44: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800C5D48: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800C5D4C: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x800C5D50: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C5D54: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800C5D58: trunc.w.s   $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5D5C: mfc1        $v0, $f30
    ctx->r2 = (int32_t)ctx->f30.u32l;
    // 0x800C5D60: sh          $v0, 0x42($s0)
    MEM_H(0X42, ctx->r16) = ctx->r2;
    // 0x800C5D64: lh          $v1, 0x4($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X4);
    // 0x800C5D68: lh          $v0, 0x4($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4);
    // 0x800C5D6C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800C5D70: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800C5D74: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800C5D78: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800C5D7C: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x800C5D80: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C5D84: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800C5D88: trunc.w.s   $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5D8C: mfc1        $v0, $f30
    ctx->r2 = (int32_t)ctx->f30.u32l;
    // 0x800C5D90: sh          $v0, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r2;
    // 0x800C5D94: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800C5D98: sh          $v0, -0x12($t0)
    MEM_H(-0X12, ctx->r8) = ctx->r2;
L_800C5D9C:
    // 0x800C5D9C: div.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C5DA0: mul.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800C5DA4: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x800C5DA8: nop

    // 0x800C5DAC: bc1tl       L_800C5DC4
    if (c1cs) {
        // 0x800C5DB0: sub.s       $f0, $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_800C5DC4;
    }
    goto skip_4;
    // 0x800C5DB0: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
    skip_4:
    // 0x800C5DB4: trunc.w.s   $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5DB8: mfc1        $v0, $f30
    ctx->r2 = (int32_t)ctx->f30.u32l;
    // 0x800C5DBC: j           L_800C5DD4
    // 0x800C5DC0: sub.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f4.fl;
        goto L_800C5DD4;
    // 0x800C5DC0: sub.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f4.fl;
L_800C5DC4:
    // 0x800C5DC4: trunc.w.s   $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5DC8: mfc1        $v0, $f30
    ctx->r2 = (int32_t)ctx->f30.u32l;
    // 0x800C5DCC: or          $v0, $v0, $t1
    ctx->r2 = ctx->r2 | ctx->r9;
    // 0x800C5DD0: sub.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f4.fl;
L_800C5DD4:
    // 0x800C5DD4: add.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800C5DD8: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x800C5DDC: nop

    // 0x800C5DE0: bc1f        L_800C5DEC
    if (!c1cs) {
        // 0x800C5DE4: sh          $v0, -0x8($t0)
        MEM_H(-0X8, ctx->r8) = ctx->r2;
            goto L_800C5DEC;
    }
    // 0x800C5DE4: sh          $v0, -0x8($t0)
    MEM_H(-0X8, ctx->r8) = ctx->r2;
    // 0x800C5DE8: mov.s       $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = ctx->f10.fl;
L_800C5DEC:
    // 0x800C5DEC: div.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C5DF0: mul.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800C5DF4: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x800C5DF8: nop

    // 0x800C5DFC: bc1tl       L_800C5E14
    if (c1cs) {
        // 0x800C5E00: sub.s       $f0, $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_800C5E14;
    }
    goto skip_5;
    // 0x800C5E00: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
    skip_5:
    // 0x800C5E04: trunc.w.s   $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5E08: mfc1        $v0, $f30
    ctx->r2 = (int32_t)ctx->f30.u32l;
    // 0x800C5E0C: j           L_800C5E24
    // 0x800C5E10: sub.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f4.fl;
        goto L_800C5E24;
    // 0x800C5E10: sub.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f4.fl;
L_800C5E14:
    // 0x800C5E14: trunc.w.s   $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5E18: mfc1        $v0, $f30
    ctx->r2 = (int32_t)ctx->f30.u32l;
    // 0x800C5E1C: or          $v0, $v0, $t1
    ctx->r2 = ctx->r2 | ctx->r9;
    // 0x800C5E20: sub.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f4.fl;
L_800C5E24:
    // 0x800C5E24: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x800C5E28: c.lt.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl < ctx->f20.fl;
    // 0x800C5E2C: nop

    // 0x800C5E30: bc1f        L_800C5F18
    if (!c1cs) {
        // 0x800C5E34: sh          $v0, -0x4($t0)
        MEM_H(-0X4, ctx->r8) = ctx->r2;
            goto L_800C5F18;
    }
    // 0x800C5E34: sh          $v0, -0x4($t0)
    MEM_H(-0X4, ctx->r8) = ctx->r2;
    // 0x800C5E38: add.s       $f4, $f6, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f14.fl;
    // 0x800C5E3C: addiu       $a0, $a2, 0x1
    ctx->r4 = ADD32(ctx->r6, 0X1);
    // 0x800C5E40: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x800C5E44: trunc.w.s   $f30, $f4
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    ctx->f30.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800C5E48: mfc1        $v0, $f30
    ctx->r2 = (int32_t)ctx->f30.u32l;
    // 0x800C5E4C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C5E50: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C5E54: sll         $v0, $a2, 3
    ctx->r2 = S32(ctx->r6 << 3);
    // 0x800C5E58: addu        $a3, $v0, $s0
    ctx->r7 = ADD32(ctx->r2, ctx->r16);
    // 0x800C5E5C: lh          $a1, 0x0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X0);
    // 0x800C5E60: mtc1        $a1, $f2
    ctx->f2.u32l = ctx->r5;
    // 0x800C5E64: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800C5E68: bgez        $a0, L_800C5E74
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800C5E6C: sub.s       $f4, $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
            goto L_800C5E74;
    }
    // 0x800C5E6C: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800C5E70: addiu       $v1, $a2, 0x8
    ctx->r3 = ADD32(ctx->r6, 0X8);
L_800C5E74:
    // 0x800C5E74: sra         $v1, $v1, 3
    ctx->r3 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800C5E78: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800C5E7C: subu        $v1, $a0, $v1
    ctx->r3 = SUB32(ctx->r4, ctx->r3);
    // 0x800C5E80: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800C5E84: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x800C5E88: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800C5E8C: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x800C5E90: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C5E94: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C5E98: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800C5E9C: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C5EA0: trunc.w.s   $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5EA4: mfc1        $v0, $f30
    ctx->r2 = (int32_t)ctx->f30.u32l;
    // 0x800C5EA8: sh          $v0, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r2;
    // 0x800C5EAC: lh          $a0, 0x2($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X2);
    // 0x800C5EB0: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
    // 0x800C5EB4: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800C5EB8: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800C5EBC: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800C5EC0: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800C5EC4: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x800C5EC8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C5ECC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800C5ED0: trunc.w.s   $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C5ED4: mfc1        $v0, $f30
    ctx->r2 = (int32_t)ctx->f30.u32l;
    // 0x800C5ED8: sh          $v0, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r2;
    // 0x800C5EDC: lh          $a0, 0x4($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X4);
    // 0x800C5EE0: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x800C5EE4: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800C5EE8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C5EEC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C5EF0: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800C5EF4: mtc1        $a0, $f2
    ctx->f2.u32l = ctx->r4;
    // 0x800C5EF8: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800C5EFC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C5F00: mov.s       $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = ctx->f6.fl;
    // 0x800C5F04: trunc.w.s   $f30, $f2
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    ctx->f30.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800C5F08: mfc1        $v0, $f30
    ctx->r2 = (int32_t)ctx->f30.u32l;
    // 0x800C5F0C: sh          $v0, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r2;
    // 0x800C5F10: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x800C5F14: sh          $v0, -0x10($t0)
    MEM_H(-0X10, ctx->r8) = ctx->r2;
L_800C5F18:
    // 0x800C5F18: lwl         $t3, 0x10($sp)
    ctx->r11 = do_lwl(rdram, ctx->r11, ctx->r29, 0X10);
    // 0x800C5F1C: lwr         $t3, 0x13($sp)
    ctx->r11 = do_lwr(rdram, ctx->r11, ctx->r29, 0X13);
    // 0x800C5F20: swl         $t3, 0x0($t0)
    do_swl(rdram, 0X0, ctx->r8, ctx->r11);
    // 0x800C5F24: swr         $t3, 0x3($t0)
    do_swr(rdram, 0X3, ctx->r8, ctx->r11);
    // 0x800C5F28: addiu       $t0, $t0, -0x24
    ctx->r8 = ADD32(ctx->r8, -0X24);
    // 0x800C5F2C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C5F30: slti        $v0, $s1, 0x8
    ctx->r2 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
    // 0x800C5F34: beq         $v0, $zero, L_800C5F4C
    if (ctx->r2 == 0) {
        // 0x800C5F38: addiu       $s3, $s3, -0x24
        ctx->r19 = ADD32(ctx->r19, -0X24);
            goto L_800C5F4C;
    }
    // 0x800C5F38: addiu       $s3, $s3, -0x24
    ctx->r19 = ADD32(ctx->r19, -0X24);
    // 0x800C5F3C: c.lt.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl < ctx->f6.fl;
    // 0x800C5F40: nop

    // 0x800C5F44: bc1tl       L_800C5C94
    if (c1cs) {
        // 0x800C5F48: add.s       $f0, $f20, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f14.fl;
            goto L_800C5C94;
    }
    goto skip_6;
    // 0x800C5F48: add.s       $f0, $f20, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f14.fl;
    skip_6:
L_800C5F4C:
    // 0x800C5F4C: addiu       $v0, $s3, 0x24
    ctx->r2 = ADD32(ctx->r19, 0X24);
    // 0x800C5F50: sw          $v0, 0x940($s2)
    MEM_W(0X940, ctx->r18) = ctx->r2;
    // 0x800C5F54: addiu       $v0, $s1, 0x8
    ctx->r2 = ADD32(ctx->r17, 0X8);
    // 0x800C5F58: sw          $v0, 0x944($s2)
    MEM_W(0X944, ctx->r18) = ctx->r2;
    // 0x800C5F5C: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x800C5F60: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C5F64: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C5F68: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C5F6C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C5F70: ldc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X58);
    // 0x800C5F74: ldc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X50);
    // 0x800C5F78: ldc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X48);
    // 0x800C5F7C: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x800C5F80: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x800C5F84: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800C5F88: jr          $ra
    // 0x800C5F8C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800C5F8C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_800C5D9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5D9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C5DA0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800C5DA4: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800C5DA8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C5DAC: lbu         $a2, 0xB2F($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0XB2F);
    // 0x800C5DB0: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x800C5DB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C5DB8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800C5DBC: sltiu       $v0, $a2, 0x10
    ctx->r2 = ctx->r6 < 0X10 ? 1 : 0;
    // 0x800C5DC0: bne         $v0, $zero, L_800C5DCC
    if (ctx->r2 != 0) {
        // 0x800C5DC4: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_800C5DCC;
    }
    // 0x800C5DC4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C5DC8: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
L_800C5DCC:
    // 0x800C5DCC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C5DD0: addiu       $v1, $v0, 0xB40
    ctx->r3 = ADD32(ctx->r2, 0XB40);
    // 0x800C5DD4: lw          $a1, 0x18($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X18);
    // 0x800C5DD8: andi        $v0, $a1, 0x1
    ctx->r2 = ctx->r5 & 0X1;
    // 0x800C5DDC: bnel        $v0, $zero, L_800C5DE4
    if (ctx->r2 != 0) {
        // 0x800C5DE0: addiu       $a2, $zero, 0xF
        ctx->r6 = ADD32(0, 0XF);
            goto L_800C5DE4;
    }
    goto skip_0;
    // 0x800C5DE0: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    skip_0:
L_800C5DE4:
    // 0x800C5DE4: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800C5DE8: lui         $v1, 0x10
    ctx->r3 = S32(0X10 << 16);
    // 0x800C5DEC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800C5DF0: bnel        $v0, $zero, L_800C5E0C
    if (ctx->r2 != 0) {
        // 0x800C5DF4: addiu       $a2, $zero, 0x10
        ctx->r6 = ADD32(0, 0X10);
            goto L_800C5E0C;
    }
    goto skip_1;
    // 0x800C5DF4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    skip_1:
    // 0x800C5DF8: lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // 0x800C5DFC: and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // 0x800C5E00: beq         $v0, $zero, L_800C5E10
    if (ctx->r2 == 0) {
        // 0x800C5E04: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800C5E10;
    }
    // 0x800C5E04: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C5E08: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
L_800C5E0C:
    // 0x800C5E0C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800C5E10:
    // 0x800C5E10: addiu       $a1, $v0, 0xB40
    ctx->r5 = ADD32(ctx->r2, 0XB40);
    // 0x800C5E14: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x800C5E18: lui         $v1, 0x20
    ctx->r3 = S32(0X20 << 16);
    // 0x800C5E1C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800C5E20: bnel        $v0, $zero, L_800C5E40
    if (ctx->r2 != 0) {
        // 0x800C5E24: addiu       $a2, $zero, 0x11
        ctx->r6 = ADD32(0, 0X11);
            goto L_800C5E40;
    }
    goto skip_2;
    // 0x800C5E24: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    skip_2:
    // 0x800C5E28: lw          $v0, 0x18($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X18);
    // 0x800C5E2C: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x800C5E30: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800C5E34: beq         $v0, $zero, L_800C5E44
    if (ctx->r2 == 0) {
        // 0x800C5E38: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800C5E44;
    }
    // 0x800C5E38: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C5E3C: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
L_800C5E40:
    // 0x800C5E40: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800C5E44:
    // 0x800C5E44: addiu       $a1, $v0, 0xB40
    ctx->r5 = ADD32(ctx->r2, 0XB40);
    // 0x800C5E48: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x800C5E4C: lui         $v1, 0x40
    ctx->r3 = S32(0X40 << 16);
    // 0x800C5E50: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800C5E54: bnel        $v0, $zero, L_800C5E70
    if (ctx->r2 != 0) {
        // 0x800C5E58: addiu       $a2, $zero, 0x12
        ctx->r6 = ADD32(0, 0X12);
            goto L_800C5E70;
    }
    goto skip_3;
    // 0x800C5E58: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    skip_3:
    // 0x800C5E5C: lw          $v0, 0x18($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X18);
    // 0x800C5E60: lui         $v1, 0x1000
    ctx->r3 = S32(0X1000 << 16);
    // 0x800C5E64: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800C5E68: bnel        $v0, $zero, L_800C5E70
    if (ctx->r2 != 0) {
        // 0x800C5E6C: addiu       $a2, $zero, 0x12
        ctx->r6 = ADD32(0, 0X12);
            goto L_800C5E70;
    }
    goto skip_4;
    // 0x800C5E6C: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    skip_4:
L_800C5E70:
    // 0x800C5E70: lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X0);
    // 0x800C5E74: sltu        $v0, $a2, $v1
    ctx->r2 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x800C5E78: bne         $v0, $zero, L_800C5E84
    if (ctx->r2 != 0) {
        // 0x800C5E7C: addu        $a3, $a2, $zero
        ctx->r7 = ADD32(ctx->r6, 0);
            goto L_800C5E84;
    }
    // 0x800C5E7C: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x800C5E80: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
L_800C5E84:
    // 0x800C5E84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C5E88: addu        $a2, $a2, $a1
    ctx->r6 = ADD32(ctx->r6, ctx->r5);
    // 0x800C5E8C: sllv        $a2, $a1, $a2
    ctx->r6 = S32(ctx->r5 << (ctx->r6 & 31));
    // 0x800C5E90: sllv        $a1, $a1, $a3
    ctx->r5 = S32(ctx->r5 << (ctx->r7 & 31));
    // 0x800C5E94: jal         0x800AEC60
    // 0x800C5E98: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    func_800AEC60(rdram, ctx);
        goto after_0;
    // 0x800C5E98: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    after_0:
    // 0x800C5E9C: lui         $s1, 0xFF
    ctx->r17 = S32(0XFF << 16);
    // 0x800C5EA0: ori         $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 | 0XFFFF;
L_800C5EA4:
    // 0x800C5EA4: jal         0x800AF3C0
    // 0x800C5EA8: nop

    func_800AF3C0(rdram, ctx);
        goto after_1;
    // 0x800C5EA8: nop

    after_1:
    // 0x800C5EAC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800C5EB0: beq         $s0, $s1, L_800C5EA4
    if (ctx->r16 == ctx->r17) {
        // 0x800C5EB4: nop
    
            goto L_800C5EA4;
    }
    // 0x800C5EB4: nop

    // 0x800C5EB8: jal         0x800B24C4
    // 0x800C5EBC: nop

    func_800B24C4(rdram, ctx);
        goto after_2;
    // 0x800C5EBC: nop

    after_2:
    // 0x800C5EC0: lui         $v0, 0xFF
    ctx->r2 = S32(0XFF << 16);
    // 0x800C5EC4: ori         $v0, $v0, 0xFFFE
    ctx->r2 = ctx->r2 | 0XFFFE;
    // 0x800C5EC8: bne         $s0, $v0, L_800C5ED8
    if (ctx->r16 != ctx->r2) {
        // 0x800C5ECC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800C5ED8;
    }
    // 0x800C5ECC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C5ED0: j           L_800C5EE0
    // 0x800C5ED4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800C5EE0;
    // 0x800C5ED4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800C5ED8:
    // 0x800C5ED8: sb          $s0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r16;
    // 0x800C5EDC: sb          $zero, 0x2($s2)
    MEM_B(0X2, ctx->r18) = 0;
L_800C5EE0:
    // 0x800C5EE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C5EE4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800C5EE8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C5EEC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C5EF0: jr          $ra
    // 0x800C5EF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C5EF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800C5EF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5EF8: addiu       $sp, $sp, -0x1E8
    ctx->r29 = ADD32(ctx->r29, -0X1E8);
    // 0x800C5EFC: sw          $s6, 0x1D8($sp)
    MEM_W(0X1D8, ctx->r29) = ctx->r22;
    // 0x800C5F00: addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // 0x800C5F04: sw          $s2, 0x1C8($sp)
    MEM_W(0X1C8, ctx->r29) = ctx->r18;
    // 0x800C5F08: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800C5F0C: sw          $s3, 0x1CC($sp)
    MEM_W(0X1CC, ctx->r29) = ctx->r19;
    // 0x800C5F10: addu        $s3, $s2, $zero
    ctx->r19 = ADD32(ctx->r18, 0);
    // 0x800C5F14: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800C5F18: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C5F1C: sw          $ra, 0x1E0($sp)
    MEM_W(0X1E0, ctx->r29) = ctx->r31;
    // 0x800C5F20: sw          $s7, 0x1DC($sp)
    MEM_W(0X1DC, ctx->r29) = ctx->r23;
    // 0x800C5F24: sw          $s5, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r21;
    // 0x800C5F28: sw          $s4, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r20;
    // 0x800C5F2C: sw          $s1, 0x1C4($sp)
    MEM_W(0X1C4, ctx->r29) = ctx->r17;
    // 0x800C5F30: sw          $s0, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = ctx->r16;
    // 0x800C5F34: addiu       $t3, $v0, 0x760C
    ctx->r11 = ADD32(ctx->r2, 0X760C);
    // 0x800C5F38: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800C5F3C: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x800C5F40: lw          $t2, 0x8($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X8);
    // 0x800C5F44: sw          $t0, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r8;
    // 0x800C5F48: sw          $t1, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r9;
    // 0x800C5F4C: sw          $t2, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r10;
    // 0x800C5F50: lw          $t0, 0xC($t3)
    ctx->r8 = MEM_W(ctx->r11, 0XC);
    // 0x800C5F54: lw          $t1, 0x10($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X10);
    // 0x800C5F58: lw          $t2, 0x14($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X14);
    // 0x800C5F5C: sw          $t0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r8;
    // 0x800C5F60: sw          $t1, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r9;
    // 0x800C5F64: sw          $t2, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r10;
    // 0x800C5F68: lw          $t0, 0x18($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X18);
    // 0x800C5F6C: lw          $t1, 0x1C($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X1C);
    // 0x800C5F70: sw          $t0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r8;
    // 0x800C5F74: sw          $t1, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r9;
    // 0x800C5F78: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C5F7C: addiu       $t3, $v0, 0x7644
    ctx->r11 = ADD32(ctx->r2, 0X7644);
    // 0x800C5F80: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800C5F84: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x800C5F88: lw          $t2, 0x8($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X8);
    // 0x800C5F8C: sw          $t0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r8;
    // 0x800C5F90: sw          $t1, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r9;
    // 0x800C5F94: sw          $t2, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r10;
    // 0x800C5F98: jal         0x8001CA50
    // 0x800C5F9C: addiu       $a0, $a0, -0x2BC8
    ctx->r4 = ADD32(ctx->r4, -0X2BC8);
    func_8001CA50(rdram, ctx);
        goto after_0;
    // 0x800C5F9C: addiu       $a0, $a0, -0x2BC8
    ctx->r4 = ADD32(ctx->r4, -0X2BC8);
    after_0:
    // 0x800C5FA0: andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // 0x800C5FA4: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x800C5FA8: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x800C5FAC: beq         $v0, $zero, L_800C60CC
    if (ctx->r2 == 0) {
        // 0x800C5FB0: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_800C60CC;
    }
    // 0x800C5FB0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C5FB4: addiu       $v0, $v0, 0x7690
    ctx->r2 = ADD32(ctx->r2, 0X7690);
    // 0x800C5FB8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C5FBC: addu        $v1, $v1, $v0
    gpr jr_addend_800C5FC4 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C5FC0: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800C5FC4: jr          $v0
    // 0x800C5FC8: nop

    switch (jr_addend_800C5FC4 >> 2) {
        case 0: goto L_800C5FCC; break;
        case 1: goto L_800C5FFC; break;
        case 2: goto L_800C602C; break;
        case 3: goto L_800C606C; break;
        case 4: goto L_800C60A0; break;
        default: switch_error(__func__, 0x800C5FC4, 0x800A7690);
    }
    // 0x800C5FC8: nop

L_800C5FCC:
    // 0x800C5FCC: addiu       $s2, $zero, 0x12
    ctx->r18 = ADD32(0, 0X12);
    // 0x800C5FD0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800C5FD4: addiu       $s1, $sp, 0x10
    ctx->r17 = ADD32(ctx->r29, 0X10);
L_800C5FD8:
    // 0x800C5FD8: jal         0x8005589C
    // 0x800C5FDC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    getGameOrFrontText(rdram, ctx);
        goto after_1;
    // 0x800C5FDC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800C5FE0: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800C5FE4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C5FE8: sltu        $v0, $s2, $s0
    ctx->r2 = ctx->r18 < ctx->r16 ? 1 : 0;
    // 0x800C5FEC: beq         $v0, $zero, L_800C5FD8
    if (ctx->r2 == 0) {
        // 0x800C5FF0: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800C5FD8;
    }
    // 0x800C5FF0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800C5FF4: j           L_800C60D0
    // 0x800C5FF8: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
        goto L_800C60D0;
    // 0x800C5FF8: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
L_800C5FFC:
    // 0x800C5FFC: addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
    // 0x800C6000: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800C6004: addiu       $s1, $sp, 0x10
    ctx->r17 = ADD32(ctx->r29, 0X10);
L_800C6008:
    // 0x800C6008: jal         0x8005589C
    // 0x800C600C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    getGameOrFrontText(rdram, ctx);
        goto after_2;
    // 0x800C600C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_2:
    // 0x800C6010: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800C6014: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C6018: sltu        $v0, $s2, $s0
    ctx->r2 = ctx->r18 < ctx->r16 ? 1 : 0;
    // 0x800C601C: beq         $v0, $zero, L_800C6008
    if (ctx->r2 == 0) {
        // 0x800C6020: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800C6008;
    }
    // 0x800C6020: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800C6024: j           L_800C60D0
    // 0x800C6028: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
        goto L_800C60D0;
    // 0x800C6028: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
L_800C602C:
    // 0x800C602C: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x800C6030: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800C6034: addiu       $s1, $sp, 0x10
    ctx->r17 = ADD32(ctx->r29, 0X10);
L_800C6038:
    // 0x800C6038: jal         0x8005589C
    // 0x800C603C: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    getGameOrFrontText(rdram, ctx);
        goto after_3;
    // 0x800C603C: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    after_3:
    // 0x800C6040: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800C6044: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C6048: sltu        $v0, $s2, $s0
    ctx->r2 = ctx->r18 < ctx->r16 ? 1 : 0;
    // 0x800C604C: beq         $v0, $zero, L_800C6038
    if (ctx->r2 == 0) {
        // 0x800C6050: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800C6038;
    }
    // 0x800C6050: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800C6054: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C6058: lbu         $a0, 0xB40($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XB40);
    // 0x800C605C: jal         0x800C6720
    // 0x800C6060: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    getLevelHardwiredDifficulty(rdram, ctx);
        goto after_4;
    // 0x800C6060: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    after_4:
    // 0x800C6064: j           L_800C60D0
    // 0x800C6068: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
        goto L_800C60D0;
    // 0x800C6068: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
L_800C606C:
    // 0x800C606C: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x800C6070: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800C6074: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800C6078: addiu       $v1, $sp, 0x110
    ctx->r3 = ADD32(ctx->r29, 0X110);
L_800C607C:
    // 0x800C607C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800C6080: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C6084: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C6088: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800C608C: sltu        $v0, $s2, $s0
    ctx->r2 = ctx->r18 < ctx->r16 ? 1 : 0;
    // 0x800C6090: beq         $v0, $zero, L_800C607C
    if (ctx->r2 == 0) {
        // 0x800C6094: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800C607C;
    }
    // 0x800C6094: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800C6098: j           L_800C60D0
    // 0x800C609C: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
        goto L_800C60D0;
    // 0x800C609C: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
L_800C60A0:
    // 0x800C60A0: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x800C60A4: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800C60A8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800C60AC: addiu       $v1, $sp, 0x130
    ctx->r3 = ADD32(ctx->r29, 0X130);
L_800C60B0:
    // 0x800C60B0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800C60B4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C60B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C60BC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800C60C0: sltu        $v0, $s2, $s0
    ctx->r2 = ctx->r18 < ctx->r16 ? 1 : 0;
    // 0x800C60C4: beq         $v0, $zero, L_800C60B0
    if (ctx->r2 == 0) {
        // 0x800C60C8: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800C60B0;
    }
    // 0x800C60C8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_800C60CC:
    // 0x800C60CC: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
L_800C60D0:
    // 0x800C60D0: addiu       $s7, $sp, 0x10
    ctx->r23 = ADD32(ctx->r29, 0X10);
    // 0x800C60D4: addiu       $s4, $zero, 0x3E
    ctx->r20 = ADD32(0, 0X3E);
L_800C60D8:
    // 0x800C60D8: jal         0x80003430
    // 0x800C60DC: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    rand_recomp(rdram, ctx);
        goto after_5;
    // 0x800C60DC: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    after_5:
    // 0x800C60E0: jal         0x80002FF4
    // 0x800C60E4: addu        $s1, $s7, $zero
    ctx->r17 = ADD32(ctx->r23, 0);
    func_80002FF4(rdram, ctx);
        goto after_6;
    // 0x800C60E4: addu        $s1, $s7, $zero
    ctx->r17 = ADD32(ctx->r23, 0);
    after_6:
    // 0x800C60E8: jal         0x80079CE0
    // 0x800C60EC: nop

    setNewAndPreviousButtonsPressed(rdram, ctx);
        goto after_7;
    // 0x800C60EC: nop

    after_7:
    // 0x800C60F0: jal         0x8000A86C
    // 0x800C60F4: nop

    func_8000A86C(rdram, ctx);
        goto after_8;
    // 0x800C60F4: nop

    after_8:
    // 0x800C60F8: jal         0x8000A6CC
    // 0x800C60FC: nop

    func_8000A6CC(rdram, ctx);
        goto after_9;
    // 0x800C60FC: nop

    after_9:
L_800C6100:
    // 0x800C6100: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x800C6104: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x800C6108: jal         0x80033CC4
    // 0x800C610C: addiu       $a1, $s5, 0x7650
    ctx->r5 = ADD32(ctx->r21, 0X7650);
    sprintf_recomp(rdram, ctx);
        goto after_10;
    // 0x800C610C: addiu       $a1, $s5, 0x7650
    ctx->r5 = ADD32(ctx->r21, 0X7650);
    after_10:
    // 0x800C6110: beql        $s0, $s3, L_800C6118
    if (ctx->r16 == ctx->r19) {
        // 0x800C6114: sb          $s4, 0x90($sp)
        MEM_B(0X90, ctx->r29) = ctx->r20;
            goto L_800C6118;
    }
    goto skip_0;
    // 0x800C6114: sb          $s4, 0x90($sp)
    MEM_B(0X90, ctx->r29) = ctx->r20;
    skip_0:
L_800C6118:
    // 0x800C6118: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C611C: sltu        $v0, $s2, $s0
    ctx->r2 = ctx->r18 < ctx->r16 ? 1 : 0;
    // 0x800C6120: beq         $v0, $zero, L_800C6100
    if (ctx->r2 == 0) {
        // 0x800C6124: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800C6100;
    }
    // 0x800C6124: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800C6128: andi        $v1, $s6, 0xFF
    ctx->r3 = ctx->r22 & 0XFF;
    // 0x800C612C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800C6130: bne         $v1, $v0, L_800C6170
    if (ctx->r3 != ctx->r2) {
        // 0x800C6134: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_800C6170;
    }
    // 0x800C6134: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C6138: lbu         $a0, 0xB40($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XB40);
    // 0x800C613C: jal         0x8005589C
    // 0x800C6140: nop

    getGameOrFrontText(rdram, ctx);
        goto after_11;
    // 0x800C6140: nop

    after_11:
    // 0x800C6144: lbu         $a0, 0xB40($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XB40);
    // 0x800C6148: jal         0x800C6720
    // 0x800C614C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    getLevelHardwiredDifficulty(rdram, ctx);
        goto after_12;
    // 0x800C614C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_12:
    // 0x800C6150: jal         0x8005589C
    // 0x800C6154: addiu       $a0, $v0, 0x14
    ctx->r4 = ADD32(ctx->r2, 0X14);
    getGameOrFrontText(rdram, ctx);
        goto after_13;
    // 0x800C6154: addiu       $a0, $v0, 0x14
    ctx->r4 = ADD32(ctx->r2, 0X14);
    after_13:
    // 0x800C6158: addiu       $a0, $sp, 0x140
    ctx->r4 = ADD32(ctx->r29, 0X140);
    // 0x800C615C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800C6160: addiu       $a1, $a1, 0x7654
    ctx->r5 = ADD32(ctx->r5, 0X7654);
    // 0x800C6164: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800C6168: jal         0x80033CC4
    // 0x800C616C: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    sprintf_recomp(rdram, ctx);
        goto after_14;
    // 0x800C616C: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    after_14:
L_800C6170:
    // 0x800C6170: jal         0x80079F50
    // 0x800C6174: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    getControllerNewButtonsPressed(rdram, ctx);
        goto after_15;
    // 0x800C6174: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_15:
    // 0x800C6178: lui         $v1, 0x20
    ctx->r3 = S32(0X20 << 16);
    // 0x800C617C: ori         $v1, $v1, 0x800
    ctx->r3 = ctx->r3 | 0X800;
    // 0x800C6180: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800C6184: beq         $v0, $zero, L_800C619C
    if (ctx->r2 == 0) {
        // 0x800C6188: nop
    
            goto L_800C619C;
    }
    // 0x800C6188: nop

    // 0x800C618C: beq         $s3, $zero, L_800C6198
    if (ctx->r19 == 0) {
        // 0x800C6190: addu        $v0, $s2, $zero
        ctx->r2 = ADD32(ctx->r18, 0);
            goto L_800C6198;
    }
    // 0x800C6190: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x800C6194: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
L_800C6198:
    // 0x800C6198: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
L_800C619C:
    // 0x800C619C: jal         0x80079F50
    // 0x800C61A0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    getControllerNewButtonsPressed(rdram, ctx);
        goto after_16;
    // 0x800C61A0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_16:
    // 0x800C61A4: lui         $v1, 0x10
    ctx->r3 = S32(0X10 << 16);
    // 0x800C61A8: ori         $v1, $v1, 0x400
    ctx->r3 = ctx->r3 | 0X400;
    // 0x800C61AC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800C61B0: beq         $v0, $zero, L_800C61C8
    if (ctx->r2 == 0) {
        // 0x800C61B4: nop
    
            goto L_800C61C8;
    }
    // 0x800C61B4: nop

    // 0x800C61B8: beq         $s3, $s2, L_800C61C4
    if (ctx->r19 == ctx->r18) {
        // 0x800C61BC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800C61C4;
    }
    // 0x800C61BC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800C61C0: addiu       $v0, $s3, 0x1
    ctx->r2 = ADD32(ctx->r19, 0X1);
L_800C61C4:
    // 0x800C61C4: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
L_800C61C8:
    // 0x800C61C8: jal         0x80079F50
    // 0x800C61CC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    getControllerNewButtonsPressed(rdram, ctx);
        goto after_17;
    // 0x800C61CC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_17:
    // 0x800C61D0: andi        $v0, $v0, 0x5000
    ctx->r2 = ctx->r2 & 0X5000;
    // 0x800C61D4: bne         $v0, $zero, L_800C61FC
    if (ctx->r2 != 0) {
        // 0x800C61D8: lui         $a0, 0x800D
        ctx->r4 = S32(0X800D << 16);
            goto L_800C61FC;
    }
    // 0x800C61D8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800C61DC: jal         0x80016C44
    // 0x800C61E0: addiu       $a0, $a0, -0x2BF4
    ctx->r4 = ADD32(ctx->r4, -0X2BF4);
    func_80016C44(rdram, ctx);
        goto after_18;
    // 0x800C61E0: addiu       $a0, $a0, -0x2BF4
    ctx->r4 = ADD32(ctx->r4, -0X2BF4);
    after_18:
    // 0x800C61E4: jal         0x8000B6F4
    // 0x800C61E8: nop

    func_8000B6F4(rdram, ctx);
        goto after_19;
    // 0x800C61E8: nop

    after_19:
    // 0x800C61EC: jal         0x8000C07C
    // 0x800C61F0: nop

    func_8000C07C(rdram, ctx);
        goto after_20;
    // 0x800C61F0: nop

    after_20:
    // 0x800C61F4: j           L_800C60D8
    // 0x800C61F8: nop

        goto L_800C60D8;
    // 0x800C61F8: nop

L_800C61FC:
    // 0x800C61FC: jal         0x8000BF60
    // 0x800C6200: nop

    func_8000BF60(rdram, ctx);
        goto after_21;
    // 0x800C6200: nop

    after_21:
    // 0x800C6204: addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
    // 0x800C6208: lw          $ra, 0x1E0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1E0);
    // 0x800C620C: lw          $s7, 0x1DC($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X1DC);
    // 0x800C6210: lw          $s6, 0x1D8($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X1D8);
    // 0x800C6214: lw          $s5, 0x1D4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1D4);
    // 0x800C6218: lw          $s4, 0x1D0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X1D0);
    // 0x800C621C: lw          $s3, 0x1CC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1CC);
    // 0x800C6220: lw          $s2, 0x1C8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C8);
    // 0x800C6224: lw          $s1, 0x1C4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C4);
    // 0x800C6228: lw          $s0, 0x1C0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C0);
    // 0x800C622C: jr          $ra
    // 0x800C6230: addiu       $sp, $sp, 0x1E8
    ctx->r29 = ADD32(ctx->r29, 0X1E8);
    return;
    // 0x800C6230: addiu       $sp, $sp, 0x1E8
    ctx->r29 = ADD32(ctx->r29, 0X1E8);
;}
RECOMP_FUNC void func_800C5F90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5F90: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C5F94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C5F98: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800C5F9C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C5FA0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C5FA4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C5FA8: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x800C5FAC: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x800C5FB0: jal         0x8006C918
    // 0x800C5FB4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8006C918(rdram, ctx);
        goto after_0;
    // 0x800C5FB4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // 0x800C5FB8: lhu         $v1, 0xDB8($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XDB8);
    // 0x800C5FBC: addiu       $a2, $v1, -0x1
    ctx->r6 = ADD32(ctx->r3, -0X1);
    // 0x800C5FC0: bltz        $a2, L_800C6030
    if (SIGNED(ctx->r6) < 0) {
        // 0x800C5FC4: addu        $s2, $v0, $zero
        ctx->r18 = ADD32(ctx->r2, 0);
            goto L_800C6030;
    }
    // 0x800C5FC4: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x800C5FC8: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800C5FCC: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800C5FD0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800C5FD4: addu        $a1, $v0, $s0
    ctx->r5 = ADD32(ctx->r2, ctx->r16);
L_800C5FD8:
    // 0x800C5FD8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800C5FDC: lhu         $v1, 0xC38($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0XC38);
    // 0x800C5FE0: lbu         $a0, 0xC3A($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0XC3A);
    // 0x800C5FE4: addu        $v0, $s0, $v1
    ctx->r2 = ADD32(ctx->r16, ctx->r3);
    // 0x800C5FE8: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x800C5FEC: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800C5FF0: andi        $v0, $v0, 0x7FF
    ctx->r2 = ctx->r2 & 0X7FF;
    // 0x800C5FF4: lbu         $a0, 0xC3B($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0XC3B);
    // 0x800C5FF8: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800C5FFC: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x800C6000: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    // 0x800C6004: andi        $v0, $v0, 0x7FF
    ctx->r2 = ctx->r2 & 0X7FF;
    // 0x800C6008: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800C600C: addiu       $v1, $v1, 0x21
    ctx->r3 = ADD32(ctx->r3, 0X21);
    // 0x800C6010: andi        $v1, $v1, 0x7FF
    ctx->r3 = ctx->r3 & 0X7FF;
    // 0x800C6014: lbu         $a0, 0xC3C($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0XC3C);
    // 0x800C6018: addu        $v1, $s0, $v1
    ctx->r3 = ADD32(ctx->r16, ctx->r3);
    // 0x800C601C: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x800C6020: lbu         $v0, 0xC3D($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0XC3D);
    // 0x800C6024: addiu       $a1, $a1, -0x6
    ctx->r5 = ADD32(ctx->r5, -0X6);
    // 0x800C6028: bgez        $a2, L_800C5FD8
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800C602C: sb          $v0, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r2;
            goto L_800C5FD8;
    }
    // 0x800C602C: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_800C6030:
    // 0x800C6030: sh          $zero, 0xDB8($s0)
    MEM_H(0XDB8, ctx->r16) = 0;
    // 0x800C6034: lwc1        $f2, 0x0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800C6038: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C603C: lwc1        $f4, 0x6864($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6864);
    // 0x800C6040: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800C6044: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800C6048: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800C604C: lh          $v0, 0x85C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X85C);
    // 0x800C6050: trunc.w.s   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800C6054: mfc1        $s1, $f6
    ctx->r17 = (int32_t)ctx->f6.u32l;
    // 0x800C6058: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C605C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800C6060: bne         $s1, $v0, L_800C6074
    if (ctx->r17 != ctx->r2) {
        // 0x800C6064: nop
    
            goto L_800C6074;
    }
    // 0x800C6064: nop

    // 0x800C6068: lh          $v0, 0x85E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X85E);
    // 0x800C606C: beq         $v1, $v0, L_800C60FC
    if (ctx->r3 == ctx->r2) {
        // 0x800C6070: nop
    
            goto L_800C60FC;
    }
    // 0x800C6070: nop

L_800C6074:
    // 0x800C6074: lh          $a1, 0x85E($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X85E);
    // 0x800C6078: slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800C607C: beq         $v0, $zero, L_800C6098
    if (ctx->r2 == 0) {
        // 0x800C6080: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800C6098;
    }
    // 0x800C6080: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C6084: jal         0x800C435C
    // 0x800C6088: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    func_800C435C(rdram, ctx);
        goto after_1;
    // 0x800C6088: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    after_1:
    // 0x800C608C: lhu         $v0, 0x85E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X85E);
    // 0x800C6090: j           L_800C60B4
    // 0x800C6094: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_800C60B4;
    // 0x800C6094: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800C6098:
    // 0x800C6098: slt         $v0, $a1, $v1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C609C: beq         $v0, $zero, L_800C60B8
    if (ctx->r2 == 0) {
        // 0x800C60A0: nop
    
            goto L_800C60B8;
    }
    // 0x800C60A0: nop

    // 0x800C60A4: jal         0x800C435C
    // 0x800C60A8: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_800C435C(rdram, ctx);
        goto after_2;
    // 0x800C60A8: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_2:
    // 0x800C60AC: lhu         $v0, 0x85E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X85E);
    // 0x800C60B0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800C60B4:
    // 0x800C60B4: sh          $v0, 0x85E($s0)
    MEM_H(0X85E, ctx->r16) = ctx->r2;
L_800C60B8:
    // 0x800C60B8: lh          $a1, 0x85C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X85C);
    // 0x800C60BC: slt         $v0, $s1, $a1
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800C60C0: beq         $v0, $zero, L_800C60DC
    if (ctx->r2 == 0) {
        // 0x800C60C4: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800C60DC;
    }
    // 0x800C60C4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C60C8: jal         0x800C41B0
    // 0x800C60CC: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    func_800C41B0(rdram, ctx);
        goto after_3;
    // 0x800C60CC: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    after_3:
    // 0x800C60D0: lhu         $v0, 0x85C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X85C);
    // 0x800C60D4: j           L_800C60F8
    // 0x800C60D8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_800C60F8;
    // 0x800C60D8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800C60DC:
    // 0x800C60DC: slt         $v0, $a1, $s1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800C60E0: beq         $v0, $zero, L_800C60FC
    if (ctx->r2 == 0) {
        // 0x800C60E4: nop
    
            goto L_800C60FC;
    }
    // 0x800C60E4: nop

    // 0x800C60E8: jal         0x800C41B0
    // 0x800C60EC: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_800C41B0(rdram, ctx);
        goto after_4;
    // 0x800C60EC: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_4:
    // 0x800C60F0: lhu         $v0, 0x85C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X85C);
    // 0x800C60F4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800C60F8:
    // 0x800C60F8: sh          $v0, 0x85C($s0)
    MEM_H(0X85C, ctx->r16) = ctx->r2;
L_800C60FC:
    // 0x800C60FC: lwc1        $f2, 0xC($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0XC);
    // 0x800C6100: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800C6104: lwc1        $f0, 0x14($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X14);
    // 0x800C6108: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C610C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C6110: sqrt.s      $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = sqrtf(ctx->f2.fl);
    // 0x800C6114: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800C6118: lw          $v0, -0x72E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X72E4);
    // 0x800C611C: lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X4);
    // 0x800C6120: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800C6124: bne         $v1, $v0, L_800C6150
    if (ctx->r3 != ctx->r2) {
        // 0x800C6128: addiu       $v0, $s0, 0x948
        ctx->r2 = ADD32(ctx->r16, 0X948);
            goto L_800C6150;
    }
    // 0x800C6128: addiu       $v0, $s0, 0x948
    ctx->r2 = ADD32(ctx->r16, 0X948);
    // 0x800C612C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C6130: addiu       $s1, $v0, 0xB40
    ctx->r17 = ADD32(ctx->r2, 0XB40);
    // 0x800C6134: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x800C6138: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800C613C: beq         $v0, $zero, L_800C6150
    if (ctx->r2 == 0) {
        // 0x800C6140: addiu       $v0, $s0, 0x948
        ctx->r2 = ADD32(ctx->r16, 0X948);
            goto L_800C6150;
    }
    // 0x800C6140: addiu       $v0, $s0, 0x948
    ctx->r2 = ADD32(ctx->r16, 0X948);
    // 0x800C6144: lbu         $v0, 0xDD0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XDD0);
    // 0x800C6148: bne         $v0, $zero, L_800C619C
    if (ctx->r2 != 0) {
        // 0x800C614C: addiu       $v0, $s0, 0x948
        ctx->r2 = ADD32(ctx->r16, 0X948);
            goto L_800C619C;
    }
    // 0x800C614C: addiu       $v0, $s0, 0x948
    ctx->r2 = ADD32(ctx->r16, 0X948);
L_800C6150:
    // 0x800C6150: sw          $v0, 0x900($s0)
    MEM_W(0X900, ctx->r16) = ctx->r2;
    // 0x800C6154: addiu       $v1, $s0, 0x8AC
    ctx->r3 = ADD32(ctx->r16, 0X8AC);
    // 0x800C6158: addiu       $v0, $s0, 0x860
    ctx->r2 = ADD32(ctx->r16, 0X860);
    // 0x800C615C: addiu       $a0, $s0, 0x890
    ctx->r4 = ADD32(ctx->r16, 0X890);
L_800C6160:
    // 0x800C6160: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800C6164: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x800C6168: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x800C616C: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    // 0x800C6170: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800C6174: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x800C6178: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
    // 0x800C617C: sw          $t0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r8;
    // 0x800C6180: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800C6184: bne         $v0, $a0, L_800C6160
    if (ctx->r2 != ctx->r4) {
        // 0x800C6188: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800C6160;
    }
    // 0x800C6188: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800C618C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C6190: lwc1        $f20, -0x4024($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, -0X4024);
    // 0x800C6194: j           L_800C6228
    // 0x800C6198: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
        goto L_800C6228;
    // 0x800C6198: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_800C619C:
    // 0x800C619C: jal         0x800C7268
    // 0x800C61A0: addiu       $a0, $s0, 0x8AC
    ctx->r4 = ADD32(ctx->r16, 0X8AC);
    func_800C7268(rdram, ctx);
        goto after_5;
    // 0x800C61A0: addiu       $a0, $s0, 0x8AC
    ctx->r4 = ADD32(ctx->r16, 0X8AC);
    after_5:
    // 0x800C61A4: addiu       $v0, $s0, 0x9A0
    ctx->r2 = ADD32(ctx->r16, 0X9A0);
    // 0x800C61A8: sw          $v0, 0x900($s0)
    MEM_W(0X900, ctx->r16) = ctx->r2;
    // 0x800C61AC: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x800C61B0: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800C61B4: beq         $v0, $zero, L_800C6220
    if (ctx->r2 == 0) {
        // 0x800C61B8: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800C6220;
    }
    // 0x800C61B8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C61BC: lhu         $v0, 0x7F3C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7F3C);
    // 0x800C61C0: andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // 0x800C61C4: bne         $v0, $zero, L_800C6220
    if (ctx->r2 != 0) {
        // 0x800C61C8: nop
    
            goto L_800C6220;
    }
    // 0x800C61C8: nop

    // 0x800C61CC: jal         0x800C722C
    // 0x800C61D0: nop

    func_800C722C(rdram, ctx);
        goto after_6;
    // 0x800C61D0: nop

    after_6:
    // 0x800C61D4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800C61D8: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800C61DC: nop

    // 0x800C61E0: bc1f        L_800C6220
    if (!c1cs) {
        // 0x800C61E4: nop
    
            goto L_800C6220;
    }
    // 0x800C61E4: nop

    // 0x800C61E8: jal         0x800FEECC
    // 0x800C61EC: nop

    func_800FEECC(rdram, ctx);
        goto after_7;
    // 0x800C61EC: nop

    after_7:
    // 0x800C61F0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C61F4: beq         $v0, $zero, L_800C6210
    if (ctx->r2 == 0) {
        // 0x800C61F8: nop
    
            goto L_800C6210;
    }
    // 0x800C61F8: nop

    // 0x800C61FC: jal         0x800FEEF4
    // 0x800C6200: nop

    getHudSecondaryWeponCount(rdram, ctx);
        goto after_8;
    // 0x800C6200: nop

    after_8:
    // 0x800C6204: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C6208: bne         $v0, $zero, L_800C6220
    if (ctx->r2 != 0) {
        // 0x800C620C: nop
    
            goto L_800C6220;
    }
    // 0x800C620C: nop

L_800C6210:
    // 0x800C6210: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C6214: lwc1        $f20, 0x6868($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X6868);
    // 0x800C6218: j           L_800C6228
    // 0x800C621C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
        goto L_800C6228;
    // 0x800C621C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_800C6220:
    // 0x800C6220: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800C6224: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_800C6228:
    // 0x800C6228: lwc1        $f0, 0xC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC);
    // 0x800C622C: lwc1        $f2, 0x14($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X14);
    // 0x800C6230: div.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800C6234: div.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f22.fl);
    // 0x800C6238: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800C623C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800C6240: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800C6244: jal         0x800C4D8C
    // 0x800C6248: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_800C4D8C(rdram, ctx);
        goto after_9;
    // 0x800C6248: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_9:
    // 0x800C624C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C6250: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800C6254: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800C6258: jal         0x800C5580
    // 0x800C625C: addiu       $a2, $s2, 0xC
    ctx->r6 = ADD32(ctx->r18, 0XC);
    func_800C5580(rdram, ctx);
        goto after_10;
    // 0x800C625C: addiu       $a2, $s2, 0xC
    ctx->r6 = ADD32(ctx->r18, 0XC);
    after_10:
    // 0x800C6260: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C6264: lwc1        $f0, 0xC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC);
    // 0x800C6268: lwc1        $f2, 0x14($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X14);
    // 0x800C626C: div.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800C6270: div.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f22.fl);
    // 0x800C6274: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800C6278: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800C627C: jal         0x800C5918
    // 0x800C6280: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_800C5918(rdram, ctx);
        goto after_11;
    // 0x800C6280: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_11:
    // 0x800C6284: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C6288: jal         0x800C51E0
    // 0x800C628C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    placeRadarDots(rdram, ctx);
        goto after_12;
    // 0x800C628C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_12:
    // 0x800C6290: addiu       $a1, $s0, 0x800
    ctx->r5 = ADD32(ctx->r16, 0X800);
    // 0x800C6294: addiu       $a2, $s0, 0x824
    ctx->r6 = ADD32(ctx->r16, 0X824);
    // 0x800C6298: lhu         $a0, 0x858($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X858);
    // 0x800C629C: jal         0x80022C00
    // 0x800C62A0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80022C00(rdram, ctx);
        goto after_13;
    // 0x800C62A0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_13:
    // 0x800C62A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C62A8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C62AC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C62B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C62B4: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x800C62B8: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800C62BC: jr          $ra
    // 0x800C62C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C62C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void getAvailablePlayerCraftFlagsConsiderUnlocks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6234: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800C6238: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C623C: addiu       $v0, $v0, -0x13B0
    ctx->r2 = ADD32(ctx->r2, -0X13B0);
    // 0x800C6240: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x800C6244: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C6248: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C624C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C6250: addiu       $a2, $v0, 0xB10
    ctx->r6 = ADD32(ctx->r2, 0XB10);
    // 0x800C6254: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800C6258: lbu         $v0, 0x1F($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X1F);
    // 0x800C625C: sltiu       $v0, $v0, 0x5
    ctx->r2 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x800C6260: bne         $v0, $zero, L_800C6280
    if (ctx->r2 != 0) {
        // 0x800C6264: sllv        $a0, $a0, $v1
        ctx->r4 = S32(ctx->r4 << (ctx->r3 & 31));
            goto L_800C6280;
    }
    // 0x800C6264: sllv        $a0, $a0, $v1
    ctx->r4 = S32(ctx->r4 << (ctx->r3 & 31));
    // 0x800C6268: lbu         $v0, 0x1F($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X1F);
    // 0x800C626C: sltu        $v0, $a1, $v0
    ctx->r2 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x800C6270: beq         $v0, $zero, L_800C6280
    if (ctx->r2 == 0) {
        // 0x800C6274: andi        $v0, $a0, 0xD
        ctx->r2 = ctx->r4 & 0XD;
            goto L_800C6280;
    }
    // 0x800C6274: andi        $v0, $a0, 0xD
    ctx->r2 = ctx->r4 & 0XD;
    // 0x800C6278: bnel        $v0, $zero, L_800C6280
    if (ctx->r2 != 0) {
        // 0x800C627C: ori         $a0, $a0, 0x4
        ctx->r4 = ctx->r4 | 0X4;
            goto L_800C6280;
    }
    goto skip_0;
    // 0x800C627C: ori         $a0, $a0, 0x4
    ctx->r4 = ctx->r4 | 0X4;
    skip_0:
L_800C6280:
    // 0x800C6280: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C6284: addiu       $v1, $v0, 0xB10
    ctx->r3 = ADD32(ctx->r2, 0XB10);
    // 0x800C6288: lbu         $v0, 0x1F($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1F);
    // 0x800C628C: sltiu       $v0, $v0, 0xA
    ctx->r2 = ctx->r2 < 0XA ? 1 : 0;
    // 0x800C6290: bne         $v0, $zero, L_800C62B4
    if (ctx->r2 != 0) {
        // 0x800C6294: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800C62B4;
    }
    // 0x800C6294: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C6298: lbu         $v0, 0x1F($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1F);
    // 0x800C629C: sltu        $v0, $a1, $v0
    ctx->r2 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x800C62A0: beq         $v0, $zero, L_800C62B0
    if (ctx->r2 == 0) {
        // 0x800C62A4: andi        $v0, $a0, 0xD
        ctx->r2 = ctx->r4 & 0XD;
            goto L_800C62B0;
    }
    // 0x800C62A4: andi        $v0, $a0, 0xD
    ctx->r2 = ctx->r4 & 0XD;
    // 0x800C62A8: bnel        $v0, $zero, L_800C62B0
    if (ctx->r2 != 0) {
        // 0x800C62AC: ori         $a0, $a0, 0x8
        ctx->r4 = ctx->r4 | 0X8;
            goto L_800C62B0;
    }
    goto skip_1;
    // 0x800C62AC: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    skip_1:
L_800C62B0:
    // 0x800C62B0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800C62B4:
    // 0x800C62B4: addiu       $v1, $v0, 0xB10
    ctx->r3 = ADD32(ctx->r2, 0XB10);
    // 0x800C62B8: lbu         $v0, 0x1F($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1F);
    // 0x800C62BC: sltiu       $v0, $v0, 0xF
    ctx->r2 = ctx->r2 < 0XF ? 1 : 0;
    // 0x800C62C0: bne         $v0, $zero, L_800C62E4
    if (ctx->r2 != 0) {
        // 0x800C62C4: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800C62E4;
    }
    // 0x800C62C4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C62C8: lbu         $v0, 0x1F($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1F);
    // 0x800C62CC: sltu        $v0, $a1, $v0
    ctx->r2 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x800C62D0: beq         $v0, $zero, L_800C62E0
    if (ctx->r2 == 0) {
        // 0x800C62D4: andi        $v0, $a0, 0xD
        ctx->r2 = ctx->r4 & 0XD;
            goto L_800C62E0;
    }
    // 0x800C62D4: andi        $v0, $a0, 0xD
    ctx->r2 = ctx->r4 & 0XD;
    // 0x800C62D8: bnel        $v0, $zero, L_800C62E0
    if (ctx->r2 != 0) {
        // 0x800C62DC: ori         $a0, $a0, 0x1
        ctx->r4 = ctx->r4 | 0X1;
            goto L_800C62E0;
    }
    goto skip_2;
    // 0x800C62DC: ori         $a0, $a0, 0x1
    ctx->r4 = ctx->r4 | 0X1;
    skip_2:
L_800C62E0:
    // 0x800C62E0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800C62E4:
    // 0x800C62E4: addiu       $a2, $v0, 0xB40
    ctx->r6 = ADD32(ctx->r2, 0XB40);
    // 0x800C62E8: lw          $v1, 0xC($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XC);
    // 0x800C62EC: lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
    // 0x800C62F0: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x800C62F4: bnel        $v0, $zero, L_800C62FC
    if (ctx->r2 != 0) {
        // 0x800C62F8: ori         $a0, $a0, 0x7F
        ctx->r4 = ctx->r4 | 0X7F;
            goto L_800C62FC;
    }
    goto skip_3;
    // 0x800C62F8: ori         $a0, $a0, 0x7F
    ctx->r4 = ctx->r4 | 0X7F;
    skip_3:
L_800C62FC:
    // 0x800C62FC: lw          $v0, 0x18($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X18);
    // 0x800C6300: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800C6304: bnel        $v0, $zero, L_800C6320
    if (ctx->r2 != 0) {
        // 0x800C6308: ori         $a0, $a0, 0x20
        ctx->r4 = ctx->r4 | 0X20;
            goto L_800C6320;
    }
    goto skip_4;
    // 0x800C6308: ori         $a0, $a0, 0x20
    ctx->r4 = ctx->r4 | 0X20;
    skip_4:
    // 0x800C630C: lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
    // 0x800C6310: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x800C6314: beq         $v0, $zero, L_800C6324
    if (ctx->r2 == 0) {
        // 0x800C6318: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800C6324;
    }
    // 0x800C6318: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C631C: ori         $a0, $a0, 0x20
    ctx->r4 = ctx->r4 | 0X20;
L_800C6320:
    // 0x800C6320: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800C6324:
    // 0x800C6324: addiu       $v1, $v0, 0xB40
    ctx->r3 = ADD32(ctx->r2, 0XB40);
    // 0x800C6328: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x800C632C: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x800C6330: bnel        $v0, $zero, L_800C6350
    if (ctx->r2 != 0) {
        // 0x800C6334: ori         $a0, $a0, 0x40
        ctx->r4 = ctx->r4 | 0X40;
            goto L_800C6350;
    }
    goto skip_5;
    // 0x800C6334: ori         $a0, $a0, 0x40
    ctx->r4 = ctx->r4 | 0X40;
    skip_5:
    // 0x800C6338: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800C633C: lui         $v1, 0x4
    ctx->r3 = S32(0X4 << 16);
    // 0x800C6340: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800C6344: beq         $v0, $zero, L_800C6354
    if (ctx->r2 == 0) {
        // 0x800C6348: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_800C6354;
    }
    // 0x800C6348: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x800C634C: ori         $a0, $a0, 0x40
    ctx->r4 = ctx->r4 | 0X40;
L_800C6350:
    // 0x800C6350: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_800C6354:
    // 0x800C6354: bne         $a1, $v0, L_800C6370
    if (ctx->r5 != ctx->r2) {
        // 0x800C6358: addiu       $v0, $zero, 0x11
        ctx->r2 = ADD32(0, 0X11);
            goto L_800C6370;
    }
    // 0x800C6358: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // 0x800C635C: addiu       $v0, $zero, -0x9
    ctx->r2 = ADD32(0, -0X9);
    // 0x800C6360: and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
    // 0x800C6364: addiu       $v0, $zero, -0x11
    ctx->r2 = ADD32(0, -0X11);
    // 0x800C6368: and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
    // 0x800C636C: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_800C6370:
    // 0x800C6370: beql        $a1, $v0, L_800C6378
    if (ctx->r5 == ctx->r2) {
        // 0x800C6374: andi        $a0, $a0, 0x1
        ctx->r4 = ctx->r4 & 0X1;
            goto L_800C6378;
    }
    goto skip_6;
    // 0x800C6374: andi        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 & 0X1;
    skip_6:
L_800C6378:
    // 0x800C6378: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800C637C: beql        $a1, $v0, L_800C6384
    if (ctx->r5 == ctx->r2) {
        // 0x800C6380: andi        $a0, $a0, 0x3
        ctx->r4 = ctx->r4 & 0X3;
            goto L_800C6384;
    }
    goto skip_7;
    // 0x800C6380: andi        $a0, $a0, 0x3
    ctx->r4 = ctx->r4 & 0X3;
    skip_7:
L_800C6384:
    // 0x800C6384: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800C6388: beq         $a1, $v0, L_800C63A8
    if (ctx->r5 == ctx->r2) {
        // 0x800C638C: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_800C63A8;
    }
    // 0x800C638C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800C6390: beq         $a1, $v0, L_800C63A8
    if (ctx->r5 == ctx->r2) {
        // 0x800C6394: addiu       $v0, $zero, 0xB
        ctx->r2 = ADD32(0, 0XB);
            goto L_800C63A8;
    }
    // 0x800C6394: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x800C6398: beq         $a1, $v0, L_800C63A8
    if (ctx->r5 == ctx->r2) {
        // 0x800C639C: addiu       $v0, $zero, 0x12
        ctx->r2 = ADD32(0, 0X12);
            goto L_800C63A8;
    }
    // 0x800C639C: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x800C63A0: bne         $a1, $v0, L_800C63B0
    if (ctx->r5 != ctx->r2) {
        // 0x800C63A4: addiu       $v0, $zero, 0x10
        ctx->r2 = ADD32(0, 0X10);
            goto L_800C63B0;
    }
    // 0x800C63A4: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_800C63A8:
    // 0x800C63A8: andi        $a0, $a0, 0x10
    ctx->r4 = ctx->r4 & 0X10;
    // 0x800C63AC: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_800C63B0:
    // 0x800C63B0: beql        $a1, $v0, L_800C63B8
    if (ctx->r5 == ctx->r2) {
        // 0x800C63B4: andi        $a0, $a0, 0x80
        ctx->r4 = ctx->r4 & 0X80;
            goto L_800C63B8;
    }
    goto skip_8;
    // 0x800C63B4: andi        $a0, $a0, 0x80
    ctx->r4 = ctx->r4 & 0X80;
    skip_8:
L_800C63B8:
    // 0x800C63B8: jr          $ra
    // 0x800C63BC: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    return;
    // 0x800C63BC: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
;}
RECOMP_FUNC void func_800C62C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C62C4: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x800C62C8: lbu         $v1, -0x601C($a2)
    ctx->r3 = MEM_BU(ctx->r6, -0X601C);
    // 0x800C62CC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800C62D0: beq         $v1, $v0, L_800C6310
    if (ctx->r3 == ctx->r2) {
        // 0x800C62D4: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800C6310;
    }
    // 0x800C62D4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C62D8: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x800C62DC: addiu       $a2, $a2, -0x601C
    ctx->r6 = ADD32(ctx->r6, -0X601C);
    // 0x800C62E0: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
    // 0x800C62E4: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
L_800C62E8:
    // 0x800C62E8: beq         $v0, $a0, L_800C62FC
    if (ctx->r2 == ctx->r4) {
        // 0x800C62EC: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_800C62FC;
    }
    // 0x800C62EC: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800C62F0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800C62F4: bne         $v0, $a3, L_800C62E8
    if (ctx->r2 != ctx->r7) {
        // 0x800C62F8: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_800C62E8;
    }
    // 0x800C62F8: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
L_800C62FC:
    // 0x800C62FC: addu        $v0, $a1, $a2
    ctx->r2 = ADD32(ctx->r5, ctx->r6);
    // 0x800C6300: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800C6304: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800C6308: bne         $v1, $v0, L_800C6318
    if (ctx->r3 != ctx->r2) {
        // 0x800C630C: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_800C6318;
    }
    // 0x800C630C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
L_800C6310:
    // 0x800C6310: jr          $ra
    // 0x800C6314: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800C6314: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800C6318:
    // 0x800C6318: addiu       $v1, $v1, -0x4010
    ctx->r3 = ADD32(ctx->r3, -0X4010);
    // 0x800C631C: sra         $v0, $a1, 1
    ctx->r2 = S32(SIGNED(ctx->r5) >> 1);
    // 0x800C6320: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800C6324: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C6328: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800C632C: jr          $ra
    // 0x800C6330: nop

    return;
    // 0x800C6330: nop

;}
RECOMP_FUNC void func_800C6334(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6334: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C6338: jr          $ra
    // 0x800C633C: sh          $zero, -0x3F80($v0)
    MEM_H(-0X3F80, ctx->r2) = 0;
    return;
    // 0x800C633C: sh          $zero, -0x3F80($v0)
    MEM_H(-0X3F80, ctx->r2) = 0;
;}
