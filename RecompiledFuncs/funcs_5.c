#include "recomp.h"
#include "funcs.h"
#include <stdio.h>

RECOMP_FUNC void func_8001A038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A038: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001A03C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8001A040: jal         0x80037510
    // 0x8001A044: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_0;
    // 0x8001A044: nop

    after_0:
    // 0x8001A048: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8001A04C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001A050: jr          $ra
    // 0x8001A054: nop

    return;
    // 0x8001A054: nop

;}
RECOMP_FUNC void func_8001A058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    { static int n=0; if (++n<=10 || (n%100)==0) { if(0) fprintf(stderr, "[trace] func_8001A058(audio-submit) #%d dl=0x%08X\n", n, (uint32_t)ctx->r4); fflush(stderr); } }
    // 0x8001A058: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001A05C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8001A060: addiu       $a1, $a1, -0x7380
    ctx->r5 = ADD32(ctx->r5, -0X7380);
    // 0x8001A064: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001A068: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8001A06C: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x8001A070: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001A074: sw          $a0, -0x737C($at)
    MEM_W(-0X737C, ctx->r1) = ctx->r4;
    // 0x8001A078: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001A07C: addiu       $a0, $a0, -0x5BE0
    ctx->r4 = ADD32(ctx->r4, -0X5BE0);
    // 0x8001A080: jal         0x80033410
    // 0x8001A084: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8001A084: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8001A088: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8001A08C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001A090: jr          $ra
    // 0x8001A094: nop

    return;
    // 0x8001A094: nop

;}
RECOMP_FUNC void func_8001A098(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A098: addiu       $sp, $sp, -0x1C0
    ctx->r29 = ADD32(ctx->r29, -0X1C0);
    // 0x8001A09C: lw          $v1, 0x1F4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1F4);
    // 0x8001A0A0: sw          $s6, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->r22;
    // 0x8001A0A4: lhu         $s6, 0x1D2($sp)
    ctx->r22 = MEM_HU(ctx->r29, 0X1D2);
    // 0x8001A0A8: lbu         $t9, 0x1D7($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X1D7);
    // 0x8001A0AC: sw          $s7, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r23;
    // 0x8001A0B0: lbu         $s7, 0x1E7($sp)
    ctx->r23 = MEM_BU(ctx->r29, 0X1E7);
    // 0x8001A0B4: sw          $fp, 0x1A8($sp)
    MEM_W(0X1A8, ctx->r29) = ctx->r30;
    // 0x8001A0B8: lbu         $fp, 0x1EB($sp)
    ctx->r30 = MEM_BU(ctx->r29, 0X1EB);
    // 0x8001A0BC: lbu         $t0, 0x1FB($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1FB);
    // 0x8001A0C0: sw          $s0, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r16;
    // 0x8001A0C4: lbu         $s0, 0x1FF($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X1FF);
    // 0x8001A0C8: sb          $t9, 0x15F($sp)
    MEM_B(0X15F, ctx->r29) = ctx->r25;
    // 0x8001A0CC: lbu         $t9, 0x1DB($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X1DB);
    // 0x8001A0D0: sb          $t9, 0x167($sp)
    MEM_B(0X167, ctx->r29) = ctx->r25;
    // 0x8001A0D4: lbu         $t9, 0x1DF($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X1DF);
    // 0x8001A0D8: sb          $t9, 0x16F($sp)
    MEM_B(0X16F, ctx->r29) = ctx->r25;
    // 0x8001A0DC: lbu         $t9, 0x1E3($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X1E3);
    // 0x8001A0E0: sb          $t9, 0x177($sp)
    MEM_B(0X177, ctx->r29) = ctx->r25;
    // 0x8001A0E4: lbu         $t9, 0x1EF($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X1EF);
    // 0x8001A0E8: sb          $t9, 0x17F($sp)
    MEM_B(0X17F, ctx->r29) = ctx->r25;
    // 0x8001A0EC: lbu         $t9, 0x1F3($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X1F3);
    // 0x8001A0F0: sw          $s3, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r19;
    // 0x8001A0F4: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x8001A0F8: sw          $s4, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->r20;
    // 0x8001A0FC: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x8001A100: sw          $ra, 0x1AC($sp)
    MEM_W(0X1AC, ctx->r29) = ctx->r31;
    // 0x8001A104: sw          $s5, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r21;
    // 0x8001A108: sw          $s2, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->r18;
    // 0x8001A10C: sw          $s1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r17;
    // 0x8001A110: sdc1        $f22, 0x1B8($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X1B8, ctx->r29);
    // 0x8001A114: sdc1        $f20, 0x1B0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X1B0, ctx->r29);
    // 0x8001A118: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001A11C: sb          $zero, -0x7156($at)
    MEM_B(-0X7156, ctx->r1) = 0;
    // 0x8001A120: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001A124: sb          $zero, -0x7155($at)
    MEM_B(-0X7155, ctx->r1) = 0;
    // 0x8001A128: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001A12C: sb          $zero, -0x7154($at)
    MEM_B(-0X7154, ctx->r1) = 0;
    // 0x8001A130: sb          $t9, 0x187($sp)
    MEM_B(0X187, ctx->r29) = ctx->r25;
    // 0x8001A134: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001A138: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x8001A13C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001A140: sw          $v0, -0x7168($at)
    MEM_W(-0X7168, ctx->r1) = ctx->r2;
    // 0x8001A144: beq         $fp, $zero, L_8001A158
    if (ctx->r30 == 0) {
        // 0x8001A148: addu        $s2, $a3, $zero
        ctx->r18 = ADD32(ctx->r7, 0);
            goto L_8001A158;
    }
    // 0x8001A148: addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    // 0x8001A14C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001A150: j           L_8001A15C
    // 0x8001A154: nop

        goto L_8001A15C;
    // 0x8001A154: nop

L_8001A158:
    // 0x8001A158: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
L_8001A15C:
    // 0x8001A15C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001A160: sw          $v0, -0x7164($at)
    MEM_W(-0X7164, ctx->r1) = ctx->r2;
    // 0x8001A164: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x8001A168: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001A16C: sw          $v0, -0x7160($at)
    MEM_W(-0X7160, ctx->r1) = ctx->r2;
    // 0x8001A170: bne         $v0, $zero, L_8001A17C
    if (ctx->r2 != 0) {
        // 0x8001A174: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8001A17C;
    }
    // 0x8001A174: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8001A178: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8001A17C:
    // 0x8001A17C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001A180: sb          $v0, -0x7153($at)
    MEM_B(-0X7153, ctx->r1) = ctx->r2;
    // 0x8001A184: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001A188: addiu       $a0, $a0, -0x72F0
    ctx->r4 = ADD32(ctx->r4, -0X72F0);
    // 0x8001A18C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8001A190: addiu       $a1, $a1, -0x72D8
    ctx->r5 = ADD32(ctx->r5, -0X72D8);
    // 0x8001A194: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8001A198: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001A19C: sb          $t0, -0x7151($at)
    MEM_B(-0X7151, ctx->r1) = ctx->r8;
    // 0x8001A1A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001A1A4: sw          $v0, -0x714C($at)
    MEM_W(-0X714C, ctx->r1) = ctx->r2;
    // 0x8001A1A8: jal         0x8002B300
    // 0x8001A1AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8001A1AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8001A1B0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001A1B4: addiu       $a0, $a0, -0x72F0
    ctx->r4 = ADD32(ctx->r4, -0X72F0);
    // 0x8001A1B8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8001A1BC: jal         0x80033410
    // 0x8001A1C0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8001A1C0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // 0x8001A1C4: bne         $s0, $zero, L_8001A280
    if (ctx->r16 != 0) {
        // 0x8001A1C8: nop
    
            goto L_8001A280;
    }
    // 0x8001A1C8: nop

    // 0x8001A1CC: jal         0x80007980
    // 0x8001A1D0: addiu       $s1, $zero, 0x7A
    ctx->r17 = ADD32(0, 0X7A);
    func_80007980(rdram, ctx);
        goto after_2;
    // 0x8001A1D0: addiu       $s1, $zero, 0x7A
    ctx->r17 = ADD32(0, 0X7A);
    after_2:
    // 0x8001A1D4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8001A1D8: addiu       $s0, $s0, -0x32D8
    ctx->r16 = ADD32(ctx->r16, -0X32D8);
    // 0x8001A1DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8001A1E0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8001A1E4: lui         $a2, 0x8002
    ctx->r6 = S32(0X8002 << 16);
    // 0x8001A1E8: addiu       $a2, $a2, -0x6798
    ctx->r6 = ADD32(ctx->r6, -0X6798);
    // 0x8001A1EC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8001A1F0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001A1F4: addiu       $v0, $v0, -0x36D8
    ctx->r2 = ADD32(ctx->r2, -0X36D8);
    // 0x8001A1F8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8001A1FC: addiu       $v0, $zero, 0x75
    ctx->r2 = ADD32(0, 0X75);
    // 0x8001A200: jal         0x8002B330
    // 0x8001A204: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    osCreateThread_recomp(rdram, ctx);
        goto after_3;
    // 0x8001A204: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_3:
    // 0x8001A208: jal         0x800344E0
    // 0x8001A20C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osStartThread_recomp(rdram, ctx);
        goto after_4;
    // 0x8001A20C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x8001A210: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8001A214: addiu       $s0, $s0, -0x2568
    ctx->r16 = ADD32(ctx->r16, -0X2568);
    // 0x8001A218: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8001A21C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8001A220: lui         $a2, 0x8002
    ctx->r6 = S32(0X8002 << 16);
    // 0x8001A224: addiu       $a2, $a2, -0x640C
    ctx->r6 = ADD32(ctx->r6, -0X640C);
    // 0x8001A228: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8001A22C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001A230: addiu       $v0, $v0, -0x2B68
    ctx->r2 = ADD32(ctx->r2, -0X2B68);
    // 0x8001A234: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8001A238: jal         0x8002B330
    // 0x8001A23C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    osCreateThread_recomp(rdram, ctx);
        goto after_5;
    // 0x8001A23C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_5:
    // 0x8001A240: jal         0x800344E0
    // 0x8001A244: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osStartThread_recomp(rdram, ctx);
        goto after_6;
    // 0x8001A244: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // 0x8001A248: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8001A24C: addiu       $s0, $s0, -0x3128
    ctx->r16 = ADD32(ctx->r16, -0X3128);
    // 0x8001A250: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8001A254: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8001A258: lui         $a2, 0x8002
    ctx->r6 = S32(0X8002 << 16);
    // 0x8001A25C: addiu       $a2, $a2, -0x3CD8
    ctx->r6 = ADD32(ctx->r6, -0X3CD8);
    // 0x8001A260: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8001A264: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001A268: addiu       $v0, $v0, -0x32D8
    ctx->r2 = ADD32(ctx->r2, -0X32D8);
    // 0x8001A26C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8001A270: jal         0x8002B330
    // 0x8001A274: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    osCreateThread_recomp(rdram, ctx);
        goto after_7;
    // 0x8001A274: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_7:
    // 0x8001A278: jal         0x800344E0
    // 0x8001A27C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osStartThread_recomp(rdram, ctx);
        goto after_8;
    // 0x8001A27C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_8:
L_8001A280:
    // 0x8001A280: jal         0x8001BF20
    // 0x8001A284: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8001BF20(rdram, ctx);
        goto after_9;
    // 0x8001A284: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_9:
    // 0x8001A288: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8001A28C: sll         $v0, $s6, 16
    ctx->r2 = S32(ctx->r22 << 16);
    // 0x8001A290: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8001A294: slti        $v0, $v0, 0x18
    ctx->r2 = SIGNED(ctx->r2) < 0X18 ? 1 : 0;
    // 0x8001A298: beq         $v0, $zero, L_8001A2C4
    if (ctx->r2 == 0) {
        // 0x8001A29C: sll         $s0, $s3, 16
        ctx->r16 = S32(ctx->r19 << 16);
            goto L_8001A2C4;
    }
    // 0x8001A29C: sll         $s0, $s3, 16
    ctx->r16 = S32(ctx->r19 << 16);
    // 0x8001A2A0: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8001A2A4: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x8001A2A8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8001A2AC: mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A2B0: mflo        $s0
    ctx->r16 = lo;
    // 0x8001A2B4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8001A2B8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8001A2BC: j           L_8001A2E4
    // 0x8001A2C0: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
        goto L_8001A2E4;
    // 0x8001A2C0: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
L_8001A2C4:
    // 0x8001A2C4: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8001A2C8: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x8001A2CC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8001A2D0: mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A2D4: mflo        $s0
    ctx->r16 = lo;
    // 0x8001A2D8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8001A2DC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8001A2E0: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
L_8001A2E4:
    // 0x8001A2E4: jal         0x800078E0
    // 0x8001A2E8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    rs_memset(rdram, ctx);
        goto after_10;
    // 0x8001A2E8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_10:
    // 0x8001A2EC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8001A2F0: jal         0x800358B0
    // 0x8001A2F4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_11;
    // 0x8001A2F4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_11:
    // 0x8001A2F8: jal         0x8001BEC8
    // 0x8001A2FC: nop

    func_8001BEC8(rdram, ctx);
        goto after_12;
    // 0x8001A2FC: nop

    after_12:
    // 0x8001A300: jal         0x8001BCE4
    // 0x8001A304: nop

    func_8001BCE4(rdram, ctx);
        goto after_13;
    // 0x8001A304: nop

    after_13:
    // 0x8001A308: jal         0x8000273C
    // 0x8001A30C: nop

    getViModeType(rdram, ctx);
        goto after_14;
    // 0x8001A30C: nop

    after_14:
    // 0x8001A310: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8001A314: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8001A318: bne         $v0, $v1, L_8001A348
    if (ctx->r2 != ctx->r3) {
        // 0x8001A31C: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_8001A348;
    }
    // 0x8001A31C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8001A320: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001A324: lwc1        $f22, 0x7F0($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X7F0);
    // 0x8001A328: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001A32C: lwc1        $f20, 0x7F4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X7F4);
    // 0x8001A330: addiu       $s1, $zero, 0x17
    ctx->r17 = ADD32(0, 0X17);
    // 0x8001A334: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
    // 0x8001A338: beq         $v0, $zero, L_8001A358
    if (ctx->r2 == 0) {
        // 0x8001A33C: addu        $s0, $s2, $zero
        ctx->r16 = ADD32(ctx->r18, 0);
            goto L_8001A358;
    }
    // 0x8001A33C: addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
    // 0x8001A340: j           L_8001A358
    // 0x8001A344: addiu       $s0, $s2, 0x2
    ctx->r16 = ADD32(ctx->r18, 0X2);
        goto L_8001A358;
    // 0x8001A344: addiu       $s0, $s2, 0x2
    ctx->r16 = ADD32(ctx->r18, 0X2);
L_8001A348:
    // 0x8001A348: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001A34C: lwc1        $f22, 0x7F8($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X7F8);
    // 0x8001A350: addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
    // 0x8001A354: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
L_8001A358:
    // 0x8001A358: lbu         $t9, 0x187($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X187);
    // 0x8001A35C: beq         $t9, $zero, L_8001ACA8
    if (ctx->r25 == 0) {
        // 0x8001A360: nop
    
            goto L_8001ACA8;
    }
    // 0x8001A360: nop

    // 0x8001A364: beq         $s7, $zero, L_8001A8AC
    if (ctx->r23 == 0) {
        // 0x8001A368: nop
    
            goto L_8001A8AC;
    }
    // 0x8001A368: nop

    // 0x8001A36C: jal         0x8000273C
    // 0x8001A370: nop

    getViModeType(rdram, ctx);
        goto after_15;
    // 0x8001A370: nop

    after_15:
    // 0x8001A374: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8001A378: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001A37C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001A380: lbu         $v1, 0x7830($at)
    ctx->r3 = MEM_BU(ctx->r1, 0X7830);
    // 0x8001A384: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    // 0x8001A388: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001A38C: addiu       $a0, $a0, -0x6CD0
    ctx->r4 = ADD32(ctx->r4, -0X6CD0);
    // 0x8001A390: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001A394: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001A398: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001A39C: addu        $a2, $v0, $a0
    ctx->r6 = ADD32(ctx->r2, ctx->r4);
    // 0x8001A3A0: addiu       $t0, $a2, 0x50
    ctx->r8 = ADD32(ctx->r6, 0X50);
L_8001A3A4:
    // 0x8001A3A4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8001A3A8: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8001A3AC: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8001A3B0: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8001A3B4: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8001A3B8: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x8001A3BC: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x8001A3C0: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x8001A3C4: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001A3C8: bne         $a2, $t0, L_8001A3A4
    if (ctx->r6 != ctx->r8) {
        // 0x8001A3CC: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8001A3A4;
    }
    // 0x8001A3CC: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8001A3D0: jal         0x8000273C
    // 0x8001A3D4: nop

    getViModeType(rdram, ctx);
        goto after_16;
    // 0x8001A3D4: nop

    after_16:
    // 0x8001A3D8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8001A3DC: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001A3E0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001A3E4: lbu         $v1, 0x782C($at)
    ctx->r3 = MEM_BU(ctx->r1, 0X782C);
    // 0x8001A3E8: addiu       $a3, $sp, 0x108
    ctx->r7 = ADD32(ctx->r29, 0X108);
    // 0x8001A3EC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001A3F0: addiu       $a0, $a0, -0x6CD0
    ctx->r4 = ADD32(ctx->r4, -0X6CD0);
    // 0x8001A3F4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001A3F8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001A3FC: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001A400: addu        $a2, $v0, $a0
    ctx->r6 = ADD32(ctx->r2, ctx->r4);
    // 0x8001A404: addiu       $t0, $a2, 0x50
    ctx->r8 = ADD32(ctx->r6, 0X50);
L_8001A408:
    // 0x8001A408: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8001A40C: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8001A410: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8001A414: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8001A418: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8001A41C: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x8001A420: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x8001A424: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x8001A428: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001A42C: bne         $a2, $t0, L_8001A408
    if (ctx->r6 != ctx->r8) {
        // 0x8001A430: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8001A408;
    }
    // 0x8001A430: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8001A434: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8001A438: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    // 0x8001A43C: addiu       $t0, $sp, 0xB8
    ctx->r8 = ADD32(ctx->r29, 0XB8);
L_8001A440:
    // 0x8001A440: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8001A444: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8001A448: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8001A44C: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8001A450: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8001A454: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x8001A458: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x8001A45C: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x8001A460: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001A464: bne         $a2, $t0, L_8001A440
    if (ctx->r6 != ctx->r8) {
        // 0x8001A468: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8001A440;
    }
    // 0x8001A468: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8001A46C: addiu       $a3, $sp, 0xB8
    ctx->r7 = ADD32(ctx->r29, 0XB8);
    // 0x8001A470: addiu       $a2, $sp, 0x108
    ctx->r6 = ADD32(ctx->r29, 0X108);
    // 0x8001A474: addiu       $t0, $sp, 0x158
    ctx->r8 = ADD32(ctx->r29, 0X158);
L_8001A478:
    // 0x8001A478: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8001A47C: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8001A480: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8001A484: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8001A488: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8001A48C: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x8001A490: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x8001A494: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x8001A498: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001A49C: bne         $a2, $t0, L_8001A478
    if (ctx->r6 != ctx->r8) {
        // 0x8001A4A0: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8001A478;
    }
    // 0x8001A4A0: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8001A4A4: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x8001A4A8: addiu       $t3, $sp, 0x18
    ctx->r11 = ADD32(ctx->r29, 0X18);
    // 0x8001A4AC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001A4B0: lwc1        $f4, 0x7FC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7FC);
    // 0x8001A4B4: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x8001A4B8: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x8001A4BC: sll         $t7, $s1, 1
    ctx->r15 = S32(ctx->r17 << 1);
    // 0x8001A4C0: lui         $v1, 0x6666
    ctx->r3 = S32(0X6666 << 16);
    // 0x8001A4C4: ori         $v1, $v1, 0x6667
    ctx->r3 = ctx->r3 | 0X6667;
    // 0x8001A4C8: lui         $s1, 0xFFFF
    ctx->r17 = S32(0XFFFF << 16);
    // 0x8001A4CC: sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20 << 16);
    // 0x8001A4D0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001A4D4: sll         $t6, $a0, 9
    ctx->r14 = S32(ctx->r4 << 9);
    // 0x8001A4D8: sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19 << 16);
    // 0x8001A4DC: sra         $t4, $v0, 16
    ctx->r12 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8001A4E0: sll         $a1, $t4, 10
    ctx->r5 = S32(ctx->r12 << 10);
    // 0x8001A4E4: andi        $a2, $s5, 0xFFFF
    ctx->r6 = ctx->r21 & 0XFFFF;
    // 0x8001A4E8: mult        $a1, $v1
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A4EC: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
    // 0x8001A4F0: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x8001A4F4: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8001A4F8: addiu       $v1, $zero, 0xF0
    ctx->r3 = ADD32(0, 0XF0);
    // 0x8001A4FC: subu        $t0, $v1, $v0
    ctx->r8 = SUB32(ctx->r3, ctx->r2);
    // 0x8001A500: sll         $t5, $a0, 10
    ctx->r13 = S32(ctx->r4 << 10);
    // 0x8001A504: mtc1        $a2, $f0
    ctx->f0.u32l = ctx->r6;
    // 0x8001A508: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001A50C: sra         $a1, $a1, 31
    ctx->r5 = S32(SIGNED(ctx->r5) >> 31);
    // 0x8001A510: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001A514: mfhi        $t9
    ctx->r25 = hi;
    // 0x8001A518: sra         $v0, $t9, 8
    ctx->r2 = S32(SIGNED(ctx->r25) >> 8);
    // 0x8001A51C: subu        $s2, $v0, $a1
    ctx->r18 = SUB32(ctx->r2, ctx->r5);
L_8001A520:
    // 0x8001A520: andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
    // 0x8001A524: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001A528: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001A52C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001A530: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x8001A534: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8001A538: bc1t        L_8001A550
    if (c1cs) {
        // 0x8001A53C: addiu       $a1, $v0, 0x30
        ctx->r5 = ADD32(ctx->r2, 0X30);
            goto L_8001A550;
    }
    // 0x8001A53C: addiu       $a1, $v0, 0x30
    ctx->r5 = ADD32(ctx->r2, 0X30);
    // 0x8001A540: trunc.w.s   $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8001A544: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x8001A548: j           L_8001A560
    // 0x8001A54C: nop

        goto L_8001A560;
    // 0x8001A54C: nop

L_8001A550:
    // 0x8001A550: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8001A554: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001A558: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8001A55C: or          $v1, $v1, $t2
    ctx->r3 = ctx->r3 | ctx->r10;
L_8001A560:
    // 0x8001A560: mtc1        $s0, $f0
    ctx->f0.u32l = ctx->r16;
    // 0x8001A564: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001A568: mul.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001A56C: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8001A570: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8001A574: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001A578: bc1t        L_8001A590
    if (c1cs) {
        // 0x8001A57C: sh          $v0, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r2;
            goto L_8001A590;
    }
    // 0x8001A57C: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8001A580: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001A584: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x8001A588: j           L_8001A5A0
    // 0x8001A58C: nop

        goto L_8001A5A0;
    // 0x8001A58C: nop

L_8001A590:
    // 0x8001A590: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8001A594: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001A598: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8001A59C: or          $v1, $v1, $t2
    ctx->r3 = ctx->r3 | ctx->r10;
L_8001A5A0:
    // 0x8001A5A0: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x8001A5A4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8001A5A8: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x8001A5AC: mtc1        $a2, $f0
    ctx->f0.u32l = ctx->r6;
    // 0x8001A5B0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001A5B4: sh          $v0, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r2;
    // 0x8001A5B8: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x8001A5BC: mul.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001A5C0: subu        $v1, $v1, $t7
    ctx->r3 = SUB32(ctx->r3, ctx->r15);
    // 0x8001A5C4: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8001A5C8: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
    // 0x8001A5CC: andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
    // 0x8001A5D0: sh          $v0, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r2;
    // 0x8001A5D4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001A5D8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001A5DC: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001A5E0: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8001A5E4: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8001A5E8: bc1t        L_8001A600
    if (c1cs) {
        // 0x8001A5EC: addiu       $a1, $v0, 0x44
        ctx->r5 = ADD32(ctx->r2, 0X44);
            goto L_8001A600;
    }
    // 0x8001A5EC: addiu       $a1, $v0, 0x44
    ctx->r5 = ADD32(ctx->r2, 0X44);
    // 0x8001A5F0: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001A5F4: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x8001A5F8: j           L_8001A610
    // 0x8001A5FC: nop

        goto L_8001A610;
    // 0x8001A5FC: nop

L_8001A600:
    // 0x8001A600: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8001A604: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001A608: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8001A60C: or          $v1, $v1, $t2
    ctx->r3 = ctx->r3 | ctx->r10;
L_8001A610:
    // 0x8001A610: mtc1        $s0, $f0
    ctx->f0.u32l = ctx->r16;
    // 0x8001A614: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001A618: mul.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001A61C: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8001A620: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8001A624: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001A628: bc1t        L_8001A640
    if (c1cs) {
        // 0x8001A62C: sh          $v0, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r2;
            goto L_8001A640;
    }
    // 0x8001A62C: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8001A630: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001A634: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x8001A638: j           L_8001A650
    // 0x8001A63C: nop

        goto L_8001A650;
    // 0x8001A63C: nop

L_8001A640:
    // 0x8001A640: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8001A644: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001A648: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8001A64C: or          $v1, $v1, $t2
    ctx->r3 = ctx->r3 | ctx->r10;
L_8001A650:
    // 0x8001A650: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x8001A654: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8001A658: sh          $v0, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r2;
    // 0x8001A65C: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8001A660: lhu         $v1, 0x2($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X2);
    // 0x8001A664: subu        $v0, $v0, $t7
    ctx->r2 = SUB32(ctx->r2, ctx->r15);
    // 0x8001A668: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x8001A66C: sh          $v1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r3;
    // 0x8001A670: andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
    // 0x8001A674: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8001A678: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001A67C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001A680: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001A684: addu        $a1, $t3, $v0
    ctx->r5 = ADD32(ctx->r11, ctx->r2);
    // 0x8001A688: lw          $v1, 0x2C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X2C);
    // 0x8001A68C: lw          $a0, 0x40($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X40);
    // 0x8001A690: sll         $v0, $t4, 2
    ctx->r2 = S32(ctx->r12 << 2);
    // 0x8001A694: sw          $v0, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->r2;
    // 0x8001A698: sll         $v0, $t4, 3
    ctx->r2 = S32(ctx->r12 << 3);
    // 0x8001A69C: sw          $v0, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->r2;
    // 0x8001A6A0: sw          $s2, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r18;
    // 0x8001A6A4: and         $v1, $v1, $s1
    ctx->r3 = ctx->r3 & ctx->r17;
    // 0x8001A6A8: and         $a0, $a0, $s1
    ctx->r4 = ctx->r4 & ctx->r17;
    // 0x8001A6AC: sw          $v1, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r3;
    // 0x8001A6B0: beq         $fp, $zero, L_8001A794
    if (ctx->r30 == 0) {
        // 0x8001A6B4: sw          $a0, 0x40($a1)
        MEM_W(0X40, ctx->r5) = ctx->r4;
            goto L_8001A794;
    }
    // 0x8001A6B4: sw          $a0, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->r4;
    // 0x8001A6B8: div         $zero, $t6, $t0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r8)));
    // 0x8001A6BC: bne         $t0, $zero, L_8001A6C8
    if (ctx->r8 != 0) {
        // 0x8001A6C0: nop
    
            goto L_8001A6C8;
    }
    // 0x8001A6C0: nop

    // 0x8001A6C4: break       7
    do_break(2147591876);
L_8001A6C8:
    // 0x8001A6C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001A6CC: bne         $t0, $at, L_8001A6E0
    if (ctx->r8 != ctx->r1) {
        // 0x8001A6D0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001A6E0;
    }
    // 0x8001A6D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001A6D4: bne         $t6, $at, L_8001A6E0
    if (ctx->r14 != ctx->r1) {
        // 0x8001A6D8: nop
    
            goto L_8001A6E0;
    }
    // 0x8001A6D8: nop

    // 0x8001A6DC: break       6
    do_break(2147591900);
L_8001A6E0:
    // 0x8001A6E0: mflo        $v0
    ctx->r2 = lo;
    // 0x8001A6E4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8001A6E8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001A6EC: mul.s       $f2, $f22, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8001A6F0: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8001A6F4: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8001A6F8: sll         $v0, $t4, 1
    ctx->r2 = S32(ctx->r12 << 1);
    // 0x8001A6FC: bc1t        L_8001A714
    if (c1cs) {
        // 0x8001A700: sw          $v0, 0x8($a1)
        MEM_W(0X8, ctx->r5) = ctx->r2;
            goto L_8001A714;
    }
    // 0x8001A700: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x8001A704: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001A708: mfc1        $a0, $f0
    ctx->r4 = (int32_t)ctx->f0.u32l;
    // 0x8001A70C: j           L_8001A724
    // 0x8001A710: nop

        goto L_8001A724;
    // 0x8001A710: nop

L_8001A714:
    // 0x8001A714: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8001A718: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001A71C: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x8001A720: or          $a0, $a0, $t2
    ctx->r4 = ctx->r4 | ctx->r10;
L_8001A724:
    // 0x8001A724: div         $zero, $t6, $t0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r8)));
    // 0x8001A728: bne         $t0, $zero, L_8001A734
    if (ctx->r8 != 0) {
        // 0x8001A72C: nop
    
            goto L_8001A734;
    }
    // 0x8001A72C: nop

    // 0x8001A730: break       7
    do_break(2147591984);
L_8001A734:
    // 0x8001A734: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001A738: bne         $t0, $at, L_8001A74C
    if (ctx->r8 != ctx->r1) {
        // 0x8001A73C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001A74C;
    }
    // 0x8001A73C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001A740: bne         $t6, $at, L_8001A74C
    if (ctx->r14 != ctx->r1) {
        // 0x8001A744: nop
    
            goto L_8001A74C;
    }
    // 0x8001A744: nop

    // 0x8001A748: break       6
    do_break(2147592008);
L_8001A74C:
    // 0x8001A74C: mflo        $v0
    ctx->r2 = lo;
    // 0x8001A750: lw          $v1, 0x2C($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X2C);
    // 0x8001A754: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8001A758: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001A75C: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8001A760: mul.s       $f2, $f22, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8001A764: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8001A768: sw          $v1, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r3;
    // 0x8001A76C: andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
    // 0x8001A770: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001A774: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001A778: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001A77C: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8001A780: addu        $a1, $t3, $v0
    ctx->r5 = ADD32(ctx->r11, ctx->r2);
    // 0x8001A784: bc1f        L_8001A864
    if (!c1cs) {
        // 0x8001A788: addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
            goto L_8001A864;
    }
    // 0x8001A788: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // 0x8001A78C: j           L_8001A878
    // 0x8001A790: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
        goto L_8001A878;
    // 0x8001A790: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
L_8001A794:
    // 0x8001A794: div         $zero, $t5, $t0
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r8)));
    // 0x8001A798: bne         $t0, $zero, L_8001A7A4
    if (ctx->r8 != 0) {
        // 0x8001A79C: nop
    
            goto L_8001A7A4;
    }
    // 0x8001A79C: nop

    // 0x8001A7A0: break       7
    do_break(2147592096);
L_8001A7A4:
    // 0x8001A7A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001A7A8: bne         $t0, $at, L_8001A7BC
    if (ctx->r8 != ctx->r1) {
        // 0x8001A7AC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001A7BC;
    }
    // 0x8001A7AC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001A7B0: bne         $t5, $at, L_8001A7BC
    if (ctx->r13 != ctx->r1) {
        // 0x8001A7B4: nop
    
            goto L_8001A7BC;
    }
    // 0x8001A7B4: nop

    // 0x8001A7B8: break       6
    do_break(2147592120);
L_8001A7BC:
    // 0x8001A7BC: mflo        $v0
    ctx->r2 = lo;
    // 0x8001A7C0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8001A7C4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001A7C8: mul.s       $f2, $f22, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8001A7CC: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8001A7D0: sw          $t4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r12;
    // 0x8001A7D4: bc1t        L_8001A7EC
    if (c1cs) {
        // 0x8001A7D8: addu        $a3, $a1, $zero
        ctx->r7 = ADD32(ctx->r5, 0);
            goto L_8001A7EC;
    }
    // 0x8001A7D8: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8001A7DC: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001A7E0: mfc1        $a0, $f0
    ctx->r4 = (int32_t)ctx->f0.u32l;
    // 0x8001A7E4: j           L_8001A7FC
    // 0x8001A7E8: nop

        goto L_8001A7FC;
    // 0x8001A7E8: nop

L_8001A7EC:
    // 0x8001A7EC: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8001A7F0: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001A7F4: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x8001A7F8: or          $a0, $a0, $t2
    ctx->r4 = ctx->r4 | ctx->r10;
L_8001A7FC:
    // 0x8001A7FC: div         $zero, $t5, $t0
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r8)));
    // 0x8001A800: bne         $t0, $zero, L_8001A80C
    if (ctx->r8 != 0) {
        // 0x8001A804: nop
    
            goto L_8001A80C;
    }
    // 0x8001A804: nop

    // 0x8001A808: break       7
    do_break(2147592200);
L_8001A80C:
    // 0x8001A80C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001A810: bne         $t0, $at, L_8001A824
    if (ctx->r8 != ctx->r1) {
        // 0x8001A814: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001A824;
    }
    // 0x8001A814: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001A818: bne         $t5, $at, L_8001A824
    if (ctx->r13 != ctx->r1) {
        // 0x8001A81C: nop
    
            goto L_8001A824;
    }
    // 0x8001A81C: nop

    // 0x8001A820: break       6
    do_break(2147592224);
L_8001A824:
    // 0x8001A824: mflo        $v0
    ctx->r2 = lo;
    // 0x8001A828: lw          $v1, 0x2C($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X2C);
    // 0x8001A82C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8001A830: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001A834: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8001A838: mul.s       $f2, $f22, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8001A83C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8001A840: sw          $v1, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r3;
    // 0x8001A844: andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
    // 0x8001A848: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001A84C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001A850: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001A854: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8001A858: addu        $a1, $t3, $v0
    ctx->r5 = ADD32(ctx->r11, ctx->r2);
    // 0x8001A85C: bc1t        L_8001A874
    if (c1cs) {
        // 0x8001A860: addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
            goto L_8001A874;
    }
    // 0x8001A860: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
L_8001A864:
    // 0x8001A864: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001A868: mfc1        $a0, $f0
    ctx->r4 = (int32_t)ctx->f0.u32l;
    // 0x8001A86C: j           L_8001A884
    // 0x8001A870: nop

        goto L_8001A884;
    // 0x8001A870: nop

L_8001A874:
    // 0x8001A874: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
L_8001A878:
    // 0x8001A878: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001A87C: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x8001A880: or          $a0, $a0, $t2
    ctx->r4 = ctx->r4 | ctx->r10;
L_8001A884:
    // 0x8001A884: lw          $v1, 0x40($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X40);
    // 0x8001A888: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8001A88C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8001A890: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001A894: andi        $v0, $t1, 0xFFFF
    ctx->r2 = ctx->r9 & 0XFFFF;
    // 0x8001A898: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x8001A89C: bne         $v0, $zero, L_8001A520
    if (ctx->r2 != 0) {
        // 0x8001A8A0: sw          $v1, 0x40($a1)
        MEM_W(0X40, ctx->r5) = ctx->r3;
            goto L_8001A520;
    }
    // 0x8001A8A0: sw          $v1, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->r3;
    // 0x8001A8A4: j           L_8001B664
    // 0x8001A8A8: nop

        goto L_8001B664;
    // 0x8001A8A8: nop

L_8001A8AC:
    // 0x8001A8AC: jal         0x8000273C
    // 0x8001A8B0: nop

    getViModeType(rdram, ctx);
        goto after_17;
    // 0x8001A8B0: nop

    after_17:
    // 0x8001A8B4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8001A8B8: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001A8BC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001A8C0: lbu         $v1, 0x7818($at)
    ctx->r3 = MEM_BU(ctx->r1, 0X7818);
    // 0x8001A8C4: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    // 0x8001A8C8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001A8CC: addiu       $a0, $a0, -0x6CD0
    ctx->r4 = ADD32(ctx->r4, -0X6CD0);
    // 0x8001A8D0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001A8D4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001A8D8: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001A8DC: addu        $a2, $v0, $a0
    ctx->r6 = ADD32(ctx->r2, ctx->r4);
    // 0x8001A8E0: addiu       $t0, $a2, 0x50
    ctx->r8 = ADD32(ctx->r6, 0X50);
L_8001A8E4:
    // 0x8001A8E4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8001A8E8: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8001A8EC: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8001A8F0: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8001A8F4: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8001A8F8: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x8001A8FC: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x8001A900: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x8001A904: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001A908: bne         $a2, $t0, L_8001A8E4
    if (ctx->r6 != ctx->r8) {
        // 0x8001A90C: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8001A8E4;
    }
    // 0x8001A90C: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8001A910: addiu       $a3, $sp, 0x108
    ctx->r7 = ADD32(ctx->r29, 0X108);
    // 0x8001A914: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    // 0x8001A918: addiu       $t0, $sp, 0xB8
    ctx->r8 = ADD32(ctx->r29, 0XB8);
L_8001A91C:
    // 0x8001A91C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8001A920: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8001A924: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8001A928: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8001A92C: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8001A930: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x8001A934: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x8001A938: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x8001A93C: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001A940: bne         $a2, $t0, L_8001A91C
    if (ctx->r6 != ctx->r8) {
        // 0x8001A944: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8001A91C;
    }
    // 0x8001A944: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8001A948: jal         0x8000273C
    // 0x8001A94C: nop

    getViModeType(rdram, ctx);
        goto after_18;
    // 0x8001A94C: nop

    after_18:
    // 0x8001A950: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8001A954: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001A958: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001A95C: lbu         $v1, 0x7814($at)
    ctx->r3 = MEM_BU(ctx->r1, 0X7814);
    // 0x8001A960: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8001A964: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001A968: addiu       $a0, $a0, -0x6CD0
    ctx->r4 = ADD32(ctx->r4, -0X6CD0);
    // 0x8001A96C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001A970: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001A974: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001A978: addu        $a2, $v0, $a0
    ctx->r6 = ADD32(ctx->r2, ctx->r4);
    // 0x8001A97C: addiu       $t0, $a2, 0x50
    ctx->r8 = ADD32(ctx->r6, 0X50);
L_8001A980:
    // 0x8001A980: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8001A984: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8001A988: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8001A98C: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8001A990: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8001A994: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x8001A998: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x8001A99C: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x8001A9A0: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001A9A4: bne         $a2, $t0, L_8001A980
    if (ctx->r6 != ctx->r8) {
        // 0x8001A9A8: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8001A980;
    }
    // 0x8001A9A8: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8001A9AC: addiu       $a3, $sp, 0xB8
    ctx->r7 = ADD32(ctx->r29, 0XB8);
    // 0x8001A9B0: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x8001A9B4: addiu       $t0, $sp, 0x68
    ctx->r8 = ADD32(ctx->r29, 0X68);
L_8001A9B8:
    // 0x8001A9B8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8001A9BC: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8001A9C0: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8001A9C4: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8001A9C8: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8001A9CC: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x8001A9D0: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x8001A9D4: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x8001A9D8: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001A9DC: bne         $a2, $t0, L_8001A9B8
    if (ctx->r6 != ctx->r8) {
        // 0x8001A9E0: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8001A9B8;
    }
    // 0x8001A9E0: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8001A9E4: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x8001A9E8: addiu       $t0, $sp, 0x18
    ctx->r8 = ADD32(ctx->r29, 0X18);
    // 0x8001A9EC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001A9F0: lwc1        $f4, 0x800($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X800);
    // 0x8001A9F4: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x8001A9F8: andi        $t6, $s0, 0xFFFF
    ctx->r14 = ctx->r16 & 0XFFFF;
    // 0x8001A9FC: sll         $a3, $s1, 1
    ctx->r7 = S32(ctx->r17 << 1);
    // 0x8001AA00: sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19 << 16);
    // 0x8001AA04: sra         $t5, $v0, 16
    ctx->r13 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8001AA08: sll         $s0, $t5, 2
    ctx->r16 = S32(ctx->r13 << 2);
    // 0x8001AA0C: lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    // 0x8001AA10: ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // 0x8001AA14: sll         $a0, $t5, 10
    ctx->r4 = S32(ctx->r13 << 10);
    // 0x8001AA18: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001AA1C: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x8001AA20: sra         $t4, $v0, 6
    ctx->r12 = S32(SIGNED(ctx->r2) >> 6);
    // 0x8001AA24: andi        $a2, $s5, 0xFFFF
    ctx->r6 = ctx->r21 & 0XFFFF;
    // 0x8001AA28: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
    // 0x8001AA2C: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x8001AA30: addiu       $v1, $zero, 0xF0
    ctx->r3 = ADD32(0, 0XF0);
    // 0x8001AA34: subu        $t3, $v1, $v0
    ctx->r11 = SUB32(ctx->r3, ctx->r2);
    // 0x8001AA38: mtc1        $a2, $f0
    ctx->f0.u32l = ctx->r6;
    // 0x8001AA3C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001AA40: sra         $a0, $a0, 31
    ctx->r4 = S32(SIGNED(ctx->r4) >> 31);
    // 0x8001AA44: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001AA48: mfhi        $t9
    ctx->r25 = hi;
    // 0x8001AA4C: sra         $v0, $t9, 8
    ctx->r2 = S32(SIGNED(ctx->r25) >> 8);
    // 0x8001AA50: subu        $t7, $v0, $a0
    ctx->r15 = SUB32(ctx->r2, ctx->r4);
    // 0x8001AA54: andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
L_8001AA58:
    // 0x8001AA58: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001AA5C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001AA60: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001AA64: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x8001AA68: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x8001AA6C: bc1t        L_8001AA84
    if (c1cs) {
        // 0x8001AA70: addiu       $a1, $v0, 0x30
        ctx->r5 = ADD32(ctx->r2, 0X30);
            goto L_8001AA84;
    }
    // 0x8001AA70: addiu       $a1, $v0, 0x30
    ctx->r5 = ADD32(ctx->r2, 0X30);
    // 0x8001AA74: trunc.w.s   $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8001AA78: mfc1        $a0, $f0
    ctx->r4 = (int32_t)ctx->f0.u32l;
    // 0x8001AA7C: j           L_8001AA94
    // 0x8001AA80: nop

        goto L_8001AA94;
    // 0x8001AA80: nop

L_8001AA84:
    // 0x8001AA84: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8001AA88: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001AA8C: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x8001AA90: or          $a0, $a0, $t2
    ctx->r4 = ctx->r4 | ctx->r10;
L_8001AA94:
    // 0x8001AA94: mtc1        $t6, $f0
    ctx->f0.u32l = ctx->r14;
    // 0x8001AA98: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001AA9C: mul.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001AAA0: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x8001AAA4: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8001AAA8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001AAAC: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8001AAB0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001AAB4: bc1t        L_8001AACC
    if (c1cs) {
        // 0x8001AAB8: sh          $v1, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r3;
            goto L_8001AACC;
    }
    // 0x8001AAB8: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
    // 0x8001AABC: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001AAC0: mfc1        $a0, $f0
    ctx->r4 = (int32_t)ctx->f0.u32l;
    // 0x8001AAC4: j           L_8001AADC
    // 0x8001AAC8: nop

        goto L_8001AADC;
    // 0x8001AAC8: nop

L_8001AACC:
    // 0x8001AACC: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8001AAD0: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001AAD4: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x8001AAD8: or          $a0, $a0, $t2
    ctx->r4 = ctx->r4 | ctx->r10;
L_8001AADC:
    // 0x8001AADC: lhu         $v1, 0x2($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X2);
    // 0x8001AAE0: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8001AAE4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001AAE8: mtc1        $a2, $f0
    ctx->f0.u32l = ctx->r6;
    // 0x8001AAEC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001AAF0: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8001AAF4: sh          $v1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r3;
    // 0x8001AAF8: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x8001AAFC: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x8001AB00: mul.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001AB04: subu        $v1, $v1, $a3
    ctx->r3 = SUB32(ctx->r3, ctx->r7);
    // 0x8001AB08: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8001AB0C: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
    // 0x8001AB10: andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
    // 0x8001AB14: sh          $v0, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r2;
    // 0x8001AB18: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001AB1C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001AB20: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001AB24: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8001AB28: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x8001AB2C: bc1t        L_8001AB44
    if (c1cs) {
        // 0x8001AB30: addiu       $a1, $v0, 0x44
        ctx->r5 = ADD32(ctx->r2, 0X44);
            goto L_8001AB44;
    }
    // 0x8001AB30: addiu       $a1, $v0, 0x44
    ctx->r5 = ADD32(ctx->r2, 0X44);
    // 0x8001AB34: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001AB38: mfc1        $a0, $f0
    ctx->r4 = (int32_t)ctx->f0.u32l;
    // 0x8001AB3C: j           L_8001AB54
    // 0x8001AB40: nop

        goto L_8001AB54;
    // 0x8001AB40: nop

L_8001AB44:
    // 0x8001AB44: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8001AB48: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001AB4C: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x8001AB50: or          $a0, $a0, $t2
    ctx->r4 = ctx->r4 | ctx->r10;
L_8001AB54:
    // 0x8001AB54: mtc1        $t6, $f0
    ctx->f0.u32l = ctx->r14;
    // 0x8001AB58: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001AB5C: mul.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001AB60: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x8001AB64: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8001AB68: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001AB6C: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8001AB70: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001AB74: bc1t        L_8001AB8C
    if (c1cs) {
        // 0x8001AB78: sh          $v1, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r3;
            goto L_8001AB8C;
    }
    // 0x8001AB78: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
    // 0x8001AB7C: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001AB80: mfc1        $a0, $f0
    ctx->r4 = (int32_t)ctx->f0.u32l;
    // 0x8001AB84: j           L_8001AB9C
    // 0x8001AB88: nop

        goto L_8001AB9C;
    // 0x8001AB88: nop

L_8001AB8C:
    // 0x8001AB8C: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8001AB90: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001AB94: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x8001AB98: or          $a0, $a0, $t2
    ctx->r4 = ctx->r4 | ctx->r10;
L_8001AB9C:
    // 0x8001AB9C: lhu         $v1, 0x2($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X2);
    // 0x8001ABA0: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8001ABA4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001ABA8: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8001ABAC: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8001ABB0: sh          $v1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r3;
    // 0x8001ABB4: lhu         $v1, 0x2($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X2);
    // 0x8001ABB8: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x8001ABBC: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x8001ABC0: sh          $v1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r3;
    // 0x8001ABC4: andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
    // 0x8001ABC8: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8001ABCC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001ABD0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001ABD4: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001ABD8: addu        $v1, $t0, $v0
    ctx->r3 = ADD32(ctx->r8, ctx->r2);
    // 0x8001ABDC: beq         $a2, $zero, L_8001ABEC
    if (ctx->r6 == 0) {
        // 0x8001ABE0: addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
            goto L_8001ABEC;
    }
    // 0x8001ABE0: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x8001ABE4: j           L_8001ABF0
    // 0x8001ABE8: sw          $s0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r16;
        goto L_8001ABF0;
    // 0x8001ABE8: sw          $s0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r16;
L_8001ABEC:
    // 0x8001ABEC: sw          $zero, 0x28($v1)
    MEM_W(0X28, ctx->r3) = 0;
L_8001ABF0:
    // 0x8001ABF0: div         $zero, $t4, $t3
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r11)));
    // 0x8001ABF4: bne         $t3, $zero, L_8001AC00
    if (ctx->r11 != 0) {
        // 0x8001ABF8: nop
    
            goto L_8001AC00;
    }
    // 0x8001ABF8: nop

    // 0x8001ABFC: break       7
    do_break(2147593212);
L_8001AC00:
    // 0x8001AC00: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001AC04: bne         $t3, $at, L_8001AC18
    if (ctx->r11 != ctx->r1) {
        // 0x8001AC08: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001AC18;
    }
    // 0x8001AC08: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001AC0C: bne         $t4, $at, L_8001AC18
    if (ctx->r12 != ctx->r1) {
        // 0x8001AC10: nop
    
            goto L_8001AC18;
    }
    // 0x8001AC10: nop

    // 0x8001AC14: break       6
    do_break(2147593236);
L_8001AC18:
    // 0x8001AC18: mflo        $a0
    ctx->r4 = lo;
    // 0x8001AC1C: lw          $v0, 0x28($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X28);
    // 0x8001AC20: sw          $v0, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->r2;
    // 0x8001AC24: sw          $v0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r2;
    // 0x8001AC28: andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
    // 0x8001AC2C: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x8001AC30: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001AC34: mul.s       $f2, $f22, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8001AC38: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001AC3C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001AC40: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001AC44: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x8001AC48: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
    // 0x8001AC4C: sw          $t7, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r15;
    // 0x8001AC50: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8001AC54: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8001AC58: bc1t        L_8001AC70
    if (c1cs) {
        // 0x8001AC5C: addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
            goto L_8001AC70;
    }
    // 0x8001AC5C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8001AC60: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001AC64: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x8001AC68: j           L_8001AC84
    // 0x8001AC6C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
        goto L_8001AC84;
    // 0x8001AC6C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_8001AC70:
    // 0x8001AC70: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8001AC74: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001AC78: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8001AC7C: or          $v1, $v1, $t2
    ctx->r3 = ctx->r3 | ctx->r10;
    // 0x8001AC80: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_8001AC84:
    // 0x8001AC84: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x8001AC88: sw          $v0, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r2;
    // 0x8001AC8C: sw          $v0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r2;
    // 0x8001AC90: andi        $v0, $t1, 0xFFFF
    ctx->r2 = ctx->r9 & 0XFFFF;
    // 0x8001AC94: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x8001AC98: bne         $v0, $zero, L_8001AA58
    if (ctx->r2 != 0) {
        // 0x8001AC9C: andi        $v1, $t1, 0xFFFF
        ctx->r3 = ctx->r9 & 0XFFFF;
            goto L_8001AA58;
    }
    // 0x8001AC9C: andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
    // 0x8001ACA0: j           L_8001B63C
    // 0x8001ACA4: sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19 << 16);
        goto L_8001B63C;
    // 0x8001ACA4: sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19 << 16);
L_8001ACA8:
    // 0x8001ACA8: beq         $s7, $zero, L_8001B244
    if (ctx->r23 == 0) {
        // 0x8001ACAC: nop
    
            goto L_8001B244;
    }
    // 0x8001ACAC: nop

    // 0x8001ACB0: jal         0x8000273C
    // 0x8001ACB4: nop

    getViModeType(rdram, ctx);
        goto after_19;
    // 0x8001ACB4: nop

    after_19:
    // 0x8001ACB8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8001ACBC: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001ACC0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001ACC4: lbu         $v1, 0x7828($at)
    ctx->r3 = MEM_BU(ctx->r1, 0X7828);
    // 0x8001ACC8: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    // 0x8001ACCC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001ACD0: addiu       $a0, $a0, -0x6CD0
    ctx->r4 = ADD32(ctx->r4, -0X6CD0);
    // 0x8001ACD4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001ACD8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001ACDC: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001ACE0: addu        $a2, $v0, $a0
    ctx->r6 = ADD32(ctx->r2, ctx->r4);
    // 0x8001ACE4: addiu       $t0, $a2, 0x50
    ctx->r8 = ADD32(ctx->r6, 0X50);
L_8001ACE8:
    // 0x8001ACE8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8001ACEC: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8001ACF0: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8001ACF4: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8001ACF8: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8001ACFC: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x8001AD00: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x8001AD04: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x8001AD08: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001AD0C: bne         $a2, $t0, L_8001ACE8
    if (ctx->r6 != ctx->r8) {
        // 0x8001AD10: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8001ACE8;
    }
    // 0x8001AD10: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8001AD14: jal         0x8000273C
    // 0x8001AD18: nop

    getViModeType(rdram, ctx);
        goto after_20;
    // 0x8001AD18: nop

    after_20:
    // 0x8001AD1C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8001AD20: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001AD24: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001AD28: lbu         $v1, 0x7824($at)
    ctx->r3 = MEM_BU(ctx->r1, 0X7824);
    // 0x8001AD2C: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8001AD30: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001AD34: addiu       $a0, $a0, -0x6CD0
    ctx->r4 = ADD32(ctx->r4, -0X6CD0);
    // 0x8001AD38: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001AD3C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001AD40: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001AD44: addu        $a2, $v0, $a0
    ctx->r6 = ADD32(ctx->r2, ctx->r4);
    // 0x8001AD48: addiu       $t0, $a2, 0x50
    ctx->r8 = ADD32(ctx->r6, 0X50);
L_8001AD4C:
    // 0x8001AD4C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8001AD50: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8001AD54: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8001AD58: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8001AD5C: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8001AD60: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x8001AD64: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x8001AD68: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x8001AD6C: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001AD70: bne         $a2, $t0, L_8001AD4C
    if (ctx->r6 != ctx->r8) {
        // 0x8001AD74: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8001AD4C;
    }
    // 0x8001AD74: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8001AD78: jal         0x8000273C
    // 0x8001AD7C: nop

    getViModeType(rdram, ctx);
        goto after_21;
    // 0x8001AD7C: nop

    after_21:
    // 0x8001AD80: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8001AD84: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001AD88: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001AD8C: lbu         $v1, 0x7820($at)
    ctx->r3 = MEM_BU(ctx->r1, 0X7820);
    // 0x8001AD90: addiu       $a3, $sp, 0x108
    ctx->r7 = ADD32(ctx->r29, 0X108);
    // 0x8001AD94: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001AD98: addiu       $a0, $a0, -0x6CD0
    ctx->r4 = ADD32(ctx->r4, -0X6CD0);
    // 0x8001AD9C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001ADA0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001ADA4: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001ADA8: addu        $a2, $v0, $a0
    ctx->r6 = ADD32(ctx->r2, ctx->r4);
    // 0x8001ADAC: addiu       $t0, $a2, 0x50
    ctx->r8 = ADD32(ctx->r6, 0X50);
L_8001ADB0:
    // 0x8001ADB0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8001ADB4: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8001ADB8: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8001ADBC: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8001ADC0: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8001ADC4: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x8001ADC8: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x8001ADCC: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x8001ADD0: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001ADD4: bne         $a2, $t0, L_8001ADB0
    if (ctx->r6 != ctx->r8) {
        // 0x8001ADD8: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8001ADB0;
    }
    // 0x8001ADD8: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8001ADDC: jal         0x8000273C
    // 0x8001ADE0: nop

    getViModeType(rdram, ctx);
        goto after_22;
    // 0x8001ADE0: nop

    after_22:
    // 0x8001ADE4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8001ADE8: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001ADEC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001ADF0: lbu         $v1, 0x781C($at)
    ctx->r3 = MEM_BU(ctx->r1, 0X781C);
    // 0x8001ADF4: addiu       $a3, $sp, 0xB8
    ctx->r7 = ADD32(ctx->r29, 0XB8);
    // 0x8001ADF8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001ADFC: addiu       $a0, $a0, -0x6CD0
    ctx->r4 = ADD32(ctx->r4, -0X6CD0);
    // 0x8001AE00: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001AE04: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001AE08: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001AE0C: addu        $a2, $v0, $a0
    ctx->r6 = ADD32(ctx->r2, ctx->r4);
    // 0x8001AE10: addiu       $t0, $a2, 0x50
    ctx->r8 = ADD32(ctx->r6, 0X50);
L_8001AE14:
    // 0x8001AE14: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8001AE18: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8001AE1C: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8001AE20: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8001AE24: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8001AE28: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x8001AE2C: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x8001AE30: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x8001AE34: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001AE38: bne         $a2, $t0, L_8001AE14
    if (ctx->r6 != ctx->r8) {
        // 0x8001AE3C: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8001AE14;
    }
    // 0x8001AE3C: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8001AE40: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x8001AE44: addiu       $t3, $sp, 0x18
    ctx->r11 = ADD32(ctx->r29, 0X18);
    // 0x8001AE48: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001AE4C: lwc1        $f4, 0x804($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X804);
    // 0x8001AE50: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x8001AE54: andi        $t8, $s0, 0xFFFF
    ctx->r24 = ctx->r16 & 0XFFFF;
    // 0x8001AE58: sll         $t6, $s1, 1
    ctx->r14 = S32(ctx->r17 << 1);
    // 0x8001AE5C: sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19 << 16);
    // 0x8001AE60: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8001AE64: sll         $s0, $t7, 1
    ctx->r16 = S32(ctx->r15 << 1);
    // 0x8001AE68: lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    // 0x8001AE6C: ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // 0x8001AE70: lui         $s1, 0xFFFF
    ctx->r17 = S32(0XFFFF << 16);
    // 0x8001AE74: sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20 << 16);
    // 0x8001AE78: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001AE7C: sll         $t5, $a0, 9
    ctx->r13 = S32(ctx->r4 << 9);
    // 0x8001AE80: sll         $a1, $t7, 10
    ctx->r5 = S32(ctx->r15 << 10);
    // 0x8001AE84: andi        $a2, $s5, 0xFFFF
    ctx->r6 = ctx->r21 & 0XFFFF;
    // 0x8001AE88: mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001AE8C: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
    // 0x8001AE90: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x8001AE94: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8001AE98: addiu       $v1, $zero, 0xF0
    ctx->r3 = ADD32(0, 0XF0);
    // 0x8001AE9C: subu        $t0, $v1, $v0
    ctx->r8 = SUB32(ctx->r3, ctx->r2);
    // 0x8001AEA0: sll         $t4, $a0, 10
    ctx->r12 = S32(ctx->r4 << 10);
    // 0x8001AEA4: mtc1        $a2, $f0
    ctx->f0.u32l = ctx->r6;
    // 0x8001AEA8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001AEAC: sra         $a1, $a1, 31
    ctx->r5 = S32(SIGNED(ctx->r5) >> 31);
    // 0x8001AEB0: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001AEB4: mfhi        $t9
    ctx->r25 = hi;
    // 0x8001AEB8: sra         $v0, $t9, 8
    ctx->r2 = S32(SIGNED(ctx->r25) >> 8);
    // 0x8001AEBC: subu        $s2, $v0, $a1
    ctx->r18 = SUB32(ctx->r2, ctx->r5);
L_8001AEC0:
    // 0x8001AEC0: andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
    // 0x8001AEC4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001AEC8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001AECC: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001AED0: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x8001AED4: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8001AED8: bc1t        L_8001AEF0
    if (c1cs) {
        // 0x8001AEDC: addiu       $a1, $v0, 0x30
        ctx->r5 = ADD32(ctx->r2, 0X30);
            goto L_8001AEF0;
    }
    // 0x8001AEDC: addiu       $a1, $v0, 0x30
    ctx->r5 = ADD32(ctx->r2, 0X30);
    // 0x8001AEE0: trunc.w.s   $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8001AEE4: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x8001AEE8: j           L_8001AF00
    // 0x8001AEEC: nop

        goto L_8001AF00;
    // 0x8001AEEC: nop

L_8001AEF0:
    // 0x8001AEF0: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8001AEF4: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001AEF8: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8001AEFC: or          $v1, $v1, $t2
    ctx->r3 = ctx->r3 | ctx->r10;
L_8001AF00:
    // 0x8001AF00: mtc1        $t8, $f0
    ctx->f0.u32l = ctx->r24;
    // 0x8001AF04: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001AF08: mul.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001AF0C: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8001AF10: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8001AF14: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001AF18: bc1t        L_8001AF30
    if (c1cs) {
        // 0x8001AF1C: sh          $v0, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r2;
            goto L_8001AF30;
    }
    // 0x8001AF1C: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8001AF20: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001AF24: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x8001AF28: j           L_8001AF40
    // 0x8001AF2C: nop

        goto L_8001AF40;
    // 0x8001AF2C: nop

L_8001AF30:
    // 0x8001AF30: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8001AF34: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001AF38: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8001AF3C: or          $v1, $v1, $t2
    ctx->r3 = ctx->r3 | ctx->r10;
L_8001AF40:
    // 0x8001AF40: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x8001AF44: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8001AF48: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x8001AF4C: mtc1        $a2, $f0
    ctx->f0.u32l = ctx->r6;
    // 0x8001AF50: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001AF54: sh          $v0, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r2;
    // 0x8001AF58: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x8001AF5C: mul.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001AF60: subu        $v1, $v1, $t6
    ctx->r3 = SUB32(ctx->r3, ctx->r14);
    // 0x8001AF64: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8001AF68: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
    // 0x8001AF6C: andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
    // 0x8001AF70: sh          $v0, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r2;
    // 0x8001AF74: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001AF78: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001AF7C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001AF80: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8001AF84: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8001AF88: bc1t        L_8001AFA0
    if (c1cs) {
        // 0x8001AF8C: addiu       $a1, $v0, 0x44
        ctx->r5 = ADD32(ctx->r2, 0X44);
            goto L_8001AFA0;
    }
    // 0x8001AF8C: addiu       $a1, $v0, 0x44
    ctx->r5 = ADD32(ctx->r2, 0X44);
    // 0x8001AF90: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001AF94: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x8001AF98: j           L_8001AFB0
    // 0x8001AF9C: nop

        goto L_8001AFB0;
    // 0x8001AF9C: nop

L_8001AFA0:
    // 0x8001AFA0: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8001AFA4: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001AFA8: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8001AFAC: or          $v1, $v1, $t2
    ctx->r3 = ctx->r3 | ctx->r10;
L_8001AFB0:
    // 0x8001AFB0: mtc1        $t8, $f0
    ctx->f0.u32l = ctx->r24;
    // 0x8001AFB4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001AFB8: mul.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001AFBC: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8001AFC0: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8001AFC4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001AFC8: bc1t        L_8001AFE0
    if (c1cs) {
        // 0x8001AFCC: sh          $v0, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r2;
            goto L_8001AFE0;
    }
    // 0x8001AFCC: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8001AFD0: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001AFD4: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x8001AFD8: j           L_8001AFF0
    // 0x8001AFDC: nop

        goto L_8001AFF0;
    // 0x8001AFDC: nop

L_8001AFE0:
    // 0x8001AFE0: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8001AFE4: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001AFE8: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8001AFEC: or          $v1, $v1, $t2
    ctx->r3 = ctx->r3 | ctx->r10;
L_8001AFF0:
    // 0x8001AFF0: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x8001AFF4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8001AFF8: sh          $v0, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r2;
    // 0x8001AFFC: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8001B000: lhu         $v1, 0x2($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X2);
    // 0x8001B004: subu        $v0, $v0, $t6
    ctx->r2 = SUB32(ctx->r2, ctx->r14);
    // 0x8001B008: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x8001B00C: sh          $v1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r3;
    // 0x8001B010: andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
    // 0x8001B014: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8001B018: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001B01C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001B020: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001B024: addu        $a1, $t3, $v0
    ctx->r5 = ADD32(ctx->r11, ctx->r2);
    // 0x8001B028: lw          $v1, 0x2C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X2C);
    // 0x8001B02C: lw          $a0, 0x40($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X40);
    // 0x8001B030: sll         $v0, $t7, 2
    ctx->r2 = S32(ctx->r15 << 2);
    // 0x8001B034: sw          $s0, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->r16;
    // 0x8001B038: sw          $v0, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->r2;
    // 0x8001B03C: sw          $s2, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r18;
    // 0x8001B040: and         $v1, $v1, $s1
    ctx->r3 = ctx->r3 & ctx->r17;
    // 0x8001B044: and         $a0, $a0, $s1
    ctx->r4 = ctx->r4 & ctx->r17;
    // 0x8001B048: sw          $v1, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r3;
    // 0x8001B04C: beq         $fp, $zero, L_8001B12C
    if (ctx->r30 == 0) {
        // 0x8001B050: sw          $a0, 0x40($a1)
        MEM_W(0X40, ctx->r5) = ctx->r4;
            goto L_8001B12C;
    }
    // 0x8001B050: sw          $a0, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->r4;
    // 0x8001B054: div         $zero, $t5, $t0
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r8)));
    // 0x8001B058: bne         $t0, $zero, L_8001B064
    if (ctx->r8 != 0) {
        // 0x8001B05C: nop
    
            goto L_8001B064;
    }
    // 0x8001B05C: nop

    // 0x8001B060: break       7
    do_break(2147594336);
L_8001B064:
    // 0x8001B064: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001B068: bne         $t0, $at, L_8001B07C
    if (ctx->r8 != ctx->r1) {
        // 0x8001B06C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001B07C;
    }
    // 0x8001B06C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001B070: bne         $t5, $at, L_8001B07C
    if (ctx->r13 != ctx->r1) {
        // 0x8001B074: nop
    
            goto L_8001B07C;
    }
    // 0x8001B074: nop

    // 0x8001B078: break       6
    do_break(2147594360);
L_8001B07C:
    // 0x8001B07C: mflo        $v0
    ctx->r2 = lo;
    // 0x8001B080: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8001B084: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001B088: mul.s       $f2, $f22, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8001B08C: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8001B090: sw          $s0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r16;
    // 0x8001B094: bc1t        L_8001B0AC
    if (c1cs) {
        // 0x8001B098: addu        $a3, $a1, $zero
        ctx->r7 = ADD32(ctx->r5, 0);
            goto L_8001B0AC;
    }
    // 0x8001B098: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8001B09C: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001B0A0: mfc1        $a0, $f0
    ctx->r4 = (int32_t)ctx->f0.u32l;
    // 0x8001B0A4: j           L_8001B0BC
    // 0x8001B0A8: nop

        goto L_8001B0BC;
    // 0x8001B0A8: nop

L_8001B0AC:
    // 0x8001B0AC: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8001B0B0: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001B0B4: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x8001B0B8: or          $a0, $a0, $t2
    ctx->r4 = ctx->r4 | ctx->r10;
L_8001B0BC:
    // 0x8001B0BC: div         $zero, $t5, $t0
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r8)));
    // 0x8001B0C0: bne         $t0, $zero, L_8001B0CC
    if (ctx->r8 != 0) {
        // 0x8001B0C4: nop
    
            goto L_8001B0CC;
    }
    // 0x8001B0C4: nop

    // 0x8001B0C8: break       7
    do_break(2147594440);
L_8001B0CC:
    // 0x8001B0CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001B0D0: bne         $t0, $at, L_8001B0E4
    if (ctx->r8 != ctx->r1) {
        // 0x8001B0D4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001B0E4;
    }
    // 0x8001B0D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001B0D8: bne         $t5, $at, L_8001B0E4
    if (ctx->r13 != ctx->r1) {
        // 0x8001B0DC: nop
    
            goto L_8001B0E4;
    }
    // 0x8001B0DC: nop

    // 0x8001B0E0: break       6
    do_break(2147594464);
L_8001B0E4:
    // 0x8001B0E4: mflo        $v0
    ctx->r2 = lo;
    // 0x8001B0E8: lw          $v1, 0x2C($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X2C);
    // 0x8001B0EC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8001B0F0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001B0F4: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8001B0F8: mul.s       $f2, $f22, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8001B0FC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8001B100: sw          $v1, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r3;
    // 0x8001B104: andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
    // 0x8001B108: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001B10C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001B110: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001B114: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8001B118: addu        $a1, $t3, $v0
    ctx->r5 = ADD32(ctx->r11, ctx->r2);
    // 0x8001B11C: bc1f        L_8001B1FC
    if (!c1cs) {
        // 0x8001B120: addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
            goto L_8001B1FC;
    }
    // 0x8001B120: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // 0x8001B124: j           L_8001B210
    // 0x8001B128: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
        goto L_8001B210;
    // 0x8001B128: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
L_8001B12C:
    // 0x8001B12C: div         $zero, $t4, $t0
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r8)));
    // 0x8001B130: bne         $t0, $zero, L_8001B13C
    if (ctx->r8 != 0) {
        // 0x8001B134: nop
    
            goto L_8001B13C;
    }
    // 0x8001B134: nop

    // 0x8001B138: break       7
    do_break(2147594552);
L_8001B13C:
    // 0x8001B13C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001B140: bne         $t0, $at, L_8001B154
    if (ctx->r8 != ctx->r1) {
        // 0x8001B144: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001B154;
    }
    // 0x8001B144: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001B148: bne         $t4, $at, L_8001B154
    if (ctx->r12 != ctx->r1) {
        // 0x8001B14C: nop
    
            goto L_8001B154;
    }
    // 0x8001B14C: nop

    // 0x8001B150: break       6
    do_break(2147594576);
L_8001B154:
    // 0x8001B154: mflo        $v0
    ctx->r2 = lo;
    // 0x8001B158: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8001B15C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001B160: mul.s       $f2, $f22, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8001B164: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8001B168: sw          $t7, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r15;
    // 0x8001B16C: bc1t        L_8001B184
    if (c1cs) {
        // 0x8001B170: addu        $a3, $a1, $zero
        ctx->r7 = ADD32(ctx->r5, 0);
            goto L_8001B184;
    }
    // 0x8001B170: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8001B174: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001B178: mfc1        $a0, $f0
    ctx->r4 = (int32_t)ctx->f0.u32l;
    // 0x8001B17C: j           L_8001B194
    // 0x8001B180: nop

        goto L_8001B194;
    // 0x8001B180: nop

L_8001B184:
    // 0x8001B184: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8001B188: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001B18C: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x8001B190: or          $a0, $a0, $t2
    ctx->r4 = ctx->r4 | ctx->r10;
L_8001B194:
    // 0x8001B194: div         $zero, $t4, $t0
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r8)));
    // 0x8001B198: bne         $t0, $zero, L_8001B1A4
    if (ctx->r8 != 0) {
        // 0x8001B19C: nop
    
            goto L_8001B1A4;
    }
    // 0x8001B19C: nop

    // 0x8001B1A0: break       7
    do_break(2147594656);
L_8001B1A4:
    // 0x8001B1A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001B1A8: bne         $t0, $at, L_8001B1BC
    if (ctx->r8 != ctx->r1) {
        // 0x8001B1AC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001B1BC;
    }
    // 0x8001B1AC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001B1B0: bne         $t4, $at, L_8001B1BC
    if (ctx->r12 != ctx->r1) {
        // 0x8001B1B4: nop
    
            goto L_8001B1BC;
    }
    // 0x8001B1B4: nop

    // 0x8001B1B8: break       6
    do_break(2147594680);
L_8001B1BC:
    // 0x8001B1BC: mflo        $v0
    ctx->r2 = lo;
    // 0x8001B1C0: lw          $v1, 0x2C($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X2C);
    // 0x8001B1C4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8001B1C8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001B1CC: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8001B1D0: mul.s       $f2, $f22, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8001B1D4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8001B1D8: sw          $v1, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r3;
    // 0x8001B1DC: andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
    // 0x8001B1E0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001B1E4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001B1E8: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001B1EC: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8001B1F0: addu        $a1, $t3, $v0
    ctx->r5 = ADD32(ctx->r11, ctx->r2);
    // 0x8001B1F4: bc1t        L_8001B20C
    if (c1cs) {
        // 0x8001B1F8: addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
            goto L_8001B20C;
    }
    // 0x8001B1F8: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
L_8001B1FC:
    // 0x8001B1FC: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001B200: mfc1        $a0, $f0
    ctx->r4 = (int32_t)ctx->f0.u32l;
    // 0x8001B204: j           L_8001B21C
    // 0x8001B208: nop

        goto L_8001B21C;
    // 0x8001B208: nop

L_8001B20C:
    // 0x8001B20C: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
L_8001B210:
    // 0x8001B210: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001B214: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x8001B218: or          $a0, $a0, $t2
    ctx->r4 = ctx->r4 | ctx->r10;
L_8001B21C:
    // 0x8001B21C: lw          $v1, 0x40($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X40);
    // 0x8001B220: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8001B224: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8001B228: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001B22C: andi        $v0, $t1, 0xFFFF
    ctx->r2 = ctx->r9 & 0XFFFF;
    // 0x8001B230: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x8001B234: bne         $v0, $zero, L_8001AEC0
    if (ctx->r2 != 0) {
        // 0x8001B238: sw          $v1, 0x40($a1)
        MEM_W(0X40, ctx->r5) = ctx->r3;
            goto L_8001AEC0;
    }
    // 0x8001B238: sw          $v1, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->r3;
    // 0x8001B23C: j           L_8001B664
    // 0x8001B240: nop

        goto L_8001B664;
    // 0x8001B240: nop

L_8001B244:
    // 0x8001B244: jal         0x8000273C
    // 0x8001B248: nop

    getViModeType(rdram, ctx);
        goto after_23;
    // 0x8001B248: nop

    after_23:
    // 0x8001B24C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8001B250: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001B254: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001B258: lbu         $v1, 0x7810($at)
    ctx->r3 = MEM_BU(ctx->r1, 0X7810);
    // 0x8001B25C: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    // 0x8001B260: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001B264: addiu       $a0, $a0, -0x6CD0
    ctx->r4 = ADD32(ctx->r4, -0X6CD0);
    // 0x8001B268: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001B26C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001B270: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001B274: addu        $a2, $v0, $a0
    ctx->r6 = ADD32(ctx->r2, ctx->r4);
    // 0x8001B278: addiu       $t0, $a2, 0x50
    ctx->r8 = ADD32(ctx->r6, 0X50);
L_8001B27C:
    // 0x8001B27C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8001B280: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8001B284: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8001B288: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8001B28C: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8001B290: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x8001B294: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x8001B298: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x8001B29C: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001B2A0: bne         $a2, $t0, L_8001B27C
    if (ctx->r6 != ctx->r8) {
        // 0x8001B2A4: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8001B27C;
    }
    // 0x8001B2A4: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8001B2A8: addiu       $a3, $sp, 0x108
    ctx->r7 = ADD32(ctx->r29, 0X108);
    // 0x8001B2AC: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    // 0x8001B2B0: addiu       $t0, $sp, 0xB8
    ctx->r8 = ADD32(ctx->r29, 0XB8);
L_8001B2B4:
    // 0x8001B2B4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8001B2B8: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8001B2BC: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8001B2C0: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8001B2C4: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8001B2C8: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x8001B2CC: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x8001B2D0: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x8001B2D4: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001B2D8: bne         $a2, $t0, L_8001B2B4
    if (ctx->r6 != ctx->r8) {
        // 0x8001B2DC: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8001B2B4;
    }
    // 0x8001B2DC: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8001B2E0: jal         0x8000273C
    // 0x8001B2E4: nop

    getViModeType(rdram, ctx);
        goto after_24;
    // 0x8001B2E4: nop

    after_24:
    // 0x8001B2E8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8001B2EC: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001B2F0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001B2F4: lbu         $v1, 0x780C($at)
    ctx->r3 = MEM_BU(ctx->r1, 0X780C);
    // 0x8001B2F8: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8001B2FC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001B300: addiu       $a0, $a0, -0x6CD0
    ctx->r4 = ADD32(ctx->r4, -0X6CD0);
    // 0x8001B304: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001B308: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001B30C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001B310: addu        $a2, $v0, $a0
    ctx->r6 = ADD32(ctx->r2, ctx->r4);
    // 0x8001B314: addiu       $t0, $a2, 0x50
    ctx->r8 = ADD32(ctx->r6, 0X50);
L_8001B318:
    // 0x8001B318: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8001B31C: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8001B320: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8001B324: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8001B328: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8001B32C: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x8001B330: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x8001B334: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x8001B338: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001B33C: bne         $a2, $t0, L_8001B318
    if (ctx->r6 != ctx->r8) {
        // 0x8001B340: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8001B318;
    }
    // 0x8001B340: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8001B344: addiu       $a3, $sp, 0xB8
    ctx->r7 = ADD32(ctx->r29, 0XB8);
    // 0x8001B348: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x8001B34C: addiu       $t0, $sp, 0x68
    ctx->r8 = ADD32(ctx->r29, 0X68);
L_8001B350:
    // 0x8001B350: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8001B354: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8001B358: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8001B35C: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8001B360: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8001B364: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x8001B368: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x8001B36C: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x8001B370: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001B374: bne         $a2, $t0, L_8001B350
    if (ctx->r6 != ctx->r8) {
        // 0x8001B378: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8001B350;
    }
    // 0x8001B378: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8001B37C: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x8001B380: addiu       $t0, $sp, 0x18
    ctx->r8 = ADD32(ctx->r29, 0X18);
    // 0x8001B384: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001B388: lwc1        $f4, 0x808($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X808);
    // 0x8001B38C: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x8001B390: andi        $t6, $s0, 0xFFFF
    ctx->r14 = ctx->r16 & 0XFFFF;
    // 0x8001B394: sll         $a3, $s1, 1
    ctx->r7 = S32(ctx->r17 << 1);
    // 0x8001B398: sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19 << 16);
    // 0x8001B39C: sra         $t5, $v0, 16
    ctx->r13 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8001B3A0: sll         $s0, $t5, 1
    ctx->r16 = S32(ctx->r13 << 1);
    // 0x8001B3A4: lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    // 0x8001B3A8: ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // 0x8001B3AC: sll         $a0, $t5, 10
    ctx->r4 = S32(ctx->r13 << 10);
    // 0x8001B3B0: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B3B4: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x8001B3B8: sra         $t4, $v0, 6
    ctx->r12 = S32(SIGNED(ctx->r2) >> 6);
    // 0x8001B3BC: andi        $a2, $s5, 0xFFFF
    ctx->r6 = ctx->r21 & 0XFFFF;
    // 0x8001B3C0: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
    // 0x8001B3C4: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x8001B3C8: addiu       $v1, $zero, 0xF0
    ctx->r3 = ADD32(0, 0XF0);
    // 0x8001B3CC: subu        $t3, $v1, $v0
    ctx->r11 = SUB32(ctx->r3, ctx->r2);
    // 0x8001B3D0: mtc1        $a2, $f0
    ctx->f0.u32l = ctx->r6;
    // 0x8001B3D4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001B3D8: sra         $a0, $a0, 31
    ctx->r4 = S32(SIGNED(ctx->r4) >> 31);
    // 0x8001B3DC: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001B3E0: mfhi        $t9
    ctx->r25 = hi;
    // 0x8001B3E4: sra         $v0, $t9, 8
    ctx->r2 = S32(SIGNED(ctx->r25) >> 8);
    // 0x8001B3E8: subu        $t7, $v0, $a0
    ctx->r15 = SUB32(ctx->r2, ctx->r4);
    // 0x8001B3EC: andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
L_8001B3F0:
    // 0x8001B3F0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001B3F4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001B3F8: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001B3FC: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x8001B400: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x8001B404: bc1t        L_8001B41C
    if (c1cs) {
        // 0x8001B408: addiu       $a1, $v0, 0x30
        ctx->r5 = ADD32(ctx->r2, 0X30);
            goto L_8001B41C;
    }
    // 0x8001B408: addiu       $a1, $v0, 0x30
    ctx->r5 = ADD32(ctx->r2, 0X30);
    // 0x8001B40C: trunc.w.s   $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8001B410: mfc1        $a0, $f0
    ctx->r4 = (int32_t)ctx->f0.u32l;
    // 0x8001B414: j           L_8001B42C
    // 0x8001B418: nop

        goto L_8001B42C;
    // 0x8001B418: nop

L_8001B41C:
    // 0x8001B41C: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8001B420: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001B424: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x8001B428: or          $a0, $a0, $t2
    ctx->r4 = ctx->r4 | ctx->r10;
L_8001B42C:
    // 0x8001B42C: mtc1        $t6, $f0
    ctx->f0.u32l = ctx->r14;
    // 0x8001B430: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001B434: mul.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001B438: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x8001B43C: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8001B440: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001B444: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8001B448: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001B44C: bc1t        L_8001B464
    if (c1cs) {
        // 0x8001B450: sh          $v1, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r3;
            goto L_8001B464;
    }
    // 0x8001B450: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
    // 0x8001B454: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001B458: mfc1        $a0, $f0
    ctx->r4 = (int32_t)ctx->f0.u32l;
    // 0x8001B45C: j           L_8001B474
    // 0x8001B460: nop

        goto L_8001B474;
    // 0x8001B460: nop

L_8001B464:
    // 0x8001B464: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8001B468: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001B46C: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x8001B470: or          $a0, $a0, $t2
    ctx->r4 = ctx->r4 | ctx->r10;
L_8001B474:
    // 0x8001B474: lhu         $v1, 0x2($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X2);
    // 0x8001B478: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8001B47C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001B480: mtc1        $a2, $f0
    ctx->f0.u32l = ctx->r6;
    // 0x8001B484: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001B488: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8001B48C: sh          $v1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r3;
    // 0x8001B490: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x8001B494: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x8001B498: mul.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001B49C: subu        $v1, $v1, $a3
    ctx->r3 = SUB32(ctx->r3, ctx->r7);
    // 0x8001B4A0: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8001B4A4: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
    // 0x8001B4A8: andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
    // 0x8001B4AC: sh          $v0, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r2;
    // 0x8001B4B0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001B4B4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001B4B8: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001B4BC: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8001B4C0: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x8001B4C4: bc1t        L_8001B4DC
    if (c1cs) {
        // 0x8001B4C8: addiu       $a1, $v0, 0x44
        ctx->r5 = ADD32(ctx->r2, 0X44);
            goto L_8001B4DC;
    }
    // 0x8001B4C8: addiu       $a1, $v0, 0x44
    ctx->r5 = ADD32(ctx->r2, 0X44);
    // 0x8001B4CC: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001B4D0: mfc1        $a0, $f0
    ctx->r4 = (int32_t)ctx->f0.u32l;
    // 0x8001B4D4: j           L_8001B4EC
    // 0x8001B4D8: nop

        goto L_8001B4EC;
    // 0x8001B4D8: nop

L_8001B4DC:
    // 0x8001B4DC: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8001B4E0: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001B4E4: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x8001B4E8: or          $a0, $a0, $t2
    ctx->r4 = ctx->r4 | ctx->r10;
L_8001B4EC:
    // 0x8001B4EC: mtc1        $t6, $f0
    ctx->f0.u32l = ctx->r14;
    // 0x8001B4F0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001B4F4: mul.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001B4F8: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x8001B4FC: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8001B500: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001B504: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8001B508: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001B50C: bc1t        L_8001B524
    if (c1cs) {
        // 0x8001B510: sh          $v1, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r3;
            goto L_8001B524;
    }
    // 0x8001B510: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
    // 0x8001B514: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001B518: mfc1        $a0, $f0
    ctx->r4 = (int32_t)ctx->f0.u32l;
    // 0x8001B51C: j           L_8001B534
    // 0x8001B520: nop

        goto L_8001B534;
    // 0x8001B520: nop

L_8001B524:
    // 0x8001B524: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8001B528: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001B52C: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x8001B530: or          $a0, $a0, $t2
    ctx->r4 = ctx->r4 | ctx->r10;
L_8001B534:
    // 0x8001B534: lhu         $v1, 0x2($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X2);
    // 0x8001B538: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8001B53C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001B540: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8001B544: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8001B548: sh          $v1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r3;
    // 0x8001B54C: lhu         $v1, 0x2($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X2);
    // 0x8001B550: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x8001B554: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x8001B558: sh          $v1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r3;
    // 0x8001B55C: andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
    // 0x8001B560: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8001B564: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001B568: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001B56C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001B570: addu        $v1, $t0, $v0
    ctx->r3 = ADD32(ctx->r8, ctx->r2);
    // 0x8001B574: beq         $a2, $zero, L_8001B584
    if (ctx->r6 == 0) {
        // 0x8001B578: addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
            goto L_8001B584;
    }
    // 0x8001B578: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x8001B57C: j           L_8001B588
    // 0x8001B580: sw          $s0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r16;
        goto L_8001B588;
    // 0x8001B580: sw          $s0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r16;
L_8001B584:
    // 0x8001B584: sw          $zero, 0x28($v1)
    MEM_W(0X28, ctx->r3) = 0;
L_8001B588:
    // 0x8001B588: div         $zero, $t4, $t3
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r11)));
    // 0x8001B58C: bne         $t3, $zero, L_8001B598
    if (ctx->r11 != 0) {
        // 0x8001B590: nop
    
            goto L_8001B598;
    }
    // 0x8001B590: nop

    // 0x8001B594: break       7
    do_break(2147595668);
L_8001B598:
    // 0x8001B598: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001B59C: bne         $t3, $at, L_8001B5B0
    if (ctx->r11 != ctx->r1) {
        // 0x8001B5A0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001B5B0;
    }
    // 0x8001B5A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001B5A4: bne         $t4, $at, L_8001B5B0
    if (ctx->r12 != ctx->r1) {
        // 0x8001B5A8: nop
    
            goto L_8001B5B0;
    }
    // 0x8001B5A8: nop

    // 0x8001B5AC: break       6
    do_break(2147595692);
L_8001B5B0:
    // 0x8001B5B0: mflo        $a0
    ctx->r4 = lo;
    // 0x8001B5B4: lw          $v0, 0x28($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X28);
    // 0x8001B5B8: sw          $v0, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->r2;
    // 0x8001B5BC: sw          $v0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r2;
    // 0x8001B5C0: andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
    // 0x8001B5C4: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x8001B5C8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001B5CC: mul.s       $f2, $f22, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8001B5D0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001B5D4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001B5D8: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001B5DC: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x8001B5E0: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
    // 0x8001B5E4: sw          $t7, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r15;
    // 0x8001B5E8: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8001B5EC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8001B5F0: bc1t        L_8001B608
    if (c1cs) {
        // 0x8001B5F4: addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
            goto L_8001B608;
    }
    // 0x8001B5F4: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8001B5F8: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001B5FC: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x8001B600: j           L_8001B61C
    // 0x8001B604: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
        goto L_8001B61C;
    // 0x8001B604: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_8001B608:
    // 0x8001B608: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8001B60C: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001B610: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8001B614: or          $v1, $v1, $t2
    ctx->r3 = ctx->r3 | ctx->r10;
    // 0x8001B618: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_8001B61C:
    // 0x8001B61C: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x8001B620: sw          $v0, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r2;
    // 0x8001B624: sw          $v0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r2;
    // 0x8001B628: andi        $v0, $t1, 0xFFFF
    ctx->r2 = ctx->r9 & 0XFFFF;
    // 0x8001B62C: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x8001B630: bne         $v0, $zero, L_8001B3F0
    if (ctx->r2 != 0) {
        // 0x8001B634: andi        $v1, $t1, 0xFFFF
        ctx->r3 = ctx->r9 & 0XFFFF;
            goto L_8001B3F0;
    }
    // 0x8001B634: andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
    // 0x8001B638: sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19 << 16);
L_8001B63C:
    // 0x8001B63C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8001B640: slti        $v0, $v0, 0x141
    ctx->r2 = SIGNED(ctx->r2) < 0X141 ? 1 : 0;
    // 0x8001B644: bne         $v0, $zero, L_8001B664
    if (ctx->r2 != 0) {
        // 0x8001B648: addiu       $a0, $zero, -0x101
        ctx->r4 = ADD32(0, -0X101);
            goto L_8001B664;
    }
    // 0x8001B648: addiu       $a0, $zero, -0x101
    ctx->r4 = ADD32(0, -0X101);
    // 0x8001B64C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B650: lw          $v1, 0xBC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XBC);
    // 0x8001B654: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x8001B658: and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // 0x8001B65C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8001B660: sw          $v1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r3;
L_8001B664:
    // 0x8001B664: jal         0x8001BE80
    // 0x8001B668: nop

    func_8001BE80(rdram, ctx);
        goto after_25;
    // 0x8001B668: nop

    after_25:
    // 0x8001B66C: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x8001B670: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8001B674: addiu       $t3, $t3, -0x72B0
    ctx->r11 = ADD32(ctx->r11, -0X72B0);
    // 0x8001B678: addiu       $t2, $sp, 0x18
    ctx->r10 = ADD32(ctx->r29, 0X18);
    // 0x8001B67C: andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
L_8001B680:
    // 0x8001B680: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001B684: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001B688: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8001B68C: addu        $a3, $v0, $t3
    ctx->r7 = ADD32(ctx->r2, ctx->r11);
    // 0x8001B690: addu        $a2, $v0, $t2
    ctx->r6 = ADD32(ctx->r2, ctx->r10);
    // 0x8001B694: addiu       $t0, $a2, 0x50
    ctx->r8 = ADD32(ctx->r6, 0X50);
L_8001B698:
    // 0x8001B698: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8001B69C: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8001B6A0: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8001B6A4: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8001B6A8: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8001B6AC: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x8001B6B0: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x8001B6B4: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x8001B6B8: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001B6BC: bne         $a2, $t0, L_8001B698
    if (ctx->r6 != ctx->r8) {
        // 0x8001B6C0: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8001B698;
    }
    // 0x8001B6C0: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8001B6C4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001B6C8: andi        $v0, $t1, 0xFFFF
    ctx->r2 = ctx->r9 & 0XFFFF;
    // 0x8001B6CC: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x8001B6D0: bne         $v0, $zero, L_8001B680
    if (ctx->r2 != 0) {
        // 0x8001B6D4: andi        $v1, $t1, 0xFFFF
        ctx->r3 = ctx->r9 & 0XFFFF;
            goto L_8001B680;
    }
    // 0x8001B6D4: andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
    // 0x8001B6D8: lbu         $t9, 0x17F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X17F);
    // 0x8001B6DC: sltu        $v1, $zero, $fp
    ctx->r3 = 0 < ctx->r30 ? 1 : 0;
    // 0x8001B6E0: sltiu       $v0, $t9, 0x1
    ctx->r2 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8001B6E4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8001B6E8: beq         $v0, $zero, L_8001B70C
    if (ctx->r2 == 0) {
        // 0x8001B6EC: nop
    
            goto L_8001B70C;
    }
    // 0x8001B6EC: nop

    // 0x8001B6F0: lbu         $t9, 0x15F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X15F);
    // 0x8001B6F4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001B6F8: addiu       $a0, $a0, -0x72B0
    ctx->r4 = ADD32(ctx->r4, -0X72B0);
    // 0x8001B6FC: beql        $t9, $zero, L_8001B720
    if (ctx->r25 == 0) {
        // 0x8001B700: addiu       $a0, $a0, 0x50
        ctx->r4 = ADD32(ctx->r4, 0X50);
            goto L_8001B720;
    }
    goto skip_0;
    // 0x8001B700: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    skip_0:
    // 0x8001B704: j           L_8001B720
    // 0x8001B708: nop

        goto L_8001B720;
    // 0x8001B708: nop

L_8001B70C:
    // 0x8001B70C: lbu         $t9, 0x15F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X15F);
    // 0x8001B710: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001B714: addiu       $a0, $a0, -0x71C0
    ctx->r4 = ADD32(ctx->r4, -0X71C0);
    // 0x8001B718: bnel        $t9, $zero, L_8001B720
    if (ctx->r25 != 0) {
        // 0x8001B71C: addiu       $a0, $a0, -0x50
        ctx->r4 = ADD32(ctx->r4, -0X50);
            goto L_8001B720;
    }
    goto skip_1;
    // 0x8001B71C: addiu       $a0, $a0, -0x50
    ctx->r4 = ADD32(ctx->r4, -0X50);
    skip_1:
L_8001B720:
    // 0x8001B720: jal         0x800352D0
    // 0x8001B724: nop

    osViSetMode_recomp(rdram, ctx);
        goto after_26;
    // 0x8001B724: nop

    after_26:
    // 0x8001B728: lbu         $t9, 0x187($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X187);
    // 0x8001B72C: bne         $t9, $zero, L_8001B74C
    if (ctx->r25 != 0) {
        // 0x8001B730: nop
    
            goto L_8001B74C;
    }
    // 0x8001B730: nop

    // 0x8001B734: lbu         $t9, 0x167($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X167);
    // 0x8001B738: beq         $t9, $zero, L_8001B744
    if (ctx->r25 == 0) {
        // 0x8001B73C: addiu       $a0, $zero, 0x80
        ctx->r4 = ADD32(0, 0X80);
            goto L_8001B744;
    }
    // 0x8001B73C: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x8001B740: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
L_8001B744:
    // 0x8001B744: jal         0x80035340
    // 0x8001B748: nop

    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_27;
    // 0x8001B748: nop

    after_27:
L_8001B74C:
    // 0x8001B74C: lbu         $t9, 0x16F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X16F);
    // 0x8001B750: beq         $t9, $zero, L_8001B75C
    if (ctx->r25 == 0) {
        // 0x8001B754: addiu       $a0, $zero, 0x20
        ctx->r4 = ADD32(0, 0X20);
            goto L_8001B75C;
    }
    // 0x8001B754: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8001B758: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
L_8001B75C:
    // 0x8001B75C: jal         0x80035340
    // 0x8001B760: nop

    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_28;
    // 0x8001B760: nop

    after_28:
    // 0x8001B764: lbu         $t9, 0x177($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X177);
    // 0x8001B768: beq         $t9, $zero, L_8001B774
    if (ctx->r25 == 0) {
        // 0x8001B76C: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_8001B774;
    }
    // 0x8001B76C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001B770: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8001B774:
    // 0x8001B774: jal         0x80035340
    // 0x8001B778: nop

    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_29;
    // 0x8001B778: nop

    after_29:
    // 0x8001B77C: lw          $ra, 0x1AC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1AC);
    // 0x8001B780: lw          $fp, 0x1A8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X1A8);
    // 0x8001B784: lw          $s7, 0x1A4($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X1A4);
    // 0x8001B788: lw          $s6, 0x1A0($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X1A0);
    // 0x8001B78C: lw          $s5, 0x19C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X19C);
    // 0x8001B790: lw          $s4, 0x198($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X198);
    // 0x8001B794: lw          $s3, 0x194($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X194);
    // 0x8001B798: lw          $s2, 0x190($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X190);
    // 0x8001B79C: lw          $s1, 0x18C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18C);
    // 0x8001B7A0: lw          $s0, 0x188($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X188);
    // 0x8001B7A4: ldc1        $f22, 0x1B8($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X1B8);
    // 0x8001B7A8: ldc1        $f20, 0x1B0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X1B0);
    // 0x8001B7AC: addiu       $sp, $sp, 0x1C0
    ctx->r29 = ADD32(ctx->r29, 0X1C0);
    // 0x8001B7B0: jr          $ra
    // 0x8001B7B4: nop

    return;
    // 0x8001B7B4: nop

;}
RECOMP_FUNC void func_8001B7B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B7B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001B7BC: sw          $a0, -0x7170($at)
    MEM_W(-0X7170, ctx->r1) = ctx->r4;
    // 0x8001B7C0: jr          $ra
    // 0x8001B7C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8001B7C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_8001B7C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B7C8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001B7CC: sw          $a0, -0x716C($at)
    MEM_W(-0X716C, ctx->r1) = ctx->r4;
    // 0x8001B7D0: jr          $ra
    // 0x8001B7D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8001B7D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_8001B7D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B7D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001B7DC: sw          $zero, -0x7170($at)
    MEM_W(-0X7170, ctx->r1) = 0;
    // 0x8001B7E0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001B7E4: sw          $zero, -0x716C($at)
    MEM_W(-0X716C, ctx->r1) = 0;
    // 0x8001B7E8: jr          $ra
    // 0x8001B7EC: nop

    return;
    // 0x8001B7EC: nop

;}
RECOMP_FUNC void func_8001B7F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B7F0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001B7F4: lw          $v0, -0x716C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X716C);
    // 0x8001B7F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001B7FC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8001B800: beq         $v0, $zero, L_8001B810
    if (ctx->r2 == 0) {
        // 0x8001B804: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8001B810;
    }
    // 0x8001B804: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8001B808: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001B80C: sb          $zero, -0x579E($at)
    MEM_B(-0X579E, ctx->r1) = 0;
L_8001B810:
    // 0x8001B810: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001B814: lw          $v0, -0x716C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X716C);
    // 0x8001B818: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x8001B81C: beq         $v0, $zero, L_8001B82C
    if (ctx->r2 == 0) {
        // 0x8001B820: nop
    
            goto L_8001B82C;
    }
    // 0x8001B820: nop

    // 0x8001B824: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001B828: sb          $zero, -0x579B($at)
    MEM_B(-0X579B, ctx->r1) = 0;
L_8001B82C:
    // 0x8001B82C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001B830: lw          $v0, -0x7170($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7170);
    // 0x8001B834: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8001B838: beq         $v0, $zero, L_8001B848
    if (ctx->r2 == 0) {
        // 0x8001B83C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001B848;
    }
    // 0x8001B83C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001B840: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001B844: sb          $v0, -0x579E($at)
    MEM_B(-0X579E, ctx->r1) = ctx->r2;
L_8001B848:
    // 0x8001B848: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001B84C: lw          $v0, -0x7170($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7170);
    // 0x8001B850: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x8001B854: beq         $v0, $zero, L_8001B864
    if (ctx->r2 == 0) {
        // 0x8001B858: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001B864;
    }
    // 0x8001B858: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001B85C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001B860: sb          $v0, -0x579B($at)
    MEM_B(-0X579B, ctx->r1) = ctx->r2;
L_8001B864:
    // 0x8001B864: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001B868: lw          $v0, -0x716C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X716C);
    // 0x8001B86C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001B870: lw          $v1, -0x7170($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7170);
    // 0x8001B874: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8001B878: andi        $v0, $v0, 0x9
    ctx->r2 = ctx->r2 & 0X9;
    // 0x8001B87C: beq         $v0, $zero, L_8001B998
    if (ctx->r2 == 0) {
        // 0x8001B880: nop
    
            goto L_8001B998;
    }
    // 0x8001B880: nop

    // 0x8001B884: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001B888: lbu         $v0, -0x579B($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X579B);
    // 0x8001B88C: beq         $v0, $zero, L_8001B8A4
    if (ctx->r2 == 0) {
        // 0x8001B890: nop
    
            goto L_8001B8A4;
    }
    // 0x8001B890: nop

    // 0x8001B894: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001B898: lbu         $v0, -0x579C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X579C);
    // 0x8001B89C: beq         $v0, $zero, L_8001B8C4
    if (ctx->r2 == 0) {
        // 0x8001B8A0: nop
    
            goto L_8001B8C4;
    }
    // 0x8001B8A0: nop

L_8001B8A4:
    // 0x8001B8A4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001B8A8: lbu         $v0, -0x579E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X579E);
    // 0x8001B8AC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001B8B0: addiu       $a0, $a0, -0x72B0
    ctx->r4 = ADD32(ctx->r4, -0X72B0);
    // 0x8001B8B4: beql        $v0, $zero, L_8001B8DC
    if (ctx->r2 == 0) {
        // 0x8001B8B8: addiu       $a0, $a0, 0x50
        ctx->r4 = ADD32(ctx->r4, 0X50);
            goto L_8001B8DC;
    }
    goto skip_0;
    // 0x8001B8B8: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    skip_0:
    // 0x8001B8BC: j           L_8001B8DC
    // 0x8001B8C0: nop

        goto L_8001B8DC;
    // 0x8001B8C0: nop

L_8001B8C4:
    // 0x8001B8C4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001B8C8: lbu         $v0, -0x579E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X579E);
    // 0x8001B8CC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001B8D0: addiu       $a0, $a0, -0x71C0
    ctx->r4 = ADD32(ctx->r4, -0X71C0);
    // 0x8001B8D4: bnel        $v0, $zero, L_8001B8DC
    if (ctx->r2 != 0) {
        // 0x8001B8D8: addiu       $a0, $a0, -0x50
        ctx->r4 = ADD32(ctx->r4, -0X50);
            goto L_8001B8DC;
    }
    goto skip_1;
    // 0x8001B8D8: addiu       $a0, $a0, -0x50
    ctx->r4 = ADD32(ctx->r4, -0X50);
    skip_1:
L_8001B8DC:
    // 0x8001B8DC: jal         0x800352D0
    // 0x8001B8E0: nop

    osViSetMode_recomp(rdram, ctx);
        goto after_0;
    // 0x8001B8E0: nop

    after_0:
    // 0x8001B8E4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001B8E8: lw          $v0, -0x7170($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7170);
    // 0x8001B8EC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001B8F0: lw          $v1, -0x716C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X716C);
    // 0x8001B8F4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8001B8F8: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x8001B8FC: bne         $v0, $zero, L_8001B920
    if (ctx->r2 != 0) {
        // 0x8001B900: nop
    
            goto L_8001B920;
    }
    // 0x8001B900: nop

    // 0x8001B904: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001B908: lbu         $v0, -0x5798($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5798);
    // 0x8001B90C: beq         $v0, $zero, L_8001B918
    if (ctx->r2 == 0) {
        // 0x8001B910: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_8001B918;
    }
    // 0x8001B910: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001B914: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8001B918:
    // 0x8001B918: jal         0x80035340
    // 0x8001B91C: nop

    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_1;
    // 0x8001B91C: nop

    after_1:
L_8001B920:
    // 0x8001B920: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001B924: lw          $v0, -0x7170($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7170);
    // 0x8001B928: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001B92C: lw          $v1, -0x716C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X716C);
    // 0x8001B930: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8001B934: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x8001B938: bne         $v0, $zero, L_8001B95C
    if (ctx->r2 != 0) {
        // 0x8001B93C: nop
    
            goto L_8001B95C;
    }
    // 0x8001B93C: nop

    // 0x8001B940: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001B944: lbu         $v0, -0x579A($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X579A);
    // 0x8001B948: beq         $v0, $zero, L_8001B954
    if (ctx->r2 == 0) {
        // 0x8001B94C: addiu       $a0, $zero, 0x80
        ctx->r4 = ADD32(0, 0X80);
            goto L_8001B954;
    }
    // 0x8001B94C: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x8001B950: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
L_8001B954:
    // 0x8001B954: jal         0x80035340
    // 0x8001B958: nop

    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_2;
    // 0x8001B958: nop

    after_2:
L_8001B95C:
    // 0x8001B95C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001B960: lw          $v0, -0x7170($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7170);
    // 0x8001B964: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001B968: lw          $v1, -0x716C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X716C);
    // 0x8001B96C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8001B970: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8001B974: bne         $v0, $zero, L_8001B998
    if (ctx->r2 != 0) {
        // 0x8001B978: nop
    
            goto L_8001B998;
    }
    // 0x8001B978: nop

    // 0x8001B97C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001B980: lbu         $v0, -0x5799($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5799);
    // 0x8001B984: beq         $v0, $zero, L_8001B990
    if (ctx->r2 == 0) {
        // 0x8001B988: addiu       $a0, $zero, 0x20
        ctx->r4 = ADD32(0, 0X20);
            goto L_8001B990;
    }
    // 0x8001B988: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8001B98C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
L_8001B990:
    // 0x8001B990: jal         0x80035340
    // 0x8001B994: nop

    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_3;
    // 0x8001B994: nop

    after_3:
L_8001B998:
    // 0x8001B998: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001B99C: lw          $v0, -0x716C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X716C);
    // 0x8001B9A0: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x8001B9A4: beq         $v0, $zero, L_8001B9BC
    if (ctx->r2 == 0) {
        // 0x8001B9A8: nop
    
            goto L_8001B9BC;
    }
    // 0x8001B9A8: nop

    // 0x8001B9AC: jal         0x80035340
    // 0x8001B9B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_4;
    // 0x8001B9B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x8001B9B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001B9B8: sb          $zero, -0x5798($at)
    MEM_B(-0X5798, ctx->r1) = 0;
L_8001B9BC:
    // 0x8001B9BC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001B9C0: lw          $v0, -0x716C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X716C);
    // 0x8001B9C4: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x8001B9C8: beq         $v0, $zero, L_8001B9E0
    if (ctx->r2 == 0) {
        // 0x8001B9CC: nop
    
            goto L_8001B9E0;
    }
    // 0x8001B9CC: nop

    // 0x8001B9D0: jal         0x80035340
    // 0x8001B9D4: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_5;
    // 0x8001B9D4: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_5:
    // 0x8001B9D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001B9DC: sb          $zero, -0x579A($at)
    MEM_B(-0X579A, ctx->r1) = 0;
L_8001B9E0:
    // 0x8001B9E0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001B9E4: lw          $v0, -0x716C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X716C);
    // 0x8001B9E8: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8001B9EC: beq         $v0, $zero, L_8001BA04
    if (ctx->r2 == 0) {
        // 0x8001B9F0: nop
    
            goto L_8001BA04;
    }
    // 0x8001B9F0: nop

    // 0x8001B9F4: jal         0x80035340
    // 0x8001B9F8: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_6;
    // 0x8001B9F8: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_6:
    // 0x8001B9FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001BA00: sb          $zero, -0x5799($at)
    MEM_B(-0X5799, ctx->r1) = 0;
L_8001BA04:
    // 0x8001BA04: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001BA08: lw          $v0, -0x7170($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7170);
    // 0x8001BA0C: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x8001BA10: beq         $v0, $zero, L_8001BA2C
    if (ctx->r2 == 0) {
        // 0x8001BA14: nop
    
            goto L_8001BA2C;
    }
    // 0x8001BA14: nop

    // 0x8001BA18: jal         0x80035340
    // 0x8001BA1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_7;
    // 0x8001BA1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x8001BA20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001BA24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001BA28: sb          $v0, -0x5798($at)
    MEM_B(-0X5798, ctx->r1) = ctx->r2;
L_8001BA2C:
    // 0x8001BA2C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001BA30: lw          $v0, -0x7170($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7170);
    // 0x8001BA34: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x8001BA38: beq         $v0, $zero, L_8001BA54
    if (ctx->r2 == 0) {
        // 0x8001BA3C: nop
    
            goto L_8001BA54;
    }
    // 0x8001BA3C: nop

    // 0x8001BA40: jal         0x80035340
    // 0x8001BA44: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_8;
    // 0x8001BA44: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_8:
    // 0x8001BA48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001BA4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001BA50: sb          $v0, -0x579A($at)
    MEM_B(-0X579A, ctx->r1) = ctx->r2;
L_8001BA54:
    // 0x8001BA54: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001BA58: lw          $v0, -0x7170($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7170);
    // 0x8001BA5C: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8001BA60: beq         $v0, $zero, L_8001BA7C
    if (ctx->r2 == 0) {
        // 0x8001BA64: nop
    
            goto L_8001BA7C;
    }
    // 0x8001BA64: nop

    // 0x8001BA68: jal         0x80035340
    // 0x8001BA6C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_9;
    // 0x8001BA6C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_9:
    // 0x8001BA70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001BA74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001BA78: sb          $v0, -0x5799($at)
    MEM_B(-0X5799, ctx->r1) = ctx->r2;
L_8001BA7C:
    // 0x8001BA7C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BA80: sw          $zero, -0x716C($at)
    MEM_W(-0X716C, ctx->r1) = 0;
    // 0x8001BA84: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BA88: sw          $zero, -0x7170($at)
    MEM_W(-0X7170, ctx->r1) = 0;
    // 0x8001BA8C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8001BA90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001BA94: jr          $ra
    // 0x8001BA98: nop

    return;
    // 0x8001BA98: nop

;}
RECOMP_FUNC void func_8001BA9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BA9C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BAA0: lbu         $v0, -0x579B($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X579B);
    // 0x8001BAA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001BAA8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001BAAC: addiu       $v1, $v1, -0x72B0
    ctx->r3 = ADD32(ctx->r3, -0X72B0);
    // 0x8001BAB0: beq         $v0, $zero, L_8001BAC8
    if (ctx->r2 == 0) {
        // 0x8001BAB4: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8001BAC8;
    }
    // 0x8001BAB4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8001BAB8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BABC: lbu         $v0, -0x579C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X579C);
    // 0x8001BAC0: beq         $v0, $zero, L_8001BAE0
    if (ctx->r2 == 0) {
        // 0x8001BAC4: nop
    
            goto L_8001BAE0;
    }
    // 0x8001BAC4: nop

L_8001BAC8:
    // 0x8001BAC8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BACC: lbu         $v0, -0x579E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X579E);
    // 0x8001BAD0: beql        $v0, $zero, L_8001BAF4
    if (ctx->r2 == 0) {
        // 0x8001BAD4: addiu       $v1, $v1, 0x50
        ctx->r3 = ADD32(ctx->r3, 0X50);
            goto L_8001BAF4;
    }
    goto skip_0;
    // 0x8001BAD4: addiu       $v1, $v1, 0x50
    ctx->r3 = ADD32(ctx->r3, 0X50);
    skip_0:
    // 0x8001BAD8: j           L_8001BAF4
    // 0x8001BADC: nop

        goto L_8001BAF4;
    // 0x8001BADC: nop

L_8001BAE0:
    // 0x8001BAE0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BAE4: lbu         $v0, -0x579E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X579E);
    // 0x8001BAE8: beql        $v0, $zero, L_8001BAF4
    if (ctx->r2 == 0) {
        // 0x8001BAEC: addiu       $v1, $v1, 0xF0
        ctx->r3 = ADD32(ctx->r3, 0XF0);
            goto L_8001BAF4;
    }
    goto skip_1;
    // 0x8001BAEC: addiu       $v1, $v1, 0xF0
    ctx->r3 = ADD32(ctx->r3, 0XF0);
    skip_1:
    // 0x8001BAF0: addiu       $v1, $v1, 0xA0
    ctx->r3 = ADD32(ctx->r3, 0XA0);
L_8001BAF4:
    // 0x8001BAF4: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8001BAF8: addiu       $a3, $a3, -0x7370
    ctx->r7 = ADD32(ctx->r7, -0X7370);
    // 0x8001BAFC: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x8001BB00: addiu       $t0, $a2, 0x50
    ctx->r8 = ADD32(ctx->r6, 0X50);
L_8001BB04:
    // 0x8001BB04: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8001BB08: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8001BB0C: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8001BB10: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8001BB14: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8001BB18: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x8001BB1C: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x8001BB20: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x8001BB24: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001BB28: bne         $a2, $t0, L_8001BB04
    if (ctx->r6 != ctx->r8) {
        // 0x8001BB2C: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8001BB04;
    }
    // 0x8001BB2C: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8001BB30: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001BB34: addiu       $a0, $a0, -0x7340
    ctx->r4 = ADD32(ctx->r4, -0X7340);
    // 0x8001BB38: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8001BB3C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x8001BB40: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BB44: sh          $v0, -0x733E($at)
    MEM_H(-0X733E, ctx->r1) = ctx->r2;
    // 0x8001BB48: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8001BB4C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BB50: sh          $v0, -0x732A($at)
    MEM_H(-0X732A, ctx->r1) = ctx->r2;
    // 0x8001BB54: jal         0x800352D0
    // 0x8001BB58: addiu       $a0, $a0, -0x44
    ctx->r4 = ADD32(ctx->r4, -0X44);
    osViSetMode_recomp(rdram, ctx);
        goto after_0;
    // 0x8001BB58: addiu       $a0, $a0, -0x44
    ctx->r4 = ADD32(ctx->r4, -0X44);
    after_0:
    // 0x8001BB5C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8001BB60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001BB64: jr          $ra
    // 0x8001BB68: nop

    return;
    // 0x8001BB68: nop

;}
RECOMP_FUNC void func_8001BB6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BB6C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BB70: lbu         $v0, -0x579B($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X579B);
    // 0x8001BB74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001BB78: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001BB7C: addiu       $v1, $v1, -0x72B0
    ctx->r3 = ADD32(ctx->r3, -0X72B0);
    // 0x8001BB80: beq         $v0, $zero, L_8001BB98
    if (ctx->r2 == 0) {
        // 0x8001BB84: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8001BB98;
    }
    // 0x8001BB84: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8001BB88: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BB8C: lbu         $v0, -0x579C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X579C);
    // 0x8001BB90: beq         $v0, $zero, L_8001BBB0
    if (ctx->r2 == 0) {
        // 0x8001BB94: nop
    
            goto L_8001BBB0;
    }
    // 0x8001BB94: nop

L_8001BB98:
    // 0x8001BB98: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BB9C: lbu         $v0, -0x579E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X579E);
    // 0x8001BBA0: beql        $v0, $zero, L_8001BBC4
    if (ctx->r2 == 0) {
        // 0x8001BBA4: addiu       $v1, $v1, 0x50
        ctx->r3 = ADD32(ctx->r3, 0X50);
            goto L_8001BBC4;
    }
    goto skip_0;
    // 0x8001BBA4: addiu       $v1, $v1, 0x50
    ctx->r3 = ADD32(ctx->r3, 0X50);
    skip_0:
    // 0x8001BBA8: j           L_8001BBC4
    // 0x8001BBAC: nop

        goto L_8001BBC4;
    // 0x8001BBAC: nop

L_8001BBB0:
    // 0x8001BBB0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BBB4: lbu         $v0, -0x579E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X579E);
    // 0x8001BBB8: beql        $v0, $zero, L_8001BBC4
    if (ctx->r2 == 0) {
        // 0x8001BBBC: addiu       $v1, $v1, 0xF0
        ctx->r3 = ADD32(ctx->r3, 0XF0);
            goto L_8001BBC4;
    }
    goto skip_1;
    // 0x8001BBBC: addiu       $v1, $v1, 0xF0
    ctx->r3 = ADD32(ctx->r3, 0XF0);
    skip_1:
    // 0x8001BBC0: addiu       $v1, $v1, 0xA0
    ctx->r3 = ADD32(ctx->r3, 0XA0);
L_8001BBC4:
    // 0x8001BBC4: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8001BBC8: addiu       $a3, $a3, -0x7370
    ctx->r7 = ADD32(ctx->r7, -0X7370);
    // 0x8001BBCC: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x8001BBD0: addiu       $t0, $a2, 0x50
    ctx->r8 = ADD32(ctx->r6, 0X50);
L_8001BBD4:
    // 0x8001BBD4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8001BBD8: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8001BBDC: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8001BBE0: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8001BBE4: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8001BBE8: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x8001BBEC: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x8001BBF0: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x8001BBF4: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001BBF8: bne         $a2, $t0, L_8001BBD4
    if (ctx->r6 != ctx->r8) {
        // 0x8001BBFC: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8001BBD4;
    }
    // 0x8001BBFC: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8001BC00: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001BC04: lhu         $v0, -0x7340($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7340);
    // 0x8001BC08: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001BC0C: lhu         $v1, -0x732C($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X732C);
    // 0x8001BC10: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001BC14: addiu       $a0, $a0, -0x7370
    ctx->r4 = ADD32(ctx->r4, -0X7370);
    // 0x8001BC18: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BC1C: sh          $v0, -0x733E($at)
    MEM_H(-0X733E, ctx->r1) = ctx->r2;
    // 0x8001BC20: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BC24: sh          $v1, -0x732A($at)
    MEM_H(-0X732A, ctx->r1) = ctx->r3;
    // 0x8001BC28: jal         0x800352D0
    // 0x8001BC2C: nop

    osViSetMode_recomp(rdram, ctx);
        goto after_0;
    // 0x8001BC2C: nop

    after_0:
    // 0x8001BC30: jal         0x8001BE80
    // 0x8001BC34: nop

    func_8001BE80(rdram, ctx);
        goto after_1;
    // 0x8001BC34: nop

    after_1:
    // 0x8001BC38: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8001BC3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001BC40: jr          $ra
    // 0x8001BC44: nop

    return;
    // 0x8001BC44: nop

;}
RECOMP_FUNC void func_8001BC48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BC48: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BC4C: lh          $v0, -0x57B8($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X57B8);
    // 0x8001BC50: slti        $v0, $v0, 0x18
    ctx->r2 = SIGNED(ctx->r2) < 0X18 ? 1 : 0;
    // 0x8001BC54: beq         $v0, $zero, L_8001BC7C
    if (ctx->r2 == 0) {
        // 0x8001BC58: nop
    
            goto L_8001BC7C;
    }
    // 0x8001BC58: nop

    // 0x8001BC5C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BC60: lw          $v0, -0x57C8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X57C8);
    // 0x8001BC64: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001BC68: lw          $v1, -0x57C4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X57C4);
    // 0x8001BC6C: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001BC70: mflo        $v0
    ctx->r2 = lo;
    // 0x8001BC74: j           L_8001BC98
    // 0x8001BC78: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
        goto L_8001BC98;
    // 0x8001BC78: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
L_8001BC7C:
    // 0x8001BC7C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BC80: lw          $v0, -0x57C8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X57C8);
    // 0x8001BC84: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001BC88: lw          $v1, -0x57C4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X57C4);
    // 0x8001BC8C: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001BC90: mflo        $v0
    ctx->r2 = lo;
    // 0x8001BC94: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
L_8001BC98:
    // 0x8001BC98: jr          $ra
    // 0x8001BC9C: nop

    return;
    // 0x8001BC9C: nop

;}
RECOMP_FUNC void func_8001BCA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BCA0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001BCA4: lw          $v1, -0x714C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X714C);
    // 0x8001BCA8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8001BCAC: bnel        $v1, $v0, L_8001BCC4
    if (ctx->r3 != ctx->r2) {
        // 0x8001BCB0: sw          $v1, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r3;
            goto L_8001BCC4;
    }
    goto skip_0;
    // 0x8001BCB0: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    skip_0:
    // 0x8001BCB4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8001BCB8: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8001BCBC: j           L_8001BCDC
    // 0x8001BCC0: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_8001BCDC;
    // 0x8001BCC0: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_8001BCC4:
    // 0x8001BCC4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001BCC8: lw          $v0, -0x7148($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7148);
    // 0x8001BCCC: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x8001BCD0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001BCD4: lw          $v0, -0x7144($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7144);
    // 0x8001BCD8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_8001BCDC:
    // 0x8001BCDC: jr          $ra
    // 0x8001BCE0: nop

    return;
    // 0x8001BCE0: nop

;}
RECOMP_FUNC void func_8001BCE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    { static int n=0; ++n; if (n<=10 || (n%20)==0) { if(1) fprintf(stderr, "[trace] producer::func_8001BCE4 ENTRY #%d\n", n); fflush(stderr); } }
    // 0x8001BCE4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001BCE8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001BCEC: addiu       $a0, $a0, -0x72F0
    ctx->r4 = ADD32(ctx->r4, -0X72F0);
    // 0x8001BCF0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8001BCF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8001BCF8: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x8001BCFC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8001BD00: jal         0x800331D0
    // 0x8001BD04: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8001BD04: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    after_0:
    // 0x8001BD08: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001BD0C: addiu       $v1, $v1, -0x7153
    ctx->r3 = ADD32(ctx->r3, -0X7153);
    // 0x8001BD10: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8001BD14: blez        $v0, L_8001BE54
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001BD18: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8001BE54;
    }
    // 0x8001BD18: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8001BD1C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8001BD20: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x8001BD24: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8001BD28: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8001BD2C: addiu       $s0, $v1, -0x3
    ctx->r16 = ADD32(ctx->r3, -0X3);
    // 0x8001BD30: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8001BD34: addiu       $a2, $v1, -0x9
    ctx->r6 = ADD32(ctx->r3, -0X9);
    // 0x8001BD38: addiu       $t0, $v1, 0x1F
    ctx->r8 = ADD32(ctx->r3, 0X1F);
    // 0x8001BD3C: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
L_8001BD40:
    // 0x8001BD40: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    { static int n=0; ++n; if (n<=20 || (n%50)==0) {
        uint8_t t0 = *(uint8_t*)(rdram + (size_t)((0x80128EAAu ^ 3) & 0x7FFFFFFFu));
        uint8_t t1 = *(uint8_t*)(rdram + (size_t)((0x80128EABu ^ 3) & 0x7FFFFFFFu));
        uint8_t cE = *(uint8_t*)(rdram + (size_t)((0x80128EAEu ^ 3) & 0x7FFFFFFFu));
        uint8_t cF = *(uint8_t*)(rdram + (size_t)((0x80128EAFu ^ 3) & 0x7FFFFFFFu));
        if(1) fprintf(stderr, "[trace] producer::scan-loop #%d a0_byte=%d types=[%02X %02X] counters=[%u %u]\n",
            n, (int)(int32_t)ctx->r3, (unsigned)t0, (unsigned)t1, (unsigned)cE, (unsigned)cF);
        fflush(stderr);
    } }
    // 0x8001BD44: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001BD48: bnel        $v1, $v0, L_8001BE34
    if (ctx->r3 != ctx->r2) {
        // 0x8001BD4C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8001BE34;
    }
    goto skip_0;
    // 0x8001BD4C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8001BD50: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001BD54: lw          $v0, -0x72CC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X72CC);
    // 0x8001BD58: xor         $v1, $v0, $t3
    ctx->r3 = ctx->r2 ^ ctx->r11;
    // 0x8001BD5C: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x8001BD60: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x8001BD64: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8001BD68: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8001BD6C: lbu         $v0, -0x1F($t0)
    ctx->r2 = MEM_BU(ctx->r8, -0X1F);
    // 0x8001BD70: blez        $v0, L_8001BDB4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001BD74: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8001BDB4;
    }
    // 0x8001BD74: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8001BD78: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    // 0x8001BD7C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8001BD80: addiu       $a1, $a1, -0x7153
    ctx->r5 = ADD32(ctx->r5, -0X7153);
L_8001BD84:
    // 0x8001BD84: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BD88: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8001BD8C: lbu         $v0, -0x7156($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X7156);
    // 0x8001BD90: bne         $v0, $s1, L_8001BDA4
    if (ctx->r2 != ctx->r17) {
        // 0x8001BD94: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8001BDA4;
    }
    // 0x8001BD94: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001BD98: sb          $t1, 0x0($s0)
    { static int n=0; ++n; if (n<=10 || (n%20)==0) { if(0) fprintf(stderr, "[trace] producer::write-type3 #%d slot_ptr=0x%016llX\n", n, (unsigned long long)(uintptr_t)ctx->r16); fflush(stderr); } }
    MEM_B(0X0, ctx->r16) = ctx->r9;
    // 0x8001BD9C: j           L_8001BE54
    // 0x8001BDA0: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
        goto L_8001BE54;
    // 0x8001BDA0: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
L_8001BDA4:
    // 0x8001BDA4: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8001BDA8: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001BDAC: bne         $v0, $zero, L_8001BD84
    if (ctx->r2 != 0) {
        // 0x8001BDB0: nop
    
            goto L_8001BD84;
    }
    // 0x8001BDB0: nop

L_8001BDB4:
    // 0x8001BDB4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001BDB8: lbu         $v0, -0x7153($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7153);
    // 0x8001BDBC: blez        $v0, L_8001BE18
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001BDC0: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8001BE18;
    }
    // 0x8001BDC0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8001BDC4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001BDC8: addiu       $a0, $a0, -0x7152
    ctx->r4 = ADD32(ctx->r4, -0X7152);
    // 0x8001BDCC: addiu       $a1, $a0, -0x1
    ctx->r5 = ADD32(ctx->r4, -0X1);
L_8001BDD0:
    // 0x8001BDD0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BDD4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8001BDD8: lbu         $v0, -0x7156($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X7156);
    // 0x8001BDDC: bne         $v0, $t2, L_8001BE08
    if (ctx->r2 != ctx->r10) {
        // 0x8001BDE0: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8001BE08;
    }
    // 0x8001BDE0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001BDE4: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x8001BDE8: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8001BDEC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001BDF0: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001BDF4: beq         $v1, $zero, L_8001BE18
    if (ctx->r3 == 0) {
        // 0x8001BDF8: nop
    
            goto L_8001BE18;
    }
    // 0x8001BDF8: nop

    // 0x8001BDFC: sb          $t1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r9;
    { static int n=0; ++n; if (n<=10 || (n%20)==0) {
        uint8_t t0 = *(uint8_t*)(rdram + (size_t)((0x80128EAAu ^ 3) & 0x7FFFFFFFu));
        uint8_t t1 = *(uint8_t*)(rdram + (size_t)((0x80128EABu ^ 3) & 0x7FFFFFFFu));
        uint8_t cE = *(uint8_t*)(rdram + (size_t)((0x80128EAEu ^ 3) & 0x7FFFFFFFu));
        uint8_t cF = *(uint8_t*)(rdram + (size_t)((0x80128EAFu ^ 3) & 0x7FFFFFFFu));
        if(0) fprintf(stderr, "[trace] producer::POST-write3-B #%d types=[%02X %02X] counters=[%u %u] r16=0x%016llX\n",
            n, (unsigned)t0, (unsigned)t1, (unsigned)cE, (unsigned)cF,
            (unsigned long long)(uintptr_t)ctx->r16);
        fflush(stderr);
    } }
    // 0x8001BE00: j           L_8001BE54
    // 0x8001BE04: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
        goto L_8001BE54;
    // 0x8001BE04: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
L_8001BE08:
    // 0x8001BE08: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8001BE0C: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001BE10: bne         $v0, $zero, L_8001BDD0
    if (ctx->r2 != 0) {
        // 0x8001BE14: nop
    
            goto L_8001BDD0;
    }
    // 0x8001BE14: nop

L_8001BE18:
    // 0x8001BE18: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BE1C: addu        $at, $at, $a3
    ctx->r1 = ADD32(ctx->r1, ctx->r7);
    // 0x8001BE20: lw          $a0, -0x7168($at)
    ctx->r4 = MEM_W(ctx->r1, -0X7168);
    // 0x8001BE24: jal         0x80035500
    // 0x8001BE28: nop

    osViSwapBuffer_recomp(rdram, ctx);
        goto after_1;
    // 0x8001BE28: nop

    after_1:
    // 0x8001BE2C: j           L_8001BE54
    // 0x8001BE30: sb          $s1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r17;
        goto L_8001BE54;
    // 0x8001BE30: sb          $s1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r17;
L_8001BE34:
    // 0x8001BE34: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8001BE38: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8001BE3C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001BE40: lbu         $v0, -0x7153($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7153);
    // 0x8001BE44: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001BE48: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001BE4C: bne         $v0, $zero, L_8001BD40
    if (ctx->r2 != 0) {
        // 0x8001BE50: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8001BD40;
    }
    // 0x8001BE50: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8001BE54:
    // 0x8001BE54: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001BE58: addiu       $a0, $a0, -0x72F0
    ctx->r4 = ADD32(ctx->r4, -0X72F0);
    // 0x8001BE5C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8001BE60: jal         0x80033410
    // 0x8001BE64: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8001BE64: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_2:
    // 0x8001BE68: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x8001BE6C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8001BE70: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8001BE74: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8001BE78: jr          $ra
    // 0x8001BE7C: nop

    return;
    // 0x8001BE7C: nop

;}
RECOMP_FUNC void func_8001BE80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BE80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001BE84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001BE88: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001BE8C: addiu       $a0, $a0, -0x7310
    ctx->r4 = ADD32(ctx->r4, -0X7310);
    // 0x8001BE90: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8001BE94: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8001BE98: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001BE9C: sb          $v0, 0x7808($at)
    MEM_B(0X7808, ctx->r1) = ctx->r2;
    // 0x8001BEA0: jal         0x800331D0
    // 0x8001BEA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8001BEA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8001BEA8: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001BEAC: sb          $zero, 0x7808($at)
    MEM_B(0X7808, ctx->r1) = 0;
    // 0x8001BEB0: jal         0x80037510
    // 0x8001BEB4: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_1;
    // 0x8001BEB4: nop

    after_1:
    // 0x8001BEB8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8001BEBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001BEC0: jr          $ra
    // 0x8001BEC4: nop

    return;
    // 0x8001BEC4: nop

;}
RECOMP_FUNC void func_8001BEC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    { static int n=0; ++n; if (n<=10 || (n%50)==0) {
        uint8_t t0 = *(uint8_t*)(rdram + (size_t)((0x80128EAAu ^ 3) & 0x7FFFFFFFu));
        uint8_t t1 = *(uint8_t*)(rdram + (size_t)((0x80128EABu ^ 3) & 0x7FFFFFFFu));
        uint8_t t2 = *(uint8_t*)(rdram + (size_t)((0x80128EACu ^ 3) & 0x7FFFFFFFu));
        uint8_t count = *(uint8_t*)(rdram + (size_t)((0x80128EADu ^ 3) & 0x7FFFFFFFu));
        fprintf(stderr, "[trace] mark-ready(1->2) func_8001BEC8 ENTRY #%d slots=[%02X %02X %02X] count=%u\n", n, (unsigned)t0, (unsigned)t1, (unsigned)t2, (unsigned)count);
        fflush(stderr);
    } }
    // 0x8001BEC8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001BECC: addiu       $v1, $v1, -0x7153
    ctx->r3 = ADD32(ctx->r3, -0X7153);
    // 0x8001BED0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8001BED4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8001BED8: blez        $v0, L_8001BF14
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001BEDC: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8001BF14;
    }
    // 0x8001BEDC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8001BEE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8001BEE4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8001BEE8: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x8001BEEC: addiu       $v1, $a1, -0x3
    ctx->r3 = ADD32(ctx->r5, -0X3);
L_8001BEF0:
    // 0x8001BEF0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8001BEF4: bne         $v0, $a2, L_8001BF04
    if (ctx->r2 != ctx->r6) {
        // 0x8001BEF8: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8001BF04;
    }
    // 0x8001BEF8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001BEFC: j           L_8001BF14
    // 0x8001BF00: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
        goto L_8001BF14;
    // 0x8001BF00: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
L_8001BF04:
    // 0x8001BF04: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8001BF08: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001BF0C: bne         $v0, $zero, L_8001BEF0
    if (ctx->r2 != 0) {
        // 0x8001BF10: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8001BEF0;
    }
    // 0x8001BF10: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8001BF14:
    // 0x8001BF14: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8001BF18: jr          $ra
    // 0x8001BF1C: nop

    return;
    // 0x8001BF1C: nop

;}
RECOMP_FUNC void func_8001BF20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    { static int n=0; ++n; if (n<=10 || (n%50)==0) {
        uint8_t t0 = *(uint8_t*)(rdram + (size_t)((0x80128EAAu ^ 3) & 0x7FFFFFFFu));
        uint8_t t1 = *(uint8_t*)(rdram + (size_t)((0x80128EABu ^ 3) & 0x7FFFFFFFu));
        uint8_t t2 = *(uint8_t*)(rdram + (size_t)((0x80128EACu ^ 3) & 0x7FFFFFFFu));
        uint8_t count = *(uint8_t*)(rdram + (size_t)((0x80128EADu ^ 3) & 0x7FFFFFFFu));
        fprintf(stderr, "[trace] alloc(0->1) func_8001BF20 ENTRY #%d slots=[%02X %02X %02X] count=%u\n", n, (unsigned)t0, (unsigned)t1, (unsigned)t2, (unsigned)count);
        fflush(stderr);
    } }
    // 0x8001BF20: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001BF24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8001BF28: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001BF2C: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8001BF30: addiu       $s3, $s3, -0x7140
    ctx->r19 = ADD32(ctx->r19, -0X7140);
    // 0x8001BF34: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001BF38: addiu       $s4, $s3, -0x28
    ctx->r20 = ADD32(ctx->r19, -0X28);
    // 0x8001BF3C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001BF40: andi        $s1, $a0, 0xFF
    ctx->r17 = ctx->r4 & 0XFF;
    // 0x8001BF44: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001BF48: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8001BF4C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001BF50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
L_8001BF54:
    // 0x8001BF54: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001BF58: lbu         $v0, -0x7153($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7153);
    // 0x8001BF5C: blez        $v0, L_8001BFBC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001BF60: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8001BFBC;
    }
    // 0x8001BF60: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8001BF64: addu        $s0, $s4, $zero
    ctx->r16 = ADD32(ctx->r20, 0);
    // 0x8001BF68: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8001BF6C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001BF70: addiu       $v1, $v1, -0x7156
    ctx->r3 = ADD32(ctx->r3, -0X7156);
L_8001BF74:
    // 0x8001BF74: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8001BF78: bnel        $v0, $zero, L_8001BFA0
    if (ctx->r2 != 0) {
        // 0x8001BF7C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8001BFA0;
    }
    goto skip_0;
    // 0x8001BF7C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x8001BF80: sb          $s2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r18;
    // 0x8001BF84: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BF88: lw          $v0, -0x5770($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5770);
    // 0x8001BF8C: jal         0x80001880
    // 0x8001BF90: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    func_80001880(rdram, ctx);
        goto after_0;
    // 0x8001BF90: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    after_0:
    // 0x8001BF94: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8001BF98: j           L_8001C058
    // 0x8001BF9C: nop

        goto L_8001C058;
    // 0x8001BF9C: nop

L_8001BFA0:
    // 0x8001BFA0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8001BFA4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001BFA8: lbu         $v0, -0x7153($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7153);
    // 0x8001BFAC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001BFB0: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001BFB4: bne         $v0, $zero, L_8001BF74
    if (ctx->r2 != 0) {
        // 0x8001BFB8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8001BF74;
    }
    // 0x8001BFB8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8001BFBC:
    // 0x8001BFBC: beq         $s1, $s2, L_8001C058
    if (ctx->r17 == ctx->r18) {
        // 0x8001BFC0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8001C058;
    }
    // 0x8001BFC0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8001BFC4: beq         $s1, $zero, L_8001BFDC
    if (ctx->r17 == 0) {
        // 0x8001BFC8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8001BFDC;
    }
    // 0x8001BFC8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001BFCC: beq         $s1, $v0, L_8001C018
    if (ctx->r17 == ctx->r2) {
        // 0x8001BFD0: andi        $v0, $a2, 0xFF
        ctx->r2 = ctx->r6 & 0XFF;
            goto L_8001C018;
    }
    // 0x8001BFD0: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x8001BFD4: j           L_8001BF54
    // 0x8001BFD8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
        goto L_8001BF54;
    // 0x8001BFD8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_8001BFDC:
    // 0x8001BFDC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001BFE0: addiu       $a0, $a0, -0x7310
    ctx->r4 = ADD32(ctx->r4, -0X7310);
    // 0x8001BFE4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8001BFE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8001BFEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001BFF0: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001BFF4: sb          $v0, 0x7808($at)
    MEM_B(0X7808, ctx->r1) = ctx->r2;
    // 0x8001BFF8: jal         0x800331D0
    // 0x8001BFFC: nop

    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8001BFFC: nop

    after_1:
    // 0x8001C000: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001C004: sb          $zero, 0x7808($at)
    MEM_B(0X7808, ctx->r1) = 0;
    // 0x8001C008: jal         0x80037510
    // 0x8001C00C: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_2;
    // 0x8001C00C: nop

    after_2:
    // 0x8001C010: j           L_8001BF54
    // 0x8001C014: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
        goto L_8001BF54;
    // 0x8001C014: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_8001C018:
    // 0x8001C018: bne         $v0, $zero, L_8001C034
    if (ctx->r2 != 0) {
        // 0x8001C01C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001C034;
    }
    // 0x8001C01C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001C020: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001C024: sb          $zero, 0x7808($at)
    MEM_B(0X7808, ctx->r1) = 0;
    // 0x8001C028: jal         0x80037510
    // 0x8001C02C: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_3;
    // 0x8001C02C: nop

    after_3:
    // 0x8001C030: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001C034:
    // 0x8001C034: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001C038: sb          $v0, 0x7808($at)
    MEM_B(0X7808, ctx->r1) = ctx->r2;
    // 0x8001C03C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001C040: addiu       $a0, $a0, -0x7310
    ctx->r4 = ADD32(ctx->r4, -0X7310);
    // 0x8001C044: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8001C048: jal         0x800331D0
    // 0x8001C04C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x8001C04C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x8001C050: j           L_8001BF54
    // 0x8001C054: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
        goto L_8001BF54;
    // 0x8001C054: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_8001C058:
    // 0x8001C058: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001C05C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001C060: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001C064: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001C068: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C06C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001C070: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001C074: jr          $ra
    // 0x8001C078: nop

    return;
    // 0x8001C078: nop

;}
RECOMP_FUNC void func_8001C07C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C07C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001C080: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001C084: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8001C088: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001C08C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8001C090: addiu       $s1, $s1, -0x7168
    ctx->r17 = ADD32(ctx->r17, -0X7168);
    // 0x8001C094: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
L_8001C098:
    // 0x8001C098: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001C09C: lbu         $v0, -0x7153($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7153);
    // 0x8001C0A0: blez        $v0, L_8001C0D4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001C0A4: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8001C0D4;
    }
    // 0x8001C0A4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8001C0A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001C0AC: lbu         $a0, -0x7153($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X7153);
L_8001C0B0:
    // 0x8001C0B0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001C0B4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8001C0B8: lbu         $v0, -0x7156($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X7156);
    // 0x8001C0BC: beq         $v0, $zero, L_8001C10C
    if (ctx->r2 == 0) {
        // 0x8001C0C0: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8001C10C;
    }
    // 0x8001C0C0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001C0C4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001C0C8: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001C0CC: bne         $v0, $zero, L_8001C0B0
    if (ctx->r2 != 0) {
        // 0x8001C0D0: nop
    
            goto L_8001C0B0;
    }
    // 0x8001C0D0: nop

L_8001C0D4:
    // 0x8001C0D4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001C0D8: addiu       $a0, $a0, -0x7310
    ctx->r4 = ADD32(ctx->r4, -0X7310);
    // 0x8001C0DC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8001C0E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8001C0E4: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001C0E8: sb          $s0, 0x7808($at)
    MEM_B(0X7808, ctx->r1) = ctx->r16;
    // 0x8001C0EC: jal         0x800331D0
    // 0x8001C0F0: nop

    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8001C0F0: nop

    after_0:
    // 0x8001C0F4: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001C0F8: sb          $zero, 0x7808($at)
    MEM_B(0X7808, ctx->r1) = 0;
    // 0x8001C0FC: jal         0x80037510
    // 0x8001C100: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_1;
    // 0x8001C100: nop

    after_1:
    // 0x8001C104: j           L_8001C098
    // 0x8001C108: nop

        goto L_8001C098;
    // 0x8001C108: nop

L_8001C10C:
    // 0x8001C10C: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x8001C110: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8001C114: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8001C118: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C11C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001C120: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001C124: jr          $ra
    // 0x8001C128: nop

    return;
    // 0x8001C128: nop

;}
RECOMP_FUNC void func_8001C12C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    if(0) { static int n=0; if (++n<=20 || (n%50)==0) {
        uint8_t gate = (uint8_t)MEM_BU(0xFFFFFFFF801128C8ULL, 0);
        fprintf(stderr, "[trace] func_8001C12C(gfx-submit) #%d gate@0x801128C8=0x%02X\n", n, gate);
        fflush(stderr);
    } }
    // 0x8001C12C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001C130: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001C134: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8001C138: addiu       $s0, $s0, -0x5738
    ctx->r16 = ADD32(ctx->r16, -0X5738);
    // 0x8001C13C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C140: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8001C144: beq         $v0, $zero, L_8001C230
    if (ctx->r2 == 0) {
        // 0x8001C148: nop
    
            goto L_8001C230;
    }
    // 0x8001C148: nop

    // 0x8001C14C: jal         0x8001BF20
    // 0x8001C150: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001BF20(rdram, ctx);
        goto after_0;
    // 0x8001C150: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8001C154: beq         $v0, $zero, L_8001C230
    if (ctx->r2 == 0) {
        // 0x8001C158: nop
    
            goto L_8001C230;
    }
    // 0x8001C158: nop

    // 0x8001C15C: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8001C160: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8001C164: lbu         $a1, -0x72D4($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X72D4);
    // 0x8001C168: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8001C16C: jal         0x8000BAFC
    // 0x8001C170: xori        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 ^ 0X1;
    func_8000BAFC(rdram, ctx);
        goto after_1;
    // 0x8001C170: xori        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 ^ 0X1;
    after_1:
    // 0x8001C174: jal         0x8000BBB0
    // 0x8001C178: nop

    func_8000BBB0(rdram, ctx);
        goto after_2;
    // 0x8001C178: nop

    after_2:
    // 0x8001C17C: jal         0x80035930
    // 0x8001C180: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_3;
    // 0x8001C180: nop

    after_3:
    // 0x8001C184: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001C188: addiu       $v1, $v1, 0x25D0
    ctx->r3 = ADD32(ctx->r3, 0X25D0);
    // 0x8001C18C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001C190: addiu       $v0, $v0, 0x26A0
    ctx->r2 = ADD32(ctx->r2, 0X26A0);
    // 0x8001C194: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8001C198: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001C19C: sw          $v0, 0x77D4($at)
    MEM_W(0X77D4, ctx->r1) = ctx->r2;
    // 0x8001C1A0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001C1A4: lw          $v0, -0x5B40($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5B40);
    // 0x8001C1A8: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001C1AC: sw          $v1, 0x77D0($at)
    MEM_W(0X77D0, ctx->r1) = ctx->r3;
    // 0x8001C1B0: lui         $v1, 0x8003
    ctx->r3 = S32(0X8003 << 16);
    // 0x8001C1B4: lw          $v1, 0x77C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X77C0);
    // 0x8001C1B8: lui         $a1, 0x8003
    ctx->r5 = S32(0X8003 << 16);
    // 0x8001C1BC: lw          $a1, 0x77C4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X77C4);
    // 0x8001C1C0: lui         $s0, 0x8003
    ctx->r16 = S32(0X8003 << 16);
    // 0x8001C1C4: addiu       $s0, $s0, 0x77F8
    ctx->r16 = ADD32(ctx->r16, 0X77F8);
    // 0x8001C1C8: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001C1CC: sw          $zero, 0x77FC($at)
    MEM_W(0X77FC, ctx->r1) = 0;
    // 0x8001C1D0: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // 0x8001C1D4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8001C1D8: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001C1DC: sw          $v1, 0x77D8($at)
    MEM_W(0X77D8, ctx->r1) = ctx->r3;
    // 0x8001C1E0: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001C1E4: sw          $a1, 0x77E0($at)
    MEM_W(0X77E0, ctx->r1) = ctx->r5;
    // 0x8001C1E8: jal         0x8002B5E0
    // 0x8001C1EC: addiu       $a0, $zero, 0x1C0
    ctx->r4 = ADD32(0, 0X1C0);
    osDpSetStatus_recomp(rdram, ctx);
        goto after_4;
    // 0x8001C1EC: addiu       $a0, $zero, 0x1C0
    ctx->r4 = ADD32(0, 0X1C0);
    after_4:
    // 0x8001C1F0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001C1F4: addiu       $a0, $a0, -0x5BE0
    ctx->r4 = ADD32(ctx->r4, -0X5BE0);
    // 0x8001C1F8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8001C1FC: addiu       $a1, $a1, -0x7320
    ctx->r5 = ADD32(ctx->r5, -0X7320);
    // 0x8001C200: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001C204: addiu       $s0, $s0, -0x30
    ctx->r16 = ADD32(ctx->r16, -0X30);
    // 0x8001C208: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8001C20C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001C210: sb          $v0, -0x5762($at)
    MEM_B(-0X5762, ctx->r1) = ctx->r2;
    // 0x8001C214: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001C218: sb          $v0, -0x5763($at)
    MEM_B(-0X5763, ctx->r1) = ctx->r2;
    // 0x8001C21C: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    { static int n=0; if (++n<=10) {
        uint8_t rb = (uint8_t)MEM_BU(0, ctx->r5);
        if(0) fprintf(stderr, "[trace] func_8001C12C POST-SB #%d wrote_via_r2=0x%02X readback msg[0]@0x%08X=0x%02X\n",
            n, (uint8_t)(ctx->r2 & 0xFF), (uint32_t)ctx->r5, rb);
        fflush(stderr);
    } }
    // 0x8001C220: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001C224: sw          $s0, -0x731C($at)
    MEM_W(-0X731C, ctx->r1) = ctx->r16;
    { static int n=0; if (++n<=20 || (n%50)==0) {
        uint8_t mt = ctx->r5 ? (uint8_t)MEM_BU(0, ctx->r5) : 0xFF;
        if(0) fprintf(stderr, "[trace] func_8001C12C ABOUT TO osSendMesg #%d queue=0x%08X msg=0x%08X type=0x%02X\n",
            n, (uint32_t)ctx->r4, (uint32_t)ctx->r5, mt);
        fflush(stderr);
    } }
    // 0x8001C228: jal         0x80033410
    // 0x8001C22C: nop

    osSendMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x8001C22C: nop

    after_5:
L_8001C230:
    // 0x8001C230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001C234: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001C238: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001C23C: jr          $ra
    // 0x8001C240: nop

    return;
    // 0x8001C240: nop

;}
RECOMP_FUNC void func_8001C244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C244: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001C248: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001C24C: sb          $v0, -0x5738($at)
    MEM_B(-0X5738, ctx->r1) = ctx->r2;
    // 0x8001C250: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001C254: sb          $v0, -0x5737($at)
    MEM_B(-0X5737, ctx->r1) = ctx->r2;
    // 0x8001C258: jr          $ra
    // 0x8001C25C: nop

    return;
    // 0x8001C25C: nop

;}
RECOMP_FUNC void func_8001C260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C260: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001C264: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001C268: addiu       $v1, $v1, -0x5737
    ctx->r3 = ADD32(ctx->r3, -0X5737);
    // 0x8001C26C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8001C270: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8001C274: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001C278: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8001C27C: beq         $v0, $zero, L_8001C2E0
    if (ctx->r2 == 0) {
        // 0x8001C280: nop
    
            goto L_8001C2E0;
    }
    // 0x8001C280: nop

    // 0x8001C284: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001C288: lbu         $v0, -0x5738($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5738);
    // 0x8001C28C: beq         $v0, $zero, L_8001C2D8
    if (ctx->r2 == 0) {
        // 0x8001C290: nop
    
            goto L_8001C2D8;
    }
    // 0x8001C290: nop

    // 0x8001C294: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8001C298: addiu       $s0, $v1, -0x1
    ctx->r16 = ADD32(ctx->r3, -0X1);
L_8001C29C:
    // 0x8001C29C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001C2A0: addiu       $a0, $a0, -0x7310
    ctx->r4 = ADD32(ctx->r4, -0X7310);
    // 0x8001C2A4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8001C2A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8001C2AC: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001C2B0: sb          $s1, 0x7808($at)
    MEM_B(0X7808, ctx->r1) = ctx->r17;
    // 0x8001C2B4: jal         0x800331D0
    // 0x8001C2B8: nop

    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8001C2B8: nop

    after_0:
    // 0x8001C2BC: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001C2C0: sb          $zero, 0x7808($at)
    MEM_B(0X7808, ctx->r1) = 0;
    // 0x8001C2C4: jal         0x80037510
    // 0x8001C2C8: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_1;
    // 0x8001C2C8: nop

    after_1:
    // 0x8001C2CC: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8001C2D0: bne         $v0, $zero, L_8001C29C
    if (ctx->r2 != 0) {
        // 0x8001C2D4: nop
    
            goto L_8001C29C;
    }
    // 0x8001C2D4: nop

L_8001C2D8:
    // 0x8001C2D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001C2DC: sb          $zero, -0x5737($at)
    MEM_B(-0X5737, ctx->r1) = 0;
L_8001C2E0:
    // 0x8001C2E0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8001C2E4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8001C2E8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001C2EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001C2F0: jr          $ra
    // 0x8001C2F4: nop

    return;
    // 0x8001C2F4: nop

;}
RECOMP_FUNC void func_8001C2F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C2F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001C2FC: sb          $zero, -0x5738($at)
    MEM_B(-0X5738, ctx->r1) = 0;
    // 0x8001C300: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001C304: sb          $zero, -0x5737($at)
    MEM_B(-0X5737, ctx->r1) = 0;
    // 0x8001C308: jr          $ra
    // 0x8001C30C: nop

    return;
    // 0x8001C30C: nop

;}
RECOMP_FUNC void func_8001C310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C310: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001C314: sw          $a0, 0x77C0($at)
    MEM_W(0X77C0, ctx->r1) = ctx->r4;
    // 0x8001C318: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8001C31C: sw          $a1, 0x77C4($at)
    MEM_W(0X77C4, ctx->r1) = ctx->r5;
    // 0x8001C320: jr          $ra
    // 0x8001C324: nop

    return;
    // 0x8001C324: nop

;}
RECOMP_FUNC void func_8001C328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C328: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001C32C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001C330: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8001C334: addiu       $s0, $s0, -0x5BF8
    ctx->r16 = ADD32(ctx->r16, -0X5BF8);
    // 0x8001C338: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8001C33C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001C340: addiu       $a1, $a1, -0x57D0
    ctx->r5 = ADD32(ctx->r5, -0X57D0);
    // 0x8001C344: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C348: jal         0x8002B300
    // 0x8001C34C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8001C34C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8001C350: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8001C354: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8001C358: jal         0x80033560
    // 0x8001C35C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8001C35C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // 0x8001C360: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001C364: addiu       $a0, $a0, -0x5818
    ctx->r4 = ADD32(ctx->r4, -0X5818);
    // 0x8001C368: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001C36C: addiu       $a1, $a1, -0x239C
    ctx->r5 = ADD32(ctx->r5, -0X239C);
    // 0x8001C370: jal         0x8002B300
    // 0x8001C374: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_2;
    // 0x8001C374: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8001C378: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8001C37C: addiu       $s0, $s0, -0x5763
    ctx->r16 = ADD32(ctx->r16, -0X5763);
L_8001C380:
    // 0x8001C380: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001C384: addiu       $a0, $a0, -0x5BF8
    ctx->r4 = ADD32(ctx->r4, -0X5BF8);
    // 0x8001C388: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8001C38C: jal         0x800331D0
    // 0x8001C390: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x8001C390: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8001C394: jal         0x8002BF00
    // 0x8001C398: nop

    osGetTime_recomp(rdram, ctx);
        goto after_4;
    // 0x8001C398: nop

    after_4:
    // 0x8001C39C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001C3A0: lw          $a0, -0x72D0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X72D0);
    // 0x8001C3A4: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8001C3A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001C3AC: sw          $v1, -0x72CC($at)
    MEM_W(-0X72CC, ctx->r1) = ctx->r3;
    // 0x8001C3B0: jal         0x80023D08
    // 0x8001C3B4: nop

    func_80023D08(rdram, ctx);
        goto after_5;
    // 0x8001C3B4: nop

    after_5:
    // 0x8001C3B8: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    { static int n=0; ++n; if (n<=20 || (n%50)==0) { if(0) fprintf(stderr, "[trace] gate_thread iter=%d gate@0x8011A89D=0x%X\n", n, (unsigned)(ctx->r3 & 0xFF)); fflush(stderr); } }
    // 0x8001C3BC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001C3C0: sw          $v0, -0x7124($at)
    MEM_W(-0X7124, ctx->r1) = ctx->r2;
    // 0x8001C3C4: beq         $v1, $zero, L_8001C3DC
    if (ctx->r3 == 0) {
        // 0x8001C3C8: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8001C3DC;
    }
    // 0x8001C3C8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8001C3CC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001C3D0: addiu       $a0, $a0, -0x5818
    ctx->r4 = ADD32(ctx->r4, -0X5818);
    // 0x8001C3D4: jal         0x80033410
    // 0x8001C3D8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    { static int n=0; ++n; if (n<=20 || (n%50)==0) { if(0) fprintf(stderr, "[trace] gate_thread #%d sending to 0x8011A7E8\n", n); fflush(stderr); } }
    osSendMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x8001C3D8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_6:
L_8001C3DC:
    // 0x8001C3DC: sb          $zero, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = 0;
    // 0x8001C3E0: j           L_8001C380
    // 0x8001C3E4: nop

        goto L_8001C380;
    // 0x8001C3E4: nop

    // 0x8001C3E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001C3EC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001C3F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001C3F4: jr          $ra
    // 0x8001C3F8: nop

    return;
    // 0x8001C3F8: nop

;}
RECOMP_FUNC void fake_func_8001C3FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8001C400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C400: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C404: lwc1        $f0, 0x810($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X810);
    // 0x8001C408: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8001C40C: nop

    // 0x8001C410: bc1f        L_8001C428
    if (!c1cs) {
        // 0x8001C414: nop
    
            goto L_8001C428;
    }
    // 0x8001C414: nop

    // 0x8001C418: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C41C: lwc1        $f0, 0x814($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X814);
    // 0x8001C420: j           L_8001C5C4
    // 0x8001C424: nop

        goto L_8001C5C4;
    // 0x8001C424: nop

L_8001C428:
    // 0x8001C428: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C42C: lwc1        $f0, 0x818($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X818);
    // 0x8001C430: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8001C434: nop

    // 0x8001C438: bc1f        L_8001C450
    if (!c1cs) {
        // 0x8001C43C: nop
    
            goto L_8001C450;
    }
    // 0x8001C43C: nop

    // 0x8001C440: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C444: lwc1        $f0, 0x81C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X81C);
    // 0x8001C448: j           L_8001C5C4
    // 0x8001C44C: nop

        goto L_8001C5C4;
    // 0x8001C44C: nop

L_8001C450:
    // 0x8001C450: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C454: lwc1        $f0, 0x820($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X820);
    // 0x8001C458: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8001C45C: nop

    // 0x8001C460: bc1t        L_8001C46C
    if (c1cs) {
        // 0x8001C464: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8001C46C;
    }
    // 0x8001C464: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8001C468: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8001C46C:
    // 0x8001C46C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C470: lwc1        $f0, 0x824($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X824);
    // 0x8001C474: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8001C478: nop

    // 0x8001C47C: bc1t        L_8001C488
    if (c1cs) {
        // 0x8001C480: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001C488;
    }
    // 0x8001C480: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001C484: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8001C488:
    // 0x8001C488: and         $a0, $v1, $v0
    ctx->r4 = ctx->r3 & ctx->r2;
    // 0x8001C48C: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8001C490: bne         $v0, $zero, L_8001C4E4
    if (ctx->r2 != 0) {
        // 0x8001C494: nop
    
            goto L_8001C4E4;
    }
    // 0x8001C494: nop

    // 0x8001C498: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001C49C: mov.s       $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    ctx->f10.fl = ctx->f12.fl;
    // 0x8001C4A0: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8001C4A4: nop

    // 0x8001C4A8: mul.s       $f2, $f10, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8001C4AC: bc1fl       L_8001C4D4
    if (!c1cs) {
        // 0x8001C4B0: nop
    
            goto L_8001C4D4;
    }
    goto skip_0;
    // 0x8001C4B0: nop

    skip_0:
    // 0x8001C4B4: nop

    // 0x8001C4B8: mul.s       $f0, $f10, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8001C4BC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C4C0: lwc1        $f2, 0x828($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X828);
    // 0x8001C4C4: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8001C4C8: sqrt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = sqrtf(ctx->f2.fl);
    // 0x8001C4CC: j           L_8001C4E4
    // 0x8001C4D0: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
        goto L_8001C4E4;
    // 0x8001C4D0: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
L_8001C4D4:
    // 0x8001C4D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C4D8: lwc1        $f0, 0x82C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X82C);
    // 0x8001C4DC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8001C4E0: sqrt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = sqrtf(ctx->f0.fl);
L_8001C4E4:
    // 0x8001C4E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C4E8: lwc1        $f0, 0x830($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X830);
    // 0x8001C4EC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8001C4F0: nop

    // 0x8001C4F4: bc1t        L_8001C500
    if (c1cs) {
        // 0x8001C4F8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001C500;
    }
    // 0x8001C4F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001C4FC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8001C500:
    // 0x8001C500: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C504: lwc1        $f0, 0x834($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X834);
    // 0x8001C508: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8001C50C: nop

    // 0x8001C510: bc1t        L_8001C51C
    if (c1cs) {
        // 0x8001C514: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8001C51C;
    }
    // 0x8001C514: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8001C518: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8001C51C:
    // 0x8001C51C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8001C520: bne         $v0, $zero, L_8001C58C
    if (ctx->r2 != 0) {
        // 0x8001C524: andi        $v0, $a0, 0xFF
        ctx->r2 = ctx->r4 & 0XFF;
            goto L_8001C58C;
    }
    // 0x8001C524: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8001C528: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8001C52C: nop

    // 0x8001C530: mul.s       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8001C534: nop

    // 0x8001C538: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8001C53C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C540: lwc1        $f2, 0x838($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X838);
    // 0x8001C544: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001C548: nop

    // 0x8001C54C: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8001C550: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C554: lwc1        $f2, 0x83C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X83C);
    // 0x8001C558: mul.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8001C55C: nop

    // 0x8001C560: mul.s       $f4, $f8, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8001C564: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C568: lwc1        $f2, 0x840($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X840);
    // 0x8001C56C: mul.s       $f8, $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8001C570: add.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x8001C574: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C578: lwc1        $f2, 0x844($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X844);
    // 0x8001C57C: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8001C580: mul.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8001C584: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8001C588: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
L_8001C58C:
    // 0x8001C58C: bne         $v0, $zero, L_8001C5C4
    if (ctx->r2 != 0) {
        // 0x8001C590: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_8001C5C4;
    }
    // 0x8001C590: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8001C594: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001C598: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8001C59C: nop

    // 0x8001C5A0: bc1f        L_8001C5B8
    if (!c1cs) {
        // 0x8001C5A4: nop
    
            goto L_8001C5B8;
    }
    // 0x8001C5A4: nop

    // 0x8001C5A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C5AC: lwc1        $f0, 0x848($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X848);
    // 0x8001C5B0: j           L_8001C5C4
    // 0x8001C5B4: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
        goto L_8001C5C4;
    // 0x8001C5B4: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
L_8001C5B8:
    // 0x8001C5B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C5BC: lwc1        $f0, 0x84C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X84C);
    // 0x8001C5C0: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
L_8001C5C4:
    // 0x8001C5C4: jr          $ra
    // 0x8001C5C8: nop

    return;
    // 0x8001C5C8: nop

;}
RECOMP_FUNC void func_8001C5CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C5CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001C5D0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8001C5D4: jal         0x8001C400
    // 0x8001C5D8: nop

    func_8001C400(rdram, ctx);
        goto after_0;
    // 0x8001C5D8: nop

    after_0:
    // 0x8001C5DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C5E0: lwc1        $f2, 0x850($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X850);
    // 0x8001C5E4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8001C5E8: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8001C5EC: jr          $ra
    // 0x8001C5F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001C5F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001C5F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C5F4: mov.s       $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.fl = ctx->f12.fl;
    // 0x8001C5F8: mul.s       $f2, $f4, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8001C5FC: nop

    // 0x8001C600: mul.s       $f0, $f14, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8001C604: add.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8001C608: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8001C60C: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x8001C610: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001C614: bc1f        L_8001C760
    if (!c1cs) {
        // 0x8001C618: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8001C760;
    }
    // 0x8001C618: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8001C61C: sqrt.s      $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = sqrtf(ctx->f12.fl);
    // 0x8001C620: div.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8001C624: div.s       $f12, $f4, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8001C628: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x8001C62C: abs.d       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = fabs(ctx->f2.d);
    // 0x8001C630: cvt.d.s     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.d = CVT_D_S(ctx->f14.fl);
    // 0x8001C634: abs.d       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = fabs(ctx->f0.d);
    // 0x8001C638: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x8001C63C: nop

    // 0x8001C640: bc1f        L_8001C6D0
    if (!c1cs) {
        // 0x8001C644: nop
    
            goto L_8001C6D0;
    }
    // 0x8001C644: nop

    // 0x8001C648: c.le.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl <= ctx->f12.fl;
    // 0x8001C64C: nop

    // 0x8001C650: bc1f        L_8001C690
    if (!c1cs) {
        // 0x8001C654: nop
    
            goto L_8001C690;
    }
    // 0x8001C654: nop

    // 0x8001C658: c.le.s      $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f6.fl <= ctx->f14.fl;
    // 0x8001C65C: nop

    // 0x8001C660: bc1f        L_8001C678
    if (!c1cs) {
        // 0x8001C664: nop
    
            goto L_8001C678;
    }
    // 0x8001C664: nop

    // 0x8001C668: jal         0x8001C400
    // 0x8001C66C: nop

    func_8001C400(rdram, ctx);
        goto after_0;
    // 0x8001C66C: nop

    after_0:
    // 0x8001C670: j           L_8001C764
    // 0x8001C674: nop

        goto L_8001C764;
    // 0x8001C674: nop

L_8001C678:
    // 0x8001C678: jal         0x8001C400
    // 0x8001C67C: nop

    func_8001C400(rdram, ctx);
        goto after_1;
    // 0x8001C67C: nop

    after_1:
    // 0x8001C680: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C684: lwc1        $f2, 0x854($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X854);
    // 0x8001C688: j           L_8001C764
    // 0x8001C68C: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
        goto L_8001C764;
    // 0x8001C68C: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
L_8001C690:
    // 0x8001C690: c.le.s      $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f6.fl <= ctx->f14.fl;
    // 0x8001C694: nop

    // 0x8001C698: bc1f        L_8001C6B8
    if (!c1cs) {
        // 0x8001C69C: nop
    
            goto L_8001C6B8;
    }
    // 0x8001C69C: nop

    // 0x8001C6A0: jal         0x8001C400
    // 0x8001C6A4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_8001C400(rdram, ctx);
        goto after_2;
    // 0x8001C6A4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_2:
    // 0x8001C6A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C6AC: lwc1        $f2, 0x858($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X858);
    // 0x8001C6B0: j           L_8001C764
    // 0x8001C6B4: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
        goto L_8001C764;
    // 0x8001C6B4: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
L_8001C6B8:
    // 0x8001C6B8: jal         0x8001C400
    // 0x8001C6BC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_8001C400(rdram, ctx);
        goto after_3;
    // 0x8001C6BC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_3:
    // 0x8001C6C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C6C4: lwc1        $f2, 0x85C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X85C);
    // 0x8001C6C8: j           L_8001C764
    // 0x8001C6CC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_8001C764;
    // 0x8001C6CC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_8001C6D0:
    // 0x8001C6D0: c.le.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl <= ctx->f12.fl;
    // 0x8001C6D4: nop

    // 0x8001C6D8: bc1f        L_8001C720
    if (!c1cs) {
        // 0x8001C6DC: nop
    
            goto L_8001C720;
    }
    // 0x8001C6DC: nop

    // 0x8001C6E0: c.le.s      $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f6.fl <= ctx->f14.fl;
    // 0x8001C6E4: nop

    // 0x8001C6E8: bc1f        L_8001C708
    if (!c1cs) {
        // 0x8001C6EC: nop
    
            goto L_8001C708;
    }
    // 0x8001C6EC: nop

    // 0x8001C6F0: jal         0x8001C400
    // 0x8001C6F4: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    func_8001C400(rdram, ctx);
        goto after_4;
    // 0x8001C6F4: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    after_4:
    // 0x8001C6F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C6FC: lwc1        $f2, 0x860($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X860);
    // 0x8001C700: j           L_8001C764
    // 0x8001C704: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
        goto L_8001C764;
    // 0x8001C704: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
L_8001C708:
    // 0x8001C708: jal         0x8001C400
    // 0x8001C70C: neg.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = -ctx->f14.fl;
    func_8001C400(rdram, ctx);
        goto after_5;
    // 0x8001C70C: neg.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = -ctx->f14.fl;
    after_5:
    // 0x8001C710: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C714: lwc1        $f2, 0x864($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X864);
    // 0x8001C718: j           L_8001C764
    // 0x8001C71C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_8001C764;
    // 0x8001C71C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_8001C720:
    // 0x8001C720: c.le.s      $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f6.fl <= ctx->f14.fl;
    // 0x8001C724: nop

    // 0x8001C728: bc1f        L_8001C748
    if (!c1cs) {
        // 0x8001C72C: nop
    
            goto L_8001C748;
    }
    // 0x8001C72C: nop

    // 0x8001C730: jal         0x8001C400
    // 0x8001C734: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    func_8001C400(rdram, ctx);
        goto after_6;
    // 0x8001C734: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    after_6:
    // 0x8001C738: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C73C: lwc1        $f2, 0x868($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X868);
    // 0x8001C740: j           L_8001C764
    // 0x8001C744: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_8001C764;
    // 0x8001C744: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_8001C748:
    // 0x8001C748: jal         0x8001C400
    // 0x8001C74C: neg.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = -ctx->f14.fl;
    func_8001C400(rdram, ctx);
        goto after_7;
    // 0x8001C74C: neg.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = -ctx->f14.fl;
    after_7:
    // 0x8001C750: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C754: lwc1        $f2, 0x86C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X86C);
    // 0x8001C758: j           L_8001C764
    // 0x8001C75C: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
        goto L_8001C764;
    // 0x8001C75C: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
L_8001C760:
    // 0x8001C760: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
L_8001C764:
    // 0x8001C764: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8001C768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001C76C: jr          $ra
    // 0x8001C770: nop

    return;
    // 0x8001C770: nop

;}
RECOMP_FUNC void func_8001C774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C774: lwc1        $f14, 0x10($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8001C778: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8001C77C: mul.s       $f12, $f14, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x8001C780: lwc1        $f2, 0x1C($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x8001C784: lwc1        $f0, 0x14($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8001C788: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001C78C: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8001C790: mul.s       $f6, $f8, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8001C794: lwc1        $f10, 0x18($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8001C798: mul.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8001C79C: nop

    // 0x8001C7A0: mul.s       $f8, $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8001C7A4: nop

    // 0x8001C7A8: mul.s       $f10, $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8001C7AC: sub.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x8001C7B0: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001C7B4: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8001C7B8: sub.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8001C7BC: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001C7C0: neg.s       $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = -ctx->f6.fl;
    // 0x8001C7C4: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001C7C8: sub.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8001C7CC: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8001C7D0: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8001C7D4: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8001C7D8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8001C7DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C7E0: lwc1        $f10, 0x870($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X870);
    // 0x8001C7E4: div.s       $f10, $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8001C7E8: mul.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8001C7EC: nop

    // 0x8001C7F0: mul.s       $f6, $f10, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8001C7F4: nop

    // 0x8001C7F8: mul.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8001C7FC: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x8001C800: swc1        $f6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f6.u32l;
    // 0x8001C804: swc1        $f8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f8.u32l;
    // 0x8001C808: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001C80C: lwc1        $f2, 0x20($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8001C810: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001C814: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8001C818: lwc1        $f2, 0x1C($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x8001C81C: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8001C820: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8001C824: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x8001C828: mul.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001C82C: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x8001C830: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001C834: lwc1        $f2, 0x20($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8001C838: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001C83C: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8001C840: lwc1        $f2, 0x18($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8001C844: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8001C848: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8001C84C: mul.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8001C850: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x8001C854: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001C858: lwc1        $f2, 0x1C($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x8001C85C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001C860: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001C864: lwc1        $f2, 0x18($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8001C868: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8001C86C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8001C870: mul.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001C874: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x8001C878: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001C87C: lwc1        $f2, 0x14($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8001C880: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001C884: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8001C888: lwc1        $f2, 0x10($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8001C88C: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8001C890: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8001C894: mul.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8001C898: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x8001C89C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001C8A0: lwc1        $f0, 0x14($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8001C8A4: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001C8A8: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8001C8AC: lwc1        $f0, 0xC($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8001C8B0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001C8B4: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8001C8B8: mul.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8001C8BC: swc1        $f6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f6.u32l;
    // 0x8001C8C0: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001C8C4: lwc1        $f0, 0x10($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8001C8C8: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001C8CC: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001C8D0: lwc1        $f0, 0xC($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8001C8D4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001C8D8: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8001C8DC: mul.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8001C8E0: swc1        $f10, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f10.u32l;
    // 0x8001C8E4: lwc1        $f0, 0x24($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8001C8E8: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8001C8EC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8001C8F0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001C8F4: lwc1        $f6, 0x28($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X28);
    // 0x8001C8F8: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8001C8FC: mul.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8001C900: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8001C904: lwc1        $f2, 0x2C($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8001C908: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8001C90C: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8001C910: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8001C914: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x8001C918: lwc1        $f0, 0x24($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8001C91C: lwc1        $f2, 0xC($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8001C920: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8001C924: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001C928: lwc1        $f6, 0x28($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X28);
    // 0x8001C92C: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8001C930: mul.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8001C934: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8001C938: lwc1        $f2, 0x2C($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8001C93C: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8001C940: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8001C944: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8001C948: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
    // 0x8001C94C: lwc1        $f0, 0x24($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8001C950: lwc1        $f2, 0x18($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8001C954: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8001C958: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001C95C: lwc1        $f6, 0x28($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X28);
    // 0x8001C960: lwc1        $f2, 0x1C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8001C964: mul.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8001C968: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8001C96C: lwc1        $f2, 0x2C($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8001C970: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8001C974: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8001C978: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8001C97C: jr          $ra
    // 0x8001C980: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x8001C980: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_8001C984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C984: addu        $t6, $zero, $zero
    ctx->r14 = ADD32(0, 0);
    // 0x8001C988: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C98C: lwc1        $f4, 0x874($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X874);
    // 0x8001C990: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C994: lwc1        $f6, 0x878($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X878);
    // 0x8001C998: addu        $t3, $a0, $zero
    ctx->r11 = ADD32(ctx->r4, 0);
    // 0x8001C99C: addu        $t4, $t3, $zero
    ctx->r12 = ADD32(ctx->r11, 0);
    // 0x8001C9A0: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8001C9A4: addu        $t5, $a1, $zero
    ctx->r13 = ADD32(ctx->r5, 0);
L_8001C9A8:
    // 0x8001C9A8: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x8001C9AC: addu        $t0, $t5, $zero
    ctx->r8 = ADD32(ctx->r13, 0);
    // 0x8001C9B0: addu        $a3, $t3, $zero
    ctx->r7 = ADD32(ctx->r11, 0);
L_8001C9B4:
    // 0x8001C9B4: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8001C9B8: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8001C9BC: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8001C9C0: addu        $a0, $t2, $a3
    ctx->r4 = ADD32(ctx->r10, ctx->r7);
    // 0x8001C9C4: addiu       $v1, $a3, 0x20
    ctx->r3 = ADD32(ctx->r7, 0X20);
    // 0x8001C9C8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8001C9CC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001C9D0: addu        $v1, $t2, $v1
    ctx->r3 = ADD32(ctx->r10, ctx->r3);
    // 0x8001C9D4: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001C9D8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8001C9DC: sra         $v0, $a2, 16
    ctx->r2 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8001C9E0: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x8001C9E4: slti        $v0, $t1, 0x3
    ctx->r2 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x8001C9E8: bne         $v0, $zero, L_8001C9B4
    if (ctx->r2 != 0) {
        // 0x8001C9EC: sh          $a2, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r6;
            goto L_8001C9B4;
    }
    // 0x8001C9EC: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x8001C9F0: lwc1        $f0, 0x24($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8001C9F4: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8001C9F8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8001C9FC: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x8001CA00: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x8001CA04: addiu       $t6, $t6, 0x1
    ctx->r14 = ADD32(ctx->r14, 0X1);
    // 0x8001CA08: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001CA0C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8001CA10: sra         $v0, $a2, 16
    ctx->r2 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8001CA14: sh          $v0, 0x18($t4)
    MEM_H(0X18, ctx->r12) = ctx->r2;
    // 0x8001CA18: sh          $a2, 0x38($t4)
    MEM_H(0X38, ctx->r12) = ctx->r6;
    // 0x8001CA1C: slti        $v0, $t6, 0x3
    ctx->r2 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x8001CA20: bne         $v0, $zero, L_8001C9A8
    if (ctx->r2 != 0) {
        // 0x8001CA24: addiu       $t4, $t4, 0x2
        ctx->r12 = ADD32(ctx->r12, 0X2);
            goto L_8001C9A8;
    }
    // 0x8001CA24: addiu       $t4, $t4, 0x2
    ctx->r12 = ADD32(ctx->r12, 0X2);
    // 0x8001CA28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001CA2C: sh          $zero, 0x36($t3)
    MEM_H(0X36, ctx->r11) = 0;
    // 0x8001CA30: sh          $zero, 0x16($t3)
    MEM_H(0X16, ctx->r11) = 0;
    // 0x8001CA34: sh          $zero, 0x2E($t3)
    MEM_H(0X2E, ctx->r11) = 0;
    // 0x8001CA38: sh          $zero, 0xE($t3)
    MEM_H(0XE, ctx->r11) = 0;
    // 0x8001CA3C: sh          $zero, 0x26($t3)
    MEM_H(0X26, ctx->r11) = 0;
    // 0x8001CA40: sh          $zero, 0x6($t3)
    MEM_H(0X6, ctx->r11) = 0;
    // 0x8001CA44: sh          $v0, 0x1E($t3)
    MEM_H(0X1E, ctx->r11) = ctx->r2;
    // 0x8001CA48: jr          $ra
    // 0x8001CA4C: sh          $zero, 0x3E($t3)
    MEM_H(0X3E, ctx->r11) = 0;
    return;
    // 0x8001CA4C: sh          $zero, 0x3E($t3)
    MEM_H(0X3E, ctx->r11) = 0;
;}
RECOMP_FUNC void func_8001CA50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CA50: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001CA54: lwc1        $f2, 0x87C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X87C);
    // 0x8001CA58: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001CA5C: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x8001CA60: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x8001CA64: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x8001CA68: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
    // 0x8001CA6C: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x8001CA70: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x8001CA74: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x8001CA78: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x8001CA7C: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x8001CA80: swc1        $f2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f2.u32l;
    // 0x8001CA84: swc1        $f2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f2.u32l;
    // 0x8001CA88: jr          $ra
    // 0x8001CA8C: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x8001CA8C: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
;}
RECOMP_FUNC void func_8001CA90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CA90: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8001CA94: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x8001CA98: lwc1        $f2, 0x28($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8001CA9C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001CAA0: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x8001CAA4: lwc1        $f0, 0x2C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8001CAA8: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x8001CAAC: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x8001CAB0: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8001CAB4: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
    // 0x8001CAB8: swc1        $f2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f2.u32l;
    // 0x8001CABC: jr          $ra
    // 0x8001CAC0: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x8001CAC0: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_8001CAC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CAC4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001CAC8: lwc1        $f2, 0x880($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X880);
    // 0x8001CACC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001CAD0: sw          $a1, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r5;
    // 0x8001CAD4: sw          $a2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r6;
    // 0x8001CAD8: sw          $a3, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r7;
    // 0x8001CADC: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x8001CAE0: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x8001CAE4: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x8001CAE8: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x8001CAEC: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x8001CAF0: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x8001CAF4: swc1        $f2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f2.u32l;
    // 0x8001CAF8: swc1        $f2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f2.u32l;
    // 0x8001CAFC: jr          $ra
    // 0x8001CB00: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x8001CB00: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
;}
RECOMP_FUNC void func_8001CB04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CB04: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8001CB08: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x8001CB0C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001CB10: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8001CB14: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x8001CB18: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8001CB1C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8001CB20: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8001CB24: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x8001CB28: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x8001CB2C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8001CB30: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8001CB34: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8001CB38: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8001CB3C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8001CB40: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8001CB44: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8001CB48: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8001CB4C: jal         0x800191C4
    // 0x8001CB50: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_800191C4(rdram, ctx);
        goto after_0;
    // 0x8001CB50: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8001CB54: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x8001CB58: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8001CB5C: jr          $ra
    // 0x8001CB60: nop

    return;
    // 0x8001CB60: nop

;}
RECOMP_FUNC void func_8001CB64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CB64: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001CB68: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x8001CB6C: sw          $a2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r6;
    // 0x8001CB70: sw          $a3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r7;
    // 0x8001CB74: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x8001CB78: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x8001CB7C: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x8001CB80: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
    // 0x8001CB84: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x8001CB88: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x8001CB8C: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x8001CB90: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x8001CB94: jr          $ra
    // 0x8001CB98: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x8001CB98: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_8001CB9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CB9C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001CBA0: lwc1        $f0, 0x884($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X884);
    // 0x8001CBA4: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x8001CBA8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8001CBAC: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x8001CBB0: mul.s       $f20, $f6, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001CBB4: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8001CBB8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001CBBC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8001CBC0: jal         0x80033960
    // 0x8001CBC4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001CBC4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x8001CBC8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8001CBCC: jal         0x8002B190
    // 0x8001CBD0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001CBD0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_1:
    // 0x8001CBD4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001CBD8: lwc1        $f4, 0x888($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X888);
    // 0x8001CBDC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8001CBE0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8001CBE4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001CBE8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8001CBEC: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x8001CBF0: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x8001CBF4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8001CBF8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8001CBFC: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8001CC00: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x8001CC04: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x8001CC08: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x8001CC0C: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x8001CC10: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x8001CC14: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x8001CC18: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x8001CC1C: jal         0x800191C4
    // 0x8001CC20: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800191C4(rdram, ctx);
        goto after_2;
    // 0x8001CC20: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x8001CC24: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8001CC28: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8001CC2C: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x8001CC30: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8001CC34: jr          $ra
    // 0x8001CC38: nop

    return;
    // 0x8001CC38: nop

;}
RECOMP_FUNC void func_8001CC3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CC3C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001CC40: lwc1        $f0, 0x88C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X88C);
    // 0x8001CC44: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x8001CC48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001CC4C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8001CC50: mul.s       $f20, $f6, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001CC54: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001CC58: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001CC5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001CC60: jal         0x80033960
    // 0x8001CC64: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001CC64: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x8001CC68: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8001CC6C: jal         0x8002B190
    // 0x8001CC70: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001CC70: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_1:
    // 0x8001CC74: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001CC78: lwc1        $f4, 0x890($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X890);
    // 0x8001CC7C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001CC80: swc1        $f20, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f20.u32l;
    // 0x8001CC84: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x8001CC88: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x8001CC8C: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x8001CC90: swc1        $f20, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f20.u32l;
    // 0x8001CC94: swc1        $f2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f2.u32l;
    // 0x8001CC98: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    // 0x8001CC9C: swc1        $f2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f2.u32l;
    // 0x8001CCA0: swc1        $f2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f2.u32l;
    // 0x8001CCA4: swc1        $f2, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f2.u32l;
    // 0x8001CCA8: swc1        $f2, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f2.u32l;
    // 0x8001CCAC: swc1        $f2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f2.u32l;
    // 0x8001CCB0: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x8001CCB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CCB8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001CCBC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8001CCC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001CCC4: jr          $ra
    // 0x8001CCC8: nop

    return;
    // 0x8001CCC8: nop

;}
RECOMP_FUNC void func_8001CCCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CCCC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001CCD0: lwc1        $f0, 0x894($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X894);
    // 0x8001CCD4: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x8001CCD8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8001CCDC: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x8001CCE0: mul.s       $f20, $f6, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001CCE4: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8001CCE8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001CCEC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8001CCF0: jal         0x80033960
    // 0x8001CCF4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001CCF4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x8001CCF8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8001CCFC: jal         0x8002B190
    // 0x8001CD00: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001CD00: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_1:
    // 0x8001CD04: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001CD08: lwc1        $f4, 0x898($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X898);
    // 0x8001CD0C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8001CD10: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8001CD14: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001CD18: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8001CD1C: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8001CD20: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x8001CD24: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8001CD28: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8001CD2C: swc1        $f20, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f20.u32l;
    // 0x8001CD30: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x8001CD34: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x8001CD38: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x8001CD3C: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x8001CD40: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x8001CD44: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x8001CD48: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x8001CD4C: jal         0x800191C4
    // 0x8001CD50: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    func_800191C4(rdram, ctx);
        goto after_2;
    // 0x8001CD50: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x8001CD54: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8001CD58: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8001CD5C: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x8001CD60: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8001CD64: jr          $ra
    // 0x8001CD68: nop

    return;
    // 0x8001CD68: nop

;}
RECOMP_FUNC void func_8001CD6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CD6C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001CD70: lwc1        $f0, 0x89C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X89C);
    // 0x8001CD74: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x8001CD78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001CD7C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8001CD80: mul.s       $f20, $f6, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001CD84: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001CD88: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001CD8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001CD90: jal         0x80033960
    // 0x8001CD94: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001CD94: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x8001CD98: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8001CD9C: jal         0x8002B190
    // 0x8001CDA0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001CDA0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_1:
    // 0x8001CDA4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001CDA8: lwc1        $f4, 0x8A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X8A0);
    // 0x8001CDAC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001CDB0: swc1        $f20, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f20.u32l;
    // 0x8001CDB4: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x8001CDB8: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8001CDBC: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x8001CDC0: swc1        $f20, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f20.u32l;
    // 0x8001CDC4: swc1        $f2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f2.u32l;
    // 0x8001CDC8: swc1        $f2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f2.u32l;
    // 0x8001CDCC: swc1        $f2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f2.u32l;
    // 0x8001CDD0: swc1        $f2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f2.u32l;
    // 0x8001CDD4: swc1        $f2, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f2.u32l;
    // 0x8001CDD8: swc1        $f2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f2.u32l;
    // 0x8001CDDC: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
    // 0x8001CDE0: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x8001CDE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CDE8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001CDEC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8001CDF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001CDF4: jr          $ra
    // 0x8001CDF8: nop

    return;
    // 0x8001CDF8: nop

;}
RECOMP_FUNC void func_8001CDFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CDFC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001CE00: lwc1        $f0, 0x8A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X8A4);
    // 0x8001CE04: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x8001CE08: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8001CE0C: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x8001CE10: mul.s       $f20, $f6, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001CE14: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8001CE18: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001CE1C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8001CE20: jal         0x80033960
    // 0x8001CE24: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001CE24: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x8001CE28: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8001CE2C: jal         0x8002B190
    // 0x8001CE30: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001CE30: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_1:
    // 0x8001CE34: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001CE38: lwc1        $f4, 0x8A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X8A8);
    // 0x8001CE3C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8001CE40: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8001CE44: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001CE48: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8001CE4C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8001CE50: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x8001CE54: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8001CE58: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8001CE5C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8001CE60: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x8001CE64: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x8001CE68: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x8001CE6C: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x8001CE70: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x8001CE74: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x8001CE78: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x8001CE7C: jal         0x800191C4
    // 0x8001CE80: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    func_800191C4(rdram, ctx);
        goto after_2;
    // 0x8001CE80: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x8001CE84: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8001CE88: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8001CE8C: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x8001CE90: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8001CE94: jr          $ra
    // 0x8001CE98: nop

    return;
    // 0x8001CE98: nop

;}
RECOMP_FUNC void func_8001CE9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CE9C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001CEA0: lwc1        $f0, 0x8AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X8AC);
    // 0x8001CEA4: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x8001CEA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001CEAC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8001CEB0: mul.s       $f20, $f6, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001CEB4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001CEB8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001CEBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001CEC0: jal         0x80033960
    // 0x8001CEC4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001CEC4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x8001CEC8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8001CECC: jal         0x8002B190
    // 0x8001CED0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001CED0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_1:
    // 0x8001CED4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001CED8: lwc1        $f4, 0x8B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X8B0);
    // 0x8001CEDC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001CEE0: swc1        $f20, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f20.u32l;
    // 0x8001CEE4: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x8001CEE8: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8001CEEC: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x8001CEF0: swc1        $f20, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f20.u32l;
    // 0x8001CEF4: swc1        $f2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f2.u32l;
    // 0x8001CEF8: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
    // 0x8001CEFC: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    // 0x8001CF00: swc1        $f2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f2.u32l;
    // 0x8001CF04: swc1        $f2, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f2.u32l;
    // 0x8001CF08: swc1        $f2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f2.u32l;
    // 0x8001CF0C: swc1        $f2, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f2.u32l;
    // 0x8001CF10: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x8001CF14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CF18: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001CF1C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8001CF20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001CF24: jr          $ra
    // 0x8001CF28: nop

    return;
    // 0x8001CF28: nop

;}
RECOMP_FUNC void func_8001CF2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CF2C: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8001CF30: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001CF34: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8001CF38: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8001CF3C: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8001CF40: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8001CF44: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8001CF48: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8001CF4C: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8001CF50: jr          $ra
    // 0x8001CF54: nop

    return;
    // 0x8001CF54: nop

;}
RECOMP_FUNC void normalize_vector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CF58: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8001CF5C: mul.s       $f4, $f6, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8001CF60: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8001CF64: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8001CF68: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8001CF6C: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001CF70: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8001CF74: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8001CF78: sqrt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = sqrtf(ctx->f4.fl);
    // 0x8001CF7C: div.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001CF80: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8001CF84: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001CF88: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8001CF8C: div.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001CF90: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x8001CF94: swc1        $f2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f2.u32l;
    // 0x8001CF98: jr          $ra
    // 0x8001CF9C: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x8001CF9C: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_8001CFA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CFA0: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001CFA4: mul.s       $f4, $f6, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8001CFA8: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001CFAC: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8001CFB0: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8001CFB4: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001CFB8: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8001CFBC: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8001CFC0: sqrt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = sqrtf(ctx->f4.fl);
    // 0x8001CFC4: div.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001CFC8: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x8001CFCC: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001CFD0: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001CFD4: swc1        $f2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f2.u32l;
    // 0x8001CFD8: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8001CFDC: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001CFE0: jr          $ra
    // 0x8001CFE4: swc1        $f2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x8001CFE4: swc1        $f2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f2.u32l;
;}
RECOMP_FUNC void func_8001CFE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CFE8: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8001CFEC: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001CFF0: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001CFF4: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8001CFF8: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001CFFC: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001D000: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8001D004: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8001D008: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001D00C: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8001D010: jr          $ra
    // 0x8001D014: add.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f0.fl;
    return;
    // 0x8001D014: add.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f0.fl;
;}
RECOMP_FUNC void func_8001D018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D018: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8001D01C: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001D020: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001D024: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001D028: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8001D02C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001D030: jr          $ra
    // 0x8001D034: sub.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f0.fl;
    return;
    // 0x8001D034: sub.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f0.fl;
;}
RECOMP_FUNC void func_8001D038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D038: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001D03C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001D040: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001D044: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D048: lwc1        $f0, 0x8B4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X8B4);
    // 0x8001D04C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8001D050: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001D054: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x8001D058: sltiu       $v0, $a1, 0x6
    ctx->r2 = ctx->r5 < 0X6 ? 1 : 0;
    // 0x8001D05C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D060: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8001D064: swc1        $f2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f2.u32l;
    // 0x8001D068: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    // 0x8001D06C: swc1        $f2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f2.u32l;
    // 0x8001D070: mul.s       $f20, $f6, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001D074: beq         $v0, $zero, L_8001D0F0
    if (ctx->r2 == 0) {
        // 0x8001D078: nop
    
            goto L_8001D0F0;
    }
    // 0x8001D078: nop

    // 0x8001D07C: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8001D080: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D084: addu        $at, $at, $v0
    gpr jr_addend_8001D08C = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001D088: lw          $v0, 0x8B8($at)
    ctx->r2 = ADD32(ctx->r1, 0X8B8);
    // 0x8001D08C: jr          $v0
    // 0x8001D090: nop

    switch (jr_addend_8001D08C >> 2) {
        case 0: goto L_8001D094; break;
        case 1: goto L_8001D0A4; break;
        case 2: goto L_8001D0B4; break;
        case 3: goto L_8001D0C4; break;
        case 4: goto L_8001D0D4; break;
        case 5: goto L_8001D0E4; break;
        default: switch_error(__func__, 0x8001D08C, 0x800008B8);
    }
    // 0x8001D090: nop

L_8001D094:
    // 0x8001D094: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D098: lwc1        $f0, 0x8D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X8D0);
    // 0x8001D09C: j           L_8001D0F0
    // 0x8001D0A0: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
        goto L_8001D0F0;
    // 0x8001D0A0: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
L_8001D0A4:
    // 0x8001D0A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D0A8: lwc1        $f0, 0x8D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X8D4);
    // 0x8001D0AC: j           L_8001D0F0
    // 0x8001D0B0: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
        goto L_8001D0F0;
    // 0x8001D0B0: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
L_8001D0B4:
    // 0x8001D0B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D0B8: lwc1        $f0, 0x8D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X8D8);
    // 0x8001D0BC: j           L_8001D0F0
    // 0x8001D0C0: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
        goto L_8001D0F0;
    // 0x8001D0C0: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
L_8001D0C4:
    // 0x8001D0C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D0C8: lwc1        $f0, 0x8DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X8DC);
    // 0x8001D0CC: j           L_8001D0F0
    // 0x8001D0D0: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
        goto L_8001D0F0;
    // 0x8001D0D0: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
L_8001D0D4:
    // 0x8001D0D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D0D8: lwc1        $f0, 0x8E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X8E0);
    // 0x8001D0DC: j           L_8001D0F0
    // 0x8001D0E0: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
        goto L_8001D0F0;
    // 0x8001D0E0: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
L_8001D0E4:
    // 0x8001D0E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D0E8: lwc1        $f0, 0x8E4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X8E4);
    // 0x8001D0EC: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
L_8001D0F0:
    // 0x8001D0F0: jal         0x8002B190
    // 0x8001D0F4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001D0F4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x8001D0F8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8001D0FC: jal         0x80033960
    // 0x8001D100: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001D100: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x8001D104: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8001D108: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8001D10C: mul.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8001D110: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8001D114: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x8001D118: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8001D11C: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001D120: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8001D124: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    // 0x8001D128: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x8001D12C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D130: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001D134: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8001D138: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001D13C: jr          $ra
    // 0x8001D140: nop

    return;
    // 0x8001D140: nop

;}
RECOMP_FUNC void func_8001D144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D144: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001D148: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8001D14C: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x8001D150: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8001D154: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001D158: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8001D15C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8001D160: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8001D164: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001D168: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8001D16C: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8001D170: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D174: lwc1        $f4, 0x8E8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X8E8);
    // 0x8001D178: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x8001D17C: mul.s       $f20, $f6, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8001D180: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8001D184: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8001D188: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8001D18C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001D190: c.eq.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl == ctx->f2.fl;
    // 0x8001D194: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001D198: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001D19C: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8001D1A0: sqrt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = sqrtf(ctx->f0.fl);
    // 0x8001D1A4: bc1tl       L_8001D1AC
    if (c1cs) {
        // 0x8001D1A8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8001D1AC;
    }
    goto skip_0;
    // 0x8001D1A8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_0:
L_8001D1AC:
    // 0x8001D1AC: c.eq.s      $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f22.fl == ctx->f2.fl;
    // 0x8001D1B0: nop

    // 0x8001D1B4: bc1f        L_8001D1C0
    if (!c1cs) {
        // 0x8001D1B8: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8001D1C0;
    }
    // 0x8001D1B8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8001D1BC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8001D1C0:
    // 0x8001D1C0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8001D1C4: beql        $v0, $zero, L_8001D20C
    if (ctx->r2 == 0) {
        // 0x8001D1C8: swc1        $f2, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->f2.u32l;
            goto L_8001D20C;
    }
    goto skip_1;
    // 0x8001D1C8: swc1        $f2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f2.u32l;
    skip_1:
    // 0x8001D1CC: jal         0x8002B190
    // 0x8001D1D0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001D1D0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x8001D1D4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8001D1D8: jal         0x80033960
    // 0x8001D1DC: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001D1DC: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x8001D1E0: div.s       $f20, $f0, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8001D1E4: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8001D1E8: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001D1EC: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x8001D1F0: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8001D1F4: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001D1F8: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x8001D1FC: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8001D200: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001D204: j           L_8001D220
    // 0x8001D208: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
        goto L_8001D220;
    // 0x8001D208: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
L_8001D20C:
    // 0x8001D20C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D210: lwc1        $f0, 0x8EC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X8EC);
    // 0x8001D214: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    // 0x8001D218: swc1        $f2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f2.u32l;
    // 0x8001D21C: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
L_8001D220:
    // 0x8001D220: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8001D224: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8001D228: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001D22C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8001D230: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8001D234: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001D238: jr          $ra
    // 0x8001D23C: nop

    return;
    // 0x8001D23C: nop

;}
RECOMP_FUNC void func_8001D240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D240: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D244: lwc1        $f0, 0x8F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X8F0);
    // 0x8001D248: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x8001D24C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001D250: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8001D254: mul.s       $f20, $f4, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001D258: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001D25C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001D260: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8001D264: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x8001D268: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8001D26C: jal         0x8002B190
    // 0x8001D270: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001D270: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x8001D274: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8001D278: jal         0x80033960
    // 0x8001D27C: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001D27C: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x8001D280: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8001D284: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001D288: swc1        $f2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f2.u32l;
    // 0x8001D28C: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8001D290: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001D294: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    // 0x8001D298: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8001D29C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001D2A0: swc1        $f2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f2.u32l;
    // 0x8001D2A4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8001D2A8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8001D2AC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001D2B0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8001D2B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001D2B8: jr          $ra
    // 0x8001D2BC: nop

    return;
    // 0x8001D2BC: nop

;}
RECOMP_FUNC void func_8001D2C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D2C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001D2C4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8001D2C8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8001D2CC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8001D2D0: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x8001D2D4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001D2D8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8001D2DC: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8001D2E0: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8001D2E4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001D2E8: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8001D2EC: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8001D2F0: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001D2F4: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8001D2F8: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8001D2FC: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001D300: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8001D304: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8001D308: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x8001D30C: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8001D310: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8001D314: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x8001D318: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8001D31C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8001D320: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x8001D324: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x8001D328: jal         0x80019548
    // 0x8001D32C: swc1        $f0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f0.u32l;
    func_80019548(rdram, ctx);
        goto after_0;
    // 0x8001D32C: swc1        $f0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f0.u32l;
    after_0:
    // 0x8001D330: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8001D334: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8001D338: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001D33C: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8001D340: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8001D344: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8001D348: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8001D34C: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8001D350: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8001D354: swc1        $f0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f0.u32l;
    // 0x8001D358: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8001D35C: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8001D360: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001D364: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8001D368: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8001D36C: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8001D370: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8001D374: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8001D378: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8001D37C: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
    // 0x8001D380: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8001D384: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8001D388: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001D38C: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8001D390: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8001D394: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8001D398: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8001D39C: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8001D3A0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8001D3A4: swc1        $f0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f0.u32l;
    // 0x8001D3A8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001D3AC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8001D3B0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8001D3B4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8001D3B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001D3BC: jr          $ra
    // 0x8001D3C0: nop

    return;
    // 0x8001D3C0: nop

;}
RECOMP_FUNC void func_8001D3C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D3C4: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8001D3C8: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001D3CC: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8001D3D0: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8001D3D4: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001D3D8: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001D3DC: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8001D3E0: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8001D3E4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001D3E8: add.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8001D3EC: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x8001D3F0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x8001D3F4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8001D3F8: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x8001D3FC: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8001D400: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001D404: mul.s       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8001D408: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8001D40C: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8001D410: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001D414: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001D418: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8001D41C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001D420: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8001D424: sub.s       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8001D428: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
    // 0x8001D42C: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8001D430: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001D434: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001D438: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8001D43C: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001D440: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001D444: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8001D448: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8001D44C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001D450: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8001D454: sub.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8001D458: swc1        $f8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f8.u32l;
    // 0x8001D45C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8001D460: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8001D464: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001D468: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8001D46C: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001D470: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001D474: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001D478: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8001D47C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001D480: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001D484: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8001D488: swc1        $f4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f4.u32l;
    // 0x8001D48C: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8001D490: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8001D494: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8001D498: mul.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8001D49C: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8001D4A0: mul.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8001D4A4: lwc1        $f2, 0xC($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8001D4A8: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8001D4AC: mul.s       $f8, $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8001D4B0: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8001D4B4: sub.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8001D4B8: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x8001D4BC: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8001D4C0: lwc1        $f2, 0x8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8001D4C4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001D4C8: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8001D4CC: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8001D4D0: mul.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8001D4D4: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8001D4D8: lwc1        $f2, 0xC($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8001D4DC: mul.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8001D4E0: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8001D4E4: lwc1        $f2, 0xC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8001D4E8: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8001D4EC: mul.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8001D4F0: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8001D4F4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8001D4F8: swc1        $f0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f0.u32l;
    // 0x8001D4FC: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8001D500: lwc1        $f2, 0xC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8001D504: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001D508: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8001D50C: lwc1        $f2, 0xC($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8001D510: mul.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8001D514: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8001D518: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8001D51C: mul.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8001D520: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8001D524: lwc1        $f2, 0x4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8001D528: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8001D52C: mul.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8001D530: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8001D534: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8001D538: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
    // 0x8001D53C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x8001D540: jr          $ra
    // 0x8001D544: nop

    return;
    // 0x8001D544: nop

;}
RECOMP_FUNC void func_8001D548(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D548: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001D54C: sdc1        $f28, 0x20($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X20, ctx->r29);
    // 0x8001D550: sdc1        $f26, 0x18($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X18, ctx->r29);
    // 0x8001D554: sdc1        $f24, 0x10($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X10, ctx->r29);
    // 0x8001D558: sdc1        $f22, 0x8($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X8, ctx->r29);
    // 0x8001D55C: sdc1        $f20, 0x0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X0, ctx->r29);
    // 0x8001D560: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8001D564: mul.s       $f0, $f10, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8001D568: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8001D56C: mul.s       $f2, $f12, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8001D570: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8001D574: mul.s       $f4, $f8, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8001D578: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8001D57C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8001D580: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8001D584: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8001D588: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8001D58C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D590: lwc1        $f2, 0x8F4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X8F4);
    // 0x8001D594: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001D598: mul.s       $f20, $f10, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8001D59C: nop

    // 0x8001D5A0: mul.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8001D5A4: nop

    // 0x8001D5A8: mul.s       $f2, $f8, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8001D5AC: nop

    // 0x8001D5B0: mul.s       $f22, $f6, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8001D5B4: nop

    // 0x8001D5B8: mul.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8001D5BC: nop

    // 0x8001D5C0: mul.s       $f28, $f12, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f28.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8001D5C4: nop

    // 0x8001D5C8: mul.s       $f8, $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8001D5CC: nop

    // 0x8001D5D0: mul.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8001D5D4: nop

    // 0x8001D5D8: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8001D5DC: nop

    // 0x8001D5E0: mul.s       $f10, $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8001D5E4: add.s       $f18, $f28, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f28.fl + ctx->f8.fl;
    // 0x8001D5E8: add.s       $f24, $f4, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8001D5EC: mul.s       $f6, $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8001D5F0: sub.s       $f26, $f16, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f26.fl = ctx->f16.fl - ctx->f22.fl;
    // 0x8001D5F4: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8001D5F8: mul.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8001D5FC: add.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8001D600: add.s       $f2, $f12, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x8001D604: add.s       $f16, $f16, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x8001D608: sub.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x8001D60C: add.s       $f10, $f10, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f28.fl;
    // 0x8001D610: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D614: lwc1        $f14, 0x8F8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X8F8);
    // 0x8001D618: sub.s       $f18, $f14, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x8001D61C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001D620: sub.s       $f8, $f14, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f8.fl;
    // 0x8001D624: swc1        $f0, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f0.u32l;
    // 0x8001D628: swc1        $f0, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->f0.u32l;
    // 0x8001D62C: swc1        $f0, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f0.u32l;
    // 0x8001D630: sub.s       $f14, $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x8001D634: swc1        $f24, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f24.u32l;
    // 0x8001D638: swc1        $f26, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f26.u32l;
    // 0x8001D63C: swc1        $f4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f4.u32l;
    // 0x8001D640: swc1        $f2, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f2.u32l;
    // 0x8001D644: swc1        $f16, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f16.u32l;
    // 0x8001D648: swc1        $f12, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f12.u32l;
    // 0x8001D64C: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    // 0x8001D650: swc1        $f8, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f8.u32l;
    // 0x8001D654: swc1        $f14, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f14.u32l;
    // 0x8001D658: ldc1        $f28, 0x20($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X20);
    // 0x8001D65C: ldc1        $f26, 0x18($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X18);
    // 0x8001D660: ldc1        $f24, 0x10($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X10);
    // 0x8001D664: ldc1        $f22, 0x8($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X8);
    // 0x8001D668: ldc1        $f20, 0x0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X0);
    // 0x8001D66C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001D670: jr          $ra
    // 0x8001D674: nop

    return;
    // 0x8001D674: nop

;}
